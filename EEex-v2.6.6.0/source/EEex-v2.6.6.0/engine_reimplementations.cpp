
#define _USE_MATH_DEFINES
#include <math.h>

#include "Baldur-v2.6.6.0_generated.h"
#include "util.hpp"

byte GetSpritePersonalSpace(CGameSprite* pSprite)
{
	return (pSprite->m_animation.m_overrides & 4) == 0
		? pSprite->m_animation.m_animation->virtual_GetPersonalSpace()
		: pSprite->m_animation.m_personalSpace;
}

void CAIGroup::Override_GroupSetTarget(CPoint target, int additive, ushort formationType, CPoint cursor)
{
	if (formationType == 0) {
		this->FollowLeader(target, additive);
		return;
	}

	if (abs(target.x - cursor.x) < 12 && abs(target.y - cursor.y) < 9)
	{
		cursor.x = -1;
		cursor.y = -1;
	}

	CTypedPtrList<CPtrList, long>& memberList { this->m_memberList };
	CInfGame& pGame { *(*p_g_pBaldurChitin)->m_pObjectGame };
	CGameArea& pVisibleArea { *pGame.m_gameAreas[pGame.m_visibleArea] };
	CSearchBitmap* pSearchMap { &pVisibleArea.m_search };

	if (memberList.m_nCount == 0) {
		return;
	}

	if (memberList.m_nCount == 1)
	{
		CGameSprite* pSprite { };
		if (CGameObjectArray::GetShare(memberList.m_pNodeHead->data, reinterpret_cast<CGameObject**>(&pSprite))) {
			return;
		}

		CGameArea* pSpriteArea { pSprite->m_pArea };
		CDerivedStats& pStats { *pSprite->GetActiveStats() };

		if (pStats.m_nEncumberance == 2)
		{
			EngineVal<CString> temp { "" };
			pSprite->FeedBack(0xF, 1, 0, 0, -1, 0, &*temp);
			return;
		}

		if (pStats.m_nEncumberance == 1)
		{
			EngineVal<CString> temp { "" };
			pSprite->FeedBack(0xE, 1, 0, 0, -1, 0, &*temp);
		}

		CPoint targetGrid { target.x / 16, target.y / 12 };
		CPoint spriteGrid { pSprite->m_pos.x / 16, pSprite->m_pos.y / 12 };
		CPoint finalTarget { target.x, target.y };

		if (targetGrid.x != spriteGrid.x || targetGrid.y != spriteGrid.y)
		{
			if (pSpriteArea == nullptr) {
				return;
			}

			this->RemoveFromSearch(pSearchMap);

			CPoint targetGridAdjust { targetGrid.x, targetGrid.y };
			if (!pSpriteArea->AdjustTarget(spriteGrid, &targetGridAdjust, GetSpritePersonalSpace(pSprite), 10))
			{
				this->AddToSearch(pSearchMap);
				return;
			}

			this->AddToSearch(pSearchMap);

			if (targetGrid.x != targetGridAdjust.x || targetGrid.y != targetGridAdjust.y)
			{
				finalTarget.x = targetGridAdjust.x * 16 + 8;
				finalTarget.y = targetGridAdjust.y * 12 + 6;
			}
		}

		EngineVal<CAIAction> moveToPoint { 23, &finalTarget, 0, -1 };
		pSprite->m_userCommandPause = 75;
		pSprite->m_triggerId = -1;

		if (additive == 0)
		{
			pSprite->virtual_AddAction(&*moveToPoint);
			pSprite->m_interrupt = 1;
		}
		else
		{
			pSprite->virtual_InsertAction(&*moveToPoint);
			if (pSprite->m_curAction.m_actionID != 23) {
				pSprite->m_interrupt = 1;
			}
		}

		pSprite->PlaySound(22, 1, 0, 0);
		return;
	}

	this->RemoveFromSearch(pSearchMap);

	CPoint curTargetPoint { target.x, target.y };
	byte nCharacter { 0 };
	CPoint* offsets { };
	short* facings { };
	EngineVal<CTypedPtrList<CPtrList, EngineVal<CAIAction>*>> actionList { 10 };

	CTypedPtrList<CPtrList, long>::CNode* memberNode { memberList.m_pNodeHead };
	while (memberNode != nullptr)
	{
		CGameSprite* pSprite { };
		byte shareResult { CGameObjectArray::GetShare(memberNode->data, reinterpret_cast<CGameObject**>(&pSprite)) };
		memberNode = memberNode->pNext;

		if (shareResult) {
			continue;
		}

		CGameArea* pSpriteArea { pSprite->m_pArea };
		CPoint spritePosGrid { pSprite->m_pos.x / 16, pSprite->m_pos.y / 12 };
		byte spritePersonalSpace { GetSpritePersonalSpace(pSprite) };

		if (nCharacter == 0)
		{
			pSprite->PlaySound(22, 1, 0, 0);

			CPoint& origin { cursor.x == -1 && cursor.y == -1
				? pSprite->m_pos
				: cursor };

			int xDiff { curTargetPoint.x - origin.x };
			int yDiff { curTargetPoint.y - origin.y };
			double radians { acos(abs(xDiff) / (double)(int)sqrtf((float)(xDiff * xDiff + yDiff * yDiff))) };

			if (xDiff < 0)
			{
				if (yDiff < 0) {
					radians += M_PI;
				}
				else {
					radians = M_PI - radians;
				}
			}
			else if (yDiff < 0) {
				radians = 2 * M_PI - radians;
			}

			short direction { (90 - (short)(radians * -360 / (2 * M_PI))) % 360 };
			offsets = this->GetOffsets(formationType, direction, 0);
			facings = this->GetFacings(formationType, direction);

			CPoint curTargetPointGrid { curTargetPoint.x / 16, curTargetPoint.y / 12 };
			if (curTargetPointGrid.x != spritePosGrid.x || curTargetPointGrid.y != spritePosGrid.y)
			{
				if (pSpriteArea == nullptr)
				{
					this->AddToSearch(pSearchMap);
					break;
				}

				// Adjust clicked target towards group leader with tolerance of 10
				// if failed to find valid map location, abort everything.
				CPoint curTargetPointGridAdjusted { curTargetPointGrid.x, curTargetPointGrid.y };
				if (!pSpriteArea->AdjustTarget(spritePosGrid, &curTargetPointGridAdjusted, spritePersonalSpace, 10))
				{
					this->AddToSearch(pSearchMap);
					break;
				}

				if (curTargetPointGrid.x != curTargetPointGridAdjusted.x || curTargetPointGrid.y != curTargetPointGridAdjusted.y)
				{
					curTargetPoint.x = curTargetPointGridAdjusted.x * 16 + 8;
					curTargetPoint.y = curTargetPointGridAdjusted.y * 12 + 6;
				}
			}
		}

		CPoint& curPointOffset { *(offsets + nCharacter) };
		int curPointOffsetX { curPointOffset.x * 16 / 1000 };
		int curPointOffsetY { curPointOffset.y * 12 / 1000 };

		CPoint facePoint { -1, -1 };
		actionList->AddTail(new EngineVal<CAIAction>{ 84, &facePoint, *(facings + nCharacter), -1 });

		// Apply formation offsets
		CPoint curTargetPointOffset { curTargetPoint.x + curPointOffsetX, curTargetPoint.y + curPointOffsetY };
		CPoint curTargetPointOffsetGrid { curTargetPointOffset.x / 16, curTargetPointOffset.y / 12 };

		// If offset put the target in an invalid location, just use the main target point
		if (pSpriteArea != nullptr
			&& (curTargetPointOffsetGrid.x != spritePosGrid.x || curTargetPointOffsetGrid.y != spritePosGrid.y)
			&& !pSpriteArea->AdjustTarget(spritePosGrid, &curTargetPointOffsetGrid, spritePersonalSpace, 1))
		{
			curTargetPointOffset.x = curTargetPoint.x;
			curTargetPointOffset.y = curTargetPoint.y;
		}

		if (false)
		{
			// This whole block seems to have no effect
			if (!pSpriteArea->CheckWalkable(&pSprite->m_pos, &curTargetPointOffset, pSprite->virtual_GetVisibleTerrainTable(), spritePersonalSpace, 0))
			{
				bool done { false };

				int curOffsetX { abs(curPointOffsetX) };
				int curOffsetXNegative { -curOffsetX };
				do
				{
					if (done) { break; }

					int curOffsetY { abs(curPointOffsetY) };
					int curOffsetYNegative { -curOffsetY };

					do
					{
						if (done) { break; }

						CPoint tempAdjust { curOffsetX >= 0 ? curOffsetX : curOffsetXNegative, curOffsetY >= 0 ? curOffsetY : curOffsetYNegative };
						tempAdjust.x += curTargetPointOffset.x / 16;
						tempAdjust.y += curTargetPointOffset.y / 12;

						if (pSpriteArea->AdjustTarget(spritePosGrid, &tempAdjust, spritePersonalSpace, 1)) {
							done = true;
						}

						++curOffsetYNegative;
						--curOffsetY;
					}
					while (curOffsetY >= 0);

					--curOffsetX;
					++curOffsetXNegative;
				}
				while (curOffsetX >= 0);
			}
		}

		CDerivedStats* pStats { pSprite->GetActiveStats() };

		if (pStats->m_nEncumberance == 2)
		{
			EngineVal<CString> temp { "" };
			pSprite->FeedBack(0xF, 1, 0, 0, -1, 0, &*temp);
		}
		else
		{
			if (pStats->m_nEncumberance == 1)
			{
				EngineVal<CString> temp { "" };
				pSprite->FeedBack(0xE, 1, 0, 0, -1, 0, &*temp);
			}

			// MoveToPoint
			actionList->AddTail(new EngineVal<CAIAction>{ 23, &curTargetPointOffset, 0, -1 });

			if (pGame.m_worldTime.m_active)
			{
				// SmallWait
				CPoint temp { -1, -1 };
				actionList->AddTail(new EngineVal<CAIAction>{ 83, &temp, ((rand() & 0x7FFF) * 7) >> 0xF, -1});
			}

			pSprite->m_userCommandPause = 75;
			pSprite->m_triggerId = -1;

			if (additive)
			{
				pSprite->m_interrupt = 1;
				while (actionList->m_nCount != 0)
				{
					EngineVal<CAIAction>* pAction { actionList->RemoveHead() };
					pSprite->virtual_AddAction(&**pAction);
					delete pAction;
				}
			}
			else
			{
				short curActionID { pSprite->m_curAction.m_actionID };
				if (curActionID != 23 && curActionID != 83 && curActionID != 84)
				{
					pSprite->m_interrupt = 1;
				}

				while (actionList->m_nCount != 0)
				{
					EngineVal<CAIAction>* pAction { actionList->RemoveHead() };
					pSprite->virtual_InsertAction(&**pAction);
					delete pAction;
				}
			}
		}

		pSprite->m_inFormation = 1;
		pSprite->m_groupMove = 0;

		if (nCharacter < 6) {
			++nCharacter;
		}
	}

	free(offsets);
	free(facings);

	this->AddToSearch(pSearchMap);
}

