#pragma once

#include <Windows.h>
#include <string>
#include <vector>

// TODO :: Write UniqueResource

namespace WinFramework
{
namespace ServiceApi
{
	// YA :: TODO :: Add Tests
	// YA :: TODO :: Change to autohandle
	SC_HANDLE OpenSCMManagerW(std::wstring& machineName, std::wstring& database, DWORD desiredAccess);

	SC_HANDLE CreateServiceW(SC_HANDLE scmHandle, std::wstring& serviceName, std::wstring& displayName, DWORD desiredAccess, DWORD serviceType, DWORD startType, DWORD errorControl, std::wstring& binaryPathName, std::wstring& loadOrderGroup, LPDWORD tagId, std::wstring& dependencies, std::wstring& serviceStartName, std::wstring& password);
	
	VOID StartServiceW(SC_HANDLE serviceHandle, std::vector<std::wstring> serviceArgs);
}
}