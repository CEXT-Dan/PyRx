#include "stdafx.h"
#include "PyCmd.h"

int PyCmd::getCommandFlagsByName(AcString& str)
{
    if (str.find(_T("MODAL")) != -1)
        return ACRX_CMD_MODAL;
    else if (str.find(_T("TRANSPARENT")) != -1)
        return ACRX_CMD_TRANSPARENT;
    else if (str.find(_T("USEPICKSET")) != -1)
        return ACRX_CMD_USEPICKSET;
    else if (str.find(_T("REDRAW")) != -1)
        return ACRX_CMD_REDRAW;
    else if (str.find(_T("NOPERSPECTIVE")) != -1)
        return ACRX_CMD_NOPERSPECTIVE;
    else if (str.find(_T("NOMULTIPLE")) != -1)
        return ACRX_CMD_NOMULTIPLE;
    else if (str.find(_T("NOTILEMODE")) != -1)
        return ACRX_CMD_NOTILEMODE;
    else if (str.find(_T("NOPAPERSPACE")) != -1)
        return ACRX_CMD_NOPAPERSPACE;
    else if (str.find(_T("DEPRECATED")) != -1)
#ifdef BRXAPP
        return 1;
#else
        return ACRX_CMD_DEPRECATED;
#endif
    else if (str.find(_T("NOOEM")) != -1)
        return ACRX_CMD_NOOEM;
    else if (str.find(_T("UNDEFINED")) != -1)
        return ACRX_CMD_UNDEFINED;
    else if (str.find(_T("INPROGRESS")) != -1)
        return ACRX_CMD_INPROGRESS;
    else if (str.find(_T("DEFUN")) != -1)
        return ACRX_CMD_DEFUN;
    else if (str.find(_T("NOINTERNALLOCK")) != -1)
        return ACRX_CMD_NOINTERNALLOCK;
    else if (str.find(_T("DOCREADLOCK")) != -1)
        return ACRX_CMD_DOCREADLOCK;
    else if (str.find(_T("DOCEXCLUSIVELOCK")) != -1)
        return ACRX_CMD_DOCEXCLUSIVELOCK;
    else if (str.find(_T("SESSION")) != -1)
        return ACRX_CMD_SESSION;
    else if (str.find(_T("INTERRUPTIBLE")) != -1)
        return ACRX_CMD_INTERRUPTIBLE;
    else if (str.find(_T("NOHISTORY")) != -1)
        return ACRX_CMD_NOHISTORY;
    else if (str.find(_T("NO_UNDO_MARKER")) != -1)
        return ACRX_CMD_NO_UNDO_MARKER;
    else if (str.find(_T("CMD_NOBEDIT")) != -1)
        return ACRX_CMD_NOBEDIT;
    else if (str.find(_T("NOACTIONRECORDING")) != -1)
#ifdef BRXAPP
        return 1;
#else
        return ACRX_CMD_NOACTIONRECORDING;
#endif
    else if (str.find(_T("ACTIONMACRO")) != -1)
#ifdef BRXAPP
        return 1;
#else
        return ACRX_CMD_ACTIONMACRO;
#endif
    else if (str.find(_T("RELAXASSOC")) != -1)
#ifdef BRXAPP
        return 1;
#else
        return ACRX_CMD_RELAXASSOC;
#endif
    else if (str.find(_T("NOINFERCONSTRAINT")) != -1)
#ifdef BRXAPP
        return 1;
#else
        return ACRX_CMD_NOINFERCONSTRAINT;
#endif
    else if (str.find(_T("TEMPSHOWDYNDIM")) != -1)
#ifdef BRXAPP
        return 1;
#else
        return ACRX_CMD_TEMPSHOWDYNDIM;
#endif
    return -1;
}

int PyCmd::getCommandFlags(AcString& str)
{
    if (str.length() < 3) //we may get the function '()'
        return 1;
    int flag = getCommandFlagsByName(str);
    if (flag != -1)
        return flag;
#ifndef BRXAPP
    str.remove();
#endif // !BRXAPP
    if (str.find(PyCommandFlagPrefix) == -1)
        return 1;
    AcString sflag = str.substr(PyCommandFlagPrefix.length() + 1, str.length() - 1);
#ifdef BRXAPP
    CString csFlag = (const TCHAR*)sflag;
    csFlag.TrimRight(')');
    return _wtoi(csFlag);
#else
    return _wtoi(sflag);
#endif // !BRXAPP
}

int PyCmd::getCommandFlags(PyObject* pCommand)
{
    WxPyAutoLock lock;

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
    return getCommandFlags(strFlags);
}
