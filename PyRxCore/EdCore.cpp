#include "stdafx.h"
#include "EdCore.h"
#include "PyDbObjectId.h"
#include "PyDbDatabase.h"
#include "ResultBuffer.h"
#include "acedCmdNF.h"
#include "PyDbMText.h"
#include "PyApDocument.h"
#include "PyDbViewport.h"
#include "PyDbSymbolTableRecord.h"
#include "rxvar.h"
#include "PyEdUserInteraction.h"
#include "PyDbHatch.h"
#include "PyRxApp.h"
#include "PyDbGraph.h"
#include "xgraph.h"


#ifdef ARXAPP
#include "AcHTMLApi.h"
#endif

using namespace boost::python;

void                            ads_regen(void);

#ifdef ZRXAPP
int                             zcedEvaluateLisp(ACHAR const* str, resbuf*& result);
extern bool                     zcedHatchPalletteDialog(wchar_t const*, bool, wchar_t*&);
#endif

#ifdef GRXAPP
int                             gcedEvaluateLisp(ACHAR const* str, resbuf*& result);
extern Adesk::Boolean           gcedHatchPalletteDialog(wchar_t const*, Adesk::Boolean, wchar_t*&);
extern Adesk::Boolean           gcedPostCommand(const ACHAR*);
#endif

#ifdef BRXAPP
int                             acedEvaluateLisp(ACHAR const* str, resbuf*& result);
extern  bool                    acedHatchPalletteDialog(const wchar_t*, bool, wchar_t*&);
extern Adesk::Boolean           acedPostCommand(const ACHAR*);
#endif


#ifdef ARXAPP
int                             acedEvaluateLisp(ACHAR const* str, resbuf*& result);
int                             acedEvaluateDiesel(const ACHAR*, ACHAR*, size_t);
EXTERN_C void                   acedLoadJSScript(const ACHAR* pUriOfJSFile);
EXTERN_C bool                   acedGetPredefinedPattens(AcStringArray& patterns);
EXTERN_C Acad::ErrorStatus      acedSetUndoMark(bool);
EXTERN_C void                   acedGetCommandPromptString(CString&);
EXTERN_C void                   acedDropOpenFile(const ACHAR*);
extern void                     acedGetLastCommandLines(AcStringArray&, int, bool);
extern Adesk::Boolean           acedPostCommand(const ACHAR*);
bool                            acedLoadMainMenu(const ACHAR*);
extern Adesk::Boolean           acedHatchPalletteDialog(wchar_t const*, Adesk::Boolean, wchar_t*&);

//acedLinetypeDialog()
//acedLineWeightDialog()
#endif

//-----------------------------------------------------------------------------------------
//Util
void makePyUtilWrapper()
{
    PyDocString DS("Util");
    class_<Util>("Util")
        .def(init<>(DS.ARGS()))
        .def("angle", &Util::angle, DS.SARGS({ "pt1: PyGe.Point3d","pt2: PyGe.Point3d" })).staticmethod("angle")
        .def("cvUnit", &Util::cvUnit, DS.SARGS({ "val: float","oldunit: str","newunit: str" })).staticmethod("cvUnit")
        .def("distance", &Util::distance, DS.SARGS({ "pt1: PyGe.Point3d","pt2: PyGe.Point3d" })).staticmethod("distance")
        .def("polar", &Util::polar, DS.SARGS({ "pt1: PyGe.Point3d","angle: float","dist: float" })).staticmethod("polar")
        .def("wcMatch", &Util::wcMatch, DS.SARGS({ "string: str","pattern: str","ignoreCase: bool" })).staticmethod("wcMatch")
        ;
}

double Util::angle(const AcGePoint3d& pt1, const AcGePoint3d& pt2)
{
    return acutAngle(asDblArray(pt1), asDblArray(pt1));
}

double Util::cvUnit(double val, const std::string& oldunit, const std::string& newunit)
{
    double result = 0;
    PyThrowBadRt(acutCvUnit(val, utf8_to_wstr(oldunit).c_str(), utf8_to_wstr(newunit).c_str(), &result));
    return result;
}

double Util::distance(const AcGePoint3d& pt1, const AcGePoint3d& pt2)
{
    return acutDistance(asDblArray(pt1), asDblArray(pt1));
}

AcGePoint3d Util::polar(const AcGePoint3d& pt, double angle, double dist)
{
    AcGePoint3d result;
    acutPolar(asDblArray(pt), angle, dist, asDblArray(result));
    return result;
}

bool Util::wcMatch(const std::string& string, const std::string& pattern, bool ignoreCase)
{
    return acutWcMatchEx(utf8_to_wstr(string).c_str(), utf8_to_wstr(pattern).c_str(), ignoreCase);
}

