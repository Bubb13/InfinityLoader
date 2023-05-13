
#pragma once

#include <cstdint>

#include "dll_api.h"

class AssemblyWriterImp {
private:
	friend class AssemblyWriter;
	size_t bufferSize;
	unsigned char* buffer;
	size_t curI;
	uintptr_t startMemAddress;
	uintptr_t curMemAddress;
	AssemblyWriterImp();
	~AssemblyWriterImp();
};

class AssemblyWriter {
private:
	AssemblyWriterImp* imp;
public:
	EXPORT AssemblyWriter();
	EXPORT ~AssemblyWriter();
	EXPORT const unsigned char* GetBuffer();
	EXPORT uintptr_t GetCurrentLocation();
	EXPORT uintptr_t GetStartingLocation();
	EXPORT size_t GetSize();
	EXPORT void AlignStackAndMakeShadowSpace();
	void branchUsingIndirect64(uintptr_t destAddress, unsigned char branchOpcode);
	EXPORT void CallToAddress(uintptr_t address);
	EXPORT void CallToAddressFar(uintptr_t address);
	EXPORT void Flush();
	EXPORT void JmpToAddress(uintptr_t address);
	EXPORT void JmpToAddressFar(uintptr_t address);
	EXPORT void PopVolatileRegisters();
	EXPORT void PrintBuffer();
	EXPORT void PushVolatileRegisters();
	EXPORT void SetLocation(uintptr_t newCurMemAddress);
	EXPORT void UndoAlignAndShadowSpace();
	EXPORT void WriteArgImmediate32(size_t argI, __int32 num);
	EXPORT void WriteBytesToBuffer(size_t numBytes, ...);
	EXPORT void WriteNumberToBuffer(uintptr_t pointer, size_t writeSize);
	EXPORT void WriteRelativeToBuffer32(uintptr_t relAddress);
};
