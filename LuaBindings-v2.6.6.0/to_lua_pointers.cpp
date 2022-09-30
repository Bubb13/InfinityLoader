
#include "to_lua_pointers.h"
#include "lua_pointers.h"

#include "EEexLua_generated_baseclass_offsets.h"

//////////////
// Pointers //
//////////////

type_free* p_free;
type_malloc* p_malloc;
type_tolua_beginmodule* p_tolua_beginmodule;
type_tolua_bnd_cast* p_tolua_bnd_cast;
type_tolua_bnd_release* p_tolua_bnd_release;
type_tolua_bnd_releaseownership* p_tolua_bnd_releaseownership;
type_tolua_bnd_takeownership* p_tolua_bnd_takeownership;
type_tolua_bnd_type* p_tolua_bnd_type;
//type_tolua_cclass* p_tolua_cclass;
type_tolua_constant* p_tolua_constant;
type_tolua_endmodule* p_tolua_endmodule;
type_tolua_error* p_tolua_error;
type_tolua_function* p_tolua_function;
type_tolua_getmetatable* p_tolua_getmetatable;
type_tolua_isboolean* p_tolua_isboolean;
type_tolua_isnumber* p_tolua_isnumber;
type_tolua_isstring* p_tolua_isstring;
type_tolua_isusertype* p_tolua_isusertype;
type_tolua_module* p_tolua_module;
type_tolua_newmetatable* p_tolua_newmetatable;
//type_tolua_open* p_tolua_open;
type_tolua_pushboolean* p_tolua_pushboolean;
type_tolua_pushnumber* p_tolua_pushnumber;
type_tolua_pushstring* p_tolua_pushstring;
//type_tolua_tonumber* p_tolua_tonumber;
type_tolua_tostring* p_tolua_tostring;
type_tolua_tousertype* p_tolua_tousertype;
type_tolua_typename* p_tolua_typename;
type_tolua_usertype* p_tolua_usertype;
type_tolua_variable* p_tolua_variable;

//////////////////////////////////////////////////////
// Reimplementations (engine doesn't include these) //
//////////////////////////////////////////////////////

int p_tolua_istable(lua_State* L, int lo, int def, tolua_Error* err) {
	if (def && p_lua_gettop(L) < abs(lo))
		return 1;
	if (p_lua_istable(L, lo))
		return 1;
	err->index = lo;
	err->array = 0;
	err->type = "table";
	return 0;
}

int p_tolua_isuserdata(lua_State* L, int lo, int def, tolua_Error* err) {
	if (def && p_lua_gettop(L) < abs(lo))
		return 1;
	if (p_lua_isnil(L, lo) || p_lua_isuserdata(L, lo))
		return 1;
	err->index = lo;
	err->array = 0;
	err->type = "userdata";
	return 0;
}

int p_tolua_isvaluenil(lua_State* L, int lo, tolua_Error* err) {
	if (p_lua_gettop(L) < abs(lo))
		return 0;
	if (!p_lua_isnil(L, lo))
		return 0;
	err->index = lo;
	err->array = 0;
	err->type = "value";
	return 1;
}

void p_tolua_pushusertype_nocast(lua_State* L, void* value, const char* type) {
	if (value == nullptr) {
		p_lua_pushnil(L);
	}
	else {
		*(void**)p_lua_newuserdata(L, sizeof(void*)) = value;
		p_tolua_getmetatable(L, type);
		p_lua_setmetatable(L, -2);
	}
}

void* p_tolua_touserdata(lua_State* L, int narg, void* def) {
	return p_lua_gettop(L) < abs(narg) ? def : p_lua_touserdata(L, narg);
}

std::string tolua_getusertype(lua_State* L, int lo) {
	int tag = p_lua_type(L, lo);
	if (tag == LUA_TUSERDATA && p_lua_getmetatable(L, lo)) {
		p_lua_rawget(L, LUA_REGISTRYINDEX);
		if (p_lua_type(L, -1) == LUA_TSTRING) {
			std::string toReturn{ p_lua_tostring(L, -1) };
			p_lua_pop(L, 1);
			return toReturn;
		}
		else {
			p_lua_pop(L, 1);
		}
	}
	return std::string{};
}

void tolua_pushusertypepointer(lua_State* L, void* value, const char* type) {
	if (value == nullptr) {
		p_lua_pushnil(L);
	}
	else {
		void** block = (void**)p_lua_newuserdata(L, sizeof(void*) * 2);
		block[0] = &block[1];
		block[1] = value;
		p_tolua_getmetatable(L, type);
		p_lua_setmetatable(L, -2);
	}
}

void tolua_pushusertypestring(lua_State* L, int index) {
	int tag = p_lua_type(L, index);
	if (tag == LUA_TUSERDATA && p_lua_getmetatable(L, index)) {
		                                    // [ getmetatable(stack[index]) ]
		p_lua_rawget(L, LUA_REGISTRYINDEX); // [ registry[getmetatable(stack[index])] ]
		if (p_lua_type(L, -1) == LUA_TSTRING) {
			return;
		}
		else {
			p_lua_pop(L, 1);                // [ ]
		}
	}
	p_lua_pushnil(L);                       // [ nil ]
}

///////////////////////////////////////////////////
// Overrides (engine needs these to be replaced) //
///////////////////////////////////////////////////

void dumpStackIndex(lua_State* L, const char* label, int index) {

	p_lua_getglobal(L, "debug");        // [ debug ]
	p_lua_getfield(L, -1, "traceback"); // [ debug, traceback ]

	p_lua_getglobal(L, "EEex_Dump");    // [ debug, traceback, EEex_Dump ]
	p_lua_pushstring(L, label);         // [ debug, traceback, EEex_Dump, label ]
	p_lua_pushvalue(L, index);          // [ debug, traceback, EEex_Dump, label, stack[index] ]

	if (p_lua_pcallk(L, 2, 0, -4, 0, nullptr) != LUA_OK) {
		// [ debug, traceback, errorMessage ]
		printf("[!] %s\n", p_lua_tostring(L, -1));
		p_lua_pop(L, 3);                // [ ]
	}
	else {
		// [ debug, traceback ]
		p_lua_pop(L, 2);                // [ ]
	}
}

void dumpStack(lua_State* L) {
	size_t top = p_lua_gettop(L);
	for (size_t i = 1; i <= top; ++i) {
		char indexChar[2] = { i + 48, '\0' };
		dumpStackIndex(L, indexChar, i);
	}
}

