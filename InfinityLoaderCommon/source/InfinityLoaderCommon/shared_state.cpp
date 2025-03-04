
#include "infinity_loader_common.h"
#include "shared_state.h"

#include <dbghelp.h>
#include <psapi.h>

/////////////////////////////
// SharedStateMappedMemory //
/////////////////////////////

OpaqueObjectBoilerplateImp(SharedStateMappedMemory, SharedStateMappedMemoryData)

DWORD SharedStateMappedMemory::Create(HANDLE& mappedMemoryHandleOut, SharedStateMappedMemory& mappedMemoryOut) {

	DWORD lastError = ERROR_SUCCESS;

	SharedStateMappedMemory toReturn {

		[&]() -> SharedStateMappedMemoryData* {

			constexpr std::size_t sharedMemSize = sizeof(SharedStateMappedMemoryData);
			HANDLE mappedHandle = CreateFileMapping(
				INVALID_HANDLE_VALUE,
				0,                    // Default security
				PAGE_READWRITE,
#ifdef _WIN64
				sharedMemSize >> 32,
#else
				0,
#endif
				sharedMemSize & 0xFFFFFFFF,
				nullptr               // No name
			);

			if (mappedHandle == NULL) {
				lastError = GetLastError();
				FPrint("[!][InfinityLoaderCommon.dll] SharedStateMappedMemory::Create() - CreateFileMapping() failed (%d)\n", lastError);
				return nullptr;
			}

			mappedMemoryHandleOut = mappedHandle;

			SharedStateMappedMemoryData* mappedMemory = reinterpret_cast<SharedStateMappedMemoryData*>(MapViewOfFile(
				mappedHandle,
				FILE_MAP_ALL_ACCESS,
				0,                   // Offset to map (high)
				0,                   // Offset to map (low)
				0                    // Number of bytes to map (0 = to end of file)
			));

			if (mappedMemory == nullptr) {
				lastError = GetLastError();
				FPrint("[!][InfinityLoaderCommon.dll] SharedStateMappedMemory::Create() - MapViewOfFile() failed (%d)\n", lastError);
				return nullptr;
			}

			return mappedMemory;
		},
		[&](SharedStateMappedMemoryData* data) {
			UnmapViewOfFile(data);
		},
		OpaqueObject::AllocMode::NOW
	};

	if (lastError == ERROR_SUCCESS) {
		mappedMemoryOut = std::move(toReturn);
	}

	return lastError;
}

DWORD SharedStateMappedMemory::CreateFromHandle(HANDLE mappedMemoryHandle, SharedStateMappedMemory& mappedMemoryOut) {

	DWORD lastError = ERROR_SUCCESS;

	SharedStateMappedMemory toReturn {

		[&]() -> SharedStateMappedMemoryData* {

			SharedStateMappedMemoryData *const mappedMemory = reinterpret_cast<SharedStateMappedMemoryData*>(
				MapViewOfFile(mappedMemoryHandle,
					FILE_MAP_ALL_ACCESS,
					0,                   // Offset to map (high)
					0,                   // Offset to map (low)
					0                    // Number of bytes to map (0 = to end of file)
				)
			);

			if (mappedMemory == nullptr) {
				lastError = GetLastError();
				MessageBoxFormatA("InfinityLoaderCommon.dll", MB_ICONERROR, "[!] SharedStateMappedMemory::CreateFromHandle() - MapViewOfFile() failed (%d)", lastError);
				return nullptr;
			}

			return mappedMemory;
		},
		[&](SharedStateMappedMemoryData* data) {
			UnmapViewOfFile(data);
		},
		OpaqueObject::AllocMode::NOW
	};

	if (lastError == ERROR_SUCCESS) {
		mappedMemoryOut = std::move(toReturn);
	}

	return lastError;
}

EXPORT DWORD& SharedStateMappedMemory::ParentProcessId() {
	return data()->io.parentProcessId;
}

EXPORT HANDLE& SharedStateMappedMemory::StdIn() {
	return data()->io.hStdIn;
}

EXPORT HANDLE& SharedStateMappedMemory::StdOut() {
	return data()->io.hStdOut;
}

EXPORT HANDLE& SharedStateMappedMemory::StdErr() {
	return data()->io.hStdErr;
}

