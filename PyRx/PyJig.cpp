#include "stdafx.h"
#include "PyJig.h"
#include "PyDbObjectId.h"
#include "PyDbEntity.h"

using namespace boost::python;

void makeAcEdJigWrapper()
{
    class_<PyJig, bases<PyRxObject>>("PyJig")
        .def("drag", &PyJig::drag1)
        .def("sampler", &PyJig::sampler)
        .def("update", &PyJig::update)
        .def("append", &PyJig::append)
        .def("keywordList", &PyJig::keywordList)
        .def("setKeywordList", &PyJig::setKeywordList)
        .def("dispPrompt", &PyJig::dispPrompt)
        .def("setDispPrompt", &PyJig::setDispPrompt)
        .def("acquireString", &PyJig::acquireString)
        .def("acquireAngle", &PyJig::acquireAngle1)
        .def("acquireAngle", &PyJig::acquireAngle2)
        .def("acquireDist", &PyJig::acquireDist1)
        .def("acquireDist", &PyJig::acquireDist2)
        .def("acquirePoint", &PyJig::acquirePoint1)
        .def("acquirePoint", &PyJig::acquirePoint2)
        .def("specialCursorType", &PyJig::specialCursorType)
        .def("setSpecialCursorType", &PyJig::setSpecialCursorType)
        .def("userInputControls", &PyJig::userInputControls)
        .def("setUserInputControls", &PyJig::setUserInputControls)
        .def("entity", &PyJig::entity)
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

PyJig::PyJig()
    : PyRxObject(new AcEdJig(), true, false)
{
}

AcEdJig::DragStatus PyJig::drag1()
{
    return impObj()->drag();
}

#ifdef NEVER
AcEdJig::DragStatus PyJig::drag2(const AcEdDragStyle& style)
{
    return impObj()->drag(style);
}
#endif

AcEdJig::DragStatus PyJig::sampler()
{
    return impObj()->sampler();
}

Adesk::Boolean PyJig::update()
{
    return impObj()->update();
}

PyDbObjectId PyJig::append()
{
    return PyDbObjectId(impObj()->append());
}

std::string PyJig::keywordList()
{
    return wstr_to_utf8(impObj()->keywordList());
}

void PyJig::setKeywordList(const std::string& val)
{
    impObj()->setKeywordList(utf8_to_wstr(val).c_str());
}

std::string PyJig::dispPrompt()
{
    return wstr_to_utf8(impObj()->dispPrompt());
}

void PyJig::setDispPrompt(const std::string& val)
{
    impObj()->setDispPrompt(utf8_to_wstr(val).c_str());
}

boost::python::tuple PyJig::acquireString()
{
#ifdef ARXAPP
    AcString value;
    auto result = impObj()->acquireString(value);
    return boost::python::make_tuple(result, wstr_to_utf8(value));
#else
    throw PyNotimplementedByHost();
#endif
}

boost::python::tuple PyJig::acquireAngle1()
{
    double value;
    auto result = impObj()->acquireAngle(value);
    return boost::python::make_tuple(result,value);
}

boost::python::tuple PyJig::acquireAngle2(const AcGePoint3d& basePnt)
{
    double value;
    auto result = impObj()->acquireAngle(value, basePnt);
    return boost::python::make_tuple(result, value);
}

boost::python::tuple PyJig::acquireDist1()
{
    double value;
    auto result = impObj()->acquireDist(value);
    return boost::python::make_tuple(result, value);
}

boost::python::tuple PyJig::acquireDist2(const AcGePoint3d& basePnt)
{
    double value;
    auto result = impObj()->acquireDist(value, basePnt);
    return boost::python::make_tuple(result, value);
}

boost::python::tuple PyJig::acquirePoint1()
{
    AcGePoint3d value;
    auto result = impObj()->acquirePoint(value);
    return boost::python::make_tuple(result, value);
}

boost::python::tuple PyJig::acquirePoint2(const AcGePoint3d& basePnt)
{
    AcGePoint3d value;
    auto result = impObj()->acquirePoint(value, basePnt);
    return boost::python::make_tuple(result, value);
}

AcEdJig::CursorType PyJig::specialCursorType()
{
    return impObj()->specialCursorType();
}

void PyJig::setSpecialCursorType(AcEdJig::CursorType val)
{
    impObj()->setSpecialCursorType(val);
}

AcEdJig::UserInputControls PyJig::userInputControls()
{
    return impObj()->userInputControls();
}

void PyJig::setUserInputControls(AcEdJig::UserInputControls val)
{
    return impObj()->setUserInputControls(val);
}

PyDbEntity PyJig::entity() const
{
    return PyDbEntity(nullptr, false);
}

std::string PyJig::className()
{
    return "AcEdJig";
}

AcEdJig* PyJig::impObj() const
{
    if (m_pImp == nullptr)
        throw PyNullObject();
    return static_cast<AcEdJig*>(m_pImp.get());
}