void p_tolua_open(lua_State* L) {
	int top = p_lua_gettop(L);
	p_lua_pushstring(L, "tolua_opened");       // [ "tolua_opened" ]
	p_lua_rawget(L, LUA_REGISTRYINDEX);        // [ registry["tolua_opened"] ]
	if (!p_lua_isboolean(L, -1)) {

		p_lua_pushstring(L, "tolua_opened");   // [ registry["tolua_opened"], "tolua_opened" ]
		p_lua_pushboolean(L, 1);               // [ registry["tolua_opened"], "tolua_opened", true ]
		p_lua_rawset(L, LUA_REGISTRYINDEX);    // [ registry["tolua_opened"] ]

		p_lua_pushstring(L, "tolua_ubox");     // [ registry["tolua_opened"], "tolua_ubox" ]
		p_lua_newtable(L);                     // [ registry["tolua_opened"], "tolua_ubox", newT ]
		p_lua_pushvalue(L, -1);                // [ registry["tolua_opened"], "tolua_ubox", newT, newT ]
		p_lua_pushstring(L, "__mode");         // [ registry["tolua_opened"], "tolua_ubox", newT, newT, "__mode" ]
		p_lua_pushstring(L, "v");              // [ registry["tolua_opened"], "tolua_ubox", newT, newT, "__mode", "v" ]
		p_lua_rawset(L, -3);                   // [ registry["tolua_opened"], "tolua_ubox", newT, newT ]
		p_lua_setmetatable(L, -2);             // [ registry["tolua_opened"], "tolua_ubox", newT ]
		p_lua_rawset(L, LUA_REGISTRYINDEX);    // [ registry["tolua_opened"] ]

		p_lua_pushstring(L, "tolua_peer");     // [ registry["tolua_opened"], "tolua_peer" ]
		p_lua_newtable(L);                     // [ registry["tolua_opened"], "tolua_peer", newT ]
		p_lua_pushvalue(L, -1);                // [ registry["tolua_opened"], "tolua_peer", newT, newT ]
		p_lua_pushstring(L, "__mode");         // [ registry["tolua_opened"], "tolua_peer", newT, newT, "__mode" ]
		p_lua_pushstring(L, "k");              // [ registry["tolua_opened"], "tolua_peer", newT, newT, "__mode", "k" ]
		p_lua_rawset(L, -3);                   // [ registry["tolua_opened"], "tolua_peer", newT, newT ]
		p_lua_setmetatable(L, -2);             // [ registry["tolua_opened"], "tolua_peer", newT ]
		p_lua_rawset(L, LUA_REGISTRYINDEX);    // [ registry["tolua_opened"] ]

		p_lua_pushstring(L, "tolua_super");    // [ registry["tolua_opened"], "tolua_super" ]
		p_lua_newtable(L);                     // [ registry["tolua_opened"], "tolua_super", newT ]
		p_lua_rawset(L, LUA_REGISTRYINDEX);    // [ registry["tolua_opened"] ]

		p_lua_pushstring(L, "tolua_gc");       // [ registry["tolua_opened"], "tolua_gc" ]
		p_lua_newtable(L);                     // [ registry["tolua_opened"], "tolua_gc", newT ]
		p_lua_rawset(L, LUA_REGISTRYINDEX);    // [ registry["tolua_opened"] ]

		p_lua_pushstring(L, "tolua_base");     // [ registry["tolua_opened"], "tolua_base" ]
		p_lua_newtable(L);                     // [ registry["tolua_opened"], "tolua_base", newT ]
		p_lua_rawset(L, LUA_REGISTRYINDEX);    // [ registry["tolua_opened"] ]

		p_lua_pushstring(L, "tolua_base_map"); // [ registry["tolua_opened"], "tolua_base_map" ]
		p_lua_newtable(L);                     // [ registry["tolua_opened"], "tolua_base_map", newT ]
		p_lua_rawset(L, LUA_REGISTRYINDEX);    // [ registry["tolua_opened"] ]

		p_tolua_newmetatable(L, "tolua_commonclass");

		p_tolua_module(L, NULL, 0);
		p_tolua_beginmodule(L, NULL);
		p_tolua_module(L, "tolua", 0);
		p_tolua_beginmodule(L, "tolua");
		p_tolua_function(L, "type", p_tolua_bnd_type);
		p_tolua_function(L, "takeownership", p_tolua_bnd_takeownership);
		p_tolua_function(L, "releaseownership", p_tolua_bnd_releaseownership);
		p_tolua_function(L, "cast", p_tolua_bnd_cast);
		p_tolua_function(L, "release", p_tolua_bnd_release);
		//p_tolua_function(L, "getpeertable", tolua_bnd_getpeertable);
		p_tolua_endmodule(L);
		p_tolua_endmodule(L);
	}
	p_lua_settop(L, top);
}

// The normal implementation of this interprets "0" as "true"!
int p_tolua_toboolean(lua_State* L, int narg, int def) {
	if (p_lua_gettop(L) < abs(narg)) {
		return def;
	}
	if (p_lua_isnumber(L, narg)) {
		return p_lua_tonumber(L, narg) != 0;
	}
	return p_lua_toboolean(L, narg);
}

// The normal implementation of this interprets "true" as "0"!
double p_tolua_tonumber(lua_State* L, int narg, double def) {
	if (p_lua_gettop(L) < abs(narg)) {
		return def;
	}
	if (p_lua_isboolean(L, narg)) {
		return p_lua_toboolean(L, narg);
	}
	return p_lua_tonumber(L, narg);
}

// Custom
lua_Number tolua_setter_tonumber(lua_State* L, const char* variableName) {
	constexpr int narg = 2;
	if (p_lua_gettop(L) < narg) {
		return luaL_error(L, "argument missing in number variable setter '%s'; 'number' expected.", variableName);
	}
	return p_lua_type(L, narg) == LUA_TNUMBER
		? p_lua_tonumber(L, narg)
		: luaL_error(L, "invalid type '%s' in number variable setter '%s'; 'number' expected.", p_tolua_typename(L, narg), variableName);
}

// Custom
lua_Integer tolua_setter_tointeger(lua_State* L, const char* variableName) {
	constexpr int narg = 2;
	if (p_lua_gettop(L) < narg) {
		return luaL_error(L, "argument missing in integer variable setter '%s'; 'number' or 'boolean' expected.", variableName);
	}
	switch (p_lua_type(L, narg)) {
		case LUA_TBOOLEAN: return p_lua_toboolean(L, narg);
		case LUA_TNUMBER: return p_lua_tointeger(L, narg);
	}
	return luaL_error(L, "invalid type '%s' in integer variable setter '%s'; 'number' or 'boolean' expected.", p_tolua_typename(L, narg), variableName);
}

// Custom
bool tolua_setter_toboolean(lua_State* L, const char* variableName) {
	constexpr int narg = 2;
	if (p_lua_gettop(L) < narg) {
		return luaL_error(L, "argument missing in boolean variable setter '%s'; 'boolean' or 'number' expected.", variableName);
	}
	switch (p_lua_type(L, narg)) {
		case LUA_TBOOLEAN: return p_lua_toboolean(L, narg);
		case LUA_TNUMBER: {
			const lua_Integer arg = p_lua_tointeger(L, narg);
			switch (arg) {
				case 0: return false;
				case 1: return true;
			}
			return luaL_error(L, "invalid integer argument '%d' in boolean variable setter '%s'; '0' or '1' expected.", arg, variableName);
		}
	}
	return luaL_error(L, "invalid type '%s' in boolean variable setter '%s'; 'boolean' or 'number' expected.", p_tolua_typename(L, narg), variableName);
}

