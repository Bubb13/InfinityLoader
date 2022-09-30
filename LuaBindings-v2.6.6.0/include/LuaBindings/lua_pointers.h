
#pragma once

#include "lua.h"

//////////////
// Pointers //
//////////////

typedef void type_lua_callk(lua_State* L, int nargs, int nresults, int ctx, lua_CFunction k);
extern type_lua_callk* p_lua_callk;

typedef void type_lua_createtable(lua_State* L, int narr, int nrec);
extern type_lua_createtable* p_lua_createtable;

typedef void type_lua_getfield(lua_State* L, int idx, const char* k);
extern type_lua_getfield* p_lua_getfield;

typedef void type_lua_getglobal(lua_State* L, const char* name);
extern type_lua_getglobal* p_lua_getglobal;

typedef int type_lua_getmetatable(lua_State* L, int objindex);
extern type_lua_getmetatable* p_lua_getmetatable;

typedef void type_lua_gettable(lua_State* L, int index);
extern type_lua_gettable* p_lua_gettable;

typedef int type_lua_gettop(lua_State* L);
extern type_lua_gettop* p_lua_gettop;

typedef void type_lua_insert(lua_State* L, int idx);
extern type_lua_insert* p_lua_insert;

typedef int type_lua_iscfunction(lua_State* L, int index);
extern type_lua_iscfunction* p_lua_iscfunction;

typedef int type_lua_isnumber(lua_State* L, int index);
extern type_lua_isnumber* p_lua_isnumber;

typedef int type_lua_isuserdata(lua_State* L, int index);
extern type_lua_isuserdata* p_lua_isuserdata;

typedef void* type_lua_newuserdata(lua_State* L, size_t size);
extern type_lua_newuserdata* p_lua_newuserdata;

typedef int type_lua_next(lua_State* L, int index);
extern type_lua_next* p_lua_next;

typedef int type_lua_pcallk(lua_State* L, int nargs, int nresults, int errfunc, int ctx, lua_CFunction k);
extern type_lua_pcallk* p_lua_pcallk;

typedef void type_lua_pushboolean(lua_State* L, int b);
extern type_lua_pushboolean* p_lua_pushboolean;

typedef void type_lua_pushcclosure(lua_State* L, lua_CFunction fn, int n);
extern type_lua_pushcclosure* p_lua_pushcclosure;

typedef void type_lua_pushinteger(lua_State* L, lua_Integer n);
extern type_lua_pushinteger* p_lua_pushinteger;

typedef void type_lua_pushlightuserdata(lua_State* L, void* p);
extern type_lua_pushlightuserdata* p_lua_pushlightuserdata;

typedef const char* type_lua_pushlstring(lua_State* L, const char* s, size_t len);
extern type_lua_pushlstring* p_lua_pushlstring;

typedef void type_lua_pushnil(lua_State* L);
extern type_lua_pushnil* p_lua_pushnil;

typedef const char* type_lua_pushstring(lua_State* L, const char* s);
extern type_lua_pushstring* p_lua_pushstring;

typedef void type_lua_pushvalue(lua_State* L, int index);
extern type_lua_pushvalue* p_lua_pushvalue;

typedef void type_lua_rawget(lua_State* L, int index);
extern type_lua_rawget* p_lua_rawget;

typedef void type_lua_rawgeti(lua_State* L, int index, int n);
extern type_lua_rawgeti* p_lua_rawgeti;

typedef void type_lua_rawset(lua_State* L, int index);
extern type_lua_rawset* p_lua_rawset;

typedef void type_lua_rawseti(lua_State* L, int index, int n);
extern type_lua_rawseti* p_lua_rawseti;

typedef void type_lua_remove(lua_State* L, int index);
extern type_lua_remove* p_lua_remove;

typedef void type_lua_setglobal(lua_State* L, const char* name);
extern type_lua_setglobal* p_lua_setglobal;

typedef void type_lua_setmetatable(lua_State* L, int index);
extern type_lua_setmetatable* p_lua_setmetatable;

typedef void type_lua_settable(lua_State* L, int index);
extern type_lua_settable* p_lua_settable;

typedef void type_lua_settop(lua_State* L, int index);
extern type_lua_settop* p_lua_settop;

typedef int type_lua_toboolean(lua_State* L, int idx);
extern type_lua_toboolean* p_lua_toboolean;

typedef lua_CFunction type_lua_tocfunction(lua_State* L, int index);
extern type_lua_tocfunction* p_lua_tocfunction;

typedef lua_Integer type_lua_tointegerx(lua_State* L, int index, int* isnum);
extern type_lua_tointegerx* p_lua_tointegerx;

typedef const char* type_lua_tolstring(lua_State* L, int index, size_t* len);
extern type_lua_tolstring* p_lua_tolstring;

typedef lua_Number type_lua_tonumberx(lua_State* L, int index, int* isnum);
extern type_lua_tonumberx* p_lua_tonumberx;

typedef void* type_lua_touserdata(lua_State* L, int idx);
extern type_lua_touserdata* p_lua_touserdata;

typedef int type_lua_type(lua_State* L, int index);
extern type_lua_type* p_lua_type;

typedef int type_luaL_error (lua_State* L, const char* fmt, ...);
extern type_luaL_error* p_luaL_error;

typedef int type_luaL_loadfilex(lua_State* L, const char* fileName, const char* mode);
extern type_luaL_loadfilex* p_luaL_loadfilex;

typedef int type_luaL_loadstring(lua_State* L, const char* s);
extern type_luaL_loadstring* p_luaL_loadstring;

///////////////////////
// Reimplementations //
///////////////////////

extern int p_lua_absindex(lua_State* L, int idx);

/////////////
// Defines //
/////////////

#define p_lua_call(L, n, r) p_lua_callk(L, (n), (r), 0, NULL)
#define p_lua_cast(t, exp) ((t)(exp))
#define p_lua_cast_int(i) p_lua_cast(int, (i))
#define p_lua_isboolean(L, n) (p_lua_type(L, (n)) == LUA_TBOOLEAN)
#define p_lua_isfunction(L, n) (p_lua_type(L, (n)) == LUA_TFUNCTION)
#define p_lua_isnil(L, n) (p_lua_type(L, (n)) == LUA_TNIL)
#define p_lua_ispseudo(i) ((i) <= LUA_REGISTRYINDEX)
#define p_lua_istable(L, n) (p_lua_type(L, (n)) == LUA_TTABLE)
#define p_lua_newtable(L) p_lua_createtable(L, 0, 0)
#define p_lua_pop(L, n) p_lua_settop(L, -(n) - 1)
#define p_lua_pushcfunction(L, f) p_lua_pushcclosure(L, (f), 0)
#define p_lua_tointeger(L, i) p_lua_tointegerx(L, (i), NULL)
#define p_lua_tonumber(L,i) p_lua_tonumberx(L, i, NULL)
#define p_lua_tostring(L, i) p_lua_tolstring(L, (i), NULL)
#define p_luaL_getmetatable(L,n) (p_lua_getfield(L, LUA_REGISTRYINDEX, (n)))
