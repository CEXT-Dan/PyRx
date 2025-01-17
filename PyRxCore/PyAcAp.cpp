#include "stdafx.h"
#include "PyAcAp.h"

#include "PyRxApp.h"
#include "PyRxModuleLoader.h"
#include "PyApDocument.h"
#include "PyApDocManager.h"
#include "PyApApplication.h"
#include "PyDbTransactionManager.h"
#include "PyApLayoutManager.h"
#include "PyUiPalette.h"
#include "PyLayerFilter.h"

using namespace boost::python;

struct CmdFlags
{
    inline static int kMODAL = ACRX_CMD_MODAL;
    inline static int kTRANSPARENT = ACRX_CMD_TRANSPARENT;
    inline static int kUSEPICKSET = ACRX_CMD_USEPICKSET;
    inline static int kREDRAW = ACRX_CMD_REDRAW;
    inline static int kNOPERSPECTIVE = ACRX_CMD_NOPERSPECTIVE;
    inline static int kNOMULTIPLE = ACRX_CMD_NOMULTIPLE;
    inline static int kNOTILEMODE = ACRX_CMD_NOTILEMODE;
    inline static int kNOPAPERSPACE = ACRX_CMD_NOPAPERSPACE;
    inline static int kNOOEM = ACRX_CMD_NOOEM;
    inline static int kUNDEFINED = ACRX_CMD_UNDEFINED;
    inline static int kINPROGRESS = ACRX_CMD_INPROGRESS;
    inline static int kDEFUN = ACRX_CMD_DEFUN;
    inline static int kNOINTERNALLOCK = ACRX_CMD_NOINTERNALLOCK;
    inline static int kDOCREADLOCK = ACRX_CMD_DOCREADLOCK;
    inline static int kDOCEXCLUSIVELOCK = ACRX_CMD_DOCEXCLUSIVELOCK;
    inline static int kSESSION = ACRX_CMD_SESSION;
    inline static int kINTERRUPTIBLE = ACRX_CMD_INTERRUPTIBLE;
    inline static int kNOHISTORY = ACRX_CMD_NOHISTORY;
    inline static int kNO_UNDO_MARKER = ACRX_CMD_NO_UNDO_MARKER;
    inline static int kNOBEDIT = ACRX_CMD_NOBEDIT;
};

static PyApDocument curPyDoc()
{
    return PyApDocument(curDoc(), false);
}

