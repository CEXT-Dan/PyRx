#include "pch.h"
#include "RxEnvironment.h"
#include "Registry.hpp"


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
	MessageBox(NULL, L"install", L"OK", MB_OK);
	auto pyPath = findPythonPath();
	if (pyPath.size() == 0)
	{
		MessageBoxA(NULL, "FAIL @ findPythonPath", "FAIL", MB_OK);
		return false;
	}
	else
	{
		MessageBoxA(NULL, "YAY", "YAY", MB_OK);
	}
	return true;
}

bool RxEnvironment::uninstall()
{
	MessageBox(NULL, L"uninstall", L"OK", MB_OK);
	return true;
}

RxEnvironment& RxEnvironment::instance(std::filesystem::path modulePath, MSIHANDLE hInstall)
{
	static RxEnvironment mthis(modulePath, hInstall);
	return mthis;
}
