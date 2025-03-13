
#include <format>

#include "infinity_loader_common_api.h"
#include "shared_state_api.h"
#include "tolua.h"
#include "tolua_infinityloader_overrides.h"
#include "tolua_pointers.h"

/////////////
// Globals //
/////////////

bool alreadyInitialized = false;
StringA luaGlobalsPrefix;
#define prefixed(str) std::format("{}"##str, luaGlobalsPrefix).c_str()  

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
	tolua_pushusertype(g_lua, *ptr, lua_tostring(g_lua, 2));
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
	tolua_pushusertype(L, p_malloc(lua_tointeger(L, -1)), userTypeStr);
	return 1;
}

int pointerToUserDataLua(lua_State * g_lua) {
	void* ptr = reinterpret_cast<void*>(lua_tointeger(g_lua, 1));
	if (!ptr) {
		lua_pushnil(g_lua);
		return 1;
	}
	tolua_pushusertype(g_lua, ptr, lua_tostring(g_lua, 2));
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

static void initLuaState(lua_State *const L) {
	
	lua_pushstring(L, "InfinityLoader_LuaBindingsCore_Opened"); // 1 [ "InfinityLoader_LuaBindingsCore_Opened" ]
	lua_rawget(L, LUA_REGISTRYINDEX);                           // 1 [ registry["InfinityLoader_LuaBindingsCore_Opened"] ]

	if (lua_toboolean(L, -1)) {
		lua_pop(L, 1);                                          // 0 [ ]
		return;
	}

	lua_pushstring(L, "InfinityLoader_LuaBindingsCore_Opened"); // 2 [ registry["InfinityLoader_LuaBindingsCore_Opened"], "InfinityLoader_LuaBindingsCore_Opened" ]
	lua_pushboolean(L, true);                                   // 3 [ registry["InfinityLoader_LuaBindingsCore_Opened"], "InfinityLoader_LuaBindingsCore_Opened", true ]
	lua_rawset(L, LUA_REGISTRYINDEX);                           // 1 [ registry["InfinityLoader_LuaBindingsCore_Opened"] ]
	lua_pop(L, 1);                                              // 0 [ ]

	// Export Lua functions that deal with user data / user types
	exposeToLua(L, prefixed("CastUserData"), castUserDataLua);
	exposeToLua(L, prefixed("CastUD"), castUserDataLua);

	exposeToLua(L, prefixed("FreeUserData"), freeUserDataLua);
	exposeToLua(L, prefixed("FreeUD"), freeUserDataLua);

	exposeToLua(L, prefixed("GetUserType"), getUserTypeLua);
	exposeToLua(L, prefixed("GetUT"), getUserTypeLua);

	exposeToLua(L, prefixed("LightUserDataToPointer"), lightUserDataToPointerLua);
	exposeToLua(L, prefixed("LightUDToPtr"), lightUserDataToPointerLua);

	exposeToLua(L, prefixed("MemsetUserData"), memsetUserDataLua);
	exposeToLua(L, prefixed("MemsetUD"), memsetUserDataLua);

	exposeToLua(L, prefixed("NewUserData"), newUserDataLua);
	exposeToLua(L, prefixed("NewUD"), newUserDataLua);

	exposeToLua(L, prefixed("PointerToUserData"), pointerToUserDataLua);
	exposeToLua(L, prefixed("PtrToUD"), pointerToUserDataLua);

	exposeToLua(L, prefixed("SetUserDataGarbageCollectionFunction"), setUserDataGarbageCollectionFunctionLua);
	exposeToLua(L, prefixed("SetUDGCFunc"), setUserDataGarbageCollectionFunctionLua);

	exposeToLua(L, prefixed("UserDataToLightUserData"), userDataToLightUserDataLua);
	exposeToLua(L, prefixed("UDToLightUD"), userDataToLightUserDataLua);

	exposeToLua(L, prefixed("UserDataToPointer"), userDataToPointerLua);
	exposeToLua(L, prefixed("UDToPtr"), userDataToPointerLua);

	// Special
	lua_pushlightuserdata(L, &NULL_POINTER);
	lua_setglobal(L, "NULL_PTR");
	lua_pushlightuserdata(L, &NULL_POINTER);
	lua_setglobal(L, "NULL_POINTER");
}

template<typename POINTER_OUT>
static bool setPointerInternal(const TCHAR *const patternName, POINTER_OUT& pointerOut) {
	PatternValueHandle patternHandle;
	switch (sharedState().GetPatternValue(patternName, patternHandle)) {
		case PatternValueType::SINGLE: {
			pointerOut = reinterpret_cast<POINTER_OUT>(sharedState().GetSinglePatternValue(patternHandle));
			return true;
		}
		case PatternValueType::INVALID: {
			FPrintT(TEXT("[!][LuaBindingsCore.dll] setPointer() - Pattern [%s] missing; initialization failed\n"), patternName);
			return false;
		}
		default: {
			FPrintT(TEXT("[!][LuaBindingsCore.dll] setPointer() - Pattern [%s].Type not SINGLE; initialization failed\n"), patternName);
			return false;
		}
	}
}

static bool exportPatternInternal(const TCHAR *const patternName, void* patternValue) {

	PatternValueHandle patternHandle;
	if (sharedState().GetOrCreatePatternValue(patternName, PatternValueType::SINGLE, patternHandle)) {
		FPrintT(TEXT("[!][LuaBindingsCore.dll] exportPattern() - [%s].Type must be SINGLE\n"), patternName);
		return false;
	}
	
	sharedState().SetSinglePatternValue(patternHandle, patternValue);
	return true;
}

// Track changes to p_free() and p_malloc()
static void onAfterPatternModified(const PatternValueHandle handle, const uintptr_t newAddress) {

	if (sharedState().GetPatternValueType(handle) != PatternValueType::SINGLE) {
		return;
	}

	const String& patternName = sharedState().GetPatternValueName(handle);

	if (patternName == TEXT("Hardcoded_free")) {
		p_free = reinterpret_cast<type_free>(newAddress);
	}
	else if (patternName == TEXT("Hardcoded_malloc")) {
		p_malloc = reinterpret_cast<type_malloc>(newAddress);
	}
}

EXPORT void InitLuaBindingsCommon(SharedState argSharedDLL) {

#define setPointer(funcName) \
	if (!setPointerInternal(L"Hardcoded_"#funcName, p_##funcName)) return;

#define exportPattern(patternName, func) \
	if (!exportPatternInternal(patternName, func)) return;

	if (!alreadyInitialized) {
		sharedState() = argSharedDLL;
	}

	lua_State *const L = luaState();

	if (!alreadyInitialized) {

		if (int error = InitFPrint()) {
			FPrint("[!][LuaBindingsCore.dll] InitLuaBindingsCommon() - InitFPrint() failed (%d)\n", error);
			return;
		}

		String luaGlobalsPrefixW;
		if (GetINIStrDef(iniPath(), TEXT("General"), TEXT("LuaGlobalsPrefix"), TEXT("EEex_"), luaGlobalsPrefixW) != ERROR_SUCCESS) {
			Print("[!][LuaBindingsCore.dll] InitLuaBindingsCommon() - Failed to read [General].LuaGlobalsPrefix\n");
			return;
		}
		luaGlobalsPrefix = StrToStrA(luaGlobalsPrefixW);

		// Read required function pointers from the pattern map
		setPointer(free)
		setPointer(malloc)
		sharedState().AddAfterPatternModifiedListener(onAfterPatternModified);

		// Export tolua functions required for patches
		exportPattern(TEXT("Hardcoded_tolua_pushusertype"), tolua_pushusertype);
		exportPattern(TEXT("Hardcoded_tolua_tousertype"), tolua_tousertype);

		// Export tolua overrides (the versions in-engine aren't sufficient)
		exportPattern(TEXT("override_class_index_event"), class_index_event);
		exportPattern(TEXT("override_class_newindex_event"), class_newindex_event);
		exportPattern(TEXT("override_module_index_event"), module_index_event);
		exportPattern(TEXT("override_module_newindex_event"), module_newindex_event);
		exportPattern(TEXT("override_tolua_cclass"), tolua_cclass_translate);
		exportPattern(TEXT("override_tolua_open"), tolua_open);
		exportPattern(TEXT("override_tolua_beginmodule"), tolua_beginmodule);
		exportPattern(TEXT("override_tolua_module"), tolua_module);
		exportPattern(TEXT("override_tolua_usertype"), tolua_usertype);
	}

	initLuaState(L);

	if (!alreadyInitialized) {

		alreadyInitialized = true;

		// The Lua environment needs to grab the pattern map and execute any
		// patches relating to tolua before the Lua bindings are exported
		runCallback(L);
	}
}
