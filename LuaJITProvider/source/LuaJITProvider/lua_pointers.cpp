
#include <format>

#include "infinity_loader_common_api.h"
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

type_lua_atpanic p_lua_atpanic;
type_lua_callk p_lua_callk;
type_lua_concat p_lua_concat;
type_lua_createtable p_lua_createtable;
type_lua_getfield p_lua_getfield;
type_lua_getglobal p_lua_getglobal;
type_lua_getmetatable p_lua_getmetatable;
type_lua_gettable p_lua_gettable;
type_lua_gettop p_lua_gettop;
type_lua_insert p_lua_insert;
type_lua_iscfunction p_lua_iscfunction;
type_lua_isnumber p_lua_isnumber;
type_lua_isstring p_lua_isstring;
type_lua_isuserdata p_lua_isuserdata;
type_lua_newuserdata p_lua_newuserdata;
type_lua_next p_lua_next;
type_lua_pcall p_lua_pcall;
type_lua_pcallk p_lua_pcallk;
type_lua_pushboolean p_lua_pushboolean;
type_lua_pushcclosure p_lua_pushcclosure;
type_lua_pushinteger p_lua_pushinteger;
type_lua_pushlightuserdata p_lua_pushlightuserdata;
type_lua_pushlstring p_lua_pushlstring;
type_lua_pushnil p_lua_pushnil;
type_lua_pushnumber p_lua_pushnumber;
type_lua_pushstring p_lua_pushstring;
type_lua_pushvalue p_lua_pushvalue;
type_lua_rawequal p_lua_rawequal;
type_lua_rawget p_lua_rawget;
type_lua_rawgeti p_lua_rawgeti;
type_lua_rawlen p_lua_rawlen;
type_lua_rawset p_lua_rawset;
type_lua_rawseti p_lua_rawseti;
type_lua_remove p_lua_remove;
type_lua_setfield p_lua_setfield;
type_lua_setglobal p_lua_setglobal;
type_lua_setmetatable p_lua_setmetatable;
type_lua_settable p_lua_settable;
type_lua_settop p_lua_settop;
type_lua_toboolean p_lua_toboolean;
type_lua_tocfunction p_lua_tocfunction;
type_lua_tointegerx p_lua_tointegerx;
type_lua_tolstring p_lua_tolstring;
type_lua_tonumber p_lua_tonumber;
type_lua_tonumberx p_lua_tonumberx;
type_lua_touserdata p_lua_touserdata;
type_lua_type p_lua_type;
type_lua_typename p_lua_typename;
type_luaL_error p_luaL_error;
type_luaL_loadfilex p_luaL_loadfilex;
type_luaL_loadstring p_luaL_loadstring;
type_luaL_newmetatable p_luaL_newmetatable;
type_luaL_newstate p_luaL_newstate;
type_luaL_openlibs p_luaL_openlibs;
type_luaL_ref p_luaL_ref;

////////////////////////////////
// Switchable Implementations //
////////////////////////////////

//-----------//
// lua_pcall //
//-----------//

type_lua_pcall imp_lua_pcall;

int lua51_pcall(lua_State* L, int nargs, int nresults, int msgh) {
	return p_lua_pcall(L, nargs, nresults, msgh);
}

int lua52_pcall(lua_State* L, int nargs, int nresults, int msgh) {
	return p_lua_pcallk(L, nargs, nresults, msgh, 0, nullptr);
}

//------------//
// lua_pcallk //
//------------//

type_lua_pcallk imp_lua_pcallk;

int lua51_pcallk(lua_State* L, int nargs, int nresults, int errfunc, int ctx, lua_CFunction k) {
	if (ctx != 0) Print("[!][LuaProvider.dll] lua51_pcallk() - Unhandled lua52 argument (ctx)\n");
	if (k != nullptr) Print("[!][LuaProvider.dll] lua51_pcallk() - Unhandled lua52 argument (k)\n");
	return p_lua_pcall(L, nargs, nresults, errfunc);
}

