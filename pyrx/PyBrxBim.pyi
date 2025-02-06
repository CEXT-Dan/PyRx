from __future__ import annotations
from typing import overload, Any, ClassVar, Self, TypeVar
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
from pyrx import Cv as PyBrxCv
from pyrx import Bim as PyBrxBim
from pyrx import Brx as PyBrx
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
eAssociatedLibraryNotAccessible: ResultStatus  # 7
eBimAnnotation: BimElementType  # 51
eBimBeam: BimElementType  # 7
eBimBuilding: BimObjectType  # 3
eBimBuildingType: BimElementType  # 54
eBimColumn: BimElementType  # 5
eBimComposition: BimObjectType  # 4
eBimCovering: BimElementType  # 9
eBimCurtainWall: BimElementType  # 10
eBimDetail: BimElementType  # 58
eBimDiscreteAccessory: BimElementType  # 43
eBimDistributionChamberElement: BimElementType  # 30
eBimDistributionControlElement: BimElementType  # 27
eBimDistributionFlowElement: BimElementType  # 29
eBimDistributionPort: BimElementType  # 28
eBimDoor: BimElementType  # 4
eBimEnergyConversionDevice: BimElementType  # 31
eBimFastener: BimElementType  # 44
eBimFlowConnectionPoint: BimElementType  # 49
eBimFlowController: BimElementType  # 33
eBimFlowFitting: BimElementType  # 32
eBimFlowMovingDevice: BimElementType  # 34
eBimFlowSegment: BimElementType  # 35
eBimFlowStorageDevice: BimElementType  # 36
eBimFlowTerminal: BimElementType  # 11
eBimFlowTreatmentDevice: BimElementType  # 37
eBimFooting: BimElementType  # 22
eBimFurnishingElement: BimElementType  # 12
eBimGenericBuildingElt: BimElementType  # 0
eBimGrid: BimElementType  # 48
eBimGridAxis: BimElementType  # 47
eBimMaterial: BimObjectType  # 7
eBimMechanicalFastener: BimElementType  # 45
eBimMember: BimElementType  # 13
eBimNotAvailable: ResultStatus  # 33
eBimNotImplementedYet: ResultStatus  # 32
eBimOpening: BimElementType  # 50
eBimPile: BimElementType  # 14
eBimPlate: BimElementType  # 42
eBimPly: BimObjectType  # 6
eBimProduct: BimElementType  # 57
eBimRailing: BimElementType  # 15
eBimRamp: BimElementType  # 16
eBimRampFlight: BimElementType  # 17
eBimReinforcingBar: BimElementType  # 38
eBimReinforcingMesh: BimElementType  # 39
eBimRoof: BimElementType  # 18
eBimRoom: BimElementType  # 8
eBimRoomObject: BimObjectType  # 5
eBimSchedule: BimElementType  # 46
eBimSection: BimElementType  # 1
eBimSite: BimElementType  # 19
eBimSlab: BimElementType  # 6
eBimSpaceType: BimElementType  # 53
eBimSpatialElementType: BimElementType  # 52
eBimSpatialLocation: BimObjectType  # 1
eBimStair: BimElementType  # 20
eBimStairFlight: BimElementType  # 21
eBimStory: BimObjectType  # 2
eBimStoryType: BimElementType  # 55
eBimTendon: BimElementType  # 40
eBimTendonAnchor: BimElementType  # 41
eBimUnknownObject: BimObjectType  # 0
eBimViewportType: BimElementType  # 56
eBimWall: BimElementType  # 2
eBimWindow: BimElementType  # 3
eBimXReference: BimElementType  # 26
eBinary: IfcValueType  # 7
eBool: IfcValueType  # 0
eDbNotAccessible: ResultStatus  # 2
eDbNotOpenForWrite: ResultStatus  # 4
eDbObjectNotSupported: ResultStatus  # 3
eEmpty: IfcValueType  # 12
eEntity: IfcValueType  # 5
eEnum: IfcValueType  # 9
eFootprint: BimSpaceRepresentation  # 1
eGuid: IfcValueType  # 8
eHatchCustom: BimHatchType  # 2
eHatchNone: BimHatchType  # -1
eHatchPredefined: BimHatchType  # 1
eHatchUserDefined: BimHatchType  # 0
eIFC2X3: IfcSchemaId  # 0
eIFC4: IfcSchemaId  # 1
eIFC4X1: IfcSchemaId  # 2
eIfcGlobalOrigin: IfcImportModelOrigin  # 0
eIfcProjectLocation: IfcImportModelOrigin  # 2
eIfcSchemaLast: IfcSchemaId  # 2
eIfcSiteLocation: IfcImportModelOrigin  # 1
eInstantSave: BimPolicyOptions  # 1
eInt: IfcValueType  # 1
eInternalError: IfcResult  # 4
eInvalidArgument: ResultStatus  # 44
eInvalidIndex: ResultStatus  # 36
eInvalidInput: ResultStatus  # 37
eInvalidMaterial: ResultStatus  # 10
eInvalidMaterialComposition: ResultStatus  # 11
eInvalidName: ResultStatus  # 16
eInvalidSpatialLocation: ResultStatus  # 9
eInvalidValue: ResultStatus  # 18
eInvalidXmlFormat: ResultStatus  # 15
eLogical: IfcValueType  # 6
eModelSpaceNotAccessible: ResultStatus  # 5
eNameSpaceAlreadyExists: ResultStatus  # 39
eNoAttributeSet: ResultStatus  # 45
eNoBuildingElement: BimElementType  # 59
eNoData: ResultStatus  # 28
eNoDbResidentObject: ResultStatus  # 1
eNoNameSpace: ResultStatus  # 38
eNoProfileAssigned: ResultStatus  # 27
eNoProperty: ResultStatus  # 42
eNoPropertySet: ResultStatus  # 40
eNotApplicableForTheseParameters: ResultStatus  # 8
eNotAssignedToLibrary: ResultStatus  # 19
eNotImplemented: ResultStatus  # 43
eNotInitialized: IfcResult  # 1
eNotLinearBuildingElement: ResultStatus  # 17
eNothing: BimPolicyOptions  # 0
eNullDatabase: ResultStatus  # 22
eNullDocument: ResultStatus  # 23
eNullObject: ResultStatus  # 20
eNullObjectId: ResultStatus  # 21
eNullString: ResultStatus  # 24
eObjectAlreadyExists: ResultStatus  # 12
eObjectCouldNotBeDeleted: ResultStatus  # 13
eObjectNotExisting: ResultStatus  # 25
eObjectNotSupported: ResultStatus  # 26
eOk: IfcResult  # 0
eProjectDbNotAccessible: ResultStatus  # 6
ePropertySetAlreadyExists: ResultStatus  # 41
eReal: IfcValueType  # 3
eSelect: IfcValueType  # 10
eSolid: BimSpaceRepresentation  # 0
eString: IfcValueType  # 4
eUInt: IfcValueType  # 2
eUnassignedEntity: ResultStatus  # 31
eUnknownData: ResultStatus  # 29
eUnknownError: ResultStatus  # 35
eVector: IfcValueType  # 11
eWrongDataType: ResultStatus  # 30
eWrongName: IfcResult  # 2
eWrongType: IfcResult  # 3
eXmlFileCouldNotBeParsed: ResultStatus  # 14
kBricsys: BimCategory  # 1
kClassfication: BimCategory  # 6
kIFC2x3: BimCategory  # 2
kIFC4: BimCategory  # 7
kIFCCustom: BimCategory  # 3
kIFCQuantity: BimCategory  # 8
kQuantity: BimCategory  # 5
kStandard: BimCategory  # 0
kUser: BimCategory  # 4
class BimAssets:
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
class BimBuilding(PyBrxBim.BimSpatialLocation):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def allObjectBuildings(db: PyDb.Database, /) -> list:
        pass
    def allObjectStories(self, /) -> list:
        pass
    @staticmethod
    def allObjectStoriesFromDb(db: PyDb.Database, /) -> list:
        pass
    @staticmethod
    def allStringBuildings(db: PyDb.Database, /) -> list:
        pass
    def allStringStories(self, /) -> list:
        pass
    @staticmethod
    def allStringStoriesFromDb(db: PyDb.Database, /) -> list:
        pass
    def assignToEntity(self, id: PyDb.ObjectId, /) -> None:
        pass
    @staticmethod
    def assignedBuilding(building: PyBrxBim.BimBuilding,id: PyDb.ObjectId, /) -> None:
        pass
    def assignedObjects(self, db: PyDb.Database, /) -> list:
        pass
    @staticmethod
    def cast(otherObject: PyBrxBim.BimObject, /) -> BimBuilding:
        pass
    @staticmethod
    def className() -> str:
        pass
    def createBuilding(self, name: str, db: PyDb.Database, /) -> None:
        pass
    @staticmethod
    def createNewBuilding(db: PyDb.Database,name: str, /) -> BimBuilding:
        pass
    def createStory(self, name: str, /) -> None:
        pass
    @staticmethod
    def deleteBuildingFromDb(db: PyDb.Database,name: str, /) -> None:
        pass
    def deleteStoryObject(self, story: PyBrxBim.BimStory, /) -> None:
        pass
    def deleteStoryString(self, story: str, /) -> None:
        pass
    def description(self, /) -> str:
        pass
    @staticmethod
    def getBuilding(db: PyDb.Database,name: str, /) -> BimBuilding:
        pass
    def getStory(self, story: str, /) -> BimStory:
        pass
    def isNull(self, /) -> bool:
        pass
    def longName(self, /) -> str:
        pass
    def name(self, /) -> str:
        pass
    def setDescription(self, desc: str, /) -> None:
        pass
    def setLongName(self, name: str, /) -> None:
        pass
    def setName(self, name: str, /) -> None:
        pass
    def setNull(self, /) -> None:
        pass
    def typeDesc(self, /) -> BimObjectType:
        pass
    def typeName(self, /) -> str:
        pass
