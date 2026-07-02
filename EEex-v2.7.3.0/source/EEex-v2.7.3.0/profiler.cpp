
#include <algorithm>
#include <cinttypes>
#include <mutex>
#include <shared_mutex>
#include <unordered_map>
#include <vector>

#include <Windows.h>

#include "Baldur-v2.7.3.0_generated.h"
#include "engine_function_names.hpp"
#include "infinity_loader_common_api.h"
#include "profiler.hpp"
#include "time_util.hpp"

//---------------------------//
//          Structs          //
//---------------------------//

struct ReturnPtr
{
	void* sourceStackPtr;
	uintptr_t function;
	SavedRegisters savedRegisters;
	void* returnPtr;
	bool alsoPopPrevious;
	TimeType startTime;
};

template<typename T>
struct ThreadLocalContainer
{
	T value{};
	DWORD threadID = GetCurrentThreadId();
	std::vector<ThreadLocalContainer<T>*>* storageVector;
	size_t position = static_cast<size_t>(-1);
	bool deadAllocatedCopy = false;
	std::shared_mutex* storageLock;

	ThreadLocalContainer(std::vector<ThreadLocalContainer<T>*>* storageVector, std::shared_mutex* storageLock, bool add = true);
	~ThreadLocalContainer();
};

template<typename T>
ThreadLocalContainer<T>::ThreadLocalContainer(std::vector<ThreadLocalContainer<T>*> *const theStorageVector, std::shared_mutex *const theStorageLock, const bool add)
{
	storageVector = theStorageVector;
	storageLock = theStorageLock;

	if (add)
	{
		const std::unique_lock lk1 { *storageLock };
		position = storageVector->size();
		storageVector->push_back(this);
	}
}

template<typename T>
ThreadLocalContainer<T>::~ThreadLocalContainer()
{
	if (!deadAllocatedCopy)
	{
		const std::unique_lock lk1 { *storageLock };
		ThreadLocalContainer<T> *const copy = new ThreadLocalContainer<T> { storageVector, storageLock, false };
		copy->deadAllocatedCopy = true;
		copy->value = std::move(value);
		storageVector->at(position) = copy;
	}
}

struct TimerEntry
{
	TimeType milliseconds;
	std::string column1;
	std::string column2;
	std::string column3;
	std::string column4;
	std::string column5;
	std::string column6;
};

struct TimerTime
{
	TimeType microseconds = 0;
	size_t callCount = 0;
	std::vector<std::string> debugLines{};
};

struct TraceEntry
{
	TraceType traceType;
	std::string traceName;
	uintptr_t endFunction;
	TimeType logTimeThreshold;
};

//---------------------------//
//          Globals          //
//---------------------------//

thread_local std::vector<ReturnPtr> threadSavedReturnPtrs;

std::vector<ThreadLocalContainer<std::unordered_map<uintptr_t, TimerTime>>*> funcTimesRefs;
std::shared_mutex funcTimesRefsLock;
thread_local ThreadLocalContainer<std::unordered_map<uintptr_t, TimerTime>> threadFuncTimes { &funcTimesRefs, &funcTimesRefsLock };

std::atomic<TraceType> traceType;
std::atomic<bool> pendingSpamTrace;
TimeType startTraceTime;

DWORD traceStartThreadID;

std::unordered_map<uintptr_t, TraceEntry> traceEntries;
std::shared_mutex traceEntriesLock;
TraceEntry currentTraceEntry;
std::mutex startTracingLock;

//-----------------------------//
//          Functions          //
//-----------------------------//

void Profiler_StartTrace(const TimeType startTime, const TraceType toStartType)
{
	if (toStartType == TraceType::NORMAL)
	{
		traceStartThreadID = GetCurrentThreadId();
		startTraceTime = startTime;

		const std::unique_lock lk1 { funcTimesRefsLock };

		size_t curI = 0;
		for (auto itr = funcTimesRefs.begin(); itr != funcTimesRefs.end(); )
		{
			auto& threadLocalContainer = *itr;
			if (threadLocalContainer->deadAllocatedCopy)
			{
				delete threadLocalContainer;
				itr = funcTimesRefs.erase(itr);
			}
			else
			{
				threadLocalContainer->value.clear();
				threadLocalContainer->position = curI++;
				++itr;
			}
		}
	}

	traceType = toStartType;
}

void Profiler_RegisterTrace(const char *const traceName, const uintptr_t address, const TimeType logTimeThreshold)
{
	std::unique_lock lk1 { traceEntriesLock };
	traceEntries.try_emplace(address, TraceType::NORMAL, traceName, address, logTimeThreshold);
}

