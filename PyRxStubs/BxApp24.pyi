from _typeshed import Incomplete
from win32com.client import CoClassBaseClass, DispatchBaseClass

makepy_version: str
python_version: int
defaultNamedOptArg: Incomplete
defaultNamedNotOptArg: Incomplete
defaultUnnamedArg: Incomplete
CLSID: Incomplete
MajorVersion: int
MinorVersion: int
LibraryFlags: int
LCID: int

class constants:
    acLsAll: int
    acLsColor: int
    acLsFrozen: int
    acLsLineType: int
    acLsLineWeight: int
    acLsLocked: int
    acLsNewViewport: int
    acLsNone: int
    acLsOn: int
    acLsPlot: int
    acLsPlotStyle: int
    ACADSECURITYPARAMS_ALGID_RC4: int
    ACADSECURITYPARAMS_ADD_TIMESTAMP: int
    ACADSECURITYPARAMS_ENCRYPT_DATA: int
    ACADSECURITYPARAMS_ENCRYPT_PROPS: int
    ACADSECURITYPARAMS_SIGN_DATA: int
    odDwfAscii: int
    odDwfCompressedBinary: int
    odDwfUncompressedBinary: int
    odDwf_v42: int
    odDwf_v55: int
    odDwf_v60: int
    od2000_Template: int
    od2000_dwg: int
    od2000_dxf: int
    od2004_Template: int
    od2004_dwg: int
    od2004_dxf: int
    od2007_Template: int
    od2007_dwg: int
    od2007_dxf: int
    od2010_Template: int
    od2010_dwg: int
    od2010_dxf: int
    od2013_Template: int
    od2013_dwg: int
    od2013_dxf: int
    od2018_Template: int
    od2018_dwg: int
    od2018_dxf: int
    odNative: int
    odR09_dxf: int
    odR10_dxf: int
    odR12_dwg: int
    odR12_dxf: int
    odR13_dwg: int
    odR13_dxf: int
    odR14_dwg: int
    odR14_dxf: int
    odR15_Template: int
    odR15_dwg: int
    odR15_dxf: int
    odR18_Template: int
    odR18_dwg: int
    odR18_dxf: int
    odR21_Template: int
    odR21_dwg: int
    odR21_dxf: int
    odR24_Template: int
    odR24_dwg: int
    odR24_dxf: int
    odR27_Template: int
    odR27_dwg: int
    odR27_dxf: int
    odR32_Template: int
    odR32_dwg: int
    odR32_dxf: int
    odUnknown: int
    PDFEXPORT_EXCLUDE_OFFLAYER: int
    PDFEXPORT_INCLUDE_OFFLAYER: int
    PDFEXPORT_NOLAYER: int
    PDFEXPORT_LAYOUTS_ACTIVE: int
    PDFEXPORT_LAYOUTS_ALL: int
    e3rdPartyAddedFile: int
    eAltFontFile: int
    eDGNUnderlay: int
    eDWFUnderlay: int
    eDataLinkFile: int
    eDwgFile: int
    eEdgeTextureFile: int
    eFontFile: int
    eFontMapFile: int
    eGeneratedFile: int
    eImageFile: int
    eMaterialTextureFile: int
    eNoType: int
    ePDFUnderlay: int
    ePfbAltFontFile: int
    ePfbFontFile: int
    ePhotometricWebFile: int
    ePlotCfgFile: int
    ePlotStyleTableFile: int
    eSheetSetFile: int
    eSheetSetSupportFile: int
    eShxAltFontFile: int
    eShxFontFile: int
    eTtfAltFontFile: int
    eTtfFontFile: int
    eUserAddedFile: int
    eXrefAttachFile: int
    eXrefFile: int
    eXrefOverlayFile: int
    eFileAdded: int
    eFileAlreadyAdded: int
    eFileNotAdded: int
    eFileNotAddedBadArg: int
    eFileNotAddedToPreventCycle: int
    eRelationshipAdded: int
    eAutoCAD14: int
    eAutoCAD2000: int
    eAutoCADR18: int
    eAutoCADR21: int
    eNoConversion: int
    eOverwriteCancel: int
    eOverwriteNo: int
    eOverwriteYes: int
    eOverwriteYesToAll: int
    eOverwriteYesToAllReadOnly: int

class IAcadApplication(DispatchBaseClass):
    CLSID: Incomplete
    coclass_clsid: Incomplete
    def DefineFunction(self, FunctionName=..., FunctionPointer=...): ...
    def Eval(self, Expression=...): ...
    def GetAcadState(self): ...
    def GetInterfaceObject(self, ProgID=...): ...
    def ListArx(self): ...
    def LoadArx(self, Name=...): ...
    def LoadDVB(self, Name=...): ...
    def Quit(self): ...
    def RunCommand(self, Command=...): ...
    def RunMacro(self, MacroPath=...): ...
    def RunScript(self, Script=...): ...
    def StatusId(self, VportObj=...): ...
    def UndefineFunction(self, FunctionName=...): ...
    def UnloadArx(self, Name=...): ...
    def UnloadDVB(self, Name=...): ...
    def Update(self): ...
    def Zoom(self, Type=..., vParams=...): ...
    def ZoomAll(self): ...
    def ZoomCenter(self, Center=..., Magnify=...): ...
    def ZoomExtents(self): ...
    def ZoomPickWindow(self): ...
    def ZoomPrevious(self): ...
    def ZoomScaled(self, scale=..., ScaleType=...): ...
    def ZoomWindow(self, LowerLeft=..., UpperRight=...): ...
    def __iter__(self): ...

