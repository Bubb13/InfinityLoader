
#include <format>

#include "lua_pointers.h"

/////////////
// Defines //
/////////////

////////////////////
// Config Globals //
////////////////////

EXPORT int LUA_VERSION_NUM = 501;
EXPORT int LUA_REGISTRYINDEX = -10000;
// Invalid dummy value for code that supports both Lua 5.1 and Lua 5.2.
// A Lua 5.2 LuaProvider should properly define this.
EXPORT int LUA_RIDX_GLOBALS;
EXPORT int LUA_GLOBALSINDEX = -10002;

//////////////
// Pointers //
//////////////

EXPORT type_lua_atpanic lua_atpanic;
EXPORT type_lua_callk lua_callk;
EXPORT type_lua_createtable lua_createtable;
EXPORT type_lua_getfield lua_getfield;
EXPORT type_lua_getglobal lua_getglobal;
EXPORT type_lua_getmetatable lua_getmetatable;
EXPORT type_lua_gettable lua_gettable;
EXPORT type_lua_gettop lua_gettop;
EXPORT type_lua_insert lua_insert;
EXPORT type_lua_iscfunction lua_iscfunction;
EXPORT type_lua_isnumber lua_isnumber;
EXPORT type_lua_isuserdata lua_isuserdata;
EXPORT type_lua_newuserdata lua_newuserdata;
EXPORT type_lua_next lua_next;
EXPORT type_lua_pcallk lua_pcallk;
EXPORT type_lua_pushboolean lua_pushboolean;
EXPORT type_lua_pushcclosure lua_pushcclosure;
EXPORT type_lua_pushinteger lua_pushinteger;
EXPORT type_lua_pushlightuserdata lua_pushlightuserdata;
EXPORT type_lua_pushlstring lua_pushlstring;
EXPORT type_lua_pushnil lua_pushnil;
EXPORT type_lua_pushstring lua_pushstring;
EXPORT type_lua_pushvalue lua_pushvalue;
EXPORT type_lua_rawget lua_rawget;
EXPORT type_lua_rawgeti lua_rawgeti;
EXPORT type_lua_rawlen lua_rawlen;
EXPORT type_lua_rawset lua_rawset;
EXPORT type_lua_rawseti lua_rawseti;
EXPORT type_lua_remove lua_remove;
EXPORT type_lua_setglobal lua_setglobal;
EXPORT type_lua_setmetatable lua_setmetatable;
EXPORT type_lua_settable lua_settable;
EXPORT type_lua_settop lua_settop;
EXPORT type_lua_toboolean lua_toboolean;
EXPORT type_lua_tocfunction lua_tocfunction;
EXPORT type_lua_tointegerx lua_tointegerx;
EXPORT type_lua_tolstring lua_tolstring;
EXPORT type_lua_tonumberx lua_tonumberx;
EXPORT type_lua_touserdata lua_touserdata;
EXPORT type_lua_type lua_type;
EXPORT type_luaL_error luaL_error;
EXPORT type_luaL_loadfilex luaL_loadfilex;
EXPORT type_luaL_loadstring luaL_loadstring;
EXPORT type_luaL_ref luaL_ref;
EXPORT type_lua_pushnumber lua_pushnumber;

///////////////////////
// Reimplementations //
///////////////////////

EXPORT int lua_absindex(lua_State* L, int idx) {
	return idx > 0 || idx <= LUA_REGISTRYINDEX ? idx : lua_gettop(L) + idx + 1;
}

/////////////
// Utiilty //
/////////////

typedef ptrdiff_t lua_Integer;
#define lua_tointeger(L, i) lua_tointegerx(L, (i), NULL)

template<typename IntegerType>
bool checkLuaArgBounds(lua_State *const L, const int argI, IntegerType& resultVal, std::string& error) {

	const lua_Integer val = lua_tointeger(L, argI);

	constexpr auto min = (std::numeric_limits<IntegerType>::lowest)();
	if (val < min) {
		// Error: Too small
		error = std::format("arg #{:d} ({:d}) too small (min: {:d})", argI, val, min);
		return true;
	}

	constexpr auto max = (std::numeric_limits<IntegerType>::max)();
	if (val > max) {
		// Error: Too large
		error = std::format("arg #{:d} ({:d}) too large (max: {:d})", argI, val, max);
		return true;
	}

	resultVal = static_cast<IntegerType>(val);
	return false;
}

EXPORT bool CheckLuaArgBoundsInt8(lua_State* L, const int argI, __int8& resultVal, std::string& error) {
	return checkLuaArgBounds<__int8>(L, argI, resultVal, error);
}

EXPORT bool CheckLuaArgBoundsInt16(lua_State* L, const int argI, __int16& resultVal, std::string& error) {
 	return checkLuaArgBounds<__int16>(L, argI, resultVal, error);
}

EXPORT bool CheckLuaArgBoundsInt32(lua_State* L, const int argI, __int32& resultVal, std::string& error) {
	return checkLuaArgBounds<__int32>(L, argI, resultVal, error);
}

EXPORT bool CheckLuaArgBoundsInt64(lua_State* L, const int argI, __int64& resultVal, std::string& error) {
	return checkLuaArgBounds<__int64>(L, argI, resultVal, error);
}

EXPORT bool CheckLuaArgBoundsUInt8(lua_State* L, const int argI, unsigned __int8& resultVal, std::string& error) {
	return checkLuaArgBounds<unsigned __int8>(L, argI, resultVal, error);
}

EXPORT bool CheckLuaArgBoundsUInt16(lua_State* L, const int argI, unsigned __int16& resultVal, std::string& error) {
	return checkLuaArgBounds<unsigned __int16>(L, argI, resultVal, error);
}

EXPORT bool CheckLuaArgBoundsUInt32(lua_State* L, const int argI, unsigned __int32& resultVal, std::string& error) {
	return checkLuaArgBounds<unsigned __int32>(L, argI, resultVal, error);
}

EXPORT bool CheckLuaArgBoundsUInt64(lua_State* L, const int argI, unsigned __int64& resultVal, std::string& error) {
	return checkLuaArgBounds<unsigned __int64>(L, argI, resultVal, error);
}

EXPORT bool CheckLuaArgBoundsInt(lua_State* L, const int argI, int& resultVal, std::string& error) {
	return checkLuaArgBounds<int>(L, argI, resultVal, error);
}

EXPORT bool CheckLuaArgBoundsUInt(lua_State* L, const int argI, unsigned int& resultVal, std::string& error) {
	return checkLuaArgBounds<unsigned int>(L, argI, resultVal, error);
}

EXPORT bool CheckLuaArgBoundsSizeT(lua_State* L, const int argI, size_t& resultVal, std::string& error) {
	return checkLuaArgBounds<size_t>(L, argI, resultVal, error);
}

EXPORT bool CheckLuaArgBoundsUIntPtr(lua_State* L, const int argI, size_t& resultVal, std::string& error) {
	return checkLuaArgBounds<uintptr_t>(L, argI, resultVal, error);
}
