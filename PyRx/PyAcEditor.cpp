#include "stdafx.h"
#include "PyAcEditor.h"
#include "PyDbObjectId.h"
#include "ResultBuffer.h"
#include "acedCmdNF.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------------
//helpers
boost::python::tuple makeSelectionResult(ads_name name, Acad::PromptStatus result)
{
    PyAutoLockGIL lock;
    AcDbObjectIdArray ids;
    boost::python::list pyList;
    if (acedGetCurrentSelectionSet(ids) == eOk)
    {
        for (const auto& id : ids)
            pyList.append(PyDbObjectId{ id });
    }
    acedSSFree(name);
    return boost::python::make_tuple<Acad::PromptStatus, boost::python::list>(result, pyList);
}


//-----------------------------------------------------------------------------------------
// PyAcEditor wrapper

void makeAcEditorWrapper()
{
    class_<PyAcEditor>("Editor")
        .def("className", &PyAcEditor::className).staticmethod("className")

        .def("alert", &PyAcEditor::alert)
        .def("arxLoad", &PyAcEditor::arxLoad)
        .def("arxUnload", &PyAcEditor::arxUnload)
        .def("arxLoaded", &PyAcEditor::arxLoaded)
        .def("audit", &PyAcEditor::audit)
        .def("cmdS", &PyAcEditor::cmdS)
        .def("findFile", &PyAcEditor::findFile)
        .def("findTrustedFile", &PyAcEditor::findTrustedFile)

        .def("getInteger", &PyAcEditor::getInteger)
        .def("getDouble", &PyAcEditor::getDouble)
        .def("getReal", &PyAcEditor::getDouble)
        .def("getAngle", &PyAcEditor::getAngle)
        .def("getString", &PyAcEditor::getString)

        .def<boost::python::tuple(PyAcEditor::*)(const std::string&)>("getPoint", &PyAcEditor::getPoint)
        .def<boost::python::tuple(PyAcEditor::*)(const AcGePoint3d&, const std::string&)>("getPoint", &PyAcEditor::getPoint)

        .def<boost::python::tuple(PyAcEditor::*)(const std::string&)>("getDist", &PyAcEditor::getDist)
        .def<boost::python::tuple(PyAcEditor::*)(const AcGePoint3d&, const std::string&)>("getDist", &PyAcEditor::getDist)

        .def("entSel", &PyAcEditor::entSel)
        .def("getCurrentUCS", &PyAcEditor::curUCS)
        .def("setCurrentUCS", &PyAcEditor::setCurUCS)

        .def("activeViewportId", &PyAcEditor::activeViewportId)

        .def<boost::python::tuple(PyAcEditor::*)(void)>("selectAll", &PyAcEditor::selectAll)
        .def<boost::python::tuple(PyAcEditor::*)(const boost::python::list&)>("selectAll", &PyAcEditor::selectAll)

        .def("select", &PyAcEditor::select1)
        .def("select", &PyAcEditor::select2)
        .def("select", &PyAcEditor::select3)
        .def("select", &PyAcEditor::select4)
        .def("selectCrossingWindow", &PyAcEditor::selectCrossingWindow1)
        .def("selectCrossingWindow", &PyAcEditor::selectCrossingWindow2)
        .def("initGet", &PyAcEditor::initGet)
        .def("getKword", &PyAcEditor::getKword)
        ;
}

//-----------------------------------------------------------------------------------------
// PyAcEditor
void PyAcEditor::alert(const std::string& prompt)
{
    acedAlert(utf8_to_wstr(prompt).c_str());
}

bool PyAcEditor::arxLoad(const std::string& path)
{
    return (acedArxLoad(utf8_to_wstr(path).c_str()) == RTNORM);
}

bool PyAcEditor::arxUnload(const std::string& app)
{
    return acedArxUnload(utf8_to_wstr(app).c_str()) == RTNORM;
}

Acad::ErrorStatus PyAcEditor::audit(const PyDbDatabase& db, bool bFixErrors, bool bCmdLnEcho)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return acedAudit(db.impObj(), bFixErrors, bCmdLnEcho);
#endif
}

bool PyAcEditor::cmdS(const boost::python::list& lst)
{
    AcResBufPtr pcmd(listToResbuf(lst));
    return acedCmdS(pcmd.get()) == RTNORM;
}

std::string PyAcEditor::findFile(const std::string& file)
{
    std::array<wchar_t, MAX_PATH> data;
    acedFindFile(utf8_to_wstr(file).c_str(), data.data(), data.size());
    return wstr_to_utf8(data.data());
}

std::string PyAcEditor::findTrustedFile(const std::string& file)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    std::array<wchar_t, MAX_PATH> data;
    acedFindTrustedFile(utf8_to_wstr(file).c_str(), data.data(), data.size());
    return wstr_to_utf8(data.data());
