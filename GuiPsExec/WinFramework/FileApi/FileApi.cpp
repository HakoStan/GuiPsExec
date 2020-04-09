#include "FileApi.hpp"
#include "Exceptions\GeneralWin32Exceptions.hpp"

VOID WinFramework::FileApi::CopyFile(std::wstring& sourceFile, std::wstring& targetFile, BOOL overrideFile)
{
	BOOL bRes = ::CopyFile(sourceFile.c_str(), targetFile.c_str(), !overrideFile);

	if (bRes)
	{
		return;
	}

	if (ERROR_FILE_NOT_FOUND == ::GetLastError())
	{
		throw WinFramework::FileApiExceptions::SourceFileNotFound();
	}

	throw WinFramework::GeneralWin32Exceptions::UnkownWin32Exception();
}
