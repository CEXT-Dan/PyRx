from __future__ import annotations

from typing import Any, ClassVar, Self, overload

import wx

from pyrx import Brx as PyBrx
from pyrx import Db as PyDb
from pyrx.doc_utils.boost_meta import _BoostPythonEnum

eAc3DAngle: ConstraintType  # 1
eAc3DCoincident: ConstraintType  # 2
eAc3DConcentric: ConstraintType  # 3
eAc3DDistance: ConstraintType  # 4
eAc3DFix: ConstraintType  # 5
eAc3DMajorRadius: ConstraintType  # 6
eAc3DMinorRadius: ConstraintType  # 7
eAc3DParallel: ConstraintType  # 8
eAc3DPerpendicular: ConstraintType  # 9
eAc3DPlanarAngle: ConstraintType  # 10
eAc3DRadius: ConstraintType  # 11
eAc3DRigidSet: ConstraintType  # 12
eAc3DTangent: ConstraintType  # 13
eAcCircularArray: ConstraintType  # 14
eAcObjectAngle: ConstraintType  # 15
eAcPath: ConstraintType  # 16
eAcUnknown: ConstraintType  # 0
eBim: LicensedFeature  # 2
eBoolean: MechanicalPropertyType  # 3
eCommunicator: LicensedFeature  # 1
eCore: LicensedFeature  # 0
eDirectionsAny: ConstraintDirections  # 0
eDirectionsKeep: ConstraintDirections  # 3
eDirectionsOpposite: ConstraintDirections  # 2
eDirectionsSame: ConstraintDirections  # 1
eInteger: MechanicalPropertyType  # 1
eMeasurementModeBoundary: ConstraintMeasurementMode  # 1
eMeasurementModeCenter: ConstraintMeasurementMode  # 0
eMeasurementModeCentralPoint: ConstraintMeasurementMode  # 2
eMechanical: LicensedFeature  # 3
ePlacementAny: ConstraintPlacement  # 0
ePlacementInside: ConstraintPlacement  # 2
ePlacementKeep: ConstraintPlacement  # 3
ePlacementOutside: ConstraintPlacement  # 1
eReal: MechanicalPropertyType  # 2
eString: MechanicalPropertyType  # 4
eUndefined: MechanicalPropertyType  # 0

class ConstraintDirections(_BoostPythonEnum):
    eDirectionsAny: ClassVar[Self]  # 0
    eDirectionsSame: ClassVar[Self]  # 1
    eDirectionsOpposite: ClassVar[Self]  # 2
    eDirectionsKeep: ClassVar[Self]  # 3

class ConstraintMeasurementMode(_BoostPythonEnum):
    eMeasurementModeCenter: ClassVar[Self]  # 0
    eMeasurementModeBoundary: ClassVar[Self]  # 1
    eMeasurementModeCentralPoint: ClassVar[Self]  # 2

class ConstraintPlacement(_BoostPythonEnum):
    ePlacementAny: ClassVar[Self]  # 0
    ePlacementOutside: ClassVar[Self]  # 1
    ePlacementInside: ClassVar[Self]  # 2
    ePlacementKeep: ClassVar[Self]  # 3

class ConstraintType(_BoostPythonEnum):
    eAcUnknown: ClassVar[Self]  # 0
    eAc3DAngle: ClassVar[Self]  # 1
    eAc3DCoincident: ClassVar[Self]  # 2
    eAc3DConcentric: ClassVar[Self]  # 3
    eAc3DDistance: ClassVar[Self]  # 4
    eAc3DFix: ClassVar[Self]  # 5
    eAc3DMajorRadius: ClassVar[Self]  # 6
    eAc3DMinorRadius: ClassVar[Self]  # 7
    eAc3DParallel: ClassVar[Self]  # 8
    eAc3DPerpendicular: ClassVar[Self]  # 9
    eAc3DPlanarAngle: ClassVar[Self]  # 10
    eAc3DRadius: ClassVar[Self]  # 11
    eAc3DRigidSet: ClassVar[Self]  # 12
    eAc3DTangent: ClassVar[Self]  # 13
    eAcCircularArray: ClassVar[Self]  # 14
    eAcObjectAngle: ClassVar[Self]  # 15
    eAcPath: ClassVar[Self]  # 16

