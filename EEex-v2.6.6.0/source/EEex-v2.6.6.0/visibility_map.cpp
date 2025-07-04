
#include <unordered_map>
#include <vector>

#include "Baldur-v2.6.6.0_generated.h"
#include "EEex.h"

////////////////
// Structures //
////////////////

//--------------------------//
// VisibilityMapCharacterEx //
//--------------------------//

class VisibilityMapCharacterEx
{
private:
	byte m_nVisRange = 0;
	int m_nSideLen = 0;
	int m_nArraySize = 0;
	byte* m_pCanSee = nullptr;

public:
	VisibilityMapCharacterEx();

	// Error if copy or move is attempted.
	VisibilityMapCharacterEx(const VisibilityMapCharacterEx& other) = delete;
	VisibilityMapCharacterEx(VisibilityMapCharacterEx&& other) = delete;
	VisibilityMapCharacterEx& operator=(const VisibilityMapCharacterEx& other) = delete;
	VisibilityMapCharacterEx& operator=(VisibilityMapCharacterEx&& other) = delete;

	~VisibilityMapCharacterEx();
	template<bool set> void apply(CVisibilityMap* pVisMap, CPoint ptVisCenter);
	void checkInitRange(byte nVisRange);
	void setAtOffset(CPoint ptVisOffset);
};

VisibilityMapCharacterEx::VisibilityMapCharacterEx()
{
}

VisibilityMapCharacterEx::~VisibilityMapCharacterEx()
{
	delete[] m_pCanSee;
}

template<bool set>
void VisibilityMapCharacterEx::apply(CVisibilityMap* pVisMap, CPoint ptVisCenter)
{
	const int nLocalLeft = ptVisCenter.x - m_nVisRange;
	const int nLocalTop = ptVisCenter.y - m_nVisRange;

	const int nLeft = (std::max)(0, nLocalLeft);
	const int nTop = (std::max)(0, nLocalTop);
	const int nRight = (std::min)(ptVisCenter.x + m_nVisRange, static_cast<int>(pVisMap->m_nWidth - 1));
	const int nBottom = (std::min)(ptVisCenter.y + m_nVisRange, static_cast<int>(pVisMap->m_nHeight - 1));

	ushort *const pMap = pVisMap->m_pMap;

	for (int nY = nTop; nY <= nBottom; ++nY)
	{
		const int nSourceOffsetY = (nY - nLocalTop) * m_nSideLen;
		ushort* pDest = &pMap[nY * pVisMap->m_nWidth + nLeft];

		for (int nX = nLeft; nX <= nRight; ++nX, ++pDest)
		{
			if constexpr (set)
			{
				if (m_pCanSee[nSourceOffsetY + nX - nLocalLeft])
				{
					*pDest = 0x8000 | ((*pDest & 0x7FFF) + 1);
				}
			}
			else
			{
				if (m_pCanSee[nSourceOffsetY + nX - nLocalLeft])
				{
					*pDest = 0x8000 | ((*pDest & 0x7FFF) - 1);
				}
			}
		}
	}
}

void VisibilityMapCharacterEx::checkInitRange(byte nVisRange)
{
	if (nVisRange <= m_nVisRange)
	{
		memset(m_pCanSee, 0, m_nArraySize);
		return;
	}

	m_nVisRange = nVisRange;
	m_nSideLen = 1 + m_nVisRange * 2;
	m_nArraySize = m_nSideLen * m_nSideLen;
	delete[] m_pCanSee;
	m_pCanSee = new byte[m_nArraySize];
	memset(m_pCanSee, 0, m_nArraySize);
}

void VisibilityMapCharacterEx::setAtOffset(CPoint ptVisOffset)
{
	const int nIndexX = ptVisOffset.x + m_nVisRange;
	const int nIndexY = ptVisOffset.y + m_nVisRange;

	if (nIndexX >= m_nSideLen || nIndexY >= m_nSideLen)
	{
		FPrint("[!][EEex.dll] VisibilityMapCharacterEx::setAtOffset() - Out of bounds write at (%d,%d)!\n", ptVisOffset.x, ptVisOffset.y);
		return;
	}

	m_pCanSee[nIndexY * m_nSideLen + nIndexX] = 1;
}

