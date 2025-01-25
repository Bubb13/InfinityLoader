
#pragma once

#include <string>

#include "dll_api.h"

#ifdef LUA_PROVIDER_EXPORT
#define LUA_PROVIDER_API EXPORT
#define LUA_PROVIDER_API_VAR EXTERN_EXPORT
#else
#define LUA_PROVIDER_API IMPORT
#define LUA_PROVIDER_API_VAR EXTERN_IMPORT
#endif

///////////////
// Type Defs //
///////////////

struct lua_State; // Hide implementation
typedef int (*lua_CFunction)(lua_State* L);
typedef ptrdiff_t lua_Integer;
typedef double lua_Number;

////////////////////
// Config Globals //
////////////////////

LUA_PROVIDER_API_VAR int LUA_VERSION_NUM;
LUA_PROVIDER_API_VAR int LUA_REGISTRYINDEX;
LUA_PROVIDER_API_VAR int LUA_RIDX_GLOBALS;
LUA_PROVIDER_API_VAR int LUA_GLOBALSINDEX;

//////////////////
// Lua Wrappers //
//////////////////

LUA_PROVIDER_API int lua_absindex(lua_State* L, int idx);
LUA_PROVIDER_API lua_CFunction lua_atpanic(lua_State* L, lua_CFunction panicf);
LUA_PROVIDER_API void lua_callk(lua_State* L, int nargs, int nresults, int ctx, lua_CFunction k);
LUA_PROVIDER_API void lua_concat(lua_State* L, int n);
LUA_PROVIDER_API void lua_createtable(lua_State* L, int narr, int nrec);
LUA_PROVIDER_API void lua_getfield(lua_State* L, int idx, const char* k);
LUA_PROVIDER_API void lua_getglobal(lua_State* L, const char* name);
LUA_PROVIDER_API int lua_getmetatable(lua_State* L, int objindex);
LUA_PROVIDER_API void lua_gettable(lua_State* L, int index);
LUA_PROVIDER_API int lua_gettop(lua_State* L);
LUA_PROVIDER_API void lua_insert(lua_State* L, int idx);
LUA_PROVIDER_API int lua_iscfunction(lua_State* L, int index);
LUA_PROVIDER_API int lua_isnumber(lua_State* L, int index);
LUA_PROVIDER_API int lua_isstring(lua_State* L, int index);
LUA_PROVIDER_API int lua_isuserdata(lua_State* L, int index);
LUA_PROVIDER_API void* lua_newuserdata(lua_State* L, size_t size);
LUA_PROVIDER_API int lua_next(lua_State* L, int index);
LUA_PROVIDER_API int lua_pcall(lua_State* L, int nargs, int nresults, int msgh);
LUA_PROVIDER_API int lua_pcallk(lua_State* L, int nargs, int nresults, int errfunc, int ctx, lua_CFunction k);
LUA_PROVIDER_API void lua_pushboolean(lua_State* L, int b);
LUA_PROVIDER_API void lua_pushcclosure(lua_State* L, lua_CFunction fn, int n);
LUA_PROVIDER_API void lua_pushinteger(lua_State* L, lua_Integer n);
LUA_PROVIDER_API void lua_pushlightuserdata(lua_State* L, void* p);
LUA_PROVIDER_API const char* lua_pushlstring(lua_State* L, const char* s, size_t len);
LUA_PROVIDER_API void lua_pushnil(lua_State* L);
LUA_PROVIDER_API void lua_pushnumber(lua_State* L, lua_Number n);
LUA_PROVIDER_API const char* lua_pushstring(lua_State* L, const char* s);
LUA_PROVIDER_API void lua_pushvalue(lua_State* L, int index);
LUA_PROVIDER_API int lua_rawequal(lua_State* L, int index1, int index2);
LUA_PROVIDER_API void lua_rawget(lua_State* L, int index);
LUA_PROVIDER_API void lua_rawgeti(lua_State* L, int index, int n);
LUA_PROVIDER_API size_t lua_rawlen(lua_State* L, int index);
LUA_PROVIDER_API void lua_rawset(lua_State* L, int index);
LUA_PROVIDER_API void lua_rawseti(lua_State* L, int index, int n);
LUA_PROVIDER_API void lua_remove(lua_State* L, int index);
LUA_PROVIDER_API void lua_setfield(lua_State* L, int index, const char* k);
LUA_PROVIDER_API void lua_setglobal(lua_State* L, const char* name);
LUA_PROVIDER_API void lua_setmetatable(lua_State* L, int index);
LUA_PROVIDER_API void lua_settable(lua_State* L, int index);
LUA_PROVIDER_API void lua_settop(lua_State* L, int index);
LUA_PROVIDER_API int lua_toboolean(lua_State* L, int idx);
LUA_PROVIDER_API lua_CFunction lua_tocfunction(lua_State* L, int index);
LUA_PROVIDER_API lua_Integer lua_tointegerx(lua_State* L, int index, int* isnum);
LUA_PROVIDER_API const char* lua_tolstring(lua_State* L, int index, size_t* len);
LUA_PROVIDER_API lua_Number lua_tonumber(lua_State* L, int index);
LUA_PROVIDER_API lua_Number lua_tonumberx(lua_State* L, int index, int* isnum);
LUA_PROVIDER_API void* lua_touserdata(lua_State* L, int idx);
LUA_PROVIDER_API int lua_type(lua_State* L, int index);
LUA_PROVIDER_API const char* lua_typename(lua_State* L, int tp);
LUA_PROVIDER_API int luaL_error(lua_State* L, const char* fmt, ...);
LUA_PROVIDER_API int luaL_loadfilex(lua_State* L, const char* fileName, const char* mode);
LUA_PROVIDER_API int luaL_loadstring(lua_State* L, const char* s);
LUA_PROVIDER_API int luaL_newmetatable(lua_State* L, const char* tname);
LUA_PROVIDER_API lua_State* luaL_newstate();
LUA_PROVIDER_API void luaL_openlibs(lua_State* L);
LUA_PROVIDER_API int luaL_ref(lua_State* L, int t);
LUA_PROVIDER_API void luaL_traceback(lua_State* L, lua_State* L1, const char* msg, int level);

