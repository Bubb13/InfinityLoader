
#include "infinity_loader_common_api.h"
#include "to_lua_pointers.h"
#include "shared_state_api.h"

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

int freeUserDataLua(lua_State* g_lua) {
	p_free(tolua_tousertype(g_lua, 1, nullptr));
	return 0;
}

int getUserTypeLua(lua_State* L) {
	tolua_pushusertypestring(L, 1);
	return 1;
}

int lightUserDataToPointerLua(lua_State* L) {
	if (const void *const ptr = lua_touserdata(L, 1); ptr == nullptr) {
		lua_pushnil(L);
	}
	else {
		lua_pushinteger(L, reinterpret_cast<uintptr_t>(ptr));
	}
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

	lua_getglobal(L, "debug");                                                       // [ debug ]
	lua_getfield(L, -1, "traceback");                                                // [ debug, traceback ]
	lua_pushvalue(L, 2);                                                             // [ debug, traceback, func ]

	if (lua_pcallk(L, 0, 0, -2, 0, nullptr) != LUA_OK) {
																					 // [ debug, traceback, errorMessage ]
		FPrint("[!][LuaBindingsCore.dll] runCallback() - %s\n", lua_tostring(L, -1));
		lua_pop(L, 3);                                                               // [ ]
	}
	else {
																					 // [ debug, traceback ]
		lua_pop(L, 2);                                                               // [ ]
	}
}

// Ugly hack to get a member-function pointer
template<typename T>
constexpr void* GetMemberPtr(T func) {
	return reinterpret_cast<void*&>(func);
}

void exportPattern(const String& name, void* value) {

	PatternValueHandle handle;
	if (sharedState().GetOrCreatePatternValue(name, PatternValueType::SINGLE, handle)) {
		FPrintT(TEXT("[!][LuaBindingsCore.dll] exportPattern() - [%s].Type must be SINGLE\n"), name.c_str());
		return;
	}

	sharedState().SetSinglePatternValue(handle, value);
}

template<typename out_type>
DWORD getToLuaProc(HMODULE toLuaLibrary, const char* name, out_type& out) {
	if (out = reinterpret_cast<out_type>(GetProcAddress(toLuaLibrary, name)); out == 0) {
		DWORD lastError = GetLastError();
		FPrint("[!][LuaBindingsCore.dll] getToLuaProc() - GetProcAddress() failed (%d) to find ToLua function \"%s\"\n", lastError, name);
		return lastError;
	}
	return 0;
}

