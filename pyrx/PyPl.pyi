from __future__ import annotations
from typing import *
from pyrx import Ap as PyAp
from pyrx import Br as PyBr
from pyrx import Db as PyDb
from pyrx import Ed as PyEd
from pyrx import Ge as PyGe
from pyrx import Gi as PyGi
from pyrx import Gs as PyGs
from pyrx import Pl as PyPl
from pyrx import Rx as PyRx
from pyrx import Sm as PySm
from pyrx import Ax as PyAx
import wx

T = TypeVar("T")

class _BoostPythonEnumMeta(type):
    # This is not a real class, it is just for better type hints

    def __call__(cls: type[T], value: int) -> T: ...

class _BoostPythonEnum(int, metaclass=_BoostPythonEnumMeta):
    # This is not a real class, it is just for better type hints

    values: ClassVar[dict[int, Self]]
    names: ClassVar[dict[str, Self]]

    name: str
eDeviceLoadFailed: CustomSizeResult  # 8192
eException: CustomSizeResult  # 256
eMustCreatePC3: CustomSizeResult  # 1
ePC3DirReadOnly: CustomSizeResult  # 4
ePC3FileReadOnly: CustomSizeResult  # 64
ePMPDirMissing: CustomSizeResult  # 16
ePMPDirReadOnly: CustomSizeResult  # 8
ePMPFileReadOnly: CustomSizeResult  # 2048
ePossible: CustomSizeResult  # 0
eRotationRequired: CustomSizeResult  # 2
eSizeTooBig: CustomSizeResult  # 128
eUnknownErrPC3File: CustomSizeResult  # 512
eUnknownErrPMPDir: CustomSizeResult  # 32
eUnknownErrPMPFile: CustomSizeResult  # 1024
eWidthAndHeightMustBePositive: CustomSizeResult  # 4096
k3dDwf: SetupType  # 3
kAll: RefreshCode  # 0
kAllTypes: StyTypes  # 7
kBackgroundPlotting: ProcessPlotState  # 2
kCancelJobBtnMsg: PlotMSGIndex  # 9
kCancelSheetBtnMsg: PlotMSGIndex  # 8
kColorDep: StyTypes  # 4
kDWF6ePlot: StdConfigs  # 2
kDWFePlotOptForPlotting: StdConfigs  # 3
kDWFePlotOptForViewing: StdConfigs  # 4
kDWFxePlot: StdConfigs  # 8
kDefaultWindowsSysPrinter: StdConfigs  # 1
kDialogTitle: PlotMSGIndex  # 0
kForegroundPlotting: ProcessPlotState  # 1
kMatchDisabled: MatchingPolicy  # 1
kMatchEnabled: MatchingPolicy  # 2
kMatchEnabledCustom: MatchingPolicy  # 3
kMatchEnabledTmpCustom: MatchingPolicy  # 4
kMsgCancelling: PlotMSGIndex  # 6
kMsgCancellingCurrent: PlotMSGIndex  # 7
kMsgCount: PlotMSGIndex  # 10
kMultiDWF: SheetType  # 1
kMultiDWFx: SheetType  # 4
kMultiPDF: SheetType  # 6
kMultiSVF: SheetType  # 8
kMustPlotToFile: PlotToFileCapability  # 2
kNPSOtherDWG: SetupType  # 2
kNPSSameDWG: SetupType  # 1
kNoPlotToFile: PlotToFileCapability  # 0
kNoneDevice: StdConfigs  # 0
kNotPlotting: ProcessPlotState  # 0
kOneOffConfig: DeviceType  # 2
kOriginalDevice: SheetType  # 2
kOriginalPS: SetupType  # 0
kOverridePS: SetupType  # 4
kPC3File: DeviceType  # 1
kPDFePlot: StdConfigs  # 10
kPDFePlotGeneralDocs: StdConfigs  # 11
kPDFePlotHighQuality: StdConfigs  # 12
kPDFePlotSmallerFile: StdConfigs  # 13
kPDFePlotWebMobile: StdConfigs  # 14
kPlotCancelStatusCount: PlotCancelStatus  # 3
kPlotCanceledByCaller: PlotCancelStatus  # 1
kPlotCanceledByCancelAllButton: PlotCancelStatus  # 2
kPlotContinue: PlotCancelStatus  # 0
kPlotToFileAllowed: PlotToFileCapability  # 1
kPublishToWebDWF: StdConfigs  # 5
kPublishToWebDWFx: StdConfigs  # 9
kPublishToWebJPG: StdConfigs  # 6
kPublishToWebPNG: StdConfigs  # 7
kRefreshDevicesList: RefreshCode  # 1
kRefreshPC3DevicesList: RefreshCode  # 4
kRefreshStyleList: RefreshCode  # 2
kRefreshSystemDevicesList: RefreshCode  # 3
kRegular: StyTypes  # 1
kSVFePlot: StdConfigs  # 15
kSheetCancelStatusCount: SheetCancelStatus  # 4
kSheetCanceledByCaller: SheetCancelStatus  # 3
kSheetCanceledByCancelAllButton: SheetCancelStatus  # 2
kSheetCanceledByCancelButton: SheetCancelStatus  # 1
kSheetContinue: SheetCancelStatus  # 0
kSheetName: PlotMSGIndex  # 1
kSheetNameToolTip: PlotMSGIndex  # 2
kSheetProgressCaption: PlotMSGIndex  # 4
kSheetSetProgressCaption: PlotMSGIndex  # 5
kSingleDWF: SheetType  # 0
kSingleDWFx: SheetType  # 3
kSinglePDF: SheetType  # 5
kSingleSVF: SheetType  # 7
kStatus: PlotMSGIndex  # 3
kSystemPrinter: DeviceType  # 0
kTranslation: StyTypes  # 2
kUndefined: StyTypes  # 0
kUninitialized: DeviceType  # -1
class Core:
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def processPlotState() -> ProcessPlotState:
        pass
    @staticmethod
    def publishExecute(dsdDataObj: PyPl.DSDData,pConfig: PyPl.PlotConfig,bShowPlotProgress: bool, /) -> None:
        pass
