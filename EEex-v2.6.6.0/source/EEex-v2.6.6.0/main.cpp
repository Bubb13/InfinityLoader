
#include "Baldur-v2.6.6.0_generated.h"
#include "EEex.h"
#include "EEexLua_generated.h"

static void exportPattern(const String& name, void* value) {

	PatternValueHandle handle;
	if (sharedState().GetOrCreatePatternValue(name, PatternValueType::SINGLE, handle)) {
		FPrintT(TEXT("[!][EEex.dll] exportPattern() - [%s].Type must be SINGLE\n"), name.c_str());
		return;
	}

	sharedState().SetSinglePatternValue(handle, value);
}

// Ugly hack to get a member-function pointer
template<typename T>
static constexpr void* getMemberPtr(T func) {
	return reinterpret_cast<void*&>(func);
}

static void exportPatterns() {

	///////////////////////////////////////////////
	//          Hook Integrity Watchdog          //
	///////////////////////////////////////////////

	exportPattern(TEXT("EEex::HookIntegrityWatchdogEnter"), EEex::HookIntegrityWatchdogEnter);
	exportPattern(TEXT("EEex::HookIntegrityWatchdogExit"), EEex::HookIntegrityWatchdogExit);

	/////////////////////////////////
	//          Overrides          //
	/////////////////////////////////

	exportPattern(TEXT("CAICondition::Override_Hold"), getMemberPtr(&CAICondition::Override_Hold));
	exportPattern(TEXT("CAICondition::Override_TriggerHolds"), getMemberPtr(&CAICondition::Override_TriggerHolds));
	exportPattern(TEXT("CGameAIBase::Override_ApplyTriggers"), getMemberPtr(&CGameAIBase::Override_ApplyTriggers));
	exportPattern(TEXT("CGameAIBase::Override_SetTrigger"), getMemberPtr(&CGameAIBase::Override_SetTrigger));
	exportPattern(TEXT("CGameArea::Override_AddClairvoyanceObject(CGameSprite*,CPoint,int)"), getMemberPtr(&CGameArea::Override_AddClairvoyanceObject));
	exportPattern(TEXT("CGameEffectList::Override_Unmarshal"), getMemberPtr(&CGameEffectList::Override_Unmarshal));
	exportPattern(TEXT("CGameEffectUsability::Override_CheckUsability"), getMemberPtr(&CGameEffectUsability::Override_CheckUsability));
	exportPattern(TEXT("CGameSprite::Override_CheckIfVisible"), getMemberPtr(&CGameSprite::Override_CheckIfVisible));
	exportPattern(TEXT("CGameSprite::Override_Damage"), getMemberPtr(&CGameSprite::Override_Damage));
	exportPattern(TEXT("CGameSprite::Override_SetVisualRange"), getMemberPtr(&CGameSprite::Override_SetVisualRange));
	exportPattern(TEXT("CMessageSetLastObject::Override_Run"), getMemberPtr(&CMessageSetLastObject::Override_Run));
	exportPattern(TEXT("CVisibilityMap::Override_AddCharacter"), getMemberPtr(&CVisibilityMap::Override_AddCharacter));
	exportPattern(TEXT("CVisibilityMap::Override_IsCharacterIdOnMap"), getMemberPtr(&CVisibilityMap::Override_IsCharacterIdOnMap));
	exportPattern(TEXT("CVisibilityMap::Override_RemoveCharacter"), getMemberPtr(&CVisibilityMap::Override_RemoveCharacter));
	exportPattern(TEXT("CVisibilityMap::Override_UpDate"), getMemberPtr(&CVisibilityMap::Override_UpDate));
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
	exportPattern(TEXT("EEex::GameState_Hook_OnAfterGlobalVariablesUnmarshalled"), EEex::GameState_Hook_OnAfterGlobalVariablesUnmarshalled);

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

	// op101
	exportPattern(TEXT("EEex::Opcode_Hook_Op101_ShouldEffectBypassImmunity"), EEex::Opcode_Hook_Op101_ShouldEffectBypassImmunity);
	// op248
	exportPattern(TEXT("EEex::Opcode_Hook_OnOp248AddTail"), EEex::Opcode_Hook_OnOp248AddTail);
	// op249
	exportPattern(TEXT("EEex::Opcode_Hook_OnOp249AddTail"), EEex::Opcode_Hook_OnOp249AddTail);
	// op280
	exportPattern(TEXT("EEex::Opcode_Hook_Op280_BeforeApplyEffect"), EEex::Opcode_Hook_Op280_BeforeApplyEffect);
	exportPattern(TEXT("EEex::Opcode_Hook_Op280_GetForcedWildSurgeNumber"), EEex::Opcode_Hook_Op280_GetForcedWildSurgeNumber);
	exportPattern(TEXT("EEex::Opcode_Hook_Op280_ShouldSuppressWildSurgeVisuals"), EEex::Opcode_Hook_Op280_ShouldSuppressWildSurgeVisuals);
	// op319
	exportPattern(TEXT("EEex::Opcode_Hook_Op319_IsInverted"), EEex::Opcode_Hook_Op319_IsInverted);
	// New op400
	exportPattern(TEXT("EEex::Opcode_Hook_SetTemporaryAIScript_ApplyEffect"), EEex::Opcode_Hook_SetTemporaryAIScript_ApplyEffect);
	exportPattern(TEXT("EEex::Opcode_Hook_SetTemporaryAIScript_OnRemove"), EEex::Opcode_Hook_SetTemporaryAIScript_OnRemove);
	// New op401
	exportPattern(TEXT("EEex::Opcode_Hook_SetExtendedStat_ApplyEffect"), EEex::Opcode_Hook_SetExtendedStat_ApplyEffect);
	// New op403
	exportPattern(TEXT("EEex::Opcode_Hook_ScreenEffects_ApplyEffect"), EEex::Opcode_Hook_ScreenEffects_ApplyEffect);
	exportPattern(TEXT("EEex::Opcode_Hook_ScreenEffects_OnRemove"), EEex::Opcode_Hook_ScreenEffects_OnRemove);
	// New op408
	exportPattern(TEXT("EEex::Opcode_Hook_ProjectileMutator_ApplyEffect"), EEex::Opcode_Hook_ProjectileMutator_ApplyEffect);
	exportPattern(TEXT("EEex::Opcode_Hook_ProjectileMutator_OnRemove"), EEex::Opcode_Hook_ProjectileMutator_OnRemove);
	// New op409
	exportPattern(TEXT("EEex::Opcode_Hook_EnableActionListener_ApplyEffect"), EEex::Opcode_Hook_EnableActionListener_ApplyEffect);
	exportPattern(TEXT("EEex::Opcode_Hook_EnableActionListener_OnRemove"), EEex::Opcode_Hook_EnableActionListener_OnRemove);

	exportPattern(TEXT("EEex::Opcode_Hook_OnCopy"), EEex::Opcode_Hook_OnCopy);
	exportPattern(TEXT("EEex::Opcode_Hook_OnDestruct"), EEex::Opcode_Hook_OnDestruct);
	exportPattern(TEXT("EEex::Opcode_Hook_ApplySpell_ShouldFlipSplprotSourceAndTarget"), EEex::Opcode_Hook_ApplySpell_ShouldFlipSplprotSourceAndTarget);
	exportPattern(TEXT("EEex::Opcode_Hook_OnCheckAdd"), EEex::Opcode_Hook_OnCheckAdd);
	exportPattern(TEXT("EEex::Opcode_Hook_AfterListsResolved"), EEex::Opcode_Hook_AfterListsResolved);

	////////////
	// Sprite //
	////////////

	exportPattern(TEXT("EEex::Sprite_Hook_OnConstruct"), EEex::Sprite_Hook_OnConstruct);
	exportPattern(TEXT("EEex::Sprite_Hook_OnDestruct"), EEex::Sprite_Hook_OnDestruct);
	exportPattern(TEXT("EEex::Sprite_Hook_OnAfterEffectListUnmarshalled"), EEex::Sprite_Hook_OnAfterEffectListUnmarshalled);
	exportPattern(TEXT("EEex::Sprite_Hook_OnBeforeEffectListMarshalled"), EEex::Sprite_Hook_OnBeforeEffectListMarshalled);

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

	/////////
	// Fix //
	/////////

	exportPattern(TEXT("EEex::Fix_Hook_ShouldProcessEffectListSkipRolls"), EEex::Fix_Hook_ShouldProcessEffectListSkipRolls);
	exportPattern(TEXT("EEex::Fix_Hook_ShouldTransformSpellImmunityStrref"), EEex::Fix_Hook_ShouldTransformSpellImmunityStrref);
	exportPattern(TEXT("EEex::Fix_Hook_SpellImmunityShouldSkipItemIndexing"), EEex::Fix_Hook_SpellImmunityShouldSkipItemIndexing);

	/////////////
	// Trigger //
	/////////////

	exportPattern(TEXT("EEex::Trigger_Hook_OnScriptLevelHit"), EEex::Trigger_Hook_OnScriptLevelHit);
	exportPattern(TEXT("EEex::Trigger_Hook_OnConditionResponseHit"), EEex::Trigger_Hook_OnConditionResponseHit);

	////////////////////
	// Visibility Map //
	////////////////////

	exportPattern(TEXT("EEex::VisibilityMap_Hook_OnConstruct"), EEex::VisibilityMap_Hook_OnConstruct);
	exportPattern(TEXT("EEex::VisibilityMap_Hook_OnDestruct"), EEex::VisibilityMap_Hook_OnDestruct);

	///////////////////////////////
	//          Globals          //
	///////////////////////////////

	exportPattern(TEXT("EEex::bInTrackedResponse"), &EEex::bInTrackedResponse);
	exportPattern(TEXT("EEex::bNoUUID"), &EEex::bNoUUID);
	exportPattern(TEXT("EEex::bStripUUID"), &EEex::bStripUUID);
	exportPattern(TEXT("EEex::CGameSprite_Hit_Roll"), &EEex::CGameSprite_Hit_Roll);
}

void __stdcall InitBindings(SharedState argSharedState) {

	sharedState() = argSharedState;
	InitBindingsInternal();

	EEex::InitEEex();
	exportPatterns();
}

void __stdcall OpenBindings() {

	InitLuaBindingsCommon(sharedState());

	// Export lua bindings
	OpenBindingsInternal(luaState());
}
