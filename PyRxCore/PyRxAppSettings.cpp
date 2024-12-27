#include "stdafx.h"
#include "PyRxAppSettings.h"
#include "PyRxApp.h"

const std::filesystem::path& PyRxAppSettings::iniPath()
{
    constexpr const wchar_t* ininame = _T("PyRx.INI");
    static std::filesystem::path spath = PyRxApp::modulePath() / ininame;
    return spath;
}

const std::tuple<bool, std::wstring> PyRxAppSettings::pythonvenv_path()
{
    std::error_code ec;
    {
        std::wstring exepath(MAX_PATH, 0);
        if (acedGetEnv(_T("PYRX_VIRTUAL_ENV"), exepath.data(), exepath.size()) == RTNORM)
        {
            if (std::filesystem::exists(exepath.c_str(), ec))
                return std::make_tuple(true, exepath.c_str());
        }
    }
    return std::make_tuple(false, L"");
}

const std::tuple<bool, std::wstring> PyRxAppSettings::pyonload_path()
{
    std::error_code ec;
    std::wstring buffer(5, 0);
    if (GetEnvironmentVariable(_T("PYRX_DISABLE_ONLOAD"), buffer.data(), buffer.size()))
    {
        if (std::stoi(buffer) == 1)
            return std::make_tuple(false, std::wstring());
    }

    std::wstring path(MAX_PATH, 0);
    if (acedGetEnv(_T("PYRX_ONLOAD_PATH"), path.data(), path.size()) == RTNORM)
    {
        if (AcString foundPath; acdbHostApplicationServices()->findFile(foundPath, path.c_str()) == eOk && foundPath.length() != 0)
        {
            if (std::filesystem::exists((const wchar_t*)foundPath, ec))
                return std::make_tuple(true, std::wstring((const wchar_t*)foundPath));
        }
    }

    const auto pyrx_onloadPath = PyRxApp::modulePath() / _T("pyrx_onload.py");
    if (AcString foundPath; acdbHostApplicationServices()->findFile(foundPath, pyrx_onloadPath.c_str()) == eOk && foundPath.length() != 0)
    {
        if (std::filesystem::exists((const wchar_t*)foundPath, ec))
            return std::make_tuple(true, std::wstring((const wchar_t*)foundPath));
    }

    if (AcString foundPath; acdbHostApplicationServices()->findFile(foundPath, _T("pyrx_onload.py")) == eOk && foundPath.length() != 0)
    {
        if (std::filesystem::exists((const wchar_t*)foundPath, ec))
            return std::make_tuple(true, std::wstring((const wchar_t*)foundPath));
    }
    return std::make_tuple(false, std::wstring());
}
