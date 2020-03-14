#pragma once

#include <Windows.h>
#include <string>
#include "FileApiExceptions.h"

namespace WinFramework
{
namespace FileApi
{
	VOID CopyFile(std::wstring& sourceFile, std::wstring& targetFile, BOOL overrideFile);
}
}