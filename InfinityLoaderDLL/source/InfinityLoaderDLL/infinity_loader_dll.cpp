
#include <filesystem>
#include <iostream>
#include <regex>

#include "asmjit/asmjit.h"
#include "asmtk/asmtk.h"
#include "infinity_loader_common_api.h"
#include "ini_util.hpp"
#include "lua_provider_api.h"
#include "lua_util.hpp"
#include "file_util.hpp"
#include "pointers.h"
#include "protection_util.hpp"

#include <conio.h>
#include <Windows.h>

/////////////
// Structs //
/////////////

struct LoadedBindings {

	enum class LoadState {
		Uninitialized,
		Initialized,
	};

	LoadState loadState = LoadState::Uninitialized;
	HMODULE hHandle;
};

/////////////
// Globals //
/////////////

asmjit::JitRuntime rt;
std::unordered_map<StringA, LoadedBindings> loadedBindingsMap{};

StringA earlyPrintPrefix;
StringA extenderName;
StringA luaGlobalsPrefix;
#define prefixed(str) std::format("{}"##str, luaGlobalsPrefix).c_str()

///////////////////////
// General Functions //
///////////////////////

template<typename CheckFunc>
static asmjit::Error jitAt(uint8_t* dst, asmjit::CodeHolder* code, const CheckFunc checkFunc) noexcept {

	ASMJIT_PROPAGATE(code->flatten());
	ASMJIT_PROPAGATE(code->resolveUnresolvedLinks());

	size_t estimatedCodeSize = code->codeSize();
	if (ASMJIT_UNLIKELY(estimatedCodeSize == 0))
		return asmjit::DebugUtils::errored(asmjit::kErrorNoCodeGenerated);

	// Recalculate the final code size and shrink the memory we allocated for it
	// in case that some relocations didn't require records in an address table.
	size_t codeSize;

	while (true) {
		// Relocate the code.
		asmjit::Error err = code->relocateToBase(reinterpret_cast<uint64_t>(dst));
		if (ASMJIT_UNLIKELY(err)) {
			return err;
		}

		codeSize = code->codeSize();
		uint8_t* newDst = checkFunc(codeSize);
		if (newDst == reinterpret_cast<uint8_t*>(-1))
			return asmjit::kErrorOk;
		else if (newDst)
			dst = newDst;
		else
			break;
	}

	for (asmjit::Section* section : code->_sections) {
		size_t offset = size_t(section->offset());
		size_t bufferSize = size_t(section->bufferSize());
		size_t virtualSize = size_t(section->virtualSize());

		ASMJIT_ASSERT(offset + bufferSize <= codeSize);
		memcpy(dst + offset, section->data(), bufferSize);

		if (virtualSize > bufferSize) {
			ASMJIT_ASSERT(offset + virtualSize <= codeSize);
			memset(dst + offset + bufferSize, 0, virtualSize - bufferSize);
		}
	}

	rt.flush(dst, codeSize);
	return asmjit::kErrorOk;
}

template<typename out_type>
static DWORD getLuaProc(const char* name, out_type& out) {
	if (out = reinterpret_cast<out_type>(GetProcAddress(luaLibrary(), name)); out == 0) {
		DWORD lastError = GetLastError();
		FPrint("[!][InfinityLoaderDLL.dll] getLuaProc() - GetProcAddress() failed (%d) to find Lua function \"%s\"\n", lastError, name);
		return lastError;
	}
	return 0;
}

//////////////////////
// Pattern Matching //
//////////////////////

template<typename Func>
static void forEveryINISectionName(const String iniPath, const Func action) {

	DWORD numChars = 1024;
	TCHAR* buffer = new TCHAR[numChars];

	DWORD numRead = GetPrivateProfileSectionNames(buffer, numChars, iniPath.c_str());
	while (numRead == (numChars - 2)) {
		delete[] buffer;
		numChars *= 2;
		buffer = new TCHAR[numChars];
		numRead = GetPrivateProfileSectionNames(buffer, numChars, iniPath.c_str());
	}

	size_t lastI = 0;
	for (size_t i = 0; i < numRead; ++i) {
		if (buffer[i] == TCHAR{ '\0' }) {
			if (action(String{ &buffer[lastI], i - lastI })) {
				return;
			}
			lastI = i + 1;
		}
	}

	delete[] buffer;
}

static long long getFileLastModifiedTime(String filePath) {

	// IMPORTANT: std::chrono::clock_cast() loads icu.dll, which is only present
	// on Windows versions >= 1903 (May 2019 Update). Using it breaks compatibility
	// with older Windows versions and Wine / Proton!

	//const auto fileTime = std::filesystem::last_write_time(filePath);
	//if (!protonCompatibility) {
	//	const auto systemTime = std::chrono::clock_cast<std::chrono::system_clock>(fileTime);
	//	return std::chrono::duration_cast<std::chrono::milliseconds>(systemTime.time_since_epoch()).count();
	//}
	//else {
	//	const auto systemTime = fileTime;
	//	return std::chrono::duration_cast<std::chrono::milliseconds>(systemTime.time_since_epoch()).count();
	//}

	const auto fileTime = std::filesystem::last_write_time(filePath);
	return std::chrono::duration_cast<std::chrono::milliseconds>(fileTime.time_since_epoch()).count();
}

static DWORD findPatterns(void* sectionPtr, DWORD sectionSize) {

	bool alreadyCached;
	long long cachedExeTime;

	if (DWORD lastError = GetINILongLong(iniPath(), TEXT("Auto-Generated"), TEXT("CachedExeTime"), cachedExeTime, alreadyCached)) {
		return lastError;
	}

	const long long exeLastModifiedTime = getFileLastModifiedTime(exePath());

	if (alreadyCached) {
		if (debug()) {
			FPrint("[?][InfinityLoaderDLL.dll] findPatterns() - exeLastModifiedTime: %lld, CachedExeTime: %lld\n", exeLastModifiedTime, cachedExeTime);
		}
		if (exeLastModifiedTime == cachedExeTime) {
			attemptUseCached = true;
		}
	}

	if (!attemptUseCached) {
		if (DWORD lastError = SetINILongLong(iniPath(), TEXT("Auto-Generated"), TEXT("CachedExeTime"), exeLastModifiedTime)) {
			return lastError;
		}
	}

	if (debug()) {
		FPrint("[?][InfinityLoaderDLL.dll] findPatterns() - Using cached pattern addresses: %s\n", attemptUseCached ? "true" : "false");
	}

	if (luaMode() == LuaMode::INTERNAL) {
		// Required by LuaProvider.dll
		PatternValueHandle unused;
		findINICategoryPattern(sectionPtr, sectionSize, iniPath(), TEXT("Hardcoded_luaL_loadfilexptr"), unused);
		findINICategoryPattern(sectionPtr, sectionSize, iniPath(), TEXT("Hardcoded_wfopen"), unused);
	}

	DWORD returnVal = 0;
	forEveryINISectionName(dbPath(), [&](const String section) {

		if (section.rfind(TEXT("!"), 0) != std::string::npos) {
			return false;
		}

		PatternValueHandle patternValue;
		if (returnVal = findINICategoryPattern(sectionPtr, sectionSize, dbPath(), section.c_str(), patternValue)) {
			return true;
		}

		return false;
	});

	return returnVal;
}

///////////////////
// Lua Functions //
///////////////////

static int addToLuaRegistryLua(lua_State* L) {
	lua_pushvalue(L, 1);
	lua_pushinteger(L, luaL_ref(L, LUA_REGISTRYINDEX));
	return 1;
}

static int allocCodePageInternalLua(lua_State* L) {

	SYSTEM_INFO info;
	GetSystemInfo(&info);

	uintptr_t allocated;
	if (AllocateNear(sharedState().ImageBase(), info.dwAllocationGranularity, allocated)) {
		return 0;
	}

	lua_pushinteger(L, allocated);                    // [ address ]
	lua_pushinteger(L, info.dwAllocationGranularity); // [ address, size ]
	return 2;
}

typedef std::make_unsigned<lua_Integer>::type UnsignedLuaInt;

static int bandLua(lua_State* L) {
	lua_pushinteger(L, static_cast<UnsignedLuaInt>(lua_tointeger(L, 1)) & static_cast<UnsignedLuaInt>(lua_tointeger(L, 2)));
	return 1;
}

static int bnotLua(lua_State* L) {
	lua_pushinteger(L, ~static_cast<UnsignedLuaInt>(lua_tointeger(L, 1)));
	return 1;
}

static int borLua(lua_State* L) {
	lua_pushinteger(L, static_cast<UnsignedLuaInt>(lua_tointeger(L, 1)) | static_cast<UnsignedLuaInt>(lua_tointeger(L, 2)));
	return 1;
}

static int cFunctionToPointerLua(lua_State* L) {
	lua_pushinteger(L, reinterpret_cast<lua_Integer>(lua_tocfunction(L, 1)));
	return 1;
}

static int disableCodeProtectionLua(lua_State* L) {
	disableCodeProtection();
	return 0;
}

static int doFileLua(lua_State* L) {
	callScriptFileA(L, lua_tostring(L, 1));
	return 0;
}

static int enableCodeProtectionLua(lua_State* L) {
	enableCodeProtection();
	return 0;
}

static int exposeToLuaLua(lua_State* L) {
	exposeToLua(L, lua_tostring(L, 2), reinterpret_cast<lua_CFunction>(lua_tointeger(L, 1)));
	return 0;
}

static int extractLua(lua_State* L) {
	UnsignedLuaInt num = lua_tointeger(L, 1);
	UnsignedLuaInt start = lua_tointeger(L, 2);
	UnsignedLuaInt len = lua_tointeger(L, 3);
	UnsignedLuaInt mask = 0x0;
	for (UnsignedLuaInt i = 0; i < len; ++i) {
		mask = (mask << 1) | 1;
	}
	lua_pushinteger(L, (num >> start) & mask);
	return 1;
}

