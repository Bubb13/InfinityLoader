
#pragma once

#include "time_util.hpp"

enum class TraceType
{
	NONE,
	NORMAL,
	SPAM
};

#pragma pack(push, 1)
struct SavedRegisters
{
	byte xmm1[16];
	byte xmm0[16];
	uintptr_t r11;
	uintptr_t r10;
	uintptr_t r9;
	uintptr_t r8;
	uintptr_t rdx;
	uintptr_t rcx;
	uintptr_t rax;
};
#pragma pack(pop)

void Profiler_StartTrace(TimeType startTime, TraceType toStartType);
void __stdcall Profiler_Trace(uintptr_t funcAddress, const SavedRegisters* savedRegisters, void* stackPtr);
void Profiler_RegisterTrace(const char* traceName, uintptr_t address, TimeType logTimeThreshold);
