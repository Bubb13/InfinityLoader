
#pragma once

#include <string>
#include <unordered_map>
#include <vector>
#include <mutex>
#include <set>

#include "time_util.hpp"

/////////////
// Classes //
/////////////

template<typename YType>
class ImRollingLineGraph
{
	struct DataPoint
	{
		TimeType nTime;
		YType nYValue;
	};

	std::string sTitle;
	std::string sTitleXAxis;
	std::string sTitleYAxis;

	std::vector<double> xArray;
	std::vector<double> yArray;

	std::multiset<YType, std::greater<YType>> maxYValuePriorityQueue;

	TimeType nRollingDataTimePeriod;
	TimeType nDataDisplayScale;

	std::mutex m;
	std::unordered_map<std::string, std::vector<DataPoint>> allDataPoints;

	void PruneOld(TimeType newest);

public:

	ImRollingLineGraph(const char* sTitle, const char* sTitleXAxis, const char* sTitleYAxis, TimeType nRollingDataTimePeriod, TimeType nDataDisplayScale);

	//----------------------------------------------------
	// Logging
	//----------------------------------------------------

	void Plot(const std::string& sLineName, TimeType nTime, YType nYValue);

	//----------------------------------------------------
	// Rendering
	//----------------------------------------------------

	void Draw(TimeType nCurrentTime);
};