BOOST_PYTHON_MODULE(PyAp)
{
    docstring_options local_docstring_options(py_show_user_defined, py_show_py_signatures, py_show_cpp_signatures);

    register_exception_translator<PyNullObject>(PyNullObject::translator);
    register_exception_translator<PyNotimplementedByHost>(PyNotimplementedByHost::translator);
    register_exception_translator<PyAcadHrError>(PyAcadHrError::translator);
#if defined(_BRXTARGET)
    register_exception_translator<PyBrxBimError>(PyBrxBimError::translator);
#endif

    PyDocString DS("CmdFlags");
    class_<CmdFlags>("CmdFlags")
        .def_readonly("MODAL", CmdFlags::kMODAL, DS.ARGS())
        .def_readonly("TRANSPARENT", CmdFlags::kTRANSPARENT, DS.ARGS())
        .def_readonly("USEPICKSET", CmdFlags::kUSEPICKSET, DS.ARGS())
        .def_readonly("REDRAW", CmdFlags::kREDRAW, DS.ARGS())
        .def_readonly("NOPERSPECTIVE", CmdFlags::kNOPERSPECTIVE, DS.ARGS())
        .def_readonly("NOMULTIPLE", CmdFlags::kNOMULTIPLE, DS.ARGS())
        .def_readonly("NOTILEMODE", CmdFlags::kNOTILEMODE, DS.ARGS())
        .def_readonly("NOPAPERSPACE", CmdFlags::kNOPAPERSPACE, DS.ARGS())
        .def_readonly("NOOEM", CmdFlags::kNOOEM, DS.ARGS())
        .def_readonly("UNDEFINED", CmdFlags::kUNDEFINED, DS.ARGS())
        .def_readonly("INPROGRESS", CmdFlags::kINPROGRESS, DS.ARGS())
        .def_readonly("DEFUN", CmdFlags::kDEFUN, DS.ARGS())
        .def_readonly("NOINTERNALLOCK", CmdFlags::kNOINTERNALLOCK, DS.ARGS())
        .def_readonly("DOCREADLOCK", CmdFlags::kDOCREADLOCK, DS.ARGS())
        .def_readonly("DOCEXCLUSIVELOCK", CmdFlags::kDOCEXCLUSIVELOCK, DS.ARGS())
        .def_readonly("SESSION", CmdFlags::kSESSION, DS.ARGS())
        .def_readonly("INTERRUPTIBLE", CmdFlags::kINTERRUPTIBLE, DS.ARGS())
        .def_readonly("NOHISTORY", CmdFlags::kNOHISTORY, DS.ARGS())
        .def_readonly("NO_UNDO_MARKER", CmdFlags::kNO_UNDO_MARKER, DS.ARGS())
        .def_readonly("NOBEDIT", CmdFlags::kNOBEDIT, DS.ARGS())
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
    enum_<InternalCmdFlags>("ICmdFlags")
        .value("kMODAL", InternalCmdFlags::kMODAL)
        .value("kTRANSPARENT", InternalCmdFlags::kTRANSPARENT)
        .value("kUSEPICKSET", InternalCmdFlags::kUSEPICKSET)
        .value("kREDRAW", InternalCmdFlags::kREDRAW)
        .value("kNOPERSPECTIVE", InternalCmdFlags::kNOPERSPECTIVE)
        .value("kNOMULTIPLE", InternalCmdFlags::kNOMULTIPLE)
        .value("kNOTILEMODE", InternalCmdFlags::kNOTILEMODE)
        .value("kNOPAPERSPACE", InternalCmdFlags::kNOPAPERSPACE)
        .value("kNOOEM", InternalCmdFlags::kNOOEM)
        .value("kUNDEFINED", InternalCmdFlags::kUNDEFINED)
        .value("kINPROGRESS", InternalCmdFlags::kINPROGRESS)
        .value("kDEFUN", InternalCmdFlags::kDEFUN)
        .value("kNOINTERNALLOCK", InternalCmdFlags::kNOINTERNALLOCK)
        .value("kDOCREADLOCK", InternalCmdFlags::kDOCREADLOCK)
        .value("kDOCEXCLUSIVELOCK", InternalCmdFlags::kDOCEXCLUSIVELOCK)
        .value("kSESSION", InternalCmdFlags::kSESSION)
        .value("kINTERRUPTIBLE", InternalCmdFlags::kINTERRUPTIBLE)
        .value("kNOHISTORY", InternalCmdFlags::kNOHISTORY)
        .value("kNO_UNDO_MARKER", InternalCmdFlags::kNO_UNDO_MARKER)
        .value("kNOBEDIT", InternalCmdFlags::kNOBEDIT)
        .export_values()
        ;

    enum_<PyRxTestFlags>("PyRxTestFlags")
        .value("kPyReserved0", PyRxTestFlags::kPyTfReserved0)
        .value("kPyReserved1", PyRxTestFlags::kPyTfReserved1)
        .value("kPyReserved2", PyRxTestFlags::kPyTfReserved2)
        .value("kPyReserved3", PyRxTestFlags::kPyTfReserved3)
        .value("kPyReserved4", PyRxTestFlags::kPyTfReserved4)
        .value("kPyReserved5", PyRxTestFlags::kPyTfReserved5)
        .value("kPyReserved6", PyRxTestFlags::kPyTfReserved6)
        .value("kPyReserved7", PyRxTestFlags::kPyTfReserved7)
        .value("kWaitForDebug", PyRxTestFlags::kPyTfWaitForDebug)
        .export_values()
        ;

    makePyTransactionManagerManager();
    makePyApResourceOverrideWrapper();
    makePyApApplictionWrapper();
    makePyAutoDocLockWrapper();
    makePyApDocManagerWrapper();
    makePyApDocumentWrapper();
    makePyApDocManagerReactorWrapper();
    makePyApLayoutManagerWrapper();
    makePyCAdUiPaletteSetWrapper();
    makePyCAdUiPaletteWrapper();
    makePyLyLayerFilterWrapper();
    makePyLyLayerGroupWrapper();
    makePyLayerFilterManagerWrapper();

    def("curDoc", curPyDoc);
    def("Command", PyCommandDecorator1, (arg("flags") = InternalCmdFlags::kMODAL));
    def("Command", PyCommandDecorator2, (arg("name") = "", arg("flags") = InternalCmdFlags::kMODAL));
    def("LispFunction", PyLispFuncDecorator1);
    def("LispFunction", PyLispFuncDecorator2);
};

void initPyApModule()
{
    PyImport_AppendInittab(PyApNamespace, &PyInit_PyAp);
}