static int freeLua(lua_State* L) {
	void* ptr = reinterpret_cast<void*>(lua_tointeger(L, 1));
	p_free(ptr);
	return 0;
}

static int getProcAddressLua(lua_State* L) {
	const HMODULE hModule = reinterpret_cast<HMODULE>(lua_tointeger(L, 1));
	const FARPROC proc = GetProcAddress(hModule, lua_tostring(L, 2));
	lua_pushinteger(L, reinterpret_cast<lua_Integer>(proc));
	return 1;
}

static int getLuaRegistryIndexLua(lua_State* L) {
	castLuaIntArg(1, int, Int, n)
	lua_rawgeti(L, LUA_REGISTRYINDEX, n);
	return 1;
}

static int getLuaLibraryProcLua(lua_State* L) {
	uintptr_t address;
	if (getLuaProc(lua_tostring(L, 1), address)) {
		return 0;
	}
	lua_pushinteger(L, address);
	return 1;
}

static int getMicrosecondsLua(lua_State* L) {
	lua_pushinteger(L, static_cast<lua_Integer>(CurrentMicroseconds() - initTime()));
	return 1;
}

static int getPatternMapLua(lua_State* L) {
	lua_pushstring(L, "InfinityLoader_Patterns"); // 1 [ "InfinityLoader_Patterns" ]
	lua_rawget(L, LUA_REGISTRYINDEX);             // 1 [ registry["InfinityLoader_Patterns"] ]
	return 1;
}

static int iterateRegexLua(lua_State* L) {

	const char* str = lua_tostring(L, 1);
	const char* strEnd = str;
	while (*strEnd) ++strEnd;
	std::regex pattern{ lua_tostring(L, 2) };
	std::cregex_iterator foundBegin{ str, strEnd, pattern };
	std::cregex_iterator foundEnd;

	lua_getglobal(L, "debug");                                                                   // [ debug ]
	lua_getfield(L, -1, "traceback");                                                            // [ debug, traceback ]

	for (std::cregex_iterator& i = foundBegin; i != foundEnd; ++i) {

		const std::cmatch& match = *i;
		lua_pushvalue(L, 3);                                                                     // [ debug, traceback, func ]
		lua_pushinteger(L, match.position() + 1);                                                // [ debug, traceback, func, pos ]
		lua_pushinteger(L, match.position() + match.length());                                   // [ debug, traceback, func, pos, endPos ]
		lua_pushstring(L, match.str().c_str());                                                  // [ debug, traceback, func, pos, endPos, str ]

		lua_newtable(L);                                                                         // [ debug, traceback, func, pos, endPos, str, groups ]
		for (size_t i = 1; i < match.size(); ++i) {
			const std::csub_match& subMatch = match[i];
			lua_pushinteger(L, i);                                                               // [ debug, traceback, func, pos, endPos, str, groups, k ]
			if (!subMatch.length()) {
				lua_pushnil(L);                                                                  // [ debug, traceback, func, pos, endPos, str, groups, k, nil ]
			}
			else {
				lua_pushstring(L, subMatch.str().c_str());                                       // [ debug, traceback, func, pos, endPos, str, groups, k, v ]
			}
			lua_rawset(L, -3);                                                                   // [ debug, traceback, func, pos, endPos, str, groups ]
		}

		if (lua_pcallk(L, 4, 1, -6, 0, nullptr) != LUA_OK) {
																								 // [ debug, traceback, errorMessage ]
			FPrint("[!][InfinityLoaderDLL.dll] %sIterateRegex() - %s\n", luaGlobalsPrefix.c_str(), lua_tostring(L, -1));
			lua_pop(L, 1);                                                                       // [ debug, traceback ]
			break;
		}
		else {
																								 // [ debug, traceback, ret ]
			int retVal = lua_toboolean(L, -1);
			lua_pop(L, 1);                                                                       // [ debug, traceback ]
			if (retVal) {
				break;
			}
		}
	}

	lua_pop(L, 2);                                                                               // [ ]
	return 0;
}

static int jitLua(lua_State* L) {

	asmjit::CodeHolder code;
	code.init(rt.environment());

	asmjit::x86::Assembler a(&code);
	asmtk::AsmParser p(&a);

	if (asmjit::Error err = p.parse(lua_tostring(L, 1))) {
		FPrint("[!][InfinityLoaderDLL.dll] %sJIT() - AsmJit failed: %s\n", luaGlobalsPrefix.c_str(), asmjit::DebugUtils::errorAsString(err));
		return 0;
	}

	void* ptr;
	if (asmjit::Error err = rt.add(&ptr, &code)) {
		FPrint("[!][InfinityLoaderDLL.dll] %sJIT() - AsmJit failed: %s\n", luaGlobalsPrefix.c_str(), asmjit::DebugUtils::errorAsString(err));
		return 0;
	}

	lua_pushinteger(L, reinterpret_cast<uintptr_t>(ptr));
	return 1;
}

static int jitAtInternalLua(lua_State* L) {

	asmjit::CodeHolder code;
	code.init(rt.environment());

	asmjit::x86::Assembler a(&code);
	asmtk::AsmParser p(&a);

	if (asmjit::Error err = p.parse(lua_tostring(L, 3))) {
		FPrint("[!][InfinityLoaderDLL.dll] %sJITAtInternal() - AsmJit failed: %s\n", luaGlobalsPrefix.c_str(), asmjit::DebugUtils::errorAsString(err));
		return 0;
	}

	auto checkFunc = [&](size_t size) {

		lua_getglobal(L, "debug");                                                                                              // [ debug ]
		lua_getfield(L, -1, "traceback");                                                                                       // [ debug, traceback ]

		lua_pushvalue(L, 2);                                                                                                    // [ debug, traceback, func ]
		lua_pushinteger(L, size);                                                                                               // [ debug, traceback, func, size ]
		if (lua_pcallk(L, 1, 1, -3, 0, nullptr) != LUA_OK) {
																																// [ debug, traceback, errorMessage ]
			FPrint("[!][InfinityLoaderDLL.dll] %sJITAtInternal() - AsmJit failed: %s\n", luaGlobalsPrefix.c_str(), lua_tostring(L, -1));
			lua_pop(L, 3);                                                                                                      // [ ]
			return reinterpret_cast<uint8_t*>(-1);
		}
																																// [ debug, traceback, result ]
		uint8_t* newDst = reinterpret_cast<uint8_t*>(lua_tointeger(L, -1));
		lua_pop(L, 3);                                                                                                          // [ ]
		return newDst;
	};

	if (asmjit::Error err = jitAt(reinterpret_cast<uint8_t*>(lua_tointeger(L, 1)), &code, checkFunc)) {
		FPrint("[!][InfinityLoaderDLL.dll] %sJITAtInternal() - AsmJit failed: %s\n", luaGlobalsPrefix.c_str(), asmjit::DebugUtils::errorAsString(err));
		return 0;
	}

	return 0;
}

static bool initializeLuaBindings(const char *const bindingsFileName, LoadedBindings& loadedBindings) {

	const StringA bindingsPath = StringA{ workingFolderA() }.append(bindingsFileName).append(".dll");

	if (loadedBindings.hHandle = LoadLibraryA(bindingsPath.c_str()); !loadedBindings.hHandle) {
		FPrint("[!][InfinityLoaderDLL.dll] initializeLuaBindings() - LoadLibraryA(\"%s\") failed (%d)\n", bindingsPath.c_str(), GetLastError());
		return true;
	}

	FARPROC initProcFar;
	if (initProcFar = GetProcAddress(loadedBindings.hHandle, "InitBindings"); !initProcFar) {
		FPrint("[!][InfinityLoaderDLL.dll] initializeLuaBindings() - GetProcAddress() failed (%d)\n", GetLastError());
		return true;
	}

	typedef void(__stdcall* type_Init)(SharedState);
	const type_Init initProc = reinterpret_cast<type_Init>(initProcFar);
	initProc(sharedState());

	loadedBindings.loadState = LoadedBindings::LoadState::Initialized;
	return false;
}

static int loadLibraryLua(lua_State *const L) {
	const HMODULE hModule = LoadLibraryA(lua_tostring(L, 1));
	lua_pushinteger(L, reinterpret_cast<lua_Integer>(hModule));
	return 1;
}

static int openLuaBindingsLua(lua_State *const L) {

	const char *const bindingsFileName = lua_tolstring(L, 1, nullptr);
	LoadedBindings& loadedBindings = loadedBindingsMap[bindingsFileName];

	// Initialize the dll if it hasn't been initialized already

	if (loadedBindings.loadState == LoadedBindings::LoadState::Uninitialized
		&& initializeLuaBindings(bindingsFileName, loadedBindings))
	{
		return 0;
	}

	// Check if the dll's bindings have already been opened for the given Lua state

	const StringA openedKey = StringA{ "InfinityLoader_" }.append(bindingsFileName).append("_Opened");

	lua_pushstring(L, openedKey.c_str()); // 1 [ openedKey ]
	lua_rawget(L, LUA_REGISTRYINDEX);     // 1 [ registry[openedKey] ]

	if (lua_toboolean(L, -1)) {
		lua_pop(L, 1);                    // 0 [ ]
		return 0;
	}

	lua_pushstring(L, openedKey.c_str()); // 2 [ registry[openedKey], openedKey ]
	lua_pushboolean(L, true);             // 3 [ registry[openedKey], openedKey, true ]
	lua_rawset(L, LUA_REGISTRYINDEX);     // 1 [ registry[openedKey] ]
	lua_pop(L, 1);                        // 0 [ ]

	// Call dll's OpenBindings()

	FARPROC openBindingsProcFar;
	if (openBindingsProcFar = GetProcAddress(loadedBindings.hHandle, "OpenBindings"); !openBindingsProcFar) {
		FPrint("[!][InfinityLoaderDLL.dll] %sOpenLuaBindings() - GetProcAddress() failed (%d)\n", luaGlobalsPrefix.c_str(), GetLastError());
		return 0;
	}

	typedef void(__stdcall* type_OpenBindings)();
	const type_OpenBindings openBindingsProc = reinterpret_cast<type_OpenBindings>(openBindingsProcFar);
	openBindingsProc();

	return 0;
}

