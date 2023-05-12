
#pragma once

#include <format>
#include <string>

#include "tolua/tolua.h"
#include "lua_provider_api.h"

/////////////
// Special //
/////////////

EXTERN_EXPORT bool NULL_POINTER;

//////////////
// Pointers //
//////////////

typedef void (__cdecl* type_free)(void* memblock);
EXTERN_EXPORT type_free p_free;

typedef void* (__cdecl* type_malloc)(size_t size);
EXTERN_EXPORT type_malloc p_malloc;

typedef int (*type_tolua_bnd_cast)(lua_State* L);
EXTERN_EXPORT type_tolua_bnd_cast tolua_bnd_cast;

typedef int (*type_tolua_bnd_release)(lua_State* L);
EXTERN_EXPORT type_tolua_bnd_release tolua_bnd_release;

typedef int (*type_tolua_bnd_releaseownership)(lua_State* L);
EXTERN_EXPORT type_tolua_bnd_releaseownership tolua_bnd_releaseownership;

typedef int (*type_tolua_bnd_takeownership)(lua_State* L);
EXTERN_EXPORT type_tolua_bnd_takeownership tolua_bnd_takeownership;

typedef int (*type_tolua_bnd_type)(lua_State* L);
EXTERN_EXPORT type_tolua_bnd_type tolua_bnd_type;

typedef void (*type_tolua_constant)(lua_State* L, const char* name, double value);
EXTERN_EXPORT type_tolua_constant tolua_constant;

typedef void (*type_tolua_endmodule)(lua_State* L);
EXTERN_EXPORT type_tolua_endmodule tolua_endmodule;

typedef void (*type_tolua_error)(lua_State* L, const char* msg, tolua_Error* err);
EXTERN_EXPORT type_tolua_error tolua_error;

typedef void (*type_tolua_function)(lua_State* L, const char* name, lua_CFunction func);
EXTERN_EXPORT type_tolua_function tolua_function;

typedef void (*type_tolua_getmetatable)(lua_State* L, const char* name);
EXTERN_EXPORT type_tolua_getmetatable tolua_getmetatable;

typedef int (*type_tolua_isboolean)(lua_State* L, int lo, int def, tolua_Error* err);
EXTERN_EXPORT type_tolua_isboolean tolua_isboolean;

typedef int (*type_tolua_ismodulemetatable)(lua_State* L);
EXTERN_EXPORT type_tolua_ismodulemetatable tolua_ismodulemetatable;

typedef int (*type_tolua_isnumber)(lua_State* L, int lo, int def, tolua_Error* err);
EXTERN_EXPORT type_tolua_isnumber tolua_isnumber;

typedef int (*type_tolua_isstring)(lua_State* L, int lo, int def, tolua_Error* err);
EXTERN_EXPORT type_tolua_isstring tolua_isstring;

typedef int (*type_tolua_isusertype)(lua_State* L, int lo, const char* type, int def, tolua_Error* err);
EXTERN_EXPORT type_tolua_isusertype tolua_isusertype;

typedef void (*type_tolua_moduleevents)(lua_State* L);
EXTERN_EXPORT type_tolua_moduleevents tolua_moduleevents;

typedef void (*type_tolua_newmetatable)(lua_State* L, const char* name);
EXTERN_EXPORT type_tolua_newmetatable tolua_newmetatable;

typedef void (*type_tolua_pushboolean)(lua_State* L, int value);
EXTERN_EXPORT type_tolua_pushboolean tolua_pushboolean;

typedef void (*type_tolua_pushnumber)(lua_State* L, double value);
EXTERN_EXPORT type_tolua_pushnumber tolua_pushnumber;

typedef void (*type_tolua_pushstring)(lua_State* L, const char* value);
EXTERN_EXPORT type_tolua_pushstring tolua_pushstring;

typedef const char* (*type_tolua_tostring)(lua_State* L, int narg, const char* def);
EXTERN_EXPORT type_tolua_tostring tolua_tostring;

typedef void* (*type_tolua_tousertype)(lua_State* L, int narg, void* def);
EXTERN_EXPORT type_tolua_tousertype tolua_tousertype;

typedef const char* (*type_tolua_typename)(lua_State* L, int lo);
EXTERN_EXPORT type_tolua_typename tolua_typename;

typedef void (*type_tolua_usertype)(lua_State* L, const char* type);
EXTERN_EXPORT type_tolua_usertype tolua_usertype;

typedef void (*type_tolua_variable)(lua_State* L, const char* name, lua_CFunction get, lua_CFunction set);
EXTERN_EXPORT type_tolua_variable tolua_variable;

////////////
// Custom //
////////////

EXPORT void tolua_cclass_translate(lua_State* L, const char* lname, const char* name, const char* base, lua_CFunction col);

EXPORT bool tolua_function_toboolean(lua_State* L, int narg, const char* functionName);
EXPORT char tolua_function_tochar(lua_State* L, int narg, const char* functionName);
EXPORT const char* tolua_function_tostring(lua_State* L, int narg, const char* functionName);

EXPORT bool tolua_setter_toboolean(lua_State* L, const char* variableName);
EXPORT char tolua_setter_tochar(lua_State* L, const char* variableName);

EXPORT void* tolua_tousertype_dynamic(lua_State* L, int narg, void* def, const char* targetUsertype);

EXPORT void tolua_pushusertype_nocast(lua_State* L, void* value, const char* type);
EXPORT void tolua_pushusertypepointer(lua_State* L, void* value, const char* type);
EXPORT void tolua_pushusertypestring(lua_State* L, int lo);

///////////////////////////////////////////////////
// Overrides (engine needs these to be replaced) //
///////////////////////////////////////////////////

EXPORT int class_index_event(lua_State* L);
EXPORT int class_newindex_event(lua_State* L);
EXPORT int module_index_event(lua_State* L);
EXPORT int module_newindex_event(lua_State* L);
// tolua_cclass_translate() actually overrides the engine function, though this still needs a declaration for use in EEexLua_generated.cpp
EXPORT void tolua_cclass(lua_State* L, const char* lname, const char* name, std::initializer_list<const char*>&& bases, lua_CFunction col);
EXPORT void tolua_beginmodule(lua_State* L, const char* name);
EXPORT void tolua_module(lua_State* L, const char* name, int hasvar);
EXPORT void tolua_open(lua_State* L);
