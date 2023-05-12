
#pragma once

#include <functional>
#include <format>

#include "shared_memory_dll.h"
#include "tolua/tolua.h"
#include "lua_provider_api.h"

//////////
// Main //
//////////

IMPORT void InitLuaBindingsCommon(SharedDLLMemory *const argSharedDLL, std::function<void()> specificBindingsCallback);
IMPORT void AddPattern(const char* name, void* value);
IMPORT void RegisterClassBaseclassOffsets(const char* name, const std::initializer_list<const std::pair<const char*, uintptr_t>>& toRegister);
IMPORT void RegisterBaseclassOffsets(const std::initializer_list<const std::pair<const char*, std::initializer_list<const std::pair<const char*, uintptr_t>>>>& toRegister);

/////////////
// Special //
/////////////

EXTERN_IMPORT bool NULL_POINTER;

//////////////
// Pointers //
//////////////

typedef void (__cdecl* type_free)(void* memblock);
EXTERN_IMPORT type_free p_free;

typedef void* (__cdecl* type_malloc)(size_t size);
EXTERN_IMPORT type_malloc p_malloc;

typedef int (*type_tolua_bnd_cast)(lua_State* L);
EXTERN_IMPORT type_tolua_bnd_cast tolua_bnd_cast;

typedef int (*type_tolua_bnd_release)(lua_State* L);
EXTERN_IMPORT type_tolua_bnd_release tolua_bnd_release;

typedef int (*type_tolua_bnd_releaseownership)(lua_State* L);
EXTERN_IMPORT type_tolua_bnd_releaseownership tolua_bnd_releaseownership;

typedef int (*type_tolua_bnd_takeownership)(lua_State* L);
EXTERN_IMPORT type_tolua_bnd_takeownership tolua_bnd_takeownership;

typedef int (*type_tolua_bnd_type)(lua_State* L);
EXTERN_IMPORT type_tolua_bnd_type tolua_bnd_type;

typedef void (*type_tolua_constant)(lua_State* L, const char* name, double value);
EXTERN_IMPORT type_tolua_constant tolua_constant;

typedef void (*type_tolua_endmodule)(lua_State* L);
EXTERN_IMPORT type_tolua_endmodule tolua_endmodule;

typedef void (*type_tolua_error)(lua_State* L, const char* msg, tolua_Error* err);
EXTERN_IMPORT type_tolua_error tolua_error;

typedef void (*type_tolua_function)(lua_State* L, const char* name, lua_CFunction func);
EXTERN_IMPORT type_tolua_function tolua_function;

typedef void (*type_tolua_getmetatable)(lua_State* L, const char* name);
EXTERN_IMPORT type_tolua_getmetatable tolua_getmetatable;

typedef int (*type_tolua_isboolean)(lua_State* L, int lo, int def, tolua_Error* err);
EXTERN_IMPORT type_tolua_isboolean tolua_isboolean;

typedef int (*type_tolua_ismodulemetatable)(lua_State* L);
EXTERN_IMPORT type_tolua_ismodulemetatable tolua_ismodulemetatable;

typedef int (*type_tolua_isnumber)(lua_State* L, int lo, int def, tolua_Error* err);
EXTERN_IMPORT type_tolua_isnumber tolua_isnumber;

typedef int (*type_tolua_isstring)(lua_State* L, int lo, int def, tolua_Error* err);
EXTERN_IMPORT type_tolua_isstring tolua_isstring;

typedef int (*type_tolua_isusertype)(lua_State* L, int lo, const char* type, int def, tolua_Error* err);
EXTERN_IMPORT type_tolua_isusertype tolua_isusertype;

typedef void (*type_tolua_moduleevents)(lua_State* L);
EXTERN_IMPORT type_tolua_moduleevents tolua_moduleevents;

typedef void (*type_tolua_newmetatable)(lua_State* L, const char* name);
EXTERN_IMPORT type_tolua_newmetatable tolua_newmetatable;

