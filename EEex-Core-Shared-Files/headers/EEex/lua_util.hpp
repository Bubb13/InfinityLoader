
#pragma once

#include "infinity_loader_common_api.h"

//-----------------------------//
//          Functions          //
//-----------------------------//

bool luaCallProtected(lua_State* L, int nArg, int nReturn, std::function<void(int)> setup);
