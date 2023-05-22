
#include "infinity_loader_common_api.h"
#include "to_lua_pointers.h"

/////////////
// Globals //
/////////////

bool alreadyInitialized = false;

///////////////////////
// General Functions //
///////////////////////

void exposeToLua(lua_State* L, const char* exposedName, lua_CFunction func) {
	lua_pushcclosure(L, func, 0);
	lua_setglobal(L, exposedName);
}

///////////////////
// Lua Functions //
///////////////////

int castUserDataLua(lua_State* g_lua) {
	void** ptr = reinterpret_cast<void**>(lua_touserdata(g_lua, 1));
	if (!ptr) {
		lua_pushnil(g_lua);
		return 1;
	}
	tolua_pushusertype_nocast(g_lua, *ptr, lua_tostring(g_lua, 2));
	return 1;
}

int exposeToLuaLua(lua_State* L) {
	exposeToLua(L, lua_tostring(L, 2), reinterpret_cast<lua_CFunction>(lua_tointeger(L, 1)));
	return 0;
}

int freeUserDataLua(lua_State* g_lua) {
	p_free(tolua_tousertype(g_lua, 1, nullptr));
	return 0;
}

int getUserTypeLua(lua_State* L) {
	tolua_pushusertypestring(L, 1);
	return 1;
}

int memsetUserDataLua(lua_State* L) {
	castLuaIntArg(2, int, Int, val)
	castLuaIntArg(3, size_t, SizeT, size)
	memset(tolua_tousertype(L, 1, 0), val, size);
	return 0;
}

int newUserDataLua(lua_State* L) {
	const char* userTypeStr = lua_tostring(L, 1);
	lua_getglobal(L, userTypeStr);
	lua_getfield(L, -1, "sizeof");
	tolua_pushusertype_nocast(L, p_malloc(lua_tointeger(L, -1)), userTypeStr);
	return 1;
}

int pointerToUserDataLua(lua_State * g_lua) {
	void* ptr = reinterpret_cast<void*>(lua_tointeger(g_lua, 1));
	if (!ptr) {
		lua_pushnil(g_lua);
		return 1;
	}
	tolua_pushusertype_nocast(g_lua, ptr, lua_tostring(g_lua, 2));
	return 1;
}

// Expects [ ..., ud, func ]
int setUserDataGarbageCollectionFunctionLua(lua_State* L) {
	void* ptr = *reinterpret_cast<void**>(lua_touserdata(L, -2));
	lua_pushstring(L, "tolua_gc");    // 3 [ ..., ud, func, "tolua_gc" ]
	lua_rawget(L, LUA_REGISTRYINDEX); // 3 [ ..., ud, func, registry["tolua_gc"] ]
	lua_pushlightuserdata(L, ptr);    // 4 [ ..., ud, func, registry["tolua_gc"], lud(value) ]
	lua_pushvalue(L, -3);             // 5 [ ..., ud, func, registry["tolua_gc"], lud(value), func ]
	lua_rawset(L, -3);                // 3 [ ..., ud, func, registry["tolua_gc"] ]
	lua_pop(L, 1);                    // 2 [ ..., ud, func ]
	return 0;
}

int userDataToLightUserDataLua(lua_State* L) {
	lua_pushlightuserdata(L, tolua_tousertype(L, 1, 0));
	return 1;
}

int userDataToPointerLua(lua_State * g_lua) {
	uintptr_t* ptr = reinterpret_cast<uintptr_t*>(lua_touserdata(g_lua, 1));
	if (ptr == nullptr) {
		lua_pushnil(g_lua);
	}
	else {
		lua_pushinteger(g_lua, *ptr);
	}
	return 1;
}

////////////////////
// Initialization //
////////////////////

void runCallback(lua_State* L) {

	if (lua_type(L, 2) != LUA_TFUNCTION) {
		return;
	}

	lua_getglobal(L, "debug");                           // [ debug ]
	lua_getfield(L, -1, "traceback");                    // [ debug, traceback ]
	lua_pushvalue(L, 2);                                 // [ debug, traceback, func ]

	if (lua_pcallk(L, 0, 0, -2, 0, nullptr) != LUA_OK) {
														 // [ debug, traceback, errorMessage ]
		Print("[!] %s\n", lua_tostring(L, -1));
		lua_pop(L, 3);                                   // [ ]
	}
	else {
														 // [ debug, traceback ]
		lua_pop(L, 2);                                   // [ ]
	}
}

// Ugly hack to get a member-function pointer
template<typename T>
constexpr void* GetMemberPtr(T func) {
	return reinterpret_cast<void*&>(func);
}

