
#include "infinity_loader_common_api.h"

//-----------------------------//
//          Functions          //
//-----------------------------//

// Expects:       0 [ ... ]
// Returns: nReturn [ ..., return1, ..., returnN ]
bool luaCallProtected(lua_State* L, int nArg, int nReturn, std::function<void(int)> setup) {

	const int top = lua_gettop(L);

	lua_getglobal(L, "debug");                                                 //           1 [ debug ]
	lua_getfield(L, -1, "traceback");                                          //           2 [ debug, traceback ]

	setup(top);

	if (lua_pcallk(L, nArg, nReturn, top + 2, 0, nullptr) == LUA_OK) {
																			   // nReturn + 2 [ debug, traceback, return1, ..., returnN ]
		lua_remove(L, top + 2);                                                // nReturn + 1 [ debug, return1, ..., returnN ]
		lua_remove(L, top + 1);                                                //     nReturn [ return1, ..., returnN ]
		return true;
	}
	else {
																			   //           3 [ debug, traceback, errorMessage ]
		FPrint("[!][EEex.dll] luaCallProtected() - %s\n", lua_tostring(L, -1));
		lua_pop(L, 3);                                                         //           0 [ ]
		return false;
	}
}
