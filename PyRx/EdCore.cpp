#include "stdafx.h"
#include "EdCore.h"
#include "PyDbObjectId.h"
#include "PyDbDatabase.h"
#include "ResultBuffer.h"

#include "acedCmdNF.h"

extern "C" bool acedGetPredefinedPattens(AcStringArray & patterns);

using namespace boost::python;

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