class CustomSizeResult(_BoostPythonEnum):
    ePossible: ClassVar[Self]  # 0
    eMustCreatePC3: ClassVar[Self]  # 1
    eRotationRequired: ClassVar[Self]  # 2
    ePC3DirReadOnly: ClassVar[Self]  # 4
    ePMPDirReadOnly: ClassVar[Self]  # 8
    ePMPDirMissing: ClassVar[Self]  # 16
    eUnknownErrPMPDir: ClassVar[Self]  # 32
    ePC3FileReadOnly: ClassVar[Self]  # 64
    eSizeTooBig: ClassVar[Self]  # 128
    eException: ClassVar[Self]  # 256
    eUnknownErrPC3File: ClassVar[Self]  # 512
    eUnknownErrPMPFile: ClassVar[Self]  # 1024
    ePMPFileReadOnly: ClassVar[Self]  # 2048
    eWidthAndHeightMustBePositive: ClassVar[Self]  # 4096
    eDeviceLoadFailed: ClassVar[Self]  # 8192
class DSDData(PyPl.PlObject):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    def categoryName(self, /) -> str:
        pass
    @staticmethod
    def className() -> str:
        pass
    def currentPrecision(self, /) -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def destinationName(self, /) -> str:
        pass
    def get3dDwfOptions(self, /) -> tuple[bool,bool]:
        pass
    def getDSDEntries(self, /) -> list[PyPl.DSDEntry]:
        pass
    def getPrecisionEntries(self, /) -> list[PyPl.PrecisionEntry]:
        pass
    def getUnrecognizedData(self, /) -> None:
        pass
    def includeLayerInfo(self, /) -> bool:
        pass
    def initializeLayouts(self, /) -> bool:
        pass
    def isHomogeneous(self, /) -> bool:
        pass
    def isSheetSet(self, /) -> bool:
        pass
    def lineMerge(self, /) -> bool:
        pass
    def logFilePath(self, /) -> str:
        pass
    def majorVersion(self, /) -> int:
        pass
    def minorVersion(self, /) -> int:
        pass
    def noOfCopies(self, /) -> int:
        pass
    def numberOfDSDEntries(self, /) -> int:
        pass
    def password(self, /) -> str:
        pass
    def plotStampOn(self, /) -> bool:
        pass
    def projectPath(self, /) -> str:
        pass
    def promptForDwfName(self, /) -> bool:
        pass
    def promptForPassword(self, /) -> bool:
        pass
    def pwdProtectPublishedDWF(self, /) -> bool:
        pass
    def selectionSetName(self, /) -> str:
        pass
    def set3dDwfOptions(self, /) -> None:
        pass
    def setCategoryName(self, /) -> None:
        pass
    def setCurrentPrecision(self, /) -> None:
        pass
    def setDSDEntries(self, /) -> None:
        pass
    def setDestinationName(self, /) -> None:
        pass
    def setIncludeLayerInfo(self, /) -> None:
        pass
    def setInitializeLayouts(self, /) -> None:
        pass
    def setIsHomogeneous(self, /) -> None:
        pass
    def setIsSheetSet(self, /) -> None:
        pass
    def setLineMerge(self, /) -> None:
        pass
    def setLogFilePath(self, /) -> None:
        pass
    def setMajorVersion(self, /) -> None:
        pass
    def setMinorVersion(self, /) -> None:
        pass
    def setNoOfCopies(self, /) -> None:
        pass
    def setPassword(self, /) -> None:
        pass
    def setPlotStampOn(self, /) -> None:
        pass
    def setPrecisionEntries(self, /) -> None:
        pass
    def setProjectPath(self, /) -> None:
        pass
    def setPromptForDwfName(self, /) -> None:
        pass
    def setPromptForPassword(self, /) -> None:
        pass
    def setPwdProtectPublishedDWF(self, /) -> None:
        pass
    def setSelectionSetName(self, /) -> None:
        pass
    def setSheetSetName(self, /) -> None:
        pass
    def setSheetType(self, /) -> None:
        pass
    def setUnrecognizedData(self, /) -> None:
        pass
    def setViewFile(self, /) -> None:
        pass
    def sheetSetName(self, /) -> str:
        pass
    def sheetType(self, /) -> SheetType:
        pass
    def viewFile(self, /) -> bool:
        pass
