#pragma once

#include <exception>
#include <Windows.h>
#include <string>

namespace WinFramework
{
namespace GeneralWin32Exceptions
{
	class UnkownWin32Exception : public std::exception
	{
		const char * what() const throw ()
		{
			DWORD win32ErrorMessage = ::GetLastError();
			std::string returnMessage = std::string("Win32 Error Code: ") + std::to_string(win32ErrorMessage);
			return returnMessage.c_str();
		}
	};
}
}