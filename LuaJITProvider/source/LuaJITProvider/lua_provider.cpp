
#include "infinity_loader_common_api.h"
#include "lua_pointers.h"
#include "shared_state_api.h"

//////////
// Init //
//////////

template<typename FunctionPtr>
static bool checkExportPattern(const String& name, FunctionPtr value) {

	if (sharedState().LuaMode() != LuaMode::EXTERNAL) {
		return true;
	}

	PatternValueHandle handle;
	if (sharedState().GetOrCreatePatternValue(name, PatternValueType::SINGLE, handle)) {
		FPrintT(TEXT("[!][LuaProvider.dll] exportPattern() - [%s].Type must be SINGLE; initialization failed\n"), name.c_str());
		return false;
	}

	sharedState().SetSinglePatternValue(handle, reinterpret_cast<void*>(value));
	return true;
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
		TryRetDefErrCode ( checkExportPattern(luaPatternName, funcPtrOut) )
	}

	return ERROR_SUCCESS;
}

template<typename BackupType, typename OutType>
static bool tryLinkAPIInternal(const HMODULE hLuaLibrary, const char* const name, const String& luaPatternName, BackupType& backup, OutType& out) {
	if (hLuaLibrary != INVALID_HANDLE_VALUE) {
		if (out = reinterpret_cast<OutType>(GetProcAddress(hLuaLibrary, name)); out == 0) {
			out = backup;
		}
	}
	else {
		out = backup;
	}
	return checkExportPattern(luaPatternName, out);
}

#define linkMatchingAPI(apiNum, luaPrefix, luaFuncName) \
	imp_##luaPrefix##_##luaFuncName = luaPrefix##apiNum##_##luaFuncName; \
	TryRetErr ( setLuaPointerInternal(TEXT("switchLuaImplementations"), hLuaLibrary, TEXT("Hardcoded_"#luaPrefix"_"#luaFuncName), #luaPrefix"_"#luaFuncName, p_##luaPrefix##_##luaFuncName) )

#define linkMismatchingAPI(apiNum, luaPrefix, luaFuncName) \
	TryRetDefErrCode ( tryLinkAPIInternal(hLuaLibrary, #luaPrefix"_"#luaFuncName, TEXT("Hardcoded_"#luaPrefix"_"#luaFuncName), luaPrefix##apiNum##_##luaFuncName, imp_##luaPrefix##_##luaFuncName) )

static DWORD switchLuaImplementations(const HMODULE hLuaLibrary, const char *const luaVersionKey, const String& luaVersion) {

	if (luaVersion == TEXT("5.1")) {
		// lua_pcall
		linkMatchingAPI(51, lua, pcall)
		// lua_pcallk
		linkMismatchingAPI(51, lua, pcallk)
		// lua_tonumber
		linkMatchingAPI(51, lua, tonumber)
		// lua_tonumberx
		linkMismatchingAPI(51, lua, tonumberx)
	}
	else if (luaVersion == TEXT("5.2")) {
		// lua_pcall
		linkMismatchingAPI(52, lua, pcall)
		// lua_pcallk
		linkMatchingAPI(52, lua, pcallk)
		// lua_tonumber
		linkMismatchingAPI(52, lua, tonumber)
		// lua_tonumberx
		linkMatchingAPI(52, lua, tonumberx)
	}
	else {
		FPrint("[!][LuaProvider.dll] switchLuaImplementations() - Invalid [General].%s value (must be \"5.1\" or \"5.2\"); initialization failed\n", luaVersionKey);
		return -1;
	}

	return ERROR_SUCCESS;
}

#undef linkMismatchingAPI
#undef linkMatchingAPI

#define setLuaPointer(luaFuncName) \
	TryRetErr ( setLuaPointerInternal(TEXT("InitLuaProvider"), hLuaLibrary, TEXT("Hardcoded_"#luaFuncName), #luaFuncName, p_##luaFuncName) )

EXPORT DWORD InitLuaProvider(SharedState sharedDLL) {

	sharedState() = sharedDLL;
	const HMODULE hLuaLibrary = luaLibrary();

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

	setLuaPointer(lua_atpanic)
	setLuaPointer(lua_callk)
	setLuaPointer(lua_concat)
	setLuaPointer(lua_createtable)
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
	setLuaPointer(lua_pcallk)
	setLuaPointer(lua_pushboolean)
	setLuaPointer(lua_pushcclosure)
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
	setLuaPointer(luaL_loadfilex)
	setLuaPointer(luaL_loadstring)
	setLuaPointer(luaL_newmetatable)
	setLuaPointer(luaL_newstate)
	setLuaPointer(luaL_openlibs)
	setLuaPointer(luaL_ref)

	return ERROR_SUCCESS;
}

#undef setLuaPointer
