
#include "Baldur-v2.6.6.0_generated.h"
#include "EEexLua_generated.h"

void __stdcall Init(SharedState argSharedDLL) {

    sharedState() = argSharedDLL;

    InitLuaBindingsCommon(argSharedDLL, [&]() {
        sharedState().SetPatternValue(TEXT("EEex::DestroyUDAux"), EEex::DestroyUDAux);
        sharedState().SetPatternValue(TEXT("EEex::CopyUDAux"), EEex::CopyUDAux);
        sharedState().SetPatternValue(TEXT("EEex::Override_CGameEffect_CheckSave"), EEex::Override_CGameEffect_CheckSave);
        sharedState().SetPatternValue(TEXT("EEex::Stats_Hook_OnEqu"), EEex::Stats_Hook_OnEqu);
        sharedState().SetPatternValue(TEXT("EEex::Opcode_Hook_ApplySpell_ShouldFlipSplprotSourceAndTarget"), EEex::Opcode_Hook_ApplySpell_ShouldFlipSplprotSourceAndTarget);
        sharedState().SetPatternValue(TEXT("EEex::Opcode_Hook_OnCheckAdd"), EEex::Opcode_Hook_OnCheckAdd);
        sharedState().SetPatternValue(TEXT("EEex::Projectile_Hook_BeforeAddEffect"), EEex::Projectile_Hook_BeforeAddEffect);
    });

    // Populate internal engine pointers from patterns
    for (auto& pair : internalPointersMap) {
        uintptr_t patternVal;
        if (sharedState().GetPatternValue(pair.first, patternVal)) {
            *pair.second = reinterpret_cast<void*>(patternVal);
        }
        else {
            PrintT(TEXT("[!][LuaBindings-v2.6.6.0] Function pattern [%s] not present for bindings; calling this function will crash the game!\n"), pair.first);
        }
    }

    InitGenerated();

    EEex::InitEEex();

    // Export lua bindings
    OpenBindings(luaState());
}
