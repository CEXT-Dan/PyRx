#include "stdafx.h"
#include "PyJig.h"
#include "PyDbObjectId.h"
#include "PyDbEntity.h"

using namespace boost::python;


PyJigBase::PyJigBase()
    : AcEdJig()
{
}

AcDbEntity* PyJigBase::entity() const
{
    return nullptr;
}

AcEdJig::DragStatus PyJigBase::sampler()
{
    return AcEdJig::DragStatus::kNoChange;
}

Adesk::Boolean PyJigBase::update()
{
    return false;
}

//-----------------------------------------------------------------------------------------------------------------------------------
void makeAcEdJigWrapper()
{
    class_<PyJig>("Jig", boost::python::no_init)
        .def(init<const PyDbEntity&>())
        .def("drag", &PyJig::drag1)
        .def("sampler", &PyJig::sampler)
        .def("update", &PyJig::update)
        .def("append", &PyJig::append1)
        .def("keywordList", &PyJig::keywordList1)
        .def("setKeywordList", &PyJig::setKeywordList1)
        .def("dispPrompt", &PyJig::dispPrompt1)
        .def("setDispPrompt", &PyJig::setDispPrompt1)
        .def("acquireString", &PyJig::acquireString1)
        .def("acquireAngle", &PyJig::acquireAngle1)
        .def("acquireAngle", &PyJig::acquireAngle2)
        .def("acquireDist", &PyJig::acquireDist1)
        .def("acquireDist", &PyJig::acquireDist2)
        .def("acquirePoint", &PyJig::acquirePoint1)
        .def("acquirePoint", &PyJig::acquirePoint2)
        .def("specialCursorType", &PyJig::specialCursorType1)
        .def("setSpecialCursorType", &PyJig::setSpecialCursorType1)
        .def("userInputControls", &PyJig::userInputControls1)
        .def("setUserInputControls", &PyJig::setUserInputControls1)
        .def("className", &PyJig::className).staticmethod("className")
        ;
    enum_<AcEdJig::DragStatus>("DragStatus")
        .value("kModeless", AcEdJig::DragStatus::kModeless)
        .value("kNoChange", AcEdJig::DragStatus::kNoChange)
        .value("kCancel", AcEdJig::DragStatus::kCancel)
        .value("kOther", AcEdJig::DragStatus::kOther)
        .value("kNull", AcEdJig::DragStatus::kNull)
        .value("kNormal", AcEdJig::DragStatus::kNormal)
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
    : m_pEnt(ent.impObj()), PyJigBase()
{
}

AcEdJig::DragStatus PyJig::drag1()
{
    return this->drag();
}

#ifdef NEVER
AcEdJig::DragStatus PyJig::drag2(const AcEdDragStyle& style)
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

PyDbObjectId PyJig::append1()
{
    return PyDbObjectId(this->append());
}

std::string PyJig::keywordList1()
{
    return wstr_to_utf8(this->keywordList());
}

void PyJig::setKeywordList1(const std::string& val)
{
    this->setKeywordList(utf8_to_wstr(val).c_str());
}

std::string PyJig::dispPrompt1()
{
    return wstr_to_utf8(this->dispPrompt());
}

void PyJig::setDispPrompt1(const std::string& val)
{
  this->setDispPrompt(utf8_to_wstr(val).c_str());
}

boost::python::tuple PyJig::acquireString1()
{
#ifdef ARXAPP
    AcString value;
    auto result = this->acquireString(value);
    return boost::python::make_tuple(result, wstr_to_utf8(value));
#else
    throw PyNotimplementedByHost();
#endif
}

boost::python::tuple PyJig::acquireAngle1()
{
    double value;
    auto result = this->acquireAngle(value);
    return boost::python::make_tuple(result,value);
}

boost::python::tuple PyJig::acquireAngle2(const AcGePoint3d& basePnt)
{
    double value;
    auto result = this->acquireAngle(value, basePnt);
    return boost::python::make_tuple(result, value);
}

boost::python::tuple PyJig::acquireDist1()
{
    double value;
    auto result = this->acquireDist(value);
    return boost::python::make_tuple(result, value);
}

boost::python::tuple PyJig::acquireDist2(const AcGePoint3d& basePnt)
{
    double value;
    auto result = this->acquireDist(value, basePnt);
    return boost::python::make_tuple(result, value);
}

boost::python::tuple PyJig::acquirePoint1()
{
    AcGePoint3d value;
    auto result = this->acquirePoint(value);
    return boost::python::make_tuple(result, value);
}

boost::python::tuple PyJig::acquirePoint2(const AcGePoint3d& basePnt)
{
    AcGePoint3d value;
    auto result = this->acquirePoint(value, basePnt);
    return boost::python::make_tuple(result, value);
}

AcEdJig::CursorType PyJig::specialCursorType1()
{
    return this->specialCursorType();
}

void PyJig::setSpecialCursorType1(AcEdJig::CursorType val)
{
    this->setSpecialCursorType(val);
}

AcEdJig::UserInputControls PyJig::userInputControls1()
{
    return this->userInputControls();
}

void PyJig::setUserInputControls1(AcEdJig::UserInputControls val)
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