static bool sortTimerEntryByTime(const TimerEntry& a, const TimerEntry& b)
{
	return a.milliseconds > b.milliseconds;
}

static std::string formatString(const char *const format, ...)
{
	constexpr int initialBufferSize = 256;

	va_list args;
	va_start(args, format);

	int bufferSize = initialBufferSize;
	std::string result;

	while (true)
	{
		char *const buffer = new char[bufferSize];
		const int ret = vsnprintf(buffer, bufferSize, format, args);

		if (ret <= -1)
		{
			// Encoding error
			delete[] buffer;
			result = "<ENCODING_ERROR>";
			break;
		}

		if (ret < bufferSize)
		{
			// Formatting succeeded
			result = buffer;
			delete[] buffer;
			break;
		}

		// Increase buffer size and try again
		delete[] buffer;
		bufferSize = ret + 1;
	}

	va_end(args);
	return result;
}

static void endTracingNormal(const TimeType endTime)
{
	const TimeType totalMicroseconds = endTime - startTraceTime;

	if (totalMicroseconds / 1000 <= currentTraceEntry.logTimeThreshold)
	{
		return;
	}

	FPrint("[%s] - Total Time: %.02f ms\n", currentTraceEntry.traceName.c_str(), static_cast<double>(totalMicroseconds) / 1000);

	{
		const std::unique_lock lk1 { funcTimesRefsLock };

		for (const ThreadLocalContainer<std::unordered_map<uintptr_t, TimerTime>> *const threadFuncTimesRef : funcTimesRefs)
		{
			if (threadFuncTimesRef->value.empty())
			{
				continue;
			}

			std::vector<TimerEntry> toSort{};
			size_t longestColumn1 = 0;
			size_t longestColumn2 = 0;
			size_t longestColumn3 = 0;
			size_t longestColumn4 = 0;
			size_t longestColumn5 = 0;

			for (const auto& x : threadFuncTimesRef->value)
			{
				const TimeType microseconds = x.second.microseconds;
				const double percent = totalMicroseconds != 0 ? (static_cast<double>(microseconds) * 100 / totalMicroseconds) : 0;

				if (percent >= 1)
				{
					TimerEntry& placed = toSort.emplace_back();
					placed.milliseconds = microseconds;
					placed.column1 = formatString("%lux", x.second.callCount);
					placed.column2 = formatString("%.02f%%", percent);
					placed.column3 = formatString("%.02f ms", static_cast<double>(microseconds) / 1000);
					placed.column4 = formatString("%.02f ms", static_cast<double>(microseconds) / 1000 / x.second.callCount);
					placed.column5 = formatString("0x%" PRIXPTR, x.first);
					placed.column6 = formatString("%s", GetFunctionName(x.first).c_str());

					if (const size_t len = placed.column1.length(); len > longestColumn1)
					{
						longestColumn1 = len;
					}

					if (const size_t len = placed.column2.length(); len > longestColumn2)
					{
						longestColumn2 = len;
					}

					if (const size_t len = placed.column3.length(); len > longestColumn3)
					{
						longestColumn3 = len;
					}

					if (const size_t len = placed.column4.length(); len > longestColumn4)
					{
						longestColumn4 = len;
					}

					if (const size_t len = placed.column5.length(); len > longestColumn5)
					{
						longestColumn5 = len;
					}
				}
			}

			std::sort(toSort.begin(), toSort.end(), sortTimerEntryByTime);

			if (!toSort.empty())
			{
				if (threadFuncTimesRef->threadID == traceStartThreadID)
				{
					FPrint("    [Thread 0x%X] - Primary\n", threadFuncTimesRef->threadID);
				}
				else
				{
					FPrint("    [Thread 0x%X]\n", threadFuncTimesRef->threadID);
				}

				for (const auto& x : toSort)
				{
					FPrint("        | %s | total %s | %s | %s avg | %s | %s\n",
						formatString("%*s", longestColumn1, x.column1.c_str()).c_str(),
						formatString("%*s", longestColumn2, x.column2.c_str()).c_str(),
						formatString("%*s", longestColumn3, x.column3.c_str()).c_str(),
						formatString("%*s", longestColumn4, x.column4.c_str()).c_str(),
						formatString("%*s", longestColumn5, x.column5.c_str()).c_str(),
						formatString("%s", x.column6.c_str()).c_str()
					);
				}
			}

			for (const auto& x : threadFuncTimesRef->value)
			{
				const TimerTime& timerTime = x.second;

				for (const std::string& debugLine : timerTime.debugLines)
				{
					FPrint("        %s", debugLine.c_str());
				}
			}
		}
	}
}

