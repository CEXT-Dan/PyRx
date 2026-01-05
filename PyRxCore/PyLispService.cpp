#include "stdafx.h"
#include "PyLispService.h"
#include "ResultBuffer.h"
#include "PyRxApp.h"
#include "PyDbObjectId.h"
#include "PyEdSelectionSet.h"

using namespace boost::python;

static int retTuple(const boost::python::tuple& tpl)
{
    int code = extract<int>(tpl[0]);
    if (code < 5000)
    {
        int _code = code == 0 ? RTDXF0 : code;
        switch (acdbGroupCodeToType(_code))
        {
            case AcDb::kDwgText:
            {
                AcString str = utf8_to_wstr(extract<char*>(tpl[1])).c_str();
                acedRetStr(str);
                return RSRSLT;
            }
            case AcDb::kDwgInt8:
            {
                int val = extract<int>(tpl[1]);
                acedRetInt(val);
                return RSRSLT;
            }
            case AcDb::kDwgInt16:
            {
                int val = extract<int>(tpl[1]);
                acedRetInt(val);
                return RSRSLT;
            }
            case AcDb::kDwgInt32:
            {
                int val = extract<int>(tpl[1]);
                acedRetInt(val);
                return RSRSLT;
            }
            case AcDb::kDwgReal:
            {
                double val = extract<double>(tpl[1]);
                acedRetReal(val);
                return RSRSLT;
            }
            case AcDb::kDwg3Real:
            {
                if (extract<AcGePoint3d>(tpl[1]).check())
                    acedRetPoint(asDblArray(extract<AcGePoint3d>(tpl[1])));
                else if (extract<AcGeVector3d>(tpl[1]).check())
                    acedRetPoint(asDblArray(extract<AcGeVector3d>(tpl[1])));
                return RSRSLT;
            }
            case AcDb::kDwgHandle:
            case AcDb::kDwgHardOwnershipId:
            case AcDb::kDwgSoftOwnershipId:
            case AcDb::kDwgHardPointerId:
            case AcDb::kDwgSoftPointerId:
            {
                ads_name name = { 0L };
                PyDbObjectId id = extract<PyDbObjectId>(tpl[1]);
                acdbGetAdsName(name, id.m_id);
                acedRetName(name, RTENAME);
                return RSRSLT;
            }
        }
    }
    else
    {
        switch (code)
        {
            case RTT:
            {
                acedRetT();
                return RSRSLT;
            }
            case RTNIL:
            {
                acedRetNil();
                return RSRSLT;
            }
            case RTANG:
            case RTREAL:
            {
                const double val = extract<double>(tpl[1]);
                acedRetReal(val);
                return RSRSLT;
            }
            case RTORINT:
            case RT3DPOINT:
            {
                if (extract<AcGePoint3d>(tpl[1]).check())
                    acedRetPoint(asDblArray(extract<AcGePoint3d>(tpl[1])));
                else if (extract<AcGeVector3d>(tpl[1]).check())
                    acedRetPoint(asDblArray(extract<AcGeVector3d>(tpl[1])));
                return RSRSLT;
            }
            case RTPOINT:
            {
                if (extract<AcGePoint2d>(tpl[1]).check())
                {
                    const AcGePoint2d& p = extract<AcGePoint2d>(tpl[1]);
                    const AcGePoint3d val(p.x, p.y, 0);
                    acedRetPoint(asDblArray(val));
                }
                else if (extract<AcGeVector2d>(tpl[1]).check())
                {
                    const AcGeVector2d& p = extract<AcGeVector2d>(tpl[1]);
                    const AcGePoint3d val(p.x, p.y, 0);
                    acedRetPoint(asDblArray(val));
                }
                return RSRSLT;
            }
            case RTSHORT:
            {
                const short val = extract<int>(tpl[1]);
                acedRetInt(val);
                return RSRSLT;
            }
            case RTLONG:
            {
                const int val = extract<int>(tpl[1]);
                acedRetInt(val);
                return RSRSLT;
            }
            case RTLONG_PTR:
            case RTINT64:
            {
                const int64_t val = extract<int64_t>(tpl[1]);
                acedRetInt(int(val));
                return RSRSLT;
            }
            case RTSTR:
            {
                const AcString str = utf8_to_wstr(extract<char*>(tpl[1])).c_str();
                acedRetStr(str);
                return RSRSLT;
            }
            case RTPICKS:
            {
                PyEdSelectionSet ss = extract<PyEdSelectionSet>(tpl[1]);
                const AdsName& pyssname = ss.adsname();
                acedRetName(ads_name{ pyssname.m_data[0], pyssname.m_data[1] }, RTPICKS);
                return RSRSLT;
            }
            case RTENAME:
            {
                ads_name name = { 0L };
                const PyDbObjectId id = extract<PyDbObjectId>(tpl[1]);
                acdbGetAdsName(name, id.m_id);
                acedRetName(name, RTENAME);
                return RSRSLT;
            }
        }
    }
    acutPrintf(L"\nInvalid input in retTuple");
    return RSRSLT;
}


