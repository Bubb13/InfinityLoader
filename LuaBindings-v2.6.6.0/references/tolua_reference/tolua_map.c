/* tolua: functions to map features
 ** Support code for Lua bindings.
 ** Written by Waldemar Celes
 ** TeCGraf/PUC-Rio
 ** Apr 2003
 ** $Id: tolua_map.c,v 1.10 2011/01/13 13:43:46 fabraham Exp $
 */

 /* This code is free software; you can redistribute it and/or modify it.
  ** The software provided hereunder is on an "as is" basis, and
  ** the author has no obligation to provide maintenance, support, updates,
  ** enhancements, or modifications.
  */

#include "tolua_reference/tolua.h"
#include "tolua_reference/tolua_event.h"
#include "tolua_reference/lauxlib.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


static char toluaname[128] = "tolua.";
static const char* TOLUANAME(const char* n) {
	sprintf(&toluaname[6], "%.120s", n);
	return toluaname;
}

// Creates new metatable in the registry under "tolua.<name>"
// and adds reverse metatable => <name> mapping in registry
void tolua_newmetatable(lua_State* L, const char* name) {
	if (luaL_newmetatable(L, TOLUANAME(name))) { // [ metatable(name) ]
		lua_pushvalue(L, -1);                    // [ metatable(name), metatable(name) ]
		lua_pushstring(L, name);                 // [ metatable(name), metatable(name), name ]
		lua_rawset(L, LUA_REGISTRYINDEX);        // [ metatable(name) ]
	}

	tolua_classevents(L);
	lua_pop(L, 1);                               // [ ]
}

// Get metatable from registry under "tolua.<name>"
void tolua_getmetatable(lua_State* L, const char* name) {
	luaL_getmetatable(L, TOLUANAME(name));
}

static void mapsuper(lua_State* L, const char* name, const char* base) {

	////////////////////////////////////////////////////////////////////
	// registry["tolua_super"][tolua_getmetatable(name)][base] = true //
	////////////////////////////////////////////////////////////////////

	lua_pushstring(L, "tolua_super"); // 1 [ "tolua_super" ]
	lua_rawget(L, LUA_REGISTRYINDEX); // 1 [ registry["tolua_super"] ]
	tolua_getmetatable(L, name);      // 2 [ registry["tolua_super"], tolua_getmetatable(name) ] // TODO: Metatable
	lua_rawget(L, -2);                // 2 [ registry["tolua_super"], registry["tolua_super"][tolua_getmetatable(name)] ]
	if (lua_isnil(L, -1)) {
		lua_pop(L, 1);                // 1 [ registry["tolua_super"] ]
		lua_newtable(L);              // 2 [ registry["tolua_super"], newtable ]
		tolua_getmetatable(L, name);  // 3 [ registry["tolua_super"], newtable, tolua_getmetatable(name) ] // TODO: Metatable
		lua_pushvalue(L, -2);         // 4 [ registry["tolua_super"], newtable, tolua_getmetatable(name), newtable ]
		lua_rawset(L, -4);            // 2 [ registry["tolua_super"], newtable ]
	}
	                                  // 2 [ registry["tolua_super"], registry["tolua_super"][tolua_getmetatable(name)] ]
	lua_pushstring(L, base);          // 3 [ registry["tolua_super"], registry["tolua_super"][tolua_getmetatable(name)], base ]
	lua_pushboolean(L, 1);            // 4 [ registry["tolua_super"], registry["tolua_super"][tolua_getmetatable(name)], base, true ]
	lua_rawset(L, -3);                // 2 [ registry["tolua_super"], registry["tolua_super"][tolua_getmetatable(name)] ]

	//////////////////////////////////////////////////////////////////////
	// local t = registry["tolua_super"][tolua_getmetatable(base)]      //
	// if type(t) == "table" then                                       //
	//     for k, v in pairs(t) do                                      //
	//         registry["tolua_super"][tolua_getmetatable(name)][k] = v //
	//     end                                                          //
	// end                                                              //
	//////////////////////////////////////////////////////////////////////

	tolua_getmetatable(L, base); // 3 [ registry["tolua_super"], registry["tolua_super"][tolua_getmetatable(name)], tolua_getmetatable(base) ] // TODO: Metatable
	lua_rawget(L, -3);               // 3 [ registry["tolua_super"], registry["tolua_super"][tolua_getmetatable(name)], registry["tolua_super"][tolua_getmetatable(base)] ]
	if (lua_istable(L, -1)) {
		lua_pushnil(L);              // 4 [ registry["tolua_super"], registry["tolua_super"][tolua_getmetatable(name)], registry["tolua_super"][tolua_getmetatable(base)], nil ]
		while (lua_next(L, -2) != 0) {
			                         // 5 [ registry["tolua_super"], registry["tolua_super"][tolua_getmetatable(name)], registry["tolua_super"][tolua_getmetatable(base)], k, v ]
			lua_pushvalue(L, -2);    // 6 [ registry["tolua_super"], registry["tolua_super"][tolua_getmetatable(name)], registry["tolua_super"][tolua_getmetatable(base)], k, v, k ]
			lua_insert(L, -2);       // 6 [ registry["tolua_super"], registry["tolua_super"][tolua_getmetatable(name)], registry["tolua_super"][tolua_getmetatable(base)], k, k, v ]
			lua_rawset(L, -5);       // 4 [ registry["tolua_super"], registry["tolua_super"][tolua_getmetatable(name)], registry["tolua_super"][tolua_getmetatable(base)], k]
		}
		                             // 3 [ registry["tolua_super"], registry["tolua_super"][tolua_getmetatable(name)], registry["tolua_super"][tolua_getmetatable(base)] ]
	}
	lua_pop(L, 3);                   // 0 [ ]
}

