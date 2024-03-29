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

void showFailedToWrite(MSIHANDLE hInstall)
{
	auto hRecord = MsiCreateRecord(1);
	MsiRecordSetString(hRecord, 0, L"Failed to write value to registry!");
	MsiProcessMessage(hInstall, INSTALLMESSAGE_ERROR, hRecord);
	MsiCloseHandle(hRecord);
}

void showFailMessage(MSIHANDLE hInstall, const std::wstring& msg)
{
	auto hRecord = MsiCreateRecord(1);
	MsiRecordSetString(hRecord, 0, msg.c_str());
	MsiProcessMessage(hInstall, INSTALLMESSAGE_ERROR, hRecord);
	MsiCloseHandle(hRecord);
}

void showSuccessMessage(MSIHANDLE hInstall)
{
	auto hRecord = MsiCreateRecord(1);
	MsiRecordSetString(hRecord, 0, L"Install success!");
	MsiProcessMessage(hInstall, INSTALLMESSAGE_USER, hRecord);
	MsiCloseHandle(hRecord);
}

RxEnvironment::RxEnvironment(std::filesystem::path _modulePath, MSIHANDLE _hInstall)
	: modulePath(_modulePath), hInstall(_hInstall)
{
}

std::wstring RxEnvironment::findPythonPathPath()
{
	std::wstring res;
	try
	{
		if (auto result = win32::RegGetString(HKEY_CURRENT_USER, L"Environment", L"PYTHONPATH"); result.first == ERROR_SUCCESS)
			return result.second;
	}
	catch (...)
	{
		showFailMessage(hInstall, L"exception in findPythonPathPath! ");
	}
	return res;
}

std::wstring RxEnvironment::findPythonPath()
{
	std::wstring res;
	try
	{
		if (auto result = win32::RegGetString(HKEY_CURRENT_USER, L"Environment", L"PATH"); result.first == ERROR_SUCCESS)
		{
			if (result.second.size() == 0)
				return res;
			std::vector<std::wstring> elems;
			split(result.second, ';', elems);
			for (auto& item : elems)
			{
				//CASE idiot
				if (item.ends_with(L"Python312\\") || item.ends_with(L"Python312/") || item.ends_with(L"Python312"))
					res = item;
				else if (item.ends_with(L"python312\\") || item.ends_with(L"python312/") || item.ends_with(L"python312"))
					res = item;
			}
		}
	}
	catch (...)
	{
		showFailMessage(hInstall, L"exception in findPythonPath! ");
	}
	return res;
}

std::wstring RxEnvironment::findWxPythonPath()
{
	std::wstring res;
	try
	{
		if (auto result = win32::RegGetString(HKEY_CURRENT_USER, L"Environment", L"PATH"); result.first == ERROR_SUCCESS)
		{
			if (result.second.size() == 0)
				return res;
			std::vector<std::wstring> elems;
			split(result.second, ';', elems);
			for (auto& item : elems)
			{
				if (item.find(L"site-packages") != std::string::npos)
				{
					if (item.ends_with(L"wx\\") || item.ends_with(L"wx/") || item.ends_with(L"wx"))
						res = item;
				}
			}
		}
	}
	catch (...)
	{
		showFailMessage(hInstall, L"exception in findWxPythonPath! ");
	}
	return res;
}

std::wstring RxEnvironment::findStubPath()
{
	std::wstring res;
	try
	{
		if (auto result = win32::RegGetString(HKEY_CURRENT_USER, L"Environment", L"PYTHONPATH"); result.first == ERROR_SUCCESS)
		{
			if (result.second.size() == 0)
				return res;
			std::vector<std::wstring> elems;
			split(result.second, ';', elems);
			for (auto& item : elems)
			{
				if (item.ends_with(L"PyRxStubs\\") || item.ends_with(L"PyRxStubs/") || item.ends_with(L"PyRxStubs"))
					res = item;
			}
		}
	}
	catch (...)
	{
		showFailMessage(hInstall, L"exception in findStubPath! ");
	}
	return res;
}

