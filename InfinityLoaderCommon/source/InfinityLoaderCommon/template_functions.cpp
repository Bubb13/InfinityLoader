
#include "InfinityLoaderCommon.h"
#include "template_functions.h"

/////////////
// Globals //
/////////////

const std::initializer_list<const std::pair<TCHAR, unsigned char>> aDecimalDigitToByte = {
	std::pair{TCHAR{'0'}, 0},
	std::pair{TCHAR{'1'}, 1},
	std::pair{TCHAR{'2'}, 2},
	std::pair{TCHAR{'3'}, 3},
	std::pair{TCHAR{'4'}, 4},
	std::pair{TCHAR{'5'}, 5},
	std::pair{TCHAR{'6'}, 6},
	std::pair{TCHAR{'7'}, 7},
	std::pair{TCHAR{'8'}, 8},
	std::pair{TCHAR{'9'}, 9},
};

///////////////
// Functions //
///////////////

void LogUsingFuncT(LogFuncT logFunc, const TCHAR* formatText, ...) {

	va_list args;
	TCHAR buffer[printBufferCount];
	constexpr DWORD count = _countof(buffer);

	va_start(args, formatText);
	int bytesWritten = _vsnprintfT_s(buffer, count, _TRUNCATE, formatText, args);
	va_end(args);

	logFunc(buffer);
}