class DSDEntry(PyPl.PlObject):
    def NPS(self, /) -> str:
        pass
    def NPSSourceDWG(self, /) -> str:
        pass
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def dwgName(self, /) -> str:
        pass
    def has3dDwfSetup(self, /) -> bool:
        pass
    def layout(self, /) -> str:
        pass
    def orgSheetPath(self, /) -> str:
        pass
    def setDwgName(self, /) -> None:
        pass
    def setHas3dDwfSetup(self, /) -> None:
        pass
    def setLayout(self, /) -> None:
        pass
    def setNPS(self, /) -> None:
        pass
    def setNPSSourceDWG(self, /) -> None:
        pass
    def setSetupType(self, /) -> None:
        pass
    def setTitle(self, /) -> None:
        pass
    def setTraceSession(self, /) -> None:
        pass
    def setupType(self, /) -> SetupType:
        pass
    def title(self, /) -> str:
        pass
    def traceSession(self, /) -> str:
        pass
class DeviceType(_BoostPythonEnum):
    kSystemPrinter: ClassVar[Self]  # 0
    kPC3File: ClassVar[Self]  # 1
    kOneOffConfig: ClassVar[Self]  # 2
    kUninitialized: ClassVar[Self]  # -1
class MatchingPolicy(_BoostPythonEnum):
    kMatchDisabled: ClassVar[Self]  # 1
    kMatchEnabled: ClassVar[Self]  # 2
    kMatchEnabledCustom: ClassVar[Self]  # 3
    kMatchEnabledTmpCustom: ClassVar[Self]  # 4
class PlObject(PyRx.RxObject):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def className() -> str:
        pass
class PlotCancelStatus(_BoostPythonEnum):
    kPlotContinue: ClassVar[Self]  # 0
    kPlotCanceledByCaller: ClassVar[Self]  # 1
    kPlotCanceledByCancelAllButton: ClassVar[Self]  # 2
    kPlotCancelStatusCount: ClassVar[Self]  # 3
class PlotConfig(PyPl.PlObject):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def deviceName(self, /) -> str:
        pass
    def deviceType(self, /) -> int:
        pass
    def fullPath(self, /) -> str:
        pass
    def getCanonicalMediaNameList(self, /) -> list[str]:
        pass
    def getDefaultFileExtension(self, /) -> str:
        pass
    def getDescriptionFields(self, /) -> tuple[str,...]:
        pass
    def getLocalMediaName(self, /) -> str:
        pass
    def getMediaBounds(self, /) -> None:
        pass
    def isPlotToFile(self, /) -> bool:
        pass
    def maxDeviceDPI(self, /) -> int:
        pass
    def plotToFileCapability(self, /) -> PlotToFileCapability:
        pass
    def refreshMediaNameList(self, /) -> None:
        pass
    def saveToPC3(self, /) -> bool:
        pass
    def setPlotToFile(self, /) -> None:
        pass