static void mapinheritance(lua_State* L, const char* name, const char* base) {

	/////////////////////////////////////////////////////////////////////////////////
	// setmetatable(getmetatable(name), getmetatable(base or "tolua_commonclass")) //
	/////////////////////////////////////////////////////////////////////////////////

	tolua_getmetatable(L, name);                        // 1 [ tolua_getmetatable(name) ] // TODO: Metatable
	if (base && *base) {
		tolua_getmetatable(L, base);                // 2 [ tolua_getmetatable(name), tolua_getmetatable(base) ] // TODO: Metatable
	}
	else {
		tolua_getmetatable(L, "tolua_commonclass"); // 2 [ tolua_getmetatable(name), tolua_getmetatable("tolua_commonclass") ] // TODO: Metatable
	}
	lua_setmetatable(L, -2);                            // 1 [ tolua_getmetatable(name) ]
	lua_pop(L, 1);                                      // 0 [ ]
}

/* Object type
 */
static int tolua_bnd_type(lua_State* L)
{
	tolua_typename(L, lua_gettop(L));
	return 1;
}

int tolua_bnd_takeownership(lua_State* L) {
	lua_CFunction func = 0;
	if (lua_isuserdata(L, 1)) {
		if (lua_getmetatable(L, 1)) { // TODO: Metatable
			void* u;
			lua_pushstring(L, ".collector");
			lua_rawget(L, -2);
			func = lua_iscfunction(L, -1) ? lua_tocfunction(L, -1) : NULL;
			lua_pop(L, 2);
			u = *((void**)lua_touserdata(L, 1));
			tolua_clone(L, u, func);
		}
	}
	lua_pushboolean(L, func != 0);
	return 1;
}

/* Release ownership
 */
static int tolua_bnd_releaseownership(lua_State* L)
{
	int done = 0;
	if (lua_isuserdata(L, 1))
	{
		void* u = *((void**)lua_touserdata(L, 1));
		lua_pushstring(L, "tolua_gc");
		lua_rawget(L, LUA_REGISTRYINDEX);
		lua_pushlightuserdata(L, u);
		lua_rawget(L, -2);
		lua_pushlightuserdata(L, u);
		lua_pushnil(L);
		lua_rawset(L, -4);
		done = 1;
	}
	lua_pushboolean(L, done != 0);
	return 1;
}

