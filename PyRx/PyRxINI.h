#pragma once
class PyRxINI
{
public:

    static std::filesystem::path iniPath();
    static std::tuple<bool, bool> pythonIsolated();
    static std::tuple<bool, std::wstring> pythonvenv_path();
};

