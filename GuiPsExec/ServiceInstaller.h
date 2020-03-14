#pragma once

#include <Windows.h>
#include <string>
#include "Common.hpp"
#include "WinFramework/FileApi/FileApi.h"

class ServiceInstaller
{
public:
	static ServiceInstaller & getInstance();

	ServiceInstaller(const ServiceInstaller&) = delete;
	ServiceInstaller& operator=(const ServiceInstaller&) = delete;

	Errors_e RunInstallProcedure(std::wstring& targetComputer);
private:
	ServiceInstaller();
	Errors_e CopyServiceExecutable(std::wstring& targetComputer);
};