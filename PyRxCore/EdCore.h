#pragma once
#pragma pack (push, 8)

class PyDbObjectId;
class PyDbDatabase;
class PyDbMText;
class PyApDocument;
class PyDbBlockTableRecord;
class PyDbViewTableRecord;
class PyDbViewport;
class PySysVar;
class PyDbHatch;
class PyDbEntity;
class PyDbXrefGraph;

// TODO:
// acedGetAcadFrame
// acedGetApplicationFrame();

void makePyUtilWrapper();
class Util
{
public:
    static double               angle(const AcGePoint3d& pt1, const AcGePoint3d& pt2);
    static double               cvUnit(double val, const std::string& oldunit, const std::string& newunit);
    static double               distance(const AcGePoint3d& pt1, const AcGePoint3d& pt2);
    static AcGePoint3d          polar(const AcGePoint3d& pt, double angle, double dist);
    static bool                 wcMatch(const std::string& string, const std::string& pattern, bool ignoreCase);
};

void makePyEdCoreWrapper();

class EdCore
{
public:
    static bool                 addSupplementalCursorImage1(const boost::python::object& image);
    static bool                 addSupplementalCursorImage2(const boost::python::object& image, int order, Adesk::UInt8 alpha);
    static bool                 removeSupplementalCursorImage();
    static bool                 hasSupplementalCursorImage();
    static void                 setSupplementalCursorOffset(int x, int y);
    static boost::python::tuple getSupplementalCursorOffset();
    static ULONG_PTR            getAcadDockCmdLine();
    static ULONG_PTR            getAcadTextCmdLine();
    static int                  alert(const std::string& msg);
    static int                  arxLoad(const std::string& msg);
    static boost::python::list  arxLoaded();
    static int                  arxUnload(const std::string& app);
    static void                 audit1(PyDbDatabase& pDb, bool bFixErrors);
    static void                 audit2(PyDbDatabase& pDb, bool bFixErrors, bool bCmdLnEcho);
    static void                 callBackOnCancel();
    static bool                 clearOLELock(int handle);
    static std::string          clipFormatName();
    static bool                 cmdCWasCancelled();
    static int                  cmdUndefine(const std::string& name, int undefIt);
    static boost::python::dict  getCommands();
    static boost::python::tuple calcTextExtents(const std::string& strval, const PyDbObjectId& textStyle);
    static void                 convertEntityToHatch(const PyDbHatch& hatch, const PyDbEntity& entity, bool transferId);
    static AcGePoint3d          coordFromPixelToWorld1(const boost::python::tuple& tin);
    static AcGePoint3d          coordFromPixelToWorld2(int windnum, const boost::python::tuple& tin);
    static boost::python::tuple coordFromWorldToPixel(int windnum, const AcGePoint3d& pnt);
    static bool                 createInternetShortcut(const std::string& szURL, const std::string& szShortcutPath);
    static PyDbObjectId         createViewportByView(PyDbDatabase& db, PyDbObjectId& view, const AcGePoint2d& location, double scale);
    static bool                 cmdS1(const std::string& name);
    static bool                 cmdS2(const boost::python::list& lst);
    static int                  defun(const std::string& pszName, int nFuncNum);
    static int                  defunEx(const std::string& pszGlobalName, const std::string& pszLocalName, int nFuncNum);
    static void                 disableDefaultARXExceptionHandler(bool flag);
    static void                 disableUsrbrk();
    static bool                 displayBorder(bool flag);
    static bool                 drawingStatusBarsVisible();
    static void                 drawOrderInherit(PyDbObjectId& parent, const boost::python::list& childArray, AcEdDrawOrderCmdType cmd);
    static void                 dropOpenFile(const std::string& value);
    static int                  eatCommandThroat();
    static int                  editMTextInteractive(PyDbMText& mtext, bool useNewUI, bool allowTabs);
    static void                 enableUsrbrk();
    static boost::python::list  evaluateLisp(const std::string& str);
    static std::string          evaluateDiesel(const std::string& str);
    static std::string          findFile(const std::string& file);
    static std::string          findTrustedFile(const std::string& file);
    static boost::python::list  getPredefinedPattens();
    static std::string          getFileD(const std::string& title, const std::string& defawlt, const std::string& ext, int flags);
    static boost::python::list  getFileNavDialog(const std::string& title, const std::string& defawlt, const std::string& ext, const std::string& dlgname, int flags);
    static std::string          getCommandPromptString();
    static boost::python::list  getLastCommandLines(int lineCount, bool ignoreNull);
    static unsigned int         getBlockEditMode();
    static std::string          getCommandForDocument(const PyApDocument& doc);
    static boost::python::list  getCurrentSelectionSet();
    static boost::python::tuple getCurVportPixelToDisplay();
    static boost::python::tuple getCurVportScreenToDisplay();
    static float                getDpiScalingValue();
    static std::string          getUserFavoritesDir();
    static std::string          getEnv(const std::string& str);
    static void                 setEnv(const std::string& sym, const std::string& val);
    static std::string          getCfg(const std::string& str);
    static void                 setCfg(const std::string& sym, const std::string& val);
    static boost::python::list  getSym(const std::string& symname);
    static bool                 putSym(const std::string& symname, boost::python::list& buf);
    static int                  getWinNum(int ptx, int pty);
    static boost::python::tuple getRGB(int idx);
    static void                 graphScr();
    static boost::python::dict  getSysVars();
    static boost::python::object getVar(const std::string& sym);
    static bool                  setVar(const std::string& sym, const boost::python::object&);
    static PySysVar              autoSetVar(const std::string& sym, const  boost::python::object& val);
    static int                  grDraw1(const AcGePoint2d& from, const AcGePoint2d& to, int colorIndex, int highlight);
    static int                  grDraw2(const AcGePoint3d& from, const AcGePoint3d& to, int colorIndex, int highlight);
    static int                  grDrawArc(const AcGePoint3d& p1, const AcGePoint3d& p2, const AcGePoint3d& p3, int nsegs, int colorIndex);
    static int                  grDrawBox(const boost::python::object& iterable, int colorIndex, int highlight);
    static int                  grDrawCircle(const AcGePoint3d& cen, double radius, int nsegs, int colorIndex);
    static int                  grDrawPoly2d(const boost::python::object& iterable, int colorIndex);
    static int                  grDrawPoly3d(const boost::python::object& iterable, int colorIndex);
    static int                  grVecs(const boost::python::list& iterable, const AcGeMatrix3d& mat);
    static int                  grText(int box, const std::string& text, int hl);
    static AcGePoint3d          getMousePositionUCS();
    static AcGePoint3d          getMousePositionWCS();
    static std::string          hatchPalletteDialog(const std::string& pattern, bool showCustom);
    static boost::python::list  invoke(const boost::python::list& args);
    static Adesk::Boolean       initDialog(Adesk::Boolean useDialog);
    static int                  isDragging();
    static bool                 isInBackgroundMode();
    static bool                 isInputPending();
    static Adesk::Boolean       isMenuGroupLoaded(const std::string& mnu);
    static bool                 isOsnapOverride();
    static bool                 isUpdateDisplayPaused();
    static bool                 isUsrbrkDisabled();
    static void                 loadJSScript(const std::string& pUriOfJSFile);
    static bool                 loadPartialMenu(const std::string& mnu);
    static bool                 loadMainMenu(const std::string& mnu);
    static void                 markForDelayXRefRelativePathResolve(const PyDbObjectId& id);
    static int                  menuCmd(const std::string& mnu);
    static void                 mSpace();
    static void                 pSpace();
    static void                 postCommand(const std::string& str);
    static void                 postCommandPrompt();
    static int                  prompt(const std::string& str);
    static int                  redraw(const PyDbObjectId& ent, int mode);
    static void                 reloadMenus(bool bIncrementalReloading);
    static void                 restoreCurrentView(const PyDbObjectId& namedViewId);
    static void                 restorePreviousUCS();
    static void                 restoreStatusBar();
    static void                 regen();
    static void                 sendModelessOperationEnded(const std::string& strContext);
    static void                 sendModelessOperationStart(const std::string& strContext);
    static boost::python::tuple setColorDialog(int color, Adesk::Boolean bAllowMetaColor, int nCurLayerColor);
    static boost::python::tuple setColorDialogTrueColor1(const AcCmColor& color, Adesk::Boolean bAllowMetaColor, const AcCmColor& nCurLayerColor);
    static boost::python::tuple setColorDialogTrueColor2(const AcCmColor& color, Adesk::Boolean bAllowMetaColor, const AcCmColor& nCurLayerColor, AcCm::DialogTabs tab);
    static AcGePoint3d          osnap(const AcGePoint3d& pt, const std::string& mode);

