
#include "EEexLua_generated_baseclass_offsets.h"

template<typename Derived, typename Base>
constexpr uintptr_t offsetofbase() {
	return reinterpret_cast<uintptr_t>(static_cast<Base*>(reinterpret_cast<Derived*>(1))) - 1;
}

std::unordered_map<const char*, std::unordered_map<const char*, uintptr_t>> baseclassOffsets {
	{"CResInfTile", {
		{"CResTile", offsetofbase<CResInfTile, CResTile>()},
	}},
	{"CSnowFlake", {
		{"CParticle", offsetofbase<CSnowFlake, CParticle>()},
	}},
	{"CRainDrop", {
		{"CParticle", offsetofbase<CRainDrop, CParticle>()},
	}},
	{"CPoint", {
		{"tagPOINT", offsetofbase<CPoint, tagPOINT>()},
	}},
	{"CRect", {
		{"tagRECT", offsetofbase<CRect, tagRECT>()},
	}},
	{"CSize", {
		{"tagSIZE", offsetofbase<CSize, tagSIZE>()},
	}},
	{"CSpawnPointVar", {
		{"CSpawnVar", offsetofbase<CSpawnPointVar, CSpawnVar>()},
	}},
	{"CResWebm", {
		{"CRes", offsetofbase<CResWebm, CRes>()},
	}},
	{"CResWave", {
		{"CRes", offsetofbase<CResWave, CRes>()},
	}},
	{"CResWED", {
		{"CRes", offsetofbase<CResWED, CRes>()},
	}},
	{"CResTileSet", {
		{"CRes", offsetofbase<CResTileSet, CRes>()},
	}},
	{"CResText", {
		{"CRes", offsetofbase<CResText, CRes>()},
	}},
	{"CResSpell", {
		{"CRes", offsetofbase<CResSpell, CRes>()},
	}},
	{"CResPVR", {
		{"CRes", offsetofbase<CResPVR, CRes>()},
	}},
	{"CResMosaic", {
		{"CRes", offsetofbase<CResMosaic, CRes>()},
	}},
	{"CResItem", {
		{"CRes", offsetofbase<CResItem, CRes>()},
	}},
	{"CResGame", {
		{"CRes", offsetofbase<CResGame, CRes>()},
	}},
	{"CResFont", {
		{"CRes", offsetofbase<CResFont, CRes>()},
	}},
	{"CResCell", {
		{"CRes", offsetofbase<CResCell, CRes>()},
	}},
	{"CResBitmap", {
		{"CRes", offsetofbase<CResBitmap, CRes>()},
	}},
	{"CList<long,long>", {
		{"CObject", offsetofbase<CList<long,long>, CObject>()},
	}},
	{"CTypedPtrList<CPtrList,CAIId*>", {
		{"CObject", offsetofbase<CTypedPtrList<CPtrList,CAIId*>, CObject>()},
	}},
	{"CTypedPtrList<CPtrList,CCreatureFileKnownSpell*>", {
		{"CObject", offsetofbase<CTypedPtrList<CPtrList,CCreatureFileKnownSpell*>, CObject>()},
	}},
	{"CTypedPtrList<CPtrList,CCreatureFileMemorizedSpell*>", {
		{"CObject", offsetofbase<CTypedPtrList<CPtrList,CCreatureFileMemorizedSpell*>, CObject>()},
	}},
	{"CTypedPtrList<CPtrList,long*>", {
		{"CObject", offsetofbase<CTypedPtrList<CPtrList,long*>, CObject>()},
	}},
	{"CTypedPtrList<CPtrList,CBlood*>", {
		{"CObject", offsetofbase<CTypedPtrList<CPtrList,CBlood*>, CObject>()},
	}},
	{"CTypedPtrList<CPtrList,CPortraitIcon*>", {
		{"CObject", offsetofbase<CTypedPtrList<CPtrList,CPortraitIcon*>, CObject>()},
	}},
	{"CTypedPtrList<CPtrList,CPoint*>", {
		{"CObject", offsetofbase<CTypedPtrList<CPtrList,CPoint*>, CObject>()},
	}},
	{"CTypedPtrList<CPtrList,CFeedbackEntry*>", {
		{"CObject", offsetofbase<CTypedPtrList<CPtrList,CFeedbackEntry*>, CObject>()},
	}},
	{"CTypedPtrList<CPtrList,CGameSprite::GroundItem*>", {
		{"CObject", offsetofbase<CTypedPtrList<CPtrList,CGameSprite::GroundItem*>, CObject>()},
	}},
	{"CTypedPtrList<CPtrList,CResRef*>", {
		{"CObject", offsetofbase<CTypedPtrList<CPtrList,CResRef*>, CObject>()},
	}},
	{"CTypedPtrList<CPtrList,CSearchRequest*>", {
		{"CObject", offsetofbase<CTypedPtrList<CPtrList,CSearchRequest*>, CObject>()},
	}},
	{"CTypedPtrList<CPtrList,SAreaFileWrapper*>", {
		{"CObject", offsetofbase<CTypedPtrList<CPtrList,SAreaFileWrapper*>, CObject>()},
	}},
	{"CTypedPtrList<CPtrList,CSavedGameStoredLocation*>", {
		{"CObject", offsetofbase<CTypedPtrList<CPtrList,CSavedGameStoredLocation*>, CObject>()},
	}},
	{"CTypedPtrList<CPtrList,cnetworkwindow_queueentry_st*>", {
		{"CObject", offsetofbase<CTypedPtrList<CPtrList,cnetworkwindow_queueentry_st*>, CObject>()},
	}},
	{"CTypedPtrList<CPtrList,CMusicPosition*>", {
		{"CObject", offsetofbase<CTypedPtrList<CPtrList,CMusicPosition*>, CObject>()},
	}},
	{"CTypedPtrList<CPtrList,CGameJournalEntry*>", {
		{"CObject", offsetofbase<CTypedPtrList<CPtrList,CGameJournalEntry*>, CObject>()},
	}},
	{"CTypedPtrList<CPtrList,CMoveListEntry*>", {
		{"CObject", offsetofbase<CTypedPtrList<CPtrList,CMoveListEntry*>, CObject>()},
	}},
	{"CTypedPtrList<CPtrList,CAreaUserNote*>", {
		{"CObject", offsetofbase<CTypedPtrList<CPtrList,CAreaUserNote*>, CObject>()},
	}},
	{"CTypedPtrList<CPtrList,CAOEEntry*>", {
		{"CObject", offsetofbase<CTypedPtrList<CPtrList,CAOEEntry*>, CObject>()},
	}},
	{"CTypedPtrList<CPtrList,void*>", {
		{"CObject", offsetofbase<CTypedPtrList<CPtrList,void*>, CObject>()},
	}},
	{"CTypedPtrList<CPtrList,CAreaFileCharacterEntryPoint*>", {
		{"CObject", offsetofbase<CTypedPtrList<CPtrList,CAreaFileCharacterEntryPoint*>, CObject>()},
	}},
	{"CTypedPtrList<CPtrList,__POSITION*>", {
		{"CObject", offsetofbase<CTypedPtrList<CPtrList,__POSITION*>, CObject>()},
	}},
	{"CTypedPtrList<CPtrList,CTiledObject*>", {
		{"CObject", offsetofbase<CTypedPtrList<CPtrList,CTiledObject*>, CObject>()},
	}},
	{"CTypedPtrList<CPtrList,CGameAreaClairvoyanceEntry*>", {
		{"CObject", offsetofbase<CTypedPtrList<CPtrList,CGameAreaClairvoyanceEntry*>, CObject>()},
	}},
	{"CTypedPtrList<CPtrList,CGameEffectUsability*>", {
		{"CObject", offsetofbase<CTypedPtrList<CPtrList,CGameEffectUsability*>, CObject>()},
	}},
	{"CTypedPtrList<CPtrList,CStoreFileItem*>", {
		{"CObject", offsetofbase<CTypedPtrList<CPtrList,CStoreFileItem*>, CObject>()},
	}},
	{"CTypedPtrList<CPtrList,CMemINIValue*>", {
		{"CObject", offsetofbase<CTypedPtrList<CPtrList,CMemINIValue*>, CObject>()},
	}},
	{"CTypedPtrList<CPtrList,CAIConditionResponse*>", {
		{"CObject", offsetofbase<CTypedPtrList<CPtrList,CAIConditionResponse*>, CObject>()},
	}},
	{"CTypedPtrList<CPtrList,CAIResponse*>", {
		{"CObject", offsetofbase<CTypedPtrList<CPtrList,CAIResponse*>, CObject>()},
	}},
	{"CTypedPtrList<CPtrList,CAITrigger*>", {
		{"CObject", offsetofbase<CTypedPtrList<CPtrList,CAITrigger*>, CObject>()},
	}},
	{"CTypedPtrList<CPtrList,CAIAction*>", {
		{"CObject", offsetofbase<CTypedPtrList<CPtrList,CAIAction*>, CObject>()},
	}},
	{"CTypedPtrList<CPtrList,CSpawn*>", {
		{"CObject", offsetofbase<CTypedPtrList<CPtrList,CSpawn*>, CObject>()},
	}},
	{"CTypedPtrList<CPtrList,CGameEffect*>", {
		{"CObject", offsetofbase<CTypedPtrList<CPtrList,CGameEffect*>, CObject>()},
	}},
	{"CTypedPtrList<CPtrList,CAIObjectType*>", {
		{"CObject", offsetofbase<CTypedPtrList<CPtrList,CAIObjectType*>, CObject>()},
	}},
	{"CTypedPtrList<CPtrList,CWeaponIdentification*>", {
		{"CObject", offsetofbase<CTypedPtrList<CPtrList,CWeaponIdentification*>, CObject>()},
	}},
	{"CTypedPtrList<CPtrList,CSelectiveBonus*>", {
		{"CObject", offsetofbase<CTypedPtrList<CPtrList,CSelectiveBonus*>, CObject>()},
	}},
	{"CTypedPtrList<CPtrList,CImmunitiesItemEquip*>", {
		{"CObject", offsetofbase<CTypedPtrList<CPtrList,CImmunitiesItemEquip*>, CObject>()},
	}},
	{"CTypedPtrList<CPtrList,CImmunitiesItemTypeEquip*>", {
		{"CObject", offsetofbase<CTypedPtrList<CPtrList,CImmunitiesItemTypeEquip*>, CObject>()},
	}},
	{"CTypedPtrList<CPtrList,CImmunitySpell*>", {
		{"CObject", offsetofbase<CTypedPtrList<CPtrList,CImmunitySpell*>, CObject>()},
	}},
	{"CTypedPtrList<CPtrList,CSchoolAndSecondaryDecrementing*>", {
		{"CObject", offsetofbase<CTypedPtrList<CPtrList,CSchoolAndSecondaryDecrementing*>, CObject>()},
	}},
	{"CTypedPtrList<CPtrList,CContingency*>", {
		{"CObject", offsetofbase<CTypedPtrList<CPtrList,CContingency*>, CObject>()},
	}},
	{"CTypedPtrList<CPtrList,CPersistantEffect*>", {
		{"CObject", offsetofbase<CTypedPtrList<CPtrList,CPersistantEffect*>, CObject>()},
	}},
	{"CTypedPtrList<CPtrList,CColorRange*>", {
		{"CObject", offsetofbase<CTypedPtrList<CPtrList,CColorRange*>, CObject>()},
	}},
	{"CTypedPtrList<CPtrList,CColorEffect*>", {
		{"CObject", offsetofbase<CTypedPtrList<CPtrList,CColorEffect*>, CObject>()},
	}},
	{"CTypedPtrList<CPtrList,CSelectiveWeaponType*>", {
		{"CObject", offsetofbase<CTypedPtrList<CPtrList,CSelectiveWeaponType*>, CObject>()},
	}},
	{"CTypedPtrList<CPtrList,CCriticalEntry*>", {
		{"CObject", offsetofbase<CTypedPtrList<CPtrList,CCriticalEntry*>, CObject>()},
	}},
	{"CTypedPtrList<CPtrList,EEex_CGameOptions*>", {
		{"CObject", offsetofbase<CTypedPtrList<CPtrList,CGameOptions*>, CObject>()},
	}},
	{"CTypedPtrList<CPtrList,CDeathSound*>", {
		{"CObject", offsetofbase<CTypedPtrList<CPtrList,CDeathSound*>, CObject>()},
	}},
	{"CTypedPtrList<CPtrList,CString*>", {
		{"CObject", offsetofbase<CTypedPtrList<CPtrList,CString*>, CObject>()},
	}},
	{"CTypedPtrList<CPtrList,CMessage*>", {
		{"CObject", offsetofbase<CTypedPtrList<CPtrList,CMessage*>, CObject>()},
	}},
	{"CTypedPtrList<CPtrList,CGameTimer*>", {
		{"CObject", offsetofbase<CTypedPtrList<CPtrList,CGameTimer*>, CObject>()},
	}},
	{"CTypedPtrList<CPtrList,CBounceEntry*>", {
		{"CObject", offsetofbase<CTypedPtrList<CPtrList,CBounceEntry*>, CObject>()},
	}},
	{"CTypedPtrList<CPtrList,CSequenceSound*>", {
		{"CObject", offsetofbase<CTypedPtrList<CPtrList,CSequenceSound*>, CObject>()},
	}},
	{"CTypedPtrList<CPtrList,CButtonData*>", {
		{"CObject", offsetofbase<CTypedPtrList<CPtrList,CButtonData*>, CObject>()},
	}},
	{"CTypedPtrList<CPtrList,CItem*>", {
		{"CObject", offsetofbase<CTypedPtrList<CPtrList,CItem*>, CObject>()},
	}},
	{"CTypedPtrList<CPtrList,CParticle*>", {
		{"CObject", offsetofbase<CTypedPtrList<CPtrList,CParticle*>, CObject>()},
	}},
	{"CTypedPtrList<CPtrList,CVidCell*>", {
		{"CObject", offsetofbase<CTypedPtrList<CPtrList,CVidCell*>, CObject>()},
	}},
	{"CTypedPtrList<CPtrList,long>", {
		{"CObject", offsetofbase<CTypedPtrList<CPtrList,long>, CObject>()},
	}},
	{"CTypedPtrArray<CPtrArray,CRes*>", {
		{"CObject", offsetofbase<CTypedPtrArray<CPtrArray,CRes*>, CObject>()},
	}},
	{"CTypedPtrArray<CPtrArray,long*>", {
		{"CObject", offsetofbase<CTypedPtrArray<CPtrArray,long*>, CObject>()},
	}},
	{"CTypedPtrArray<CPtrArray,CTypedPtrList<CPtrList,CGameJournalEntry*>*>", {
		{"CObject", offsetofbase<CTypedPtrArray<CPtrArray,CTypedPtrList<CPtrList,CGameJournalEntry*>*>, CObject>()},
	}},
	{"CTypedPtrArray<CPtrArray,CSavedGamePartyCreature*>", {
		{"CObject", offsetofbase<CTypedPtrArray<CPtrArray,CSavedGamePartyCreature*>, CObject>()},
	}},
	{"CTypedPtrArray<CPtrArray,unsigned char*>", {
		{"CObject", offsetofbase<CTypedPtrArray<CPtrArray,unsigned char*>, CObject>()},
	}},
	{"CTypedPtrArray<CPtrArray,CAbilityData*>", {
		{"CObject", offsetofbase<CTypedPtrArray<CPtrArray,CAbilityData*>, CObject>()},
	}},
	{"CTypedPtrArray<CPtrArray,char>", {
		{"CObject", offsetofbase<CTypedPtrArray<CPtrArray,char>, CObject>()},
	}},
	{"CTypedPtrArray<CPtrArray,CSaveGameSlot*>", {
		{"CObject", offsetofbase<CTypedPtrArray<CPtrArray,CSaveGameSlot*>, CObject>()},
	}},
	{"CTypedPtrArray<CPtrArray,CGameDialogEntry*>", {
		{"CObject", offsetofbase<CTypedPtrArray<CPtrArray,CGameDialogEntry*>, CObject>()},
	}},
	{"CTypedPtrArray<CPtrArray,CSpawnPoint*>", {
		{"CObject", offsetofbase<CTypedPtrArray<CPtrArray,CSpawnPoint*>, CObject>()},
	}},
	{"CTypedPtrArray<CPtrArray,CGameDialogReply*>", {
		{"CObject", offsetofbase<CTypedPtrArray<CPtrArray,CGameDialogReply*>, CObject>()},
	}},
	{"CStringList", {
		{"CObject", offsetofbase<CStringList, CObject>()},
	}},
	{"CPtrList", {
		{"CObject", offsetofbase<CPtrList, CObject>()},
	}},
	{"CPersistantEffectList", {
		{"CTypedPtrList<CPtrList,CPersistantEffect*>", offsetofbase<CPersistantEffectList, CTypedPtrList<CPtrList,CPersistantEffect*>>()},
	}},
	{"CPersistantEffectListRegenerated", {
		{"CTypedPtrList<CPtrList,CPersistantEffect*>", offsetofbase<CPersistantEffectListRegenerated, CTypedPtrList<CPtrList,CPersistantEffect*>>()},
	}},
	{"CSpawnList", {
		{"CTypedPtrList<CPtrList,CSpawn*>", offsetofbase<CSpawnList, CTypedPtrList<CPtrList,CSpawn*>>()},
	}},
	{"CSpawnFile", {
		{"CTypedPtrList<CPtrList,void*>", offsetofbase<CSpawnFile, CTypedPtrList<CPtrList,void*>>()},
	}},
	{"CSequenceSoundList", {
		{"CTypedPtrList<CPtrList,CSequenceSound*>", offsetofbase<CSequenceSoundList, CTypedPtrList<CPtrList,CSequenceSound*>>()},
	}},
	{"CSelectiveWeaponTypeList", {
		{"CTypedPtrList<CPtrList,CSelectiveWeaponType*>", offsetofbase<CSelectiveWeaponTypeList, CTypedPtrList<CPtrList,CSelectiveWeaponType*>>()},
	}},
	{"CSelectiveBonusList", {
		{"CTypedPtrList<CPtrList,CSelectiveBonus*>", offsetofbase<CSelectiveBonusList, CTypedPtrList<CPtrList,CSelectiveBonus*>>()},
	}},
	{"CPtrArray", {
		{"CObject", offsetofbase<CPtrArray, CObject>()},
	}},
	{"CSpawnPointArray", {
		{"CTypedPtrArray<CPtrArray,CSpawnPoint*>", offsetofbase<CSpawnPointArray, CTypedPtrArray<CPtrArray,CSpawnPoint*>>()},
	}},
	{"CObList", {
		{"CObject", offsetofbase<CObList, CObject>()},
	}},
	{"EEex_CWarp", {
		{"CObject", offsetofbase<CWarp, CObject>()},
	}},
	{"CObArray", {
		{"CObject", offsetofbase<CObArray, CObject>()},
	}},
	{"CMoveList", {
		{"CTypedPtrList<CPtrList,CMoveListEntry*>", offsetofbase<CMoveList, CTypedPtrList<CPtrList,CMoveListEntry*>>()},
	}},
	{"CMemINISection", {
		{"CTypedPtrList<CPtrList,CMemINIValue*>", offsetofbase<CMemINISection, CTypedPtrList<CPtrList,CMemINIValue*>>()},
	}},
	{"CMemINI", {
		{"CTypedPtrList<CPtrList,void*>", offsetofbase<CMemINI, CTypedPtrList<CPtrList,void*>>()},
	}},
	{"CMapStringToString", {
		{"CObject", offsetofbase<CMapStringToString, CObject>()},
	}},
	{"CImmunitiesWeapon", {
		{"CTypedPtrList<CPtrList,CWeaponIdentification*>", offsetofbase<CImmunitiesWeapon, CTypedPtrList<CPtrList,CWeaponIdentification*>>()},
	}},
	{"CImmunitiesSpellList", {
		{"CTypedPtrList<CPtrList,CImmunitySpell*>", offsetofbase<CImmunitiesSpellList, CTypedPtrList<CPtrList,CImmunitySpell*>>()},
	}},
	{"CImmunitiesSchoolAndSecondaryDecrementing", {
		{"CTypedPtrList<CPtrList,CSchoolAndSecondaryDecrementing*>", offsetofbase<CImmunitiesSchoolAndSecondaryDecrementing, CTypedPtrList<CPtrList,CSchoolAndSecondaryDecrementing*>>()},
	}},
	{"CImmunitiesSchoolAndSecondary", {
		{"CTypedPtrList<CPtrList,long*>", offsetofbase<CImmunitiesSchoolAndSecondary, CTypedPtrList<CPtrList,long*>>()},
	}},
	{"CImmunitiesProjectile", {
		{"CTypedPtrList<CPtrList,long*>", offsetofbase<CImmunitiesProjectile, CTypedPtrList<CPtrList,long*>>()},
	}},
	{"CImmunitiesItemTypeEquipList", {
		{"CTypedPtrList<CPtrList,CImmunitiesItemTypeEquip*>", offsetofbase<CImmunitiesItemTypeEquipList, CTypedPtrList<CPtrList,CImmunitiesItemTypeEquip*>>()},
	}},
	{"CImmunitiesItemEquipList", {
		{"CTypedPtrList<CPtrList,CImmunitiesItemEquip*>", offsetofbase<CImmunitiesItemEquipList, CTypedPtrList<CPtrList,CImmunitiesItemEquip*>>()},
	}},
	{"CImmunitiesEffect", {
		{"CTypedPtrList<CPtrList,CGameEffect*>", offsetofbase<CImmunitiesEffect, CTypedPtrList<CPtrList,CGameEffect*>>()},
	}},
	{"CImmunitiesAIType", {
		{"CTypedPtrList<CPtrList,CAIObjectType*>", offsetofbase<CImmunitiesAIType, CTypedPtrList<CPtrList,CAIObjectType*>>()},
	}},
	{"CGameEffectUsabilityList", {
		{"CTypedPtrList<CPtrList,CGameEffectUsability*>", offsetofbase<CGameEffectUsabilityList, CTypedPtrList<CPtrList,CGameEffectUsability*>>()},
	}},
	{"CGameEffectList", {
		{"CTypedPtrList<CPtrList,CGameEffect*>", offsetofbase<CGameEffectList, CTypedPtrList<CPtrList,CGameEffect*>>()},
	}},
	{"CGameDialogEntry", {
		{"CTypedPtrArray<CPtrArray,CGameDialogReply*>", offsetofbase<CGameDialogEntry, CTypedPtrArray<CPtrArray,CGameDialogReply*>>()},
	}},
	{"CGameButtonList", {
		{"CTypedPtrList<CPtrList,CButtonData*>", offsetofbase<CGameButtonList, CTypedPtrList<CPtrList,CButtonData*>>()},
	}},
	{"CGameAbilityList", {
		{"CTypedPtrArray<CPtrArray,CAbilityData*>", offsetofbase<CGameAbilityList, CTypedPtrArray<CPtrArray,CAbilityData*>>()},
	}},
	{"CFile", {
		{"CObject", offsetofbase<CFile, CObject>()},
	}},
	{"CException", {
		{"CObject", offsetofbase<CException, CObject>()},
	}},
	{"CFileException", {
		{"CException", offsetofbase<CFileException, CException>()},
	}},
	{"CDWordArray", {
		{"CObject", offsetofbase<CDWordArray, CObject>()},
	}},
	{"CCriticalEntryList", {
		{"CTypedPtrList<CPtrList,CCriticalEntry*>", offsetofbase<CCriticalEntryList, CTypedPtrList<CPtrList,CCriticalEntry*>>()},
	}},
	{"CContingencyList", {
		{"CTypedPtrList<CPtrList,CContingency*>", offsetofbase<CContingencyList, CTypedPtrList<CPtrList,CContingency*>>()},
	}},
	{"CColorRanges", {
		{"CTypedPtrList<CPtrList,CColorRange*>", offsetofbase<CColorRanges, CTypedPtrList<CPtrList,CColorRange*>>()},
	}},
	{"CColorEffects", {
		{"CTypedPtrList<CPtrList,CColorEffect*>", offsetofbase<CColorEffects, CTypedPtrList<CPtrList,CColorEffect*>>()},
	}},
	{"CCallResult<CSteam,CreateItemResult_t>", {
		{"CCallbackBase", offsetofbase<CCallResult<CSteam,CreateItemResult_t>, CCallbackBase>()},
	}},
	{"CCallResult<CSteam,SteamUGCQueryCompleted_t>", {
		{"CCallbackBase", offsetofbase<CCallResult<CSteam,SteamUGCQueryCompleted_t>, CCallbackBase>()},
	}},
	{"CCallResult<CSteam,SubmitItemUpdateResult_t>", {
		{"CCallbackBase", offsetofbase<CCallResult<CSteam,SubmitItemUpdateResult_t>, CCallbackBase>()},
	}},
	{"CCallResult<CSteam,SteamUGCRequestUGCDetailsResult_t>", {
		{"CCallbackBase", offsetofbase<CCallResult<CSteam,SteamUGCRequestUGCDetailsResult_t>, CCallbackBase>()},
	}},
	{"CBounceList", {
		{"CTypedPtrList<CPtrList,CBounceEntry*>", offsetofbase<CBounceList, CTypedPtrList<CPtrList,CBounceEntry*>>()},
	}},
	{"EEex_CBaldurEngine", {
		{"EEex_CWarp", offsetofbase<CBaldurEngine, CWarp>()},
	}},
	{"CDungeonMaster", {
		{"EEex_CBaldurEngine", offsetofbase<CDungeonMaster, CBaldurEngine>()},
	}},
	{"CApplyEffectList", {
		{"CTypedPtrList<CPtrList,CGameEffect*>", offsetofbase<CApplyEffectList, CTypedPtrList<CPtrList,CGameEffect*>>()},
	}},
	{"CVidTile", {
		{"CVidImage", offsetofbase<CVidTile, CVidImage>()},
	}},
	{"EEex_CScreenMovies", {
		{"EEex_CBaldurEngine", offsetofbase<CScreenMovies, CBaldurEngine>()},
	}},
	{"EEex_CScreenConnection", {
		{"EEex_CBaldurEngine", offsetofbase<CScreenConnection, CBaldurEngine>()},
	}},
	{"CGameStatsRes", {
		{"CObject", offsetofbase<CGameStatsRes, CObject>()},
	}},
	{"EEex_CScreenWizSpell", {
		{"EEex_CBaldurEngine", offsetofbase<CScreenWizSpell, CBaldurEngine>()},
	}},
	{"EEex_CScreenPriestSpell", {
		{"EEex_CBaldurEngine", offsetofbase<CScreenPriestSpell, CBaldurEngine>()},
	}},
	{"EEex_CScreenCharacter", {
		{"EEex_CBaldurEngine", offsetofbase<CScreenCharacter, CBaldurEngine>()},
	}},
	{"C2DArray", {
		{"CResHelper<CResText,1012>", offsetofbase<C2DArray, CResHelper<CResText,1012>>()},
	}},
	{"CAIIdList", {
		{"CResHelper<CResText,1008>", offsetofbase<CAIIdList, CResHelper<CResText,1008>>()},
	}},
	{"CGameFile", {
		{"CResHelper<CResGame,1013>", offsetofbase<CGameFile, CResHelper<CResGame,1013>>()},
	}},
	{"CVidMosaic", {
		{"CVidImage", offsetofbase<CVidMosaic, CVidImage>()},
		{"CResHelper<CResMosaic,1004>", offsetofbase<CVidMosaic, CResHelper<CResMosaic,1004>>()},
	}},
	{"CVidFont", {
		{"CResHelper<CResFont,1034>", offsetofbase<CVidFont, CResHelper<CResFont,1034>>()},
	}},
	{"EEex_CScreenInventory", {
		{"EEex_CBaldurEngine", offsetofbase<CScreenInventory, CBaldurEngine>()},
	}},
	{"EEex_CScreenJournal", {
		{"EEex_CBaldurEngine", offsetofbase<CScreenJournal, CBaldurEngine>()},
	}},
	{"EEex_CScreenCreateChar", {
		{"EEex_CBaldurEngine", offsetofbase<CScreenCreateChar, CBaldurEngine>()},
	}},
	{"EEex_CScreenCreateParty", {
		{"EEex_CBaldurEngine", offsetofbase<CScreenCreateParty, CBaldurEngine>()},
	}},
	{"EEex_CScreenDLC", {
		{"EEex_CBaldurEngine", offsetofbase<CScreenDLC, CBaldurEngine>()},
	}},
	{"EEex_CScreenLoad", {
		{"EEex_CBaldurEngine", offsetofbase<CScreenLoad, CBaldurEngine>()},
	}},
	{"EEex_CScreenMap", {
		{"EEex_CBaldurEngine", offsetofbase<CScreenMap, CBaldurEngine>()},
	}},
	{"EEex_CScreenMultiPlayer", {
		{"EEex_CBaldurEngine", offsetofbase<CScreenMultiPlayer, CBaldurEngine>()},
	}},
	{"EEex_CScreenOptions", {
		{"EEex_CBaldurEngine", offsetofbase<CScreenOptions, CBaldurEngine>()},
	}},
	{"EEex_CScreenSave", {
		{"EEex_CBaldurEngine", offsetofbase<CScreenSave, CBaldurEngine>()},
	}},
	{"EEex_CScreenStart", {
		{"EEex_CBaldurEngine", offsetofbase<CScreenStart, CBaldurEngine>()},
	}},
	{"CVidCell", {
		{"CVidImage", offsetofbase<CVidCell, CVidImage>()},
		{"CResHelper<CResCell,1000>", offsetofbase<CVidCell, CResHelper<CResCell,1000>>()},
	}},
	{"EEex_CScreenWorldMap", {
		{"EEex_CBaldurEngine", offsetofbase<CScreenWorldMap, CBaldurEngine>()},
	}},
	{"CVidCellFont", {
		{"CVidCell", offsetofbase<CVidCellFont, CVidCell>()},
	}},
	{"CVidBitmap", {
		{"CVidImage", offsetofbase<CVidBitmap, CVidImage>()},
		{"CResHelper<CResBitmap,1>", offsetofbase<CVidBitmap, CResHelper<CResBitmap,1>>()},
	}},
	{"CScreenAI", {
		{"EEex_CBaldurEngine", offsetofbase<CScreenAI, CBaldurEngine>()},
	}},
	{"CSpell", {
		{"CResHelper<CResSpell,1006>", offsetofbase<CSpell, CResHelper<CResSpell,1006>>()},
	}},
	{"CSoundImp", {
		{"CObject", offsetofbase<CSoundImp, CObject>()},
		{"CResHelper<CResWave,4>", offsetofbase<CSoundImp, CResHelper<CResWave,4>>()},
	}},
	{"CSound", {
		{"CObject", offsetofbase<CSound, CObject>()},
		{"CResHelper<CResWave,4>", offsetofbase<CSound, CResHelper<CResWave,4>>()},
	}},
	{"EEex_CScreenChapter", {
		{"EEex_CBaldurEngine", offsetofbase<CScreenChapter, CBaldurEngine>()},
	}},
	{"EEex_CInfToolTip", {
		{"CVidCell", offsetofbase<CInfToolTip, CVidCell>()},
	}},
	{"EEex_CScreenWorld", {
		{"EEex_CBaldurEngine", offsetofbase<CScreenWorld, CBaldurEngine>()},
	}},
	{"CItem", {
		{"CResHelper<CResItem,1005>", offsetofbase<CItem, CResHelper<CResItem,1005>>()},
	}},
	{"CGameEffect", {
		{"CGameEffectBase", offsetofbase<CGameEffect, CGameEffectBase>()},
	}},
	{"CGameEffectUsability", {
		{"CGameEffect", offsetofbase<CGameEffectUsability, CGameEffect>()},
	}},
	{"CDerivedStats", {
		{"CDerivedStatsTemplate", offsetofbase<CDerivedStats, CDerivedStatsTemplate>()},
	}},
	{"EEex_CBaldurProjector", {
		{"EEex_CBaldurEngine", offsetofbase<CBaldurProjector, CBaldurEngine>()},
	}},
	{"CVariable", {
		{"CAreaVariable", offsetofbase<CVariable, CAreaVariable>()},
	}},
	{"EEex_CScreenStore", {
		{"EEex_CBaldurEngine", offsetofbase<CScreenStore, CBaldurEngine>()},
	}},
	{"CGameFireball3d", {
		{"CGameObject", offsetofbase<CGameFireball3d, CGameObject>()},
	}},
	{"CProjectile", {
		{"CGameObject", offsetofbase<CProjectile, CGameObject>()},
	}},
	{"CObjectMarker", {
		{"CGameObject", offsetofbase<CObjectMarker, CGameObject>()},
	}},
	{"CGameTemporal", {
		{"CGameObject", offsetofbase<CGameTemporal, CGameObject>()},
	}},
	{"CGameStatic", {
		{"CGameObject", offsetofbase<CGameStatic, CGameObject>()},
	}},
	{"CGameSpawning", {
		{"CGameObject", offsetofbase<CGameSpawning, CGameObject>()},
	}},
	{"CGameSound", {
		{"CGameObject", offsetofbase<CGameSound, CGameObject>()},
	}},
	{"CGameAIBase", {
		{"CGameObject", offsetofbase<CGameAIBase, CGameObject>()},
	}},
	{"CGameAIArea", {
		{"CGameAIBase", offsetofbase<CGameAIArea, CGameAIBase>()},
	}},
	{"CGameTrigger", {
		{"CGameAIBase", offsetofbase<CGameTrigger, CGameAIBase>()},
	}},
	{"CGameTiledObject", {
		{"CGameAIBase", offsetofbase<CGameTiledObject, CGameAIBase>()},
	}},
	{"CGameSprite", {
		{"CGameAIBase", offsetofbase<CGameSprite, CGameAIBase>()},
	}},
	{"CGameDoor", {
		{"CGameAIBase", offsetofbase<CGameDoor, CGameAIBase>()},
	}},
	{"CGameContainer", {
		{"CGameAIBase", offsetofbase<CGameContainer, CGameAIBase>()},
	}},
	{"CGameAIGame", {
		{"CGameAIBase", offsetofbase<CGameAIGame, CGameAIBase>()},
	}},
	{"EEex_CBaldurChitin", {
		{"EEex_CChitin", offsetofbase<CBaldurChitin, CChitin>()},
	}},
};
