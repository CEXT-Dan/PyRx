#pragma once
#include "stdafx.h"
#include "PyLispService.h"

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

    void cleanUpCommands();
    using FuncNameMap = std::map<AcString, PyRxMethod>;
    FuncNameMap funcNameMap;

    using LoadedPaths = std::set<std::filesystem::path>;
    LoadedPaths loadedModulePaths;

    using CmdNameMap = std::map<AcString, PyObject*>;
    using CmdLispMap = std::map<int, AcString>;
    using PathForCommand = std::map<AcString, std::filesystem::path>;

    CmdNameMap commands;
    PyLispService lispService;
    PathForCommand pathForCommand;

    bool isLoaded = false;
};

PyMODINIT_FUNC PyInitPyRxModule(void);