class IAcadDocument(DispatchBaseClass):
    CLSID: Incomplete
    coclass_clsid: Incomplete
    def AbortTransaction(self): ...
    def Activate(self): ...
    def AuditInfo(self, FixErr=...): ...
    def Close(self, SaveChanges=..., FileName=...): ...
    def CopyObjects(self, Objects=..., Owner=..., IdPairs=...): ...
    def EndTransaction(self): ...
    def EndUndoMark(self): ...
    def EvaluateLisp(self, lispString=...): ...
    def Export(self, FileName=..., Extension=..., SelectionSet=...): ...
    def GetVariable(self, Name=...): ...
    def HandleToObject(self, Handle=...): ...
    def Import(self, FileName=..., InsertionPoint=..., ScaleFactor=...): ...
    def LoadShapeFile(self, FullName=...): ...
    def New(self, TemplateFileName=...): ...
    def ObjectIdToObject(self, ObjectID=...): ...
    def ObjectIdToObject32(self, ObjectID=...): ...
    def Open(self, FullName=..., Password=...): ...
    def PurgeAll(self): ...
    def Regen(self, WhichViewports=...): ...
    def Save(self): ...
    def SaveAs(self, FullFileName=..., SaveAsType=..., vSecurityParams=...): ...
    def SendCommand(self, Command=...): ...
    def SetVariable(self, Name=..., Value=...): ...
    def StartTransaction(self): ...
    def StartUndoMark(self): ...
    def Wblock(self, FileName=..., SelectionSet=...): ...
    def getTransmittalOperationInterface(self): ...
    def __iter__(self): ...

class IAcadDocuments(DispatchBaseClass):
    CLSID: Incomplete
    coclass_clsid: Incomplete
    def Add(self, TemplateName=...): ...
    def Close(self): ...
    def Item(self, Index=...): ...
    def Open(self, Name=..., ReadOnly=..., Password=...): ...
    def __call__(self, Index=...): ...
    def __int__(self, *args) -> int: ...
    def __iter__(self): ...
    def __len__(self) -> int: ...
    def __nonzero__(self): ...

class IAcadLayerStateManager(DispatchBaseClass):
    CLSID: Incomplete
    coclass_clsid: Incomplete
    def Delete(self, bsName=...): ...
    def Export(self, bsName=..., bsFilename=...): ...
    def Import(self, bsFilename=...): ...
    def Mask(self, bsName=...): ...
    def Rename(self, bsName=..., bsNewName=...): ...
    def Restore(self, bsName=...): ...
    def Save(self, bsName=..., eMask=...): ...
    def SetDatabase(self, iHostDb=...): ...
    def SetMask(self, bsName=..., arg1=...): ...
    def __iter__(self): ...

class IAcadMenuBar(DispatchBaseClass):
    CLSID: Incomplete
    coclass_clsid: Incomplete
    def Item(self, Index=...): ...
    def __call__(self, Index=...): ...
    def __int__(self, *args) -> int: ...
    def __iter__(self): ...
    def __len__(self) -> int: ...
    def __nonzero__(self): ...

class IAcadMenuGroup(DispatchBaseClass):
    CLSID: Incomplete
    coclass_clsid: Incomplete
    def Save(self, MenuFileType=...): ...
    def SaveAs(self, MenuFileName=..., MenuFileType=...): ...
    def Unload(self): ...
    def __iter__(self): ...

class IAcadMenuGroups(DispatchBaseClass):
    CLSID: Incomplete
    coclass_clsid: Incomplete
    def Item(self, Index=...): ...
    def Load(self, MenuFileName=..., BaseMenu=...): ...
    def __call__(self, Index=...): ...
    def __int__(self, *args) -> int: ...
    def __iter__(self): ...
    def __len__(self) -> int: ...
    def __nonzero__(self): ...

class IAcadPlot(DispatchBaseClass):
    CLSID: Incomplete
    coclass_clsid: Incomplete
    def DisplayPlotPreview(self, PreviewMode=...): ...
    def PlotToDevice(self, plotConfig=...): ...
    def PlotToFile(self, plotFile=..., plotConfig=...): ...
    def SetLayoutsToPlot(self, layoutList=...): ...
    def StartBatchMode(self, entryCount=...): ...
    def __iter__(self): ...

