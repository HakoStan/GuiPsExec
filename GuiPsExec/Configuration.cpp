#include "Configuration.hpp"


Configuration& Configuration::getInstance()
{
	static Configuration instance;
	return instance;
}

VOID Configuration::printUsage()
{
	DWORD charCount;
	WCHAR computerName[MAX_COMPUTERNAME_LENGTH + 1] = { DEFAULT_COMPUTER_NAME };

	GetComputerNameW(computerName, &charCount);

	std::wcout << "USAGE: GuiPsExec.exe \\\\<hostname>" << std::endl;
	std::wcout << "Example: GuiPsExec.exe \\\\" << computerName;
}

std::wstring Configuration::getTargetComputer()
{
	return this->m_targetComputer;
}

VOID Configuration::setTargetComputer(std::wstring& targetComputer)
{
	this->m_targetComputer = targetComputer;
}

VOID Configuration::parseArguments(INT numOfArgs, PWCHAR args[])
{
	if (2 != numOfArgs)
	{
		throw Exceptions::ConfigurationExceptions::ArgumentsParseException();
	}

	this->m_targetComputer = args[1];
}

Configuration::Configuration() {};