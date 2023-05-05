
#pragma once

#include <Windows.h>

#include <functional>
#include <map>
#include <unordered_map>
#include <vector>

#include "InfinityLoaderCommon.h"

EXTERN_C_EXPORT void addPattern(const char* name, void* value);
EXTERN_C_EXPORT void InitLuaBindingsCommon(SharedDLLMemory* argSharedDLL, std::function<void()> specificBindingsCallback);
