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

static DWORD writeLineToConsole(const std::wstring& buffer)
{
    DWORD numberOfCharsWritten = 0;
    WriteConsole(GetStdHandle(STD_OUTPUT_HANDLE), buffer.c_str(), buffer.size(), &numberOfCharsWritten, nullptr);
    return numberOfCharsWritten;
}

static BOOL WINAPI CtrlHandler(DWORD fdwCtrlType)
{
    switch (fdwCtrlType)
    {
        case CTRL_C_EVENT:
        case CTRL_CLOSE_EVENT:
        case CTRL_BREAK_EVENT:
        case CTRL_LOGOFF_EVENT:
        case CTRL_SHUTDOWN_EVENT:
            writeLineToConsole(L"\nUse quit() to exit: \n");
            return TRUE;
        default:
            return FALSE;
    }
}

static bool fireOnbeginConsole()
{
    if (HMENU hSysMenu = ::GetSystemMenu(GetConsoleWindow(), FALSE); hSysMenu)
    {
        ::EnableMenuItem(hSysMenu, SC_CLOSE, (MF_DISABLED | MF_GRAYED | MF_BYCOMMAND));
        if (SetConsoleCtrlHandler(CtrlHandler, TRUE))
            return true;
    }
    return false;
}

static PyApDocument curPyDoc()
{   
    if (curDoc() == nullptr)
        PyThrowBadEs(eNoDocument);
    return PyApDocument(curDoc(), false);
}

static BOOST_PYTHON_MODULE(PyAp)
{
    docstring_options local_docstring_options(py_show_user_defined, py_show_py_signatures, py_show_cpp_signatures);

    register_exception_translator<PyNullObject>(PyNullObject::translator);
    register_exception_translator<PyNotimplementedByHost>(PyNotimplementedByHost::translator);
    register_exception_translator<PyAcadHrError>(PyAcadHrError::translator);
    register_exception_translator<PyRxEKeyError>(&PyRxEKeyError::translate);

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

    enum_<PyRxTestFlags>("PyRxTestFlags")
        .value("kNoOptimize", PyRxTestFlags::kPyTfNoOptimize)
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

    PyDocString DSCmd("CommandFunction");
    PyDocString DSLsp("LispFunction");

    constexpr const std::string_view CommandOverloads = "Overloads:\n"
        "- None: Any\n"
        "- commandName: str\n"
        "- commandName: str, CmdFlags: int\n";

    constexpr const std::string_view LispOverloads = "Overloads:\n"
        "- None: Any\n"
        "- functionName: str\n";

    def("curDoc", curPyDoc);
    def("fireOnbeginConsole", fireOnbeginConsole);
    def("Command", PyCommandDecorator1, (arg("flags") = CmdFlags::kMODAL));
    def("Command", PyCommandDecorator2, (arg("name") = "", arg("flags") = CmdFlags::kMODAL), DSCmd.SOVRL(CommandOverloads));
    def("LispFunction", PyLispFuncDecorator1);
    def("LispFunction", PyLispFuncDecorator2, DSLsp.SOVRL(LispOverloads));
    def("using_scope", PyUsingDecorator);
};

void initPyApModule()
{
    PyImport_AppendInittab(PyApNamespace, &PyInit_PyAp);
}


