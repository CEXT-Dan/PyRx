// (C) Copyright 2002-2007 by Autodesk, Inc. 
//
// Permission to use, copy, modify, and distribute this software in
// object code form for any purpose and without fee is hereby granted, 
// provided that the above copyright notice appears in all copies and 
// that both that copyright notice and the limited warranty and
// restricted rights notice below appear in all supporting 
// documentation.
//
// AUTODESK PROVIDES THIS PROGRAM "AS IS" AND WITH ALL FAULTS. 
// AUTODESK SPECIFICALLY DISCLAIMS ANY IMPLIED WARRANTY OF
// MERCHANTABILITY OR FITNESS FOR A PARTICULAR USE.  AUTODESK, INC. 
// DOES NOT WARRANT THAT THE OPERATION OF THE PROGRAM WILL BE
// UNINTERRUPTED OR ERROR FREE.
//
// Use, duplication, or disclosure by the U.S. Government is subject to 
// restrictions set forth in FAR 52.227-19 (Commercial Computer
// Software - Restricted Rights) and DFAR 252.227-7013(c)(1)(ii)
// (Rights in Technical Data and Computer Software), as applicable.
//

//-----------------------------------------------------------------------------
//----- acrxEntryPoint.cpp
//-----------------------------------------------------------------------------
#include "StdAfx.h"
#include "resource.h"

//-----------------------------------------------------------------------------
#define szRDS _RXST("")

constexpr const wchar_t* PATHENV = _T("PATH");
constexpr const wchar_t* PYTHONNAME = _T("python312");
constexpr const wchar_t* PYRXSETTINGS = _T("PYRXSETTINGS");
constexpr const wchar_t* WXPYTHONPATH = _T("WXPYTHONPATH");
constexpr const wchar_t* PYTHONINSTALLEDPATH = _T("PYTHONINSTALLEDPATH");
constexpr const wchar_t* WXPYTHONPATHLIB = _T("Lib\\site-packages\\wx");

//-----------------------------------------------------------------------------
//----- ObjectARX EntryPoint
class PyRxLoader : public AcRxArxApp
{
    std::wstring envToRestoreFrom;

public:
    PyRxLoader() : AcRxArxApp()
    {
    }

    virtual AcRx::AppRetCode On_kInitAppMsg(void* pkt)
    {
        AcRx::AppRetCode retCode = AcRxArxApp::On_kInitAppMsg(pkt);
        PyRxLoader_loader();
        envToRestoreFrom = getPathEnvironmentVariable();
        return (retCode);
    }

    virtual AcRx::AppRetCode On_kUnloadAppMsg(void* pkt)
    {
        AcRx::AppRetCode retCode = AcRxArxApp::On_kUnloadAppMsg(pkt);
        SetEnvironmentVariable(PATHENV, envToRestoreFrom.c_str());
        return (retCode);
    }

    virtual AcRx::AppRetCode On_kLoadDwgMsg(void* pkt) override
    {
        AcRx::AppRetCode retCode = AcRxDbxApp::On_kLoadDwgMsg(pkt);
        return retCode;
    }

    virtual void RegisterServerComponents()
    {
    }

    static const TCHAR* getNameOfModuleToLoad()
    {
#if defined(_ARXTARGET) && _ARXTARGET == 240
        return L"PyRx24.0.arx";
#elif defined(_ARXTARGET) && _ARXTARGET == 241
        return L"PyRx24.1.arx";
#elif defined(_ARXTARGET) && _ARXTARGET == 242
        return L"PyRx24.2.arx";
#elif defined(_ARXTARGET) && _ARXTARGET == 243
        return L"PyRx24.3.arx";
#elif defined(_ARXTARGET) && _ARXTARGET == 250
        return L"PyRx25.0.arx";
#elif defined(_BRXTARGET) && _BRXTARGET == 240
        return L"PyRxV24.0.brx";
#elif defined(_GRXTARGET) && _GRXTARGET == 240
        return L"PyRxG24.0.grx";
#elif defined(_ZRXTARGET) && _ZRXTARGET == 240
        return L"PyRxZ24.0.Zrx";
#endif
        acutPrintf(_T("Error in getNameOfModuleToLoad: "));
        return L"!ERROR!";
    }