typedef void (*type_tolua_pushboolean)(lua_State* L, int value);
EXTERN_IMPORT type_tolua_pushboolean tolua_pushboolean;

typedef void (*type_tolua_pushnumber)(lua_State* L, double value);
EXTERN_IMPORT type_tolua_pushnumber tolua_pushnumber;

typedef void (*type_tolua_pushstring)(lua_State* L, const char* value);
EXTERN_IMPORT type_tolua_pushstring tolua_pushstring;

typedef const char* (*type_tolua_tostring)(lua_State* L, int narg, const char* def);
EXTERN_IMPORT type_tolua_tostring tolua_tostring;

typedef void* (*type_tolua_tousertype)(lua_State* L, int narg, void* def);
EXTERN_IMPORT type_tolua_tousertype tolua_tousertype;

typedef const char* (*type_tolua_typename)(lua_State* L, int lo);
EXTERN_IMPORT type_tolua_typename tolua_typename;

typedef void (*type_tolua_usertype)(lua_State* L, const char* type);
EXTERN_IMPORT type_tolua_usertype tolua_usertype;

typedef void (*type_tolua_variable)(lua_State* L, const char* name, lua_CFunction get, lua_CFunction set);
EXTERN_IMPORT type_tolua_variable tolua_variable;

////////////
// Custom //
////////////

IMPORT void tolua_cclass_translate(lua_State* L, const char* lname, const char* name, const char* base, lua_CFunction col);

IMPORT bool tolua_function_toboolean(lua_State* L, int narg, const char* functionName);
IMPORT char tolua_function_tochar(lua_State* L, int narg, const char* functionName);
IMPORT const char* tolua_function_tostring(lua_State* L, int narg, const char* functionName);

IMPORT bool tolua_setter_toboolean(lua_State* L, const char* variableName);
IMPORT char tolua_setter_tochar(lua_State* L, const char* variableName);

IMPORT void* tolua_tousertype_dynamic(lua_State* L, int narg, void* def, const char* targetUsertype);

IMPORT void tolua_pushusertype_nocast(lua_State* L, void* value, const char* type);
IMPORT void tolua_pushusertypepointer(lua_State* L, void* value, const char* type);
IMPORT void tolua_pushusertypestring(lua_State* L, int lo);

///////////////////////////////////////////////////
// Overrides (engine needs these to be replaced) //
///////////////////////////////////////////////////

IMPORT int class_index_event(lua_State* L);
IMPORT int class_newindex_event(lua_State* L);
IMPORT int module_index_event(lua_State* L);
IMPORT int module_newindex_event(lua_State* L);
// tolua_cclass_translate() actually overrides the engine function, though this still needs a declaration for use in EEexLua_generated.cpp
IMPORT void tolua_cclass(lua_State* L, const char* lname, const char* name, std::initializer_list<const char*>&& bases, lua_CFunction col);
IMPORT void tolua_beginmodule(lua_State* L, const char* name);
IMPORT void tolua_module(lua_State* L, const char* name, int hasvar);
IMPORT void tolua_open(lua_State* L);

//////////////////////////////
// Template Implementations //
//////////////////////////////

template<typename IntegerType>
IntegerType tolua_function_tointeger(lua_State* const L, const int narg, const char* const functionName) {

	if (lua_gettop(L) < narg) {
		return luaL_error(L, "integer argument #%d missing in function '%s'; 'number' or 'boolean' expected.", narg, functionName);
	}

	if (const int type = lua_type(L, narg); type == LUA_TBOOLEAN) {
		return static_cast<IntegerType>(lua_toboolean(L, narg));
	}
	else if (type == LUA_TNUMBER) {

		const lua_Integer val = lua_tointeger(L, narg);
		constexpr auto min = (std::numeric_limits<IntegerType>::lowest)();
		constexpr auto max = (std::numeric_limits<IntegerType>::max)();

		if (val < min || val > max) {
			std::string error = std::format("invalid integer '{:d}' for integer argument #{:d} in function '{:s}'; '[{:d}-{:d}]' expected.", val, narg, functionName, min, max);
			return luaL_error(L, "%s", error.c_str());
		}

		return static_cast<IntegerType>(val);
	}
	return luaL_error(L, "invalid type '%s' for integer argument #%d in function '%s'; 'number' or 'boolean' expected.", tolua_typename(L, narg), narg, functionName);
}

