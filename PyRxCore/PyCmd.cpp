#include "stdafx.h"
#include "PyCmd.h"

int PyCmd::getCommandFlags(AcString& str)
{
    if (str.length() < 3) //we may get the function '()'
        return 1;
    if (str.find(PyCommandFlagPrefix) == -1)
        return 1;
    AcString sflag = str.substr(PyCommandFlagPrefix.length() + 1, str.length() - 1);
    return _wtoi(sflag);
}

int PyCmd::getCommandFlags(PyObject* pCommand)
{
    PyAutoLockGIL lock;

    if (pCommand == nullptr)
        return 1;

    //TODO: maybe leave this module imported for the session?
    PyObjectPtr inspect(PyImport_ImportModule("inspect"));
    if (inspect == nullptr)
        return 1;
    PyObjectPtr func(PyObject_GetAttrString(inspect.get(), "signature"));
    if (func == nullptr)
        return 1;
    if (PyCallable_Check(func.get()) == 0)
        return 1;
    PyObjectPtr args(PyTuple_Pack(1, pCommand));
    if (args == nullptr)
        return 1;
    PyObjectPtr res(PyObject_CallObject(func.get(), args.get()));
    if (res == nullptr)
        return 1;
    PyObjectPtr objStr(PyObject_Str(res.get()));
    if (res == nullptr)
        return 1;
    AcString strFlags = PyUnicode_AsWideCharString(objStr.get(), nullptr);
    strFlags.makeLower();
    return getCommandFlags(strFlags);
}
