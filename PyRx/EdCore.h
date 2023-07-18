#pragma once
class PyDbObjectId;
class PyDbDatabase;

void makePyEdCoreWrapper();

//acedSetUndoMark

class EdCore
{
public:
    static int                  alert(const std::string& msg);
    static int                  arxLoad(const std::string& msg);
    static boost::python::list  arxLoaded();
    static int                  arxUnload(const std::string& app);
    static void                 audit1(PyDbDatabase& pDb, bool bFixErrors);
    static void                 audit2(PyDbDatabase& pDb, bool bFixErrors, bool bCmdLnEcho);
    static void                 callBackOnCancel();
    static bool                 clearOLELock(int handle);
    static bool                 cmdS(const boost::python::list& lst);
    static std::string          findFile(const std::string& file);
    static std::string          findTrustedFile(const std::string& file);
    static boost::python::list  getPredefinedPattens();
    static std::string          getFileD(const std::string& title, const std::string& defawlt, const std::string& ext, int flags);
    static boost::python::list  getFileNavDialog(const std::string& title, const std::string& defawlt, const std::string& ext, const std::string& dlgname, int flags);
    static std::string          getCommandPromptString();
    static boost::python::object getVar(const std::string& sym);
    static bool                  setVar(const std::string& sym, const  boost::python::object&);
    static void                 mSpace();
    static void                 pSpace();
    static int                  grDraw(const AcGePoint3d& from, const AcGePoint3d& to, int colorIndex, int highlight);
    static void                 setUndoMark(bool flag);
    static bool                 showHTMLModalWindow1(UINT_PTR hwnd, const std::string & uriOfHtmlPage);
    static bool                 showHTMLModalWindow2(UINT_PTR hwnd, const std::string& uriOfHtmlPage, bool persistSizeAndPosition);
    static int                  update(int vport, const AcGePoint2d& p1, const AcGePoint2d& p2);
    static void                 updateDisplay();
    static void                 updateDisplayPause(bool bEnable);
    static bool                 usrBrk();
    static PyDbObjectId         viewportIdFromNumber(int val);
    static void                 vpLayer(const PyDbObjectId& vpId, const boost::python::list& layerIds, AcDb::VpFreezeOps operation);
    static boost::python::list  vports();
    static void                 vports2VportTableRecords();
    static void                 vportTableRecords2Vports();
    static void                 xrefAttach1(const std::string& path, const std::string& name);
    static void                 xrefAttach2(const std::string& path, const std::string& name, PyDbObjectId& btrid, PyDbObjectId& refid, AcGePoint3d& pt,
        AcGeScale3d& sc, double rot, bool bQuiet, PyDbDatabase& pHostDb, const std::string& passwd);

    static std::string          xrefCreateBlockname(const std::string& XrefPathname);
    static void                 xrefDetach1(const std::string& XrefBlockname);
    static void                 xrefDetach2(const std::string& XrefBlockname, bool bQuiet, PyDbDatabase& pHostDb);
    static bool                 xrefNotifyCheckFileChanged(const PyDbObjectId& id);
    static void                 xrefOverlay1(const std::string& path, const std::string& name);
    static void                 xrefOverlay2(const std::string& path, const std::string& name, PyDbObjectId& btrid, PyDbObjectId& refid, AcGePoint3d& pt,
        AcGeScale3d& sc, double rot, bool bQuiet, PyDbDatabase& pHostDb, const std::string& passwd);
    static void                 xrefReload1(const boost::python::list& symbolIds);
    static void                 xrefReload2(const boost::python::list& symbolIds, bool bQuiet, PyDbDatabase& pHostDb);
    static void                 xrefReload3(const std::string& name);
    static void                 xrefReload4(const std::string& name, bool bQuiet, PyDbDatabase& pHostDb);
    static void                 xrefResolve1(PyDbDatabase& pHostDb);
    static void                 xrefResolve2(PyDbDatabase& pHostDb, bool bQuiet);
    static void                 xrefUnload1(const std::string& XrefBlockname);
    static void                 xrefUnload2(const std::string& XrefBlockname, bool bQuiet, PyDbDatabase& pHostDb);
    static void                 xrefBind1(const std::string& XrefBlockname);
    static void                 xrefBind2(const std::string& XrefBlockname, bool bInsertBind, bool bQuiet, PyDbDatabase& pHostDb);
    static void                 xrefXBind1(const boost::python::list& symbolIds);
    static void                 xrefXBind2(const boost::python::list& symbolIds, bool bQuiet, PyDbDatabase& pHostDb);
};