EXPORT bool& SharedStateMappedMemory::Debug() {
	return data()->options.debug;
}

EXPORT bool& SharedStateMappedMemory::Pause() {
	return data()->options.pause;
}

EXPORT bool& SharedStateMappedMemory::ProtonCompatibility() {
	return data()->options.protonCompatibility;
}

/////////////////
// SharedState //
/////////////////

static const String EMPTY_STRING{TEXT("")};

Pattern::Entry::Entry(const String& str, const uintptr_t val) {
	name = str;
	valueType = Pattern::ValueType::SINGLE;
	value.single.address = val;
}

Pattern::Entry::Entry(const String& str, const ValueType valType) {
	name = str;
	valueType = valType;
	switch (valType) {
		case Pattern::ValueType::LIST: {
			new (&value.list) Pattern::ListValue{};
			break;
		}
	}
}

Pattern::Entry::~Entry() {
	switch (valueType) {
		case Pattern::ValueType::LIST: {
			value.list.~ListValue();
			break;
		}
	}
}

OpaqueObjectBoilerplateImp(SharedState, SharedStateData)

// Thread safe
EXPORT DWORD SharedState::Create(SharedStateMappedMemory mappedMemory, SharedState& sharedStateOut) {

	SharedState toReturn {
		[&]() -> SharedStateData* {
			SharedStateData* toReturn = new SharedStateData{};
			toReturn->mappedMemory = mappedMemory;
			return toReturn;
		},
		[&](SharedStateData* data) {
			delete data;
		},
		OpaqueObject::AllocMode::NOW
	};

	sharedStateOut = std::move(toReturn);
	return ERROR_SUCCESS;
}

// Thread safe
static DWORD loadLuaLibrary(const String& iniPath, const String& luaModeStr, HMODULE& luaLibraryOut) {

	String luaLibraryName;

	bool filled;
	TryRetErr( GetINIStr(iniPath, TEXT("General"), TEXT("LuaLibrary"), luaLibraryName, filled) )

	if (!filled) {
		FPrintT(TEXT("[!][InfinityLoaderCommon.dll] loadLuaLibrary() - [General].LuaLibrary must be defined when [General].LuaPatchMode == \"%s\"\n"), luaModeStr.c_str());
		return -1;
	}

	if (HMODULE hLuaLibrary = LoadLibrary(luaLibraryName.c_str())) {
		luaLibraryOut = hLuaLibrary;
	}
	else {
		DWORD lastError = GetLastError();
		FPrintT(TEXT("[!][InfinityLoaderCommon.dll] loadLuaLibrary() - LoadLibrary() failed (%d) to load [General].LuaLibrary \"%s\"\n"), lastError, luaLibraryName.c_str());
		return lastError;
	}

	return ERROR_SUCCESS;
}

// Thread safe
static DWORD findModuleWithPath(HANDLE process, const String& path, HMODULE& foundModule) {

	HMODULE modules[1024];
	DWORD needed;
	TCHAR nameBuffer[MAX_PATH];

	if (EnumProcessModules(process, modules, sizeof(modules), &needed)) {

		int filledModules = needed / sizeof(HMODULE);

		for (int i = 0; i < filledModules; i++) {

			HMODULE module = modules[i];
			if (!GetModuleFileName(module, nameBuffer, MAX_PATH)) {
				DWORD lastError = GetLastError();
				FPrint("[!][InfinityLoaderCommon.dll] findModuleWithPath() - GetModuleFileName() failed (%d)\n", lastError);
				return lastError;
			}

			if (strcmpT(path.c_str(), nameBuffer) == 0) {
				foundModule = module;
				return 0;
			}
		}
	}
	else {
		DWORD lastError = GetLastError();
		FPrint("[!][InfinityLoaderCommon.dll] findModuleWithPath() - EnumProcessModules() failed (%d)\n", lastError);
		return lastError;
	}

	return ERROR_SUCCESS;
}

