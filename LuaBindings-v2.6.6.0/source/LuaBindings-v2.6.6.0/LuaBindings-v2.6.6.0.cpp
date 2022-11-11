
#include "LuaBindingsCommon.h"
#include "EEexLua_generated.h"

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

// Ugly hack to get a member-function pointer
template<typename T>
constexpr void* GetMemberPtr(T func) {
    return reinterpret_cast<void*&>(func);
}

void __stdcall Init(lua_State* L, std::map<String, PatternEntry>& patterns, ImageSectionInfo& pTextInfo) {

    InitLuaBindingsCommon(L, patterns, pTextInfo);

    // Export lua bindings
    tolua_EEexLua_open(L);
}
