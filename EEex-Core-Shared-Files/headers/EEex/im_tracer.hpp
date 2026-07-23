
/*
* Unfinished
*/

#pragma once

#include <string>
#include <unordered_map>
#include <vector>
#include <mutex>

#include "time_util.hpp"

/////////////
// Classes //
/////////////

class FunctionTimeline
{
	struct Span
	{
		std::string name;
		TimeType start_us;
		TimeType end_us;
		int row;
	};

	struct ActiveCall
	{
		TimeType start_us;
	};

	// Completed spans
	std::vector<Span> spans;

	// Active (supports recursion)
	std::unordered_map<std::string, std::vector<ActiveCall>> active;

	// Function -> row number
	std::unordered_map<std::string, int> rows;

	std::mutex m;

	void PruneOld(TimeType newest);

public:

	//----------------------------------------------------
	// Logging
	//----------------------------------------------------

	void Begin(const std::string& name, TimeType time_us);
	void End(const std::string& name, TimeType time_us);
	void Clear();

	//----------------------------------------------------
	// Rendering
	//----------------------------------------------------

	void Draw(const char* title = "Function Timeline");
};
