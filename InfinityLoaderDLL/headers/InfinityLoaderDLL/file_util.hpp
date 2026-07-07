
#pragma once

#include "infinity_loader_common_types.h"

//-----------------------------//
//          Functions          //
//-----------------------------//

const String& getScriptFolder();
DWORD initScriptFolder();
void iterateMatchingFilesInFolder(const String& sPath, std::function<void(const String& path)> itr);
DWORD prepareExtenderScripts(const String* sEngineName);
