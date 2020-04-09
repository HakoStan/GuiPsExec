#include "ServiceApi.hpp"
#include "Exceptions\GeneralWin32Exceptions.hpp"

SC_HANDLE WinFramework::ServiceApi::OpenSCMManagerW(std::wstring& machineName, std::wstring& database, DWORD desiredAccess)
{
	SC_HANDLE handle = ::OpenSCManagerW(machineName.c_str(), database.c_str(), desiredAccess);

	if (NULL == handle)
	{
		throw WinFramework::GeneralWin32Exceptions::UnkownWin32Exception();
	}

	return handle;
}

SC_HANDLE WinFramework::ServiceApi::CreateServiceW(SC_HANDLE scmHandle, std::wstring& serviceName, std::wstring& displayName, DWORD desiredAccess, DWORD serviceType, DWORD startType, DWORD errorControl, std::wstring& binaryPathName, std::wstring& loadOrderGroup, LPDWORD tagId, std::wstring& dependencies, std::wstring& serviceStartName, std::wstring& password)
{
	SC_HANDLE handle = ::CreateServiceW(scmHandle,
		serviceName.c_str(),
		displayName.c_str(),
		desiredAccess,
		serviceType,
		startType,
		errorControl,
		binaryPathName.c_str(),
		loadOrderGroup.c_str(),
		tagId,
		dependencies.c_str(),
		serviceStartName.c_str(),
		password.c_str());

	if (NULL == handle)
	{
		throw WinFramework::GeneralWin32Exceptions::UnkownWin32Exception();
	}

	return handle;
}

VOID WinFramework::ServiceApi::StartServiceW(SC_HANDLE serviceHandle, std::vector<std::wstring> serviceArgs)
{
	PWCHAR * serviceArgsStr = nullptr;
	if (0 != serviceArgs.size())
	{
		std::size_t totalSize = GetStringsTotalSizeInVector(serviceArgs);
		serviceArgsStr = static_cast<PWCHAR *>(::HeapAlloc(::GetProcessHeap(), HEAP_ZERO_MEMORY | HEAP_GENERATE_EXCEPTIONS, totalSize));
		CopyStringsFromVectorToMemoryArray(serviceArgs, serviceArgsStr);
	}

	BOOL res = ::StartServiceW(serviceHandle,
		serviceArgs.size(),
		serviceArgsStr);

	if (FALSE == res)
	{
		throw WinFramework::GeneralWin32Exceptions::UnkownWin32Exception();
	}
}


std::size_t GetStringsTotalSizeInVector(std::vector<std::wstring>& strVector)
{
	std::size_t totalSize = 0;
	for (std::wstring str : strVector)
	{
		totalSize += str.size();
	}

	return totalSize;
}


VOID CopyStringsFromVectorToMemoryArray(std::vector<std::wstring> strVector, PWCHAR * strArray)
{
	UINT32 i = 0;
	for (std::wstring str : strVector)
	{
		strArray[i] = static_cast<PWCHAR>(::HeapAlloc(::GetProcessHeap(), HEAP_ZERO_MEMORY | HEAP_GENERATE_EXCEPTIONS, str.size()));
		::CopyMemory(strArray[i], str.data(), str.size());
		i++;
	}
}