int CGameArea::Override_AdjustTarget(CPoint start, CPoint* goal, byte personalSpace, short tolerance)
{
	int startX { start.x };
	int startY { start.y };

	CPoint curGoal { goal->x, goal->y };

	if (curGoal.x != startX || curGoal.y != startY)
	{
		int xDiff { startX - curGoal.x };
		int xDiffAbs { abs(xDiff) };
		int yDiff { startY - curGoal.y };
		int yDiffAbs { abs(yDiff) };

		int xStepExact;
		int yStepExact;

		if (yDiffAbs < xDiffAbs)
		{
			xStepExact = curGoal.x < startX ? 0x400 : -0x400;
			yStepExact = yDiff * 0x400 / xDiffAbs;
		}
		else
		{
			xStepExact = xDiff * 0x400 / yDiffAbs;
			yStepExact = curGoal.y < startY ? 0x400 : -0x400;
		}

		int goalXExact { curGoal.x * 0x400 + 0x200 };
		int goalYExact { curGoal.y * 0x400 + 0x200 };

		while (true)
		{
			if (curGoal.x == startX && curGoal.y == startY) {
				return 0;
			}

			if (tolerance < 1) {
				return 0;
			}

			if (int mapIndex { (curGoal.x * 0x10 + 8) / 0x20 + (curGoal.y * 0xC + 6) / 0x20 * this->m_visibility.m_nWidth };
				mapIndex >= 0 && mapIndex < this->m_visibility.m_nMapSize && (this->m_visibility.m_pMap[mapIndex] & 0x8000) != 0)
			{
				if (ushort temp; this->m_search.GetCost(&curGoal, CGameObject::p_DEFAULT_TERRAIN_TABLE->data, personalSpace, &temp, 1) != 0xFF) {
					break;
				}
			}

			goalXExact += xStepExact;
			goalYExact += yStepExact;

			curGoal.x = goalXExact / 0x400;
			curGoal.y = goalYExact / 0x400;
			--tolerance;
		}

		if (curGoal.x != startX || curGoal.y != startY)
		{
			goal->x = curGoal.x;
			goal->y = curGoal.y;
			return 1;
		}
	}

	return 0;
}