int lua52_pcallk(lua_State* L, int nargs, int nresults, int errfunc, int ctx, lua_CFunction k) {
	return p_lua_pcallk(L, nargs, nresults, errfunc, ctx, k);
}

//--------------//
// lua_tonumber //
//--------------//

type_lua_tonumber imp_lua_tonumber;

lua_Number lua51_tonumber(lua_State* L, int index) {
	return p_lua_tonumber(L, index);
}

lua_Number lua52_tonumber(lua_State* L, int index) {
	return p_lua_tonumberx(L, index, nullptr);
}

//---------------//
// lua_tonumberx //
//---------------//

type_lua_tonumberx imp_lua_tonumberx;

lua_Number lua51_tonumberx(lua_State* L, int index, int* isnum) {
	if (isnum != nullptr) Print("[!][LuaProvider.dll] lua51_tonumberx() - Unhandled lua52 argument (isnum)\n");
	return p_lua_tonumber(L, index);
}

lua_Number lua52_tonumberx(lua_State* L, int index, int* isnum) {
	return p_lua_tonumberx(L, index, isnum);
}

/////////////
// Exports //
/////////////

EXPORT lua_CFunction lua_atpanic(lua_State* L, lua_CFunction panicf) {
	return p_lua_atpanic(L, panicf);
}

EXPORT void lua_callk(lua_State* L, int nargs, int nresults, int ctx, lua_CFunction k) {
	p_lua_callk(L, nargs, nresults, ctx, k);
}

EXPORT void lua_concat(lua_State* L, int n) {
	p_lua_concat(L, n);
}

EXPORT void lua_createtable(lua_State* L, int narr, int nrec) {
	p_lua_createtable(L, narr, nrec);
}

EXPORT void lua_getfield(lua_State* L, int idx, const char* k) {
	p_lua_getfield(L, idx, k);
}

EXPORT void lua_getglobal(lua_State* L, const char* name) {
	p_lua_getglobal(L, name);
}

EXPORT int lua_getmetatable(lua_State* L, int objindex) {
	return p_lua_getmetatable(L, objindex);
}

EXPORT void lua_gettable(lua_State* L, int index) {
	p_lua_gettable(L, index);
}

EXPORT int lua_gettop(lua_State* L) {
	return p_lua_gettop(L);
}

EXPORT void lua_insert(lua_State* L, int idx) {
	p_lua_insert(L, idx);
}

EXPORT int lua_iscfunction(lua_State* L, int index) {
	return p_lua_iscfunction(L, index);
}

EXPORT int lua_isnumber(lua_State* L, int index) {
	return p_lua_isnumber(L, index);
}

EXPORT int lua_isstring(lua_State* L, int index) {
	return p_lua_isstring(L, index);
}

EXPORT int lua_isuserdata(lua_State* L, int index) {
	return p_lua_isuserdata(L, index);
}

EXPORT void* lua_newuserdata(lua_State* L, size_t size) {
	return p_lua_newuserdata(L, size);
}

EXPORT int lua_next(lua_State* L, int index) {
	return p_lua_next(L, index);
}

EXPORT int lua_pcall(lua_State* L, int nargs, int nresults, int msgh) {
	return imp_lua_pcall(L, nargs, nresults, msgh);
}

EXPORT int lua_pcallk(lua_State* L, int nargs, int nresults, int errfunc, int ctx, lua_CFunction k) {
	return imp_lua_pcallk(L, nargs, nresults, errfunc, ctx, k);
}

EXPORT void lua_pushboolean(lua_State* L, int b) {
	p_lua_pushboolean(L, b);
}

EXPORT void lua_pushcclosure(lua_State* L, lua_CFunction fn, int n) {
	p_lua_pushcclosure(L, fn, n);
}

EXPORT void lua_pushinteger(lua_State* L, lua_Integer n) {
	p_lua_pushinteger(L, n);
}

EXPORT void lua_pushlightuserdata(lua_State* L, void* p) {
	p_lua_pushlightuserdata(L, p);
}

EXPORT const char* lua_pushlstring(lua_State* L, const char* s, size_t len) {
	return p_lua_pushlstring(L, s, len);
}

