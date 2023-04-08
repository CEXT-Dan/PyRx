#pragma once
#include "PyLispService.h"

PyMODINIT_FUNC PyInitPyRxModule(void);

using PyObjectPtr = std::unique_ptr < PyObject, decltype([](PyObject* ptr) noexcept
{
    Py_XDECREF(ptr);
}) > ;


template<typename T>
inline std::vector< T > py_list_to_std_vector(const boost::python::object& iterable)
{
    return std::vector< T >(boost::python::stl_input_iterator< T >(iterable),
        boost::python::stl_input_iterator< T >());
}


template <class T>
inline boost::python::list std_vector_to_py_list(std::vector<T> vector) {
    typename std::vector<T>::iterator iter;
    boost::python::list list;
    for (iter = vector.begin(); iter != vector.end(); ++iter) {
        list.append(*iter);
    }
    return list;
}

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
    using CmdLispMap = std::map<int, AcString>;

    CmdNameMap commands;
    PyLispService lispService;

    bool isLoaded = false;
};

