# PyEd

```PY




eAligned: PointHistory  # 1024
eAppFiltered: PointHistory  # 2048
eCancel: PromptStatus  # -5002
eCartSnapped: PointHistory  # 16
eCoordPending: PointHistory  # 458752
eCyclingPt: PointHistory  # 64
eDidNotPick: PointHistory  # 0
eDirect: PromptStatus  # -5999
eDirectDistance: PointHistory  # 2097152
eError: PromptStatus  # -5001
eFailed: PromptStatus  # -5004
eForcedPick: PointHistory  # 4096
eFromKeyboard: PointHistory  # 524288
eGizmoConstrainted: PointHistory  # 4194304
eGripped: PointHistory  # 8
eKeyword: PromptStatus  # -5005
eLastPt: PointHistory  # 4
eModeless: PromptStatus  # 5027
eNoEmpty: PromptCondition  # 1
eNoNegative: PromptCondition  # 2
eNoZero: PromptCondition  # 1
eNone: PromptCondition  # 0
eNormal: PromptStatus  # 5100
eNotDigitizer: PointHistory  # 2
eNotInteractive: PointHistory  # 1048576
eOk: PromptStatus  # 5100
eOrtho: PointHistory  # 32
eOsnapped: PointHistory  # 128
ePickAborted: PointHistory  # 32768
ePickMask: PointHistory  # 57344
ePolarAngle: PointHistory  # 256
eRejected: PromptStatus  # -5003
eTablet: PointHistory  # 1
eUsedOsnapBox: PointHistory  # 16384
eUsedPickBox: PointHistory  # 8192
eXPending: PointHistory  # 65536
eYPending: PointHistory  # 131072
eZPending: PointHistory  # 262144
kAccept3dCoordinates: UserInputControls  # 128
kAcceptMouseUpAsPoint: UserInputControls  # 256
kAcceptOtherInputString: UserInputControls  # 2048
kAnyBlankTerminatesInput: UserInputControls  # 512
kCancel: DragStatus  # -4
kCrosshair: CursorType  # 0
kCrosshairDashed: CursorType  # 12
kCrosshairNoRotate: CursorType  # 6
kDeletedEffect: DragStyleType  # 4
kDisableDirectDistanceInput: UserInputControls  # 65536
kDontEchoCancelForCtrlC: UserInputControls  # 4
kDontUpdateLastPoint: UserInputControls  # 8
kDrawOrderAbove: DrawOrderCmdType  # 4
kDrawOrderBelow: DrawOrderCmdType  # 3
kDrawOrderBottom: DrawOrderCmdType  # 1
kDrawOrderNone: DrawOrderCmdType  # 0
kDrawOrderTop: DrawOrderCmdType  # 2
kEntitySelect: CursorType  # 8
kEntitySelectNoPersp: CursorType  # 10
kGovernedByOrthoMode: UserInputControls  # 1
kGovernedByUCSDetect: UserInputControls  # 4096
kHide: DragStyleType  # 1
kHighlight: DragStyleType  # 5
kImpliedFaceForUCSChange: UserInputControls  # 16384
kInitialBlankTerminatesInput: UserInputControls  # 1024
kInvisible: CursorType  # 7
kKW1: DragStatus  # 1
kKW2: DragStatus  # 2
kKW3: DragStatus  # 3
kKW4: DragStatus  # 4
kKW5: DragStatus  # 5
kKW6: DragStatus  # 6
kKW7: DragStatus  # 7
kKW8: DragStatus  # 8
kKW9: DragStatus  # 9
kModeless: DragStatus  # -17
kNoChange: DragStatus  # -6
kNoDwgLimitsChecking: UserInputControls  # 16
kNoNegativeResponseAccepted: UserInputControls  # 64
kNoSpecialCursor: CursorType  # -1
kNoZDirectionOrtho: UserInputControls  # 8192
kNoZeroResponseAccepted: UserInputControls  # 32
kNone: DragStyleType  # 0
kNormal: PromptStatus  # 5100
kNotRotated: CursorType  # 3
kNotSet: DragStyleType  # 6
kNull: DragStatus  # -1
kNullResponseAccepted: UserInputControls  # 2
kOther: DragStatus  # -3
kParallelogram: CursorType  # 9
kPkfirstOrGrips: CursorType  # 11
kRectCursor: CursorType  # 1
kRotatedCrosshair: CursorType  # 5
kRubberBand: CursorType  # 2
kTargetBox: CursorType  # 4
kTransparent25: DragStyleType  # 2
kTransparent75: DragStyleType  # 3
kUseBasePointElevation: UserInputControls  # 32768

class AutoSysVar:
    def __init__(self, varName: str, value, /) -> None:  
    def detach(self, val: bool, /) -> None:  

class Core:
    def __init__(self, /) -> None:  
    @staticmethod
    def addSupplementalCursorImage(
        image: wx.Image, order: int = 0, alpha: int = 255, /
    ) -> bool:  
    @staticmethod
    def alert(msg: str, /) -> int:
    @staticmethod
    def arxLoad(path: str, /) -> int:
    @staticmethod
    def arxLoaded() -> list:
    @staticmethod
    def arxUnload(app: str, /) -> int:
    @staticmethod
    def audit(db: PyDb.Database, fix: bool, echo: bool = False, /) -> None:
    @staticmethod
    def autoSetVar(name: str, value, /) -> AutoSysVar:  
    @staticmethod
    def calcTextExtents(val: str, textStyleId: PyDb.ObjectId, /) -> tuple[float, float]:  
    @staticmethod
    def callBackOnCancel() -> None:
    @staticmethod
    def clearOLELock(handle: int, /) -> bool:
    @staticmethod
    def clipFormatName() -> str:
    @staticmethod
    def cmdCWasCancelled() -> bool:
    @overload
    @staticmethod
    def cmdS(commandName: str, /) -> bool:
    @overload
    @staticmethod
    def cmdS(resultBuffer: list[tuple[int, Any]], /) -> bool:
    @overload
    @staticmethod
    def cmdS(*args) -> bool:
    @staticmethod
    def cmdUndefine(name: str, undefineit: int, /) -> int:
    @staticmethod
    def convertEntityToHatch(hatch: PyDb.Hatch, entity: PyDb.Entity, transferId: bool, /) -> None:
    @overload
    @staticmethod
    def coordFromPixelToWorld(pt: tuple[int, int], /) -> PyGe.Point3d:
    @overload
    @staticmethod
    def coordFromPixelToWorld(winnum: int, pt: tuple[int, int], /) -> PyGe.Point3d:
    @overload
    @staticmethod
    def coordFromPixelToWorld(*args) -> PyGe.Point3d:
    @staticmethod
    def coordFromWorldToPixel(windnum: int, pnt: PyGe.Point3d, /) -> tuple[int, int]:
    @staticmethod
    def createInternetShortcut(szURL: str, szShortcutPath: str, /) -> bool:
    @staticmethod
    def createViewportByView(
        db: PyDb.Database, view: PyDb.ObjectId, pt: PyGe.Point2d, scale: float, /
    ) -> PyDb.ObjectId:
    @staticmethod
    def curDwgXrefGraph() -> PyDb.XrefGraph:  
    @staticmethod
    def defun(name: str, funcnumber: int, /) -> int:
    @staticmethod
    def defunEx(globalName: str, name: str, funcnumber: int, /) -> int:
    @staticmethod
    def disableDefaultARXExceptionHandler(val: bool, /) -> None:
    @staticmethod
    def disableUsrbrk() -> None:
    @staticmethod
    def displayBorder(val: bool, /) -> bool:
    @staticmethod
    def drawOrderInherit(
        parent: PyDb.ObjectId, childids: list[PyDb.ObjectId], cmd: PyEd.DrawOrderCmdType, /
    ) -> None:
    @staticmethod
    def drawingStatusBarsVisible() -> bool:
    @staticmethod
    def dropOpenFile(val: str, /) -> None:  
    @staticmethod
    def eatCommandThroat() -> int:
    @staticmethod
    def editMTextInteractive(mt: PyDb.MText, usenewUI: bool, allowTabs: bool, /) -> int:
    @staticmethod
    def enableUsrbrk() -> None:
    @staticmethod
    def evaluateDiesel(statement: str, /) -> str:  
    @staticmethod
    def evaluateLisp(statement: str, /) -> list:  
    @staticmethod
    def exceptionTest() -> str:  
    @staticmethod
    def findFile(fname: str, /) -> str:
    @staticmethod
    def findTrustedFile(fname: str, /) -> str:
    @staticmethod
    def getAcadDockCmdLine() -> int:
    @staticmethod
    def getAcadTextCmdLine() -> int:
    @staticmethod
    def getBlockEditMode() -> int:
    @staticmethod
    def getCfg(val: str, /) -> str:
    @staticmethod
    def getCommandForDocument(doc: PyAp.Document, /) -> str:
    @staticmethod
    def getCommandPromptString() -> str:  
    @staticmethod
    def getCommands() -> dict:  
    @staticmethod
    def getCurVportPixelToDisplay() -> tuple[float, float]:
    @staticmethod
    def getCurVportScreenToDisplay() -> tuple[float, float]:
    @staticmethod
    def getCurrentSelectionSet() -> list[PyDb.ObjectId]:
    @staticmethod
    def getCurrentView() -> PyDb.ViewTableRecord:  
    @staticmethod
    def getDpiScalingValue() -> float:
    @staticmethod
    def getEnv(val: str, /) -> str:
    @staticmethod
    def getFileD(title: str, defawlt: str, ext: str, flags: int, /) -> str:
    @staticmethod
    def getFileNavDialog(title: str, defawlt: str, ext: str, dlgname: str, flags: int, /) -> list:
    @staticmethod
    def getLastCommandLines(lineCount: int, ignoreNull: bool, /) -> list[str]:  
    @staticmethod
    def getMousePositionUCS() -> PyGe.Point3d:  
    @staticmethod
    def getMousePositionWCS() -> PyGe.Point3d:  
    @staticmethod
    def getPredefinedHatchPatterns() -> list[str]:  
    @staticmethod
    def getRGB(colorIndex: int, /) -> tuple[int,  ]:
    @staticmethod
    def getSupplementalCursorOffset() -> tuple:  
    @staticmethod
    def getSym(val: str, /) -> list:
    @staticmethod
    def getSysVars() -> dict:  
    @staticmethod
    def getUserFavoritesDir() -> str:
    @staticmethod
    def getVar(name: str, /) -> object:
    @staticmethod
    def getWinNum(ptx: int, pty: int, /) -> int:
    @staticmethod
    def grDraw(
        pt1: PyGe.Point2d | PyGe.Point3d,
        pt2: PyGe.Point2d | PyGe.Point3d,
        color: int,
        highlight: int,
        /,
    ) -> int:
    @staticmethod
    def grDrawArc(
        pt1: PyGe.Point3d, pt2: PyGe.Point3d, pt3: PyGe.Point3d, numsegs: int, color: int, /
    ) -> int:  
    @staticmethod
    def grDrawBox(pts: list[PyGe.Point3d], color: int, highlight: int, /) -> int:  
    @staticmethod
    def grDrawCircle(cen: PyGe.Point3d, radius: float, numsegs: int, color: int, /) -> int:  
    @staticmethod
    def grDrawPoly2d(pts: list[PyGe.Point2d], color: int, /) -> int:  
    @staticmethod
    def grDrawPoly3d(pts: list[PyGe.Point3d], color: int, /) -> int:  
    @staticmethod
    def grText(box: int, text: str, hl: int, /) -> int:
    @staticmethod
    def grVecs(resbuf: list, xform: PyGe.Matrix3d, /) -> int:
    @staticmethod
    def graphScr() -> None:
    @staticmethod
    def hasSupplementalCursorImage() -> bool:  
    @staticmethod
    def hatchPalletteDialog(pattern: str, custom: bool, /) -> str:  
    @staticmethod
    def initDialog(useDialog: bool, /) -> bool:
    @staticmethod
    def invoke(resultBuffer: list, /) -> list:
    @staticmethod
    def isDragging() -> int:
    @staticmethod
    def isInBackgroundMode() -> bool:
    @staticmethod
    def isInputPending() -> bool:
    @staticmethod
    def isMenuGroupLoaded(mnu: str, /) -> bool:
    @staticmethod
    def isOsnapOverride() -> bool:
    @staticmethod
    def isUpdateDisplayPaused() -> bool:
    @staticmethod
    def isUsrbrkDisabled() -> bool:
    @staticmethod
    def loadJSScript(scr: str, /) -> None:  
    @staticmethod
    def loadMainMenu(mnu: str, /) -> bool:  
    @staticmethod
    def loadPartialMenu(mnu: str, /) -> bool:
    @staticmethod
    def mSpace() -> None:
    @staticmethod
    def markForDelayXRefRelativePathResolve(id: PyDb.ObjectId, /) -> None:
    @staticmethod
    def menuCmd(cmd: str, /) -> int:  
    @staticmethod
    def osnap(pt: PyGe.Point3d, mode: str, /) -> PyGe.Point3d:
    @staticmethod
    def pSpace() -> None:
    @staticmethod
    def postCommand(str: str, /) -> None:  
    @staticmethod
    def postCommandPrompt() -> None:
    @staticmethod
    def prompt(val: str, /) -> int:
    @staticmethod
    def putSym(sym: str, resultBuffer: list, /) -> bool:
    @staticmethod
    def redraw(id: PyDb.ObjectId, mode: int, /) -> int:
    @staticmethod
    def regen() -> None:  
    @staticmethod
    def reloadMenus(bIncrementalReloading: bool, /) -> None:
    @staticmethod
    def removeSupplementalCursorImage() -> bool:  
    @staticmethod
    def restoreCurrentView(vid: PyDb.ObjectId, /) -> None:
    @staticmethod
    def restorePreviousUCS() -> None:
    @staticmethod
    def restoreStatusBar() -> None:
    @staticmethod
    def sendModelessOperationEnded(ctx: str, /) -> None:
    @staticmethod
    def sendModelessOperationStart(ctx: str, /) -> None:
    @staticmethod
    def setCfg(sym: str, val: str, /) -> None:
    @staticmethod
    def setColorDialog(
        clr: int, bAllowMetaColor: bool, nCurLayerColor, int, /
    ) -> tuple[bool, int]:
    @staticmethod
    def setColorDialogTrueColor(
        clr: PyDb.AcCmColor, bAllowMetaColor: bool, nCurLayerColor: PyDb.AcCmColor, tab: int = 7, /
    ) -> tuple[bool, PyDb.Color]:
    @staticmethod
    def setColorPrompt(prompt: str, bAllowMetaColor: bool, /) -> PyDb.Color:
    @staticmethod
    def setCurrentVPort(vp: PyDb.Viewport, /) -> None:
    @staticmethod
    def setCurrentView(vrec: PyDb.ViewTableRecord, vp: PyDb.Viewport =  , /) -> None:
    @staticmethod
    def setEnv(sym: str, val: str, /) -> None:
    @staticmethod
    def setFieldUpdateEnabled(doc: PyAp.Document, enabled: bool, /) -> None:
    @staticmethod
    def setFunHelp(functionName: str, helpfile: str, topic: str, iCmd: int, /) -> int:
    @staticmethod
    def setStatusBarProgressMeter(lable: str, nMinPos: int, nMaxPos: int, /) -> int:
    @staticmethod
    def setStatusBarProgressMeterPos(pos: int, /) -> int:
    @staticmethod
    def setSupplementalCursorOffset(x: int, y: int, /) -> None:  
    @staticmethod
    def setUndoMark(flag: bool, /) -> None:  
    @staticmethod
    def setVar(name: str, value, /) -> bool:
    @staticmethod
    def setXrefResolvedWithUpdateStatus(rec: PyDb.BlockTableRecord, /) -> None:
    @staticmethod
    def showHTMLModalWindow(
        hwnd: int, uriOfHtmlPage: str, persistSizeAndPosition: bool = True, /
    ) -> bool:
    @staticmethod
    def showHTMLModelessWindow(
        hwnd: int, uriOfHtmlPage: str, persistSizeAndPosition: bool = True, /
    ) -> int:
    @staticmethod
    def skipXrefNotification(db: PyDb.Database, name: str, /) -> None:
    @staticmethod
    def textBox(resultBuffer: list, /) -> tuple[PyGe.Point3d, PyGe.Point3d]:
    @staticmethod
    def textPage() -> None:
    @staticmethod
    def textScr() -> None:
    @staticmethod
    def trans(pt: PyGe.Point3d, rbFrom: tuple, rbTo: tuple, disp: bool, /) -> PyGe.Point3d:
    @staticmethod
    def unloadPartialMenu(mnu: str, /) -> bool:
    @staticmethod
    def unmarkForDelayXRefRelativePathResolve(id: PyDb.ObjectId, /) -> None:
    @staticmethod
    def update(vport: int, pt1: PyGe.Point2d, pt2: PyGe.Point2d, /) -> int:
    @staticmethod
    def updateDisplay() -> None:
    @staticmethod
    def updateDisplayPause(val: bool, /) -> None:
    @staticmethod
    def usrBrk() -> bool:
    @staticmethod
    def viewportIdFromNumber(val: int, /) -> PyDb.ObjectId:
    @staticmethod
    def vpLayer(
        id: PyDb.ObjectId, layerIds: list[PyDb.ObjectId], operation: PyDb.VpFreezeOps, /
    ) -> None:
    @staticmethod
    def vportTableRecords2Vports() -> None:
    @staticmethod
    def vports() -> list:
    @staticmethod
    def vports2VportTableRecords() -> None:
    @overload
    @staticmethod
    def xrefAttach(path: str, name: str, /) -> None:  
    @overload
    @staticmethod
    def xrefAttach(
        path: str,
        name: str,
        btrid: PyDb.ObjectId,
        refid: PyDb.ObjectId,
        pt: PyGe.Point3d,
        sc: PyGe.Scale3d,
        rot: float,
        bQuiet: bool,
        pHostDb: PyDb.Database,
        passwd: str,
        /,
    ) -> None:  
    @overload
    @staticmethod
    def xrefAttach(*args) -> None:  
    @overload
    @staticmethod
    def xrefBind(XrefBlockname: str, /) -> None:  
    @overload
    @staticmethod
    def xrefBind(
        XrefBlockname: str, bInsertBind: bool, bQuiet: bool, pHostDb: PyDb.Database, /
    ) -> None:  
    @overload
    @staticmethod
    def xrefBind(*args) -> None:  
    @staticmethod
    def xrefCreateBlockname(XrefPathname: str, /) -> str:  
    @overload
    @staticmethod
    def xrefDetach(XrefBlockname: str, /) -> None:  
    @overload
    @staticmethod
    def xrefDetach(XrefBlockname: str, bQuiet: bool, pHostDb: PyDb.Database, /) -> None:  
    @overload
    @staticmethod
    def xrefDetach(*args) -> None:  
    @staticmethod
    def xrefNotifyCheckFileChanged(id: PyDb.ObjectId, /) -> bool:  
    @overload
    @staticmethod
    def xrefOverlay(path: str, name: str, /) -> None:  
    @overload
    @staticmethod
    def xrefOverlay(
        path: str,
        name: str,
        btrid: PyDb.ObjectId,
        refid: PyDb.ObjectId,
        pt: PyGe.Point3d,
        sc: PyGe.Scale3d,
        rot: float,
        bQuiet: bool,
        pHostDb: PyDb.Database,
        passwd: str,
        /,
    ) -> None:  
    @overload
    @staticmethod
    def xrefOverlay(*args) -> None:  
    @overload
    @staticmethod
    def xrefReload(symbolIds: list[PyDb.ObjectId], /) -> None:  
    @overload
    @staticmethod
    def xrefReload(
        symbolIds: list[PyDb.ObjectId], bQuiet: bool, pHostDb: PyDb.Database, /
    ) -> None:  
    @overload
    @staticmethod
    def xrefReload(name: str, /) -> None:  
    @overload
    @staticmethod
    def xrefReload(name: str, bQuiet: bool, pHostDb: PyDb.Database, /) -> None:  
    @overload
    @staticmethod
    def xrefReload(*args) -> None:  
    @staticmethod
    def xrefResolve(db: PyDb.Database, bQuiet: bool = True, /) -> None:  
    @overload
    @staticmethod
    def xrefUnload(XrefBlockname: str, /) -> None:  
    @overload
    @staticmethod
    def xrefUnload(XrefBlockname: str, bQuiet: bool, pHostDb: PyDb.Database, /) -> None:  
    @overload
    @staticmethod
    def xrefUnload(*args) -> None:  
    @overload
    @staticmethod
    def xrefXBind(symbolIds: list[PyDb.ObjectId], /) -> None:  
    @overload
    @staticmethod
    def xrefXBind(
        symbolIds: list[PyDb.ObjectId], bQuiet: bool, pHostDb: PyDb.Database, /
    ) -> None:  
    @overload
    @staticmethod
    def xrefXBind(*args) -> None:  

class CursorType(_BoostPythonEnum):
    kNoSpecialCursor: ClassVar[Self]  # -1
    kCrosshair: ClassVar[Self]  # 0
    kRectCursor: ClassVar[Self]  # 1
    kRubberBand: ClassVar[Self]  # 2
    kNotRotated: ClassVar[Self]  # 3
    kTargetBox: ClassVar[Self]  # 4
    kRotatedCrosshair: ClassVar[Self]  # 5
    kCrosshairNoRotate: ClassVar[Self]  # 6
    kInvisible: ClassVar[Self]  # 7
    kEntitySelect: ClassVar[Self]  # 8
    kParallelogram: ClassVar[Self]  # 9
    kEntitySelectNoPersp: ClassVar[Self]  # 10
    kPkfirstOrGrips: ClassVar[Self]  # 11
    kCrosshairDashed: ClassVar[Self]  # 12

class DragStatus(_BoostPythonEnum):
    kModeless: ClassVar[Self]  # -17
    kNoChange: ClassVar[Self]  # -6
    kCancel: ClassVar[Self]  # -4
    kOther: ClassVar[Self]  # -3
    kNull: ClassVar[Self]  # -1
    eNormal: ClassVar[Self]  # 0
    eOk: ClassVar[Self]  # 0
    kNormal: ClassVar[Self]  # 0
    kKW1: ClassVar[Self]  # 1
    kKW2: ClassVar[Self]  # 2
    kKW3: ClassVar[Self]  # 3
    kKW4: ClassVar[Self]  # 4
    kKW5: ClassVar[Self]  # 5
    kKW6: ClassVar[Self]  # 6
    kKW7: ClassVar[Self]  # 7
    kKW8: ClassVar[Self]  # 8
    kKW9: ClassVar[Self]  # 9

class DragStyle:
    def __init__(
        self, styleTypeForOriginal: PyEd.DragStyleType, styleTypeForDragged: PyEd.DragStyleType, /
    ) -> None:  
    def setStyleTypeForDragged(
        self, styleTypeForDragged: PyEd.DragStyleType, /
    ) -> PyDb.ErrorStatus:  
    def setStyleTypeForOriginal(
        self, styleTypeForOriginal: PyEd.DragStyleType, /
    ) -> PyDb.ErrorStatus:  
    def styleTypeForDragged(self, /) -> DragStyleType:  
    def styleTypeForOriginal(self, /) -> DragStyleType:  

class DragStyleType(_BoostPythonEnum):
    kNone: ClassVar[Self]  # 0
    kHide: ClassVar[Self]  # 1
    kTransparent25: ClassVar[Self]  # 2
    kTransparent75: ClassVar[Self]  # 3
    kDeletedEffect: ClassVar[Self]  # 4
    kHighlight: ClassVar[Self]  # 5
    kNotSet: ClassVar[Self]  # 6

class DrawJig:
    def __init__(self, /) -> None:  
    def acquireAngle(self, basePnt: PyGe.Point3d =  , /) -> tuple[PyEd.DragStatus, float]:  
    def acquireDist(self, basePnt: PyGe.Point3d =  , /) -> tuple[PyEd.DragStatus, float]:  
    def acquirePoint(
        self, basePnt: PyGe.Point3d =  , /
    ) -> tuple[PyEd.DragStatus, PyGe.Point3d]:  
    def acquireString(self, /) -> tuple[PyEd.DragStatus, str]:  
    @staticmethod
    def className() -> str:  
    def dispPrompt(self, /) -> str:  
    def drag(self, style: PyEd.DragStyle =  , /) -> DragStatus:  
    def keywordList(self, /) -> str:  
    def sampler(self, /) -> DragStatus:  
    def setDispPrompt(self, val: str, /) -> None:  
    def setKeywordList(self, val: str, /) -> None:  
    def setSpecialCursorType(self, val: PyEd.CursorType, /) -> None:  
    def setUserInputControls(self, val: PyEd.UserInputControls, /) -> None:  
    def specialCursorType(self, /) -> CursorType:  
    def update(self, /) -> bool:  
    def userInputControls(self, /) -> UserInputControls:  
    def viewportDraw(self, wd: PyGi.ViewportDraw, /) -> None:  
    def worldDraw(self, wd: PyGi.WorldDraw, /) -> bool:  

class DrawOrderCmdType(_BoostPythonEnum):
    kDrawOrderNone: ClassVar[Self]  # 0
    kDrawOrderBottom: ClassVar[Self]  # 1
    kDrawOrderTop: ClassVar[Self]  # 2
    kDrawOrderBelow: ClassVar[Self]  # 3
    kDrawOrderAbove: ClassVar[Self]  # 4

class Editor:
    def __init__(self, /) -> None:  
    @staticmethod
    def activeViewportId() -> PyDb.ObjectId:
    @staticmethod
    def className() -> str:  
    @staticmethod
    def curViewportObjectId() -> PyDb.ObjectId:
    @staticmethod
    def duplicateSelectionsAllowed(doc: PyAp.Document, /) -> bool:
    @overload
    @staticmethod
    def entSel(prompt: str, /) -> tuple[PyEd.PromptStatus, PyDb.ObjectId, PyGe.Point3d]:
    @overload
    @staticmethod
    def entSel(
        prompt: str, eType: PyRx.RxClass, /
    ) -> tuple[PyEd.PromptStatus, PyDb.ObjectId, PyGe.Point3d]:
    @overload
    @staticmethod
    def entSel(
        prompt: str, eTypes: list[PyRx.RxClass], /
    ) -> tuple[PyEd.PromptStatus, PyDb.ObjectId, PyGe.Point3d]:
    @overload
    @staticmethod
    def entSel(*args) -> tuple[PyEd.PromptStatus, PyDb.ObjectId, PyGe.Point3d]:
    @staticmethod
    def getAngle(basePt: PyGe.Point3d, prompt: str, /) -> tuple[PyEd.PromptStatus, float]:
    @staticmethod
    def getCorner(basePt: PyGe.Point3d, prompt: str, /) -> tuple[PyEd.PromptStatus, PyGe.Point3d]:
    @staticmethod
    def getCurrentSelectionSet() -> list[PyDb.ObjectId]:
    @staticmethod
    def getCurrentUCS() -> PyGe.Matrix3d:
    @overload
    @staticmethod
    def getDist(prompt: str, /) -> tuple[PyEd.PromptStatus, float]:
    @overload
    @staticmethod
    def getDist(basePt: PyGe.Point3d, prompt: str, /) -> tuple[PyEd.PromptStatus, float]:
    @overload
    @staticmethod
    def getDist(*args) -> tuple[PyEd.PromptStatus, float]:
    @staticmethod
    def getDouble(
        prompt: str, condition: PyEd.PromptCondition = PyEd.PromptCondition.eNone, /
    ) -> tuple[PyEd.PromptStatus, float]:
    @staticmethod
    def getInput() -> str:
    @staticmethod
    def getInteger(
        prompt: str, condition: PyEd.PromptCondition = PyEd.PromptCondition.eNone, /
    ) -> tuple[PyEd.PromptStatus, int]:
    @staticmethod
    def getKword(keyword: str, /) -> tuple[PyEd.PromptStatus, str]:
    @overload
    @staticmethod
    def getPoint(prompt: str, /) -> tuple[PyEd.PromptStatus, PyGe.Point3d]:
    @overload
    @staticmethod
    def getPoint(basePt: PyGe.Point3d, prompt: str, /) -> tuple[PyEd.PromptStatus, PyGe.Point3d]:
    @overload
    @staticmethod
    def getPoint(*args) -> tuple[PyEd.PromptStatus, PyGe.Point3d]:
    @staticmethod
    def getReal(
        prompt: str, condition: PyEd.PromptCondition = PyEd.PromptCondition.eNone, /
    ) -> tuple[PyEd.PromptStatus, float]:
    @overload
    @staticmethod
    def getString(prompt: str, /) -> tuple[PyEd.PromptStatus, str]:
    @overload
    @staticmethod
    def getString(
        prompt: str, condition: PyEd.PromptCondition, /
    ) -> tuple[PyEd.PromptStatus, str]:
    @overload
    @staticmethod
    def getString(cronly: int, prompt: str, /) -> tuple[PyEd.PromptStatus, str]:
    @overload
    @staticmethod
    def getString(
        cronly: int, prompt: str, condition: PyEd.PromptCondition, /
    ) -> tuple[PyEd.PromptStatus, str]:
    @overload
    @staticmethod
    def getString(*args) -> tuple[PyEd.PromptStatus, str]:
    @staticmethod
    def getViewportNumber(ptx: int, pty: int, /) -> int:
    @staticmethod
    def initGet(val: int, keyword: str, /) -> PromptStatus:
    @staticmethod
    def nEntSelP(
        prompt: str, selpt: PyGe.Point3d =  , /
    ) -> tuple[
        PyEd.PromptStatus, PyDb.ObjectId, PyGe.Point3d, PyGe.Matrix3d, list[PyDb.ObjectId]
    ]:  
    @overload
    @staticmethod
    def nEntSelPEx(
        prompt: str, flags: int, /
    ) -> tuple[
        PyEd.PromptStatus, PyDb.ObjectId, PyGe.Point3d, PyGe.Matrix3d, int, list[PyDb.ObjectId]
    ]:  
    @overload
    @staticmethod
    def nEntSelPEx(
        prompt: str, selpt: PyGe.Point3d, flags: int, /
    ) -> tuple[
        PyEd.PromptStatus, PyDb.ObjectId, PyGe.Point3d, PyGe.Matrix3d, int, list[PyDb.ObjectId]
    ]:  
    @overload
    @staticmethod
    def nEntSelPEx(
        *args,
    ) -> tuple[
        PyEd.PromptStatus, PyDb.ObjectId, PyGe.Point3d, PyGe.Matrix3d, int, list[PyDb.ObjectId]
    ]:  
    @staticmethod
    def regen() -> None:  
    @staticmethod
    def select(
        filter: Collection[tuple[int, Any]] =  , /
    ) -> tuple[PyEd.PromptStatus, PyEd.SelectionSet]:
    @staticmethod
    def selectAll(
        filter: Collection[tuple[int, Any]] =  , /
    ) -> tuple[PyEd.PromptStatus, PyEd.SelectionSet]:
    @staticmethod
    def selectFence(
        points: Collection[PyGe.Point3d], filter: Collection[tuple[int, Any]] =  , /
    ) -> tuple[PyEd.PromptStatus, PyEd.SelectionSet]:
    @staticmethod
    def selectImplied() -> tuple[PyEd.PromptStatus, PyEd.SelectionSet]:  
    @staticmethod
    def selectLast(
        filter: Collection[tuple[int, Any]] =  , /
    ) -> tuple[PyEd.PromptStatus, PyEd.SelectionSet]:
    @staticmethod
    def selectPrevious(
        filter: Collection[tuple[int, Any]] =  , /
    ) -> tuple[PyEd.PromptStatus, PyEd.SelectionSet]:
    @staticmethod
    def selectPrompt(
        addPromt: str, remPromt: str, filter: Collection[tuple[int, Any]] =  , /
    ) -> tuple[PyEd.PromptStatus, PyEd.SelectionSet]:
    @staticmethod
    def selectWindow(
        pt1: PyGe.Point3d, pt2: PyGe.Point3d, filter: Collection[tuple[int, Any]] =  , /
    ) -> tuple[PyEd.PromptStatus, PyEd.SelectionSet]:
    @staticmethod
    def selectWindowPolygon(
        points: Collection[PyGe.Point3d], filter: Collection[tuple[int, Any]] =  , /
    ) -> tuple[PyEd.PromptStatus, PyEd.SelectionSet]:
    @staticmethod
    def setAllowDuplicateSelection(doc: PyAp.Document, flag: bool, /) -> None:
    @staticmethod
    def setCurrentUCS(ucs: PyGe.Matrix3d, /) -> None:
    @staticmethod
    def ssget(
        mode: str, arg1: object, arg2: object, filter: Collection[tuple[int, Any]] =  , /
    ) -> tuple[PyEd.PromptStatus, PyEd.SelectionSet]:
    @staticmethod
    def traceBoundary(point: PyGe.Point3d, detectIslands: bool, /) -> list[PyDb.Polyline]:
    @staticmethod
    def ucsNormalVector() -> PyGe.Vector3d:
    @staticmethod
    def ucsXDir() -> PyGe.Vector3d:
    @staticmethod
    def ucsYDir() -> PyGe.Vector3d:

class EditorReactor:
    def __init__(self, /) -> None:  
    def abortAttach(self, dbFrom: PyDb.Database, /) -> None:  
    def abortDeepClone(self, idMap: PyDb.IdMapping, /) -> None:  
    def abortDxfIn(self, db: PyDb.Database, /) -> None:  
    def abortDxfOut(self, db: PyDb.Database, /) -> None:  
    def abortInsert(self, db: PyDb.Database, /) -> None:  
    def abortRestore(self, dbTo: PyDb.Database, /) -> None:  
    def abortSave(self, db: PyDb.Database, /) -> None:  
    def abortWblock(self, db: PyDb.Database, /) -> None:  
    def addReactor(self, /) -> None:  
    def beginAttach(self, dbTo: PyDb.Database, val: str, dbFrom: PyDb.Database, /) -> None:  
    def beginCloseAll(self, /) -> None:  
    def beginDeepClone(self, db: PyDb.Database, idMap: PyDb.IdMapping, /) -> None:  
    def beginDeepCloneXlation(self, idMap: PyDb.IdMapping, /) -> PyDb.ErrorStatus:  
    def beginDocClose(self, db: PyDb.Database, /) -> None:  
    def beginDoubleClick(self, pt: PyGe.Point3d, /) -> None:  
    def beginDwgOpen(self, fineName: str, /) -> None:  
    def beginDxfIn(self, db: PyDb.Database, /) -> None:  
    def beginDxfOut(self, db: PyDb.Database, /) -> None:  
    @overload
    def beginInsert(
        self, dbTo: PyDb.Database, pBlockName: str, dbFrom: PyDb.Database, /
    ) -> None:  
    @overload
    def beginInsert(
        self, dbTo: PyDb.Database, xform: PyGe.Matrix3d, dbFrom: PyDb.Database, /
    ) -> None:  
    @overload
    def beginInsert(self, *args) -> None:  
    def beginQuit(self, /) -> None:  
    def beginRestore(self, dbTo: PyDb.Database, val: str, dbFrom: PyDb.Database, /) -> None:  
    def beginRightClick(self, pt: PyGe.Point3d, /) -> None:  
    def beginSave(self, db: PyDb.Database, fname: str, /) -> None:  
    def beginWblock(
        self, dbTo: PyDb.Database, dbFrom: PyDb.Database, id: PyDb.ObjectId, /
    ) -> None:  
    def beginWblockObjects(self, dbTo: PyDb.Database, idMap: PyDb.IdMapping, /) -> None:  
    def cmdIUnkModified(self, command: str, /) -> None:  
    def comandeered(
        self, dbTo: PyDb.Database, id: PyDb.ObjectId, dbFrom: PyDb.Database, /
    ) -> None:  
    def commandCancelled(self, cmdStr: str, /) -> None:  
    def commandEnded(self, cmdStr: str, /) -> None:  
    def commandFailed(self, cmdStr: str, /) -> None:  
    def commandWillStart(self, cmdStr: str, /) -> None:  
    def databaseConstructed(self, db: PyDb.Database, /) -> None:  
    def databaseToBeDestroyed(self, db: PyDb.Database, /) -> None:  
    def docCloseAborted(self, db: PyDb.Database, /) -> None:  
    def docCloseWillStart(self, db: PyDb.Database, /) -> None:  
    def docFrameMovedOrResized(self, hwndDocFrame: int, moved: bool, /) -> None:  
    def dwgViewResized(self, hwndDwgView: int, /) -> None:  
    def dxfInComplete(self, db: PyDb.Database, /) -> None:  
    def dxfOutComplete(self, db: PyDb.Database, /) -> None:  
    def endAttach(self, db: PyDb.Database, /) -> None:  
    def endDeepClone(self, idMap: PyDb.IdMapping, /) -> None:  
    def endDwgOpen(self, fineName: str, db: PyDb.Database, /) -> None:  
    def endInsert(self, db: PyDb.Database, /) -> None:  
    def endRestore(self, dbTo: PyDb.Database, /) -> None:  
    def endWblock(self, db: PyDb.Database, /) -> None:  
    def fullRegenEnded(self, db: PyDb.Database, regenedViewports: list[int], /) -> None:  
    def fullRegenWillStart(self, db: PyDb.Database, /) -> None:  
    def initialDwgFileOpenComplete(self, db: PyDb.Database, /) -> None:  
    def layoutSwitched(self, layoutName: str, /) -> None:  
    def layoutToBeSwitched(self, oldLayoutName: str, newLayoutName: str, /) -> None:  
    def lispCancelled(self, /) -> None:  
    def lispEnded(self, /) -> None:  
    def lispWillStart(self, val: str, /) -> None:  
    def mainFrameMovedOrResized(self, hwndDocFrame: int, moved: bool, /) -> None:  
    def modelessOperationEnded(self, context: str, /) -> None:  
    def modelessOperationWillStart(self, context: str, /) -> None:  
    def objectsLazyLoaded(self, ids: list[PyDb.ObjectId], /) -> None:  
    def otherAttach(self, dbTo: PyDb.Database, dbFrom: PyDb.Database, /) -> None:  
    def otherInsert(
        self, dbTo: PyDb.Database, idMap: PyDb.IdMapping, dbFrom: PyDb.Database, /
    ) -> None:  
    def otherWblock(
        self, dbTo: PyDb.Database, idMap: PyDb.IdMapping, dbFrom: PyDb.Database, /
    ) -> None:  
    def partialOpenNotice(self, db: PyDb.Database, /) -> None:  
    def pickfirstModified(self, /) -> None:  
    def preXrefLockFile(self, id: PyDb.ObjectId, /) -> None:  
    def quitAborted(self, /) -> None:  
    def quitWillStart(self, /) -> None:  
    def redirected(self, newId: PyDb.ObjectId, oldId: PyDb.ObjectId, /) -> None:  
    def removeReactor(self, /) -> None:  
    def saveComplete(self, db: PyDb.Database, fname: str, /) -> None:  
    def sysVarChanged(self, varName: str, success: bool, /) -> None:  
    def sysVarWillChange(self, varName: str, /) -> None:  
    def toolbarBitmapSizeChanged(self, large: bool, /) -> None:  
    def toolbarBitmapSizeWillChange(self, large: bool, /) -> None:  
    def undoSubcommandAuto(self, activity: int, state: bool, /) -> None:  
    def undoSubcommandBack(self, activity: int, /) -> None:  
    def undoSubcommandBegin(self, activity: int, /) -> None:  
    def undoSubcommandControl(self, activity: int, option: int, /) -> None:  
    def undoSubcommandEnd(self, activity: int, /) -> None:  
    def undoSubcommandMark(self, activity: int, /) -> None:  
    def undoSubcommandNumber(self, activity: int, num: int, /) -> None:  
    def veto(self, /) -> PyDb.ErrorStatus:  
    def viewChanged(self, /) -> None:  
    def wblockNotice(self, db: PyDb.Database, /) -> None:  
    def xrefSubcommandAttachItem(self, db: PyDb.Database, activity: int, path: str, /) -> None:  
    def xrefSubcommandBindItem(
        self, db: PyDb.Database, activity: int, blockId: PyDb.ObjectId, /
    ) -> None:  
    def xrefSubcommandDetachItem(
        self, db: PyDb.Database, activity: int, blockId: PyDb.ObjectId, /
    ) -> None:  
    def xrefSubcommandOverlayItem(
        self, db: PyDb.Database, activity: int, path: str, /
    ) -> None:  
    def xrefSubcommandPathItem(
        self, activity: int, blockId: PyDb.ObjectId, path: str, /
    ) -> None:  
    def xrefSubcommandReloadItem(
        self, db: PyDb.Database, activity: int, blockId: PyDb.ObjectId, /
    ) -> None:  
    def xrefSubcommandUnloadItem(
        self, db: PyDb.Database, activity: int, blockId: PyDb.ObjectId, /
    ) -> None:  

class InputPoint:
    def __init__(self) -> None:
    def alignmentPaths(self, /) -> list[PyGe.Curve]:  
    def cartesianSnappedPoint(self, /) -> PyGe.Point3d:  
    def computedPoint(self, /) -> PyGe.Point3d:  
    def document(self, /) -> PyAp.Document:  
    def drawContext(self, /) -> PyGi.ViewportDraw:  
    def grippedPoint(self, /) -> PyGe.Point3d:  
    def gsSelectionMark(self, /) -> list[int]:  
    def history(self, /) -> PointHistory:  
    def keyPointEntities(self, /) -> list[PyDb.ObjectId]:  
    def keyPointGsSelectionMark(self, /) -> list[int]:  
    def lastPoint(self, /) -> PyGe.Point3d:  
    def nestedKeyPointEntities(self, /) -> list[list[PyDb.ObjectId]]:  
    def nestedPickedEntities(self, /) -> list[list[PyDb.ObjectId]]:  
    def osnapMask(self, /) -> PyDb.OsnapMask:  
    def osnapOverrides(self, /) -> PyDb.OsnapMask:  
    def osnappedPoint(self, /) -> PyGe.Point3d:  
    def pickedEntities(self, /) -> list[PyDb.ObjectId]:  
    def pointComputed(self, /) -> bool:  
    def rawPoint(self, /) -> PyGe.Point3d:  
    def tooltipString(self, /) -> str:  

class InputPointFilter:
    def __init__(self, /) -> None:  
    def processInputPoint(
        self, input: PyEd.InputPoint, output: PyEd.InputPointFilterResult, /
    ) -> PyDb.ErrorStatus:  

class InputPointFilterResult:
    def __init__(self) -> None:
    def displayOsnapGlyph(self, /) -> bool:  
    def newPoint(self, /) -> PyGe.Point3d:  
    def newTooltipString(self, /) -> str:  
    def retry(self, /) -> bool:  
    def setDisplayOsnapGlyph(self, val: bool, /) -> None:  
    def setNewPoint(self, val: PyGe.Point3d, /) -> None:  
    def setNewTooltipString(self, val: str, /) -> None:  
    def setRetry(self, val: bool, /) -> None:  

class InputPointManager:
    def __init__(self) -> None:
    def addPointMonitor(self, monitor: PyEd.InputPointMonitor, /) -> None:  
    def disableSystemCursorGraphics(self, /) -> bool:  
    def enableMultiSubentPathSelection(self, /) -> None:  
    def enableSystemCursorGraphics(self, /) -> bool:  
    def forcedPickCount(self, /) -> int:  
    def hasFilter(self, /) -> bool:  
    def mouseHasMoved(self, /) -> int:  
    def registerPointFilter(self, filter: PyEd.InputPointFilter, /) -> None:  
    def removePointMonitor(self, monitor: PyEd.InputPointMonitor, /) -> None:  
    def revokePointFilter(self, /) -> None:  
    def systemCursorDisableCount(self, /) -> int:  
    def turnOffForcedPick(self, /) -> bool:  
    def turnOffSubentityWindowSelection(self, /) -> bool:  
    def turnOnSubentityWindowSelection(self, /) -> bool:  

class InputPointMonitor:
    def __init__(self, /) -> None:  
    def monitorInputPoint(
        self, input: PyEd.InputPoint, output: PyEd.InputPointMonitorResult, /
    ) -> PyDb.ErrorStatus:  

class InputPointMonitorResult:
    def __init__(self) -> None:
    def additionalTooltipString(self, /) -> str:  
    def appendToTooltipStr(self, /) -> bool:  
    def setAdditionalTooltipString(self, val: str, /) -> None:  

class Jig:
    def __init__(self, entity: PyDb.Entity, /) -> None:  
    def acquireAngle(self, basePnt: PyGe.Point3d =  , /) -> tuple[PyEd.DragStatus, float]:  
    def acquireDist(self, basePnt: PyGe.Point3d =  , /) -> tuple[PyEd.DragStatus, float]:  
    def acquirePoint(
        self, basePnt: PyGe.Point3d =  , /
    ) -> tuple[PyEd.DragStatus, PyGe.Point3d]:  
    def acquireString(self, /) -> tuple[PyEd.DragStatus, str]:  
    def append(self, /) -> PyDb.ObjectId:  
    @staticmethod
    def className() -> str:  
    def dispPrompt(self, /) -> str:  
    def drag(self, style: PyEd.DragStyle =  , /) -> DragStatus:  
    def keywordList(self, /) -> str:  
    def sampler(self, /) -> DragStatus:  
    def setDispPrompt(self, val: str, /) -> None:  
    def setKeywordList(self, val: str, /) -> None:  
    def setSpecialCursorType(self, val: PyEd.CursorType, /) -> None:  
    def setUserInputControls(self, val: PyEd.UserInputControls, /) -> None:  
    def specialCursorType(self, /) -> CursorType:  
    def update(self, /) -> bool:  
    def userInputControls(self, /) -> UserInputControls:  

class PointHistory(_BoostPythonEnum):
    eTablet: ClassVar[Self]  # 1
    eNotDigitizer: ClassVar[Self]  # 2
    eLastPt: ClassVar[Self]  # 4
    eGripped: ClassVar[Self]  # 8
    eCartSnapped: ClassVar[Self]  # 16
    eOrtho: ClassVar[Self]  # 32
    eCyclingPt: ClassVar[Self]  # 64
    eOsnapped: ClassVar[Self]  # 128
    ePolarAngle: ClassVar[Self]  # 256
    eAligned: ClassVar[Self]  # 1024
    eAppFiltered: ClassVar[Self]  # 2048
    eForcedPick: ClassVar[Self]  # 4096
    ePickMask: ClassVar[Self]  # 57344
    eDidNotPick: ClassVar[Self]  # 0
    eUsedPickBox: ClassVar[Self]  # 8192
    eUsedOsnapBox: ClassVar[Self]  # 16384
    ePickAborted: ClassVar[Self]  # 32768
    eXPending: ClassVar[Self]  # 65536
    eYPending: ClassVar[Self]  # 131072
    eZPending: ClassVar[Self]  # 262144
    eCoordPending: ClassVar[Self]  # 458752
    eFromKeyboard: ClassVar[Self]  # 524288
    eNotInteractive: ClassVar[Self]  # 1048576
    eDirectDistance: ClassVar[Self]  # 2097152
    eGizmoConstrainted: ClassVar[Self]  # 4194304

class PromptCondition(_BoostPythonEnum):
    eNone: ClassVar[Self]  # 0
    eNoZero: ClassVar[Self]  # 1
    eNoEmpty: ClassVar[Self]  # 1
    eNoNegative: ClassVar[Self]  # 2

class PromptStatus(_BoostPythonEnum):
    eNone: ClassVar[Self]  # 5000
    eModeless: ClassVar[Self]  # 5027
    eNormal: ClassVar[Self]  # 5100
    kNormal: ClassVar[Self]  # 5100
    eOk: ClassVar[Self]  # 5100
    eError: ClassVar[Self]  # -5001
    eCancel: ClassVar[Self]  # -5002
    eRejected: ClassVar[Self]  # -5003
    eFailed: ClassVar[Self]  # -5004
    eKeyword: ClassVar[Self]  # -5005
    eDirect: ClassVar[Self]  # -5999

class SelectionSet:
    def __init__(self, /) -> None:  
    def __iter__(self, /) -> Iterator[PyDb.ObjectId]:  
    def add(self, id: PyDb.ObjectId, /) -> None:  
    def adsname(self, /) -> PyDb.AdsName:  
    def clear(self, /) -> None:  
    def hasMember(self, id: PyDb.ObjectId, /) -> bool:  
    def isInitialized(self, /) -> bool:  
    def keepAlive(self, flag: bool, /) -> None:  
    @overload
    def objectIdArray(self, desc: PyRx.RxClass = PyDb.Entity, /) -> PyDb.ObjectIdArray:  
    @overload
    def objectIdArray(self, descList: list[PyRx.RxClass], /) -> PyDb.ObjectIdArray:  
    @overload
    def objectIdArray(self, *args) -> PyDb.ObjectIdArray:  
    @overload
    def objectIds(self, desc: PyRx.RxClass = PyDb.Entity, /) -> list[PyDb.ObjectId]:  
    @overload
    def objectIds(self, descList: list[PyRx.RxClass], /) -> list[PyDb.ObjectId]:  
    @overload
    def objectIds(self, *args) -> list[PyDb.ObjectId]:  
    def remove(self, id: PyDb.ObjectId, /) -> None:  
    def size(self, /) -> int:  
    def ssNameX(self, val: int = 0, /) -> list:  
    def ssSetFirst(self, /) -> bool:  
    def ssXform(self, xform: PyGe.Matrix3d, /) -> PromptStatus:  
    def toList(self, /) -> list[PyDb.ObjectId]:  

class UIContext:
    def OnUpdateMenu(self, /) -> None:  
    def __init__(self, /) -> None:  
    @staticmethod
    def addDefaultContextMenu(context: PyEd.UIContext, appName: str =  , /) -> bool:  
    @staticmethod
    def addObjectContextMenu(val: PyRx.RxClass, context: PyEd.UIContext, /) -> bool:  
    def getMenuContext(self, val: PyRx.RxClass, ids: list[PyDb.ObjectId], /) -> object:  
    def hitPoint(self, /) -> PyGe.Point3d:  
    def onCommand(self, mnuCmd: int, /) -> None:  
    @staticmethod
    def removeDefaultContextMenu(context: PyEd.UIContext, /) -> bool:  
    @staticmethod
    def removeObjectContextMenu(val: PyRx.RxClass, context: PyEd.UIContext, /) -> bool:  

class UserInputControls(_BoostPythonEnum):
    kGovernedByOrthoMode: ClassVar[Self]  # 1
    kNullResponseAccepted: ClassVar[Self]  # 2
    kDontEchoCancelForCtrlC: ClassVar[Self]  # 4
    kDontUpdateLastPoint: ClassVar[Self]  # 8
    kNoDwgLimitsChecking: ClassVar[Self]  # 16
    kNoZeroResponseAccepted: ClassVar[Self]  # 32
    kNoNegativeResponseAccepted: ClassVar[Self]  # 64
    kAccept3dCoordinates: ClassVar[Self]  # 128
    kAcceptMouseUpAsPoint: ClassVar[Self]  # 256
    kAnyBlankTerminatesInput: ClassVar[Self]  # 512
    kInitialBlankTerminatesInput: ClassVar[Self]  # 1024
    kAcceptOtherInputString: ClassVar[Self]  # 2048
    kGovernedByUCSDetect: ClassVar[Self]  # 4096
    kNoZDirectionOrtho: ClassVar[Self]  # 8192
    kImpliedFaceForUCSChange: ClassVar[Self]  # 16384
    kUseBasePointElevation: ClassVar[Self]  # 32768
    kDisableDirectDistanceInput: ClassVar[Self]  # 65536

class UserInteraction:
    def __init__(self, doc: PyAp.Document = "current", isPrompting: bool = True, /) -> None:  

class Util:
    def __init__(self, /) -> None:  
    @staticmethod
    def angle(pt1: PyGe.Point3d, pt2: PyGe.Point3d, /) -> float:  
    @staticmethod
    def cvUnit(val: float, oldunit: str, newunit: str, /) -> float:  
    @staticmethod
    def distance(pt1: PyGe.Point3d, pt2: PyGe.Point3d, /) -> float:  
    @staticmethod
    def polar(pt1: PyGe.Point3d, angle: float, dist: float, /) -> PyGe.Point3d:  
    @staticmethod
    def wcMatch(string: str, pattern: str, ignoreCase: bool, /) -> bool:  

def print(*args) -> None:
```
