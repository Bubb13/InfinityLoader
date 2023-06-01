
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
				sharedMemSize >> 32,
				sharedMemSize & 0xFFFFFFFF,
				nullptr               // No name
			);

			if (mappedHandle == NULL) {
				lastError = GetLastError();
				Print("[!] CreateFileMapping failed (%d).\n", lastError);
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
				Print("[!] MapViewOfFile failed (%d).\n", lastError);
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
				MessageBoxFormatA("InfinityLoaderCommon", MB_ICONERROR, "[!] MapViewOfFile failed (%d).\n", lastError);
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

PatternEntry::PatternEntry(const String str, const uintptr_t val) :
	name(str), value(val)
{}

OpaqueObjectBoilerplateImp(SharedState, SharedStateData)

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

DWORD loadLuaLibrary(const String& iniPath, const String& luaModeStr, HMODULE& luaLibraryOut) {

	String luaLibraryName;

	bool filled;
	TryRetErr( GetINIStr(iniPath, TEXT("General"), TEXT("LuaLibrary"), luaLibraryName, filled) )

	if (!filled) {
		PrintT(TEXT("[!] [General].LuaLibrary must be defined when [General].LuaPatchMode == \"%s\".\n"), luaModeStr.c_str());
		return -1;
	}

	if (HMODULE hLuaLibrary = LoadLibrary(luaLibraryName.c_str())) {
		luaLibraryOut = hLuaLibrary;
	}
	else {
		DWORD lastError = GetLastError();
		PrintT(TEXT("[!] LoadLibrary failed (%d) to load [General].LuaLibrary \"%s\".\n"), lastError, luaLibraryName.c_str());
		return lastError;
	}

	return ERROR_SUCCESS;
}

DWORD findModuleWithPath(HANDLE process, const String& path, HMODULE& foundModule) {

	HMODULE modules[1024];
	DWORD needed;
	TCHAR nameBuffer[MAX_PATH];

	if (EnumProcessModules(process, modules, sizeof(modules), &needed)) {

		int filledModules = needed / sizeof(HMODULE);

		for (int i = 0; i < filledModules; i++) {

			HMODULE module = modules[i];
			if (!GetModuleFileName(module, nameBuffer, MAX_PATH)) {
				DWORD lastError = GetLastError();
				Print("[!] GetModuleFileName failed (%d).\n", lastError);
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
		Print("[!] EnumProcessModules failed (%d).\n", lastError);
		return lastError;
	}

	return ERROR_SUCCESS;
}

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
	TryRetErr( GetINIStrDef(paths.iniPath, TEXT("General"), TEXT("LuaPatchMode"), TEXT(""), luaModeStr) );

	// Init luaLibrary
	if (luaModeStr == TEXT("INTERNAL")) {
		state.luaMode = LuaMode::INTERNAL;
	}
	else if (luaModeStr == TEXT("EXTERNAL")) {
		state.luaMode = LuaMode::EXTERNAL;
		HMODULE luaLibrary;
		TryRetErr( loadLuaLibrary(paths.iniPath, luaModeStr, luaLibrary) );
		state.luaLibrary = luaLibrary;
	}
	else if (luaModeStr == TEXT("REPLACE_INTERNAL_WITH_EXTERNAL")) {
		state.luaMode = LuaMode::REPLACE_INTERNAL_WITH_EXTERNAL;
		HMODULE luaLibrary;
		TryRetErr( loadLuaLibrary(paths.iniPath, luaModeStr, luaLibrary) );
		state.luaLibrary = luaLibrary;
	}
	else {
		Print("[!] [General].LuaPatchMode must be either \"INTERNAL\", \"EXTERNAL\", or \"REPLACE_INTERNAL_WITH_EXTERNAL\".\n");
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

EXPORT SharedStateMappedMemory& SharedState::MappedMemory() {
	return data()->mappedMemory;
}

EXPORT const String& SharedState::DbPath() {
	return data()->paths.dbPath;
}

EXPORT const String& SharedState::ExePath() {
	return data()->paths.exePath;
}

EXPORT const String& SharedState::ExeName() {
	return data()->paths.exeName;
}

EXPORT const String& SharedState::IniPath() {
	return data()->paths.iniPath;
}

EXPORT const String& SharedState::WorkingFolder() {
	return data()->paths.workingFolder;
}

EXPORT const StringA& SharedState::WorkingFolderA() {
	return data()->paths.workingFolderA;
}

EXPORT long long SharedState::InitTime() {
	return data()->state.initTime;
}

EXPORT void SharedState::InitLuaState(lua_State* L) {
	lua_State*& luaState = data()->state.L;
	if (luaState != nullptr) {
		Print("[!][InfinityLoaderCommon] Attempted to call SharedState::InitLuaState() more than once, ignoring.");
		return;
	}
	luaState = L;
}

EXPORT lua_State* SharedState::LuaState() {
	return data()->state.L;
}

EXPORT HMODULE SharedState::LuaLibrary() {
	return data()->state.luaLibrary;
}

EXPORT LuaMode SharedState::LuaMode() {
	return data()->state.luaMode;
}

EXPORT void SharedState::IteratePatternValues(std::function<bool(const String&, uintptr_t)> func) {
	auto& patterns =  data()->state.patterns;
	for (auto& [key, entry] : patterns) {
		if (func(entry.name, entry.value)) {
			break;
		}
	}
}

EXPORT bool SharedState::GetPatternValue(const String& name, uintptr_t& out) {
	auto& patterns =  data()->state.patterns;
	if (auto found = patterns.find(name); found != patterns.end()) {
		out = found->second.value;
		return true;
	}
	return false;
}

EXPORT void SharedState::SetPatternValue(const String& name, uintptr_t value) {
	auto& patterns =  data()->state.patterns;
	if (auto found = patterns.find(name); found == patterns.end()) {
		patterns.try_emplace(name, name, value);
	}
	else {
		found->second.value = value;
	}
}

EXPORT void SharedState::SetPatternValue(const String& name, void* value) {
	SetPatternValue(name, reinterpret_cast<uintptr_t>(value));
}

bool findSectionInfo(HMODULE module, const char* sectionName, SectionInfo& sectionInfo) {

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

EXPORT uintptr_t SharedState::ImageBase() {
	return data()->state.imageBase;
}

EXPORT DWORD SharedState::LoadSegmentInfo(const StringA& sectionName) {

	HMODULE foundModule;
	TryRetErr( findModuleWithPath(GetCurrentProcess(), data()->paths.exePath, foundModule) )

	auto& sectionInfoMap = data()->state.sectionInfo;
	SectionInfo& pSectionInfo = sectionInfoMap[sectionName];

	if (!findSectionInfo(foundModule, sectionName.c_str(), pSectionInfo)) {
		Print("[!] Failed to locate %s segment.\n", sectionName);
		return -1;
	}

	return ERROR_SUCCESS;
}

EXPORT bool SharedState::GetSegmentPointer(const char* name, void*& out) {
	auto& sectionInfoMap = data()->state.sectionInfo;
	if (auto itr = sectionInfoMap.find(name); itr != sectionInfoMap.end()) {
		out = itr->second.SectionPointer;
		return false;
	}
	return true;
}

EXPORT bool SharedState::GetSegmentSize(const char* name, DWORD& out) {
	auto& sectionInfoMap = data()->state.sectionInfo;
	if (auto itr = sectionInfoMap.find(name); itr != sectionInfoMap.end()) {
		out = itr->second.SectionSize;
		return false;
	}
	return true;
}

EXPORT bool SharedState::GetSegmentPointerAndSize(const char* name, void*& ptrOut, DWORD& sizeOut) {
	auto& sectionInfoMap = data()->state.sectionInfo;
	if (auto itr = sectionInfoMap.find(name); itr != sectionInfoMap.end()) {
		ptrOut = itr->second.SectionPointer;
		sizeOut = itr->second.SectionSize;
		return false;
	}
	return true;
}