//-----------------------------------------------------------------------------------------
//EdCore
void makePyEdCoreWrapper()
{
    constexpr const std::string_view xrefAttachOverloads = "Overloads:\n"
        "- path: str, name: str\n"
        "- path: str, name: str, btrid: PyDb.ObjectId, refid: PyDb.ObjectId, pt: PyGe.Point3d, sc: PyGe.Scale3d, rot: float, bQuiet: bool, pHostDb: PyDb.Database, passwd: str\n";

    constexpr const std::string_view xrefDetachOverloads = "Overloads:\n"
        "- XrefBlockname: str\n"
        "- XrefBlockname: str, bQuiet: bool, pHostDb: PyDb.Database\n";

    constexpr const std::string_view xrefOverlayhOverloads = "Overloads:\n"
        "- path: str, name: str\n"
        "- path: str, name: str, btrid: PyDb.ObjectId, refid: PyDb.ObjectId, pt: PyGe.Point3d, sc: PyGe.Scale3d, rot: float, bQuiet: bool, pHostDb: PyDb.Database, passwd: str\n";

    constexpr const std::string_view xrefReloadOverloads = "Overloads:\n"
        "- symbolIds: list[PyDb.ObjectId]\n"
        "- symbolIds: list[PyDb.ObjectId], bQuiet: bool, pHostDb: PyDb.Database\n"
        "- name: str\n"
        "- name: str, bQuiet: bool, pHostDb: PyDb.Database\n";

    constexpr const std::string_view xrefUnloadOverloads = "Overloads:\n"
        "- XrefBlockname: str\n"
        "- XrefBlockname: str, bQuiet: bool, pHostDb: PyDb.Database\n";

    constexpr const std::string_view xrefBindOverloads = "Overloads:\n"
        "- XrefBlockname: str\n"
        "- XrefBlockname: str,bInsertBind: bool, bQuiet: bool, pHostDb: PyDb.Database\n";

    constexpr const std::string_view  xrefXBindOverloads = "Overloads:\n"
        "- symbolIds: list[PyDb.ObjectId]\n"
        "- symbolIds: list[PyDb.ObjectId], bQuiet: bool, pHostDb: PyDb.Database\n";

    constexpr const std::string_view  coordFromPixelToWorldOverloads = "Overloads:\n"
        "- pt: tuple[int,int]\n"
        "- winnum: int, pt: tuple[int,int]\n";

    constexpr const std::string_view  cmdSOverloads = "Overloads:\n"
        "- commandName:str\n"
        "- resultBuffer:list[tuple[int,Any]]\n";

    PyDocString DS("Core");
    class_<EdCore>("Core")
        .def(init<>(DS.ARGS()))
        .def("alert", &EdCore::alert, DS.SARGS({ "msg: str" }, 10717)).staticmethod("alert")
        .def("arxLoad", &EdCore::arxLoad, DS.SARGS({ "path: str" }, 10718)).staticmethod("arxLoad")
        .def("arxLoaded", &EdCore::arxLoaded, DS.SARGS(10719)).staticmethod("arxLoaded")
        .def("arxUnload", &EdCore::arxUnload, DS.SARGS({ "app: str" }, 10720)).staticmethod("arxUnload")
        .def("audit", &EdCore::audit1)
        .def("audit", &EdCore::audit2, DS.SARGS({ "db: PyDb.Database", "fix: bool","echo: bool=False" }, 10721)).staticmethod("audit")
        .def("callBackOnCancel", &EdCore::callBackOnCancel, DS.SARGS(10722)).staticmethod("callBackOnCancel")
        .def("calcTextExtents", &EdCore::calcTextExtents, DS.SARGS({ "val: str" , "textStyleId: PyDb.ObjectId" })).staticmethod("calcTextExtents")
        .def("clearOLELock", &EdCore::clearOLELock, DS.SARGS({ "handle: int" }, 10723)).staticmethod("clearOLELock")
        .def("clipFormatName", &EdCore::clipFormatName, DS.SARGS(10724)).staticmethod("clipFormatName")
        .def("cmdCWasCancelled", &EdCore::cmdCWasCancelled, DS.SARGS(10726)).staticmethod("cmdCWasCancelled")
        .def("cmdUndefine", &EdCore::cmdUndefine, DS.SARGS({ "name: str", "undefineit: int" }, 10730)).staticmethod("cmdUndefine")
        .def("getCommands", &EdCore::getCommands, DS.SARGS()).staticmethod("getCommands")
        .def("coordFromPixelToWorld", &EdCore::coordFromPixelToWorld1)
        .def("coordFromPixelToWorld", &EdCore::coordFromPixelToWorld2, DS.SOVRL(coordFromPixelToWorldOverloads, 10775)).staticmethod("coordFromPixelToWorld")
        .def("coordFromWorldToPixel", &EdCore::coordFromWorldToPixel, DS.SARGS({ "windnum: int ","pnt: PyGe.Point3d" }, 10776)).staticmethod("coordFromWorldToPixel")
        .def("convertEntityToHatch", &EdCore::convertEntityToHatch, DS.SARGS({ "hatch: PyDb.Hatch","entity: PyDb.Entity", "transferId: bool" }, 10774)).staticmethod("convertEntityToHatch")
        .def("createInternetShortcut", &EdCore::createInternetShortcut, DS.SARGS({ "szURL: str","szShortcutPath: str" }, 10779)).staticmethod("createInternetShortcut")
        .def("createViewportByView", &EdCore::createViewportByView, DS.SARGS({ "db: PyDb.Database","view: PyDb.ObjectId","pt: PyGe.Point2d","scale: float" }, 10783)).staticmethod("createViewportByView")
        .def("cmdS", &EdCore::cmdS1)
        .def("cmdS", &EdCore::cmdS2, DS.SOVRL(cmdSOverloads, 10729)).staticmethod("cmdS")
        .def("defun", &EdCore::defun, DS.SARGS({ "name: str", "funcnumber: int" }, 10784)).staticmethod("defun")
        .def("defunEx", &EdCore::defunEx, DS.SARGS({ "globalName: str", "name: str", "funcnumber: int" }, 10785)).staticmethod("defunEx")
        .def("disableDefaultARXExceptionHandler", &EdCore::disableDefaultARXExceptionHandler, DS.SARGS({ "val: bool" }, 10788)).staticmethod("disableDefaultARXExceptionHandler")
        .def("disableUsrbrk", &EdCore::disableUsrbrk, DS.SARGS(10789)).staticmethod("disableUsrbrk")
        .def("displayBorder", &EdCore::displayBorder, DS.SARGS({ "val: bool" }, 10790)).staticmethod("displayBorder")
        .def("drawingStatusBarsVisible", &EdCore::drawingStatusBarsVisible, DS.SARGS(10803)).staticmethod("drawingStatusBarsVisible")
        .def("drawOrderInherit", &EdCore::drawOrderInherit, DS.SARGS({ "parent: PyDb.ObjectId","childids: list[PyDb.ObjectId]", "cmd: PyEd.DrawOrderCmdType" }, 10805)).staticmethod("drawOrderInherit")
        .def("dropOpenFile", &EdCore::dropOpenFile, DS.SARGS({ "val: str" })).staticmethod("dropOpenFile")
        .def("eatCommandThroat", &EdCore::eatCommandThroat, DS.SARGS(10806)).staticmethod("eatCommandThroat")
        .def("editMTextInteractive", &EdCore::editMTextInteractive, DS.SARGS({ "mt: PyDb.MText", "usenewUI: bool","allowTabs: bool" }, 10808)).staticmethod("editMTextInteractive")
        .def("enableUsrbrk", &EdCore::enableUsrbrk, DS.SARGS(10811)).staticmethod("enableUsrbrk")
        .def("evaluateLisp", &EdCore::evaluateLisp, DS.SARGS({ "statement : str" })).staticmethod("evaluateLisp")
        .def("evaluateDiesel", &EdCore::evaluateDiesel, DS.SARGS({ "statement : str" })).staticmethod("evaluateDiesel")
        .def("findFile", &EdCore::findFile, DS.SARGS({ "fname: str" }, 10815)).staticmethod("findFile")
        .def("findTrustedFile", &EdCore::findTrustedFile, DS.SARGS({ "fname: str" }, 10816)).staticmethod("findTrustedFile")
        .def("getPredefinedHatchPatterns", &EdCore::getPredefinedPattens, DS.SARGS()).staticmethod("getPredefinedHatchPatterns")
        .def("getFileD", &EdCore::getFileD, DS.SARGS({ "title: str", "defawlt: str","ext: str", "flags: int" }, 10855)).staticmethod("getFileD")
        .def("getFileNavDialog", &EdCore::getFileNavDialog, DS.SARGS({ "title: str", "defawlt: str","ext: str","dlgname: str","flags: int" }, 10856)).staticmethod("getFileNavDialog")
        .def("getAcadDockCmdLine", &EdCore::getAcadDockCmdLine, DS.SARGS(10819)).staticmethod("getAcadDockCmdLine")
        .def("getAcadTextCmdLine", &EdCore::getAcadTextCmdLine, DS.SARGS(10823)).staticmethod("getAcadTextCmdLine")
        .def("getCommandForDocument", &EdCore::getCommandForDocument, DS.SARGS({ "doc: PyAp.Document" }, 10838)).staticmethod("getCommandForDocument")
        .def("getCurrentSelectionSet", &EdCore::getCurrentSelectionSet, DS.SARGS(10846)).staticmethod("getCurrentSelectionSet")
        .def("getCurVportPixelToDisplay", &EdCore::getCurVportPixelToDisplay, DS.SARGS(10850)).staticmethod("getCurVportPixelToDisplay")
        .def("getCurVportScreenToDisplay", &EdCore::getCurVportScreenToDisplay, DS.SARGS(10851)).staticmethod("getCurVportScreenToDisplay")
        .def("getEnv", &EdCore::getEnv, DS.SARGS({ "val: str" }, 10854)).staticmethod("getEnv")
        .def("setEnv", &EdCore::setEnv, DS.SARGS({ "sym: str", "val: str" }, 11319)).staticmethod("setEnv")
        .def("getCfg", &EdCore::getCfg, DS.SARGS({ "val: str" }, 10834)).staticmethod("getCfg")
        .def("setCfg", &EdCore::setCfg, DS.SARGS({ "sym: str", "val: str" }, 11305)).staticmethod("setCfg")
        .def("getSym", &EdCore::getSym, DS.SARGS({ "val: str" }, 10876)).staticmethod("getSym")
        .def("putSym", &EdCore::putSym, DS.SARGS({ "sym: str", "resultBuffer: list" }, 11235)).staticmethod("putSym")
        .def("getWinNum", &EdCore::getWinNum, DS.SARGS({ "ptx: int","pty: int" }, 10885)).staticmethod("getWinNum")
        .def("getRGB", &EdCore::getRGB, DS.SARGS({ "colorIndex : int" }, 10873)).staticmethod("getRGB")
        .def("graphScr", &EdCore::graphScr, DS.SARGS(10886)).staticmethod("graphScr")
        .def("grDraw", &EdCore::grDraw1)
        .def("grDraw", &EdCore::grDraw2, DS.SARGS({ "pt1: PyGe.Point2d|PyGe.Point3d","pt2: PyGe.Point2d|PyGe.Point3d","color: int","highlight: int" }, 10887)).staticmethod("grDraw")
        .def("grDrawArc", &EdCore::grDrawArc, DS.SARGS({ "pt1: PyGe.Point3d","pt2: PyGe.Point3d","pt3: PyGe.Point3d","numsegs: int","color: int" })).staticmethod("grDrawArc")
        .def("grDrawBox", &EdCore::grDrawBox, DS.SARGS({ "pts: list[PyGe.Point3d]","color: int","highlight: int" })).staticmethod("grDrawBox")
        .def("grDrawCircle", &EdCore::grDrawCircle, DS.SARGS({ "cen: PyGe.Point3d", "radius: float", "numsegs: int","color: int" })).staticmethod("grDrawCircle")
        .def("grDrawPoly2d", &EdCore::grDrawPoly2d, DS.SARGS({ "pts: list[PyGe.Point2d]","color: int" })).staticmethod("grDrawPoly2d")
        .def("grDrawPoly3d", &EdCore::grDrawPoly3d, DS.SARGS({ "pts: list[PyGe.Point3d]","color: int" })).staticmethod("grDrawPoly3d")
        .def("grVecs", &EdCore::grVecs, DS.SARGS({ "resbuf: list","xform: PyGe.Matrix3d" }, 10890)).staticmethod("grVecs")
        .def("grText", &EdCore::grText, DS.SARGS({ "box: int","text: str","hl: int" }, 10889)).staticmethod("grText")
        .def("getCommandPromptString", &EdCore::getCommandPromptString, DS.SARGS()).staticmethod("getCommandPromptString")
        .def("getLastCommandLines", &EdCore::getLastCommandLines, DS.SARGS({ "lineCount: int","ignoreNull: bool" })).staticmethod("getLastCommandLines")
        .def("getBlockEditMode", &EdCore::getBlockEditMode, DS.SARGS(10832)).staticmethod("getBlockEditMode")
        .def("getVar", &EdCore::getVar, DS.SARGS({ "name:str" }, 10884)).staticmethod("getVar")
        .def("setVar", &EdCore::setVar, DS.SARGS({ "name:str","value" }, 11328)).staticmethod("setVar")
        .def("autoSetVar", &EdCore::autoSetVar, DS.SARGS({ "name:str","value" })).staticmethod("autoSetVar")
        .def("getSysVars", &EdCore::getSysVars, DS.SARGS()).staticmethod("getSysVars")
        .def("getMousePositionUCS", &EdCore::getMousePositionUCS, DS.SARGS()).staticmethod("getMousePositionUCS")
        .def("getMousePositionWCS", &EdCore::getMousePositionWCS, DS.SARGS()).staticmethod("getMousePositionWCS")
        .def("getDpiScalingValue", &EdCore::getDpiScalingValue, DS.SARGS(10853)).staticmethod("getDpiScalingValue")
        .def("getUserFavoritesDir", &EdCore::getUserFavoritesDir, DS.SARGS(10883)).staticmethod("getUserFavoritesDir")
        .def("hatchPalletteDialog", &EdCore::hatchPalletteDialog, DS.SARGS({ "pattern:str","custom : bool" })).staticmethod("hatchPalletteDialog")
        .def("invoke", &EdCore::invoke, DS.SARGS({ "resultBuffer: list" }, 11086)).staticmethod("invoke")
        .def("initDialog", &EdCore::initDialog, DS.SARGS({ "useDialog: bool" }, 10896)).staticmethod("initDialog")
        .def("isDragging", &EdCore::isDragging, DS.SARGS(11087)).staticmethod("isDragging")
        .def("isInBackgroundMode", &EdCore::isInBackgroundMode, DS.SARGS(11089)).staticmethod("isInBackgroundMode")
        .def("isInputPending", &EdCore::isInputPending, DS.SARGS(11090)).staticmethod("isInputPending")
        .def("isMenuGroupLoaded", &EdCore::isMenuGroupLoaded, DS.SARGS({ "mnu: str" }, 11091)).staticmethod("isMenuGroupLoaded")
        .def("isOsnapOverride", &EdCore::isOsnapOverride, DS.SARGS(11092)).staticmethod("isOsnapOverride")
        .def("isUpdateDisplayPaused", &EdCore::isUpdateDisplayPaused, DS.SARGS(11093)).staticmethod("isUpdateDisplayPaused")
        .def("isUsrbrkDisabled", &EdCore::isUsrbrkDisabled, DS.SARGS(11094)).staticmethod("isUsrbrkDisabled")
        .def("loadJSScript", &EdCore::loadJSScript, DS.SARGS({ "scr: str" })).staticmethod("loadJSScript")
        .def("loadPartialMenu", &EdCore::loadPartialMenu, DS.SARGS({ "mnu: str" }, 11219)).staticmethod("loadPartialMenu")
        .def("loadMainMenu", &EdCore::loadMainMenu, DS.SARGS({ "mnu: str" })).staticmethod("loadMainMenu")
        .def("menuCmd", &EdCore::menuCmd, DS.SARGS({ "cmd: str" })).staticmethod("menuCmd")
        .def("markForDelayXRefRelativePathResolve", &EdCore::markForDelayXRefRelativePathResolve, DS.SARGS({ "id: PyDb.ObjectId" }, 11221)).staticmethod("markForDelayXRefRelativePathResolve")
        .def("mSpace", &EdCore::mSpace, DS.SARGS(11223)).staticmethod("mSpace")
        .def("pSpace", &EdCore::pSpace, DS.SARGS(11234)).staticmethod("pSpace")
        .def("postCommand", &EdCore::postCommand, DS.SARGS({ "str: str" })).staticmethod("postCommand")
        .def("postCommandPrompt", &EdCore::postCommandPrompt, DS.SARGS(11232)).staticmethod("postCommandPrompt")
        .def("prompt", &EdCore::prompt, DS.SARGS({ "val: str" }, 11233)).staticmethod("prompt")
        .def("osnap", &EdCore::osnap, DS.SARGS({ "pt: PyGe.Point3d","mode: str" }, 11228)).staticmethod("osnap")
        .def("redraw", &EdCore::redraw, DS.SARGS({ "id: PyDb.ObjectId","mode: int" }, 11236)).staticmethod("redraw")
        .def("reloadMenus", &EdCore::reloadMenus, DS.SARGS({ "bIncrementalReloading: bool" }, 11248)).staticmethod("reloadMenus")
        .def("restoreCurrentView", &EdCore::restoreCurrentView, DS.SARGS({ "vid: PyDb.ObjectId" }, 11260)).staticmethod("restoreCurrentView")
        .def("restorePreviousUCS", &EdCore::restorePreviousUCS, DS.SARGS(11261)).staticmethod("restorePreviousUCS")
        .def("restoreStatusBar", &EdCore::restoreStatusBar, DS.SARGS(11262)).staticmethod("restoreStatusBar")
        .def("regen", &EdCore::regen, DS.SARGS()).staticmethod("regen")
        .def("sendModelessOperationEnded", &EdCore::sendModelessOperationEnded, DS.SARGS({ "ctx: str" }, 11300)).staticmethod("sendModelessOperationEnded")
        .def("sendModelessOperationStart", &EdCore::sendModelessOperationStart, DS.SARGS({ "ctx: str" }, 11301)).staticmethod("sendModelessOperationStart")
        .def("setColorDialog", &EdCore::setColorDialog, DS.SARGS({ "clr: int","bAllowMetaColor: bool","nCurLayerColor, int" }, 11308)).staticmethod("setColorDialog")
        .def("setColorDialogTrueColor", &EdCore::setColorDialogTrueColor1)
        .def("setColorDialogTrueColor", &EdCore::setColorDialogTrueColor2, DS.SARGS({ "clr: PyDb.AcCmColor","bAllowMetaColor: bool","nCurLayerColor: PyDb.AcCmColor","tab: int = 7" }, 11309)).staticmethod("setColorDialogTrueColor")
        .def("setColorPrompt", &EdCore::setColorPrompt, DS.SARGS({ "prompt: str","bAllowMetaColor: bool" }, 11311)).staticmethod("setColorPrompt")
        .def("getCurrentView", &EdCore::getCurrentView,DS.SARGS()).staticmethod("getCurrentView")
        .def("setCurrentView", &EdCore::setCurrentView1)
        .def("setCurrentView", &EdCore::setCurrentView2, DS.SARGS({ "vrec: PyDb.ViewTableRecord", "vp: PyDb.Viewport = ..." }, 11317)).staticmethod("setCurrentView")
        .def("setCurrentVPort", &EdCore::setCurrentVPort, DS.SARGS({ "vp: PyDb.Viewport" }, 11318)).staticmethod("setCurrentVPort")
        .def("setStatusBarProgressMeter", &EdCore::setStatusBarProgressMeter, DS.SARGS({ "lable: str", "nMinPos: int","nMaxPos: int" }, 11325)).staticmethod("setStatusBarProgressMeter")
        .def("setStatusBarProgressMeterPos", &EdCore::setStatusBarProgressMeterPos, DS.SARGS({ "pos: int" }, 11326)).staticmethod("setStatusBarProgressMeterPos")
        .def("setXrefResolvedWithUpdateStatus", &EdCore::setXrefResolvedWithUpdateStatus, DS.SARGS({ "rec: PyDb.BlockTableRecord" }, 11330)).staticmethod("setXrefResolvedWithUpdateStatus")
        .def("setUndoMark", &EdCore::setUndoMark, DS.SARGS({ "flag: bool" })).staticmethod("setUndoMark")
        .def("showHTMLModalWindow", &EdCore::showHTMLModalWindow1)
        .def("showHTMLModalWindow", &EdCore::showHTMLModalWindow2, DS.SARGS({ "hwnd: int","uriOfHtmlPage: str","persistSizeAndPosition: bool=True" }, 11334)).staticmethod("showHTMLModalWindow")
        .def("showHTMLModelessWindow", &EdCore::showHTMLModelessWindow1)
        .def("showHTMLModelessWindow", &EdCore::showHTMLModelessWindow2, DS.SARGS({ "hwnd: int","uriOfHtmlPage: str","persistSizeAndPosition: bool=True" }, 11335)).staticmethod("showHTMLModelessWindow")
        .def("skipXrefNotification", &EdCore::skipXrefNotification, DS.SARGS({ "db: PyDb.Database","name: str" }, 11336)).staticmethod("skipXrefNotification")
        .def("setFieldUpdateEnabled", &EdCore::setFieldUpdateEnabled, DS.SARGS({ "doc: PyAp.Document","enabled: bool" }, 11320)).staticmethod("setFieldUpdateEnabled")
        .def("setFunHelp", &EdCore::setFunHelp, DS.SARGS({ "functionName: str", "helpfile: str","topic: str","iCmd: int" }, 11321)).staticmethod("setFunHelp")
        .def("textBox", &EdCore::textBox, DS.SARGS({ "resultBuffer: list" }, 11461)).staticmethod("textBox")
        .def("textPage", &EdCore::textPage, DS.SARGS(11462)).staticmethod("textPage")
        .def("textScr", &EdCore::textScr, DS.SARGS(11463)).staticmethod("textScr")
        .def("trans", &EdCore::trans, DS.SARGS({ "pt: PyGe.Point3d", "rbFrom: tuple", "rbTo: tuple", "disp: bool" }, 11465)).staticmethod("trans")
        .def("unloadPartialMenu", &EdCore::unloadPartialMenu, DS.SARGS({ "mnu: str" }, 11471)).staticmethod("unloadPartialMenu")
        .def("unmarkForDelayXRefRelativePathResolve", &EdCore::unmarkForDelayXRefRelativePathResolve, DS.SARGS({ "id: PyDb.ObjectId" }, 11472)).staticmethod("unmarkForDelayXRefRelativePathResolve")
        .def("update", &EdCore::update, DS.SARGS({ "vport: int","pt1: PyGe.Point2d","pt2: PyGe.Point2d" }, 11475)).staticmethod("update")
        .def("updateDisplay", &EdCore::updateDisplay, DS.SARGS(11476)).staticmethod("updateDisplay")
        .def("updateDisplayPause", &EdCore::updateDisplayPause, DS.SARGS({ "val: bool" }, 11477)).staticmethod("updateDisplayPause")
        .def("usrBrk", &EdCore::usrBrk, DS.SARGS(11483)).staticmethod("usrBrk")
        .def("viewportIdFromNumber", &EdCore::viewportIdFromNumber, DS.SARGS({ "val: int" }, 11541)).staticmethod("viewportIdFromNumber")
        .def("vpLayer", &EdCore::vpLayer, DS.SARGS({ "id: PyDb.ObjectId","layerIds: list[PyDb.ObjectId]", "operation: PyDb.VpFreezeOps" }, 11542)).staticmethod("vpLayer")
        .def("vports", &EdCore::vports, DS.SARGS(11544)).staticmethod("vports")
        .def("vports2VportTableRecords", &EdCore::vports2VportTableRecords, DS.SARGS(11543)).staticmethod("vports2VportTableRecords")
        .def("vportTableRecords2Vports", &EdCore::vportTableRecords2Vports, DS.SARGS(11545)).staticmethod("vportTableRecords2Vports")
        .def("xrefAttach", &EdCore::xrefAttach1)
        .def("xrefAttach", &EdCore::xrefAttach2, DS.SOVRL(xrefAttachOverloads)).staticmethod("xrefAttach")
        .def("xrefCreateBlockname", &EdCore::xrefCreateBlockname, DS.SARGS({ "XrefPathname: str" })).staticmethod("xrefCreateBlockname")
        .def("xrefDetach", &EdCore::xrefDetach1)
        .def("xrefDetach", &EdCore::xrefDetach2, DS.SOVRL(xrefDetachOverloads)).staticmethod("xrefDetach")
        .def("xrefNotifyCheckFileChanged", &EdCore::xrefNotifyCheckFileChanged, DS.SARGS({ "id: PyDb.ObjectId" })).staticmethod("xrefNotifyCheckFileChanged")
        .def("xrefOverlay", &EdCore::xrefOverlay1)
        .def("xrefOverlay", &EdCore::xrefOverlay2, DS.SOVRL(xrefOverlayhOverloads)).staticmethod("xrefOverlay")
        .def("xrefReload", &EdCore::xrefReload1)
        .def("xrefReload", &EdCore::xrefReload2)
        .def("xrefReload", &EdCore::xrefReload3)
        .def("xrefReload", &EdCore::xrefReload4, DS.SOVRL(xrefReloadOverloads)).staticmethod("xrefReload")
        .def("xrefResolve", &EdCore::xrefResolve1)
        .def("xrefResolve", &EdCore::xrefResolve2, DS.SARGS({ "db: PyDb.Database", "bQuiet: bool=True" })).staticmethod("xrefResolve")
        .def("xrefUnload", &EdCore::xrefUnload1)
        .def("xrefUnload", &EdCore::xrefUnload2, DS.SOVRL(xrefUnloadOverloads)).staticmethod("xrefUnload")
        .def("xrefBind", &EdCore::xrefBind1)
        .def("xrefBind", &EdCore::xrefBind2, DS.SOVRL(xrefBindOverloads)).staticmethod("xrefBind")
        .def("xrefXBind", &EdCore::xrefXBind1)
        .def("xrefXBind", &EdCore::xrefXBind2, DS.SOVRL(xrefXBindOverloads)).staticmethod("xrefXBind")
        .def("exceptionTest", &EdCore::exceptionTest, DS.SARGS()).staticmethod("exceptionTest")
        .def("addSupplementalCursorImage", &EdCore::addSupplementalCursorImage1)
        .def("addSupplementalCursorImage", &EdCore::addSupplementalCursorImage2, DS.SARGS({ "image: wx.Image", "order: int = 0", "alpha: int = 255" })).staticmethod("addSupplementalCursorImage")
        .def("removeSupplementalCursorImage", &EdCore::removeSupplementalCursorImage, DS.SARGS()).staticmethod("removeSupplementalCursorImage")
        .def("hasSupplementalCursorImage", &EdCore::hasSupplementalCursorImage, DS.SARGS()).staticmethod("hasSupplementalCursorImage")
        .def("getSupplementalCursorOffset", &EdCore::getSupplementalCursorOffset, DS.SARGS()).staticmethod("getSupplementalCursorOffset")
        .def("setSupplementalCursorOffset", &EdCore::setSupplementalCursorOffset, DS.SARGS({ "x:int", "y:int" })).staticmethod("setSupplementalCursorOffset")
        .def("curDwgXrefGraph", &EdCore::curDwgXrefGraph, DS.SARGS()).staticmethod("curDwgXrefGraph")
        ;
}

