#include "stdafx.h"
#include "PyAcAp.h"

#include "PyApDocument.h"
#include "PyApDocManager.h"
#include "PyApApplication.h"

using namespace boost::python;


uint64_t acadMainWnd()
{
    return reinterpret_cast<int64_t>(adsw_acadMainWnd());
}

uint64_t acadDocWnd()
{
    return reinterpret_cast<uint64_t>(adsw_acadDocWnd());
}

BOOST_PYTHON_MODULE(PyAp)
{
#ifndef  PyRxDebug
    docstring_options local_docstring_options(false, true, false);
#endif // ! PyRxDebug

    def("acadMainWnd", acadMainWnd);
    def("acadDocWnd", acadDocWnd);

    register_exception_translator<PyNullObject>(PyNullObject::translator);
    register_exception_translator<PyEditorError>(PyEditorError::translator);
    register_exception_translator<PyAcadErrorStatus>(PyAcadErrorStatus::translator);
    register_exception_translator<PyNotThatKindOfClass>(PyNotThatKindOfClass::translator);
    register_exception_translator<PyNotimplementedByHost>(PyNotimplementedByHost::translator);
    makeAcApApplictionWrapper();
    makeAcApDocManagerWrapper();
    makeAcApDocumentWrapper();

    enum_<AcAp::DocLockMode>("DocLockMode")
        .value("kNone", AcAp::DocLockMode::kNone)
        .value("kAutoWrite", AcAp::DocLockMode::kAutoWrite)
        .value("kNotLocked", AcAp::DocLockMode::kNotLocked)
        .value("kWrite", AcAp::DocLockMode::kWrite)
        .value("kProtectedAutoWrite", AcAp::DocLockMode::kProtectedAutoWrite)
        .value("kRead", AcAp::DocLockMode::kRead)
        .value("kXWrite", AcAp::DocLockMode::kXWrite)
        .export_values()
        ;
};

void initPyApModule()
{
    PyImport_AppendInittab(PyApNamespace, &PyInit_PyAp);
}


