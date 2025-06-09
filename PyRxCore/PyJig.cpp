#include "stdafx.h"
#include "PyJig.h"
#include "PyDbObjectId.h"
#include "PyDbEntity.h"
#include "PyGiCommonDraw.h"
#include "PyEdUserInteraction.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------------------------------------------------------
void makePyEdJigWrapper()
{
    PyDocString DS("Jig");
    class_<PyJig, boost::noncopyable>("Jig", boost::python::no_init)
        .def(init<const PyDbEntity&>(DS.ARGS({ "entity: PyDb.Entity" })))
        .def("drag", &PyJig::dragwr1)
#if !defined(_BRXTARGET250)
        .def("drag", &PyJig::dragwr2, DS.ARGS({ "style: PyEd.DragStyle = ..." }))
#endif
        .def("sampler", &PyJig::sampler, DS.ARGS())
        .def("update", &PyJig::update, DS.ARGS())
        .def("append", &PyJig::appendwr, DS.ARGS())
        .def("keywordList", &PyJig::keywordListWr, DS.ARGS())
        .def("setKeywordList", &PyJig::setKeywordListWr, DS.ARGS({ "val: str" }))
        .def("dispPrompt", &PyJig::dispPromptWr, DS.ARGS())
        .def("setDispPrompt", &PyJig::setDispPromptWr, DS.ARGS({ "val: str" }))
        .def("acquireString", &PyJig::acquireStringWr, DS.ARGS())
        .def("acquireAngle", &PyJig::acquireAngleWr1)
        .def("acquireAngle", &PyJig::acquireAngleWr2, DS.ARGS({ "basePnt: PyGe.Point3d = ..." }))
        .def("acquireDist", &PyJig::acquireDistWr1)
        .def("acquireDist", &PyJig::acquireDistWr2, DS.ARGS({ "basePnt: PyGe.Point3d = ..." }))
        .def("acquirePoint", &PyJig::acquirePointWr1)
        .def("acquirePoint", &PyJig::acquirePointWr2, DS.ARGS({ "basePnt: PyGe.Point3d = ..." }))
        .def("specialCursorType", &PyJig::specialCursorTypeWr, DS.ARGS())
        .def("setSpecialCursorType", &PyJig::setSpecialCursorTypeWr, DS.ARGS({ "val: PyEd.CursorType" }))
        .def("userInputControls", &PyJig::userInputControlsWr, DS.ARGS())
        .def("setUserInputControls", &PyJig::setUserInputControlsWr, DS.ARGS({ "val:  PyEd.UserInputControls" }))
        .def("className", &PyJig::className, DS.SARGS()).staticmethod("className")
        ;

    enum_<PyJig::DragStatus>("DragStatus")
        .value("kModeless", PyJig::DragStatus::kModeless)
        .value("kNoChange", PyJig::DragStatus::kNoChange)
        .value("kCancel", PyJig::DragStatus::kCancel)
        .value("kOther", PyJig::DragStatus::kOther)
        .value("kNull", PyJig::DragStatus::kNull)
        .value("eNormal", PyJig::DragStatus::kNormal)
        .value("eOk", PyJig::DragStatus::kNormal)
        .value("kNormal", PyJig::DragStatus::kNormal)
        .value("kKW1", PyJig::DragStatus::kKW1)
        .value("kKW2", PyJig::DragStatus::kKW2)
        .value("kKW3", PyJig::DragStatus::kKW3)
        .value("kKW4", PyJig::DragStatus::kKW4)
        .value("kKW5", PyJig::DragStatus::kKW5)
        .value("kKW6", PyJig::DragStatus::kKW6)
        .value("kKW7", PyJig::DragStatus::kKW7)
        .value("kKW8", PyJig::DragStatus::kKW8)
        .value("kKW9", PyJig::DragStatus::kKW9)
        .export_values()
        ;
    enum_<PyJig::CursorType>("CursorType")
        .value("kNoSpecialCursor", PyJig::CursorType::kNoSpecialCursor)
        .value("kCrosshair", PyJig::CursorType::kCrosshair)
        .value("kRectCursor", PyJig::CursorType::kRectCursor)
        .value("kRubberBand", PyJig::CursorType::kRubberBand)
        .value("kNotRotated", PyJig::CursorType::kNotRotated)
        .value("kTargetBox", PyJig::CursorType::kTargetBox)
        .value("kRotatedCrosshair", PyJig::CursorType::kRotatedCrosshair)
        .value("kCrosshairNoRotate", PyJig::CursorType::kCrosshairNoRotate)
        .value("kInvisible", PyJig::CursorType::kInvisible)
        .value("kEntitySelect", PyJig::CursorType::kEntitySelect)
        .value("kParallelogram", PyJig::CursorType::kParallelogram)
        .value("kEntitySelectNoPersp", PyJig::CursorType::kEntitySelectNoPersp)
        .value("kPkfirstOrGrips", PyJig::CursorType::kPkfirstOrGrips)
        .value("kCrosshairDashed", PyJig::CursorType::kCrosshairDashed)
        .export_values()
        ;
    enum_<PyJig::UserInputControls>("UserInputControls")
        .value("kGovernedByOrthoMode", PyJig::UserInputControls::kGovernedByOrthoMode)
        .value("kNullResponseAccepted", PyJig::UserInputControls::kNullResponseAccepted)
        .value("kDontEchoCancelForCtrlC", PyJig::UserInputControls::kDontEchoCancelForCtrlC)
        .value("kDontUpdateLastPoint", PyJig::UserInputControls::kDontUpdateLastPoint)
        .value("kNoDwgLimitsChecking", PyJig::UserInputControls::kNoDwgLimitsChecking)
        .value("kNoZeroResponseAccepted", PyJig::UserInputControls::kNoZeroResponseAccepted)
        .value("kNoNegativeResponseAccepted", PyJig::UserInputControls::kNoNegativeResponseAccepted)
        .value("kAccept3dCoordinates", PyJig::UserInputControls::kAccept3dCoordinates)
        .value("kAcceptMouseUpAsPoint", PyJig::UserInputControls::kAcceptMouseUpAsPoint)
        .value("kAnyBlankTerminatesInput", PyJig::UserInputControls::kAnyBlankTerminatesInput)
        .value("kInitialBlankTerminatesInput", PyJig::UserInputControls::kInitialBlankTerminatesInput)
        .value("kAcceptOtherInputString", PyJig::UserInputControls::kAcceptOtherInputString)
        .value("kGovernedByUCSDetect", PyJig::UserInputControls::kGovernedByUCSDetect)
        .value("kNoZDirectionOrtho", PyJig::UserInputControls::kNoZDirectionOrtho)
        .value("kImpliedFaceForUCSChange", PyJig::UserInputControls::kImpliedFaceForUCSChange)
        .value("kUseBasePointElevation", PyJig::UserInputControls::kUseBasePointElevation)
        .value("kDisableDirectDistanceInput", PyJig::UserInputControls::kDisableDirectDistanceInput)
        .export_values()
        ;

#if !defined (_BRXTARGET250)
    class_<AcEdDragStyle>("DragStyle")
        .def(init<>())
        .def(init<AcEdDragStyle::StyleType, AcEdDragStyle::StyleType>(DS.ARGS({ "styleTypeForOriginal: PyEd.DragStyleType","styleTypeForDragged: PyEd.DragStyleType" })))
        .def("styleTypeForOriginal", &AcEdDragStyle::styleTypeForOriginal, DS.ARGS())
        .def("styleTypeForDragged", &AcEdDragStyle::styleTypeForDragged, DS.ARGS())
        .def("setStyleTypeForOriginal", &AcEdDragStyle::setStyleTypeForOriginal, DS.ARGS({ "styleTypeForOriginal: PyEd.DragStyleType" }))
        .def("setStyleTypeForDragged", &AcEdDragStyle::setStyleTypeForDragged, DS.ARGS({ "styleTypeForDragged: PyEd.DragStyleType" }))
        ;
#endif
#if !defined (_BRXTARGET250)
    enum_<AcEdDragStyle::StyleType>("DragStyleType")
        .value("kNone", AcEdDragStyle::StyleType::kNone)
        .value("kHide", AcEdDragStyle::StyleType::kHide)
        .value("kTransparent25", AcEdDragStyle::StyleType::kTransparent25)
        .value("kTransparent75", AcEdDragStyle::StyleType::kTransparent75)
        .value("kDeletedEffect", AcEdDragStyle::StyleType::kDeletedEffect)
        .value("kHighlight", AcEdDragStyle::StyleType::kHighlight)
        .value("kNotSet", AcEdDragStyle::StyleType::kNotSet)
        .export_values()
        ;
#endif
}

