
#include "Baldur-v2.6.6.0_generated.h"

//-----------------------------//
//          Functions          //
//-----------------------------//

int getMenuStackTop()
{
	return *p_nextStackMenuIdx > 0 ? *p_nextStackMenuIdx - 1 : 0;
}

int getMenuX(uiMenu* pMenu)
{
	const int nHorizontalAlignment = pMenu->ha;
	const int nScreenWidth = *CVidMode::p_SCREENWIDTH;
	const int nMenuWidth = pMenu->width;

	int nAlignmentX = 0;

	if (nHorizontalAlignment == 1) // right
	{
		nAlignmentX = nScreenWidth - nMenuWidth;
	}
	else if (nHorizontalAlignment == 2) // center
	{
		nAlignmentX = nScreenWidth / 2 - nMenuWidth / 2;
	}

	return nAlignmentX + pMenu->offset.x;
}

int getMenuY(uiMenu* pMenu)
{
	const int nVerticalAlignment = pMenu->va;
	const int nScreenHeight = *CVidMode::p_SCREENHEIGHT;
	const int nMenuHeight = pMenu->height;

	int nAlignmentY = 0;

	if (nVerticalAlignment == 1) // bottom
	{
		nAlignmentY = nScreenHeight - nMenuHeight;
	}
	else if (nVerticalAlignment == 2) // center
	{
		nAlignmentY = nScreenHeight / 2 - nMenuHeight / 2;
	}

	return nAlignmentY + pMenu->offset.y;
}

uiMenu* getStackMenu(int num)
{
	return num > -1 && num < *p_nextStackMenuIdx ? (*p_menuStack)[num] : nullptr;
}
