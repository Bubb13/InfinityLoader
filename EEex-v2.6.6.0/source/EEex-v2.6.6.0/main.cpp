
#include "Baldur-v2.6.6.0_generated.h"
#include "EEexLua_generated.h"

void __stdcall Init(SharedState argSharedDLL) {

    sharedState() = argSharedDLL;

    InitLuaBindingsCommon(argSharedDLL, [&]() {
        AddPattern("EEex::DestroyUDAux", EEex::DestroyUDAux);
        AddPattern("EEex::CopyUDAux", EEex::CopyUDAux);
        AddPattern("EEex::Override_CGameEffect_CheckSave", EEex::Override_CGameEffect_CheckSave);
        AddPattern("EEex::Stats_Hook_OnEqu", EEex::Stats_Hook_OnEqu);
        AddPattern("EEex::Opcode_Hook_ApplySpell_ShouldFlipSplprotSourceAndTarget", EEex::Opcode_Hook_ApplySpell_ShouldFlipSplprotSourceAndTarget);
        AddPattern("EEex::Opcode_Hook_OnCheckAdd", EEex::Opcode_Hook_OnCheckAdd);
        AddPattern("EEex::Projectile_Hook_BeforeAddEffect", EEex::Projectile_Hook_BeforeAddEffect);
    });

    // Populate internal engine pointers from patterns
    for (auto& pair : internalPointersMap) {
        if (auto node = patterns().find(pair.first); node != patterns().end()) {
            PatternEntry& pattern = node->second;
            *pair.second = reinterpret_cast<void*>(pattern.value);
        }
        else {
            PrintT(TEXT("[!][EEex.dll] Function pattern [%s] not present for bindings; calling this function will crash the game!\n"), pair.first);
        }
    }

    InitGenerated();

    EEex::InitPatterns(patterns());

    // Export lua bindings
    OpenBindings(luaState());
}