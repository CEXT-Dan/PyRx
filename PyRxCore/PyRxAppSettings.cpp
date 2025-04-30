#include "stdafx.h"
#include "PyRxAppSettings.h"
#include "PyRxApp.h"

//https://marzer.github.io/tomlplusplus/
#define TOML_EXCEPTIONS 0
#define TOML_HEADER_ONLY 1
#include "toml.h"

constexpr const wchar_t* pyrx_config_name = L"pyrx.toml";

const std::tuple<bool, std::wstring> PyRxAppSettings::getOrCreateConfigPath()
{
    static bool flag = false;
    static std::wstring foundPath;
    if (flag && foundPath.size() != 0)
    {
        return std::make_tuple(flag, foundPath);
    }

    std::error_code ec;
    wchar_t acstrPath[MAX_PATH];
    if (auto rt = acedFindFile(pyrx_config_name, acstrPath, MAX_PATH); rt == RTNORM)
    {
        flag = true;
        foundPath = std::wstring{ acstrPath };
        return std::make_tuple(flag, foundPath);
    }

    const auto roamingPath = PyRxApp::getAppDataPath() / pyrx_config_name;
    if (!std::filesystem::exists(roamingPath, ec))
    {
#ifdef PYRXDEBUG
        std::filesystem::copy(SOLUTION_DIR / L"pyrx" / pyrx_config_name, roamingPath, ec);
#else
        std::filesystem::copy(PyRxApp::modulePath() / pyrx_config_name, roamingPath, ec);
#endif
    }
    if (!std::filesystem::exists(roamingPath, ec))
    {
        acutPrintf(_T("\nError to create config %ls  %ls: "), __FUNCTIONW__, utf8_to_wstr(ec.message()).c_str());
        return std::make_tuple(false, std::wstring{ });
    }
    else
    {
        flag = true;
        foundPath = roamingPath.wstring();
        return std::make_tuple(flag, foundPath);
    }
    return std::make_tuple(false, std::wstring{ });
}

int PyRxAppSettings::optimizationLevel()
{
    std::wstring buffer(5, 0);
    if (GetEnvironmentVariable(_T("PYRX_OPTIMIZATION_LEVEL"), buffer.data(), buffer.size()))
    {
        return std::stoi(buffer);
    }
    if (auto [flag, configPath] = getOrCreateConfigPath(); flag)
    {
        toml::parse_result result = toml::parse_file(configPath);
        if (!result)
        {
            std::string reason{ result.error().description() };
            acutPrintf(_T("\nError to parse config %ls  %ls: "), __FUNCTIONW__, utf8_to_wstr(reason).c_str());
            return 2;
        }
        auto table = std::move(result).table();
        auto optimization_level = table["system"]["optimization_level"];
        if (optimization_level.is_integer())
            return int32_t(optimization_level.value_or(2));
        else
            acutPrintf(_T("\nError optimization_level not found %ls: "), __FUNCTIONW__);

    }
    return 2;
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