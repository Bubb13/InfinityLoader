
#include "Baldur-v2.6.6.0_generated.h"

template<typename Derived, typename Base>
constexpr uintptr_t offsetofbase() {
	return reinterpret_cast<uintptr_t>(static_cast<Base*>(reinterpret_cast<Derived*>(1))) - 1;
}

void registerBaseclasses() {
	RegisterBaseclassOffsets({
		{"CResInfTile", {
			{"CResTile", offsetofbase<CResInfTile, CResTile>()},
		}},
		{"CSnowFlake", {
			{"CParticle", offsetofbase<CSnowFlake, CParticle>()},
		}},
		{"CRainDrop", {
			{"CParticle", offsetofbase<CRainDrop, CParticle>()},
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
		{"CResWorldMap", {
			{"CRes", offsetofbase<CResWorldMap, CRes>()},
		}},
		{"CResWorldMap::vtbl", {
			{"CRes::vtbl", offsetofbase<CResWorldMap::vtbl, CRes::vtbl>()},
		}},
		{"CResWebm", {
			{"CRes", offsetofbase<CResWebm, CRes>()},
		}},
		{"CResWebm::vtbl", {
			{"CRes::vtbl", offsetofbase<CResWebm::vtbl, CRes::vtbl>()},
		}},
		{"CResWave", {
			{"CRes", offsetofbase<CResWave, CRes>()},
		}},
		{"CResWave::vtbl", {
			{"CRes::vtbl", offsetofbase<CResWave::vtbl, CRes::vtbl>()},
		}},
		{"CResWED", {
			{"CRes", offsetofbase<CResWED, CRes>()},
		}},
		{"CResWED::vtbl", {
			{"CRes::vtbl", offsetofbase<CResWED::vtbl, CRes::vtbl>()},
		}},
		{"CResUI", {
			{"CRes", offsetofbase<CResUI, CRes>()},
		}},
		{"CResUI::vtbl", {
			{"CRes::vtbl", offsetofbase<CResUI::vtbl, CRes::vtbl>()},
		}},
		{"CResTileSet", {
			{"CRes", offsetofbase<CResTileSet, CRes>()},
		}},
		{"CResTileSet::vtbl", {
			{"CRes::vtbl", offsetofbase<CResTileSet::vtbl, CRes::vtbl>()},
		}},
		{"CResText", {
			{"CRes", offsetofbase<CResText, CRes>()},
		}},
		{"CResText::vtbl", {
			{"CRes::vtbl", offsetofbase<CResText::vtbl, CRes::vtbl>()},
		}},
		{"CResStore", {
			{"CRes", offsetofbase<CResStore, CRes>()},
		}},
		{"CResStore::vtbl", {
			{"CRes::vtbl", offsetofbase<CResStore::vtbl, CRes::vtbl>()},
		}},
		{"CResSpell", {
			{"CRes", offsetofbase<CResSpell, CRes>()},
		}},
		{"CResSpell::vtbl", {
			{"CRes::vtbl", offsetofbase<CResSpell::vtbl, CRes::vtbl>()},
		}},
		{"CResPng", {
			{"CRes", offsetofbase<CResPng, CRes>()},
		}},
		{"CResPng::vtbl", {
			{"CRes::vtbl", offsetofbase<CResPng::vtbl, CRes::vtbl>()},
		}},
		{"CResPVR", {
			{"CRes", offsetofbase<CResPVR, CRes>()},
		}},
		{"CResPVR::vtbl", {
			{"CRes::vtbl", offsetofbase<CResPVR::vtbl, CRes::vtbl>()},
		}},
		{"CResPLT", {
			{"CRes", offsetofbase<CResPLT, CRes>()},
		}},
		{"CResPLT::vtbl", {
			{"CRes::vtbl", offsetofbase<CResPLT::vtbl, CRes::vtbl>()},
		}},
		{"CResMosaic", {
			{"CRes", offsetofbase<CResMosaic, CRes>()},
		}},
		{"CResMosaic::vtbl", {
			{"CRes::vtbl", offsetofbase<CResMosaic::vtbl, CRes::vtbl>()},
		}},
		{"CResItem", {
			{"CRes", offsetofbase<CResItem, CRes>()},
		}},
		{"CResItem::vtbl", {
			{"CRes::vtbl", offsetofbase<CResItem::vtbl, CRes::vtbl>()},
		}},
		{"CResINI", {
			{"CRes", offsetofbase<CResINI, CRes>()},
		}},
		{"CResINI::vtbl", {
			{"CRes::vtbl", offsetofbase<CResINI::vtbl, CRes::vtbl>()},
		}},
		{"CResGame", {
			{"CRes", offsetofbase<CResGame, CRes>()},
		}},
		{"CResGame::vtbl", {
			{"CRes::vtbl", offsetofbase<CResGame::vtbl, CRes::vtbl>()},
		}},
		{"CResFont", {
			{"CRes", offsetofbase<CResFont, CRes>()},
		}},
		{"CResFont::vtbl", {
			{"CRes::vtbl", offsetofbase<CResFont::vtbl, CRes::vtbl>()},
		}},
		{"CResEffect", {
			{"CRes", offsetofbase<CResEffect, CRes>()},
		}},
		{"CResEffect::vtbl", {
			{"CRes::vtbl", offsetofbase<CResEffect::vtbl, CRes::vtbl>()},
		}},
		{"CResDLG", {
			{"CRes", offsetofbase<CResDLG, CRes>()},
		}},
		{"CResDLG::vtbl", {
			{"CRes::vtbl", offsetofbase<CResDLG::vtbl, CRes::vtbl>()},
		}},
		{"CResCell", {
			{"CRes", offsetofbase<CResCell, CRes>()},
		}},
		{"CResCell::vtbl", {
			{"CRes::vtbl", offsetofbase<CResCell::vtbl, CRes::vtbl>()},
		}},
		{"CResCRE", {
			{"CRes", offsetofbase<CResCRE, CRes>()},
		}},
		{"CResCRE::vtbl", {
			{"CRes::vtbl", offsetofbase<CResCRE::vtbl, CRes::vtbl>()},
		}},
		{"CResCHR", {
			{"CRes", offsetofbase<CResCHR, CRes>()},
		}},
		{"CResCHR::vtbl", {
			{"CRes::vtbl", offsetofbase<CResCHR::vtbl, CRes::vtbl>()},
		}},
		{"CResBitmap", {
			{"CRes", offsetofbase<CResBitmap, CRes>()},
		}},
		{"CResBitmap::vtbl", {
			{"CRes::vtbl", offsetofbase<CResBitmap::vtbl, CRes::vtbl>()},
		}},
		{"CResBIO", {
			{"CRes", offsetofbase<CResBIO, CRes>()},
		}},
		{"CResBIO::vtbl", {
			{"CRes::vtbl", offsetofbase<CResBIO::vtbl, CRes::vtbl>()},
		}},
		{"CResArea", {
			{"CRes", offsetofbase<CResArea, CRes>()},
		}},
		{"CResArea::vtbl", {
			{"CRes::vtbl", offsetofbase<CResArea::vtbl, CRes::vtbl>()},
		}},
		{"CArray<CRect,CRect*>", {
			{"CObject", offsetofbase<CArray<CRect,CRect*>, CObject>()},
		}},
		{"CDWordArray", {
			{"CObject", offsetofbase<CDWordArray, CObject>()},
		}},
		{"CDWordArray::vtbl", {
			{"CObject::vtbl", offsetofbase<CDWordArray::vtbl, CObject::vtbl>()},
		}},
		{"CException", {
			{"CObject", offsetofbase<CException, CObject>()},
		}},
		{"CException::vtbl", {
			{"CObject::vtbl", offsetofbase<CException::vtbl, CObject::vtbl>()},
		}},
		{"CFileException", {
			{"CException", offsetofbase<CFileException, CException>()},
		}},
		{"CFileException::vtbl", {
			{"CException::vtbl", offsetofbase<CFileException::vtbl, CException::vtbl>()},
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
		{"CMapStringToString::vtbl", {
			{"CObject::vtbl", offsetofbase<CMapStringToString::vtbl, CObject::vtbl>()},
		}},
		{"CObArray", {
			{"CObject", offsetofbase<CObArray, CObject>()},
		}},
		{"CObArray::vtbl", {
			{"CObject::vtbl", offsetofbase<CObArray::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrList<CPtrList,CAIId*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CAIId*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CAIId*>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrList<CPtrList,CAIId*>::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrList<CPtrList,CAIAction*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CAIAction*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CAIAction*>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrList<CPtrList,CAIAction*>::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrList<CPtrList,CAITrigger*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CAITrigger*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CAITrigger*>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrList<CPtrList,CAITrigger*>::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrList<CPtrList,CGameTimer*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CGameTimer*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CGameTimer*>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrList<CPtrList,CGameTimer*>::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrList<CPtrList,CCreatureFileKnownSpell*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CCreatureFileKnownSpell*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CCreatureFileKnownSpell*>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrList<CPtrList,CCreatureFileKnownSpell*>::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrList<CPtrList,CCreatureFileMemorizedSpell*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CCreatureFileMemorizedSpell*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CCreatureFileMemorizedSpell*>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrList<CPtrList,CCreatureFileMemorizedSpell*>::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrList<CPtrList,long*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,long*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,long*>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrList<CPtrList,long*>::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrList<CPtrList,CBlood*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CBlood*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CBlood*>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrList<CPtrList,CBlood*>::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrList<CPtrList,CPortraitIcon*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CPortraitIcon*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CPortraitIcon*>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrList<CPtrList,CPortraitIcon*>::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrList<CPtrList,CPoint*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CPoint*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CPoint*>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrList<CPtrList,CPoint*>::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrList<CPtrList,CFeedbackEntry*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CFeedbackEntry*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CFeedbackEntry*>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrList<CPtrList,CFeedbackEntry*>::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrList<CPtrList,CGameSprite::GroundItem*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CGameSprite::GroundItem*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CGameSprite::GroundItem*>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrList<CPtrList,CGameSprite::GroundItem*>::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrList<CPtrList,CResRef*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CResRef*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CResRef*>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrList<CPtrList,CResRef*>::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrList<CPtrList,CSearchRequest*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CSearchRequest*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CSearchRequest*>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrList<CPtrList,CSearchRequest*>::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrList<CPtrList,SAreaFileWrapper*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,SAreaFileWrapper*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,SAreaFileWrapper*>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrList<CPtrList,SAreaFileWrapper*>::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrList<CPtrList,CSavedGameStoredLocation*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CSavedGameStoredLocation*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CSavedGameStoredLocation*>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrList<CPtrList,CSavedGameStoredLocation*>::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrList<CPtrList,long>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,long>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,long>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrList<CPtrList,long>::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrList<CPtrList,CAreaFileCharacterEntryPoint*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CAreaFileCharacterEntryPoint*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CAreaFileCharacterEntryPoint*>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrList<CPtrList,CAreaFileCharacterEntryPoint*>::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrList<CPtrList,__POSITION*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,__POSITION*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,__POSITION*>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrList<CPtrList,__POSITION*>::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrList<CPtrList,CTiledObject*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CTiledObject*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CTiledObject*>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrList<CPtrList,CTiledObject*>::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrList<CPtrList,CGameAreaClairvoyanceEntry*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CGameAreaClairvoyanceEntry*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CGameAreaClairvoyanceEntry*>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrList<CPtrList,CGameAreaClairvoyanceEntry*>::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrList<CPtrList,CAIObjectType*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CAIObjectType*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CAIObjectType*>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrList<CPtrList,CAIObjectType*>::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrList<CPtrList,CAIConditionResponse*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CAIConditionResponse*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CAIConditionResponse*>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrList<CPtrList,CAIConditionResponse*>::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrList<CPtrList,CMessage*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CMessage*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CMessage*>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrList<CPtrList,CMessage*>::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrList<CPtrList,CDeathSound*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CDeathSound*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CDeathSound*>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrList<CPtrList,CDeathSound*>::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrList<CPtrList,CItem*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CItem*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CItem*>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrList<CPtrList,CItem*>::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrList<CPtrList,CContingency*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CContingency*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CContingency*>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrList<CPtrList,CContingency*>::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrList<CPtrList,cnetworkwindow_queueentry_st*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,cnetworkwindow_queueentry_st*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,cnetworkwindow_queueentry_st*>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrList<CPtrList,cnetworkwindow_queueentry_st*>::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrList<CPtrList,CMusicPosition*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CMusicPosition*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CMusicPosition*>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrList<CPtrList,CMusicPosition*>::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrList<CPtrList,CGameJournalEntry*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CGameJournalEntry*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CGameJournalEntry*>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrList<CPtrList,CGameJournalEntry*>::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrList<CPtrList,CMoveListEntry*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CMoveListEntry*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CMoveListEntry*>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrList<CPtrList,CMoveListEntry*>::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrList<CPtrList,CAreaUserNote*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CAreaUserNote*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CAreaUserNote*>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrList<CPtrList,CAreaUserNote*>::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrList<CPtrList,CAOEEntry*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CAOEEntry*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CAOEEntry*>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrList<CPtrList,CAOEEntry*>::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrList<CPtrList,void*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,void*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,void*>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrList<CPtrList,void*>::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrList<CPtrList,CGameEffectUsability*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CGameEffectUsability*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CGameEffectUsability*>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrList<CPtrList,CGameEffectUsability*>::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrList<CPtrList,CStoreFileItem*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CStoreFileItem*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CStoreFileItem*>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrList<CPtrList,CStoreFileItem*>::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrList<CPtrList,CMemINIValue*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CMemINIValue*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CMemINIValue*>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrList<CPtrList,CMemINIValue*>::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrList<CPtrList,CAIResponse*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CAIResponse*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CAIResponse*>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrList<CPtrList,CAIResponse*>::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrList<CPtrList,CSpawn*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CSpawn*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CSpawn*>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrList<CPtrList,CSpawn*>::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrList<CPtrList,CGameEffect*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CGameEffect*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CGameEffect*>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrList<CPtrList,CGameEffect*>::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrList<CPtrList,CWeaponIdentification*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CWeaponIdentification*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CWeaponIdentification*>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrList<CPtrList,CWeaponIdentification*>::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrList<CPtrList,CSelectiveBonus*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CSelectiveBonus*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CSelectiveBonus*>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrList<CPtrList,CSelectiveBonus*>::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrList<CPtrList,CImmunitiesItemEquip*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CImmunitiesItemEquip*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CImmunitiesItemEquip*>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrList<CPtrList,CImmunitiesItemEquip*>::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrList<CPtrList,CImmunitiesItemTypeEquip*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CImmunitiesItemTypeEquip*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CImmunitiesItemTypeEquip*>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrList<CPtrList,CImmunitiesItemTypeEquip*>::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrList<CPtrList,CImmunitySpell*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CImmunitySpell*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CImmunitySpell*>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrList<CPtrList,CImmunitySpell*>::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrList<CPtrList,CSchoolAndSecondaryDecrementing*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CSchoolAndSecondaryDecrementing*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CSchoolAndSecondaryDecrementing*>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrList<CPtrList,CSchoolAndSecondaryDecrementing*>::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrList<CPtrList,CPersistantEffect*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CPersistantEffect*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CPersistantEffect*>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrList<CPtrList,CPersistantEffect*>::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrList<CPtrList,CColorRange*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CColorRange*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CColorRange*>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrList<CPtrList,CColorRange*>::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrList<CPtrList,CColorEffect*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CColorEffect*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CColorEffect*>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrList<CPtrList,CColorEffect*>::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrList<CPtrList,CSelectiveWeaponType*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CSelectiveWeaponType*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CSelectiveWeaponType*>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrList<CPtrList,CSelectiveWeaponType*>::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrList<CPtrList,CCriticalEntry*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CCriticalEntry*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CCriticalEntry*>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrList<CPtrList,CCriticalEntry*>::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrList<CPtrList,EEex_CGameOptions*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CGameOptions*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CGameOptions*>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrList<CPtrList,CGameOptions*>::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrList<CPtrList,CString*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CString*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CString*>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrList<CPtrList,CString*>::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrList<CPtrList,CBounceEntry*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CBounceEntry*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CBounceEntry*>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrList<CPtrList,CBounceEntry*>::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrList<CPtrList,CSequenceSound*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CSequenceSound*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CSequenceSound*>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrList<CPtrList,CSequenceSound*>::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrList<CPtrList,CButtonData*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CButtonData*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CButtonData*>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrList<CPtrList,CButtonData*>::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrList<CPtrList,CParticle*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CParticle*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CParticle*>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrList<CPtrList,CParticle*>::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrList<CPtrList,CVidCell*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CVidCell*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CVidCell*>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrList<CPtrList,CVidCell*>::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrList<CPtrList,CProjectile*>", {
			{"CObject", offsetofbase<CTypedPtrList<CPtrList,CProjectile*>, CObject>()},
		}},
		{"CTypedPtrList<CPtrList,CProjectile*>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrList<CPtrList,CProjectile*>::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrArray<CPtrArray,CRes*>", {
			{"CObject", offsetofbase<CTypedPtrArray<CPtrArray,CRes*>, CObject>()},
		}},
		{"CTypedPtrArray<CPtrArray,CRes*>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrArray<CPtrArray,CRes*>::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrArray<CPtrArray,long*>", {
			{"CObject", offsetofbase<CTypedPtrArray<CPtrArray,long*>, CObject>()},
		}},
		{"CTypedPtrArray<CPtrArray,long*>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrArray<CPtrArray,long*>::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrArray<CPtrArray,CTypedPtrList<CPtrList,CGameJournalEntry*>*>", {
			{"CObject", offsetofbase<CTypedPtrArray<CPtrArray,CTypedPtrList<CPtrList,CGameJournalEntry*>*>, CObject>()},
		}},
		{"CTypedPtrArray<CPtrArray,CTypedPtrList<CPtrList,CGameJournalEntry*>*>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrArray<CPtrArray,CTypedPtrList<CPtrList,CGameJournalEntry*>*>::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrArray<CPtrArray,CSavedGamePartyCreature*>", {
			{"CObject", offsetofbase<CTypedPtrArray<CPtrArray,CSavedGamePartyCreature*>, CObject>()},
		}},
		{"CTypedPtrArray<CPtrArray,CSavedGamePartyCreature*>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrArray<CPtrArray,CSavedGamePartyCreature*>::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrArray<CPtrArray,unsigned char*>", {
			{"CObject", offsetofbase<CTypedPtrArray<CPtrArray,unsigned char*>, CObject>()},
		}},
		{"CTypedPtrArray<CPtrArray,unsigned char*>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrArray<CPtrArray,unsigned char*>::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrArray<CPtrArray,CAbilityData*>", {
			{"CObject", offsetofbase<CTypedPtrArray<CPtrArray,CAbilityData*>, CObject>()},
		}},
		{"CTypedPtrArray<CPtrArray,CAbilityData*>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrArray<CPtrArray,CAbilityData*>::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrArray<CPtrArray,CSaveGameSlot*>", {
			{"CObject", offsetofbase<CTypedPtrArray<CPtrArray,CSaveGameSlot*>, CObject>()},
		}},
		{"CTypedPtrArray<CPtrArray,CSaveGameSlot*>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrArray<CPtrArray,CSaveGameSlot*>::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrArray<CPtrArray,CGameDialogEntry*>", {
			{"CObject", offsetofbase<CTypedPtrArray<CPtrArray,CGameDialogEntry*>, CObject>()},
		}},
		{"CTypedPtrArray<CPtrArray,CGameDialogEntry*>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrArray<CPtrArray,CGameDialogEntry*>::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrArray<CPtrArray,CSpawnPoint*>", {
			{"CObject", offsetofbase<CTypedPtrArray<CPtrArray,CSpawnPoint*>, CObject>()},
		}},
		{"CTypedPtrArray<CPtrArray,CSpawnPoint*>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrArray<CPtrArray,CSpawnPoint*>::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrArray<CPtrArray,CGameDialogReply*>", {
			{"CObject", offsetofbase<CTypedPtrArray<CPtrArray,CGameDialogReply*>, CObject>()},
		}},
		{"CTypedPtrArray<CPtrArray,CGameDialogReply*>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrArray<CPtrArray,CGameDialogReply*>::vtbl, CObject::vtbl>()},
		}},
		{"CTypedPtrArray<CPtrArray,__int8>", {
			{"CObject", offsetofbase<CTypedPtrArray<CPtrArray,__int8>, CObject>()},
		}},
		{"CTypedPtrArray<CPtrArray,__int8>::vtbl", {
			{"CObject::vtbl", offsetofbase<CTypedPtrArray<CPtrArray,__int8>::vtbl, CObject::vtbl>()},
		}},
		{"CStringList", {
			{"CObject", offsetofbase<CStringList, CObject>()},
		}},
		{"CStringList::vtbl", {
			{"CObject::vtbl", offsetofbase<CStringList::vtbl, CObject::vtbl>()},
		}},
		{"CPtrList", {
			{"CObject", offsetofbase<CPtrList, CObject>()},
		}},
		{"CPtrList::vtbl", {
			{"CObject::vtbl", offsetofbase<CPtrList::vtbl, CObject::vtbl>()},
		}},
		{"CGameButtonList", {
			{"CTypedPtrList<CPtrList,CButtonData*>", offsetofbase<CGameButtonList, CTypedPtrList<CPtrList,CButtonData*>>()},
		}},
		{"CGameButtonList::vtbl", {
			{"CTypedPtrList<CPtrList,CButtonData*>::vtbl", offsetofbase<CGameButtonList::vtbl, CTypedPtrList<CPtrList,CButtonData*>::vtbl>()},
		}},
		{"CGameEffectList", {
			{"CTypedPtrList<CPtrList,CGameEffect*>", offsetofbase<CGameEffectList, CTypedPtrList<CPtrList,CGameEffect*>>()},
		}},
		{"CGameEffectList::vtbl", {
			{"CTypedPtrList<CPtrList,CGameEffect*>::vtbl", offsetofbase<CGameEffectList::vtbl, CTypedPtrList<CPtrList,CGameEffect*>::vtbl>()},
		}},
		{"CImmunitiesAIType", {
			{"CTypedPtrList<CPtrList,CAIObjectType*>", offsetofbase<CImmunitiesAIType, CTypedPtrList<CPtrList,CAIObjectType*>>()},
		}},
		{"CImmunitiesAIType::vtbl", {
			{"CTypedPtrList<CPtrList,CAIObjectType*>::vtbl", offsetofbase<CImmunitiesAIType::vtbl, CTypedPtrList<CPtrList,CAIObjectType*>::vtbl>()},
		}},
		{"CPersistantEffectListRegenerated", {
			{"CTypedPtrList<CPtrList,CPersistantEffect*>", offsetofbase<CPersistantEffectListRegenerated, CTypedPtrList<CPtrList,CPersistantEffect*>>()},
		}},
		{"CPersistantEffectListRegenerated::vtbl", {
			{"CTypedPtrList<CPtrList,CPersistantEffect*>::vtbl", offsetofbase<CPersistantEffectListRegenerated::vtbl, CTypedPtrList<CPtrList,CPersistantEffect*>::vtbl>()},
		}},
		{"CApplyEffectList", {
			{"CTypedPtrList<CPtrList,CGameEffect*>", offsetofbase<CApplyEffectList, CTypedPtrList<CPtrList,CGameEffect*>>()},
		}},
		{"CApplyEffectList::vtbl", {
			{"CTypedPtrList<CPtrList,CGameEffect*>::vtbl", offsetofbase<CApplyEffectList::vtbl, CTypedPtrList<CPtrList,CGameEffect*>::vtbl>()},
		}},
		{"CBounceList", {
			{"CTypedPtrList<CPtrList,CBounceEntry*>", offsetofbase<CBounceList, CTypedPtrList<CPtrList,CBounceEntry*>>()},
		}},
		{"CBounceList::vtbl", {
			{"CTypedPtrList<CPtrList,CBounceEntry*>::vtbl", offsetofbase<CBounceList::vtbl, CTypedPtrList<CPtrList,CBounceEntry*>::vtbl>()},
		}},
		{"CColorEffects", {
			{"CTypedPtrList<CPtrList,CColorEffect*>", offsetofbase<CColorEffects, CTypedPtrList<CPtrList,CColorEffect*>>()},
		}},
		{"CColorEffects::vtbl", {
			{"CTypedPtrList<CPtrList,CColorEffect*>::vtbl", offsetofbase<CColorEffects::vtbl, CTypedPtrList<CPtrList,CColorEffect*>::vtbl>()},
		}},
		{"CColorRanges", {
			{"CTypedPtrList<CPtrList,CColorRange*>", offsetofbase<CColorRanges, CTypedPtrList<CPtrList,CColorRange*>>()},
		}},
		{"CColorRanges::vtbl", {
			{"CTypedPtrList<CPtrList,CColorRange*>::vtbl", offsetofbase<CColorRanges::vtbl, CTypedPtrList<CPtrList,CColorRange*>::vtbl>()},
		}},
		{"CCriticalEntryList", {
			{"CTypedPtrList<CPtrList,CCriticalEntry*>", offsetofbase<CCriticalEntryList, CTypedPtrList<CPtrList,CCriticalEntry*>>()},
		}},
		{"CCriticalEntryList::vtbl", {
			{"CTypedPtrList<CPtrList,CCriticalEntry*>::vtbl", offsetofbase<CCriticalEntryList::vtbl, CTypedPtrList<CPtrList,CCriticalEntry*>::vtbl>()},
		}},
		{"CGameEffectUsabilityList", {
			{"CTypedPtrList<CPtrList,CGameEffectUsability*>", offsetofbase<CGameEffectUsabilityList, CTypedPtrList<CPtrList,CGameEffectUsability*>>()},
		}},
		{"CGameEffectUsabilityList::vtbl", {
			{"CTypedPtrList<CPtrList,CGameEffectUsability*>::vtbl", offsetofbase<CGameEffectUsabilityList::vtbl, CTypedPtrList<CPtrList,CGameEffectUsability*>::vtbl>()},
		}},
		{"CImmunitiesEffect", {
			{"CTypedPtrList<CPtrList,CGameEffect*>", offsetofbase<CImmunitiesEffect, CTypedPtrList<CPtrList,CGameEffect*>>()},
		}},
		{"CImmunitiesEffect::vtbl", {
			{"CTypedPtrList<CPtrList,CGameEffect*>::vtbl", offsetofbase<CImmunitiesEffect::vtbl, CTypedPtrList<CPtrList,CGameEffect*>::vtbl>()},
		}},
		{"CImmunitiesItemEquipList", {
			{"CTypedPtrList<CPtrList,CImmunitiesItemEquip*>", offsetofbase<CImmunitiesItemEquipList, CTypedPtrList<CPtrList,CImmunitiesItemEquip*>>()},
		}},
		{"CImmunitiesItemEquipList::vtbl", {
			{"CTypedPtrList<CPtrList,CImmunitiesItemEquip*>::vtbl", offsetofbase<CImmunitiesItemEquipList::vtbl, CTypedPtrList<CPtrList,CImmunitiesItemEquip*>::vtbl>()},
		}},
		{"CImmunitiesItemTypeEquipList", {
			{"CTypedPtrList<CPtrList,CImmunitiesItemTypeEquip*>", offsetofbase<CImmunitiesItemTypeEquipList, CTypedPtrList<CPtrList,CImmunitiesItemTypeEquip*>>()},
		}},
		{"CImmunitiesItemTypeEquipList::vtbl", {
			{"CTypedPtrList<CPtrList,CImmunitiesItemTypeEquip*>::vtbl", offsetofbase<CImmunitiesItemTypeEquipList::vtbl, CTypedPtrList<CPtrList,CImmunitiesItemTypeEquip*>::vtbl>()},
		}},
		{"CImmunitiesProjectile", {
			{"CTypedPtrList<CPtrList,long*>", offsetofbase<CImmunitiesProjectile, CTypedPtrList<CPtrList,long*>>()},
		}},
		{"CImmunitiesProjectile::vtbl", {
			{"CTypedPtrList<CPtrList,long*>::vtbl", offsetofbase<CImmunitiesProjectile::vtbl, CTypedPtrList<CPtrList,long*>::vtbl>()},
		}},
		{"CImmunitiesSchoolAndSecondary", {
			{"CTypedPtrList<CPtrList,long*>", offsetofbase<CImmunitiesSchoolAndSecondary, CTypedPtrList<CPtrList,long*>>()},
		}},
		{"CImmunitiesSchoolAndSecondary::vtbl", {
			{"CTypedPtrList<CPtrList,long*>::vtbl", offsetofbase<CImmunitiesSchoolAndSecondary::vtbl, CTypedPtrList<CPtrList,long*>::vtbl>()},
		}},
		{"CImmunitiesSchoolAndSecondaryDecrementing", {
			{"CTypedPtrList<CPtrList,CSchoolAndSecondaryDecrementing*>", offsetofbase<CImmunitiesSchoolAndSecondaryDecrementing, CTypedPtrList<CPtrList,CSchoolAndSecondaryDecrementing*>>()},
		}},
		{"CImmunitiesSchoolAndSecondaryDecrementing::vtbl", {
			{"CTypedPtrList<CPtrList,CSchoolAndSecondaryDecrementing*>::vtbl", offsetofbase<CImmunitiesSchoolAndSecondaryDecrementing::vtbl, CTypedPtrList<CPtrList,CSchoolAndSecondaryDecrementing*>::vtbl>()},
		}},
		{"CImmunitiesSpellList", {
			{"CTypedPtrList<CPtrList,CImmunitySpell*>", offsetofbase<CImmunitiesSpellList, CTypedPtrList<CPtrList,CImmunitySpell*>>()},
		}},
		{"CImmunitiesSpellList::vtbl", {
			{"CTypedPtrList<CPtrList,CImmunitySpell*>::vtbl", offsetofbase<CImmunitiesSpellList::vtbl, CTypedPtrList<CPtrList,CImmunitySpell*>::vtbl>()},
		}},
		{"CImmunitiesWeapon", {
			{"CTypedPtrList<CPtrList,CWeaponIdentification*>", offsetofbase<CImmunitiesWeapon, CTypedPtrList<CPtrList,CWeaponIdentification*>>()},
		}},
		{"CImmunitiesWeapon::vtbl", {
			{"CTypedPtrList<CPtrList,CWeaponIdentification*>::vtbl", offsetofbase<CImmunitiesWeapon::vtbl, CTypedPtrList<CPtrList,CWeaponIdentification*>::vtbl>()},
		}},
		{"CMemINI", {
			{"CTypedPtrList<CPtrList,void*>", offsetofbase<CMemINI, CTypedPtrList<CPtrList,void*>>()},
		}},
		{"CMemINI::vtbl", {
			{"CTypedPtrList<CPtrList,void*>::vtbl", offsetofbase<CMemINI::vtbl, CTypedPtrList<CPtrList,void*>::vtbl>()},
		}},
		{"CMemINISection", {
			{"CTypedPtrList<CPtrList,CMemINIValue*>", offsetofbase<CMemINISection, CTypedPtrList<CPtrList,CMemINIValue*>>()},
		}},
		{"CMemINISection::vtbl", {
			{"CTypedPtrList<CPtrList,CMemINIValue*>::vtbl", offsetofbase<CMemINISection::vtbl, CTypedPtrList<CPtrList,CMemINIValue*>::vtbl>()},
		}},
		{"CMoveList", {
			{"CTypedPtrList<CPtrList,CMoveListEntry*>", offsetofbase<CMoveList, CTypedPtrList<CPtrList,CMoveListEntry*>>()},
		}},
		{"CMoveList::vtbl", {
			{"CTypedPtrList<CPtrList,CMoveListEntry*>::vtbl", offsetofbase<CMoveList::vtbl, CTypedPtrList<CPtrList,CMoveListEntry*>::vtbl>()},
		}},
		{"CPersistantEffectList", {
			{"CTypedPtrList<CPtrList,CPersistantEffect*>", offsetofbase<CPersistantEffectList, CTypedPtrList<CPtrList,CPersistantEffect*>>()},
		}},
		{"CPersistantEffectList::vtbl", {
			{"CTypedPtrList<CPtrList,CPersistantEffect*>::vtbl", offsetofbase<CPersistantEffectList::vtbl, CTypedPtrList<CPtrList,CPersistantEffect*>::vtbl>()},
		}},
		{"CSpawnList", {
			{"CTypedPtrList<CPtrList,CSpawn*>", offsetofbase<CSpawnList, CTypedPtrList<CPtrList,CSpawn*>>()},
		}},
		{"CSpawnList::vtbl", {
			{"CTypedPtrList<CPtrList,CSpawn*>::vtbl", offsetofbase<CSpawnList::vtbl, CTypedPtrList<CPtrList,CSpawn*>::vtbl>()},
		}},
		{"CSpawnFile", {
			{"CTypedPtrList<CPtrList,void*>", offsetofbase<CSpawnFile, CTypedPtrList<CPtrList,void*>>()},
		}},
		{"CSpawnFile::vtbl", {
			{"CTypedPtrList<CPtrList,void*>::vtbl", offsetofbase<CSpawnFile::vtbl, CTypedPtrList<CPtrList,void*>::vtbl>()},
		}},
		{"CSequenceSoundList", {
			{"CTypedPtrList<CPtrList,CSequenceSound*>", offsetofbase<CSequenceSoundList, CTypedPtrList<CPtrList,CSequenceSound*>>()},
		}},
		{"CSequenceSoundList::vtbl", {
			{"CTypedPtrList<CPtrList,CSequenceSound*>::vtbl", offsetofbase<CSequenceSoundList::vtbl, CTypedPtrList<CPtrList,CSequenceSound*>::vtbl>()},
		}},
		{"CSelectiveWeaponTypeList", {
			{"CTypedPtrList<CPtrList,CSelectiveWeaponType*>", offsetofbase<CSelectiveWeaponTypeList, CTypedPtrList<CPtrList,CSelectiveWeaponType*>>()},
		}},
		{"CSelectiveWeaponTypeList::vtbl", {
			{"CTypedPtrList<CPtrList,CSelectiveWeaponType*>::vtbl", offsetofbase<CSelectiveWeaponTypeList::vtbl, CTypedPtrList<CPtrList,CSelectiveWeaponType*>::vtbl>()},
		}},
		{"CSelectiveBonusList", {
			{"CTypedPtrList<CPtrList,CSelectiveBonus*>", offsetofbase<CSelectiveBonusList, CTypedPtrList<CPtrList,CSelectiveBonus*>>()},
		}},
		{"CSelectiveBonusList::vtbl", {
			{"CTypedPtrList<CPtrList,CSelectiveBonus*>::vtbl", offsetofbase<CSelectiveBonusList::vtbl, CTypedPtrList<CPtrList,CSelectiveBonus*>::vtbl>()},
		}},
		{"CPtrArray", {
			{"CObject", offsetofbase<CPtrArray, CObject>()},
		}},
		{"CPtrArray::vtbl", {
			{"CObject::vtbl", offsetofbase<CPtrArray::vtbl, CObject::vtbl>()},
		}},
		{"CGameDialogEntry", {
			{"CTypedPtrArray<CPtrArray,CGameDialogReply*>", offsetofbase<CGameDialogEntry, CTypedPtrArray<CPtrArray,CGameDialogReply*>>()},
		}},
		{"CGameDialogEntry::vtbl", {
			{"CTypedPtrArray<CPtrArray,CGameDialogReply*>::vtbl", offsetofbase<CGameDialogEntry::vtbl, CTypedPtrArray<CPtrArray,CGameDialogReply*>::vtbl>()},
		}},
		{"CGameAbilityList", {
			{"CTypedPtrArray<CPtrArray,CAbilityData*>", offsetofbase<CGameAbilityList, CTypedPtrArray<CPtrArray,CAbilityData*>>()},
		}},
		{"CGameAbilityList::vtbl", {
			{"CTypedPtrArray<CPtrArray,CAbilityData*>::vtbl", offsetofbase<CGameAbilityList::vtbl, CTypedPtrArray<CPtrArray,CAbilityData*>::vtbl>()},
		}},
		{"CSpawnPointArray", {
			{"CTypedPtrArray<CPtrArray,CSpawnPoint*>", offsetofbase<CSpawnPointArray, CTypedPtrArray<CPtrArray,CSpawnPoint*>>()},
		}},
		{"CSpawnPointArray::vtbl", {
			{"CTypedPtrArray<CPtrArray,CSpawnPoint*>::vtbl", offsetofbase<CSpawnPointArray::vtbl, CTypedPtrArray<CPtrArray,CSpawnPoint*>::vtbl>()},
		}},
		{"CObList", {
			{"CObject", offsetofbase<CObList, CObject>()},
		}},
		{"CObList::vtbl", {
			{"CObject::vtbl", offsetofbase<CObList::vtbl, CObject::vtbl>()},
		}},
		{"EEex_CWarp", {
			{"CObject", offsetofbase<CWarp, CObject>()},
		}},
		{"CWarp::vtbl", {
			{"CObject::vtbl", offsetofbase<CWarp::vtbl, CObject::vtbl>()},
		}},
		{"CMessageSetDirection", {
			{"CMessage", offsetofbase<CMessageSetDirection, CMessage>()},
		}},
		{"CMessageSetDirection::vtbl", {
			{"CMessage::vtbl", offsetofbase<CMessageSetDirection::vtbl, CMessage::vtbl>()},
		}},
		{"CMessageDisplayTextRef", {
			{"CMessage", offsetofbase<CMessageDisplayTextRef, CMessage>()},
		}},
		{"CMessageDisplayTextRef::vtbl", {
			{"CMessage::vtbl", offsetofbase<CMessageDisplayTextRef::vtbl, CMessage::vtbl>()},
		}},
		{"CMessageDisplayText", {
			{"CMessage", offsetofbase<CMessageDisplayText, CMessage>()},
		}},
		{"CMessageDisplayText::vtbl", {
			{"CMessage::vtbl", offsetofbase<CMessageDisplayText::vtbl, CMessage::vtbl>()},
		}},
		{"CMessageAddEffect", {
			{"CMessage", offsetofbase<CMessageAddEffect, CMessage>()},
		}},
		{"CMessageAddEffect::vtbl", {
			{"CMessage::vtbl", offsetofbase<CMessageAddEffect::vtbl, CMessage::vtbl>()},
		}},
		{"CFile", {
			{"CObject", offsetofbase<CFile, CObject>()},
		}},
		{"CFile::vtbl", {
			{"CObject::vtbl", offsetofbase<CFile::vtbl, CObject::vtbl>()},
		}},
		{"CContingencyList", {
			{"CTypedPtrList<CPtrList,CContingency*>", offsetofbase<CContingencyList, CTypedPtrList<CPtrList,CContingency*>>()},
		}},
		{"CContingencyList::vtbl", {
			{"CTypedPtrList<CPtrList,CContingency*>::vtbl", offsetofbase<CContingencyList::vtbl, CTypedPtrList<CPtrList,CContingency*>::vtbl>()},
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
		{"CBaldurEngine::vtbl", {
			{"EEex_CWarp::vtbl", offsetofbase<CBaldurEngine::vtbl, CWarp::vtbl>()},
		}},
		{"CDungeonMaster", {
			{"EEex_CBaldurEngine", offsetofbase<CDungeonMaster, CBaldurEngine>()},
		}},
		{"CDungeonMaster::vtbl", {
			{"EEex_CBaldurEngine::vtbl", offsetofbase<CDungeonMaster::vtbl, CBaldurEngine::vtbl>()},
		}},
		{"CVariable", {
			{"CAreaVariable", offsetofbase<CVariable, CAreaVariable>()},
		}},
		{"CVidTile", {
			{"CVidImage", offsetofbase<CVidTile, CVidImage>()},
		}},
		{"EEex_CScreenMovies", {
			{"EEex_CBaldurEngine", offsetofbase<CScreenMovies, CBaldurEngine>()},
		}},
		{"CScreenMovies::vtbl", {
			{"EEex_CBaldurEngine::vtbl", offsetofbase<CScreenMovies::vtbl, CBaldurEngine::vtbl>()},
		}},
		{"EEex_CScreenConnection", {
			{"EEex_CBaldurEngine", offsetofbase<CScreenConnection, CBaldurEngine>()},
		}},
		{"CScreenConnection::vtbl", {
			{"EEex_CBaldurEngine::vtbl", offsetofbase<CScreenConnection::vtbl, CBaldurEngine::vtbl>()},
		}},
		{"CGameStatsRes", {
			{"CObject", offsetofbase<CGameStatsRes, CObject>()},
		}},
		{"CGameStatsRes::vtbl", {
			{"CObject::vtbl", offsetofbase<CGameStatsRes::vtbl, CObject::vtbl>()},
		}},
		{"EEex_CScreenWizSpell", {
			{"EEex_CBaldurEngine", offsetofbase<CScreenWizSpell, CBaldurEngine>()},
		}},
		{"CScreenWizSpell::vtbl", {
			{"EEex_CBaldurEngine::vtbl", offsetofbase<CScreenWizSpell::vtbl, CBaldurEngine::vtbl>()},
		}},
		{"EEex_CScreenPriestSpell", {
			{"EEex_CBaldurEngine", offsetofbase<CScreenPriestSpell, CBaldurEngine>()},
		}},
		{"CScreenPriestSpell::vtbl", {
			{"EEex_CBaldurEngine::vtbl", offsetofbase<CScreenPriestSpell::vtbl, CBaldurEngine::vtbl>()},
		}},
		{"EEex_CScreenCharacter", {
			{"EEex_CBaldurEngine", offsetofbase<CScreenCharacter, CBaldurEngine>()},
		}},
		{"CScreenCharacter::vtbl", {
			{"EEex_CBaldurEngine::vtbl", offsetofbase<CScreenCharacter::vtbl, CBaldurEngine::vtbl>()},
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
		{"CScreenInventory::vtbl", {
			{"EEex_CBaldurEngine::vtbl", offsetofbase<CScreenInventory::vtbl, CBaldurEngine::vtbl>()},
		}},
		{"EEex_CScreenJournal", {
			{"EEex_CBaldurEngine", offsetofbase<CScreenJournal, CBaldurEngine>()},
		}},
		{"CScreenJournal::vtbl", {
			{"EEex_CBaldurEngine::vtbl", offsetofbase<CScreenJournal::vtbl, CBaldurEngine::vtbl>()},
		}},
		{"EEex_CScreenCreateChar", {
			{"EEex_CBaldurEngine", offsetofbase<CScreenCreateChar, CBaldurEngine>()},
		}},
		{"CScreenCreateChar::vtbl", {
			{"EEex_CBaldurEngine::vtbl", offsetofbase<CScreenCreateChar::vtbl, CBaldurEngine::vtbl>()},
		}},
		{"EEex_CScreenCreateParty", {
			{"EEex_CBaldurEngine", offsetofbase<CScreenCreateParty, CBaldurEngine>()},
		}},
		{"CScreenCreateParty::vtbl", {
			{"EEex_CBaldurEngine::vtbl", offsetofbase<CScreenCreateParty::vtbl, CBaldurEngine::vtbl>()},
		}},
		{"EEex_CScreenDLC", {
			{"EEex_CBaldurEngine", offsetofbase<CScreenDLC, CBaldurEngine>()},
		}},
		{"CScreenDLC::vtbl", {
			{"EEex_CBaldurEngine::vtbl", offsetofbase<CScreenDLC::vtbl, CBaldurEngine::vtbl>()},
		}},
		{"EEex_CScreenLoad", {
			{"EEex_CBaldurEngine", offsetofbase<CScreenLoad, CBaldurEngine>()},
		}},
		{"CScreenLoad::vtbl", {
			{"EEex_CBaldurEngine::vtbl", offsetofbase<CScreenLoad::vtbl, CBaldurEngine::vtbl>()},
		}},
		{"EEex_CScreenMap", {
			{"EEex_CBaldurEngine", offsetofbase<CScreenMap, CBaldurEngine>()},
		}},
		{"CScreenMap::vtbl", {
			{"EEex_CBaldurEngine::vtbl", offsetofbase<CScreenMap::vtbl, CBaldurEngine::vtbl>()},
		}},
		{"EEex_CScreenMultiPlayer", {
			{"EEex_CBaldurEngine", offsetofbase<CScreenMultiPlayer, CBaldurEngine>()},
		}},
		{"CScreenMultiPlayer::vtbl", {
			{"EEex_CBaldurEngine::vtbl", offsetofbase<CScreenMultiPlayer::vtbl, CBaldurEngine::vtbl>()},
		}},
		{"EEex_CScreenOptions", {
			{"EEex_CBaldurEngine", offsetofbase<CScreenOptions, CBaldurEngine>()},
		}},
		{"CScreenOptions::vtbl", {
			{"EEex_CBaldurEngine::vtbl", offsetofbase<CScreenOptions::vtbl, CBaldurEngine::vtbl>()},
		}},
		{"EEex_CScreenSave", {
			{"EEex_CBaldurEngine", offsetofbase<CScreenSave, CBaldurEngine>()},
		}},
		{"CScreenSave::vtbl", {
			{"EEex_CBaldurEngine::vtbl", offsetofbase<CScreenSave::vtbl, CBaldurEngine::vtbl>()},
		}},
		{"EEex_CScreenStart", {
			{"EEex_CBaldurEngine", offsetofbase<CScreenStart, CBaldurEngine>()},
		}},
		{"CScreenStart::vtbl", {
			{"EEex_CBaldurEngine::vtbl", offsetofbase<CScreenStart::vtbl, CBaldurEngine::vtbl>()},
		}},
		{"CVidCell", {
			{"CVidImage", offsetofbase<CVidCell, CVidImage>()},
			{"CResHelper<CResCell,1000>", offsetofbase<CVidCell, CResHelper<CResCell,1000>>()},
		}},
		{"EEex_CScreenWorldMap", {
			{"EEex_CBaldurEngine", offsetofbase<CScreenWorldMap, CBaldurEngine>()},
		}},
		{"CScreenWorldMap::vtbl", {
			{"EEex_CBaldurEngine::vtbl", offsetofbase<CScreenWorldMap::vtbl, CBaldurEngine::vtbl>()},
		}},
		{"CVidCellFont", {
			{"CVidCell", offsetofbase<CVidCellFont, CVidCell>()},
		}},
		{"CVidCellFont::vtbl", {
			{"CVidCell::vtbl", offsetofbase<CVidCellFont::vtbl, CVidCell::vtbl>()},
		}},
		{"CVidBitmap", {
			{"CVidImage", offsetofbase<CVidBitmap, CVidImage>()},
			{"CResHelper<CResBitmap,1>", offsetofbase<CVidBitmap, CResHelper<CResBitmap,1>>()},
		}},
		{"CScreenAI", {
			{"EEex_CBaldurEngine", offsetofbase<CScreenAI, CBaldurEngine>()},
		}},
		{"CScreenAI::vtbl", {
			{"EEex_CBaldurEngine::vtbl", offsetofbase<CScreenAI::vtbl, CBaldurEngine::vtbl>()},
		}},
		{"CSpell", {
			{"CResHelper<CResSpell,1006>", offsetofbase<CSpell, CResHelper<CResSpell,1006>>()},
		}},
		{"CSoundImp", {
			{"CObject", offsetofbase<CSoundImp, CObject>()},
			{"CResHelper<CResWave,4>", offsetofbase<CSoundImp, CResHelper<CResWave,4>>()},
		}},
		{"CSoundImp::vtbl", {
			{"CObject::vtbl", offsetofbase<CSoundImp::vtbl, CObject::vtbl>()},
		}},
		{"CSound", {
			{"CObject", offsetofbase<CSound, CObject>()},
			{"CResHelper<CResWave,4>", offsetofbase<CSound, CResHelper<CResWave,4>>()},
		}},
		{"CSound::vtbl", {
			{"CObject::vtbl", offsetofbase<CSound::vtbl, CObject::vtbl>()},
		}},
		{"EEex_CScreenChapter", {
			{"EEex_CBaldurEngine", offsetofbase<CScreenChapter, CBaldurEngine>()},
		}},
		{"CScreenChapter::vtbl", {
			{"EEex_CBaldurEngine::vtbl", offsetofbase<CScreenChapter::vtbl, CBaldurEngine::vtbl>()},
		}},
		{"EEex_CInfToolTip", {
			{"CVidCell", offsetofbase<CInfToolTip, CVidCell>()},
		}},
		{"CInfToolTip::vtbl", {
			{"CVidCell::vtbl", offsetofbase<CInfToolTip::vtbl, CVidCell::vtbl>()},
		}},
		{"EEex_CScreenWorld", {
			{"EEex_CBaldurEngine", offsetofbase<CScreenWorld, CBaldurEngine>()},
		}},
		{"CScreenWorld::vtbl", {
			{"EEex_CBaldurEngine::vtbl", offsetofbase<CScreenWorld::vtbl, CBaldurEngine::vtbl>()},
		}},
		{"CResBinary", {
			{"CRes", offsetofbase<CResBinary, CRes>()},
		}},
		{"CResBinary::vtbl", {
			{"CRes::vtbl", offsetofbase<CResBinary::vtbl, CRes::vtbl>()},
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
		{"CGameEffectUsability::vtbl", {
			{"CGameEffect::vtbl", offsetofbase<CGameEffectUsability::vtbl, CGameEffect::vtbl>()},
		}},
		{"CDerivedStats", {
			{"CDerivedStatsTemplate", offsetofbase<CDerivedStats, CDerivedStatsTemplate>()},
		}},
		{"EEex_CBaldurProjector", {
			{"EEex_CBaldurEngine", offsetofbase<CBaldurProjector, CBaldurEngine>()},
		}},
		{"CBaldurProjector::vtbl", {
			{"EEex_CBaldurEngine::vtbl", offsetofbase<CBaldurProjector::vtbl, CBaldurEngine::vtbl>()},
		}},
		{"EEex_CBaldurChitin", {
			{"EEex_CChitin", offsetofbase<CBaldurChitin, CChitin>()},
		}},
		{"CBaldurChitin::vtbl", {
			{"EEex_CChitin::vtbl", offsetofbase<CBaldurChitin::vtbl, CChitin::vtbl>()},
		}},
		{"EEex_CScreenStore", {
			{"EEex_CBaldurEngine", offsetofbase<CScreenStore, CBaldurEngine>()},
		}},
		{"CScreenStore::vtbl", {
			{"EEex_CBaldurEngine::vtbl", offsetofbase<CScreenStore::vtbl, CBaldurEngine::vtbl>()},
		}},
		{"CGameFireball3d", {
			{"CGameObject", offsetofbase<CGameFireball3d, CGameObject>()},
		}},
		{"CGameFireball3d::vtbl", {
			{"CGameObject::vtbl", offsetofbase<CGameFireball3d::vtbl, CGameObject::vtbl>()},
		}},
		{"CProjectile", {
			{"CGameObject", offsetofbase<CProjectile, CGameObject>()},
		}},
		{"CProjectile::vtbl", {
			{"CGameObject::vtbl", offsetofbase<CProjectile::vtbl, CGameObject::vtbl>()},
		}},
		{"CProjectileTravelDoor", {
			{"CProjectile", offsetofbase<CProjectileTravelDoor, CProjectile>()},
		}},
		{"CProjectileTravelDoor::vtbl", {
			{"CProjectile::vtbl", offsetofbase<CProjectileTravelDoor::vtbl, CProjectile::vtbl>()},
		}},
		{"CProjectileSpellHit", {
			{"CProjectile", offsetofbase<CProjectileSpellHit, CProjectile>()},
		}},
		{"CProjectileSpellHit::vtbl", {
			{"CProjectile::vtbl", offsetofbase<CProjectileSpellHit::vtbl, CProjectile::vtbl>()},
		}},
		{"CProjectileAmbiant", {
			{"CProjectileSpellHit", offsetofbase<CProjectileAmbiant, CProjectileSpellHit>()},
		}},
		{"CProjectileAmbiant::vtbl", {
			{"CProjectileSpellHit::vtbl", offsetofbase<CProjectileAmbiant::vtbl, CProjectileSpellHit::vtbl>()},
		}},
		{"CProjectileSkyStrike", {
			{"CProjectile", offsetofbase<CProjectileSkyStrike, CProjectile>()},
		}},
		{"CProjectileSkyStrike::vtbl", {
			{"CProjectile::vtbl", offsetofbase<CProjectileSkyStrike::vtbl, CProjectile::vtbl>()},
		}},
		{"CProjectileInstant", {
			{"CProjectile", offsetofbase<CProjectileInstant, CProjectile>()},
		}},
		{"CProjectileInstant::vtbl", {
			{"CProjectile::vtbl", offsetofbase<CProjectileInstant::vtbl, CProjectile::vtbl>()},
		}},
		{"CProjectileCallLightning", {
			{"CProjectileInstant", offsetofbase<CProjectileCallLightning, CProjectileInstant>()},
		}},
		{"CProjectileCallLightning::vtbl", {
			{"CProjectileInstant::vtbl", offsetofbase<CProjectileCallLightning::vtbl, CProjectileInstant::vtbl>()},
		}},
		{"CProjectileCastingGlow", {
			{"CProjectile", offsetofbase<CProjectileCastingGlow, CProjectile>()},
		}},
		{"CProjectileCastingGlow::vtbl", {
			{"CProjectile::vtbl", offsetofbase<CProjectileCastingGlow::vtbl, CProjectile::vtbl>()},
		}},
		{"CProjectileBAM", {
			{"CProjectile", offsetofbase<CProjectileBAM, CProjectile>()},
		}},
		{"CProjectileBAM::vtbl", {
			{"CProjectile::vtbl", offsetofbase<CProjectileBAM::vtbl, CProjectile::vtbl>()},
		}},
		{"CProjectileArea", {
			{"CProjectileBAM", offsetofbase<CProjectileArea, CProjectileBAM>()},
		}},
		{"CProjectileArea::vtbl", {
			{"CProjectileBAM::vtbl", offsetofbase<CProjectileArea::vtbl, CProjectileBAM::vtbl>()},
		}},
		{"CProjectileSkyStrikeBAM", {
			{"CProjectileBAM", offsetofbase<CProjectileSkyStrikeBAM, CProjectileBAM>()},
		}},
		{"CProjectileSkyStrikeBAM::vtbl", {
			{"CProjectileBAM::vtbl", offsetofbase<CProjectileSkyStrikeBAM::vtbl, CProjectileBAM::vtbl>()},
		}},
		{"CProjectileSegment", {
			{"CProjectileBAM", offsetofbase<CProjectileSegment, CProjectileBAM>()},
		}},
		{"CProjectileSegment::vtbl", {
			{"CProjectileBAM::vtbl", offsetofbase<CProjectileSegment::vtbl, CProjectileBAM::vtbl>()},
		}},
		{"CProjectileScorcher", {
			{"CProjectileBAM", offsetofbase<CProjectileScorcher, CProjectileBAM>()},
		}},
		{"CProjectileScorcher::vtbl", {
			{"CProjectileBAM::vtbl", offsetofbase<CProjectileScorcher::vtbl, CProjectileBAM::vtbl>()},
		}},
		{"CProjectileNewScorcher", {
			{"CProjectileBAM", offsetofbase<CProjectileNewScorcher, CProjectileBAM>()},
		}},
		{"CProjectileNewScorcher::vtbl", {
			{"CProjectileBAM::vtbl", offsetofbase<CProjectileNewScorcher::vtbl, CProjectileBAM::vtbl>()},
		}},
		{"CProjectileMushroom", {
			{"CProjectileBAM", offsetofbase<CProjectileMushroom, CProjectileBAM>()},
		}},
		{"CProjectileMushroom::vtbl", {
			{"CProjectileBAM::vtbl", offsetofbase<CProjectileMushroom::vtbl, CProjectileBAM::vtbl>()},
		}},
		{"CProjectileMulti", {
			{"CProjectileBAM", offsetofbase<CProjectileMulti, CProjectileBAM>()},
		}},
		{"CProjectileMulti::vtbl", {
			{"CProjectileBAM::vtbl", offsetofbase<CProjectileMulti::vtbl, CProjectileBAM::vtbl>()},
		}},
		{"CProjectileMagicMissileMulti", {
			{"CProjectileMulti", offsetofbase<CProjectileMagicMissileMulti, CProjectileMulti>()},
		}},
		{"CProjectileMagicMissileMulti::vtbl", {
			{"CProjectileMulti::vtbl", offsetofbase<CProjectileMagicMissileMulti::vtbl, CProjectileMulti::vtbl>()},
		}},
		{"CProjectileLightningBounce", {
			{"CProjectileBAM", offsetofbase<CProjectileLightningBounce, CProjectileBAM>()},
		}},
		{"CProjectileLightningBounce::vtbl", {
			{"CProjectileBAM::vtbl", offsetofbase<CProjectileLightningBounce::vtbl, CProjectileBAM::vtbl>()},
		}},
		{"CProjectileLightningBoltGround", {
			{"CProjectileBAM", offsetofbase<CProjectileLightningBoltGround, CProjectileBAM>()},
		}},
		{"CProjectileLightningBoltGround::vtbl", {
			{"CProjectileBAM::vtbl", offsetofbase<CProjectileLightningBoltGround::vtbl, CProjectileBAM::vtbl>()},
		}},
		{"CProjectileLightningBolt", {
			{"CProjectileBAM", offsetofbase<CProjectileLightningBolt, CProjectileBAM>()},
		}},
		{"CProjectileLightningBolt::vtbl", {
			{"CProjectileBAM::vtbl", offsetofbase<CProjectileLightningBolt::vtbl, CProjectileBAM::vtbl>()},
		}},
		{"CProjectileInvisibleTravelling", {
			{"CProjectileBAM", offsetofbase<CProjectileInvisibleTravelling, CProjectileBAM>()},
		}},
		{"CProjectileInvisibleTravelling::vtbl", {
			{"CProjectileBAM::vtbl", offsetofbase<CProjectileInvisibleTravelling::vtbl, CProjectileBAM::vtbl>()},
		}},
		{"CProjectileFireHands", {
			{"CProjectileBAM", offsetofbase<CProjectileFireHands, CProjectileBAM>()},
		}},
		{"CProjectileFireHands::vtbl", {
			{"CProjectileBAM::vtbl", offsetofbase<CProjectileFireHands::vtbl, CProjectileBAM::vtbl>()},
		}},
		{"CProjectileFall", {
			{"CProjectileBAM", offsetofbase<CProjectileFall, CProjectileBAM>()},
		}},
		{"CProjectileFall::vtbl", {
			{"CProjectileBAM::vtbl", offsetofbase<CProjectileFall::vtbl, CProjectileBAM::vtbl>()},
		}},
		{"CProjectileConeOfCold", {
			{"CProjectileBAM", offsetofbase<CProjectileConeOfCold, CProjectileBAM>()},
		}},
		{"CProjectileConeOfCold::vtbl", {
			{"CProjectileBAM::vtbl", offsetofbase<CProjectileConeOfCold::vtbl, CProjectileBAM::vtbl>()},
		}},
		{"CProjectileColorSpray", {
			{"CProjectileBAM", offsetofbase<CProjectileColorSpray, CProjectileBAM>()},
		}},
		{"CProjectileColorSpray::vtbl", {
			{"CProjectileBAM::vtbl", offsetofbase<CProjectileColorSpray::vtbl, CProjectileBAM::vtbl>()},
		}},
		{"CProjectileChain", {
			{"CProjectileBAM", offsetofbase<CProjectileChain, CProjectileBAM>()},
		}},
		{"CProjectileChain::vtbl", {
			{"CProjectileBAM::vtbl", offsetofbase<CProjectileChain::vtbl, CProjectileBAM::vtbl>()},
		}},
		{"CProjectileLightningStorm", {
			{"CProjectileChain", offsetofbase<CProjectileLightningStorm, CProjectileChain>()},
		}},
		{"CProjectileLightningStorm::vtbl", {
			{"CProjectileChain::vtbl", offsetofbase<CProjectileLightningStorm::vtbl, CProjectileChain::vtbl>()},
		}},
		{"CObjectMarker", {
			{"CGameObject", offsetofbase<CObjectMarker, CGameObject>()},
		}},
		{"CObjectMarker::vtbl", {
			{"CGameObject::vtbl", offsetofbase<CObjectMarker::vtbl, CGameObject::vtbl>()},
		}},
		{"CGameTemporal", {
			{"CGameObject", offsetofbase<CGameTemporal, CGameObject>()},
		}},
		{"CGameTemporal::vtbl", {
			{"CGameObject::vtbl", offsetofbase<CGameTemporal::vtbl, CGameObject::vtbl>()},
		}},
		{"CGameStatic", {
			{"CGameObject", offsetofbase<CGameStatic, CGameObject>()},
		}},
		{"CGameStatic::vtbl", {
			{"CGameObject::vtbl", offsetofbase<CGameStatic::vtbl, CGameObject::vtbl>()},
		}},
		{"CGameSpawning", {
			{"CGameObject", offsetofbase<CGameSpawning, CGameObject>()},
		}},
		{"CGameSpawning::vtbl", {
			{"CGameObject::vtbl", offsetofbase<CGameSpawning::vtbl, CGameObject::vtbl>()},
		}},
		{"CGameSound", {
			{"CGameObject", offsetofbase<CGameSound, CGameObject>()},
		}},
		{"CGameSound::vtbl", {
			{"CGameObject::vtbl", offsetofbase<CGameSound::vtbl, CGameObject::vtbl>()},
		}},
		{"CGameAIBase", {
			{"CGameObject", offsetofbase<CGameAIBase, CGameObject>()},
		}},
		{"CGameAIBase::vtbl", {
			{"CGameObject::vtbl", offsetofbase<CGameAIBase::vtbl, CGameObject::vtbl>()},
		}},
		{"CGameTrigger", {
			{"CGameAIBase", offsetofbase<CGameTrigger, CGameAIBase>()},
		}},
		{"CGameTrigger::vtbl", {
			{"CGameAIBase::vtbl", offsetofbase<CGameTrigger::vtbl, CGameAIBase::vtbl>()},
		}},
		{"CGameTiledObject", {
			{"CGameAIBase", offsetofbase<CGameTiledObject, CGameAIBase>()},
		}},
		{"CGameTiledObject::vtbl", {
			{"CGameAIBase::vtbl", offsetofbase<CGameTiledObject::vtbl, CGameAIBase::vtbl>()},
		}},
		{"CGameSprite", {
			{"CGameAIBase", offsetofbase<CGameSprite, CGameAIBase>()},
		}},
		{"CGameSprite::vtbl", {
			{"CGameAIBase::vtbl", offsetofbase<CGameSprite::vtbl, CGameAIBase::vtbl>()},
		}},
		{"CGameDoor", {
			{"CGameAIBase", offsetofbase<CGameDoor, CGameAIBase>()},
		}},
		{"CGameDoor::vtbl", {
			{"CGameAIBase::vtbl", offsetofbase<CGameDoor::vtbl, CGameAIBase::vtbl>()},
		}},
		{"CGameContainer", {
			{"CGameAIBase", offsetofbase<CGameContainer, CGameAIBase>()},
		}},
		{"CGameContainer::vtbl", {
			{"CGameAIBase::vtbl", offsetofbase<CGameContainer::vtbl, CGameAIBase::vtbl>()},
		}},
		{"CGameAIGame", {
			{"CGameAIBase", offsetofbase<CGameAIGame, CGameAIBase>()},
		}},
		{"CGameAIGame::vtbl", {
			{"CGameAIBase::vtbl", offsetofbase<CGameAIGame::vtbl, CGameAIBase::vtbl>()},
		}},
		{"CGameAIArea", {
			{"CGameAIBase", offsetofbase<CGameAIArea, CGameAIBase>()},
		}},
		{"CGameAIArea::vtbl", {
			{"CGameAIBase::vtbl", offsetofbase<CGameAIArea::vtbl, CGameAIBase::vtbl>()},
		}},
	});
}

