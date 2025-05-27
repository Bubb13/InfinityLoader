
#include "Baldur-v2.6.6.0_generated.h"

//////////////////////////
// Forward Declarations //
//////////////////////////

static void CVisibilityMap_TraverseTree(CVisibilityMap* pThis, CPoint ptStart, CPoint ptInvert, byte range, ushort nMask, byte* pVisibleTerrainTable);

//////////////
// Internal //
//////////////

static void CVisibilityMap_ClimbWall(CVisibilityMap* pThis, CPoint* ptStart, CPoint* ptEnd, ushort nMask, byte* pVisibleTerrainTable, short nHighest)
{
	if (nHighest < 1 || nHighest > 3)
	{
		return;
	}

	const int nClampedEndY = (std::max)(0, ptEnd->y);
	const int nMapSize = pThis->m_nWidth * pThis->m_nHeight;

	for (short nCurHighest = nHighest; nCurHighest >= 1; --nCurHighest)
	{
		const int ptStartAdjY = ptStart->y - nCurHighest + 1;

		if (ptStartAdjY < nClampedEndY)
		{
			continue;
		}

		const int nMapIndex = ptStartAdjY * pThis->m_nWidth + ptStart->x;

		if (nMapIndex >= 0 && nMapIndex < nMapSize)
		{
			pThis->m_pMap[nMapIndex] |= 0x8000 | nMask;
		}
	}
}

static void CVisibilityMap_PrivateAddCharacter(
	CVisibilityMap* pThis, CPoint* ptPos, ushort nMask, byte* pVisibleTerrainTable, byte visualRange, int* pRemovalTable)
{
	///////////////////////////
	// Update exact position //
	///////////////////////////

	int xPos = ptPos->x;
	if (xPos < 0) { xPos += 31; } // Vanilla Bug: Bad attempt to round towards floor for negative values
	xPos /= 32;

	int yPos = ptPos->y;
	if (yPos < 0) { yPos += 31; } // Vanilla Bug: Bad attempt to round towards floor for negative values
	yPos /= 32;

	const int nMapIndex = yPos * pThis->m_nWidth + xPos;

	if (nMapIndex >= 0 && nMapIndex < pThis->m_nHeight * pThis->m_nWidth)
	{
		pThis->m_pMap[nMapIndex] |= 0x8000 | nMask;
	}

	//////////////////////////////
	// Update full visual range //
	//////////////////////////////

	const int xPosSearch = ptPos->x / 16;
	const int yPosSearch = ptPos->y / 12;
	const int nClampedVisualRange = (std::max)(0, (std::min)(static_cast<int>(visualRange), 23));

	CVisibilityMap_TraverseTree(pThis, CPoint{xPosSearch, yPosSearch}, CPoint{ 1,  1}, nClampedVisualRange, nMask, pVisibleTerrainTable);
	CVisibilityMap_TraverseTree(pThis, CPoint{xPosSearch, yPosSearch}, CPoint{-1,  1}, nClampedVisualRange, nMask, pVisibleTerrainTable);
	CVisibilityMap_TraverseTree(pThis, CPoint{xPosSearch, yPosSearch}, CPoint{-1, -1}, nClampedVisualRange, nMask, pVisibleTerrainTable);
	CVisibilityMap_TraverseTree(pThis, CPoint{xPosSearch, yPosSearch}, CPoint{ 1, -1}, nClampedVisualRange, nMask, pVisibleTerrainTable);

	////////////////////////////
	// Update listen position //
	////////////////////////////

	CPoint listenPosition;
	int unused;
	(*p_g_pBaldurChitin)->cSoundMixer->GetListenPosition(&listenPosition, &unused);

	if (listenPosition.x == -1 && listenPosition.y == -1)
	{
		CGameArea* pArea = pThis->m_pSearchMap->m_pArea;
		CInfGame* pGame = (*p_g_pBaldurChitin)->m_pObjectGame;

		if (pArea == pGame->m_gameAreas[pGame->m_visibleArea])
		{
			pArea->m_cInfinity.m_updateListenPosition = 1;
		}
	}
}

static void CVisibilityMap_SetTileVisible(CVisibilityMap* pThis, int nIndex, ushort nMask)
{
	if (nIndex >= 0 && nIndex < pThis->m_nWidth * pThis->m_nHeight)
	{
		pThis->m_pMap[nIndex] |= 0x8000 | nMask;
	}
}