std::wstring RxEnvironment::installDir()
{
	std::wstring res;
	DWORD dwSize = MAX_PATH;
	std::unique_ptr<wchar_t[]> buf(new wchar_t[MAX_PATH]());
	if (auto result = MsiGetProperty(hInstall, TEXT("CustomActionData"), buf.get(), &dwSize); result == ERROR_SUCCESS)
		res = buf.get();
	return res;
}

DWORD RxEnvironment::calcBufferSize(const std::wstring& str)
{
	return ((DWORD)str.size() + 1) * sizeof(wchar_t);
}

void RxEnvironment::appendPath(std::wstring& src, const std::wstring& pathToAppend)
{
	rtrim(src, ';');
	src += L";";
	src += pathToAppend;
	src += L";";
}

void RxEnvironment::flushEnvironment()
{
	if (auto rootKey = win32::RegOpenKey(HKEY_CURRENT_USER, L"Environment"); rootKey.IsValid())
	{
		SendNotifyMessage(HWND_BROADCAST, WM_SETTINGCHANGE, 0, (LPARAM)TEXT("Environment"));
		if (RegFlushKey(rootKey.Get()) != ERROR_SUCCESS)
			showFailMessage(hInstall, L"Failed to flush registry");
	}
	else
	{
		showFailMessage(hInstall, L"Failed to flush registry");
	}
}

bool RxEnvironment::install()
{
	try
	{

#ifdef MYDEBUGMODE//Break here
		MessageBox(NULL, L"PyRxInstallerBreakPoint", L"PyRxInstallerBreakPoint", MB_OK);
#endif
		const auto pyRegPath = findPythonPath();
		if (pyRegPath.size() == 0)
		{
			showPythonNotFound(hInstall);
			return true;
		}
		std::filesystem::path wxLibPath = pyRegPath;
		wxLibPath /= L"Lib\\site-packages\\wx";

		if (std::error_code _Ec; !std::filesystem::exists(wxLibPath, _Ec))
		{
			showWxPythonNotFound(hInstall);
			return true;
		}

		if (const auto wxRegPath = findWxPythonPath(); wxRegPath.size() == 0)
		{
			if (auto result = win32::RegGetString(HKEY_CURRENT_USER, L"Environment", L"PATH"); result.first == ERROR_SUCCESS)
			{
				std::wstring path = result.second;
				appendPath(path, wxLibPath);
				auto key = win32::RegOpenKey(HKEY_CURRENT_USER, L"Environment");
				if (key.IsValid())
				{
					const DWORD sz = calcBufferSize(path);
					if (RegSetValueEx(key.Get(), L"PATH", 0, REG_SZ, (LPBYTE)path.c_str(), sz) != ERROR_SUCCESS)
						showFailedToWrite(hInstall);
				}
			}
		}

		//validate
		if (const auto regStubPath = findStubPath(); regStubPath.size() == 0)
		{
			std::filesystem::path stub = installDir();
			stub /= L"PyRxStubs";

			std::wstring path = findPythonPathPath();
			{
				if (path.size() != 0)
					appendPath(path, stub);
				else
					path = stub.wstring();
			}
			if (auto rootKey = win32::RegOpenKey(HKEY_CURRENT_USER, L"Environment"); rootKey.IsValid())
			{
				const DWORD sz = calcBufferSize(path);
				if (RegSetValueEx(rootKey.Get(), L"PYTHONPATH", 0, REG_SZ, (LPBYTE)path.c_str(), sz) != ERROR_SUCCESS)
					showFailedToWrite(hInstall);
			}
		}
		flushEnvironment();

		if (const auto wxRegPath = findWxPythonPath(); wxRegPath.size() != 0)
			showSuccessMessage(hInstall);
	}
	catch (...)
	{
		showFailMessage(hInstall, L"Install failed with exception! ");
	}
	return true;
}

bool RxEnvironment::uninstall()
{
	return true;
}

RxEnvironment& RxEnvironment::instance(std::filesystem::path modulePath, MSIHANDLE hInstall)
{
	static RxEnvironment mthis(modulePath, hInstall);
	return mthis;
}