#endif
}

boost::python::list PyAcEditor::arxLoaded()
{
    PyAutoLockGIL lock;
    AcResBufPtr pLoaded(acedArxLoaded());
    return resbufToList(pLoaded.get());
}

boost::python::tuple PyAcEditor::getInteger(const std::string& prompt)
{
    PyAutoLockGIL lock;
    WxUserInteraction ui;
    std::pair<Acad::PromptStatus, int> res;
    res.first = static_cast<Acad::PromptStatus>(acedGetInt(utf8_to_wstr(prompt).c_str(), &res.second));
    return boost::python::make_tuple(res.first, res.second);
}

boost::python::tuple PyAcEditor::getDouble(const std::string& prompt)
{
    PyAutoLockGIL lock;
    WxUserInteraction ui;
    std::pair<Acad::PromptStatus, double> res;
    res.first = static_cast<Acad::PromptStatus>(acedGetReal(utf8_to_wstr(prompt).c_str(), &res.second));
    return boost::python::make_tuple(res.first, res.second);
}

boost::python::tuple PyAcEditor::getAngle(const AcGePoint3d& basePt, const std::string& prompt)
{
    PyAutoLockGIL lock;
    WxUserInteraction ui;
    std::pair<Acad::PromptStatus, double> res;
    res.first = static_cast<Acad::PromptStatus>(acedGetAngle(asDblArray(basePt), utf8_to_wstr(prompt).c_str(), &res.second));
    return boost::python::make_tuple(res.first, res.second);
}

boost::python::tuple PyAcEditor::getPoint(const std::string& prompt)
{
    PyAutoLockGIL lock;
    WxUserInteraction ui;
    ads_point pnt;
    std::pair<Acad::PromptStatus, AcGePoint3d> res;
    res.first = static_cast<Acad::PromptStatus>(acedGetPoint(nullptr, utf8_to_wstr(prompt).c_str(), pnt));
    res.second = asPnt3d(pnt);
    return boost::python::make_tuple(res.first, res.second);
}

boost::python::tuple PyAcEditor::getPoint(const AcGePoint3d& basePt, const std::string& prompt)
{
    PyAutoLockGIL lock;
    WxUserInteraction ui;
    ads_point pnt;
    std::pair<Acad::PromptStatus, AcGePoint3d> res;
    res.first = static_cast<Acad::PromptStatus>(acedGetPoint(asDblArray(basePt), utf8_to_wstr(prompt).c_str(), pnt));
    res.second = asPnt3d(pnt);
    return boost::python::make_tuple(res.first, res.second);
}

boost::python::tuple PyAcEditor::getDist(const std::string& prompt)
{
    PyAutoLockGIL lock;
    WxUserInteraction ui;
    std::pair<Acad::PromptStatus, double> res;
    res.first = static_cast<Acad::PromptStatus>(acedGetDist(nullptr, utf8_to_wstr(prompt).c_str(), &res.second));
    return boost::python::make_tuple(res.first, res.second);
}

boost::python::tuple PyAcEditor::getDist(const AcGePoint3d& basePt, const std::string& prompt)
{
    PyAutoLockGIL lock;
    WxUserInteraction ui;
    std::pair<Acad::PromptStatus, double> res;
    res.first = static_cast<Acad::PromptStatus>(acedGetDist(asDblArray(basePt), utf8_to_wstr(prompt).c_str(), &res.second));
    return boost::python::make_tuple(res.first, res.second);
}

boost::python::tuple PyAcEditor::getString(int cronly, const std::string& prompt)
{
    PyAutoLockGIL lock;
    WxUserInteraction ui;
    AcString str;
    std::pair<Acad::PromptStatus, std::string> res;
    res.first = static_cast<Acad::PromptStatus>(acedGetString(cronly, utf8_to_wstr(prompt).c_str(), str));
    res.second = wstr_to_utf8(str);
    return boost::python::make_tuple(res.first, res.second);
}

boost::python::tuple PyAcEditor::entSel(const std::string& prompt)
{
    PyAutoLockGIL lock;
    WxUserInteraction ui;
    ads_point pnt;
    ads_name name = { 0L };
    auto stat = static_cast<Acad::PromptStatus>(acedEntSel(utf8_to_wstr(prompt).c_str(), name, pnt));
    PyDbObjectId id;
    acdbGetObjectId(id.m_id, name);
    return boost::python::make_tuple<Acad::PromptStatus, PyDbObjectId, AcGePoint3d>(stat, id, asPnt3d(pnt));
}

