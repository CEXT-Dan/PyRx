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
kEmpty: PropertyFlags  # 0
kHardPointer: ObjectReferenceFlags  # 2
kIsChild: PropertyFlags  # 8
kLockedAccessDenied: LockStatus  # 16
kLockedLocal: LockStatus  # 1
kLockedNotConnected: LockStatus  # 8
kLockedReadOnly: LockStatus  # 4
kLockedRemote: LockStatus  # 2
kSheetProp: PropertyFlags  # 2
kSheetSetProp: PropertyFlags  # 1
kSoftPointer: ObjectReferenceFlags  # 1
kSubSetProp: PropertyFlags  # 4
kUnLocked: LockStatus  # 0
class CalloutBlocks(PySm.Component):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    def add(self, val: PySm.DbBlockRecordReference, /) -> None:
        pass
    @staticmethod
    def cast(otherObject: PySm.Persist, /) -> CalloutBlocks:
        pass
    @staticmethod
    def className() -> str:
        pass
    def getDbBlockRecordReferences(self, /) -> list[PySm.DbBlockRecordReference]:
        pass
    def remove(self, val: PySm.DbBlockRecordReference, /) -> None:
        pass
class Component(PySm.Persist):
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PySm.Persist, /) -> Component:
        pass
    @staticmethod
    def className() -> str:
        pass
    def getCustomPropertyBag(self, /) -> CustomPropertyBag:
        pass
    def getDesc(self, /) -> str:
        pass
    def getName(self, /) -> str:
        pass
    def setDesc(self, desc: str, /) -> None:
        pass
    def setName(self, name: str, /) -> None:
        pass
class CustomPropertyBag(PySm.Persist):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PySm.Persist, /) -> CustomPropertyBag:
        pass
    @staticmethod
    def className() -> str:
        pass
    def getProperties(self, /) -> list[tuple[str,PySm.CustomPropertyValue]]:
        pass
    def getProperty(self, prop: str, /) -> CustomPropertyValue:
        pass
    def getPropertyValues(self, /) -> list[tuple[str,PyDb.AcValue]]:
        pass
    def hasProperty(self, prop: str, /) -> bool:
        pass
    def setProperty(self, prop: str, val: PySm.CustomPropertyValue, /) -> None:
        pass
class CustomPropertyValue(PySm.Persist):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PySm.Persist, /) -> CustomPropertyValue:
        pass
    @staticmethod
    def className() -> str:
        pass
    def getFlags(self, /) -> PropertyFlags:
        pass
    def getValue(self, /) -> PyDb.AcValue:
        pass
    def setFlags(self, flags: PySm.PropertyFlags, /) -> None:
        pass
    def setValue(self, val: PyDb.AcValue|str|int|float, /) -> None:
        pass
class DbBlockRecordReference(PySm.NamedDbObjectReference):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PySm.Persist, /) -> DbBlockRecordReference:
        pass
    @staticmethod
    def className() -> str:
        pass
class DbDatabase:
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
    def getAcDbDatabase(self, /) -> PyDb.Database:
        pass
class DbLayoutReference(PySm.NamedDbObjectReference):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PySm.Persist, /) -> DbLayoutReference:
        pass
    @staticmethod
    def className() -> str:
        pass
class DbObjectReference(PySm.FileReference):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PySm.Persist, /) -> DbObjectReference:
        pass
    @staticmethod
    def className() -> str:
        pass
    def getAcDbHandle(self, /) -> PyDb.Handle:
        pass
    def getAcSmAcDbDatabase(self, /) -> DbDatabase:
        pass
    def resolveAcDbObject(self, db: PyDb.Database, /) -> PyDb.Handle:
        pass
    def setAcDbHandle(self, handle: PyDb.Handle, /) -> None:
        pass
    def setAcDbObject(self, obj: PyDb.Object, /) -> None:
        pass
