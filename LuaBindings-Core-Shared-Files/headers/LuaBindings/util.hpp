
#pragma once

#include "Baldur_generated.h"

__forceinline int square(int x) {
	return x * x;
}

__forceinline bool isAIBase(const CGameObjectType type) {
	return (static_cast<__int8>(type) & static_cast<__int8>(CGameObjectType::AIBASE)) != 0;
}

///////////////
// Debugging //
///////////////

void dumpLuaStack(lua_State *const L);
