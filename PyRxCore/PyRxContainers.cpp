#include "stdafx.h"
#include "PyRxContainers.h"

bool LoadedPaths::contains(const std::wstring& path)
{
    return m_paths.contains(tolower(path));
}

bool LoadedPaths::contains(const std::filesystem::path& path)
{
    return m_paths.contains(tolower(path));
}

void LoadedPaths::insert(const std::wstring& path)
{
    m_paths.insert(tolower(path));
}

void LoadedPaths::insert(const std::filesystem::path& path)
{
    m_paths.insert(tolower(path));
}