enum class CheckNearestShortCircuitCallbackResult
{
	SHORT_CIRCUIT = 0,
	SKIP = 1,
	CONTINUE = 2,
};

typedef CheckNearestShortCircuitCallbackResult(*CheckNearestShortCircuitCallback)(int range, int yDiff);

CheckNearestShortCircuitCallbackResult checkNearestForwardCallback(int range, int yDiff)
{
	if (yDiff >= 0)
	{
		if (yDiff > range) {
			return CheckNearestShortCircuitCallbackResult::SHORT_CIRCUIT;
		}
	}
	else if (-yDiff > range) {
		return CheckNearestShortCircuitCallbackResult::SKIP;
	}
	return CheckNearestShortCircuitCallbackResult::CONTINUE;
}

CheckNearestShortCircuitCallbackResult checkNearestBackwardCallback(int range, int yDiff)
{
	if (yDiff < 0)
	{
		if (-yDiff > range) {
			return CheckNearestShortCircuitCallbackResult::SHORT_CIRCUIT;
		}
	}
	else if (yDiff > range) {
		return CheckNearestShortCircuitCallbackResult::SKIP;
	}
	return CheckNearestShortCircuitCallbackResult::CONTINUE;
}

int CGameArea::Override_GetNearest2(CPoint center, const CAIObjectType* type, short range,
	const byte* terrainTable, int lineOfSight, int seeInvisible, byte nNearest)
{
	const short arraySize { static_cast<short>(nNearest) + 1 };
	int *const idArray { reinterpret_cast<int*>(alloca(sizeof(int) * arraySize * 2)) };
	int *const distanceArray { idArray + arraySize };

	for (short i { 0 }; i <= nNearest; ++i) {
		idArray[i] = -1;
		distanceArray[i] = INT_MAX;
	}

	const CPoint centerAdj { center.x, center.y * 4/3 };
	const int rangeSquared { square(range) };

	CTypedPtrList<CPtrList,long>::CNode* pNode { this->m_lVertSort.m_pNodeHead };

	while (pNode != nullptr)
	{
		const int objectID { pNode->data };
		pNode = pNode->pNext;

		CGameObject* object;
		if (CGameObjectArray::GetShare(objectID, &object) != 0) {
			continue;
		}

		const CPoint& objectPos { object->m_pos };
		const CPoint objectPosAdj { objectPos.x, objectPos.y * 4/3 };

		const int yDiff { objectPosAdj.y - centerAdj.y };

		// Short-circuit loop based on the sorted nature of m_lVertSort
		if (CheckNearestShortCircuitCallbackResult result { checkNearestForwardCallback(range, yDiff) };
			result == CheckNearestShortCircuitCallbackResult::SHORT_CIRCUIT)
		{
			break;
		}
		else if (result == CheckNearestShortCircuitCallbackResult::SKIP) {
			continue;
		}

		const int distanceSquared { square(objectPosAdj.x - centerAdj.x) + square(yDiff) };
		if (distanceSquared > rangeSquared) {
			continue;
		}

		if (object->virtual_GetObjectType() == CGameObjectType::SPRITE)
		{
			CGameSprite& sprite { *reinterpret_cast<CGameSprite*>(object) };
			CDerivedStats& stats { *sprite.GetActiveStats() };

			if (!sprite.m_active || !sprite.m_activeAI || !sprite.m_activeImprisonment
				|| (!seeInvisible && ((stats.m_generalState & 0x10) != 0 || stats.m_bSanctuary))
				|| !sprite.m_animation.m_animation->virtual_GetAboveGround())
			{
				continue;
			}
		}

		if (!object->virtual_GetAIType()->OfType(type, 0, 0, 0)
			|| (lineOfSight && !this->CheckLOS(&center, &objectPos, terrainTable, 0, 0)))
		{
			continue;
		}

		for (short i { 0 }; i <= nNearest; ++i)
		{
			if (distanceSquared < distanceArray[i])
			{
				const short slotsAfter { nNearest - i };
				memmove(&idArray[i + 1], &idArray[i], sizeof(int) * slotsAfter);
				memmove(&distanceArray[i + 1], &distanceArray[i], sizeof(int) * slotsAfter);
				idArray[i] = object->m_id;
				distanceArray[i] = distanceSquared;
				break;
			}
		}
	}

	const int returnVal { idArray[nNearest] };
	return nNearest == 0 || returnVal != -1
		? returnVal
		: 0;
}