// !NOT! thread safe
EXPORT DWORD SharedState::InitState() {

	SharedStateData& data = *this->data();
	SharedDLLState& state = data.state;
	SharedPaths& paths = data.paths;

	// Init initTime
	state.initTime = CurrentMicroseconds();

	// Init dbPath, exePath, exeName, iniPath, workingFolder, workingFolderA
	TryRetErr( InitPaths(paths.dbPath, paths.exePath, paths.exeName, paths.iniPath, paths.workingFolder, paths.workingFolderA) )

	// Init luaMode
	String luaModeStr;
	TryRetErr( GetINIStrDef(paths.iniPath, TEXT("General"), TEXT("LuaPatchMode"), TEXT(""), luaModeStr) )

	// Init luaLibrary
	if (luaModeStr == TEXT("INTERNAL")) {
		state.luaMode = LuaMode::INTERNAL;
	}
	else if (luaModeStr == TEXT("EXTERNAL")) {
		state.luaMode = LuaMode::EXTERNAL;
		HMODULE luaLibrary;
		TryRetErr( loadLuaLibrary(paths.iniPath, luaModeStr, luaLibrary) )
		state.luaLibrary = luaLibrary;
	}
	else if (luaModeStr == TEXT("REPLACE_INTERNAL_WITH_EXTERNAL")) {
		state.luaMode = LuaMode::REPLACE_INTERNAL_WITH_EXTERNAL;
		HMODULE luaLibrary;
		TryRetErr( loadLuaLibrary(paths.iniPath, luaModeStr, luaLibrary) )
		state.luaLibrary = luaLibrary;
	}
	else {
		Print("[!][InfinityLoaderCommon.dll] SharedState::InitState() - [General].LuaPatchMode must be either \"INTERNAL\", \"EXTERNAL\", or \"REPLACE_INTERNAL_WITH_EXTERNAL\"\n");
		return -1;
	}

	// Init imageBase
	HMODULE foundModule;
	TryRetErr( findModuleWithPath(GetCurrentProcess(), paths.exePath, foundModule) )

	IMAGE_NT_HEADERS* pNtHdr = ImageNtHeader(foundModule);
	state.imageBase = pNtHdr->OptionalHeader.ImageBase;

	// Init .text segment info
	TryRetErr( LoadSegmentInfo(".text") )

	return ERROR_SUCCESS;
}

// Thread safe
EXPORT SharedStateMappedMemory& SharedState::MappedMemory() {
	return data()->mappedMemory;
}

// Thread safe
EXPORT const String& SharedState::DbPath() {
	return data()->paths.dbPath;
}

// Thread safe
EXPORT const String& SharedState::ExePath() {
	return data()->paths.exePath;
}

// Thread safe
EXPORT const String& SharedState::ExeName() {
	return data()->paths.exeName;
}

// Thread safe
EXPORT const String& SharedState::IniPath() {
	return data()->paths.iniPath;
}

// Thread safe
EXPORT const String& SharedState::WorkingFolder() {
	return data()->paths.workingFolder;
}

// Thread safe
EXPORT const StringA& SharedState::WorkingFolderA() {
	return data()->paths.workingFolderA;
}

// Thread safe
EXPORT long long SharedState::InitTime() {
	return data()->state.initTime;
}

// Thread safe
EXPORT void SharedState::InitLuaState(lua_State* L) {

	SharedDLLState& state = data()->state;
	auto& luaStateEntries = state.luaStateEntries;

	const DWORD threadId = GetCurrentThreadId();
	
	{
		std::unique_lock<std::shared_mutex> lk { state.luaStateEntriesMutex };

		for (const SharedDLLState::LuaStateEntry& luaStateEntry : luaStateEntries) {
			if (luaStateEntry.threadId == threadId) {
				Print("[!][InfinityLoaderCommon.dll] SharedState::InitLuaState() - Attempted to call SharedState::InitLuaState() more than once for thread, ignoring\n");
				return;
			}
		}

		luaStateEntries.emplace_back(threadId, L);
	}

	auto& callbacks = state.luaStateInitializedCallbacks;
	for (auto& callback : callbacks) {
		callback(L);
	}
}

// !NOT! thread safe
EXPORT void SharedState::AddLuaStateInitializedCallback(std::function<void(lua_State*)> callback) {

	SharedDLLState& state = data()->state;
	state.luaStateInitializedCallbacks.emplace_back(callback);

	for (const SharedDLLState::LuaStateEntry& luaStateEntry : state.luaStateEntries) {
		callback(luaStateEntry.L);
	}
}