EXPORT void InitLuaBindingsCommon(SharedState argSharedDLL) {

#define setNamedPointer(patternName, funcName, ptrName) \
	switch (sharedState().GetPatternValue(TEXT(patternName), patternHandle)) { \
		case PatternValueType::SINGLE: { \
			##ptrName = (type_##funcName)(sharedState().GetSinglePatternValue(patternHandle)); \
			break; \
		} \
		case PatternValueType::INVALID: { \
			FPrint("[!][LuaBindingsCore.dll] InitLuaBindingsCommon() - Pattern [%s] not defined; initialization failed\n", patternName); \
			return; \
		} \
		default: { \
			FPrint("[!][LuaBindingsCore.dll] InitLuaBindingsCommon() - [%s].Type must be SINGLE; initialization failed\n", patternName); \
			return; \
		} \
	}

#define setPointer(patternName, functionNameStr, funcName) \
	if (toLuaLibrary == INVALID_HANDLE_VALUE) { \
		switch (sharedState().GetPatternValue(TEXT(patternName), patternHandle)) { \
			case PatternValueType::SINGLE: { \
				##funcName = (type_##funcName)(sharedState().GetSinglePatternValue(patternHandle)); \
				break; \
			} \
			case PatternValueType::INVALID: { \
				FPrint("[!][LuaBindingsCore.dll] InitLuaBindingsCommon() - ToLua pattern [%s] missing; initialization failed\n", patternName); \
				return; \
			} \
			default: { \
				FPrint("[!][LuaBindingsCore.dll] InitLuaBindingsCommon() - ToLua pattern [%s].Type not SINGLE; initialization failed\n", patternName); \
				return; \
			} \
		} \
	} \
	else { \
		if (DWORD lastError = getToLuaProc(toLuaLibrary, functionNameStr, ##funcName)) { \
			return; \
		} \
	}

	if (!alreadyInitialized) {
		sharedState() = argSharedDLL;
	}

	lua_State *const L = luaState();

	if (!alreadyInitialized) {

		alreadyInitialized = true;

		if (int error = InitFPrint()) {
			FPrint("[!][LuaBindingsCore.dll] InitFPrint() failed (%d)\n", error);
			return;
		}

		HMODULE toLuaLibrary = toLuaLibrary();
		PatternValueHandle patternHandle;

		// Read required function pointers from the pattern map
		setNamedPointer("Hardcoded_free", free, p_free)
		setNamedPointer("Hardcoded_malloc", malloc, p_malloc)
		setPointer("Hardcoded_tolua_bnd_cast", "tolua_bnd_cast", tolua_bnd_cast)
		setPointer("Hardcoded_tolua_bnd_release", "tolua_bnd_release", tolua_bnd_release)
		setPointer("Hardcoded_tolua_bnd_releaseownership", "tolua_bnd_releaseownership", tolua_bnd_releaseownership)
		setPointer("Hardcoded_tolua_bnd_takeownership", "tolua_bnd_takeownership", tolua_bnd_takeownership)
		setPointer("Hardcoded_tolua_bnd_type", "tolua_bnd_type", tolua_bnd_type)
		setPointer("Hardcoded_tolua_constant", "tolua_constant", tolua_constant)
		setPointer("Hardcoded_tolua_endmodule", "tolua_endmodule", tolua_endmodule)
		setPointer("Hardcoded_tolua_error", "tolua_error", tolua_error)
		setPointer("Hardcoded_tolua_function", "tolua_function", tolua_function)
		setPointer("Hardcoded_tolua_getmetatable", "tolua_getmetatable", tolua_getmetatable)
		setPointer("Hardcoded_tolua_isboolean", "tolua_isboolean", tolua_isboolean)
		setPointer("Hardcoded_tolua_ismodulemetatable", "tolua_ismodulemetatable", tolua_ismodulemetatable)
		setPointer("Hardcoded_tolua_isnumber", "tolua_isnumber", tolua_isnumber)
		setPointer("Hardcoded_tolua_isstring", "tolua_isstring", tolua_isstring)
		setPointer("Hardcoded_tolua_isusertype", "tolua_isusertype", tolua_isusertype)
		setPointer("Hardcoded_tolua_moduleevents", "tolua_moduleevents", tolua_moduleevents)
		setPointer("Hardcoded_tolua_newmetatable", "tolua_newmetatable", tolua_newmetatable)
		setPointer("Hardcoded_tolua_pushboolean", "tolua_pushboolean", tolua_pushboolean)
		setPointer("Hardcoded_tolua_pushnumber", "tolua_pushnumber", tolua_pushnumber)
		setPointer("Hardcoded_tolua_pushstring", "tolua_pushstring", tolua_pushstring)
		setPointer("Hardcoded_tolua_tostring", "tolua_tostring", tolua_tostring)
		setPointer("Hardcoded_tolua_tousertype", "tolua_tousertype", tolua_tousertype)
		setPointer("Hardcoded_tolua_typename", "tolua_typename", tolua_typename)
		setPointer("Hardcoded_tolua_variable", "tolua_variable", tolua_variable)

		// Export Lua functions that deal with user data / user types
		exposeToLua(L, "EEex_CastUserData", castUserDataLua);
		exposeToLua(L, "EEex_CastUD", castUserDataLua);

		exposeToLua(L, "EEex_FreeUserData", freeUserDataLua);
		exposeToLua(L, "EEex_FreeUD", freeUserDataLua);

		exposeToLua(L, "EEex_GetUserType", getUserTypeLua);
		exposeToLua(L, "EEex_GetUT", getUserTypeLua);

		exposeToLua(L, "EEex_LightUserDataToPointer", lightUserDataToPointerLua);
		exposeToLua(L, "EEex_LightUDToPtr", lightUserDataToPointerLua);

		exposeToLua(L, "EEex_MemsetUserData", memsetUserDataLua);
		exposeToLua(L, "EEex_MemsetUD", memsetUserDataLua);

		exposeToLua(L, "EEex_NewUserData", newUserDataLua);
		exposeToLua(L, "EEex_NewUD", newUserDataLua);

		exposeToLua(L, "EEex_PointerToUserData", pointerToUserDataLua);
		exposeToLua(L, "EEex_PtrToUD", pointerToUserDataLua);

		exposeToLua(L, "EEex_SetUserDataGarbageCollectionFunction", setUserDataGarbageCollectionFunctionLua);
		exposeToLua(L, "EEex_SetUDGCFunc", setUserDataGarbageCollectionFunctionLua);

		exposeToLua(L, "EEex_UserDataToLightUserData", userDataToLightUserDataLua);
		exposeToLua(L, "EEex_UDToLightUD", userDataToLightUserDataLua);

		exposeToLua(L, "EEex_UserDataToPointer", userDataToPointerLua);
		exposeToLua(L, "EEex_UDToPtr", userDataToPointerLua);

		// Special
		lua_pushlightuserdata(L, &NULL_POINTER);
		lua_setglobal(L, "NULL_PTR");
		lua_pushlightuserdata(L, &NULL_POINTER);
		lua_setglobal(L, "NULL_POINTER");

		// Export tolua overrides (the versions in-engine aren't sufficient)
		exportPattern(TEXT("Hardcoded_tolua_pushusertype"), tolua_pushusertype_nocast);
		exportPattern(TEXT("override_class_index_event"), class_index_event);
		exportPattern(TEXT("override_class_newindex_event"), class_newindex_event);
		exportPattern(TEXT("override_module_index_event"), module_index_event);
		exportPattern(TEXT("override_module_newindex_event"), module_newindex_event);
		exportPattern(TEXT("override_tolua_cclass"), tolua_cclass_translate);
		exportPattern(TEXT("override_tolua_open"), tolua_open);
		exportPattern(TEXT("override_tolua_beginmodule"), tolua_beginmodule);
		exportPattern(TEXT("override_tolua_module"), tolua_module);
		exportPattern(TEXT("override_tolua_usertype"), tolua_usertype);

		// The Lua environment needs to grab the pattern map and execute any
		// patches relating to tolua before the Lua bindings are exported
		runCallback(L);
	}
}
