
#pragma once

#include "Baldur-v2.6.6.0_generated.h"

#pragma pack(push, 1)
struct RegisterValues {
	uintptr_t rax;
	uintptr_t rbx;
	uintptr_t rcx;
	uintptr_t rdx;
	uintptr_t rbp;
	uintptr_t rsp;
	uintptr_t rsi;
	uintptr_t rdi;
	uintptr_t r8;
	uintptr_t r9;
	uintptr_t r10;
	uintptr_t r11;
	uintptr_t r12;
	uintptr_t r13;
	uintptr_t r14;
	uintptr_t r15;
};
#pragma pack(pop)

namespace EEex {

	//-------------------------------------------//
	//          Hook Integrity Watchdog          //
	//-------------------------------------------//

	void HookIntegrityWatchdogEnter(uintptr_t hookAddress, const RegisterValues* registers);
	void HookIntegrityWatchdogExit(uintptr_t hookAddress, size_t instance, const RegisterValues* registers);

	//------------------------//
	//          Misc          //
	//------------------------//

	void DeepCopy(lua_State* L);
	void DeepCopyIndex(lua_State* L, int index);
	void InitEEex();
	long MatchObject(lua_State* L, CGameObject* pStartObject, const char* matchChunk, int nNearest, int range, EEex_MatchObjectFlags flags);

	//-----------------------------//
	//          Overrides          //
	//-----------------------------//

	void Override_bootstrapLua();
	int Override_CGameEffect_CheckSave(CGameEffect* pEffect, CGameSprite* pSprite, byte* saveVSDeathRollRaw, byte* saveVSWandsRollRaw, byte* saveVSPolyRollRaw, byte* saveVSBreathRollRaw, byte* saveVSSpellRollRaw, byte* resistMagicRollRaw);
	void __cdecl Override_chWriteInifile();
	//int __cdecl Override_fontWrap(char* text, SDL_Rect* r, SDL_Rect* rClip, int* horizontalAlignment, int* verticalAlignment, font_t* font, int* pointSize, letter_t* letters, int* nlines, int* nletters, int* pointIndex, bool* scale, adjustmentData_t* adjustData, int indent, bool bUseFontSizeFloor);
	int __cdecl Override_Infinity_TransitionMenu(lua_State* L);
	int __cdecl Override_Infinity_WriteINILine(lua_State* L);
	void __cdecl Override_uiDoFile(char* fileName);
	bool __cdecl Override_uiEventMenuStack(SDL_Event* pEvent, SDL_Rect* pWindow);

	//-------------------------//
	//          Hooks          //
	//-------------------------//

	////////////////
	// Game State //
	////////////////

	void GameState_Hook_OnInitialized();
	void GameState_Hook_OnAfterGlobalVariablesUnmarshalled();

	///////////
	// Stats //
	///////////

	void Stats_Hook_OnConstruct(CDerivedStats* pStats);
	void Stats_Hook_OnDestruct(CDerivedStats* pStats);
	void Stats_Hook_OnReload(CGameSprite* pSprite);
	void Stats_Hook_OnEqu(CDerivedStats* pStats, CDerivedStats* pOtherStats);
	void Stats_Hook_OnPlusEqu(CDerivedStats* pStats, CDerivedStats* pOtherStats);
	int Stats_Hook_OnGettingUnknown(CDerivedStats* pStats, int nStatId);

	////////////
	// Opcode //
	////////////

	// op101
	bool Opcode_Hook_Op101_ShouldEffectBypassImmunity(CGameEffect* pEffect);
	// op248
	void Opcode_Hook_OnOp248AddTail(CGameEffect* pOp248, CGameEffect* pEffect);
	// op249
	void Opcode_Hook_OnOp249AddTail(CGameEffect* pOp249, CGameEffect* pEffect);
	// op280
	void Opcode_Hook_Op280_BeforeApplyEffect(CGameEffect* pEffect, CGameSprite* pSprite);
	int Opcode_Hook_Op280_GetForcedWildSurgeNumber(CGameSprite* pSprite);
	bool Opcode_Hook_Op280_ShouldSuppressWildSurgeVisuals(CGameSprite* pSprite);
	// op319
	bool Opcode_Hook_Op319_IsInverted(CGameEffect* pEffect);
	// New op400
	int Opcode_Hook_SetTemporaryAIScript_ApplyEffect(CGameEffect* pEffect, CGameSprite* pSprite);
	void Opcode_Hook_SetTemporaryAIScript_OnRemove(CGameEffect* pEffect, CGameSprite* pSprite);
	// New op401
	int Opcode_Hook_SetExtendedStat_ApplyEffect(CGameEffect* pEffect, CGameSprite* pSprite);
	// New op403
	int Opcode_Hook_ScreenEffects_ApplyEffect(CGameEffect* pEffect, CGameSprite* pSprite);
	void Opcode_Hook_ScreenEffects_OnRemove(CGameEffect* pEffect, CGameSprite* pSprite);
	// New op408
	int Opcode_Hook_ProjectileMutator_ApplyEffect(CGameEffect* pEffect, CGameSprite* pSprite);
	void Opcode_Hook_ProjectileMutator_OnRemove(CGameEffect* pEffect, CGameSprite* pSprite);
	// New op409
	int Opcode_Hook_EnableActionListener_ApplyEffect(CGameEffect* pEffect, CGameSprite* pSprite);
	void Opcode_Hook_EnableActionListener_OnRemove(CGameEffect* pEffect, CGameSprite* pSprite);