// Expects   [ ..., key, value ]
// End Stack [ ... ]
static void p_storeatpeer(lua_State* L, int index) {

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

	p_lua_pushstring(L, "tolua_peer");  // 3 [ ..., key, value, "tolua_peer" ]
	p_lua_rawget(L, LUA_REGISTRYINDEX); // 3 [ ..., key, value, registry["tolua_peer"] ]
	p_lua_pushvalue(L, index);          // 4 [ ..., key, value, registry["tolua_peer"], stack[index] ]
	p_lua_rawget(L, -2);                // 4 [ ..., key, value, registry["tolua_peer"], registry["tolua_peer"][stack[index]] -> dest ]
	if (!p_lua_istable(L, -1)) {

		///////////////////////////////////////////////////////
		// registry["tolua_peer"][stack[index]] = {} -> dest //
		///////////////////////////////////////////////////////

		p_lua_pop(L, 1);                // 3 [ ..., key, value, registry["tolua_peer"] ]
		p_lua_newtable(L);              // 4 [ ..., key, value, registry["tolua_peer"], newtable ]
		p_lua_pushvalue(L, index);      // 5 [ ..., key, value, registry["tolua_peer"], newtable, stack[index] ]
		p_lua_pushvalue(L, -2);         // 6 [ ..., key, value, registry["tolua_peer"], newtable, stack[index], newtable ]
		p_lua_settable(L, -4);          // 4 [ ..., key, value, registry["tolua_peer"], newtable -> dest ]
	}

	///////////////////////
	// dest[key] = value //
	///////////////////////

	p_lua_insert(L, -4);                // 4 [ ..., dest, key, value, registry["tolua_peer"] ]
	p_lua_pop(L, 1);                    // 3 [ ..., dest, key, value ]
	p_lua_rawset(L, -3);                // 1 [ ..., dest ]
	p_lua_pop(L, 1);                    // 0 [ ... ]
}

// Expects   [ ..., table, key, value ]
// End Stack [ ..., table, key, value ]
void callSetI(lua_State* L) {
	p_lua_pushvalue(L, -3);             // 4 [ ..., table, key, value, table ]
	while (p_lua_getmetatable(L, -1)) {
		                                // 5 [ ..., table, key, value, table, getmetatable(table) ]
		p_lua_remove(L, -2);            // 4 [ ..., table, key, value, getmetatable(table) ]
		p_lua_pushstring(L, ".seti");   // 5 [ ..., table, key, value, getmetatable(table), ".seti" ]
		p_lua_rawget(L, -2);            // 5 [ ..., table, key, value, getmetatable(table), getmetatable(table)[".seti"] ]
		if (p_lua_isfunction(L, -1)) {
			p_lua_pushvalue(L, -5);     // 6 [ ..., table, key, value, getmetatable(table), getmetatable(table)[".seti"], table ]
			p_lua_pushvalue(L, -5);     // 7 [ ..., table, key, value, getmetatable(table), getmetatable(table)[".seti"], table, key ]
			p_lua_pushvalue(L, -5);     // 8 [ ..., table, key, value, getmetatable(table), getmetatable(table)[".seti"], table, key, value ]
			p_lua_call(L, 3, 0);        // 4 [ ..., table, key, value, getmetatable(table) ]
			p_lua_pop(L, 1);            // 3 [ ..., table, key, value ]
			return;
		}
		p_lua_pop(L, 1);                // 4 [ ..., table, key, value, getmetatable(table) ]
	}
	p_lua_pop(L, 1);                    // 3 [ ..., table, key, value ]
	p_tolua_error(L, "Attempt to set indexed value on an invalid operand", NULL);
}

// Expects   [ ..., table, key, value ]
// End Stack [ ..., table, key, value ]
int callSet(lua_State* L) {

	///////////////////////////////////////////
	// local setT = table[".set"]            //
	// if type(setT) == "table" then         //
	//     local setV = setT[key]            //
	//     if type(setV) == "cfunction" then //
	//         return setV(table, value)     //
	//     end                               //
	// end                                   //
	///////////////////////////////////////////

	p_lua_pushstring(L, ".set");            // 4 [ ..., table, key, value, ".set" ]
	p_lua_rawget(L, -4);                    // 4 [ ..., table, key, value, table[".set"] ]
	if (p_lua_istable(L, -1)) {
		p_lua_pushvalue(L, -3);             // 5 [ ..., table, key, value, table[".set"], key ]
		p_lua_rawget(L, -2);                // 5 [ ..., table, key, value, table[".set"], table[".set"][key] ]
		if (p_lua_iscfunction(L, -1)) {
			p_lua_pushvalue(L, -5);         // 6 [ ..., table, key, value, table[".set"], table[".set"][key], table ]
			p_lua_pushvalue(L, -4);         // 7 [ ..., table, key, value, table[".set"], table[".set"][key], table, value ]
			p_lua_call(L, 2, 0);            // 4 [ ..., table, key, value, table[".set"] ]
			p_lua_pop(L, 1);                // 3 [ ..., table, key, value ]
			return 1;
		}
		else {
			p_lua_pop(L, 2);                // 3 [ ..., table, key, value ]
		}
	}
	else {
		p_lua_pop(L, 1);                    // 3 [ ..., table, key, value ]
	}

	//////////////////////////////////////////////
	// local curTable = table                   //
	// while true do                            //
	//     local meta = getmetatable(curTable)  //
	//     if not meta then                     //
	//         break                            //
	//     end                                  //
	//     curTable = meta                      //
	//     local setT = meta[".set"]            //
	//     if type(setT) == "table" then        //
	//         local set = setT[key]            //
	//         if type(set) == "cfunction" then //
	//             set(table, value)            //
	//             return 1                     //
	//         end                              //
	//     end                                  //
	// end                                      //
	// return 0                                 //
	//////////////////////////////////////////////

	p_lua_pushvalue(L, -3);                 // 4 [ ..., table, key, value, table ]
	while (p_lua_getmetatable(L, -1)) {
		                                    // 5 [ ..., table, key, value, table, getmetatable(table) ]
		p_lua_remove(L, -2);                // 4 [ ..., table, key, value, getmetatable(table) ]
		p_lua_pushstring(L, ".set");        // 5 [ ..., table, key, value, getmetatable(table), ".set" ]
		p_lua_rawget(L, -2);                // 5 [ ..., table, key, value, getmetatable(table), getmetatable(table)[".set"] ]
		if (p_lua_istable(L, -1)) {
			p_lua_pushvalue(L, -4);         // 6 [ ..., table, key, value, getmetatable(table), getmetatable(table)[".set"], key ]
			p_lua_rawget(L, -2);            // 6 [ ..., table, key, value, getmetatable(table), getmetatable(table)[".set"], getmetatable(table)[".set"][key] ]
			if (p_lua_iscfunction(L, -1)) {
				p_lua_pushvalue(L, -6);     // 7 [ ..., table, key, value, getmetatable(table), getmetatable(table)[".set"], getmetatable(table)[".set"][key], table ]
				p_lua_pushvalue(L, -5);     // 8 [ ..., table, key, value, getmetatable(table), getmetatable(table)[".set"], getmetatable(table)[".set"][key], table, value ]
				p_lua_call(L, 2, 0);        // 5 [ ..., table, key, value, getmetatable(table), getmetatable(table)[".set"] ]
				p_lua_pop(L, 2);            // 3 [ ..., table, key, value ]
				return 1;
			}
			else {
				p_lua_pop(L, 2);            // 4 [ ..., table, key, value, getmetatable(table) ]
			}
		}
		else {
			p_lua_pop(L, 1);                // 4 [ ..., table, key, value, getmetatable(table) ]
		}
	}
	p_lua_pop(L, 1);                        // 3 [ ..., table, key, value ]
	return 0;
}

