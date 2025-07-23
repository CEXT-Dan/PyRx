#include "stdafx.h"
#include "PyAcEd.h"
#include "PyAcEditor.h"
#include "PyJig.h"
#include "PyEditorReactor.h"
#include "PyEdSelectionSet.h"
#include "EdCore.h"
#include "PyEdUserInteraction.h"
#include "PyEdInput.h"

using namespace boost::python;

static void print(const boost::python::object& obj)
{
    PyAutoLockGIL lock;
    std::string str = boost::python::extract<std::string>(boost::python::str(obj));
    acutPrintf(utf8_to_wstr(str).c_str());
}

static BOOST_PYTHON_MODULE(PyEd)
{
    docstring_options local_docstring_options(py_show_user_defined, py_show_py_signatures, py_show_cpp_signatures);

    makePyEdCoreWrapper();
    makePyUtilWrapper();
    makePyEdSelectionSetWrapper();
    makePyEdJigWrapper();
    makePyEdDrawJigWrapper();
    makePyEditorWrapper();
    makePyEditorReactorWrapper();
    makePyEdUIContextWrapper();
    makePyEdUserInteractionWrapper();
    makePyEdInputPointManagerWrapper();
    makePyEdInputPointFilterWrapper();
    makePyEdInputPointMonitorWrapper();
    makePyEdInputPointWrapper();
    makePyEdInputPointFilterResultWrapper();
    makePyEdInputPointMonitorResultWrapper();
    makePySysVarWrapper();

    def("print", print);

    enum_<Acad::PromptStatus>("PromptStatus")
        .value("eNone", Acad::PromptStatus::eNone)
        .value("eModeless", Acad::PromptStatus::eModeless)
        .value("eNormal", Acad::PromptStatus::eNormal)
        .value("kNormal", Acad::PromptStatus::eNormal)
        .value("eOk", Acad::PromptStatus::eNormal)
        .value("eError", Acad::PromptStatus::eError)
        .value("eCancel", Acad::PromptStatus::eCancel)
        .value("eRejected", Acad::PromptStatus::eRejected)
        .value("eFailed", Acad::PromptStatus::eFailed)
        .value("eKeyword", Acad::PromptStatus::eKeyword)
        .value("eDirect", Acad::PromptStatus::eDirect)
        .export_values()
        ;
    enum_<PromptCondition>("PromptCondition")
        .value("eNone", PromptCondition::eNone)
        .value("eNoZero", PromptCondition::eNoZero)
        .value("eNoEmpty", PromptCondition::eNoEmpty)
        .value("eNoNegative", PromptCondition::eNoNegative)
        .export_values()
        ;

    enum_<AcEdDrawOrderCmdType>("DrawOrderCmdType")
        .value("kDrawOrderNone", AcEdDrawOrderCmdType::kDrawOrderNone)
        .value("kDrawOrderBottom", AcEdDrawOrderCmdType::kDrawOrderBottom)
        .value("kDrawOrderTop", AcEdDrawOrderCmdType::kDrawOrderTop)
        .value("kDrawOrderBelow", AcEdDrawOrderCmdType::kDrawOrderBelow)
        .value("kDrawOrderAbove", AcEdDrawOrderCmdType::kDrawOrderAbove)
        .export_values()
        ;
    enum_<Acad::PointHistory>("PointHistory")
        .value("eTablet", Acad::PointHistory::eTablet)
        .value("eNotDigitizer", Acad::PointHistory::eNotDigitizer)
        .value("eLastPt", Acad::PointHistory::eLastPt)
        .value("eGripped", Acad::PointHistory::eGripped)
        .value("eCartSnapped", Acad::PointHistory::eCartSnapped)
        .value("eOrtho", Acad::PointHistory::eOrtho)
        .value("eCyclingPt", Acad::PointHistory::eCyclingPt)
        .value("eOsnapped", Acad::PointHistory::eOsnapped)
        .value("ePolarAngle", Acad::PointHistory::ePolarAngle)
        .value("eAligned", Acad::PointHistory::eAligned)
        .value("eAppFiltered", Acad::PointHistory::eAppFiltered)
        .value("eForcedPick", Acad::PointHistory::eForcedPick)
        .value("ePickMask", Acad::PointHistory::ePickMask)
        .value("eDidNotPick", Acad::PointHistory::eDidNotPick)
        .value("eUsedPickBox", Acad::PointHistory::eUsedPickBox)
        .value("eUsedOsnapBox", Acad::PointHistory::eUsedOsnapBox)
        .value("ePickAborted", Acad::PointHistory::ePickAborted)
        .value("eXPending", Acad::PointHistory::eXPending)
        .value("eYPending", Acad::PointHistory::eYPending)
        .value("eZPending", Acad::PointHistory::eZPending)
        .value("eCoordPending", Acad::PointHistory::eCoordPending)
        .value("eFromKeyboard", Acad::PointHistory::eFromKeyboard)
        .value("eNotInteractive", Acad::PointHistory::eNotInteractive)
        .value("eDirectDistance", Acad::PointHistory::eDirectDistance)
        .value("eGizmoConstrainted", Acad::PointHistory::eGizmoConstrainted)
        .export_values()
        ;
};

void initPyEdModule()
{
    PyImport_AppendInittab(PyEdNamespace, &PyInit_PyEd);
}
