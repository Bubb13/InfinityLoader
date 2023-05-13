
#include "assembly_writer.h"
#include "infinity_loader_common.h"

///////////////////////
// AssemblyWriterImp //
///////////////////////

AssemblyWriterImp::AssemblyWriterImp() :
	bufferSize(1024),
	buffer(new unsigned char[bufferSize]),
	curI(0), startMemAddress(0), curMemAddress(0) {}

AssemblyWriterImp::~AssemblyWriterImp() {
	delete[] buffer;
}

////////////////////
// AssemblyWriter //
////////////////////

EXPORT AssemblyWriter::AssemblyWriter() {
	imp = new AssemblyWriterImp{};
}

EXPORT AssemblyWriter::~AssemblyWriter() {
	delete imp;
}

EXPORT const unsigned char* AssemblyWriter::GetBuffer() {
	return imp->buffer;
}

EXPORT uintptr_t AssemblyWriter::GetCurrentLocation() {
	return imp->curMemAddress;
}

EXPORT uintptr_t AssemblyWriter::GetStartingLocation() {
	return imp->startMemAddress;
}

EXPORT size_t AssemblyWriter::GetSize() {
	return imp->curI;
}

EXPORT void AssemblyWriter::AlignStackAndMakeShadowSpace() {
#if defined(_WIN64)
	// push rsp
	// and rsp, 0xFFFFFFFFFFFFFFF0
	// sub rsp, 0x20
	WriteBytesToBuffer(9, 0x54, 0x48, 0x83, 0xE4, 0xF0, 0x48, 0x83, 0xEC, 0x20);
#endif
}

void AssemblyWriter::branchUsingIndirect64(uintptr_t destAddress, unsigned char branchOpcode) {

	WriteBytesToBuffer(2, 0xEB, 0x8); // JMP
	WriteNumberToBuffer(destAddress, 8); // (QWORD)

	WriteBytesToBuffer(2, 0xFF, branchOpcode); // CALL/JMP [&QWORD]
	WriteRelativeToBuffer32(imp->curMemAddress - 10);
}

EXPORT void AssemblyWriter::CallToAddress(uintptr_t address) {
	WriteBytesToBuffer(1, 0xE8);
	WriteRelativeToBuffer32(address);
}

EXPORT void AssemblyWriter::CallToAddressFar(uintptr_t address) {
#if defined(_WIN64)
	branchUsingIndirect64(address, 0x15);
#else
	WriteBytesToBuffer(1, 0xE8);
	WriteRelativeToBuffer32(address);
#endif
}

EXPORT void AssemblyWriter::Flush() {
	memcpy_s(reinterpret_cast<void*>(imp->startMemAddress), imp->curI, imp->buffer, imp->curI);
	imp->startMemAddress = imp->curMemAddress;
	imp->curI = 0;
}

EXPORT void AssemblyWriter::JmpToAddress(uintptr_t address) {
	WriteBytesToBuffer(1, 0xE9);
	WriteRelativeToBuffer32(address);
}

EXPORT void AssemblyWriter::JmpToAddressFar(uintptr_t address) {
#if defined(_WIN64)
	branchUsingIndirect64(address, 0x25);
#else
	WriteBytesToBuffer(1, 0xE9);
	WriteRelativeToBuffer32(address);
#endif
}

EXPORT void AssemblyWriter::PopVolatileRegisters() {
#if defined(_WIN64)
	WriteBytesToBuffer(11, 0x41, 0x5B, 0x41, 0x5A, 0x41, 0x59, 0x41, 0x58, 0x5A, 0x59, 0x58);
#else
	WriteBytesToBuffer(3, 0x59, 0x5A, 0x58);
#endif
}

EXPORT void AssemblyWriter::PrintBuffer() {
	Print("[!] Debug dump of AssemblyWriter located at %p: ", reinterpret_cast<void*>(imp->startMemAddress));
	for (size_t i = 0; i < imp->curI; ++i) {
		Print("%02X ", imp->buffer[i]);
	}
	Print("\n");
}

EXPORT void AssemblyWriter::PushVolatileRegisters() {
#if defined(_WIN64)
	WriteBytesToBuffer(11, 0x50, 0x51, 0x52, 0x41, 0x50, 0x41, 0x51, 0x41, 0x52, 0x41, 0x53);
#else
	WriteBytesToBuffer(3, 0x50, 0x52, 0x51);
#endif
}

EXPORT void AssemblyWriter::SetLocation(uintptr_t newCurMemAddress) {
	imp->curI = 0;
	imp->startMemAddress = newCurMemAddress;
	imp->curMemAddress = newCurMemAddress;
}

EXPORT void AssemblyWriter::UndoAlignAndShadowSpace() {
#if defined(_WIN64)
	WriteBytesToBuffer(5, 0x48, 0x83, 0xC4, 0x20, 0x5C);
#endif
}

EXPORT void AssemblyWriter::WriteArgImmediate32(size_t argI, __int32 num) {

#if defined(_WIN64)
	switch (argI) {
		case 0: WriteBytesToBuffer(3, 0x48, 0xC7, 0xC1); break;
		case 1: WriteBytesToBuffer(3, 0x48, 0xC7, 0xC2); break;
		case 2: WriteBytesToBuffer(3, 0x49, 0xC7, 0xC0); break;
		case 3: WriteBytesToBuffer(3, 0x49, 0xC7, 0xC1); break;
		default: MessageBoxFormat(TEXT("InfinityLoader"), MB_ICONERROR, TEXT("(internal error) unhandled argI: %d"), argI); return;
	}
#else
	WriteBytesToBuffer(1, 0x68);
#endif

	WriteNumberToBuffer(num, 4);
}

EXPORT void AssemblyWriter::WriteBytesToBuffer(size_t numBytes, ...) {
	va_list args;
	va_start(args, numBytes);
	for (size_t i = 0; i < numBytes; ++i) {
		unsigned char byte = va_arg(args, unsigned char);
		imp->buffer[imp->curI++] = byte;
		++imp->curMemAddress;
	}
	va_end(args);
}

EXPORT void AssemblyWriter::WriteNumberToBuffer(uintptr_t pointer, size_t writeSize) {
	for (size_t i = 0; i < writeSize; ++i) {
		imp->buffer[imp->curI++] = pointer & 0xFF;
		++imp->curMemAddress;
		pointer = pointer >> 8;
	}
}

EXPORT void AssemblyWriter::WriteRelativeToBuffer32(uintptr_t relAddress) {
	uintptr_t destOffset = relAddress - (imp->curMemAddress + 4);
	WriteNumberToBuffer(destOffset, 4);
}
