#include "pch.h"
#include "RxEnvironment.h"
#include "Registry.hpp"

void showPythonNotFound(MSIHANDLE hInstall)
{
	auto hRecord = MsiCreateRecord(1);
	MsiRecordSetString(hRecord, 0, L"Python not found!\n PyRx extension might not load correctly");
	MsiProcessMessage(hInstall, INSTALLMESSAGE_ERROR, hRecord);
	MsiCloseHandle(hRecord);
}

void showWxPythonNotFound(MSIHANDLE hInstall)
{
	auto hRecord = MsiCreateRecord(1);
	MsiRecordSetString(hRecord, 0, L"wxPython not found!\n PyRx extension might not load correctly");
	MsiProcessMessage(hInstall, INSTALLMESSAGE_ERROR, hRecord);
	MsiCloseHandle(hRecord);
}


RxEnvironment::RxEnvironment(std::filesystem::path _modulePath, MSIHANDLE _hInstall)
	: modulePath(_modulePath), hInstall(_hInstall)

{
}

std::wstring RxEnvironment::findPythonPath()
{
	std::wstring res;
	std::wstring path = win32::RegGetString(HKEY_CURRENT_USER, L"Environment", L"PATH");
	std::vector<std::wstring> elems;
	split(path,';', elems);
	for (auto& item : elems)
	{
		if (item.ends_with(L"python310\\") || item.ends_with(L"python310/") || item.ends_with(L"python310"))
			res = item;
		else if(item.ends_with(L"Python310\\") || item.ends_with(L"Python310/") || item.ends_with(L"Python310"))
			res = item;
	}
	return res;
}

std::wstring RxEnvironment::findWxPythonPath()
{
	std::wstring res;
	std::wstring path = win32::RegGetString(HKEY_CURRENT_USER, L"Environment", L"PATH");
	std::vector<std::wstring> elems;
	split(path, ';', elems);
	for (auto& item : elems)
	{
		if (item.find(L"site-packages") != std::string::npos)
		{
			if (item.ends_with(L"wx\\") || item.ends_with(L"wx/") || item.ends_with(L"wx"))
				res = item;
		}
	}
	return res;
}

std::wstring RxEnvironment::findStubPath()
{
	std::wstring res;
	std::wstring path = win32::RegGetString(HKEY_CURRENT_USER, L"Environment", L"PYTHONPATH");
	std::vector<std::wstring> elems;
	split(path, ';', elems);
	for (auto& item : elems)
	{
		if (item.ends_with(L"PyRxStubs\\") || item.ends_with(L"PyRxStubs/") || item.ends_with(L"PyRxStubs"))
			res = item;
	}
	return res;
}

bool RxEnvironment::install()
{
#ifdef MYDEBUGMODE
	MessageBox(NULL, L"install", L"OK", MB_OK);
#endif
	
	auto pyRegPath = findPythonPath();
	if (pyRegPath.size() == 0)
	{
		showPythonNotFound(hInstall);
		return true;
	}

	std::filesystem::path wxLibPath = pyRegPath;
	wxLibPath /= L"Lib\\site-packages\\wx";

	std::error_code _Ec;
	if (!std::filesystem::exists(wxLibPath, _Ec))
	{
		showWxPythonNotFound(hInstall);
		return true;
	}

	auto wxRegPath = findWxPythonPath();
	if (wxRegPath.size() == 0)
	{
		//append to PATH
	}

	auto regStubPath = findStubPath();
	if (wxRegPath.size() == 0)
	{
		//append to PYTHONPATH
	}

	return true;
}

bool RxEnvironment::uninstall()
{
#ifdef MYDEBUGMODE
	MessageBox(NULL, L"uninstall", L"OK", MB_OK);
#endif
	return true;
}

RxEnvironment& RxEnvironment::instance(std::filesystem::path modulePath, MSIHANDLE hInstall)
{
	static RxEnvironment mthis(modulePath, hInstall);
	return mthis;
}
