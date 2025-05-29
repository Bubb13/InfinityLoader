
#include "Baldur-v2.6.6.0_generated.h"

template<typename Derived, typename Base>
constexpr uintptr_t offsetofbase() {
	return reinterpret_cast<uintptr_t>(static_cast<Base*>(reinterpret_cast<Derived*>(1))) - 1;
}

void registerBaseclasses() {
	RegisterBaseclassOffsets({
		{"CResWorldMap", {
			{"CRes", offsetofbase<CResWorldMap, CRes>()},
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
		{"CResUI", {
			{"CRes", offsetofbase<CResUI, CRes>()},
		}},
		{"CResTileSet", {
			{"CRes", offsetofbase<CResTileSet, CRes>()},
		}},
		{"CResText", {
			{"CRes", offsetofbase<CResText, CRes>()},
		}},
		{"CResStore", {
			{"CRes", offsetofbase<CResStore, CRes>()},
		}},
		{"CResSpell", {
			{"CRes", offsetofbase<CResSpell, CRes>()},
		}},
		{"CResPng", {
			{"CRes", offsetofbase<CResPng, CRes>()},
		}},
		{"CResPVR", {
			{"CRes", offsetofbase<CResPVR, CRes>()},
		}},
		{"CResPLT", {
			{"CRes", offsetofbase<CResPLT, CRes>()},
		}},
		{"CResMosaic", {
			{"CRes", offsetofbase<CResMosaic, CRes>()},
		}},
		{"CResItem", {
			{"CRes", offsetofbase<CResItem, CRes>()},
		}},
		{"CResINI", {
			{"CRes", offsetofbase<CResINI, CRes>()},
		}},
		{"CResGame", {
			{"CRes", offsetofbase<CResGame, CRes>()},
		}},
		{"CResFont", {
			{"CRes", offsetofbase<CResFont, CRes>()},
		}},
		{"CResEffect", {
			{"CRes", offsetofbase<CResEffect, CRes>()},
		}},
		{"CResDLG", {
			{"CRes", offsetofbase<CResDLG, CRes>()},
		}},
		{"CResCell", {
			{"CRes", offsetofbase<CResCell, CRes>()},
		}},
		{"CResCRE", {
			{"CRes", offsetofbase<CResCRE, CRes>()},
		}},
		{"CResCHR", {
			{"CRes", offsetofbase<CResCHR, CRes>()},
		}},
		{"CResBitmap", {
			{"CRes", offsetofbase<CResBitmap, CRes>()},
		}},
		{"CResBIO", {
			{"CRes", offsetofbase<CResBIO, CRes>()},
		}},
		{"CResArea", {
			{"CRes", offsetofbase<CResArea, CRes>()},
		}},
		{"CArray<CRect,CRect*>", {
			{"CObject", offsetofbase<CArray<CRect,CRect*>, CObject>()},
		}},
		{"CDWordArray", {
			{"CObject", offsetofbase<CDWordArray, CObject>()},
		}},
		{"CException", {
			{"CObject", offsetofbase<CException, CObject>()},
		}},
		{"CFileException", {
			{"CException", offsetofbase<CFileException, CException>()},
		}},
		{"CList<long,long>", {
			{"CObject", offsetofbase<CList<long,long>, CObject>()},
		}},
		{"CList<unsigned long,unsigned long*>", {
			{"CObject", offsetofbase<CList<unsigned long,unsigned long*>, CObject>()},
		}},
		{"CMapStringToString", {
			{"CObject", offsetofbase<CMapStringToString, CObject>()},
		}},
		{"CVoice", {
			{"CObject", offsetofbase<CVoice, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CAIId*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CAIId*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CAIAction*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CAIAction*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CAITrigger*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CAITrigger*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CGameTimer*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CGameTimer*>, CObject>()},
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
		{"CTypedPtrList<CPtrList,long>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,long>, CObject>()},
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
		{"CTypedPtrList<CPtrList,CVEFEvent*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CVEFEvent*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CAIObjectType*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CAIObjectType*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CAIConditionResponse*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CAIConditionResponse*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CMessage*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CMessage*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CDeathSound*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CDeathSound*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CItem*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CItem*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CContingency*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CContingency*>, CObject>()},
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
		{"CTypedPtrList<CPtrList,CGameEffectUsability*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CGameEffectUsability*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CStoreFileItem*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CStoreFileItem*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CMemINIValue*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CMemINIValue*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CAIResponse*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CAIResponse*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CSpawn*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CSpawn*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CGameEffect*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CGameEffect*>, CObject>()},
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
		{"CTypedPtrList<CPtrList,CString*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CString*>, CObject>()},
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
		{"CTypedPtrList<CPtrList,CParticle*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CParticle*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CVidCell*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CVidCell*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CProjectile*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CProjectile*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,EEex_CWarp*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CWarp*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CScreenStoreItem*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CScreenStoreItem*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CSound*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CSound*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CVoice*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CVoice*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CTimer*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CTimer*>, CObject>()},
		}},
		{"CTypedPtrArray<CPtrArray,CRes*>", {
			{"CObject", offsetofbase<CTypedPtrArray<CPtrArray,CRes*>, CObject>()},
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
		{"CTypedPtrArray<CPtrArray,long>", {
			{"CObject", offsetofbase<CTypedPtrArray<CPtrArray,long>, CObject>()},
		}},
		{"CTypedPtrArray<CPtrArray,__int8>", {
			{"CObject", offsetofbase<CTypedPtrArray<CPtrArray,__int8>, CObject>()},
		}},
		{"CTypedPtrArray<CPtrArray,CSoundChannel*>", {
			{"CObject", offsetofbase<CTypedPtrArray<CPtrArray,CSoundChannel*>, CObject>()},
		}},
		{"CTimer", {
			{"CObject", offsetofbase<CTimer, CObject>()},
		}},
		{"CStringList", {
			{"CObject", offsetofbase<CStringList, CObject>()},
		}},
		{"CPtrList", {
			{"CObject", offsetofbase<CPtrList, CObject>()},
		}},
		{"CImmunitiesProjectile", {
			{"CTypedPtrList<CPtrList,long>", offsetofbase<CImmunitiesProjectile, CTypedPtrList<CPtrList,long>>()},
		}},
		{"CImmunitiesSchoolAndSecondary", {
			{"CTypedPtrList<CPtrList,long>", offsetofbase<CImmunitiesSchoolAndSecondary, CTypedPtrList<CPtrList,long>>()},
		}},
		{"CGameButtonList", {
			{"CTypedPtrList<CPtrList,CButtonData*>", offsetofbase<CGameButtonList, CTypedPtrList<CPtrList,CButtonData*>>()},
		}},
		{"CImmunitiesAIType", {
			{"CTypedPtrList<CPtrList,CAIObjectType*>", offsetofbase<CImmunitiesAIType, CTypedPtrList<CPtrList,CAIObjectType*>>()},
		}},
		{"CPersistantEffectListRegenerated", {
			{"CTypedPtrList<CPtrList,CPersistantEffect*>", offsetofbase<CPersistantEffectListRegenerated, CTypedPtrList<CPtrList,CPersistantEffect*>>()},
		}},
		{"EEex_CWarp", {
			{"CObject", offsetofbase<CWarp, CObject>()},
		}},
		{"CApplyEffectList", {
			{"CTypedPtrList<CPtrList,CGameEffect*>", offsetofbase<CApplyEffectList, CTypedPtrList<CPtrList,CGameEffect*>>()},
		}},
		{"CBounceList", {
			{"CTypedPtrList<CPtrList,CBounceEntry*>", offsetofbase<CBounceList, CTypedPtrList<CPtrList,CBounceEntry*>>()},
		}},
		{"CColorEffects", {
			{"CTypedPtrList<CPtrList,CColorEffect*>", offsetofbase<CColorEffects, CTypedPtrList<CPtrList,CColorEffect*>>()},
		}},
		{"CColorRanges", {
			{"CTypedPtrList<CPtrList,CColorRange*>", offsetofbase<CColorRanges, CTypedPtrList<CPtrList,CColorRange*>>()},
		}},
		{"CCriticalEntryList", {
			{"CTypedPtrList<CPtrList,CCriticalEntry*>", offsetofbase<CCriticalEntryList, CTypedPtrList<CPtrList,CCriticalEntry*>>()},
		}},
		{"CGameEffectUsabilityList", {
			{"CTypedPtrList<CPtrList,CGameEffectUsability*>", offsetofbase<CGameEffectUsabilityList, CTypedPtrList<CPtrList,CGameEffectUsability*>>()},
		}},
		{"CImmunitiesEffect", {
			{"CTypedPtrList<CPtrList,CGameEffect*>", offsetofbase<CImmunitiesEffect, CTypedPtrList<CPtrList,CGameEffect*>>()},
		}},
		{"CImmunitiesItemEquipList", {
			{"CTypedPtrList<CPtrList,CImmunitiesItemEquip*>", offsetofbase<CImmunitiesItemEquipList, CTypedPtrList<CPtrList,CImmunitiesItemEquip*>>()},
		}},
		{"CImmunitiesItemTypeEquipList", {
			{"CTypedPtrList<CPtrList,CImmunitiesItemTypeEquip*>", offsetofbase<CImmunitiesItemTypeEquipList, CTypedPtrList<CPtrList,CImmunitiesItemTypeEquip*>>()},
		}},
		{"CImmunitiesSchoolAndSecondaryDecrementing", {
			{"CTypedPtrList<CPtrList,CSchoolAndSecondaryDecrementing*>", offsetofbase<CImmunitiesSchoolAndSecondaryDecrementing, CTypedPtrList<CPtrList,CSchoolAndSecondaryDecrementing*>>()},
		}},
		{"CImmunitiesSpellList", {
			{"CTypedPtrList<CPtrList,CImmunitySpell*>", offsetofbase<CImmunitiesSpellList, CTypedPtrList<CPtrList,CImmunitySpell*>>()},
		}},
		{"CImmunitiesWeapon", {
			{"CTypedPtrList<CPtrList,CWeaponIdentification*>", offsetofbase<CImmunitiesWeapon, CTypedPtrList<CPtrList,CWeaponIdentification*>>()},
		}},
		{"CMemINI", {
			{"CTypedPtrList<CPtrList,void*>", offsetofbase<CMemINI, CTypedPtrList<CPtrList,void*>>()},
		}},
		{"CMemINISection", {
			{"CTypedPtrList<CPtrList,CMemINIValue*>", offsetofbase<CMemINISection, CTypedPtrList<CPtrList,CMemINIValue*>>()},
		}},
		{"CMoveList", {
			{"CTypedPtrList<CPtrList,CMoveListEntry*>", offsetofbase<CMoveList, CTypedPtrList<CPtrList,CMoveListEntry*>>()},
		}},
		{"CPersistantEffectList", {
			{"CTypedPtrList<CPtrList,CPersistantEffect*>", offsetofbase<CPersistantEffectList, CTypedPtrList<CPtrList,CPersistantEffect*>>()},
		}},
		{"CSpawnList", {
			{"CTypedPtrList<CPtrList,CSpawn*>", offsetofbase<CSpawnList, CTypedPtrList<CPtrList,CSpawn*>>()},
		}},
		{"CSpawnFile", {
			{"CTypedPtrList<CPtrList,void*>", offsetofbase<CSpawnFile, CTypedPtrList<CPtrList,void*>>()},
		}},
		{"CSoundChannel", {
			{"CObject", offsetofbase<CSoundChannel, CObject>()},
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
		{"CGameDialogEntry", {
			{"CTypedPtrArray<CPtrArray,CGameDialogReply*>", offsetofbase<CGameDialogEntry, CTypedPtrArray<CPtrArray,CGameDialogReply*>>()},
		}},
		{"CGameAbilityList", {
			{"CTypedPtrArray<CPtrArray,CAbilityData*>", offsetofbase<CGameAbilityList, CTypedPtrArray<CPtrArray,CAbilityData*>>()},
		}},
		{"CSpawnPointArray", {
			{"CTypedPtrArray<CPtrArray,CSpawnPoint*>", offsetofbase<CSpawnPointArray, CTypedPtrArray<CPtrArray,CSpawnPoint*>>()},
		}},
		{"CObList", {
			{"CObject", offsetofbase<CObList, CObject>()},
		}},
		{"CMessageUpdateReaction", {
			{"CMessage", offsetofbase<CMessageUpdateReaction, CMessage>()},
		}},
		{"CMessageSetDirection", {
			{"CMessage", offsetofbase<CMessageSetDirection, CMessage>()},
		}},
		{"CMessageDisplayTextRef", {
			{"CMessage", offsetofbase<CMessageDisplayTextRef, CMessage>()},
		}},
		{"CMessageDisplayText", {
			{"CMessage", offsetofbase<CMessageDisplayText, CMessage>()},
		}},
		{"CMessageAddEffect", {
			{"CMessage", offsetofbase<CMessageAddEffect, CMessage>()},
		}},
		{"CMessageAddClairvoyance", {
			{"CMessage", offsetofbase<CMessageAddClairvoyance, CMessage>()},
		}},
		{"CGameEffectList", {
			{"CTypedPtrList<CPtrList,CGameEffect*>", offsetofbase<CGameEffectList, CTypedPtrList<CPtrList,CGameEffect*>>()},
		}},
		{"CFile", {
			{"CObject", offsetofbase<CFile, CObject>()},
		}},
		{"CContingencyList", {
			{"CTypedPtrList<CPtrList,CContingency*>", offsetofbase<CContingencyList, CTypedPtrList<CPtrList,CContingency*>>()},
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
		{"EEex_CBaldurEngine", {
			{"EEex_CWarp", offsetofbase<CBaldurEngine, CWarp>()},
		}},
		{"CDungeonMaster", {
			{"EEex_CBaldurEngine", offsetofbase<CDungeonMaster, CBaldurEngine>()},
		}},
		{"CResBinary", {
			{"CRes", offsetofbase<CResBinary, CRes>()},
		}},
		{"EEex_CScreenMovies", {
			{"EEex_CBaldurEngine", offsetofbase<CScreenMovies, CBaldurEngine>()},
		}},
		{"EEex_CScreenConnection", {
			{"EEex_CBaldurEngine", offsetofbase<CScreenConnection, CBaldurEngine>()},
		}},
		{"CAIIdList", {
			{"CResHelper<CResText,1008>", offsetofbase<CAIIdList, CResHelper<CResText,1008>>()},
		}},
		{"CSound", {
			{"CObject", offsetofbase<CSound, CObject>()},
			{"CResHelper<CResWave,4>", offsetofbase<CSound, CResHelper<CResWave,4>>()},
		}},
		{"CSoundImp", {
			{"CObject", offsetofbase<CSoundImp, CObject>()},
			{"CResHelper<CResWave,4>", offsetofbase<CSoundImp, CResHelper<CResWave,4>>()},
		}},
		{"CScreenAI", {
			{"EEex_CBaldurEngine", offsetofbase<CScreenAI, CBaldurEngine>()},
		}},
		{"CVidCell", {
			{"CVidImage", offsetofbase<CVidCell, CVidImage>()},
			{"CResHelper<CResCell,1000>", offsetofbase<CVidCell, CResHelper<CResCell,1000>>()},
		}},
		{"CVidCellFont", {
			{"CVidCell", offsetofbase<CVidCellFont, CVidCell>()},
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
		{"EEex_CInfToolTip", {
			{"CVidCell", offsetofbase<CInfToolTip, CVidCell>()},
		}},
		{"CGameStatsRes", {
			{"CObject", offsetofbase<CGameStatsRes, CObject>()},
		}},
		{"EEex_CScreenWorldMap", {
			{"EEex_CBaldurEngine", offsetofbase<CScreenWorldMap, CBaldurEngine>()},
		}},
		{"EEex_CScreenWorld", {
			{"EEex_CBaldurEngine", offsetofbase<CScreenWorld, CBaldurEngine>()},
		}},
		{"EEex_CScreenWizSpell", {
			{"EEex_CBaldurEngine", offsetofbase<CScreenWizSpell, CBaldurEngine>()},
		}},
		{"EEex_CScreenPriestSpell", {
			{"EEex_CBaldurEngine", offsetofbase<CScreenPriestSpell, CBaldurEngine>()},
		}},
		{"EEex_CScreenJournal", {
			{"EEex_CBaldurEngine", offsetofbase<CScreenJournal, CBaldurEngine>()},
		}},
		{"EEex_CScreenInventory", {
			{"EEex_CBaldurEngine", offsetofbase<CScreenInventory, CBaldurEngine>()},
		}},
		{"EEex_CScreenCharacter", {
			{"EEex_CBaldurEngine", offsetofbase<CScreenCharacter, CBaldurEngine>()},
		}},
		{"EEex_CScreenChapter", {
			{"EEex_CBaldurEngine", offsetofbase<CScreenChapter, CBaldurEngine>()},
		}},
		{"CItem", {
			{"CResHelper<CResItem,1005>", offsetofbase<CItem, CResHelper<CResItem,1005>>()},
		}},
		{"CGameEffect", {
			{"CGameEffectBase", offsetofbase<CGameEffect, CGameEffectBase>()},
		}},
		{"CGameEffectDamage", {
			{"CGameEffect", offsetofbase<CGameEffectDamage, CGameEffect>()},
		}},
		{"CGameEffectUsability", {
			{"CGameEffect", offsetofbase<CGameEffectUsability, CGameEffect>()},
		}},
		{"EEex_CBaldurProjector", {
			{"EEex_CBaldurEngine", offsetofbase<CBaldurProjector, CBaldurEngine>()},
		}},
		{"EEex_CBaldurChitin", {
			{"EEex_CChitin", offsetofbase<CBaldurChitin, CChitin>()},
		}},
		{"EEex_CScreenStore", {
			{"EEex_CBaldurEngine", offsetofbase<CScreenStore, CBaldurEngine>()},
		}},
		{"CMessageSetLastObject", {
			{"CMessage", offsetofbase<CMessageSetLastObject, CMessage>()},
		}},
		{"CGameFireball3d", {
			{"CGameObject", offsetofbase<CGameFireball3d, CGameObject>()},
		}},
		{"CVisualEffect", {
			{"CGameObject", offsetofbase<CVisualEffect, CGameObject>()},
			{"CVisualEffectBase", offsetofbase<CVisualEffect, CVisualEffectBase>()},
		}},
		{"CProjectile", {
			{"CGameObject", offsetofbase<CProjectile, CGameObject>()},
		}},
		{"CProjectileTravelDoor", {
			{"CProjectile", offsetofbase<CProjectileTravelDoor, CProjectile>()},
		}},
		{"CProjectileSpellHit", {
			{"CProjectile", offsetofbase<CProjectileSpellHit, CProjectile>()},
		}},
		{"CProjectileAmbiant", {
			{"CProjectileSpellHit", offsetofbase<CProjectileAmbiant, CProjectileSpellHit>()},
		}},
		{"CProjectileSkyStrike", {
			{"CProjectile", offsetofbase<CProjectileSkyStrike, CProjectile>()},
		}},
		{"CProjectileInstant", {
			{"CProjectile", offsetofbase<CProjectileInstant, CProjectile>()},
		}},
		{"CProjectileCallLightning", {
			{"CProjectileInstant", offsetofbase<CProjectileCallLightning, CProjectileInstant>()},
		}},
		{"CProjectileCastingGlow", {
			{"CProjectile", offsetofbase<CProjectileCastingGlow, CProjectile>()},
		}},
		{"CProjectileBAM", {
			{"CProjectile", offsetofbase<CProjectileBAM, CProjectile>()},
		}},
		{"CProjectileArea", {
			{"CProjectileBAM", offsetofbase<CProjectileArea, CProjectileBAM>()},
		}},
		{"CProjectileSkyStrikeBAM", {
			{"CProjectileBAM", offsetofbase<CProjectileSkyStrikeBAM, CProjectileBAM>()},
		}},
		{"CProjectileSegment", {
			{"CProjectileBAM", offsetofbase<CProjectileSegment, CProjectileBAM>()},
		}},
		{"CProjectileScorcher", {
			{"CProjectileBAM", offsetofbase<CProjectileScorcher, CProjectileBAM>()},
		}},
		{"CProjectileNewScorcher", {
			{"CProjectileBAM", offsetofbase<CProjectileNewScorcher, CProjectileBAM>()},
		}},
		{"CProjectileMushroom", {
			{"CProjectileBAM", offsetofbase<CProjectileMushroom, CProjectileBAM>()},
		}},
		{"CProjectileMulti", {
			{"CProjectileBAM", offsetofbase<CProjectileMulti, CProjectileBAM>()},
		}},
		{"CProjectileMagicMissileMulti", {
			{"CProjectileMulti", offsetofbase<CProjectileMagicMissileMulti, CProjectileMulti>()},
		}},
		{"CProjectileLightningBounce", {
			{"CProjectileBAM", offsetofbase<CProjectileLightningBounce, CProjectileBAM>()},
		}},
		{"CProjectileLightningBoltGround", {
			{"CProjectileBAM", offsetofbase<CProjectileLightningBoltGround, CProjectileBAM>()},
		}},
		{"CProjectileLightningBolt", {
			{"CProjectileBAM", offsetofbase<CProjectileLightningBolt, CProjectileBAM>()},
		}},
		{"CProjectileInvisibleTravelling", {
			{"CProjectileBAM", offsetofbase<CProjectileInvisibleTravelling, CProjectileBAM>()},
		}},
		{"CProjectileFireHands", {
			{"CProjectileBAM", offsetofbase<CProjectileFireHands, CProjectileBAM>()},
		}},
		{"CProjectileFall", {
			{"CProjectileBAM", offsetofbase<CProjectileFall, CProjectileBAM>()},
		}},
		{"CProjectileConeOfCold", {
			{"CProjectileBAM", offsetofbase<CProjectileConeOfCold, CProjectileBAM>()},
		}},
		{"CProjectileColorSpray", {
			{"CProjectileBAM", offsetofbase<CProjectileColorSpray, CProjectileBAM>()},
		}},
		{"CProjectileChain", {
			{"CProjectileBAM", offsetofbase<CProjectileChain, CProjectileBAM>()},
		}},
		{"CProjectileLightningStorm", {
			{"CProjectileChain", offsetofbase<CProjectileLightningStorm, CProjectileChain>()},
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
		{"CMessageSetTrigger", {
			{"CMessage", offsetofbase<CMessageSetTrigger, CMessage>()},
		}},
		{"CGameAIBase", {
			{"CGameObject", offsetofbase<CGameAIBase, CGameObject>()},
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
		{"CGameAIArea", {
			{"CGameAIBase", offsetofbase<CGameAIArea, CGameAIBase>()},
		}},
	});
}

