
#include <array>
#include <filesystem>
#include <string>

#include <ShlObj_core.h> // Has to be before `infinity_loader_common_api.h` because its Print() macro conflicts

#include "infinity_loader_common_api.h"

#include <tchar.h>

#include "unzip.h"

//---------------------------//
//          Globals          //
//---------------------------//

String sScriptFolder;

//------------------------------------//
//          Static Functions          //
//------------------------------------//

static DWORD getWriteableDirectory(String& out)
{
	TCHAR buffer[MAX_PATH];

	// `SHGetKnownFolderPath()` is better, but engine uses `SHGetFolderPath()`
	if (SHGetFolderPath(NULL, CSIDL_MYDOCUMENTS, NULL, 0, buffer) != S_OK)
	{
		const DWORD lastError = GetLastError();
		FPrint("[!][InfinityLoaderDLL.dll] getWriteableDirectory() - SHGetFolderPathW() failed (%d)\n", lastError);
		return lastError;
	}

	out = buffer;
	return ERROR_SUCCESS;
}

#ifndef UNICODE
#define pathString() string()
#else
#define pathString() wstring()
#endif

static void iterateMatchingFilesInFolder(const String& sPath, std::function<void(const String& path)> itr)
{
	// Note: This is a fake glob. The file name before the extension is ignored.
	const std::filesystem::path path { sPath };
	const std::filesystem::path parentPath = path.parent_path();
	const std::filesystem::path extensionPath = path.extension();

	try
	{
		for (const auto& entry : std::filesystem::directory_iterator(parentPath))
		{
			if (entry.is_regular_file() && entry.path().extension() == extensionPath)
			{
				itr(entry.path().pathString());
			}
		}
	}
	catch (const std::filesystem::filesystem_error& error)
	{
		if (error.code() != std::errc::no_such_file_or_directory)
		{
			FPrintT(TEXT("[!][InfinityLoaderDLL.dll] iterateMatchingFilesInFolder() - Failed to iterate \"%s\": %s\n"),
				sPath.c_str(), NulTermStrToStr(error.code().message().c_str()).c_str());
		}
	}
}

#undef pathString

static voidpf ZCALLBACK wchar_zopen_file(voidpf opaque, const char* filename, int mode)
{
	const wchar_t* path = reinterpret_cast<const wchar_t*>(filename);
	const wchar_t* modeStr = nullptr;

	if ((mode & ZLIB_FILEFUNC_MODE_READWRITEFILTER) == ZLIB_FILEFUNC_MODE_READ)
	{
		modeStr = L"rb";
	}
	else if (mode & ZLIB_FILEFUNC_MODE_EXISTING)
	{
		modeStr = L"r+b";
	}
	else if (mode & ZLIB_FILEFUNC_MODE_CREATE)
	{
		modeStr = L"wb";
	}
	else
	{
		return nullptr;
	}

	return _wfopen(path, modeStr);
}

static unzFile openZip(const TCHAR* sFilePath)
{
	zlib_filefunc_def_s ffunc;
	fill_fopen_filefunc(&ffunc);

#ifdef UNICODE
	ffunc.zopen_file = wchar_zopen_file;
#endif

	return unzOpen2(reinterpret_cast<const char*>(sFilePath), &ffunc);
}

static bool iterateFilesInZip(unzFile zipFile, std::function<void(char*, unz_file_info&)> zipFileNameCallback)
{
	if (zipFile == nullptr)
	{
		return false;
	}

	if (const int error = unzGoToFirstFile(zipFile); error != UNZ_OK)
	{
		FPrint("[!][InfinityLoaderDLL.dll] iterateFilesInZip() - unzGoToFirstFile() failed (%d)\n", error);
		unzClose(zipFile);
		return false;
	}

	while (true)
	{
		char filename[256]; // Engine limit
		unz_file_info fileInfo;

		if (const int error = unzGetCurrentFileInfo(zipFile, &fileInfo, filename, sizeof(filename), nullptr, 0, nullptr, 0); error != UNZ_OK)
		{
			FPrint("[!][InfinityLoaderDLL.dll] iterateFilesInZip() - unzGetCurrentFileInfo() failed (%d)\n", error);
			continue;
		}

		zipFileNameCallback(filename, fileInfo);

		switch (const int error = unzGoToNextFile(zipFile))
		{
			case UNZ_OK: break;
			default: FPrint("[!][InfinityLoaderDLL.dll] iterateFilesInZip() - unzGoToNextFile() failed (%d)\n", error); [[fallthrough]];
			case UNZ_END_OF_LIST_OF_FILE: goto breakOuter;
		}
	}

breakOuter:;
	unzClose(zipFile);
	return true;
}

