#include "stdafx.h"
#include "PyAcEditor.h"
#include "PyDbObjectId.h"
#include "ResultBuffer.h"
#include "acedCmdNF.h"
#include "PyEdSelectionSet.h"
#include "PyDbEntity.h"
#include "PyEdUserInteraction.h"
#include "PyApDocument.h"
#include "PyDbEnts.h"

using namespace boost::python;

constexpr const char* enstselstr = "\nSelect entity:\t";

#ifdef BRXAPP
void ads_regen(void);

extern int acedNEntSelPEx(
    const ACHAR* str,
    ads_name entres,
    ads_point ptres,
    int pickflag,
    ads_matrix xformres,
    struct resbuf** refstkres,
    unsigned int uTransSpaceFlag,
    Adesk::GsMarker* gsmarker);
#endif


#ifdef GRXAPP
void ads_regen(void);
#endif

#ifdef IRXAPP
void ads_regen(void);
#endif

#ifdef ARXAPP
void ads_regen(void);

extern int acedNEntSelPEx(
    const ACHAR* str,
    ads_name entres,
    ads_point ptres,
    int pickflag,
    ads_matrix xformres,
    struct resbuf** refstkres,
    unsigned int uTransSpaceFlag,
    Adesk::GsMarker* gsmarker);
#endif
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
        else if (PyList_Check(m_obj.ptr()))
        {
            ptr.reset(AcGePoint3dArrayToResbuf(PyListToPoint3dArray(m_obj)));
            return ptr.get();
        }
        else if (PyTuple_Check(m_obj.ptr()))
        {
            PyAutoLockGIL lock;
            tuple tpl = extract<tuple>(m_obj);
            if (boost::python::len(tpl) != 2)
                throw PyErrorStatusException(Acad::eInvalidInput);
            if (!(boost::python::extract<std::string>(tpl[0]).check() && boost::python::extract<std::string>(tpl[1]).check()))
                throw PyErrorStatusException(Acad::eInvalidInput);
            add = utf8_to_wstr(boost::python::extract<std::string>(tpl[0])).c_str();
            rem = utf8_to_wstr(boost::python::extract<std::string>(tpl[1])).c_str();
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

static boost::python::tuple makeSelectionResult(const ads_name& name, Acad::PromptStatus result)
{
    PyAutoLockGIL lock;
    return boost::python::make_tuple<Acad::PromptStatus, PyEdSelectionSet>(result, PyEdSelectionSet{ name });
}

//-----------------------------------------------------------------------------------------
// PyAcEditor wrapper

void makePyEditorWrapper()
{
    constexpr const std::string_view getStringOverloads = "Overloads:\n"
        "- prompt: str\n"
        "- prompt: str, condition :PyEd.PromptCondition\n"
        "- cronly: int, prompt: str\n"
        "- cronly: int, prompt: str, condition :PyEd.PromptCondition\n";

    constexpr const std::string_view getPointOverloads = "Overloads:\n"
        "- prompt: str\n"
        "- basePt: PyGe.Point3d, prompt: str\n";

    constexpr const std::string_view nEntSelPExloads = "Overloads:\n"
        "- prompt: str, flags: int\n"
        "- prompt: str, selpt: PyGe.Point3d, flags: int\n";

    constexpr const std::string_view entselOverloads = "Overloads:\n"
        "- None: Any\n"
        "- prompt: str\n"
        "- prompt: str, eType: PyRx.RxClass\n"
        "- prompt: str, eTypes: list[PyRx.RxClass]\n"
        "- eType : PyRx.RxClass\n"
        "- eTypes: list[PyRx.RxClass]\n";

    PyDocString DS("Editor");
    class_<PyAcEditor>("Editor")
        .def(init<>(DS.ARGS()))
        .def("getCorner", &PyAcEditor::getCorner, DS.SARGS({ "basePt: PyGe.Point3d","prompt: str" }, 10840)).staticmethod("getCorner")
        .def("getInteger", &PyAcEditor::getInteger1)
        .def("getInteger", &PyAcEditor::getInteger2, DS.SARGS({ "prompt: str","condition :PyEd.PromptCondition = PyEd.PromptCondition.eNone" }, 10865)).staticmethod("getInteger")
        .def("getDouble", &PyAcEditor::getDouble1)
        .def("getDouble", &PyAcEditor::getDouble2, DS.SARGS({ "prompt: str","condition :PyEd.PromptCondition = PyEd.PromptCondition.eNone" }, 10871)).staticmethod("getDouble")
        .def("getReal", &PyAcEditor::getDouble1)
        .def("getReal", &PyAcEditor::getDouble2, DS.SARGS({ "prompt: str","condition :PyEd.PromptCondition = PyEd.PromptCondition.eNone" }, 10871)).staticmethod("getReal")
        .def("getAngle", &PyAcEditor::getAngle, DS.SARGS({ "basePt: PyGe.Point3d","prompt: str" }, 10825)).staticmethod("getAngle")
        .def("getCurrentSelectionSet", &PyAcEditor::getCurrentSelectionSet, DS.SARGS(10846)).staticmethod("getCurrentSelectionSet")
        .def("getString", &PyAcEditor::getString1)
        .def("getString", &PyAcEditor::getString2)
        .def("getString", &PyAcEditor::getString3)
        .def("getString", &PyAcEditor::getString4, DS.SOVRL(getStringOverloads, 10859)).staticmethod("getString")
        .def("getPoint", &PyAcEditor::getPoint1)
        .def("getPoint", &PyAcEditor::getPoint2, DS.SOVRL(getPointOverloads, 10870)).staticmethod("getPoint")
        .def("getDist", &PyAcEditor::getDist1)
        .def("getDist", &PyAcEditor::getDist2, DS.SOVRL(getPointOverloads, 10852)).staticmethod("getDist")
        .def("entSel", &PyAcEditor::entSel0)
        .def("entSel", &PyAcEditor::entSel1)
        .def("entSel", &PyAcEditor::entSel2)
        .def("entSel", &PyAcEditor::entSel3)
        .def("entSel", &PyAcEditor::entSel4)
        .def("entSel", &PyAcEditor::entSel5, DS.SOVRL(entselOverloads, 10813)).staticmethod("entSel")
        .def("nEntSelP", &PyAcEditor::nEntSelP1)
        .def("nEntSelP", &PyAcEditor::nEntSelP2, DS.SARGS({ "prompt: str","selpt: PyGe.Point3d = ..." })).staticmethod("nEntSelP")
        .def("nEntSelPEx", &PyAcEditor::nEntSelPEx1)
        .def("nEntSelPEx", &PyAcEditor::nEntSelPEx2, DS.SOVRL(nEntSelPExloads)).staticmethod("nEntSelPEx")
        .def("getCurrentUCS", &PyAcEditor::curUCS, DS.SARGS(10847)).staticmethod("getCurrentUCS")
        .def("setCurrentUCS", &PyAcEditor::setCurUCS, DS.SARGS({ "ucs: PyGe.Matrix3d" }, 11316)).staticmethod("setCurrentUCS")
        .def("activeViewportId", &PyAcEditor::activeViewportId, DS.SARGS(10711)).staticmethod("activeViewportId")
        .def("curViewportObjectId", &PyAcEditor::curViewportObjectId, DS.SARGS(10848)).staticmethod("curViewportObjectId")
        .def("selectAll", &PyAcEditor::selectAll1)
        .def("selectAll", &PyAcEditor::selectAll2, DS.SARGS({ "filter: Collection[tuple[int, Any]] = ..." }, 11344)).staticmethod("selectAll")
        .def("select", &PyAcEditor::select1)
        .def("select", &PyAcEditor::select2, DS.SARGS({ "filter:Collection[tuple[int, Any]] = ..." }, 11344)).staticmethod("select")
        .def("selectImplied", &PyAcEditor::selectImplied, DS.SARGS()).staticmethod("selectImplied")
        .def("selectPrompt", &PyAcEditor::select3)
        .def("selectPrompt", &PyAcEditor::select4, DS.SARGS({ "addPromt: str","remPromt: str","filter: Collection[tuple[int, Any]] = ..." }, 11344)).staticmethod("selectPrompt")
        .def("selectWindow", &PyAcEditor::selectWindow1)
        .def("selectWindow", &PyAcEditor::selectWindow2, DS.SARGS({ "pt1: PyGe.Point3d","pt2: PyGe.Point3d","filter: Collection[tuple[int, Any]] = ..." }, 11344)).staticmethod("selectWindow")
        .def("selectWindowPolygon", &PyAcEditor::selectWindowPolygon1)
        .def("selectWindowPolygon", &PyAcEditor::selectWindowPolygon2, DS.SARGS({ "points:Collection[PyGe.Point3d]","filter: Collection[tuple[int, Any]] = ..." }, 11344)).staticmethod("selectWindowPolygon")
        .def("selectFence", &PyAcEditor::selectFence1)
        .def("selectFence", &PyAcEditor::selectFence2, DS.SARGS({ "points:Collection[PyGe.Point3d]","filter:Collection[tuple[int, Any]] = ..." }, 11344)).staticmethod("selectFence")
        .def("selectPrevious", &PyAcEditor::selectPrevious1)
        .def("selectPrevious", &PyAcEditor::selectPrevious2, DS.SARGS({ "filter:Collection[tuple[int, Any]] = ..." }, 11344)).staticmethod("selectPrevious")
        .def("selectLast", &PyAcEditor::selectLast1)
        .def("selectLast", &PyAcEditor::selectLast2, DS.SARGS({ "filter:Collection[tuple[int, Any]] = ..." }, 11344)).staticmethod("selectLast")
        .def("ssget", &PyAcEditor::ssget1)
        .def("ssget", &PyAcEditor::ssget2, DS.SARGS({ "mode: str","arg1: object","arg2: object","filter:Collection[tuple[int, Any]] = ..." }, 11344)).staticmethod("ssget")
        .def("initGet", &PyAcEditor::initGet, DS.SARGS({ "val: int","keyword: str" }, 10897)).staticmethod("initGet")
        .def("getKword", &PyAcEditor::getKword, DS.SARGS({ "keyword: str" }, 10858)).staticmethod("getKword")
        .def("getInput", &PyAcEditor::getInput, DS.SARGS(10864)).staticmethod("getInput")
        .def("traceBoundary", &PyAcEditor::traceBoundary, DS.SARGS({ "point: PyGe.Point3d","detectIslands: bool" }, 11464)).staticmethod("traceBoundary")
        .def("ucsNormalVector", &PyAcEditor::ucsNormalVector, DS.SARGS(19116)).staticmethod("ucsNormalVector")
        .def("ucsXDir", &PyAcEditor::ucsXDir, DS.SARGS(19117)).staticmethod("ucsXDir")
        .def("ucsYDir", &PyAcEditor::ucsYDir, DS.SARGS(19118)).staticmethod("ucsYDir")
        .def("duplicateSelectionsAllowed", &PyAcEditor::duplicateSelectionsAllowed, DS.SARGS({ "doc: PyAp.Document" }, 18856)).staticmethod("duplicateSelectionsAllowed")
        .def("setAllowDuplicateSelection", &PyAcEditor::setAllowDuplicateSelection, DS.SARGS({ "doc: PyAp.Document","flag: bool" }, 19033)).staticmethod("setAllowDuplicateSelection")
        .def("regen", &PyAcEditor::regen, DS.SARGS()).staticmethod("regen")
        .def("getViewportNumber", &PyAcEditor::getViewportNumber, DS.SARGS({ "ptx: int","pty: int" }, 10885)).staticmethod("getViewportNumber")
        .def("className", &PyAcEditor::className, DS.SARGS()).staticmethod("className")
        ;
}

//-----------------------------------------------------------------------------------------
// PyAcEditor
boost::python::tuple PyAcEditor::getCorner(const AcGePoint3d& basePt, const std::string& prompt)
{
    ads_point pnt;
    PyAutoLockGIL lock;
    PyEdUserInteraction ui;
    auto res = static_cast<Acad::PromptStatus>(acedGetCorner(asDblArray(basePt), utf8_to_wstr(prompt).c_str(), pnt));
    AcGePoint3d pnt3d = asPnt3d(pnt);
    return boost::python::make_tuple(res, pnt3d);
}

boost::python::tuple PyAcEditor::getInteger1(const std::string& prompt)
{
    return getInteger2(prompt, PromptCondition::eNone);
}

boost::python::tuple PyAcEditor::getInteger2(const std::string& prompt, PromptCondition condition)
{
    int val = 0;
    PyAutoLockGIL lock;
    PyEdUserInteraction ui;
    Acad::PromptStatus stat = static_cast<Acad::PromptStatus>(acedGetInt(utf8_to_wstr(prompt).c_str(), &val));
    if (GETBIT(condition, PromptCondition::eNoZero))
    {
        if (val == 0)
            return boost::python::make_tuple(Acad::PromptStatus::eRejected, val);
    }
    if (GETBIT(condition, PromptCondition::eNoNegative))
    {
        if (val < 0)
            return boost::python::make_tuple(Acad::PromptStatus::eRejected, val);
    }
    return boost::python::make_tuple(stat, val);
}

boost::python::tuple PyAcEditor::getDouble1(const std::string& prompt)
{
    return getDouble2(prompt, PromptCondition::eNone);
}

boost::python::tuple PyAcEditor::getDouble2(const std::string& prompt, PromptCondition condition)
{
    PyAutoLockGIL lock;
    PyEdUserInteraction ui;
    double val = 0;
    Acad::PromptStatus stat = static_cast<Acad::PromptStatus>(acedGetReal(utf8_to_wstr(prompt).c_str(), &val));
    if (GETBIT(condition, PromptCondition::eNoZero))
    {
        if (std::fabs(val) < AcGeContext::gTol.equalPoint())
            return boost::python::make_tuple(Acad::PromptStatus::eRejected, val);
    }
    if (GETBIT(condition, PromptCondition::eNoNegative))
    {
        if (val < 0)
            return boost::python::make_tuple(Acad::PromptStatus::eRejected, val);
    }
    return boost::python::make_tuple(stat, val);
}

boost::python::tuple PyAcEditor::getAngle(const AcGePoint3d& basePt, const std::string& prompt)
{
    PyAutoLockGIL lock;
    PyEdUserInteraction ui;
    std::pair<Acad::PromptStatus, double> res;
    res.first = static_cast<Acad::PromptStatus>(acedGetAngle(asDblArray(basePt), utf8_to_wstr(prompt).c_str(), &res.second));
    return boost::python::make_tuple(res.first, res.second);
}

boost::python::tuple PyAcEditor::getPoint1(const std::string& prompt)
{
    PyAutoLockGIL lock;
    PyEdUserInteraction ui;
    ads_point pnt;
    std::pair<Acad::PromptStatus, AcGePoint3d> res;
    res.first = static_cast<Acad::PromptStatus>(acedGetPoint(nullptr, utf8_to_wstr(prompt).c_str(), pnt));
    res.second = asPnt3d(pnt);
    return boost::python::make_tuple(res.first, res.second);
}

boost::python::tuple PyAcEditor::getPoint2(const AcGePoint3d& basePt, const std::string& prompt)
{
    PyAutoLockGIL lock;
    PyEdUserInteraction ui;
    ads_point pnt;
    std::pair<Acad::PromptStatus, AcGePoint3d> res;
    res.first = static_cast<Acad::PromptStatus>(acedGetPoint(asDblArray(basePt), utf8_to_wstr(prompt).c_str(), pnt));
    res.second = asPnt3d(pnt);
    return boost::python::make_tuple(res.first, res.second);
}

boost::python::tuple PyAcEditor::getDist1(const std::string& prompt)
{
    PyAutoLockGIL lock;
    PyEdUserInteraction ui;
    std::pair<Acad::PromptStatus, double> res;
    res.first = static_cast<Acad::PromptStatus>(acedGetDist(nullptr, utf8_to_wstr(prompt).c_str(), &res.second));
    if (res.first != Acad::eNormal)
        return boost::python::make_tuple(res.first, res.second);
    if (res.second < 0)
        return boost::python::make_tuple(Acad::PromptStatus::eRejected, res.second);
    return boost::python::make_tuple(res.first, res.second);
}

boost::python::tuple PyAcEditor::getDist2(const AcGePoint3d& basePt, const std::string& prompt)
{
    PyAutoLockGIL lock;
    PyEdUserInteraction ui;
    std::pair<Acad::PromptStatus, double> res;
    res.first = static_cast<Acad::PromptStatus>(acedGetDist(asDblArray(basePt), utf8_to_wstr(prompt).c_str(), &res.second));
    if (res.first != Acad::eNormal)
        return boost::python::make_tuple(res.first, res.second);
    if (res.second < 0)
        return boost::python::make_tuple(Acad::PromptStatus::eRejected, res.second);
    return boost::python::make_tuple(res.first, res.second);
}

boost::python::tuple PyAcEditor::getString1(const std::string& prompt)
{
    return getString4(0, prompt, PromptCondition::eNone);
}

boost::python::tuple PyAcEditor::getString2(int cronly, const std::string& prompt)
{
    return getString4(cronly, prompt, PromptCondition::eNone);
}

boost::python::tuple PyAcEditor::getString3(const std::string& prompt, PromptCondition condition)
{
    return getString4(0, prompt, condition);
}

boost::python::tuple PyAcEditor::getString4(int cronly, const std::string& prompt, PromptCondition condition)
{
    PyAutoLockGIL lock;
    PyEdUserInteraction ui;
    RxAutoOutStr val;
    Acad::PromptStatus stat = static_cast<Acad::PromptStatus>(acedGetFullString(cronly, utf8_to_wstr(prompt).c_str(), val.buf));
    const std::string sval = val.str();
    if (GETBIT(condition, PromptCondition::eNoEmpty))
    {
        if (sval.empty())
            return boost::python::make_tuple(Acad::PromptStatus::eRejected, sval);
    }
    return boost::python::make_tuple(stat, sval);
}

static boost::python::tuple entSelFilter(const std::string& prompt, const AcRxClass* desc)
{
    PyEdUserInteraction ui;
    ads_point pnt;
    PyDbObjectId id;
    ads_name name = { 0L };
    PyAutoLockGIL lock;
    auto stat = static_cast<Acad::PromptStatus>(acedEntSel(utf8_to_wstr(prompt).c_str(), name, pnt));
    if (stat == Acad::eNormal)
    {
        if (acdbGetObjectId(id.m_id, name) != eOk)
        {
            return boost::python::make_tuple<Acad::PromptStatus, PyDbObjectId, AcGePoint3d>(Acad::PromptStatus::eError, id, asPnt3d(pnt));
        }
        if (id.m_id.objectClass()->isDerivedFrom(desc))
        {
            return boost::python::make_tuple<Acad::PromptStatus, PyDbObjectId, AcGePoint3d>(stat, id, asPnt3d(pnt));
        }
        return boost::python::make_tuple<Acad::PromptStatus, PyDbObjectId, AcGePoint3d>(Acad::PromptStatus::eRejected, id, asPnt3d(pnt));
    }
    return boost::python::make_tuple<Acad::PromptStatus, PyDbObjectId, AcGePoint3d>(stat, id, asPnt3d(pnt));
}

static boost::python::tuple entSelFilterList(const std::string& prompt, const AcRxClassArray& descs)
{
    PyEdUserInteraction ui;
    ads_point pnt;
    PyDbObjectId id;
    ads_name name = { 0L };
    PyAutoLockGIL lock;
    auto stat = static_cast<Acad::PromptStatus>(acedEntSel(utf8_to_wstr(prompt).c_str(), name, pnt));
    if (stat == Acad::eNormal)
    {
        if (acdbGetObjectId(id.m_id, name) != eOk)
        {
            return boost::python::make_tuple<Acad::PromptStatus, PyDbObjectId, AcGePoint3d>(Acad::PromptStatus::eError, id, asPnt3d(pnt));
        }
        std::unordered_set<AcRxClass*> _set;
        for (auto& item : descs)
        {
            _set.insert(item);
        }
        if (_set.contains(id.m_id.objectClass()))
        {
            return boost::python::make_tuple<Acad::PromptStatus, PyDbObjectId, AcGePoint3d>(stat, id, asPnt3d(pnt));
        }
        return boost::python::make_tuple<Acad::PromptStatus, PyDbObjectId, AcGePoint3d>(Acad::PromptStatus::eRejected, id, asPnt3d(pnt));
    }
    return boost::python::make_tuple<Acad::PromptStatus, PyDbObjectId, AcGePoint3d>(stat, id, asPnt3d(pnt));
}

boost::python::tuple PyAcEditor::entSel0()
{
    return entSelFilter(enstselstr, AcDbEntity::desc());
}

boost::python::tuple PyAcEditor::entSel1(const std::string& prompt)
{
    return entSelFilter(prompt, AcDbEntity::desc());
}

boost::python::tuple PyAcEditor::entSel2(const std::string& prompt, const PyRxClass& desc)
{
    return entSelFilter(prompt, desc.impObj());
}

boost::python::tuple PyAcEditor::entSel3(const std::string& prompt, const boost::python::list& filter)
{
    const auto& classes = PyListToAcRxClassArray(filter);
    return entSelFilterList(prompt, classes);
}

boost::python::tuple PyAcEditor::entSel4(const boost::python::list& filter)
{
    const auto& classes = PyListToAcRxClassArray(filter);
    return entSelFilterList(enstselstr, classes);
}

boost::python::tuple PyAcEditor::entSel5(const PyRxClass& desc)
{
    return entSelFilter(enstselstr, desc.impObj());
}

static boost::python::tuple nEntSelP(const std::string& prompt, const AcGePoint3d& ptres, int opt)
{
    PyAutoLockGIL lock;
    PyEdUserInteraction ui;
    ads_point pnt = { ptres.x,ptres.y, ptres.z };
    ads_matrix xform;
    AcGeMatrix3d xformres;
    memcpy(xform, xformres.entry, sizeof(ads_matrix));
    struct resbuf* pRb = NULL;
    ads_name name = { 0L };
    auto flag = static_cast<Acad::PromptStatus>(acedNEntSelP(utf8_to_wstr(prompt).c_str(), name, pnt, opt, xform, &pRb));
    AcResBufPtr buf(pRb);
    PyDbObjectId id;
    acdbGetObjectId(id.m_id, name);
    memcpy(xformres.entry, xform, sizeof(ads_matrix));
    boost::python::list pyIds;
    if (pRb != nullptr)
    {
        for (resbuf* pTail = pRb; pTail != nullptr; pTail = pTail->rbnext)
        {
            if (pTail->restype != RTENAME)
                continue;
            PyDbObjectId sid;
            if (acdbGetObjectId(sid.m_id, pTail->resval.rlname) == eOk)
                pyIds.append(sid);
        }
    }
    return boost::python::make_tuple(flag, id, asPnt3d(pnt), xformres, pyIds);
}

boost::python::tuple PyAcEditor::nEntSelP1(const std::string& prompt)
{
    AcGePoint3d dummyptp;
    return nEntSelP(prompt, dummyptp, 0);
}

boost::python::tuple PyAcEditor::nEntSelP2(const std::string& prompt, const AcGePoint3d& ptres)
{
    return nEntSelP(prompt, ptres, 1);
}

static boost::python::tuple nEntSelPEx(const std::string& prompt, const AcGePoint3d& ptres, int opt, unsigned int uTransSpaceFlag)
{
#if defined(_ZRXTARGET) && _ZRXTARGET <= 260 || defined(_GRXTARGET) && _GRXTARGET <= 260 ||  defined(_IRXTARGET) && _IRXTARGET <= 140
    throw PyNotimplementedByHost();
#else
    PyAutoLockGIL lock;
    PyEdUserInteraction ui;
    ads_point pnt = { ptres.x,ptres.y, ptres.z };
    ads_matrix xform;
    AcGeMatrix3d xformres;
    memcpy(xform, xformres.entry, sizeof(ads_matrix));
    struct resbuf* pRb = NULL;
    ads_name name = { 0L };
    int64_t gsmarker = -1;
    const auto status = static_cast<Acad::PromptStatus>(acedNEntSelPEx(utf8_to_wstr(prompt).c_str(), name, pnt, opt, xform, &pRb, uTransSpaceFlag, &gsmarker));
    AcResBufPtr buf(pRb);
    PyDbObjectId id;
    acdbGetObjectId(id.m_id, name);
    memcpy(xformres.entry, xform, sizeof(ads_matrix));
    boost::python::list pyIds;
    if (pRb != nullptr)
    {
        for (resbuf* pTail = pRb; pTail != nullptr; pTail = pTail->rbnext)
        {
            if (pTail->restype != RTENAME)
                continue;
            PyDbObjectId sid;
            if (acdbGetObjectId(sid.m_id, pTail->resval.rlname) == eOk)
                pyIds.append(sid);
        }
    }
    return boost::python::make_tuple(status, id, asPnt3d(pnt), xformres, gsmarker, pyIds);
#endif
}

boost::python::tuple PyAcEditor::nEntSelPEx1(const std::string& prompt, int uTransSpaceFlag)
{
    AcGePoint3d dummyptp;
    return nEntSelPEx(prompt, dummyptp, 0, uTransSpaceFlag);
}

boost::python::tuple PyAcEditor::nEntSelPEx2(const std::string& prompt, const AcGePoint3d& ptres, int uTransSpaceFlag)
{
    return nEntSelPEx(prompt, ptres, 1, uTransSpaceFlag);
}

boost::python::tuple PyAcEditor::select1()
{
    PyEdUserInteraction ui;
    ads_name name = { 0L };
    auto stat = static_cast<Acad::PromptStatus>(acedSSGet(nullptr, nullptr, nullptr, nullptr, name));
    return makeSelectionResult(name, stat);
}

boost::python::tuple PyAcEditor::select2(const boost::python::object& filter)
{
    PyEdUserInteraction ui;
    ads_name name = { 0L };
    AcResBufPtr pFilter(listToResbuf(filter));
    auto stat = static_cast<Acad::PromptStatus>(acedSSGet(nullptr, nullptr, nullptr, pFilter.get(), name));
    return makeSelectionResult(name, stat);
}

boost::python::tuple PyAcEditor::select3(const std::string& add, const std::string& remove)
{
    PyEdUserInteraction ui;
    ads_name name = { 0L };
    const CString csAdd = utf8_to_wstr(add).c_str();
    const CString csRem = utf8_to_wstr(remove).c_str();
    const wchar_t* prompts[] = { (const wchar_t*)csAdd, (const wchar_t*)csRem };
    auto stat = static_cast<Acad::PromptStatus>(acedSSGet(_T("_:$"), prompts, nullptr, nullptr, name));
    return makeSelectionResult(name, stat);
}

boost::python::tuple PyAcEditor::select4(const std::string& add, const std::string& remove, const boost::python::object& filter)
{
    PyEdUserInteraction ui;
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
    PyEdUserInteraction ui;
    ads_name name = { 0L };
    auto stat = static_cast<Acad::PromptStatus>(acedSSGet(_T("_A"), nullptr, nullptr, nullptr, name));
    return makeSelectionResult(name, stat);
}

boost::python::tuple PyAcEditor::selectAll2(const boost::python::object& filter)
{
    PyEdUserInteraction ui;
    ads_name name = { 0L };
    AcResBufPtr pFilter(listToResbuf(filter));
    auto stat = static_cast<Acad::PromptStatus>(acedSSGet(_T("_A"), nullptr, nullptr, pFilter.get(), name));
    return makeSelectionResult(name, stat);
}

boost::python::tuple PyAcEditor::selectImplied()
{
    PyEdUserInteraction ui;
    resbuf* resbufPtr = nullptr;
    auto stat = static_cast<Acad::PromptStatus>(acedSSGetFirst(0L, &resbufPtr));
    AcResBufPtr pHolder(resbufPtr);
    return makeSelectionResult(resbufPtr->resval.rlname, stat);
}

boost::python::tuple PyAcEditor::selectWindow1(const AcGePoint3d& pt1, const AcGePoint3d& pt2)
{
    PyEdUserInteraction ui;
    ads_name name = { 0L };
    auto stat = static_cast<Acad::PromptStatus>(acedSSGet(_T("_W"), asDblArray(pt1), asDblArray(pt2), nullptr, name));
    return makeSelectionResult(name, stat);
}

boost::python::tuple PyAcEditor::selectWindow2(const AcGePoint3d& pt1, const AcGePoint3d& pt2, const boost::python::object& filter)
{
    PyEdUserInteraction ui;
    ads_name name = { 0L };
    AcResBufPtr pFilter(listToResbuf(filter));
    auto stat = static_cast<Acad::PromptStatus>(acedSSGet(_T("_W"), asDblArray(pt1), asDblArray(pt2), pFilter.get(), name));
    return makeSelectionResult(name, stat);
}

boost::python::tuple PyAcEditor::selectFence1(const boost::python::object& points)
{
    PyEdUserInteraction ui;
    ads_name name = { 0L };
    AcResBufPtr rbPoints(AcGePoint3dArrayToResbuf(PyListToPoint3dArray(points)));
    auto stat = static_cast<Acad::PromptStatus>(acedSSGet(_T("_F"), rbPoints.get(), nullptr, nullptr, name));
    return makeSelectionResult(name, stat);
}

boost::python::tuple PyAcEditor::selectFence2(const boost::python::object& points, const boost::python::object& filter)
{
    PyEdUserInteraction ui;
    ads_name name = { 0L };
    AcResBufPtr pFilter(listToResbuf(filter));
    AcResBufPtr rbPoints(AcGePoint3dArrayToResbuf(PyListToPoint3dArray(points)));
    auto stat = static_cast<Acad::PromptStatus>(acedSSGet(_T("_F"), rbPoints.get(), nullptr, pFilter.get(), name));
    return makeSelectionResult(name, stat);
}

boost::python::tuple PyAcEditor::selectWindowPolygon1(const boost::python::object& points)
{
    PyEdUserInteraction ui;
    ads_name name = { 0L };
    AcResBufPtr rbPoints(AcGePoint3dArrayToResbuf(PyListToPoint3dArray(points)));
    auto stat = static_cast<Acad::PromptStatus>(acedSSGet(_T("_WP"), rbPoints.get(), nullptr, nullptr, name));
    return makeSelectionResult(name, stat);
}

boost::python::tuple PyAcEditor::selectWindowPolygon2(const boost::python::object& points, const boost::python::object& filter)
{
    PyEdUserInteraction ui;
    ads_name name = { 0L };
    AcResBufPtr pFilter(listToResbuf(filter));
    AcResBufPtr rbPoints(AcGePoint3dArrayToResbuf(PyListToPoint3dArray(points)));
    auto stat = static_cast<Acad::PromptStatus>(acedSSGet(_T("_WP"), rbPoints.get(), nullptr, pFilter.get(), name));
    return makeSelectionResult(name, stat);
}

boost::python::tuple PyAcEditor::selectPrevious1()
{
    PyEdUserInteraction ui;
    ads_name name = { 0L };
    auto stat = static_cast<Acad::PromptStatus>(acedSSGet(_T("_P"), nullptr, nullptr, nullptr, name));
    return makeSelectionResult(name, stat);
}

boost::python::tuple PyAcEditor::selectPrevious2(const boost::python::object& filter)
{
    PyEdUserInteraction ui;
    ads_name name = { 0L };
    AcResBufPtr pFilter(listToResbuf(filter));
    auto stat = static_cast<Acad::PromptStatus>(acedSSGet(_T("_P"), nullptr, nullptr, pFilter.get(), name));
    return makeSelectionResult(name, stat);
}

boost::python::tuple PyAcEditor::selectLast1()
{
    PyEdUserInteraction ui;
    ads_name name = { 0L };
    auto stat = static_cast<Acad::PromptStatus>(acedSSGet(_T("_L"), nullptr, nullptr, nullptr, name));
    return makeSelectionResult(name, stat);
}

boost::python::tuple PyAcEditor::selectLast2(const boost::python::object& filter)
{
    PyEdUserInteraction ui;
    ads_name name = { 0L };
    AcResBufPtr pFilter(listToResbuf(filter));
    auto stat = static_cast<Acad::PromptStatus>(acedSSGet(_T("_L"), nullptr, nullptr, pFilter.get(), name));
    return makeSelectionResult(name, stat);
}

boost::python::tuple PyAcEditor::ssget1(const std::string& args, const boost::python::object& arg1, const boost::python::object& arg2)
{
    PyEdUserInteraction ui;
    ads_name name = { 0L };
    ssArgExtracter ssarg1(arg1);
    ssArgExtracter ssarg2(arg2);
    AcString strArg = utf8_to_wstr(args).c_str();
    auto stat = static_cast<Acad::PromptStatus>(acedSSGet(strArg, ssarg1.extractArg(), ssarg2.extractArg(), nullptr, name));
    return makeSelectionResult(name, stat);
}

boost::python::tuple PyAcEditor::ssget2(const std::string& args, const boost::python::object& arg1, const boost::python::object& arg2, const boost::python::object& filter)
{
    PyEdUserInteraction ui;
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
    PyThrowBadEs(acedGetCurrentUCS(mat));
    return mat;
}

void PyAcEditor::setCurUCS(const AcGeMatrix3d& mat)
{
    return PyThrowBadEs(acedSetCurrentUCS(mat));
}

PyDbObjectId PyAcEditor::activeViewportId()
{
    return PyDbObjectId(acedActiveViewportId());
}

PyDbObjectId PyAcEditor::curViewportObjectId()
{
    return PyDbObjectId(acedGetCurViewportObjectId());
}

AcGeVector3d PyAcEditor::ucsNormalVector()
{
    AcGeVector3d vec;
    ::ucsNormalVector(vec);
    return vec;
}

AcGeVector3d PyAcEditor::ucsXDir()
{
    return ::ucsXDir();
}

AcGeVector3d PyAcEditor::ucsYDir()
{
    return ::ucsYDir();
}

Acad::PromptStatus PyAcEditor::initGet(int val, const std::string& skwl)
{
    return static_cast<Acad::PromptStatus>(acedInitGet(val, utf8_to_wstr(skwl).c_str()));
}

std::string PyAcEditor::getInput()
{
    AcString str;
    acedGetInput(str);
    return wstr_to_utf8(str);
}

boost::python::tuple PyAcEditor::getKword(const std::string& skwl)
{
    PyAutoLockGIL lock;
    RxAutoOutStr pStr;
    auto resval = static_cast<Acad::PromptStatus>(acedGetFullKword(utf8_to_wstr(skwl).c_str(), pStr.buf));
    return boost::python::make_tuple(resval, pStr.str());
}

boost::python::list PyAcEditor::traceBoundary(const AcGePoint3d& seedPoint, bool detectIslands)
{
    PyAutoLockGIL lock;
    PyEdUserInteraction ui;
    AcAxDocLock dlock;
    boost::python::list pyList;
    AcDbVoidPtrArray resultingBoundarySet;
    PyThrowBadEs(acedTraceBoundary(seedPoint, detectIslands, resultingBoundarySet));
    for (auto ptr : resultingBoundarySet)
        pyList.append(PyDbPolyline(static_cast<AcDbPolyline*>(ptr), true));
    return pyList;
}

boost::python::list PyAcEditor::getCurrentSelectionSet()
{
    AcDbObjectIdArray sset;
    PyThrowBadEs(acedGetCurrentSelectionSet(sset));
    return ObjectIdArrayToPyList(sset);
}

void PyAcEditor::setAllowDuplicateSelection(PyApDocument& doc, bool flag)
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(::setAllowDuplicateSelection(doc.impObj(), flag));
#endif
}

bool PyAcEditor::duplicateSelectionsAllowed(PyApDocument& doc)
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost();
#else
    return ::duplicateSelectionsAllowed(doc.impObj());
#endif
}

void PyAcEditor::regen()
{
    ads_regen();
}

int PyAcEditor::getViewportNumber(int ptx, int pty)
{
    return acedGetWinNum(ptx, pty);
}

std::string PyAcEditor::className()
{
    return std::string{ "Editor" };
}
