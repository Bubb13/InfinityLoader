
#pragma once

#include "Baldur-v2.6.6.0_generated.h"

namespace EEex {

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

	int Override_CGameEffect_CheckSave(CGameEffect* pEffect, CGameSprite* pSprite, byte* saveVSDeathRollRaw, byte* saveVSWandsRollRaw, byte* saveVSPolyRollRaw, byte* saveVSBreathRollRaw, byte* saveVSSpellRollRaw, byte* resistMagicRollRaw);
	
	//-------------------------//
	//          Hooks          //
	//-------------------------//

	////////////////
	// Game State //
	////////////////

	void GameState_Hook_OnInitialized();

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

	// op248
	void Opcode_Hook_OnOp248AddTail(CGameEffect* pOp248, CGameEffect* pEffect);
	// op249
	void Opcode_Hook_OnOp249AddTail(CGameEffect* pOp249, CGameEffect* pEffect);
	// New op400
	int Opcode_Hook_SetTemporaryAIScript_ApplyEffect(CGameEffect* pEffect, CGameSprite* pSprite);
	void Opcode_Hook_SetTemporaryAIScript_OnRemove(CGameEffect* pEffect, CGameSprite* pSprite);
	// New op401
	int Opcode_Hook_SetExtendedStat_ApplyEffect(CGameEffect* pEffect, CGameSprite* pSprite);
	// New op403
	int Opcode_Hook_ScreenEffects_ApplyEffect(CGameEffect* pEffect, CGameSprite* pSprite);
	// New op408
	int Opcode_Hook_ProjectileMutator_ApplyEffect(CGameEffect* pEffect, CGameSprite* pSprite);
	// New op409
	int Opcode_Hook_EnableActionListener_ApplyEffect(CGameEffect* pEffect, CGameSprite* pSprite);

	int Opcode_Hook_ApplySpell_ShouldFlipSplprotSourceAndTarget(CGameEffect* pEffect);
	int Opcode_Hook_OnCheckAdd(CGameEffect* pEffect, CGameSprite* pSprite);
	void Opcode_Hook_OnCopy(CGameEffect* pSrcEffect, CGameEffect* pDstEffect);
	void Opcode_Hook_OnDestruct(CGameEffect* pEffect);
	void Opcode_Hook_AfterListsResolved(CGameSprite* pSprite);

	////////////
	// Action //
	////////////

	void Action_Hook_OnAfterSpriteStartedAction(CGameSprite* pSprite);

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
}