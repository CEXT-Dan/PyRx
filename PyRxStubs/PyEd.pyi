import PyRx
import PyGe
import PyGi
import PyGs
import PyDb
import PyAp
import PyEd
import PyPl
from typing import overload

class AutoSysVar(object):
    def __init__ (self, varname:str, value)-> None :
      '''                             '''
    ...
    def detach (self, *args, **kwargs)-> None :
      '''detach( (AutoSysVar)arg1, (bool)arg2) -> None :

    C++ signature :
        void detach(class PySysVar {lvalue},bool)'''
    ...

class Core(object):
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...

    @staticmethod
    def alert (msg: str)-> int :
      '''                             '''
    ...

    @staticmethod
    def arxLoad (path: str)-> int :
      '''                             '''
    ...

    @staticmethod
    def arxLoaded ()-> list :
      '''                             '''
    ...

    @staticmethod
    def arxUnload (app: str)-> int :
      '''                             '''
    ...

    @staticmethod
    def audit (db: PyDb.Database,fix: bool,echo: bool=False)-> None :
      '''                             '''
    ...

    @staticmethod
    def autoSetVar (name:str,value)-> PyEd.AutoSysVar :
      '''                             '''
    ...

    @staticmethod
    def callBackOnCancel ()-> None :
      '''                             '''
    ...

    @staticmethod
    def clearOLELock (handle: int)-> bool :
      '''                             '''
    ...

    @staticmethod
    def clipFormatName ()-> str :
      '''                             '''
    ...

    @staticmethod
    def cmdCWasCancelled ()-> bool :
      '''                             '''
    ...

    @staticmethod
    def cmdS (resultBuffer: list)-> bool :
      '''                             '''
    ...

    @staticmethod
    def cmdUndefine (name: str,undefineit: int)-> int :
      '''                             '''
    ...

    @staticmethod
    def coordFromPixelToWorld (windnum: int = 'None',pt: tuple[int,int])-> PyGe.Point3d :
      '''                             '''
    ...

    @staticmethod
    def coordFromWorldToPixel (windnum: int ,pnt: PyGe.Point3d)-> tuple :
      '''                             '''
    ...

    @staticmethod
    def createInternetShortcut (szURL: str,szShortcutPath: str)-> bool :
      '''                             '''
    ...

    @staticmethod
    def createViewportByView (db: PyDb.Database,view: PyDb.ObjectId,pt: PyGe.Point2d,scale: float)-> PyDb.ObjectId :
      '''                             '''
    ...

    @staticmethod
    def defun (name: str,funcnumber: int)-> int :
      '''                             '''
    ...

    @staticmethod
    def defunEx (global: str,name: str,funcnumber: int)-> int :
      '''                             '''
    ...

    @staticmethod
    def disableDefaultARXExceptionHandler (val: bool)-> None :
      '''                             '''
    ...

    @staticmethod
    def disableUsrbrk ()-> None :
      '''                             '''
    ...

    @staticmethod
    def displayBorder (val: bool)-> bool :
      '''                             '''
    ...

    @staticmethod
    def drawOrderInherit (parent: PyDb.ObjectId,childids: list[PyDb.ObjectId],cmd: PyEd.DrawOrderCmdType)-> None :
      '''                             '''
    ...

    @staticmethod
    def drawingStatusBarsVisible ()-> bool :
      '''                             '''
    ...

    @staticmethod
    def dropOpenFile (val: str)-> None :
      '''                             '''
    ...

    @staticmethod
    def eatCommandThroat ()-> int :
      '''                             '''
    ...

    @staticmethod
    def editMTextInteractive (mt: PyDb.MText,usenewUI: bool,allowTabs: bool)-> int :
      '''                             '''
    ...

    @staticmethod
    def enableUsrbrk ()-> None :
      '''                             '''
    ...

    @staticmethod
    def evaluateDiesel (statement : str)-> str :
      '''                             '''
    ...

    @staticmethod
    def evaluateLisp (statement : str)-> list :
      '''                             '''
    ...

    @staticmethod
    def findFile (fname: str)-> str :
      '''                             '''
    ...

    @staticmethod
    def findTrustedFile (fname: str)-> str :
      '''                             '''
    ...

    @staticmethod
    def getAcadDockCmdLine ()-> int :
      '''                             '''
    ...

    @staticmethod
    def getAcadTextCmdLine ()-> int :
      '''                             '''
    ...

    @staticmethod
    def getBlockEditMode ()-> int :
      '''                             '''
    ...

    @staticmethod
    def getCfg (val: str)-> str :
      '''                             '''
    ...

    @staticmethod
    def getCommandForDocument (doc: PyAp.Document)-> str :
      '''                             '''
    ...

    @staticmethod
    def getCommandPromptString ()-> str :
      '''                             '''
    ...

    @staticmethod
    def getCommands ()-> dict :
      '''                             '''
    ...

    @staticmethod
    def getCurVportPixelToDisplay ()-> tuple :
      '''                             '''
    ...

    @staticmethod
    def getCurVportScreenToDisplay ()-> tuple :
      '''                             '''
    ...

    @staticmethod
    def getCurrentSelectionSet ()-> list :
      '''                             '''
    ...

    @staticmethod
    def getDpiScalingValue ()-> float :
      '''                             '''
    ...

    @staticmethod
    def getEnv (val: str)-> str :
      '''                             '''
    ...

    @staticmethod
    def getFileD (title: str,defawlt: str,ext: str,flags: int)-> str :
      '''                             '''
    ...

    @staticmethod
    def getFileNavDialog (title: str,defawlt: str,ext: str,dlgname: str,flags: int)-> list :
      '''                             '''
    ...

    @staticmethod
    def getLastCommandLines (lineCount: int,ignoreNull: bool)-> list :
      '''                             '''
    ...

    @staticmethod
    def getMousePositionUCS ()-> PyGe.Point3d :
      '''                             '''
    ...

    @staticmethod
    def getMousePositionWCS ()-> PyGe.Point3d :
      '''                             '''
    ...

    @staticmethod
    def getPredefinedHatchPatterns ()-> list :
      '''                             '''
    ...

    @staticmethod
    def getRGB (colorIndex : int)-> tuple :
      '''                             '''
    ...

    @staticmethod
    def getSym (val: str)-> list :
      '''                             '''
    ...

    @staticmethod
    def getSysVars ()-> dict :
      '''                             '''
    ...

    @staticmethod
    def getUserFavoritesDir ()-> str :
      '''                             '''
    ...

    @staticmethod
    def getVar (name:str)-> object :
      '''                             '''
    ...

    @staticmethod
    def getWinNum (ptx: int,pty: int)-> int :
      '''                             '''
    ...

    @staticmethod
    def grDraw (pt1: PyGe.Point2d|PyGe.Point3d,pt2: PyGe.Point2d|PyGe.Point3d,color: int,highlight: int)-> int :
      '''                             '''
    ...

    @staticmethod
    def graphScr ()-> None :
      '''                             '''
    ...

    @staticmethod
    def hatchPalletteDialog (pattern:str,custom : bool)-> str :
      '''                             '''
    ...

    @staticmethod
    def initDialog (useDialog: bool)-> bool :
      '''                             '''
    ...

    @staticmethod
    def invoke (resultBuffer: list)-> list :
      '''                             '''
    ...

    @staticmethod
    def isDragging ()-> int :
      '''                             '''
    ...

    @staticmethod
    def isInBackgroundMode ()-> bool :
      '''                             '''
    ...

    @staticmethod
    def isInputPending ()-> bool :
      '''                             '''
    ...

    @staticmethod
    def isMenuGroupLoaded (mnu: str)-> bool :
      '''                             '''
    ...

    @staticmethod
    def isOsnapOverride ()-> bool :
      '''                             '''
    ...

    @staticmethod
    def isUpdateDisplayPaused ()-> bool :
      '''                             '''
    ...

    @staticmethod
    def isUsrbrkDisabled ()-> bool :
      '''                             '''
    ...

    @staticmethod
    def loadJSScript (scr: str)-> None :
      '''                             '''
    ...

    @staticmethod
    def loadMainMenu (mnu: str)-> bool :
      '''                             '''
    ...

    @staticmethod
    def loadPartialMenu (mnu: str)-> bool :
      '''                             '''
    ...

    @staticmethod
    def mSpace ()-> None :
      '''                             '''
    ...

    @staticmethod
    def markForDelayXRefRelativePathResolve (id: PyDb.ObjectId)-> None :
      '''                             '''
    ...

    @staticmethod
    def osnap (pt: AcGe.Point3d,mode: str)-> PyGe.Point3d :
      '''                             '''
    ...

    @staticmethod
    def pSpace ()-> None :
      '''                             '''
    ...

    @staticmethod
    def postCommand (str: str)-> None :
      '''                             '''
    ...

    @staticmethod
    def postCommandPrompt ()-> None :
      '''                             '''
    ...

    @staticmethod
    def prompt (val: str)-> int :
      '''                             '''
    ...

    @staticmethod
    def putSym (sym: str,resultBuffer: list)-> bool :
      '''                             '''
    ...

    @staticmethod
    def redraw (id: PyDb.ObjectId,mode: int)-> int :
      '''                             '''
    ...

    @staticmethod
    def regen ()-> None :
      '''                             '''
    ...

    @staticmethod
    def reloadMenus (bIncrementalReloading: bool)-> None :
      '''                             '''
    ...

    @staticmethod
    def restoreCurrentView (vid: PyDb.ObjectId)-> None :
      '''                             '''
    ...

    @staticmethod
    def restorePreviousUCS ()-> None :
      '''                             '''
    ...

    @staticmethod
    def restoreStatusBar ()-> None :
      '''                             '''
    ...

    @staticmethod
    def sendModelessOperationEnded (ctx: str)-> None :
      '''                             '''
    ...

    @staticmethod
    def sendModelessOperationStart (ctx: str)-> None :
      '''                             '''
    ...

    @staticmethod
    def setCfg (sym: str,val: str)-> None :
      '''                             '''
    ...

    @staticmethod
    def setColorDialog (clr: int,bAllowMetaColor: bool,nCurLayerColor, int)-> tuple :
      '''                             '''
    ...

    @staticmethod
    def setColorDialogTrueColor (clr: PyDb.AcCmColor,bAllowMetaColor: bool,bAllowMetaColor: bool,nCurLayerColor: PyDb.AcCmColor,tab: int = 7)-> tuple :
      '''                             '''
    ...

    @staticmethod
    def setCurrentVPort (vp: PyDb.Viewport)-> None :
      '''                             '''
    ...

    @staticmethod
    def setCurrentView (vrec: PyDb.ViewTableRecord,vp: PyDb.Viewport)-> None :
      '''                             '''
    ...

    @staticmethod
    def setEnv (sym: str,val: str)-> None :
      '''                             '''
    ...

    @staticmethod
    def setFieldUpdateEnabled (doc: PyAp.Document,enabled: bool)-> None :
      '''                             '''
    ...

    @staticmethod
    def setFunHelp (functionName: str,helpfile: str,topic: str,iCmd: int)-> int :
      '''                             '''
    ...

    @staticmethod
    def setStatusBarProgressMeter (lable: str,nMinPos: int,nMaxPos: int)-> int :
      '''                             '''
    ...

    @staticmethod
    def setStatusBarProgressMeterPos (pos: int)-> int :
      '''                             '''
    ...

    @staticmethod
    def setUndoMark (flag: bool)-> None :
      '''                             '''
    ...

    @staticmethod
    def setVar (name:str,value)-> bool :
      '''                             '''
    ...

    @staticmethod
    def setXrefResolvedWithUpdateStatus (rec: PyDb.BlockTableRecord)-> None :
      '''                             '''
    ...

    @staticmethod
    def showHTMLModalWindow (hwnd: int,val: uriOfHtmlPage,persistSizeAndPosition: bool=True)-> bool :
      '''                             '''
    ...

    @staticmethod
    def showHTMLModelessWindow (hwnd: int,val: uriOfHtmlPage,persistSizeAndPosition: bool=True)-> int :
      '''                             '''
    ...

    @staticmethod
    def skipXrefNotification (db: PyDb.Database,name: str)-> None :
      '''                             '''
    ...

    @staticmethod
    def textBox (resultBuffer: list)-> tuple :
      '''                             '''
    ...

    @staticmethod
    def textPage ()-> None :
      '''                             '''
    ...

    @staticmethod
    def textScr ()-> None :
      '''                             '''
    ...

    @staticmethod
    def trans (pt: PyGe.Point3d,rbFrom: tuple,rbTo: tuple,disp: bool)-> PyGe.Point3d :
      '''                             '''
    ...

    @staticmethod
    def unloadPartialMenu (mnu: str)-> bool :
      '''                             '''
    ...

    @staticmethod
    def unmarkForDelayXRefRelativePathResolve (id: PyDb.ObjectId)-> None :
      '''                             '''
    ...

    @staticmethod
    def update (vport: int,pt1: PyGe.Point2d,pt2: PyGe.Point2d)-> int :
      '''                             '''
    ...

    @staticmethod
    def updateDisplay ()-> None :
      '''                             '''
    ...

    @staticmethod
    def updateDisplayPause (val: bool)-> None :
      '''                             '''
    ...

    @staticmethod
    def usrBrk ()-> bool :
      '''                             '''
    ...

    @staticmethod
    def viewportIdFromNumber (val: int)-> PyDb.ObjectId :
      '''                             '''
    ...

    @staticmethod
    def vpLayer (id: PyDb.ObjectId,layerIds: list[PyDb.ObjectId],operation: PyDb.VpFreezeOps)-> None :
      '''                             '''
    ...

    @staticmethod
    def vportTableRecords2Vports ()-> None :
      '''                             '''
    ...

    @staticmethod
    def vports ()-> list :
      '''                             '''
    ...

    @staticmethod
    def vports2VportTableRecords ()-> None :
      '''                             '''
    ...

    @staticmethod
    def xrefAttach ()-> None :
      '''Overloads:
    - path: str, name: str
    - path: str, name: str, btrid: PyDb.ObjectId, refid: PyDb.ObjectId, pt: PyGe.Point3d, sc: PyGe.Scale3d, rot: float, bQuiet: bool, pHostDb: PyDb.Database, passwd: str
    '''
    ...

    @staticmethod
    def xrefBind (db: PyDb.Database,bQuiet: bool=True)-> None :
      '''Overloads:
    - XrefBlockname: str
    - XrefBlockname: str, bQuiet: bool, pHostDb: PyDb.Database
    '''
    ...

    @staticmethod
    def xrefCreateBlockname (XrefPathname: str)-> str :
      '''                             '''
    ...

    @staticmethod
    def xrefDetach (XrefPathname: str)-> None :
      '''Overloads:
    - XrefBlockname: str
    - XrefBlockname: str, bQuiet: bool, pHostDb: PyDb.Database
    '''
    ...

    @staticmethod
    def xrefNotifyCheckFileChanged (id: PyDb.ObjectId)-> bool :
      '''                             '''
    ...

    @staticmethod
    def xrefOverlay (id: PyDb.ObjectId)-> None :
      '''Overloads:
    - path: str, name: str
    - path: str, name: str, btrid: PyDb.ObjectId, refid: PyDb.ObjectId, pt: PyGe.Point3d, sc: PyGe.Scale3d, rot: float, bQuiet: bool, pHostDb: PyDb.Database, passwd: str
    '''
    ...

    @staticmethod
    def xrefReload (id: PyDb.ObjectId)-> None :
      '''Overloads:
    - path: str, name: str
    - path: str, name: str, btrid: PyDb.ObjectId, refid: PyDb.ObjectId, pt: PyGe.Point3d, sc: PyGe.Scale3d, rot: float, bQuiet: bool, pHostDb: PyDb.Database, passwd: str
    '''
    ...

    @staticmethod
    def xrefResolve (db: PyDb.Database,bQuiet: bool=True)-> None :
      '''                             '''
    ...

    @staticmethod
    def xrefUnload (db: PyDb.Database,bQuiet: bool=True)-> None :
      '''Overloads:
    - XrefBlockname: str
    - XrefBlockname: str, bQuiet: bool, pHostDb: PyDb.Database
    '''
    ...

    @staticmethod
    def xrefXBind (db: PyDb.Database,bQuiet: bool=True)-> None :
      '''Overloads:
    - XrefBlockname: str
    - XrefBlockname: str, bQuiet: bool, pHostDb: PyDb.Database
    '''
    ...

