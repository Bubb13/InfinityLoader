
#pragma once

#include "dll_api.h"
#include "lua/lua.h"

////////////////////
// Config Globals //
////////////////////

EXTERN_EXPORT int LUA_VERSION_NUM;
EXTERN_EXPORT int LUA_REGISTRYINDEX;
EXTERN_EXPORT int LUA_RIDX_GLOBALS;
// Invalid dummy value for code that supports both Lua 5.1 and Lua 5.2.
// A Lua 5.1 LuaProvider should properly define this.
EXTERN_EXPORT int LUA_GLOBALSINDEX;

//////////////
// Pointers //
//////////////

typedef lua_CFunction (*type_lua_atpanic)(lua_State* L, lua_CFunction panicf);
EXTERN_EXPORT type_lua_atpanic lua_atpanic;

typedef void (*type_lua_callk)(lua_State* L, int nargs, int nresults, int ctx, lua_CFunction k);
EXTERN_EXPORT type_lua_callk lua_callk;

typedef void (*type_lua_concat)(lua_State* L, int n);
EXTERN_EXPORT type_lua_concat lua_concat;

typedef void (*type_lua_createtable)(lua_State* L, int narr, int nrec);
EXTERN_EXPORT type_lua_createtable lua_createtable;

typedef void (*type_lua_getfield)(lua_State* L, int idx, const char* k);
EXTERN_EXPORT type_lua_getfield lua_getfield;

typedef void (*type_lua_getglobal)(lua_State* L, const char* name);
EXTERN_EXPORT type_lua_getglobal lua_getglobal;

typedef int (*type_lua_getmetatable)(lua_State* L, int objindex);
EXTERN_EXPORT type_lua_getmetatable lua_getmetatable;

typedef void (*type_lua_gettable)(lua_State* L, int index);
EXTERN_EXPORT type_lua_gettable lua_gettable;

typedef int (*type_lua_gettop)(lua_State* L);
EXTERN_EXPORT type_lua_gettop lua_gettop;

typedef void (*type_lua_insert)(lua_State* L, int idx);
EXTERN_EXPORT type_lua_insert lua_insert;

typedef int (*type_lua_iscfunction)(lua_State* L, int index);
EXTERN_EXPORT type_lua_iscfunction lua_iscfunction;

typedef int (*type_lua_isnumber)(lua_State* L, int index);
EXTERN_EXPORT type_lua_isnumber lua_isnumber;

typedef int (*type_lua_isstring)(lua_State* L, int index);
EXTERN_EXPORT type_lua_isstring lua_isstring;

typedef int (*type_lua_isuserdata)(lua_State* L, int index);
EXTERN_EXPORT type_lua_isuserdata lua_isuserdata;

typedef void* (*type_lua_newuserdata)(lua_State* L, size_t size);
EXTERN_EXPORT type_lua_newuserdata lua_newuserdata;

typedef int (*type_lua_next)(lua_State* L, int index);
EXTERN_EXPORT type_lua_next lua_next;

typedef int (*type_lua_pcallk)(lua_State* L, int nargs, int nresults, int errfunc, int ctx, lua_CFunction k);
EXTERN_EXPORT type_lua_pcallk lua_pcallk;

typedef void (*type_lua_pushboolean)(lua_State* L, int b);
EXTERN_EXPORT type_lua_pushboolean lua_pushboolean;

typedef void (*type_lua_pushcclosure)(lua_State* L, lua_CFunction fn, int n);
EXTERN_EXPORT type_lua_pushcclosure lua_pushcclosure;

typedef void (*type_lua_pushinteger)(lua_State* L, lua_Integer n);
EXTERN_EXPORT type_lua_pushinteger lua_pushinteger;

typedef void (*type_lua_pushlightuserdata)(lua_State* L, void* p);
EXTERN_EXPORT type_lua_pushlightuserdata lua_pushlightuserdata;

typedef const char* (*type_lua_pushlstring)(lua_State* L, const char* s, size_t len);
EXTERN_EXPORT type_lua_pushlstring lua_pushlstring;

typedef void (*type_lua_pushnil)(lua_State* L);
EXTERN_EXPORT type_lua_pushnil lua_pushnil;

typedef const char* (*type_lua_pushstring)(lua_State* L, const char* s);
EXTERN_EXPORT type_lua_pushstring lua_pushstring;

