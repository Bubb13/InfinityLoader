
#pragma once

#include "Baldur-v2.6.6.0_generated.h"

__forceinline int square(int x) {
	return x * x;
}

__forceinline bool isAIBase(const CGameObjectType type) {
	return (static_cast<__int8>(type) & static_cast<__int8>(CGameObjectType::AIBASE)) != 0;
}
