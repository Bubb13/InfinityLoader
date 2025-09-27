
#include <deque>

#include "EEex.h"
#include "coordinate_util.hpp"
#include "time_util.hpp"

//-----------------------------//
//          Constants          //
//-----------------------------//

constexpr long long AUTO_ZOOM_TARGET_TIME = 10 * 1000000LL / 30;

// Empirically derived; lower values increase the smoothness of the "snap" at the
// end of an exponential autoscroll at the cost of drawing out the autoscroll.
constexpr int EXP_SCROLL_THRESHOLD = 2500;

// Empirically derived; lower values decrease the time spent linear scrolling at the
// end of an exponential autoscroll, reducing smoothness for that period in exchange
// for making the exponential -> linear transition less jarring.
constexpr int EXP_SCROLL_MIN_STEP = 2500;

//---------------------------//
//          Structs          //
//---------------------------//

struct ExInfinityData
{
	long long nLastAutoZoomTime = 0;
	long long nAutoZoomTimeRemaining = 0;
};

enum class ExpScrollEndReason
{
	GRANULARITY,
	THRESHOLD,
	NORMAL,
};

struct ExpScrollResult
{
	bool bHadNonMinStep;
	ExpScrollEndReason endReason;
	int nStepCount;
};

template<typename T>
class RollingAverage
{
	struct Entry
	{
		const long long timestamp;
		const T value;

		Entry(long long timestamp, T value) : timestamp(timestamp), value(value) {}
	};

	const long long timeWindow;

	T currentAverage = 0;
	std::deque<Entry> queue{};

public:
	RollingAverage(long long timeWindow);
	T get();
	T getLast();
	void push(long long currentTime, T value);
	void recalculate(long long currentTime);
};

template<typename T>
RollingAverage<T>::RollingAverage(long long timeWindow) : timeWindow(timeWindow) {}

template<typename T>
T RollingAverage<T>::get()
{
	return currentAverage;
}

template<typename T>
T RollingAverage<T>::getLast()
{
	return queue.back().value;
}

template<typename T>
void RollingAverage<T>::push(long long currentTime, T value)
{
	queue.emplace_back(currentTime, value);
}

template<typename T>
void RollingAverage<T>::recalculate(long long currentTime)
{
	const long long dropTime = currentTime - this->timeWindow;

	while (!queue.empty() && queue.front().timestamp < dropTime)
	{
		queue.pop_front();
	}

	T sum = 0;

	for (const Entry& entry : queue)
	{
		sum += entry.value;
	}

	currentAverage = sum / static_cast<T>(queue.size());
}

//---------------------------//
//          Globals          //
//---------------------------//

RollingAverage<int> averageSyncUpdateDelta { 1000000 };
std::unordered_map<void*, ExInfinityData> exInfinityDataMap{};
long long nLastScrollTime = 0;
bool bAutoScrollFirstTick = false;
long long nLastSyncUpdateTime = 0;
long long nLastTPSPrintTime = 0;
long long nNextLightSyncUpdateTick = -1;
long long nNextFullSyncUpdateTick = 0;
long long nRemainingScrollTime = 0;

bool bWasWorldActionbarOpen = false;
bool bWasWorldQuicklootOpen = false;
bool bWasWorldDialogOpen    = false;
bool bWasWorldMessagesOpen  = false;

//-----------------------------//
//          Functions          //
//-----------------------------//

///////////////////////////
// Miscellaneous Utility //
///////////////////////////

static SDL_Keymod operator|(const SDL_Keymod& a, const SDL_Keymod b)
{
	return static_cast<SDL_Keymod>(static_cast<__int32>(a) | static_cast<__int32>(b));
}

static SDL_Keymod operator&(const SDL_Keymod& a, const SDL_Keymod b)
{
	return static_cast<SDL_Keymod>(static_cast<__int32>(a) & static_cast<__int32>(b));
}

///////////////////////
// Scrolling Utility //
///////////////////////

static int clampStep(int distance, int speed, int minStep)
{
	if (std::abs(distance) <= std::abs(minStep)) return distance;
	const int nStep = distance / speed;
	return nStep >= 0 ? (std::max)(minStep, nStep) : (std::min)(nStep, -minStep);
}

static ExpScrollResult expScrollNumSteps(int src, int dst, int minStep, int threshold, int speed)
{
	if (dst > src)
	{
		minStep = -minStep;
	}

	int nStepAmount = (src - dst) / speed;

	if (nStepAmount == 0)
	{
		return { false, ExpScrollEndReason::GRANULARITY, 1 }; // Hit granularity limit; no progress can be made at higher speeds
	}

	bool hadNonMinStep = false;
	int nStepCount = 2;

	for (int cur = src;; ++nStepCount)
	{
		if (std::abs(nStepAmount) < std::abs(minStep))
		{
			nStepAmount = minStep;
		}
		else
		{
			hadNonMinStep = true;
		}

		cur -= nStepAmount;

		if (std::abs(cur - dst) <= threshold)
		{
			return { hadNonMinStep, ExpScrollEndReason::THRESHOLD, nStepCount };
		}

		nStepAmount = (cur - dst) / speed;

		if (nStepAmount == 0)
		{
			return { hadNonMinStep, ExpScrollEndReason::NORMAL, nStepCount };
		}
	}
}

static int expScrollScaleSpeedToTime(int src, int dst, int minStep, int threshold, int microsecondDelta, long long targetMicroseconds)
{
	if (std::abs(src - dst) <= threshold)
	{
		return 1;
	}

	for (int speed = 1;; ++speed)
	{
		const ExpScrollResult result = expScrollNumSteps(src, dst, minStep, threshold, speed);
		const ExpScrollEndReason endReason = result.endReason;
		const int nSteps = result.nStepCount;

		if (!result.bHadNonMinStep || endReason == ExpScrollEndReason::GRANULARITY || nSteps * microsecondDelta >= targetMicroseconds)
		{
			return speed;
		}
	}
}