template<typename IntegerType>
IntegerType tolua_setter_tointeger(lua_State* const L, const char* const variableName) {

	constexpr int narg = 2;
	if (lua_gettop(L) < narg) {
		return luaL_error(L, "argument missing in integer variable setter '%s'; 'number' or 'boolean' expected.", variableName);
	}

	if (const int type = lua_type(L, narg); type == LUA_TBOOLEAN) {
		return static_cast<IntegerType>(lua_toboolean(L, narg));
	}
	else if (type == LUA_TNUMBER) {

		const lua_Integer val = lua_tointeger(L, narg);
		constexpr auto min = (std::numeric_limits<IntegerType>::lowest)();
		constexpr auto max = (std::numeric_limits<IntegerType>::max)();

		if (val < min || val > max) {
			std::string error = std::format("invalid integer '{:d}' in integer variable setter '{:s}'; '[{:d}-{:d}]' expected.", val, variableName, min, max);
			return luaL_error(L, "%s", error.c_str());
		}

		return static_cast<IntegerType>(val);
	}
	return luaL_error(L, "invalid type '%s' in integer variable setter '%s'; 'number' or 'boolean' expected.", tolua_typename(L, narg), variableName);
}

template<typename FloatingType>
FloatingType tolua_function_tonumber(lua_State* const L, const int narg, const char* const functionName) {

	if (lua_gettop(L) < narg) {
		luaL_error(L, "number argument #%d missing in function '%s'; 'number' expected.", narg, functionName);
	}

	if (lua_type(L, narg) == LUA_TNUMBER) {

		const lua_Number val = lua_tonumber(L, narg);
		constexpr auto min = (std::numeric_limits<FloatingType>::lowest)();
		constexpr auto max = (std::numeric_limits<FloatingType>::max)();

		if (val < min || val > max) {
			std::string error = std::format("invalid number '{:e}' for number argument #{:d} in function '{:s}'; '[{:e}-{:e}]' expected.", val, narg, functionName, min, max);
			luaL_error(L, "%s", error.c_str());
		}

		return static_cast<FloatingType>(val);
	}
	luaL_error(L, "invalid type '%s' for number argument #%d in function '%s'; 'number' expected.", tolua_typename(L, narg), narg, functionName);
	return static_cast<FloatingType>(0); // To silence warning, luaL_error() never returns
}

template<typename FloatingType>
FloatingType tolua_setter_tonumber(lua_State* const L, const char* const variableName) {

	constexpr int narg = 2;
	if (lua_gettop(L) < narg) {
		luaL_error(L, "argument missing in number variable setter '%s'; 'number' expected.", variableName);
	}

	if (lua_type(L, narg) == LUA_TNUMBER) {

		const lua_Number val = lua_tonumber(L, narg);
		constexpr auto min = (std::numeric_limits<FloatingType>::lowest)();
		constexpr auto max = (std::numeric_limits<FloatingType>::max)();

		if (val < min || val > max) {
			std::string error = std::format("invalid number '{:e}' in number variable setter '{:s}'; '[{:e}-{:e}]' expected.", val, variableName, min, max);
			luaL_error(L, "%s", error.c_str());
		}

		return static_cast<FloatingType>(val);
	}
	luaL_error(L, "invalid type '%s' in number variable setter '%s'; 'number' expected.", tolua_typename(L, narg), variableName);
	return static_cast<FloatingType>(0); // To silence warning, luaL_error() never returns
}

/////////////
// Defines //
/////////////

#define tolua_pushusertype tolua_pushusertype_nocast
