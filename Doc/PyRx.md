# PyRx

```PY



kAngle: LispType  # 5004
kDottedPair: LispType  # 5018
kDouble: LispType  # 5001
kEqual: Ordering  # 0
kGreaterThan: Ordering  # 1
kInt16: LispType  # 5003
kInt32: LispType  # 5010
kLessThan: Ordering  # -1
kListBegin: LispType  # 5016
kListEnd: LispType  # 5017
kNil: LispType  # 5019
kNone: LispType  # 5000
kNotOrderable: Ordering  # 2
kObjectId: LispType  # 5006
kOrientation: LispType  # 5008
kPoint2d: LispType  # 5002
kPoint3d: LispType  # 5009
kSelectionSet: LispType  # 5007
kT_atom: LispType  # 5021
kText: LispType  # 5005
kVector2d: LispType  # 5002
kVector3d: LispType  # 5009
kVoid: LispType  # 5014

class LispType(_BoostPythonEnum):
    kAngle: ClassVar[Self]  # 5004
    kDottedPair: ClassVar[Self]  # 5018
    kDouble: ClassVar[Self]  # 5001
    kInt16: ClassVar[Self]  # 5003
    kInt32: ClassVar[Self]  # 5010
    kListBegin: ClassVar[Self]  # 5016
    kListEnd: ClassVar[Self]  # 5017
    kNil: ClassVar[Self]  # 5019
    kNone: ClassVar[Self]  # 5000
    kObjectId: ClassVar[Self]  # 5006
    kOrientation: ClassVar[Self]  # 5008
    kPoint2d: ClassVar[Self]  # 5002
    kVector2d: ClassVar[Self]  # 5002
    kPoint3d: ClassVar[Self]  # 5009
    kVector3d: ClassVar[Self]  # 5009
    kT_atom: ClassVar[Self]  # 5021
    kText: ClassVar[Self]  # 5005
    kVoid: ClassVar[Self]  # 5014
    kSelectionSet: ClassVar[Self]  # 5007

class Ordering(_BoostPythonEnum):
    kLessThan: ClassVar[Self]  # -1
    kEqual: ClassVar[Self]  # 0
    kGreaterThan: ClassVar[Self]  # 1
    kNotOrderable: ClassVar[Self]  # 2

class Overrule(PyRx.RxObject):
    def __init__(self) -> None:
    def __reduce__(self, /) -> Any:  
    @staticmethod
    def addOverrule(rxClass: PyRx.RxClass, overrule: PyRx.Overrule, /) -> None:  
    @staticmethod
    def addOverruleLast(
        rxClass: PyRx.RxClass, overrule: PyRx.Overrule, addLast: bool, /
    ) -> None:  
    @staticmethod
    def className() -> str:  
    @staticmethod
    def desc() -> RxClass:
    @staticmethod
    def hasOverrule(subject: PyRx.RxObject, rxClass: PyRx.RxClass, /) -> bool:  
    @staticmethod
    def isOverruling() -> bool:  
    @staticmethod
    def removeOverrule(rxClass: PyRx.RxClass, overrule: PyRx.Overrule, /) -> None:  
    @staticmethod
    def setIsOverruling(flag: bool, /) -> None:  

class RxClass(PyRx.RxObject):
    def __init__(self) -> None:
    def __reduce__(self, /) -> Any:  
    def appName(self, /) -> str:
    @staticmethod
    def className() -> str:  
    @staticmethod
    def desc() -> RxClass:
    def dxfName(self, /) -> str:
    def isDerivedFrom(self, other: PyRx.RxClass, /) -> bool:
    def myParent(self, /) -> RxClass:
    def name(self, /) -> str:
    def queryX(self, rhs: PyRx.RxClass, /) -> RxObject:

class RxObject:
    def __hash__(self, /) -> int:  
    def __init__(self) -> None:
    def __ne__(self, rhs: PyRx.RxObject, /) -> bool:  
    def __reduce__(self, /) -> Any:  
    @staticmethod
    def className() -> str:  
    def comparedTo(self, other: PyRx.RxObject, /) -> Ordering:
    def copyFrom(self, other: PyRx.RxObject, /) -> None:
    @staticmethod
    def desc() -> RxClass:
    def dispose(self, /) -> None:  
    def implRefCount(self, /) -> int:  
    def intPtr(self, /) -> int:  
    def isA(self, /) -> RxClass:
    def isDerivedFrom(self, other: PyRx.RxClass, /) -> bool:
    def isKindOf(self, rhs: PyRx.RxClass, /) -> bool:
    def isNullObj(self, /) -> bool:  
    def keepAlive(self, flag: bool, /) -> None:  
    def queryX(self, rhs: PyRx.RxClass, /) -> RxObject:

class stderr:
    def __init__(self, /) -> None:  
    def __reduce__(self, /) -> Any:  
    def flush(self, /) -> None:  
    def write(self, /) -> None:  

class stdout:
    def __init__(self, /) -> None:  
    def __reduce__(self, /) -> Any:  
    def flush(self, /) -> None:  
    def write(self, /) -> None:  
```