class BimCategory(_BoostPythonEnum):
    kStandard: ClassVar[Self]  # 0
    kBricsys: ClassVar[Self]  # 1
    kIFC2x3: ClassVar[Self]  # 2
    kIFCCustom: ClassVar[Self]  # 3
    kUser: ClassVar[Self]  # 4
    kQuantity: ClassVar[Self]  # 5
    kClassfication: ClassVar[Self]  # 6
    kIFC4: ClassVar[Self]  # 7
    kIFCQuantity: ClassVar[Self]  # 8
class BimClassification:
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def className() -> str:
        pass
    @overload
    @staticmethod
    def classifyAs(id: PyDb.ObjectId, objectType: PyBrxBim.BimElementType, /) -> None: ...
    @overload
    @staticmethod
    def classifyAs(database: PyDb.database, objectType: PyBrxBim.BimElementType, /) -> None: ...
    @overload
    @staticmethod
    def classifyAs(id: PyDb.ObjectId, typeName: str, /) -> None: ...
    @overload
    @staticmethod
    def classifyAs(id: PyDb.ObjectId, typeName: str, localName: bool, /) -> None: ...
    @staticmethod
    def classifyAs(*args) -> None:
        pass
    @overload
    @staticmethod
    def deleteProperty(id: PyDb.ObjectId, propertyName: str, /) -> bool: ...
    @overload
    @staticmethod
    def deleteProperty(id: PyDb.ObjectId, propertyName: str, category : PyBrxBim.EBimCategory, /) -> bool: ...
    @overload
    @staticmethod
    def deleteProperty(id: PyDb.ObjectId, propertyName: str, category: str, /) -> bool: ...
    @staticmethod
    def deleteProperty(*args) -> bool:
        pass
    @staticmethod
    def getAllClassified(db: PyDb.Database, /) -> list:
        pass
    @staticmethod
    def getAllClassifiedAs(name: str,db: PyDb.Database, /) -> list:
        pass
    @staticmethod
    def getAllClassifiedAsName(name: str,db: PyDb.Database,local: bool = False, /) -> list:
        pass
    @staticmethod
    def getAllUnclassified(db: PyDb.Database, /) -> list:
        pass
    @staticmethod
    def getAllUsedClassificationNames(db: PyDb.Database,local: bool = False, /) -> list:
        pass
    @staticmethod
    def getAllUsedClassifications(db: PyDb.Database, /) -> list:
        pass
    @staticmethod
    def getBimTypeNames(local: bool = False, /) -> list:
        pass
    @staticmethod
    def getClassification():
        pass
    def getClassificationName(id: PyDb.ObjectId,localName : bool = False, /) -> str:
        pass
    @staticmethod
    def getDescription(id: PyDb.ObjectId, /) -> str:
        pass
    @staticmethod
    def getGUID(id: PyDb.ObjectId, /) -> str:
        pass
    @staticmethod
    def getName(id: PyDb.ObjectId, /) -> str:
        pass
    @overload
    @staticmethod
    def getProperty(id: PyDb.ObjectId, propertyName: str, /) -> PyDb.AcValue: ...
    @overload
    @staticmethod
    def getProperty(id: PyDb.ObjectId, propertyName: str, category : PyBrxBim.EBimCategory, /) -> PyDb.AcValue: ...
    @overload
    @staticmethod
    def getProperty(id: PyDb.ObjectId, propertyName: str, category: str, /) -> PyDb.AcValue: ...
    @staticmethod
    def getProperty(*args) -> PyDb.AcValue:
        pass
    @staticmethod
    def getPropertyDict(id: PyDb.ObjectId, /) -> dict:
        pass
    @staticmethod
    def getPropertyNames(id: PyDb.ObjectId, /) -> list:
        pass
    @overload
    @staticmethod
    def hasProperty(id: PyDb.ObjectId, propertyName: str, /) -> bool: ...
    @overload
    @staticmethod
    def hasProperty(id: PyDb.ObjectId, propertyName: str, category : PyBrxBim.EBimCategory, /) -> bool: ...
    @overload
    @staticmethod
    def hasProperty(id: PyDb.ObjectId, propertyName: str, category: str, /) -> bool: ...
    @staticmethod
    def hasProperty(*args) -> bool:
        pass
    @staticmethod
    def isClassified(val: PyDb.Database, /) -> bool:
        pass
    @overload
    @staticmethod
    def isClassifiedAs(id: PyDb.ObjectId, objectType: PyBrxBim.BimElementType, /) -> bool: ...
    @overload
    @staticmethod
    def isClassifiedAs(database: PyDb.database, objectType: PyBrxBim.BimElementType, /) -> bool: ...
    @overload
    @staticmethod
    def isClassifiedAs(id: PyDb.ObjectId, typeName: str, /) -> bool: ...
    @overload
    @staticmethod
    def isClassifiedAs(id: PyDb.ObjectId, typeName: str, localName: bool, /) -> bool: ...
    @staticmethod
    def isClassifiedAs(*args) -> bool:
        pass
    @staticmethod
    def isClassifiedAsAnyBuildingElement(id: PyDb.ObjectId, /) -> bool:
        pass
    @staticmethod
    def isUnclassified(id: PyDb.ObjectId, /) -> bool:
        pass
    @staticmethod
    def setDescription(id: PyDb.ObjectId,description: str, /) -> None:
        pass
    @staticmethod
    def setName(id: PyDb.ObjectId,description: str, /) -> None:
        pass
    @overload
    @staticmethod
    def setProperty(id: PyDb.ObjectId, propertyName: str, val: PyDb.AcValue, /) -> None: ...
    @overload
    @staticmethod
    def setProperty(id: PyDb.ObjectId, propertyName: str, val: PyDb.AcValue,category : PyBrxBim.EBimCategory, /) -> None: ...
    @overload
    @staticmethod
    def setProperty(id: PyDb.ObjectId, propertyName: str, val: PyDb.AcValue, category: str, /) -> None: ...
    @staticmethod
    def setProperty(*args) -> None:
        pass
    @staticmethod
    def unClassify(val: PyDb.ObjectId|PyDb.Database, /) -> None:
        pass
class BimComposition(PyBrxBim.BimObject):
    @overload
    def __init__(self, /) -> None: ...
    @overload
    def __init__(self, name: str, /) -> None: ...
    def __init__(self, *args) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyBrxBim.BimObject, /) -> BimComposition:
        pass
    @staticmethod
    def className() -> str:
        pass
class BimElementType(_BoostPythonEnum):
    eBimGenericBuildingElt: ClassVar[Self]  # 0
    eBimSection: ClassVar[Self]  # 1
    eBimWall: ClassVar[Self]  # 2
    eBimWindow: ClassVar[Self]  # 3
    eBimDoor: ClassVar[Self]  # 4
    eBimColumn: ClassVar[Self]  # 5
    eBimSlab: ClassVar[Self]  # 6
    eBimBeam: ClassVar[Self]  # 7
    eBimRoom: ClassVar[Self]  # 8
    eBimCovering: ClassVar[Self]  # 9
    eBimCurtainWall: ClassVar[Self]  # 10
    eBimFlowTerminal: ClassVar[Self]  # 11
    eBimFurnishingElement: ClassVar[Self]  # 12
    eBimMember: ClassVar[Self]  # 13
    eBimPile: ClassVar[Self]  # 14
    eBimRailing: ClassVar[Self]  # 15
    eBimRamp: ClassVar[Self]  # 16
    eBimRampFlight: ClassVar[Self]  # 17
    eBimRoof: ClassVar[Self]  # 18
    eBimSite: ClassVar[Self]  # 19
    eBimStair: ClassVar[Self]  # 20
    eBimStairFlight: ClassVar[Self]  # 21
    eBimFooting: ClassVar[Self]  # 22
    eBimXReference: ClassVar[Self]  # 26
    eBimDistributionControlElement: ClassVar[Self]  # 27
    eBimDistributionPort: ClassVar[Self]  # 28
    eBimDistributionFlowElement: ClassVar[Self]  # 29
    eBimDistributionChamberElement: ClassVar[Self]  # 30
    eBimEnergyConversionDevice: ClassVar[Self]  # 31
    eBimFlowFitting: ClassVar[Self]  # 32
    eBimFlowController: ClassVar[Self]  # 33
    eBimFlowMovingDevice: ClassVar[Self]  # 34
    eBimFlowSegment: ClassVar[Self]  # 35
    eBimFlowStorageDevice: ClassVar[Self]  # 36
    eBimFlowTreatmentDevice: ClassVar[Self]  # 37
    eBimReinforcingBar: ClassVar[Self]  # 38
    eBimReinforcingMesh: ClassVar[Self]  # 39
    eBimTendon: ClassVar[Self]  # 40
    eBimTendonAnchor: ClassVar[Self]  # 41
    eBimPlate: ClassVar[Self]  # 42
    eBimDiscreteAccessory: ClassVar[Self]  # 43
    eBimFastener: ClassVar[Self]  # 44
    eBimMechanicalFastener: ClassVar[Self]  # 45
    eBimSchedule: ClassVar[Self]  # 46
    eBimGridAxis: ClassVar[Self]  # 47
    eBimGrid: ClassVar[Self]  # 48
    eBimFlowConnectionPoint: ClassVar[Self]  # 49
    eBimOpening: ClassVar[Self]  # 50
    eBimAnnotation: ClassVar[Self]  # 51
    eBimSpatialElementType: ClassVar[Self]  # 52
    eBimSpaceType: ClassVar[Self]  # 53
    eBimBuildingType: ClassVar[Self]  # 54
    eBimStoryType: ClassVar[Self]  # 55
    eBimViewportType: ClassVar[Self]  # 56
    eBimProduct: ClassVar[Self]  # 57
    eBimDetail: ClassVar[Self]  # 58
    eNoBuildingElement: ClassVar[Self]  # 59
