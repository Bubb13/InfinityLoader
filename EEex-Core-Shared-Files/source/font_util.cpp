
#include "Baldur_generated.h"
#include "EEex.h"

//-----------------------------//
//          Functions          //
//-----------------------------//

///////////
// Ortho //
///////////

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

///////////
// Reimp //
///////////

int fontWrap(
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

	p_DrawTransformToScreen(r, r);
	p_DrawTransformToScreen(rClip, rClip);

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

	int nFinalPoint = static_cast<int>(p_DrawTransformToScreenH(static_cast<float>(*pointSize)));

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

/////////////////////
// Debug Overrides //
/////////////////////

int __cdecl EEex::Override_wordwrap(
	letter_t* letters,
	int maxletters,
	int* numletters,
	char* text,
	int width,
	font_t* font,
	int pointSize,
	int pointIndex,
	int maxLines,
	int* lastLineHeight,
	adjustmentData_t* adjustData,
	int indent)
{
	bool bIsCommand;
	glyphmap_t* pGlyphMap;
	int nUTF8Char;
	int nGlyphIndex;
	int nKernAdvance1;
	int nLetterWidth1;
	int nKernAdvance2;
	int nLetterWidth2;
	int nPointLineHeight1;
	int nLineHeight1;
	int whatever9;
	int whatever10;
	int nPointLineHeight2;
	int nLineHeight2;
	int whatever16;
	int temp;
	letter_t* pNextLetter2;
	int nLetterIndex;
	uint uVar1;
	int nNumLines1;
	letter_t* pLineAggregateInfo;
	letter_t* pLastSpaceLetter1;
	float nLeftSideBearing;
	double dVar2;
	int nCommandLength;
	int nCommandCounter;
	char* pCurTextChar1;
	letter_t* pNextLetter;
	int nNumLetters;
	letter_t* pLastSpaceLetter2;
	int nNumLines2;
	int whatever13;
	int nLastLineWidth3;
	int nLastLineWidth2;
	int nLastLineWidth4;
	int nLastLineWidth1;
	bool bCommandConsumed;
	letter_t* pCurLetter;
	char* pCurTextChar2;
	line_metric* pNewLineMetrics;

	pCurTextChar1 = text;
	adjustData->maxAscent = 0;
	pLineAggregateInfo = (letter_t*)0x0;
	adjustData->maxDescent = 0;
	pLastSpaceLetter1 = (letter_t*)0x0;
	nCommandCounter = 0;
	nCommandLength = 0;
	bCommandConsumed = false;

	if (reinterpret_cast<uintptr_t>(font) == 0xcdcdcdcd)
	{
		p_SDL_Log("Uninitialized font!");
	}

	pGlyphMap = p_fontGetGlyphMap(font, pointSize);
	nNumLines1 = 0;
	nNumLines2 = 0;
	letters->gi = -2;
	letters->w = 0;
	letters->T = (char*)0x0;
	*lastLineHeight = 0;
	nNumLetters = 1;

	if (maxletters < 2)
	{
		*numletters = 1;
		return 0;
	}

	pNextLetter = letters + 1;

	do
	{
		pCurTextChar2 = pCurTextChar1;

		/* Also advances input pointer to next char */
		nUTF8Char = p_DecodeUTF8Char(&pCurTextChar1);

		if (pLineAggregateInfo == (letter_t*)0x0)
		{
			if ((maxLines != 0) && (nNumLines1 == maxLines))
			{
				*numletters = nNumLetters;
				return nNumLines1;
			}

			nNumLetters = nNumLetters + 1;
			nNumLines1 = nNumLines1 + 1;
			pNextLetter->gi = -1;
			pNextLetter->w = 0;
			pNextLetter->T = (char*)0x0;
			pLineAggregateInfo = pNextLetter;
			pNextLetter = pNextLetter + 1;
			nNumLines2 = nNumLines1;
		}

		if (nUTF8Char == 0)
		{
			break;
		}

		if (nUTF8Char == 10)
		{
			/* Line Feed */
			nLastLineWidth1 = pLineAggregateInfo->w;

			if (pLineAggregateInfo->w < letters->w)
			{
				nLastLineWidth1 = letters->w;
			}

			letters->w = nLastLineWidth1;
			pLineAggregateInfo = (letter_t*)0x0;
		}
		else
		{
			/* Space */

			if (nUTF8Char == 0x20)
			{
				pLastSpaceLetter1 = pNextLetter;
			}

			pLastSpaceLetter2 = pLastSpaceLetter1;
			nGlyphIndex = p_fontGetGlyphIndex(font, nUTF8Char);

			if (-1 < nGlyphIndex)
			{
				if (pGlyphMap[nGlyphIndex].glyphIndex == -1)
				{
					p_fontAddTempGlyph(font, nUTF8Char, pointSize, pGlyphMap);
				}

				pCurLetter = pNextLetter;
				nNumLetters = nNumLetters + 1;
				pNextLetter2 = pNextLetter + 1;
				pNextLetter->gi = nGlyphIndex;
				pNextLetter->T = pCurTextChar2;
				pNextLetter->w = pLineAggregateInfo->w;
				pNextLetter = pNextLetter2;

				if (nUTF8Char == 0x5e)
				{
					/* '^' */
					bIsCommand = p_fontIsCommandLetter(*pCurTextChar1);
					nNumLines1 = nNumLines2;
					pLastSpaceLetter1 = pLastSpaceLetter2;

					if (bIsCommand)
					{
						nCommandCounter = 1;
						nCommandLength = 1;
					}
					else
					{
						if ((*pCurTextChar1 != '0') || (pCurTextChar1[1] != 'x'))
						{
							goto PROCESS_NON_COMMAND_LETTER;
						}

						nCommandCounter = 10;
						nCommandLength = 10;
					}
				}
				else
				{

				PROCESS_NON_COMMAND_LETTER:

					if (nCommandCounter == 0)
					{
						nLetterIndex = static_cast<int>((reinterpret_cast<intptr_t>(pCurLetter) - reinterpret_cast<intptr_t>(pLineAggregateInfo)) >> 4);

						if (bCommandConsumed)
						{
							if ((nLetterIndex != nCommandLength + 1) && (pCurLetter[-(nCommandLength + 2)].gi != -1))
							{
								nKernAdvance1 =
									p_fontGetKernAdvance(font, pGlyphMap[pCurLetter[-(nCommandLength + 2)].gi].glyphIndex,
										pGlyphMap[nGlyphIndex].glyphIndex);

								nLetterWidth1 =
									static_cast<int>(pGlyphMap[nGlyphIndex].leftSideBearing +
										((float)nKernAdvance1 * font->newLineMetrics[pointSize].scale));

								pLineAggregateInfo->w = pLineAggregateInfo->w + nLetterWidth1;
							}

							bCommandConsumed = false;
						}
						else if (nLetterIndex == 1)
						{
							nLeftSideBearing = pGlyphMap[nGlyphIndex].leftSideBearing;

							if (nLeftSideBearing <= 0.0)
							{
								nLeftSideBearing = 0.0;
							}

							pLineAggregateInfo->w = (int)nLeftSideBearing;

							if (pGlyphMap[nGlyphIndex].xOffset < 0)
							{
								pLineAggregateInfo->w = (int)nLeftSideBearing - pGlyphMap[nGlyphIndex].xOffset;
							}
						}
						else
						{
							nKernAdvance2 = p_fontGetKernAdvance(font, pGlyphMap[pCurLetter[-1].gi].glyphIndex, pGlyphMap[nGlyphIndex].glyphIndex);

							nLetterWidth2 =
								static_cast<int>(pGlyphMap[nGlyphIndex].leftSideBearing +
									((float)nKernAdvance2 * font->newLineMetrics[pointSize].scale));

							pLineAggregateInfo->w = pLineAggregateInfo->w + nLetterWidth2;
						}

						pCurLetter->w = pLineAggregateInfo->w;
						pLineAggregateInfo->w = pLineAggregateInfo->w + pGlyphMap[nGlyphIndex].advanceWidth;
						pNewLineMetrics = font->newLineMetrics;
						dVar2 = ceil((double)((pNewLineMetrics[pointSize].ascent - pNewLineMetrics[pointSize].descent) +
							pNewLineMetrics[pointSize].line_spacing));

						nPointLineHeight1 = static_cast<int>(dVar2);
						nLineHeight1 = nPointLineHeight1 + (uint)pGlyphMap[nGlyphIndex].packedRect.h + pGlyphMap[nGlyphIndex].yOffset;

						if (*lastLineHeight < nLineHeight1)
						{
							*lastLineHeight = nLineHeight1;
						}

						uVar1 = pGlyphMap[nGlyphIndex].yOffset >> 0x1f;
						whatever9 = (pGlyphMap[nGlyphIndex].yOffset ^ uVar1) - uVar1;

						if ((adjustData->maxAscent < whatever9) && (nNumLines2 < 2))
						{
							adjustData->maxAscent = whatever9;
						}

						whatever10 = -(pGlyphMap[nGlyphIndex].packedRect.h + pGlyphMap[nGlyphIndex].yOffset);

						if (whatever10 < adjustData->maxDescent)
						{
							adjustData->maxDescent = whatever10;
						}

						nNumLines1 = nNumLines2;
						pLastSpaceLetter1 = pLastSpaceLetter2;

						if ((width < pLineAggregateInfo->w) || (((indent != 0 && (1 < nNumLines2)) && (width + -0x3c < pLineAggregateInfo->w))))
						{
							/* Wrap */

							if ((pLastSpaceLetter2 == (letter_t*)0x0) || (pLastSpaceLetter2->gi == -1))
							{
								if (0x2000 < nUTF8Char)
								{
									*lastLineHeight = 0;
									adjustData->maxDescent = 0;
									nLastLineWidth2 = pCurLetter->w;
									pLineAggregateInfo->w = nLastLineWidth2;

									if ((maxLines != 0) && (maxLines == nNumLines2))
									{
										break;
									}

									if (nLastLineWidth2 < letters->w)
									{
										nLastLineWidth2 = letters->w;
									}

									nNumLetters = nNumLetters + 1;
									letters->w = nLastLineWidth2;
									nNumLines1 = nNumLines2 + 1;
									pNextLetter->gi = pCurLetter->gi;
									pNextLetter->w = 0;
									pNextLetter->T = pCurLetter->T;
									pCurLetter->gi = -1;
									pCurLetter->w = pGlyphMap[nGlyphIndex].advanceWidth;
									pCurLetter->T = (char*)0x0;
									pLineAggregateInfo = pCurLetter;
									pNextLetter = pNextLetter + 1;
									nNumLines2 = nNumLines1;
								}
							}
							else
							{
								pLineAggregateInfo->w = pLastSpaceLetter2->w;

								if ((maxLines != 0) && (maxLines == nNumLines2))
								{
									break;
								}

								*lastLineHeight = 0;
								adjustData->maxDescent = 0;
								nLastLineWidth3 = pLineAggregateInfo->w;

								if (pLineAggregateInfo->w < letters->w)
								{
									nLastLineWidth3 = letters->w;
								}

								nNumLines2 = nNumLines2 + 1;
								letters->w = nLastLineWidth3;
								pLastSpaceLetter2->gi = -1;
								pLastSpaceLetter2->w = 0;
								pLastSpaceLetter2->T = (char*)0x0;
								nNumLines1 = nNumLines2;
								pLineAggregateInfo = pLastSpaceLetter2;

								if (pLastSpaceLetter2 < pCurLetter)
								{
									whatever13 = pLastSpaceLetter2[1].w;
									nLeftSideBearing = pGlyphMap[nGlyphIndex].leftSideBearing;

									while (pLastSpaceLetter1 = pLastSpaceLetter1 + 1, pLastSpaceLetter1 <= pCurLetter)
									{
										pLastSpaceLetter1->w = (int)((float)pLastSpaceLetter1->w - ((float)whatever13 - nLeftSideBearing));
									}

									pLastSpaceLetter2->w = pCurLetter->w + pGlyphMap[nGlyphIndex].advanceWidth;
									pNewLineMetrics = font->newLineMetrics;
									dVar2 = ceil((double)((pNewLineMetrics[pointSize].ascent - pNewLineMetrics[pointSize].descent) +
										pNewLineMetrics[pointSize].line_spacing));

									nPointLineHeight2 = static_cast<int>(dVar2);
									nLineHeight2 = nPointLineHeight2 + (uint)pGlyphMap[nGlyphIndex].packedRect.h + pGlyphMap[nGlyphIndex].yOffset;

									if (*lastLineHeight < nLineHeight2)
									{
										*lastLineHeight = nLineHeight2;
									}

									uVar1 = pGlyphMap[nGlyphIndex].yOffset >> 0x1f;
									whatever16 = (pGlyphMap[nGlyphIndex].yOffset ^ uVar1) - uVar1;

									if ((adjustData->maxAscent < whatever16) && (nNumLines2 < 2))
									{
										adjustData->maxAscent = whatever16;
									}

									temp = -(pGlyphMap[nGlyphIndex].packedRect.h + pGlyphMap[nGlyphIndex].yOffset);
									nNumLines1 = nNumLines2;
									pLastSpaceLetter1 = pLastSpaceLetter2;

									if (temp < adjustData->maxDescent)
									{
										adjustData->maxDescent = temp;
									}
								}
							}
						}
					}
					else
					{
						nCommandCounter = nCommandCounter + -1;
						nNumLines1 = nNumLines2;
						pLastSpaceLetter1 = pLastSpaceLetter2;

						if (nCommandCounter == 0)
						{
							bCommandConsumed = true;
						}
					}
				}
			}
		}
	}
	while (nNumLetters < maxletters);

	if (pLineAggregateInfo != (letter_t*)0x0)
	{
		nLastLineWidth4 = pLineAggregateInfo->w;

		if (pLineAggregateInfo->w < letters->w)
		{
			nLastLineWidth4 = letters->w;
		}

		letters->w = nLastLineWidth4;
		*numletters = nNumLetters;
		return nNumLines2;
	}

	*numletters = nNumLetters;
	return nNumLines2;
}

int __cdecl EEex::Override_fontGetGlyphIndex(font_t* font, int glyph)
{
	int iVar1;
	uint nBucketIndex;
	glyphHashEntry_t *pGlyphHashEntry;

	if (0x7fec < (font->glyphHashTable).numElements)
	{
		p_SDL_Log("Font: ERROR: number of glyphs has exceeded hash table size!");
		iVar1 = p_stbtt_FindGlyphIndex(&font->fontInfo,glyph);
		return iVar1;
	}

	nBucketIndex = (uint)glyph % 0x7fed;
	pGlyphHashEntry = (font->glyphHashTable).table + nBucketIndex;
	iVar1 = (font->glyphHashTable).table[nBucketIndex].key;

	while (iVar1 != glyph)
	{
		if (pGlyphHashEntry->key == -1)
		{
			goto LAB_007af761;
		}

		nBucketIndex = (int)(nBucketIndex + 1) % 0x7fed;
		pGlyphHashEntry = (font->glyphHashTable).table + nBucketIndex;
		iVar1 = (font->glyphHashTable).table[nBucketIndex].key;
	}

	if (pGlyphHashEntry->key == -1)
	{
LAB_007af761:
		pGlyphHashEntry->key = glyph;
		iVar1 = p_stbtt_FindGlyphIndex(&font->fontInfo,glyph);
		pGlyphHashEntry->glyphIndex = iVar1;
		(font->glyphHashTable).numElements = (font->glyphHashTable).numElements + 1;
	}

	return pGlyphHashEntry->glyphIndex;
}
