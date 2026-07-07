/* tolua: event functions
** Support code for Lua bindings.
** Written by Waldemar Celes
** TeCGraf/PUC-Rio
** Apr 2003
** $Id: tolua_event.c,v 1.7 2011/01/13 13:43:46 fabraham Exp $
*/

/* This code is free software; you can redistribute it and/or modify it.
** The software provided hereunder is on an "as is" basis, and
** the author has no obligation to provide maintenance, support, updates,
** enhancements, or modifications.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tolua_reference/tolua.h"

// Expects   [ ..., key, value ]
// End Stack [ ... ]
static void storeatpeer(lua_State* L, int index) {

	///////////////////////////////////////////////////////////////////
	// local peer = registry["tolua_peer"]                           //
	// local atTable = stack[index]                                  //
	// local dest = peer[atTable]                                    //
	// if type(dest) ~= "table" then                                 //
	//     dest = {}                                                 //
	//     peer[atTable] = dest                                      //
	// end                                                           //
	// dest[key] = value                                             //
	///////////////////////////////////////////////////////////////////

	lua_pushstring(L, "tolua_peer");  // 3 [ key, value, "tolua_peer" ]
	lua_rawget(L, LUA_REGISTRYINDEX); // 3 [ key, value, registry["tolua_peer"] ]
	lua_pushvalue(L, index);          // 4 [ key, value, registry["tolua_peer"], stack[index] ]
	lua_rawget(L, -2);                // 4 [ key, value, registry["tolua_peer"], registry["tolua_peer"][stack[index]] -> dest ]
	if (!lua_istable(L, -1)) {

		///////////////////////////////////////////////////////
		// registry["tolua_peer"][stack[index]] = {} -> dest //
		///////////////////////////////////////////////////////

		lua_pop(L, 1);                // 3 [ key, value, registry["tolua_peer"] ]
		lua_newtable(L);              // 4 [ key, value, registry["tolua_peer"], newtable ]
		lua_pushvalue(L, index);      // 5 [ key, value, registry["tolua_peer"], newtable, stack[index] ]
		lua_pushvalue(L, -2);         // 6 [ key, value, registry["tolua_peer"], newtable, stack[index], newtable ]
		lua_settable(L, -4);          // 4 [ key, value, registry["tolua_peer"], newtable -> dest ]
	}

	///////////////////////
	// dest[key] = value //
	///////////////////////

	lua_insert(L, -4);                // 4 [ dest, key, value, registry["tolua_peer"] ]
	lua_pop(L, 1);                    // 3 [ dest, key, value ]
	lua_rawset(L, -3);                // 1 [ dest ]
	lua_pop(L, 1);                    // 0 [ ]
}

// Expects   [ table, key ]
// End Stack [ table, key, table[".get"], ..., retVal ]
// Returns   1
static int module_index_event(lua_State* L) {

	///////////////////////////////////////////
	// local getT = table[".get"]            //
	// if type(getT) == "table" then         //
	//     local getV = getT[key]            //
	//     if type(getV) == "cfunction" then //
	//         return getV()                 //
	//     elseif type(getV) == "table" then //
	//         return getV                   //
	//     end                               //
	// end                                   //
	///////////////////////////////////////////

	lua_pushstring(L, ".get");        // 3 [ table, key, ".get" ]
	lua_rawget(L, -3);                // 3 [ table, key, table[".get"] ]
	if (lua_istable(L, -1)) {
		lua_pushvalue(L, 2);          // 4 [ table, key, table[".get"], key ]
		lua_rawget(L, -2);            // 4 [ table, key, table[".get"], table[".get"][key] ]
		if (lua_iscfunction(L, -1)) {
			lua_call(L, 0, 1);        // 3 [ table, key, table[".get"], retVal ]
			return 1;
		}
		else if (lua_istable(L, -1)) {
			return 1;
		}
	}

	/////////////////////////////////////////////////
	// local mt = getmetatable(table)              //
	// if mt then                                  //
	//     local mtIndex = mt["__index"][key]      //
	//     if type(key) == "function" then         //
	//         return mtIndex(table, key)          //
	//     elseif type(key) == "table" then        //
	//         return mtIndex[key]                 //
	//     end                                     //
	// end                                         //
	/////////////////////////////////////////////////

	// Note: Below lua_isfunction() and lua_istable() using wrong index?

									  // 3 [ table, key, table[".get"], ... ]
	if (lua_getmetatable(L, 1)) {     // TODO: Metatable
									  // 4 [ table, key, table[".get"], ..., mt(table) ]
		lua_pushstring(L, "__index"); // 5 [ table, key, table[".get"], ..., mt(table), "__index" ]
		lua_rawget(L, -2);            // 5 [ table, key, table[".get"], ..., mt(table), mt(table)["__index"] ]
		lua_pushvalue(L, 1);          // 6 [ table, key, table[".get"], ..., mt(table), mt(table)["__index"], table ]
		lua_pushvalue(L, 2);          // 7 [ table, key, table[".get"], ..., mt(table), mt(table)["__index"], table, key ]
		if (lua_isfunction(L, -1)) {
			lua_call(L, 2, 1);        // 5 [ table, key, table[".get"], ..., mt(table), retVal ]
			return 1;
		}
		else if (lua_istable(L, -1)) {
			lua_gettable(L, -3);      // 7 [ table, key, table[".get"], ..., mt(table), mt(table)["__index"], table, mt(table)["__index"][key] ]
			return 1;
		}
	}
	lua_pushnil(L);                   // 4 [ table, key, table[".get"], ..., nil ]
	return 1;
}

// Expects   [ table, key, value ]
// End Stack [ table, ... ]
// Returns   0
static int module_newindex_event(lua_State* L) {

	///////////////////////////////////////////////////
	// local setT = table[".set"]                    //
	// if type(setT) == "table" then                 //
	//     local set = setT[key]                     //
	//     if type(set) == "cfunction" then          //
	//         set(table, value)                     //
	//         return                                //
	//     end                                       //
	// end                                           //
	// baseMT = getmetatable(getmetatable(table))    //
	// if baseMT then                                //
	//     local baseNewIndex = baseMT["__newindex"] //
	//     if type(baseNewIndex) == "function" then  //
	//         baseNewIndex(table, key, value)       //
	//     end                                       //
	// end                                           //
	// table[key] = value                            //
	///////////////////////////////////////////////////

	lua_pushstring(L, ".set");           // 4  [ table, key, value, ".set" ]
	lua_rawget(L, -4);                   // 4  [ table, key, value, table[".set"] ]
	if (lua_istable(L, -1)) {
		lua_pushvalue(L, 2);             // 5  [ table, key, value, table[".set"], key ]
		lua_rawget(L, -2);               // 5  [ table, key, value, table[".set"], table[".set"][key] ]
		if (lua_iscfunction(L, -1)) {
			lua_pushvalue(L, 1);         // 6  [ table, key, value, table[".set"], table[".set"][key], table ]
			lua_pushvalue(L, 3);         // 7  [ table, key, value, table[".set"], table[".set"][key], table, value ]
			lua_call(L, 2, 0);           // 4  [ table, key, value, table[".set"] ]
			return 0;
		}
	}
										 // 4  [ table, key, value, table[".set"], ... ]
	if (lua_getmetatable(L, 1) && lua_getmetatable(L, -1)) { // TODO: Metatable Base
										 // 6  [ table, key, value, table[".set"], ..., mt(table), mt(mt(table)) ]
		lua_pushstring(L, "__newindex"); // 7  [ table, key, value, table[".set"], ..., mt(table), mt(mt(table)), "__newindex" ]
		lua_rawget(L, -2);               // 7  [ table, key, value, table[".set"], ..., mt(table), mt(mt(table)), mt(mt(table))["__newindex"] ]
		if (lua_isfunction(L, -1)) {
			lua_pushvalue(L, 1);         // 8  [ table, key, value, table[".set"], ..., mt(table), mt(mt(table)), mt(mt(table))["__newindex"], table ]
			lua_pushvalue(L, 2);         // 9  [ table, key, value, table[".set"], ..., mt(table), mt(mt(table)), mt(mt(table))["__newindex"], table, key ]
			lua_pushvalue(L, 3);         // 10 [ table, key, value, table[".set"], ..., mt(table), mt(mt(table)), mt(mt(table))["__newindex"], table, key, value ]
			lua_call(L, 3, 0);           // 6  [ table, key, value, table[".set"], ..., mt(table), mt(mt(table)) ]
		}
	}
	lua_settop(L, 3);                    // 3  [ table, key, value ]
	lua_rawset(L, -3);                   // 1  [ table ]
	return 0;
}

// Expects   [ table, key ]
// End Stack [ table, key, ..., retVal ]
// Returns   1
int class_index_event(lua_State* L) {
	int t = lua_type(L, 1);
	if (t == LUA_TUSERDATA) {

		/////////////////////////////////////////////////
		// local peerT = registry["tolua_peer"][table] //
		// if type(peerT) == "table" then              //
		//     local val = peerT[key]                  //
		//     if val ~= nil then                      //
		//         return val                          //
		//     end                                     //
		// end                                         //
		/////////////////////////////////////////////////

		lua_pushstring(L, "tolua_peer");             // 3 [ table, key, "tolua_peer" ]
		lua_rawget(L, LUA_REGISTRYINDEX);            // 3 [ table, key, registry["tolua_peer"] ]
		lua_pushvalue(L, 1);                         // 4 [ table, key, registry["tolua_peer"], table ]
		lua_rawget(L, -2);                           // 4 [ table, key, registry["tolua_peer"], registry["tolua_peer"][table] ]
		if (lua_istable(L, -1)) {
			lua_pushvalue(L, 2);                     // 5 [ table, key, registry["tolua_peer"], registry["tolua_peer"][table], key ]
			lua_gettable(L, -2);                     // 5 [ table, key, registry["tolua_peer"], registry["tolua_peer"][table], registry["tolua_peer"][table][key] ]
			if (!lua_isnil(L, -1)) {
				return 1;
			}
		}

		/////////////////////////////////////////////////////////
		// local curT = table                                  //
		// while true do                                       //
		//     local mt = getmetatable(curT)                   //
		//     if not mt then                                  //
		//         break                                       //
		//     end                                             //
		//     if type(key) == "number" then                   //
		//         local geti = mt[".geti"]                    //
		//         if type(geti) == "function" then            //
		//             return geti(table, key)                 //
		//         end                                         //
		//     else                                            //
		//         local mtVal = mt[key]                       //
		//         if mtVal ~= nil then                        //
		//             return mtVal                            //
		//         end                                         //
		//         local get = mt[".get"]                      //
		//         if type(get) == "table" then                //
		//             local getVal = get[key]                 //
		//             local getType = type(getVal)            //
		//             if getType == "cfunction" then          //
		//                 return getVal(table, key)           //
		//             elseif getType == "table" then          //
		//                 local newT = {}                     //
		//                 newT[".self"] = lud(ud2ptr(table))  //
		//                 setmetatable(newT, getVal)          //
		//                 storeatpeer(table, key, newTable)   //
		//                 return newTable                     //
		//             end                                     //
		//         end                                         //
		//     end                                             //
		//     curT = mt                                       //
		// end                                                 //
		// return nil                                          //
		/////////////////////////////////////////////////////////

		lua_settop(L, 2);                            // 2 [ table, key ]
		lua_pushvalue(L, 1);                         // 3 [ table, key, table -> curT ]
		while (lua_getmetatable(L, -1)) {            // TODO: Metatable Base
													 // 4 [ table, key, curT, mt(curT) ]
			lua_remove(L, -2);                       // 3 [ table, key, mt(curT) ]
			if (lua_isnumber(L, 2)) {
				lua_pushstring(L, ".geti");          // 4 [ table, key, mt(curT), ".geti" ]
				lua_rawget(L, -2);                   // 4 [ table, key, mt(curT), mt(curT)[".geti"] ]
				if (lua_isfunction(L, -1)) {
					lua_pushvalue(L, 1);             // 5 [ table, key, mt(curT), mt(curT)[".geti"], table ]
					lua_pushvalue(L, 2);             // 6 [ table, key, mt(curT), mt(curT)[".geti"], table, key ]
					lua_call(L, 2, 1);               // 4 [ table, key, mt(curT), retVal ]
					return 1;
				}
			}
			else {
				lua_pushvalue(L, 2);                 // 4 [ table, key, mt(curT), key ]
				lua_rawget(L, -2);                   // 4 [ table, key, mt(curT), mt(curT)[key] ]
				if (!lua_isnil(L, -1)) {
					return 1;
				}
				else {
					lua_pop(L, 1);                   // 3 [ table, key, mt(curT) ]
				}
				lua_pushstring(L, ".get");           // 4 [ table, key, mt(curT), ".get" ]
				lua_rawget(L, -2);                   // 4 [ table, key, mt(curT), mt(curT)[".get"] ]
				if (lua_istable(L, -1)) {
					lua_pushvalue(L, 2);             // 5 [ table, key, mt(curT), mt(curT)[".get"], key ]
					lua_rawget(L, -2);               // 5 [ table, key, mt(curT), mt(curT)[".get"], mt(curT)[".get"][key] ]
					if (lua_iscfunction(L, -1)) {
						lua_pushvalue(L, 1);         // 6 [ table, key, mt(curT), mt(curT)[".get"], mt(curT)[".get"][key], table ]
						lua_pushvalue(L, 2);         // 7 [ table, key, mt(curT), mt(curT)[".get"], mt(curT)[".get"][key], table, key ]
						lua_call(L, 2, 1);           // 5 [ table, key, mt(curT), mt(curT)[".get"], retVal ]
						return 1;
					}
					else if (lua_istable(L, -1)) {
						void* u = *((void**)lua_touserdata(L, 1));
						lua_newtable(L);             // 6 [ table, key, mt(curT), mt(curT)[".get"], mt(curT)[".get"][key], newTable ]
						lua_pushstring(L, ".self");  // 7 [ table, key, mt(curT), mt(curT)[".get"], mt(curT)[".get"][key], newTable, ".self" ]
						lua_pushlightuserdata(L, u); // 8 [ table, key, mt(curT), mt(curT)[".get"], mt(curT)[".get"][key], newTable, ".self", lud(ud2ptr(table)) ]
						lua_rawset(L, -3);           // 6 [ table, key, mt(curT), mt(curT)[".get"], mt(curT)[".get"][key], newTable ]
						lua_insert(L, -2);           // 6 [ table, key, mt(curT), mt(curT)[".get"], newTable, mt(table)[".get"][key] ]
						lua_setmetatable(L, -2);     // 5 [ table, key, mt(curT), mt(curT)[".get"], newTable ]
						lua_pushvalue(L, -1);        // 6 [ table, key, mt(curT), mt(curT)[".get"], newTable, newTable ]
						lua_pushvalue(L, 2);         // 7 [ table, key, mt(curT), mt(curT)[".get"], newTable, newTable, key]
						lua_insert(L, -2);           // 7 [ table, key, mt(curT), mt(curT)[".get"], newTable, key, newTable]
						storeatpeer(L, 1);           // 5 [ table, key, mt(curT), mt(curT)[".get"], newTable ]
						return 1;
					}
				}
			}
			lua_settop(L, 3);                        // 3 [ table, key, mt(table) -> curT ]
		}
		lua_pushnil(L);                              // 4 [ table, key, ..., nil ]
		return 1;
	}
	else if (t == LUA_TTABLE) {
		module_index_event(L);                       // 4 [ table, key, table[".get"], ..., retVal ]
		return 1;
	}
	lua_pushnil(L);                                  // 3 [ table, key, nil ]
	return 1;
}

// Expects   [ table, key, value ]
// End Stack [ table, ... ]
// Returns   0
static int class_newindex_event(lua_State* L) {
	int t = lua_type(L, 1);
	if (t == LUA_TUSERDATA) {

		/////////////////////////////////////////////////////////////////////
		// if type(key) == "number" then                                   //
		//     local curT = table                                          //
		//     while true do                                               //
		//         local mt = getmetatable(curT)                           //
		//         if not mt then                                          //
		//             break                                               //
		//         end                                                     //
		//         local seti = mt[".seti"]                                //
		//         if type(seti) == "function" then                        //
		//             seti(table, key, value)                             //
		//             return                                              //
		//         end                                                     //
		//         curT = mt                                               //
		//     end                                                         //
		//     error("Attempt to set indexed value on an invalid operand") //
		// else                                                            //
		//     local curT = table                                          //
		//     while true do                                               //
		//         local mt = getmetatable(curT)                           //
		//         if not mt then                                          //
		//             break                                               //
		//         end                                                     //
		//         local set = mt[".set"]                                  //
		//         if type(set) == "table" then                            //
		//             local setV = set[key]                               //
		//             if type(setV) == "cfunction" then                   //
		//                 setV(table, value)                              //
		//                 return                                          //
		//             end                                                 //
		//         end                                                     //
		//         curT = mt                                               //
		//     end                                                         //
		// end                                                             //
		// storeatpeer(table, key, value)                                  //
		/////////////////////////////////////////////////////////////////////

		if (lua_isnumber(L, 2)) {
			lua_pushvalue(L, 1);              // 4 [ table, key, value, table -> curT ]
			while (lua_getmetatable(L, -1)) { // TODO: Metatable Base
											  // 5 [ table, key, value, curT, mt(curT) ]
				lua_remove(L, -2);            // 4 [ table, key, value, mt(curT) ]
				lua_pushstring(L, ".seti");   // 5 [ table, key, value, mt(curT), ".seti" ]
				lua_rawget(L, -2);            // 5 [ table, key, value, mt(curT), mt(curT)[".seti"] ]
				if (lua_isfunction(L, -1)) {
					lua_pushvalue(L, 1);      // 6 [ table, key, value, mt(curT), mt(curT)[".seti"], table ]
					lua_pushvalue(L, 2);      // 7 [ table, key, value, mt(curT), mt(curT)[".seti"], table, key ]
					lua_pushvalue(L, 3);      // 8 [ table, key, value, mt(curT), mt(curT)[".seti"], table, key, value ]
					lua_call(L, 3, 0);        // 4 [ table, key, value, mt(curT) ]
					return 0;
				}
				lua_settop(L, 4);             // 4 [ table, key, value, mt(curT) -> curT ]
			}
			tolua_error(L, "Attempt to set indexed value on an invalid operand", NULL);
		}
		else {
			lua_pushvalue(L, 1);              // 4 [ table, key, value, table -> curT ]
			while (lua_getmetatable(L, -1)) { // TODO: Metatable Base
											  // 5 [ table, key, value, curT, mt(curT) ]
				lua_remove(L, -2);            // 4 [ table, key, value, mt(curT) ]
				lua_pushstring(L, ".set");    // 5 [ table, key, value, mt(curT), ".set" ]
				lua_rawget(L, -2);            // 5 [ table, key, value, mt(curT), mt(curT)[".set"] ]
				if (lua_istable(L, -1)) {
					lua_pushvalue(L, 2);      // 6 [ table, key, value, mt(curT), mt(curT)[".set"], key ]
					lua_rawget(L, -2);        // 6 [ table, key, value, mt(curT), mt(curT)[".set"], mt(curT)[".set"][key] ]
					if (lua_iscfunction(L, -1)) {
						lua_pushvalue(L, 1);  // 7 [ table, key, value, mt(curT), mt(curT)[".set"], mt(curT)[".set"][key], table ]
						lua_pushvalue(L, 3);  // 8 [ table, key, value, mt(curT), mt(curT)[".set"], mt(curT)[".set"][key], table, value ]
						lua_call(L, 2, 0);    // 5 [ table, key, value, mt(curT), mt(curT)[".set"] ]
						return 0;
					}
				}
				lua_settop(L, 4);             // 4 [ table, key, value, mt(curT) -> curT ]
			}
		}
		lua_settop(L, 3);                     // 3 [ table, key, value ]
		storeatpeer(L, 1);                    // 1 [ table ]
	}
	else if (t == LUA_TTABLE) {
		module_newindex_event(L);
	}
	return 0;
}

// Expects   [ a, b ]
// End Stack [ a, b, ..., retVal ]
// Returns   1
static int do_operator(lua_State* L, const char* op) {

	/////////////////////////////////////////////////////////////////
	// if type(a) == "userdata" then                               //
	//     local curT = a                                          //
	//     while true do                                           //
	//         local mt = getmetatable(curT)                       //
	//         if not mt then                                      //
	//             break                                           //
	//         end                                                 //
	//         local opV = mt[op]                                  //
	//         if type(opV) == "function" then                     //
	//             return opV(a, b)                                //
	//         end                                                 //
	//         curT = mt                                           //
	//     end                                                     //
	// end                                                         //
	// if op == ".eq" then                                         //
	//     return rawequal(a, b)                                   //
	// end                                                         //
	// error("Attempt to perform operation on an invalid operand") //
	/////////////////////////////////////////////////////////////////

	if (lua_isuserdata(L, 1)) {
		lua_pushvalue(L, 1);                       // 3 [ a, b, a -> curT ]
		while (lua_getmetatable(L, -1)) {          // TODO: Metatable Base
												   // 4 [ a, b, curT, mt(curT) ]
			lua_remove(L, -2);                     // 3 [ a, b, mt(curT) ]
			lua_pushstring(L, op);                 // 4 [ a, b, mt(curT), op ]
			lua_rawget(L, -2);                     // 4 [ a, b, mt(curT), mt(curT)[op] ]
			if (lua_isfunction(L, -1)) {
				lua_pushvalue(L, 1);               // 5 [ a, b, mt(curT), mt(curT)[op], a ]
				lua_pushvalue(L, 2);               // 6 [ a, b, mt(curT), mt(curT)[op], a, b ]
				lua_call(L, 2, 1);                 // 4 [ a, b, mt(curT), retVal ]
				return 1;
			}
			lua_settop(L, 3);                      // 2 [ a, b, mt(curT) -> curT ]
		}
	}
	if (strcmp(op, ".eq") == 0) {
		lua_pushboolean(L, lua_rawequal(L, 1, 2)); // 3 [ a, b, ..., true/false ]
		return 1;
	}
	else {
		tolua_error(L, "Attempt to perform operation on an invalid operand", NULL);
		return 0;
	}
}

static int class_add_event(lua_State* L) {
	return do_operator(L, ".add");
}

static int class_sub_event(lua_State* L) {
	return do_operator(L, ".sub");
}

static int class_mul_event(lua_State* L) {
	return do_operator(L, ".mul");
}

static int class_div_event(lua_State* L) {
	return do_operator(L, ".div");
}

static int class_lt_event(lua_State* L) {
	return do_operator(L, ".lt");
}

static int class_le_event(lua_State* L) {
	return do_operator(L, ".le");
}

static int class_eq_event(lua_State* L) {
	return do_operator(L, ".eq");
}

// Expects   [ table ]
// End Stack [ table, mt(curT), retVal ]
// Returns   1
static int class_len_event(lua_State* L) {
	if (lua_isuserdata(L, 1)) {
		lua_pushvalue(L, 1);              // 2 [ table, table -> curT ]
		while (lua_getmetatable(L, -1)) { // TODO: Metatable Base
										  // 3 [ table, curT, mt(curT) ]
			lua_remove(L, -2);            // 2 [ table, mt(curT) ]
			lua_pushstring(L, ".len");    // 3 [ table, mt(curT), ".len" ]
			lua_rawget(L, -2);            // 3 [ table, mt(curT), mt(curT)[".len"] ]
			if (lua_isfunction(L, -1)) {
				lua_pushvalue(L, 1);      // 4 [ table, mt(curT), mt(curT)[".len"], table ]
				lua_call(L, 1, 1);        // 3 [ table, mt(curT), retVal ]
				return 1;
			}
			// Note: Loop using wrong top index, (3 vs 2)?
			lua_settop(L, 3);             // 3 [ table, mt(curT), mt(curT)[".len"] ]
		}
	}
	tolua_error(L, "Attempt to perform operation on an invalid operand", NULL);
	return 0;
}

// Expects   [ table ]
// End Stack [ table ]
// Returns   0
static int class_gc_event(lua_State* L) {

	//////////////////////////////////////////////////////////////////////////////////
	// if type(table) == "userdata" then                                            //
	//     local ptr = ud2ptr(table)                                                //
	//     local ptrLUD = lud(ptr)                                                  //
	//     local gcRegV = registry["tolua_gc"][ptrLUD]                              //
	//     if gcRegV ~= nil then                                                    //
	//         registry["tolua_gc"][ptrLUD] = nil                                   //
	//         if type(gcRegV) == "function" then                                   //
	//             gcRegV(table)                                                    //
	//         elseif type(gcRegV) == "userdata" and ud2ptr(gcRegV) == nullptr then //
	//             free(ptr)                                                        //
	//             tolua_release(ptr)                                               //
	//         end                                                                  //
	//     end                                                                      //
	// end                                                                          //
	//////////////////////////////////////////////////////////////////////////////////

	if (lua_type(L, 1) == LUA_TUSERDATA) {
		int top = lua_gettop(L);
		void* u = *((void**)lua_touserdata(L, 1));
		lua_pushstring(L, "tolua_gc");    // 2 [ table, "tolua_gc" ]
		lua_rawget(L, LUA_REGISTRYINDEX); // 2 [ table, registry["tolua_gc"] ]
		lua_pushlightuserdata(L, u);      // 3 [ table, registry["tolua_gc"], lud(ptr) ]
		lua_rawget(L, -2);                // 3 [ table, registry["tolua_gc"], registry["tolua_gc"][lud(ptr)] ]
		if (!lua_isnil(L, -1)) {
			lua_pushlightuserdata(L, u);  // 4 [ table, registry["tolua_gc"], registry["tolua_gc"][lud(ptr)], lud(ptr) ]
			lua_pushnil(L);               // 5 [ table, registry["tolua_gc"], registry["tolua_gc"][lud(ptr)], lud(ptr), nil ]
			lua_rawset(L, -4);            // 3 [ table, registry["tolua_gc"], registry["tolua_gc"][lud(ptr)] ]
			if (lua_isfunction(L, -1)) {
				lua_pushvalue(L, 1);      // 4 [ table, registry["tolua_gc"], registry["tolua_gc"][lud(ptr)], table ]
				lua_call(L, 1, 0);        // 2 [ table, registry["tolua_gc"] ]
			}
			else if (lua_isuserdata(L, -1) && *((void**)lua_touserdata(L, -1)) == NULL) {
				free(u);
				tolua_release(L, u);
			}
		}
		lua_settop(L, top);               // 1 [ table ]
	}
	return 0;
}

// Expects   [ ..., module ]
// End Stack [ ..., module ]
TOLUA_API void tolua_moduleevents(lua_State* L) {
	lua_pushstring(L, "__index");
	lua_pushcfunction(L, module_index_event);
	lua_rawset(L, -3);

	lua_pushstring(L, "__newindex");
	lua_pushcfunction(L, module_newindex_event);
	lua_rawset(L, -3);
}

// Expects   [ ..., table ]
// End Stack [ ..., table ]
TOLUA_API int tolua_ismodulemetatable(lua_State* L) {
	int r = 0;
	if (lua_getmetatable(L, -1)) {    // TODO: Metatable
									  // 2 [ ..., table, mt(table) ]
		lua_pushstring(L, "__index"); // 3 [ ..., table, mt(table), "__index" ]
		lua_rawget(L, -2);            // 3 [ ..., table, mt(table), mt(table)["__index"] ]
		r = (lua_tocfunction(L, -1) == module_index_event);
		lua_pop(L, 2);                // 1 [ ..., table ]
	}
	return r;
}

// Expects   [ ..., metatable ]
// End Stack [ ..., metatable ]
TOLUA_API void tolua_classevents(lua_State* L) {
	lua_pushstring(L, "__index");
	lua_pushcfunction(L, class_index_event);
	lua_rawset(L, -3);

	lua_pushstring(L, "__newindex");
	lua_pushcfunction(L, class_newindex_event);
	lua_rawset(L, -3);

	lua_pushstring(L, "__add");
	lua_pushcfunction(L, class_add_event);
	lua_rawset(L, -3);

	lua_pushstring(L, "__sub");
	lua_pushcfunction(L, class_sub_event);
	lua_rawset(L, -3);

	lua_pushstring(L, "__mul");
	lua_pushcfunction(L, class_mul_event);
	lua_rawset(L, -3);

	lua_pushstring(L, "__div");
	lua_pushcfunction(L, class_div_event);
	lua_rawset(L, -3);

	lua_pushstring(L, "__lt");
	lua_pushcfunction(L, class_lt_event);
	lua_rawset(L, -3);

	lua_pushstring(L, "__le");
	lua_pushcfunction(L, class_le_event);
	lua_rawset(L, -3);

	lua_pushstring(L, "__eq");
	lua_pushcfunction(L, class_eq_event);
	lua_rawset(L, -3);

	lua_pushstring(L, "__len");
	lua_pushcfunction(L, class_len_event);
	lua_rawset(L, -3);

	lua_pushstring(L, "__gc");
	lua_pushcfunction(L, class_gc_event);
	lua_rawset(L, -3);
}
