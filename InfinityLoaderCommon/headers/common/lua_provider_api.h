
#pragma once

#include "lua_provider_api_core.h"
#include "shared_memory_dll.h"

//////////
// Init //
//////////

LUA_PROVIDER_API DWORD InitLuaProvider(SharedDLLMemory* sharedDLL);