    static auto thisModulePath()
    {
        std::wstring buffer(MAX_PATH, 0);
        GetModuleFileName(_hdllInstance, buffer.data(), buffer.size());
        std::filesystem::path path = buffer.c_str();
        path.remove_filename();
        std::error_code ec;
        return std::tuple(std::filesystem::is_directory(path, ec), path);
    }

    static auto getInstallPath()
    {
        std::wstring buffer(MAX_PATH, 0);
        GetEnvironmentVariable(_T("localappdata"), buffer.data(), buffer.size());
        std::filesystem::path path = buffer.c_str();
        path /= _T("Programs\\PyRx");
        std::error_code ec;
        return std::tuple(std::filesystem::is_directory(path, ec), path);
    }

    static auto getPythonVenvPath()
    {
        std::wstring buffer(MAX_PATH, 0);
        GetEnvironmentVariable(_T("VIRTUAL_ENV"), buffer.data(), buffer.size());
        std::filesystem::path path = buffer.c_str();
        std::error_code ec;
        return std::tuple(std::filesystem::is_directory(path, ec), path);
    }

    static std::wstring getPathEnvironmentVariable()
    {
        std::wstring buffer(32767, 0);
        GetEnvironmentVariable(PATHENV, buffer.data(), buffer.size());
        buffer.erase(std::find(buffer.begin(), buffer.end(), '\0'), buffer.end());
        return buffer;
    }

    static bool setenvpath(const std::wstring& pathToAdd)
    {
        const std::wstring pathToAddLower = tolower(pathToAdd);
        std::wstring buffer = tolower(getPathEnvironmentVariable());
        if (buffer.find(pathToAddLower) == std::string::npos)
        {
            buffer.append(_T(";"));
            buffer.append(pathToAddLower.c_str());
            if (SetEnvironmentVariable(_T("PATH"), buffer.data()) == 0)
            {
                acutPrintf(_T("\nFailed @ SetEnvironmentVariable %ls: "), _T("pathToAdd"));
                return false;
            }
        }
        return true;
    }

    static auto getIniPath()
    {
        constexpr const wchar_t* ininame = _T("PyRx.INI");
        constexpr const wchar_t* ininamebin = _T("Bin\\PyRx.INI");
        const auto [modulePathPound, modulePath] = thisModulePath();
        std::filesystem::path path = modulePath / ininame;
        std::error_code ec;
        if (std::filesystem::exists(path, ec))
            return std::tuple(true, path);
        const auto [installPathFound, installPath] = getInstallPath();
        if (installPathFound)
        {
            path = installPath / ininamebin;
            if (std::filesystem::exists(path, ec))
                return std::tuple(true, path);
        }
        acutPrintf(_T("\nCan't find PyRx.INI: "));
        return std::tuple(false, std::filesystem::path{});
    }

    static auto tryFindPythonPath()
    {
        std::wstring buffer = tolower(getPathEnvironmentVariable());
        std::vector<std::wstring> words;
        splitW(buffer, ';', words);
        for (auto& word : words)
        {
            rtrim(word, '\\');
            if (word.ends_with(PYTHONNAME))
                return std::tuple(true, std::filesystem::path{ word });
        }
        return std::tuple(false, std::filesystem::path{});
    }

    static void setEnvWithNoIni()
    {
        const auto [pythonPathFound, pythonPath] = tryFindPythonPath();
        if (pythonPathFound)
        {
            setenvpath(pythonPath);
            setenvpath(pythonPath / WXPYTHONPATHLIB);
        }
    }