class DbViewReference(PySm.NamedDbObjectReference):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PySm.Persist, /) -> DbViewReference:
        pass
    @staticmethod
    def className() -> str:
        pass
class FileReference(PySm.Persist):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PySm.Persist, /) -> FileReference:
        pass
    @staticmethod
    def className() -> str:
        pass
    def getFileName(self, /) -> str:
        pass
    def setFileName(self, fname: str, /) -> None:
        pass
class LockStatus(_BoostPythonEnum):
    kUnLocked: ClassVar[Self]  # 0
    kLockedLocal: ClassVar[Self]  # 1
    kLockedRemote: ClassVar[Self]  # 2
    kLockedReadOnly: ClassVar[Self]  # 4
    kLockedNotConnected: ClassVar[Self]  # 8
    kLockedAccessDenied: ClassVar[Self]  # 16
class NamedDbObjectReference(PySm.DbObjectReference):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PySm.Persist, /) -> NamedDbObjectReference:
        pass
    @staticmethod
    def className() -> str:
        pass
    def getName(self, /) -> str:
        pass
    def getOwnerAcDbHandle(self, /) -> PyDb.Handle:
        pass
    def setName(self, val: str, /) -> None:
        pass
    def setOwnerAcDbHandle(self, val: PyDb.Handle, /) -> None:
        pass
class ObjectReference(PySm.Persist):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PySm.Persist, /) -> ObjectReference:
        pass
    @staticmethod
    def className() -> str:
        pass
    def getReferenceFlags(self, /) -> ObjectReferenceFlags:
        pass
    def getReferencedObject(self, /) -> Persist:
        pass
    def setReferenceFlags(self, val: PySm.ObjectReferenceFlags, /) -> None:
        pass
    def setReferencedObject(self, val: PySm.Persist, /) -> None:
        pass
class ObjectReferenceFlags(_BoostPythonEnum):
    kSoftPointer: ClassVar[Self]  # 1
    kHardPointer: ClassVar[Self]  # 2
class Persist:
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PySm.Persist, /) -> Persist:
        pass
    @staticmethod
    def className() -> str:
        pass
    def clear(self, /) -> None:
        pass
    def getDatabase(self, /) -> SmDatabase:
        pass
    def getIsDirty(self, /) -> bool:
        pass
    def getObjectId(self, /) -> object:
        pass
    def getOwner(self, /) -> Persist:
        pass
    def getTypeName(self, /) -> str:
        pass
    def initNew(self, owner: PySm.Persist, /) -> None:
        pass
    def isNull(self, /) -> bool:
        pass
    def setOwner(self, owner: PySm.Persist, /) -> None:
        pass
class PersistProxy(PySm.Persist):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PySm.Persist, /) -> PersistProxy:
        pass
    @staticmethod
    def className() -> str:
        pass
class ProjectPointLocation(PySm.Persist):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PySm.Persist, /) -> ProjectPointLocation:
        pass
    @staticmethod
    def className() -> str:
        pass
    def getFolder(self, /) -> str:
        pass
    def getPassword(self, /) -> str:
        pass
    def getResourceType(self, /) -> int:
        pass
    def getURL(self, /) -> str:
        pass
    def getUsername(self, /) -> str:
        pass
    def setFolder(self, val: str, /) -> None:
        pass
    def setPassword(self, val: str, /) -> None:
        pass
    def setResourceType(self, val: int, /) -> None:
        pass
    def setUsername(self, val: str, /) -> None:
        pass
class ProjectPointLocations(PySm.Component):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    def addNewLocation(self, name: str, url: str, folder: str, username: str, password: str, /) -> ProjectPointLocation:
        pass
    @staticmethod
    def cast(otherObject: PySm.Persist, /) -> ProjectPointLocations:
        pass
    @staticmethod
    def className() -> str:
        pass
    def getLocation(self, locationName: str, /) -> ProjectPointLocation:
        pass
    def removeLocation(self, val: PySm.ProjectPointLocation, /) -> None:
        pass