static int initializeLuaBindingsLua(lua_State* L) {

	const char* bindingsFileName = lua_tolstring(L, 1, nullptr);
	LoadedBindings& loadedBindings = loadedBindingsMap[bindingsFileName];

	if (loadedBindings.loadState != LoadedBindings::LoadState::Uninitialized) {
		return 0;
	}

	initializeLuaBindings(bindingsFileName, loadedBindings);
	return 0;
}

static int lshiftLua(lua_State* L) {
	lua_pushinteger(L, static_cast<UnsignedLuaInt>(lua_tointeger(L, 1)) << static_cast<UnsignedLuaInt>(lua_tointeger(L, 2)));
	return 1;
}

static int mallocLua(lua_State* L) {
	castLuaIntArg(1, size_t, SizeT, size)
	lua_pushinteger(L, reinterpret_cast<lua_Integer>(p_malloc(size)));
	return 1;
}

static int memcpyLua(lua_State* L) {
	castLuaIntArg(3, size_t, SizeT, size)
	memcpy(reinterpret_cast<void*>(lua_tointeger(L, 1)), reinterpret_cast<void*>(lua_tointeger(L, 2)), size);
	return 0;
}

static int memsetLua(lua_State* L) {
	castLuaIntArg(2, int, Int, val)
	castLuaIntArg(3, size_t, SizeT, size)
	memset(reinterpret_cast<void*>(lua_tointeger(L, 1)), val, size);
	return 0;
}

static int messageBoxInternalLua(lua_State* L) {
	castLuaIntArg(2, UINT, UInt, uType)
	MessageBoxA(NULL, lua_tostring(L, 1), extenderName.c_str(), uType);
	return 0;
}

static int printLua(lua_State* L) {
	Print(lua_tostring(L, 1));
	return 0;
}

static int printErrLua(lua_State* L) {
	PrintErr(lua_tostring(L, 1));
	return 0;
}

static int processThreadQueueLua(lua_State* L) {
	sharedState().ProcessThreadQueue();
	return 0;
}

static int read16Lua(lua_State* L) {
	lua_pushinteger(L, *reinterpret_cast<__int16*>(lua_tointeger(L, 1)));
	return 1;
}

static int read32Lua(lua_State* L) {
	lua_pushinteger(L, *reinterpret_cast<__int32*>(lua_tointeger(L, 1)));
	return 1;
}

#if defined(_WIN64)
static int read64Lua(lua_State* L) {
	lua_pushinteger(L, *reinterpret_cast<__int64*>(lua_tointeger(L, 1)));
	return 1;
}
#endif

static int read8Lua(lua_State* L) {
	lua_pushinteger(L, *reinterpret_cast<__int8*>(lua_tointeger(L, 1)));
	return 1;
}

static int readPointerLua(lua_State* L) {
	lua_pushinteger(L, *reinterpret_cast<uintptr_t*>(lua_tointeger(L, 1)));
	return 1;
}

static int readU16Lua(lua_State* L) {
	lua_pushinteger(L, *reinterpret_cast<unsigned __int16*>(lua_tointeger(L, 1)));
	return 1;
}

static int readU32Lua(lua_State* L) {
	lua_pushinteger(L, *reinterpret_cast<unsigned __int32*>(lua_tointeger(L, 1)));
	return 1;
}

#if defined(_WIN64)
static int readU64Lua(lua_State* L) {
	lua_pushinteger(L, *reinterpret_cast<unsigned __int64*>(lua_tointeger(L, 1)));
	return 1;
}
#endif

static int readU8Lua(lua_State* L) {
	lua_pushinteger(L, *reinterpret_cast<unsigned __int8*>(lua_tointeger(L, 1)));
	return 1;
}

static int readLString(lua_State* L) {
	const char *const data { reinterpret_cast<char*>(lua_tointeger(L, 1)) };
	castLuaIntArg(2, size_t, SizeT, length)
	char *const localCopy { reinterpret_cast<char*>(alloca(length + 1)) };
	size_t i { 0 };
	for (; i < length; ++i) {
		const char readVal { data[i] };
		if (readVal == '\0') {
			break;
		}
		localCopy[i] = readVal;
	}
	localCopy[i] = '\0';
	lua_pushstring(L, localCopy);
	return 1;
}

static int readString(lua_State* L) {
	lua_pushstring(L, reinterpret_cast<const char*>(lua_tointeger(L, 1)));
	return 1;
}

static int rshiftLua(lua_State* L) {
	lua_pushinteger(L, static_cast<UnsignedLuaInt>(lua_tointeger(L, 1)) >> static_cast<UnsignedLuaInt>(lua_tointeger(L, 2)));
	return 1;
}

static int runWithStackLua(lua_State* L) {

	castLuaIntArg(1, size_t, SizeT, size)

	lua_getglobal(L, "debug");                                                               // [ debug ]
	lua_getfield(L, -1, "traceback");                                                        // [ debug, traceback ]
	lua_pushvalue(L, 2);                                                                     // [ debug, traceback, func ]

	void* mem = alloca(size);
	lua_pushinteger(L, reinterpret_cast<lua_Integer>(mem));                                  // [ debug, traceback, func, stackPtr ]

	if (lua_pcallk(L, 1, 0, -3, 0, nullptr) != LUA_OK) {
																							 // [ debug, traceback, errorMessage ]
		FPrint("[!][InfinityLoaderDLL.dll] %sRunWithStack() - %s\n", luaGlobalsPrefix.c_str(), lua_tostring(L, -1));
		lua_pop(L, 3);                                                                       // [ ]
	}
	else {
																							 // [ debug, traceback ]
		lua_pop(L, 2);                                                                       // [ ]
	}

	return 0;
}

static int runWithString(lua_State* L) {

	lua_getglobal(L, "debug");                                           // [ debug ]
	lua_getfield(L, -1, "traceback");                                    // [ debug, traceback ]
	lua_pushvalue(L, 2);                                                 // [ debug, traceback, func ]

	lua_pushinteger(L, reinterpret_cast<uintptr_t>(lua_tostring(L, 1)));

	if (lua_pcallk(L, 1, 0, -3, 0, nullptr) != LUA_OK) {
																		 // [ debug, traceback, errorMessage ]
		FPrint("[!][InfinityLoaderDLL.dll] %sRunWithString() - %s\n", luaGlobalsPrefix.c_str(), lua_tostring(L, -1));
		lua_pop(L, 3);                                                   // [ ]
	}
	else {
																		 // [ debug, traceback ]
		lua_pop(L, 2);                                                   // [ ]
	}

	return 0;
}

static int selectFromTablesLua(lua_State* L) {

	const int nStackTop = lua_gettop(L);

	if (nStackTop % 3 != 0) {
		luaL_error(L, "Expected number of args to be a multiple of 3 (got %d)", nStackTop);
	}

	int nTotalLength = 0;

	for (int i = 1; i <= nStackTop; i += 3) {

		if (lua_type(L, i) != LUA_TNUMBER) {
			luaL_error(L, "Expected number (nStart) at arg %d", i);
		}

		const int nLengthI = i + 1;
		if (lua_type(L, i) != LUA_TNUMBER) {
			luaL_error(L, "Expected number (nLength) at arg %d", nLengthI);
		}

		const int nTableI = i + 2;
		if (lua_type(L, nTableI) != LUA_TTABLE) {
			luaL_error(L, "Expected table at arg %d", nTableI);
		}

		castLuaIntArg(i, int, Int, nStart)
		castLuaIntArg(nLengthI, int, Int, nLength)

		if (nLength == -1) {
			int j = nStart;
			while (true) {
				lua_rawgeti(L, nTableI, j++);
				if (lua_type(L, -1) == LUA_TNIL) {
					lua_pop(L, 1);
					break;
				}
				++nTotalLength;
			}
		}
		else {
			int end = nStart + nLength;
			for (int j = nStart; j < end; ++j) {
				lua_rawgeti(L, nTableI, j);
			}
			nTotalLength += nLength;
		}
	}

	return nTotalLength;
}

static int setLuaRegistryIndexLua(lua_State* L) {
	castLuaIntArg(1, int, Int, n)
	lua_pushvalue(L, 2);
	lua_rawseti(L, LUA_REGISTRYINDEX, n);
	return 0;
}

static int setSegmentProtectionLua(lua_State* L) {
	const char *const segmentName = lua_tostring(L, 1);
	castLuaIntArg(2, unsigned __int32, UInt32, protectionFlags)
	setSegmentProtection(segmentName, protectionFlags);
	return 0;
}

static int temporaryPrintReplacementLua(lua_State* L) {
	const int top = lua_gettop(L);
	for (int index = 1; index <= top; ++index) {
		if (!lua_isstring(L, index)) {
			FPrint("Unable to convert arg %d a %s to string\n", index, lua_typename(L, index));
		}
		else {
			FPrint("%s%s\n", earlyPrintPrefix.c_str(), lua_tolstring(L, index, nullptr));
		}
	}
	return 0;
}

