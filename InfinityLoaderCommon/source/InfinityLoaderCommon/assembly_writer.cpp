
#include "InfinityLoaderCommon.h"
#include "assembly_writer.h"

//////////////////////
// Assembly Writing //
//////////////////////

EXPORT AssemblyWriter::AssemblyWriter(unsigned char* buff) :
	buffer(buff), curI(0), startMemAddress(0),
	curMemAddress(0) {}

EXPORT intptr_t AssemblyWriter::getLocation() {
	return curMemAddress;
}

EXPORT void AssemblyWriter::setLocation(intptr_t newCurMemAddress) {
	curI = 0;
	startMemAddress = newCurMemAddress;
	curMemAddress = newCurMemAddress;
}

EXPORT void AssemblyWriter::writeBytesToBuffer(int numBytes, ...) {
	va_list args;
	va_start(args, numBytes);
	for (int i = 0; i < numBytes; ++i) {
		unsigned char byte = va_arg(args, unsigned char);
		buffer[curI++] = byte;
		++curMemAddress;
	}
	va_end(args);
}

EXPORT void AssemblyWriter::writeNumberToBuffer(intptr_t pointer, size_t writeSize) {
	for (size_t i = 0; i < writeSize; ++i) {
		buffer[curI++] = pointer & 0xFF;
		++curMemAddress;
		pointer = pointer >> 8;
	}
}

EXPORT void AssemblyWriter::writeRelativeToBuffer32(intptr_t relAddress) {
	intptr_t destOffset = relAddress - (curMemAddress + 4);
	writeNumberToBuffer(destOffset, 4);
}

EXPORT void AssemblyWriter::branchUsingIndirect64(intptr_t destAddress, unsigned char branchOpcode) {

	writeBytesToBuffer(2, 0xEB, 0x8); // JMP
	writeNumberToBuffer(destAddress, 8); // (QWORD)

	writeBytesToBuffer(2, 0xFF, branchOpcode); // CALL/JMP [&QWORD]
	writeRelativeToBuffer32(curMemAddress - 10);
}

EXPORT void AssemblyWriter::writeArgImmediate32(__int32 num, int argI) {

#if defined(_WIN64)
	switch (argI) {
		case 0: writeBytesToBuffer(3, 0x48, 0xC7, 0xC1); break;
		case 1: writeBytesToBuffer(3, 0x48, 0xC7, 0xC2); break;
		case 2: writeBytesToBuffer(3, 0x49, 0xC7, 0xC0); break;
		case 3: writeBytesToBuffer(3, 0x49, 0xC7, 0xC1); break;
		default: MessageBoxFormat(TEXT("InfinityLoader"), MB_ICONERROR, TEXT("(internal error) unhandled argI: %d"), argI); return;
	}
#else
	writeBytesToBuffer(1, 0x68);
#endif

	writeNumberToBuffer(num, 4);
}

EXPORT void AssemblyWriter::jmpToAddressFar(intptr_t address) {
#if defined(_WIN64)
	branchUsingIndirect64(address, 0x25);
#else
	writeBytesToBuffer(1, 0xE9);
	writeRelativeToBuffer32(address);
#endif
}

EXPORT void AssemblyWriter::jmpToAddress(intptr_t address) {
	writeBytesToBuffer(1, 0xE9);
	writeRelativeToBuffer32(address);
}

EXPORT void AssemblyWriter::callToAddressFar(intptr_t address) {
#if defined(_WIN64)
	branchUsingIndirect64(address, 0x15);
#else
	writeBytesToBuffer(1, 0xE8);
	writeRelativeToBuffer32(address);
#endif
}

EXPORT void AssemblyWriter::callToAddress(intptr_t address) {
	writeBytesToBuffer(1, 0xE8);
	writeRelativeToBuffer32(address);
}

EXPORT void AssemblyWriter::alignStackAndMakeShadowSpace() {
#if defined(_WIN64)
	// push rsp
	// and rsp, 0xFFFFFFFFFFFFFFF0
	// sub rsp, 0x20
	writeBytesToBuffer(9, 0x54, 0x48, 0x83, 0xE4, 0xF0, 0x48, 0x83, 0xEC, 0x20);
#endif
}

EXPORT void AssemblyWriter::undoAlignAndShadowSpace() {
#if defined(_WIN64)
	writeBytesToBuffer(5, 0x48, 0x83, 0xC4, 0x20, 0x5C);
#endif
}

EXPORT void AssemblyWriter::pushVolatileRegisters() {
#if defined(_WIN64)
	writeBytesToBuffer(11, 0x50, 0x51, 0x52, 0x41, 0x50, 0x41, 0x51, 0x41, 0x52, 0x41, 0x53);
#else
	writeBytesToBuffer(3, 0x50, 0x52, 0x51);
#endif
}

EXPORT void AssemblyWriter::popVolatileRegisters() {
#if defined(_WIN64)
	writeBytesToBuffer(11, 0x41, 0x5B, 0x41, 0x5A, 0x41, 0x59, 0x41, 0x58, 0x5A, 0x59, 0x58);
#else
	writeBytesToBuffer(3, 0x59, 0x5A, 0x58);
#endif
}

EXPORT void AssemblyWriter::printBuffer() {
	Print("[!] Debug dump of AssemblyWriter located at %p: ", reinterpret_cast<void*>(startMemAddress));
	for (size_t i = 0; i < curI; ++i) {
		Print("%02X ", buffer[i]);
	}
	Print("\n");
}

EXPORT void AssemblyWriter::flush() {
	memcpy_s(reinterpret_cast<void*>(startMemAddress), curI, buffer, curI);
	curI = 0;
}
