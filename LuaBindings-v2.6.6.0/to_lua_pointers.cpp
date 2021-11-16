
#include "to_lua_pointers.h"
#include "lua_pointers.h"

//////////////
// Pointers //
//////////////

type_free* p_free;
type_malloc* p_malloc;
type_tolua_beginmodule* p_tolua_beginmodule;
type_tolua_cclass* p_tolua_cclass;
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
type_tolua_open* p_tolua_open;
type_tolua_pushboolean* p_tolua_pushboolean;
type_tolua_pushnumber* p_tolua_pushnumber;
type_tolua_pushstring* p_tolua_pushstring;
type_tolua_tonumber* p_tolua_tonumber;
type_tolua_tostring* p_tolua_tostring;
type_tolua_tousertype* p_tolua_tousertype;
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

void tolua_pushusertypestring(lua_State* L, int lo) {
	int tag = p_lua_type(L, lo);
	if (tag == LUA_TUSERDATA && p_lua_getmetatable(L, lo)) {
		p_lua_rawget(L, LUA_REGISTRYINDEX);
		if (p_lua_type(L, -1) == LUA_TSTRING) {
			return;
		}
		else {
			p_lua_pop(L, 1);
		}
	}
	p_lua_pushnil(L);
}

///////////////////////////////////////////////////
// Overrides (engine needs these to be replaced) //
///////////////////////////////////////////////////

// The normal implementation of this interprets "0" as "true"!
int p_tolua_toboolean(lua_State* L, int narg, int def)
{
	if (p_lua_gettop(L) < abs(narg))
		return def;

	if (p_lua_isnumber(L, narg))
		return p_lua_tonumberx(L, narg, nullptr) != 0;

	return p_lua_toboolean(L, narg);
}

// Expects [ userdata, key, value ]
// Note: This seems like a broken implementation
void storeatpeer(lua_State* L, int index) {
	p_lua_pushstring(L, "tolua_peer");  // [ userdata, key, value, "tolua_peer" ]
	p_lua_rawget(L, LUA_REGISTRYINDEX); // [ userdata, key, value, registry["tolua_peer"] ]
	p_lua_pushvalue(L, index);          // [ userdata, key, value, registry["tolua_peer"], stack[index] ]
	p_lua_rawget(L, -2);                // [ userdata, key, value, registry["tolua_peer"][stack[index]] ]
	if (!p_lua_istable(L, -1)) {
		p_lua_pop(L, 1);                // [ userdata, key, value ]
		p_lua_newtable(L);              // [ userdata, key, value, t ]
		p_lua_pushvalue(L, index);      // [ userdata, key, value, t, stack[index] ]
		p_lua_pushvalue(L, -2);         // [ userdata, key, value, t, stack[index], t ]
		p_lua_settable(L, -4);          // [ userdata, key, value, t ]
	}
	p_lua_insert(L, -4);                // [ registry["tolua_peer"][stack[index]], userdata, key, value ]
	p_lua_pop(L, 1);                    // [ registry["tolua_peer"][stack[index]], userdata, key ]
	p_lua_rawset(L, -3);                // [ registry["tolua_peer"][stack[index]], userdata, key ]
	p_lua_pop(L, 1);
}

// Expects [ ..., table, key, value ]
void callSetI(lua_State* L) {
	p_lua_pushvalue(L, -3);             // [ ..., table, key, value, table ]
	while (p_lua_getmetatable(L, -1)) {
		                                // [ ..., table, key, value, table, metatable(table) ]
		p_lua_remove(L, -2);            // [ ..., table, key, value, metatable(table) ]
		p_lua_pushstring(L, ".seti");   // [ ..., table, key, value, metatable(table), ".seti" ]
		p_lua_rawget(L, -2);            // [ ..., table, key, value, metatable(table), metatable(table)[".seti"] ]
		if (p_lua_isfunction(L, -1)) {
			p_lua_pushvalue(L, -5);     // [ ..., table, key, value, metatable(table), metatable(table)[".seti"], table ]
			p_lua_pushvalue(L, -5);     // [ ..., table, key, value, metatable(table), metatable(table)[".seti"], table, key ]
			p_lua_pushvalue(L, -5);     // [ ..., table, key, value, metatable(table), metatable(table)[".seti"], table, key, value ]
			p_lua_call(L, 3, 0);        // [ ..., table, key, value, metatable(table) ]
			p_lua_pop(L, 1);            // [ ..., table, key, value ]
			return;
		}
		p_lua_pop(L, 1);                // [ ..., table, key, value, metatable(table) ]
	}
	p_lua_pop(L, 1);                    // [ ..., table, key, value ]
	p_tolua_error(L, "Attempt to set indexed value on an invalid operand", NULL);
}

