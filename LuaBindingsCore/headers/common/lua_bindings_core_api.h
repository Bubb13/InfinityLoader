
#pragma once

#include <format>
#include <functional>

#include "lua_provider_api.h"

///////////
// Types //
///////////

struct tolua_Error; // Hide implementation
typedef void(__cdecl* type_free)(void* memblock);
typedef void*(__cdecl* type_malloc)(size_t size);

////////////
// Custom //
////////////

IMPORT bool tolua_function_toboolean(lua_State* L, int narg, const char* functionName);
IMPORT char tolua_function_tochar(lua_State* L, int narg, const char* functionName);
IMPORT const char* tolua_function_tostring(lua_State* L, int narg, const char* functionName);
IMPORT bool tolua_setter_toboolean(lua_State* L, const char* variableName);
IMPORT char tolua_setter_tochar(lua_State* L, const char* variableName);
IMPORT void* tolua_tousertype_dynamic(lua_State* L, int index, void* def, const char* targetUsertype);

////////////
// Normal //
////////////

IMPORT void tolua_constant(lua_State* L, const char* name, double value);
IMPORT void tolua_endmodule(lua_State* L);
IMPORT void tolua_error(lua_State* L, const char* msg, tolua_Error* err);
IMPORT void tolua_function(lua_State* L, const char* name, lua_CFunction func);
IMPORT void tolua_pushboolean(lua_State* L, int value);
IMPORT void tolua_pushnumber(lua_State* L, double value);
IMPORT void tolua_pushstring(lua_State* L, const char* value);
IMPORT const char* tolua_typename(lua_State* L, int lo);
IMPORT void tolua_variable(lua_State* L, const char* name, lua_CFunction get, lua_CFunction set);

//////////
// Main //
//////////

IMPORT void InitLuaBindingsCommon(SharedState argSharedDLL);

///////////////
// Overrides //
///////////////

IMPORT void tolua_beginmodule(lua_State* L, const char* name);
IMPORT void tolua_cclass(lua_State* L, const char* lname, const char* name, std::initializer_list<const char*>&& bases, lua_CFunction col);
IMPORT void tolua_module(lua_State* L, const char* name, int hasvar);
IMPORT void tolua_open(lua_State* L);
IMPORT void tolua_pushusertype(lua_State* L, void* value, const char* type);
IMPORT void tolua_usertype(lua_State* L, const char* type);

//////////////
// Pointers //
//////////////

IMPORT type_free p_free;
IMPORT type_malloc p_malloc;

/////////////
// Special //
/////////////

EXTERN_IMPORT bool NULL_POINTER;

IMPORT void RegisterClassBaseclassOffsets(const char* name, const std::initializer_list<std::pair<const char*, uintptr_t>>& toRegister);
IMPORT void RegisterBaseclassOffsets(const std::initializer_list<std::pair<const char*, std::initializer_list<std::pair<const char*, uintptr_t>>>>& toRegister);

//////////////////////////////
// Template Implementations //
//////////////////////////////

template<typename IntegerType>
IntegerType tolua_function_tointeger(lua_State *const L, const int narg, const char *const functionName) {

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
IntegerType tolua_setter_tointeger(lua_State *const L, const char *const variableName) {

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
FloatingType tolua_function_tonumber(lua_State *const L, const int narg, const char *const functionName) {

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
FloatingType tolua_setter_tonumber(lua_State *const L, const char *const variableName) {

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
