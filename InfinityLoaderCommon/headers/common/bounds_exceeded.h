
#pragma once

#include <string>

#ifndef LUA_OK
#include "dummy_lua_generated.h"
#endif

template<typename IntegerType>
bool boundsExceeded(lua_State* L, int argI, IntegerType& resultVal, std::string& error);

#define instantiateBoundsExceeded(integerTypeName) \
	template bool boundsExceeded(lua_State* L, int argI, integerTypeName& resultVal, std::string& error);

#define castLuaIntArg(argI, typeName, varName) \
	typeName varName; \
	if (std::string error; boundsExceeded<typeName>(L, argI, varName, error)) { \
		p_luaL_error(L, "%s", error.c_str()); \
		return 0; \
	}
