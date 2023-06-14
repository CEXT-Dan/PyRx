#pragma once
class PyDbObjectId;
class PyDbDatabase;

void makeEdCoreWrapper();

class EdCore
{
public:
  static PyDbObjectId activeViewportId();
  static int alert(const std::string& msg);
  static int arxLoad(const std::string& msg);
  static boost::python::list arxLoaded();
  static int arxUnload(const std::string& app);
  static Acad::ErrorStatus audit1(PyDbDatabase& pDb,bool bFixErrors);
  static Acad::ErrorStatus audit2(PyDbDatabase& pDb, bool bFixErrors, bool bCmdLnEcho);
  static void callBackOnCancel();
  static bool clearOLELock(int handle);

  static bool           cmdS(const boost::python::list& lst);
  static std::string    findFile(const std::string& file);
  static std::string    findTrustedFile(const std::string& file);


  static Acad::ErrorStatus xrefDetach1(const std::string& XrefBlockname);
  static Acad::ErrorStatus xrefDetach2(const std::string& XrefBlockname, bool bQuiet, PyDbDatabase& db);
};

