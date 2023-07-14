#include "stdafx.h"
#include "PyJig.h"
#include "PyDbObjectId.h"
#include "PyDbEntity.h"
#include "PyGiCommonDraw.h"
#include "PyEdUserInteraction.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------------------------------------------------------
void makeAcEdJigWrapper()
{
    {
        class_<PyJig, boost::noncopyable>("Jig", boost::python::no_init)
            .def(init<const PyDbEntity&>())
            .def("drag", &PyJig::dragwr1)
#ifndef BRXAPP
            .def("drag", &PyJig::dragwr2)
#endif
            .def("sampler", &PyJig::sampler)
            .def("update", &PyJig::update)
            .def("append", &PyJig::appendwr)
            .def("keywordList", &PyJig::keywordListwr)
            .def("setKeywordList", &PyJig::setKeywordListwr)
            .def("dispPrompt", &PyJig::dispPromptwr)
            .def("setDispPrompt", &PyJig::setDispPromptwr)
            .def("acquireString", &PyJig::acquireStringwr)
            .def("acquireAngle", &PyJig::acquireAnglewr1)
            .def("acquireAngle", &PyJig::acquireAnglewr2)
            .def("acquireDist", &PyJig::acquireDistwr1)
            .def("acquireDist", &PyJig::acquireDistwr2)
            .def("acquirePoint", &PyJig::acquirePointwr1)
            .def("acquirePoint", &PyJig::acquirePointwr2)
            .def("specialCursorType", &PyJig::specialCursorTypewr)
            .def("setSpecialCursorType", &PyJig::setSpecialCursorTypewr)
            .def("userInputControls", &PyJig::userInputControlswr)
            .def("setUserInputControls", &PyJig::setUserInputControlswr)
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
    }

#ifndef BRXAPP
    {
        class_<AcEdDragStyle>("DragStyle")
            .def(init<>())
            .def(init<AcEdDragStyle::StyleType, AcEdDragStyle::StyleType>())
            .def("styleTypeForOriginal", &AcEdDragStyle::styleTypeForOriginal)
            .def("styleTypeForDragged", &AcEdDragStyle::styleTypeForDragged)
            .def("setStyleTypeForOriginal", &AcEdDragStyle::setStyleTypeForOriginal)
            .def("setStyleTypeForDragged", &AcEdDragStyle::setStyleTypeForDragged)
            ;
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
    }
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

#ifndef BRXAPP
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
        if (override f = this->get_override("sampler"))
            return f();
    }
    catch (...) {}
    return AcEdJig::DragStatus::kCancel;
}

Adesk::Boolean PyJig::update()
{
    PyAutoLockGIL lock;
    try
    {
        if (override f = this->get_override("update"))
            return f();
    }
    catch (...) {}
    return true;
}

PyDbObjectId PyJig::appendwr()
{
    return PyDbObjectId(this->append());
}

std::string PyJig::keywordListwr()
{
    return wstr_to_utf8(this->keywordList());
}

void PyJig::setKeywordListwr(const std::string& val)
{
    this->setKeywordList(utf8_to_wstr(val).c_str());
}

std::string PyJig::dispPromptwr()
{
    return wstr_to_utf8(this->dispPrompt());
}

void PyJig::setDispPromptwr(const std::string& val)
{
    this->setDispPrompt(utf8_to_wstr(val).c_str());
}

boost::python::tuple PyJig::acquireStringwr()
{
#ifdef ARXAPP
    PyAutoLockGIL lock;
    AcString value;
    auto result = this->acquireString(value);
    return boost::python::make_tuple(result, wstr_to_utf8(value));
#else
    throw PyNotimplementedByHost();
#endif
}

boost::python::tuple PyJig::acquireAnglewr1()
{
    PyAutoLockGIL lock;
    double value;
    auto result = this->acquireAngle(value);
    return boost::python::make_tuple(result, value);
}

boost::python::tuple PyJig::acquireAnglewr2(const AcGePoint3d& basePnt)
{
    PyAutoLockGIL lock;
    double value;
    auto result = this->acquireAngle(value, basePnt);
    return boost::python::make_tuple(result, value);
}

boost::python::tuple PyJig::acquireDistwr1()
{
    PyAutoLockGIL lock;
    double value;
    auto result = this->acquireDist(value);
    return boost::python::make_tuple(result, value);
}

boost::python::tuple PyJig::acquireDistwr2(const AcGePoint3d& basePnt)
{
    PyAutoLockGIL lock;
    double value;
    auto result = this->acquireDist(value, basePnt);
    return boost::python::make_tuple(result, value);
}

boost::python::tuple PyJig::acquirePointwr1()
{
    PyAutoLockGIL lock;
    AcGePoint3d value;
    auto result = this->acquirePoint(value);
    return boost::python::make_tuple(result, value);
}

boost::python::tuple PyJig::acquirePointwr2(const AcGePoint3d& basePnt)
{
    PyAutoLockGIL lock;
    AcGePoint3d value;
    auto result = this->acquirePoint(value, basePnt);
    return boost::python::make_tuple(result, value);
}

AcEdJig::CursorType PyJig::specialCursorTypewr()
{
    return this->specialCursorType();
}

void PyJig::setSpecialCursorTypewr(AcEdJig::CursorType val)
{
    this->setSpecialCursorType(val);
}

AcEdJig::UserInputControls PyJig::userInputControlswr()
{
    return this->userInputControls();
}

