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

//FORCEBUILD = 20
constexpr const wchar_t* PATHENV = _T("PATH");
constexpr const wchar_t* PYTHONNAME = _T("python312");
constexpr const wchar_t* PYTHONDLLNAME = _T("python312.dll");
constexpr const wchar_t* PYTHONEXEC = _T("python.exe");
constexpr const wchar_t* PYTHONVENVEXEC = _T("Scripts\\python.exe");
constexpr const wchar_t* PYRXPATHLIB = _T("Lib\\site-packages\\pyrx");
constexpr const wchar_t* WXPYTHONPATHLIB = _T("Lib\\site-packages\\wx");
constexpr const wchar_t* PYRXPATHLIB_EMEDDED = _T("pyrx");
constexpr const wchar_t* WXPYTHONPATHLIB_EMEDDED = _T("wx");
constexpr const wchar_t* APPDATA_PYTHONPATH = _T("Programs\\Python\\Python312");


//-----------------------------------------------------------------------------
//----- pyrx_locale
_locale_t& pyrx_locale()
{
    // TODO: set form OS? or pyrx_config 
    // this is only used in toupper & tolower
    static _locale_t pyrx_locale = _create_locale(LC_ALL, "en_US.UTF-8");
    return pyrx_locale;
}

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
#elif defined(_ARXTARGET) && _ARXTARGET == 251
        return L"PyRx25.1.arx";
#elif defined(_BRXTARGET) && _BRXTARGET == 240
        return L"PyRxV24.0.brx";
#elif defined(_BRXTARGET) && _BRXTARGET == 250
        return L"PyRxV25.0.brx";
#elif defined(_GRXTARGET) && _GRXTARGET == 240
        return L"PyRxG24.0.grx";
#elif defined(_GRXTARGET) && _GRXTARGET == 250
        return L"PyRxG25.0.grx";
#elif defined(_GRXTARGET) && _GRXTARGET == 260
        return L"PyRxG26.0.grx";
#elif defined(_ZRXTARGET) && _ZRXTARGET == 240
        return L"PyRxZ24.0.Zrx";
#elif defined(_ZRXTARGET) && _ZRXTARGET == 250
        return L"PyRxZ25.0.Zrx";
