
#pragma once

#include <Windows.h>

#include <functional>
#include <map>
#include <unordered_map>
#include <vector>

#include "InfinityLoaderCommon.h"
#include "lua/lua.h"

extern std::unordered_map<const char*, std::unordered_map<const char*, uintptr_t>> baseclassOffsets;
extern std::vector<std::pair<const TCHAR*, void**>> internalPointersMap;

void addPattern(std::map<String, PatternEntry>& patterns, const char* name, void* value);
void InitLuaBindingsCommon(SharedDLLMemory* argSharedDLL, std::function<void()> specificBindingsCallback);
