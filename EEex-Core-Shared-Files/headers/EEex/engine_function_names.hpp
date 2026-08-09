
#pragma once

#include <string>

///////////////
// Functions //
///////////////

const std::string& getContainingFunctionName(uintptr_t address);
const std::string& getFunctionName(uintptr_t address);
void initFunctionNames();