static int tolua_bnd_cast(lua_State* L) {
	void* v = tolua_tousertype(L, 1, NULL);
	const char* s = tolua_tostring(L, 2, NULL);
	if (!v) {
		lua_pushnil(L);
	}
	else if (v && s) {
		tolua_getmetatable(L, s); // TODO: Metatable
		if (lua_isnil(L, -1)) {
			tolua_error(L, "Unknown 'type' for 'tolua.cast' function", NULL);
		}
		tolua_pushusertype(L, v, s);
	}
	else {
		tolua_error(L, "Invalid arguments for 'tolua.cast' function", NULL);
	}
	return 1;
}

/* Release
** Function to be called by a Lua code that uses a function to explicitly
** release a mapped object. This function is automatically called by all
** destructors bound by tolua and by all collected objects.
*/
static int tolua_bnd_release(lua_State* L)
{
	void* value = tolua_tousertype(L, 1, NULL);
	if (value)
		tolua_release(L, value);
	return 1;
}

/*
** Function to return peer table associated to a given object
*/
static int tolua_bnd_getpeertable(lua_State* L)
{
	lua_pushstring(L, "tolua_peer");
	lua_rawget(L, LUA_REGISTRYINDEX);        /* stack: k v peer */
	lua_pushvalue(L, 1);
	lua_rawget(L, -2);                       /* stack: k v peer peer[u] */
	if (!lua_istable(L, -1))
	{
		lua_pop(L, 1);                          /* stack: k v peer */
		lua_newtable(L);                       /* stack: k v peer table */
		lua_pushvalue(L, 1);
		lua_pushvalue(L, -2);                   /* stack: k v peer table u table */
		lua_rawset(L, -4);                      /* stack: k v peer peer[u]=table */
	}
	return 1;
}

static void tolua_push_globals_table(lua_State* L)
{
#if defined (LUA_VERSION_NUM) && LUA_VERSION_NUM >= 502 /* after lua 5.2 */
	lua_pushvalue(L, LUA_REGISTRYINDEX); /* registry */
	lua_pushnumber(L, LUA_RIDX_GLOBALS); /* registry globalsindex */
	lua_rawget(L, -2);                  /* registry registry[globalsindex] */
	lua_remove(L, -2);                  /* registry[globalsindex] */
#else
	lua_pushvalue(L, LUA_GLOBALSINDEX);
#endif
}

