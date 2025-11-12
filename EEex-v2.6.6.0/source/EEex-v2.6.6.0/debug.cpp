
#include "Baldur-v2.6.6.0_generated.h"

uint CGameArea::Override_GetTintColor(CPoint* cPoint, byte listType)
{
	if (listType == 2 || this->m_bmLum.pRes == nullptr) // Flying creature or no light map
	{
		return 0xFFFFFF;
	}

	const int nRenderCode = (this->m_cInfinity.m_areaType & 0x40) != 0 ? this->m_cInfinity.m_renderDayNightCode : 1;

	const int nXMod16 = cPoint->x % 16;
	const int nYMod12 = cPoint->y % 12;

	const int nXToNextLumCoord = 16 - nXMod16;
	const int nYToNextLumCoord = 12 - nYMod12;

	tagRGBQUAD rgbTL{};
	tagRGBQUAD rgbTR{};
	tagRGBQUAD rgbBL{};
	tagRGBQUAD rgbBR{};

	// These are uninitialized in the engine
	int nRgbTLRed   = 0x42;
	int nRgbTLGreen = 0x42;
	int nRgbTLBlue  = 0x42;

	int nRgbTRRed   = 0x42;
	int nRgbTRGreen = 0x42;
	int nRgbTRBlue  = 0x42;

	int nRgbBLRed   = 0x42;
	int nRgbBLGreen = 0x42;
	int nRgbBLBlue  = 0x42;

	int nRgbBRRed   = 0x42;
	int nRgbBRGreen = 0x42;
	int nRgbBRBlue  = 0x42;

	if ((nRenderCode & 1) != 0)
	{
		const int nLightMapX = cPoint->x / this->m_lightmapRatio.cx;
		const int nLightMapY = cPoint->y / this->m_lightmapRatio.cy;

		this->m_bmLum.GetPixelColor(&rgbTL, nLightMapX, nLightMapY);

		if (this->m_bmLum.GetPixelColor(&rgbTR, nLightMapX + 1, nLightMapY) == 0)
		{
			rgbTR = rgbTL;
		}

		if (this->m_bmLum.GetPixelColor(&rgbBL, nLightMapX, nLightMapY + 1) == 0)
		{
			rgbBL = rgbTL;
		}

		if (this->m_bmLum.GetPixelColor(&rgbBR, nLightMapX + 1, nLightMapY + 1) == 0)
		{
			rgbBR = rgbTL;
		}
	}

	if ((nRenderCode & 2) == 0 || this->m_pbmLumNight == nullptr)
	{
		nRgbTLRed   = rgbTL.rgbRed;
		nRgbTLGreen = rgbTL.rgbGreen;
		nRgbTLBlue  = rgbTL.rgbBlue;

		nRgbTRRed   = rgbTR.rgbRed;
		nRgbTRGreen = rgbTR.rgbGreen;
		nRgbTRBlue  = rgbTR.rgbBlue;

		nRgbBLRed   = rgbBL.rgbRed;
		nRgbBLGreen = rgbBL.rgbGreen;
		nRgbBLBlue  = rgbBL.rgbBlue;

		nRgbBRRed   = rgbBR.rgbRed;
		nRgbBRGreen = rgbBR.rgbGreen;
		nRgbBRBlue  = rgbBR.rgbBlue;
	}
	else // (nRenderCode & 2) != 0 && this->m_pbmLumNight != nullptr
	{
		// Night and has night light map

		const int xLum = cPoint->x / 16;
		const int yLum = cPoint->y / 12;

		tagRGBQUAD rgbNightTL;
		tagRGBQUAD rgbNightTR;
		tagRGBQUAD rgbNightBL;
		tagRGBQUAD rgbNightBR;

		this->m_pbmLumNight->GetPixelColor(&rgbNightTL, xLum, yLum);

		if (this->m_pbmLumNight->GetPixelColor(&rgbNightTR, xLum + 1, yLum) == 0)
		{
			rgbNightTR = rgbNightTL;
		}

		if (this->m_pbmLumNight->GetPixelColor(&rgbNightBL, xLum, yLum + 1) == 0)
		{
			rgbNightBL = rgbNightTL;
		}

		if (this->m_pbmLumNight->GetPixelColor(&rgbNightBR, xLum + 1, yLum + 1) == 0)
		{
			rgbNightBR = rgbNightTL;
		}

		const int nRgbNightTLRed   = rgbNightTL.rgbRed;
		const int nRgbNightTLGreen = rgbNightTL.rgbGreen;
		const int nRgbNightTLBlue  = rgbNightTL.rgbBlue;

		const int nRgbNightTRRed   = rgbNightTR.rgbRed;
		const int nRgbNightTRGreen = rgbNightTR.rgbGreen;
		const int nRgbNightTRBlue  = rgbNightTR.rgbBlue;

		const int nRgbNightBLRed   = rgbNightBL.rgbRed;
		const int nRgbNightBLGreen = rgbNightBL.rgbGreen;
		const int nRgbNightBLBlue  = rgbNightBL.rgbBlue;

		const int nRgbNightBRRed   = rgbNightBR.rgbRed;
		const int nRgbNightBRGreen = rgbNightBR.rgbGreen;
		const int nRgbNightBRBlue  = rgbNightBR.rgbBlue;

		if ((nRenderCode & 1) == 0)
		{
			// Not day
			const int nMixTopRed   = ((nRgbNightTLRed   * nXToNextLumCoord) + (nRgbNightTRRed   * nXMod16)) / 16;
			const int nMixTopGreen = ((nRgbNightTLGreen * nXToNextLumCoord) + (nRgbNightTRGreen * nXMod16)) / 16;
			const int nMixTopBlue  = ((nRgbNightTLBlue  * nXToNextLumCoord) + (nRgbNightTRBlue  * nXMod16)) / 16;

			const int nMixBottomRed   = ((nRgbNightBLRed   * nXToNextLumCoord) + (nRgbNightBRRed   * nXMod16)) / 16;
			const int nMixBottomGreen = ((nRgbNightBLGreen * nXToNextLumCoord) + (nRgbNightBRGreen * nXMod16)) / 16;
			const int nMixBottomBlue  = ((nRgbNightBLBlue  * nXToNextLumCoord) + (nRgbNightBRBlue  * nXMod16)) / 16;

			const int nMixRed   = ((nMixTopRed   * nYToNextLumCoord) + (nMixBottomRed   * nYMod12)) / 12;
			const int nMixGreen = ((nMixTopGreen * nYToNextLumCoord) + (nMixBottomGreen * nYMod12)) / 12;
			const int nMixBlue  = ((nMixTopBlue  * nYToNextLumCoord) + (nMixBottomBlue  * nYMod12)) / 12;

			return (nMixBlue & 0xFF) << 16 | (nMixGreen & 0xFF) << 8 | (nMixRed & 0xFF);
		}

		// Both day and night (nRenderCode == 3) - not used?
		const int nDayIntensity = this->m_cInfinity.m_dayLightIntensity;
		const int nNightIntensity = 255 - nDayIntensity;

		nRgbTLRed   = ((nRgbTLRed   * nDayIntensity) + (nRgbNightTLRed   * nNightIntensity)) / 256;
		nRgbTLGreen = ((nRgbTLGreen * nDayIntensity) + (nRgbNightTLGreen * nNightIntensity)) / 256;
		nRgbTLBlue  = ((nRgbTLBlue  * nDayIntensity) + (nRgbNightTLBlue  * nNightIntensity)) / 256;

		nRgbTRRed   = ((nRgbTRRed   * nDayIntensity) + (nRgbNightTRRed   * nNightIntensity)) / 256;
		nRgbTRGreen = ((nRgbTRGreen * nDayIntensity) + (nRgbNightTRGreen * nNightIntensity)) / 256;
		nRgbTRBlue  = ((nRgbTRBlue  * nDayIntensity) + (nRgbNightTRBlue  * nNightIntensity)) / 256;

		nRgbBLRed   = ((nRgbBLRed   * nDayIntensity) + (nRgbNightBLRed   * nNightIntensity)) / 256;
		nRgbBLGreen = ((nRgbBLGreen * nDayIntensity) + (nRgbNightBLGreen * nNightIntensity)) / 256;
		nRgbBLBlue  = ((nRgbBLBlue  * nDayIntensity) + (nRgbNightBLRed   * nNightIntensity)) / 256;

		nRgbBRRed   = ((nRgbBRRed   * nDayIntensity) + (nRgbNightBRRed   * nNightIntensity)) / 256;
		nRgbBRGreen = ((nRgbBRGreen * nDayIntensity) + (nRgbNightBRGreen * nNightIntensity)) / 256;
		nRgbBRBlue  = ((nRgbBRBlue  * nDayIntensity) + (nRgbNightBRBlue  * nNightIntensity)) / 256;
	}

	const int nMixTopRed   = ((nRgbTLRed   * nXToNextLumCoord) + (nRgbTRRed   * nXMod16)) / 16;
	const int nMixTopGreen = ((nRgbTLGreen * nXToNextLumCoord) + (nRgbTRGreen * nXMod16)) / 16;
	const int nMixTopBlue  = ((nRgbTLBlue  * nXToNextLumCoord) + (nRgbTRBlue  * nXMod16)) / 16;

	const int nMixBottomRed   = ((nRgbBLRed   * nXToNextLumCoord) + (nRgbBRRed   * nXMod16)) / 16;
	const int nMixBottomGreen = ((nRgbBLGreen * nXToNextLumCoord) + (nRgbBRGreen * nXMod16)) / 16;
	const int nMixBottomBlue  = ((nRgbBLBlue  * nXToNextLumCoord) + (nRgbBRBlue  * nXMod16)) / 16;

	const int nMixRed   = ((nMixTopRed   * nYToNextLumCoord) + (nMixBottomRed   * nYMod12)) / 12;
	const int nMixGreen = ((nMixTopGreen * nYToNextLumCoord) + (nMixBottomGreen * nYMod12)) / 12;
	const int nMixBlue  = ((nMixTopBlue  * nYToNextLumCoord) + (nMixBottomBlue  * nYMod12)) / 12;

	return (nMixBlue & 0xFF) << 16 | (nMixGreen & 0xFF) << 8 | (nMixRed & 0xFF);
}

