#include "stdafx.h"
#include "PyAcEd.h"
#include "PyAcEditor.h"
#include "PyJig.h"

using namespace boost::python;

BOOST_PYTHON_MODULE(PyEd)
{
#ifndef  PyRxDebug
    docstring_options local_docstring_options(false, true, false);
#endif // ! PyRxDebug

    makeAcEdJigWrapper();
    makeAcEditorWrapper();

    enum_<Acad::PromptStatus>("PromptStatus")
        .value("kNone", Acad::PromptStatus::eNone)
        .value("kModeless", Acad::PromptStatus::eModeless)
        .value("kNormal", Acad::PromptStatus::eNormal)
        .value("kError", Acad::PromptStatus::eError)
        .value("kCancel", Acad::PromptStatus::eCancel)
        .value("kRejected", Acad::PromptStatus::eRejected)
        .value("kFailed", Acad::PromptStatus::eFailed)
        .value("kKeyword", Acad::PromptStatus::eKeyword)
        .value("keDirect", Acad::PromptStatus::eDirect)
        .export_values()
        ;
};

void initPyEdModule()
{
    PyImport_AppendInittab(PyEdNamespace, &PyInit_PyEd);
}
