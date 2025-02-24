
#pragma once

#include "lua_provider_api_core.h"

////////////
// Custom //
////////////

void tolua_cclass_translate(lua_State* L, const char* lname, const char* name, const char* base, lua_CFunction col);
void tolua_pushusertypestring(lua_State* L, int lo);

////////////////////
// Custom Exports //
////////////////////

EXPORT bool tolua_function_toboolean(lua_State* L, int narg, const char* functionName);
EXPORT char tolua_function_tochar(lua_State* L, int narg, const char* functionName);
EXPORT const char* tolua_function_tostring(lua_State* L, int narg, const char* functionName);
EXPORT bool tolua_setter_toboolean(lua_State* L, const char* variableName);
EXPORT char tolua_setter_tochar(lua_State* L, const char* variableName);
EXPORT void* tolua_tousertype_dynamic(lua_State* L, int narg, void* def, const char* targetUsertype);

//////////////
// Internal //
//////////////

void mapinheritance(lua_State* L, const char* name, const char* base);
void mapsuper(lua_State* L, const char* name, const char* baseName);
void storeatpeer(lua_State* L, int index);

////////////////////////
// Internal Overrides //
////////////////////////

int class_index_event(lua_State* L);
int class_newindex_event(lua_State* L);
int module_index_event(lua_State* L);
int module_newindex_event(lua_State* L);
