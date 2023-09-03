#include "stdafx.h"
#include "PyLispService.h"
#include "ResultBuffer.h"
#include "PyRxApp.h"

//TODO set current directory...
int PyLispService::execLispFunc()
{
    try
    {
        PyAutoLockGIL lock;
        const int fcode = acedGetFunCode();
        auto& lisplispService = PyRxApp::instance().lispService;
        if (lisplispService.lispFuncCodes.contains(fcode))
        {
            WxPyAutoLock lock;
            auto method = lisplispService.lispFuncCodes.at(fcode);
            if (PyCallable_Check(method))
            {
                const boost::python::list& args = resbufToList(acedGetArgs());
                PyObjectPtr pResult(PyObject_CallOneArg(method, args.ptr()));
                if (pResult == nullptr)
                {
                    acedRetT();
                    return RSRSLT;
                }
                else if (pResult.get() == Py_None)
                {
                    acedRetT();
                    return RSRSLT;
                }
                if (!PyList_Check(pResult.get()))//lists only for now
                {
                    acutPrintf(_T("\nNot a list: "));
                    acedRetNil();
                    return RSERR;
                }
                boost::python::handle<> resultHandle(pResult.get());
                if (resultHandle != nullptr)
                {
                    boost::python::list reslist(resultHandle);
                    pResult.release();// boost owns it from here
                    if (reslist.is_none())
                    {
                        acedRetT();
                        return RSRSLT;
                    }
                    AcResBufPtr ptr(listToResbuf(reslist));
                    if (ptr != nullptr)
                        acedRetList(ptr.get());
                }
            }
        }
    }
    catch (...)
    {
        acutPrintf(_T("\npyfunc failed: "));
    }
    return RSRSLT;
}

bool PyLispService::tryAddFunc(const AcString& pythonFuncName, PyObject* method)
{
    WxPyAutoLock lock;
    const AcString lispFuncName = pythonFuncName.substr(PyLispFuncPrefix.length(), pythonFuncName.length() - 1);
    if (PyFunction_Check(method))
    {
        if (lispFuncs.contains(lispFuncName))
        {
            funcode code = lispFuncs.at(lispFuncName);
            lispFuncCodes[code] = method;
        }
        else
        {
            funcode code = lispFuncCodes.size() +1;
            lispFuncs.emplace(lispFuncName, code);
            lispFuncCodes.emplace(code, method);
            acedDefun(lispFuncName, code);
            ads_regfunc(PyLispService::execLispFunc, code);
        }
        return lispFuncs.size() == lispFuncCodes.size();
    }
    return false;
}

void PyLispService::On_kLoadDwgMsg()
{
    if (lispFuncs.size() == lispFuncCodes.size())
    {
        for (auto& item : lispFuncs)
        {
            acedDefun(item.first, item.second);
            ads_regfunc(PyLispService::execLispFunc, item.second);
        }
    }
}

void PyLispService::cleanup()
{
    WxPyAutoLock lock;
    for (auto& item : lispFuncCodes)
    {
        auto& val = item.second;
        Py_DecRef(val);
    }
    lispFuncCodes.clear();
}