bool EdCore::addSupplementalCursorImage1(const boost::python::object& image)
{
    return addSupplementalCursorImage2(image, 0, 255);
}

bool EdCore::addSupplementalCursorImage2(const boost::python::object& image, int order, Adesk::UInt8 alpha)
{
#if defined(_ARXTARGET)
    wxImage* pimage = nullptr;// we are NOT the owner!
    if (!wxPyConvertWrappedPtr(image.ptr(), (void**)&pimage, wxT("wxImage")))
        return false;
    if (!pimage->IsOk())
        return false;
    removeSupplementalCursorImage();
    const auto imageHandle = DocVars.docData().createCursorImage(*pimage, alpha);
    return acedAddSupplementalCursorImage(imageHandle, order);
#else
    return false;
#endif
}

bool EdCore::removeSupplementalCursorImage()
{
#if defined(_ARXTARGET)
    if (DocVars.docData().getCursorImage() != nullptr)
    {
        bool flag = acedRemoveSupplementalCursorImage(DocVars.docData().getCursorImage());
        DocVars.docData().clearCursorImage();
        return flag;
    }
    return false;
#else
    return false;
#endif
}

bool EdCore::hasSupplementalCursorImage()
{
#if defined(_ARXTARGET)
    return acedHasSupplementalCursorImage();
#else
    return false;
#endif
}

