#include "stdafx.h"
#include "PyRxAppSettings.h"
#include "PyRxApp.h"

//https://marzer.github.io/tomlplusplus/
#define TOML_EXCEPTIONS 0
#define TOML_HEADER_ONLY 1
#include "toml.h"

_locale_t& pyrx_locale()
{
    // TODO: set form OS? or pyrx_config 
    // this is only used in toupper & tolower
    static _locale_t pyrx_locale = _create_locale(LC_ALL, "en_US.UTF-8");
    return pyrx_locale;
}


constexpr const wchar_t* pyrx_config_name = L"pyrx.toml";

const std::tuple<bool, std::wstring> PyRxAppSettings::tryFindConfigPath()
{
    std::error_code ec;
    if (const auto roamingPath = PyRxApp::getAppDataPath() / pyrx_config_name; std::filesystem::exists(roamingPath, ec))
        return std::make_tuple(true, roamingPath);
    return std::make_tuple(false, std::wstring{ });
}

static auto pyrxConfig() -> std::pair<bool, toml::table>
{
    static std::pair<bool, toml::table> item;
    if (item.first == false)
    {
        if (auto [flag, configPath] = PyRxAppSettings::tryFindConfigPath(); flag)
        {
            toml::parse_result result = toml::parse_file(configPath);
            if (result)
            {
                item.first = true;
                item.second = std::move(result).table();
            }
        }
    }
    return item;
}

int PyRxAppSettings::optimizationLevel()
{
    std::wstring buffer(5, 0);
    if (GetEnvironmentVariable(_T("PYRX_OPTIMIZATION_LEVEL"), buffer.data(), buffer.size()))
    {
        return std::stoi(buffer);
    }
    if (auto [flag, table] = pyrxConfig(); flag)
    {
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