PyJig::PyJig(const PyDbEntity& ent)
    : AcEdJig(), m_pEnt(ent.impObj())
{
}

AcEdJig::DragStatus PyJig::dragwr1()
{
    return this->drag();
}

#if !defined(_BRXTARGET250)
AcEdJig::DragStatus PyJig::dragwr2(const AcEdDragStyle& style)
{
    return  this->drag(style);
}
#endif

AcEdJig::DragStatus PyJig::sampler()
{
    PyAutoLockGIL lock;
    try
    {
        if (const override& f = this->get_override("sampler"))
            return f();
    }
    catch (...)
    {
        printExceptionMsg();
    }
    return AcEdJig::DragStatus::kCancel;
}

Adesk::Boolean PyJig::update()
{
    PyAutoLockGIL lock;
    try
    {
        if (const override& f = this->get_override("update"))
            return f();
    }
    catch (...)
    {
        printExceptionMsg();
    }
    return true;
}

PyDbObjectId PyJig::appendwr()
{
    return PyDbObjectId(this->append());
}

std::string PyJig::keywordListWr()
{
    return wstr_to_utf8(this->keywordList());
}

void PyJig::setKeywordListWr(const std::string& val)
{
    this->setKeywordList(utf8_to_wstr(val).c_str());
}

std::string PyJig::dispPromptWr()
{
    return wstr_to_utf8(this->dispPrompt());
}

