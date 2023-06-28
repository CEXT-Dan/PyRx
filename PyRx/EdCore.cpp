#include "stdafx.h"
#include "EdCore.h"
#include "PyDbObjectId.h"
#include "PyDbDatabase.h"
#include "ResultBuffer.h"

#include "acedCmdNF.h"

using namespace boost::python;

#ifdef ARXAPP
extern "C" bool acedGetPredefinedPattens(AcStringArray & patterns);
#endif

//-----------------------------------------------------------------------------------------
//helpers

//-----------------------------------------------------------------------------------------
//EdCore
void makeEdCoreWrapper()
{
    class_<EdCore>("Core")
        .def("alert", &EdCore::alert).staticmethod("alert")
        .def("arxLoad", &EdCore::arxLoad).staticmethod("arxLoad")
        .def("arxLoaded", &EdCore::arxLoaded).staticmethod("arxLoaded")
        .def("arxUnload", &EdCore::arxUnload).staticmethod("arxUnload")
        .def("audit", &EdCore::audit1)//.staticmethod("audit")
        .def("audit", &EdCore::audit2).staticmethod("audit")
        .def("callBackOnCancel", &EdCore::callBackOnCancel).staticmethod("callBackOnCancel")
        .def("clearOLELock", &EdCore::clearOLELock).staticmethod("clearOLELock")
        .def("xrefDetach", &EdCore::xrefDetach1)//.staticmethod("xrefDetach")
        .def("xrefDetach", &EdCore::xrefDetach2).staticmethod("xrefDetach")
        .def("cmdS", &EdCore::cmdS).staticmethod("cmdS")
        .def("findFile", &EdCore::findFile).staticmethod("findFile")
        .def("findTrustedFile", &EdCore::findTrustedFile).staticmethod("findTrustedFile")
        .def("getPredefinedHatchPatterns", &EdCore::getPredefinedPattens).staticmethod("getPredefinedHatchPatterns")
        .def("getFileD", &EdCore::getFileD).staticmethod("getFileD")
        .def("getFileNavDialog", &EdCore::getFileNavDialog).staticmethod("getFileNavDialog")
        .def("getVar", &EdCore::getVar).staticmethod("getVar")
        .def("setVar", &EdCore::setVar).staticmethod("setVar")
        .def("mSpace", &EdCore::mSpace).staticmethod("mSpace")
        .def("pSpace", &EdCore::pSpace).staticmethod("pSpace")

        .def("xrefResolve", &EdCore::xrefResolve1)
        .def("xrefResolve", &EdCore::xrefResolve2).staticmethod("xrefResolve")
        .def("xrefUnload", &EdCore::xrefUnload1)
        .def("xrefUnload", &EdCore::xrefUnload2).staticmethod("xrefUnload")
        .def("xrefXBind", &EdCore::xrefXBind1)
        .def("xrefXBind", &EdCore::xrefXBind2).staticmethod("xrefXBind")
        ;
}

int EdCore::alert(const std::string& msg)
{
    return acedAlert(utf8_to_wstr(msg).c_str());
}

int EdCore::arxLoad(const std::string& msg)
{
    return acedArxLoad(utf8_to_wstr(msg).c_str());
}

boost::python::list EdCore::arxLoaded()
{
    PyAutoLockGIL lock;
    AcResBufPtr pLoaded(acedArxLoaded());
    return resbufToList(pLoaded.get());
}

int EdCore::arxUnload(const std::string& app)
{
    return acedArxUnload(utf8_to_wstr(app).c_str());
}

Acad::ErrorStatus EdCore::audit1(PyDbDatabase& pDb, bool bFixErrors)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return acedAudit(pDb.impObj(), bFixErrors);
#endif
}

Acad::ErrorStatus EdCore::audit2(PyDbDatabase& pDb, bool bFixErrors, bool bCmdLnEcho)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return acedAudit(pDb.impObj(), bFixErrors, bCmdLnEcho);
#endif
}

