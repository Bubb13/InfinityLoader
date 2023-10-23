
#include "infinity_loader_common_api.h"

///////////////
// Debugging //
///////////////

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

		Print("%d    %s    ", i, typeStr);
		switch (type)
		{
			case LUA_TNUMBER:
				Print("%g\n", lua_tonumberx(L, i, nullptr));
				break;
			case LUA_TSTRING:
				Print("%s\n", lua_tostring(L, i));
				break;
			case LUA_TBOOLEAN:
				Print("%s\n", lua_toboolean(L, i) ? "true" : "false");
				break;
			case LUA_TNIL:
				Print("%s\n", "nil");
				break;
			default:
				Print("<no representation>\n");
				break;
		}
	}
}
