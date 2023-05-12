#include "stdafx.h"
#include "PyAcAp.h"

#include "PyApDocument.h"
#include "PyApDocManager.h"
#include "PyApApplication.h"

using namespace boost::python;


enum class CmdFlags
{
    kMODAL = ACRX_CMD_MODAL,
    kTRANSPARENT = ACRX_CMD_TRANSPARENT,
    kUSEPICKSET = ACRX_CMD_USEPICKSET,
    kREDRAW = ACRX_CMD_REDRAW,
    kNOPERSPECTIVE = ACRX_CMD_NOPERSPECTIVE,
    kNOMULTIPLE = ACRX_CMD_NOMULTIPLE,
    kNOTILEMODE = ACRX_CMD_NOTILEMODE,
    kNOPAPERSPACE = ACRX_CMD_NOPAPERSPACE,
    kNOOEM = ACRX_CMD_NOOEM,
    kUNDEFINED = ACRX_CMD_UNDEFINED,
    kINPROGRESS = ACRX_CMD_INPROGRESS,
    kDEFUN = ACRX_CMD_DEFUN,
    kNOINTERNALLOCK = ACRX_CMD_NOINTERNALLOCK,
    kDOCREADLOCK = ACRX_CMD_DOCREADLOCK,
    kDOCEXCLUSIVELOCK = ACRX_CMD_DOCEXCLUSIVELOCK,
    kSESSION = ACRX_CMD_SESSION,
    kINTERRUPTIBLE = ACRX_CMD_INTERRUPTIBLE,
    kNOHISTORY = ACRX_CMD_NOHISTORY,
    kNO_UNDO_MARKER = ACRX_CMD_NO_UNDO_MARKER,
    kNOBEDIT = ACRX_CMD_NOBEDIT,
};


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
    docstring_options local_docstring_options(false, true, true);
#endif // ! PyRxDebug

    def("acadMainWnd", acadMainWnd);
    def("acadDocWnd", acadDocWnd);

    register_exception_translator<PyNullObject>(PyNullObject::translator);
    register_exception_translator<PyEditorError>(PyEditorError::translator);
    register_exception_translator<PyAcadErrorStatus>(PyAcadErrorStatus::translator);
    register_exception_translator<PyNotThatKindOfClass>(PyNotThatKindOfClass::translator);
    register_exception_translator<PyNotimplementedByHost>(PyNotimplementedByHost::translator);

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

    enum_<CmdFlags>("CmdFlags")
        .value("MODAL", CmdFlags::kMODAL)
        .value("TRANSPARENT", CmdFlags::kTRANSPARENT)
        .value("USEPICKSET", CmdFlags::kUSEPICKSET)
        .value("REDRAW", CmdFlags::kREDRAW)
        .value("NOPERSPECTIVE", CmdFlags::kNOPERSPECTIVE)
        .value("NOMULTIPLE", CmdFlags::kNOMULTIPLE)
        .value("NOTILEMODE", CmdFlags::kNOTILEMODE)
        .value("NOPAPERSPACE", CmdFlags::kNOPAPERSPACE)
        .value("NOOEM", CmdFlags::kNOOEM)
        .value("UNDEFINED", CmdFlags::kUNDEFINED)
        .value("INPROGRESS", CmdFlags::kINPROGRESS)
        .value("DEFUN", CmdFlags::kDEFUN)
        .value("NOINTERNALLOCK", CmdFlags::kNOINTERNALLOCK)
        .value("DOCREADLOCK", CmdFlags::kDOCREADLOCK)
        .value("DOCEXCLUSIVELOCK", CmdFlags::kDOCEXCLUSIVELOCK)
        .value("SESSION", CmdFlags::kSESSION)
        .value("INTERRUPTIBLE", CmdFlags::kINTERRUPTIBLE)
        .value("NOHISTORY", CmdFlags::kNOHISTORY)
        .value("NO_UNDO_MARKER", CmdFlags::kNO_UNDO_MARKER)
        .value("NOBEDIT", CmdFlags::kNOBEDIT)
        .export_values()
        ;

    makeAcApApplictionWrapper();
    makeAcApDocManagerWrapper();
    makeAcApDocumentWrapper();
    makePyApDocManagerReactorWrapper();

};

void initPyApModule()
{
    PyImport_AppendInittab(PyApNamespace, &PyInit_PyAp);
}


