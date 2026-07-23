
#include "implot.h"
#include "im_rolling_line_graph.hpp"

#include "infinity_loader_common_api.h"

///////////////
// Functions //
///////////////

template<typename YType>
ImRollingLineGraph<YType>::ImRollingLineGraph(
	const char* sTitle, const char* sTitleXAxis, const char* sTitleYAxis, TimeType nRollingDataTimePeriod, TimeType nDataDisplayScale)
	: sTitle(sTitle), sTitleXAxis(sTitleXAxis), sTitleYAxis(sTitleYAxis),
	nRollingDataTimePeriod(nRollingDataTimePeriod), nDataDisplayScale(nDataDisplayScale)
{
}

template<typename YType>
void ImRollingLineGraph<YType>::Plot(const std::string& sLineName, TimeType nTime, YType nYValue)
{
	std::scoped_lock lock(m);

	maxYValuePriorityQueue.insert(nYValue);

	std::vector<DataPoint>& dataPoints = allDataPoints[sLineName];
	dataPoints.push_back({ nTime, nYValue });
}

template<typename YType>
void ImRollingLineGraph<YType>::PruneOld(TimeType nCurrentTime)
{
	const TimeType nCutOff = (nCurrentTime > nRollingDataTimePeriod) ? nCurrentTime - nRollingDataTimePeriod : 0;

	for (auto allDataPointsItr = allDataPoints.begin(); allDataPointsItr != allDataPoints.end(); )
	{
		std::vector<DataPoint>& dataPoints = allDataPointsItr->second;

		for (auto dataPointsItr = dataPoints.begin(); dataPointsItr != dataPoints.end(); )
		{
			const DataPoint& dataPoint = *dataPointsItr;

			if (dataPoint.nTime < nCutOff)
			{
				maxYValuePriorityQueue.erase(maxYValuePriorityQueue.find(dataPoint.nYValue));
				dataPointsItr = dataPoints.erase(dataPointsItr);
			}
			else
			{
				++dataPointsItr;
			}
		}

		const auto oldItr = allDataPointsItr++;

		if (dataPoints.empty())
		{
			allDataPoints.erase(oldItr);
		}
	}
}

///////////////
// Rendering //
///////////////

TimeType nFirstCurrentTime = -1;

template<typename YType>
void ImRollingLineGraph<YType>::Draw(TimeType nCurrentTime)
{
	std::scoped_lock lock(m);

	PruneOld(nCurrentTime);

	const TimeType nPlotTotalTime = nRollingDataTimePeriod;

	const TimeType nPlotStartTime = (nCurrentTime > nPlotTotalTime) ? nCurrentTime - nPlotTotalTime : 0;
	const TimeType nPlotEndTime = nPlotStartTime + nPlotTotalTime;

	const double fScaledWidth = static_cast<double>(nPlotTotalTime) / nDataDisplayScale;

	if (ImPlot::BeginPlot(sTitle.c_str(), ImVec2(-1, 250)))
	{
		ImPlot::SetupAxes(sTitleXAxis.c_str(), sTitleYAxis.c_str());

		ImPlot::SetupAxisLimits(
			ImAxis_X1,
			-fScaledWidth,
			0.0,
			ImGuiCond_Always
		);

		const TimeType nMaxYValue = maxYValuePriorityQueue.empty() ? 0 : *maxYValuePriorityQueue.begin();

		ImPlot::SetupAxisLimits(
			ImAxis_Y1,
			0,
			static_cast<double>(nMaxYValue),
			ImGuiCond_Always
		);

		for (const auto& [sLineName, dataPoints] : allDataPoints)
		{
			xArray.clear();
			yArray.clear();

			for (const DataPoint& dataPoint : dataPoints)
			{
				TimeType nDataPointTime = dataPoint.nTime;

				const double nDataPointXPercent = static_cast<double>(nDataPointTime - nPlotStartTime) / nPlotTotalTime;
				const double nDataPointScaledX = -fScaledWidth + (fScaledWidth * nDataPointXPercent);
				const double nDataPointScaledY = static_cast<double>(dataPoint.nYValue);

				xArray.push_back(nDataPointScaledX);
				yArray.push_back(nDataPointScaledY);
			}

			char id[32];
			sprintf(id, "##span%zu", static_cast<uint64_t>(0));

			ImPlotSpec spec;
			spec.LineColor = ImVec4(1,0,0,1);
			spec.LineWeight = 2.0f;
			spec.Marker = ImPlotMarker_Circle;
			spec.Flags = ImPlotItemFlags_NoLegend;

			ImPlot::PlotLine(id, xArray.data(), yArray.data(), static_cast<int>(xArray.size()), spec);
		}

		ImPlot::EndPlot();
	}
}

template class ImRollingLineGraph<TimeType>;