void EdCore::setSupplementalCursorOffset(int x, int y)
{
#if defined(_ARXTARGET)
    acedSetSupplementalCursorOffset(x, y);
#endif
}

boost::python::tuple EdCore::getSupplementalCursorOffset()
{
    int x = 0;
    int y = 0;
#if defined(_ARXTARGET)
    acedGetSupplementalCursorOffset(x, y);
#endif
    PyAutoLockGIL lock;
    return boost::python::make_tuple(x, y);
}

ULONG_PTR EdCore::getAcadDockCmdLine()
{
    return reinterpret_cast<UINT_PTR>(acedGetAcadDockCmdLine()->GetSafeHwnd());
}

ULONG_PTR EdCore::getAcadTextCmdLine()
{
    return reinterpret_cast<UINT_PTR>(acedGetAcadTextCmdLine()->GetSafeHwnd());
}

int EdCore::alert(const std::string& msg)
{
    return acedAlert(utf8_to_wstr(msg).c_str());
}

int EdCore::arxLoad(const std::string& path)
{
    return acedArxLoad(utf8_to_wstr(path).c_str());
}

boost::python::list EdCore::arxLoaded()
{
    PyAutoLockGIL lock;
    AcResBufPtr pLoaded(acedArxLoaded());
    return resbufToList(pLoaded.get());
}

int EdCore::arxUnload(const std::string& app)
{
    return acedArxUnload(utf8_to_wstr(app).c_str());
}

void EdCore::audit1(PyDbDatabase& pDb, bool bFixErrors)
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(acedAudit(pDb.impObj(), bFixErrors));
#endif
}

void EdCore::audit2(PyDbDatabase& pDb, bool bFixErrors, bool bCmdLnEcho)
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(acedAudit(pDb.impObj(), bFixErrors, bCmdLnEcho));
#endif
}

void EdCore::callBackOnCancel()
{
    acedCallBackOnCancel();
}

bool EdCore::clearOLELock(int handle)
{
    return acedClearOLELock(handle);
}

std::string EdCore::clipFormatName()
{
#if defined(_GRXTARGET) && (_GRXTARGET <= 260)
    throw PyNotimplementedByHost();
#else
    return wstr_to_utf8(acedClipFormatName());
#endif
}

bool EdCore::cmdCWasCancelled()
{
    return acedCmdCWasCancelled();
}

int EdCore::cmdUndefine(const std::string& name, int undefIt)
{
    return acedCmdUndefine(utf8_to_wstr(name).c_str(), undefIt);
}

boost::python::dict EdCore::getCommands()
{
    PyAutoLockGIL lock;
    boost::python::dict Pydict;
    std::map<std::string, boost::python::list> pyMap;
    std::unique_ptr<AcEdCommandIterator>iter(acedRegCmds->iterator());
    if (iter == nullptr)
        return Pydict;
    //AutoCAD has duplicates in the iterator?
    std::unordered_set<const AcEdCommand*> cmdSet;
    for (; !iter->done(); iter->next())
    {
        const auto cmd = iter->command();
        if (cmdSet.contains(cmd))
            continue;
        cmdSet.insert(cmd);
        const auto& groupname = wstr_to_utf8(iter->commandGroup());
        const auto& globalname = wstr_to_utf8(cmd->globalName());
        const auto& localname = wstr_to_utf8(cmd->localName());
        pyMap[groupname].append(boost::python::make_tuple(globalname, localname, cmd->commandFlags()));
    }
    for (auto& item : pyMap)
    {
        Pydict[item.first] = item.second;
    }
    return Pydict;
}

boost::python::tuple EdCore::calcTextExtents(const std::string& strval, const PyDbObjectId& textStyle)
{
    AcGiTextStyle iStyle;
    PyThrowBadEs(fromAcDbTextStyle(iStyle, textStyle.m_id));
    const std::wstring wstrval = utf8_to_wstr(strval);
    auto pnt = iStyle.extents(wstrval.c_str(), Adesk::kFalse, wstrval.size(), Adesk::kTrue);
    PyAutoLockGIL lock;
    return boost::python::make_tuple(pnt.x, pnt.y);
}

void EdCore::convertEntityToHatch(const PyDbHatch& hatch, const PyDbEntity& entity, bool transferId)
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    AcDbEntity* pEnt = entity.impObj();
    PyThrowBadEs(acedConvertEntityToHatch(hatch.impObj(), pEnt, transferId));
#endif
}

AcGePoint3d EdCore::coordFromPixelToWorld1(const boost::python::tuple& tin)
{
    PyAutoLockGIL lock;
    const size_t listSize = boost::python::len(tin);
    if (listSize != 2)
        PyThrowBadEs(eInvalidInput);

    int x = extract<int>(tin[0]);
    int y = extract<int>(tin[1]);

    AcGePoint3d pnt;

    CPoint cpnt(x, y);
    acedCoordFromPixelToWorld(cpnt, asDblArray(pnt));
    return pnt;
}

AcGePoint3d EdCore::coordFromPixelToWorld2(int windnum, const boost::python::tuple& tin)
{
    PyAutoLockGIL lock;
    const size_t listSize = boost::python::len(tin);
    if (listSize != 2)
        PyThrowBadEs(eInvalidInput);
    int x = extract<int>(tin[0]);
    int y = extract<int>(tin[1]);
    CPoint cpnt(x, y);
    AcGePoint3d pnt;
    if (acedCoordFromPixelToWorld(windnum, cpnt, asDblArray(pnt)) == false)
        PyThrowBadEs(eInvalidInput);
    return pnt;
}

boost::python::tuple EdCore::coordFromWorldToPixel(int windnum, const AcGePoint3d& pnt)
{
    CPoint cpnt;
    if (acedCoordFromWorldToPixel(windnum, asDblArray(pnt), cpnt) == false)
        PyThrowBadEs(eInvalidInput);
    PyAutoLockGIL lock;
    return boost::python::make_tuple(cpnt.x, cpnt.y);
}

bool EdCore::createInternetShortcut(const std::string& szURL, const std::string& szShortcutPath)
{
#if defined(_ZRXTARGET240) || defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return acedCreateInternetShortcut(utf8_to_wstr(szURL).c_str(), utf8_to_wstr(szShortcutPath).c_str());
#endif
}

PyDbObjectId EdCore::createViewportByView(PyDbDatabase& db, PyDbObjectId& view, const AcGePoint2d& location, double scale)
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    PyDbObjectId id;
    PyThrowBadEs(acedCreateViewportByView(db.impObj(), view.m_id, location, scale, id.m_id));
    return id;
#endif
}

int EdCore::defun(const std::string& pszName, int nFuncNum)
{
    return acedDefun(utf8_to_wstr(pszName).c_str(), nFuncNum);
}

int EdCore::defunEx(const std::string& pszGlobalName, const std::string& pszLocalName, int nFuncNum)
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return acedDefunEx(utf8_to_wstr(pszGlobalName).c_str(), utf8_to_wstr(pszLocalName).c_str(), nFuncNum);
#endif
}

void EdCore::disableDefaultARXExceptionHandler(bool flag)
{
    acedDisableDefaultARXExceptionHandler(flag);
}

void EdCore::disableUsrbrk()
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    acedDisableUsrbrk();
#endif
}

bool EdCore::displayBorder(bool flag)
{
#if defined(_BRXTARGET250) || defined(_GRXTARGET250) || defined(_ZRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return acedDisplayBorder(flag);
#endif
}

bool EdCore::drawingStatusBarsVisible()
{
    return acedDrawingStatusBarsVisible();
}

void EdCore::drawOrderInherit(PyDbObjectId& parent, const boost::python::list& childArray, AcEdDrawOrderCmdType cmd)
{
    auto ids = PyListToObjectIdArray(childArray);
    PyThrowBadEs(acedDrawOrderInherit(parent.m_id, ids, cmd));
}

void EdCore::dropOpenFile(const std::string& value)
{
#if defined(_BRXTARGET250) || defined(_GRXTARGET260) || defined(_ZRXTARGET260)
    throw PyNotimplementedByHost();
#else
    acedDropOpenFile(utf8_to_wstr(value).c_str());
#endif
}

int EdCore::eatCommandThroat()
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return acedEatCommandThroat();
#endif
}

int EdCore::editMTextInteractive(PyDbMText& mtext, bool useNewUI, bool allowTabs)
{
    return acedEditMTextInteractive(mtext.impObj(), useNewUI, allowTabs);
}

void EdCore::enableUsrbrk()
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return acedEnableUsrbrk();
#endif
}

boost::python::list EdCore::evaluateLisp(const std::string& str)
{
    int np = 0;
    for (const auto item : str)
    {
        switch (item)
        {
            case '(':
                np++;
                break;
            case ')':
                np--;
                break;
            default:
                break;
        }
    }
    if (np != 0)
    {
        PyThrowBadEs(eInvalidInput);
    }
    resbuf* pRb = nullptr;
#ifdef _ZRXTARGET 
    zcedEvaluateLisp(utf8_to_wstr(str).c_str(), pRb);
#endif
#ifdef _GRXTARGET 
    gcedEvaluateLisp(utf8_to_wstr(str).c_str(), pRb);
#endif
#ifdef _BRXTARGET 
    acedEvaluateLisp(utf8_to_wstr(str).c_str(), pRb);
#endif
#ifdef _ARXTARGET 
    acedEvaluateLisp(utf8_to_wstr(str).c_str(), pRb);
#endif
    AcResBufPtr pSafeRb(pRb);
    return resbufToList(pRb);
}

