#include <Windows.h>
#include "Configuration.hpp"
#include <iostream>


INT wmain(INT argc, PWCHAR argv[])
{
	try
	{
		Configuration::getInstance().parseArguments(argc, argv);
	}
	catch (Exceptions::ConfigurationExceptions::ArgumentsParseException)
	{
		Configuration::printUsage();
	}

	std::wcout << Configuration::getInstance().getTargetComputer();


	return 0;
}