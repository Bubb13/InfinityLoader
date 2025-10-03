
#include "Baldur-v2.6.6.0_generated.h"
#include "Baldur-v2.6.6.0_lua_generated.h"
#include "lua_bindings_core_api.h"

static int tolua_get_EEex_Opcode_LuaHook_AfterListsResolved_Enabled(lua_State* L)
{
	tolua_pushboolean(L, (bool)EEex::Opcode_LuaHook_AfterListsResolved_Enabled);
	return 1;
}

static int tolua_set_EEex_Opcode_LuaHook_AfterListsResolved_Enabled(lua_State* L)
{
	EEex::Opcode_LuaHook_AfterListsResolved_Enabled = tolua_setter_toboolean(L, "Opcode_LuaHook_AfterListsResolved_Enabled");
	return 0;
}

static int tolua_get_EEex_reference_Opcode_LuaHook_AfterListsResolved_Enabled(lua_State* L)
{
	tolua_pushusertype(L, (void*)&EEex::Opcode_LuaHook_AfterListsResolved_Enabled, "Primitive<bool>");
	return 1;
}

static int tolua_get_EEex_Projectile_LuaHook_GlobalMutators_Enabled(lua_State* L)
{
	tolua_pushboolean(L, (bool)EEex::Projectile_LuaHook_GlobalMutators_Enabled);
	return 1;
}

static int tolua_set_EEex_Projectile_LuaHook_GlobalMutators_Enabled(lua_State* L)
{
	EEex::Projectile_LuaHook_GlobalMutators_Enabled = tolua_setter_toboolean(L, "Projectile_LuaHook_GlobalMutators_Enabled");
	return 0;
}

static int tolua_get_EEex_reference_Projectile_LuaHook_GlobalMutators_Enabled(lua_State* L)
{
	tolua_pushusertype(L, (void*)&EEex::Projectile_LuaHook_GlobalMutators_Enabled, "Primitive<bool>");
	return 1;
}

static int tolua_get_EEex_StutterDetector_Enabled(lua_State* L)
{
	tolua_pushboolean(L, (bool)EEex::StutterDetector_Enabled);
	return 1;
}

static int tolua_set_EEex_StutterDetector_Enabled(lua_State* L)
{
	EEex::StutterDetector_Enabled = tolua_setter_toboolean(L, "StutterDetector_Enabled");
	return 0;
}

static int tolua_get_EEex_reference_StutterDetector_Enabled(lua_State* L)
{
	tolua_pushusertype(L, (void*)&EEex::StutterDetector_Enabled, "Primitive<bool>");
	return 1;
}

static int tolua_get_EEex_UncapFPS_BusyWaitThreshold(lua_State* L)
{
	lua_pushinteger(L, (lua_Integer)EEex::UncapFPS_BusyWaitThreshold);
	return 1;
}

static int tolua_set_EEex_UncapFPS_BusyWaitThreshold(lua_State* L)
{
	EEex::UncapFPS_BusyWaitThreshold = tolua_setter_tointeger<int>(L, "UncapFPS_BusyWaitThreshold");
	return 0;
}

static int tolua_get_EEex_reference_UncapFPS_BusyWaitThreshold(lua_State* L)
{
	tolua_pushusertype(L, (void*)&EEex::UncapFPS_BusyWaitThreshold, "Primitive<int>");
	return 1;
}

static int tolua_get_EEex_UncapFPS_Enabled(lua_State* L)
{
	tolua_pushboolean(L, (bool)EEex::UncapFPS_Enabled);
	return 1;
}

static int tolua_set_EEex_UncapFPS_Enabled(lua_State* L)
{
	EEex::UncapFPS_Enabled = tolua_setter_toboolean(L, "UncapFPS_Enabled");
	return 0;
}

static int tolua_get_EEex_reference_UncapFPS_Enabled(lua_State* L)
{
	tolua_pushusertype(L, (void*)&EEex::UncapFPS_Enabled, "Primitive<bool>");
	return 1;
}

static int tolua_get_EEex_UncapFPS_FPSLimit(lua_State* L)
{
	lua_pushinteger(L, (lua_Integer)EEex::UncapFPS_FPSLimit);
	return 1;
}

static int tolua_set_EEex_UncapFPS_FPSLimit(lua_State* L)
{
	EEex::UncapFPS_FPSLimit = tolua_setter_tointeger<int>(L, "UncapFPS_FPSLimit");
	return 0;
}

static int tolua_get_EEex_reference_UncapFPS_FPSLimit(lua_State* L)
{
	tolua_pushusertype(L, (void*)&EEex::UncapFPS_FPSLimit, "Primitive<int>");
	return 1;
}

static int tolua_get_EEex_UncapFPS_RemoveMiddleMouseScrollMultiplier(lua_State* L)
{
	tolua_pushboolean(L, (bool)EEex::UncapFPS_RemoveMiddleMouseScrollMultiplier);
	return 1;
}

static int tolua_set_EEex_UncapFPS_RemoveMiddleMouseScrollMultiplier(lua_State* L)
{
	EEex::UncapFPS_RemoveMiddleMouseScrollMultiplier = tolua_setter_toboolean(L, "UncapFPS_RemoveMiddleMouseScrollMultiplier");
	return 0;
}

static int tolua_get_EEex_reference_UncapFPS_RemoveMiddleMouseScrollMultiplier(lua_State* L)
{
	tolua_pushusertype(L, (void*)&EEex::UncapFPS_RemoveMiddleMouseScrollMultiplier, "Primitive<bool>");
	return 1;
}

static int tolua_function_EEex_CreateTemplateFromCopy(lua_State* L)
{
	uiItem* returnVal = EEex::CreateTemplateFromCopy(L, tolua_function_tostring(L, 1, "CreateTemplateFromCopy"), tolua_function_tostring(L, 2, "CreateTemplateFromCopy"), (uiItem*)tolua_tousertype_dynamic(L, 3, 0, "uiItem"));
	tolua_pushusertype(L, (void*)returnVal, "uiItem");
	return 1;
}

static int tolua_function_EEex_DeepCopy(lua_State* L)
{
	EEex::DeepCopy(L);
	return 1;
}

static int tolua_function_EEex_DrawSlicedRect(lua_State* L)
{
	EEex::DrawSlicedRect(L);
	return 0;
}

static int tolua_function_EEex_DrawSlicedRectNum(lua_State* L)
{
	EEex::DrawSlicedRectNum(L);
	return 0;
}

static int tolua_function_EEex_DestroyAllTemplates(lua_State* L)
{
	EEex::DestroyAllTemplates(L, tolua_function_tostring(L, 1, "DestroyAllTemplates"));
	return 0;
}

static int tolua_function_EEex_ForceScrollbarRenderForItemName(lua_State* L)
{
	EEex::ForceScrollbarRenderForItemName(L);
	return 0;
}

static int tolua_function_EEex_FormatPointerAsEngine(lua_State* L)
{
	const char* returnVal = EEex::FormatPointerAsEngine(tolua_function_tointeger<uintptr_t>(L, 1, "FormatPointerAsEngine"));
	tolua_pushstring(L, (const char*)returnVal);
	return 1;
}