bool checkNearest(
	// Loop data
	const CheckNearestShortCircuitCallback shortCircuitCallback, int *const idArray, int *const distanceArray, const short nArray,
	// Area data
	CGameArea& area, const byte *const terrainTable,
	// Checking object
	const int objectID,
	// Caller data
	const CAIObjectType& callerType, const CPoint& callerPos, const CPoint& callerPosAdj,
	// Restrictions
	const short range, const int rangeSquared, const CAIObjectType& matchType, const bool bCheckLOS,
	const bool bSeeInvisible, const bool bIgnoreSleeping, const bool bIgnoreDead)
{
	CGameObject* object;
	if (CGameObjectArray::GetShare(objectID, &object) != 0) {
		return false;
	}

	if (object->virtual_GetVertListPos() == nullptr) {
		return false;
	}

	const CPoint& objectPos { object->m_pos };
	const CPoint objectPosAdj { objectPos.x, objectPos.y * 4/3 };

	const int yDiff { objectPosAdj.y - callerPosAdj.y };

	// Short-circuit loop based on the sorted nature of m_lVertSort
	if (CheckNearestShortCircuitCallbackResult result { shortCircuitCallback(range, yDiff) };
		result == CheckNearestShortCircuitCallbackResult::SHORT_CIRCUIT)
	{
		return true;
	}
	else if (result == CheckNearestShortCircuitCallbackResult::SKIP) {
		return false;
	}

	const int distanceSquared { square(objectPosAdj.x - callerPosAdj.x) + square(yDiff) };
	if (distanceSquared > rangeSquared) {
		return false;
	}

	if (object->virtual_GetObjectType() == CGameObjectType::SPRITE)
	{
		CGameSprite& sprite { *reinterpret_cast<CGameSprite*>(object) };
		CDerivedStats& stats { *sprite.GetActiveStats() };
		const uint generalState { stats.m_generalState };

		if (!sprite.m_active || !sprite.m_activeAI || !sprite.m_activeImprisonment
			|| (!bSeeInvisible && ((generalState & 0x10) != 0 || stats.m_bSanctuary))
			|| (bIgnoreSleeping && (generalState & 1) != 0)
			|| (bIgnoreDead && (generalState & 0x800) != 0)
			|| !sprite.m_animation.m_animation->virtual_GetAboveGround()
			|| stats.m_cImmunitiesAIType.OnList(&callerType))
		{
			return false;
		}
	}

	if (!object->virtual_GetAIType()->OfType(&matchType, 0, 0, 0)
		|| (bCheckLOS && !area.CheckLOS(&callerPos, &objectPos, terrainTable, 0, 0)))
	{
		return false;
	}

	for (short i { 0 }; i <= nArray; ++i)
	{
		if (distanceSquared < distanceArray[i])
		{
			const short slotsAfter { nArray - i };
			memmove(&idArray[i + 1], &idArray[i], sizeof(int) * slotsAfter);
			memmove(&distanceArray[i + 1], &distanceArray[i], sizeof(int) * slotsAfter);
			idArray[i] = object->m_id;
			distanceArray[i] = distanceSquared;
			return false;
		}
	}

	return false;
}