boost::python::tuple PyAcEditor::select1()
{
    WxUserInteraction ui;
    ads_name name = { 0L };
    auto stat = static_cast<Acad::PromptStatus>(acedSSGet(nullptr, nullptr, nullptr,nullptr, name));
    return makeSelectionResult(name, stat);
}

boost::python::tuple PyAcEditor::select2(const boost::python::list& filter)
{
    WxUserInteraction ui;
    ads_name name = { 0L };
    AcResBufPtr pFilter(listToResbuf(filter));
    auto stat = static_cast<Acad::PromptStatus>(acedSSGet(nullptr, nullptr, nullptr, pFilter.get(), name));
    return makeSelectionResult(name, stat);
}

boost::python::tuple PyAcEditor::select3(const std::string& add, const std::string& remove)
{
    WxUserInteraction ui;
    ads_name name = { 0L };

    const CString csAdd = utf8_to_wstr(add).c_str();
    const CString csRem = utf8_to_wstr(remove).c_str();
    const wchar_t* prompts[] = { (const wchar_t*)csAdd, (const wchar_t*)csRem };

    auto stat = static_cast<Acad::PromptStatus>(acedSSGet(_T("_:$"), prompts,nullptr,nullptr, name));
    return makeSelectionResult(name, stat);
}

boost::python::tuple PyAcEditor::select4(const std::string& add, const std::string& remove, const boost::python::list& filter)
{
    WxUserInteraction ui;
    ads_name name = { 0L };
    AcResBufPtr pFilter(listToResbuf(filter));

    const CString csAdd = utf8_to_wstr(add).c_str();
    const CString csRem = utf8_to_wstr(remove).c_str();
    const wchar_t* prompts[] = { (const wchar_t*)csAdd, (const wchar_t*)csRem };

    auto stat = static_cast<Acad::PromptStatus>(acedSSGet(_T("_:$"), prompts, nullptr, pFilter.get(), name));
    return makeSelectionResult(name, stat);
}

boost::python::tuple PyAcEditor::selectAll()
{
    WxUserInteraction ui;
    ads_name name = { 0L };
    auto stat = static_cast<Acad::PromptStatus>(acedSSGet(_T("_A"), nullptr, nullptr, nullptr, name));
    return makeSelectionResult(name, stat);
}

boost::python::tuple PyAcEditor::selectAll(const boost::python::list& filter)
{
    WxUserInteraction ui;
    ads_name name = { 0L };
    AcResBufPtr pFilter(listToResbuf(filter));
    auto stat = static_cast<Acad::PromptStatus>(acedSSGet(_T("_A"), nullptr, nullptr, pFilter.get(), name));
    return makeSelectionResult(name, stat);
}

boost::python::tuple PyAcEditor::selectCrossingWindow1(const AcGePoint3d& pt1, const AcGePoint3d& pt2)
{
    WxUserInteraction ui;
    ads_name name = { 0L };
    auto stat = static_cast<Acad::PromptStatus>(acedSSGet(_T("_W"), asDblArray(pt1), asDblArray(pt2),nullptr, name));
    return makeSelectionResult(name, stat);
}

boost::python::tuple PyAcEditor::selectCrossingWindow2(const AcGePoint3d& pt1, const AcGePoint3d& pt2, const boost::python::list& filter)
{
    WxUserInteraction ui;
    ads_name name = { 0L };
    AcResBufPtr pFilter(listToResbuf(filter));
    auto stat = static_cast<Acad::PromptStatus>(acedSSGet(_T("_W"),asDblArray(pt1), asDblArray(pt2), pFilter.get(), name));
    return makeSelectionResult(name, stat);
}

AcGeMatrix3d PyAcEditor::curUCS()
{
    AcGeMatrix3d mat;
    if (auto es = acedGetCurrentUCS(mat); es != eOk)
        throw PyAcadErrorStatus(es);
    return mat;
}

Acad::ErrorStatus PyAcEditor::setCurUCS(const AcGeMatrix3d& mat)
{
    return acedSetCurrentUCS(mat);
}

PyDbObjectId PyAcEditor::activeViewportId()
{
    return PyDbObjectId(acedActiveViewportId());
}

Acad::PromptStatus PyAcEditor::initGet(int val, const std::string& skwl)
{
    return static_cast<Acad::PromptStatus>(acedInitGet(val, utf8_to_wstr(skwl).c_str()));
}

boost::python::tuple PyAcEditor::getKword(const std::string& skwl)
{
    PyAutoLockGIL lock;
    ACHAR* pStr = nullptr;
    int resval = acedGetFullKword(utf8_to_wstr(skwl).c_str(), pStr);
    std::string resStr = wstr_to_utf8(pStr);
    acutDelString(pStr);
    return boost::python::make_tuple(resval, resStr);
}

std::string PyAcEditor::className()
{
    return std::string{ "Editor" };
}
