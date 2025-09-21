
#pragma once

#include "Baldur-v2.6.6.0_generated.h"

void cursorToInternalResolutionCoordinate(int cursorX, int cursorY, CPoint* pPointOut);
void cursorToWorldCoordinateSpace(CInfinity* pInfinity, int cursorX, int cursorY, CPoint* pPointOut);
void cursorToExactWorldCoordinateSpace(CInfinity* pInfinity, int cursorX, int cursorY, CPoint* pPointOut);
void cursorToWorldCoordinate(CInfinity* pInfinity, int cursorX, int cursorY, CPoint* pPointOut);
void setViewPositionFromExact(CInfinity* pInfinity);
void setViewPositionToExact(CInfinity* pInfinity, int nExactDestX, int nExactDestY);
