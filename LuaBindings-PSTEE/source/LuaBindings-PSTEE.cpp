
#include "engine_structs_generated.h"
#include "EEexLua_generated.h"

void __stdcall Init(SharedState argSharedState) {

    sharedState() = argSharedState;

    InitLuaBindingsCommon(argSharedState);

    // Populate internal engine pointers from patterns
    for (auto& pair : internalPointersMap) {
        uintptr_t patternVal;
        if (sharedState().GetPatternValue(pair.first, patternVal)) {
            *pair.second = reinterpret_cast<void*>(patternVal);
        }
        else {
            PrintT(TEXT("[!][LuaBindings-PSTEE] Function pattern [%s] not present for bindings; calling this function will crash the game!\n"), pair.first);
        }
    }

    InitGenerated();

    // Export lua bindings
    OpenBindings(luaState());
}
