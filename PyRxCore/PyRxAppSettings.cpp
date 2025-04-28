#include "stdafx.h"
#include "PyRxAppSettings.h"
#include "PyRxApp.h"

//https://marzer.github.io/tomlplusplus/
#define TOML_EXCEPTIONS 0
#define TOML_HEADER_ONLY 1
#include "toml.h"

void PyRxAppSettings::tomlTest()
{
    toml::parse_result result = toml::parse_file("M:\\Dev\\Projects\\PyRxGit\\pyproject.toml");
    if (!result)
    {
        acutPrintf(_T("FAIL"));
        return;
    }
    auto table = std::move(result).table();
    auto name = table["project"]["name"];
    if (name.is_string())
    {
        acutPrintf(_T("name = %ls"), utf8_to_wstr(name.as_string()->get()).c_str());
    }
}

const std::tuple<bool, std::wstring> PyRxAppSettings::pyexecutable_path()
{
    std::error_code ec;
    {
        std::wstring exepath(MAX_PATH, 0);
        if (acedGetEnv(_T("PYRX_PYEXE_PATH"), exepath.data(), exepath.size()) == RTNORM)
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
    if (GetEnvironmentVariable(_T("PYRX_ONLOAD_PATH"), path.data(), path.size()) == RTNORM)
    {
        if (AcString foundPath; acdbHostApplicationServices()->findFile(foundPath, path.c_str()) == eOk && foundPath.length() != 0)
        {
            if (std::filesystem::exists((const wchar_t*)foundPath, ec))
                return std::make_tuple(true, std::wstring((const wchar_t*)foundPath));
        }
    }

    const auto pyrx_onloadPathc = PyRxApp::modulePath() / _T("pyrx_onload.pyc");
    if (AcString foundPath; acdbHostApplicationServices()->findFile(foundPath, pyrx_onloadPathc.c_str()) == eOk && foundPath.length() != 0)
    {
        if (std::filesystem::exists((const wchar_t*)foundPath, ec))
            return std::make_tuple(true, std::wstring((const wchar_t*)foundPath));
    }

    const auto pyrx_onloadPath = PyRxApp::modulePath() / _T("pyrx_onload.py");
    if (AcString foundPath; acdbHostApplicationServices()->findFile(foundPath, pyrx_onloadPath.c_str()) == eOk && foundPath.length() != 0)
    {
        if (std::filesystem::exists((const wchar_t*)foundPath, ec))
            return std::make_tuple(true, std::wstring((const wchar_t*)foundPath));
    }

    if (AcString foundPath; acdbHostApplicationServices()->findFile(foundPath, _T("pyrx_onload.pyc")) == eOk && foundPath.length() != 0)
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

std::vector<std::wstring>& PyRxAppSettings::getCommandLineArgs()
{
    static std::vector<std::wstring> pyrxArgs;
    if (pyrxArgs.size() == 0)
    {
        int nArgs = 0;
        LPWSTR* szArglist = CommandLineToArgvW(GetCommandLineW(), &nArgs);
        if (szArglist != nullptr)
        {
            for (int i = 0; i < nArgs; i++)
                pyrxArgs.emplace_back(std::wstring{ szArglist[i] });
            LocalFree(szArglist);
        }
    }
    return pyrxArgs;
}