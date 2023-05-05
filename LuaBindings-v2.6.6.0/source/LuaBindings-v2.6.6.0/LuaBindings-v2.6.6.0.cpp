
#include "lua_bindings_core_api.h"
#include "EEexLua_generated.h"
#include "Baldur-v2.6.6.0_generated.h"

void __stdcall Init(SharedDLLMemory *const argSharedDLL) {

    sharedDLL = argSharedDLL;

    InitLuaBindingsCommon(argSharedDLL, [&]() {
        addPattern("EEex::DestroyUDAux", EEex::DestroyUDAux);
        addPattern("EEex::CopyUDAux", EEex::CopyUDAux);
        addPattern("EEex::Override_CGameEffect_CheckSave", EEex::Override_CGameEffect_CheckSave);
        addPattern("EEex::Stats_Hook_OnEqu", EEex::Stats_Hook_OnEqu);
        addPattern("EEex::Opcode_Hook_ApplySpell_ShouldFlipSplprotSourceAndTarget", EEex::Opcode_Hook_ApplySpell_ShouldFlipSplprotSourceAndTarget);
        addPattern("EEex::Opcode_Hook_OnCheckAdd", EEex::Opcode_Hook_OnCheckAdd);
        addPattern("EEex::Projectile_Hook_BeforeAddEffect", EEex::Projectile_Hook_BeforeAddEffect);
    });

    // Populate internal engine pointers from patterns
    for (auto& pair : internalPointersMap) {
        if (auto node = patterns().find(pair.first); node != patterns().end()) {
            PatternEntry& pattern = node->second;
            *pair.second = reinterpret_cast<void*>(pattern.value);
        }
        else {
            PrintT(TEXT("[!][LuaBindings-v2.6.6.0] Function pattern [%s] not present for bindings; calling this function will crash the game!\n"), pair.first);
        }
    }

    InitGenerated();

    EEex::InitPatterns(patterns());

    // Export lua bindings
    OpenBindings(L());
}
