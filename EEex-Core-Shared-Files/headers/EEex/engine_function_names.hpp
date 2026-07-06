
#pragma once

#include <string>

const std::string& GetContainingFunctionName(uintptr_t address);
const std::string& GetFunctionName(uintptr_t address);
void LoadFunctionNames();
