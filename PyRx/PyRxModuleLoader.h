#pragma once
struct PyModulePath;

bool showNavFileDialog(PyModulePath& path);
bool loadPythonModule(const PyModulePath& path, bool silent);
bool reloadPythonModule(const PyModulePath& path, bool silent);
bool ads_loadPythonModule(const std::filesystem::path& pypath);