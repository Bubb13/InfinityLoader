
#pragma once

#include <Windows.h>

#include <functional>
#include <map>
#include <unordered_map>
#include <vector>

#include "infinity_loader_common_api.h"

EXPORT void AddPattern(const char* name, void* value);
EXPORT void InitLuaBindingsCommon(SharedDLLMemory *const argSharedDLL, std::function<void()> specificBindingsCallback);