std::string EdCore::evaluateDiesel(const std::string& str)
{
#ifdef _ARXTARGET 
    std::wstring data(256, 0);
    acedEvaluateDiesel(utf8_to_wstr(str).c_str(), data.data(), data.size());
    return wstr_to_utf8(data.c_str());
#else
    throw PyNotimplementedByHost();
#endif
}

bool EdCore::cmdS1(const std::string& name)
{

#ifdef _ZRXTARGET260
    PyRxApp::instance().commandForDocOverride = utf8_to_wstr(name).c_str();
#endif
    AcResBufPtr pcmd(acutBuildList(RTSTR, utf8_to_wstr(name).c_str(), RTNONE));
    return acedCmdS(pcmd.get()) == RTNORM;
}

bool EdCore::cmdS2(const boost::python::list& lst)
{
#ifdef _ZRXTARGET260
    if (boost::python::len(lst) != 0 && boost::python::len(lst[0]) != 0)
        PyRxApp::instance().commandForDocOverride = utf8_to_wstr(extract<char*>(lst[0][1])).c_str();
#endif
    AcResBufPtr pcmd(listToResbuf(lst));
    return acedCmdS(pcmd.get()) == RTNORM;
}

std::string EdCore::findFile(const std::string& file)
{
    std::wstring data(MAX_PATH, 0);
    acedFindFile(utf8_to_wstr(file).c_str(), data.data(), data.size());
    return wstr_to_utf8(data.c_str());
}

std::string EdCore::findTrustedFile(const std::string& file)
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    std::wstring data(MAX_PATH, 0);
    acedFindTrustedFile(utf8_to_wstr(file).c_str(), data.data(), data.size());
    return wstr_to_utf8(data.c_str());
#endif
}

boost::python::list EdCore::getPredefinedPattens()
{
#if defined(_BRXTARGET250) || defined(_GRXTARGET260) || defined(_ZRXTARGET260)
    throw PyNotimplementedByHost();
#else
    PyAutoLockGIL lock;
    AcStringArray patterns;
    boost::python::list py_patterns;
    if (acedGetPredefinedPattens(patterns) == true)
    {
        for (auto& pattern : patterns)
            py_patterns.append(wstr_to_utf8(pattern));
    }
    return py_patterns;
#endif
}

std::string EdCore::getFileD(const std::string& title, const std::string& defawlt, const std::string& ext, int flags)
{
    std::string path;
    AcResBufPtr result(acutNewRb(RTSTR));
    if (acedGetFileD(utf8_to_wstr(title).c_str(), utf8_to_wstr(defawlt).c_str(), utf8_to_wstr(ext).c_str(), flags, result.get()) == RTNORM)
        path = wstr_to_utf8(result->resval.rstring);
    return path;
}

boost::python::list EdCore::getFileNavDialog(const std::string& title, const std::string& defawlt, const std::string& ext, const std::string& dlgname, int flags)
{
    PyAutoLockGIL lock;
    resbuf* result = nullptr;
    boost::python::list pyList;
    if (acedGetFileNavDialog(utf8_to_wstr(title).c_str(), utf8_to_wstr(defawlt).c_str(), utf8_to_wstr(ext).c_str(), utf8_to_wstr(dlgname).c_str(), flags, &result) == RTNORM)
    {
        AcResBufPtr resultptr(result);
        for (resbuf* pbuf = result; pbuf != nullptr; pbuf = pbuf->rbnext)
        {
            if (pbuf->restype == RTSTR)
                pyList.append(wstr_to_utf8(pbuf->resval.rstring));
        }
    }
    return pyList;
}

std::string EdCore::getCommandPromptString()
{
#if defined(_BRXTARGET250) || defined(_GRXTARGET260) || defined(_ZRXTARGET260)
    throw PyNotimplementedByHost();
#else
    CString str;
    acedGetCommandPromptString(str);
    return wstr_to_utf8(str);
#endif

}

boost::python::list EdCore::getLastCommandLines(int lineCount, bool ignoreNull)
{
#if defined(_BRXTARGET250) || defined(_GRXTARGET260) || defined(_ZRXTARGET260)
    throw PyNotimplementedByHost();
#else
    AcStringArray strs;
    acedGetLastCommandLines(strs, lineCount, ignoreNull);
    return AcStringArrayToPyList(strs);
#endif
}

unsigned int EdCore::getBlockEditMode()
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return acedGetBlockEditMode();
#endif
}

std::string EdCore::getCommandForDocument(const PyApDocument& doc)
{
    AcString cmd;
    PyThrowBadEs(acedGetCommandForDocument(doc.impObj(), cmd));
    return wstr_to_utf8(cmd);
}

boost::python::list EdCore::getCurrentSelectionSet()
{
    AcDbObjectIdArray sset;
    PyThrowBadEs(acedGetCurrentSelectionSet(sset));
    return ObjectIdArrayToPyList(sset);
}

boost::python::tuple EdCore::getCurVportPixelToDisplay()
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    PyAutoLockGIL lock;
    double xFactor = 0;
    double yFactor = 0;
    acedGetCurVportPixelToDisplay(xFactor, yFactor);
    return boost::python::make_tuple(xFactor, yFactor);
#endif
}

boost::python::tuple EdCore::getCurVportScreenToDisplay()
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    PyAutoLockGIL lock;
    double xFactor = 0;
    double yFactor = 0;
    acedGetCurVportScreenToDisplay(xFactor, yFactor);
    return boost::python::make_tuple(xFactor, yFactor);
#endif
}

float EdCore::getDpiScalingValue()
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return acedGetDpiScalingValue();
#endif
}

std::string EdCore::getUserFavoritesDir()
{
#if defined(_BRXTARGET250) || defined(_GRXTARGET260) || defined(_ZRXTARGET260)
    throw PyNotimplementedByHost();
#endif
#ifdef _ARXTARGET
#if defined(_ARXTARGET) && (_ARXTARGET >= 242)
    AcString sFavoritesDir;
    acedGetUserFavoritesDir(sFavoritesDir);
    return wstr_to_utf8(sFavoritesDir);
#else
    RxAutoOutStr buff;
    acedGetUserFavoritesDir(buff.buf);
    return buff.str();
#endif
#endif
}

std::string EdCore::getEnv(const std::string& env)
{
#if defined(_ARXTARGET) && (_ARXTARGET >= 242)
    AcString val;
    PyThrowBadRt(acedGetEnv(utf8_to_wstr(env).c_str(), val));
    return wstr_to_utf8(val);
#else
    std::wstring buff(8096, 0);
    PyThrowBadRt(acedGetEnv(utf8_to_wstr(env).c_str(), buff.data(), buff.size()));
    return wstr_to_utf8(buff.c_str());
#endif
}

void EdCore::setEnv(const std::string& sym, const std::string& val)
{
    PyThrowBadRt(acedSetEnv(utf8_to_wstr(sym).c_str(), utf8_to_wstr(val).c_str()));
}

std::string EdCore::getCfg(const std::string& str)
{
    std::wstring buff(2048, 0);
    PyThrowBadRt(acedGetCfg(utf8_to_wstr(str).c_str(), buff.data(), buff.size()));
    return wstr_to_utf8(buff.c_str());
}

void EdCore::setCfg(const std::string& sym, const std::string& val)
{
    PyThrowBadRt(acedSetCfg(utf8_to_wstr(sym).c_str(), utf8_to_wstr(val).c_str()));
}

boost::python::list EdCore::getSym(const std::string& symname)
{
    PyAutoLockGIL lock;
    resbuf* rb = nullptr;
    acedGetSym(utf8_to_wstr(symname).c_str(), &rb);
    AcResBufPtr holder(rb);
    return resbufToList(rb);
}

bool EdCore::putSym(const std::string& symname, boost::python::list& buf)
{
    AcResBufPtr ptr(listToResbuf(buf));
    return acedPutSym(utf8_to_wstr(symname).c_str(), ptr.get()) == RTNORM;
}

int EdCore::getWinNum(int ptx, int pty)
{
    return acedGetWinNum(ptx, pty);
}

boost::python::tuple EdCore::getRGB(int idx)
{
#if defined (_ZRXTARGET250) || defined (_GRXTARGET250)
    throw PyNotimplementedByHost();
#else
    PyAutoLockGIL lock;
    auto clr = AcCmColor();
    if (clr.setCOLORREF(acedGetRGB(idx)) == eOk)
        return boost::python::make_tuple(clr.red(), clr.green(), clr.blue());
    return boost::python::make_tuple(-1, -1, -1);
#endif
}

void EdCore::graphScr()
{
    PyThrowBadRt(acedGraphScr());
}

Adesk::Boolean EdCore::initDialog(Adesk::Boolean useDialog)
{
    return acedInitDialog(useDialog);
}

int EdCore::isDragging()
{
    return acedIsDragging();
}

bool EdCore::isInBackgroundMode()
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return acedIsInBackgroundMode();
#endif
}

bool EdCore::isInputPending()
{
    return acedIsInputPending();
}

Adesk::Boolean EdCore::isMenuGroupLoaded(const std::string& mnu)
{
    return acedIsMenuGroupLoaded(utf8_to_wstr(mnu).c_str());
}

bool EdCore::isOsnapOverride()
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return acedIsOsnapOverride();
#endif
}

bool EdCore::isUpdateDisplayPaused()
{
    return acedIsUpdateDisplayPaused();
}

bool EdCore::isUsrbrkDisabled()
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return acedIsUsrbrkDisabled();
#endif
}

void EdCore::loadJSScript(const std::string& pUriOfJSFile)
{
#if defined(_BRXTARGET250) || defined(_GRXTARGET260) || defined(_ZRXTARGET260)
    throw PyNotimplementedByHost();
#else
    acedLoadJSScript(utf8_to_wstr(pUriOfJSFile).c_str());
#endif
}

bool EdCore::loadPartialMenu(const std::string& mnu)
{
    return acedLoadPartialMenu(utf8_to_wstr(mnu).c_str());
}

bool EdCore::loadMainMenu(const std::string& mnu)
{
#if defined(_BRXTARGET250) || defined(_GRXTARGET260) || defined(_ZRXTARGET260)
    throw PyNotimplementedByHost();
#else
    return acedLoadMainMenu(utf8_to_wstr(mnu).c_str());
#endif
}

void EdCore::markForDelayXRefRelativePathResolve(const PyDbObjectId& id)
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    acedMarkForDelayXRefRelativePathResolve(id.m_id);
#endif
}

int EdCore::menuCmd(const std::string& mnu)
{
    return acedMenuCmd(utf8_to_wstr(mnu).c_str());
}

boost::python::list EdCore::invoke(const boost::python::list& SARGS)
{
    PyAutoLockGIL lock;
    AcResBufPtr pArgs(listToResbuf(SARGS));
    resbuf* pResult = nullptr;
    acedInvoke(pArgs.get(), &pResult);
    AcResBufPtr pResultPtr(pResult);
    return resbufToList(pResult);
}

