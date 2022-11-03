
#include <map>

#include "InfinityLoaderCommon.h"
#include "Baldur-v2.6.6.0_generated.h"
#include "EEexLua_generated.h"
#include "to_lua_pointers.h"

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved) {
    switch (ul_reason_for_call) {
        case DLL_PROCESS_ATTACH:
        case DLL_THREAD_ATTACH:
        case DLL_THREAD_DETACH:
        case DLL_PROCESS_DETACH:
            break;
    }
    return TRUE;
}

///////////////////////
// General Functions //
///////////////////////

void exposeToLua(lua_State* L, const char* exposedName, lua_CFunction func) {
    p_lua_pushcclosure(L, func, 0);
    p_lua_setglobal(L, exposedName);
}

///////////////////
// Lua Functions //
///////////////////

void addPattern(std::map<String, PatternEntry>& patterns, const char* name, void* value) {
    String nameStr = ToString(name);
    patterns.try_emplace(nameStr, nameStr, reinterpret_cast<intptr_t>(value));
}

int castUserDataLua(lua_State* g_lua) {
    void** ptr = reinterpret_cast<void**>(p_lua_touserdata(g_lua, 1));
    if (!ptr) {
        p_lua_pushnil(g_lua);
        return 1;
    }
    tolua_pushusertype_nocast(g_lua, *ptr, p_lua_tostring(g_lua, 2));
    return 1;
}

int exposeToLuaLua(lua_State* L) {
    exposeToLua(L, p_lua_tostring(L, 2), reinterpret_cast<lua_CFunction>(p_lua_tointeger(L, 1)));
    return 0;
}

int freeUserDataLua(lua_State* g_lua) {
    p_free(p_tolua_tousertype(g_lua, 1, nullptr));
    return 0;
}

int getUserTypeLua(lua_State* L) {
    tolua_pushusertypestring(L, 1);
    return 1;
}

int memsetUserDataLua(lua_State* L) {
    memset(p_tolua_tousertype(L, 1, 0), p_lua_tointeger(L, 2), p_lua_tointeger(L, 3));
    return 0;
}

int newUserDataLua(lua_State* L) {
    const char* userTypeStr = p_lua_tostring(L, 1);
    p_lua_getglobal(L, userTypeStr);
    p_lua_getfield(L, -1, "sizeof");
    tolua_pushusertype_nocast(L, p_malloc(p_lua_tointeger(L, -1)), userTypeStr);
    return 1;
}

int pointerToUserDataLua(lua_State * g_lua) {
    void* ptr = reinterpret_cast<void*>(p_lua_tointeger(g_lua, 1));
    if (!ptr) {
        p_lua_pushnil(g_lua);
        return 1;
    }
    tolua_pushusertype_nocast(g_lua, ptr, p_lua_tostring(g_lua, 2));
    return 1;
}

int userDataToLightUserDataLua(lua_State* L) {
    p_lua_pushlightuserdata(L, p_tolua_tousertype(L, 1, 0));
    return 1;
}

int userDataToPointerLua(lua_State * g_lua) {
    ptrdiff_t* ptr = reinterpret_cast<ptrdiff_t*>(p_lua_touserdata(g_lua, 1));
    if (ptr == nullptr) {
        p_lua_pushnil(g_lua);
    }
    else {
        p_lua_pushinteger(g_lua, *reinterpret_cast<ptrdiff_t*>(p_lua_touserdata(g_lua, 1)));
    }
    return 1;
}

////////////////////
// Initialization //
////////////////////

void runCallback(lua_State* L) {

    if (p_lua_type(L, 2) != LUA_TFUNCTION)
        return;

    p_lua_getglobal(L, "debug");        // [ debug ]
    p_lua_getfield(L, -1, "traceback"); // [ debug, traceback ]
    p_lua_pushvalue(L, 2);              // [ debug, traceback, func ]

    if (p_lua_pcallk(L, 0, 0, -2, 0, nullptr) != LUA_OK) {
                                        // [ debug, traceback, errorMessage ]
        Print("[!] %s\n", p_lua_tostring(L, -1));
        p_lua_pop(L, 3);                // [ ]
    }
    else {
                                        // [ debug, traceback ]
        p_lua_pop(L, 2);                // [ ]
    }
}