EXPORT void InitLuaBindingsCommon(SharedState argSharedDLL, std::function<void()> specificBindingsCallback) {

#define setNamedPointer(patternName, funcName, ptrName) \
	if (sharedState().GetPatternValue(TEXT(patternName), patternVal)) { \
		##ptrName = (type_##funcName)(patternVal); \
	} \
	else { \
		Print("[!][LuaBindingsCore] Pattern not defined: \"%s\"; initialization failed!\n", patternName); \
		return; \
	} \

#define setPointer(patternName, funcName) \
	if (sharedState().GetPatternValue(TEXT(patternName), patternVal)) { \
		##funcName = (type_##funcName)(patternVal); \
	} \
	else { \
		Print("[!][LuaBindingsCore] Lua pattern not defined: \"%s\"; initialization failed!\n", patternName); \
		return; \
	} \

	if (!alreadyInitialized) {
		sharedState() = argSharedDLL;
	}

	lua_State *const L = luaState();

	if (!alreadyInitialized) {

		alreadyInitialized = true;

		if (int error = InitFPrint()) {
			Print("[!] InitFPrint failed (%d).", error);
			return;
		}

		uintptr_t patternVal;

		// Read required function pointers from the pattern map
		setNamedPointer("Hardcoded_free", free, p_free);
		setNamedPointer("Hardcoded_malloc", malloc, p_malloc);
		setPointer("Hardcoded_tolua_bnd_cast", tolua_bnd_cast);
		setPointer("Hardcoded_tolua_bnd_release", tolua_bnd_release);
		setPointer("Hardcoded_tolua_bnd_releaseownership", tolua_bnd_releaseownership);
		setPointer("Hardcoded_tolua_bnd_takeownership", tolua_bnd_takeownership);
		setPointer("Hardcoded_tolua_bnd_type", tolua_bnd_type);
		setPointer("Hardcoded_tolua_constant", tolua_constant);
		setPointer("Hardcoded_tolua_endmodule", tolua_endmodule);
		setPointer("Hardcoded_tolua_error", tolua_error);
		setPointer("Hardcoded_tolua_function", tolua_function);
		setPointer("Hardcoded_tolua_getmetatable", tolua_getmetatable);
		setPointer("Hardcoded_tolua_isboolean", tolua_isboolean);
		setPointer("Hardcoded_tolua_ismodulemetatable", tolua_ismodulemetatable);
		setPointer("Hardcoded_tolua_isnumber", tolua_isnumber);
		setPointer("Hardcoded_tolua_isstring", tolua_isstring);
		setPointer("Hardcoded_tolua_isusertype", tolua_isusertype);
		setPointer("Hardcoded_tolua_moduleevents", tolua_moduleevents);
		setPointer("Hardcoded_tolua_newmetatable", tolua_newmetatable);
		setPointer("Hardcoded_tolua_pushboolean", tolua_pushboolean);
		setPointer("Hardcoded_tolua_pushnumber", tolua_pushnumber);
		setPointer("Hardcoded_tolua_pushstring", tolua_pushstring);
		setPointer("Hardcoded_tolua_tostring", tolua_tostring);
		setPointer("Hardcoded_tolua_tousertype", tolua_tousertype);
		setPointer("Hardcoded_tolua_typename", tolua_typename);
		setPointer("Hardcoded_tolua_usertype", tolua_usertype);
		setPointer("Hardcoded_tolua_variable", tolua_variable);

		// Export Lua functions that deal with user data / user types
		exposeToLua(L, "EEex_CastUD", castUserDataLua);
		exposeToLua(L, "EEex_CastUserData", castUserDataLua);
		exposeToLua(L, "EEex_ExposeToLua", exposeToLuaLua);
		exposeToLua(L, "EEex_FreeUD", freeUserDataLua);
		exposeToLua(L, "EEex_FreeUserData", freeUserDataLua);
		exposeToLua(L, "EEex_GetUserType", getUserTypeLua);
		exposeToLua(L, "EEex_GetUT", getUserTypeLua);
		exposeToLua(L, "EEex_MemsetUD", memsetUserDataLua);
		exposeToLua(L, "EEex_MemsetUserData", memsetUserDataLua);
		exposeToLua(L, "EEex_NewUD", newUserDataLua);
		exposeToLua(L, "EEex_NewUserData", newUserDataLua);
		exposeToLua(L, "EEex_PointerToUserData", pointerToUserDataLua);
		exposeToLua(L, "EEex_PtrToUD", pointerToUserDataLua);
		exposeToLua(L, "EEex_SetUDGCFunc", setUserDataGarbageCollectionFunctionLua);
		exposeToLua(L, "EEex_SetUserDataGarbageCollectionFunction", setUserDataGarbageCollectionFunctionLua);
		exposeToLua(L, "EEex_UDToLightUD", userDataToLightUserDataLua);
		exposeToLua(L, "EEex_UDToPtr", userDataToPointerLua);
		exposeToLua(L, "EEex_UserDataToLightUserData", userDataToLightUserDataLua);
		exposeToLua(L, "EEex_UserDataToPointer", userDataToPointerLua);

		// Special
		lua_pushlightuserdata(L, &NULL_POINTER);
		lua_setglobal(L, "NULL_PTR");
		lua_pushlightuserdata(L, &NULL_POINTER);
		lua_setglobal(L, "NULL_POINTER");

		// Export tolua overrides (the versions in-engine aren't sufficient)
		sharedState().SetPatternValue(TEXT("Hardcoded_tolua_pushusertype"), tolua_pushusertype_nocast);
		sharedState().SetPatternValue(TEXT("override_class_index_event"), class_index_event);
		sharedState().SetPatternValue(TEXT("override_class_newindex_event"), class_newindex_event);
		sharedState().SetPatternValue(TEXT("override_module_index_event"), module_index_event);
		sharedState().SetPatternValue(TEXT("override_module_newindex_event"), module_newindex_event);
		sharedState().SetPatternValue(TEXT("override_tolua_cclass"), tolua_cclass_translate);
		sharedState().SetPatternValue(TEXT("override_tolua_open"), tolua_open);
		sharedState().SetPatternValue(TEXT("override_tolua_beginmodule"), tolua_beginmodule);
		sharedState().SetPatternValue(TEXT("override_tolua_module"), tolua_module);
	}

	if (specificBindingsCallback != nullptr) {
		specificBindingsCallback();
	}

	// The Lua environment needs to grab the pattern map and execute any
	// patches relating to tolua before the Lua bindings are exported
	runCallback(L);
}