enum class KeyKeyReturn : int {
	NONE = 0,
	KEY = 1,
	KEYKEY = 2,
};

// Expects           [ ..., mt, key ]
// End Stack:
//     NONE       => [ ... ]
//     KEY/KEYKEY => [ ..., mtVal ]
template<typename SingleAction>
KeyKeyReturn findKeyKeyOnBase(lua_State* L, const char* keykey, SingleAction action) {

	p_lua_pushstring(L, "tolua_base");                 // 3  [ ..., mt, key, "tolua_base" ]
	p_lua_rawget(L, LUA_REGISTRYINDEX);                // 3  [ ..., mt, key, registry["tolua_base"] ]

	p_lua_pushvalue(L, -3);                            // 4  [ ..., mt, key, registry["tolua_base"], mt ]
	p_lua_rawget(L, -2);                               // 4  [ ..., mt, key, registry["tolua_base"], registry["tolua_base"][mt] ]

	if (!p_lua_isnil(L, -1)) {
		p_lua_pushnil(L);                              // 5  [ ..., mt, key, registry["tolua_base"], registry["tolua_base"][mt], nil ]
		while (p_lua_next(L, -2)) {
			                                           // 6  [ ..., mt, key, registry["tolua_base"], registry["tolua_base"][mt], i, v ]
			p_lua_pushstring(L, "mt");                 // 7  [ ..., mt, key, registry["tolua_base"], registry["tolua_base"][mt], i, v, "mt" ]
			p_lua_rawget(L, -2);                       // 7  [ ..., mt, key, registry["tolua_base"], registry["tolua_base"][mt], i, v, baseMT ]

			if (action(-6)) {
				                                       // 8  [ ..., mt, key, registry["tolua_base"], registry["tolua_base"][mt], i, v, baseMT, retVal ]
				p_lua_insert(L, -8);                   // 8  [ ..., retVal, mt, key, registry["tolua_base"], registry["tolua_base"][mt], i, v, baseMT ]
				p_lua_pop(L, 7);                       // 1  [ ..., retVal ]
				return KeyKeyReturn::KEY;
			}

			p_lua_pushstring(L, keykey);               // 8  [ ..., mt, key, registry["tolua_base"], registry["tolua_base"][mt], i, v, baseMT, keykey ]
			p_lua_rawget(L, -2);                       // 8  [ ..., mt, key, registry["tolua_base"], registry["tolua_base"][mt], i, v, baseMT, baseMT[keykey] ]
			if (p_lua_istable(L, -1)) {

				p_lua_pushvalue(L, -7);                // 9  [ ..., mt, key, registry["tolua_base"], registry["tolua_base"][mt], i, v, baseMT, baseMT[keykey], key ]
				p_lua_rawget(L, -2);                   // 9  [ ..., mt, key, registry["tolua_base"], registry["tolua_base"][mt], i, v, baseMT, baseMT[keykey], baseMT[keykey][key] ]

				if (!p_lua_isnil(L, -1)) {
					p_lua_insert(L, -9);               // 9  [ ..., baseMT[keykey][key], mt, key, registry["tolua_base"], registry["tolua_base"][mt], i, v, baseMT, baseMT[keykey] ]
					p_lua_pop(L, 8);                   // 1  [ ..., baseMT[keykey][key] ]
					return KeyKeyReturn::KEYKEY;
				}
				else {
					p_lua_pop(L, 2);                   // 7  [ ..., mt, key, registry["tolua_base"], registry["tolua_base"][mt], i, v, baseMT ]
					p_lua_pushvalue(L, -6);            // 8  [ ..., mt, key, registry["tolua_base"], registry["tolua_base"][mt], i, v, baseMT, key ]
					if (KeyKeyReturn retVal = findKeyKeyOnBase(L, keykey, action); retVal != KeyKeyReturn::NONE) {
						                               // 7  [ ..., mt, key, registry["tolua_base"], registry["tolua_base"][mt], i, v, mtVal ]
						p_lua_insert(L, -7);           // 7  [ ..., mtVal, mt, key, registry["tolua_base"], registry["tolua_base"][mt], i, v ]
						p_lua_pop(L, 6);               // 1  [ ..., mtVal ]
						return retVal;
					}
					else {
						                               // 6  [ ..., mt, key, registry["tolua_base"], registry["tolua_base"][mt], i, v ]
						p_lua_pop(L, 1);               // 5  [ ..., mt, key, registry["tolua_base"], registry["tolua_base"][mt], i ]
					}
				}
			}
			else {
				p_lua_pop(L, 3);                       // 5  [ ..., mt, key, registry["tolua_base"], registry["tolua_base"][mt], i ]
			}
		}
	}

	p_lua_pop(L, 4);                                   // 0  [ ... ]
	return KeyKeyReturn::NONE;
}

// Expects           [ ..., table, key ]
// End Stack:
//     NONE       => [ ... ]
//     KEY/KEYKEY => [ ..., mtVal ]
template<typename SingleAction>
KeyKeyReturn findKeyKey(lua_State* L, const char* keykey, SingleAction action) {

	p_lua_getmetatable(L, -2);                                  // 3 [ ..., table, key, mt(table) ]
	if (action(-2)) {
		                                                        // 4 [ ..., table, key, mt(table), retVal ]
		p_lua_insert(L, -4);                                    // 4 [ ..., retVal, table, key, mt(table) ]
		p_lua_pop(L, 3);                                        // 1 [ ..., retVal ]
		return KeyKeyReturn::KEY;
	}

	p_lua_pushstring(L, keykey);                                // 4 [ ..., table, key, mt(table), keykey ]
	p_lua_rawget(L, -2);                                        // 4 [ ..., table, key, mt(table), mt(table)[keykey] ]
	if (p_lua_istable(L, -1)) {
		p_lua_pushvalue(L, -3);                                 // 5 [ ..., table, key, mt(table), mt(table)[keykey], key ]
		p_lua_rawget(L, -2);                                    // 5 [ ..., table, key, mt(table), mt(table)[keykey], mt(table)[keykey][key] ]
		if (!p_lua_isnil(L, -1)) {
			p_lua_insert(L, -5);                                // 5 [ ..., mt(table)[keykey][key], table, key, mt(table), mt(table)[keykey] ]
			p_lua_pop(L, 4);                                    // 1 [ ..., mt(table)[keykey][key] ]
			return KeyKeyReturn::KEYKEY;
		}
		else {
			p_lua_pop(L, 2);                                    // 3 [ ..., table, key, mt(table) ]
		}
	}
	else {
		p_lua_pop(L, 1);                                        // 3 [ ..., table, key, mt(table) ]
	}
	p_lua_pushvalue(L, -2);                                     // 4 [ ..., table, key, mt(table), key ]
	if (KeyKeyReturn retVal = findKeyKeyOnBase(L, keykey, action); retVal != KeyKeyReturn::NONE) {
		                                                        // 3 [ ..., table, key, mtVal ]
		p_lua_insert(L, -3);                                    // 3 [ ..., mtVal, table, key ]
		p_lua_pop(L, 2);                                        // 1 [ ..., mtVal ]
		return retVal;
	}
	else {
		                                                        // 2 [ ..., table, key ]
		p_lua_pop(L, 2);                                        // 0 [ ... ]
	}
	return KeyKeyReturn::NONE;
}

