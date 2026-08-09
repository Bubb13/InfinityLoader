
#pragma once

#include "infinity_loader_common_api.h"

//-----------------------------//
//          Functions          //
//-----------------------------//

void dumpLuaStack(lua_State *const L);
bool luaCallProtected(lua_State* L, int nArg, int nReturn, std::function<void(int)> setup);