class BimHatchPattern:
    @overload
    def __init__(self, /) -> None: ...
    @overload
    def __init__(self, scaleOrSpacing: float,angle: float=0.0,cross: bool=False, /) -> None: ...
    @overload
    def __init__(self, hType: PyBrxBim.BimHatchType, name:str, scaleOrSpacing: float= 1.0, angle: float=0.0, /) -> None: ...
    def __init__(self, *args) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def className() -> str:
        pass
class BimHatchType(_BoostPythonEnum):
    eHatchNone: ClassVar[Self]  # -1
    eHatchUserDefined: ClassVar[Self]  # 0
    eHatchPredefined: ClassVar[Self]  # 1
    eHatchCustom: ClassVar[Self]  # 2
class BimInformationalAssets:
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
class BimLinearGeometry:
    @overload
    def __init__(self, /) -> None: ...
    @overload
    def __init__(self, id: PyDb.ObjectId, /) -> None: ...
    def __init__(self, *args) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def className() -> str:
        pass
class BimMaterial(PyBrxBim.BimObject):
    @overload
    def __init__(self, /) -> None: ...
    @overload
    def __init__(self, name: str, /) -> None: ...
    def __init__(self, *args) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyBrxBim.BimObject, /) -> BimMaterial:
        pass
    @staticmethod
    def className() -> str:
        pass
class BimNameSpaces:
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def className() -> str:
        pass
    @overload
    @staticmethod
    def createNameSpace(szName: str, /) -> None: ...
    @overload
    @staticmethod
    def createNameSpace(szName: str, szLabel: str, visible: bool, db: PyDb.Database, /) -> None: ...
    @staticmethod
    def createNameSpace(*args) -> None:
        pass
    @staticmethod
    def deleteNameSpace(szNameOrLabel: str,db: PyDb.Database=None, /) -> None:
        pass
    @staticmethod
    def getIsNameSpaceVisible(szNameOrLabel: str,db: PyDb.Database=None, /) -> bool:
        pass
    @staticmethod
    def getNameSpaceLabel(szName: str,db: PyDb.Database=None, /) -> str:
        pass
    @staticmethod
    def hasNameSpace(szNameOrLabel: str,db: PyDb.Database=None, /) -> bool:
        pass
    @staticmethod
    def listNameSpaces(db: PyDb.Database=None, /) -> dict:
        pass
    @staticmethod
    def setIsNameSpaceVisible(visible: bool,szNameOrLabel: str,db: PyDb.Database=None, /) -> None:
        pass
    @staticmethod
    def setNameSpaceLabel(szName: str,szLable: str,db: PyDb.Database=None, /) -> None:
        pass
class BimObject:
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyBrxBim.BimObject, /) -> BimObject:
        pass
    @staticmethod
    def className() -> str:
        pass
    def description(self, /) -> str:
        pass
    def isNull(self, /) -> bool:
        pass
    def name(self, /) -> str:
        pass
    def setDescription(self, val: str, /) -> None:
        pass
    def setName(self, val: str, /) -> None:
        pass
    def setNull(self, /) -> None:
        pass
    def typeDesc(self, /) -> BimObjectType:
        pass
    def typeName(self, /) -> str:
        pass
class BimObjectType(_BoostPythonEnum):
    eBimUnknownObject: ClassVar[Self]  # 0
    eBimSpatialLocation: ClassVar[Self]  # 1
    eBimStory: ClassVar[Self]  # 2
    eBimBuilding: ClassVar[Self]  # 3
    eBimComposition: ClassVar[Self]  # 4
    eBimRoomObject: ClassVar[Self]  # 5
    eBimPly: ClassVar[Self]  # 6
    eBimMaterial: ClassVar[Self]  # 7
class BimPly(PyBrxBim.BimObject):
    @overload
    def __init__(self, /) -> None: ...
    @overload
    def __init__(self, material: PyBrxBim.BimMaterial, function: PyBrxBim.MaterialFunction=PyBrxBim.MaterialFunction.eNone, thickness:float=1.0, /) -> None: ...
    def __init__(self, *args) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def cast(otherObject: PyBrxBim.BimObject, /) -> BimPly:
        pass
    @staticmethod
    def className() -> str:
        pass
class BimPolicies:
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
    def getPolicy(option: PyBrxBim.BimPolicyOptions, /) -> bool:
        pass
    @staticmethod
    def setPolicy(option: PyBrxBim.BimPolicyOptions,enable: bool, /) -> None:
        pass
class BimPolicyOptions(_BoostPythonEnum):
    eNothing: ClassVar[Self]  # 0
    eInstantSave: ClassVar[Self]  # 1
class BimProfile:
    @overload
    def __init__(self, /) -> None: ...
    @overload
    def __init__(self, id: PyDb.ObjectId, /) -> None: ...
    def __init__(self, *args) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def className() -> str:
        pass
class BimRoom(PyBrxBim.BimObject):
    @overload
    def __init__(self, /) -> None: ...
    @overload
    def __init__(self, id: PyDb.ObjectId, /) -> None: ...
    def __init__(self, *args) -> None:
        pass
    def __reduce__(self, /):
        pass
    def assignToBuilding(self, val: PyBrxBim.BimBuilding, /) -> None:
        pass
    @staticmethod
    def assignToBuildingS(id: PyDb.ObjectId,val: PyBrxBim.BimBuilding, /) -> None:
        pass
    def assignToStory(self, val: PyBrxBim.BimStory, /) -> None:
        pass
    @staticmethod
    def assignToStoryS(id: PyDb.ObjectId,val: PyBrxBim.BimStory, /) -> None:
        pass
    @staticmethod
    def buildAssociativeRoomS(insidePoint: PyGe.Point3d,basePlane: PyGe.Plane, /) -> PyDb.ObjectId:
        pass
    @staticmethod
    def buildNonAssociativeRoomS(id: PyDb.ObjectId, /) -> PyDb.ObjectId:
        pass
    @staticmethod
    def cast(otherObject: PyBrxBim.BimObject, /) -> BimRoom:
        pass
    @staticmethod
    def className() -> str:
        pass
    def createAssociativeRoom(self, insidePoint: PyGe.Point3d, basePlane: PyGe.Plane, /) -> PyDb.ObjectId:
        pass
    def createNonAssociativeRoom(self, id: PyDb.ObjectId, /) -> PyDb.ObjectId:
        pass
    def description(self, /) -> str:
        pass
    @staticmethod
    def descriptionS(id: PyDb.ObjectId, /) -> str:
        pass
    @overload
    @staticmethod
    def getAllRoomsS() -> list: ...
    @overload
    @staticmethod
    def getAllRoomsS(id: PyDb.Database, /) -> list: ...
    @overload
    @staticmethod
    def getAllRoomsS(val: PyBrxBim.BimStory- val: PyBrxBim.BimStory, id: PyDb.Database, /) -> list: ...
    @overload
    @staticmethod
    def getAllRoomsS(val: PyBrxBim.BimBuilding- val: PyBrxBim.BimBuilding, id: PyDb.Database, /) -> list: ...
    @staticmethod
    def getAllRoomsS(*args) -> list:
        pass
    def getAssignedBuilding(self, /) -> BimBuilding:
        pass
    @staticmethod
    def getAssignedBuildingS(id: PyDb.ObjectId, /) -> BimBuilding:
        pass
    def getAssignedLocation(self, /) -> BimSpatialLocation:
        pass
    @staticmethod
    def getAssignedLocationS(id: PyDb.ObjectId, /) -> BimSpatialLocation:
        pass
    def getAssignedStory(self, /) -> BimStory:
        pass
    @staticmethod
    def getAssignedStoryS(id: PyDb.ObjectId, /) -> BimStory:
        pass
    def getBoundingElements(self, /) -> list:
        pass
    @staticmethod
    def getBoundingElementsS(id: PyDb.ObjectId, /) -> list:
        pass
    def getId(self, /) -> PyDb.ObjectId:
        pass
    def getOpenings(self, /) -> list:
        pass
    @staticmethod
    def getOpeningsS(id: PyDb.ObjectId, /) -> list:
        pass
    def getRoomDepartment(self, /) -> str:
        pass
    @staticmethod
    def getRoomDepartmentS(id: PyDb.ObjectId, /) -> str:
        pass
    def getRoomEntity(self, /) -> PyDb.ObjectId:
        pass
    @staticmethod
    def getRoomEntityS(val: PyBrxBim.BimRoom, /) -> PyDb.ObjectId:
        pass
    def getRoomRepresentation(self, /) -> str:
        pass
    @staticmethod
    def getRoomRepresentationS(id: PyDb.ObjectId, /) -> str:
        pass
    def isAssociativeRoom(self, /) -> bool:
        pass
    @staticmethod
    def isAssociativeRoomS(id: PyDb.ObjectId, /) -> bool:
        pass
    def isNull(self, /) -> bool:
        pass
    def isRoomValid(self, /) -> bool:
        pass
    @staticmethod
    def isRoomValidS(id: PyDb.ObjectId, /) -> bool:
        pass
    def name(self, /) -> str:
        pass
    def roomArea(self, /) -> float:
        pass
    @staticmethod
    def roomAreaS(id: PyDb.ObjectId, /) -> float:
        pass
    def roomIdent(self, /) -> str:
        pass
    @staticmethod
    def roomIdentS(id: PyDb.ObjectId, /) -> str:
        pass
    def roomName(self, /) -> str:
        pass
    @staticmethod
    def roomNameS(id: PyDb.ObjectId, /) -> str:
        pass
    def roomNumber(self, /) -> str:
        pass
    @staticmethod
    def roomNumberS(id: PyDb.ObjectId, /) -> str:
        pass
    def setDescription(self, val: str, /) -> None:
        pass
    @staticmethod
    def setDescriptionS(id: PyDb.ObjectId,val: str, /) -> None:
        pass
    def setId(self, id: PyDb.ObjectId, /) -> None:
        pass
    def setName(self, val: str, /) -> None:
        pass
    def setNull(self, /) -> None:
        pass
    def setRoomDepartment(self, val: str, /) -> None:
        pass
    @staticmethod
    def setRoomDepartmentS(id: PyDb.ObjectId,val: str, /) -> None:
        pass
    def setRoomName(self, val: str, /) -> None:
        pass
    @staticmethod
    def setRoomNameS(id: PyDb.ObjectId,val: str, /) -> None:
        pass
    def setRoomNumber(self, val: str, /) -> None:
        pass
    @staticmethod
    def setRoomNumberS(id: PyDb.ObjectId,val: str, /) -> None:
        pass
    def setRoomRepresentation(self, val: str, /) -> None:
        pass
    @staticmethod
    def setRoomRepresentationS(id: PyDb.ObjectId,val: str, /) -> None:
        pass
    def typeDesc(self, /) -> BimObjectType:
        pass
    def typeName(self, /) -> str:
        pass
    def unassignLocation(self, /) -> None:
        pass
    @staticmethod
    def unassignLocationS(id: PyDb.ObjectId, /) -> None:
        pass
    def updateAssociativeRoom(self, /) -> None:
        pass
    @staticmethod
    def updateAssociativeRoomS(id: PyDb.ObjectId, /) -> None:
        pass
