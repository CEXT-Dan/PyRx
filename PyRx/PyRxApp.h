#pragma once

PyMODINIT_FUNC PyInitPyRxModule(void);

using PyObjectPtr = std::unique_ptr < PyObject, decltype([](PyObject* ptr) noexcept
{
    Py_XDECREF(ptr);
}) > ;


struct PyRxMethod
{
    PyObjectPtr modname;
    PyObjectPtr mod;
    PyObjectPtr rslt;

    //TODO: had problems using PyObjectPtr on these
    PyObject* mdict = nullptr;
    PyObject* OnPyInitApp = nullptr;
    PyObject* OnPyUnloadApp = nullptr;
    PyObject* OnPyLoadDwg = nullptr;
    PyObject* OnPyUnloadDwg = nullptr;
};

class PyRxApp
{
public:
    bool init();
    bool uninit();
    static bool setPyConfig();
    static bool pyRxAppendSearchPath(const TCHAR* pModulePath);
    static std::wstring the_error();
    static std::filesystem::path modulePath();
    static PyRxApp& instance();
public:

    using FuncNameMap = std::map<AcString, PyRxMethod>;
    FuncNameMap fnm;

    using LoadedPaths = std::set<std::filesystem::path>;
    LoadedPaths loadedModulePaths;

    using CmdNameMap = std::map<AcString, PyObject*>;
    CmdNameMap commands;

    bool isLoaded = false;
};

