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
    makePyApDocManagerReactorWrapper();

    enum_<int>("CmdFlags")
        .value("MODAL", ACRX_CMD_MODAL)
        .value("TRANSPARENT", ACRX_CMD_TRANSPARENT)
        .value("USEPICKSET", ACRX_CMD_USEPICKSET)
        .value("REDRAW", ACRX_CMD_REDRAW)
        .value("NOPERSPECTIVE", ACRX_CMD_NOPERSPECTIVE)
        .value("NOMULTIPLE", ACRX_CMD_NOMULTIPLE)
        .value("NOTILEMODE", ACRX_CMD_NOTILEMODE)
        .value("NOPAPERSPACE", ACRX_CMD_NOPAPERSPACE)
#ifndef BRXAPP
        .value("DEPRECATED", ACRX_CMD_DEPRECATED)
#endif
        .value("NOOEM", ACRX_CMD_NOOEM)
        .value("UNDEFINED", ACRX_CMD_UNDEFINED)
        .value("INPROGRESS", ACRX_CMD_INPROGRESS)
        .value("DEFUN", ACRX_CMD_DEFUN)
        .value("NOINTERNALLOCK", ACRX_CMD_NOINTERNALLOCK)
        .value("DOCREADLOCK", ACRX_CMD_DOCREADLOCK)
        .value("DOCEXCLUSIVELOCK", ACRX_CMD_DOCEXCLUSIVELOCK)
        .value("SESSION", ACRX_CMD_SESSION)
        .value("INTERRUPTIBLE", ACRX_CMD_INTERRUPTIBLE)
        .value("NOHISTORY", ACRX_CMD_NOHISTORY)
        .value("NO_UNDO_MARKER", ACRX_CMD_NO_UNDO_MARKER)
        .value("NOBEDIT", ACRX_CMD_NOBEDIT)
#ifndef BRXAPP
        .value("NOACTIONRECORDING", ACRX_CMD_NOACTIONRECORDING)
        .value("ACTIONMACRO", ACRX_CMD_ACTIONMACRO)
        .value("RELAXASSOC", ACRX_CMD_RELAXASSOC)
        .value("NOINFERCONSTRAINT", ACRX_CMD_NOINFERCONSTRAINT)
        .value("TEMPSHOWDYNDIM", ACRX_CMD_TEMPSHOWDYNDIM)
#endif
        .export_values()
        ;

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
    enum_<AcApDocument::SaveFormat>("SaveFormat")
        .value("kUnknown", AcApDocument::SaveFormat::kUnknown)
        .value("kR12_dxf", AcApDocument::SaveFormat::kR12_dxf)
        .value("kR13_dwg", AcApDocument::SaveFormat::kR13_dwg)
        .value("kR13_dxf", AcApDocument::SaveFormat::kR13_dxf)
        .value("kR14_dwg", AcApDocument::SaveFormat::kR14_dwg)
        .value("kR14_dxf", AcApDocument::SaveFormat::kR14_dxf)
        .value("k2000_dwg", AcApDocument::SaveFormat::k2000_dwg)
        .value("k2000_dxf", AcApDocument::SaveFormat::k2000_dxf)
        .value("k2000_Template", AcApDocument::SaveFormat::k2000_Template)
        .value("k2000_Standard", AcApDocument::SaveFormat::k2000_Standard)
        .value("k2000_xml", AcApDocument::SaveFormat::k2000_xml)
        .value("k2004_dwg", AcApDocument::SaveFormat::k2004_dwg)
        .value("k2004_dxf", AcApDocument::SaveFormat::k2004_dxf)
        .value("k2004_Template", AcApDocument::SaveFormat::k2004_Template)
        .value("k2004_Standard", AcApDocument::SaveFormat::k2004_Standard)
        .value("k2007_dwg", AcApDocument::SaveFormat::k2007_dwg)
        .value("k2007_dxf", AcApDocument::SaveFormat::k2007_dxf)
        .value("k2007_Template", AcApDocument::SaveFormat::k2007_Template)
        .value("k2007_Standard", AcApDocument::SaveFormat::k2007_Standard)
        .value("k2010_dwg", AcApDocument::SaveFormat::k2010_dwg)
        .value("k2010_dxf", AcApDocument::SaveFormat::k2010_dxf)
        .value("k2010_Template", AcApDocument::SaveFormat::k2010_Template)
        .value("k2010_Standard", AcApDocument::SaveFormat::k2010_Standard)
        .value("k2013_dwg", AcApDocument::SaveFormat::k2013_dwg)
        .value("k2013_dxf", AcApDocument::SaveFormat::k2013_dxf)
        .value("k2013_Template", AcApDocument::SaveFormat::k2013_Template)
        .value("k2013_Standard", AcApDocument::SaveFormat::k2013_Standard)
        .value("k2018_dwg", AcApDocument::SaveFormat::k2018_dwg)
        .value("k2018_dxf", AcApDocument::SaveFormat::k2018_dxf)
        .value("k2018_Template", AcApDocument::SaveFormat::k2018_Template)
        .value("k2018_Standard", AcApDocument::SaveFormat::k2018_Standard)
        .value("kNative", AcApDocument::SaveFormat::kNative)
        .value("kNative_Template", AcApDocument::SaveFormat::kNative_Template)
        .export_values()
        ;
};

void initPyApModule()
{
    PyImport_AppendInittab(PyApNamespace, &PyInit_PyAp);
}