class BimSpace:
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def assignToBuilding(id: PyDb.ObjectId,building: PyBrxBim.BimBuilding, /) -> None:
        pass
    @staticmethod
    def assignToStory(id: PyDb.ObjectId,building: PyBrxBim.BimStory, /) -> None:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def createSpace(pt: PyGe.Point3d, /) -> PyDb.ObjectId:
        pass
    @overload
    @staticmethod
    def getAllSpaces() -> list: ...
    @overload
    @staticmethod
    def getAllSpaces(id: PyDb.Database, /) -> list: ...
    @overload
    @staticmethod
    def getAllSpaces(val: PyBrxBim.BimStory- val: PyBrxBim.BimStory, id: PyDb.Database, /) -> list: ...
    @overload
    @staticmethod
    def getAllSpaces(val: PyBrxBim.BimBuilding- val: PyBrxBim.BimBuilding, id: PyDb.Database, /) -> list: ...
    @staticmethod
    def getAllSpaces(*args) -> list:
        pass
    @staticmethod
    def getAssignedEntities(val: str|PyDb.ObjectId,db: PyDb.Database=None, /) -> list:
        pass
    @staticmethod
    def getAssignedSpace(id: PyDb.ObjectId, /) -> tuple:
        pass
    @staticmethod
    def getBoundingElements(id: PyDb.ObjectId, /) -> list:
        pass
    @staticmethod
    def getSpaceArea(id: PyDb.ObjectId, /) -> float:
        pass
    @staticmethod
    def getSpaceEntity(spaceName: str,db: PyDb.Database = None, /) -> PyDb.ObjectId:
        pass
    @staticmethod
    def getSpaceName(id: PyDb.ObjectId, /) -> str:
        pass
    @staticmethod
    def getSpaceNumber(id: PyDb.ObjectId, /) -> str:
        pass
    @staticmethod
    def getSpaceRepresentation(id: PyDb.ObjectId, /) -> BimSpaceRepresentation:
        pass
    @staticmethod
    def isSpaceUpdated(id: PyDb.ObjectId, /) -> bool:
        pass
    @staticmethod
    def isSpaceValid(id: PyDb.ObjectId, /) -> bool:
        pass
    @staticmethod
    def setAssignedSpace(id: PyDb.ObjectId,val: str|PyDb.ObjectId, /) -> None:
        pass
    @staticmethod
    def setSpaceName(id: PyDb.ObjectId,val: str, /) -> None:
        pass
    @staticmethod
    def setSpaceNumber(id: PyDb.ObjectId,val: str, /) -> None:
        pass
    @staticmethod
    def setSpaceRepresentation(id: PyDb.ObjectId,val: PyBrxBim.BimSpaceRepresentation, /) -> None:
        pass
    @staticmethod
    def updateSpace(id: PyDb.ObjectId, /) -> None:
        pass
class BimSpaceRepresentation(_BoostPythonEnum):
    eSolid: ClassVar[Self]  # 0
    eFootprint: ClassVar[Self]  # 1
class BimSpatialLocation(PyBrxBim.BimObject):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    def assignToEntity(self, id: PyDb.ObjectId, /) -> None:
        pass
    def assignedObjects(self, id: PyDb.ObjectId, /) -> list:
        pass
    @staticmethod
    def assignedSpatialLocation(id: PyDb.ObjectId, /) -> BimSpatialLocation:
        pass
    @staticmethod
    def cast(otherObject: PyBrxBim.BimObject, /) -> BimSpatialLocation:
        pass
    @staticmethod
    def className() -> str:
        pass
    def description(self, /) -> str:
        pass
    def hasBuilding(self, /) -> bool:
        pass
    def hasStory(self, /) -> bool:
        pass
    def isBuilding(self, /) -> bool:
        pass
    def isNull(self, /) -> bool:
        pass
    def isStory(self, /) -> bool:
        pass
    def longName(self, /) -> str:
        pass
    def name(self, /) -> str:
        pass
    @staticmethod
    def removeSpatialLocationFrom(id: PyDb.ObjectId, /) -> None:
        pass
    def setDescription(self, desc: str, /) -> None:
        pass
    def setLongName(self, /) -> None:
        pass
    def setName(self, name: str, /) -> None:
        pass
    def setNull(self, /) -> None:
        pass
    def typeDesc(self, /) -> BimObjectType:
        pass
    def typeName(self, /) -> str:
        pass
class BimStory(PyBrxBim.BimSpatialLocation):
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def allStories(db: PyDb.Database, /) -> list:
        pass
    @staticmethod
    def allStoryNames(db: PyDb.Database, /) -> list:
        pass
    def assignToEntity(self, id: PyDb.ObjectId, /) -> None:
        pass
    def assignedObjects(self, db: PyDb.Database, /) -> list:
        pass
    @staticmethod
    def assignedStory(id: PyDb.ObjectId, /) -> BimStory:
        pass
    @staticmethod
    def cast(otherObject: PyBrxBim.BimObject, /) -> BimStory:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def createNewStory(db: PyDb.Database,buildingName: str,storyName: str, /) -> BimStory:
        pass
    def createStory(self, szName: str, building: PyBrxBim.BimBuilding, /) -> None:
        pass
    def deleteStory(self, /) -> None:
        pass
    @staticmethod
    def deleteStoryFromDatabase(db: PyDb.Database,buildingName: str,storyName: str, /) -> None:
        pass
    def description(self, /) -> str:
        pass
    def elevation(self, /) -> float:
        pass
    def getBuilding(self, /) -> BimBuilding:
        pass
    @staticmethod
    def getStory(db: PyDb.Database, buildingName: str, storyName: str, /) -> BimStory:
        pass
    def isNull(self, /) -> bool:
        pass
    def longName(self, /) -> str:
        pass
    def name(self, /) -> str:
        pass
    def setDescription(self, desc: str, /) -> None:
        pass
    def setElevation(self, val: float, /) -> None:
        pass
    def setLongName(self, name: str, /) -> None:
        pass
    def setName(self, name: str, /) -> None:
        pass
    def setNull(self, /) -> None:
        pass
class BrxBimAttributeSet:
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def className() -> str:
        pass
class BrxBimDialogs:
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def className() -> str:
        pass
class Core:
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    @staticmethod
    def createAnchoredBlockReference(blockRefId: PyDb.ObjectId,faceSubentPath: PyDb.FullSubentPath,pt: PyGe.Point3d,keepOrientation: bool, /) -> PyDb.ObjectId:
        pass
    @staticmethod
    def findMatchingBlockDefinition(entitySet: list[PyDb.ObjectId], /) -> tuple:
        pass
    @staticmethod
    def findSimilar3dSolids(entitySet: list[PyDb.ObjectId], /) -> tuple:
        pass
    @staticmethod
    def findSimilarGeometry(matchSet: list[PyDb.ObjectId],searchSet: list[PyDb.ObjectId], /) -> tuple:
        pass
    @staticmethod
    def getAnchorFace(id: PyDb.ObjectId, /) -> PyDb.FullSubentPath:
        pass
    @staticmethod
    def getAnchoredBlockReferences(db: PyDb.Database, /) -> list:
        pass
    @staticmethod
    def isAnchoredBlockRef(id: PyDb.ObjectId, /) -> bool:
        pass
    @staticmethod
    def isSimilarGeometry(firstSet: list[PyDb.ObjectId],secondSet: list[PyDb.ObjectId], /) -> tuple:
        pass
    @staticmethod
    def matchEntitiesToBlockDefinitions(entitySet: list[PyDb.ObjectId], /) -> tuple:
        pass
    @staticmethod
    def queryValidAnchorPt(pt: PyGe.Point3d,db: PyDb.Database, /) -> PyDb.FullSubentPath:
        pass
    @staticmethod
    def replaceGeometryByBlocks(similarGroups: tuple, /) -> tuple:
        pass
    @staticmethod
    def unAnchorBlockReference(id: PyDb.ObjectId, /) -> None:
        pass
class IfcBinary:
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def className() -> str:
        pass
    def clear(self, /) -> None:
        pass
    def getBit(self, val: int, /) -> bool:
        pass
    def getEncodedString(self, /) -> str:
        pass
    def isEmpty(self, /) -> bool:
        pass
    def numBits(self, /) -> int:
        pass
    def reset(self, val: str, /) -> None:
        pass
    def resize(self, val: int, /) -> None:
        pass
class IfcEntity:
    def IfcId(self, /) -> int:
        pass
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def create() -> IfcEntity:
        pass
    def getAttribute(self, val: str, /) -> IfcVariant:
        pass
    def getInverseRefs(self, /) -> list:
        pass
    def isA(self, /) -> IfcEntityDesc:
        pass
    def isKindOf(self, val: PyBrxBim.IfcEntityDesc, /) -> bool:
        pass
    def isNull(self, /) -> bool:
        pass
    def setAttribute(self, val: str, attribValue: PyBrxBim.IfcVariant, /) -> None:
        pass
