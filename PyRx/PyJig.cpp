#include "stdafx.h"
#include "PyJig.h"
#include "PyDbObjectId.h"
#include "PyDbEntity.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------------------------------------------------------
void makeAcEdJigWrapper()
{
    class_<PyJig, boost::noncopyable>("Jig", boost::python::no_init)
        .def(init<const PyDbEntity&>())
        .def("drag", &PyJig::dragwr1)
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
    enum_<AcEdJig::DragStatus>("DragStatus")
        .value("kModeless", AcEdJig::DragStatus::kModeless)
        .value("kNoChange", AcEdJig::DragStatus::kNoChange)
        .value("kCancel", AcEdJig::DragStatus::kCancel)
        .value("kOther", AcEdJig::DragStatus::kOther)
        .value("kNull", AcEdJig::DragStatus::kNull)
        .value("kNormal", AcEdJig::DragStatus::kNormal)
        .value("eNormal", AcEdJig::DragStatus::kNormal)
        .value("eOk", AcEdJig::DragStatus::kNormal)
        .value("kKW1", AcEdJig::DragStatus::kKW1)
        .value("kKW2", AcEdJig::DragStatus::kKW2)
        .value("kKW3", AcEdJig::DragStatus::kKW3)
        .value("kKW4", AcEdJig::DragStatus::kKW4)
        .value("kKW5", AcEdJig::DragStatus::kKW5)
        .value("kKW6", AcEdJig::DragStatus::kKW6)
        .value("kKW7", AcEdJig::DragStatus::kKW7)
        .value("kKW8", AcEdJig::DragStatus::kKW8)
        .value("kKW9", AcEdJig::DragStatus::kKW9)
        .export_values()
        ;
    enum_<AcEdJig::CursorType>("CursorType")
        .value("kNoSpecialCursor", AcEdJig::CursorType::kNoSpecialCursor)
        .value("kCrosshair", AcEdJig::CursorType::kCrosshair)
        .value("kRectCursor", AcEdJig::CursorType::kRectCursor)
        .value("kRubberBand", AcEdJig::CursorType::kRubberBand)
        .value("kNotRotated", AcEdJig::CursorType::kNotRotated )
        .value("kTargetBox", AcEdJig::CursorType::kTargetBox)
        .value("kRotatedCrosshair", AcEdJig::CursorType::kRotatedCrosshair )
        .value("kCrosshairNoRotate", AcEdJig::CursorType::kCrosshairNoRotate)
        .value("kInvisible", AcEdJig::CursorType::kInvisible)
        .value("kEntitySelect", AcEdJig::CursorType::kEntitySelect)
        .value("kParallelogram", AcEdJig::CursorType::kParallelogram)
        .value("kEntitySelectNoPersp", AcEdJig::CursorType::kEntitySelectNoPersp)
        .value("kPkfirstOrGrips", AcEdJig::CursorType::kPkfirstOrGrips)
        .value("kCrosshairDashed", AcEdJig::CursorType::kCrosshairDashed)
        .export_values()
        ;
    enum_<AcEdJig::UserInputControls>("UserInputControls")
        .value("kGovernedByOrthoMode", AcEdJig::UserInputControls::kGovernedByOrthoMode)
        .value("kNullResponseAccepted", AcEdJig::UserInputControls::kNullResponseAccepted)
        .value("kDontEchoCancelForCtrlC", AcEdJig::UserInputControls::kDontEchoCancelForCtrlC)
        .value("kDontUpdateLastPoint", AcEdJig::UserInputControls::kDontUpdateLastPoint)
        .value("kNoDwgLimitsChecking", AcEdJig::UserInputControls::kNoDwgLimitsChecking)
        .value("kNoZeroResponseAccepted", AcEdJig::UserInputControls::kNoZeroResponseAccepted)
        .value("kNoNegativeResponseAccepted", AcEdJig::UserInputControls::kNoNegativeResponseAccepted)
        .value("kAccept3dCoordinates", AcEdJig::UserInputControls::kAccept3dCoordinates)
        .value("kAcceptMouseUpAsPoint", AcEdJig::UserInputControls::kAcceptMouseUpAsPoint)
        .value("kAnyBlankTerminatesInput", AcEdJig::UserInputControls::kAnyBlankTerminatesInput)
        .value("kInitialBlankTerminatesInput", AcEdJig::UserInputControls::kInitialBlankTerminatesInput)
        .value("kAcceptOtherInputString", AcEdJig::UserInputControls::kAcceptOtherInputString)
        .value("kGovernedByUCSDetect", AcEdJig::UserInputControls::kGovernedByUCSDetect)
        .value("kNoZDirectionOrtho", AcEdJig::UserInputControls::kNoZDirectionOrtho)
        .value("kImpliedFaceForUCSChange", AcEdJig::UserInputControls::kImpliedFaceForUCSChange)
        .value("kUseBasePointElevation", AcEdJig::UserInputControls::kUseBasePointElevation)
        .value("kDisableDirectDistanceInput", AcEdJig::UserInputControls::kDisableDirectDistanceInput)
        .export_values()
        ;
}

PyJig::PyJig(const PyDbEntity& ent)
    : m_pEnt(ent.impObj()), AcEdJig()
{
}

AcEdJig::DragStatus PyJig::dragwr1()
{
    return this->drag();
}

#ifdef NEVER
AcEdJig::DragStatus PyJig::dragwr2(const AcEdDragStyle& style)
{
    return impObj()->drag(style);
}
#endif

AcEdJig::DragStatus PyJig::sampler()
{
    if (override f = this->get_override("sampler")) 
        return f();
    return AcEdJig::DragStatus::kNoChange;
}

Adesk::Boolean PyJig::update()
{
    if (override f = this->get_override("update"))
        return f();
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
    AcString value;
    auto result = this->acquireString(value);
    return boost::python::make_tuple(result, wstr_to_utf8(value));
#else
    throw PyNotimplementedByHost();
#endif
}

boost::python::tuple PyJig::acquireAnglewr1()
{
    double value;
    auto result = this->acquireAngle(value);
    return boost::python::make_tuple(result,value);
}

boost::python::tuple PyJig::acquireAnglewr2(const AcGePoint3d& basePnt)
{
    double value;
    auto result = this->acquireAngle(value, basePnt);
    return boost::python::make_tuple(result, value);
}

boost::python::tuple PyJig::acquireDistwr1()
{
    double value;
    auto result = this->acquireDist(value);
    return boost::python::make_tuple(result, value);
}

boost::python::tuple PyJig::acquireDistwr2(const AcGePoint3d& basePnt)
{
    double value;
    auto result = this->acquireDist(value, basePnt);
    return boost::python::make_tuple(result, value);
}

boost::python::tuple PyJig::acquirePointwr1()
{
    AcGePoint3d value;
    auto result = this->acquirePoint(value);
    return boost::python::make_tuple(result, value);
}

boost::python::tuple PyJig::acquirePointwr2(const AcGePoint3d& basePnt)
{
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

