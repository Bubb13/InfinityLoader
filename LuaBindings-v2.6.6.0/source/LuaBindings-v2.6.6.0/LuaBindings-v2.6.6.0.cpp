
#include "LuaBindingsCommon.h"
#include "EEexLua_generated.h"
#include "Baldur-v2.6.6.0_generated.h"

void __stdcall Init(lua_State* L, HMODULE luaLibrary, std::map<String, PatternEntry>& patterns, ImageSectionInfo& pTextInfo, bool debug,
    bool protonCompatibility)
{
    InitLuaBindingsCommon(L, luaLibrary, patterns, pTextInfo, debug, protonCompatibility, [&]() {
        addPattern(patterns, "EEex::DestroyUDAux", EEex::DestroyUDAux);
        addPattern(patterns, "EEex::CopyUDAux", EEex::CopyUDAux);
        addPattern(patterns, "EEex::Override_CGameEffect_CheckSave", EEex::Override_CGameEffect_CheckSave);
        addPattern(patterns, "EEex::Stats_Hook_OnEqu", EEex::Stats_Hook_OnEqu);
        addPattern(patterns, "EEex::Opcode_Hook_ApplySpell_ShouldFlipSplprotSourceAndTarget", EEex::Opcode_Hook_ApplySpell_ShouldFlipSplprotSourceAndTarget);
        addPattern(patterns, "EEex::Opcode_Hook_OnCheckAdd", EEex::Opcode_Hook_OnCheckAdd);
        addPattern(patterns, "EEex::Projectile_Hook_BeforeAddEffect", EEex::Projectile_Hook_BeforeAddEffect);
    });

    EEex::InitPatterns(patterns);

    // Export lua bindings
    tolua_EEexLua_open(L);
}