static void fitViewPosition(CInfinity* pInfinity, int* pX, int* pY, CRect* pViewPort,
	bool usePreviousMenuState, bool bTheoretical)
{
	lua_State *const L = *p_g_lua;
	CBaldurChitin *const pChitin = *p_g_pBaldurChitin;
	CInfGame *const pGame = pChitin->m_pObjectGame;
	CScreenWorld *const pWorld = pChitin->m_pEngineWorld;

	const bool bShowBlackSpace = pGame->m_options.m_bShowBlackSpace;
	const int nViewPortWidth = pViewPort->right - pViewPort->left;
	const int nViewPortHeight = pViewPort->bottom - pViewPort->top;

	bool bSetNoScrollCursor = false;

	const float fEffectiveZoom = pChitin->pActiveEngine != pChitin->m_pEngineMap
		? pInfinity->m_fZoom
		: pWorld->m_fOriginalZoom;

	//////////////////////////////////////
	// Calculate allowed horizontal OOB //
	//////////////////////////////////////

	const int nAllowedOOBHorizontalBase = bShowBlackSpace ? nViewPortWidth / 2 : 0;

	int nAllowedOOBLeft = nAllowedOOBHorizontalBase;
	int nAllowedOOBRight = nAllowedOOBHorizontalBase;

	if (!p_uiIsHidden())
	{
		if (p_uiIsMenuOnStack(EngineVal<CString, false>{ "LEFT_SIDEBAR" }))
		{
			lua_getglobal(L, "Infinity_GetArea");
			lua_pushstring(L, "leftSidebarBackground");
			lua_callk(L, 1, 4, 0, nullptr);
			lua_settop(L, -2);
			const lua_Number nLeftSidebarBackgroundWidth = lua_tonumberx(L, -1, nullptr);
			lua_settop(L, -4);

			nAllowedOOBLeft = static_cast<int>(nAllowedOOBHorizontalBase + nLeftSidebarBackgroundWidth * fEffectiveZoom);
		}

		if (p_uiIsMenuOnStack(EngineVal<CString, false>{ "RIGHT_SIDEBAR" }))
		{
			lua_getglobal(L, "Infinity_GetArea");
			lua_pushstring(L, "rightSidebarBackground");
			lua_callk(L, 1, 4, 0, nullptr);
			lua_settop(L, -2);
			const lua_Number nRightSidebarBackgroundWidth = lua_tonumberx(L, -1, nullptr);
			lua_settop(L, -4);

			nAllowedOOBRight = static_cast<int>(nAllowedOOBHorizontalBase + nRightSidebarBackgroundWidth * fEffectiveZoom);
		}
	}

	////////////////
	// Check left //
	////////////////

	const int nAllowedWidth = pInfinity->nAreaX + nAllowedOOBLeft + nAllowedOOBRight;

	if (nViewPortWidth > nAllowedWidth)
	{
		// Center
		const int nNewX = (nAllowedWidth - nViewPortWidth) / 2 - nAllowedOOBLeft;

		if (*pX != nNewX)
		{
			// Snap - Viewport width too large
			*pX = nNewX;

			if (!bTheoretical)
			{
				pInfinity->m_ptCurrentPosExact.x = *pX * 10000;
				//bSetNoScrollCursor = true;

				if (pInfinity->m_ptScrollDest.x != -1)
				{
					pInfinity->m_ptScrollDest.x = *pX;
				}
			}
		}
	}
	else if (*pX < -nAllowedOOBLeft)
	{
		// Snap - x too far left
		*pX = -nAllowedOOBLeft;

		if (!bTheoretical)
		{
			pInfinity->m_ptCurrentPosExact.x = *pX * 10000;
			bSetNoScrollCursor = true;

			if (pInfinity->m_ptScrollDest.x != -1)
			{
				pInfinity->m_ptScrollDest.x = *pX;
			}
		}
	}
	else
	{
		const int nMaxAllowedXRight = (pInfinity->nAreaX - nViewPortWidth) + nAllowedOOBRight;

		if (*pX > nMaxAllowedXRight)
		{
			// Snap - x too far right
			*pX = nMaxAllowedXRight;

			if (!bTheoretical)
			{
				pInfinity->m_ptCurrentPosExact.x = *pX * 10000;
				bSetNoScrollCursor = true;

				if (pInfinity->m_ptScrollDest.x != -1)
				{
					pInfinity->m_ptScrollDest.x = *pX;
				}
			}
		}
	}

	////////////////////////////////////
	// Calculate allowed vertical OOB //
	////////////////////////////////////

	const int nAllowedOOBVerticalBase = bShowBlackSpace ? nViewPortHeight / 2 : 0;

	int nAllowedOOBBottom = 0;

	if (!p_uiIsHidden() && (usePreviousMenuState ? bWasWorldActionbarOpen : p_uiIsMenuOnStack(EngineVal<CString, false>{ "WORLD_ACTIONBAR" })))
	{
		nAllowedOOBBottom = static_cast<int>(60 * fEffectiveZoom);

		if (usePreviousMenuState ? bWasWorldQuicklootOpen : p_uiIsMenuOnStack(EngineVal<CString, false>{ "WORLD_QUICKLOOT" }))
		{
			nAllowedOOBBottom *= 2;
		}

		const char* sBottomItemName = nullptr;

		if (usePreviousMenuState ? bWasWorldDialogOpen : p_uiIsMenuOnStack(EngineVal<CString, false>{ "WORLD_DIALOG" }))
		{
			sBottomItemName = "worldDialogBackground";
		}
		else if (usePreviousMenuState ? bWasWorldMessagesOpen : p_uiIsMenuOnStack(EngineVal<CString, false>{ "WORLD_MESSAGES" }))
		{
			sBottomItemName = "messagesRect";
		}

		if (sBottomItemName != nullptr)
		{
			lua_getglobal(L, "Infinity_GetArea");
			lua_pushstring(L, sBottomItemName);
			lua_callk(L, 1, 4, 0, nullptr);
			const lua_Number nBottomMenuHeight = lua_tonumberx(L, -1, nullptr);
			lua_settop(L, -5);

			nAllowedOOBBottom = static_cast<int>(nAllowedOOBBottom + nBottomMenuHeight * fEffectiveZoom);
		}
	}

	nAllowedOOBBottom = (std::max)(nAllowedOOBVerticalBase, nAllowedOOBBottom);

	///////////////
	// Check top //
	///////////////

	const int nAllowedHeight = pInfinity->nAreaY + nAllowedOOBVerticalBase + nAllowedOOBBottom;

	if (nViewPortHeight > nAllowedHeight)
	{
		// Center
		const int nNewY = (nAllowedHeight - nViewPortHeight) / 2 - nAllowedOOBVerticalBase;

		if (*pY != nNewY)
		{
			// Snap - Viewport height too large
			*pY = nNewY;

			if (!bTheoretical)
			{
				pInfinity->m_ptCurrentPosExact.y = *pY * 10000;
				//bSetNoScrollCursor = true;

				if (pInfinity->m_ptScrollDest.y != -1)
				{
					pInfinity->m_ptScrollDest.y = *pY;
				}
			}
		}
	}
	else if (*pY < -nAllowedOOBVerticalBase)
	{
		// Snap - y too far up
		*pY = -nAllowedOOBVerticalBase;

		if (!bTheoretical)
		{
			pInfinity->m_ptCurrentPosExact.y = *pY * 10000;
			bSetNoScrollCursor = true;

			if (pInfinity->m_ptScrollDest.y != -1)
			{
				pInfinity->m_ptScrollDest.y = *pY;
			}
		}
	}
	else
	{
		const int nMaxAllowedYBottom = (pInfinity->nAreaY - nViewPortHeight) + nAllowedOOBBottom;

		if (*pY > nMaxAllowedYBottom)
		{
			// Snap - y too far down
			*pY = nMaxAllowedYBottom;

			if (!bTheoretical)
			{
				pInfinity->m_ptCurrentPosExact.y = *pY * 10000;
				bSetNoScrollCursor = true;

				if (pInfinity->m_ptScrollDest.y != -1)
				{
					pInfinity->m_ptScrollDest.y = *pY;
				}
			}
		}
	}

	/////////////////////////////////
	// Check "at world edge" state //
	/////////////////////////////////

	if (bSetNoScrollCursor)
	{
		CGameArea *const pArea = pGame->m_gameAreas[pGame->m_visibleArea];

		// Patch: Only reset the cursor if it is edge scrolling
		// |
		if (pArea != nullptr && pArea->m_nScrollState >= 1 && pArea->m_nScrollState <= 8)
		{
			pArea->m_nScrollState = 9;
			pChitin->m_pObjectCursor->SetCursor(6, 0, -1);
		}
	}
}

///////////
// Hooks //
///////////

void EEex::Fix_Hook_HandleMiddleMouseDrag(SDL_Event* pEvent)
{
	CBaldurChitin *const pChitin = *p_g_pBaldurChitin;
	CInfGame *const pGame = pChitin->m_pObjectGame;
	CInfinity *const pInfinity = &pGame->m_gameAreas[pGame->m_visibleArea]->m_cInfinity;

	if (EEex::UncapFPS_RemoveMiddleMouseScrollMultiplier)
	{
		CPoint exactWorldCoordinateSpacePoint;
		cursorToExactWorldCoordinateSpace(pInfinity, pEvent->motion.xrel, pEvent->motion.yrel, &exactWorldCoordinateSpacePoint);

		pInfinity->m_ptCurrentPosExact.x -= exactWorldCoordinateSpacePoint.x;
		pInfinity->m_ptCurrentPosExact.y -= exactWorldCoordinateSpacePoint.y;
	}
	else
	{
		pInfinity->m_ptCurrentPosExact.x -= static_cast<int>(pEvent->motion.xrel * 10000 * pInfinity->m_fZoom);
		pInfinity->m_ptCurrentPosExact.y -= static_cast<int>(pEvent->motion.yrel * 10000 * pInfinity->m_fZoom);
	}

	// Vanilla Bugfix: Properly reset exact coordinates if CInfinity::FitViewPosition() snaps
	// |
	// | pInfinity->SetViewPosition(pInfinity->m_ptCurrentPosExact.x / 10000, pInfinity->m_ptCurrentPosExact.y / 10000, 0);
	// |
	setViewPositionFromExact(pInfinity);

	pChitin->m_pEngineWorld->m_bMButtonDragged = 1;
}

void EEex::UncapFPS_Hook_OnAfterAreaEdgeScrollPossiblyStarted(CGameArea* pArea)
{
	if (pArea->m_nScrollState < 1 || pArea->m_nScrollState > 8)
	{
		// Not edge scrolling
		return;
	}

	int nTestOffsetX = 0;
	int nTestOffsetY = 0;

	switch (pArea->m_nScrollState)
	{
		case 1:                    nTestOffsetY = -1; break; //         Up
		case 2: nTestOffsetX =  1; nTestOffsetY = -1; break; // Right + Up
		case 3: nTestOffsetX =  1;                    break; // Right
		case 4: nTestOffsetX =  1; nTestOffsetY =  1; break; // Right + Down
		case 5:                    nTestOffsetY =  1; break; //         Down
		case 6: nTestOffsetX = -1; nTestOffsetY =  1; break; // Left  + Down
		case 7: nTestOffsetX = -1;                    break; // Left
		case 8: nTestOffsetX = -1; nTestOffsetY = -1; break; // Left  + Up
	}

	CInfinity *const pInfinity = &pArea->m_cInfinity;

	const int nTestX = pInfinity->nNewX + nTestOffsetX;
	const int nTestY = pInfinity->nNewY + nTestOffsetY;

	int nFitX = nTestX;
	int nFitY = nTestY;
	fitViewPosition(pInfinity, &nFitX, &nFitY, &pInfinity->rViewPort, false, true);

	if (nFitX != nTestX || nFitY != nTestY)
	{
		// Already hit the edge of the scrollable area. Preemptively stop the scrolling state so
		// the "scrolling" cursor doesn't flash - which can happen with the uncapped fps because
		// the scrolling system was reworked to operate on exact coordinates, which might take a
		// few frames for its small movements to accumulate to a full pixel, where the usual edge
		// detection takes place.

		pArea->m_nScrollState = 9;
		(*p_g_pBaldurChitin)->m_pObjectCursor->SetCursor(6, 0, -1);
	}
}

void EEex::UncapFPS_Hook_OnBeforeWorldScreenDeactivated()
{
	bWasWorldActionbarOpen = p_uiIsMenuOnStack(EngineVal<CString, false>{ "WORLD_ACTIONBAR" });
	bWasWorldQuicklootOpen = p_uiIsMenuOnStack(EngineVal<CString, false>{ "WORLD_QUICKLOOT" });
	bWasWorldDialogOpen    = p_uiIsMenuOnStack(EngineVal<CString, false>{ "WORLD_DIALOG"    });
	bWasWorldMessagesOpen  = p_uiIsMenuOnStack(EngineVal<CString, false>{ "WORLD_MESSAGES"  });
}

