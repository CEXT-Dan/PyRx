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

    class_<PyJig, boost::noncopyable>("Jig", boost::python::no_init)
        .def(init<const PyDbEntity&>())
        .def("drag", &PyJig::dragwr1)
#ifndef _BRXTARGET 
        .def("drag", &PyJig::dragwr2)
#endif
        .def("sampler", &PyJig::sampler)
        .def("update", &PyJig::update)
        .def("append", &PyJig::appendwr)
        .def("keywordList", &PyJig::keywordListWr)
        .def("setKeywordList", &PyJig::setKeywordListWr)
        .def("dispPrompt", &PyJig::dispPromptWr)
        .def("setDispPrompt", &PyJig::setDispPromptWr)
        .def("acquireString", &PyJig::acquireStringWr)
        .def("acquireAngle", &PyJig::acquireAngleWr1)
        .def("acquireAngle", &PyJig::acquireAngleWr2)
        .def("acquireDist", &PyJig::acquireDistWr1)
        .def("acquireDist", &PyJig::acquireDistWr2)
        .def("acquirePoint", &PyJig::acquirePointWr1)
        .def("acquirePoint", &PyJig::acquirePointWr2)
        .def("specialCursorType", &PyJig::specialCursorTypeWr)
        .def("setSpecialCursorType", &PyJig::setSpecialCursorTypeWr)
        .def("userInputControls", &PyJig::userInputControlsWr)
        .def("setUserInputControls", &PyJig::setUserInputControlsWr)
        .def("className", &PyJig::className).staticmethod("className")
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

#ifndef _BRXTARGET 
    class_<AcEdDragStyle>("DragStyle")
        .def(init<>())
        .def(init<AcEdDragStyle::StyleType, AcEdDragStyle::StyleType>())
        .def("styleTypeForOriginal", &AcEdDragStyle::styleTypeForOriginal)
        .def("styleTypeForDragged", &AcEdDragStyle::styleTypeForDragged)
        .def("setStyleTypeForOriginal", &AcEdDragStyle::setStyleTypeForOriginal)
        .def("setStyleTypeForDragged", &AcEdDragStyle::setStyleTypeForDragged)
        ;
#endif

#ifndef _BRXTARGET 
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
    : m_pEnt(ent.impObj()), AcEdJig()
{
}

AcEdJig::DragStatus PyJig::dragwr1()
{
    return this->drag();
}

#ifndef _BRXTARGET 
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
#if _ZRXTARGET == 240 || _BRXTARGET == 240
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
    class_<PyDrawJig, boost::noncopyable>("DrawJig")
        .def("drag", &PyDrawJig::dragwr1)
#ifndef _BRXTARGET 
        .def("drag", &PyDrawJig::dragwr2)
#endif
        .def("sampler", &PyDrawJig::sampler)
        .def("update", &PyDrawJig::update)
        .def("keywordList", &PyDrawJig::keywordListWr)
        .def("setKeywordList", &PyDrawJig::setKeywordListWr)
        .def("dispPrompt", &PyDrawJig::dispPromptWr)
        .def("setDispPrompt", &PyDrawJig::setDispPromptWr)
        .def("acquireString", &PyDrawJig::acquireStringWr)
        .def("acquireAngle", &PyDrawJig::acquireAngleWr1)
        .def("acquireAngle", &PyDrawJig::acquireAngleWr2)
        .def("acquireDist", &PyDrawJig::acquireDistWr1)
        .def("acquireDist", &PyDrawJig::acquireDistWr2)
        .def("acquirePoint", &PyDrawJig::acquirePointWr1)
        .def("acquirePoint", &PyDrawJig::acquirePointWr2)
        .def("specialCursorType", &PyDrawJig::specialCursorTypeWr)
        .def("setSpecialCursorType", &PyDrawJig::setSpecialCursorTypeWr)
        .def("userInputControls", &PyDrawJig::userInputControlsWr)
        .def("setUserInputControls", &PyDrawJig::setUserInputControlsWr)
        .def("worldDraw", &PyDrawJig::worldDrawWr)
        .def("viewportDraw", &PyDrawJig::viewportDrawWr)
        .def("className", &PyDrawJig::className).staticmethod("className")
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

#ifndef _BRXTARGET 
AcEdJig::DragStatus PyDrawJig::dragwr2(const AcEdDragStyle& style)
{
    return this->drag(style);
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
#if _ZRXTARGET == 240 || _BRXTARGET == 240
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