//-----------------//
// VisibilityMapEx //
//-----------------//

template<typename T>
class ConstItrProxy
{
private:
	T& ref;
public:
	ConstItrProxy(T& r) : ref(r) {}
	auto begin() { return ref.cbegin(); }
	auto end() { return ref.cend(); }
};

class VisibilityMapEx
{
private:
	CVisibilityMap* m_owner;
	std::unordered_map<int, VisibilityMapCharacterEx> m_charactersExMap{};

public:
	VisibilityMapEx(CVisibilityMap* pOwner);

	// Only moveable. Error if copy is attempted.
	VisibilityMapEx(VisibilityMapEx&& other) = default;
	VisibilityMapEx& operator=(VisibilityMapEx&& other) = default;

	int addFakeCharacter(CPoint* pPos, byte* pVisibleTerrainTable, byte nVisRange, int* pRemovalTable);
	ConstItrProxy<decltype(m_charactersExMap)> characters();
	VisibilityMapCharacterEx* getCharacterEx(int nCharId);
	VisibilityMapCharacterEx& getOrCreateCharacterEx(int nCharId);
	CVisibilityMap* getOwner() const;
	void removeCharacter(int nCharId);
};

VisibilityMapEx::VisibilityMapEx(CVisibilityMap* pOwner) : m_owner(pOwner)
{
}

int VisibilityMapEx::addFakeCharacter(CPoint* pPos, byte* pVisibleTerrainTable, byte nVisRange, int* pRemovalTable)
{
	int nFakeId = -1;
	for (; m_charactersExMap.contains(nFakeId); --nFakeId);
	m_owner->Override_AddCharacter(pPos, nFakeId, pVisibleTerrainTable, nVisRange, pRemovalTable);
	return nFakeId;
}

ConstItrProxy<decltype(VisibilityMapEx::m_charactersExMap)> VisibilityMapEx::characters()
{
	return ConstItrProxy { m_charactersExMap };
}

VisibilityMapCharacterEx* VisibilityMapEx::getCharacterEx(int nCharId)
{
	if (auto itr = m_charactersExMap.find(nCharId); itr != m_charactersExMap.end())
	{
		return &itr->second;
	}
	return nullptr;
}

VisibilityMapCharacterEx& VisibilityMapEx::getOrCreateCharacterEx(int nCharId)
{
	return m_charactersExMap[nCharId];
}

CVisibilityMap* VisibilityMapEx::getOwner() const
{
	return m_owner;
}

void VisibilityMapEx::removeCharacter(int nCharId)
{
	m_charactersExMap.erase(nCharId);
}

/////////////
// Globals //
/////////////

std::vector<VisibilityMapEx> visibilityMapExList{};

//////////////////
// Global Utils //
//////////////////

static std::vector<VisibilityMapEx>::iterator getVisibilityMapExItr(CVisibilityMap* pThis)
{
	return std::find_if(visibilityMapExList.begin(), visibilityMapExList.end(), [=](const auto& i) { return i.getOwner() == pThis; });
}

static VisibilityMapEx& getVisibilityMapEx(CVisibilityMap* pThis)
{
	return *getVisibilityMapExItr(pThis);
}

///////////
// Hooks //
///////////

void EEex::VisibilityMap_Hook_OnConstruct(CVisibilityMap* pThis)
{
	visibilityMapExList.emplace_back(pThis);
}

void EEex::VisibilityMap_Hook_OnDestruct(CVisibilityMap* pThis)
{
	visibilityMapExList.erase(getVisibilityMapExItr(pThis));
}

//////////////////////////
// Forward Declarations //
//////////////////////////

static void CVisibilityMap_TraverseTree(CVisibilityMap* pThis, CPoint ptStartMap, CPoint ptInvertSearch, byte nVisRange, byte* pVisibleTerrainTable,
	VisibilityMapCharacterEx& characterEx);

static void CVisibilityMap_SetTileVisible(CPoint ptCenterVis, CPoint ptSetVis, VisibilityMapCharacterEx& characterEx);

//////////////
// Internal //
//////////////