static void endTracing(const TimeType endTime)
{
	const std::unique_lock lk1 { startTracingLock };

	if (traceType == TraceType::NORMAL)
	{
		endTracingNormal(endTime);
	}

	traceType = TraceType::NONE;
}

static void endFunctionTrace(const TimeType endTime, const ReturnPtr& realReturnPtr)
{
	switch (traceType)
	{
		case TraceType::NORMAL:
		{
			{
				// To prevent endTracing() from locking threadFuncTimes is ONLY modified by the current thread
				const std::shared_lock lk1 { funcTimesRefsLock };
				TimerTime& timerTime = threadFuncTimes.value[realReturnPtr.function];
				// std::max() so long running functions (those in another thread that started before the trace) don't appear over 100%

				const TimeType timeTaken = endTime - (std::max)(startTraceTime, realReturnPtr.startTime);
				timerTime.microseconds += timeTaken;
				++timerTime.callCount;

				// TODO HACK
				if (realReturnPtr.function == 0x1403D0A50)
				{
					const uiItem *const item = reinterpret_cast<uiItem*>(realReturnPtr.savedRegisters.rcx);
					const char *const menuName = item->menu != nullptr ? item->menu->name : "(null)";
					timerTime.debugLines.emplace_back(formatString("Took %.02f ms to draw item %s with type %d in menu %s\n", static_cast<double>(timeTaken) / 1000, item->name, item->type, menuName));
				}
			}

			if (traceStartThreadID == GetCurrentThreadId() && realReturnPtr.function == currentTraceEntry.endFunction)
			{
				endTracing(endTime);
			}

			break;
		}
		case TraceType::SPAM:
		{
			const std::string funcName = GetFunctionName(realReturnPtr.function);
			FPrint("[%p] END %s\n", GetCurrentThreadId(), funcName.c_str());
			break;
		}
	}
}

extern "C" void* Profiler_GetCurReturn() // Called by Profiler_Return() in profiler_assembly.asm
{
	const TimeType endTime = getTime();

	if (threadSavedReturnPtrs.empty())
	{
		MessageBoxA(NULL, "[EEex] Assert failed", "EEex", MB_ICONERROR);
	}

	ReturnPtr realReturnPtr;
	do
	{
		realReturnPtr = threadSavedReturnPtrs.back();
		threadSavedReturnPtrs.pop_back();

		if (traceType != TraceType::NONE)
		{
			endFunctionTrace(endTime, realReturnPtr);
		}
	}
	while (realReturnPtr.alsoPopPrevious);

	return realReturnPtr.returnPtr;
}

extern "C" void Profiler_Return(); // In profiler_assembly.asm

void __stdcall Profiler_Trace(const uintptr_t funcAddress, const SavedRegisters *const savedRegisters, void *const stackPtr)
{
	const TimeType startTime = getTime();
	const bool alsoPopPrevious = !threadSavedReturnPtrs.empty() && threadSavedReturnPtrs.back().sourceStackPtr == stackPtr;

	ReturnPtr& placed = threadSavedReturnPtrs.emplace_back();
	placed.sourceStackPtr = stackPtr;
	placed.function = funcAddress;
	placed.returnPtr = (void*)*(uintptr_t*)stackPtr;
	placed.alsoPopPrevious = alsoPopPrevious;
	placed.startTime = startTime;
	placed.savedRegisters = *savedRegisters;

	*reinterpret_cast<uintptr_t*>(stackPtr) = reinterpret_cast<uintptr_t>(Profiler_Return);

	switch (traceType)
	{
		case TraceType::NONE:
		{
			{
				const std::shared_lock lk1 { traceEntriesLock };

				if (const auto itr = traceEntries.find(funcAddress); itr != traceEntries.end())
				{
					const std::unique_lock lk1 { startTracingLock };

					if (traceType == TraceType::NONE)
					{
						currentTraceEntry = itr->second;
						Profiler_StartTrace(startTime, currentTraceEntry.traceType);
					}
				}
			}

			const std::unique_lock lk1 { startTracingLock };

			if (traceType == TraceType::NONE && pendingSpamTrace)
			{
				pendingSpamTrace = false;
				Profiler_StartTrace(startTime, TraceType::SPAM);
			}

			break;
		}
		case TraceType::SPAM:
		{
			const std::string funcName = GetFunctionName(funcAddress);
			FPrint("[%p] START %s\n", GetCurrentThreadId(), funcName.c_str());
			break;
		}
	}
}