class PlotConfigInfo(PyPl.PlObject):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def deviceId(self, /) -> str:
        pass
    def deviceName(self, /) -> str:
        pass
    def deviceType(self, /) -> DeviceType:
        pass
    def fullPath(self, /) -> str:
        pass
    def setDeviceId(self, /) -> None:
        pass
    def setDeviceName(self, /) -> None:
        pass
    def setDeviceType(self, /) -> None:
        pass
    def setFullPath(self, /) -> None:
        pass
class PlotConfigManager:
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def className() -> str:
        pass
    def getCurrentConfig(self, /) -> PlotConfig:
        pass
    def getDevicesList(self, /) -> list[PyPl.PlotConfigInfo]:
        pass
    def getStdConfigName(self, /) -> str:
        pass
    def getStyleList(self, /) -> list[str]:
        pass
    def refreshList(self, refreshCode:PyPl.RefreshCode= PyPl.RefreshCode.kAll, /) -> None:
        pass
    def setCurrentConfig(self, deviceName: str, /) -> PlotConfig:
        pass
class PlotEngine:
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    def beginDocument(self, /) -> None:
        pass
    def beginGenerateGraphics(self, /) -> None:
        pass
    def beginPage(self, /) -> None:
        pass
    def beginPlot(self, /) -> None:
        pass
    @staticmethod
    def className() -> str:
        pass
    def destroy(self, /) -> None:
        pass
    def endDocument(self, /) -> None:
        pass
    def endGenerateGraphics(self, /) -> None:
        pass
    def endPage(self, /) -> None:
        pass
    def endPlot(self, /) -> None:
        pass
    def isBackgroundPackaging(self, /) -> bool:
        pass
class PlotFactory:
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def createPreviewEngine(flags : int = 1, /) -> PlotEngine:
        pass
    @staticmethod
    def createPublishEngine() -> PlotEngine:
        pass
    @staticmethod
    def processPlotState() -> ProcessPlotState:
        pass
class PlotInfo(PyPl.PlObject):
    def OrgFilePath(self, /) -> str:
        pass
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def className() -> str:
        pass
    def copyFrom(self, /) -> None:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def deviceOverride(self, /) -> PlotConfig:
        pass
    def isCompatibleDocument(self, /) -> bool:
        pass
    def isValidated(self, /) -> bool:
        pass
    def layout(self, /) -> PyDb.ObjectId:
        pass
    def mergeStatus(self, /) -> int:
        pass
    def overrideSettings(self, /) -> PyDb.PlotSettings:
        pass
    def setDeviceOverride(self, /) -> None:
        pass
    def setLayout(self, /) -> None:
        pass
    def setOverrideSettings(self, /) -> None:
        pass
    def setValidatedConfig(self, /) -> None:
        pass
    def setValidatedSettings(self, /) -> None:
        pass
    def validatedConfig(self, /) -> PlotConfig:
        pass
    def validatedSettings(self, /) -> PyDb.PlotSettings:
        pass
class PlotInfoValidator(PyPl.PlObject):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def dimensionalWeight(self, /) -> int:
        pass
    def isCustomPossible(self, /) -> CustomSizeResult:
        pass
    def matchingPolicy(self, /) -> MatchingPolicy:
        pass
    def mediaBoundsWeight(self, /) -> int:
        pass
    def mediaGroupWeight(self, /) -> int:
        pass
    def mediaMatchingThreshold(self, /) -> int:
        pass
    def printableBoundsWeight(self, /) -> int:
        pass
    def setDefDimensionalWeight(self, /) -> None:
        pass
    def setDefMediaBoundsWeight(self, /) -> None:
        pass
    def setDefMediaGroupWeight(self, /) -> None:
        pass
    def setDefMediaMatchingThreshold(self, /) -> None:
        pass
    def setDefPrintableBoundsWeight(self, /) -> None:
        pass
    def setDefSheetDimensionalWeight(self, /) -> None:
        pass
    def setDefSheetMediaGroupWeight(self, /) -> None:
        pass
    def setDimensionalWeight(self, /) -> None:
        pass
    def setMediaBoundsWeight(self, /) -> None:
        pass
    def setMediaGroupWeight(self, /) -> None:
        pass
    def setMediaMatchingPolicy(self, /) -> None:
        pass
    def setMediaMatchingThreshold(self, /) -> None:
        pass
    def setPrintableBoundsWeight(self, /) -> None:
        pass
    def setSheetDimensionalWeight(self, /) -> None:
        pass
    def setSheetMediaGroupWeight(self, /) -> None:
        pass
    def sheetDimensionalWeight(self, /) -> int:
        pass
    def sheetMediaGroupWeight(self, /) -> int:
        pass
    def validate(self, /) -> None:
        pass
