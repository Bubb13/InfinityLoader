
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
	bool bUseFontSizeFloor)
{
	const int maxLines = (*verticalAlignment >> 16) & 0xFFF;
	*verticalAlignment &= 0xFFFF;

	if (r->h == 0xFFFFFF)
	{
		*verticalAlignment = 0;
	}

	int nAlignAdjX = 0;

	if ((*horizontalAlignment & 4) != 0) {
		nAlignAdjX = rClip->w - rClip->x;
	}

	if ((*horizontalAlignment & 8) != 0) {
		nAlignAdjX = r->w;
	}

	int nAlignAdjY = 0;

	if ((*verticalAlignment & 4) != 0) {
		nAlignAdjY = rClip->h - rClip->y;
	}

	if ((*verticalAlignment & 8) != 0) {
		nAlignAdjY = r->h;
	}

	*horizontalAlignment = *horizontalAlignment & 0xFFFFFFF3;
	*verticalAlignment = *verticalAlignment & 0xFFFFFFF3;

	int nFinalPoint = *pointSize;

	if (bUseFontSizeFloor)
	{
		nFinalPoint = (std::max)(10, nFinalPoint);
	}

	nFinalPoint = (std::min)(nFinalPoint, 79);
	nFinalPoint = static_cast<int>(floor(nFinalPoint));

	line_metric *const pNewLineMetrics = font->newLineMetrics;
	int lastLineHeight;

	for (; nFinalPoint > 1 && (nAlignAdjX != 0 || nAlignAdjY != 0); --nFinalPoint)
	{
		line_metric *const pNewLineMetric = &pNewLineMetrics[nFinalPoint];
		const float fLineHeight = pNewLineMetric->ascent - pNewLineMetric->descent + pNewLineMetric->line_spacing - 0.001f;

		if (nAlignAdjY < 1 || fLineHeight <= nAlignAdjY)
		{
			*nlines = p_wordwrap(letters, 0x40000, nletters, text, r->w, font, nFinalPoint, *pointIndex, maxLines, &lastLineHeight, adjustData, indent);

			if
			(
				(nAlignAdjY < 1 || *nlines * fLineHeight <= nAlignAdjY)
				&&
				(nAlignAdjX < 1 || letters->w <= nAlignAdjX)
			)
			{
				break;
			}
		}
	}

	if (*nletters == 0)
	{
		*nlines = p_wordwrap(letters, 0x40000, nletters, text, r->w, font, nFinalPoint, *pointIndex, maxLines, &lastLineHeight, adjustData, indent);
	}

	*pointSize = nFinalPoint;

	line_metric *const pNewLineMetric = &pNewLineMetrics[nFinalPoint];
	const int nLineHeight = static_cast<int>(ceil(pNewLineMetric->ascent - pNewLineMetric->descent + pNewLineMetric->line_spacing));
	return nLineHeight * *nlines;
}

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
	bool bUseFontSizeFloor)
{
	SDL_Rect rClipCopy { rClip->x, rClip->y, rClip->w, rClip->h };
	int nHorizontalAlignment = horizontalAlignment;
	int nPointSize           = pointSize;
	int nLines;
	int nLetters             = 0;
	int nPointIndex          = 0; // Unused
	bool bScale;                  // Unused

	// Patch
	// |
	// | float fScreenY = p_DrawTransformToScreenH(static_cast<float>(r->y)); // Important: Must be before fontWrap()
	// |
	const int nScreenY = r->y; // Important: Must be before fontWrap()

	adjustmentData_t adjustData;

	const int nHeightAfterWrap = fontWrapOrtho(
		text,
		r,                     // [In/Out] [!] Sets through passed-in pointer
		&rClipCopy,            // [In/Out]
		&nHorizontalAlignment, // [In/Out]
		&verticalAlignment,    // [In/Out] [!] Sets through passed-in pointer
		font,
		&nPointSize,           // [In/Out] Sets through passed-in pointer
		p_g_letters->data,
		&nLines,               // [Out]
		&nLetters,             // [Out]
		&nPointIndex,          // [In/Read-but-unused]
		&bScale,               // [Unused]
		&adjustData,           // [Out]
		indent,
		bUseFontSizeFloor
	);

	if (nLines == 0)
	{
		return 0;
	}

	int nAlignOffsetY = nLines; // Nonsense?

	if (verticalAlignment == 0)
	{
		nAlignOffsetY = static_cast<int>(ceil(static_cast<double>(font->newLineMetrics[nPointSize].line_spacing)));
	}
	else if (verticalAlignment == 1)
	{
		nAlignOffsetY = r->h - nHeightAfterWrap;
	}
	else if (verticalAlignment == 2)
	{
		line_metric *const pLineMetric = &font->newLineMetrics[nPointSize];

		const int dVar8 = static_cast<int>(ceil(static_cast<double>(pLineMetric->ascent - pLineMetric->descent + pLineMetric->line_spacing)));
		const int dVar9 = static_cast<int>(ceil(static_cast<double>(pLineMetric->ascent)));

		nAlignOffsetY = ((dVar8 + r->h - adjustData.maxAscent - nHeightAfterWrap) >> 1) - dVar9 + adjustData.maxAscent;
	}

	p_DrawOrtho11Begin();

	if (backgroundRect)
	{
		const uint nSavedColor = p_DrawColor(0xFF000000);

		SDL_Rect rBounds;
		rBounds.x = r->x - 8 + (r->w / 2 - (*p_g_letters)[0].w / 2);
		rBounds.y = r->y - 8 + nAlignOffsetY;
		rBounds.w = (*p_g_letters)[0].w + 16;
		rBounds.h = nHeightAfterWrap + 16;

		p_uiDrawSlicedRect(1, &rBounds, 150, &rBounds);

		p_DrawColor(nSavedColor);
	}

	const float fEffectiveOffsetX = bUseOffsets ? fOffsetX                     : 0.0f;

	// Patch
	// |
	// | const float fEffectiveOffsetY = bUseOffsets ? fOffsetY + (fScreenY - (float)r->y) : 0.0f;
	// |
	const float fEffectiveOffsetY = bUseOffsets ? fOffsetY + (nScreenY - r->y) : 0.0f;

	if (shadow)
	{
		const uint nSavedColor = p_DrawColor(0xFF000000);
		p_DrawColor(nSavedColor & 0xff000000);

		p_drawLetters(
			r->x + 2,
			r->y + 2 + nAlignOffsetY,
			r->w,
			&rClipCopy,
			p_g_letters->data,
			nLetters,
			nHorizontalAlignment,
			font,
			nPointSize,
			cursorPosition,
			cursor,
			selectionStart,
			selectionEnd,
			nLines,
			false,
			indent,
			fEffectiveOffsetX,
			fEffectiveOffsetY
		);

		p_drawLetters(
			r->x + 1,
			r->y + 1 + nAlignOffsetY,
			r->w,
			&rClipCopy,
			p_g_letters->data,
			nLetters,
			nHorizontalAlignment,
			font,
			nPointSize,
			cursorPosition,
			cursor,
			selectionStart,
			selectionEnd,
			nLines,
			false,
			indent,
			fEffectiveOffsetX,
			fEffectiveOffsetY
		);

		p_DrawColor(nSavedColor);
	}

	p_drawLetters(
		r->x,
		r->y + nAlignOffsetY,
		r->w,
		&rClipCopy,
		p_g_letters->data,
		nLetters,
		nHorizontalAlignment,
		font,
		nPointSize,
		cursorPosition,
		cursor,
		selectionStart,
		selectionEnd,
		nLines,
		true,
		indent,
		fEffectiveOffsetX,
		fEffectiveOffsetY
	);

	p_DrawOrtho11End();

	// Patch
	// |
	// | return static_cast<int>(p_DrawTransformFromScreenH(static_cast<float>(nHeightAfterWrap + nAlignOffsetY)));
	// |
	return nHeightAfterWrap + nAlignOffsetY;
}

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
	bool backgroundRect)
{
	p_DrawEnable(DrawFeature::DRAW_BLEND);
	p_DrawBlendFunc(DrawBlend::DRAW_ONE, DrawBlend::DRAW_ONE_MINUS_SRC_ALPHA);

	const uint nSavedColor = p_applycolor(pThis->foreground, pThis->tintcolor);

	SDL_Rect r;
	r.x = x;
	r.y = y;
	r.w = w;
	r.h = h;

	SDL_Rect rClipSDL;
	rClipSDL.x = rClip->left;
	rClipSDL.y = rClip->top;
	rClipSDL.w = rClip->right - rClipSDL.x;
	rClipSDL.h = rClip->bottom - rClipSDL.y;

	font_t *const pFont = reinterpret_cast<font_t*>(pThis->pRes->GetFont());

	const int nDrawnHeight = fontDrawOrtho(
		text,
		&r,
		&rClipSDL,
		halign | 8,
		valign | 8,
		pFont,
		-1,
		0,
		-1,
		-1,
		shadow,
		(pThis->zoom * pThis->pointSize) / 100,
		backgroundRect,
		0,
		false,
		0.0,
		0.0,
		false
	);

	p_DrawColor(nSavedColor);

	return nDrawnHeight;
}