// Expects   [ ..., table, key, value ]
// End Stack [ ..., table, key, value ]
int callSetDynamic(lua_State* L) {

	p_lua_pushvalue(L, -3);             // 4 [ ..., table, key, value, table ]
	p_lua_pushvalue(L, -3);             // 5 [ ..., table, key, value, table, key ]

	if (findKeyKey(L, ".set", [&](size_t keyIndex){
		return 0;
	}) == KeyKeyReturn::KEYKEY) {
                                        // 4 [ ..., table, key, value, mtVal ]
		if (p_lua_iscfunction(L, -1)) {
			p_lua_pushvalue(L, -4);     // 5 [ ..., table, key, value, mtVal, table ]
			p_lua_pushvalue(L, -3);     // 6 [ ..., table, key, value, mtVal, table, value ]
			p_lua_call(L, 2, 0);        // 3 [ ..., table, key, value ]
			return 1;
		}
		else {
			p_lua_pop(L, 1);            // 3 [ ..., table, key, value ]
		}
	}
	return 0;
}

// Expects   [ ..., table, key ]
// End Stack:
//     0 => [ ..., table, key ]
//     1 => [ ..., table, key, retVal ]
int callGetDynamic(lua_State* L) {

	p_lua_pushvalue(L, -2);             // 3 [ ..., table, key, table ]
	p_lua_pushvalue(L, -2);             // 4 [ ..., table, key, table, key ]

	KeyKeyReturn retVal = findKeyKey(L, ".get", [&](int keyIndex) {
		                                // 1 [ ..., mt ]
		p_lua_pushvalue(L, keyIndex);   // 2 [ ..., mt, key ]
		p_lua_rawget(L, -2);            // 2 [ ..., mt, mt[key] ]

		if (p_lua_isnil(L, -1)) {
			p_lua_pop(L, 1);            // 1 [ ..., mt ]
			return 0;
		}

		return 1;
	});

	if (retVal == KeyKeyReturn::KEY) {
		                                // 3 [ ..., table, key, mtVal ]
		return 1;
	}
	else if (retVal == KeyKeyReturn::KEYKEY) {
			                            // 3 [ ..., table, key, mtVal ]
		if (p_lua_iscfunction(L, -1)) {
			p_lua_pushvalue(L, -3);     // 4 [ ..., table, key, mtVal, table ]
			p_lua_pushvalue(L, -3);     // 5 [ ..., table, key, mtVal, table, key ]
			p_lua_call(L, 2, 1);        // 3 [ ..., table, key, retVal ]
			return 1;
		}
		else {
			p_lua_pop(L, 1);            // 2 [ ..., table, key ]
		}
	}
	return 0;                           // 2 [ ..., table, key ]
}

// Expects [ table, key, value ]
int p_module_newindex_event(lua_State* L) {

	if (callSet(L)) {
		return 0;
	}

	//if (p_lua_getmetatable(L, 1) && p_lua_getmetatable(L, -1)) {
	//	                                   // [ table, key, value, ?, getmetatable(table), getmetatable(getmetatable(table)) ]
	//	p_lua_pushstring(L, "__newindex"); // [ table, key, value, getmetatable(table), getmetatable(getmetatable(table)), "__newindex" ]
	//	p_lua_rawget(L, -2);               // [ table, key, value, getmetatable(table), getmetatable(getmetatable(table)), getmetatable(getmetatable(table))["__newindex"] ]
	//	if (p_lua_isfunction(L, -1)) {
	//		p_lua_pushvalue(L, 1);         // [ table, key, value, getmetatable(table), getmetatable(getmetatable(table)), getmetatable(getmetatable(table))["__newindex"], table ]
	//		p_lua_pushvalue(L, 2);         // [ table, key, value, getmetatable(table), getmetatable(getmetatable(table)), getmetatable(getmetatable(table))["__newindex"], table, key ]
	//		p_lua_pushvalue(L, 3);         // [ table, key, value, getmetatable(table), getmetatable(getmetatable(table)), getmetatable(getmetatable(table))["__newindex"], table, key, value ]
	//		p_lua_call(L, 3, 0);           // [ table, key, value, getmetatable(table), getmetatable(getmetatable(table)) ]
	//	}
	//}
	//p_lua_settop(L, 3);
	//p_lua_rawset(L, -3);

	p_lua_rawset(L, -3); // [ table ]
	return 0;
}

// Expects [ table, key, value ]
int p_class_newindex_event(lua_State* L) {
	int t = p_lua_type(L, 1);
	if (t == LUA_TUSERDATA) {
		if (p_lua_isnumber(L, 2)) {
			callSetI(L);
			return 0;
		}
		else if (callSetDynamic(L)) {
			return 0;
		}
		p_storeatpeer(L, 1);
	}
	else if (t == LUA_TTABLE) {
		p_module_newindex_event(L);
	}
	return 0;
}

