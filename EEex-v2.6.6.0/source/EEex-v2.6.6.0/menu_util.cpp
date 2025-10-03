
#include "Baldur-v2.6.6.0_generated.h"

//-----------------------------//
//          Functions          //
//-----------------------------//

int getMenuStackTop()
{
	return *p_nextStackMenuIdx > 0 ? *p_nextStackMenuIdx - 1 : 0;
}

uiMenu* getStackMenu(int num)
{
	return num > -1 && num < *p_nextStackMenuIdx ? (*p_menuStack)[num] : nullptr;
}
