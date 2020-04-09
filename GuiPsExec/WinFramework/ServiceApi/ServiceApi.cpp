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
