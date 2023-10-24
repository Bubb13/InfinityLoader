
#include "Baldur-v2.6.6.0_generated.h"
#include "EEex.h"
#include "EEexLua_generated.h"

void exportPattern(const String& name, void* value) {

	PatternValueHandle handle;
	if (sharedState().GetOrCreatePatternValue(name, PatternValueType::SINGLE, handle)) {
		PrintT(TEXT("[!][EEex.dll] exportPattern() - [%s].Type must be SINGLE\n"), name.c_str());
		return;
	}

	sharedState().SetSinglePatternValue(handle, value);
}

void exportPatterns() {

	////////////////////////////////////////////
	//          Integrity Check Util          //
	////////////////////////////////////////////

	exportPattern(TEXT("EEex::IntegrityCheckEnter"), EEex::IntegrityCheckEnter);
	exportPattern(TEXT("EEex::IntegrityCheckExit"), EEex::IntegrityCheckExit);

	/////////////////////////////////
	//          Overrides          //
	/////////////////////////////////

	exportPattern(TEXT("EEex::Override_bootstrapLua"), EEex::Override_bootstrapLua);
	exportPattern(TEXT("EEex::Override_CGameEffect_CheckSave"), EEex::Override_CGameEffect_CheckSave);
	exportPattern(TEXT("EEex::Override_chWriteInifile"), EEex::Override_chWriteInifile);
	exportPattern(TEXT("EEex::Override_Infinity_WriteINILine"), EEex::Override_Infinity_WriteINILine);

	/////////////////////////////
	//          Hooks          //
	/////////////////////////////

	////////////////
	// Game State //
	////////////////

	exportPattern(TEXT("EEex::GameState_Hook_OnInitialized"), EEex::GameState_Hook_OnInitialized);

	///////////
	// Stats //
	///////////

	exportPattern(TEXT("EEex::Stats_Hook_OnConstruct"), EEex::Stats_Hook_OnConstruct);
	exportPattern(TEXT("EEex::Stats_Hook_OnDestruct"), EEex::Stats_Hook_OnDestruct);
	exportPattern(TEXT("EEex::Stats_Hook_OnReload"), EEex::Stats_Hook_OnReload);
	exportPattern(TEXT("EEex::Stats_Hook_OnEqu"), EEex::Stats_Hook_OnEqu);
	exportPattern(TEXT("EEex::Stats_Hook_OnPlusEqu"), EEex::Stats_Hook_OnPlusEqu);
	exportPattern(TEXT("EEex::Stats_Hook_OnGettingUnknown"), EEex::Stats_Hook_OnGettingUnknown);

	////////////
	// Opcode //
	////////////

	// op248
	exportPattern(TEXT("EEex::Opcode_Hook_OnOp248AddTail"), EEex::Opcode_Hook_OnOp248AddTail);
	// op249
	exportPattern(TEXT("EEex::Opcode_Hook_OnOp249AddTail"), EEex::Opcode_Hook_OnOp249AddTail);
	// New op400
	exportPattern(TEXT("EEex::Opcode_Hook_SetTemporaryAIScript_ApplyEffect"), EEex::Opcode_Hook_SetTemporaryAIScript_ApplyEffect);
	exportPattern(TEXT("EEex::Opcode_Hook_SetTemporaryAIScript_OnRemove"), EEex::Opcode_Hook_SetTemporaryAIScript_OnRemove);
	// New op401
	exportPattern(TEXT("EEex::Opcode_Hook_SetExtendedStat_ApplyEffect"), EEex::Opcode_Hook_SetExtendedStat_ApplyEffect);
	// New op403
	exportPattern(TEXT("EEex::Opcode_Hook_ScreenEffects_ApplyEffect"), EEex::Opcode_Hook_ScreenEffects_ApplyEffect);
	// New op408
	exportPattern(TEXT("EEex::Opcode_Hook_ProjectileMutator_ApplyEffect"), EEex::Opcode_Hook_ProjectileMutator_ApplyEffect);
	// New op409
	exportPattern(TEXT("EEex::Opcode_Hook_EnableActionListener_ApplyEffect"), EEex::Opcode_Hook_EnableActionListener_ApplyEffect);

	exportPattern(TEXT("EEex::Opcode_Hook_OnCopy"), EEex::Opcode_Hook_OnCopy);
	exportPattern(TEXT("EEex::Opcode_Hook_OnDestruct"), EEex::Opcode_Hook_OnDestruct);
	exportPattern(TEXT("EEex::Opcode_Hook_ApplySpell_ShouldFlipSplprotSourceAndTarget"), EEex::Opcode_Hook_ApplySpell_ShouldFlipSplprotSourceAndTarget);
	exportPattern(TEXT("EEex::Opcode_Hook_OnCheckAdd"), EEex::Opcode_Hook_OnCheckAdd);
	exportPattern(TEXT("EEex::Opcode_Hook_AfterListsResolved"), EEex::Opcode_Hook_AfterListsResolved);

	////////////
	// Action //
	////////////

	exportPattern(TEXT("EEex::Action_Hook_OnAfterSpriteStartedAction"), EEex::Action_Hook_OnAfterSpriteStartedAction);

	////////////////
	// Projectile //
	////////////////

	exportPattern(TEXT("EEex::Projectile_Hook_OnBeforeAddEffect"), EEex::Projectile_Hook_OnBeforeAddEffect);
	exportPattern(TEXT("EEex::Projectile_Hook_OnBeforeDecode"), EEex::Projectile_Hook_OnBeforeDecode);
	exportPattern(TEXT("EEex::Projectile_Hook_OnAfterDecode"), EEex::Projectile_Hook_OnAfterDecode);

	////////////
	// Script //
	////////////

	exportPattern(TEXT("EEex::Script_Hook_OnRead"), EEex::Script_Hook_OnRead);
	exportPattern(TEXT("EEex::Script_Hook_OnCopy"), EEex::Script_Hook_OnCopy);
	exportPattern(TEXT("EEex::Script_Hook_OnDestruct"), EEex::Script_Hook_OnDestruct);
}

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
				PrintT(TEXT("[!][EEex.dll] Init() - Function pattern [%s] not present for bindings; calling this function will crash the game!\n"), pair.first);
				break;
			}
			default: {
				PrintT(TEXT("[!][EEex.dll] Init() - [%s].Type must be SINGLE\n"), pair.first);
				break;
			}
		}
	}

	EEex::InitEEex();
	exportPatterns();
}

void __stdcall OpenBindings() {

	InitLuaBindingsCommon(sharedState());

	// Export lua bindings
	OpenBindingsInternal(luaState());
}