// Thread safe
EXPORT lua_State* SharedState::LuaState() {

	SharedDLLState& state = data()->state;
	const DWORD threadId = GetCurrentThreadId();

	{
		std::shared_lock<std::shared_mutex> lk { state.luaStateEntriesMutex };

		for (const SharedDLLState::LuaStateEntry& luaStateEntry : state.luaStateEntries) {
			if (luaStateEntry.threadId == threadId) {
				return luaStateEntry.L;
			}
		}
	}

	return nullptr;
}

// Thread safe
EXPORT HMODULE SharedState::LuaLibrary() {
	return data()->state.luaLibrary;
}

// Thread safe
EXPORT LuaMode SharedState::LuaMode() {
	return data()->state.luaMode;
}

// !NOT! thread safe
EXPORT void SharedState::AddAfterPatternModifiedListener(std::function<void(PatternValueHandle valueHandle, uintptr_t)> listener) {
	data()->state.afterPatternSetListeners.emplace_back(listener);
}

// Thread safe
EXPORT void SharedState::AddListPatternValue(PatternValueHandle valueHandle, uintptr_t value) {

	auto* pEntry = const_cast<Pattern::Entry*>(reinterpret_cast<const Pattern::Entry*>(valueHandle));

	if (pEntry != nullptr && pEntry->valueType == Pattern::ValueType::LIST) {

		auto& listValue = pEntry->value.list;
		std::unique_lock<std::shared_mutex> lk { listValue.mutex };

		listValue.addresses.emplace_back(value);
		QueueAfterPatternSetMessage(pEntry, value);
		return;
	}

	FPrintT(
		TEXT("[!][InfinityLoaderCommon.dll] SharedState::AddListPatternValue() - Failed, type of pattern \"%s\" is not LIST\n"),
		pEntry != nullptr ? pEntry->name.c_str() : TEXT("<unknown>")
	);
}

// Thread safe
EXPORT void SharedState::AddListPatternValue(PatternValueHandle valueHandle, void* value) {
	AddListPatternValue(valueHandle, reinterpret_cast<uintptr_t>(value));
}

// Thread safe
EXPORT bool SharedState::GetOrCreatePatternValue(const String& name, PatternValueType valueType, PatternValueHandle& out) {

	SharedDLLState& state = data()->state;
	auto& patterns = state.patterns;

	std::unique_lock<std::shared_mutex> lk { state.patternsModifyMutex };

	if (auto itr = patterns.find(name); itr != patterns.end()) {

		Pattern::Entry* pEntry = &itr->second;

		if (static_cast<PatternValueType>(pEntry->valueType) == valueType) {
			out = pEntry;
			return false;
		}

		out = nullptr;
		return true;
	}

	out = &patterns.try_emplace(name, name, static_cast<Pattern::ValueType>(valueType)).first->second;
	return false;
}

// Thread safe
EXPORT PatternValueType SharedState::GetPatternValue(const String& name, PatternValueHandle& out) {

	SharedDLLState& state = data()->state;
	auto& patterns = state.patterns;

	std::shared_lock<std::shared_mutex> lk { state.patternsModifyMutex };

	if (auto itr = patterns.find(name); itr != patterns.end()) {
		Pattern::Entry* pEntry = &itr->second;
		out = pEntry;
		return static_cast<PatternValueType>(pEntry->valueType);
	}

	out = nullptr;
	return PatternValueType::INVALID;
}

// Thread safe
EXPORT const String& SharedState::GetPatternValueName(PatternValueHandle valueHandle) {

	auto* pEntry = const_cast<Pattern::Entry*>(reinterpret_cast<const Pattern::Entry*>(valueHandle));

	if (pEntry != nullptr) {
		return pEntry->name;
	}

	FPrintT(
		TEXT("[!][InfinityLoaderCommon.dll] SharedState::GetPatternValueName() - Failed, type of pattern \"%s\" is INVALID\n"),
		pEntry != nullptr ? pEntry->name.c_str() : TEXT("<unknown>")
	);
	return EMPTY_STRING;
}

// Thread safe
EXPORT PatternValueType SharedState::GetPatternValueType(PatternValueHandle valueHandle) {
	auto* pEntry = const_cast<Pattern::Entry*>(reinterpret_cast<const Pattern::Entry*>(valueHandle));
	if (pEntry != nullptr) {
		return static_cast<PatternValueType>(pEntry->valueType);
	}
	return PatternValueType::INVALID;
}