static int toDecimalStringLua(lua_State* L) {
	static_assert(std::is_same<lua_Integer, ptrdiff_t>::value, "Expected lua_Integer type");
	lua_pushstring(L, PtrDiffToDecStrA(lua_tointeger(L, 1)).c_str());
	return 1;
}

static int write16Lua(lua_State* L) {
	castLuaIntArg(2, __int16, Int16, val)
	*reinterpret_cast<__int16*>(lua_tointeger(L, 1)) = val;
	return 0;
}

static int write32Lua(lua_State* L) {
	castLuaIntArg(2, __int32, Int32, val)
	*reinterpret_cast<__int32*>(lua_tointeger(L, 1)) = val;
	return 0;
}

#if defined(_WIN64)
static int write64Lua(lua_State* L) {
	castLuaIntArg(2, __int64, Int64, val)
	*reinterpret_cast<__int64*>(lua_tointeger(L, 1)) = val;
	return 0;
}
#endif

static int write8Lua(lua_State* L) {
	castLuaIntArg(2, __int8, Int8, val)
	*reinterpret_cast<__int8*>(lua_tointeger(L, 1)) = val;
	return 0;
}

static int writePointerLua(lua_State* L) {
	*reinterpret_cast<uintptr_t*>(lua_tointeger(L, 1)) = lua_tointeger(L, 2);
	return 0;
}

static int writeU16Lua(lua_State* L) {
	castLuaIntArg(2, unsigned __int16, UInt16, val)
	*reinterpret_cast<unsigned __int16*>(lua_tointeger(L, 1)) = val;
	return 0;
}

static int writeU32Lua(lua_State* L) {
	castLuaIntArg(2, unsigned __int32, UInt32, val)
	*reinterpret_cast<unsigned __int32*>(lua_tointeger(L, 1)) = val;
	return 0;
}

static int writeU64Lua(lua_State* L) {
	castLuaIntArg(2, unsigned __int64, UInt64, val)
	*reinterpret_cast<unsigned __int64*>(lua_tointeger(L, 1)) = val;
	return 0;
}

static int writeU8Lua(lua_State* L) {
	castLuaIntArg(2, unsigned __int8, UInt8, val)
	*reinterpret_cast<unsigned __int8*>(lua_tointeger(L, 1)) = val;
	return 0;
}

static int writeLStringLua(lua_State* L) {

	char* dst = reinterpret_cast<char*>(lua_tointeger(L, 1));
	const char* src = lua_tostring(L, 2);
	castLuaIntArg(3, size_t, SizeT, limit)

	const char *const dstLimit = dst + limit;

	for (; dst < dstLimit; ++src) {
		const char srcChar = *src;
		*dst++ = srcChar;
		if (srcChar == '\0') {
			break;
		}
	}

	for (; dst < dstLimit; ++dst) {
		*dst = '\0';
	}

	return 0;
}

static int writeStringLua(lua_State* L) {
	char* writePtr = reinterpret_cast<char*>(lua_tointeger(L, 1));
	const char* str = lua_tostring(L, 2);
	while (true) {
		const char existingChar = *str++;
		*writePtr++ = existingChar;
		if (existingChar == '\0') {
			break;
		}
	}
	return 0;
}

static int writeStringAutoLua(lua_State* L) {
	const char* str = lua_tostring(L, 1);
	size_t len = strlen(str);
	char* newStr = reinterpret_cast<char*>(p_malloc(len + 1));
	char* newStrWPtr = newStr;
	for (size_t i = 0; i < len; ++i) {
		*newStrWPtr++ = *str++;
	}
	*newStrWPtr = '\0';
	lua_pushinteger(L, reinterpret_cast<uintptr_t>(newStr));
	return 1;
}

////////////////////////////
// START Pattern Tracking //
////////////////////////////

// Expects: 0 [ t, k, v ]
static int onPatternMapChanged(lua_State* L) {

	const char *const patternName = lua_tostring(L, 2);
	const uintptr_t patternValue = lua_tointeger(L, 3);

	setSinglePatternValue(NulTermStrToStr(patternName), patternValue);
	lua_rawset(L, 1);
	return 0;
}

// Expects:   0 [ ... ]
// End Stack: 1 [ ..., registry["InfinityLoader_Patterns"] ]
static void pushPatternsTable(lua_State* L) {

	lua_pushstring(L, "InfinityLoader_Patterns");     // 1 [ ..., "InfinityLoader_Patterns" ]
	lua_rawget(L, LUA_REGISTRYINDEX);                 // 1 [ ..., registry["InfinityLoader_Patterns"] ]

	if (lua_isnil(L, -1)) {

		lua_pop(L, 1);                                // 0 [ ... ]
		lua_newtable(L);                              // 1 [ ..., t ]

		lua_newtable(L);                              // 2 [ ..., t, mt ]
		lua_pushstring(L, "__newindex");              // 3 [ ..., t, mt, "__newindex" ]
		lua_pushcfunction(L, onPatternMapChanged);    // 4 [ ..., t, mt, "__newindex", onPatternMapChanged ]
		lua_rawset(L, -3);                            // 2 [ ..., t, mt ]

		lua_setmetatable(L, -2);                      // 1 [ ..., t ]

		lua_pushstring(L, "InfinityLoader_Patterns"); // 2 [ ..., t, "InfinityLoader_Patterns" ]
		lua_pushvalue(L, -2);                         // 3 [ ..., t, "InfinityLoader_Patterns", t ]
		lua_rawset(L, LUA_REGISTRYINDEX);             // 1 [ ..., t -> registry["InfinityLoader_Patterns"] ]
	}
}

// Expects:   1 [ ..., registry["InfinityLoader_Patterns"] -> patternsT ]
// End Stack: 1 [ ..., patternsT ]
static void rawsetSinglePatternValue(lua_State *const L, const PatternValueHandle handle, const uintptr_t newAddress) {
	const String& name = sharedState().GetPatternValueName(handle);
	const StringA nameA = StrToStrA(name);
	lua_pushstring(L, nameA.c_str());                               // 2 [ ..., patternsT, name ]
	lua_pushinteger(L, newAddress);                                 // 3 [ ..., patternsT, name, value ]
	lua_rawset(L, -3);                                              // 1 [ ..., patternsT ]
}

// Expects:   1 [ ..., registry["InfinityLoader_Patterns"] -> patternsT ]
// End Stack: 2 [ ..., patternsT, patternsT[patternName(handle)] ]
static void pushListPatternTable(lua_State *const L, const PatternValueHandle handle) {

	const String& name = sharedState().GetPatternValueName(handle);
	const StringA nameA = StrToStrA(name);

	lua_pushstring(L, nameA.c_str());                               // 2 [ ..., patternsT, name ]
	lua_rawget(L, -2);                                              // 2 [ ..., patternsT, patternsT[name] -> listT ]

	if (!lua_istable(L, -1)) {
		lua_pop(L, 1);                                              // 1 [ ..., patternsT ]
		lua_newtable(L);                                            // 2 [ ..., patternsT, newT ]
		lua_pushstring(L, nameA.c_str());                           // 3 [ ..., patternsT, newT, name ]
		lua_pushvalue(L, -2);                                       // 4 [ ..., patternsT, newT, name, newT ]
		lua_rawset(L, -4);                                          // 2 [ ..., patternsT, newT -> listT ]
		lua_pushinteger(L, 0);                                      // 3 [ ..., patternsT, listT, size ]
		lua_rawseti(L, -2, 0);                                      // 2 [ ..., patternsT, listT ]
	}
}

// Expects:   0 [ ... ]
// End Stack: 0 [ ... ]
static void exportExistingPatterns(lua_State *const L) {

	pushPatternsTable(L);                                                             // 1 [ ..., patternsT ]

	sharedState().IteratePatternValues([&](const PatternValueHandle handle) -> bool {

		const PatternValueType type = sharedState().GetPatternValueType(handle);
		if (type == PatternValueType::SINGLE) {
			const uintptr_t value = sharedState().GetSinglePatternValue(handle);
			rawsetSinglePatternValue(L, handle, value);
		}
		else if (type == PatternValueType::LIST) {

			pushListPatternTable(L, handle);                                          // 2 [ ..., patternsT, listT ]
			lua_rawgeti(L, -1, 0);                                                    // 3 [ ..., patternsT, listT, size ]
			int size = static_cast<int>(lua_tointeger(L, -1));

			sharedState().IteratePatternList(handle, [&](uintptr_t newAddress) {
				lua_pushinteger(L, newAddress);                                       // 4 [ ..., patternsT, listT, size, newAddress ]
				lua_rawseti(L, -3, ++size);                                           // 3 [ ..., patternsT, listT, size ]
				return false;
			});
																					  // 3 [ ..., patternsT, listT, size ]
			lua_pushinteger(L, size);                                                 // 4 [ ..., patternsT, listT, size, newSize ]
			lua_rawseti(L, -3, 0);                                                    // 3 [ ..., patternsT, listT, size ]
			lua_pop(L, 2);                                                            // 1 [ ..., patternsT ]
		}

		return false;
	});

	lua_pop(L, 1);                                                                    // 0 [ ... ]
}

static void onLuaStateInitialized(lua_State *const L) {
	exportExistingPatterns(L);
}

