
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
extern type_lua_atpanic p_lua_atpanic;

typedef void (*type_lua_callk)(lua_State* L, int nargs, int nresults, int ctx, lua_CFunction k);
extern type_lua_callk p_lua_callk;

typedef void (*type_lua_concat)(lua_State* L, int n);
extern type_lua_concat p_lua_concat;

typedef void (*type_lua_createtable)(lua_State* L, int narr, int nrec);
extern type_lua_createtable p_lua_createtable;

typedef void (*type_lua_getfield)(lua_State* L, int idx, const char* k);
extern type_lua_getfield p_lua_getfield;

typedef void (*type_lua_getglobal)(lua_State* L, const char* name);
extern type_lua_getglobal p_lua_getglobal;

typedef int (*type_lua_getmetatable)(lua_State* L, int objindex);
extern type_lua_getmetatable p_lua_getmetatable;

typedef void (*type_lua_gettable)(lua_State* L, int index);
extern type_lua_gettable p_lua_gettable;

typedef int (*type_lua_gettop)(lua_State* L);
extern type_lua_gettop p_lua_gettop;

typedef void (*type_lua_insert)(lua_State* L, int idx);
extern type_lua_insert p_lua_insert;

typedef int (*type_lua_iscfunction)(lua_State* L, int index);
extern type_lua_iscfunction p_lua_iscfunction;

typedef int (*type_lua_isnumber)(lua_State* L, int index);
extern type_lua_isnumber p_lua_isnumber;

typedef int (*type_lua_isstring)(lua_State* L, int index);
extern type_lua_isstring p_lua_isstring;

typedef int (*type_lua_isuserdata)(lua_State* L, int index);
extern type_lua_isuserdata p_lua_isuserdata;

typedef void* (*type_lua_newuserdata)(lua_State* L, size_t size);
extern type_lua_newuserdata p_lua_newuserdata;

typedef int (*type_lua_next)(lua_State* L, int index);
extern type_lua_next p_lua_next;

typedef int (*type_lua_pcallk)(lua_State* L, int nargs, int nresults, int errfunc, int ctx, lua_CFunction k);
extern type_lua_pcallk p_lua_pcallk;

typedef void (*type_lua_pushboolean)(lua_State* L, int b);
extern type_lua_pushboolean p_lua_pushboolean;

typedef void (*type_lua_pushcclosure)(lua_State* L, lua_CFunction fn, int n);
extern type_lua_pushcclosure p_lua_pushcclosure;

typedef void (*type_lua_pushinteger)(lua_State* L, lua_Integer n);
extern type_lua_pushinteger p_lua_pushinteger;

typedef void (*type_lua_pushlightuserdata)(lua_State* L, void* p);
extern type_lua_pushlightuserdata p_lua_pushlightuserdata;

typedef const char* (*type_lua_pushlstring)(lua_State* L, const char* s, size_t len);
extern type_lua_pushlstring p_lua_pushlstring;

typedef void (*type_lua_pushnil)(lua_State* L);
extern type_lua_pushnil p_lua_pushnil;

typedef void (*type_lua_pushnumber)(lua_State* L, lua_Number n);
extern type_lua_pushnumber p_lua_pushnumber;

typedef const char* (*type_lua_pushstring)(lua_State* L, const char* s);
extern type_lua_pushstring p_lua_pushstring;

typedef void (*type_lua_pushvalue)(lua_State* L, int index);
extern type_lua_pushvalue p_lua_pushvalue;

typedef int (*type_lua_rawequal)(lua_State* L, int index1, int index2);
extern type_lua_rawequal p_lua_rawequal;

typedef void (*type_lua_rawget)(lua_State* L, int index);
extern type_lua_rawget p_lua_rawget;

typedef void (*type_lua_rawgeti)(lua_State* L, int index, int n);
extern type_lua_rawgeti p_lua_rawgeti;