class IAcadPopupMenu(DispatchBaseClass):
    CLSID: Incomplete
    coclass_clsid: Incomplete
    def AddMenuItem(self, Index=..., Label=..., Macro=...): ...
    def AddSeparator(self, Index=...): ...
    def AddSubMenu(self, Index=..., Label=...): ...
    def InsertInMenuBar(self, Index=...): ...
    def Item(self, Index=...): ...
    def RemoveFromMenuBar(self): ...
    def __call__(self, Index=...): ...
    def __int__(self, *args) -> int: ...
    def __iter__(self): ...
    def __len__(self) -> int: ...
    def __nonzero__(self): ...

class IAcadPopupMenuItem(DispatchBaseClass):
    CLSID: Incomplete
    coclass_clsid: Incomplete
    def Delete(self): ...
    def __iter__(self): ...

class IAcadPopupMenus(DispatchBaseClass):
    CLSID: Incomplete
    coclass_clsid: Incomplete
    def Add(self, MenuName=...): ...
    def InsertMenuInMenuBar(self, MenuName=..., Index=...): ...
    def Item(self, Index=...): ...
    def RemoveMenuFromMenuBar(self, Index=...): ...
    def __call__(self, Index=...): ...
    def __int__(self, *args) -> int: ...
    def __iter__(self): ...
    def __len__(self) -> int: ...
    def __nonzero__(self): ...

class IAcadPreferences(DispatchBaseClass):
    CLSID: Incomplete
    coclass_clsid: Incomplete
    def __iter__(self): ...

class IAcadPreferencesDisplay(DispatchBaseClass):
    CLSID: Incomplete
    coclass_clsid: Incomplete
    def __iter__(self): ...

class IAcadPreferencesDrafting(DispatchBaseClass):
    CLSID: Incomplete
    coclass_clsid: Incomplete
    def __iter__(self): ...

class IAcadPreferencesFiles(DispatchBaseClass):
    CLSID: Incomplete
    coclass_clsid: Incomplete
    def GetProjectFilePath(self, ProjectName=...): ...
    def SetProjectFilePath(self, ProjectName=..., ProjectFilePath=...): ...
    def __call__(self): ...
    def __int__(self, *args) -> int: ...
    def __iter__(self): ...

class IAcadPreferencesOpenSave(DispatchBaseClass):
    CLSID: Incomplete
    coclass_clsid: Incomplete
    def __iter__(self): ...

class IAcadPreferencesOutput(DispatchBaseClass):
    CLSID: Incomplete
    coclass_clsid: Incomplete
    def __iter__(self): ...

class IAcadPreferencesPdfOutput(DispatchBaseClass):
    CLSID: Incomplete
    coclass_clsid: Incomplete
    def __iter__(self): ...

class IAcadPreferencesProfiles(DispatchBaseClass):
    CLSID: Incomplete
    coclass_clsid: Incomplete
    def CopyProfile(self, oldProfileName=..., newProfileName=...): ...
    def DeleteProfile(self, ProfileName=...): ...
    def ExportProfile(self, ProfileName=..., RegFile=...): ...
    def GetAllProfileNames(self, pNames=...): ...
    def ImportProfile(self, ProfileName=..., RegFile=..., IncludePathInfo=...): ...
    def RenameProfile(self, origProfileName=..., newProfileName=...): ...
    def ResetProfile(self, Profile=...): ...
    def __iter__(self): ...

class IAcadPreferencesSelection(DispatchBaseClass):
    CLSID: Incomplete
    coclass_clsid: Incomplete
    def __iter__(self): ...

class IAcadPreferencesSystem(DispatchBaseClass):
    CLSID: Incomplete
    coclass_clsid: Incomplete
    def __iter__(self): ...

class IAcadPreferencesUser(DispatchBaseClass):
    CLSID: Incomplete
    coclass_clsid: Incomplete
    def __iter__(self): ...

class IAcadSecurityParams(DispatchBaseClass):
    CLSID: Incomplete
    coclass_clsid: Incomplete
    def __iter__(self): ...

class IAcadSelectionSet(DispatchBaseClass):
    CLSID: Incomplete
    coclass_clsid: Incomplete
    def AddItems(self, pSelSet=...): ...
    def Clear(self): ...
    def Delete(self): ...
    def Erase(self): ...
    def Highlight(self, bFlag=...): ...
    def Item(self, Index=...): ...
    def RemoveItems(self, Objects=...): ...
    def Select(self, Mode=..., Point1=..., Point2=..., FilterType=..., FilterData=...): ...
    def SelectAtPoint(self, Point=..., FilterType=..., FilterData=...): ...
    def SelectByPolygon(self, Mode=..., PointsList=..., FilterType=..., FilterData=...): ...
    def SelectOnScreen(self, FilterType=..., FilterData=...): ...
    def Update(self): ...
    def __call__(self, Index=...): ...
    def __int__(self, *args) -> int: ...
    def __iter__(self): ...
    def __len__(self) -> int: ...
    def __nonzero__(self): ...

class IAcadSelectionSets(DispatchBaseClass):
    CLSID: Incomplete
    coclass_clsid: Incomplete
    def Add(self, Name=...): ...
    def Item(self, Index=...): ...
    def __call__(self, Index=...): ...
    def __int__(self, *args) -> int: ...
    def __iter__(self): ...
    def __len__(self) -> int: ...
    def __nonzero__(self): ...