static void onAfterPatternModified(const PatternValueHandle handle, const uintptr_t newAddress) {

	if (lua_State *const L = luaState(); L != nullptr) {

		pushPatternsTable(L);                                                    // 1 [ ..., patternsT ]

		const PatternValueType type = sharedState().GetPatternValueType(handle);
		if (type == PatternValueType::SINGLE) {
			uintptr_t value = sharedState().GetSinglePatternValue(handle);
			rawsetSinglePatternValue(L, handle, value);
		}
		else if (type == PatternValueType::LIST) {
			pushListPatternTable(L, handle);                                     // 2 [ ..., patternsT, listT ]
			lua_rawgeti(L, -1, 0);                                               // 3 [ ..., patternsT, listT, size ]
			const int newSize = static_cast<int>(lua_tointeger(L, -1)) + 1;
			lua_pushinteger(L, newSize);                                         // 4 [ ..., patternsT, listT, size, newSize ]
			lua_pushinteger(L, newAddress);                                      // 5 [ ..., patternsT, listT, size, newSize, newAddress ]
			lua_rawseti(L, -4, newSize);                                         // 4 [ ..., patternsT, listT, size, newSize ]
			lua_rawseti(L, -3, 0);                                               // 3 [ ..., patternsT, listT, size ]
			lua_pop(L, 3);                                                       // 0 [ ... ]
		}

		lua_pop(L, 1);                                                           // 0 [ ... ]
	}
}

static void initPatternTracking() {
	// Callback that exports all existing patterns
	sharedState().AddLuaStateInitializedCallback(onLuaStateInitialized);
	// Listener that exports future patterns when they are set
	sharedState().AddAfterPatternModifiedListener(onAfterPatternModified);
}

//////////////////////////
// END Pattern Tracking //
//////////////////////////

////////////////////
// Initialization //
////////////////////

static void bindToParentOSHandles() {

	// The strategy:
	//
	//   1) AttachConsole(), (which should have been called before this), attaches to the target console
	//      and sets STD_INPUT_HANDLE/STD_OUTPUT_HANDLE/STD_ERROR_HANDLE to new HANDLEs. However, since
	//      these handles are newly-created, they do not inherit any of the OS handle redirections of the
	//      parent process.
	//
	//   2) The console must be attached for IO to work, though (duplicates) of the parent handles
	//      must be used to maintain redirection.
	//
	//   3) Calling DuplicateHandle() and SetStdHandle() for every parent handle to make this process
	//      maintain parent redirection. Note: While this replaces the STD_INPUT_HANDLE/
	//      STD_OUTPUT_HANDLE/STD_ERROR_HANDLE values set by AttachConsole(), those handles are still
	//      cached by the crt, and are eventually closed by FreeConsole(). They MUST stay open to
	//      avoid INVALID_HANDLE_VALUE exceptions on console cleanup. This is why CloseHandle() is
	//      omitted before replacing STD_INPUT_HANDLE/STD_OUTPUT_HANDLE/STD_ERROR_HANDLE via SetStdHandle().

	HANDLE parentProcessHandle = OpenProcess(PROCESS_DUP_HANDLE, false, parentProcessId());
	HANDLE currentProcessHandle = GetCurrentProcess();
	HANDLE duplicatedHandle;

	DuplicateHandle(parentProcessHandle, stdIn(), currentProcessHandle, &duplicatedHandle, 0, false, DUPLICATE_SAME_ACCESS);
	SetStdHandle(STD_INPUT_HANDLE, duplicatedHandle);

	DuplicateHandle(parentProcessHandle, stdOut(), currentProcessHandle, &duplicatedHandle, 0, false, DUPLICATE_SAME_ACCESS);
	SetStdHandle(STD_OUTPUT_HANDLE, duplicatedHandle);

	DuplicateHandle(parentProcessHandle, stdErr(), currentProcessHandle, &duplicatedHandle, 0, false, DUPLICATE_SAME_ACCESS);
	SetStdHandle(STD_ERROR_HANDLE, duplicatedHandle);

	BindCrtStreamsToOSHandles();
	CloseHandle(parentProcessHandle);
}

bool attachedToConsole = false;

static DWORD attachToConsole(bool force = false) {

	if (!force && attachedToConsole) {
		return ERROR_SUCCESS;
	}

	if (!AttachConsole(parentProcessId())) {

		if (protonCompatibility()) {
			// Ignore the error if we are running under Wine
			return ERROR_SUCCESS;
		}

		const DWORD lastError = GetLastError();
		MessageBoxFormat(TEXT("InfinityLoaderDLL.dll"), MB_ICONERROR, TEXT("[!] attachToConsole() - AttachConsole() failed (%d)"), lastError);
		return lastError;
	}

	bindToParentOSHandles();
	attachedToConsole = true;

	if (debug()) {
		FPrint("[?][InfinityLoaderDLL.dll] attachToConsole() - force = %s\n", force ? "true" : "false");
	}

	return ERROR_SUCCESS;
}

static DWORD detatchFromConsole(bool force = false) {

	if (protonCompatibility()) {
		return ERROR_SUCCESS;
	}

	if (!force) {

		if (!attachedToConsole) {
			return ERROR_SUCCESS;
		}

		bool keepConsoleAttached;
		if (GetINIBoolDef(iniPath(), TEXT("General"), TEXT("KeepConsoleAttached"), false, keepConsoleAttached) == ERROR_SUCCESS
			&& keepConsoleAttached)
		{
			return ERROR_SUCCESS;
		}
	}

	if (debug()) {
		FPrint("[?][InfinityLoaderDLL.dll] detatchFromConsole() - force = %s\n", force ? "true" : "false");
	}

	if (!FreeConsole()) {
		const DWORD lastError = GetLastError();
		MessageBoxFormat(TEXT("InfinityLoaderDLL.dll"), MB_ICONERROR, TEXT("[!] detatchFromConsole() - FreeConsole() failed (%d)"), lastError);
		return lastError;
	}

	// FreeConsole() NtClose()'s all of the cached OS handles, though the duplicated
	// OS handles in the file descriptors still need to be closed.

	bool keepCrtStreamsAttached;
	if (GetINIBoolDef(iniPath(), TEXT("General"), TEXT("KeepCrtStreamsAttached"), false, keepCrtStreamsAttached) == ERROR_SUCCESS
		&& !keepCrtStreamsAttached)
	{
		NulCrtStreams();
	}

	// Close the duplicated parent handles so they don't leak, (crt may still hold
	// a duplicate of the duplicate if KeepCrtStreamsAttached=1, which is fine,
	// since they will be closed on the next attachToConsole()).
	//
	// Note: KeepCrtStreamsAttached=1 keeps the crt handles valid, while also closing
	// STD_INPUT_HANDLE/STD_OUTPUT_HANDLE/STD_ERROR_HANDLE. This may cause side effects
	// if the loader code / child processes expect GetStdHandle() to be valid.
	//
	// Note: SetStdHandle()'ing STD_INPUT_HANDLE/STD_OUTPUT_HANDLE/STD_ERROR_HANDLE
	// prevents the game from inheriting them, which is assumed by the rest of the
	// loader code. This prevents duplicate output for a non-patched SDL_LogOuput(),
	// because that function WriteConsole()'s and fprintf()'s, the latter is assumed
	// to be going to nul.

	CloseHandle(GetStdHandle(STD_INPUT_HANDLE));
	CloseHandle(GetStdHandle(STD_OUTPUT_HANDLE));
	CloseHandle(GetStdHandle(STD_ERROR_HANDLE));
	SetStdHandle(STD_INPUT_HANDLE, INVALID_HANDLE_VALUE);
	SetStdHandle(STD_OUTPUT_HANDLE, INVALID_HANDLE_VALUE);
	SetStdHandle(STD_ERROR_HANDLE, INVALID_HANDLE_VALUE);

	attachedToConsole = false;
	return ERROR_SUCCESS;
}

#undef fprintf

static int logShim(FILE* stream, const char* format, const char* level, const char* message) {
	if (!attachedToConsole && !protonCompatibility()) {
		// Intentionally not FPrint() - Since the engine calls both WriteConsole() and fprintf(), this fprintf()
		// call only serves to send engine output to the redirected stderr of InfinityLoader. Note that FPrint()
		// is used when `attachedToConsole == true`, as if InfinityLoader is attached to the console, that means
		// the engine isn't, (which causes its WriteConsole() to fail).
		return fprintf(stderr, format, level, message);
	}
	else {
		FPrintErr(format, level, message);
		return 0;
	}
}

#define fprintf error

static int logShimDisable(FILE* stream, const char* format, const char* level, const char* message) {
	return 0;
}

static DWORD writeReplaceLogFunction(bool disable_fprintf = false) {

	void* sectionPtr;
	DWORD sectionSize;
	if (sharedState().GetSegmentPointerAndSize(".text", sectionPtr, sectionSize)) {
		Print("[!][InfinityLoaderDLL.dll] writeReplaceLogFunction() - Failed to fetch .text pointer and size\n");
		return -1;
	}

	PatternValueHandle patchAddressHandle{};
	TryRetErr( findINICategoryPattern(sectionPtr, sectionSize, iniPath(), TEXT("Hardcoded_SDL_LogOutput()_fprintf"), patchAddressHandle) )
	if (sharedState().GetPatternValueType(patchAddressHandle) != PatternValueType::SINGLE) {
		Print("[!][InfinityLoaderDLL.dll] writeReplaceLogFunction() - [Hardcoded_SDL_LogOutput()_fprintf].Type must be SINGLE\n");
		return -1;
	}
	uintptr_t patchAddress = sharedState().GetSinglePatternValue(patchAddressHandle);

	uintptr_t curAllocatedPtr;
	SYSTEM_INFO info;
	GetSystemInfo(&info);

	if (DWORD lastError = AllocateNear(sharedState().ImageBase(), info.dwAllocationGranularity, curAllocatedPtr)) {
		return lastError;
	}

	AssemblyWriter writer = AssemblyWriter::Create();

	writer.SetLocation(patchAddress);
	writer.JmpToAddress(curAllocatedPtr);
	disableCodeProtection();
	writer.Flush();
	enableCodeProtection();
	writer.SetLocation(curAllocatedPtr);
	writer.CallToAddressFar(reinterpret_cast<uintptr_t>(!disable_fprintf ? logShim : logShimDisable));
	writer.JmpToAddress(patchAddress + 5);
	writer.Flush();

	if (debug()) {
		Print("[!][InfinityLoaderDLL.dll] writeReplaceLogFunction() - Done\n");
	}

	return 0;
}

