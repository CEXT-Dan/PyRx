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
    std::array<wchar_t, 8> buffer = { 0 };
    if (acedGetEnv(_T("PYRX_PYTHONISOLATED"), buffer.data(), buffer.size()) == RTNORM)
    {
        if (_wtoi(buffer.data()) == 1)
            return std::make_tuple(true, true);

    }
    int nDefault = 0;
    int result = GetPrivateProfileInt(_T("PYRXSETTINGS"), _T("PYTHONISOLATED"), nDefault, iniPath().c_str());
    return std::make_tuple(true, result);
}

const std::tuple<bool, std::wstring> PyRxINI::pythonvenv_path()
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
    {
        std::wstring exepath(MAX_PATH, 0);
        GetPrivateProfileStringW(_T("PYRXSETTINGS"), _T("PYTHONEXECUTABLE"), _T(""), exepath.data(), exepath.size(), iniPath().c_str());
        if (std::filesystem::exists(exepath.c_str(), ec))
            return std::make_tuple(true, exepath.c_str());
    }
    return std::make_tuple(false, L"");
}
