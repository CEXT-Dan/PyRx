#pragma once
 
class PyRxAced
{
public:
    static const char* GetStringDoc();
    static PyObject* GetString(PyObject* self, PyObject* args);

    static const char* GetVarDoc();
    static PyObject* GetVar(PyObject* self, PyObject* args);

    static const char* SetVarDoc();
    static PyObject* SetVar(PyObject* self, PyObject* args);
};

