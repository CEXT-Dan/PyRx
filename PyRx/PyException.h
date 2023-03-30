#pragma once
#include <exception>

struct PyNotThatKindOfClass
{
    static void translator(PyNotThatKindOfClass const& x)
    {
        PyErr_SetString(PyExc_RuntimeError, "\nNot that kind of class!");
    }
};

struct PyNullObject
{
    static void translator(PyNullObject const& x)
    {
        PyErr_SetString(PyExc_RuntimeError, "\nObject is null!");
    }
};

struct PyEditorError
{
    static void translator(PyEditorError const& x)
    {
        PyErr_SetString(PyExc_RuntimeError, "\nEditor error!");
    }
};

struct PyNotimplementedByHost
{
    static void translator(PyNotimplementedByHost const& x)
    {
#ifdef ARXAPP
        PyErr_SetString(PyExc_RuntimeError, "\nException, Not implemented in ARX");
#endif
#ifdef BRXAPP
        PyErr_SetString(PyExc_RuntimeError, "\nException, Not implemented in BRX");
#endif
#ifdef GRXAPP
        PyErr_SetString(PyExc_RuntimeError, "\nException, Not implemented in GRX");
#endif
#ifdef ZRXAPP
        PyErr_SetString(PyExc_RuntimeError, "\nException, Not implemented in ZRX");
#endif
    }
};

