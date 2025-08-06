# PyAp

```PY




T = TypeVar("T")

k2000_Standard: SaveFormat  # 15
k2000_Template: SaveFormat  # 14
k2000_dwg: SaveFormat  # 12
k2000_dxf: SaveFormat  # 13
k2000_xml: SaveFormat  # 16
k2004_Standard: SaveFormat  # 27
k2004_Template: SaveFormat  # 26
k2004_dwg: SaveFormat  # 24
k2004_dxf: SaveFormat  # 25
k2007_Standard: SaveFormat  # 39
k2007_Template: SaveFormat  # 38
k2007_dwg: SaveFormat  # 36
k2007_dxf: SaveFormat  # 37
k2010_Standard: SaveFormat  # 51
k2010_Template: SaveFormat  # 50
k2010_dwg: SaveFormat  # 48
k2010_dxf: SaveFormat  # 49
k2013_Standard: SaveFormat  # 63
k2013_Template: SaveFormat  # 62
k2013_dwg: SaveFormat  # 60
k2013_dxf: SaveFormat  # 61
k2018_Standard: SaveFormat  # 67
k2018_Template: SaveFormat  # 66
k2018_dwg: SaveFormat  # 64
k2018_dxf: SaveFormat  # 65
kAny: PaletteDockStyle  # 61440
kAutoWrite: DocLockMode  # 1
kBottom: PaletteDockStyle  # 32768
kLeft: PaletteDockStyle  # 4096
kNative: SaveFormat  # 64
kNative_Template: SaveFormat  # 66
kNoOptimize: PyRxTestFlags  # 1
kNone: PaletteDockStyle  # 0
kNotLocked: DocLockMode  # 2
kProtectedAutoWrite: DocLockMode  # 20
kPyReserved1: PyRxTestFlags  # 2
kPyReserved2: PyRxTestFlags  # 4
kPyReserved3: PyRxTestFlags  # 8
kPyReserved4: PyRxTestFlags  # 16
kPyReserved5: PyRxTestFlags  # 32
kPyReserved6: PyRxTestFlags  # 64
kPyReserved7: PyRxTestFlags  # 128
kR12_dxf: SaveFormat  # 1
kR13_dwg: SaveFormat  # 4
kR13_dxf: SaveFormat  # 5
kR14_dwg: SaveFormat  # 8
kR14_dxf: SaveFormat  # 9
kRead: DocLockMode  # 32
kRight: PaletteDockStyle  # 16384
kTop: PaletteDockStyle  # 8192
kUnknown: SaveFormat  # -1
kWaitForDebug: PyRxTestFlags  # 256
kWrite: DocLockMode  # 4
kXWrite: DocLockMode  # 64

class Application:
    def __init__(self, /) -> None:  
    @staticmethod
    def acadApplication() -> PyAx.AcadApplication:  
    @staticmethod
    def acadGetIDispatch() -> int:  
    @staticmethod
    def applyHostIcon(wnd: int, /) -> None:  
    @staticmethod
    def className() -> str:  
    @staticmethod
    def docManager() -> DocManager:  
    @staticmethod
    def getAppDataPath(createIfNotFound: bool = True, /) -> str:  
    @staticmethod
    def getLoadedModuleNames() -> list[str]:  
    @staticmethod
    def getLoadedModules() -> list[str]:  
    @staticmethod
    def getLocalAppDataPath(createIfNotFound: bool = True, /) -> str:  
    @staticmethod
    def getPyRxModuleName() -> str:  
    @staticmethod
    def getPyRxModulePath() -> str:  
    @staticmethod
    def hostAPI() -> str:  
    @staticmethod
    def hostAPIVER() -> str:  
    @staticmethod
    def hostFileInfo() -> str:  
    @staticmethod
    def listFilesInPath(path: str, ext: str, /) -> list:  
    @staticmethod
    def listFilesInPathRecursive(path: str, ext: str, /) -> list:  
    @staticmethod
    def loadPythonModule(fullpath: str, /) -> object:  
    @staticmethod
    def mainWnd() -> int:  
    @staticmethod
    def pyrxDLLVersion() -> str:  
    @staticmethod
    def regCommand(
        fullpath: str, modulename: str, name: str, defFunc: Any, flags: PyAp.CmdFlags, /
    ) -> None:  
    @staticmethod
    def registerOnIdleWinMsg(func: Any, /) -> None:  
    @staticmethod
    def registerWatchWinMsg(func: Any, /) -> bool:  
    @staticmethod
    def reloadPythonModule(fullpath: str, /) -> object:  
    @staticmethod
    def removeCommand(modulename: str, name: str, /) -> None:  
    @staticmethod
    def removeOnIdleWinMsg(func: Any, /) -> None:  
    @staticmethod
    def removeWatchWinMsg(func: Any, /) -> bool:  
    @staticmethod
    def setTitleThemeDark(wnd: int, /) -> None:  
    @staticmethod
    def showModalDialog(window: wx.Dialog, /) -> int:  
    @staticmethod
    def testFlags(flags: PyAp.PyRxTestFlags, /) -> str:  
    @staticmethod
    def wxApp() -> object:  

class AutoDocLock:
    def __init__(self, docToLock: PyAp.Document =  , /) -> None:
    @staticmethod
    def className() -> str:  
    def doc(self, /) -> Document:  

class CmdFlags:
    DEFUN: int
    DOCEXCLUSIVELOCK: int
    DOCREADLOCK: int
    INPROGRESS: int
    INTERRUPTIBLE: int
    MODAL: int
    NOBEDIT: int
    NOHISTORY: int
    NOINTERNALLOCK: int
    NOMULTIPLE: int
    NOOEM: int
    NOPAPERSPACE: int
    NOPERSPECTIVE: int
    NOTILEMODE: int
    NO_UNDO_MARKER: int
    REDRAW: int
    SESSION: int
    TRANSPARENT: int
    UNDEFINED: int
    USEPICKSET: int
    def __init__(self, /) -> None:  

class DocLockMode(_BoostPythonEnum):
    kNone: ClassVar[Self]  # 0
    kAutoWrite: ClassVar[Self]  # 1
    kNotLocked: ClassVar[Self]  # 2
    kWrite: ClassVar[Self]  # 4
    kProtectedAutoWrite: ClassVar[Self]  # 20
    kRead: ClassVar[Self]  # 32
    kXWrite: ClassVar[Self]  # 64

class DocManager(PyRx.RxObject):
    def __init__(self, /) -> None:
    def activateDocument(self, doc: PyAp.Document, bPassScript: bool = False, /) -> None:
    def appContextCloseDocument(self, doc: PyAp.Document, /) -> None:
    def appContextNewDocument(self, templateName: str, /) -> None:
    def appContextOpenDocument(self, dwgName: str, /) -> None:
    def appContextPromptOpenDocument(self, /) -> None:
    def appContextRecoverDocument(self, dwgName: str, /) -> None:
    @staticmethod
    def autoLock(docToLock: PyAp.Document =  , /) -> AutoDocLock:
    def beginExecuteInApplicationContext(self, func: Any, data: Any, /) -> PyDb.ErrorStatus:
    def beginExecuteInCommandContext(self, func: Any, data: Any, /) -> PyDb.ErrorStatus:
    @staticmethod
    def className() -> str:  
    def closeDocument(self, doc: PyAp.Document, /) -> None:
    def curDocument(self, /) -> Document:
    def defaultFormatForSave(self, /) -> SaveFormat:
    def disableDocumentActivation(self, /) -> None:
    def document(self, db: PyDb.Database, /) -> Document:
    def documentCount(self, /) -> int:
    def documents(self, /) -> list[PyAp.Document]:  
    def enableDocumentActivation(self, /) -> None:
    def executeInApplicationContext(self, func: Any, data: Any, /) -> None:
    def inputPending(self, doc: PyAp.Document, /) -> int:
    def isApplicationContext(self, /) -> bool:
    def isDocumentActivationEnabled(self, /) -> bool:
    def lockDocument(
        self,
        doc: PyAp.Document,
        mode: PyAp.DocLockMode = kWrite,
        gcmd: str =  ,
        lcmd: str =  ,
        prmt: bool = True,
        /,
    ) -> None:
    def mdiActiveDocument(self, /) -> Document:
    def newDocument(self, /) -> None:
    def openDocument(self, /) -> None:
    def popResourceHandle(self, /) -> None:
    def pushAcadResourceHandle(self, /) -> None:
    def sendModelessInterrupt(self, doc: PyAp.Document, /) -> None:
    def sendStringToExecute(
        self,
        doc: PyAp.Document,
        script: str,
        bActivate: bool = True,
        bWrapUpInactiveDoc: bool = False,
        bEchoString: bool = True,
        /,
    ) -> None:
    def setCurDocument(
        self, doc: PyAp.Document, mode: PyAp.DocLockMode = kNone, activate: bool = False, /
    ) -> None:
    def setDefaultFormatForSave(self, fmt: PyAp.SaveFormat, /) -> None:
    def unlockDocument(self, doc: PyAp.Document, /) -> None:

class DocManagerReactor:
    def __init__(self, /) -> None:
    def addReactor(self, /) -> None:
    def documentActivated(self, val: Document, /) -> None:
    def documentActivationModified(self, val: bool, /) -> None:
    def documentBecameCurrent(self, val: Document, /) -> None:
    def documentCreateCanceled(self, val: Document, /) -> None:
    def documentCreateStarted(self, val: Document, /) -> None:
    def documentCreated(self, val: Document, /) -> None:
    def documentDestroyed(self, val: str, /) -> None:
    def documentLockModeChangeVetoed(self, doc: Document, globalCmdName: str, /) -> None:
    def documentLockModeChanged(
        self,
        doc: Document,
        myPrevMode: DocLockMode,
        myCurMode: DocLockMode,
        currentMode: DocLockMode,
        globalCmdName: str,
        /,
    ) -> None:
    def documentLockModeWillChange(
        self,
        myCurMode: DocLockMode,
        myNewMode: DocLockMode,
        curMode: DocLockMode,
        globalCmdName: str,
        /,
    ) -> None:
    def documentToBeActivated(self, val: Document, /) -> None:
    def documentToBeDeactivated(self, val: Document, /) -> None:
    def documentToBeDestroyed(self, val: Document, /) -> None:
    def removeReactor(self, /) -> None:

class Document(PyRx.RxObject):
    def __init__(self) -> None:
    def autoLock(self, /) -> AutoDocLock:
    @staticmethod
    def className() -> str:  
    def database(self, /) -> PyDb.Database:
    def docTitle(self, /) -> str:
    @staticmethod
    def docWnd() -> int:  
    def downgradeDocOpen(self, promptForSave: bool, /) -> None:
    def editor(self, /) -> PyEd.Editor:  
    def fileName(self, /) -> str:
    def formatForSave(self, /) -> SaveFormat:
    def getCountOfLispList(self, /) -> int:
    def getItemOfLispList(self, index: int, /) -> tuple[str, bool]:
    def getUserData(self, /) -> object:  
    @staticmethod
    def getWxWindow() -> object:  
    def inputPointManager(self, /) -> PyEd.InputPointManager:
    def isCommandInputInactive(self, /) -> bool:
    def isQuiescent(self, /) -> bool:
    def lockMode(self, bIncludeMyLocks: bool = False, /) -> DocLockMode:
    def myLockMode(self, /) -> DocLockMode:
    def popDbmod(self, /) -> None:
    def pushDbmod(self, /) -> None:
    def setDocTitle(self, title: str, /) -> None:
    def setUserData(self, data: object, /) -> None:  
    def transactionManager(self, /) -> TransactionManager:
    def upgradeDocOpen(self, /) -> None:

class LayerFilter(PyRx.RxObject):
    def __init__(self, /) -> None:
    def addNested(self, val: PyAp.LayerFilter, /) -> None:
    def allowDelete(self, /) -> bool:
    def allowNested(self, /) -> bool:
    def allowRename(self, /) -> bool:
    @staticmethod
    def className() -> str:  
    def compareTo(self, other: PyAp.LayerFilter, /) -> bool:
    @staticmethod
    def desc() -> PyRx.RxClass:
    def dynamicallyGenerated(self, /) -> bool:
    def filter(self, val: PyDb.LayerTableRecord, /) -> bool:
    def filterExpression(self, /) -> str:
    def generateNested(self, /) -> None:
    def getNestedFilters(self, /) -> list[PyAp.LayerFilter]:
    def isIdFilter(self, /) -> bool:
    def isProxy(self, /) -> bool:
    def name(self, /) -> str:
    def parent(self, /) -> LayerFilter:
    def removeNested(self, val: PyAp.LayerFilter, /) -> None:
    def setFilterExpression(self, val: str, /) -> None:
    def setName(self, val: str, /) -> None:
    def showEditor(self, /) -> int:

class LayerFilterManager:
    def __init__(self, db: PyDb.Database =  , /) -> None:  
    def getFilters(self, /) -> tuple[PyAp.LayerFilter, PyAp.LayerFilter]:  
    @overload
    def setFilters(self, root: PyAp.LayerFilter, current: PyAp.LayerFilter, /) -> None:  
    @overload
    def setFilters(self, rootCurrent: tuple[PyAp.LayerFilter, PyAp.LayerFilter], /) -> None:  
    @overload
    def setFilters(self, *args) -> None:  

class LayerGroup(PyAp.LayerFilter):
    def __init__(self, /) -> None:  
    def addLayerId(self, id: PyDb.ObjectId, /) -> None:  
    @staticmethod
    def className() -> str:  
    @staticmethod
    def desc() -> PyRx.RxClass:
    def layerIds(self, /) -> list[PyDb.ObjectId]:  
    def removeLayerId(self, id: PyDb.ObjectId, /) -> None:  

class LayoutManager(PyDb.LayoutManager):
    def __init__(self, /) -> None:
    @staticmethod
    def className() -> str:  
    def createLayoutFromTemplate(
        self,
        newLayoutName: str,
        templatePath: str,
        layoutName: str,
        db: PyDb.Database = "current",
        /,
    ) -> PyDb.ObjectId:
    def createViewports(self, /) -> bool:
    @staticmethod
    def desc() -> PyRx.RxClass:
    def generateNextNewLayoutName(self, val: PyDb.Database = "current", /) -> str:
    def getActiveTab(self, /) -> str:
    def getClipBoundaryElabration(self, val: PyDb.ObjectId, /) -> list[PyGe.Point2d]:  
    def pageSetup(
        self,
        layoutBTRId: PyDb.ObjectId = PyDb.ObjectId.kNull,
        parent: int = 0,
        isPageSetupDlg: bool = True,
        /,
    ) -> int:
    def pointInViewports(self, val: PyGe.Point3d, /) -> list[PyDb.ObjectId]:
    def setCaptureOnLayoutSwitch(self, val: bool, /) -> None:
    def setCreateViewports(self, val: bool, /) -> None:
    def setDefaultPlotConfig(self, val: PyDb.ObjectId, /) -> None:
    def setShowPageSetup(self, val: bool, /) -> None:
    def setShowPaperBackground(self, val: bool, /) -> None:
    def setShowPaperMargins(self, val: bool, /) -> None:
    def setShowPrintBorder(self, val: bool, /) -> None:
    def setShowTabs(self, val: bool, /) -> None:
    def showPageSetup(self, /) -> bool:
    def showPaperBackground(self, /) -> bool:
    def showPaperMargins(self, /) -> bool:
    def showPrintBorder(self, /) -> bool:
    def showTabs(self, /) -> bool:
    def updateCurrentPaper(self, zoomToPaper: bool = False, /) -> None:
    def updateLayoutTabs(self, /) -> None:

class Palette:
    def __init__(self) -> None:
    def getWxWindow(self, /) -> object:  

class PaletteDockStyle(_BoostPythonEnum):
    kNone: ClassVar[Self]  # 0
    kLeft: ClassVar[Self]  # 4096
    kRight: ClassVar[Self]  # 16384
    kTop: ClassVar[Self]  # 8192
    kBottom: ClassVar[Self]  # 32768
    kAny: ClassVar[Self]  # 61440

class PaletteSet:
    def __init__(self, name: str, guid: str =  , /) -> None:  
    def add(self, name: str, panel: wx.Panel, /) -> int:  
    def anchored(self, /) -> bool:  
    def autoRollupStyle(self, /) -> bool:
    def closeButtonStyle(self, /) -> bool:
    def dockControlBar(
        self, style: PyAp.PaletteDockStyle, rect: tuple[int, int, int, int], /
    ) -> None:  
    def editNameStyle(self, /) -> bool:
    def enableDocking(self, style: PyAp.PaletteDockStyle, /) -> None:  
    def getActivePaletteTabIndex(self, /) -> int:
    def getAutoRollup(self, /) -> bool:
    def getDockState(self, /) -> PaletteDockStyle:  
    def getFloatingRect(self, /) -> tuple[int, int, int, int]:  
    def getFullRect(self, /) -> object:
    def getName(self, /) -> str:
    def getOpacity(self, /) -> int:
    def getPaletteCount(self, /) -> int:
    def getPaletteSetStyle(self, /) -> int:
    def getRolloverOpacity(self, /) -> int:
    def getWxWindow(self, /) -> object:  
    @staticmethod
    def hidePalettes() -> bool:  
    def initFloatingPosition(self, rect: tuple[int, int, int, int], /) -> None:  
    def isFloating(self, /) -> bool:  
    def paletteBackgroundColor(self, /) -> int:  
    def paletteTabTextColor(self, /) -> int:  
    def propertiesMenuStyle(self, /) -> bool:
    def removePalette(self, val: int, /) -> bool:
    @overload
    def restoreControlBar(self, /) -> None:  
    @overload
    def restoreControlBar(
        self, style: PyAp.PaletteDockStyle, rect: tuple[int, int, int, int], /
    ) -> None:  
    @overload
    def restoreControlBar(self, *args) -> None:  
    def rollOut(self, delay: bool = False, /) -> None:
    def rollUp(self, /) -> None:
    def rolledUp(self, /) -> bool:
    def setActivePalette(self, val: int, /) -> bool:
    def setAutoRollup(self, val: bool, /) -> bool:
    def setDockState(self, style: PyAp.PaletteDockStyle, /) -> None:  
    def setLocation(self, x: int, y: int, /) -> None:  
    def setName(self, name: str, /) -> bool:
    def setOpacity(self, val: int, /) -> bool:
    def setPaletteSetStyle(self, val: int, /) -> None:
    def setRolloverOpacity(self, val: int, /) -> bool:
    def setSize(self, x: int, y: int, /) -> None:  
    def setTitleBarLocation(self, val: PyAp.PaletteTitleBarLocation, /) -> None:
    def setToolId(self, guid: str, /) -> bool:
    def setVisible(self, val: bool, /) -> None:  
    def showIconStyle(self, /) -> bool:
    @staticmethod
    def showPalettes() -> bool:  
    def showRollupButtonStyle(self, /) -> bool:
    def singlePaletteTabStyle(self, /) -> bool:
    def snapStyle(self, /) -> bool:
    def titleBarLocation(self, /) -> PaletteTitleBarLocation:
    def updateTabs(self, /) -> None:
    def useSinglePaletteTabNameStyle(self, /) -> bool:

class PaletteTitleBarLocation(_BoostPythonEnum):
    kLeft: ClassVar[Self]  # 0
    kRight: ClassVar[Self]  # 1

class PyRxTestFlags(_BoostPythonEnum):
    kNoOptimize: ClassVar[Self]  # 1
    kPyReserved1: ClassVar[Self]  # 2
    kPyReserved2: ClassVar[Self]  # 4
    kPyReserved3: ClassVar[Self]  # 8
    kPyReserved4: ClassVar[Self]  # 16
    kPyReserved5: ClassVar[Self]  # 32
    kPyReserved6: ClassVar[Self]  # 64
    kPyReserved7: ClassVar[Self]  # 128
    kWaitForDebug: ClassVar[Self]  # 256

class ResourceOverride:
    def __init__(self, /) -> None:
    @staticmethod
    def className() -> str:  

class SaveFormat(_BoostPythonEnum):
    kUnknown: ClassVar[Self]  # -1
    kR12_dxf: ClassVar[Self]  # 1
    kR13_dwg: ClassVar[Self]  # 4
    kR13_dxf: ClassVar[Self]  # 5
    kR14_dwg: ClassVar[Self]  # 8
    kR14_dxf: ClassVar[Self]  # 9
    k2000_dwg: ClassVar[Self]  # 12
    k2000_dxf: ClassVar[Self]  # 13
    k2000_Template: ClassVar[Self]  # 14
    k2000_Standard: ClassVar[Self]  # 15
    k2000_xml: ClassVar[Self]  # 16
    k2004_dwg: ClassVar[Self]  # 24
    k2004_dxf: ClassVar[Self]  # 25
    k2004_Template: ClassVar[Self]  # 26
    k2004_Standard: ClassVar[Self]  # 27
    k2007_dwg: ClassVar[Self]  # 36
    k2007_dxf: ClassVar[Self]  # 37
    k2007_Template: ClassVar[Self]  # 38
    k2007_Standard: ClassVar[Self]  # 39
    k2010_dwg: ClassVar[Self]  # 48
    k2010_dxf: ClassVar[Self]  # 49
    k2010_Template: ClassVar[Self]  # 50
    k2010_Standard: ClassVar[Self]  # 51
    k2013_dwg: ClassVar[Self]  # 60
    k2013_dxf: ClassVar[Self]  # 61
    k2013_Template: ClassVar[Self]  # 62
    k2013_Standard: ClassVar[Self]  # 63
    k2018_dwg: ClassVar[Self]  # 64
    k2018_dxf: ClassVar[Self]  # 65
    k2018_Template: ClassVar[Self]  # 66
    k2018_Standard: ClassVar[Self]  # 67
    kNative: ClassVar[Self]  # 64
    kNative_Template: ClassVar[Self]  # 66

class TransactionManager(PyDb.TransactionManager):
    def __init__(self, /) -> None:
    @staticmethod
    def className() -> str:  
    @staticmethod
    def desc() -> PyRx.RxClass:
    def enableGraphicsFlush(self, val: bool, /) -> None:  
    def flushGraphics(self, /) -> None:  

_CommandDecorator: TypeAlias = c.Callable[[T], T]

@overload
def Command() -> _CommandDecorator:  
@overload
def Command(commandName: str, /) -> _CommandDecorator:  
@overload
def Command(commandName: str, CmdFlags: PyAp.CmdFlags, /) -> _CommandDecorator:

_LispFunctionDecorator: TypeAlias = c.Callable[[T], T]

@overload
def LispFunction() -> _LispFunctionDecorator:  
@overload
def LispFunction(defunName: str, /) -> _LispFunctionDecorator:

def curDoc(*args) -> Document:

def fireOnbeginConsole(*args) -> bool:
```