void EEex::UncapFPS_Hook_HandleAreaAutoZoom()
{
	CBaldurChitin *const pChitin = *p_g_pBaldurChitin;
	CScreenWorld *const pScreenWorld = pChitin->m_pEngineWorld;
	CInfGame *const pGame = pChitin->m_pObjectGame;
	CGameArea *const pArea = pGame->m_gameAreas[pGame->m_visibleArea];
	CInfinity *const pInfinity = &pArea->m_cInfinity;

	if (!pScreenWorld->m_bAutoZooming)
	{
		// Vanilla Bugfix: Maintain centering for small areas when the user resizes UI elements that allow OOB
		// |
		if (pChitin->pActiveEngine != pChitin->m_pEngineMap)
		{
			int x = pInfinity->nNewX;
			int y = pInfinity->nNewY;
			pInfinity->FitViewPosition(&x, &y, &pInfinity->rViewPort);
			pInfinity->nNewX = x;
			pInfinity->nNewY = y;
		}

		return;
	}

	// Patch: Keep track of auto zoom time delta
	// |
	ExInfinityData *const exInfinityData = &exInfinityDataMap[pInfinity];
	// |
	const long long nCurrentTime = getTime();
	const long long nDeltaT = nCurrentTime - exInfinityData->nLastAutoZoomTime;
	exInfinityData->nLastAutoZoomTime = nCurrentTime;

	// Patch: Calculate zoom percentage using time (instead of a static number of ticks)
	// |
	exInfinityData->nAutoZoomTimeRemaining = (std::max)(0LL, exInfinityData->nAutoZoomTimeRemaining - nDeltaT);

	CRect *const pViewPort = &pInfinity->rViewPort;

	// Patch: Calculate zoom percentage using time (instead of a static number of ticks)
	// |
	if (exInfinityData->nAutoZoomTimeRemaining == 0)
	{
		// Patch: Calculate zoom percentage using time (instead of a static number of ticks)
		// |
		// | pScreenWorld->m_nZoomCurStep = 0;

		pInfinity->SetZoom(pScreenWorld->m_fTargetZoom);

		const int nViewPortWidth  = pViewPort->right - pViewPort->left;
		const int nViewPortHeight = pViewPort->bottom - pViewPort->top;

		const int nTargetX = (pScreenWorld->m_ptTarget.x - nViewPortWidth / 2) * 10000;
		const int nTargetY = (pScreenWorld->m_ptTarget.y - nViewPortHeight / 2) * 10000;
		// |
		setViewPositionToExact(pInfinity, nTargetX, nTargetY);

		pScreenWorld->m_bAutoZooming = 0;
	}
	else
	{
		const float fPercentComplete = (AUTO_ZOOM_TARGET_TIME - exInfinityData->nAutoZoomTimeRemaining) / static_cast<float>(AUTO_ZOOM_TARGET_TIME);

		const float fZoomRange   = pScreenWorld->m_fTargetZoom - pScreenWorld->m_fPreviousZoom;
		const float fNewZoom     = pScreenWorld->m_fPreviousZoom + fZoomRange * fPercentComplete;

		pInfinity->SetZoom(fNewZoom);

		const int nPreviousX = pScreenWorld->m_ptPreviousView.x;
		const int nPreviousY = pScreenWorld->m_ptPreviousView.y;

		const int nViewPortWidth  = pViewPort->right - pViewPort->left;
		const int nViewPortHeight = pViewPort->bottom - pViewPort->top;

		const int nDeltaX = pScreenWorld->m_ptTarget.x - nPreviousX;
		const int nDeltaY = pScreenWorld->m_ptTarget.y - nPreviousY;

		// Patch: Scroll via exact coordinates
		// |
		// | const int nNewX = (nPreviousX - nViewPortWidth / 2) + static_cast<int>(nDeltaX * fZoomPercent);
		// | const int nNewY = (nPreviousY - nViewPortHeight / 2) + static_cast<int>(nDeltaY * fZoomPercent);
		// |
		// | pInfinity->SetViewPosition(nNewX, nNewY, 1);
		// |
		pInfinity->m_ptCurrentPosExact.x = (nPreviousX - nViewPortWidth / 2) * 10000 + static_cast<int>(nDeltaX * 10000 * fPercentComplete);
		pInfinity->m_ptCurrentPosExact.y = (nPreviousY - nViewPortHeight / 2) * 10000 + static_cast<int>(nDeltaY * 10000 * fPercentComplete);
		// |
		setViewPositionFromExact(pInfinity);
	}

	// Patch: Handle uncapped fps
	// |
	pArea->m_cGameAreaNotes.UpdateButtonPositions();
}

///////////////
// Overrides //
///////////////

static void trackSyncUpdateDelta(long long nStartTime)
{
	const int nSyncUpdateDelta = static_cast<int>(nStartTime - nLastSyncUpdateTime);
	nLastSyncUpdateTime = nStartTime;
	averageSyncUpdateDelta.push(nStartTime, nSyncUpdateDelta);
	averageSyncUpdateDelta.recalculate(nStartTime);

	//if (nStartTime - nLastTPSPrintTime >= 1000000)
	//{
	//	FPrint("tps: %d\n", 1000000 / averageSyncUpdateDelta.get());
	//	nLastTPSPrintTime = nStartTime;
	//}
}

void CChitin::Override_Update()
{
	const long long nStartTime = getTime();

	//////////////////////////////////////////////////////////////////////
	// Dump Lua values that were not properly cleaned up from the stack //
	//////////////////////////////////////////////////////////////////////

	lua_State *const L = *p_g_lua;

	for (int nIndex = lua_gettop(L); nIndex > 0; --nIndex)
	{
		const int nType = lua_type(L, nIndex);

		if (nType == LUA_TBOOLEAN)
		{
			p_SDL_Log("%d: %s", nIndex, lua_toboolean(L, nIndex) ? "true" : "false");
		}
		else if (nType == LUA_TNUMBER)
		{
			p_SDL_Log("%d: %g", nIndex, lua_tonumberx(L, nIndex, nullptr));
		}
		else if (nType == LUA_TSTRING)
		{
			p_SDL_Log("%d: %s", nIndex, lua_tolstring(L, nIndex, nullptr));
		}
		else
		{
			const char *const sTypeName = lua_typename(L, nType);

			if (sTypeName != nullptr)
			{
				p_SDL_Log("%d: %s", nIndex, sTypeName);
			}
			else
			{
				p_SDL_Log("%d: %d", nIndex, nType);
			}
		}
	}

	// Patch: Run "full ticks" at 30tps like normal, and (if uncapped) run in-between "light" ticks that only render the game
	// |
	if (!EEex::UncapFPS_Enabled || nStartTime >= nNextFullSyncUpdateTick)
	{
		trackSyncUpdateDelta(nStartTime);

		/////////////////
		// Search tick //
		/////////////////

		const uint nSearchStart = p_SDL_GetTicks();

		p_SearchThreadMain();

		this->m_nSearchTimer = p_SDL_GetTicks() - nSearchStart;

		/////////////////
		// Fade sounds //
		/////////////////

		p_fadeSounds();

		////////////////
		// Logic tick //
		////////////////

		const uint nAsyncStart = p_SDL_GetTicks();

		this->virtual_AsynchronousUpdate(0, 0, 0, 0, 0);

		this->m_nGameTimer = p_SDL_GetTicks() - nAsyncStart;

		/////////////////
		// Render tick //
		/////////////////

		const uint nSyncStart = p_SDL_GetTicks();

		this->m_displayStale = 1;

		if (this->m_displayStale == 1)
		{
			this->m_displayStale = 0;
			this->m_bInSyncUpdate = 1;
			this->virtual_SynchronousUpdate();
			this->m_bInSyncUpdate = 0;
			this->m_AIStale = 1;
		}

		this->m_nRenderTimer = p_SDL_GetTicks() - nSyncStart;

		//////////////////
		// Network tick //
		//////////////////

		this->cNetwork.ThreadLoop();

		////////////////////
		// All ticks done //
		////////////////////

		this->m_nFullFrameTimer = p_SDL_GetTicks() - nSearchStart;

		/////////////////////
		// tick_cucumber() //
		/////////////////////

		if (this->m_bEnableCucumber)
		{
			lua_getglobal(L, "tick_cucumber");

			if (lua_pcallk(L, 0, 0, 0, 0, nullptr) != LUA_OK)
			{
				p_SDL_Log("CUCUMBER: %s", lua_tolstring(L, -1, nullptr));
				lua_settop(L, -2);
			}
		}

		////////////////
		// Delay loop //
		////////////////

		// Patch: Don't sleep to target 30fps when uncapped
		// |
		if (!EEex::UncapFPS_Enabled)
		{
			const int nTargetMilliseconds = 1000 / *CChitin::p_TIMER_UPDATES_PER_SECOND;

			if (this->m_nFullFrameTimer < nTargetMilliseconds && !this->m_bManualFrameControl)
			{
				p_SDL_Delay(nTargetMilliseconds - this->m_nFullFrameTimer);
			}
		}
		else
		{
			const long long nEndTime = getTime();
			const long long nTimeTaken = nEndTime - nStartTime;

			const long long nTargetFullMicroseconds = 1000000 / *CChitin::p_TIMER_UPDATES_PER_SECOND - nTimeTaken;
			nNextFullSyncUpdateTick = nEndTime + nTargetFullMicroseconds;

			// Check reschedule light ticks if they are disabled
			if (nNextLightSyncUpdateTick == -1)
			{
				const int nEffectiveCap = EEex::UncapFPS_FPSLimit - *CChitin::p_TIMER_UPDATES_PER_SECOND;
				nNextLightSyncUpdateTick = nEffectiveCap > 0 ? nEndTime + 1000000 / nEffectiveCap - nTimeTaken : -1;
			}
		}

		/////////////////////
		// Log frame times //
		/////////////////////

		if
		(
			this->m_fFrameTimeLog != nullptr
			&&
			(
				(p_SDL_GetModState() & (SDL_Keymod::KMOD_RSHIFT | SDL_Keymod::KMOD_LSHIFT)) != SDL_Keymod::KMOD_NONE
				||
				this->m_bLogFrames
			)
		)
		{
			const char *const buffer = p_va("%d,%d,%d,%d,%d\n", p_SDL_GetTicks(), this->m_nRenderTimer, this->m_nGameTimer, this->m_nSearchTimer, this->m_nFullFrameTimer);

			size_t size = 0;
			for (; buffer[size] != '\0'; ++size);

			p_fwrite(buffer, size, 1, this->m_fFrameTimeLog);
		}
	}
	else if (nNextLightSyncUpdateTick != -1 && nStartTime >= nNextLightSyncUpdateTick)
	{
		trackSyncUpdateDelta(nStartTime);

		this->m_displayStale = 1;

		if (this->m_displayStale == 1)
		{
			this->m_displayStale = 0;
			this->m_bInSyncUpdate = 1;
			this->virtual_SynchronousUpdate();
			this->m_bInSyncUpdate = 0;
			this->m_AIStale = 1;
		}

		const long long nEndTime = getTime();
		const long long nTimeTaken = nEndTime - nStartTime;

		const int nEffectiveCap = EEex::UncapFPS_FPSLimit - *CChitin::p_TIMER_UPDATES_PER_SECOND;
		nNextLightSyncUpdateTick = nEffectiveCap > 0 ? nEndTime + 1000000 / nEffectiveCap - nTimeTaken : -1;
	}

	// Patch: If uncapped, sleep for a small amount so the main update loop doesn't hog the CPU
	// |
	if (EEex::UncapFPS_Enabled && EEex::UncapFPS_BusyWaitThreshold != 0)
	{
		const long long nNextTick = nNextLightSyncUpdateTick != -1 && nNextLightSyncUpdateTick < nNextFullSyncUpdateTick
			? nNextLightSyncUpdateTick
			: nNextFullSyncUpdateTick;

		const long long nDelayMilliseconds = (nNextTick - getTime()) / 1000;

		if (nDelayMilliseconds >= EEex::UncapFPS_BusyWaitThreshold)
		{
			p_SDL_Delay(static_cast<uint>(nDelayMilliseconds - EEex::UncapFPS_BusyWaitThreshold));
		}
	}
}

