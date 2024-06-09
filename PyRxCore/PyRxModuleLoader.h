#pragma once
#pragma pack (push, 8)
struct PyModulePath;

bool showNavFileDialog(PyModulePath& path);
bool loadPythonModule(const PyModulePath& path, bool silent, bool skipReactors);
bool reloadPythonModule(const PyModulePath& path, bool silent);
bool ads_loadPythonModule(const std::filesystem::path& pypath, bool skipReactors);
bool ads_reloadPythonModule(const std::filesystem::path& pypath);
#pragma pack (pop)