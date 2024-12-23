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
