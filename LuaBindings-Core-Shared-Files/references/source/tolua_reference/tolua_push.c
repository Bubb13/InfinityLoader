/* tolua: functions to push C values.
 ** Support code for Lua bindings.
 ** Written by Waldemar Celes
 ** TeCGraf/PUC-Rio
 ** Apr 2003
 ** $Id: tolua_push.c,v 1.7 2010/01/22 15:39:29 fabraham Exp $
 */

 /* This code is free software; you can redistribute it and/or modify it.
  ** The software provided hereunder is on an "as is" basis, and
  ** the author has no obligation to provide maintenance, support, updates,
  ** enhancements, or modifications.
  */

#include "tolua_reference/tolua.h"
#include "tolua_reference/lauxlib.h"

#include <stdlib.h>

TOLUA_API void tolua_pushvalue(lua_State* L, int lo)
{
	lua_pushvalue(L, lo);
}

TOLUA_API void tolua_pushboolean(lua_State* L, int value)
{
	lua_pushboolean(L, value);
}

TOLUA_API void tolua_pushnumber(lua_State* L, double value)
{
	lua_pushnumber(L, value);
}

TOLUA_API void tolua_pushstring(lua_State* L, const char* value)
{
	if (value == NULL)
		lua_pushnil(L);
	else
		lua_pushstring(L, value);
}

TOLUA_API void tolua_pushuserdata(lua_State* L, void* value)
{
	if (value == NULL)
		lua_pushnil(L);
	else
		lua_pushlightuserdata(L, value);
}

TOLUA_API void tolua_pushusertype(lua_State* L, void* value, const char* type) {
	if (value == NULL) {
		lua_pushnil(L);                                         // 1 [ nil ]
	}
	else {
		lua_pushstring(L, "tolua_ubox");                        // 1 [ "tolua_ubox" ]
		lua_rawget(L, LUA_REGISTRYINDEX);                       // 1 [ registry["tolua_ubox"] ]
		lua_pushlightuserdata(L, value);                        // 2 [ registry["tolua_ubox"], lud(value) ]
		lua_rawget(L, -2);                                      // 2 [ registry["tolua_ubox"], registry["tolua_ubox"][lud(value)] -> ubox ]
		if (lua_isnil(L, -1)) {

			///////////////////////////////////////////////
			// registry["tolua_ubox"][lud(value)] = ubox //
			// setmetatable(ubox, getmetatable(type))    //
			///////////////////////////////////////////////

			lua_pop(L, 1);                                      // 1 [ registry["tolua_ubox"] ]
			lua_pushlightuserdata(L, value);                    // 2 [ registry["tolua_ubox"], lud(value) ]
			*(void**)lua_newuserdata(L, sizeof(void*)) = value; // 3 [ registry["tolua_ubox"], lud(value), ubox ]
			lua_pushvalue(L, -1);                               // 4 [ registry["tolua_ubox"], lud(value), ubox, ubox ]
			lua_insert(L, -4);                                  // 4 [ ubox, registry["tolua_ubox"], lud(value), ubox ]
			lua_rawset(L, -3);                                  // 2 [ ubox, registry["tolua_ubox"] ]
			lua_pop(L, 1);                                      // 1 [ ubox ]
			tolua_getmetatable(L, type);                        // 2 [ ubox, getmetatable(type) ] // TODO: Metatable
			lua_setmetatable(L, -2);                            // 1 [ ubox ]
		}
		else {

			////////////////////////////////////////////////////////////////////
			// local superTable = registry["tolua_super"][getmetatable(ubox)] //
			// if type(superTable) == "table" then                            //
			//     if not superTable[type] then                               //
			//         setmetatable(ubox, getmetatable(type))                 //
			//     end                                                        //
			//     return ubox                                                //
			// end                                                            //
			////////////////////////////////////////////////////////////////////

			lua_insert(L, -2);                                  // 2 [ ubox, registry["tolua_ubox"] ]
			lua_pop(L, 1);                                      // 1 [ ubox ]
			lua_pushstring(L, "tolua_super");                   // 2 [ ubox, "tolua_super" ]
			lua_rawget(L, LUA_REGISTRYINDEX);                   // 2 [ ubox, registry["tolua_super"] ]
			lua_getmetatable(L, -2);                            // 3 [ ubox, registry["tolua_super"], getmetatable(ubox) ] // TODO: Metatable
			lua_rawget(L, -2);                                  // 3 [ ubox, registry["tolua_super"], registry["tolua_super"][getmetatable(ubox)] ]
			if (lua_istable(L, -1)) {
				lua_pushstring(L, type);                        // 4 [ ubox, registry["tolua_super"], registry["tolua_super"][getmetatable(ubox)], type ]
				lua_rawget(L, -2);                              // 4 [ ubox, registry["tolua_super"], registry["tolua_super"][getmetatable(ubox)], registry["tolua_super"][getmetatable(ubox)][type] ]
				if (lua_toboolean(L, -1) == 1) {
					lua_pop(L, 3);                              // 1 [ ubox ]
					return;
				}
			}
			// Note: Above assumes registry["tolua_super"][getmetatable(ubox)] is a table, else function breaks
			tolua_getmetatable(L, type);                        // 5 [ ubox, registry["tolua_super"], registry["tolua_super"][getmetatable(ubox)], type, getmetatable(type) ] // TODO: Metatable
			lua_setmetatable(L, -5);                            // 4 [ ubox, registry["tolua_super"], registry["tolua_super"][getmetatable(ubox)], type ]
			lua_pop(L, 3);                                      // 1 [ ubox ]
		}
	}
}

TOLUA_API void tolua_pushfieldvalue(lua_State* L, int lo, int index, int v)
{
	lua_pushnumber(L, index);
	lua_pushvalue(L, v);
	lua_settable(L, lo);
}

TOLUA_API void tolua_pushfieldboolean(lua_State* L, int lo, int index, int v)
{
	lua_pushnumber(L, index);
	lua_pushboolean(L, v);
	lua_settable(L, lo);
}


TOLUA_API void tolua_pushfieldnumber(lua_State* L, int lo, int index, double v)
{
	lua_pushnumber(L, index);
	tolua_pushnumber(L, v);
	lua_settable(L, lo);
}

TOLUA_API void tolua_pushfieldstring(lua_State* L, int lo, int index, const char* v)
{
	lua_pushnumber(L, index);
	tolua_pushstring(L, v);
	lua_settable(L, lo);
}

TOLUA_API void tolua_pushfielduserdata(lua_State* L, int lo, int index, void* v)
{
	lua_pushnumber(L, index);
	tolua_pushuserdata(L, v);
	lua_settable(L, lo);
}

TOLUA_API void tolua_pushfieldusertype(lua_State* L, int lo, int index, void* v, const char* type)
{
	lua_pushnumber(L, index);
	tolua_pushusertype(L, v, type);
	lua_settable(L, lo);
}

