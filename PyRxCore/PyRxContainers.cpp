#include "stdafx.h"
#include "PyRxContainers.h"

bool LoadedPaths::contains(const std::wstring& path)
{
    return m_paths.contains(towlower(path));
}

bool LoadedPaths::contains(const std::filesystem::path& path)
{
    return m_paths.contains(towlower(path));
}

void LoadedPaths::insert(const std::wstring& path)
{
    m_paths.insert(towlower(path));
}

void LoadedPaths::insert(const std::filesystem::path& path)
{
    m_paths.insert(towlower(path));
}
