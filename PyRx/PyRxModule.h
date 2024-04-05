#pragma once

//------------------------------------------------------------------------------------------------
//  PyModulePath command path and name
struct PyModulePath
{
    AcString moduleName;
    std::wstring modulePath;
    std::filesystem::path fullPath;
};

//------------------------------------------------------------------------------------------------
//  PyRxMethod holds command objects
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
    PyObject* OnPyReload = nullptr;
};


class PyRxModule
{
public:
    static AcString commandForCurDocument();
    static void callPyFunction();
    static void regCommand(const AcString& moduleName, const AcString& name, int context);
};

