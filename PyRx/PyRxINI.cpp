#include "stdafx.h"
#include "PyRxINI.h"
#include "PyRxApp.h"

const std::filesystem::path& PyRxINI::iniPath()
{
    constexpr const wchar_t* ininame = _T("PyRx.INI");
    static std::filesystem::path spath = PyRxApp::modulePath() / ininame;
    return spath;
}

const std::tuple<bool, bool> PyRxINI::pythonIsolated()
{
    wchar_t buffer[8] = { 0 };
    if (acedGetEnv(_T("PYRX_PYTHONISOLATED"), buffer, 12) == RTNORM)
    {
        if (_wtoi(buffer) == 1)
            return std::make_tuple(true, true);

    }
    int nDefault = 0;
    int result = GetPrivateProfileInt(_T("PYRXSETTINGS"), _T("PYTHONISOLATED"), nDefault, iniPath().c_str());
    return std::make_tuple(true, result);
}

const std::tuple<bool, std::wstring> PyRxINI::pythonvenv_path()
{
    std::error_code ec;
    wchar_t buffer[MAX_PATH] = { 0 };
    if (acedGetEnv(_T("PYRX_VIRTUAL_ENV"), buffer, MAX_PATH) == RTNORM)
    {
        if (std::filesystem::exists(buffer, ec))
            return std::make_tuple(true, buffer);
        return std::make_tuple(false, buffer);
    }
    std::wstring exepath(MAX_PATH, 0);
    GetPrivateProfileStringW(_T("PYRXSETTINGS"), _T("PYTHONEXECUTABLE"), _T(""), exepath.data(), exepath.size(), iniPath().c_str());
    if (std::filesystem::exists(exepath.c_str(), ec))
        return std::make_tuple(true, exepath.c_str());
    return std::make_tuple(false, exepath.c_str());
}