int CGameArea::Override_GetNearest(int startObject, const CAIObjectType* type, short range, const byte* terrainTable,
	int checkLOS, int seeInvisible, int ignoreSleeping, byte nNearest, int ignoreDead)
{
	CGameObject* pCaller { };
	if (CGameObjectArray::GetShare(startObject, &pCaller) != 0) {
		return -1;
	}

	if (pCaller->virtual_GetVertListType() != VertListType::LIST_FRONT) {
		return this->GetNearest(pCaller->m_pos, type, range, terrainTable, checkLOS, seeInvisible, nNearest);
	}

	const CTypedPtrList<CPtrList,long>::CNode *const pVertListPos { pCaller->virtual_GetVertListPos() };
	if (pVertListPos == nullptr) {
		return -1;
	}

	const short arraySize { static_cast<short>(nNearest) + 1 };
	int *const idArray { reinterpret_cast<int*>(alloca(sizeof(int) * arraySize * 2)) };
	int *const distanceArray { idArray + arraySize };

	for (short i { 0 }; i <= nNearest; ++i) {
		idArray[i] = -1;
		distanceArray[i] = INT_MAX;
	}

	const CAIObjectType& callerType { *pCaller->virtual_GetAIType() };
	const CPoint& callerPos { pCaller->m_pos };
	const CPoint callerPosAdj { callerPos.x, callerPos.y * 4/3 };

	const int rangeSquared { square(range) };

	CTypedPtrList<CPtrList,long>::CNode* pPrevNode { pVertListPos->pPrev };
	CTypedPtrList<CPtrList,long>::CNode* pNextNode { pVertListPos->pNext };

	while (pPrevNode != nullptr || pNextNode != nullptr)
	{
		if (pPrevNode != nullptr)
		{
			if (checkNearest(
				// Loop data
				checkNearestBackwardCallback, idArray, distanceArray, nNearest,
				// Area data
				*this, terrainTable,
				// // Checking object
				pPrevNode->data,
				// Caller data
				callerType, callerPos, callerPosAdj,
				// Restrictions
				range, rangeSquared, *type, checkLOS, seeInvisible, ignoreSleeping, ignoreDead))
			{
				pPrevNode = nullptr;
			}
			else {
				pPrevNode = pPrevNode->pPrev;
			}
		}

		if (pNextNode != nullptr)
		{
			if (checkNearest(
				// Loop data
				checkNearestForwardCallback, idArray, distanceArray, nNearest,
				// Area data
				*this, terrainTable,
				// // Checking object
				pNextNode->data,
				// Caller data
				callerType, callerPos, callerPosAdj,
				// Restrictions
				range, rangeSquared, *type, checkLOS, seeInvisible, ignoreSleeping, ignoreDead))
			{
				pNextNode = nullptr;
			}
			else {
				pNextNode = pNextNode->pNext;
			}
		}
	}

	const int returnVal { idArray[nNearest] };
	return nNearest == 0 || returnVal != -1
		? returnVal
		: 0;
}

