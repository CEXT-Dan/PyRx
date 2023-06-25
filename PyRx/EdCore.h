#pragma once
class PyDbObjectId;
class PyDbDatabase;

void makeEdCoreWrapper();

class EdCore
{
public:
  static int                 alert(const std::string& msg);
  static int                 arxLoad(const std::string& msg);
  static boost::python::list arxLoaded();
  static int                 arxUnload(const std::string& app);
  static Acad::ErrorStatus   audit1(PyDbDatabase& pDb,bool bFixErrors);
  static Acad::ErrorStatus   audit2(PyDbDatabase& pDb, bool bFixErrors, bool bCmdLnEcho);
  static void                callBackOnCancel();
  static bool                clearOLELock(int handle);
  static bool                cmdS(const boost::python::list& lst);
  static std::string         findFile(const std::string& file);
  static std::string         findTrustedFile(const std::string& file);
  static boost::python::list getPredefinedPattens();
  static Acad::ErrorStatus   xrefDetach1(const std::string& XrefBlockname);
  static Acad::ErrorStatus   xrefDetach2(const std::string& XrefBlockname, bool bQuiet, PyDbDatabase& db);
  static std::string         getFileD(const std::string& title, const std::string& defawlt, const std::string& ext, int flags);
  static boost::python::list getFileNavDialog(const std::string& title, const std::string& defawlt, const std::string& ext, const std::string& dlgname, int flags);
  static boost::python::object getVar(const std::string& sym);
  static bool                  setVar(const std::string& sym, const  boost::python::object&);
};

