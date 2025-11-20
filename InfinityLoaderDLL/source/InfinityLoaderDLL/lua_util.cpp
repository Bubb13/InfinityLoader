
#include <filesystem>

#include "file_util.hpp"
#include "lua_util.hpp"

//-----------------------------//
//          Functions          //
//-----------------------------//

bool callLuaFile(lua_State* L, const TCHAR* luaFilePath)
{
	return luaCallProtected(L, 0, 0, [&](int _) -> bool
	{
		return luaL_loadpathx(L, luaFilePath, nullptr) == LUA_OK;
	});
}

void callScriptFile(lua_State* L, const TCHAR* name)
{
	const String scriptFolderRoot = String{ workingFolder() }.append(getScriptFolder()).append(TEXT("\\"));
	const String scriptFileOverride = String{ scriptFolderRoot }.append(TEXT("override\\")).append(name).append(TEXT(".lua"));

	if (std::filesystem::exists(scriptFileOverride))
	{
		callLuaFile(L, scriptFileOverride.c_str());
	}
	else
	{
		const String scriptFile = String{ scriptFolderRoot }.append(name).append(TEXT(".lua"));
		callLuaFile(L, scriptFile.c_str());
	}
}

int callScriptFileA(lua_State* L, const char* name)
{
#if _UNICODE
	const String nameT = NulTermStrToStr(name);
	callScriptFile(L, nameT.c_str());
#else
	callScriptFile(L, name);
#endif
	return 0;
}

void exposeToLua(lua_State* L, const char* exposedName, lua_CFunction func)
{
	lua_pushcclosure(L, func, 0);
	lua_setglobal(L, exposedName);
}

// Expects:       0 [ ... ]
// Returns: nReturn [ ..., return1, ..., returnN ]
bool luaCallProtected(lua_State* L, int nArg, int nReturn, std::function<bool(int)> setup)
{
	const int top = lua_gettop(L);

	lua_getglobal(L, "debug");                                                               //           1 [ debug ]
	lua_getfield(L, -1, "traceback");                                                        //           2 [ debug, traceback ]

	if (setup(top) && lua_pcallk(L, nArg, nReturn, top + 2, 0, nullptr) == LUA_OK)
	{                                                                                        // nReturn + 2 [ debug, traceback, return1, ..., returnN ]
		lua_remove(L, top + 2);                                                              // nReturn + 1 [ debug, return1, ..., returnN ]
		lua_remove(L, top + 1);                                                              //     nReturn [ return1, ..., returnN ]
		return true;
	}
	else
	{                                                                                        //           3 [ debug, traceback, errorMessage ]
		FPrint("[!][InfinityLoaderDLL.dll] luaCallProtected() - %s\n", lua_tostring(L, -1));
		lua_pop(L, 3);                                                                       //           0 [ ]
		return false;
	}
}