// Expects [ ..., table, key, value ]
int callSet(lua_State* L) {
	p_lua_pushvalue(L, -3);                 // [ ..., table, key, value, table ]
	while (p_lua_getmetatable(L, -1)) {
		                                    // [ ..., table, key, value, table, metatable(table) ]
		p_lua_remove(L, -2);                // [ ..., table, key, value, metatable(table) ]
		p_lua_pushstring(L, ".set");        // [ ..., table, key, value, metatable(table), ".set" ]
		p_lua_rawget(L, -2);                // [ ..., table, key, value, metatable(table), metatable(table)[".set"] ]
		if (p_lua_istable(L, -1)) {
			p_lua_pushvalue(L, -4);         // [ ..., table, key, value, metatable(table), metatable(table)[".set"], key ]
			p_lua_rawget(L, -2);            // [ ..., table, key, value, metatable(table), metatable(table)[".set"], metatable(table)[".set"][key] ]
			if (p_lua_iscfunction(L, -1)) {
				p_lua_pushvalue(L, -6);     // [ ..., table, key, value, metatable(table), metatable(table)[".set"], metatable(table)[".set"][key], table ]
				p_lua_pushvalue(L, -5);     // [ ..., table, key, value, metatable(table), metatable(table)[".set"], metatable(table)[".set"][key], table, value ]
				p_lua_call(L, 2, 0);        // [ ..., table, key, value, metatable(table), metatable(table)[".set"] ]
				p_lua_pop(L, 2);            // [ ..., table, key, value ]
				return 1;
			}
			else {
				p_lua_pop(L, 2);            // [ ..., table, key, value, metatable(table) ]
			}
		}
		else {
			p_lua_pop(L, 1);                // [ ..., table, key, value, metatable(table) ]
		}
	}
	p_lua_pop(L, 1);                        // [ ..., table, key, value ]
	return 0;
}

// Expects [ table, key, value ]
int module_newindex_event(lua_State* L) {

	if (callSet(L))
		return 0;
	
	//if (p_lua_getmetatable(L, 1) && p_lua_getmetatable(L, -1)) {
	//	                                   // [ table, key, value, ?, metatable(table), metatable(metatable(table)) ]
	//	p_lua_pushstring(L, "__newindex"); // [ table, key, value, metatable(table), metatable(metatable(table)), "__newindex" ]
	//	p_lua_rawget(L, -2);               // [ table, key, value, metatable(table), metatable(metatable(table)), metatable(metatable(table))["__newindex"] ]
	//	if (p_lua_isfunction(L, -1)) {
	//		p_lua_pushvalue(L, 1);         // [ table, key, value, metatable(table), metatable(metatable(table)), metatable(metatable(table))["__newindex"], table ]
	//		p_lua_pushvalue(L, 2);         // [ table, key, value, metatable(table), metatable(metatable(table)), metatable(metatable(table))["__newindex"], table, key ]
	//		p_lua_pushvalue(L, 3);         // [ table, key, value, metatable(table), metatable(metatable(table)), metatable(metatable(table))["__newindex"], table, key, value ]
	//		p_lua_call(L, 3, 0);           // [ table, key, value, metatable(table), metatable(metatable(table)) ]
	//	}
	//}
	//p_lua_settop(L, 3);
	//p_lua_rawset(L, -3);

	p_lua_rawset(L, -3); // [ table ]
	return 0;
}

// Expects [ table, key, value ]
int class_newindex_event(lua_State* L) {
	int t = p_lua_type(L, 1);
	if (t == LUA_TUSERDATA) {
		if (p_lua_isnumber(L, 2)) {
			callSetI(L);
			return 0;
		}
		else if (callSet(L)) {
			return 0;
		}
		storeatpeer(L, 1);
	}
	else if (t == LUA_TTABLE) {
		module_newindex_event(L);
	}
	return 0;
}