    static void validateINIPythonInstallPath(const std::wstring& inipath, const std::wstring& path)
    {
        std::error_code ec;
        if (std::filesystem::is_directory(path, ec) == false)
        {
            const auto [pythonPathFound, pythonPath] = tryFindPythonPath();
            if (pythonPathFound)
            {
                WritePrivateProfileString(PYRXSETTINGS, PYTHONINSTALLEDPATH, pythonPath.c_str(), inipath.c_str());
                setenvpath(pythonPath);
                return;
            }
        }
        setenvpath(path);
    }

    static void validateINIwxPythonPath(const std::wstring& inipath, const std::wstring& path)
    {
        std::error_code ec;
        if (std::filesystem::is_directory(path, ec) == false)
        {
            const auto [pythonPathFound, pythonPath] = tryFindPythonPath();
            if (pythonPathFound)
            {
                std::filesystem::path wxPythonPath = pythonPath / WXPYTHONPATHLIB;
                WritePrivateProfileString(PYRXSETTINGS, WXPYTHONPATH, wxPythonPath.c_str(), inipath.c_str());
                setenvpath(wxPythonPath);
                return;
            }
        }
        setenvpath(path);
    }

    static void setEnvWithIni(const std::filesystem::path& inipath)
    {
        std::wstring pythonInstallPath(MAX_PATH, 0);
        if (GetPrivateProfileStringW(PYRXSETTINGS, PYTHONINSTALLEDPATH, _T(""), pythonInstallPath.data(), pythonInstallPath.size(), inipath.c_str()) != 0)
            validateINIPythonInstallPath(inipath, pythonInstallPath);
        else
            acutPrintf(_T("\nFailed to read setting %ls: "), PYTHONINSTALLEDPATH);

        std::wstring wxPythonPath(MAX_PATH, 0);
        if (GetPrivateProfileStringW(PYRXSETTINGS, WXPYTHONPATH, _T(""), wxPythonPath.data(), wxPythonPath.size(), inipath.c_str()) != 0)
            validateINIwxPythonPath(inipath, wxPythonPath);
        else
            acutPrintf(_T("\nFailed to read setting %ls: "), WXPYTHONPATH);
    }

    static void PyRxLoader_loader(void)
    {
#ifdef PYRXDEBUG
        const auto [f, p] = getPythonVenvPath();
        acutPrintf(std::format(_T("\n{}-{}"), f, p.c_str()).c_str());
#endif
        std::error_code ec;
        const auto oldpath = std::filesystem::current_path(ec);
        const auto [modulePathPound, modulePath] = thisModulePath();
        const auto [installPathFound, installPath] = getInstallPath();
        const auto [iniPathFound, inipath] = getIniPath();
        std::filesystem::current_path(modulePath, ec);
        {
            if (iniPathFound == false)
                setEnvWithNoIni();
            else
                setEnvWithIni(inipath);
        }
        if (auto arxpath = installPath / _T("Bin") / getNameOfModuleToLoad(); installPathFound && std::filesystem::exists(arxpath, ec))
        {
            if (AcString foundPath; acdbHostApplicationServices()->findFile(foundPath, arxpath.c_str()) == eOk)
                acrxDynamicLinker->loadModule(foundPath, true);
        }
        else
        {
            arxpath = modulePath / getNameOfModuleToLoad();
            if (AcString foundPath; acdbHostApplicationServices()->findFile(foundPath, arxpath.c_str()) == eOk)
                acrxDynamicLinker->loadModule(foundPath, true);
        }
        std::filesystem::current_path(oldpath, ec);
    }
};

//-----------------------------------------------------------------------------
#pragma warning( disable: 4838 ) //prevents a cast compiler warning, 
IMPLEMENT_ARX_ENTRYPOINT(PyRxLoader)
//ACED_ARXCOMMAND_ENTRY_AUTO(PyRxLoader, PyRxLoader, _loader, loader, ACRX_CMD_TRANSPARENT, NULL)
#pragma warning( pop )