static void winMainHook() {

	if (debug()) {
		Print("[?][InfinityLoaderDLL.dll] winMainHook() - Debug output 2 (Windows: No, Proton: Yes)...\n");
	}

	// This function runs before the console has been attached, temporarily attach it for error output
	if (attachToConsole() != ERROR_SUCCESS) {
		return;
	}

	if (debug()) {

		Print("[?][InfinityLoaderDLL.dll] winMainHook() - Debug output 3 (Windows: Yes, Proton: Yes)...\n");

		FPrint("[?][InfinityLoaderDLL.dll] winMainHook() - Game hStdInput: %d\n", GetStdHandle(STD_INPUT_HANDLE));
		FPrint("[?][InfinityLoaderDLL.dll] winMainHook() - Game hStdOutput: %d\n", GetStdHandle(STD_OUTPUT_HANDLE));
		FPrint("[?][InfinityLoaderDLL.dll] winMainHook() - Game hStdError: %d\n", GetStdHandle(STD_ERROR_HANDLE));
	}

	bool installLogRedirect = false;
	bool disable_fprintf = false;

	if (GetFileType(GetStdHandle(STD_ERROR_HANDLE)) != FILE_TYPE_CHAR) {

		// Redirecting output, use my fprintf so that it is actually redirected.
		// Ideally the exe's stdin, stdout, and stderr would be redirected, however,
		// this is extremely difficult to correct due to its statically linked c-runtime.
		// If AttachConsole() + BindCrtHandlesToStdHandles() are run in this DLL's Init()
		// the game will inherit redirected handles, though this makes logging too slow
		// in the case of stderr being spammed, (fprintf is SLOW, the engine normally
		// uses WriteConsole).
		//
		// Note: This only redirects SDL_LogOutput(), though most of the game's logging
		// goes through this function, and stdin, stdout, and stderr aren't normally
		// hooked up to the console anyway.

		installLogRedirect = true;
	}
	else if (protonCompatibility()) {
		installLogRedirect = true;
		disable_fprintf = true;
	}

	if (installLogRedirect) {

		if (debug()) {
			FPrint("[?][InfinityLoaderDLL.dll] winMainHook() - Redirecting output, disable_fprintf: %s\n", disable_fprintf ? "true" : "false");
		}

		if (DWORD redirectResult = writeReplaceLogFunction(disable_fprintf)) {
			FPrint("[!][InfinityLoaderDLL.dll] winMainHook() - Console redirection failed (%d)\n", redirectResult);
			goto cleanup;
		}
	}

cleanup:;
	detatchFromConsole();
}

template<typename pointer_type>
static bool fillExportedPointer(const String& name, pointer_type& pointer, uintptr_t address) {
	if (!setSinglePatternValue(name, address)) return false;
	pointer = reinterpret_cast<pointer_type>(address);
	return true;
}

template<typename pointer_type>
static bool fillExportedPointer(const String& name, pointer_type& pointer, void* address) {
	return fillExportedPointer(name, pointer, reinterpret_cast<uintptr_t>(address));
}

template<typename pointer_type, typename operations_type>
static bool fillPatternPointer(void* segmentPtr, DWORD segmentSize, const String& name, pointer_type& pointer, const operations_type& operations) {

	PatternValueHandle patternHandle{};
	TryRetErr( findINICategoryPattern(segmentPtr, segmentSize, iniPath(), name, patternHandle) )

	if (sharedState().GetPatternValueType(patternHandle) != PatternValueType::SINGLE) {
		FPrintT(TEXT("[!][InfinityLoaderDLL.dll] fillPatternPointer() - [%s].Type must be SINGLE\n"), name.c_str());
		return true;
	}

	uintptr_t address = sharedState().GetSinglePatternValue(patternHandle);
	operations(address);
	sharedState().SetSinglePatternValue(patternHandle, address);
	pointer = reinterpret_cast<pointer_type>(address);
	return false;
}

template<typename pointer_type>
static bool fillPatternPointer(void* segmentPtr, DWORD segmentSize, const String& name, pointer_type& pointer) {
	return fillPatternPointer(segmentPtr, segmentSize, name, pointer, [](uintptr_t& address){});
}

/////////////////////////
// START Lua Functions //
/////////////////////////

static void initLuaState(lua_State *const L) {

	if (luaMode() != LuaMode::INTERNAL) {

		luaL_openlibs(L);

		// Since non-internal modes initialize the Lua state immediately, the engine's print() function isn't set when EEex's initial
		// Lua file is executed, which means print() must be redirected to InfinityLoader's FPrint() to get console output from the
		// initial file.
		lua_pushcfunction(L, temporaryPrintReplacementLua);
		lua_setglobal(L, "print");
	}

	////////////////////////
	// Export Lua Globals //
	////////////////////////

	lua_pushinteger(L, sizeof(void*));
	lua_setglobal(L, prefixed("PointerSize"));

	lua_pushinteger(L, sizeof(void*));
	lua_setglobal(L, prefixed("PtrSize"));

#if _WIN64
	lua_pushstring(L, "x86-64");
#elif _WIN32
	lua_pushstring(L, "x86");
#else
	#error "Unhandled Architecture"
#endif
	lua_setglobal(L, prefixed("Architecture"));

	//////////////////////////
	// Export Lua Functions //
	//////////////////////////

	exposeToLua(L, prefixed("AddToLuaRegistry"), addToLuaRegistryLua);
	exposeToLua(L, prefixed("AllocCodePageInternal"), allocCodePageInternalLua);
	exposeToLua(L, prefixed("BAnd"), bandLua);
	exposeToLua(L, prefixed("BNot"), bnotLua);
	exposeToLua(L, prefixed("BOr"), borLua);
	exposeToLua(L, prefixed("CFunctionToPointer"), cFunctionToPointerLua);
	exposeToLua(L, prefixed("CFuncToPtr"), cFunctionToPointerLua);
	exposeToLua(L, prefixed("DisableCodeProtection"), disableCodeProtectionLua);
	exposeToLua(L, prefixed("DoFile"), doFileLua);
	exposeToLua(L, prefixed("EnableCodeProtection"), enableCodeProtectionLua);
	exposeToLua(L, prefixed("ExposeToLua"), exposeToLuaLua);
	exposeToLua(L, prefixed("Extract"), extractLua);
	exposeToLua(L, prefixed("Free"), freeLua);
	exposeToLua(L, prefixed("GetLuaRegistryIndex"), getLuaRegistryIndexLua);
	exposeToLua(L, prefixed("GetLuaLibraryProc"), getLuaLibraryProcLua);
	exposeToLua(L, prefixed("GetMicroseconds"), getMicrosecondsLua);
	exposeToLua(L, prefixed("GetPatternMap"), getPatternMapLua);
	exposeToLua(L, prefixed("GetProcAddressInternal"), getProcAddressLua);
	exposeToLua(L, prefixed("InitializeLuaBindings"), initializeLuaBindingsLua);
	exposeToLua(L, prefixed("InitLuaBindings"), initializeLuaBindingsLua);
	exposeToLua(L, prefixed("IterateRegex"), iterateRegexLua);
	exposeToLua(L, prefixed("JIT"), jitLua);
	exposeToLua(L, prefixed("JITAtInternal"), jitAtInternalLua);
	exposeToLua(L, prefixed("LoadLibrary"), loadLibraryLua);
	exposeToLua(L, prefixed("LShift"), lshiftLua);
	exposeToLua(L, prefixed("Malloc"), mallocLua);
	exposeToLua(L, prefixed("Memcpy"), memcpyLua);
	exposeToLua(L, prefixed("Memset"), memsetLua);
	exposeToLua(L, prefixed("MessageBoxInternal"), messageBoxInternalLua);
	exposeToLua(L, prefixed("OpenLuaBindings"), openLuaBindingsLua);
	exposeToLua(L, prefixed("Print"), printLua);
	exposeToLua(L, prefixed("PrintErr"), printErrLua);
	exposeToLua(L, prefixed("ProcessThreadQueue"), processThreadQueueLua);
	exposeToLua(L, prefixed("Read16"), read16Lua);
	exposeToLua(L, prefixed("Read32"), read32Lua);
#if defined(_WIN64)
	exposeToLua(L, prefixed("Read64"), read64Lua);
#endif
	exposeToLua(L, prefixed("Read8"), read8Lua);
	exposeToLua(L, prefixed("ReadPointer"), readPointerLua);
	exposeToLua(L, prefixed("ReadPtr"), readPointerLua);
	exposeToLua(L, prefixed("ReadU16"), readU16Lua);
	exposeToLua(L, prefixed("ReadU32"), readU32Lua);
#if defined(_WIN64)
	exposeToLua(L, prefixed("ReadU64"), readU64Lua);
#endif
	exposeToLua(L, prefixed("ReadU8"), readU8Lua);
	exposeToLua(L, prefixed("ReadLString"), readLString);
	exposeToLua(L, prefixed("ReadString"), readString);
	exposeToLua(L, prefixed("RShift"), rshiftLua);
	exposeToLua(L, prefixed("RunWithStack"), runWithStackLua);
	exposeToLua(L, prefixed("RunWithString"), runWithString);
	exposeToLua(L, prefixed("SelectFromTables"), selectFromTablesLua);
	exposeToLua(L, prefixed("SetLuaRegistryIndex"), setLuaRegistryIndexLua);
	exposeToLua(L, prefixed("SetSegmentProtection"), setSegmentProtectionLua);
	exposeToLua(L, prefixed("ToDecimalString"), toDecimalStringLua);
	exposeToLua(L, prefixed("ToDecStr"), toDecimalStringLua);
	exposeToLua(L, prefixed("Write16"), write16Lua);
	exposeToLua(L, prefixed("Write32"), write32Lua);
#if defined(_WIN64)
	exposeToLua(L, prefixed("Write64"), write64Lua);
#endif
	exposeToLua(L, prefixed("Write8"), write8Lua);
	exposeToLua(L, prefixed("WritePointer"), writePointerLua);
	exposeToLua(L, prefixed("WritePtr"), writePointerLua);
	exposeToLua(L, prefixed("WriteU16"), writeU16Lua);
	exposeToLua(L, prefixed("WriteU32"), writeU32Lua);
	exposeToLua(L, prefixed("WriteU64"), writeU64Lua);
	exposeToLua(L, prefixed("WriteU8"), writeU8Lua);
	exposeToLua(L, prefixed("WriteLString"), writeLStringLua);
	exposeToLua(L, prefixed("WriteString"), writeStringLua);
	exposeToLua(L, prefixed("WriteStringAuto"), writeStringAutoLua);
}

