#pragma once
class PyDbObjectId;
class PyDbDatabase;

void makeEdCoreWrapper();

class EdCore
{
public:
    static int                  alert(const std::string& msg);
    static int                  arxLoad(const std::string& msg);
    static boost::python::list  arxLoaded();
    static int                  arxUnload(const std::string& app);
    static Acad::ErrorStatus    audit1(PyDbDatabase& pDb, bool bFixErrors);
    static Acad::ErrorStatus    audit2(PyDbDatabase& pDb, bool bFixErrors, bool bCmdLnEcho);
    static void                 callBackOnCancel();
    static bool                 clearOLELock(int handle);
    static bool                 cmdS(const boost::python::list& lst);
    static std::string          findFile(const std::string& file);
    static std::string          findTrustedFile(const std::string& file);
    static boost::python::list  getPredefinedPattens();
    static std::string          getFileD(const std::string& title, const std::string& defawlt, const std::string& ext, int flags);
    static boost::python::list  getFileNavDialog(const std::string& title, const std::string& defawlt, const std::string& ext, const std::string& dlgname, int flags);
    static boost::python::object getVar(const std::string& sym);
    static bool                  setVar(const std::string& sym, const  boost::python::object&);
    static Acad::ErrorStatus    mSpace();
    static Acad::ErrorStatus    pSpace();
    static int                  grDraw(const AcGePoint3d& from, const AcGePoint3d& to, int colorIndex, int highlight);
    static int                  update(int vport, const AcGePoint2d& p1, const AcGePoint2d& p2);
    static void                 updateDisplay();
    static void                 updateDisplayPause(bool bEnable);
    static bool                 usrBrk();
    static PyDbObjectId         viewportIdFromNumber(int val);
    static Acad::ErrorStatus    vpLayer(const PyDbObjectId& vpId, const boost::python::list& layerIds, AcDb::VpFreezeOps operation);
    static boost::python::list  vports();
    static Acad::ErrorStatus    vports2VportTableRecords();
    static Acad::ErrorStatus    vportTableRecords2Vports();
    static Acad::ErrorStatus    xrefAttach1(const std::string& path, const std::string& name);
    static Acad::ErrorStatus    xrefAttach2(const std::string& path, const std::string& name, PyDbObjectId& btrid, PyDbObjectId& refid, AcGePoint3d& pt,
        AcGeScale3d& sc, double rot, bool bQuiet, PyDbDatabase& pHostDb, const std::string& passwd);

    static std::string          xrefCreateBlockname(const std::string& XrefPathname);
    static Acad::ErrorStatus    xrefDetach1(const std::string& XrefBlockname);
    static Acad::ErrorStatus    xrefDetach2(const std::string& XrefBlockname, bool bQuiet, PyDbDatabase& pHostDb);
    static bool                 xrefNotifyCheckFileChanged(const PyDbObjectId& id);
    static Acad::ErrorStatus    xrefOverlay1(const std::string& path, const std::string& name);
    static Acad::ErrorStatus    xrefOverlay2(const std::string& path, const std::string& name, PyDbObjectId& btrid, PyDbObjectId& refid, AcGePoint3d& pt,
        AcGeScale3d& sc, double rot, bool bQuiet, PyDbDatabase& pHostDb, const std::string& passwd);
    static Acad::ErrorStatus    xrefReload1(const boost::python::list& symbolIds);
    static Acad::ErrorStatus    xrefReload2(const boost::python::list& symbolIds, bool bQuiet, PyDbDatabase& pHostDb);
    static Acad::ErrorStatus    xrefReload3(const std::string& name);
    static Acad::ErrorStatus    xrefReload4(const std::string& name, bool bQuiet, PyDbDatabase& pHostDb);
    static Acad::ErrorStatus    xrefResolve1(PyDbDatabase& pHostDb);
    static Acad::ErrorStatus    xrefResolve2(PyDbDatabase& pHostDb, bool bQuiet);
    static Acad::ErrorStatus    xrefUnload1(const std::string& XrefBlockname);
    static Acad::ErrorStatus    xrefUnload2(const std::string& XrefBlockname, bool bQuiet, PyDbDatabase& pHostDb);
    static Acad::ErrorStatus    xrefBind1(const std::string& XrefBlockname);
    static Acad::ErrorStatus    xrefBind2(const std::string& XrefBlockname, bool bInsertBind, bool bQuiet, PyDbDatabase& pHostDb);
    static Acad::ErrorStatus    xrefXBind1(const boost::python::list& symbolIds);
    static Acad::ErrorStatus    xrefXBind2(const boost::python::list& symbolIds, bool bQuiet, PyDbDatabase& pHostDb);

};

