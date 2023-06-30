
#include "Baldur-v2.6.6.0_generated.h"
#include "Baldur-v2.6.6.0_lua_generated.h"
#include "lua_bindings_core_api.h"

static int tolua_function_EEex_test(lua_State* L)
{
	int returnVal = EEex::test();
	lua_pushinteger(L, (lua_Integer)returnVal);
	return 1;
}

static void tolua_reg_types(lua_State* L)
{
	tolua_usertype(L, "EEex");
}

int OpenBindings(lua_State* L)
{
	tolua_open(L);
	tolua_reg_types(L);
	tolua_module(L, NULL, 0);
	tolua_beginmodule(L, NULL);
	tolua_cclass(L, "EEex", "EEex", {}, NULL);
	tolua_beginmodule(L, "EEex");
		tolua_function(L, "test", &tolua_function_EEex_test);
	tolua_endmodule(L);
	tolua_endmodule(L);
	return 1;
}
