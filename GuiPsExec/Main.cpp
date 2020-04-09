#include <Windows.h>
#include <iostream>
#include "Configuration.hpp"
#include "Common.hpp"
#include "ServiceInstaller.h"


INT wmain(INT argc, PWCHAR argv[])
{
	try
	{
		Configuration::getInstance().parseArguments(argc, argv);
	}
	catch (Exceptions::ConfigurationExceptions::ArgumentsParseException)
	{
		Configuration::printUsage();
		return ERROR_ARGUMENTS_PARSE;
	}
	DEBUG_PRINT(Configuration::getInstance().getTargetComputer());

	std::wstring targetComputer = Configuration::getInstance().getTargetComputer();

	Errors_e returnCode = ServiceInstaller::getInstance().RunInstallProcedure(targetComputer);
	if (GUIPSEXEC_FAILED(returnCode))
	{
		return returnCode;
	}

	return GUIPSEXEC_SUCCESS;
}