#include "stdafx.h"
#include "PyAcEditor.h"
#include "PyDbObjectId.h"
#include "ResultBuffer.h"
#include "acedCmdNF.h"
#include "PyEdSelectionSet.h"
#include "PyDbEntity.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------------
//helpers
class ssArgExtracter
{
public:
    ssArgExtracter(const boost::python::object& obj)
        :m_obj(obj)
    {
    }
    const void* extractArg()
    {
        if (extract<AcGePoint3d>(m_obj).check())
        {
            return asDblArray(extract<AcGePoint3d>(m_obj));
        }
        else if (extract<boost::python::list>(m_obj).check())
        {
            ptr.reset(acGePoint3dArrayToResbuf(PyListToPoint3dArray(m_obj)));
            return ptr.get();
        }
        else if (extract<boost::python::tuple>(m_obj).check())
        {
            PyAutoLockGIL lock;
            tuple tpl = extract<tuple>(m_obj);
            if (boost::python::len(tpl) != 2)
                throw PyAcadErrorStatus(Acad::eInvalidInput);
            if (!(extract<std::string>(tpl[0]).check() && extract<std::string>(tpl[1]).check()))
                throw PyAcadErrorStatus(Acad::eInvalidInput);
            add = utf8_to_wstr(extract<std::string>(tpl[0])).c_str();
            rem = utf8_to_wstr(extract<std::string>(tpl[1])).c_str();
            prompts = { (const wchar_t*)add, (const wchar_t*)rem };
            return prompts.data();
        }
        return nullptr;
    }

public:
    //holders so extractArg() can return something alive
    CString add;
    CString rem;
    AcResBufPtr ptr;
    std::array<const wchar_t*, 2> prompts = { 0 };
private:
    const boost::python::object& m_obj;
};

boost::python::tuple makeSelectionResult(const ads_name& name, Acad::PromptStatus result)
{
    PyAutoLockGIL lock;
    PyEdSelectionSet set(name);
    return boost::python::make_tuple<Acad::PromptStatus, PyEdSelectionSet>(result, set);
}

//-----------------------------------------------------------------------------------------
// PyAcEditor wrapper

void makeAcEditorWrapper()
{
    class_<PyAcEditor>("Editor")
        .def("className", &PyAcEditor::className).staticmethod("className")
        .def("alert", &PyAcEditor::alert).staticmethod("alert")
        .def("getInteger", &PyAcEditor::getInteger).staticmethod("getInteger")
        .def("getDouble", &PyAcEditor::getDouble).staticmethod("getDouble")
        .def("getReal", &PyAcEditor::getDouble).staticmethod("getReal")
        .def("getAngle", &PyAcEditor::getAngle).staticmethod("getAngle")
        .def("getString", &PyAcEditor::getString).staticmethod("getString")
        .def("getPoint", &PyAcEditor::getPoint1)
        .def("getPoint", &PyAcEditor::getPoint2).staticmethod("getPoint")
        .def("getDist", &PyAcEditor::getDist1)
        .def("getDist", &PyAcEditor::getDist2).staticmethod("getDist")
        .def("entSel", &PyAcEditor::entSel).staticmethod("entSel")
        .def("getCurrentUCS", &PyAcEditor::curUCS).staticmethod("getCurrentUCS")
        .def("setCurrentUCS", &PyAcEditor::setCurUCS).staticmethod("setCurrentUCS")
        .def("activeViewportId", &PyAcEditor::activeViewportId).staticmethod("activeViewportId")
        .def("curViewportObjectId", &PyAcEditor::curViewportObjectId).staticmethod("curViewportObjectId")
        .def("selectAll", &PyAcEditor::selectAll1)
        .def("selectAll", &PyAcEditor::selectAll2).staticmethod("selectAll")
        .def("select", &PyAcEditor::select1)
        .def("select", &PyAcEditor::select2)
        .def("selectPrompt", &PyAcEditor::select3)
        .def("selectPrompt", &PyAcEditor::select4).staticmethod("selectPrompt")
        .def("selectWindow", &PyAcEditor::selectWindow1)
        .def("selectWindow", &PyAcEditor::selectWindow2).staticmethod("selectWindow")
        .def("selectWindowPolygon", &PyAcEditor::selectWindowPolygon1)
        .def("selectWindowPolygon", &PyAcEditor::selectWindowPolygon2).staticmethod("selectWindowPolygon")
        .def("selectFence", &PyAcEditor::selectFence1)
        .def("selectFence", &PyAcEditor::selectFence2).staticmethod("selectFence")
        .def("selectPrevious", &PyAcEditor::selectPrevious1)
        .def("selectPrevious", &PyAcEditor::selectPrevious2).staticmethod("selectPrevious")
        .def("selectLast", &PyAcEditor::selectLast1)
        .def("selectLast", &PyAcEditor::selectLast2).staticmethod("selectLast")
        .def("ssget", &PyAcEditor::ssget1)
        .def("ssget", &PyAcEditor::ssget2).staticmethod("ssget")
        .def("initGet", &PyAcEditor::initGet).staticmethod("initGet")
        .def("getKword", &PyAcEditor::getKword).staticmethod("getKword")
        .def("getVar", &PyAcEditor::getVar).staticmethod("getVar")
        .def("setVar", &PyAcEditor::setVar).staticmethod("setVar")
        .def("traceBoundary", &PyAcEditor::traceBoundary).staticmethod("traceBoundary")
        ;
}