class PlotMSGIndex(_BoostPythonEnum):
    kDialogTitle: ClassVar[Self]  # 0
    kSheetName: ClassVar[Self]  # 1
    kSheetNameToolTip: ClassVar[Self]  # 2
    kStatus: ClassVar[Self]  # 3
    kSheetProgressCaption: ClassVar[Self]  # 4
    kSheetSetProgressCaption: ClassVar[Self]  # 5
    kMsgCancelling: ClassVar[Self]  # 6
    kMsgCancellingCurrent: ClassVar[Self]  # 7
    kCancelSheetBtnMsg: ClassVar[Self]  # 8
    kCancelJobBtnMsg: ClassVar[Self]  # 9
    kMsgCount: ClassVar[Self]  # 10
class PlotPageInfo(PyPl.PlObject):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def entityCount() -> int:
        pass
    def gradientCount() -> int:
        pass
    def oleObjectCount() -> int:
        pass
    def rasterCount() -> int:
        pass
    def shadedViewportType() -> int:
        pass
class PlotProgressDialog:
    @overload
    def __init__(self, /) -> None: ...
    @overload
    def __init__(self, bPreview:bool, nSheets:int, bShowCancelSheetButton:bool, /) -> None: ...
    @overload
    def __init__(self, hwnd:int, bPreview:bool, nSheets:int, bShowCancelSheetButton:bool, /) -> None: ...
    def __init__(self, *args) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def className() -> str:
        pass
    def destroy(self, /) -> None:
        pass
    def getPlotMsgString(self, index:PyPl.PlotMSGIndex, /) -> str:
        pass
    def getPlotProgressRange(self, /) -> tuple[int,int]:
        pass
    def getSheetProgressRange(self, /) -> tuple[int,int]:
        pass
    def getStatusMsgString(self, /) -> str:
        pass
    def heartbeat(self, /) -> None:
        pass
    def isPlotCancelled(self, /) -> bool:
        pass
    def isSheetCancelled(self, /) -> bool:
        pass
    def isSingleSheetPlot(self, /) -> bool:
        pass
    def isVisible(self, /) -> bool:
        pass
    def onBeginPlot(self, /) -> bool:
        pass
    def onBeginSheet(self, /) -> bool:
        pass
    def onEndPlot(self, /) -> bool:
        pass
    def onEndSheet(self, /) -> bool:
        pass
    def plotCancelStatus(self, /) -> PlotCancelStatus:
        pass
    def plotProgressPos(self, /) -> int:
        pass
    def setIsVisible(self, val: bool, /) -> bool:
        pass
    def setPlotCancelStatus(self, val:PyPl.PlotCancelStatus, /) -> None:
        pass
    def setPlotMsgString(self, index:PyPl.PlotMSGIndex, val: str, /) -> bool:
        pass
    def setPlotProgressPos(self, pos: int, /) -> None:
        pass
    def setPlotProgressRange(self, lower: int, upper: int, /) -> None:
        pass
    def setSheetCancelStatus(self, val:PyPl.SheetCancelStatus, /) -> None:
        pass
    def setSheetProgressPos(self, pos: int, /) -> None:
        pass
    def setSheetProgressRange(self, lower: int, upper: int, /) -> None:
        pass
    def setStatusMsgString(self, val: str, /) -> bool:
        pass
    def sheetCancelStatus(self, /) -> SheetCancelStatus:
        pass
    def sheetProgressPos(self, /) -> int:
        pass
class PlotToFileCapability(_BoostPythonEnum):
    kNoPlotToFile: ClassVar[Self]  # 0
    kPlotToFileAllowed: ClassVar[Self]  # 1
    kMustPlotToFile: ClassVar[Self]  # 2