static void CVisibilityMap_TraverseTree(
	CVisibilityMap* pThis, CPoint ptStart, CPoint ptInvert, byte range, ushort nMask, byte* pVisibleTerrainTable)
{
	CVisibilityMapTreeNode *const pRootNode = pThis->m_pVisMapTrees[range];

	short nLastImpassibleNodeIndex = 0;
	int lastVisibleX = -1;
	int lastVisibleY = -1;
	short nLastHighest = 0;

	short nPreviousNodeIndex = 0;
	short nNextNodeIndex = pRootNode->m_aChildren[0];
	short nCurNodeIndex = nNextNodeIndex;

	for (; ; nPreviousNodeIndex = nCurNodeIndex, nCurNodeIndex = nNextNodeIndex)
	{
		CVisibilityMapTreeNode* pCurNode = pRootNode + nCurNodeIndex;

		CPoint curRelativePos;
		curRelativePos.x = ptStart.x + pCurNode->m_relativePos.x * ptInvert.x;
		curRelativePos.y = ptStart.y + pCurNode->m_relativePos.y * ptInvert.y;

		CPoint ptStartLocal;
		ptStartLocal.x = curRelativePos.x / 2;
		ptStartLocal.y = (curRelativePos.y >> 3) * 3 + (*CVisibilityMap::p_m_SSToVSTable)[curRelativePos.y & 7];

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

				if (short nTableIndex; pThis->m_pSearchMap->GetLOSCost(&curRelativePos, pVisibleTerrainTable, &nTableIndex, pThis->m_bOutDoor) == 0xFF)
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

					if (lastVisibleX != ptStartLocal.x || lastVisibleY != ptStartLocal.y)
					{
						const int nUnknown = range - pCurNode->m_nRange;
						CPoint ptEnd { nUnknown, nUnknown >> 16 };
						CVisibilityMap_ClimbWall(pThis, &ptStartLocal, &ptEnd, nMask, pVisibleTerrainTable, nHighest);
						lastVisibleX = ptStartLocal.x;
						lastVisibleY = ptStartLocal.y;
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

					if (lastVisibleX != ptStartLocal.x || lastVisibleY != ptStartLocal.y)
					{
						CVisibilityMap_SetTileVisible(pThis, ptStartLocal.y * pThis->m_nWidth + ptStartLocal.x, nMask);
						lastVisibleX = ptStartLocal.x;
						lastVisibleY = ptStartLocal.y;
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

///////////////
// Overrides //
///////////////

byte CVisibilityMap::Override_AddCharacter(CPoint* pos, int charId, byte* pVisibleTerrainTable, byte visualRange, int* pRemovalTable)
{
	//////////////////////////////
	// Find open character slot //
	//////////////////////////////

	int nCharIndex = 0;

	for (; nCharIndex < 15; ++nCharIndex)
	{
		const int nExistingId = this->m_aCharacterIds[nCharIndex];

		if (nExistingId == -1)
		{
			this->m_aCharacterIds[nCharIndex] = charId;
			break;
		}

		if (nExistingId == charId) // Vanilla Bug: Might already exist after an open slot
		{
			break;
		}
	}

	const ushort nMask = 1 << (nCharIndex & 0x1F);

	///////////////////////////
	// Update exact position //
	///////////////////////////

	int xPos = pos->x;
	if (xPos < 0) { xPos += 31; } // Vanilla Bug: Bad attempt to round towards floor for negative values
	xPos /= 32;

	int yPos = pos->y;
	if (yPos < 0) { yPos += 31; } // Vanilla Bug: Bad attempt to round towards floor for negative values
	yPos /= 32;

	const int nMapIndex = yPos * this->m_nWidth + xPos;

	if (nMapIndex >= 0 && nMapIndex < this->m_nHeight * this->m_nWidth)
	{
		this->m_pMap[nMapIndex] |= 0x8000 | nMask;
	}

	//////////////////////////////
	// Update full visual range //
	//////////////////////////////

	const int xPosSearch = pos->x / 16;
	const int yPosSearch = pos->y / 12;
	const int nClampedVisualRange = (std::max)(0, (std::min)(static_cast<int>(visualRange), 23));

	CVisibilityMap_TraverseTree(this, CPoint{xPosSearch, yPosSearch}, CPoint{ 1,  1}, nClampedVisualRange, nMask, pVisibleTerrainTable);
	CVisibilityMap_TraverseTree(this, CPoint{xPosSearch, yPosSearch}, CPoint{-1,  1}, nClampedVisualRange, nMask, pVisibleTerrainTable);
	CVisibilityMap_TraverseTree(this, CPoint{xPosSearch, yPosSearch}, CPoint{-1, -1}, nClampedVisualRange, nMask, pVisibleTerrainTable);
	CVisibilityMap_TraverseTree(this, CPoint{xPosSearch, yPosSearch}, CPoint{ 1, -1}, nClampedVisualRange, nMask, pVisibleTerrainTable);

	////////////////////////////
	// Update listen position //
	////////////////////////////

	CPoint listenPosition;
	int unused;
	(*p_g_pBaldurChitin)->cSoundMixer->GetListenPosition(&listenPosition, &unused);

	if (listenPosition.x == -1 && listenPosition.y == -1)
	{
		CGameArea* pArea = this->m_pSearchMap->m_pArea;
		CInfGame* pGame = (*p_g_pBaldurChitin)->m_pObjectGame;

		if (pArea == pGame->m_gameAreas[pGame->m_visibleArea])
		{
			pArea->m_cInfinity.m_updateListenPosition = 1;
		}
	}

	return 1;
}

void CVisibilityMap::Override_RemoveCharacter(CPoint* ptOldPos, int charId, byte* pVisibleTerrainTable, byte visualRange, int* pRemovalTable, byte bRemoveCharId)
{
	//////////////////////////
	// Find character index //
	//////////////////////////

	int nCharIndex = 0;

	while (this->m_aCharacterIds[nCharIndex] != charId)
	{
		if (++nCharIndex >= 15)
		{
			return;
		}
	}

	if (bRemoveCharId)
	{
		this->m_aCharacterIds[nCharIndex] = -1;
	}

	const ushort nMask = 1 << (nCharIndex & 0x1F);

	if (nMask == 0xFF) // Vanilla Bug: Never happens
	{
		return;
	}

	////////////////////////////////
	// Unset all indices in range //
	////////////////////////////////

	int xPos = ptOldPos->x;
	if (xPos < 0) { xPos += 31; } // Vanilla Bug: Bad attempt to round towards floor for negative values
	xPos /= 32;

	int yPos = ptOldPos->y;
	if (yPos < 0) { yPos += 31; } // Vanilla Bug: Bad attempt to round towards floor for negative values
	yPos /= 32;

	const int nClampedVisualRange = (std::max)(0, (std::min)(static_cast<int>(visualRange), 23));

	const int xLeft = (std::max)(0, xPos - nClampedVisualRange - 1);
	const int yTop = (std::max)(0, yPos - nClampedVisualRange - 1);
	const int xRight = (std::min)(xPos + nClampedVisualRange + 1, static_cast<int>(this->m_nWidth));
	const int yBottom = (std::min)(yPos + nClampedVisualRange + 1, static_cast<int>(this->m_nHeight));

	for (int curY = yTop; curY < yBottom; ++curY)
	{
		int curIndex = curY * this->m_nWidth + xLeft;

		for (int curX = xLeft; curX < xRight; ++curX, ++curIndex)
		{
			if (curIndex >= 0 && curIndex < this->m_nMapSize)
			{
				this->m_pMap[curIndex] &= ~nMask;
			}
		}
	}
}

void CVisibilityMap::Override_UpDate(CPoint* ptOldPos, CPoint* ptNewPos, int charId, byte* pVisibleTerrainTable, byte visualRange, int* pRemovalTable, byte bForceUpdate)
{
	if (ptOldPos->x == ptNewPos->x && ptOldPos->y == ptNewPos->y && bForceUpdate == 0)
	{
		return;
	}

	//////////////////////////
	// Find character index //
	//////////////////////////

	int nCharIndex = 0;

	while (this->m_aCharacterIds[nCharIndex] != charId)
	{
		if (++nCharIndex >= 15)
		{
			return;
		}
	}

	const ushort nMask = 1 << (nCharIndex & 0x1F);

	if (nMask == 0xFF) // Vanilla Bug: Never happens
	{
		return;
	}

	////////////////////////////////
	// Unset all indices in range //
	////////////////////////////////

	int xPos = ptOldPos->x;
	if (xPos < 0) { xPos += 31; } // Vanilla Bug: Bad attempt to round towards floor for negative values
	xPos /= 32;

	int yPos = ptOldPos->y;
	if (yPos < 0) { yPos += 31; } // Vanilla Bug: Bad attempt to round towards floor for negative values
	yPos /= 32;

	const int nClampedVisualRange = (std::max)(0, (std::min)(static_cast<int>(visualRange), 23));

	const int xLeft = (std::max)(0, xPos - nClampedVisualRange - 1);
	const int yTop = (std::max)(0, yPos - nClampedVisualRange - 1);
	const int xRight = (std::min)(xPos + nClampedVisualRange + 1, static_cast<int>(this->m_nWidth));
	const int yBottom = (std::min)(yPos + nClampedVisualRange + 1, static_cast<int>(this->m_nHeight));

	for (int curY = yTop; curY < yBottom; ++curY)
	{
		int curIndex = curY * this->m_nWidth + xLeft;

		for (int curX = xLeft; curX < xRight; ++curX, ++curIndex)
		{
			if (curIndex >= 0 && curIndex < this->m_nMapSize)
			{
				this->m_pMap[curIndex] &= ~nMask;
			}
		}
	}

	/////////////////////
	// Set new indices //
	/////////////////////

	CVisibilityMap_PrivateAddCharacter(this, ptNewPos, nMask, pVisibleTerrainTable, nClampedVisualRange, pRemovalTable);
}
