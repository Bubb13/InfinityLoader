
#include "LuaBindingsCommon.h"
#include "EEexLua_generated.h"
#include "Baldur-v2.6.6.0_generated.h"

void __stdcall Init(lua_State* L, std::map<String, PatternEntry>& patterns, ImageSectionInfo& pTextInfo, bool debug,
    bool protonCompatibility)
{
    InitLuaBindingsCommon(L, patterns, pTextInfo, debug, protonCompatibility, [&]() {
        addPattern(patterns, "EEex::DestroyUDAux", EEex::DestroyUDAux);
        addPattern(patterns, "EEex::CopyUDAux", EEex::CopyUDAux);
    });

    // Export lua bindings
    tolua_EEexLua_open(L);
}
