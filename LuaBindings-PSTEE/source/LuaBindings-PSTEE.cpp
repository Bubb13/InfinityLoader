
#include "LuaBindingsCommon.h"
#include "EEexLua_generated.h"

void __stdcall Init(lua_State* L, std::map<String, PatternEntry>& patterns, ImageSectionInfo& pTextInfo, bool protonCompatibility) {

    InitLuaBindingsCommon(L, patterns, pTextInfo, protonCompatibility);

    // Export lua bindings
    tolua_EEexLua_open(L);
}