typedef void (*type_lua_pushvalue)(lua_State* L, int index);
EXTERN_EXPORT type_lua_pushvalue lua_pushvalue;

typedef int (*type_lua_rawequal)(lua_State* L, int index1, int index2);
EXTERN_EXPORT type_lua_rawequal lua_rawequal;

typedef void (*type_lua_rawget)(lua_State* L, int index);
EXTERN_EXPORT type_lua_rawget lua_rawget;

typedef void (*type_lua_rawgeti)(lua_State* L, int index, int n);
EXTERN_EXPORT type_lua_rawgeti lua_rawgeti;

typedef size_t (*type_lua_rawlen)(lua_State* L, int index);
EXTERN_EXPORT type_lua_rawlen lua_rawlen;

typedef void (*type_lua_rawset)(lua_State* L, int index);
EXTERN_EXPORT type_lua_rawset lua_rawset;

typedef void (*type_lua_rawseti)(lua_State* L, int index, int n);
EXTERN_EXPORT type_lua_rawseti lua_rawseti;

typedef void (*type_lua_remove)(lua_State* L, int index);
EXTERN_EXPORT type_lua_remove lua_remove;

typedef void (*type_lua_setglobal)(lua_State* L, const char* name);
EXTERN_EXPORT type_lua_setglobal lua_setglobal;

typedef void (*type_lua_setmetatable)(lua_State* L, int index);
EXTERN_EXPORT type_lua_setmetatable lua_setmetatable;

typedef void (*type_lua_settable)(lua_State* L, int index);
EXTERN_EXPORT type_lua_settable lua_settable;

typedef void (*type_lua_settop)(lua_State* L, int index);
EXTERN_EXPORT type_lua_settop lua_settop;

typedef int (*type_lua_toboolean)(lua_State* L, int idx);
EXTERN_EXPORT type_lua_toboolean lua_toboolean;

typedef lua_CFunction (*type_lua_tocfunction)(lua_State* L, int index);
EXTERN_EXPORT type_lua_tocfunction lua_tocfunction;

typedef lua_Integer (*type_lua_tointegerx)(lua_State* L, int index, int* isnum);
EXTERN_EXPORT type_lua_tointegerx lua_tointegerx;

typedef const char* (*type_lua_tolstring)(lua_State* L, int index, size_t* len);
EXTERN_EXPORT type_lua_tolstring lua_tolstring;

typedef lua_Number (*type_lua_tonumberx)(lua_State* L, int index, int* isnum);
EXTERN_EXPORT type_lua_tonumberx lua_tonumberx;

typedef void* (*type_lua_touserdata)(lua_State* L, int idx);
EXTERN_EXPORT type_lua_touserdata lua_touserdata;

typedef int (*type_lua_type)(lua_State* L, int index);
EXTERN_EXPORT type_lua_type lua_type;

typedef const char* (*type_lua_typename)(lua_State* L, int tp);
EXTERN_EXPORT type_lua_typename lua_typename;

typedef int (*type_luaL_error)(lua_State* L, const char* fmt, ...);
EXTERN_EXPORT type_luaL_error luaL_error;

typedef int (*type_luaL_loadfilex)(lua_State* L, const char* fileName, const char* mode);
EXTERN_EXPORT type_luaL_loadfilex luaL_loadfilex;

typedef int (*type_luaL_loadstring)(lua_State* L, const char* s);
EXTERN_EXPORT type_luaL_loadstring luaL_loadstring;

typedef int (*type_luaL_newmetatable)(lua_State* L, const char* tname);
EXTERN_EXPORT type_luaL_newmetatable luaL_newmetatable;

typedef int (*type_luaL_ref)(lua_State* L, int t);
EXTERN_EXPORT type_luaL_ref luaL_ref;

typedef void (*type_lua_pushnumber)(lua_State* L, lua_Number n);
EXTERN_EXPORT type_lua_pushnumber lua_pushnumber;

///////////////////////
// Reimplementations //
///////////////////////

EXPORT int lua_absindex(lua_State* L, int idx);

/////////////
// Defines //
/////////////

#define lua_cast(t, exp) ((t)(exp))
#define lua_cast_int(i) lua_cast(int, (i))
#define lua_ispseudo(i) ((i) <= LUA_REGISTRYINDEX)