int Reference_CAICondition_Hold(CAICondition* pThis, CTypedPtrList<CPtrList, CAITrigger*>* pTriggerList, CGameAIBase* pCaller)
{
	auto pNode = pThis->m_triggerList.m_pNodeHead;
	if (pNode == nullptr) {
		return 1;
	}

	int nRet = 0;
	int nORCounter = 0;

	bool bNextTriggerObject = false;
	CGameAIBase* pNextTriggerObject = nullptr;

	do
	{
		if (nORCounter <= 0) {
			nRet = 0;
		}

		CAITrigger* const pTrigger = pNode->data;
		const short nTriggerID = pTrigger->m_triggerID;

		if (nTriggerID == 0x4089) // OR
		{
			nORCounter = pTrigger->m_specificID;
		}
		else if (nTriggerID == 0x40E0) // NextTriggerObject
		{
			EngineVal<CAIObjectType> nextTriggerObjectType{ &pTrigger->m_triggerCause };
			nextTriggerObjectType->Decode(pCaller);

			bNextTriggerObject = true;
			pNextTriggerObject = reinterpret_cast<CGameAIBase*>(nextTriggerObjectType->GetShareType(pCaller, CGameObjectType::AIBASE, 0));

			if (pNextTriggerObject != nullptr && nORCounter < 1) {
				nRet = 1;
			}
		}
		else {
			--nORCounter;
		}

		if (nTriggerID != 0x40E0) // NOT NextTriggerObject
		{
			if (bNextTriggerObject)
			{
				if (pNextTriggerObject != nullptr)
				{
					bNextTriggerObject = false;
					nRet |= pThis->TriggerHolds(pTrigger, pTriggerList, pNextTriggerObject);
				}
			}
			else
			{
				nRet |= pThis->TriggerHolds(pTrigger, pTriggerList, pCaller);
			}
		}

		if (nRet == 0 && nORCounter < 1) // Fail
		{
			break;
		}

		pNode = pNode->pNext;
	} while (pNode != nullptr);

	return nRet;
}

int Reference_CAICondition_TriggerHolds(CAICondition* pThis, CAITrigger* pTrigger, CTypedPtrList<CPtrList, CAITrigger*>* pTriggerList, CGameAIBase* pCaller)
{
	bool nRet = false;

	if ((pTrigger->m_triggerID & 0x4000) == 0) // Event-driven trigger
	{
		for (auto pNode = pTriggerList->m_pNodeHead; pNode != nullptr; pNode = pNode->pNext)
		{
			pTrigger->m_triggerCause.Decode(pCaller);
			nRet = pNode->data->OfType(pTrigger);

			if ((pTrigger->m_flags & 1) != 0) // Inverted
			{
				nRet = !nRet;
			}

			if (nRet) {
				break;
			}
		}
	}
	else // Status trigger
	{
		nRet = pCaller->virtual_EvaluateStatusTrigger(pTrigger);

		if ((pTrigger->m_flags & 1) != 0) // Inverted
		{
			nRet = !nRet;
		}
	}

	return nRet;
}

void Reference_CMessageSetLastObject_Run(CMessageSetLastObject* pThis) {

	CGameObject* pObject;
	if
	(
		CGameObjectArray::GetShare(pThis->m_targetId, &pObject) != 0
		||
		(pObject->virtual_GetObjectType() & CGameObjectType::AIBASE) == 0
	)
	{
		return;
	}

	if (pObject->virtual_GetObjectType() == CGameObjectType::SPRITE) {
		CGameSprite *const pSprite = reinterpret_cast<CGameSprite*>(pObject);
		if ((pSprite->m_derivedStats.m_generalState & 0x80) != 0 || (pSprite->m_baseStats.m_generalState & 0x80) != 0) {
			// STONE_DEATH
			return;
		}
	}

	CGameAIBase *const pAIBase = reinterpret_cast<CGameAIBase*>(pObject);

	switch (pThis->m_type) {
		case 0x0002: { // AttackedBy
			pAIBase->m_lAttacker.Set(&pThis->m_lAttacker);
			pAIBase->m_lAttackerSent.Set(&pThis->m_lAttacker);
			break;
		}
		case 0x0003: { // Help
			pAIBase->m_lHelp.Set(&pThis->m_lAttacker);
			pAIBase->m_lHelpSent.Set(&pThis->m_lAttacker);
			break;
		}
		case 0x0006: { // ReceivedOrder
			pAIBase->m_lOrderedBy.Set(&pThis->m_lAttacker);
			pAIBase->m_lOrderedBySent.Set(&pThis->m_lAttacker);
			break;
		}
		case 0x0007: { // Said
			pAIBase->m_lTalkedTo.Set(&pThis->m_lAttacker);
			pAIBase->m_lTalkedToSent.Set(&pThis->m_lAttacker);
			break;
		}
		case 0x0020: { // HitBy
			pAIBase->m_lHitter.Set(&pThis->m_lAttacker);
			pAIBase->m_lHitterSent.Set(&pThis->m_lAttacker);
			break;
		}
		case 0x002F: { // Heard
			pAIBase->m_lHeard.Set(&pThis->m_lAttacker);
			pAIBase->m_lHeardSent.Set(&pThis->m_lAttacker);
			break;
		}
		case 0x004B: { // Killed
			pAIBase->m_lKilled.Set(&pThis->m_lAttacker);
			pAIBase->m_lKilledSent.Set(&pThis->m_lAttacker);
			break;
		}
		case 0x0097: { // Summoned
			pAIBase->m_lSummonedBy.Set(&pThis->m_lAttacker);
			pAIBase->m_lSummonedBySent.Set(&pThis->m_lAttacker);
			break;
		}
		case 0x401C: { // See
			pAIBase->m_lSeen.Set(&pThis->m_lAttacker);
			pAIBase->m_lSeenSent.Set(&pThis->m_lAttacker);
			break;
		}
		default: {
			pAIBase->m_lTrigger.Set(&pThis->m_lAttacker);
			pAIBase->m_lTriggerSent.Set(&pThis->m_lAttacker);
			break;
		}
	}
}