class IfcEntityDesc:
    @staticmethod
    def Ifc2DCompositeCurve() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcActionRequest() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcActor() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcActorRole() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcActuator() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcActuatorType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcAddress() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcAdvancedBrep() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcAdvancedBrepWithVoids() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcAdvancedFace() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcAirTerminal() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcAirTerminalBox() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcAirTerminalBoxType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcAirTerminalType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcAirToAirHeatRecovery() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcAirToAirHeatRecoveryType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcAlarm() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcAlarmType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcAlignment() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcAlignment2DHorizontal() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcAlignment2DHorizontalSegment() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcAlignment2DSegment() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcAlignment2DVerSegCircularArc() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcAlignment2DVerSegLine() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcAlignment2DVerSegParabolicArc() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcAlignment2DVertical() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcAlignment2DVerticalSegment() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcAlignmentCurve() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcAngularDimension() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcAnnotation() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcAnnotationCurveOccurrence() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcAnnotationFillArea() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcAnnotationFillAreaOccurrence() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcAnnotationOccurrence() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcAnnotationSurface() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcAnnotationSurfaceOccurrence() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcAnnotationSymbolOccurrence() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcAnnotationTextOccurrence() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcApplication() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcAppliedValue() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcAppliedValueRelationship() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcApproval() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcApprovalActorRelationship() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcApprovalPropertyRelationship() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcApprovalRelationship() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcArbitraryClosedProfileDef() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcArbitraryOpenProfileDef() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcArbitraryProfileDefWithVoids() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcAsset() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcAsymmetricIShapeProfileDef() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcAudioVisualAppliance() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcAudioVisualApplianceType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcAxis1Placement() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcAxis2Placement2D() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcAxis2Placement3D() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcBSplineCurve() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcBSplineCurveWithKnots() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcBSplineSurface() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcBSplineSurfaceWithKnots() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcBeam() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcBeamStandardCase() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcBeamType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcBezierCurve() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcBlobTexture() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcBlock() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcBoiler() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcBoilerType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcBooleanClippingResult() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcBooleanResult() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcBoundaryCondition() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcBoundaryCurve() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcBoundaryEdgeCondition() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcBoundaryFaceCondition() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcBoundaryNodeCondition() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcBoundaryNodeConditionWarping() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcBoundedCurve() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcBoundedSurface() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcBoundingBox() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcBoxedHalfSpace() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcBuilding() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcBuildingElement() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcBuildingElementComponent() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcBuildingElementPart() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcBuildingElementPartType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcBuildingElementProxy() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcBuildingElementProxyType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcBuildingElementType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcBuildingStorey() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcBuildingSystem() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcBurner() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcBurnerType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcCShapeProfileDef() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcCableCarrierFitting() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcCableCarrierFittingType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcCableCarrierSegment() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcCableCarrierSegmentType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcCableFitting() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcCableFittingType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcCableSegment() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcCableSegmentType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcCalendarDate() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcCartesianPoint() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcCartesianPointList() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcCartesianPointList2D() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcCartesianPointList3D() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcCartesianTransformationOperator() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcCartesianTransformationOperator2D() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcCartesianTransformationOperator2DnonUniform() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcCartesianTransformationOperator3D() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcCartesianTransformationOperator3DnonUniform() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcCenterLineProfileDef() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcChamferEdgeFeature() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcChiller() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcChillerType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcChimney() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcChimneyType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcCircle() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcCircleHollowProfileDef() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcCircleProfileDef() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcCircularArcSegment2D() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcCivilElement() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcCivilElementType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcClassification() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcClassificationItem() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcClassificationItemRelationship() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcClassificationNotation() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcClassificationNotationFacet() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcClassificationReference() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcClosedShell() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcCoil() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcCoilType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcColourRgb() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcColourRgbList() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcColourSpecification() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcColumn() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcColumnStandardCase() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcColumnType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcCommunicationsAppliance() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcCommunicationsApplianceType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcComplexProperty() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcComplexPropertyTemplate() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcCompositeCurve() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcCompositeCurveOnSurface() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcCompositeCurveSegment() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcCompositeProfileDef() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcCompressor() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcCompressorType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcCondenser() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcCondenserType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcCondition() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcConditionCriterion() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcConic() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcConnectedFaceSet() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcConnectionCurveGeometry() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcConnectionGeometry() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcConnectionPointEccentricity() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcConnectionPointGeometry() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcConnectionPortGeometry() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcConnectionSurfaceGeometry() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcConnectionVolumeGeometry() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcConstraint() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcConstraintAggregationRelationship() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcConstraintClassificationRelationship() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcConstraintRelationship() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcConstructionEquipmentResource() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcConstructionEquipmentResourceType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcConstructionMaterialResource() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcConstructionMaterialResourceType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcConstructionProductResource() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcConstructionProductResourceType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcConstructionResource() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcConstructionResourceType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcContext() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcContextDependentUnit() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcControl() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcController() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcControllerType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcConversionBasedUnit() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcConversionBasedUnitWithOffset() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcCooledBeam() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcCooledBeamType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcCoolingTower() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcCoolingTowerType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcCoordinateOperation() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcCoordinateReferenceSystem() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcCoordinatedUniversalTimeOffset() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcCostItem() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcCostSchedule() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcCostValue() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcCovering() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcCoveringType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcCraneRailAShapeProfileDef() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcCraneRailFShapeProfileDef() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcCrewResource() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcCrewResourceType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcCsgPrimitive3D() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcCsgSolid() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcCurrencyRelationship() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcCurtainWall() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcCurtainWallType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcCurve() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcCurveBoundedPlane() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcCurveBoundedSurface() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcCurveSegment2D() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcCurveStyle() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcCurveStyleFont() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcCurveStyleFontAndScaling() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcCurveStyleFontPattern() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcCylindricalSurface() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcDamper() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcDamperType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcDateAndTime() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcDefinedSymbol() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcDerivedProfileDef() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcDerivedUnit() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcDerivedUnitElement() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcDiameterDimension() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcDimensionCalloutRelationship() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcDimensionCurve() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcDimensionCurveDirectedCallout() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcDimensionCurveTerminator() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcDimensionPair() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcDimensionalExponents() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcDirection() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcDiscreteAccessory() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcDiscreteAccessoryType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcDistanceExpression() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcDistributionChamberElement() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcDistributionChamberElementType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcDistributionCircuit() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcDistributionControlElement() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcDistributionControlElementType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcDistributionElement() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcDistributionElementType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcDistributionFlowElement() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcDistributionFlowElementType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcDistributionPort() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcDistributionSystem() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcDocumentElectronicFormat() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcDocumentInformation() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcDocumentInformationRelationship() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcDocumentReference() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcDoor() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcDoorLiningProperties() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcDoorPanelProperties() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcDoorStandardCase() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcDoorStyle() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcDoorType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcDraughtingCallout() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcDraughtingCalloutRelationship() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcDraughtingPreDefinedColour() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcDraughtingPreDefinedCurveFont() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcDraughtingPreDefinedTextFont() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcDuctFitting() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcDuctFittingType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcDuctSegment() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcDuctSegmentType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcDuctSilencer() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcDuctSilencerType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcEdge() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcEdgeCurve() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcEdgeFeature() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcEdgeLoop() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcElectricAppliance() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcElectricApplianceType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcElectricDistributionBoard() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcElectricDistributionBoardType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcElectricDistributionPoint() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcElectricFlowStorageDevice() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcElectricFlowStorageDeviceType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcElectricGenerator() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcElectricGeneratorType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcElectricHeaterType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcElectricMotor() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcElectricMotorType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcElectricTimeControl() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcElectricTimeControlType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcElectricalBaseProperties() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcElectricalCircuit() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcElectricalElement() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcElement() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcElementAssembly() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcElementAssemblyType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcElementComponent() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcElementComponentType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcElementQuantity() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcElementType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcElementarySurface() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcEllipse() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcEllipseProfileDef() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcEnergyConversionDevice() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcEnergyConversionDeviceType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcEnergyProperties() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcEngine() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcEngineType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcEnvironmentalImpactValue() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcEquipmentElement() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcEquipmentStandard() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcEvaporativeCooler() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcEvaporativeCoolerType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcEvaporator() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcEvaporatorType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcEvent() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcEventTime() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcEventType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcExtendedMaterialProperties() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcExtendedProperties() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcExternalInformation() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcExternalReference() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcExternalReferenceRelationship() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcExternalSpatialElement() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcExternalSpatialStructureElement() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcExternallyDefinedHatchStyle() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcExternallyDefinedSurfaceStyle() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcExternallyDefinedSymbol() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcExternallyDefinedTextFont() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcExtrudedAreaSolid() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcExtrudedAreaSolidTapered() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcFace() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcFaceBasedSurfaceModel() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcFaceBound() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcFaceOuterBound() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcFaceSurface() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcFacetedBrep() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcFacetedBrepWithVoids() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcFailureConnectionCondition() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcFan() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcFanType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcFastener() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcFastenerType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcFeatureElement() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcFeatureElementAddition() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcFeatureElementSubtraction() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcFillAreaStyle() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcFillAreaStyleHatching() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcFillAreaStyleTileSymbolWithStyle() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcFillAreaStyleTiles() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcFilter() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcFilterType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcFireSuppressionTerminal() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcFireSuppressionTerminalType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcFixedReferenceSweptAreaSolid() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcFlowController() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcFlowControllerType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcFlowFitting() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcFlowFittingType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcFlowInstrument() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcFlowInstrumentType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcFlowMeter() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcFlowMeterType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcFlowMovingDevice() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcFlowMovingDeviceType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcFlowSegment() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcFlowSegmentType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcFlowStorageDevice() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcFlowStorageDeviceType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcFlowTerminal() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcFlowTerminalType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcFlowTreatmentDevice() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcFlowTreatmentDeviceType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcFluidFlowProperties() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcFooting() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcFootingType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcFuelProperties() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcFurnishingElement() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcFurnishingElementType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcFurniture() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcFurnitureStandard() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcFurnitureType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcGasTerminalType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcGeneralMaterialProperties() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcGeneralProfileProperties() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcGeographicElement() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcGeographicElementType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcGeometricCurveSet() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcGeometricRepresentationContext() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcGeometricRepresentationItem() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcGeometricRepresentationSubContext() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcGeometricSet() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcGrid() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcGridAxis() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcGridPlacement() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcGroup() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcHalfSpaceSolid() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcHeatExchanger() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcHeatExchangerType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcHumidifier() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcHumidifierType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcHygroscopicMaterialProperties() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcIShapeProfileDef() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcImageTexture() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcIndexedColourMap() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcIndexedPolyCurve() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcIndexedPolygonalFace() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcIndexedPolygonalFaceWithVoids() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcIndexedTextureMap() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcIndexedTriangleTextureMap() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcInterceptor() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcInterceptorType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcIntersectionCurve() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcInventory() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcIrregularTimeSeries() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcIrregularTimeSeriesValue() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcJunctionBox() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcJunctionBoxType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcLShapeProfileDef() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcLaborResource() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcLaborResourceType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcLagTime() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcLamp() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcLampType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcLibraryInformation() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcLibraryReference() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcLightDistributionData() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcLightFixture() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcLightFixtureType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcLightIntensityDistribution() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcLightSource() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcLightSourceAmbient() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcLightSourceDirectional() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcLightSourceGoniometric() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcLightSourcePositional() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcLightSourceSpot() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcLine() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcLineSegment2D() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcLinearDimension() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcLinearPlacement() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcLinearPositioningElement() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcLocalPlacement() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcLocalTime() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcLoop() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcManifoldSolidBrep() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcMapConversion() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcMappedItem() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcMaterial() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcMaterialClassificationRelationship() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcMaterialConstituent() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcMaterialConstituentSet() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcMaterialDefinition() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcMaterialDefinitionRepresentation() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcMaterialLayer() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcMaterialLayerSet() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcMaterialLayerSetUsage() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcMaterialLayerWithOffsets() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcMaterialList() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcMaterialProfile() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcMaterialProfileSet() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcMaterialProfileSetUsage() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcMaterialProfileSetUsageTapering() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcMaterialProfileWithOffsets() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcMaterialProperties() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcMaterialRelationship() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcMaterialUsageDefinition() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcMeasureWithUnit() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcMechanicalConcreteMaterialProperties() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcMechanicalFastener() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcMechanicalFastenerType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcMechanicalMaterialProperties() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcMechanicalSteelMaterialProperties() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcMedicalDevice() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcMedicalDeviceType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcMember() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcMemberStandardCase() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcMemberType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcMetric() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcMirroredProfileDef() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcMonetaryUnit() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcMotorConnection() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcMotorConnectionType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcMove() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcNamedUnit() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcObject() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcObjectDefinition() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcObjectPlacement() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcObjective() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcOccupant() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcOffsetCurve() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcOffsetCurve2D() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcOffsetCurve3D() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcOffsetCurveByDistances() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcOneDirectionRepeatFactor() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcOpenShell() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcOpeningElement() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcOpeningStandardCase() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcOpticalMaterialProperties() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcOrderAction() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcOrganization() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcOrganizationRelationship() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcOrientationExpression() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcOrientedEdge() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcOuterBoundaryCurve() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcOutlet() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcOutletType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcOwnerHistory() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcParameterizedProfileDef() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcPath() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcPcurve() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcPerformanceHistory() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcPermeableCoveringProperties() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcPermit() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcPerson() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcPersonAndOrganization() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcPhysicalComplexQuantity() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcPhysicalQuantity() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcPhysicalSimpleQuantity() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcPile() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcPileType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcPipeFitting() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcPipeFittingType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcPipeSegment() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcPipeSegmentType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcPixelTexture() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcPlacement() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcPlanarBox() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcPlanarExtent() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcPlane() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcPlate() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcPlateStandardCase() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcPlateType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcPoint() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcPointOnCurve() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcPointOnSurface() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcPolyLoop() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcPolygonalBoundedHalfSpace() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcPolygonalFaceSet() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcPolyline() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcPort() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcPositioningElement() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcPostalAddress() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcPreDefinedColour() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcPreDefinedCurveFont() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcPreDefinedDimensionSymbol() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcPreDefinedItem() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcPreDefinedPointMarkerSymbol() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcPreDefinedProperties() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcPreDefinedPropertySet() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcPreDefinedSymbol() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcPreDefinedTerminatorSymbol() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcPreDefinedTextFont() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcPresentationItem() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcPresentationLayerAssignment() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcPresentationLayerWithStyle() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcPresentationStyle() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcPresentationStyleAssignment() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcProcedure() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcProcedureType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcProcess() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcProduct() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcProductDefinitionShape() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcProductRepresentation() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcProductsOfCombustionProperties() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcProfileDef() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcProfileProperties() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcProject() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcProjectLibrary() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcProjectOrder() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcProjectOrderRecord() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcProjectedCRS() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcProjectionCurve() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcProjectionElement() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcProperty() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcPropertyAbstraction() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcPropertyBoundedValue() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcPropertyConstraintRelationship() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcPropertyDefinition() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcPropertyDependencyRelationship() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcPropertyEnumeratedValue() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcPropertyEnumeration() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcPropertyListValue() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcPropertyReferenceValue() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcPropertySet() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcPropertySetDefinition() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcPropertySetTemplate() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcPropertySingleValue() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcPropertyTableValue() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcPropertyTemplate() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcPropertyTemplateDefinition() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcProtectiveDevice() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcProtectiveDeviceTrippingUnit() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcProtectiveDeviceTrippingUnitType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcProtectiveDeviceType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcProxy() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcPump() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcPumpType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcQuantityArea() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcQuantityCount() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcQuantityLength() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcQuantitySet() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcQuantityTime() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcQuantityVolume() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcQuantityWeight() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRadiusDimension() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRailing() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRailingType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRamp() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRampFlight() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRampFlightType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRampType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRationalBSplineCurveWithKnots() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRationalBSplineSurfaceWithKnots() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRationalBezierCurve() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRectangleHollowProfileDef() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRectangleProfileDef() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRectangularPyramid() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRectangularTrimmedSurface() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRecurrencePattern() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcReference() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcReferencesValueDocument() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcReferent() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRegularTimeSeries() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcReinforcementBarProperties() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcReinforcementDefinitionProperties() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcReinforcingBar() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcReinforcingBarType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcReinforcingElement() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcReinforcingElementType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcReinforcingMesh() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcReinforcingMeshType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRelAggregates() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRelAssigns() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRelAssignsTasks() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRelAssignsToActor() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRelAssignsToControl() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRelAssignsToGroup() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRelAssignsToGroupByFactor() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRelAssignsToProcess() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRelAssignsToProduct() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRelAssignsToProjectOrder() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRelAssignsToResource() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRelAssociates() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRelAssociatesAppliedValue() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRelAssociatesApproval() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRelAssociatesClassification() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRelAssociatesConstraint() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRelAssociatesDocument() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRelAssociatesLibrary() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRelAssociatesMaterial() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRelAssociatesProfileProperties() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRelConnects() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRelConnectsElements() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRelConnectsPathElements() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRelConnectsPortToElement() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRelConnectsPorts() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRelConnectsStructuralActivity() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRelConnectsStructuralElement() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRelConnectsStructuralMember() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRelConnectsWithEccentricity() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRelConnectsWithRealizingElements() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRelContainedInSpatialStructure() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRelCoversBldgElements() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRelCoversSpaces() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRelDeclares() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRelDecomposes() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRelDefines() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRelDefinesByObject() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRelDefinesByProperties() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRelDefinesByTemplate() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRelDefinesByType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRelFillsElement() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRelFlowControlElements() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRelInteractionRequirements() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRelInterferesElements() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRelNests() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRelOccupiesSpaces() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRelOverridesProperties() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRelProjectsElement() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRelReferencedInSpatialStructure() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRelSchedulesCostItems() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRelSequence() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRelServicesBuildings() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRelSpaceBoundary() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRelSpaceBoundary1stLevel() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRelSpaceBoundary2ndLevel() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRelVoidsElement() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRelationship() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRelaxation() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcReparametrisedCompositeCurveSegment() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRepresentation() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRepresentationContext() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRepresentationItem() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRepresentationMap() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcResource() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcResourceApprovalRelationship() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcResourceConstraintRelationship() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcResourceLevelRelationship() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcResourceTime() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRevolvedAreaSolid() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRevolvedAreaSolidTapered() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRibPlateProfileProperties() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRightCircularCone() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRightCircularCylinder() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRoof() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRoofType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRoot() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRoundedEdgeFeature() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcRoundedRectangleProfileDef() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcSIUnit() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcSanitaryTerminal() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcSanitaryTerminalType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcScheduleTimeControl() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcSchedulingTime() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcSeamCurve() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcSectionProperties() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcSectionReinforcementProperties() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcSectionedSolid() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcSectionedSolidHorizontal() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcSectionedSpine() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcSensor() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcSensorType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcServiceLife() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcServiceLifeFactor() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcShadingDevice() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcShadingDeviceType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcShapeAspect() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcShapeModel() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcShapeRepresentation() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcShellBasedSurfaceModel() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcSimpleProperty() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcSimplePropertyTemplate() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcSite() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcSlab() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcSlabElementedCase() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcSlabStandardCase() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcSlabType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcSlippageConnectionCondition() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcSolarDevice() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcSolarDeviceType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcSolidModel() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcSoundProperties() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcSoundValue() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcSpace() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcSpaceHeater() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcSpaceHeaterType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcSpaceProgram() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcSpaceThermalLoadProperties() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcSpaceType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcSpatialElement() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcSpatialElementType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcSpatialStructureElement() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcSpatialStructureElementType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcSpatialZone() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcSpatialZoneType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcSphere() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcSphericalSurface() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcStackTerminal() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcStackTerminalType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcStair() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcStairFlight() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcStairFlightType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcStairType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcStructuralAction() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcStructuralActivity() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcStructuralAnalysisModel() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcStructuralConnection() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcStructuralConnectionCondition() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcStructuralCurveAction() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcStructuralCurveConnection() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcStructuralCurveMember() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcStructuralCurveMemberVarying() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcStructuralCurveReaction() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcStructuralItem() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcStructuralLinearAction() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcStructuralLinearActionVarying() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcStructuralLoad() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcStructuralLoadCase() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcStructuralLoadConfiguration() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcStructuralLoadGroup() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcStructuralLoadLinearForce() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcStructuralLoadOrResult() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcStructuralLoadPlanarForce() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcStructuralLoadSingleDisplacement() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcStructuralLoadSingleDisplacementDistortion() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcStructuralLoadSingleForce() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcStructuralLoadSingleForceWarping() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcStructuralLoadStatic() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcStructuralLoadTemperature() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcStructuralMember() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcStructuralPlanarAction() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcStructuralPlanarActionVarying() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcStructuralPointAction() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcStructuralPointConnection() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcStructuralPointReaction() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcStructuralProfileProperties() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcStructuralReaction() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcStructuralResultGroup() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcStructuralSteelProfileProperties() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcStructuralSurfaceAction() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcStructuralSurfaceConnection() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcStructuralSurfaceMember() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcStructuralSurfaceMemberVarying() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcStructuralSurfaceReaction() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcStructuredDimensionCallout() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcStyleModel() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcStyledItem() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcStyledRepresentation() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcSubContractResource() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcSubContractResourceType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcSubedge() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcSurface() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcSurfaceCurve() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcSurfaceCurveSweptAreaSolid() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcSurfaceFeature() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcSurfaceOfLinearExtrusion() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcSurfaceOfRevolution() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcSurfaceReinforcementArea() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcSurfaceStyle() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcSurfaceStyleLighting() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcSurfaceStyleRefraction() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcSurfaceStyleRendering() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcSurfaceStyleShading() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcSurfaceStyleWithTextures() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcSurfaceTexture() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcSweptAreaSolid() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcSweptDiskSolid() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcSweptDiskSolidPolygonal() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcSweptSurface() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcSwitchingDevice() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcSwitchingDeviceType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcSymbolStyle() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcSystem() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcSystemFurnitureElement() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcSystemFurnitureElementType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcTShapeProfileDef() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcTable() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcTableColumn() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcTableRow() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcTank() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcTankType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcTask() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcTaskTime() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcTaskTimeRecurring() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcTaskType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcTelecomAddress() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcTendon() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcTendonAnchor() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcTendonAnchorType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcTendonType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcTerminatorSymbol() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcTessellatedFaceSet() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcTessellatedItem() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcTextLiteral() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcTextLiteralWithExtent() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcTextStyle() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcTextStyleFontModel() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcTextStyleForDefinedFont() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcTextStyleTextModel() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcTextStyleWithBoxCharacteristics() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcTextureCoordinate() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcTextureCoordinateGenerator() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcTextureMap() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcTextureVertex() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcTextureVertexList() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcThermalMaterialProperties() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcTimePeriod() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcTimeSeries() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcTimeSeriesReferenceRelationship() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcTimeSeriesSchedule() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcTimeSeriesValue() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcTopologicalRepresentationItem() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcTopologyRepresentation() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcToroidalSurface() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcTransformer() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcTransformerType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcTransitionCurveSegment2D() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcTransportElement() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcTransportElementType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcTrapeziumProfileDef() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcTriangulatedFaceSet() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcTriangulatedIrregularNetwork() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcTrimmedCurve() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcTubeBundle() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcTubeBundleType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcTwoDirectionRepeatFactor() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcTypeObject() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcTypeProcess() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcTypeProduct() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcTypeResource() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcUShapeProfileDef() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcUnitAssignment() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcUnitaryControlElement() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcUnitaryControlElementType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcUnitaryEquipment() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcUnitaryEquipmentType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcValve() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcValveType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcVector() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcVertex() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcVertexBasedTextureMap() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcVertexLoop() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcVertexPoint() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcVibrationIsolator() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcVibrationIsolatorType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcVirtualElement() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcVirtualGridIntersection() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcVoidingFeature() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcWall() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcWallElementedCase() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcWallStandardCase() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcWallType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcWasteTerminal() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcWasteTerminalType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcWaterProperties() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcWindow() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcWindowLiningProperties() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcWindowPanelProperties() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcWindowStandardCase() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcWindowStyle() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcWindowType() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcWorkCalendar() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcWorkControl() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcWorkPlan() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcWorkSchedule() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcWorkTime() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcZShapeProfileDef() -> IfcEntityDesc:
        pass
    @staticmethod
    def IfcZone() -> IfcEntityDesc:
        pass
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def className() -> str:
        pass
    def isDerivedFrom(self, entDesc: PyBrxBim.IfcEntityDesc, eSchema: IfcSchemaId, /) -> bool:
        pass
    def name(self, /) -> str:
        pass
