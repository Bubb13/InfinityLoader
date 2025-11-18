
#pragma once

#include "infinity_loader_common_api.h"

//-----------------------------//
//          Functions          //
//-----------------------------//

bool callLuaFile(lua_State* L, const TCHAR* luaFilePath);
void callScriptFile(lua_State* L, const TCHAR* name);
int callScriptFileA(lua_State* L, const char* name);
void exposeToLua(lua_State* L, const char* exposedName, lua_CFunction func);
bool luaCallProtected(lua_State* L, int nArg, int nReturn, std::function<bool(int)> setup);