void Reference_CGameAIBase_SetTrigger(CGameAIBase* pThis, const CAITrigger* pTrigger) {

	CAITrigger *const pTriggerCopy = newEngineObj<CAITrigger>(pTrigger);

	pThis->m_pendingTriggers.AddTail(pTriggerCopy);
	pThis->m_bNewTrigger = 1;

	if ((pTriggerCopy->m_flags & 4) != 0) {
		return;
	}
	pTriggerCopy->m_flags |= 4;

	CInfGame *const pGame = (*p_g_pBaldurChitin)->m_pObjectGame;

	switch (pTriggerCopy->m_triggerID) {

		case 0x0002: { // AttackedBy

			pThis->virtual_AutoPause(2);

			CGameSprite* pSprite = reinterpret_cast<CGameSprite*>(pTriggerCopy->m_triggerCause.GetShareType(pThis, CGameObjectType::SPRITE, 0));
			if (pSprite != nullptr) {
				// I don't know why the engine repeats this
				pSprite = reinterpret_cast<CGameSprite*>(pTriggerCopy->m_triggerCause.GetShareType(pThis, CGameObjectType::SPRITE, 0));
				if ((pSprite->GetActiveStats()->m_generalState & 0x800) != 0) {
					break;
				}
			}

			pThis->m_lAttackStyle = pTriggerCopy->m_specificID;
			if
			(
				pThis->m_lAttacker != &pTriggerCopy->m_triggerCause
				&&
				(
					pGame->GetCharacterPortraitNum(pThis->m_id) == -1
					||
					pGame->GetCharacterPortraitNum(pTriggerCopy->m_triggerCause.m_Instance) == -1
				)
			)
			{
				pThis->m_lAttacker.Set(&pTriggerCopy->m_triggerCause);
			}
			break;
		}
		case 0x0003: { // Help
			if (pThis->m_lHelp != &pTriggerCopy->m_triggerCause) {
				pThis->m_lHelp.Set(&pTriggerCopy->m_triggerCause);
			}
			break;
		}
		case 0x0006: { // ReceivedOrder
			if (pThis->m_lOrderedBy != &pTriggerCopy->m_triggerCause) {
				pThis->m_lOrderedBy.Set(&pTriggerCopy->m_triggerCause);
			}
			break;
		}
		case 0x0007: { // Said
			if (pThis->m_lTalkedTo != &pTriggerCopy->m_triggerCause) {
				pThis->m_lTalkedTo.Set(&pTriggerCopy->m_triggerCause);
			}
			break;
		}
		case 0x0020: { // HitBy

			pThis->virtual_AutoPause(4);
			pThis->m_lAttackStyle = pTriggerCopy->m_specificID;

			if (pThis->m_lHitter != &pTriggerCopy->m_triggerCause) {
				pThis->m_lHitter.Set(&pTriggerCopy->m_triggerCause);
			}
			break;
		}
		case 0x002F: { // Heard
			if (pThis->m_lHeard != &pTriggerCopy->m_triggerCause) {
				pThis->m_lHeard.Set(&pTriggerCopy->m_triggerCause);
			}
			break;
		}
		case 0x004C: { // Entered
			if (pThis->virtual_GetObjectType() == CGameObjectType::TRIGGER) {
				CGameTrigger *const pTrigger = reinterpret_cast<CGameTrigger*>(pThis);
				if ((pTrigger->m_dwFlags & 2) == 0) {
					pTrigger->SetDrawPoly(0);
				}
			}
			break;
		}
		case 0x0052: { // Opened
			if (pThis->virtual_GetObjectType() == CGameObjectType::DOOR) {
				CGameDoor *const pDoor = reinterpret_cast<CGameDoor*>(pThis);
				if ((pDoor->m_dwFlags & 4) == 0) {
					pDoor->SetDrawPoly(0);
				}
			}
			else {
				if (pThis->virtual_GetObjectType() == CGameObjectType::CONTAINER) {
					CGameContainer *const pContainer = reinterpret_cast<CGameContainer*>(pThis);
					if ((pContainer->m_dwFlags & 8) == 0) {
						pContainer->SetDrawPoly(0);
					}
				}
			}
			break;
		}
		case 0x0097: { // Summoned
			if (pThis->m_lSummonedBy != &pTriggerCopy->m_triggerCause) {
				pThis->m_lSummonedBy.Set(&pTriggerCopy->m_triggerCause);
			}
			break;
		}
	}

	if (pGame->SAVE_OBJECT_LIST.Find(pTriggerCopy->m_triggerID) != nullptr && pThis->m_lTrigger != &pTriggerCopy->m_triggerCause) {
		pThis->m_lTrigger.Set(&pTriggerCopy->m_triggerCause);
	}

	if (pThis->virtual_GetObjectType() == CGameObjectType::SPRITE) {
		CGameSprite *const pSprite = reinterpret_cast<CGameSprite*>(pThis);
		pSprite->GetActiveStats()->m_cContingencyList.ProcessTrigger(pSprite, pTriggerCopy);
	}
}