EXPORT void lua_pushnil(lua_State* L) {
	p_lua_pushnil(L);
}

EXPORT void lua_pushnumber(lua_State* L, lua_Number n) {
	p_lua_pushnumber(L, n);
}

EXPORT const char* lua_pushstring(lua_State* L, const char* s) {
	return p_lua_pushstring(L, s);
}

EXPORT void lua_pushvalue(lua_State* L, int index) {
	p_lua_pushvalue(L, index);
}

EXPORT int lua_rawequal(lua_State* L, int index1, int index2) {
	return p_lua_rawequal(L, index1, index2);
}

EXPORT void lua_rawget(lua_State* L, int index) {
	p_lua_rawget(L, index);
}

EXPORT void lua_rawgeti(lua_State* L, int index, int n) {
	p_lua_rawgeti(L, index, n);
}

EXPORT size_t lua_rawlen(lua_State* L, int index) {
	return p_lua_rawlen(L, index);
}

EXPORT void lua_rawset(lua_State* L, int index) {
	p_lua_rawset(L, index);
}

EXPORT void lua_rawseti(lua_State* L, int index, int n) {
	p_lua_rawseti(L, index, n);
}

EXPORT void lua_remove(lua_State* L, int index) {
	p_lua_remove(L, index);
}

EXPORT void lua_setfield(lua_State* L, int index, const char* k) {
	p_lua_setfield(L, index, k);
}

EXPORT void lua_setglobal(lua_State* L, const char* name) {
	p_lua_setglobal(L, name);
}

EXPORT void lua_setmetatable(lua_State* L, int index) {
	p_lua_setmetatable(L, index);
}

EXPORT void lua_settable(lua_State* L, int index) {
	p_lua_settable(L, index);
}

EXPORT void lua_settop(lua_State* L, int index) {
	p_lua_settop(L, index);
}

EXPORT int lua_toboolean(lua_State* L, int idx) {
	return p_lua_toboolean(L, idx);
}

EXPORT lua_CFunction lua_tocfunction(lua_State* L, int index) {
	return p_lua_tocfunction(L, index);
}

EXPORT lua_Integer lua_tointegerx(lua_State* L, int index, int* isnum) {
	return p_lua_tointegerx(L, index, isnum);
}

EXPORT const char* lua_tolstring(lua_State* L, int index, size_t* len) {
	return p_lua_tolstring(L, index, len);
}

EXPORT lua_Number lua_tonumber(lua_State* L, int index)
{
	return imp_lua_tonumber(L, index);
}

EXPORT lua_Number lua_tonumberx(lua_State* L, int index, int* isnum) {
	return imp_lua_tonumberx(L, index, isnum);
}

EXPORT void* lua_touserdata(lua_State* L, int idx)
{
	return p_lua_touserdata(L, idx);
}

EXPORT int lua_type(lua_State* L, int index)
{
	return p_lua_type(L, index);
}

EXPORT const char* lua_typename(lua_State* L, int tp)
{
	return p_lua_typename(L, tp);
}

EXPORT __attribute((naked)) int luaL_error(lua_State* L, const char* fmt, ...)
{
	__asm__("jmp [" EXTERN_C_SYMBOL(p_luaL_error) "]");
}

EXPORT int luaL_loadfilex(lua_State* L, const char* fileName, const char* mode)
{
	return p_luaL_loadfilex(L, fileName, mode);
}

EXPORT int luaL_loadstring(lua_State* L, const char* s)
{
	return p_luaL_loadstring(L, s);
}

EXPORT int luaL_newmetatable(lua_State* L, const char* tname)
{
	return p_luaL_newmetatable(L, tname);
}

EXPORT lua_State* luaL_newstate()
{
	return p_luaL_newstate();
}

EXPORT void luaL_openlibs(lua_State* L)
{
	p_luaL_openlibs(L);
}

EXPORT int luaL_ref(lua_State* L, int t)
{
	return p_luaL_ref(L, t);
}

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
