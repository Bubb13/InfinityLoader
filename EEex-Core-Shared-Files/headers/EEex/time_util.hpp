
#pragma once

#include <Windows.h>

//-----------------------------//
//          Type Defs          //
//-----------------------------//

typedef long long TimeType;

//-----------------------------//
//          Functions          //
//-----------------------------//

DWORD getHighestRefreshRate();
TimeType getInitTime();
TimeType getTime();
void initTimeUtil();