static void CVisibilityMap_ClimbWall(
	CPoint ptCenterVis, CPoint ptSetVis, CPoint ptEnd, short nHighest, VisibilityMapCharacterEx& characterEx)
{
	if (nHighest < 1 || nHighest > 3)
	{
		return;
	}

	const int nClampedEndY = (std::max)(0, ptEnd.y);

	for (short nCurHighest = nHighest; nCurHighest >= 1; --nCurHighest)
	{
		const int ptStartAdjY = ptSetVis.y - nCurHighest + 1;

		if (ptStartAdjY < nClampedEndY)
		{
			continue;
		}

		CVisibilityMap_SetTileVisible(ptCenterVis, CPoint{ ptSetVis.x, ptStartAdjY }, characterEx);
	}
}

static void CVisibilityMap_SetTileVisible(CPoint ptCenterVis, CPoint ptSetVis, VisibilityMapCharacterEx& characterEx)
{
	const CPoint ptVisOffset { ptSetVis.x - ptCenterVis.x, ptSetVis.y - ptCenterVis.y };
	characterEx.setAtOffset(ptVisOffset);
}

static void CVisibilityMap_TraverseTree(
	CVisibilityMap* pThis, CPoint ptStartMap, CPoint ptInvertSearch, byte nVisRange, byte* pVisibleTerrainTable,
	VisibilityMapCharacterEx& characterEx)
{
	const CPoint ptStartSearch { ptStartMap.x / 16, ptStartMap.y / 12 };
	const CPoint ptStartVis { ptStartMap.x / 32, ptStartMap.y / 32 };
	CVisibilityMapTreeNode *const pRootNode = pThis->m_pVisMapTrees[nVisRange];

	short nLastImpassibleNodeIndex = 0;
	short nLastHighest = 0;
	CPoint ptLastVisible { -1, -1 };

	short nPreviousNodeIndex = 0;
	short nNextNodeIndex = pRootNode->m_aChildren[0];
	short nCurNodeIndex = nNextNodeIndex;

	for (; ; nPreviousNodeIndex = nCurNodeIndex, nCurNodeIndex = nNextNodeIndex)
	{
		CVisibilityMapTreeNode* pCurNode = pRootNode + nCurNodeIndex;

		// Search units are of the ratio (3/48,4/48) compared to map units
		CPoint curSearchPos;
		curSearchPos.x = ptStartSearch.x + pCurNode->m_relativePos.x * ptInvertSearch.x;
		curSearchPos.y = ptStartSearch.y + pCurNode->m_relativePos.y * ptInvertSearch.y;

		// Visual units are of the ratio (1/32,1/32) compared to map units, (4/8,3/8) compared to search units
		// This conversion is imprecise, but leaving it as-is for parity with vanilla.
		CPoint ptStartLocal;
		ptStartLocal.x = curSearchPos.x / 2;
		ptStartLocal.y = (curSearchPos.y >> 3) * 3 + (*CVisibilityMap::p_m_SSToVSTable)[curSearchPos.y & 7];

		if (nPreviousNodeIndex == pCurNode->m_parent)
		{
			if (nCurNodeIndex != 0)
			{
				//////////////////
				// Validate pos //
				//////////////////

				if
				(
					ptStartLocal.x < 0 || ptStartLocal.x >= pThis->m_nWidth
					||
					ptStartLocal.y < 0 || ptStartLocal.y >= pThis->m_nHeight
				)
				{
					if (nLastImpassibleNodeIndex == nCurNodeIndex)
					{
						nLastHighest = 0;
						nLastImpassibleNodeIndex = 0;
					}

					nNextNodeIndex = pCurNode->m_parent;
					continue;
				}

				///////////////
				// Check LOS //
				///////////////

				if (short nTableIndex; pThis->m_pSearchMap->GetLOSCost(&curSearchPos, pVisibleTerrainTable, &nTableIndex, pThis->m_bOutDoor) == 0xFF)
				{
					////////////////
					// Impassible //
					////////////////

					if (nLastImpassibleNodeIndex == 0)
					{
						nLastImpassibleNodeIndex = nCurNodeIndex;
					}

					const short nHighest = pThis->m_pSearchMap->GetStructureHeight(nTableIndex);

					if (nHighest < nLastHighest)
					{
						if (nLastImpassibleNodeIndex == nCurNodeIndex)
						{
							nLastImpassibleNodeIndex = 0;
							nLastHighest = 0;
						}

						nNextNodeIndex = pCurNode->m_parent;
						continue;
					}

					nLastHighest = nHighest;

					if (ptLastVisible.x != ptStartLocal.x || ptLastVisible.y != ptStartLocal.y)
					{
						const int nUnknown = nVisRange - pCurNode->m_nRange;
						CPoint ptEnd { nUnknown, nUnknown >> 16 };
						CVisibilityMap_ClimbWall(ptStartVis, ptStartLocal, ptEnd, nHighest, characterEx);
						ptLastVisible = ptStartLocal;
					}

					// m_aChildren[0]
				}
				else
				{
					//////////////
					// Passible //
					//////////////

					if (nLastImpassibleNodeIndex != 0)
					{
						if (nLastImpassibleNodeIndex == nCurNodeIndex)
						{
							nLastHighest = 0;
							nLastImpassibleNodeIndex = 0;
						}

						nNextNodeIndex = pCurNode->m_parent;
						continue;
					}

					if (ptLastVisible.x != ptStartLocal.x || ptLastVisible.y != ptStartLocal.y)
					{
						CVisibilityMap_SetTileVisible(ptStartVis, ptStartLocal, characterEx);
						ptLastVisible = ptStartLocal;
					}

					// m_aChildren[0]
				}
			}

			nNextNodeIndex = pCurNode->m_aChildren[0];
		}
		else
		{
			if (pCurNode->m_aChildren[0] != 0 && nPreviousNodeIndex == pCurNode->m_aChildren[0])
			{
				nNextNodeIndex = pCurNode->m_aChildren[1];
			}
			else if (pCurNode->m_aChildren[1] != 0 && nPreviousNodeIndex == pCurNode->m_aChildren[1])
			{
				nNextNodeIndex = pCurNode->m_aChildren[2];
			}
			else
			{
				nNextNodeIndex = pCurNode->m_parent;

				if (pCurNode->m_aChildren[2] != 0 && nPreviousNodeIndex == pCurNode->m_aChildren[2])
				{
					if (nCurNodeIndex == 0)
					{
						return;
					}
				}

				if (nLastImpassibleNodeIndex == nCurNodeIndex)
				{
					nLastHighest = 0;
					nLastImpassibleNodeIndex = 0;
				}

				continue;
			}
		}

		///////////////////////////////////
		// Check fallback to parent node //
		///////////////////////////////////

		if (nNextNodeIndex != 0)
		{
			continue;
		}

		if (nCurNodeIndex == 0)
		{
			return;
		}

		if (nLastImpassibleNodeIndex == nCurNodeIndex)
		{
			nLastHighest = 0;
			nLastImpassibleNodeIndex = 0;
		}

		nNextNodeIndex = pCurNode->m_parent;
	}
}