class IAcadState(DispatchBaseClass):
    CLSID: Incomplete
    coclass_clsid: Incomplete
    def __iter__(self): ...

class IAcadToolbar(DispatchBaseClass):
    CLSID: Incomplete
    coclass_clsid: Incomplete
    def AddSeparator(self, Index=...): ...
    def AddToolbarButton(self, Index=..., Name=..., HelpString=..., Macro=..., FlyoutButton=...): ...
    def Delete(self): ...
    def Dock(self, Side=...): ...
    def Float(self, top=..., left=..., NumberFloatRows=...): ...
    def Item(self, Index=...): ...
    def __call__(self, Index=...): ...
    def __int__(self, *args) -> int: ...
    def __iter__(self): ...
    def __len__(self) -> int: ...
    def __nonzero__(self): ...

class IAcadToolbarItem(DispatchBaseClass):
    CLSID: Incomplete
    coclass_clsid: Incomplete
    def AttachToolbarToFlyout(self, MenuGroupName=..., ToolbarName=...): ...
    def Delete(self): ...
    def GetBitmaps(self, SmallIconName=..., LargeIconName=...): ...
    def SetBitmaps(self, SmallIconName=..., LargeIconName=...): ...
    def __iter__(self): ...

class IAcadToolbars(DispatchBaseClass):
    CLSID: Incomplete
    coclass_clsid: Incomplete
    def Add(self, ToolbarName=...): ...
    def Item(self, Index=...): ...
    def __call__(self, Index=...): ...
    def __int__(self, *args) -> int: ...
    def __iter__(self): ...
    def __len__(self) -> int: ...
    def __nonzero__(self): ...

class IAcadUtility(DispatchBaseClass):
    CLSID: Incomplete
    coclass_clsid: Incomplete
    def AngleFromXAxis(self, StartPoint=..., EndPoint=...): ...
    def AngleToReal(self, Angle=..., Unit=...): ...
    def AngleToString(self, Angle=..., Unit=..., precision=...): ...
    def CreateTypedArray(self, *args): ...
    def DistanceToReal(self, Distance=..., Unit=...): ...
    def GetAngle(self, Point=..., Prompt=...): ...
    def GetCorner(self, Point=..., Prompt=...): ...
    def GetDistance(self, Point=..., Prompt=...): ...
    def GetEntity(self, Object=..., PickedPoint=..., Prompt=...): ...
    def GetInput(self): ...
    def GetInteger(self, Prompt=...): ...
    def GetKeyword(self, Prompt=...): ...
    def GetObjectIdString(self, Object=..., asHex=...): ...
    def GetOrientation(self, Point=..., Prompt=...): ...
    def GetPoint(self, Point=..., Prompt=...): ...
    def GetReal(self, Prompt=...): ...
    def GetRemoteFile(self, URL=..., LocalFile=..., IgnoreCache=...): ...
    def GetString(self, HasSpaces=..., Prompt=...): ...
    def GetSubEntity(self, Object=..., PickedPoint=..., transMatrix=..., ContextData=..., Prompt=...): ...
    def InitializeUserInput(self, Bits=..., KeyWordList=...): ...
    def IsRemoteFile(self, LocalFile=..., URL=...): ...
    def IsURL(self, URL=...): ...
    def LaunchBrowserDialog(self, SelectedURL=..., DialogTitle=..., OpenButtonCaption=..., StartPageURL=..., RegistryRootKey=..., OpenButtonAlwaysEnabled=...): ...
    def LogMessage(self, msg=...): ...
    def ObjectId32ToObjectIdString(self, objectId32=...): ...
    def PolarPoint(self, Point=..., Angle=..., Distance=...): ...
    def Prompt(self, Message=...): ...
    def PutRemoteFile(self, URL=..., LocalFile=...): ...
    def RealToString(self, Value=..., Unit=..., precision=...): ...
    def SendModelessOperationEnded(self, operation=...): ...
    def SendModelessOperationStart(self, operation=...): ...
    def TranslateCoordinates(self, Point=..., FromCoordSystem=..., ToCoordSystem=..., Displacement=..., OCSNormal=...): ...
    def __iter__(self): ...

class IOdaAuditInfo(DispatchBaseClass):
    CLSID: Incomplete
    coclass_clsid: Incomplete
    def __iter__(self): ...

class IOdaBagFiler(DispatchBaseClass):
    CLSID: Incomplete
    coclass_clsid: Incomplete
    def BufferToObject(self, pObj=..., ResType=..., ResValue=...): ...
    def ObjectToBuffer(self, pObj=..., ResType=..., ResValue=...): ...
    def __iter__(self): ...

class IOdaBmpOut(DispatchBaseClass):
    CLSID: Incomplete
    coclass_clsid: Incomplete
    def WriteFile(self, database=..., BitmapName=...): ...
    def __iter__(self): ...

class IOdaConsole(DispatchBaseClass):
    CLSID: Incomplete
    coclass_clsid: Incomplete
    def GetString(self, bAllowSpaces=...): ...
    def PutString(self, text=...): ...
    def __iter__(self): ...