    static AcCmColor            setColorPrompt(const std::string& prompt, bool bAllowMetaColor);
    static void                 setUndoMark(bool flag);
    static PyDbViewTableRecord  getCurrentView();
    static void                 setCurrentView1(const PyDbViewTableRecord& vrec);
    static void                 setCurrentView2(const PyDbViewTableRecord& vrec, const PyDbViewport& vp);
    static void                 setCurrentVPort(const PyDbViewport& vp);
    static int                  setStatusBarProgressMeter(const std::string& pszLabel, int nMinPos, int nMaxPos);
    static int                  setStatusBarProgressMeterPos(int pos);
    static void                 setXrefResolvedWithUpdateStatus(const PyDbBlockTableRecord& rec);
    static bool                 showHTMLModalWindow1(UINT_PTR hwnd, const std::string& uriOfHtmlPage);
    static bool                 showHTMLModalWindow2(UINT_PTR hwnd, const std::string& uriOfHtmlPage, bool persistSizeAndPosition);
    static UINT_PTR             showHTMLModelessWindow1(UINT_PTR owner, const std::string& uriOfHtmlPage);
    static UINT_PTR             showHTMLModelessWindow2(UINT_PTR owner, const std::string& uriOfHtmlPage, bool persistSizeAndPosition);
    static void                 skipXrefNotification(PyDbDatabase& db, const std::string& xrefName);
    static void                 setFieldUpdateEnabled(PyApDocument& doc, bool enabled);
    static int                  setFunHelp(const std::string& pszFunctionName, const std::string& pszHelpfile, const std::string& pszTopic, int iCmd);
    static boost::python::tuple textBox(const boost::python::list& pyargs);
    static void                 textPage();
    static void                 textScr();
    static AcGePoint3d          trans(const AcGePoint3d& pt, const boost::python::object& from, const boost::python::object& to, bool disp);
    static bool                 unloadPartialMenu(const std::string& pszMenuFile);
    static void                 unmarkForDelayXRefRelativePathResolve(const PyDbObjectId& xrefDefId);
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
    static PyDbXrefGraph        curDwgXrefGraph();
    static std::string          exceptionTest();
};
#pragma pack (pop)

