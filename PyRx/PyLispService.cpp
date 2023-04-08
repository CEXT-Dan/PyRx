#include "stdafx.h"
#include "PyLispService.h"
#include "ResultBuffer.h"

int PyLispService::execLispFunc()
{
    try
    {
        int fcode = acedGetFunCode();
        auto& lisplispService = PyRxApp::instance().lispService;
        if (lisplispService.lispFuncCodes.contains(fcode))
        {
            auto method = lisplispService.lispFuncCodes.at(fcode);
            if (PyCallable_Check(method))
            {
                boost::python::list args = resbufToList(acedGetArgs());
                PyObjectPtr ptr(PyObject_CallFunctionObjArgs(method, args, NULL));
                if (ptr == nullptr)
                {
                    acedRetT();
                    return RSRSLT;
                }
                else if (ptr.get() == Py_None)
                {
                    acedRetT();
                    return RSRSLT;
                }
                if (!PyList_Check(ptr.get()))//lists only for now
                {
                    acutPrintf(_T("\nNot a list: "));
                    acedRetNil();
                    return RSERR;
                }
                boost::python::handle<> rslt(ptr.get());
                if (rslt != nullptr)
                {
                    boost::python::list reslist(rslt);
                    ptr.release();// boost owns it from here
                    if (reslist.is_none())
                    {
                        acedRetT();
                        return RSRSLT;
                    }
                    AcResBufPtr ptr(listToResbuf(reslist));
                    if (ptr != nullptr)
                    {
                        acedRetList(ptr.get());
                    }
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
    AcString lispFuncName = pythonFuncName.substr(PyLispFuncPrefix.length(), pythonFuncName.length() - 1);
    if (PyFunction_Check(method))
    {
        if (lispFuncs.contains(lispFuncName))
        {
            funcode code = lispFuncs.at(lispFuncName);
            lispFuncCodes[code] = method;
        }
        else
        {
            funcode code = lispFuncCodes.size();
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