class IfcEnumValue:
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
    def getValue(self, /) -> str:
        pass
    def setValue(self, val: str, /) -> None:
        pass
class IfcGuid:
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def create() -> IfcGuid:
        pass
    @staticmethod
    def createFromBase64(val: str, /) -> IfcGuid:
        pass
    @staticmethod
    def createFromText(val: str, /) -> IfcGuid:
        pass
    def getBase64(self, /) -> str:
        pass
    def getText(self, /) -> str:
        pass
class IfcHeader:
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    def author(self, /) -> IfcString:
        pass
    def authorization(self, /) -> IfcString:
        pass
    @staticmethod
    def className() -> str:
        pass
    def fileDescription(self, /) -> IfcString:
        pass
    def fileName(self, /) -> IfcString:
        pass
    def fileSchema(self, /) -> IfcString:
        pass
    def implementationLevel(self, /) -> IfcString:
        pass
    def organization(self, /) -> IfcString:
        pass
    def originatingSystem(self, /) -> IfcString:
        pass
    def preprocessorVersion(self, /) -> IfcString:
        pass
    def setAuthor(self, val: PyBrxBim.IfcString, /) -> None:
        pass
    def setAuthorization(self, val: PyBrxBim.IfcString, /) -> None:
        pass
    def setFileDescription(self, val: PyBrxBim.IfcString, /) -> None:
        pass
    def setFileName(self, val: PyBrxBim.IfcString, /) -> None:
        pass
    def setFileSchema(self, val: PyBrxBim.IfcString, /) -> None:
        pass
    def setOrganization(self, val: PyBrxBim.IfcString, /) -> None:
        pass
    def setOriginatingSystem(self, val: PyBrxBim.IfcString, /) -> None:
        pass
    def setPreprocessorVersion(self, val: PyBrxBim.IfcString, /) -> None:
        pass
    def setTimeStamp(self, val: PyBrxBim.IfcString, /) -> None:
        pass
    def timeStamp(self, /) -> IfcString:
        pass
