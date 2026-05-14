
#include <stdexcept>

#include "infinity_loader_common_api.h"
#include "lua_pointers.h"
#include "shared_state_api.h"

//////////
// Init //
//////////

template<typename FunctionPtr>
static bool exportPattern(const String& name, FunctionPtr value) {

	PatternValueHandle handle;
	if (sharedState().GetOrCreatePatternValue(name, PatternValueType::SINGLE, handle)) {
		FPrintT(TEXT("[!][LuaProvider.dll] exportPattern() - [%s].Type must be SINGLE; initialization failed\n"), name.c_str());
		return false;
	}

	sharedState().SetSinglePatternValue(handle, reinterpret_cast<void*>(value));
	return true;
}

template<typename FunctionPtr>
static bool checkExportPattern(const String& name, FunctionPtr value) {

	if (sharedState().LuaMode() != LuaMode::EXTERNAL) {
		return true;
	}

	return exportPattern(name, value);
}

template<typename out_type>
static DWORD getLuaProc(const HMODULE luaLibrary, const char *const name, out_type& out) {
	if (out = reinterpret_cast<out_type>(GetProcAddress(luaLibrary, name)); out == 0) {
		const DWORD lastError = GetLastError();
		FPrint("[!][LuaProvider.dll] getLuaProc() - GetProcAddress() failed (%d) to find Lua function \"%s\"; initialization failed\n", lastError, name);
		return lastError;
	}
	return 0;
}

template<typename FunctionPtr>
static DWORD setLuaPointerInternal(
	const TCHAR *const containingFuncName, const HMODULE hLuaLibrary,
	const TCHAR *const luaPatternName, const char *const luaFuncName,
	FunctionPtr& funcPtrOut)
{
	if (hLuaLibrary == INVALID_HANDLE_VALUE) {

		PatternValueHandle patternHandle;

		switch (sharedState().GetPatternValue(luaPatternName, patternHandle)) {

			case PatternValueType::SINGLE: {
				funcPtrOut = reinterpret_cast<FunctionPtr>(sharedState().GetSinglePatternValue(patternHandle));
				break;
			}
			case PatternValueType::INVALID: {

				bool unsupported;
				TryRetErr( GetINIBoolDef(dbPath(), luaPatternName, TEXT("Unsupported"), false, unsupported) )

				if (!unsupported) {
					FPrintT(TEXT("[!][LuaProvider.dll] %s() - Lua pattern [%s] missing; initialization failed\n"), containingFuncName, luaPatternName);
					return -1;
				}

				break;
			}
			default: {
				FPrintT(TEXT("[!][LuaProvider.dll] %s() - Lua pattern [%s].Type not SINGLE; initialization failed\n"), containingFuncName, luaPatternName);
				return -1;
			}
		}
	}
	else {
		TryRetErr( getLuaProc(hLuaLibrary, luaFuncName, funcPtrOut) )
		TryRetDefErrCode( checkExportPattern(luaPatternName, funcPtrOut) )
	}

	return ERROR_SUCCESS;
}

template<typename BackupType, typename OutType>
static bool linkMismatchingAPIIInternal(const HMODULE hLuaLibrary, const char* const procName, const String& patternName, BackupType& backupAPITranslationProc, OutType& funcPtrOut) {
	if (hLuaLibrary != INVALID_HANDLE_VALUE) {
		if (funcPtrOut = reinterpret_cast<OutType>(GetProcAddress(hLuaLibrary, procName)); funcPtrOut == 0) {
			funcPtrOut = backupAPITranslationProc;
		}
	}
	else {
		funcPtrOut = backupAPITranslationProc;
	}
	return checkExportPattern(patternName, funcPtrOut);
}

// "Matching" means the function being linked to physically exists in the target Lua version.
// Functions that exist via a #define are NOT considered matching, as they are not physically present.
//
// Switch to matching function by setting imp_* directly to function ptr.
// If LuaPatchMode == INTERNAL attempt to fetch pointer from patterns.
// If LuaPatchMode != INTERNAL attempt to fetch pointer from Lua DLL.
// Export proc if LuaPatchMode == EXTERNAL.

