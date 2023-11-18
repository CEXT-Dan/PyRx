#include "stdafx.h"
#include "PyLispService.h"
#include "ResultBuffer.h"
#include "PyRxApp.h"
using namespace boost::python;

//TODO set current directory...
int PyLispService::execLispFunc()
{
    try
    {
        const int fcode = acedGetFunCode();
        if (fcode == -1 || fcode == RTERROR)
            return RSERR;
        const auto& lisplispService = PyRxApp::instance().lispService;
        if (lisplispService.lispFuncCodes.contains(fcode))
        {
            PyAutoLockGIL lock;
            auto method = lisplispService.lispFuncCodes.at(fcode);
            if (PyCallable_Check(method))
            {
                PyErr_Clear();
                const boost::python::list& args = resbufToList(acedGetArgs());
                PyObjectPtr pResult(PyObject_CallOneArg(method, args.ptr()));
                if (pResult == nullptr)
                {
                    acedRetNil();
                    return RSERR;
                }
                else if (pResult.get() == Py_None)
                {
                    acedRetNil();
                    return RSRSLT;
                }
                else if (PyList_Check(pResult.get()))
                {
                    boost::python::handle<> resultHandle(pResult.get());
                    if (resultHandle == nullptr)
                    {
                        acedRetNil();
                        return RSERR;
                    }
                    boost::python::list reslist(resultHandle);
                    pResult.release();
                    if (reslist.is_none())
                    {
                        acedRetNil();
                        return RSRSLT;
                    }
                    AcResBufPtr ptr(listToResbuf(reslist));
                    if (ptr != nullptr)
                        acedRetList(ptr.get());

                }
                else if (PyBool_Check(pResult.get()))
                {
                    const bool val = extract<bool>(pResult.get());
                    val ? acedRetT() : acedRetNil();
                    return RSRSLT;
                }
                else if (PyLong_Check(pResult.get()))
                {
                    const int val = extract<int32_t>(pResult.get());
                    acedRetInt(val);
                    return RSRSLT;
                }
                else if (PyFloat_Check(pResult.get()))
                {
                    const double val = extract<double>(pResult.get());
                    acedRetReal(val);
                    return RSRSLT;
                }
                else if (extract<AcGePoint2d>(pResult.get()).check())
                {
                    const AcGePoint2d p = extract<AcGePoint2d>(pResult.get());
                    const AcGePoint3d val(p.x, p.y, 0);
                    acedRetPoint(asDblArray(val));
                    return RSRSLT;
                }
                else if (extract<AcGePoint3d>(pResult.get()).check())
                {
                    const AcGePoint3d val = extract<AcGePoint3d>(pResult.get());
                    acedRetPoint(asDblArray(val));
                    return RSRSLT;
                }
                else if (extract<char*>(pResult.get()).check())
                {
                    const AcString str = utf8_to_wstr(extract<char*>(pResult.get())).c_str();
                    acedRetStr(str);
                    return RSRSLT;
                }
                else
                {
                    acedRetT();
                    return RSRSLT;
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
    constexpr const int startFunCode = 16383;
    const AcString lispFuncName = pythonFuncName.substr(PyLispFuncPrefix.length(), pythonFuncName.length() - 1);
    if (PyFunction_Check(method))
    {
        if (lispFuncs.contains(lispFuncName))
        {
            const funcode code = lispFuncs.at(lispFuncName);
            lispFuncCodes[code] = method;
        }
        else
        {
            const funcode code = lispFuncCodes.size() + startFunCode;
            lispFuncs.emplace(lispFuncName, code);
            lispFuncCodes.emplace(code, method);
            if (int res = acedDefun(lispFuncName, code); res != RTNORM)
                acutPrintf(_T("\nFailed @ tryAddFunc acedDefun"));
            if (int res = acedRegFunc(PyLispService::execLispFunc, code); res != RTNORM)
                acutPrintf(_T("\nFailed @ tryAddFunc ads_regfunc"));
        }
        return lispFuncs.size() == lispFuncCodes.size();
    }
    return false;
}

void PyLispService::On_kLoadDwgMsg()
{
    if (lispFuncs.size() == lispFuncCodes.size())
    {
        for (const auto& item : lispFuncs)
        {
            if (int res = acedDefun(item.first, item.second);  res != RTNORM)
                acutPrintf(_T("\nFailed @ On_kLoadDwgMsg acedDefun"));
            if (int res = acedRegFunc(PyLispService::execLispFunc, item.second); res != RTNORM)
                acutPrintf(_T("\nFailed @ On_kLoadDwgMsg ads_regfunc"));
        }
    }
}

void PyLispService::cleanup()
{
    WxPyAutoLock lock;
    for (const auto& item : lispFuncCodes)
    {
        Py_DecRef(item.second);
    }
    lispFuncCodes.clear();
}