boost::python::dict EdCore::getSysVars()
{
#if defined(_GRXTARGET250) || defined(_ZRXTARGET260)
    throw PyNotimplementedByHost();
#else
    PyAutoLockGIL lock;
    boost::python::dict pydict;

    for (std::unique_ptr<AcEdSysVarIterator> vars(new AcEdSysVarIterator()); !vars->done(); vars->step())
    {
        resbuf buf{};
        buf.restype = 0;
        buf.resval.rint = 0;
        const AcRxVariable* var = vars->getSysVar();
        if (var == nullptr)
            continue;
        const std::string utf8Name = wstr_to_utf8(var->name());

        if (auto es = acedGetVar(var->name(), &buf); es != RTNORM)
        {
            pydict[utf8Name] = boost::python::object();
            continue;
        }
        switch (buf.restype)
        {
            case RTSTR:
            {
                pydict[utf8Name] = wstr_to_utf8(buf.resval.rstring);
                acutDelString(buf.resval.rstring);
                break;
            }
            case RTSHORT:
            {
                pydict[utf8Name] = buf.resval.rint;
                break;
            }
            case RTLONG:
            {
                pydict[utf8Name] = buf.resval.rlong;
                break;
            }
            case RTREAL:
            {
                pydict[utf8Name] = buf.resval.rreal;
                break;
            }
            case RTPOINT:
            case RT3DPOINT:
            {
                pydict[utf8Name] = asPnt3d(buf.resval.rpoint);
                break;
            }
        }
    }
    return pydict;
#endif
}

boost::python::object EdCore::getVar(const std::string& sym)
{
    PyAutoLockGIL lock;
    try
    {
        resbuf buf;
        if (acedGetVar(utf8_to_wstr(sym).c_str(), &buf) != RTNORM)
        {
            PyThrowBadRt(RTERROR);
        }
        switch (buf.restype)
        {
            case RTSHORT:
            {
                return boost::python::object(buf.resval.rint);
            }
            case RTLONG:
            {
                return boost::python::object(buf.resval.rlong);
            }
            case RTREAL:
            {
                return boost::python::object(buf.resval.rreal);
            }
            case RTSTR:
            {
                std::string val = wstr_to_utf8(buf.resval.rstring);
                acutDelString(buf.resval.rstring);
                return boost::python::object(val);
            }
            case RTPOINT:
            {
                AcGePoint2d pnt = asPnt2d(buf.resval.rpoint);
                return boost::python::object(pnt);
            }
            case RT3DPOINT:
            {
                AcGePoint3d pnt = asPnt3d(buf.resval.rpoint);
                return boost::python::object(pnt);
            }
            default:
            {
                return boost::python::object();
            }
        }
    }
    catch (...)
    {
        acutPrintf(_T("\nExeption @ %ls"), __FUNCTIONW__);
    }
    return boost::python::object();
}

bool EdCore::setVar(const std::string& sym, const boost::python::object& src)
{
    PyAutoLockGIL lock;
    try
    {
        AcResBufPtr buf;
        const AcString asSym = utf8_to_wstr(sym).c_str();
        if (PyLong_Check(src.ptr()))
        {
            const int val = extract<int32_t>(src);
            if (val <= SHRT_MAX)
                buf.reset(acutBuildList(RTSHORT, val, 0));
            else
                buf.reset(acutBuildList(RTLONG, val, 0));
        }
        else if (PyFloat_Check(src.ptr()))
        {
            const double val = extract<double>(src);
            buf.reset(acutBuildList(RTREAL, val, 0));
        }
        else if (extract<AcGePoint2d>(src).check())
        {
            const auto val = asDblArray(extract<AcGePoint2d>(src));
            buf.reset(acutBuildList(RTPOINT, val, 0));
        }
        else if (extract<AcGePoint3d>(src).check())
        {
            const auto val = asDblArray(extract<AcGePoint3d>(src));
            buf.reset(acutBuildList(RT3DPOINT, val, 0));
        }
        else if (extract<char*>(src).check())
        {
            const AcString str = utf8_to_wstr(extract<char*>(src)).c_str();
            buf.reset(acutBuildList(RTSTR, (const TCHAR*)str, 0));
        }
        PyThrowBadRt(acedSetVar(asSym, buf.get()));
        return true;
    }
    catch (...)
    {
        acutPrintf(_T("\nExeption @ %ls"), __FUNCTIONW__);
    }
    return false;
}

PySysVar EdCore::autoSetVar(const std::string& sym, const boost::python::object& val)
{
    return PySysVar(sym, val);
}

void EdCore::mSpace()
{
    return PyThrowBadEs(acedMspace());
}

void EdCore::pSpace()
{
    return PyThrowBadEs(acedPspace());
}

void EdCore::postCommand(const std::string& str)
{
#if _ZRXTARGET == 240
    throw PyNotimplementedByHost();
#endif
#if _GRXTARGET == 240 
    gcedPostCommand(utf8_to_wstr(str).c_str());
#endif
#if defined(_ARXTARGET) || defined(_BRXTARGET) 
    acedPostCommand(utf8_to_wstr(str).c_str());
#endif
}

void EdCore::postCommandPrompt()
{
    acedPostCommandPrompt();
}

int EdCore::prompt(const std::string& str)
{
    return acedPrompt(utf8_to_wstr(str).c_str());
}

int EdCore::redraw(const PyDbObjectId& ent, int mode)
{
    ads_name adsn = { 0L };
    acdbGetAdsName(adsn, ent.m_id);
    return acedRedraw(adsn, mode);
}

void EdCore::reloadMenus(bool bIncrementalReloading)
{
    acedReloadMenus(bIncrementalReloading);
}

void EdCore::restoreCurrentView(const PyDbObjectId& namedViewId)
{
    PyThrowBadEs(acedRestoreCurrentView(namedViewId.m_id));
}

void EdCore::restorePreviousUCS()
{
    PyThrowBadEs(acedRestorePreviousUCS());
}

void EdCore::restoreStatusBar()
{
    acedRestoreStatusBar();
}

void EdCore::regen()
{
    ads_regen();
}

void EdCore::sendModelessOperationEnded(const std::string& strContext)
{
    acedSendModelessOperationEnded(utf8_to_wstr(strContext).c_str());
}

void EdCore::sendModelessOperationStart(const std::string& strContext)
{
    acedSendModelessOperationStart(utf8_to_wstr(strContext).c_str());
}

boost::python::tuple EdCore::setColorDialog(int color, Adesk::Boolean bAllowMetaColor, int nCurLayerColor)
{
    PyAutoLockGIL lock;
    int _color = color;
    auto flag = acedSetColorDialog(_color, bAllowMetaColor, nCurLayerColor);
    return boost::python::make_tuple(flag, _color);
}

boost::python::tuple EdCore::setColorDialogTrueColor1(const AcCmColor& color, Adesk::Boolean bAllowMetaColor, const AcCmColor& nCurLayerColor)
{
    PyAutoLockGIL lock;
    AcCmColor _color = color;
    auto flag = acedSetColorDialogTrueColor(_color, bAllowMetaColor, nCurLayerColor);
    return boost::python::make_tuple(flag, _color);
}

boost::python::tuple EdCore::setColorDialogTrueColor2(const AcCmColor& color, Adesk::Boolean bAllowMetaColor, const AcCmColor& nCurLayerColor, AcCm::DialogTabs tab)
{
    PyAutoLockGIL lock;
    AcCmColor _color = color;
    auto flag = acedSetColorDialogTrueColor(_color, bAllowMetaColor, nCurLayerColor, tab);
    return boost::python::make_tuple(flag, _color);
}

int EdCore::grDraw1(const AcGePoint2d& from, const AcGePoint2d& to, int colorIndex, int highlight)
{
    return acedGrDraw(asDblArray(from), asDblArray(to), colorIndex, highlight);
}

int EdCore::grDraw2(const AcGePoint3d& from, const AcGePoint3d& to, int colorIndex, int highlight)
{
    return acedGrDraw(asDblArray(from), asDblArray(to), colorIndex, highlight);
}

int EdCore::grDrawArc(const AcGePoint3d& p1, const AcGePoint3d& p2, const AcGePoint3d& p3, int nsegs, int colorIndex)
{
    AcGeCircArc3d carc{ p1, p2, p3 };
    AcGePoint3dArray pnts;
    carc.getSamplePoints(nsegs, pnts);
    AcResBufPtr rb(acutNewRb(RTSHORT));
    rb->resval.rint = colorIndex;
    resbuf* rbTail = rb.get();
    constexpr const size_t copysize = sizeof(ads_point);
    for (size_t idx = 1; idx < pnts.length(); idx++)//duplicate code
    {
        rbTail = rbTail->rbnext = acutNewRb(RT3DPOINT);
        memcpy_s(rbTail->resval.rpoint, copysize, asDblArray(pnts[idx - 1]), copysize);
        rbTail = rbTail->rbnext = acutNewRb(RT3DPOINT);
        memcpy_s(rbTail->resval.rpoint, copysize, asDblArray(pnts[idx]), copysize);
    }
    return acedGrVecs(rb.get(), NULL);
}

int EdCore::grDrawBox(const boost::python::object& iterable, int colorIndex, int highlight)
{
    AcGePoint3dArray pnts = PyListToPoint3dArray(iterable);
    if (pnts.length() != 4)
        return RTERROR;

    AcDbExtents ex;
    for (const auto& pnt : pnts)
        ex.addPoint(pnt);

    pnts.remove(ex.minPoint());
    pnts.remove(ex.maxPoint());

    auto va = pnts[0] - ex.minPoint();
    auto vb = pnts[1] - ex.minPoint();

    auto sp = ex.minPoint();
    auto np = sp + va;
    grDraw2(sp, np, colorIndex, highlight);

    sp = np;
    np = sp + vb;
    grDraw2(sp, np, colorIndex, highlight);

    sp = np;
    np = sp - va;
    grDraw2(sp, np, colorIndex, highlight);

    sp = np;
    np = ex.minPoint();
    grDraw2(sp, np, colorIndex, highlight);

    return RTNORM;
}

int EdCore::grDrawCircle(const AcGePoint3d& cen, double radius, int nsegs, int colorIndex)
{
    AcGeVector3d vec;
    ::ucsNormalVector(vec);
    AcGeCircArc3d carc{ cen, vec, radius };
    AcGePoint3dArray pnts;
    carc.getSamplePoints(nsegs, pnts);
    pnts.append(pnts.first());
    AcResBufPtr rb(acutNewRb(RTSHORT));
    rb->resval.rint = colorIndex;
    resbuf* rbTail = rb.get();
    constexpr const size_t copysize = sizeof(ads_point);
    for (size_t idx = 1; idx < pnts.length(); idx++)
    {
        rbTail = rbTail->rbnext = acutNewRb(RT3DPOINT);
        memcpy_s(rbTail->resval.rpoint, copysize, asDblArray(pnts[idx - 1]), copysize);
        rbTail = rbTail->rbnext = acutNewRb(RT3DPOINT);
        memcpy_s(rbTail->resval.rpoint, copysize, asDblArray(pnts[idx]), copysize);
    }
    return acedGrVecs(rb.get(), NULL);
}