void CVidPalette::Override_RealizeResource3d(uint* pDestPalette, uint dwFlags, CVIDIMG_PALETTEAFFECT* pAffectArgs, uint nTransVal)
{
	// pAffectArgs is CVidCell::mPaletteAffects

	CBaldurChitin *const pChitin = *p_g_pBaldurChitin;
	CVidMode *const pCurVidMode = pChitin->cVideo.pCurrentMode;
	const int nRedShift   = pCurVidMode->nRShift;
	const int nGreenShift = pCurVidMode->nGShift;
	const int nBlueShift  = pCurVidMode->nBShift;

	int nCurLightPeriod = 0;
	int nCurAddPeriod   = 0;

	this->SetAUCounter();

	/* --- TINT --- */

	CVIDPALETTE_COLOR tintColor;
	int nTintShiftBack  = 0;
	int nMaxTintValue   = 1;
	bool bHasTintEffect = this->GetTint(&tintColor, pAffectArgs, &nTintShiftBack, &nMaxTintValue, dwFlags);

	// ^ Example tint from AR0022.ARE:
	//
	//     tintColor.rgbRed   = 210;
	//     tintColor.rgbGreen = 138;
	//     tintColor.rgbBlue  = 24;
	//     nTintShiftBack     = 8;
	//     nMaxTintValue      = 255;

	if (pAffectArgs != nullptr)
	{
		uint *const pRangeTint = pAffectArgs->pRangeTints[0];

		if (pRangeTint != nullptr)
		{
			const uint nRangeTint = *pRangeTint;

			const int nTintRed   =  nRangeTint        & 0xFF;
			const int nTintGreen = (nRangeTint >> 8)  & 0xFF;
			const int nTintBlue  = (nRangeTint >> 16) & 0xFF;

			int nNewTintRed;
			int nNewTintGreen;
			int nNewTintBlue;

			const int nTintPeriod = pAffectArgs->aRangeTintPeriods[0];

			if (nTintPeriod == 1)
			{
				nNewTintRed   = nTintRed;
				nNewTintGreen = nTintGreen;
				nNewTintBlue  = nTintBlue;
			}
			else
			{
				int nCurTintPeriod = this->m_nAUCounter % (nTintPeriod * 2);

				if (nTintPeriod < nCurTintPeriod)
				{
					nCurTintPeriod = nTintPeriod * 2 - nCurTintPeriod;
				}

				nNewTintRed   = 255 - ((255 - nTintRed)   * nCurTintPeriod) / nTintPeriod;
				nNewTintGreen = 255 - ((255 - nTintGreen) * nCurTintPeriod) / nTintPeriod;
				nNewTintBlue  = 255 - ((255 - nTintBlue)  * nCurTintPeriod) / nTintPeriod;
			}

			tintColor.rgbRed   *= nNewTintRed;
			tintColor.rgbGreen *= nNewTintGreen;
			tintColor.rgbBlue  *= nNewTintBlue;

			nTintShiftBack += 8;
			nMaxTintValue  *= 255;
			bHasTintEffect  = true;
		}
	}

	/* --- ADD --- */

	CVIDPALETTE_COLOR addColor;
	int nAddShiftBack  = 0;
	bool bHasAddEffect = this->GetAdd(&addColor, pAffectArgs, &nAddShiftBack, dwFlags);

	if (pAffectArgs != nullptr)
	{
		uint *const pRangeAdd = pAffectArgs->pRangeAdds[0];

		if (pRangeAdd != nullptr)
		{
			const uint nRangeAdd = *pRangeAdd;

			const int nAddRed   =  nRangeAdd        & 0xFF;
			const int nAddGreen = (nRangeAdd >> 8)  & 0xFF;
			const int nAddBlue  = (nRangeAdd >> 16) & 0xFF;

			int nNewAddRed;
			int nNewAddGreen;
			int nNewAddBlue;

			const int nAddPeriod = pAffectArgs->aRangeAddPeriods[0];

			if (nAddPeriod == 0 || nAddPeriod == 1)
			{
				nNewAddRed   = nAddRed;
				nNewAddGreen = nAddGreen;
				nNewAddBlue  = nAddBlue;

				nCurAddPeriod = nAddPeriod;
			}
			else
			{
				nCurAddPeriod = this->m_nAUCounter % (nAddPeriod * 2);

				if (nAddPeriod < nCurAddPeriod)
				{
					nCurAddPeriod = nAddPeriod * 2 - nCurAddPeriod;
				}

				nNewAddRed   = (nAddRed   * nCurAddPeriod) / nAddPeriod;
				nNewAddGreen = (nAddGreen * nCurAddPeriod) / nAddPeriod;
				nNewAddBlue  = (nAddBlue  * nCurAddPeriod) / nAddPeriod;
			}

			addColor.rgbRed   *= static_cast<byte>(~nNewAddRed);
			addColor.rgbGreen *= static_cast<byte>(~nNewAddGreen);
			addColor.rgbBlue  *= static_cast<byte>(~nNewAddBlue);

			nAddShiftBack += 8;
			bHasAddEffect  = true;
		}
	}

	/* --- LIGHT --- */

	CVIDPALETTE_COLOR lightColor;
	bool bHasLightEffect = this->GetLight(&lightColor, pAffectArgs, dwFlags);

	if (pAffectArgs != nullptr)
	{
		uint *const pRangeLight = pAffectArgs->pRangeLights[0];

		if (pRangeLight != nullptr)
		{
			const uint nLightAdd = *pRangeLight;

			const int nLightRed   =  nLightAdd        & 0xFF;
			const int nLightGreen = (nLightAdd >> 8)  & 0xFF;
			const int nLightBlue  = (nLightAdd >> 16) & 0xFF;

			int nNewLightRed;
			int nNewLightGreen;
			int nNewLightBlue;

			const int nLightPeriod = pAffectArgs->aRangeLightPeriods[0];

			if (nLightPeriod == 1)
			{
				nNewLightRed   = nLightRed;
				nNewLightGreen = nLightGreen;
				nNewLightBlue  = nLightBlue;

				nCurLightPeriod = nLightPeriod;
			}
			else
			{
				nCurLightPeriod = this->m_nAUCounter % (nLightPeriod * 2);

				if (nLightPeriod < nCurLightPeriod)
				{
					nCurLightPeriod = nLightPeriod * 2 - nCurLightPeriod;
				}

				nNewLightRed   = nLightRed   * nCurLightPeriod / nLightPeriod;
				nNewLightGreen = nLightGreen * nCurLightPeriod / nLightPeriod;
				nNewLightBlue  = nLightBlue  * nCurLightPeriod / nLightPeriod;
			}

			lightColor.rgbRed   += nNewLightRed;
			lightColor.rgbGreen += nNewLightGreen;
			lightColor.rgbBlue  += nNewLightBlue;

			bHasLightEffect = true;
		}
	}

	/* --- UNKNOWN --- */

	if (pAffectArgs != nullptr && (pAffectArgs->suppressTints & (*CVidPalette::p_m_SuppressTintMasks)[0]) != 0 && (nCurLightPeriod != 0 || nCurAddPeriod != 0))
	{
		int nEffectivePeriod;
		int nEffectiveCurPeriod;

		if (nCurLightPeriod == 0 || nCurAddPeriod >= nCurLightPeriod)
		{
			// Effective = add
			nEffectivePeriod    = pAffectArgs->aRangeAddPeriods[0];
			nEffectiveCurPeriod = nCurAddPeriod;
		}
		else
		{
			// Effective = light
			nEffectivePeriod    = pAffectArgs->aRangeLightPeriods[0];
			nEffectiveCurPeriod = nCurLightPeriod;
		}

		tintColor.rgbRed   += (nMaxTintValue - tintColor.rgbRed)   * nEffectiveCurPeriod / nEffectivePeriod;
		tintColor.rgbGreen += (nMaxTintValue - tintColor.rgbGreen) * nEffectiveCurPeriod / nEffectivePeriod;
		tintColor.rgbBlue  += (nMaxTintValue - tintColor.rgbBlue)  * nEffectiveCurPeriod / nEffectivePeriod;

		if (pCurVidMode->m_nFade != *CVidMode::p_NUM_FADE_FRAMES)
		{
			tintColor.rgbRed   = tintColor.rgbRed;   // CVidMode::ApplyFadeAmount(pCVar10, tintColor.rgbRed);
			tintColor.rgbGreen = tintColor.rgbGreen; // CVidMode::ApplyFadeAmount(pCVar10, tintColor.rgbGreen);
			tintColor.rgbBlue  = tintColor.rgbBlue;  // CVidMode::ApplyFadeAmount(pCVar10, tintColor.rgbBlue);
		}
	}

	/* --- RESERVED ENTRIES --- */

	int nPaletteIndex = 0;
	const int nNumReservedEntries = this->GetReservedEntries(dwFlags);

	for (; nPaletteIndex < nNumReservedEntries; ++nPaletteIndex)
	{
		uint nNewColor;

		if (nPaletteIndex == 1)
		{
			const uint nAdjustedColor = pCurVidMode->ApplyBrightnessContrast(0);

			const int nRed   =  nAdjustedColor        & 0xFF;
			const int nGreen = (nAdjustedColor >>  8) & 0xFF;
			const int nBlue  = (nAdjustedColor >> 16) & 0xFF;

			nNewColor = (nRed << nRedShift) | (nGreen << nGreenShift) | (nBlue << nBlueShift);
		}
		else
		{
			const tagRGBQUAD color = this->m_pPalette[nPaletteIndex];
			nNewColor = (color.rgbRed << nRedShift) | (color.rgbGreen << nGreenShift) | (color.rgbBlue << nBlueShift);
		}

		pDestPalette[nPaletteIndex] = 0xFF000000 | nNewColor;
	}

	/* --- Apply --- */

	uint nOverrideAlpha = 0xFF000000;

	if ((dwFlags & 2) != 0)
	{
		nOverrideAlpha = nTransVal << 24;
	}

	for (; nPaletteIndex < this->m_nEntries; ++nPaletteIndex)
	{
		tagRGBQUAD *const pPaletteData = this->m_pPalette;

		int nToWriteRed   = pPaletteData[nPaletteIndex].rgbRed;
		int nToWriteGreen = pPaletteData[nPaletteIndex].rgbGreen;
		int nToWriteBlue  = pPaletteData[nPaletteIndex].rgbBlue;
		int nPaletteAlpha = pPaletteData[nPaletteIndex].rgbReserved;

		if ((dwFlags & 0x80000) != 0)
		{
			nToWriteBlue  = (pPaletteData[nPaletteIndex].rgbBlue + pPaletteData[nPaletteIndex].rgbGreen + pPaletteData[nPaletteIndex].rgbRed) >> 2;
			nToWriteRed   = nToWriteBlue;
			nToWriteGreen = nToWriteBlue;
		}

		if ((dwFlags & 0x2000000) != 0)
		{
			const int nKindaAverage = (nToWriteRed + nToWriteGreen + nToWriteBlue) / 4;
			nToWriteRed   = (std::min)(nKindaAverage + 21, 255);
			nToWriteGreen = (std::min)(nKindaAverage, 255);
			nToWriteBlue  = nKindaAverage - (std::min)(nKindaAverage, 32);
		}

		if (bHasTintEffect != 0)
		{
			nToWriteRed   = (nToWriteRed   * tintColor.rgbRed)   >> nTintShiftBack;
			nToWriteGreen = (nToWriteGreen * tintColor.rgbGreen) >> nTintShiftBack;
			nToWriteBlue  = (nToWriteBlue  * tintColor.rgbBlue)  >> nTintShiftBack;
		}

		if (bHasAddEffect != 0)
		{
			nToWriteRed   = static_cast<byte>(~((static_cast<byte>(~nToWriteRed)   * addColor.rgbRed)   >> nAddShiftBack));
			nToWriteGreen = static_cast<byte>(~((static_cast<byte>(~nToWriteGreen) * addColor.rgbGreen) >> nAddShiftBack));
			nToWriteBlue  = static_cast<byte>(~((static_cast<byte>(~nToWriteBlue)  * addColor.rgbBlue)  >> nAddShiftBack));
		}

		if (bHasLightEffect != 0)
		{
			nToWriteRed   = (std::min)((nToWriteRed   * lightColor.rgbRed)   >> 3, 255);
			nToWriteGreen = (std::min)((nToWriteGreen * lightColor.rgbGreen) >> 3, 255);
			nToWriteBlue  = (std::min)((nToWriteBlue  * lightColor.rgbBlue)  >> 3, 255);
		}

		uint nToWrite;

		if (nPaletteAlpha == 0 || nPaletteAlpha == 255)
		{
			nToWrite = (nToWriteRed << nRedShift) | (nToWriteGreen << nGreenShift) | (nToWriteBlue << nBlueShift) | nOverrideAlpha;
		}
		else
		{
			nToWrite = (nToWriteRed << nRedShift) | (nToWriteGreen << nGreenShift) | (nToWriteBlue << nBlueShift) | (nPaletteAlpha << 24);
		}

		pDestPalette[nPaletteIndex] = nToWrite;
	}

	const tagRGBQUAD firstColor = this->m_pPalette[0];

	if ((dwFlags & 1) != 0 && firstColor.rgbRed == 0 && firstColor.rgbGreen == 255 && firstColor.rgbBlue == 0 && firstColor.rgbReserved == 0)
	{
		pDestPalette[0] &= 0x00FFFFFF;
	}

	if ((dwFlags & 4) != 0)
	{
		if ((dwFlags & 2) != 0)
		{
			pDestPalette[1] = ((nTransVal * 128 / 255) << 24) | (pDestPalette[1] & 0x00FFFFFF);
		}
		else
		{
			pDestPalette[1] = 0x7F000000 | (pDestPalette[1] & 0x00FFFFFF);
		}
	}
}