void CInfinity::Override_AdjustViewPosition(byte nScrollState)
{
	const uint nCurrentTick = p_SDL_GetTicks();
	// |
	// Patch: Scroll based on microsecond measurements (versus the millisecond-based vanilla implementation)
	// |
	// | const uint nDeltaT = nCurrentTick >= this->m_nLastTickCount
	// | 	? (std::min)(nCurrentTick - this->m_nLastTickCount, 500U)
	// | 	: 500U;
	// |
	this->m_nLastTickCount = nCurrentTick;
	// |
	const long long nCurrentTime = getTime();
	const int nScrollUpdateDelta = static_cast<int>(nCurrentTime - nLastScrollTime);
	const int nDeltaT = (std::max)(1, (std::min)(nScrollUpdateDelta, 500000));
	nLastScrollTime = nCurrentTime;

	// Not scrolling
	if (nScrollState == 0)
	{
		return;
	}

	// Hit edge of scrollable area
	if (nScrollState == 9)
	{
		return;
	}

	// Stop auto scrolling
	this->m_ptScrollDest.x = -1;
	this->m_ptScrollDest.y = -1;

	CBaldurChitin *const pChitin = *p_g_pBaldurChitin;
	CInfGame *const pGame = pChitin->m_pObjectGame;

	const int nSpeedBase = static_cast<int>(
		static_cast<float>(*CVidMode::p_SCREENHEIGHT)        // Internal resolution height
		/ pChitin->cVideo.pCurrentMode->nHeight              // Window height
		/ (*CInfinity::p_MAXZOOM_OUT + 1.0f - this->m_fZoom) // Zoom factor
		* pGame->GetScrollSpeed());                          // Scroll speed

	// Patch: Scroll based on microsecond measurements (versus the millisecond-based vanilla implementation)
	// |
	// | const int nSpeedFast   = nSpeedBase * 200;
	// | const int nSpeedMedium = nSpeedBase * 150;
	// | const int nSpeedSlow   = nSpeedBase * 100;
	// |
	const float nSpeedSlow   = nSpeedBase * 0.1f;
	const float nSpeedMedium = nSpeedSlow * 1.5f;
	const float nSpeedFast   = nSpeedSlow * 2.0f;

	// Vanilla Bugfix: Don't reset exact-coordinate movement
	// |
	// | const int nExactX = this->nNewX * 10000;
	// | const int nExactY = this->nNewY * 10000;
	// |
	// | this->m_ptCurrentPosExact.x = nExactX;
	// | this->m_ptCurrentPosExact.y = nExactY;
	// |
	const int nExactX = this->m_ptCurrentPosExact.x;
	const int nExactY = this->m_ptCurrentPosExact.y;

	// Vanilla Bugfix: Properly reset exact coordinates if CInfinity::FitViewPosition() snaps
	// |
	// | int nDestX;
	// | int nDestY;

	switch (nScrollState)
	{
		case 1: // Up
		{
			const int nExactDestY = nExactY - static_cast<int>(nDeltaT * nSpeedMedium);

			// Vanilla Bugfix: Properly reset exact coordinates if CInfinity::FitViewPosition() snaps
			// |
			// | nDestX = nExactX / 10000;
			// | nDestY = nExactDestY / 10000;

			this->m_ptCurrentPosExact.y = nExactDestY;
			break;
		}
		case 2: // Right + Up
		{
			const int nExactDestX = nExactX + static_cast<int>(nDeltaT * nSpeedMedium);
			const int nExactDestY = nExactY - static_cast<int>(nDeltaT * nSpeedSlow);

			// Vanilla Bugfix: Properly reset exact coordinates if CInfinity::FitViewPosition() snaps
			// |
			// | nDestX = nExactDestX / 10000;
			// | nDestY = nExactDestY / 10000;

			this->m_ptCurrentPosExact.x = nExactDestX;
			this->m_ptCurrentPosExact.y = nExactDestY;
			break;
		}
		case 3: // Right
		{
			const int nExactDestX = nExactX + static_cast<int>(nDeltaT * nSpeedFast);

			// Vanilla Bugfix: Properly reset exact coordinates if CInfinity::FitViewPosition() snaps
			// |
			// | nDestX = nExactDestX / 10000;
			// | nDestY = nExactY / 10000;

			this->m_ptCurrentPosExact.x = nExactDestX;
			break;
		}
		case 4: // Right + Down
		{
			const int nExactDestX = nExactX + static_cast<int>(nDeltaT * nSpeedMedium);
			const int nExactDestY = nExactY + static_cast<int>(nDeltaT * nSpeedSlow);

			// Vanilla Bugfix: Properly reset exact coordinates if CInfinity::FitViewPosition() snaps
			// |
			// | nDestX = nExactDestX / 10000;
			// | nDestY = nExactDestY / 10000;

			this->m_ptCurrentPosExact.x = nExactDestX;
			this->m_ptCurrentPosExact.y = nExactDestY;
			break;
		}
		case 5: // Down
		{
			const int nExactDestY = nExactY + static_cast<int>(nDeltaT * nSpeedMedium);

			// Vanilla Bugfix: Properly reset exact coordinates if CInfinity::FitViewPosition() snaps
			// |
			// | nDestX = nExactX / 10000;
			// | nDestY = nExactDestY / 10000;

			this->m_ptCurrentPosExact.y = nExactDestY;
			break;
		}
		case 6: // Left + Down
		{
			const int nExactDestX = nExactX - static_cast<int>(nDeltaT * nSpeedMedium);
			const int nExactDestY = nExactY + static_cast<int>(nDeltaT * nSpeedSlow);

			// Vanilla Bugfix: Properly reset exact coordinates if CInfinity::FitViewPosition() snaps
			// |
			// | nDestX = nExactDestX / 10000;
			// | nDestY = nExactDestY / 10000;

			this->m_ptCurrentPosExact.x = nExactDestX;
			this->m_ptCurrentPosExact.y = nExactDestY;
			break;
		}
		case 7: // Left
		{
			const int nExactDestX = nExactX - static_cast<int>(nDeltaT * nSpeedFast);

			// Vanilla Bugfix: Properly reset exact coordinates if CInfinity::FitViewPosition() snaps
			// |
			// | nDestX = nExactDestX / 10000;
			// | nDestY = nExactY / 10000;

			this->m_ptCurrentPosExact.x = nExactDestX;
			break;
		}
		case 8: // Left + Up
		{
			const int nExactDestX = nExactX - static_cast<int>(nDeltaT * nSpeedMedium);
			const int nExactDestY = nExactY - static_cast<int>(nDeltaT * nSpeedSlow);

			// Vanilla Bugfix: Properly reset exact coordinates if CInfinity::FitViewPosition() snaps
			// |
			// | nDestX = nExactDestX / 10000;
			// | nDestY = nExactDestY / 10000;

			this->m_ptCurrentPosExact.x = nExactDestX;
			this->m_ptCurrentPosExact.y = nExactDestY;
			break;
		}
		default:
		{
			return;
		}
	}

	// Vanilla Bugfix: Properly reset exact coordinates if CInfinity::FitViewPosition() snaps
	// |
	// | this->FitViewPosition(&nDestX, &nDestY, &this->rViewPort);
	// | this->nNewX = nDestX;
	// | this->nNewY = nDestY;
	// |
	setViewPositionFromExact(this);
}

