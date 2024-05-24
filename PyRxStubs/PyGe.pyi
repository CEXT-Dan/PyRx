import PyRx
import PyGe
import PyGi
import PyGs
import PyDb
import PyAp
import PyEd
import PyPl
from typing import overload

class AcGeError(object):
    def __add__ (self, value, /) :
      '''Return self+value.'''
    ...
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def __mul__ (self, value, /) :
      '''Return self*value.'''
    ...
    def __rmul__ (self, value, /) :
      '''Return value*self.'''
    ...
    def __sub__ (self, value, /) :
      '''Return self-value.'''
    ...
    def __truediv__ (self, value, /) :
      '''Return self/value.'''
    ...
    def k0Arg1 (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def k0Arg2 (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def k0This (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kArg1InsideThis (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kArg1OnThis (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kArg1TooBig (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kEqualArg1Arg2 (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kEqualArg1Arg3 (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kEqualArg2Arg3 (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kLinearlyDependentArg1Arg2Arg3 (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kOk (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kPerpendicularArg1Arg2 (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class BoundBlock2d(Entity2d):

    @overload
    def __init__ (self, /)-> None : ...
    @overload
    def __init__ (self, pt1: PyGe.Point2d, pt2: PyGe.Point2d)-> None : ...
    @overload
    def __init__ (self, base: PyGe.Point2d, dir1: PyGe.Vector2d, dir2: PyGe.Vector2d)-> None : ...
    def __init__ (self, *args, **kwargs)-> None :
      '''Overloads:
    - None: Any
    - pt1: PyGe.Point2d, pt2: PyGe.Point2d
    - base: PyGe.Point2d, dir1: PyGe.Vector2d, dir2: PyGe.Vector2d
    '''
    ...

    @staticmethod
    def cast (otherObject: PyGe.Entity2d)-> PyGe.BoundBlock2d :
      '''                             '''
    ...

    @staticmethod
    def className ()-> str :
      '''                             '''
    ...
    def contains (self, pt: PyGe.Point2d)-> bool :
      '''                             '''
    ...
    def copy (self)-> PyGe.Entity2d :
      '''                             '''
    ...

    @staticmethod
    def copycast (otherObject: PyGe.Entity2d)-> PyGe.BoundBlock2d :
      '''                             '''
    ...
    def extend (self, pt: PyGe.Point2d)-> None :
      '''                             '''
    ...
    def getBasePoint (self)-> PyGe.Point2d :
      '''                             '''
    ...
    def getDirection1 (self)-> PyGe.Vector2d :
      '''                             '''
    ...
    def getDirection2 (self)-> PyGe.Vector2d :
      '''                             '''
    ...
    def getMaxPoint (self)-> PyGe.Point2d :
      '''                             '''
    ...
    def getMinPoint (self)-> PyGe.Point2d :
      '''                             '''
    ...
    def isBox (self)-> bool :
      '''                             '''
    ...
    def isDisjoint (self, block: PyGe.BoundBlock2d)-> bool :
      '''                             '''
    ...
    def isEqualTo (self, val : PyGe.Entity2d, tol : PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def isKindOf (self, val : PyGe.EntityId)-> bool :
      '''                             '''
    ...
    def isNull (self)-> bool :
      '''                             '''
    ...
    def isOn (self, pt : PyGe.Point2d, tol : PyGe.Tol=default)-> bool :
      '''                             '''
    ...
    def mirror (self, val : PyGe.Line2d)-> None :
      '''                             '''
    ...
    def rotateBy (self, angle : float, pt : PyGe.Point3d=PyGe.Point2d.kOrgin)-> None :
      '''                             '''
    ...
    def scaleBy (self, scaleFactor : float, pt : PyGe.Point2d=PyGe.Point2d.kOrgin)-> None :
      '''                             '''
    ...

    @overload
    def set (self, pt1: PyGe.Point2d, pt2: PyGe.Point2d)-> None : ...
    @overload
    def set (self, base: PyGe.Point2d, dir1: PyGe.Vector2d, dir2: PyGe.Vector2d)-> None : ...
    def set (self, *args, **kwargs)-> None :
      '''Overloads:
    - pt1: PyGe.Point2d, pt2: PyGe.Point2d
    - base: PyGe.Point2d, dir1: PyGe.Vector2d, dir2: PyGe.Vector2d
    '''
    ...
    def setToBox (self, val: bool)-> None :
      '''                             '''
    ...
    def swell (self, val: float)-> None :
      '''                             '''
    ...
    def transformBy (self, val : PyGe.Matrix2d)-> None :
      '''                             '''
    ...
    def translateBy (self, vec : PyGe.Vector2d)-> None :
      '''                             '''
    ...
    def type (self)-> PyGe.EntityId :
      '''                             '''
    ...

class BoundBlock3d(Entity3d):

    @overload
    def __init__ (self, /)-> None : ...
    @overload
    def __init__ (self, base: PyGe.Point3d, dir1: PyGe.Vector3d, dir2: PyGe.Vector3d,dir3: PyGe.Vector3d)-> None : ...
    def __init__ (self, *args, **kwargs)-> None :
      '''Overloads:
    - None: Any
    - base: PyGe.Point3d, dir1: PyGe.Vector3d, dir2: PyGe.Vector3d,dir3: PyGe.Vector3d
    '''
    ...

    @staticmethod
    def cast (otherObject: PyGe.Entity3d)-> PyGe.BoundBlock3d :
      '''                             '''
    ...

    @staticmethod
    def className ()-> str :
      '''                             '''
    ...
    def contains (self, pt: PyGe.Point3d)-> bool :
      '''                             '''
    ...
    def copy (self)-> PyGe.Entity3d :
      '''Returns a pointer to a copy of this entity. This copy is created using the new and it is the responsibility of the caller to delete it.'''
    ...

    @staticmethod
    def copycast (otherObject: PyGe.Entity3d)-> PyGe.BoundBlock3d :
      '''                             '''
    ...
    def extend (self, pt: PyGe.Point3d)-> None :
      '''                             '''
    ...
    def getBasePoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def getDirection1 (self)-> PyGe.Vector3d :
      '''                             '''
    ...
    def getDirection3 (self)-> PyGe.Vector3d :
      '''                             '''
    ...
    def getMaxPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def getMinPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def isBox (self)-> bool :
      '''                             '''
    ...
    def isDisjoint (self, block: PyGe.BoundBlock3d)-> bool :
      '''                             '''
    ...
    def isEqualTo (self, val : PyGe.Entity3d, tol : PyGe.Tol=None)-> bool :
      '''Determines if two entities are equal to each other. Two entities are considered to be equal only if they are of the same type and they represent the same 3D point set. For instance, if the two entities are of types AcGeCircArc3d and AcGeEllipArc3d then they are not considered equal even if the ellipse is completely coincident with the circle. Also, two curves are not considered equal unless they have the same parameterization. For instance, two infinite coincident lines are not considered equal if they have different scaling in their parameterization. '''
    ...
    def isKindOf (self, val : PyGe.EntityId)-> bool :
      '''                             '''
    ...
    def isNull (self)-> bool :
      '''                             '''
    ...
    def isOn (self, pt : PyGe.Point3d, tol : PyGe.Tol=default)-> bool :
      '''Returns Adesk::kTrue if pnt lies on entity; otherwise, returns Adesk::kFalse.'''
    ...
    def mirror (self, val : PyGe.Plane)-> None :
      '''Transforms the entity by mirroring it across the input plane.'''
    ...
    def rotateBy (self, angle : float, vec : PyGe.Vector3d, pt : PyGe.Point3d = 'origin')-> None :
      '''Rotates the entity by the input angle about the line defined by the input point and vector.'''
    ...
    def scaleBy (self, scaleFactor : float, pt : PyGe.Point3d = 'origin')-> None :
      '''Scales the entity about the input point by the input scale factor. Input scale factor must be greater than 0.'''
    ...

    @overload
    def set (self, pt1: PyGe.Point3d, pt2: PyGe.Point3d)-> None : ...
    @overload
    def set (self, base: PyGe.Point3d, dir1: PyGe.Vector3d, dir2: PyGe.Vector3d,dir3: PyGe.Vector3d)-> None : ...
    def set (self, *args, **kwargs)-> None :
      '''Overloads:
    - pt1: PyGe.Point3d, pt2: PyGe.Point3d
    - base: PyGe.Point3d, dir1: PyGe.Vector3d, dir2: PyGe.Vector3d,dir3: PyGe.Vector3d
    '''
    ...
    def setToBox (self, val: bool)-> None :
      '''                             '''
    ...
    def swell (self, val: float)-> None :
      '''                             '''
    ...
    def transformBy (self, val : PyGe.Matrix3d)-> None :
      '''Transforms the entity by applying the input matrix.'''
    ...
    def translateBy (self, vec : PyGe.Vector3d)-> None :
      '''Translates the entity by the input vector.'''
    ...
    def type (self)-> PyGe.EntityId :
      '''Returns the type of the entity.'''
    ...

class BoundedPlane(PlanarEnt):
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (Point3d)arg2, (Vector3d)arg3, (Vector3d)arg4) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePoint3d,class AcGeVector3d,class AcGeVector3d)

__init__( (object)arg1, (Point3d)arg2, (Point3d)arg3, (Point3d)arg4) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePoint3d,class AcGePoint3d,class AcGePoint3d)'''
    ...
    def cast (self, *args, **kwargs)-> PyGe.BoundedPlane :
      '''cast( (Entity3d)arg1) -> BoundedPlane :

    C++ signature :
        class PyGeBoundedPlane cast(class PyGeEntity3d)'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def closestPointTo (self, *args, **kwargs)-> PyGe.Point3d :
      '''closestPointTo( (Surface)arg1, (Point3d)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d closestPointTo(class PyGeSurface {lvalue},class AcGePoint3d)

closestPointTo( (Surface)arg1, (Point3d)arg2, (Tol)arg3) -> Point3d :

    C++ signature :
        class AcGePoint3d closestPointTo(class PyGeSurface {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def closestPointToLinearEnt (self, *args, **kwargs)-> tuple :
      '''closestPointToLinearEnt( (PlanarEnt)arg1, (LinearEnt3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointToLinearEnt(class PyGePlanarEnt {lvalue},class PyGeLinearEnt3d)

closestPointToLinearEnt( (PlanarEnt)arg1, (LinearEnt3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointToLinearEnt(class PyGePlanarEnt {lvalue},class PyGeLinearEnt3d,class AcGeTol)'''
    ...
    def closestPointToPlanarEnt (self, other: PyGe.LinearEnt3d|PyGe.PlanarEnt, tol: PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def copy (self)-> PyGe.Entity3d :
      '''Returns a pointer to a copy of this entity. This copy is created using the new and it is the responsibility of the caller to delete it.'''
    ...
    def copycast (self, *args, **kwargs)-> PyGe.BoundedPlane :
      '''copycast( (Entity3d)arg1) -> BoundedPlane :

    C++ signature :
        class PyGeBoundedPlane copycast(class PyGeEntity3d)'''
    ...
    def distanceTo (self, *args, **kwargs)-> float :
      '''distanceTo( (Surface)arg1, (Point3d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeSurface {lvalue},class AcGePoint3d)

distanceTo( (Surface)arg1, (Point3d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeSurface {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def evalPoint (self, *args, **kwargs)-> PyGe.Point3d :
      '''evalPoint( (Surface)arg1, (Point2d)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d evalPoint(class PyGeSurface {lvalue},class AcGePoint2d)

evalPoint( (Surface)arg1, (Point2d)arg2, (int)arg3, (list)arg4) -> Point3d :

    C++ signature :
        class AcGePoint3d evalPoint(class PyGeSurface {lvalue},class AcGePoint2d,int,class boost::python::list {lvalue})

evalPoint( (Surface)arg1, (Point2d)arg2, (int)arg3, (list)arg4, (Vector3d)arg5) -> Point3d :

    C++ signature :
        class AcGePoint3d evalPoint(class PyGeSurface {lvalue},class AcGePoint2d,int,class boost::python::list {lvalue},class AcGeVector3d {lvalue})'''
    ...
    def getCoefficients (self)-> tuple :
      '''                             '''
    ...
    def getCoordSystem (self)-> tuple :
      '''                             '''
    ...
    def intersectWith (self, *args, **kwargs)-> tuple :
      '''intersectWith( (BoundedPlane)arg1, (LinearEnt3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeBoundedPlane {lvalue},class PyGeLinearEnt3d)

intersectWith( (BoundedPlane)arg1, (LinearEnt3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeBoundedPlane {lvalue},class PyGeLinearEnt3d,class AcGeTol)

intersectWith( (BoundedPlane)arg1, (Plane)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeBoundedPlane {lvalue},class PyGePlane)

intersectWith( (BoundedPlane)arg1, (Plane)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeBoundedPlane {lvalue},class PyGePlane,class AcGeTol)

intersectWith( (BoundedPlane)arg1, (BoundedPlane)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeBoundedPlane {lvalue},class PyGeBoundedPlane)

intersectWith( (BoundedPlane)arg1, (BoundedPlane)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeBoundedPlane {lvalue},class PyGeBoundedPlane,class AcGeTol)'''
    ...
    def isClosedInU (self, *args, **kwargs)-> bool :
      '''isClosedInU( (Surface)arg1) -> bool :

    C++ signature :
        bool isClosedInU(class PyGeSurface {lvalue})

isClosedInU( (Surface)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosedInU(class PyGeSurface {lvalue},class AcGeTol)'''
    ...
    def isClosedInV (self, *args, **kwargs)-> bool :
      '''isClosedInV( (Surface)arg1) -> bool :

    C++ signature :
        bool isClosedInV(class PyGeSurface {lvalue})

isClosedInV( (Surface)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosedInV(class PyGeSurface {lvalue},class AcGeTol)'''
    ...
    def isCoplanarTo (self, other: PyGe.PlanarEnt, tol: PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def isEqualTo (self, val : PyGe.Entity3d, tol : PyGe.Tol=None)-> bool :
      '''Determines if two entities are equal to each other. Two entities are considered to be equal only if they are of the same type and they represent the same 3D point set. For instance, if the two entities are of types AcGeCircArc3d and AcGeEllipArc3d then they are not considered equal even if the ellipse is completely coincident with the circle. Also, two curves are not considered equal unless they have the same parameterization. For instance, two infinite coincident lines are not considered equal if they have different scaling in their parameterization. '''
    ...
    def isKindOf (self, val : PyGe.EntityId)-> bool :
      '''                             '''
    ...
    def isNormalReversed (self, *args, **kwargs)-> bool :
      '''isNormalReversed( (Surface)arg1) -> bool :

    C++ signature :
        bool isNormalReversed(class PyGeSurface {lvalue})'''
    ...
    def isNull (self)-> bool :
      '''                             '''
    ...
    def isOn (self, *args, **kwargs)-> bool :
      '''isOn( (Surface)arg1, (Point3d)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeSurface {lvalue},class AcGePoint3d)

isOn( (Surface)arg1, (Point3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeSurface {lvalue},class AcGePoint3d,class AcGeTol)

isOn( (Surface)arg1, (Point3d)arg2, (Point2d)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeSurface {lvalue},class AcGePoint3d,class AcGePoint2d {lvalue})

isOn( (Surface)arg1, (Point3d)arg2, (Point2d)arg3, (Tol)arg4) -> bool :

    C++ signature :
        bool isOn(class PyGeSurface {lvalue},class AcGePoint3d,class AcGePoint2d {lvalue},class AcGeTol)'''
    ...
    def isParallelTo (self, other: PyGe.LinearEnt3d|PyGe.PlanarEnt, tol: PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def isPerpendicularTo (self, other: PyGe.LinearEnt3d|PyGe.PlanarEnt, tol: PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def mirror (self, val : PyGe.Plane)-> None :
      '''Transforms the entity by mirroring it across the input plane.'''
    ...
    def normal (self)-> PyGe.Vector3d :
      '''                             '''
    ...
    def paramOf (self, *args, **kwargs)-> PyGe.Point2d :
      '''paramOf( (Surface)arg1, (Point3d)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d paramOf(class PyGeSurface {lvalue},class AcGePoint3d)

paramOf( (Surface)arg1, (Point3d)arg2, (Tol)arg3) -> Point2d :

    C++ signature :
        class AcGePoint2d paramOf(class PyGeSurface {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def pointOnPlane (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def reverseNormal (self, *args, **kwargs)-> None :
      '''reverseNormal( (Surface)arg1) -> None :

    C++ signature :
        void reverseNormal(class PyGeSurface {lvalue})'''
    ...
    def rotateBy (self, angle : float, vec : PyGe.Vector3d, pt : PyGe.Point3d = 'origin')-> None :
      '''Rotates the entity by the input angle about the line defined by the input point and vector.'''
    ...
    def scaleBy (self, scaleFactor : float, pt : PyGe.Point3d = 'origin')-> None :
      '''Scales the entity about the input point by the input scale factor. Input scale factor must be greater than 0.'''
    ...
    def set (self, *args, **kwargs)-> None :
      '''set( (BoundedPlane)arg1, (Point3d)arg2, (Vector3d)arg3, (Vector3d)arg4) -> None :

    C++ signature :
        void set(class PyGeBoundedPlane {lvalue},class AcGePoint3d,class AcGeVector3d,class AcGeVector3d)

set( (BoundedPlane)arg1, (Point3d)arg2, (Point3d)arg3, (Point3d)arg4) -> None :

    C++ signature :
        void set(class PyGeBoundedPlane {lvalue},class AcGePoint3d,class AcGePoint3d,class AcGePoint3d)'''
    ...
    def transformBy (self, val : PyGe.Matrix3d)-> None :
      '''Transforms the entity by applying the input matrix.'''
    ...
    def translateBy (self, vec : PyGe.Vector3d)-> None :
      '''Translates the entity by the input vector.'''
    ...
    def type (self)-> PyGe.EntityId :
      '''Returns the type of the entity.'''
    ...

class CircArc2d(Curve2d):
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (Point2d)arg2, (float)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePoint2d,double)

__init__( (object)arg1, (Point2d)arg2, (float)arg3, (float)arg4, (float)arg5) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePoint2d,double,double,double)

__init__( (object)arg1, (Point2d)arg2, (float)arg3, (float)arg4, (float)arg5, (Vector2d)arg6, (bool)arg7) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePoint2d,double,double,double,class AcGeVector2d,bool)

__init__( (object)arg1, (Point2d)arg2, (Point2d)arg3, (Point2d)arg4) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePoint2d,class AcGePoint2d,class AcGePoint2d)

__init__( (object)arg1, (Point2d)arg2, (Point2d)arg3, (float)arg4, (bool)arg5) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePoint2d,class AcGePoint2d,double,bool)'''
    ...
    def area (self, startParam : float, endParam : float, tol : float = None)-> float :
      '''                             '''
    ...
    def boundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock2d :
      '''                             '''
    ...
    def cast (self, *args, **kwargs)-> PyGe.CircArc2d :
      '''cast( (Entity2d)arg1) -> CircArc2d :

    C++ signature :
        class PyGeCircArc2d cast(class PyGeEntity2d)'''
    ...
    def center (self, *args, **kwargs)-> PyGe.Point2d :
      '''center( (CircArc2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d center(class PyGeCircArc2d {lvalue})'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def closestPointTo (self, other : PyGe.Point2d | PyGe.Curve2d, tol : PyGe.Tol=None)-> PyGe.Point2d :
      '''                             '''
    ...
    def copy (self)-> PyGe.Entity2d :
      '''                             '''
    ...
    def copycast (self, *args, **kwargs)-> PyGe.CircArc2d :
      '''copycast( (Entity2d)arg1) -> CircArc2d :

    C++ signature :
        class PyGeCircArc2d copycast(class PyGeEntity2d)'''
    ...
    def distanceTo (self, pt : PyGe.Point2d | PyGe.Curve2d, tol : PyGe.Tol=None)-> float :
      '''                             '''
    ...
    def endAng (self, *args, **kwargs)-> float :
      '''endAng( (CircArc2d)arg1) -> float :

    C++ signature :
        double endAng(class PyGeCircArc2d {lvalue})'''
    ...
    def endPoint (self, *args, **kwargs)-> PyGe.Point2d :
      '''endPoint( (CircArc2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d endPoint(class PyGeCircArc2d {lvalue})'''
    ...
    def evalPoint (self, param : float, numDeriv : int = 1)-> PyGe.Point2d :
      '''                             '''
    ...
    def explode (self, val : PyGe.Interval = None)-> list :
      '''                             '''
    ...
    def getClosestPointTo (self, other : PyGe.Point2d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve2d :
      '''                             '''
    ...
    def getClosestPointsTo (self, other : PyGe.Curve2d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def getEndPoint (self)-> PyGe.Point2d :
      '''                             '''
    ...
    def getInterval (self)-> PyGe.Interval :
      '''                             '''
    ...
    def getNormalPoint (self, pnt : PyGe.Point2d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve2d :
      '''                             '''
    ...

    @overload
    def getSamplePoints (self, numSample: int)-> list : ...
    @overload
    def getSamplePoints (self, fromParam: float, toParam: float, approxEps: float)-> list : ...
    def getSamplePoints (self, *args, **kwargs)-> list :
      '''Overloads:
    - numSample: int
    - fromParam: float, toParam: float, approxEps: float
    '''
    ...
    def getSplitCurves (self, param : float)-> tuple :
      '''                             '''
    ...
    def getStartPoint (self)-> PyGe.Point2d :
      '''                             '''
    ...
    def getTrimmedOffset (self, dist : float, extensionType : PyGe.OffsetCrvExtType, tol : PyGe.Tol=None)-> list :
      '''                             '''
    ...
    def hasEndPoint (self)-> bool :
      '''                             '''
    ...
    def hasStartPoint (self)-> bool :
      '''                             '''
    ...
    def intersectWith (self, *args, **kwargs)-> tuple :
      '''intersectWith( (CircArc2d)arg1, (LinearEnt2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeCircArc2d {lvalue},class PyGeLinearEnt2d)

intersectWith( (CircArc2d)arg1, (LinearEnt2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeCircArc2d {lvalue},class PyGeLinearEnt2d,class AcGeTol)

intersectWith( (CircArc2d)arg1, (CircArc2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeCircArc2d {lvalue},class PyGeCircArc2d)

intersectWith( (CircArc2d)arg1, (CircArc2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeCircArc2d {lvalue},class PyGeCircArc2d,class AcGeTol)'''
    ...
    def isClockWise (self, *args, **kwargs)-> bool :
      '''isClockWise( (CircArc2d)arg1) -> bool :

    C++ signature :
        bool isClockWise(class PyGeCircArc2d {lvalue})'''
    ...
    def isClosed (self, tol : PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def isDegenerate (self, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isEqualTo (self, val : PyGe.Entity2d, tol : PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def isInside (self, *args, **kwargs)-> bool :
      '''isInside( (CircArc2d)arg1, (Point2d)arg2) -> bool :

    C++ signature :
        bool isInside(class PyGeCircArc2d {lvalue},class AcGePoint2d)

isInside( (CircArc2d)arg1, (Point2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isInside(class PyGeCircArc2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def isKindOf (self, val : PyGe.EntityId)-> bool :
      '''                             '''
    ...
    def isLinear (self, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isNull (self)-> bool :
      '''                             '''
    ...
    def isOn (self, pt : float | PyGe.Point2d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isPeriodic (self)-> tuple :
      '''                             '''
    ...
    def length (self, frm : float, to : float, tol : float = None)-> float :
      '''                             '''
    ...
    def mirror (self, val : PyGe.Line2d)-> None :
      '''                             '''
    ...
    def orthoBoundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock2d :
      '''                             '''
    ...
    def paramAtLength (self, datumParam: float, length: float, posParamDir: bool=True, tol: float=None)-> float :
      '''                             '''
    ...
    def paramOf (self, pt : PyGe.Point2d, tol : PyGe.Tol=None)-> float :
      '''                             '''
    ...
    def radius (self, *args, **kwargs)-> float :
      '''radius( (CircArc2d)arg1) -> float :

    C++ signature :
        double radius(class PyGeCircArc2d {lvalue})'''
    ...
    def refVec (self, *args, **kwargs)-> PyGe.Vector2d :
      '''refVec( (CircArc2d)arg1) -> Vector2d :

    C++ signature :
        class AcGeVector2d refVec(class PyGeCircArc2d {lvalue})'''
    ...
    def reverseParam (self)-> None :
      '''                             '''
    ...
    def rotateBy (self, angle : float, pt : PyGe.Point3d=PyGe.Point2d.kOrgin)-> None :
      '''                             '''
    ...
    def scaleBy (self, scaleFactor : float, pt : PyGe.Point2d=PyGe.Point2d.kOrgin)-> None :
      '''                             '''
    ...
    def set (self, *args, **kwargs)-> None :
      '''set( (CircArc2d)arg1, (Point2d)arg2, (float)arg3) -> None :

    C++ signature :
        void set(class PyGeCircArc2d {lvalue},class AcGePoint2d,double)

set( (CircArc2d)arg1, (Point2d)arg2, (float)arg3, (float)arg4, (float)arg5, (Vector2d)arg6, (bool)arg7) -> None :

    C++ signature :
        void set(class PyGeCircArc2d {lvalue},class AcGePoint2d,double,double,double,class AcGeVector2d,bool)

set( (CircArc2d)arg1, (Point2d)arg2, (Point2d)arg3, (Point2d)arg4) -> None :

    C++ signature :
        void set(class PyGeCircArc2d {lvalue},class AcGePoint2d,class AcGePoint2d,class AcGePoint2d)

set( (CircArc2d)arg1, (Point2d)arg2, (Point2d)arg3, (float)arg4, (bool)arg5) -> None :

    C++ signature :
        void set(class PyGeCircArc2d {lvalue},class AcGePoint2d,class AcGePoint2d,double,bool)

set( (CircArc2d)arg1, (Curve2d)arg2, (Curve2d)arg3, (float)arg4) -> None :

    C++ signature :
        void set(class PyGeCircArc2d {lvalue},class PyGeCurve2d,class PyGeCurve2d,double)

set( (CircArc2d)arg1, (Curve2d)arg2, (Curve2d)arg3, (Curve2d)arg4) -> None :

    C++ signature :
        void set(class PyGeCircArc2d {lvalue},class PyGeCurve2d,class PyGeCurve2d,class PyGeCurve2d)'''
    ...
    def setAngles (self, *args, **kwargs)-> None :
      '''setAngles( (CircArc2d)arg1, (float)arg2, (float)arg3) -> None :

    C++ signature :
        void setAngles(class PyGeCircArc2d {lvalue},double,double)'''
    ...
    def setCenter (self, *args, **kwargs)-> None :
      '''setCenter( (CircArc2d)arg1, (Point2d)arg2) -> None :

    C++ signature :
        void setCenter(class PyGeCircArc2d {lvalue},class AcGePoint2d)'''
    ...
    def setInterval (self, val : PyGe.Interval = None)-> None :
      '''                             '''
    ...
    def setRadius (self, *args, **kwargs)-> None :
      '''setRadius( (CircArc2d)arg1, (float)arg2) -> None :

    C++ signature :
        void setRadius(class PyGeCircArc2d {lvalue},double)'''
    ...
    def setRefVec (self, *args, **kwargs)-> None :
      '''setRefVec( (CircArc2d)arg1, (Vector2d)arg2) -> None :

    C++ signature :
        void setRefVec(class PyGeCircArc2d {lvalue},class AcGeVector2d)'''
    ...
    def setToComplement (self, *args, **kwargs)-> None :
      '''setToComplement( (CircArc2d)arg1) -> None :

    C++ signature :
        void setToComplement(class PyGeCircArc2d {lvalue})'''
    ...
    def startAng (self, *args, **kwargs)-> float :
      '''startAng( (CircArc2d)arg1) -> float :

    C++ signature :
        double startAng(class PyGeCircArc2d {lvalue})'''
    ...
    def startPoint (self, *args, **kwargs)-> PyGe.Point2d :
      '''startPoint( (CircArc2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d startPoint(class PyGeCircArc2d {lvalue})'''
    ...
    def tangent (self, *args, **kwargs)-> tuple :
      '''tangent( (CircArc2d)arg1, (Point2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple tangent(class PyGeCircArc2d {lvalue},class AcGePoint2d)

tangent( (CircArc2d)arg1, (Point2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple tangent(class PyGeCircArc2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def transformBy (self, val : PyGe.Matrix2d)-> None :
      '''                             '''
    ...
    def translateBy (self, vec : PyGe.Vector2d)-> None :
      '''                             '''
    ...
    def type (self)-> PyGe.EntityId :
      '''                             '''
    ...

class CircArc3d(Curve3d):

    @overload
    def __init__ (self, /)-> None : ...
    @overload
    def __init__ (self, cent: PyGe.Point3d, nrm: PyGe.Vector3d, radius: float)-> None : ...
    @overload
    def __init__ (self, cent: PyGe.Point3d, nrm: PyGe.Vector3d, refVec: PyGe.Vector3d, radius: float, startAngle: float, endAngle: float)-> None : ...
    @overload
    def __init__ (self, startPoint: PyGe.Point3d, pnt: PyGe.Point3d, endPoint: PyGe.Point3d)-> None : ...
    def __init__ (self, *args, **kwargs)-> None :
      '''Overloads:
    - None: Any
    - cent: PyGe.Point3d, nrm: PyGe.Vector3d, radius: float
    - cent: PyGe.Point3d, nrm: PyGe.Vector3d, refVec: PyGe.Vector3d, radius: float, startAngle: float, endAngle: float
    - startPoint: PyGe.Point3d, pnt: PyGe.Point3d, endPoint: PyGe.Point3d
    '''
    ...
    def area (self, startParam : float, endParam : float, tol : float = None)-> float :
      '''Returns the area of the interval of the curve defined by startParam and endParam. Returns Adesk::kTrue if area was successfully computed to within the specified tolerance. If the curve is not planar, then the area cannot be calculated and a value of Adesk::kFalse is returned. If the points at startParam and endParam are the same, then this function returns the area of the closed curve. If the points are different, then this function connects the two points with a line segment and return the signed area between the curve and the line segment. If the line segment does not intersect the curve at any points between startParam and endParam, then the returned area is positive. If the line segment intersects the curves at any points between startParam and endParam, then the returned area is the sum of the sub-areas created by the intersection of the line segment with the curve. Each sub-area has a positive or negative area, depending on whether the curve lies above or below the line segment. The total area returned by this function can therefore be positive, negative, or 0. '''
    ...
    def boundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock3d :
      '''Returns the bounding box of the curve. The sides of the returned box are parallel to the coordinate axes. '''
    ...

    @staticmethod
    def cast (otherObject: PyGe.Entity3d)-> PyGe.CircArc3d :
      '''                             '''
    ...
    def center (self)-> PyGe.Point3d :
      '''                             '''
    ...

    @staticmethod
    def className ()-> str :
      '''                             '''
    ...
    def closestPointTo (self, other : PyGe.Point3d | PyGe.Curve3d, tol : PyGe.Tol=None)-> PyGe.Point3d :
      '''Finds the closest point on this curve to the input point. This function is the same as closestPointTo(), except that the closest point is returned as an AcGePointOnCurve3d object.'''
    ...
    def closestPointToPlane (self, plane: PyGe.PlanarEnt, tol: PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def copy (self)-> PyGe.Entity3d :
      '''Returns a pointer to a copy of this entity. This copy is created using the new and it is the responsibility of the caller to delete it.'''
    ...

    @staticmethod
    def copycast (otherObject: PyGe.Entity3d)-> PyGe.CircArc3d :
      '''                             '''
    ...
    def distanceTo (self, pt : PyGe.Point3d | PyGe.Curve3d, tol : PyGe.Tol=None)-> float :
      '''Returns the distance between the input point and the closest point on this curve.'''
    ...
    def endAng (self)-> float :
      '''                             '''
    ...
    def endPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def evalPoint (self, param : float, numDeriv : int = 1)-> PyGe.Point3d :
      '''Returns the point on the curve that corresponds to the input parameter value. Also returns the number of derivative vectors that are specified in numDeriv. The numDeriv parameter should not be set larger than 2.'''
    ...
    def explode (self, val : PyGe.Interval = None)-> list :
      '''Explodes the curve into its individual components. If the curve is a composite curve, then explodedCurves contains the list of component curves of the composite. If the curve is a spline, then it is exploded at the points of C1 discontinuity and explodedCurves contains a copy of each continuous sub-curve. This function returns Adesk::kTrue if the curve was exploded (that is, the curve was a composite or a discontinuous spline) and Adesk::kFalse otherwise. The number of entries returned in newExplodedCurves is always the same as the number of entries in explodedCurves. Each flag in newExplodedCurves indicates whether the corresponding curve in explodedCurves was created with the new operator. If the flag is 1, then it is the responsibility of the caller to delete the curve. If the flag is 0, the curve is deleted by gelib and the caller should not attempt to delete it. If no intrvl parameter is supplied, then the interval is taken to be the entire curve. '''
    ...
    def getClosestPointTo (self, other : PyGe.Point3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''Finds the closest point on this curve to the input point. This function is the same as closestPointTo(), except that the closest point is returned as an AcGePointOnCurve3d object.'''
    ...
    def getClosestPointsTo (self, other : PyGe.Curve3d, tol : PyGe.Tol=None)-> tuple :
      '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
    ...
    def getEndPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def getInterval (self)-> PyGe.Interval :
      '''Returns the parametric range of the curve. The function evalPoint(double) always returns a point on this curve when called with a value within the returned interval.'''
    ...
    def getNormalPoint (self, pnt : PyGe.Point3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''Finds the point on the input curve whose normal passes through the input point. The returned point lies on a plane that also contains the input point and is perpendicular to the curve tangent at that point. The returned point is therefore at a local minimum or a local maximum from the input point. The curve does not need to be planar. If the curve is planar, the input point does not need to lie in the plane of the curve. On input, the second parameter is assumed to contain the parameter value of an initial guess. If there is more than one normal point on the curve, the returned point will be the one whose parameter value is closest to the input parameter value.'''
    ...
    def getPlane (self)-> PyGe.Plane :
      '''                             '''
    ...
    def getProjClosestPointTo (self, pt : PyGe.Point3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
    ...
    def getProjClosestPointsTo (self, pt : PyGe.Curve3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> tuple :
      '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
    ...

    @overload
    def getSamplePoints (self, numSample: int)-> tuple : ...
    @overload
    def getSamplePoints (self, fromParam: float, toParam: float, approxEps: float)-> tuple : ...
    def getSamplePoints (self, *args, **kwargs)-> tuple :
      '''Overloads:
    - numSample: int
    - fromParam: float, toParam: float, approxEps: float
    
	-Returns the specified number of points on the curve. The points are equally spaced by parameter value. So if the interval of the curve [0,1] and numSample is 5, the parameter values of the returned points are 0, 0.25, 0.5, 0.75, and 1.-'''
    ...
    def getSplitCurves (self, param : float)-> tuple :
      '''Returns two segments which are obtained by splitting the curve at the input parameter value. If the specified parameter value does not lie within the parametric interval of the curve or if it corresponds to the start point or endpoint of the curve, then piece1 and piece2 are set to null. This function uses the new to create the curve segments whose addresses are returned in piece1 and piece2. It is the responsibility of the caller to delete these objects. '''
    ...
    def getStartPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def getTrimmedOffset (self, dist : float, planeNormal : PyGe.Vector3d, extensionType : PyGe.OffsetCrvExtType, tol : PyGe.Tol=None)-> list :
      '''Returns one or more offset curves that represent the trimmed offset of the curve. The curve must be planar and planeNormal must be perpendicular to the plane of the curve. The positive direction of offset at a point on the curve is taken to be the cross product of planeNormal with the tangent vector at that point. The curve may be offset in either of two directions by specifying a positive or negative offset distance; planeNormal determines which direction is the positive direction of offset. The returned offset curves are trimmed so that they do not contain any points of self-intersection. Each curve that is returned in offsetCurveList is created with the new and it is the responsibility of the caller to delete these curves. Each curve that is returned in offsetCurveList is a connected curve and may be a composite curve if the offset curve had to be trimmed to remove self-intersecting loops. offsetCurveList only contains more than one curve if the offset operation produces multiple curves which are not connected. If the original curve contains points of C1 discontinuity and the direction of offset causes the offset curve to be disjoint (for instance, if the original curve is a composite curve that is a rectangle and the direction of offset is to the outside of the rectangle), then the offset curve is closed with an arc or a line segment, or the curves are simply extended depending on the value of extensionType.'''
    ...
    def hasEndPoint (self)-> bool :
      '''Returns Adesk::kTrue if curve has an endpoint. A return value of Adesk::kFalse means that the parametric interval of the curve does not have an upper bound. The endPnt parameter contains meaningful data only if this function returns a value of Adesk::kTrue.'''
    ...
    def hasStartPoint (self)-> bool :
      '''Returns Adesk::kTrue if curve has a start point. A return value of Adesk::kFalse means that the parametric interval of the curve does not have a lower bound. The startPnt parameter contains meaningful data only if this function returns a value of Adesk::kTrue.'''
    ...
    def intersectWith (self, other: PyGe.CircArc3d|PyGe.LinearEnt3d|PyGe.PlanarEnt, tol: PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isClosed (self, tol : PyGe.Tol=None)-> bool :
      '''Determines if start point and endpoint of curve are the same.'''
    ...
    def isCoplanarWith (self, curve : PyGe.Curve3d, tol : PyGe.Tol=None)-> tuple :
      '''Returns Adesk::kTrue if both curve are planar and lie in the same plane. The plane parameter is only valid if this function returns a value of Adesk::kTrue.'''
    ...
    def isDegenerate (self, tol : PyGe.Tol=None)-> tuple :
      '''Determines if the curve is degenerate and if so returns the type of entity which the curve degenerates into. For example, if the curve is a circle with a radius of 0 then degenerateType is set to AcGe::kPoint3d. If the curve is an ellipse with a minor radius of 0 and a major radius of 1, then degenerateType is set to AcGe::kLineSeg3d. The degenerateType parameter is only set to something meaningful when this function returns a value of Adesk::kTrue.'''
    ...
    def isEqualTo (self, val : PyGe.Entity3d, tol : PyGe.Tol=None)-> bool :
      '''Determines if two entities are equal to each other. Two entities are considered to be equal only if they are of the same type and they represent the same 3D point set. For instance, if the two entities are of types AcGeCircArc3d and AcGeEllipArc3d then they are not considered equal even if the ellipse is completely coincident with the circle. Also, two curves are not considered equal unless they have the same parameterization. For instance, two infinite coincident lines are not considered equal if they have different scaling in their parameterization. '''
    ...
    def isInside (self, pt: PyGe.Point3d, tol: PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def isKindOf (self, val : PyGe.EntityId)-> bool :
      '''                             '''
    ...
    def isLinear (self, tol : PyGe.Tol=None)-> tuple :
      '''Determines if curve is linear. This function returns an infinite line even if the curve is not infinite. The line parameter contains meaningful data only if this function returns a value of Adesk::kTrue.'''
    ...
    def isNull (self)-> bool :
      '''                             '''
    ...
    def isOn (self, pt : float | PyGe.Point3d, tol : PyGe.Tol=None)-> tuple :
      '''Determines if input parameter value is within valid parametric range of curve.'''
    ...
    def isPeriodic (self)-> tuple :
      '''Determines if the curve is periodic. The curve is periodic if and only if it is closed and the two points evalPoint(t) and evalPoint(t+period) are always the same point for all values of t.'''
    ...
    def isPlanar (self, tol : PyGe.Tol=None)-> tuple :
      '''Determines if curve is planar. If the curve is a line, then this function returns an arbitrary plane that contains the line. The plane parameter contains meaningful data only if this function returns a value of Adesk::kTrue. '''
    ...
    def length (self, frm : float, to : float, tol : float = None)-> float :
      '''Returns the arc length of the curve between the two parameter values.'''
    ...
    def mirror (self, val : PyGe.Plane)-> None :
      '''Transforms the entity by mirroring it across the input plane.'''
    ...
    def normal (self)-> PyGe.Vector3d :
      '''                             '''
    ...
    def orthoBoundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock3d :
      '''Returns the bounding box of the curve. The sides of the returned box are parallel to the coordinate axes.'''
    ...
    def orthoProject (self, projectionPlane : PyGe.Plane, tol : PyGe.Tol=None)-> PyGe.Entity3d :
      '''Returns the entity that is the orthogonal projection of the curve onto the projection plane. The returned entity may not be of the same type as the original curve and may not even be a curve (for instance, a line projects into a point if it is orthogonal to the projection plane). The returned entity is created with the new and it is the responsibility of the caller to delete it.'''
    ...
    def paramAtLength (self, datumParam : float, length : float, posParamDir : bool=True, tol : float = default)-> float :
      '''Returns the parameter value of the point whose arc length distance (from the point with parameter value datumParam) is the input length. In other words, ift = paramAtLength (datumParam, len, posParamDir, tol) then length (t, datumParam, tol) is (approximately) equal to len. If posParamDir is set to Adesk::kTrue, then the returned parameter value is greater than datumParam. Otherwise it will be less than datumParam. '''
    ...
    def paramOf (self, pt : PyGe.Point3d, tol : PyGe.Tol=None)-> float :
      '''Returns the parameter value of pnt. This function assumes that pnt lies on the curve and does not verify this. If pnt does not lie on the curve, this function will return unpredictable results. If it is not known whether pnt lies on the curve, the user should not call this function but should instead call AcGeCurve3d::isOn (pnt, param, tol). '''
    ...
    def projClosestPointTo (self, pt : PyGe.Point3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.Point3d :
      '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
    ...
    def projClosestPointsTo (self, pt : PyGe.Curve3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> tuple :
      '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
    ...
    def projIntersectWith (self, other: PyGe.LinearEnt3d, projDir: PyGe.Vector3d, tol: PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def project (self, projectionPlane : PyGe.Plane, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.Entity3d :
      '''Returns the entity that is the projection of the curve onto the projection plane in the specified direction. The projectDirection vector must not be parallel to the projection plane. The returned entity may not be of the same type as the original curve and may not even be a curve (for instance, a line projects into a point if it is parallel to projectDirection). The returned entity is created with the new and it is the responsibility of the caller to delete it.'''
    ...
    def radius (self)-> float :
      '''                             '''
    ...
    def refVec (self)-> PyGe.Vector3d :
      '''                             '''
    ...
    def reverseParam (self)-> None :
      '''Reverses the parametric direction of the curve. The point set of the curve is unchanged, but the direction of the curve is reversed.'''
    ...
    def rotateBy (self, angle : float, vec : PyGe.Vector3d, pt : PyGe.Point3d = 'origin')-> None :
      '''Rotates the entity by the input angle about the line defined by the input point and vector.'''
    ...
    def scaleBy (self, scaleFactor : float, pt : PyGe.Point3d = 'origin')-> None :
      '''Scales the entity about the input point by the input scale factor. Input scale factor must be greater than 0.'''
    ...

    @overload
    def set (self, cent: PyGe.Point3d, nrm: PyGe.Vector3d, radius: float)-> None : ...
    @overload
    def set (self, cent: PyGe.Point3d, nrm: PyGe.Vector3d, refVec: PyGe.Vector3d, radius: float, startAngle: float, endAngle: float)-> None : ...
    @overload
    def set (self, startPoint: PyGe.Point3d, pnt: PyGe.Point3d, endPoint: PyGe.Point3d)-> None : ...
    @overload
    def set (self, curve1: PyGe.Curve3d, curve2: PyGe.Curve3d, radius: float)-> None : ...
    @overload
    def set (self, curve1: PyGe.Curve3d, curve2: PyGe.Curve3d, curve3: PyGe.Curve3d)-> None : ...
    def set (self, *args, **kwargs)-> None :
      '''Overloads:
    - cent: PyGe.Point3d, nrm: PyGe.Vector3d, radius: float
    - cent: PyGe.Point3d, nrm: PyGe.Vector3d, refVec: PyGe.Vector3d, radius: float, startAngle: float, endAngle: float
    - startPoint: PyGe.Point3d, pnt: PyGe.Point3d, endPoint: PyGe.Point3d
    - curve1: PyGe.Curve3d, curve2: PyGe.Curve3d, radius: float
    - curve1: PyGe.Curve3d, curve2: PyGe.Curve3d, curve3: PyGe.Curve3d
    '''
    ...
    def setAngles (self, val: float)-> None :
      '''                             '''
    ...
    def setAxes (self, vec: PyGe.Vector3d, refvec: PyGe.Vector3d)-> None :
      '''                             '''
    ...
    def setCenter (self, pt: PyGe.Point3d)-> None :
      '''                             '''
    ...
    def setInterval (self, val : PyGe.Interval = None)-> None :
      '''Sets the domain of the curve to the input interval.'''
    ...
    def setRadius (self, val: float)-> None :
      '''                             '''
    ...
    def startAng (self)-> float :
      '''                             '''
    ...
    def startPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def tangent (self, pt: PyGe.Point3d, tol: PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def transformBy (self, val : PyGe.Matrix3d)-> None :
      '''Transforms the entity by applying the input matrix.'''
    ...
    def translateBy (self, vec : PyGe.Vector3d)-> None :
      '''Translates the entity by the input vector.'''
    ...
    def type (self)-> PyGe.EntityId :
      '''Returns the type of the entity.'''
    ...

class ClipBoundary2d(Entity2d):
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (Point2d)arg2, (Point2d)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePoint2d,class AcGePoint2d)

__init__( (object)arg1, (list)arg2) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class boost::python::list)'''
    ...
    def cast (self, *args, **kwargs)-> PyGe.ClipBoundary2d :
      '''cast( (Entity2d)arg1) -> ClipBoundary2d :

    C++ signature :
        class PyGeClipBoundary2d cast(class PyGeEntity2d)'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def copy (self)-> PyGe.Entity2d :
      '''                             '''
    ...
    def copycast (self, *args, **kwargs)-> PyGe.ClipBoundary2d :
      '''copycast( (Entity2d)arg1) -> ClipBoundary2d :

    C++ signature :
        class PyGeClipBoundary2d copycast(class PyGeEntity2d)'''
    ...
    def isEqualTo (self, val : PyGe.Entity2d, tol : PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def isKindOf (self, val : PyGe.EntityId)-> bool :
      '''                             '''
    ...
    def isNull (self)-> bool :
      '''                             '''
    ...
    def isOn (self, pt : PyGe.Point2d, tol : PyGe.Tol=default)-> bool :
      '''                             '''
    ...
    def mirror (self, val : PyGe.Line2d)-> None :
      '''                             '''
    ...
    def rotateBy (self, angle : float, pt : PyGe.Point3d=PyGe.Point2d.kOrgin)-> None :
      '''                             '''
    ...
    def scaleBy (self, scaleFactor : float, pt : PyGe.Point2d=PyGe.Point2d.kOrgin)-> None :
      '''                             '''
    ...
    def transformBy (self, val : PyGe.Matrix2d)-> None :
      '''                             '''
    ...
    def translateBy (self, vec : PyGe.Vector2d)-> None :
      '''                             '''
    ...
    def type (self)-> PyGe.EntityId :
      '''                             '''
    ...

class CompositeCurve2d(Curve2d):
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...
    def area (self, startParam : float, endParam : float, tol : float = None)-> float :
      '''                             '''
    ...
    def boundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock2d :
      '''                             '''
    ...
    def cast (self, *args, **kwargs)-> PyGe.CompositeCurve2d :
      '''cast( (Entity2d)arg1) -> CompositeCurve2d :

    C++ signature :
        class PyGeCompositeCurve2d cast(class PyGeEntity2d)'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def closestPointTo (self, other : PyGe.Point2d | PyGe.Curve2d, tol : PyGe.Tol=None)-> PyGe.Point2d :
      '''                             '''
    ...
    def copy (self)-> PyGe.Entity2d :
      '''                             '''
    ...
    def copycast (self, *args, **kwargs)-> PyGe.CompositeCurve2d :
      '''copycast( (Entity2d)arg1) -> CompositeCurve2d :

    C++ signature :
        class PyGeCompositeCurve2d copycast(class PyGeEntity2d)'''
    ...
    def distanceTo (self, pt : PyGe.Point2d | PyGe.Curve2d, tol : PyGe.Tol=None)-> float :
      '''                             '''
    ...
    def evalPoint (self, param : float, numDeriv : int = 1)-> PyGe.Point2d :
      '''                             '''
    ...
    def explode (self, val : PyGe.Interval = None)-> list :
      '''                             '''
    ...
    def getClosestPointTo (self, other : PyGe.Point2d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve2d :
      '''                             '''
    ...
    def getClosestPointsTo (self, other : PyGe.Curve2d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def getEndPoint (self)-> PyGe.Point2d :
      '''                             '''
    ...
    def getInterval (self)-> PyGe.Interval :
      '''                             '''
    ...
    def getNormalPoint (self, pnt : PyGe.Point2d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve2d :
      '''                             '''
    ...

    @overload
    def getSamplePoints (self, numSample: int)-> list : ...
    @overload
    def getSamplePoints (self, fromParam: float, toParam: float, approxEps: float)-> list : ...
    def getSamplePoints (self, *args, **kwargs)-> list :
      '''Overloads:
    - numSample: int
    - fromParam: float, toParam: float, approxEps: float
    '''
    ...
    def getSplitCurves (self, param : float)-> tuple :
      '''                             '''
    ...
    def getStartPoint (self)-> PyGe.Point2d :
      '''                             '''
    ...
    def getTrimmedOffset (self, dist : float, extensionType : PyGe.OffsetCrvExtType, tol : PyGe.Tol=None)-> list :
      '''                             '''
    ...
    def hasEndPoint (self)-> bool :
      '''                             '''
    ...
    def hasStartPoint (self)-> bool :
      '''                             '''
    ...
    def isClosed (self, tol : PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def isDegenerate (self, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isEqualTo (self, val : PyGe.Entity2d, tol : PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def isKindOf (self, val : PyGe.EntityId)-> bool :
      '''                             '''
    ...
    def isLinear (self, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isNull (self)-> bool :
      '''                             '''
    ...
    def isOn (self, pt : float | PyGe.Point2d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isPeriodic (self)-> tuple :
      '''                             '''
    ...
    def length (self, frm : float, to : float, tol : float = None)-> float :
      '''                             '''
    ...
    def mirror (self, val : PyGe.Line2d)-> None :
      '''                             '''
    ...
    def orthoBoundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock2d :
      '''                             '''
    ...
    def paramAtLength (self, datumParam: float, length: float, posParamDir: bool=True, tol: float=None)-> float :
      '''                             '''
    ...
    def paramOf (self, pt : PyGe.Point2d, tol : PyGe.Tol=None)-> float :
      '''                             '''
    ...
    def reverseParam (self)-> None :
      '''                             '''
    ...
    def rotateBy (self, angle : float, pt : PyGe.Point3d=PyGe.Point2d.kOrgin)-> None :
      '''                             '''
    ...
    def scaleBy (self, scaleFactor : float, pt : PyGe.Point2d=PyGe.Point2d.kOrgin)-> None :
      '''                             '''
    ...
    def setInterval (self, val : PyGe.Interval = None)-> None :
      '''                             '''
    ...
    def transformBy (self, val : PyGe.Matrix2d)-> None :
      '''                             '''
    ...
    def translateBy (self, vec : PyGe.Vector2d)-> None :
      '''                             '''
    ...
    def type (self)-> PyGe.EntityId :
      '''                             '''
    ...

class CompositeCurve3d(Curve3d):

    @overload
    def __init__ (self, /)-> None : ...
    @overload
    def __init__ (self, curveList: list[PyGe.Curve3d])-> None : ...
    @overload
    def __init__ (self, curveList: list[PyGe.Curve3d], isOwnerOfCurves: list[int])-> None : ...
    def __init__ (self, *args, **kwargs)-> None :
      '''Overloads:
    - None: Any
    - curveList: list[PyGe.Curve3d]
    - curveList: list[PyGe.Curve3d], isOwnerOfCurves: list[int]
    '''
    ...
    def area (self, startParam : float, endParam : float, tol : float = None)-> float :
      '''Returns the area of the interval of the curve defined by startParam and endParam. Returns Adesk::kTrue if area was successfully computed to within the specified tolerance. If the curve is not planar, then the area cannot be calculated and a value of Adesk::kFalse is returned. If the points at startParam and endParam are the same, then this function returns the area of the closed curve. If the points are different, then this function connects the two points with a line segment and return the signed area between the curve and the line segment. If the line segment does not intersect the curve at any points between startParam and endParam, then the returned area is positive. If the line segment intersects the curves at any points between startParam and endParam, then the returned area is the sum of the sub-areas created by the intersection of the line segment with the curve. Each sub-area has a positive or negative area, depending on whether the curve lies above or below the line segment. The total area returned by this function can therefore be positive, negative, or 0. '''
    ...
    def boundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock3d :
      '''Returns the bounding box of the curve. The sides of the returned box are parallel to the coordinate axes. '''
    ...

    @staticmethod
    def cast (otherObject: PyGe.Entity3d)-> PyGe.CompositeCurve3d :
      '''                             '''
    ...

    @staticmethod
    def className ()-> str :
      '''                             '''
    ...
    def closestPointTo (self, other : PyGe.Point3d | PyGe.Curve3d, tol : PyGe.Tol=None)-> PyGe.Point3d :
      '''Finds the closest point on this curve to the input point. This function is the same as closestPointTo(), except that the closest point is returned as an AcGePointOnCurve3d object.'''
    ...
    def copy (self)-> PyGe.Entity3d :
      '''Returns a pointer to a copy of this entity. This copy is created using the new and it is the responsibility of the caller to delete it.'''
    ...

    @staticmethod
    def copycast (otherObject: PyGe.Entity3d)-> PyGe.CompositeCurve3d :
      '''                             '''
    ...
    def distanceTo (self, pt : PyGe.Point3d | PyGe.Curve3d, tol : PyGe.Tol=None)-> float :
      '''Returns the distance between the input point and the closest point on this curve.'''
    ...
    def evalPoint (self, param : float, numDeriv : int = 1)-> PyGe.Point3d :
      '''Returns the point on the curve that corresponds to the input parameter value. Also returns the number of derivative vectors that are specified in numDeriv. The numDeriv parameter should not be set larger than 2.'''
    ...
    def explode (self, val : PyGe.Interval = None)-> list :
      '''Explodes the curve into its individual components. If the curve is a composite curve, then explodedCurves contains the list of component curves of the composite. If the curve is a spline, then it is exploded at the points of C1 discontinuity and explodedCurves contains a copy of each continuous sub-curve. This function returns Adesk::kTrue if the curve was exploded (that is, the curve was a composite or a discontinuous spline) and Adesk::kFalse otherwise. The number of entries returned in newExplodedCurves is always the same as the number of entries in explodedCurves. Each flag in newExplodedCurves indicates whether the corresponding curve in explodedCurves was created with the new operator. If the flag is 1, then it is the responsibility of the caller to delete the curve. If the flag is 0, the curve is deleted by gelib and the caller should not attempt to delete it. If no intrvl parameter is supplied, then the interval is taken to be the entire curve. '''
    ...
    def getClosestPointTo (self, other : PyGe.Point3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''Finds the closest point on this curve to the input point. This function is the same as closestPointTo(), except that the closest point is returned as an AcGePointOnCurve3d object.'''
    ...
    def getClosestPointsTo (self, other : PyGe.Curve3d, tol : PyGe.Tol=None)-> tuple :
      '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
    ...
    def getCurveList (self)-> list :
      '''                             '''
    ...
    def getEndPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def getInterval (self)-> PyGe.Interval :
      '''Returns the parametric range of the curve. The function evalPoint(double) always returns a point on this curve when called with a value within the returned interval.'''
    ...
    def getNormalPoint (self, pnt : PyGe.Point3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''Finds the point on the input curve whose normal passes through the input point. The returned point lies on a plane that also contains the input point and is perpendicular to the curve tangent at that point. The returned point is therefore at a local minimum or a local maximum from the input point. The curve does not need to be planar. If the curve is planar, the input point does not need to lie in the plane of the curve. On input, the second parameter is assumed to contain the parameter value of an initial guess. If there is more than one normal point on the curve, the returned point will be the one whose parameter value is closest to the input parameter value.'''
    ...
    def getProjClosestPointTo (self, pt : PyGe.Point3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
    ...
    def getProjClosestPointsTo (self, pt : PyGe.Curve3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> tuple :
      '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
    ...

    @overload
    def getSamplePoints (self, numSample: int)-> tuple : ...
    @overload
    def getSamplePoints (self, fromParam: float, toParam: float, approxEps: float)-> tuple : ...
    def getSamplePoints (self, *args, **kwargs)-> tuple :
      '''Overloads:
    - numSample: int
    - fromParam: float, toParam: float, approxEps: float
    
	-Returns the specified number of points on the curve. The points are equally spaced by parameter value. So if the interval of the curve [0,1] and numSample is 5, the parameter values of the returned points are 0, 0.25, 0.5, 0.75, and 1.-'''
    ...
    def getSplitCurves (self, param : float)-> tuple :
      '''Returns two segments which are obtained by splitting the curve at the input parameter value. If the specified parameter value does not lie within the parametric interval of the curve or if it corresponds to the start point or endpoint of the curve, then piece1 and piece2 are set to null. This function uses the new to create the curve segments whose addresses are returned in piece1 and piece2. It is the responsibility of the caller to delete these objects. '''
    ...
    def getStartPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def getTrimmedOffset (self, dist : float, planeNormal : PyGe.Vector3d, extensionType : PyGe.OffsetCrvExtType, tol : PyGe.Tol=None)-> list :
      '''Returns one or more offset curves that represent the trimmed offset of the curve. The curve must be planar and planeNormal must be perpendicular to the plane of the curve. The positive direction of offset at a point on the curve is taken to be the cross product of planeNormal with the tangent vector at that point. The curve may be offset in either of two directions by specifying a positive or negative offset distance; planeNormal determines which direction is the positive direction of offset. The returned offset curves are trimmed so that they do not contain any points of self-intersection. Each curve that is returned in offsetCurveList is created with the new and it is the responsibility of the caller to delete these curves. Each curve that is returned in offsetCurveList is a connected curve and may be a composite curve if the offset curve had to be trimmed to remove self-intersecting loops. offsetCurveList only contains more than one curve if the offset operation produces multiple curves which are not connected. If the original curve contains points of C1 discontinuity and the direction of offset causes the offset curve to be disjoint (for instance, if the original curve is a composite curve that is a rectangle and the direction of offset is to the outside of the rectangle), then the offset curve is closed with an arc or a line segment, or the curves are simply extended depending on the value of extensionType.'''
    ...
    def globalToLocalParam (self, param: float)-> tuple :
      '''                             '''
    ...
    def hasEndPoint (self)-> bool :
      '''Returns Adesk::kTrue if curve has an endpoint. A return value of Adesk::kFalse means that the parametric interval of the curve does not have an upper bound. The endPnt parameter contains meaningful data only if this function returns a value of Adesk::kTrue.'''
    ...
    def hasStartPoint (self)-> bool :
      '''Returns Adesk::kTrue if curve has a start point. A return value of Adesk::kFalse means that the parametric interval of the curve does not have a lower bound. The startPnt parameter contains meaningful data only if this function returns a value of Adesk::kTrue.'''
    ...
    def isClosed (self, tol : PyGe.Tol=None)-> bool :
      '''Determines if start point and endpoint of curve are the same.'''
    ...
    def isCoplanarWith (self, curve : PyGe.Curve3d, tol : PyGe.Tol=None)-> tuple :
      '''Returns Adesk::kTrue if both curve are planar and lie in the same plane. The plane parameter is only valid if this function returns a value of Adesk::kTrue.'''
    ...
    def isDegenerate (self, tol : PyGe.Tol=None)-> tuple :
      '''Determines if the curve is degenerate and if so returns the type of entity which the curve degenerates into. For example, if the curve is a circle with a radius of 0 then degenerateType is set to AcGe::kPoint3d. If the curve is an ellipse with a minor radius of 0 and a major radius of 1, then degenerateType is set to AcGe::kLineSeg3d. The degenerateType parameter is only set to something meaningful when this function returns a value of Adesk::kTrue.'''
    ...
    def isEqualTo (self, val : PyGe.Entity3d, tol : PyGe.Tol=None)-> bool :
      '''Determines if two entities are equal to each other. Two entities are considered to be equal only if they are of the same type and they represent the same 3D point set. For instance, if the two entities are of types AcGeCircArc3d and AcGeEllipArc3d then they are not considered equal even if the ellipse is completely coincident with the circle. Also, two curves are not considered equal unless they have the same parameterization. For instance, two infinite coincident lines are not considered equal if they have different scaling in their parameterization. '''
    ...
    def isKindOf (self, val : PyGe.EntityId)-> bool :
      '''                             '''
    ...
    def isLinear (self, tol : PyGe.Tol=None)-> tuple :
      '''Determines if curve is linear. This function returns an infinite line even if the curve is not infinite. The line parameter contains meaningful data only if this function returns a value of Adesk::kTrue.'''
    ...
    def isNull (self)-> bool :
      '''                             '''
    ...
    def isOn (self, pt : float | PyGe.Point3d, tol : PyGe.Tol=None)-> tuple :
      '''Determines if input parameter value is within valid parametric range of curve.'''
    ...
    def isPeriodic (self)-> tuple :
      '''Determines if the curve is periodic. The curve is periodic if and only if it is closed and the two points evalPoint(t) and evalPoint(t+period) are always the same point for all values of t.'''
    ...
    def isPlanar (self, tol : PyGe.Tol=None)-> tuple :
      '''Determines if curve is planar. If the curve is a line, then this function returns an arbitrary plane that contains the line. The plane parameter contains meaningful data only if this function returns a value of Adesk::kTrue. '''
    ...
    def length (self, frm : float, to : float, tol : float = None)-> float :
      '''Returns the arc length of the curve between the two parameter values.'''
    ...
    def localToGlobalParam (self, param: float, segNum: int)-> float :
      '''                             '''
    ...
    def mirror (self, val : PyGe.Plane)-> None :
      '''Transforms the entity by mirroring it across the input plane.'''
    ...
    def orthoBoundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock3d :
      '''Returns the bounding box of the curve. The sides of the returned box are parallel to the coordinate axes.'''
    ...
    def orthoProject (self, projectionPlane : PyGe.Plane, tol : PyGe.Tol=None)-> PyGe.Entity3d :
      '''Returns the entity that is the orthogonal projection of the curve onto the projection plane. The returned entity may not be of the same type as the original curve and may not even be a curve (for instance, a line projects into a point if it is orthogonal to the projection plane). The returned entity is created with the new and it is the responsibility of the caller to delete it.'''
    ...
    def paramAtLength (self, datumParam : float, length : float, posParamDir : bool=True, tol : float = default)-> float :
      '''Returns the parameter value of the point whose arc length distance (from the point with parameter value datumParam) is the input length. In other words, ift = paramAtLength (datumParam, len, posParamDir, tol) then length (t, datumParam, tol) is (approximately) equal to len. If posParamDir is set to Adesk::kTrue, then the returned parameter value is greater than datumParam. Otherwise it will be less than datumParam. '''
    ...
    def paramOf (self, pt : PyGe.Point3d, tol : PyGe.Tol=None)-> float :
      '''Returns the parameter value of pnt. This function assumes that pnt lies on the curve and does not verify this. If pnt does not lie on the curve, this function will return unpredictable results. If it is not known whether pnt lies on the curve, the user should not call this function but should instead call AcGeCurve3d::isOn (pnt, param, tol). '''
    ...
    def projClosestPointTo (self, pt : PyGe.Point3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.Point3d :
      '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
    ...
    def projClosestPointsTo (self, pt : PyGe.Curve3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> tuple :
      '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
    ...
    def project (self, projectionPlane : PyGe.Plane, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.Entity3d :
      '''Returns the entity that is the projection of the curve onto the projection plane in the specified direction. The projectDirection vector must not be parallel to the projection plane. The returned entity may not be of the same type as the original curve and may not even be a curve (for instance, a line projects into a point if it is parallel to projectDirection). The returned entity is created with the new and it is the responsibility of the caller to delete it.'''
    ...
    def reverseParam (self)-> None :
      '''Reverses the parametric direction of the curve. The point set of the curve is unchanged, but the direction of the curve is reversed.'''
    ...
    def rotateBy (self, angle : float, vec : PyGe.Vector3d, pt : PyGe.Point3d = 'origin')-> None :
      '''Rotates the entity by the input angle about the line defined by the input point and vector.'''
    ...
    def scaleBy (self, scaleFactor : float, pt : PyGe.Point3d = 'origin')-> None :
      '''Scales the entity about the input point by the input scale factor. Input scale factor must be greater than 0.'''
    ...

    @overload
    def setCurveList (self, curveList: list[PyGe.Curve3d])-> None : ...
    @overload
    def setCurveList (self, curveList: list[PyGe.Curve3d], isOwnerOfCurves: list[int])-> None : ...
    def setCurveList (self, *args, **kwargs)-> None :
      '''Overloads:
    - curveList: list[PyGe.Curve3d]
    - curveList: list[PyGe.Curve3d], isOwnerOfCurves: list[int]
    '''
    ...
    def setInterval (self, val : PyGe.Interval = None)-> None :
      '''Sets the domain of the curve to the input interval.'''
    ...
    def transformBy (self, val : PyGe.Matrix3d)-> None :
      '''Transforms the entity by applying the input matrix.'''
    ...
    def translateBy (self, vec : PyGe.Vector3d)-> None :
      '''Translates the entity by the input vector.'''
    ...
    def type (self)-> PyGe.EntityId :
      '''Returns the type of the entity.'''
    ...

class Cone(Surface):
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (float)arg2, (float)arg3, (Point3d)arg4, (float)arg5, (Vector3d)arg6) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,double,double,class AcGePoint3d,double,class AcGeVector3d)

__init__( (object)arg1, (float)arg2, (float)arg3, (Point3d)arg4, (float)arg5, (Vector3d)arg6, (Vector3d)arg7, (object)arg8, (float)arg9, (float)arg10) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,double,double,class AcGePoint3d,double,class AcGeVector3d,class AcGeVector3d,class AcGeInterval,double,double)'''
    ...
    def apex (self, *args, **kwargs)-> PyGe.Point3d :
      '''apex( (Cone)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d apex(class PyGeCone {lvalue})'''
    ...
    def axisOfSymmetry (self, *args, **kwargs)-> PyGe.Vector3d :
      '''axisOfSymmetry( (Cone)arg1) -> Vector3d :

    C++ signature :
        class AcGeVector3d axisOfSymmetry(class PyGeCone {lvalue})'''
    ...
    def baseCenter (self, *args, **kwargs)-> PyGe.Point3d :
      '''baseCenter( (Cone)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d baseCenter(class PyGeCone {lvalue})'''
    ...
    def baseRadius (self, *args, **kwargs)-> float :
      '''baseRadius( (Cone)arg1) -> float :

    C++ signature :
        double baseRadius(class PyGeCone {lvalue})'''
    ...
    def cast (self, *args, **kwargs)-> PyGe.Cone :
      '''cast( (Entity3d)arg1) -> Cone :

    C++ signature :
        class PyGeCone cast(class PyGeEntity3d)'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def closestPointTo (self, *args, **kwargs)-> PyGe.Point3d :
      '''closestPointTo( (Surface)arg1, (Point3d)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d closestPointTo(class PyGeSurface {lvalue},class AcGePoint3d)

closestPointTo( (Surface)arg1, (Point3d)arg2, (Tol)arg3) -> Point3d :

    C++ signature :
        class AcGePoint3d closestPointTo(class PyGeSurface {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def copy (self)-> PyGe.Entity3d :
      '''Returns a pointer to a copy of this entity. This copy is created using the new and it is the responsibility of the caller to delete it.'''
    ...
    def copycast (self, *args, **kwargs)-> PyGe.Cone :
      '''copycast( (Entity3d)arg1) -> Cone :

    C++ signature :
        class PyGeCone copycast(class PyGeEntity3d)'''
    ...
    def distanceTo (self, *args, **kwargs)-> float :
      '''distanceTo( (Surface)arg1, (Point3d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeSurface {lvalue},class AcGePoint3d)

distanceTo( (Surface)arg1, (Point3d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeSurface {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def evalPoint (self, *args, **kwargs)-> PyGe.Point3d :
      '''evalPoint( (Surface)arg1, (Point2d)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d evalPoint(class PyGeSurface {lvalue},class AcGePoint2d)

evalPoint( (Surface)arg1, (Point2d)arg2, (int)arg3, (list)arg4) -> Point3d :

    C++ signature :
        class AcGePoint3d evalPoint(class PyGeSurface {lvalue},class AcGePoint2d,int,class boost::python::list {lvalue})

evalPoint( (Surface)arg1, (Point2d)arg2, (int)arg3, (list)arg4, (Vector3d)arg5) -> Point3d :

    C++ signature :
        class AcGePoint3d evalPoint(class PyGeSurface {lvalue},class AcGePoint2d,int,class boost::python::list {lvalue},class AcGeVector3d {lvalue})'''
    ...
    def getAngles (self, *args, **kwargs)-> tuple :
      '''getAngles( (Cone)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple getAngles(class PyGeCone {lvalue})'''
    ...
    def getHalfAngle (self, *args, **kwargs)-> tuple :
      '''getHalfAngle( (Cone)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple getHalfAngle(class PyGeCone {lvalue})'''
    ...
    def getHeight (self, *args, **kwargs)-> PyGe.Interval :
      '''getHeight( (Cone)arg1) -> Interval :

    C++ signature :
        class PyGeInterval getHeight(class PyGeCone {lvalue})'''
    ...
    def halfAngle (self, *args, **kwargs)-> float :
      '''halfAngle( (Cone)arg1) -> float :

    C++ signature :
        double halfAngle(class PyGeCone {lvalue})'''
    ...
    def heightAt (self, *args, **kwargs)-> float :
      '''heightAt( (Cone)arg1, (float)arg2) -> float :

    C++ signature :
        double heightAt(class PyGeCone {lvalue},double)'''
    ...
    def intersectWith (self, *args, **kwargs)-> tuple :
      '''intersectWith( (Cone)arg1, (LinearEnt3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeCone {lvalue},class PyGeLinearEnt3d)

intersectWith( (Cone)arg1, (LinearEnt3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeCone {lvalue},class PyGeLinearEnt3d,class AcGeTol {lvalue})'''
    ...
    def isClosed (self, *args, **kwargs)-> bool :
      '''isClosed( (Cone)arg1) -> bool :

    C++ signature :
        bool isClosed(class PyGeCone {lvalue})

isClosed( (Cone)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosed(class PyGeCone {lvalue},class AcGeTol)'''
    ...
    def isClosedInU (self, *args, **kwargs)-> bool :
      '''isClosedInU( (Surface)arg1) -> bool :

    C++ signature :
        bool isClosedInU(class PyGeSurface {lvalue})

isClosedInU( (Surface)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosedInU(class PyGeSurface {lvalue},class AcGeTol)'''
    ...
    def isClosedInV (self, *args, **kwargs)-> bool :
      '''isClosedInV( (Surface)arg1) -> bool :

    C++ signature :
        bool isClosedInV(class PyGeSurface {lvalue})

isClosedInV( (Surface)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosedInV(class PyGeSurface {lvalue},class AcGeTol)'''
    ...
    def isEqualTo (self, val : PyGe.Entity3d, tol : PyGe.Tol=None)-> bool :
      '''Determines if two entities are equal to each other. Two entities are considered to be equal only if they are of the same type and they represent the same 3D point set. For instance, if the two entities are of types AcGeCircArc3d and AcGeEllipArc3d then they are not considered equal even if the ellipse is completely coincident with the circle. Also, two curves are not considered equal unless they have the same parameterization. For instance, two infinite coincident lines are not considered equal if they have different scaling in their parameterization. '''
    ...
    def isKindOf (self, val : PyGe.EntityId)-> bool :
      '''                             '''
    ...
    def isNormalReversed (self, *args, **kwargs)-> bool :
      '''isNormalReversed( (Surface)arg1) -> bool :

    C++ signature :
        bool isNormalReversed(class PyGeSurface {lvalue})'''
    ...
    def isNull (self)-> bool :
      '''                             '''
    ...
    def isOn (self, *args, **kwargs)-> bool :
      '''isOn( (Surface)arg1, (Point3d)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeSurface {lvalue},class AcGePoint3d)

isOn( (Surface)arg1, (Point3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeSurface {lvalue},class AcGePoint3d,class AcGeTol)

isOn( (Surface)arg1, (Point3d)arg2, (Point2d)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeSurface {lvalue},class AcGePoint3d,class AcGePoint2d {lvalue})

isOn( (Surface)arg1, (Point3d)arg2, (Point2d)arg3, (Tol)arg4) -> bool :

    C++ signature :
        bool isOn(class PyGeSurface {lvalue},class AcGePoint3d,class AcGePoint2d {lvalue},class AcGeTol)'''
    ...
    def isOuterNormal (self, *args, **kwargs)-> bool :
      '''isOuterNormal( (Cone)arg1) -> bool :

    C++ signature :
        bool isOuterNormal(class PyGeCone {lvalue})'''
    ...
    def mirror (self, val : PyGe.Plane)-> None :
      '''Transforms the entity by mirroring it across the input plane.'''
    ...
    def paramOf (self, *args, **kwargs)-> PyGe.Point2d :
      '''paramOf( (Surface)arg1, (Point3d)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d paramOf(class PyGeSurface {lvalue},class AcGePoint3d)

paramOf( (Surface)arg1, (Point3d)arg2, (Tol)arg3) -> Point2d :

    C++ signature :
        class AcGePoint2d paramOf(class PyGeSurface {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def refAxis (self, *args, **kwargs)-> PyGe.Vector3d :
      '''refAxis( (Cone)arg1) -> Vector3d :

    C++ signature :
        class AcGeVector3d refAxis(class PyGeCone {lvalue})'''
    ...
    def reverseNormal (self, *args, **kwargs)-> None :
      '''reverseNormal( (Surface)arg1) -> None :

    C++ signature :
        void reverseNormal(class PyGeSurface {lvalue})'''
    ...
    def rotateBy (self, angle : float, vec : PyGe.Vector3d, pt : PyGe.Point3d = 'origin')-> None :
      '''Rotates the entity by the input angle about the line defined by the input point and vector.'''
    ...
    def scaleBy (self, scaleFactor : float, pt : PyGe.Point3d = 'origin')-> None :
      '''Scales the entity about the input point by the input scale factor. Input scale factor must be greater than 0.'''
    ...
    def set (self, *args, **kwargs)-> None :
      '''set( (Cone)arg1, (float)arg2, (float)arg3, (Point3d)arg4, (float)arg5, (Vector3d)arg6) -> None :

    C++ signature :
        void set(class PyGeCone {lvalue},double,double,class AcGePoint3d,double,class AcGeVector3d)

set( (Cone)arg1, (float)arg2, (float)arg3, (Point3d)arg4, (float)arg5, (Vector3d)arg6, (Vector3d)arg7, (Interval)arg8, (float)arg9, (float)arg10) -> None :

    C++ signature :
        void set(class PyGeCone {lvalue},double,double,class AcGePoint3d,double,class AcGeVector3d,class AcGeVector3d,class PyGeInterval,double,double)'''
    ...
    def setAngles (self, *args, **kwargs)-> None :
      '''setAngles( (Cone)arg1, (float)arg2, (float)arg3) -> None :

    C++ signature :
        void setAngles(class PyGeCone {lvalue},double,double)'''
    ...
    def setBaseRadius (self, *args, **kwargs)-> None :
      '''setBaseRadius( (Cone)arg1, (float)arg2) -> None :

    C++ signature :
        void setBaseRadius(class PyGeCone {lvalue},double)'''
    ...
    def setHeight (self, *args, **kwargs)-> None :
      '''setHeight( (Cone)arg1, (Interval)arg2) -> None :

    C++ signature :
        void setHeight(class PyGeCone {lvalue},class PyGeInterval)'''
    ...
    def transformBy (self, val : PyGe.Matrix3d)-> None :
      '''Transforms the entity by applying the input matrix.'''
    ...
    def translateBy (self, vec : PyGe.Vector3d)-> None :
      '''Translates the entity by the input vector.'''
    ...
    def type (self)-> PyGe.EntityId :
      '''Returns the type of the entity.'''
    ...

class CubicSplineCurve2d(SplineEnt2d):
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (Curve2d)arg2, (float)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class PyGeCurve2d,double)

__init__( (object)arg1, (list)arg2, (Tol)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class boost::python::list,class AcGeTol)

__init__( (object)arg1, (list)arg2, (Vector2d)arg3, (Vector2d)arg4, (Tol)arg5) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class boost::python::list,class AcGeVector2d,class AcGeVector2d,class AcGeTol)

__init__( (object)arg1, (KnotVector)arg2, (list)arg3, (list)arg4, (bool)arg5) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class PyGeKnotVector,class boost::python::list,class boost::python::list,bool)'''
    ...
    def area (self, startParam : float, endParam : float, tol : float = None)-> float :
      '''                             '''
    ...
    def boundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock2d :
      '''                             '''
    ...
    def cast (self, *args, **kwargs)-> PyGe.SplineEnt2d :
      '''cast( (Entity2d)arg1) -> SplineEnt2d :

    C++ signature :
        class PyGeSplineEnt2d cast(class PyGeEntity2d)'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def closestPointTo (self, other : PyGe.Point2d | PyGe.Curve2d, tol : PyGe.Tol=None)-> PyGe.Point2d :
      '''                             '''
    ...
    def continuityAtKnot (self, *args, **kwargs)-> int :
      '''continuityAtKnot( (SplineEnt2d)arg1, (int)arg2) -> int :

    C++ signature :
        int continuityAtKnot(class PyGeSplineEnt2d {lvalue},int)

continuityAtKnot( (SplineEnt2d)arg1, (int)arg2, (Tol)arg3) -> int :

    C++ signature :
        int continuityAtKnot(class PyGeSplineEnt2d {lvalue},int,class AcGeTol)'''
    ...
    def controlPointAt (self, *args, **kwargs)-> PyGe.Point2d :
      '''controlPointAt( (SplineEnt2d)arg1, (int)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d controlPointAt(class PyGeSplineEnt2d {lvalue},int)'''
    ...
    def copy (self)-> PyGe.Entity2d :
      '''                             '''
    ...
    def copycast (self, *args, **kwargs)-> PyGe.CubicSplineCurve2d :
      '''copycast( (Entity2d)arg1) -> CubicSplineCurve2d :

    C++ signature :
        class PyGeCubicSplineCurve2d copycast(class PyGeEntity2d)'''
    ...
    def degree (self, *args, **kwargs)-> int :
      '''degree( (SplineEnt2d)arg1) -> int :

    C++ signature :
        int degree(class PyGeSplineEnt2d {lvalue})'''
    ...
    def distanceTo (self, pt : PyGe.Point2d | PyGe.Curve2d, tol : PyGe.Tol=None)-> float :
      '''                             '''
    ...
    def endParam (self, *args, **kwargs)-> float :
      '''endParam( (SplineEnt2d)arg1) -> float :

    C++ signature :
        double endParam(class PyGeSplineEnt2d {lvalue})'''
    ...
    def endPoint (self, *args, **kwargs)-> PyGe.Point2d :
      '''endPoint( (SplineEnt2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d endPoint(class PyGeSplineEnt2d {lvalue})'''
    ...
    def evalPoint (self, param : float, numDeriv : int = 1)-> PyGe.Point2d :
      '''                             '''
    ...
    def explode (self, val : PyGe.Interval = None)-> list :
      '''                             '''
    ...
    def firstDerivAt (self, *args, **kwargs)-> PyGe.Vector2d :
      '''firstDerivAt( (CubicSplineCurve2d)arg1, (int)arg2) -> Vector2d :

    C++ signature :
        class AcGeVector2d firstDerivAt(class PyGeCubicSplineCurve2d {lvalue},int)'''
    ...
    def fitPointAt (self, *args, **kwargs)-> PyGe.Point2d :
      '''fitPointAt( (CubicSplineCurve2d)arg1, (int)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d fitPointAt(class PyGeCubicSplineCurve2d {lvalue},int)'''
    ...
    def getClosestPointTo (self, other : PyGe.Point2d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve2d :
      '''                             '''
    ...
    def getClosestPointsTo (self, other : PyGe.Curve2d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def getEndPoint (self)-> PyGe.Point2d :
      '''                             '''
    ...
    def getInterval (self)-> PyGe.Interval :
      '''                             '''
    ...
    def getNormalPoint (self, pnt : PyGe.Point2d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve2d :
      '''                             '''
    ...

    @overload
    def getSamplePoints (self, numSample: int)-> list : ...
    @overload
    def getSamplePoints (self, fromParam: float, toParam: float, approxEps: float)-> list : ...
    def getSamplePoints (self, *args, **kwargs)-> list :
      '''Overloads:
    - numSample: int
    - fromParam: float, toParam: float, approxEps: float
    '''
    ...
    def getSplitCurves (self, param : float)-> tuple :
      '''                             '''
    ...
    def getStartPoint (self)-> PyGe.Point2d :
      '''                             '''
    ...
    def getTrimmedOffset (self, dist : float, extensionType : PyGe.OffsetCrvExtType, tol : PyGe.Tol=None)-> list :
      '''                             '''
    ...
    def hasEndPoint (self)-> bool :
      '''                             '''
    ...
    def hasFitData (self, *args, **kwargs)-> bool :
      '''hasFitData( (SplineEnt2d)arg1) -> bool :

    C++ signature :
        bool hasFitData(class PyGeSplineEnt2d {lvalue})'''
    ...
    def hasStartPoint (self)-> bool :
      '''                             '''
    ...
    def isClosed (self, tol : PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def isDegenerate (self, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isEqualTo (self, val : PyGe.Entity2d, tol : PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def isKindOf (self, val : PyGe.EntityId)-> bool :
      '''                             '''
    ...
    def isLinear (self, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isNull (self)-> bool :
      '''                             '''
    ...
    def isOn (self, pt : float | PyGe.Point2d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isPeriodic (self)-> tuple :
      '''                             '''
    ...
    def isRational (self, *args, **kwargs)-> bool :
      '''isRational( (SplineEnt2d)arg1) -> bool :

    C++ signature :
        bool isRational(class PyGeSplineEnt2d {lvalue})'''
    ...
    def knotAt (self, *args, **kwargs)-> float :
      '''knotAt( (SplineEnt2d)arg1, (int)arg2) -> float :

    C++ signature :
        double knotAt(class PyGeSplineEnt2d {lvalue},int)'''
    ...
    def knots (self, *args, **kwargs)-> PyGe.KnotVector :
      '''knots( (SplineEnt2d)arg1) -> KnotVector :

    C++ signature :
        class PyGeKnotVector knots(class PyGeSplineEnt2d {lvalue})'''
    ...
    def length (self, frm : float, to : float, tol : float = None)-> float :
      '''                             '''
    ...
    def mirror (self, val : PyGe.Line2d)-> None :
      '''                             '''
    ...
    def numControlPoints (self, *args, **kwargs)-> int :
      '''numControlPoints( (SplineEnt2d)arg1) -> int :

    C++ signature :
        int numControlPoints(class PyGeSplineEnt2d {lvalue})'''
    ...
    def numFitPoints (self, *args, **kwargs)-> int :
      '''numFitPoints( (CubicSplineCurve2d)arg1) -> int :

    C++ signature :
        int numFitPoints(class PyGeCubicSplineCurve2d {lvalue})'''
    ...
    def numKnots (self, *args, **kwargs)-> int :
      '''numKnots( (SplineEnt2d)arg1) -> int :

    C++ signature :
        int numKnots(class PyGeSplineEnt2d {lvalue})'''
    ...
    def order (self, *args, **kwargs)-> int :
      '''order( (SplineEnt2d)arg1) -> int :

    C++ signature :
        int order(class PyGeSplineEnt2d {lvalue})'''
    ...
    def orthoBoundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock2d :
      '''                             '''
    ...
    def paramAtLength (self, datumParam: float, length: float, posParamDir: bool=True, tol: float=None)-> float :
      '''                             '''
    ...
    def paramOf (self, pt : PyGe.Point2d, tol : PyGe.Tol=None)-> float :
      '''                             '''
    ...
    def reverseParam (self)-> None :
      '''                             '''
    ...
    def rotateBy (self, angle : float, pt : PyGe.Point3d=PyGe.Point2d.kOrgin)-> None :
      '''                             '''
    ...
    def scaleBy (self, scaleFactor : float, pt : PyGe.Point2d=PyGe.Point2d.kOrgin)-> None :
      '''                             '''
    ...
    def setControlPointAt (self, *args, **kwargs)-> None :
      '''setControlPointAt( (SplineEnt2d)arg1, (int)arg2, (Point2d)arg3) -> None :

    C++ signature :
        void setControlPointAt(class PyGeSplineEnt2d {lvalue},int,class AcGePoint2d)'''
    ...
    def setFirstDerivAt (self, *args, **kwargs)-> None :
      '''setFirstDerivAt( (CubicSplineCurve2d)arg1, (int)arg2, (Vector2d)arg3) -> None :

    C++ signature :
        void setFirstDerivAt(class PyGeCubicSplineCurve2d {lvalue},int,class AcGeVector2d)'''
    ...
    def setFitPointAt (self, *args, **kwargs)-> None :
      '''setFitPointAt( (CubicSplineCurve2d)arg1, (int)arg2, (Point2d)arg3) -> None :

    C++ signature :
        void setFitPointAt(class PyGeCubicSplineCurve2d {lvalue},int,class AcGePoint2d)'''
    ...
    def setInterval (self, val : PyGe.Interval = None)-> None :
      '''                             '''
    ...
    def setKnotAt (self, *args, **kwargs)-> None :
      '''setKnotAt( (SplineEnt2d)arg1, (int)arg2, (float)arg3) -> None :

    C++ signature :
        void setKnotAt(class PyGeSplineEnt2d {lvalue},int,double)'''
    ...
    def startParam (self, *args, **kwargs)-> float :
      '''startParam( (SplineEnt2d)arg1) -> float :

    C++ signature :
        double startParam(class PyGeSplineEnt2d {lvalue})'''
    ...
    def startPoint (self, *args, **kwargs)-> PyGe.Point2d :
      '''startPoint( (SplineEnt2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d startPoint(class PyGeSplineEnt2d {lvalue})'''
    ...
    def transformBy (self, val : PyGe.Matrix2d)-> None :
      '''                             '''
    ...
    def translateBy (self, vec : PyGe.Vector2d)-> None :
      '''                             '''
    ...
    def type (self)-> PyGe.EntityId :
      '''                             '''
    ...

class CubicSplineCurve3d(SplineEnt3d):
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (Curve3d)arg2, (float)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class PyGeCurve3d,double)

__init__( (object)arg1, (list)arg2, (Tol)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class boost::python::list,class AcGeTol)

__init__( (object)arg1, (list)arg2, (Vector3d)arg3, (Vector3d)arg4, (Tol)arg5) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class boost::python::list,class AcGeVector3d,class AcGeVector3d,class AcGeTol)

__init__( (object)arg1, (KnotVector)arg2, (list)arg3, (list)arg4, (bool)arg5) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class PyGeKnotVector,class boost::python::list,class boost::python::list,bool)'''
    ...
    def area (self, startParam : float, endParam : float, tol : float = None)-> float :
      '''Returns the area of the interval of the curve defined by startParam and endParam. Returns Adesk::kTrue if area was successfully computed to within the specified tolerance. If the curve is not planar, then the area cannot be calculated and a value of Adesk::kFalse is returned. If the points at startParam and endParam are the same, then this function returns the area of the closed curve. If the points are different, then this function connects the two points with a line segment and return the signed area between the curve and the line segment. If the line segment does not intersect the curve at any points between startParam and endParam, then the returned area is positive. If the line segment intersects the curves at any points between startParam and endParam, then the returned area is the sum of the sub-areas created by the intersection of the line segment with the curve. Each sub-area has a positive or negative area, depending on whether the curve lies above or below the line segment. The total area returned by this function can therefore be positive, negative, or 0. '''
    ...
    def boundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock3d :
      '''Returns the bounding box of the curve. The sides of the returned box are parallel to the coordinate axes. '''
    ...
    def cast (self, *args, **kwargs)-> PyGe.CubicSplineCurve3d :
      '''cast( (Entity3d)arg1) -> CubicSplineCurve3d :

    C++ signature :
        class PyGeCubicSplineCurve3d cast(class PyGeEntity3d)'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def closestPointTo (self, other : PyGe.Point3d | PyGe.Curve3d, tol : PyGe.Tol=None)-> PyGe.Point3d :
      '''Finds the closest point on this curve to the input point. This function is the same as closestPointTo(), except that the closest point is returned as an AcGePointOnCurve3d object.'''
    ...
    def continuityAtKnot (self, *args, **kwargs)-> int :
      '''continuityAtKnot( (SplineEnt3d)arg1, (int)arg2) -> int :

    C++ signature :
        int continuityAtKnot(class PyGeSplineEnt3d {lvalue},int)

continuityAtKnot( (SplineEnt3d)arg1, (int)arg2, (Tol)arg3) -> int :

    C++ signature :
        int continuityAtKnot(class PyGeSplineEnt3d {lvalue},int,class AcGeTol)'''
    ...
    def controlPointAt (self, *args, **kwargs)-> PyGe.Point3d :
      '''controlPointAt( (SplineEnt3d)arg1, (int)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d controlPointAt(class PyGeSplineEnt3d {lvalue},int)'''
    ...
    def copy (self)-> PyGe.Entity3d :
      '''Returns a pointer to a copy of this entity. This copy is created using the new and it is the responsibility of the caller to delete it.'''
    ...
    def copycast (self, *args, **kwargs)-> PyGe.CubicSplineCurve3d :
      '''copycast( (Entity3d)arg1) -> CubicSplineCurve3d :

    C++ signature :
        class PyGeCubicSplineCurve3d copycast(class PyGeEntity3d)'''
    ...
    def degree (self, *args, **kwargs)-> int :
      '''degree( (SplineEnt3d)arg1) -> int :

    C++ signature :
        int degree(class PyGeSplineEnt3d {lvalue})'''
    ...
    def distanceTo (self, pt : PyGe.Point3d | PyGe.Curve3d, tol : PyGe.Tol=None)-> float :
      '''Returns the distance between the input point and the closest point on this curve.'''
    ...
    def endParam (self, *args, **kwargs)-> float :
      '''endParam( (SplineEnt3d)arg1) -> float :

    C++ signature :
        double endParam(class PyGeSplineEnt3d {lvalue})'''
    ...
    def endPoint (self, *args, **kwargs)-> PyGe.Point3d :
      '''endPoint( (SplineEnt3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d endPoint(class PyGeSplineEnt3d {lvalue})'''
    ...
    def evalPoint (self, param : float, numDeriv : int = 1)-> PyGe.Point3d :
      '''Returns the point on the curve that corresponds to the input parameter value. Also returns the number of derivative vectors that are specified in numDeriv. The numDeriv parameter should not be set larger than 2.'''
    ...
    def explode (self, val : PyGe.Interval = None)-> list :
      '''Explodes the curve into its individual components. If the curve is a composite curve, then explodedCurves contains the list of component curves of the composite. If the curve is a spline, then it is exploded at the points of C1 discontinuity and explodedCurves contains a copy of each continuous sub-curve. This function returns Adesk::kTrue if the curve was exploded (that is, the curve was a composite or a discontinuous spline) and Adesk::kFalse otherwise. The number of entries returned in newExplodedCurves is always the same as the number of entries in explodedCurves. Each flag in newExplodedCurves indicates whether the corresponding curve in explodedCurves was created with the new operator. If the flag is 1, then it is the responsibility of the caller to delete the curve. If the flag is 0, the curve is deleted by gelib and the caller should not attempt to delete it. If no intrvl parameter is supplied, then the interval is taken to be the entire curve. '''
    ...
    def firstDerivAt (self, *args, **kwargs)-> PyGe.Vector3d :
      '''firstDerivAt( (CubicSplineCurve3d)arg1, (int)arg2) -> Vector3d :

    C++ signature :
        class AcGeVector3d firstDerivAt(class PyGeCubicSplineCurve3d {lvalue},int)'''
    ...
    def fitPointAt (self, *args, **kwargs)-> PyGe.Point3d :
      '''fitPointAt( (CubicSplineCurve3d)arg1, (int)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d fitPointAt(class PyGeCubicSplineCurve3d {lvalue},int)'''
    ...
    def getClosestPointTo (self, other : PyGe.Point3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''Finds the closest point on this curve to the input point. This function is the same as closestPointTo(), except that the closest point is returned as an AcGePointOnCurve3d object.'''
    ...
    def getClosestPointsTo (self, other : PyGe.Curve3d, tol : PyGe.Tol=None)-> tuple :
      '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
    ...
    def getEndPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def getInterval (self)-> PyGe.Interval :
      '''Returns the parametric range of the curve. The function evalPoint(double) always returns a point on this curve when called with a value within the returned interval.'''
    ...
    def getNormalPoint (self, pnt : PyGe.Point3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''Finds the point on the input curve whose normal passes through the input point. The returned point lies on a plane that also contains the input point and is perpendicular to the curve tangent at that point. The returned point is therefore at a local minimum or a local maximum from the input point. The curve does not need to be planar. If the curve is planar, the input point does not need to lie in the plane of the curve. On input, the second parameter is assumed to contain the parameter value of an initial guess. If there is more than one normal point on the curve, the returned point will be the one whose parameter value is closest to the input parameter value.'''
    ...
    def getProjClosestPointTo (self, pt : PyGe.Point3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
    ...
    def getProjClosestPointsTo (self, pt : PyGe.Curve3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> tuple :
      '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
    ...

    @overload
    def getSamplePoints (self, numSample: int)-> tuple : ...
    @overload
    def getSamplePoints (self, fromParam: float, toParam: float, approxEps: float)-> tuple : ...
    def getSamplePoints (self, *args, **kwargs)-> tuple :
      '''Overloads:
    - numSample: int
    - fromParam: float, toParam: float, approxEps: float
    
	-Returns the specified number of points on the curve. The points are equally spaced by parameter value. So if the interval of the curve [0,1] and numSample is 5, the parameter values of the returned points are 0, 0.25, 0.5, 0.75, and 1.-'''
    ...
    def getSplitCurves (self, param : float)-> tuple :
      '''Returns two segments which are obtained by splitting the curve at the input parameter value. If the specified parameter value does not lie within the parametric interval of the curve or if it corresponds to the start point or endpoint of the curve, then piece1 and piece2 are set to null. This function uses the new to create the curve segments whose addresses are returned in piece1 and piece2. It is the responsibility of the caller to delete these objects. '''
    ...
    def getStartPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def getTrimmedOffset (self, dist : float, planeNormal : PyGe.Vector3d, extensionType : PyGe.OffsetCrvExtType, tol : PyGe.Tol=None)-> list :
      '''Returns one or more offset curves that represent the trimmed offset of the curve. The curve must be planar and planeNormal must be perpendicular to the plane of the curve. The positive direction of offset at a point on the curve is taken to be the cross product of planeNormal with the tangent vector at that point. The curve may be offset in either of two directions by specifying a positive or negative offset distance; planeNormal determines which direction is the positive direction of offset. The returned offset curves are trimmed so that they do not contain any points of self-intersection. Each curve that is returned in offsetCurveList is created with the new and it is the responsibility of the caller to delete these curves. Each curve that is returned in offsetCurveList is a connected curve and may be a composite curve if the offset curve had to be trimmed to remove self-intersecting loops. offsetCurveList only contains more than one curve if the offset operation produces multiple curves which are not connected. If the original curve contains points of C1 discontinuity and the direction of offset causes the offset curve to be disjoint (for instance, if the original curve is a composite curve that is a rectangle and the direction of offset is to the outside of the rectangle), then the offset curve is closed with an arc or a line segment, or the curves are simply extended depending on the value of extensionType.'''
    ...
    def hasEndPoint (self)-> bool :
      '''Returns Adesk::kTrue if curve has an endpoint. A return value of Adesk::kFalse means that the parametric interval of the curve does not have an upper bound. The endPnt parameter contains meaningful data only if this function returns a value of Adesk::kTrue.'''
    ...
    def hasFitData (self, *args, **kwargs)-> bool :
      '''hasFitData( (SplineEnt3d)arg1) -> bool :

    C++ signature :
        bool hasFitData(class PyGeSplineEnt3d {lvalue})'''
    ...
    def hasStartPoint (self)-> bool :
      '''Returns Adesk::kTrue if curve has a start point. A return value of Adesk::kFalse means that the parametric interval of the curve does not have a lower bound. The startPnt parameter contains meaningful data only if this function returns a value of Adesk::kTrue.'''
    ...
    def isClosed (self, tol : PyGe.Tol=None)-> bool :
      '''Determines if start point and endpoint of curve are the same.'''
    ...
    def isCoplanarWith (self, curve : PyGe.Curve3d, tol : PyGe.Tol=None)-> tuple :
      '''Returns Adesk::kTrue if both curve are planar and lie in the same plane. The plane parameter is only valid if this function returns a value of Adesk::kTrue.'''
    ...
    def isDegenerate (self, tol : PyGe.Tol=None)-> tuple :
      '''Determines if the curve is degenerate and if so returns the type of entity which the curve degenerates into. For example, if the curve is a circle with a radius of 0 then degenerateType is set to AcGe::kPoint3d. If the curve is an ellipse with a minor radius of 0 and a major radius of 1, then degenerateType is set to AcGe::kLineSeg3d. The degenerateType parameter is only set to something meaningful when this function returns a value of Adesk::kTrue.'''
    ...
    def isEqualTo (self, val : PyGe.Entity3d, tol : PyGe.Tol=None)-> bool :
      '''Determines if two entities are equal to each other. Two entities are considered to be equal only if they are of the same type and they represent the same 3D point set. For instance, if the two entities are of types AcGeCircArc3d and AcGeEllipArc3d then they are not considered equal even if the ellipse is completely coincident with the circle. Also, two curves are not considered equal unless they have the same parameterization. For instance, two infinite coincident lines are not considered equal if they have different scaling in their parameterization. '''
    ...
    def isKindOf (self, val : PyGe.EntityId)-> bool :
      '''                             '''
    ...
    def isLinear (self, tol : PyGe.Tol=None)-> tuple :
      '''Determines if curve is linear. This function returns an infinite line even if the curve is not infinite. The line parameter contains meaningful data only if this function returns a value of Adesk::kTrue.'''
    ...
    def isNull (self)-> bool :
      '''                             '''
    ...
    def isOn (self, pt : float | PyGe.Point3d, tol : PyGe.Tol=None)-> tuple :
      '''Determines if input parameter value is within valid parametric range of curve.'''
    ...
    def isPeriodic (self)-> tuple :
      '''Determines if the curve is periodic. The curve is periodic if and only if it is closed and the two points evalPoint(t) and evalPoint(t+period) are always the same point for all values of t.'''
    ...
    def isPlanar (self, tol : PyGe.Tol=None)-> tuple :
      '''Determines if curve is planar. If the curve is a line, then this function returns an arbitrary plane that contains the line. The plane parameter contains meaningful data only if this function returns a value of Adesk::kTrue. '''
    ...
    def isRational (self, *args, **kwargs)-> bool :
      '''isRational( (SplineEnt3d)arg1) -> bool :

    C++ signature :
        bool isRational(class PyGeSplineEnt3d {lvalue})'''
    ...
    def knotAt (self, *args, **kwargs)-> float :
      '''knotAt( (SplineEnt3d)arg1, (int)arg2) -> float :

    C++ signature :
        double knotAt(class PyGeSplineEnt3d {lvalue},int)'''
    ...
    def knots (self, *args, **kwargs)-> PyGe.KnotVector :
      '''knots( (SplineEnt3d)arg1) -> KnotVector :

    C++ signature :
        class PyGeKnotVector knots(class PyGeSplineEnt3d {lvalue})'''
    ...
    def length (self, frm : float, to : float, tol : float = None)-> float :
      '''Returns the arc length of the curve between the two parameter values.'''
    ...
    def mirror (self, val : PyGe.Plane)-> None :
      '''Transforms the entity by mirroring it across the input plane.'''
    ...
    def numControlPoints (self, *args, **kwargs)-> int :
      '''numControlPoints( (SplineEnt3d)arg1) -> int :

    C++ signature :
        int numControlPoints(class PyGeSplineEnt3d {lvalue})'''
    ...
    def numFitPoints (self, *args, **kwargs)-> int :
      '''numFitPoints( (CubicSplineCurve3d)arg1) -> int :

    C++ signature :
        int numFitPoints(class PyGeCubicSplineCurve3d {lvalue})'''
    ...
    def numKnots (self, *args, **kwargs)-> int :
      '''numKnots( (SplineEnt3d)arg1) -> int :

    C++ signature :
        int numKnots(class PyGeSplineEnt3d {lvalue})'''
    ...
    def order (self, *args, **kwargs)-> int :
      '''order( (SplineEnt3d)arg1) -> int :

    C++ signature :
        int order(class PyGeSplineEnt3d {lvalue})'''
    ...
    def orthoBoundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock3d :
      '''Returns the bounding box of the curve. The sides of the returned box are parallel to the coordinate axes.'''
    ...
    def orthoProject (self, projectionPlane : PyGe.Plane, tol : PyGe.Tol=None)-> PyGe.Entity3d :
      '''Returns the entity that is the orthogonal projection of the curve onto the projection plane. The returned entity may not be of the same type as the original curve and may not even be a curve (for instance, a line projects into a point if it is orthogonal to the projection plane). The returned entity is created with the new and it is the responsibility of the caller to delete it.'''
    ...
    def paramAtLength (self, datumParam : float, length : float, posParamDir : bool=True, tol : float = default)-> float :
      '''Returns the parameter value of the point whose arc length distance (from the point with parameter value datumParam) is the input length. In other words, ift = paramAtLength (datumParam, len, posParamDir, tol) then length (t, datumParam, tol) is (approximately) equal to len. If posParamDir is set to Adesk::kTrue, then the returned parameter value is greater than datumParam. Otherwise it will be less than datumParam. '''
    ...
    def paramOf (self, pt : PyGe.Point3d, tol : PyGe.Tol=None)-> float :
      '''Returns the parameter value of pnt. This function assumes that pnt lies on the curve and does not verify this. If pnt does not lie on the curve, this function will return unpredictable results. If it is not known whether pnt lies on the curve, the user should not call this function but should instead call AcGeCurve3d::isOn (pnt, param, tol). '''
    ...
    def projClosestPointTo (self, pt : PyGe.Point3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.Point3d :
      '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
    ...
    def projClosestPointsTo (self, pt : PyGe.Curve3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> tuple :
      '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
    ...
    def project (self, projectionPlane : PyGe.Plane, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.Entity3d :
      '''Returns the entity that is the projection of the curve onto the projection plane in the specified direction. The projectDirection vector must not be parallel to the projection plane. The returned entity may not be of the same type as the original curve and may not even be a curve (for instance, a line projects into a point if it is parallel to projectDirection). The returned entity is created with the new and it is the responsibility of the caller to delete it.'''
    ...
    def reverseParam (self)-> None :
      '''Reverses the parametric direction of the curve. The point set of the curve is unchanged, but the direction of the curve is reversed.'''
    ...
    def rotateBy (self, angle : float, vec : PyGe.Vector3d, pt : PyGe.Point3d = 'origin')-> None :
      '''Rotates the entity by the input angle about the line defined by the input point and vector.'''
    ...
    def scaleBy (self, scaleFactor : float, pt : PyGe.Point3d = 'origin')-> None :
      '''Scales the entity about the input point by the input scale factor. Input scale factor must be greater than 0.'''
    ...
    def setControlPointAt (self, *args, **kwargs)-> None :
      '''setControlPointAt( (SplineEnt3d)arg1, (int)arg2, (Point3d)arg3) -> None :

    C++ signature :
        void setControlPointAt(class PyGeSplineEnt3d {lvalue},int,class AcGePoint3d)'''
    ...
    def setFirstDerivAt (self, *args, **kwargs)-> None :
      '''setFirstDerivAt( (CubicSplineCurve3d)arg1, (int)arg2, (Vector3d)arg3) -> None :

    C++ signature :
        void setFirstDerivAt(class PyGeCubicSplineCurve3d {lvalue},int,class AcGeVector3d)'''
    ...
    def setFitPointAt (self, *args, **kwargs)-> None :
      '''setFitPointAt( (CubicSplineCurve3d)arg1, (int)arg2, (Point3d)arg3) -> None :

    C++ signature :
        void setFitPointAt(class PyGeCubicSplineCurve3d {lvalue},int,class AcGePoint3d)'''
    ...
    def setInterval (self, val : PyGe.Interval = None)-> None :
      '''Sets the domain of the curve to the input interval.'''
    ...
    def setKnotAt (self, *args, **kwargs)-> None :
      '''setKnotAt( (SplineEnt3d)arg1, (int)arg2, (float)arg3) -> None :

    C++ signature :
        void setKnotAt(class PyGeSplineEnt3d {lvalue},int,double)'''
    ...
    def startParam (self, *args, **kwargs)-> float :
      '''startParam( (SplineEnt3d)arg1) -> float :

    C++ signature :
        double startParam(class PyGeSplineEnt3d {lvalue})'''
    ...
    def startPoint (self, *args, **kwargs)-> PyGe.Point3d :
      '''startPoint( (SplineEnt3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d startPoint(class PyGeSplineEnt3d {lvalue})'''
    ...
    def transformBy (self, val : PyGe.Matrix3d)-> None :
      '''Transforms the entity by applying the input matrix.'''
    ...
    def translateBy (self, vec : PyGe.Vector3d)-> None :
      '''Translates the entity by the input vector.'''
    ...
    def type (self)-> PyGe.EntityId :
      '''Returns the type of the entity.'''
    ...

class Curve2d(Entity2d):
    def __init__ (self, *args, **kwargs)-> None :
      '''Raises an exception
This class cannot be instantiated from Python'''
    ...
    def area (self, startParam : float, endParam : float, tol : float = None)-> float :
      '''                             '''
    ...
    def boundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock2d :
      '''                             '''
    ...

    @staticmethod
    def cast (otherObject: PyGe.Curve2d)-> PyGe.Curve2d :
      '''                             '''
    ...

    @staticmethod
    def className ()-> str :
      '''                             '''
    ...
    def closestPointTo (self, other : PyGe.Point2d | PyGe.Curve2d, tol : PyGe.Tol=None)-> PyGe.Point2d :
      '''                             '''
    ...
    def copy (self)-> PyGe.Entity2d :
      '''                             '''
    ...

    @staticmethod
    def copycast (otherObject: PyGe.Curve2d)-> PyGe.Curve2d :
      '''                             '''
    ...
    def distanceTo (self, pt : PyGe.Point2d | PyGe.Curve2d, tol : PyGe.Tol=None)-> float :
      '''                             '''
    ...
    def evalPoint (self, param : float, numDeriv : int = 1)-> PyGe.Point2d :
      '''                             '''
    ...
    def explode (self, val : PyGe.Interval = None)-> list :
      '''                             '''
    ...
    def getClosestPointTo (self, other : PyGe.Point2d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve2d :
      '''                             '''
    ...
    def getClosestPointsTo (self, other : PyGe.Curve2d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def getEndPoint (self)-> PyGe.Point2d :
      '''                             '''
    ...
    def getInterval (self)-> PyGe.Interval :
      '''                             '''
    ...
    def getNormalPoint (self, pnt : PyGe.Point2d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve2d :
      '''                             '''
    ...

    @overload
    def getSamplePoints (self, numSample: int)-> list : ...
    @overload
    def getSamplePoints (self, fromParam: float, toParam: float, approxEps: float)-> list : ...
    def getSamplePoints (self, *args, **kwargs)-> list :
      '''Overloads:
    - numSample: int
    - fromParam: float, toParam: float, approxEps: float
    '''
    ...
    def getSplitCurves (self, param : float)-> tuple :
      '''                             '''
    ...
    def getStartPoint (self)-> PyGe.Point2d :
      '''                             '''
    ...
    def getTrimmedOffset (self, dist : float, extensionType : PyGe.OffsetCrvExtType, tol : PyGe.Tol=None)-> list :
      '''                             '''
    ...
    def hasEndPoint (self)-> bool :
      '''                             '''
    ...
    def hasStartPoint (self)-> bool :
      '''                             '''
    ...
    def isClosed (self, tol : PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def isDegenerate (self, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isEqualTo (self, val : PyGe.Entity2d, tol : PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def isKindOf (self, val : PyGe.EntityId)-> bool :
      '''                             '''
    ...
    def isLinear (self, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isNull (self)-> bool :
      '''                             '''
    ...
    def isOn (self, pt : float | PyGe.Point2d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isPeriodic (self)-> tuple :
      '''                             '''
    ...
    def length (self, frm : float, to : float, tol : float = None)-> float :
      '''                             '''
    ...
    def mirror (self, val : PyGe.Line2d)-> None :
      '''                             '''
    ...
    def orthoBoundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock2d :
      '''                             '''
    ...
    def paramAtLength (self, datumParam: float, length: float, posParamDir: bool=True, tol: float=None)-> float :
      '''                             '''
    ...
    def paramOf (self, pt : PyGe.Point2d, tol : PyGe.Tol=None)-> float :
      '''                             '''
    ...
    def reverseParam (self)-> None :
      '''                             '''
    ...
    def rotateBy (self, angle : float, pt : PyGe.Point3d=PyGe.Point2d.kOrgin)-> None :
      '''                             '''
    ...
    def scaleBy (self, scaleFactor : float, pt : PyGe.Point2d=PyGe.Point2d.kOrgin)-> None :
      '''                             '''
    ...
    def setInterval (self, val : PyGe.Interval = None)-> None :
      '''                             '''
    ...
    def transformBy (self, val : PyGe.Matrix2d)-> None :
      '''                             '''
    ...
    def translateBy (self, vec : PyGe.Vector2d)-> None :
      '''                             '''
    ...
    def type (self)-> PyGe.EntityId :
      '''                             '''
    ...

class Curve3d(Entity3d):
    def __init__ (self, *args, **kwargs)-> None :
      '''Raises an exception
This class cannot be instantiated from Python'''
    ...
    def area (self, startParam : float, endParam : float, tol : float = None)-> float :
      '''Returns the area of the interval of the curve defined by startParam and endParam. Returns Adesk::kTrue if area was successfully computed to within the specified tolerance. If the curve is not planar, then the area cannot be calculated and a value of Adesk::kFalse is returned. If the points at startParam and endParam are the same, then this function returns the area of the closed curve. If the points are different, then this function connects the two points with a line segment and return the signed area between the curve and the line segment. If the line segment does not intersect the curve at any points between startParam and endParam, then the returned area is positive. If the line segment intersects the curves at any points between startParam and endParam, then the returned area is the sum of the sub-areas created by the intersection of the line segment with the curve. Each sub-area has a positive or negative area, depending on whether the curve lies above or below the line segment. The total area returned by this function can therefore be positive, negative, or 0. '''
    ...
    def boundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock3d :
      '''Returns the bounding box of the curve. The sides of the returned box are parallel to the coordinate axes. '''
    ...

    @staticmethod
    def cast (otherObject: PyGe.Curve3d)-> PyGe.Curve3d :
      '''                             '''
    ...

    @staticmethod
    def className ()-> str :
      '''                             '''
    ...
    def closestPointTo (self, other : PyGe.Point3d | PyGe.Curve3d, tol : PyGe.Tol=None)-> PyGe.Point3d :
      '''Finds the closest point on this curve to the input point. This function is the same as closestPointTo(), except that the closest point is returned as an AcGePointOnCurve3d object.'''
    ...
    def copy (self)-> PyGe.Entity3d :
      '''Returns a pointer to a copy of this entity. This copy is created using the new and it is the responsibility of the caller to delete it.'''
    ...

    @staticmethod
    def copycast (otherObject: PyGe.Curve3d)-> PyGe.Curve3d :
      '''                             '''
    ...
    def distanceTo (self, pt : PyGe.Point3d | PyGe.Curve3d, tol : PyGe.Tol=None)-> float :
      '''Returns the distance between the input point and the closest point on this curve.'''
    ...
    def evalPoint (self, param : float, numDeriv : int = 1)-> PyGe.Point3d :
      '''Returns the point on the curve that corresponds to the input parameter value. Also returns the number of derivative vectors that are specified in numDeriv. The numDeriv parameter should not be set larger than 2.'''
    ...
    def explode (self, val : PyGe.Interval = None)-> list :
      '''Explodes the curve into its individual components. If the curve is a composite curve, then explodedCurves contains the list of component curves of the composite. If the curve is a spline, then it is exploded at the points of C1 discontinuity and explodedCurves contains a copy of each continuous sub-curve. This function returns Adesk::kTrue if the curve was exploded (that is, the curve was a composite or a discontinuous spline) and Adesk::kFalse otherwise. The number of entries returned in newExplodedCurves is always the same as the number of entries in explodedCurves. Each flag in newExplodedCurves indicates whether the corresponding curve in explodedCurves was created with the new operator. If the flag is 1, then it is the responsibility of the caller to delete the curve. If the flag is 0, the curve is deleted by gelib and the caller should not attempt to delete it. If no intrvl parameter is supplied, then the interval is taken to be the entire curve. '''
    ...
    def getClosestPointTo (self, other : PyGe.Point3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''Finds the closest point on this curve to the input point. This function is the same as closestPointTo(), except that the closest point is returned as an AcGePointOnCurve3d object.'''
    ...
    def getClosestPointsTo (self, other : PyGe.Curve3d, tol : PyGe.Tol=None)-> tuple :
      '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
    ...
    def getEndPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def getInterval (self)-> PyGe.Interval :
      '''Returns the parametric range of the curve. The function evalPoint(double) always returns a point on this curve when called with a value within the returned interval.'''
    ...
    def getNormalPoint (self, pnt : PyGe.Point3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''Finds the point on the input curve whose normal passes through the input point. The returned point lies on a plane that also contains the input point and is perpendicular to the curve tangent at that point. The returned point is therefore at a local minimum or a local maximum from the input point. The curve does not need to be planar. If the curve is planar, the input point does not need to lie in the plane of the curve. On input, the second parameter is assumed to contain the parameter value of an initial guess. If there is more than one normal point on the curve, the returned point will be the one whose parameter value is closest to the input parameter value.'''
    ...
    def getProjClosestPointTo (self, pt : PyGe.Point3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
    ...
    def getProjClosestPointsTo (self, pt : PyGe.Curve3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> tuple :
      '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
    ...

    @overload
    def getSamplePoints (self, numSample: int)-> tuple : ...
    @overload
    def getSamplePoints (self, fromParam: float, toParam: float, approxEps: float)-> tuple : ...
    def getSamplePoints (self, *args, **kwargs)-> tuple :
      '''Overloads:
    - numSample: int
    - fromParam: float, toParam: float, approxEps: float
    
	-Returns the specified number of points on the curve. The points are equally spaced by parameter value. So if the interval of the curve [0,1] and numSample is 5, the parameter values of the returned points are 0, 0.25, 0.5, 0.75, and 1.-'''
    ...
    def getSplitCurves (self, param : float)-> tuple :
      '''Returns two segments which are obtained by splitting the curve at the input parameter value. If the specified parameter value does not lie within the parametric interval of the curve or if it corresponds to the start point or endpoint of the curve, then piece1 and piece2 are set to null. This function uses the new to create the curve segments whose addresses are returned in piece1 and piece2. It is the responsibility of the caller to delete these objects. '''
    ...
    def getStartPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def getTrimmedOffset (self, dist : float, planeNormal : PyGe.Vector3d, extensionType : PyGe.OffsetCrvExtType, tol : PyGe.Tol=None)-> list :
      '''Returns one or more offset curves that represent the trimmed offset of the curve. The curve must be planar and planeNormal must be perpendicular to the plane of the curve. The positive direction of offset at a point on the curve is taken to be the cross product of planeNormal with the tangent vector at that point. The curve may be offset in either of two directions by specifying a positive or negative offset distance; planeNormal determines which direction is the positive direction of offset. The returned offset curves are trimmed so that they do not contain any points of self-intersection. Each curve that is returned in offsetCurveList is created with the new and it is the responsibility of the caller to delete these curves. Each curve that is returned in offsetCurveList is a connected curve and may be a composite curve if the offset curve had to be trimmed to remove self-intersecting loops. offsetCurveList only contains more than one curve if the offset operation produces multiple curves which are not connected. If the original curve contains points of C1 discontinuity and the direction of offset causes the offset curve to be disjoint (for instance, if the original curve is a composite curve that is a rectangle and the direction of offset is to the outside of the rectangle), then the offset curve is closed with an arc or a line segment, or the curves are simply extended depending on the value of extensionType.'''
    ...
    def hasEndPoint (self)-> bool :
      '''Returns Adesk::kTrue if curve has an endpoint. A return value of Adesk::kFalse means that the parametric interval of the curve does not have an upper bound. The endPnt parameter contains meaningful data only if this function returns a value of Adesk::kTrue.'''
    ...
    def hasStartPoint (self)-> bool :
      '''Returns Adesk::kTrue if curve has a start point. A return value of Adesk::kFalse means that the parametric interval of the curve does not have a lower bound. The startPnt parameter contains meaningful data only if this function returns a value of Adesk::kTrue.'''
    ...
    def isClosed (self, tol : PyGe.Tol=None)-> bool :
      '''Determines if start point and endpoint of curve are the same.'''
    ...
    def isCoplanarWith (self, curve : PyGe.Curve3d, tol : PyGe.Tol=None)-> tuple :
      '''Returns Adesk::kTrue if both curve are planar and lie in the same plane. The plane parameter is only valid if this function returns a value of Adesk::kTrue.'''
    ...
    def isDegenerate (self, tol : PyGe.Tol=None)-> tuple :
      '''Determines if the curve is degenerate and if so returns the type of entity which the curve degenerates into. For example, if the curve is a circle with a radius of 0 then degenerateType is set to AcGe::kPoint3d. If the curve is an ellipse with a minor radius of 0 and a major radius of 1, then degenerateType is set to AcGe::kLineSeg3d. The degenerateType parameter is only set to something meaningful when this function returns a value of Adesk::kTrue.'''
    ...
    def isEqualTo (self, val : PyGe.Entity3d, tol : PyGe.Tol=None)-> bool :
      '''Determines if two entities are equal to each other. Two entities are considered to be equal only if they are of the same type and they represent the same 3D point set. For instance, if the two entities are of types AcGeCircArc3d and AcGeEllipArc3d then they are not considered equal even if the ellipse is completely coincident with the circle. Also, two curves are not considered equal unless they have the same parameterization. For instance, two infinite coincident lines are not considered equal if they have different scaling in their parameterization. '''
    ...
    def isKindOf (self, val : PyGe.EntityId)-> bool :
      '''                             '''
    ...
    def isLinear (self, tol : PyGe.Tol=None)-> tuple :
      '''Determines if curve is linear. This function returns an infinite line even if the curve is not infinite. The line parameter contains meaningful data only if this function returns a value of Adesk::kTrue.'''
    ...
    def isNull (self)-> bool :
      '''                             '''
    ...
    def isOn (self, pt : float | PyGe.Point3d, tol : PyGe.Tol=None)-> tuple :
      '''Determines if input parameter value is within valid parametric range of curve.'''
    ...
    def isPeriodic (self)-> tuple :
      '''Determines if the curve is periodic. The curve is periodic if and only if it is closed and the two points evalPoint(t) and evalPoint(t+period) are always the same point for all values of t.'''
    ...
    def isPlanar (self, tol : PyGe.Tol=None)-> tuple :
      '''Determines if curve is planar. If the curve is a line, then this function returns an arbitrary plane that contains the line. The plane parameter contains meaningful data only if this function returns a value of Adesk::kTrue. '''
    ...
    def length (self, frm : float, to : float, tol : float = None)-> float :
      '''Returns the arc length of the curve between the two parameter values.'''
    ...
    def mirror (self, val : PyGe.Plane)-> None :
      '''Transforms the entity by mirroring it across the input plane.'''
    ...
    def orthoBoundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock3d :
      '''Returns the bounding box of the curve. The sides of the returned box are parallel to the coordinate axes.'''
    ...
    def orthoProject (self, projectionPlane : PyGe.Plane, tol : PyGe.Tol=None)-> PyGe.Entity3d :
      '''Returns the entity that is the orthogonal projection of the curve onto the projection plane. The returned entity may not be of the same type as the original curve and may not even be a curve (for instance, a line projects into a point if it is orthogonal to the projection plane). The returned entity is created with the new and it is the responsibility of the caller to delete it.'''
    ...
    def paramAtLength (self, datumParam : float, length : float, posParamDir : bool=True, tol : float = default)-> float :
      '''Returns the parameter value of the point whose arc length distance (from the point with parameter value datumParam) is the input length. In other words, ift = paramAtLength (datumParam, len, posParamDir, tol) then length (t, datumParam, tol) is (approximately) equal to len. If posParamDir is set to Adesk::kTrue, then the returned parameter value is greater than datumParam. Otherwise it will be less than datumParam. '''
    ...
    def paramOf (self, pt : PyGe.Point3d, tol : PyGe.Tol=None)-> float :
      '''Returns the parameter value of pnt. This function assumes that pnt lies on the curve and does not verify this. If pnt does not lie on the curve, this function will return unpredictable results. If it is not known whether pnt lies on the curve, the user should not call this function but should instead call AcGeCurve3d::isOn (pnt, param, tol). '''
    ...
    def projClosestPointTo (self, pt : PyGe.Point3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.Point3d :
      '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
    ...
    def projClosestPointsTo (self, pt : PyGe.Curve3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> tuple :
      '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
    ...
    def project (self, projectionPlane : PyGe.Plane, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.Entity3d :
      '''Returns the entity that is the projection of the curve onto the projection plane in the specified direction. The projectDirection vector must not be parallel to the projection plane. The returned entity may not be of the same type as the original curve and may not even be a curve (for instance, a line projects into a point if it is parallel to projectDirection). The returned entity is created with the new and it is the responsibility of the caller to delete it.'''
    ...
    def reverseParam (self)-> None :
      '''Reverses the parametric direction of the curve. The point set of the curve is unchanged, but the direction of the curve is reversed.'''
    ...
    def rotateBy (self, angle : float, vec : PyGe.Vector3d, pt : PyGe.Point3d = 'origin')-> None :
      '''Rotates the entity by the input angle about the line defined by the input point and vector.'''
    ...
    def scaleBy (self, scaleFactor : float, pt : PyGe.Point3d = 'origin')-> None :
      '''Scales the entity about the input point by the input scale factor. Input scale factor must be greater than 0.'''
    ...
    def setInterval (self, val : PyGe.Interval = None)-> None :
      '''Sets the domain of the curve to the input interval.'''
    ...
    def transformBy (self, val : PyGe.Matrix3d)-> None :
      '''Transforms the entity by applying the input matrix.'''
    ...
    def translateBy (self, vec : PyGe.Vector3d)-> None :
      '''Translates the entity by the input vector.'''
    ...
    def type (self)-> PyGe.EntityId :
      '''Returns the type of the entity.'''
    ...

class CurveCurveInt2d(Entity2d):
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (Curve2d)arg2, (Curve2d)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class PyGeCurve2d,class PyGeCurve2d)

__init__( (object)arg1, (Curve2d)arg2, (Curve2d)arg3, (Tol)arg4) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class PyGeCurve2d,class PyGeCurve2d,class AcGeTol)

__init__( (object)arg1, (Curve2d)arg2, (Curve2d)arg3, (Interval)arg4, (Interval)arg5) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class PyGeCurve2d,class PyGeCurve2d,class PyGeInterval,class PyGeInterval)

__init__( (object)arg1, (Curve2d)arg2, (Curve2d)arg3, (Interval)arg4, (Interval)arg5, (Tol)arg6) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class PyGeCurve2d,class PyGeCurve2d,class PyGeInterval,class PyGeInterval,class AcGeTol)'''
    ...
    def cast (self, *args, **kwargs)-> PyGe.CurveCurveInt2d :
      '''cast( (Entity2d)arg1) -> CurveCurveInt2d :

    C++ signature :
        class PyGeCurveCurveInt2d cast(class PyGeEntity2d)'''
    ...
    def changeCurveOrder (self, *args, **kwargs)-> None :
      '''changeCurveOrder( (CurveCurveInt2d)arg1) -> None :

    C++ signature :
        void changeCurveOrder(class PyGeCurveCurveInt2d {lvalue})'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def copy (self)-> PyGe.Entity2d :
      '''                             '''
    ...
    def copycast (self, *args, **kwargs)-> PyGe.CurveCurveInt2d :
      '''copycast( (Entity2d)arg1) -> CurveCurveInt2d :

    C++ signature :
        class PyGeCurveCurveInt2d copycast(class PyGeEntity2d)'''
    ...
    def curve1 (self, *args, **kwargs)-> PyGe.Curve2d :
      '''curve1( (CurveCurveInt2d)arg1) -> Curve2d :

    C++ signature :
        class PyGeCurve2d curve1(class PyGeCurveCurveInt2d {lvalue})'''
    ...
    def curve2 (self, *args, **kwargs)-> PyGe.Curve2d :
      '''curve2( (CurveCurveInt2d)arg1) -> Curve2d :

    C++ signature :
        class PyGeCurve2d curve2(class PyGeCurveCurveInt2d {lvalue})'''
    ...
    def getIntConfigs (self, *args, **kwargs)-> tuple :
      '''getIntConfigs( (CurveCurveInt2d)arg1, (int)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getIntConfigs(class PyGeCurveCurveInt2d {lvalue},int)'''
    ...
    def getIntParams (self, *args, **kwargs)-> tuple :
      '''getIntParams( (CurveCurveInt2d)arg1, (int)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getIntParams(class PyGeCurveCurveInt2d {lvalue},int)'''
    ...
    def getIntRanges (self, *args, **kwargs)-> tuple :
      '''getIntRanges( (CurveCurveInt2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple getIntRanges(class PyGeCurveCurveInt2d {lvalue})'''
    ...
    def getOverlapRanges (self, *args, **kwargs)-> tuple :
      '''getOverlapRanges( (CurveCurveInt2d)arg1, (int)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getOverlapRanges(class PyGeCurveCurveInt2d {lvalue},int)'''
    ...
    def getPointOnCurve1 (self, *args, **kwargs)-> PyGe.PointOnCurve2d :
      '''getPointOnCurve1( (CurveCurveInt2d)arg1, (int)arg2) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getPointOnCurve1(class PyGeCurveCurveInt2d {lvalue},int)'''
    ...
    def getPointOnCurve2 (self, *args, **kwargs)-> PyGe.PointOnCurve2d :
      '''getPointOnCurve2( (CurveCurveInt2d)arg1, (int)arg2) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getPointOnCurve2(class PyGeCurveCurveInt2d {lvalue},int)'''
    ...
    def intPoint (self, *args, **kwargs)-> PyGe.Point2d :
      '''intPoint( (CurveCurveInt2d)arg1, (int)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d intPoint(class PyGeCurveCurveInt2d {lvalue},int)'''
    ...
    def intPointTol (self, *args, **kwargs)-> float :
      '''intPointTol( (CurveCurveInt2d)arg1, (int)arg2) -> float :

    C++ signature :
        double intPointTol(class PyGeCurveCurveInt2d {lvalue},int)'''
    ...
    def isEqualTo (self, val : PyGe.Entity2d, tol : PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def isKindOf (self, val : PyGe.EntityId)-> bool :
      '''                             '''
    ...
    def isNull (self)-> bool :
      '''                             '''
    ...
    def isOn (self, pt : PyGe.Point2d, tol : PyGe.Tol=default)-> bool :
      '''                             '''
    ...
    def isTangential (self, *args, **kwargs)-> bool :
      '''isTangential( (CurveCurveInt2d)arg1, (int)arg2) -> bool :

    C++ signature :
        bool isTangential(class PyGeCurveCurveInt2d {lvalue},int)'''
    ...
    def isTransversal (self, *args, **kwargs)-> bool :
      '''isTransversal( (CurveCurveInt2d)arg1, (int)arg2) -> bool :

    C++ signature :
        bool isTransversal(class PyGeCurveCurveInt2d {lvalue},int)'''
    ...
    def mirror (self, val : PyGe.Line2d)-> None :
      '''                             '''
    ...
    def numIntPoints (self, *args, **kwargs)-> int :
      '''numIntPoints( (CurveCurveInt2d)arg1) -> int :

    C++ signature :
        int numIntPoints(class PyGeCurveCurveInt2d {lvalue})'''
    ...
    def orderWrt1 (self, *args, **kwargs)-> PyGe.CurveCurveInt2d :
      '''orderWrt1( (CurveCurveInt2d)arg1) -> CurveCurveInt2d :

    C++ signature :
        class PyGeCurveCurveInt2d orderWrt1(class PyGeCurveCurveInt2d {lvalue})'''
    ...
    def orderWrt2 (self, *args, **kwargs)-> PyGe.CurveCurveInt2d :
      '''orderWrt2( (CurveCurveInt2d)arg1) -> CurveCurveInt2d :

    C++ signature :
        class PyGeCurveCurveInt2d orderWrt2(class PyGeCurveCurveInt2d {lvalue})'''
    ...
    def overlapCount (self, *args, **kwargs)-> int :
      '''overlapCount( (CurveCurveInt2d)arg1) -> int :

    C++ signature :
        int overlapCount(class PyGeCurveCurveInt2d {lvalue})'''
    ...
    def overlapDirection (self, *args, **kwargs)-> bool :
      '''overlapDirection( (CurveCurveInt2d)arg1) -> bool :

    C++ signature :
        bool overlapDirection(class PyGeCurveCurveInt2d {lvalue})'''
    ...
    def rotateBy (self, angle : float, pt : PyGe.Point3d=PyGe.Point2d.kOrgin)-> None :
      '''                             '''
    ...
    def scaleBy (self, scaleFactor : float, pt : PyGe.Point2d=PyGe.Point2d.kOrgin)-> None :
      '''                             '''
    ...
    def tolerance (self, *args, **kwargs)-> PyGe.Tol :
      '''tolerance( (CurveCurveInt2d)arg1) -> Tol :

    C++ signature :
        class AcGeTol tolerance(class PyGeCurveCurveInt2d {lvalue})'''
    ...
    def transformBy (self, val : PyGe.Matrix2d)-> None :
      '''                             '''
    ...
    def translateBy (self, vec : PyGe.Vector2d)-> None :
      '''                             '''
    ...
    def type (self)-> PyGe.EntityId :
      '''                             '''
    ...

class CurveCurveInt3d(Entity3d):
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (Curve3d)arg2, (Curve3d)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class PyGeCurve3d,class PyGeCurve3d)

__init__( (object)arg1, (Curve3d)arg2, (Curve3d)arg3, (Vector3d)arg4, (Tol)arg5) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class PyGeCurve3d,class PyGeCurve3d,class AcGeVector3d,class AcGeTol)

__init__( (object)arg1, (Curve3d)arg2, (Curve3d)arg3, (Interval)arg4, (Interval)arg5) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class PyGeCurve3d,class PyGeCurve3d,class PyGeInterval,class PyGeInterval)

__init__( (object)arg1, (Curve3d)arg2, (Curve3d)arg3, (Interval)arg4, (Interval)arg5, (Vector3d)arg6, (Tol)arg7) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class PyGeCurve3d,class PyGeCurve3d,class PyGeInterval,class PyGeInterval,class AcGeVector3d,class AcGeTol)'''
    ...
    def cast (self, *args, **kwargs)-> PyGe.CurveCurveInt3d :
      '''cast( (Entity3d)arg1) -> CurveCurveInt3d :

    C++ signature :
        class PyGeCurveCurveInt3d cast(class PyGeEntity3d)'''
    ...
    def changeCurveOrder (self, *args, **kwargs)-> None :
      '''changeCurveOrder( (CurveCurveInt3d)arg1) -> None :

    C++ signature :
        void changeCurveOrder(class PyGeCurveCurveInt3d {lvalue})'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def copy (self)-> PyGe.Entity3d :
      '''Returns a pointer to a copy of this entity. This copy is created using the new and it is the responsibility of the caller to delete it.'''
    ...
    def copycast (self, *args, **kwargs)-> PyGe.CurveCurveInt3d :
      '''copycast( (Entity3d)arg1) -> CurveCurveInt3d :

    C++ signature :
        class PyGeCurveCurveInt3d copycast(class PyGeEntity3d)'''
    ...
    def curve1 (self, *args, **kwargs)-> PyGe.Curve3d :
      '''curve1( (CurveCurveInt3d)arg1) -> Curve3d :

    C++ signature :
        class PyGeCurve3d curve1(class PyGeCurveCurveInt3d {lvalue})'''
    ...
    def curve2 (self, *args, **kwargs)-> PyGe.Curve3d :
      '''curve2( (CurveCurveInt3d)arg1) -> Curve3d :

    C++ signature :
        class PyGeCurve3d curve2(class PyGeCurveCurveInt3d {lvalue})'''
    ...
    def getIntConfigs (self, *args, **kwargs)-> tuple :
      '''getIntConfigs( (CurveCurveInt3d)arg1, (int)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getIntConfigs(class PyGeCurveCurveInt3d {lvalue},int)'''
    ...
    def getIntParams (self, *args, **kwargs)-> tuple :
      '''getIntParams( (CurveCurveInt3d)arg1, (int)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getIntParams(class PyGeCurveCurveInt3d {lvalue},int)'''
    ...
    def getIntRanges (self, *args, **kwargs)-> tuple :
      '''getIntRanges( (CurveCurveInt3d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple getIntRanges(class PyGeCurveCurveInt3d {lvalue})'''
    ...
    def getOverlapRanges (self, *args, **kwargs)-> tuple :
      '''getOverlapRanges( (CurveCurveInt3d)arg1, (int)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getOverlapRanges(class PyGeCurveCurveInt3d {lvalue},int)'''
    ...
    def getPointOnCurve1 (self, *args, **kwargs)-> PyGe.PointOnCurve3d :
      '''getPointOnCurve1( (CurveCurveInt3d)arg1, (int)arg2) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getPointOnCurve1(class PyGeCurveCurveInt3d {lvalue},int)'''
    ...
    def getPointOnCurve2 (self, *args, **kwargs)-> PyGe.PointOnCurve3d :
      '''getPointOnCurve2( (CurveCurveInt3d)arg1, (int)arg2) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d getPointOnCurve2(class PyGeCurveCurveInt3d {lvalue},int)'''
    ...
    def intPoint (self, *args, **kwargs)-> PyGe.Point3d :
      '''intPoint( (CurveCurveInt3d)arg1, (int)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d intPoint(class PyGeCurveCurveInt3d {lvalue},int)'''
    ...
    def intPointTol (self, *args, **kwargs)-> float :
      '''intPointTol( (CurveCurveInt3d)arg1, (int)arg2) -> float :

    C++ signature :
        double intPointTol(class PyGeCurveCurveInt3d {lvalue},int)'''
    ...
    def isEqualTo (self, val : PyGe.Entity3d, tol : PyGe.Tol=None)-> bool :
      '''Determines if two entities are equal to each other. Two entities are considered to be equal only if they are of the same type and they represent the same 3D point set. For instance, if the two entities are of types AcGeCircArc3d and AcGeEllipArc3d then they are not considered equal even if the ellipse is completely coincident with the circle. Also, two curves are not considered equal unless they have the same parameterization. For instance, two infinite coincident lines are not considered equal if they have different scaling in their parameterization. '''
    ...
    def isKindOf (self, val : PyGe.EntityId)-> bool :
      '''                             '''
    ...
    def isNull (self)-> bool :
      '''                             '''
    ...
    def isOn (self, pt : PyGe.Point3d, tol : PyGe.Tol=default)-> bool :
      '''Returns Adesk::kTrue if pnt lies on entity; otherwise, returns Adesk::kFalse.'''
    ...
    def isTangential (self, *args, **kwargs)-> bool :
      '''isTangential( (CurveCurveInt3d)arg1, (int)arg2) -> bool :

    C++ signature :
        bool isTangential(class PyGeCurveCurveInt3d {lvalue},int)'''
    ...
    def isTransversal (self, *args, **kwargs)-> bool :
      '''isTransversal( (CurveCurveInt3d)arg1, (int)arg2) -> bool :

    C++ signature :
        bool isTransversal(class PyGeCurveCurveInt3d {lvalue},int)'''
    ...
    def mirror (self, val : PyGe.Plane)-> None :
      '''Transforms the entity by mirroring it across the input plane.'''
    ...
    def numIntPoints (self, *args, **kwargs)-> int :
      '''numIntPoints( (CurveCurveInt3d)arg1) -> int :

    C++ signature :
        int numIntPoints(class PyGeCurveCurveInt3d {lvalue})'''
    ...
    def orderWrt1 (self, *args, **kwargs)-> PyGe.CurveCurveInt3d :
      '''orderWrt1( (CurveCurveInt3d)arg1) -> CurveCurveInt3d :

    C++ signature :
        class PyGeCurveCurveInt3d orderWrt1(class PyGeCurveCurveInt3d {lvalue})'''
    ...
    def orderWrt2 (self, *args, **kwargs)-> PyGe.CurveCurveInt3d :
      '''orderWrt2( (CurveCurveInt3d)arg1) -> CurveCurveInt3d :

    C++ signature :
        class PyGeCurveCurveInt3d orderWrt2(class PyGeCurveCurveInt3d {lvalue})'''
    ...
    def overlapCount (self, *args, **kwargs)-> int :
      '''overlapCount( (CurveCurveInt3d)arg1) -> int :

    C++ signature :
        int overlapCount(class PyGeCurveCurveInt3d {lvalue})'''
    ...
    def overlapDirection (self, *args, **kwargs)-> bool :
      '''overlapDirection( (CurveCurveInt3d)arg1) -> bool :

    C++ signature :
        bool overlapDirection(class PyGeCurveCurveInt3d {lvalue})'''
    ...
    def planeNormal (self, *args, **kwargs)-> PyGe.Vector3d :
      '''planeNormal( (CurveCurveInt3d)arg1) -> Vector3d :

    C++ signature :
        class AcGeVector3d planeNormal(class PyGeCurveCurveInt3d {lvalue})'''
    ...
    def rotateBy (self, angle : float, vec : PyGe.Vector3d, pt : PyGe.Point3d = 'origin')-> None :
      '''Rotates the entity by the input angle about the line defined by the input point and vector.'''
    ...
    def scaleBy (self, scaleFactor : float, pt : PyGe.Point3d = 'origin')-> None :
      '''Scales the entity about the input point by the input scale factor. Input scale factor must be greater than 0.'''
    ...
    def tolerance (self, *args, **kwargs)-> PyGe.Tol :
      '''tolerance( (CurveCurveInt3d)arg1) -> Tol :

    C++ signature :
        class AcGeTol tolerance(class PyGeCurveCurveInt3d {lvalue})'''
    ...
    def transformBy (self, val : PyGe.Matrix3d)-> None :
      '''Transforms the entity by applying the input matrix.'''
    ...
    def translateBy (self, vec : PyGe.Vector3d)-> None :
      '''Translates the entity by the input vector.'''
    ...
    def type (self)-> PyGe.EntityId :
      '''Returns the type of the entity.'''
    ...

class CurveSurfInt(Entity3d):
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (Curve3d)arg2, (Surface)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class PyGeCurve3d,class PyGeSurface)

__init__( (object)arg1, (Curve3d)arg2, (Surface)arg3, (Tol)arg4) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class PyGeCurve3d,class PyGeSurface,class AcGeTol)'''
    ...
    def cast (self, *args, **kwargs)-> PyGe.CurveSurfInt :
      '''cast( (Entity3d)arg1) -> CurveSurfInt :

    C++ signature :
        class PyGeCurveSurfInt cast(class PyGeEntity3d)'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def copy (self)-> PyGe.Entity3d :
      '''Returns a pointer to a copy of this entity. This copy is created using the new and it is the responsibility of the caller to delete it.'''
    ...
    def copycast (self, *args, **kwargs)-> PyGe.CurveSurfInt :
      '''copycast( (Entity3d)arg1) -> CurveSurfInt :

    C++ signature :
        class PyGeCurveSurfInt copycast(class PyGeEntity3d)'''
    ...
    def curve (self, *args, **kwargs)-> PyGe.Curve3d :
      '''curve( (CurveSurfInt)arg1) -> Curve3d :

    C++ signature :
        class PyGeCurve3d curve(class PyGeCurveSurfInt {lvalue})'''
    ...
    def getIntConfigs (self, *args, **kwargs)-> tuple :
      '''getIntConfigs( (CurveSurfInt)arg1, (int)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getIntConfigs(class PyGeCurveSurfInt {lvalue},int)'''
    ...
    def getIntParams (self, *args, **kwargs)-> tuple :
      '''getIntParams( (CurveSurfInt)arg1, (int)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getIntParams(class PyGeCurveSurfInt {lvalue},int)'''
    ...
    def getPointOnCurve (self, *args, **kwargs)-> tuple :
      '''getPointOnCurve( (CurveSurfInt)arg1, (int)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getPointOnCurve(class PyGeCurveSurfInt {lvalue},int)'''
    ...
    def getPointOnSurface (self, *args, **kwargs)-> tuple :
      '''getPointOnSurface( (CurveSurfInt)arg1, (int)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getPointOnSurface(class PyGeCurveSurfInt {lvalue},int)'''
    ...
    def intPoint (self, *args, **kwargs)-> PyGe.Point3d :
      '''intPoint( (CurveSurfInt)arg1, (int)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d intPoint(class PyGeCurveSurfInt {lvalue},int)'''
    ...
    def isEqualTo (self, val : PyGe.Entity3d, tol : PyGe.Tol=None)-> bool :
      '''Determines if two entities are equal to each other. Two entities are considered to be equal only if they are of the same type and they represent the same 3D point set. For instance, if the two entities are of types AcGeCircArc3d and AcGeEllipArc3d then they are not considered equal even if the ellipse is completely coincident with the circle. Also, two curves are not considered equal unless they have the same parameterization. For instance, two infinite coincident lines are not considered equal if they have different scaling in their parameterization. '''
    ...
    def isKindOf (self, val : PyGe.EntityId)-> bool :
      '''                             '''
    ...
    def isNull (self)-> bool :
      '''                             '''
    ...
    def isOn (self, pt : PyGe.Point3d, tol : PyGe.Tol=default)-> bool :
      '''Returns Adesk::kTrue if pnt lies on entity; otherwise, returns Adesk::kFalse.'''
    ...
    def mirror (self, val : PyGe.Plane)-> None :
      '''Transforms the entity by mirroring it across the input plane.'''
    ...
    def numIntPoints (self, *args, **kwargs)-> int :
      '''numIntPoints( (CurveSurfInt)arg1) -> int :

    C++ signature :
        int numIntPoints(class PyGeCurveSurfInt {lvalue})'''
    ...
    def rotateBy (self, angle : float, vec : PyGe.Vector3d, pt : PyGe.Point3d = 'origin')-> None :
      '''Rotates the entity by the input angle about the line defined by the input point and vector.'''
    ...
    def scaleBy (self, scaleFactor : float, pt : PyGe.Point3d = 'origin')-> None :
      '''Scales the entity about the input point by the input scale factor. Input scale factor must be greater than 0.'''
    ...
    def set (self, *args, **kwargs)-> None :
      '''set( (CurveSurfInt)arg1, (Curve3d)arg2, (Surface)arg3) -> None :

    C++ signature :
        void set(class PyGeCurveSurfInt {lvalue},class PyGeCurve3d,class PyGeSurface)

set( (CurveSurfInt)arg1, (Curve3d)arg2, (Surface)arg3, (Tol)arg4) -> None :

    C++ signature :
        void set(class PyGeCurveSurfInt {lvalue},class PyGeCurve3d,class PyGeSurface,class AcGeTol)'''
    ...
    def surface (self, *args, **kwargs)-> PyDb.Surface :
      '''surface( (CurveSurfInt)arg1) -> Surface :

    C++ signature :
        class PyGeSurface surface(class PyGeCurveSurfInt {lvalue})'''
    ...
    def tolerance (self, *args, **kwargs)-> PyGe.Tol :
      '''tolerance( (CurveSurfInt)arg1) -> Tol :

    C++ signature :
        class AcGeTol tolerance(class PyGeCurveSurfInt {lvalue})'''
    ...
    def transformBy (self, val : PyGe.Matrix3d)-> None :
      '''Transforms the entity by applying the input matrix.'''
    ...
    def translateBy (self, vec : PyGe.Vector3d)-> None :
      '''Translates the entity by the input vector.'''
    ...
    def type (self)-> PyGe.EntityId :
      '''Returns the type of the entity.'''
    ...

class Cylinder(Surface):
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (float)arg2, (Point3d)arg3, (Vector3d)arg4) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,double,class AcGePoint3d,class AcGeVector3d)

__init__( (object)arg1, (float)arg2, (Point3d)arg3, (Vector3d)arg4, (Vector3d)arg5, (Interval)arg6, (float)arg7, (float)arg8) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,double,class AcGePoint3d,class AcGeVector3d,class AcGeVector3d,class PyGeInterval,double,double)'''
    ...
    def axisOfSymmetry (self, *args, **kwargs)-> PyGe.Vector3d :
      '''axisOfSymmetry( (Cylinder)arg1) -> Vector3d :

    C++ signature :
        class AcGeVector3d axisOfSymmetry(class PyGeCylinder {lvalue})'''
    ...
    def cast (self, *args, **kwargs)-> PyGe.Cylinder :
      '''cast( (Entity3d)arg1) -> Cylinder :

    C++ signature :
        class PyGeCylinder cast(class PyGeEntity3d)'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def closestPointTo (self, *args, **kwargs)-> PyGe.Point3d :
      '''closestPointTo( (Surface)arg1, (Point3d)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d closestPointTo(class PyGeSurface {lvalue},class AcGePoint3d)

closestPointTo( (Surface)arg1, (Point3d)arg2, (Tol)arg3) -> Point3d :

    C++ signature :
        class AcGePoint3d closestPointTo(class PyGeSurface {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def copy (self)-> PyGe.Entity3d :
      '''Returns a pointer to a copy of this entity. This copy is created using the new and it is the responsibility of the caller to delete it.'''
    ...
    def copycast (self, *args, **kwargs)-> PyGe.Cylinder :
      '''copycast( (Entity3d)arg1) -> Cylinder :

    C++ signature :
        class PyGeCylinder copycast(class PyGeEntity3d)'''
    ...
    def distanceTo (self, *args, **kwargs)-> float :
      '''distanceTo( (Surface)arg1, (Point3d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeSurface {lvalue},class AcGePoint3d)

distanceTo( (Surface)arg1, (Point3d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeSurface {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def evalPoint (self, *args, **kwargs)-> PyGe.Point3d :
      '''evalPoint( (Surface)arg1, (Point2d)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d evalPoint(class PyGeSurface {lvalue},class AcGePoint2d)

evalPoint( (Surface)arg1, (Point2d)arg2, (int)arg3, (list)arg4) -> Point3d :

    C++ signature :
        class AcGePoint3d evalPoint(class PyGeSurface {lvalue},class AcGePoint2d,int,class boost::python::list {lvalue})

evalPoint( (Surface)arg1, (Point2d)arg2, (int)arg3, (list)arg4, (Vector3d)arg5) -> Point3d :

    C++ signature :
        class AcGePoint3d evalPoint(class PyGeSurface {lvalue},class AcGePoint2d,int,class boost::python::list {lvalue},class AcGeVector3d {lvalue})'''
    ...
    def getAngles (self, *args, **kwargs)-> tuple :
      '''getAngles( (Cylinder)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple getAngles(class PyGeCylinder {lvalue})'''
    ...
    def getHeight (self, *args, **kwargs)-> PyGe.Interval :
      '''getHeight( (Cylinder)arg1) -> Interval :

    C++ signature :
        class PyGeInterval getHeight(class PyGeCylinder {lvalue})'''
    ...
    def heightAt (self, *args, **kwargs)-> float :
      '''heightAt( (Cylinder)arg1, (float)arg2) -> float :

    C++ signature :
        double heightAt(class PyGeCylinder {lvalue},double)'''
    ...
    def intersectWith (self, *args, **kwargs)-> tuple :
      '''intersectWith( (Cylinder)arg1, (LinearEnt3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeCylinder {lvalue},class PyGeLinearEnt3d)

intersectWith( (Cylinder)arg1, (LinearEnt3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeCylinder {lvalue},class PyGeLinearEnt3d,class AcGeTol {lvalue})'''
    ...
    def isClosed (self, *args, **kwargs)-> bool :
      '''isClosed( (Cylinder)arg1) -> bool :

    C++ signature :
        bool isClosed(class PyGeCylinder {lvalue})

isClosed( (Cylinder)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosed(class PyGeCylinder {lvalue},class AcGeTol)'''
    ...
    def isClosedInU (self, *args, **kwargs)-> bool :
      '''isClosedInU( (Surface)arg1) -> bool :

    C++ signature :
        bool isClosedInU(class PyGeSurface {lvalue})

isClosedInU( (Surface)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosedInU(class PyGeSurface {lvalue},class AcGeTol)'''
    ...
    def isClosedInV (self, *args, **kwargs)-> bool :
      '''isClosedInV( (Surface)arg1) -> bool :

    C++ signature :
        bool isClosedInV(class PyGeSurface {lvalue})

isClosedInV( (Surface)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosedInV(class PyGeSurface {lvalue},class AcGeTol)'''
    ...
    def isEqualTo (self, val : PyGe.Entity3d, tol : PyGe.Tol=None)-> bool :
      '''Determines if two entities are equal to each other. Two entities are considered to be equal only if they are of the same type and they represent the same 3D point set. For instance, if the two entities are of types AcGeCircArc3d and AcGeEllipArc3d then they are not considered equal even if the ellipse is completely coincident with the circle. Also, two curves are not considered equal unless they have the same parameterization. For instance, two infinite coincident lines are not considered equal if they have different scaling in their parameterization. '''
    ...
    def isKindOf (self, val : PyGe.EntityId)-> bool :
      '''                             '''
    ...
    def isNormalReversed (self, *args, **kwargs)-> bool :
      '''isNormalReversed( (Surface)arg1) -> bool :

    C++ signature :
        bool isNormalReversed(class PyGeSurface {lvalue})'''
    ...
    def isNull (self)-> bool :
      '''                             '''
    ...
    def isOn (self, *args, **kwargs)-> bool :
      '''isOn( (Surface)arg1, (Point3d)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeSurface {lvalue},class AcGePoint3d)

isOn( (Surface)arg1, (Point3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeSurface {lvalue},class AcGePoint3d,class AcGeTol)

isOn( (Surface)arg1, (Point3d)arg2, (Point2d)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeSurface {lvalue},class AcGePoint3d,class AcGePoint2d {lvalue})

isOn( (Surface)arg1, (Point3d)arg2, (Point2d)arg3, (Tol)arg4) -> bool :

    C++ signature :
        bool isOn(class PyGeSurface {lvalue},class AcGePoint3d,class AcGePoint2d {lvalue},class AcGeTol)'''
    ...
    def isOuterNormal (self, *args, **kwargs)-> bool :
      '''isOuterNormal( (Cylinder)arg1) -> bool :

    C++ signature :
        bool isOuterNormal(class PyGeCylinder {lvalue})'''
    ...
    def mirror (self, val : PyGe.Plane)-> None :
      '''Transforms the entity by mirroring it across the input plane.'''
    ...
    def origin (self, *args, **kwargs)-> PyGe.Point3d :
      '''origin( (Cylinder)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d origin(class PyGeCylinder {lvalue})'''
    ...
    def paramOf (self, *args, **kwargs)-> PyGe.Point2d :
      '''paramOf( (Surface)arg1, (Point3d)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d paramOf(class PyGeSurface {lvalue},class AcGePoint3d)

paramOf( (Surface)arg1, (Point3d)arg2, (Tol)arg3) -> Point2d :

    C++ signature :
        class AcGePoint2d paramOf(class PyGeSurface {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def radius (self, *args, **kwargs)-> float :
      '''radius( (Cylinder)arg1) -> float :

    C++ signature :
        double radius(class PyGeCylinder {lvalue})'''
    ...
    def refAxis (self, *args, **kwargs)-> PyGe.Vector3d :
      '''refAxis( (Cylinder)arg1) -> Vector3d :

    C++ signature :
        class AcGeVector3d refAxis(class PyGeCylinder {lvalue})'''
    ...
    def reverseNormal (self, *args, **kwargs)-> None :
      '''reverseNormal( (Surface)arg1) -> None :

    C++ signature :
        void reverseNormal(class PyGeSurface {lvalue})'''
    ...
    def rotateBy (self, angle : float, vec : PyGe.Vector3d, pt : PyGe.Point3d = 'origin')-> None :
      '''Rotates the entity by the input angle about the line defined by the input point and vector.'''
    ...
    def scaleBy (self, scaleFactor : float, pt : PyGe.Point3d = 'origin')-> None :
      '''Scales the entity about the input point by the input scale factor. Input scale factor must be greater than 0.'''
    ...
    def set (self, *args, **kwargs)-> None :
      '''set( (Cylinder)arg1, (float)arg2, (Point3d)arg3, (Vector3d)arg4) -> None :

    C++ signature :
        void set(class PyGeCylinder {lvalue},double,class AcGePoint3d,class AcGeVector3d)

set( (Cylinder)arg1, (float)arg2, (Point3d)arg3, (Vector3d)arg4, (Vector3d)arg5, (Interval)arg6, (float)arg7, (float)arg8) -> None :

    C++ signature :
        void set(class PyGeCylinder {lvalue},double,class AcGePoint3d,class AcGeVector3d,class AcGeVector3d,class PyGeInterval,double,double)'''
    ...
    def setAngles (self, *args, **kwargs)-> None :
      '''setAngles( (Cylinder)arg1, (float)arg2, (float)arg3) -> None :

    C++ signature :
        void setAngles(class PyGeCylinder {lvalue},double,double)'''
    ...
    def setHeight (self, *args, **kwargs)-> None :
      '''setHeight( (Cylinder)arg1, (Interval)arg2) -> None :

    C++ signature :
        void setHeight(class PyGeCylinder {lvalue},class PyGeInterval)'''
    ...
    def setRadius (self, *args, **kwargs)-> None :
      '''setRadius( (Cylinder)arg1, (float)arg2) -> None :

    C++ signature :
        void setRadius(class PyGeCylinder {lvalue},double)'''
    ...
    def transformBy (self, val : PyGe.Matrix3d)-> None :
      '''Transforms the entity by applying the input matrix.'''
    ...
    def translateBy (self, vec : PyGe.Vector3d)-> None :
      '''Translates the entity by the input vector.'''
    ...
    def type (self)-> PyGe.EntityId :
      '''Returns the type of the entity.'''
    ...

class EllipArc2d(Curve2d):
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (CircArc2d)arg2) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class PyGeCircArc2d)

__init__( (object)arg1, (Point2d)arg2, (Vector2d)arg3, (Vector2d)arg4, (float)arg5, (float)arg6) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePoint2d,class AcGeVector2d,class AcGeVector2d,double,double)

__init__( (object)arg1, (Point2d)arg2, (Vector2d)arg3, (Vector2d)arg4, (float)arg5, (float)arg6, (float)arg7, (float)arg8) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePoint2d,class AcGeVector2d,class AcGeVector2d,double,double,double,double)'''
    ...
    def area (self, startParam : float, endParam : float, tol : float = None)-> float :
      '''                             '''
    ...
    def boundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock2d :
      '''                             '''
    ...
    def cast (self, *args, **kwargs)-> PyGe.EllipArc2d :
      '''cast( (Entity2d)arg1) -> EllipArc2d :

    C++ signature :
        class PyGeEllipArc2d cast(class PyGeEntity2d)'''
    ...
    def center (self, *args, **kwargs)-> PyGe.Point2d :
      '''center( (EllipArc2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d center(class PyGeEllipArc2d {lvalue})'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def closestPointTo (self, other : PyGe.Point2d | PyGe.Curve2d, tol : PyGe.Tol=None)-> PyGe.Point2d :
      '''                             '''
    ...
    def copy (self)-> PyGe.Entity2d :
      '''                             '''
    ...
    def copycast (self, *args, **kwargs)-> PyGe.EllipArc2d :
      '''copycast( (Entity2d)arg1) -> EllipArc2d :

    C++ signature :
        class PyGeEllipArc2d copycast(class PyGeEntity2d)'''
    ...
    def distanceTo (self, pt : PyGe.Point2d | PyGe.Curve2d, tol : PyGe.Tol=None)-> float :
      '''                             '''
    ...
    def endAng (self, *args, **kwargs)-> float :
      '''endAng( (EllipArc2d)arg1) -> float :

    C++ signature :
        double endAng(class PyGeEllipArc2d {lvalue})'''
    ...
    def endPoint (self, *args, **kwargs)-> PyGe.Point2d :
      '''endPoint( (EllipArc2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d endPoint(class PyGeEllipArc2d {lvalue})'''
    ...
    def evalPoint (self, param : float, numDeriv : int = 1)-> PyGe.Point2d :
      '''                             '''
    ...
    def explode (self, val : PyGe.Interval = None)-> list :
      '''                             '''
    ...
    def getClosestPointTo (self, other : PyGe.Point2d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve2d :
      '''                             '''
    ...
    def getClosestPointsTo (self, other : PyGe.Curve2d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def getEndPoint (self)-> PyGe.Point2d :
      '''                             '''
    ...
    def getInterval (self)-> PyGe.Interval :
      '''                             '''
    ...
    def getNormalPoint (self, pnt : PyGe.Point2d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve2d :
      '''                             '''
    ...

    @overload
    def getSamplePoints (self, numSample: int)-> list : ...
    @overload
    def getSamplePoints (self, fromParam: float, toParam: float, approxEps: float)-> list : ...
    def getSamplePoints (self, *args, **kwargs)-> list :
      '''Overloads:
    - numSample: int
    - fromParam: float, toParam: float, approxEps: float
    '''
    ...
    def getSplitCurves (self, param : float)-> tuple :
      '''                             '''
    ...
    def getStartPoint (self)-> PyGe.Point2d :
      '''                             '''
    ...
    def getTrimmedOffset (self, dist : float, extensionType : PyGe.OffsetCrvExtType, tol : PyGe.Tol=None)-> list :
      '''                             '''
    ...
    def hasEndPoint (self)-> bool :
      '''                             '''
    ...
    def hasStartPoint (self)-> bool :
      '''                             '''
    ...
    def intersectWith (self, *args, **kwargs)-> tuple :
      '''intersectWith( (EllipArc2d)arg1, (LinearEnt2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeEllipArc2d {lvalue},class PyGeLinearEnt2d)

intersectWith( (EllipArc2d)arg1, (LinearEnt2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeEllipArc2d {lvalue},class PyGeLinearEnt2d,class AcGeTol)'''
    ...
    def isCircular (self, *args, **kwargs)-> bool :
      '''isCircular( (EllipArc2d)arg1) -> bool :

    C++ signature :
        bool isCircular(class PyGeEllipArc2d {lvalue})

isCircular( (EllipArc2d)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isCircular(class PyGeEllipArc2d {lvalue},class AcGeTol)'''
    ...
    def isClockWise (self, *args, **kwargs)-> bool :
      '''isClockWise( (EllipArc2d)arg1) -> bool :

    C++ signature :
        bool isClockWise(class PyGeEllipArc2d {lvalue})'''
    ...
    def isClosed (self, tol : PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def isDegenerate (self, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isEqualTo (self, val : PyGe.Entity2d, tol : PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def isInside (self, *args, **kwargs)-> bool :
      '''isInside( (EllipArc2d)arg1, (Point2d)arg2) -> bool :

    C++ signature :
        bool isInside(class PyGeEllipArc2d {lvalue},class AcGePoint2d)

isInside( (EllipArc2d)arg1, (Point2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isInside(class PyGeEllipArc2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def isKindOf (self, val : PyGe.EntityId)-> bool :
      '''                             '''
    ...
    def isLinear (self, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isNull (self)-> bool :
      '''                             '''
    ...
    def isOn (self, pt : float | PyGe.Point2d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isPeriodic (self)-> tuple :
      '''                             '''
    ...
    def length (self, frm : float, to : float, tol : float = None)-> float :
      '''                             '''
    ...
    def majorAxis (self, *args, **kwargs)-> PyGe.Vector2d :
      '''majorAxis( (EllipArc2d)arg1) -> Vector2d :

    C++ signature :
        class AcGeVector2d majorAxis(class PyGeEllipArc2d {lvalue})'''
    ...
    def majorRadius (self, *args, **kwargs)-> float :
      '''majorRadius( (EllipArc2d)arg1) -> float :

    C++ signature :
        double majorRadius(class PyGeEllipArc2d {lvalue})'''
    ...
    def minorAxis (self, *args, **kwargs)-> PyGe.Vector2d :
      '''minorAxis( (EllipArc2d)arg1) -> Vector2d :

    C++ signature :
        class AcGeVector2d minorAxis(class PyGeEllipArc2d {lvalue})'''
    ...
    def minorRadius (self, *args, **kwargs)-> float :
      '''minorRadius( (EllipArc2d)arg1) -> float :

    C++ signature :
        double minorRadius(class PyGeEllipArc2d {lvalue})'''
    ...
    def mirror (self, val : PyGe.Line2d)-> None :
      '''                             '''
    ...
    def orthoBoundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock2d :
      '''                             '''
    ...
    def paramAtLength (self, datumParam: float, length: float, posParamDir: bool=True, tol: float=None)-> float :
      '''                             '''
    ...
    def paramOf (self, pt : PyGe.Point2d, tol : PyGe.Tol=None)-> float :
      '''                             '''
    ...
    def reverseParam (self)-> None :
      '''                             '''
    ...
    def rotateBy (self, angle : float, pt : PyGe.Point3d=PyGe.Point2d.kOrgin)-> None :
      '''                             '''
    ...
    def scaleBy (self, scaleFactor : float, pt : PyGe.Point2d=PyGe.Point2d.kOrgin)-> None :
      '''                             '''
    ...
    def set (self, *args, **kwargs)-> None :
      '''set( (EllipArc2d)arg1, (Point2d)arg2, (Vector2d)arg3, (Vector2d)arg4, (float)arg5, (float)arg6) -> None :

    C++ signature :
        void set(class PyGeEllipArc2d {lvalue},class AcGePoint2d,class AcGeVector2d,class AcGeVector2d,double,double)

set( (EllipArc2d)arg1, (Point2d)arg2, (Vector2d)arg3, (Vector2d)arg4, (float)arg5, (float)arg6, (float)arg7, (float)arg8) -> None :

    C++ signature :
        void set(class PyGeEllipArc2d {lvalue},class AcGePoint2d,class AcGeVector2d,class AcGeVector2d,double,double,double,double)

set( (EllipArc2d)arg1, (CircArc2d)arg2) -> None :

    C++ signature :
        void set(class PyGeEllipArc2d {lvalue},class PyGeCircArc2d)'''
    ...
    def setAngles (self, *args, **kwargs)-> None :
      '''setAngles( (EllipArc2d)arg1, (float)arg2, (float)arg3) -> None :

    C++ signature :
        void setAngles(class PyGeEllipArc2d {lvalue},double,double)'''
    ...
    def setAxes (self, *args, **kwargs)-> None :
      '''setAxes( (EllipArc2d)arg1, (Vector2d)arg2, (Vector2d)arg3) -> None :

    C++ signature :
        void setAxes(class PyGeEllipArc2d {lvalue},class AcGeVector2d,class AcGeVector2d)'''
    ...
    def setCenter (self, *args, **kwargs)-> None :
      '''setCenter( (EllipArc2d)arg1, (Point2d)arg2) -> None :

    C++ signature :
        void setCenter(class PyGeEllipArc2d {lvalue},class AcGePoint2d)'''
    ...
    def setInterval (self, val : PyGe.Interval = None)-> None :
      '''                             '''
    ...
    def setMajorRadius (self, *args, **kwargs)-> None :
      '''setMajorRadius( (EllipArc2d)arg1, (float)arg2) -> None :

    C++ signature :
        void setMajorRadius(class PyGeEllipArc2d {lvalue},double)'''
    ...
    def setMinorRadius (self, *args, **kwargs)-> None :
      '''setMinorRadius( (EllipArc2d)arg1, (float)arg2) -> None :

    C++ signature :
        void setMinorRadius(class PyGeEllipArc2d {lvalue},double)'''
    ...
    def startAng (self, *args, **kwargs)-> float :
      '''startAng( (EllipArc2d)arg1) -> float :

    C++ signature :
        double startAng(class PyGeEllipArc2d {lvalue})'''
    ...
    def startPoint (self, *args, **kwargs)-> PyGe.Point2d :
      '''startPoint( (EllipArc2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d startPoint(class PyGeEllipArc2d {lvalue})'''
    ...
    def transformBy (self, val : PyGe.Matrix2d)-> None :
      '''                             '''
    ...
    def translateBy (self, vec : PyGe.Vector2d)-> None :
      '''                             '''
    ...
    def type (self)-> PyGe.EntityId :
      '''                             '''
    ...

class EllipArc3d(Curve3d):

    @overload
    def __init__ (self, /)-> None : ...
    @overload
    def __init__ (self, carc: PyGe.CircArc3d,)-> None : ...
    @overload
    def __init__ (self, cent: PyGe.Point3d, majorAxis: PyGe.Vector3d, minorAxis: PyGe.Vector3d, majorRadius: float,minorRadius: float)-> None : ...
    @overload
    def __init__ (self, cent: PyGe.Point3d, majorAxis: PyGe.Vector3d, minorAxis: PyGe.Vector3d, majorRadius: float,minorRadius: float, startAngle: float, endAngle: float)-> None : ...
    def __init__ (self, *args, **kwargs)-> None :
      '''Overloads:
    - None: Any
    - carc: PyGe.CircArc3d,
    - cent: PyGe.Point3d, majorAxis: PyGe.Vector3d, minorAxis: PyGe.Vector3d, majorRadius: float,minorRadius: float
    - cent: PyGe.Point3d, majorAxis: PyGe.Vector3d, minorAxis: PyGe.Vector3d, majorRadius: float,minorRadius: float, startAngle: float, endAngle: float
    '''
    ...
    def area (self, startParam : float, endParam : float, tol : float = None)-> float :
      '''Returns the area of the interval of the curve defined by startParam and endParam. Returns Adesk::kTrue if area was successfully computed to within the specified tolerance. If the curve is not planar, then the area cannot be calculated and a value of Adesk::kFalse is returned. If the points at startParam and endParam are the same, then this function returns the area of the closed curve. If the points are different, then this function connects the two points with a line segment and return the signed area between the curve and the line segment. If the line segment does not intersect the curve at any points between startParam and endParam, then the returned area is positive. If the line segment intersects the curves at any points between startParam and endParam, then the returned area is the sum of the sub-areas created by the intersection of the line segment with the curve. Each sub-area has a positive or negative area, depending on whether the curve lies above or below the line segment. The total area returned by this function can therefore be positive, negative, or 0. '''
    ...
    def boundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock3d :
      '''Returns the bounding box of the curve. The sides of the returned box are parallel to the coordinate axes. '''
    ...

    @staticmethod
    def cast (otherObject: PyGe.Entity3d)-> PyGe.EllipArc3d :
      '''                             '''
    ...
    def center (self)-> PyGe.Point3d :
      '''                             '''
    ...

    @staticmethod
    def className ()-> str :
      '''                             '''
    ...
    def closestPointTo (self, other : PyGe.Point3d | PyGe.Curve3d, tol : PyGe.Tol=None)-> PyGe.Point3d :
      '''Finds the closest point on this curve to the input point. This function is the same as closestPointTo(), except that the closest point is returned as an AcGePointOnCurve3d object.'''
    ...
    def closestPointToPlane (self, plane: PyGe.PlanarEnt, tol: PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def copy (self)-> PyGe.Entity3d :
      '''Returns a pointer to a copy of this entity. This copy is created using the new and it is the responsibility of the caller to delete it.'''
    ...

    @staticmethod
    def copycast (otherObject: PyGe.Entity3d)-> PyGe.EllipArc3d :
      '''                             '''
    ...
    def distanceTo (self, pt : PyGe.Point3d | PyGe.Curve3d, tol : PyGe.Tol=None)-> float :
      '''Returns the distance between the input point and the closest point on this curve.'''
    ...
    def endAng (self)-> float :
      '''                             '''
    ...
    def endPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def evalPoint (self, param : float, numDeriv : int = 1)-> PyGe.Point3d :
      '''Returns the point on the curve that corresponds to the input parameter value. Also returns the number of derivative vectors that are specified in numDeriv. The numDeriv parameter should not be set larger than 2.'''
    ...
    def explode (self, val : PyGe.Interval = None)-> list :
      '''Explodes the curve into its individual components. If the curve is a composite curve, then explodedCurves contains the list of component curves of the composite. If the curve is a spline, then it is exploded at the points of C1 discontinuity and explodedCurves contains a copy of each continuous sub-curve. This function returns Adesk::kTrue if the curve was exploded (that is, the curve was a composite or a discontinuous spline) and Adesk::kFalse otherwise. The number of entries returned in newExplodedCurves is always the same as the number of entries in explodedCurves. Each flag in newExplodedCurves indicates whether the corresponding curve in explodedCurves was created with the new operator. If the flag is 1, then it is the responsibility of the caller to delete the curve. If the flag is 0, the curve is deleted by gelib and the caller should not attempt to delete it. If no intrvl parameter is supplied, then the interval is taken to be the entire curve. '''
    ...
    def getClosestPointTo (self, other : PyGe.Point3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''Finds the closest point on this curve to the input point. This function is the same as closestPointTo(), except that the closest point is returned as an AcGePointOnCurve3d object.'''
    ...
    def getClosestPointsTo (self, other : PyGe.Curve3d, tol : PyGe.Tol=None)-> tuple :
      '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
    ...
    def getEndPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def getInterval (self)-> PyGe.Interval :
      '''Returns the parametric range of the curve. The function evalPoint(double) always returns a point on this curve when called with a value within the returned interval.'''
    ...
    def getNormalPoint (self, pnt : PyGe.Point3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''Finds the point on the input curve whose normal passes through the input point. The returned point lies on a plane that also contains the input point and is perpendicular to the curve tangent at that point. The returned point is therefore at a local minimum or a local maximum from the input point. The curve does not need to be planar. If the curve is planar, the input point does not need to lie in the plane of the curve. On input, the second parameter is assumed to contain the parameter value of an initial guess. If there is more than one normal point on the curve, the returned point will be the one whose parameter value is closest to the input parameter value.'''
    ...
    def getPlane (self)-> PyGe.Plane :
      '''                             '''
    ...
    def getProjClosestPointTo (self, pt : PyGe.Point3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
    ...
    def getProjClosestPointsTo (self, pt : PyGe.Curve3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> tuple :
      '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
    ...

    @overload
    def getSamplePoints (self, numSample: int)-> tuple : ...
    @overload
    def getSamplePoints (self, fromParam: float, toParam: float, approxEps: float)-> tuple : ...
    def getSamplePoints (self, *args, **kwargs)-> tuple :
      '''Overloads:
    - numSample: int
    - fromParam: float, toParam: float, approxEps: float
    
	-Returns the specified number of points on the curve. The points are equally spaced by parameter value. So if the interval of the curve [0,1] and numSample is 5, the parameter values of the returned points are 0, 0.25, 0.5, 0.75, and 1.-'''
    ...
    def getSplitCurves (self, param : float)-> tuple :
      '''Returns two segments which are obtained by splitting the curve at the input parameter value. If the specified parameter value does not lie within the parametric interval of the curve or if it corresponds to the start point or endpoint of the curve, then piece1 and piece2 are set to null. This function uses the new to create the curve segments whose addresses are returned in piece1 and piece2. It is the responsibility of the caller to delete these objects. '''
    ...
    def getStartPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def getTrimmedOffset (self, dist : float, planeNormal : PyGe.Vector3d, extensionType : PyGe.OffsetCrvExtType, tol : PyGe.Tol=None)-> list :
      '''Returns one or more offset curves that represent the trimmed offset of the curve. The curve must be planar and planeNormal must be perpendicular to the plane of the curve. The positive direction of offset at a point on the curve is taken to be the cross product of planeNormal with the tangent vector at that point. The curve may be offset in either of two directions by specifying a positive or negative offset distance; planeNormal determines which direction is the positive direction of offset. The returned offset curves are trimmed so that they do not contain any points of self-intersection. Each curve that is returned in offsetCurveList is created with the new and it is the responsibility of the caller to delete these curves. Each curve that is returned in offsetCurveList is a connected curve and may be a composite curve if the offset curve had to be trimmed to remove self-intersecting loops. offsetCurveList only contains more than one curve if the offset operation produces multiple curves which are not connected. If the original curve contains points of C1 discontinuity and the direction of offset causes the offset curve to be disjoint (for instance, if the original curve is a composite curve that is a rectangle and the direction of offset is to the outside of the rectangle), then the offset curve is closed with an arc or a line segment, or the curves are simply extended depending on the value of extensionType.'''
    ...
    def hasEndPoint (self)-> bool :
      '''Returns Adesk::kTrue if curve has an endpoint. A return value of Adesk::kFalse means that the parametric interval of the curve does not have an upper bound. The endPnt parameter contains meaningful data only if this function returns a value of Adesk::kTrue.'''
    ...
    def hasStartPoint (self)-> bool :
      '''Returns Adesk::kTrue if curve has a start point. A return value of Adesk::kFalse means that the parametric interval of the curve does not have a lower bound. The startPnt parameter contains meaningful data only if this function returns a value of Adesk::kTrue.'''
    ...
    def intersectWith (self, other: PyGe.LinearEnt3d|PyGe.PlanarEnt, tol: PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isCircular (self, tol: PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def isClosed (self, tol : PyGe.Tol=None)-> bool :
      '''Determines if start point and endpoint of curve are the same.'''
    ...
    def isCoplanarWith (self, curve : PyGe.Curve3d, tol : PyGe.Tol=None)-> tuple :
      '''Returns Adesk::kTrue if both curve are planar and lie in the same plane. The plane parameter is only valid if this function returns a value of Adesk::kTrue.'''
    ...
    def isDegenerate (self, tol : PyGe.Tol=None)-> tuple :
      '''Determines if the curve is degenerate and if so returns the type of entity which the curve degenerates into. For example, if the curve is a circle with a radius of 0 then degenerateType is set to AcGe::kPoint3d. If the curve is an ellipse with a minor radius of 0 and a major radius of 1, then degenerateType is set to AcGe::kLineSeg3d. The degenerateType parameter is only set to something meaningful when this function returns a value of Adesk::kTrue.'''
    ...
    def isEqualTo (self, val : PyGe.Entity3d, tol : PyGe.Tol=None)-> bool :
      '''Determines if two entities are equal to each other. Two entities are considered to be equal only if they are of the same type and they represent the same 3D point set. For instance, if the two entities are of types AcGeCircArc3d and AcGeEllipArc3d then they are not considered equal even if the ellipse is completely coincident with the circle. Also, two curves are not considered equal unless they have the same parameterization. For instance, two infinite coincident lines are not considered equal if they have different scaling in their parameterization. '''
    ...
    def isInside (self, pt: PyGe.Point3d, tol: PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def isKindOf (self, val : PyGe.EntityId)-> bool :
      '''                             '''
    ...
    def isLinear (self, tol : PyGe.Tol=None)-> tuple :
      '''Determines if curve is linear. This function returns an infinite line even if the curve is not infinite. The line parameter contains meaningful data only if this function returns a value of Adesk::kTrue.'''
    ...
    def isNull (self)-> bool :
      '''                             '''
    ...
    def isOn (self, pt : float | PyGe.Point3d, tol : PyGe.Tol=None)-> tuple :
      '''Determines if input parameter value is within valid parametric range of curve.'''
    ...
    def isPeriodic (self)-> tuple :
      '''Determines if the curve is periodic. The curve is periodic if and only if it is closed and the two points evalPoint(t) and evalPoint(t+period) are always the same point for all values of t.'''
    ...
    def isPlanar (self, tol : PyGe.Tol=None)-> tuple :
      '''Determines if curve is planar. If the curve is a line, then this function returns an arbitrary plane that contains the line. The plane parameter contains meaningful data only if this function returns a value of Adesk::kTrue. '''
    ...
    def length (self, frm : float, to : float, tol : float = None)-> float :
      '''Returns the arc length of the curve between the two parameter values.'''
    ...
    def majorAxis (self)-> PyGe.Vector3d :
      '''                             '''
    ...
    def majorRadius (self)-> float :
      '''                             '''
    ...
    def minorAxis (self)-> PyGe.Vector3d :
      '''                             '''
    ...
    def minorRadius (self)-> float :
      '''                             '''
    ...
    def mirror (self, val : PyGe.Plane)-> None :
      '''Transforms the entity by mirroring it across the input plane.'''
    ...
    def normal (self)-> PyGe.Vector3d :
      '''                             '''
    ...
    def orthoBoundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock3d :
      '''Returns the bounding box of the curve. The sides of the returned box are parallel to the coordinate axes.'''
    ...
    def orthoProject (self, projectionPlane : PyGe.Plane, tol : PyGe.Tol=None)-> PyGe.Entity3d :
      '''Returns the entity that is the orthogonal projection of the curve onto the projection plane. The returned entity may not be of the same type as the original curve and may not even be a curve (for instance, a line projects into a point if it is orthogonal to the projection plane). The returned entity is created with the new and it is the responsibility of the caller to delete it.'''
    ...
    def paramAtLength (self, datumParam : float, length : float, posParamDir : bool=True, tol : float = default)-> float :
      '''Returns the parameter value of the point whose arc length distance (from the point with parameter value datumParam) is the input length. In other words, ift = paramAtLength (datumParam, len, posParamDir, tol) then length (t, datumParam, tol) is (approximately) equal to len. If posParamDir is set to Adesk::kTrue, then the returned parameter value is greater than datumParam. Otherwise it will be less than datumParam. '''
    ...
    def paramOf (self, pt : PyGe.Point3d, tol : PyGe.Tol=None)-> float :
      '''Returns the parameter value of pnt. This function assumes that pnt lies on the curve and does not verify this. If pnt does not lie on the curve, this function will return unpredictable results. If it is not known whether pnt lies on the curve, the user should not call this function but should instead call AcGeCurve3d::isOn (pnt, param, tol). '''
    ...
    def projClosestPointTo (self, pt : PyGe.Point3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.Point3d :
      '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
    ...
    def projClosestPointsTo (self, pt : PyGe.Curve3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> tuple :
      '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
    ...
    def projIntersectWith (self, other: PyGe.LinearEnt3d, projDir: PyGe.Vector3d, tol: PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def project (self, projectionPlane : PyGe.Plane, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.Entity3d :
      '''Returns the entity that is the projection of the curve onto the projection plane in the specified direction. The projectDirection vector must not be parallel to the projection plane. The returned entity may not be of the same type as the original curve and may not even be a curve (for instance, a line projects into a point if it is parallel to projectDirection). The returned entity is created with the new and it is the responsibility of the caller to delete it.'''
    ...
    def reverseParam (self)-> None :
      '''Reverses the parametric direction of the curve. The point set of the curve is unchanged, but the direction of the curve is reversed.'''
    ...
    def rotateBy (self, angle : float, vec : PyGe.Vector3d, pt : PyGe.Point3d = 'origin')-> None :
      '''Rotates the entity by the input angle about the line defined by the input point and vector.'''
    ...
    def scaleBy (self, scaleFactor : float, pt : PyGe.Point3d = 'origin')-> None :
      '''Scales the entity about the input point by the input scale factor. Input scale factor must be greater than 0.'''
    ...

    @overload
    def set (self, carc: PyGe.CircArc3d,)-> None : ...
    @overload
    def set (self, cent: PyGe.Point3d, majorAxis: PyGe.Vector3d, minorAxis: PyGe.Vector3d, majorRadius: float,minorRadius: float)-> None : ...
    @overload
    def set (self, cent: PyGe.Point3d, majorAxis: PyGe.Vector3d, minorAxis: PyGe.Vector3d, majorRadius: float,minorRadius: float, startAngle: float, endAngle: float)-> None : ...
    def set (self, *args, **kwargs)-> None :
      '''Overloads:
    - carc: PyGe.CircArc3d,
    - cent: PyGe.Point3d, majorAxis: PyGe.Vector3d, minorAxis: PyGe.Vector3d, majorRadius: float,minorRadius: float
    - cent: PyGe.Point3d, majorAxis: PyGe.Vector3d, minorAxis: PyGe.Vector3d, majorRadius: float,minorRadius: float, startAngle: float, endAngle: float
    '''
    ...
    def setAngles (self, startAngle: float, endAngle: float)-> None :
      '''                             '''
    ...
    def setAxes (self, majorAxis: PyGe.Vector3d, minorAxis: PyGe.Vector3d)-> None :
      '''                             '''
    ...
    def setCenter (self, pt: PyGe.Point3d)-> None :
      '''                             '''
    ...
    def setInterval (self, val : PyGe.Interval = None)-> None :
      '''Sets the domain of the curve to the input interval.'''
    ...
    def setMajorRadius (self, val: float)-> None :
      '''                             '''
    ...
    def setMinorRadius (self, val: float)-> None :
      '''                             '''
    ...
    def startAng (self)-> float :
      '''                             '''
    ...
    def startPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def transformBy (self, val : PyGe.Matrix3d)-> None :
      '''Transforms the entity by applying the input matrix.'''
    ...
    def translateBy (self, vec : PyGe.Vector3d)-> None :
      '''Translates the entity by the input vector.'''
    ...
    def type (self)-> PyGe.EntityId :
      '''Returns the type of the entity.'''
    ...

class Entity2d(object):
    def __init__ (self, *args, **kwargs)-> None :
      '''Raises an exception
This class cannot be instantiated from Python'''
    ...

    @staticmethod
    def className ()-> str :
      '''                             '''
    ...
    def copy (self)-> PyGe.Entity2d :
      '''                             '''
    ...

    @staticmethod
    def copycast (otherObject: PyGe.Entity2d)-> PyGe.Entity2d :
      '''                             '''
    ...
    def isEqualTo (self, val : PyGe.Entity2d, tol : PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def isKindOf (self, val : PyGe.EntityId)-> bool :
      '''                             '''
    ...
    def isNull (self)-> bool :
      '''                             '''
    ...
    def isOn (self, pt : PyGe.Point2d, tol : PyGe.Tol=default)-> bool :
      '''                             '''
    ...
    def mirror (self, val : PyGe.Line2d)-> None :
      '''                             '''
    ...
    def rotateBy (self, angle : float, pt : PyGe.Point3d=PyGe.Point2d.kOrgin)-> None :
      '''                             '''
    ...
    def scaleBy (self, scaleFactor : float, pt : PyGe.Point2d=PyGe.Point2d.kOrgin)-> None :
      '''                             '''
    ...
    def transformBy (self, val : PyGe.Matrix2d)-> None :
      '''                             '''
    ...
    def translateBy (self, vec : PyGe.Vector2d)-> None :
      '''                             '''
    ...
    def type (self)-> PyGe.EntityId :
      '''                             '''
    ...

class Entity3d(object):
    def __init__ (self, *args, **kwargs)-> None :
      '''Raises an exception
This class cannot be instantiated from Python'''
    ...

    @staticmethod
    def className ()-> str :
      '''                             '''
    ...
    def copy (self)-> PyGe.Entity3d :
      '''Returns a pointer to a copy of this entity. This copy is created using the new and it is the responsibility of the caller to delete it.'''
    ...

    @staticmethod
    def copycast (otherObject: PyGe.Entity3d)-> PyGe.Entity3d :
      '''                             '''
    ...
    def isEqualTo (self, val : PyGe.Entity3d, tol : PyGe.Tol=None)-> bool :
      '''Determines if two entities are equal to each other. Two entities are considered to be equal only if they are of the same type and they represent the same 3D point set. For instance, if the two entities are of types AcGeCircArc3d and AcGeEllipArc3d then they are not considered equal even if the ellipse is completely coincident with the circle. Also, two curves are not considered equal unless they have the same parameterization. For instance, two infinite coincident lines are not considered equal if they have different scaling in their parameterization. '''
    ...
    def isKindOf (self, val : PyGe.EntityId)-> bool :
      '''                             '''
    ...
    def isNull (self)-> bool :
      '''                             '''
    ...
    def isOn (self, pt : PyGe.Point3d, tol : PyGe.Tol=default)-> bool :
      '''Returns Adesk::kTrue if pnt lies on entity; otherwise, returns Adesk::kFalse.'''
    ...
    def mirror (self, val : PyGe.Plane)-> None :
      '''Transforms the entity by mirroring it across the input plane.'''
    ...
    def rotateBy (self, angle : float, vec : PyGe.Vector3d, pt : PyGe.Point3d = 'origin')-> None :
      '''Rotates the entity by the input angle about the line defined by the input point and vector.'''
    ...
    def scaleBy (self, scaleFactor : float, pt : PyGe.Point3d = 'origin')-> None :
      '''Scales the entity about the input point by the input scale factor. Input scale factor must be greater than 0.'''
    ...
    def transformBy (self, val : PyGe.Matrix3d)-> None :
      '''Transforms the entity by applying the input matrix.'''
    ...
    def translateBy (self, vec : PyGe.Vector3d)-> None :
      '''Translates the entity by the input vector.'''
    ...
    def type (self)-> PyGe.EntityId :
      '''Returns the type of the entity.'''
    ...

class EntityId(object):
    def Helix (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def __add__ (self, value, /) :
      '''Return self+value.'''
    ...
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def __mul__ (self, value, /) :
      '''Return self*value.'''
    ...
    def __rmul__ (self, value, /) :
      '''Return value*self.'''
    ...
    def __sub__ (self, value, /) :
      '''Return self-value.'''
    ...
    def __truediv__ (self, value, /) :
      '''Return self/value.'''
    ...
    def kAugPolyline2d (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kAugPolyline3d (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kBezierCurve3d (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kBoundBlock2d (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kBoundBlock3d (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kBoundedPlane (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kCircArc2d (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kCircArc3d (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kClipBoundary2d (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kCompositeCrv2d (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kCompositeCrv3d (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kCone (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kConic2d (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kConic3d (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kCubicSplineCurve2d (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kCubicSplineCurve3d (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kCurve2d (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kCurve3d (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kCurveBoundedSurface (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kCurveCurveInt2d (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kCurveCurveInt3d (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kCurveSampleData (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kCurveSurfaceInt (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kCylinder (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kDSpline2d (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kDSpline3d (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kEllipArc2d (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kEllipArc3d (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kEllipCone (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kEllipCylinder (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kEntity2d (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kEntity3d (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kEnvelope2d (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kExternalBoundedSurface (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kExternalCurve2d (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kExternalCurve3d (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kExternalObject (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kExternalSurface (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kFitData3d (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kHatch (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kIntervalBoundBlock (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kLine2d (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kLine3d (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kLineSeg2d (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kLineSeg3d (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kLinearEnt2d (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kLinearEnt3d (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kNurbCurve2d (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kNurbCurve3d (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kNurbSurface (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kObject (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kOffsetCurve2d (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kOffsetCurve3d (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kOffsetSurface (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kPlanarEnt (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kPlane (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kPointEnt2d (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kPointEnt3d (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kPointOnCurve2d (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kPointOnCurve3d (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kPointOnSurface (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kPolyline2d (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kPolyline3d (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kPolynomCurve3d (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kPosition2d (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kPosition3d (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kRay2d (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kRay3d (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kSphere (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kSplineEnt2d (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kSplineEnt3d (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kSurface (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kSurfaceCurve2dTo3d (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kSurfaceCurve3dTo2d (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kSurfaceSurfaceInt (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kTorus (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kTrimmedCrv2d (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kTrimmedCurve2d (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kTrimmedCurve3d (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kTrimmedSurface (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class ExternalBoundedSurface(Surface):
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...
    def cast (self, *args, **kwargs)-> PyGe.ExternalBoundedSurface :
      '''cast( (Entity3d)arg1) -> ExternalBoundedSurface :

    C++ signature :
        class PyGeExternalBoundedSurface cast(class PyGeEntity3d)'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def closestPointTo (self, *args, **kwargs)-> PyGe.Point3d :
      '''closestPointTo( (Surface)arg1, (Point3d)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d closestPointTo(class PyGeSurface {lvalue},class AcGePoint3d)

closestPointTo( (Surface)arg1, (Point3d)arg2, (Tol)arg3) -> Point3d :

    C++ signature :
        class AcGePoint3d closestPointTo(class PyGeSurface {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def copy (self)-> PyGe.Entity3d :
      '''Returns a pointer to a copy of this entity. This copy is created using the new and it is the responsibility of the caller to delete it.'''
    ...
    def copycast (self, *args, **kwargs)-> PyGe.ExternalBoundedSurface :
      '''copycast( (Entity3d)arg1) -> ExternalBoundedSurface :

    C++ signature :
        class PyGeExternalBoundedSurface copycast(class PyGeEntity3d)'''
    ...
    def distanceTo (self, *args, **kwargs)-> float :
      '''distanceTo( (Surface)arg1, (Point3d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeSurface {lvalue},class AcGePoint3d)

distanceTo( (Surface)arg1, (Point3d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeSurface {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def evalPoint (self, *args, **kwargs)-> PyGe.Point3d :
      '''evalPoint( (Surface)arg1, (Point2d)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d evalPoint(class PyGeSurface {lvalue},class AcGePoint2d)

evalPoint( (Surface)arg1, (Point2d)arg2, (int)arg3, (list)arg4) -> Point3d :

    C++ signature :
        class AcGePoint3d evalPoint(class PyGeSurface {lvalue},class AcGePoint2d,int,class boost::python::list {lvalue})

evalPoint( (Surface)arg1, (Point2d)arg2, (int)arg3, (list)arg4, (Vector3d)arg5) -> Point3d :

    C++ signature :
        class AcGePoint3d evalPoint(class PyGeSurface {lvalue},class AcGePoint2d,int,class boost::python::list {lvalue},class AcGeVector3d {lvalue})'''
    ...
    def isClosedInU (self, *args, **kwargs)-> bool :
      '''isClosedInU( (Surface)arg1) -> bool :

    C++ signature :
        bool isClosedInU(class PyGeSurface {lvalue})

isClosedInU( (Surface)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosedInU(class PyGeSurface {lvalue},class AcGeTol)'''
    ...
    def isClosedInV (self, *args, **kwargs)-> bool :
      '''isClosedInV( (Surface)arg1) -> bool :

    C++ signature :
        bool isClosedInV(class PyGeSurface {lvalue})

isClosedInV( (Surface)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosedInV(class PyGeSurface {lvalue},class AcGeTol)'''
    ...
    def isEqualTo (self, val : PyGe.Entity3d, tol : PyGe.Tol=None)-> bool :
      '''Determines if two entities are equal to each other. Two entities are considered to be equal only if they are of the same type and they represent the same 3D point set. For instance, if the two entities are of types AcGeCircArc3d and AcGeEllipArc3d then they are not considered equal even if the ellipse is completely coincident with the circle. Also, two curves are not considered equal unless they have the same parameterization. For instance, two infinite coincident lines are not considered equal if they have different scaling in their parameterization. '''
    ...
    def isKindOf (self, val : PyGe.EntityId)-> bool :
      '''                             '''
    ...
    def isNormalReversed (self, *args, **kwargs)-> bool :
      '''isNormalReversed( (Surface)arg1) -> bool :

    C++ signature :
        bool isNormalReversed(class PyGeSurface {lvalue})'''
    ...
    def isNull (self)-> bool :
      '''                             '''
    ...
    def isOn (self, *args, **kwargs)-> bool :
      '''isOn( (Surface)arg1, (Point3d)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeSurface {lvalue},class AcGePoint3d)

isOn( (Surface)arg1, (Point3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeSurface {lvalue},class AcGePoint3d,class AcGeTol)

isOn( (Surface)arg1, (Point3d)arg2, (Point2d)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeSurface {lvalue},class AcGePoint3d,class AcGePoint2d {lvalue})

isOn( (Surface)arg1, (Point3d)arg2, (Point2d)arg3, (Tol)arg4) -> bool :

    C++ signature :
        bool isOn(class PyGeSurface {lvalue},class AcGePoint3d,class AcGePoint2d {lvalue},class AcGeTol)'''
    ...
    def mirror (self, val : PyGe.Plane)-> None :
      '''Transforms the entity by mirroring it across the input plane.'''
    ...
    def paramOf (self, *args, **kwargs)-> PyGe.Point2d :
      '''paramOf( (Surface)arg1, (Point3d)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d paramOf(class PyGeSurface {lvalue},class AcGePoint3d)

paramOf( (Surface)arg1, (Point3d)arg2, (Tol)arg3) -> Point2d :

    C++ signature :
        class AcGePoint2d paramOf(class PyGeSurface {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def reverseNormal (self, *args, **kwargs)-> None :
      '''reverseNormal( (Surface)arg1) -> None :

    C++ signature :
        void reverseNormal(class PyGeSurface {lvalue})'''
    ...
    def rotateBy (self, angle : float, vec : PyGe.Vector3d, pt : PyGe.Point3d = 'origin')-> None :
      '''Rotates the entity by the input angle about the line defined by the input point and vector.'''
    ...
    def scaleBy (self, scaleFactor : float, pt : PyGe.Point3d = 'origin')-> None :
      '''Scales the entity about the input point by the input scale factor. Input scale factor must be greater than 0.'''
    ...
    def transformBy (self, val : PyGe.Matrix3d)-> None :
      '''Transforms the entity by applying the input matrix.'''
    ...
    def translateBy (self, vec : PyGe.Vector3d)-> None :
      '''Translates the entity by the input vector.'''
    ...
    def type (self)-> PyGe.EntityId :
      '''Returns the type of the entity.'''
    ...

class ExternalCurve2d(Curve2d):
    def __init__ (self, *args, **kwargs)-> None :
      '''Raises an exception
This class cannot be instantiated from Python'''
    ...
    def area (self, startParam : float, endParam : float, tol : float = None)-> float :
      '''                             '''
    ...
    def boundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock2d :
      '''                             '''
    ...
    def cast (self, *args, **kwargs)-> PyGe.ExternalCurve2d :
      '''cast( (Entity2d)arg1) -> ExternalCurve2d :

    C++ signature :
        class PyGeExternalCurve2d cast(class PyGeEntity2d)'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def closestPointTo (self, other : PyGe.Point2d | PyGe.Curve2d, tol : PyGe.Tol=None)-> PyGe.Point2d :
      '''                             '''
    ...
    def copy (self)-> PyGe.Entity2d :
      '''                             '''
    ...
    def copycast (self, *args, **kwargs)-> PyGe.ExternalCurve2d :
      '''copycast( (Entity2d)arg1) -> ExternalCurve2d :

    C++ signature :
        class PyGeExternalCurve2d copycast(class PyGeEntity2d)'''
    ...
    def distanceTo (self, pt : PyGe.Point2d | PyGe.Curve2d, tol : PyGe.Tol=None)-> float :
      '''                             '''
    ...
    def evalPoint (self, param : float, numDeriv : int = 1)-> PyGe.Point2d :
      '''                             '''
    ...
    def explode (self, val : PyGe.Interval = None)-> list :
      '''                             '''
    ...
    def getClosestPointTo (self, other : PyGe.Point2d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve2d :
      '''                             '''
    ...
    def getClosestPointsTo (self, other : PyGe.Curve2d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def getEndPoint (self)-> PyGe.Point2d :
      '''                             '''
    ...
    def getInterval (self)-> PyGe.Interval :
      '''                             '''
    ...
    def getNormalPoint (self, pnt : PyGe.Point2d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve2d :
      '''                             '''
    ...

    @overload
    def getSamplePoints (self, numSample: int)-> list : ...
    @overload
    def getSamplePoints (self, fromParam: float, toParam: float, approxEps: float)-> list : ...
    def getSamplePoints (self, *args, **kwargs)-> list :
      '''Overloads:
    - numSample: int
    - fromParam: float, toParam: float, approxEps: float
    '''
    ...
    def getSplitCurves (self, param : float)-> tuple :
      '''                             '''
    ...
    def getStartPoint (self)-> PyGe.Point2d :
      '''                             '''
    ...
    def getTrimmedOffset (self, dist : float, extensionType : PyGe.OffsetCrvExtType, tol : PyGe.Tol=None)-> list :
      '''                             '''
    ...
    def hasEndPoint (self)-> bool :
      '''                             '''
    ...
    def hasStartPoint (self)-> bool :
      '''                             '''
    ...
    def isClosed (self, tol : PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def isDegenerate (self, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isEqualTo (self, val : PyGe.Entity2d, tol : PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def isKindOf (self, val : PyGe.EntityId)-> bool :
      '''                             '''
    ...
    def isLinear (self, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isNull (self)-> bool :
      '''                             '''
    ...
    def isOn (self, pt : float | PyGe.Point2d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isPeriodic (self)-> tuple :
      '''                             '''
    ...
    def length (self, frm : float, to : float, tol : float = None)-> float :
      '''                             '''
    ...
    def mirror (self, val : PyGe.Line2d)-> None :
      '''                             '''
    ...
    def orthoBoundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock2d :
      '''                             '''
    ...
    def paramAtLength (self, datumParam: float, length: float, posParamDir: bool=True, tol: float=None)-> float :
      '''                             '''
    ...
    def paramOf (self, pt : PyGe.Point2d, tol : PyGe.Tol=None)-> float :
      '''                             '''
    ...
    def reverseParam (self)-> None :
      '''                             '''
    ...
    def rotateBy (self, angle : float, pt : PyGe.Point3d=PyGe.Point2d.kOrgin)-> None :
      '''                             '''
    ...
    def scaleBy (self, scaleFactor : float, pt : PyGe.Point2d=PyGe.Point2d.kOrgin)-> None :
      '''                             '''
    ...
    def setInterval (self, val : PyGe.Interval = None)-> None :
      '''                             '''
    ...
    def transformBy (self, val : PyGe.Matrix2d)-> None :
      '''                             '''
    ...
    def translateBy (self, vec : PyGe.Vector2d)-> None :
      '''                             '''
    ...
    def type (self)-> PyGe.EntityId :
      '''                             '''
    ...

class ExternalCurve3d(Curve3d):
    def __init__ (self, *args, **kwargs)-> None :
      '''Raises an exception
This class cannot be instantiated from Python'''
    ...
    def area (self, startParam : float, endParam : float, tol : float = None)-> float :
      '''Returns the area of the interval of the curve defined by startParam and endParam. Returns Adesk::kTrue if area was successfully computed to within the specified tolerance. If the curve is not planar, then the area cannot be calculated and a value of Adesk::kFalse is returned. If the points at startParam and endParam are the same, then this function returns the area of the closed curve. If the points are different, then this function connects the two points with a line segment and return the signed area between the curve and the line segment. If the line segment does not intersect the curve at any points between startParam and endParam, then the returned area is positive. If the line segment intersects the curves at any points between startParam and endParam, then the returned area is the sum of the sub-areas created by the intersection of the line segment with the curve. Each sub-area has a positive or negative area, depending on whether the curve lies above or below the line segment. The total area returned by this function can therefore be positive, negative, or 0. '''
    ...
    def boundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock3d :
      '''Returns the bounding box of the curve. The sides of the returned box are parallel to the coordinate axes. '''
    ...

    @staticmethod
    def cast (otherObject: PyGe.Entity3d)-> PyGe.ExternalCurve3d :
      '''                             '''
    ...

    @staticmethod
    def className ()-> str :
      '''                             '''
    ...
    def closestPointTo (self, other : PyGe.Point3d | PyGe.Curve3d, tol : PyGe.Tol=None)-> PyGe.Point3d :
      '''Finds the closest point on this curve to the input point. This function is the same as closestPointTo(), except that the closest point is returned as an AcGePointOnCurve3d object.'''
    ...
    def copy (self)-> PyGe.Entity3d :
      '''Returns a pointer to a copy of this entity. This copy is created using the new and it is the responsibility of the caller to delete it.'''
    ...

    @staticmethod
    def copycast (otherObject: PyGe.Entity3d)-> PyGe.ExternalCurve3d :
      '''                             '''
    ...
    def distanceTo (self, pt : PyGe.Point3d | PyGe.Curve3d, tol : PyGe.Tol=None)-> float :
      '''Returns the distance between the input point and the closest point on this curve.'''
    ...
    def evalPoint (self, param : float, numDeriv : int = 1)-> PyGe.Point3d :
      '''Returns the point on the curve that corresponds to the input parameter value. Also returns the number of derivative vectors that are specified in numDeriv. The numDeriv parameter should not be set larger than 2.'''
    ...
    def explode (self, val : PyGe.Interval = None)-> list :
      '''Explodes the curve into its individual components. If the curve is a composite curve, then explodedCurves contains the list of component curves of the composite. If the curve is a spline, then it is exploded at the points of C1 discontinuity and explodedCurves contains a copy of each continuous sub-curve. This function returns Adesk::kTrue if the curve was exploded (that is, the curve was a composite or a discontinuous spline) and Adesk::kFalse otherwise. The number of entries returned in newExplodedCurves is always the same as the number of entries in explodedCurves. Each flag in newExplodedCurves indicates whether the corresponding curve in explodedCurves was created with the new operator. If the flag is 1, then it is the responsibility of the caller to delete the curve. If the flag is 0, the curve is deleted by gelib and the caller should not attempt to delete it. If no intrvl parameter is supplied, then the interval is taken to be the entire curve. '''
    ...
    def getClosestPointTo (self, other : PyGe.Point3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''Finds the closest point on this curve to the input point. This function is the same as closestPointTo(), except that the closest point is returned as an AcGePointOnCurve3d object.'''
    ...
    def getClosestPointsTo (self, other : PyGe.Curve3d, tol : PyGe.Tol=None)-> tuple :
      '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
    ...
    def getEndPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def getInterval (self)-> PyGe.Interval :
      '''Returns the parametric range of the curve. The function evalPoint(double) always returns a point on this curve when called with a value within the returned interval.'''
    ...
    def getNormalPoint (self, pnt : PyGe.Point3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''Finds the point on the input curve whose normal passes through the input point. The returned point lies on a plane that also contains the input point and is perpendicular to the curve tangent at that point. The returned point is therefore at a local minimum or a local maximum from the input point. The curve does not need to be planar. If the curve is planar, the input point does not need to lie in the plane of the curve. On input, the second parameter is assumed to contain the parameter value of an initial guess. If there is more than one normal point on the curve, the returned point will be the one whose parameter value is closest to the input parameter value.'''
    ...
    def getProjClosestPointTo (self, pt : PyGe.Point3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
    ...
    def getProjClosestPointsTo (self, pt : PyGe.Curve3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> tuple :
      '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
    ...

    @overload
    def getSamplePoints (self, numSample: int)-> tuple : ...
    @overload
    def getSamplePoints (self, fromParam: float, toParam: float, approxEps: float)-> tuple : ...
    def getSamplePoints (self, *args, **kwargs)-> tuple :
      '''Overloads:
    - numSample: int
    - fromParam: float, toParam: float, approxEps: float
    
	-Returns the specified number of points on the curve. The points are equally spaced by parameter value. So if the interval of the curve [0,1] and numSample is 5, the parameter values of the returned points are 0, 0.25, 0.5, 0.75, and 1.-'''
    ...
    def getSplitCurves (self, param : float)-> tuple :
      '''Returns two segments which are obtained by splitting the curve at the input parameter value. If the specified parameter value does not lie within the parametric interval of the curve or if it corresponds to the start point or endpoint of the curve, then piece1 and piece2 are set to null. This function uses the new to create the curve segments whose addresses are returned in piece1 and piece2. It is the responsibility of the caller to delete these objects. '''
    ...
    def getStartPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def getTrimmedOffset (self, dist : float, planeNormal : PyGe.Vector3d, extensionType : PyGe.OffsetCrvExtType, tol : PyGe.Tol=None)-> list :
      '''Returns one or more offset curves that represent the trimmed offset of the curve. The curve must be planar and planeNormal must be perpendicular to the plane of the curve. The positive direction of offset at a point on the curve is taken to be the cross product of planeNormal with the tangent vector at that point. The curve may be offset in either of two directions by specifying a positive or negative offset distance; planeNormal determines which direction is the positive direction of offset. The returned offset curves are trimmed so that they do not contain any points of self-intersection. Each curve that is returned in offsetCurveList is created with the new and it is the responsibility of the caller to delete these curves. Each curve that is returned in offsetCurveList is a connected curve and may be a composite curve if the offset curve had to be trimmed to remove self-intersecting loops. offsetCurveList only contains more than one curve if the offset operation produces multiple curves which are not connected. If the original curve contains points of C1 discontinuity and the direction of offset causes the offset curve to be disjoint (for instance, if the original curve is a composite curve that is a rectangle and the direction of offset is to the outside of the rectangle), then the offset curve is closed with an arc or a line segment, or the curves are simply extended depending on the value of extensionType.'''
    ...
    def hasEndPoint (self)-> bool :
      '''Returns Adesk::kTrue if curve has an endpoint. A return value of Adesk::kFalse means that the parametric interval of the curve does not have an upper bound. The endPnt parameter contains meaningful data only if this function returns a value of Adesk::kTrue.'''
    ...
    def hasStartPoint (self)-> bool :
      '''Returns Adesk::kTrue if curve has a start point. A return value of Adesk::kFalse means that the parametric interval of the curve does not have a lower bound. The startPnt parameter contains meaningful data only if this function returns a value of Adesk::kTrue.'''
    ...
    def isClosed (self, tol : PyGe.Tol=None)-> bool :
      '''Determines if start point and endpoint of curve are the same.'''
    ...
    def isCoplanarWith (self, curve : PyGe.Curve3d, tol : PyGe.Tol=None)-> tuple :
      '''Returns Adesk::kTrue if both curve are planar and lie in the same plane. The plane parameter is only valid if this function returns a value of Adesk::kTrue.'''
    ...
    def isDegenerate (self, tol : PyGe.Tol=None)-> tuple :
      '''Determines if the curve is degenerate and if so returns the type of entity which the curve degenerates into. For example, if the curve is a circle with a radius of 0 then degenerateType is set to AcGe::kPoint3d. If the curve is an ellipse with a minor radius of 0 and a major radius of 1, then degenerateType is set to AcGe::kLineSeg3d. The degenerateType parameter is only set to something meaningful when this function returns a value of Adesk::kTrue.'''
    ...
    def isEqualTo (self, val : PyGe.Entity3d, tol : PyGe.Tol=None)-> bool :
      '''Determines if two entities are equal to each other. Two entities are considered to be equal only if they are of the same type and they represent the same 3D point set. For instance, if the two entities are of types AcGeCircArc3d and AcGeEllipArc3d then they are not considered equal even if the ellipse is completely coincident with the circle. Also, two curves are not considered equal unless they have the same parameterization. For instance, two infinite coincident lines are not considered equal if they have different scaling in their parameterization. '''
    ...
    def isKindOf (self, val : PyGe.EntityId)-> bool :
      '''                             '''
    ...
    def isLinear (self, tol : PyGe.Tol=None)-> tuple :
      '''Determines if curve is linear. This function returns an infinite line even if the curve is not infinite. The line parameter contains meaningful data only if this function returns a value of Adesk::kTrue.'''
    ...
    def isNull (self)-> bool :
      '''                             '''
    ...
    def isOn (self, pt : float | PyGe.Point3d, tol : PyGe.Tol=None)-> tuple :
      '''Determines if input parameter value is within valid parametric range of curve.'''
    ...
    def isPeriodic (self)-> tuple :
      '''Determines if the curve is periodic. The curve is periodic if and only if it is closed and the two points evalPoint(t) and evalPoint(t+period) are always the same point for all values of t.'''
    ...
    def isPlanar (self, tol : PyGe.Tol=None)-> tuple :
      '''Determines if curve is planar. If the curve is a line, then this function returns an arbitrary plane that contains the line. The plane parameter contains meaningful data only if this function returns a value of Adesk::kTrue. '''
    ...
    def length (self, frm : float, to : float, tol : float = None)-> float :
      '''Returns the arc length of the curve between the two parameter values.'''
    ...
    def mirror (self, val : PyGe.Plane)-> None :
      '''Transforms the entity by mirroring it across the input plane.'''
    ...
    def orthoBoundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock3d :
      '''Returns the bounding box of the curve. The sides of the returned box are parallel to the coordinate axes.'''
    ...
    def orthoProject (self, projectionPlane : PyGe.Plane, tol : PyGe.Tol=None)-> PyGe.Entity3d :
      '''Returns the entity that is the orthogonal projection of the curve onto the projection plane. The returned entity may not be of the same type as the original curve and may not even be a curve (for instance, a line projects into a point if it is orthogonal to the projection plane). The returned entity is created with the new and it is the responsibility of the caller to delete it.'''
    ...
    def paramAtLength (self, datumParam : float, length : float, posParamDir : bool=True, tol : float = default)-> float :
      '''Returns the parameter value of the point whose arc length distance (from the point with parameter value datumParam) is the input length. In other words, ift = paramAtLength (datumParam, len, posParamDir, tol) then length (t, datumParam, tol) is (approximately) equal to len. If posParamDir is set to Adesk::kTrue, then the returned parameter value is greater than datumParam. Otherwise it will be less than datumParam. '''
    ...
    def paramOf (self, pt : PyGe.Point3d, tol : PyGe.Tol=None)-> float :
      '''Returns the parameter value of pnt. This function assumes that pnt lies on the curve and does not verify this. If pnt does not lie on the curve, this function will return unpredictable results. If it is not known whether pnt lies on the curve, the user should not call this function but should instead call AcGeCurve3d::isOn (pnt, param, tol). '''
    ...
    def projClosestPointTo (self, pt : PyGe.Point3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.Point3d :
      '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
    ...
    def projClosestPointsTo (self, pt : PyGe.Curve3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> tuple :
      '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
    ...
    def project (self, projectionPlane : PyGe.Plane, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.Entity3d :
      '''Returns the entity that is the projection of the curve onto the projection plane in the specified direction. The projectDirection vector must not be parallel to the projection plane. The returned entity may not be of the same type as the original curve and may not even be a curve (for instance, a line projects into a point if it is parallel to projectDirection). The returned entity is created with the new and it is the responsibility of the caller to delete it.'''
    ...
    def reverseParam (self)-> None :
      '''Reverses the parametric direction of the curve. The point set of the curve is unchanged, but the direction of the curve is reversed.'''
    ...
    def rotateBy (self, angle : float, vec : PyGe.Vector3d, pt : PyGe.Point3d = 'origin')-> None :
      '''Rotates the entity by the input angle about the line defined by the input point and vector.'''
    ...
    def scaleBy (self, scaleFactor : float, pt : PyGe.Point3d = 'origin')-> None :
      '''Scales the entity about the input point by the input scale factor. Input scale factor must be greater than 0.'''
    ...
    def setInterval (self, val : PyGe.Interval = None)-> None :
      '''Sets the domain of the curve to the input interval.'''
    ...
    def transformBy (self, val : PyGe.Matrix3d)-> None :
      '''Transforms the entity by applying the input matrix.'''
    ...
    def translateBy (self, vec : PyGe.Vector3d)-> None :
      '''Translates the entity by the input vector.'''
    ...
    def type (self)-> PyGe.EntityId :
      '''Returns the type of the entity.'''
    ...

class ExternalSurface(Surface):
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...
    def cast (self, *args, **kwargs)-> PyGe.ExternalSurface :
      '''cast( (Entity3d)arg1) -> ExternalSurface :

    C++ signature :
        class PyGeExternalSurface cast(class PyGeEntity3d)'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def closestPointTo (self, *args, **kwargs)-> PyGe.Point3d :
      '''closestPointTo( (Surface)arg1, (Point3d)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d closestPointTo(class PyGeSurface {lvalue},class AcGePoint3d)

closestPointTo( (Surface)arg1, (Point3d)arg2, (Tol)arg3) -> Point3d :

    C++ signature :
        class AcGePoint3d closestPointTo(class PyGeSurface {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def copy (self)-> PyGe.Entity3d :
      '''Returns a pointer to a copy of this entity. This copy is created using the new and it is the responsibility of the caller to delete it.'''
    ...
    def copycast (self, *args, **kwargs)-> PyGe.ExternalSurface :
      '''copycast( (Entity3d)arg1) -> ExternalSurface :

    C++ signature :
        class PyGeExternalSurface copycast(class PyGeEntity3d)'''
    ...
    def distanceTo (self, *args, **kwargs)-> float :
      '''distanceTo( (Surface)arg1, (Point3d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeSurface {lvalue},class AcGePoint3d)

distanceTo( (Surface)arg1, (Point3d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeSurface {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def evalPoint (self, *args, **kwargs)-> PyGe.Point3d :
      '''evalPoint( (Surface)arg1, (Point2d)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d evalPoint(class PyGeSurface {lvalue},class AcGePoint2d)

evalPoint( (Surface)arg1, (Point2d)arg2, (int)arg3, (list)arg4) -> Point3d :

    C++ signature :
        class AcGePoint3d evalPoint(class PyGeSurface {lvalue},class AcGePoint2d,int,class boost::python::list {lvalue})

evalPoint( (Surface)arg1, (Point2d)arg2, (int)arg3, (list)arg4, (Vector3d)arg5) -> Point3d :

    C++ signature :
        class AcGePoint3d evalPoint(class PyGeSurface {lvalue},class AcGePoint2d,int,class boost::python::list {lvalue},class AcGeVector3d {lvalue})'''
    ...
    def isClosedInU (self, *args, **kwargs)-> bool :
      '''isClosedInU( (Surface)arg1) -> bool :

    C++ signature :
        bool isClosedInU(class PyGeSurface {lvalue})

isClosedInU( (Surface)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosedInU(class PyGeSurface {lvalue},class AcGeTol)'''
    ...
    def isClosedInV (self, *args, **kwargs)-> bool :
      '''isClosedInV( (Surface)arg1) -> bool :

    C++ signature :
        bool isClosedInV(class PyGeSurface {lvalue})

isClosedInV( (Surface)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosedInV(class PyGeSurface {lvalue},class AcGeTol)'''
    ...
    def isEqualTo (self, val : PyGe.Entity3d, tol : PyGe.Tol=None)-> bool :
      '''Determines if two entities are equal to each other. Two entities are considered to be equal only if they are of the same type and they represent the same 3D point set. For instance, if the two entities are of types AcGeCircArc3d and AcGeEllipArc3d then they are not considered equal even if the ellipse is completely coincident with the circle. Also, two curves are not considered equal unless they have the same parameterization. For instance, two infinite coincident lines are not considered equal if they have different scaling in their parameterization. '''
    ...
    def isKindOf (self, val : PyGe.EntityId)-> bool :
      '''                             '''
    ...
    def isNormalReversed (self, *args, **kwargs)-> bool :
      '''isNormalReversed( (Surface)arg1) -> bool :

    C++ signature :
        bool isNormalReversed(class PyGeSurface {lvalue})'''
    ...
    def isNull (self)-> bool :
      '''                             '''
    ...
    def isOn (self, *args, **kwargs)-> bool :
      '''isOn( (Surface)arg1, (Point3d)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeSurface {lvalue},class AcGePoint3d)

isOn( (Surface)arg1, (Point3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeSurface {lvalue},class AcGePoint3d,class AcGeTol)

isOn( (Surface)arg1, (Point3d)arg2, (Point2d)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeSurface {lvalue},class AcGePoint3d,class AcGePoint2d {lvalue})

isOn( (Surface)arg1, (Point3d)arg2, (Point2d)arg3, (Tol)arg4) -> bool :

    C++ signature :
        bool isOn(class PyGeSurface {lvalue},class AcGePoint3d,class AcGePoint2d {lvalue},class AcGeTol)'''
    ...
    def mirror (self, val : PyGe.Plane)-> None :
      '''Transforms the entity by mirroring it across the input plane.'''
    ...
    def paramOf (self, *args, **kwargs)-> PyGe.Point2d :
      '''paramOf( (Surface)arg1, (Point3d)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d paramOf(class PyGeSurface {lvalue},class AcGePoint3d)

paramOf( (Surface)arg1, (Point3d)arg2, (Tol)arg3) -> Point2d :

    C++ signature :
        class AcGePoint2d paramOf(class PyGeSurface {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def reverseNormal (self, *args, **kwargs)-> None :
      '''reverseNormal( (Surface)arg1) -> None :

    C++ signature :
        void reverseNormal(class PyGeSurface {lvalue})'''
    ...
    def rotateBy (self, angle : float, vec : PyGe.Vector3d, pt : PyGe.Point3d = 'origin')-> None :
      '''Rotates the entity by the input angle about the line defined by the input point and vector.'''
    ...
    def scaleBy (self, scaleFactor : float, pt : PyGe.Point3d = 'origin')-> None :
      '''Scales the entity about the input point by the input scale factor. Input scale factor must be greater than 0.'''
    ...
    def transformBy (self, val : PyGe.Matrix3d)-> None :
      '''Transforms the entity by applying the input matrix.'''
    ...
    def translateBy (self, vec : PyGe.Vector3d)-> None :
      '''Translates the entity by the input vector.'''
    ...
    def type (self)-> PyGe.EntityId :
      '''Returns the type of the entity.'''
    ...

class Interval(object):
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (float)arg2, (float)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,double,double)

__init__( (object)arg1, (bool)arg2, (float)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,bool,double)'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def contains (self, *args, **kwargs)-> bool :
      '''contains( (Interval)arg1, (Interval)arg2) -> bool :

    C++ signature :
        bool contains(class PyGeInterval {lvalue},class PyGeInterval)

contains( (Interval)arg1, (float)arg2) -> bool :

    C++ signature :
        bool contains(class PyGeInterval {lvalue},double)'''
    ...
    def element (self, *args, **kwargs)-> float :
      '''element( (Interval)arg1) -> float :

    C++ signature :
        double element(class PyGeInterval {lvalue})'''
    ...
    def getBounds (self, *args, **kwargs)-> tuple :
      '''getBounds( (Interval)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple getBounds(class PyGeInterval {lvalue})'''
    ...
    def getMerge (self, *args, **kwargs)-> None :
      '''getMerge( (Interval)arg1, (Interval)arg2, (Interval)arg3) -> None :

    C++ signature :
        void getMerge(class PyGeInterval {lvalue},class PyGeInterval,class PyGeInterval {lvalue})'''
    ...
    def intersectWith (self, *args, **kwargs)-> bool :
      '''intersectWith( (Interval)arg1, (Interval)arg2, (Interval)arg3) -> bool :

    C++ signature :
        bool intersectWith(class PyGeInterval {lvalue},class PyGeInterval,class PyGeInterval {lvalue})'''
    ...
    def isBounded (self, *args, **kwargs)-> bool :
      '''isBounded( (Interval)arg1) -> bool :

    C++ signature :
        bool isBounded(class PyGeInterval {lvalue})'''
    ...
    def isBoundedAbove (self, *args, **kwargs)-> bool :
      '''isBoundedAbove( (Interval)arg1) -> bool :

    C++ signature :
        bool isBoundedAbove(class PyGeInterval {lvalue})'''
    ...
    def isBoundedBelow (self, *args, **kwargs)-> bool :
      '''isBoundedBelow( (Interval)arg1) -> bool :

    C++ signature :
        bool isBoundedBelow(class PyGeInterval {lvalue})'''
    ...
    def isContinuousAtUpper (self, *args, **kwargs)-> bool :
      '''isContinuousAtUpper( (Interval)arg1, (Interval)arg2) -> bool :

    C++ signature :
        bool isContinuousAtUpper(class PyGeInterval {lvalue},class PyGeInterval)'''
    ...
    def isDisjoint (self, *args, **kwargs)-> bool :
      '''isDisjoint( (Interval)arg1, (Interval)arg2) -> bool :

    C++ signature :
        bool isDisjoint(class PyGeInterval {lvalue},class PyGeInterval)'''
    ...
    def isEqualAtLower (self, *args, **kwargs)-> bool :
      '''isEqualAtLower( (Interval)arg1, (Interval)arg2) -> bool :

    C++ signature :
        bool isEqualAtLower(class PyGeInterval {lvalue},class PyGeInterval)

isEqualAtLower( (Interval)arg1, (float)arg2) -> bool :

    C++ signature :
        bool isEqualAtLower(class PyGeInterval {lvalue},double)'''
    ...
    def isEqualAtUpper (self, *args, **kwargs)-> bool :
      '''isEqualAtUpper( (Interval)arg1, (Interval)arg2) -> bool :

    C++ signature :
        bool isEqualAtUpper(class PyGeInterval {lvalue},class PyGeInterval)

isEqualAtUpper( (Interval)arg1, (float)arg2) -> bool :

    C++ signature :
        bool isEqualAtUpper(class PyGeInterval {lvalue},double)'''
    ...
    def isGreater (self, *args, **kwargs)-> bool :
      '''isGreater( (Interval)arg1, (float)arg2) -> bool :

    C++ signature :
        bool isGreater(class PyGeInterval {lvalue},double)

isGreater( (Interval)arg1, (Interval)arg2) -> bool :

    C++ signature :
        bool isGreater(class PyGeInterval {lvalue},class PyGeInterval)'''
    ...
    def isGreaterOrEqual (self, *args, **kwargs)-> bool :
      '''isGreaterOrEqual( (Interval)arg1, (float)arg2) -> bool :

    C++ signature :
        bool isGreaterOrEqual(class PyGeInterval {lvalue},double)

isGreaterOrEqual( (Interval)arg1, (Interval)arg2) -> bool :

    C++ signature :
        bool isGreaterOrEqual(class PyGeInterval {lvalue},class PyGeInterval)'''
    ...
    def isLess (self, *args, **kwargs)-> bool :
      '''isLess( (Interval)arg1, (float)arg2) -> bool :

    C++ signature :
        bool isLess(class PyGeInterval {lvalue},double)

isLess( (Interval)arg1, (Interval)arg2) -> bool :

    C++ signature :
        bool isLess(class PyGeInterval {lvalue},class PyGeInterval)'''
    ...
    def isLessOrEqual (self, *args, **kwargs)-> bool :
      '''isLessOrEqual( (Interval)arg1, (float)arg2) -> bool :

    C++ signature :
        bool isLessOrEqual(class PyGeInterval {lvalue},double)

isLessOrEqual( (Interval)arg1, (Interval)arg2) -> bool :

    C++ signature :
        bool isLessOrEqual(class PyGeInterval {lvalue},class PyGeInterval)'''
    ...
    def isOverlapAtUpper (self, *args, **kwargs)-> bool :
      '''isOverlapAtUpper( (Interval)arg1, (Interval)arg2, (Interval)arg3) -> bool :

    C++ signature :
        bool isOverlapAtUpper(class PyGeInterval {lvalue},class PyGeInterval,class PyGeInterval {lvalue})'''
    ...
    def isPeriodicallyOn (self, *args, **kwargs)-> tuple :
      '''isPeriodicallyOn( (Interval)arg1, (float)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isPeriodicallyOn(class PyGeInterval {lvalue},double)'''
    ...
    def isSingleton (self, *args, **kwargs)-> bool :
      '''isSingleton( (Interval)arg1) -> bool :

    C++ signature :
        bool isSingleton(class PyGeInterval {lvalue})'''
    ...
    def isUnBounded (self, *args, **kwargs)-> bool :
      '''isUnBounded( (Interval)arg1) -> bool :

    C++ signature :
        bool isUnBounded(class PyGeInterval {lvalue})'''
    ...
    def length (self, *args, **kwargs)-> float :
      '''length( (Interval)arg1) -> float :

    C++ signature :
        double length(class PyGeInterval {lvalue})'''
    ...
    def lowerBound (self, *args, **kwargs)-> float :
      '''lowerBound( (Interval)arg1) -> float :

    C++ signature :
        double lowerBound(class PyGeInterval {lvalue})'''
    ...
    def set (self, *args, **kwargs)-> None :
      '''set( (Interval)arg1, (float)arg2, (float)arg3) -> None :

    C++ signature :
        void set(class PyGeInterval {lvalue},double,double)

set( (Interval)arg1, (bool)arg2, (float)arg3) -> None :

    C++ signature :
        void set(class PyGeInterval {lvalue},bool,double)

set( (Interval)arg1) -> None :

    C++ signature :
        void set(class PyGeInterval {lvalue})'''
    ...
    def setLower (self, *args, **kwargs)-> None :
      '''setLower( (Interval)arg1, (float)arg2) -> None :

    C++ signature :
        void setLower(class PyGeInterval {lvalue},double)'''
    ...
    def setTolerance (self, *args, **kwargs)-> None :
      '''setTolerance( (Interval)arg1, (float)arg2) -> None :

    C++ signature :
        void setTolerance(class PyGeInterval {lvalue},double)'''
    ...
    def setUpper (self, *args, **kwargs)-> None :
      '''setUpper( (Interval)arg1, (float)arg2) -> None :

    C++ signature :
        void setUpper(class PyGeInterval {lvalue},double)'''
    ...
    def subtract (self, *args, **kwargs)-> int :
      '''subtract( (Interval)arg1, (Interval)arg2, (Interval)arg3, (Interval)arg4) -> int :

    C++ signature :
        int subtract(class PyGeInterval {lvalue},class PyGeInterval,class PyGeInterval {lvalue},class PyGeInterval {lvalue})'''
    ...
    def tolerance (self, *args, **kwargs)-> float :
      '''tolerance( (Interval)arg1) -> float :

    C++ signature :
        double tolerance(class PyGeInterval {lvalue})'''
    ...
    def upperBound (self, *args, **kwargs)-> float :
      '''upperBound( (Interval)arg1) -> float :

    C++ signature :
        double upperBound(class PyGeInterval {lvalue})'''
    ...

class KnotParameterization(object):
    def __add__ (self, value, /) :
      '''Return self+value.'''
    ...
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def __mul__ (self, value, /) :
      '''Return self*value.'''
    ...
    def __rmul__ (self, value, /) :
      '''Return value*self.'''
    ...
    def __sub__ (self, value, /) :
      '''Return self-value.'''
    ...
    def __truediv__ (self, value, /) :
      '''Return self/value.'''
    ...
    def kChord (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kCustomParameterization (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kNotDefinedKnotParam (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kSqrtChord (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kUniform (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class KnotVector(object):
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (int)arg2, (int)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,int,int)

__init__( (object)arg1, (list)arg2) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class boost::python::list)

__init__( (object)arg1, (int)arg2, (KnotVector)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,int,class PyGeKnotVector)'''
    ...
    def append (self, *args, **kwargs)-> int :
      '''append( (KnotVector)arg1, (float)arg2) -> int :

    C++ signature :
        int append(class PyGeKnotVector {lvalue},double)

append( (KnotVector)arg1, (KnotVector)arg2) -> None :

    C++ signature :
        void append(class PyGeKnotVector {lvalue},class PyGeKnotVector {lvalue})

append( (KnotVector)arg1, (KnotVector)arg2, (float)arg3) -> None :

    C++ signature :
        void append(class PyGeKnotVector {lvalue},class PyGeKnotVector {lvalue},double)'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def contains (self, *args, **kwargs)-> bool :
      '''contains( (KnotVector)arg1, (float)arg2) -> bool :

    C++ signature :
        bool contains(class PyGeKnotVector {lvalue},double)'''
    ...
    def endParam (self, *args, **kwargs)-> float :
      '''endParam( (KnotVector)arg1) -> float :

    C++ signature :
        double endParam(class PyGeKnotVector {lvalue})'''
    ...
    def getDistinctKnots (self, *args, **kwargs)-> list :
      '''getDistinctKnots( (KnotVector)arg1) -> list :

    C++ signature :
        class boost::python::list getDistinctKnots(class PyGeKnotVector {lvalue})'''
    ...
    def getInterval (self, *args, **kwargs)-> tuple :
      '''getInterval( (KnotVector)arg1, (int)arg2, (float)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple getInterval(class PyGeKnotVector {lvalue},int,double)'''
    ...
    def growLength (self, *args, **kwargs)-> int :
      '''growLength( (KnotVector)arg1) -> int :

    C++ signature :
        int growLength(class PyGeKnotVector {lvalue})'''
    ...
    def insert (self, *args, **kwargs)-> None :
      '''insert( (KnotVector)arg1, (float)arg2) -> None :

    C++ signature :
        void insert(class PyGeKnotVector {lvalue},double)'''
    ...
    def insertAt (self, *args, **kwargs)-> None :
      '''insertAt( (KnotVector)arg1, (int)arg2, (float)arg3) -> None :

    C++ signature :
        void insertAt(class PyGeKnotVector {lvalue},int,double)

insertAt( (KnotVector)arg1, (int)arg2, (float)arg3, (int)arg4) -> None :

    C++ signature :
        void insertAt(class PyGeKnotVector {lvalue},int,double,int)'''
    ...
    def isEmpty (self, *args, **kwargs)-> bool :
      '''isEmpty( (KnotVector)arg1) -> bool :

    C++ signature :
        bool isEmpty(class PyGeKnotVector {lvalue})'''
    ...
    def isEqualTo (self, *args, **kwargs)-> bool :
      '''isEqualTo( (KnotVector)arg1, (KnotVector)arg2) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeKnotVector {lvalue},class PyGeKnotVector)'''
    ...
    def isOn (self, *args, **kwargs)-> bool :
      '''isOn( (KnotVector)arg1, (float)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeKnotVector {lvalue},double)'''
    ...
    def length (self, *args, **kwargs)-> int :
      '''length( (KnotVector)arg1) -> int :

    C++ signature :
        int length(class PyGeKnotVector {lvalue})'''
    ...
    def logicalLength (self, *args, **kwargs)-> int :
      '''logicalLength( (KnotVector)arg1) -> int :

    C++ signature :
        int logicalLength(class PyGeKnotVector {lvalue})'''
    ...
    def multiplicityAt (self, *args, **kwargs)-> int :
      '''multiplicityAt( (KnotVector)arg1, (int)arg2) -> int :

    C++ signature :
        int multiplicityAt(class PyGeKnotVector {lvalue},int)'''
    ...
    def multiplicityAtParam (self, *args, **kwargs)-> int :
      '''multiplicityAtParam( (KnotVector)arg1, (float)arg2) -> int :

    C++ signature :
        int multiplicityAtParam(class PyGeKnotVector {lvalue},double)'''
    ...
    def numIntervals (self, *args, **kwargs)-> int :
      '''numIntervals( (KnotVector)arg1) -> int :

    C++ signature :
        int numIntervals(class PyGeKnotVector {lvalue})'''
    ...
    def physicalLength (self, *args, **kwargs)-> int :
      '''physicalLength( (KnotVector)arg1) -> int :

    C++ signature :
        int physicalLength(class PyGeKnotVector {lvalue})'''
    ...
    def removeAt (self, *args, **kwargs)-> None :
      '''removeAt( (KnotVector)arg1, (int)arg2) -> None :

    C++ signature :
        void removeAt(class PyGeKnotVector {lvalue},int)'''
    ...
    def removeSubVector (self, *args, **kwargs)-> None :
      '''removeSubVector( (KnotVector)arg1, (int)arg2, (int)arg3) -> None :

    C++ signature :
        void removeSubVector(class PyGeKnotVector {lvalue},int,int)'''
    ...
    def reverse (self, *args, **kwargs)-> None :
      '''reverse( (KnotVector)arg1) -> None :

    C++ signature :
        void reverse(class PyGeKnotVector {lvalue})'''
    ...
    def setGrowLength (self, *args, **kwargs)-> None :
      '''setGrowLength( (KnotVector)arg1, (int)arg2) -> None :

    C++ signature :
        void setGrowLength(class PyGeKnotVector {lvalue},int)'''
    ...
    def setLogicalLength (self, *args, **kwargs)-> None :
      '''setLogicalLength( (KnotVector)arg1, (int)arg2) -> None :

    C++ signature :
        void setLogicalLength(class PyGeKnotVector {lvalue},int)'''
    ...
    def setPhysicalLength (self, *args, **kwargs)-> None :
      '''setPhysicalLength( (KnotVector)arg1, (int)arg2) -> None :

    C++ signature :
        void setPhysicalLength(class PyGeKnotVector {lvalue},int)'''
    ...
    def setRange (self, *args, **kwargs)-> None :
      '''setRange( (KnotVector)arg1, (float)arg2, (float)arg3) -> None :

    C++ signature :
        void setRange(class PyGeKnotVector {lvalue},double,double)'''
    ...
    def setTolerance (self, *args, **kwargs)-> None :
      '''setTolerance( (KnotVector)arg1, (float)arg2) -> None :

    C++ signature :
        void setTolerance(class PyGeKnotVector {lvalue},double)'''
    ...
    def split (self, *args, **kwargs)-> tuple :
      '''split( (KnotVector)arg1, (float)arg2, (int)arg3, (int)arg4) -> tuple :

    C++ signature :
        class boost::python::tuple split(class PyGeKnotVector {lvalue},double,int,int)'''
    ...
    def startParam (self, *args, **kwargs)-> float :
      '''startParam( (KnotVector)arg1) -> float :

    C++ signature :
        double startParam(class PyGeKnotVector {lvalue})'''
    ...
    def tolerance (self, *args, **kwargs)-> float :
      '''tolerance( (KnotVector)arg1) -> float :

    C++ signature :
        double tolerance(class PyGeKnotVector {lvalue})'''
    ...

class Line2d(LinearEnt2d):
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (Point2d)arg2, (Vector2d)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePoint2d,class AcGeVector2d)

__init__( (object)arg1, (Point2d)arg2, (Point2d)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePoint2d,class AcGePoint2d)'''
    ...
    def area (self, startParam : float, endParam : float, tol : float = None)-> float :
      '''                             '''
    ...
    def boundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock2d :
      '''                             '''
    ...
    def cast (self, *args, **kwargs)-> PyGe.Line2d :
      '''cast( (Entity2d)arg1) -> Line2d :

    C++ signature :
        class PyGeLine2d cast(class PyGeEntity2d)'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def closestPointTo (self, other : PyGe.Point2d | PyGe.Curve2d, tol : PyGe.Tol=None)-> PyGe.Point2d :
      '''                             '''
    ...
    def copy (self)-> PyGe.Entity2d :
      '''                             '''
    ...
    def copycast (self, *args, **kwargs)-> PyGe.Line2d :
      '''copycast( (Entity2d)arg1) -> Line2d :

    C++ signature :
        class PyGeLine2d copycast(class PyGeEntity2d)'''
    ...
    def direction (self, *args, **kwargs)-> PyGe.Vector2d :
      '''direction( (LinearEnt2d)arg1) -> Vector2d :

    C++ signature :
        class AcGeVector2d direction(class PyGeLinearEnt2d {lvalue})'''
    ...
    def distanceTo (self, pt : PyGe.Point2d | PyGe.Curve2d, tol : PyGe.Tol=None)-> float :
      '''                             '''
    ...
    def evalPoint (self, param : float, numDeriv : int = 1)-> PyGe.Point2d :
      '''                             '''
    ...
    def explode (self, val : PyGe.Interval = None)-> list :
      '''                             '''
    ...
    def getClosestPointTo (self, other : PyGe.Point2d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve2d :
      '''                             '''
    ...
    def getClosestPointsTo (self, other : PyGe.Curve2d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def getEndPoint (self)-> PyGe.Point2d :
      '''                             '''
    ...
    def getInterval (self)-> PyGe.Interval :
      '''                             '''
    ...
    def getLine (self, *args, **kwargs)-> PyGe.Line2d :
      '''getLine( (LinearEnt2d)arg1) -> Line2d :

    C++ signature :
        class PyGeLine2d getLine(class PyGeLinearEnt2d {lvalue})'''
    ...
    def getNormalPoint (self, pnt : PyGe.Point2d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve2d :
      '''                             '''
    ...
    def getPerpLine (self, *args, **kwargs)-> PyGe.Line2d :
      '''getPerpLine( (LinearEnt2d)arg1, (Point2d)arg2) -> Line2d :

    C++ signature :
        class PyGeLine2d getPerpLine(class PyGeLinearEnt2d {lvalue},class AcGePoint2d)'''
    ...

    @overload
    def getSamplePoints (self, numSample: int)-> list : ...
    @overload
    def getSamplePoints (self, fromParam: float, toParam: float, approxEps: float)-> list : ...
    def getSamplePoints (self, *args, **kwargs)-> list :
      '''Overloads:
    - numSample: int
    - fromParam: float, toParam: float, approxEps: float
    '''
    ...
    def getSplitCurves (self, param : float)-> tuple :
      '''                             '''
    ...
    def getStartPoint (self)-> PyGe.Point2d :
      '''                             '''
    ...
    def getTrimmedOffset (self, dist : float, extensionType : PyGe.OffsetCrvExtType, tol : PyGe.Tol=None)-> list :
      '''                             '''
    ...
    def hasEndPoint (self)-> bool :
      '''                             '''
    ...
    def hasStartPoint (self)-> bool :
      '''                             '''
    ...
    def intersectWith (self, *args, **kwargs)-> tuple :
      '''intersectWith( (LinearEnt2d)arg1, (LinearEnt2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d)

intersectWith( (LinearEnt2d)arg1, (LinearEnt2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d,class AcGeTol)'''
    ...
    def isClosed (self, tol : PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def isColinearTo (self, *args, **kwargs)-> bool :
      '''isColinearTo( (LinearEnt2d)arg1, (LinearEnt2d)arg2) -> bool :

    C++ signature :
        bool isColinearTo(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d)

isColinearTo( (LinearEnt2d)arg1, (LinearEnt2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isColinearTo(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d,class AcGeTol)'''
    ...
    def isDegenerate (self, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isEqualTo (self, val : PyGe.Entity2d, tol : PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def isKindOf (self, val : PyGe.EntityId)-> bool :
      '''                             '''
    ...
    def isLinear (self, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isNull (self)-> bool :
      '''                             '''
    ...
    def isOn (self, pt : float | PyGe.Point2d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isParallelTo (self, *args, **kwargs)-> bool :
      '''isParallelTo( (LinearEnt2d)arg1, (LinearEnt2d)arg2) -> bool :

    C++ signature :
        bool isParallelTo(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d)

isParallelTo( (LinearEnt2d)arg1, (LinearEnt2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isParallelTo(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d,class AcGeTol)'''
    ...
    def isPeriodic (self)-> tuple :
      '''                             '''
    ...
    def isPerpendicularTo (self, *args, **kwargs)-> bool :
      '''isPerpendicularTo( (LinearEnt2d)arg1, (LinearEnt2d)arg2) -> bool :

    C++ signature :
        bool isPerpendicularTo(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d)

isPerpendicularTo( (LinearEnt2d)arg1, (LinearEnt2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isPerpendicularTo(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d,class AcGeTol)'''
    ...
    def kXAxis (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kYAxis (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def length (self, frm : float, to : float, tol : float = None)-> float :
      '''                             '''
    ...
    def mirror (self, val : PyGe.Line2d)-> None :
      '''                             '''
    ...
    def orthoBoundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock2d :
      '''                             '''
    ...
    def overlap (self, *args, **kwargs)-> tuple :
      '''overlap( (LinearEnt2d)arg1, (LinearEnt2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple overlap(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d)

overlap( (LinearEnt2d)arg1, (LinearEnt2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple overlap(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d,class AcGeTol)'''
    ...
    def paramAtLength (self, datumParam: float, length: float, posParamDir: bool=True, tol: float=None)-> float :
      '''                             '''
    ...
    def paramOf (self, pt : PyGe.Point2d, tol : PyGe.Tol=None)-> float :
      '''                             '''
    ...
    def pointOnLine (self, *args, **kwargs)-> PyGe.Point2d :
      '''pointOnLine( (LinearEnt2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d pointOnLine(class PyGeLinearEnt2d {lvalue})'''
    ...
    def reverseParam (self)-> None :
      '''                             '''
    ...
    def rotateBy (self, angle : float, pt : PyGe.Point3d=PyGe.Point2d.kOrgin)-> None :
      '''                             '''
    ...
    def scaleBy (self, scaleFactor : float, pt : PyGe.Point2d=PyGe.Point2d.kOrgin)-> None :
      '''                             '''
    ...
    def set (self, *args, **kwargs)-> None :
      '''set( (Line2d)arg1, (Point2d)arg2, (Vector2d)arg3) -> None :

    C++ signature :
        void set(class PyGeLine2d {lvalue},class AcGePoint2d,class AcGeVector2d)

set( (Line2d)arg1, (Point2d)arg2, (Point2d)arg3) -> None :

    C++ signature :
        void set(class PyGeLine2d {lvalue},class AcGePoint2d,class AcGePoint2d)'''
    ...
    def setInterval (self, val : PyGe.Interval = None)-> None :
      '''                             '''
    ...
    def transformBy (self, val : PyGe.Matrix2d)-> None :
      '''                             '''
    ...
    def translateBy (self, vec : PyGe.Vector2d)-> None :
      '''                             '''
    ...
    def type (self)-> PyGe.EntityId :
      '''                             '''
    ...

class Line3d(LinearEnt3d):

    @overload
    def __init__ (self, /)-> None : ...
    @overload
    def __init__ (self, startPoint: PyGe.Point3d, endPoint: PyGe.Point3d)-> None : ...
    @overload
    def __init__ (self, startPoint: PyGe.Point3d, direction: PyGe.Vector3d)-> None : ...
    def __init__ (self, *args, **kwargs)-> None :
      '''Overloads:
    - None: Any
    - startPoint: PyGe.Point3d, endPoint: PyGe.Point3d
    - startPoint: PyGe.Point3d, direction: PyGe.Vector3d
    '''
    ...
    def area (self, startParam : float, endParam : float, tol : float = None)-> float :
      '''Returns the area of the interval of the curve defined by startParam and endParam. Returns Adesk::kTrue if area was successfully computed to within the specified tolerance. If the curve is not planar, then the area cannot be calculated and a value of Adesk::kFalse is returned. If the points at startParam and endParam are the same, then this function returns the area of the closed curve. If the points are different, then this function connects the two points with a line segment and return the signed area between the curve and the line segment. If the line segment does not intersect the curve at any points between startParam and endParam, then the returned area is positive. If the line segment intersects the curves at any points between startParam and endParam, then the returned area is the sum of the sub-areas created by the intersection of the line segment with the curve. Each sub-area has a positive or negative area, depending on whether the curve lies above or below the line segment. The total area returned by this function can therefore be positive, negative, or 0. '''
    ...
    def boundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock3d :
      '''Returns the bounding box of the curve. The sides of the returned box are parallel to the coordinate axes. '''
    ...

    @staticmethod
    def cast (otherObject: PyGe.Entity3d)-> PyGe.Line3d :
      '''                             '''
    ...

    @staticmethod
    def className ()-> str :
      '''                             '''
    ...
    def closestPointTo (self, other : PyGe.Point3d | PyGe.Curve3d, tol : PyGe.Tol=None)-> PyGe.Point3d :
      '''Finds the closest point on this curve to the input point. This function is the same as closestPointTo(), except that the closest point is returned as an AcGePointOnCurve3d object.'''
    ...
    def copy (self)-> PyGe.Entity3d :
      '''Returns a pointer to a copy of this entity. This copy is created using the new and it is the responsibility of the caller to delete it.'''
    ...

    @staticmethod
    def copycast (otherObject: PyGe.Entity3d)-> PyGe.Line3d :
      '''                             '''
    ...
    def direction (self)-> PyGe.Vector3d :
      '''                             '''
    ...
    def distanceTo (self, pt : PyGe.Point3d | PyGe.Curve3d, tol : PyGe.Tol=None)-> float :
      '''Returns the distance between the input point and the closest point on this curve.'''
    ...
    def evalPoint (self, param : float, numDeriv : int = 1)-> PyGe.Point3d :
      '''Returns the point on the curve that corresponds to the input parameter value. Also returns the number of derivative vectors that are specified in numDeriv. The numDeriv parameter should not be set larger than 2.'''
    ...
    def explode (self, val : PyGe.Interval = None)-> list :
      '''Explodes the curve into its individual components. If the curve is a composite curve, then explodedCurves contains the list of component curves of the composite. If the curve is a spline, then it is exploded at the points of C1 discontinuity and explodedCurves contains a copy of each continuous sub-curve. This function returns Adesk::kTrue if the curve was exploded (that is, the curve was a composite or a discontinuous spline) and Adesk::kFalse otherwise. The number of entries returned in newExplodedCurves is always the same as the number of entries in explodedCurves. Each flag in newExplodedCurves indicates whether the corresponding curve in explodedCurves was created with the new operator. If the flag is 1, then it is the responsibility of the caller to delete the curve. If the flag is 0, the curve is deleted by gelib and the caller should not attempt to delete it. If no intrvl parameter is supplied, then the interval is taken to be the entire curve. '''
    ...
    def getClosestPointTo (self, other : PyGe.Point3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''Finds the closest point on this curve to the input point. This function is the same as closestPointTo(), except that the closest point is returned as an AcGePointOnCurve3d object.'''
    ...
    def getClosestPointsTo (self, other : PyGe.Curve3d, tol : PyGe.Tol=None)-> tuple :
      '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
    ...
    def getEndPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def getInterval (self)-> PyGe.Interval :
      '''Returns the parametric range of the curve. The function evalPoint(double) always returns a point on this curve when called with a value within the returned interval.'''
    ...
    def getLine (self)-> PyGe.Line3d :
      '''                             '''
    ...
    def getNormalPoint (self, pnt : PyGe.Point3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''Finds the point on the input curve whose normal passes through the input point. The returned point lies on a plane that also contains the input point and is perpendicular to the curve tangent at that point. The returned point is therefore at a local minimum or a local maximum from the input point. The curve does not need to be planar. If the curve is planar, the input point does not need to lie in the plane of the curve. On input, the second parameter is assumed to contain the parameter value of an initial guess. If there is more than one normal point on the curve, the returned point will be the one whose parameter value is closest to the input parameter value.'''
    ...
    def getPerpPlane (self, pt: PyGe.Point3d)-> PyGe.Plane :
      '''                             '''
    ...
    def getProjClosestPointTo (self, pt : PyGe.Point3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
    ...
    def getProjClosestPointsTo (self, pt : PyGe.Curve3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> tuple :
      '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
    ...

    @overload
    def getSamplePoints (self, numSample: int)-> tuple : ...
    @overload
    def getSamplePoints (self, fromParam: float, toParam: float, approxEps: float)-> tuple : ...
    def getSamplePoints (self, *args, **kwargs)-> tuple :
      '''Overloads:
    - numSample: int
    - fromParam: float, toParam: float, approxEps: float
    
	-Returns the specified number of points on the curve. The points are equally spaced by parameter value. So if the interval of the curve [0,1] and numSample is 5, the parameter values of the returned points are 0, 0.25, 0.5, 0.75, and 1.-'''
    ...
    def getSplitCurves (self, param : float)-> tuple :
      '''Returns two segments which are obtained by splitting the curve at the input parameter value. If the specified parameter value does not lie within the parametric interval of the curve or if it corresponds to the start point or endpoint of the curve, then piece1 and piece2 are set to null. This function uses the new to create the curve segments whose addresses are returned in piece1 and piece2. It is the responsibility of the caller to delete these objects. '''
    ...
    def getStartPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def getTrimmedOffset (self, dist : float, planeNormal : PyGe.Vector3d, extensionType : PyGe.OffsetCrvExtType, tol : PyGe.Tol=None)-> list :
      '''Returns one or more offset curves that represent the trimmed offset of the curve. The curve must be planar and planeNormal must be perpendicular to the plane of the curve. The positive direction of offset at a point on the curve is taken to be the cross product of planeNormal with the tangent vector at that point. The curve may be offset in either of two directions by specifying a positive or negative offset distance; planeNormal determines which direction is the positive direction of offset. The returned offset curves are trimmed so that they do not contain any points of self-intersection. Each curve that is returned in offsetCurveList is created with the new and it is the responsibility of the caller to delete these curves. Each curve that is returned in offsetCurveList is a connected curve and may be a composite curve if the offset curve had to be trimmed to remove self-intersecting loops. offsetCurveList only contains more than one curve if the offset operation produces multiple curves which are not connected. If the original curve contains points of C1 discontinuity and the direction of offset causes the offset curve to be disjoint (for instance, if the original curve is a composite curve that is a rectangle and the direction of offset is to the outside of the rectangle), then the offset curve is closed with an arc or a line segment, or the curves are simply extended depending on the value of extensionType.'''
    ...
    def hasEndPoint (self)-> bool :
      '''Returns Adesk::kTrue if curve has an endpoint. A return value of Adesk::kFalse means that the parametric interval of the curve does not have an upper bound. The endPnt parameter contains meaningful data only if this function returns a value of Adesk::kTrue.'''
    ...
    def hasStartPoint (self)-> bool :
      '''Returns Adesk::kTrue if curve has a start point. A return value of Adesk::kFalse means that the parametric interval of the curve does not have a lower bound. The startPnt parameter contains meaningful data only if this function returns a value of Adesk::kTrue.'''
    ...
    def intersectWith (self, other: PyGe.LinearEnt3d | PyGe.PlanarEnt, tol: PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isClosed (self, tol : PyGe.Tol=None)-> bool :
      '''Determines if start point and endpoint of curve are the same.'''
    ...
    def isColinearTo (self, pt: PyGe.LinearEnt3d, tol: PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def isCoplanarWith (self, curve : PyGe.Curve3d, tol : PyGe.Tol=None)-> tuple :
      '''Returns Adesk::kTrue if both curve are planar and lie in the same plane. The plane parameter is only valid if this function returns a value of Adesk::kTrue.'''
    ...
    def isDegenerate (self, tol : PyGe.Tol=None)-> tuple :
      '''Determines if the curve is degenerate and if so returns the type of entity which the curve degenerates into. For example, if the curve is a circle with a radius of 0 then degenerateType is set to AcGe::kPoint3d. If the curve is an ellipse with a minor radius of 0 and a major radius of 1, then degenerateType is set to AcGe::kLineSeg3d. The degenerateType parameter is only set to something meaningful when this function returns a value of Adesk::kTrue.'''
    ...
    def isEqualTo (self, val : PyGe.Entity3d, tol : PyGe.Tol=None)-> bool :
      '''Determines if two entities are equal to each other. Two entities are considered to be equal only if they are of the same type and they represent the same 3D point set. For instance, if the two entities are of types AcGeCircArc3d and AcGeEllipArc3d then they are not considered equal even if the ellipse is completely coincident with the circle. Also, two curves are not considered equal unless they have the same parameterization. For instance, two infinite coincident lines are not considered equal if they have different scaling in their parameterization. '''
    ...
    def isKindOf (self, val : PyGe.EntityId)-> bool :
      '''                             '''
    ...
    def isLinear (self, tol : PyGe.Tol=None)-> tuple :
      '''Determines if curve is linear. This function returns an infinite line even if the curve is not infinite. The line parameter contains meaningful data only if this function returns a value of Adesk::kTrue.'''
    ...
    def isNull (self)-> bool :
      '''                             '''
    ...

    @overload
    def isOn (self, pnt: PyGe.Point3d)-> tuple : ...
    @overload
    def isOn (self, pnt: PyGe.Point3d, tol: PyGe.Tol)-> tuple : ...
    @overload
    def isOn (self, param: float)-> tuple : ...
    @overload
    def isOn (self, param: float, tol: PyGe.Tol)-> tuple : ...
    @overload
    def isOn (self, plane: PyGe.Plane)-> tuple : ...
    @overload
    def isOn (self, plane: PyGe.Plane, tol: PyGe.Tol)-> tuple : ...
    def isOn (self, *args, **kwargs)-> tuple :
      '''Overloads:
    - pnt: PyGe.Point3d
    - pnt: PyGe.Point3d, tol: PyGe.Tol
    - param: float
    - param: float, tol: PyGe.Tol
    - plane: PyGe.Plane
    - plane: PyGe.Plane, tol: PyGe.Tol
    '''
    ...

    @overload
    def isParallelTo (self, line: PyGe.LinearEnt3d)-> bool : ...
    @overload
    def isParallelTo (self, line: PyGe.LinearEnt3d, tol: PyGe.Tol)-> bool : ...
    @overload
    def isParallelTo (self, line: PyGe.PlanarEnt)-> bool : ...
    @overload
    def isParallelTo (self, line: PyGe.PlanarEnt, tol: PyGe.Tol)-> bool : ...
    def isParallelTo (self, *args, **kwargs)-> bool :
      '''Overloads:
    - line: PyGe.LinearEnt3d
    - line: PyGe.LinearEnt3d, tol: PyGe.Tol
    - line: PyGe.PlanarEnt
    - line: PyGe.PlanarEnt, tol: PyGe.Tol
    '''
    ...
    def isPeriodic (self)-> tuple :
      '''Determines if the curve is periodic. The curve is periodic if and only if it is closed and the two points evalPoint(t) and evalPoint(t+period) are always the same point for all values of t.'''
    ...

    @overload
    def isPerpendicularTo (self, line: PyGe.LinearEnt3d)-> bool : ...
    @overload
    def isPerpendicularTo (self, line: PyGe.LinearEnt3d, tol: PyGe.Tol)-> bool : ...
    @overload
    def isPerpendicularTo (self, line: PyGe.PlanarEnt)-> bool : ...
    @overload
    def isPerpendicularTo (self, line: PyGe.PlanarEnt, tol: PyGe.Tol)-> bool : ...
    def isPerpendicularTo (self, *args, **kwargs)-> bool :
      '''Overloads:
    - line: PyGe.LinearEnt3d
    - line: PyGe.LinearEnt3d, tol: PyGe.Tol
    - line: PyGe.PlanarEnt
    - line: PyGe.PlanarEnt, tol: PyGe.Tol
    '''
    ...
    def isPlanar (self, tol : PyGe.Tol=None)-> tuple :
      '''Determines if curve is planar. If the curve is a line, then this function returns an arbitrary plane that contains the line. The plane parameter contains meaningful data only if this function returns a value of Adesk::kTrue. '''
    ...
    def kXAxis (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kYAxis (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kZAxis (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def length (self, frm : float, to : float, tol : float = None)-> float :
      '''Returns the arc length of the curve between the two parameter values.'''
    ...
    def mirror (self, val : PyGe.Plane)-> None :
      '''Transforms the entity by mirroring it across the input plane.'''
    ...
    def orthoBoundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock3d :
      '''Returns the bounding box of the curve. The sides of the returned box are parallel to the coordinate axes.'''
    ...
    def orthoProject (self, projectionPlane : PyGe.Plane, tol : PyGe.Tol=None)-> PyGe.Entity3d :
      '''Returns the entity that is the orthogonal projection of the curve onto the projection plane. The returned entity may not be of the same type as the original curve and may not even be a curve (for instance, a line projects into a point if it is orthogonal to the projection plane). The returned entity is created with the new and it is the responsibility of the caller to delete it.'''
    ...
    def overlap (self, other: PyGe.LinearEnt3d, tol: PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def paramAtLength (self, datumParam : float, length : float, posParamDir : bool=True, tol : float = default)-> float :
      '''Returns the parameter value of the point whose arc length distance (from the point with parameter value datumParam) is the input length. In other words, ift = paramAtLength (datumParam, len, posParamDir, tol) then length (t, datumParam, tol) is (approximately) equal to len. If posParamDir is set to Adesk::kTrue, then the returned parameter value is greater than datumParam. Otherwise it will be less than datumParam. '''
    ...
    def paramOf (self, pt : PyGe.Point3d, tol : PyGe.Tol=None)-> float :
      '''Returns the parameter value of pnt. This function assumes that pnt lies on the curve and does not verify this. If pnt does not lie on the curve, this function will return unpredictable results. If it is not known whether pnt lies on the curve, the user should not call this function but should instead call AcGeCurve3d::isOn (pnt, param, tol). '''
    ...
    def pointOnLine (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def projClosestPointTo (self, pt : PyGe.Point3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.Point3d :
      '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
    ...
    def projClosestPointsTo (self, pt : PyGe.Curve3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> tuple :
      '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
    ...
    def projIntersectWith (self, other: PyGe.LinearEnt3d, projDir: PyGe.Vector3d, tol: PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def project (self, projectionPlane : PyGe.Plane, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.Entity3d :
      '''Returns the entity that is the projection of the curve onto the projection plane in the specified direction. The projectDirection vector must not be parallel to the projection plane. The returned entity may not be of the same type as the original curve and may not even be a curve (for instance, a line projects into a point if it is parallel to projectDirection). The returned entity is created with the new and it is the responsibility of the caller to delete it.'''
    ...
    def reverseParam (self)-> None :
      '''Reverses the parametric direction of the curve. The point set of the curve is unchanged, but the direction of the curve is reversed.'''
    ...
    def rotateBy (self, angle : float, vec : PyGe.Vector3d, pt : PyGe.Point3d = 'origin')-> None :
      '''Rotates the entity by the input angle about the line defined by the input point and vector.'''
    ...
    def scaleBy (self, scaleFactor : float, pt : PyGe.Point3d = 'origin')-> None :
      '''Scales the entity about the input point by the input scale factor. Input scale factor must be greater than 0.'''
    ...

    @overload
    def set (self, startPoint: PyGe.Point3d, endPoint: PyGe.Point3d)-> None : ...
    @overload
    def set (self, startPoint: PyGe.Point3d, direction: PyGe.Vector3d)-> None : ...
    def set (self, *args, **kwargs)-> None :
      '''Overloads:
    - startPoint: PyGe.Point3d, endPoint: PyGe.Point3d
    - startPoint: PyGe.Point3d, direction: PyGe.Vector3d
    '''
    ...
    def setInterval (self, val : PyGe.Interval = None)-> None :
      '''Sets the domain of the curve to the input interval.'''
    ...
    def transformBy (self, val : PyGe.Matrix3d)-> None :
      '''Transforms the entity by applying the input matrix.'''
    ...
    def translateBy (self, vec : PyGe.Vector3d)-> None :
      '''Translates the entity by the input vector.'''
    ...
    def type (self)-> PyGe.EntityId :
      '''Returns the type of the entity.'''
    ...

class LineSeg2d(LinearEnt2d):
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (Point2d)arg2, (Vector2d)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePoint2d,class AcGeVector2d)

__init__( (object)arg1, (Point2d)arg2, (Point2d)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePoint2d,class AcGePoint2d)'''
    ...
    def area (self, startParam : float, endParam : float, tol : float = None)-> float :
      '''                             '''
    ...
    def baryComb (self, *args, **kwargs)-> PyGe.Point2d :
      '''baryComb( (LineSeg2d)arg1, (float)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d baryComb(class PyGeLineSeg2d {lvalue},double)'''
    ...
    def boundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock2d :
      '''                             '''
    ...
    def cast (self, *args, **kwargs)-> PyGe.LineSeg2d :
      '''cast( (Entity2d)arg1) -> LineSeg2d :

    C++ signature :
        class PyGeLineSeg2d cast(class PyGeEntity2d)'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def closestPointTo (self, other : PyGe.Point2d | PyGe.Curve2d, tol : PyGe.Tol=None)-> PyGe.Point2d :
      '''                             '''
    ...
    def copy (self)-> PyGe.Entity2d :
      '''                             '''
    ...
    def copycast (self, *args, **kwargs)-> PyGe.LineSeg2d :
      '''copycast( (Entity2d)arg1) -> LineSeg2d :

    C++ signature :
        class PyGeLineSeg2d copycast(class PyGeEntity2d)'''
    ...
    def direction (self, *args, **kwargs)-> PyGe.Vector2d :
      '''direction( (LinearEnt2d)arg1) -> Vector2d :

    C++ signature :
        class AcGeVector2d direction(class PyGeLinearEnt2d {lvalue})'''
    ...
    def distanceTo (self, pt : PyGe.Point2d | PyGe.Curve2d, tol : PyGe.Tol=None)-> float :
      '''                             '''
    ...
    def endPoint (self, *args, **kwargs)-> PyGe.Point2d :
      '''endPoint( (LineSeg2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d endPoint(class PyGeLineSeg2d {lvalue})'''
    ...
    def evalPoint (self, param : float, numDeriv : int = 1)-> PyGe.Point2d :
      '''                             '''
    ...
    def explode (self, val : PyGe.Interval = None)-> list :
      '''                             '''
    ...
    def getBisector (self, *args, **kwargs)-> PyGe.Line2d :
      '''getBisector( (LineSeg2d)arg1) -> Line2d :

    C++ signature :
        class PyGeLine2d getBisector(class PyGeLineSeg2d {lvalue})'''
    ...
    def getClosestPointTo (self, other : PyGe.Point2d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve2d :
      '''                             '''
    ...
    def getClosestPointsTo (self, other : PyGe.Curve2d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def getEndPoint (self)-> PyGe.Point2d :
      '''                             '''
    ...
    def getInterval (self)-> PyGe.Interval :
      '''                             '''
    ...
    def getLine (self, *args, **kwargs)-> PyGe.Line2d :
      '''getLine( (LinearEnt2d)arg1) -> Line2d :

    C++ signature :
        class PyGeLine2d getLine(class PyGeLinearEnt2d {lvalue})'''
    ...
    def getNormalPoint (self, pnt : PyGe.Point2d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve2d :
      '''                             '''
    ...
    def getPerpLine (self, *args, **kwargs)-> PyGe.Line2d :
      '''getPerpLine( (LinearEnt2d)arg1, (Point2d)arg2) -> Line2d :

    C++ signature :
        class PyGeLine2d getPerpLine(class PyGeLinearEnt2d {lvalue},class AcGePoint2d)'''
    ...

    @overload
    def getSamplePoints (self, numSample: int)-> list : ...
    @overload
    def getSamplePoints (self, fromParam: float, toParam: float, approxEps: float)-> list : ...
    def getSamplePoints (self, *args, **kwargs)-> list :
      '''Overloads:
    - numSample: int
    - fromParam: float, toParam: float, approxEps: float
    '''
    ...
    def getSplitCurves (self, param : float)-> tuple :
      '''                             '''
    ...
    def getStartPoint (self)-> PyGe.Point2d :
      '''                             '''
    ...
    def getTrimmedOffset (self, dist : float, extensionType : PyGe.OffsetCrvExtType, tol : PyGe.Tol=None)-> list :
      '''                             '''
    ...
    def hasEndPoint (self)-> bool :
      '''                             '''
    ...
    def hasStartPoint (self)-> bool :
      '''                             '''
    ...
    def intersectWith (self, *args, **kwargs)-> tuple :
      '''intersectWith( (LinearEnt2d)arg1, (LinearEnt2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d)

intersectWith( (LinearEnt2d)arg1, (LinearEnt2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d,class AcGeTol)'''
    ...
    def isClosed (self, tol : PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def isColinearTo (self, *args, **kwargs)-> bool :
      '''isColinearTo( (LinearEnt2d)arg1, (LinearEnt2d)arg2) -> bool :

    C++ signature :
        bool isColinearTo(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d)

isColinearTo( (LinearEnt2d)arg1, (LinearEnt2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isColinearTo(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d,class AcGeTol)'''
    ...
    def isDegenerate (self, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isEqualTo (self, val : PyGe.Entity2d, tol : PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def isKindOf (self, val : PyGe.EntityId)-> bool :
      '''                             '''
    ...
    def isLinear (self, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isNull (self)-> bool :
      '''                             '''
    ...
    def isOn (self, pt : float | PyGe.Point2d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isParallelTo (self, *args, **kwargs)-> bool :
      '''isParallelTo( (LinearEnt2d)arg1, (LinearEnt2d)arg2) -> bool :

    C++ signature :
        bool isParallelTo(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d)

isParallelTo( (LinearEnt2d)arg1, (LinearEnt2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isParallelTo(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d,class AcGeTol)'''
    ...
    def isPeriodic (self)-> tuple :
      '''                             '''
    ...
    def isPerpendicularTo (self, *args, **kwargs)-> bool :
      '''isPerpendicularTo( (LinearEnt2d)arg1, (LinearEnt2d)arg2) -> bool :

    C++ signature :
        bool isPerpendicularTo(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d)

isPerpendicularTo( (LinearEnt2d)arg1, (LinearEnt2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isPerpendicularTo(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d,class AcGeTol)'''
    ...
    def length (self, *args, **kwargs)-> float :
      '''length( (LineSeg2d)arg1) -> float :

    C++ signature :
        double length(class PyGeLineSeg2d {lvalue})

length( (LineSeg2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double length(class PyGeLineSeg2d {lvalue},double,double)

length( (LineSeg2d)arg1, (float)arg2, (float)arg3, (float)arg4) -> float :

    C++ signature :
        double length(class PyGeLineSeg2d {lvalue},double,double,double)'''
    ...
    def midPoint (self, *args, **kwargs)-> PyGe.Point2d :
      '''midPoint( (LineSeg2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d midPoint(class PyGeLineSeg2d {lvalue})'''
    ...
    def mirror (self, val : PyGe.Line2d)-> None :
      '''                             '''
    ...
    def orthoBoundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock2d :
      '''                             '''
    ...
    def overlap (self, *args, **kwargs)-> tuple :
      '''overlap( (LinearEnt2d)arg1, (LinearEnt2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple overlap(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d)

overlap( (LinearEnt2d)arg1, (LinearEnt2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple overlap(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d,class AcGeTol)'''
    ...
    def paramAtLength (self, datumParam: float, length: float, posParamDir: bool=True, tol: float=None)-> float :
      '''                             '''
    ...
    def paramOf (self, pt : PyGe.Point2d, tol : PyGe.Tol=None)-> float :
      '''                             '''
    ...
    def pointOnLine (self, *args, **kwargs)-> PyGe.Point2d :
      '''pointOnLine( (LinearEnt2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d pointOnLine(class PyGeLinearEnt2d {lvalue})'''
    ...
    def reverseParam (self)-> None :
      '''                             '''
    ...
    def rotateBy (self, angle : float, pt : PyGe.Point3d=PyGe.Point2d.kOrgin)-> None :
      '''                             '''
    ...
    def scaleBy (self, scaleFactor : float, pt : PyGe.Point2d=PyGe.Point2d.kOrgin)-> None :
      '''                             '''
    ...
    def set (self, *args, **kwargs)-> None :
      '''set( (LineSeg2d)arg1, (Point2d)arg2, (Vector2d)arg3) -> None :

    C++ signature :
        void set(class PyGeLineSeg2d {lvalue},class AcGePoint2d,class AcGeVector2d)

set( (LineSeg2d)arg1, (Point2d)arg2, (Point2d)arg3) -> None :

    C++ signature :
        void set(class PyGeLineSeg2d {lvalue},class AcGePoint2d,class AcGePoint2d)

set( (LineSeg2d)arg1, (Curve2d)arg2, (Curve2d)arg3) -> None :

    C++ signature :
        void set(class PyGeLineSeg2d {lvalue},class PyGeCurve2d,class PyGeCurve2d)

set( (LineSeg2d)arg1, (Curve2d)arg2, (Point2d)arg3) -> None :

    C++ signature :
        void set(class PyGeLineSeg2d {lvalue},class PyGeCurve2d,class AcGePoint2d)'''
    ...
    def setInterval (self, val : PyGe.Interval = None)-> None :
      '''                             '''
    ...
    def startPoint (self, *args, **kwargs)-> PyGe.Point2d :
      '''startPoint( (LineSeg2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d startPoint(class PyGeLineSeg2d {lvalue})'''
    ...
    def transformBy (self, val : PyGe.Matrix2d)-> None :
      '''                             '''
    ...
    def translateBy (self, vec : PyGe.Vector2d)-> None :
      '''                             '''
    ...
    def type (self)-> PyGe.EntityId :
      '''                             '''
    ...

class LineSeg3d(LinearEnt3d):

    @overload
    def __init__ (self, /)-> None : ...
    @overload
    def __init__ (self, startPoint: PyGe.Point3d, endPoint: PyGe.Point3d)-> None : ...
    @overload
    def __init__ (self, startPoint: PyGe.Point3d, direction: PyGe.Vector3d)-> None : ...
    def __init__ (self, *args, **kwargs)-> None :
      '''Overloads:
    - None: Any
    - startPoint: PyGe.Point3d, endPoint: PyGe.Point3d
    - startPoint: PyGe.Point3d, direction: PyGe.Vector3d
    '''
    ...
    def area (self, startParam : float, endParam : float, tol : float = None)-> float :
      '''Returns the area of the interval of the curve defined by startParam and endParam. Returns Adesk::kTrue if area was successfully computed to within the specified tolerance. If the curve is not planar, then the area cannot be calculated and a value of Adesk::kFalse is returned. If the points at startParam and endParam are the same, then this function returns the area of the closed curve. If the points are different, then this function connects the two points with a line segment and return the signed area between the curve and the line segment. If the line segment does not intersect the curve at any points between startParam and endParam, then the returned area is positive. If the line segment intersects the curves at any points between startParam and endParam, then the returned area is the sum of the sub-areas created by the intersection of the line segment with the curve. Each sub-area has a positive or negative area, depending on whether the curve lies above or below the line segment. The total area returned by this function can therefore be positive, negative, or 0. '''
    ...
    def baryComb (self, *args, **kwargs)-> PyGe.Point3d :
      '''baryComb( (LineSeg3d)arg1, (float)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d baryComb(class PyGeLineSeg3d {lvalue},double)'''
    ...
    def boundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock3d :
      '''Returns the bounding box of the curve. The sides of the returned box are parallel to the coordinate axes. '''
    ...
    def cast (self, *args, **kwargs)-> PyGe.LineSeg3d :
      '''cast( (Entity3d)arg1) -> LineSeg3d :

    C++ signature :
        class PyGeLineSeg3d cast(class PyGeEntity3d)'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def closestPointTo (self, other : PyGe.Point3d | PyGe.Curve3d, tol : PyGe.Tol=None)-> PyGe.Point3d :
      '''Finds the closest point on this curve to the input point. This function is the same as closestPointTo(), except that the closest point is returned as an AcGePointOnCurve3d object.'''
    ...
    def copy (self)-> PyGe.Entity3d :
      '''Returns a pointer to a copy of this entity. This copy is created using the new and it is the responsibility of the caller to delete it.'''
    ...
    def copycast (self, *args, **kwargs)-> PyGe.LineSeg3d :
      '''copycast( (Entity3d)arg1) -> LineSeg3d :

    C++ signature :
        class PyGeLineSeg3d copycast(class PyGeEntity3d)'''
    ...
    def direction (self)-> PyGe.Vector3d :
      '''                             '''
    ...
    def distanceTo (self, pt : PyGe.Point3d | PyGe.Curve3d, tol : PyGe.Tol=None)-> float :
      '''Returns the distance between the input point and the closest point on this curve.'''
    ...
    def endPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def evalPoint (self, param : float, numDeriv : int = 1)-> PyGe.Point3d :
      '''Returns the point on the curve that corresponds to the input parameter value. Also returns the number of derivative vectors that are specified in numDeriv. The numDeriv parameter should not be set larger than 2.'''
    ...
    def explode (self, val : PyGe.Interval = None)-> list :
      '''Explodes the curve into its individual components. If the curve is a composite curve, then explodedCurves contains the list of component curves of the composite. If the curve is a spline, then it is exploded at the points of C1 discontinuity and explodedCurves contains a copy of each continuous sub-curve. This function returns Adesk::kTrue if the curve was exploded (that is, the curve was a composite or a discontinuous spline) and Adesk::kFalse otherwise. The number of entries returned in newExplodedCurves is always the same as the number of entries in explodedCurves. Each flag in newExplodedCurves indicates whether the corresponding curve in explodedCurves was created with the new operator. If the flag is 1, then it is the responsibility of the caller to delete the curve. If the flag is 0, the curve is deleted by gelib and the caller should not attempt to delete it. If no intrvl parameter is supplied, then the interval is taken to be the entire curve. '''
    ...
    def getBisector (self)-> PyGe.Plane :
      '''                             '''
    ...
    def getClosestPointTo (self, other : PyGe.Point3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''Finds the closest point on this curve to the input point. This function is the same as closestPointTo(), except that the closest point is returned as an AcGePointOnCurve3d object.'''
    ...
    def getClosestPointsTo (self, other : PyGe.Curve3d, tol : PyGe.Tol=None)-> tuple :
      '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
    ...
    def getEndPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def getInterval (self)-> PyGe.Interval :
      '''Returns the parametric range of the curve. The function evalPoint(double) always returns a point on this curve when called with a value within the returned interval.'''
    ...
    def getLine (self)-> PyGe.Line3d :
      '''                             '''
    ...
    def getNormalPoint (self, pnt : PyGe.Point3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''Finds the point on the input curve whose normal passes through the input point. The returned point lies on a plane that also contains the input point and is perpendicular to the curve tangent at that point. The returned point is therefore at a local minimum or a local maximum from the input point. The curve does not need to be planar. If the curve is planar, the input point does not need to lie in the plane of the curve. On input, the second parameter is assumed to contain the parameter value of an initial guess. If there is more than one normal point on the curve, the returned point will be the one whose parameter value is closest to the input parameter value.'''
    ...
    def getPerpPlane (self, pt: PyGe.Point3d)-> PyGe.Plane :
      '''                             '''
    ...
    def getProjClosestPointTo (self, pt : PyGe.Point3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
    ...
    def getProjClosestPointsTo (self, pt : PyGe.Curve3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> tuple :
      '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
    ...

    @overload
    def getSamplePoints (self, numSample: int)-> tuple : ...
    @overload
    def getSamplePoints (self, fromParam: float, toParam: float, approxEps: float)-> tuple : ...
    def getSamplePoints (self, *args, **kwargs)-> tuple :
      '''Overloads:
    - numSample: int
    - fromParam: float, toParam: float, approxEps: float
    
	-Returns the specified number of points on the curve. The points are equally spaced by parameter value. So if the interval of the curve [0,1] and numSample is 5, the parameter values of the returned points are 0, 0.25, 0.5, 0.75, and 1.-'''
    ...
    def getSplitCurves (self, param : float)-> tuple :
      '''Returns two segments which are obtained by splitting the curve at the input parameter value. If the specified parameter value does not lie within the parametric interval of the curve or if it corresponds to the start point or endpoint of the curve, then piece1 and piece2 are set to null. This function uses the new to create the curve segments whose addresses are returned in piece1 and piece2. It is the responsibility of the caller to delete these objects. '''
    ...
    def getStartPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def getTrimmedOffset (self, dist : float, planeNormal : PyGe.Vector3d, extensionType : PyGe.OffsetCrvExtType, tol : PyGe.Tol=None)-> list :
      '''Returns one or more offset curves that represent the trimmed offset of the curve. The curve must be planar and planeNormal must be perpendicular to the plane of the curve. The positive direction of offset at a point on the curve is taken to be the cross product of planeNormal with the tangent vector at that point. The curve may be offset in either of two directions by specifying a positive or negative offset distance; planeNormal determines which direction is the positive direction of offset. The returned offset curves are trimmed so that they do not contain any points of self-intersection. Each curve that is returned in offsetCurveList is created with the new and it is the responsibility of the caller to delete these curves. Each curve that is returned in offsetCurveList is a connected curve and may be a composite curve if the offset curve had to be trimmed to remove self-intersecting loops. offsetCurveList only contains more than one curve if the offset operation produces multiple curves which are not connected. If the original curve contains points of C1 discontinuity and the direction of offset causes the offset curve to be disjoint (for instance, if the original curve is a composite curve that is a rectangle and the direction of offset is to the outside of the rectangle), then the offset curve is closed with an arc or a line segment, or the curves are simply extended depending on the value of extensionType.'''
    ...
    def hasEndPoint (self)-> bool :
      '''Returns Adesk::kTrue if curve has an endpoint. A return value of Adesk::kFalse means that the parametric interval of the curve does not have an upper bound. The endPnt parameter contains meaningful data only if this function returns a value of Adesk::kTrue.'''
    ...
    def hasStartPoint (self)-> bool :
      '''Returns Adesk::kTrue if curve has a start point. A return value of Adesk::kFalse means that the parametric interval of the curve does not have a lower bound. The startPnt parameter contains meaningful data only if this function returns a value of Adesk::kTrue.'''
    ...
    def intersectWith (self, other: PyGe.LinearEnt3d | PyGe.PlanarEnt, tol: PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isClosed (self, tol : PyGe.Tol=None)-> bool :
      '''Determines if start point and endpoint of curve are the same.'''
    ...
    def isColinearTo (self, pt: PyGe.LinearEnt3d, tol: PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def isCoplanarWith (self, curve : PyGe.Curve3d, tol : PyGe.Tol=None)-> tuple :
      '''Returns Adesk::kTrue if both curve are planar and lie in the same plane. The plane parameter is only valid if this function returns a value of Adesk::kTrue.'''
    ...
    def isDegenerate (self, tol : PyGe.Tol=None)-> tuple :
      '''Determines if the curve is degenerate and if so returns the type of entity which the curve degenerates into. For example, if the curve is a circle with a radius of 0 then degenerateType is set to AcGe::kPoint3d. If the curve is an ellipse with a minor radius of 0 and a major radius of 1, then degenerateType is set to AcGe::kLineSeg3d. The degenerateType parameter is only set to something meaningful when this function returns a value of Adesk::kTrue.'''
    ...
    def isEqualTo (self, val : PyGe.Entity3d, tol : PyGe.Tol=None)-> bool :
      '''Determines if two entities are equal to each other. Two entities are considered to be equal only if they are of the same type and they represent the same 3D point set. For instance, if the two entities are of types AcGeCircArc3d and AcGeEllipArc3d then they are not considered equal even if the ellipse is completely coincident with the circle. Also, two curves are not considered equal unless they have the same parameterization. For instance, two infinite coincident lines are not considered equal if they have different scaling in their parameterization. '''
    ...
    def isKindOf (self, val : PyGe.EntityId)-> bool :
      '''                             '''
    ...
    def isLinear (self, tol : PyGe.Tol=None)-> tuple :
      '''Determines if curve is linear. This function returns an infinite line even if the curve is not infinite. The line parameter contains meaningful data only if this function returns a value of Adesk::kTrue.'''
    ...
    def isNull (self)-> bool :
      '''                             '''
    ...

    @overload
    def isOn (self, pnt: PyGe.Point3d)-> tuple : ...
    @overload
    def isOn (self, pnt: PyGe.Point3d, tol: PyGe.Tol)-> tuple : ...
    @overload
    def isOn (self, param: float)-> tuple : ...
    @overload
    def isOn (self, param: float, tol: PyGe.Tol)-> tuple : ...
    @overload
    def isOn (self, plane: PyGe.Plane)-> tuple : ...
    @overload
    def isOn (self, plane: PyGe.Plane, tol: PyGe.Tol)-> tuple : ...
    def isOn (self, *args, **kwargs)-> tuple :
      '''Overloads:
    - pnt: PyGe.Point3d
    - pnt: PyGe.Point3d, tol: PyGe.Tol
    - param: float
    - param: float, tol: PyGe.Tol
    - plane: PyGe.Plane
    - plane: PyGe.Plane, tol: PyGe.Tol
    '''
    ...

    @overload
    def isParallelTo (self, line: PyGe.LinearEnt3d)-> bool : ...
    @overload
    def isParallelTo (self, line: PyGe.LinearEnt3d, tol: PyGe.Tol)-> bool : ...
    @overload
    def isParallelTo (self, line: PyGe.PlanarEnt)-> bool : ...
    @overload
    def isParallelTo (self, line: PyGe.PlanarEnt, tol: PyGe.Tol)-> bool : ...
    def isParallelTo (self, *args, **kwargs)-> bool :
      '''Overloads:
    - line: PyGe.LinearEnt3d
    - line: PyGe.LinearEnt3d, tol: PyGe.Tol
    - line: PyGe.PlanarEnt
    - line: PyGe.PlanarEnt, tol: PyGe.Tol
    '''
    ...
    def isPeriodic (self)-> tuple :
      '''Determines if the curve is periodic. The curve is periodic if and only if it is closed and the two points evalPoint(t) and evalPoint(t+period) are always the same point for all values of t.'''
    ...

    @overload
    def isPerpendicularTo (self, line: PyGe.LinearEnt3d)-> bool : ...
    @overload
    def isPerpendicularTo (self, line: PyGe.LinearEnt3d, tol: PyGe.Tol)-> bool : ...
    @overload
    def isPerpendicularTo (self, line: PyGe.PlanarEnt)-> bool : ...
    @overload
    def isPerpendicularTo (self, line: PyGe.PlanarEnt, tol: PyGe.Tol)-> bool : ...
    def isPerpendicularTo (self, *args, **kwargs)-> bool :
      '''Overloads:
    - line: PyGe.LinearEnt3d
    - line: PyGe.LinearEnt3d, tol: PyGe.Tol
    - line: PyGe.PlanarEnt
    - line: PyGe.PlanarEnt, tol: PyGe.Tol
    '''
    ...
    def isPlanar (self, tol : PyGe.Tol=None)-> tuple :
      '''Determines if curve is planar. If the curve is a line, then this function returns an arbitrary plane that contains the line. The plane parameter contains meaningful data only if this function returns a value of Adesk::kTrue. '''
    ...

    @overload
    def length (self, /)-> float : ...
    @overload
    def length (self, fromParam: float, toParam: float)-> float : ...
    @overload
    def length (self, fromParam: float, toParam: float, tol: float)-> float : ...
    def length (self, *args, **kwargs)-> float :
      '''Overloads:
    - None: Any
    - fromParam: float, toParam: float
    - fromParam: float, toParam: float, tol: float
    '''
    ...
    def midPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def mirror (self, val : PyGe.Plane)-> None :
      '''Transforms the entity by mirroring it across the input plane.'''
    ...
    def orthoBoundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock3d :
      '''Returns the bounding box of the curve. The sides of the returned box are parallel to the coordinate axes.'''
    ...
    def orthoProject (self, projectionPlane : PyGe.Plane, tol : PyGe.Tol=None)-> PyGe.Entity3d :
      '''Returns the entity that is the orthogonal projection of the curve onto the projection plane. The returned entity may not be of the same type as the original curve and may not even be a curve (for instance, a line projects into a point if it is orthogonal to the projection plane). The returned entity is created with the new and it is the responsibility of the caller to delete it.'''
    ...
    def overlap (self, other: PyGe.LinearEnt3d, tol: PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def paramAtLength (self, datumParam : float, length : float, posParamDir : bool=True, tol : float = default)-> float :
      '''Returns the parameter value of the point whose arc length distance (from the point with parameter value datumParam) is the input length. In other words, ift = paramAtLength (datumParam, len, posParamDir, tol) then length (t, datumParam, tol) is (approximately) equal to len. If posParamDir is set to Adesk::kTrue, then the returned parameter value is greater than datumParam. Otherwise it will be less than datumParam. '''
    ...
    def paramOf (self, pt : PyGe.Point3d, tol : PyGe.Tol=None)-> float :
      '''Returns the parameter value of pnt. This function assumes that pnt lies on the curve and does not verify this. If pnt does not lie on the curve, this function will return unpredictable results. If it is not known whether pnt lies on the curve, the user should not call this function but should instead call AcGeCurve3d::isOn (pnt, param, tol). '''
    ...
    def pointOnLine (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def projClosestPointTo (self, pt : PyGe.Point3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.Point3d :
      '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
    ...
    def projClosestPointsTo (self, pt : PyGe.Curve3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> tuple :
      '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
    ...
    def projIntersectWith (self, other: PyGe.LinearEnt3d, projDir: PyGe.Vector3d, tol: PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def project (self, projectionPlane : PyGe.Plane, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.Entity3d :
      '''Returns the entity that is the projection of the curve onto the projection plane in the specified direction. The projectDirection vector must not be parallel to the projection plane. The returned entity may not be of the same type as the original curve and may not even be a curve (for instance, a line projects into a point if it is parallel to projectDirection). The returned entity is created with the new and it is the responsibility of the caller to delete it.'''
    ...
    def reverseParam (self)-> None :
      '''Reverses the parametric direction of the curve. The point set of the curve is unchanged, but the direction of the curve is reversed.'''
    ...
    def rotateBy (self, angle : float, vec : PyGe.Vector3d, pt : PyGe.Point3d = 'origin')-> None :
      '''Rotates the entity by the input angle about the line defined by the input point and vector.'''
    ...
    def scaleBy (self, scaleFactor : float, pt : PyGe.Point3d = 'origin')-> None :
      '''Scales the entity about the input point by the input scale factor. Input scale factor must be greater than 0.'''
    ...

    @overload
    def set (self, startPoint: PyGe.Point3d, endPoint: PyGe.Point3d)-> None : ...
    @overload
    def set (self, startPoint: PyGe.Point3d, direction: PyGe.Vector3d)-> None : ...
    def set (self, *args, **kwargs)-> None :
      '''Overloads:
    - startPoint: PyGe.Point3d, endPoint: PyGe.Point3d
    - startPoint: PyGe.Point3d, direction: PyGe.Vector3d
    '''
    ...
    def setInterval (self, val : PyGe.Interval = None)-> None :
      '''Sets the domain of the curve to the input interval.'''
    ...
    def startPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def transformBy (self, val : PyGe.Matrix3d)-> None :
      '''Transforms the entity by applying the input matrix.'''
    ...
    def translateBy (self, vec : PyGe.Vector3d)-> None :
      '''Translates the entity by the input vector.'''
    ...
    def type (self)-> PyGe.EntityId :
      '''Returns the type of the entity.'''
    ...

class LinearEnt2d(Curve2d):
    def __init__ (self, *args, **kwargs)-> None :
      '''Raises an exception
This class cannot be instantiated from Python'''
    ...
    def area (self, startParam : float, endParam : float, tol : float = None)-> float :
      '''                             '''
    ...
    def boundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock2d :
      '''                             '''
    ...
    def cast (self, *args, **kwargs)-> PyGe.LinearEnt2d :
      '''cast( (Entity2d)arg1) -> LinearEnt2d :

    C++ signature :
        class PyGeLinearEnt2d cast(class PyGeEntity2d)'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def closestPointTo (self, other : PyGe.Point2d | PyGe.Curve2d, tol : PyGe.Tol=None)-> PyGe.Point2d :
      '''                             '''
    ...
    def copy (self)-> PyGe.Entity2d :
      '''                             '''
    ...
    def copycast (self, *args, **kwargs)-> PyGe.LinearEnt2d :
      '''copycast( (Entity2d)arg1) -> LinearEnt2d :

    C++ signature :
        class PyGeLinearEnt2d copycast(class PyGeEntity2d)'''
    ...
    def direction (self, *args, **kwargs)-> PyGe.Vector2d :
      '''direction( (LinearEnt2d)arg1) -> Vector2d :

    C++ signature :
        class AcGeVector2d direction(class PyGeLinearEnt2d {lvalue})'''
    ...
    def distanceTo (self, pt : PyGe.Point2d | PyGe.Curve2d, tol : PyGe.Tol=None)-> float :
      '''                             '''
    ...
    def evalPoint (self, param : float, numDeriv : int = 1)-> PyGe.Point2d :
      '''                             '''
    ...
    def explode (self, val : PyGe.Interval = None)-> list :
      '''                             '''
    ...
    def getClosestPointTo (self, other : PyGe.Point2d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve2d :
      '''                             '''
    ...
    def getClosestPointsTo (self, other : PyGe.Curve2d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def getEndPoint (self)-> PyGe.Point2d :
      '''                             '''
    ...
    def getInterval (self)-> PyGe.Interval :
      '''                             '''
    ...
    def getLine (self, *args, **kwargs)-> PyGe.Line2d :
      '''getLine( (LinearEnt2d)arg1) -> Line2d :

    C++ signature :
        class PyGeLine2d getLine(class PyGeLinearEnt2d {lvalue})'''
    ...
    def getNormalPoint (self, pnt : PyGe.Point2d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve2d :
      '''                             '''
    ...
    def getPerpLine (self, *args, **kwargs)-> PyGe.Line2d :
      '''getPerpLine( (LinearEnt2d)arg1, (Point2d)arg2) -> Line2d :

    C++ signature :
        class PyGeLine2d getPerpLine(class PyGeLinearEnt2d {lvalue},class AcGePoint2d)'''
    ...

    @overload
    def getSamplePoints (self, numSample: int)-> list : ...
    @overload
    def getSamplePoints (self, fromParam: float, toParam: float, approxEps: float)-> list : ...
    def getSamplePoints (self, *args, **kwargs)-> list :
      '''Overloads:
    - numSample: int
    - fromParam: float, toParam: float, approxEps: float
    '''
    ...
    def getSplitCurves (self, param : float)-> tuple :
      '''                             '''
    ...
    def getStartPoint (self)-> PyGe.Point2d :
      '''                             '''
    ...
    def getTrimmedOffset (self, dist : float, extensionType : PyGe.OffsetCrvExtType, tol : PyGe.Tol=None)-> list :
      '''                             '''
    ...
    def hasEndPoint (self)-> bool :
      '''                             '''
    ...
    def hasStartPoint (self)-> bool :
      '''                             '''
    ...
    def intersectWith (self, *args, **kwargs)-> tuple :
      '''intersectWith( (LinearEnt2d)arg1, (LinearEnt2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d)

intersectWith( (LinearEnt2d)arg1, (LinearEnt2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d,class AcGeTol)'''
    ...
    def isClosed (self, tol : PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def isColinearTo (self, *args, **kwargs)-> bool :
      '''isColinearTo( (LinearEnt2d)arg1, (LinearEnt2d)arg2) -> bool :

    C++ signature :
        bool isColinearTo(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d)

isColinearTo( (LinearEnt2d)arg1, (LinearEnt2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isColinearTo(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d,class AcGeTol)'''
    ...
    def isDegenerate (self, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isEqualTo (self, val : PyGe.Entity2d, tol : PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def isKindOf (self, val : PyGe.EntityId)-> bool :
      '''                             '''
    ...
    def isLinear (self, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isNull (self)-> bool :
      '''                             '''
    ...
    def isOn (self, pt : float | PyGe.Point2d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isParallelTo (self, *args, **kwargs)-> bool :
      '''isParallelTo( (LinearEnt2d)arg1, (LinearEnt2d)arg2) -> bool :

    C++ signature :
        bool isParallelTo(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d)

isParallelTo( (LinearEnt2d)arg1, (LinearEnt2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isParallelTo(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d,class AcGeTol)'''
    ...
    def isPeriodic (self)-> tuple :
      '''                             '''
    ...
    def isPerpendicularTo (self, *args, **kwargs)-> bool :
      '''isPerpendicularTo( (LinearEnt2d)arg1, (LinearEnt2d)arg2) -> bool :

    C++ signature :
        bool isPerpendicularTo(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d)

isPerpendicularTo( (LinearEnt2d)arg1, (LinearEnt2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isPerpendicularTo(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d,class AcGeTol)'''
    ...
    def length (self, frm : float, to : float, tol : float = None)-> float :
      '''                             '''
    ...
    def mirror (self, val : PyGe.Line2d)-> None :
      '''                             '''
    ...
    def orthoBoundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock2d :
      '''                             '''
    ...
    def overlap (self, *args, **kwargs)-> tuple :
      '''overlap( (LinearEnt2d)arg1, (LinearEnt2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple overlap(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d)

overlap( (LinearEnt2d)arg1, (LinearEnt2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple overlap(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d,class AcGeTol)'''
    ...
    def paramAtLength (self, datumParam: float, length: float, posParamDir: bool=True, tol: float=None)-> float :
      '''                             '''
    ...
    def paramOf (self, pt : PyGe.Point2d, tol : PyGe.Tol=None)-> float :
      '''                             '''
    ...
    def pointOnLine (self, *args, **kwargs)-> PyGe.Point2d :
      '''pointOnLine( (LinearEnt2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d pointOnLine(class PyGeLinearEnt2d {lvalue})'''
    ...
    def reverseParam (self)-> None :
      '''                             '''
    ...
    def rotateBy (self, angle : float, pt : PyGe.Point3d=PyGe.Point2d.kOrgin)-> None :
      '''                             '''
    ...
    def scaleBy (self, scaleFactor : float, pt : PyGe.Point2d=PyGe.Point2d.kOrgin)-> None :
      '''                             '''
    ...
    def setInterval (self, val : PyGe.Interval = None)-> None :
      '''                             '''
    ...
    def transformBy (self, val : PyGe.Matrix2d)-> None :
      '''                             '''
    ...
    def translateBy (self, vec : PyGe.Vector2d)-> None :
      '''                             '''
    ...
    def type (self)-> PyGe.EntityId :
      '''                             '''
    ...

class LinearEnt3d(Curve3d):
    def __init__ (self, *args, **kwargs)-> None :
      '''Raises an exception
This class cannot be instantiated from Python'''
    ...
    def area (self, startParam : float, endParam : float, tol : float = None)-> float :
      '''Returns the area of the interval of the curve defined by startParam and endParam. Returns Adesk::kTrue if area was successfully computed to within the specified tolerance. If the curve is not planar, then the area cannot be calculated and a value of Adesk::kFalse is returned. If the points at startParam and endParam are the same, then this function returns the area of the closed curve. If the points are different, then this function connects the two points with a line segment and return the signed area between the curve and the line segment. If the line segment does not intersect the curve at any points between startParam and endParam, then the returned area is positive. If the line segment intersects the curves at any points between startParam and endParam, then the returned area is the sum of the sub-areas created by the intersection of the line segment with the curve. Each sub-area has a positive or negative area, depending on whether the curve lies above or below the line segment. The total area returned by this function can therefore be positive, negative, or 0. '''
    ...
    def boundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock3d :
      '''Returns the bounding box of the curve. The sides of the returned box are parallel to the coordinate axes. '''
    ...

    @staticmethod
    def cast (otherObject: PyGe.Entity3d)-> PyGe.LinearEnt3d :
      '''                             '''
    ...

    @staticmethod
    def className ()-> str :
      '''                             '''
    ...
    def closestPointTo (self, other : PyGe.Point3d | PyGe.Curve3d, tol : PyGe.Tol=None)-> PyGe.Point3d :
      '''Finds the closest point on this curve to the input point. This function is the same as closestPointTo(), except that the closest point is returned as an AcGePointOnCurve3d object.'''
    ...
    def copy (self)-> PyGe.Entity3d :
      '''Returns a pointer to a copy of this entity. This copy is created using the new and it is the responsibility of the caller to delete it.'''
    ...

    @staticmethod
    def copycast (otherObject: PyGe.Entity3d)-> PyGe.LinearEnt3d :
      '''                             '''
    ...
    def direction (self)-> PyGe.Vector3d :
      '''                             '''
    ...
    def distanceTo (self, pt : PyGe.Point3d | PyGe.Curve3d, tol : PyGe.Tol=None)-> float :
      '''Returns the distance between the input point and the closest point on this curve.'''
    ...
    def evalPoint (self, param : float, numDeriv : int = 1)-> PyGe.Point3d :
      '''Returns the point on the curve that corresponds to the input parameter value. Also returns the number of derivative vectors that are specified in numDeriv. The numDeriv parameter should not be set larger than 2.'''
    ...
    def explode (self, val : PyGe.Interval = None)-> list :
      '''Explodes the curve into its individual components. If the curve is a composite curve, then explodedCurves contains the list of component curves of the composite. If the curve is a spline, then it is exploded at the points of C1 discontinuity and explodedCurves contains a copy of each continuous sub-curve. This function returns Adesk::kTrue if the curve was exploded (that is, the curve was a composite or a discontinuous spline) and Adesk::kFalse otherwise. The number of entries returned in newExplodedCurves is always the same as the number of entries in explodedCurves. Each flag in newExplodedCurves indicates whether the corresponding curve in explodedCurves was created with the new operator. If the flag is 1, then it is the responsibility of the caller to delete the curve. If the flag is 0, the curve is deleted by gelib and the caller should not attempt to delete it. If no intrvl parameter is supplied, then the interval is taken to be the entire curve. '''
    ...
    def getClosestPointTo (self, other : PyGe.Point3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''Finds the closest point on this curve to the input point. This function is the same as closestPointTo(), except that the closest point is returned as an AcGePointOnCurve3d object.'''
    ...
    def getClosestPointsTo (self, other : PyGe.Curve3d, tol : PyGe.Tol=None)-> tuple :
      '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
    ...
    def getEndPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def getInterval (self)-> PyGe.Interval :
      '''Returns the parametric range of the curve. The function evalPoint(double) always returns a point on this curve when called with a value within the returned interval.'''
    ...
    def getLine (self)-> PyGe.Line3d :
      '''                             '''
    ...
    def getNormalPoint (self, pnt : PyGe.Point3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''Finds the point on the input curve whose normal passes through the input point. The returned point lies on a plane that also contains the input point and is perpendicular to the curve tangent at that point. The returned point is therefore at a local minimum or a local maximum from the input point. The curve does not need to be planar. If the curve is planar, the input point does not need to lie in the plane of the curve. On input, the second parameter is assumed to contain the parameter value of an initial guess. If there is more than one normal point on the curve, the returned point will be the one whose parameter value is closest to the input parameter value.'''
    ...
    def getPerpPlane (self, pt: PyGe.Point3d)-> PyGe.Plane :
      '''                             '''
    ...
    def getProjClosestPointTo (self, pt : PyGe.Point3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
    ...
    def getProjClosestPointsTo (self, pt : PyGe.Curve3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> tuple :
      '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
    ...

    @overload
    def getSamplePoints (self, numSample: int)-> tuple : ...
    @overload
    def getSamplePoints (self, fromParam: float, toParam: float, approxEps: float)-> tuple : ...
    def getSamplePoints (self, *args, **kwargs)-> tuple :
      '''Overloads:
    - numSample: int
    - fromParam: float, toParam: float, approxEps: float
    
	-Returns the specified number of points on the curve. The points are equally spaced by parameter value. So if the interval of the curve [0,1] and numSample is 5, the parameter values of the returned points are 0, 0.25, 0.5, 0.75, and 1.-'''
    ...
    def getSplitCurves (self, param : float)-> tuple :
      '''Returns two segments which are obtained by splitting the curve at the input parameter value. If the specified parameter value does not lie within the parametric interval of the curve or if it corresponds to the start point or endpoint of the curve, then piece1 and piece2 are set to null. This function uses the new to create the curve segments whose addresses are returned in piece1 and piece2. It is the responsibility of the caller to delete these objects. '''
    ...
    def getStartPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def getTrimmedOffset (self, dist : float, planeNormal : PyGe.Vector3d, extensionType : PyGe.OffsetCrvExtType, tol : PyGe.Tol=None)-> list :
      '''Returns one or more offset curves that represent the trimmed offset of the curve. The curve must be planar and planeNormal must be perpendicular to the plane of the curve. The positive direction of offset at a point on the curve is taken to be the cross product of planeNormal with the tangent vector at that point. The curve may be offset in either of two directions by specifying a positive or negative offset distance; planeNormal determines which direction is the positive direction of offset. The returned offset curves are trimmed so that they do not contain any points of self-intersection. Each curve that is returned in offsetCurveList is created with the new and it is the responsibility of the caller to delete these curves. Each curve that is returned in offsetCurveList is a connected curve and may be a composite curve if the offset curve had to be trimmed to remove self-intersecting loops. offsetCurveList only contains more than one curve if the offset operation produces multiple curves which are not connected. If the original curve contains points of C1 discontinuity and the direction of offset causes the offset curve to be disjoint (for instance, if the original curve is a composite curve that is a rectangle and the direction of offset is to the outside of the rectangle), then the offset curve is closed with an arc or a line segment, or the curves are simply extended depending on the value of extensionType.'''
    ...
    def hasEndPoint (self)-> bool :
      '''Returns Adesk::kTrue if curve has an endpoint. A return value of Adesk::kFalse means that the parametric interval of the curve does not have an upper bound. The endPnt parameter contains meaningful data only if this function returns a value of Adesk::kTrue.'''
    ...
    def hasStartPoint (self)-> bool :
      '''Returns Adesk::kTrue if curve has a start point. A return value of Adesk::kFalse means that the parametric interval of the curve does not have a lower bound. The startPnt parameter contains meaningful data only if this function returns a value of Adesk::kTrue.'''
    ...
    def intersectWith (self, other: PyGe.LinearEnt3d | PyGe.PlanarEnt, tol: PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isClosed (self, tol : PyGe.Tol=None)-> bool :
      '''Determines if start point and endpoint of curve are the same.'''
    ...
    def isColinearTo (self, pt: PyGe.LinearEnt3d, tol: PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def isCoplanarWith (self, curve : PyGe.Curve3d, tol : PyGe.Tol=None)-> tuple :
      '''Returns Adesk::kTrue if both curve are planar and lie in the same plane. The plane parameter is only valid if this function returns a value of Adesk::kTrue.'''
    ...
    def isDegenerate (self, tol : PyGe.Tol=None)-> tuple :
      '''Determines if the curve is degenerate and if so returns the type of entity which the curve degenerates into. For example, if the curve is a circle with a radius of 0 then degenerateType is set to AcGe::kPoint3d. If the curve is an ellipse with a minor radius of 0 and a major radius of 1, then degenerateType is set to AcGe::kLineSeg3d. The degenerateType parameter is only set to something meaningful when this function returns a value of Adesk::kTrue.'''
    ...
    def isEqualTo (self, val : PyGe.Entity3d, tol : PyGe.Tol=None)-> bool :
      '''Determines if two entities are equal to each other. Two entities are considered to be equal only if they are of the same type and they represent the same 3D point set. For instance, if the two entities are of types AcGeCircArc3d and AcGeEllipArc3d then they are not considered equal even if the ellipse is completely coincident with the circle. Also, two curves are not considered equal unless they have the same parameterization. For instance, two infinite coincident lines are not considered equal if they have different scaling in their parameterization. '''
    ...
    def isKindOf (self, val : PyGe.EntityId)-> bool :
      '''                             '''
    ...
    def isLinear (self, tol : PyGe.Tol=None)-> tuple :
      '''Determines if curve is linear. This function returns an infinite line even if the curve is not infinite. The line parameter contains meaningful data only if this function returns a value of Adesk::kTrue.'''
    ...
    def isNull (self)-> bool :
      '''                             '''
    ...

    @overload
    def isOn (self, pnt: PyGe.Point3d)-> tuple : ...
    @overload
    def isOn (self, pnt: PyGe.Point3d, tol: PyGe.Tol)-> tuple : ...
    @overload
    def isOn (self, param: float)-> tuple : ...
    @overload
    def isOn (self, param: float, tol: PyGe.Tol)-> tuple : ...
    @overload
    def isOn (self, plane: PyGe.Plane)-> tuple : ...
    @overload
    def isOn (self, plane: PyGe.Plane, tol: PyGe.Tol)-> tuple : ...
    def isOn (self, *args, **kwargs)-> tuple :
      '''Overloads:
    - pnt: PyGe.Point3d
    - pnt: PyGe.Point3d, tol: PyGe.Tol
    - param: float
    - param: float, tol: PyGe.Tol
    - plane: PyGe.Plane
    - plane: PyGe.Plane, tol: PyGe.Tol
    '''
    ...

    @overload
    def isParallelTo (self, line: PyGe.LinearEnt3d)-> bool : ...
    @overload
    def isParallelTo (self, line: PyGe.LinearEnt3d, tol: PyGe.Tol)-> bool : ...
    @overload
    def isParallelTo (self, line: PyGe.PlanarEnt)-> bool : ...
    @overload
    def isParallelTo (self, line: PyGe.PlanarEnt, tol: PyGe.Tol)-> bool : ...
    def isParallelTo (self, *args, **kwargs)-> bool :
      '''Overloads:
    - line: PyGe.LinearEnt3d
    - line: PyGe.LinearEnt3d, tol: PyGe.Tol
    - line: PyGe.PlanarEnt
    - line: PyGe.PlanarEnt, tol: PyGe.Tol
    '''
    ...
    def isPeriodic (self)-> tuple :
      '''Determines if the curve is periodic. The curve is periodic if and only if it is closed and the two points evalPoint(t) and evalPoint(t+period) are always the same point for all values of t.'''
    ...

    @overload
    def isPerpendicularTo (self, line: PyGe.LinearEnt3d)-> bool : ...
    @overload
    def isPerpendicularTo (self, line: PyGe.LinearEnt3d, tol: PyGe.Tol)-> bool : ...
    @overload
    def isPerpendicularTo (self, line: PyGe.PlanarEnt)-> bool : ...
    @overload
    def isPerpendicularTo (self, line: PyGe.PlanarEnt, tol: PyGe.Tol)-> bool : ...
    def isPerpendicularTo (self, *args, **kwargs)-> bool :
      '''Overloads:
    - line: PyGe.LinearEnt3d
    - line: PyGe.LinearEnt3d, tol: PyGe.Tol
    - line: PyGe.PlanarEnt
    - line: PyGe.PlanarEnt, tol: PyGe.Tol
    '''
    ...
    def isPlanar (self, tol : PyGe.Tol=None)-> tuple :
      '''Determines if curve is planar. If the curve is a line, then this function returns an arbitrary plane that contains the line. The plane parameter contains meaningful data only if this function returns a value of Adesk::kTrue. '''
    ...
    def length (self, frm : float, to : float, tol : float = None)-> float :
      '''Returns the arc length of the curve between the two parameter values.'''
    ...
    def mirror (self, val : PyGe.Plane)-> None :
      '''Transforms the entity by mirroring it across the input plane.'''
    ...
    def orthoBoundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock3d :
      '''Returns the bounding box of the curve. The sides of the returned box are parallel to the coordinate axes.'''
    ...
    def orthoProject (self, projectionPlane : PyGe.Plane, tol : PyGe.Tol=None)-> PyGe.Entity3d :
      '''Returns the entity that is the orthogonal projection of the curve onto the projection plane. The returned entity may not be of the same type as the original curve and may not even be a curve (for instance, a line projects into a point if it is orthogonal to the projection plane). The returned entity is created with the new and it is the responsibility of the caller to delete it.'''
    ...
    def overlap (self, other: PyGe.LinearEnt3d, tol: PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def paramAtLength (self, datumParam : float, length : float, posParamDir : bool=True, tol : float = default)-> float :
      '''Returns the parameter value of the point whose arc length distance (from the point with parameter value datumParam) is the input length. In other words, ift = paramAtLength (datumParam, len, posParamDir, tol) then length (t, datumParam, tol) is (approximately) equal to len. If posParamDir is set to Adesk::kTrue, then the returned parameter value is greater than datumParam. Otherwise it will be less than datumParam. '''
    ...
    def paramOf (self, pt : PyGe.Point3d, tol : PyGe.Tol=None)-> float :
      '''Returns the parameter value of pnt. This function assumes that pnt lies on the curve and does not verify this. If pnt does not lie on the curve, this function will return unpredictable results. If it is not known whether pnt lies on the curve, the user should not call this function but should instead call AcGeCurve3d::isOn (pnt, param, tol). '''
    ...
    def pointOnLine (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def projClosestPointTo (self, pt : PyGe.Point3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.Point3d :
      '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
    ...
    def projClosestPointsTo (self, pt : PyGe.Curve3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> tuple :
      '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
    ...
    def projIntersectWith (self, other: PyGe.LinearEnt3d, projDir: PyGe.Vector3d, tol: PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def project (self, projectionPlane : PyGe.Plane, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.Entity3d :
      '''Returns the entity that is the projection of the curve onto the projection plane in the specified direction. The projectDirection vector must not be parallel to the projection plane. The returned entity may not be of the same type as the original curve and may not even be a curve (for instance, a line projects into a point if it is parallel to projectDirection). The returned entity is created with the new and it is the responsibility of the caller to delete it.'''
    ...
    def reverseParam (self)-> None :
      '''Reverses the parametric direction of the curve. The point set of the curve is unchanged, but the direction of the curve is reversed.'''
    ...
    def rotateBy (self, angle : float, vec : PyGe.Vector3d, pt : PyGe.Point3d = 'origin')-> None :
      '''Rotates the entity by the input angle about the line defined by the input point and vector.'''
    ...
    def scaleBy (self, scaleFactor : float, pt : PyGe.Point3d = 'origin')-> None :
      '''Scales the entity about the input point by the input scale factor. Input scale factor must be greater than 0.'''
    ...
    def setInterval (self, val : PyGe.Interval = None)-> None :
      '''Sets the domain of the curve to the input interval.'''
    ...
    def transformBy (self, val : PyGe.Matrix3d)-> None :
      '''Transforms the entity by applying the input matrix.'''
    ...
    def translateBy (self, vec : PyGe.Vector3d)-> None :
      '''Translates the entity by the input vector.'''
    ...
    def type (self)-> PyGe.EntityId :
      '''Returns the type of the entity.'''
    ...

class Matrix2d(object):
    def __imul__ (self, *args, **kwargs)-> PyGe.Matrix2d :
      '''__imul__( (Matrix2d)arg1, (Matrix2d)arg2) -> Matrix2d :

    C++ signature :
        class AcGeMatrix2d {lvalue} __imul__(class AcGeMatrix2d {lvalue},class AcGeMatrix2d)'''
    ...
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...
    def __mul__ (self, *args, **kwargs)-> PyGe.Matrix2d :
      '''__mul__( (Matrix2d)arg1, (Matrix2d)arg2) -> Matrix2d :

    C++ signature :
        class AcGeMatrix2d __mul__(class AcGeMatrix2d {lvalue},class AcGeMatrix2d)'''
    ...
    def alignCoordSys (self, *args, **kwargs)-> PyGe.Matrix2d :
      '''alignCoordSys( (Point2d)arg1, (Vector2d)arg2, (Vector2d)arg3, (Point2d)arg4, (Vector2d)arg5, (Vector2d)arg6) -> Matrix2d :

    C++ signature :
        class AcGeMatrix2d alignCoordSys(class AcGePoint2d,class AcGeVector2d,class AcGeVector2d,class AcGePoint2d,class AcGeVector2d,class AcGeVector2d)'''
    ...
    def det (self)-> float :
      '''                             '''
    ...
    def elementAt (self, *args, **kwargs)-> float :
      '''elementAt( (Matrix2d)arg1, (SubentType)arg2, (SubentType)arg3) -> float :

    C++ signature :
        double elementAt(class AcGeMatrix2d {lvalue},unsigned int,unsigned int)'''
    ...
    def getCoordSystem (self, *args, **kwargs)-> None :
      '''getCoordSystem( (Matrix2d)arg1, (Point2d)arg2, (Vector2d)arg3, (Vector2d)arg4) -> None :

    C++ signature :
        void getCoordSystem(class AcGeMatrix2d {lvalue},class AcGePoint2d {lvalue},class AcGeVector2d {lvalue},class AcGeVector2d {lvalue})'''
    ...
    def getTranslation (self, *args, **kwargs)-> PyGe.Vector2d :
      '''getTranslation( (Matrix2d)arg1) -> Vector2d :

    C++ signature :
        class AcGeVector2d getTranslation(class AcGeMatrix2d {lvalue})'''
    ...
    def inverse (self)-> PyGe.Matrix2d :
      '''                             '''
    ...
    def invert (self)-> PyGe.Matrix2d :
      '''                             '''
    ...
    def isConformal (self, *args, **kwargs)-> bool :
      '''isConformal( (Matrix2d)arg1, (float)arg2, (float)arg3, (bool)arg4, (Vector2d)arg5) -> bool :

    C++ signature :
        bool isConformal(class AcGeMatrix2d {lvalue},double {lvalue},double {lvalue},bool {lvalue},class AcGeVector2d {lvalue})'''
    ...
    def isEqualTo (self, *args, **kwargs)-> bool :
      '''isEqualTo( (Matrix2d)arg1, (Matrix2d)arg2 [, (Tol)AcGeTol=<PyGe.Tol object at 0x0000015DE42E88B0>]) -> bool :

    C++ signature :
        bool isEqualTo(class AcGeMatrix2d {lvalue},class AcGeMatrix2d [,class AcGeTol=<PyGe.Tol object at 0x0000015DE42E88B0>])'''
    ...
    def isScaledOrtho (self, *args, **kwargs)-> bool :
      '''isScaledOrtho( (Matrix2d)arg1 [, (Tol)AcGeTol=<PyGe.Tol object at 0x0000015DE42E89D0>]) -> bool :

    C++ signature :
        bool isScaledOrtho(class AcGeMatrix2d {lvalue} [,class AcGeTol=<PyGe.Tol object at 0x0000015DE42E89D0>])'''
    ...
    def isSingular (self, *args, **kwargs)-> bool :
      '''isSingular( (Matrix2d)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isSingular(class AcGeMatrix2d {lvalue},class AcGeTol)'''
    ...
    def isUniScaledOrtho (self, *args, **kwargs)-> bool :
      '''isUniScaledOrtho( (Matrix2d)arg1 [, (Tol)AcGeTol=<PyGe.Tol object at 0x0000015DE42E8940>]) -> bool :

    C++ signature :
        bool isUniScaledOrtho(class AcGeMatrix2d {lvalue} [,class AcGeTol=<PyGe.Tol object at 0x0000015DE42E8940>])'''
    ...
    def kIdentity (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def mirroring (self, *args, **kwargs)-> PyGe.Matrix2d :
      '''mirroring( (Point2d)arg1) -> Matrix2d :

    C++ signature :
        class AcGeMatrix2d mirroring(class AcGePoint2d)

mirroring( (object)arg1) -> Matrix2d :

    C++ signature :
        class AcGeMatrix2d mirroring(class AcGeLine2d)'''
    ...
    def postMultBy (self, *args, **kwargs)-> PyGe.Matrix2d :
      '''postMultBy( (Matrix2d)arg1, (Matrix2d)arg2) -> Matrix2d :

    C++ signature :
        class AcGeMatrix2d {lvalue} postMultBy(class AcGeMatrix2d {lvalue},class AcGeMatrix2d)'''
    ...
    def preMultBy (self, *args, **kwargs)-> PyGe.Matrix2d :
      '''preMultBy( (Matrix2d)arg1, (Matrix2d)arg2) -> Matrix2d :

    C++ signature :
        class AcGeMatrix2d {lvalue} preMultBy(class AcGeMatrix2d {lvalue},class AcGeMatrix2d)'''
    ...
    def rotation (self, *args, **kwargs)-> PyGe.Matrix2d :
      '''rotation( (float)arg1, (Point2d)arg2) -> Matrix2d :

    C++ signature :
        class AcGeMatrix2d rotation(double,class AcGePoint2d)'''
    ...
    def scale (self)-> float :
      '''                             '''
    ...

    @staticmethod
    def scaling (scaleAll:float,center: PyGe.Point2d)-> PyGe.Matrix2d :
      '''                             '''
    ...
    def setCoordSystem (self, *args, **kwargs)-> PyGe.Matrix2d :
      '''setCoordSystem( (Matrix2d)arg1, (Point2d)arg2, (Vector2d)arg3, (Vector2d)arg4) -> Matrix2d :

    C++ signature :
        class AcGeMatrix2d {lvalue} setCoordSystem(class AcGeMatrix2d {lvalue},class AcGePoint2d,class AcGeVector2d,class AcGeVector2d)'''
    ...
    def setToAlignCoordSys (self, *args, **kwargs)-> PyGe.Matrix2d :
      '''setToAlignCoordSys( (Matrix2d)arg1, (Point2d)arg2, (Vector2d)arg3, (Vector2d)arg4, (Point2d)arg5, (Vector2d)arg6, (Vector2d)arg7) -> Matrix2d :

    C++ signature :
        class AcGeMatrix2d {lvalue} setToAlignCoordSys(class AcGeMatrix2d {lvalue},class AcGePoint2d,class AcGeVector2d,class AcGeVector2d,class AcGePoint2d,class AcGeVector2d,class AcGeVector2d)'''
    ...
    def setToIdentity (self, *args, **kwargs)-> PyGe.Matrix2d :
      '''setToIdentity( (Matrix2d)arg1) -> Matrix2d :

    C++ signature :
        class AcGeMatrix2d {lvalue} setToIdentity(class AcGeMatrix2d {lvalue})'''
    ...
    def setToMirroring (self, *args, **kwargs)-> PyGe.Matrix2d :
      '''setToMirroring( (Matrix2d)arg1, (Point2d)arg2) -> Matrix2d :

    C++ signature :
        class AcGeMatrix2d {lvalue} setToMirroring(class AcGeMatrix2d {lvalue},class AcGePoint2d)

setToMirroring( (Matrix2d)arg1, (object)arg2) -> Matrix2d :

    C++ signature :
        class AcGeMatrix2d {lvalue} setToMirroring(class AcGeMatrix2d {lvalue},class AcGeLine2d)'''
    ...
    def setToProduct (self, *args, **kwargs)-> PyGe.Matrix2d :
      '''setToProduct( (Matrix2d)arg1, (Matrix2d)arg2, (Matrix2d)arg3) -> Matrix2d :

    C++ signature :
        class AcGeMatrix2d {lvalue} setToProduct(class AcGeMatrix2d {lvalue},class AcGeMatrix2d,class AcGeMatrix2d)'''
    ...
    def setToRotation (self, *args, **kwargs)-> PyGe.Matrix2d :
      '''setToRotation( (Matrix2d)arg1, (float)arg2 [, (Point2d)AcGePoint2d=<PyGe.Point2d(0.00000000000000,0.00000000000000)>]) -> Matrix2d :

    C++ signature :
        class AcGeMatrix2d {lvalue} setToRotation(class AcGeMatrix2d {lvalue},double [,class AcGePoint2d=<PyGe.Point2d(0.00000000000000,0.00000000000000)>])'''
    ...
    def setToScaling (self, *args, **kwargs)-> PyGe.Matrix2d :
      '''setToScaling( (Matrix2d)arg1, (float)arg2, (Point2d)arg3) -> Matrix2d :

    C++ signature :
        class AcGeMatrix2d {lvalue} setToScaling(class AcGeMatrix2d {lvalue},double,class AcGePoint2d)'''
    ...
    def setToTranslation (self, *args, **kwargs)-> PyGe.Matrix2d :
      '''setToTranslation( (Matrix2d)arg1, (Vector2d)arg2) -> Matrix2d :

    C++ signature :
        class AcGeMatrix2d {lvalue} setToTranslation(class AcGeMatrix2d {lvalue},class AcGeVector2d)'''
    ...
    def setTranslation (self, *args, **kwargs)-> PyGe.Matrix2d :
      '''setTranslation( (Matrix2d)arg1, (Vector2d)arg2) -> Matrix2d :

    C++ signature :
        class AcGeMatrix2d {lvalue} setTranslation(class AcGeMatrix2d {lvalue},class AcGeVector2d)'''
    ...
    def toList (self)-> list :
      '''                             '''
    ...
    def toString (self)-> str :
      '''                             '''
    ...
    def toTuple (self)-> tuple :
      '''                             '''
    ...

    @staticmethod
    def translation (vec: PyGe.Vector2d)-> PyGe.Matrix2d :
      '''                             '''
    ...
    def transpose (self)-> PyGe.Matrix2d :
      '''                             '''
    ...
    def transposeIt (self)-> PyGe.Matrix2d :
      '''                             '''
    ...

class Matrix3d(object):
    def __imul__ (self, xform: PyGe.Matrix3d)-> PyGe.Matrix3d :
      '''                             '''
    ...
    def __init__ (self)-> None :
      '''                             '''
    ...
    def __mul__ (self, xform: PyGe.Matrix3d)-> PyGe.Matrix3d :
      '''                             '''
    ...

    @staticmethod
    def alignCoordSys (fromOrigin: PyGe.Point3d,fromXAxis: PyGe.Vector3d,fromYAxis: PyGe.Vector3d,fromZAxis: PyGe.Vector3d,toOrigin: PyGe.Point3d,toXAxis: PyGe.Vector3d,toYAxis: PyGe.Vector3d,toZAxis: PyGe.Vector3d)-> PyGe.Matrix3d :
      '''                             '''
    ...
    def convertToLocal (self, normal: PyGe.Vector3d, elev: float)-> PyGe.Matrix2d :
      '''                             '''
    ...
    def det (self)-> float :
      '''                             '''
    ...
    def elementAt (self, row: int, col: int)-> float :
      '''                             '''
    ...
    def getCoordSystem (self, origin: PyGe.Point3d, x: PyGe.Vector3d, y: PyGe.Vector3d, z: PyGe.Vector3d)-> None :
      '''                             '''
    ...
    def getTranslation (self)-> PyGe.Vector3d :
      '''                             '''
    ...
    def inverse (self, tol: PyGe.Tol=None)-> PyGe.Matrix3d :
      '''                             '''
    ...
    def invert (self)-> PyGe.Matrix3d :
      '''                             '''
    ...
    def isEqualTo (self, other: PyGe.Matrix3d, tol: PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def isScaledOrtho (self, val: PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def isSingular (self, val: PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def isUniScaledOrtho (self, val: PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def kIdentity (self, *args, **kwargs)-> None :
      '''None'''
    ...

    @staticmethod
    def mirroring (val: PyGe.Point3d|PyGe.Plane|PyGe.Line3d)-> PyGe.Matrix3d :
      '''                             '''
    ...
    def norm (self)-> float :
      '''                             '''
    ...

    @staticmethod
    def planeToWorld (val: PyGe.Vector3d|PyGe.Plane)-> PyGe.Matrix3d :
      '''                             '''
    ...
    def postMultBy (self, val: PyGe.Matrix3d)-> PyGe.Matrix3d :
      '''                             '''
    ...
    def preMultBy (self, val: PyGe.Matrix3d)-> PyGe.Matrix3d :
      '''                             '''
    ...

    @staticmethod
    def projection (projectionPlane: PyGe.Plane,projectDir: PyGe.Vector3d)-> PyGe.Matrix3d :
      '''                             '''
    ...

    @staticmethod
    def rotation (angle: float,axis: PyGe.Vector3d,center: PyGe.Point3d)-> PyGe.Matrix3d :
      '''                             '''
    ...
    def scale (self)-> float :
      '''                             '''
    ...

    @staticmethod
    def scaling (val: float,center: PyGe.Point3d)-> PyGe.Matrix3d :
      '''                             '''
    ...
    def setCoordSystem (self, origin: PyGe.Point3d, x: PyGe.Vector3d, y: PyGe.Vector3d, z: PyGe.Vector3d)-> PyGe.Matrix3d :
      '''                             '''
    ...
    def setToAlignCoordSys (self, fromOrigin: PyGe.Point3d, fromXAxis: PyGe.Vector3d, fromYAxis: PyGe.Vector3d, fromZAxis: PyGe.Vector3d, toOrigin: PyGe.Point3d, toXAxis: PyGe.Vector3d, toYAxis: PyGe.Vector3d, toZAxis: PyGe.Vector3d)-> PyGe.Matrix3d :
      '''                             '''
    ...
    def setToIdentity (self)-> PyGe.Matrix3d :
      '''                             '''
    ...

    @overload
    def setToMirroring (self, val: PyGe.Plane)-> None : ...
    @overload
    def setToMirroring (self, val: PyGe.Line3d)-> None : ...
    @overload
    def setToMirroring (self, val: PyGe.Point3d)-> None : ...
    def setToMirroring (self, *args, **kwargs)-> None :
      '''Overloads:
    - val: PyGe.Plane
    - val: PyGe.Line3d
    - val: PyGe.Point3d
    '''
    ...
    def setToPlaneToWorld (self, val: PyGe.Vector3d | PyGe.Plane)-> None :
      '''                             '''
    ...
    def setToProduct (self, mat1: PyGe.Matrix3d, mat2: PyGe.Matrix3d)-> PyGe.Matrix3d :
      '''                             '''
    ...
    def setToProjection (self, projectionPlane: PyGe.Plane, projectDir: PyGe.Vector3d)-> PyGe.Matrix3d :
      '''                             '''
    ...
    def setToRotation (self, angle: float, axis: PyGe.Vector3d, center :PyGe.Point3d=PyGe.Point3d.kOrigin)-> PyGe.Matrix3d :
      '''                             '''
    ...
    def setToScaling (self, val: float, center: PyGe.Point3d=PyGe.Point3d.kOrigin)-> PyGe.Matrix3d :
      '''                             '''
    ...
    def setToTranslation (self, val: PyGe.Vector3d)-> PyGe.Matrix3d :
      '''                             '''
    ...
    def setToWorldToPlane (self, val: PyGe.Vector3d | PyGe.Plane)-> None :
      '''                             '''
    ...
    def setTranslation (self, val: PyGe.Vector2d)-> PyGe.Matrix3d :
      '''                             '''
    ...
    def toList (self)-> list :
      '''                             '''
    ...
    def toString (self)-> str :
      '''                             '''
    ...
    def toTuple (self)-> tuple :
      '''                             '''
    ...

    @staticmethod
    def translation (val: PyGe.Vector3d)-> PyGe.Matrix3d :
      '''                             '''
    ...
    def transpose (self)-> PyGe.Matrix3d :
      '''                             '''
    ...
    def transposeIt (self)-> PyGe.Matrix3d :
      '''                             '''
    ...

    @staticmethod
    def worldToPlane (val: PyGe.Vector3d|PyGe.Plane)-> PyGe.Matrix3d :
      '''                             '''
    ...

class NurbCurve2d(SplineEnt2d):
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (EllipArc2d)arg2) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class PyGeEllipArc2d)

__init__( (object)arg1, (LineSeg2d)arg2) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class PyGeLineSeg2d)

__init__( (object)arg1, (Curve2d)arg2, (float)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class PyGeCurve2d,double)

__init__( (object)arg1, (list)arg2, (Tol)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class boost::python::list,class AcGeTol)

__init__( (object)arg1, (int)arg2, (Polyline2d)arg3, (bool)arg4) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,int,class PyGePolyline2d,bool)

__init__( (object)arg1, (int)arg2, (KnotVector)arg3, (list)arg4, (bool)arg5) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,int,class PyGeKnotVector,class boost::python::list,bool)

__init__( (object)arg1, (list)arg2, (list)arg3, (Tol)arg4, (bool)arg5) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class boost::python::list,class boost::python::list,class AcGeTol,bool)

__init__( (object)arg1, (list)arg2, (Vector2d)arg3, (Vector2d)arg4, (bool)arg5, (bool)arg6, (Tol)arg7) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class boost::python::list,class AcGeVector2d,class AcGeVector2d,bool,bool,class AcGeTol)

__init__( (object)arg1, (list)arg2, (Vector2d)arg3, (Vector2d)arg4, (bool)arg5, (bool)arg6, (KnotParameterization)arg7, (Tol)arg8) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class boost::python::list,class AcGeVector2d,class AcGeVector2d,bool,bool,enum AcGe::KnotParameterization,class AcGeTol)'''
    ...
    def addControlPointAt (self, *args, **kwargs)-> bool :
      '''addControlPointAt( (NurbCurve2d)arg1, (float)arg2, (Point2d)arg3, (float)arg4) -> bool :

    C++ signature :
        bool addControlPointAt(class PyGeNurbCurve2d {lvalue},double,class AcGePoint2d,double)'''
    ...
    def addFitPointAt (self, *args, **kwargs)-> bool :
      '''addFitPointAt( (NurbCurve2d)arg1, (int)arg2, (Point2d)arg3) -> bool :

    C++ signature :
        bool addFitPointAt(class PyGeNurbCurve2d {lvalue},int,class AcGePoint2d)'''
    ...
    def addKnot (self, *args, **kwargs)-> None :
      '''addKnot( (NurbCurve2d)arg1, (float)arg2) -> None :

    C++ signature :
        void addKnot(class PyGeNurbCurve2d {lvalue},double)'''
    ...
    def area (self, startParam : float, endParam : float, tol : float = None)-> float :
      '''                             '''
    ...
    def boundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock2d :
      '''                             '''
    ...
    def buildFitData (self, *args, **kwargs)-> bool :
      '''buildFitData( (NurbCurve2d)arg1) -> bool :

    C++ signature :
        bool buildFitData(class PyGeNurbCurve2d {lvalue})

buildFitData( (NurbCurve2d)arg1, (KnotParameterization)arg2) -> bool :

    C++ signature :
        bool buildFitData(class PyGeNurbCurve2d {lvalue},enum AcGe::KnotParameterization)'''
    ...
    def cast (self, *args, **kwargs)-> PyGe.SplineEnt2d :
      '''cast( (Entity2d)arg1) -> SplineEnt2d :

    C++ signature :
        class PyGeSplineEnt2d cast(class PyGeEntity2d)'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def closestPointTo (self, other : PyGe.Point2d | PyGe.Curve2d, tol : PyGe.Tol=None)-> PyGe.Point2d :
      '''                             '''
    ...
    def continuityAtKnot (self, *args, **kwargs)-> int :
      '''continuityAtKnot( (SplineEnt2d)arg1, (int)arg2) -> int :

    C++ signature :
        int continuityAtKnot(class PyGeSplineEnt2d {lvalue},int)

continuityAtKnot( (SplineEnt2d)arg1, (int)arg2, (Tol)arg3) -> int :

    C++ signature :
        int continuityAtKnot(class PyGeSplineEnt2d {lvalue},int,class AcGeTol)'''
    ...
    def controlPointAt (self, *args, **kwargs)-> PyGe.Point2d :
      '''controlPointAt( (SplineEnt2d)arg1, (int)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d controlPointAt(class PyGeSplineEnt2d {lvalue},int)'''
    ...
    def copy (self)-> PyGe.Entity2d :
      '''                             '''
    ...
    def copycast (self, *args, **kwargs)-> PyGe.NurbCurve2d :
      '''copycast( (Entity2d)arg1) -> NurbCurve2d :

    C++ signature :
        class PyGeNurbCurve2d copycast(class PyGeEntity2d)'''
    ...
    def degree (self, *args, **kwargs)-> int :
      '''degree( (SplineEnt2d)arg1) -> int :

    C++ signature :
        int degree(class PyGeSplineEnt2d {lvalue})'''
    ...
    def deleteControlPointAt (self, *args, **kwargs)-> bool :
      '''deleteControlPointAt( (NurbCurve2d)arg1, (int)arg2) -> bool :

    C++ signature :
        bool deleteControlPointAt(class PyGeNurbCurve2d {lvalue},int)'''
    ...
    def deleteFitPointAt (self, *args, **kwargs)-> bool :
      '''deleteFitPointAt( (NurbCurve2d)arg1, (int)arg2) -> bool :

    C++ signature :
        bool deleteFitPointAt(class PyGeNurbCurve2d {lvalue},int)'''
    ...
    def distanceTo (self, pt : PyGe.Point2d | PyGe.Curve2d, tol : PyGe.Tol=None)-> float :
      '''                             '''
    ...
    def elevateDegree (self, *args, **kwargs)-> None :
      '''elevateDegree( (NurbCurve2d)arg1, (int)arg2) -> None :

    C++ signature :
        void elevateDegree(class PyGeNurbCurve2d {lvalue},int)'''
    ...
    def endParam (self, *args, **kwargs)-> float :
      '''endParam( (SplineEnt2d)arg1) -> float :

    C++ signature :
        double endParam(class PyGeSplineEnt2d {lvalue})'''
    ...
    def endPoint (self, *args, **kwargs)-> PyGe.Point2d :
      '''endPoint( (SplineEnt2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d endPoint(class PyGeSplineEnt2d {lvalue})'''
    ...
    def evalMode (self, *args, **kwargs)-> bool :
      '''evalMode( (NurbCurve2d)arg1) -> bool :

    C++ signature :
        bool evalMode(class PyGeNurbCurve2d {lvalue})'''
    ...
    def evalPoint (self, param : float, numDeriv : int = 1)-> PyGe.Point2d :
      '''                             '''
    ...
    def explode (self, val : PyGe.Interval = None)-> list :
      '''                             '''
    ...
    def getClosestPointTo (self, other : PyGe.Point2d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve2d :
      '''                             '''
    ...
    def getClosestPointsTo (self, other : PyGe.Curve2d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def getDefinitionData (self, *args, **kwargs)-> tuple :
      '''getDefinitionData( (NurbCurve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple getDefinitionData(class PyGeNurbCurve2d {lvalue})'''
    ...
    def getEndPoint (self)-> PyGe.Point2d :
      '''                             '''
    ...
    def getFitData (self, *args, **kwargs)-> tuple :
      '''getFitData( (NurbCurve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple getFitData(class PyGeNurbCurve2d {lvalue})'''
    ...
    def getFitPointAt (self, *args, **kwargs)-> tuple :
      '''getFitPointAt( (NurbCurve2d)arg1, (int)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getFitPointAt(class PyGeNurbCurve2d {lvalue},int)'''
    ...
    def getFitTangents (self, *args, **kwargs)-> tuple :
      '''getFitTangents( (NurbCurve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple getFitTangents(class PyGeNurbCurve2d {lvalue})'''
    ...
    def getFitTolerance (self, *args, **kwargs)-> tuple :
      '''getFitTolerance( (NurbCurve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple getFitTolerance(class PyGeNurbCurve2d {lvalue})'''
    ...
    def getInterval (self)-> PyGe.Interval :
      '''                             '''
    ...
    def getNormalPoint (self, pnt : PyGe.Point2d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve2d :
      '''                             '''
    ...
    def getParamsOfC1Discontinuity (self, *args, **kwargs)-> tuple :
      '''getParamsOfC1Discontinuity( (NurbCurve2d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getParamsOfC1Discontinuity(class PyGeNurbCurve2d {lvalue},class AcGeTol)'''
    ...
    def getParamsOfG1Discontinuity (self, *args, **kwargs)-> tuple :
      '''getParamsOfG1Discontinuity( (NurbCurve2d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getParamsOfG1Discontinuity(class PyGeNurbCurve2d {lvalue},class AcGeTol)'''
    ...

    @overload
    def getSamplePoints (self, numSample: int)-> list : ...
    @overload
    def getSamplePoints (self, fromParam: float, toParam: float, approxEps: float)-> list : ...
    def getSamplePoints (self, *args, **kwargs)-> list :
      '''Overloads:
    - numSample: int
    - fromParam: float, toParam: float, approxEps: float
    '''
    ...
    def getSplitCurves (self, param : float)-> tuple :
      '''                             '''
    ...
    def getStartPoint (self)-> PyGe.Point2d :
      '''                             '''
    ...
    def getTrimmedOffset (self, dist : float, extensionType : PyGe.OffsetCrvExtType, tol : PyGe.Tol=None)-> list :
      '''                             '''
    ...
    def hardTrimByParams (self, *args, **kwargs)-> None :
      '''hardTrimByParams( (NurbCurve2d)arg1, (float)arg2, (float)arg3) -> None :

    C++ signature :
        void hardTrimByParams(class PyGeNurbCurve2d {lvalue},double,double)'''
    ...
    def hasEndPoint (self)-> bool :
      '''                             '''
    ...
    def hasFitData (self, *args, **kwargs)-> bool :
      '''hasFitData( (SplineEnt2d)arg1) -> bool :

    C++ signature :
        bool hasFitData(class PyGeSplineEnt2d {lvalue})'''
    ...
    def hasStartPoint (self)-> bool :
      '''                             '''
    ...
    def insertKnot (self, *args, **kwargs)-> None :
      '''insertKnot( (NurbCurve2d)arg1, (float)arg2) -> None :

    C++ signature :
        void insertKnot(class PyGeNurbCurve2d {lvalue},double)'''
    ...
    def isClosed (self, tol : PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def isDegenerate (self, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isEqualTo (self, val : PyGe.Entity2d, tol : PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def isKindOf (self, val : PyGe.EntityId)-> bool :
      '''                             '''
    ...
    def isLinear (self, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isNull (self)-> bool :
      '''                             '''
    ...
    def isOn (self, pt : float | PyGe.Point2d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isPeriodic (self)-> tuple :
      '''                             '''
    ...
    def isRational (self, *args, **kwargs)-> bool :
      '''isRational( (SplineEnt2d)arg1) -> bool :

    C++ signature :
        bool isRational(class PyGeSplineEnt2d {lvalue})'''
    ...
    def joinWith (self, *args, **kwargs)-> None :
      '''joinWith( (NurbCurve2d)arg1, (NurbCurve2d)arg2) -> None :

    C++ signature :
        void joinWith(class PyGeNurbCurve2d {lvalue},class PyGeNurbCurve2d)'''
    ...
    def knotAt (self, *args, **kwargs)-> float :
      '''knotAt( (SplineEnt2d)arg1, (int)arg2) -> float :

    C++ signature :
        double knotAt(class PyGeSplineEnt2d {lvalue},int)'''
    ...
    def knots (self, *args, **kwargs)-> PyGe.KnotVector :
      '''knots( (SplineEnt2d)arg1) -> KnotVector :

    C++ signature :
        class PyGeKnotVector knots(class PyGeSplineEnt2d {lvalue})'''
    ...
    def length (self, frm : float, to : float, tol : float = None)-> float :
      '''                             '''
    ...
    def makeClosed (self, *args, **kwargs)-> None :
      '''makeClosed( (NurbCurve2d)arg1) -> None :

    C++ signature :
        void makeClosed(class PyGeNurbCurve2d {lvalue})'''
    ...
    def makeNonPeriodic (self, *args, **kwargs)-> None :
      '''makeNonPeriodic( (NurbCurve2d)arg1) -> None :

    C++ signature :
        void makeNonPeriodic(class PyGeNurbCurve2d {lvalue})'''
    ...
    def makeOpen (self, *args, **kwargs)-> None :
      '''makeOpen( (NurbCurve2d)arg1) -> None :

    C++ signature :
        void makeOpen(class PyGeNurbCurve2d {lvalue})'''
    ...
    def makePeriodic (self, *args, **kwargs)-> None :
      '''makePeriodic( (NurbCurve2d)arg1) -> None :

    C++ signature :
        void makePeriodic(class PyGeNurbCurve2d {lvalue})'''
    ...
    def makeRational (self, *args, **kwargs)-> None :
      '''makeRational( (NurbCurve2d)arg1, (float)arg2) -> None :

    C++ signature :
        void makeRational(class PyGeNurbCurve2d {lvalue},double)'''
    ...
    def mirror (self, val : PyGe.Line2d)-> None :
      '''                             '''
    ...
    def numControlPoints (self, *args, **kwargs)-> int :
      '''numControlPoints( (SplineEnt2d)arg1) -> int :

    C++ signature :
        int numControlPoints(class PyGeSplineEnt2d {lvalue})'''
    ...
    def numFitPoints (self, *args, **kwargs)-> int :
      '''numFitPoints( (NurbCurve2d)arg1) -> int :

    C++ signature :
        int numFitPoints(class PyGeNurbCurve2d {lvalue})'''
    ...
    def numKnots (self, *args, **kwargs)-> int :
      '''numKnots( (SplineEnt2d)arg1) -> int :

    C++ signature :
        int numKnots(class PyGeSplineEnt2d {lvalue})'''
    ...
    def numWeights (self, *args, **kwargs)-> int :
      '''numWeights( (NurbCurve2d)arg1) -> int :

    C++ signature :
        int numWeights(class PyGeNurbCurve2d {lvalue})'''
    ...
    def order (self, *args, **kwargs)-> int :
      '''order( (SplineEnt2d)arg1) -> int :

    C++ signature :
        int order(class PyGeSplineEnt2d {lvalue})'''
    ...
    def orthoBoundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock2d :
      '''                             '''
    ...
    def paramAtLength (self, datumParam: float, length: float, posParamDir: bool=True, tol: float=None)-> float :
      '''                             '''
    ...
    def paramOf (self, pt : PyGe.Point2d, tol : PyGe.Tol=None)-> float :
      '''                             '''
    ...
    def purgeFitData (self, *args, **kwargs)-> bool :
      '''purgeFitData( (NurbCurve2d)arg1) -> bool :

    C++ signature :
        bool purgeFitData(class PyGeNurbCurve2d {lvalue})'''
    ...
    def reverseParam (self)-> None :
      '''                             '''
    ...
    def rotateBy (self, angle : float, pt : PyGe.Point3d=PyGe.Point2d.kOrgin)-> None :
      '''                             '''
    ...
    def scaleBy (self, scaleFactor : float, pt : PyGe.Point2d=PyGe.Point2d.kOrgin)-> None :
      '''                             '''
    ...
    def setControlPointAt (self, *args, **kwargs)-> None :
      '''setControlPointAt( (SplineEnt2d)arg1, (int)arg2, (Point2d)arg3) -> None :

    C++ signature :
        void setControlPointAt(class PyGeSplineEnt2d {lvalue},int,class AcGePoint2d)'''
    ...
    def setEvalMode (self, *args, **kwargs)-> None :
      '''setEvalMode( (NurbCurve2d)arg1, (bool)arg2) -> None :

    C++ signature :
        void setEvalMode(class PyGeNurbCurve2d {lvalue},bool)'''
    ...
    def setFitData (self, *args, **kwargs)-> None :
      '''setFitData( (NurbCurve2d)arg1, (list)arg2, (Vector2d)arg3, (Vector2d)arg4, (Tol)arg5) -> None :

    C++ signature :
        void setFitData(class PyGeNurbCurve2d {lvalue},class boost::python::list,class AcGeVector2d,class AcGeVector2d,class AcGeTol)

setFitData( (NurbCurve2d)arg1, (list)arg2, (Vector2d)arg3, (Vector2d)arg4, (KnotParameterization)arg5, (Tol)arg6) -> None :

    C++ signature :
        void setFitData(class PyGeNurbCurve2d {lvalue},class boost::python::list,class AcGeVector2d,class AcGeVector2d,enum AcGe::KnotParameterization,class AcGeTol)

setFitData( (NurbCurve2d)arg1, (KnotVector)arg2, (list)arg3, (Vector2d)arg4, (Vector2d)arg5, (Tol)arg6, (bool)arg7) -> None :

    C++ signature :
        void setFitData(class PyGeNurbCurve2d {lvalue},class PyGeKnotVector,class boost::python::list,class AcGeVector2d,class AcGeVector2d,class AcGeTol,bool)

setFitData( (NurbCurve2d)arg1, (int)arg2, (list)arg3, (Tol)arg4) -> None :

    C++ signature :
        void setFitData(class PyGeNurbCurve2d {lvalue},int,class boost::python::list,class AcGeTol)'''
    ...
    def setFitKnotParameterization (self, *args, **kwargs)-> bool :
      '''setFitKnotParameterization( (NurbCurve2d)arg1, (KnotParameterization)arg2) -> bool :

    C++ signature :
        bool setFitKnotParameterization(class PyGeNurbCurve2d {lvalue},enum AcGe::KnotParameterization)'''
    ...
    def setFitPointAt (self, *args, **kwargs)-> bool :
      '''setFitPointAt( (NurbCurve2d)arg1, (int)arg2, (Point2d)arg3) -> bool :

    C++ signature :
        bool setFitPointAt(class PyGeNurbCurve2d {lvalue},int,class AcGePoint2d)'''
    ...
    def setFitTangents (self, *args, **kwargs)-> bool :
      '''setFitTangents( (NurbCurve2d)arg1, (Vector2d)arg2, (Vector2d)arg3) -> bool :

    C++ signature :
        bool setFitTangents(class PyGeNurbCurve2d {lvalue},class AcGeVector2d,class AcGeVector2d)'''
    ...
    def setFitTolerance (self, *args, **kwargs)-> bool :
      '''setFitTolerance( (NurbCurve2d)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool setFitTolerance(class PyGeNurbCurve2d {lvalue},class AcGeTol)'''
    ...
    def setInterval (self, val : PyGe.Interval = None)-> None :
      '''                             '''
    ...
    def setKnotAt (self, *args, **kwargs)-> None :
      '''setKnotAt( (SplineEnt2d)arg1, (int)arg2, (float)arg3) -> None :

    C++ signature :
        void setKnotAt(class PyGeSplineEnt2d {lvalue},int,double)'''
    ...
    def setWeightAt (self, *args, **kwargs)-> None :
      '''setWeightAt( (NurbCurve2d)arg1, (int)arg2, (float)arg3) -> None :

    C++ signature :
        void setWeightAt(class PyGeNurbCurve2d {lvalue},int,double)'''
    ...
    def startParam (self, *args, **kwargs)-> float :
      '''startParam( (SplineEnt2d)arg1) -> float :

    C++ signature :
        double startParam(class PyGeSplineEnt2d {lvalue})'''
    ...
    def startPoint (self, *args, **kwargs)-> PyGe.Point2d :
      '''startPoint( (SplineEnt2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d startPoint(class PyGeSplineEnt2d {lvalue})'''
    ...
    def transformBy (self, val : PyGe.Matrix2d)-> None :
      '''                             '''
    ...
    def translateBy (self, vec : PyGe.Vector2d)-> None :
      '''                             '''
    ...
    def type (self)-> PyGe.EntityId :
      '''                             '''
    ...
    def weightAt (self, *args, **kwargs)-> float :
      '''weightAt( (NurbCurve2d)arg1, (int)arg2) -> float :

    C++ signature :
        double weightAt(class PyGeNurbCurve2d {lvalue},int)'''
    ...

class NurbCurve3d(SplineEnt3d):
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (EllipArc3d)arg2) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class PyGeEllipArc3d)

__init__( (object)arg1, (LineSeg3d)arg2) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class PyGeLineSeg3d)

__init__( (object)arg1, (Curve3d)arg2, (float)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class PyGeCurve3d,double)

__init__( (object)arg1, (list)arg2, (Tol)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class boost::python::list,class AcGeTol)

__init__( (object)arg1, (int)arg2, (Polyline3d)arg3, (bool)arg4) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,int,class PyGePolyline3d,bool)

__init__( (object)arg1, (int)arg2, (KnotVector)arg3, (list)arg4, (bool)arg5) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,int,class PyGeKnotVector,class boost::python::list,bool)

__init__( (object)arg1, (list)arg2, (list)arg3, (Tol)arg4, (bool)arg5) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class boost::python::list,class boost::python::list,class AcGeTol,bool)

__init__( (object)arg1, (list)arg2, (Vector3d)arg3, (Vector3d)arg4, (bool)arg5, (bool)arg6, (Tol)arg7) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class boost::python::list,class AcGeVector3d,class AcGeVector3d,bool,bool,class AcGeTol)

__init__( (object)arg1, (list)arg2, (Vector3d)arg3, (Vector3d)arg4, (bool)arg5, (bool)arg6, (KnotParameterization)arg7, (Tol)arg8) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class boost::python::list,class AcGeVector3d,class AcGeVector3d,bool,bool,enum AcGe::KnotParameterization,class AcGeTol)'''
    ...
    def addControlPointAt (self, *args, **kwargs)-> bool :
      '''addControlPointAt( (NurbCurve3d)arg1, (float)arg2, (Point3d)arg3, (float)arg4) -> bool :

    C++ signature :
        bool addControlPointAt(class PyGeNurbCurve3d {lvalue},double,class AcGePoint3d,double)'''
    ...
    def addFitPointAt (self, *args, **kwargs)-> bool :
      '''addFitPointAt( (NurbCurve3d)arg1, (int)arg2, (Point3d)arg3) -> bool :

    C++ signature :
        bool addFitPointAt(class PyGeNurbCurve3d {lvalue},int,class AcGePoint3d)'''
    ...
    def addKnot (self, *args, **kwargs)-> None :
      '''addKnot( (NurbCurve3d)arg1, (float)arg2) -> None :

    C++ signature :
        void addKnot(class PyGeNurbCurve3d {lvalue},double)'''
    ...
    def area (self, startParam : float, endParam : float, tol : float = None)-> float :
      '''Returns the area of the interval of the curve defined by startParam and endParam. Returns Adesk::kTrue if area was successfully computed to within the specified tolerance. If the curve is not planar, then the area cannot be calculated and a value of Adesk::kFalse is returned. If the points at startParam and endParam are the same, then this function returns the area of the closed curve. If the points are different, then this function connects the two points with a line segment and return the signed area between the curve and the line segment. If the line segment does not intersect the curve at any points between startParam and endParam, then the returned area is positive. If the line segment intersects the curves at any points between startParam and endParam, then the returned area is the sum of the sub-areas created by the intersection of the line segment with the curve. Each sub-area has a positive or negative area, depending on whether the curve lies above or below the line segment. The total area returned by this function can therefore be positive, negative, or 0. '''
    ...
    def boundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock3d :
      '''Returns the bounding box of the curve. The sides of the returned box are parallel to the coordinate axes. '''
    ...
    def buildFitData (self, *args, **kwargs)-> bool :
      '''buildFitData( (NurbCurve3d)arg1) -> bool :

    C++ signature :
        bool buildFitData(class PyGeNurbCurve3d {lvalue})

buildFitData( (NurbCurve3d)arg1, (KnotParameterization)arg2) -> bool :

    C++ signature :
        bool buildFitData(class PyGeNurbCurve3d {lvalue},enum AcGe::KnotParameterization)'''
    ...
    def cast (self, *args, **kwargs)-> PyGe.NurbCurve3d :
      '''cast( (Entity3d)arg1) -> NurbCurve3d :

    C++ signature :
        class PyGeNurbCurve3d cast(class PyGeEntity3d)'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def closestPointTo (self, other : PyGe.Point3d | PyGe.Curve3d, tol : PyGe.Tol=None)-> PyGe.Point3d :
      '''Finds the closest point on this curve to the input point. This function is the same as closestPointTo(), except that the closest point is returned as an AcGePointOnCurve3d object.'''
    ...
    def continuityAtKnot (self, *args, **kwargs)-> int :
      '''continuityAtKnot( (SplineEnt3d)arg1, (int)arg2) -> int :

    C++ signature :
        int continuityAtKnot(class PyGeSplineEnt3d {lvalue},int)

continuityAtKnot( (SplineEnt3d)arg1, (int)arg2, (Tol)arg3) -> int :

    C++ signature :
        int continuityAtKnot(class PyGeSplineEnt3d {lvalue},int,class AcGeTol)'''
    ...
    def controlPointAt (self, *args, **kwargs)-> PyGe.Point3d :
      '''controlPointAt( (SplineEnt3d)arg1, (int)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d controlPointAt(class PyGeSplineEnt3d {lvalue},int)'''
    ...
    def copy (self)-> PyGe.Entity3d :
      '''Returns a pointer to a copy of this entity. This copy is created using the new and it is the responsibility of the caller to delete it.'''
    ...
    def copycast (self, *args, **kwargs)-> PyGe.NurbCurve3d :
      '''copycast( (Entity3d)arg1) -> NurbCurve3d :

    C++ signature :
        class PyGeNurbCurve3d copycast(class PyGeEntity3d)'''
    ...
    def degree (self, *args, **kwargs)-> int :
      '''degree( (SplineEnt3d)arg1) -> int :

    C++ signature :
        int degree(class PyGeSplineEnt3d {lvalue})'''
    ...
    def deleteControlPointAt (self, *args, **kwargs)-> bool :
      '''deleteControlPointAt( (NurbCurve3d)arg1, (int)arg2) -> bool :

    C++ signature :
        bool deleteControlPointAt(class PyGeNurbCurve3d {lvalue},int)'''
    ...
    def deleteFitPointAt (self, *args, **kwargs)-> bool :
      '''deleteFitPointAt( (NurbCurve3d)arg1, (int)arg2) -> bool :

    C++ signature :
        bool deleteFitPointAt(class PyGeNurbCurve3d {lvalue},int)'''
    ...
    def distanceTo (self, pt : PyGe.Point3d | PyGe.Curve3d, tol : PyGe.Tol=None)-> float :
      '''Returns the distance between the input point and the closest point on this curve.'''
    ...
    def elevateDegree (self, *args, **kwargs)-> None :
      '''elevateDegree( (NurbCurve3d)arg1, (int)arg2) -> None :

    C++ signature :
        void elevateDegree(class PyGeNurbCurve3d {lvalue},int)'''
    ...
    def endParam (self, *args, **kwargs)-> float :
      '''endParam( (SplineEnt3d)arg1) -> float :

    C++ signature :
        double endParam(class PyGeSplineEnt3d {lvalue})'''
    ...
    def endPoint (self, *args, **kwargs)-> PyGe.Point3d :
      '''endPoint( (SplineEnt3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d endPoint(class PyGeSplineEnt3d {lvalue})'''
    ...
    def evalMode (self, *args, **kwargs)-> bool :
      '''evalMode( (NurbCurve3d)arg1) -> bool :

    C++ signature :
        bool evalMode(class PyGeNurbCurve3d {lvalue})'''
    ...
    def evalPoint (self, param : float, numDeriv : int = 1)-> PyGe.Point3d :
      '''Returns the point on the curve that corresponds to the input parameter value. Also returns the number of derivative vectors that are specified in numDeriv. The numDeriv parameter should not be set larger than 2.'''
    ...
    def explode (self, val : PyGe.Interval = None)-> list :
      '''Explodes the curve into its individual components. If the curve is a composite curve, then explodedCurves contains the list of component curves of the composite. If the curve is a spline, then it is exploded at the points of C1 discontinuity and explodedCurves contains a copy of each continuous sub-curve. This function returns Adesk::kTrue if the curve was exploded (that is, the curve was a composite or a discontinuous spline) and Adesk::kFalse otherwise. The number of entries returned in newExplodedCurves is always the same as the number of entries in explodedCurves. Each flag in newExplodedCurves indicates whether the corresponding curve in explodedCurves was created with the new operator. If the flag is 1, then it is the responsibility of the caller to delete the curve. If the flag is 0, the curve is deleted by gelib and the caller should not attempt to delete it. If no intrvl parameter is supplied, then the interval is taken to be the entire curve. '''
    ...
    def getClosestPointTo (self, other : PyGe.Point3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''Finds the closest point on this curve to the input point. This function is the same as closestPointTo(), except that the closest point is returned as an AcGePointOnCurve3d object.'''
    ...
    def getClosestPointsTo (self, other : PyGe.Curve3d, tol : PyGe.Tol=None)-> tuple :
      '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
    ...
    def getDefinitionData (self, *args, **kwargs)-> tuple :
      '''getDefinitionData( (NurbCurve3d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple getDefinitionData(class PyGeNurbCurve3d {lvalue})'''
    ...
    def getEndPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def getFitData (self, *args, **kwargs)-> tuple :
      '''getFitData( (NurbCurve3d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple getFitData(class PyGeNurbCurve3d {lvalue})'''
    ...
    def getFitPointAt (self, *args, **kwargs)-> tuple :
      '''getFitPointAt( (NurbCurve3d)arg1, (int)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getFitPointAt(class PyGeNurbCurve3d {lvalue},int)'''
    ...
    def getFitTangents (self, *args, **kwargs)-> tuple :
      '''getFitTangents( (NurbCurve3d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple getFitTangents(class PyGeNurbCurve3d {lvalue})'''
    ...
    def getFitTolerance (self, *args, **kwargs)-> tuple :
      '''getFitTolerance( (NurbCurve3d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple getFitTolerance(class PyGeNurbCurve3d {lvalue})'''
    ...
    def getInterval (self)-> PyGe.Interval :
      '''Returns the parametric range of the curve. The function evalPoint(double) always returns a point on this curve when called with a value within the returned interval.'''
    ...
    def getNormalPoint (self, pnt : PyGe.Point3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''Finds the point on the input curve whose normal passes through the input point. The returned point lies on a plane that also contains the input point and is perpendicular to the curve tangent at that point. The returned point is therefore at a local minimum or a local maximum from the input point. The curve does not need to be planar. If the curve is planar, the input point does not need to lie in the plane of the curve. On input, the second parameter is assumed to contain the parameter value of an initial guess. If there is more than one normal point on the curve, the returned point will be the one whose parameter value is closest to the input parameter value.'''
    ...
    def getParamsOfC1Discontinuity (self, *args, **kwargs)-> tuple :
      '''getParamsOfC1Discontinuity( (NurbCurve3d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getParamsOfC1Discontinuity(class PyGeNurbCurve3d {lvalue},class AcGeTol)'''
    ...
    def getParamsOfG1Discontinuity (self, *args, **kwargs)-> tuple :
      '''getParamsOfG1Discontinuity( (NurbCurve3d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getParamsOfG1Discontinuity(class PyGeNurbCurve3d {lvalue},class AcGeTol)'''
    ...
    def getProjClosestPointTo (self, pt : PyGe.Point3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
    ...
    def getProjClosestPointsTo (self, pt : PyGe.Curve3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> tuple :
      '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
    ...

    @overload
    def getSamplePoints (self, numSample: int)-> tuple : ...
    @overload
    def getSamplePoints (self, fromParam: float, toParam: float, approxEps: float)-> tuple : ...
    def getSamplePoints (self, *args, **kwargs)-> tuple :
      '''Overloads:
    - numSample: int
    - fromParam: float, toParam: float, approxEps: float
    
	-Returns the specified number of points on the curve. The points are equally spaced by parameter value. So if the interval of the curve [0,1] and numSample is 5, the parameter values of the returned points are 0, 0.25, 0.5, 0.75, and 1.-'''
    ...
    def getSplitCurves (self, param : float)-> tuple :
      '''Returns two segments which are obtained by splitting the curve at the input parameter value. If the specified parameter value does not lie within the parametric interval of the curve or if it corresponds to the start point or endpoint of the curve, then piece1 and piece2 are set to null. This function uses the new to create the curve segments whose addresses are returned in piece1 and piece2. It is the responsibility of the caller to delete these objects. '''
    ...
    def getStartPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def getTrimmedOffset (self, dist : float, planeNormal : PyGe.Vector3d, extensionType : PyGe.OffsetCrvExtType, tol : PyGe.Tol=None)-> list :
      '''Returns one or more offset curves that represent the trimmed offset of the curve. The curve must be planar and planeNormal must be perpendicular to the plane of the curve. The positive direction of offset at a point on the curve is taken to be the cross product of planeNormal with the tangent vector at that point. The curve may be offset in either of two directions by specifying a positive or negative offset distance; planeNormal determines which direction is the positive direction of offset. The returned offset curves are trimmed so that they do not contain any points of self-intersection. Each curve that is returned in offsetCurveList is created with the new and it is the responsibility of the caller to delete these curves. Each curve that is returned in offsetCurveList is a connected curve and may be a composite curve if the offset curve had to be trimmed to remove self-intersecting loops. offsetCurveList only contains more than one curve if the offset operation produces multiple curves which are not connected. If the original curve contains points of C1 discontinuity and the direction of offset causes the offset curve to be disjoint (for instance, if the original curve is a composite curve that is a rectangle and the direction of offset is to the outside of the rectangle), then the offset curve is closed with an arc or a line segment, or the curves are simply extended depending on the value of extensionType.'''
    ...
    def hardTrimByParams (self, *args, **kwargs)-> None :
      '''hardTrimByParams( (NurbCurve3d)arg1, (float)arg2, (float)arg3) -> None :

    C++ signature :
        void hardTrimByParams(class PyGeNurbCurve3d {lvalue},double,double)'''
    ...
    def hasEndPoint (self)-> bool :
      '''Returns Adesk::kTrue if curve has an endpoint. A return value of Adesk::kFalse means that the parametric interval of the curve does not have an upper bound. The endPnt parameter contains meaningful data only if this function returns a value of Adesk::kTrue.'''
    ...
    def hasFitData (self, *args, **kwargs)-> bool :
      '''hasFitData( (SplineEnt3d)arg1) -> bool :

    C++ signature :
        bool hasFitData(class PyGeSplineEnt3d {lvalue})'''
    ...
    def hasStartPoint (self)-> bool :
      '''Returns Adesk::kTrue if curve has a start point. A return value of Adesk::kFalse means that the parametric interval of the curve does not have a lower bound. The startPnt parameter contains meaningful data only if this function returns a value of Adesk::kTrue.'''
    ...
    def insertKnot (self, *args, **kwargs)-> None :
      '''insertKnot( (NurbCurve3d)arg1, (float)arg2) -> None :

    C++ signature :
        void insertKnot(class PyGeNurbCurve3d {lvalue},double)'''
    ...
    def isClosed (self, tol : PyGe.Tol=None)-> bool :
      '''Determines if start point and endpoint of curve are the same.'''
    ...
    def isCoplanarWith (self, curve : PyGe.Curve3d, tol : PyGe.Tol=None)-> tuple :
      '''Returns Adesk::kTrue if both curve are planar and lie in the same plane. The plane parameter is only valid if this function returns a value of Adesk::kTrue.'''
    ...
    def isDegenerate (self, tol : PyGe.Tol=None)-> tuple :
      '''Determines if the curve is degenerate and if so returns the type of entity which the curve degenerates into. For example, if the curve is a circle with a radius of 0 then degenerateType is set to AcGe::kPoint3d. If the curve is an ellipse with a minor radius of 0 and a major radius of 1, then degenerateType is set to AcGe::kLineSeg3d. The degenerateType parameter is only set to something meaningful when this function returns a value of Adesk::kTrue.'''
    ...
    def isEqualTo (self, val : PyGe.Entity3d, tol : PyGe.Tol=None)-> bool :
      '''Determines if two entities are equal to each other. Two entities are considered to be equal only if they are of the same type and they represent the same 3D point set. For instance, if the two entities are of types AcGeCircArc3d and AcGeEllipArc3d then they are not considered equal even if the ellipse is completely coincident with the circle. Also, two curves are not considered equal unless they have the same parameterization. For instance, two infinite coincident lines are not considered equal if they have different scaling in their parameterization. '''
    ...
    def isKindOf (self, val : PyGe.EntityId)-> bool :
      '''                             '''
    ...
    def isLinear (self, tol : PyGe.Tol=None)-> tuple :
      '''Determines if curve is linear. This function returns an infinite line even if the curve is not infinite. The line parameter contains meaningful data only if this function returns a value of Adesk::kTrue.'''
    ...
    def isNull (self)-> bool :
      '''                             '''
    ...
    def isOn (self, pt : float | PyGe.Point3d, tol : PyGe.Tol=None)-> tuple :
      '''Determines if input parameter value is within valid parametric range of curve.'''
    ...
    def isPeriodic (self)-> tuple :
      '''Determines if the curve is periodic. The curve is periodic if and only if it is closed and the two points evalPoint(t) and evalPoint(t+period) are always the same point for all values of t.'''
    ...
    def isPlanar (self, tol : PyGe.Tol=None)-> tuple :
      '''Determines if curve is planar. If the curve is a line, then this function returns an arbitrary plane that contains the line. The plane parameter contains meaningful data only if this function returns a value of Adesk::kTrue. '''
    ...
    def isRational (self, *args, **kwargs)-> bool :
      '''isRational( (SplineEnt3d)arg1) -> bool :

    C++ signature :
        bool isRational(class PyGeSplineEnt3d {lvalue})'''
    ...
    def joinWith (self, *args, **kwargs)-> None :
      '''joinWith( (NurbCurve3d)arg1, (NurbCurve3d)arg2) -> None :

    C++ signature :
        void joinWith(class PyGeNurbCurve3d {lvalue},class PyGeNurbCurve3d)'''
    ...
    def knotAt (self, *args, **kwargs)-> float :
      '''knotAt( (SplineEnt3d)arg1, (int)arg2) -> float :

    C++ signature :
        double knotAt(class PyGeSplineEnt3d {lvalue},int)'''
    ...
    def knots (self, *args, **kwargs)-> PyGe.KnotVector :
      '''knots( (SplineEnt3d)arg1) -> KnotVector :

    C++ signature :
        class PyGeKnotVector knots(class PyGeSplineEnt3d {lvalue})'''
    ...
    def length (self, frm : float, to : float, tol : float = None)-> float :
      '''Returns the arc length of the curve between the two parameter values.'''
    ...
    def makeClosed (self, *args, **kwargs)-> None :
      '''makeClosed( (NurbCurve3d)arg1) -> None :

    C++ signature :
        void makeClosed(class PyGeNurbCurve3d {lvalue})'''
    ...
    def makeNonPeriodic (self, *args, **kwargs)-> None :
      '''makeNonPeriodic( (NurbCurve3d)arg1) -> None :

    C++ signature :
        void makeNonPeriodic(class PyGeNurbCurve3d {lvalue})'''
    ...
    def makeOpen (self, *args, **kwargs)-> None :
      '''makeOpen( (NurbCurve3d)arg1) -> None :

    C++ signature :
        void makeOpen(class PyGeNurbCurve3d {lvalue})'''
    ...
    def makePeriodic (self, *args, **kwargs)-> None :
      '''makePeriodic( (NurbCurve3d)arg1) -> None :

    C++ signature :
        void makePeriodic(class PyGeNurbCurve3d {lvalue})'''
    ...
    def makeRational (self, *args, **kwargs)-> None :
      '''makeRational( (NurbCurve3d)arg1, (float)arg2) -> None :

    C++ signature :
        void makeRational(class PyGeNurbCurve3d {lvalue},double)'''
    ...
    def mirror (self, val : PyGe.Plane)-> None :
      '''Transforms the entity by mirroring it across the input plane.'''
    ...
    def numControlPoints (self, *args, **kwargs)-> int :
      '''numControlPoints( (SplineEnt3d)arg1) -> int :

    C++ signature :
        int numControlPoints(class PyGeSplineEnt3d {lvalue})'''
    ...
    def numFitPoints (self, *args, **kwargs)-> int :
      '''numFitPoints( (NurbCurve3d)arg1) -> int :

    C++ signature :
        int numFitPoints(class PyGeNurbCurve3d {lvalue})'''
    ...
    def numKnots (self, *args, **kwargs)-> int :
      '''numKnots( (SplineEnt3d)arg1) -> int :

    C++ signature :
        int numKnots(class PyGeSplineEnt3d {lvalue})'''
    ...
    def numWeights (self, *args, **kwargs)-> int :
      '''numWeights( (NurbCurve3d)arg1) -> int :

    C++ signature :
        int numWeights(class PyGeNurbCurve3d {lvalue})'''
    ...
    def order (self, *args, **kwargs)-> int :
      '''order( (SplineEnt3d)arg1) -> int :

    C++ signature :
        int order(class PyGeSplineEnt3d {lvalue})'''
    ...
    def orthoBoundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock3d :
      '''Returns the bounding box of the curve. The sides of the returned box are parallel to the coordinate axes.'''
    ...
    def orthoProject (self, projectionPlane : PyGe.Plane, tol : PyGe.Tol=None)-> PyGe.Entity3d :
      '''Returns the entity that is the orthogonal projection of the curve onto the projection plane. The returned entity may not be of the same type as the original curve and may not even be a curve (for instance, a line projects into a point if it is orthogonal to the projection plane). The returned entity is created with the new and it is the responsibility of the caller to delete it.'''
    ...
    def paramAtLength (self, datumParam : float, length : float, posParamDir : bool=True, tol : float = default)-> float :
      '''Returns the parameter value of the point whose arc length distance (from the point with parameter value datumParam) is the input length. In other words, ift = paramAtLength (datumParam, len, posParamDir, tol) then length (t, datumParam, tol) is (approximately) equal to len. If posParamDir is set to Adesk::kTrue, then the returned parameter value is greater than datumParam. Otherwise it will be less than datumParam. '''
    ...
    def paramOf (self, pt : PyGe.Point3d, tol : PyGe.Tol=None)-> float :
      '''Returns the parameter value of pnt. This function assumes that pnt lies on the curve and does not verify this. If pnt does not lie on the curve, this function will return unpredictable results. If it is not known whether pnt lies on the curve, the user should not call this function but should instead call AcGeCurve3d::isOn (pnt, param, tol). '''
    ...
    def projClosestPointTo (self, pt : PyGe.Point3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.Point3d :
      '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
    ...
    def projClosestPointsTo (self, pt : PyGe.Curve3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> tuple :
      '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
    ...
    def project (self, projectionPlane : PyGe.Plane, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.Entity3d :
      '''Returns the entity that is the projection of the curve onto the projection plane in the specified direction. The projectDirection vector must not be parallel to the projection plane. The returned entity may not be of the same type as the original curve and may not even be a curve (for instance, a line projects into a point if it is parallel to projectDirection). The returned entity is created with the new and it is the responsibility of the caller to delete it.'''
    ...
    def purgeFitData (self, *args, **kwargs)-> bool :
      '''purgeFitData( (NurbCurve3d)arg1) -> bool :

    C++ signature :
        bool purgeFitData(class PyGeNurbCurve3d {lvalue})'''
    ...
    def reverseParam (self)-> None :
      '''Reverses the parametric direction of the curve. The point set of the curve is unchanged, but the direction of the curve is reversed.'''
    ...
    def rotateBy (self, angle : float, vec : PyGe.Vector3d, pt : PyGe.Point3d = 'origin')-> None :
      '''Rotates the entity by the input angle about the line defined by the input point and vector.'''
    ...
    def scaleBy (self, scaleFactor : float, pt : PyGe.Point3d = 'origin')-> None :
      '''Scales the entity about the input point by the input scale factor. Input scale factor must be greater than 0.'''
    ...
    def setControlPointAt (self, *args, **kwargs)-> None :
      '''setControlPointAt( (SplineEnt3d)arg1, (int)arg2, (Point3d)arg3) -> None :

    C++ signature :
        void setControlPointAt(class PyGeSplineEnt3d {lvalue},int,class AcGePoint3d)'''
    ...
    def setEvalMode (self, *args, **kwargs)-> None :
      '''setEvalMode( (NurbCurve3d)arg1, (bool)arg2) -> None :

    C++ signature :
        void setEvalMode(class PyGeNurbCurve3d {lvalue},bool)'''
    ...
    def setFitData (self, *args, **kwargs)-> None :
      '''setFitData( (NurbCurve3d)arg1, (list)arg2, (Vector3d)arg3, (Vector3d)arg4, (Tol)arg5) -> None :

    C++ signature :
        void setFitData(class PyGeNurbCurve3d {lvalue},class boost::python::list,class AcGeVector3d,class AcGeVector3d,class AcGeTol)

setFitData( (NurbCurve3d)arg1, (list)arg2, (Vector3d)arg3, (Vector3d)arg4, (KnotParameterization)arg5, (Tol)arg6) -> None :

    C++ signature :
        void setFitData(class PyGeNurbCurve3d {lvalue},class boost::python::list,class AcGeVector3d,class AcGeVector3d,enum AcGe::KnotParameterization,class AcGeTol)

setFitData( (NurbCurve3d)arg1, (KnotVector)arg2, (list)arg3, (Vector3d)arg4, (Vector3d)arg5, (Tol)arg6, (bool)arg7) -> None :

    C++ signature :
        void setFitData(class PyGeNurbCurve3d {lvalue},class PyGeKnotVector,class boost::python::list,class AcGeVector3d,class AcGeVector3d,class AcGeTol,bool)

setFitData( (NurbCurve3d)arg1, (int)arg2, (list)arg3, (Tol)arg4) -> None :

    C++ signature :
        void setFitData(class PyGeNurbCurve3d {lvalue},int,class boost::python::list,class AcGeTol)'''
    ...
    def setFitKnotParameterization (self, *args, **kwargs)-> bool :
      '''setFitKnotParameterization( (NurbCurve3d)arg1, (KnotParameterization)arg2) -> bool :

    C++ signature :
        bool setFitKnotParameterization(class PyGeNurbCurve3d {lvalue},enum AcGe::KnotParameterization)'''
    ...
    def setFitPointAt (self, *args, **kwargs)-> bool :
      '''setFitPointAt( (NurbCurve3d)arg1, (int)arg2, (Point3d)arg3) -> bool :

    C++ signature :
        bool setFitPointAt(class PyGeNurbCurve3d {lvalue},int,class AcGePoint3d)'''
    ...
    def setFitTangents (self, *args, **kwargs)-> bool :
      '''setFitTangents( (NurbCurve3d)arg1, (Vector3d)arg2, (Vector3d)arg3) -> bool :

    C++ signature :
        bool setFitTangents(class PyGeNurbCurve3d {lvalue},class AcGeVector3d,class AcGeVector3d)

setFitTangents( (NurbCurve3d)arg1, (Vector3d)arg2, (Vector3d)arg3, (bool)arg4, (bool)arg5) -> bool :

    C++ signature :
        bool setFitTangents(class PyGeNurbCurve3d {lvalue},class AcGeVector3d,class AcGeVector3d,bool,bool)'''
    ...
    def setFitTolerance (self, *args, **kwargs)-> bool :
      '''setFitTolerance( (NurbCurve3d)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool setFitTolerance(class PyGeNurbCurve3d {lvalue},class AcGeTol)'''
    ...
    def setInterval (self, val : PyGe.Interval = None)-> None :
      '''Sets the domain of the curve to the input interval.'''
    ...
    def setKnotAt (self, *args, **kwargs)-> None :
      '''setKnotAt( (SplineEnt3d)arg1, (int)arg2, (float)arg3) -> None :

    C++ signature :
        void setKnotAt(class PyGeSplineEnt3d {lvalue},int,double)'''
    ...
    def setWeightAt (self, *args, **kwargs)-> None :
      '''setWeightAt( (NurbCurve3d)arg1, (int)arg2, (float)arg3) -> None :

    C++ signature :
        void setWeightAt(class PyGeNurbCurve3d {lvalue},int,double)'''
    ...
    def startParam (self, *args, **kwargs)-> float :
      '''startParam( (SplineEnt3d)arg1) -> float :

    C++ signature :
        double startParam(class PyGeSplineEnt3d {lvalue})'''
    ...
    def startPoint (self, *args, **kwargs)-> PyGe.Point3d :
      '''startPoint( (SplineEnt3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d startPoint(class PyGeSplineEnt3d {lvalue})'''
    ...
    def transformBy (self, val : PyGe.Matrix3d)-> None :
      '''Transforms the entity by applying the input matrix.'''
    ...
    def translateBy (self, vec : PyGe.Vector3d)-> None :
      '''Translates the entity by the input vector.'''
    ...
    def type (self)-> PyGe.EntityId :
      '''Returns the type of the entity.'''
    ...
    def weightAt (self, *args, **kwargs)-> float :
      '''weightAt( (NurbCurve3d)arg1, (int)arg2) -> float :

    C++ signature :
        double weightAt(class PyGeNurbCurve3d {lvalue},int)'''
    ...

class NurbSurface(Surface):
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...
    def cast (self, *args, **kwargs)-> PyDb.NurbSurface :
      '''cast( (Entity3d)arg1) -> NurbSurface :

    C++ signature :
        class PyGeNurbSurface cast(class PyGeEntity3d)'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def closestPointTo (self, *args, **kwargs)-> PyGe.Point3d :
      '''closestPointTo( (Surface)arg1, (Point3d)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d closestPointTo(class PyGeSurface {lvalue},class AcGePoint3d)

closestPointTo( (Surface)arg1, (Point3d)arg2, (Tol)arg3) -> Point3d :

    C++ signature :
        class AcGePoint3d closestPointTo(class PyGeSurface {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def copy (self)-> PyGe.Entity3d :
      '''Returns a pointer to a copy of this entity. This copy is created using the new and it is the responsibility of the caller to delete it.'''
    ...
    def copycast (self, *args, **kwargs)-> PyDb.NurbSurface :
      '''copycast( (Entity3d)arg1) -> NurbSurface :

    C++ signature :
        class PyGeNurbSurface copycast(class PyGeEntity3d)'''
    ...
    def distanceTo (self, *args, **kwargs)-> float :
      '''distanceTo( (Surface)arg1, (Point3d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeSurface {lvalue},class AcGePoint3d)

distanceTo( (Surface)arg1, (Point3d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeSurface {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def evalPoint (self, *args, **kwargs)-> PyGe.Point3d :
      '''evalPoint( (Surface)arg1, (Point2d)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d evalPoint(class PyGeSurface {lvalue},class AcGePoint2d)

evalPoint( (Surface)arg1, (Point2d)arg2, (int)arg3, (list)arg4) -> Point3d :

    C++ signature :
        class AcGePoint3d evalPoint(class PyGeSurface {lvalue},class AcGePoint2d,int,class boost::python::list {lvalue})

evalPoint( (Surface)arg1, (Point2d)arg2, (int)arg3, (list)arg4, (Vector3d)arg5) -> Point3d :

    C++ signature :
        class AcGePoint3d evalPoint(class PyGeSurface {lvalue},class AcGePoint2d,int,class boost::python::list {lvalue},class AcGeVector3d {lvalue})'''
    ...
    def isClosedInU (self, *args, **kwargs)-> bool :
      '''isClosedInU( (Surface)arg1) -> bool :

    C++ signature :
        bool isClosedInU(class PyGeSurface {lvalue})

isClosedInU( (Surface)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosedInU(class PyGeSurface {lvalue},class AcGeTol)'''
    ...
    def isClosedInV (self, *args, **kwargs)-> bool :
      '''isClosedInV( (Surface)arg1) -> bool :

    C++ signature :
        bool isClosedInV(class PyGeSurface {lvalue})

isClosedInV( (Surface)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosedInV(class PyGeSurface {lvalue},class AcGeTol)'''
    ...
    def isEqualTo (self, val : PyGe.Entity3d, tol : PyGe.Tol=None)-> bool :
      '''Determines if two entities are equal to each other. Two entities are considered to be equal only if they are of the same type and they represent the same 3D point set. For instance, if the two entities are of types AcGeCircArc3d and AcGeEllipArc3d then they are not considered equal even if the ellipse is completely coincident with the circle. Also, two curves are not considered equal unless they have the same parameterization. For instance, two infinite coincident lines are not considered equal if they have different scaling in their parameterization. '''
    ...
    def isKindOf (self, val : PyGe.EntityId)-> bool :
      '''                             '''
    ...
    def isNormalReversed (self, *args, **kwargs)-> bool :
      '''isNormalReversed( (Surface)arg1) -> bool :

    C++ signature :
        bool isNormalReversed(class PyGeSurface {lvalue})'''
    ...
    def isNull (self)-> bool :
      '''                             '''
    ...
    def isOn (self, *args, **kwargs)-> bool :
      '''isOn( (Surface)arg1, (Point3d)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeSurface {lvalue},class AcGePoint3d)

isOn( (Surface)arg1, (Point3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeSurface {lvalue},class AcGePoint3d,class AcGeTol)

isOn( (Surface)arg1, (Point3d)arg2, (Point2d)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeSurface {lvalue},class AcGePoint3d,class AcGePoint2d {lvalue})

isOn( (Surface)arg1, (Point3d)arg2, (Point2d)arg3, (Tol)arg4) -> bool :

    C++ signature :
        bool isOn(class PyGeSurface {lvalue},class AcGePoint3d,class AcGePoint2d {lvalue},class AcGeTol)'''
    ...
    def mirror (self, val : PyGe.Plane)-> None :
      '''Transforms the entity by mirroring it across the input plane.'''
    ...
    def paramOf (self, *args, **kwargs)-> PyGe.Point2d :
      '''paramOf( (Surface)arg1, (Point3d)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d paramOf(class PyGeSurface {lvalue},class AcGePoint3d)

paramOf( (Surface)arg1, (Point3d)arg2, (Tol)arg3) -> Point2d :

    C++ signature :
        class AcGePoint2d paramOf(class PyGeSurface {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def reverseNormal (self, *args, **kwargs)-> None :
      '''reverseNormal( (Surface)arg1) -> None :

    C++ signature :
        void reverseNormal(class PyGeSurface {lvalue})'''
    ...
    def rotateBy (self, angle : float, vec : PyGe.Vector3d, pt : PyGe.Point3d = 'origin')-> None :
      '''Rotates the entity by the input angle about the line defined by the input point and vector.'''
    ...
    def scaleBy (self, scaleFactor : float, pt : PyGe.Point3d = 'origin')-> None :
      '''Scales the entity about the input point by the input scale factor. Input scale factor must be greater than 0.'''
    ...
    def transformBy (self, val : PyGe.Matrix3d)-> None :
      '''Transforms the entity by applying the input matrix.'''
    ...
    def translateBy (self, vec : PyGe.Vector3d)-> None :
      '''Translates the entity by the input vector.'''
    ...
    def type (self)-> PyGe.EntityId :
      '''Returns the type of the entity.'''
    ...

class OffsetCrvExtType(object):
    def __add__ (self, value, /) :
      '''Return self+value.'''
    ...
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def __mul__ (self, value, /) :
      '''Return self*value.'''
    ...
    def __rmul__ (self, value, /) :
      '''Return value*self.'''
    ...
    def __sub__ (self, value, /) :
      '''Return self-value.'''
    ...
    def __truediv__ (self, value, /) :
      '''Return self/value.'''
    ...
    def kChamfer (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kExtend (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kFillet (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def name (self, *args, **kwargs)-> None :
      '''None'''
    ...

class OffsetCurve2d(Curve2d):
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1, (Curve2d)arg2, (float)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class PyGeCurve2d,double)'''
    ...
    def area (self, startParam : float, endParam : float, tol : float = None)-> float :
      '''                             '''
    ...
    def boundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock2d :
      '''                             '''
    ...
    def cast (self, *args, **kwargs)-> PyGe.OffsetCurve2d :
      '''cast( (Entity2d)arg1) -> OffsetCurve2d :

    C++ signature :
        class PyGeOffsetCurve2d cast(class PyGeEntity2d)'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def closestPointTo (self, other : PyGe.Point2d | PyGe.Curve2d, tol : PyGe.Tol=None)-> PyGe.Point2d :
      '''                             '''
    ...
    def copy (self)-> PyGe.Entity2d :
      '''                             '''
    ...
    def copycast (self, *args, **kwargs)-> PyGe.OffsetCurve2d :
      '''copycast( (Entity2d)arg1) -> OffsetCurve2d :

    C++ signature :
        class PyGeOffsetCurve2d copycast(class PyGeEntity2d)'''
    ...
    def distanceTo (self, pt : PyGe.Point2d | PyGe.Curve2d, tol : PyGe.Tol=None)-> float :
      '''                             '''
    ...
    def evalPoint (self, param : float, numDeriv : int = 1)-> PyGe.Point2d :
      '''                             '''
    ...
    def explode (self, val : PyGe.Interval = None)-> list :
      '''                             '''
    ...
    def getClosestPointTo (self, other : PyGe.Point2d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve2d :
      '''                             '''
    ...
    def getClosestPointsTo (self, other : PyGe.Curve2d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def getEndPoint (self)-> PyGe.Point2d :
      '''                             '''
    ...
    def getInterval (self)-> PyGe.Interval :
      '''                             '''
    ...
    def getNormalPoint (self, pnt : PyGe.Point2d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve2d :
      '''                             '''
    ...

    @overload
    def getSamplePoints (self, numSample: int)-> list : ...
    @overload
    def getSamplePoints (self, fromParam: float, toParam: float, approxEps: float)-> list : ...
    def getSamplePoints (self, *args, **kwargs)-> list :
      '''Overloads:
    - numSample: int
    - fromParam: float, toParam: float, approxEps: float
    '''
    ...
    def getSplitCurves (self, param : float)-> tuple :
      '''                             '''
    ...
    def getStartPoint (self)-> PyGe.Point2d :
      '''                             '''
    ...
    def getTrimmedOffset (self, dist : float, extensionType : PyGe.OffsetCrvExtType, tol : PyGe.Tol=None)-> list :
      '''                             '''
    ...
    def hasEndPoint (self)-> bool :
      '''                             '''
    ...
    def hasStartPoint (self)-> bool :
      '''                             '''
    ...
    def isClosed (self, tol : PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def isDegenerate (self, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isEqualTo (self, val : PyGe.Entity2d, tol : PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def isKindOf (self, val : PyGe.EntityId)-> bool :
      '''                             '''
    ...
    def isLinear (self, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isNull (self)-> bool :
      '''                             '''
    ...
    def isOn (self, pt : float | PyGe.Point2d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isPeriodic (self)-> tuple :
      '''                             '''
    ...
    def length (self, frm : float, to : float, tol : float = None)-> float :
      '''                             '''
    ...
    def mirror (self, val : PyGe.Line2d)-> None :
      '''                             '''
    ...
    def orthoBoundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock2d :
      '''                             '''
    ...
    def paramAtLength (self, datumParam: float, length: float, posParamDir: bool=True, tol: float=None)-> float :
      '''                             '''
    ...
    def paramOf (self, pt : PyGe.Point2d, tol : PyGe.Tol=None)-> float :
      '''                             '''
    ...
    def reverseParam (self)-> None :
      '''                             '''
    ...
    def rotateBy (self, angle : float, pt : PyGe.Point3d=PyGe.Point2d.kOrgin)-> None :
      '''                             '''
    ...
    def scaleBy (self, scaleFactor : float, pt : PyGe.Point2d=PyGe.Point2d.kOrgin)-> None :
      '''                             '''
    ...
    def setInterval (self, val : PyGe.Interval = None)-> None :
      '''                             '''
    ...
    def transformBy (self, val : PyGe.Matrix2d)-> None :
      '''                             '''
    ...
    def translateBy (self, vec : PyGe.Vector2d)-> None :
      '''                             '''
    ...
    def type (self)-> PyGe.EntityId :
      '''                             '''
    ...

class OffsetCurve3d(Curve3d):
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1, (Curve3d)arg2, (Vector3d)arg3, (float)arg4) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class PyGeCurve3d,class AcGeVector3d,double)'''
    ...
    def area (self, startParam : float, endParam : float, tol : float = None)-> float :
      '''Returns the area of the interval of the curve defined by startParam and endParam. Returns Adesk::kTrue if area was successfully computed to within the specified tolerance. If the curve is not planar, then the area cannot be calculated and a value of Adesk::kFalse is returned. If the points at startParam and endParam are the same, then this function returns the area of the closed curve. If the points are different, then this function connects the two points with a line segment and return the signed area between the curve and the line segment. If the line segment does not intersect the curve at any points between startParam and endParam, then the returned area is positive. If the line segment intersects the curves at any points between startParam and endParam, then the returned area is the sum of the sub-areas created by the intersection of the line segment with the curve. Each sub-area has a positive or negative area, depending on whether the curve lies above or below the line segment. The total area returned by this function can therefore be positive, negative, or 0. '''
    ...
    def boundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock3d :
      '''Returns the bounding box of the curve. The sides of the returned box are parallel to the coordinate axes. '''
    ...
    def cast (self, *args, **kwargs)-> PyGe.OffsetCurve3d :
      '''cast( (Entity3d)arg1) -> OffsetCurve3d :

    C++ signature :
        class PyGeOffsetCurve3d cast(class PyGeEntity3d)'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def closestPointTo (self, other : PyGe.Point3d | PyGe.Curve3d, tol : PyGe.Tol=None)-> PyGe.Point3d :
      '''Finds the closest point on this curve to the input point. This function is the same as closestPointTo(), except that the closest point is returned as an AcGePointOnCurve3d object.'''
    ...
    def copy (self)-> PyGe.Entity3d :
      '''Returns a pointer to a copy of this entity. This copy is created using the new and it is the responsibility of the caller to delete it.'''
    ...
    def copycast (self, *args, **kwargs)-> PyGe.OffsetCurve3d :
      '''copycast( (Entity3d)arg1) -> OffsetCurve3d :

    C++ signature :
        class PyGeOffsetCurve3d copycast(class PyGeEntity3d)'''
    ...
    def curve (self, *args, **kwargs)-> PyGe.Curve3d :
      '''curve( (OffsetCurve3d)arg1) -> Curve3d :

    C++ signature :
        class PyGeCurve3d curve(class PyGeOffsetCurve3d {lvalue})'''
    ...
    def distanceTo (self, pt : PyGe.Point3d | PyGe.Curve3d, tol : PyGe.Tol=None)-> float :
      '''Returns the distance between the input point and the closest point on this curve.'''
    ...
    def evalPoint (self, param : float, numDeriv : int = 1)-> PyGe.Point3d :
      '''Returns the point on the curve that corresponds to the input parameter value. Also returns the number of derivative vectors that are specified in numDeriv. The numDeriv parameter should not be set larger than 2.'''
    ...
    def explode (self, val : PyGe.Interval = None)-> list :
      '''Explodes the curve into its individual components. If the curve is a composite curve, then explodedCurves contains the list of component curves of the composite. If the curve is a spline, then it is exploded at the points of C1 discontinuity and explodedCurves contains a copy of each continuous sub-curve. This function returns Adesk::kTrue if the curve was exploded (that is, the curve was a composite or a discontinuous spline) and Adesk::kFalse otherwise. The number of entries returned in newExplodedCurves is always the same as the number of entries in explodedCurves. Each flag in newExplodedCurves indicates whether the corresponding curve in explodedCurves was created with the new operator. If the flag is 1, then it is the responsibility of the caller to delete the curve. If the flag is 0, the curve is deleted by gelib and the caller should not attempt to delete it. If no intrvl parameter is supplied, then the interval is taken to be the entire curve. '''
    ...
    def getClosestPointTo (self, other : PyGe.Point3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''Finds the closest point on this curve to the input point. This function is the same as closestPointTo(), except that the closest point is returned as an AcGePointOnCurve3d object.'''
    ...
    def getClosestPointsTo (self, other : PyGe.Curve3d, tol : PyGe.Tol=None)-> tuple :
      '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
    ...
    def getEndPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def getInterval (self)-> PyGe.Interval :
      '''Returns the parametric range of the curve. The function evalPoint(double) always returns a point on this curve when called with a value within the returned interval.'''
    ...
    def getNormalPoint (self, pnt : PyGe.Point3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''Finds the point on the input curve whose normal passes through the input point. The returned point lies on a plane that also contains the input point and is perpendicular to the curve tangent at that point. The returned point is therefore at a local minimum or a local maximum from the input point. The curve does not need to be planar. If the curve is planar, the input point does not need to lie in the plane of the curve. On input, the second parameter is assumed to contain the parameter value of an initial guess. If there is more than one normal point on the curve, the returned point will be the one whose parameter value is closest to the input parameter value.'''
    ...
    def getProjClosestPointTo (self, pt : PyGe.Point3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
    ...
    def getProjClosestPointsTo (self, pt : PyGe.Curve3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> tuple :
      '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
    ...

    @overload
    def getSamplePoints (self, numSample: int)-> tuple : ...
    @overload
    def getSamplePoints (self, fromParam: float, toParam: float, approxEps: float)-> tuple : ...
    def getSamplePoints (self, *args, **kwargs)-> tuple :
      '''Overloads:
    - numSample: int
    - fromParam: float, toParam: float, approxEps: float
    
	-Returns the specified number of points on the curve. The points are equally spaced by parameter value. So if the interval of the curve [0,1] and numSample is 5, the parameter values of the returned points are 0, 0.25, 0.5, 0.75, and 1.-'''
    ...
    def getSplitCurves (self, param : float)-> tuple :
      '''Returns two segments which are obtained by splitting the curve at the input parameter value. If the specified parameter value does not lie within the parametric interval of the curve or if it corresponds to the start point or endpoint of the curve, then piece1 and piece2 are set to null. This function uses the new to create the curve segments whose addresses are returned in piece1 and piece2. It is the responsibility of the caller to delete these objects. '''
    ...
    def getStartPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def getTrimmedOffset (self, dist : float, planeNormal : PyGe.Vector3d, extensionType : PyGe.OffsetCrvExtType, tol : PyGe.Tol=None)-> list :
      '''Returns one or more offset curves that represent the trimmed offset of the curve. The curve must be planar and planeNormal must be perpendicular to the plane of the curve. The positive direction of offset at a point on the curve is taken to be the cross product of planeNormal with the tangent vector at that point. The curve may be offset in either of two directions by specifying a positive or negative offset distance; planeNormal determines which direction is the positive direction of offset. The returned offset curves are trimmed so that they do not contain any points of self-intersection. Each curve that is returned in offsetCurveList is created with the new and it is the responsibility of the caller to delete these curves. Each curve that is returned in offsetCurveList is a connected curve and may be a composite curve if the offset curve had to be trimmed to remove self-intersecting loops. offsetCurveList only contains more than one curve if the offset operation produces multiple curves which are not connected. If the original curve contains points of C1 discontinuity and the direction of offset causes the offset curve to be disjoint (for instance, if the original curve is a composite curve that is a rectangle and the direction of offset is to the outside of the rectangle), then the offset curve is closed with an arc or a line segment, or the curves are simply extended depending on the value of extensionType.'''
    ...
    def hasEndPoint (self)-> bool :
      '''Returns Adesk::kTrue if curve has an endpoint. A return value of Adesk::kFalse means that the parametric interval of the curve does not have an upper bound. The endPnt parameter contains meaningful data only if this function returns a value of Adesk::kTrue.'''
    ...
    def hasStartPoint (self)-> bool :
      '''Returns Adesk::kTrue if curve has a start point. A return value of Adesk::kFalse means that the parametric interval of the curve does not have a lower bound. The startPnt parameter contains meaningful data only if this function returns a value of Adesk::kTrue.'''
    ...
    def isClosed (self, tol : PyGe.Tol=None)-> bool :
      '''Determines if start point and endpoint of curve are the same.'''
    ...
    def isCoplanarWith (self, curve : PyGe.Curve3d, tol : PyGe.Tol=None)-> tuple :
      '''Returns Adesk::kTrue if both curve are planar and lie in the same plane. The plane parameter is only valid if this function returns a value of Adesk::kTrue.'''
    ...
    def isDegenerate (self, tol : PyGe.Tol=None)-> tuple :
      '''Determines if the curve is degenerate and if so returns the type of entity which the curve degenerates into. For example, if the curve is a circle with a radius of 0 then degenerateType is set to AcGe::kPoint3d. If the curve is an ellipse with a minor radius of 0 and a major radius of 1, then degenerateType is set to AcGe::kLineSeg3d. The degenerateType parameter is only set to something meaningful when this function returns a value of Adesk::kTrue.'''
    ...
    def isEqualTo (self, val : PyGe.Entity3d, tol : PyGe.Tol=None)-> bool :
      '''Determines if two entities are equal to each other. Two entities are considered to be equal only if they are of the same type and they represent the same 3D point set. For instance, if the two entities are of types AcGeCircArc3d and AcGeEllipArc3d then they are not considered equal even if the ellipse is completely coincident with the circle. Also, two curves are not considered equal unless they have the same parameterization. For instance, two infinite coincident lines are not considered equal if they have different scaling in their parameterization. '''
    ...
    def isKindOf (self, val : PyGe.EntityId)-> bool :
      '''                             '''
    ...
    def isLinear (self, tol : PyGe.Tol=None)-> tuple :
      '''Determines if curve is linear. This function returns an infinite line even if the curve is not infinite. The line parameter contains meaningful data only if this function returns a value of Adesk::kTrue.'''
    ...
    def isNull (self)-> bool :
      '''                             '''
    ...
    def isOn (self, pt : float | PyGe.Point3d, tol : PyGe.Tol=None)-> tuple :
      '''Determines if input parameter value is within valid parametric range of curve.'''
    ...
    def isPeriodic (self)-> tuple :
      '''Determines if the curve is periodic. The curve is periodic if and only if it is closed and the two points evalPoint(t) and evalPoint(t+period) are always the same point for all values of t.'''
    ...
    def isPlanar (self, tol : PyGe.Tol=None)-> tuple :
      '''Determines if curve is planar. If the curve is a line, then this function returns an arbitrary plane that contains the line. The plane parameter contains meaningful data only if this function returns a value of Adesk::kTrue. '''
    ...
    def length (self, frm : float, to : float, tol : float = None)-> float :
      '''Returns the arc length of the curve between the two parameter values.'''
    ...
    def mirror (self, val : PyGe.Plane)-> None :
      '''Transforms the entity by mirroring it across the input plane.'''
    ...
    def normal (self, *args, **kwargs)-> PyGe.Vector3d :
      '''normal( (OffsetCurve3d)arg1) -> Vector3d :

    C++ signature :
        class AcGeVector3d normal(class PyGeOffsetCurve3d {lvalue})'''
    ...
    def offsetDistance (self, *args, **kwargs)-> float :
      '''offsetDistance( (OffsetCurve3d)arg1) -> float :

    C++ signature :
        double offsetDistance(class PyGeOffsetCurve3d {lvalue})'''
    ...
    def orthoBoundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock3d :
      '''Returns the bounding box of the curve. The sides of the returned box are parallel to the coordinate axes.'''
    ...
    def orthoProject (self, projectionPlane : PyGe.Plane, tol : PyGe.Tol=None)-> PyGe.Entity3d :
      '''Returns the entity that is the orthogonal projection of the curve onto the projection plane. The returned entity may not be of the same type as the original curve and may not even be a curve (for instance, a line projects into a point if it is orthogonal to the projection plane). The returned entity is created with the new and it is the responsibility of the caller to delete it.'''
    ...
    def paramAtLength (self, datumParam : float, length : float, posParamDir : bool=True, tol : float = default)-> float :
      '''Returns the parameter value of the point whose arc length distance (from the point with parameter value datumParam) is the input length. In other words, ift = paramAtLength (datumParam, len, posParamDir, tol) then length (t, datumParam, tol) is (approximately) equal to len. If posParamDir is set to Adesk::kTrue, then the returned parameter value is greater than datumParam. Otherwise it will be less than datumParam. '''
    ...
    def paramDirection (self, *args, **kwargs)-> bool :
      '''paramDirection( (OffsetCurve3d)arg1) -> bool :

    C++ signature :
        bool paramDirection(class PyGeOffsetCurve3d {lvalue})'''
    ...
    def paramOf (self, pt : PyGe.Point3d, tol : PyGe.Tol=None)-> float :
      '''Returns the parameter value of pnt. This function assumes that pnt lies on the curve and does not verify this. If pnt does not lie on the curve, this function will return unpredictable results. If it is not known whether pnt lies on the curve, the user should not call this function but should instead call AcGeCurve3d::isOn (pnt, param, tol). '''
    ...
    def projClosestPointTo (self, pt : PyGe.Point3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.Point3d :
      '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
    ...
    def projClosestPointsTo (self, pt : PyGe.Curve3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> tuple :
      '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
    ...
    def project (self, projectionPlane : PyGe.Plane, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.Entity3d :
      '''Returns the entity that is the projection of the curve onto the projection plane in the specified direction. The projectDirection vector must not be parallel to the projection plane. The returned entity may not be of the same type as the original curve and may not even be a curve (for instance, a line projects into a point if it is parallel to projectDirection). The returned entity is created with the new and it is the responsibility of the caller to delete it.'''
    ...
    def reverseParam (self)-> None :
      '''Reverses the parametric direction of the curve. The point set of the curve is unchanged, but the direction of the curve is reversed.'''
    ...
    def rotateBy (self, angle : float, vec : PyGe.Vector3d, pt : PyGe.Point3d = 'origin')-> None :
      '''Rotates the entity by the input angle about the line defined by the input point and vector.'''
    ...
    def scaleBy (self, scaleFactor : float, pt : PyGe.Point3d = 'origin')-> None :
      '''Scales the entity about the input point by the input scale factor. Input scale factor must be greater than 0.'''
    ...
    def setCurve (self, *args, **kwargs)-> None :
      '''setCurve( (OffsetCurve3d)arg1, (Curve3d)arg2) -> None :

    C++ signature :
        void setCurve(class PyGeOffsetCurve3d {lvalue},class PyGeCurve3d)'''
    ...
    def setInterval (self, val : PyGe.Interval = None)-> None :
      '''Sets the domain of the curve to the input interval.'''
    ...
    def setNormal (self, *args, **kwargs)-> None :
      '''setNormal( (OffsetCurve3d)arg1, (Vector3d)arg2) -> None :

    C++ signature :
        void setNormal(class PyGeOffsetCurve3d {lvalue},class AcGeVector3d)'''
    ...
    def setOffsetDistance (self, *args, **kwargs)-> None :
      '''setOffsetDistance( (OffsetCurve3d)arg1, (float)arg2) -> None :

    C++ signature :
        void setOffsetDistance(class PyGeOffsetCurve3d {lvalue},double)'''
    ...
    def transformBy (self, val : PyGe.Matrix3d)-> None :
      '''Transforms the entity by applying the input matrix.'''
    ...
    def transformation (self, *args, **kwargs)-> PyGe.Matrix3d :
      '''transformation( (OffsetCurve3d)arg1) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d transformation(class PyGeOffsetCurve3d {lvalue})'''
    ...
    def translateBy (self, vec : PyGe.Vector3d)-> None :
      '''Translates the entity by the input vector.'''
    ...
    def type (self)-> PyGe.EntityId :
      '''Returns the type of the entity.'''
    ...

class OffsetSurface(Surface):
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...
    def cast (self, *args, **kwargs)-> PyGe.OffsetSurface :
      '''cast( (Entity3d)arg1) -> OffsetSurface :

    C++ signature :
        class PyGeOffsetSurface cast(class PyGeEntity3d)'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def closestPointTo (self, *args, **kwargs)-> PyGe.Point3d :
      '''closestPointTo( (Surface)arg1, (Point3d)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d closestPointTo(class PyGeSurface {lvalue},class AcGePoint3d)

closestPointTo( (Surface)arg1, (Point3d)arg2, (Tol)arg3) -> Point3d :

    C++ signature :
        class AcGePoint3d closestPointTo(class PyGeSurface {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def copy (self)-> PyGe.Entity3d :
      '''Returns a pointer to a copy of this entity. This copy is created using the new and it is the responsibility of the caller to delete it.'''
    ...
    def copycast (self, *args, **kwargs)-> PyGe.OffsetSurface :
      '''copycast( (Entity3d)arg1) -> OffsetSurface :

    C++ signature :
        class PyGeOffsetSurface copycast(class PyGeEntity3d)'''
    ...
    def distanceTo (self, *args, **kwargs)-> float :
      '''distanceTo( (Surface)arg1, (Point3d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeSurface {lvalue},class AcGePoint3d)

distanceTo( (Surface)arg1, (Point3d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeSurface {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def evalPoint (self, *args, **kwargs)-> PyGe.Point3d :
      '''evalPoint( (Surface)arg1, (Point2d)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d evalPoint(class PyGeSurface {lvalue},class AcGePoint2d)

evalPoint( (Surface)arg1, (Point2d)arg2, (int)arg3, (list)arg4) -> Point3d :

    C++ signature :
        class AcGePoint3d evalPoint(class PyGeSurface {lvalue},class AcGePoint2d,int,class boost::python::list {lvalue})

evalPoint( (Surface)arg1, (Point2d)arg2, (int)arg3, (list)arg4, (Vector3d)arg5) -> Point3d :

    C++ signature :
        class AcGePoint3d evalPoint(class PyGeSurface {lvalue},class AcGePoint2d,int,class boost::python::list {lvalue},class AcGeVector3d {lvalue})'''
    ...
    def isClosedInU (self, *args, **kwargs)-> bool :
      '''isClosedInU( (Surface)arg1) -> bool :

    C++ signature :
        bool isClosedInU(class PyGeSurface {lvalue})

isClosedInU( (Surface)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosedInU(class PyGeSurface {lvalue},class AcGeTol)'''
    ...
    def isClosedInV (self, *args, **kwargs)-> bool :
      '''isClosedInV( (Surface)arg1) -> bool :

    C++ signature :
        bool isClosedInV(class PyGeSurface {lvalue})

isClosedInV( (Surface)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosedInV(class PyGeSurface {lvalue},class AcGeTol)'''
    ...
    def isEqualTo (self, val : PyGe.Entity3d, tol : PyGe.Tol=None)-> bool :
      '''Determines if two entities are equal to each other. Two entities are considered to be equal only if they are of the same type and they represent the same 3D point set. For instance, if the two entities are of types AcGeCircArc3d and AcGeEllipArc3d then they are not considered equal even if the ellipse is completely coincident with the circle. Also, two curves are not considered equal unless they have the same parameterization. For instance, two infinite coincident lines are not considered equal if they have different scaling in their parameterization. '''
    ...
    def isKindOf (self, val : PyGe.EntityId)-> bool :
      '''                             '''
    ...
    def isNormalReversed (self, *args, **kwargs)-> bool :
      '''isNormalReversed( (Surface)arg1) -> bool :

    C++ signature :
        bool isNormalReversed(class PyGeSurface {lvalue})'''
    ...
    def isNull (self)-> bool :
      '''                             '''
    ...
    def isOn (self, *args, **kwargs)-> bool :
      '''isOn( (Surface)arg1, (Point3d)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeSurface {lvalue},class AcGePoint3d)

isOn( (Surface)arg1, (Point3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeSurface {lvalue},class AcGePoint3d,class AcGeTol)

isOn( (Surface)arg1, (Point3d)arg2, (Point2d)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeSurface {lvalue},class AcGePoint3d,class AcGePoint2d {lvalue})

isOn( (Surface)arg1, (Point3d)arg2, (Point2d)arg3, (Tol)arg4) -> bool :

    C++ signature :
        bool isOn(class PyGeSurface {lvalue},class AcGePoint3d,class AcGePoint2d {lvalue},class AcGeTol)'''
    ...
    def mirror (self, val : PyGe.Plane)-> None :
      '''Transforms the entity by mirroring it across the input plane.'''
    ...
    def paramOf (self, *args, **kwargs)-> PyGe.Point2d :
      '''paramOf( (Surface)arg1, (Point3d)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d paramOf(class PyGeSurface {lvalue},class AcGePoint3d)

paramOf( (Surface)arg1, (Point3d)arg2, (Tol)arg3) -> Point2d :

    C++ signature :
        class AcGePoint2d paramOf(class PyGeSurface {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def reverseNormal (self, *args, **kwargs)-> None :
      '''reverseNormal( (Surface)arg1) -> None :

    C++ signature :
        void reverseNormal(class PyGeSurface {lvalue})'''
    ...
    def rotateBy (self, angle : float, vec : PyGe.Vector3d, pt : PyGe.Point3d = 'origin')-> None :
      '''Rotates the entity by the input angle about the line defined by the input point and vector.'''
    ...
    def scaleBy (self, scaleFactor : float, pt : PyGe.Point3d = 'origin')-> None :
      '''Scales the entity about the input point by the input scale factor. Input scale factor must be greater than 0.'''
    ...
    def transformBy (self, val : PyGe.Matrix3d)-> None :
      '''Transforms the entity by applying the input matrix.'''
    ...
    def translateBy (self, vec : PyGe.Vector3d)-> None :
      '''Translates the entity by the input vector.'''
    ...
    def type (self)-> PyGe.EntityId :
      '''Returns the type of the entity.'''
    ...

class PlanarEnt(Surface):
    def __init__ (self, *args, **kwargs)-> None :
      '''Raises an exception
This class cannot be instantiated from Python'''
    ...

    @staticmethod
    def cast (otherObject: PyGe.Entity3d)-> PyGe.PlanarEnt :
      '''                             '''
    ...

    @staticmethod
    def className ()-> str :
      '''                             '''
    ...
    def closestPointTo (self, *args, **kwargs)-> PyGe.Point3d :
      '''closestPointTo( (Surface)arg1, (Point3d)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d closestPointTo(class PyGeSurface {lvalue},class AcGePoint3d)

closestPointTo( (Surface)arg1, (Point3d)arg2, (Tol)arg3) -> Point3d :

    C++ signature :
        class AcGePoint3d closestPointTo(class PyGeSurface {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def closestPointToLinearEnt (self, *args, **kwargs)-> tuple :
      '''closestPointToLinearEnt( (PlanarEnt)arg1, (LinearEnt3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointToLinearEnt(class PyGePlanarEnt {lvalue},class PyGeLinearEnt3d)

closestPointToLinearEnt( (PlanarEnt)arg1, (LinearEnt3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointToLinearEnt(class PyGePlanarEnt {lvalue},class PyGeLinearEnt3d,class AcGeTol)'''
    ...
    def closestPointToPlanarEnt (self, other: PyGe.LinearEnt3d|PyGe.PlanarEnt, tol: PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def copy (self)-> PyGe.Entity3d :
      '''Returns a pointer to a copy of this entity. This copy is created using the new and it is the responsibility of the caller to delete it.'''
    ...

    @staticmethod
    def copycast (otherObject: PyGe.Entity3d)-> PyGe.PlanarEnt :
      '''                             '''
    ...
    def distanceTo (self, *args, **kwargs)-> float :
      '''distanceTo( (Surface)arg1, (Point3d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeSurface {lvalue},class AcGePoint3d)

distanceTo( (Surface)arg1, (Point3d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeSurface {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def evalPoint (self, *args, **kwargs)-> PyGe.Point3d :
      '''evalPoint( (Surface)arg1, (Point2d)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d evalPoint(class PyGeSurface {lvalue},class AcGePoint2d)

evalPoint( (Surface)arg1, (Point2d)arg2, (int)arg3, (list)arg4) -> Point3d :

    C++ signature :
        class AcGePoint3d evalPoint(class PyGeSurface {lvalue},class AcGePoint2d,int,class boost::python::list {lvalue})

evalPoint( (Surface)arg1, (Point2d)arg2, (int)arg3, (list)arg4, (Vector3d)arg5) -> Point3d :

    C++ signature :
        class AcGePoint3d evalPoint(class PyGeSurface {lvalue},class AcGePoint2d,int,class boost::python::list {lvalue},class AcGeVector3d {lvalue})'''
    ...
    def getCoefficients (self)-> tuple :
      '''                             '''
    ...
    def getCoordSystem (self)-> tuple :
      '''                             '''
    ...
    def intersectWith (self, other: PyGe.LinearEnt3d, tol: PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isClosedInU (self, *args, **kwargs)-> bool :
      '''isClosedInU( (Surface)arg1) -> bool :

    C++ signature :
        bool isClosedInU(class PyGeSurface {lvalue})

isClosedInU( (Surface)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosedInU(class PyGeSurface {lvalue},class AcGeTol)'''
    ...
    def isClosedInV (self, *args, **kwargs)-> bool :
      '''isClosedInV( (Surface)arg1) -> bool :

    C++ signature :
        bool isClosedInV(class PyGeSurface {lvalue})

isClosedInV( (Surface)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosedInV(class PyGeSurface {lvalue},class AcGeTol)'''
    ...
    def isCoplanarTo (self, other: PyGe.PlanarEnt, tol: PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def isEqualTo (self, val : PyGe.Entity3d, tol : PyGe.Tol=None)-> bool :
      '''Determines if two entities are equal to each other. Two entities are considered to be equal only if they are of the same type and they represent the same 3D point set. For instance, if the two entities are of types AcGeCircArc3d and AcGeEllipArc3d then they are not considered equal even if the ellipse is completely coincident with the circle. Also, two curves are not considered equal unless they have the same parameterization. For instance, two infinite coincident lines are not considered equal if they have different scaling in their parameterization. '''
    ...
    def isKindOf (self, val : PyGe.EntityId)-> bool :
      '''                             '''
    ...
    def isNormalReversed (self, *args, **kwargs)-> bool :
      '''isNormalReversed( (Surface)arg1) -> bool :

    C++ signature :
        bool isNormalReversed(class PyGeSurface {lvalue})'''
    ...
    def isNull (self)-> bool :
      '''                             '''
    ...
    def isOn (self, *args, **kwargs)-> bool :
      '''isOn( (Surface)arg1, (Point3d)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeSurface {lvalue},class AcGePoint3d)

isOn( (Surface)arg1, (Point3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeSurface {lvalue},class AcGePoint3d,class AcGeTol)

isOn( (Surface)arg1, (Point3d)arg2, (Point2d)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeSurface {lvalue},class AcGePoint3d,class AcGePoint2d {lvalue})

isOn( (Surface)arg1, (Point3d)arg2, (Point2d)arg3, (Tol)arg4) -> bool :

    C++ signature :
        bool isOn(class PyGeSurface {lvalue},class AcGePoint3d,class AcGePoint2d {lvalue},class AcGeTol)'''
    ...
    def isParallelTo (self, other: PyGe.LinearEnt3d|PyGe.PlanarEnt, tol: PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def isPerpendicularTo (self, other: PyGe.LinearEnt3d|PyGe.PlanarEnt, tol: PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def mirror (self, val : PyGe.Plane)-> None :
      '''Transforms the entity by mirroring it across the input plane.'''
    ...
    def normal (self)-> PyGe.Vector3d :
      '''                             '''
    ...
    def paramOf (self, *args, **kwargs)-> PyGe.Point2d :
      '''paramOf( (Surface)arg1, (Point3d)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d paramOf(class PyGeSurface {lvalue},class AcGePoint3d)

paramOf( (Surface)arg1, (Point3d)arg2, (Tol)arg3) -> Point2d :

    C++ signature :
        class AcGePoint2d paramOf(class PyGeSurface {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def pointOnPlane (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def reverseNormal (self, *args, **kwargs)-> None :
      '''reverseNormal( (Surface)arg1) -> None :

    C++ signature :
        void reverseNormal(class PyGeSurface {lvalue})'''
    ...
    def rotateBy (self, angle : float, vec : PyGe.Vector3d, pt : PyGe.Point3d = 'origin')-> None :
      '''Rotates the entity by the input angle about the line defined by the input point and vector.'''
    ...
    def scaleBy (self, scaleFactor : float, pt : PyGe.Point3d = 'origin')-> None :
      '''Scales the entity about the input point by the input scale factor. Input scale factor must be greater than 0.'''
    ...
    def transformBy (self, val : PyGe.Matrix3d)-> None :
      '''Transforms the entity by applying the input matrix.'''
    ...
    def translateBy (self, vec : PyGe.Vector3d)-> None :
      '''Translates the entity by the input vector.'''
    ...
    def type (self)-> PyGe.EntityId :
      '''Returns the type of the entity.'''
    ...

class Plane(PlanarEnt):
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (Point3d)arg2, (Vector3d)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePoint3d,class AcGeVector3d)

__init__( (object)arg1, (Point3d)arg2, (Vector3d)arg3, (Vector3d)arg4) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePoint3d,class AcGeVector3d,class AcGeVector3d)

__init__( (object)arg1, (Point3d)arg2, (Point3d)arg3, (Point3d)arg4) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePoint3d,class AcGePoint3d,class AcGePoint3d)

__init__( (object)arg1, (float)arg2, (float)arg3, (float)arg4, (float)arg5) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,double,double,double,double)'''
    ...
    def cast (self, *args, **kwargs)-> PyGe.Plane :
      '''cast( (Entity3d)arg1) -> Plane :

    C++ signature :
        class PyGePlane cast(class PyGeEntity3d)'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def closestPointTo (self, *args, **kwargs)-> PyGe.Point3d :
      '''closestPointTo( (Surface)arg1, (Point3d)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d closestPointTo(class PyGeSurface {lvalue},class AcGePoint3d)

closestPointTo( (Surface)arg1, (Point3d)arg2, (Tol)arg3) -> Point3d :

    C++ signature :
        class AcGePoint3d closestPointTo(class PyGeSurface {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def closestPointToLinearEnt (self, *args, **kwargs)-> tuple :
      '''closestPointToLinearEnt( (PlanarEnt)arg1, (LinearEnt3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointToLinearEnt(class PyGePlanarEnt {lvalue},class PyGeLinearEnt3d)

closestPointToLinearEnt( (PlanarEnt)arg1, (LinearEnt3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointToLinearEnt(class PyGePlanarEnt {lvalue},class PyGeLinearEnt3d,class AcGeTol)'''
    ...
    def closestPointToPlanarEnt (self, other: PyGe.LinearEnt3d|PyGe.PlanarEnt, tol: PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def copy (self)-> PyGe.Entity3d :
      '''Returns a pointer to a copy of this entity. This copy is created using the new and it is the responsibility of the caller to delete it.'''
    ...
    def copycast (self, *args, **kwargs)-> PyGe.Plane :
      '''copycast( (Entity3d)arg1) -> Plane :

    C++ signature :
        class PyGePlane copycast(class PyGeEntity3d)'''
    ...
    def distanceTo (self, *args, **kwargs)-> float :
      '''distanceTo( (Surface)arg1, (Point3d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeSurface {lvalue},class AcGePoint3d)

distanceTo( (Surface)arg1, (Point3d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeSurface {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def evalPoint (self, *args, **kwargs)-> PyGe.Point3d :
      '''evalPoint( (Surface)arg1, (Point2d)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d evalPoint(class PyGeSurface {lvalue},class AcGePoint2d)

evalPoint( (Surface)arg1, (Point2d)arg2, (int)arg3, (list)arg4) -> Point3d :

    C++ signature :
        class AcGePoint3d evalPoint(class PyGeSurface {lvalue},class AcGePoint2d,int,class boost::python::list {lvalue})

evalPoint( (Surface)arg1, (Point2d)arg2, (int)arg3, (list)arg4, (Vector3d)arg5) -> Point3d :

    C++ signature :
        class AcGePoint3d evalPoint(class PyGeSurface {lvalue},class AcGePoint2d,int,class boost::python::list {lvalue},class AcGeVector3d {lvalue})'''
    ...
    def getCoefficients (self)-> tuple :
      '''                             '''
    ...
    def getCoordSystem (self)-> tuple :
      '''                             '''
    ...
    def intersectWith (self, *args, **kwargs)-> tuple :
      '''intersectWith( (Plane)arg1, (LinearEnt3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGePlane {lvalue},class PyGeLinearEnt3d)

intersectWith( (Plane)arg1, (LinearEnt3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGePlane {lvalue},class PyGeLinearEnt3d,class AcGeTol)

intersectWith( (Plane)arg1, (Plane)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGePlane {lvalue},class PyGePlane)

intersectWith( (Plane)arg1, (Plane)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGePlane {lvalue},class PyGePlane,class AcGeTol)

intersectWith( (Plane)arg1, (BoundedPlane)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGePlane {lvalue},class PyGeBoundedPlane)

intersectWith( (Plane)arg1, (BoundedPlane)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGePlane {lvalue},class PyGeBoundedPlane,class AcGeTol)'''
    ...
    def isClosedInU (self, *args, **kwargs)-> bool :
      '''isClosedInU( (Surface)arg1) -> bool :

    C++ signature :
        bool isClosedInU(class PyGeSurface {lvalue})

isClosedInU( (Surface)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosedInU(class PyGeSurface {lvalue},class AcGeTol)'''
    ...
    def isClosedInV (self, *args, **kwargs)-> bool :
      '''isClosedInV( (Surface)arg1) -> bool :

    C++ signature :
        bool isClosedInV(class PyGeSurface {lvalue})

isClosedInV( (Surface)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosedInV(class PyGeSurface {lvalue},class AcGeTol)'''
    ...
    def isCoplanarTo (self, other: PyGe.PlanarEnt, tol: PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def isEqualTo (self, val : PyGe.Entity3d, tol : PyGe.Tol=None)-> bool :
      '''Determines if two entities are equal to each other. Two entities are considered to be equal only if they are of the same type and they represent the same 3D point set. For instance, if the two entities are of types AcGeCircArc3d and AcGeEllipArc3d then they are not considered equal even if the ellipse is completely coincident with the circle. Also, two curves are not considered equal unless they have the same parameterization. For instance, two infinite coincident lines are not considered equal if they have different scaling in their parameterization. '''
    ...
    def isKindOf (self, val : PyGe.EntityId)-> bool :
      '''                             '''
    ...
    def isNormalReversed (self, *args, **kwargs)-> bool :
      '''isNormalReversed( (Surface)arg1) -> bool :

    C++ signature :
        bool isNormalReversed(class PyGeSurface {lvalue})'''
    ...
    def isNull (self)-> bool :
      '''                             '''
    ...
    def isOn (self, *args, **kwargs)-> bool :
      '''isOn( (Surface)arg1, (Point3d)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeSurface {lvalue},class AcGePoint3d)

isOn( (Surface)arg1, (Point3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeSurface {lvalue},class AcGePoint3d,class AcGeTol)

isOn( (Surface)arg1, (Point3d)arg2, (Point2d)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeSurface {lvalue},class AcGePoint3d,class AcGePoint2d {lvalue})

isOn( (Surface)arg1, (Point3d)arg2, (Point2d)arg3, (Tol)arg4) -> bool :

    C++ signature :
        bool isOn(class PyGeSurface {lvalue},class AcGePoint3d,class AcGePoint2d {lvalue},class AcGeTol)'''
    ...
    def isParallelTo (self, other: PyGe.LinearEnt3d|PyGe.PlanarEnt, tol: PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def isPerpendicularTo (self, other: PyGe.LinearEnt3d|PyGe.PlanarEnt, tol: PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def mirror (self, val : PyGe.Plane)-> None :
      '''Transforms the entity by mirroring it across the input plane.'''
    ...
    def normal (self)-> PyGe.Vector3d :
      '''                             '''
    ...
    def paramOf (self, *args, **kwargs)-> PyGe.Point2d :
      '''paramOf( (Surface)arg1, (Point3d)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d paramOf(class PyGeSurface {lvalue},class AcGePoint3d)

paramOf( (Surface)arg1, (Point3d)arg2, (Tol)arg3) -> Point2d :

    C++ signature :
        class AcGePoint2d paramOf(class PyGeSurface {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def pointOnPlane (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def reverseNormal (self, *args, **kwargs)-> None :
      '''reverseNormal( (Surface)arg1) -> None :

    C++ signature :
        void reverseNormal(class PyGeSurface {lvalue})'''
    ...
    def rotateBy (self, angle : float, vec : PyGe.Vector3d, pt : PyGe.Point3d = 'origin')-> None :
      '''Rotates the entity by the input angle about the line defined by the input point and vector.'''
    ...
    def scaleBy (self, scaleFactor : float, pt : PyGe.Point3d = 'origin')-> None :
      '''Scales the entity about the input point by the input scale factor. Input scale factor must be greater than 0.'''
    ...
    def set (self, *args, **kwargs)-> None :
      '''set( (Plane)arg1, (Point3d)arg2, (Vector3d)arg3) -> None :

    C++ signature :
        void set(class PyGePlane {lvalue},class AcGePoint3d,class AcGeVector3d)

set( (Plane)arg1, (Point3d)arg2, (Point3d)arg3, (Point3d)arg4) -> None :

    C++ signature :
        void set(class PyGePlane {lvalue},class AcGePoint3d,class AcGePoint3d,class AcGePoint3d)

set( (Plane)arg1, (float)arg2, (float)arg3, (float)arg4, (float)arg5) -> None :

    C++ signature :
        void set(class PyGePlane {lvalue},double,double,double,double)

set( (Plane)arg1, (Point3d)arg2, (Vector3d)arg3, (Vector3d)arg4) -> None :

    C++ signature :
        void set(class PyGePlane {lvalue},class AcGePoint3d,class AcGeVector3d,class AcGeVector3d)'''
    ...
    def signedDistanceTo (self, *args, **kwargs)-> float :
      '''signedDistanceTo( (Plane)arg1, (Point3d)arg2) -> float :

    C++ signature :
        double signedDistanceTo(class PyGePlane {lvalue},class AcGePoint3d)'''
    ...
    def transformBy (self, val : PyGe.Matrix3d)-> None :
      '''Transforms the entity by applying the input matrix.'''
    ...
    def translateBy (self, vec : PyGe.Vector3d)-> None :
      '''Translates the entity by the input vector.'''
    ...
    def type (self)-> PyGe.EntityId :
      '''Returns the type of the entity.'''
    ...

class Point2d(object):
    def __add__ (self, *args, **kwargs)-> PyGe.Point2d :
      '''__add__( (Point2d)arg1, (Vector2d)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d __add__(class AcGePoint2d {lvalue},class AcGeVector2d)'''
    ...
    def __getitem__ (self, *args, **kwargs)-> float :
      '''__getitem__( (Point2d)arg1, (int)arg2) -> float :

    C++ signature :
        double __getitem__(class AcGePoint2d,int)'''
    ...
    def __imul__ (self, *args, **kwargs)-> PyGe.Point2d :
      '''__imul__( (Point2d)arg1, (float)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d {lvalue} __imul__(class AcGePoint2d {lvalue},double)'''
    ...

    @overload
    def __init__ (self, /)-> None : ...
    @overload
    def __init__ (self, x: float, y: float)-> None : ...
    def __init__ (self, *args, **kwargs)-> None :
      '''Overloads:
    - None: Any
    - x: float, y: float
    '''
    ...
    def __isub__ (self, *args, **kwargs)-> PyGe.Point2d :
      '''__isub__( (Point2d)arg1, (Vector2d)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d {lvalue} __isub__(class AcGePoint2d {lvalue},class AcGeVector2d)'''
    ...
    def __itruediv__ (self, *args, **kwargs)-> PyGe.Point2d :
      '''__itruediv__( (Point2d)arg1, (float)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d {lvalue} __itruediv__(class AcGePoint2d {lvalue},double)'''
    ...
    def __mul__ (self, *args, **kwargs)-> PyGe.Point2d :
      '''__mul__( (Point2d)arg1, (float)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d __mul__(class AcGePoint2d {lvalue},double)'''
    ...
    def __setitem__ (self, *args, **kwargs)-> None :
      '''__setitem__( (Point2d)arg1, (int)arg2, (float)arg3) -> None :

    C++ signature :
        void __setitem__(class AcGePoint2d {lvalue},int,double)'''
    ...
    def __sub__ (self, *args, **kwargs)-> PyGe.Point2d :
      '''__sub__( (Point2d)arg1, (Vector2d)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d __sub__(class AcGePoint2d {lvalue},class AcGeVector2d)

__sub__( (Point2d)arg1, (Point2d)arg2) -> Vector2d :

    C++ signature :
        class AcGeVector2d __sub__(class AcGePoint2d {lvalue},class AcGePoint2d)'''
    ...
    def __truediv__ (self, *args, **kwargs)-> PyGe.Point2d :
      '''__truediv__( (Point2d)arg1, (float)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d __truediv__(class AcGePoint2d {lvalue},double)'''
    ...
    def asVector (self)-> PyGe.Vector2d :
      '''                             '''
    ...
    def distanceTo (self, pt: PyGe.Point2d)-> float :
      '''                             '''
    ...
    def isEqualTo (self, pt: PyGe.Point2d, tol: PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def kOrigin (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def mirror (self, *args, **kwargs)-> PyGe.Point2d :
      '''mirror( (Point2d)arg1, (object)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d {lvalue} mirror(class AcGePoint2d {lvalue},class AcGeLine2d)'''
    ...
    def rotateBy (self, *args, **kwargs)-> PyGe.Point2d :
      '''rotateBy( (Point2d)arg1, (float)arg2 [, (Point2d)AcGePoint2d=<PyGe.Point2d(0.00000000000000,0.00000000000000)>]) -> Point2d :

    C++ signature :
        class AcGePoint2d {lvalue} rotateBy(class AcGePoint2d {lvalue},double [,class AcGePoint2d=<PyGe.Point2d(0.00000000000000,0.00000000000000)>])'''
    ...
    def scaleBy (self, *args, **kwargs)-> PyGe.Point2d :
      '''scaleBy( (Point2d)arg1, (float)arg2 [, (Point2d)AcGePoint2d=<PyGe.Point2d(0.00000000000000,0.00000000000000)>]) -> Point2d :

    C++ signature :
        class AcGePoint2d {lvalue} scaleBy(class AcGePoint2d {lvalue},double [,class AcGePoint2d=<PyGe.Point2d(0.00000000000000,0.00000000000000)>])'''
    ...
    def set (self, *args, **kwargs)-> PyGe.Point2d :
      '''set( (Point2d)arg1, (float)arg2, (float)arg3) -> Point2d :

    C++ signature :
        class AcGePoint2d {lvalue} set(class AcGePoint2d {lvalue},double,double)'''
    ...
    def setToProduct (self, *args, **kwargs)-> PyGe.Point2d :
      '''setToProduct( (Point2d)arg1, (Matrix2d)arg2, (Point2d)arg3) -> Point2d :

    C++ signature :
        class AcGePoint2d {lvalue} setToProduct(class AcGePoint2d {lvalue},class AcGeMatrix2d,class AcGePoint2d)'''
    ...
    def setToSum (self, *args, **kwargs)-> PyGe.Point2d :
      '''setToSum( (Point2d)arg1, (Point2d)arg2, (Vector2d)arg3) -> Point2d :

    C++ signature :
        class AcGePoint2d {lvalue} setToSum(class AcGePoint2d {lvalue},class AcGePoint2d,class AcGeVector2d)'''
    ...
    def toList (self)-> list :
      '''                             '''
    ...
    def toString (self)-> str :
      '''                             '''
    ...
    def toTuple (self)-> tuple :
      '''                             '''
    ...
    def transformBy (self, *args, **kwargs)-> PyGe.Point2d :
      '''transformBy( (Point2d)arg1, (Matrix2d)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d {lvalue} transformBy(class AcGePoint2d {lvalue},class AcGeMatrix2d)'''
    ...
    def x (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def y (self, *args, **kwargs)-> None :
      '''None'''
    ...

class Point3d(object):
    def __add__ (self, vec: PyGe.Vector3d)-> PyGe.Point3d :
      '''                             '''
    ...
    def __getitem__ (self, idx: int)-> float :
      '''                             '''
    ...
    def __imul__ (self, val: float)-> PyGe.Point3d :
      '''                             '''
    ...

    @overload
    def __init__ (self, /)-> None : ...
    @overload
    def __init__ (self, floats: tuple[float] | list[float])-> None : ...
    @overload
    def __init__ (self, x: float,y: float,z: float)-> None : ...
    @overload
    def __init__ (self, pln: PyGe.PlanarEnt, pnt2d: PyGe.Point2d)-> None : ...
    def __init__ (self, *args, **kwargs)-> None :
      '''Overloads:
    - None: Any
    - floats: tuple[float] | list[float]
    - x: float,y: float,z: float
    - pln: PyGe.PlanarEnt, pnt2d: PyGe.Point2d
    '''
    ...
    def __isub__ (self, vec: PyGe.Vector3d)-> PyGe.Point3d :
      '''                             '''
    ...
    def __itruediv__ (self, val: float)-> PyGe.Point3d :
      '''                             '''
    ...
    def __mul__ (self, val: float)-> PyGe.Point3d :
      '''                             '''
    ...
    def __rmul__ (self, val: float|PyGe.Matrix3d)-> PyGe.Point3d :
      '''                             '''
    ...
    def __setitem__ (self, idx: int, val: float)-> None :
      '''                             '''
    ...
    def __sub__ (self, val: PyGe.Vector3d | PyGe.Point3d)-> PyGe.Vector3d :
      '''                             '''
    ...
    def __truediv__ (self, val: float)-> PyGe.Point3d :
      '''                             '''
    ...
    def asVector (self)-> PyGe.Vector3d :
      '''Converts 3D point into 3D vector with the same set of coordinates ( see AcGeVector3d ).Return value is a class AcGeVector3d.'''
    ...
    def convert2d (self, pln: PyGe.PlanarEnt)-> PyGe.Point2d :
      '''Returns 2D point with the coordinates corresponding to the decomposition of the vector *this - p in the basis uAxis, vAxis in the planar entity, where p, uAxis, and vAxis can found by function call pln.get(p, uAxis, vAxis).Contract: This 3D point assumed to be on the planar entity pln.'''
    ...
    def distanceTo (self, pnt: PyGe.Point3d)-> float :
      '''Evaluates and returns distance from this point to the point pnt.'''
    ...
    def isEqualTo (self, pnt: PyGe.Point3d, tol: PyGe.Tol=None)-> bool :
      '''Checks if this point is within the distance tol.equalPoint() from the point pnt. The default value of the tolerance class tol is AcGeContext::gTol.Returns Adesk::kTrue if this condition is met and Adesk::kFalse otherwise.'''
    ...
    def kOrigin (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def mirror (self, pln: PyGe.Plane)-> PyGe.Point3d :
      '''Returns the 3D point that is the result of mirroring of this point with respect to the plane pln.'''
    ...
    def orthoProject (self, pln: PyGe.Plane)-> PyGe.Point3d :
      '''Returns 3D point that is the result of the orthogonal projection of this point into the plane pln. '''
    ...
    def project (self, pln: PyGe.Plane, vec:  PyGe.Vector3d)-> PyGe.Point3d :
      '''Returns 3D point that is the result of the parallel projection of this point into the plane pln. The direction of projection is defined by vector vec.'''
    ...
    def rotateBy (self, angle: float, vec:  PyGe.Vector3d, wrtPoint:  PyGe.Point3d=Point3d.kOrigin)-> PyGe.Point3d :
      '''Returns 3D point that is the result of rotation of this point around the line with direction vector vec passing through the point wrtPoint. Rotation angle is given by the argument angle, where positive direction of rotation is defined by the right-hand rule.'''
    ...
    def scaleBy (self, factor: float, pnt:  PyGe.Point3d='orgin')-> PyGe.Point3d :
      '''Returns 3D point that is the result of scaling of this point with respect to the 3D point wrtPoint by scale factor scaleFactor.'''
    ...

    @overload
    def set (self, x: float, y: float, z: float)-> PyGe.Point3d : ...
    @overload
    def set (self, pl: PyGe.PlanarEnt, pt2d: PyGe.Point2d)-> PyGe.Point3d : ...
    def set (self, *args, **kwargs)-> PyGe.Point3d :
      '''Overloads:
    - x: float, y: float, z: float
    - pl: PyGe.PlanarEnt, pt2d: PyGe.Point2d
    '''
    ...
    def setToProduct (self, mat: PyGe.Matrix3d, pnt:  PyGe.Point3d)-> PyGe.Point3d :
      '''Sets this point to the product of matrix mat and point pnt. The order of multiplication is mat*pnt, where points are considered as columns. Returns the reference to this point.'''
    ...
    def setToSum (self, pnt:  PyGe.Point3d, vec:  PyGe.Vector3d)-> PyGe.Point3d :
      '''Sets this point to the sum of the pnt and vector vec. Returns the reference to this point.'''
    ...
    def toList (self)-> list :
      '''                             '''
    ...
    def toString (self)-> str :
      '''                             '''
    ...
    def toTuple (self)-> tuple :
      '''                             '''
    ...
    def transformBy (self, mat: PyGe.Matrix3d)-> PyGe.Point3d :
      '''Transform this pre-multiplying it the matrix leftSide. Returns the reference to this point. Result is the same as setToProduct(leftSide, *this).'''
    ...
    def x (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def y (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def z (self, *args, **kwargs)-> None :
      '''None'''
    ...

class PointEnt2d(Entity2d):
    def __init__ (self, *args, **kwargs)-> None :
      '''Raises an exception
This class cannot be instantiated from Python'''
    ...
    def cast (self, *args, **kwargs)-> PyGe.PointEnt2d :
      '''cast( (Entity2d)arg1) -> PointEnt2d :

    C++ signature :
        class PyGePointEnt2d cast(class PyGeEntity2d)'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def copy (self)-> PyGe.Entity2d :
      '''                             '''
    ...
    def copycast (self, *args, **kwargs)-> PyGe.PointEnt2d :
      '''copycast( (Entity2d)arg1) -> PointEnt2d :

    C++ signature :
        class PyGePointEnt2d copycast(class PyGeEntity2d)'''
    ...
    def isEqualTo (self, val : PyGe.Entity2d, tol : PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def isKindOf (self, val : PyGe.EntityId)-> bool :
      '''                             '''
    ...
    def isNull (self)-> bool :
      '''                             '''
    ...
    def isOn (self, pt : PyGe.Point2d, tol : PyGe.Tol=default)-> bool :
      '''                             '''
    ...
    def mirror (self, val : PyGe.Line2d)-> None :
      '''                             '''
    ...
    def point2d (self, *args, **kwargs)-> PyGe.Point2d :
      '''point2d( (PointEnt2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d point2d(class PyGePointEnt2d {lvalue})'''
    ...
    def rotateBy (self, angle : float, pt : PyGe.Point3d=PyGe.Point2d.kOrgin)-> None :
      '''                             '''
    ...
    def scaleBy (self, scaleFactor : float, pt : PyGe.Point2d=PyGe.Point2d.kOrgin)-> None :
      '''                             '''
    ...
    def transformBy (self, val : PyGe.Matrix2d)-> None :
      '''                             '''
    ...
    def translateBy (self, vec : PyGe.Vector2d)-> None :
      '''                             '''
    ...
    def type (self)-> PyGe.EntityId :
      '''                             '''
    ...

class PointEnt3d(Entity3d):
    def __init__ (self, *args, **kwargs)-> None :
      '''Raises an exception
This class cannot be instantiated from Python'''
    ...
    def cast (self, *args, **kwargs)-> PyGe.PointEnt3d :
      '''cast( (Entity3d)arg1) -> PointEnt3d :

    C++ signature :
        class PyGePointEnt3d cast(class PyGeEntity3d)'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def copy (self)-> PyGe.Entity3d :
      '''Returns a pointer to a copy of this entity. This copy is created using the new and it is the responsibility of the caller to delete it.'''
    ...
    def copycast (self, *args, **kwargs)-> PyGe.PointEnt3d :
      '''copycast( (Entity3d)arg1) -> PointEnt3d :

    C++ signature :
        class PyGePointEnt3d copycast(class PyGeEntity3d)'''
    ...
    def isEqualTo (self, val : PyGe.Entity3d, tol : PyGe.Tol=None)-> bool :
      '''Determines if two entities are equal to each other. Two entities are considered to be equal only if they are of the same type and they represent the same 3D point set. For instance, if the two entities are of types AcGeCircArc3d and AcGeEllipArc3d then they are not considered equal even if the ellipse is completely coincident with the circle. Also, two curves are not considered equal unless they have the same parameterization. For instance, two infinite coincident lines are not considered equal if they have different scaling in their parameterization. '''
    ...
    def isKindOf (self, val : PyGe.EntityId)-> bool :
      '''                             '''
    ...
    def isNull (self)-> bool :
      '''                             '''
    ...
    def isOn (self, pt : PyGe.Point3d, tol : PyGe.Tol=default)-> bool :
      '''Returns Adesk::kTrue if pnt lies on entity; otherwise, returns Adesk::kFalse.'''
    ...
    def mirror (self, val : PyGe.Plane)-> None :
      '''Transforms the entity by mirroring it across the input plane.'''
    ...
    def point3d (self, *args, **kwargs)-> PyGe.Point3d :
      '''point3d( (PointEnt3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d point3d(class PyGePointEnt3d {lvalue})'''
    ...
    def rotateBy (self, angle : float, vec : PyGe.Vector3d, pt : PyGe.Point3d = 'origin')-> None :
      '''Rotates the entity by the input angle about the line defined by the input point and vector.'''
    ...
    def scaleBy (self, scaleFactor : float, pt : PyGe.Point3d = 'origin')-> None :
      '''Scales the entity about the input point by the input scale factor. Input scale factor must be greater than 0.'''
    ...
    def transformBy (self, val : PyGe.Matrix3d)-> None :
      '''Transforms the entity by applying the input matrix.'''
    ...
    def translateBy (self, vec : PyGe.Vector3d)-> None :
      '''Translates the entity by the input vector.'''
    ...
    def type (self)-> PyGe.EntityId :
      '''Returns the type of the entity.'''
    ...

class PointOnCurve2d(PointEnt2d):
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (Curve2d)arg2) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class PyGeCurve2d)

__init__( (object)arg1, (Curve2d)arg2, (float)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class PyGeCurve2d,double)'''
    ...
    def cast (self, *args, **kwargs)-> PyGe.PointEnt2d :
      '''cast( (Entity2d)arg1) -> PointEnt2d :

    C++ signature :
        class PyGePointEnt2d cast(class PyGeEntity2d)'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def copy (self)-> PyGe.Entity2d :
      '''                             '''
    ...
    def copycast (self, *args, **kwargs)-> PyGe.PointOnCurve2d :
      '''copycast( (Entity2d)arg1) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d copycast(class PyGeEntity2d)'''
    ...
    def curve (self, *args, **kwargs)-> PyGe.Curve2d :
      '''curve( (PointOnCurve2d)arg1) -> Curve2d :

    C++ signature :
        class PyGeCurve2d curve(class PyGePointOnCurve2d {lvalue})'''
    ...
    def deriv (self, *args, **kwargs)-> PyGe.Vector2d :
      '''deriv( (PointOnCurve2d)arg1, (int)arg2) -> Vector2d :

    C++ signature :
        class AcGeVector2d deriv(class PyGePointOnCurve2d {lvalue},int)

deriv( (PointOnCurve2d)arg1, (int)arg2, (float)arg3) -> Vector2d :

    C++ signature :
        class AcGeVector2d deriv(class PyGePointOnCurve2d {lvalue},int,double)

deriv( (PointOnCurve2d)arg1, (int)arg2, (Curve2d)arg3, (float)arg4) -> Vector2d :

    C++ signature :
        class AcGeVector2d deriv(class PyGePointOnCurve2d {lvalue},int,class PyGeCurve2d,double)'''
    ...
    def isEqualTo (self, val : PyGe.Entity2d, tol : PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def isKindOf (self, val : PyGe.EntityId)-> bool :
      '''                             '''
    ...
    def isNull (self)-> bool :
      '''                             '''
    ...
    def isOn (self, pt : PyGe.Point2d, tol : PyGe.Tol=default)-> bool :
      '''                             '''
    ...
    def mirror (self, val : PyGe.Line2d)-> None :
      '''                             '''
    ...
    def parameter (self, *args, **kwargs)-> float :
      '''parameter( (PointOnCurve2d)arg1) -> float :

    C++ signature :
        double parameter(class PyGePointOnCurve2d {lvalue})'''
    ...
    def point (self, *args, **kwargs)-> PyGe.Point2d :
      '''point( (PointOnCurve2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d point(class PyGePointOnCurve2d {lvalue})

point( (PointOnCurve2d)arg1, (float)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d point(class PyGePointOnCurve2d {lvalue},double)

point( (PointOnCurve2d)arg1, (Curve2d)arg2, (float)arg3) -> Point2d :

    C++ signature :
        class AcGePoint2d point(class PyGePointOnCurve2d {lvalue},class PyGeCurve2d,double)'''
    ...
    def point2d (self, *args, **kwargs)-> PyGe.Point2d :
      '''point2d( (PointEnt2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d point2d(class PyGePointEnt2d {lvalue})'''
    ...
    def rotateBy (self, angle : float, pt : PyGe.Point3d=PyGe.Point2d.kOrgin)-> None :
      '''                             '''
    ...
    def scaleBy (self, scaleFactor : float, pt : PyGe.Point2d=PyGe.Point2d.kOrgin)-> None :
      '''                             '''
    ...
    def setCurve (self, *args, **kwargs)-> None :
      '''setCurve( (PointOnCurve2d)arg1, (Curve2d)arg2) -> None :

    C++ signature :
        void setCurve(class PyGePointOnCurve2d {lvalue},class PyGeCurve2d)'''
    ...
    def setParameter (self, *args, **kwargs)-> None :
      '''setParameter( (PointOnCurve2d)arg1, (float)arg2) -> None :

    C++ signature :
        void setParameter(class PyGePointOnCurve2d {lvalue},double)'''
    ...
    def transformBy (self, val : PyGe.Matrix2d)-> None :
      '''                             '''
    ...
    def translateBy (self, vec : PyGe.Vector2d)-> None :
      '''                             '''
    ...
    def type (self)-> PyGe.EntityId :
      '''                             '''
    ...

class PointOnCurve3d(PointEnt3d):
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (Curve3d)arg2) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class PyGeCurve3d)

__init__( (object)arg1, (Curve3d)arg2, (float)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class PyGeCurve3d,double)'''
    ...
    def cast (self, *args, **kwargs)-> PyGe.PointOnCurve3d :
      '''cast( (Entity3d)arg1) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d cast(class PyGeEntity3d)'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def copy (self)-> PyGe.Entity3d :
      '''Returns a pointer to a copy of this entity. This copy is created using the new and it is the responsibility of the caller to delete it.'''
    ...
    def copycast (self, *args, **kwargs)-> PyGe.PointOnCurve3d :
      '''copycast( (Entity3d)arg1) -> PointOnCurve3d :

    C++ signature :
        class PyGePointOnCurve3d copycast(class PyGeEntity3d)'''
    ...
    def curvature (self, *args, **kwargs)-> float :
      '''curvature( (PointOnCurve3d)arg1) -> float :

    C++ signature :
        double curvature(class PyGePointOnCurve3d {lvalue})

curvature( (PointOnCurve3d)arg1, (float)arg2) -> float :

    C++ signature :
        double curvature(class PyGePointOnCurve3d {lvalue},double)'''
    ...
    def curve (self, *args, **kwargs)-> PyGe.Curve3d :
      '''curve( (PointOnCurve3d)arg1) -> Curve3d :

    C++ signature :
        class PyGeCurve3d curve(class PyGePointOnCurve3d {lvalue})'''
    ...
    def deriv (self, *args, **kwargs)-> PyGe.Vector3d :
      '''deriv( (PointOnCurve3d)arg1, (int)arg2) -> Vector3d :

    C++ signature :
        class AcGeVector3d deriv(class PyGePointOnCurve3d {lvalue},int)

deriv( (PointOnCurve3d)arg1, (int)arg2, (float)arg3) -> Vector3d :

    C++ signature :
        class AcGeVector3d deriv(class PyGePointOnCurve3d {lvalue},int,double)

deriv( (PointOnCurve3d)arg1, (int)arg2, (Curve3d)arg3, (float)arg4) -> Vector3d :

    C++ signature :
        class AcGeVector3d deriv(class PyGePointOnCurve3d {lvalue},int,class PyGeCurve3d,double)'''
    ...
    def isEqualTo (self, val : PyGe.Entity3d, tol : PyGe.Tol=None)-> bool :
      '''Determines if two entities are equal to each other. Two entities are considered to be equal only if they are of the same type and they represent the same 3D point set. For instance, if the two entities are of types AcGeCircArc3d and AcGeEllipArc3d then they are not considered equal even if the ellipse is completely coincident with the circle. Also, two curves are not considered equal unless they have the same parameterization. For instance, two infinite coincident lines are not considered equal if they have different scaling in their parameterization. '''
    ...
    def isKindOf (self, val : PyGe.EntityId)-> bool :
      '''                             '''
    ...
    def isNull (self)-> bool :
      '''                             '''
    ...
    def isOn (self, pt : PyGe.Point3d, tol : PyGe.Tol=default)-> bool :
      '''Returns Adesk::kTrue if pnt lies on entity; otherwise, returns Adesk::kFalse.'''
    ...
    def isSingular (self, *args, **kwargs)-> bool :
      '''isSingular( (PointOnCurve3d)arg1) -> bool :

    C++ signature :
        bool isSingular(class PyGePointOnCurve3d {lvalue})'''
    ...
    def mirror (self, val : PyGe.Plane)-> None :
      '''Transforms the entity by mirroring it across the input plane.'''
    ...
    def parameter (self, *args, **kwargs)-> float :
      '''parameter( (PointOnCurve3d)arg1) -> float :

    C++ signature :
        double parameter(class PyGePointOnCurve3d {lvalue})'''
    ...
    def point (self, *args, **kwargs)-> PyGe.Point3d :
      '''point( (PointOnCurve3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d point(class PyGePointOnCurve3d {lvalue})

point( (PointOnCurve3d)arg1, (float)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d point(class PyGePointOnCurve3d {lvalue},double)

point( (PointOnCurve3d)arg1, (Curve3d)arg2, (float)arg3) -> Point3d :

    C++ signature :
        class AcGePoint3d point(class PyGePointOnCurve3d {lvalue},class PyGeCurve3d,double)'''
    ...
    def point3d (self, *args, **kwargs)-> PyGe.Point3d :
      '''point3d( (PointEnt3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d point3d(class PyGePointEnt3d {lvalue})'''
    ...
    def rotateBy (self, angle : float, vec : PyGe.Vector3d, pt : PyGe.Point3d = 'origin')-> None :
      '''Rotates the entity by the input angle about the line defined by the input point and vector.'''
    ...
    def scaleBy (self, scaleFactor : float, pt : PyGe.Point3d = 'origin')-> None :
      '''Scales the entity about the input point by the input scale factor. Input scale factor must be greater than 0.'''
    ...
    def setCurve (self, *args, **kwargs)-> None :
      '''setCurve( (PointOnCurve3d)arg1, (Curve3d)arg2) -> None :

    C++ signature :
        void setCurve(class PyGePointOnCurve3d {lvalue},class PyGeCurve3d)'''
    ...
    def setParameter (self, *args, **kwargs)-> None :
      '''setParameter( (PointOnCurve3d)arg1, (float)arg2) -> None :

    C++ signature :
        void setParameter(class PyGePointOnCurve3d {lvalue},double)'''
    ...
    def transformBy (self, val : PyGe.Matrix3d)-> None :
      '''Transforms the entity by applying the input matrix.'''
    ...
    def translateBy (self, vec : PyGe.Vector3d)-> None :
      '''Translates the entity by the input vector.'''
    ...
    def type (self)-> PyGe.EntityId :
      '''Returns the type of the entity.'''
    ...

class PointOnSurface(PointEnt3d):
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (Surface)arg2) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class PyGeSurface)

__init__( (object)arg1, (Surface)arg2, (Point2d)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class PyGeSurface,class AcGePoint2d)'''
    ...
    def cast (self, *args, **kwargs)-> PyGe.PointOnSurface :
      '''cast( (Entity3d)arg1) -> PointOnSurface :

    C++ signature :
        class PyGePointOnSurface cast(class PyGeEntity3d)'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def copy (self)-> PyGe.Entity3d :
      '''Returns a pointer to a copy of this entity. This copy is created using the new and it is the responsibility of the caller to delete it.'''
    ...
    def copycast (self, *args, **kwargs)-> PyGe.PointOnSurface :
      '''copycast( (Entity3d)arg1) -> PointOnSurface :

    C++ signature :
        class PyGePointOnSurface copycast(class PyGeEntity3d)'''
    ...
    def inverseTangentVector (self, *args, **kwargs)-> PyGe.Vector2d :
      '''inverseTangentVector( (PointOnSurface)arg1, (Vector3d)arg2) -> Vector2d :

    C++ signature :
        class AcGeVector2d inverseTangentVector(class PyGePointOnSurface {lvalue},class AcGeVector3d)

inverseTangentVector( (PointOnSurface)arg1, (Vector3d)arg2, (Point2d)arg3) -> Vector2d :

    C++ signature :
        class AcGeVector2d inverseTangentVector(class PyGePointOnSurface {lvalue},class AcGeVector3d,class AcGePoint2d)

inverseTangentVector( (PointOnSurface)arg1, (Vector3d)arg2, (Surface)arg3, (Point2d)arg4) -> Vector2d :

    C++ signature :
        class AcGeVector2d inverseTangentVector(class PyGePointOnSurface {lvalue},class AcGeVector3d,class PyGeSurface,class AcGePoint2d)'''
    ...
    def isEqualTo (self, val : PyGe.Entity3d, tol : PyGe.Tol=None)-> bool :
      '''Determines if two entities are equal to each other. Two entities are considered to be equal only if they are of the same type and they represent the same 3D point set. For instance, if the two entities are of types AcGeCircArc3d and AcGeEllipArc3d then they are not considered equal even if the ellipse is completely coincident with the circle. Also, two curves are not considered equal unless they have the same parameterization. For instance, two infinite coincident lines are not considered equal if they have different scaling in their parameterization. '''
    ...
    def isKindOf (self, val : PyGe.EntityId)-> bool :
      '''                             '''
    ...
    def isNull (self)-> bool :
      '''                             '''
    ...
    def isOn (self, pt : PyGe.Point3d, tol : PyGe.Tol=default)-> bool :
      '''Returns Adesk::kTrue if pnt lies on entity; otherwise, returns Adesk::kFalse.'''
    ...
    def mirror (self, val : PyGe.Plane)-> None :
      '''Transforms the entity by mirroring it across the input plane.'''
    ...
    def mixedPartial (self, *args, **kwargs)-> PyGe.Vector3d :
      '''mixedPartial( (PointOnSurface)arg1) -> Vector3d :

    C++ signature :
        class AcGeVector3d mixedPartial(class PyGePointOnSurface {lvalue})

mixedPartial( (PointOnSurface)arg1, (Point2d)arg2) -> Vector3d :

    C++ signature :
        class AcGeVector3d mixedPartial(class PyGePointOnSurface {lvalue},class AcGePoint2d)

mixedPartial( (PointOnSurface)arg1, (Surface)arg2, (Point2d)arg3) -> Vector3d :

    C++ signature :
        class AcGeVector3d mixedPartial(class PyGePointOnSurface {lvalue},class PyGeSurface,class AcGePoint2d)'''
    ...
    def normal (self, *args, **kwargs)-> PyGe.Vector3d :
      '''normal( (PointOnSurface)arg1) -> Vector3d :

    C++ signature :
        class AcGeVector3d normal(class PyGePointOnSurface {lvalue})

normal( (PointOnSurface)arg1, (Point2d)arg2) -> Vector3d :

    C++ signature :
        class AcGeVector3d normal(class PyGePointOnSurface {lvalue},class AcGePoint2d)

normal( (PointOnSurface)arg1, (Surface)arg2, (Point2d)arg3) -> Vector3d :

    C++ signature :
        class AcGeVector3d normal(class PyGePointOnSurface {lvalue},class PyGeSurface,class AcGePoint2d)'''
    ...
    def parameter (self, *args, **kwargs)-> PyGe.Point2d :
      '''parameter( (PointOnSurface)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d parameter(class PyGePointOnSurface {lvalue})'''
    ...
    def point (self, *args, **kwargs)-> PyGe.Point3d :
      '''point( (PointOnSurface)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d point(class PyGePointOnSurface {lvalue})

point( (PointOnSurface)arg1, (Point2d)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d point(class PyGePointOnSurface {lvalue},class AcGePoint2d)

point( (PointOnSurface)arg1, (Surface)arg2, (Point2d)arg3) -> Point3d :

    C++ signature :
        class AcGePoint3d point(class PyGePointOnSurface {lvalue},class PyGeSurface,class AcGePoint2d)'''
    ...
    def point3d (self, *args, **kwargs)-> PyGe.Point3d :
      '''point3d( (PointEnt3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d point3d(class PyGePointEnt3d {lvalue})'''
    ...
    def rotateBy (self, angle : float, vec : PyGe.Vector3d, pt : PyGe.Point3d = 'origin')-> None :
      '''Rotates the entity by the input angle about the line defined by the input point and vector.'''
    ...
    def scaleBy (self, scaleFactor : float, pt : PyGe.Point3d = 'origin')-> None :
      '''Scales the entity about the input point by the input scale factor. Input scale factor must be greater than 0.'''
    ...
    def setParameter (self, *args, **kwargs)-> None :
      '''setParameter( (PointOnSurface)arg1, (Point2d)arg2) -> None :

    C++ signature :
        void setParameter(class PyGePointOnSurface {lvalue},class AcGePoint2d)'''
    ...
    def setSurface (self, *args, **kwargs)-> None :
      '''setSurface( (PointOnSurface)arg1, (Surface)arg2) -> None :

    C++ signature :
        void setSurface(class PyGePointOnSurface {lvalue},class PyGeSurface)'''
    ...
    def surface (self, *args, **kwargs)-> PyDb.Surface :
      '''surface( (PointOnSurface)arg1) -> Surface :

    C++ signature :
        class PyGeSurface surface(class PyGePointOnSurface {lvalue})'''
    ...
    def tangentVector (self, *args, **kwargs)-> PyGe.Vector3d :
      '''tangentVector( (PointOnSurface)arg1, (Vector2d)arg2) -> Vector3d :

    C++ signature :
        class AcGeVector3d tangentVector(class PyGePointOnSurface {lvalue},class AcGeVector2d)

tangentVector( (PointOnSurface)arg1, (Vector2d)arg2, (Point2d)arg3) -> Vector3d :

    C++ signature :
        class AcGeVector3d tangentVector(class PyGePointOnSurface {lvalue},class AcGeVector2d,class AcGePoint2d)

tangentVector( (PointOnSurface)arg1, (Vector2d)arg2, (Surface)arg3, (Point2d)arg4) -> Vector3d :

    C++ signature :
        class AcGeVector3d tangentVector(class PyGePointOnSurface {lvalue},class AcGeVector2d,class PyGeSurface,class AcGePoint2d)'''
    ...
    def transformBy (self, val : PyGe.Matrix3d)-> None :
      '''Transforms the entity by applying the input matrix.'''
    ...
    def translateBy (self, vec : PyGe.Vector3d)-> None :
      '''Translates the entity by the input vector.'''
    ...
    def type (self)-> PyGe.EntityId :
      '''Returns the type of the entity.'''
    ...
    def uDeriv (self, *args, **kwargs)-> PyGe.Vector3d :
      '''uDeriv( (PointOnSurface)arg1, (int)arg2) -> Vector3d :

    C++ signature :
        class AcGeVector3d uDeriv(class PyGePointOnSurface {lvalue},int)

uDeriv( (PointOnSurface)arg1, (int)arg2, (Point2d)arg3) -> Vector3d :

    C++ signature :
        class AcGeVector3d uDeriv(class PyGePointOnSurface {lvalue},int,class AcGePoint2d)

uDeriv( (PointOnSurface)arg1, (int)arg2, (Surface)arg3, (Point2d)arg4) -> Vector3d :

    C++ signature :
        class AcGeVector3d uDeriv(class PyGePointOnSurface {lvalue},int,class PyGeSurface,class AcGePoint2d)'''
    ...
    def vDeriv (self, *args, **kwargs)-> PyGe.Vector3d :
      '''vDeriv( (PointOnSurface)arg1, (int)arg2) -> Vector3d :

    C++ signature :
        class AcGeVector3d vDeriv(class PyGePointOnSurface {lvalue},int)

vDeriv( (PointOnSurface)arg1, (int)arg2, (Point2d)arg3) -> Vector3d :

    C++ signature :
        class AcGeVector3d vDeriv(class PyGePointOnSurface {lvalue},int,class AcGePoint2d)

vDeriv( (PointOnSurface)arg1, (int)arg2, (Surface)arg3, (Point2d)arg4) -> Vector3d :

    C++ signature :
        class AcGeVector3d vDeriv(class PyGePointOnSurface {lvalue},int,class PyGeSurface,class AcGePoint2d)'''
    ...

class Polyline2d(SplineEnt2d):
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (list)arg2) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class boost::python::list)

__init__( (object)arg1, (KnotVector)arg2, (list)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class PyGeKnotVector,class boost::python::list)

__init__( (object)arg1, (Curve2d)arg2, (float)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class PyGeCurve2d,double)'''
    ...
    def area (self, startParam : float, endParam : float, tol : float = None)-> float :
      '''                             '''
    ...
    def boundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock2d :
      '''                             '''
    ...
    def cast (self, *args, **kwargs)-> PyGe.SplineEnt2d :
      '''cast( (Entity2d)arg1) -> SplineEnt2d :

    C++ signature :
        class PyGeSplineEnt2d cast(class PyGeEntity2d)'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def closestPointTo (self, other : PyGe.Point2d | PyGe.Curve2d, tol : PyGe.Tol=None)-> PyGe.Point2d :
      '''                             '''
    ...
    def continuityAtKnot (self, *args, **kwargs)-> int :
      '''continuityAtKnot( (SplineEnt2d)arg1, (int)arg2) -> int :

    C++ signature :
        int continuityAtKnot(class PyGeSplineEnt2d {lvalue},int)

continuityAtKnot( (SplineEnt2d)arg1, (int)arg2, (Tol)arg3) -> int :

    C++ signature :
        int continuityAtKnot(class PyGeSplineEnt2d {lvalue},int,class AcGeTol)'''
    ...
    def controlPointAt (self, *args, **kwargs)-> PyGe.Point2d :
      '''controlPointAt( (SplineEnt2d)arg1, (int)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d controlPointAt(class PyGeSplineEnt2d {lvalue},int)'''
    ...
    def copy (self)-> PyGe.Entity2d :
      '''                             '''
    ...
    def copycast (self, *args, **kwargs)-> PyDb.Polyline2d :
      '''copycast( (Entity2d)arg1) -> Polyline2d :

    C++ signature :
        class PyGePolyline2d copycast(class PyGeEntity2d)'''
    ...
    def degree (self, *args, **kwargs)-> int :
      '''degree( (SplineEnt2d)arg1) -> int :

    C++ signature :
        int degree(class PyGeSplineEnt2d {lvalue})'''
    ...
    def distanceTo (self, pt : PyGe.Point2d | PyGe.Curve2d, tol : PyGe.Tol=None)-> float :
      '''                             '''
    ...
    def endParam (self, *args, **kwargs)-> float :
      '''endParam( (SplineEnt2d)arg1) -> float :

    C++ signature :
        double endParam(class PyGeSplineEnt2d {lvalue})'''
    ...
    def endPoint (self, *args, **kwargs)-> PyGe.Point2d :
      '''endPoint( (SplineEnt2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d endPoint(class PyGeSplineEnt2d {lvalue})'''
    ...
    def evalPoint (self, param : float, numDeriv : int = 1)-> PyGe.Point2d :
      '''                             '''
    ...
    def explode (self, val : PyGe.Interval = None)-> list :
      '''                             '''
    ...
    def fitPointAt (self, *args, **kwargs)-> PyGe.Point2d :
      '''fitPointAt( (Polyline2d)arg1, (int)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d fitPointAt(class PyGePolyline2d {lvalue},int)'''
    ...
    def getClosestPointTo (self, other : PyGe.Point2d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve2d :
      '''                             '''
    ...
    def getClosestPointsTo (self, other : PyGe.Curve2d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def getEndPoint (self)-> PyGe.Point2d :
      '''                             '''
    ...
    def getInterval (self)-> PyGe.Interval :
      '''                             '''
    ...
    def getNormalPoint (self, pnt : PyGe.Point2d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve2d :
      '''                             '''
    ...

    @overload
    def getSamplePoints (self, numSample: int)-> list : ...
    @overload
    def getSamplePoints (self, fromParam: float, toParam: float, approxEps: float)-> list : ...
    def getSamplePoints (self, *args, **kwargs)-> list :
      '''Overloads:
    - numSample: int
    - fromParam: float, toParam: float, approxEps: float
    '''
    ...
    def getSplitCurves (self, param : float)-> tuple :
      '''                             '''
    ...
    def getStartPoint (self)-> PyGe.Point2d :
      '''                             '''
    ...
    def getTrimmedOffset (self, dist : float, extensionType : PyGe.OffsetCrvExtType, tol : PyGe.Tol=None)-> list :
      '''                             '''
    ...
    def hasEndPoint (self)-> bool :
      '''                             '''
    ...
    def hasFitData (self, *args, **kwargs)-> bool :
      '''hasFitData( (SplineEnt2d)arg1) -> bool :

    C++ signature :
        bool hasFitData(class PyGeSplineEnt2d {lvalue})'''
    ...
    def hasStartPoint (self)-> bool :
      '''                             '''
    ...
    def isClosed (self, tol : PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def isDegenerate (self, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isEqualTo (self, val : PyGe.Entity2d, tol : PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def isKindOf (self, val : PyGe.EntityId)-> bool :
      '''                             '''
    ...
    def isLinear (self, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isNull (self)-> bool :
      '''                             '''
    ...
    def isOn (self, pt : float | PyGe.Point2d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isPeriodic (self)-> tuple :
      '''                             '''
    ...
    def isRational (self, *args, **kwargs)-> bool :
      '''isRational( (SplineEnt2d)arg1) -> bool :

    C++ signature :
        bool isRational(class PyGeSplineEnt2d {lvalue})'''
    ...
    def knotAt (self, *args, **kwargs)-> float :
      '''knotAt( (SplineEnt2d)arg1, (int)arg2) -> float :

    C++ signature :
        double knotAt(class PyGeSplineEnt2d {lvalue},int)'''
    ...
    def knots (self, *args, **kwargs)-> PyGe.KnotVector :
      '''knots( (SplineEnt2d)arg1) -> KnotVector :

    C++ signature :
        class PyGeKnotVector knots(class PyGeSplineEnt2d {lvalue})'''
    ...
    def length (self, frm : float, to : float, tol : float = None)-> float :
      '''                             '''
    ...
    def mirror (self, val : PyGe.Line2d)-> None :
      '''                             '''
    ...
    def numControlPoints (self, *args, **kwargs)-> int :
      '''numControlPoints( (SplineEnt2d)arg1) -> int :

    C++ signature :
        int numControlPoints(class PyGeSplineEnt2d {lvalue})'''
    ...
    def numFitPoints (self, *args, **kwargs)-> int :
      '''numFitPoints( (Polyline2d)arg1) -> int :

    C++ signature :
        int numFitPoints(class PyGePolyline2d {lvalue})'''
    ...
    def numKnots (self, *args, **kwargs)-> int :
      '''numKnots( (SplineEnt2d)arg1) -> int :

    C++ signature :
        int numKnots(class PyGeSplineEnt2d {lvalue})'''
    ...
    def order (self, *args, **kwargs)-> int :
      '''order( (SplineEnt2d)arg1) -> int :

    C++ signature :
        int order(class PyGeSplineEnt2d {lvalue})'''
    ...
    def orthoBoundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock2d :
      '''                             '''
    ...
    def paramAtLength (self, datumParam: float, length: float, posParamDir: bool=True, tol: float=None)-> float :
      '''                             '''
    ...
    def paramOf (self, pt : PyGe.Point2d, tol : PyGe.Tol=None)-> float :
      '''                             '''
    ...
    def reverseParam (self)-> None :
      '''                             '''
    ...
    def rotateBy (self, angle : float, pt : PyGe.Point3d=PyGe.Point2d.kOrgin)-> None :
      '''                             '''
    ...
    def scaleBy (self, scaleFactor : float, pt : PyGe.Point2d=PyGe.Point2d.kOrgin)-> None :
      '''                             '''
    ...
    def setControlPointAt (self, *args, **kwargs)-> None :
      '''setControlPointAt( (SplineEnt2d)arg1, (int)arg2, (Point2d)arg3) -> None :

    C++ signature :
        void setControlPointAt(class PyGeSplineEnt2d {lvalue},int,class AcGePoint2d)'''
    ...
    def setFitPointAt (self, *args, **kwargs)-> None :
      '''setFitPointAt( (Polyline2d)arg1, (int)arg2, (Point2d)arg3) -> None :

    C++ signature :
        void setFitPointAt(class PyGePolyline2d {lvalue},int,class AcGePoint2d)'''
    ...
    def setInterval (self, val : PyGe.Interval = None)-> None :
      '''                             '''
    ...
    def setKnotAt (self, *args, **kwargs)-> None :
      '''setKnotAt( (SplineEnt2d)arg1, (int)arg2, (float)arg3) -> None :

    C++ signature :
        void setKnotAt(class PyGeSplineEnt2d {lvalue},int,double)'''
    ...
    def startParam (self, *args, **kwargs)-> float :
      '''startParam( (SplineEnt2d)arg1) -> float :

    C++ signature :
        double startParam(class PyGeSplineEnt2d {lvalue})'''
    ...
    def startPoint (self, *args, **kwargs)-> PyGe.Point2d :
      '''startPoint( (SplineEnt2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d startPoint(class PyGeSplineEnt2d {lvalue})'''
    ...
    def transformBy (self, val : PyGe.Matrix2d)-> None :
      '''                             '''
    ...
    def translateBy (self, vec : PyGe.Vector2d)-> None :
      '''                             '''
    ...
    def type (self)-> PyGe.EntityId :
      '''                             '''
    ...

class Polyline3d(SplineEnt3d):
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (list)arg2) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class boost::python::list)

__init__( (object)arg1, (KnotVector)arg2, (list)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class PyGeKnotVector,class boost::python::list)

__init__( (object)arg1, (Curve3d)arg2, (float)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class PyGeCurve3d,double)'''
    ...
    def area (self, startParam : float, endParam : float, tol : float = None)-> float :
      '''Returns the area of the interval of the curve defined by startParam and endParam. Returns Adesk::kTrue if area was successfully computed to within the specified tolerance. If the curve is not planar, then the area cannot be calculated and a value of Adesk::kFalse is returned. If the points at startParam and endParam are the same, then this function returns the area of the closed curve. If the points are different, then this function connects the two points with a line segment and return the signed area between the curve and the line segment. If the line segment does not intersect the curve at any points between startParam and endParam, then the returned area is positive. If the line segment intersects the curves at any points between startParam and endParam, then the returned area is the sum of the sub-areas created by the intersection of the line segment with the curve. Each sub-area has a positive or negative area, depending on whether the curve lies above or below the line segment. The total area returned by this function can therefore be positive, negative, or 0. '''
    ...
    def boundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock3d :
      '''Returns the bounding box of the curve. The sides of the returned box are parallel to the coordinate axes. '''
    ...
    def cast (self, *args, **kwargs)-> PyDb.Polyline3d :
      '''cast( (Entity3d)arg1) -> Polyline3d :

    C++ signature :
        class PyGePolyline3d cast(class PyGeEntity3d)'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def closestPointTo (self, other : PyGe.Point3d | PyGe.Curve3d, tol : PyGe.Tol=None)-> PyGe.Point3d :
      '''Finds the closest point on this curve to the input point. This function is the same as closestPointTo(), except that the closest point is returned as an AcGePointOnCurve3d object.'''
    ...
    def continuityAtKnot (self, *args, **kwargs)-> int :
      '''continuityAtKnot( (SplineEnt3d)arg1, (int)arg2) -> int :

    C++ signature :
        int continuityAtKnot(class PyGeSplineEnt3d {lvalue},int)

continuityAtKnot( (SplineEnt3d)arg1, (int)arg2, (Tol)arg3) -> int :

    C++ signature :
        int continuityAtKnot(class PyGeSplineEnt3d {lvalue},int,class AcGeTol)'''
    ...
    def controlPointAt (self, *args, **kwargs)-> PyGe.Point3d :
      '''controlPointAt( (SplineEnt3d)arg1, (int)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d controlPointAt(class PyGeSplineEnt3d {lvalue},int)'''
    ...
    def copy (self)-> PyGe.Entity3d :
      '''Returns a pointer to a copy of this entity. This copy is created using the new and it is the responsibility of the caller to delete it.'''
    ...
    def copycast (self, *args, **kwargs)-> PyDb.Polyline3d :
      '''copycast( (Entity3d)arg1) -> Polyline3d :

    C++ signature :
        class PyGePolyline3d copycast(class PyGeEntity3d)'''
    ...
    def degree (self, *args, **kwargs)-> int :
      '''degree( (SplineEnt3d)arg1) -> int :

    C++ signature :
        int degree(class PyGeSplineEnt3d {lvalue})'''
    ...
    def distanceTo (self, pt : PyGe.Point3d | PyGe.Curve3d, tol : PyGe.Tol=None)-> float :
      '''Returns the distance between the input point and the closest point on this curve.'''
    ...
    def endParam (self, *args, **kwargs)-> float :
      '''endParam( (SplineEnt3d)arg1) -> float :

    C++ signature :
        double endParam(class PyGeSplineEnt3d {lvalue})'''
    ...
    def endPoint (self, *args, **kwargs)-> PyGe.Point3d :
      '''endPoint( (SplineEnt3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d endPoint(class PyGeSplineEnt3d {lvalue})'''
    ...
    def evalPoint (self, param : float, numDeriv : int = 1)-> PyGe.Point3d :
      '''Returns the point on the curve that corresponds to the input parameter value. Also returns the number of derivative vectors that are specified in numDeriv. The numDeriv parameter should not be set larger than 2.'''
    ...
    def explode (self, val : PyGe.Interval = None)-> list :
      '''Explodes the curve into its individual components. If the curve is a composite curve, then explodedCurves contains the list of component curves of the composite. If the curve is a spline, then it is exploded at the points of C1 discontinuity and explodedCurves contains a copy of each continuous sub-curve. This function returns Adesk::kTrue if the curve was exploded (that is, the curve was a composite or a discontinuous spline) and Adesk::kFalse otherwise. The number of entries returned in newExplodedCurves is always the same as the number of entries in explodedCurves. Each flag in newExplodedCurves indicates whether the corresponding curve in explodedCurves was created with the new operator. If the flag is 1, then it is the responsibility of the caller to delete the curve. If the flag is 0, the curve is deleted by gelib and the caller should not attempt to delete it. If no intrvl parameter is supplied, then the interval is taken to be the entire curve. '''
    ...
    def fitPointAt (self, *args, **kwargs)-> PyGe.Point3d :
      '''fitPointAt( (Polyline3d)arg1, (int)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d fitPointAt(class PyGePolyline3d {lvalue},int)'''
    ...
    def getClosestPointTo (self, other : PyGe.Point3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''Finds the closest point on this curve to the input point. This function is the same as closestPointTo(), except that the closest point is returned as an AcGePointOnCurve3d object.'''
    ...
    def getClosestPointsTo (self, other : PyGe.Curve3d, tol : PyGe.Tol=None)-> tuple :
      '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
    ...
    def getEndPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def getInterval (self)-> PyGe.Interval :
      '''Returns the parametric range of the curve. The function evalPoint(double) always returns a point on this curve when called with a value within the returned interval.'''
    ...
    def getNormalPoint (self, pnt : PyGe.Point3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''Finds the point on the input curve whose normal passes through the input point. The returned point lies on a plane that also contains the input point and is perpendicular to the curve tangent at that point. The returned point is therefore at a local minimum or a local maximum from the input point. The curve does not need to be planar. If the curve is planar, the input point does not need to lie in the plane of the curve. On input, the second parameter is assumed to contain the parameter value of an initial guess. If there is more than one normal point on the curve, the returned point will be the one whose parameter value is closest to the input parameter value.'''
    ...
    def getProjClosestPointTo (self, pt : PyGe.Point3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
    ...
    def getProjClosestPointsTo (self, pt : PyGe.Curve3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> tuple :
      '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
    ...

    @overload
    def getSamplePoints (self, numSample: int)-> tuple : ...
    @overload
    def getSamplePoints (self, fromParam: float, toParam: float, approxEps: float)-> tuple : ...
    def getSamplePoints (self, *args, **kwargs)-> tuple :
      '''Overloads:
    - numSample: int
    - fromParam: float, toParam: float, approxEps: float
    
	-Returns the specified number of points on the curve. The points are equally spaced by parameter value. So if the interval of the curve [0,1] and numSample is 5, the parameter values of the returned points are 0, 0.25, 0.5, 0.75, and 1.-'''
    ...
    def getSplitCurves (self, param : float)-> tuple :
      '''Returns two segments which are obtained by splitting the curve at the input parameter value. If the specified parameter value does not lie within the parametric interval of the curve or if it corresponds to the start point or endpoint of the curve, then piece1 and piece2 are set to null. This function uses the new to create the curve segments whose addresses are returned in piece1 and piece2. It is the responsibility of the caller to delete these objects. '''
    ...
    def getStartPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def getTrimmedOffset (self, dist : float, planeNormal : PyGe.Vector3d, extensionType : PyGe.OffsetCrvExtType, tol : PyGe.Tol=None)-> list :
      '''Returns one or more offset curves that represent the trimmed offset of the curve. The curve must be planar and planeNormal must be perpendicular to the plane of the curve. The positive direction of offset at a point on the curve is taken to be the cross product of planeNormal with the tangent vector at that point. The curve may be offset in either of two directions by specifying a positive or negative offset distance; planeNormal determines which direction is the positive direction of offset. The returned offset curves are trimmed so that they do not contain any points of self-intersection. Each curve that is returned in offsetCurveList is created with the new and it is the responsibility of the caller to delete these curves. Each curve that is returned in offsetCurveList is a connected curve and may be a composite curve if the offset curve had to be trimmed to remove self-intersecting loops. offsetCurveList only contains more than one curve if the offset operation produces multiple curves which are not connected. If the original curve contains points of C1 discontinuity and the direction of offset causes the offset curve to be disjoint (for instance, if the original curve is a composite curve that is a rectangle and the direction of offset is to the outside of the rectangle), then the offset curve is closed with an arc or a line segment, or the curves are simply extended depending on the value of extensionType.'''
    ...
    def hasEndPoint (self)-> bool :
      '''Returns Adesk::kTrue if curve has an endpoint. A return value of Adesk::kFalse means that the parametric interval of the curve does not have an upper bound. The endPnt parameter contains meaningful data only if this function returns a value of Adesk::kTrue.'''
    ...
    def hasFitData (self, *args, **kwargs)-> bool :
      '''hasFitData( (SplineEnt3d)arg1) -> bool :

    C++ signature :
        bool hasFitData(class PyGeSplineEnt3d {lvalue})'''
    ...
    def hasStartPoint (self)-> bool :
      '''Returns Adesk::kTrue if curve has a start point. A return value of Adesk::kFalse means that the parametric interval of the curve does not have a lower bound. The startPnt parameter contains meaningful data only if this function returns a value of Adesk::kTrue.'''
    ...
    def isClosed (self, tol : PyGe.Tol=None)-> bool :
      '''Determines if start point and endpoint of curve are the same.'''
    ...
    def isCoplanarWith (self, curve : PyGe.Curve3d, tol : PyGe.Tol=None)-> tuple :
      '''Returns Adesk::kTrue if both curve are planar and lie in the same plane. The plane parameter is only valid if this function returns a value of Adesk::kTrue.'''
    ...
    def isDegenerate (self, tol : PyGe.Tol=None)-> tuple :
      '''Determines if the curve is degenerate and if so returns the type of entity which the curve degenerates into. For example, if the curve is a circle with a radius of 0 then degenerateType is set to AcGe::kPoint3d. If the curve is an ellipse with a minor radius of 0 and a major radius of 1, then degenerateType is set to AcGe::kLineSeg3d. The degenerateType parameter is only set to something meaningful when this function returns a value of Adesk::kTrue.'''
    ...
    def isEqualTo (self, val : PyGe.Entity3d, tol : PyGe.Tol=None)-> bool :
      '''Determines if two entities are equal to each other. Two entities are considered to be equal only if they are of the same type and they represent the same 3D point set. For instance, if the two entities are of types AcGeCircArc3d and AcGeEllipArc3d then they are not considered equal even if the ellipse is completely coincident with the circle. Also, two curves are not considered equal unless they have the same parameterization. For instance, two infinite coincident lines are not considered equal if they have different scaling in their parameterization. '''
    ...
    def isKindOf (self, val : PyGe.EntityId)-> bool :
      '''                             '''
    ...
    def isLinear (self, tol : PyGe.Tol=None)-> tuple :
      '''Determines if curve is linear. This function returns an infinite line even if the curve is not infinite. The line parameter contains meaningful data only if this function returns a value of Adesk::kTrue.'''
    ...
    def isNull (self)-> bool :
      '''                             '''
    ...
    def isOn (self, pt : float | PyGe.Point3d, tol : PyGe.Tol=None)-> tuple :
      '''Determines if input parameter value is within valid parametric range of curve.'''
    ...
    def isPeriodic (self)-> tuple :
      '''Determines if the curve is periodic. The curve is periodic if and only if it is closed and the two points evalPoint(t) and evalPoint(t+period) are always the same point for all values of t.'''
    ...
    def isPlanar (self, tol : PyGe.Tol=None)-> tuple :
      '''Determines if curve is planar. If the curve is a line, then this function returns an arbitrary plane that contains the line. The plane parameter contains meaningful data only if this function returns a value of Adesk::kTrue. '''
    ...
    def isRational (self, *args, **kwargs)-> bool :
      '''isRational( (SplineEnt3d)arg1) -> bool :

    C++ signature :
        bool isRational(class PyGeSplineEnt3d {lvalue})'''
    ...
    def knotAt (self, *args, **kwargs)-> float :
      '''knotAt( (SplineEnt3d)arg1, (int)arg2) -> float :

    C++ signature :
        double knotAt(class PyGeSplineEnt3d {lvalue},int)'''
    ...
    def knots (self, *args, **kwargs)-> PyGe.KnotVector :
      '''knots( (SplineEnt3d)arg1) -> KnotVector :

    C++ signature :
        class PyGeKnotVector knots(class PyGeSplineEnt3d {lvalue})'''
    ...
    def length (self, frm : float, to : float, tol : float = None)-> float :
      '''Returns the arc length of the curve between the two parameter values.'''
    ...
    def mirror (self, val : PyGe.Plane)-> None :
      '''Transforms the entity by mirroring it across the input plane.'''
    ...
    def numControlPoints (self, *args, **kwargs)-> int :
      '''numControlPoints( (SplineEnt3d)arg1) -> int :

    C++ signature :
        int numControlPoints(class PyGeSplineEnt3d {lvalue})'''
    ...
    def numFitPoints (self, *args, **kwargs)-> int :
      '''numFitPoints( (Polyline3d)arg1) -> int :

    C++ signature :
        int numFitPoints(class PyGePolyline3d {lvalue})'''
    ...
    def numKnots (self, *args, **kwargs)-> int :
      '''numKnots( (SplineEnt3d)arg1) -> int :

    C++ signature :
        int numKnots(class PyGeSplineEnt3d {lvalue})'''
    ...
    def order (self, *args, **kwargs)-> int :
      '''order( (SplineEnt3d)arg1) -> int :

    C++ signature :
        int order(class PyGeSplineEnt3d {lvalue})'''
    ...
    def orthoBoundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock3d :
      '''Returns the bounding box of the curve. The sides of the returned box are parallel to the coordinate axes.'''
    ...
    def orthoProject (self, projectionPlane : PyGe.Plane, tol : PyGe.Tol=None)-> PyGe.Entity3d :
      '''Returns the entity that is the orthogonal projection of the curve onto the projection plane. The returned entity may not be of the same type as the original curve and may not even be a curve (for instance, a line projects into a point if it is orthogonal to the projection plane). The returned entity is created with the new and it is the responsibility of the caller to delete it.'''
    ...
    def paramAtLength (self, datumParam : float, length : float, posParamDir : bool=True, tol : float = default)-> float :
      '''Returns the parameter value of the point whose arc length distance (from the point with parameter value datumParam) is the input length. In other words, ift = paramAtLength (datumParam, len, posParamDir, tol) then length (t, datumParam, tol) is (approximately) equal to len. If posParamDir is set to Adesk::kTrue, then the returned parameter value is greater than datumParam. Otherwise it will be less than datumParam. '''
    ...
    def paramOf (self, pt : PyGe.Point3d, tol : PyGe.Tol=None)-> float :
      '''Returns the parameter value of pnt. This function assumes that pnt lies on the curve and does not verify this. If pnt does not lie on the curve, this function will return unpredictable results. If it is not known whether pnt lies on the curve, the user should not call this function but should instead call AcGeCurve3d::isOn (pnt, param, tol). '''
    ...
    def projClosestPointTo (self, pt : PyGe.Point3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.Point3d :
      '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
    ...
    def projClosestPointsTo (self, pt : PyGe.Curve3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> tuple :
      '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
    ...
    def project (self, projectionPlane : PyGe.Plane, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.Entity3d :
      '''Returns the entity that is the projection of the curve onto the projection plane in the specified direction. The projectDirection vector must not be parallel to the projection plane. The returned entity may not be of the same type as the original curve and may not even be a curve (for instance, a line projects into a point if it is parallel to projectDirection). The returned entity is created with the new and it is the responsibility of the caller to delete it.'''
    ...
    def reverseParam (self)-> None :
      '''Reverses the parametric direction of the curve. The point set of the curve is unchanged, but the direction of the curve is reversed.'''
    ...
    def rotateBy (self, angle : float, vec : PyGe.Vector3d, pt : PyGe.Point3d = 'origin')-> None :
      '''Rotates the entity by the input angle about the line defined by the input point and vector.'''
    ...
    def scaleBy (self, scaleFactor : float, pt : PyGe.Point3d = 'origin')-> None :
      '''Scales the entity about the input point by the input scale factor. Input scale factor must be greater than 0.'''
    ...
    def setControlPointAt (self, *args, **kwargs)-> None :
      '''setControlPointAt( (SplineEnt3d)arg1, (int)arg2, (Point3d)arg3) -> None :

    C++ signature :
        void setControlPointAt(class PyGeSplineEnt3d {lvalue},int,class AcGePoint3d)'''
    ...
    def setFitPointAt (self, *args, **kwargs)-> None :
      '''setFitPointAt( (Polyline3d)arg1, (int)arg2, (Point3d)arg3) -> None :

    C++ signature :
        void setFitPointAt(class PyGePolyline3d {lvalue},int,class AcGePoint3d)'''
    ...
    def setInterval (self, val : PyGe.Interval = None)-> None :
      '''Sets the domain of the curve to the input interval.'''
    ...
    def setKnotAt (self, *args, **kwargs)-> None :
      '''setKnotAt( (SplineEnt3d)arg1, (int)arg2, (float)arg3) -> None :

    C++ signature :
        void setKnotAt(class PyGeSplineEnt3d {lvalue},int,double)'''
    ...
    def startParam (self, *args, **kwargs)-> float :
      '''startParam( (SplineEnt3d)arg1) -> float :

    C++ signature :
        double startParam(class PyGeSplineEnt3d {lvalue})'''
    ...
    def startPoint (self, *args, **kwargs)-> PyGe.Point3d :
      '''startPoint( (SplineEnt3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d startPoint(class PyGeSplineEnt3d {lvalue})'''
    ...
    def transformBy (self, val : PyGe.Matrix3d)-> None :
      '''Transforms the entity by applying the input matrix.'''
    ...
    def translateBy (self, vec : PyGe.Vector3d)-> None :
      '''Translates the entity by the input vector.'''
    ...
    def type (self)-> PyGe.EntityId :
      '''Returns the type of the entity.'''
    ...

class Position2d(PointEnt2d):
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (Point2d)arg2) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePoint2d)

__init__( (object)arg1, (float)arg2, (float)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,double,double)'''
    ...
    def cast (self, *args, **kwargs)-> PyGe.Position2d :
      '''cast( (Entity2d)arg1) -> Position2d :

    C++ signature :
        class PyGePosition2d cast(class PyGeEntity2d)'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def copy (self)-> PyGe.Entity2d :
      '''                             '''
    ...
    def copycast (self, *args, **kwargs)-> PyGe.Position2d :
      '''copycast( (Entity2d)arg1) -> Position2d :

    C++ signature :
        class PyGePosition2d copycast(class PyGeEntity2d)'''
    ...
    def isEqualTo (self, val : PyGe.Entity2d, tol : PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def isKindOf (self, val : PyGe.EntityId)-> bool :
      '''                             '''
    ...
    def isNull (self)-> bool :
      '''                             '''
    ...
    def isOn (self, pt : PyGe.Point2d, tol : PyGe.Tol=default)-> bool :
      '''                             '''
    ...
    def mirror (self, val : PyGe.Line2d)-> None :
      '''                             '''
    ...
    def point2d (self, *args, **kwargs)-> PyGe.Point2d :
      '''point2d( (PointEnt2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d point2d(class PyGePointEnt2d {lvalue})'''
    ...
    def rotateBy (self, angle : float, pt : PyGe.Point3d=PyGe.Point2d.kOrgin)-> None :
      '''                             '''
    ...
    def scaleBy (self, scaleFactor : float, pt : PyGe.Point2d=PyGe.Point2d.kOrgin)-> None :
      '''                             '''
    ...
    def set (self, *args, **kwargs)-> None :
      '''set( (Position2d)arg1, (Point2d)arg2) -> None :

    C++ signature :
        void set(class PyGePosition2d {lvalue},class AcGePoint2d)

set( (Position2d)arg1, (float)arg2, (float)arg3) -> None :

    C++ signature :
        void set(class PyGePosition2d {lvalue},double,double)'''
    ...
    def transformBy (self, val : PyGe.Matrix2d)-> None :
      '''                             '''
    ...
    def translateBy (self, vec : PyGe.Vector2d)-> None :
      '''                             '''
    ...
    def type (self)-> PyGe.EntityId :
      '''                             '''
    ...

class Position3d(PointEnt3d):
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (Point3d)arg2) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePoint3d)

__init__( (object)arg1, (float)arg2, (float)arg3, (float)arg4) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,double,double,double)'''
    ...
    def cast (self, *args, **kwargs)-> PyGe.Position3d :
      '''cast( (Entity3d)arg1) -> Position3d :

    C++ signature :
        class PyGePosition3d cast(class PyGeEntity3d)'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def copy (self)-> PyGe.Entity3d :
      '''Returns a pointer to a copy of this entity. This copy is created using the new and it is the responsibility of the caller to delete it.'''
    ...
    def copycast (self, *args, **kwargs)-> PyGe.Position3d :
      '''copycast( (Entity3d)arg1) -> Position3d :

    C++ signature :
        class PyGePosition3d copycast(class PyGeEntity3d)'''
    ...
    def isEqualTo (self, val : PyGe.Entity3d, tol : PyGe.Tol=None)-> bool :
      '''Determines if two entities are equal to each other. Two entities are considered to be equal only if they are of the same type and they represent the same 3D point set. For instance, if the two entities are of types AcGeCircArc3d and AcGeEllipArc3d then they are not considered equal even if the ellipse is completely coincident with the circle. Also, two curves are not considered equal unless they have the same parameterization. For instance, two infinite coincident lines are not considered equal if they have different scaling in their parameterization. '''
    ...
    def isKindOf (self, val : PyGe.EntityId)-> bool :
      '''                             '''
    ...
    def isNull (self)-> bool :
      '''                             '''
    ...
    def isOn (self, pt : PyGe.Point3d, tol : PyGe.Tol=default)-> bool :
      '''Returns Adesk::kTrue if pnt lies on entity; otherwise, returns Adesk::kFalse.'''
    ...
    def mirror (self, val : PyGe.Plane)-> None :
      '''Transforms the entity by mirroring it across the input plane.'''
    ...
    def point3d (self, *args, **kwargs)-> PyGe.Point3d :
      '''point3d( (PointEnt3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d point3d(class PyGePointEnt3d {lvalue})'''
    ...
    def rotateBy (self, angle : float, vec : PyGe.Vector3d, pt : PyGe.Point3d = 'origin')-> None :
      '''Rotates the entity by the input angle about the line defined by the input point and vector.'''
    ...
    def scaleBy (self, scaleFactor : float, pt : PyGe.Point3d = 'origin')-> None :
      '''Scales the entity about the input point by the input scale factor. Input scale factor must be greater than 0.'''
    ...
    def set (self, *args, **kwargs)-> None :
      '''set( (Position3d)arg1, (Point3d)arg2) -> None :

    C++ signature :
        void set(class PyGePosition3d {lvalue},class AcGePoint3d)

set( (Position3d)arg1, (float)arg2, (float)arg3, (float)arg4) -> None :

    C++ signature :
        void set(class PyGePosition3d {lvalue},double,double,double)'''
    ...
    def transformBy (self, val : PyGe.Matrix3d)-> None :
      '''Transforms the entity by applying the input matrix.'''
    ...
    def translateBy (self, vec : PyGe.Vector3d)-> None :
      '''Translates the entity by the input vector.'''
    ...
    def type (self)-> PyGe.EntityId :
      '''Returns the type of the entity.'''
    ...

class Ray2d(LinearEnt2d):
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (Point2d)arg2, (Vector2d)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePoint2d,class AcGeVector2d)

__init__( (object)arg1, (Point2d)arg2, (Point2d)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePoint2d,class AcGePoint2d)'''
    ...
    def area (self, startParam : float, endParam : float, tol : float = None)-> float :
      '''                             '''
    ...
    def boundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock2d :
      '''                             '''
    ...
    def cast (self, *args, **kwargs)-> PyGe.Ray2d :
      '''cast( (Entity2d)arg1) -> Ray2d :

    C++ signature :
        class PyGeRay2d cast(class PyGeEntity2d)'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def closestPointTo (self, other : PyGe.Point2d | PyGe.Curve2d, tol : PyGe.Tol=None)-> PyGe.Point2d :
      '''                             '''
    ...
    def copy (self)-> PyGe.Entity2d :
      '''                             '''
    ...
    def copycast (self, *args, **kwargs)-> PyGe.Ray2d :
      '''copycast( (Entity2d)arg1) -> Ray2d :

    C++ signature :
        class PyGeRay2d copycast(class PyGeEntity2d)'''
    ...
    def direction (self, *args, **kwargs)-> PyGe.Vector2d :
      '''direction( (LinearEnt2d)arg1) -> Vector2d :

    C++ signature :
        class AcGeVector2d direction(class PyGeLinearEnt2d {lvalue})'''
    ...
    def distanceTo (self, pt : PyGe.Point2d | PyGe.Curve2d, tol : PyGe.Tol=None)-> float :
      '''                             '''
    ...
    def evalPoint (self, param : float, numDeriv : int = 1)-> PyGe.Point2d :
      '''                             '''
    ...
    def explode (self, val : PyGe.Interval = None)-> list :
      '''                             '''
    ...
    def getClosestPointTo (self, other : PyGe.Point2d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve2d :
      '''                             '''
    ...
    def getClosestPointsTo (self, other : PyGe.Curve2d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def getEndPoint (self)-> PyGe.Point2d :
      '''                             '''
    ...
    def getInterval (self)-> PyGe.Interval :
      '''                             '''
    ...
    def getLine (self, *args, **kwargs)-> PyGe.Line2d :
      '''getLine( (LinearEnt2d)arg1) -> Line2d :

    C++ signature :
        class PyGeLine2d getLine(class PyGeLinearEnt2d {lvalue})'''
    ...
    def getNormalPoint (self, pnt : PyGe.Point2d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve2d :
      '''                             '''
    ...
    def getPerpLine (self, *args, **kwargs)-> PyGe.Line2d :
      '''getPerpLine( (LinearEnt2d)arg1, (Point2d)arg2) -> Line2d :

    C++ signature :
        class PyGeLine2d getPerpLine(class PyGeLinearEnt2d {lvalue},class AcGePoint2d)'''
    ...

    @overload
    def getSamplePoints (self, numSample: int)-> list : ...
    @overload
    def getSamplePoints (self, fromParam: float, toParam: float, approxEps: float)-> list : ...
    def getSamplePoints (self, *args, **kwargs)-> list :
      '''Overloads:
    - numSample: int
    - fromParam: float, toParam: float, approxEps: float
    '''
    ...
    def getSplitCurves (self, param : float)-> tuple :
      '''                             '''
    ...
    def getStartPoint (self)-> PyGe.Point2d :
      '''                             '''
    ...
    def getTrimmedOffset (self, dist : float, extensionType : PyGe.OffsetCrvExtType, tol : PyGe.Tol=None)-> list :
      '''                             '''
    ...
    def hasEndPoint (self)-> bool :
      '''                             '''
    ...
    def hasStartPoint (self)-> bool :
      '''                             '''
    ...
    def intersectWith (self, *args, **kwargs)-> tuple :
      '''intersectWith( (LinearEnt2d)arg1, (LinearEnt2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d)

intersectWith( (LinearEnt2d)arg1, (LinearEnt2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d,class AcGeTol)'''
    ...
    def isClosed (self, tol : PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def isColinearTo (self, *args, **kwargs)-> bool :
      '''isColinearTo( (LinearEnt2d)arg1, (LinearEnt2d)arg2) -> bool :

    C++ signature :
        bool isColinearTo(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d)

isColinearTo( (LinearEnt2d)arg1, (LinearEnt2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isColinearTo(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d,class AcGeTol)'''
    ...
    def isDegenerate (self, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isEqualTo (self, val : PyGe.Entity2d, tol : PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def isKindOf (self, val : PyGe.EntityId)-> bool :
      '''                             '''
    ...
    def isLinear (self, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isNull (self)-> bool :
      '''                             '''
    ...
    def isOn (self, pt : float | PyGe.Point2d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isParallelTo (self, *args, **kwargs)-> bool :
      '''isParallelTo( (LinearEnt2d)arg1, (LinearEnt2d)arg2) -> bool :

    C++ signature :
        bool isParallelTo(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d)

isParallelTo( (LinearEnt2d)arg1, (LinearEnt2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isParallelTo(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d,class AcGeTol)'''
    ...
    def isPeriodic (self)-> tuple :
      '''                             '''
    ...
    def isPerpendicularTo (self, *args, **kwargs)-> bool :
      '''isPerpendicularTo( (LinearEnt2d)arg1, (LinearEnt2d)arg2) -> bool :

    C++ signature :
        bool isPerpendicularTo(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d)

isPerpendicularTo( (LinearEnt2d)arg1, (LinearEnt2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isPerpendicularTo(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d,class AcGeTol)'''
    ...
    def length (self, frm : float, to : float, tol : float = None)-> float :
      '''                             '''
    ...
    def mirror (self, val : PyGe.Line2d)-> None :
      '''                             '''
    ...
    def orthoBoundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock2d :
      '''                             '''
    ...
    def overlap (self, *args, **kwargs)-> tuple :
      '''overlap( (LinearEnt2d)arg1, (LinearEnt2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple overlap(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d)

overlap( (LinearEnt2d)arg1, (LinearEnt2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple overlap(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d,class AcGeTol)'''
    ...
    def paramAtLength (self, datumParam: float, length: float, posParamDir: bool=True, tol: float=None)-> float :
      '''                             '''
    ...
    def paramOf (self, pt : PyGe.Point2d, tol : PyGe.Tol=None)-> float :
      '''                             '''
    ...
    def pointOnLine (self, *args, **kwargs)-> PyGe.Point2d :
      '''pointOnLine( (LinearEnt2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d pointOnLine(class PyGeLinearEnt2d {lvalue})'''
    ...
    def reverseParam (self)-> None :
      '''                             '''
    ...
    def rotateBy (self, angle : float, pt : PyGe.Point3d=PyGe.Point2d.kOrgin)-> None :
      '''                             '''
    ...
    def scaleBy (self, scaleFactor : float, pt : PyGe.Point2d=PyGe.Point2d.kOrgin)-> None :
      '''                             '''
    ...
    def set (self, *args, **kwargs)-> None :
      '''set( (Ray2d)arg1, (Point2d)arg2, (Vector2d)arg3) -> None :

    C++ signature :
        void set(class PyGeRay2d {lvalue},class AcGePoint2d,class AcGeVector2d)

set( (Ray2d)arg1, (Point2d)arg2, (Point2d)arg3) -> None :

    C++ signature :
        void set(class PyGeRay2d {lvalue},class AcGePoint2d,class AcGePoint2d)'''
    ...
    def setInterval (self, val : PyGe.Interval = None)-> None :
      '''                             '''
    ...
    def transformBy (self, val : PyGe.Matrix2d)-> None :
      '''                             '''
    ...
    def translateBy (self, vec : PyGe.Vector2d)-> None :
      '''                             '''
    ...
    def type (self)-> PyGe.EntityId :
      '''                             '''
    ...

class Ray3d(LinearEnt3d):

    @overload
    def __init__ (self, /)-> None : ...
    @overload
    def __init__ (self, startPoint: PyGe.Point3d, endPoint: PyGe.Point3d)-> None : ...
    @overload
    def __init__ (self, startPoint: PyGe.Point3d, direction: PyGe.Vector3d)-> None : ...
    def __init__ (self, *args, **kwargs)-> None :
      '''Overloads:
    - None: Any
    - startPoint: PyGe.Point3d, endPoint: PyGe.Point3d
    - startPoint: PyGe.Point3d, direction: PyGe.Vector3d
    '''
    ...
    def area (self, startParam : float, endParam : float, tol : float = None)-> float :
      '''Returns the area of the interval of the curve defined by startParam and endParam. Returns Adesk::kTrue if area was successfully computed to within the specified tolerance. If the curve is not planar, then the area cannot be calculated and a value of Adesk::kFalse is returned. If the points at startParam and endParam are the same, then this function returns the area of the closed curve. If the points are different, then this function connects the two points with a line segment and return the signed area between the curve and the line segment. If the line segment does not intersect the curve at any points between startParam and endParam, then the returned area is positive. If the line segment intersects the curves at any points between startParam and endParam, then the returned area is the sum of the sub-areas created by the intersection of the line segment with the curve. Each sub-area has a positive or negative area, depending on whether the curve lies above or below the line segment. The total area returned by this function can therefore be positive, negative, or 0. '''
    ...
    def boundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock3d :
      '''Returns the bounding box of the curve. The sides of the returned box are parallel to the coordinate axes. '''
    ...

    @staticmethod
    def cast (otherObject: PyGe.Entity3d)-> PyGe.Ray3d :
      '''                             '''
    ...

    @staticmethod
    def className ()-> str :
      '''                             '''
    ...
    def closestPointTo (self, other : PyGe.Point3d | PyGe.Curve3d, tol : PyGe.Tol=None)-> PyGe.Point3d :
      '''Finds the closest point on this curve to the input point. This function is the same as closestPointTo(), except that the closest point is returned as an AcGePointOnCurve3d object.'''
    ...
    def copy (self)-> PyGe.Entity3d :
      '''Returns a pointer to a copy of this entity. This copy is created using the new and it is the responsibility of the caller to delete it.'''
    ...

    @staticmethod
    def copycast (otherObject: PyGe.Entity3d)-> PyGe.Ray3d :
      '''                             '''
    ...
    def direction (self)-> PyGe.Vector3d :
      '''                             '''
    ...
    def distanceTo (self, pt : PyGe.Point3d | PyGe.Curve3d, tol : PyGe.Tol=None)-> float :
      '''Returns the distance between the input point and the closest point on this curve.'''
    ...
    def evalPoint (self, param : float, numDeriv : int = 1)-> PyGe.Point3d :
      '''Returns the point on the curve that corresponds to the input parameter value. Also returns the number of derivative vectors that are specified in numDeriv. The numDeriv parameter should not be set larger than 2.'''
    ...
    def explode (self, val : PyGe.Interval = None)-> list :
      '''Explodes the curve into its individual components. If the curve is a composite curve, then explodedCurves contains the list of component curves of the composite. If the curve is a spline, then it is exploded at the points of C1 discontinuity and explodedCurves contains a copy of each continuous sub-curve. This function returns Adesk::kTrue if the curve was exploded (that is, the curve was a composite or a discontinuous spline) and Adesk::kFalse otherwise. The number of entries returned in newExplodedCurves is always the same as the number of entries in explodedCurves. Each flag in newExplodedCurves indicates whether the corresponding curve in explodedCurves was created with the new operator. If the flag is 1, then it is the responsibility of the caller to delete the curve. If the flag is 0, the curve is deleted by gelib and the caller should not attempt to delete it. If no intrvl parameter is supplied, then the interval is taken to be the entire curve. '''
    ...
    def getClosestPointTo (self, other : PyGe.Point3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''Finds the closest point on this curve to the input point. This function is the same as closestPointTo(), except that the closest point is returned as an AcGePointOnCurve3d object.'''
    ...
    def getClosestPointsTo (self, other : PyGe.Curve3d, tol : PyGe.Tol=None)-> tuple :
      '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
    ...
    def getEndPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def getInterval (self)-> PyGe.Interval :
      '''Returns the parametric range of the curve. The function evalPoint(double) always returns a point on this curve when called with a value within the returned interval.'''
    ...
    def getLine (self)-> PyGe.Line3d :
      '''                             '''
    ...
    def getNormalPoint (self, pnt : PyGe.Point3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''Finds the point on the input curve whose normal passes through the input point. The returned point lies on a plane that also contains the input point and is perpendicular to the curve tangent at that point. The returned point is therefore at a local minimum or a local maximum from the input point. The curve does not need to be planar. If the curve is planar, the input point does not need to lie in the plane of the curve. On input, the second parameter is assumed to contain the parameter value of an initial guess. If there is more than one normal point on the curve, the returned point will be the one whose parameter value is closest to the input parameter value.'''
    ...
    def getPerpPlane (self, pt: PyGe.Point3d)-> PyGe.Plane :
      '''                             '''
    ...
    def getProjClosestPointTo (self, pt : PyGe.Point3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
    ...
    def getProjClosestPointsTo (self, pt : PyGe.Curve3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> tuple :
      '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
    ...

    @overload
    def getSamplePoints (self, numSample: int)-> tuple : ...
    @overload
    def getSamplePoints (self, fromParam: float, toParam: float, approxEps: float)-> tuple : ...
    def getSamplePoints (self, *args, **kwargs)-> tuple :
      '''Overloads:
    - numSample: int
    - fromParam: float, toParam: float, approxEps: float
    
	-Returns the specified number of points on the curve. The points are equally spaced by parameter value. So if the interval of the curve [0,1] and numSample is 5, the parameter values of the returned points are 0, 0.25, 0.5, 0.75, and 1.-'''
    ...
    def getSplitCurves (self, param : float)-> tuple :
      '''Returns two segments which are obtained by splitting the curve at the input parameter value. If the specified parameter value does not lie within the parametric interval of the curve or if it corresponds to the start point or endpoint of the curve, then piece1 and piece2 are set to null. This function uses the new to create the curve segments whose addresses are returned in piece1 and piece2. It is the responsibility of the caller to delete these objects. '''
    ...
    def getStartPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def getTrimmedOffset (self, dist : float, planeNormal : PyGe.Vector3d, extensionType : PyGe.OffsetCrvExtType, tol : PyGe.Tol=None)-> list :
      '''Returns one or more offset curves that represent the trimmed offset of the curve. The curve must be planar and planeNormal must be perpendicular to the plane of the curve. The positive direction of offset at a point on the curve is taken to be the cross product of planeNormal with the tangent vector at that point. The curve may be offset in either of two directions by specifying a positive or negative offset distance; planeNormal determines which direction is the positive direction of offset. The returned offset curves are trimmed so that they do not contain any points of self-intersection. Each curve that is returned in offsetCurveList is created with the new and it is the responsibility of the caller to delete these curves. Each curve that is returned in offsetCurveList is a connected curve and may be a composite curve if the offset curve had to be trimmed to remove self-intersecting loops. offsetCurveList only contains more than one curve if the offset operation produces multiple curves which are not connected. If the original curve contains points of C1 discontinuity and the direction of offset causes the offset curve to be disjoint (for instance, if the original curve is a composite curve that is a rectangle and the direction of offset is to the outside of the rectangle), then the offset curve is closed with an arc or a line segment, or the curves are simply extended depending on the value of extensionType.'''
    ...
    def hasEndPoint (self)-> bool :
      '''Returns Adesk::kTrue if curve has an endpoint. A return value of Adesk::kFalse means that the parametric interval of the curve does not have an upper bound. The endPnt parameter contains meaningful data only if this function returns a value of Adesk::kTrue.'''
    ...
    def hasStartPoint (self)-> bool :
      '''Returns Adesk::kTrue if curve has a start point. A return value of Adesk::kFalse means that the parametric interval of the curve does not have a lower bound. The startPnt parameter contains meaningful data only if this function returns a value of Adesk::kTrue.'''
    ...
    def intersectWith (self, other: PyGe.LinearEnt3d | PyGe.PlanarEnt, tol: PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isClosed (self, tol : PyGe.Tol=None)-> bool :
      '''Determines if start point and endpoint of curve are the same.'''
    ...
    def isColinearTo (self, pt: PyGe.LinearEnt3d, tol: PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def isCoplanarWith (self, curve : PyGe.Curve3d, tol : PyGe.Tol=None)-> tuple :
      '''Returns Adesk::kTrue if both curve are planar and lie in the same plane. The plane parameter is only valid if this function returns a value of Adesk::kTrue.'''
    ...
    def isDegenerate (self, tol : PyGe.Tol=None)-> tuple :
      '''Determines if the curve is degenerate and if so returns the type of entity which the curve degenerates into. For example, if the curve is a circle with a radius of 0 then degenerateType is set to AcGe::kPoint3d. If the curve is an ellipse with a minor radius of 0 and a major radius of 1, then degenerateType is set to AcGe::kLineSeg3d. The degenerateType parameter is only set to something meaningful when this function returns a value of Adesk::kTrue.'''
    ...
    def isEqualTo (self, val : PyGe.Entity3d, tol : PyGe.Tol=None)-> bool :
      '''Determines if two entities are equal to each other. Two entities are considered to be equal only if they are of the same type and they represent the same 3D point set. For instance, if the two entities are of types AcGeCircArc3d and AcGeEllipArc3d then they are not considered equal even if the ellipse is completely coincident with the circle. Also, two curves are not considered equal unless they have the same parameterization. For instance, two infinite coincident lines are not considered equal if they have different scaling in their parameterization. '''
    ...
    def isKindOf (self, val : PyGe.EntityId)-> bool :
      '''                             '''
    ...
    def isLinear (self, tol : PyGe.Tol=None)-> tuple :
      '''Determines if curve is linear. This function returns an infinite line even if the curve is not infinite. The line parameter contains meaningful data only if this function returns a value of Adesk::kTrue.'''
    ...
    def isNull (self)-> bool :
      '''                             '''
    ...

    @overload
    def isOn (self, pnt: PyGe.Point3d)-> tuple : ...
    @overload
    def isOn (self, pnt: PyGe.Point3d, tol: PyGe.Tol)-> tuple : ...
    @overload
    def isOn (self, param: float)-> tuple : ...
    @overload
    def isOn (self, param: float, tol: PyGe.Tol)-> tuple : ...
    @overload
    def isOn (self, plane: PyGe.Plane)-> tuple : ...
    @overload
    def isOn (self, plane: PyGe.Plane, tol: PyGe.Tol)-> tuple : ...
    def isOn (self, *args, **kwargs)-> tuple :
      '''Overloads:
    - pnt: PyGe.Point3d
    - pnt: PyGe.Point3d, tol: PyGe.Tol
    - param: float
    - param: float, tol: PyGe.Tol
    - plane: PyGe.Plane
    - plane: PyGe.Plane, tol: PyGe.Tol
    '''
    ...

    @overload
    def isParallelTo (self, line: PyGe.LinearEnt3d)-> bool : ...
    @overload
    def isParallelTo (self, line: PyGe.LinearEnt3d, tol: PyGe.Tol)-> bool : ...
    @overload
    def isParallelTo (self, line: PyGe.PlanarEnt)-> bool : ...
    @overload
    def isParallelTo (self, line: PyGe.PlanarEnt, tol: PyGe.Tol)-> bool : ...
    def isParallelTo (self, *args, **kwargs)-> bool :
      '''Overloads:
    - line: PyGe.LinearEnt3d
    - line: PyGe.LinearEnt3d, tol: PyGe.Tol
    - line: PyGe.PlanarEnt
    - line: PyGe.PlanarEnt, tol: PyGe.Tol
    '''
    ...
    def isPeriodic (self)-> tuple :
      '''Determines if the curve is periodic. The curve is periodic if and only if it is closed and the two points evalPoint(t) and evalPoint(t+period) are always the same point for all values of t.'''
    ...

    @overload
    def isPerpendicularTo (self, line: PyGe.LinearEnt3d)-> bool : ...
    @overload
    def isPerpendicularTo (self, line: PyGe.LinearEnt3d, tol: PyGe.Tol)-> bool : ...
    @overload
    def isPerpendicularTo (self, line: PyGe.PlanarEnt)-> bool : ...
    @overload
    def isPerpendicularTo (self, line: PyGe.PlanarEnt, tol: PyGe.Tol)-> bool : ...
    def isPerpendicularTo (self, *args, **kwargs)-> bool :
      '''Overloads:
    - line: PyGe.LinearEnt3d
    - line: PyGe.LinearEnt3d, tol: PyGe.Tol
    - line: PyGe.PlanarEnt
    - line: PyGe.PlanarEnt, tol: PyGe.Tol
    '''
    ...
    def isPlanar (self, tol : PyGe.Tol=None)-> tuple :
      '''Determines if curve is planar. If the curve is a line, then this function returns an arbitrary plane that contains the line. The plane parameter contains meaningful data only if this function returns a value of Adesk::kTrue. '''
    ...
    def length (self, frm : float, to : float, tol : float = None)-> float :
      '''Returns the arc length of the curve between the two parameter values.'''
    ...
    def mirror (self, val : PyGe.Plane)-> None :
      '''Transforms the entity by mirroring it across the input plane.'''
    ...
    def orthoBoundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock3d :
      '''Returns the bounding box of the curve. The sides of the returned box are parallel to the coordinate axes.'''
    ...
    def orthoProject (self, projectionPlane : PyGe.Plane, tol : PyGe.Tol=None)-> PyGe.Entity3d :
      '''Returns the entity that is the orthogonal projection of the curve onto the projection plane. The returned entity may not be of the same type as the original curve and may not even be a curve (for instance, a line projects into a point if it is orthogonal to the projection plane). The returned entity is created with the new and it is the responsibility of the caller to delete it.'''
    ...
    def overlap (self, other: PyGe.LinearEnt3d, tol: PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def paramAtLength (self, datumParam : float, length : float, posParamDir : bool=True, tol : float = default)-> float :
      '''Returns the parameter value of the point whose arc length distance (from the point with parameter value datumParam) is the input length. In other words, ift = paramAtLength (datumParam, len, posParamDir, tol) then length (t, datumParam, tol) is (approximately) equal to len. If posParamDir is set to Adesk::kTrue, then the returned parameter value is greater than datumParam. Otherwise it will be less than datumParam. '''
    ...
    def paramOf (self, pt : PyGe.Point3d, tol : PyGe.Tol=None)-> float :
      '''Returns the parameter value of pnt. This function assumes that pnt lies on the curve and does not verify this. If pnt does not lie on the curve, this function will return unpredictable results. If it is not known whether pnt lies on the curve, the user should not call this function but should instead call AcGeCurve3d::isOn (pnt, param, tol). '''
    ...
    def pointOnLine (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def projClosestPointTo (self, pt : PyGe.Point3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.Point3d :
      '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
    ...
    def projClosestPointsTo (self, pt : PyGe.Curve3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> tuple :
      '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
    ...
    def projIntersectWith (self, other: PyGe.LinearEnt3d, projDir: PyGe.Vector3d, tol: PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def project (self, projectionPlane : PyGe.Plane, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.Entity3d :
      '''Returns the entity that is the projection of the curve onto the projection plane in the specified direction. The projectDirection vector must not be parallel to the projection plane. The returned entity may not be of the same type as the original curve and may not even be a curve (for instance, a line projects into a point if it is parallel to projectDirection). The returned entity is created with the new and it is the responsibility of the caller to delete it.'''
    ...
    def reverseParam (self)-> None :
      '''Reverses the parametric direction of the curve. The point set of the curve is unchanged, but the direction of the curve is reversed.'''
    ...
    def rotateBy (self, angle : float, vec : PyGe.Vector3d, pt : PyGe.Point3d = 'origin')-> None :
      '''Rotates the entity by the input angle about the line defined by the input point and vector.'''
    ...
    def scaleBy (self, scaleFactor : float, pt : PyGe.Point3d = 'origin')-> None :
      '''Scales the entity about the input point by the input scale factor. Input scale factor must be greater than 0.'''
    ...

    @overload
    def set (self, startPoint: PyGe.Point3d, endPoint: PyGe.Point3d)-> None : ...
    @overload
    def set (self, startPoint: PyGe.Point3d, direction: PyGe.Vector3d)-> None : ...
    def set (self, *args, **kwargs)-> None :
      '''Overloads:
    - startPoint: PyGe.Point3d, endPoint: PyGe.Point3d
    - startPoint: PyGe.Point3d, direction: PyGe.Vector3d
    '''
    ...
    def setInterval (self, val : PyGe.Interval = None)-> None :
      '''Sets the domain of the curve to the input interval.'''
    ...
    def transformBy (self, val : PyGe.Matrix3d)-> None :
      '''Transforms the entity by applying the input matrix.'''
    ...
    def translateBy (self, vec : PyGe.Vector3d)-> None :
      '''Translates the entity by the input vector.'''
    ...
    def type (self)-> PyGe.EntityId :
      '''Returns the type of the entity.'''
    ...

class Scale2d(object):
    def __getitem__ (self, idx: int)-> float :
      '''                             '''
    ...
    def __imul__ (self, val: float)-> PyGe.Scale2d :
      '''                             '''
    ...

    @overload
    def __init__ (self, /)-> None : ...
    @overload
    def __init__ (self, factor: float)-> None : ...
    @overload
    def __init__ (self, xFactor: float, yFactor: float)-> None : ...
    def __init__ (self, *args, **kwargs)-> None :
      '''Overloads:
    - None: Any
    - factor: float
    - xFactor: float, yFactor: float
    '''
    ...
    def __mul__ (self, val: float)-> PyGe.Scale2d :
      '''                             '''
    ...
    def __setitem__ (self, idx: int, val: float)-> None :
      '''                             '''
    ...
    def postMultBy (self, right: PyGe.Scale2d)-> PyGe.Scale2d :
      '''                             '''
    ...
    def preMultBy (self, left: PyGe.Scale2d)-> PyGe.Scale2d :
      '''                             '''
    ...

    @overload
    def setToProduct (self, sclVec1: PyGe.Scale2d, s: float)-> PyGe.Scale2d : ...
    @overload
    def setToProduct (self, sclVec1: PyGe.Scale2d, ssclVec2: PyGe.Scale2d)-> PyGe.Scale2d : ...
    def setToProduct (self, *args, **kwargs)-> PyGe.Scale2d :
      '''Overloads:
    - sclVec1: PyGe.Scale2d, s: float
    - sclVec1: PyGe.Scale2d, ssclVec2: PyGe.Scale2d
    '''
    ...
    def sx (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def sy (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def toString (self)-> str :
      '''                             '''
    ...

class Scale3d(object):
    def __getitem__ (self, *args, **kwargs)-> float :
      '''__getitem__( (Scale3d)arg1, (int)arg2) -> float :

    C++ signature :
        double __getitem__(class AcGeScale3d,int)'''
    ...
    def __imul__ (self, *args, **kwargs)-> PyGe.Scale3d :
      '''__imul__( (Scale3d)arg1, (float)arg2) -> Scale3d :

    C++ signature :
        class AcGeScale3d {lvalue} __imul__(class AcGeScale3d {lvalue},double)

__imul__( (Scale3d)arg1, (Scale3d)arg2) -> Scale3d :

    C++ signature :
        class AcGeScale3d {lvalue} __imul__(class AcGeScale3d {lvalue},class AcGeScale3d)'''
    ...

    @overload
    def __init__ (self, /)-> None : ...
    @overload
    def __init__ (self, factor: float)-> None : ...
    @overload
    def __init__ (self, sx: float,sy: float,sz: float)-> None : ...
    def __init__ (self, *args, **kwargs)-> None :
      '''Overloads:
    - None: Any
    - factor: float
    - sx: float,sy: float,sz: float
    '''
    ...
    def __mul__ (self, *args, **kwargs)-> PyGe.Scale3d :
      '''__mul__( (Scale3d)arg1, (float)arg2) -> Scale3d :

    C++ signature :
        class AcGeScale3d __mul__(class AcGeScale3d {lvalue},double)

__mul__( (Scale3d)arg1, (Scale3d)arg2) -> Scale3d :

    C++ signature :
        class AcGeScale3d __mul__(class AcGeScale3d {lvalue},class AcGeScale3d)'''
    ...
    def __setitem__ (self, *args, **kwargs)-> None :
      '''__setitem__( (Scale3d)arg1, (int)arg2, (float)arg3) -> None :

    C++ signature :
        void __setitem__(class AcGeScale3d {lvalue},int,double)'''
    ...
    def postMultBy (self, *args, **kwargs)-> PyGe.Scale3d :
      '''postMultBy( (Scale3d)arg1, (Scale3d)arg2) -> Scale3d :

    C++ signature :
        class AcGeScale3d {lvalue} postMultBy(class AcGeScale3d {lvalue},class AcGeScale3d)'''
    ...
    def preMultBy (self, *args, **kwargs)-> PyGe.Scale3d :
      '''preMultBy( (Scale3d)arg1, (Scale3d)arg2) -> Scale3d :

    C++ signature :
        class AcGeScale3d {lvalue} preMultBy(class AcGeScale3d {lvalue},class AcGeScale3d)'''
    ...
    def setToProduct (self, *args, **kwargs)-> PyGe.Scale3d :
      '''setToProduct( (Scale3d)arg1, (Scale3d)arg2, (float)arg3) -> Scale3d :

    C++ signature :
        class AcGeScale3d {lvalue} setToProduct(class AcGeScale3d {lvalue},class AcGeScale3d,double)

setToProduct( (Scale3d)arg1, (Scale3d)arg2, (Scale3d)arg3) -> Scale3d :

    C++ signature :
        class AcGeScale3d {lvalue} setToProduct(class AcGeScale3d {lvalue},class AcGeScale3d,class AcGeScale3d)'''
    ...
    def sx (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def sy (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def sz (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def toString (self, *args, **kwargs)-> str :
      '''toString( (Scale3d)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > toString(class AcGeScale3d)'''
    ...

class Sphere(Surface):
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (float)arg2, (Point3d)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,double,class AcGePoint3d)

__init__( (object)arg1, (float)arg2, (Point3d)arg3, (Vector3d)arg4, (Vector3d)arg5, (float)arg6, (float)arg7, (float)arg8, (float)arg9) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,double,class AcGePoint3d,class AcGeVector3d,class AcGeVector3d,double,double,double,double)'''
    ...
    def cast (self, *args, **kwargs)-> PyGe.Sphere :
      '''cast( (Entity3d)arg1) -> Sphere :

    C++ signature :
        class PyGeSphere cast(class PyGeEntity3d)'''
    ...
    def center (self, *args, **kwargs)-> PyGe.Point3d :
      '''center( (Sphere)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d center(class PyGeSphere {lvalue})'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def closestPointTo (self, *args, **kwargs)-> PyGe.Point3d :
      '''closestPointTo( (Surface)arg1, (Point3d)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d closestPointTo(class PyGeSurface {lvalue},class AcGePoint3d)

closestPointTo( (Surface)arg1, (Point3d)arg2, (Tol)arg3) -> Point3d :

    C++ signature :
        class AcGePoint3d closestPointTo(class PyGeSurface {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def copy (self)-> PyGe.Entity3d :
      '''Returns a pointer to a copy of this entity. This copy is created using the new and it is the responsibility of the caller to delete it.'''
    ...
    def copycast (self, *args, **kwargs)-> PyGe.Sphere :
      '''copycast( (Entity3d)arg1) -> Sphere :

    C++ signature :
        class PyGeSphere copycast(class PyGeEntity3d)'''
    ...
    def distanceTo (self, *args, **kwargs)-> float :
      '''distanceTo( (Surface)arg1, (Point3d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeSurface {lvalue},class AcGePoint3d)

distanceTo( (Surface)arg1, (Point3d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeSurface {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def evalPoint (self, *args, **kwargs)-> PyGe.Point3d :
      '''evalPoint( (Surface)arg1, (Point2d)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d evalPoint(class PyGeSurface {lvalue},class AcGePoint2d)

evalPoint( (Surface)arg1, (Point2d)arg2, (int)arg3, (list)arg4) -> Point3d :

    C++ signature :
        class AcGePoint3d evalPoint(class PyGeSurface {lvalue},class AcGePoint2d,int,class boost::python::list {lvalue})

evalPoint( (Surface)arg1, (Point2d)arg2, (int)arg3, (list)arg4, (Vector3d)arg5) -> Point3d :

    C++ signature :
        class AcGePoint3d evalPoint(class PyGeSurface {lvalue},class AcGePoint2d,int,class boost::python::list {lvalue},class AcGeVector3d {lvalue})'''
    ...
    def getAnglesInU (self, *args, **kwargs)-> tuple :
      '''getAnglesInU( (Sphere)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple getAnglesInU(class PyGeSphere {lvalue})'''
    ...
    def getAnglesInV (self, *args, **kwargs)-> tuple :
      '''getAnglesInV( (Sphere)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple getAnglesInV(class PyGeSphere {lvalue})'''
    ...
    def intersectWith (self, *args, **kwargs)-> tuple :
      '''intersectWith( (Sphere)arg1, (LinearEnt3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeSphere {lvalue},class PyGeLinearEnt3d)

intersectWith( (Sphere)arg1, (LinearEnt3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeSphere {lvalue},class PyGeLinearEnt3d,class AcGeTol)'''
    ...
    def isClosed (self, *args, **kwargs)-> bool :
      '''isClosed( (Sphere)arg1) -> bool :

    C++ signature :
        bool isClosed(class PyGeSphere {lvalue})

isClosed( (Sphere)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosed(class PyGeSphere {lvalue},class AcGeTol)'''
    ...
    def isClosedInU (self, *args, **kwargs)-> bool :
      '''isClosedInU( (Surface)arg1) -> bool :

    C++ signature :
        bool isClosedInU(class PyGeSurface {lvalue})

isClosedInU( (Surface)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosedInU(class PyGeSurface {lvalue},class AcGeTol)'''
    ...
    def isClosedInV (self, *args, **kwargs)-> bool :
      '''isClosedInV( (Surface)arg1) -> bool :

    C++ signature :
        bool isClosedInV(class PyGeSurface {lvalue})

isClosedInV( (Surface)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosedInV(class PyGeSurface {lvalue},class AcGeTol)'''
    ...
    def isEqualTo (self, val : PyGe.Entity3d, tol : PyGe.Tol=None)-> bool :
      '''Determines if two entities are equal to each other. Two entities are considered to be equal only if they are of the same type and they represent the same 3D point set. For instance, if the two entities are of types AcGeCircArc3d and AcGeEllipArc3d then they are not considered equal even if the ellipse is completely coincident with the circle. Also, two curves are not considered equal unless they have the same parameterization. For instance, two infinite coincident lines are not considered equal if they have different scaling in their parameterization. '''
    ...
    def isKindOf (self, val : PyGe.EntityId)-> bool :
      '''                             '''
    ...
    def isNormalReversed (self, *args, **kwargs)-> bool :
      '''isNormalReversed( (Surface)arg1) -> bool :

    C++ signature :
        bool isNormalReversed(class PyGeSurface {lvalue})'''
    ...
    def isNull (self)-> bool :
      '''                             '''
    ...
    def isOn (self, *args, **kwargs)-> bool :
      '''isOn( (Surface)arg1, (Point3d)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeSurface {lvalue},class AcGePoint3d)

isOn( (Surface)arg1, (Point3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeSurface {lvalue},class AcGePoint3d,class AcGeTol)

isOn( (Surface)arg1, (Point3d)arg2, (Point2d)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeSurface {lvalue},class AcGePoint3d,class AcGePoint2d {lvalue})

isOn( (Surface)arg1, (Point3d)arg2, (Point2d)arg3, (Tol)arg4) -> bool :

    C++ signature :
        bool isOn(class PyGeSurface {lvalue},class AcGePoint3d,class AcGePoint2d {lvalue},class AcGeTol)'''
    ...
    def isOuterNormal (self, *args, **kwargs)-> bool :
      '''isOuterNormal( (Sphere)arg1) -> bool :

    C++ signature :
        bool isOuterNormal(class PyGeSphere {lvalue})'''
    ...
    def mirror (self, val : PyGe.Plane)-> None :
      '''Transforms the entity by mirroring it across the input plane.'''
    ...
    def northAxis (self, *args, **kwargs)-> PyGe.Vector3d :
      '''northAxis( (Sphere)arg1) -> Vector3d :

    C++ signature :
        class AcGeVector3d northAxis(class PyGeSphere {lvalue})'''
    ...
    def northPole (self, *args, **kwargs)-> PyGe.Point3d :
      '''northPole( (Sphere)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d northPole(class PyGeSphere {lvalue})'''
    ...
    def paramOf (self, *args, **kwargs)-> PyGe.Point2d :
      '''paramOf( (Surface)arg1, (Point3d)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d paramOf(class PyGeSurface {lvalue},class AcGePoint3d)

paramOf( (Surface)arg1, (Point3d)arg2, (Tol)arg3) -> Point2d :

    C++ signature :
        class AcGePoint2d paramOf(class PyGeSurface {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def radius (self, *args, **kwargs)-> float :
      '''radius( (Sphere)arg1) -> float :

    C++ signature :
        double radius(class PyGeSphere {lvalue})'''
    ...
    def refAxis (self, *args, **kwargs)-> PyGe.Vector3d :
      '''refAxis( (Sphere)arg1) -> Vector3d :

    C++ signature :
        class AcGeVector3d refAxis(class PyGeSphere {lvalue})'''
    ...
    def reverseNormal (self, *args, **kwargs)-> None :
      '''reverseNormal( (Surface)arg1) -> None :

    C++ signature :
        void reverseNormal(class PyGeSurface {lvalue})'''
    ...
    def rotateBy (self, angle : float, vec : PyGe.Vector3d, pt : PyGe.Point3d = 'origin')-> None :
      '''Rotates the entity by the input angle about the line defined by the input point and vector.'''
    ...
    def scaleBy (self, scaleFactor : float, pt : PyGe.Point3d = 'origin')-> None :
      '''Scales the entity about the input point by the input scale factor. Input scale factor must be greater than 0.'''
    ...
    def set (self, *args, **kwargs)-> None :
      '''set( (Sphere)arg1, (float)arg2, (Point3d)arg3) -> None :

    C++ signature :
        void set(class PyGeSphere {lvalue},double,class AcGePoint3d)

set( (Sphere)arg1, (float)arg2, (Point3d)arg3, (Vector3d)arg4, (Vector3d)arg5, (float)arg6, (float)arg7, (float)arg8, (float)arg9) -> None :

    C++ signature :
        void set(class PyGeSphere {lvalue},double,class AcGePoint3d,class AcGeVector3d,class AcGeVector3d,double,double,double,double)'''
    ...
    def setAnglesInU (self, *args, **kwargs)-> None :
      '''setAnglesInU( (Sphere)arg1, (float)arg2, (float)arg3) -> None :

    C++ signature :
        void setAnglesInU(class PyGeSphere {lvalue},double,double)'''
    ...
    def setAnglesInV (self, *args, **kwargs)-> None :
      '''setAnglesInV( (Sphere)arg1, (float)arg2, (float)arg3) -> None :

    C++ signature :
        void setAnglesInV(class PyGeSphere {lvalue},double,double)'''
    ...
    def setRadius (self, *args, **kwargs)-> None :
      '''setRadius( (Sphere)arg1, (float)arg2) -> None :

    C++ signature :
        void setRadius(class PyGeSphere {lvalue},double)'''
    ...
    def southPole (self, *args, **kwargs)-> PyGe.Point3d :
      '''southPole( (Sphere)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d southPole(class PyGeSphere {lvalue})'''
    ...
    def transformBy (self, val : PyGe.Matrix3d)-> None :
      '''Transforms the entity by applying the input matrix.'''
    ...
    def translateBy (self, vec : PyGe.Vector3d)-> None :
      '''Translates the entity by the input vector.'''
    ...
    def type (self)-> PyGe.EntityId :
      '''Returns the type of the entity.'''
    ...

class SplineEnt2d(Curve2d):
    def __init__ (self, *args, **kwargs)-> None :
      '''Raises an exception
This class cannot be instantiated from Python'''
    ...
    def area (self, startParam : float, endParam : float, tol : float = None)-> float :
      '''                             '''
    ...
    def boundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock2d :
      '''                             '''
    ...
    def cast (self, *args, **kwargs)-> PyGe.SplineEnt2d :
      '''cast( (Entity2d)arg1) -> SplineEnt2d :

    C++ signature :
        class PyGeSplineEnt2d cast(class PyGeEntity2d)'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def closestPointTo (self, other : PyGe.Point2d | PyGe.Curve2d, tol : PyGe.Tol=None)-> PyGe.Point2d :
      '''                             '''
    ...
    def continuityAtKnot (self, *args, **kwargs)-> int :
      '''continuityAtKnot( (SplineEnt2d)arg1, (int)arg2) -> int :

    C++ signature :
        int continuityAtKnot(class PyGeSplineEnt2d {lvalue},int)

continuityAtKnot( (SplineEnt2d)arg1, (int)arg2, (Tol)arg3) -> int :

    C++ signature :
        int continuityAtKnot(class PyGeSplineEnt2d {lvalue},int,class AcGeTol)'''
    ...
    def controlPointAt (self, *args, **kwargs)-> PyGe.Point2d :
      '''controlPointAt( (SplineEnt2d)arg1, (int)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d controlPointAt(class PyGeSplineEnt2d {lvalue},int)'''
    ...
    def copy (self)-> PyGe.Entity2d :
      '''                             '''
    ...
    def copycast (self, *args, **kwargs)-> PyGe.SplineEnt2d :
      '''copycast( (Entity2d)arg1) -> SplineEnt2d :

    C++ signature :
        class PyGeSplineEnt2d copycast(class PyGeEntity2d)'''
    ...
    def degree (self, *args, **kwargs)-> int :
      '''degree( (SplineEnt2d)arg1) -> int :

    C++ signature :
        int degree(class PyGeSplineEnt2d {lvalue})'''
    ...
    def distanceTo (self, pt : PyGe.Point2d | PyGe.Curve2d, tol : PyGe.Tol=None)-> float :
      '''                             '''
    ...
    def endParam (self, *args, **kwargs)-> float :
      '''endParam( (SplineEnt2d)arg1) -> float :

    C++ signature :
        double endParam(class PyGeSplineEnt2d {lvalue})'''
    ...
    def endPoint (self, *args, **kwargs)-> PyGe.Point2d :
      '''endPoint( (SplineEnt2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d endPoint(class PyGeSplineEnt2d {lvalue})'''
    ...
    def evalPoint (self, param : float, numDeriv : int = 1)-> PyGe.Point2d :
      '''                             '''
    ...
    def explode (self, val : PyGe.Interval = None)-> list :
      '''                             '''
    ...
    def getClosestPointTo (self, other : PyGe.Point2d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve2d :
      '''                             '''
    ...
    def getClosestPointsTo (self, other : PyGe.Curve2d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def getEndPoint (self)-> PyGe.Point2d :
      '''                             '''
    ...
    def getInterval (self)-> PyGe.Interval :
      '''                             '''
    ...
    def getNormalPoint (self, pnt : PyGe.Point2d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve2d :
      '''                             '''
    ...

    @overload
    def getSamplePoints (self, numSample: int)-> list : ...
    @overload
    def getSamplePoints (self, fromParam: float, toParam: float, approxEps: float)-> list : ...
    def getSamplePoints (self, *args, **kwargs)-> list :
      '''Overloads:
    - numSample: int
    - fromParam: float, toParam: float, approxEps: float
    '''
    ...
    def getSplitCurves (self, param : float)-> tuple :
      '''                             '''
    ...
    def getStartPoint (self)-> PyGe.Point2d :
      '''                             '''
    ...
    def getTrimmedOffset (self, dist : float, extensionType : PyGe.OffsetCrvExtType, tol : PyGe.Tol=None)-> list :
      '''                             '''
    ...
    def hasEndPoint (self)-> bool :
      '''                             '''
    ...
    def hasFitData (self, *args, **kwargs)-> bool :
      '''hasFitData( (SplineEnt2d)arg1) -> bool :

    C++ signature :
        bool hasFitData(class PyGeSplineEnt2d {lvalue})'''
    ...
    def hasStartPoint (self)-> bool :
      '''                             '''
    ...
    def isClosed (self, tol : PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def isDegenerate (self, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isEqualTo (self, val : PyGe.Entity2d, tol : PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def isKindOf (self, val : PyGe.EntityId)-> bool :
      '''                             '''
    ...
    def isLinear (self, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isNull (self)-> bool :
      '''                             '''
    ...
    def isOn (self, pt : float | PyGe.Point2d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isPeriodic (self)-> tuple :
      '''                             '''
    ...
    def isRational (self, *args, **kwargs)-> bool :
      '''isRational( (SplineEnt2d)arg1) -> bool :

    C++ signature :
        bool isRational(class PyGeSplineEnt2d {lvalue})'''
    ...
    def knotAt (self, *args, **kwargs)-> float :
      '''knotAt( (SplineEnt2d)arg1, (int)arg2) -> float :

    C++ signature :
        double knotAt(class PyGeSplineEnt2d {lvalue},int)'''
    ...
    def knots (self, *args, **kwargs)-> PyGe.KnotVector :
      '''knots( (SplineEnt2d)arg1) -> KnotVector :

    C++ signature :
        class PyGeKnotVector knots(class PyGeSplineEnt2d {lvalue})'''
    ...
    def length (self, frm : float, to : float, tol : float = None)-> float :
      '''                             '''
    ...
    def mirror (self, val : PyGe.Line2d)-> None :
      '''                             '''
    ...
    def numControlPoints (self, *args, **kwargs)-> int :
      '''numControlPoints( (SplineEnt2d)arg1) -> int :

    C++ signature :
        int numControlPoints(class PyGeSplineEnt2d {lvalue})'''
    ...
    def numKnots (self, *args, **kwargs)-> int :
      '''numKnots( (SplineEnt2d)arg1) -> int :

    C++ signature :
        int numKnots(class PyGeSplineEnt2d {lvalue})'''
    ...
    def order (self, *args, **kwargs)-> int :
      '''order( (SplineEnt2d)arg1) -> int :

    C++ signature :
        int order(class PyGeSplineEnt2d {lvalue})'''
    ...
    def orthoBoundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock2d :
      '''                             '''
    ...
    def paramAtLength (self, datumParam: float, length: float, posParamDir: bool=True, tol: float=None)-> float :
      '''                             '''
    ...
    def paramOf (self, pt : PyGe.Point2d, tol : PyGe.Tol=None)-> float :
      '''                             '''
    ...
    def reverseParam (self)-> None :
      '''                             '''
    ...
    def rotateBy (self, angle : float, pt : PyGe.Point3d=PyGe.Point2d.kOrgin)-> None :
      '''                             '''
    ...
    def scaleBy (self, scaleFactor : float, pt : PyGe.Point2d=PyGe.Point2d.kOrgin)-> None :
      '''                             '''
    ...
    def setControlPointAt (self, *args, **kwargs)-> None :
      '''setControlPointAt( (SplineEnt2d)arg1, (int)arg2, (Point2d)arg3) -> None :

    C++ signature :
        void setControlPointAt(class PyGeSplineEnt2d {lvalue},int,class AcGePoint2d)'''
    ...
    def setInterval (self, val : PyGe.Interval = None)-> None :
      '''                             '''
    ...
    def setKnotAt (self, *args, **kwargs)-> None :
      '''setKnotAt( (SplineEnt2d)arg1, (int)arg2, (float)arg3) -> None :

    C++ signature :
        void setKnotAt(class PyGeSplineEnt2d {lvalue},int,double)'''
    ...
    def startParam (self, *args, **kwargs)-> float :
      '''startParam( (SplineEnt2d)arg1) -> float :

    C++ signature :
        double startParam(class PyGeSplineEnt2d {lvalue})'''
    ...
    def startPoint (self, *args, **kwargs)-> PyGe.Point2d :
      '''startPoint( (SplineEnt2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d startPoint(class PyGeSplineEnt2d {lvalue})'''
    ...
    def transformBy (self, val : PyGe.Matrix2d)-> None :
      '''                             '''
    ...
    def translateBy (self, vec : PyGe.Vector2d)-> None :
      '''                             '''
    ...
    def type (self)-> PyGe.EntityId :
      '''                             '''
    ...

class SplineEnt3d(Curve3d):
    def __init__ (self, *args, **kwargs)-> None :
      '''Raises an exception
This class cannot be instantiated from Python'''
    ...
    def area (self, startParam : float, endParam : float, tol : float = None)-> float :
      '''Returns the area of the interval of the curve defined by startParam and endParam. Returns Adesk::kTrue if area was successfully computed to within the specified tolerance. If the curve is not planar, then the area cannot be calculated and a value of Adesk::kFalse is returned. If the points at startParam and endParam are the same, then this function returns the area of the closed curve. If the points are different, then this function connects the two points with a line segment and return the signed area between the curve and the line segment. If the line segment does not intersect the curve at any points between startParam and endParam, then the returned area is positive. If the line segment intersects the curves at any points between startParam and endParam, then the returned area is the sum of the sub-areas created by the intersection of the line segment with the curve. Each sub-area has a positive or negative area, depending on whether the curve lies above or below the line segment. The total area returned by this function can therefore be positive, negative, or 0. '''
    ...
    def boundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock3d :
      '''Returns the bounding box of the curve. The sides of the returned box are parallel to the coordinate axes. '''
    ...
    def cast (self, *args, **kwargs)-> PyGe.SplineEnt3d :
      '''cast( (Entity3d)arg1) -> SplineEnt3d :

    C++ signature :
        class PyGeSplineEnt3d cast(class PyGeEntity3d)'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def closestPointTo (self, other : PyGe.Point3d | PyGe.Curve3d, tol : PyGe.Tol=None)-> PyGe.Point3d :
      '''Finds the closest point on this curve to the input point. This function is the same as closestPointTo(), except that the closest point is returned as an AcGePointOnCurve3d object.'''
    ...
    def continuityAtKnot (self, *args, **kwargs)-> int :
      '''continuityAtKnot( (SplineEnt3d)arg1, (int)arg2) -> int :

    C++ signature :
        int continuityAtKnot(class PyGeSplineEnt3d {lvalue},int)

continuityAtKnot( (SplineEnt3d)arg1, (int)arg2, (Tol)arg3) -> int :

    C++ signature :
        int continuityAtKnot(class PyGeSplineEnt3d {lvalue},int,class AcGeTol)'''
    ...
    def controlPointAt (self, *args, **kwargs)-> PyGe.Point3d :
      '''controlPointAt( (SplineEnt3d)arg1, (int)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d controlPointAt(class PyGeSplineEnt3d {lvalue},int)'''
    ...
    def copy (self)-> PyGe.Entity3d :
      '''Returns a pointer to a copy of this entity. This copy is created using the new and it is the responsibility of the caller to delete it.'''
    ...
    def copycast (self, *args, **kwargs)-> PyGe.SplineEnt3d :
      '''copycast( (Entity3d)arg1) -> SplineEnt3d :

    C++ signature :
        class PyGeSplineEnt3d copycast(class PyGeEntity3d)'''
    ...
    def degree (self, *args, **kwargs)-> int :
      '''degree( (SplineEnt3d)arg1) -> int :

    C++ signature :
        int degree(class PyGeSplineEnt3d {lvalue})'''
    ...
    def distanceTo (self, pt : PyGe.Point3d | PyGe.Curve3d, tol : PyGe.Tol=None)-> float :
      '''Returns the distance between the input point and the closest point on this curve.'''
    ...
    def endParam (self, *args, **kwargs)-> float :
      '''endParam( (SplineEnt3d)arg1) -> float :

    C++ signature :
        double endParam(class PyGeSplineEnt3d {lvalue})'''
    ...
    def endPoint (self, *args, **kwargs)-> PyGe.Point3d :
      '''endPoint( (SplineEnt3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d endPoint(class PyGeSplineEnt3d {lvalue})'''
    ...
    def evalPoint (self, param : float, numDeriv : int = 1)-> PyGe.Point3d :
      '''Returns the point on the curve that corresponds to the input parameter value. Also returns the number of derivative vectors that are specified in numDeriv. The numDeriv parameter should not be set larger than 2.'''
    ...
    def explode (self, val : PyGe.Interval = None)-> list :
      '''Explodes the curve into its individual components. If the curve is a composite curve, then explodedCurves contains the list of component curves of the composite. If the curve is a spline, then it is exploded at the points of C1 discontinuity and explodedCurves contains a copy of each continuous sub-curve. This function returns Adesk::kTrue if the curve was exploded (that is, the curve was a composite or a discontinuous spline) and Adesk::kFalse otherwise. The number of entries returned in newExplodedCurves is always the same as the number of entries in explodedCurves. Each flag in newExplodedCurves indicates whether the corresponding curve in explodedCurves was created with the new operator. If the flag is 1, then it is the responsibility of the caller to delete the curve. If the flag is 0, the curve is deleted by gelib and the caller should not attempt to delete it. If no intrvl parameter is supplied, then the interval is taken to be the entire curve. '''
    ...
    def getClosestPointTo (self, other : PyGe.Point3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''Finds the closest point on this curve to the input point. This function is the same as closestPointTo(), except that the closest point is returned as an AcGePointOnCurve3d object.'''
    ...
    def getClosestPointsTo (self, other : PyGe.Curve3d, tol : PyGe.Tol=None)-> tuple :
      '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
    ...
    def getEndPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def getInterval (self)-> PyGe.Interval :
      '''Returns the parametric range of the curve. The function evalPoint(double) always returns a point on this curve when called with a value within the returned interval.'''
    ...
    def getNormalPoint (self, pnt : PyGe.Point3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''Finds the point on the input curve whose normal passes through the input point. The returned point lies on a plane that also contains the input point and is perpendicular to the curve tangent at that point. The returned point is therefore at a local minimum or a local maximum from the input point. The curve does not need to be planar. If the curve is planar, the input point does not need to lie in the plane of the curve. On input, the second parameter is assumed to contain the parameter value of an initial guess. If there is more than one normal point on the curve, the returned point will be the one whose parameter value is closest to the input parameter value.'''
    ...
    def getProjClosestPointTo (self, pt : PyGe.Point3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
    ...
    def getProjClosestPointsTo (self, pt : PyGe.Curve3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> tuple :
      '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
    ...

    @overload
    def getSamplePoints (self, numSample: int)-> tuple : ...
    @overload
    def getSamplePoints (self, fromParam: float, toParam: float, approxEps: float)-> tuple : ...
    def getSamplePoints (self, *args, **kwargs)-> tuple :
      '''Overloads:
    - numSample: int
    - fromParam: float, toParam: float, approxEps: float
    
	-Returns the specified number of points on the curve. The points are equally spaced by parameter value. So if the interval of the curve [0,1] and numSample is 5, the parameter values of the returned points are 0, 0.25, 0.5, 0.75, and 1.-'''
    ...
    def getSplitCurves (self, param : float)-> tuple :
      '''Returns two segments which are obtained by splitting the curve at the input parameter value. If the specified parameter value does not lie within the parametric interval of the curve or if it corresponds to the start point or endpoint of the curve, then piece1 and piece2 are set to null. This function uses the new to create the curve segments whose addresses are returned in piece1 and piece2. It is the responsibility of the caller to delete these objects. '''
    ...
    def getStartPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def getTrimmedOffset (self, dist : float, planeNormal : PyGe.Vector3d, extensionType : PyGe.OffsetCrvExtType, tol : PyGe.Tol=None)-> list :
      '''Returns one or more offset curves that represent the trimmed offset of the curve. The curve must be planar and planeNormal must be perpendicular to the plane of the curve. The positive direction of offset at a point on the curve is taken to be the cross product of planeNormal with the tangent vector at that point. The curve may be offset in either of two directions by specifying a positive or negative offset distance; planeNormal determines which direction is the positive direction of offset. The returned offset curves are trimmed so that they do not contain any points of self-intersection. Each curve that is returned in offsetCurveList is created with the new and it is the responsibility of the caller to delete these curves. Each curve that is returned in offsetCurveList is a connected curve and may be a composite curve if the offset curve had to be trimmed to remove self-intersecting loops. offsetCurveList only contains more than one curve if the offset operation produces multiple curves which are not connected. If the original curve contains points of C1 discontinuity and the direction of offset causes the offset curve to be disjoint (for instance, if the original curve is a composite curve that is a rectangle and the direction of offset is to the outside of the rectangle), then the offset curve is closed with an arc or a line segment, or the curves are simply extended depending on the value of extensionType.'''
    ...
    def hasEndPoint (self)-> bool :
      '''Returns Adesk::kTrue if curve has an endpoint. A return value of Adesk::kFalse means that the parametric interval of the curve does not have an upper bound. The endPnt parameter contains meaningful data only if this function returns a value of Adesk::kTrue.'''
    ...
    def hasFitData (self, *args, **kwargs)-> bool :
      '''hasFitData( (SplineEnt3d)arg1) -> bool :

    C++ signature :
        bool hasFitData(class PyGeSplineEnt3d {lvalue})'''
    ...
    def hasStartPoint (self)-> bool :
      '''Returns Adesk::kTrue if curve has a start point. A return value of Adesk::kFalse means that the parametric interval of the curve does not have a lower bound. The startPnt parameter contains meaningful data only if this function returns a value of Adesk::kTrue.'''
    ...
    def isClosed (self, tol : PyGe.Tol=None)-> bool :
      '''Determines if start point and endpoint of curve are the same.'''
    ...
    def isCoplanarWith (self, curve : PyGe.Curve3d, tol : PyGe.Tol=None)-> tuple :
      '''Returns Adesk::kTrue if both curve are planar and lie in the same plane. The plane parameter is only valid if this function returns a value of Adesk::kTrue.'''
    ...
    def isDegenerate (self, tol : PyGe.Tol=None)-> tuple :
      '''Determines if the curve is degenerate and if so returns the type of entity which the curve degenerates into. For example, if the curve is a circle with a radius of 0 then degenerateType is set to AcGe::kPoint3d. If the curve is an ellipse with a minor radius of 0 and a major radius of 1, then degenerateType is set to AcGe::kLineSeg3d. The degenerateType parameter is only set to something meaningful when this function returns a value of Adesk::kTrue.'''
    ...
    def isEqualTo (self, val : PyGe.Entity3d, tol : PyGe.Tol=None)-> bool :
      '''Determines if two entities are equal to each other. Two entities are considered to be equal only if they are of the same type and they represent the same 3D point set. For instance, if the two entities are of types AcGeCircArc3d and AcGeEllipArc3d then they are not considered equal even if the ellipse is completely coincident with the circle. Also, two curves are not considered equal unless they have the same parameterization. For instance, two infinite coincident lines are not considered equal if they have different scaling in their parameterization. '''
    ...
    def isKindOf (self, val : PyGe.EntityId)-> bool :
      '''                             '''
    ...
    def isLinear (self, tol : PyGe.Tol=None)-> tuple :
      '''Determines if curve is linear. This function returns an infinite line even if the curve is not infinite. The line parameter contains meaningful data only if this function returns a value of Adesk::kTrue.'''
    ...
    def isNull (self)-> bool :
      '''                             '''
    ...
    def isOn (self, pt : float | PyGe.Point3d, tol : PyGe.Tol=None)-> tuple :
      '''Determines if input parameter value is within valid parametric range of curve.'''
    ...
    def isPeriodic (self)-> tuple :
      '''Determines if the curve is periodic. The curve is periodic if and only if it is closed and the two points evalPoint(t) and evalPoint(t+period) are always the same point for all values of t.'''
    ...
    def isPlanar (self, tol : PyGe.Tol=None)-> tuple :
      '''Determines if curve is planar. If the curve is a line, then this function returns an arbitrary plane that contains the line. The plane parameter contains meaningful data only if this function returns a value of Adesk::kTrue. '''
    ...
    def isRational (self, *args, **kwargs)-> bool :
      '''isRational( (SplineEnt3d)arg1) -> bool :

    C++ signature :
        bool isRational(class PyGeSplineEnt3d {lvalue})'''
    ...
    def knotAt (self, *args, **kwargs)-> float :
      '''knotAt( (SplineEnt3d)arg1, (int)arg2) -> float :

    C++ signature :
        double knotAt(class PyGeSplineEnt3d {lvalue},int)'''
    ...
    def knots (self, *args, **kwargs)-> PyGe.KnotVector :
      '''knots( (SplineEnt3d)arg1) -> KnotVector :

    C++ signature :
        class PyGeKnotVector knots(class PyGeSplineEnt3d {lvalue})'''
    ...
    def length (self, frm : float, to : float, tol : float = None)-> float :
      '''Returns the arc length of the curve between the two parameter values.'''
    ...
    def mirror (self, val : PyGe.Plane)-> None :
      '''Transforms the entity by mirroring it across the input plane.'''
    ...
    def numControlPoints (self, *args, **kwargs)-> int :
      '''numControlPoints( (SplineEnt3d)arg1) -> int :

    C++ signature :
        int numControlPoints(class PyGeSplineEnt3d {lvalue})'''
    ...
    def numKnots (self, *args, **kwargs)-> int :
      '''numKnots( (SplineEnt3d)arg1) -> int :

    C++ signature :
        int numKnots(class PyGeSplineEnt3d {lvalue})'''
    ...
    def order (self, *args, **kwargs)-> int :
      '''order( (SplineEnt3d)arg1) -> int :

    C++ signature :
        int order(class PyGeSplineEnt3d {lvalue})'''
    ...
    def orthoBoundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock3d :
      '''Returns the bounding box of the curve. The sides of the returned box are parallel to the coordinate axes.'''
    ...
    def orthoProject (self, projectionPlane : PyGe.Plane, tol : PyGe.Tol=None)-> PyGe.Entity3d :
      '''Returns the entity that is the orthogonal projection of the curve onto the projection plane. The returned entity may not be of the same type as the original curve and may not even be a curve (for instance, a line projects into a point if it is orthogonal to the projection plane). The returned entity is created with the new and it is the responsibility of the caller to delete it.'''
    ...
    def paramAtLength (self, datumParam : float, length : float, posParamDir : bool=True, tol : float = default)-> float :
      '''Returns the parameter value of the point whose arc length distance (from the point with parameter value datumParam) is the input length. In other words, ift = paramAtLength (datumParam, len, posParamDir, tol) then length (t, datumParam, tol) is (approximately) equal to len. If posParamDir is set to Adesk::kTrue, then the returned parameter value is greater than datumParam. Otherwise it will be less than datumParam. '''
    ...
    def paramOf (self, pt : PyGe.Point3d, tol : PyGe.Tol=None)-> float :
      '''Returns the parameter value of pnt. This function assumes that pnt lies on the curve and does not verify this. If pnt does not lie on the curve, this function will return unpredictable results. If it is not known whether pnt lies on the curve, the user should not call this function but should instead call AcGeCurve3d::isOn (pnt, param, tol). '''
    ...
    def projClosestPointTo (self, pt : PyGe.Point3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.Point3d :
      '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
    ...
    def projClosestPointsTo (self, pt : PyGe.Curve3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> tuple :
      '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
    ...
    def project (self, projectionPlane : PyGe.Plane, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.Entity3d :
      '''Returns the entity that is the projection of the curve onto the projection plane in the specified direction. The projectDirection vector must not be parallel to the projection plane. The returned entity may not be of the same type as the original curve and may not even be a curve (for instance, a line projects into a point if it is parallel to projectDirection). The returned entity is created with the new and it is the responsibility of the caller to delete it.'''
    ...
    def reverseParam (self)-> None :
      '''Reverses the parametric direction of the curve. The point set of the curve is unchanged, but the direction of the curve is reversed.'''
    ...
    def rotateBy (self, angle : float, vec : PyGe.Vector3d, pt : PyGe.Point3d = 'origin')-> None :
      '''Rotates the entity by the input angle about the line defined by the input point and vector.'''
    ...
    def scaleBy (self, scaleFactor : float, pt : PyGe.Point3d = 'origin')-> None :
      '''Scales the entity about the input point by the input scale factor. Input scale factor must be greater than 0.'''
    ...
    def setControlPointAt (self, *args, **kwargs)-> None :
      '''setControlPointAt( (SplineEnt3d)arg1, (int)arg2, (Point3d)arg3) -> None :

    C++ signature :
        void setControlPointAt(class PyGeSplineEnt3d {lvalue},int,class AcGePoint3d)'''
    ...
    def setInterval (self, val : PyGe.Interval = None)-> None :
      '''Sets the domain of the curve to the input interval.'''
    ...
    def setKnotAt (self, *args, **kwargs)-> None :
      '''setKnotAt( (SplineEnt3d)arg1, (int)arg2, (float)arg3) -> None :

    C++ signature :
        void setKnotAt(class PyGeSplineEnt3d {lvalue},int,double)'''
    ...
    def startParam (self, *args, **kwargs)-> float :
      '''startParam( (SplineEnt3d)arg1) -> float :

    C++ signature :
        double startParam(class PyGeSplineEnt3d {lvalue})'''
    ...
    def startPoint (self, *args, **kwargs)-> PyGe.Point3d :
      '''startPoint( (SplineEnt3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d startPoint(class PyGeSplineEnt3d {lvalue})'''
    ...
    def transformBy (self, val : PyGe.Matrix3d)-> None :
      '''Transforms the entity by applying the input matrix.'''
    ...
    def translateBy (self, vec : PyGe.Vector3d)-> None :
      '''Translates the entity by the input vector.'''
    ...
    def type (self)-> PyGe.EntityId :
      '''Returns the type of the entity.'''
    ...

class SurfSurfInt(Entity3d):
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (Surface)arg2, (Surface)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class PyGeSurface,class PyGeSurface)

__init__( (object)arg1, (Surface)arg2, (Surface)arg3, (Tol)arg4) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class PyGeSurface,class PyGeSurface,class AcGeTol)'''
    ...
    def cast (self, *args, **kwargs)-> PyGe.SurfSurfInt :
      '''cast( (Entity3d)arg1) -> SurfSurfInt :

    C++ signature :
        class PyGeSurfSurfInt cast(class PyGeEntity3d)'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def copy (self)-> PyGe.Entity3d :
      '''Returns a pointer to a copy of this entity. This copy is created using the new and it is the responsibility of the caller to delete it.'''
    ...
    def copycast (self, *args, **kwargs)-> PyGe.SurfSurfInt :
      '''copycast( (Entity3d)arg1) -> SurfSurfInt :

    C++ signature :
        class PyGeSurfSurfInt copycast(class PyGeEntity3d)'''
    ...
    def getDimension (self, *args, **kwargs)-> int :
      '''getDimension( (SurfSurfInt)arg1, (int)arg2) -> int :

    C++ signature :
        int getDimension(class PyGeSurfSurfInt {lvalue},int)'''
    ...
    def getIntConfigs (self, *args, **kwargs)-> tuple :
      '''getIntConfigs( (SurfSurfInt)arg1, (int)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getIntConfigs(class PyGeSurfSurfInt {lvalue},int)'''
    ...
    def getIntPointParams (self, *args, **kwargs)-> tuple :
      '''getIntPointParams( (SurfSurfInt)arg1, (int)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getIntPointParams(class PyGeSurfSurfInt {lvalue},int)'''
    ...
    def getType (self, *args, **kwargs)-> int :
      '''getType( (SurfSurfInt)arg1, (int)arg2) -> int :

    C++ signature :
        int getType(class PyGeSurfSurfInt {lvalue},int)'''
    ...
    def intCurve (self, *args, **kwargs)-> PyGe.Curve3d :
      '''intCurve( (SurfSurfInt)arg1, (int)arg2, (bool)arg3) -> Curve3d :

    C++ signature :
        class PyGeCurve3d intCurve(class PyGeSurfSurfInt {lvalue},int,bool)'''
    ...
    def intParamCurve (self, *args, **kwargs)-> PyGe.Curve2d :
      '''intParamCurve( (SurfSurfInt)arg1, (int)arg2, (bool)arg3, (bool)arg4) -> Curve2d :

    C++ signature :
        class PyGeCurve2d intParamCurve(class PyGeSurfSurfInt {lvalue},int,bool,bool)'''
    ...
    def intPoint (self, *args, **kwargs)-> PyGe.Point3d :
      '''intPoint( (SurfSurfInt)arg1, (int)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d intPoint(class PyGeSurfSurfInt {lvalue},int)'''
    ...
    def isEqualTo (self, val : PyGe.Entity3d, tol : PyGe.Tol=None)-> bool :
      '''Determines if two entities are equal to each other. Two entities are considered to be equal only if they are of the same type and they represent the same 3D point set. For instance, if the two entities are of types AcGeCircArc3d and AcGeEllipArc3d then they are not considered equal even if the ellipse is completely coincident with the circle. Also, two curves are not considered equal unless they have the same parameterization. For instance, two infinite coincident lines are not considered equal if they have different scaling in their parameterization. '''
    ...
    def isKindOf (self, val : PyGe.EntityId)-> bool :
      '''                             '''
    ...
    def isNull (self)-> bool :
      '''                             '''
    ...
    def isOn (self, pt : PyGe.Point3d, tol : PyGe.Tol=default)-> bool :
      '''Returns Adesk::kTrue if pnt lies on entity; otherwise, returns Adesk::kFalse.'''
    ...
    def mirror (self, val : PyGe.Plane)-> None :
      '''Transforms the entity by mirroring it across the input plane.'''
    ...
    def numResults (self, *args, **kwargs)-> int :
      '''numResults( (SurfSurfInt)arg1) -> int :

    C++ signature :
        int numResults(class PyGeSurfSurfInt {lvalue})'''
    ...
    def rotateBy (self, angle : float, vec : PyGe.Vector3d, pt : PyGe.Point3d = 'origin')-> None :
      '''Rotates the entity by the input angle about the line defined by the input point and vector.'''
    ...
    def scaleBy (self, scaleFactor : float, pt : PyGe.Point3d = 'origin')-> None :
      '''Scales the entity about the input point by the input scale factor. Input scale factor must be greater than 0.'''
    ...
    def set (self, *args, **kwargs)-> None :
      '''set( (SurfSurfInt)arg1, (Surface)arg2, (Surface)arg3) -> None :

    C++ signature :
        void set(class PyGeSurfSurfInt {lvalue},class PyGeSurface,class PyGeSurface)

set( (SurfSurfInt)arg1, (Surface)arg2, (Surface)arg3, (Tol)arg4) -> None :

    C++ signature :
        void set(class PyGeSurfSurfInt {lvalue},class PyGeSurface,class PyGeSurface,class AcGeTol)'''
    ...
    def surface1 (self, *args, **kwargs)-> PyDb.Surface :
      '''surface1( (SurfSurfInt)arg1) -> Surface :

    C++ signature :
        class PyGeSurface surface1(class PyGeSurfSurfInt {lvalue})'''
    ...
    def surface2 (self, *args, **kwargs)-> PyDb.Surface :
      '''surface2( (SurfSurfInt)arg1) -> Surface :

    C++ signature :
        class PyGeSurface surface2(class PyGeSurfSurfInt {lvalue})'''
    ...
    def tolerance (self, *args, **kwargs)-> PyGe.Tol :
      '''tolerance( (SurfSurfInt)arg1) -> Tol :

    C++ signature :
        class AcGeTol tolerance(class PyGeSurfSurfInt {lvalue})'''
    ...
    def transformBy (self, val : PyGe.Matrix3d)-> None :
      '''Transforms the entity by applying the input matrix.'''
    ...
    def translateBy (self, vec : PyGe.Vector3d)-> None :
      '''Translates the entity by the input vector.'''
    ...
    def type (self)-> PyGe.EntityId :
      '''Returns the type of the entity.'''
    ...

class Surface(Entity3d):
    def __init__ (self, *args, **kwargs)-> None :
      '''Raises an exception
This class cannot be instantiated from Python'''
    ...
    def cast (self, *args, **kwargs)-> PyDb.Surface :
      '''cast( (Entity3d)arg1) -> Surface :

    C++ signature :
        class PyGeSurface cast(class PyGeEntity3d)'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def closestPointTo (self, *args, **kwargs)-> PyGe.Point3d :
      '''closestPointTo( (Surface)arg1, (Point3d)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d closestPointTo(class PyGeSurface {lvalue},class AcGePoint3d)

closestPointTo( (Surface)arg1, (Point3d)arg2, (Tol)arg3) -> Point3d :

    C++ signature :
        class AcGePoint3d closestPointTo(class PyGeSurface {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def copy (self)-> PyGe.Entity3d :
      '''Returns a pointer to a copy of this entity. This copy is created using the new and it is the responsibility of the caller to delete it.'''
    ...
    def copycast (self, *args, **kwargs)-> PyDb.Surface :
      '''copycast( (Entity3d)arg1) -> Surface :

    C++ signature :
        class PyGeSurface copycast(class PyGeEntity3d)'''
    ...
    def distanceTo (self, *args, **kwargs)-> float :
      '''distanceTo( (Surface)arg1, (Point3d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeSurface {lvalue},class AcGePoint3d)

distanceTo( (Surface)arg1, (Point3d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeSurface {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def evalPoint (self, *args, **kwargs)-> PyGe.Point3d :
      '''evalPoint( (Surface)arg1, (Point2d)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d evalPoint(class PyGeSurface {lvalue},class AcGePoint2d)

evalPoint( (Surface)arg1, (Point2d)arg2, (int)arg3, (list)arg4) -> Point3d :

    C++ signature :
        class AcGePoint3d evalPoint(class PyGeSurface {lvalue},class AcGePoint2d,int,class boost::python::list {lvalue})

evalPoint( (Surface)arg1, (Point2d)arg2, (int)arg3, (list)arg4, (Vector3d)arg5) -> Point3d :

    C++ signature :
        class AcGePoint3d evalPoint(class PyGeSurface {lvalue},class AcGePoint2d,int,class boost::python::list {lvalue},class AcGeVector3d {lvalue})'''
    ...
    def isClosedInU (self, *args, **kwargs)-> bool :
      '''isClosedInU( (Surface)arg1) -> bool :

    C++ signature :
        bool isClosedInU(class PyGeSurface {lvalue})

isClosedInU( (Surface)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosedInU(class PyGeSurface {lvalue},class AcGeTol)'''
    ...
    def isClosedInV (self, *args, **kwargs)-> bool :
      '''isClosedInV( (Surface)arg1) -> bool :

    C++ signature :
        bool isClosedInV(class PyGeSurface {lvalue})

isClosedInV( (Surface)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosedInV(class PyGeSurface {lvalue},class AcGeTol)'''
    ...
    def isEqualTo (self, val : PyGe.Entity3d, tol : PyGe.Tol=None)-> bool :
      '''Determines if two entities are equal to each other. Two entities are considered to be equal only if they are of the same type and they represent the same 3D point set. For instance, if the two entities are of types AcGeCircArc3d and AcGeEllipArc3d then they are not considered equal even if the ellipse is completely coincident with the circle. Also, two curves are not considered equal unless they have the same parameterization. For instance, two infinite coincident lines are not considered equal if they have different scaling in their parameterization. '''
    ...
    def isKindOf (self, val : PyGe.EntityId)-> bool :
      '''                             '''
    ...
    def isNormalReversed (self, *args, **kwargs)-> bool :
      '''isNormalReversed( (Surface)arg1) -> bool :

    C++ signature :
        bool isNormalReversed(class PyGeSurface {lvalue})'''
    ...
    def isNull (self)-> bool :
      '''                             '''
    ...
    def isOn (self, *args, **kwargs)-> bool :
      '''isOn( (Surface)arg1, (Point3d)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeSurface {lvalue},class AcGePoint3d)

isOn( (Surface)arg1, (Point3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeSurface {lvalue},class AcGePoint3d,class AcGeTol)

isOn( (Surface)arg1, (Point3d)arg2, (Point2d)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeSurface {lvalue},class AcGePoint3d,class AcGePoint2d {lvalue})

isOn( (Surface)arg1, (Point3d)arg2, (Point2d)arg3, (Tol)arg4) -> bool :

    C++ signature :
        bool isOn(class PyGeSurface {lvalue},class AcGePoint3d,class AcGePoint2d {lvalue},class AcGeTol)'''
    ...
    def mirror (self, val : PyGe.Plane)-> None :
      '''Transforms the entity by mirroring it across the input plane.'''
    ...
    def paramOf (self, *args, **kwargs)-> PyGe.Point2d :
      '''paramOf( (Surface)arg1, (Point3d)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d paramOf(class PyGeSurface {lvalue},class AcGePoint3d)

paramOf( (Surface)arg1, (Point3d)arg2, (Tol)arg3) -> Point2d :

    C++ signature :
        class AcGePoint2d paramOf(class PyGeSurface {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def reverseNormal (self, *args, **kwargs)-> None :
      '''reverseNormal( (Surface)arg1) -> None :

    C++ signature :
        void reverseNormal(class PyGeSurface {lvalue})'''
    ...
    def rotateBy (self, angle : float, vec : PyGe.Vector3d, pt : PyGe.Point3d = 'origin')-> None :
      '''Rotates the entity by the input angle about the line defined by the input point and vector.'''
    ...
    def scaleBy (self, scaleFactor : float, pt : PyGe.Point3d = 'origin')-> None :
      '''Scales the entity about the input point by the input scale factor. Input scale factor must be greater than 0.'''
    ...
    def transformBy (self, val : PyGe.Matrix3d)-> None :
      '''Transforms the entity by applying the input matrix.'''
    ...
    def translateBy (self, vec : PyGe.Vector3d)-> None :
      '''Translates the entity by the input vector.'''
    ...
    def type (self)-> PyGe.EntityId :
      '''Returns the type of the entity.'''
    ...

class Tol(object):
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...
    def current (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def equalPoint (self)-> float :
      '''                             '''
    ...
    def equalVector (self)-> float :
      '''                             '''
    ...
    def setEqualPoint (self, val : float)-> None :
      '''                             '''
    ...
    def setEqualVector (self, val : float)-> None :
      '''                             '''
    ...

class Torus(Surface):
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...
    def cast (self, *args, **kwargs)-> PyGe.Torus :
      '''cast( (Entity3d)arg1) -> Torus :

    C++ signature :
        class PyGeTorus cast(class PyGeEntity3d)'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def closestPointTo (self, *args, **kwargs)-> PyGe.Point3d :
      '''closestPointTo( (Surface)arg1, (Point3d)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d closestPointTo(class PyGeSurface {lvalue},class AcGePoint3d)

closestPointTo( (Surface)arg1, (Point3d)arg2, (Tol)arg3) -> Point3d :

    C++ signature :
        class AcGePoint3d closestPointTo(class PyGeSurface {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def copy (self)-> PyGe.Entity3d :
      '''Returns a pointer to a copy of this entity. This copy is created using the new and it is the responsibility of the caller to delete it.'''
    ...
    def copycast (self, *args, **kwargs)-> PyGe.Torus :
      '''copycast( (Entity3d)arg1) -> Torus :

    C++ signature :
        class PyGeTorus copycast(class PyGeEntity3d)'''
    ...
    def distanceTo (self, *args, **kwargs)-> float :
      '''distanceTo( (Surface)arg1, (Point3d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeSurface {lvalue},class AcGePoint3d)

distanceTo( (Surface)arg1, (Point3d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeSurface {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def evalPoint (self, *args, **kwargs)-> PyGe.Point3d :
      '''evalPoint( (Surface)arg1, (Point2d)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d evalPoint(class PyGeSurface {lvalue},class AcGePoint2d)

evalPoint( (Surface)arg1, (Point2d)arg2, (int)arg3, (list)arg4) -> Point3d :

    C++ signature :
        class AcGePoint3d evalPoint(class PyGeSurface {lvalue},class AcGePoint2d,int,class boost::python::list {lvalue})

evalPoint( (Surface)arg1, (Point2d)arg2, (int)arg3, (list)arg4, (Vector3d)arg5) -> Point3d :

    C++ signature :
        class AcGePoint3d evalPoint(class PyGeSurface {lvalue},class AcGePoint2d,int,class boost::python::list {lvalue},class AcGeVector3d {lvalue})'''
    ...
    def isClosedInU (self, *args, **kwargs)-> bool :
      '''isClosedInU( (Surface)arg1) -> bool :

    C++ signature :
        bool isClosedInU(class PyGeSurface {lvalue})

isClosedInU( (Surface)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosedInU(class PyGeSurface {lvalue},class AcGeTol)'''
    ...
    def isClosedInV (self, *args, **kwargs)-> bool :
      '''isClosedInV( (Surface)arg1) -> bool :

    C++ signature :
        bool isClosedInV(class PyGeSurface {lvalue})

isClosedInV( (Surface)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosedInV(class PyGeSurface {lvalue},class AcGeTol)'''
    ...
    def isEqualTo (self, val : PyGe.Entity3d, tol : PyGe.Tol=None)-> bool :
      '''Determines if two entities are equal to each other. Two entities are considered to be equal only if they are of the same type and they represent the same 3D point set. For instance, if the two entities are of types AcGeCircArc3d and AcGeEllipArc3d then they are not considered equal even if the ellipse is completely coincident with the circle. Also, two curves are not considered equal unless they have the same parameterization. For instance, two infinite coincident lines are not considered equal if they have different scaling in their parameterization. '''
    ...
    def isKindOf (self, val : PyGe.EntityId)-> bool :
      '''                             '''
    ...
    def isNormalReversed (self, *args, **kwargs)-> bool :
      '''isNormalReversed( (Surface)arg1) -> bool :

    C++ signature :
        bool isNormalReversed(class PyGeSurface {lvalue})'''
    ...
    def isNull (self)-> bool :
      '''                             '''
    ...
    def isOn (self, *args, **kwargs)-> bool :
      '''isOn( (Surface)arg1, (Point3d)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeSurface {lvalue},class AcGePoint3d)

isOn( (Surface)arg1, (Point3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeSurface {lvalue},class AcGePoint3d,class AcGeTol)

isOn( (Surface)arg1, (Point3d)arg2, (Point2d)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeSurface {lvalue},class AcGePoint3d,class AcGePoint2d {lvalue})

isOn( (Surface)arg1, (Point3d)arg2, (Point2d)arg3, (Tol)arg4) -> bool :

    C++ signature :
        bool isOn(class PyGeSurface {lvalue},class AcGePoint3d,class AcGePoint2d {lvalue},class AcGeTol)'''
    ...
    def mirror (self, val : PyGe.Plane)-> None :
      '''Transforms the entity by mirroring it across the input plane.'''
    ...
    def paramOf (self, *args, **kwargs)-> PyGe.Point2d :
      '''paramOf( (Surface)arg1, (Point3d)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d paramOf(class PyGeSurface {lvalue},class AcGePoint3d)

paramOf( (Surface)arg1, (Point3d)arg2, (Tol)arg3) -> Point2d :

    C++ signature :
        class AcGePoint2d paramOf(class PyGeSurface {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def reverseNormal (self, *args, **kwargs)-> None :
      '''reverseNormal( (Surface)arg1) -> None :

    C++ signature :
        void reverseNormal(class PyGeSurface {lvalue})'''
    ...
    def rotateBy (self, angle : float, vec : PyGe.Vector3d, pt : PyGe.Point3d = 'origin')-> None :
      '''Rotates the entity by the input angle about the line defined by the input point and vector.'''
    ...
    def scaleBy (self, scaleFactor : float, pt : PyGe.Point3d = 'origin')-> None :
      '''Scales the entity about the input point by the input scale factor. Input scale factor must be greater than 0.'''
    ...
    def transformBy (self, val : PyGe.Matrix3d)-> None :
      '''Transforms the entity by applying the input matrix.'''
    ...
    def translateBy (self, vec : PyGe.Vector3d)-> None :
      '''Translates the entity by the input vector.'''
    ...
    def type (self)-> PyGe.EntityId :
      '''Returns the type of the entity.'''
    ...

class Vector2d(object):
    def __add__ (self, *args, **kwargs)-> PyGe.Vector2d :
      '''__add__( (Vector2d)arg1, (Vector2d)arg2) -> Vector2d :

    C++ signature :
        class AcGeVector2d __add__(class AcGeVector2d {lvalue},class AcGeVector2d)'''
    ...
    def __getitem__ (self, *args, **kwargs)-> float :
      '''__getitem__( (Vector2d)arg1, (int)arg2) -> float :

    C++ signature :
        double __getitem__(class AcGeVector2d,int)'''
    ...
    def __imul__ (self, *args, **kwargs)-> PyGe.Vector2d :
      '''__imul__( (Vector2d)arg1, (float)arg2) -> Vector2d :

    C++ signature :
        class AcGeVector2d {lvalue} __imul__(class AcGeVector2d {lvalue},double)'''
    ...

    @overload
    def __init__ (self, /)-> None : ...
    @overload
    def __init__ (self, x: float, y: float)-> None : ...
    def __init__ (self, *args, **kwargs)-> None :
      '''Overloads:
    - None: Any
    - x: float, y: float
    '''
    ...
    def __isub__ (self, *args, **kwargs)-> PyGe.Vector2d :
      '''__isub__( (Vector2d)arg1, (Vector2d)arg2) -> Vector2d :

    C++ signature :
        class AcGeVector2d {lvalue} __isub__(class AcGeVector2d {lvalue},class AcGeVector2d)'''
    ...
    def __itruediv__ (self, *args, **kwargs)-> PyGe.Vector2d :
      '''__itruediv__( (Vector2d)arg1, (float)arg2) -> Vector2d :

    C++ signature :
        class AcGeVector2d {lvalue} __itruediv__(class AcGeVector2d {lvalue},double)'''
    ...
    def __mul__ (self, *args, **kwargs)-> PyGe.Vector2d :
      '''__mul__( (Vector2d)arg1, (float)arg2) -> Vector2d :

    C++ signature :
        class AcGeVector2d __mul__(class AcGeVector2d {lvalue},double)'''
    ...
    def __rmul__ (self, *args, **kwargs)-> PyGe.Vector2d :
      '''__rmul__( (Vector2d)arg1, (float)arg2) -> Vector2d :

    C++ signature :
        class AcGeVector2d __rmul__(class AcGeVector2d,double)

__rmul__( (Vector2d)arg1, (Matrix2d)arg2) -> Vector2d :

    C++ signature :
        class AcGeVector2d __rmul__(class AcGeVector2d,class AcGeMatrix2d)'''
    ...
    def __setitem__ (self, *args, **kwargs)-> None :
      '''__setitem__( (Vector2d)arg1, (int)arg2, (float)arg3) -> None :

    C++ signature :
        void __setitem__(class AcGeVector2d {lvalue},int,double)'''
    ...
    def __sub__ (self, *args, **kwargs)-> PyGe.Vector2d :
      '''__sub__( (Vector2d)arg1) -> Vector2d :

    C++ signature :
        class AcGeVector2d __sub__(class AcGeVector2d {lvalue})

__sub__( (Vector2d)arg1, (Vector2d)arg2) -> Vector2d :

    C++ signature :
        class AcGeVector2d __sub__(class AcGeVector2d {lvalue},class AcGeVector2d)'''
    ...
    def __truediv__ (self, *args, **kwargs)-> PyGe.Vector2d :
      '''__truediv__( (Vector2d)arg1, (float)arg2) -> Vector2d :

    C++ signature :
        class AcGeVector2d __truediv__(class AcGeVector2d {lvalue},double)'''
    ...
    def angle (self)-> float :
      '''                             '''
    ...
    def angleTo (self, *args, **kwargs)-> float :
      '''angleTo( (Vector2d)arg1, (Vector2d)arg2) -> float :

    C++ signature :
        double angleTo(class AcGeVector2d {lvalue},class AcGeVector2d)'''
    ...
    def dotProduct (self, vec: PyGe.Vector2d)-> float :
      '''                             '''
    ...
    def isCodirectionalTo (self, *args, **kwargs)-> bool :
      '''isCodirectionalTo( (Vector2d)arg1, (Vector2d)arg2 [, (Tol)AcGeTol=<PyGe.Tol object at 0x0000015DE42E8700>]) -> bool :

    C++ signature :
        bool isCodirectionalTo(class AcGeVector2d {lvalue},class AcGeVector2d [,class AcGeTol=<PyGe.Tol object at 0x0000015DE42E8700>])'''
    ...
    def isEqualTo (self, *args, **kwargs)-> bool :
      '''isEqualTo( (Vector2d)arg1, (Vector2d)arg2 [, (Tol)AcGeTol=<PyGe.Tol object at 0x0000015DE42E8820>]) -> bool :

    C++ signature :
        bool isEqualTo(class AcGeVector2d {lvalue},class AcGeVector2d [,class AcGeTol=<PyGe.Tol object at 0x0000015DE42E8820>])'''
    ...
    def isParallelTo (self, *args, **kwargs)-> bool :
      '''isParallelTo( (Vector2d)arg1, (Vector2d)arg2 [, (Tol)AcGeTol=<PyGe.Tol object at 0x0000015DE42E8670>]) -> bool :

    C++ signature :
        bool isParallelTo(class AcGeVector2d {lvalue},class AcGeVector2d [,class AcGeTol=<PyGe.Tol object at 0x0000015DE42E8670>])'''
    ...
    def isPerpendicularTo (self, *args, **kwargs)-> bool :
      '''isPerpendicularTo( (Vector2d)arg1, (Vector2d)arg2 [, (Tol)AcGeTol=<PyGe.Tol object at 0x0000015DE42E8790>]) -> bool :

    C++ signature :
        bool isPerpendicularTo(class AcGeVector2d {lvalue},class AcGeVector2d [,class AcGeTol=<PyGe.Tol object at 0x0000015DE42E8790>])'''
    ...
    def isUnitLength (self, *args, **kwargs)-> bool :
      '''isUnitLength( (Vector2d)arg1 [, (Tol)AcGeTol=<PyGe.Tol object at 0x0000015DE42E8550>]) -> bool :

    C++ signature :
        bool isUnitLength(class AcGeVector2d {lvalue} [,class AcGeTol=<PyGe.Tol object at 0x0000015DE42E8550>])'''
    ...
    def isZeroLength (self, *args, **kwargs)-> bool :
      '''isZeroLength( (Vector2d)arg1 [, (Tol)AcGeTol=<PyGe.Tol object at 0x0000015DE42E85E0>]) -> bool :

    C++ signature :
        bool isZeroLength(class AcGeVector2d {lvalue} [,class AcGeTol=<PyGe.Tol object at 0x0000015DE42E85E0>])'''
    ...
    def kIdentity (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kXAxis (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kYAxis (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def length (self)-> float :
      '''                             '''
    ...
    def lengthSqrd (self)-> float :
      '''                             '''
    ...
    def mirror (self, *args, **kwargs)-> PyGe.Vector2d :
      '''mirror( (Vector2d)arg1, (Vector2d)arg2) -> Vector2d :

    C++ signature :
        class AcGeVector2d {lvalue} mirror(class AcGeVector2d {lvalue},class AcGeVector2d)'''
    ...
    def negate (self, *args, **kwargs)-> PyGe.Vector2d :
      '''negate( (Vector2d)arg1) -> Vector2d :

    C++ signature :
        class AcGeVector2d {lvalue} negate(class AcGeVector2d {lvalue})'''
    ...
    def normal (self, *args, **kwargs)-> PyGe.Vector2d :
      '''normal( (Vector2d)arg1 [, (Tol)AcGeTol=<PyGe.Tol object at 0x0000015DE42E8430>]) -> Vector2d :

    C++ signature :
        class AcGeVector2d normal(class AcGeVector2d {lvalue} [,class AcGeTol=<PyGe.Tol object at 0x0000015DE42E8430>])'''
    ...
    def normalize (self, *args, **kwargs)-> PyGe.Vector2d :
      '''normalize( (Vector2d)arg1 [, (Tol)AcGeTol=<PyGe.Tol object at 0x0000015DE42E84C0>]) -> Vector2d :

    C++ signature :
        class AcGeVector2d {lvalue} normalize(class AcGeVector2d {lvalue} [,class AcGeTol=<PyGe.Tol object at 0x0000015DE42E84C0>])'''
    ...
    def rotateBy (self, *args, **kwargs)-> PyGe.Vector2d :
      '''rotateBy( (Vector2d)arg1, (float)arg2) -> Vector2d :

    C++ signature :
        class AcGeVector2d {lvalue} rotateBy(class AcGeVector2d {lvalue},double)'''
    ...
    def set (self, *args, **kwargs)-> PyGe.Vector2d :
      '''set( (Vector2d)arg1, (float)arg2, (float)arg3) -> Vector2d :

    C++ signature :
        class AcGeVector2d {lvalue} set(class AcGeVector2d {lvalue},double,double)'''
    ...
    def setToProduct (self, *args, **kwargs)-> PyGe.Vector2d :
      '''setToProduct( (Vector2d)arg1, (Vector2d)arg2, (float)arg3) -> Vector2d :

    C++ signature :
        class AcGeVector2d {lvalue} setToProduct(class AcGeVector2d {lvalue},class AcGeVector2d,double)

setToProduct( (Vector2d)arg1, (Matrix2d)arg2, (Vector2d)arg3) -> Vector2d :

    C++ signature :
        class AcGeVector2d {lvalue} setToProduct(class AcGeVector2d {lvalue},class AcGeMatrix2d,class AcGeVector2d)'''
    ...
    def setToSum (self, *args, **kwargs)-> PyGe.Vector2d :
      '''setToSum( (Vector2d)arg1, (Vector2d)arg2, (Vector2d)arg3) -> Vector2d :

    C++ signature :
        class AcGeVector2d {lvalue} setToSum(class AcGeVector2d {lvalue},class AcGeVector2d,class AcGeVector2d)'''
    ...
    def toList (self, *args, **kwargs)-> list :
      '''toList( (Vector2d)arg1) -> list :

    C++ signature :
        class boost::python::list toList(class AcGeVector2d)'''
    ...
    def toString (self, *args, **kwargs)-> str :
      '''toString( (Vector2d)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > toString(class AcGeVector2d)'''
    ...
    def toTuple (self, *args, **kwargs)-> tuple :
      '''toTuple( (Vector2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple toTuple(class AcGeVector2d)'''
    ...
    def transformBy (self, *args, **kwargs)-> PyGe.Vector2d :
      '''transformBy( (Vector2d)arg1, (Matrix2d)arg2) -> Vector2d :

    C++ signature :
        class AcGeVector2d {lvalue} transformBy(class AcGeVector2d {lvalue},class AcGeMatrix2d)'''
    ...
    def x (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def y (self, *args, **kwargs)-> None :
      '''None'''
    ...

class Vector3d(object):
    def __add__ (self, *args, **kwargs)-> PyGe.Vector3d :
      '''__add__( (Vector3d)arg1, (Vector3d)arg2) -> Vector3d :

    C++ signature :
        class AcGeVector3d __add__(class AcGeVector3d {lvalue},class AcGeVector3d)'''
    ...
    def __getitem__ (self, idx: int)-> float :
      '''                             '''
    ...
    def __imul__ (self, *args, **kwargs)-> PyGe.Vector3d :
      '''__imul__( (Vector3d)arg1, (float)arg2) -> Vector3d :

    C++ signature :
        class AcGeVector3d {lvalue} __imul__(class AcGeVector3d {lvalue},double)'''
    ...

    @overload
    def __init__ (self, /)-> None : ...
    @overload
    def __init__ (self, floats: tuple[float] | list[float])-> None : ...
    @overload
    def __init__ (self, x: float,y: float,z: float)-> None : ...
    @overload
    def __init__ (self, pln: PyGe.PlanarEnt, pnt2d: PyGe.Vector2d)-> None : ...
    def __init__ (self, *args, **kwargs)-> None :
      '''Overloads:
    - None: Any
    - floats: tuple[float] | list[float]
    - x: float,y: float,z: float
    - pln: PyGe.PlanarEnt, pnt2d: PyGe.Vector2d
    '''
    ...
    def __isub__ (self, *args, **kwargs)-> PyGe.Vector3d :
      '''__isub__( (Vector3d)arg1, (Vector3d)arg2) -> Vector3d :

    C++ signature :
        class AcGeVector3d {lvalue} __isub__(class AcGeVector3d {lvalue},class AcGeVector3d)'''
    ...
    def __itruediv__ (self, *args, **kwargs)-> PyGe.Vector3d :
      '''__itruediv__( (Vector3d)arg1, (float)arg2) -> Vector3d :

    C++ signature :
        class AcGeVector3d {lvalue} __itruediv__(class AcGeVector3d {lvalue},double)'''
    ...
    def __mul__ (self, *args, **kwargs)-> PyGe.Vector3d :
      '''__mul__( (Vector3d)arg1, (float)arg2) -> Vector3d :

    C++ signature :
        class AcGeVector3d __mul__(class AcGeVector3d {lvalue},double)'''
    ...
    def __rmul__ (self, *args, **kwargs)-> PyGe.Vector3d :
      '''__rmul__( (Vector3d)arg1, (float)arg2) -> Vector3d :

    C++ signature :
        class AcGeVector3d __rmul__(class AcGeVector3d,double)

__rmul__( (Vector3d)arg1, (Matrix3d)arg2) -> Vector3d :

    C++ signature :
        class AcGeVector3d __rmul__(class AcGeVector3d,class AcGeMatrix3d)'''
    ...
    def __setitem__ (self, idx: int, val: float)-> None :
      '''                             '''
    ...
    def __sub__ (self, *args, **kwargs)-> PyGe.Vector3d :
      '''__sub__( (Vector3d)arg1, (Vector3d)arg2) -> Vector3d :

    C++ signature :
        class AcGeVector3d __sub__(class AcGeVector3d {lvalue},class AcGeVector3d)'''
    ...
    def __truediv__ (self, *args, **kwargs)-> PyGe.Vector3d :
      '''__truediv__( (Vector3d)arg1, (float)arg2) -> Vector3d :

    C++ signature :
        class AcGeVector3d __truediv__(class AcGeVector3d {lvalue},double)'''
    ...
    def angleOnPlane (self, pln: PyGe.PlanarEnt)-> float :
      '''Returns the angle between the orthogonal projection of this vector into the plane through the origin with the same normal as planar entity pln and the zeroth basis vector v0 of the planar entity pln provided by the function pln.getCoordSystem (p, v0, v1).'''
    ...
    def angleTo (self, vec: PyGe.Vector3d, ref: PyGe.Vector3d=None)-> float :
      '''Returns the angle between this vector and the vector vec in the range [0, Pi].'''
    ...
    def convert2d (self, pln: PyGe.PlanarEnt)-> PyGe.Vector2d :
      '''Returns 2D vector with the coordinates corresponding to the decomposition of this vector in the basis uAxis, vAxis in the planar entity pln, where uAxis and vAxis can be found by function call pln.get(p, uAxis, vAxis).Contract: This 3D vector is assumed to be parallel to the planar entity pln.'''
    ...
    def crossProduct (self, vec: PyGe.Vector3d)-> PyGe.Vector3d :
      '''Returns the cross product of this vector and vector vec.'''
    ...
    def dotProduct (self, vec: PyGe.Vector3d)-> float :
      '''Returns the dot product of this vector and vector v.'''
    ...
    def isCodirectionalTo (self, vec: PyGe.Vector3d, tol: PyGe.Tol=None)-> bool :
      '''Checks if this vector is codirectional to the vector vec. Namely, it checks if after normalization this vector is within the distance tol.equalVector() from the normalization of the vector vec.Returns Adesk::kTrue if this condition is met and Adesk::kFalse otherwise.'''
    ...
    def isEqualTo (self, vec: PyGe.Vector3d, tol: PyGe.Tol=None)-> bool :
      '''Checks if this vector is within the distance tol.equalVector() from the vector vec.The default value of the tolerance class tol is AcGeContext::gTol.Returns Adesk::kTrue if this condition is met and Adesk::kFalse otherwise.'''
    ...
    def isParallelTo (self, vec: PyGe.Vector3d, tol: PyGe.Tol=None)-> bool :
      '''Checks if this vector is parallel to the vector vec. Namely, it checks if after normalization (and negation, in the case of negative dot product with the vector vec), this vector is within the distance tol.equalVector() from the normalization of the vector vec.Returns Adesk::kTrue if this condition is met and Adesk::kFalse otherwise.'''
    ...
    def isPerpendicularTo (self, vec: PyGe.Vector3d, tol: PyGe.Tol=None)-> bool :
      '''Checks if this vector is perpendicular to the vector vec. Namely, it checks if after normalization the dot product of this vector with the normalization of the vector vec is less than tol.equalVector() in absolute value.Returns Adesk::kTrue if this condition is met and Adesk::kFalse otherwise.'''
    ...
    def isUnitLength (self, tol: PyGe.Tol=None)-> bool :
      '''Returns Adesk::kTrue if this vector is equal to its normalization. Returns Adesk::kFalse otherwise.'''
    ...
    def isZeroLength (self, tol: PyGe.Tol=None)-> bool :
      '''Returns Adesk::kTrue if this vector is a zero length vector, Adesk::kFalse otherwise.'''
    ...
    def kIdentity (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kXAxis (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kYAxis (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def kZAxis (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def largestElement (self)-> int :
      '''Returns the index of the largest absolute value coordinate of this vector.'''
    ...
    def length (self)-> float :
      '''Returns the Euclidean length of this vector.'''
    ...
    def lengthSqrd (self)-> float :
      '''Returns the square of the Euclidean length of this vector.'''
    ...
    def mirror (self, normalToPlane: PyGe.Vector3d)-> PyGe.Vector3d :
      '''Returns the 3D vector which is the result of mirroring of this vector with respect to the plane with the normal normalToPlane passing through the origin.'''
    ...
    def negate (self)-> PyGe.Vector3d :
      '''Negates this vector, namely sets it to be equal to the vector (-x,-y). Returns the reference to this vector.'''
    ...
    def normal (self, tol: PyGe.Tol=None)-> PyGe.Vector3d :
      '''Returns the unit vector codirectional to this vector. The vector is not normalized if its length is less than tol.equalVector(), in which case the returned vector is the same as this vector. '''
    ...
    def normalize (self)-> PyGe.Vector3d :
      '''Sets this vector to the unit vector codirectional to this vector. Returns the reference to this vector. This vector is not normalized if its length is less than tol.equalVector(), in which case it remains unchanged. The flag argument will be set to the following value to indicate if a failure may have occurred: k0This.'''
    ...
    def orthoProject (self, planeNormal: PyGe.Vector3d, tol: PyGe.Tol=None)-> PyGe.Vector3d :
      '''Returns a 3D vector which is the result of the orthogonal projection of this point into the plane with normal planeNormal passing through the origin.'''
    ...
    def perpVector (self)-> PyGe.Vector3d :
      '''Returns a vector orthogonal to this vector. The choice of the orthogonal vector is determined by the function AcGeContext::gOrthoVector.'''
    ...
    def project (self, pln: PyGe.Vector3d, dir: PyGe.Vector3d, tol: PyGe.Tol=None)-> PyGe.Vector3d :
      '''Returns the 3D vector that is the result of the parallel projection of this vector into the plane with normal planeNormal passing through the origin. The direction of projection is defined by vector projectDirection.'''
    ...
    def rotateBy (self, angle: float, axis: PyGe.Vector3d)-> PyGe.Vector3d :
      '''Returns 3D point which is the result of rotation of this vector around the line with axis passing through the origin. Rotation angle is given by the argument ang, where positive direction of rotation is defined by the right-hand rule.'''
    ...
    def rotateTo (self, vec: PyGe.Vector3d, axis: PyGe.Vector3d= PyGe.Vector3d.kIdentity)-> PyGe.Matrix3d :
      '''Returns a matrix mat such that matX this vector yields the argument vector vec. There is no unique matrix to represent a rotation from this vector to vec when they are parallel and in opposite directions. In this case, the argument axis is used (if it is perpendicular to this vector) to uniquely determine the resultant matrix. axis defaults to the zero-length vector, in which case an arbitrary (but correct) matrix will be returned that rotates this vector to vec.Contract: This vector and vec must be non-zero length.'''
    ...

    @overload
    def set (self, x: float,y: float,z: float)-> PyGe.Vector3d : ...
    @overload
    def set (self, pln: PyGe.PlanarEnt, pnt2d: PyGe.Vector2d)-> PyGe.Vector3d : ...
    def set (self, *args, **kwargs)-> PyGe.Vector3d :
      '''Overloads:
    - x: float,y: float,z: float
    - pln: PyGe.PlanarEnt, pnt2d: PyGe.Vector2d
    '''
    ...

    @overload
    def setToProduct (self, vec: PyGe.Vector2d, s: float)-> PyGe.Vector3d : ...
    @overload
    def setToProduct (self, xform: PyGe.Matrix3d, vec: PyGe.Vector3d)-> PyGe.Vector3d : ...
    def setToProduct (self, *args, **kwargs)-> PyGe.Vector3d :
      '''Overloads:
    - vec: PyGe.Vector2d, s: float
    - xform: PyGe.Matrix3d, vec: PyGe.Vector3d
    '''
    ...
    def setToSum (self, v1: PyGe.Vector3d, v2: PyGe.Vector3d)-> PyGe.Vector3d :
      '''Sets this vector to the sum of the vector v1 and vector v2. Returns the reference to this vector.'''
    ...
    def toList (self)-> list :
      '''                             '''
    ...
    def toString (self)-> str :
      '''                             '''
    ...
    def toTuple (self)-> tuple :
      '''                             '''
    ...
    def transformBy (self, xform: PyGe.Matrix3d)-> PyGe.Vector3d :
      '''Transform this vector by pre-multiplying it by the matrix leftSide. Returns the reference to this vector. Result is the same as setToProduct(leftSide, *this).'''
    ...
    def x (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def y (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def z (self, *args, **kwargs)-> None :
      '''None'''
    ...