class PropertyFlags(_BoostPythonEnum):
    kEmpty: ClassVar[Self]  # 0
    kSheetSetProp: ClassVar[Self]  # 1
    kSheetProp: ClassVar[Self]  # 2
    kSubSetProp: ClassVar[Self]  # 4
    kIsChild: ClassVar[Self]  # 8
class PublishOptions(PySm.Persist):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PySm.Persist, /) -> PublishOptions:
        pass
    @staticmethod
    def className() -> str:
        pass
    def getDefaultFilename(self, /) -> str:
        pass
    def getDefaultOutputdir(self, /) -> FileReference:
        pass
    def getDwfType(self, /) -> bool:
        pass
    def getEplotFormat(self, /) -> int:
        pass
    def getIncludeSheetData(self, /) -> bool:
        pass
    def getIncludeSheetSetData(self, /) -> bool:
        pass
    def getLayerInfo(self, /) -> bool:
        pass
    def getLinesMerge(self, /) -> bool:
        pass
    def getPromptForName(self, /) -> bool:
        pass
    def getPromptForPassword(self, /) -> bool:
        pass
    def getUnrecognizedData(self, /) -> CustomPropertyBag:
        pass
    def getUnrecognizedSections(self, /) -> CustomPropertyBag:
        pass
    def getUsePassword(self, /) -> bool:
        pass
    def setDefaultFilename(self, val: str, /) -> None:
        pass
    def setDefaultOutputdir(self, val: PySm.FileReference, /) -> None:
        pass
    def setDwfType(self, val: bool, /) -> None:
        pass
    def setEplotFormat(self, val: int, /) -> None:
        pass
    def setIncludeSheetData(self, val: bool, /) -> None:
        pass
    def setIncludeSheetSetData(self, val: bool, /) -> None:
        pass
    def setLayerInfo(self, val: bool, /) -> None:
        pass
    def setLinesMerge(self, val: bool, /) -> None:
        pass
    def setPromptForName(self, val: bool, /) -> None:
        pass
    def setPromptForPassword(self, val: bool, /) -> None:
        pass
    def setUnrecognizedData(self, val: PySm.CustomPropertyBag, /) -> None:
        pass
    def setUnrecognizedSections(self, val: PySm.CustomPropertyBag, /) -> None:
        pass
    def setUsePassword(self, val: bool, /) -> None:
        pass
class Resources(PySm.Component):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    def add(self, val: PySm.FileReference, /) -> None:
        pass
    @staticmethod
    def cast(otherObject: PySm.Persist, /) -> Resources:
        pass
    @staticmethod
    def className() -> str:
        pass
    def getFileReferences(self, /) -> list[PySm.FileReference]:
        pass
    def remove(self, val: PySm.FileReference, /) -> None:
        pass
class Sheet(PySm.Component):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PySm.Persist, /) -> Sheet:
        pass
    @staticmethod
    def className() -> str:
        pass
    def getCategory(self, /) -> str:
        pass
    def getDoNotPlot(self, /) -> bool:
        pass
    def getIssuePurpose(self, /) -> str:
        pass
    def getLayout(self, /) -> DbLayoutReference:
        pass
    def getNumber(self, /) -> str:
        pass
    def getRevisionDate(self, /) -> str:
        pass
    def getRevisionNumber(self, /) -> str:
        pass
    def getSheetViews(self, /) -> SheetViews:
        pass
    def getTitle(self, /) -> str:
        pass
    def setCategory(self, cat: str, /) -> None:
        pass
    def setDoNotPlot(self, flag: bool, /) -> None:
        pass
    def setIssuePurpose(self, why: str, /) -> None:
        pass
    def setLayout(self, layout: PySm.DbLayoutReference, /) -> None:
        pass
    def setNumber(self, number: str, /) -> None:
        pass
    def setRevisionDate(self, date: str, /) -> None:
        pass
    def setRevisionNumber(self, number: str, /) -> None:
        pass
    def setTitle(self, title: str, /) -> None:
        pass