class IfcImportContext:
    def IfcModel(self, /) -> IfcModel:
        pass
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    def angleConversionFactor(self, /) -> float:
        pass
    def areaConversionFactor(self, /) -> float:
        pass
    @staticmethod
    def className() -> str:
        pass
    def createDefaultRepresentation(self, entity: PyBrxBim.IfcEntity, isParent: bool, parent: PyBrxBim.IfcEntity, /) -> PyBr.Entity:
        pass
    def createPoint(self, entity: PyBrxBim.IfcEntity, /) -> PyGe.Point3d:
        pass
    def createRepresentationFromItem(self, entity: PyBrxBim.IfcEntity, /) -> PyBr.Entity:
        pass
    def createSweptArea(self, entity: PyBrxBim.IfcEntity, /) -> list:
        pass
    def database(self, /) -> PyDb.Database:
        pass
    def getEntity(self, entity: PyBrxBim.IfcEntity, /) -> PyBr.Entity:
        pass
    def getEntityId(self, entity: PyBrxBim.IfcEntity, /) -> PyDb.ObjectId:
        pass
    def getLocalPlacement(self, entity: PyBrxBim.IfcEntity, /) -> PyGe.Matrix3d:
        pass
    def lengthConversionFactor(self, /) -> float:
        pass
    def precision(self, /) -> float:
        pass
    def volumeConversionFactor(self, /) -> float:
        pass
class IfcImportInfo:
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    def author(self, /) -> str:
        pass
    def authorization(self, /) -> str:
        pass
    @staticmethod
    def className() -> str:
        pass
    def importBimData(self, /) -> bool:
        pass
    def importBrepGeometryAsMeshes(self, /) -> bool:
        pass
    def importIfcProjectStructureAsXrefs(self, /) -> bool:
        pass
    def importIfcSpace(self, /) -> bool:
        pass
    def importParametricComponents(self, /) -> bool:
        pass
    def organization(self, /) -> str:
        pass
    def originatingSystem(self, /) -> str:
        pass
    def preprocessorVersion(self, /) -> str:
        pass
    def timeStamp(self, /) -> str:
        pass
class IfcImportModelOrigin(_BoostPythonEnum):
    eIfcGlobalOrigin: ClassVar[Self]  # 0
    eIfcSiteLocation: ClassVar[Self]  # 1
    eIfcProjectLocation: ClassVar[Self]  # 2
