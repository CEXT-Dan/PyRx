from __future__ import annotations

from typing import Any, ClassVar, Self

from pyrx import Rx as PyRx
from pyrx.doc_utils.boost_meta import _BoostPythonEnum

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
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def addOverrule(rxClass: PyRx.RxClass, overrule: PyRx.Overrule, /) -> None: ...
    @staticmethod
    def addOverruleLast(
        rxClass: PyRx.RxClass, overrule: PyRx.Overrule, addLast: bool, /
    ) -> None: ...
    @staticmethod
    def className() -> str: ...
    @staticmethod
    def desc() -> RxClass:
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
    @staticmethod
    def hasOverrule(subject: PyRx.RxObject, rxClass: PyRx.RxClass, /) -> bool: ...
    @staticmethod
    def isOverruling() -> bool: ...
    @staticmethod
    def removeOverrule(rxClass: PyRx.RxClass, overrule: PyRx.Overrule, /) -> None: ...
    @staticmethod
    def setIsOverruling(flag: bool, /) -> None: ...

class RxClass(PyRx.RxObject):
    def __init__(self) -> None:
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /) -> Any: ...
    def appName(self, /) -> str:
        """
        Returns a pointer to the application name string which is the last parameter in the
        ACRX_DXF_DEFINE_MEMBERS macro and is also the last parameter to the global newAcRxClass()
        pseudo-constructor. This string is used as the application identifier in the error dialog
        that is displayed whenever an object of the class is loaded and the application is not
        present. WarningAs the const qualifier indicates, no attempt should be made to deallocate
        the returned string.
        """
    @staticmethod
    def className() -> str: ...
    @staticmethod
    def desc() -> RxClass:
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
    def dxfName(self, /) -> str:
        """
        This function returns a pointer to the DXF name for the class. This string is only required
        to be non-NULL for classes derived from AcDbObject. Other classes may set this via the
        second to the last parameter of the global newAcRxClass() pseudo-constructor. If the
        dxfName string has not been set, then this function will return NULL. WarningAs the const
        qualifier indicates, no attempt should be made to deallocate the string.
        """
    def isDerivedFrom(self, other: PyRx.RxClass, /) -> bool:
        """
        Static method for checking if first (left) class arg is derived from second (right) one.
        """
    def myParent(self, /) -> RxClass:
        """
        This function returns a pointer to the AcRxClass object associated with the base class of
        the class that is represented by the AcRxClass object on which this method is called.
        """
    def name(self, /) -> str:
        """
        This function returns a pointer to a string that is the name of the C++ class represented
        by this AcRxClass object. WarningAs the const qualifier indicates, no attempt should be
        made to deallocate the string.
        """
    def queryX(self, rhs: PyRx.RxClass, /) -> RxObject:
        """
        This function returns the protocol extension object stored with the key pProtocolClass. If
        there is no such object specific to the class represented by this AcRxClass object, then
        the protocol extension object for the parent class is used, or its parent class, or on up
        the hierarchy as far as needed to obtain the protocol extension object sought. If the
        pProtocolClass key is not present in this AcRxClass object nor in any of the base class's
        AcRxClass objects, then this function will return NULL. This function does the real work
        for AcRxObject::queryX() and is invoked from it.
        """

class RxObject:
    def __hash__(self, /) -> int: ...
    def __init__(self) -> None:
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __ne__(self, rhs: PyRx.RxObject, /) -> bool: ...
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def className() -> str: ...
    def comparedTo(self, other: PyRx.RxObject, /) -> Ordering:
        """
        Function usage: This function is intended to allow classes to provide a means to compare
        class objects much the way strcmp() compares character strings. The object pointed to by
        other is compared with this object. The result of the comparison is returned. The possible
        AcRx::Ordering types are: AcRx::kLessThan AcRx::kEqual AcRx::kGreaterThan
        AcRx::kNotOrderable The AcRx::kNotOrderable type is there because C++ classes often cannot
        support object value comparison. Function implementation in derived classes: There are no
        restrictions or expectations on how this function is implemented. Each class will have its
        own requirements for comparison. Default implementation: Simply returns AcRx::kNotOrderable
        since many C++ classes cannot support object value comparison.
        """
    def copyFrom(self, other: PyRx.RxObject, /) -> None:
        """
        Function usage: Copies the contents of other into the messaged object, whenever feasible.
        Function implementation in derived classes: If implemented, this function needs to be able
        to read the data in the object pointed to by other and copy any or all data as appropriate
        into this object. There is no requirement that the object pointed to by other and this
        object be of the same class, but that is the generally assumed condition. Default
        implementation: Because this function must be overridden to have any meaning, a fatal error
        will be caused when calling the default implementation.
        """
    @staticmethod
    def desc() -> RxClass:
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
    def dispose(self, /) -> None: ...
    def implRefCount(self, /) -> int: ...
    def intPtr(self, /) -> int: ...
    def isA(self, /) -> RxClass:
        """
        Function usage: For each class registered with ObjectARX, the implementation of this
        function is to return a pointer to the AcRxClass object for the class of the object in
        which this method is called. For classes not registered with ObjectARX, this method has no
        meaning. Function implementation in derived classes: This function is overridden in all
        derived classes. The AcRx macros declare and define this function, so that the override is
        taken care of as part of using the macros. The implementation of this function is simply to
        return ::desc(). For example. the implementation for AcDbLine would be: return
        AcDbLine::desc(); Default implementation for AcRxObject: { return AcRxObject::desc(); }
        """
    def isDerivedFrom(self, other: PyRx.RxClass, /) -> bool:
        """
        Static method for checking if first (left) class arg is derived from second (right) one.
        """
    def isKindOf(self, rhs: PyRx.RxClass, /) -> bool:
        """
        Returns true if 'this' object is of a member of either the class represented by aClass, or
        a class derived from aClass.
        """
    def isNullObj(self, /) -> bool: ...
    def keepAlive(self, flag: bool, /) -> None: ...
    def queryX(self, rhs: PyRx.RxClass, /) -> RxObject:
        """
        This method searches for a protocol extension object associated with this object. The
        method begins the search by examining the AcRxClass object associated with this object, and
        if no protocol extension object is found, the search continues in the base class of the
        object's class and so on up the inheritance tree for the class. This procedure provides a
        form of protocol extension inheritance. An object's AcRxClass member may be found by using
        the class's isA() method. If the search for a protocol extension object is unsuccessful,
        then NULL is returned.
        """

class stderr:
    def __init__(self, /) -> None: ...
    def __reduce__(self, /) -> Any: ...
    def flush(self, /) -> None: ...
    def write(self, /) -> None: ...

class stdout:
    def __init__(self, /) -> None: ...
    def __reduce__(self, /) -> Any: ...
    def flush(self, /) -> None: ...
    def write(self, /) -> None: ...