class IOdaDwf3dExport(DispatchBaseClass):
    CLSID: Incomplete
    coclass_clsid: Incomplete
    def Export3dDwf(self, database=..., FileName=...): ...
    def __iter__(self): ...

class IOdaDwfImporter(DispatchBaseClass):
    CLSID: Incomplete
    coclass_clsid: Incomplete
    def Import(self, database=..., FileName=..., Password: str = ..., wPaper: float = ..., hPaper: float = ...): ...
    def __iter__(self): ...

class IOdaDwfImporter2(DispatchBaseClass):
    CLSID: Incomplete
    coclass_clsid: Incomplete
    def Close(self): ...
    def Import(self, database=..., FileName=..., Password: str = ..., wPaper: float = ..., hPaper: float = ...): ...
    def Properties(self, Name=...): ...
    def SetProperties(self, Name=..., arg1=...): ...
    def __iter__(self): ...

class IOdaDwfPageData(DispatchBaseClass):
    CLSID: Incomplete
    coclass_clsid: Incomplete
    def __iter__(self): ...

class IOdaDwfTemplate(DispatchBaseClass):
    CLSID: Incomplete
    coclass_clsid: Incomplete
    def AddPage(self, LayoutName=...): ...
    def Page(self, Index=...): ...
    def RemoveAllPages(self): ...
    def RemovePage(self, Index=...): ...
    def WriteFile(self, database=..., FileName=..., FileType=..., version=...): ...
    def __iter__(self): ...

class IOdaHostApp(DispatchBaseClass):
    CLSID: Incomplete
    coclass_clsid: Incomplete
    def AuditDatabase(self, pDoc=..., bFixErrors=...): ...
    def BrowseForOpenFileName(self, rootFolder=..., fileFilter=..., bOk=..., FileName=...): ...
    def OriginalFileType(self, pDoc=..., FileType=...): ...
    def Recover(self, FileName=..., Password=...): ...
    def __iter__(self): ...

class IOdaHostApp2(DispatchBaseClass):
    CLSID: Incomplete
    coclass_clsid: Incomplete
    def AuditDatabase(self, pDoc=..., bFixErrors=...): ...
    def BrowseForOpenFileName(self, rootFolder=..., fileFilter=..., bOk=..., FileName=...): ...
    def OriginalFileType(self, pDoc=..., FileType=...): ...
    def Recover(self, FileName=..., Password=...): ...
    def __iter__(self): ...

class IOdaSvgExporter(DispatchBaseClass):
    CLSID: Incomplete
    coclass_clsid: Incomplete
    def Export(self, database=..., FilePath=...): ...
    def Properties(self, Name=...): ...
    def SetProperties(self, Name=..., arg1=...): ...
    def __iter__(self): ...

class ITransmittalFile(DispatchBaseClass):
    CLSID: Incomplete
    coclass_clsid: Incomplete
    def getDependee(self, nIndex=...): ...
    def getDependent(self, nIndex=...): ...
    def __iter__(self): ...

class ITransmittalFilesGraph(DispatchBaseClass):
    CLSID: Incomplete
    coclass_clsid: Incomplete
    def addEdge(self, pTransmitFileFrom=..., pTransmitFileTo=...): ...
    def getAt(self, nIndex=...): ...
    def getNumberOfFiles(self, bIncludeMissingFiles=..., bIncludeUnselectedFiles=...): ...
    def getRoot(self): ...
    def removeEdge(self, pTransmitFile=..., pParentFile=...): ...
    def reset(self): ...
    def totalBytes(self, bIncludedFilesOnly=...): ...
    def __iter__(self): ...

class ITransmittalInfo(DispatchBaseClass):
    CLSID: Incomplete
    coclass_clsid: Incomplete
    def __iter__(self): ...

class ITransmittalOperation(DispatchBaseClass):
    CLSID: Incomplete
    coclass_clsid: Incomplete
    def addDrawingFile(self, fullpathname=..., ppIAddedFile=...): ...
    def addFile(self, bstrFullPath=..., pIParentFile=..., bAddedBy3rdParty=..., ppIAddedFile=...): ...
    def addToReport(self, bstrTextToAdd=..., nIndex=...): ...
    def createTransmittalPackage(self): ...
    def getTransmittalGraphInterface(self): ...
    def getTransmittalInfoInterface(self): ...
    def getTransmittalReport(self): ...
    def __iter__(self): ...

class _DAcadApplicationEvents:
    CLSID: Incomplete
    CLSID_Sink: Incomplete
    coclass_clsid: Incomplete
    def __init__(self, oobj: Incomplete | None = ...) -> None: ...
    def __del__(self) -> None: ...
    def close(self) -> None: ...

class _DAcadDocumentEvents:
    CLSID: Incomplete
    CLSID_Sink: Incomplete
    coclass_clsid: Incomplete
    def __init__(self, oobj: Incomplete | None = ...) -> None: ...
    def __del__(self) -> None: ...
    def close(self) -> None: ...