// Vanilla Implementation - So broken it's been rewritten

//void CInfinity::Override_FitViewPosition(int* pX, int* pY, CRect* pViewPort)
//{
//	lua_State *const L = *p_g_lua;
//	CBaldurChitin *const pChitin = *p_g_pBaldurChitin;
//	CInfGame *const pGame = pChitin->m_pObjectGame;
//
//	const bool bShowBlackSpace = pGame->m_options.m_bShowBlackSpace;
//	const int nViewPortWidth = pViewPort->right - pViewPort->left;
//	const int nViewPortHeight = pViewPort->bottom - pViewPort->top;
//
//	bool bSnapped = false;
//
//	//////////////////////////////////////
//	// Calculate allowed horizontal OOB //
//	//////////////////////////////////////
//
//	const int nAllowedOOBHorizontalBase = bShowBlackSpace ? nViewPortWidth / 2 : 0;
//
//	int nAllowedOOBLeft = nAllowedOOBHorizontalBase;
//	int nAllowedOOBRight = nAllowedOOBHorizontalBase;
//
//	if (!p_uiIsHidden())
//	{
//		if (p_uiIsMenuOnStack(EngineVal<CString, false>{ "LEFT_SIDEBAR" }))
//		{
//			lua_getglobal(L, "Infinity_GetArea");
//			lua_pushstring(L, "leftSidebarBackground");
//			lua_callk(L, 1, 4, 0, nullptr);
//			lua_settop(L, -2);
//			const lua_Number nLeftSidebarBackgroundWidth = lua_tonumberx(L, -1, nullptr);
//			lua_settop(L, -4);
//
//			nAllowedOOBLeft = static_cast<int>(nAllowedOOBHorizontalBase + nLeftSidebarBackgroundWidth * this->m_fZoom);
//		}
//
//		if (p_uiIsMenuOnStack(EngineVal<CString, false>{ "RIGHT_SIDEBAR" }))
//		{
//			lua_getglobal(L, "Infinity_GetArea");
//			lua_pushstring(L, "rightSidebarBackground");
//			lua_callk(L, 1, 4, 0, nullptr);
//			lua_settop(L, -2);
//			const lua_Number nRightSidebarBackgroundWidth = lua_tonumberx(L, -1, nullptr);
//			lua_settop(L, -4);
//
//			nAllowedOOBRight = static_cast<int>(nAllowedOOBHorizontalBase + nRightSidebarBackgroundWidth * this->m_fZoom);
//		}
//	}
//
//	////////////////
//	// Check left //
//	////////////////
//
//	const int nNegAllowedOOBLeft = -nAllowedOOBLeft;
//
//	if (*pX < nNegAllowedOOBLeft)
//	{
//		// Snap - x too far left
//		*pX = nNegAllowedOOBLeft;
//		                          // Vanilla Bug: Not snapping exact coord
//		bSnapped = true;
//
//		// Vanilla Bug: Not clamping auto scroll
//	}
//
//	/////////////////
//	// Check right //
//	/////////////////
//
//	int nMaxAllowedXRight = (this->nAreaX - nViewPortWidth) + nAllowedOOBRight;
//	bool bNeedHorizontalSnap = false;
//
//	if (*pX < 0)
//	{
//		// Horizontally center if the area width is smaller than the viewport
//		if (*pX >= nMaxAllowedXRight / 2)
//		{
//			nMaxAllowedXRight /= 2;
//			bNeedHorizontalSnap = true;
//		}
//	}
//	else if (*pX > nMaxAllowedXRight)
//	{
//		bNeedHorizontalSnap = true;
//	}
//
//	if (bNeedHorizontalSnap)
//	{
//		// TODO: What is this doing?
//		if (nMaxAllowedXRight > 0)
//		{
//			nMaxAllowedXRight = (std::min)(*pX, nMaxAllowedXRight);
//		}
//
//		// Snap - x too far right
//		*pX = nMaxAllowedXRight;
//		this->m_ptCurrentPosExact.x = nMaxAllowedXRight * 10000;
//		bSnapped = true;
//
//		if (this->m_ptScrollDest.x != -1)
//		{
//			this->m_ptScrollDest.x = *pX;
//		}
//	}
//
//	////////////////////////////////////
//	// Calculate allowed vertical OOB //
//	////////////////////////////////////
//
//	const int nAllowedOOBVerticalBase = bShowBlackSpace ? nViewPortHeight / 2 : 0;
//
//	int nAllowedOOBBottom = 0;
//
//	if (!p_uiIsHidden() && p_uiIsMenuOnStack(EngineVal<CString, false>{ "WORLD_ACTIONBAR" }))
//	{
//		nAllowedOOBBottom = static_cast<int>(60 * this->m_fZoom);
//
//		if (p_uiIsMenuOnStack(EngineVal<CString, false>{ "WORLD_QUICKLOOT" }))
//		{
//			nAllowedOOBBottom *= 2;
//		}
//
//		const char* sBottomItemName = nullptr;
//
//		if (p_uiIsMenuOnStack(EngineVal<CString, false>{ "WORLD_DIALOG" }))
//		{
//			sBottomItemName = "worldDialogBackground";
//		}
//		else if (p_uiIsMenuOnStack(EngineVal<CString, false>{ "WORLD_MESSAGES" }))
//		{
//			sBottomItemName = "messagesRect";
//		}
//
//		if (sBottomItemName != nullptr)
//		{
//			lua_getglobal(L, "Infinity_GetArea");
//			lua_pushstring(L, sBottomItemName);
//			lua_callk(L, 1, 4, 0, nullptr);
//			const lua_Number nBottomMenuHeight = lua_tonumberx(L, -1, nullptr);
//			lua_settop(L, -5);
//
//			nAllowedOOBBottom = static_cast<int>(nAllowedOOBBottom + nBottomMenuHeight * this->m_fZoom);
//		}
//	}
//
//	nAllowedOOBBottom = (std::max)(nAllowedOOBVerticalBase, nAllowedOOBBottom);
//
//	///////////////
//	// Check top //
//	///////////////
//
//	const int nNegAllowedOOBVerticalBase = -nAllowedOOBVerticalBase;
//
//	if (*pY < nNegAllowedOOBVerticalBase)
//	{
//		// Snap - y too far up
//		*pY = nNegAllowedOOBVerticalBase;
//		this->m_ptCurrentPosExact.y = nNegAllowedOOBVerticalBase; // Vanilla Bug: Setting exact coordinates without multiplying by 10,000
//		bSnapped = true;
//
//		// Vanilla Bug: Not clamping auto scroll
//	}
//
//	//////////////////
//	// Check bottom //
//	//////////////////
//
//	int nMaxAllowedYBottom = (this->nAreaY - nViewPortHeight) + nAllowedOOBBottom;
//
//	bool bNeedVerticalSnap = false;
//
//	if (*pY < 0)
//	{
//		// Vertically center if the area width is smaller than the viewport
//		if (*pY >= nMaxAllowedYBottom / 2)
//		{
//			nMaxAllowedYBottom /= 2;
//			bNeedVerticalSnap = true;
//		}
//	}
//	else if (*pY > nMaxAllowedYBottom)
//	{
//		bNeedVerticalSnap = true;
//	}
//
//	if (bNeedVerticalSnap)
//	{
//		// Snap - y too far down
//		*pY = nMaxAllowedYBottom;
//		this->m_ptCurrentPosExact.y = nMaxAllowedYBottom * 10000;
//		bSnapped = true;
//
//		if (this->m_ptScrollDest.y != -1)
//		{
//			this->m_ptScrollDest.y = *pY;
//		}
//	}
//
//	/////////////////////////////////
//	// Check "at world edge" state //
//	/////////////////////////////////
//
//	if (bSnapped)
//	{
//		CGameArea *const pArea = pGame->m_gameAreas[pGame->m_visibleArea];
//
//		if (pArea != nullptr)
//		{
//			pArea->m_nScrollState = 9;
//		}
//
//		pChitin->m_pObjectCursor->SetCursor(6, 0, -1);
//	}
//}

void CInfinity::Override_FitViewPosition(int* pX, int* pY, CRect* pViewPort)
{
	CBaldurChitin *const pChitin = *p_g_pBaldurChitin;

	// Don't fit the view if the game is transitioning between engines or the local map is zooming.
	if (!pChitin->bEngineActive || pChitin->m_pEngineWorld->m_bAutoZooming)
	{
		return;
	}

	fitViewPosition(this, pX, pY, pViewPort, false, false);
}