int EdCore::grDrawPoly2d(const boost::python::object& iterable, int colorIndex)
{
    AcGePoint2dArray pnts = PyListToPoint2dArray(iterable);
    if (pnts.length() < 2)
        return RTERROR;
    AcResBufPtr rb(acutNewRb(RTSHORT));
    rb->resval.rint = colorIndex;
    resbuf* rbTail = rb.get();
    constexpr const size_t copysize = sizeof(ads_point);
    for (size_t idx = 1; idx < pnts.length(); idx++)
    {
        rbTail = rbTail->rbnext = acutNewRb(RTPOINT);
        memcpy_s(rbTail->resval.rpoint, copysize, asDblArray(pnts[idx - 1]), copysize);
        rbTail = rbTail->rbnext = acutNewRb(RTPOINT);
        memcpy_s(rbTail->resval.rpoint, copysize, asDblArray(pnts[idx]), copysize);
    }
    return acedGrVecs(rb.get(), NULL);
}

int EdCore::grDrawPoly3d(const boost::python::object& iterable, int colorIndex)
{
    AcGePoint3dArray pnts = PyListToPoint3dArray(iterable);
    if (pnts.length() < 2)
        return RTERROR;
    AcResBufPtr rb(acutNewRb(RTSHORT));
    rb->resval.rint = colorIndex;
    resbuf* rbTail = rb.get();
    constexpr const size_t copysize = sizeof(ads_point);
    for (size_t idx = 1; idx < pnts.length(); idx++)
    {
        rbTail = rbTail->rbnext = acutNewRb(RT3DPOINT);
        memcpy_s(rbTail->resval.rpoint, copysize, asDblArray(pnts[idx - 1]), copysize);
        rbTail = rbTail->rbnext = acutNewRb(RT3DPOINT);
        memcpy_s(rbTail->resval.rpoint, copysize, asDblArray(pnts[idx]), copysize);
    }
    return acedGrVecs(rb.get(), NULL);
}

int EdCore::grVecs(const boost::python::list& iterable, const AcGeMatrix3d& mat)
{
    AcResBufPtr rb(listToResbuf(iterable));
    ads_matrix adsmat = { { 0 } };
    memcpy_s(adsmat, sizeof(ads_matrix), mat.entry, sizeof(ads_matrix));
    return acedGrVecs(rb.get(), adsmat);
}

int EdCore::grText(int box, const std::string& text, int hl)
{
    return acedGrText(box, utf8_to_wstr(text).c_str(), hl);
}

AcGePoint3d EdCore::getMousePositionUCS()
{
    CPoint cursorPos;
    ::GetCursorPos(&cursorPos);
    ::ScreenToClient(adsw_acadDocWnd(), &cursorPos);

    acedDwgPoint cpt;
    acedCoordFromPixelToWorld(cursorPos, cpt);

    resbuf fromrb{};
    fromrb.restype = RTSHORT;
    fromrb.resval.rint = 2; // DCS

    resbuf torb{};
    torb.restype = RTSHORT;
    torb.resval.rint = 1; // UCS 

    AcGePoint3d hitPoint;
    acedTrans(cpt, &fromrb, &torb, FALSE, asDblArray(hitPoint));
    return hitPoint;
}

AcGePoint3d EdCore::getMousePositionWCS()
{
    CPoint cursorPos;
    ::GetCursorPos(&cursorPos);
    ::ScreenToClient(adsw_acadDocWnd(), &cursorPos);

    acedDwgPoint cpt;
    acedCoordFromPixelToWorld(cursorPos, cpt);

    resbuf fromrb{};
    fromrb.restype = RTSHORT;
    fromrb.resval.rint = 2; // DCS

    resbuf torb{};
    torb.restype = RTSHORT;
    torb.resval.rint = 0; // WCS 

    AcGePoint3d hitPoint;
    acedTrans(cpt, &fromrb, &torb, FALSE, asDblArray(hitPoint));
    return hitPoint;
}

std::string EdCore::hatchPalletteDialog(const std::string& pattern, bool showCustom)
{
    RxAutoOutStr outstr;
#ifdef _ZRXTARGET 
    throw PyNotimplementedByHost();
    //zcedHatchPalletteDialog(utf8_to_wstr(pattern).c_str(), showCustom, outstr.buf);
#endif
#ifdef _GRXTARGET 
    gcedHatchPalletteDialog(utf8_to_wstr(pattern).c_str(), showCustom, outstr.buf);
#endif
#ifdef _BRXTARGET 
    acedHatchPalletteDialog(utf8_to_wstr(pattern).c_str(), showCustom, outstr.buf);
#endif
#ifdef _ARXTARGET 
    acedHatchPalletteDialog(utf8_to_wstr(pattern).c_str(), showCustom, outstr.buf);
#endif
    return outstr.str();
}

AcGePoint3d EdCore::osnap(const AcGePoint3d& pt, const std::string& mode)
{
    AcGePoint3d result;
    PyThrowBadRt(acedOsnap(asDblArray(pt), utf8_to_wstr(mode).c_str(), asDblArray(result)));
    return result;
}

AcCmColor EdCore::setColorPrompt(const std::string& prompt, bool bAllowMetaColor)
{
    AcCmColor color;
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#elif defined(_GRXTARGET250) || defined(_ZRXTARGET250)
    RxAutoOutStr str;
    PyThrowBadEs(acutNewString(utf8_to_wstr(prompt).c_str(), str.buf));
    acedSetColorPrompt(str.buf, color, bAllowMetaColor);
#else
    acedSetColorPrompt(utf8_to_wstr(prompt).c_str(), color, bAllowMetaColor);
#endif
    return color;
}

void EdCore::setUndoMark(bool flag)
{
#if defined(_BRXTARGET250) || defined(_GRXTARGET260) || defined(_ZRXTARGET260)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(acedSetUndoMark(flag));
#endif
}

//https://forums.autodesk.com/t5/objectarx-forum/view-not-restoring-to-previous-view/m-p/7203525/highlight/true#M8017
PyDbViewTableRecord EdCore::getCurrentView()
{
    AcDbViewTableRecord* view = new AcDbViewTableRecord();
    struct resbuf var;
    struct resbuf WCS, UCS, DCS;
    WCS.restype = RTSHORT;
    WCS.resval.rint = 0;
    UCS.restype = RTSHORT;
    UCS.resval.rint = 1;
    DCS.restype = RTSHORT;
    DCS.resval.rint = 2;
    ads_getvar(L"VIEWMODE", &var);
    view->setPerspectiveEnabled(var.resval.rint & 1);
    view->setFrontClipEnabled(var.resval.rint & 2 ? true : false);
    view->setBackClipEnabled(var.resval.rint & 4 ? true : false);
    view->setFrontClipAtEye(!(var.resval.rint & 16));
    ads_getvar(L"BACKZ", &var);
    view->setBackClipDistance(var.resval.rreal);
    ads_getvar(L"VIEWCTR", &var);
    ads_trans(var.resval.rpoint, &UCS, &DCS, NULL, var.resval.rpoint);
    view->setCenterPoint(asPnt2d(var.resval.rpoint));
    ads_getvar(L"FRONTZ", &var);
    view->setFrontClipDistance(var.resval.rreal);
    ads_getvar(L"LENSLENGTH", &var);
    view->setLensLength(var.resval.rreal);
    ads_getvar(L"TARGET", &var);
    ads_trans(var.resval.rpoint, &UCS, &WCS, NULL, var.resval.rpoint);
    view->setTarget(asPnt3d(var.resval.rpoint));
    ads_getvar(L"VIEWDIR", &var);
    ads_trans(var.resval.rpoint, &UCS, &WCS, TRUE, var.resval.rpoint);
    view->setViewDirection(asVec3d(var.resval.rpoint));
    ads_getvar(L"VIEWSIZE", &var);
    view->setHeight(var.resval.rreal);
    return PyDbViewTableRecord(view, true);
}

void EdCore::setCurrentView1(const PyDbViewTableRecord& vrec)
{
    return PyThrowBadEs(acedSetCurrentView(vrec.impObj(), nullptr));
}

void EdCore::setCurrentView2(const PyDbViewTableRecord& vrec, const PyDbViewport& vp)
{
    return PyThrowBadEs(acedSetCurrentView(vrec.impObj(), vp.impObj()));
}

void EdCore::setCurrentVPort(const PyDbViewport& vp)
{
    return PyThrowBadEs(acedSetCurrentVPort(vp.impObj()));
}

int EdCore::setStatusBarProgressMeter(const std::string& pszLabel, int nMinPos, int nMaxPos)
{
    return acedSetStatusBarProgressMeter(utf8_to_wstr(pszLabel).c_str(), nMinPos, nMaxPos);
}

int EdCore::setStatusBarProgressMeterPos(int pos)
{
    return acedSetStatusBarProgressMeterPos(pos);
}

void EdCore::setXrefResolvedWithUpdateStatus(const PyDbBlockTableRecord& rec)
{
#if defined(_BRXTARGET250) || defined(_GRXTARGET250) || defined(_ZRXTARGET260)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(acedSetXrefResolvedWithUpdateStatus(rec.impObj()));
#endif
}

bool EdCore::showHTMLModalWindow1(UINT_PTR hwnd, const std::string& uriOfHtmlPage)
{
    return showHTMLModalWindow2(hwnd, uriOfHtmlPage, true);
}

bool EdCore::showHTMLModalWindow2(UINT_PTR hwnd, const std::string& uriOfHtmlPage, bool persistSizeAndPosition)
{
#if defined(_BRXTARGET250) || defined(_GRXTARGET260) || defined(_ZRXTARGET260)
    throw PyNotimplementedByHost();
#else
    return acedShowHTMLModalWindow((HWND)hwnd, utf8_to_wstr(uriOfHtmlPage).c_str(), persistSizeAndPosition);
#endif
}

UINT_PTR EdCore::showHTMLModelessWindow1(UINT_PTR owner, const std::string& uriOfHtmlPage)
{
    return showHTMLModelessWindow2(owner, uriOfHtmlPage, true);
}

UINT_PTR EdCore::showHTMLModelessWindow2(UINT_PTR owner, const std::string& uriOfHtmlPage, bool persistSizeAndPosition)
{
#if defined(_BRXTARGET250) || defined(_GRXTARGET260) || defined(_ZRXTARGET260)
    throw PyNotimplementedByHost();
#else
    return (UINT_PTR)acedShowHTMLModelessWindow((HWND)owner, utf8_to_wstr(uriOfHtmlPage).c_str(), persistSizeAndPosition);
#endif
}

void EdCore::skipXrefNotification(PyDbDatabase& db, const std::string& xrefName)
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(acedSkipXrefNotification(db.impObj(), utf8_to_wstr(xrefName).c_str()));
#endif
}