class SheetSelSet(PySm.Component):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    def add(self, val: PySm.Component, /) -> None:
        pass
    @staticmethod
    def cast(otherObject: PySm.Persist, /) -> SheetSelSet:
        pass
    @staticmethod
    def className() -> str:
        pass
    def getComponents(self, /) -> list[PySm.Component]:
        pass
    def remove(self, /) -> None:
        pass
class SheetSelSets(PySm.Component):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    def add(self, name: str, desc: str, /) -> SheetSelSet:
        pass
    @staticmethod
    def cast(otherObject: PySm.Persist, /) -> SheetSelSets:
        pass
    @staticmethod
    def className() -> str:
        pass
    def getSheetSelSets(self, /) -> list[PySm.SheetSelSet]:
        pass
    def remove(self, val: PySm.SheetSelSet, /) -> None:
        pass
class SheetSet(PySm.Subset):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PySm.Persist, /) -> SheetSet:
        pass
    @staticmethod
    def className() -> str:
        pass
    def getAltPageSetups(self, /) -> FileReference:
        pass
    def getCalloutBlocks(self, /) -> CalloutBlocks:
        pass
    def getDefAltPageSetup(self, /) -> NamedDbObjectReference:
        pass
    def getDefLabelBlk(self, /) -> DbBlockRecordReference:
        pass
    def getPromptForDwgName(self, /) -> bool:
        pass
    def getPublishOptions(self, /) -> PublishOptions:
        pass
    def getResources(self, /) -> Resources:
        pass
    def getSheetSelSets(self, /) -> SheetSelSets:
        pass
    def getViewCategories(self, /) -> ViewCategories:
        pass
    def setAltPageSetups(self, val: PySm.FileReference, /) -> None:
        pass
    def setDefAltPageSetup(self, val: PySm.NamedDbObjectReference, /) -> None:
        pass
    def setDefLabelBlk(self, val: PySm.DbBlockRecordReference, /) -> None:
        pass
    def setPromptForDwgName(self, val: bool, /) -> None:
        pass
    def sync(self, db: PyDb.Database, /) -> None:
        pass
    def updateSheetCustomProps(self, /) -> None:
        pass
class SheetSetMgr:
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def className() -> str:
        pass
    def close(self, smDb: PySm.Database, /) -> None:
        pass
    def closeAll() -> None:
        pass
    @overload
    def createDatabase(self, filename: str, /) -> SmDatabase: ...
    @overload
    def createDatabase(self, filename: str, template: str, bAlwaysCreate: bool, /) -> SmDatabase: ...
    def createDatabase(self, *args) -> SmDatabase:
        pass
    def findOpenDatabase(self, filename: str, /) -> SmDatabase:
        pass
    def getDatabases(self, /) -> list[PySm.SmDatabase]:
        pass
    def getParentSheetSet(self, dwg: str, layout: str, /) -> tuple[PySm.SmDatabase,PySm.SheetSet]:
        pass
    def getSheetFromLayout(self, layout: PyDb.Object, /) -> tuple[PySm.SmDatabase,PySm.Sheet]:
        pass
    def openDatabase(self, filename: str, /) -> SmDatabase:
        pass
    @staticmethod
    def runTest() -> bool:
        pass
class SheetView(PySm.Component):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PySm.Persist, /) -> SheetView:
        pass
    @staticmethod
    def className() -> str:
        pass
    def getCategory(self, /) -> ViewCategory:
        pass
    def getNamedView(self, /) -> DbViewReference:
        pass
    def getNumber(self, /) -> str:
        pass
    def getTitle(self, /) -> str:
        pass
    def setCategory(self, val: PySm.ViewCategory, /) -> None:
        pass
    def setNamedView(self, val: PySm.AcDbViewReference, /) -> None:
        pass
    def setNumber(self, val: str, /) -> None:
        pass
    def setTitle(self, val: str, /) -> None:
        pass