static void unseePreviousPoints(CVisibilityMap* pThis, CPoint ptOld, VisibilityMapCharacterEx& characterEx)
{
	///////////////////////////
	// Unsee previous points //
	///////////////////////////

	int nOldVisPosX = ptOld.x;
	if (nOldVisPosX < 0) { nOldVisPosX += 31; } // Vanilla Bug: Bad attempt to round towards floor for negative values
	nOldVisPosX /= 32;

	int nOldVisPosY = ptOld.y;
	if (nOldVisPosY < 0) { nOldVisPosY += 31; } // Vanilla Bug: Bad attempt to round towards floor for negative values
	nOldVisPosY /= 32;

	characterEx.apply<false>(pThis, CPoint{ nOldVisPosX, nOldVisPosY });
}

static void calculateNewSeenPoints(
	CVisibilityMap* pThis, CPoint ptNew, byte* pVisibleTerrainTable, byte nVisRange, VisibilityMapCharacterEx& characterEx)
{
	///////////////////////////////
	// Calculate new seen points //
	///////////////////////////////

	int nNewVisPosX = ptNew.x;
	if (nNewVisPosX < 0) { nNewVisPosX += 31; } // Vanilla Bug: Bad attempt to round towards floor for negative values
	nNewVisPosX /= 32;

	int nNewVisPosY = ptNew.y;
	if (nNewVisPosY < 0) { nNewVisPosY += 31; } // Vanilla Bug: Bad attempt to round towards floor for negative values
	nNewVisPosY /= 32;

	const int nClampedVisualRange = (std::max)(0, (std::min)(static_cast<int>(nVisRange), 23));

	characterEx.checkInitRange(nClampedVisualRange);
	CVisibilityMap_TraverseTree(pThis, ptNew, CPoint{ 1,  1}, nClampedVisualRange, pVisibleTerrainTable, characterEx);
	CVisibilityMap_TraverseTree(pThis, ptNew, CPoint{-1,  1}, nClampedVisualRange, pVisibleTerrainTable, characterEx);
	CVisibilityMap_TraverseTree(pThis, ptNew, CPoint{-1, -1}, nClampedVisualRange, pVisibleTerrainTable, characterEx);
	CVisibilityMap_TraverseTree(pThis, ptNew, CPoint{ 1, -1}, nClampedVisualRange, pVisibleTerrainTable, characterEx);
	characterEx.apply<true>(pThis, CPoint{ nNewVisPosX, nNewVisPosY });

	////////////////////////////
	// Update listen position //
	////////////////////////////

	CPoint listenPosition;
	int unused;
	(*p_g_pBaldurChitin)->cSoundMixer->GetListenPosition(&listenPosition, &unused);

	if (listenPosition.x == -1 && listenPosition.y == -1)
	{
		CGameArea *const pArea = pThis->m_pSearchMap->m_pArea;
		CInfGame *const pGame = (*p_g_pBaldurChitin)->m_pObjectGame;

		if (pArea == pGame->m_gameAreas[pGame->m_visibleArea])
		{
			pArea->m_cInfinity.m_updateListenPosition = 1;
		}
	}
}