void PyJig::setDispPromptWr(const std::string& val)
{
    this->setDispPrompt(utf8_to_wstr(val).c_str());
}

boost::python::tuple PyJig::acquireStringWr()
{
#if defined(_BRXTARGET250) || defined(_GRXTARGET260) || defined(_ZRXTARGET260)
    PyAutoLockGIL lock;
    wchar_t value[2049];
    auto result = this->acquireString(value);
    return boost::python::make_tuple(result, wstr_to_utf8(value));
#endif

#ifdef _ARXTARGET
    PyAutoLockGIL lock;
    AcString value;
    auto result = this->acquireString(value);
    return boost::python::make_tuple(result, wstr_to_utf8(value));
#endif
}

boost::python::tuple PyJig::acquireAngleWr1()
{
    PyAutoLockGIL lock;
    double value;
    auto result = this->acquireAngle(value);
    return boost::python::make_tuple(result, value);
}

boost::python::tuple PyJig::acquireAngleWr2(const AcGePoint3d& basePnt)
{
    PyAutoLockGIL lock;
    double value;
    auto result = this->acquireAngle(value, basePnt);
    return boost::python::make_tuple(result, value);
}

boost::python::tuple PyJig::acquireDistWr1()
{
    PyAutoLockGIL lock;
    double value;
    auto result = this->acquireDist(value);
    return boost::python::make_tuple(result, value);
}

boost::python::tuple PyJig::acquireDistWr2(const AcGePoint3d& basePnt)
{
    PyAutoLockGIL lock;
    double value;
    auto result = this->acquireDist(value, basePnt);
    return boost::python::make_tuple(result, value);
}

boost::python::tuple PyJig::acquirePointWr1()
{
    PyAutoLockGIL lock;
    AcGePoint3d value;
    auto result = this->acquirePoint(value);
    return boost::python::make_tuple(result, value);
}

boost::python::tuple PyJig::acquirePointWr2(const AcGePoint3d& basePnt)
{
    PyAutoLockGIL lock;
    AcGePoint3d value;
    auto result = this->acquirePoint(value, basePnt);
    return boost::python::make_tuple(result, value);
}

AcEdJig::CursorType PyJig::specialCursorTypeWr()
{
    return this->specialCursorType();
}

void PyJig::setSpecialCursorTypeWr(AcEdJig::CursorType val)
{
    this->setSpecialCursorType(val);
}

