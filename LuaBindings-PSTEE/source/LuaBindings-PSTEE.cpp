
#include "engine_structs_generated.h"
#include "EEexLua_generated.h"

void __stdcall Init(SharedState argSharedState) {

	sharedState() = argSharedState;

	// Populate internal engine pointers from patterns
	for (auto& pair : internalPointersMap) {
		PatternValueHandle patternHandle;
		switch (sharedState().GetPatternValue(pair.first, patternHandle)) {
			case (PatternValueType::SINGLE): {
				*pair.second = reinterpret_cast<void*>(sharedState().GetSinglePatternValue(patternHandle));
				break;
			}
			case (PatternValueType::INVALID): {
				PrintT(TEXT("[!][LuaBindings-PSTEE.dll] Init() - Function pattern [%s] not present for bindings; calling this function will crash the game!\n"), pair.first);
				break;
			}
			default: {
				PrintT(TEXT("[!][LuaBindings-PSTEE.dll] Init() - [%s].Type must be SINGLE\n"), pair.first);
				break;
			}
		}
	}
}

void __stdcall OpenBindings() {

	InitLuaBindingsCommon(sharedState());

	// Export lua bindings
	OpenBindingsInternal(luaState());
}