#elif defined(_ZRXTARGET) && _ZRXTARGET == 260
        return L"PyRxZ26.0.Zrx";
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

    [[nodiscard]] static std::wstring getPathEnvironmentVariable()
    {
        std::wstring _buffer(32767, 0);
        GetEnvironmentVariable(PATHENV, _buffer.data(), _buffer.size());
        return std::wstring{ _buffer.c_str() };
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

    [[nodiscard]] static const auto tryFindPythonPathFromParent()
    {
        std::error_code ec;
        static std::filesystem::path path;
        if (path.empty())
        {
            auto [bfound, fpath] = thisModulePath();
            if (bfound == true)
            {
                const auto root = fpath.root_path();

                if (_wcsicmp(fpath.filename().c_str(), PYTHONNAME) == 0 ||
                    std::filesystem::exists(fpath / PYTHONDLLNAME, ec))
                {
                    path = fpath;
                }
                else
                {
                    while (fpath.has_parent_path() && fpath != root)
                    {
                        fpath = fpath.parent_path();
                        if (_wcsicmp(fpath.filename().c_str(), PYTHONNAME) == 0 ||
                            std::filesystem::exists(fpath / PYTHONDLLNAME, ec))
                        {
                            path = fpath;
                            break;
                        }
                    }
                }
            }
            appendLog(std::format(_T("{} {}"), __FUNCTIONW__, path.c_str()));
        }
        return std::tuple(std::filesystem::is_directory(path, ec), path);
    }

    [[nodiscard]] static const auto tryFindPythonPathFromAppData()
    {
        static std::filesystem::path path;
        if (path.empty())
        {
            std::wstring buffer(MAX_PATH, 0);
            GetEnvironmentVariable(_T("localappdata"), buffer.data(), buffer.size());
            path = buffer.c_str();
            path /= APPDATA_PYTHONPATH;
            appendLog(std::format(_T("{} {}"), __FUNCTIONW__, path.c_str()));
        }
        std::error_code ec;
        return std::tuple(std::filesystem::is_directory(path, ec), path);
    }

    [[nodiscard]] static auto tryFindPythonPath()
    {
        static std::filesystem::path path;
        if (path.empty())
        {
            if (auto [bfound, fpath] = tryFindPythonPathFromParent(); bfound)
            {
                path = fpath;
            }
            else if (auto [bfound, fpath] = tryFindPythonPathFromAppData(); bfound)
            {
                path = fpath;
            }
            else
            {
                std::wstring buffer = towlower(getPathEnvironmentVariable());
                std::vector<std::wstring> words;
                splitW(buffer, ';', words);
                for (auto& word : words)
                {
                    rtrim(word, '\\');
                    rtrim(word, '/');
                    if (word.ends_with(PYTHONNAME))
                    {
                        path = std::filesystem::path{ word };
                        appendLog(std::format(_T("{} {}"), __FUNCTIONW__, path.c_str()));
                    }
                }
            }
        }
        if (!path.empty())
        {
            std::error_code ec;
            const std::wstring exepath = (path / PYTHONEXEC);
            if (std::filesystem::exists(exepath,ec))
                acedSetEnv(_T("PYRX_PYEXE_PATH"), exepath.c_str());
            else
                appendLog(std::format(_T("PyExePath Failed @ {} {} {}"), __FUNCTIONW__, __LINE__, path.c_str()));
            return std::tuple(true, path);
        }
        return std::tuple(false, path);
    }

    [[nodiscard]] static const auto getInstallPath()
    {
        static std::filesystem::path path;
        std::error_code ec;
        if (path.empty())
        {
            if (auto [bvenv, venv] = getPythonVenvPath(); bvenv == true)
            {
                if (std::filesystem::is_directory(venv / PYRXPATHLIB, ec))
                    path = venv / PYRXPATHLIB;
                else if (std::filesystem::is_directory(venv / PYRXPATHLIB_EMEDDED, ec))
                    path = venv / PYRXPATHLIB_EMEDDED;
                else
                    appendLog(std::format(_T("Failed @ {} {} {}"), __FUNCTIONW__, __LINE__, path.c_str()));
            }
            else if (auto [bpypath, pypath] = tryFindPythonPath(); bpypath == true)
            {
                if (std::filesystem::is_directory(pypath / PYRXPATHLIB, ec))
                    path = pypath / PYRXPATHLIB;
                else if (std::filesystem::is_directory(pypath / PYRXPATHLIB_EMEDDED, ec))
                    path = pypath / PYRXPATHLIB_EMEDDED;
                else
                    appendLog(std::format(_T("Failed @ {} {} {}"), __FUNCTIONW__, __LINE__, path.c_str()));
            }
            else
            {
                appendLog(std::format(_T("Failed @ {} {} {}"), __FUNCTIONW__, __LINE__, path.c_str()));
            }
            appendLog(std::format(_T("{} {}"), __FUNCTIONW__, path.c_str()));
        }
        return std::tuple(std::filesystem::is_directory(path, ec), path);
    }

    static bool setenvpath(const std::wstring& pathToAdd)
    {
        const std::wstring pathToAddLower = towlower(pathToAdd) + _T(";");
        std::wstring buffer = towlower(getPathEnvironmentVariable());
        if (buffer.find(pathToAddLower) == std::string::npos)
        {
            buffer = pathToAddLower + buffer;
            if (SetEnvironmentVariable(_T("PATH"), buffer.data()) == 0)
            {
                appendLog(std::format(_T("Failed @ {} {} {}"), __FUNCTIONW__, __LINE__, pathToAdd.c_str()));
                return false;
            }
            appendLog(std::format(_T("added path @ {} {} {}"), __FUNCTIONW__, __LINE__, pathToAdd.c_str()));
        }
        return true;
    }

    [[nodiscard]] static const auto tryFindWxPythonPath()
    {
        static std::filesystem::path path;
        std::error_code ec;
        if (path.empty())
        {
            if (auto [bvenv, venv] = getPythonVenvPath(); bvenv == true)
            {
                if (std::filesystem::is_directory(venv / WXPYTHONPATHLIB, ec))
                    path = venv / WXPYTHONPATHLIB;
                else if (std::filesystem::is_directory(venv / WXPYTHONPATHLIB_EMEDDED, ec))
                    path = venv / WXPYTHONPATHLIB_EMEDDED;
                else
                    appendLog(std::format(_T("Failed @ {} {} {}"), __FUNCTIONW__, __LINE__, path.c_str()));
            }
            else if (auto [pythonPathFound, pythonPath] = tryFindPythonPath(); pythonPathFound == true)
            {
                if (std::filesystem::is_directory(pythonPath / WXPYTHONPATHLIB, ec))
                    path = pythonPath / WXPYTHONPATHLIB;
                else if (std::filesystem::is_directory(pythonPath / WXPYTHONPATHLIB_EMEDDED, ec))
                    path = pythonPath / WXPYTHONPATHLIB_EMEDDED;
                else
                    appendLog(std::format(_T("Failed @ {} {} {}"), __FUNCTIONW__, __LINE__, path.c_str()));
            }
            appendLog(std::format(_T("{} {}"), __FUNCTIONW__, path.c_str()));
        }
        return std::tuple(std::filesystem::is_directory(path, ec), path);
    }

    [[nodiscard]] static bool setEnvWithNoVENV()
    {
        const auto [pythonPathFound, pythonPath] = tryFindPythonPath();
        const auto [wxpythonPathFound, wxpythonPath] = tryFindWxPythonPath();
        if (pythonPathFound)
            setenvpath(pythonPath);
        if (wxpythonPathFound)
            setenvpath(wxpythonPath);
        return pythonPathFound && wxpythonPathFound;
    }

    [[nodiscard]] static bool checkFileVersionInfo(const CString& ver)
    {
        HINSTANCE hInst = AfxGetInstanceHandle();
        std::wstring fpath(MAX_PATH, 0);
        GetModuleFileName(hInst, fpath.data(), fpath.size());
        const auto infoSize = GetFileVersionInfoSize(fpath.c_str(), nullptr);

        auto lpInfo = std::make_unique<BYTE[]>(infoSize);
        GetFileVersionInfo(fpath.c_str(), 0, infoSize, lpInfo.get());

        UINT valLen = MAX_PATH;
        LPVOID valPtr = NULL;
        CString valStr;

        if (::VerQueryValue(lpInfo.get(), TEXT("\\"), &valPtr, &valLen))
        {
            VS_FIXEDFILEINFO* pFinfo = (VS_FIXEDFILEINFO*)valPtr;
            valStr.Format(_T("%d.%d.%d.%d"),
                HIWORD(pFinfo->dwFileVersionMS),
                LOWORD(pFinfo->dwFileVersionMS),
                HIWORD(pFinfo->dwFileVersionLS),
                LOWORD(pFinfo->dwFileVersionLS)
            );
        }
        return valStr == ver;
    }

    static void PyRxLoader_loader(void)
    {
        std::error_code ec;
        bool envSet = false;

        const auto oldpath = std::filesystem::current_path(ec);
        const auto [virtual_env_found, virtual_env_path] = getPythonVenvPath();
        const auto [modulePathPound, modulePath] = thisModulePath();
        const auto [installPathFound, installPath] = getInstallPath();
        const auto [wxpythonPathFound, wxpythonPath] = tryFindWxPythonPath();

        std::filesystem::current_path(modulePath, ec);
        acedSetEnv(_T("PYRX_PYEXE_PATH"), L"");

        std::time_t now_time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        const auto date = _wctime64(&now_time);
        if (date != nullptr)
            appendLog(date);

        if (virtual_env_found)
        {
            acedSetEnv(_T("PYRX_PYEXE_PATH"), (virtual_env_path / PYTHONVENVEXEC).c_str());
            setenvpath(wxpythonPath);
            appendLog(_T("\nLoading PyRx from venv condition"));
            envSet = true;
        }
        else
        {
            envSet = setEnvWithNoVENV();
            appendLog(_T("\nLoading PyRx from normal condition"));
        }
        if (envSet == false)
        {
            appendLog(_T("\nPyRxLoader_loader @find path FAILED"));
            return;
        }
        bool loaded = false;
#ifdef PYRXDEBUG 
        if (auto arxpath = installPath / getNameOfModuleToLoad(); installPathFound && std::filesystem::exists(arxpath, ec))
        {
            appendLog(std::format(_T("{} Loading, {}"), __FUNCTIONW__, arxpath.c_str()));
            if (AcString foundPath; acdbHostApplicationServices()->findFile(foundPath, arxpath.c_str()) == eOk)
                loaded = acrxDynamicLinker->loadModule(foundPath, true);
        }
        else
        {
            arxpath = modulePath / getNameOfModuleToLoad();
            appendLog(std::format(_T("{} Loading, {}"), __FUNCTIONW__, arxpath.c_str()));
            if (AcString foundPath; acdbHostApplicationServices()->findFile(foundPath, arxpath.c_str()) == eOk)
                loaded = acrxDynamicLinker->loadModule(foundPath, true);
        }
#else
        if (const auto arxpath = modulePath / getNameOfModuleToLoad(); modulePathPound && std::filesystem::exists(arxpath, ec))
        {
            appendLog(std::format(_T("{} Loading, {}"), __FUNCTIONW__, arxpath.c_str()));
            if (AcString foundPath; acdbHostApplicationServices()->findFile(foundPath, arxpath.c_str()) == eOk)
                loaded = acrxDynamicLinker->loadModule(foundPath, true);
        }
        else if (const auto arxpath = installPath / getNameOfModuleToLoad(); installPathFound && std::filesystem::exists(arxpath, ec))
        {
            appendLog(std::format(_T("{} Loading, {}"), __FUNCTIONW__, arxpath.c_str()));
            if (AcString foundPath; acdbHostApplicationServices()->findFile(foundPath, arxpath.c_str()) == eOk)
                loaded = acrxDynamicLinker->loadModule(foundPath, true);
        }
        else
        {
            appendLog(_T("\nPyRxLoader_loader @loadModule not found"));
        }
#endif
        std::filesystem::current_path(oldpath, ec);
        if (loaded == false)
        {
            appendLog(_T("\nPyRxLoader_loader @loadModule  FAILED"));
            return;
        }
        appendLog(_T("\nPyRxLoader_loader SUCCESS"));
    }

    static void PyRxLoader_pyrxloadlog(void)
    {
        acutPrintf(_T("\nLog:\n%ls"), log_buffer.c_str());
    }
};

//-----------------------------------------------------------------------------
#pragma warning( disable: 4838 ) //prevents a cast compiler warning, 
IMPLEMENT_ARX_ENTRYPOINT(PyRxLoader)
#ifdef NEVER
ACED_ARXCOMMAND_ENTRY_AUTO(PyRxLoader, PyRxLoader, _loader, loader, ACRX_CMD_TRANSPARENT, NULL)
#endif
ACED_ARXCOMMAND_ENTRY_AUTO(PyRxLoader, PyRxLoader, _pyrxloadlog, pyrxloadlog, ACRX_CMD_TRANSPARENT, NULL)
#pragma warning( pop )
