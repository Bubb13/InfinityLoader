
#pragma once

#include "Baldur-v2.6.6.0_generated.h"

//-----------------------------//
//          Functions          //
//-----------------------------//

int fontWrapOrtho(
	char* text,
	SDL_Rect* r,
	SDL_Rect* rClip,
	int* horizontalAlignment,
	int* verticalAlignment,
	font_t* font,
	int* pointSize,
	letter_t* letters,
	int* nlines,
	int* nletters,
	int* pointIndex,
	bool* scale,
	adjustmentData_t* adjustData,
	int indent,
	bool bUseFontSizeFloor
);

int fontDrawOrtho(
	char* text,
	SDL_Rect* r,
	SDL_Rect* rClip,
	int horizontalAlignment,
	int verticalAlignment,
	font_t* font,
	int cursorPosition,
	int cursor,
	int selectionStart,
	int selectionEnd,
	bool shadow,
	int pointSize,
	bool backgroundRect,
	int indent,
	bool bUseOffsets,
	float fOffsetX,
	float fOffsetY,
	bool bUseFontSizeFloor
);

int renderTextWrapOrtho(
	CVidFont* pThis,
	char* text,
	int x,
	int y,
	int w,
	int h,
	CRect* rClip,
	int halign,
	int valign,
	bool shadow,
	bool backgroundRect
);