class Core:
    def __init__(self) -> None:
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def blockParameterHasStringValue(blockRefId: PyDb.ObjectId, name: str, /) -> bool: ...
    @staticmethod
    def effectiveBlockRefName(blockRefId: PyDb.ObjectId, /) -> str: ...
    @staticmethod
    def effectiveBlockTableRecord(blockRefId: PyDb.ObjectId, /) -> PyDb.ObjectId: ...
    @staticmethod
    def getBlockParameterExpression(blockRefId: PyDb.ObjectId, name: str, /) -> str: ...
    @staticmethod
    def getBlockParameterStringValue(blockRefId: PyDb.ObjectId, name: str, /) -> str: ...
    @staticmethod
    def getBlockParameterValue(blockRefId: PyDb.ObjectId, name: str, /) -> float: ...
    @staticmethod
    def getBlockParametersNames(blockRefId: PyDb.ObjectId, /) -> list: ...
    @staticmethod
    def getEntityGuiName(entId: PyDb.ObjectId, /) -> str: ...
    @staticmethod
    def getOpenObjects() -> list: ...
    @staticmethod
    def isLicenseAvailable(val: PyBrx.LicensedFeature, /) -> bool: ...
    @staticmethod
    def removeConstraints(id: PyDb.ObjectId, /) -> bool: ...
    @staticmethod
    def removeConstraintsFromDatabase(db: PyDb.Database, /) -> bool: ...
    @staticmethod
    def setBlockParameterExpression(
        blockRefId: PyDb.ObjectId, name: str, expr: str, /
    ) -> None: ...
    @staticmethod
    def setEntityGuiName(entId: PyDb.ObjectId, name: str, /) -> None: ...

class DbProperties:
    def __init__(self) -> None:
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def dumpAll(id: PyDb.ObjectId, /) -> None: ...
    @staticmethod
    def getValue(id: PyDb.ObjectId, name: str, /) -> PyDb.AcValue: ...
    @staticmethod
    def isReadOnly(id: PyDb.ObjectId, name: str, /) -> tuple: ...
    @staticmethod
    def isValid(id: PyDb.ObjectId, name: str, /) -> tuple: ...
    @staticmethod
    def listAll(id: PyDb.ObjectId, /) -> list: ...
    @staticmethod
    def setValue(id: PyDb.ObjectId, name: str, val: PyDb.AcValue, /) -> None: ...

class LicensedFeature(_BoostPythonEnum):
    eCore: ClassVar[Self]  # 0
    eCommunicator: ClassVar[Self]  # 1
    eBim: ClassVar[Self]  # 2
    eMechanical: ClassVar[Self]  # 3

class MechanicalPropertyDefinition:
    def __init__(self, /) -> None: ...
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def className() -> str: ...
    def doesExist(self, /) -> bool: ...
    def enumValues(self, /) -> list: ...
    def isNull(self, /) -> bool: ...
    def label(self, /) -> str: ...
    def name(self, /) -> str: ...
    def setEnumValues(self, aNewEnumValues: list[tuple[str, str]], /) -> None: ...
    def setLabel(self, newLabel: str, /) -> None: ...
    def setType(self, newTypeName: PyBrx.MechanicalPropertyType, /) -> None: ...
    def type(self, /) -> MechanicalPropertyType: ...

class MechanicalPropertySet:
    def __init__(self, /) -> None: ...
    def __reduce__(self, /) -> Any: ...
    def addProperty(
        self, propertyName: str, propertyType: PyBrx.MechanicalPropertyType, label: str = ..., /
    ) -> MechanicalPropertyDefinition: ...
    def categoryLabel(self, /) -> str: ...
    def categoryName(self, /) -> str: ...
    @staticmethod
    def className() -> str: ...
    @overload
    def createCategory(db: PyDb.Database, propertyName: str, /) -> MechanicalPropertySet: ...
    @overload
    def createCategory(
        db: PyDb.Database, propertyName: str, isPerInstance: bool, /
    ) -> MechanicalPropertySet: ...
    @overload
    def createCategory(
        db: PyDb.Database, propertyName: str, isPerInstance: bool, label: str, /
    ) -> MechanicalPropertySet: ...
    @overload
    def createCategory(self, *args) -> MechanicalPropertySet: ...
    @staticmethod
    def getAllCategories() -> Any: ...
    def getAllCustomProperties(self, /) -> list: ...
    def getCategoryByName(db: PyDb.Database, propertyName: str, /) -> MechanicalPropertySet: ...
    def getPropertyByName(self, propertyName: str, /) -> MechanicalPropertyDefinition: ...
    def isNull(self, /) -> bool: ...
    def isPerInstance(self, /) -> bool: ...

class MechanicalPropertyType(_BoostPythonEnum):
    eUndefined: ClassVar[Self]  # 0
    eInteger: ClassVar[Self]  # 1
    eReal: ClassVar[Self]  # 2
    eBoolean: ClassVar[Self]  # 3
    eString: ClassVar[Self]  # 4

class PyBrxPanel:
    def __init__(self, name: str, configKey: str = ..., /) -> None: ...
    def __reduce__(self, /) -> Any: ...
    def backgroundColor(self, /) -> int: ...
    def create(self, panel: wx.Panel, /) -> bool: ...
    def destroy(self, /) -> None: ...
    def isFloating(self, /) -> bool: ...
    def setIcon(self, imagePath: str, /) -> None: ...
    def tabTextColor(self, /) -> int: ...
