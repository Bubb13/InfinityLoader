
#include "infinity_loader_common_api.h"

//////////
// Init //
//////////

template<typename out_type>
DWORD getLuaProc(HMODULE luaLibrary, const char* name, out_type& out) {
	if (out = reinterpret_cast<out_type>(GetProcAddress(luaLibrary, name)); out == 0) {
		DWORD lastError = GetLastError();
		Print("[!] GetProcAddress failed (%d) to find Lua function \"%s\".\n", lastError, name);
		return lastError;
	}
	return 0;
}

EXPORT DWORD InitLuaProvider(SharedDLLMemory* sharedDLL) {

	#define setLuaPointer(patternName, functionNameStr, functionName) \
		if (reinterpret_cast<intptr_t>(luaLibrary()) == -1) { \
			if (auto itr = patterns().find(TEXT(patternName)); itr != patterns().end()) { \
				##functionName = (type_##functionName)(itr->second.value); \
			} \
			else { \
				Print("[!] Lua pattern not defined: \"Hardcoded_%s\"; binding failed!\n", functionNameStr); \
				return -1; \
			} \
		} \
		else { \
			if (DWORD lastError = getLuaProc(luaLibrary(), functionNameStr, ##functionName)) { \
				return lastError; \
			} \
		}

	setLuaPointer("Hardcoded_lua_callk", "lua_callk", lua_callk)
	setLuaPointer("Hardcoded_lua_createtable", "lua_createtable", lua_createtable)
	setLuaPointer("Hardcoded_lua_getfield", "lua_getfield", lua_getfield)
	setLuaPointer("Hardcoded_lua_getglobal", "lua_getglobal", lua_getglobal)
	setLuaPointer("Hardcoded_lua_getmetatable", "lua_getmetatable", lua_getmetatable)
	setLuaPointer("Hardcoded_lua_gettable", "lua_gettable", lua_gettable)
	setLuaPointer("Hardcoded_lua_gettop", "lua_gettop", lua_gettop)
	setLuaPointer("Hardcoded_lua_insert", "lua_insert", lua_insert)
	setLuaPointer("Hardcoded_lua_iscfunction", "lua_iscfunction", lua_iscfunction)
	setLuaPointer("Hardcoded_lua_isnumber", "lua_isnumber", lua_isnumber)
	setLuaPointer("Hardcoded_lua_isuserdata", "lua_isuserdata", lua_isuserdata)
	setLuaPointer("Hardcoded_lua_newuserdata", "lua_newuserdata", lua_newuserdata)
	setLuaPointer("Hardcoded_lua_next", "lua_next", lua_next)
	setLuaPointer("Hardcoded_lua_pcallk", "lua_pcallk", lua_pcallk)
	setLuaPointer("Hardcoded_lua_pushboolean", "lua_pushboolean", lua_pushboolean)
	setLuaPointer("Hardcoded_lua_pushcclosure", "lua_pushcclosure", lua_pushcclosure)
	setLuaPointer("Hardcoded_lua_pushinteger", "lua_pushinteger", lua_pushinteger)
	setLuaPointer("Hardcoded_lua_pushlightuserdata", "lua_pushlightuserdata", lua_pushlightuserdata)
	setLuaPointer("Hardcoded_lua_pushlstring", "lua_pushlstring", lua_pushlstring)
	setLuaPointer("Hardcoded_lua_pushnil", "lua_pushnil", lua_pushnil)
	setLuaPointer("Hardcoded_lua_pushnumber", "lua_pushnumber", lua_pushnumber)
	setLuaPointer("Hardcoded_lua_pushstring", "lua_pushstring", lua_pushstring)
	setLuaPointer("Hardcoded_lua_pushvalue", "lua_pushvalue", lua_pushvalue)
	setLuaPointer("Hardcoded_lua_rawget", "lua_rawget", lua_rawget)
	setLuaPointer("Hardcoded_lua_rawgeti", "lua_rawgeti", lua_rawgeti)
	setLuaPointer("Hardcoded_lua_rawset", "lua_rawset", lua_rawset)
	setLuaPointer("Hardcoded_lua_rawseti", "lua_rawseti", lua_rawseti)
	setLuaPointer("Hardcoded_lua_remove", "lua_remove", lua_remove)
	setLuaPointer("Hardcoded_lua_setglobal", "lua_setglobal", lua_setglobal)
	setLuaPointer("Hardcoded_lua_setmetatable", "lua_setmetatable", lua_setmetatable)
	setLuaPointer("Hardcoded_lua_settable", "lua_settable", lua_settable)
	setLuaPointer("Hardcoded_lua_settop", "lua_settop", lua_settop)
	setLuaPointer("Hardcoded_lua_toboolean", "lua_toboolean", lua_toboolean)
	setLuaPointer("Hardcoded_lua_tocfunction", "lua_tocfunction", lua_tocfunction)
	setLuaPointer("Hardcoded_lua_tointegerx", "lua_tointegerx", lua_tointegerx)
	setLuaPointer("Hardcoded_lua_tolstring", "lua_tolstring", lua_tolstring)
	setLuaPointer("Hardcoded_lua_tonumberx", "lua_tonumberx", lua_tonumberx)
	setLuaPointer("Hardcoded_lua_touserdata", "lua_touserdata", lua_touserdata)
	setLuaPointer("Hardcoded_lua_type", "lua_type", lua_type)
	setLuaPointer("Hardcoded_luaL_error", "luaL_error", luaL_error)
	setLuaPointer("Hardcoded_luaL_loadfilex", "luaL_loadfilex", luaL_loadfilex)
	setLuaPointer("Hardcoded_luaL_loadstring", "luaL_loadstring", luaL_loadstring)
	setLuaPointer("Hardcoded_luaL_ref", "luaL_ref", luaL_ref)

	return ERROR_SUCCESS;
}