TOLUA_API void tolua_open(lua_State* L) {
	int top = lua_gettop(L);
	lua_pushstring(L, "tolua_opened");     // [ "tolua_opened" ]
	lua_rawget(L, LUA_REGISTRYINDEX);      // [ registry["tolua_opened"] ]
	if (!lua_isboolean(L, -1)) {

		lua_pushstring(L, "tolua_opened"); // [ registry["tolua_opened"], "tolua_opened" ]
		lua_pushboolean(L, 1);             // [ registry["tolua_opened"], "tolua_opened", true ]
		lua_rawset(L, LUA_REGISTRYINDEX);  // [ registry["tolua_opened"] ]

		lua_pushstring(L, "tolua_ubox");   // [ registry["tolua_opened"], "tolua_ubox" ]
		lua_newtable(L);                   // [ registry["tolua_opened"], "tolua_ubox", newT ]
		lua_pushvalue(L, -1);              // [ registry["tolua_opened"], "tolua_ubox", newT, newT ]
		lua_pushstring(L, "__mode");       // [ registry["tolua_opened"], "tolua_ubox", newT, newT, "__mode" ]
		lua_pushstring(L, "v");            // [ registry["tolua_opened"], "tolua_ubox", newT, newT, "__mode", "v" ]
		lua_rawset(L, -3);                 // [ registry["tolua_opened"], "tolua_ubox", newT, newT ]
		lua_setmetatable(L, -2);           // [ registry["tolua_opened"], "tolua_ubox", newT ]
		lua_rawset(L, LUA_REGISTRYINDEX);  // [ registry["tolua_opened"] ]

		lua_pushstring(L, "tolua_peer");   // [ registry["tolua_opened"], "tolua_peer" ]
		lua_newtable(L);                   // [ registry["tolua_opened"], "tolua_peer", newT ]
		lua_pushvalue(L, -1);              // [ registry["tolua_opened"], "tolua_peer", newT, newT ]
		lua_pushstring(L, "__mode");       // [ registry["tolua_opened"], "tolua_peer", newT, newT, "__mode" ]
		lua_pushstring(L, "k");            // [ registry["tolua_opened"], "tolua_peer", newT, newT, "__mode", "k" ]
		lua_rawset(L, -3);                 // [ registry["tolua_opened"], "tolua_peer", newT, newT ]
		lua_setmetatable(L, -2);           // [ registry["tolua_opened"], "tolua_peer", newT ]
		lua_rawset(L, LUA_REGISTRYINDEX);  // [ registry["tolua_opened"] ]

		lua_pushstring(L, "tolua_super");  // [ registry["tolua_opened"], "tolua_super" ]
		lua_newtable(L);                   // [ registry["tolua_opened"], "tolua_super", newT ]
		lua_rawset(L, LUA_REGISTRYINDEX);  // [ registry["tolua_opened"] ]

		lua_pushstring(L, "tolua_gc");     // [ registry["tolua_opened"], "tolua_gc" ]
		lua_newtable(L);                   // [ registry["tolua_gc"], "tolua_gc", newT ]
		lua_rawset(L, LUA_REGISTRYINDEX);  // [ registry["tolua_gc"] ]

		tolua_newmetatable(L, "tolua_commonclass");

		tolua_module(L, NULL, 0);
		tolua_beginmodule(L, NULL);
		tolua_module(L, "tolua", 0);
		tolua_beginmodule(L, "tolua");
		tolua_function(L, "type", tolua_bnd_type);
		tolua_function(L, "takeownership", tolua_bnd_takeownership);
		tolua_function(L, "releaseownership", tolua_bnd_releaseownership);
		tolua_function(L, "cast", tolua_bnd_cast);
		tolua_function(L, "release", tolua_bnd_release);
		tolua_function(L, "getpeertable", tolua_bnd_getpeertable);
		tolua_endmodule(L);
		tolua_endmodule(L);
	}
	lua_settop(L, top);
}

TOLUA_API void* tolua_copy(lua_State* L, void* value, unsigned int size) {
	void* clone = (void*)malloc(size);
	if (clone) {
		memcpy(clone, value, size);
	}
	else {
		tolua_error(L, "insuficient memory", NULL);
	}
	return clone;
}

// Deletes the ubox associated with value
TOLUA_API void tolua_release(lua_State* L, void* value) {

	//////////////////////////////////////////////
	// tolua_ubox = registry["tolua_ubox"]      //
	// local valLUD = lud(value)                //
	// local ubox = ud2ubox(tolua_ubox[valLUD]) //
	// if ubox ~= nullptr then                  //
	//     *ubox = nullptr                      //
	// end                                      //
	// tolua_ubox[valLUD] = nil                 //
	//////////////////////////////////////////////

	void** p;
	lua_pushstring(L, "tolua_ubox");  // 1 [ "tolua_ubox" ]
	lua_rawget(L, LUA_REGISTRYINDEX); // 1 [ registry["tolua_ubox"] ]
	lua_pushlightuserdata(L, value);  // 2 [ registry["tolua_ubox"], lud(value) ]
	lua_rawget(L, -2);                // 2 [ registry["tolua_ubox"], registry["tolua_ubox"][lud(value)] ]
	p = (void**)lua_touserdata(L, -1);
	if (p) *p = NULL;
	lua_pop(L, 1);                    // 1 [ registry["tolua_ubox"] ]
	lua_pushlightuserdata(L, value);  // 2 [ registry["tolua_ubox"], lud(value) ]
	lua_pushnil(L);                   // 3 [ registry["tolua_ubox"], lud(value), nil ]
	lua_rawset(L, -3);                // 1 [ registry["tolua_ubox"] ]
	lua_pop(L, 1);                    // 0 [ ]
}

