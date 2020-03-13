#pragma once

#include <Windows.h>
#include <String>
#include <iostream>
#include "ConfigurationException.h"

#define DEFAULT_COMPUTER_NAME L"COMPUTERNAME"

class Configuration
{
public:
	static Configuration & getInstance();
	static VOID printUsage();

	std::wstring getTargetComputer();
	VOID setTargetComputer(std::wstring& targetComputer);

	VOID parseArguments(INT argc, PWCHAR argv[]);

	Configuration(const Configuration&) = delete;
	Configuration& operator=(const Configuration&) = delete;
private:
	Configuration();

	std::wstring m_targetComputer;
};