#define linkMatchingAPI(luaPrefix, luaFuncName) \
	TryRetErr ( setLuaPointerInternal(TEXT("switchLuaImplementations"), hLuaLibrary, TEXT("Hardcoded_"#luaPrefix"_"#luaFuncName), #luaPrefix"_"#luaFuncName, p_##luaPrefix##_##luaFuncName) ) \
	imp_##luaPrefix##_##luaFuncName = p_##luaPrefix##_##luaFuncName;

#define linkMatchingAPIUnderAlias(luaPrefix, luaFuncPtrName, luaFuncAlias) \
	TryRetErr ( setLuaPointerInternal(TEXT("switchLuaImplementations"), hLuaLibrary, TEXT("Hardcoded_"#luaPrefix"_"#luaFuncAlias), #luaPrefix"_"#luaFuncAlias, p_##luaPrefix##_##luaFuncPtrName) ) \
	imp_##luaPrefix##_##luaFuncPtrName = p_##luaPrefix##_##luaFuncPtrName;

// "Mismatching" means the function being linked to does NOT physically exist in the target Lua version.
// Functions that exist via a #define are considered mismatching, as they are not physically present.
//
// Switch to:
//   *) If LuaPatchMode != INTERNAL, proc fetched from Lua DLL.
//   *) if LuaPatchMode == INTERNAL or DLL didn't contain function, mismatching func translator (lua51/lua52).
//
// Export proc if LuaPatchMode == EXTERNAL.

#define linkMismatchingAPI(apiNum, luaPrefix, luaFuncName) \
	TryRetDefErrCode ( linkMismatchingAPIIInternal(hLuaLibrary, #luaPrefix"_"#luaFuncName, TEXT("Hardcoded_"#luaPrefix"_"#luaFuncName), luaPrefix##apiNum##_##luaFuncName, imp_##luaPrefix##_##luaFuncName) )

static DWORD switchLuaImplementations(const HMODULE hLuaLibrary, const char *const luaVersionKey, const String& luaVersion) {

	const bool is51 = luaVersion == TEXT("5.1");
	const bool is51LuaJIT = !is51 && luaVersion == TEXT("5.1-LuaJIT");

	if (is51 || is51LuaJIT) {

		if (is51) {
			// lua_load
			linkMatchingAPI(lua, load)
			// lua_loadx
			linkMismatchingAPI(51, lua, loadx)
		}
		else if (is51LuaJIT) {
			// lua_load
			linkMatchingAPI(lua, load)
			// lua_loadx
			linkMatchingAPI(lua, loadx)
		}
		else {
			throw std::invalid_argument{"[LuaProvider.dll] Unhandled Lua version"};
		}

		// lua_pcall
		linkMatchingAPI(lua, pcall)
		// lua_pcallk
		linkMismatchingAPI(51, lua, pcallk)
		// lua_tonumber
		linkMatchingAPI(lua, tonumber)
		// lua_tonumberx
		linkMismatchingAPI(51, lua, tonumberx)
	}
	else if (luaVersion == TEXT("5.2")) {
		// lua_load
		linkMismatchingAPI(52, lua, load)
		// lua_loadx
		linkMatchingAPIUnderAlias(lua, loadx, load)
		// lua_pcall
		linkMismatchingAPI(52, lua, pcall)
		// lua_pcallk
		linkMatchingAPI(lua, pcallk)
		// lua_tonumber
		linkMismatchingAPI(52, lua, tonumber)
		// lua_tonumberx
		linkMatchingAPI(lua, tonumberx)
	}
	else {
		FPrint("[!][LuaProvider.dll] switchLuaImplementations() - Invalid [General].%s value (must be \"5.1\" or \"5.1-LuaJIT\" or \"5.2\"); initialization failed\n", luaVersionKey);
		return -1;
	}

	return ERROR_SUCCESS;
}

#undef linkMismatchingAPI
#undef linkMatchingAPIUnderAlias
#undef linkMatchingAPI

#define setLuaPointer(luaFuncName) \
	TryRetErr ( setLuaPointerInternal(TEXT("InitLuaProvider"), hLuaLibrary, TEXT("Hardcoded_"#luaFuncName), #luaFuncName, p_##luaFuncName) )

EXPORT DWORD InitLuaProvider(SharedState sharedDLL) {

	sharedState() = sharedDLL;
	const HMODULE hLuaLibrary = luaLibrary();

	////////////////////////////////
	// Switchable Implementations //
	////////////////////////////////

	if (hLuaLibrary == INVALID_HANDLE_VALUE) {
		String internalLuaVersion;
		TryRetLastErr( GetINIStrDef(iniPath(), TEXT("General"), TEXT("LuaVersionInternal"), TEXT("5.2"), internalLuaVersion) )
		switchLuaImplementations(hLuaLibrary, "LuaVersionInternal", internalLuaVersion);
	}
	else {
		String externalLuaVersion;
		TryRetLastErr( GetINIStrDef(iniPath(), TEXT("General"), TEXT("LuaVersionExternal"), TEXT("5.1"), externalLuaVersion) )
		switchLuaImplementations(hLuaLibrary, "LuaVersionExternal", externalLuaVersion);
	}

	///////////////////////////
	// Standard Lua Pointers //
	///////////////////////////

	setLuaPointer(lua_atpanic)
	setLuaPointer(lua_callk)
	setLuaPointer(lua_concat)
	setLuaPointer(lua_createtable)
	setLuaPointer(lua_gc)
	setLuaPointer(lua_getfield)
	setLuaPointer(lua_getglobal)
	setLuaPointer(lua_getmetatable)
	setLuaPointer(lua_gettable)
	setLuaPointer(lua_gettop)
	setLuaPointer(lua_insert)
	setLuaPointer(lua_iscfunction)
	setLuaPointer(lua_isnumber)
	setLuaPointer(lua_isstring)
	setLuaPointer(lua_isuserdata)
	setLuaPointer(lua_newuserdata)
	setLuaPointer(lua_next)
	setLuaPointer(lua_pushboolean)
	setLuaPointer(lua_pushcclosure)
	setLuaPointer(lua_pushfstring)
	setLuaPointer(lua_pushinteger)
	setLuaPointer(lua_pushlightuserdata)
	setLuaPointer(lua_pushlstring)
	setLuaPointer(lua_pushnil)
	setLuaPointer(lua_pushnumber)
	setLuaPointer(lua_pushstring)
	setLuaPointer(lua_pushvalue)
	setLuaPointer(lua_rawequal)
	setLuaPointer(lua_rawget)
	setLuaPointer(lua_rawgeti)
	setLuaPointer(lua_rawlen)
	setLuaPointer(lua_rawset)
	setLuaPointer(lua_rawseti)
	setLuaPointer(lua_remove)
	setLuaPointer(lua_setfield)
	setLuaPointer(lua_setglobal)
	setLuaPointer(lua_setmetatable)
	setLuaPointer(lua_settable)
	setLuaPointer(lua_settop)
	setLuaPointer(lua_toboolean)
	setLuaPointer(lua_tocfunction)
	setLuaPointer(lua_tointegerx)
	setLuaPointer(lua_tolstring)
	setLuaPointer(lua_touserdata)
	setLuaPointer(lua_type)
	setLuaPointer(lua_typename)
	setLuaPointer(luaL_error)
	setLuaPointer(luaL_loadbufferx)
	setLuaPointer(luaL_loadfilex)
	setLuaPointer(luaL_loadstring)
	setLuaPointer(luaL_newmetatable)
	setLuaPointer(luaL_newstate)
	setLuaPointer(luaL_openlibs)
	setLuaPointer(luaL_ref)
	setLuaPointer(luaL_traceback) // TODO: Should be switched above

	/////////////////////////
	// Custom Lua Pointers //
	/////////////////////////

	TryRetDefErrCode( exportPattern(TEXT("lua_wfopen"), _wfopen) )
	TryRetDefErrCode( exportPattern(TEXT("luaL_loadfilexnamedptr"), luaL_loadfilexnamedptr) )

	return ERROR_SUCCESS;
}

#undef setLuaPointer