TOLUA_API void* tolua_clone(lua_State* L, void* value, lua_CFunction func) {

	/////////////////////////////////////////////
	// registry["tolua_gc"][lud(value)] = func //
	/////////////////////////////////////////////

	lua_pushstring(L, "tolua_gc");    // 1 [ "tolua_gc" ]
	lua_rawget(L, LUA_REGISTRYINDEX); // 1 [ registry["tolua_gc"] ]
	lua_pushlightuserdata(L, value);  // 2 [ registry["tolua_gc"], lud(value) ]
	lua_pushcfunction(L, func);       // 3 [ registry["tolua_gc"], lud(value), func ]
	lua_rawset(L, -3);                // 1 [ registry["tolua_gc"] ]
	lua_pop(L, 1);                    // 0 [ ]
	return value;
}

TOLUA_API void tolua_usertype(lua_State* L, const char* type)
{
	char ctype[128] = "const ";
	strncat(ctype, type, 120);

	tolua_newmetatable(L, ctype);
	tolua_newmetatable(L, type);

	mapsuper(L, type, ctype);
}

// Expects [ module ]
TOLUA_API void tolua_beginmodule(lua_State* L, const char* name) {
	if (name) {
		lua_pushstring(L, name);     // [ module, name ]
		lua_rawget(L, -2);           // [ module[name] ]
	}
	else {
		tolua_push_globals_table(L); // [ module, _G ]
	}
}

/* End module
 * It pops the module (or class) from the stack
 */
TOLUA_API void tolua_endmodule(lua_State* L)
{
	lua_pop(L, 1);
}

// [ table ]
#if 1
TOLUA_API void tolua_module(lua_State* L, const char* name, int hasvar) {
	if (name) {
		lua_pushstring(L, name);         // [ table, name ]
		lua_rawget(L, -2);               // [ table, table[name] -> module ]
		if (!lua_istable(L, -1)) {
			lua_pop(L, 1);               // [ table ]
			lua_newtable(L);             // [ table, newT ]
			lua_pushstring(L, name);     // [ table, newT, name ]
			lua_pushvalue(L, -2);        // [ table, newT, name, newT ]
			lua_rawset(L, -4);           // [ table, newT -> module ]
		}
	}
	else {
		tolua_push_globals_table(L);
	}

	if (hasvar) {
		if (!tolua_ismodulemetatable(L)) {
			lua_newtable(L);             // [ table, module, newMT ]
			tolua_moduleevents(L);
			if (lua_getmetatable(L, -2)) { // TODO: Metatable
				                         // [ table, module, newMT, mt(module) ]
				lua_setmetatable(L, -2); // [ table, module, newMT ]
			}
			lua_setmetatable(L, -2);     // [ table, module ]
		}
	}
	lua_pop(L, 1);                       // [ table ]
}
#else
TOLUA_API void tolua_module(lua_State* L, const char* name, int hasvar)
{
	if (name)
	{
		/* tolua module */
		lua_pushstring(L, name);
		lua_newtable(L);
	}
	else
		tolua_push_globals_table(L);
	if (hasvar)
	{
		/* create metatable to get/set C/C++ variable */
		lua_newtable(L);
		tolua_moduleevents(L);
		if (lua_getmetatable(L, -2)) // TODO: Metatable
			lua_setmetatable(L, -2);  /* set old metatable as metatable of metatable */
		lua_setmetatable(L, -2);
	}
	if (name)
		lua_rawset(L, -3);       /* assing module into module */
	else
		lua_pop(L, 1);           /* pop global table */
}
#endif

