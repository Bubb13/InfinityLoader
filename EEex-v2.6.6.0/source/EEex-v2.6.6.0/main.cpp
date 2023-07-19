
#include "Baldur-v2.6.6.0_generated.h"
#include "EEex.h"
#include "EEexLua_generated.h"

void __stdcall Init(SharedState argSharedDLL) {

	sharedState() = argSharedDLL;

	InitLuaBindingsCommon(argSharedDLL, [&]() {

		/////////////////////////////////
		//          Overrides          //
		/////////////////////////////////

		sharedState().SetPatternValue(TEXT("EEex::Override_CGameEffect_CheckSave"), EEex::Override_CGameEffect_CheckSave);

		/////////////////////////////
		//          Hooks          //
		/////////////////////////////

		////////////////
		// Game State //
		////////////////

		sharedState().SetPatternValue(TEXT("EEex::GameState_Hook_OnInitialized"), EEex::GameState_Hook_OnInitialized);

		///////////
		// Stats //
		///////////

		sharedState().SetPatternValue(TEXT("EEex::Stats_Hook_OnConstruct"), EEex::Stats_Hook_OnConstruct);
		sharedState().SetPatternValue(TEXT("EEex::Stats_Hook_OnDestruct"), EEex::Stats_Hook_OnDestruct);
		sharedState().SetPatternValue(TEXT("EEex::Stats_Hook_OnReload"), EEex::Stats_Hook_OnReload);
		sharedState().SetPatternValue(TEXT("EEex::Stats_Hook_OnEqu"), EEex::Stats_Hook_OnEqu);
		sharedState().SetPatternValue(TEXT("EEex::Stats_Hook_OnPlusEqu"), EEex::Stats_Hook_OnPlusEqu);
		sharedState().SetPatternValue(TEXT("EEex::Stats_Hook_OnGettingUnknown"), EEex::Stats_Hook_OnGettingUnknown);

		////////////
		// Opcode //
		////////////

		// op248
		sharedState().SetPatternValue(TEXT("EEex::Opcode_Hook_OnOp248AddTail"), EEex::Opcode_Hook_OnOp248AddTail);
		// op249
		sharedState().SetPatternValue(TEXT("EEex::Opcode_Hook_OnOp249AddTail"), EEex::Opcode_Hook_OnOp249AddTail);
		// New op400
		sharedState().SetPatternValue(TEXT("EEex::Opcode_Hook_SetTemporaryAIScript_ApplyEffect"), EEex::Opcode_Hook_SetTemporaryAIScript_ApplyEffect);
		sharedState().SetPatternValue(TEXT("EEex::Opcode_Hook_SetTemporaryAIScript_OnRemove"), EEex::Opcode_Hook_SetTemporaryAIScript_OnRemove);
		// New op401
		sharedState().SetPatternValue(TEXT("EEex::Opcode_Hook_SetExtendedStat_ApplyEffect"), EEex::Opcode_Hook_SetExtendedStat_ApplyEffect);
		// New op403
		sharedState().SetPatternValue(TEXT("EEex::Opcode_Hook_ScreenEffects_ApplyEffect"), EEex::Opcode_Hook_ScreenEffects_ApplyEffect);
		// New op408
		sharedState().SetPatternValue(TEXT("EEex::Opcode_Hook_ProjectileMutator_ApplyEffect"), EEex::Opcode_Hook_ProjectileMutator_ApplyEffect);
		// New op409
		sharedState().SetPatternValue(TEXT("EEex::Opcode_Hook_EnableActionListener_ApplyEffect"), EEex::Opcode_Hook_EnableActionListener_ApplyEffect);
		
		sharedState().SetPatternValue(TEXT("EEex::Opcode_Hook_OnCopy"), EEex::Opcode_Hook_OnCopy);
		sharedState().SetPatternValue(TEXT("EEex::Opcode_Hook_OnDestruct"), EEex::Opcode_Hook_OnDestruct);
		sharedState().SetPatternValue(TEXT("EEex::Opcode_Hook_ApplySpell_ShouldFlipSplprotSourceAndTarget"), EEex::Opcode_Hook_ApplySpell_ShouldFlipSplprotSourceAndTarget);
		sharedState().SetPatternValue(TEXT("EEex::Opcode_Hook_OnCheckAdd"), EEex::Opcode_Hook_OnCheckAdd);
		sharedState().SetPatternValue(TEXT("EEex::Opcode_Hook_AfterListsResolved"), EEex::Opcode_Hook_AfterListsResolved);

		////////////
		// Action //
		////////////

		sharedState().SetPatternValue(TEXT("EEex::Action_Hook_OnAfterSpriteStartedAction"), EEex::Action_Hook_OnAfterSpriteStartedAction);

		////////////////
		// Projectile //
		////////////////

		sharedState().SetPatternValue(TEXT("EEex::Projectile_Hook_OnBeforeAddEffect"), EEex::Projectile_Hook_OnBeforeAddEffect);
		sharedState().SetPatternValue(TEXT("EEex::Projectile_Hook_OnBeforeDecode"), EEex::Projectile_Hook_OnBeforeDecode);
		sharedState().SetPatternValue(TEXT("EEex::Projectile_Hook_OnAfterDecode"), EEex::Projectile_Hook_OnAfterDecode);

		////////////
		// Script //
		////////////

		sharedState().SetPatternValue(TEXT("EEex::Script_Hook_OnRead"), EEex::Script_Hook_OnRead);
		sharedState().SetPatternValue(TEXT("EEex::Script_Hook_OnCopy"), EEex::Script_Hook_OnCopy);
		sharedState().SetPatternValue(TEXT("EEex::Script_Hook_OnDestruct"), EEex::Script_Hook_OnDestruct);
	});

	// Populate internal engine pointers from patterns
	for (auto& pair : internalPointersMap) {
		uintptr_t patternVal;
		if (sharedState().GetPatternValue(pair.first, patternVal)) {
			*pair.second = reinterpret_cast<void*>(patternVal);
		}
		else {
			PrintT(TEXT("[!][EEex.dll] Function pattern [%s] not present for bindings; calling this function will crash the game!\n"), pair.first);
		}
	}

	InitGenerated();

	EEex::InitEEex();

	// Export lua bindings
	OpenBindings(luaState());
}