void PyJig::setUserInputControlswr(AcEdJig::UserInputControls val)
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
void makeAcEdDrawJigWrapper()
{
    class_<PyDrawJig, boost::noncopyable>("DrawJig")
        .def("drag", &PyDrawJig::dragwr1)
#ifndef BRXAPP
        .def("drag", &PyDrawJig::dragwr2)
#endif
        .def("sampler", &PyDrawJig::sampler)
        .def("update", &PyDrawJig::update)
        .def("keywordList", &PyDrawJig::keywordListwr)
        .def("setKeywordList", &PyDrawJig::setKeywordListwr)
        .def("dispPrompt", &PyDrawJig::dispPromptwr)
        .def("setDispPrompt", &PyDrawJig::setDispPromptwr)
        .def("acquireString", &PyDrawJig::acquireStringwr)
        .def("acquireAngle", &PyDrawJig::acquireAnglewr1)
        .def("acquireAngle", &PyDrawJig::acquireAnglewr2)
        .def("acquireDist", &PyDrawJig::acquireDistwr1)
        .def("acquireDist", &PyDrawJig::acquireDistwr2)
        .def("acquirePoint", &PyDrawJig::acquirePointwr1)
        .def("acquirePoint", &PyDrawJig::acquirePointwr2)
        .def("specialCursorType", &PyDrawJig::specialCursorTypewr)
        .def("setSpecialCursorType", &PyDrawJig::setSpecialCursorTypewr)
        .def("userInputControls", &PyDrawJig::userInputControlswr)
        .def("setUserInputControls", &PyDrawJig::setUserInputControlswr)
        .def("worldDraw", &PyDrawJig::worldDrawwr)
        .def("viewportDraw", &PyDrawJig::viewportDrawwr)
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

#ifndef BRXAPP
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
        if (override f = this->get_override("sampler"))
            return f();
    }
    catch (...) {}
    return AcEdJig::DragStatus::kCancel;
}

Adesk::Boolean PyDrawJig::update()
{
    PyAutoLockGIL lock;
    try
    {
        if (override f = this->get_override("update"))
            return f();
    }
    catch (...) {}
    return false;
}

std::string PyDrawJig::keywordListwr()
{
    return wstr_to_utf8(this->keywordList());
}

void PyDrawJig::setKeywordListwr(const std::string& val)
{
    this->setKeywordList(utf8_to_wstr(val).c_str());
}

std::string PyDrawJig::dispPromptwr()
{
    return wstr_to_utf8(this->dispPrompt());
}

void PyDrawJig::setDispPromptwr(const std::string& val)
{
    this->setDispPrompt(utf8_to_wstr(val).c_str());
}

boost::python::tuple PyDrawJig::acquireStringwr()
{
#ifdef ARXAPP
    PyAutoLockGIL lock;
    AcString value;
    auto result = this->acquireString(value);
    return boost::python::make_tuple(result, wstr_to_utf8(value));
#else
    throw PyNotimplementedByHost();
#endif
}

boost::python::tuple PyDrawJig::acquireAnglewr1()
{
    PyAutoLockGIL lock;
    double value;
    auto result = this->acquireAngle(value);
    return boost::python::make_tuple(result, value);
}

boost::python::tuple PyDrawJig::acquireAnglewr2(const AcGePoint3d& basePnt)
{
    PyAutoLockGIL lock;
    double value;
    auto result = this->acquireAngle(value, basePnt);
    return boost::python::make_tuple(result, value);
}

boost::python::tuple PyDrawJig::acquireDistwr1()
{
    PyAutoLockGIL lock;
    double value;
    auto result = this->acquireDist(value);
    return boost::python::make_tuple(result, value);
}

boost::python::tuple PyDrawJig::acquireDistwr2(const AcGePoint3d& basePnt)
{
    PyAutoLockGIL lock;
    double value;
    auto result = this->acquireDist(value, basePnt);
    return boost::python::make_tuple(result, value);
}

boost::python::tuple PyDrawJig::acquirePointwr1()
{
    PyAutoLockGIL lock;
    AcGePoint3d value;
    auto result = this->acquirePoint(value);
    return boost::python::make_tuple(result, value);
}

boost::python::tuple PyDrawJig::acquirePointwr2(const AcGePoint3d& basePnt)
{
    PyAutoLockGIL lock;
    AcGePoint3d value;
    auto result = this->acquirePoint(value, basePnt);
    return boost::python::make_tuple(result, value);
}

AcEdJig::CursorType PyDrawJig::specialCursorTypewr()
{
    return this->specialCursorType();
}

void PyDrawJig::setSpecialCursorTypewr(AcEdJig::CursorType val)
{
    this->setSpecialCursorType(val);
}

AcEdJig::UserInputControls PyDrawJig::userInputControlswr()
{
    return this->userInputControls();
}

void PyDrawJig::setUserInputControlswr(AcEdJig::UserInputControls val)
{
    return this->setUserInputControls(val);
}

Adesk::Boolean PyDrawJig::worldDrawwr(PyGiWorldDraw& wd)
{
    PyAutoLockGIL lock;
    try
    {
        if (override f = this->get_override("worldDraw"))
            return f(wd);
    }
    catch (...) {}
    return false;
}

void PyDrawJig::viewportDrawwr(PyGiViewportDraw& vd)
{
    try
    {
        PyAutoLockGIL lock;
        if (override f = this->get_override("ViewportDraw"))
            f(vd);
    }
    catch (...) {}
}

Adesk::Boolean PyDrawJig::subWorldDraw(AcGiWorldDraw* wd)
{
    PyGiWorldDraw draw(wd, false);
    return worldDrawwr(draw);
}

void PyDrawJig::subViewportDraw(AcGiViewportDraw* vd)
{
    PyGiViewportDraw draw(vd, false);
    viewportDrawwr(draw);
}

AcDbEntity* PyDrawJig::entity() const
{
    return const_cast<AcDbEntity*>(static_cast<const AcDbEntity*>(this));
}

std::string PyDrawJig::className()
{
    return "AcEdJig";
}
