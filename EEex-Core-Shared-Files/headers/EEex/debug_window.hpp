
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

extern ImRollingLineGraph<TimeType> rollingFullUpdateTime;
extern ImRollingLineGraph<TimeType> rollingRenderTime;
extern ImRollingLineGraph<TimeType> rollingLuaGCTime;
extern ImRollingLineGraph<TimeType> rollingFullUpdatePhase;
extern ImRollingLineGraph<TimeType> rollingFullUpdateLateBy;
extern ImRollingLineGraph<TimeType> rollingLogicTime;

///////////////
// Functions //
///////////////

void CreateDebugWindow();
bool IsDebugWindowOpen();
