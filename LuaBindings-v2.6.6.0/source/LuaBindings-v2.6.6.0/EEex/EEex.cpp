
#include "Baldur-v2.6.6.0_generated.h"
#include "util.hpp"

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
}

// This is written in C++ for the scenario in which EEex hooks an object's destructor to clean up auxiliary values,
// with the caveat that the destructor is called frequently enough that calling out to Lua is impractical.
// An example would be cleaning up CGameEffect auxiliaries.
void EEex::DestroyUDAux(lua_State* L, void* ptr) {
	p_lua_getglobal(L, "EEex_UserDataAuxiliary"); // 1 [ EEex_UserDataAuxiliary ]
	p_lua_pushlightuserdata(L, ptr);              // 2 [ EEex_UserDataAuxiliary, lud(ptr) ]
	p_lua_pushnil(L);                             // 3 [ EEex_UserDataAuxiliary, lud(ptr), nil ]
	p_lua_rawset(L, -3);                          // 1 [ EEex_UserDataAuxiliary ]
	p_lua_pop(L, 1);                              // 0 [ ]
}

// This should be entirely in C++, though a deepcopy is non-trivial.
// Cheating by calling EEex_Utility_DeepCopy().
void EEex::CopyUDAux(lua_State* L, void* sourcePtr, void* targetPtr) {

	p_lua_getglobal(L, "debug");                  // 1 [ debug ]
	p_lua_getfield(L, -1, "traceback");           // 2 [ debug, traceback ]

	p_lua_getglobal(L, "EEex_UserDataAuxiliary"); // 3 [ debug, traceback, EEex_UserDataAuxiliary ]
	p_lua_pushlightuserdata(L, targetPtr);        // 4 [ debug, traceback, EEex_UserDataAuxiliary, lud(targetPtr) ]

	p_lua_getglobal(L, "EEex_Utility_DeepCopy");  // 5 [ debug, traceback, EEex_UserDataAuxiliary, lud(targetPtr), EEex_Utility_DeepCopy ]

	p_lua_pushlightuserdata(L, sourcePtr);        // 6 [ debug, traceback, EEex_UserDataAuxiliary, lud(targetPtr), EEex_Utility_DeepCopy, lud(sourcePtr) ]
	p_lua_rawget(L, -4);                          // 6 [ debug, traceback, EEex_UserDataAuxiliary, lud(targetPtr), EEex_Utility_DeepCopy, EEex_UserDataAuxiliary[lud(sourcePtr)] ]
 
	if (p_lua_pcallk(L, 1, 1, -5, 0, nullptr) != LUA_OK) {
		                                          // 5 [ debug, traceback, EEex_UserDataAuxiliary, lud(targetPtr), errorMessage ]
		Print("[!] %s\n", p_lua_tostring(L, -1));
		p_lua_pop(L, 5);                          // 0 [ ]
	}
	else {
		                                          // 5 [ debug, traceback, EEex_UserDataAuxiliary, lud(targetPtr), copyT ]
		p_lua_rawset(L, -3);                      // 3 [ debug, traceback, EEex_UserDataAuxiliary ]
		p_lua_pop(L, 3);                          // 0 [ ]
	}
}