class IfcImportOptions:
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def className() -> str:
        pass
    def importBimData(self, /) -> bool:
        pass
    def importBrepGeometryAsMeshes(self, /) -> bool:
        pass
    @staticmethod
    def importIfcFile(db: PyDb.Database,filename: str,options: PyBrxIfc.ImportOptions=None, /) -> None:
        pass
    def importIfcProjectStructureAsXrefs(self, /) -> bool:
        pass
    def importIfcSpace(self, /) -> bool:
        pass
    def importModelOrigin(self, /) -> IfcImportModelOrigin:
        pass
    def importParametricComponents(self, /) -> bool:
        pass
    def setImportBimData(self, val: bool, /) -> None:
        pass
    def setImportBrepGeometryAsMeshes(self, val: bool, /) -> None:
        pass
    def setImportIfcProjectStructureAsXrefs(self, val: bool, /) -> None:
        pass
    def setImportIfcSpace(self, val: bool, /) -> None:
        pass
    def setImportModelOrigin(self, val: PyBrxBim.IfcImportModelOrigin, /) -> None:
        pass
    def setImportParametricComponents(self, val: bool, /) -> None:
        pass
class IfcImportReactor:
    def __init__(self, displayName: str, guid: str, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    def attachReactor(self, /) -> bool:
        pass
    def beforeCompletion(self, context: PyBrxBim.IfcImportContext, success: bool, /) -> None:
        pass
    @staticmethod
    def className() -> str:
        pass
    def detachReactor(self, /) -> bool:
        pass
    def onIfcProduct(self, context: PyBrxBim.IfcImportContext, entity:  PyBrxBim.IfcEntity, isParent: bool, parentEntity:  PyBrxBim.IfcEntity, /) -> bool:
        pass
    def onIfcProductImported(self, desc: PyBrxBim.IfcEntityDesc, schema: EIfcSchemaId, /) -> None:
        pass
    def onStart(self, context: PyBrxBim.IfcImportContext, project:  PyBrxBim.IfcEntity, info: PyBrxBim.IfcImportInfo, /) -> None:
        pass
class IfcLogical:
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def className() -> str:
        pass
    def isKnown(self, /) -> bool:
        pass
    def isUnknown(self, /) -> bool:
        pass
class IfcModel:
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
    def get(self, val: int, /) -> IfcEntity:
        pass
    def getNumEntities(self, /) -> int:
        pass
    @staticmethod
    def read(val: str, /) -> IfcModel:
        pass
    def release(self, /) -> None:
        pass
    def schemaId(self, /) -> IfcSchemaId:
        pass
    @staticmethod
    def write(val: str,val: PyBrxBim.IfcHeader, /) -> bool:
        pass
class IfcResult(_BoostPythonEnum):
    eOk: ClassVar[Self]  # 0
    eNotInitialized: ClassVar[Self]  # 1
    eWrongName: ClassVar[Self]  # 2
    eWrongType: ClassVar[Self]  # 3
    eInternalError: ClassVar[Self]  # 4
class IfcSchemaId(_BoostPythonEnum):
    eIFC2X3: ClassVar[Self]  # 0
    eIFC4: ClassVar[Self]  # 1
    eIFC4X1: ClassVar[Self]  # 2
    eIfcSchemaLast: ClassVar[Self]  # 2
class IfcSelectValue:
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
    def getValue(self, /) -> IfcVariant:
        pass
    def isNull(self, /) -> bool:
        pass
    def setValue(self, tag: str, val: PyBrxBim.IfcVariant, /) -> str:
        pass
    def tag(self, /) -> str:
        pass
class IfcSelectorDesc:
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def className() -> str:
        pass
class IfcString:
    @overload
    def __init__(self, /) -> None: ...
    @overload
    def __init__(self, text: str, /) -> None: ...
    def __init__(self, *args) -> None:
        pass
    def __reduce__(self, /):
        pass
    def c_str(self, /) -> str:
        pass
    @staticmethod
    def className() -> str:
        pass
    @staticmethod
    def decode(val: str, /) -> IfcString:
        pass
    def getEncoded(self, /) -> str:
        pass
    def isEmpty(self, /) -> bool:
        pass
    def setEmpty(self, /) -> None:
        pass
class IfcValueType(_BoostPythonEnum):
    eBool: ClassVar[Self]  # 0
    eInt: ClassVar[Self]  # 1
    eUInt: ClassVar[Self]  # 2
    eReal: ClassVar[Self]  # 3
    eString: ClassVar[Self]  # 4
    eEntity: ClassVar[Self]  # 5
    eLogical: ClassVar[Self]  # 6
    eBinary: ClassVar[Self]  # 7
    eGuid: ClassVar[Self]  # 8
    eEnum: ClassVar[Self]  # 9
    eSelect: ClassVar[Self]  # 10
    eVector: ClassVar[Self]  # 11
    eEmpty: ClassVar[Self]  # 12
class IfcVariant:
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def className() -> str:
        pass
    def getBinary(self, /) -> IfcBinary:
        pass
    def getBool(self, /) -> bool:
        pass
    def getEntity(self, /) -> IfcEntity:
        pass
    def getEnum(self, /) -> IfcEnumValue:
        pass
    def getGuid(self, /) -> IfcGuid:
        pass
    def getInt(self, /) -> int:
        pass
    def getLogical(self, /) -> IfcLogical:
        pass
    def getReal(self, /) -> float:
        pass
    def getSelect(self, /) -> IfcSelectValue:
        pass
    def getString(self, /) -> IfcString:
        pass
    def getUInt(self, /) -> int:
        pass
    def getVector(self, /) -> IfcVectorValue:
        pass
    def setBinary(self, val: PyBrxBim.IfcBinary, /) -> None:
        pass
    def setBool(self, val: bool, /) -> None:
        pass
    def setEntity(self, val: PyBrxBim.IfcEntity, /) -> None:
        pass
    def setEnum(self, val: PyBrxBim.IfcEnumValue, /) -> None:
        pass
    def setGuid(self, val: PyBrxBim.IfcGuid, /) -> None:
        pass
    def setInt(self, val: int, /) -> None:
        pass
    def setLogical(self, val: PyBrxBim.IfcLogical, /) -> None:
        pass
    def setReal(self, val: float, /) -> None:
        pass
    def setSelect(self, val: PyBrxBim.IfcVectorValue, /) -> None:
        pass
    def setString(self, val: PyBrxBim.IfcString, /) -> None:
        pass
    def setUInt(self, val: int, /) -> None:
        pass
    def setVector(self, val: PyBrxBim.IfcVectorValue, /) -> None:
        pass
    def type(self, /) -> IfcValueType:
        pass
class IfcVectorDesc:
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def className() -> str:
        pass
class IfcVectorValue:
    def __init__(self):
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /):
        pass
    def add(self, val: PyBrxBim.IfcVariant, /) -> IfcResult:
        pass
    @staticmethod
    def className() -> str:
        pass
    def clear(self, /) -> None:
        pass
    def isNull(self, /) -> bool:
        pass
    def remove(self, val: int, /) -> bool:
        pass
    def size(self, /) -> int:
        pass
    def values(self, /) -> list:
        pass
class PyBrxBimPropertySets:
    def __init__(self, /) -> None:
        pass
    def __reduce__(self, /):
        pass
    @staticmethod
    def className() -> str:
        pass
class ResultStatus(_BoostPythonEnum):
    eOk: ClassVar[Self]  # 0
    eNoDbResidentObject: ClassVar[Self]  # 1
    eDbNotAccessible: ClassVar[Self]  # 2
    eDbObjectNotSupported: ClassVar[Self]  # 3
    eDbNotOpenForWrite: ClassVar[Self]  # 4
    eModelSpaceNotAccessible: ClassVar[Self]  # 5
    eProjectDbNotAccessible: ClassVar[Self]  # 6
    eAssociatedLibraryNotAccessible: ClassVar[Self]  # 7
    eNotApplicableForTheseParameters: ClassVar[Self]  # 8
    eInvalidSpatialLocation: ClassVar[Self]  # 9
    eInvalidMaterial: ClassVar[Self]  # 10
    eInvalidMaterialComposition: ClassVar[Self]  # 11
    eObjectAlreadyExists: ClassVar[Self]  # 12
    eObjectCouldNotBeDeleted: ClassVar[Self]  # 13
    eXmlFileCouldNotBeParsed: ClassVar[Self]  # 14
    eInvalidXmlFormat: ClassVar[Self]  # 15
    eInvalidName: ClassVar[Self]  # 16
    eNotLinearBuildingElement: ClassVar[Self]  # 17
    eInvalidValue: ClassVar[Self]  # 18
    eNotAssignedToLibrary: ClassVar[Self]  # 19
    eNullObject: ClassVar[Self]  # 20
    eNullObjectId: ClassVar[Self]  # 21
    eNullDatabase: ClassVar[Self]  # 22
    eNullDocument: ClassVar[Self]  # 23
    eNullString: ClassVar[Self]  # 24
    eObjectNotExisting: ClassVar[Self]  # 25
    eObjectNotSupported: ClassVar[Self]  # 26
    eNoProfileAssigned: ClassVar[Self]  # 27
    eNoData: ClassVar[Self]  # 28
    eUnknownData: ClassVar[Self]  # 29
    eWrongDataType: ClassVar[Self]  # 30
    eUnassignedEntity: ClassVar[Self]  # 31
    eBimNotImplementedYet: ClassVar[Self]  # 32
    eBimNotAvailable: ClassVar[Self]  # 33
    eInternalError: ClassVar[Self]  # 34
    eUnknownError: ClassVar[Self]  # 35
    eInvalidIndex: ClassVar[Self]  # 36
    eInvalidInput: ClassVar[Self]  # 37
    eNoNameSpace: ClassVar[Self]  # 38
    eNameSpaceAlreadyExists: ClassVar[Self]  # 39
    eNoPropertySet: ClassVar[Self]  # 40
    ePropertySetAlreadyExists: ClassVar[Self]  # 41
    eNoProperty: ClassVar[Self]  # 42
    eNotImplemented: ClassVar[Self]  # 43
    eInvalidArgument: ClassVar[Self]  # 44
    eNoAttributeSet: ClassVar[Self]  # 45