AcEdJig::UserInputControls PyJig::userInputControlsWr()
{
    return this->userInputControls();
}

void PyJig::setUserInputControlsWr(AcEdJig::UserInputControls val)
{
    return this->setUserInputControls(val);
}

AcDbEntity* PyJig::entity() const
{
    return m_pEnt;
}

std::string PyJig::className()
{
    return "AcEdJig";
}

//--------------------------------------------------------------------------------------------------------
//PyDrawJig
void makePyEdDrawJigWrapper()
{
    PyDocString DS("DrawJig");
    class_<PyDrawJig, boost::noncopyable>("DrawJig")
        .def(init<>(DS.ARGS()))
        .def("drag", &PyDrawJig::dragwr1)
#if !defined(_BRXTARGET250)
        .def("drag", &PyDrawJig::dragwr2, DS.ARGS({ "style: PyEd.DragStyle = ..." }))
#endif
        .def("sampler", &PyDrawJig::sampler, DS.ARGS())
        .def("update", &PyDrawJig::update, DS.ARGS())
        .def("keywordList", &PyDrawJig::keywordListWr, DS.ARGS())
        .def("setKeywordList", &PyDrawJig::setKeywordListWr, DS.ARGS({ "val: str" }))
        .def("dispPrompt", &PyDrawJig::dispPromptWr, DS.ARGS())
        .def("setDispPrompt", &PyDrawJig::setDispPromptWr, DS.ARGS({ "val: str" }))
        .def("acquireString", &PyDrawJig::acquireStringWr, DS.ARGS())
        .def("acquireAngle", &PyDrawJig::acquireAngleWr1)
        .def("acquireAngle", &PyDrawJig::acquireAngleWr2, DS.ARGS({ "basePnt: PyGe.Point3d = ..." }))
        .def("acquireDist", &PyDrawJig::acquireDistWr1)
        .def("acquireDist", &PyDrawJig::acquireDistWr2, DS.ARGS({ "basePnt: PyGe.Point3d = ..." }))
        .def("acquirePoint", &PyDrawJig::acquirePointWr1)
        .def("acquirePoint", &PyDrawJig::acquirePointWr2, DS.ARGS({ "basePnt: PyGe.Point3d = ..." }))
        .def("specialCursorType", &PyDrawJig::specialCursorTypeWr, DS.ARGS())
        .def("setSpecialCursorType", &PyDrawJig::setSpecialCursorTypeWr, DS.ARGS({ "val: PyEd.CursorType" }))
        .def("userInputControls", &PyDrawJig::userInputControlsWr, DS.ARGS())
        .def("setUserInputControls", &PyDrawJig::setUserInputControlsWr, DS.ARGS({ "val:  PyEd.UserInputControls" }))
        .def("worldDraw", &PyDrawJig::worldDrawWr, DS.ARGS({ "wd: PyGi.WorldDraw" }))
        .def("viewportDraw", &PyDrawJig::viewportDrawWr, DS.ARGS({ "wd: PyGi.ViewportDraw" }))
        .def("className", &PyDrawJig::className, DS.SARGS()).staticmethod("className")
        ;
}

PyDrawJig::PyDrawJig()
{
    this->setDatabaseDefaults();
}

AcEdJig::DragStatus PyDrawJig::dragwr1()
{
    return this->drag();
}

#if !defined(_BRXTARGET250)
AcEdJig::DragStatus PyDrawJig::dragwr2(const AcEdDragStyle& style)
{
#if defined(_ZRXTARGET260)
    throw PyNotimplementedByHost{};
#else
    return this->drag(style);
#endif
}
#endif

AcEdJig::DragStatus PyDrawJig::sampler()
{
    PyAutoLockGIL lock;
    try
    {
        if (const override& f = this->get_override("sampler"))
            return f();
    }
    catch (...)
    {
        printExceptionMsg();
    }
    return AcEdJig::DragStatus::kCancel;
}

Adesk::Boolean PyDrawJig::update()
{
    PyAutoLockGIL lock;
    try
    {
        if (const override& f = this->get_override("update"))
            return f();
    }
    catch (...)
    {
        printExceptionMsg();
    }
    return false;
}

std::string PyDrawJig::keywordListWr()
{
    return wstr_to_utf8(this->keywordList());
}