// Expects   [ table, key ]
// End Stack [ table, key, table[".get"], ..., retVal ]
// Returns   1
int p_module_index_event(lua_State* L) {

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

	p_lua_pushstring(L, ".get");        // 3 [ table, key, ".get" ]
	p_lua_rawget(L, -3);                // 3 [ table, key, table[".get"] ]
	if (p_lua_istable(L, -1)) {
		p_lua_pushvalue(L, 2);          // 4 [ table, key, table[".get"], key ]
		p_lua_rawget(L, -2);            // 4 [ table, key, table[".get"], table[".get"][key] ]
		if (p_lua_iscfunction(L, -1)) {
			p_lua_call(L, 0, 1);        // 3 [ table, key, table[".get"], retVal ]
			return 1;
		}
		else if (p_lua_istable(L, -1)) {
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
	if (p_lua_getmetatable(L, 1)) {     // TODO: Metatable
									    // 4 [ table, key, table[".get"], ..., mt(table) ]
		p_lua_pushstring(L, "__index"); // 5 [ table, key, table[".get"], ..., mt(table), "__index" ]
		p_lua_rawget(L, -2);            // 5 [ table, key, table[".get"], ..., mt(table), mt(table)["__index"] ]
		p_lua_pushvalue(L, 1);          // 6 [ table, key, table[".get"], ..., mt(table), mt(table)["__index"], table ]
		p_lua_pushvalue(L, 2);          // 7 [ table, key, table[".get"], ..., mt(table), mt(table)["__index"], table, key ]
		if (p_lua_isfunction(L, -1)) {
			p_lua_call(L, 2, 1);        // 5 [ table, key, table[".get"], ..., mt(table), retVal ]
			return 1;
		}
		else if (p_lua_istable(L, -1)) {
			p_lua_gettable(L, -3);      // 7 [ table, key, table[".get"], ..., mt(table), mt(table)["__index"], table, mt(table)["__index"][key] ]
			return 1;
		}
	}
	p_lua_pushnil(L);                   // 4 [ table, key, table[".get"], ..., nil ]
	return 1;
}

// Expects   [ table, key ]
// End Stack [ table, key, ..., retVal ]
// Returns   1
int p_class_index_event(lua_State* L) {
	int t = p_lua_type(L, 1);
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

		p_lua_pushstring(L, "tolua_peer");             // 3 [ table, key, "tolua_peer" ]
		p_lua_rawget(L, LUA_REGISTRYINDEX);            // 3 [ table, key, registry["tolua_peer"] ]
		p_lua_pushvalue(L, 1);                         // 4 [ table, key, registry["tolua_peer"], table ]
		p_lua_rawget(L, -2);                           // 4 [ table, key, registry["tolua_peer"], registry["tolua_peer"][table] ]
		if (p_lua_istable(L, -1)) {
			p_lua_pushvalue(L, 2);                     // 5 [ table, key, registry["tolua_peer"], registry["tolua_peer"][table], key ]
			p_lua_gettable(L, -2);                     // 5 [ table, key, registry["tolua_peer"], registry["tolua_peer"][table], registry["tolua_peer"][table][key] ]
			if (!p_lua_isnil(L, -1)) {
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

		p_lua_settop(L, 2);                            // 2 [ table, key ]

		if (callGetDynamic(L)) {
			return 1;
		}

		/*p_lua_pushvalue(L, 1);                         // 3 [ table, key, table -> curT ]
		while (p_lua_getmetatable(L, -1)) {            // TODO: Metatable Base
													   // 4 [ table, key, curT, mt(curT) ]
			p_lua_remove(L, -2);                       // 3 [ table, key, mt(curT) ]
			if (p_lua_isnumber(L, 2)) {
				p_lua_pushstring(L, ".geti");          // 4 [ table, key, mt(curT), ".geti" ]
				p_lua_rawget(L, -2);                   // 4 [ table, key, mt(curT), mt(curT)[".geti"] ]
				if (p_lua_isfunction(L, -1)) {
					p_lua_pushvalue(L, 1);             // 5 [ table, key, mt(curT), mt(curT)[".geti"], table ]
					p_lua_pushvalue(L, 2);             // 6 [ table, key, mt(curT), mt(curT)[".geti"], table, key ]
					p_lua_call(L, 2, 1);               // 4 [ table, key, mt(curT), retVal ]
					return 1;
				}
			}
			else {
				p_lua_pushvalue(L, 2);                 // 4 [ table, key, mt(curT), key ]
				p_lua_rawget(L, -2);                   // 4 [ table, key, mt(curT), mt(curT)[key] ]
				if (!p_lua_isnil(L, -1)) {
					return 1;
				}
				else {
					p_lua_pop(L, 1);                   // 3 [ table, key, mt(curT) ]
				}
				p_lua_pushstring(L, ".get");           // 4 [ table, key, mt(curT), ".get" ]
				p_lua_rawget(L, -2);                   // 4 [ table, key, mt(curT), mt(curT)[".get"] ]
				if (p_lua_istable(L, -1)) {
					p_lua_pushvalue(L, 2);             // 5 [ table, key, mt(curT), mt(curT)[".get"], key ]
					p_lua_rawget(L, -2);               // 5 [ table, key, mt(curT), mt(curT)[".get"], mt(curT)[".get"][key] ]
					if (p_lua_iscfunction(L, -1)) {
						p_lua_pushvalue(L, 1);         // 6 [ table, key, mt(curT), mt(curT)[".get"], mt(curT)[".get"][key], table ]
						p_lua_pushvalue(L, 2);         // 7 [ table, key, mt(curT), mt(curT)[".get"], mt(curT)[".get"][key], table, key ]
						p_lua_call(L, 2, 1);           // 5 [ table, key, mt(curT), mt(curT)[".get"], retVal ]
						return 1;
					}
					else if (p_lua_istable(L, -1)) {
						void* u = *((void**)p_lua_touserdata(L, 1));
						p_lua_newtable(L);             // 6 [ table, key, mt(curT), mt(curT)[".get"], mt(curT)[".get"][key], newTable ]
						p_lua_pushstring(L, ".self");  // 7 [ table, key, mt(curT), mt(curT)[".get"], mt(curT)[".get"][key], newTable, ".self" ]
						p_lua_pushlightuserdata(L, u); // 8 [ table, key, mt(curT), mt(curT)[".get"], mt(curT)[".get"][key], newTable, ".self", lud(ud2ptr(table)) ]
						p_lua_rawset(L, -3);           // 6 [ table, key, mt(curT), mt(curT)[".get"], mt(curT)[".get"][key], newTable ]
						p_lua_insert(L, -2);           // 6 [ table, key, mt(curT), mt(curT)[".get"], newTable, mt(table)[".get"][key] ]
						p_lua_setmetatable(L, -2);     // 5 [ table, key, mt(curT), mt(curT)[".get"], newTable ]
						p_lua_pushvalue(L, -1);        // 6 [ table, key, mt(curT), mt(curT)[".get"], newTable, newTable ]
						p_lua_pushvalue(L, 2);         // 7 [ table, key, mt(curT), mt(curT)[".get"], newTable, newTable, key]
						p_lua_insert(L, -2);           // 7 [ table, key, mt(curT), mt(curT)[".get"], newTable, key, newTable]
						p_storeatpeer(L, 1);           // 5 [ table, key, mt(curT), mt(curT)[".get"], newTable ]
						return 1;
					}
				}
			}
			p_lua_settop(L, 3);                        // 3 [ table, key, mt(table) -> curT ]
		}*/

		p_lua_pushnil(L);                              // 4 [ table, key, ..., nil ]
		return 1;
	}
	else if (t == LUA_TTABLE) {
		p_module_index_event(L);                       // 4 [ table, key, table[".get"], ..., retVal ]
		return 1;
	}
	p_lua_pushnil(L);                                  // 3 [ table, key, nil ]
	return 1;
}

// Sets registry["tolua_super"][getmetatable(name)][base] = true
// All superclasses mapped under registry["tolua_super"][getmetatable(base)] are also copied to name's entry.
// registry["tolua_super"] used by:
//     lua_isusertype()
//     tolua_pushusertype()
static void p_mapsuper(lua_State* L, const char* name, const char* base) {

	////////////////////////////////////////////////////////////////////
	// registry["tolua_super"][tolua_getmetatable(name)][base] = true //
	////////////////////////////////////////////////////////////////////

	p_lua_pushstring(L, "tolua_super"); // 1 [ "tolua_super" ]
	p_lua_rawget(L, LUA_REGISTRYINDEX); // 1 [ registry["tolua_super"] ]
	p_tolua_getmetatable(L, name);      // 2 [ registry["tolua_super"], tolua_getmetatable(name) ] // TODO: Metatable
	p_lua_rawget(L, -2);                // 2 [ registry["tolua_super"], registry["tolua_super"][tolua_getmetatable(name)] ]
	if (p_lua_isnil(L, -1)) {
		p_lua_pop(L, 1);                // 1 [ registry["tolua_super"] ]
		p_lua_newtable(L);              // 2 [ registry["tolua_super"], newtable ]
		p_tolua_getmetatable(L, name);  // 3 [ registry["tolua_super"], newtable, tolua_getmetatable(name) ] // TODO: Metatable
		p_lua_pushvalue(L, -2);         // 4 [ registry["tolua_super"], newtable, tolua_getmetatable(name), newtable ]
		p_lua_rawset(L, -4);            // 2 [ registry["tolua_super"], newtable ]
	}
	                                    // 2 [ registry["tolua_super"], registry["tolua_super"][tolua_getmetatable(name)] ]
	p_lua_pushstring(L, base);          // 3 [ registry["tolua_super"], registry["tolua_super"][tolua_getmetatable(name)], base ]
	p_lua_pushboolean(L, 1);            // 4 [ registry["tolua_super"], registry["tolua_super"][tolua_getmetatable(name)], base, true ]
	p_lua_rawset(L, -3);                // 2 [ registry["tolua_super"], registry["tolua_super"][tolua_getmetatable(name)] ]

	//////////////////////////////////////////////////////////////////////
	// local t = registry["tolua_super"][tolua_getmetatable(base)]      //
	// if type(t) == "table" then                                       //
	//     for k, v in pairs(t) do                                      //
	//         registry["tolua_super"][tolua_getmetatable(name)][k] = v //
	//     end                                                          //
	// end                                                              //
	//////////////////////////////////////////////////////////////////////

	p_tolua_getmetatable(L, base);      // 3 [ registry["tolua_super"], registry["tolua_super"][tolua_getmetatable(name)], tolua_getmetatable(base) ] // TODO: Metatable
	p_lua_rawget(L, -3);                // 3 [ registry["tolua_super"], registry["tolua_super"][tolua_getmetatable(name)], registry["tolua_super"][tolua_getmetatable(base)] ]
	if (p_lua_istable(L, -1)) {
		p_lua_pushnil(L);               // 4 [ registry["tolua_super"], registry["tolua_super"][tolua_getmetatable(name)], registry["tolua_super"][tolua_getmetatable(base)], nil ]
		while (p_lua_next(L, -2) != 0) {
			                            // 5 [ registry["tolua_super"], registry["tolua_super"][tolua_getmetatable(name)], registry["tolua_super"][tolua_getmetatable(base)], k, v ]
			p_lua_pushvalue(L, -2);     // 6 [ registry["tolua_super"], registry["tolua_super"][tolua_getmetatable(name)], registry["tolua_super"][tolua_getmetatable(base)], k, v, k ]
			p_lua_insert(L, -2);        // 6 [ registry["tolua_super"], registry["tolua_super"][tolua_getmetatable(name)], registry["tolua_super"][tolua_getmetatable(base)], k, k, v ]
			p_lua_rawset(L, -5);        // 4 [ registry["tolua_super"], registry["tolua_super"][tolua_getmetatable(name)], registry["tolua_super"][tolua_getmetatable(base)], k]
		}
		                                // 3 [ registry["tolua_super"], registry["tolua_super"][tolua_getmetatable(name)], registry["tolua_super"][tolua_getmetatable(base)] ]
	}
	p_lua_pop(L, 3);                    // 0 [ ]
}

// Set name's metatable-metatable to base metatable
static void p_mapinheritance(lua_State* L, const char* name, const char* base) {

	/////////////////////////////////////////////////////////////////////////////////
	// setmetatable(getmetatable(name), getmetatable(base or "tolua_commonclass")) //
	/////////////////////////////////////////////////////////////////////////////////

	p_tolua_getmetatable(L, name);                    // 1 [ tolua_getmetatable(name) ] // TODO: Metatable
	if (base && *base) {
		p_tolua_getmetatable(L, base);                // 2 [ tolua_getmetatable(name), tolua_getmetatable(base) ] // TODO: Metatable
	}
	else {
		p_tolua_getmetatable(L, "tolua_commonclass"); // 2 [ tolua_getmetatable(name), tolua_getmetatable("tolua_commonclass") ] // TODO: Metatable
	}
	p_lua_setmetatable(L, -2);                        // 1 [ tolua_getmetatable(name) ]
	p_lua_pop(L, 1);                                  // 0 [ ]
}

// Expects   [ ..., key ]
// End Stack [ ..., t ]
static void getOrCreateTable(lua_State* L, int tableI) {
	tableI = p_lua_absindex(L, tableI);
	p_lua_pushvalue(L, -1);      // 2 [ ..., key, key ]
	p_lua_rawget(L, tableI);     // 2 [ ..., key, table[key] ]
	if (!p_lua_istable(L, -1)) {
		p_lua_pop(L, 1);         // 1 [ ..., key ]
		p_lua_newtable(L);       // 2 [ ..., key, newT ]
		p_lua_insert(L, -2);     // 2 [ ..., newT, key ]
		p_lua_pushvalue(L, -2);  // 3 [ ..., newT, key, newT ]
		p_lua_rawset(L, tableI); // 1 [ ..., newT -> t ]
	}
	else {
		p_lua_remove(L, -2);     // 1 [ ..., table[key] -> t ]
	}
}

// Expects   [ ..., key, default ]
// End Stack [ ..., retVal ]
static void getOrCreate(lua_State* L, int tableI) {
	tableI = p_lua_absindex(L, tableI);
	p_lua_pushvalue(L, -2);      // 3 [ ..., key, default, key ]
	p_lua_rawget(L, tableI);     // 3 [ ..., key, default, table[key] ]
	if (p_lua_isnil(L, -1)) {
		p_lua_pop(L, 1);         // 2 [ ..., key, default ]
		p_lua_pushvalue(L, -1);  // 3 [ ..., key, default, default ]
		p_lua_insert(L, -3);     // 3 [ ..., default, key, default ]
		p_lua_rawset(L, tableI); // 1 [ ..., default -> retVal ]
	}
	else {
		p_lua_insert(L, -3);     // 3 [ ..., table[key], key, default ]
		p_lua_pop(L, 2);         // 1 [ ..., table[key] -> retVal ]
	}
}

// Expects   [ ... ]
// End Stack [ ..., t ]
static void getOrCreateTableI(lua_State* L, int tableI, int i) {
	tableI = p_lua_absindex(L, tableI);
	p_lua_rawgeti(L, tableI, i);     // 1 [ ..., table[i] ]
	if (!p_lua_istable(L, -1)) {
		p_lua_pop(L, 1);             // 0 [ ... ]
		p_lua_newtable(L);           // 1 [ ..., newT ]
		p_lua_pushvalue(L, -1);      // 2 [ ..., newT, newT ]
		p_lua_rawseti(L, tableI, i); // 1 [ ..., newT -> t ]
	}
}

static void mapBases(lua_State* L, const char* name, std::initializer_list<const char*>& bases) {

	p_lua_pushstring(L, "tolua_base");       // 1 [ ..., "tolua_base" ]
	p_lua_rawget(L, LUA_REGISTRYINDEX);      // 1 [ ..., registry["tolua_base"] ]

	p_tolua_getmetatable(L, name);           // 2 [ ..., registry["tolua_base"], mt(name) ]
	getOrCreateTable(L, -2);                 // 2 [ ..., registry["tolua_base"], registry["tolua_base"][mt(name)] -> baseT ]

	std::unordered_map<const char*, uintptr_t>& offsets = baseclassOffsets[name];
	size_t i{ 0 };
	for (const char* base : bases) {

		getOrCreateTableI(L, -1, ++i);       // 3 [ ..., registry["tolua_base"], baseT, baseT[i] ]

		p_lua_pushstring(L, "mt");           // 4 [ ..., registry["tolua_base"], baseT, baseT[i], "mt" ]
		p_tolua_getmetatable(L, base);       // 5 [ ..., registry["tolua_base"], baseT, baseT[i], "mt", mt(base) ]
		p_lua_rawset(L, -3);                 // 3 [ ..., registry["tolua_base"], baseT, baseT[i] ]

		p_lua_pop(L, 1);                     // 2 [ ..., registry["tolua_base"], baseT ]
	}

	p_lua_pushstring(L, "tolua_base_map");   // 3 [ ..., registry["tolua_base"], baseT, "tolua_base_map" ]
	p_lua_rawget(L, LUA_REGISTRYINDEX);      // 3 [ ..., registry["tolua_base"], baseT, registry["tolua_base_map"] ]

	p_tolua_getmetatable(L, name);           // 4 [ ..., registry["tolua_base"], baseT, registry["tolua_base_map"], mt(name) ]
	getOrCreateTable(L, -2);                 // 4 [ ..., registry["tolua_base"], baseT, registry["tolua_base_map"], registry["tolua_base_map"][mt(name)] -> baseMapT ]

	// base, offset
	std::vector<std::pair<const char*, uintptr_t>> toProcess{};
	toProcess.emplace_back(name, 0);

	while (!toProcess.empty()) {

		std::pair<const char*, uintptr_t>& pair = toProcess.back();
		const char* base = pair.first;
		uintptr_t offset = pair.second;
		toProcess.pop_back();

		p_lua_pushstring(L, base);           // 5 [ ..., registry["tolua_base"], baseT, registry["tolua_base_map"], baseMapT, base ]
		p_lua_pushinteger(L, offset);        // 6 [ ..., registry["tolua_base"], baseT, registry["tolua_base_map"], baseMapT, base, offset ]
		p_lua_rawset(L, -3);                 // 4 [ ..., registry["tolua_base"], baseT, registry["tolua_base_map"], baseMapT ]

		if (baseclassOffsets.contains(base)) {
			for (std::pair<const char*, uintptr_t>&& basePair : baseclassOffsets[base]) {
				toProcess.emplace_back(basePair.first, offset + basePair.second);
			}
		}
	}

	p_lua_pop(L, 4);                         // 0 [ ... ]
}

// Expects   [ ..., module ]
// End Stack [ ..., module ]
void p_tolua_cclass(lua_State* L, const char* lname, const char* name, std::initializer_list<const char*>&& bases, lua_CFunction col) {

	const char* base = bases.size() > 0 ? *bases.begin() : "";
	char cname[128] = "const ";
	char cbase[128] = "const ";
	strncat(cname, name, 120);
	strncat(cbase, base, 120);

	p_mapinheritance(L, name, base);
	p_mapinheritance(L, cname, name);

	p_mapsuper(L, cname, cbase);
	p_mapsuper(L, name, base);

	mapBases(L, name, bases);

	///////////////////////////////////////////////
	// getmetatable(name)[".collector"] = col    //
	// module[lname] = getmetatable(name)        //
	///////////////////////////////////////////////

	p_lua_pushstring(L, lname);        // [ ..., module, lname ]
	p_tolua_getmetatable(L, name);     // [ ..., module, lname, getmetatable(name) ]
	p_lua_pushstring(L, ".collector"); // [ ..., module, lname, getmetatable(name), ".collector" ]
	p_lua_pushcfunction(L, col);       // [ ..., module, lname, getmetatable(name), ".collector", col ]
	p_lua_rawset(L, -3);               // [ ..., module, lname, getmetatable(name) ]
	p_lua_rawset(L, -3);               // [ ..., module ]
}

void p_tolua_cclass_translate(lua_State* L, const char* lname, const char* name, const char* base, lua_CFunction col) {
	p_tolua_cclass(L, lname, name, { base }, col);
}

void* tolua_tousertype_dynamic(lua_State* L, int index, void* def, const char* targetUsertype) {
	if (p_lua_gettop(L) < abs(index)) {
		return def;
	}
	else {

		index = p_lua_absindex(L, index);

		void** u = reinterpret_cast<void**>(p_lua_touserdata(L, index));
		if (u == nullptr) {
			return u;
		}

		void* ptr = *u;

		p_lua_pushstring(L, "tolua_base_map"); // 1 [ ...,"tolua_base_map" ]
		p_lua_rawget(L, LUA_REGISTRYINDEX);    // 1 [ ..., registry["tolua_base_map"] ]

		if (!p_lua_getmetatable(L, index)) {
			p_lua_pop(L, 1);                   // 0 [ ... ]
			return ptr;
		}
		                                       // 2 [ ..., registry["tolua_base_map"], mt ]
		p_lua_rawget(L, -2);                   // 2 [ ..., registry["tolua_base_map"], registry["tolua_base_map"][mt] ]

		if (p_lua_isnil(L, -1)) {
			p_lua_pop(L, 2);                   // 0 [ ... ]
			return ptr;
		}

		p_lua_pushstring(L, targetUsertype);   // 3 [ ..., registry["tolua_base_map"], registry["tolua_base_map"][mt], targetUsertype ]
		p_lua_rawget(L, -2);                   // 3 [ ..., registry["tolua_base_map"], registry["tolua_base_map"][mt], registry["tolua_base_map"][mt][targetUsertype] ]

		lua_Integer offset{ 0 };
		if (p_lua_isnumber(L, -1)) {
			offset = p_lua_tointeger(L, -1);
		}

		p_lua_pop(L, 3);                       // 0 [ ... ]
		return reinterpret_cast<void*>(reinterpret_cast<uintptr_t>(ptr) + offset);
	}
}