class SheetViews(PySm.Component):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PySm.Persist, /) -> SheetViews:
        pass
    @staticmethod
    def className() -> str:
        pass
    def getSheetViews(self, /) -> list[PySm.SheetView]:
        pass
    def sync(self, val: PySm.AcDbLayoutReference, db: PyDb.Database, /) -> None:
        pass
class SmDatabase(PySm.Component):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PySm.Persist, /) -> SmDatabase:
        pass
    @staticmethod
    def className() -> str:
        pass
    def getFileName(self, /) -> str:
        pass
    def getLockOwnerInfo(self, /) -> tuple[str,str]:
        pass
    def getLockStatus(self, /) -> LockStatus:
        pass
    def getPersistObjects(self, /) -> list[PySm.Persist]:
        pass
    def getSheetSet(self, /) -> SheetSet:
        pass
    def getTemplateDstFileName(self, /) -> str:
        pass
    def loadFromFile(self, filename: str, /) -> None:
        pass
    def lockDb(self, /) -> None:
        pass
    def setFileName(self, filename: str, /) -> None:
        pass
    def unlockDb(self, commit: bool, /) -> None:
        pass
class Subset(PySm.Component):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    def addNewSheet(self, name: str, desc: str, /) -> Sheet:
        pass
    @staticmethod
    def cast(otherObject: PySm.Persist, /) -> Subset:
        pass
    @staticmethod
    def className() -> str:
        pass
    def createSubset(self, name: str, desc: str, /) -> Subset:
        pass
    def getDefDwtLayout(self, /) -> DbLayoutReference:
        pass
    def getNewSheetLocation(self, /) -> FileReference:
        pass
    def getOverrideSheetPublish(self, /) -> bool:
        pass
    def getPromptForDwt(self, /) -> bool:
        pass
    def getSheets(self, /) -> list[PySm.Sheet]:
        pass
    def importSheet(self, val: PySm.DbLayoutReference, /) -> Sheet:
        pass
    def insertComponent(self, newSheet: PySm.Component, beforeSheet: PySm.Component, /) -> None:
        pass
    def insertComponentAfter(self, newSheet: PySm.Component, afterSheet: PySm.Component, /) -> None:
        pass
    def insertComponentFirst(self, newSheet: PySm.Component, /) -> None:
        pass
    def removeSheet(self, val: PySm.Sheet, /) -> None:
        pass
    def removeSubset(self, val: PySm.Subset, /) -> None:
        pass
    def setDefDwtLayout(self, val: PySm.DbLayoutReference, /) -> None:
        pass
    def setNewSheetLocation(self, val: PySm.FileReference, /) -> None:
        pass
    def setOverrideSheetPublish(self, val: bool, /) -> None:
        pass
    def setPromptForDwt(self, val: bool, /) -> None:
        pass
    def updateInMemoryDwgHints(self, /) -> None:
        pass
class ViewCategories(PySm.Component):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PySm.Persist, /) -> ViewCategories:
        pass
    @staticmethod
    def className() -> str:
        pass
    def createViewCategory(self, name: str, desc: str, id: str, /) -> ViewCategory:
        pass
    def getDefaultViewCategory(self, /) -> ViewCategory:
        pass
    def getViewCategories(self, /) -> list[PySm.ViewCategory]:
        pass
    def removeViewCategory(self, val: PySm.ViewCategory, /) -> None:
        pass
class ViewCategory(PySm.Component):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PySm.Persist, /) -> ViewCategory:
        pass
    @staticmethod
    def className() -> str:
        pass
    def getCalloutBlocks(self, /) -> CalloutBlocks:
        pass
    def getSheetViews(self, /) -> list[PySm.SheetView]:
        pass