// Thread safe
EXPORT uintptr_t SharedState::GetSinglePatternValue(PatternValueHandle valueHandle) {

	auto* pEntry = const_cast<Pattern::Entry*>(reinterpret_cast<const Pattern::Entry*>(valueHandle));

	if (pEntry != nullptr && pEntry->valueType == Pattern::ValueType::SINGLE) {
		return pEntry->value.single.address;
	}

	FPrintT(
		TEXT("[!][InfinityLoaderCommon.dll] SharedState::GetSinglePatternValue() - Failed, type of pattern \"%s\" is not SINGLE\n"),
		pEntry != nullptr ? pEntry->name.c_str() : TEXT("<unknown>")
	);
	return 0x0;
}

// Thread safe
EXPORT void SharedState::IteratePatternList(PatternValueHandle valueHandle, std::function<bool(uintptr_t)> func) {

	auto* pEntry = const_cast<Pattern::Entry*>(reinterpret_cast<const Pattern::Entry*>(valueHandle));

	if (pEntry != nullptr && pEntry->valueType == Pattern::ValueType::LIST) {

		auto& listValue = pEntry->value.list;
		std::shared_lock<std::shared_mutex> lk { listValue.mutex };

		for (uintptr_t address : listValue.addresses) {
			if (func(address)) {
				break;
			}
		}

		return;
	}

	FPrintT(
		TEXT("[!][InfinityLoaderCommon.dll] SharedState::IteratePatternList() - Failed, type of pattern \"%s\" is not LIST\n"),
		pEntry != nullptr ? pEntry->name.c_str() : TEXT("<unknown>")
	);
}

// Thread safe
EXPORT void SharedState::IteratePatternValues(std::function<bool(PatternValueHandle)> func) {

	SharedDLLState& state = data()->state;

	std::shared_lock<std::shared_mutex> lk { state.patternsModifyMutex };

	for (auto& [key, entry] : state.patterns) {
		if (func(reinterpret_cast<PatternValueHandle>(&entry))) {
			break;
		}
	}
}

// Thread safe
EXPORT void SharedState::ProcessThreadQueue() {

	SharedDLLState& state = data()->state;

	const DWORD threadId = GetCurrentThreadId();
	SharedDLLState::ThreadQueue* threadQueue = nullptr;

	{
		std::shared_lock<std::shared_mutex> lk { state.luaStateEntriesMutex };

		for (SharedDLLState::LuaStateEntry& luaStateEntry : state.luaStateEntries) {
			if (luaStateEntry.threadId == threadId) {
				threadQueue = &luaStateEntry.threadQueue;
			}
		}
	}

	if (threadQueue == nullptr) {
		Print("[!][InfinityLoaderCommon.dll] SharedState::ProcessThreadQueue() - No queue associated with the calling thread\n");
		return;
	}

	auto& messages = threadQueue->messages;

	while (!messages.empty()) {
		auto& message = messages.front();
		switch (message.type) {
			case MessageType::PATTERN_UPDATED: {
				auto& patternSet = message.patternSet;
				for (const auto& listener : state.afterPatternSetListeners) {
					listener(patternSet.patternValueHandle, patternSet.value);
				}
				break;
			}
		}
		messages.pop();
	}
}

// Thread safe
void SharedState::QueueAfterPatternSetMessage(PatternValueHandle valueHandle, uintptr_t value) {

	SharedDLLState& state = data()->state;
	const DWORD threadId = GetCurrentThreadId();

	{
		std::shared_lock<std::shared_mutex> lk { state.luaStateEntriesMutex };

		for (SharedDLLState::LuaStateEntry& luaStateEntry : state.luaStateEntries) {

			if (luaStateEntry.threadId == threadId) {
				// Lua state owned by this thread; run listeners now
				for (const auto& listener : state.afterPatternSetListeners) {
					listener(valueHandle, value);
				}
			}
			else {
				// Lua state owned by another thread; add message to its queue
				auto& threadQueue = luaStateEntry.threadQueue;
				{
					std::unique_lock<std::mutex> lk { threadQueue.messagesMutex };

					auto& message = threadQueue.messages.emplace();
					message.type = MessageType::PATTERN_UPDATED;
					message.patternSet.patternValueHandle = valueHandle;
					message.patternSet.value = value;
				}
			}
		}
	}
}

