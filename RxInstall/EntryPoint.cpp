#include "pch.h"

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
	MessageBox(NULL, L"RxInstall", L"RxInstall", MB_OK);
	std::filesystem::path path = getModulePath();
	return ERROR_SUCCESS;
}

EXTERN_C DllExport UINT WINAPI RxUninstall(MSIHANDLE hInstall)
{
	MessageBox(NULL, L"RxUninstall", L"RxUninstall", MB_OK);
	std::filesystem::path path = getModulePath();
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