void EdCore::callBackOnCancel()
{
    acedCallBackOnCancel();
}

bool EdCore::clearOLELock(int handle)
{
    return acedClearOLELock(handle);
}

bool EdCore::cmdS(const boost::python::list& lst)
{
    AcResBufPtr pcmd(listToResbuf(lst));
    return acedCmdS(pcmd.get()) == RTNORM;
}

std::string EdCore::findFile(const std::string& file)
{
    std::array<wchar_t, MAX_PATH> data;
    acedFindFile(utf8_to_wstr(file).c_str(), data.data(), data.size());
    return wstr_to_utf8(data.data());
}

std::string EdCore::findTrustedFile(const std::string& file)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    std::array<wchar_t, MAX_PATH> data;
    acedFindTrustedFile(utf8_to_wstr(file).c_str(), data.data(), data.size());
    return wstr_to_utf8(data.data());
#endif
}

boost::python::list EdCore::getPredefinedPattens()
{
#ifndef ARXAPP
    throw PyNotimplementedByHost();
#else
    PyAutoLockGIL lock;
    AcStringArray patterns;
    boost::python::list py_patterns;
    if (acedGetPredefinedPattens(patterns) == true)
    {
        for (auto& pattern : patterns)
            py_patterns.append(wstr_to_utf8(pattern));
    }
    return py_patterns;
#endif
}

Acad::ErrorStatus EdCore::xrefDetach1(const std::string& XrefBlockname)
{
    return acedXrefDetach(utf8_to_wstr(XrefBlockname).c_str());
}

Acad::ErrorStatus EdCore::xrefDetach2(const std::string& XrefBlockname, bool bQuiet, PyDbDatabase& db)
{
    return acedXrefDetach(utf8_to_wstr(XrefBlockname).c_str(), bQuiet, db.impObj());
}

std::string EdCore::getFileD(const std::string& title, const std::string& defawlt, const std::string& ext, int flags)
{
    std::string path;
    AcResBufPtr result(acutNewRb(RTSTR));
    if (acedGetFileD(utf8_to_wstr(title).c_str(), utf8_to_wstr(defawlt).c_str(), utf8_to_wstr(ext).c_str(), flags, result.get()) == RTNORM)
        path = wstr_to_utf8(result->resval.rstring);
    return path;
}

boost::python::list EdCore::getFileNavDialog(const std::string& title, const std::string& defawlt, const std::string& ext, const std::string& dlgname, int flags)
{
    PyAutoLockGIL lock;
    resbuf* result = nullptr;
    boost::python::list pyList;
    if (acedGetFileNavDialog(utf8_to_wstr(title).c_str(), utf8_to_wstr(defawlt).c_str(), utf8_to_wstr(ext).c_str(), utf8_to_wstr(dlgname).c_str(), flags, &result) == RTNORM)
    {
        AcResBufPtr resultptr(result);
        for (resbuf* pbuf = result; pbuf != nullptr; pbuf = pbuf->rbnext)
        {
            if (pbuf->restype == RTSTR)
                pyList.append(wstr_to_utf8(pbuf->resval.rstring));
        }
    }
    return pyList;
}

boost::python::object EdCore::getVar(const std::string& sym)
{
    PyAutoLockGIL lock;
    try
    {
        resbuf buf;
        if (acedGetVar(utf8_to_wstr(sym).c_str(), &buf) != RTNORM)
        {
            return boost::python::make_tuple(false, boost::python::object());
        }
        switch (buf.restype)
        {
            case RTSHORT:
            {
                return boost::python::object(buf.resval.rint);
            }
            case RTLONG:
            {
                return boost::python::object(buf.resval.rlong);
            }
            case RTREAL:
            {
                return boost::python::object(buf.resval.rreal);
            }
            case RTSTR:
            {
                std::string val = wstr_to_utf8(buf.resval.rstring);
                acutDelString(buf.resval.rstring);
                return boost::python::object(val);
            }
            case RTPOINT:
            {
                AcGePoint2d pnt = asPnt2d(buf.resval.rpoint);
                return boost::python::object(pnt);
            }
            case RT3DPOINT:
            {
                AcGePoint3d pnt = asPnt3d(buf.resval.rpoint);
                return boost::python::object(pnt);
            }
            default:
            {
                return boost::python::object();
            }
        }
    }
    catch (...)
    {
        acutPrintf(_T("\nExeption @ %ls"), __FUNCTIONW__);
    }
    return boost::python::object();
}

