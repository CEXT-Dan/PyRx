#pragma once
class PyRxINI
{
public:

    static const std::filesystem::path& iniPath();
    static const std::tuple<bool, bool> pythonIsolated();
    static const std::tuple<bool, std::wstring> pythonvenv_path();
};

