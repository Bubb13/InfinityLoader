
#include "infinity_loader_common_api.h"

//-----------------------------//
//          Functions          //
//-----------------------------//

void dumpLuaStack(lua_State *const L)
{
	const int top { lua_gettop(L) };
	for (int i { 1 }; i <= top; ++i)
	{
		const int type { lua_type(L, i) };
		const char* typeStr { nullptr };

		switch (type)
		{
			case LUA_TNONE:          typeStr = "LUA_TNONE";          break;
			case LUA_TNIL:           typeStr = "LUA_TNIL";           break;
			case LUA_TBOOLEAN:       typeStr = "LUA_TBOOLEAN";       break;
			case LUA_TLIGHTUSERDATA: typeStr = "LUA_TLIGHTUSERDATA"; break;
			case LUA_TNUMBER:        typeStr = "LUA_TNUMBER";        break;
			case LUA_TSTRING:        typeStr = "LUA_TSTRING";        break;
			case LUA_TTABLE:         typeStr = "LUA_TTABLE";         break;
			case LUA_TFUNCTION:      typeStr = "LUA_TFUNCTION";      break;
			case LUA_TUSERDATA:      typeStr = "LUA_TUSERDATA";      break;
			case LUA_TTHREAD:        typeStr = "LUA_TTHREAD";        break;
			default:                 typeStr = "UNKNOWN";            break;
		}

		FPrint("%d    %s    ", i, typeStr);
		switch (type)
		{
			case LUA_TNUMBER:
				FPrint("%g\n", lua_tonumberx(L, i, nullptr));
				break;
			case LUA_TSTRING:
				FPrint("%s\n", lua_tostring(L, i));
				break;
			case LUA_TBOOLEAN:
				FPrint("%s\n", lua_toboolean(L, i) ? "true" : "false");
				break;
			case LUA_TNIL:
				Print("nil\n");
				break;
			default:
				Print("<no representation>\n");
				break;
		}
	}
}

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
