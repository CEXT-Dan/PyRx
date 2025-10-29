#pragma once
#pragma pack (push, 8)
struct PyModulePath;

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


bool showNavFileDialog(PyModulePath& path);
boost::python::object PyCommandDecorator1(int flags = CmdFlags::kMODAL);
boost::python::object PyCommandDecorator2(const std::string& name = "", int flags = CmdFlags::kMODAL);
boost::python::object PyLispFuncDecorator1();
boost::python::object PyLispFuncDecorator2(const std::string& name);
boost::python::object PyUsingDecorator();

void regcommand(const std::string& fullpath, const std::string& modulename, const std::string& name, const boost::python::object& func, int flags);
void removecommand(const std::string& modulename, const std::string& name);

bool loadPythonModule(const PyModulePath& path, bool silent);
bool reloadPythonModule(const PyModulePath& path, bool silent);
bool ads_loadPythonModule(const std::filesystem::path& pypath,  bool silent = true);
bool ads_reloadPythonModule(const std::filesystem::path& pypath, bool silent = true);

#pragma pack (pop)