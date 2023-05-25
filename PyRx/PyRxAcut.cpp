#include "stdafx.h"
#include "PyRxAcut.h"

const char* PyRxAcut::PrintfDoc()
{
    return "Wraps acutPrintf \nSends a string to the command line";
}

PyObject* PyRxAcut::Printf(PyObject* self, PyObject* args)
{
    PyObject* obj = NULL, * strobj = NULL;

    if (!PyArg_ParseTuple(args, "O:Printf()", &obj))
        return NULL;

    if (PyUnicode_Check(obj))
        strobj = obj;
    else
        strobj = PyObject_Str(obj);

    if (const wchar_t* text = PyUnicode_AsWideCharString(strobj, nullptr); text != nullptr)
        acutPrintf(text);

    if (strobj != obj)
        Py_DECREF(strobj);
    Py_INCREF(Py_None);
    return Py_None;
}