static DWORD prepareExtenderScriptsAfterLuaInitialization(lua_State *const L) {

	bool eeZipSupport;
	TryRetErr( GetINIBoolDef(iniPath(), TEXT("General"), TEXT("EEZipSupport"), false, eeZipSupport) );

	if (eeZipSupport) {

		const String engineLuaFilePath = workingFolder() + TEXT("engine.lua");
		callLuaFile(L, engineLuaFilePath.c_str());
		lua_getglobal(L, "engine_name"); // 1 [ ..., engine_name ]

		if (!lua_isstring(L, -1)) {
			Print("[!][InfinityLoaderDLL.dll] prepareExtenderScriptsAfterLuaInitialization() - invalid `engine_name` type; string expected\n");
			lua_pop(L, 1);               // 0 [ ... ]
			return -1;
		}

		const String sEngineName = NulTermStrToStr(lua_tostring(L, -1));
		lua_pop(L, 1);                   // 0 [ ... ]

		return prepareExtenderScripts(&sEngineName);
	}
	else {
		return prepareExtenderScripts(nullptr);
	}
}

/////////////////////////////////////
// START Hardcoded Pattern Exports //
/////////////////////////////////////

static void __stdcall doLuaFileExport(lua_State *const L, const char *const str) {
	callScriptFileA(L, str);
}

static lua_State* __stdcall getLuaStateExport() {
	return luaState();
}

static void __stdcall logExport(const char *const str) {
	Print(str);
}

static void logVExport(const char* formatText, ...) {

	va_list args;
	va_start(args, formatText);

	RunWithGrowingBuffer<char>(
		[&](char *const buffer, const size_t bufferSize) {
			const int result = _vsnprintf_s(buffer, bufferSize, _TRUNCATE, formatText, args);
			return result == -1 ? TryFillBufferResult::GROW : TryFillBufferResult::DONE;
		},
		[&](char *const buffer, const size_t) {
			Print(buffer);
		}
	);

	va_end(args);
}

// This needs to be a separate export in order to support the extender creating
// a lua_State before initializing it, e.g. to write the lua_State's address
// as part of a patch before its thread has started.
static void __stdcall initLuaStateExport(lua_State *const L) {
	sharedState().InitLuaState(L);
	initLuaState(L);
}

// This is a shortcut for luaL_newstate() + Hardcoded_initLuaState()
// Only applicable if calling from the lua_State's thread
static lua_State* __stdcall newLuaStateExport() {
	lua_State *const L = luaL_newstate();
	initLuaStateExport(L);
	return L;
}

///////////////////////////////////
// END Hardcoded Pattern Exports //
///////////////////////////////////