//TODO set current directory...
int PyLispService::execLispFunc()
{
    try
    {
        auto& rxApp = PyRxApp::instance();
        const auto& lisplispService = rxApp.lispService;
        const int fcode = acedGetFunCode();

        if (fcode == -1 || fcode == RTERROR)
            return RSERR;
        if (lisplispService.lispFuncCodes.contains(fcode))
        {
            if (rxApp.pathForLispFunc.contains(fcode))
            {
                std::error_code _Ec;
                std::filesystem::current_path(rxApp.pathForLispFunc.at(fcode), _Ec);
            }
            PyAutoLockGIL lock;
            auto method = lisplispService.lispFuncCodes.at(fcode);
            if (PyCallable_Check(method))
            {
                PyErr_Clear();
                const boost::python::list& args = resbufToList(acedGetArgs());
                PyObjectPtr pResult(PyObject_CallOneArg(method, args.ptr()));
                if (pResult == nullptr)
                {
                    acedRetVoid();
                    return RSERR;
                }
                else if (pResult.get() == Py_None)
                {
                    acedRetVoid();
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
                    return RSRSLT;
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
                    const AcGePoint2d& p = extract<AcGePoint2d>(pResult.get());
                    const AcGePoint3d val(p.x, p.y, 0);
                    acedRetPoint(asDblArray(val));
                    return RSRSLT;
                }
                else if (extract<AcGePoint3d>(pResult.get()).check())
                {
                    acedRetPoint(asDblArray(extract<AcGePoint3d>(pResult.get())));
                    return RSRSLT;
                }
                else if (extract<PyDbObjectId>(pResult.get()).check())
                {
                    const PyDbObjectId val = extract<PyDbObjectId>(pResult.get());
                    ads_name name;
                    acdbGetAdsName(name, val.m_id);
                    acedRetName(name, RTENAME);
                    return RSRSLT;
                }
                else if (extract<char*>(pResult.get()).check())
                {
                    const AcString str = utf8_to_wstr(extract<char*>(pResult.get())).c_str();
                    acedRetStr(str);
                    return RSRSLT;
                }
                else if (extract<PyEdSelectionSet>(pResult.get()).check())
                {
                    PyEdSelectionSet ss = extract<PyEdSelectionSet>(pResult.get());
                    const AdsName& pyssname = ss.adsname();
                    acedRetName(ads_name{ pyssname.m_data[0], pyssname.m_data[1] }, RTPICKS);
                    return RSRSLT;
                }
                else if (extract<tuple>(pResult.get()).check())
                {
                    tuple tpl = extract<tuple>(pResult.get());
                    if (boost::python::len(tpl) == 2)
                        return retTuple(tpl);
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
    // warn the user and clear, otherwise things get wonky 
    {
        PyAutoLockGIL lock;
        PyErr_Clear();
    }
    return RSERR;
}


bool PyLispService::tryAddFunc(const std::filesystem::path& fpath, const AcString& pythonFuncName, PyObject* method)
{
    PyAutoLockGIL lock;
    // TODO: we can start from the first unused code for the hinstance, something like 10
    constexpr const int startFunCode = 16383;
    AcString lispFuncName;
    if (pythonFuncName.find(PyLispFuncPrefix) != -1)
        lispFuncName = pythonFuncName.substr(PyLispFuncPrefix.length(), pythonFuncName.length() - 1);
    else
        lispFuncName = pythonFuncName;
    if (PyFunction_Check(method))
    {
        if (lispFuncs.contains(lispFuncName))
        {
            const funcode code = lispFuncs.at(lispFuncName);
            lispFuncCodes[code] = method;
        }
        else
        {
            auto& rxApp = PyRxApp::instance();
            const funcode code = lispFuncCodes.size() + startFunCode;
            lispFuncs.emplace(lispFuncName, code);
            lispFuncCodes.emplace(code, method);
            if (int res = acedDefun(lispFuncName, code); res != RTNORM)
                acutPrintf(_T("\nFailed @ tryAddFunc acedDefun"));
            if (int res = acedRegFunc(PyLispService::execLispFunc, code); res != RTNORM)
                acutPrintf(_T("\nFailed @ tryAddFunc ads_regfunc"));
            if (rxApp.pathForLispFunc.contains(code))
                rxApp.pathForLispFunc.at(code) = fpath;
            else
                rxApp.pathForLispFunc.emplace(code, fpath);
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
    PyAutoLockGIL lock;
    for (const auto& item : lispFuncCodes)
    {
        Py_DecRef(item.second);
    }
    lispFuncCodes.clear();
}