/////////////
// Utility //
/////////////

LUA_PROVIDER_API bool CheckLuaArgBoundsInt8(lua_State* L, int argI, __int8& resultVal, std::string& error);
LUA_PROVIDER_API bool CheckLuaArgBoundsInt16(lua_State* L, int argI, __int16& resultVal, std::string& error);
LUA_PROVIDER_API bool CheckLuaArgBoundsInt32(lua_State* L, int argI, __int32& resultVal, std::string& error);
LUA_PROVIDER_API bool CheckLuaArgBoundsInt64(lua_State* L, int argI, __int64& resultVal, std::string& error);
LUA_PROVIDER_API bool CheckLuaArgBoundsUInt8(lua_State* L, int argI, unsigned __int8& resultVal, std::string& error);
LUA_PROVIDER_API bool CheckLuaArgBoundsUInt16(lua_State* L, int argI, unsigned __int16& resultVal, std::string& error);
LUA_PROVIDER_API bool CheckLuaArgBoundsUInt32(lua_State* L, int argI, unsigned __int32& resultVal, std::string& error);
LUA_PROVIDER_API bool CheckLuaArgBoundsUInt64(lua_State* L, int argI, unsigned __int64& resultVal, std::string& error);
LUA_PROVIDER_API bool CheckLuaArgBoundsInt(lua_State* L, int argI, int& resultVal, std::string& error);
LUA_PROVIDER_API bool CheckLuaArgBoundsUInt(lua_State* L, int argI, unsigned int& resultVal, std::string& error);
LUA_PROVIDER_API bool CheckLuaArgBoundsSizeT(lua_State* L, int argI, size_t& resultVal, std::string& error);
LUA_PROVIDER_API bool CheckLuaArgBoundsUIntPtr(lua_State* L, const int argI, size_t& resultVal, std::string& error);

/////////////
// Defines //
/////////////

#define LUA_OK 0

#define LUA_TNONE -1
#define LUA_TNIL 0
#define LUA_TBOOLEAN 1
#define LUA_TLIGHTUSERDATA 2
#define LUA_TNUMBER 3
#define LUA_TSTRING 4
#define LUA_TTABLE 5
#define LUA_TFUNCTION 6
#define LUA_TUSERDATA 7
#define LUA_TTHREAD 8

#define lua_call(L, n, r) lua_callk(L, (n), (r), 0, NULL)
#define lua_isboolean(L, n) (lua_type(L, (n)) == LUA_TBOOLEAN)
#define lua_isfunction(L, n) (lua_type(L, (n)) == LUA_TFUNCTION)
#define lua_isnil(L, n) (lua_type(L, (n)) == LUA_TNIL)
#define lua_ispseudo(i) ((i) <= LUA_REGISTRYINDEX)
#define lua_istable(L, n) (lua_type(L, (n)) == LUA_TTABLE)
#define lua_newtable(L) lua_createtable(L, 0, 0)
#define lua_pop(L, n) lua_settop(L, -(n) - 1)
#define lua_pushcfunction(L, f) lua_pushcclosure(L, (f), 0)
#define lua_tointeger(L, i) lua_tointegerx(L, (i), NULL)
#define lua_tostring(L, i) lua_tolstring(L, (i), NULL)
#define luaL_getmetatable(L,n) (lua_getfield(L, LUA_REGISTRYINDEX, (n)))

#define castLuaIntArg(argI, typeName, funcSuffix, varName) \
	typeName varName; \
	if (std::string error; CheckLuaArgBounds##funcSuffix(L, argI, varName, error)) { \
		luaL_error(L, "%s", error.c_str()); \
		return 0; \
	}
