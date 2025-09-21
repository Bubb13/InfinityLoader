
#include "Baldur-v2.6.6.0_generated.h"

// `pInfinity->rViewPortNotZoomed` is (0, 0, `CVidMode::SCREENWIDTH`, `CVidMode::SCREENHEIGHT`)
//     i.e. equal to the internal resolution of the game.
//
// `CInfinity::rViewPort` is `CInfinity::rViewPortNotZoomed` multiplied by `CInfinity::m_fZoom`
//     [0-1] = zoom in, [1-inf] zoom out; relative to the internal resolution of the game.
//
// `CInfinity::nNewX` and `CInfinity::nNewY` are in the non-zoomed internal resolution coordinate space.

void cursorToInternalResolutionCoordinate(int cursorX, int cursorY, CPoint* pPointOut)
{
	CVidMode *const pVidMode = (*p_g_pBaldurChitin)->cVideo.pCurrentMode;
	// Floats to prevent integer overflow when working in exact coords
	pPointOut->x = static_cast<int>(static_cast<float>(cursorX) / pVidMode->nWidth * *CVidMode::p_SCREENWIDTH);
	pPointOut->y = static_cast<int>(static_cast<float>(cursorY) / pVidMode->nHeight * *CVidMode::p_SCREENHEIGHT);
}

void cursorToWorldCoordinateSpace(CInfinity* pInfinity, int cursorX, int cursorY, CPoint* pPointOut)
{
	cursorToInternalResolutionCoordinate(cursorX, cursorY, pPointOut);
	pPointOut->x = static_cast<int>(pPointOut->x * pInfinity->m_fZoom);
	pPointOut->y = static_cast<int>(pPointOut->y * pInfinity->m_fZoom);
}

void cursorToExactWorldCoordinateSpace(CInfinity* pInfinity, int cursorX, int cursorY, CPoint* pPointOut)
{
	cursorToWorldCoordinateSpace(pInfinity, cursorX * 10000, cursorY * 10000, pPointOut);
}

void cursorToWorldCoordinate(CInfinity* pInfinity, int cursorX, int cursorY, CPoint* pPointOut)
{
	cursorToWorldCoordinateSpace(pInfinity, cursorX, cursorY, pPointOut);
	pPointOut->x += pInfinity->nNewX;
	pPointOut->y += pInfinity->nNewY;
}

void setViewPositionFromExact(CInfinity* pInfinity)
{
	const int nDestX = pInfinity->m_ptCurrentPosExact.x / 10000;
	const int nDestY = pInfinity->m_ptCurrentPosExact.y / 10000;

	int nFitX = nDestX;
	int nFitY = nDestY;
	pInfinity->FitViewPosition(&nFitX, &nFitY, &pInfinity->rViewPort);

	if (nFitX != nDestX)
	{
		pInfinity->m_ptCurrentPosExact.x = nFitX * 10000;
	}

	if (nFitY != nDestY)
	{
		pInfinity->m_ptCurrentPosExact.y = nFitY * 10000;
	}

	pInfinity->nNewX = nFitX;
	pInfinity->nNewY = nFitY;
	pInfinity->m_updateListenPosition = 1;
}

void setViewPositionToExact(CInfinity* pInfinity, int nExactDestX, int nExactDestY)
{
	pInfinity->m_ptCurrentPosExact.x = nExactDestX;
	pInfinity->m_ptCurrentPosExact.y = nExactDestY;
	setViewPositionFromExact(pInfinity);
}