void EdCore::setFieldUpdateEnabled(PyApDocument& doc, bool enabled)
{
#if defined(_BRXTARGET250) || defined(_GRXTARGET260) || defined(_ZRXTARGET250)
    throw PyNotimplementedByHost();
#else
    acedSetFieldUpdateEnabled(doc.impObj(), enabled);
#endif
}

int EdCore::setFunHelp(const std::string& pszFunctionName, const std::string& pszHelpfile, const std::string& pszTopic, int iCmd)
{
    return acedSetFunHelp(utf8_to_wstr(pszFunctionName).c_str(), utf8_to_wstr(pszHelpfile).c_str(), utf8_to_wstr(pszTopic).c_str(), iCmd);
}

boost::python::tuple EdCore::textBox(const boost::python::list& pyargs)
{
    AcResBufPtr ptr(listToResbuf(pyargs));
    AcGePoint3d ll, ur;
    PyThrowBadRt(acedTextBox(ptr.get(), asDblArray(ll), asDblArray(ur)));
    return boost::python::make_tuple(ll, ur);
}

void EdCore::textPage()
{
    PyThrowBadRt(acedTextPage());
}

void EdCore::textScr()
{
    PyThrowBadRt(acedTextScr());
}

static resbuf* transArgToResfBuf(const boost::python::object& arg)
{
    if (PyLong_Check(arg.ptr()))
    {
        const int val = extract<int32_t>(arg);
        return acutBuildList(RTSHORT, val, 0);
    }
    else if (extract<PyDbObjectId>(arg).check())
    {
        PyDbObjectId val = extract<PyDbObjectId>(arg);
        ads_name name = { 0L };
        PyThrowBadEs(acdbGetAdsName(name, val.m_id));
        return acutBuildList(RTENAME, name, 0);
    }
    else if (extract<AcGePoint3d>(arg).check())
    {
        AcGePoint3d val = extract<AcGePoint3d>(arg);
        return acutBuildList(RT3DPOINT, asDblArray(val), 0);
    }
    else if (extract<AcGeVector3d>(arg).check())
    {
        AcGeVector3d val = extract<AcGeVector3d>(arg);
        return acutBuildList(RT3DPOINT, asDblArray(val), 0);
    }
    else if (PyList_Check(arg.ptr()))
    {
        const boost::python::list& pylist = extract<boost::python::list>(arg);
        return listToResbuf(pylist);
    }
    else
    {
        return nullptr;
    }
}

AcGePoint3d EdCore::trans(const AcGePoint3d& pt, const boost::python::object& from, const boost::python::object& to, bool disp)
{
    PyAutoLockGIL lock;
    AcResBufPtr fromBuf(transArgToResfBuf(from));
    AcResBufPtr toBuf(transArgToResfBuf(to));
    ads_point outpnt;
    PyThrowBadRt(acedTrans(asDblArray(pt), fromBuf.get(), toBuf.get(), disp ? 1 : 0, outpnt));
    return asPnt3d(outpnt);
}

bool EdCore::unloadPartialMenu(const std::string& pszMenuFile)
{
    return acedUnloadPartialMenu(utf8_to_wstr(pszMenuFile).c_str());
}

void EdCore::unmarkForDelayXRefRelativePathResolve(const PyDbObjectId& xrefDefId)
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    acedUnmarkForDelayXRefRelativePathResolve(xrefDefId.m_id);
#endif
}

int EdCore::update(int vport, const AcGePoint2d& p1, const AcGePoint2d& p2)
{
    return acedUpdate(vport, asDblArray(p1), asDblArray(p2));
}

void EdCore::updateDisplay()
{
    acedUpdateDisplay();
}

void EdCore::updateDisplayPause(bool bEnable)
{
    acedUpdateDisplayPause(bEnable);
}

bool EdCore::usrBrk()
{
    return acedUsrBrk() == 1;
}

PyDbObjectId EdCore::viewportIdFromNumber(int val)
{
    return PyDbObjectId(acedViewportIdFromNumber(val));
}

void EdCore::vpLayer(const PyDbObjectId& vpId, const boost::python::list& layerIds, AcDb::VpFreezeOps operation)
{
    return PyThrowBadEs(acedVPLayer(vpId.m_id, PyListToObjectIdArray(layerIds), operation));
}

boost::python::list EdCore::vports()
{
    resbuf* buf = nullptr;
    if (auto es = acedVports(&buf); es != RTNORM)
        throw PyErrorStatusException(eOutOfMemory);
    AcResBufPtr autodel(buf);
    return resbufToList(buf);
}

void EdCore::vports2VportTableRecords()
{
    return PyThrowBadEs(acedVports2VportTableRecords());
}

void EdCore::vportTableRecords2Vports()
{
    return PyThrowBadEs(acedVportTableRecords2Vports());
}

void EdCore::xrefAttach1(const std::string& path, const std::string& name)
{
    return PyThrowBadEs(acedXrefAttach(utf8_to_wstr(path).c_str(), utf8_to_wstr(name).c_str()));
}

void EdCore::xrefAttach2(const std::string& path, const std::string& name, PyDbObjectId& btrid, PyDbObjectId& refid,
    AcGePoint3d& pt, AcGeScale3d& sc, double rot, bool bQuiet, PyDbDatabase& pHostDb, const std::string& passwd)
{
    return PyThrowBadEs(acedXrefAttach(utf8_to_wstr(path).c_str(), utf8_to_wstr(name).c_str(),
        &btrid.m_id, &refid.m_id, &pt, &sc, &rot, bQuiet, pHostDb.impObj(), utf8_to_wstr(passwd).c_str()));
}

std::string EdCore::xrefCreateBlockname(const std::string& XrefPathname)
{
    std::string result;
    ACHAR* XrefBlockname = nullptr;
    if (auto es = acedXrefCreateBlockname(utf8_to_wstr(XrefPathname).c_str(), XrefBlockname); es != eOk)
        throw PyErrorStatusException(es);
    result = wstr_to_utf8(XrefBlockname);
    acutDelString(XrefBlockname);
    return result;
}

void EdCore::xrefDetach1(const std::string& XrefBlockname)
{
    return PyThrowBadEs(acedXrefDetach(utf8_to_wstr(XrefBlockname).c_str()));
}

void EdCore::xrefDetach2(const std::string& XrefBlockname, bool bQuiet, PyDbDatabase& pHostDb)
{
    return PyThrowBadEs(acedXrefDetach(utf8_to_wstr(XrefBlockname).c_str(), bQuiet, pHostDb.impObj()));
}

bool EdCore::xrefNotifyCheckFileChanged(const PyDbObjectId& id)
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    bool flag = false;
    if (auto es = acedXrefNotifyCheckFileChanged(id.m_id, flag); es != eOk)
        throw PyErrorStatusException(es);
    return flag;
#endif
}

void EdCore::xrefOverlay1(const std::string& path, const std::string& name)
{
    return PyThrowBadEs(acedXrefOverlay(utf8_to_wstr(path).c_str(), utf8_to_wstr(name).c_str()));
}

void EdCore::xrefOverlay2(const std::string& path, const std::string& name, PyDbObjectId& btrid, PyDbObjectId& refid,
    AcGePoint3d& pt, AcGeScale3d& sc, double rot, bool bQuiet, PyDbDatabase& pHostDb, const std::string& passwd)
{
    return PyThrowBadEs(acedXrefOverlay(utf8_to_wstr(path).c_str(),
        utf8_to_wstr(name).c_str(), &btrid.m_id, &refid.m_id, &pt, &sc, &rot, bQuiet, pHostDb.impObj(), utf8_to_wstr(passwd).c_str()));
}

void EdCore::xrefReload1(const boost::python::list& symbolIds)
{
    AcDbObjectIdArray ids = PyListToObjectIdArray(symbolIds);
    return PyThrowBadEs(acedXrefReload(ids));
}

void EdCore::xrefReload2(const boost::python::list& symbolIds, bool bQuiet, PyDbDatabase& pHostDb)
{
    AcDbObjectIdArray ids = PyListToObjectIdArray(symbolIds);
    return PyThrowBadEs(acedXrefReload(ids, bQuiet, pHostDb.impObj()));
}

void EdCore::xrefReload3(const std::string& name)
{
    return PyThrowBadEs(acedXrefReload(utf8_to_wstr(name).c_str()));
}

void EdCore::xrefReload4(const std::string& name, bool bQuiet, PyDbDatabase& pHostDb)
{
    return PyThrowBadEs(acedXrefReload(utf8_to_wstr(name).c_str(), bQuiet, pHostDb.impObj()));
}

void EdCore::xrefResolve1(PyDbDatabase& pHostDb)
{
    return PyThrowBadEs(acedXrefResolve(pHostDb.impObj()));
}

void EdCore::xrefResolve2(PyDbDatabase& pHostDb, bool bQuiet)
{
    return PyThrowBadEs(acedXrefResolve(pHostDb.impObj(), bQuiet));
}

void EdCore::xrefUnload1(const std::string& XrefBlockname)
{
    return PyThrowBadEs(acedXrefUnload(utf8_to_wstr(XrefBlockname).c_str()));
}

void EdCore::xrefUnload2(const std::string& XrefBlockname, bool bQuiet, PyDbDatabase& pHostDb)
{
    return PyThrowBadEs(acedXrefUnload(utf8_to_wstr(XrefBlockname).c_str(), bQuiet, pHostDb.impObj()));
}

void EdCore::xrefBind1(const std::string& XrefBlockname)
{
    return PyThrowBadEs(acedXrefBind(utf8_to_wstr(XrefBlockname).c_str()));
}

void EdCore::xrefBind2(const std::string& XrefBlockname, bool bInsertBind, bool bQuiet, PyDbDatabase& pHostDb)
{
    return PyThrowBadEs(acedXrefBind(utf8_to_wstr(XrefBlockname).c_str(), bInsertBind, bQuiet, pHostDb.impObj()));
}

void EdCore::xrefXBind1(const boost::python::list& symbolIds)
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    AcDbObjectIdArray ids = PyListToObjectIdArray(symbolIds);
    return PyThrowBadEs(acedXrefXBind(ids));
#endif
}

void EdCore::xrefXBind2(const boost::python::list& symbolIds, bool bQuiet, PyDbDatabase& pHostDb)
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    AcDbObjectIdArray ids = PyListToObjectIdArray(symbolIds);
    return PyThrowBadEs(acedXrefXBind(ids, bQuiet, pHostDb.impObj()));
#endif
}

PyDbXrefGraph EdCore::curDwgXrefGraph()
{
    PyDbXrefGraph gr{};
    PyThrowBadEs(acedGetCurDwgXrefGraph(*gr.impObj(), Adesk::kFalse));
    return gr;
}

std::string EdCore::exceptionTest()
{
    PyThrowBadEs(Acad::ErrorStatus::eNotAssociative);
    return std::string{};
}
