#include "stdafx.h"
#include "PyAcEd.h"
#include "PyAcEditor.h"


using namespace boost::python;

BOOST_PYTHON_MODULE(PyEd)
{
    makeAcEditorWrapper();

    enum_<Acad::PromptStatus>("PromptStatus")
        .value("None", Acad::PromptStatus::eNone)
        .value("Modeless", Acad::PromptStatus::eModeless)
        .value("Normal", Acad::PromptStatus::eNormal)
        .value("Error", Acad::PromptStatus::eError)
        .value("Cancel", Acad::PromptStatus::eCancel)
        .value("Rejected", Acad::PromptStatus::eRejected)
        .value("Failed", Acad::PromptStatus::eFailed)
        .value("Keyword", Acad::PromptStatus::eKeyword)
        .value("eDirect", Acad::PromptStatus::eDirect)
        ;
};

void initPyEdModule()
{
    PyImport_AppendInittab(PyEdNamespace, &PyInit_PyEd);
}