//-----------------------------------------------------------------------------------------
// PyAcEditor
void PyAcEditor::alert(const std::string& prompt)
{
    acedAlert(utf8_to_wstr(prompt).c_str());
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

boost::python::tuple PyAcEditor::getPoint1(const std::string& prompt)
{
    PyAutoLockGIL lock;
    WxUserInteraction ui;
    ads_point pnt;
    std::pair<Acad::PromptStatus, AcGePoint3d> res;
    res.first = static_cast<Acad::PromptStatus>(acedGetPoint(nullptr, utf8_to_wstr(prompt).c_str(), pnt));
    res.second = asPnt3d(pnt);
    return boost::python::make_tuple(res.first, res.second);
}

boost::python::tuple PyAcEditor::getPoint2(const AcGePoint3d& basePt, const std::string& prompt)
{
    PyAutoLockGIL lock;
    WxUserInteraction ui;
    ads_point pnt;
    std::pair<Acad::PromptStatus, AcGePoint3d> res;
    res.first = static_cast<Acad::PromptStatus>(acedGetPoint(asDblArray(basePt), utf8_to_wstr(prompt).c_str(), pnt));
    res.second = asPnt3d(pnt);
    return boost::python::make_tuple(res.first, res.second);
}

boost::python::tuple PyAcEditor::getDist1(const std::string& prompt)
{
    PyAutoLockGIL lock;
    WxUserInteraction ui;
    std::pair<Acad::PromptStatus, double> res;
    res.first = static_cast<Acad::PromptStatus>(acedGetDist(nullptr, utf8_to_wstr(prompt).c_str(), &res.second));
    return boost::python::make_tuple(res.first, res.second);
}

boost::python::tuple PyAcEditor::getDist2(const AcGePoint3d& basePt, const std::string& prompt)
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
    auto stat = static_cast<Acad::PromptStatus>(acedSSGet(nullptr, nullptr, nullptr, nullptr, name));
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
    auto stat = static_cast<Acad::PromptStatus>(acedSSGet(_T("_:$"), prompts, nullptr, nullptr, name));
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

boost::python::tuple PyAcEditor::selectAll1()
{
    WxUserInteraction ui;
    ads_name name = { 0L };
    auto stat = static_cast<Acad::PromptStatus>(acedSSGet(_T("_A"), nullptr, nullptr, nullptr, name));
    return makeSelectionResult(name, stat);
}

boost::python::tuple PyAcEditor::selectAll2(const boost::python::list& filter)
{
    WxUserInteraction ui;
    ads_name name = { 0L };
    AcResBufPtr pFilter(listToResbuf(filter));
    auto stat = static_cast<Acad::PromptStatus>(acedSSGet(_T("_A"), nullptr, nullptr, pFilter.get(), name));
    return makeSelectionResult(name, stat);
}

boost::python::tuple PyAcEditor::selectWindow1(const AcGePoint3d& pt1, const AcGePoint3d& pt2)
{
    WxUserInteraction ui;
    ads_name name = { 0L };
    auto stat = static_cast<Acad::PromptStatus>(acedSSGet(_T("_W"), asDblArray(pt1), asDblArray(pt2), nullptr, name));
    return makeSelectionResult(name, stat);
}

boost::python::tuple PyAcEditor::selectWindow2(const AcGePoint3d& pt1, const AcGePoint3d& pt2, const boost::python::list& filter)
{
    WxUserInteraction ui;
    ads_name name = { 0L };
    AcResBufPtr pFilter(listToResbuf(filter));
    auto stat = static_cast<Acad::PromptStatus>(acedSSGet(_T("_W"), asDblArray(pt1), asDblArray(pt2), pFilter.get(), name));
    return makeSelectionResult(name, stat);
}

boost::python::tuple PyAcEditor::selectFence1(const boost::python::list& points)
{
    WxUserInteraction ui;
    ads_name name = { 0L };
    AcResBufPtr rbPoints(acGePoint3dArrayToResbuf(PyListToPoint3dArray(points)));
    auto stat = static_cast<Acad::PromptStatus>(acedSSGet(_T("_F"), rbPoints.get(), nullptr,nullptr, name));
    return makeSelectionResult(name, stat);
}

boost::python::tuple PyAcEditor::selectFence2(const boost::python::list& points, const boost::python::list& filter)
{
    WxUserInteraction ui;
    ads_name name = { 0L };
    AcResBufPtr pFilter(listToResbuf(filter));
    AcResBufPtr rbPoints(acGePoint3dArrayToResbuf(PyListToPoint3dArray(points)));
    auto stat = static_cast<Acad::PromptStatus>(acedSSGet(_T("_F"), rbPoints.get(), nullptr, pFilter.get(), name));
    return makeSelectionResult(name, stat);
}

boost::python::tuple PyAcEditor::selectWindowPolygon1(const boost::python::list& points)
{
    WxUserInteraction ui;
    ads_name name = { 0L };
    AcResBufPtr rbPoints(acGePoint3dArrayToResbuf(PyListToPoint3dArray(points)));
    auto stat = static_cast<Acad::PromptStatus>(acedSSGet(_T("_WP"), rbPoints.get(), nullptr, nullptr, name));
    return makeSelectionResult(name, stat);
}

boost::python::tuple PyAcEditor::selectWindowPolygon2(const boost::python::list& points, const boost::python::list& filter)
{
    WxUserInteraction ui;
    ads_name name = { 0L };
    AcResBufPtr pFilter(listToResbuf(filter));
    AcResBufPtr rbPoints(acGePoint3dArrayToResbuf(PyListToPoint3dArray(points)));
    auto stat = static_cast<Acad::PromptStatus>(acedSSGet(_T("_WP"), rbPoints.get(), nullptr, pFilter.get(), name));
    return makeSelectionResult(name, stat);
}

boost::python::tuple PyAcEditor::selectPrevious1()
{
    WxUserInteraction ui;
    ads_name name = { 0L };
    auto stat = static_cast<Acad::PromptStatus>(acedSSGet(_T("_P"), nullptr, nullptr, nullptr, name));
    return makeSelectionResult(name, stat);
}

boost::python::tuple PyAcEditor::selectPrevious2(const boost::python::list& filter)
{
    WxUserInteraction ui;
    ads_name name = { 0L };
    AcResBufPtr pFilter(listToResbuf(filter));
    auto stat = static_cast<Acad::PromptStatus>(acedSSGet(_T("_P"), nullptr, nullptr, pFilter.get(), name));
    return makeSelectionResult(name, stat);
}

boost::python::tuple PyAcEditor::selectLast1()
{
    WxUserInteraction ui;
    ads_name name = { 0L };
    auto stat = static_cast<Acad::PromptStatus>(acedSSGet(_T("_L"), nullptr, nullptr, nullptr, name));
    return makeSelectionResult(name, stat);
}

boost::python::tuple PyAcEditor::selectLast2(const boost::python::list& filter)
{
    WxUserInteraction ui;
    ads_name name = { 0L };
    AcResBufPtr pFilter(listToResbuf(filter));
    auto stat = static_cast<Acad::PromptStatus>(acedSSGet(_T("_L"), nullptr, nullptr, pFilter.get(), name));
    return makeSelectionResult(name, stat);
}

boost::python::tuple PyAcEditor::ssget1(const std::string& args,const boost::python::object& arg1,const boost::python::object& arg2)
{
    WxUserInteraction ui;
    ads_name name = { 0L };
    ssArgExtracter ssarg1(arg1);
    ssArgExtracter ssarg2(arg2);
    AcString strArg = utf8_to_wstr(args).c_str();
    auto stat = static_cast<Acad::PromptStatus>(acedSSGet(strArg, ssarg1.extractArg(), ssarg2.extractArg(), nullptr, name));
    return makeSelectionResult(name, stat);
}

boost::python::tuple PyAcEditor::ssget2(const std::string& args, const boost::python::object& arg1, const boost::python::object& arg2, const boost::python::list& filter)
{
    WxUserInteraction ui;
    ads_name name = { 0L };
    ssArgExtracter ssarg1(arg1);
    ssArgExtracter ssarg2(arg2);
    AcResBufPtr pFilter(listToResbuf(filter));
    AcString strArg = utf8_to_wstr(args).c_str();
    auto stat = static_cast<Acad::PromptStatus>(acedSSGet(strArg, ssarg1.extractArg(), ssarg2.extractArg(), pFilter.get(), name));
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

PyDbObjectId PyAcEditor::curViewportObjectId()
{
    return PyDbObjectId(acedGetCurViewportObjectId());
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

boost::python::object PyAcEditor::getVar(const std::string& sym)
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

bool PyAcEditor::setVar(const std::string& sym, const  boost::python::object& src)
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

boost::python::list PyAcEditor::traceBoundary(const AcGePoint3d& seedPoint, bool detectIslands)
{
    PyAutoLockGIL lock;
    boost::python::list pyList;
    AcDbVoidPtrArray resultingBoundarySet;
    if (auto es = acedTraceBoundary(seedPoint, detectIslands, resultingBoundarySet); es != eOk)
        throw PyAcadErrorStatus(es);
    for (auto ptr : resultingBoundarySet)
        pyList.append(PyDbEntity(static_cast<AcDbEntity*>(ptr), true));
    return pyList;
}

std::string PyAcEditor::className()
{
    return std::string{ "Editor" };
}
