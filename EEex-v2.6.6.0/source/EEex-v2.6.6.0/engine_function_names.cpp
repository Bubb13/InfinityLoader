
#include <fstream>
#include <vector>

#include "engine_function_names.hpp"
#include "infinity_loader_common_api.h"

///////////////
// Constants //
///////////////

std::string EMPTY_STRING { "" };

/////////////
// Globals //
/////////////

std::vector<std::pair<uintptr_t, std::string>> addressToName{};

///////////////
// Functions //
///////////////

const std::string& GetContainingFunctionName(uintptr_t address)
{
	const size_t size = addressToName.size();
	const size_t lastValidIndex = size - 1;

	size_t l = 0;
	size_t r = size;

	while (l < r)
	{
		const size_t mid = (l + r) / 2;
		const std::pair<uintptr_t, std::string>& pair = addressToName.at(mid);

		if (address >= pair.first)
		{
			if (pair.first == address || mid == lastValidIndex || address < addressToName.at(mid + 1).first)
			{
				return pair.second;
			}

			l = mid + 1;
		}
		else
		{
			r = mid;
		}
	}

	return EMPTY_STRING;
}

const std::string& GetFunctionName(uintptr_t address)
{
	size_t l = 0;
	size_t r = addressToName.size();

	while (l < r)
	{
		const size_t mid = (l + r) / 2;
		const std::pair<uintptr_t, std::string>& pair = addressToName.at(mid);

		if (address < pair.first)
		{
			r = mid;
		}
		else if (pair.first == address)
		{
			return pair.second;
		}
		else
		{
			l = mid + 1;
		}
	}

	return EMPTY_STRING;
}

void LoadFunctionNames()
{
	std::ifstream inputFile { "function_names.db" };

	if (!inputFile)
	{
		FPrint("[!][EEex.dll] LoadFunctionNames() - Error opening function_names.db\n");
		return;
	}

	for (std::string line; std::getline(inputFile, line); )
	{
		const size_t spaceI = line.find('\t');
		const uintptr_t address = std::stoull(line.substr(0, spaceI), nullptr, 16);
		addressToName.emplace_back(address, line.substr(spaceI + 1));
	}

	inputFile.close();
	return;
}