class PrecisionEntry(PyPl.PlObject):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def className() -> str:
        pass
    def colorResolution(self, /) -> int:
        pass
    @staticmethod
    def desc() -> PyRx.RxClass:
        """
        Returns a pointer to the AcRxClass object representing the specific class, or most recent
        parent class explicitly registered with ObjectARX of either the pointer type used to invoke
        it or the class qualifier used with it. (Remember that when a static member function is
        invoked via a pointer, the pointer type, not the object type, determines which
        implementation of the function is invoked.) When working with a pointer to an object and
        the proper AcRxClass object for the class of the object pointed to is desired, the
        AcRxObject::isA() function should be used, since it is a virtual non-static method and is
        therefore not pointer type dependent. Caching the value of the pointer returned by this
        method is acceptable, provided the application knows that the AcRxClass object pointed to
        by the returned pointer was created by an ObjectARX application that will not be unloaded.
        """
    def description(self, /) -> str:
        pass
    def desiredPrecision(self, /) -> float:
        pass
    def gradientResolution(self, /) -> int:
        pass
    def monoResolution(self, /) -> int:
        pass
    def setColorResolution(self, /) -> None:
        pass
    def setDescription(self, /) -> None:
        pass
    def setDesiredPrecision(self, /) -> None:
        pass
    def setGradientResolution(self, /) -> None:
        pass
    def setMonoResolution(self, /) -> None:
        pass
    def setTitle(self, /) -> None:
        pass
    def setUnitScale(self, /) -> None:
        pass
    def setUnitType(self, /) -> None:
        pass
    def title(self, /) -> str:
        pass
    def unitScale(self, /) -> str:
        pass
    def unitType(self, /) -> str:
        pass
class ProcessPlotState(_BoostPythonEnum):
    kNotPlotting: ClassVar[Self]  # 0
    kForegroundPlotting: ClassVar[Self]  # 1
    kBackgroundPlotting: ClassVar[Self]  # 2
class RefreshCode(_BoostPythonEnum):
    kAll: ClassVar[Self]  # 0
    kRefreshDevicesList: ClassVar[Self]  # 1
    kRefreshStyleList: ClassVar[Self]  # 2
    kRefreshSystemDevicesList: ClassVar[Self]  # 3
    kRefreshPC3DevicesList: ClassVar[Self]  # 4
class SetupType(_BoostPythonEnum):
    kOriginalPS: ClassVar[Self]  # 0
    kNPSSameDWG: ClassVar[Self]  # 1
    kNPSOtherDWG: ClassVar[Self]  # 2
    k3dDwf: ClassVar[Self]  # 3
    kOverridePS: ClassVar[Self]  # 4
class SheetCancelStatus(_BoostPythonEnum):
    kSheetContinue: ClassVar[Self]  # 0
    kSheetCanceledByCancelButton: ClassVar[Self]  # 1
    kSheetCanceledByCancelAllButton: ClassVar[Self]  # 2
    kSheetCanceledByCaller: ClassVar[Self]  # 3
    kSheetCancelStatusCount: ClassVar[Self]  # 4
class SheetType(_BoostPythonEnum):
    kSingleDWF: ClassVar[Self]  # 0
    kMultiDWF: ClassVar[Self]  # 1
    kOriginalDevice: ClassVar[Self]  # 2
    kSingleDWFx: ClassVar[Self]  # 3
    kMultiDWFx: ClassVar[Self]  # 4
    kSinglePDF: ClassVar[Self]  # 5
    kMultiPDF: ClassVar[Self]  # 6
    kSingleSVF: ClassVar[Self]  # 7
    kMultiSVF: ClassVar[Self]  # 8
class StdConfigs(_BoostPythonEnum):
    kNoneDevice: ClassVar[Self]  # 0
    kDefaultWindowsSysPrinter: ClassVar[Self]  # 1
    kDWF6ePlot: ClassVar[Self]  # 2
    kDWFePlotOptForPlotting: ClassVar[Self]  # 3
    kDWFePlotOptForViewing: ClassVar[Self]  # 4
    kPublishToWebDWF: ClassVar[Self]  # 5
    kPublishToWebJPG: ClassVar[Self]  # 6
    kPublishToWebPNG: ClassVar[Self]  # 7
    kDWFxePlot: ClassVar[Self]  # 8
    kPublishToWebDWFx: ClassVar[Self]  # 9
    kPDFePlot: ClassVar[Self]  # 10
    kPDFePlotGeneralDocs: ClassVar[Self]  # 11
    kPDFePlotHighQuality: ClassVar[Self]  # 12
    kPDFePlotSmallerFile: ClassVar[Self]  # 13
    kPDFePlotWebMobile: ClassVar[Self]  # 14
    kSVFePlot: ClassVar[Self]  # 15
class StyTypes(_BoostPythonEnum):
    kUndefined: ClassVar[Self]  # 0
    kRegular: ClassVar[Self]  # 1
    kTranslation: ClassVar[Self]  # 2
    kColorDep: ClassVar[Self]  # 4
    kAllTypes: ClassVar[Self]  # 7