void Reference_CGameAIBase_ApplyTriggers(CGameAIBase* pThis) {

	CBaldurChitin *const pBaldurChitin = *p_g_pBaldurChitin;
	CInfGame *const pGame = pBaldurChitin->m_pObjectGame;

	if (pGame->m_worldTime.m_gameTime % 3600 == 0) {
		CMessageUpdateReaction *const pMessage = newEngineObj<CMessageUpdateReaction>(11, pThis->m_id, pThis->m_id);
		pBaldurChitin->m_cMessageHandler.AddMessage(pMessage, 0);
	}

	if (pThis->virtual_GetObjectType() == CGameObjectType::SPRITE) {
		CGameSprite *const pSprite = reinterpret_cast<CGameSprite*>(pThis);
		pSprite->GetActiveStats()->m_cContingencyList.Process(pSprite);
	}

	for (auto pNode = pThis->m_pendingTriggers.m_pNodeHead; pNode != nullptr; pNode = pNode->pNext) {

		CAITrigger *const pTrigger = pNode->data;
		if ((pTrigger->m_flags & 4) != 0) {
			continue;
		}
		pTrigger->m_flags |= 4;

		switch (pTrigger->m_triggerID) {

			case 0x0002: { // AttackedBy

				pThis->virtual_AutoPause(2);
				pThis->m_lAttackStyle = pTrigger->m_specificID;

				if
				(
					pThis->m_lAttacker != &pTrigger->m_triggerCause
					&&
					(
						pGame->GetCharacterPortraitNum(pThis->m_id) == -1
						||
						pGame->GetCharacterPortraitNum(pTrigger->m_triggerCause.m_Instance) == -1
					)
				)
				{
					pThis->m_lAttacker.Set(&pTrigger->m_triggerCause);
				}
				break;
			}
			case 0x0003: { // Help
				if (pThis->m_lHelp != &pTrigger->m_triggerCause) {
					pThis->m_lHelp.Set(&pTrigger->m_triggerCause);
				}
				break;
			}
			case 0x0006: { // ReceivedOrder
				if (pThis->m_lOrderedBy != &pTrigger->m_triggerCause) {
					pThis->m_lOrderedBy.Set(&pTrigger->m_triggerCause);
				}
				break;
			}
			case 0x0007: { // Said
				if (pThis->m_lTalkedTo != &pTrigger->m_triggerCause) {
					pThis->m_lTalkedTo.Set(&pTrigger->m_triggerCause);
				}
				break;
			}
			case 0x0020: { // HitBy

				pThis->virtual_AutoPause(4);
				pThis->m_lAttackStyle = pTrigger->m_specificID;

				if (pThis->m_lHitter != &pTrigger->m_triggerCause) {
					pThis->m_lHitter.Set(&pTrigger->m_triggerCause);
				}
				break;
			}
			case 0x002F: { // Heard
				if (pThis->m_lHeard != &pTrigger->m_triggerCause) {
					pThis->m_lHeard.Set(&pTrigger->m_triggerCause);
				}
				break;
			}
			case 0x0097: { // Summoned
				if (pThis->m_lSummonedBy != &pTrigger->m_triggerCause) {
					pThis->m_lSummonedBy.Set(&pTrigger->m_triggerCause);
				}
				break;
			}
		}

		if (pGame->SAVE_OBJECT_LIST.Find(pTrigger->m_triggerID) != nullptr && pThis->m_lTrigger != &pTrigger->m_triggerCause) {
			pThis->m_lTrigger.Set(&pTrigger->m_triggerCause);
		}

		if (pThis->virtual_GetObjectType() == CGameObjectType::SPRITE) {
			CGameSprite *const pSprite = reinterpret_cast<CGameSprite*>(pThis);
			pSprite->GetActiveStats()->m_cContingencyList.ProcessTrigger(pSprite, pTrigger);
		}
	}
}
