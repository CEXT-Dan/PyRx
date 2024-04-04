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
    int nDefault = 0;
    int result = GetPrivateProfileInt(_T("PYRXSETTINGS"), _T("PYTHONISOLATED"), nDefault, iniPath().c_str());
    return std::make_tuple(true, result);
}

const std::tuple<bool, std::wstring> PyRxINI::pythonvenv_path()
{
    std::wstring exepath(MAX_PATH, 0);
    GetPrivateProfileStringW(_T("PYRXSETTINGS"), _T("PYTHONEXECUTABLE"), _T(""), exepath.data(), exepath.size(), iniPath().c_str());
    std::error_code ec;
    if (std::filesystem::exists(exepath.c_str(), ec))
        return std::make_tuple(true, exepath.c_str());
    return std::make_tuple(false, exepath.c_str());
}
