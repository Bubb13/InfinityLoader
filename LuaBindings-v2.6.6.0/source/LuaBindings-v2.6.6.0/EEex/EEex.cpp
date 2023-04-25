
#include "Baldur-v2.6.6.0_generated.h"
#include "util.hpp"
#include <functional>

long long currentMicroseconds() {
	return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

bool topLevel = true;

void exitStutterLog(const char *const name, long long timeTaken) {

	lua_State *const L = *p_g_lua;
	p_lua_getglobal(L, "EEex_StutterDetector_Private_Times");            // 1 [ ..., EEex_StutterDetector_Private_Times ]

	p_lua_pushstring(L, name);                                           // 2 [ ..., EEex_StutterDetector_Private_Times, name ]
	p_lua_rawget(L, -2);                                                 // 2 [ ..., EEex_StutterDetector_Private_Times, EEex_StutterDetector_Private_Times[name] -> timeEntry ]

	if (!p_lua_isnil(L, -1)) {

		p_lua_rawgeti(L, -1, 1);                                         // 3 [ ..., EEex_StutterDetector_Private_Times, timeEntry, timeEntry[1] -> count ]
		const lua_Integer count = p_lua_tointeger(L, -1);
		p_lua_pop(L, 1);                                                 // 2 [ ..., EEex_StutterDetector_Private_Times, timeEntry ]
		p_lua_pushinteger(L, count + 1);                                 // 3 [ ..., EEex_StutterDetector_Private_Times, timeEntry, newCount ]
		p_lua_rawseti(L, -2, 1);                                         // 2 [ ..., EEex_StutterDetector_Private_Times, timeEntry ]

		p_lua_rawgeti(L, -1, 2);                                         // 3 [ ..., EEex_StutterDetector_Private_Times, timeEntry, timeEntry[1] -> totalTimeTaken ]
		const lua_Integer totalTimeTaken = p_lua_tointeger(L, -1);
		p_lua_pop(L, 1);                                                 // 2 [ ..., EEex_StutterDetector_Private_Times, timeEntry ]
		p_lua_pushinteger(L, totalTimeTaken + timeTaken);                // 3 [ ..., EEex_StutterDetector_Private_Times, timeEntry, newTotalTimeTaken ]
		p_lua_rawseti(L, -2, 2);                                         // 2 [ ..., EEex_StutterDetector_Private_Times, timeEntry ]

		p_lua_pop(L, 2);                                                 // 0 [ ... ]
	}
	else {

		p_lua_pop(L, 1);                                                 // 1 [ ..., EEex_StutterDetector_Private_Times ]
		p_lua_pushstring(L, name);                                       // 2 [ ..., EEex_StutterDetector_Private_Times, name ]
		p_lua_newtable(L);                                               // 3 [ ..., EEex_StutterDetector_Private_Times, name, {} -> timeEntry ]

		p_lua_pushinteger(L, 1);                                         // 4 [ ..., EEex_StutterDetector_Private_Times, name, timeEntry, 1 ]
		p_lua_rawseti(L, -2, 1);                                         // 3 [ ..., EEex_StutterDetector_Private_Times, name, timeEntry ]

		p_lua_pushinteger(L, timeTaken);                                 // 4 [ ..., EEex_StutterDetector_Private_Times, name, timeEntry, timeTaken ]
		p_lua_rawseti(L, -2, 2);                                         // 3 [ ..., EEex_StutterDetector_Private_Times, name, timeEntry ]

		p_lua_rawset(L, -3);                                             // 1 [ ..., EEex_StutterDetector_Private_Times ]

		p_lua_pop(L, 1);                                                 // 0 [ ... ]
	}

	if (topLevel) {

		p_lua_getglobal(L, "EEex_StutterDetector_Private_TopLevelTime"); // 1 [ ..., EEex_StutterDetector_Private_TopLevelTime ]
		const lua_Integer topLevelTime = p_lua_tointeger(L, -1);
		p_lua_pop(L, 1);                                                 // 0 [ ... ]
		p_lua_pushinteger(L, topLevelTime + timeTaken);                  // 1 [ ..., newTopLevelTime ]
		p_lua_setglobal(L, "EEex_StutterDetector_Private_TopLevelTime"); // 0 [ ... ]
	}
}

template<typename RetType>
RetType logStutter(const char* name, std::function<RetType()> func) {
	bool oldTopLevel = topLevel;
	topLevel = false;
	long long startTime = currentMicroseconds();
	RetType ret = func();
	long long timeTaken = currentMicroseconds() - startTime;
	topLevel = oldTopLevel;
	exitStutterLog(name, timeTaken);
	return ret;
}

template<>
void logStutter<void>(const char* name, std::function<void()> func) {
	bool oldTopLevel = topLevel;
	topLevel = false;
	long long startTime = currentMicroseconds();
	func();
	long long timeTaken = currentMicroseconds() - startTime;
	topLevel = oldTopLevel;
	exitStutterLog(name, timeTaken);
}

__forceinline int operator&(EEex_MatchObjectFlags a, EEex_MatchObjectFlags b)
{
	return static_cast<__int32>(a) & static_cast<__int32>(b);
}

enum class EEex_CheckShortCircuitDirection
{
	BACKWARD = 0,
	FORWARD = 1,
	IMPOSSIBLE = 2,
};

void EEex_PushGameObjectUserData(lua_State *const L, CGameObject *const pObject)
{
	const char* pUserTypeName;
	switch (pObject->m_objectType)
	{
		default:
		case CGameObjectType::NONE:          pUserTypeName = nullptr;            break;
		case CGameObjectType::AIBASE:        pUserTypeName = "CGameAIBase";      break;
		case CGameObjectType::SOUND:         pUserTypeName = "CGameSound";       break;
		case CGameObjectType::CONTAINER:     pUserTypeName = "CGameContainer";   break;
		case CGameObjectType::SPAWNING:      pUserTypeName = "CGameSpawning";    break;
		case CGameObjectType::DOOR:          pUserTypeName = "CGameDoor";        break;
		case CGameObjectType::STATIC:        pUserTypeName = "CGameStatic";      break;
		case CGameObjectType::SPRITE:        pUserTypeName = "CGameSprite";      break;
		case CGameObjectType::OBJECT_MARKER: pUserTypeName = "CObjectMarker";    break;
		case CGameObjectType::TRIGGER:       pUserTypeName = "CGameTrigger";     break;
		case CGameObjectType::TILED_OBJECT:  pUserTypeName = "CGameTiledObject"; break;
		case CGameObjectType::TEMPORAL:      pUserTypeName = "CGameTemporal";    break;
		case CGameObjectType::AREA_AI:       pUserTypeName = "CGameAIArea";      break;
		case CGameObjectType::FIREBALL:      pUserTypeName = "CGameFireball3d";  break;
		case CGameObjectType::GAME_AI:       pUserTypeName = "CGameAIGame";      break;
	}
	tolua_pushusertype_nocast(L, pObject, pUserTypeName);
}

// 3 [ ..., matchFunc, debug, traceback ]
bool EEex_RunMatchFunction(lua_State *const L, CGameObject *const pObject)
{
	p_lua_pushvalue(L, -3);                                                          // 4 [ ..., matchFunc, debug, traceback, matchFunc ]
	EEex_PushGameObjectUserData(L, pObject);                                         // 5 [ ..., matchFunc, debug, traceback, matchFunc, pObject ]
	p_lua_setglobal(L, "EEex_MatchObject");                                          // 4 [ ..., matchFunc, debug, traceback, matchFunc ]

    if (p_lua_pcallk(L, 0, 1, -2, 0, nullptr) != LUA_OK)
	{
                                                                                     // 4 [ ..., matchFunc, debug, traceback, error ]
        Print("[!] [EEex_MatchObject] Runtime error: %s\n", p_lua_tostring(L, -1));
        p_lua_pop(L, 1);                                                             // 3 [ ..., matchFunc, debug, traceback ]
		return false;
    }
	                                                                                 // 4 [ ..., matchFunc, debug, traceback, result ]
	const bool toReturn { static_cast<bool>(p_lua_toboolean(L, -1)) };
    p_lua_pop(L, 1);                                                                 // 3 [ ..., matchFunc, debug, traceback ]
	return toReturn;
}

bool EEex_CheckMatch(lua_State* L,
	// Loop data
	const EEex_CheckShortCircuitDirection shortCircuitDirection,
	long *const idArray, int *const distanceArray, const short nArray,
	// Area data
	CGameArea& area, const byte *const terrainTable,
	// Checking object
	const long objectID,
	// Caller data
	const CAIObjectType& callerType, const CPoint& callerPos, const CPoint& callerPosAdj,
	// Restrictions
	const bool bNearest, const short range, const int rangeSquared, const bool bCheckLOS,
	const bool bIgnoreNonSprites, const bool bIgnoreInvisible, const bool bIgnoreSleeping, const bool bIgnoreDead)
{
	CGameObject* object;
	if (CGameObjectArray::GetShare(objectID, &object) != 0) {
		return false;
	}

	const CGameObjectType objectType { object->virtual_GetObjectType() };

	if ((bIgnoreNonSprites && objectType != CGameObjectType::SPRITE) || !isAIBase(objectType)) {
		return false;
	}

	const CPoint& objectPos { object->m_pos };
	const CPoint objectPosAdj { objectPos.x, objectPos.y * 4/3 };

	const int yDiff { objectPosAdj.y - callerPosAdj.y };
	const int distanceSquared { square(objectPosAdj.x - callerPosAdj.x) + square(yDiff) };

	if (range != -1)
	{
		// Short-circuit loop based on the sorted nature of m_lVertSort*
		if (shortCircuitDirection == EEex_CheckShortCircuitDirection::BACKWARD)
		{
			if (yDiff < 0)
			{
				if (-yDiff > range) {
					return true;
				}
			}
			else if (yDiff > range) {
				return false;
			}
		}
		else if (shortCircuitDirection == EEex_CheckShortCircuitDirection::FORWARD)
		{
			if (yDiff >= 0)
			{
				if (yDiff > range) {
					return true;
				}
			}
			else if (-yDiff > range) {
				return false;
			}
		}

		if (distanceSquared > rangeSquared) {
			return false;
		}
	}

	if (objectType == CGameObjectType::SPRITE)
	{
		CGameSprite& sprite { *reinterpret_cast<CGameSprite*>(object) };
		CDerivedStats& stats { *sprite.GetActiveStats() };
		const uint generalState { stats.m_generalState };

		if (!sprite.m_active || !sprite.m_activeAI || !sprite.m_activeImprisonment
			|| (bIgnoreInvisible && ((generalState & 0x10) != 0 || stats.m_bSanctuary))
			|| (bIgnoreSleeping && (generalState & 1) != 0)
			|| (bIgnoreDead && (generalState & 0x800) != 0)
			|| !sprite.m_animation.m_animation->virtual_GetAboveGround()
			|| stats.m_cImmunitiesAIType.OnList(&callerType))
		{
			return false;
		}
	}

	if ((bCheckLOS && !area.CheckLOS(&callerPos, &objectPos, terrainTable, 0, range)) ||
		!EEex_RunMatchFunction(L, object))
	{
		return false;
	}

	for (short i { 0 }; i <= nArray; ++i)
	{
		if (bNearest)
		{
			if (distanceSquared >= distanceArray[i]) {
				continue;
			}
		}
		else if (distanceSquared <= distanceArray[i]) {
			continue;
		}

		const short slotsAfter { nArray - i };
		memmove(&idArray[i + 1], &idArray[i], sizeof(long) * slotsAfter);
		memmove(&distanceArray[i + 1], &distanceArray[i], sizeof(int) * slotsAfter);
		idArray[i] = object->m_id;
		distanceArray[i] = distanceSquared;
		return false;
	}

	return false;
}

long EEex::MatchObject(lua_State *const L, CGameObject *const pStartObject, const char *const matchChunk,
	const int nth, int range, const EEex_MatchObjectFlags flags)
{
	return logStutter<long>("EEex::MatchObject", [&]() -> long {

		if (pStartObject == nullptr || !isAIBase(pStartObject->virtual_GetObjectType())) {
			return -1;
		}

		CGameAIBase *const pStartAIBase { reinterpret_cast<CGameSprite*>(pStartObject) };
		CGameArea *const pArea { pStartAIBase->m_pArea };

		if (pArea == nullptr) {
			return -1;
		}

		const CTypedPtrList<CPtrList,long>::CNode *const pVertListPos { pStartAIBase->virtual_GetVertListPos() };

		if (pVertListPos == nullptr) {
			return -1;
		}

		if (nth < 0 || nth >= MAXBYTE)
		{
			Print("[!] [EEex_MatchObject] nth %d invalid, must be [0-255]!\n", nth);
			return -1;
		}

		int rangeSquared;
		bool bCheckLOS { (flags & EEex_MatchObjectFlags::IGNORE_LOS) == 0 };

		if (range == 0)
		{
			range = pStartAIBase->virtual_GetVisualRange();
			rangeSquared = square(range);
		}
		else if (range < 0)
		{
			if (range == -1) {
				bCheckLOS = false;
			}
			else
			{
				Print("[!] [EEex_MatchObject] range %d invalid, use -1 to ignore!\n", range);
				return -1;
			}
		}
		else if (range <= static_cast<int>(sqrt(INT_MAX)))
		{
			if (bCheckLOS)
			{
				if (const short callerVisualRange { pStartAIBase->virtual_GetVisualRange() };
					callerVisualRange < range)
				{
					range = callerVisualRange;
				}
			}
			rangeSquared = square(range);
		}
		else
		{
			Print("[!] [EEex_MatchObject] range %d too large, use -1 to ignore!\n", range);
			return -1;
		}

		if (p_luaL_loadstring(L, matchChunk) != LUA_OK)
		{                                                                                // 1 [ ..., error ]
			Print("[!] [EEex_MatchObject] Compile error: %s\n", p_lua_tostring(L, -1));
			p_lua_pop(L, 1);                                                             // 0 [ ... ]
			return -1;
		}
		                                                                                 // 1 [ ..., matchFunc ]
		p_lua_getglobal(L, "debug");                                                     // 2 [ ..., matchFunc, debug ]
		p_lua_getfield(L, -1, "traceback");                                              // 3 [ ..., matchFunc, debug, traceback ]

		const short arraySize { static_cast<short>(nth) + 1 };
		long *const idArray { reinterpret_cast<long*>(alloca(sizeof(long) * arraySize + sizeof(int) * arraySize)) };
		int *const distanceArray { reinterpret_cast<int*>(idArray + arraySize) };

		const int distanceArrayDefault { (flags & EEex_MatchObjectFlags::FARTHEST) == 0
			? INT_MAX
			: INT_MIN };

		for (short i { 0 }; i <= nth; ++i)
		{
			idArray[i] = -1;
			distanceArray[i] = distanceArrayDefault;
		}

		const byte* pTerrainTable { pStartAIBase->virtual_GetTerrainTable() };

		const CAIObjectType& callerType { *pStartAIBase->virtual_GetAIType() };
		const CPoint& callerPos { pStartAIBase->m_pos };
		const CPoint callerPosAdj { callerPos.x, callerPos.y * 4/3 };

		const bool bNearest { (flags & EEex_MatchObjectFlags::FARTHEST) == 0 };
		const bool bIgnoreNonSprites { (flags & EEex_MatchObjectFlags::MATCH_NON_SPRITES) == 0 };
		const bool bIgnoreInvisible {
			(flags & EEex_MatchObjectFlags::IGNORE_INVISIBLE) != 0 ||
			((flags & EEex_MatchObjectFlags::MATCH_INVISIBLE) == 0 && !pStartAIBase->virtual_GetCanSeeInvisible())
		};
		const bool bIgnoreSleeping { (flags & EEex_MatchObjectFlags::MATCH_SLEEPING) == 0 };
		const bool bIgnoreDead { (flags & EEex_MatchObjectFlags::MATCH_DEAD) == 0 };

		#define check(nodeName, stepName, directionName) \
			while (nodeName != nullptr) \
			{ \
				if (EEex_CheckMatch(L, \
					/* Loop data */ \
					directionName, idArray, distanceArray, nth, \
					/* Area data */ \
					*pArea, pTerrainTable, \
					/* Checking object */ \
					nodeName->data, \
					/* Caller data */ \
					callerType, callerPos, callerPosAdj, \
					/* Restrictions */ \
					bNearest, range, rangeSquared, bCheckLOS, \
					bIgnoreNonSprites, bIgnoreInvisible, bIgnoreSleeping, bIgnoreDead)) \
				{ \
					break; \
				} \
				else { \
					nodeName = nodeName->stepName; \
				} \
			}

		if ((flags & EEex_MatchObjectFlags::MATCH_ONLY_BACKLIST) == 0)
		{
			const VertListType vertListType { pStartAIBase->virtual_GetVertListType() };
			if (vertListType == VertListType::LIST_FRONT)
			{
				CTypedPtrList<CPtrList,long>::CNode* pNode { pVertListPos->pPrev };
				check(pNode, pPrev, EEex_CheckShortCircuitDirection::BACKWARD);

				pNode = pVertListPos->pNext;
				check(pNode, pNext, EEex_CheckShortCircuitDirection::FORWARD);
			}
			else
			{
				CTypedPtrList<CPtrList,long>::CNode* pNextNode { pArea->m_lVertSort.m_pNodeHead };
				check(pNextNode, pNext, EEex_CheckShortCircuitDirection::FORWARD);
			}
		}

		long toReturn;

		if ((flags & EEex_MatchObjectFlags::MATCH_DEAD) != 0
			|| (flags & EEex_MatchObjectFlags::MATCH_BACKLIST) != 0
			|| (flags & EEex_MatchObjectFlags::PRIORITIZE_BACKLIST) != 0
			|| (flags & EEex_MatchObjectFlags::MATCH_ONLY_BACKLIST) != 0)
		{
			if ((flags & EEex_MatchObjectFlags::PRIORITIZE_BACKLIST) != 0
				|| (flags & EEex_MatchObjectFlags::MATCH_ONLY_BACKLIST) != 0)
			{
				CTypedPtrList<CPtrList,long>::CNode* pNextNode { pArea->m_lVertSortBack.m_pNodeHead };
				check(pNextNode, pNext, EEex_CheckShortCircuitDirection::IMPOSSIBLE);
				toReturn = idArray[nth];
			}
			else if (toReturn = idArray[nth]; toReturn == -1)
			{
				for (short i { 0 }; i <= nth; ++i)
				{
					idArray[i] = -1;
					distanceArray[i] = distanceArrayDefault;
				}

				CTypedPtrList<CPtrList,long>::CNode* pNextNode { pArea->m_lVertSortBack.m_pNodeHead };
				check(pNextNode, pNext, EEex_CheckShortCircuitDirection::IMPOSSIBLE);
				toReturn = idArray[nth];
			}
		}
		else {
			toReturn = idArray[nth];
		}

		#undef check

		p_lua_pop(L, 3);                                                                 // 0 [ ... ]
		return toReturn;
	});
}

// Expects: n [ ... ]
// Returns: n [ ... ]
//
// This is written in C++ for the scenario in which EEex hooks an object's destructor to clean up auxiliary values,
// with the caveat that the destructor is called frequently enough that calling out to Lua is impractical.
// An example would be cleaning up CGameEffect auxiliaries.
//
void EEex::DestroyUDAux(lua_State* L, void* ptr) {
	logStutter<void>("EEex::DestroyUDAux", [&]() {
		p_lua_getglobal(L, "EEex_UserDataAuxiliary"); // 1 [ ..., EEex_UserDataAuxiliary ]
		p_lua_pushlightuserdata(L, ptr);              // 2 [ ..., EEex_UserDataAuxiliary, lud(ptr) ]
		p_lua_pushnil(L);                             // 3 [ ..., EEex_UserDataAuxiliary, lud(ptr), nil ]
		p_lua_rawset(L, -3);                          // 1 [ ..., EEex_UserDataAuxiliary ]
		p_lua_pop(L, 1);                              // 0 [ ... ]
	});
}

// Expects: n [ ... ]
// Returns: n [ ... ]
void EEex::CopyUDAux(lua_State* L, void* sourcePtr, void* targetPtr) {
	logStutter<void>("EEex::CopyUDAux", [&]() {
		p_lua_getglobal(L, "EEex_UserDataAuxiliary"); // 1 [ ..., EEex_UserDataAuxiliary ]
		p_lua_pushlightuserdata(L, sourcePtr);        // 2 [ ..., EEex_UserDataAuxiliary, lud(sourcePtr) ]
		p_lua_rawget(L, -2);                          // 2 [ ..., EEex_UserDataAuxiliary, EEex_UserDataAuxiliary[lud(sourcePtr)] -> srcAux ]
		p_lua_pushlightuserdata(L, targetPtr);        // 3 [ ..., EEex_UserDataAuxiliary, srcAux, lud(targetPtr) ]
		EEex::DeepCopyIndex(L, -2);                   // 4 [ ..., EEex_UserDataAuxiliary, srcAux, lud(targetPtr), srcAuxCopy ]
		p_lua_rawset(L, -4);                          // 2 [ ..., EEex_UserDataAuxiliary, srcAux ]
		p_lua_pop(L, 2);                              // 0 [ ... ]
	});
}

W<CString> fetchStrRef(uint strref) {
	W<STR_RES> res;
	(*p_g_pBaldurChitin)->m_cTlkTable.Fetch(strref, &*res, false);
	return W<CString>(&res->szText);
}

W<CString> getEffectSourceName(CGameEffect* pEffect) {
	if (pEffect->m_sourceType == 1) {
		// Spell
		W<CSpell> spell{ pEffect->m_sourceRes };
		CResSpell* res = spell->pRes;
		if (res->Demand()) {
			return fetchStrRef(res->pHeader->genericName);
		}
	}
	else if (pEffect->m_sourceType == 2) {
		// Item
		W<CItem> item{ pEffect->m_sourceRes, 0, 0, 0, 0, 0 };
		CResItem* res = item->pRes;
		if (res->Demand()) {
			if ((pEffect->m_flags & 0x80000000) != 0) {
				return fetchStrRef(res->pHeader->identifiedName);
			}
			else {
				return fetchStrRef(res->pHeader->genericName);
			}
		}
	}
	return "Unknown";
}

void displaySpriteMessage(CGameSprite* pTarget, W<CString> message) {

	CMessageDisplayText *const pMessageDisplayText = newEngineObj<CMessageDisplayText>(
		pTarget->GetName(false), &*message, 0xBED7D7, 0xBED7D7, -1, pTarget->m_id, pTarget->m_id);

	(*p_g_pBaldurChitin)->m_cMessageHandler.AddMessage(pMessageDisplayText, false);
}

int checkNoSavingThrowsAndEvasion(CGameEffect *const pEffect, CGameSprite *const pTarget) {

	if ((pEffect->m_savingThrow & 0x1F) == 0) {

		// .EFF [+0x5C] BIT2
		// Automatically set by:
		//   Targeting modes 3, 4, 5, 6, 7, and 8
		//   Secondary AoE projectiles

		if ((pEffect->m_flags & 4) != 0) {

			for (auto pNode = pTarget->m_equipedEffectList.m_pNodeHead; pNode != nullptr; pNode = pNode->pNext) {
				// CGameEffectEvadeAreaOfEffect
				if (pNode->data->m_effectId == 0x142) {
					pEffect->m_savingThrow >>= 5;
					goto checkStillNoSavingThrow;
				}
			}

			for (auto pNode = pTarget->m_timedEffectList.m_pNodeHead; pNode != nullptr; pNode = pNode->pNext) {
				// CGameEffectEvadeAreaOfEffect
				if (pNode->data->m_effectId == 0x142) {
					pEffect->m_savingThrow >>= 5;
				}
			}
		}

	checkStillNoSavingThrow:;
		if ((pEffect->m_savingThrow & 0x1F) == 0) {
			return true; // No saving throws defined or evaded
		}
	}

	return false; // Not evaded
}

int EEex::Override_CGameEffect_CheckSave(CGameEffect *const pEffect, CGameSprite *const pTarget,
	byte *const saveVSDeathRollRaw, byte *const saveVSWandsRollRaw, byte *const saveVSPolyRollRaw,
	byte *const saveVSBreathRollRaw, byte *const saveVSSpellRollRaw, byte *const resistMagicRollRaw)
{
	return logStutter<int>("EEex::Override_CGameEffect_CheckSave", [&] {

		bool extraFeedback = true;

		CBaldurChitin& chitin = **p_g_pBaldurChitin;
		CInfGame& game = *chitin.m_pObjectGame;
		CDerivedStats& targetStats = *pTarget->GetActiveStats();

		// State: Poison || Graphics: Display Special Effect Icon - Poisoned
		if (const uint nEffectId = pEffect->m_effectId;
			(nEffectId == 25 || (nEffectId == 142 && pEffect->m_dWFlags == 6))
			&& ((pTarget->m_nMirrorImages != 0 && (pEffect->m_savingThrow & 0x1000000) == 0) // Bypass mirror image
				|| targetStats.m_nStoneSkins > 0
				|| targetStats.m_nStoneSkinsGolem > 0
			))
		{
			if (extraFeedback) {
				displaySpriteMessage(pTarget, "Poison blocked.");
			}

			return false; // SAVE SUCCEEDED (EFFECT BLOCKED)
		}

		// v2.5
		//if (uint nResistFlags = pEffect->m_flags; (nResistFlags & 1) != 0 && (nResistFlags & 2) == 0) {
		//
		//	sbyte resistMagicRoll = *resistMagicRollRaw & 0x7F;
		//	short nMagicResistance = targetStats.m_nResistMagic;
		//
		//	if (resistMagicRoll < nMagicResistance) {
		//
		//		if ((*resistMagicRollRaw & 0x80) == 0) {
		//
		//			CMessageDisplayTextRef* pMessageDisplayTextRef = newEngineObj<CMessageDisplayTextRef>(
		//				pTarget->GetNameRef(), 0xF00519, 0xBED7D7, 0xBED7D7, -1, pTarget->m_id, pTarget->m_id);
		//
		//			chitin.m_cMessageHandler.AddMessage(pMessageDisplayTextRef, false);
		//			*resistMagicRollRaw = *resistMagicRollRaw | 0x80;
		//		}
		//
		//		return false;
		//	}
		//}

		const uint nResistFlags = pEffect->m_flags;
		const sbyte nResistMagicRoll = *resistMagicRollRaw & 0x7F;
		const short nResistMagic = targetStats.m_nResistMagic;
		const bool bMagicResisted = nResistMagicRoll < nResistMagic;

		// .EFF [+0x5C] BIT3
		// Automatically set by:
		//   Targeting modes 1, 2 (sometimes), and 9

		if ((nResistFlags & 8) != 0 && pEffect->m_sourceId == pTarget->m_id && bMagicResisted
			&& checkNoSavingThrowsAndEvasion(pEffect, pTarget))
		{
			return true; // SAVE FAILED (EFFECT ADDED)
		}

		if ((nResistFlags & 1) != 0 && (nResistFlags & 2) == 0 && bMagicResisted) {

			if ((*resistMagicRollRaw & 0x80) == 0) {

				if (extraFeedback) {
					W<CString> magicResStr = fetchStrRef(0xF00519);
					displaySpriteMessage(pTarget, std::format("{} ({:d} < {})",
						magicResStr->m_pchData, nResistMagicRoll, nResistMagic).c_str());
				}
				else {
					CMessageDisplayTextRef *const pMessageDisplayTextRef = newEngineObj<CMessageDisplayTextRef>(
						pTarget->GetNameRef(), 0xF00519, 0xBED7D7, 0xBED7D7, -1, pTarget->m_id, pTarget->m_id);

					chitin.m_cMessageHandler.AddMessage(pMessageDisplayTextRef, false);
				}

				*resistMagicRollRaw = *resistMagicRollRaw | 0x80;
			}

			return false; // SAVE SUCCEEDED (EFFECT BLOCKED)
		}

		// .EFF [0x50]
		// Automatically set by:
		//   CProjectileNewScorcher::ApplyEffectsToTarget()
		//     1 -> Target
		//     2 -> Bystander (standing in projectile path)

		if (const uint nJeremyIsAnIdiot = pEffect->m_JeremyIsAnIdiot;
			   (nJeremyIsAnIdiot == 1 && (pEffect->m_savingThrow & 0x400) != 0)  // Ignore primary target
			|| (nJeremyIsAnIdiot == 2 && (pEffect->m_savingThrow & 0x800) != 0)) // Ignore secondary target
		{
			return false; // SAVE SUCCEEDED (EFFECT BLOCKED)
		}

		if (checkNoSavingThrowsAndEvasion(pEffect, pTarget)) {
			return true; // SAVE FAILED (EFFECT ADDED)
		}

		short nBestSaveStat = 20;
		int nBestSavesRoll = 0;
		uint saveFeedbackStrRef = 0;

		// Save vs. Death
		if ((pEffect->m_savingThrow & 4) != 0 && targetStats.m_nSaveVSDeath < nBestSaveStat) {

			nBestSaveStat = targetStats.m_nSaveVSDeath;
			nBestSavesRoll = *saveVSDeathRollRaw & 0x7F;

			// BUGFIX: The engine normally checks whether it should output "Save vs. Type" here
			//         via (nBestSaveStat <= nBestSavesRoll). This breaks when the modifiers
			//         later in the function change an initially failed save into a success.
			//
			if ((*saveVSDeathRollRaw & 0x80) == 0) {
				saveFeedbackStrRef = 0xF00517;
				*saveVSWandsRollRaw = *saveVSWandsRollRaw & 0x7F;
				*saveVSPolyRollRaw = *saveVSPolyRollRaw & 0x7F;
				*saveVSBreathRollRaw = *saveVSBreathRollRaw & 0x7F;
				*saveVSSpellRollRaw = *saveVSSpellRollRaw & 0x7F;
				*saveVSDeathRollRaw = *saveVSDeathRollRaw | 0x80;
			}
		}

		// Save vs. Wands
		if ((pEffect->m_savingThrow & 8) != 0 && targetStats.m_nSaveVSWands < nBestSaveStat) {

			nBestSaveStat = targetStats.m_nSaveVSWands;
			nBestSavesRoll = *saveVSWandsRollRaw & 0x7F;

			// BUGFIX: The engine normally checks whether it should output "Save vs. Type" here
			//         via (nBestSaveStat <= nBestSavesRoll). This breaks when the modifiers
			//         later in the function change an initially failed save into a success.
			//
			if ((*saveVSWandsRollRaw & 0x80) == 0) {
				saveFeedbackStrRef = 0xF0051B;
				*saveVSDeathRollRaw = *saveVSDeathRollRaw & 0x7F;
				*saveVSPolyRollRaw = *saveVSPolyRollRaw & 0x7F;
				*saveVSBreathRollRaw = *saveVSBreathRollRaw & 0x7F;
				*saveVSSpellRollRaw = *saveVSSpellRollRaw & 0x7F;
				*saveVSWandsRollRaw = *saveVSWandsRollRaw | 0x80;
			}
		}

		// Save vs. Poly
		if ((pEffect->m_savingThrow & 0x10) != 0 && targetStats.m_nSaveVSPoly < nBestSaveStat) {

			nBestSaveStat = targetStats.m_nSaveVSPoly;
			nBestSavesRoll = *saveVSPolyRollRaw & 0x7F;

			// BUGFIX: The engine normally checks whether it should output "Save vs. Type" here
			//         via (nBestSaveStat <= nBestSavesRoll). This breaks when the modifiers
			//         later in the function change an initially failed save into a success.
			//
			if ((*saveVSPolyRollRaw & 0x80) == 0) {
				saveFeedbackStrRef = 0xF00518;
				*saveVSDeathRollRaw = *saveVSDeathRollRaw & 0x7F;
				*saveVSWandsRollRaw = *saveVSWandsRollRaw & 0x7F;
				*saveVSBreathRollRaw = *saveVSBreathRollRaw & 0x7F;
				*saveVSSpellRollRaw = *saveVSSpellRollRaw & 0x7F;
				*saveVSPolyRollRaw = *saveVSPolyRollRaw | 0x80;
			}
		}

		// Save vs. Breath
		if ((pEffect->m_savingThrow & 2) != 0 && targetStats.m_nSaveVSBreath < nBestSaveStat) {

			nBestSaveStat = targetStats.m_nSaveVSBreath;
			nBestSavesRoll = *saveVSBreathRollRaw & 0x7F;

			// BUGFIX: The engine normally checks whether it should output "Save vs. Type" here
			//         via (nBestSaveStat <= nBestSavesRoll). This breaks when the modifiers
			//         later in the function change an initially failed save into a success.
			//
			if ((*saveVSBreathRollRaw & 0x80) == 0) {
				saveFeedbackStrRef = 0xF00516;
				*saveVSDeathRollRaw = *saveVSDeathRollRaw & 0x7F;
				*saveVSWandsRollRaw = *saveVSWandsRollRaw & 0x7F;
				*saveVSPolyRollRaw = *saveVSPolyRollRaw & 0x7F;
				*saveVSSpellRollRaw = *saveVSSpellRollRaw & 0x7F;
				*saveVSBreathRollRaw = *saveVSBreathRollRaw | 0x80;
			}
		}

		// Save vs. Spell
		if ((pEffect->m_savingThrow & 1) != 0 && targetStats.m_nSaveVSSpell < nBestSaveStat) {

			nBestSaveStat = targetStats.m_nSaveVSSpell;
			nBestSavesRoll = *saveVSSpellRollRaw & 0x7F;

			// BUGFIX: The engine normally checks whether it should output "Save vs. Type" here
			//         via (nBestSaveStat <= nBestSavesRoll). This breaks when the modifiers
			//         later in the function change an initially failed save into a success.
			//
			if ((*saveVSSpellRollRaw & 0x80) == 0) {
				saveFeedbackStrRef = 0xF0051A;
				*saveVSDeathRollRaw = *saveVSDeathRollRaw & 0x7F;
				*saveVSWandsRollRaw = *saveVSWandsRollRaw & 0x7F;
				*saveVSPolyRollRaw = *saveVSPolyRollRaw & 0x7F;
				*saveVSBreathRollRaw = *saveVSBreathRollRaw & 0x7F;
				*saveVSSpellRollRaw = *saveVSSpellRollRaw | 0x80;
			}
		}

		int nBestSavesRollTotal = nBestSavesRoll;
		OStringStreamA extraFeedbackStream{};
		bool alreadyOutputRoll = false;
		const char* feedbackSeparator = "";

		#define outputBonus(name, val)                                \
			if (!alreadyOutputRoll) {                                 \
				alreadyOutputRoll = true;                             \
				extraFeedbackStream << "Roll: " << nBestSavesRoll;    \
				feedbackSeparator = ", ";                             \
			}                                                         \
			extraFeedbackStream << feedbackSeparator << name << ": "; \
			if (val > 0) {                                            \
				extraFeedbackStream << "+";                           \
			}                                                         \
			extraFeedbackStream << val;                               \
			feedbackSeparator = ", ";

		// Improved Invisibility
		//
		// BUGFIX: The engine normally subtracts 4 from nBestSaveStat in the blocks above,
		//         however, this causes a bug when multiple saving throw types are
		//         selected, where a better saving throw stat must be better than or equal
		//         to the improved invisibility bonus (-4) to be used. This really doesn't
		//         matter since no vanilla spells use the mechanic, but fix it anyway in
		//         case some mod uses it.
		//
		if ((targetStats.m_generalState & 0x400000) != 0) {
			nBestSavesRollTotal += 4;
			outputBonus("Improved Invisibility", 4);
		}

		// .EFF [+0x44] - Effect save bonus
		const int nSaveMod = pEffect->m_saveMod;
		nBestSavesRollTotal += nSaveMod;
		if (nSaveMod != 0) {
			outputBonus("Spell Bonus", nSaveMod);
		}

		// Legacy of Bhaal - Removed in v2.6 as part of bugfix
		//if (game.m_options.m_bNightmareMode
		//	&& pTarget->virtual_GetAIType()->m_EnemyAlly >= 30) // GOODCUTOFF
		//{
		//	nBestSavesRoll += 5;
		//}

		// Mage specialist bonus vs. incoming spells
		const uint school = pEffect->m_school;
		if (school != 0 && school == game.m_ruleTables.MapCharacterSpecializationToSchool(
			pTarget->m_baseStats.m_mageSpecialization))
		{
			nBestSavesRollTotal += 2;
			outputBonus("Specialist vs. School", 2);
		}

		// op346
		if (school < 12) {
			const short nSchoolSaveBonus = targetStats.m_nSchoolSaveBonus[school];
			nBestSavesRollTotal += nSchoolSaveBonus;
			if (nSchoolSaveBonus != 0) {
				outputBonus("Creature vs. School", nSchoolSaveBonus);
			}
		}

		CGameSprite* pSourceSprite = nullptr;

		// op219
		if (CGameObject* pSourceObject;
			pEffect->m_sourceId != -1 && CGameObjectArray::GetShare(pEffect->m_sourceId, &pSourceObject) == 0
			&& pSourceObject->virtual_GetObjectType() == CGameObjectType::SPRITE)
		{
			pSourceSprite = reinterpret_cast<CGameSprite*>(pSourceObject);
			const CAIObjectType* pSourceAIType = pSourceObject->virtual_GetAIType();
			const CSelectiveBonus* pFoundBonus = nullptr;

			for (auto pNode = targetStats.m_cProtectionList.m_pNodeHead; pNode != nullptr; pNode = pNode->pNext) {

				const CSelectiveBonus* pBonus = pNode->data;

				// type, checkForNonSprites, noNonSprites, deathMatchAllowance
				if (pSourceAIType->OfType(&pBonus->m_type, false, false, false)) {
					pFoundBonus = pBonus;
					break;
				}
			}

			const short nAITypeBonus = pFoundBonus != nullptr ? static_cast<short>(pFoundBonus->m_bonus) : 0;
			nBestSavesRollTotal += nAITypeBonus;
			if (nAITypeBonus != 0) {
				const CAIObjectType& type = pFoundBonus->m_type;
				const char* bonusName;
				if (type.m_EnemyAlly != 0) {
					bonusName = "Creature vs. Allegiance";
				}
				else if (type.m_General != 0) {
					bonusName = "Creature vs. General";
				}
				else if (type.m_Race != 0) {
					bonusName = "Creature vs. Race";
				}
				else if (type.m_Class != 0) {
					bonusName = "Creature vs. Class";
				}
				else if (type.m_Specifics != 0) {
					bonusName = "Creature vs. Specifics";
				}
				else if (type.m_Gender != 0) {
					bonusName = "Creature vs. Gender";
				}
				else if (type.m_Alignment != 0) {
					bonusName = "Creature vs. Alignment";
				}
				else {
					bonusName = "Creature vs. Everyone";
				}
				outputBonus(bonusName, nAITypeBonus);
			}
		}

		if (nBestSaveStat <= nBestSavesRollTotal) {

			if (saveFeedbackStrRef != 0 && (targetStats.m_generalState & 0x800) == 0) {

				if (extraFeedback) {

					W<CString> saveStr = fetchStrRef(saveFeedbackStrRef);
					const std::string extraFeedbackStr = extraFeedbackStream.str();

					W<CString> sourceName = getEffectSourceName(pEffect);
					W<CString> name = "Unknown";

					if (pSourceSprite != nullptr) {
						*name = pSourceSprite->GetName(true);
					}

					if (extraFeedbackStr.empty()) {
						displaySpriteMessage(pTarget, std::format("{} ({}: {}) : {} <= {}", saveStr->m_pchData,
							sourceName->m_pchData, name->m_pchData, nBestSaveStat, nBestSavesRollTotal).c_str());
					}
					else {
						displaySpriteMessage(pTarget, std::format("{} ({}: {}) : {} <= {} ({})", saveStr->m_pchData,
							sourceName->m_pchData, name->m_pchData, nBestSaveStat, nBestSavesRollTotal, extraFeedbackStr).c_str());
					}
				}
				else {

					if (const uint nTextLevel = game.m_options.m_nEffectTextLevel; (nTextLevel & 1) == 0)
					{
						if ((nTextLevel & 8) != 0) {

							//     Options->Gameplay->Feedback->To-Hit Rolls  [Disabled]
							// and Options->Gameplay->Feedback->State Changes [Enabled]
							// (default config)

							CMessageDisplayTextRef *const pMessageDisplayTextRef = newEngineObj<CMessageDisplayTextRef>(
								pTarget->GetNameRef(), saveFeedbackStrRef, 0xBED7D7, 0xBED7D7, -1, pTarget->m_id, pTarget->m_id);

							chitin.m_cMessageHandler.AddMessage(pMessageDisplayTextRef, false);
						}
					}
					else {

						// Options->Gameplay->Feedback->To-Hit Rolls [Enabled]

						displaySpriteMessage(pTarget, std::format("{} : {}",
							fetchStrRef(saveFeedbackStrRef)->m_pchData, nBestSavesRollTotal).c_str());
					}
				}
			}

			return false; // SAVE SUCCEEDED (EFFECT BLOCKED)
		}

		return true; // SAVE FAILED (EFFECT ADDED)
	});
}

// Expects: n     [ ... ]
// Returns: n + 1 [ ..., t ]
void getUDAux(lua_State *const L, void *const ptr) {

	////////////////////////////////////////////////////////////
	// function EEex_GetUserDataAuxiliary(ptr)                //
	//     local auxiliary = EEex_UserDataAuxiliary[lud(lud)] //
	//     if not auxiliary then                              //
	//         auxiliary = {}                                 //
	//         EEex_UserDataAuxiliary[lud(ptr)] = auxiliary   //
	//     end                                                //
	//     return auxiliary                                   //
	// end                                                    //
	////////////////////////////////////////////////////////////

	p_lua_getglobal(L, "EEex_UserDataAuxiliary"); // 1 [ ..., EEex_UserDataAuxiliary ]
	p_lua_pushlightuserdata(L, ptr);              // 2 [ ..., EEex_UserDataAuxiliary, lud(ptr) -> lud ]
	p_lua_rawget(L, -2);                          // 2 [ ..., EEex_UserDataAuxiliary, EEex_UserDataAuxiliary[lud] -> t ]
	if (p_lua_isnil(L, -1)) {
		p_lua_pop(L, 1);                          // 1 [ ..., EEex_UserDataAuxiliary ]
		p_lua_newtable(L);                        // 2 [ ..., EEex_UserDataAuxiliary, {} -> t ]
		p_lua_pushlightuserdata(L, ptr);          // 3 [ ..., EEex_UserDataAuxiliary, t, lud(ptr) -> lud ]
		p_lua_pushvalue(L, -2);                   // 4 [ ..., EEex_UserDataAuxiliary, t, lud, t ]
		p_lua_rawset(L, -4);                      // 2 [ ..., EEex_UserDataAuxiliary, t ]
	}
	p_lua_remove(L, -2);                          // 1 [ ..., t ]
}

// Expects: n     [ ... ]
// Returns: n + 1 [ ..., castPtrUD ]
void getCastUD(lua_State* L, const char* castBaseName, const char* castFuncName, void* toCastPtr) {
	p_lua_getglobal(L, castFuncName);                      // 1 [ castFunc ]
	tolua_pushusertype_nocast(L, toCastPtr, castBaseName); // 2 [ castFunc, toCastPtr ]
	p_lua_call(L, 1, 1);                                   // 1 [ castPtrUD ]
}

bool isSprite(CGameObject* pObject, bool allowDead = false) {
	if (pObject != nullptr && pObject->m_objectType == CGameObjectType::SPRITE) {
		return allowDead || (reinterpret_cast<CGameSprite*>(pObject)->m_baseStats.m_generalState & 0xFC0) == 0;
	}
	return false;
}

void EEex::Stats_Hook_OnEqu(lua_State* L, CDerivedStats* stats, CDerivedStats* otherStats) {

	logStutter<void>("EEex::Stats_Hook_OnEqu", [&] {

		///////////////////////////////////////////////////////////////////////////////////////////////////////
		// function EEex_Stats_Hook_OnEqu(stats, otherStats)                                                 //
		//     local aux = EEex_GetUDAux(stats)                                                              //
		//     local otherAux = EEex_GetUDAux(otherStats)                                                    //
		//     for _, registered in pairs(EEex_Stats_Registered) do                                          //
		//         EEex_Utility_CallIfExists(registered.onEqu, registered, stats, aux, otherStats, otherAux) //
		//     end                                                                                           //
		// end                                                                                               //
		///////////////////////////////////////////////////////////////////////////////////////////////////////

		tolua_pushusertype_nocast(L, stats, "CDerivedStats");      //  1 [ statsUD ]
		getUDAux(L, stats);                                        //  2 [ statsUD, statsAux ]
		tolua_pushusertype_nocast(L, otherStats, "CDerivedStats"); //  3 [ statsUD, statsAux, otherStatsUD ]
		getUDAux(L, otherStats);                                   //  4 [ statsUD, statsAux, otherStatsUD, otherStatsAux ]

		p_lua_getglobal(L, "EEex_Stats_Registered");               //  5 [ statsUD, statsAux, otherStatsUD, otherStatsAux, "EEex_Stats_Registered" ]
		p_lua_pushnil(L);                                          //  6 [ statsUD, statsAux, otherStatsUD, otherStatsAux, "EEex_Stats_Registered", nil ]
		while (p_lua_next(L, -2)) {
			                                                       //  7 [ statsUD, statsAux, otherStatsUD, otherStatsAux, "EEex_Stats_Registered", k, v ]
			p_lua_getfield(L, -1, "onEqu");                        //  8 [ statsUD, statsAux, otherStatsUD, otherStatsAux, "EEex_Stats_Registered", k, v, v.onEqu ]
			if (!p_lua_isnil(L, -1)) {
				p_lua_pushvalue(L, -2);                            //  9 [ statsUD, statsAux, otherStatsUD, otherStatsAux, "EEex_Stats_Registered", k, v, v.onEqu, v ]
				p_lua_pushvalue(L, -9);                            // 10 [ statsUD, statsAux, otherStatsUD, otherStatsAux, "EEex_Stats_Registered", k, v, v.onEqu, v, statsUD ]
				p_lua_pushvalue(L, -9);                            // 11 [ statsUD, statsAux, otherStatsUD, otherStatsAux, "EEex_Stats_Registered", k, v, v.onEqu, v, statsUD, statsAux ]
				p_lua_pushvalue(L, -9);                            // 12 [ statsUD, statsAux, otherStatsUD, otherStatsAux, "EEex_Stats_Registered", k, v, v.onEqu, v, statsUD, statsAux, otherStatsUD ]
				p_lua_pushvalue(L, -9);                            // 13 [ statsUD, statsAux, otherStatsUD, otherStatsAux, "EEex_Stats_Registered", k, v, v.onEqu, v, statsUD, statsAux, otherStatsUD, otherStatsAux ]
				p_lua_call(L, 5, 0);                               //  7 [ statsUD, statsAux, otherStatsUD, otherStatsAux, "EEex_Stats_Registered", k, v ]
				p_lua_pop(L, 1);                                   //  6 [ statsUD, statsAux, otherStatsUD, otherStatsAux, "EEex_Stats_Registered", k ]
			}
			else {
				p_lua_pop(L, 2);                                   //  6 [ statsUD, statsAux, otherStatsUD, otherStatsAux, "EEex_Stats_Registered", k ]
			}
		}
		                                                           //  5 [ statsUD, statsAux, otherStatsUD, otherStatsAux, "EEex_Stats_Registered" ]
		p_lua_pop(L, 5);                                           //  0 [ ]
	});
}

int EEex::Opcode_Hook_ApplySpell_ShouldFlipSplprotSourceAndTarget(CGameEffect* effect) {
	return logStutter<int>("EEex::Opcode_Hook_ApplySpell_ShouldFlipSplprotSourceAndTarget", [&]() {
		return (effect->m_special & 2) != 0;
	});
}

int EEex::Opcode_Hook_OnCheckAdd(lua_State* L, CGameEffect* effect, CGameSprite* sprite) {

	return logStutter<int>("EEex::Opcode_Hook_OnCheckAdd", [&]() {

		////////////////////////////////////////////////////////////////////////////////////////
		// function EEex_Opcode_Hook_OnCheckAdd(effect, sprite)                               //
		//     local statsAux = EEex_GetUDAux(sprite:getActiveStats())                        //
		//     for _, screenEffect in ipairs(statsAux["EEex_ScreenEffects"]) do               //
		//         local immunityFunc = _G[screenEffect.m_res:get()]                          //
		//         if immunityFunc ~= nil and immunityFunc(screenEffect, effect, sprite) then //
		//             return true                                                            //
		//         end                                                                        //
		//     end                                                                            //
		//     return false                                                                   //
		// end                                                                                //
		////////////////////////////////////////////////////////////////////////////////////////

		tolua_pushusertype_nocast(L, effect, "CGameEffect");               //  1 [ effectUD ]
		tolua_pushusertype_nocast(L, sprite, "CGameSprite");               //  2 [ effectUD, spriteUD ]

		getUDAux(L, sprite->GetActiveStats());                             //  3 [ effectUD, spriteUD, aux(sprite->GetActiveStats()) -> statsAux ]

		p_lua_pushstring(L, "EEex_ScreenEffects");                         //  4 [ effectUD, spriteUD, statsAux, "EEex_ScreenEffects" ]
		p_lua_rawget(L, -2);                                               //  4 [ effectUD, spriteUD, statsAux, statsAux["EEex_ScreenEffects"] -> screenT ]

		p_lua_pushnil(L);                                                  //  5 [ effectUD, spriteUD, statsAux, screenT, nil ]
		while (p_lua_next(L, -2)) {
			                                                               //  6 [ effectUD, spriteUD, statsAux, screenT, k, v -> screenEffectUD ]
			CGameEffect *const pEffect = *reinterpret_cast<CGameEffect**>(
				p_lua_touserdata(L, -1));

			char immunityFuncName[9];
			pEffect->m_res.toNullTerminatedStr(immunityFuncName);

			p_lua_getglobal(L, immunityFuncName);                          //  7 [ effectUD, spriteUD, statsAux, screenT, k, screenEffectUD, immunityFunc ]

			if (!p_lua_isnil(L, -1)) {

				p_lua_insert(L, -2);                                       //  7 [ effectUD, spriteUD, statsAux, screenT, k, immunityFunc, screenEffectUD ]
				p_lua_pushvalue(L, -7);                                    //  8 [ effectUD, spriteUD, statsAux, screenT, k, immunityFunc, screenEffectUD, effectUD ]
				p_lua_pushvalue(L, -7);                                    //  9 [ effectUD, spriteUD, statsAux, screenT, k, immunityFunc, screenEffectUD, effectUD, spriteUD ]
				p_lua_call(L, 3, 1);                                       //  6 [ effectUD, spriteUD, statsAux, screenT, k, retVal ]

				if (p_lua_toboolean(L, -1)) {
					p_lua_pop(L, 6);                                       //  0 [ ]
					return 1;
				}

				p_lua_pop(L, 1);                                           //  5 [ effectUD, spriteUD, statsAux, screenT, k ]
			}
			else {
				p_lua_pop(L, 2);                                           //  5 [ effectUD, spriteUD, statsAux, screenT, k ]
			}
		}
		                                                                   //  4 [ effectUD, spriteUD, statsAux, screenT ]
		p_lua_pop(L, 4);                                                   //  0 [ ]
		return 0;
	});
}

std::unordered_map<uintptr_t, std::pair<const char*, EEex::ProjectileType>> projVFTableToType{};

void registerProjVFTableType(std::map<String, PatternEntry>& patterns, const TCHAR* patternName, std::pair<const char*, EEex::ProjectileType> info) {
	if (auto found = patterns.find(patternName); found != patterns.end()) {
		projVFTableToType.emplace(found->second.value, info);
	}
	else {
		PrintT(TEXT("[!] Pattern %s missing, EEex will not work as expected!\n"), patternName);
	}
}

void pushProjectileUD(lua_State* L, CProjectile* pProjectile) {
	if (pProjectile == nullptr) {
		p_lua_pushnil(L);
		return;
	}
	const uintptr_t vfptr = *reinterpret_cast<uintptr_t*>(pProjectile);
	if (auto found = projVFTableToType.find(vfptr); found != projVFTableToType.end()) {
		tolua_pushusertype_nocast(L, pProjectile, found->second.first);
	}
	else {
		tolua_pushusertype_nocast(L, pProjectile, "CProjectile");
	}
}

void EEex::InitPatterns(std::map<String, PatternEntry>& patterns) {
	registerProjVFTableType(patterns, TEXT("CProjectile::VFTable"),              { "CProjectile",                    EEex::ProjectileType::CProjectile                    });
	registerProjVFTableType(patterns, TEXT("CProjectileAmbiant::VFTable"),       { "CProjectileAmbiant",             EEex::ProjectileType::CProjectileAmbiant             });
	registerProjVFTableType(patterns, TEXT("CProjectileArea::VFTable"),          { "CProjectileArea",                EEex::ProjectileType::CProjectileArea                });
	registerProjVFTableType(patterns, TEXT("CProjectileBAM::VFTable"),           { "CProjectileBAM",                 EEex::ProjectileType::CProjectileBAM                 });
	//registerProjVFTableType(patterns, TEXT("CProjectileCallLightning::VFTable"), { "CProjectileCallLightning",       EEex::ProjectileType::CProjectileCallLightning       });
	//registerProjVFTableType(patterns, TEXT("CProjectileCastingGlow::VFTable"),   { "CProjectileCastingGlow",         EEex::ProjectileType::CProjectileCastingGlow         });
	registerProjVFTableType(patterns, TEXT("CProjectileChain::VFTable"),         { "CProjectileChain",               EEex::ProjectileType::CProjectileChain               });
	registerProjVFTableType(patterns, TEXT("CProjectileColorSpray::VFTable"),    { "CProjectileColorSpray",          EEex::ProjectileType::CProjectileColorSpray          });
	registerProjVFTableType(patterns, TEXT("CProjectileConeOfCold::VFTable"),    { "CProjectileConeOfCold",          EEex::ProjectileType::CProjectileConeOfCold          });
	registerProjVFTableType(patterns, TEXT("CProjectileFall::VFTable"),          { "CProjectileFall",                EEex::ProjectileType::CProjectileFall                });
	registerProjVFTableType(patterns, TEXT("CProjectileFireHands::VFTable"),     { "CProjectileFireHands",           EEex::ProjectileType::CProjectileFireHands           });
	registerProjVFTableType(patterns, TEXT("CProjectileInstant::VFTable"),       { "CProjectileInstant",             EEex::ProjectileType::CProjectileInstant             });
	//registerProjVFTableType(patterns, TEXT("CProjectileInvisibleTravelling"),    { "CProjectileInvisibleTravelling", EEex::ProjectileType::CProjectileInvisibleTravelling });
	//registerProjVFTableType(patterns, TEXT("CProjectileLightningBolt"),          { "CProjectileLightningBolt",       EEex::ProjectileType::CProjectileLightningBolt       });
	//registerProjVFTableType(patterns, TEXT("CProjectileLightningBoltGround"),    { "CProjectileLightningBoltGround", EEex::ProjectileType::CProjectileLightningBoltGround });
	//registerProjVFTableType(patterns, TEXT("CProjectileLightningBounce"),        { "CProjectileLightningBounce",     EEex::ProjectileType::CProjectileLightningBounce     });
	//registerProjVFTableType(patterns, TEXT("CProjectileLightningStorm"),         { "CProjectileLightningStorm",      EEex::ProjectileType::CProjectileLightningStorm      });
	//registerProjVFTableType(patterns, TEXT("CProjectileMagicMissileMulti"),      { "CProjectileMagicMissileMulti",   EEex::ProjectileType::CProjectileMagicMissileMulti   });
	registerProjVFTableType(patterns, TEXT("CProjectileMulti::VFTable"),         { "CProjectileMulti",               EEex::ProjectileType::CProjectileMulti               });
	registerProjVFTableType(patterns, TEXT("CProjectileMushroom::VFTable"),      { "CProjectileMushroom",            EEex::ProjectileType::CProjectileMushroom            });
	registerProjVFTableType(patterns, TEXT("CProjectileNewScorcher::VFTable"),   { "CProjectileNewScorcher",         EEex::ProjectileType::CProjectileNewScorcher         });
	registerProjVFTableType(patterns, TEXT("CProjectileScorcher::VFTable"),      { "CProjectileScorcher",            EEex::ProjectileType::CProjectileScorcher            });
	registerProjVFTableType(patterns, TEXT("CProjectileSegment::VFTable"),       { "CProjectileSegment",             EEex::ProjectileType::CProjectileSegment             });
	registerProjVFTableType(patterns, TEXT("CProjectileSkyStrike::VFTable"),     { "CProjectileSkyStrike",           EEex::ProjectileType::CProjectileSkyStrike           });
	registerProjVFTableType(patterns, TEXT("CProjectileSkyStrikeBAM::VFTable"),  { "CProjectileSkyStrikeBAM",        EEex::ProjectileType::CProjectileSkyStrikeBAM        });
	registerProjVFTableType(patterns, TEXT("CProjectileSpellHit::VFTable"),      { "CProjectileSpellHit",            EEex::ProjectileType::CProjectileSpellHit            });
	registerProjVFTableType(patterns, TEXT("CProjectileTravelDoor::VFTable"),    { "CProjectileTravelDoor",          EEex::ProjectileType::CProjectileTravelDoor          });
}

void pushGameObjectUD(lua_State* L, CGameObject* pGameObject) {
	if (pGameObject == nullptr) {
		p_lua_pushnil(L);
		return;
	}
	const char* userType;
	switch (pGameObject->m_objectType) {
		case CGameObjectType::AIBASE:        userType = "CGameAIBase";      break;
		case CGameObjectType::SOUND:         userType = "CGameSound";       break;
		case CGameObjectType::CONTAINER:     userType = "CGameContainer";   break;
		case CGameObjectType::SPAWNING:      userType = "CGameSpawning";    break;
		case CGameObjectType::DOOR:          userType = "CGameDoor";        break;
		case CGameObjectType::STATIC:        userType = "CGameStatic";      break;
		case CGameObjectType::SPRITE:        userType = "CGameSprite";      break;
		case CGameObjectType::OBJECT_MARKER: userType = "CObjectMarker";    break;
		case CGameObjectType::TRIGGER:       userType = "CGameTrigger";     break;
		case CGameObjectType::TILED_OBJECT:  userType = "CGameTiledObject"; break;
		case CGameObjectType::TEMPORAL:      userType = "CGameTemporal";    break;
		case CGameObjectType::AREA_AI:       userType = "CGameAIArea";      break;
		case CGameObjectType::FIREBALL:      userType = "CGameFireball3d";  break;
		case CGameObjectType::GAME_AI:       userType = "CGameAIGame";      break;
		default:                             userType = "CGameObject";      break;
	}
	tolua_pushusertype_nocast(L, pGameObject, userType);
}

union LuaTypeValue {
	const char* string;
	lua_Integer integer;
	bool boolean;
	LuaTypeValue(const char* string) : string(string) {}
	LuaTypeValue(lua_Integer integer) : integer(integer) {}
	LuaTypeValue(bool boolean) : boolean(boolean) {}
	LuaTypeValue() {}
};

struct LuaTypeContainer {
	bool valid;
	int type;
	LuaTypeValue value;
	LuaTypeContainer(int type, LuaTypeValue value) : type(type), value(value), valid(true) {}
	LuaTypeContainer(int type) : type(type), valid(true) {}
	LuaTypeContainer() : valid(false) {}
};

LuaTypeContainer getLuaTypeContainer(lua_State* L, int index) {
	const int type = p_lua_type(L, index);
	switch (type) {
		case LUA_TNUMBER: return LuaTypeContainer{ type, p_lua_tointeger(L, index) };
		case LUA_TSTRING: return LuaTypeContainer{ type, p_lua_tostring(L, index) };
		case LUA_TBOOLEAN: return LuaTypeContainer{ type, static_cast<bool>(p_lua_toboolean(L, index)) };
	}
	return LuaTypeContainer{ type };
}

LuaTypeContainer callMutatorFunction(
	lua_State* L,
	const char* mutatorTableName,
	const char* mutatorFunctionName,
	int argumentsTableIndex)
{
	argumentsTableIndex = p_lua_absindex(L, argumentsTableIndex);
	p_lua_getglobal(L, mutatorTableName);            // 1 [ ..., mutatorTable ]
	if (p_lua_type(L, -1) == LUA_TTABLE) {
		p_lua_pushstring(L, mutatorFunctionName);    // 2 [ ..., mutatorTable, mutatorFunctionName ]
		p_lua_rawget(L, -2);                         // 2 [ ..., mutatorTable, mutatorFunction ]
		if (p_lua_type(L, -1) == LUA_TFUNCTION) {
			p_lua_pushvalue(L, argumentsTableIndex); // 3 [ ..., mutatorTable, mutatorFunction, argumentsTable ]
			p_lua_call(L, 1, 1);                     // 2 [ ..., mutatorTable, retVal ]
			const LuaTypeContainer toRet = getLuaTypeContainer(L, -1);
			p_lua_pop(L, 2);                         // 0 [ ... ]
			return toRet;
		}
		else {
			Print("[!] op408 (ProjectileMutator) attempted to use an invalid \"%s\" value under: \"%s\"", mutatorFunctionName, mutatorTableName);
			p_lua_pop(L, 2);                         // 0 [ ... ]
		}
	}
	else {
		Print("[!] op408(ProjectileMutator) attempted to use an invalid mutator table : \"%s\"", mutatorTableName);
		p_lua_pop(L, 1);                             // 0 [ ... ]
	}
	return LuaTypeContainer{};
}

LuaTypeContainer processMutatorFunctions(
	lua_State* L,
	int projectileMutatorEffectsIndex,
	std::function<LuaTypeContainer(const char*, std::optional<int>)> func)
{
	projectileMutatorEffectsIndex = p_lua_absindex(L, projectileMutatorEffectsIndex);

	p_lua_getglobal(L, "EEex_Projectile_Private_GlobalMutators"); // 1 [ ..., EEex_Projectile_Private_GlobalMutators ]
	p_lua_pushnil(L);                                             // 2 [ ..., EEex_Projectile_Private_GlobalMutators, nil ]
	while (p_lua_next(L, -2)) {
		                                                          // 3 [ ..., EEex_Projectile_Private_GlobalMutators, k, v -> mutatorTableName ]
		LuaTypeContainer retType = func(p_lua_tostring(L, -1), {});
		if (retType.valid && retType.type != LUA_TNIL) {
			p_lua_pop(L, 3);                                      // 0 [ ... ]
			return retType;
		}

		p_lua_pop(L, 1);                                          // 2 [ ..., EEex_Projectile_Private_GlobalMutators, k ]
	}
	                                                              // 1 [ ..., EEex_Projectile_Private_GlobalMutators ]
	p_lua_pop(L, 1);                                              // 0 [ ... ]

	if (!p_lua_isnil(L, projectileMutatorEffectsIndex)) {
		p_lua_pushnil(L);                                         // 1 [ ..., nil ]
		while (p_lua_next(L, projectileMutatorEffectsIndex)) {
			                                                      // 2 [ ..., k, v -> originatingEffect ]
			CGameEffect *const pEffect = *reinterpret_cast<CGameEffect**>(p_lua_touserdata(L, -1));
			char mutatorTableName[9];
			pEffect->m_res.toNullTerminatedStr(mutatorTableName);

			LuaTypeContainer retType = func(mutatorTableName, -1);
			if (retType.valid && retType.type != LUA_TNIL) {
				p_lua_pop(L, 2);                                  // 0 [ ... ]
				return retType;
			}

			p_lua_pop(L, 1);                                      // 1 [ ..., k ]
		}
	}

	return LuaTypeContainer{};
}

void EEex::Projectile_Hook_BeforeAddEffect(
	lua_State* L,
	CProjectile* projectile,
	CGameAIBase* aiBase,
	CGameEffect* effect,
	uintptr_t retPtr)
{
	logStutter<void>("EEex::Projectile_Hook_BeforeAddEffect", [&]() {

		const int myBase = p_lua_gettop(L);

		p_lua_getglobal(L, "EEex_Projectile_Private_AddEffectSources");                                             // 1 [ ..., EEex_Projectile_Private_AddEffectSources ]
		p_lua_pushinteger(L, retPtr);                                                                               // 2 [ ..., EEex_Projectile_Private_AddEffectSources, retPtr ]
		p_lua_rawget(L, -2);                                                                                        // 2 [ ..., EEex_Projectile_Private_AddEffectSources, EEex_Projectile_Private_AddEffectSources[retPtr] -> addEffectSource ]
		p_lua_remove(L, -2);                                                                                        // 1 [ ..., addEffectSource ]

		pushProjectileUD(L, projectile);                                                                            // 2 [ ..., addEffectSource, projectileUD ]
		pushGameObjectUD(L, aiBase);                                                                                // 3 [ ..., addEffectSource, projectileUD, aiBaseUD ]

		if (isSprite(aiBase, true)) {
			getUDAux(L, reinterpret_cast<CGameSprite*>(aiBase)->GetActiveStats());                                  // 4 [ ..., addEffectSource, projectileUD, aiBaseUD, aux(aiBase->GetActiveStats()) -> aiBaseStatsAux ]
			p_lua_pushstring(L, "EEex_ProjectileMutatorEffects");                                                   // 5 [ ..., addEffectSource, projectileUD, aiBaseUD, aiBaseStatsAux, "EEex_ProjectileMutatorEffects" ]
			p_lua_rawget(L, -2);                                                                                    // 5 [ ..., addEffectSource, projectileUD, aiBaseUD, aiBaseStatsAux, aiBaseStatsAux["EEex_ProjectileMutatorEffects"] -> projectileMutatorEffects ]
			p_lua_remove(L, -2);                                                                                    // 4 [ ..., addEffectSource, projectileUD, aiBaseUD, projectileMutatorEffects ]
		}
		else {
			p_lua_pushnil(L);                                                                                       // 4 [ ..., addEffectSource, projectileUD, aiBaseUD, nil -> projectileMutatorEffects]
		}

		tolua_pushusertype_nocast(L, effect, "CGameEffect");                                                        // 5 [ ..., addEffectSource, projectileUD, aiBaseUD, projectileMutatorEffects, effectUD ]

		processMutatorFunctions(L, -2, [&](const char* mutatorTableName, std::optional<int> originatingEffectIndex) -> LuaTypeContainer {
			                                                                                                        // 6 [ ..., addEffectSource, projectileUD, aiBaseUD, projectileMutatorEffects, effectUD, ... ]
			if (originatingEffectIndex.has_value()) {
				originatingEffectIndex = p_lua_absindex(L, *originatingEffectIndex);
			}

			p_lua_newtable(L);                                                                                      // 6 [ ..., addEffectSource, projectileUD, aiBaseUD, projectileMutatorEffects, effectUD, ..., argsT]

			p_lua_pushstring(L, "addEffectSource");                                                                 // 7 [ ..., addEffectSource, projectileUD, aiBaseUD, projectileMutatorEffects, effectUD, ..., argsT, "addEffectSource" ]
			p_lua_pushvalue(L, myBase + 1);                                                                         // 8 [ ..., addEffectSource, projectileUD, aiBaseUD, projectileMutatorEffects, effectUD, ..., argsT, "addEffectSource", addEffectSource ]
			p_lua_rawset(L, -3);                                                                                    // 6 [ ..., addEffectSource, projectileUD, aiBaseUD, projectileMutatorEffects, effectUD, ..., argsT ]

			p_lua_pushstring(L, "projectile");                                                                      // 7 [ ..., addEffectSource, projectileUD, aiBaseUD, projectileMutatorEffects, effectUD, ..., argsT, "projectile" ]
			p_lua_pushvalue(L, myBase + 2);                                                                         // 8 [ ..., addEffectSource, projectileUD, aiBaseUD, projectileMutatorEffects, effectUD, ..., argsT, "projectile", projectileUD ]
			p_lua_rawset(L, -3);                                                                                    // 6 [ ..., addEffectSource, projectileUD, aiBaseUD, projectileMutatorEffects, effectUD, ..., argsT ]

			p_lua_pushstring(L, "originatingSprite");                                                               // 7 [ ..., addEffectSource, projectileUD, aiBaseUD, projectileMutatorEffects, effectUD, ..., argsT, "originatingSprite" ]
			p_lua_pushvalue(L, myBase + 3);                                                                         // 8 [ ..., addEffectSource, projectileUD, aiBaseUD, projectileMutatorEffects, effectUD, ..., argsT, "originatingSprite", aiBaseUD ]
			p_lua_rawset(L, -3);                                                                                    // 6 [ ..., addEffectSource, projectileUD, aiBaseUD, projectileMutatorEffects, effectUD, ..., argsT ]

			p_lua_pushstring(L, "effect");                                                                          // 7 [ ..., addEffectSource, projectileUD, aiBaseUD, projectileMutatorEffects, effectUD, ..., argsT, "effect" ]
			p_lua_pushvalue(L, myBase + 5);                                                                         // 8 [ ..., addEffectSource, projectileUD, aiBaseUD, projectileMutatorEffects, effectUD, ..., argsT, "effect", effectUD ]
			p_lua_rawset(L, -3);                                                                                    // 6 [ ..., addEffectSource, projectileUD, aiBaseUD, projectileMutatorEffects, effectUD, ..., argsT ]

			if (originatingEffectIndex.has_value()) {
				p_lua_pushstring(L, "originatingEffect");                                                           // 7 [ ..., addEffectSource, projectileUD, aiBaseUD, projectileMutatorEffects, effectUD, ..., argsT, "originatingEffect" ]
				p_lua_pushvalue(L, *originatingEffectIndex);                                                        // 8 [ ..., addEffectSource, projectileUD, aiBaseUD, projectileMutatorEffects, effectUD, ..., argsT, "originatingEffect", originatingEffect ]
				p_lua_rawset(L, -3);                                                                                // 6 [ ..., addEffectSource, projectileUD, aiBaseUD, projectileMutatorEffects, effectUD, ..., argsT ]
			}

			LuaTypeContainer blockFurtherMutations = callMutatorFunction(L, mutatorTableName, "effectMutator", -1); // 6 [ ..., addEffectSource, projectileUD, aiBaseUD, projectileMutatorEffects, effectUD, ..., argsT ]
			p_lua_pop(L, 1);                                                                                        // 5 [ ..., addEffectSource, projectileUD, aiBaseUD, projectileMutatorEffects, effectUD, ... ]

			if (blockFurtherMutations.valid && blockFurtherMutations.type != LUA_TNIL) {
				if (blockFurtherMutations.type == LUA_TBOOLEAN) {
					if (blockFurtherMutations.value.boolean) {
						return blockFurtherMutations;
					}
				}
				else {
					Print("[!] op408 (ProjectileMutator) attempted to use an invalid return value from projectileMutator under: \"%s\"", mutatorTableName);
				}
			}

			return LuaTypeContainer{};
		});
		                                                                                                            // 5 [ ..., addEffectSource, projectileUD, aiBaseUD, projectileMutatorEffects, effectUD ]
		p_lua_pop(L, 5);                                                                                            // 0 [ ... ]
	});
}

// Expects: n     [ ..., t, ... ]
// Returns: n + 1 [ ..., t, ..., tCopy ]
void EEex::DeepCopyIndex(lua_State* L, int tIndex) {

	logStutter<void>("EEex::DeepCopyIndex", [&] {

		// Only deep-copying tables
		if (p_lua_type(L, tIndex) != LUA_TTABLE) {
			p_lua_pushvalue(L, tIndex);                 // 1 [ ..., t ]
			return;
		}

		tIndex = p_lua_absindex(L, tIndex);

		// Push return value (tCopy)
		// and processStack.
		p_lua_newtable(L);                              // 1 [ ..., tCopy ]
		p_lua_newtable(L);                              // 2 [ ..., tCopy, processStack ]
		int stackTop = 1;

		// Set initial toFillT (tCopy)
		p_lua_pushvalue(L, -2);                         // 3 [ ..., tCopy, processStack, tCopy -> toFillT ]
		p_lua_rawseti(L, -2, stackTop++);               // 2 [ ..., tCopy, processStack ]

		// Set initial toProcessT (t)
		p_lua_pushvalue(L, tIndex);                     // 3 [ ..., tCopy, processStack, t -> toProcessT ]
		p_lua_rawseti(L, -2, stackTop++);               // 2 [ ..., tCopy, processStack ]

		// Set initial iterK (nil)
		p_lua_pushnil(L);                               // 3 [ ..., tCopy, processStack, nil -> iterK ]
		p_lua_rawseti(L, -2, stackTop++);               // 2 [ ..., tCopy, processStack ]

		while (true) {
		continueOuterWhile:;

			// Read toFillT, toProcessT, and
			// iterK from processStack.
			p_lua_rawgeti(L, -1, stackTop - 3);         // 3 [ ..., tCopy, processStack, toFillT ]
			p_lua_rawgeti(L, -2, stackTop - 2);         // 4 [ ..., tCopy, processStack, toFillT, toProcessT ]
			p_lua_rawgeti(L, -3, stackTop - 1);         // 5 [ ..., tCopy, processStack, toFillT, toProcessT, iterK ]

			while (p_lua_next(L, -2)) {
				                                        // 6 [ ..., tCopy, processStack, toFillT, toProcessT, k, v ]
				if (p_lua_type(L, -1) == LUA_TTABLE) {

					// Save iterK to resume later
					p_lua_pushvalue(L, -2);             // 7 [ ..., tCopy, processStack, toFillT, toProcessT, k, v, k ]
					p_lua_rawseti(L, -6, stackTop - 1); // 6 [ ..., tCopy, processStack, toFillT, toProcessT, k, v ]

					// Set next toFillT ({})
					p_lua_newtable(L);                  // 7 [ ..., tCopy, processStack, toFillT, toProcessT, k, v, nextToFillT ]
					p_lua_rawseti(L, -6, stackTop++);   // 6 [ ..., tCopy, processStack, toFillT, toProcessT, k, v ]

					// Set next toProcessT (v)
					p_lua_pushvalue(L, -1);             // 7 [ ..., tCopy, processStack, toFillT, toProcessT, k, v, nextToProcessT ]
					p_lua_rawseti(L, -6, stackTop++);   // 6 [ ..., tCopy, processStack, toFillT, toProcessT, k, v ]

					// Set next iterK (nil)
					p_lua_pushnil(L);                   // 7 [ ..., tCopy, processStack, toFillT, toProcessT, k, v, nil -> nextIterK ]
					p_lua_rawseti(L, -6, stackTop++);   // 6 [ ..., tCopy, processStack, toFillT, toProcessT, k, v ]

					// Jump to process subtable
					p_lua_pop(L, 4);                    // 2 [ ..., tCopy, processStack ]
					goto continueOuterWhile;
				}
				else {
					// toFillT[iterK] = v
					p_lua_pushvalue(L, -2);             // 7 [ ..., tCopy, processStack, toFillT, toProcessT, k, v, k ]
					p_lua_insert(L, -2);                // 7 [ ..., tCopy, processStack, toFillT, toProcessT, k, k, v ]
					p_lua_rawset(L, -5);                // 5 [ ..., tCopy, processStack, toFillT, toProcessT, k ]
				}
			}
			                                            // 4 [ ..., tCopy, processStack, toFillT, toProcessT ]
			if (stackTop == 4) {
				// The top-level table doesn't have
				// a parent to store its value on,
				// deep copy done.
				p_lua_pop(L, 3);                        // 1 [ ..., tCopy ]
				return;
			}

			// Remove toFillT, toProcessT, and
			// iterK from processStack.
			p_lua_pushnil(L);                           // 5 [ ..., tCopy, processStack, toFillT, toProcessT, nil ]
			p_lua_rawseti(L, -4, --stackTop);           // 4 [ ..., tCopy, processStack, toFillT, toProcessT ]
			p_lua_pushnil(L);                           // 5 [ ..., tCopy, processStack, toFillT, toProcessT, nil ]
			p_lua_rawseti(L, -4, --stackTop);           // 4 [ ..., tCopy, processStack, toFillT, toProcessT ]
			p_lua_pushnil(L);                           // 5 [ ..., tCopy, processStack, toFillT, toProcessT, nil ]
			p_lua_rawseti(L, -4, --stackTop);           // 4 [ ..., tCopy, processStack, toFillT, toProcessT ]

			// parentToFillT[parentIterK] = toFillT
			p_lua_rawgeti(L, -3, stackTop - 3);         // 5 [ ..., tCopy, processStack, toFillT, toProcessT, parentToFillT ]
			p_lua_rawgeti(L, -4, stackTop - 1);         // 6 [ ..., tCopy, processStack, toFillT, toProcessT, parentToFillT, parentIterK ]
			p_lua_pushvalue(L, -4);                     // 7 [ ..., tCopy, processStack, toFillT, toProcessT, parentToFillT, parentIterK, toFillT ]
			p_lua_rawset(L, -3);                        // 5 [ ..., tCopy, processStack, toFillT, toProcessT, parentToFillT ]

			// Continue parent processing
			p_lua_pop(L, 3);                            // 2 [ ..., tCopy, processStack ]
		}
	});
}

void EEex::DeepCopy(lua_State* L) {
	EEex::DeepCopyIndex(L, 1);
	return;
}