void PyDrawJig::setKeywordListWr(const std::string& val)
{
    this->setKeywordList(utf8_to_wstr(val).c_str());
}

std::string PyDrawJig::dispPromptWr()
{
    return wstr_to_utf8(this->dispPrompt());
}

void PyDrawJig::setDispPromptWr(const std::string& val)
{
    this->setDispPrompt(utf8_to_wstr(val).c_str());
}

boost::python::tuple PyDrawJig::acquireStringWr()
{
#if defined(_BRXTARGET250) || defined(_GRXTARGET260) || defined(_ZRXTARGET260)
    PyAutoLockGIL lock;
    wchar_t value[2049];
    auto result = this->acquireString(value);
    return boost::python::make_tuple(result, wstr_to_utf8(value));
#endif

#ifdef _ARXTARGET 
    PyAutoLockGIL lock;
    AcString value;
    auto result = this->acquireString(value);
    return boost::python::make_tuple(result, wstr_to_utf8(value));
#endif
}

boost::python::tuple PyDrawJig::acquireAngleWr1()
{
    PyAutoLockGIL lock;
    double value;
    auto result = this->acquireAngle(value);
    return boost::python::make_tuple(result, value);
}

boost::python::tuple PyDrawJig::acquireAngleWr2(const AcGePoint3d& basePnt)
{
    PyAutoLockGIL lock;
    double value;
    auto result = this->acquireAngle(value, basePnt);
    return boost::python::make_tuple(result, value);
}

boost::python::tuple PyDrawJig::acquireDistWr1()
{
    PyAutoLockGIL lock;
    double value;
    auto result = this->acquireDist(value);
    return boost::python::make_tuple(result, value);
}

boost::python::tuple PyDrawJig::acquireDistWr2(const AcGePoint3d& basePnt)
{
    PyAutoLockGIL lock;
    double value;
    auto result = this->acquireDist(value, basePnt);
    return boost::python::make_tuple(result, value);
}

boost::python::tuple PyDrawJig::acquirePointWr1()
{
    PyAutoLockGIL lock;
    AcGePoint3d value;
    auto result = this->acquirePoint(value);
    return boost::python::make_tuple(result, value);
}

boost::python::tuple PyDrawJig::acquirePointWr2(const AcGePoint3d& basePnt)
{
    PyAutoLockGIL lock;
    AcGePoint3d value;
    auto result = this->acquirePoint(value, basePnt);
    return boost::python::make_tuple(result, value);
}

AcEdJig::CursorType PyDrawJig::specialCursorTypeWr()
{
    return this->specialCursorType();
}

void PyDrawJig::setSpecialCursorTypeWr(AcEdJig::CursorType val)
{
    this->setSpecialCursorType(val);
}

AcEdJig::UserInputControls PyDrawJig::userInputControlsWr()
{
    return this->userInputControls();
}

void PyDrawJig::setUserInputControlsWr(AcEdJig::UserInputControls val)
{
    return this->setUserInputControls(val);
}

Adesk::Boolean PyDrawJig::worldDrawWr(PyGiWorldDraw& wd)
{
    PyAutoLockGIL lock;
    try
    {
        if (override f = this->get_override("worldDraw"))
            return f(wd);
    }
    catch (...)
    {
        printExceptionMsg();
    }
    return false;
}

void PyDrawJig::viewportDrawWr(PyGiViewportDraw& vd)
{
    try
    {
        PyAutoLockGIL lock;
        if (override f = this->get_override("ViewportDraw"))
            f(vd);
    }
    catch (...)
    {
        printExceptionMsg();
    }
}

Adesk::Boolean PyDrawJig::subWorldDraw(AcGiWorldDraw* wd)
{
    PyGiWorldDraw draw(wd, false);
    return worldDrawWr(draw);
}

void PyDrawJig::subViewportDraw(AcGiViewportDraw* vd)
{
    PyGiViewportDraw draw(vd, false);
    viewportDrawWr(draw);
}

AcDbEntity* PyDrawJig::entity() const
{
    return const_cast<AcDbEntity*>(static_cast<const AcDbEntity*>(this));
}

std::string PyDrawJig::className()
{
    return "AcEdJig";
}
