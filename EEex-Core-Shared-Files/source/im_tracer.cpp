
/*
* Unfinished
*/

#include <implot.h>

#include "im_tracer.hpp"

///////////////
// Functions //
///////////////

static constexpr TimeType WindowUS = 5000000; // 1 seconds

void FunctionTimeline::Begin(const std::string& name, TimeType time_us)
{
	std::scoped_lock lock(m);

	active[name].push_back({time_us});

	if (!rows.count(name))
	{
		rows[name] = (int)rows.size();
	}
}

void FunctionTimeline::End(const std::string& name, TimeType time_us)
{
	std::scoped_lock lock(m);

	auto it = active.find(name);
	if (it == active.end() || it->second.empty())
	{
		return;
	}

	ActiveCall call = it->second.back();
	it->second.pop_back();

	spans.push_back({
		name,
		call.start_us,
		time_us,
		rows[name]
	});

	PruneOld(time_us);
}

void FunctionTimeline::Clear()
{
	std::scoped_lock lock(m);
	spans.clear();
	active.clear();
}

void FunctionTimeline::PruneOld(TimeType newest)
{
	TimeType cutoff = (newest > WindowUS) ? newest - WindowUS : 0;

	spans.erase(
		std::remove_if(
			spans.begin(),
			spans.end(),
			[&](const Span& s)
			{
				return s.end_us < cutoff;
			}
		),
		spans.end()
	);
}

//----------------------------------------------------
// Rendering
//----------------------------------------------------

void FunctionTimeline::Draw(const char* title)
{
	std::scoped_lock lock(m);

	if (spans.empty())
	{
		return;
	}

	TimeType newest = 0;

	for (const Span& s : spans)
	{
		newest = (std::max)(newest, s.end_us);
	}

	TimeType windowStart = (newest > WindowUS) ? newest - WindowUS : 0;

	if (ImPlot::BeginPlot(title, ImVec2(-1, 300)))
	{
		ImPlot::SetupAxes("Seconds Ago", nullptr);

		// X axis is always [-5,0]
		ImPlot::SetupAxisLimits(
			ImAxis_X1,
			-5.0,
			0.0,
			ImGuiCond_Always
		);

		ImPlot::SetupAxisLimits(
			ImAxis_Y1,
			0,
			(double)rows.size(),
			ImGuiCond_Always
		);

		for (size_t i = 0; i < spans.size(); ++i)
		{
			const Span& s = spans[i];

			// Skip spans outside the window.
			if (s.end_us < windowStart)
			{
				continue;
			}

			// Clamp to visible window.
			TimeType begin = (std::max)(s.start_us, windowStart);
			TimeType end   = (std::min)(s.end_us, newest);

			// Convert to seconds relative to newest sample.

			double startX = (double)(begin - newest) / 1e6;
			double endX = (double)(end - newest) / 1e6;

			double x[2] =
			{
				startX,
				(std::max)(endX, startX + 0.01)
			};

			double lower[2] =
			{
				s.row + 0.15,
				s.row + 0.15
			};

			double upper[2] =
			{
				s.row + 0.85,
				s.row + 0.85
			};

			char id[32];
			sprintf(id, "##span%zu", static_cast<uint64_t>(0));

			ImPlot::PlotShaded(id, x, lower, upper, 2);

			// Draw label if the bar is wide enough.
			if (x[1] - x[0] > 0.05)
			{
				ImPlot::PlotText(
					s.name.c_str(),
					0.5 * (x[0] + x[1]),
					s.row + 0.5,
					ImVec2(0.5f, 0.5f)
				);
			}
		}

		ImPlot::EndPlot();
	}
}
