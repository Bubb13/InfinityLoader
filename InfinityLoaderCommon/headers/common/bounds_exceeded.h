
#pragma once

#include <string>

#include "lua_provider_api.h"

template<typename IntegerType>
bool boundsExceeded(lua_State *const L, const int argI, IntegerType& resultVal, std::string& error) {

	const lua_Integer val = lua_tointeger(L, argI);

	constexpr auto min = minIntegerTypeValue<IntegerType>();
	if (val < min) {
		// Error: Too small
		error = std::format("arg #{:d} ({:d}) too small (min: {:d})", argI, val, min);
		return true;
	}

	constexpr auto max = maxIntegerTypeValue<IntegerType>();
	if (val > max) {
		// Error: Too large
		error = std::format("arg #{:d} ({:d}) too large (max: {:d})", argI, val, max);
		return true;
	}

	resultVal = static_cast<IntegerType>(val);
	return false;
}

//#define castLuaIntArg(argI, typeName, varName) \
//	typeName varName; \
//	if (std::string error; boundsExceeded<typeName>(L, argI, varName, error)) { \
//		luaL_error(L, "%s", error.c_str()); \
//		return 0; \
//	}