	int Opcode_Hook_ApplySpell_ShouldFlipSplprotSourceAndTarget(CGameEffect* pEffect);
	int Opcode_Hook_OnCheckAdd(CGameEffect* pEffect, CGameSprite* pSprite);
	void Opcode_Hook_OnCopy(CGameEffect* pSrcEffect, CGameEffect* pDstEffect);
	void Opcode_Hook_OnDestruct(CGameEffect* pEffect);
	void Opcode_Hook_AfterListsResolved(CGameSprite* pSprite);

	////////////
	// Sprite //
	////////////

	void Sprite_Hook_OnConstruct(CGameSprite* pSprite);
	void Sprite_Hook_OnDestruct(CGameSprite* pSprite);
	void Sprite_Hook_OnAfterEffectListUnmarshalled(CGameSprite* pSprite);
	void Sprite_Hook_OnBeforeEffectListMarshalled(CGameSprite* pSprite);

	////////////
	// Action //
	////////////

	void Action_Hook_OnAfterSpriteStartedAction(CGameSprite* pSprite);

	//////////
	// Menu //
	//////////

	void Menu_Hook_CheckApplyTextScrollbarPad(uiItem* pItem, SDL_Rect* pItemArea);
	void Menu_Hook_FreeUITemplate(uiItem* pItem);
	void Menu_Hook_OnBeforeMenuStackSave();

	////////////////
	// Projectile //
	////////////////

	void Projectile_Hook_OnBeforeAddEffect(CProjectile* pProjectile, CGameAIBase* pDecoder, CGameEffect* pEffect, uintptr_t pRetPtr);
	ushort Projectile_Hook_OnBeforeDecode(ushort nProjectileType, CGameAIBase* pDecoder, uintptr_t pRetPtr);
	void Projectile_Hook_OnAfterDecode(CProjectile* pProjectile, CGameAIBase* pDecoder, uintptr_t pRetPtr);

	////////////
	// Script //
	////////////

	void Script_Hook_OnRead(CAIScript* pScript, bool bPlayerScript);
	void Script_Hook_OnCopy(CAIScript* pSrcScript, CAIScript* pDstScript);
	void Script_Hook_OnDestruct(CAIScript* pScript);

	/////////
	// Fix //
	/////////

	void Fix_Hook_HandleMiddleMouseDrag(SDL_Event* pEvent);
	void Fix_Hook_OnBeforeUIKillCapture();
	bool Fix_Hook_OnUIItemCheckRenderScrollbar(uiItem* pItem, bool bVisible);
	bool Fix_Hook_ShouldProcessEffectListSkipRolls();
	bool Fix_Hook_ShouldTransformSpellImmunityStrref(CGameEffect* pEffect, CImmunitySpell* pImmunitySpell);
	bool Fix_Hook_SpellImmunityShouldSkipItemIndexing(CGameObject* pGameObject);

	/////////////
	// Trigger //
	/////////////

	void Trigger_Hook_OnScriptLevelHit(CGameAIBase* pCaller, unsigned char nScriptLevel);
	void Trigger_Hook_OnConditionResponseHit(int16_t nResponseSetNum);

	///////////////
	// Uncap FPS //
	///////////////

	void UncapFPS_Hook_OnAfterAreaActivated(CGameArea* pArea);
	void UncapFPS_Hook_OnAfterAreaEdgeScrollPossiblyStarted(CGameArea* pArea);
	void UncapFPS_Hook_OnBeforeAreaDeactivated(CGameArea* pArea);
	void UncapFPS_Hook_OnBeforeWorldScreenDeactivated();
	void UncapFPS_Hook_HandleAreaAutoZoom();
	void UncapFPS_Hook_HandleTransitionMenuFade();

	////////////////////
	// Visibility Map //
	////////////////////

	void VisibilityMap_Hook_OnConstruct(CVisibilityMap* pThis);
	void VisibilityMap_Hook_OnDestruct(CVisibilityMap* pThis);

	//---------------------------//
	//          Exports          //
	//---------------------------//

	EXPORT void RegisterScriptLevelHitCallback(std::function<void(CGameAIBase*, unsigned char)> callback);
	EXPORT void RegisterConditionResponseHitCallback(std::function<void(int16_t)> callback);
	EXPORT void RegisterTriggerHitCallback(std::function<void(int32_t)> callback);
	EXPORT void RegisterTriggerEvaluatedCallback(std::function<void(bool)> callback);
}