class _IOdaHostAppEvents:
    CLSID: Incomplete
    CLSID_Sink: Incomplete
    coclass_clsid: Incomplete
    def __init__(self, oobj: Incomplete | None = ...) -> None: ...
    def __del__(self) -> None: ...
    def close(self) -> None: ...

class AcPePick2PointsCtrl(CoClassBaseClass):
    CLSID: Incomplete
    coclass_sources: Incomplete
    coclass_interfaces: Incomplete

class AcPePropertyEditorColor(CoClassBaseClass):
    CLSID: Incomplete
    coclass_sources: Incomplete
    coclass_interfaces: Incomplete

class AcPePropertyEditorEllipses(CoClassBaseClass):
    CLSID: Incomplete
    coclass_sources: Incomplete
    coclass_interfaces: Incomplete

class AcPePropertyEditorLType(CoClassBaseClass):
    CLSID: Incomplete
    coclass_sources: Incomplete
    coclass_interfaces: Incomplete

class AcPePropertyEditorLWeight(CoClassBaseClass):
    CLSID: Incomplete
    coclass_sources: Incomplete
    coclass_interfaces: Incomplete

class AcPePropertyEditorLayer(CoClassBaseClass):
    CLSID: Incomplete
    coclass_sources: Incomplete
    coclass_interfaces: Incomplete

class AcPePropertyEditorTextStyle(CoClassBaseClass):
    CLSID: Incomplete
    coclass_sources: Incomplete
    coclass_interfaces: Incomplete

class AcadApplication(CoClassBaseClass):
    CLSID: Incomplete
    coclass_sources: Incomplete
    default_source: Incomplete
    coclass_interfaces: Incomplete
    default_interface = IAcadApplication

class AcadDocument(CoClassBaseClass):
    CLSID: Incomplete
    coclass_sources: Incomplete
    default_source: Incomplete
    coclass_interfaces: Incomplete
    default_interface = IAcadDocument

class AcadDocuments(CoClassBaseClass):
    CLSID: Incomplete
    coclass_sources: Incomplete
    coclass_interfaces: Incomplete
    default_interface = IAcadDocuments

class AcadLayerStateManager(CoClassBaseClass):
    CLSID: Incomplete
    coclass_sources: Incomplete
    coclass_interfaces: Incomplete
    default_interface = IAcadLayerStateManager

class AcadMenuBar(CoClassBaseClass):
    CLSID: Incomplete
    coclass_sources: Incomplete
    coclass_interfaces: Incomplete
    default_interface = IAcadMenuBar

class AcadMenuGroup(CoClassBaseClass):
    CLSID: Incomplete
    coclass_sources: Incomplete
    coclass_interfaces: Incomplete
    default_interface = IAcadMenuGroup

class AcadMenuGroups(CoClassBaseClass):
    CLSID: Incomplete
    coclass_sources: Incomplete
    coclass_interfaces: Incomplete
    default_interface = IAcadMenuGroups

class AcadPlot(CoClassBaseClass):
    CLSID: Incomplete
    coclass_sources: Incomplete
    coclass_interfaces: Incomplete
    default_interface = IAcadPlot

class AcadPopupMenu(CoClassBaseClass):
    CLSID: Incomplete
    coclass_sources: Incomplete
    coclass_interfaces: Incomplete
    default_interface = IAcadPopupMenu

class AcadPopupMenuItem(CoClassBaseClass):
    CLSID: Incomplete
    coclass_sources: Incomplete
    coclass_interfaces: Incomplete
    default_interface = IAcadPopupMenuItem

class AcadPopupMenus(CoClassBaseClass):
    CLSID: Incomplete
    coclass_sources: Incomplete
    coclass_interfaces: Incomplete
    default_interface = IAcadPopupMenus

class AcadPreferences(CoClassBaseClass):
    CLSID: Incomplete
    coclass_sources: Incomplete
    coclass_interfaces: Incomplete
    default_interface = IAcadPreferences

class AcadPreferencesDisplay(CoClassBaseClass):
    CLSID: Incomplete
    coclass_sources: Incomplete
    coclass_interfaces: Incomplete
    default_interface = IAcadPreferencesDisplay

class AcadPreferencesDrafting(CoClassBaseClass):
    CLSID: Incomplete
    coclass_sources: Incomplete
    coclass_interfaces: Incomplete
    default_interface = IAcadPreferencesDrafting

class AcadPreferencesFiles(CoClassBaseClass):
    CLSID: Incomplete
    coclass_sources: Incomplete
    coclass_interfaces: Incomplete
    default_interface = IAcadPreferencesFiles

class AcadPreferencesOpenSave(CoClassBaseClass):
    CLSID: Incomplete
    coclass_sources: Incomplete
    coclass_interfaces: Incomplete
    default_interface = IAcadPreferencesOpenSave

class AcadPreferencesOutput(CoClassBaseClass):
    CLSID: Incomplete
    coclass_sources: Incomplete
    coclass_interfaces: Incomplete
    default_interface = IAcadPreferencesOutput

class AcadPreferencesPdfOutput(CoClassBaseClass):
    CLSID: Incomplete
    coclass_sources: Incomplete
    coclass_interfaces: Incomplete
    default_interface = IAcadPreferencesPdfOutput

