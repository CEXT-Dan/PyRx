#include "pch.h"
#include "RxEnvironment.h"

static HMODULE ghThisModule = NULL;

#define DllExport   __declspec( dllexport ) 

std::filesystem::path getModulePath()
{
	TCHAR modPath[MAX_PATH] = { 0 };
	GetModuleFileName(ghThisModule, modPath, MAX_PATH);
	return std::filesystem::path{ modPath };
}

EXTERN_C DllExport UINT WINAPI RxInstall(MSIHANDLE hInstall)
{
	std::filesystem::path path = getModulePath();
	RxEnvironment& env = RxEnvironment::instance(path, hInstall);
	env.install();
	return ERROR_SUCCESS;
}

EXTERN_C DllExport UINT WINAPI RxUninstall(MSIHANDLE hInstall)
{
	std::filesystem::path path = getModulePath();
	RxEnvironment& env = RxEnvironment::instance(path, hInstall);
	env.uninstall();
	return ERROR_SUCCESS;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  dwReason, LPVOID lpReserved)
{
	if (dwReason == DLL_PROCESS_ATTACH)
	{
		DisableThreadLibraryCalls(hModule);
		ghThisModule = hModule;
	}
	return TRUE;
}