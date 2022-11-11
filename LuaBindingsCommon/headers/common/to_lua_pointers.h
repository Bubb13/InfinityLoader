
#pragma once

#include <string>

#include "tolua/tolua.h"
#include "lua_pointers.h"

/////////////
// Special //
/////////////

extern bool NULL_POINTER;

//////////////
// Pointers //
//////////////

typedef void(__cdecl type_free)(void* memblock);
extern type_free* p_free;

typedef void* (__cdecl type_malloc)(size_t size);
extern type_malloc* p_malloc;

typedef void type_tolua_beginmodule(lua_State* L, const char* name);
extern type_tolua_beginmodule* p_tolua_beginmodule;

typedef int type_tolua_bnd_cast(lua_State* L);
extern type_tolua_bnd_cast* p_tolua_bnd_cast;

typedef int type_tolua_bnd_release(lua_State* L);
extern type_tolua_bnd_release* p_tolua_bnd_release;

typedef int type_tolua_bnd_releaseownership(lua_State* L);
extern type_tolua_bnd_releaseownership* p_tolua_bnd_releaseownership;

typedef int type_tolua_bnd_takeownership(lua_State* L);
extern type_tolua_bnd_takeownership* p_tolua_bnd_takeownership;

typedef int type_tolua_bnd_type(lua_State* L);
extern type_tolua_bnd_type* p_tolua_bnd_type;

typedef void type_tolua_constant(lua_State* L, const char* name, double value);
extern type_tolua_constant* p_tolua_constant;

typedef void type_tolua_endmodule(lua_State* L);
extern type_tolua_endmodule* p_tolua_endmodule;

typedef void type_tolua_error(lua_State* L, const char* msg, tolua_Error* err);
extern type_tolua_error* p_tolua_error;

typedef void type_tolua_function(lua_State* L, const char* name, lua_CFunction func);
extern type_tolua_function* p_tolua_function;

typedef void type_tolua_getmetatable(lua_State* L, const char* name);
extern type_tolua_getmetatable* p_tolua_getmetatable;

typedef int type_tolua_isboolean(lua_State* L, int lo, int def, tolua_Error* err);
extern type_tolua_isboolean* p_tolua_isboolean;

typedef int type_tolua_isnumber(lua_State* L, int lo, int def, tolua_Error* err);
extern type_tolua_isnumber* p_tolua_isnumber;

typedef int type_tolua_isstring(lua_State* L, int lo, int def, tolua_Error* err);
extern type_tolua_isstring* p_tolua_isstring;

typedef int type_tolua_isusertype(lua_State* L, int lo, const char* type, int def, tolua_Error* err);
extern type_tolua_isusertype* p_tolua_isusertype;

typedef void type_tolua_module(lua_State* L, const char* name, int hasvar);
extern type_tolua_module* p_tolua_module;

typedef void type_tolua_newmetatable(lua_State* L, const char* name);
extern type_tolua_newmetatable* p_tolua_newmetatable;

typedef void type_tolua_pushboolean(lua_State* L, int value);
extern type_tolua_pushboolean* p_tolua_pushboolean;

typedef void type_tolua_pushnumber(lua_State* L, double value);
extern type_tolua_pushnumber* p_tolua_pushnumber;

typedef void type_tolua_pushstring(lua_State* L, const char* value);
extern type_tolua_pushstring* p_tolua_pushstring;

typedef const char* type_tolua_tostring(lua_State* L, int narg, const char* def);
extern type_tolua_tostring* p_tolua_tostring;

typedef void* type_tolua_tousertype(lua_State* L, int narg, void* def);
extern type_tolua_tousertype* p_tolua_tousertype;

typedef const char* type_tolua_typename(lua_State* L, int lo);
extern type_tolua_typename* p_tolua_typename;

typedef void type_tolua_usertype(lua_State* L, const char* type);
extern type_tolua_usertype* p_tolua_usertype;

typedef void type_tolua_variable(lua_State* L, const char* name, lua_CFunction get, lua_CFunction set);
extern type_tolua_variable* p_tolua_variable;

////////////
// Custom //
////////////

void tolua_cclass_translate(lua_State* L, const char* lname, const char* name, const char* base, lua_CFunction col);
bool tolua_function_toboolean(lua_State *const L, const int narg, const char *const functionName);
char tolua_function_tochar(lua_State *const L, const int narg, const char *const functionName);
lua_Integer tolua_function_tointeger(lua_State *const L, const int narg, const char *const functionName);
lua_Number tolua_function_tonumber(lua_State *const L, const int narg, const char *const functionName);
const char* tolua_function_tostring(lua_State *const L, const int narg, const char *const functionName);
void tolua_pushusertype_nocast(lua_State* L, void* value, const char* type);
void tolua_pushusertypepointer(lua_State* L, void* value, const char* type);
void tolua_pushusertypestring(lua_State* L, int lo);
bool tolua_setter_toboolean(lua_State *const L, const char *const variableName);
lua_Integer tolua_setter_tointeger(lua_State *const L, const char *const variableName);
lua_Number tolua_setter_tonumber(lua_State *const L, const char *const variableName);
void* tolua_tousertype_dynamic(lua_State* L, int narg, void* def, const char* targetUsertype);

///////////////////////////////////////////////////
// Overrides (engine needs these to be replaced) //
///////////////////////////////////////////////////

int p_class_index_event(lua_State* L);
int p_class_newindex_event(lua_State* L);
int p_module_index_event(lua_State* L);
int p_module_newindex_event(lua_State* L);
// tolua_cclass_translate() actually overrides the engine function, though this still needs a declaration for use in EEexLua_generated.cpp
void p_tolua_cclass(lua_State* L, const char* lname, const char* name, std::initializer_list<const char*>&& bases, lua_CFunction col);
void p_tolua_open(lua_State* L);

/////////////////////////////////////////////
// Redefine certain functions so that they //
// point to the in-exe versions.           //
/////////////////////////////////////////////

#define lua_pushlstring p_lua_pushlstring
#define lua_toboolean p_lua_toboolean
#define lua_tointeger p_lua_tointeger
#define lua_tointegerx p_lua_tointegerx
#define lua_tonumber p_lua_tonumber
#define lua_tonumberx p_lua_tonumberx
#define lua_touserdata p_lua_touserdata
#define luaL_error p_luaL_error
#define tolua_beginmodule p_tolua_beginmodule
#define tolua_cclass p_tolua_cclass
#define tolua_constant p_tolua_constant
#define tolua_endmodule p_tolua_endmodule
#define tolua_error p_tolua_error
#define tolua_function p_tolua_function
#define tolua_module p_tolua_module
#define tolua_open p_tolua_open
#define tolua_pushboolean p_tolua_pushboolean
#define tolua_pushnumber p_tolua_pushnumber
#define tolua_pushstring p_tolua_pushstring
#define tolua_pushusertype tolua_pushusertype_nocast
#define tolua_toboolean p_tolua_toboolean
#define tolua_tonumber p_tolua_tonumber
#define tolua_tostring p_tolua_tostring
#define tolua_tousertype p_tolua_tousertype
#define tolua_usertype p_tolua_usertype
#define tolua_variable p_tolua_variable
