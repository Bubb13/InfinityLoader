
#include "infinity_loader_common_api.h"

//-----------------------------//
//          Functions          //
//-----------------------------//

// Expects:       0 [ ... ]
// Returns: nReturn [ ..., return1, ..., returnN ]
bool luaCallProtected(lua_State* L, int nArg, int nReturn, std::function<void(int)> setup)
{
	const int top = lua_gettop(L);

	lua_pushstring(L, "InfinityLoader_ErrorMessageHandler");                                 //           1 [ "InfinityLoader_ErrorMessageHandler" ]
	lua_rawget(L, LUA_REGISTRYINDEX);                                                        //           1 [ InfinityLoader_ErrorMessageHandler ]

	setup(top);

	if (lua_pcallk(L, nArg, nReturn, top + 1, 0, nullptr) == LUA_OK)
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