// Expects [ module ]
TOLUA_API void tolua_cclass(lua_State* L, const char* lname, const char* name, const char* base, lua_CFunction col) {
	char cname[128] = "const ";
	char cbase[128] = "const ";
	strncat(cname, name, 120);
	strncat(cbase, base, 120);

	mapinheritance(L, name, base);
	mapinheritance(L, cname, name);

	mapsuper(L, cname, cbase);
	mapsuper(L, name, base);

	/////////////////////////////////////////
	// metatable(name)[".collector"] = col //
	// module[lname] = metatable(name)     //
	/////////////////////////////////////////

	lua_pushstring(L, lname);        // [ module, lname ]
	tolua_getmetatable(L, name);     // [ module, lname, metatable(name) ] // TODO: Metatable
	lua_pushstring(L, ".collector"); // [ module, lname, metatable(name), ".collector" ]
	lua_pushcfunction(L, col);       // [ module, lname, metatable(name), ".collector", col ]
	lua_rawset(L, -3);               // [ module, lname, metatable(name) ]
	lua_rawset(L, -3);               // [ module ]
}

/* Map function
 * It assigns a function into the current module (or class)
 */
TOLUA_API void tolua_function(lua_State* L, const char* name, lua_CFunction func)
{
	lua_pushstring(L, name);
	lua_pushcfunction(L, func);
	lua_rawset(L, -3);
}

/* Map constant number
 * It assigns a constant number into the current module (or class)
 */
TOLUA_API void tolua_constant(lua_State* L, const char* name, double value)
{
	lua_pushstring(L, name);
	tolua_pushnumber(L, value);
	lua_rawset(L, -3);
}


/* Map variable
 * It assigns a variable into the current module (or class)
 */
TOLUA_API void tolua_variable(lua_State* L, const char* name, lua_CFunction get, lua_CFunction set)
{
	/* get func */
	lua_pushstring(L, ".get");
	lua_rawget(L, -2);
	if (!lua_istable(L, -1))
	{
		/* create .get table, leaving it at the top */
		lua_pop(L, 1);
		lua_newtable(L);
		lua_pushstring(L, ".get");
		lua_pushvalue(L, -2);
		lua_rawset(L, -4);
	}
	lua_pushstring(L, name);
	lua_pushcfunction(L, get);
	lua_rawset(L, -3);                  /* store variable */
	lua_pop(L, 1);                      /* pop .get table */

	/* set func */
	if (set)
	{
		lua_pushstring(L, ".set");
		lua_rawget(L, -2);
		if (!lua_istable(L, -1))
		{
			/* create .set table, leaving it at the top */
			lua_pop(L, 1);
			lua_newtable(L);
			lua_pushstring(L, ".set");
			lua_pushvalue(L, -2);
			lua_rawset(L, -4);
		}
		lua_pushstring(L, name);
		lua_pushcfunction(L, set);
		lua_rawset(L, -3);                  /* store variable */
		lua_pop(L, 1);                      /* pop .set table */
	}
}

/* Access const array
 * It reports an error when trying to write into a const array
 */
static int const_array(lua_State* L)
{
	luaL_error(L, "value of const array cannot be changed");
	return 0;
}

/* Map an array
 * It assigns an array into the current module (or class)
 */
TOLUA_API void tolua_array(lua_State* L, const char* name, lua_CFunction get, lua_CFunction set)
{
	lua_pushstring(L, ".get");
	lua_rawget(L, -2);
	if (!lua_istable(L, -1))
	{
		/* create .get table, leaving it at the top */
		lua_pop(L, 1);
		lua_newtable(L);
		lua_pushstring(L, ".get");
		lua_pushvalue(L, -2);
		lua_rawset(L, -4);
	}
	lua_pushstring(L, name);

	lua_newtable(L);           /* create array metatable */
	lua_pushvalue(L, -1);
	lua_setmetatable(L, -2);    /* set the own table as metatable (for modules) */
	lua_pushstring(L, "__index");
	lua_pushcfunction(L, get);
	lua_rawset(L, -3);
	lua_pushstring(L, "__newindex");
	lua_pushcfunction(L, set ? set : const_array);
	lua_rawset(L, -3);

	lua_rawset(L, -3);                  /* store variable */
	lua_pop(L, 1);                      /* pop .get table */
}

