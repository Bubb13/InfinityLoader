
#include <filesystem>

#include "file_util.hpp"
#include "lua_util.hpp"

//-----------------------------//
//          Functions          //
//-----------------------------//

bool callLuaFile(lua_State* L, const char* chunkName, const TCHAR* luaFilePath)
{
	return luaCallProtected(L, 0, 0, [&](int _) -> bool
	{
		return luaL_loadpathx(L, chunkName, luaFilePath, nullptr) == LUA_OK;
	});
}

bool callScriptFile(lua_State* L, const char* fileName)
{
	const StringA fileNameWithExtension = StringA{ fileName }.append(".lua");
	const String fileNameWithExtensionT = StrAToStr(fileNameWithExtension);

	const String scriptFolderRoot = String{ workingFolder() }.append(getScriptFolder()).append(TEXT("\\"));
	const String scriptFileOverride = String{ scriptFolderRoot }.append(TEXT("override\\")).append(fileNameWithExtensionT);

	if (std::filesystem::exists(scriptFileOverride))
	{
		return callLuaFile(L, fileNameWithExtension.c_str(), scriptFileOverride.c_str());
	}
	else
	{
		const String scriptFile = String{ scriptFolderRoot }.append(fileNameWithExtensionT);
		return callLuaFile(L, fileNameWithExtension.c_str(), scriptFile.c_str());
	}
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

	lua_pushstring(L, "InfinityLoader_ErrorMessageHandler");                                 //           1 [ "InfinityLoader_ErrorMessageHandler" ]
	lua_rawget(L, LUA_REGISTRYINDEX);                                                        //           1 [ InfinityLoader_ErrorMessageHandler ]

	if (setup(top) && lua_pcallk(L, nArg, nReturn, top + 1, 0, nullptr) == LUA_OK)
	{                                                                                        // nReturn + 1 [ EEex_ErrorMessageHandler, return1, ..., returnN ]
		lua_remove(L, top + 1);                                                              //     nReturn [ return1, ..., returnN ]
		return true;
	}
	else
	{                                                                                        //           2 [ EEex_ErrorMessageHandler, errorMessage ]
		FPrint("[protected] %s\n", lua_tostring(L, -1));
		lua_pop(L, 2);                                                                       //           0 [ ]
		return false;
	}
}