class AcadPreferencesProfiles(CoClassBaseClass):
    CLSID: Incomplete
    coclass_sources: Incomplete
    coclass_interfaces: Incomplete
    default_interface = IAcadPreferencesProfiles

class AcadPreferencesSelection(CoClassBaseClass):
    CLSID: Incomplete
    coclass_sources: Incomplete
    coclass_interfaces: Incomplete
    default_interface = IAcadPreferencesSelection

class AcadPreferencesSystem(CoClassBaseClass):
    CLSID: Incomplete
    coclass_sources: Incomplete
    coclass_interfaces: Incomplete
    default_interface = IAcadPreferencesSystem

class AcadPreferencesUser(CoClassBaseClass):
    CLSID: Incomplete
    coclass_sources: Incomplete
    coclass_interfaces: Incomplete
    default_interface = IAcadPreferencesUser

class AcadSecurityParams(CoClassBaseClass):
    CLSID: Incomplete
    coclass_sources: Incomplete
    coclass_interfaces: Incomplete
    default_interface = IAcadSecurityParams

class AcadSelectionSet(CoClassBaseClass):
    CLSID: Incomplete
    coclass_sources: Incomplete
    coclass_interfaces: Incomplete
    default_interface = IAcadSelectionSet

class AcadSelectionSets(CoClassBaseClass):
    CLSID: Incomplete
    coclass_sources: Incomplete
    coclass_interfaces: Incomplete
    default_interface = IAcadSelectionSets

class AcadState(CoClassBaseClass):
    CLSID: Incomplete
    coclass_sources: Incomplete
    coclass_interfaces: Incomplete
    default_interface = IAcadState

class AcadToolbar(CoClassBaseClass):
    CLSID: Incomplete
    coclass_sources: Incomplete
    coclass_interfaces: Incomplete
    default_interface = IAcadToolbar

class AcadToolbarItem(CoClassBaseClass):
    CLSID: Incomplete
    coclass_sources: Incomplete
    coclass_interfaces: Incomplete
    default_interface = IAcadToolbarItem

class AcadToolbars(CoClassBaseClass):
    CLSID: Incomplete
    coclass_sources: Incomplete
    coclass_interfaces: Incomplete
    default_interface = IAcadToolbars

class AcadUtility(CoClassBaseClass):
    CLSID: Incomplete
    coclass_sources: Incomplete
    coclass_interfaces: Incomplete
    default_interface = IAcadUtility

class OdaBagFiler(CoClassBaseClass):
    CLSID: Incomplete
    coclass_sources: Incomplete
    coclass_interfaces: Incomplete
    default_interface = IOdaBagFiler

class OdaBmpOut(CoClassBaseClass):
    CLSID: Incomplete
    coclass_sources: Incomplete
    coclass_interfaces: Incomplete
    default_interface = IOdaBmpOut

class OdaDwf3dExport(CoClassBaseClass):
    CLSID: Incomplete
    coclass_sources: Incomplete
    coclass_interfaces: Incomplete
    default_interface = IOdaDwf3dExport

class OdaDwfImporter(CoClassBaseClass):
    CLSID: Incomplete
    coclass_sources: Incomplete
    coclass_interfaces: Incomplete
    default_interface = IOdaDwfImporter

class OdaDwfTemplate(CoClassBaseClass):
    CLSID: Incomplete
    coclass_sources: Incomplete
    coclass_interfaces: Incomplete
    default_interface = IOdaDwfTemplate

class OdaHostApp(CoClassBaseClass):
    CLSID: Incomplete
    coclass_sources: Incomplete
    default_source: Incomplete
    coclass_interfaces: Incomplete
    default_interface = IOdaHostApp2

class OdaSvgExporter(CoClassBaseClass):
    CLSID: Incomplete
    coclass_sources: Incomplete
    coclass_interfaces: Incomplete
    default_interface = IOdaSvgExporter

class TransmittalFile(CoClassBaseClass):
    CLSID: Incomplete
    coclass_sources: Incomplete
    coclass_interfaces: Incomplete
    default_interface = ITransmittalFile

class TransmittalFilesGraph(CoClassBaseClass):
    CLSID: Incomplete
    coclass_sources: Incomplete
    coclass_interfaces: Incomplete
    default_interface = ITransmittalFilesGraph

class TransmittalInfo(CoClassBaseClass):
    CLSID: Incomplete
    coclass_sources: Incomplete
    coclass_interfaces: Incomplete
    default_interface = ITransmittalInfo

class TransmittalOperation(CoClassBaseClass):
    CLSID: Incomplete
    coclass_sources: Incomplete
    coclass_interfaces: Incomplete
    default_interface = ITransmittalOperation