bool EdCore::setVar(const std::string& sym, const boost::python::object& src)
{
    PyAutoLockGIL lock;
    try
    {
        if (extract<double>(src).check())
        {
            const double val = extract<double>(src);
            AcResBufPtr buf(acutBuildList(RTREAL, val, 0));
            return acedSetVar(utf8_to_wstr(sym).c_str(), buf.get()) == RTNORM;
        }
        else if (extract<int>(src).check())
        {
            const int val = extract<int>(src);
            AcResBufPtr buf(acutBuildList(RTLONG, val, 0));
            return acedSetVar(utf8_to_wstr(sym).c_str(), buf.get()) == RTNORM;
        }
        else if (extract<AcGePoint2d>(src).check())
        {
            const auto val = asDblArray(extract<AcGePoint2d>(src));
            AcResBufPtr buf(acutBuildList(RTPOINT, val, 0));
            return acedSetVar(utf8_to_wstr(sym).c_str(), buf.get()) == RTNORM;
        }
        else if (extract<AcGePoint3d>(src).check())
        {
            const auto val = asDblArray(extract<AcGePoint3d>(src));
            AcResBufPtr buf(acutBuildList(RT3DPOINT, val, 0));
            return acedSetVar(utf8_to_wstr(sym).c_str(), buf.get()) == RTNORM;
        }
        else if (extract<char*>(src).check())
        {
            const AcString str = utf8_to_wstr(extract<char*>(src)).c_str();
            AcResBufPtr buf(acutBuildList(RTSTR, (const TCHAR*)str, 0));
            return acedSetVar(utf8_to_wstr(sym).c_str(), buf.get()) == RTNORM;
        }
    }
    catch (...)
    {
        acutPrintf(_T("\nExeption @ %ls"), __FUNCTIONW__);
    }
    return false;
}

Acad::ErrorStatus EdCore::mSpace()
{
    return acedMspace();
}

Acad::ErrorStatus EdCore::pSpace()
{
    return acedPspace();
}

Acad::ErrorStatus EdCore::xrefResolve1(PyDbDatabase& pHostDb)
{
    return acedXrefResolve(pHostDb.impObj());
}

Acad::ErrorStatus EdCore::xrefResolve2(PyDbDatabase& pHostDb, const bool bQuiet)
{
    return acedXrefResolve(pHostDb.impObj(), bQuiet);
}

Acad::ErrorStatus EdCore::xrefUnload1(const std::string& XrefBlockname)
{
    return acedXrefUnload(utf8_to_wstr(XrefBlockname).c_str());
}

Acad::ErrorStatus EdCore::xrefUnload2(const std::string& XrefBlockname, bool bQuiet, PyDbDatabase& pHostDb)
{
    return acedXrefUnload(utf8_to_wstr(XrefBlockname).c_str(), bQuiet, pHostDb.impObj());
}

Acad::ErrorStatus EdCore::xrefXBind1(const boost::python::list& symbolIds)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    AcDbObjectIdArray ids = PyListToObjectIdArray(symbolIds);
    return acedXrefXBind(ids);
#endif
}

Acad::ErrorStatus EdCore::xrefXBind2(const boost::python::list& symbolIds, bool bQuiet, PyDbDatabase& pHostDb)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    AcDbObjectIdArray ids = PyListToObjectIdArray(symbolIds);
    return acedXrefXBind(ids, bQuiet, pHostDb.impObj());
#endif
}
