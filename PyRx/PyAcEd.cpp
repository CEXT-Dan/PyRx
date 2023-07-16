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

BOOST_PYTHON_MODULE(PyEd)
{
    docstring_options local_docstring_options(true, true, true);

    makeEdCoreWrapper();
    makePyEdSelectionSetWrapper();
    makeAcEdJigWrapper();
    makeAcEdDrawJigWrapper();
    makeAcEditorWrapper();
    makePyEditorReactorWrapper();
    makePyEdUIContextWrapper();
    makePyEdInputPointManagerWrapper();
    makePyEdInputPointFilterWrapper();
    makePyEdInputPointMonitorWrapper();
    makePyEdInputPointWrapper();
    makePyEdInputPointFilterResultWrapper();
    makePyEdInputPointMonitorResultWrapper();

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
};

void initPyEdModule()
{
    PyImport_AppendInittab(PyEdNamespace, &PyInit_PyEd);
}