static DWORD initLua(bool bFromPatch = false) {

	if (debug()) {
		Print("[?][InfinityLoaderDLL.dll] initLua() - Debug output 4 (Windows: No, Proton: Yes)...\n");
	}

	if (bFromPatch) {
		// This function runs before the console has been attached, temporarily attach it for error output
		TryRetErr( attachToConsole() );
	}

	DWORD toReturn = ERROR_SUCCESS;

	if (debug()) {
		Print("[?][InfinityLoaderDLL.dll] initLua() - Debug output 5 (Windows: Yes, Proton: Yes)...\n");
	}

#define fillPatternPointerCleanup(name, outName) \
	if (fillPatternPointer(sectionPtr, sectionSize, TEXT(name), p_##outName)) { \
		toReturn = -1; \
		goto cleanup; \
	}

#define fillExportedPointerCleanup(name, pointer, address) \
	if (!fillExportedPointer(name, pointer, address)) { \
		toReturn = -1; \
		goto cleanup; \
	}

#define setSinglePatternValueCleanup(name, address) \
	if (!setSinglePatternValue(name, address)) { \
		toReturn = -1; \
		goto cleanup; \
	}

	////////////////////
	// Init Lua state //
	////////////////////

	void* sectionPtr;
	DWORD sectionSize;

	String earlyPrintPrefixW;
	String extenderNameW;
	String luaGlobalsPrefixW;

	if (sharedState().GetSegmentPointerAndSize(".text", sectionPtr, sectionSize)) {
		Print("[!][InfinityLoaderDLL.dll] initLua() - Failed to fetch .text pointer and size\n");
		toReturn = -1;
		goto cleanup;
	}

	if (toReturn = GetINIStrDef(iniPath(), TEXT("General"), TEXT("ExtenderName"), TEXT("EEex"), extenderNameW); toReturn != ERROR_SUCCESS) {
		Print("[!][InfinityLoaderDLL.dll] initLua() - Failed to read [General].ExtenderName\n");
		goto cleanup;
	}
	extenderName = StrToStrA(extenderNameW);

	if (toReturn = GetINIStrDef(iniPath(), TEXT("General"), TEXT("LuaGlobalsPrefix"), TEXT("EEex_"), luaGlobalsPrefixW); toReturn != ERROR_SUCCESS) {
		Print("[!][InfinityLoaderDLL.dll] initLua() - Failed to read [General].LuaGlobalsPrefix\n");
		goto cleanup;
	}
	luaGlobalsPrefix = StrToStrA(luaGlobalsPrefixW);

	if (toReturn = GetINIStrDef(iniPath(), TEXT("General"), TEXT("EarlyPrintPrefix"), TEXT(""), earlyPrintPrefixW); toReturn != ERROR_SUCCESS) {
		Print("[!][InfinityLoaderDLL.dll] initLua() - Failed to read [General].EarlyPrintPrefixW\n");
		goto cleanup;
	}
	earlyPrintPrefix = StrToStrA(earlyPrintPrefixW);

	lua_State* L;

	if (luaMode() == LuaMode::INTERNAL) {
		if (fillPatternPointer(sectionPtr, sectionSize, TEXT("Hardcoded_InternalLuaState"), L, [](uintptr_t& address) {
			address = *reinterpret_cast<uintptr_t*>(address);
		})) {
			toReturn = -1;
			goto cleanup;
		}
	}
	else {
		L = luaL_newstate();
		setSinglePatternValueCleanup(TEXT("Hardcoded_InternalLuaState"), L)
	}

	sharedState().InitLuaState(L);
	initLuaState(L);

	/////////////////////////////////////
	// Export Hardcoded Pattern Values //
	/////////////////////////////////////

	setSinglePatternValueCleanup(TEXT("Hardcoded_doLuaFile"), doLuaFileExport)
	setSinglePatternValueCleanup(TEXT("Hardcoded_getLuaState"), getLuaStateExport)
	setSinglePatternValueCleanup(TEXT("Hardcoded_initLuaState"), initLuaStateExport)
	setSinglePatternValueCleanup(TEXT("Hardcoded_log"), logExport)
	setSinglePatternValueCleanup(TEXT("Hardcoded_logV"), logVExport)
	setSinglePatternValueCleanup(TEXT("Hardcoded_newLuaState"), newLuaStateExport)

	/////////////////////////
	// Prepare Lua Scripts //
	/////////////////////////

	if (toReturn = prepareExtenderScriptsAfterLuaInitialization(L); toReturn != ERROR_SUCCESS)
	{
		Print("[!][InfinityLoaderDLL.dll] initLua() - Failed to prepare Lua scripts\n");
		goto cleanup;
	}

	///////////////////////
	// Run Main Lua File //
	///////////////////////

	if (luaMode() == LuaMode::INTERNAL) {
		fillPatternPointerCleanup("Hardcoded_free", free)
		fillPatternPointerCleanup("Hardcoded_malloc", malloc);
		callScriptFileA(L, prefixed("Main"));
	}
	else {

		// LuaMode::EXTERNAL calls EEex_Main.lua before __tmainCRTStartup() has
		// been called to initialize the game's heap. Let EEex_Main.lua use the
		// DLL's heap for initialization.
		//
		// Note: Memory allocated during initialization should NEVER be freed.
		// Since free() is swapped out after EEex_Main.lua, attempting to free
		// memory allocated during initialization results in the wrong heap
		// being modified.

		fillExportedPointerCleanup(TEXT("Hardcoded_free"), p_free, free);
		fillExportedPointerCleanup(TEXT("Hardcoded_malloc"), p_malloc, malloc);

		if (luaMode() == LuaMode::REPLACE_INTERNAL_WITH_EXTERNAL) {
			callScriptFileA(L, prefixed("EarlyMain"));
		}
		else {
			callScriptFileA(L, prefixed("Main"));
		}

		fillPatternPointerCleanup("Hardcoded_free", free);
		fillPatternPointerCleanup("Hardcoded_malloc", malloc);
	}

cleanup:;

	if (bFromPatch) {

		if (toReturn != ERROR_SUCCESS) {
			Print("[!][InfinityLoaderDLL.dll] initLua() - Initialization failed; the main Lua file will not be executed\n");
		}

		const DWORD detatchResult = detatchFromConsole();
		return toReturn == ERROR_SUCCESS ? detatchResult : toReturn;
	}

	return toReturn;
}

static void initLuaPatch() {
	initLua(true);
}

static void delayedMainCall() {
	TryRetTruthy( attachToConsole() )
	callScriptFileA(luaState(), prefixed("Main"));
	TryRetTruthy( detatchFromConsole() )
}

static void writeCallHookProcAfterCall(AssemblyWriter& writer, uintptr_t& curAllocatedPtr, uintptr_t patchAddress, void* targetProc) {

	// curAllocatedPtr keeps track of the current address in the VirtualAlloc()'d patch space

	__int32 relativeAmount = *reinterpret_cast<__int32*>(patchAddress + 1);
	uintptr_t target = patchAddress + 5 + relativeAmount;

	writer.SetLocation(patchAddress);
	writer.JmpToAddress(curAllocatedPtr);
	disableCodeProtection();
	writer.Flush();
	enableCodeProtection();

	writer.SetLocation(curAllocatedPtr);
	writer.CallToAddress(target);
	writer.PushVolatileRegisters();
	writer.AlignStackAndMakeShadowSpace();
	writer.CallToAddressFar(reinterpret_cast<uintptr_t>(targetProc));
	writer.UndoAlignAndShadowSpace();
	writer.PopVolatileRegisters();
	writer.JmpToAddress(patchAddress + 5);
	writer.Flush();

	curAllocatedPtr = writer.GetCurrentLocation();
}

static DWORD writeInternalPatch(AssemblyWriter& writer, uintptr_t& curAllocatedPtr, void* funcPtr) {

	// curAllocatedPtr keeps track of the current address in the VirtualAlloc()'d patch space

	void* sectionPtr;
	DWORD sectionSize;
	if (sharedState().GetSegmentPointerAndSize(".text", sectionPtr, sectionSize)) {
		Print("[!][InfinityLoaderDLL.dll] writeInternalPatch() - Failed to fetch .text pointer and size\n");
		return -1;
	}

	PatternValueHandle patchAddressHandle{};
	TryRetErr( findINICategoryPattern(sectionPtr, sectionSize, iniPath(), TEXT("Hardcoded_InternalPatchLocation"), patchAddressHandle) )
	if (sharedState().GetPatternValueType(patchAddressHandle) != PatternValueType::SINGLE) {
		Print("[!][InfinityLoaderDLL.dll] writeInternalPatch() - [Hardcoded_InternalPatchLocation].Type must be SINGLE\n");
		return -1;
	}
	uintptr_t patchAddress = sharedState().GetSinglePatternValue(patchAddressHandle);

	writeCallHookProcAfterCall(writer, curAllocatedPtr, patchAddress, funcPtr);
	return ERROR_SUCCESS;
}

static DWORD setUpLuaInitialization(void* sectionPtr, DWORD sectionSize) {

	uintptr_t curAllocatedPtr;
	SYSTEM_INFO info;
	GetSystemInfo(&info);

	TryRetErr( AllocateNear(sharedState().ImageBase(), info.dwAllocationGranularity, curAllocatedPtr) )

	AssemblyWriter writer = AssemblyWriter::Create();

	// Write hook early in WinMain to check for Console redirection
	if (INISectionExists(iniPath(), TEXT("Hardcoded_WinMainPatchLocation"))) {
		PatternValueHandle winMainPatchAddressHandle;
		TryRetErr( findINICategoryPattern(sectionPtr, sectionSize, iniPath(), TEXT("Hardcoded_WinMainPatchLocation"), winMainPatchAddressHandle) )
		if (sharedState().GetPatternValueType(winMainPatchAddressHandle) != PatternValueType::SINGLE) {
			Print("[!][InfinityLoaderDLL.dll] setUpLuaInitialization() - [Hardcoded_WinMainPatchLocation].Type must be SINGLE\n");
			return -1;
		}
		uintptr_t winMainPatchAddress = sharedState().GetSinglePatternValue(winMainPatchAddressHandle);
		writeCallHookProcAfterCall(writer, curAllocatedPtr, winMainPatchAddress, winMainHook);
	}

	// Initialize code that tracks patterns and exports them to Lua
	initPatternTracking();

	// Write Lua initialization hook
	if (LuaMode luaMode = luaMode(); luaMode == LuaMode::INTERNAL) {
		TryRetErr( writeInternalPatch(writer, curAllocatedPtr, initLuaPatch) )
		return ERROR_SUCCESS;
	}
	else if (luaMode == LuaMode::REPLACE_INTERNAL_WITH_EXTERNAL) {
		TryRetErr( initLua() );
		return writeInternalPatch(writer, curAllocatedPtr, delayedMainCall);
	}
	else {
		return initLua();
	}
}

static DWORD patchExe() {

	#pragma push_macro("printInitFailed")
	#pragma push_macro("attemptElseRetErr")
	#define printInitFailed() Print("[!][InfinityLoaderDLL.dll] patchExe() - Initialization failed; the main Lua file will not be executed\n");
	#define attemptElseRetErr(call) TryElseRetErr( call, printInitFailed() )

	attemptElseRetErr( loadExeNameForPatterns() )

	void* sectionPtr;
	DWORD sectionSize;
	if (sharedState().GetSegmentPointerAndSize(".text", sectionPtr, sectionSize)) {
		Print("[!][InfinityLoaderDLL.dll] patchExe() - Failed to fetch .text pointer and size\n");
		printInitFailed()
		return -1;
	}

	attemptElseRetErr( findPatterns(sectionPtr, sectionSize) )
	attemptElseRetErr( InitLuaProvider(sharedState()) )
	attemptElseRetErr( setUpLuaInitialization(sectionPtr, sectionSize) )
	return ERROR_SUCCESS;

	#pragma pop_macro("attemptElseRetErr")
	#pragma pop_macro("printInitFailed")
}

// Return:
//   0 -> No Error
//   1 -> Error (no console output)
//   2 -> Error (console output)

static byte init(HANDLE mappedMemoryHandle) {

	SharedStateMappedMemory mappedMemory;
	if (InitMappedMemory(mappedMemoryHandle, mappedMemory) || SharedState::Create(mappedMemory, sharedState())) {
		return 1;
	}

	if (pause()) {
		MessageBox(NULL, TEXT("[?] init() - Pause"), TEXT("InfinityLoaderDLL.dll"), MB_ICONINFORMATION);
	}

	// This function runs before the console has been attached, temporarily attach it for error output
	if (attachToConsole() != ERROR_SUCCESS) {
		return 1;
	}

	if (protonCompatibility()) {
		if (int error = UnbufferCrtStreams()) {
			FPrint("[!][InfinityLoaderDLL.dll] init() - UnbufferCrtStreams() failed (%d)\n", error);
			return 2;
		}
	}

	if (int error = InitFPrint()) {
		FPrint("[!][InfinityLoaderDLL.dll] init() - InitFPrint() failed (%d)\n", error);
		return 2;
	}

	if (debug()) {

		Print("[?][InfinityLoaderDLL.dll] init() - Debug output 1 (Windows: Yes, Proton: Yes)...\n");

		FPrint("[?][InfinityLoaderDLL.dll] init() - DLL hStdInput: %d\n", GetStdHandle(STD_INPUT_HANDLE));
		FPrint("[?][InfinityLoaderDLL.dll] init() - DLL hStdOutput: %d\n", GetStdHandle(STD_OUTPUT_HANDLE));
		FPrint("[?][InfinityLoaderDLL.dll] init() - DLL hStdError: %d\n", GetStdHandle(STD_ERROR_HANDLE));
	}

	if (sharedState().InitState()) {
		return 2;
	}

	return 0;
}

static int exceptionFilter(unsigned int code, _EXCEPTION_POINTERS* pointers, unsigned int& codeOut) {
	if (IsDebuggerPresent()) return EXCEPTION_CONTINUE_SEARCH;
	DumpCrashInfo(pointers);
	codeOut = code;
	return EXCEPTION_EXECUTE_HANDLER;
}

static int exceptionFilterIgnoreIfSubsequent(unsigned int code, _EXCEPTION_POINTERS* pointers, unsigned int& codeOut) {
	if (!codeOut) {
		if (IsDebuggerPresent()) return EXCEPTION_CONTINUE_SEARCH;
		DumpCrashInfo(pointers);
		codeOut = code;
	}
	return EXCEPTION_EXECUTE_HANDLER;
}

// Don't remove __stdcall - the patch that calls this function assumes the stack gets cleaned up
void __stdcall Init(HANDLE mappedMemoryHandle) {

	unsigned int exitCode = 0;

	__try {

		if (byte result = init(mappedMemoryHandle)) {
			if (result == 2) {
				goto errorLogged;
			}
			return;
		}

		if (patchExe()) {
			goto errorLogged;
		}
	}
	__except (exceptionFilter(GetExceptionCode(), GetExceptionInformation(), exitCode)) {}

	goto cleanup;

errorLogged:;

	__try {
		ShowWindow(GetConsoleWindow(), SW_SHOW);
		Print("Press any key to continue . . .\n");
		_getch(); // TODO: This properly blocks, unlike `std::cin.get()`. Is something wrong with binding to the parent's console handles?
	}
	__except (exceptionFilterIgnoreIfSubsequent(GetExceptionCode(), GetExceptionInformation(), exitCode)) {}

cleanup:;

	__try {
		detatchFromConsole();
	}
	__except (exceptionFilterIgnoreIfSubsequent(GetExceptionCode(), GetExceptionInformation(), exitCode)) {}

	if (exitCode) {
		exit(exitCode);
	}
}
