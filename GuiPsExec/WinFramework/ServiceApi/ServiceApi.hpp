#pragma once

#include <Windows.h>
#include <string>

// TODO :: Write UniqueResource

namespace WinFramework
{
namespace ServiceApi
{
	// YA :: TODO :: Change to autohandle
	SC_HANDLE OpenSCMManagerW(std::wstring& machineName, std::wstring& database, DWORD desiredAccess);

	// CreateServiceA 
	// StartServices 
}
}