
#include "infinity_loader_common_api.h"

/////////////
// Globals //
/////////////

String sScriptFolder;

///////////////
// Functions //
///////////////

const String& getScriptFolder()
{
	return sScriptFolder;
}

DWORD initScriptFolder()
{
	bool hasScriptFolder;
	TryRetErr( GetINIStr(iniPath(), TEXT("General"), TEXT("ScriptFolder"), sScriptFolder, hasScriptFolder) );

	if (!hasScriptFolder)
	{
		// Should never happen since this is enforced by InfinityLoaderDLL
		Print("[!][EEex.dll] initScriptFolder() - [General].ScriptFolder must be defined\n");
		return -1;
	}

	return ERROR_SUCCESS;
}
