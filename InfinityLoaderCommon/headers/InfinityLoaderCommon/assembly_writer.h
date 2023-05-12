
#pragma once

#include <cstdint>

#include "dll_api.h"

class AssemblyWriter {
private:
	unsigned char* buffer;
	size_t curI;
	intptr_t startMemAddress;
	intptr_t curMemAddress;
public:
	EXPORT AssemblyWriter(unsigned char* buff);
	EXPORT intptr_t getLocation();
	EXPORT void setLocation(intptr_t newCurMemAddress);
	EXPORT void writeBytesToBuffer(int numBytes, ...);
	EXPORT void writeNumberToBuffer(intptr_t pointer, size_t writeSize);
	EXPORT void writeRelativeToBuffer32(intptr_t relAddress);
	EXPORT void branchUsingIndirect64(intptr_t destAddress, unsigned char branchOpcode);
	EXPORT void writeArgImmediate32(__int32 num, int argI);
	EXPORT void jmpToAddressFar(intptr_t address);
	EXPORT void jmpToAddress(intptr_t address);
	EXPORT void callToAddressFar(intptr_t address);
	EXPORT void callToAddress(intptr_t address);
	EXPORT void alignStackAndMakeShadowSpace();
	EXPORT void undoAlignAndShadowSpace();
	EXPORT void pushVolatileRegisters();
	EXPORT void popVolatileRegisters();
	EXPORT void printBuffer();
	EXPORT void flush();
};
