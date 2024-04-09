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
constexpr const wchar_t* PYTHONVENVEXEC = _T("Scripts\\python.exe");

//-----------------------------------------------------------------------------
//----- ObjectARX EntryPoint
class PyRxLoader : public AcRxArxApp
{
    std::wstring envToRestoreFrom;
    inline static std::wstring log_buffer;
    inline static int PYRX_LOG = 0;

public:
    PyRxLoader() : AcRxArxApp()
    {
    }

    //(setenv "PYRX_LOG" "1")
    //(setenv "PYRX_LOG" "0")
    virtual AcRx::AppRetCode On_kInitAppMsg(void* pkt)
    {
        AcRx::AppRetCode retCode = AcRxArxApp::On_kInitAppMsg(pkt);
        acrxLockApplication(pkt);
        acedRegisterOnIdleWinMsg(PyRxOnIdleMsgFn);
        std::array<wchar_t, 8> buffer = { 0 };
        if (acedGetEnv(_T("PYRX_LOG"), buffer.data(), buffer.size()) == RTNORM)
        {
            if (_wtoi(buffer.data()) == 1)
                PYRX_LOG = 1;
            else
                PYRX_LOG = 0;
        }
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

    [[nodiscard]] static const TCHAR* getNameOfModuleToLoad()
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

    static void appendLog(const std::wstring& message)
    {
        if (PYRX_LOG)
        {
            log_buffer.append(message);
            log_buffer.append(_T("\n"));
        }
    }

    static void PyRxOnIdleMsgFn()
    {
        if (log_buffer.size() && curDoc() != nullptr)
        {
            acutPrintf(_T("\n%ls"), log_buffer.c_str());
            log_buffer.clear();
#ifndef _GRXTARGET
            acedRemoveOnIdleWinMsg(PyRxOnIdleMsgFn);
#endif 
        }
    }

    [[nodiscard]] static const auto thisModulePath()
    {
        static std::filesystem::path path;
        if (path.empty())
        {
            std::wstring buffer(MAX_PATH, 0);
            GetModuleFileName(_hdllInstance, buffer.data(), buffer.size());
            path = buffer.c_str();
            path.remove_filename();
            appendLog(std::format(_T("{} {}"), __FUNCTIONW__, path.c_str()));
        }
        std::error_code ec;
        return std::tuple(std::filesystem::is_directory(path, ec), path);
    }

    [[nodiscard]] static const auto getInstallPath()
    {
        static std::filesystem::path path;
        if (path.empty())
        {
            std::wstring buffer(MAX_PATH, 0);
            GetEnvironmentVariable(_T("localappdata"), buffer.data(), buffer.size());
            path = buffer.c_str();
            path /= _T("Programs\\PyRx");
            appendLog(std::format(_T("{} {}"), __FUNCTIONW__, path.c_str()));
        }
        std::error_code ec;
        return std::tuple(std::filesystem::is_directory(path, ec), path);
    }

    [[nodiscard]] static const auto getPythonVenvPath()
    {
        static std::filesystem::path path;
        if (path.empty())
        {
            std::wstring buffer(MAX_PATH, 0);
            GetEnvironmentVariable(_T("VIRTUAL_ENV"), buffer.data(), buffer.size());
            path = buffer.c_str();
            appendLog(std::format(_T("{} {}"), __FUNCTIONW__, path.c_str()));
        }
        std::error_code ec;
        return std::tuple(std::filesystem::is_directory(path, ec), path);
    }

    [[nodiscard]] static std::wstring getPathEnvironmentVariable()
    {
        std::wstring buffer(32767, 0);
        GetEnvironmentVariable(PATHENV, buffer.data(), buffer.size());
        buffer.erase(std::find(buffer.begin(), buffer.end(), '\0'), buffer.end());
        return buffer;
    }

    [[nodiscard]] static auto getIniPath()
    {
        constexpr const wchar_t* ininame = _T("PyRx.INI");
        constexpr const wchar_t* ininamebin = _T("Bin\\PyRx.INI");
        const auto [modulePathPound, modulePath] = thisModulePath();
        std::filesystem::path path = modulePath / ininame;
        std::error_code ec;
        if (std::filesystem::exists(path, ec))
        {
            appendLog(std::format(_T("{} {}"), __FUNCTIONW__, path.c_str()));
            return std::tuple(true, path);
        }
        const auto [installPathFound, installPath] = getInstallPath();
        if (installPathFound)
        {
            path = installPath / ininamebin;
            if (std::filesystem::exists(path, ec))
            {
                appendLog(std::format(_T("{} {}"), __FUNCTIONW__, path.c_str()));
                return std::tuple(true, path);
            }
        }
        acutPrintf(_T("\nCan't find PyRx.INI: "));
        return std::tuple(false, std::filesystem::path{});
    }

    [[nodiscard]] static auto tryFindPythonPath()
    {
        static std::filesystem::path path;
        if (path.empty())
        {
            std::wstring buffer = tolower(getPathEnvironmentVariable());
            std::vector<std::wstring> words;
            splitW(buffer, ';', words);
            for (auto& word : words)
            {
                rtrim(word, '\\');
                if (word.ends_with(PYTHONNAME))
                {
                    path = std::filesystem::path{ word };
                    appendLog(std::format(_T("{} {}"), __FUNCTIONW__, path.c_str()));
                    return std::tuple(!path.empty(), path);
                }
            }
        }
        return std::tuple(!path.empty(), path);
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
                appendLog(std::format(_T("{} {}"), __FUNCTIONW__, pythonPath.c_str()));
                setenvpath(pythonPath);
                return;
            }
        }
        appendLog(std::format(_T("{} {}"), __FUNCTIONW__, path.c_str()));
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
                appendLog(std::format(_T("{} {}"), __FUNCTIONW__, wxPythonPath.c_str()));
                setenvpath(wxPythonPath);
                return;
            }
        }
        appendLog(std::format(_T("{} {}"), __FUNCTIONW__, path.c_str()));
        setenvpath(path);
    }

    static void PyRxLoader_loader(void)
    {
        std::error_code ec;
        const auto oldpath = std::filesystem::current_path(ec);
        const auto [virtual_env_found, virtual_env_path] = getPythonVenvPath();
        const auto [modulePathPound, modulePath] = thisModulePath();
        const auto [installPathFound, installPath] = getInstallPath();
        const auto [iniPathFound, inipath] = getIniPath();
        std::filesystem::current_path(modulePath, ec);

        acedSetEnv(_T("PYRX_VIRTUAL_ENV"), L"");
        acedSetEnv(_T("PYRX_PYTHONISOLATED"), L"0");
        if (virtual_env_found)
        {
            acedSetEnv(_T("PYRX_VIRTUAL_ENV"), (virtual_env_path / PYTHONVENVEXEC).c_str());
            acedSetEnv(_T("PYRX_PYTHONISOLATED"), L"1");
            setenvpath(virtual_env_path / WXPYTHONPATHLIB);
            appendLog(_T("\nLoading PyRx from venv condition"));
            appendLog((virtual_env_path / WXPYTHONPATHLIB));
        }
        else if (iniPathFound)
        {
            setEnvWithIni(inipath);
            appendLog(_T("\nLoading PyRx from ini condition"));
        }
        else
        {
            setEnvWithNoIni();
            appendLog(_T("\nLoading PyRx from no ini condition"));
        }
        if (auto arxpath = installPath / _T("Bin") / getNameOfModuleToLoad(); installPathFound && std::filesystem::exists(arxpath, ec))
        {
            appendLog(std::format(_T("{} Loading, {}"), __FUNCTIONW__, arxpath.c_str()));
            if (AcString foundPath; acdbHostApplicationServices()->findFile(foundPath, arxpath.c_str()) == eOk)
                acrxDynamicLinker->loadModule(foundPath, true);
        }
        else
        {
            arxpath = modulePath / getNameOfModuleToLoad();
            appendLog(std::format(_T("{} Loading, {}"), __FUNCTIONW__, arxpath.c_str()));
            if (AcString foundPath; acdbHostApplicationServices()->findFile(foundPath, arxpath.c_str()) == eOk)
                acrxDynamicLinker->loadModule(foundPath, true);
        }
        appendLog(_T("\nFinished PyRxLoader_loader"));
        std::filesystem::current_path(oldpath, ec);
    }
};

//-----------------------------------------------------------------------------
#pragma warning( disable: 4838 ) //prevents a cast compiler warning, 
IMPLEMENT_ARX_ENTRYPOINT(PyRxLoader)
//ACED_ARXCOMMAND_ENTRY_AUTO(PyRxLoader, PyRxLoader, _loader, loader, ACRX_CMD_TRANSPARENT, NULL)
#pragma warning( pop )