static int tolua_function_EEex_GetExtendedStatValue(lua_State* L)
{
	int returnVal = EEex::GetExtendedStatValue((CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite"), tolua_function_tointeger<int>(L, 2, "GetExtendedStatValue"));
	lua_pushinteger(L, (lua_Integer)returnVal);
	return 1;
}

static int tolua_function_EEex_GetHighestRefreshRate(lua_State* L)
{
	int returnVal = EEex::GetHighestRefreshRate();
	lua_pushinteger(L, (lua_Integer)returnVal);
	return 1;
}

static int tolua_function_EEex_GetINIString(lua_State* L)
{
	EEex::GetINIString(L, tolua_function_tostring(L, 1, "GetINIString"), tolua_function_tostring(L, 2, "GetINIString"), tolua_function_tostring(L, 3, "GetINIString"), tolua_function_tostring(L, 4, "GetINIString"));
	return 1;
}

static int tolua_function_EEex_GetProjectileStartingPos(lua_State* L)
{
	EEex::GetProjectileStartingPos(L, (CProjectile*)tolua_tousertype_dynamic(L, 1, 0, "CProjectile"), (CGameArea*)tolua_tousertype_dynamic(L, 2, 0, "CGameArea"), (CGameAIBase*)tolua_tousertype_dynamic(L, 3, 0, "CGameAIBase"), (CGameObject*)tolua_tousertype_dynamic(L, 4, 0, "CGameObject"), tolua_function_tointeger<int>(L, 5, "GetProjectileStartingPos"), tolua_function_tointeger<int>(L, 6, "GetProjectileStartingPos"), tolua_function_tointeger<int>(L, 7, "GetProjectileStartingPos"));
	return 3;
}

static int tolua_function_EEex_GetSpriteFromUUID(lua_State* L)
{
	CGameSprite* returnVal = EEex::GetSpriteFromUUID(tolua_function_tointeger<uint64_t>(L, 1, "GetSpriteFromUUID"));
	tolua_pushusertype(L, (void*)returnVal, "CGameSprite");
	return 1;
}

static int tolua_function_EEex_HookIntegrityWatchdogIgnoreRegisters(lua_State* L)
{
	EEex::HookIntegrityWatchdogIgnoreRegisters(tolua_function_tointeger<uintptr_t>(L, 1, "HookIntegrityWatchdogIgnoreRegisters"), tolua_function_tointeger<size_t>(L, 2, "HookIntegrityWatchdogIgnoreRegisters"), (EEex_HookIntegrityWatchdogRegister)tolua_function_tointeger<__int32>(L, 3, "HookIntegrityWatchdogIgnoreRegisters"));
	return 0;
}

static int tolua_function_EEex_HookIntegrityWatchdogIgnoreStackRange(lua_State* L)
{
	EEex::HookIntegrityWatchdogIgnoreStackRange(tolua_function_tointeger<uintptr_t>(L, 1, "HookIntegrityWatchdogIgnoreStackRange"), tolua_function_tointeger<size_t>(L, 2, "HookIntegrityWatchdogIgnoreStackRange"), tolua_function_tointeger<int>(L, 3, "HookIntegrityWatchdogIgnoreStackRange"), tolua_function_tointeger<int>(L, 4, "HookIntegrityWatchdogIgnoreStackRange"));
	return 0;
}

static int tolua_function_EEex_InjectTemplateInstance(lua_State* L)
{
	uiItem* returnVal = EEex::InjectTemplateInstance(L, tolua_function_tostring(L, 1, "InjectTemplateInstance"), tolua_function_tostring(L, 2, "InjectTemplateInstance"), tolua_function_tointeger<int>(L, 3, "InjectTemplateInstance"), tolua_function_tointeger<int>(L, 4, "InjectTemplateInstance"), tolua_function_tointeger<int>(L, 5, "InjectTemplateInstance"));
	tolua_pushusertype(L, (void*)returnVal, "uiItem");
	return 1;
}

static int tolua_function_EEex_IsDefaultAttackCursor(lua_State* L)
{
	bool returnVal = EEex::IsDefaultAttackCursor();
	tolua_pushboolean(L, (bool)returnVal);
	return 1;
}

static int tolua_function_EEex_IsMarshallingCopy(lua_State* L)
{
	bool returnVal = EEex::IsMarshallingCopy();
	tolua_pushboolean(L, (bool)returnVal);
	return 1;
}

static int tolua_function_EEex_IsPlayerScript(lua_State* L)
{
	bool returnVal = EEex::IsPlayerScript((CAIScript*)tolua_tousertype_dynamic(L, 1, 0, "CAIScript"));
	tolua_pushboolean(L, (bool)returnVal);
	return 1;
}

static int tolua_function_EEex_MatchObject(lua_State* L)
{
	long returnVal = EEex::MatchObject(L, (CGameObject*)tolua_tousertype_dynamic(L, 1, 0, "CGameObject"), tolua_function_tostring(L, 2, "MatchObject"), tolua_function_tointeger<int>(L, 3, "MatchObject"), tolua_function_tointeger<int>(L, 4, "MatchObject"), (EEex_MatchObjectFlags)tolua_function_tointeger<__int32>(L, 5, "MatchObject"));
	lua_pushinteger(L, (lua_Integer)returnVal);
	return 1;
}

static int tolua_function_EEex_RegisterSlicedRect(lua_State* L)
{
	EEex::RegisterSlicedRect(L);
	return 0;
}

static int tolua_function_EEex_SetINIString(lua_State* L)
{
	EEex::SetINIString(tolua_function_tostring(L, 1, "SetINIString"), tolua_function_tostring(L, 2, "SetINIString"), tolua_function_tostring(L, 3, "SetINIString"), tolua_function_tostring(L, 4, "SetINIString"));
	return 0;
}

static int tolua_function_EEex_SetUIItemExtraScrollbarPad(lua_State* L)
{
	EEex::SetUIItemExtraScrollbarPad((uiItem*)tolua_tousertype_dynamic(L, 1, 0, "uiItem"), tolua_function_tointeger<int>(L, 2, "SetUIItemExtraScrollbarPad"));
	return 0;
}

static int tolua_function_EEex_ShouldEffectBypassOp120(lua_State* L)
{
	bool returnVal = EEex::ShouldEffectBypassOp120((CGameEffect*)tolua_tousertype_dynamic(L, 1, 0, "CGameEffect"));
	tolua_pushboolean(L, (bool)returnVal);
	return 1;
}

static int tolua_function_CGameSprite_getUUID(lua_State* L)
{
	CGameSprite* self = (CGameSprite*)tolua_tousertype_dynamic(L, 1, 0, "CGameSprite");
	if (!self) tolua_error(L, "invalid 'self' in calling function 'getUUID'", NULL);
	uint64_t returnVal = self->GetUUID();
	lua_pushinteger(L, (lua_Integer)returnVal);
	return 1;
}

static void tolua_reg_types(lua_State* L)
{
	tolua_usertype(L, "EEex_ScriptingObject");
	tolua_usertype(L, "EEex_MatchObjectFlags");
	tolua_usertype(L, "EEex_HookIntegrityWatchdogRegister");
	tolua_usertype(L, "CSteamID");
	tolua_usertype(L, "CSteamID::SteamID_t");
	tolua_usertype(L, "frameTableEntry_st");
	tolua_usertype(L, "frameTableEntry_st::_anonymous_tag_");
	tolua_usertype(L, "SDL_SysWMmsg");
	tolua_usertype(L, "SDL_SysWMmsg::msg_t");
	tolua_usertype(L, "Udata");
	tolua_usertype(L, "TString");
	tolua_usertype(L, "ISteamUserStats");
	tolua_usertype(L, "DPWrapper");
	tolua_usertype(L, "CallInfo");
	tolua_usertype(L, "CallInfo::u_t");
	tolua_usertype(L, "UpVal");
	tolua_usertype(L, "UpVal::u_t");
	tolua_usertype(L, "TKey");
	tolua_usertype(L, "uiVariant");
	tolua_usertype(L, "ISteamUGC");
	tolua_usertype(L, "ISteamRemoteStorage");
	tolua_usertype(L, "IDPProvider");
	tolua_usertype(L, "IDPPeer");
	tolua_usertype(L, "EEex");
	tolua_usertype(L, "EEex::ProjectileType");
	tolua_usertype(L, "CRes");
	tolua_usertype(L, "CResWorldMap");
	tolua_usertype(L, "CResWave");
	tolua_usertype(L, "CResWED");
	tolua_usertype(L, "CResUI");
	tolua_usertype(L, "CResTileSet");
	tolua_usertype(L, "CResText");
	tolua_usertype(L, "CResStore");
	tolua_usertype(L, "CResSpell");
	tolua_usertype(L, "CResPng");
	tolua_usertype(L, "CResPVR");
	tolua_usertype(L, "CResPLT");
	tolua_usertype(L, "CResMosaic");
	tolua_usertype(L, "CResItem");
	tolua_usertype(L, "CResINI");
	tolua_usertype(L, "CResGame");
	tolua_usertype(L, "CResFont");
	tolua_usertype(L, "CResEffect");
	tolua_usertype(L, "CResDLG");
	tolua_usertype(L, "CResCell");
	tolua_usertype(L, "CResCRE");
	tolua_usertype(L, "CResCHR");
	tolua_usertype(L, "CResBitmap");
	tolua_usertype(L, "CResBIO");
	tolua_usertype(L, "CResArea");
	tolua_usertype(L, "CResWebm");
	tolua_usertype(L, "CAOEEntry");
	tolua_usertype(L, "CSpawnPoint");
	tolua_usertype(L, "CPersistantEffect");
	tolua_usertype(L, "CObject");
	tolua_usertype(L, "CArray<CRect,CRect*>");
	tolua_usertype(L, "CDWordArray");
	tolua_usertype(L, "CException");
	tolua_usertype(L, "CFileException");
	tolua_usertype(L, "CList<long,long>");
	tolua_usertype(L, "CList<unsigned long,unsigned long*>");
	tolua_usertype(L, "CMapStringToString");
	tolua_usertype(L, "CVoice");
	tolua_usertype(L, "CTypedPtrList<CPtrList,CAIId*>");
	tolua_usertype(L, "CTypedPtrList<CPtrList,CAreaUserNote*>");
	tolua_usertype(L, "CTypedPtrList<CPtrList,CAIAction*>");
	tolua_usertype(L, "CTypedPtrList<CPtrList,CAITrigger*>");
	tolua_usertype(L, "CTypedPtrList<CPtrList,CGameTimer*>");
	tolua_usertype(L, "CTypedPtrList<CPtrList,CCreatureFileKnownSpell*>");
	tolua_usertype(L, "CTypedPtrList<CPtrList,CCreatureFileMemorizedSpell*>");
	tolua_usertype(L, "CTypedPtrList<CPtrList,long*>");
	tolua_usertype(L, "CTypedPtrList<CPtrList,CBlood*>");
	tolua_usertype(L, "CTypedPtrList<CPtrList,CPortraitIcon*>");
	tolua_usertype(L, "CTypedPtrList<CPtrList,CPoint*>");
	tolua_usertype(L, "CTypedPtrList<CPtrList,CFeedbackEntry*>");
	tolua_usertype(L, "CTypedPtrList<CPtrList,CGameSprite::GroundItem*>");
	tolua_usertype(L, "CTypedPtrList<CPtrList,CResRef*>");
	tolua_usertype(L, "CTypedPtrList<CPtrList,CSearchRequest*>");
	tolua_usertype(L, "CTypedPtrList<CPtrList,SAreaFileWrapper*>");
	tolua_usertype(L, "CTypedPtrList<CPtrList,CSavedGameStoredLocation*>");
	tolua_usertype(L, "CTypedPtrList<CPtrList,CAOEEntry*>");
	tolua_usertype(L, "CTypedPtrList<CPtrList,long>");
	tolua_usertype(L, "CTypedPtrList<CPtrList,CAreaFileCharacterEntryPoint*>");
	tolua_usertype(L, "CTypedPtrList<CPtrList,__POSITION*>");
	tolua_usertype(L, "CTypedPtrList<CPtrList,CTiledObject*>");
	tolua_usertype(L, "CTypedPtrList<CPtrList,CGameAreaClairvoyanceEntry*>");
	tolua_usertype(L, "CTypedPtrList<CPtrList,CVEFEvent*>");
	tolua_usertype(L, "CTypedPtrList<CPtrList,CAIObjectType*>");
	tolua_usertype(L, "CTypedPtrList<CPtrList,CAIConditionResponse*>");
	tolua_usertype(L, "CTypedPtrList<CPtrList,CMessage*>");
	tolua_usertype(L, "CTypedPtrList<CPtrList,CDeathSound*>");
	tolua_usertype(L, "CTypedPtrList<CPtrList,CItem*>");
	tolua_usertype(L, "CTypedPtrList<CPtrList,CContingency*>");
	tolua_usertype(L, "CTypedPtrList<CPtrList,cnetworkwindow_queueentry_st*>");
	tolua_usertype(L, "CTypedPtrList<CPtrList,CMusicPosition*>");
	tolua_usertype(L, "CTypedPtrList<CPtrList,CGameJournalEntry*>");
	tolua_usertype(L, "CTypedPtrList<CPtrList,CMoveListEntry*>");
	tolua_usertype(L, "CTypedPtrList<CPtrList,void*>");
	tolua_usertype(L, "CTypedPtrList<CPtrList,CGameEffectUsability*>");
	tolua_usertype(L, "CTypedPtrList<CPtrList,CStoreFileItem*>");
	tolua_usertype(L, "CTypedPtrList<CPtrList,CMemINIValue*>");
	tolua_usertype(L, "CTypedPtrList<CPtrList,CAIResponse*>");
	tolua_usertype(L, "CTypedPtrList<CPtrList,CSpawn*>");
	tolua_usertype(L, "CTypedPtrList<CPtrList,CGameEffect*>");
	tolua_usertype(L, "CTypedPtrList<CPtrList,CWeaponIdentification*>");
	tolua_usertype(L, "CTypedPtrList<CPtrList,CSelectiveBonus*>");
	tolua_usertype(L, "CTypedPtrList<CPtrList,CImmunitiesItemEquip*>");
	tolua_usertype(L, "CTypedPtrList<CPtrList,CImmunitiesItemTypeEquip*>");
	tolua_usertype(L, "CTypedPtrList<CPtrList,CImmunitySpell*>");
	tolua_usertype(L, "CTypedPtrList<CPtrList,CSchoolAndSecondaryDecrementing*>");
	tolua_usertype(L, "CTypedPtrList<CPtrList,CPersistantEffect*>");
	tolua_usertype(L, "CTypedPtrList<CPtrList,CColorRange*>");
	tolua_usertype(L, "CTypedPtrList<CPtrList,CColorEffect*>");
	tolua_usertype(L, "CTypedPtrList<CPtrList,CSelectiveWeaponType*>");
	tolua_usertype(L, "CTypedPtrList<CPtrList,CCriticalEntry*>");
	tolua_usertype(L, "CTypedPtrList<CPtrList,EEex_CGameOptions*>");
	tolua_usertype(L, "CTypedPtrList<CPtrList,CString*>");
	tolua_usertype(L, "CTypedPtrList<CPtrList,CBounceEntry*>");
	tolua_usertype(L, "CTypedPtrList<CPtrList,CSequenceSound*>");
	tolua_usertype(L, "CTypedPtrList<CPtrList,CButtonData*>");
	tolua_usertype(L, "CTypedPtrList<CPtrList,CParticle*>");
	tolua_usertype(L, "CTypedPtrList<CPtrList,CVidCell*>");
	tolua_usertype(L, "CTypedPtrList<CPtrList,CProjectile*>");
	tolua_usertype(L, "CTypedPtrList<CPtrList,EEex_CWarp*>");
	tolua_usertype(L, "CTypedPtrList<CPtrList,CScreenStoreItem*>");
	tolua_usertype(L, "CTypedPtrList<CPtrList,CSound*>");
	tolua_usertype(L, "CTypedPtrList<CPtrList,CVoice*>");
	tolua_usertype(L, "CTypedPtrList<CPtrList,CTimer*>");
	tolua_usertype(L, "CTypedPtrArray<CPtrArray,CRes*>");
	tolua_usertype(L, "CTypedPtrArray<CPtrArray,CTypedPtrList<CPtrList,CGameJournalEntry*>*>");
	tolua_usertype(L, "CTypedPtrArray<CPtrArray,CSavedGamePartyCreature*>");
	tolua_usertype(L, "CTypedPtrArray<CPtrArray,unsigned char*>");
	tolua_usertype(L, "CTypedPtrArray<CPtrArray,CAbilityData*>");
	tolua_usertype(L, "CTypedPtrArray<CPtrArray,CSaveGameSlot*>");
	tolua_usertype(L, "CTypedPtrArray<CPtrArray,CGameDialogEntry*>");
	tolua_usertype(L, "CTypedPtrArray<CPtrArray,CSpawnPoint*>");
	tolua_usertype(L, "CTypedPtrArray<CPtrArray,CGameDialogReply*>");
	tolua_usertype(L, "CTypedPtrArray<CPtrArray,long>");
	tolua_usertype(L, "CTypedPtrArray<CPtrArray,__int8>");
	tolua_usertype(L, "CTypedPtrArray<CPtrArray,CSoundChannel*>");
	tolua_usertype(L, "CTimer");
	tolua_usertype(L, "CStringList");
	tolua_usertype(L, "CPtrList");
	tolua_usertype(L, "CImmunitiesProjectile");
	tolua_usertype(L, "CImmunitiesSchoolAndSecondary");
	tolua_usertype(L, "CGameButtonList");
	tolua_usertype(L, "CImmunitiesAIType");
	tolua_usertype(L, "CPersistantEffectListRegenerated");
	tolua_usertype(L, "EEex_CWarp");
	tolua_usertype(L, "CApplyEffectList");
	tolua_usertype(L, "CBounceList");
	tolua_usertype(L, "CColorEffects");
	tolua_usertype(L, "CColorRanges");
	tolua_usertype(L, "CCriticalEntryList");
	tolua_usertype(L, "CGameEffectUsabilityList");
	tolua_usertype(L, "CImmunitiesEffect");
	tolua_usertype(L, "CImmunitiesItemEquipList");
	tolua_usertype(L, "CImmunitiesItemTypeEquipList");
	tolua_usertype(L, "CImmunitiesSchoolAndSecondaryDecrementing");
	tolua_usertype(L, "CImmunitiesSpellList");
	tolua_usertype(L, "CImmunitiesWeapon");
	tolua_usertype(L, "CMemINI");
	tolua_usertype(L, "CMemINISection");
	tolua_usertype(L, "CMoveList");
	tolua_usertype(L, "CPersistantEffectList");
	tolua_usertype(L, "CSpawnList");
	tolua_usertype(L, "CSpawnFile");
	tolua_usertype(L, "CSoundChannel");
	tolua_usertype(L, "CSequenceSoundList");
	tolua_usertype(L, "CSelectiveWeaponTypeList");
	tolua_usertype(L, "CSelectiveBonusList");
	tolua_usertype(L, "CPtrArray");
	tolua_usertype(L, "CGameDialogEntry");
	tolua_usertype(L, "CGameAbilityList");
	tolua_usertype(L, "CSpawnPointArray");
	tolua_usertype(L, "CObList");
	tolua_usertype(L, "CMessage");
	tolua_usertype(L, "CMessageUpdateReaction");
	tolua_usertype(L, "CMessageSetDirection");
	tolua_usertype(L, "CMessageDisplayTextRef");
	tolua_usertype(L, "CMessageDisplayText");
	tolua_usertype(L, "CMessageAddEffect");
	tolua_usertype(L, "CMessageAddClairvoyance");
	tolua_usertype(L, "CMemINIValue");
	tolua_usertype(L, "CGameEffectList");
	tolua_usertype(L, "CFile");
	tolua_usertype(L, "CContingencyList");
	tolua_usertype(L, "CCallbackBase");
	tolua_usertype(L, "CCallResult<CSteam,CreateItemResult_t>");
	tolua_usertype(L, "CCallResult<CSteam,SteamUGCQueryCompleted_t>");
	tolua_usertype(L, "CCallResult<CSteam,SubmitItemUpdateResult_t>");
	tolua_usertype(L, "CCallResult<CSteam,SteamUGCRequestUGCDetailsResult_t>");
	tolua_usertype(L, "EEex_CBaldurEngine");
	tolua_usertype(L, "CDungeonMaster");
	tolua_usertype(L, "uiItem");
	tolua_usertype(L, "CResBinary");
	tolua_usertype(L, "CSteam");
	tolua_usertype(L, "EEex_CScreenMovies");
	tolua_usertype(L, "EEex_CScreenConnection");
	tolua_usertype(L, "CAIIdList");
	tolua_usertype(L, "CSound");
	tolua_usertype(L, "CSoundImp");
	tolua_usertype(L, "CScreenAI");
	tolua_usertype(L, "CVidCell");
	tolua_usertype(L, "CVidCellFont");
	tolua_usertype(L, "EEex_CScreenCreateChar");
	tolua_usertype(L, "EEex_CScreenCreateParty");
	tolua_usertype(L, "EEex_CScreenDLC");
	tolua_usertype(L, "EEex_CScreenLoad");
	tolua_usertype(L, "EEex_CScreenMap");
	tolua_usertype(L, "EEex_CScreenMultiPlayer");
	tolua_usertype(L, "EEex_CScreenOptions");
	tolua_usertype(L, "EEex_CScreenSave");
	tolua_usertype(L, "EEex_CScreenStart");
	tolua_usertype(L, "EEex_CInfToolTip");
	tolua_usertype(L, "CGameStatsRes");
	tolua_usertype(L, "EEex_CScreenWorldMap");
	tolua_usertype(L, "EEex_CScreenWorld");
	tolua_usertype(L, "EEex_CScreenWizSpell");
	tolua_usertype(L, "EEex_CScreenPriestSpell");
	tolua_usertype(L, "EEex_CScreenJournal");
	tolua_usertype(L, "EEex_CScreenInventory");
	tolua_usertype(L, "EEex_CScreenCharacter");
	tolua_usertype(L, "EEex_CScreenChapter");
	tolua_usertype(L, "EEex_CChitin");
	tolua_usertype(L, "CItem");
	tolua_usertype(L, "CGameEffect");
	tolua_usertype(L, "CGameEffectDamage");
	tolua_usertype(L, "CGameEffectUsability");
	tolua_usertype(L, "CGameAnimationType");
	tolua_usertype(L, "EEex_CBaldurProjector");
	tolua_usertype(L, "EEex_CBaldurChitin");
	tolua_usertype(L, "CGameArea");
	tolua_usertype(L, "CSpawn");
	tolua_usertype(L, "EEex_CScreenStore");
	tolua_usertype(L, "CMessageSetLastObject");
	tolua_usertype(L, "CGameObject");
	tolua_usertype(L, "CGameFireball3d");
	tolua_usertype(L, "CVisualEffect");
	tolua_usertype(L, "CProjectile");
	tolua_usertype(L, "CProjectileTravelDoor");
	tolua_usertype(L, "CProjectileSpellHit");
	tolua_usertype(L, "CProjectileAmbiant");
	tolua_usertype(L, "CProjectileSkyStrike");
	tolua_usertype(L, "CProjectileInstant");
	tolua_usertype(L, "CProjectileCallLightning");
	tolua_usertype(L, "CProjectileCastingGlow");
	tolua_usertype(L, "CProjectileBAM");
	tolua_usertype(L, "CProjectileArea");
	tolua_usertype(L, "CProjectileSkyStrikeBAM");
	tolua_usertype(L, "CProjectileSegment");
	tolua_usertype(L, "CProjectileScorcher");
	tolua_usertype(L, "CProjectileNewScorcher");
	tolua_usertype(L, "CProjectileMushroom");
	tolua_usertype(L, "CProjectileMulti");
	tolua_usertype(L, "CProjectileMagicMissileMulti");
	tolua_usertype(L, "CProjectileLightningBounce");
	tolua_usertype(L, "CProjectileLightningBoltGround");
	tolua_usertype(L, "CProjectileLightningBolt");
	tolua_usertype(L, "CProjectileInvisibleTravelling");
	tolua_usertype(L, "CProjectileFireHands");
	tolua_usertype(L, "CProjectileFall");
	tolua_usertype(L, "CProjectileConeOfCold");
	tolua_usertype(L, "CProjectileColorSpray");
	tolua_usertype(L, "CProjectileChain");
	tolua_usertype(L, "CProjectileLightningStorm");
	tolua_usertype(L, "CObjectMarker");
	tolua_usertype(L, "CGameTemporal");
	tolua_usertype(L, "CGameStatic");
	tolua_usertype(L, "CGameSpawning");
	tolua_usertype(L, "CGameSound");
	tolua_usertype(L, "CMessageSetTrigger");
	tolua_usertype(L, "CGameAIBase");
	tolua_usertype(L, "CGameTrigger");
	tolua_usertype(L, "CGameTiledObject");
	tolua_usertype(L, "CGameSprite");
	tolua_usertype(L, "CGameDoor");
	tolua_usertype(L, "CGameContainer");
	tolua_usertype(L, "CGameAIGame");
	tolua_usertype(L, "CGameAIArea");
}

void registerBaseclasses();
int OpenBindingsInternal(lua_State* L)
{
	registerBaseclasses();
	tolua_open(L);
	tolua_reg_types(L);
	tolua_module(L, NULL, 0);
	tolua_beginmodule(L, NULL);
	tolua_cclass(L, "EEex_ScriptingObject", "EEex_ScriptingObject", {"__int32"}, NULL);
	tolua_beginmodule(L, "EEex_ScriptingObject");
		tolua_constant(L, "ATTACKER", 0);
		tolua_constant(L, "ORDERED_BY", 1);
		tolua_constant(L, "HITTER", 2);
		tolua_constant(L, "HELP", 3);
		tolua_constant(L, "TRIGGER", 4);
		tolua_constant(L, "SEEN", 5);
		tolua_constant(L, "TALKED_TO", 6);
		tolua_constant(L, "HEARD", 7);
		tolua_constant(L, "SUMMONED_BY", 8);
		tolua_constant(L, "KILLED", 9);
	tolua_endmodule(L);
	tolua_cclass(L, "EEex_MatchObjectFlags", "EEex_MatchObjectFlags", {"__int32"}, NULL);
	tolua_beginmodule(L, "EEex_MatchObjectFlags");
		tolua_constant(L, "IGNORE_LOS", 1);
		tolua_constant(L, "MATCH_NON_SPRITES", 2);
		tolua_constant(L, "IGNORE_INVISIBLE", 4);
		tolua_constant(L, "MATCH_INVISIBLE", 8);
		tolua_constant(L, "MATCH_SLEEPING", 16);
		tolua_constant(L, "MATCH_DEAD", 32);
		tolua_constant(L, "MATCH_BACKLIST", 64);
		tolua_constant(L, "PRIORITIZE_BACKLIST", 128);
		tolua_constant(L, "MATCH_ONLY_BACKLIST", 256);
		tolua_constant(L, "FARTHEST", 512);
	tolua_endmodule(L);
	tolua_cclass(L, "EEex_HookIntegrityWatchdogRegister", "EEex_HookIntegrityWatchdogRegister", {"__int32"}, NULL);
	tolua_beginmodule(L, "EEex_HookIntegrityWatchdogRegister");
		tolua_constant(L, "RAX", 1);
		tolua_constant(L, "RBX", 2);
		tolua_constant(L, "RCX", 4);
		tolua_constant(L, "RDX", 8);
		tolua_constant(L, "RBP", 16);
		tolua_constant(L, "RSP", 32);
		tolua_constant(L, "RSI", 64);
		tolua_constant(L, "RDI", 128);
		tolua_constant(L, "R8", 256);
		tolua_constant(L, "R9", 512);
		tolua_constant(L, "R10", 1024);
		tolua_constant(L, "R11", 2048);
		tolua_constant(L, "R12", 65536);
		tolua_constant(L, "R13", 131072);
		tolua_constant(L, "R14", 262144);
		tolua_constant(L, "R15", 524288);
	tolua_endmodule(L);
	tolua_cclass(L, "CSteamID", "CSteamID", {}, NULL);
	tolua_beginmodule(L, "CSteamID");
	tolua_endmodule(L);
	tolua_cclass(L, "CSteamID::SteamID_t", "CSteamID::SteamID_t", {}, NULL);
	tolua_beginmodule(L, "CSteamID::SteamID_t");
	tolua_endmodule(L);
	tolua_cclass(L, "frameTableEntry_st", "frameTableEntry_st", {}, NULL);
	tolua_beginmodule(L, "frameTableEntry_st");
	tolua_endmodule(L);
	tolua_cclass(L, "frameTableEntry_st::_anonymous_tag_", "frameTableEntry_st::_anonymous_tag_", {}, NULL);
	tolua_beginmodule(L, "frameTableEntry_st::_anonymous_tag_");
	tolua_endmodule(L);
	tolua_cclass(L, "SDL_SysWMmsg", "SDL_SysWMmsg", {}, NULL);
	tolua_beginmodule(L, "SDL_SysWMmsg");
	tolua_endmodule(L);
	tolua_cclass(L, "SDL_SysWMmsg::msg_t", "SDL_SysWMmsg::msg_t", {}, NULL);
	tolua_beginmodule(L, "SDL_SysWMmsg::msg_t");
	tolua_endmodule(L);
	tolua_cclass(L, "Udata", "Udata", {}, NULL);
	tolua_beginmodule(L, "Udata");
	tolua_endmodule(L);
	tolua_cclass(L, "TString", "TString", {}, NULL);
	tolua_beginmodule(L, "TString");
	tolua_endmodule(L);
	tolua_cclass(L, "ISteamUserStats", "ISteamUserStats", {}, NULL);
	tolua_beginmodule(L, "ISteamUserStats");
	tolua_endmodule(L);
	tolua_cclass(L, "DPWrapper", "DPWrapper", {}, NULL);
	tolua_beginmodule(L, "DPWrapper");
	tolua_endmodule(L);
	tolua_cclass(L, "CallInfo", "CallInfo", {}, NULL);
	tolua_beginmodule(L, "CallInfo");
	tolua_endmodule(L);
	tolua_cclass(L, "CallInfo::u_t", "CallInfo::u_t", {}, NULL);
	tolua_beginmodule(L, "CallInfo::u_t");
	tolua_endmodule(L);
	tolua_cclass(L, "UpVal", "UpVal", {}, NULL);
	tolua_beginmodule(L, "UpVal");
	tolua_endmodule(L);
	tolua_cclass(L, "UpVal::u_t", "UpVal::u_t", {}, NULL);
	tolua_beginmodule(L, "UpVal::u_t");
	tolua_endmodule(L);
	tolua_cclass(L, "TKey", "TKey", {}, NULL);
	tolua_beginmodule(L, "TKey");
	tolua_endmodule(L);
	tolua_cclass(L, "uiVariant", "uiVariant", {}, NULL);
	tolua_beginmodule(L, "uiVariant");
	tolua_endmodule(L);
	tolua_cclass(L, "ISteamUGC", "ISteamUGC", {}, NULL);
	tolua_beginmodule(L, "ISteamUGC");
	tolua_endmodule(L);
	tolua_cclass(L, "ISteamRemoteStorage", "ISteamRemoteStorage", {}, NULL);
	tolua_beginmodule(L, "ISteamRemoteStorage");
	tolua_endmodule(L);
	tolua_cclass(L, "IDPProvider", "IDPProvider", {}, NULL);
	tolua_beginmodule(L, "IDPProvider");
	tolua_endmodule(L);
	tolua_cclass(L, "IDPPeer", "IDPPeer", {}, NULL);
	tolua_beginmodule(L, "IDPPeer");
	tolua_endmodule(L);
	tolua_cclass(L, "EEex", "EEex", {}, NULL);
	tolua_beginmodule(L, "EEex");
		tolua_variable(L, "Opcode_LuaHook_AfterListsResolved_Enabled", tolua_get_EEex_Opcode_LuaHook_AfterListsResolved_Enabled, tolua_set_EEex_Opcode_LuaHook_AfterListsResolved_Enabled);
		tolua_variable(L, "reference_Opcode_LuaHook_AfterListsResolved_Enabled", tolua_get_EEex_reference_Opcode_LuaHook_AfterListsResolved_Enabled, NULL);
		tolua_variable(L, "Projectile_LuaHook_GlobalMutators_Enabled", tolua_get_EEex_Projectile_LuaHook_GlobalMutators_Enabled, tolua_set_EEex_Projectile_LuaHook_GlobalMutators_Enabled);
		tolua_variable(L, "reference_Projectile_LuaHook_GlobalMutators_Enabled", tolua_get_EEex_reference_Projectile_LuaHook_GlobalMutators_Enabled, NULL);
		tolua_variable(L, "StutterDetector_Enabled", tolua_get_EEex_StutterDetector_Enabled, tolua_set_EEex_StutterDetector_Enabled);
		tolua_variable(L, "reference_StutterDetector_Enabled", tolua_get_EEex_reference_StutterDetector_Enabled, NULL);
		tolua_variable(L, "UncapFPS_BusyWaitThreshold", tolua_get_EEex_UncapFPS_BusyWaitThreshold, tolua_set_EEex_UncapFPS_BusyWaitThreshold);
		tolua_variable(L, "reference_UncapFPS_BusyWaitThreshold", tolua_get_EEex_reference_UncapFPS_BusyWaitThreshold, NULL);
		tolua_variable(L, "UncapFPS_Enabled", tolua_get_EEex_UncapFPS_Enabled, tolua_set_EEex_UncapFPS_Enabled);
		tolua_variable(L, "reference_UncapFPS_Enabled", tolua_get_EEex_reference_UncapFPS_Enabled, NULL);
		tolua_variable(L, "UncapFPS_FPSLimit", tolua_get_EEex_UncapFPS_FPSLimit, tolua_set_EEex_UncapFPS_FPSLimit);
		tolua_variable(L, "reference_UncapFPS_FPSLimit", tolua_get_EEex_reference_UncapFPS_FPSLimit, NULL);
		tolua_variable(L, "UncapFPS_RemoveMiddleMouseScrollMultiplier", tolua_get_EEex_UncapFPS_RemoveMiddleMouseScrollMultiplier, tolua_set_EEex_UncapFPS_RemoveMiddleMouseScrollMultiplier);
		tolua_variable(L, "reference_UncapFPS_RemoveMiddleMouseScrollMultiplier", tolua_get_EEex_reference_UncapFPS_RemoveMiddleMouseScrollMultiplier, NULL);
		tolua_function(L, "CreateTemplateFromCopy", &tolua_function_EEex_CreateTemplateFromCopy);
		tolua_function(L, "DeepCopy", &tolua_function_EEex_DeepCopy);
		tolua_function(L, "DrawSlicedRect", &tolua_function_EEex_DrawSlicedRect);
		tolua_function(L, "DrawSlicedRectNum", &tolua_function_EEex_DrawSlicedRectNum);
		tolua_function(L, "DestroyAllTemplates", &tolua_function_EEex_DestroyAllTemplates);
		tolua_function(L, "ForceScrollbarRenderForItemName", &tolua_function_EEex_ForceScrollbarRenderForItemName);
		tolua_function(L, "FormatPointerAsEngine", &tolua_function_EEex_FormatPointerAsEngine);
		tolua_function(L, "GetExtendedStatValue", &tolua_function_EEex_GetExtendedStatValue);
		tolua_function(L, "GetHighestRefreshRate", &tolua_function_EEex_GetHighestRefreshRate);
		tolua_function(L, "GetINIString", &tolua_function_EEex_GetINIString);
		tolua_function(L, "GetProjectileStartingPos", &tolua_function_EEex_GetProjectileStartingPos);
		tolua_function(L, "GetSpriteFromUUID", &tolua_function_EEex_GetSpriteFromUUID);
		tolua_function(L, "HookIntegrityWatchdogIgnoreRegisters", &tolua_function_EEex_HookIntegrityWatchdogIgnoreRegisters);
		tolua_function(L, "HookIntegrityWatchdogIgnoreStackRange", &tolua_function_EEex_HookIntegrityWatchdogIgnoreStackRange);
		tolua_function(L, "InjectTemplateInstance", &tolua_function_EEex_InjectTemplateInstance);
		tolua_function(L, "IsDefaultAttackCursor", &tolua_function_EEex_IsDefaultAttackCursor);
		tolua_function(L, "IsMarshallingCopy", &tolua_function_EEex_IsMarshallingCopy);
		tolua_function(L, "IsPlayerScript", &tolua_function_EEex_IsPlayerScript);
		tolua_function(L, "MatchObject", &tolua_function_EEex_MatchObject);
		tolua_function(L, "RegisterSlicedRect", &tolua_function_EEex_RegisterSlicedRect);
		tolua_function(L, "SetINIString", &tolua_function_EEex_SetINIString);
		tolua_function(L, "SetUIItemExtraScrollbarPad", &tolua_function_EEex_SetUIItemExtraScrollbarPad);
		tolua_function(L, "ShouldEffectBypassOp120", &tolua_function_EEex_ShouldEffectBypassOp120);
	tolua_endmodule(L);
	tolua_cclass(L, "EEex::ProjectileType", "EEex::ProjectileType", {"__int32"}, NULL);
	tolua_beginmodule(L, "EEex::ProjectileType");
		tolua_constant(L, "Unknown", 1);
		tolua_constant(L, "CProjectile", 2);
		tolua_constant(L, "CProjectileAmbiant", 4);
		tolua_constant(L, "CProjectileArea", 8);
		tolua_constant(L, "CProjectileBAM", 16);
		tolua_constant(L, "CProjectileChain", 32);
		tolua_constant(L, "CProjectileColorSpray", 64);
		tolua_constant(L, "CProjectileConeOfCold", 128);
		tolua_constant(L, "CProjectileFall", 256);
		tolua_constant(L, "CProjectileFireHands", 512);
		tolua_constant(L, "CProjectileInstant", 1024);
		tolua_constant(L, "CProjectileMulti", 2048);
		tolua_constant(L, "CProjectileMushroom", 4096);
		tolua_constant(L, "CProjectileNewScorcher", 8192);
		tolua_constant(L, "CProjectileScorcher", 16384);
		tolua_constant(L, "CProjectileSegment", 32768);
		tolua_constant(L, "CProjectileSkyStrike", 65536);
		tolua_constant(L, "CProjectileSkyStrikeBAM", 131072);
		tolua_constant(L, "CProjectileSpellHit", 262144);
		tolua_constant(L, "CProjectileTravelDoor", 524288);
	tolua_endmodule(L);
	tolua_cclass(L, "CRes", "CRes", {}, NULL);
	tolua_beginmodule(L, "CRes");
	tolua_endmodule(L);
	tolua_cclass(L, "CResWorldMap", "CResWorldMap", {"CRes"}, NULL);
	tolua_beginmodule(L, "CResWorldMap");
	tolua_endmodule(L);
	tolua_cclass(L, "CResWave", "CResWave", {"CRes"}, NULL);
	tolua_beginmodule(L, "CResWave");
	tolua_endmodule(L);
	tolua_cclass(L, "CResWED", "CResWED", {"CRes"}, NULL);
	tolua_beginmodule(L, "CResWED");
	tolua_endmodule(L);
	tolua_cclass(L, "CResUI", "CResUI", {"CRes"}, NULL);
	tolua_beginmodule(L, "CResUI");
	tolua_endmodule(L);
	tolua_cclass(L, "CResTileSet", "CResTileSet", {"CRes"}, NULL);
	tolua_beginmodule(L, "CResTileSet");
	tolua_endmodule(L);
	tolua_cclass(L, "CResText", "CResText", {"CRes"}, NULL);
	tolua_beginmodule(L, "CResText");
	tolua_endmodule(L);
	tolua_cclass(L, "CResStore", "CResStore", {"CRes"}, NULL);
	tolua_beginmodule(L, "CResStore");
	tolua_endmodule(L);
	tolua_cclass(L, "CResSpell", "CResSpell", {"CRes"}, NULL);
	tolua_beginmodule(L, "CResSpell");
	tolua_endmodule(L);
	tolua_cclass(L, "CResPng", "CResPng", {"CRes"}, NULL);
	tolua_beginmodule(L, "CResPng");
	tolua_endmodule(L);
	tolua_cclass(L, "CResPVR", "CResPVR", {"CRes"}, NULL);
	tolua_beginmodule(L, "CResPVR");
	tolua_endmodule(L);
	tolua_cclass(L, "CResPLT", "CResPLT", {"CRes"}, NULL);
	tolua_beginmodule(L, "CResPLT");
	tolua_endmodule(L);
	tolua_cclass(L, "CResMosaic", "CResMosaic", {"CRes"}, NULL);
	tolua_beginmodule(L, "CResMosaic");
	tolua_endmodule(L);
	tolua_cclass(L, "CResItem", "CResItem", {"CRes"}, NULL);
	tolua_beginmodule(L, "CResItem");
	tolua_endmodule(L);
	tolua_cclass(L, "CResINI", "CResINI", {"CRes"}, NULL);
	tolua_beginmodule(L, "CResINI");
	tolua_endmodule(L);
	tolua_cclass(L, "CResGame", "CResGame", {"CRes"}, NULL);
	tolua_beginmodule(L, "CResGame");
	tolua_endmodule(L);
	tolua_cclass(L, "CResFont", "CResFont", {"CRes"}, NULL);
	tolua_beginmodule(L, "CResFont");
	tolua_endmodule(L);
	tolua_cclass(L, "CResEffect", "CResEffect", {"CRes"}, NULL);
	tolua_beginmodule(L, "CResEffect");
	tolua_endmodule(L);
	tolua_cclass(L, "CResDLG", "CResDLG", {"CRes"}, NULL);
	tolua_beginmodule(L, "CResDLG");
	tolua_endmodule(L);
	tolua_cclass(L, "CResCell", "CResCell", {"CRes"}, NULL);
	tolua_beginmodule(L, "CResCell");
	tolua_endmodule(L);
	tolua_cclass(L, "CResCRE", "CResCRE", {"CRes"}, NULL);
	tolua_beginmodule(L, "CResCRE");
	tolua_endmodule(L);
	tolua_cclass(L, "CResCHR", "CResCHR", {"CRes"}, NULL);
	tolua_beginmodule(L, "CResCHR");
	tolua_endmodule(L);
	tolua_cclass(L, "CResBitmap", "CResBitmap", {"CRes"}, NULL);
	tolua_beginmodule(L, "CResBitmap");
	tolua_endmodule(L);
	tolua_cclass(L, "CResBIO", "CResBIO", {"CRes"}, NULL);
	tolua_beginmodule(L, "CResBIO");
	tolua_endmodule(L);
	tolua_cclass(L, "CResArea", "CResArea", {"CRes"}, NULL);
	tolua_beginmodule(L, "CResArea");
	tolua_endmodule(L);
	tolua_cclass(L, "CResWebm", "CResWebm", {"CRes"}, NULL);
	tolua_beginmodule(L, "CResWebm");
	tolua_endmodule(L);
	tolua_cclass(L, "CAOEEntry", "CAOEEntry", {}, NULL);
	tolua_beginmodule(L, "CAOEEntry");
	tolua_endmodule(L);
	tolua_cclass(L, "CSpawnPoint", "CSpawnPoint", {}, NULL);
	tolua_beginmodule(L, "CSpawnPoint");
	tolua_endmodule(L);
	tolua_cclass(L, "CPersistantEffect", "CPersistantEffect", {}, NULL);
	tolua_beginmodule(L, "CPersistantEffect");
	tolua_endmodule(L);
	tolua_cclass(L, "CObject", "CObject", {}, NULL);
	tolua_beginmodule(L, "CObject");
	tolua_endmodule(L);
	tolua_cclass(L, "CArray<CRect,CRect*>", "CArray<CRect,CRect*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CArray<CRect,CRect*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CDWordArray", "CDWordArray", {"CObject"}, NULL);
	tolua_beginmodule(L, "CDWordArray");
	tolua_endmodule(L);
	tolua_cclass(L, "CException", "CException", {"CObject"}, NULL);
	tolua_beginmodule(L, "CException");
	tolua_endmodule(L);
	tolua_cclass(L, "CFileException", "CFileException", {"CException"}, NULL);
	tolua_beginmodule(L, "CFileException");
	tolua_endmodule(L);
	tolua_cclass(L, "CList<long,long>", "CList<long,long>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CList<long,long>");
	tolua_endmodule(L);
	tolua_cclass(L, "CList<unsigned long,unsigned long*>", "CList<unsigned long,unsigned long*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CList<unsigned long,unsigned long*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CMapStringToString", "CMapStringToString", {"CObject"}, NULL);
	tolua_beginmodule(L, "CMapStringToString");
	tolua_endmodule(L);
	tolua_cclass(L, "CVoice", "CVoice", {"CObject"}, NULL);
	tolua_beginmodule(L, "CVoice");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,CAIId*>", "CTypedPtrList<CPtrList,CAIId*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,CAIId*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,CAreaUserNote*>", "CTypedPtrList<CPtrList,CAreaUserNote*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,CAreaUserNote*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,CAIAction*>", "CTypedPtrList<CPtrList,CAIAction*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,CAIAction*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,CAITrigger*>", "CTypedPtrList<CPtrList,CAITrigger*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,CAITrigger*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,CGameTimer*>", "CTypedPtrList<CPtrList,CGameTimer*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,CGameTimer*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,CCreatureFileKnownSpell*>", "CTypedPtrList<CPtrList,CCreatureFileKnownSpell*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,CCreatureFileKnownSpell*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,CCreatureFileMemorizedSpell*>", "CTypedPtrList<CPtrList,CCreatureFileMemorizedSpell*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,CCreatureFileMemorizedSpell*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,long*>", "CTypedPtrList<CPtrList,long*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,long*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,CBlood*>", "CTypedPtrList<CPtrList,CBlood*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,CBlood*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,CPortraitIcon*>", "CTypedPtrList<CPtrList,CPortraitIcon*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,CPortraitIcon*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,CPoint*>", "CTypedPtrList<CPtrList,CPoint*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,CPoint*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,CFeedbackEntry*>", "CTypedPtrList<CPtrList,CFeedbackEntry*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,CFeedbackEntry*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,CGameSprite::GroundItem*>", "CTypedPtrList<CPtrList,CGameSprite::GroundItem*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,CGameSprite::GroundItem*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,CResRef*>", "CTypedPtrList<CPtrList,CResRef*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,CResRef*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,CSearchRequest*>", "CTypedPtrList<CPtrList,CSearchRequest*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,CSearchRequest*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,SAreaFileWrapper*>", "CTypedPtrList<CPtrList,SAreaFileWrapper*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,SAreaFileWrapper*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,CSavedGameStoredLocation*>", "CTypedPtrList<CPtrList,CSavedGameStoredLocation*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,CSavedGameStoredLocation*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,CAOEEntry*>", "CTypedPtrList<CPtrList,CAOEEntry*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,CAOEEntry*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,long>", "CTypedPtrList<CPtrList,long>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,long>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,CAreaFileCharacterEntryPoint*>", "CTypedPtrList<CPtrList,CAreaFileCharacterEntryPoint*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,CAreaFileCharacterEntryPoint*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,__POSITION*>", "CTypedPtrList<CPtrList,__POSITION*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,__POSITION*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,CTiledObject*>", "CTypedPtrList<CPtrList,CTiledObject*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,CTiledObject*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,CGameAreaClairvoyanceEntry*>", "CTypedPtrList<CPtrList,CGameAreaClairvoyanceEntry*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,CGameAreaClairvoyanceEntry*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,CVEFEvent*>", "CTypedPtrList<CPtrList,CVEFEvent*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,CVEFEvent*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,CAIObjectType*>", "CTypedPtrList<CPtrList,CAIObjectType*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,CAIObjectType*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,CAIConditionResponse*>", "CTypedPtrList<CPtrList,CAIConditionResponse*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,CAIConditionResponse*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,CMessage*>", "CTypedPtrList<CPtrList,CMessage*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,CMessage*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,CDeathSound*>", "CTypedPtrList<CPtrList,CDeathSound*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,CDeathSound*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,CItem*>", "CTypedPtrList<CPtrList,CItem*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,CItem*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,CContingency*>", "CTypedPtrList<CPtrList,CContingency*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,CContingency*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,cnetworkwindow_queueentry_st*>", "CTypedPtrList<CPtrList,cnetworkwindow_queueentry_st*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,cnetworkwindow_queueentry_st*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,CMusicPosition*>", "CTypedPtrList<CPtrList,CMusicPosition*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,CMusicPosition*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,CGameJournalEntry*>", "CTypedPtrList<CPtrList,CGameJournalEntry*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,CGameJournalEntry*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,CMoveListEntry*>", "CTypedPtrList<CPtrList,CMoveListEntry*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,CMoveListEntry*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,void*>", "CTypedPtrList<CPtrList,void*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,void*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,CGameEffectUsability*>", "CTypedPtrList<CPtrList,CGameEffectUsability*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,CGameEffectUsability*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,CStoreFileItem*>", "CTypedPtrList<CPtrList,CStoreFileItem*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,CStoreFileItem*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,CMemINIValue*>", "CTypedPtrList<CPtrList,CMemINIValue*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,CMemINIValue*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,CAIResponse*>", "CTypedPtrList<CPtrList,CAIResponse*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,CAIResponse*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,CSpawn*>", "CTypedPtrList<CPtrList,CSpawn*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,CSpawn*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,CGameEffect*>", "CTypedPtrList<CPtrList,CGameEffect*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,CGameEffect*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,CWeaponIdentification*>", "CTypedPtrList<CPtrList,CWeaponIdentification*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,CWeaponIdentification*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,CSelectiveBonus*>", "CTypedPtrList<CPtrList,CSelectiveBonus*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,CSelectiveBonus*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,CImmunitiesItemEquip*>", "CTypedPtrList<CPtrList,CImmunitiesItemEquip*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,CImmunitiesItemEquip*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,CImmunitiesItemTypeEquip*>", "CTypedPtrList<CPtrList,CImmunitiesItemTypeEquip*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,CImmunitiesItemTypeEquip*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,CImmunitySpell*>", "CTypedPtrList<CPtrList,CImmunitySpell*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,CImmunitySpell*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,CSchoolAndSecondaryDecrementing*>", "CTypedPtrList<CPtrList,CSchoolAndSecondaryDecrementing*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,CSchoolAndSecondaryDecrementing*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,CPersistantEffect*>", "CTypedPtrList<CPtrList,CPersistantEffect*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,CPersistantEffect*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,CColorRange*>", "CTypedPtrList<CPtrList,CColorRange*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,CColorRange*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,CColorEffect*>", "CTypedPtrList<CPtrList,CColorEffect*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,CColorEffect*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,CSelectiveWeaponType*>", "CTypedPtrList<CPtrList,CSelectiveWeaponType*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,CSelectiveWeaponType*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,CCriticalEntry*>", "CTypedPtrList<CPtrList,CCriticalEntry*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,CCriticalEntry*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,EEex_CGameOptions*>", "CTypedPtrList<CPtrList,EEex_CGameOptions*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,EEex_CGameOptions*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,CString*>", "CTypedPtrList<CPtrList,CString*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,CString*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,CBounceEntry*>", "CTypedPtrList<CPtrList,CBounceEntry*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,CBounceEntry*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,CSequenceSound*>", "CTypedPtrList<CPtrList,CSequenceSound*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,CSequenceSound*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,CButtonData*>", "CTypedPtrList<CPtrList,CButtonData*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,CButtonData*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,CParticle*>", "CTypedPtrList<CPtrList,CParticle*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,CParticle*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,CVidCell*>", "CTypedPtrList<CPtrList,CVidCell*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,CVidCell*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,CProjectile*>", "CTypedPtrList<CPtrList,CProjectile*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,CProjectile*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,EEex_CWarp*>", "CTypedPtrList<CPtrList,EEex_CWarp*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,EEex_CWarp*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,CScreenStoreItem*>", "CTypedPtrList<CPtrList,CScreenStoreItem*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,CScreenStoreItem*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,CSound*>", "CTypedPtrList<CPtrList,CSound*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,CSound*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,CVoice*>", "CTypedPtrList<CPtrList,CVoice*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,CVoice*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrList<CPtrList,CTimer*>", "CTypedPtrList<CPtrList,CTimer*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrList<CPtrList,CTimer*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrArray<CPtrArray,CRes*>", "CTypedPtrArray<CPtrArray,CRes*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrArray<CPtrArray,CRes*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrArray<CPtrArray,CTypedPtrList<CPtrList,CGameJournalEntry*>*>", "CTypedPtrArray<CPtrArray,CTypedPtrList<CPtrList,CGameJournalEntry*>*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrArray<CPtrArray,CTypedPtrList<CPtrList,CGameJournalEntry*>*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrArray<CPtrArray,CSavedGamePartyCreature*>", "CTypedPtrArray<CPtrArray,CSavedGamePartyCreature*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrArray<CPtrArray,CSavedGamePartyCreature*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrArray<CPtrArray,unsigned char*>", "CTypedPtrArray<CPtrArray,unsigned char*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrArray<CPtrArray,unsigned char*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrArray<CPtrArray,CAbilityData*>", "CTypedPtrArray<CPtrArray,CAbilityData*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrArray<CPtrArray,CAbilityData*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrArray<CPtrArray,CSaveGameSlot*>", "CTypedPtrArray<CPtrArray,CSaveGameSlot*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrArray<CPtrArray,CSaveGameSlot*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrArray<CPtrArray,CGameDialogEntry*>", "CTypedPtrArray<CPtrArray,CGameDialogEntry*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrArray<CPtrArray,CGameDialogEntry*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrArray<CPtrArray,CSpawnPoint*>", "CTypedPtrArray<CPtrArray,CSpawnPoint*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrArray<CPtrArray,CSpawnPoint*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrArray<CPtrArray,CGameDialogReply*>", "CTypedPtrArray<CPtrArray,CGameDialogReply*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrArray<CPtrArray,CGameDialogReply*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrArray<CPtrArray,long>", "CTypedPtrArray<CPtrArray,long>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrArray<CPtrArray,long>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrArray<CPtrArray,__int8>", "CTypedPtrArray<CPtrArray,__int8>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrArray<CPtrArray,__int8>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTypedPtrArray<CPtrArray,CSoundChannel*>", "CTypedPtrArray<CPtrArray,CSoundChannel*>", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTypedPtrArray<CPtrArray,CSoundChannel*>");
	tolua_endmodule(L);
	tolua_cclass(L, "CTimer", "CTimer", {"CObject"}, NULL);
	tolua_beginmodule(L, "CTimer");
	tolua_endmodule(L);
	tolua_cclass(L, "CStringList", "CStringList", {"CObject"}, NULL);
	tolua_beginmodule(L, "CStringList");
	tolua_endmodule(L);
	tolua_cclass(L, "CPtrList", "CPtrList", {"CObject"}, NULL);
	tolua_beginmodule(L, "CPtrList");
	tolua_endmodule(L);
	tolua_cclass(L, "CImmunitiesProjectile", "CImmunitiesProjectile", {"CTypedPtrList<CPtrList,long>"}, NULL);
	tolua_beginmodule(L, "CImmunitiesProjectile");
	tolua_endmodule(L);
	tolua_cclass(L, "CImmunitiesSchoolAndSecondary", "CImmunitiesSchoolAndSecondary", {"CTypedPtrList<CPtrList,long>"}, NULL);
	tolua_beginmodule(L, "CImmunitiesSchoolAndSecondary");
	tolua_endmodule(L);
	tolua_cclass(L, "CGameButtonList", "CGameButtonList", {"CTypedPtrList<CPtrList,CButtonData*>"}, NULL);
	tolua_beginmodule(L, "CGameButtonList");
	tolua_endmodule(L);
	tolua_cclass(L, "CImmunitiesAIType", "CImmunitiesAIType", {"CTypedPtrList<CPtrList,CAIObjectType*>"}, NULL);
	tolua_beginmodule(L, "CImmunitiesAIType");
	tolua_endmodule(L);
	tolua_cclass(L, "CPersistantEffectListRegenerated", "CPersistantEffectListRegenerated", {"CTypedPtrList<CPtrList,CPersistantEffect*>"}, NULL);
	tolua_beginmodule(L, "CPersistantEffectListRegenerated");
	tolua_endmodule(L);
	tolua_cclass(L, "EEex_CWarp", "EEex_CWarp", {"CObject"}, NULL);
	tolua_beginmodule(L, "EEex_CWarp");
	tolua_endmodule(L);
	tolua_cclass(L, "CApplyEffectList", "CApplyEffectList", {"CTypedPtrList<CPtrList,CGameEffect*>"}, NULL);
	tolua_beginmodule(L, "CApplyEffectList");
	tolua_endmodule(L);
	tolua_cclass(L, "CBounceList", "CBounceList", {"CTypedPtrList<CPtrList,CBounceEntry*>"}, NULL);
	tolua_beginmodule(L, "CBounceList");
	tolua_endmodule(L);
	tolua_cclass(L, "CColorEffects", "CColorEffects", {"CTypedPtrList<CPtrList,CColorEffect*>"}, NULL);
	tolua_beginmodule(L, "CColorEffects");
	tolua_endmodule(L);
	tolua_cclass(L, "CColorRanges", "CColorRanges", {"CTypedPtrList<CPtrList,CColorRange*>"}, NULL);
	tolua_beginmodule(L, "CColorRanges");
	tolua_endmodule(L);
	tolua_cclass(L, "CCriticalEntryList", "CCriticalEntryList", {"CTypedPtrList<CPtrList,CCriticalEntry*>"}, NULL);
	tolua_beginmodule(L, "CCriticalEntryList");
	tolua_endmodule(L);
	tolua_cclass(L, "CGameEffectUsabilityList", "CGameEffectUsabilityList", {"CTypedPtrList<CPtrList,CGameEffectUsability*>"}, NULL);
	tolua_beginmodule(L, "CGameEffectUsabilityList");
	tolua_endmodule(L);
	tolua_cclass(L, "CImmunitiesEffect", "CImmunitiesEffect", {"CTypedPtrList<CPtrList,CGameEffect*>"}, NULL);
	tolua_beginmodule(L, "CImmunitiesEffect");
	tolua_endmodule(L);
	tolua_cclass(L, "CImmunitiesItemEquipList", "CImmunitiesItemEquipList", {"CTypedPtrList<CPtrList,CImmunitiesItemEquip*>"}, NULL);
	tolua_beginmodule(L, "CImmunitiesItemEquipList");
	tolua_endmodule(L);
	tolua_cclass(L, "CImmunitiesItemTypeEquipList", "CImmunitiesItemTypeEquipList", {"CTypedPtrList<CPtrList,CImmunitiesItemTypeEquip*>"}, NULL);
	tolua_beginmodule(L, "CImmunitiesItemTypeEquipList");
	tolua_endmodule(L);
	tolua_cclass(L, "CImmunitiesSchoolAndSecondaryDecrementing", "CImmunitiesSchoolAndSecondaryDecrementing", {"CTypedPtrList<CPtrList,CSchoolAndSecondaryDecrementing*>"}, NULL);
	tolua_beginmodule(L, "CImmunitiesSchoolAndSecondaryDecrementing");
	tolua_endmodule(L);
	tolua_cclass(L, "CImmunitiesSpellList", "CImmunitiesSpellList", {"CTypedPtrList<CPtrList,CImmunitySpell*>"}, NULL);
	tolua_beginmodule(L, "CImmunitiesSpellList");
	tolua_endmodule(L);
	tolua_cclass(L, "CImmunitiesWeapon", "CImmunitiesWeapon", {"CTypedPtrList<CPtrList,CWeaponIdentification*>"}, NULL);
	tolua_beginmodule(L, "CImmunitiesWeapon");
	tolua_endmodule(L);
	tolua_cclass(L, "CMemINI", "CMemINI", {"CTypedPtrList<CPtrList,void*>"}, NULL);
	tolua_beginmodule(L, "CMemINI");
	tolua_endmodule(L);
	tolua_cclass(L, "CMemINISection", "CMemINISection", {"CTypedPtrList<CPtrList,CMemINIValue*>"}, NULL);
	tolua_beginmodule(L, "CMemINISection");
	tolua_endmodule(L);
	tolua_cclass(L, "CMoveList", "CMoveList", {"CTypedPtrList<CPtrList,CMoveListEntry*>"}, NULL);
	tolua_beginmodule(L, "CMoveList");
	tolua_endmodule(L);
	tolua_cclass(L, "CPersistantEffectList", "CPersistantEffectList", {"CTypedPtrList<CPtrList,CPersistantEffect*>"}, NULL);
	tolua_beginmodule(L, "CPersistantEffectList");
	tolua_endmodule(L);
	tolua_cclass(L, "CSpawnList", "CSpawnList", {"CTypedPtrList<CPtrList,CSpawn*>"}, NULL);
	tolua_beginmodule(L, "CSpawnList");
	tolua_endmodule(L);
	tolua_cclass(L, "CSpawnFile", "CSpawnFile", {"CTypedPtrList<CPtrList,void*>"}, NULL);
	tolua_beginmodule(L, "CSpawnFile");
	tolua_endmodule(L);
	tolua_cclass(L, "CSoundChannel", "CSoundChannel", {"CObject"}, NULL);
	tolua_beginmodule(L, "CSoundChannel");
	tolua_endmodule(L);
	tolua_cclass(L, "CSequenceSoundList", "CSequenceSoundList", {"CTypedPtrList<CPtrList,CSequenceSound*>"}, NULL);
	tolua_beginmodule(L, "CSequenceSoundList");
	tolua_endmodule(L);
	tolua_cclass(L, "CSelectiveWeaponTypeList", "CSelectiveWeaponTypeList", {"CTypedPtrList<CPtrList,CSelectiveWeaponType*>"}, NULL);
	tolua_beginmodule(L, "CSelectiveWeaponTypeList");
	tolua_endmodule(L);
	tolua_cclass(L, "CSelectiveBonusList", "CSelectiveBonusList", {"CTypedPtrList<CPtrList,CSelectiveBonus*>"}, NULL);
	tolua_beginmodule(L, "CSelectiveBonusList");
	tolua_endmodule(L);
	tolua_cclass(L, "CPtrArray", "CPtrArray", {"CObject"}, NULL);
	tolua_beginmodule(L, "CPtrArray");
	tolua_endmodule(L);
	tolua_cclass(L, "CGameDialogEntry", "CGameDialogEntry", {"CTypedPtrArray<CPtrArray,CGameDialogReply*>"}, NULL);
	tolua_beginmodule(L, "CGameDialogEntry");
	tolua_endmodule(L);
	tolua_cclass(L, "CGameAbilityList", "CGameAbilityList", {"CTypedPtrArray<CPtrArray,CAbilityData*>"}, NULL);
	tolua_beginmodule(L, "CGameAbilityList");
	tolua_endmodule(L);
	tolua_cclass(L, "CSpawnPointArray", "CSpawnPointArray", {"CTypedPtrArray<CPtrArray,CSpawnPoint*>"}, NULL);
	tolua_beginmodule(L, "CSpawnPointArray");
	tolua_endmodule(L);
	tolua_cclass(L, "CObList", "CObList", {"CObject"}, NULL);
	tolua_beginmodule(L, "CObList");
	tolua_endmodule(L);
	tolua_cclass(L, "CMessage", "CMessage", {}, NULL);
	tolua_beginmodule(L, "CMessage");
	tolua_endmodule(L);
	tolua_cclass(L, "CMessageUpdateReaction", "CMessageUpdateReaction", {"CMessage"}, NULL);
	tolua_beginmodule(L, "CMessageUpdateReaction");
	tolua_endmodule(L);
	tolua_cclass(L, "CMessageSetDirection", "CMessageSetDirection", {"CMessage"}, NULL);
	tolua_beginmodule(L, "CMessageSetDirection");
	tolua_endmodule(L);
	tolua_cclass(L, "CMessageDisplayTextRef", "CMessageDisplayTextRef", {"CMessage"}, NULL);
	tolua_beginmodule(L, "CMessageDisplayTextRef");
	tolua_endmodule(L);
	tolua_cclass(L, "CMessageDisplayText", "CMessageDisplayText", {"CMessage"}, NULL);
	tolua_beginmodule(L, "CMessageDisplayText");
	tolua_endmodule(L);
	tolua_cclass(L, "CMessageAddEffect", "CMessageAddEffect", {"CMessage"}, NULL);
	tolua_beginmodule(L, "CMessageAddEffect");
	tolua_endmodule(L);
	tolua_cclass(L, "CMessageAddClairvoyance", "CMessageAddClairvoyance", {"CMessage"}, NULL);
	tolua_beginmodule(L, "CMessageAddClairvoyance");
	tolua_endmodule(L);
	tolua_cclass(L, "CMemINIValue", "CMemINIValue", {}, NULL);
	tolua_beginmodule(L, "CMemINIValue");
	tolua_endmodule(L);
	tolua_cclass(L, "CGameEffectList", "CGameEffectList", {"CTypedPtrList<CPtrList,CGameEffect*>"}, NULL);
	tolua_beginmodule(L, "CGameEffectList");
	tolua_endmodule(L);
	tolua_cclass(L, "CFile", "CFile", {"CObject"}, NULL);
	tolua_beginmodule(L, "CFile");
	tolua_endmodule(L);
	tolua_cclass(L, "CContingencyList", "CContingencyList", {"CTypedPtrList<CPtrList,CContingency*>"}, NULL);
	tolua_beginmodule(L, "CContingencyList");
	tolua_endmodule(L);
	tolua_cclass(L, "CCallbackBase", "CCallbackBase", {}, NULL);
	tolua_beginmodule(L, "CCallbackBase");
	tolua_endmodule(L);
	tolua_cclass(L, "CCallResult<CSteam,CreateItemResult_t>", "CCallResult<CSteam,CreateItemResult_t>", {"CCallbackBase"}, NULL);
	tolua_beginmodule(L, "CCallResult<CSteam,CreateItemResult_t>");
	tolua_endmodule(L);
	tolua_cclass(L, "CCallResult<CSteam,SteamUGCQueryCompleted_t>", "CCallResult<CSteam,SteamUGCQueryCompleted_t>", {"CCallbackBase"}, NULL);
	tolua_beginmodule(L, "CCallResult<CSteam,SteamUGCQueryCompleted_t>");
	tolua_endmodule(L);
	tolua_cclass(L, "CCallResult<CSteam,SubmitItemUpdateResult_t>", "CCallResult<CSteam,SubmitItemUpdateResult_t>", {"CCallbackBase"}, NULL);
	tolua_beginmodule(L, "CCallResult<CSteam,SubmitItemUpdateResult_t>");
	tolua_endmodule(L);
	tolua_cclass(L, "CCallResult<CSteam,SteamUGCRequestUGCDetailsResult_t>", "CCallResult<CSteam,SteamUGCRequestUGCDetailsResult_t>", {"CCallbackBase"}, NULL);
	tolua_beginmodule(L, "CCallResult<CSteam,SteamUGCRequestUGCDetailsResult_t>");
	tolua_endmodule(L);
	tolua_cclass(L, "EEex_CBaldurEngine", "EEex_CBaldurEngine", {"EEex_CWarp"}, NULL);
	tolua_beginmodule(L, "EEex_CBaldurEngine");
	tolua_endmodule(L);
	tolua_cclass(L, "CDungeonMaster", "CDungeonMaster", {"EEex_CBaldurEngine"}, NULL);
	tolua_beginmodule(L, "CDungeonMaster");
	tolua_endmodule(L);
	tolua_cclass(L, "uiItem", "uiItem", {}, NULL);
	tolua_beginmodule(L, "uiItem");
	tolua_endmodule(L);
	tolua_cclass(L, "CResBinary", "CResBinary", {"CRes"}, NULL);
	tolua_beginmodule(L, "CResBinary");
	tolua_endmodule(L);
	tolua_cclass(L, "CSteam", "CSteam", {}, NULL);
	tolua_beginmodule(L, "CSteam");
	tolua_endmodule(L);
	tolua_cclass(L, "EEex_CScreenMovies", "EEex_CScreenMovies", {"EEex_CBaldurEngine"}, NULL);
	tolua_beginmodule(L, "EEex_CScreenMovies");
	tolua_endmodule(L);
	tolua_cclass(L, "EEex_CScreenConnection", "EEex_CScreenConnection", {"EEex_CBaldurEngine"}, NULL);
	tolua_beginmodule(L, "EEex_CScreenConnection");
	tolua_endmodule(L);
	tolua_cclass(L, "CAIIdList", "CAIIdList", {"CResHelper<CResText,1008>"}, NULL);
	tolua_beginmodule(L, "CAIIdList");
	tolua_endmodule(L);
	tolua_cclass(L, "CSound", "CSound", {"CObject","CResHelper<CResWave,4>"}, NULL);
	tolua_beginmodule(L, "CSound");
	tolua_endmodule(L);
	tolua_cclass(L, "CSoundImp", "CSoundImp", {"CObject","CResHelper<CResWave,4>"}, NULL);
	tolua_beginmodule(L, "CSoundImp");
	tolua_endmodule(L);
	tolua_cclass(L, "CScreenAI", "CScreenAI", {"EEex_CBaldurEngine"}, NULL);
	tolua_beginmodule(L, "CScreenAI");
	tolua_endmodule(L);
	tolua_cclass(L, "CVidCell", "CVidCell", {"CVidImage","CResHelper<CResCell,1000>"}, NULL);
	tolua_beginmodule(L, "CVidCell");
	tolua_endmodule(L);
	tolua_cclass(L, "CVidCellFont", "CVidCellFont", {"CVidCell"}, NULL);
	tolua_beginmodule(L, "CVidCellFont");
	tolua_endmodule(L);
	tolua_cclass(L, "EEex_CScreenCreateChar", "EEex_CScreenCreateChar", {"EEex_CBaldurEngine"}, NULL);
	tolua_beginmodule(L, "EEex_CScreenCreateChar");
	tolua_endmodule(L);
	tolua_cclass(L, "EEex_CScreenCreateParty", "EEex_CScreenCreateParty", {"EEex_CBaldurEngine"}, NULL);
	tolua_beginmodule(L, "EEex_CScreenCreateParty");
	tolua_endmodule(L);
	tolua_cclass(L, "EEex_CScreenDLC", "EEex_CScreenDLC", {"EEex_CBaldurEngine"}, NULL);
	tolua_beginmodule(L, "EEex_CScreenDLC");
	tolua_endmodule(L);
	tolua_cclass(L, "EEex_CScreenLoad", "EEex_CScreenLoad", {"EEex_CBaldurEngine"}, NULL);
	tolua_beginmodule(L, "EEex_CScreenLoad");
	tolua_endmodule(L);
	tolua_cclass(L, "EEex_CScreenMap", "EEex_CScreenMap", {"EEex_CBaldurEngine"}, NULL);
	tolua_beginmodule(L, "EEex_CScreenMap");
	tolua_endmodule(L);
	tolua_cclass(L, "EEex_CScreenMultiPlayer", "EEex_CScreenMultiPlayer", {"EEex_CBaldurEngine"}, NULL);
	tolua_beginmodule(L, "EEex_CScreenMultiPlayer");
	tolua_endmodule(L);
	tolua_cclass(L, "EEex_CScreenOptions", "EEex_CScreenOptions", {"EEex_CBaldurEngine"}, NULL);
	tolua_beginmodule(L, "EEex_CScreenOptions");
	tolua_endmodule(L);
	tolua_cclass(L, "EEex_CScreenSave", "EEex_CScreenSave", {"EEex_CBaldurEngine"}, NULL);
	tolua_beginmodule(L, "EEex_CScreenSave");
	tolua_endmodule(L);
	tolua_cclass(L, "EEex_CScreenStart", "EEex_CScreenStart", {"EEex_CBaldurEngine"}, NULL);
	tolua_beginmodule(L, "EEex_CScreenStart");
	tolua_endmodule(L);
	tolua_cclass(L, "EEex_CInfToolTip", "EEex_CInfToolTip", {"CVidCell"}, NULL);
	tolua_beginmodule(L, "EEex_CInfToolTip");
	tolua_endmodule(L);
	tolua_cclass(L, "CGameStatsRes", "CGameStatsRes", {"CObject"}, NULL);
	tolua_beginmodule(L, "CGameStatsRes");
	tolua_endmodule(L);
	tolua_cclass(L, "EEex_CScreenWorldMap", "EEex_CScreenWorldMap", {"EEex_CBaldurEngine"}, NULL);
	tolua_beginmodule(L, "EEex_CScreenWorldMap");
	tolua_endmodule(L);
	tolua_cclass(L, "EEex_CScreenWorld", "EEex_CScreenWorld", {"EEex_CBaldurEngine"}, NULL);
	tolua_beginmodule(L, "EEex_CScreenWorld");
	tolua_endmodule(L);
	tolua_cclass(L, "EEex_CScreenWizSpell", "EEex_CScreenWizSpell", {"EEex_CBaldurEngine"}, NULL);
	tolua_beginmodule(L, "EEex_CScreenWizSpell");
	tolua_endmodule(L);
	tolua_cclass(L, "EEex_CScreenPriestSpell", "EEex_CScreenPriestSpell", {"EEex_CBaldurEngine"}, NULL);
	tolua_beginmodule(L, "EEex_CScreenPriestSpell");
	tolua_endmodule(L);
	tolua_cclass(L, "EEex_CScreenJournal", "EEex_CScreenJournal", {"EEex_CBaldurEngine"}, NULL);
	tolua_beginmodule(L, "EEex_CScreenJournal");
	tolua_endmodule(L);
	tolua_cclass(L, "EEex_CScreenInventory", "EEex_CScreenInventory", {"EEex_CBaldurEngine"}, NULL);
	tolua_beginmodule(L, "EEex_CScreenInventory");
	tolua_endmodule(L);
	tolua_cclass(L, "EEex_CScreenCharacter", "EEex_CScreenCharacter", {"EEex_CBaldurEngine"}, NULL);
	tolua_beginmodule(L, "EEex_CScreenCharacter");
	tolua_endmodule(L);
	tolua_cclass(L, "EEex_CScreenChapter", "EEex_CScreenChapter", {"EEex_CBaldurEngine"}, NULL);
	tolua_beginmodule(L, "EEex_CScreenChapter");
	tolua_endmodule(L);
	tolua_cclass(L, "EEex_CChitin", "EEex_CChitin", {}, NULL);
	tolua_beginmodule(L, "EEex_CChitin");
	tolua_endmodule(L);
	tolua_cclass(L, "CItem", "CItem", {"CResHelper<CResItem,1005>"}, NULL);
	tolua_beginmodule(L, "CItem");
	tolua_endmodule(L);
	tolua_cclass(L, "CGameEffect", "CGameEffect", {"CGameEffectBase"}, NULL);
	tolua_beginmodule(L, "CGameEffect");
	tolua_endmodule(L);
	tolua_cclass(L, "CGameEffectDamage", "CGameEffectDamage", {"CGameEffect"}, NULL);
	tolua_beginmodule(L, "CGameEffectDamage");
	tolua_endmodule(L);
	tolua_cclass(L, "CGameEffectUsability", "CGameEffectUsability", {"CGameEffect"}, NULL);
	tolua_beginmodule(L, "CGameEffectUsability");
	tolua_endmodule(L);
	tolua_cclass(L, "CGameAnimationType", "CGameAnimationType", {}, NULL);
	tolua_beginmodule(L, "CGameAnimationType");
	tolua_endmodule(L);
	tolua_cclass(L, "EEex_CBaldurProjector", "EEex_CBaldurProjector", {"EEex_CBaldurEngine"}, NULL);
	tolua_beginmodule(L, "EEex_CBaldurProjector");
	tolua_endmodule(L);
	tolua_cclass(L, "EEex_CBaldurChitin", "EEex_CBaldurChitin", {"EEex_CChitin"}, NULL);
	tolua_beginmodule(L, "EEex_CBaldurChitin");
	tolua_endmodule(L);
	tolua_cclass(L, "CGameArea", "CGameArea", {}, NULL);
	tolua_beginmodule(L, "CGameArea");
	tolua_endmodule(L);
	tolua_cclass(L, "CSpawn", "CSpawn", {}, NULL);
	tolua_beginmodule(L, "CSpawn");
	tolua_endmodule(L);
	tolua_cclass(L, "EEex_CScreenStore", "EEex_CScreenStore", {"EEex_CBaldurEngine"}, NULL);
	tolua_beginmodule(L, "EEex_CScreenStore");
	tolua_endmodule(L);
	tolua_cclass(L, "CMessageSetLastObject", "CMessageSetLastObject", {"CMessage"}, NULL);
	tolua_beginmodule(L, "CMessageSetLastObject");
	tolua_endmodule(L);
	tolua_cclass(L, "CGameObject", "CGameObject", {}, NULL);
	tolua_beginmodule(L, "CGameObject");
	tolua_endmodule(L);
	tolua_cclass(L, "CGameFireball3d", "CGameFireball3d", {"CGameObject"}, NULL);
	tolua_beginmodule(L, "CGameFireball3d");
	tolua_endmodule(L);
	tolua_cclass(L, "CVisualEffect", "CVisualEffect", {"CGameObject","CVisualEffectBase"}, NULL);
	tolua_beginmodule(L, "CVisualEffect");
	tolua_endmodule(L);
	tolua_cclass(L, "CProjectile", "CProjectile", {"CGameObject"}, NULL);
	tolua_beginmodule(L, "CProjectile");
	tolua_endmodule(L);
	tolua_cclass(L, "CProjectileTravelDoor", "CProjectileTravelDoor", {"CProjectile"}, NULL);
	tolua_beginmodule(L, "CProjectileTravelDoor");
	tolua_endmodule(L);
	tolua_cclass(L, "CProjectileSpellHit", "CProjectileSpellHit", {"CProjectile"}, NULL);
	tolua_beginmodule(L, "CProjectileSpellHit");
	tolua_endmodule(L);
	tolua_cclass(L, "CProjectileAmbiant", "CProjectileAmbiant", {"CProjectileSpellHit"}, NULL);
	tolua_beginmodule(L, "CProjectileAmbiant");
	tolua_endmodule(L);
	tolua_cclass(L, "CProjectileSkyStrike", "CProjectileSkyStrike", {"CProjectile"}, NULL);
	tolua_beginmodule(L, "CProjectileSkyStrike");
	tolua_endmodule(L);
	tolua_cclass(L, "CProjectileInstant", "CProjectileInstant", {"CProjectile"}, NULL);
	tolua_beginmodule(L, "CProjectileInstant");
	tolua_endmodule(L);
	tolua_cclass(L, "CProjectileCallLightning", "CProjectileCallLightning", {"CProjectileInstant"}, NULL);
	tolua_beginmodule(L, "CProjectileCallLightning");
	tolua_endmodule(L);
	tolua_cclass(L, "CProjectileCastingGlow", "CProjectileCastingGlow", {"CProjectile"}, NULL);
	tolua_beginmodule(L, "CProjectileCastingGlow");
	tolua_endmodule(L);
	tolua_cclass(L, "CProjectileBAM", "CProjectileBAM", {"CProjectile"}, NULL);
	tolua_beginmodule(L, "CProjectileBAM");
	tolua_endmodule(L);
	tolua_cclass(L, "CProjectileArea", "CProjectileArea", {"CProjectileBAM"}, NULL);
	tolua_beginmodule(L, "CProjectileArea");
	tolua_endmodule(L);
	tolua_cclass(L, "CProjectileSkyStrikeBAM", "CProjectileSkyStrikeBAM", {"CProjectileBAM"}, NULL);
	tolua_beginmodule(L, "CProjectileSkyStrikeBAM");
	tolua_endmodule(L);
	tolua_cclass(L, "CProjectileSegment", "CProjectileSegment", {"CProjectileBAM"}, NULL);
	tolua_beginmodule(L, "CProjectileSegment");
	tolua_endmodule(L);
	tolua_cclass(L, "CProjectileScorcher", "CProjectileScorcher", {"CProjectileBAM"}, NULL);
	tolua_beginmodule(L, "CProjectileScorcher");
	tolua_endmodule(L);
	tolua_cclass(L, "CProjectileNewScorcher", "CProjectileNewScorcher", {"CProjectileBAM"}, NULL);
	tolua_beginmodule(L, "CProjectileNewScorcher");
	tolua_endmodule(L);
	tolua_cclass(L, "CProjectileMushroom", "CProjectileMushroom", {"CProjectileBAM"}, NULL);
	tolua_beginmodule(L, "CProjectileMushroom");
	tolua_endmodule(L);
	tolua_cclass(L, "CProjectileMulti", "CProjectileMulti", {"CProjectileBAM"}, NULL);
	tolua_beginmodule(L, "CProjectileMulti");
	tolua_endmodule(L);
	tolua_cclass(L, "CProjectileMagicMissileMulti", "CProjectileMagicMissileMulti", {"CProjectileMulti"}, NULL);
	tolua_beginmodule(L, "CProjectileMagicMissileMulti");
	tolua_endmodule(L);
	tolua_cclass(L, "CProjectileLightningBounce", "CProjectileLightningBounce", {"CProjectileBAM"}, NULL);
	tolua_beginmodule(L, "CProjectileLightningBounce");
	tolua_endmodule(L);
	tolua_cclass(L, "CProjectileLightningBoltGround", "CProjectileLightningBoltGround", {"CProjectileBAM"}, NULL);
	tolua_beginmodule(L, "CProjectileLightningBoltGround");
	tolua_endmodule(L);
	tolua_cclass(L, "CProjectileLightningBolt", "CProjectileLightningBolt", {"CProjectileBAM"}, NULL);
	tolua_beginmodule(L, "CProjectileLightningBolt");
	tolua_endmodule(L);
	tolua_cclass(L, "CProjectileInvisibleTravelling", "CProjectileInvisibleTravelling", {"CProjectileBAM"}, NULL);
	tolua_beginmodule(L, "CProjectileInvisibleTravelling");
	tolua_endmodule(L);
	tolua_cclass(L, "CProjectileFireHands", "CProjectileFireHands", {"CProjectileBAM"}, NULL);
	tolua_beginmodule(L, "CProjectileFireHands");
	tolua_endmodule(L);
	tolua_cclass(L, "CProjectileFall", "CProjectileFall", {"CProjectileBAM"}, NULL);
	tolua_beginmodule(L, "CProjectileFall");
	tolua_endmodule(L);
	tolua_cclass(L, "CProjectileConeOfCold", "CProjectileConeOfCold", {"CProjectileBAM"}, NULL);
	tolua_beginmodule(L, "CProjectileConeOfCold");
	tolua_endmodule(L);
	tolua_cclass(L, "CProjectileColorSpray", "CProjectileColorSpray", {"CProjectileBAM"}, NULL);
	tolua_beginmodule(L, "CProjectileColorSpray");
	tolua_endmodule(L);
	tolua_cclass(L, "CProjectileChain", "CProjectileChain", {"CProjectileBAM"}, NULL);
	tolua_beginmodule(L, "CProjectileChain");
	tolua_endmodule(L);
	tolua_cclass(L, "CProjectileLightningStorm", "CProjectileLightningStorm", {"CProjectileChain"}, NULL);
	tolua_beginmodule(L, "CProjectileLightningStorm");
	tolua_endmodule(L);
	tolua_cclass(L, "CObjectMarker", "CObjectMarker", {"CGameObject"}, NULL);
	tolua_beginmodule(L, "CObjectMarker");
	tolua_endmodule(L);
	tolua_cclass(L, "CGameTemporal", "CGameTemporal", {"CGameObject"}, NULL);
	tolua_beginmodule(L, "CGameTemporal");
	tolua_endmodule(L);
	tolua_cclass(L, "CGameStatic", "CGameStatic", {"CGameObject"}, NULL);
	tolua_beginmodule(L, "CGameStatic");
	tolua_endmodule(L);
	tolua_cclass(L, "CGameSpawning", "CGameSpawning", {"CGameObject"}, NULL);
	tolua_beginmodule(L, "CGameSpawning");
	tolua_endmodule(L);
	tolua_cclass(L, "CGameSound", "CGameSound", {"CGameObject"}, NULL);
	tolua_beginmodule(L, "CGameSound");
	tolua_endmodule(L);
	tolua_cclass(L, "CMessageSetTrigger", "CMessageSetTrigger", {"CMessage"}, NULL);
	tolua_beginmodule(L, "CMessageSetTrigger");
	tolua_endmodule(L);
	tolua_cclass(L, "CGameAIBase", "CGameAIBase", {"CGameObject"}, NULL);
	tolua_beginmodule(L, "CGameAIBase");
	tolua_endmodule(L);
	tolua_cclass(L, "CGameTrigger", "CGameTrigger", {"CGameAIBase"}, NULL);
	tolua_beginmodule(L, "CGameTrigger");
	tolua_endmodule(L);
	tolua_cclass(L, "CGameTiledObject", "CGameTiledObject", {"CGameAIBase"}, NULL);
	tolua_beginmodule(L, "CGameTiledObject");
	tolua_endmodule(L);
	tolua_cclass(L, "CGameSprite", "CGameSprite", {"CGameAIBase"}, NULL);
	tolua_beginmodule(L, "CGameSprite");
		tolua_function(L, "getUUID", &tolua_function_CGameSprite_getUUID);
	tolua_endmodule(L);
	tolua_cclass(L, "CGameDoor", "CGameDoor", {"CGameAIBase"}, NULL);
	tolua_beginmodule(L, "CGameDoor");
	tolua_endmodule(L);
	tolua_cclass(L, "CGameContainer", "CGameContainer", {"CGameAIBase"}, NULL);
	tolua_beginmodule(L, "CGameContainer");
	tolua_endmodule(L);
	tolua_cclass(L, "CGameAIGame", "CGameAIGame", {"CGameAIBase"}, NULL);
	tolua_beginmodule(L, "CGameAIGame");
	tolua_endmodule(L);
	tolua_cclass(L, "CGameAIArea", "CGameAIArea", {"CGameAIBase"}, NULL);
	tolua_beginmodule(L, "CGameAIArea");
	tolua_endmodule(L);
	tolua_endmodule(L);
	return 1;
}
