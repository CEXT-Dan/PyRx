import PyRx
import PyGe
import PyGi
import PyGs
import PyDb
import PyAp
import PyEd
import PyPl
from typing import overload

class AcGeError:
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def conjugate (self, *args, **kwargs)-> None :
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs)-> None :
      '''the denominator of a rational number in lowest terms'''
    ...
    def imag (self, *args, **kwargs)-> None :
      '''the imaginary part of a complex number'''
    ...
    def is_integer (self, /) :
      '''Returns True. Exists for duck type compatibility with float.is_integer.'''
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
    def numerator (self, *args, **kwargs)-> None :
      '''the numerator of a rational number in lowest terms'''
    ...
    def real (self, *args, **kwargs)-> None :
      '''the real part of a complex number'''
    ...

class AcGeKnotParameterization:
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def conjugate (self, *args, **kwargs)-> None :
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs)-> None :
      '''the denominator of a rational number in lowest terms'''
    ...
    def imag (self, *args, **kwargs)-> None :
      '''the imaginary part of a complex number'''
    ...
    def is_integer (self, /) :
      '''Returns True. Exists for duck type compatibility with float.is_integer.'''
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
    def numerator (self, *args, **kwargs)-> None :
      '''the numerator of a rational number in lowest terms'''
    ...
    def real (self, *args, **kwargs)-> None :
      '''the real part of a complex number'''
    ...

class BoundBlock2d:
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

__init__( (object)arg1, (Point2d)arg2, (Vector2d)arg3, (Vector2d)arg4) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePoint2d,class AcGeVector2d,class AcGeVector2d)'''
    ...
    def cast (self, *args, **kwargs)-> PyGe.BoundBlock2d :
      '''cast( (Entity2d)arg1) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d cast(class PyGeEntity2d)'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def contains (self, *args, **kwargs)-> bool :
      '''contains( (BoundBlock2d)arg1, (Point2d)arg2) -> bool :

    C++ signature :
        bool contains(class PyGeBoundBlock2d {lvalue},class AcGePoint2d)'''
    ...
    def copy (self, *args, **kwargs)-> PyGe.Entity2d :
      '''copy( (Entity2d)arg1) -> Entity2d :

    C++ signature :
        class PyGeEntity2d copy(class PyGeEntity2d {lvalue})'''
    ...
    def copycast (self, *args, **kwargs)-> PyGe.BoundBlock2d :
      '''copycast( (Entity2d)arg1) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d copycast(class PyGeEntity2d)'''
    ...
    def extend (self, *args, **kwargs)-> None :
      '''extend( (BoundBlock2d)arg1, (Point2d)arg2) -> None :

    C++ signature :
        void extend(class PyGeBoundBlock2d {lvalue},class AcGePoint2d)'''
    ...
    def getBasePoint (self, *args, **kwargs)-> PyGe.Point2d :
      '''getBasePoint( (BoundBlock2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d getBasePoint(class PyGeBoundBlock2d {lvalue})'''
    ...
    def getDirection1 (self, *args, **kwargs)-> PyGe.Vector2d :
      '''getDirection1( (BoundBlock2d)arg1) -> Vector2d :

    C++ signature :
        class AcGeVector2d getDirection1(class PyGeBoundBlock2d {lvalue})'''
    ...
    def getDirection2 (self, *args, **kwargs)-> PyGe.Vector2d :
      '''getDirection2( (BoundBlock2d)arg1) -> Vector2d :

    C++ signature :
        class AcGeVector2d getDirection2(class PyGeBoundBlock2d {lvalue})'''
    ...
    def getMaxPoint (self, *args, **kwargs)-> PyGe.Point2d :
      '''getMaxPoint( (BoundBlock2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d getMaxPoint(class PyGeBoundBlock2d {lvalue})'''
    ...
    def getMinPoint (self, *args, **kwargs)-> PyGe.Point2d :
      '''getMinPoint( (BoundBlock2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d getMinPoint(class PyGeBoundBlock2d {lvalue})'''
    ...
    def isBox (self, *args, **kwargs)-> bool :
      '''isBox( (BoundBlock2d)arg1) -> bool :

    C++ signature :
        bool isBox(class PyGeBoundBlock2d {lvalue})'''
    ...
    def isDisjoint (self, *args, **kwargs)-> bool :
      '''isDisjoint( (BoundBlock2d)arg1, (BoundBlock2d)arg2) -> bool :

    C++ signature :
        bool isDisjoint(class PyGeBoundBlock2d {lvalue},class PyGeBoundBlock2d)'''
    ...
    def isEqualTo (self, *args, **kwargs)-> bool :
      '''isEqualTo( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d)

isEqualTo( (Entity2d)arg1, (Entity2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d,class AcGeTol)'''
    ...
    def isKindOf (self, *args, **kwargs)-> bool :
      '''isKindOf( (Entity2d)arg1, (EntityId)arg2) -> bool :

    C++ signature :
        bool isKindOf(class PyGeEntity2d {lvalue},enum AcGe::EntityId)'''
    ...
    def isNull (self, *args, **kwargs)-> bool :
      '''isNull( (Entity2d)arg1) -> bool :

    C++ signature :
        bool isNull(class PyGeEntity2d {lvalue})'''
    ...
    def isOn (self, *args, **kwargs)-> bool :
      '''isOn( (Entity2d)arg1, (Point2d)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeEntity2d {lvalue},class AcGePoint2d)

isOn( (Entity2d)arg1, (Point2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeEntity2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def mirror (self, *args, **kwargs)-> None :
      '''mirror( (Entity2d)arg1, (Line2d)arg2) -> None :

    C++ signature :
        void mirror(class PyGeEntity2d {lvalue},class PyGeLine2d)'''
    ...
    def rotateBy (self, *args, **kwargs)-> None :
      '''rotateBy( (Entity2d)arg1, (float)arg2) -> None :

    C++ signature :
        void rotateBy(class PyGeEntity2d {lvalue},double)

rotateBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> None :

    C++ signature :
        void rotateBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def scaleBy (self, *args, **kwargs)-> None :
      '''scaleBy( (Entity2d)arg1, (float)arg2) -> None :

    C++ signature :
        void scaleBy(class PyGeEntity2d {lvalue},double)

scaleBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> None :

    C++ signature :
        void scaleBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def set (self, *args, **kwargs)-> None :
      '''set( (BoundBlock2d)arg1, (Point2d)arg2, (Point2d)arg3) -> None :

    C++ signature :
        void set(class PyGeBoundBlock2d {lvalue},class AcGePoint2d,class AcGePoint2d)

set( (BoundBlock2d)arg1, (Point2d)arg2, (Vector2d)arg3, (Vector2d)arg4) -> None :

    C++ signature :
        void set(class PyGeBoundBlock2d {lvalue},class AcGePoint2d,class AcGeVector2d,class AcGeVector2d)'''
    ...
    def setToBox (self, *args, **kwargs)-> None :
      '''setToBox( (BoundBlock2d)arg1, (bool)arg2) -> None :

    C++ signature :
        void setToBox(class PyGeBoundBlock2d {lvalue},bool)'''
    ...
    def swell (self, *args, **kwargs)-> None :
      '''swell( (BoundBlock2d)arg1, (float)arg2) -> None :

    C++ signature :
        void swell(class PyGeBoundBlock2d {lvalue},double)'''
    ...
    def transformBy (self, *args, **kwargs)-> None :
      '''transformBy( (Entity2d)arg1, (Matrix2d)arg2) -> None :

    C++ signature :
        void transformBy(class PyGeEntity2d {lvalue},class AcGeMatrix2d)'''
    ...
    def translateBy (self, *args, **kwargs)-> None :
      '''translateBy( (Entity2d)arg1, (Vector2d)arg2) -> None :

    C++ signature :
        void translateBy(class PyGeEntity2d {lvalue},class AcGeVector2d)'''
    ...
    def type (self, *args, **kwargs)-> PyGe.EntityId :
      '''type( (Entity2d)arg1) -> EntityId :

    C++ signature :
        enum AcGe::EntityId type(class PyGeEntity2d {lvalue})'''
    ...

class BoundBlock3d:
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (Point3d)arg2, (Vector3d)arg3, (Vector3d)arg4, (Vector3d)arg5) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePoint3d,class AcGeVector3d,class AcGeVector3d,class AcGeVector3d)'''
    ...
    def cast (self, *args, **kwargs)-> PyGe.BoundBlock3d :
      '''cast( (Entity3d)arg1) -> BoundBlock3d :

    C++ signature :
        class PyGeBoundBlock3d cast(class PyGeEntity3d)'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def contains (self, *args, **kwargs)-> bool :
      '''contains( (BoundBlock3d)arg1, (Point3d)arg2) -> bool :

    C++ signature :
        bool contains(class PyGeBoundBlock3d {lvalue},class AcGePoint3d)'''
    ...
    def copy (self)-> PyGe.Entity3d :
      '''                             '''
    ...
    def copycast (self, *args, **kwargs)-> PyGe.BoundBlock3d :
      '''copycast( (Entity3d)arg1) -> BoundBlock3d :

    C++ signature :
        class PyGeBoundBlock3d copycast(class PyGeEntity3d)'''
    ...
    def extend (self, *args, **kwargs)-> PyGe.BoundBlock3d :
      '''extend( (BoundBlock3d)arg1, (Point3d)arg2) -> BoundBlock3d :

    C++ signature :
        class PyGeBoundBlock3d {lvalue} extend(class PyGeBoundBlock3d {lvalue},class AcGePoint3d)'''
    ...
    def getBasePoint (self, *args, **kwargs)-> PyGe.Point3d :
      '''getBasePoint( (BoundBlock3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d getBasePoint(class PyGeBoundBlock3d {lvalue})'''
    ...
    def getDirection1 (self, *args, **kwargs)-> PyGe.Vector3d :
      '''getDirection1( (BoundBlock3d)arg1) -> Vector3d :

    C++ signature :
        class AcGeVector3d getDirection1(class PyGeBoundBlock3d {lvalue})'''
    ...
    def getDirection3 (self, *args, **kwargs)-> PyGe.Vector3d :
      '''getDirection3( (BoundBlock3d)arg1) -> Vector3d :

    C++ signature :
        class AcGeVector3d getDirection3(class PyGeBoundBlock3d {lvalue})

getDirection3( (BoundBlock3d)arg1) -> Vector3d :

    C++ signature :
        class AcGeVector3d getDirection3(class PyGeBoundBlock3d {lvalue})'''
    ...
    def getMaxPoint (self, *args, **kwargs)-> PyGe.Point3d :
      '''getMaxPoint( (BoundBlock3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d getMaxPoint(class PyGeBoundBlock3d {lvalue})'''
    ...
    def getMinPoint (self, *args, **kwargs)-> PyGe.Point3d :
      '''getMinPoint( (BoundBlock3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d getMinPoint(class PyGeBoundBlock3d {lvalue})'''
    ...
    def isBox (self, *args, **kwargs)-> bool :
      '''isBox( (BoundBlock3d)arg1) -> bool :

    C++ signature :
        bool isBox(class PyGeBoundBlock3d {lvalue})'''
    ...
    def isDisjoint (self, *args, **kwargs)-> bool :
      '''isDisjoint( (BoundBlock3d)arg1, (BoundBlock3d)arg2) -> bool :

    C++ signature :
        bool isDisjoint(class PyGeBoundBlock3d {lvalue},class PyGeBoundBlock3d)'''
    ...
    def isEqualTo (self, val : PyGe.Entity3d, tol : PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def isKindOf (self, val : PyGe.EntityId)-> bool :
      '''                             '''
    ...
    def isNull (self)-> bool :
      '''                             '''
    ...
    def isOn (self, pt : PyGe.Point3d, tol : PyGe.Tol=default)-> bool :
      '''                             '''
    ...
    def mirror (self, val : PyGe.Plane)-> None :
      '''                             '''
    ...
    def rotateBy (self, angle : double, vec : PyGe.Vector3d, pt : PyGe.Point3d = origin)-> None :
      '''                             '''
    ...
    def scaleBy (self, scaleFactor : double, pt : PyGe.Point3d = origin)-> None :
      '''                             '''
    ...
    def set (self, *args, **kwargs)-> PyGe.BoundBlock3d :
      '''set( (BoundBlock3d)arg1, (Point3d)arg2, (Point3d)arg3) -> BoundBlock3d :

    C++ signature :
        class PyGeBoundBlock3d {lvalue} set(class PyGeBoundBlock3d {lvalue},class AcGePoint3d,class AcGePoint3d)

set( (BoundBlock3d)arg1, (Point3d)arg2, (Vector3d)arg3, (Vector3d)arg4, (Vector3d)arg5) -> BoundBlock3d :

    C++ signature :
        class PyGeBoundBlock3d {lvalue} set(class PyGeBoundBlock3d {lvalue},class AcGePoint3d,class AcGeVector3d,class AcGeVector3d,class AcGeVector3d)'''
    ...
    def setToBox (self, *args, **kwargs)-> PyGe.BoundBlock3d :
      '''setToBox( (BoundBlock3d)arg1, (bool)arg2) -> BoundBlock3d :

    C++ signature :
        class PyGeBoundBlock3d {lvalue} setToBox(class PyGeBoundBlock3d {lvalue},bool)'''
    ...
    def swell (self, *args, **kwargs)-> PyGe.BoundBlock3d :
      '''swell( (BoundBlock3d)arg1, (float)arg2) -> BoundBlock3d :

    C++ signature :
        class PyGeBoundBlock3d {lvalue} swell(class PyGeBoundBlock3d {lvalue},double)'''
    ...
    def transformBy (self, val : PyGe.Matrix3d)-> None :
      '''                             '''
    ...
    def translateBy (self, vec : PyGe.Vector3d)-> None :
      '''                             '''
    ...
    def type (self)-> PyGe.EntityId :
      '''                             '''
    ...

class BoundedPlane:
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
    def closestPointToPlanarEnt (self, *args, **kwargs)-> tuple :
      '''closestPointToPlanarEnt( (PlanarEnt)arg1, (PlanarEnt)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointToPlanarEnt(class PyGePlanarEnt {lvalue},class PyGePlanarEnt)

closestPointToPlanarEnt( (PlanarEnt)arg1, (PlanarEnt)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointToPlanarEnt(class PyGePlanarEnt {lvalue},class PyGePlanarEnt,class AcGeTol)'''
    ...
    def copy (self)-> PyGe.Entity3d :
      '''                             '''
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
    def getCoefficients (self, *args, **kwargs)-> tuple :
      '''getCoefficients( (PlanarEnt)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple getCoefficients(class PyGePlanarEnt {lvalue})'''
    ...
    def getCoordSystem (self, *args, **kwargs)-> tuple :
      '''getCoordSystem( (PlanarEnt)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple getCoordSystem(class PyGePlanarEnt {lvalue})'''
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
    def isCoplanarTo (self, *args, **kwargs)-> bool :
      '''isCoplanarTo( (PlanarEnt)arg1, (PlanarEnt)arg2) -> bool :

    C++ signature :
        bool isCoplanarTo(class PyGePlanarEnt {lvalue},class PyGePlanarEnt)

isCoplanarTo( (PlanarEnt)arg1, (PlanarEnt)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isCoplanarTo(class PyGePlanarEnt {lvalue},class PyGePlanarEnt,class AcGeTol)'''
    ...
    def isEqualTo (self, val : PyGe.Entity3d, tol : PyGe.Tol=None)-> bool :
      '''                             '''
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
    def isParallelTo (self, *args, **kwargs)-> bool :
      '''isParallelTo( (PlanarEnt)arg1, (LinearEnt3d)arg2) -> bool :

    C++ signature :
        bool isParallelTo(class PyGePlanarEnt {lvalue},class PyGeLinearEnt3d)

isParallelTo( (PlanarEnt)arg1, (LinearEnt3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isParallelTo(class PyGePlanarEnt {lvalue},class PyGeLinearEnt3d,class AcGeTol)

isParallelTo( (PlanarEnt)arg1, (PlanarEnt)arg2) -> bool :

    C++ signature :
        bool isParallelTo(class PyGePlanarEnt {lvalue},class PyGePlanarEnt)

isParallelTo( (PlanarEnt)arg1, (PlanarEnt)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isParallelTo(class PyGePlanarEnt {lvalue},class PyGePlanarEnt,class AcGeTol)'''
    ...
    def isPerpendicularTo (self, *args, **kwargs)-> bool :
      '''isPerpendicularTo( (PlanarEnt)arg1, (LinearEnt3d)arg2) -> bool :

    C++ signature :
        bool isPerpendicularTo(class PyGePlanarEnt {lvalue},class PyGeLinearEnt3d)

isPerpendicularTo( (PlanarEnt)arg1, (LinearEnt3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isPerpendicularTo(class PyGePlanarEnt {lvalue},class PyGeLinearEnt3d,class AcGeTol)

isPerpendicularTo( (PlanarEnt)arg1, (PlanarEnt)arg2) -> bool :

    C++ signature :
        bool isPerpendicularTo(class PyGePlanarEnt {lvalue},class PyGePlanarEnt)

isPerpendicularTo( (PlanarEnt)arg1, (PlanarEnt)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isPerpendicularTo(class PyGePlanarEnt {lvalue},class PyGePlanarEnt,class AcGeTol)'''
    ...
    def mirror (self, val : PyGe.Plane)-> None :
      '''                             '''
    ...
    def normal (self, *args, **kwargs)-> PyGe.Vector3d :
      '''normal( (PlanarEnt)arg1) -> Vector3d :

    C++ signature :
        class AcGeVector3d normal(class PyGePlanarEnt {lvalue})'''
    ...
    def paramOf (self, *args, **kwargs)-> PyGe.Point2d :
      '''paramOf( (Surface)arg1, (Point3d)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d paramOf(class PyGeSurface {lvalue},class AcGePoint3d)

paramOf( (Surface)arg1, (Point3d)arg2, (Tol)arg3) -> Point2d :

    C++ signature :
        class AcGePoint2d paramOf(class PyGeSurface {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def pointOnPlane (self, *args, **kwargs)-> PyGe.Point3d :
      '''pointOnPlane( (PlanarEnt)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d pointOnPlane(class PyGePlanarEnt {lvalue})'''
    ...
    def reverseNormal (self, *args, **kwargs)-> None :
      '''reverseNormal( (Surface)arg1) -> None :

    C++ signature :
        void reverseNormal(class PyGeSurface {lvalue})'''
    ...
    def rotateBy (self, angle : double, vec : PyGe.Vector3d, pt : PyGe.Point3d = origin)-> None :
      '''                             '''
    ...
    def scaleBy (self, scaleFactor : double, pt : PyGe.Point3d = origin)-> None :
      '''                             '''
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
      '''                             '''
    ...
    def translateBy (self, vec : PyGe.Vector3d)-> None :
      '''                             '''
    ...
    def type (self)-> PyGe.EntityId :
      '''                             '''
    ...

class CircArc2d:
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
    def area (self, *args, **kwargs)-> float :
      '''area( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double area(class PyGeCurve2d {lvalue},double,double)

area( (Curve2d)arg1, (float)arg2, (float)arg3, (Tol)arg4) -> float :

    C++ signature :
        double area(class PyGeCurve2d {lvalue},double,double,class AcGeTol)'''
    ...
    def boundBlock (self, *args, **kwargs)-> PyGe.BoundBlock2d :
      '''boundBlock( (Curve2d)arg1) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d boundBlock(class PyGeCurve2d {lvalue})

boundBlock( (Curve2d)arg1, (Interval)arg2) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d boundBlock(class PyGeCurve2d {lvalue},class PyGeInterval)'''
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
    def closestPointTo (self, *args, **kwargs)-> PyGe.Point2d :
      '''closestPointTo( (Curve2d)arg1, (Point2d)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d closestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

closestPointTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> Point2d :

    C++ signature :
        class AcGePoint2d closestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

closestPointTo( (Curve2d)arg1, (Curve2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

closestPointTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def copy (self, *args, **kwargs)-> PyGe.Entity2d :
      '''copy( (Entity2d)arg1) -> Entity2d :

    C++ signature :
        class PyGeEntity2d copy(class PyGeEntity2d {lvalue})'''
    ...
    def copycast (self, *args, **kwargs)-> PyGe.CircArc2d :
      '''copycast( (Entity2d)arg1) -> CircArc2d :

    C++ signature :
        class PyGeCircArc2d copycast(class PyGeEntity2d)'''
    ...
    def distanceTo (self, *args, **kwargs)-> float :
      '''distanceTo( (Curve2d)arg1, (Point2d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

distanceTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

distanceTo( (Curve2d)arg1, (Curve2d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

distanceTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
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
    def evalPoint (self, *args, **kwargs)-> PyGe.Point2d :
      '''evalPoint( (Curve2d)arg1, (float)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d evalPoint(class PyGeCurve2d {lvalue},double)

evalPoint( (Curve2d)arg1, (float)arg2, (int)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple evalPoint(class PyGeCurve2d {lvalue},double,int)'''
    ...
    def explode (self, *args, **kwargs)-> list :
      '''explode( (Curve2d)arg1) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve2d {lvalue})

explode( (Curve2d)arg1, (Interval)arg2) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def getClosestPointTo (self, *args, **kwargs)-> PyGe.PointOnCurve2d :
      '''getClosestPointTo( (Curve2d)arg1, (Point2d)arg2) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getClosestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

getClosestPointTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getClosestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def getClosestPointsTo (self, *args, **kwargs)-> tuple :
      '''getClosestPointsTo( (Curve2d)arg1, (Curve2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

getClosestPointsTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def getEndPoint (self, *args, **kwargs)-> PyGe.Point2d :
      '''getEndPoint( (Curve2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d getEndPoint(class PyGeCurve2d {lvalue})'''
    ...
    def getInterval (self, *args, **kwargs)-> PyGe.Interval :
      '''getInterval( (Curve2d)arg1) -> Interval :

    C++ signature :
        class PyGeInterval getInterval(class PyGeCurve2d {lvalue})'''
    ...
    def getNormalPoint (self, *args, **kwargs)-> PyGe.PointOnCurve2d :
      '''getNormalPoint( (Curve2d)arg1, (Point2d)arg2) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getNormalPoint(class PyGeCurve2d {lvalue},class AcGePoint2d)

getNormalPoint( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getNormalPoint(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def getSamplePoints (self, *args, **kwargs)-> list :
      '''getSamplePoints( (Curve2d)arg1, (int)arg2) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve2d {lvalue},int)

getSamplePoints( (Curve2d)arg1, (float)arg2, (float)arg3, (float)arg4) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve2d {lvalue},double,double,double)'''
    ...
    def getSplitCurves (self, *args, **kwargs)-> tuple :
      '''getSplitCurves( (Curve2d)arg1, (float)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getSplitCurves(class PyGeCurve2d {lvalue},double)'''
    ...
    def getStartPoint (self, *args, **kwargs)-> PyGe.Point2d :
      '''getStartPoint( (Curve2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d getStartPoint(class PyGeCurve2d {lvalue})'''
    ...
    def getTrimmedOffset (self, *args, **kwargs)-> list :
      '''getTrimmedOffset( (Curve2d)arg1, (float)arg2, (OffsetCrvExtType)arg3) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve2d {lvalue},double,enum AcGe::OffsetCrvExtType)

getTrimmedOffset( (Curve2d)arg1, (float)arg2, (OffsetCrvExtType)arg3, (Tol)arg4) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve2d {lvalue},double,enum AcGe::OffsetCrvExtType,class AcGeTol)'''
    ...
    def hasEndPoint (self, *args, **kwargs)-> bool :
      '''hasEndPoint( (Curve2d)arg1) -> bool :

    C++ signature :
        bool hasEndPoint(class PyGeCurve2d {lvalue})'''
    ...
    def hasStartPoint (self, *args, **kwargs)-> bool :
      '''hasStartPoint( (Curve2d)arg1) -> bool :

    C++ signature :
        bool hasStartPoint(class PyGeCurve2d {lvalue})'''
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
    def isClosed (self, *args, **kwargs)-> bool :
      '''isClosed( (Curve2d)arg1) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve2d {lvalue})

isClosed( (Curve2d)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isDegenerate (self, *args, **kwargs)-> tuple :
      '''isDegenerate( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve2d {lvalue})

isDegenerate( (Curve2d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isEqualTo (self, *args, **kwargs)-> bool :
      '''isEqualTo( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d)

isEqualTo( (Entity2d)arg1, (Entity2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d,class AcGeTol)'''
    ...
    def isInside (self, *args, **kwargs)-> bool :
      '''isInside( (CircArc2d)arg1, (Point2d)arg2) -> bool :

    C++ signature :
        bool isInside(class PyGeCircArc2d {lvalue},class AcGePoint2d)

isInside( (CircArc2d)arg1, (Point2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isInside(class PyGeCircArc2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def isKindOf (self, *args, **kwargs)-> bool :
      '''isKindOf( (Entity2d)arg1, (EntityId)arg2) -> bool :

    C++ signature :
        bool isKindOf(class PyGeEntity2d {lvalue},enum AcGe::EntityId)'''
    ...
    def isLinear (self, *args, **kwargs)-> tuple :
      '''isLinear( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve2d {lvalue})

isLinear( (Curve2d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isNull (self, *args, **kwargs)-> bool :
      '''isNull( (Entity2d)arg1) -> bool :

    C++ signature :
        bool isNull(class PyGeEntity2d {lvalue})'''
    ...
    def isOn (self, *args, **kwargs)-> tuple :
      '''isOn( (Curve2d)arg1, (Point2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isOn(class PyGeCurve2d {lvalue},class AcGePoint2d)

isOn( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple isOn(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

isOn( (Curve2d)arg1, (float)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isOn(class PyGeCurve2d {lvalue},double)

isOn( (Curve2d)arg1, (float)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple isOn(class PyGeCurve2d {lvalue},double,class AcGeTol)'''
    ...
    def isPeriodic (self, *args, **kwargs)-> tuple :
      '''isPeriodic( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isPeriodic(class PyGeCurve2d {lvalue})'''
    ...
    def length (self, *args, **kwargs)-> float :
      '''length( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double length(class PyGeCurve2d {lvalue},double,double)

length( (Curve2d)arg1, (float)arg2, (float)arg3, (float)arg4) -> float :

    C++ signature :
        double length(class PyGeCurve2d {lvalue},double,double,double)'''
    ...
    def mirror (self, *args, **kwargs)-> None :
      '''mirror( (Entity2d)arg1, (Line2d)arg2) -> None :

    C++ signature :
        void mirror(class PyGeEntity2d {lvalue},class PyGeLine2d)'''
    ...
    def orthoBoundBlock (self, *args, **kwargs)-> PyGe.BoundBlock2d :
      '''orthoBoundBlock( (Curve2d)arg1) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d orthoBoundBlock(class PyGeCurve2d {lvalue})

orthoBoundBlock( (Curve2d)arg1, (Interval)arg2) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d orthoBoundBlock(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def paramAtLength (self, *args, **kwargs)-> float :
      '''paramAtLength( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve2d {lvalue},double,double)

paramAtLength( (Curve2d)arg1, (float)arg2, (float)arg3, (bool)arg4, (float)arg5) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve2d {lvalue},double,double,bool,double)'''
    ...
    def paramOf (self, *args, **kwargs)-> float :
      '''paramOf( (Curve2d)arg1, (Point2d)arg2) -> float :

    C++ signature :
        double paramOf(class PyGeCurve2d {lvalue},class AcGePoint2d)

paramOf( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double paramOf(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
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
    def reverseParam (self, *args, **kwargs)-> None :
      '''reverseParam( (Curve2d)arg1) -> None :

    C++ signature :
        void reverseParam(class PyGeCurve2d {lvalue})'''
    ...
    def rotateBy (self, *args, **kwargs)-> None :
      '''rotateBy( (Entity2d)arg1, (float)arg2) -> None :

    C++ signature :
        void rotateBy(class PyGeEntity2d {lvalue},double)

rotateBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> None :

    C++ signature :
        void rotateBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def scaleBy (self, *args, **kwargs)-> None :
      '''scaleBy( (Entity2d)arg1, (float)arg2) -> None :

    C++ signature :
        void scaleBy(class PyGeEntity2d {lvalue},double)

scaleBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> None :

    C++ signature :
        void scaleBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
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
    def setInterval (self, *args, **kwargs)-> None :
      '''setInterval( (Curve2d)arg1) -> None :

    C++ signature :
        void setInterval(class PyGeCurve2d {lvalue})

setInterval( (Curve2d)arg1, (Interval)arg2) -> bool :

    C++ signature :
        bool setInterval(class PyGeCurve2d {lvalue},class PyGeInterval)'''
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
    def transformBy (self, *args, **kwargs)-> None :
      '''transformBy( (Entity2d)arg1, (Matrix2d)arg2) -> None :

    C++ signature :
        void transformBy(class PyGeEntity2d {lvalue},class AcGeMatrix2d)'''
    ...
    def translateBy (self, *args, **kwargs)-> None :
      '''translateBy( (Entity2d)arg1, (Vector2d)arg2) -> None :

    C++ signature :
        void translateBy(class PyGeEntity2d {lvalue},class AcGeVector2d)'''
    ...
    def type (self, *args, **kwargs)-> PyGe.EntityId :
      '''type( (Entity2d)arg1) -> EntityId :

    C++ signature :
        enum AcGe::EntityId type(class PyGeEntity2d {lvalue})'''
    ...

class CircArc3d:
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (Point3d)arg2, (Vector3d)arg3, (float)arg4) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePoint3d,class AcGeVector3d,double)

__init__( (object)arg1, (Point3d)arg2, (Vector3d)arg3, (Vector3d)arg4, (float)arg5, (float)arg6, (float)arg7) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePoint3d,class AcGeVector3d,class AcGeVector3d,double,double,double)

__init__( (object)arg1, (Point3d)arg2, (Point3d)arg3, (Point3d)arg4) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePoint3d,class AcGePoint3d,class AcGePoint3d)'''
    ...
    def area (self, startParam : float, endParam : float, tol : float = default)-> float :
      '''                             '''
    ...
    def boundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock3d :
      '''                             '''
    ...
    def cast (self, *args, **kwargs)-> PyGe.CircArc3d :
      '''cast( (Entity3d)arg1) -> CircArc3d :

    C++ signature :
        class PyGeCircArc3d cast(class PyGeEntity3d)'''
    ...
    def center (self, *args, **kwargs)-> PyGe.Point3d :
      '''center( (CircArc3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d center(class PyGeCircArc3d {lvalue})'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def closestPointTo (self, other : PyGe.Point3d | PyGe.Curve3d, tol : PyGe.Tol=None)-> PyGe.Point3d :
      '''                             '''
    ...
    def closestPointToPlane (self, *args, **kwargs)-> tuple :
      '''closestPointToPlane( (CircArc3d)arg1, (PlanarEnt)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointToPlane(class PyGeCircArc3d {lvalue},class PyGePlanarEnt)

closestPointToPlane( (CircArc3d)arg1, (PlanarEnt)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointToPlane(class PyGeCircArc3d {lvalue},class PyGePlanarEnt,class AcGeTol)'''
    ...
    def copy (self)-> PyGe.Entity3d :
      '''                             '''
    ...
    def copycast (self, *args, **kwargs)-> PyGe.CircArc3d :
      '''copycast( (Entity3d)arg1) -> CircArc3d :

    C++ signature :
        class PyGeCircArc3d copycast(class PyGeEntity3d)'''
    ...
    def distanceTo (self, pt : float | PyGe.Point3d, tol : PyGe.Tol=None)-> float :
      '''                             '''
    ...
    def endAng (self, *args, **kwargs)-> float :
      '''endAng( (CircArc3d)arg1) -> float :

    C++ signature :
        double endAng(class PyGeCircArc3d {lvalue})'''
    ...
    def endPoint (self, *args, **kwargs)-> PyGe.Point3d :
      '''endPoint( (CircArc3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d endPoint(class PyGeCircArc3d {lvalue})'''
    ...
    def evalPoint (self, param : float, numDeriv : int = 1)-> PyGe.Point3d :
      '''                             '''
    ...
    def explode (self, val : PyGe.Interval = None)-> list :
      '''                             '''
    ...
    def getClosestPointTo (self, other : PyGe.Point3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''                             '''
    ...
    def getClosestPointsTo (self, other : PyGe.Curve3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def getEndPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def getInterval (self)-> PyGe.Interval :
      '''                             '''
    ...
    def getNormalPoint (self, pnt : PyGe.Point3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''                             '''
    ...
    def getPlane (self, *args, **kwargs)-> PyGe.Plane :
      '''getPlane( (CircArc3d)arg1) -> Plane :

    C++ signature :
        class PyGePlane getPlane(class PyGeCircArc3d {lvalue})'''
    ...
    def getProjClosestPointTo (self, pt : PyGe.Point3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''                             '''
    ...
    def getProjClosestPointsTo (self, pt : PyGe.Curve3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def getSamplePoints (self, *args, **kwargs)-> list :
      '''getSamplePoints( (Curve3d)arg1, (int)arg2) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve3d {lvalue},int)

getSamplePoints( (Curve3d)arg1, (float)arg2, (float)arg3, (float)arg4) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve3d {lvalue},double,double,double)'''
    ...
    def getSplitCurves (self, param : float)-> tuple :
      '''                             '''
    ...
    def getStartPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def getTrimmedOffset (self, dist : float, planeNormal : PyGe.Vector3d, extensionType : PyGe.OffsetCrvExtType, tol : PyGe.Tol=None)-> list :
      '''                             '''
    ...
    def hasEndPoint (self)-> bool :
      '''                             '''
    ...
    def hasStartPoint (self)-> bool :
      '''                             '''
    ...
    def intersectWith (self, *args, **kwargs)-> tuple :
      '''intersectWith( (CircArc3d)arg1, (LinearEnt3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeCircArc3d {lvalue},class PyGeLinearEnt3d)

intersectWith( (CircArc3d)arg1, (LinearEnt3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeCircArc3d {lvalue},class PyGeLinearEnt3d,class AcGeTol)

intersectWith( (CircArc3d)arg1, (CircArc3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeCircArc3d {lvalue},class PyGeCircArc3d)

intersectWith( (CircArc3d)arg1, (CircArc3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeCircArc3d {lvalue},class PyGeCircArc3d,class AcGeTol)

intersectWith( (CircArc3d)arg1, (PlanarEnt)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeCircArc3d {lvalue},class PyGePlanarEnt)

intersectWith( (CircArc3d)arg1, (PlanarEnt)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeCircArc3d {lvalue},class PyGePlanarEnt,class AcGeTol)'''
    ...
    def isClosed (self, tol : PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def isCoplanarWith (self, curve : PyGe.Curve3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isDegenerate (self, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isEqualTo (self, val : PyGe.Entity3d, tol : PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def isInside (self, *args, **kwargs)-> bool :
      '''isInside( (CircArc3d)arg1, (Point3d)arg2) -> bool :

    C++ signature :
        bool isInside(class PyGeCircArc3d {lvalue},class AcGePoint3d)

isInside( (CircArc3d)arg1, (Point3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isInside(class PyGeCircArc3d {lvalue},class AcGePoint3d,class AcGeTol)'''
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
    def isOn (self, pt : float | PyGe.Point3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isPeriodic (self)-> tuple :
      '''                             '''
    ...
    def isPlanar (self, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def length (self, frm : float, to : float, tol : float = default)-> float :
      '''                             '''
    ...
    def mirror (self, val : PyGe.Plane)-> None :
      '''                             '''
    ...
    def normal (self, *args, **kwargs)-> PyGe.Vector3d :
      '''normal( (CircArc3d)arg1) -> Vector3d :

    C++ signature :
        class AcGeVector3d normal(class PyGeCircArc3d {lvalue})'''
    ...
    def orthoBoundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock3d :
      '''                             '''
    ...
    def orthoProject (self, projectionPlane : PyGe.Plane, tol : PyGe.Tol=None)-> PyGe.Entity3d :
      '''                             '''
    ...
    def paramAtLength (self, datumParam : float, length : float, posParamDir : bool=True, tol : float = default)-> float :
      '''                             '''
    ...
    def paramOf (self, pt : PyGe.Point3d, tol : PyGe.Tol=None)-> float :
      '''                             '''
    ...
    def projClosestPointTo (self, pt : PyGe.Point3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.Point3d :
      '''                             '''
    ...
    def projClosestPointsTo (self, pt : PyGe.Curve3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def projIntersectWith (self, *args, **kwargs)-> tuple :
      '''projIntersectWith( (CircArc3d)arg1, (LinearEnt3d)arg2, (Vector3d)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple projIntersectWith(class PyGeCircArc3d {lvalue},class PyGeLinearEnt3d,class AcGeVector3d)

projIntersectWith( (CircArc3d)arg1, (LinearEnt3d)arg2, (Vector3d)arg3, (Tol)arg4) -> tuple :

    C++ signature :
        class boost::python::tuple projIntersectWith(class PyGeCircArc3d {lvalue},class PyGeLinearEnt3d,class AcGeVector3d,class AcGeTol)'''
    ...
    def project (self, projectionPlane : PyGe.Plane, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.Entity3d :
      '''                             '''
    ...
    def radius (self, *args, **kwargs)-> float :
      '''radius( (CircArc3d)arg1) -> float :

    C++ signature :
        double radius(class PyGeCircArc3d {lvalue})'''
    ...
    def refVec (self, *args, **kwargs)-> PyGe.Vector3d :
      '''refVec( (CircArc3d)arg1) -> Vector3d :

    C++ signature :
        class AcGeVector3d refVec(class PyGeCircArc3d {lvalue})'''
    ...
    def reverseParam (self)-> None :
      '''                             '''
    ...
    def rotateBy (self, angle : double, vec : PyGe.Vector3d, pt : PyGe.Point3d = origin)-> None :
      '''                             '''
    ...
    def scaleBy (self, scaleFactor : double, pt : PyGe.Point3d = origin)-> None :
      '''                             '''
    ...
    def set (self, *args, **kwargs)-> None :
      '''set( (CircArc3d)arg1, (Point3d)arg2, (Vector3d)arg3, (float)arg4) -> None :

    C++ signature :
        void set(class PyGeCircArc3d {lvalue},class AcGePoint3d,class AcGeVector3d,double)

set( (CircArc3d)arg1, (Point3d)arg2, (Vector3d)arg3, (Vector3d)arg4, (float)arg5, (float)arg6, (float)arg7) -> None :

    C++ signature :
        void set(class PyGeCircArc3d {lvalue},class AcGePoint3d,class AcGeVector3d,class AcGeVector3d,double,double,double)

set( (CircArc3d)arg1, (Point3d)arg2, (Point3d)arg3, (Point3d)arg4) -> None :

    C++ signature :
        void set(class PyGeCircArc3d {lvalue},class AcGePoint3d,class AcGePoint3d,class AcGePoint3d)

set( (CircArc3d)arg1, (Curve3d)arg2, (Curve3d)arg3, (float)arg4) -> None :

    C++ signature :
        void set(class PyGeCircArc3d {lvalue},class PyGeCurve3d,class PyGeCurve3d,double)

set( (CircArc3d)arg1, (Curve3d)arg2, (Curve3d)arg3, (Curve3d)arg4) -> None :

    C++ signature :
        void set(class PyGeCircArc3d {lvalue},class PyGeCurve3d,class PyGeCurve3d,class PyGeCurve3d)'''
    ...
    def setAngles (self, *args, **kwargs)-> None :
      '''setAngles( (CircArc3d)arg1, (float)arg2, (float)arg3) -> None :

    C++ signature :
        void setAngles(class PyGeCircArc3d {lvalue},double,double)'''
    ...
    def setAxes (self, *args, **kwargs)-> None :
      '''setAxes( (CircArc3d)arg1, (Vector3d)arg2, (Vector3d)arg3) -> None :

    C++ signature :
        void setAxes(class PyGeCircArc3d {lvalue},class AcGeVector3d,class AcGeVector3d)'''
    ...
    def setCenter (self, *args, **kwargs)-> None :
      '''setCenter( (CircArc3d)arg1, (Point3d)arg2) -> None :

    C++ signature :
        void setCenter(class PyGeCircArc3d {lvalue},class AcGePoint3d)'''
    ...
    def setInterval (self, val : PyGe.Interval = None)-> None :
      '''                             '''
    ...
    def setRadius (self, *args, **kwargs)-> None :
      '''setRadius( (CircArc3d)arg1, (float)arg2) -> None :

    C++ signature :
        void setRadius(class PyGeCircArc3d {lvalue},double)'''
    ...
    def startAng (self, *args, **kwargs)-> float :
      '''startAng( (CircArc3d)arg1) -> float :

    C++ signature :
        double startAng(class PyGeCircArc3d {lvalue})'''
    ...
    def startPoint (self, *args, **kwargs)-> PyGe.Point3d :
      '''startPoint( (CircArc3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d startPoint(class PyGeCircArc3d {lvalue})'''
    ...
    def tangent (self, *args, **kwargs)-> tuple :
      '''tangent( (CircArc3d)arg1, (Point3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple tangent(class PyGeCircArc3d {lvalue},class AcGePoint3d)

tangent( (CircArc3d)arg1, (Point3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple tangent(class PyGeCircArc3d {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def transformBy (self, val : PyGe.Matrix3d)-> None :
      '''                             '''
    ...
    def translateBy (self, vec : PyGe.Vector3d)-> None :
      '''                             '''
    ...
    def type (self)-> PyGe.EntityId :
      '''                             '''
    ...

class ClipBoundary2d:
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
    def copy (self, *args, **kwargs)-> PyGe.Entity2d :
      '''copy( (Entity2d)arg1) -> Entity2d :

    C++ signature :
        class PyGeEntity2d copy(class PyGeEntity2d {lvalue})'''
    ...
    def copycast (self, *args, **kwargs)-> PyGe.ClipBoundary2d :
      '''copycast( (Entity2d)arg1) -> ClipBoundary2d :

    C++ signature :
        class PyGeClipBoundary2d copycast(class PyGeEntity2d)'''
    ...
    def isEqualTo (self, *args, **kwargs)-> bool :
      '''isEqualTo( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d)

isEqualTo( (Entity2d)arg1, (Entity2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d,class AcGeTol)'''
    ...
    def isKindOf (self, *args, **kwargs)-> bool :
      '''isKindOf( (Entity2d)arg1, (EntityId)arg2) -> bool :

    C++ signature :
        bool isKindOf(class PyGeEntity2d {lvalue},enum AcGe::EntityId)'''
    ...
    def isNull (self, *args, **kwargs)-> bool :
      '''isNull( (Entity2d)arg1) -> bool :

    C++ signature :
        bool isNull(class PyGeEntity2d {lvalue})'''
    ...
    def isOn (self, *args, **kwargs)-> bool :
      '''isOn( (Entity2d)arg1, (Point2d)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeEntity2d {lvalue},class AcGePoint2d)

isOn( (Entity2d)arg1, (Point2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeEntity2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def mirror (self, *args, **kwargs)-> None :
      '''mirror( (Entity2d)arg1, (Line2d)arg2) -> None :

    C++ signature :
        void mirror(class PyGeEntity2d {lvalue},class PyGeLine2d)'''
    ...
    def rotateBy (self, *args, **kwargs)-> None :
      '''rotateBy( (Entity2d)arg1, (float)arg2) -> None :

    C++ signature :
        void rotateBy(class PyGeEntity2d {lvalue},double)

rotateBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> None :

    C++ signature :
        void rotateBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def scaleBy (self, *args, **kwargs)-> None :
      '''scaleBy( (Entity2d)arg1, (float)arg2) -> None :

    C++ signature :
        void scaleBy(class PyGeEntity2d {lvalue},double)

scaleBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> None :

    C++ signature :
        void scaleBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def transformBy (self, *args, **kwargs)-> None :
      '''transformBy( (Entity2d)arg1, (Matrix2d)arg2) -> None :

    C++ signature :
        void transformBy(class PyGeEntity2d {lvalue},class AcGeMatrix2d)'''
    ...
    def translateBy (self, *args, **kwargs)-> None :
      '''translateBy( (Entity2d)arg1, (Vector2d)arg2) -> None :

    C++ signature :
        void translateBy(class PyGeEntity2d {lvalue},class AcGeVector2d)'''
    ...
    def type (self, *args, **kwargs)-> PyGe.EntityId :
      '''type( (Entity2d)arg1) -> EntityId :

    C++ signature :
        enum AcGe::EntityId type(class PyGeEntity2d {lvalue})'''
    ...

class CompositeCurve2d:
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...
    def area (self, *args, **kwargs)-> float :
      '''area( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double area(class PyGeCurve2d {lvalue},double,double)

area( (Curve2d)arg1, (float)arg2, (float)arg3, (Tol)arg4) -> float :

    C++ signature :
        double area(class PyGeCurve2d {lvalue},double,double,class AcGeTol)'''
    ...
    def boundBlock (self, *args, **kwargs)-> PyGe.BoundBlock2d :
      '''boundBlock( (Curve2d)arg1) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d boundBlock(class PyGeCurve2d {lvalue})

boundBlock( (Curve2d)arg1, (Interval)arg2) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d boundBlock(class PyGeCurve2d {lvalue},class PyGeInterval)'''
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
    def closestPointTo (self, *args, **kwargs)-> PyGe.Point2d :
      '''closestPointTo( (Curve2d)arg1, (Point2d)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d closestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

closestPointTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> Point2d :

    C++ signature :
        class AcGePoint2d closestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

closestPointTo( (Curve2d)arg1, (Curve2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

closestPointTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def copy (self, *args, **kwargs)-> PyGe.Entity2d :
      '''copy( (Entity2d)arg1) -> Entity2d :

    C++ signature :
        class PyGeEntity2d copy(class PyGeEntity2d {lvalue})'''
    ...
    def copycast (self, *args, **kwargs)-> PyGe.CompositeCurve2d :
      '''copycast( (Entity2d)arg1) -> CompositeCurve2d :

    C++ signature :
        class PyGeCompositeCurve2d copycast(class PyGeEntity2d)'''
    ...
    def distanceTo (self, *args, **kwargs)-> float :
      '''distanceTo( (Curve2d)arg1, (Point2d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

distanceTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

distanceTo( (Curve2d)arg1, (Curve2d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

distanceTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def evalPoint (self, *args, **kwargs)-> PyGe.Point2d :
      '''evalPoint( (Curve2d)arg1, (float)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d evalPoint(class PyGeCurve2d {lvalue},double)

evalPoint( (Curve2d)arg1, (float)arg2, (int)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple evalPoint(class PyGeCurve2d {lvalue},double,int)'''
    ...
    def explode (self, *args, **kwargs)-> list :
      '''explode( (Curve2d)arg1) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve2d {lvalue})

explode( (Curve2d)arg1, (Interval)arg2) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def getClosestPointTo (self, *args, **kwargs)-> PyGe.PointOnCurve2d :
      '''getClosestPointTo( (Curve2d)arg1, (Point2d)arg2) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getClosestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

getClosestPointTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getClosestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def getClosestPointsTo (self, *args, **kwargs)-> tuple :
      '''getClosestPointsTo( (Curve2d)arg1, (Curve2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

getClosestPointsTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def getEndPoint (self, *args, **kwargs)-> PyGe.Point2d :
      '''getEndPoint( (Curve2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d getEndPoint(class PyGeCurve2d {lvalue})'''
    ...
    def getInterval (self, *args, **kwargs)-> PyGe.Interval :
      '''getInterval( (Curve2d)arg1) -> Interval :

    C++ signature :
        class PyGeInterval getInterval(class PyGeCurve2d {lvalue})'''
    ...
    def getNormalPoint (self, *args, **kwargs)-> PyGe.PointOnCurve2d :
      '''getNormalPoint( (Curve2d)arg1, (Point2d)arg2) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getNormalPoint(class PyGeCurve2d {lvalue},class AcGePoint2d)

getNormalPoint( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getNormalPoint(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def getSamplePoints (self, *args, **kwargs)-> list :
      '''getSamplePoints( (Curve2d)arg1, (int)arg2) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve2d {lvalue},int)

getSamplePoints( (Curve2d)arg1, (float)arg2, (float)arg3, (float)arg4) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve2d {lvalue},double,double,double)'''
    ...
    def getSplitCurves (self, *args, **kwargs)-> tuple :
      '''getSplitCurves( (Curve2d)arg1, (float)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getSplitCurves(class PyGeCurve2d {lvalue},double)'''
    ...
    def getStartPoint (self, *args, **kwargs)-> PyGe.Point2d :
      '''getStartPoint( (Curve2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d getStartPoint(class PyGeCurve2d {lvalue})'''
    ...
    def getTrimmedOffset (self, *args, **kwargs)-> list :
      '''getTrimmedOffset( (Curve2d)arg1, (float)arg2, (OffsetCrvExtType)arg3) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve2d {lvalue},double,enum AcGe::OffsetCrvExtType)

getTrimmedOffset( (Curve2d)arg1, (float)arg2, (OffsetCrvExtType)arg3, (Tol)arg4) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve2d {lvalue},double,enum AcGe::OffsetCrvExtType,class AcGeTol)'''
    ...
    def hasEndPoint (self, *args, **kwargs)-> bool :
      '''hasEndPoint( (Curve2d)arg1) -> bool :

    C++ signature :
        bool hasEndPoint(class PyGeCurve2d {lvalue})'''
    ...
    def hasStartPoint (self, *args, **kwargs)-> bool :
      '''hasStartPoint( (Curve2d)arg1) -> bool :

    C++ signature :
        bool hasStartPoint(class PyGeCurve2d {lvalue})'''
    ...
    def isClosed (self, *args, **kwargs)-> bool :
      '''isClosed( (Curve2d)arg1) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve2d {lvalue})

isClosed( (Curve2d)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isDegenerate (self, *args, **kwargs)-> tuple :
      '''isDegenerate( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve2d {lvalue})

isDegenerate( (Curve2d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isEqualTo (self, *args, **kwargs)-> bool :
      '''isEqualTo( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d)

isEqualTo( (Entity2d)arg1, (Entity2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d,class AcGeTol)'''
    ...
    def isKindOf (self, *args, **kwargs)-> bool :
      '''isKindOf( (Entity2d)arg1, (EntityId)arg2) -> bool :

    C++ signature :
        bool isKindOf(class PyGeEntity2d {lvalue},enum AcGe::EntityId)'''
    ...
    def isLinear (self, *args, **kwargs)-> tuple :
      '''isLinear( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve2d {lvalue})

isLinear( (Curve2d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isNull (self, *args, **kwargs)-> bool :
      '''isNull( (Entity2d)arg1) -> bool :

    C++ signature :
        bool isNull(class PyGeEntity2d {lvalue})'''
    ...
    def isOn (self, *args, **kwargs)-> tuple :
      '''isOn( (Curve2d)arg1, (Point2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isOn(class PyGeCurve2d {lvalue},class AcGePoint2d)

isOn( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple isOn(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

isOn( (Curve2d)arg1, (float)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isOn(class PyGeCurve2d {lvalue},double)

isOn( (Curve2d)arg1, (float)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple isOn(class PyGeCurve2d {lvalue},double,class AcGeTol)'''
    ...
    def isPeriodic (self, *args, **kwargs)-> tuple :
      '''isPeriodic( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isPeriodic(class PyGeCurve2d {lvalue})'''
    ...
    def length (self, *args, **kwargs)-> float :
      '''length( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double length(class PyGeCurve2d {lvalue},double,double)

length( (Curve2d)arg1, (float)arg2, (float)arg3, (float)arg4) -> float :

    C++ signature :
        double length(class PyGeCurve2d {lvalue},double,double,double)'''
    ...
    def mirror (self, *args, **kwargs)-> None :
      '''mirror( (Entity2d)arg1, (Line2d)arg2) -> None :

    C++ signature :
        void mirror(class PyGeEntity2d {lvalue},class PyGeLine2d)'''
    ...
    def orthoBoundBlock (self, *args, **kwargs)-> PyGe.BoundBlock2d :
      '''orthoBoundBlock( (Curve2d)arg1) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d orthoBoundBlock(class PyGeCurve2d {lvalue})

orthoBoundBlock( (Curve2d)arg1, (Interval)arg2) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d orthoBoundBlock(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def paramAtLength (self, *args, **kwargs)-> float :
      '''paramAtLength( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve2d {lvalue},double,double)

paramAtLength( (Curve2d)arg1, (float)arg2, (float)arg3, (bool)arg4, (float)arg5) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve2d {lvalue},double,double,bool,double)'''
    ...
    def paramOf (self, *args, **kwargs)-> float :
      '''paramOf( (Curve2d)arg1, (Point2d)arg2) -> float :

    C++ signature :
        double paramOf(class PyGeCurve2d {lvalue},class AcGePoint2d)

paramOf( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double paramOf(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def reverseParam (self, *args, **kwargs)-> None :
      '''reverseParam( (Curve2d)arg1) -> None :

    C++ signature :
        void reverseParam(class PyGeCurve2d {lvalue})'''
    ...
    def rotateBy (self, *args, **kwargs)-> None :
      '''rotateBy( (Entity2d)arg1, (float)arg2) -> None :

    C++ signature :
        void rotateBy(class PyGeEntity2d {lvalue},double)

rotateBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> None :

    C++ signature :
        void rotateBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def scaleBy (self, *args, **kwargs)-> None :
      '''scaleBy( (Entity2d)arg1, (float)arg2) -> None :

    C++ signature :
        void scaleBy(class PyGeEntity2d {lvalue},double)

scaleBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> None :

    C++ signature :
        void scaleBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def setInterval (self, *args, **kwargs)-> None :
      '''setInterval( (Curve2d)arg1) -> None :

    C++ signature :
        void setInterval(class PyGeCurve2d {lvalue})

setInterval( (Curve2d)arg1, (Interval)arg2) -> bool :

    C++ signature :
        bool setInterval(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def transformBy (self, *args, **kwargs)-> None :
      '''transformBy( (Entity2d)arg1, (Matrix2d)arg2) -> None :

    C++ signature :
        void transformBy(class PyGeEntity2d {lvalue},class AcGeMatrix2d)'''
    ...
    def translateBy (self, *args, **kwargs)-> None :
      '''translateBy( (Entity2d)arg1, (Vector2d)arg2) -> None :

    C++ signature :
        void translateBy(class PyGeEntity2d {lvalue},class AcGeVector2d)'''
    ...
    def type (self, *args, **kwargs)-> PyGe.EntityId :
      '''type( (Entity2d)arg1) -> EntityId :

    C++ signature :
        enum AcGe::EntityId type(class PyGeEntity2d {lvalue})'''
    ...

class CompositeCurve3d:
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

__init__( (object)arg1, (list)arg2, (list)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class boost::python::list,class boost::python::list)'''
    ...
    def area (self, startParam : float, endParam : float, tol : float = default)-> float :
      '''                             '''
    ...
    def boundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock3d :
      '''                             '''
    ...
    def cast (self, *args, **kwargs)-> PyGe.CompositeCurve3d :
      '''cast( (Entity3d)arg1) -> CompositeCurve3d :

    C++ signature :
        class PyGeCompositeCurve3d cast(class PyGeEntity3d)'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def closestPointTo (self, other : PyGe.Point3d | PyGe.Curve3d, tol : PyGe.Tol=None)-> PyGe.Point3d :
      '''                             '''
    ...
    def copy (self)-> PyGe.Entity3d :
      '''                             '''
    ...
    def copycast (self, *args, **kwargs)-> PyGe.CompositeCurve3d :
      '''copycast( (Entity3d)arg1) -> CompositeCurve3d :

    C++ signature :
        class PyGeCompositeCurve3d copycast(class PyGeEntity3d)'''
    ...
    def distanceTo (self, pt : float | PyGe.Point3d, tol : PyGe.Tol=None)-> float :
      '''                             '''
    ...
    def evalPoint (self, param : float, numDeriv : int = 1)-> PyGe.Point3d :
      '''                             '''
    ...
    def explode (self, val : PyGe.Interval = None)-> list :
      '''                             '''
    ...
    def getClosestPointTo (self, other : PyGe.Point3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''                             '''
    ...
    def getClosestPointsTo (self, other : PyGe.Curve3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def getCurveList (self, *args, **kwargs)-> list :
      '''getCurveList( (CompositeCurve3d)arg1) -> list :

    C++ signature :
        class boost::python::list getCurveList(class PyGeCompositeCurve3d {lvalue})'''
    ...
    def getEndPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def getInterval (self)-> PyGe.Interval :
      '''                             '''
    ...
    def getNormalPoint (self, pnt : PyGe.Point3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''                             '''
    ...
    def getProjClosestPointTo (self, pt : PyGe.Point3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''                             '''
    ...
    def getProjClosestPointsTo (self, pt : PyGe.Curve3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def getSamplePoints (self, *args, **kwargs)-> list :
      '''getSamplePoints( (Curve3d)arg1, (int)arg2) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve3d {lvalue},int)

getSamplePoints( (Curve3d)arg1, (float)arg2, (float)arg3, (float)arg4) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve3d {lvalue},double,double,double)'''
    ...
    def getSplitCurves (self, param : float)-> tuple :
      '''                             '''
    ...
    def getStartPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def getTrimmedOffset (self, dist : float, planeNormal : PyGe.Vector3d, extensionType : PyGe.OffsetCrvExtType, tol : PyGe.Tol=None)-> list :
      '''                             '''
    ...
    def globalToLocalParam (self, *args, **kwargs)-> tuple :
      '''globalToLocalParam( (CompositeCurve3d)arg1, (float)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple globalToLocalParam(class PyGeCompositeCurve3d {lvalue},double)'''
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
    def isCoplanarWith (self, curve : PyGe.Curve3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isDegenerate (self, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isEqualTo (self, val : PyGe.Entity3d, tol : PyGe.Tol=None)-> bool :
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
    def isOn (self, pt : float | PyGe.Point3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isPeriodic (self)-> tuple :
      '''                             '''
    ...
    def isPlanar (self, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def length (self, frm : float, to : float, tol : float = default)-> float :
      '''                             '''
    ...
    def localToGlobalParam (self, *args, **kwargs)-> float :
      '''localToGlobalParam( (CompositeCurve3d)arg1, (float)arg2, (int)arg3) -> float :

    C++ signature :
        double localToGlobalParam(class PyGeCompositeCurve3d {lvalue},double,int)'''
    ...
    def mirror (self, val : PyGe.Plane)-> None :
      '''                             '''
    ...
    def orthoBoundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock3d :
      '''                             '''
    ...
    def orthoProject (self, projectionPlane : PyGe.Plane, tol : PyGe.Tol=None)-> PyGe.Entity3d :
      '''                             '''
    ...
    def paramAtLength (self, datumParam : float, length : float, posParamDir : bool=True, tol : float = default)-> float :
      '''                             '''
    ...
    def paramOf (self, pt : PyGe.Point3d, tol : PyGe.Tol=None)-> float :
      '''                             '''
    ...
    def projClosestPointTo (self, pt : PyGe.Point3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.Point3d :
      '''                             '''
    ...
    def projClosestPointsTo (self, pt : PyGe.Curve3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def project (self, projectionPlane : PyGe.Plane, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.Entity3d :
      '''                             '''
    ...
    def reverseParam (self)-> None :
      '''                             '''
    ...
    def rotateBy (self, angle : double, vec : PyGe.Vector3d, pt : PyGe.Point3d = origin)-> None :
      '''                             '''
    ...
    def scaleBy (self, scaleFactor : double, pt : PyGe.Point3d = origin)-> None :
      '''                             '''
    ...
    def setCurveList (self, *args, **kwargs)-> None :
      '''setCurveList( (CompositeCurve3d)arg1, (list)arg2) -> None :

    C++ signature :
        void setCurveList(class PyGeCompositeCurve3d {lvalue},class boost::python::list)

setCurveList( (CompositeCurve3d)arg1, (list)arg2, (list)arg3) -> None :

    C++ signature :
        void setCurveList(class PyGeCompositeCurve3d {lvalue},class boost::python::list,class boost::python::list)'''
    ...
    def setInterval (self, val : PyGe.Interval = None)-> None :
      '''                             '''
    ...
    def transformBy (self, val : PyGe.Matrix3d)-> None :
      '''                             '''
    ...
    def translateBy (self, vec : PyGe.Vector3d)-> None :
      '''                             '''
    ...
    def type (self)-> PyGe.EntityId :
      '''                             '''
    ...

class Cone:
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
      '''                             '''
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
      '''                             '''
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
    def rotateBy (self, angle : double, vec : PyGe.Vector3d, pt : PyGe.Point3d = origin)-> None :
      '''                             '''
    ...
    def scaleBy (self, scaleFactor : double, pt : PyGe.Point3d = origin)-> None :
      '''                             '''
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
      '''                             '''
    ...
    def translateBy (self, vec : PyGe.Vector3d)-> None :
      '''                             '''
    ...
    def type (self)-> PyGe.EntityId :
      '''                             '''
    ...

class CubicSplineCurve2d:
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
    def area (self, *args, **kwargs)-> float :
      '''area( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double area(class PyGeCurve2d {lvalue},double,double)

area( (Curve2d)arg1, (float)arg2, (float)arg3, (Tol)arg4) -> float :

    C++ signature :
        double area(class PyGeCurve2d {lvalue},double,double,class AcGeTol)'''
    ...
    def boundBlock (self, *args, **kwargs)-> PyGe.BoundBlock2d :
      '''boundBlock( (Curve2d)arg1) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d boundBlock(class PyGeCurve2d {lvalue})

boundBlock( (Curve2d)arg1, (Interval)arg2) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d boundBlock(class PyGeCurve2d {lvalue},class PyGeInterval)'''
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
    def closestPointTo (self, *args, **kwargs)-> PyGe.Point2d :
      '''closestPointTo( (Curve2d)arg1, (Point2d)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d closestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

closestPointTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> Point2d :

    C++ signature :
        class AcGePoint2d closestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

closestPointTo( (Curve2d)arg1, (Curve2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

closestPointTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
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
    def copy (self, *args, **kwargs)-> PyGe.Entity2d :
      '''copy( (Entity2d)arg1) -> Entity2d :

    C++ signature :
        class PyGeEntity2d copy(class PyGeEntity2d {lvalue})'''
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
    def distanceTo (self, *args, **kwargs)-> float :
      '''distanceTo( (Curve2d)arg1, (Point2d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

distanceTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

distanceTo( (Curve2d)arg1, (Curve2d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

distanceTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
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
    def evalPoint (self, *args, **kwargs)-> PyGe.Point2d :
      '''evalPoint( (Curve2d)arg1, (float)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d evalPoint(class PyGeCurve2d {lvalue},double)

evalPoint( (Curve2d)arg1, (float)arg2, (int)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple evalPoint(class PyGeCurve2d {lvalue},double,int)'''
    ...
    def explode (self, *args, **kwargs)-> list :
      '''explode( (Curve2d)arg1) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve2d {lvalue})

explode( (Curve2d)arg1, (Interval)arg2) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve2d {lvalue},class PyGeInterval)'''
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
    def getClosestPointTo (self, *args, **kwargs)-> PyGe.PointOnCurve2d :
      '''getClosestPointTo( (Curve2d)arg1, (Point2d)arg2) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getClosestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

getClosestPointTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getClosestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def getClosestPointsTo (self, *args, **kwargs)-> tuple :
      '''getClosestPointsTo( (Curve2d)arg1, (Curve2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

getClosestPointsTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def getEndPoint (self, *args, **kwargs)-> PyGe.Point2d :
      '''getEndPoint( (Curve2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d getEndPoint(class PyGeCurve2d {lvalue})'''
    ...
    def getInterval (self, *args, **kwargs)-> PyGe.Interval :
      '''getInterval( (Curve2d)arg1) -> Interval :

    C++ signature :
        class PyGeInterval getInterval(class PyGeCurve2d {lvalue})'''
    ...
    def getNormalPoint (self, *args, **kwargs)-> PyGe.PointOnCurve2d :
      '''getNormalPoint( (Curve2d)arg1, (Point2d)arg2) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getNormalPoint(class PyGeCurve2d {lvalue},class AcGePoint2d)

getNormalPoint( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getNormalPoint(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def getSamplePoints (self, *args, **kwargs)-> list :
      '''getSamplePoints( (Curve2d)arg1, (int)arg2) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve2d {lvalue},int)

getSamplePoints( (Curve2d)arg1, (float)arg2, (float)arg3, (float)arg4) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve2d {lvalue},double,double,double)'''
    ...
    def getSplitCurves (self, *args, **kwargs)-> tuple :
      '''getSplitCurves( (Curve2d)arg1, (float)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getSplitCurves(class PyGeCurve2d {lvalue},double)'''
    ...
    def getStartPoint (self, *args, **kwargs)-> PyGe.Point2d :
      '''getStartPoint( (Curve2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d getStartPoint(class PyGeCurve2d {lvalue})'''
    ...
    def getTrimmedOffset (self, *args, **kwargs)-> list :
      '''getTrimmedOffset( (Curve2d)arg1, (float)arg2, (OffsetCrvExtType)arg3) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve2d {lvalue},double,enum AcGe::OffsetCrvExtType)

getTrimmedOffset( (Curve2d)arg1, (float)arg2, (OffsetCrvExtType)arg3, (Tol)arg4) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve2d {lvalue},double,enum AcGe::OffsetCrvExtType,class AcGeTol)'''
    ...
    def hasEndPoint (self, *args, **kwargs)-> bool :
      '''hasEndPoint( (Curve2d)arg1) -> bool :

    C++ signature :
        bool hasEndPoint(class PyGeCurve2d {lvalue})'''
    ...
    def hasFitData (self, *args, **kwargs)-> bool :
      '''hasFitData( (SplineEnt2d)arg1) -> bool :

    C++ signature :
        bool hasFitData(class PyGeSplineEnt2d {lvalue})'''
    ...
    def hasStartPoint (self, *args, **kwargs)-> bool :
      '''hasStartPoint( (Curve2d)arg1) -> bool :

    C++ signature :
        bool hasStartPoint(class PyGeCurve2d {lvalue})'''
    ...
    def isClosed (self, *args, **kwargs)-> bool :
      '''isClosed( (Curve2d)arg1) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve2d {lvalue})

isClosed( (Curve2d)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isDegenerate (self, *args, **kwargs)-> tuple :
      '''isDegenerate( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve2d {lvalue})

isDegenerate( (Curve2d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isEqualTo (self, *args, **kwargs)-> bool :
      '''isEqualTo( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d)

isEqualTo( (Entity2d)arg1, (Entity2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d,class AcGeTol)'''
    ...
    def isKindOf (self, *args, **kwargs)-> bool :
      '''isKindOf( (Entity2d)arg1, (EntityId)arg2) -> bool :

    C++ signature :
        bool isKindOf(class PyGeEntity2d {lvalue},enum AcGe::EntityId)'''
    ...
    def isLinear (self, *args, **kwargs)-> tuple :
      '''isLinear( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve2d {lvalue})

isLinear( (Curve2d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isNull (self, *args, **kwargs)-> bool :
      '''isNull( (Entity2d)arg1) -> bool :

    C++ signature :
        bool isNull(class PyGeEntity2d {lvalue})'''
    ...
    def isOn (self, *args, **kwargs)-> tuple :
      '''isOn( (Curve2d)arg1, (Point2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isOn(class PyGeCurve2d {lvalue},class AcGePoint2d)

isOn( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple isOn(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

isOn( (Curve2d)arg1, (float)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isOn(class PyGeCurve2d {lvalue},double)

isOn( (Curve2d)arg1, (float)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple isOn(class PyGeCurve2d {lvalue},double,class AcGeTol)'''
    ...
    def isPeriodic (self, *args, **kwargs)-> tuple :
      '''isPeriodic( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isPeriodic(class PyGeCurve2d {lvalue})'''
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
    def length (self, *args, **kwargs)-> float :
      '''length( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double length(class PyGeCurve2d {lvalue},double,double)

length( (Curve2d)arg1, (float)arg2, (float)arg3, (float)arg4) -> float :

    C++ signature :
        double length(class PyGeCurve2d {lvalue},double,double,double)'''
    ...
    def mirror (self, *args, **kwargs)-> None :
      '''mirror( (Entity2d)arg1, (Line2d)arg2) -> None :

    C++ signature :
        void mirror(class PyGeEntity2d {lvalue},class PyGeLine2d)'''
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
    def orthoBoundBlock (self, *args, **kwargs)-> PyGe.BoundBlock2d :
      '''orthoBoundBlock( (Curve2d)arg1) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d orthoBoundBlock(class PyGeCurve2d {lvalue})

orthoBoundBlock( (Curve2d)arg1, (Interval)arg2) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d orthoBoundBlock(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def paramAtLength (self, *args, **kwargs)-> float :
      '''paramAtLength( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve2d {lvalue},double,double)

paramAtLength( (Curve2d)arg1, (float)arg2, (float)arg3, (bool)arg4, (float)arg5) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve2d {lvalue},double,double,bool,double)'''
    ...
    def paramOf (self, *args, **kwargs)-> float :
      '''paramOf( (Curve2d)arg1, (Point2d)arg2) -> float :

    C++ signature :
        double paramOf(class PyGeCurve2d {lvalue},class AcGePoint2d)

paramOf( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double paramOf(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def reverseParam (self, *args, **kwargs)-> None :
      '''reverseParam( (Curve2d)arg1) -> None :

    C++ signature :
        void reverseParam(class PyGeCurve2d {lvalue})'''
    ...
    def rotateBy (self, *args, **kwargs)-> None :
      '''rotateBy( (Entity2d)arg1, (float)arg2) -> None :

    C++ signature :
        void rotateBy(class PyGeEntity2d {lvalue},double)

rotateBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> None :

    C++ signature :
        void rotateBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def scaleBy (self, *args, **kwargs)-> None :
      '''scaleBy( (Entity2d)arg1, (float)arg2) -> None :

    C++ signature :
        void scaleBy(class PyGeEntity2d {lvalue},double)

scaleBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> None :

    C++ signature :
        void scaleBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
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
    def setInterval (self, *args, **kwargs)-> None :
      '''setInterval( (Curve2d)arg1) -> None :

    C++ signature :
        void setInterval(class PyGeCurve2d {lvalue})

setInterval( (Curve2d)arg1, (Interval)arg2) -> bool :

    C++ signature :
        bool setInterval(class PyGeCurve2d {lvalue},class PyGeInterval)'''
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
    def transformBy (self, *args, **kwargs)-> None :
      '''transformBy( (Entity2d)arg1, (Matrix2d)arg2) -> None :

    C++ signature :
        void transformBy(class PyGeEntity2d {lvalue},class AcGeMatrix2d)'''
    ...
    def translateBy (self, *args, **kwargs)-> None :
      '''translateBy( (Entity2d)arg1, (Vector2d)arg2) -> None :

    C++ signature :
        void translateBy(class PyGeEntity2d {lvalue},class AcGeVector2d)'''
    ...
    def type (self, *args, **kwargs)-> PyGe.EntityId :
      '''type( (Entity2d)arg1) -> EntityId :

    C++ signature :
        enum AcGe::EntityId type(class PyGeEntity2d {lvalue})'''
    ...

class CubicSplineCurve3d:
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
    def area (self, startParam : float, endParam : float, tol : float = default)-> float :
      '''                             '''
    ...
    def boundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock3d :
      '''                             '''
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
      '''                             '''
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
      '''                             '''
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
    def distanceTo (self, pt : float | PyGe.Point3d, tol : PyGe.Tol=None)-> float :
      '''                             '''
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
      '''                             '''
    ...
    def explode (self, val : PyGe.Interval = None)-> list :
      '''                             '''
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
      '''                             '''
    ...
    def getClosestPointsTo (self, other : PyGe.Curve3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def getEndPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def getInterval (self)-> PyGe.Interval :
      '''                             '''
    ...
    def getNormalPoint (self, pnt : PyGe.Point3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''                             '''
    ...
    def getProjClosestPointTo (self, pt : PyGe.Point3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''                             '''
    ...
    def getProjClosestPointsTo (self, pt : PyGe.Curve3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def getSamplePoints (self, *args, **kwargs)-> list :
      '''getSamplePoints( (Curve3d)arg1, (int)arg2) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve3d {lvalue},int)

getSamplePoints( (Curve3d)arg1, (float)arg2, (float)arg3, (float)arg4) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve3d {lvalue},double,double,double)'''
    ...
    def getSplitCurves (self, param : float)-> tuple :
      '''                             '''
    ...
    def getStartPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def getTrimmedOffset (self, dist : float, planeNormal : PyGe.Vector3d, extensionType : PyGe.OffsetCrvExtType, tol : PyGe.Tol=None)-> list :
      '''                             '''
    ...
    def hasEndPoint (self)-> bool :
      '''                             '''
    ...
    def hasFitData (self, *args, **kwargs)-> bool :
      '''hasFitData( (SplineEnt3d)arg1) -> bool :

    C++ signature :
        bool hasFitData(class PyGeSplineEnt3d {lvalue})'''
    ...
    def hasStartPoint (self)-> bool :
      '''                             '''
    ...
    def isClosed (self, tol : PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def isCoplanarWith (self, curve : PyGe.Curve3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isDegenerate (self, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isEqualTo (self, val : PyGe.Entity3d, tol : PyGe.Tol=None)-> bool :
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
    def isOn (self, pt : float | PyGe.Point3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isPeriodic (self)-> tuple :
      '''                             '''
    ...
    def isPlanar (self, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
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
    def length (self, frm : float, to : float, tol : float = default)-> float :
      '''                             '''
    ...
    def mirror (self, val : PyGe.Plane)-> None :
      '''                             '''
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
      '''                             '''
    ...
    def orthoProject (self, projectionPlane : PyGe.Plane, tol : PyGe.Tol=None)-> PyGe.Entity3d :
      '''                             '''
    ...
    def paramAtLength (self, datumParam : float, length : float, posParamDir : bool=True, tol : float = default)-> float :
      '''                             '''
    ...
    def paramOf (self, pt : PyGe.Point3d, tol : PyGe.Tol=None)-> float :
      '''                             '''
    ...
    def projClosestPointTo (self, pt : PyGe.Point3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.Point3d :
      '''                             '''
    ...
    def projClosestPointsTo (self, pt : PyGe.Curve3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def project (self, projectionPlane : PyGe.Plane, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.Entity3d :
      '''                             '''
    ...
    def reverseParam (self)-> None :
      '''                             '''
    ...
    def rotateBy (self, angle : double, vec : PyGe.Vector3d, pt : PyGe.Point3d = origin)-> None :
      '''                             '''
    ...
    def scaleBy (self, scaleFactor : double, pt : PyGe.Point3d = origin)-> None :
      '''                             '''
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
      '''                             '''
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
      '''                             '''
    ...
    def translateBy (self, vec : PyGe.Vector3d)-> None :
      '''                             '''
    ...
    def type (self)-> PyGe.EntityId :
      '''                             '''
    ...

class Curve2d:
    def __init__ (self, *args, **kwargs)-> None :
      '''Raises an exception
This class cannot be instantiated from Python'''
    ...
    def area (self, *args, **kwargs)-> float :
      '''area( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double area(class PyGeCurve2d {lvalue},double,double)

area( (Curve2d)arg1, (float)arg2, (float)arg3, (Tol)arg4) -> float :

    C++ signature :
        double area(class PyGeCurve2d {lvalue},double,double,class AcGeTol)'''
    ...
    def boundBlock (self, *args, **kwargs)-> PyGe.BoundBlock2d :
      '''boundBlock( (Curve2d)arg1) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d boundBlock(class PyGeCurve2d {lvalue})

boundBlock( (Curve2d)arg1, (Interval)arg2) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d boundBlock(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def cast (self, *args, **kwargs)-> PyGe.Curve2d :
      '''cast( (Entity2d)arg1) -> Curve2d :

    C++ signature :
        class PyGeCurve2d cast(class PyGeEntity2d)'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def closestPointTo (self, *args, **kwargs)-> PyGe.Point2d :
      '''closestPointTo( (Curve2d)arg1, (Point2d)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d closestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

closestPointTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> Point2d :

    C++ signature :
        class AcGePoint2d closestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

closestPointTo( (Curve2d)arg1, (Curve2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

closestPointTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def copy (self, *args, **kwargs)-> PyGe.Entity2d :
      '''copy( (Entity2d)arg1) -> Entity2d :

    C++ signature :
        class PyGeEntity2d copy(class PyGeEntity2d {lvalue})'''
    ...
    def copycast (self, *args, **kwargs)-> PyGe.Curve2d :
      '''copycast( (Entity2d)arg1) -> Curve2d :

    C++ signature :
        class PyGeCurve2d copycast(class PyGeEntity2d)'''
    ...
    def distanceTo (self, *args, **kwargs)-> float :
      '''distanceTo( (Curve2d)arg1, (Point2d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

distanceTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

distanceTo( (Curve2d)arg1, (Curve2d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

distanceTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def evalPoint (self, *args, **kwargs)-> PyGe.Point2d :
      '''evalPoint( (Curve2d)arg1, (float)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d evalPoint(class PyGeCurve2d {lvalue},double)

evalPoint( (Curve2d)arg1, (float)arg2, (int)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple evalPoint(class PyGeCurve2d {lvalue},double,int)'''
    ...
    def explode (self, *args, **kwargs)-> list :
      '''explode( (Curve2d)arg1) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve2d {lvalue})

explode( (Curve2d)arg1, (Interval)arg2) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def getClosestPointTo (self, *args, **kwargs)-> PyGe.PointOnCurve2d :
      '''getClosestPointTo( (Curve2d)arg1, (Point2d)arg2) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getClosestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

getClosestPointTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getClosestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def getClosestPointsTo (self, *args, **kwargs)-> tuple :
      '''getClosestPointsTo( (Curve2d)arg1, (Curve2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

getClosestPointsTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def getEndPoint (self, *args, **kwargs)-> PyGe.Point2d :
      '''getEndPoint( (Curve2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d getEndPoint(class PyGeCurve2d {lvalue})'''
    ...
    def getInterval (self, *args, **kwargs)-> PyGe.Interval :
      '''getInterval( (Curve2d)arg1) -> Interval :

    C++ signature :
        class PyGeInterval getInterval(class PyGeCurve2d {lvalue})'''
    ...
    def getNormalPoint (self, *args, **kwargs)-> PyGe.PointOnCurve2d :
      '''getNormalPoint( (Curve2d)arg1, (Point2d)arg2) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getNormalPoint(class PyGeCurve2d {lvalue},class AcGePoint2d)

getNormalPoint( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getNormalPoint(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def getSamplePoints (self, *args, **kwargs)-> list :
      '''getSamplePoints( (Curve2d)arg1, (int)arg2) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve2d {lvalue},int)

getSamplePoints( (Curve2d)arg1, (float)arg2, (float)arg3, (float)arg4) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve2d {lvalue},double,double,double)'''
    ...
    def getSplitCurves (self, *args, **kwargs)-> tuple :
      '''getSplitCurves( (Curve2d)arg1, (float)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getSplitCurves(class PyGeCurve2d {lvalue},double)'''
    ...
    def getStartPoint (self, *args, **kwargs)-> PyGe.Point2d :
      '''getStartPoint( (Curve2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d getStartPoint(class PyGeCurve2d {lvalue})'''
    ...
    def getTrimmedOffset (self, *args, **kwargs)-> list :
      '''getTrimmedOffset( (Curve2d)arg1, (float)arg2, (OffsetCrvExtType)arg3) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve2d {lvalue},double,enum AcGe::OffsetCrvExtType)

getTrimmedOffset( (Curve2d)arg1, (float)arg2, (OffsetCrvExtType)arg3, (Tol)arg4) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve2d {lvalue},double,enum AcGe::OffsetCrvExtType,class AcGeTol)'''
    ...
    def hasEndPoint (self, *args, **kwargs)-> bool :
      '''hasEndPoint( (Curve2d)arg1) -> bool :

    C++ signature :
        bool hasEndPoint(class PyGeCurve2d {lvalue})'''
    ...
    def hasStartPoint (self, *args, **kwargs)-> bool :
      '''hasStartPoint( (Curve2d)arg1) -> bool :

    C++ signature :
        bool hasStartPoint(class PyGeCurve2d {lvalue})'''
    ...
    def isClosed (self, *args, **kwargs)-> bool :
      '''isClosed( (Curve2d)arg1) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve2d {lvalue})

isClosed( (Curve2d)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isDegenerate (self, *args, **kwargs)-> tuple :
      '''isDegenerate( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve2d {lvalue})

isDegenerate( (Curve2d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isEqualTo (self, *args, **kwargs)-> bool :
      '''isEqualTo( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d)

isEqualTo( (Entity2d)arg1, (Entity2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d,class AcGeTol)'''
    ...
    def isKindOf (self, *args, **kwargs)-> bool :
      '''isKindOf( (Entity2d)arg1, (EntityId)arg2) -> bool :

    C++ signature :
        bool isKindOf(class PyGeEntity2d {lvalue},enum AcGe::EntityId)'''
    ...
    def isLinear (self, *args, **kwargs)-> tuple :
      '''isLinear( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve2d {lvalue})

isLinear( (Curve2d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isNull (self, *args, **kwargs)-> bool :
      '''isNull( (Entity2d)arg1) -> bool :

    C++ signature :
        bool isNull(class PyGeEntity2d {lvalue})'''
    ...
    def isOn (self, *args, **kwargs)-> tuple :
      '''isOn( (Curve2d)arg1, (Point2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isOn(class PyGeCurve2d {lvalue},class AcGePoint2d)

isOn( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple isOn(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

isOn( (Curve2d)arg1, (float)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isOn(class PyGeCurve2d {lvalue},double)

isOn( (Curve2d)arg1, (float)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple isOn(class PyGeCurve2d {lvalue},double,class AcGeTol)'''
    ...
    def isPeriodic (self, *args, **kwargs)-> tuple :
      '''isPeriodic( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isPeriodic(class PyGeCurve2d {lvalue})'''
    ...
    def length (self, *args, **kwargs)-> float :
      '''length( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double length(class PyGeCurve2d {lvalue},double,double)

length( (Curve2d)arg1, (float)arg2, (float)arg3, (float)arg4) -> float :

    C++ signature :
        double length(class PyGeCurve2d {lvalue},double,double,double)'''
    ...
    def mirror (self, *args, **kwargs)-> None :
      '''mirror( (Entity2d)arg1, (Line2d)arg2) -> None :

    C++ signature :
        void mirror(class PyGeEntity2d {lvalue},class PyGeLine2d)'''
    ...
    def orthoBoundBlock (self, *args, **kwargs)-> PyGe.BoundBlock2d :
      '''orthoBoundBlock( (Curve2d)arg1) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d orthoBoundBlock(class PyGeCurve2d {lvalue})

orthoBoundBlock( (Curve2d)arg1, (Interval)arg2) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d orthoBoundBlock(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def paramAtLength (self, *args, **kwargs)-> float :
      '''paramAtLength( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve2d {lvalue},double,double)

paramAtLength( (Curve2d)arg1, (float)arg2, (float)arg3, (bool)arg4, (float)arg5) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve2d {lvalue},double,double,bool,double)'''
    ...
    def paramOf (self, *args, **kwargs)-> float :
      '''paramOf( (Curve2d)arg1, (Point2d)arg2) -> float :

    C++ signature :
        double paramOf(class PyGeCurve2d {lvalue},class AcGePoint2d)

paramOf( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double paramOf(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def reverseParam (self, *args, **kwargs)-> None :
      '''reverseParam( (Curve2d)arg1) -> None :

    C++ signature :
        void reverseParam(class PyGeCurve2d {lvalue})'''
    ...
    def rotateBy (self, *args, **kwargs)-> None :
      '''rotateBy( (Entity2d)arg1, (float)arg2) -> None :

    C++ signature :
        void rotateBy(class PyGeEntity2d {lvalue},double)

rotateBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> None :

    C++ signature :
        void rotateBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def scaleBy (self, *args, **kwargs)-> None :
      '''scaleBy( (Entity2d)arg1, (float)arg2) -> None :

    C++ signature :
        void scaleBy(class PyGeEntity2d {lvalue},double)

scaleBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> None :

    C++ signature :
        void scaleBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def setInterval (self, *args, **kwargs)-> None :
      '''setInterval( (Curve2d)arg1) -> None :

    C++ signature :
        void setInterval(class PyGeCurve2d {lvalue})

setInterval( (Curve2d)arg1, (Interval)arg2) -> bool :

    C++ signature :
        bool setInterval(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def transformBy (self, *args, **kwargs)-> None :
      '''transformBy( (Entity2d)arg1, (Matrix2d)arg2) -> None :

    C++ signature :
        void transformBy(class PyGeEntity2d {lvalue},class AcGeMatrix2d)'''
    ...
    def translateBy (self, *args, **kwargs)-> None :
      '''translateBy( (Entity2d)arg1, (Vector2d)arg2) -> None :

    C++ signature :
        void translateBy(class PyGeEntity2d {lvalue},class AcGeVector2d)'''
    ...
    def type (self, *args, **kwargs)-> PyGe.EntityId :
      '''type( (Entity2d)arg1) -> EntityId :

    C++ signature :
        enum AcGe::EntityId type(class PyGeEntity2d {lvalue})'''
    ...

class Curve3d:
    def __init__ (self, *args, **kwargs)-> None :
      '''Raises an exception
This class cannot be instantiated from Python'''
    ...
    def area (self, startParam : float, endParam : float, tol : float = default)-> float :
      '''                             '''
    ...
    def boundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock3d :
      '''                             '''
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
      '''                             '''
    ...
    def copy (self)-> PyGe.Entity3d :
      '''                             '''
    ...

    @staticmethod
    def copycast (otherObject: PyGe.Curve3d)-> PyGe.Curve3d :
      '''                             '''
    ...
    def distanceTo (self, pt : float | PyGe.Point3d, tol : PyGe.Tol=None)-> float :
      '''                             '''
    ...
    def evalPoint (self, param : float, numDeriv : int = 1)-> PyGe.Point3d :
      '''                             '''
    ...
    def explode (self, val : PyGe.Interval = None)-> list :
      '''                             '''
    ...
    def getClosestPointTo (self, other : PyGe.Point3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''                             '''
    ...
    def getClosestPointsTo (self, other : PyGe.Curve3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def getEndPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def getInterval (self)-> PyGe.Interval :
      '''                             '''
    ...
    def getNormalPoint (self, pnt : PyGe.Point3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''                             '''
    ...
    def getProjClosestPointTo (self, pt : PyGe.Point3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''                             '''
    ...
    def getProjClosestPointsTo (self, pt : PyGe.Curve3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def getSamplePoints (self, *args, **kwargs)-> list :
      '''getSamplePoints( (Curve3d)arg1, (int)arg2) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve3d {lvalue},int)

getSamplePoints( (Curve3d)arg1, (float)arg2, (float)arg3, (float)arg4) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve3d {lvalue},double,double,double)'''
    ...
    def getSplitCurves (self, param : float)-> tuple :
      '''                             '''
    ...
    def getStartPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def getTrimmedOffset (self, dist : float, planeNormal : PyGe.Vector3d, extensionType : PyGe.OffsetCrvExtType, tol : PyGe.Tol=None)-> list :
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
    def isCoplanarWith (self, curve : PyGe.Curve3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isDegenerate (self, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isEqualTo (self, val : PyGe.Entity3d, tol : PyGe.Tol=None)-> bool :
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
    def isOn (self, pt : float | PyGe.Point3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isPeriodic (self)-> tuple :
      '''                             '''
    ...
    def isPlanar (self, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def length (self, frm : float, to : float, tol : float = default)-> float :
      '''                             '''
    ...
    def mirror (self, val : PyGe.Plane)-> None :
      '''                             '''
    ...
    def orthoBoundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock3d :
      '''                             '''
    ...
    def orthoProject (self, projectionPlane : PyGe.Plane, tol : PyGe.Tol=None)-> PyGe.Entity3d :
      '''                             '''
    ...
    def paramAtLength (self, datumParam : float, length : float, posParamDir : bool=True, tol : float = default)-> float :
      '''                             '''
    ...
    def paramOf (self, pt : PyGe.Point3d, tol : PyGe.Tol=None)-> float :
      '''                             '''
    ...
    def projClosestPointTo (self, pt : PyGe.Point3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.Point3d :
      '''                             '''
    ...
    def projClosestPointsTo (self, pt : PyGe.Curve3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def project (self, projectionPlane : PyGe.Plane, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.Entity3d :
      '''                             '''
    ...
    def reverseParam (self)-> None :
      '''                             '''
    ...
    def rotateBy (self, angle : double, vec : PyGe.Vector3d, pt : PyGe.Point3d = origin)-> None :
      '''                             '''
    ...
    def scaleBy (self, scaleFactor : double, pt : PyGe.Point3d = origin)-> None :
      '''                             '''
    ...
    def setInterval (self, val : PyGe.Interval = None)-> None :
      '''                             '''
    ...
    def transformBy (self, val : PyGe.Matrix3d)-> None :
      '''                             '''
    ...
    def translateBy (self, vec : PyGe.Vector3d)-> None :
      '''                             '''
    ...
    def type (self)-> PyGe.EntityId :
      '''                             '''
    ...

class CurveCurveInt2d:
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
    def copy (self, *args, **kwargs)-> PyGe.Entity2d :
      '''copy( (Entity2d)arg1) -> Entity2d :

    C++ signature :
        class PyGeEntity2d copy(class PyGeEntity2d {lvalue})'''
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
    def isEqualTo (self, *args, **kwargs)-> bool :
      '''isEqualTo( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d)

isEqualTo( (Entity2d)arg1, (Entity2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d,class AcGeTol)'''
    ...
    def isKindOf (self, *args, **kwargs)-> bool :
      '''isKindOf( (Entity2d)arg1, (EntityId)arg2) -> bool :

    C++ signature :
        bool isKindOf(class PyGeEntity2d {lvalue},enum AcGe::EntityId)'''
    ...
    def isNull (self, *args, **kwargs)-> bool :
      '''isNull( (Entity2d)arg1) -> bool :

    C++ signature :
        bool isNull(class PyGeEntity2d {lvalue})'''
    ...
    def isOn (self, *args, **kwargs)-> bool :
      '''isOn( (Entity2d)arg1, (Point2d)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeEntity2d {lvalue},class AcGePoint2d)

isOn( (Entity2d)arg1, (Point2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeEntity2d {lvalue},class AcGePoint2d,class AcGeTol)'''
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
    def mirror (self, *args, **kwargs)-> None :
      '''mirror( (Entity2d)arg1, (Line2d)arg2) -> None :

    C++ signature :
        void mirror(class PyGeEntity2d {lvalue},class PyGeLine2d)'''
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
    def rotateBy (self, *args, **kwargs)-> None :
      '''rotateBy( (Entity2d)arg1, (float)arg2) -> None :

    C++ signature :
        void rotateBy(class PyGeEntity2d {lvalue},double)

rotateBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> None :

    C++ signature :
        void rotateBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def scaleBy (self, *args, **kwargs)-> None :
      '''scaleBy( (Entity2d)arg1, (float)arg2) -> None :

    C++ signature :
        void scaleBy(class PyGeEntity2d {lvalue},double)

scaleBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> None :

    C++ signature :
        void scaleBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def tolerance (self, *args, **kwargs)-> PyGe.Tol :
      '''tolerance( (CurveCurveInt2d)arg1) -> Tol :

    C++ signature :
        class AcGeTol tolerance(class PyGeCurveCurveInt2d {lvalue})'''
    ...
    def transformBy (self, *args, **kwargs)-> None :
      '''transformBy( (Entity2d)arg1, (Matrix2d)arg2) -> None :

    C++ signature :
        void transformBy(class PyGeEntity2d {lvalue},class AcGeMatrix2d)'''
    ...
    def translateBy (self, *args, **kwargs)-> None :
      '''translateBy( (Entity2d)arg1, (Vector2d)arg2) -> None :

    C++ signature :
        void translateBy(class PyGeEntity2d {lvalue},class AcGeVector2d)'''
    ...
    def type (self, *args, **kwargs)-> PyGe.EntityId :
      '''type( (Entity2d)arg1) -> EntityId :

    C++ signature :
        enum AcGe::EntityId type(class PyGeEntity2d {lvalue})'''
    ...

class CurveCurveInt3d:
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
      '''                             '''
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
      '''                             '''
    ...
    def isKindOf (self, val : PyGe.EntityId)-> bool :
      '''                             '''
    ...
    def isNull (self)-> bool :
      '''                             '''
    ...
    def isOn (self, pt : PyGe.Point3d, tol : PyGe.Tol=default)-> bool :
      '''                             '''
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
      '''                             '''
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
    def rotateBy (self, angle : double, vec : PyGe.Vector3d, pt : PyGe.Point3d = origin)-> None :
      '''                             '''
    ...
    def scaleBy (self, scaleFactor : double, pt : PyGe.Point3d = origin)-> None :
      '''                             '''
    ...
    def tolerance (self, *args, **kwargs)-> PyGe.Tol :
      '''tolerance( (CurveCurveInt3d)arg1) -> Tol :

    C++ signature :
        class AcGeTol tolerance(class PyGeCurveCurveInt3d {lvalue})'''
    ...
    def transformBy (self, val : PyGe.Matrix3d)-> None :
      '''                             '''
    ...
    def translateBy (self, vec : PyGe.Vector3d)-> None :
      '''                             '''
    ...
    def type (self)-> PyGe.EntityId :
      '''                             '''
    ...

class CurveSurfInt:
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
      '''                             '''
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
      '''                             '''
    ...
    def isKindOf (self, val : PyGe.EntityId)-> bool :
      '''                             '''
    ...
    def isNull (self)-> bool :
      '''                             '''
    ...
    def isOn (self, pt : PyGe.Point3d, tol : PyGe.Tol=default)-> bool :
      '''                             '''
    ...
    def mirror (self, val : PyGe.Plane)-> None :
      '''                             '''
    ...
    def numIntPoints (self, *args, **kwargs)-> int :
      '''numIntPoints( (CurveSurfInt)arg1) -> int :

    C++ signature :
        int numIntPoints(class PyGeCurveSurfInt {lvalue})'''
    ...
    def rotateBy (self, angle : double, vec : PyGe.Vector3d, pt : PyGe.Point3d = origin)-> None :
      '''                             '''
    ...
    def scaleBy (self, scaleFactor : double, pt : PyGe.Point3d = origin)-> None :
      '''                             '''
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
      '''                             '''
    ...
    def translateBy (self, vec : PyGe.Vector3d)-> None :
      '''                             '''
    ...
    def type (self)-> PyGe.EntityId :
      '''                             '''
    ...

class Cylinder:
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
      '''                             '''
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
      '''                             '''
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
      '''                             '''
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
    def rotateBy (self, angle : double, vec : PyGe.Vector3d, pt : PyGe.Point3d = origin)-> None :
      '''                             '''
    ...
    def scaleBy (self, scaleFactor : double, pt : PyGe.Point3d = origin)-> None :
      '''                             '''
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
      '''                             '''
    ...
    def translateBy (self, vec : PyGe.Vector3d)-> None :
      '''                             '''
    ...
    def type (self)-> PyGe.EntityId :
      '''                             '''
    ...

class EllipArc2d:
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
    def area (self, *args, **kwargs)-> float :
      '''area( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double area(class PyGeCurve2d {lvalue},double,double)

area( (Curve2d)arg1, (float)arg2, (float)arg3, (Tol)arg4) -> float :

    C++ signature :
        double area(class PyGeCurve2d {lvalue},double,double,class AcGeTol)'''
    ...
    def boundBlock (self, *args, **kwargs)-> PyGe.BoundBlock2d :
      '''boundBlock( (Curve2d)arg1) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d boundBlock(class PyGeCurve2d {lvalue})

boundBlock( (Curve2d)arg1, (Interval)arg2) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d boundBlock(class PyGeCurve2d {lvalue},class PyGeInterval)'''
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
    def closestPointTo (self, *args, **kwargs)-> PyGe.Point2d :
      '''closestPointTo( (Curve2d)arg1, (Point2d)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d closestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

closestPointTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> Point2d :

    C++ signature :
        class AcGePoint2d closestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

closestPointTo( (Curve2d)arg1, (Curve2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

closestPointTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def copy (self, *args, **kwargs)-> PyGe.Entity2d :
      '''copy( (Entity2d)arg1) -> Entity2d :

    C++ signature :
        class PyGeEntity2d copy(class PyGeEntity2d {lvalue})'''
    ...
    def copycast (self, *args, **kwargs)-> PyGe.EllipArc2d :
      '''copycast( (Entity2d)arg1) -> EllipArc2d :

    C++ signature :
        class PyGeEllipArc2d copycast(class PyGeEntity2d)'''
    ...
    def distanceTo (self, *args, **kwargs)-> float :
      '''distanceTo( (Curve2d)arg1, (Point2d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

distanceTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

distanceTo( (Curve2d)arg1, (Curve2d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

distanceTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
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
    def evalPoint (self, *args, **kwargs)-> PyGe.Point2d :
      '''evalPoint( (Curve2d)arg1, (float)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d evalPoint(class PyGeCurve2d {lvalue},double)

evalPoint( (Curve2d)arg1, (float)arg2, (int)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple evalPoint(class PyGeCurve2d {lvalue},double,int)'''
    ...
    def explode (self, *args, **kwargs)-> list :
      '''explode( (Curve2d)arg1) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve2d {lvalue})

explode( (Curve2d)arg1, (Interval)arg2) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def getClosestPointTo (self, *args, **kwargs)-> PyGe.PointOnCurve2d :
      '''getClosestPointTo( (Curve2d)arg1, (Point2d)arg2) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getClosestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

getClosestPointTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getClosestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def getClosestPointsTo (self, *args, **kwargs)-> tuple :
      '''getClosestPointsTo( (Curve2d)arg1, (Curve2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

getClosestPointsTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def getEndPoint (self, *args, **kwargs)-> PyGe.Point2d :
      '''getEndPoint( (Curve2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d getEndPoint(class PyGeCurve2d {lvalue})'''
    ...
    def getInterval (self, *args, **kwargs)-> PyGe.Interval :
      '''getInterval( (Curve2d)arg1) -> Interval :

    C++ signature :
        class PyGeInterval getInterval(class PyGeCurve2d {lvalue})'''
    ...
    def getNormalPoint (self, *args, **kwargs)-> PyGe.PointOnCurve2d :
      '''getNormalPoint( (Curve2d)arg1, (Point2d)arg2) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getNormalPoint(class PyGeCurve2d {lvalue},class AcGePoint2d)

getNormalPoint( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getNormalPoint(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def getSamplePoints (self, *args, **kwargs)-> list :
      '''getSamplePoints( (Curve2d)arg1, (int)arg2) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve2d {lvalue},int)

getSamplePoints( (Curve2d)arg1, (float)arg2, (float)arg3, (float)arg4) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve2d {lvalue},double,double,double)'''
    ...
    def getSplitCurves (self, *args, **kwargs)-> tuple :
      '''getSplitCurves( (Curve2d)arg1, (float)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getSplitCurves(class PyGeCurve2d {lvalue},double)'''
    ...
    def getStartPoint (self, *args, **kwargs)-> PyGe.Point2d :
      '''getStartPoint( (Curve2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d getStartPoint(class PyGeCurve2d {lvalue})'''
    ...
    def getTrimmedOffset (self, *args, **kwargs)-> list :
      '''getTrimmedOffset( (Curve2d)arg1, (float)arg2, (OffsetCrvExtType)arg3) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve2d {lvalue},double,enum AcGe::OffsetCrvExtType)

getTrimmedOffset( (Curve2d)arg1, (float)arg2, (OffsetCrvExtType)arg3, (Tol)arg4) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve2d {lvalue},double,enum AcGe::OffsetCrvExtType,class AcGeTol)'''
    ...
    def hasEndPoint (self, *args, **kwargs)-> bool :
      '''hasEndPoint( (Curve2d)arg1) -> bool :

    C++ signature :
        bool hasEndPoint(class PyGeCurve2d {lvalue})'''
    ...
    def hasStartPoint (self, *args, **kwargs)-> bool :
      '''hasStartPoint( (Curve2d)arg1) -> bool :

    C++ signature :
        bool hasStartPoint(class PyGeCurve2d {lvalue})'''
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
    def isClosed (self, *args, **kwargs)-> bool :
      '''isClosed( (Curve2d)arg1) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve2d {lvalue})

isClosed( (Curve2d)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isDegenerate (self, *args, **kwargs)-> tuple :
      '''isDegenerate( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve2d {lvalue})

isDegenerate( (Curve2d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isEqualTo (self, *args, **kwargs)-> bool :
      '''isEqualTo( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d)

isEqualTo( (Entity2d)arg1, (Entity2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d,class AcGeTol)'''
    ...
    def isInside (self, *args, **kwargs)-> bool :
      '''isInside( (EllipArc2d)arg1, (Point2d)arg2) -> bool :

    C++ signature :
        bool isInside(class PyGeEllipArc2d {lvalue},class AcGePoint2d)

isInside( (EllipArc2d)arg1, (Point2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isInside(class PyGeEllipArc2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def isKindOf (self, *args, **kwargs)-> bool :
      '''isKindOf( (Entity2d)arg1, (EntityId)arg2) -> bool :

    C++ signature :
        bool isKindOf(class PyGeEntity2d {lvalue},enum AcGe::EntityId)'''
    ...
    def isLinear (self, *args, **kwargs)-> tuple :
      '''isLinear( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve2d {lvalue})

isLinear( (Curve2d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isNull (self, *args, **kwargs)-> bool :
      '''isNull( (Entity2d)arg1) -> bool :

    C++ signature :
        bool isNull(class PyGeEntity2d {lvalue})'''
    ...
    def isOn (self, *args, **kwargs)-> tuple :
      '''isOn( (Curve2d)arg1, (Point2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isOn(class PyGeCurve2d {lvalue},class AcGePoint2d)

isOn( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple isOn(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

isOn( (Curve2d)arg1, (float)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isOn(class PyGeCurve2d {lvalue},double)

isOn( (Curve2d)arg1, (float)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple isOn(class PyGeCurve2d {lvalue},double,class AcGeTol)'''
    ...
    def isPeriodic (self, *args, **kwargs)-> tuple :
      '''isPeriodic( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isPeriodic(class PyGeCurve2d {lvalue})'''
    ...
    def length (self, *args, **kwargs)-> float :
      '''length( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double length(class PyGeCurve2d {lvalue},double,double)

length( (Curve2d)arg1, (float)arg2, (float)arg3, (float)arg4) -> float :

    C++ signature :
        double length(class PyGeCurve2d {lvalue},double,double,double)'''
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
    def mirror (self, *args, **kwargs)-> None :
      '''mirror( (Entity2d)arg1, (Line2d)arg2) -> None :

    C++ signature :
        void mirror(class PyGeEntity2d {lvalue},class PyGeLine2d)'''
    ...
    def orthoBoundBlock (self, *args, **kwargs)-> PyGe.BoundBlock2d :
      '''orthoBoundBlock( (Curve2d)arg1) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d orthoBoundBlock(class PyGeCurve2d {lvalue})

orthoBoundBlock( (Curve2d)arg1, (Interval)arg2) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d orthoBoundBlock(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def paramAtLength (self, *args, **kwargs)-> float :
      '''paramAtLength( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve2d {lvalue},double,double)

paramAtLength( (Curve2d)arg1, (float)arg2, (float)arg3, (bool)arg4, (float)arg5) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve2d {lvalue},double,double,bool,double)'''
    ...
    def paramOf (self, *args, **kwargs)-> float :
      '''paramOf( (Curve2d)arg1, (Point2d)arg2) -> float :

    C++ signature :
        double paramOf(class PyGeCurve2d {lvalue},class AcGePoint2d)

paramOf( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double paramOf(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def reverseParam (self, *args, **kwargs)-> None :
      '''reverseParam( (Curve2d)arg1) -> None :

    C++ signature :
        void reverseParam(class PyGeCurve2d {lvalue})'''
    ...
    def rotateBy (self, *args, **kwargs)-> None :
      '''rotateBy( (Entity2d)arg1, (float)arg2) -> None :

    C++ signature :
        void rotateBy(class PyGeEntity2d {lvalue},double)

rotateBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> None :

    C++ signature :
        void rotateBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def scaleBy (self, *args, **kwargs)-> None :
      '''scaleBy( (Entity2d)arg1, (float)arg2) -> None :

    C++ signature :
        void scaleBy(class PyGeEntity2d {lvalue},double)

scaleBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> None :

    C++ signature :
        void scaleBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
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
    def setInterval (self, *args, **kwargs)-> None :
      '''setInterval( (Curve2d)arg1) -> None :

    C++ signature :
        void setInterval(class PyGeCurve2d {lvalue})

setInterval( (Curve2d)arg1, (Interval)arg2) -> bool :

    C++ signature :
        bool setInterval(class PyGeCurve2d {lvalue},class PyGeInterval)'''
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
    def transformBy (self, *args, **kwargs)-> None :
      '''transformBy( (Entity2d)arg1, (Matrix2d)arg2) -> None :

    C++ signature :
        void transformBy(class PyGeEntity2d {lvalue},class AcGeMatrix2d)'''
    ...
    def translateBy (self, *args, **kwargs)-> None :
      '''translateBy( (Entity2d)arg1, (Vector2d)arg2) -> None :

    C++ signature :
        void translateBy(class PyGeEntity2d {lvalue},class AcGeVector2d)'''
    ...
    def type (self, *args, **kwargs)-> PyGe.EntityId :
      '''type( (Entity2d)arg1) -> EntityId :

    C++ signature :
        enum AcGe::EntityId type(class PyGeEntity2d {lvalue})'''
    ...

class EllipArc3d:
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (CircArc3d)arg2) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class PyGeCircArc3d)

__init__( (object)arg1, (Point3d)arg2, (Vector3d)arg3, (Vector3d)arg4, (float)arg5, (float)arg6) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePoint3d,class AcGeVector3d,class AcGeVector3d,double,double)

__init__( (object)arg1, (Point3d)arg2, (Vector3d)arg3, (Vector3d)arg4, (float)arg5, (float)arg6, (float)arg7, (float)arg8) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePoint3d,class AcGeVector3d,class AcGeVector3d,double,double,double,double)'''
    ...
    def area (self, startParam : float, endParam : float, tol : float = default)-> float :
      '''                             '''
    ...
    def boundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock3d :
      '''                             '''
    ...
    def cast (self, *args, **kwargs)-> PyGe.EllipArc3d :
      '''cast( (Entity3d)arg1) -> EllipArc3d :

    C++ signature :
        class PyGeEllipArc3d cast(class PyGeEntity3d)'''
    ...
    def center (self, *args, **kwargs)-> PyGe.Point3d :
      '''center( (EllipArc3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d center(class PyGeEllipArc3d {lvalue})'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def closestPointTo (self, other : PyGe.Point3d | PyGe.Curve3d, tol : PyGe.Tol=None)-> PyGe.Point3d :
      '''                             '''
    ...
    def closestPointToPlane (self, *args, **kwargs)-> tuple :
      '''closestPointToPlane( (EllipArc3d)arg1, (PlanarEnt)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointToPlane(class PyGeEllipArc3d {lvalue},class PyGePlanarEnt)

closestPointToPlane( (EllipArc3d)arg1, (PlanarEnt)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointToPlane(class PyGeEllipArc3d {lvalue},class PyGePlanarEnt,class AcGeTol)'''
    ...
    def copy (self)-> PyGe.Entity3d :
      '''                             '''
    ...
    def copycast (self, *args, **kwargs)-> PyGe.EllipArc3d :
      '''copycast( (Entity3d)arg1) -> EllipArc3d :

    C++ signature :
        class PyGeEllipArc3d copycast(class PyGeEntity3d)'''
    ...
    def distanceTo (self, pt : float | PyGe.Point3d, tol : PyGe.Tol=None)-> float :
      '''                             '''
    ...
    def endAng (self, *args, **kwargs)-> float :
      '''endAng( (EllipArc3d)arg1) -> float :

    C++ signature :
        double endAng(class PyGeEllipArc3d {lvalue})'''
    ...
    def endPoint (self, *args, **kwargs)-> PyGe.Point3d :
      '''endPoint( (EllipArc3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d endPoint(class PyGeEllipArc3d {lvalue})'''
    ...
    def evalPoint (self, param : float, numDeriv : int = 1)-> PyGe.Point3d :
      '''                             '''
    ...
    def explode (self, val : PyGe.Interval = None)-> list :
      '''                             '''
    ...
    def getClosestPointTo (self, other : PyGe.Point3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''                             '''
    ...
    def getClosestPointsTo (self, other : PyGe.Curve3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def getEndPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def getInterval (self)-> PyGe.Interval :
      '''                             '''
    ...
    def getNormalPoint (self, pnt : PyGe.Point3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''                             '''
    ...
    def getPlane (self, *args, **kwargs)-> PyGe.Plane :
      '''getPlane( (EllipArc3d)arg1) -> Plane :

    C++ signature :
        class PyGePlane getPlane(class PyGeEllipArc3d {lvalue})'''
    ...
    def getProjClosestPointTo (self, pt : PyGe.Point3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''                             '''
    ...
    def getProjClosestPointsTo (self, pt : PyGe.Curve3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def getSamplePoints (self, *args, **kwargs)-> list :
      '''getSamplePoints( (Curve3d)arg1, (int)arg2) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve3d {lvalue},int)

getSamplePoints( (Curve3d)arg1, (float)arg2, (float)arg3, (float)arg4) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve3d {lvalue},double,double,double)'''
    ...
    def getSplitCurves (self, param : float)-> tuple :
      '''                             '''
    ...
    def getStartPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def getTrimmedOffset (self, dist : float, planeNormal : PyGe.Vector3d, extensionType : PyGe.OffsetCrvExtType, tol : PyGe.Tol=None)-> list :
      '''                             '''
    ...
    def hasEndPoint (self)-> bool :
      '''                             '''
    ...
    def hasStartPoint (self)-> bool :
      '''                             '''
    ...
    def intersectWith (self, *args, **kwargs)-> tuple :
      '''intersectWith( (EllipArc3d)arg1, (LinearEnt3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeEllipArc3d {lvalue},class PyGeLinearEnt3d)

intersectWith( (EllipArc3d)arg1, (LinearEnt3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeEllipArc3d {lvalue},class PyGeLinearEnt3d,class AcGeTol)

intersectWith( (EllipArc3d)arg1, (PlanarEnt)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeEllipArc3d {lvalue},class PyGePlanarEnt)

intersectWith( (EllipArc3d)arg1, (PlanarEnt)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeEllipArc3d {lvalue},class PyGePlanarEnt,class AcGeTol)'''
    ...
    def isCircular (self, *args, **kwargs)-> bool :
      '''isCircular( (EllipArc3d)arg1) -> bool :

    C++ signature :
        bool isCircular(class PyGeEllipArc3d {lvalue})

isCircular( (EllipArc3d)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isCircular(class PyGeEllipArc3d {lvalue},class AcGeTol)'''
    ...
    def isClosed (self, tol : PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def isCoplanarWith (self, curve : PyGe.Curve3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isDegenerate (self, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isEqualTo (self, val : PyGe.Entity3d, tol : PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def isInside (self, *args, **kwargs)-> bool :
      '''isInside( (EllipArc3d)arg1, (Point3d)arg2) -> bool :

    C++ signature :
        bool isInside(class PyGeEllipArc3d {lvalue},class AcGePoint3d)

isInside( (EllipArc3d)arg1, (Point3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isInside(class PyGeEllipArc3d {lvalue},class AcGePoint3d,class AcGeTol)'''
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
    def isOn (self, pt : float | PyGe.Point3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isPeriodic (self)-> tuple :
      '''                             '''
    ...
    def isPlanar (self, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def length (self, frm : float, to : float, tol : float = default)-> float :
      '''                             '''
    ...
    def majorAxis (self, *args, **kwargs)-> PyGe.Vector3d :
      '''majorAxis( (EllipArc3d)arg1) -> Vector3d :

    C++ signature :
        class AcGeVector3d majorAxis(class PyGeEllipArc3d {lvalue})'''
    ...
    def majorRadius (self, *args, **kwargs)-> float :
      '''majorRadius( (EllipArc3d)arg1) -> float :

    C++ signature :
        double majorRadius(class PyGeEllipArc3d {lvalue})'''
    ...
    def minorAxis (self, *args, **kwargs)-> PyGe.Vector3d :
      '''minorAxis( (EllipArc3d)arg1) -> Vector3d :

    C++ signature :
        class AcGeVector3d minorAxis(class PyGeEllipArc3d {lvalue})'''
    ...
    def minorRadius (self, *args, **kwargs)-> float :
      '''minorRadius( (EllipArc3d)arg1) -> float :

    C++ signature :
        double minorRadius(class PyGeEllipArc3d {lvalue})'''
    ...
    def mirror (self, val : PyGe.Plane)-> None :
      '''                             '''
    ...
    def normal (self, *args, **kwargs)-> PyGe.Vector3d :
      '''normal( (EllipArc3d)arg1) -> Vector3d :

    C++ signature :
        class AcGeVector3d normal(class PyGeEllipArc3d {lvalue})'''
    ...
    def orthoBoundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock3d :
      '''                             '''
    ...
    def orthoProject (self, projectionPlane : PyGe.Plane, tol : PyGe.Tol=None)-> PyGe.Entity3d :
      '''                             '''
    ...
    def paramAtLength (self, datumParam : float, length : float, posParamDir : bool=True, tol : float = default)-> float :
      '''                             '''
    ...
    def paramOf (self, pt : PyGe.Point3d, tol : PyGe.Tol=None)-> float :
      '''                             '''
    ...
    def projClosestPointTo (self, pt : PyGe.Point3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.Point3d :
      '''                             '''
    ...
    def projClosestPointsTo (self, pt : PyGe.Curve3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def projIntersectWith (self, *args, **kwargs)-> tuple :
      '''projIntersectWith( (EllipArc3d)arg1, (LinearEnt3d)arg2, (Vector3d)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple projIntersectWith(class PyGeEllipArc3d {lvalue},class PyGeLinearEnt3d,class AcGeVector3d)

projIntersectWith( (EllipArc3d)arg1, (LinearEnt3d)arg2, (Vector3d)arg3, (Tol)arg4) -> tuple :

    C++ signature :
        class boost::python::tuple projIntersectWith(class PyGeEllipArc3d {lvalue},class PyGeLinearEnt3d,class AcGeVector3d,class AcGeTol)'''
    ...
    def project (self, projectionPlane : PyGe.Plane, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.Entity3d :
      '''                             '''
    ...
    def reverseParam (self)-> None :
      '''                             '''
    ...
    def rotateBy (self, angle : double, vec : PyGe.Vector3d, pt : PyGe.Point3d = origin)-> None :
      '''                             '''
    ...
    def scaleBy (self, scaleFactor : double, pt : PyGe.Point3d = origin)-> None :
      '''                             '''
    ...
    def set (self, *args, **kwargs)-> None :
      '''set( (EllipArc3d)arg1, (Point3d)arg2, (Vector3d)arg3, (Vector3d)arg4, (float)arg5, (float)arg6) -> None :

    C++ signature :
        void set(class PyGeEllipArc3d {lvalue},class AcGePoint3d,class AcGeVector3d,class AcGeVector3d,double,double)

set( (EllipArc3d)arg1, (Point3d)arg2, (Vector3d)arg3, (Vector3d)arg4, (float)arg5, (float)arg6, (float)arg7, (float)arg8) -> None :

    C++ signature :
        void set(class PyGeEllipArc3d {lvalue},class AcGePoint3d,class AcGeVector3d,class AcGeVector3d,double,double,double,double)

set( (EllipArc3d)arg1, (CircArc3d)arg2) -> None :

    C++ signature :
        void set(class PyGeEllipArc3d {lvalue},class PyGeCircArc3d)'''
    ...
    def setAngles (self, *args, **kwargs)-> None :
      '''setAngles( (EllipArc3d)arg1, (float)arg2, (float)arg3) -> None :

    C++ signature :
        void setAngles(class PyGeEllipArc3d {lvalue},double,double)'''
    ...
    def setAxes (self, *args, **kwargs)-> None :
      '''setAxes( (EllipArc3d)arg1, (Vector3d)arg2, (Vector3d)arg3) -> None :

    C++ signature :
        void setAxes(class PyGeEllipArc3d {lvalue},class AcGeVector3d,class AcGeVector3d)'''
    ...
    def setCenter (self, *args, **kwargs)-> None :
      '''setCenter( (EllipArc3d)arg1, (Point3d)arg2) -> None :

    C++ signature :
        void setCenter(class PyGeEllipArc3d {lvalue},class AcGePoint3d)'''
    ...
    def setInterval (self, val : PyGe.Interval = None)-> None :
      '''                             '''
    ...
    def setMajorRadius (self, *args, **kwargs)-> None :
      '''setMajorRadius( (EllipArc3d)arg1, (float)arg2) -> None :

    C++ signature :
        void setMajorRadius(class PyGeEllipArc3d {lvalue},double)'''
    ...
    def setMinorRadius (self, *args, **kwargs)-> None :
      '''setMinorRadius( (EllipArc3d)arg1, (float)arg2) -> None :

    C++ signature :
        void setMinorRadius(class PyGeEllipArc3d {lvalue},double)'''
    ...
    def startAng (self, *args, **kwargs)-> float :
      '''startAng( (EllipArc3d)arg1) -> float :

    C++ signature :
        double startAng(class PyGeEllipArc3d {lvalue})'''
    ...
    def startPoint (self, *args, **kwargs)-> PyGe.Point3d :
      '''startPoint( (EllipArc3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d startPoint(class PyGeEllipArc3d {lvalue})'''
    ...
    def transformBy (self, val : PyGe.Matrix3d)-> None :
      '''                             '''
    ...
    def translateBy (self, vec : PyGe.Vector3d)-> None :
      '''                             '''
    ...
    def type (self)-> PyGe.EntityId :
      '''                             '''
    ...

class Entity2d:
    def __init__ (self, *args, **kwargs)-> None :
      '''Raises an exception
This class cannot be instantiated from Python'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def copy (self, *args, **kwargs)-> PyGe.Entity2d :
      '''copy( (Entity2d)arg1) -> Entity2d :

    C++ signature :
        class PyGeEntity2d copy(class PyGeEntity2d {lvalue})'''
    ...
    def copycast (self, *args, **kwargs)-> PyGe.Entity2d :
      '''copycast( (Entity2d)arg1) -> Entity2d :

    C++ signature :
        class PyGeEntity2d copycast(class PyGeEntity2d)'''
    ...
    def isEqualTo (self, *args, **kwargs)-> bool :
      '''isEqualTo( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d)

isEqualTo( (Entity2d)arg1, (Entity2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d,class AcGeTol)'''
    ...
    def isKindOf (self, *args, **kwargs)-> bool :
      '''isKindOf( (Entity2d)arg1, (EntityId)arg2) -> bool :

    C++ signature :
        bool isKindOf(class PyGeEntity2d {lvalue},enum AcGe::EntityId)'''
    ...
    def isNull (self, *args, **kwargs)-> bool :
      '''isNull( (Entity2d)arg1) -> bool :

    C++ signature :
        bool isNull(class PyGeEntity2d {lvalue})'''
    ...
    def isOn (self, *args, **kwargs)-> bool :
      '''isOn( (Entity2d)arg1, (Point2d)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeEntity2d {lvalue},class AcGePoint2d)

isOn( (Entity2d)arg1, (Point2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeEntity2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def mirror (self, *args, **kwargs)-> None :
      '''mirror( (Entity2d)arg1, (Line2d)arg2) -> None :

    C++ signature :
        void mirror(class PyGeEntity2d {lvalue},class PyGeLine2d)'''
    ...
    def rotateBy (self, *args, **kwargs)-> None :
      '''rotateBy( (Entity2d)arg1, (float)arg2) -> None :

    C++ signature :
        void rotateBy(class PyGeEntity2d {lvalue},double)

rotateBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> None :

    C++ signature :
        void rotateBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def scaleBy (self, *args, **kwargs)-> None :
      '''scaleBy( (Entity2d)arg1, (float)arg2) -> None :

    C++ signature :
        void scaleBy(class PyGeEntity2d {lvalue},double)

scaleBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> None :

    C++ signature :
        void scaleBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def transformBy (self, *args, **kwargs)-> None :
      '''transformBy( (Entity2d)arg1, (Matrix2d)arg2) -> None :

    C++ signature :
        void transformBy(class PyGeEntity2d {lvalue},class AcGeMatrix2d)'''
    ...
    def translateBy (self, *args, **kwargs)-> None :
      '''translateBy( (Entity2d)arg1, (Vector2d)arg2) -> None :

    C++ signature :
        void translateBy(class PyGeEntity2d {lvalue},class AcGeVector2d)'''
    ...
    def type (self, *args, **kwargs)-> PyGe.EntityId :
      '''type( (Entity2d)arg1) -> EntityId :

    C++ signature :
        enum AcGe::EntityId type(class PyGeEntity2d {lvalue})'''
    ...

class Entity3d:
    def __init__ (self, *args, **kwargs)-> None :
      '''Raises an exception
This class cannot be instantiated from Python'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def copy (self)-> PyGe.Entity3d :
      '''                             '''
    ...
    def copycast (self, *args, **kwargs)-> PyGe.Entity3d :
      '''copycast( (Entity3d)arg1) -> Entity3d :

    C++ signature :
        class PyGeEntity3d copycast(class PyGeEntity3d)'''
    ...
    def isEqualTo (self, val : PyGe.Entity3d, tol : PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def isKindOf (self, val : PyGe.EntityId)-> bool :
      '''                             '''
    ...
    def isNull (self)-> bool :
      '''                             '''
    ...
    def isOn (self, pt : PyGe.Point3d, tol : PyGe.Tol=default)-> bool :
      '''                             '''
    ...
    def mirror (self, val : PyGe.Plane)-> None :
      '''                             '''
    ...
    def rotateBy (self, angle : double, vec : PyGe.Vector3d, pt : PyGe.Point3d = origin)-> None :
      '''                             '''
    ...
    def scaleBy (self, scaleFactor : double, pt : PyGe.Point3d = origin)-> None :
      '''                             '''
    ...
    def transformBy (self, val : PyGe.Matrix3d)-> None :
      '''                             '''
    ...
    def translateBy (self, vec : PyGe.Vector3d)-> None :
      '''                             '''
    ...
    def type (self)-> PyGe.EntityId :
      '''                             '''
    ...

class EntityId:
    def Helix (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def conjugate (self, *args, **kwargs)-> None :
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs)-> None :
      '''the denominator of a rational number in lowest terms'''
    ...
    def imag (self, *args, **kwargs)-> None :
      '''the imaginary part of a complex number'''
    ...
    def is_integer (self, /) :
      '''Returns True. Exists for duck type compatibility with float.is_integer.'''
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
    def numerator (self, *args, **kwargs)-> None :
      '''the numerator of a rational number in lowest terms'''
    ...
    def real (self, *args, **kwargs)-> None :
      '''the real part of a complex number'''
    ...

class ExternalBoundedSurface:
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
      '''                             '''
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
      '''                             '''
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
    def reverseNormal (self, *args, **kwargs)-> None :
      '''reverseNormal( (Surface)arg1) -> None :

    C++ signature :
        void reverseNormal(class PyGeSurface {lvalue})'''
    ...
    def rotateBy (self, angle : double, vec : PyGe.Vector3d, pt : PyGe.Point3d = origin)-> None :
      '''                             '''
    ...
    def scaleBy (self, scaleFactor : double, pt : PyGe.Point3d = origin)-> None :
      '''                             '''
    ...
    def transformBy (self, val : PyGe.Matrix3d)-> None :
      '''                             '''
    ...
    def translateBy (self, vec : PyGe.Vector3d)-> None :
      '''                             '''
    ...
    def type (self)-> PyGe.EntityId :
      '''                             '''
    ...

class ExternalCurve2d:
    def __init__ (self, *args, **kwargs)-> None :
      '''Raises an exception
This class cannot be instantiated from Python'''
    ...
    def area (self, *args, **kwargs)-> float :
      '''area( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double area(class PyGeCurve2d {lvalue},double,double)

area( (Curve2d)arg1, (float)arg2, (float)arg3, (Tol)arg4) -> float :

    C++ signature :
        double area(class PyGeCurve2d {lvalue},double,double,class AcGeTol)'''
    ...
    def boundBlock (self, *args, **kwargs)-> PyGe.BoundBlock2d :
      '''boundBlock( (Curve2d)arg1) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d boundBlock(class PyGeCurve2d {lvalue})

boundBlock( (Curve2d)arg1, (Interval)arg2) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d boundBlock(class PyGeCurve2d {lvalue},class PyGeInterval)'''
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
    def closestPointTo (self, *args, **kwargs)-> PyGe.Point2d :
      '''closestPointTo( (Curve2d)arg1, (Point2d)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d closestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

closestPointTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> Point2d :

    C++ signature :
        class AcGePoint2d closestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

closestPointTo( (Curve2d)arg1, (Curve2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

closestPointTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def copy (self, *args, **kwargs)-> PyGe.Entity2d :
      '''copy( (Entity2d)arg1) -> Entity2d :

    C++ signature :
        class PyGeEntity2d copy(class PyGeEntity2d {lvalue})'''
    ...
    def copycast (self, *args, **kwargs)-> PyGe.ExternalCurve2d :
      '''copycast( (Entity2d)arg1) -> ExternalCurve2d :

    C++ signature :
        class PyGeExternalCurve2d copycast(class PyGeEntity2d)'''
    ...
    def distanceTo (self, *args, **kwargs)-> float :
      '''distanceTo( (Curve2d)arg1, (Point2d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

distanceTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

distanceTo( (Curve2d)arg1, (Curve2d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

distanceTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def evalPoint (self, *args, **kwargs)-> PyGe.Point2d :
      '''evalPoint( (Curve2d)arg1, (float)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d evalPoint(class PyGeCurve2d {lvalue},double)

evalPoint( (Curve2d)arg1, (float)arg2, (int)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple evalPoint(class PyGeCurve2d {lvalue},double,int)'''
    ...
    def explode (self, *args, **kwargs)-> list :
      '''explode( (Curve2d)arg1) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve2d {lvalue})

explode( (Curve2d)arg1, (Interval)arg2) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def getClosestPointTo (self, *args, **kwargs)-> PyGe.PointOnCurve2d :
      '''getClosestPointTo( (Curve2d)arg1, (Point2d)arg2) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getClosestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

getClosestPointTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getClosestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def getClosestPointsTo (self, *args, **kwargs)-> tuple :
      '''getClosestPointsTo( (Curve2d)arg1, (Curve2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

getClosestPointsTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def getEndPoint (self, *args, **kwargs)-> PyGe.Point2d :
      '''getEndPoint( (Curve2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d getEndPoint(class PyGeCurve2d {lvalue})'''
    ...
    def getInterval (self, *args, **kwargs)-> PyGe.Interval :
      '''getInterval( (Curve2d)arg1) -> Interval :

    C++ signature :
        class PyGeInterval getInterval(class PyGeCurve2d {lvalue})'''
    ...
    def getNormalPoint (self, *args, **kwargs)-> PyGe.PointOnCurve2d :
      '''getNormalPoint( (Curve2d)arg1, (Point2d)arg2) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getNormalPoint(class PyGeCurve2d {lvalue},class AcGePoint2d)

getNormalPoint( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getNormalPoint(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def getSamplePoints (self, *args, **kwargs)-> list :
      '''getSamplePoints( (Curve2d)arg1, (int)arg2) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve2d {lvalue},int)

getSamplePoints( (Curve2d)arg1, (float)arg2, (float)arg3, (float)arg4) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve2d {lvalue},double,double,double)'''
    ...
    def getSplitCurves (self, *args, **kwargs)-> tuple :
      '''getSplitCurves( (Curve2d)arg1, (float)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getSplitCurves(class PyGeCurve2d {lvalue},double)'''
    ...
    def getStartPoint (self, *args, **kwargs)-> PyGe.Point2d :
      '''getStartPoint( (Curve2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d getStartPoint(class PyGeCurve2d {lvalue})'''
    ...
    def getTrimmedOffset (self, *args, **kwargs)-> list :
      '''getTrimmedOffset( (Curve2d)arg1, (float)arg2, (OffsetCrvExtType)arg3) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve2d {lvalue},double,enum AcGe::OffsetCrvExtType)

getTrimmedOffset( (Curve2d)arg1, (float)arg2, (OffsetCrvExtType)arg3, (Tol)arg4) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve2d {lvalue},double,enum AcGe::OffsetCrvExtType,class AcGeTol)'''
    ...
    def hasEndPoint (self, *args, **kwargs)-> bool :
      '''hasEndPoint( (Curve2d)arg1) -> bool :

    C++ signature :
        bool hasEndPoint(class PyGeCurve2d {lvalue})'''
    ...
    def hasStartPoint (self, *args, **kwargs)-> bool :
      '''hasStartPoint( (Curve2d)arg1) -> bool :

    C++ signature :
        bool hasStartPoint(class PyGeCurve2d {lvalue})'''
    ...
    def isClosed (self, *args, **kwargs)-> bool :
      '''isClosed( (Curve2d)arg1) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve2d {lvalue})

isClosed( (Curve2d)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isDegenerate (self, *args, **kwargs)-> tuple :
      '''isDegenerate( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve2d {lvalue})

isDegenerate( (Curve2d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isEqualTo (self, *args, **kwargs)-> bool :
      '''isEqualTo( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d)

isEqualTo( (Entity2d)arg1, (Entity2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d,class AcGeTol)'''
    ...
    def isKindOf (self, *args, **kwargs)-> bool :
      '''isKindOf( (Entity2d)arg1, (EntityId)arg2) -> bool :

    C++ signature :
        bool isKindOf(class PyGeEntity2d {lvalue},enum AcGe::EntityId)'''
    ...
    def isLinear (self, *args, **kwargs)-> tuple :
      '''isLinear( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve2d {lvalue})

isLinear( (Curve2d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isNull (self, *args, **kwargs)-> bool :
      '''isNull( (Entity2d)arg1) -> bool :

    C++ signature :
        bool isNull(class PyGeEntity2d {lvalue})'''
    ...
    def isOn (self, *args, **kwargs)-> tuple :
      '''isOn( (Curve2d)arg1, (Point2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isOn(class PyGeCurve2d {lvalue},class AcGePoint2d)

isOn( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple isOn(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

isOn( (Curve2d)arg1, (float)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isOn(class PyGeCurve2d {lvalue},double)

isOn( (Curve2d)arg1, (float)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple isOn(class PyGeCurve2d {lvalue},double,class AcGeTol)'''
    ...
    def isPeriodic (self, *args, **kwargs)-> tuple :
      '''isPeriodic( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isPeriodic(class PyGeCurve2d {lvalue})'''
    ...
    def length (self, *args, **kwargs)-> float :
      '''length( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double length(class PyGeCurve2d {lvalue},double,double)

length( (Curve2d)arg1, (float)arg2, (float)arg3, (float)arg4) -> float :

    C++ signature :
        double length(class PyGeCurve2d {lvalue},double,double,double)'''
    ...
    def mirror (self, *args, **kwargs)-> None :
      '''mirror( (Entity2d)arg1, (Line2d)arg2) -> None :

    C++ signature :
        void mirror(class PyGeEntity2d {lvalue},class PyGeLine2d)'''
    ...
    def orthoBoundBlock (self, *args, **kwargs)-> PyGe.BoundBlock2d :
      '''orthoBoundBlock( (Curve2d)arg1) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d orthoBoundBlock(class PyGeCurve2d {lvalue})

orthoBoundBlock( (Curve2d)arg1, (Interval)arg2) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d orthoBoundBlock(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def paramAtLength (self, *args, **kwargs)-> float :
      '''paramAtLength( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve2d {lvalue},double,double)

paramAtLength( (Curve2d)arg1, (float)arg2, (float)arg3, (bool)arg4, (float)arg5) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve2d {lvalue},double,double,bool,double)'''
    ...
    def paramOf (self, *args, **kwargs)-> float :
      '''paramOf( (Curve2d)arg1, (Point2d)arg2) -> float :

    C++ signature :
        double paramOf(class PyGeCurve2d {lvalue},class AcGePoint2d)

paramOf( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double paramOf(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def reverseParam (self, *args, **kwargs)-> None :
      '''reverseParam( (Curve2d)arg1) -> None :

    C++ signature :
        void reverseParam(class PyGeCurve2d {lvalue})'''
    ...
    def rotateBy (self, *args, **kwargs)-> None :
      '''rotateBy( (Entity2d)arg1, (float)arg2) -> None :

    C++ signature :
        void rotateBy(class PyGeEntity2d {lvalue},double)

rotateBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> None :

    C++ signature :
        void rotateBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def scaleBy (self, *args, **kwargs)-> None :
      '''scaleBy( (Entity2d)arg1, (float)arg2) -> None :

    C++ signature :
        void scaleBy(class PyGeEntity2d {lvalue},double)

scaleBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> None :

    C++ signature :
        void scaleBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def setInterval (self, *args, **kwargs)-> None :
      '''setInterval( (Curve2d)arg1) -> None :

    C++ signature :
        void setInterval(class PyGeCurve2d {lvalue})

setInterval( (Curve2d)arg1, (Interval)arg2) -> bool :

    C++ signature :
        bool setInterval(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def transformBy (self, *args, **kwargs)-> None :
      '''transformBy( (Entity2d)arg1, (Matrix2d)arg2) -> None :

    C++ signature :
        void transformBy(class PyGeEntity2d {lvalue},class AcGeMatrix2d)'''
    ...
    def translateBy (self, *args, **kwargs)-> None :
      '''translateBy( (Entity2d)arg1, (Vector2d)arg2) -> None :

    C++ signature :
        void translateBy(class PyGeEntity2d {lvalue},class AcGeVector2d)'''
    ...
    def type (self, *args, **kwargs)-> PyGe.EntityId :
      '''type( (Entity2d)arg1) -> EntityId :

    C++ signature :
        enum AcGe::EntityId type(class PyGeEntity2d {lvalue})'''
    ...

class ExternalCurve3d:
    def __init__ (self, *args, **kwargs)-> None :
      '''Raises an exception
This class cannot be instantiated from Python'''
    ...
    def area (self, startParam : float, endParam : float, tol : float = default)-> float :
      '''                             '''
    ...
    def boundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock3d :
      '''                             '''
    ...
    def cast (self, *args, **kwargs)-> PyGe.ExternalCurve3d :
      '''cast( (Entity3d)arg1) -> ExternalCurve3d :

    C++ signature :
        class PyGeExternalCurve3d cast(class PyGeEntity3d)'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def closestPointTo (self, other : PyGe.Point3d | PyGe.Curve3d, tol : PyGe.Tol=None)-> PyGe.Point3d :
      '''                             '''
    ...
    def copy (self)-> PyGe.Entity3d :
      '''                             '''
    ...
    def copycast (self, *args, **kwargs)-> PyGe.ExternalCurve3d :
      '''copycast( (Entity3d)arg1) -> ExternalCurve3d :

    C++ signature :
        class PyGeExternalCurve3d copycast(class PyGeEntity3d)'''
    ...
    def distanceTo (self, pt : float | PyGe.Point3d, tol : PyGe.Tol=None)-> float :
      '''                             '''
    ...
    def evalPoint (self, param : float, numDeriv : int = 1)-> PyGe.Point3d :
      '''                             '''
    ...
    def explode (self, val : PyGe.Interval = None)-> list :
      '''                             '''
    ...
    def getClosestPointTo (self, other : PyGe.Point3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''                             '''
    ...
    def getClosestPointsTo (self, other : PyGe.Curve3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def getEndPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def getInterval (self)-> PyGe.Interval :
      '''                             '''
    ...
    def getNormalPoint (self, pnt : PyGe.Point3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''                             '''
    ...
    def getProjClosestPointTo (self, pt : PyGe.Point3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''                             '''
    ...
    def getProjClosestPointsTo (self, pt : PyGe.Curve3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def getSamplePoints (self, *args, **kwargs)-> list :
      '''getSamplePoints( (Curve3d)arg1, (int)arg2) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve3d {lvalue},int)

getSamplePoints( (Curve3d)arg1, (float)arg2, (float)arg3, (float)arg4) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve3d {lvalue},double,double,double)'''
    ...
    def getSplitCurves (self, param : float)-> tuple :
      '''                             '''
    ...
    def getStartPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def getTrimmedOffset (self, dist : float, planeNormal : PyGe.Vector3d, extensionType : PyGe.OffsetCrvExtType, tol : PyGe.Tol=None)-> list :
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
    def isCoplanarWith (self, curve : PyGe.Curve3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isDegenerate (self, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isEqualTo (self, val : PyGe.Entity3d, tol : PyGe.Tol=None)-> bool :
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
    def isOn (self, pt : float | PyGe.Point3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isPeriodic (self)-> tuple :
      '''                             '''
    ...
    def isPlanar (self, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def length (self, frm : float, to : float, tol : float = default)-> float :
      '''                             '''
    ...
    def mirror (self, val : PyGe.Plane)-> None :
      '''                             '''
    ...
    def orthoBoundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock3d :
      '''                             '''
    ...
    def orthoProject (self, projectionPlane : PyGe.Plane, tol : PyGe.Tol=None)-> PyGe.Entity3d :
      '''                             '''
    ...
    def paramAtLength (self, datumParam : float, length : float, posParamDir : bool=True, tol : float = default)-> float :
      '''                             '''
    ...
    def paramOf (self, pt : PyGe.Point3d, tol : PyGe.Tol=None)-> float :
      '''                             '''
    ...
    def projClosestPointTo (self, pt : PyGe.Point3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.Point3d :
      '''                             '''
    ...
    def projClosestPointsTo (self, pt : PyGe.Curve3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def project (self, projectionPlane : PyGe.Plane, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.Entity3d :
      '''                             '''
    ...
    def reverseParam (self)-> None :
      '''                             '''
    ...
    def rotateBy (self, angle : double, vec : PyGe.Vector3d, pt : PyGe.Point3d = origin)-> None :
      '''                             '''
    ...
    def scaleBy (self, scaleFactor : double, pt : PyGe.Point3d = origin)-> None :
      '''                             '''
    ...
    def setInterval (self, val : PyGe.Interval = None)-> None :
      '''                             '''
    ...
    def transformBy (self, val : PyGe.Matrix3d)-> None :
      '''                             '''
    ...
    def translateBy (self, vec : PyGe.Vector3d)-> None :
      '''                             '''
    ...
    def type (self)-> PyGe.EntityId :
      '''                             '''
    ...

class ExternalSurface:
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
      '''                             '''
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
      '''                             '''
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
    def reverseNormal (self, *args, **kwargs)-> None :
      '''reverseNormal( (Surface)arg1) -> None :

    C++ signature :
        void reverseNormal(class PyGeSurface {lvalue})'''
    ...
    def rotateBy (self, angle : double, vec : PyGe.Vector3d, pt : PyGe.Point3d = origin)-> None :
      '''                             '''
    ...
    def scaleBy (self, scaleFactor : double, pt : PyGe.Point3d = origin)-> None :
      '''                             '''
    ...
    def transformBy (self, val : PyGe.Matrix3d)-> None :
      '''                             '''
    ...
    def translateBy (self, vec : PyGe.Vector3d)-> None :
      '''                             '''
    ...
    def type (self)-> PyGe.EntityId :
      '''                             '''
    ...

class Interval:
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

class KnotVector:
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

class Line2d:
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
    def area (self, *args, **kwargs)-> float :
      '''area( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double area(class PyGeCurve2d {lvalue},double,double)

area( (Curve2d)arg1, (float)arg2, (float)arg3, (Tol)arg4) -> float :

    C++ signature :
        double area(class PyGeCurve2d {lvalue},double,double,class AcGeTol)'''
    ...
    def boundBlock (self, *args, **kwargs)-> PyGe.BoundBlock2d :
      '''boundBlock( (Curve2d)arg1) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d boundBlock(class PyGeCurve2d {lvalue})

boundBlock( (Curve2d)arg1, (Interval)arg2) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d boundBlock(class PyGeCurve2d {lvalue},class PyGeInterval)'''
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
    def closestPointTo (self, *args, **kwargs)-> PyGe.Point2d :
      '''closestPointTo( (Curve2d)arg1, (Point2d)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d closestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

closestPointTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> Point2d :

    C++ signature :
        class AcGePoint2d closestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

closestPointTo( (Curve2d)arg1, (Curve2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

closestPointTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def copy (self, *args, **kwargs)-> PyGe.Entity2d :
      '''copy( (Entity2d)arg1) -> Entity2d :

    C++ signature :
        class PyGeEntity2d copy(class PyGeEntity2d {lvalue})'''
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
    def distanceTo (self, *args, **kwargs)-> float :
      '''distanceTo( (Curve2d)arg1, (Point2d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

distanceTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

distanceTo( (Curve2d)arg1, (Curve2d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

distanceTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def evalPoint (self, *args, **kwargs)-> PyGe.Point2d :
      '''evalPoint( (Curve2d)arg1, (float)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d evalPoint(class PyGeCurve2d {lvalue},double)

evalPoint( (Curve2d)arg1, (float)arg2, (int)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple evalPoint(class PyGeCurve2d {lvalue},double,int)'''
    ...
    def explode (self, *args, **kwargs)-> list :
      '''explode( (Curve2d)arg1) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve2d {lvalue})

explode( (Curve2d)arg1, (Interval)arg2) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def getClosestPointTo (self, *args, **kwargs)-> PyGe.PointOnCurve2d :
      '''getClosestPointTo( (Curve2d)arg1, (Point2d)arg2) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getClosestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

getClosestPointTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getClosestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def getClosestPointsTo (self, *args, **kwargs)-> tuple :
      '''getClosestPointsTo( (Curve2d)arg1, (Curve2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

getClosestPointsTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def getEndPoint (self, *args, **kwargs)-> PyGe.Point2d :
      '''getEndPoint( (Curve2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d getEndPoint(class PyGeCurve2d {lvalue})'''
    ...
    def getInterval (self, *args, **kwargs)-> PyGe.Interval :
      '''getInterval( (Curve2d)arg1) -> Interval :

    C++ signature :
        class PyGeInterval getInterval(class PyGeCurve2d {lvalue})'''
    ...
    def getLine (self, *args, **kwargs)-> PyGe.Line2d :
      '''getLine( (LinearEnt2d)arg1) -> Line2d :

    C++ signature :
        class PyGeLine2d getLine(class PyGeLinearEnt2d {lvalue})'''
    ...
    def getNormalPoint (self, *args, **kwargs)-> PyGe.PointOnCurve2d :
      '''getNormalPoint( (Curve2d)arg1, (Point2d)arg2) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getNormalPoint(class PyGeCurve2d {lvalue},class AcGePoint2d)

getNormalPoint( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getNormalPoint(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def getPerpLine (self, *args, **kwargs)-> PyGe.Line2d :
      '''getPerpLine( (LinearEnt2d)arg1, (Point2d)arg2) -> Line2d :

    C++ signature :
        class PyGeLine2d getPerpLine(class PyGeLinearEnt2d {lvalue},class AcGePoint2d)'''
    ...
    def getSamplePoints (self, *args, **kwargs)-> list :
      '''getSamplePoints( (Curve2d)arg1, (int)arg2) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve2d {lvalue},int)

getSamplePoints( (Curve2d)arg1, (float)arg2, (float)arg3, (float)arg4) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve2d {lvalue},double,double,double)'''
    ...
    def getSplitCurves (self, *args, **kwargs)-> tuple :
      '''getSplitCurves( (Curve2d)arg1, (float)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getSplitCurves(class PyGeCurve2d {lvalue},double)'''
    ...
    def getStartPoint (self, *args, **kwargs)-> PyGe.Point2d :
      '''getStartPoint( (Curve2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d getStartPoint(class PyGeCurve2d {lvalue})'''
    ...
    def getTrimmedOffset (self, *args, **kwargs)-> list :
      '''getTrimmedOffset( (Curve2d)arg1, (float)arg2, (OffsetCrvExtType)arg3) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve2d {lvalue},double,enum AcGe::OffsetCrvExtType)

getTrimmedOffset( (Curve2d)arg1, (float)arg2, (OffsetCrvExtType)arg3, (Tol)arg4) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve2d {lvalue},double,enum AcGe::OffsetCrvExtType,class AcGeTol)'''
    ...
    def hasEndPoint (self, *args, **kwargs)-> bool :
      '''hasEndPoint( (Curve2d)arg1) -> bool :

    C++ signature :
        bool hasEndPoint(class PyGeCurve2d {lvalue})'''
    ...
    def hasStartPoint (self, *args, **kwargs)-> bool :
      '''hasStartPoint( (Curve2d)arg1) -> bool :

    C++ signature :
        bool hasStartPoint(class PyGeCurve2d {lvalue})'''
    ...
    def intersectWith (self, *args, **kwargs)-> tuple :
      '''intersectWith( (LinearEnt2d)arg1, (LinearEnt2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d)

intersectWith( (LinearEnt2d)arg1, (LinearEnt2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d,class AcGeTol)'''
    ...
    def isClosed (self, *args, **kwargs)-> bool :
      '''isClosed( (Curve2d)arg1) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve2d {lvalue})

isClosed( (Curve2d)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isColinearTo (self, *args, **kwargs)-> bool :
      '''isColinearTo( (LinearEnt2d)arg1, (LinearEnt2d)arg2) -> bool :

    C++ signature :
        bool isColinearTo(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d)

isColinearTo( (LinearEnt2d)arg1, (LinearEnt2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isColinearTo(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d,class AcGeTol)'''
    ...
    def isDegenerate (self, *args, **kwargs)-> tuple :
      '''isDegenerate( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve2d {lvalue})

isDegenerate( (Curve2d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isEqualTo (self, *args, **kwargs)-> bool :
      '''isEqualTo( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d)

isEqualTo( (Entity2d)arg1, (Entity2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d,class AcGeTol)'''
    ...
    def isKindOf (self, *args, **kwargs)-> bool :
      '''isKindOf( (Entity2d)arg1, (EntityId)arg2) -> bool :

    C++ signature :
        bool isKindOf(class PyGeEntity2d {lvalue},enum AcGe::EntityId)'''
    ...
    def isLinear (self, *args, **kwargs)-> tuple :
      '''isLinear( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve2d {lvalue})

isLinear( (Curve2d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isNull (self, *args, **kwargs)-> bool :
      '''isNull( (Entity2d)arg1) -> bool :

    C++ signature :
        bool isNull(class PyGeEntity2d {lvalue})'''
    ...
    def isOn (self, *args, **kwargs)-> tuple :
      '''isOn( (Curve2d)arg1, (Point2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isOn(class PyGeCurve2d {lvalue},class AcGePoint2d)

isOn( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple isOn(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

isOn( (Curve2d)arg1, (float)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isOn(class PyGeCurve2d {lvalue},double)

isOn( (Curve2d)arg1, (float)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple isOn(class PyGeCurve2d {lvalue},double,class AcGeTol)'''
    ...
    def isParallelTo (self, *args, **kwargs)-> bool :
      '''isParallelTo( (LinearEnt2d)arg1, (LinearEnt2d)arg2) -> bool :

    C++ signature :
        bool isParallelTo(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d)

isParallelTo( (LinearEnt2d)arg1, (LinearEnt2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isParallelTo(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d,class AcGeTol)'''
    ...
    def isPeriodic (self, *args, **kwargs)-> tuple :
      '''isPeriodic( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isPeriodic(class PyGeCurve2d {lvalue})'''
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
    def length (self, *args, **kwargs)-> float :
      '''length( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double length(class PyGeCurve2d {lvalue},double,double)

length( (Curve2d)arg1, (float)arg2, (float)arg3, (float)arg4) -> float :

    C++ signature :
        double length(class PyGeCurve2d {lvalue},double,double,double)'''
    ...
    def mirror (self, *args, **kwargs)-> None :
      '''mirror( (Entity2d)arg1, (Line2d)arg2) -> None :

    C++ signature :
        void mirror(class PyGeEntity2d {lvalue},class PyGeLine2d)'''
    ...
    def orthoBoundBlock (self, *args, **kwargs)-> PyGe.BoundBlock2d :
      '''orthoBoundBlock( (Curve2d)arg1) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d orthoBoundBlock(class PyGeCurve2d {lvalue})

orthoBoundBlock( (Curve2d)arg1, (Interval)arg2) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d orthoBoundBlock(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def overlap (self, *args, **kwargs)-> tuple :
      '''overlap( (LinearEnt2d)arg1, (LinearEnt2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple overlap(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d)

overlap( (LinearEnt2d)arg1, (LinearEnt2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple overlap(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d,class AcGeTol)'''
    ...
    def paramAtLength (self, *args, **kwargs)-> float :
      '''paramAtLength( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve2d {lvalue},double,double)

paramAtLength( (Curve2d)arg1, (float)arg2, (float)arg3, (bool)arg4, (float)arg5) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve2d {lvalue},double,double,bool,double)'''
    ...
    def paramOf (self, *args, **kwargs)-> float :
      '''paramOf( (Curve2d)arg1, (Point2d)arg2) -> float :

    C++ signature :
        double paramOf(class PyGeCurve2d {lvalue},class AcGePoint2d)

paramOf( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double paramOf(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def pointOnLine (self, *args, **kwargs)-> PyGe.Point2d :
      '''pointOnLine( (LinearEnt2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d pointOnLine(class PyGeLinearEnt2d {lvalue})'''
    ...
    def reverseParam (self, *args, **kwargs)-> None :
      '''reverseParam( (Curve2d)arg1) -> None :

    C++ signature :
        void reverseParam(class PyGeCurve2d {lvalue})'''
    ...
    def rotateBy (self, *args, **kwargs)-> None :
      '''rotateBy( (Entity2d)arg1, (float)arg2) -> None :

    C++ signature :
        void rotateBy(class PyGeEntity2d {lvalue},double)

rotateBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> None :

    C++ signature :
        void rotateBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def scaleBy (self, *args, **kwargs)-> None :
      '''scaleBy( (Entity2d)arg1, (float)arg2) -> None :

    C++ signature :
        void scaleBy(class PyGeEntity2d {lvalue},double)

scaleBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> None :

    C++ signature :
        void scaleBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def set (self, *args, **kwargs)-> None :
      '''set( (Line2d)arg1, (Point2d)arg2, (Vector2d)arg3) -> None :

    C++ signature :
        void set(class PyGeLine2d {lvalue},class AcGePoint2d,class AcGeVector2d)

set( (Line2d)arg1, (Point2d)arg2, (Point2d)arg3) -> None :

    C++ signature :
        void set(class PyGeLine2d {lvalue},class AcGePoint2d,class AcGePoint2d)'''
    ...
    def setInterval (self, *args, **kwargs)-> None :
      '''setInterval( (Curve2d)arg1) -> None :

    C++ signature :
        void setInterval(class PyGeCurve2d {lvalue})

setInterval( (Curve2d)arg1, (Interval)arg2) -> bool :

    C++ signature :
        bool setInterval(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def transformBy (self, *args, **kwargs)-> None :
      '''transformBy( (Entity2d)arg1, (Matrix2d)arg2) -> None :

    C++ signature :
        void transformBy(class PyGeEntity2d {lvalue},class AcGeMatrix2d)'''
    ...
    def translateBy (self, *args, **kwargs)-> None :
      '''translateBy( (Entity2d)arg1, (Vector2d)arg2) -> None :

    C++ signature :
        void translateBy(class PyGeEntity2d {lvalue},class AcGeVector2d)'''
    ...
    def type (self, *args, **kwargs)-> PyGe.EntityId :
      '''type( (Entity2d)arg1) -> EntityId :

    C++ signature :
        enum AcGe::EntityId type(class PyGeEntity2d {lvalue})'''
    ...

class Line3d:
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

__init__( (object)arg1, (Point3d)arg2, (Point3d)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePoint3d,class AcGePoint3d)'''
    ...
    def area (self, startParam : float, endParam : float, tol : float = default)-> float :
      '''                             '''
    ...
    def boundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock3d :
      '''                             '''
    ...
    def cast (self, *args, **kwargs)-> PyGe.Line3d :
      '''cast( (Entity3d)arg1) -> Line3d :

    C++ signature :
        class PyGeLine3d cast(class PyGeEntity3d)'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def closestPointTo (self, other : PyGe.Point3d | PyGe.Curve3d, tol : PyGe.Tol=None)-> PyGe.Point3d :
      '''                             '''
    ...
    def copy (self)-> PyGe.Entity3d :
      '''                             '''
    ...
    def copycast (self, *args, **kwargs)-> PyGe.Line3d :
      '''copycast( (Entity3d)arg1) -> Line3d :

    C++ signature :
        class PyGeLine3d copycast(class PyGeEntity3d)'''
    ...
    def direction (self, *args, **kwargs)-> PyGe.Vector3d :
      '''direction( (LinearEnt3d)arg1) -> Vector3d :

    C++ signature :
        class AcGeVector3d direction(class PyGeLinearEnt3d {lvalue})'''
    ...
    def distanceTo (self, pt : float | PyGe.Point3d, tol : PyGe.Tol=None)-> float :
      '''                             '''
    ...
    def evalPoint (self, param : float, numDeriv : int = 1)-> PyGe.Point3d :
      '''                             '''
    ...
    def explode (self, val : PyGe.Interval = None)-> list :
      '''                             '''
    ...
    def getClosestPointTo (self, other : PyGe.Point3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''                             '''
    ...
    def getClosestPointsTo (self, other : PyGe.Curve3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def getEndPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def getInterval (self)-> PyGe.Interval :
      '''                             '''
    ...
    def getLine (self, *args, **kwargs)-> PyGe.Line3d :
      '''getLine( (LinearEnt3d)arg1) -> Line3d :

    C++ signature :
        class PyGeLine3d getLine(class PyGeLinearEnt3d {lvalue})'''
    ...
    def getNormalPoint (self, pnt : PyGe.Point3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''                             '''
    ...
    def getPerpPlane (self, *args, **kwargs)-> PyGe.Plane :
      '''getPerpPlane( (LinearEnt3d)arg1, (Point3d)arg2) -> Plane :

    C++ signature :
        class PyGePlane getPerpPlane(class PyGeLinearEnt3d {lvalue},class AcGePoint3d)'''
    ...
    def getProjClosestPointTo (self, pt : PyGe.Point3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''                             '''
    ...
    def getProjClosestPointsTo (self, pt : PyGe.Curve3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def getSamplePoints (self, *args, **kwargs)-> list :
      '''getSamplePoints( (Curve3d)arg1, (int)arg2) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve3d {lvalue},int)

getSamplePoints( (Curve3d)arg1, (float)arg2, (float)arg3, (float)arg4) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve3d {lvalue},double,double,double)'''
    ...
    def getSplitCurves (self, param : float)-> tuple :
      '''                             '''
    ...
    def getStartPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def getTrimmedOffset (self, dist : float, planeNormal : PyGe.Vector3d, extensionType : PyGe.OffsetCrvExtType, tol : PyGe.Tol=None)-> list :
      '''                             '''
    ...
    def hasEndPoint (self)-> bool :
      '''                             '''
    ...
    def hasStartPoint (self)-> bool :
      '''                             '''
    ...
    def intersectWith (self, other : PyGe.LinearEnt3d | PyGe.PlanarEnt, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isClosed (self, tol : PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def isColinearTo (self, *args, **kwargs)-> bool :
      '''isColinearTo( (LinearEnt3d)arg1, (LinearEnt3d)arg2) -> bool :

    C++ signature :
        bool isColinearTo(class PyGeLinearEnt3d {lvalue},class PyGeLinearEnt3d)

isColinearTo( (LinearEnt3d)arg1, (LinearEnt3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isColinearTo(class PyGeLinearEnt3d {lvalue},class PyGeLinearEnt3d,class AcGeTol)'''
    ...
    def isCoplanarWith (self, curve : PyGe.Curve3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isDegenerate (self, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isEqualTo (self, val : PyGe.Entity3d, tol : PyGe.Tol=None)-> bool :
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
    def isOn (self, *args, **kwargs)-> tuple :
      '''isOn( (LinearEnt3d)arg1, (Point3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isOn(class PyGeLinearEnt3d {lvalue},class AcGePoint3d)

isOn( (LinearEnt3d)arg1, (Point3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple isOn(class PyGeLinearEnt3d {lvalue},class AcGePoint3d,class AcGeTol)

isOn( (LinearEnt3d)arg1, (float)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeLinearEnt3d {lvalue},double)

isOn( (LinearEnt3d)arg1, (float)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeLinearEnt3d {lvalue},double,class AcGeTol)

isOn( (LinearEnt3d)arg1, (Plane)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeLinearEnt3d {lvalue},class PyGePlane)

isOn( (LinearEnt3d)arg1, (Plane)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeLinearEnt3d {lvalue},class PyGePlane,class AcGeTol)'''
    ...
    def isParallelTo (self, *args, **kwargs)-> bool :
      '''isParallelTo( (LinearEnt3d)arg1, (LinearEnt3d)arg2) -> bool :

    C++ signature :
        bool isParallelTo(class PyGeLinearEnt3d {lvalue},class PyGeLinearEnt3d)

isParallelTo( (LinearEnt3d)arg1, (LinearEnt3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isParallelTo(class PyGeLinearEnt3d {lvalue},class PyGeLinearEnt3d,class AcGeTol)

isParallelTo( (LinearEnt3d)arg1, (PlanarEnt)arg2) -> bool :

    C++ signature :
        bool isParallelTo(class PyGeLinearEnt3d {lvalue},class PyGePlanarEnt)

isParallelTo( (LinearEnt3d)arg1, (PlanarEnt)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isParallelTo(class PyGeLinearEnt3d {lvalue},class PyGePlanarEnt,class AcGeTol)'''
    ...
    def isPeriodic (self)-> tuple :
      '''                             '''
    ...
    def isPerpendicularTo (self, *args, **kwargs)-> bool :
      '''isPerpendicularTo( (LinearEnt3d)arg1, (LinearEnt3d)arg2) -> bool :

    C++ signature :
        bool isPerpendicularTo(class PyGeLinearEnt3d {lvalue},class PyGeLinearEnt3d)

isPerpendicularTo( (LinearEnt3d)arg1, (LinearEnt3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isPerpendicularTo(class PyGeLinearEnt3d {lvalue},class PyGeLinearEnt3d,class AcGeTol)

isPerpendicularTo( (LinearEnt3d)arg1, (PlanarEnt)arg2) -> bool :

    C++ signature :
        bool isPerpendicularTo(class PyGeLinearEnt3d {lvalue},class PyGePlanarEnt)

isPerpendicularTo( (LinearEnt3d)arg1, (PlanarEnt)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isPerpendicularTo(class PyGeLinearEnt3d {lvalue},class PyGePlanarEnt,class AcGeTol)'''
    ...
    def isPlanar (self, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
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
    def length (self, frm : float, to : float, tol : float = default)-> float :
      '''                             '''
    ...
    def mirror (self, val : PyGe.Plane)-> None :
      '''                             '''
    ...
    def orthoBoundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock3d :
      '''                             '''
    ...
    def orthoProject (self, projectionPlane : PyGe.Plane, tol : PyGe.Tol=None)-> PyGe.Entity3d :
      '''                             '''
    ...
    def overlap (self, other : PyGe.LinearEnt3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def paramAtLength (self, datumParam : float, length : float, posParamDir : bool=True, tol : float = default)-> float :
      '''                             '''
    ...
    def paramOf (self, pt : PyGe.Point3d, tol : PyGe.Tol=None)-> float :
      '''                             '''
    ...
    def pointOnLine (self, *args, **kwargs)-> PyGe.Point3d :
      '''pointOnLine( (LinearEnt3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d pointOnLine(class PyGeLinearEnt3d {lvalue})'''
    ...
    def projClosestPointTo (self, pt : PyGe.Point3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.Point3d :
      '''                             '''
    ...
    def projClosestPointsTo (self, pt : PyGe.Curve3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def projIntersectWith (self, other : PyGe.LinearEnt3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def project (self, projectionPlane : PyGe.Plane, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.Entity3d :
      '''                             '''
    ...
    def reverseParam (self)-> None :
      '''                             '''
    ...
    def rotateBy (self, angle : double, vec : PyGe.Vector3d, pt : PyGe.Point3d = origin)-> None :
      '''                             '''
    ...
    def scaleBy (self, scaleFactor : double, pt : PyGe.Point3d = origin)-> None :
      '''                             '''
    ...
    def set (self, *args, **kwargs)-> None :
      '''set( (Line3d)arg1, (Point3d)arg2, (Vector3d)arg3) -> None :

    C++ signature :
        void set(class PyGeLine3d {lvalue},class AcGePoint3d,class AcGeVector3d)

set( (Line3d)arg1, (Point3d)arg2, (Point3d)arg3) -> None :

    C++ signature :
        void set(class PyGeLine3d {lvalue},class AcGePoint3d,class AcGePoint3d)'''
    ...
    def setInterval (self, val : PyGe.Interval = None)-> None :
      '''                             '''
    ...
    def transformBy (self, val : PyGe.Matrix3d)-> None :
      '''                             '''
    ...
    def translateBy (self, vec : PyGe.Vector3d)-> None :
      '''                             '''
    ...
    def type (self)-> PyGe.EntityId :
      '''                             '''
    ...

class LineSeg2d:
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
    def area (self, *args, **kwargs)-> float :
      '''area( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double area(class PyGeCurve2d {lvalue},double,double)

area( (Curve2d)arg1, (float)arg2, (float)arg3, (Tol)arg4) -> float :

    C++ signature :
        double area(class PyGeCurve2d {lvalue},double,double,class AcGeTol)'''
    ...
    def baryComb (self, *args, **kwargs)-> PyGe.Point2d :
      '''baryComb( (LineSeg2d)arg1, (float)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d baryComb(class PyGeLineSeg2d {lvalue},double)'''
    ...
    def boundBlock (self, *args, **kwargs)-> PyGe.BoundBlock2d :
      '''boundBlock( (Curve2d)arg1) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d boundBlock(class PyGeCurve2d {lvalue})

boundBlock( (Curve2d)arg1, (Interval)arg2) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d boundBlock(class PyGeCurve2d {lvalue},class PyGeInterval)'''
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
    def closestPointTo (self, *args, **kwargs)-> PyGe.Point2d :
      '''closestPointTo( (Curve2d)arg1, (Point2d)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d closestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

closestPointTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> Point2d :

    C++ signature :
        class AcGePoint2d closestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

closestPointTo( (Curve2d)arg1, (Curve2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

closestPointTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def copy (self, *args, **kwargs)-> PyGe.Entity2d :
      '''copy( (Entity2d)arg1) -> Entity2d :

    C++ signature :
        class PyGeEntity2d copy(class PyGeEntity2d {lvalue})'''
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
    def distanceTo (self, *args, **kwargs)-> float :
      '''distanceTo( (Curve2d)arg1, (Point2d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

distanceTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

distanceTo( (Curve2d)arg1, (Curve2d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

distanceTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def endPoint (self, *args, **kwargs)-> PyGe.Point2d :
      '''endPoint( (LineSeg2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d endPoint(class PyGeLineSeg2d {lvalue})'''
    ...
    def evalPoint (self, *args, **kwargs)-> PyGe.Point2d :
      '''evalPoint( (Curve2d)arg1, (float)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d evalPoint(class PyGeCurve2d {lvalue},double)

evalPoint( (Curve2d)arg1, (float)arg2, (int)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple evalPoint(class PyGeCurve2d {lvalue},double,int)'''
    ...
    def explode (self, *args, **kwargs)-> list :
      '''explode( (Curve2d)arg1) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve2d {lvalue})

explode( (Curve2d)arg1, (Interval)arg2) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def getBisector (self, *args, **kwargs)-> PyGe.Line2d :
      '''getBisector( (LineSeg2d)arg1) -> Line2d :

    C++ signature :
        class PyGeLine2d getBisector(class PyGeLineSeg2d {lvalue})'''
    ...
    def getClosestPointTo (self, *args, **kwargs)-> PyGe.PointOnCurve2d :
      '''getClosestPointTo( (Curve2d)arg1, (Point2d)arg2) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getClosestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

getClosestPointTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getClosestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def getClosestPointsTo (self, *args, **kwargs)-> tuple :
      '''getClosestPointsTo( (Curve2d)arg1, (Curve2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

getClosestPointsTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def getEndPoint (self, *args, **kwargs)-> PyGe.Point2d :
      '''getEndPoint( (Curve2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d getEndPoint(class PyGeCurve2d {lvalue})'''
    ...
    def getInterval (self, *args, **kwargs)-> PyGe.Interval :
      '''getInterval( (Curve2d)arg1) -> Interval :

    C++ signature :
        class PyGeInterval getInterval(class PyGeCurve2d {lvalue})'''
    ...
    def getLine (self, *args, **kwargs)-> PyGe.Line2d :
      '''getLine( (LinearEnt2d)arg1) -> Line2d :

    C++ signature :
        class PyGeLine2d getLine(class PyGeLinearEnt2d {lvalue})'''
    ...
    def getNormalPoint (self, *args, **kwargs)-> PyGe.PointOnCurve2d :
      '''getNormalPoint( (Curve2d)arg1, (Point2d)arg2) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getNormalPoint(class PyGeCurve2d {lvalue},class AcGePoint2d)

getNormalPoint( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getNormalPoint(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def getPerpLine (self, *args, **kwargs)-> PyGe.Line2d :
      '''getPerpLine( (LinearEnt2d)arg1, (Point2d)arg2) -> Line2d :

    C++ signature :
        class PyGeLine2d getPerpLine(class PyGeLinearEnt2d {lvalue},class AcGePoint2d)'''
    ...
    def getSamplePoints (self, *args, **kwargs)-> list :
      '''getSamplePoints( (Curve2d)arg1, (int)arg2) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve2d {lvalue},int)

getSamplePoints( (Curve2d)arg1, (float)arg2, (float)arg3, (float)arg4) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve2d {lvalue},double,double,double)'''
    ...
    def getSplitCurves (self, *args, **kwargs)-> tuple :
      '''getSplitCurves( (Curve2d)arg1, (float)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getSplitCurves(class PyGeCurve2d {lvalue},double)'''
    ...
    def getStartPoint (self, *args, **kwargs)-> PyGe.Point2d :
      '''getStartPoint( (Curve2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d getStartPoint(class PyGeCurve2d {lvalue})'''
    ...
    def getTrimmedOffset (self, *args, **kwargs)-> list :
      '''getTrimmedOffset( (Curve2d)arg1, (float)arg2, (OffsetCrvExtType)arg3) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve2d {lvalue},double,enum AcGe::OffsetCrvExtType)

getTrimmedOffset( (Curve2d)arg1, (float)arg2, (OffsetCrvExtType)arg3, (Tol)arg4) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve2d {lvalue},double,enum AcGe::OffsetCrvExtType,class AcGeTol)'''
    ...
    def hasEndPoint (self, *args, **kwargs)-> bool :
      '''hasEndPoint( (Curve2d)arg1) -> bool :

    C++ signature :
        bool hasEndPoint(class PyGeCurve2d {lvalue})'''
    ...
    def hasStartPoint (self, *args, **kwargs)-> bool :
      '''hasStartPoint( (Curve2d)arg1) -> bool :

    C++ signature :
        bool hasStartPoint(class PyGeCurve2d {lvalue})'''
    ...
    def intersectWith (self, *args, **kwargs)-> tuple :
      '''intersectWith( (LinearEnt2d)arg1, (LinearEnt2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d)

intersectWith( (LinearEnt2d)arg1, (LinearEnt2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d,class AcGeTol)'''
    ...
    def isClosed (self, *args, **kwargs)-> bool :
      '''isClosed( (Curve2d)arg1) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve2d {lvalue})

isClosed( (Curve2d)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isColinearTo (self, *args, **kwargs)-> bool :
      '''isColinearTo( (LinearEnt2d)arg1, (LinearEnt2d)arg2) -> bool :

    C++ signature :
        bool isColinearTo(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d)

isColinearTo( (LinearEnt2d)arg1, (LinearEnt2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isColinearTo(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d,class AcGeTol)'''
    ...
    def isDegenerate (self, *args, **kwargs)-> tuple :
      '''isDegenerate( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve2d {lvalue})

isDegenerate( (Curve2d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isEqualTo (self, *args, **kwargs)-> bool :
      '''isEqualTo( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d)

isEqualTo( (Entity2d)arg1, (Entity2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d,class AcGeTol)'''
    ...
    def isKindOf (self, *args, **kwargs)-> bool :
      '''isKindOf( (Entity2d)arg1, (EntityId)arg2) -> bool :

    C++ signature :
        bool isKindOf(class PyGeEntity2d {lvalue},enum AcGe::EntityId)'''
    ...
    def isLinear (self, *args, **kwargs)-> tuple :
      '''isLinear( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve2d {lvalue})

isLinear( (Curve2d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isNull (self, *args, **kwargs)-> bool :
      '''isNull( (Entity2d)arg1) -> bool :

    C++ signature :
        bool isNull(class PyGeEntity2d {lvalue})'''
    ...
    def isOn (self, *args, **kwargs)-> tuple :
      '''isOn( (Curve2d)arg1, (Point2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isOn(class PyGeCurve2d {lvalue},class AcGePoint2d)

isOn( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple isOn(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

isOn( (Curve2d)arg1, (float)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isOn(class PyGeCurve2d {lvalue},double)

isOn( (Curve2d)arg1, (float)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple isOn(class PyGeCurve2d {lvalue},double,class AcGeTol)'''
    ...
    def isParallelTo (self, *args, **kwargs)-> bool :
      '''isParallelTo( (LinearEnt2d)arg1, (LinearEnt2d)arg2) -> bool :

    C++ signature :
        bool isParallelTo(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d)

isParallelTo( (LinearEnt2d)arg1, (LinearEnt2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isParallelTo(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d,class AcGeTol)'''
    ...
    def isPeriodic (self, *args, **kwargs)-> tuple :
      '''isPeriodic( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isPeriodic(class PyGeCurve2d {lvalue})'''
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
    def mirror (self, *args, **kwargs)-> None :
      '''mirror( (Entity2d)arg1, (Line2d)arg2) -> None :

    C++ signature :
        void mirror(class PyGeEntity2d {lvalue},class PyGeLine2d)'''
    ...
    def orthoBoundBlock (self, *args, **kwargs)-> PyGe.BoundBlock2d :
      '''orthoBoundBlock( (Curve2d)arg1) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d orthoBoundBlock(class PyGeCurve2d {lvalue})

orthoBoundBlock( (Curve2d)arg1, (Interval)arg2) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d orthoBoundBlock(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def overlap (self, *args, **kwargs)-> tuple :
      '''overlap( (LinearEnt2d)arg1, (LinearEnt2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple overlap(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d)

overlap( (LinearEnt2d)arg1, (LinearEnt2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple overlap(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d,class AcGeTol)'''
    ...
    def paramAtLength (self, *args, **kwargs)-> float :
      '''paramAtLength( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve2d {lvalue},double,double)

paramAtLength( (Curve2d)arg1, (float)arg2, (float)arg3, (bool)arg4, (float)arg5) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve2d {lvalue},double,double,bool,double)'''
    ...
    def paramOf (self, *args, **kwargs)-> float :
      '''paramOf( (Curve2d)arg1, (Point2d)arg2) -> float :

    C++ signature :
        double paramOf(class PyGeCurve2d {lvalue},class AcGePoint2d)

paramOf( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double paramOf(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def pointOnLine (self, *args, **kwargs)-> PyGe.Point2d :
      '''pointOnLine( (LinearEnt2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d pointOnLine(class PyGeLinearEnt2d {lvalue})'''
    ...
    def reverseParam (self, *args, **kwargs)-> None :
      '''reverseParam( (Curve2d)arg1) -> None :

    C++ signature :
        void reverseParam(class PyGeCurve2d {lvalue})'''
    ...
    def rotateBy (self, *args, **kwargs)-> None :
      '''rotateBy( (Entity2d)arg1, (float)arg2) -> None :

    C++ signature :
        void rotateBy(class PyGeEntity2d {lvalue},double)

rotateBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> None :

    C++ signature :
        void rotateBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def scaleBy (self, *args, **kwargs)-> None :
      '''scaleBy( (Entity2d)arg1, (float)arg2) -> None :

    C++ signature :
        void scaleBy(class PyGeEntity2d {lvalue},double)

scaleBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> None :

    C++ signature :
        void scaleBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
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
    def setInterval (self, *args, **kwargs)-> None :
      '''setInterval( (Curve2d)arg1) -> None :

    C++ signature :
        void setInterval(class PyGeCurve2d {lvalue})

setInterval( (Curve2d)arg1, (Interval)arg2) -> bool :

    C++ signature :
        bool setInterval(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def startPoint (self, *args, **kwargs)-> PyGe.Point2d :
      '''startPoint( (LineSeg2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d startPoint(class PyGeLineSeg2d {lvalue})'''
    ...
    def transformBy (self, *args, **kwargs)-> None :
      '''transformBy( (Entity2d)arg1, (Matrix2d)arg2) -> None :

    C++ signature :
        void transformBy(class PyGeEntity2d {lvalue},class AcGeMatrix2d)'''
    ...
    def translateBy (self, *args, **kwargs)-> None :
      '''translateBy( (Entity2d)arg1, (Vector2d)arg2) -> None :

    C++ signature :
        void translateBy(class PyGeEntity2d {lvalue},class AcGeVector2d)'''
    ...
    def type (self, *args, **kwargs)-> PyGe.EntityId :
      '''type( (Entity2d)arg1) -> EntityId :

    C++ signature :
        enum AcGe::EntityId type(class PyGeEntity2d {lvalue})'''
    ...

class LineSeg3d:
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

__init__( (object)arg1, (Point3d)arg2, (Point3d)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePoint3d,class AcGePoint3d)'''
    ...
    def area (self, startParam : float, endParam : float, tol : float = default)-> float :
      '''                             '''
    ...
    def baryComb (self, *args, **kwargs)-> PyGe.Point3d :
      '''baryComb( (LineSeg3d)arg1, (float)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d baryComb(class PyGeLineSeg3d {lvalue},double)'''
    ...
    def boundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock3d :
      '''                             '''
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
      '''                             '''
    ...
    def copy (self)-> PyGe.Entity3d :
      '''                             '''
    ...
    def copycast (self, *args, **kwargs)-> PyGe.LineSeg3d :
      '''copycast( (Entity3d)arg1) -> LineSeg3d :

    C++ signature :
        class PyGeLineSeg3d copycast(class PyGeEntity3d)'''
    ...
    def direction (self, *args, **kwargs)-> PyGe.Vector3d :
      '''direction( (LinearEnt3d)arg1) -> Vector3d :

    C++ signature :
        class AcGeVector3d direction(class PyGeLinearEnt3d {lvalue})'''
    ...
    def distanceTo (self, pt : float | PyGe.Point3d, tol : PyGe.Tol=None)-> float :
      '''                             '''
    ...
    def endPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def evalPoint (self, param : float, numDeriv : int = 1)-> PyGe.Point3d :
      '''                             '''
    ...
    def explode (self, val : PyGe.Interval = None)-> list :
      '''                             '''
    ...
    def getBisector (self)-> PyGe.Plane :
      '''                             '''
    ...
    def getClosestPointTo (self, other : PyGe.Point3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''                             '''
    ...
    def getClosestPointsTo (self, other : PyGe.Curve3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def getEndPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def getInterval (self)-> PyGe.Interval :
      '''                             '''
    ...
    def getLine (self, *args, **kwargs)-> PyGe.Line3d :
      '''getLine( (LinearEnt3d)arg1) -> Line3d :

    C++ signature :
        class PyGeLine3d getLine(class PyGeLinearEnt3d {lvalue})'''
    ...
    def getNormalPoint (self, pnt : PyGe.Point3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''                             '''
    ...
    def getPerpPlane (self, *args, **kwargs)-> PyGe.Plane :
      '''getPerpPlane( (LinearEnt3d)arg1, (Point3d)arg2) -> Plane :

    C++ signature :
        class PyGePlane getPerpPlane(class PyGeLinearEnt3d {lvalue},class AcGePoint3d)'''
    ...
    def getProjClosestPointTo (self, pt : PyGe.Point3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''                             '''
    ...
    def getProjClosestPointsTo (self, pt : PyGe.Curve3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def getSamplePoints (self, *args, **kwargs)-> list :
      '''getSamplePoints( (Curve3d)arg1, (int)arg2) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve3d {lvalue},int)

getSamplePoints( (Curve3d)arg1, (float)arg2, (float)arg3, (float)arg4) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve3d {lvalue},double,double,double)'''
    ...
    def getSplitCurves (self, param : float)-> tuple :
      '''                             '''
    ...
    def getStartPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def getTrimmedOffset (self, dist : float, planeNormal : PyGe.Vector3d, extensionType : PyGe.OffsetCrvExtType, tol : PyGe.Tol=None)-> list :
      '''                             '''
    ...
    def hasEndPoint (self)-> bool :
      '''                             '''
    ...
    def hasStartPoint (self)-> bool :
      '''                             '''
    ...
    def intersectWith (self, other : PyGe.LinearEnt3d | PyGe.PlanarEnt, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isClosed (self, tol : PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def isColinearTo (self, *args, **kwargs)-> bool :
      '''isColinearTo( (LinearEnt3d)arg1, (LinearEnt3d)arg2) -> bool :

    C++ signature :
        bool isColinearTo(class PyGeLinearEnt3d {lvalue},class PyGeLinearEnt3d)

isColinearTo( (LinearEnt3d)arg1, (LinearEnt3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isColinearTo(class PyGeLinearEnt3d {lvalue},class PyGeLinearEnt3d,class AcGeTol)'''
    ...
    def isCoplanarWith (self, curve : PyGe.Curve3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isDegenerate (self, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isEqualTo (self, val : PyGe.Entity3d, tol : PyGe.Tol=None)-> bool :
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
    def isOn (self, *args, **kwargs)-> tuple :
      '''isOn( (LinearEnt3d)arg1, (Point3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isOn(class PyGeLinearEnt3d {lvalue},class AcGePoint3d)

isOn( (LinearEnt3d)arg1, (Point3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple isOn(class PyGeLinearEnt3d {lvalue},class AcGePoint3d,class AcGeTol)

isOn( (LinearEnt3d)arg1, (float)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeLinearEnt3d {lvalue},double)

isOn( (LinearEnt3d)arg1, (float)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeLinearEnt3d {lvalue},double,class AcGeTol)

isOn( (LinearEnt3d)arg1, (Plane)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeLinearEnt3d {lvalue},class PyGePlane)

isOn( (LinearEnt3d)arg1, (Plane)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeLinearEnt3d {lvalue},class PyGePlane,class AcGeTol)'''
    ...
    def isParallelTo (self, *args, **kwargs)-> bool :
      '''isParallelTo( (LinearEnt3d)arg1, (LinearEnt3d)arg2) -> bool :

    C++ signature :
        bool isParallelTo(class PyGeLinearEnt3d {lvalue},class PyGeLinearEnt3d)

isParallelTo( (LinearEnt3d)arg1, (LinearEnt3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isParallelTo(class PyGeLinearEnt3d {lvalue},class PyGeLinearEnt3d,class AcGeTol)

isParallelTo( (LinearEnt3d)arg1, (PlanarEnt)arg2) -> bool :

    C++ signature :
        bool isParallelTo(class PyGeLinearEnt3d {lvalue},class PyGePlanarEnt)

isParallelTo( (LinearEnt3d)arg1, (PlanarEnt)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isParallelTo(class PyGeLinearEnt3d {lvalue},class PyGePlanarEnt,class AcGeTol)'''
    ...
    def isPeriodic (self)-> tuple :
      '''                             '''
    ...
    def isPerpendicularTo (self, *args, **kwargs)-> bool :
      '''isPerpendicularTo( (LinearEnt3d)arg1, (LinearEnt3d)arg2) -> bool :

    C++ signature :
        bool isPerpendicularTo(class PyGeLinearEnt3d {lvalue},class PyGeLinearEnt3d)

isPerpendicularTo( (LinearEnt3d)arg1, (LinearEnt3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isPerpendicularTo(class PyGeLinearEnt3d {lvalue},class PyGeLinearEnt3d,class AcGeTol)

isPerpendicularTo( (LinearEnt3d)arg1, (PlanarEnt)arg2) -> bool :

    C++ signature :
        bool isPerpendicularTo(class PyGeLinearEnt3d {lvalue},class PyGePlanarEnt)

isPerpendicularTo( (LinearEnt3d)arg1, (PlanarEnt)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isPerpendicularTo(class PyGeLinearEnt3d {lvalue},class PyGePlanarEnt,class AcGeTol)'''
    ...
    def isPlanar (self, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def length (self, *args, **kwargs)-> float :
      '''length( (LineSeg3d)arg1) -> float :

    C++ signature :
        double length(class PyGeLineSeg3d {lvalue})

length( (LineSeg3d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double length(class PyGeLineSeg3d {lvalue},double,double)

length( (LineSeg3d)arg1, (float)arg2, (float)arg3, (float)arg4) -> float :

    C++ signature :
        double length(class PyGeLineSeg3d {lvalue},double,double,double)'''
    ...
    def midPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def mirror (self, val : PyGe.Plane)-> None :
      '''                             '''
    ...
    def orthoBoundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock3d :
      '''                             '''
    ...
    def orthoProject (self, projectionPlane : PyGe.Plane, tol : PyGe.Tol=None)-> PyGe.Entity3d :
      '''                             '''
    ...
    def overlap (self, other : PyGe.LinearEnt3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def paramAtLength (self, datumParam : float, length : float, posParamDir : bool=True, tol : float = default)-> float :
      '''                             '''
    ...
    def paramOf (self, pt : PyGe.Point3d, tol : PyGe.Tol=None)-> float :
      '''                             '''
    ...
    def pointOnLine (self, *args, **kwargs)-> PyGe.Point3d :
      '''pointOnLine( (LinearEnt3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d pointOnLine(class PyGeLinearEnt3d {lvalue})'''
    ...
    def projClosestPointTo (self, pt : PyGe.Point3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.Point3d :
      '''                             '''
    ...
    def projClosestPointsTo (self, pt : PyGe.Curve3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def projIntersectWith (self, other : PyGe.LinearEnt3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def project (self, projectionPlane : PyGe.Plane, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.Entity3d :
      '''                             '''
    ...
    def reverseParam (self)-> None :
      '''                             '''
    ...
    def rotateBy (self, angle : double, vec : PyGe.Vector3d, pt : PyGe.Point3d = origin)-> None :
      '''                             '''
    ...
    def scaleBy (self, scaleFactor : double, pt : PyGe.Point3d = origin)-> None :
      '''                             '''
    ...
    def set (self, *args, **kwargs)-> None :
      '''set( (LineSeg3d)arg1, (Point3d)arg2, (Vector3d)arg3) -> None :

    C++ signature :
        void set(class PyGeLineSeg3d {lvalue},class AcGePoint3d,class AcGeVector3d)

set( (LineSeg3d)arg1, (Point3d)arg2, (Point3d)arg3) -> None :

    C++ signature :
        void set(class PyGeLineSeg3d {lvalue},class AcGePoint3d,class AcGePoint3d)'''
    ...
    def setInterval (self, val : PyGe.Interval = None)-> None :
      '''                             '''
    ...
    def startPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def transformBy (self, val : PyGe.Matrix3d)-> None :
      '''                             '''
    ...
    def translateBy (self, vec : PyGe.Vector3d)-> None :
      '''                             '''
    ...
    def type (self)-> PyGe.EntityId :
      '''                             '''
    ...

class LinearEnt2d:
    def __init__ (self, *args, **kwargs)-> None :
      '''Raises an exception
This class cannot be instantiated from Python'''
    ...
    def area (self, *args, **kwargs)-> float :
      '''area( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double area(class PyGeCurve2d {lvalue},double,double)

area( (Curve2d)arg1, (float)arg2, (float)arg3, (Tol)arg4) -> float :

    C++ signature :
        double area(class PyGeCurve2d {lvalue},double,double,class AcGeTol)'''
    ...
    def boundBlock (self, *args, **kwargs)-> PyGe.BoundBlock2d :
      '''boundBlock( (Curve2d)arg1) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d boundBlock(class PyGeCurve2d {lvalue})

boundBlock( (Curve2d)arg1, (Interval)arg2) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d boundBlock(class PyGeCurve2d {lvalue},class PyGeInterval)'''
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
    def closestPointTo (self, *args, **kwargs)-> PyGe.Point2d :
      '''closestPointTo( (Curve2d)arg1, (Point2d)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d closestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

closestPointTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> Point2d :

    C++ signature :
        class AcGePoint2d closestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

closestPointTo( (Curve2d)arg1, (Curve2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

closestPointTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def copy (self, *args, **kwargs)-> PyGe.Entity2d :
      '''copy( (Entity2d)arg1) -> Entity2d :

    C++ signature :
        class PyGeEntity2d copy(class PyGeEntity2d {lvalue})'''
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
    def distanceTo (self, *args, **kwargs)-> float :
      '''distanceTo( (Curve2d)arg1, (Point2d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

distanceTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

distanceTo( (Curve2d)arg1, (Curve2d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

distanceTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def evalPoint (self, *args, **kwargs)-> PyGe.Point2d :
      '''evalPoint( (Curve2d)arg1, (float)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d evalPoint(class PyGeCurve2d {lvalue},double)

evalPoint( (Curve2d)arg1, (float)arg2, (int)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple evalPoint(class PyGeCurve2d {lvalue},double,int)'''
    ...
    def explode (self, *args, **kwargs)-> list :
      '''explode( (Curve2d)arg1) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve2d {lvalue})

explode( (Curve2d)arg1, (Interval)arg2) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def getClosestPointTo (self, *args, **kwargs)-> PyGe.PointOnCurve2d :
      '''getClosestPointTo( (Curve2d)arg1, (Point2d)arg2) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getClosestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

getClosestPointTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getClosestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def getClosestPointsTo (self, *args, **kwargs)-> tuple :
      '''getClosestPointsTo( (Curve2d)arg1, (Curve2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

getClosestPointsTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def getEndPoint (self, *args, **kwargs)-> PyGe.Point2d :
      '''getEndPoint( (Curve2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d getEndPoint(class PyGeCurve2d {lvalue})'''
    ...
    def getInterval (self, *args, **kwargs)-> PyGe.Interval :
      '''getInterval( (Curve2d)arg1) -> Interval :

    C++ signature :
        class PyGeInterval getInterval(class PyGeCurve2d {lvalue})'''
    ...
    def getLine (self, *args, **kwargs)-> PyGe.Line2d :
      '''getLine( (LinearEnt2d)arg1) -> Line2d :

    C++ signature :
        class PyGeLine2d getLine(class PyGeLinearEnt2d {lvalue})'''
    ...
    def getNormalPoint (self, *args, **kwargs)-> PyGe.PointOnCurve2d :
      '''getNormalPoint( (Curve2d)arg1, (Point2d)arg2) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getNormalPoint(class PyGeCurve2d {lvalue},class AcGePoint2d)

getNormalPoint( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getNormalPoint(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def getPerpLine (self, *args, **kwargs)-> PyGe.Line2d :
      '''getPerpLine( (LinearEnt2d)arg1, (Point2d)arg2) -> Line2d :

    C++ signature :
        class PyGeLine2d getPerpLine(class PyGeLinearEnt2d {lvalue},class AcGePoint2d)'''
    ...
    def getSamplePoints (self, *args, **kwargs)-> list :
      '''getSamplePoints( (Curve2d)arg1, (int)arg2) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve2d {lvalue},int)

getSamplePoints( (Curve2d)arg1, (float)arg2, (float)arg3, (float)arg4) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve2d {lvalue},double,double,double)'''
    ...
    def getSplitCurves (self, *args, **kwargs)-> tuple :
      '''getSplitCurves( (Curve2d)arg1, (float)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getSplitCurves(class PyGeCurve2d {lvalue},double)'''
    ...
    def getStartPoint (self, *args, **kwargs)-> PyGe.Point2d :
      '''getStartPoint( (Curve2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d getStartPoint(class PyGeCurve2d {lvalue})'''
    ...
    def getTrimmedOffset (self, *args, **kwargs)-> list :
      '''getTrimmedOffset( (Curve2d)arg1, (float)arg2, (OffsetCrvExtType)arg3) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve2d {lvalue},double,enum AcGe::OffsetCrvExtType)

getTrimmedOffset( (Curve2d)arg1, (float)arg2, (OffsetCrvExtType)arg3, (Tol)arg4) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve2d {lvalue},double,enum AcGe::OffsetCrvExtType,class AcGeTol)'''
    ...
    def hasEndPoint (self, *args, **kwargs)-> bool :
      '''hasEndPoint( (Curve2d)arg1) -> bool :

    C++ signature :
        bool hasEndPoint(class PyGeCurve2d {lvalue})'''
    ...
    def hasStartPoint (self, *args, **kwargs)-> bool :
      '''hasStartPoint( (Curve2d)arg1) -> bool :

    C++ signature :
        bool hasStartPoint(class PyGeCurve2d {lvalue})'''
    ...
    def intersectWith (self, *args, **kwargs)-> tuple :
      '''intersectWith( (LinearEnt2d)arg1, (LinearEnt2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d)

intersectWith( (LinearEnt2d)arg1, (LinearEnt2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d,class AcGeTol)'''
    ...
    def isClosed (self, *args, **kwargs)-> bool :
      '''isClosed( (Curve2d)arg1) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve2d {lvalue})

isClosed( (Curve2d)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isColinearTo (self, *args, **kwargs)-> bool :
      '''isColinearTo( (LinearEnt2d)arg1, (LinearEnt2d)arg2) -> bool :

    C++ signature :
        bool isColinearTo(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d)

isColinearTo( (LinearEnt2d)arg1, (LinearEnt2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isColinearTo(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d,class AcGeTol)'''
    ...
    def isDegenerate (self, *args, **kwargs)-> tuple :
      '''isDegenerate( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve2d {lvalue})

isDegenerate( (Curve2d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isEqualTo (self, *args, **kwargs)-> bool :
      '''isEqualTo( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d)

isEqualTo( (Entity2d)arg1, (Entity2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d,class AcGeTol)'''
    ...
    def isKindOf (self, *args, **kwargs)-> bool :
      '''isKindOf( (Entity2d)arg1, (EntityId)arg2) -> bool :

    C++ signature :
        bool isKindOf(class PyGeEntity2d {lvalue},enum AcGe::EntityId)'''
    ...
    def isLinear (self, *args, **kwargs)-> tuple :
      '''isLinear( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve2d {lvalue})

isLinear( (Curve2d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isNull (self, *args, **kwargs)-> bool :
      '''isNull( (Entity2d)arg1) -> bool :

    C++ signature :
        bool isNull(class PyGeEntity2d {lvalue})'''
    ...
    def isOn (self, *args, **kwargs)-> tuple :
      '''isOn( (Curve2d)arg1, (Point2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isOn(class PyGeCurve2d {lvalue},class AcGePoint2d)

isOn( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple isOn(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

isOn( (Curve2d)arg1, (float)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isOn(class PyGeCurve2d {lvalue},double)

isOn( (Curve2d)arg1, (float)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple isOn(class PyGeCurve2d {lvalue},double,class AcGeTol)'''
    ...
    def isParallelTo (self, *args, **kwargs)-> bool :
      '''isParallelTo( (LinearEnt2d)arg1, (LinearEnt2d)arg2) -> bool :

    C++ signature :
        bool isParallelTo(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d)

isParallelTo( (LinearEnt2d)arg1, (LinearEnt2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isParallelTo(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d,class AcGeTol)'''
    ...
    def isPeriodic (self, *args, **kwargs)-> tuple :
      '''isPeriodic( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isPeriodic(class PyGeCurve2d {lvalue})'''
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
      '''length( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double length(class PyGeCurve2d {lvalue},double,double)

length( (Curve2d)arg1, (float)arg2, (float)arg3, (float)arg4) -> float :

    C++ signature :
        double length(class PyGeCurve2d {lvalue},double,double,double)'''
    ...
    def mirror (self, *args, **kwargs)-> None :
      '''mirror( (Entity2d)arg1, (Line2d)arg2) -> None :

    C++ signature :
        void mirror(class PyGeEntity2d {lvalue},class PyGeLine2d)'''
    ...
    def orthoBoundBlock (self, *args, **kwargs)-> PyGe.BoundBlock2d :
      '''orthoBoundBlock( (Curve2d)arg1) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d orthoBoundBlock(class PyGeCurve2d {lvalue})

orthoBoundBlock( (Curve2d)arg1, (Interval)arg2) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d orthoBoundBlock(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def overlap (self, *args, **kwargs)-> tuple :
      '''overlap( (LinearEnt2d)arg1, (LinearEnt2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple overlap(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d)

overlap( (LinearEnt2d)arg1, (LinearEnt2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple overlap(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d,class AcGeTol)'''
    ...
    def paramAtLength (self, *args, **kwargs)-> float :
      '''paramAtLength( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve2d {lvalue},double,double)

paramAtLength( (Curve2d)arg1, (float)arg2, (float)arg3, (bool)arg4, (float)arg5) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve2d {lvalue},double,double,bool,double)'''
    ...
    def paramOf (self, *args, **kwargs)-> float :
      '''paramOf( (Curve2d)arg1, (Point2d)arg2) -> float :

    C++ signature :
        double paramOf(class PyGeCurve2d {lvalue},class AcGePoint2d)

paramOf( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double paramOf(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def pointOnLine (self, *args, **kwargs)-> PyGe.Point2d :
      '''pointOnLine( (LinearEnt2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d pointOnLine(class PyGeLinearEnt2d {lvalue})'''
    ...
    def reverseParam (self, *args, **kwargs)-> None :
      '''reverseParam( (Curve2d)arg1) -> None :

    C++ signature :
        void reverseParam(class PyGeCurve2d {lvalue})'''
    ...
    def rotateBy (self, *args, **kwargs)-> None :
      '''rotateBy( (Entity2d)arg1, (float)arg2) -> None :

    C++ signature :
        void rotateBy(class PyGeEntity2d {lvalue},double)

rotateBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> None :

    C++ signature :
        void rotateBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def scaleBy (self, *args, **kwargs)-> None :
      '''scaleBy( (Entity2d)arg1, (float)arg2) -> None :

    C++ signature :
        void scaleBy(class PyGeEntity2d {lvalue},double)

scaleBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> None :

    C++ signature :
        void scaleBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def setInterval (self, *args, **kwargs)-> None :
      '''setInterval( (Curve2d)arg1) -> None :

    C++ signature :
        void setInterval(class PyGeCurve2d {lvalue})

setInterval( (Curve2d)arg1, (Interval)arg2) -> bool :

    C++ signature :
        bool setInterval(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def transformBy (self, *args, **kwargs)-> None :
      '''transformBy( (Entity2d)arg1, (Matrix2d)arg2) -> None :

    C++ signature :
        void transformBy(class PyGeEntity2d {lvalue},class AcGeMatrix2d)'''
    ...
    def translateBy (self, *args, **kwargs)-> None :
      '''translateBy( (Entity2d)arg1, (Vector2d)arg2) -> None :

    C++ signature :
        void translateBy(class PyGeEntity2d {lvalue},class AcGeVector2d)'''
    ...
    def type (self, *args, **kwargs)-> PyGe.EntityId :
      '''type( (Entity2d)arg1) -> EntityId :

    C++ signature :
        enum AcGe::EntityId type(class PyGeEntity2d {lvalue})'''
    ...

class LinearEnt3d:
    def __init__ (self, *args, **kwargs)-> None :
      '''Raises an exception
This class cannot be instantiated from Python'''
    ...
    def area (self, startParam : float, endParam : float, tol : float = default)-> float :
      '''                             '''
    ...
    def boundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock3d :
      '''                             '''
    ...
    def cast (self, *args, **kwargs)-> PyGe.LinearEnt3d :
      '''cast( (Entity3d)arg1) -> LinearEnt3d :

    C++ signature :
        class PyGeLinearEnt3d cast(class PyGeEntity3d)'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def closestPointTo (self, other : PyGe.Point3d | PyGe.Curve3d, tol : PyGe.Tol=None)-> PyGe.Point3d :
      '''                             '''
    ...
    def copy (self)-> PyGe.Entity3d :
      '''                             '''
    ...
    def copycast (self, *args, **kwargs)-> PyGe.LinearEnt3d :
      '''copycast( (Entity3d)arg1) -> LinearEnt3d :

    C++ signature :
        class PyGeLinearEnt3d copycast(class PyGeEntity3d)'''
    ...
    def direction (self, *args, **kwargs)-> PyGe.Vector3d :
      '''direction( (LinearEnt3d)arg1) -> Vector3d :

    C++ signature :
        class AcGeVector3d direction(class PyGeLinearEnt3d {lvalue})'''
    ...
    def distanceTo (self, pt : float | PyGe.Point3d, tol : PyGe.Tol=None)-> float :
      '''                             '''
    ...
    def evalPoint (self, param : float, numDeriv : int = 1)-> PyGe.Point3d :
      '''                             '''
    ...
    def explode (self, val : PyGe.Interval = None)-> list :
      '''                             '''
    ...
    def getClosestPointTo (self, other : PyGe.Point3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''                             '''
    ...
    def getClosestPointsTo (self, other : PyGe.Curve3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def getEndPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def getInterval (self)-> PyGe.Interval :
      '''                             '''
    ...
    def getLine (self, *args, **kwargs)-> PyGe.Line3d :
      '''getLine( (LinearEnt3d)arg1) -> Line3d :

    C++ signature :
        class PyGeLine3d getLine(class PyGeLinearEnt3d {lvalue})'''
    ...
    def getNormalPoint (self, pnt : PyGe.Point3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''                             '''
    ...
    def getPerpPlane (self, *args, **kwargs)-> PyGe.Plane :
      '''getPerpPlane( (LinearEnt3d)arg1, (Point3d)arg2) -> Plane :

    C++ signature :
        class PyGePlane getPerpPlane(class PyGeLinearEnt3d {lvalue},class AcGePoint3d)'''
    ...
    def getProjClosestPointTo (self, pt : PyGe.Point3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''                             '''
    ...
    def getProjClosestPointsTo (self, pt : PyGe.Curve3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def getSamplePoints (self, *args, **kwargs)-> list :
      '''getSamplePoints( (Curve3d)arg1, (int)arg2) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve3d {lvalue},int)

getSamplePoints( (Curve3d)arg1, (float)arg2, (float)arg3, (float)arg4) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve3d {lvalue},double,double,double)'''
    ...
    def getSplitCurves (self, param : float)-> tuple :
      '''                             '''
    ...
    def getStartPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def getTrimmedOffset (self, dist : float, planeNormal : PyGe.Vector3d, extensionType : PyGe.OffsetCrvExtType, tol : PyGe.Tol=None)-> list :
      '''                             '''
    ...
    def hasEndPoint (self)-> bool :
      '''                             '''
    ...
    def hasStartPoint (self)-> bool :
      '''                             '''
    ...
    def intersectWith (self, other : PyGe.LinearEnt3d | PyGe.PlanarEnt, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isClosed (self, tol : PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def isColinearTo (self, *args, **kwargs)-> bool :
      '''isColinearTo( (LinearEnt3d)arg1, (LinearEnt3d)arg2) -> bool :

    C++ signature :
        bool isColinearTo(class PyGeLinearEnt3d {lvalue},class PyGeLinearEnt3d)

isColinearTo( (LinearEnt3d)arg1, (LinearEnt3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isColinearTo(class PyGeLinearEnt3d {lvalue},class PyGeLinearEnt3d,class AcGeTol)'''
    ...
    def isCoplanarWith (self, curve : PyGe.Curve3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isDegenerate (self, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isEqualTo (self, val : PyGe.Entity3d, tol : PyGe.Tol=None)-> bool :
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
    def isOn (self, *args, **kwargs)-> tuple :
      '''isOn( (LinearEnt3d)arg1, (Point3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isOn(class PyGeLinearEnt3d {lvalue},class AcGePoint3d)

isOn( (LinearEnt3d)arg1, (Point3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple isOn(class PyGeLinearEnt3d {lvalue},class AcGePoint3d,class AcGeTol)

isOn( (LinearEnt3d)arg1, (float)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeLinearEnt3d {lvalue},double)

isOn( (LinearEnt3d)arg1, (float)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeLinearEnt3d {lvalue},double,class AcGeTol)

isOn( (LinearEnt3d)arg1, (Plane)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeLinearEnt3d {lvalue},class PyGePlane)

isOn( (LinearEnt3d)arg1, (Plane)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeLinearEnt3d {lvalue},class PyGePlane,class AcGeTol)'''
    ...
    def isParallelTo (self, *args, **kwargs)-> bool :
      '''isParallelTo( (LinearEnt3d)arg1, (LinearEnt3d)arg2) -> bool :

    C++ signature :
        bool isParallelTo(class PyGeLinearEnt3d {lvalue},class PyGeLinearEnt3d)

isParallelTo( (LinearEnt3d)arg1, (LinearEnt3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isParallelTo(class PyGeLinearEnt3d {lvalue},class PyGeLinearEnt3d,class AcGeTol)

isParallelTo( (LinearEnt3d)arg1, (PlanarEnt)arg2) -> bool :

    C++ signature :
        bool isParallelTo(class PyGeLinearEnt3d {lvalue},class PyGePlanarEnt)

isParallelTo( (LinearEnt3d)arg1, (PlanarEnt)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isParallelTo(class PyGeLinearEnt3d {lvalue},class PyGePlanarEnt,class AcGeTol)'''
    ...
    def isPeriodic (self)-> tuple :
      '''                             '''
    ...
    def isPerpendicularTo (self, *args, **kwargs)-> bool :
      '''isPerpendicularTo( (LinearEnt3d)arg1, (LinearEnt3d)arg2) -> bool :

    C++ signature :
        bool isPerpendicularTo(class PyGeLinearEnt3d {lvalue},class PyGeLinearEnt3d)

isPerpendicularTo( (LinearEnt3d)arg1, (LinearEnt3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isPerpendicularTo(class PyGeLinearEnt3d {lvalue},class PyGeLinearEnt3d,class AcGeTol)

isPerpendicularTo( (LinearEnt3d)arg1, (PlanarEnt)arg2) -> bool :

    C++ signature :
        bool isPerpendicularTo(class PyGeLinearEnt3d {lvalue},class PyGePlanarEnt)

isPerpendicularTo( (LinearEnt3d)arg1, (PlanarEnt)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isPerpendicularTo(class PyGeLinearEnt3d {lvalue},class PyGePlanarEnt,class AcGeTol)'''
    ...
    def isPlanar (self, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def length (self, frm : float, to : float, tol : float = default)-> float :
      '''                             '''
    ...
    def mirror (self, val : PyGe.Plane)-> None :
      '''                             '''
    ...
    def orthoBoundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock3d :
      '''                             '''
    ...
    def orthoProject (self, projectionPlane : PyGe.Plane, tol : PyGe.Tol=None)-> PyGe.Entity3d :
      '''                             '''
    ...
    def overlap (self, other : PyGe.LinearEnt3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def paramAtLength (self, datumParam : float, length : float, posParamDir : bool=True, tol : float = default)-> float :
      '''                             '''
    ...
    def paramOf (self, pt : PyGe.Point3d, tol : PyGe.Tol=None)-> float :
      '''                             '''
    ...
    def pointOnLine (self, *args, **kwargs)-> PyGe.Point3d :
      '''pointOnLine( (LinearEnt3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d pointOnLine(class PyGeLinearEnt3d {lvalue})'''
    ...
    def projClosestPointTo (self, pt : PyGe.Point3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.Point3d :
      '''                             '''
    ...
    def projClosestPointsTo (self, pt : PyGe.Curve3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def projIntersectWith (self, other : PyGe.LinearEnt3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def project (self, projectionPlane : PyGe.Plane, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.Entity3d :
      '''                             '''
    ...
    def reverseParam (self)-> None :
      '''                             '''
    ...
    def rotateBy (self, angle : double, vec : PyGe.Vector3d, pt : PyGe.Point3d = origin)-> None :
      '''                             '''
    ...
    def scaleBy (self, scaleFactor : double, pt : PyGe.Point3d = origin)-> None :
      '''                             '''
    ...
    def setInterval (self, val : PyGe.Interval = None)-> None :
      '''                             '''
    ...
    def transformBy (self, val : PyGe.Matrix3d)-> None :
      '''                             '''
    ...
    def translateBy (self, vec : PyGe.Vector3d)-> None :
      '''                             '''
    ...
    def type (self)-> PyGe.EntityId :
      '''                             '''
    ...

class Matrix2d:
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...
    def alignCoordSys (self, *args, **kwargs)-> PyGe.Matrix2d :
      '''alignCoordSys( (Point2d)arg1, (Vector2d)arg2, (Vector2d)arg3, (Point2d)arg4, (Vector2d)arg5, (Vector2d)arg6) -> Matrix2d :

    C++ signature :
        class AcGeMatrix2d alignCoordSys(class AcGePoint2d,class AcGeVector2d,class AcGeVector2d,class AcGePoint2d,class AcGeVector2d,class AcGeVector2d)'''
    ...
    def det (self, *args, **kwargs)-> float :
      '''det( (Matrix2d)arg1) -> float :

    C++ signature :
        double det(class AcGeMatrix2d {lvalue})'''
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
    def inverse (self, *args, **kwargs)-> PyGe.Matrix2d :
      '''inverse( (Matrix2d)arg1) -> Matrix2d :

    C++ signature :
        class AcGeMatrix2d inverse(class AcGeMatrix2d {lvalue})'''
    ...
    def invert (self, *args, **kwargs)-> PyGe.Matrix2d :
      '''invert( (Matrix2d)arg1) -> Matrix2d :

    C++ signature :
        class AcGeMatrix2d {lvalue} invert(class AcGeMatrix2d {lvalue})'''
    ...
    def isConformal (self, *args, **kwargs)-> bool :
      '''isConformal( (Matrix2d)arg1, (float)arg2, (float)arg3, (bool)arg4, (Vector2d)arg5) -> bool :

    C++ signature :
        bool isConformal(class AcGeMatrix2d {lvalue},double {lvalue},double {lvalue},bool {lvalue},class AcGeVector2d {lvalue})'''
    ...
    def isEqualTo (self, *args, **kwargs)-> bool :
      '''isEqualTo( (Matrix2d)arg1, (Matrix2d)arg2 [, (Tol)AcGeTol=<PyGe.Tol object at 0x000002587A47FEB0>]) -> bool :

    C++ signature :
        bool isEqualTo(class AcGeMatrix2d {lvalue},class AcGeMatrix2d [,class AcGeTol=<PyGe.Tol object at 0x000002587A47FEB0>])'''
    ...
    def isScaledOrtho (self, *args, **kwargs)-> bool :
      '''isScaledOrtho( (Matrix2d)arg1 [, (Tol)AcGeTol=<PyGe.Tol object at 0x000002587A7FC040>]) -> bool :

    C++ signature :
        bool isScaledOrtho(class AcGeMatrix2d {lvalue} [,class AcGeTol=<PyGe.Tol object at 0x000002587A7FC040>])'''
    ...
    def isSingular (self, *args, **kwargs)-> bool :
      '''isSingular( (Matrix2d)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isSingular(class AcGeMatrix2d {lvalue},class AcGeTol)'''
    ...
    def isUniScaledOrtho (self, *args, **kwargs)-> bool :
      '''isUniScaledOrtho( (Matrix2d)arg1 [, (Tol)AcGeTol=<PyGe.Tol object at 0x000002587A47FF40>]) -> bool :

    C++ signature :
        bool isUniScaledOrtho(class AcGeMatrix2d {lvalue} [,class AcGeTol=<PyGe.Tol object at 0x000002587A47FF40>])'''
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
    def scale (self, *args, **kwargs)-> float :
      '''scale( (Matrix2d)arg1) -> float :

    C++ signature :
        double scale(class AcGeMatrix2d {lvalue})'''
    ...
    def scaling (self, *args, **kwargs)-> method

Convert a function to be a static method.

A static method does not receive an implicit first argument.
To declare a static method, use this idiom :
      '''staticmethod(function) -> method

Convert a function to be a static method.

A static method does not receive an implicit first argument.
To declare a static method, use this idiom:

     class C:
         @staticmethod
         def f(arg1, arg2, argN):
             ...

It can be called either on the class (e.g. C.f()) or on an instance
(e.g. C().f()). Both the class and the instance are ignored, and
neither is passed implicitly as the first argument to the method.

Static methods in Python are similar to those found in Java or C++.
For a more advanced concept, see the classmethod builtin.'''
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
    def toList (self, *args, **kwargs)-> list :
      '''toList( (Matrix2d)arg1) -> list :

    C++ signature :
        class boost::python::list toList(class AcGeMatrix2d)'''
    ...
    def toString (self, *args, **kwargs)-> str :
      '''toString( (Matrix2d)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > toString(class AcGeMatrix2d)'''
    ...
    def toTuple (self, *args, **kwargs)-> tuple :
      '''toTuple( (Matrix2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple toTuple(class AcGeMatrix2d)'''
    ...
    def translation (self, *args, **kwargs)-> PyGe.Vector2d :
      '''translation( (Matrix2d)arg1) -> Vector2d :

    C++ signature :
        class AcGeVector2d translation(class AcGeMatrix2d {lvalue})

translation( (Vector2d)arg1) -> Matrix2d :

    C++ signature :
        class AcGeMatrix2d translation(class AcGeVector2d)'''
    ...
    def transpose (self, *args, **kwargs)-> PyGe.Matrix2d :
      '''transpose( (Matrix2d)arg1) -> Matrix2d :

    C++ signature :
        class AcGeMatrix2d transpose(class AcGeMatrix2d {lvalue})'''
    ...
    def transposeIt (self, *args, **kwargs)-> PyGe.Matrix2d :
      '''transposeIt( (Matrix2d)arg1) -> Matrix2d :

    C++ signature :
        class AcGeMatrix2d {lvalue} transposeIt(class AcGeMatrix2d {lvalue})'''
    ...

class Matrix3d:
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)'''
    ...
    def alignCoordSys (self, *args, **kwargs)-> PyGe.Matrix3d :
      '''alignCoordSys( (Point3d)arg1, (Vector3d)arg2, (Vector3d)arg3, (Vector3d)arg4, (Point3d)arg5, (Vector3d)arg6, (Vector3d)arg7, (Vector3d)arg8) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d alignCoordSys(class AcGePoint3d,class AcGeVector3d,class AcGeVector3d,class AcGeVector3d,class AcGePoint3d,class AcGeVector3d,class AcGeVector3d,class AcGeVector3d)'''
    ...
    def convertToLocal (self, normal: PyGe.Vector3d, elev: float)-> PyGe.Matrix2d :
      '''                             '''
    ...
    def det (self)-> float :
      '''                             '''
    ...
    def elementAt (self, *args, **kwargs)-> float :
      '''elementAt( (Matrix3d)arg1, (SubentType)arg2, (SubentType)arg3) -> float :

    C++ signature :
        double elementAt(class AcGeMatrix3d {lvalue},unsigned int,unsigned int)'''
    ...
    def getCoordSystem (self, origin: PyGe.Point3d, x: PyGe.Vector3d, y: PyGe.Vector3d, z: PyGe.Vector3d)-> None :
      '''                             '''
    ...
    def inverse (self, *args, **kwargs)-> PyGe.Matrix3d :
      '''inverse( (Matrix3d)arg1) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d inverse(class AcGeMatrix3d {lvalue})

inverse( (Matrix3d)arg1, (Tol)arg2) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d inverse(class AcGeMatrix3d {lvalue},class AcGeTol)

inverse( (Matrix3d)arg1, (Matrix3d)arg2, (float)arg3) -> bool :

    C++ signature :
        bool inverse(class AcGeMatrix3d {lvalue},class AcGeMatrix3d {lvalue},double)'''
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
    def mirroring (self, *args, **kwargs)-> PyGe.Matrix3d :
      '''mirroring( (Plane)arg1) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d mirroring(class PyGePlane)

mirroring( (Point3d)arg1) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d mirroring(class AcGePoint3d)

mirroring( (object)arg1) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d mirroring(class AcGeLine3d)'''
    ...
    def norm (self)-> float :
      '''                             '''
    ...
    def planeToWorld (self, *args, **kwargs)-> PyGe.Matrix3d :
      '''planeToWorld( (Vector3d)arg1) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d planeToWorld(class AcGeVector3d)

planeToWorld( (Plane)arg1) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d planeToWorld(class PyGePlane)'''
    ...
    def postMultBy (self, val: PyGe.Matrix3d)-> PyGe.Matrix3d :
      '''                             '''
    ...
    def preMultBy (self, val: PyGe.Matrix3d)-> PyGe.Matrix3d :
      '''                             '''
    ...
    def projection (self, *args, **kwargs)-> PyGe.Matrix3d :
      '''projection( (Plane)arg1, (Vector3d)arg2) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d projection(class PyGePlane,class AcGeVector3d)'''
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
    def setToAlignCoordSys (self, *args, **kwargs)-> PyGe.Matrix3d :
      '''setToAlignCoordSys( (Matrix3d)arg1, (Point3d)arg2, (Vector3d)arg3, (Vector3d)arg4, (Vector3d)arg5, (Point3d)arg6, (Vector3d)arg7, (Vector3d)arg8, (Vector3d)arg9) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d {lvalue} setToAlignCoordSys(class AcGeMatrix3d {lvalue},class AcGePoint3d,class AcGeVector3d,class AcGeVector3d,class AcGeVector3d,class AcGePoint3d,class AcGeVector3d,class AcGeVector3d,class AcGeVector3d)'''
    ...
    def setToIdentity (self)-> PyGe.Matrix3d :
      '''                             '''
    ...
    def setToMirroring (self, *args, **kwargs)-> None :
      '''setToMirroring( (Matrix3d)arg1, (Plane)arg2) -> None :

    C++ signature :
        void setToMirroring(class AcGeMatrix3d {lvalue},class PyGePlane)

setToMirroring( (Matrix3d)arg1, (object)arg2) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d {lvalue} setToMirroring(class AcGeMatrix3d {lvalue},class AcGeLine3d)

setToMirroring( (Matrix3d)arg1, (Point3d)arg2) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d {lvalue} setToMirroring(class AcGeMatrix3d {lvalue},class AcGePoint3d)'''
    ...
    def setToPlaneToWorld (self, *args, **kwargs)-> None :
      '''setToPlaneToWorld( (Matrix3d)arg1, (Plane)arg2) -> None :

    C++ signature :
        void setToPlaneToWorld(class AcGeMatrix3d {lvalue},class PyGePlane)

setToPlaneToWorld( (Matrix3d)arg1, (Vector3d)arg2) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d {lvalue} setToPlaneToWorld(class AcGeMatrix3d {lvalue},class AcGeVector3d)'''
    ...
    def setToProduct (self, mat1: PyGe.Matrix3d, mat2: PyGe.Matrix3d)-> PyGe.Matrix3d :
      '''                             '''
    ...
    def setToProjection (self, *args, **kwargs)-> PyGe.Matrix3d :
      '''setToProjection( (Matrix3d)arg1, (object)arg2, (Vector3d)arg3) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d {lvalue} setToProjection(class AcGeMatrix3d {lvalue},class AcGePlane,class AcGeVector3d)'''
    ...
    def setToRotation (self, angle: float, axis: PyGe.Vector3d, center :PyGe.Point3d=kOrigin)-> PyGe.Matrix3d :
      '''                             '''
    ...
    def setToScaling (self, val: float, center: PyGe.Point3d=kOrigin)-> PyGe.Matrix3d :
      '''                             '''
    ...
    def setToTranslation (self, val: PyGe.Vector3d)-> PyGe.Matrix3d :
      '''                             '''
    ...
    def setToWorldToPlane (self, *args, **kwargs)-> None :
      '''setToWorldToPlane( (Matrix3d)arg1, (Plane)arg2) -> None :

    C++ signature :
        void setToWorldToPlane(class AcGeMatrix3d {lvalue},class PyGePlane)

setToWorldToPlane( (Matrix3d)arg1, (Vector3d)arg2) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d {lvalue} setToWorldToPlane(class AcGeMatrix3d {lvalue},class AcGeVector3d)'''
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
    def translation (self)-> PyGe.Vector3d :
      '''                             '''
    ...
    def transpose (self)-> PyGe.Matrix3d :
      '''                             '''
    ...
    def transposeIt (self)-> PyGe.Matrix3d :
      '''                             '''
    ...
    def worldToPlane (self, *args, **kwargs)-> PyGe.Matrix3d :
      '''worldToPlane( (Vector3d)arg1) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d worldToPlane(class AcGeVector3d)

worldToPlane( (Plane)arg1) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d worldToPlane(class PyGePlane)'''
    ...

class NurbCurve2d:
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

__init__( (object)arg1, (list)arg2, (Vector2d)arg3, (Vector2d)arg4, (bool)arg5, (bool)arg6, (AcGeKnotParameterization)arg7, (Tol)arg8) -> None :

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
    def area (self, *args, **kwargs)-> float :
      '''area( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double area(class PyGeCurve2d {lvalue},double,double)

area( (Curve2d)arg1, (float)arg2, (float)arg3, (Tol)arg4) -> float :

    C++ signature :
        double area(class PyGeCurve2d {lvalue},double,double,class AcGeTol)'''
    ...
    def boundBlock (self, *args, **kwargs)-> PyGe.BoundBlock2d :
      '''boundBlock( (Curve2d)arg1) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d boundBlock(class PyGeCurve2d {lvalue})

boundBlock( (Curve2d)arg1, (Interval)arg2) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d boundBlock(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def buildFitData (self, *args, **kwargs)-> bool :
      '''buildFitData( (NurbCurve2d)arg1) -> bool :

    C++ signature :
        bool buildFitData(class PyGeNurbCurve2d {lvalue})

buildFitData( (NurbCurve2d)arg1, (AcGeKnotParameterization)arg2) -> bool :

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
    def closestPointTo (self, *args, **kwargs)-> PyGe.Point2d :
      '''closestPointTo( (Curve2d)arg1, (Point2d)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d closestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

closestPointTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> Point2d :

    C++ signature :
        class AcGePoint2d closestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

closestPointTo( (Curve2d)arg1, (Curve2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

closestPointTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
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
    def copy (self, *args, **kwargs)-> PyGe.Entity2d :
      '''copy( (Entity2d)arg1) -> Entity2d :

    C++ signature :
        class PyGeEntity2d copy(class PyGeEntity2d {lvalue})'''
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
    def distanceTo (self, *args, **kwargs)-> float :
      '''distanceTo( (Curve2d)arg1, (Point2d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

distanceTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

distanceTo( (Curve2d)arg1, (Curve2d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

distanceTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
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
    def evalPoint (self, *args, **kwargs)-> PyGe.Point2d :
      '''evalPoint( (Curve2d)arg1, (float)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d evalPoint(class PyGeCurve2d {lvalue},double)

evalPoint( (Curve2d)arg1, (float)arg2, (int)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple evalPoint(class PyGeCurve2d {lvalue},double,int)'''
    ...
    def explode (self, *args, **kwargs)-> list :
      '''explode( (Curve2d)arg1) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve2d {lvalue})

explode( (Curve2d)arg1, (Interval)arg2) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def getClosestPointTo (self, *args, **kwargs)-> PyGe.PointOnCurve2d :
      '''getClosestPointTo( (Curve2d)arg1, (Point2d)arg2) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getClosestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

getClosestPointTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getClosestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def getClosestPointsTo (self, *args, **kwargs)-> tuple :
      '''getClosestPointsTo( (Curve2d)arg1, (Curve2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

getClosestPointsTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def getDefinitionData (self, *args, **kwargs)-> tuple :
      '''getDefinitionData( (NurbCurve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple getDefinitionData(class PyGeNurbCurve2d {lvalue})'''
    ...
    def getEndPoint (self, *args, **kwargs)-> PyGe.Point2d :
      '''getEndPoint( (Curve2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d getEndPoint(class PyGeCurve2d {lvalue})'''
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
    def getInterval (self, *args, **kwargs)-> PyGe.Interval :
      '''getInterval( (Curve2d)arg1) -> Interval :

    C++ signature :
        class PyGeInterval getInterval(class PyGeCurve2d {lvalue})'''
    ...
    def getNormalPoint (self, *args, **kwargs)-> PyGe.PointOnCurve2d :
      '''getNormalPoint( (Curve2d)arg1, (Point2d)arg2) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getNormalPoint(class PyGeCurve2d {lvalue},class AcGePoint2d)

getNormalPoint( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getNormalPoint(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
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
    def getSamplePoints (self, *args, **kwargs)-> list :
      '''getSamplePoints( (Curve2d)arg1, (int)arg2) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve2d {lvalue},int)

getSamplePoints( (Curve2d)arg1, (float)arg2, (float)arg3, (float)arg4) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve2d {lvalue},double,double,double)'''
    ...
    def getSplitCurves (self, *args, **kwargs)-> tuple :
      '''getSplitCurves( (Curve2d)arg1, (float)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getSplitCurves(class PyGeCurve2d {lvalue},double)'''
    ...
    def getStartPoint (self, *args, **kwargs)-> PyGe.Point2d :
      '''getStartPoint( (Curve2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d getStartPoint(class PyGeCurve2d {lvalue})'''
    ...
    def getTrimmedOffset (self, *args, **kwargs)-> list :
      '''getTrimmedOffset( (Curve2d)arg1, (float)arg2, (OffsetCrvExtType)arg3) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve2d {lvalue},double,enum AcGe::OffsetCrvExtType)

getTrimmedOffset( (Curve2d)arg1, (float)arg2, (OffsetCrvExtType)arg3, (Tol)arg4) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve2d {lvalue},double,enum AcGe::OffsetCrvExtType,class AcGeTol)'''
    ...
    def hardTrimByParams (self, *args, **kwargs)-> None :
      '''hardTrimByParams( (NurbCurve2d)arg1, (float)arg2, (float)arg3) -> None :

    C++ signature :
        void hardTrimByParams(class PyGeNurbCurve2d {lvalue},double,double)'''
    ...
    def hasEndPoint (self, *args, **kwargs)-> bool :
      '''hasEndPoint( (Curve2d)arg1) -> bool :

    C++ signature :
        bool hasEndPoint(class PyGeCurve2d {lvalue})'''
    ...
    def hasFitData (self, *args, **kwargs)-> bool :
      '''hasFitData( (SplineEnt2d)arg1) -> bool :

    C++ signature :
        bool hasFitData(class PyGeSplineEnt2d {lvalue})'''
    ...
    def hasStartPoint (self, *args, **kwargs)-> bool :
      '''hasStartPoint( (Curve2d)arg1) -> bool :

    C++ signature :
        bool hasStartPoint(class PyGeCurve2d {lvalue})'''
    ...
    def insertKnot (self, *args, **kwargs)-> None :
      '''insertKnot( (NurbCurve2d)arg1, (float)arg2) -> None :

    C++ signature :
        void insertKnot(class PyGeNurbCurve2d {lvalue},double)'''
    ...
    def isClosed (self, *args, **kwargs)-> bool :
      '''isClosed( (Curve2d)arg1) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve2d {lvalue})

isClosed( (Curve2d)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isDegenerate (self, *args, **kwargs)-> tuple :
      '''isDegenerate( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve2d {lvalue})

isDegenerate( (Curve2d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isEqualTo (self, *args, **kwargs)-> bool :
      '''isEqualTo( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d)

isEqualTo( (Entity2d)arg1, (Entity2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d,class AcGeTol)'''
    ...
    def isKindOf (self, *args, **kwargs)-> bool :
      '''isKindOf( (Entity2d)arg1, (EntityId)arg2) -> bool :

    C++ signature :
        bool isKindOf(class PyGeEntity2d {lvalue},enum AcGe::EntityId)'''
    ...
    def isLinear (self, *args, **kwargs)-> tuple :
      '''isLinear( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve2d {lvalue})

isLinear( (Curve2d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isNull (self, *args, **kwargs)-> bool :
      '''isNull( (Entity2d)arg1) -> bool :

    C++ signature :
        bool isNull(class PyGeEntity2d {lvalue})'''
    ...
    def isOn (self, *args, **kwargs)-> tuple :
      '''isOn( (Curve2d)arg1, (Point2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isOn(class PyGeCurve2d {lvalue},class AcGePoint2d)

isOn( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple isOn(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

isOn( (Curve2d)arg1, (float)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isOn(class PyGeCurve2d {lvalue},double)

isOn( (Curve2d)arg1, (float)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple isOn(class PyGeCurve2d {lvalue},double,class AcGeTol)'''
    ...
    def isPeriodic (self, *args, **kwargs)-> tuple :
      '''isPeriodic( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isPeriodic(class PyGeCurve2d {lvalue})'''
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
    def length (self, *args, **kwargs)-> float :
      '''length( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double length(class PyGeCurve2d {lvalue},double,double)

length( (Curve2d)arg1, (float)arg2, (float)arg3, (float)arg4) -> float :

    C++ signature :
        double length(class PyGeCurve2d {lvalue},double,double,double)'''
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
    def mirror (self, *args, **kwargs)-> None :
      '''mirror( (Entity2d)arg1, (Line2d)arg2) -> None :

    C++ signature :
        void mirror(class PyGeEntity2d {lvalue},class PyGeLine2d)'''
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
    def orthoBoundBlock (self, *args, **kwargs)-> PyGe.BoundBlock2d :
      '''orthoBoundBlock( (Curve2d)arg1) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d orthoBoundBlock(class PyGeCurve2d {lvalue})

orthoBoundBlock( (Curve2d)arg1, (Interval)arg2) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d orthoBoundBlock(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def paramAtLength (self, *args, **kwargs)-> float :
      '''paramAtLength( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve2d {lvalue},double,double)

paramAtLength( (Curve2d)arg1, (float)arg2, (float)arg3, (bool)arg4, (float)arg5) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve2d {lvalue},double,double,bool,double)'''
    ...
    def paramOf (self, *args, **kwargs)-> float :
      '''paramOf( (Curve2d)arg1, (Point2d)arg2) -> float :

    C++ signature :
        double paramOf(class PyGeCurve2d {lvalue},class AcGePoint2d)

paramOf( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double paramOf(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def purgeFitData (self, *args, **kwargs)-> bool :
      '''purgeFitData( (NurbCurve2d)arg1) -> bool :

    C++ signature :
        bool purgeFitData(class PyGeNurbCurve2d {lvalue})'''
    ...
    def reverseParam (self, *args, **kwargs)-> None :
      '''reverseParam( (Curve2d)arg1) -> None :

    C++ signature :
        void reverseParam(class PyGeCurve2d {lvalue})'''
    ...
    def rotateBy (self, *args, **kwargs)-> None :
      '''rotateBy( (Entity2d)arg1, (float)arg2) -> None :

    C++ signature :
        void rotateBy(class PyGeEntity2d {lvalue},double)

rotateBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> None :

    C++ signature :
        void rotateBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def scaleBy (self, *args, **kwargs)-> None :
      '''scaleBy( (Entity2d)arg1, (float)arg2) -> None :

    C++ signature :
        void scaleBy(class PyGeEntity2d {lvalue},double)

scaleBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> None :

    C++ signature :
        void scaleBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
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

setFitData( (NurbCurve2d)arg1, (list)arg2, (Vector2d)arg3, (Vector2d)arg4, (AcGeKnotParameterization)arg5, (Tol)arg6) -> None :

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
      '''setFitKnotParameterization( (NurbCurve2d)arg1, (AcGeKnotParameterization)arg2) -> bool :

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
    def setInterval (self, *args, **kwargs)-> None :
      '''setInterval( (Curve2d)arg1) -> None :

    C++ signature :
        void setInterval(class PyGeCurve2d {lvalue})

setInterval( (Curve2d)arg1, (Interval)arg2) -> bool :

    C++ signature :
        bool setInterval(class PyGeCurve2d {lvalue},class PyGeInterval)'''
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
    def transformBy (self, *args, **kwargs)-> None :
      '''transformBy( (Entity2d)arg1, (Matrix2d)arg2) -> None :

    C++ signature :
        void transformBy(class PyGeEntity2d {lvalue},class AcGeMatrix2d)'''
    ...
    def translateBy (self, *args, **kwargs)-> None :
      '''translateBy( (Entity2d)arg1, (Vector2d)arg2) -> None :

    C++ signature :
        void translateBy(class PyGeEntity2d {lvalue},class AcGeVector2d)'''
    ...
    def type (self, *args, **kwargs)-> PyGe.EntityId :
      '''type( (Entity2d)arg1) -> EntityId :

    C++ signature :
        enum AcGe::EntityId type(class PyGeEntity2d {lvalue})'''
    ...
    def weightAt (self, *args, **kwargs)-> float :
      '''weightAt( (NurbCurve2d)arg1, (int)arg2) -> float :

    C++ signature :
        double weightAt(class PyGeNurbCurve2d {lvalue},int)'''
    ...

class NurbCurve3d:
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

__init__( (object)arg1, (list)arg2, (Vector3d)arg3, (Vector3d)arg4, (bool)arg5, (bool)arg6, (AcGeKnotParameterization)arg7, (Tol)arg8) -> None :

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
    def area (self, startParam : float, endParam : float, tol : float = default)-> float :
      '''                             '''
    ...
    def boundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock3d :
      '''                             '''
    ...
    def buildFitData (self, *args, **kwargs)-> bool :
      '''buildFitData( (NurbCurve3d)arg1) -> bool :

    C++ signature :
        bool buildFitData(class PyGeNurbCurve3d {lvalue})

buildFitData( (NurbCurve3d)arg1, (AcGeKnotParameterization)arg2) -> bool :

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
      '''                             '''
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
      '''                             '''
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
    def distanceTo (self, pt : float | PyGe.Point3d, tol : PyGe.Tol=None)-> float :
      '''                             '''
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
      '''                             '''
    ...
    def explode (self, val : PyGe.Interval = None)-> list :
      '''                             '''
    ...
    def getClosestPointTo (self, other : PyGe.Point3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''                             '''
    ...
    def getClosestPointsTo (self, other : PyGe.Curve3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
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
      '''                             '''
    ...
    def getNormalPoint (self, pnt : PyGe.Point3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''                             '''
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
      '''                             '''
    ...
    def getProjClosestPointsTo (self, pt : PyGe.Curve3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def getSamplePoints (self, *args, **kwargs)-> list :
      '''getSamplePoints( (Curve3d)arg1, (int)arg2) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve3d {lvalue},int)

getSamplePoints( (Curve3d)arg1, (float)arg2, (float)arg3, (float)arg4) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve3d {lvalue},double,double,double)'''
    ...
    def getSplitCurves (self, param : float)-> tuple :
      '''                             '''
    ...
    def getStartPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def getTrimmedOffset (self, dist : float, planeNormal : PyGe.Vector3d, extensionType : PyGe.OffsetCrvExtType, tol : PyGe.Tol=None)-> list :
      '''                             '''
    ...
    def hardTrimByParams (self, *args, **kwargs)-> None :
      '''hardTrimByParams( (NurbCurve3d)arg1, (float)arg2, (float)arg3) -> None :

    C++ signature :
        void hardTrimByParams(class PyGeNurbCurve3d {lvalue},double,double)'''
    ...
    def hasEndPoint (self)-> bool :
      '''                             '''
    ...
    def hasFitData (self, *args, **kwargs)-> bool :
      '''hasFitData( (SplineEnt3d)arg1) -> bool :

    C++ signature :
        bool hasFitData(class PyGeSplineEnt3d {lvalue})'''
    ...
    def hasStartPoint (self)-> bool :
      '''                             '''
    ...
    def insertKnot (self, *args, **kwargs)-> None :
      '''insertKnot( (NurbCurve3d)arg1, (float)arg2) -> None :

    C++ signature :
        void insertKnot(class PyGeNurbCurve3d {lvalue},double)'''
    ...
    def isClosed (self, tol : PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def isCoplanarWith (self, curve : PyGe.Curve3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isDegenerate (self, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isEqualTo (self, val : PyGe.Entity3d, tol : PyGe.Tol=None)-> bool :
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
    def isOn (self, pt : float | PyGe.Point3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isPeriodic (self)-> tuple :
      '''                             '''
    ...
    def isPlanar (self, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
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
    def length (self, frm : float, to : float, tol : float = default)-> float :
      '''                             '''
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
      '''                             '''
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
      '''                             '''
    ...
    def orthoProject (self, projectionPlane : PyGe.Plane, tol : PyGe.Tol=None)-> PyGe.Entity3d :
      '''                             '''
    ...
    def paramAtLength (self, datumParam : float, length : float, posParamDir : bool=True, tol : float = default)-> float :
      '''                             '''
    ...
    def paramOf (self, pt : PyGe.Point3d, tol : PyGe.Tol=None)-> float :
      '''                             '''
    ...
    def projClosestPointTo (self, pt : PyGe.Point3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.Point3d :
      '''                             '''
    ...
    def projClosestPointsTo (self, pt : PyGe.Curve3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def project (self, projectionPlane : PyGe.Plane, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.Entity3d :
      '''                             '''
    ...
    def purgeFitData (self, *args, **kwargs)-> bool :
      '''purgeFitData( (NurbCurve3d)arg1) -> bool :

    C++ signature :
        bool purgeFitData(class PyGeNurbCurve3d {lvalue})'''
    ...
    def reverseParam (self)-> None :
      '''                             '''
    ...
    def rotateBy (self, angle : double, vec : PyGe.Vector3d, pt : PyGe.Point3d = origin)-> None :
      '''                             '''
    ...
    def scaleBy (self, scaleFactor : double, pt : PyGe.Point3d = origin)-> None :
      '''                             '''
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

setFitData( (NurbCurve3d)arg1, (list)arg2, (Vector3d)arg3, (Vector3d)arg4, (AcGeKnotParameterization)arg5, (Tol)arg6) -> None :

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
      '''setFitKnotParameterization( (NurbCurve3d)arg1, (AcGeKnotParameterization)arg2) -> bool :

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
      '''                             '''
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
      '''                             '''
    ...
    def translateBy (self, vec : PyGe.Vector3d)-> None :
      '''                             '''
    ...
    def type (self)-> PyGe.EntityId :
      '''                             '''
    ...
    def weightAt (self, *args, **kwargs)-> float :
      '''weightAt( (NurbCurve3d)arg1, (int)arg2) -> float :

    C++ signature :
        double weightAt(class PyGeNurbCurve3d {lvalue},int)'''
    ...

class NurbSurface:
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
      '''                             '''
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
      '''                             '''
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
    def reverseNormal (self, *args, **kwargs)-> None :
      '''reverseNormal( (Surface)arg1) -> None :

    C++ signature :
        void reverseNormal(class PyGeSurface {lvalue})'''
    ...
    def rotateBy (self, angle : double, vec : PyGe.Vector3d, pt : PyGe.Point3d = origin)-> None :
      '''                             '''
    ...
    def scaleBy (self, scaleFactor : double, pt : PyGe.Point3d = origin)-> None :
      '''                             '''
    ...
    def transformBy (self, val : PyGe.Matrix3d)-> None :
      '''                             '''
    ...
    def translateBy (self, vec : PyGe.Vector3d)-> None :
      '''                             '''
    ...
    def type (self)-> PyGe.EntityId :
      '''                             '''
    ...

class OffsetCrvExtType:
    def __init__ (self, /, *args, **kwargs) :
      '''Initialize self.  See help(type(self)) for accurate signature.'''
    ...
    def conjugate (self, *args, **kwargs)-> None :
      '''Returns self, the complex conjugate of any int.'''
    ...
    def denominator (self, *args, **kwargs)-> None :
      '''the denominator of a rational number in lowest terms'''
    ...
    def imag (self, *args, **kwargs)-> None :
      '''the imaginary part of a complex number'''
    ...
    def is_integer (self, /) :
      '''Returns True. Exists for duck type compatibility with float.is_integer.'''
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
    def numerator (self, *args, **kwargs)-> None :
      '''the numerator of a rational number in lowest terms'''
    ...
    def real (self, *args, **kwargs)-> None :
      '''the real part of a complex number'''
    ...

class OffsetCurve2d:
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1, (Curve2d)arg2, (float)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class PyGeCurve2d,double)'''
    ...
    def area (self, *args, **kwargs)-> float :
      '''area( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double area(class PyGeCurve2d {lvalue},double,double)

area( (Curve2d)arg1, (float)arg2, (float)arg3, (Tol)arg4) -> float :

    C++ signature :
        double area(class PyGeCurve2d {lvalue},double,double,class AcGeTol)'''
    ...
    def boundBlock (self, *args, **kwargs)-> PyGe.BoundBlock2d :
      '''boundBlock( (Curve2d)arg1) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d boundBlock(class PyGeCurve2d {lvalue})

boundBlock( (Curve2d)arg1, (Interval)arg2) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d boundBlock(class PyGeCurve2d {lvalue},class PyGeInterval)'''
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
    def closestPointTo (self, *args, **kwargs)-> PyGe.Point2d :
      '''closestPointTo( (Curve2d)arg1, (Point2d)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d closestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

closestPointTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> Point2d :

    C++ signature :
        class AcGePoint2d closestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

closestPointTo( (Curve2d)arg1, (Curve2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

closestPointTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def copy (self, *args, **kwargs)-> PyGe.Entity2d :
      '''copy( (Entity2d)arg1) -> Entity2d :

    C++ signature :
        class PyGeEntity2d copy(class PyGeEntity2d {lvalue})'''
    ...
    def copycast (self, *args, **kwargs)-> PyGe.OffsetCurve2d :
      '''copycast( (Entity2d)arg1) -> OffsetCurve2d :

    C++ signature :
        class PyGeOffsetCurve2d copycast(class PyGeEntity2d)'''
    ...
    def distanceTo (self, *args, **kwargs)-> float :
      '''distanceTo( (Curve2d)arg1, (Point2d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

distanceTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

distanceTo( (Curve2d)arg1, (Curve2d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

distanceTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def evalPoint (self, *args, **kwargs)-> PyGe.Point2d :
      '''evalPoint( (Curve2d)arg1, (float)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d evalPoint(class PyGeCurve2d {lvalue},double)

evalPoint( (Curve2d)arg1, (float)arg2, (int)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple evalPoint(class PyGeCurve2d {lvalue},double,int)'''
    ...
    def explode (self, *args, **kwargs)-> list :
      '''explode( (Curve2d)arg1) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve2d {lvalue})

explode( (Curve2d)arg1, (Interval)arg2) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def getClosestPointTo (self, *args, **kwargs)-> PyGe.PointOnCurve2d :
      '''getClosestPointTo( (Curve2d)arg1, (Point2d)arg2) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getClosestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

getClosestPointTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getClosestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def getClosestPointsTo (self, *args, **kwargs)-> tuple :
      '''getClosestPointsTo( (Curve2d)arg1, (Curve2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

getClosestPointsTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def getEndPoint (self, *args, **kwargs)-> PyGe.Point2d :
      '''getEndPoint( (Curve2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d getEndPoint(class PyGeCurve2d {lvalue})'''
    ...
    def getInterval (self, *args, **kwargs)-> PyGe.Interval :
      '''getInterval( (Curve2d)arg1) -> Interval :

    C++ signature :
        class PyGeInterval getInterval(class PyGeCurve2d {lvalue})'''
    ...
    def getNormalPoint (self, *args, **kwargs)-> PyGe.PointOnCurve2d :
      '''getNormalPoint( (Curve2d)arg1, (Point2d)arg2) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getNormalPoint(class PyGeCurve2d {lvalue},class AcGePoint2d)

getNormalPoint( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getNormalPoint(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def getSamplePoints (self, *args, **kwargs)-> list :
      '''getSamplePoints( (Curve2d)arg1, (int)arg2) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve2d {lvalue},int)

getSamplePoints( (Curve2d)arg1, (float)arg2, (float)arg3, (float)arg4) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve2d {lvalue},double,double,double)'''
    ...
    def getSplitCurves (self, *args, **kwargs)-> tuple :
      '''getSplitCurves( (Curve2d)arg1, (float)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getSplitCurves(class PyGeCurve2d {lvalue},double)'''
    ...
    def getStartPoint (self, *args, **kwargs)-> PyGe.Point2d :
      '''getStartPoint( (Curve2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d getStartPoint(class PyGeCurve2d {lvalue})'''
    ...
    def getTrimmedOffset (self, *args, **kwargs)-> list :
      '''getTrimmedOffset( (Curve2d)arg1, (float)arg2, (OffsetCrvExtType)arg3) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve2d {lvalue},double,enum AcGe::OffsetCrvExtType)

getTrimmedOffset( (Curve2d)arg1, (float)arg2, (OffsetCrvExtType)arg3, (Tol)arg4) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve2d {lvalue},double,enum AcGe::OffsetCrvExtType,class AcGeTol)'''
    ...
    def hasEndPoint (self, *args, **kwargs)-> bool :
      '''hasEndPoint( (Curve2d)arg1) -> bool :

    C++ signature :
        bool hasEndPoint(class PyGeCurve2d {lvalue})'''
    ...
    def hasStartPoint (self, *args, **kwargs)-> bool :
      '''hasStartPoint( (Curve2d)arg1) -> bool :

    C++ signature :
        bool hasStartPoint(class PyGeCurve2d {lvalue})'''
    ...
    def isClosed (self, *args, **kwargs)-> bool :
      '''isClosed( (Curve2d)arg1) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve2d {lvalue})

isClosed( (Curve2d)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isDegenerate (self, *args, **kwargs)-> tuple :
      '''isDegenerate( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve2d {lvalue})

isDegenerate( (Curve2d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isEqualTo (self, *args, **kwargs)-> bool :
      '''isEqualTo( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d)

isEqualTo( (Entity2d)arg1, (Entity2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d,class AcGeTol)'''
    ...
    def isKindOf (self, *args, **kwargs)-> bool :
      '''isKindOf( (Entity2d)arg1, (EntityId)arg2) -> bool :

    C++ signature :
        bool isKindOf(class PyGeEntity2d {lvalue},enum AcGe::EntityId)'''
    ...
    def isLinear (self, *args, **kwargs)-> tuple :
      '''isLinear( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve2d {lvalue})

isLinear( (Curve2d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isNull (self, *args, **kwargs)-> bool :
      '''isNull( (Entity2d)arg1) -> bool :

    C++ signature :
        bool isNull(class PyGeEntity2d {lvalue})'''
    ...
    def isOn (self, *args, **kwargs)-> tuple :
      '''isOn( (Curve2d)arg1, (Point2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isOn(class PyGeCurve2d {lvalue},class AcGePoint2d)

isOn( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple isOn(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

isOn( (Curve2d)arg1, (float)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isOn(class PyGeCurve2d {lvalue},double)

isOn( (Curve2d)arg1, (float)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple isOn(class PyGeCurve2d {lvalue},double,class AcGeTol)'''
    ...
    def isPeriodic (self, *args, **kwargs)-> tuple :
      '''isPeriodic( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isPeriodic(class PyGeCurve2d {lvalue})'''
    ...
    def length (self, *args, **kwargs)-> float :
      '''length( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double length(class PyGeCurve2d {lvalue},double,double)

length( (Curve2d)arg1, (float)arg2, (float)arg3, (float)arg4) -> float :

    C++ signature :
        double length(class PyGeCurve2d {lvalue},double,double,double)'''
    ...
    def mirror (self, *args, **kwargs)-> None :
      '''mirror( (Entity2d)arg1, (Line2d)arg2) -> None :

    C++ signature :
        void mirror(class PyGeEntity2d {lvalue},class PyGeLine2d)'''
    ...
    def orthoBoundBlock (self, *args, **kwargs)-> PyGe.BoundBlock2d :
      '''orthoBoundBlock( (Curve2d)arg1) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d orthoBoundBlock(class PyGeCurve2d {lvalue})

orthoBoundBlock( (Curve2d)arg1, (Interval)arg2) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d orthoBoundBlock(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def paramAtLength (self, *args, **kwargs)-> float :
      '''paramAtLength( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve2d {lvalue},double,double)

paramAtLength( (Curve2d)arg1, (float)arg2, (float)arg3, (bool)arg4, (float)arg5) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve2d {lvalue},double,double,bool,double)'''
    ...
    def paramOf (self, *args, **kwargs)-> float :
      '''paramOf( (Curve2d)arg1, (Point2d)arg2) -> float :

    C++ signature :
        double paramOf(class PyGeCurve2d {lvalue},class AcGePoint2d)

paramOf( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double paramOf(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def reverseParam (self, *args, **kwargs)-> None :
      '''reverseParam( (Curve2d)arg1) -> None :

    C++ signature :
        void reverseParam(class PyGeCurve2d {lvalue})'''
    ...
    def rotateBy (self, *args, **kwargs)-> None :
      '''rotateBy( (Entity2d)arg1, (float)arg2) -> None :

    C++ signature :
        void rotateBy(class PyGeEntity2d {lvalue},double)

rotateBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> None :

    C++ signature :
        void rotateBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def scaleBy (self, *args, **kwargs)-> None :
      '''scaleBy( (Entity2d)arg1, (float)arg2) -> None :

    C++ signature :
        void scaleBy(class PyGeEntity2d {lvalue},double)

scaleBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> None :

    C++ signature :
        void scaleBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def setInterval (self, *args, **kwargs)-> None :
      '''setInterval( (Curve2d)arg1) -> None :

    C++ signature :
        void setInterval(class PyGeCurve2d {lvalue})

setInterval( (Curve2d)arg1, (Interval)arg2) -> bool :

    C++ signature :
        bool setInterval(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def transformBy (self, *args, **kwargs)-> None :
      '''transformBy( (Entity2d)arg1, (Matrix2d)arg2) -> None :

    C++ signature :
        void transformBy(class PyGeEntity2d {lvalue},class AcGeMatrix2d)'''
    ...
    def translateBy (self, *args, **kwargs)-> None :
      '''translateBy( (Entity2d)arg1, (Vector2d)arg2) -> None :

    C++ signature :
        void translateBy(class PyGeEntity2d {lvalue},class AcGeVector2d)'''
    ...
    def type (self, *args, **kwargs)-> PyGe.EntityId :
      '''type( (Entity2d)arg1) -> EntityId :

    C++ signature :
        enum AcGe::EntityId type(class PyGeEntity2d {lvalue})'''
    ...

class OffsetCurve3d:
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1, (Curve3d)arg2, (Vector3d)arg3, (float)arg4) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class PyGeCurve3d,class AcGeVector3d,double)'''
    ...
    def area (self, startParam : float, endParam : float, tol : float = default)-> float :
      '''                             '''
    ...
    def boundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock3d :
      '''                             '''
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
      '''                             '''
    ...
    def copy (self)-> PyGe.Entity3d :
      '''                             '''
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
    def distanceTo (self, pt : float | PyGe.Point3d, tol : PyGe.Tol=None)-> float :
      '''                             '''
    ...
    def evalPoint (self, param : float, numDeriv : int = 1)-> PyGe.Point3d :
      '''                             '''
    ...
    def explode (self, val : PyGe.Interval = None)-> list :
      '''                             '''
    ...
    def getClosestPointTo (self, other : PyGe.Point3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''                             '''
    ...
    def getClosestPointsTo (self, other : PyGe.Curve3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def getEndPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def getInterval (self)-> PyGe.Interval :
      '''                             '''
    ...
    def getNormalPoint (self, pnt : PyGe.Point3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''                             '''
    ...
    def getProjClosestPointTo (self, pt : PyGe.Point3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''                             '''
    ...
    def getProjClosestPointsTo (self, pt : PyGe.Curve3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def getSamplePoints (self, *args, **kwargs)-> list :
      '''getSamplePoints( (Curve3d)arg1, (int)arg2) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve3d {lvalue},int)

getSamplePoints( (Curve3d)arg1, (float)arg2, (float)arg3, (float)arg4) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve3d {lvalue},double,double,double)'''
    ...
    def getSplitCurves (self, param : float)-> tuple :
      '''                             '''
    ...
    def getStartPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def getTrimmedOffset (self, dist : float, planeNormal : PyGe.Vector3d, extensionType : PyGe.OffsetCrvExtType, tol : PyGe.Tol=None)-> list :
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
    def isCoplanarWith (self, curve : PyGe.Curve3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isDegenerate (self, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isEqualTo (self, val : PyGe.Entity3d, tol : PyGe.Tol=None)-> bool :
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
    def isOn (self, pt : float | PyGe.Point3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isPeriodic (self)-> tuple :
      '''                             '''
    ...
    def isPlanar (self, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def length (self, frm : float, to : float, tol : float = default)-> float :
      '''                             '''
    ...
    def mirror (self, val : PyGe.Plane)-> None :
      '''                             '''
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
      '''                             '''
    ...
    def orthoProject (self, projectionPlane : PyGe.Plane, tol : PyGe.Tol=None)-> PyGe.Entity3d :
      '''                             '''
    ...
    def paramAtLength (self, datumParam : float, length : float, posParamDir : bool=True, tol : float = default)-> float :
      '''                             '''
    ...
    def paramDirection (self, *args, **kwargs)-> bool :
      '''paramDirection( (OffsetCurve3d)arg1) -> bool :

    C++ signature :
        bool paramDirection(class PyGeOffsetCurve3d {lvalue})'''
    ...
    def paramOf (self, pt : PyGe.Point3d, tol : PyGe.Tol=None)-> float :
      '''                             '''
    ...
    def projClosestPointTo (self, pt : PyGe.Point3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.Point3d :
      '''                             '''
    ...
    def projClosestPointsTo (self, pt : PyGe.Curve3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def project (self, projectionPlane : PyGe.Plane, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.Entity3d :
      '''                             '''
    ...
    def reverseParam (self)-> None :
      '''                             '''
    ...
    def rotateBy (self, angle : double, vec : PyGe.Vector3d, pt : PyGe.Point3d = origin)-> None :
      '''                             '''
    ...
    def scaleBy (self, scaleFactor : double, pt : PyGe.Point3d = origin)-> None :
      '''                             '''
    ...
    def setCurve (self, *args, **kwargs)-> None :
      '''setCurve( (OffsetCurve3d)arg1, (Curve3d)arg2) -> None :

    C++ signature :
        void setCurve(class PyGeOffsetCurve3d {lvalue},class PyGeCurve3d)'''
    ...
    def setInterval (self, val : PyGe.Interval = None)-> None :
      '''                             '''
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
      '''                             '''
    ...
    def transformation (self, *args, **kwargs)-> PyGe.Matrix3d :
      '''transformation( (OffsetCurve3d)arg1) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d transformation(class PyGeOffsetCurve3d {lvalue})'''
    ...
    def translateBy (self, vec : PyGe.Vector3d)-> None :
      '''                             '''
    ...
    def type (self)-> PyGe.EntityId :
      '''                             '''
    ...

class OffsetSurface:
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
      '''                             '''
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
      '''                             '''
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
    def reverseNormal (self, *args, **kwargs)-> None :
      '''reverseNormal( (Surface)arg1) -> None :

    C++ signature :
        void reverseNormal(class PyGeSurface {lvalue})'''
    ...
    def rotateBy (self, angle : double, vec : PyGe.Vector3d, pt : PyGe.Point3d = origin)-> None :
      '''                             '''
    ...
    def scaleBy (self, scaleFactor : double, pt : PyGe.Point3d = origin)-> None :
      '''                             '''
    ...
    def transformBy (self, val : PyGe.Matrix3d)-> None :
      '''                             '''
    ...
    def translateBy (self, vec : PyGe.Vector3d)-> None :
      '''                             '''
    ...
    def type (self)-> PyGe.EntityId :
      '''                             '''
    ...

class PlanarEnt:
    def __init__ (self, *args, **kwargs)-> None :
      '''Raises an exception
This class cannot be instantiated from Python'''
    ...
    def cast (self, *args, **kwargs)-> PyGe.PlanarEnt :
      '''cast( (Entity3d)arg1) -> PlanarEnt :

    C++ signature :
        class PyGePlanarEnt cast(class PyGeEntity3d)'''
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
    def closestPointToPlanarEnt (self, *args, **kwargs)-> tuple :
      '''closestPointToPlanarEnt( (PlanarEnt)arg1, (PlanarEnt)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointToPlanarEnt(class PyGePlanarEnt {lvalue},class PyGePlanarEnt)

closestPointToPlanarEnt( (PlanarEnt)arg1, (PlanarEnt)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointToPlanarEnt(class PyGePlanarEnt {lvalue},class PyGePlanarEnt,class AcGeTol)'''
    ...
    def copy (self)-> PyGe.Entity3d :
      '''                             '''
    ...
    def copycast (self, *args, **kwargs)-> PyGe.PlanarEnt :
      '''copycast( (Entity3d)arg1) -> PlanarEnt :

    C++ signature :
        class PyGePlanarEnt copycast(class PyGeEntity3d)'''
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
    def getCoefficients (self, *args, **kwargs)-> tuple :
      '''getCoefficients( (PlanarEnt)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple getCoefficients(class PyGePlanarEnt {lvalue})'''
    ...
    def getCoordSystem (self, *args, **kwargs)-> tuple :
      '''getCoordSystem( (PlanarEnt)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple getCoordSystem(class PyGePlanarEnt {lvalue})'''
    ...
    def intersectWith (self, *args, **kwargs)-> tuple :
      '''intersectWith( (PlanarEnt)arg1, (LinearEnt3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGePlanarEnt {lvalue},class PyGeLinearEnt3d)

intersectWith( (PlanarEnt)arg1, (LinearEnt3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGePlanarEnt {lvalue},class PyGeLinearEnt3d,class AcGeTol)'''
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
    def isCoplanarTo (self, *args, **kwargs)-> bool :
      '''isCoplanarTo( (PlanarEnt)arg1, (PlanarEnt)arg2) -> bool :

    C++ signature :
        bool isCoplanarTo(class PyGePlanarEnt {lvalue},class PyGePlanarEnt)

isCoplanarTo( (PlanarEnt)arg1, (PlanarEnt)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isCoplanarTo(class PyGePlanarEnt {lvalue},class PyGePlanarEnt,class AcGeTol)'''
    ...
    def isEqualTo (self, val : PyGe.Entity3d, tol : PyGe.Tol=None)-> bool :
      '''                             '''
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
    def isParallelTo (self, *args, **kwargs)-> bool :
      '''isParallelTo( (PlanarEnt)arg1, (LinearEnt3d)arg2) -> bool :

    C++ signature :
        bool isParallelTo(class PyGePlanarEnt {lvalue},class PyGeLinearEnt3d)

isParallelTo( (PlanarEnt)arg1, (LinearEnt3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isParallelTo(class PyGePlanarEnt {lvalue},class PyGeLinearEnt3d,class AcGeTol)

isParallelTo( (PlanarEnt)arg1, (PlanarEnt)arg2) -> bool :

    C++ signature :
        bool isParallelTo(class PyGePlanarEnt {lvalue},class PyGePlanarEnt)

isParallelTo( (PlanarEnt)arg1, (PlanarEnt)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isParallelTo(class PyGePlanarEnt {lvalue},class PyGePlanarEnt,class AcGeTol)'''
    ...
    def isPerpendicularTo (self, *args, **kwargs)-> bool :
      '''isPerpendicularTo( (PlanarEnt)arg1, (LinearEnt3d)arg2) -> bool :

    C++ signature :
        bool isPerpendicularTo(class PyGePlanarEnt {lvalue},class PyGeLinearEnt3d)

isPerpendicularTo( (PlanarEnt)arg1, (LinearEnt3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isPerpendicularTo(class PyGePlanarEnt {lvalue},class PyGeLinearEnt3d,class AcGeTol)

isPerpendicularTo( (PlanarEnt)arg1, (PlanarEnt)arg2) -> bool :

    C++ signature :
        bool isPerpendicularTo(class PyGePlanarEnt {lvalue},class PyGePlanarEnt)

isPerpendicularTo( (PlanarEnt)arg1, (PlanarEnt)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isPerpendicularTo(class PyGePlanarEnt {lvalue},class PyGePlanarEnt,class AcGeTol)'''
    ...
    def mirror (self, val : PyGe.Plane)-> None :
      '''                             '''
    ...
    def normal (self, *args, **kwargs)-> PyGe.Vector3d :
      '''normal( (PlanarEnt)arg1) -> Vector3d :

    C++ signature :
        class AcGeVector3d normal(class PyGePlanarEnt {lvalue})'''
    ...
    def paramOf (self, *args, **kwargs)-> PyGe.Point2d :
      '''paramOf( (Surface)arg1, (Point3d)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d paramOf(class PyGeSurface {lvalue},class AcGePoint3d)

paramOf( (Surface)arg1, (Point3d)arg2, (Tol)arg3) -> Point2d :

    C++ signature :
        class AcGePoint2d paramOf(class PyGeSurface {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def pointOnPlane (self, *args, **kwargs)-> PyGe.Point3d :
      '''pointOnPlane( (PlanarEnt)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d pointOnPlane(class PyGePlanarEnt {lvalue})'''
    ...
    def reverseNormal (self, *args, **kwargs)-> None :
      '''reverseNormal( (Surface)arg1) -> None :

    C++ signature :
        void reverseNormal(class PyGeSurface {lvalue})'''
    ...
    def rotateBy (self, angle : double, vec : PyGe.Vector3d, pt : PyGe.Point3d = origin)-> None :
      '''                             '''
    ...
    def scaleBy (self, scaleFactor : double, pt : PyGe.Point3d = origin)-> None :
      '''                             '''
    ...
    def transformBy (self, val : PyGe.Matrix3d)-> None :
      '''                             '''
    ...
    def translateBy (self, vec : PyGe.Vector3d)-> None :
      '''                             '''
    ...
    def type (self)-> PyGe.EntityId :
      '''                             '''
    ...

class Plane:
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
    def closestPointToPlanarEnt (self, *args, **kwargs)-> tuple :
      '''closestPointToPlanarEnt( (PlanarEnt)arg1, (PlanarEnt)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointToPlanarEnt(class PyGePlanarEnt {lvalue},class PyGePlanarEnt)

closestPointToPlanarEnt( (PlanarEnt)arg1, (PlanarEnt)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointToPlanarEnt(class PyGePlanarEnt {lvalue},class PyGePlanarEnt,class AcGeTol)'''
    ...
    def copy (self)-> PyGe.Entity3d :
      '''                             '''
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
    def getCoefficients (self, *args, **kwargs)-> tuple :
      '''getCoefficients( (PlanarEnt)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple getCoefficients(class PyGePlanarEnt {lvalue})'''
    ...
    def getCoordSystem (self, *args, **kwargs)-> tuple :
      '''getCoordSystem( (PlanarEnt)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple getCoordSystem(class PyGePlanarEnt {lvalue})'''
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
    def isCoplanarTo (self, *args, **kwargs)-> bool :
      '''isCoplanarTo( (PlanarEnt)arg1, (PlanarEnt)arg2) -> bool :

    C++ signature :
        bool isCoplanarTo(class PyGePlanarEnt {lvalue},class PyGePlanarEnt)

isCoplanarTo( (PlanarEnt)arg1, (PlanarEnt)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isCoplanarTo(class PyGePlanarEnt {lvalue},class PyGePlanarEnt,class AcGeTol)'''
    ...
    def isEqualTo (self, val : PyGe.Entity3d, tol : PyGe.Tol=None)-> bool :
      '''                             '''
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
    def isParallelTo (self, *args, **kwargs)-> bool :
      '''isParallelTo( (PlanarEnt)arg1, (LinearEnt3d)arg2) -> bool :

    C++ signature :
        bool isParallelTo(class PyGePlanarEnt {lvalue},class PyGeLinearEnt3d)

isParallelTo( (PlanarEnt)arg1, (LinearEnt3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isParallelTo(class PyGePlanarEnt {lvalue},class PyGeLinearEnt3d,class AcGeTol)

isParallelTo( (PlanarEnt)arg1, (PlanarEnt)arg2) -> bool :

    C++ signature :
        bool isParallelTo(class PyGePlanarEnt {lvalue},class PyGePlanarEnt)

isParallelTo( (PlanarEnt)arg1, (PlanarEnt)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isParallelTo(class PyGePlanarEnt {lvalue},class PyGePlanarEnt,class AcGeTol)'''
    ...
    def isPerpendicularTo (self, *args, **kwargs)-> bool :
      '''isPerpendicularTo( (PlanarEnt)arg1, (LinearEnt3d)arg2) -> bool :

    C++ signature :
        bool isPerpendicularTo(class PyGePlanarEnt {lvalue},class PyGeLinearEnt3d)

isPerpendicularTo( (PlanarEnt)arg1, (LinearEnt3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isPerpendicularTo(class PyGePlanarEnt {lvalue},class PyGeLinearEnt3d,class AcGeTol)

isPerpendicularTo( (PlanarEnt)arg1, (PlanarEnt)arg2) -> bool :

    C++ signature :
        bool isPerpendicularTo(class PyGePlanarEnt {lvalue},class PyGePlanarEnt)

isPerpendicularTo( (PlanarEnt)arg1, (PlanarEnt)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isPerpendicularTo(class PyGePlanarEnt {lvalue},class PyGePlanarEnt,class AcGeTol)'''
    ...
    def mirror (self, val : PyGe.Plane)-> None :
      '''                             '''
    ...
    def normal (self, *args, **kwargs)-> PyGe.Vector3d :
      '''normal( (PlanarEnt)arg1) -> Vector3d :

    C++ signature :
        class AcGeVector3d normal(class PyGePlanarEnt {lvalue})'''
    ...
    def paramOf (self, *args, **kwargs)-> PyGe.Point2d :
      '''paramOf( (Surface)arg1, (Point3d)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d paramOf(class PyGeSurface {lvalue},class AcGePoint3d)

paramOf( (Surface)arg1, (Point3d)arg2, (Tol)arg3) -> Point2d :

    C++ signature :
        class AcGePoint2d paramOf(class PyGeSurface {lvalue},class AcGePoint3d,class AcGeTol)'''
    ...
    def pointOnPlane (self, *args, **kwargs)-> PyGe.Point3d :
      '''pointOnPlane( (PlanarEnt)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d pointOnPlane(class PyGePlanarEnt {lvalue})'''
    ...
    def reverseNormal (self, *args, **kwargs)-> None :
      '''reverseNormal( (Surface)arg1) -> None :

    C++ signature :
        void reverseNormal(class PyGeSurface {lvalue})'''
    ...
    def rotateBy (self, angle : double, vec : PyGe.Vector3d, pt : PyGe.Point3d = origin)-> None :
      '''                             '''
    ...
    def scaleBy (self, scaleFactor : double, pt : PyGe.Point3d = origin)-> None :
      '''                             '''
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
      '''                             '''
    ...
    def translateBy (self, vec : PyGe.Vector3d)-> None :
      '''                             '''
    ...
    def type (self)-> PyGe.EntityId :
      '''                             '''
    ...

class Point2d:
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

__init__( (object)arg1, (object)arg2) -> object :

    C++ signature :
        void * __ptr64 __init__(class boost::python::api::object,class boost::python::api::object)'''
    ...
    def asVector (self, *args, **kwargs)-> PyGe.Vector2d :
      '''asVector( (Point2d)arg1) -> Vector2d :

    C++ signature :
        class AcGeVector2d asVector(class AcGePoint2d {lvalue})'''
    ...
    def distanceTo (self, *args, **kwargs)-> float :
      '''distanceTo( (Point2d)arg1, (Point2d)arg2) -> float :

    C++ signature :
        double distanceTo(class AcGePoint2d {lvalue},class AcGePoint2d)'''
    ...
    def isEqualTo (self, *args, **kwargs)-> bool :
      '''isEqualTo( (Point2d)arg1, (Point2d)arg2 [, (Tol)AcGeTol=<PyGe.Tol object at 0x000002587A47F880>]) -> bool :

    C++ signature :
        bool isEqualTo(class AcGePoint2d {lvalue},class AcGePoint2d [,class AcGeTol=<PyGe.Tol object at 0x000002587A47F880>])'''
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
    def toList (self, *args, **kwargs)-> list :
      '''toList( (Point2d)arg1) -> list :

    C++ signature :
        class boost::python::list toList(class AcGePoint2d)'''
    ...
    def toString (self, *args, **kwargs)-> str :
      '''toString( (Point2d)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > toString(class AcGePoint2d)'''
    ...
    def toTuple (self, *args, **kwargs)-> tuple :
      '''toTuple( (Point2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple toTuple(class AcGePoint2d)'''
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

class Point3d:
    def __init__ (self, x: float, y: float, z: float)-> None :
      '''                             '''
    ...
    def asVector (self)-> PyGe.Vector3d :
      '''                             '''
    ...
    def convert2d (self, *args, **kwargs)-> PyGe.Point2d :
      '''convert2d( (Point3d)arg1, (object)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d convert2d(class AcGePoint3d {lvalue},class AcGePlanarEnt)'''
    ...
    def distanceTo (self, pnt: PyGe.Point3d)-> float :
      '''                             '''
    ...
    def isEqualTo (self, pnt: PyGe.Point3d, tol: PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def kOrigin (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def mirror (self, pln: PyGe.Plane)-> PyGe.Point3d :
      '''                             '''
    ...
    def orthoProject (self, pln: PyGe.Plane)-> PyGe.Point3d :
      '''                             '''
    ...
    def project (self, pln: PyGe.Plane, vec:  PyGe.Vector3d)-> PyGe.Point3d :
      '''                             '''
    ...
    def rotateBy (self, angle: float, vec:  PyGe.Vector3d, wrtPoint:  PyGe.Point3d=Point3d.kOrigin)-> PyGe.Point3d :
      '''                             '''
    ...
    def scaleBy (self, factor: float, pnt:  PyGe.Point3d=orgin)-> PyGe.Point3d :
      '''                             '''
    ...
    def set (self, x: float, y: float, z: float)-> PyGe.Point3d :
      '''                             '''
    ...
    def setToProduct (self, mat: PyGe.Matrix3d, pnt:  PyGe.Point3d)-> PyGe.Point3d :
      '''                             '''
    ...
    def setToSum (self, pnt:  PyGe.Point3d, vec:  PyGe.Vector3d)-> PyGe.Point3d :
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
    def transformBy (self, mat: PyGe.Matrix3d)-> PyGe.Point3d :
      '''                             '''
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

class PointEnt2d:
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
    def copy (self, *args, **kwargs)-> PyGe.Entity2d :
      '''copy( (Entity2d)arg1) -> Entity2d :

    C++ signature :
        class PyGeEntity2d copy(class PyGeEntity2d {lvalue})'''
    ...
    def copycast (self, *args, **kwargs)-> PyGe.PointEnt2d :
      '''copycast( (Entity2d)arg1) -> PointEnt2d :

    C++ signature :
        class PyGePointEnt2d copycast(class PyGeEntity2d)'''
    ...
    def isEqualTo (self, *args, **kwargs)-> bool :
      '''isEqualTo( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d)

isEqualTo( (Entity2d)arg1, (Entity2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d,class AcGeTol)'''
    ...
    def isKindOf (self, *args, **kwargs)-> bool :
      '''isKindOf( (Entity2d)arg1, (EntityId)arg2) -> bool :

    C++ signature :
        bool isKindOf(class PyGeEntity2d {lvalue},enum AcGe::EntityId)'''
    ...
    def isNull (self, *args, **kwargs)-> bool :
      '''isNull( (Entity2d)arg1) -> bool :

    C++ signature :
        bool isNull(class PyGeEntity2d {lvalue})'''
    ...
    def isOn (self, *args, **kwargs)-> bool :
      '''isOn( (Entity2d)arg1, (Point2d)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeEntity2d {lvalue},class AcGePoint2d)

isOn( (Entity2d)arg1, (Point2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeEntity2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def mirror (self, *args, **kwargs)-> None :
      '''mirror( (Entity2d)arg1, (Line2d)arg2) -> None :

    C++ signature :
        void mirror(class PyGeEntity2d {lvalue},class PyGeLine2d)'''
    ...
    def point2d (self, *args, **kwargs)-> PyGe.Point2d :
      '''point2d( (PointEnt2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d point2d(class PyGePointEnt2d {lvalue})'''
    ...
    def rotateBy (self, *args, **kwargs)-> None :
      '''rotateBy( (Entity2d)arg1, (float)arg2) -> None :

    C++ signature :
        void rotateBy(class PyGeEntity2d {lvalue},double)

rotateBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> None :

    C++ signature :
        void rotateBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def scaleBy (self, *args, **kwargs)-> None :
      '''scaleBy( (Entity2d)arg1, (float)arg2) -> None :

    C++ signature :
        void scaleBy(class PyGeEntity2d {lvalue},double)

scaleBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> None :

    C++ signature :
        void scaleBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def transformBy (self, *args, **kwargs)-> None :
      '''transformBy( (Entity2d)arg1, (Matrix2d)arg2) -> None :

    C++ signature :
        void transformBy(class PyGeEntity2d {lvalue},class AcGeMatrix2d)'''
    ...
    def translateBy (self, *args, **kwargs)-> None :
      '''translateBy( (Entity2d)arg1, (Vector2d)arg2) -> None :

    C++ signature :
        void translateBy(class PyGeEntity2d {lvalue},class AcGeVector2d)'''
    ...
    def type (self, *args, **kwargs)-> PyGe.EntityId :
      '''type( (Entity2d)arg1) -> EntityId :

    C++ signature :
        enum AcGe::EntityId type(class PyGeEntity2d {lvalue})'''
    ...

class PointEnt3d:
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
      '''                             '''
    ...
    def copycast (self, *args, **kwargs)-> PyGe.PointEnt3d :
      '''copycast( (Entity3d)arg1) -> PointEnt3d :

    C++ signature :
        class PyGePointEnt3d copycast(class PyGeEntity3d)'''
    ...
    def isEqualTo (self, val : PyGe.Entity3d, tol : PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def isKindOf (self, val : PyGe.EntityId)-> bool :
      '''                             '''
    ...
    def isNull (self)-> bool :
      '''                             '''
    ...
    def isOn (self, pt : PyGe.Point3d, tol : PyGe.Tol=default)-> bool :
      '''                             '''
    ...
    def mirror (self, val : PyGe.Plane)-> None :
      '''                             '''
    ...
    def point3d (self, *args, **kwargs)-> PyGe.Point3d :
      '''point3d( (PointEnt3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d point3d(class PyGePointEnt3d {lvalue})'''
    ...
    def rotateBy (self, angle : double, vec : PyGe.Vector3d, pt : PyGe.Point3d = origin)-> None :
      '''                             '''
    ...
    def scaleBy (self, scaleFactor : double, pt : PyGe.Point3d = origin)-> None :
      '''                             '''
    ...
    def transformBy (self, val : PyGe.Matrix3d)-> None :
      '''                             '''
    ...
    def translateBy (self, vec : PyGe.Vector3d)-> None :
      '''                             '''
    ...
    def type (self)-> PyGe.EntityId :
      '''                             '''
    ...

class PointOnCurve2d:
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
    def copy (self, *args, **kwargs)-> PyGe.Entity2d :
      '''copy( (Entity2d)arg1) -> Entity2d :

    C++ signature :
        class PyGeEntity2d copy(class PyGeEntity2d {lvalue})'''
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
    def isEqualTo (self, *args, **kwargs)-> bool :
      '''isEqualTo( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d)

isEqualTo( (Entity2d)arg1, (Entity2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d,class AcGeTol)'''
    ...
    def isKindOf (self, *args, **kwargs)-> bool :
      '''isKindOf( (Entity2d)arg1, (EntityId)arg2) -> bool :

    C++ signature :
        bool isKindOf(class PyGeEntity2d {lvalue},enum AcGe::EntityId)'''
    ...
    def isNull (self, *args, **kwargs)-> bool :
      '''isNull( (Entity2d)arg1) -> bool :

    C++ signature :
        bool isNull(class PyGeEntity2d {lvalue})'''
    ...
    def isOn (self, *args, **kwargs)-> bool :
      '''isOn( (Entity2d)arg1, (Point2d)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeEntity2d {lvalue},class AcGePoint2d)

isOn( (Entity2d)arg1, (Point2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeEntity2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def mirror (self, *args, **kwargs)-> None :
      '''mirror( (Entity2d)arg1, (Line2d)arg2) -> None :

    C++ signature :
        void mirror(class PyGeEntity2d {lvalue},class PyGeLine2d)'''
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
    def rotateBy (self, *args, **kwargs)-> None :
      '''rotateBy( (Entity2d)arg1, (float)arg2) -> None :

    C++ signature :
        void rotateBy(class PyGeEntity2d {lvalue},double)

rotateBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> None :

    C++ signature :
        void rotateBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def scaleBy (self, *args, **kwargs)-> None :
      '''scaleBy( (Entity2d)arg1, (float)arg2) -> None :

    C++ signature :
        void scaleBy(class PyGeEntity2d {lvalue},double)

scaleBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> None :

    C++ signature :
        void scaleBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
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
    def transformBy (self, *args, **kwargs)-> None :
      '''transformBy( (Entity2d)arg1, (Matrix2d)arg2) -> None :

    C++ signature :
        void transformBy(class PyGeEntity2d {lvalue},class AcGeMatrix2d)'''
    ...
    def translateBy (self, *args, **kwargs)-> None :
      '''translateBy( (Entity2d)arg1, (Vector2d)arg2) -> None :

    C++ signature :
        void translateBy(class PyGeEntity2d {lvalue},class AcGeVector2d)'''
    ...
    def type (self, *args, **kwargs)-> PyGe.EntityId :
      '''type( (Entity2d)arg1) -> EntityId :

    C++ signature :
        enum AcGe::EntityId type(class PyGeEntity2d {lvalue})'''
    ...

class PointOnCurve3d:
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
      '''                             '''
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
      '''                             '''
    ...
    def isKindOf (self, val : PyGe.EntityId)-> bool :
      '''                             '''
    ...
    def isNull (self)-> bool :
      '''                             '''
    ...
    def isOn (self, pt : PyGe.Point3d, tol : PyGe.Tol=default)-> bool :
      '''                             '''
    ...
    def isSingular (self, *args, **kwargs)-> bool :
      '''isSingular( (PointOnCurve3d)arg1) -> bool :

    C++ signature :
        bool isSingular(class PyGePointOnCurve3d {lvalue})'''
    ...
    def mirror (self, val : PyGe.Plane)-> None :
      '''                             '''
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
    def rotateBy (self, angle : double, vec : PyGe.Vector3d, pt : PyGe.Point3d = origin)-> None :
      '''                             '''
    ...
    def scaleBy (self, scaleFactor : double, pt : PyGe.Point3d = origin)-> None :
      '''                             '''
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
      '''                             '''
    ...
    def translateBy (self, vec : PyGe.Vector3d)-> None :
      '''                             '''
    ...
    def type (self)-> PyGe.EntityId :
      '''                             '''
    ...

class PointOnSurface:
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
      '''                             '''
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
      '''                             '''
    ...
    def isKindOf (self, val : PyGe.EntityId)-> bool :
      '''                             '''
    ...
    def isNull (self)-> bool :
      '''                             '''
    ...
    def isOn (self, pt : PyGe.Point3d, tol : PyGe.Tol=default)-> bool :
      '''                             '''
    ...
    def mirror (self, val : PyGe.Plane)-> None :
      '''                             '''
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
    def rotateBy (self, angle : double, vec : PyGe.Vector3d, pt : PyGe.Point3d = origin)-> None :
      '''                             '''
    ...
    def scaleBy (self, scaleFactor : double, pt : PyGe.Point3d = origin)-> None :
      '''                             '''
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
      '''                             '''
    ...
    def translateBy (self, vec : PyGe.Vector3d)-> None :
      '''                             '''
    ...
    def type (self)-> PyGe.EntityId :
      '''                             '''
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

class Polyline2d:
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
    def area (self, *args, **kwargs)-> float :
      '''area( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double area(class PyGeCurve2d {lvalue},double,double)

area( (Curve2d)arg1, (float)arg2, (float)arg3, (Tol)arg4) -> float :

    C++ signature :
        double area(class PyGeCurve2d {lvalue},double,double,class AcGeTol)'''
    ...
    def boundBlock (self, *args, **kwargs)-> PyGe.BoundBlock2d :
      '''boundBlock( (Curve2d)arg1) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d boundBlock(class PyGeCurve2d {lvalue})

boundBlock( (Curve2d)arg1, (Interval)arg2) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d boundBlock(class PyGeCurve2d {lvalue},class PyGeInterval)'''
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
    def closestPointTo (self, *args, **kwargs)-> PyGe.Point2d :
      '''closestPointTo( (Curve2d)arg1, (Point2d)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d closestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

closestPointTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> Point2d :

    C++ signature :
        class AcGePoint2d closestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

closestPointTo( (Curve2d)arg1, (Curve2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

closestPointTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
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
    def copy (self, *args, **kwargs)-> PyGe.Entity2d :
      '''copy( (Entity2d)arg1) -> Entity2d :

    C++ signature :
        class PyGeEntity2d copy(class PyGeEntity2d {lvalue})'''
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
    def distanceTo (self, *args, **kwargs)-> float :
      '''distanceTo( (Curve2d)arg1, (Point2d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

distanceTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

distanceTo( (Curve2d)arg1, (Curve2d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

distanceTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
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
    def evalPoint (self, *args, **kwargs)-> PyGe.Point2d :
      '''evalPoint( (Curve2d)arg1, (float)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d evalPoint(class PyGeCurve2d {lvalue},double)

evalPoint( (Curve2d)arg1, (float)arg2, (int)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple evalPoint(class PyGeCurve2d {lvalue},double,int)'''
    ...
    def explode (self, *args, **kwargs)-> list :
      '''explode( (Curve2d)arg1) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve2d {lvalue})

explode( (Curve2d)arg1, (Interval)arg2) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def fitPointAt (self, *args, **kwargs)-> PyGe.Point2d :
      '''fitPointAt( (Polyline2d)arg1, (int)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d fitPointAt(class PyGePolyline2d {lvalue},int)'''
    ...
    def getClosestPointTo (self, *args, **kwargs)-> PyGe.PointOnCurve2d :
      '''getClosestPointTo( (Curve2d)arg1, (Point2d)arg2) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getClosestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

getClosestPointTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getClosestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def getClosestPointsTo (self, *args, **kwargs)-> tuple :
      '''getClosestPointsTo( (Curve2d)arg1, (Curve2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

getClosestPointsTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def getEndPoint (self, *args, **kwargs)-> PyGe.Point2d :
      '''getEndPoint( (Curve2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d getEndPoint(class PyGeCurve2d {lvalue})'''
    ...
    def getInterval (self, *args, **kwargs)-> PyGe.Interval :
      '''getInterval( (Curve2d)arg1) -> Interval :

    C++ signature :
        class PyGeInterval getInterval(class PyGeCurve2d {lvalue})'''
    ...
    def getNormalPoint (self, *args, **kwargs)-> PyGe.PointOnCurve2d :
      '''getNormalPoint( (Curve2d)arg1, (Point2d)arg2) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getNormalPoint(class PyGeCurve2d {lvalue},class AcGePoint2d)

getNormalPoint( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getNormalPoint(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def getSamplePoints (self, *args, **kwargs)-> list :
      '''getSamplePoints( (Curve2d)arg1, (int)arg2) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve2d {lvalue},int)

getSamplePoints( (Curve2d)arg1, (float)arg2, (float)arg3, (float)arg4) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve2d {lvalue},double,double,double)'''
    ...
    def getSplitCurves (self, *args, **kwargs)-> tuple :
      '''getSplitCurves( (Curve2d)arg1, (float)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getSplitCurves(class PyGeCurve2d {lvalue},double)'''
    ...
    def getStartPoint (self, *args, **kwargs)-> PyGe.Point2d :
      '''getStartPoint( (Curve2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d getStartPoint(class PyGeCurve2d {lvalue})'''
    ...
    def getTrimmedOffset (self, *args, **kwargs)-> list :
      '''getTrimmedOffset( (Curve2d)arg1, (float)arg2, (OffsetCrvExtType)arg3) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve2d {lvalue},double,enum AcGe::OffsetCrvExtType)

getTrimmedOffset( (Curve2d)arg1, (float)arg2, (OffsetCrvExtType)arg3, (Tol)arg4) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve2d {lvalue},double,enum AcGe::OffsetCrvExtType,class AcGeTol)'''
    ...
    def hasEndPoint (self, *args, **kwargs)-> bool :
      '''hasEndPoint( (Curve2d)arg1) -> bool :

    C++ signature :
        bool hasEndPoint(class PyGeCurve2d {lvalue})'''
    ...
    def hasFitData (self, *args, **kwargs)-> bool :
      '''hasFitData( (SplineEnt2d)arg1) -> bool :

    C++ signature :
        bool hasFitData(class PyGeSplineEnt2d {lvalue})'''
    ...
    def hasStartPoint (self, *args, **kwargs)-> bool :
      '''hasStartPoint( (Curve2d)arg1) -> bool :

    C++ signature :
        bool hasStartPoint(class PyGeCurve2d {lvalue})'''
    ...
    def isClosed (self, *args, **kwargs)-> bool :
      '''isClosed( (Curve2d)arg1) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve2d {lvalue})

isClosed( (Curve2d)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isDegenerate (self, *args, **kwargs)-> tuple :
      '''isDegenerate( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve2d {lvalue})

isDegenerate( (Curve2d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isEqualTo (self, *args, **kwargs)-> bool :
      '''isEqualTo( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d)

isEqualTo( (Entity2d)arg1, (Entity2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d,class AcGeTol)'''
    ...
    def isKindOf (self, *args, **kwargs)-> bool :
      '''isKindOf( (Entity2d)arg1, (EntityId)arg2) -> bool :

    C++ signature :
        bool isKindOf(class PyGeEntity2d {lvalue},enum AcGe::EntityId)'''
    ...
    def isLinear (self, *args, **kwargs)-> tuple :
      '''isLinear( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve2d {lvalue})

isLinear( (Curve2d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isNull (self, *args, **kwargs)-> bool :
      '''isNull( (Entity2d)arg1) -> bool :

    C++ signature :
        bool isNull(class PyGeEntity2d {lvalue})'''
    ...
    def isOn (self, *args, **kwargs)-> tuple :
      '''isOn( (Curve2d)arg1, (Point2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isOn(class PyGeCurve2d {lvalue},class AcGePoint2d)

isOn( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple isOn(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

isOn( (Curve2d)arg1, (float)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isOn(class PyGeCurve2d {lvalue},double)

isOn( (Curve2d)arg1, (float)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple isOn(class PyGeCurve2d {lvalue},double,class AcGeTol)'''
    ...
    def isPeriodic (self, *args, **kwargs)-> tuple :
      '''isPeriodic( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isPeriodic(class PyGeCurve2d {lvalue})'''
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
    def length (self, *args, **kwargs)-> float :
      '''length( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double length(class PyGeCurve2d {lvalue},double,double)

length( (Curve2d)arg1, (float)arg2, (float)arg3, (float)arg4) -> float :

    C++ signature :
        double length(class PyGeCurve2d {lvalue},double,double,double)'''
    ...
    def mirror (self, *args, **kwargs)-> None :
      '''mirror( (Entity2d)arg1, (Line2d)arg2) -> None :

    C++ signature :
        void mirror(class PyGeEntity2d {lvalue},class PyGeLine2d)'''
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
    def orthoBoundBlock (self, *args, **kwargs)-> PyGe.BoundBlock2d :
      '''orthoBoundBlock( (Curve2d)arg1) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d orthoBoundBlock(class PyGeCurve2d {lvalue})

orthoBoundBlock( (Curve2d)arg1, (Interval)arg2) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d orthoBoundBlock(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def paramAtLength (self, *args, **kwargs)-> float :
      '''paramAtLength( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve2d {lvalue},double,double)

paramAtLength( (Curve2d)arg1, (float)arg2, (float)arg3, (bool)arg4, (float)arg5) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve2d {lvalue},double,double,bool,double)'''
    ...
    def paramOf (self, *args, **kwargs)-> float :
      '''paramOf( (Curve2d)arg1, (Point2d)arg2) -> float :

    C++ signature :
        double paramOf(class PyGeCurve2d {lvalue},class AcGePoint2d)

paramOf( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double paramOf(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def reverseParam (self, *args, **kwargs)-> None :
      '''reverseParam( (Curve2d)arg1) -> None :

    C++ signature :
        void reverseParam(class PyGeCurve2d {lvalue})'''
    ...
    def rotateBy (self, *args, **kwargs)-> None :
      '''rotateBy( (Entity2d)arg1, (float)arg2) -> None :

    C++ signature :
        void rotateBy(class PyGeEntity2d {lvalue},double)

rotateBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> None :

    C++ signature :
        void rotateBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def scaleBy (self, *args, **kwargs)-> None :
      '''scaleBy( (Entity2d)arg1, (float)arg2) -> None :

    C++ signature :
        void scaleBy(class PyGeEntity2d {lvalue},double)

scaleBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> None :

    C++ signature :
        void scaleBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
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
    def setInterval (self, *args, **kwargs)-> None :
      '''setInterval( (Curve2d)arg1) -> None :

    C++ signature :
        void setInterval(class PyGeCurve2d {lvalue})

setInterval( (Curve2d)arg1, (Interval)arg2) -> bool :

    C++ signature :
        bool setInterval(class PyGeCurve2d {lvalue},class PyGeInterval)'''
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
    def transformBy (self, *args, **kwargs)-> None :
      '''transformBy( (Entity2d)arg1, (Matrix2d)arg2) -> None :

    C++ signature :
        void transformBy(class PyGeEntity2d {lvalue},class AcGeMatrix2d)'''
    ...
    def translateBy (self, *args, **kwargs)-> None :
      '''translateBy( (Entity2d)arg1, (Vector2d)arg2) -> None :

    C++ signature :
        void translateBy(class PyGeEntity2d {lvalue},class AcGeVector2d)'''
    ...
    def type (self, *args, **kwargs)-> PyGe.EntityId :
      '''type( (Entity2d)arg1) -> EntityId :

    C++ signature :
        enum AcGe::EntityId type(class PyGeEntity2d {lvalue})'''
    ...

class Polyline3d:
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
    def area (self, startParam : float, endParam : float, tol : float = default)-> float :
      '''                             '''
    ...
    def boundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock3d :
      '''                             '''
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
      '''                             '''
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
      '''                             '''
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
    def distanceTo (self, pt : float | PyGe.Point3d, tol : PyGe.Tol=None)-> float :
      '''                             '''
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
      '''                             '''
    ...
    def explode (self, val : PyGe.Interval = None)-> list :
      '''                             '''
    ...
    def fitPointAt (self, *args, **kwargs)-> PyGe.Point3d :
      '''fitPointAt( (Polyline3d)arg1, (int)arg2) -> Point3d :

    C++ signature :
        class AcGePoint3d fitPointAt(class PyGePolyline3d {lvalue},int)'''
    ...
    def getClosestPointTo (self, other : PyGe.Point3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''                             '''
    ...
    def getClosestPointsTo (self, other : PyGe.Curve3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def getEndPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def getInterval (self)-> PyGe.Interval :
      '''                             '''
    ...
    def getNormalPoint (self, pnt : PyGe.Point3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''                             '''
    ...
    def getProjClosestPointTo (self, pt : PyGe.Point3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''                             '''
    ...
    def getProjClosestPointsTo (self, pt : PyGe.Curve3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def getSamplePoints (self, *args, **kwargs)-> list :
      '''getSamplePoints( (Curve3d)arg1, (int)arg2) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve3d {lvalue},int)

getSamplePoints( (Curve3d)arg1, (float)arg2, (float)arg3, (float)arg4) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve3d {lvalue},double,double,double)'''
    ...
    def getSplitCurves (self, param : float)-> tuple :
      '''                             '''
    ...
    def getStartPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def getTrimmedOffset (self, dist : float, planeNormal : PyGe.Vector3d, extensionType : PyGe.OffsetCrvExtType, tol : PyGe.Tol=None)-> list :
      '''                             '''
    ...
    def hasEndPoint (self)-> bool :
      '''                             '''
    ...
    def hasFitData (self, *args, **kwargs)-> bool :
      '''hasFitData( (SplineEnt3d)arg1) -> bool :

    C++ signature :
        bool hasFitData(class PyGeSplineEnt3d {lvalue})'''
    ...
    def hasStartPoint (self)-> bool :
      '''                             '''
    ...
    def isClosed (self, tol : PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def isCoplanarWith (self, curve : PyGe.Curve3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isDegenerate (self, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isEqualTo (self, val : PyGe.Entity3d, tol : PyGe.Tol=None)-> bool :
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
    def isOn (self, pt : float | PyGe.Point3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isPeriodic (self)-> tuple :
      '''                             '''
    ...
    def isPlanar (self, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
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
    def length (self, frm : float, to : float, tol : float = default)-> float :
      '''                             '''
    ...
    def mirror (self, val : PyGe.Plane)-> None :
      '''                             '''
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
      '''                             '''
    ...
    def orthoProject (self, projectionPlane : PyGe.Plane, tol : PyGe.Tol=None)-> PyGe.Entity3d :
      '''                             '''
    ...
    def paramAtLength (self, datumParam : float, length : float, posParamDir : bool=True, tol : float = default)-> float :
      '''                             '''
    ...
    def paramOf (self, pt : PyGe.Point3d, tol : PyGe.Tol=None)-> float :
      '''                             '''
    ...
    def projClosestPointTo (self, pt : PyGe.Point3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.Point3d :
      '''                             '''
    ...
    def projClosestPointsTo (self, pt : PyGe.Curve3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def project (self, projectionPlane : PyGe.Plane, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.Entity3d :
      '''                             '''
    ...
    def reverseParam (self)-> None :
      '''                             '''
    ...
    def rotateBy (self, angle : double, vec : PyGe.Vector3d, pt : PyGe.Point3d = origin)-> None :
      '''                             '''
    ...
    def scaleBy (self, scaleFactor : double, pt : PyGe.Point3d = origin)-> None :
      '''                             '''
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
      '''                             '''
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
      '''                             '''
    ...
    def translateBy (self, vec : PyGe.Vector3d)-> None :
      '''                             '''
    ...
    def type (self)-> PyGe.EntityId :
      '''                             '''
    ...

class Position2d:
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
    def copy (self, *args, **kwargs)-> PyGe.Entity2d :
      '''copy( (Entity2d)arg1) -> Entity2d :

    C++ signature :
        class PyGeEntity2d copy(class PyGeEntity2d {lvalue})'''
    ...
    def copycast (self, *args, **kwargs)-> PyGe.Position2d :
      '''copycast( (Entity2d)arg1) -> Position2d :

    C++ signature :
        class PyGePosition2d copycast(class PyGeEntity2d)'''
    ...
    def isEqualTo (self, *args, **kwargs)-> bool :
      '''isEqualTo( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d)

isEqualTo( (Entity2d)arg1, (Entity2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d,class AcGeTol)'''
    ...
    def isKindOf (self, *args, **kwargs)-> bool :
      '''isKindOf( (Entity2d)arg1, (EntityId)arg2) -> bool :

    C++ signature :
        bool isKindOf(class PyGeEntity2d {lvalue},enum AcGe::EntityId)'''
    ...
    def isNull (self, *args, **kwargs)-> bool :
      '''isNull( (Entity2d)arg1) -> bool :

    C++ signature :
        bool isNull(class PyGeEntity2d {lvalue})'''
    ...
    def isOn (self, *args, **kwargs)-> bool :
      '''isOn( (Entity2d)arg1, (Point2d)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeEntity2d {lvalue},class AcGePoint2d)

isOn( (Entity2d)arg1, (Point2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeEntity2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def mirror (self, *args, **kwargs)-> None :
      '''mirror( (Entity2d)arg1, (Line2d)arg2) -> None :

    C++ signature :
        void mirror(class PyGeEntity2d {lvalue},class PyGeLine2d)'''
    ...
    def point2d (self, *args, **kwargs)-> PyGe.Point2d :
      '''point2d( (PointEnt2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d point2d(class PyGePointEnt2d {lvalue})'''
    ...
    def rotateBy (self, *args, **kwargs)-> None :
      '''rotateBy( (Entity2d)arg1, (float)arg2) -> None :

    C++ signature :
        void rotateBy(class PyGeEntity2d {lvalue},double)

rotateBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> None :

    C++ signature :
        void rotateBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def scaleBy (self, *args, **kwargs)-> None :
      '''scaleBy( (Entity2d)arg1, (float)arg2) -> None :

    C++ signature :
        void scaleBy(class PyGeEntity2d {lvalue},double)

scaleBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> None :

    C++ signature :
        void scaleBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def set (self, *args, **kwargs)-> None :
      '''set( (Position2d)arg1, (Point2d)arg2) -> None :

    C++ signature :
        void set(class PyGePosition2d {lvalue},class AcGePoint2d)

set( (Position2d)arg1, (float)arg2, (float)arg3) -> None :

    C++ signature :
        void set(class PyGePosition2d {lvalue},double,double)'''
    ...
    def transformBy (self, *args, **kwargs)-> None :
      '''transformBy( (Entity2d)arg1, (Matrix2d)arg2) -> None :

    C++ signature :
        void transformBy(class PyGeEntity2d {lvalue},class AcGeMatrix2d)'''
    ...
    def translateBy (self, *args, **kwargs)-> None :
      '''translateBy( (Entity2d)arg1, (Vector2d)arg2) -> None :

    C++ signature :
        void translateBy(class PyGeEntity2d {lvalue},class AcGeVector2d)'''
    ...
    def type (self, *args, **kwargs)-> PyGe.EntityId :
      '''type( (Entity2d)arg1) -> EntityId :

    C++ signature :
        enum AcGe::EntityId type(class PyGeEntity2d {lvalue})'''
    ...

class Position3d:
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
      '''                             '''
    ...
    def copycast (self, *args, **kwargs)-> PyGe.Position3d :
      '''copycast( (Entity3d)arg1) -> Position3d :

    C++ signature :
        class PyGePosition3d copycast(class PyGeEntity3d)'''
    ...
    def isEqualTo (self, val : PyGe.Entity3d, tol : PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def isKindOf (self, val : PyGe.EntityId)-> bool :
      '''                             '''
    ...
    def isNull (self)-> bool :
      '''                             '''
    ...
    def isOn (self, pt : PyGe.Point3d, tol : PyGe.Tol=default)-> bool :
      '''                             '''
    ...
    def mirror (self, val : PyGe.Plane)-> None :
      '''                             '''
    ...
    def point3d (self, *args, **kwargs)-> PyGe.Point3d :
      '''point3d( (PointEnt3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d point3d(class PyGePointEnt3d {lvalue})'''
    ...
    def rotateBy (self, angle : double, vec : PyGe.Vector3d, pt : PyGe.Point3d = origin)-> None :
      '''                             '''
    ...
    def scaleBy (self, scaleFactor : double, pt : PyGe.Point3d = origin)-> None :
      '''                             '''
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
      '''                             '''
    ...
    def translateBy (self, vec : PyGe.Vector3d)-> None :
      '''                             '''
    ...
    def type (self)-> PyGe.EntityId :
      '''                             '''
    ...

class Ray2d:
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
    def area (self, *args, **kwargs)-> float :
      '''area( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double area(class PyGeCurve2d {lvalue},double,double)

area( (Curve2d)arg1, (float)arg2, (float)arg3, (Tol)arg4) -> float :

    C++ signature :
        double area(class PyGeCurve2d {lvalue},double,double,class AcGeTol)'''
    ...
    def boundBlock (self, *args, **kwargs)-> PyGe.BoundBlock2d :
      '''boundBlock( (Curve2d)arg1) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d boundBlock(class PyGeCurve2d {lvalue})

boundBlock( (Curve2d)arg1, (Interval)arg2) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d boundBlock(class PyGeCurve2d {lvalue},class PyGeInterval)'''
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
    def closestPointTo (self, *args, **kwargs)-> PyGe.Point2d :
      '''closestPointTo( (Curve2d)arg1, (Point2d)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d closestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

closestPointTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> Point2d :

    C++ signature :
        class AcGePoint2d closestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

closestPointTo( (Curve2d)arg1, (Curve2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

closestPointTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def copy (self, *args, **kwargs)-> PyGe.Entity2d :
      '''copy( (Entity2d)arg1) -> Entity2d :

    C++ signature :
        class PyGeEntity2d copy(class PyGeEntity2d {lvalue})'''
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
    def distanceTo (self, *args, **kwargs)-> float :
      '''distanceTo( (Curve2d)arg1, (Point2d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

distanceTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

distanceTo( (Curve2d)arg1, (Curve2d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

distanceTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def evalPoint (self, *args, **kwargs)-> PyGe.Point2d :
      '''evalPoint( (Curve2d)arg1, (float)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d evalPoint(class PyGeCurve2d {lvalue},double)

evalPoint( (Curve2d)arg1, (float)arg2, (int)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple evalPoint(class PyGeCurve2d {lvalue},double,int)'''
    ...
    def explode (self, *args, **kwargs)-> list :
      '''explode( (Curve2d)arg1) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve2d {lvalue})

explode( (Curve2d)arg1, (Interval)arg2) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def getClosestPointTo (self, *args, **kwargs)-> PyGe.PointOnCurve2d :
      '''getClosestPointTo( (Curve2d)arg1, (Point2d)arg2) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getClosestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

getClosestPointTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getClosestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def getClosestPointsTo (self, *args, **kwargs)-> tuple :
      '''getClosestPointsTo( (Curve2d)arg1, (Curve2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

getClosestPointsTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def getEndPoint (self, *args, **kwargs)-> PyGe.Point2d :
      '''getEndPoint( (Curve2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d getEndPoint(class PyGeCurve2d {lvalue})'''
    ...
    def getInterval (self, *args, **kwargs)-> PyGe.Interval :
      '''getInterval( (Curve2d)arg1) -> Interval :

    C++ signature :
        class PyGeInterval getInterval(class PyGeCurve2d {lvalue})'''
    ...
    def getLine (self, *args, **kwargs)-> PyGe.Line2d :
      '''getLine( (LinearEnt2d)arg1) -> Line2d :

    C++ signature :
        class PyGeLine2d getLine(class PyGeLinearEnt2d {lvalue})'''
    ...
    def getNormalPoint (self, *args, **kwargs)-> PyGe.PointOnCurve2d :
      '''getNormalPoint( (Curve2d)arg1, (Point2d)arg2) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getNormalPoint(class PyGeCurve2d {lvalue},class AcGePoint2d)

getNormalPoint( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getNormalPoint(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def getPerpLine (self, *args, **kwargs)-> PyGe.Line2d :
      '''getPerpLine( (LinearEnt2d)arg1, (Point2d)arg2) -> Line2d :

    C++ signature :
        class PyGeLine2d getPerpLine(class PyGeLinearEnt2d {lvalue},class AcGePoint2d)'''
    ...
    def getSamplePoints (self, *args, **kwargs)-> list :
      '''getSamplePoints( (Curve2d)arg1, (int)arg2) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve2d {lvalue},int)

getSamplePoints( (Curve2d)arg1, (float)arg2, (float)arg3, (float)arg4) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve2d {lvalue},double,double,double)'''
    ...
    def getSplitCurves (self, *args, **kwargs)-> tuple :
      '''getSplitCurves( (Curve2d)arg1, (float)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getSplitCurves(class PyGeCurve2d {lvalue},double)'''
    ...
    def getStartPoint (self, *args, **kwargs)-> PyGe.Point2d :
      '''getStartPoint( (Curve2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d getStartPoint(class PyGeCurve2d {lvalue})'''
    ...
    def getTrimmedOffset (self, *args, **kwargs)-> list :
      '''getTrimmedOffset( (Curve2d)arg1, (float)arg2, (OffsetCrvExtType)arg3) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve2d {lvalue},double,enum AcGe::OffsetCrvExtType)

getTrimmedOffset( (Curve2d)arg1, (float)arg2, (OffsetCrvExtType)arg3, (Tol)arg4) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve2d {lvalue},double,enum AcGe::OffsetCrvExtType,class AcGeTol)'''
    ...
    def hasEndPoint (self, *args, **kwargs)-> bool :
      '''hasEndPoint( (Curve2d)arg1) -> bool :

    C++ signature :
        bool hasEndPoint(class PyGeCurve2d {lvalue})'''
    ...
    def hasStartPoint (self, *args, **kwargs)-> bool :
      '''hasStartPoint( (Curve2d)arg1) -> bool :

    C++ signature :
        bool hasStartPoint(class PyGeCurve2d {lvalue})'''
    ...
    def intersectWith (self, *args, **kwargs)-> tuple :
      '''intersectWith( (LinearEnt2d)arg1, (LinearEnt2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d)

intersectWith( (LinearEnt2d)arg1, (LinearEnt2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple intersectWith(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d,class AcGeTol)'''
    ...
    def isClosed (self, *args, **kwargs)-> bool :
      '''isClosed( (Curve2d)arg1) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve2d {lvalue})

isClosed( (Curve2d)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isColinearTo (self, *args, **kwargs)-> bool :
      '''isColinearTo( (LinearEnt2d)arg1, (LinearEnt2d)arg2) -> bool :

    C++ signature :
        bool isColinearTo(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d)

isColinearTo( (LinearEnt2d)arg1, (LinearEnt2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isColinearTo(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d,class AcGeTol)'''
    ...
    def isDegenerate (self, *args, **kwargs)-> tuple :
      '''isDegenerate( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve2d {lvalue})

isDegenerate( (Curve2d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isEqualTo (self, *args, **kwargs)-> bool :
      '''isEqualTo( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d)

isEqualTo( (Entity2d)arg1, (Entity2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d,class AcGeTol)'''
    ...
    def isKindOf (self, *args, **kwargs)-> bool :
      '''isKindOf( (Entity2d)arg1, (EntityId)arg2) -> bool :

    C++ signature :
        bool isKindOf(class PyGeEntity2d {lvalue},enum AcGe::EntityId)'''
    ...
    def isLinear (self, *args, **kwargs)-> tuple :
      '''isLinear( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve2d {lvalue})

isLinear( (Curve2d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isNull (self, *args, **kwargs)-> bool :
      '''isNull( (Entity2d)arg1) -> bool :

    C++ signature :
        bool isNull(class PyGeEntity2d {lvalue})'''
    ...
    def isOn (self, *args, **kwargs)-> tuple :
      '''isOn( (Curve2d)arg1, (Point2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isOn(class PyGeCurve2d {lvalue},class AcGePoint2d)

isOn( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple isOn(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

isOn( (Curve2d)arg1, (float)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isOn(class PyGeCurve2d {lvalue},double)

isOn( (Curve2d)arg1, (float)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple isOn(class PyGeCurve2d {lvalue},double,class AcGeTol)'''
    ...
    def isParallelTo (self, *args, **kwargs)-> bool :
      '''isParallelTo( (LinearEnt2d)arg1, (LinearEnt2d)arg2) -> bool :

    C++ signature :
        bool isParallelTo(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d)

isParallelTo( (LinearEnt2d)arg1, (LinearEnt2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isParallelTo(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d,class AcGeTol)'''
    ...
    def isPeriodic (self, *args, **kwargs)-> tuple :
      '''isPeriodic( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isPeriodic(class PyGeCurve2d {lvalue})'''
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
      '''length( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double length(class PyGeCurve2d {lvalue},double,double)

length( (Curve2d)arg1, (float)arg2, (float)arg3, (float)arg4) -> float :

    C++ signature :
        double length(class PyGeCurve2d {lvalue},double,double,double)'''
    ...
    def mirror (self, *args, **kwargs)-> None :
      '''mirror( (Entity2d)arg1, (Line2d)arg2) -> None :

    C++ signature :
        void mirror(class PyGeEntity2d {lvalue},class PyGeLine2d)'''
    ...
    def orthoBoundBlock (self, *args, **kwargs)-> PyGe.BoundBlock2d :
      '''orthoBoundBlock( (Curve2d)arg1) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d orthoBoundBlock(class PyGeCurve2d {lvalue})

orthoBoundBlock( (Curve2d)arg1, (Interval)arg2) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d orthoBoundBlock(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def overlap (self, *args, **kwargs)-> tuple :
      '''overlap( (LinearEnt2d)arg1, (LinearEnt2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple overlap(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d)

overlap( (LinearEnt2d)arg1, (LinearEnt2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple overlap(class PyGeLinearEnt2d {lvalue},class PyGeLinearEnt2d,class AcGeTol)'''
    ...
    def paramAtLength (self, *args, **kwargs)-> float :
      '''paramAtLength( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve2d {lvalue},double,double)

paramAtLength( (Curve2d)arg1, (float)arg2, (float)arg3, (bool)arg4, (float)arg5) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve2d {lvalue},double,double,bool,double)'''
    ...
    def paramOf (self, *args, **kwargs)-> float :
      '''paramOf( (Curve2d)arg1, (Point2d)arg2) -> float :

    C++ signature :
        double paramOf(class PyGeCurve2d {lvalue},class AcGePoint2d)

paramOf( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double paramOf(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def pointOnLine (self, *args, **kwargs)-> PyGe.Point2d :
      '''pointOnLine( (LinearEnt2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d pointOnLine(class PyGeLinearEnt2d {lvalue})'''
    ...
    def reverseParam (self, *args, **kwargs)-> None :
      '''reverseParam( (Curve2d)arg1) -> None :

    C++ signature :
        void reverseParam(class PyGeCurve2d {lvalue})'''
    ...
    def rotateBy (self, *args, **kwargs)-> None :
      '''rotateBy( (Entity2d)arg1, (float)arg2) -> None :

    C++ signature :
        void rotateBy(class PyGeEntity2d {lvalue},double)

rotateBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> None :

    C++ signature :
        void rotateBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def scaleBy (self, *args, **kwargs)-> None :
      '''scaleBy( (Entity2d)arg1, (float)arg2) -> None :

    C++ signature :
        void scaleBy(class PyGeEntity2d {lvalue},double)

scaleBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> None :

    C++ signature :
        void scaleBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def set (self, *args, **kwargs)-> None :
      '''set( (Ray2d)arg1, (Point2d)arg2, (Vector2d)arg3) -> None :

    C++ signature :
        void set(class PyGeRay2d {lvalue},class AcGePoint2d,class AcGeVector2d)

set( (Ray2d)arg1, (Point2d)arg2, (Point2d)arg3) -> None :

    C++ signature :
        void set(class PyGeRay2d {lvalue},class AcGePoint2d,class AcGePoint2d)'''
    ...
    def setInterval (self, *args, **kwargs)-> None :
      '''setInterval( (Curve2d)arg1) -> None :

    C++ signature :
        void setInterval(class PyGeCurve2d {lvalue})

setInterval( (Curve2d)arg1, (Interval)arg2) -> bool :

    C++ signature :
        bool setInterval(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def transformBy (self, *args, **kwargs)-> None :
      '''transformBy( (Entity2d)arg1, (Matrix2d)arg2) -> None :

    C++ signature :
        void transformBy(class PyGeEntity2d {lvalue},class AcGeMatrix2d)'''
    ...
    def translateBy (self, *args, **kwargs)-> None :
      '''translateBy( (Entity2d)arg1, (Vector2d)arg2) -> None :

    C++ signature :
        void translateBy(class PyGeEntity2d {lvalue},class AcGeVector2d)'''
    ...
    def type (self, *args, **kwargs)-> PyGe.EntityId :
      '''type( (Entity2d)arg1) -> EntityId :

    C++ signature :
        enum AcGe::EntityId type(class PyGeEntity2d {lvalue})'''
    ...

class Ray3d:
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

__init__( (object)arg1, (Point3d)arg2, (Point3d)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePoint3d,class AcGePoint3d)'''
    ...
    def area (self, startParam : float, endParam : float, tol : float = default)-> float :
      '''                             '''
    ...
    def boundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock3d :
      '''                             '''
    ...
    def cast (self, *args, **kwargs)-> PyGe.Ray3d :
      '''cast( (Entity3d)arg1) -> Ray3d :

    C++ signature :
        class PyGeRay3d cast(class PyGeEntity3d)'''
    ...
    def className (self, *args, **kwargs)-> str :
      '''className() -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > className()'''
    ...
    def closestPointTo (self, other : PyGe.Point3d | PyGe.Curve3d, tol : PyGe.Tol=None)-> PyGe.Point3d :
      '''                             '''
    ...
    def copy (self)-> PyGe.Entity3d :
      '''                             '''
    ...
    def copycast (self, *args, **kwargs)-> PyGe.Ray3d :
      '''copycast( (Entity3d)arg1) -> Ray3d :

    C++ signature :
        class PyGeRay3d copycast(class PyGeEntity3d)'''
    ...
    def direction (self, *args, **kwargs)-> PyGe.Vector3d :
      '''direction( (LinearEnt3d)arg1) -> Vector3d :

    C++ signature :
        class AcGeVector3d direction(class PyGeLinearEnt3d {lvalue})'''
    ...
    def distanceTo (self, pt : float | PyGe.Point3d, tol : PyGe.Tol=None)-> float :
      '''                             '''
    ...
    def evalPoint (self, param : float, numDeriv : int = 1)-> PyGe.Point3d :
      '''                             '''
    ...
    def explode (self, val : PyGe.Interval = None)-> list :
      '''                             '''
    ...
    def getClosestPointTo (self, other : PyGe.Point3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''                             '''
    ...
    def getClosestPointsTo (self, other : PyGe.Curve3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def getEndPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def getInterval (self)-> PyGe.Interval :
      '''                             '''
    ...
    def getLine (self, *args, **kwargs)-> PyGe.Line3d :
      '''getLine( (LinearEnt3d)arg1) -> Line3d :

    C++ signature :
        class PyGeLine3d getLine(class PyGeLinearEnt3d {lvalue})'''
    ...
    def getNormalPoint (self, pnt : PyGe.Point3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''                             '''
    ...
    def getPerpPlane (self, *args, **kwargs)-> PyGe.Plane :
      '''getPerpPlane( (LinearEnt3d)arg1, (Point3d)arg2) -> Plane :

    C++ signature :
        class PyGePlane getPerpPlane(class PyGeLinearEnt3d {lvalue},class AcGePoint3d)'''
    ...
    def getProjClosestPointTo (self, pt : PyGe.Point3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''                             '''
    ...
    def getProjClosestPointsTo (self, pt : PyGe.Curve3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def getSamplePoints (self, *args, **kwargs)-> list :
      '''getSamplePoints( (Curve3d)arg1, (int)arg2) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve3d {lvalue},int)

getSamplePoints( (Curve3d)arg1, (float)arg2, (float)arg3, (float)arg4) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve3d {lvalue},double,double,double)'''
    ...
    def getSplitCurves (self, param : float)-> tuple :
      '''                             '''
    ...
    def getStartPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def getTrimmedOffset (self, dist : float, planeNormal : PyGe.Vector3d, extensionType : PyGe.OffsetCrvExtType, tol : PyGe.Tol=None)-> list :
      '''                             '''
    ...
    def hasEndPoint (self)-> bool :
      '''                             '''
    ...
    def hasStartPoint (self)-> bool :
      '''                             '''
    ...
    def intersectWith (self, other : PyGe.LinearEnt3d | PyGe.PlanarEnt, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isClosed (self, tol : PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def isColinearTo (self, *args, **kwargs)-> bool :
      '''isColinearTo( (LinearEnt3d)arg1, (LinearEnt3d)arg2) -> bool :

    C++ signature :
        bool isColinearTo(class PyGeLinearEnt3d {lvalue},class PyGeLinearEnt3d)

isColinearTo( (LinearEnt3d)arg1, (LinearEnt3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isColinearTo(class PyGeLinearEnt3d {lvalue},class PyGeLinearEnt3d,class AcGeTol)'''
    ...
    def isCoplanarWith (self, curve : PyGe.Curve3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isDegenerate (self, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isEqualTo (self, val : PyGe.Entity3d, tol : PyGe.Tol=None)-> bool :
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
    def isOn (self, *args, **kwargs)-> tuple :
      '''isOn( (LinearEnt3d)arg1, (Point3d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isOn(class PyGeLinearEnt3d {lvalue},class AcGePoint3d)

isOn( (LinearEnt3d)arg1, (Point3d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple isOn(class PyGeLinearEnt3d {lvalue},class AcGePoint3d,class AcGeTol)

isOn( (LinearEnt3d)arg1, (float)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeLinearEnt3d {lvalue},double)

isOn( (LinearEnt3d)arg1, (float)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeLinearEnt3d {lvalue},double,class AcGeTol)

isOn( (LinearEnt3d)arg1, (Plane)arg2) -> bool :

    C++ signature :
        bool isOn(class PyGeLinearEnt3d {lvalue},class PyGePlane)

isOn( (LinearEnt3d)arg1, (Plane)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isOn(class PyGeLinearEnt3d {lvalue},class PyGePlane,class AcGeTol)'''
    ...
    def isParallelTo (self, *args, **kwargs)-> bool :
      '''isParallelTo( (LinearEnt3d)arg1, (LinearEnt3d)arg2) -> bool :

    C++ signature :
        bool isParallelTo(class PyGeLinearEnt3d {lvalue},class PyGeLinearEnt3d)

isParallelTo( (LinearEnt3d)arg1, (LinearEnt3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isParallelTo(class PyGeLinearEnt3d {lvalue},class PyGeLinearEnt3d,class AcGeTol)

isParallelTo( (LinearEnt3d)arg1, (PlanarEnt)arg2) -> bool :

    C++ signature :
        bool isParallelTo(class PyGeLinearEnt3d {lvalue},class PyGePlanarEnt)

isParallelTo( (LinearEnt3d)arg1, (PlanarEnt)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isParallelTo(class PyGeLinearEnt3d {lvalue},class PyGePlanarEnt,class AcGeTol)'''
    ...
    def isPeriodic (self)-> tuple :
      '''                             '''
    ...
    def isPerpendicularTo (self, *args, **kwargs)-> bool :
      '''isPerpendicularTo( (LinearEnt3d)arg1, (LinearEnt3d)arg2) -> bool :

    C++ signature :
        bool isPerpendicularTo(class PyGeLinearEnt3d {lvalue},class PyGeLinearEnt3d)

isPerpendicularTo( (LinearEnt3d)arg1, (LinearEnt3d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isPerpendicularTo(class PyGeLinearEnt3d {lvalue},class PyGeLinearEnt3d,class AcGeTol)

isPerpendicularTo( (LinearEnt3d)arg1, (PlanarEnt)arg2) -> bool :

    C++ signature :
        bool isPerpendicularTo(class PyGeLinearEnt3d {lvalue},class PyGePlanarEnt)

isPerpendicularTo( (LinearEnt3d)arg1, (PlanarEnt)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isPerpendicularTo(class PyGeLinearEnt3d {lvalue},class PyGePlanarEnt,class AcGeTol)'''
    ...
    def isPlanar (self, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def length (self, frm : float, to : float, tol : float = default)-> float :
      '''                             '''
    ...
    def mirror (self, val : PyGe.Plane)-> None :
      '''                             '''
    ...
    def orthoBoundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock3d :
      '''                             '''
    ...
    def orthoProject (self, projectionPlane : PyGe.Plane, tol : PyGe.Tol=None)-> PyGe.Entity3d :
      '''                             '''
    ...
    def overlap (self, other : PyGe.LinearEnt3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def paramAtLength (self, datumParam : float, length : float, posParamDir : bool=True, tol : float = default)-> float :
      '''                             '''
    ...
    def paramOf (self, pt : PyGe.Point3d, tol : PyGe.Tol=None)-> float :
      '''                             '''
    ...
    def pointOnLine (self, *args, **kwargs)-> PyGe.Point3d :
      '''pointOnLine( (LinearEnt3d)arg1) -> Point3d :

    C++ signature :
        class AcGePoint3d pointOnLine(class PyGeLinearEnt3d {lvalue})'''
    ...
    def projClosestPointTo (self, pt : PyGe.Point3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.Point3d :
      '''                             '''
    ...
    def projClosestPointsTo (self, pt : PyGe.Curve3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def projIntersectWith (self, other : PyGe.LinearEnt3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def project (self, projectionPlane : PyGe.Plane, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.Entity3d :
      '''                             '''
    ...
    def reverseParam (self)-> None :
      '''                             '''
    ...
    def rotateBy (self, angle : double, vec : PyGe.Vector3d, pt : PyGe.Point3d = origin)-> None :
      '''                             '''
    ...
    def scaleBy (self, scaleFactor : double, pt : PyGe.Point3d = origin)-> None :
      '''                             '''
    ...
    def set (self, *args, **kwargs)-> None :
      '''set( (Ray3d)arg1, (Point3d)arg2, (Vector3d)arg3) -> None :

    C++ signature :
        void set(class PyGeRay3d {lvalue},class AcGePoint3d,class AcGeVector3d)

set( (Ray3d)arg1, (Point3d)arg2, (Point3d)arg3) -> None :

    C++ signature :
        void set(class PyGeRay3d {lvalue},class AcGePoint3d,class AcGePoint3d)'''
    ...
    def setInterval (self, val : PyGe.Interval = None)-> None :
      '''                             '''
    ...
    def transformBy (self, val : PyGe.Matrix3d)-> None :
      '''                             '''
    ...
    def translateBy (self, vec : PyGe.Vector3d)-> None :
      '''                             '''
    ...
    def type (self)-> PyGe.EntityId :
      '''                             '''
    ...

class Scale2d:
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (float)arg2) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,double)

__init__( (object)arg1, (float)arg2, (float)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,double,double)'''
    ...
    def postMultBy (self, *args, **kwargs)-> PyGe.Scale2d :
      '''postMultBy( (Scale2d)arg1, (Scale2d)arg2) -> Scale2d :

    C++ signature :
        class AcGeScale2d {lvalue} postMultBy(class AcGeScale2d {lvalue},class AcGeScale2d)'''
    ...
    def preMultBy (self, *args, **kwargs)-> PyGe.Scale2d :
      '''preMultBy( (Scale2d)arg1, (Scale2d)arg2) -> Scale2d :

    C++ signature :
        class AcGeScale2d {lvalue} preMultBy(class AcGeScale2d {lvalue},class AcGeScale2d)'''
    ...
    def setToProduct (self, *args, **kwargs)-> PyGe.Scale2d :
      '''setToProduct( (Scale2d)arg1, (Scale2d)arg2, (float)arg3) -> Scale2d :

    C++ signature :
        class AcGeScale2d {lvalue} setToProduct(class AcGeScale2d {lvalue},class AcGeScale2d,double)

setToProduct( (Scale2d)arg1, (Scale2d)arg2, (Scale2d)arg3) -> Scale2d :

    C++ signature :
        class AcGeScale2d {lvalue} setToProduct(class AcGeScale2d {lvalue},class AcGeScale2d,class AcGeScale2d)'''
    ...
    def sx (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def sy (self, *args, **kwargs)-> None :
      '''None'''
    ...
    def toString (self, *args, **kwargs)-> str :
      '''toString( (Scale2d)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > toString(class AcGeScale2d)'''
    ...

class Scale3d:
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (float)arg2) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,double)

__init__( (object)arg1, (float)arg2, (float)arg3, (float)arg4) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,double,double,double)'''
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

class Sphere:
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
      '''                             '''
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
      '''                             '''
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
      '''                             '''
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
    def rotateBy (self, angle : double, vec : PyGe.Vector3d, pt : PyGe.Point3d = origin)-> None :
      '''                             '''
    ...
    def scaleBy (self, scaleFactor : double, pt : PyGe.Point3d = origin)-> None :
      '''                             '''
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
      '''                             '''
    ...
    def translateBy (self, vec : PyGe.Vector3d)-> None :
      '''                             '''
    ...
    def type (self)-> PyGe.EntityId :
      '''                             '''
    ...

class SplineEnt2d:
    def __init__ (self, *args, **kwargs)-> None :
      '''Raises an exception
This class cannot be instantiated from Python'''
    ...
    def area (self, *args, **kwargs)-> float :
      '''area( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double area(class PyGeCurve2d {lvalue},double,double)

area( (Curve2d)arg1, (float)arg2, (float)arg3, (Tol)arg4) -> float :

    C++ signature :
        double area(class PyGeCurve2d {lvalue},double,double,class AcGeTol)'''
    ...
    def boundBlock (self, *args, **kwargs)-> PyGe.BoundBlock2d :
      '''boundBlock( (Curve2d)arg1) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d boundBlock(class PyGeCurve2d {lvalue})

boundBlock( (Curve2d)arg1, (Interval)arg2) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d boundBlock(class PyGeCurve2d {lvalue},class PyGeInterval)'''
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
    def closestPointTo (self, *args, **kwargs)-> PyGe.Point2d :
      '''closestPointTo( (Curve2d)arg1, (Point2d)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d closestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

closestPointTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> Point2d :

    C++ signature :
        class AcGePoint2d closestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

closestPointTo( (Curve2d)arg1, (Curve2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

closestPointTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple closestPointTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
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
    def copy (self, *args, **kwargs)-> PyGe.Entity2d :
      '''copy( (Entity2d)arg1) -> Entity2d :

    C++ signature :
        class PyGeEntity2d copy(class PyGeEntity2d {lvalue})'''
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
    def distanceTo (self, *args, **kwargs)-> float :
      '''distanceTo( (Curve2d)arg1, (Point2d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

distanceTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

distanceTo( (Curve2d)arg1, (Curve2d)arg2) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

distanceTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double distanceTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
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
    def evalPoint (self, *args, **kwargs)-> PyGe.Point2d :
      '''evalPoint( (Curve2d)arg1, (float)arg2) -> Point2d :

    C++ signature :
        class AcGePoint2d evalPoint(class PyGeCurve2d {lvalue},double)

evalPoint( (Curve2d)arg1, (float)arg2, (int)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple evalPoint(class PyGeCurve2d {lvalue},double,int)'''
    ...
    def explode (self, *args, **kwargs)-> list :
      '''explode( (Curve2d)arg1) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve2d {lvalue})

explode( (Curve2d)arg1, (Interval)arg2) -> list :

    C++ signature :
        class boost::python::list explode(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def getClosestPointTo (self, *args, **kwargs)-> PyGe.PointOnCurve2d :
      '''getClosestPointTo( (Curve2d)arg1, (Point2d)arg2) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getClosestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d)

getClosestPointTo( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getClosestPointTo(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def getClosestPointsTo (self, *args, **kwargs)-> tuple :
      '''getClosestPointsTo( (Curve2d)arg1, (Curve2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve2d {lvalue},class PyGeCurve2d)

getClosestPointsTo( (Curve2d)arg1, (Curve2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple getClosestPointsTo(class PyGeCurve2d {lvalue},class PyGeCurve2d,class AcGeTol)'''
    ...
    def getEndPoint (self, *args, **kwargs)-> PyGe.Point2d :
      '''getEndPoint( (Curve2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d getEndPoint(class PyGeCurve2d {lvalue})'''
    ...
    def getInterval (self, *args, **kwargs)-> PyGe.Interval :
      '''getInterval( (Curve2d)arg1) -> Interval :

    C++ signature :
        class PyGeInterval getInterval(class PyGeCurve2d {lvalue})'''
    ...
    def getNormalPoint (self, *args, **kwargs)-> PyGe.PointOnCurve2d :
      '''getNormalPoint( (Curve2d)arg1, (Point2d)arg2) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getNormalPoint(class PyGeCurve2d {lvalue},class AcGePoint2d)

getNormalPoint( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> PointOnCurve2d :

    C++ signature :
        class PyGePointOnCurve2d getNormalPoint(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def getSamplePoints (self, *args, **kwargs)-> list :
      '''getSamplePoints( (Curve2d)arg1, (int)arg2) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve2d {lvalue},int)

getSamplePoints( (Curve2d)arg1, (float)arg2, (float)arg3, (float)arg4) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve2d {lvalue},double,double,double)'''
    ...
    def getSplitCurves (self, *args, **kwargs)-> tuple :
      '''getSplitCurves( (Curve2d)arg1, (float)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple getSplitCurves(class PyGeCurve2d {lvalue},double)'''
    ...
    def getStartPoint (self, *args, **kwargs)-> PyGe.Point2d :
      '''getStartPoint( (Curve2d)arg1) -> Point2d :

    C++ signature :
        class AcGePoint2d getStartPoint(class PyGeCurve2d {lvalue})'''
    ...
    def getTrimmedOffset (self, *args, **kwargs)-> list :
      '''getTrimmedOffset( (Curve2d)arg1, (float)arg2, (OffsetCrvExtType)arg3) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve2d {lvalue},double,enum AcGe::OffsetCrvExtType)

getTrimmedOffset( (Curve2d)arg1, (float)arg2, (OffsetCrvExtType)arg3, (Tol)arg4) -> list :

    C++ signature :
        class boost::python::list getTrimmedOffset(class PyGeCurve2d {lvalue},double,enum AcGe::OffsetCrvExtType,class AcGeTol)'''
    ...
    def hasEndPoint (self, *args, **kwargs)-> bool :
      '''hasEndPoint( (Curve2d)arg1) -> bool :

    C++ signature :
        bool hasEndPoint(class PyGeCurve2d {lvalue})'''
    ...
    def hasFitData (self, *args, **kwargs)-> bool :
      '''hasFitData( (SplineEnt2d)arg1) -> bool :

    C++ signature :
        bool hasFitData(class PyGeSplineEnt2d {lvalue})'''
    ...
    def hasStartPoint (self, *args, **kwargs)-> bool :
      '''hasStartPoint( (Curve2d)arg1) -> bool :

    C++ signature :
        bool hasStartPoint(class PyGeCurve2d {lvalue})'''
    ...
    def isClosed (self, *args, **kwargs)-> bool :
      '''isClosed( (Curve2d)arg1) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve2d {lvalue})

isClosed( (Curve2d)arg1, (Tol)arg2) -> bool :

    C++ signature :
        bool isClosed(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isDegenerate (self, *args, **kwargs)-> tuple :
      '''isDegenerate( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve2d {lvalue})

isDegenerate( (Curve2d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isDegenerate(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isEqualTo (self, *args, **kwargs)-> bool :
      '''isEqualTo( (Entity2d)arg1, (Entity2d)arg2) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d)

isEqualTo( (Entity2d)arg1, (Entity2d)arg2, (Tol)arg3) -> bool :

    C++ signature :
        bool isEqualTo(class PyGeEntity2d {lvalue},class PyGeEntity2d,class AcGeTol)'''
    ...
    def isKindOf (self, *args, **kwargs)-> bool :
      '''isKindOf( (Entity2d)arg1, (EntityId)arg2) -> bool :

    C++ signature :
        bool isKindOf(class PyGeEntity2d {lvalue},enum AcGe::EntityId)'''
    ...
    def isLinear (self, *args, **kwargs)-> tuple :
      '''isLinear( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve2d {lvalue})

isLinear( (Curve2d)arg1, (Tol)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isLinear(class PyGeCurve2d {lvalue},class AcGeTol)'''
    ...
    def isNull (self, *args, **kwargs)-> bool :
      '''isNull( (Entity2d)arg1) -> bool :

    C++ signature :
        bool isNull(class PyGeEntity2d {lvalue})'''
    ...
    def isOn (self, *args, **kwargs)-> tuple :
      '''isOn( (Curve2d)arg1, (Point2d)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isOn(class PyGeCurve2d {lvalue},class AcGePoint2d)

isOn( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple isOn(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)

isOn( (Curve2d)arg1, (float)arg2) -> tuple :

    C++ signature :
        class boost::python::tuple isOn(class PyGeCurve2d {lvalue},double)

isOn( (Curve2d)arg1, (float)arg2, (Tol)arg3) -> tuple :

    C++ signature :
        class boost::python::tuple isOn(class PyGeCurve2d {lvalue},double,class AcGeTol)'''
    ...
    def isPeriodic (self, *args, **kwargs)-> tuple :
      '''isPeriodic( (Curve2d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple isPeriodic(class PyGeCurve2d {lvalue})'''
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
    def length (self, *args, **kwargs)-> float :
      '''length( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double length(class PyGeCurve2d {lvalue},double,double)

length( (Curve2d)arg1, (float)arg2, (float)arg3, (float)arg4) -> float :

    C++ signature :
        double length(class PyGeCurve2d {lvalue},double,double,double)'''
    ...
    def mirror (self, *args, **kwargs)-> None :
      '''mirror( (Entity2d)arg1, (Line2d)arg2) -> None :

    C++ signature :
        void mirror(class PyGeEntity2d {lvalue},class PyGeLine2d)'''
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
    def orthoBoundBlock (self, *args, **kwargs)-> PyGe.BoundBlock2d :
      '''orthoBoundBlock( (Curve2d)arg1) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d orthoBoundBlock(class PyGeCurve2d {lvalue})

orthoBoundBlock( (Curve2d)arg1, (Interval)arg2) -> BoundBlock2d :

    C++ signature :
        class PyGeBoundBlock2d orthoBoundBlock(class PyGeCurve2d {lvalue},class PyGeInterval)'''
    ...
    def paramAtLength (self, *args, **kwargs)-> float :
      '''paramAtLength( (Curve2d)arg1, (float)arg2, (float)arg3) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve2d {lvalue},double,double)

paramAtLength( (Curve2d)arg1, (float)arg2, (float)arg3, (bool)arg4, (float)arg5) -> float :

    C++ signature :
        double paramAtLength(class PyGeCurve2d {lvalue},double,double,bool,double)'''
    ...
    def paramOf (self, *args, **kwargs)-> float :
      '''paramOf( (Curve2d)arg1, (Point2d)arg2) -> float :

    C++ signature :
        double paramOf(class PyGeCurve2d {lvalue},class AcGePoint2d)

paramOf( (Curve2d)arg1, (Point2d)arg2, (Tol)arg3) -> float :

    C++ signature :
        double paramOf(class PyGeCurve2d {lvalue},class AcGePoint2d,class AcGeTol)'''
    ...
    def reverseParam (self, *args, **kwargs)-> None :
      '''reverseParam( (Curve2d)arg1) -> None :

    C++ signature :
        void reverseParam(class PyGeCurve2d {lvalue})'''
    ...
    def rotateBy (self, *args, **kwargs)-> None :
      '''rotateBy( (Entity2d)arg1, (float)arg2) -> None :

    C++ signature :
        void rotateBy(class PyGeEntity2d {lvalue},double)

rotateBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> None :

    C++ signature :
        void rotateBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def scaleBy (self, *args, **kwargs)-> None :
      '''scaleBy( (Entity2d)arg1, (float)arg2) -> None :

    C++ signature :
        void scaleBy(class PyGeEntity2d {lvalue},double)

scaleBy( (Entity2d)arg1, (float)arg2, (Point2d)arg3) -> None :

    C++ signature :
        void scaleBy(class PyGeEntity2d {lvalue},double,class AcGePoint2d)'''
    ...
    def setControlPointAt (self, *args, **kwargs)-> None :
      '''setControlPointAt( (SplineEnt2d)arg1, (int)arg2, (Point2d)arg3) -> None :

    C++ signature :
        void setControlPointAt(class PyGeSplineEnt2d {lvalue},int,class AcGePoint2d)'''
    ...
    def setInterval (self, *args, **kwargs)-> None :
      '''setInterval( (Curve2d)arg1) -> None :

    C++ signature :
        void setInterval(class PyGeCurve2d {lvalue})

setInterval( (Curve2d)arg1, (Interval)arg2) -> bool :

    C++ signature :
        bool setInterval(class PyGeCurve2d {lvalue},class PyGeInterval)'''
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
    def transformBy (self, *args, **kwargs)-> None :
      '''transformBy( (Entity2d)arg1, (Matrix2d)arg2) -> None :

    C++ signature :
        void transformBy(class PyGeEntity2d {lvalue},class AcGeMatrix2d)'''
    ...
    def translateBy (self, *args, **kwargs)-> None :
      '''translateBy( (Entity2d)arg1, (Vector2d)arg2) -> None :

    C++ signature :
        void translateBy(class PyGeEntity2d {lvalue},class AcGeVector2d)'''
    ...
    def type (self, *args, **kwargs)-> PyGe.EntityId :
      '''type( (Entity2d)arg1) -> EntityId :

    C++ signature :
        enum AcGe::EntityId type(class PyGeEntity2d {lvalue})'''
    ...

class SplineEnt3d:
    def __init__ (self, *args, **kwargs)-> None :
      '''Raises an exception
This class cannot be instantiated from Python'''
    ...
    def area (self, startParam : float, endParam : float, tol : float = default)-> float :
      '''                             '''
    ...
    def boundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock3d :
      '''                             '''
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
      '''                             '''
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
      '''                             '''
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
    def distanceTo (self, pt : float | PyGe.Point3d, tol : PyGe.Tol=None)-> float :
      '''                             '''
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
      '''                             '''
    ...
    def explode (self, val : PyGe.Interval = None)-> list :
      '''                             '''
    ...
    def getClosestPointTo (self, other : PyGe.Point3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''                             '''
    ...
    def getClosestPointsTo (self, other : PyGe.Curve3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def getEndPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def getInterval (self)-> PyGe.Interval :
      '''                             '''
    ...
    def getNormalPoint (self, pnt : PyGe.Point3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''                             '''
    ...
    def getProjClosestPointTo (self, pt : PyGe.Point3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
      '''                             '''
    ...
    def getProjClosestPointsTo (self, pt : PyGe.Curve3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def getSamplePoints (self, *args, **kwargs)-> list :
      '''getSamplePoints( (Curve3d)arg1, (int)arg2) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve3d {lvalue},int)

getSamplePoints( (Curve3d)arg1, (float)arg2, (float)arg3, (float)arg4) -> list :

    C++ signature :
        class boost::python::list getSamplePoints(class PyGeCurve3d {lvalue},double,double,double)'''
    ...
    def getSplitCurves (self, param : float)-> tuple :
      '''                             '''
    ...
    def getStartPoint (self)-> PyGe.Point3d :
      '''                             '''
    ...
    def getTrimmedOffset (self, dist : float, planeNormal : PyGe.Vector3d, extensionType : PyGe.OffsetCrvExtType, tol : PyGe.Tol=None)-> list :
      '''                             '''
    ...
    def hasEndPoint (self)-> bool :
      '''                             '''
    ...
    def hasFitData (self, *args, **kwargs)-> bool :
      '''hasFitData( (SplineEnt3d)arg1) -> bool :

    C++ signature :
        bool hasFitData(class PyGeSplineEnt3d {lvalue})'''
    ...
    def hasStartPoint (self)-> bool :
      '''                             '''
    ...
    def isClosed (self, tol : PyGe.Tol=None)-> bool :
      '''                             '''
    ...
    def isCoplanarWith (self, curve : PyGe.Curve3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isDegenerate (self, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isEqualTo (self, val : PyGe.Entity3d, tol : PyGe.Tol=None)-> bool :
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
    def isOn (self, pt : float | PyGe.Point3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def isPeriodic (self)-> tuple :
      '''                             '''
    ...
    def isPlanar (self, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
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
    def length (self, frm : float, to : float, tol : float = default)-> float :
      '''                             '''
    ...
    def mirror (self, val : PyGe.Plane)-> None :
      '''                             '''
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
      '''                             '''
    ...
    def orthoProject (self, projectionPlane : PyGe.Plane, tol : PyGe.Tol=None)-> PyGe.Entity3d :
      '''                             '''
    ...
    def paramAtLength (self, datumParam : float, length : float, posParamDir : bool=True, tol : float = default)-> float :
      '''                             '''
    ...
    def paramOf (self, pt : PyGe.Point3d, tol : PyGe.Tol=None)-> float :
      '''                             '''
    ...
    def projClosestPointTo (self, pt : PyGe.Point3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.Point3d :
      '''                             '''
    ...
    def projClosestPointsTo (self, pt : PyGe.Curve3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> tuple :
      '''                             '''
    ...
    def project (self, projectionPlane : PyGe.Plane, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.Entity3d :
      '''                             '''
    ...
    def reverseParam (self)-> None :
      '''                             '''
    ...
    def rotateBy (self, angle : double, vec : PyGe.Vector3d, pt : PyGe.Point3d = origin)-> None :
      '''                             '''
    ...
    def scaleBy (self, scaleFactor : double, pt : PyGe.Point3d = origin)-> None :
      '''                             '''
    ...
    def setControlPointAt (self, *args, **kwargs)-> None :
      '''setControlPointAt( (SplineEnt3d)arg1, (int)arg2, (Point3d)arg3) -> None :

    C++ signature :
        void setControlPointAt(class PyGeSplineEnt3d {lvalue},int,class AcGePoint3d)'''
    ...
    def setInterval (self, val : PyGe.Interval = None)-> None :
      '''                             '''
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
      '''                             '''
    ...
    def translateBy (self, vec : PyGe.Vector3d)-> None :
      '''                             '''
    ...
    def type (self)-> PyGe.EntityId :
      '''                             '''
    ...

class SurfSurfInt:
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
      '''                             '''
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
      '''                             '''
    ...
    def isKindOf (self, val : PyGe.EntityId)-> bool :
      '''                             '''
    ...
    def isNull (self)-> bool :
      '''                             '''
    ...
    def isOn (self, pt : PyGe.Point3d, tol : PyGe.Tol=default)-> bool :
      '''                             '''
    ...
    def mirror (self, val : PyGe.Plane)-> None :
      '''                             '''
    ...
    def numResults (self, *args, **kwargs)-> int :
      '''numResults( (SurfSurfInt)arg1) -> int :

    C++ signature :
        int numResults(class PyGeSurfSurfInt {lvalue})'''
    ...
    def rotateBy (self, angle : double, vec : PyGe.Vector3d, pt : PyGe.Point3d = origin)-> None :
      '''                             '''
    ...
    def scaleBy (self, scaleFactor : double, pt : PyGe.Point3d = origin)-> None :
      '''                             '''
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
      '''                             '''
    ...
    def translateBy (self, vec : PyGe.Vector3d)-> None :
      '''                             '''
    ...
    def type (self)-> PyGe.EntityId :
      '''                             '''
    ...

class Surface:
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
      '''                             '''
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
      '''                             '''
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
    def reverseNormal (self, *args, **kwargs)-> None :
      '''reverseNormal( (Surface)arg1) -> None :

    C++ signature :
        void reverseNormal(class PyGeSurface {lvalue})'''
    ...
    def rotateBy (self, angle : double, vec : PyGe.Vector3d, pt : PyGe.Point3d = origin)-> None :
      '''                             '''
    ...
    def scaleBy (self, scaleFactor : double, pt : PyGe.Point3d = origin)-> None :
      '''                             '''
    ...
    def transformBy (self, val : PyGe.Matrix3d)-> None :
      '''                             '''
    ...
    def translateBy (self, vec : PyGe.Vector3d)-> None :
      '''                             '''
    ...
    def type (self)-> PyGe.EntityId :
      '''                             '''
    ...

class Tol:
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

class Torus:
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
      '''                             '''
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
      '''                             '''
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
    def reverseNormal (self, *args, **kwargs)-> None :
      '''reverseNormal( (Surface)arg1) -> None :

    C++ signature :
        void reverseNormal(class PyGeSurface {lvalue})'''
    ...
    def rotateBy (self, angle : double, vec : PyGe.Vector3d, pt : PyGe.Point3d = origin)-> None :
      '''                             '''
    ...
    def scaleBy (self, scaleFactor : double, pt : PyGe.Point3d = origin)-> None :
      '''                             '''
    ...
    def transformBy (self, val : PyGe.Matrix3d)-> None :
      '''                             '''
    ...
    def translateBy (self, vec : PyGe.Vector3d)-> None :
      '''                             '''
    ...
    def type (self)-> PyGe.EntityId :
      '''                             '''
    ...

class Vector2d:
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

__init__( (object)arg1, (object)arg2) -> object :

    C++ signature :
        void * __ptr64 __init__(class boost::python::api::object,class boost::python::api::object)'''
    ...
    def angle (self, *args, **kwargs)-> float :
      '''angle( (Vector2d)arg1) -> float :

    C++ signature :
        double angle(class AcGeVector2d {lvalue})'''
    ...
    def angleTo (self, *args, **kwargs)-> float :
      '''angleTo( (Vector2d)arg1, (Vector2d)arg2) -> float :

    C++ signature :
        double angleTo(class AcGeVector2d {lvalue},class AcGeVector2d)'''
    ...
    def dotProduct (self, *args, **kwargs)-> float :
      '''dotProduct( (Vector2d)arg1, (Vector2d)arg2) -> float :

    C++ signature :
        double dotProduct(class AcGeVector2d {lvalue},class AcGeVector2d)'''
    ...
    def isCodirectionalTo (self, *args, **kwargs)-> bool :
      '''isCodirectionalTo( (Vector2d)arg1, (Vector2d)arg2 [, (Tol)AcGeTol=<PyGe.Tol object at 0x000002587A47FD00>]) -> bool :

    C++ signature :
        bool isCodirectionalTo(class AcGeVector2d {lvalue},class AcGeVector2d [,class AcGeTol=<PyGe.Tol object at 0x000002587A47FD00>])'''
    ...
    def isEqualTo (self, *args, **kwargs)-> bool :
      '''isEqualTo( (Vector2d)arg1, (Vector2d)arg2 [, (Tol)AcGeTol=<PyGe.Tol object at 0x000002587A47FE20>]) -> bool :

    C++ signature :
        bool isEqualTo(class AcGeVector2d {lvalue},class AcGeVector2d [,class AcGeTol=<PyGe.Tol object at 0x000002587A47FE20>])'''
    ...
    def isParallelTo (self, *args, **kwargs)-> bool :
      '''isParallelTo( (Vector2d)arg1, (Vector2d)arg2 [, (Tol)AcGeTol=<PyGe.Tol object at 0x000002587A47FC70>]) -> bool :

    C++ signature :
        bool isParallelTo(class AcGeVector2d {lvalue},class AcGeVector2d [,class AcGeTol=<PyGe.Tol object at 0x000002587A47FC70>])'''
    ...
    def isPerpendicularTo (self, *args, **kwargs)-> bool :
      '''isPerpendicularTo( (Vector2d)arg1, (Vector2d)arg2 [, (Tol)AcGeTol=<PyGe.Tol object at 0x000002587A47FD90>]) -> bool :

    C++ signature :
        bool isPerpendicularTo(class AcGeVector2d {lvalue},class AcGeVector2d [,class AcGeTol=<PyGe.Tol object at 0x000002587A47FD90>])'''
    ...
    def isUnitLength (self, *args, **kwargs)-> bool :
      '''isUnitLength( (Vector2d)arg1 [, (Tol)AcGeTol=<PyGe.Tol object at 0x000002587A47FB50>]) -> bool :

    C++ signature :
        bool isUnitLength(class AcGeVector2d {lvalue} [,class AcGeTol=<PyGe.Tol object at 0x000002587A47FB50>])'''
    ...
    def isZeroLength (self, *args, **kwargs)-> bool :
      '''isZeroLength( (Vector2d)arg1 [, (Tol)AcGeTol=<PyGe.Tol object at 0x000002587A47FBE0>]) -> bool :

    C++ signature :
        bool isZeroLength(class AcGeVector2d {lvalue} [,class AcGeTol=<PyGe.Tol object at 0x000002587A47FBE0>])'''
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
    def length (self, *args, **kwargs)-> float :
      '''length( (Vector2d)arg1) -> float :

    C++ signature :
        double length(class AcGeVector2d {lvalue})'''
    ...
    def lengthSqrd (self, *args, **kwargs)-> float :
      '''lengthSqrd( (Vector2d)arg1) -> float :

    C++ signature :
        double lengthSqrd(class AcGeVector2d {lvalue})'''
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
      '''normal( (Vector2d)arg1 [, (Tol)AcGeTol=<PyGe.Tol object at 0x000002587A47F7F0>]) -> Vector2d :

    C++ signature :
        class AcGeVector2d normal(class AcGeVector2d {lvalue} [,class AcGeTol=<PyGe.Tol object at 0x000002587A47F7F0>])'''
    ...
    def normalize (self, *args, **kwargs)-> PyGe.Vector2d :
      '''normalize( (Vector2d)arg1 [, (Tol)AcGeTol=<PyGe.Tol object at 0x000002587A47F9A0>]) -> Vector2d :

    C++ signature :
        class AcGeVector2d {lvalue} normalize(class AcGeVector2d {lvalue} [,class AcGeTol=<PyGe.Tol object at 0x000002587A47F9A0>])'''
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

class Vector3d:
    def __init__ (self, *args, **kwargs)-> None :
      '''__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64)

__init__( (object)arg1, (float)arg2, (float)arg3, (float)arg4) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,double,double,double)

__init__( (object)arg1, (object)arg2, (Vector2d)arg3) -> None :

    C++ signature :
        void __init__(struct _object * __ptr64,class AcGePlanarEnt,class AcGeVector2d)

__init__( (object)arg1, (object)arg2) -> object :

    C++ signature :
        void * __ptr64 __init__(class boost::python::api::object,class boost::python::api::object)'''
    ...
    def angleOnPlane (self, *args, **kwargs)-> float :
      '''angleOnPlane( (Vector3d)arg1, (object)arg2) -> float :

    C++ signature :
        double angleOnPlane(class AcGeVector3d {lvalue},class AcGePlanarEnt)'''
    ...
    def angleTo (self, *args, **kwargs)-> float :
      '''angleTo( (Vector3d)arg1, (Vector3d)arg2) -> float :

    C++ signature :
        double angleTo(class AcGeVector3d {lvalue},class AcGeVector3d)

angleTo( (Vector3d)arg1, (Vector3d)arg2, (Vector3d)arg3) -> float :

    C++ signature :
        double angleTo(class AcGeVector3d {lvalue},class AcGeVector3d,class AcGeVector3d)'''
    ...
    def convert2d (self, *args, **kwargs)-> PyGe.Vector2d :
      '''convert2d( (Vector3d)arg1, (object)arg2) -> Vector2d :

    C++ signature :
        class AcGeVector2d convert2d(class AcGeVector3d {lvalue},class AcGePlanarEnt)'''
    ...
    def crossProduct (self, *args, **kwargs)-> PyGe.Vector3d :
      '''crossProduct( (Vector3d)arg1, (Vector3d)arg2) -> Vector3d :

    C++ signature :
        class AcGeVector3d crossProduct(class AcGeVector3d {lvalue},class AcGeVector3d)'''
    ...
    def dotProduct (self, *args, **kwargs)-> float :
      '''dotProduct( (Vector3d)arg1, (Vector3d)arg2) -> float :

    C++ signature :
        double dotProduct(class AcGeVector3d {lvalue},class AcGeVector3d)'''
    ...
    def isCodirectionalTo (self, *args, **kwargs)-> bool :
      '''isCodirectionalTo( (Vector3d)arg1, (Vector3d)arg2 [, (Tol)AcGeTol=<PyGe.Tol object at 0x000002587A7FC430>]) -> bool :

    C++ signature :
        bool isCodirectionalTo(class AcGeVector3d {lvalue},class AcGeVector3d [,class AcGeTol=<PyGe.Tol object at 0x000002587A7FC430>])'''
    ...
    def isEqualTo (self, *args, **kwargs)-> bool :
      '''isEqualTo( (Vector3d)arg1, (Vector3d)arg2 [, (Tol)AcGeTol=<PyGe.Tol object at 0x000002587A7FC550>]) -> bool :

    C++ signature :
        bool isEqualTo(class AcGeVector3d {lvalue},class AcGeVector3d [,class AcGeTol=<PyGe.Tol object at 0x000002587A7FC550>])'''
    ...
    def isParallelTo (self, *args, **kwargs)-> bool :
      '''isParallelTo( (Vector3d)arg1, (Vector3d)arg2 [, (Tol)AcGeTol=<PyGe.Tol object at 0x000002587A7FC3A0>]) -> bool :

    C++ signature :
        bool isParallelTo(class AcGeVector3d {lvalue},class AcGeVector3d [,class AcGeTol=<PyGe.Tol object at 0x000002587A7FC3A0>])'''
    ...
    def isPerpendicularTo (self, *args, **kwargs)-> bool :
      '''isPerpendicularTo( (Vector3d)arg1, (Vector3d)arg2 [, (Tol)AcGeTol=<PyGe.Tol object at 0x000002587A7FC4C0>]) -> bool :

    C++ signature :
        bool isPerpendicularTo(class AcGeVector3d {lvalue},class AcGeVector3d [,class AcGeTol=<PyGe.Tol object at 0x000002587A7FC4C0>])'''
    ...
    def isUnitLength (self, *args, **kwargs)-> bool :
      '''isUnitLength( (Vector3d)arg1 [, (Tol)AcGeTol=<PyGe.Tol object at 0x000002587A7FC280>]) -> bool :

    C++ signature :
        bool isUnitLength(class AcGeVector3d {lvalue} [,class AcGeTol=<PyGe.Tol object at 0x000002587A7FC280>])'''
    ...
    def isZeroLength (self, *args, **kwargs)-> bool :
      '''isZeroLength( (Vector3d)arg1 [, (Tol)AcGeTol=<PyGe.Tol object at 0x000002587A7FC310>]) -> bool :

    C++ signature :
        bool isZeroLength(class AcGeVector3d {lvalue} [,class AcGeTol=<PyGe.Tol object at 0x000002587A7FC310>])'''
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
    def largestElement (self, *args, **kwargs)-> int :
      '''largestElement( (Vector3d)arg1) -> int :

    C++ signature :
        unsigned int largestElement(class AcGeVector3d {lvalue})'''
    ...
    def length (self, *args, **kwargs)-> float :
      '''length( (Vector3d)arg1) -> float :

    C++ signature :
        double length(class AcGeVector3d {lvalue})'''
    ...
    def lengthSqrd (self, *args, **kwargs)-> float :
      '''lengthSqrd( (Vector3d)arg1) -> float :

    C++ signature :
        double lengthSqrd(class AcGeVector3d {lvalue})'''
    ...
    def mirror (self, *args, **kwargs)-> PyGe.Vector3d :
      '''mirror( (Vector3d)arg1, (Vector3d)arg2) -> Vector3d :

    C++ signature :
        class AcGeVector3d {lvalue} mirror(class AcGeVector3d {lvalue},class AcGeVector3d)'''
    ...
    def negate (self, *args, **kwargs)-> PyGe.Vector3d :
      '''negate( (Vector3d)arg1) -> Vector3d :

    C++ signature :
        class AcGeVector3d {lvalue} negate(class AcGeVector3d {lvalue})'''
    ...
    def normal (self, *args, **kwargs)-> PyGe.Vector3d :
      '''normal( (Vector3d)arg1 [, (Tol)AcGeTol=<PyGe.Tol object at 0x000002587A7FC1F0>]) -> Vector3d :

    C++ signature :
        class AcGeVector3d normal(class AcGeVector3d {lvalue} [,class AcGeTol=<PyGe.Tol object at 0x000002587A7FC1F0>])'''
    ...
    def normalize (self, *args, **kwargs)-> PyGe.Vector3d :
      '''normalize( (Vector3d)arg1 [, (Tol)AcGeTol=<PyGe.Tol object at 0x000002587A7FC160>]) -> Vector3d :

    C++ signature :
        class AcGeVector3d {lvalue} normalize(class AcGeVector3d {lvalue} [,class AcGeTol=<PyGe.Tol object at 0x000002587A7FC160>])

normalize( (Vector3d)arg1, (Tol)arg2, (AcGeError)arg3) -> Vector3d :

    C++ signature :
        class AcGeVector3d {lvalue} normalize(class AcGeVector3d {lvalue},class AcGeTol,enum AcGe::ErrorCondition {lvalue})'''
    ...
    def orthoProject (self, *args, **kwargs)-> PyGe.Vector3d :
      '''orthoProject( (Vector3d)arg1, (Vector3d)arg2) -> Vector3d :

    C++ signature :
        class AcGeVector3d orthoProject(class AcGeVector3d {lvalue},class AcGeVector3d)

orthoProject( (Vector3d)arg1, (Vector3d)arg2, (Tol)arg3, (AcGeError)arg4) -> Vector3d :

    C++ signature :
        class AcGeVector3d orthoProject(class AcGeVector3d {lvalue},class AcGeVector3d,class AcGeTol,enum AcGe::ErrorCondition {lvalue})'''
    ...
    def perpVector (self, *args, **kwargs)-> PyGe.Vector3d :
      '''perpVector( (Vector3d)arg1) -> Vector3d :

    C++ signature :
        class AcGeVector3d perpVector(class AcGeVector3d {lvalue})'''
    ...
    def project (self, *args, **kwargs)-> PyGe.Vector3d :
      '''project( (Vector3d)arg1, (Vector3d)arg2, (Vector3d)arg3) -> Vector3d :

    C++ signature :
        class AcGeVector3d project(class AcGeVector3d {lvalue},class AcGeVector3d,class AcGeVector3d)

project( (Vector3d)arg1, (Vector3d)arg2, (Vector3d)arg3, (Tol)arg4, (AcGeError)arg5) -> Vector3d :

    C++ signature :
        class AcGeVector3d project(class AcGeVector3d {lvalue},class AcGeVector3d,class AcGeVector3d,class AcGeTol,enum AcGe::ErrorCondition {lvalue})'''
    ...
    def rotateBy (self, *args, **kwargs)-> PyGe.Vector3d :
      '''rotateBy( (Vector3d)arg1, (float)arg2, (Vector3d)arg3) -> Vector3d :

    C++ signature :
        class AcGeVector3d {lvalue} rotateBy(class AcGeVector3d {lvalue},double,class AcGeVector3d)'''
    ...
    def rotateTo (self, *args, **kwargs)-> PyGe.Matrix3d :
      '''rotateTo( (Vector3d)arg1, (Vector3d)arg2, (Vector3d)arg3) -> Matrix3d :

    C++ signature :
        class AcGeMatrix3d rotateTo(class AcGeVector3d {lvalue},class AcGeVector3d,class AcGeVector3d)'''
    ...
    def set (self, *args, **kwargs)-> PyGe.Vector3d :
      '''set( (Vector3d)arg1, (float)arg2, (float)arg3, (float)arg4) -> Vector3d :

    C++ signature :
        class AcGeVector3d {lvalue} set(class AcGeVector3d {lvalue},double,double,double)

set( (Vector3d)arg1, (object)arg2, (Vector2d)arg3) -> Vector3d :

    C++ signature :
        class AcGeVector3d {lvalue} set(class AcGeVector3d {lvalue},class AcGePlanarEnt,class AcGeVector2d)'''
    ...
    def setToProduct (self, *args, **kwargs)-> PyGe.Vector3d :
      '''setToProduct( (Vector3d)arg1, (Vector3d)arg2, (float)arg3) -> Vector3d :

    C++ signature :
        class AcGeVector3d {lvalue} setToProduct(class AcGeVector3d {lvalue},class AcGeVector3d,double)

setToProduct( (Vector3d)arg1, (Matrix3d)arg2, (Vector3d)arg3) -> Vector3d :

    C++ signature :
        class AcGeVector3d {lvalue} setToProduct(class AcGeVector3d {lvalue},class AcGeMatrix3d,class AcGeVector3d)'''
    ...
    def setToSum (self, *args, **kwargs)-> PyGe.Vector3d :
      '''setToSum( (Vector3d)arg1, (Vector3d)arg2, (Vector3d)arg3) -> Vector3d :

    C++ signature :
        class AcGeVector3d {lvalue} setToSum(class AcGeVector3d {lvalue},class AcGeVector3d,class AcGeVector3d)'''
    ...
    def toList (self, *args, **kwargs)-> list :
      '''toList( (Vector3d)arg1) -> list :

    C++ signature :
        class boost::python::list toList(class AcGeVector3d)'''
    ...
    def toString (self, *args, **kwargs)-> str :
      '''toString( (Vector3d)arg1) -> str :

    C++ signature :
        class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > toString(class AcGeVector3d)'''
    ...
    def toTuple (self, *args, **kwargs)-> tuple :
      '''toTuple( (Vector3d)arg1) -> tuple :

    C++ signature :
        class boost::python::tuple toTuple(class AcGeVector3d)'''
    ...
    def transformBy (self, *args, **kwargs)-> PyGe.Vector3d :
      '''transformBy( (Vector3d)arg1, (Matrix3d)arg2) -> Vector3d :

    C++ signature :
        class AcGeVector3d {lvalue} transformBy(class AcGeVector3d {lvalue},class AcGeMatrix3d)'''
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