// Used by:
//
//     CGameAIBase::MoveView()
//         CGameAIBase::MoveViewPoint()     | action 49  | speed: m_specificID
//         CGameAIBase::MoveViewObject()    | action 50  | speed: m_specificID
//         CGameSprite::LeaveAreaLUA()      | action 110 | speed: -1
//         CGameSprite::LeaveAreaLUAEntry() | action 350 | speed: -1
//                                          |            |
//     CGameDialogEntry::Display()          | Dialog     | speed: 0 or -4

void CInfinity::Override_Scroll(CPoint ptDest, short speed)
{
	const int nCurrentTick = p_SDL_GetTicks();
	// |
	// Patch: Scroll based on microsecond measurements (versus the millisecond-based vanilla implementation)
	// |
	// | const uint nDeltaT = nCurrentTick >= this->m_nLastTickCount
	// | 	? (std::min)(nCurrentTick - this->m_nLastTickCount, 500U)
	// | 	: 500U;
	// |
	this->m_nLastTickCount = nCurrentTick;
	// |
	const long long nCurrentTime = getTime();
	const int nScrollUpdateDelta = bAutoScrollFirstTick ? averageSyncUpdateDelta.getLast() : static_cast<int>(nCurrentTime - nLastScrollTime);
	const int nDeltaT = (std::max)(1, (std::min)(nScrollUpdateDelta, 500000));
	bAutoScrollFirstTick = false;
	nLastScrollTime = nCurrentTime;

	const int nOldX = this->nNewX;
	const int nOldY = this->nNewY;
	const int nSpeedAbs = static_cast<short>(abs(speed));

	if (speed < 0)
	{
		// Exponential scroll that moves by `delta / speed` every tick
		
		nRemainingScrollTime = (std::max)(0LL, nRemainingScrollTime - nDeltaT);

		// Patch: Scroll via exact coordinates
		// | 
		// | const int nStepX = (this->nNewX - ptDest.x) / nSpeedAbs;
		// | const int nStepY = (this->nNewY - ptDest.y) / nSpeedAbs;
		// |
		ExInfinityData& exInfinityData = exInfinityDataMap[this];
		// |
		const int nExactDestX = ptDest.x * 10000;
		const int nExactDestY = ptDest.y * 10000;
		// |
		const int nExactDeltaX = this->m_ptCurrentPosExact.x - nExactDestX;
		const int nExactDeltaY = this->m_ptCurrentPosExact.y - nExactDestY;
		// |
		const int nScaledSpeedX = expScrollScaleSpeedToTime(this->m_ptCurrentPosExact.x, nExactDestX, EXP_SCROLL_MIN_STEP, EXP_SCROLL_THRESHOLD, nDeltaT, nRemainingScrollTime);
		const int nScaledSpeedY = expScrollScaleSpeedToTime(this->m_ptCurrentPosExact.y, nExactDestY, EXP_SCROLL_MIN_STEP, EXP_SCROLL_THRESHOLD, nDeltaT, nRemainingScrollTime);
		// |
		const int nStepX = clampStep(nExactDeltaX, nScaledSpeedX, EXP_SCROLL_MIN_STEP);
		const int nStepY = clampStep(nExactDeltaY, nScaledSpeedY, EXP_SCROLL_MIN_STEP);

		//FPrint("Time remaining: %lld, nDeltaT: %d, (%d/%d)=%d (%d/%d)=%d\n", nRemainingScrollTime, nDeltaT, nExactDeltaX, nScaledSpeedX, nStepX, nExactDeltaY, nScaledSpeedY, nStepY);

		// Vanilla Bugfix - Only end if both x and y scrolling is done
		// |
		// | if (nStepX == 0 || nStepY == 0)
		// | if (nStepX == 0 && nStepY == 0) // <-- Fix
		// |
		// Patch: Implement threshold to stop exponential scrolling from executing extremely small movements near the target
		// |
		if
		(
			(nStepX == 0 && nStepY == 0)
			||
			(std::abs(nExactDeltaX) <= EXP_SCROLL_THRESHOLD && std::abs(nExactDeltaY) <= EXP_SCROLL_THRESHOLD)
		)
		{
			// Vanilla Bugfix: Snapping to final destination should also set exact coordinates
			// |
			// Vanilla Bugfix: Properly reset exact coordinates if CInfinity::FitViewPosition() snaps
			// |
			// | int nDestX = ptDest.x;
			// | int nDestY = ptDest.y;
			// | this->FitViewPosition(&nDestX, &nDestY, &this->rViewPort);
			// | this->nNewX = nDestX;
			// | this->nNewY = nDestY;
			// |
			setViewPositionToExact(this, nExactDestX, nExactDestY);

			// Stop auto scrolling
			this->m_ptScrollDest.x = -1;
			this->m_ptScrollDest.y = -1;
		}
		else
		{
			// Patch: Scroll via exact coordinates
			// |
			// | int nDestX = this->nNewX - nStepX;
			// | int nDestY = this->nNewY - nStepY;
			// | this->FitViewPosition(&nDestX, &nDestY, &this->rViewPort);
			// | this->nNewX = nDestX;
			// | this->nNewY = nDestY;
			// |
			// | this->m_ptCurrentPosExact.x = nDestX * 10000;
			// | this->m_ptCurrentPosExact.y = nDestY * 10000;
			// |
			this->m_ptCurrentPosExact.x -= nStepX;
			this->m_ptCurrentPosExact.y -= nStepY;

			// Vanilla Bugfix: Properly reset exact coordinates if CInfinity::FitViewPosition() snaps
			// |
			// | int nDestX = this->m_ptCurrentPosExact.x / 10000;
			// | int nDestY = this->m_ptCurrentPosExact.y / 10000;
			// | this->FitViewPosition(&nDestX, &nDestY, &this->rViewPort);
			// | this->nNewX = nDestX;
			// | this->nNewY = nDestY;
			// |
			setViewPositionFromExact(this);
		}
	}
	else if (speed == 0)
	{
		// Moving instantly

		// Vanilla Bugfix: Properly reset exact coordinates if CInfinity::FitViewPosition() snaps
		// |
		// | int nDestX = ptDest.x;
		// | int nDestY = ptDest.y;
		// | this->FitViewPosition(&nDestX, &nDestY, &this->rViewPort);
		// | this->nNewX = nDestX;
		// | this->nNewY = nDestY;
		// |
		// | this->m_ptCurrentPosExact.x = nDestX * 10000;
		// | this->m_ptCurrentPosExact.y = nDestY * 10000;
		// |
		setViewPositionToExact(this, ptDest.x * 10000, ptDest.y * 10000);

		// Stop auto scrolling
		this->m_ptScrollDest.x = -1;
		this->m_ptScrollDest.y = -1;
		return;
	}
	else
	{
		const int nExactDestX = ptDest.x * 10000;
		const int nExactDestY = ptDest.y * 10000;

		const int nExactDestDeltaX = nExactDestX - this->m_ptCurrentPosExact.x;
		const int nExactDestDeltaY = nExactDestY - this->m_ptCurrentPosExact.y;

		// Patch: Scroll based on microsecond measurements (versus the millisecond-based vanilla implementation)
		// |
		// | const int nSpeedExactSlow   = nSpeedAbs * nDeltaT * 100;
		// | const int nSpeedExactMedium = nSpeedAbs * nDeltaT * 150;
		// | const int nSpeedExactFast   = nSpeedAbs * nDeltaT * 200;
		// |
		const float nSpeedExactBase = nSpeedAbs * nDeltaT * 0.1f;
		const int nSpeedExactSlow   = static_cast<int>(nSpeedExactBase);
		const int nSpeedExactMedium = static_cast<int>(nSpeedExactBase * 1.5f);
		const int nSpeedExactFast   = static_cast<int>(nSpeedExactBase * 2.0f);

		if (nExactDestDeltaX < -nSpeedExactFast || nExactDestDeltaX > nSpeedExactFast)
		{
			// Not moving fast enough horizontally to complete

			if (nExactDestDeltaX > 0 && nExactDestDeltaY <= 6 && nExactDestDeltaY >= -nSpeedExactMedium)
			{
				// Moving right and (down <= 6 or up vertically fast enough to complete)
				//
				// Why does moving down have the weird hardcoded threshold?
				//     Vanilla Bug: Allows the scroll to overshoot for one frame.

				this->m_ptCurrentPosExact.x += nSpeedExactFast;
				this->m_ptCurrentPosExact.y = nExactDestY;
			}
			else if (nExactDestDeltaX < 0 && nExactDestDeltaY <= 6 && nExactDestDeltaY >= -nSpeedExactMedium)
			{
				// Moving left and (down <= 6 or up vertically fast enough to complete)
				//
				// Why does moving down have the weird hardcoded threshold?
				//     Vanilla Bug: Allows the scroll to overshoot for one frame.

				this->m_ptCurrentPosExact.x -= nSpeedExactFast;
				this->m_ptCurrentPosExact.y = nExactDestY;
			}
			else if (nExactDestDeltaX > 0 && nExactDestDeltaY > 0)
			{
				// Moving right and down
				this->m_ptCurrentPosExact.x += nSpeedExactMedium;
				this->m_ptCurrentPosExact.y += nSpeedExactSlow;
			}
			else if (nExactDestDeltaX < 0 && nExactDestDeltaY > 0)
			{
				// Moving left and down
				this->m_ptCurrentPosExact.x -= nSpeedExactMedium;
				this->m_ptCurrentPosExact.y += nSpeedExactSlow;
			}
			else if (nExactDestDeltaX > 0 && nExactDestDeltaY < 0)
			{
				// Moving right and up
				this->m_ptCurrentPosExact.x += nSpeedExactMedium;
				this->m_ptCurrentPosExact.y -= nSpeedExactSlow;
			}
			else if (nExactDestDeltaX < 0 && nExactDestDeltaY < 0)
			{
				// Moving left and up
				this->m_ptCurrentPosExact.x -= nSpeedExactMedium;
				this->m_ptCurrentPosExact.y -= nSpeedExactSlow;
			}

			// Vanilla Bugfix: Properly reset exact coordinates if CInfinity::FitViewPosition() snaps
			// |
			// | int nDestX = this->m_ptCurrentPosExact.x / 10000;
			// | int nDestY = this->m_ptCurrentPosExact.y / 10000;
			// | this->FitViewPosition(&nDestX, &nDestY, &this->rViewPort);
			// | this->nNewX = nDestX;
			// | this->nNewY = nDestY;
			// |
			setViewPositionFromExact(this);
		}
		else if (nExactDestDeltaY >= -nSpeedExactMedium && nExactDestDeltaY <= nSpeedExactMedium)
		{
			// Moving fast enough horizontally to complete, moving vertically fast enough to complete

			// Vanilla Bugfix: Properly reset exact coordinates if CInfinity::FitViewPosition() snaps
			// |
			// | this->m_ptCurrentPosExact.x = nExactDestX;
			// | this->m_ptCurrentPosExact.y = nExactDestY;
			// |
			// | int nDestX = this->m_ptCurrentPosExact.x / 10000;
			// | int nDestY = this->m_ptCurrentPosExact.y / 10000;
			// | this->FitViewPosition(&nDestX, &nDestY, &this->rViewPort);
			// | this->nNewX = nDestX;
			// | this->nNewY = nDestY;
			// |
			setViewPositionToExact(this, nExactDestX, nExactDestY);

			// Stop auto scrolling
			this->m_ptScrollDest.x = -1;
			this->m_ptScrollDest.y = -1;
			return;
		}
		else
		{
			// Moving fast enough horizontally to complete, not moving vertically fast enough to complete

			this->m_ptCurrentPosExact.x = nExactDestX;
			this->m_ptCurrentPosExact.y = nExactDestDeltaY <= 0
				? this->m_ptCurrentPosExact.y - nSpeedExactMedium  // Moving up
				: this->m_ptCurrentPosExact.y + nSpeedExactMedium; // Moving down

			// Vanilla Bugfix: Properly reset exact coordinates if CInfinity::FitViewPosition() snaps
			// |
			// | int nDestX = this->m_ptCurrentPosExact.x / 10000;
			// | int nDestY = this->m_ptCurrentPosExact.y / 10000;
			// | this->FitViewPosition(&nDestX, &nDestY, &this->rViewPort);
			// | this->nNewX = nDestX;
			// | this->nNewY = nDestY;
			// |
			setViewPositionFromExact(this);
		}
	}

	// Vanilla bug: This failsafe can't be triggered due to `m_nScrollAttempts` being immediately reset
	if (nOldX == this->nNewX && nOldY == this->nNewY && this->m_nScrollAttempts++ == 10)
	{
		this->m_ptScrollDest.x = -1;
		this->m_ptScrollDest.y = -1;
	}

	this->m_nScrollAttempts = 0;
}