///////////////
// Overrides //
///////////////

void CGameArea::Override_AddClairvoyanceObject(CGameSprite* pSprite, CPoint position, int duration)
{
	//////////////////
	// Send message //
	//////////////////

	CBaldurChitin *const pChitin = *p_g_pBaldurChitin;

	if (pChitin->cNetwork.m_bConnectionEstablished == 1 && pChitin->cNetwork.m_idLocalPlayer == pSprite->m_remotePlayerID)
	{
		CMessageAddClairvoyance *const pMessage = newEngineObj<CMessageAddClairvoyance>(
			position.x, position.y, duration, pSprite->m_id, pSprite->m_id);

		pChitin->m_cMessageHandler.AddMessage(pMessage, 0);
	}

	///////////////////////////////////////////////////////////
	// Add clairvoyance object to the vismap using a fake id //
	///////////////////////////////////////////////////////////

	VisibilityMapEx& visibilityMapEx = getVisibilityMapEx(&this->m_visibility);
	byte *const pVisibleTerrainTable = pSprite->virtual_GetVisibleTerrainTable();
	constexpr short VISUAL_RANGE = 448;

	const int nVisMapId = visibilityMapEx.addFakeCharacter(
		&position,
		pVisibleTerrainTable,
		static_cast<byte>(VISUAL_RANGE), // Vanilla bug: VISUAL_RANGE is mistakenly passed as map coordinates, not visual coordinates.
										 // This is attempting to pass the default visual range of 14, but (after truncation) passes
										 // 192 instead, which ends up clamped to the maximum of 23.
		nullptr
	);

	//////////////////////////////////////
	// Register the clairvoyance object //
	//////////////////////////////////////

	CGameAreaClairvoyanceEntry *const pClairvoyanceEntry = newEngineObj<CGameAreaClairvoyanceEntry>(
		position.x, position.y,                                    // position
		nVisMapId,                                                 // id (visibility map)
		pChitin->m_pObjectGame->m_worldTime.m_gameTime + duration, // timeKill
		pVisibleTerrainTable,                                      // visibleTerrainTable
		pSprite->m_id,                                             // charId (caster)
		VISUAL_RANGE                                               // visRange
	);

	this->m_lClairvoyanceObjects.AddTail(pClairvoyanceEntry);
	this->ShowMonstersInArea(pClairvoyanceEntry);
}