IAcadApplication_vtables_dispatch_: int
IAcadApplication_vtables_: Incomplete
IAcadDocument_vtables_dispatch_: int
IAcadDocument_vtables_: Incomplete
IAcadDocuments_vtables_dispatch_: int
IAcadDocuments_vtables_: Incomplete
IAcadLayerStateManager_vtables_dispatch_: int
IAcadLayerStateManager_vtables_: Incomplete
IAcadMenuBar_vtables_dispatch_: int
IAcadMenuBar_vtables_: Incomplete
IAcadMenuGroup_vtables_dispatch_: int
IAcadMenuGroup_vtables_: Incomplete
IAcadMenuGroups_vtables_dispatch_: int
IAcadMenuGroups_vtables_: Incomplete
IAcadPlot_vtables_dispatch_: int
IAcadPlot_vtables_: Incomplete
IAcadPopupMenu_vtables_dispatch_: int
IAcadPopupMenu_vtables_: Incomplete
IAcadPopupMenuItem_vtables_dispatch_: int
IAcadPopupMenuItem_vtables_: Incomplete
IAcadPopupMenus_vtables_dispatch_: int
IAcadPopupMenus_vtables_: Incomplete
IAcadPreferences_vtables_dispatch_: int
IAcadPreferences_vtables_: Incomplete
IAcadPreferencesDisplay_vtables_dispatch_: int
IAcadPreferencesDisplay_vtables_: Incomplete
IAcadPreferencesDrafting_vtables_dispatch_: int
IAcadPreferencesDrafting_vtables_: Incomplete
IAcadPreferencesFiles_vtables_dispatch_: int
IAcadPreferencesFiles_vtables_: Incomplete
IAcadPreferencesOpenSave_vtables_dispatch_: int
IAcadPreferencesOpenSave_vtables_: Incomplete
IAcadPreferencesOutput_vtables_dispatch_: int
IAcadPreferencesOutput_vtables_: Incomplete
IAcadPreferencesPdfOutput_vtables_dispatch_: int
IAcadPreferencesPdfOutput_vtables_: Incomplete
IAcadPreferencesProfiles_vtables_dispatch_: int
IAcadPreferencesProfiles_vtables_: Incomplete
IAcadPreferencesSelection_vtables_dispatch_: int
IAcadPreferencesSelection_vtables_: Incomplete
IAcadPreferencesSystem_vtables_dispatch_: int
IAcadPreferencesSystem_vtables_: Incomplete
IAcadPreferencesUser_vtables_dispatch_: int
IAcadPreferencesUser_vtables_: Incomplete
IAcadSecurityParams_vtables_dispatch_: int
IAcadSecurityParams_vtables_: Incomplete
IAcadSelectionSet_vtables_dispatch_: int
IAcadSelectionSet_vtables_: Incomplete
IAcadSelectionSets_vtables_dispatch_: int
IAcadSelectionSets_vtables_: Incomplete
IAcadState_vtables_dispatch_: int
IAcadState_vtables_: Incomplete
IAcadToolbar_vtables_dispatch_: int
IAcadToolbar_vtables_: Incomplete
IAcadToolbarItem_vtables_dispatch_: int
IAcadToolbarItem_vtables_: Incomplete
IAcadToolbars_vtables_dispatch_: int
IAcadToolbars_vtables_: Incomplete
IAcadUtility_vtables_dispatch_: int
IAcadUtility_vtables_: Incomplete
IOdaAuditInfo_vtables_dispatch_: int
IOdaAuditInfo_vtables_: Incomplete
IOdaBagFiler_vtables_dispatch_: int
IOdaBagFiler_vtables_: Incomplete
IOdaBmpOut_vtables_dispatch_: int
IOdaBmpOut_vtables_: Incomplete
IOdaConsole_vtables_dispatch_: int
IOdaConsole_vtables_: Incomplete
IOdaDwf3dExport_vtables_dispatch_: int
IOdaDwf3dExport_vtables_: Incomplete
IOdaDwfImporter_vtables_dispatch_: int
IOdaDwfImporter_vtables_: Incomplete
IOdaDwfImporter2_vtables_dispatch_: int
IOdaDwfImporter2_vtables_: Incomplete
IOdaDwfPageData_vtables_dispatch_: int
IOdaDwfPageData_vtables_: Incomplete
IOdaDwfTemplate_vtables_dispatch_: int
IOdaDwfTemplate_vtables_: Incomplete
IOdaHostApp_vtables_dispatch_: int
IOdaHostApp_vtables_: Incomplete
IOdaHostApp2_vtables_dispatch_: int
IOdaHostApp2_vtables_: Incomplete
IOdaSvgExporter_vtables_dispatch_: int
IOdaSvgExporter_vtables_: Incomplete
ITransmittalFile_vtables_dispatch_: int
ITransmittalFile_vtables_: Incomplete
ITransmittalFilesGraph_vtables_dispatch_: int
ITransmittalFilesGraph_vtables_: Incomplete
ITransmittalInfo_vtables_dispatch_: int
ITransmittalInfo_vtables_: Incomplete
ITransmittalOperation_vtables_dispatch_: int
ITransmittalOperation_vtables_: Incomplete
RecordMap: Incomplete
CLSIDToClassMap: Incomplete
CLSIDToPackageMap: Incomplete
VTablesToPackageMap: Incomplete
VTablesToClassMap: Incomplete
NamesToIIDMap: Incomplete
