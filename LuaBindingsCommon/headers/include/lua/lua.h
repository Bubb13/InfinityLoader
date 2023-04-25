
#pragma once

#include "lua/luaconf.h"
#include "dummy_lua_generated.h"

typedef LUA_NUMBER lua_Number;
typedef LUA_INTEGER lua_Integer;
typedef int (*lua_CFunction) (lua_State* L);

//#define LUA_REGISTRYINDEX LUAI_FIRSTPSEUDOIDX
#define LUA_REGISTRYINDEX (-10000)
#define LUA_GLOBALSINDEX (-10002)

#define LUA_TNONE (-1)
#define LUA_TNIL 0
#define LUA_TBOOLEAN 1
#define LUA_TLIGHTUSERDATA 2
#define LUA_TNUMBER 3
#define LUA_TSTRING 4
#define LUA_TTABLE 5
#define LUA_TFUNCTION 6
#define LUA_TUSERDATA 7
#define LUA_TTHREAD 8

#define LUA_OK 0