void CGameSprite::Override_CheckIfVisible()
{
	////////////////////////////////////////
	// Check if I'm always seen via op114 //
	////////////////////////////////////////

	if (this->GetActiveStats()->m_bIdentifyMode != 0)
	{
		this->m_canBeSeen = 8;
		return;
	}

	/////////////////////////////
	// Check if I'm in an area //
	/////////////////////////////

	CGameArea *const pArea = this->m_pArea;

	if (pArea == nullptr)
	{
		this->m_canBeSeen = 8;
		return;
	}

	////////////////////////////////
	// Check if I'm always "seen" //
	////////////////////////////////

	CVisibilityMap *const pVisibility = &pArea->m_visibility;

	if
	(
		(
			pVisibility->Override_IsCharacterIdOnMap(this->m_id)      // If I'm a FoW clearing creature...
			||
			this->m_animation.m_animation->virtual_GetListType() == 2 // or I'm a flying creature...
		)
		&&
		(this->GetActiveStats()->m_generalState & 0x800) == 0         // + I'm not STATE_DEAD...
	)
	{
		this->m_canBeSeen = 8;                                        // ...then I'm always seen
		return;
	}

	//////////////////////////////////////////
	// Loop over all FoW clearing creatures //
	//////////////////////////////////////////

	VisibilityMapEx& visibilityMapEx = getVisibilityMapEx(pVisibility);

	for (const auto& [nCharId, characterEx] : visibilityMapEx.characters())
	{
		CGameSprite* pFoWClearingCreature = nullptr; // Vanilla bug: Assumes sprite

		if (CGameObjectArray::GetShare(nCharId, reinterpret_cast<CGameObject**>(&pFoWClearingCreature)) != 0)
		{
			continue;
		}

		////////////////////////////////////////
		// Check that we are in the same area //
		////////////////////////////////////////

		if (pFoWClearingCreature->m_pArea != pArea)
		{
			continue;
		}

		//////////////////////////////////////////////////////////
		// Check that the FoW clearing object is not STATE_DEAD //
		//////////////////////////////////////////////////////////

		if ((pFoWClearingCreature->GetActiveStats()->m_generalState & 0x800) != 0)
		{
			continue;
		}

		////////////////////////////////////////////////////////////////////////////////////////////////
		// Check LOS from me to FoW clearing object, using their visual range (but my terrain table?) //
		////////////////////////////////////////////////////////////////////////////////////////////////

		const int bLOSResult = pArea->CheckLOS(
			&this->m_pos,
			&pFoWClearingCreature->m_pos,
			this->m_visibleTerrainTable,
			1,
			pFoWClearingCreature->virtual_GetVisualRange()
		);

		if (!bLOSResult)
		{
			continue;
		}

		//////////////////////////////////
		// Check if I'm a visible enemy //
		//////////////////////////////////

		if
		(
			this->m_bVisibleMonster == 0                          // I haven't passed this guard yet
			&&
			this->m_typeAI.m_EnemyAlly >= 200                     // + My EA is >= EVILCUTOFF
			&&
			(this->GetActiveStats()->m_generalState & 0x800) == 0 // + I'm not STATE_DEAD
			&&
			(this->GetActiveStats()->m_generalState & 0x10) == 0  // + I'm not STATE_INVISIBLE
		)
		{
			this->m_bVisibleMonster = 1;

			if (pArea->m_nVisibleMonster++ == 0)
			{
				pFoWClearingCreature->virtual_AutoPause(0x80);
			}
		}

		////////////////////////////////////
		// Check if I just became visible //
		////////////////////////////////////

		if (this->m_canBeSeen == 0)
		{
			this->m_bSeenPartyBefore = 1; // Unused

			// Vanilla bug: BecameVisible() set on FoW object, (not the current sprite)?
			CMessageSetTrigger *const pMessage = newEngineObj<CMessageSetTrigger>(
				EngineVal<CAITrigger> { 0x0033, 0 }, // BecameVisible()
				this->m_id,
				pFoWClearingCreature->m_id
			);

			(*p_g_pBaldurChitin)->m_cMessageHandler.AddMessage(pMessage, 0);
		}

		this->m_canBeSeen = 8;
		break;
	}
}