static DWORD unzipCurrentFile(unzFile zipFile, const TCHAR* sDestPath)
{
	if (const int openResult = unzOpenCurrentFile(zipFile); openResult != UNZ_OK)
	{
		FPrint("[!][InfinityLoaderDLL.dll] unzipCurrentFile() - unzOpenCurrentFile() failed (%d)\n", openResult);
		return -1;
	}

	const HANDLE outputFile = CreateFile(sDestPath, GENERIC_WRITE, 0, nullptr, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);

	if (outputFile == INVALID_HANDLE_VALUE)
	{
		const DWORD lastError = GetLastError();
		FPrint("[!][InfinityLoaderDLL.dll] unzipCurrentFile() - CreateFile() failed (%d)\n", lastError);

		unzCloseCurrentFile(zipFile);
		return lastError;
	}

	constexpr int bufferSize = 8192;
	char buffer[bufferSize];

	DWORD toReturn = ERROR_SUCCESS;

	while (true)
	{
		const int bytesRead = unzReadCurrentFile(zipFile, buffer, bufferSize);

		if (bytesRead == 0)
		{
			break;
		}
		else if (bytesRead < 0)
		{
			FPrint("[!][InfinityLoaderDLL.dll] unzipCurrentFile() - unzReadCurrentFile() failed (%d)\n", bytesRead);
			toReturn = -1;
			break;
		}

		DWORD bytesWritten;
		if (!WriteFile(outputFile, buffer, bytesRead, &bytesWritten, nullptr))
		{
			toReturn = GetLastError();
			FPrint("[!][InfinityLoaderDLL.dll] unzipCurrentFile() - WriteFile() failed (%d)\n", toReturn);
			break;
		}
	}

	unzCloseCurrentFile(zipFile);
	CloseHandle(outputFile);
	return ERROR_SUCCESS;
}

static bool startsWithDirectory(const TCHAR* str, const TCHAR* text, const TCHAR*& out)
{
	for (const TCHAR* curStr = str; ; ++curStr, ++text)
	{
		const TCHAR textChar = *text;

		if (textChar == TCHAR{'\0'})
		{
			if (*curStr == TCHAR{'/'} && *(curStr + 1) != TCHAR{'\0'})
			{
				out = curStr + 1;
				return true;
			}

			return false;
		}

		if (*curStr != textChar)
		{
			return false;
		}
	}
}

static void checkFolderForZips(const String& sSearchFolderPath, const String& sScriptFolderRoot)
{
	iterateMatchingFilesInFolder(sSearchFolderPath, [&](const String& sZipFilePath)
	{
		const unzFile zipFile = openZip(sZipFilePath.c_str());

		iterateFilesInZip(zipFile, [&](const char* sZippedFileNamePath, unz_file_info& fileInfo)
		{
			const String sZippedFileNamePathT = NulTermStrToStr(sZippedFileNamePath);
			const TCHAR* sZippedFileNamePathTAfterDir;

			// Only unzip files in the script folder directly under the zip root, e.g. `EEex_scripts/EEex_Main.lua`
			if (!startsWithDirectory(sZippedFileNamePathT.c_str(), sScriptFolder.c_str(), sZippedFileNamePathTAfterDir))
			{
				return;
			}

			// Ignore files in subdirectories under the script folder
			if (_tcschr(sZippedFileNamePathTAfterDir, '/') != nullptr)
			{
				return;
			}

			const String sUnzipDest = String{ sScriptFolderRoot }.append(sZippedFileNamePathTAfterDir);

			if (unzipCurrentFile(zipFile, sUnzipDest.c_str()) == ERROR_SUCCESS)
			{
				FPrintT(TEXT("[?][InfinityLoaderDLL.dll] checkFolderForZips() - \"%s\" sourced \"%s\"\n"), sZipFilePath.c_str(), sZippedFileNamePathTAfterDir);
			}
			else
			{
				FPrintT(TEXT("[!][InfinityLoaderDLL.dll] checkFolderForZips() - \"%s\" failed to source \"%s\"\n"), sZipFilePath.c_str(), sUnzipDest.c_str());
			}
		});
	});
}

static bool createDirectory(const TCHAR *const sPath)
{
	try
	{
		std::filesystem::create_directory(sPath);
		return true;
	}
	catch (const std::filesystem::filesystem_error& error)
	{
		FPrintT(TEXT("[!][InfinityLoaderDLL.dll] createDirectory() - Failed to create \"%s\": %s\n"), sPath, NulTermStrToStr(error.code().message().c_str()).c_str());
		return false;
	}
}

static bool createDirectory(const String& sPath)
{
	return createDirectory(sPath.c_str());
}

//-----------------------------//
//          Functions          //
//-----------------------------//

const String& getScriptFolder()
{
	return sScriptFolder;
}

DWORD prepareExtenderScripts(const String* sEngineName)
{
	bool hasScriptFolder;
	TryRetErr( GetINIStr(iniPath(), TEXT("General"), TEXT("ScriptFolder"), sScriptFolder, hasScriptFolder) );

	if (!hasScriptFolder)
	{
		Print("[!][InfinityLoaderDLL.dll] prepareExtenderScripts() - [General].ScriptFolder must be defined\n");
		return -1;
	}

	const String scriptFolderPath = String{ workingFolder() }.append(sScriptFolder).append(TEXT("\\"));
	const String scriptFolderOverridePath = String{ scriptFolderPath }.append(TEXT("override\\"));

	TryRetDefErrCode( createDirectory(scriptFolderPath) );
	TryRetDefErrCode( createDirectory(scriptFolderOverridePath) );

	if (sEngineName != nullptr)
	{
		String writeableDirectory{};

		if (getWriteableDirectory(writeableDirectory) == ERROR_SUCCESS)
		{
			const String writableDirectoryZips = String{ writeableDirectory }.append(TEXT("\\")).append(*sEngineName).append(TEXT("\\*.zip"));
			checkFolderForZips(writableDirectoryZips, scriptFolderOverridePath);
		}

		checkFolderForZips(workingFolder() + TEXT("*.zip"), scriptFolderOverridePath);
		checkFolderForZips(workingFolder() + TEXT("dlc\\*.zip"), scriptFolderOverridePath);
		checkFolderForZips(workingFolder() + TEXT("workshop\\*.mod"), scriptFolderOverridePath);
	}

	return ERROR_SUCCESS;
}
