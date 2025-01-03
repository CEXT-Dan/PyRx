#pragma once
#pragma pack (push, 8)
struct PyModulePath;

enum InternalCmdFlags
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

bool showNavFileDialog(PyModulePath& path);
boost::python::object PyCommandDecorator(const std::string& name = "", InternalCmdFlags flags = kMODAL);
void regcommand(const std::string& fullpath, const std::string& modulename, const std::string& name, const boost::python::object& func, InternalCmdFlags flags);
bool loadPythonModule(const PyModulePath& path, bool silent);
bool reloadPythonModule(const PyModulePath& path, bool silent);
bool ads_loadPythonModule(const std::filesystem::path& pypath);
bool ads_reloadPythonModule(const std::filesystem::path& pypath);
#pragma pack (pop)