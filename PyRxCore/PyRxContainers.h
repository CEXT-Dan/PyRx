#pragma once

class LoadedPaths
{
public:
    bool contains(const std::wstring& path);
    bool contains(const std::filesystem::path& path);

    void insert(const std::wstring& path);
    void insert(const std::filesystem::path& path);

public:
    std::unordered_set<std::wstring> m_paths;
};