class CursorType(object):
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def kCrosshair (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kCrosshairDashed (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kCrosshairNoRotate (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kEntitySelect (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kEntitySelectNoPersp (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kInvisible (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kNoSpecialCursor (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kNotRotated (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kParallelogram (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kPkfirstOrGrips (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kRectCursor (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kRotatedCrosshair (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kRubberBand (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kTargetBox (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class DragStatus(object):
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def eNormal (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def eOk (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kCancel (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kKW1 (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kKW2 (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kKW3 (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kKW4 (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kKW5 (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kKW6 (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kKW7 (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kKW8 (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kKW9 (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kModeless (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kNoChange (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kNormal (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kNull (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kOther (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class DragStyle(object):
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (DragStyleType)arg2, (DragStyleType)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,enum AcEdDragStyle::StyleType,enum AcEdDragStyle::StyleType)'''
    ...
    def setStyleTypeForDragged (self, *args, **kwargs)-> PyDb.ErrorStatus :
      '''setStyleTypeForDragged( (DragStyle)arg1, (DragStyleType)arg2) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus setStyleTypeForDragged(class AcEdDragStyle {lvalue},enum AcEdDragStyle::StyleType)'''
    ...
    def setStyleTypeForOriginal (self, *args, **kwargs)-> PyDb.ErrorStatus :
      '''setStyleTypeForOriginal( (DragStyle)arg1, (DragStyleType)arg2) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus setStyleTypeForOriginal(class AcEdDragStyle {lvalue},enum AcEdDragStyle::StyleType)'''
    ...
    def styleTypeForDragged (self, *args, **kwargs)-> PyEd.DragStyleType :
      '''styleTypeForDragged( (DragStyle)arg1) -> DragStyleType :

    C++ signature :
        enum AcEdDragStyle::StyleType styleTypeForDragged(class AcEdDragStyle {lvalue})'''
    ...
    def styleTypeForOriginal (self, *args, **kwargs)-> PyEd.DragStyleType :
      '''styleTypeForOriginal( (DragStyle)arg1) -> DragStyleType :

    C++ signature :
        enum AcEdDragStyle::StyleType styleTypeForOriginal(class AcEdDragStyle {lvalue})'''
    ...

class DragStyleType(object):
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def kDeletedEffect (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kHide (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kHighlight (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kNone (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kNotSet (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kTransparent25 (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kTransparent75 (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class DrawJig(object):
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...
    def acquireAngle (self, basePnt: PyGe.Point3d=None)-> tuple :
      '''                             '''
    ...
    def acquireDist (self, basePnt: PyGe.Point3d=None)-> tuple :
      '''                             '''
    ...
    def acquirePoint (self, basePnt: PyGe.Point3d=None)-> tuple :
      '''                             '''
    ...
    def acquireString (self)-> tuple :
      '''                             '''
    ...

    @staticmethod
    def className ()-> str :
      '''                             '''
    ...
    def dispPrompt (self)-> str :
      '''                             '''
    ...
    def drag (self, style: PyEd.DragStyle=None)-> PyEd.DragStatus :
      '''                             '''
    ...
    def keywordList (self)-> str :
      '''                             '''
    ...
    def sampler (self)-> PyEd.DragStatus :
      '''                             '''
    ...
    def setDispPrompt (self, val: str)-> None :
      '''                             '''
    ...
    def setKeywordList (self, val: str)-> None :
      '''                             '''
    ...
    def setSpecialCursorType (self, val: PyEd.CursorType)-> None :
      '''                             '''
    ...
    def setUserInputControls (self, val:  PyEd.UserInputControls)-> None :
      '''                             '''
    ...
    def specialCursorType (self)-> PyEd.CursorType :
      '''                             '''
    ...
    def update (self)-> bool :
      '''                             '''
    ...
    def userInputControls (self)-> PyEd.UserInputControls :
      '''                             '''
    ...
    def viewportDraw (self, wd: PyGi.ViewportDraw)-> None :
      '''                             '''
    ...
    def worldDraw (self, wd: PyGi.WorldDraw)-> bool :
      '''                             '''
    ...

class DrawOrderCmdType(object):
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def kDrawOrderAbove (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kDrawOrderBelow (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kDrawOrderBottom (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kDrawOrderNone (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kDrawOrderTop (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class Editor(object):
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...
    def activeViewportId (self, *args, **kwargs)-> PyDb.ObjectId :
      '''activeViewportId() -> ObjectId :

    C++ signature :
        class PyDbObjectId activeViewportId()'''
    ...

    @staticmethod
    def className ()-> str :
      '''                             '''
    ...
    def curViewportObjectId (self, *args, **kwargs)-> PyDb.ObjectId :
      '''curViewportObjectId() -> ObjectId :

    C++ signature :
        class PyDbObjectId curViewportObjectId()'''
    ...

    @staticmethod
    def duplicateSelectionsAllowed (doc: PyAp.Document)-> bool :
      '''                             '''
    ...

    @staticmethod
    def entSel (prompt: str,desc: PyRx.RxClass=PyDb.Entity)-> tuple :
      '''                             '''
    ...

    @staticmethod
    def getAngle (basePt: PyGe.Point3d,prompt: str)-> tuple :
      '''                             '''
    ...

    @staticmethod
    def getCorner (basePt: PyGe.Point3d,prompt: str)-> tuple :
      '''                             '''
    ...

    @staticmethod
    def getCurrentSelectionSet ()-> list :
      '''                             '''
    ...

    @staticmethod
    def getCurrentUCS ()-> PyGe.Matrix3d :
      '''                             '''
    ...

    @staticmethod
    def getDist (basePt: PyGe.Point3d='None',prompt: str)-> tuple :
      '''                             '''
    ...

    @staticmethod
    def getDouble (prompt: str)-> tuple :
      '''                             '''
    ...

    @staticmethod
    def getInteger (prompt: str)-> tuple :
      '''                             '''
    ...

    @staticmethod
    def getKword (keyword: str)-> tuple :
      '''                             '''
    ...

    @staticmethod
    def getPoint (basePt: PyGe.Point3d='None',prompt: str)-> tuple :
      '''                             '''
    ...

    @staticmethod
    def getReal (prompt: str)-> tuple :
      '''                             '''
    ...

    @staticmethod
    def getString (cronly: int,prompt: str)-> tuple :
      '''                             '''
    ...

    @staticmethod
    def getViewportNumber (ptx: int,pty: int)-> int :
      '''                             '''
    ...

    @staticmethod
    def initGet (val: int,keyword: str)-> PyEd.PromptStatus :
      '''                             '''
    ...

    @staticmethod
    def nEntSelP (prompt: str,selpt: PyGe.Point3d='None')-> tuple :
      '''                             '''
    ...

    @staticmethod
    def nEntSelPEx (prompt: str,selpt: PyGe.Point3d='None',flags: int)-> tuple :
      '''                             '''
    ...

    @staticmethod
    def regen ()-> None :
      '''                             '''
    ...

    @staticmethod
    def select (filer: list='None')-> tuple :
      '''                             '''
    ...

    @staticmethod
    def selectAll (filer: list='None')-> tuple :
      '''                             '''
    ...

    @staticmethod
    def selectFence (points: list[PyGe.Point3d],filer: list='None')-> tuple :
      '''                             '''
    ...

    @staticmethod
    def selectLast (filer: list='None')-> tuple :
      '''                             '''
    ...

    @staticmethod
    def selectPrevious (filer: list='None')-> tuple :
      '''                             '''
    ...

    @staticmethod
    def selectPrompt (addPromt: str,remPromt: str,filer: list='None')-> tuple :
      '''                             '''
    ...

    @staticmethod
    def selectWindow (pt1: PyGe.Point3d,pt2: PyGe.Point3d,filer: list='None')-> tuple :
      '''                             '''
    ...

    @staticmethod
    def selectWindowPolygon (points: list[PyGe.Point3d],filer: list='None')-> tuple :
      '''                             '''
    ...

    @staticmethod
    def setAllowDuplicateSelection (doc: PyAp.Document,flag: bool)-> None :
      '''                             '''
    ...

    @staticmethod
    def setCurrentUCS (ucs: PyGe.Matrix3d)-> None :
      '''                             '''
    ...

    @staticmethod
    def ssget (mode: str,arg1: any,arg2: any,filer: list='None')-> tuple :
      '''                             '''
    ...

    @staticmethod
    def traceBoundary (point: PyGe.Point3d,detectIslands: bool)-> list :
      '''                             '''
    ...

    @staticmethod
    def ucsNormalVector ()-> PyGe.Vector3d :
      '''                             '''
    ...

    @staticmethod
    def ucsXDir ()-> PyGe.Vector3d :
      '''                             '''
    ...

    @staticmethod
    def ucsYDir ()-> PyGe.Vector3d :
      '''                             '''
    ...

class EditorReactor(object):
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...
    def abortAttach (self, *args, **kwargs)-> None :
      '''abortAttach( (EditorReactor)arg1, (Database)arg2) -> None :

    C++ signature :
        void abortAttach(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def abortDeepClone (self, *args, **kwargs)-> None :
      '''abortDeepClone( (EditorReactor)arg1, (IdMapping)arg2) -> None :

    C++ signature :
        void abortDeepClone(class PyEditorReactor {lvalue},class PyDbIdMapping {lvalue})'''
    ...
    def abortDxfIn (self, *args, **kwargs)-> None :
      '''abortDxfIn( (EditorReactor)arg1, (Database)arg2) -> None :

    C++ signature :
        void abortDxfIn(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def abortDxfOut (self, *args, **kwargs)-> None :
      '''abortDxfOut( (EditorReactor)arg1, (Database)arg2) -> None :

    C++ signature :
        void abortDxfOut(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def abortInsert (self, *args, **kwargs)-> None :
      '''abortInsert( (EditorReactor)arg1, (Database)arg2) -> None :

    C++ signature :
        void abortInsert(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def abortRestore (self, *args, **kwargs)-> None :
      '''abortRestore( (EditorReactor)arg1, (Database)arg2) -> None :

    C++ signature :
        void abortRestore(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def abortSave (self, *args, **kwargs)-> None :
      '''abortSave( (EditorReactor)arg1, (Database)arg2) -> None :

    C++ signature :
        void abortSave(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def abortWblock (self, *args, **kwargs)-> None :
      '''abortWblock( (EditorReactor)arg1, (Database)arg2) -> None :

    C++ signature :
        void abortWblock(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def addReactor (self, *args, **kwargs)-> None :
      '''addReactor( (EditorReactor)arg1) -> None :

    C++ signature :
        void addReactor(class PyEditorReactor {lvalue})'''
    ...
    def beginAttach (self, *args, **kwargs)-> None :
      '''beginAttach( (EditorReactor)arg1, (Database)arg2, (str)arg3, (Database)arg4) -> None :

    C++ signature :
        void beginAttach(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class PyDbDatabase {lvalue})'''
    ...
    def beginCloseAll (self, *args, **kwargs)-> None :
      '''beginCloseAll( (EditorReactor)arg1) -> None :

    C++ signature :
        void beginCloseAll(class PyEditorReactor {lvalue})'''
    ...
    def beginDeepClone (self, *args, **kwargs)-> None :
      '''beginDeepClone( (EditorReactor)arg1, (Database)arg2, (IdMapping)arg3) -> None :

    C++ signature :
        void beginDeepClone(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue},class PyDbIdMapping {lvalue})'''
    ...
    def beginDeepCloneXlation (self, *args, **kwargs)-> PyDb.ErrorStatus :
      '''beginDeepCloneXlation( (EditorReactor)arg1, (IdMapping)arg2) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus beginDeepCloneXlation(class PyEditorReactor {lvalue},class PyDbIdMapping {lvalue})'''
    ...
    def beginDocClose (self, *args, **kwargs)-> None :
      '''beginDocClose( (EditorReactor)arg1, (Database)arg2) -> None :

    C++ signature :
        void beginDocClose(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def beginDoubleClick (self, *args, **kwargs)-> None :
      '''beginDoubleClick( (EditorReactor)arg1, (Point3d)arg2) -> None :

    C++ signature :
        void beginDoubleClick(class PyEditorReactor {lvalue},class AcGePoint3d)'''
    ...
    def beginDwgOpen (self, *args, **kwargs)-> None :
      '''beginDwgOpen( (EditorReactor)arg1, (str)arg2) -> None :

    C++ signature :
        void beginDwgOpen(class PyEditorReactor {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def beginDxfIn (self, *args, **kwargs)-> None :
      '''beginDxfIn( (EditorReactor)arg1, (Database)arg2) -> None :

    C++ signature :
        void beginDxfIn(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def beginDxfOut (self, *args, **kwargs)-> None :
      '''beginDxfOut( (EditorReactor)arg1, (Database)arg2) -> None :

    C++ signature :
        void beginDxfOut(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def beginInsert (self, *args, **kwargs)-> None :
      '''beginInsert( (EditorReactor)arg1, (Database)arg2, (str)arg3, (Database)arg4) -> None :

    C++ signature :
        void beginInsert(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class PyDbDatabase {lvalue})

beginInsert( (EditorReactor)arg1, (Database)arg2, (Matrix3d)arg3, (Database)arg4) -> None :

    C++ signature :
        void beginInsert(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue},class AcGeMatrix3d,class PyDbDatabase {lvalue})'''
    ...
    def beginQuit (self, *args, **kwargs)-> None :
      '''beginQuit( (EditorReactor)arg1) -> None :

    C++ signature :
        void beginQuit(class PyEditorReactor {lvalue})'''
    ...
    def beginRestore (self, *args, **kwargs)-> None :
      '''beginRestore( (EditorReactor)arg1, (Database)arg2, (str)arg3, (Database)arg4) -> None :

    C++ signature :
        void beginRestore(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class PyDbDatabase {lvalue})'''
    ...
    def beginRightClick (self, *args, **kwargs)-> None :
      '''beginRightClick( (EditorReactor)arg1, (Point3d)arg2) -> None :

    C++ signature :
        void beginRightClick(class PyEditorReactor {lvalue},class AcGePoint3d)'''
    ...
    def beginSave (self, *args, **kwargs)-> None :
      '''beginSave( (EditorReactor)arg1, (Database)arg2, (str)arg3) -> None :

    C++ signature :
        void beginSave(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def beginWblock (self, *args, **kwargs)-> None :
      '''beginWblock( (EditorReactor)arg1, (Database)arg2, (Database)arg3, (ObjectId)arg4) -> None :

    C++ signature :
        void beginWblock(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue},class PyDbDatabase {lvalue},class PyDbObjectId {lvalue})'''
    ...
    def beginWblockObjects (self, *args, **kwargs)-> None :
      '''beginWblockObjects( (EditorReactor)arg1, (Database)arg2, (IdMapping)arg3) -> None :

    C++ signature :
        void beginWblockObjects(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue},class PyDbIdMapping {lvalue})'''
    ...
    def cmdIUnkModified (self, *args, **kwargs)-> None :
      '''cmdIUnkModified( (EditorReactor)arg1, (str)arg2) -> None :

    C++ signature :
        void cmdIUnkModified(class PyEditorReactor {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def comandeered (self, *args, **kwargs)-> None :
      '''comandeered( (EditorReactor)arg1, (Database)arg2, (ObjectId)arg3, (Database)arg4) -> None :

    C++ signature :
        void comandeered(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue},class PyDbObjectId {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def commandCancelled (self, *args, **kwargs)-> None :
      '''commandCancelled( (EditorReactor)arg1, (str)arg2) -> None :

    C++ signature :
        void commandCancelled(class PyEditorReactor {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def commandEnded (self, *args, **kwargs)-> None :
      '''commandEnded( (EditorReactor)arg1, (str)arg2) -> None :

    C++ signature :
        void commandEnded(class PyEditorReactor {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def commandFailed (self, *args, **kwargs)-> None :
      '''commandFailed( (EditorReactor)arg1, (str)arg2) -> None :

    C++ signature :
        void commandFailed(class PyEditorReactor {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def commandWillStart (self, *args, **kwargs)-> None :
      '''commandWillStart( (EditorReactor)arg1, (str)arg2) -> None :

    C++ signature :
        void commandWillStart(class PyEditorReactor {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def databaseConstructed (self, *args, **kwargs)-> None :
      '''databaseConstructed( (EditorReactor)arg1, (Database)arg2) -> None :

    C++ signature :
        void databaseConstructed(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def databaseToBeDestroyed (self, *args, **kwargs)-> None :
      '''databaseToBeDestroyed( (EditorReactor)arg1, (Database)arg2) -> None :

    C++ signature :
        void databaseToBeDestroyed(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def docCloseAborted (self, *args, **kwargs)-> None :
      '''docCloseAborted( (EditorReactor)arg1, (Database)arg2) -> None :

    C++ signature :
        void docCloseAborted(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def docCloseWillStart (self, *args, **kwargs)-> None :
      '''docCloseWillStart( (EditorReactor)arg1, (Database)arg2) -> None :

    C++ signature :
        void docCloseWillStart(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def docFrameMovedOrResized (self, *args, **kwargs)-> None :
      '''docFrameMovedOrResized( (EditorReactor)arg1, (int)arg2, (bool)arg3) -> None :

    C++ signature :
        void docFrameMovedOrResized(class PyEditorReactor {lvalue},__int64,bool)'''
    ...
    def dwgViewResized (self, *args, **kwargs)-> None :
      '''dwgViewResized( (EditorReactor)arg1, (int)arg2) -> None :

    C++ signature :
        void dwgViewResized(class PyEditorReactor {lvalue},__int64)'''
    ...
    def dxfInComplete (self, *args, **kwargs)-> None :
      '''dxfInComplete( (EditorReactor)arg1, (Database)arg2) -> None :

    C++ signature :
        void dxfInComplete(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def dxfOutComplete (self, *args, **kwargs)-> None :
      '''dxfOutComplete( (EditorReactor)arg1, (Database)arg2) -> None :

    C++ signature :
        void dxfOutComplete(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def endAttach (self, *args, **kwargs)-> None :
      '''endAttach( (EditorReactor)arg1, (Database)arg2) -> None :

    C++ signature :
        void endAttach(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def endDeepClone (self, *args, **kwargs)-> None :
      '''endDeepClone( (EditorReactor)arg1, (IdMapping)arg2) -> None :

    C++ signature :
        void endDeepClone(class PyEditorReactor {lvalue},class PyDbIdMapping {lvalue})'''
    ...
    def endDwgOpen (self, *args, **kwargs)-> None :
      '''endDwgOpen( (EditorReactor)arg1, (str)arg2, (Database)arg3) -> None :

    C++ signature :
        void endDwgOpen(class PyEditorReactor {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class PyDbDatabase {lvalue})'''
    ...
    def endInsert (self, *args, **kwargs)-> None :
      '''endInsert( (EditorReactor)arg1, (Database)arg2) -> None :

    C++ signature :
        void endInsert(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def endRestore (self, *args, **kwargs)-> None :
      '''endRestore( (EditorReactor)arg1, (Database)arg2) -> None :

    C++ signature :
        void endRestore(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def endWblock (self, *args, **kwargs)-> None :
      '''endWblock( (EditorReactor)arg1, (Database)arg2) -> None :

    C++ signature :
        void endWblock(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def fullRegenEnded (self, *args, **kwargs)-> None :
      '''fullRegenEnded( (EditorReactor)arg1, (Database)arg2, (list)arg3) -> None :

    C++ signature :
        void fullRegenEnded(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue},class boost::python::list)'''
    ...
    def fullRegenWillStart (self, *args, **kwargs)-> None :
      '''fullRegenWillStart( (EditorReactor)arg1, (Database)arg2) -> None :

    C++ signature :
        void fullRegenWillStart(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def initialDwgFileOpenComplete (self, *args, **kwargs)-> None :
      '''initialDwgFileOpenComplete( (EditorReactor)arg1, (Database)arg2) -> None :

    C++ signature :
        void initialDwgFileOpenComplete(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def layoutSwitched (self, *args, **kwargs)-> None :
      '''layoutSwitched( (EditorReactor)arg1, (str)arg2) -> None :

    C++ signature :
        void layoutSwitched(class PyEditorReactor {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def layoutToBeSwitched (self, *args, **kwargs)-> None :
      '''layoutToBeSwitched( (EditorReactor)arg1, (str)arg2, (str)arg3) -> None :

    C++ signature :
        void layoutToBeSwitched(class PyEditorReactor {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def lispCancelled (self, *args, **kwargs)-> None :
      '''lispCancelled( (EditorReactor)arg1) -> None :

    C++ signature :
        void lispCancelled(class PyEditorReactor {lvalue})'''
    ...
    def lispEnded (self, *args, **kwargs)-> None :
      '''lispEnded( (EditorReactor)arg1) -> None :

    C++ signature :
        void lispEnded(class PyEditorReactor {lvalue})'''
    ...
    def lispWillStart (self, *args, **kwargs)-> None :
      '''lispWillStart( (EditorReactor)arg1, (str)arg2) -> None :

    C++ signature :
        void lispWillStart(class PyEditorReactor {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def mainFrameMovedOrResized (self, *args, **kwargs)-> None :
      '''mainFrameMovedOrResized( (EditorReactor)arg1, (int)arg2, (bool)arg3) -> None :

    C++ signature :
        void mainFrameMovedOrResized(class PyEditorReactor {lvalue},__int64,bool)'''
    ...
    def modelessOperationEnded (self, *args, **kwargs)-> None :
      '''modelessOperationEnded( (EditorReactor)arg1, (str)arg2) -> None :

    C++ signature :
        void modelessOperationEnded(class PyEditorReactor {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def modelessOperationWillStart (self, *args, **kwargs)-> None :
      '''modelessOperationWillStart( (EditorReactor)arg1, (str)arg2) -> None :

    C++ signature :
        void modelessOperationWillStart(class PyEditorReactor {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def objectsLazyLoaded (self, *args, **kwargs)-> None :
      '''objectsLazyLoaded( (EditorReactor)arg1, (list)arg2) -> None :

    C++ signature :
        void objectsLazyLoaded(class PyEditorReactor {lvalue},class boost::python::list)'''
    ...
    def otherAttach (self, *args, **kwargs)-> None :
      '''otherAttach( (EditorReactor)arg1, (Database)arg2, (Database)arg3) -> None :

    C++ signature :
        void otherAttach(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def otherInsert (self, *args, **kwargs)-> None :
      '''otherInsert( (EditorReactor)arg1, (Database)arg2, (IdMapping)arg3, (Database)arg4) -> None :

    C++ signature :
        void otherInsert(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue},class PyDbIdMapping {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def otherWblock (self, *args, **kwargs)-> None :
      '''otherWblock( (EditorReactor)arg1, (Database)arg2, (IdMapping)arg3, (Database)arg4) -> None :

    C++ signature :
        void otherWblock(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue},class PyDbIdMapping {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def partialOpenNotice (self, *args, **kwargs)-> None :
      '''partialOpenNotice( (EditorReactor)arg1, (Database)arg2) -> None :

    C++ signature :
        void partialOpenNotice(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def pickfirstModified (self, *args, **kwargs)-> None :
      '''pickfirstModified( (EditorReactor)arg1) -> None :

    C++ signature :
        void pickfirstModified(class PyEditorReactor {lvalue})'''
    ...
    def preXrefLockFile (self, *args, **kwargs)-> None :
      '''preXrefLockFile( (EditorReactor)arg1, (ObjectId)arg2) -> None :

    C++ signature :
        void preXrefLockFile(class PyEditorReactor {lvalue},class PyDbObjectId {lvalue})'''
    ...
    def quitAborted (self, *args, **kwargs)-> None :
      '''quitAborted( (EditorReactor)arg1) -> None :

    C++ signature :
        void quitAborted(class PyEditorReactor {lvalue})'''
    ...
    def quitWillStart (self, *args, **kwargs)-> None :
      '''quitWillStart( (EditorReactor)arg1) -> None :

    C++ signature :
        void quitWillStart(class PyEditorReactor {lvalue})'''
    ...
    def redirected (self, *args, **kwargs)-> None :
      '''redirected( (EditorReactor)arg1, (ObjectId)arg2, (ObjectId)arg3) -> None :

    C++ signature :
        void redirected(class PyEditorReactor {lvalue},class PyDbObjectId {lvalue},class PyDbObjectId {lvalue})'''
    ...
    def removeReactor (self, *args, **kwargs)-> None :
      '''removeReactor( (EditorReactor)arg1) -> None :

    C++ signature :
        void removeReactor(class PyEditorReactor {lvalue})'''
    ...
    def saveComplete (self, *args, **kwargs)-> None :
      '''saveComplete( (EditorReactor)arg1, (Database)arg2, (str)arg3) -> None :

    C++ signature :
        void saveComplete(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def sysVarChanged (self, *args, **kwargs)-> None :
      '''sysVarChanged( (EditorReactor)arg1, (str)arg2, (bool)arg3) -> None :

    C++ signature :
        void sysVarChanged(class PyEditorReactor {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,bool)'''
    ...
    def sysVarWillChange (self, *args, **kwargs)-> None :
      '''sysVarWillChange( (EditorReactor)arg1, (str)arg2) -> None :

    C++ signature :
        void sysVarWillChange(class PyEditorReactor {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def toolbarBitmapSizeChanged (self, *args, **kwargs)-> None :
      '''toolbarBitmapSizeChanged( (EditorReactor)arg1, (bool)arg2) -> None :

    C++ signature :
        void toolbarBitmapSizeChanged(class PyEditorReactor {lvalue},bool)'''
    ...
    def toolbarBitmapSizeWillChange (self, *args, **kwargs)-> None :
      '''toolbarBitmapSizeWillChange( (EditorReactor)arg1, (bool)arg2) -> None :

    C++ signature :
        void toolbarBitmapSizeWillChange(class PyEditorReactor {lvalue},bool)'''
    ...
    def undoSubcommandAuto (self, *args, **kwargs)-> None :
      '''undoSubcommandAuto( (EditorReactor)arg1, (int)arg2, (bool)arg3) -> None :

    C++ signature :
        void undoSubcommandAuto(class PyEditorReactor {lvalue},int,bool)'''
    ...
    def undoSubcommandBack (self, *args, **kwargs)-> None :
      '''undoSubcommandBack( (EditorReactor)arg1, (int)arg2) -> None :

    C++ signature :
        void undoSubcommandBack(class PyEditorReactor {lvalue},int)'''
    ...
    def undoSubcommandBegin (self, *args, **kwargs)-> None :
      '''undoSubcommandBegin( (EditorReactor)arg1, (int)arg2) -> None :

    C++ signature :
        void undoSubcommandBegin(class PyEditorReactor {lvalue},int)'''
    ...
    def undoSubcommandControl (self, *args, **kwargs)-> None :
      '''undoSubcommandControl( (EditorReactor)arg1, (int)arg2, (int)arg3) -> None :

    C++ signature :
        void undoSubcommandControl(class PyEditorReactor {lvalue},int,int)'''
    ...
    def undoSubcommandEnd (self, *args, **kwargs)-> None :
      '''undoSubcommandEnd( (EditorReactor)arg1, (int)arg2) -> None :

    C++ signature :
        void undoSubcommandEnd(class PyEditorReactor {lvalue},int)'''
    ...
    def undoSubcommandMark (self, *args, **kwargs)-> None :
      '''undoSubcommandMark( (EditorReactor)arg1, (int)arg2) -> None :

    C++ signature :
        void undoSubcommandMark(class PyEditorReactor {lvalue},int)'''
    ...
    def undoSubcommandNumber (self, *args, **kwargs)-> None :
      '''undoSubcommandNumber( (EditorReactor)arg1, (int)arg2, (int)arg3) -> None :

    C++ signature :
        void undoSubcommandNumber(class PyEditorReactor {lvalue},int,int)'''
    ...
    def veto (self, *args, **kwargs)-> PyDb.ErrorStatus :
      '''veto( (EditorReactor)arg1) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus veto(class PyEditorReactor {lvalue})'''
    ...
    def viewChanged (self, *args, **kwargs)-> None :
      '''viewChanged( (EditorReactor)arg1) -> None :

    C++ signature :
        void viewChanged(class PyEditorReactor {lvalue})'''
    ...
    def wblockNotice (self, *args, **kwargs)-> None :
      '''wblockNotice( (EditorReactor)arg1, (Database)arg2) -> None :

    C++ signature :
        void wblockNotice(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue})'''
    ...
    def xrefSubcommandAttachItem (self, *args, **kwargs)-> None :
      '''xrefSubcommandAttachItem( (EditorReactor)arg1, (Database)arg2, (int)arg3, (str)arg4) -> None :

    C++ signature :
        void xrefSubcommandAttachItem(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue},int,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def xrefSubcommandBindItem (self, *args, **kwargs)-> None :
      '''xrefSubcommandBindItem( (EditorReactor)arg1, (Database)arg2, (int)arg3, (ObjectId)arg4) -> None :

    C++ signature :
        void xrefSubcommandBindItem(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue},int,class PyDbObjectId {lvalue})'''
    ...
    def xrefSubcommandDetachItem (self, *args, **kwargs)-> None :
      '''xrefSubcommandDetachItem( (EditorReactor)arg1, (Database)arg2, (int)arg3, (ObjectId)arg4) -> None :

    C++ signature :
        void xrefSubcommandDetachItem(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue},int,class PyDbObjectId {lvalue})'''
    ...
    def xrefSubcommandOverlayItem (self, *args, **kwargs)-> None :
      '''xrefSubcommandOverlayItem( (EditorReactor)arg1, (Database)arg2, (int)arg3, (str)arg4) -> None :

    C++ signature :
        void xrefSubcommandOverlayItem(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue},int,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def xrefSubcommandPathItem (self, *args, **kwargs)-> None :
      '''xrefSubcommandPathItem( (EditorReactor)arg1, (int)arg2, (ObjectId)arg3, (str)arg4) -> None :

    C++ signature :
        void xrefSubcommandPathItem(class PyEditorReactor {lvalue},int,class PyDbObjectId {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def xrefSubcommandReloadItem (self, *args, **kwargs)-> None :
      '''xrefSubcommandReloadItem( (EditorReactor)arg1, (Database)arg2, (int)arg3, (ObjectId)arg4) -> None :

    C++ signature :
        void xrefSubcommandReloadItem(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue},int,class PyDbObjectId {lvalue})'''
    ...
    def xrefSubcommandUnloadItem (self, *args, **kwargs)-> None :
      '''xrefSubcommandUnloadItem( (EditorReactor)arg1, (Database)arg2, (int)arg3, (ObjectId)arg4) -> None :

    C++ signature :
        void xrefSubcommandUnloadItem(class PyEditorReactor {lvalue},class PyDbDatabase {lvalue},int,class PyDbObjectId {lvalue})'''
    ...

class InputPoint(object):
    def __init__ (self, *args, **kwargs)-> None :
      '''Raises an exception
This class cannot be instantiated from Python'''
    ...
    def alignmentPaths (self)-> list :
      '''                             '''
    ...
    def cartesianSnappedPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def computedPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def document (self)-> PyAp.Document :
      '''                             '''
    ...
    def drawContext (self)-> PyGi.ViewportDraw :
      '''                             '''
    ...
    def grippedPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def gsSelectionMark (self)-> list :
      '''                             '''
    ...
    def history (self)-> PyEd.PointHistory :
      '''                             '''
    ...
    def keyPointEntities (self)-> list :
      '''                             '''
    ...
    def keyPointGsSelectionMark (self)-> list :
      '''                             '''
    ...
    def lastPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def nestedKeyPointEntities (self)-> list :
      '''                             '''
    ...
    def nestedPickedEntities (self)-> list :
      '''                             '''
    ...
    def osnapMask (self)-> PyDb.OsnapMask :
      '''                             '''
    ...
    def osnapOverrides (self)-> PyDb.OsnapMask :
      '''                             '''
    ...
    def osnappedPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def pickedEntities (self)-> list :
      '''                             '''
    ...
    def pointComputed (self)-> bool :
      '''                             '''
    ...
    def rawPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def tooltipString (self)-> str :
      '''                             '''
    ...

class InputPointFilter(object):
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...
    def processInputPoint (self, *args, **kwargs)-> PyDb.ErrorStatus :
      '''processInputPoint( (InputPointFilter)arg1, (InputPoint)arg2, (InputPointFilterResult)arg3) -> ErrorStatus :

    C++ signature :
        enum Acad::ErrorStatus processInputPoint(class PyEdInputPointFilter {lvalue},class PyEdInputPoint,class PyEdInputPointFilterResult {lvalue})'''
    ...

class InputPointFilterResult(object):
    def __init__ (self, *args, **kwargs)-> None :
      '''Raises an exception
This class cannot be instantiated from Python'''
    ...
    def displayOsnapGlyph (self)-> bool :
      '''                             '''
    ...
    def newPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def newTooltipString (self)-> str :
      '''                             '''
    ...
    def retry (self)-> bool :
      '''                             '''
    ...
    def setDisplayOsnapGlyph (self, val : bool)-> None :
      '''                             '''
    ...
    def setNewPoint (self, val : PyGe.Point3d)-> None :
      '''                             '''
    ...
    def setNewTooltipString (self, val : str)-> None :
      '''                             '''
    ...
    def setRetry (self, val : bool)-> None :
      '''                             '''
    ...

class InputPointManager(object):
    def __init__ (self, *args, **kwargs)-> None :
      '''Raises an exception
This class cannot be instantiated from Python'''
    ...
    def addPointMonitor (self, monitor : PyEd.InputPointMonitor)-> None :
      '''                             '''
    ...
    def disableSystemCursorGraphics (self)-> bool :
      '''                             '''
    ...
    def enableMultiSubentPathSelection (self)-> None :
      '''                             '''
    ...
    def enableSystemCursorGraphics (self)-> bool :
      '''                             '''
    ...
    def forcedPickCount (self)-> int :
      '''                             '''
    ...
    def hasFilter (self)-> bool :
      '''                             '''
    ...
    def mouseHasMoved (self)-> int :
      '''                             '''
    ...
    def registerPointFilter (self, filter : PyEd.InputPointFilter)-> None :
      '''                             '''
    ...
    def removePointMonitor (self, monitor : PyEd.InputPointMonitor)-> None :
      '''                             '''
    ...
    def revokePointFilter (self)-> None :
      '''                             '''
    ...
    def systemCursorDisableCount (self)-> int :
      '''                             '''
    ...
    def turnOffForcedPick (self)-> bool :
      '''                             '''
    ...
    def turnOffSubentityWindowSelection (self)-> bool :
      '''                             '''
    ...
    def turnOnSubentityWindowSelection (self)-> bool :
      '''                             '''
    ...

class InputPointMonitor(object):
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...
    def monitorInputPoint (self, input : PyEd.InputPoint, output : PyEd.InputPointMonitorResult)-> PyDb.ErrorStatus :
      '''                             '''
    ...

class InputPointMonitorResult(object):
    def __init__ (self, *args, **kwargs)-> None :
      '''Raises an exception
This class cannot be instantiated from Python'''
    ...
    def additionalTooltipString (self)-> str :
      '''                             '''
    ...
    def appendToTooltipStr (self)-> bool :
      '''                             '''
    ...
    def setAdditionalTooltipString (self, val : str)-> None :
      '''                             '''
    ...

class Jig(object):
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1, (Entity)arg2) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class PyDbEntity)'''
    ...
    def acquireAngle (self, basePnt: PyGe.Point3d=None)-> tuple :
      '''                             '''
    ...
    def acquireDist (self, basePnt: PyGe.Point3d=None)-> tuple :
      '''                             '''
    ...
    def acquirePoint (self, basePnt: PyGe.Point3d=None)-> tuple :
      '''                             '''
    ...
    def acquireString (self)-> tuple :
      '''                             '''
    ...
    def append (self)-> PyDb.ObjectId :
      '''                             '''
    ...

    @staticmethod
    def className ()-> str :
      '''                             '''
    ...
    def dispPrompt (self)-> str :
      '''                             '''
    ...
    def drag (self, style: PyEd.DragStyle=None)-> PyEd.DragStatus :
      '''                             '''
    ...
    def keywordList (self)-> str :
      '''                             '''
    ...
    def sampler (self)-> PyEd.DragStatus :
      '''                             '''
    ...
    def setDispPrompt (self, val: str)-> None :
      '''                             '''
    ...
    def setKeywordList (self, val: str)-> None :
      '''                             '''
    ...
    def setSpecialCursorType (self, val: PyEd.CursorType)-> None :
      '''                             '''
    ...
    def setUserInputControls (self, val:  PyEd.UserInputControls)-> None :
      '''                             '''
    ...
    def specialCursorType (self)-> PyEd.CursorType :
      '''                             '''
    ...
    def update (self)-> bool :
      '''                             '''
    ...
    def userInputControls (self)-> PyEd.UserInputControls :
      '''                             '''
    ...

class PointHistory(object):
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def eAligned (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def eAppFiltered (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def eCartSnapped (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def eCoordPending (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def eCyclingPt (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def eDidNotPick (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def eDirectDistance (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def eForcedPick (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def eFromKeyboard (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def eGizmoConstrainted (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def eGripped (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def eLastPt (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def eNotDigitizer (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def eNotInteractive (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def eOrtho (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def eOsnapped (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def ePickAborted (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def ePickMask (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def ePolarAngle (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def eTablet (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def eUsedOsnapBox (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def eUsedPickBox (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def eXPending (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def eYPending (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def eZPending (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class PromptStatus(object):
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def eCancel (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def eDirect (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def eError (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def eFailed (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def eKeyword (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def eModeless (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def eNone (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def eNormal (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def eOk (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def eRejected (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kNormal (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class SelectionSet(object):
    def __init__ (self)-> None :
      '''                             '''
    ...
    def add (self, id: PyDb.ObjectId)-> None :
      '''                             '''
    ...
    def adsname (self)-> PyDb.AdsName :
      '''                             '''
    ...
    def clear (self)-> None :
      '''                             '''
    ...
    def hasMember (self, id: PyDb.ObjectId)-> bool :
      '''                             '''
    ...
    def isInitialized (self)-> bool :
      '''                             '''
    ...
    def objectIds (self, desc: PyRx.RxClass=PyDb.Entity)-> list :
      '''                             '''
    ...
    def remove (self, id: PyDb.ObjectId)-> None :
      '''                             '''
    ...
    def size (self)-> int :
      '''                             '''
    ...
    def ssNameX (self, val: int = 0)-> list :
      '''                             '''
    ...
    def ssSetFirst (self)-> bool :
      '''                             '''
    ...
    def ssXform (self, xform: PyGe.Matrix3d)-> PyEd.PromptStatus :
      '''                             '''
    ...
    def toList (self)-> list :
      '''                             '''
    ...

class UIContext(object):
    def OnUpdateMenu (self, *args, **kwargs)-> None :
      '''OnUpdateMenu( (UIContext)arg1) -> None :

    C++ signature :
        void OnUpdateMenu(class PyEdUIContext {lvalue})'''
    ...
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...
    def addDefaultContextMenu (self, *args, **kwargs)-> bool :
      '''addDefaultContextMenu( (UIContext)arg1) -> bool :

    C++ signature :
        bool addDefaultContextMenu(class PyEdUIContext {lvalue})

addDefaultContextMenu( (UIContext)arg1, (str)arg2) -> bool :

    C++ signature :
        bool addDefaultContextMenu(class PyEdUIContext {lvalue},class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)'''
    ...
    def addObjectContextMenu (self, *args, **kwargs)-> bool :
      '''addObjectContextMenu( (RxClass)arg1, (UIContext)arg2) -> bool :

    C++ signature :
        bool addObjectContextMenu(class PyRxClass {lvalue},class PyEdUIContext {lvalue})'''
    ...
    def getMenuContext (self, *args, **kwargs)-> object :
      '''getMenuContext( (UIContext)arg1, (RxClass)arg2, (list)arg3) -> object :

    C++ signature :
        class boost::python::api::object getMenuContext(class PyEdUIContext {lvalue},class PyRxClass,class boost::python::list)'''
    ...
    def hitPoint (self, *args, **kwargs)-> PyGe.Point3d :
      '''hitPoint( (UIContext)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d hitPoint(class PyEdUIContext {lvalue})'''
    ...
    def onCommand (self, *args, **kwargs)-> None :
      '''onCommand( (UIContext)arg1, (SubentType)arg2) -> None :

    C++ signature :
        void onCommand(class PyEdUIContext {lvalue},unsigned int)'''
    ...
    def removeDefaultContextMenu (self, *args, **kwargs)-> bool :
      '''removeDefaultContextMenu( (UIContext)arg1) -> bool :

    C++ signature :
        bool removeDefaultContextMenu(class PyEdUIContext {lvalue})'''
    ...
    def removeObjectContextMenu (self, *args, **kwargs)-> bool :
      '''removeObjectContextMenu( (RxClass)arg1, (UIContext)arg2) -> bool :

    C++ signature :
        bool removeObjectContextMenu(class PyRxClass {lvalue},class PyEdUIContext {lvalue})'''
    ...

class UserInputControls(object):
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def kAccept3dCoordinates (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kAcceptMouseUpAsPoint (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kAcceptOtherInputString (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kAnyBlankTerminatesInput (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kDisableDirectDistanceInput (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kDontEchoCancelForCtrlC (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kDontUpdateLastPoint (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kGovernedByOrthoMode (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kGovernedByUCSDetect (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kImpliedFaceForUCSChange (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kInitialBlankTerminatesInput (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kNoDwgLimitsChecking (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kNoNegativeResponseAccepted (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kNoZDirectionOrtho (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kNoZeroResponseAccepted (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kNullResponseAccepted (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kUseBasePointElevation (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class UserInteraction(object):
    def __init__ (self, doc:PyAp.Document='current', isPrompting:bool=True)-> None :
      '''                             '''
    ...

class Util(object):
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...

    @staticmethod
    def angle (pt1: PyGe.Point3d,pt2: PyGe.Point3d)-> float :
      '''                             '''
    ...

    @staticmethod
    def cvUnit (val: float,oldunit: str,newunit: str)-> float :
      '''                             '''
    ...

    @staticmethod
    def distance (pt1: PyGe.Point3d,pt2: PyGe.Point3d)-> float :
      '''                             '''
    ...

    @staticmethod
    def polar (pt1: PyGe.Point3d,angle: float,dist: float)-> PyGe.Point3d :
      '''                             '''
    ...

    @staticmethod
    def wcMatch (string: str,pattern: str,ignoreCase: bool)-> bool :
      '''                             '''
    ...

def print (*args, **kwargs)-> None :
    '''print( (object)arg1) -> None :

    C++ signature :
        void print(class boost::python::api::object)'''
    ...
