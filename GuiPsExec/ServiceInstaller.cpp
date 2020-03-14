#include "ServiceInstaller.h"


ServiceInstaller& ServiceInstaller::getInstance()
{
	static ServiceInstaller instance;
	return instance;
}

Errors_e ServiceInstaller::RunInstallProcedure(std::wstring& targetComputer)
{
	CopyServiceExecutable(targetComputer);
	return ERROR_GUIPSEXEC_SUCCESS;
}

Errors_e ServiceInstaller::CopyServiceExecutable(std::wstring& targetComputer)
{
	std::wstring sourceFile = { L"C:\\temp\\cmd.exe" };
	std::wstring targetFile = targetComputer + L"\\admin$\\system32\\GuiPsExecSvc.exe";
	
	WinFramework::FileApi::CopyFile(sourceFile, targetComputer, TRUE);

	return ERROR_GUIPSEXEC_SUCCESS;
}

ServiceInstaller::ServiceInstaller() {};