short CGameSprite::Override_SetVisualRange(short nVisRange)
{
	const byte nOldVisRange = this->m_nVisualRange;
	CGameArea *const pArea = this->m_pArea;

	if (pArea == nullptr)
	{
		return nOldVisRange;
	}

	CVisibilityMap *const pVisibility = &pArea->m_visibility;
	VisibilityMapEx& visibilityMapEx = getVisibilityMapEx(pVisibility);
	VisibilityMapCharacterEx *const pCharacterEx = visibilityMapEx.getCharacterEx(this->m_id);

	if (pCharacterEx == nullptr)
	{
		this->m_nVisualRange = static_cast<byte>(nVisRange);
		return nOldVisRange;
	}

	///////////////////////////
	// Unsee previous points //
	///////////////////////////

	unseePreviousPoints(pVisibility, this->m_pos, *pCharacterEx);

	/////////////////////////
	// Update visual range //
	/////////////////////////

	this->m_nVisualRange = static_cast<byte>(nVisRange);

	///////////////////////////////
	// Calculate new seen points //
	///////////////////////////////

	calculateNewSeenPoints(pVisibility, this->m_pos, this->m_visibleTerrainTable, this->m_nVisualRange, *pCharacterEx);

	return nOldVisRange;
}

byte CVisibilityMap::Override_AddCharacter(CPoint* pPos, int nCharId, byte* pVisibleTerrainTable, byte nVisRange, int* pRemovalTable)
{
	//////////////////////////////
	// Find open character slot //
	//////////////////////////////

	VisibilityMapEx& visibilityMapEx = getVisibilityMapEx(this);
	VisibilityMapCharacterEx& characterEx = visibilityMapEx.getOrCreateCharacterEx(nCharId);

	///////////////////////////////
	// Calculate new seen points //
	///////////////////////////////

	calculateNewSeenPoints(this, *pPos, pVisibleTerrainTable, nVisRange, characterEx);

	return 1;
}

int CVisibilityMap::Override_IsCharacterIdOnMap(int nCharId)
{
	VisibilityMapEx& visibilityMapEx = getVisibilityMapEx(this);
	VisibilityMapCharacterEx *const characterEx = visibilityMapEx.getCharacterEx(nCharId);
	return characterEx != nullptr;
}

void CVisibilityMap::Override_RemoveCharacter(CPoint* pOldPos, int nCharId, byte* pVisibleTerrainTable, byte nVisRange, int* pRemovalTable, byte bRemoveCharId)
{
	//////////////////////////
	// Find character index //
	//////////////////////////

	VisibilityMapEx& visibilityMapEx = getVisibilityMapEx(this);
	VisibilityMapCharacterEx *const pCharacterEx = visibilityMapEx.getCharacterEx(nCharId);

	if (pCharacterEx == nullptr)
	{
		return;
	}

	///////////////////////////
	// Unsee previous points //
	///////////////////////////

	unseePreviousPoints(this, *pOldPos, *pCharacterEx);

	//////////////////////
	// Remove character //
	//////////////////////

	// This flag is only used by Farsight objects in the old vismap code, (they hackily used to share a single vismap id).
	// Ignoring the following workaround since I assign them unique ids in CGameArea::Override_AddClairvoyanceObject().

	//if (bRemoveCharId)
	//{
	//	visibilityMapEx.removeCharacter(nCharId);
	//}

	visibilityMapEx.removeCharacter(nCharId);
}

void CVisibilityMap::Override_UpDate(CPoint* pOldPos, CPoint* pNewPos, int nCharId, byte* pVisibleTerrainTable, byte nVisRange, int* pRemovalTable, byte bForceUpdate)
{
	if (pOldPos->x == pNewPos->x && pOldPos->y == pNewPos->y && bForceUpdate == 0)
	{
		return;
	}

	//////////////////////////
	// Find character index //
	//////////////////////////

	VisibilityMapEx& visibilityMapEx = getVisibilityMapEx(this);
	VisibilityMapCharacterEx *const pCharacterEx = visibilityMapEx.getCharacterEx(nCharId);

	if (pCharacterEx == nullptr)
	{
		return;
	}

	///////////////////////////
	// Unsee previous points //
	///////////////////////////

	unseePreviousPoints(this, *pOldPos, *pCharacterEx);

	///////////////////////////////
	// Calculate new seen points //
	///////////////////////////////

	calculateNewSeenPoints(this, *pNewPos, pVisibleTerrainTable, nVisRange, *pCharacterEx);
}