// Ugly hack to get a member-function pointer
template<typename T>
constexpr void* GetMemberPtr(T func) {
    return reinterpret_cast<void*&>(func);
}

void __stdcall Init(lua_State* L, std::map<String, PatternEntry>& patterns, ImageSectionInfo& pTextInfo) {

#define setLuaPointer(patternName, pointerGlobal) \
    if (auto itr = patterns.find(TEXT(patternName)); itr != patterns.end()) { \
        p_##pointerGlobal = (type_##pointerGlobal*)(itr->second.value); \
    } \
    else { \
        Print("[!] Lua pattern not defined: \"%s\"; binding failed!\n", patternName); \
        return; \
    }

    // Read required function pointers from the pattern map
    setLuaPointer("Hardcoded_free", free);
    setLuaPointer("Hardcoded_lua_callk", lua_callk);
    setLuaPointer("Hardcoded_lua_createtable", lua_createtable);
    setLuaPointer("Hardcoded_lua_getfield", lua_getfield);
    setLuaPointer("Hardcoded_lua_getglobal", lua_getglobal);
    setLuaPointer("Hardcoded_lua_getmetatable", lua_getmetatable);
    setLuaPointer("Hardcoded_lua_gettable", lua_gettable);
    setLuaPointer("Hardcoded_lua_gettop", lua_gettop);
    setLuaPointer("Hardcoded_lua_insert", lua_insert);
    setLuaPointer("Hardcoded_lua_iscfunction", lua_iscfunction);
    setLuaPointer("Hardcoded_lua_isnumber", lua_isnumber);
    setLuaPointer("Hardcoded_lua_isuserdata", lua_isuserdata);
    setLuaPointer("Hardcoded_lua_newuserdata", lua_newuserdata);
    setLuaPointer("Hardcoded_lua_next", lua_next);
    setLuaPointer("Hardcoded_lua_pcallk", lua_pcallk);
    setLuaPointer("Hardcoded_lua_pushboolean", lua_pushboolean);
    setLuaPointer("Hardcoded_lua_pushcclosure", lua_pushcclosure);
    setLuaPointer("Hardcoded_lua_pushinteger", lua_pushinteger);
    setLuaPointer("Hardcoded_lua_pushlightuserdata", lua_pushlightuserdata);
    setLuaPointer("Hardcoded_lua_pushlstring", lua_pushlstring);
    setLuaPointer("Hardcoded_lua_pushnil", lua_pushnil);
    setLuaPointer("Hardcoded_lua_pushstring", lua_pushstring);
    setLuaPointer("Hardcoded_lua_pushvalue", lua_pushvalue);
    setLuaPointer("Hardcoded_lua_rawget", lua_rawget);
    setLuaPointer("Hardcoded_lua_rawgeti", lua_rawgeti);
    setLuaPointer("Hardcoded_lua_rawset", lua_rawset);
    setLuaPointer("Hardcoded_lua_rawseti", lua_rawseti);
    setLuaPointer("Hardcoded_lua_remove", lua_remove);
    setLuaPointer("Hardcoded_lua_setglobal", lua_setglobal);
    setLuaPointer("Hardcoded_lua_setmetatable", lua_setmetatable);
    setLuaPointer("Hardcoded_lua_settable", lua_settable);
    setLuaPointer("Hardcoded_lua_settop", lua_settop);
    setLuaPointer("Hardcoded_lua_toboolean", lua_toboolean);
    setLuaPointer("Hardcoded_lua_tocfunction", lua_tocfunction);
    setLuaPointer("Hardcoded_lua_tointegerx", lua_tointegerx);
    setLuaPointer("Hardcoded_lua_tolstring", lua_tolstring);
    setLuaPointer("Hardcoded_lua_tonumberx", lua_tonumberx);
    setLuaPointer("Hardcoded_lua_touserdata", lua_touserdata);
    setLuaPointer("Hardcoded_lua_type", lua_type);
    setLuaPointer("Hardcoded_luaL_error", luaL_error);
    setLuaPointer("Hardcoded_luaL_loadfilex", luaL_loadfilex);
    setLuaPointer("Hardcoded_luaL_loadstring", luaL_loadstring);
    setLuaPointer("Hardcoded_malloc", malloc);
    setLuaPointer("Hardcoded_tolua_beginmodule", tolua_beginmodule);
    setLuaPointer("Hardcoded_tolua_bnd_cast", tolua_bnd_cast);
    setLuaPointer("Hardcoded_tolua_bnd_release", tolua_bnd_release);
    setLuaPointer("Hardcoded_tolua_bnd_releaseownership", tolua_bnd_releaseownership);
    setLuaPointer("Hardcoded_tolua_bnd_takeownership", tolua_bnd_takeownership);
    setLuaPointer("Hardcoded_tolua_bnd_type", tolua_bnd_type);
    setLuaPointer("Hardcoded_tolua_constant", tolua_constant);
    setLuaPointer("Hardcoded_tolua_endmodule", tolua_endmodule);
    setLuaPointer("Hardcoded_tolua_error", tolua_error);
    setLuaPointer("Hardcoded_tolua_function", tolua_function);
    setLuaPointer("Hardcoded_tolua_getmetatable", tolua_getmetatable);
    setLuaPointer("Hardcoded_tolua_isboolean", tolua_isboolean);
    setLuaPointer("Hardcoded_tolua_isnumber", tolua_isnumber);
    setLuaPointer("Hardcoded_tolua_isstring", tolua_isstring);
    setLuaPointer("Hardcoded_tolua_isusertype", tolua_isusertype);
    setLuaPointer("Hardcoded_tolua_module", tolua_module);
    setLuaPointer("Hardcoded_tolua_newmetatable", tolua_newmetatable);
    setLuaPointer("Hardcoded_tolua_pushboolean", tolua_pushboolean);
    setLuaPointer("Hardcoded_tolua_pushnumber", tolua_pushnumber);
    setLuaPointer("Hardcoded_tolua_pushstring", tolua_pushstring);
    setLuaPointer("Hardcoded_tolua_tostring", tolua_tostring);
    setLuaPointer("Hardcoded_tolua_tousertype", tolua_tousertype);
    setLuaPointer("Hardcoded_tolua_typename", tolua_typename);
    setLuaPointer("Hardcoded_tolua_usertype", tolua_usertype);
    setLuaPointer("Hardcoded_tolua_variable", tolua_variable);

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
    exposeToLua(L, "EEex_NewUserData", newUserDataLua);
    exposeToLua(L, "EEex_NewUD", newUserDataLua);
    exposeToLua(L, "EEex_PointerToUserData", pointerToUserDataLua);
    exposeToLua(L, "EEex_PtrToUD", pointerToUserDataLua);
    exposeToLua(L, "EEex_UDToLightUD", userDataToLightUserDataLua);
    exposeToLua(L, "EEex_UDToPtr", userDataToPointerLua);
    exposeToLua(L, "EEex_UserDataToLightUserData", userDataToLightUserDataLua);
    exposeToLua(L, "EEex_UserDataToPointer", userDataToPointerLua);

    // Special
    p_lua_pushlightuserdata(L, &NULL_POINTER);
    p_lua_setglobal(L, "NULL_PTR");
    p_lua_pushlightuserdata(L, &NULL_POINTER);
    p_lua_setglobal(L, "NULL_POINTER");

    // Populate internal engine pointers from patterns
    for (auto& pair : internalPointersMap) {
        if (auto node = patterns.find(pair.first); node != patterns.end()) {
            PatternEntry& pattern = node->second;
            *pair.second = reinterpret_cast<void*>(pattern.value);
        }
        else {
            PrintT(TEXT("[!] Function pattern [%s] not present for bindings; calling this function will crash the game!\n"), pair.first);
        }
    }

    // Export tolua overrides (the versions in-engine aren't sufficient)
    addPattern(patterns, "Hardcoded_tolua_pushusertype", tolua_pushusertype_nocast);
    addPattern(patterns, "override_class_index_event", p_class_index_event);
    addPattern(patterns, "override_class_newindex_event", p_class_newindex_event);
    addPattern(patterns, "override_module_index_event", p_module_index_event);
    addPattern(patterns, "override_module_newindex_event", p_module_newindex_event);
    addPattern(patterns, "override_tolua_cclass", tolua_cclass_translate);
    addPattern(patterns, "override_tolua_open", p_tolua_open);

    // The Lua environment needs to grab the pattern map and execute any
    // patches relating to tolua before the Lua bindings are exported
    runCallback(L);

    // Export lua bindings
    tolua_EEexLua_open(L);
}
