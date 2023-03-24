
#pragma once

#include "lua/lua.h"

//////////////
// Pointers //
//////////////

typedef void(__cdecl* type_free)(void* memblock);
extern type_free p_free;

typedef void(__cdecl* type_lua_createtable)(lua_State* L, int narr, int nrec);
extern type_lua_createtable p_lua_createtable;

typedef void(__cdecl* type_lua_getfield)(lua_State* L, int index, const char* k);
extern type_lua_getfield p_lua_getfield;

typedef void(__cdecl* type_lua_getglobal)(lua_State* L, const char* name);
extern type_lua_getglobal p_lua_getglobal;

typedef int(__cdecl* type_lua_gettop)(lua_State* L);
extern type_lua_gettop p_lua_gettop;

typedef int(__cdecl* type_lua_pcallk)(lua_State* L, int nargs, int nresults, int errfunc, int ctx, lua_CFunction k);
extern type_lua_pcallk p_lua_pcallk;

typedef void(__cdecl* type_lua_pushcclosure)(lua_State* L, lua_CFunction fn, int n);
extern type_lua_pushcclosure p_lua_pushcclosure;

typedef void(__cdecl* type_lua_pushinteger)(lua_State* L, lua_Integer n);
extern type_lua_pushinteger p_lua_pushinteger;

typedef void(__cdecl* type_lua_pushnil)(lua_State* L);
extern type_lua_pushnil p_lua_pushnil;

typedef const char* (__cdecl* type_lua_pushstring)(lua_State* L, const char* s);
extern type_lua_pushstring p_lua_pushstring;

typedef void(__cdecl* type_lua_pushvalue)(lua_State* L, int index);
extern type_lua_pushvalue p_lua_pushvalue;

typedef void(__cdecl* type_lua_rawgeti)(lua_State* L, int index, int n);
extern type_lua_rawgeti p_lua_rawgeti;

typedef void(__cdecl* type_lua_rawset)(lua_State* L, int index);
extern type_lua_rawset p_lua_rawset;

typedef void(__cdecl* type_lua_rawseti)(lua_State* L, int index, int n);
extern type_lua_rawseti p_lua_rawseti;

typedef void(__cdecl* type_lua_setglobal)(lua_State* L, const char* name);
extern type_lua_setglobal p_lua_setglobal;

typedef void(__cdecl* type_lua_settop)(lua_State* L, int index);
extern type_lua_settop p_lua_settop;

typedef int(__cdecl* type_lua_toboolean)(lua_State* L, int index);
extern type_lua_toboolean p_lua_toboolean;

typedef lua_Integer(__cdecl* type_lua_tointegerx)(lua_State* L, int index, int* isnum);
extern type_lua_tointegerx p_lua_tointegerx;

typedef const char* (__cdecl* type_lua_tolstring)(lua_State* L, int index, size_t* len);
extern type_lua_tolstring p_lua_tolstring;

typedef int(__cdecl* type_lua_type)(lua_State* L, int index);
extern type_lua_type p_lua_type;

typedef int(__cdecl* type_luaL_error)(lua_State* L, const char* fmt, ...);
extern type_luaL_error p_luaL_error;

typedef int(__cdecl* type_luaL_loadfilex)(lua_State* L, const char* fileName, const char* mode);
extern type_luaL_loadfilex p_luaL_loadfilex;

typedef int(__cdecl* type_luaL_ref)(lua_State* L, int t);
extern type_luaL_ref p_luaL_ref;

typedef void* (__cdecl* type_malloc)(size_t size);
extern type_malloc p_malloc;

#define p_lua_newtable(L) p_lua_createtable(L, 0, 0)
#define p_lua_pop(L, n) p_lua_settop(L, -(n) - 1)
#define p_lua_tointeger(L, i) p_lua_tointegerx(L, (i), NULL)
#define p_lua_tostring(L, i) p_lua_tolstring(L, (i), nullptr)
