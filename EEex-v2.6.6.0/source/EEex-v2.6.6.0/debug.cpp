
#include "Baldur-v2.6.6.0_generated.h"

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
