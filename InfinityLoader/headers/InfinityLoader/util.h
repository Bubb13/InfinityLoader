
#pragma once

#include <functional>

#include "infinity_loader_common_types.h"

enum class TryFillBufferResult {
    GROW,
    DONE,
    ABORT,
};

template<typename BufferType>
void RunWithGrowingBuffer(
    const std::function<TryFillBufferResult(BufferType*, size_t)> tryFillBuffer,
    const std::function<size_t(size_t)> growSizeCompute,
    const std::function<void(BufferType*, size_t)> useBuffer)
{
    // Try to use a stack buffer at first
    const size_t initialBufferSize = 1024;
    BufferType stackBuffer[initialBufferSize];

    // If the stack buffer is too small allocate one on the heap
    BufferType* curBuffer = stackBuffer;
    size_t curBufferSize = initialBufferSize;

    if (const TryFillBufferResult result = tryFillBuffer(curBuffer, curBufferSize); result == TryFillBufferResult::DONE) {
        useBuffer(curBuffer, curBufferSize);
        return;
    }
    else if (result == TryFillBufferResult::ABORT) {
        return;
    }
    else if (result != TryFillBufferResult::GROW) {
        Print("[!][InfinityLoader.exe] RunWithGrowingBuffer() - Bad TryFillBufferResult (%d)\n", result);
        return;
    }

    // Stack buffer too small
    curBufferSize = growSizeCompute(curBufferSize);
    curBuffer = new BufferType[curBufferSize];

    while (true) {

        // Try again with the larger buffer
        if (const TryFillBufferResult result = tryFillBuffer(curBuffer, curBufferSize); result == TryFillBufferResult::DONE) {
            useBuffer(curBuffer, curBufferSize);
            delete[] curBuffer;
            return;
        }
        else if (result == TryFillBufferResult::ABORT) {
            return;
        }
        else if (result != TryFillBufferResult::GROW) {
            Print("[!][InfinityLoader.exe] RunWithGrowingBuffer() - Bad TryFillBufferResult (%d)\n", result);
            return;
        }

        // Still too small
        delete[] curBuffer;
        curBufferSize = growSizeCompute(curBufferSize);
        curBuffer = new BufferType[curBufferSize];
    }
}

size_t GrowDouble(size_t size);

template<typename BufferType>
void RunWithGrowingBuffer(
    const std::function<TryFillBufferResult(BufferType*, size_t)> tryFillBuffer,
    const std::function<void(BufferType*, size_t)> useBuffer)
{
    RunWithGrowingBuffer(tryFillBuffer, GrowDouble, useBuffer);
}