// Thread safe
EXPORT void SharedState::SetSinglePatternValue(PatternValueHandle valueHandle, uintptr_t value) {

	auto* pEntry = const_cast<Pattern::Entry*>(reinterpret_cast<const Pattern::Entry*>(valueHandle));

	if (pEntry != nullptr && pEntry->valueType == Pattern::ValueType::SINGLE) {
		pEntry->value.single.address = value;
		QueueAfterPatternSetMessage(pEntry, value);
		return;
	}

	FPrintT(
		TEXT("[!][InfinityLoaderCommon.dll] SharedState::SetSinglePatternValue() - Failed, type of pattern \"%s\" is not SINGLE\n"),
		pEntry != nullptr ? pEntry->name.c_str() : TEXT("<unknown>")
	);
}

// Thread safe
EXPORT void SharedState::SetSinglePatternValue(PatternValueHandle valueHandle, void* value) {
	SetSinglePatternValue(valueHandle, reinterpret_cast<uintptr_t>(value));
}

// Thread safe
static bool findSectionInfo(HMODULE module, const char* sectionName, SectionInfo& sectionInfo) {

	char* dllImageBase = (char*)module;
	IMAGE_NT_HEADERS* pNtHdr = ImageNtHeader(dllImageBase);
	IMAGE_SECTION_HEADER* pSectionHdr = (IMAGE_SECTION_HEADER*)(pNtHdr + 1);

	for (int i = 0; i < pNtHdr->FileHeader.NumberOfSections; i++) {

		if (strcmp((char*)pSectionHdr->Name, sectionName) == 0) {
			strcpy_s(sectionInfo.SectionName, sectionName);
			sectionInfo.SectionPointer = dllImageBase + pSectionHdr->VirtualAddress;
			sectionInfo.SectionSize = pSectionHdr->Misc.VirtualSize;
			return true;
		}

		pSectionHdr++;
	}

	return false;
}

// Thread safe
EXPORT uintptr_t SharedState::ImageBase() {
	return data()->state.imageBase;
}

// !NOT! thread safe
EXPORT DWORD SharedState::LoadSegmentInfo(const StringA& sectionName) {

	auto& sectionInfoMap = data()->state.sectionInfo;

	if (auto itr = sectionInfoMap.find(sectionName); itr != sectionInfoMap.end()) {
		return ERROR_SUCCESS;
	}

	HMODULE foundModule;
	TryRetErr( findModuleWithPath(GetCurrentProcess(), data()->paths.exePath, foundModule) )

	SectionInfo& pSectionInfo = sectionInfoMap[sectionName];

	if (!findSectionInfo(foundModule, sectionName.c_str(), pSectionInfo)) {
		FPrint("[!][InfinityLoaderCommon.dll] SharedState::LoadSegmentInfo() - Failed to locate %s segment\n", sectionName);
		return -1;
	}

	return ERROR_SUCCESS;
}

// !NOT! thread safe
EXPORT bool SharedState::GetSegmentPointer(const char* name, void*& out) {
	auto& sectionInfoMap = data()->state.sectionInfo;
	if (auto itr = sectionInfoMap.find(name); itr != sectionInfoMap.end()) {
		out = itr->second.SectionPointer;
		return false;
	}
	return true;
}

// !NOT! thread safe
EXPORT bool SharedState::GetSegmentSize(const char* name, DWORD& out) {
	auto& sectionInfoMap = data()->state.sectionInfo;
	if (auto itr = sectionInfoMap.find(name); itr != sectionInfoMap.end()) {
		out = itr->second.SectionSize;
		return false;
	}
	return true;
}

// !NOT! thread safe
EXPORT bool SharedState::GetSegmentPointerAndSize(const char* name, void*& ptrOut, DWORD& sizeOut) {
	auto& sectionInfoMap = data()->state.sectionInfo;
	if (auto itr = sectionInfoMap.find(name); itr != sectionInfoMap.end()) {
		ptrOut = itr->second.SectionPointer;
		sizeOut = itr->second.SectionSize;
		return false;
	}
	return true;
}
