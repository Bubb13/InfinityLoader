
#pragma once

#include "im_rolling_line_graph.hpp"

/////////////
// Globals //
/////////////

extern ImRollingLineGraph<TimeType> rollingFlipTime;
extern ImRollingLineGraph<TimeType> rollingTimeBetweenFlipEnds;
extern ImRollingLineGraph<TimeType> rollingTimeBetweenFullUpdates;

extern ImRollingLineGraph<TimeType> rollingScrollDeltaX;
extern ImRollingLineGraph<TimeType> rollingScrollDeltaY;

///////////////
// Functions //
///////////////

void CreateDebugWindow();
bool IsDebugWindowOpen();