typedef size_t (*type_lua_rawlen)(lua_State* L, int index);
extern type_lua_rawlen p_lua_rawlen;

typedef void (*type_lua_rawset)(lua_State* L, int index);
extern type_lua_rawset p_lua_rawset;

typedef void (*type_lua_rawseti)(lua_State* L, int index, int n);
extern type_lua_rawseti p_lua_rawseti;

typedef void (*type_lua_remove)(lua_State* L, int index);
extern type_lua_remove p_lua_remove;

typedef void (*type_lua_setfield)(lua_State* L, int index, const char* k);
extern type_lua_setfield p_lua_setfield;

typedef void (*type_lua_setglobal)(lua_State* L, const char* name);
extern type_lua_setglobal p_lua_setglobal;

typedef void (*type_lua_setmetatable)(lua_State* L, int index);
extern type_lua_setmetatable p_lua_setmetatable;

typedef void (*type_lua_settable)(lua_State* L, int index);
extern type_lua_settable p_lua_settable;

typedef void (*type_lua_settop)(lua_State* L, int index);
extern type_lua_settop p_lua_settop;

typedef int (*type_lua_toboolean)(lua_State* L, int idx);
extern type_lua_toboolean p_lua_toboolean;

typedef lua_CFunction (*type_lua_tocfunction)(lua_State* L, int index);
extern type_lua_tocfunction p_lua_tocfunction;

typedef lua_Integer (*type_lua_tointegerx)(lua_State* L, int index, int* isnum);
extern type_lua_tointegerx p_lua_tointegerx;

typedef const char* (*type_lua_tolstring)(lua_State* L, int index, size_t* len);
extern type_lua_tolstring p_lua_tolstring;

typedef lua_Number (*type_lua_tonumberx)(lua_State* L, int index, int* isnum);
extern type_lua_tonumberx p_lua_tonumberx;

typedef void* (*type_lua_touserdata)(lua_State* L, int idx);
extern type_lua_touserdata p_lua_touserdata;

typedef int (*type_lua_type)(lua_State* L, int index);
extern type_lua_type p_lua_type;

typedef const char* (*type_lua_typename)(lua_State* L, int tp);
extern type_lua_typename p_lua_typename;

typedef int (*type_luaL_error)(lua_State* L, const char* fmt, ...);
extern "C" type_luaL_error p_luaL_error;

typedef int (*type_luaL_loadbufferx)(lua_State* L, const char* buff, size_t sz, const char* name, const char* mode);
extern type_luaL_loadbufferx p_luaL_loadbufferx;

typedef int (*type_luaL_loadfilex)(lua_State* L, const char* fileName, const char* mode);
extern type_luaL_loadfilex p_luaL_loadfilex;

typedef int (*type_luaL_loadstring)(lua_State* L, const char* s);
extern type_luaL_loadstring p_luaL_loadstring;

typedef int (*type_luaL_newmetatable)(lua_State* L, const char* tname);
extern type_luaL_newmetatable p_luaL_newmetatable;

typedef lua_State* (*type_luaL_newstate)();
extern type_luaL_newstate p_luaL_newstate;

typedef void (*type_luaL_openlibs)(lua_State* L);
extern type_luaL_openlibs p_luaL_openlibs;

typedef int (*type_luaL_ref)(lua_State* L, int t);
extern type_luaL_ref p_luaL_ref;

typedef void (*type_luaL_traceback)(lua_State* L, lua_State* L1, const char* msg, int level);
extern type_luaL_traceback p_luaL_traceback;

///////////////////////
// Reimplementations //
///////////////////////

EXPORT int lua_absindex(lua_State* L, int idx);
EXPORT lua_Number lua_tonumber(lua_State* L, int index);

/////////////
// Defines //
/////////////

#define lua_cast(t, exp) ((t)(exp))
#define lua_cast_int(i) lua_cast(int, (i))
#define lua_ispseudo(i) ((i) <= LUA_REGISTRYINDEX)