void CInfinity::Override_SetScrollDest(CPoint* ptDest)
{
	// Patch: Keep track of "last scroll time" in microseconds
	// |
	nLastScrollTime = getTime();
	bAutoScrollFirstTick = true;

	this->m_ptScrollDest = *ptDest;
	this->m_nLastTickCount = p_SDL_GetTicks();

	CInfGame *const pGame = (*p_g_pBaldurChitin)->m_pObjectGame;
	CInfinity *const pInfinity = &pGame->m_gameAreas[pGame->m_visibleArea]->m_cInfinity;

	if (!pGame->m_options.m_bShowBlackSpace)
	{
		if (this->m_ptScrollDest.x < 0)
		{
			this->m_ptScrollDest.x = 0;
		}
		else if (this->m_ptScrollDest.x > pInfinity->nAreaX)
		{
			this->m_ptScrollDest.x = pInfinity->nAreaX;
		}

		if (this->m_ptScrollDest.y < 0)
		{
			this->m_ptScrollDest.y = 0;
		}
		else if (this->m_ptScrollDest.y > pInfinity->nAreaY)
		{
			this->m_ptScrollDest.y = pInfinity->nAreaY;
		}
	}
}

void CScreenMap::Override_CenterViewPort(CPoint* ptPoint)
{
	CBaldurChitin *const pChitin = *p_g_pBaldurChitin;
	CInfGame *const pGame = pChitin->m_pObjectGame;
	CInfinity *const pInfinity = &pGame->m_gameAreas[pGame->m_visibleArea]->m_cInfinity;
	CScreenWorld *const pWorld = pChitin->m_pEngineWorld;

	CPoint worldPoint;
	pInfinity->ScreenToWorld(&worldPoint, ptPoint);

	CRect *const pOriginalViewPort = &pWorld->m_rOriginalViewPort;
	const int nOriginalViewPortCenterX = (pOriginalViewPort->right - pOriginalViewPort->left) / 2;
	const int nOriginalViewPortCenterY = (pOriginalViewPort->bottom - pOriginalViewPort->top) / 2;

	int nX = worldPoint.x - nOriginalViewPortCenterX;
	int nY = worldPoint.y - nOriginalViewPortCenterY;
	// |
	// Patch: Directly call EEex's reimplementation (instead of the shim) to force fit even though the map engine is active
	// |
	fitViewPosition(pInfinity, &nX, &nY, &pWorld->m_rOriginalViewPort, true, true);

	pWorld->m_ptOriginalView.x = nX + nOriginalViewPortCenterX;
	pWorld->m_ptOriginalView.y = nY + nOriginalViewPortCenterY;
}

//void CScreenMap::Override_OnLButtonUp(CPoint cPoint)
//{
//	local_res10 = cPoint;
//	bVar4 = uiIsPointOverMenu((g_pBaldurChitin->baseclass).cMousePosition);
//
//	if (bVar4)
//	{
//		return;
//	}
//
//	g_pBaldurChitin->m_pObjectCursor->nState = 0;
//	CScreenMap::CenterViewPort(this,&local_res10);
//
//	if (this->m_pArea != (CGameArea *)0x0)
//	{
//		local_res18 = cPoint;
//		CInfinity::ScreenToWorld(
//			&g_pBaldurChitin->m_pObjectGame->m_gameAreas[g_pBaldurChitin->m_pObjectGame->m_visibleArea]->m_cInfinity,
//			&local_res20,
//			&local_res18
//		);
//
//		pCVar1 = g_pBaldurChitin->m_pEngineMap;
//
//		if (pCVar1->m_nClairvoyanceCaster != -1)
//		{
//			if (pCVar1->m_bClairvoyanceCastInBlack == '\0')
//			{
//				pCVar2 = this->m_pArea;
//				sVar6 = (short)((longlong)((ulonglong)(uint)(local_res20.x >> 0x1f) << 0x20 | (ulonglong)local_res20 & 0xffffffff) / 0x20) +
//						(short)((longlong)((ulonglong)(uint)(local_res20.y >> 0x1f) << 0x20 | (ulonglong)local_res20 >> 0x20) / 0x20) *
//						(pCVar2->m_visibility).m_nWidth;
//
//				if (sVar6 < 0)
//				{
//					return;
//				}
//
//				if ((pCVar2->m_visibility).m_nMapSize <= (int)sVar6)
//				{
//					return;
//				}
//
//				if (((pCVar2->m_visibility).m_pMap[sVar6] & 0x8000) == 0)
//				{
//					return;
//				}
//			}
//
//			bVar5 = CGameObjectArray::GetDeny(pCVar1->m_nClairvoyanceCaster,(CGameObject **)&local_res18);
//
//			if (bVar5 == 0)
//			{
//				CGameArea::AddClairvoyanceObject(this->m_pArea,(CGameSprite *)local_res18,local_res20,pCVar1->m_nClairvoyanceDuration);
//			}
//
//			pCVar1->m_nClairvoyanceCaster = -1;
//			pCVar1->m_nClairvoyanceDuration = 0;
//			pCVar1->m_bClairvoyanceCastInBlack = '\0';
//			pCVar3 = (g_pBaldurChitin->baseclass).pActiveEngine;
//			pCVar3->virtual_SelectEngine(g_pBaldurChitin->m_pEngineWorld);
//		}
//	}
//}

