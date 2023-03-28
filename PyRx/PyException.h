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



