#include "stdafx.h"
#include "PyAcEd.h"
#include "PyAcEditor.h"
#include "PyJig.h"
#include "PyEditorReactor.h"

using namespace boost::python;

BOOST_PYTHON_MODULE(PyEd)
{
#ifndef  PyRxDebug
    docstring_options local_docstring_options(false, true, true);
#endif // ! PyRxDebug

    makeAcEdJigWrapper();
    makeAcEditorWrapper();
    makePyEditorReactorWrapper();

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