void CScreenWorld::Override_ResetZoom()
{
	this->m_ptPreviousView = this->m_ptTarget;
	this->m_fPreviousZoom  = this->m_fTargetZoom;

	this->m_ptTarget    = this->m_ptOriginalView;
	this->m_fTargetZoom = this->m_fOriginalZoom;

	//FPrint("ResetZoom() reverse - previous: (%04d,%04d) %f, target: (%04d,%04d) %f\n",
	//	this->m_ptPreviousView.x, this->m_ptPreviousView.y, this->m_fPreviousZoom,
	//	this->m_ptTarget.x, this->m_ptTarget.y, this->m_fTargetZoom
	//);

	CBaldurChitin *const pChitin = *p_g_pBaldurChitin;
	CInfGame *const pGame = pChitin->m_pObjectGame;
	CInfinity *const pInfinity = &pGame->m_gameAreas[pGame->m_visibleArea]->m_cInfinity;

	const long long nCurrentTime = getTime();

	if (!this->m_bAutoZooming)
	{
		this->m_bAutoZooming = true;

		// Patch: Scroll via exact coordinates
		// |
		// | this->m_nZoomCurStep = 0;
		// |
		ExInfinityData *const exInfinityData = &exInfinityDataMap[pInfinity];
		exInfinityData->nAutoZoomTimeRemaining = AUTO_ZOOM_TARGET_TIME;
		exInfinityData->nLastAutoZoomTime = nCurrentTime;

		if (pGame->m_options.m_bAreaMapZoom == 0)
		{
			// Patch: Scroll via exact coordinates
			// |
			// | this->m_nZoomCurStep = 10;
			// |
			ExInfinityData *const exInfinityData = &exInfinityDataMap[pInfinity];
			// |
			exInfinityData->nAutoZoomTimeRemaining = 0;
		}
	}
	else
	{
		// Patch: Scroll via exact coordinates
		// |
		// | this->m_nZoomCurStep = 10 - this->m_nZoomCurStep;
		// |
		ExInfinityData *const exInfinityData = &exInfinityDataMap[pInfinity];
		// |
		exInfinityData->nAutoZoomTimeRemaining = AUTO_ZOOM_TARGET_TIME - exInfinityData->nAutoZoomTimeRemaining;
		exInfinityData->nLastAutoZoomTime = nCurrentTime;
	}
}

void CScreenWorld::Override_StartScroll(CPoint dest, short speed)
{
	CBaldurChitin *const pChitin = *p_g_pBaldurChitin;
	CInfGame *const pGame = pChitin->m_pObjectGame;
	CInfinity *const pInfinity = &pGame->m_gameAreas[pGame->m_visibleArea]->m_cInfinity;

	if (speed < 0)
	{
		// Patch: Scale exponential scrolling speed to make it approximate vanilla timings (which is based around 30fps)
		// |
		ExInfinityData& exInfinityData = exInfinityDataMap[pInfinity];
		// |
		const int nExactDestX = dest.x * 10000;
		const int nExactDestY = dest.y * 10000;
		// |
		const int nExactDistanceX = std::abs(nExactDestX - pInfinity->m_ptCurrentPosExact.x);
		const int nExactDistanceY = std::abs(nExactDestY - pInfinity->m_ptCurrentPosExact.y);
		// |
		const int nNormalTimeX = expScrollNumSteps(pInfinity->m_ptCurrentPosExact.x, nExactDestX, EXP_SCROLL_MIN_STEP, EXP_SCROLL_THRESHOLD, -speed).nStepCount * 1000000 / 30;
		const int nNormalTimeY = expScrollNumSteps(pInfinity->m_ptCurrentPosExact.y, nExactDestY, EXP_SCROLL_MIN_STEP, EXP_SCROLL_THRESHOLD, -speed).nStepCount * 1000000 / 30;
		// |
		nRemainingScrollTime = (std::max)(nNormalTimeX, nNormalTimeY);
		speed = -1;
	}
	else if (speed > 0)
	{
		speed = static_cast<short>(speed * *CChitin::p_TIMER_UPDATES_PER_SECOND / 24);
	}

	pInfinity->SetScrollDest(&dest);
	pInfinity->m_autoScrollSpeed = speed;
}

void CScreenWorld::Override_ZoomToMap(bool bOverwriteOriginal)
{
	CBaldurChitin *const pChitin = *p_g_pBaldurChitin;
	CInfGame *const pGame = pChitin->m_pObjectGame;
	CInfinity *const pInfinity = &pGame->m_gameAreas[pGame->m_visibleArea]->m_cInfinity;

	const long long nCurrentTime = getTime();

	if (!this->m_bAutoZooming)
	{
		CRect *const pViewPort = &pInfinity->rViewPort;

		lua_State *const L = *p_g_lua;
		lua_getglobal(L, "Infinity_GetArea");
		lua_pushstring(L, "AREA_MAP_BACKGROUND");
		lua_callk(L, 1, 4, 0, nullptr);
		const lua_Integer nAreaMapBackgroundHeight = lua_tointeger(L, -1);
		lua_settop(L, -5);

		const int nViewPortWidth = pViewPort->right - pViewPort->left;
		const int nViewPortHeight = pViewPort->bottom - pViewPort->top;

		const float fViewPortWidthPercentOfArea = static_cast<short>(pInfinity->nAreaX) / static_cast<float>(nViewPortWidth);
		const float fViewPortHeightPercentOfArea = static_cast<short>(pInfinity->nAreaY) / (nViewPortHeight - nAreaMapBackgroundHeight * pInfinity->m_fZoom);

		const float fViewPortPercentOfArea = (std::max)(fViewPortWidthPercentOfArea, fViewPortHeightPercentOfArea);

		// Vanilla Bugfix: Improve auto zoom criteria so multiple auto zooms aren't initiated in succession
		// |
		// | if (fViewPortPercentOfArea > 0.999f && fViewPortPercentOfArea < 1.001f)
		// | {
		// |	return;
		// | }
		// |
		const CPoint ptPreviousView {
			pInfinity->nNewX + nViewPortWidth / 2,
			pInfinity->nNewY + nViewPortHeight / 2
		};

		const float fPreviousZoom = pInfinity->m_fZoom;

		const CPoint ptTarget {
			static_cast<short>(pInfinity->nAreaX) / 2,
			static_cast<short>(pInfinity->nAreaY) / 2 - static_cast<int>(nAreaMapBackgroundHeight * 0.5f * fViewPortPercentOfArea * pInfinity->m_fZoom)
		};

		const float fTargetZoom = fViewPortPercentOfArea * pInfinity->m_fZoom;
		// |
		if (ptPreviousView.x == ptTarget.x && ptPreviousView.y == ptTarget.y && std::abs(fPreviousZoom - fTargetZoom) < 0.01f)
		{
			return;
		}

		this->m_ptPreviousView    = ptPreviousView;
		this->m_rPreviousViewPort = *pViewPort;
		this->m_fPreviousZoom     = fPreviousZoom;

		this->m_ptTarget    = ptTarget;
		this->m_fTargetZoom = fTargetZoom;

		//FPrint("ZoomToMap() initial - previous: (%04d,%04d) %f, target: (%04d,%04d) %f\n",
		//	this->m_ptPreviousView.x, this->m_ptPreviousView.y, this->m_fPreviousZoom,
		//	this->m_ptTarget.x, this->m_ptTarget.y, this->m_fTargetZoom
		//);

		if (bOverwriteOriginal)
		{
			this->m_ptOriginalView    = ptPreviousView;
			this->m_rOriginalViewPort = *pViewPort;
			this->m_fOriginalZoom     = this->m_fPreviousZoom;
		}

		// Patch: Scroll via exact coordinates
		// |
		// | this->m_nZoomCurStep = 0;
		// |
		this->m_bAutoZooming = true;
		// |
		ExInfinityData *const exInfinityData = &exInfinityDataMap[pInfinity];
		// |
		exInfinityData->nAutoZoomTimeRemaining = AUTO_ZOOM_TARGET_TIME;
		exInfinityData->nLastAutoZoomTime = nCurrentTime;

		if (pGame->m_options.m_bAreaMapZoom == 0)
		{
			// Patch: Scroll via exact coordinates
			// |
			// | this->m_nZoomCurStep = 10;
			// |
			exInfinityData->nAutoZoomTimeRemaining = 0;
		}
	}
	else
	{
		// Vanilla Bugfix: Properly reverse
		// |
		// | this->m_ptPreviousView = this->m_ptTarget;
		// | this->m_fPreviousZoom  = this->m_fTargetZoom;
		// |
		// | this->m_ptTarget    = this->m_ptOriginalView;
		// | this->m_fTargetZoom = this->m_fOriginalZoom;
		// |
		const CPoint previousViewTemp = this->m_ptPreviousView;
		const float fPreviousZoomTemp = this->m_fPreviousZoom;
		// |
		this->m_ptPreviousView = this->m_ptTarget;
		this->m_fPreviousZoom  = this->m_fTargetZoom;
		// |
		this->m_ptTarget = previousViewTemp;
		this->m_fTargetZoom = fPreviousZoomTemp;

		//FPrint("ZoomToMap() reverse - previous: (%04d,%04d) %f, target: (%04d,%04d) %f\n",
		//	this->m_ptPreviousView.x, this->m_ptPreviousView.y, this->m_fPreviousZoom,
		//	this->m_ptTarget.x, this->m_ptTarget.y, this->m_fTargetZoom
		//);

		// Patch: Scroll via exact coordinates
		// |
		// | this->m_nZoomCurStep = 10 - this->m_nZoomCurStep;
		// |
		ExInfinityData *const exInfinityData = &exInfinityDataMap[pInfinity];
		// |
		exInfinityData->nAutoZoomTimeRemaining = AUTO_ZOOM_TARGET_TIME - exInfinityData->nAutoZoomTimeRemaining;
		exInfinityData->nLastAutoZoomTime = nCurrentTime;
	}
}

////////////////////
// Initialization //
////////////////////

void initUncapFPS()
{
	const long long initTime = getInitTime();
	nLastSyncUpdateTime = initTime;
	nLastScrollTime = initTime;
}
