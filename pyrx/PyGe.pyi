import PyRx
import PyGe
import PyGi
import PyGs
import PyDb
import PyAp
import PyEd
import PyPl
import PySm
import PyBr
from typing import overload
from typing import Any

class AcGeCSIConfig(object):
    def kXCoincident (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kXCoincidentUnbounded (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kXIn (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kXOut (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kXTanIn (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kXTanOut (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kXUnknown (self, *args, **kwargs)-> None :
        '''None'''
        ...

class AcGeError(object):
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

class AcGeSSIConfig(object):
    def kSSICoincident (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kSSIIn (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kSSIOut (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kSSIUnknown (self, *args, **kwargs)-> None :
        '''None'''
        ...

class AcGeSSIType(object):
    def kSSIAntiTangent (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kSSITangent (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kSSITransverse (self, *args, **kwargs)-> None :
        '''None'''
        ...

class AcGeXConfig(object):
    def kLeftLeft (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kLeftOverlap (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kLeftRight (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kNotDefined (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kOverlapEnd (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kOverlapLeft (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kOverlapOverlap (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kOverlapRight (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kOverlapStart (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kPointLeft (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kPointRight (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kRightLeft (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kRightOverlap (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kRightRight (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kUnknown (self, *args, **kwargs)-> None :
        '''None'''
        ...

class AutoTol(object):
    def __init__ (self)-> None :
        '''                             '''
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

class BoundedPlane(PlanarEnt):

    @overload
    def __init__ (self, /)-> None : ...
    @overload
    def __init__ (self, origin: PyGe.Point3d, uVec: PyGe.Vector3d, vVec: PyGe.Vector3d)-> None : ...
    @overload
    def __init__ (self, p1: PyGe.Point3d, origin: PyGe.Point3d, p2: PyGe.Point3d)-> None : ...
    def __init__ (self, *args, **kwargs)-> None :
        '''Overloads:
    - None: Any
    - origin: PyGe.Point3d, uVec: PyGe.Vector3d, vVec: PyGe.Vector3d
    - p1: PyGe.Point3d, origin: PyGe.Point3d, p2: PyGe.Point3d
    '''
        ...

    @staticmethod
    def cast (otherObject: PyGe.Entity3d)-> PyGe.BoundedPlane :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def copycast (otherObject: PyGe.Entity3d)-> PyGe.BoundedPlane :
        '''                             '''
        ...
    def intersectWith (self, val: PyGe.LinearEnt3d | PyGe.Plane | PyGe.BoundedPlane, tol: PyGe.Tol=None)-> tuple[bool,PyGe.LineSeg3d] :
        '''                             '''
        ...

    @overload
    def set (self, origin: PyGe.Point3d, uVec: PyGe.Vector3d, vVec: PyGe.Vector3d)-> None : ...
    @overload
    def set (self, p1: PyGe.Point3d, origin: PyGe.Point3d, p2: PyGe.Point3d)-> None : ...
    def set (self, *args, **kwargs)-> None :
        '''Overloads:
    - origin: PyGe.Point3d, uVec: PyGe.Vector3d, vVec: PyGe.Vector3d
    - p1: PyGe.Point3d, origin: PyGe.Point3d, p2: PyGe.Point3d
    '''
        ...

class CircArc2d(Curve2d):

    @overload
    def __init__ (self, /)-> None : ...
    @overload
    def __init__ (self, cent: PyGe.Point2d, radius: float)-> None : ...
    @overload
    def __init__ (self, cent: PyGe.Point2d, radius: float, startAngle: float, endAngle: float)-> None : ...
    @overload
    def __init__ (self, cent: PyGe.Point2d, radius: float, startAngle: float, endAngle: float, refVec: PyGe.Vector2d, isClockWise: bool)-> None : ...
    @overload
    def __init__ (self, startPoint: PyGe.Point2d, pnt: PyGe.Point2d, endPoint: PyGe.Point2d)-> None : ...
    @overload
    def __init__ (self, startPoint: PyGe.Point2d, endPoint: PyGe.Point2d, bulge: float, bulgeFlag: bool)-> None : ...
    def __init__ (self, *args, **kwargs)-> None :
        '''Overloads:
    - None: Any
    - cent: PyGe.Point2d, radius: float
    - cent: PyGe.Point2d, radius: float, startAngle: float, endAngle: float
    - cent: PyGe.Point2d, radius: float, startAngle: float, endAngle: float, refVec: PyGe.Vector2d, isClockWise: bool
    - startPoint: PyGe.Point2d, pnt: PyGe.Point2d, endPoint: PyGe.Point2d
    - startPoint: PyGe.Point2d, endPoint: PyGe.Point2d, bulge: float, bulgeFlag: bool
    '''
        ...

    @staticmethod
    def cast (otherObject: PyGe.Entity2d)-> PyGe.CircArc2d :
        '''                             '''
        ...
    def center (self)-> PyGe.Point2d :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def copycast (otherObject: PyGe.Entity2d)-> PyGe.CircArc2d :
        '''                             '''
        ...
    def endAng (self)-> float :
        '''                             '''
        ...
    def endPoint (self)-> PyGe.Point2d :
        '''                             '''
        ...
    def intersectWith (self, val: PyGe.CircArc2d | PyGe.LinearEnt2d, tol: PyGe.Tol=None)-> tuple[bool,int,PyGe.Point2d,PyGe.Point2d] :
        '''                             '''
        ...
    def isClockWise (self)-> bool :
        '''                             '''
        ...
    def isInside (self, pt: PyGe.Point2d, tol: PyGe.Tol=None)-> bool :
        '''                             '''
        ...
    def radius (self)-> float :
        '''                             '''
        ...
    def refVec (self)-> PyGe.Vector2d :
        '''                             '''
        ...

    @overload
    def set (self, cent: PyGe.Point2d, radius: float)-> None : ...
    @overload
    def set (self, cent: PyGe.Point2d, radius: float, startAngle: float, endAngle: float, refVec: PyGe.Vector2d, isClockWise: bool)-> None : ...
    @overload
    def set (self, startPoint: PyGe.Point2d, pnt: PyGe.Point2d, endPoint: PyGe.Point2d)-> None : ...
    @overload
    def set (self, startPoint: PyGe.Point2d, endPoint: PyGe.Point2d, bulge: float, bulgeFlag: bool)-> None : ...
    @overload
    def set (self, curve1: PyGe.Curve2d, curve2: PyGe.Curve2d, radius: float)-> None : ...
    @overload
    def set (self, curve1: PyGe.Curve2d, curve2: PyGe.Curve2d, curve3: PyGe.Curve2d)-> None : ...
    def set (self, *args, **kwargs)-> None :
        '''Overloads:
    - cent: PyGe.Point2d, radius: float
    - cent: PyGe.Point2d, radius: float, startAngle: float, endAngle: float, refVec: PyGe.Vector2d, isClockWise: bool
    - startPoint: PyGe.Point2d, pnt: PyGe.Point2d, endPoint: PyGe.Point2d
    - startPoint: PyGe.Point2d, endPoint: PyGe.Point2d, bulge: float, bulgeFlag: bool
    - curve1: PyGe.Curve2d, curve2: PyGe.Curve2d, radius: float
    - curve1: PyGe.Curve2d, curve2: PyGe.Curve2d, curve3: PyGe.Curve2d
    '''
        ...
    def setAngles (self, startAng: float, endAng: float)-> None :
        '''                             '''
        ...
    def setCenter (self, pt: PyGe.Point2d)-> None :
        '''                             '''
        ...
    def setRadius (self, val: float)-> None :
        '''                             '''
        ...
    def setRefVec (self)-> None :
        '''                             '''
        ...
    def setToComplement (self)-> None :
        '''                             '''
        ...
    def startAng (self)-> float :
        '''                             '''
        ...
    def startPoint (self)-> PyGe.Point2d :
        '''                             '''
        ...
    def tangent (self, pt: PyGe.Point2d, tol: PyGe.Tol=None)-> tuple[bool,PyGe.Line3d,PyGe.AcGeError] :
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
    def closestPointToPlane (self, plane: PyGe.PlanarEnt, tol: PyGe.Tol=None)-> tuple[PyGe.Point3d,PyGe.Point3d] :
        '''                             '''
        ...

    @staticmethod
    def copycast (otherObject: PyGe.Entity3d)-> PyGe.CircArc3d :
        '''                             '''
        ...
    def endAng (self)-> float :
        '''                             '''
        ...
    def endPoint (self)-> PyGe.Point3d :
        '''                             '''
        ...
    def getPlane (self)-> PyGe.Plane :
        '''                             '''
        ...
    def intersectWith (self, other: PyGe.CircArc3d|PyGe.LinearEnt3d|PyGe.PlanarEnt, tol: PyGe.Tol=None)-> tuple[bool,int,PyGe.Point3d,PyGe.Point3d] :
        '''                             '''
        ...
    def isInside (self, pt: PyGe.Point3d, tol: PyGe.Tol=None)-> bool :
        '''                             '''
        ...
    def normal (self)-> PyGe.Vector3d :
        '''                             '''
        ...
    def projIntersectWith (self, other: PyGe.LinearEnt3d, projDir: PyGe.Vector3d, tol: PyGe.Tol=None)-> tuple :
        '''                             '''
        ...
    def radius (self)-> float :
        '''                             '''
        ...
    def refVec (self)-> PyGe.Vector3d :
        '''                             '''
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
    def setRadius (self, val: float)-> None :
        '''                             '''
        ...
    def startAng (self)-> float :
        '''                             '''
        ...
    def startPoint (self)-> PyGe.Point3d :
        '''                             '''
        ...
    def tangent (self, pt: PyGe.Point3d, tol: PyGe.Tol=None)-> tuple[bool,PyGe.Line3d] :
        '''                             '''
        ...

class ClipBoundary2d(Entity2d):

    @overload
    def __init__ (self, /)-> None : ...
    @overload
    def __init__ (self, cornerA: PyGe.Point2d, cornerB: PyGe.Point2d)-> None : ...
    @overload
    def __init__ (self, clipBoundary: list[PyGe.Point2d])-> None : ...
    def __init__ (self, *args, **kwargs)-> None :
        '''Overloads:
    - None: Any
    - cornerA: PyGe.Point2d, cornerB: PyGe.Point2d
    - clipBoundary: list[PyGe.Point2d]
    '''
        ...

    @staticmethod
    def cast (otherObject: PyGe.Entity2d)-> PyGe.ClipBoundary2d :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def copycast (otherObject: PyGe.Entity2d)-> PyGe.ClipBoundary2d :
        '''                             '''
        ...

class CompositeCurve2d(Curve2d):

    @overload
    def __init__ (self, /)-> None : ...
    @overload
    def __init__ (self, curveList: list[PyGe.Curve2d])-> None : ...
    @overload
    def __init__ (self, curveList: list[PyGe.Curve2d], isOwnerOfCurves: list[int])-> None : ...
    def __init__ (self, *args, **kwargs)-> None :
        '''Overloads:
    - None: Any
    - curveList: list[PyGe.Curve2d]
    - curveList: list[PyGe.Curve2d], isOwnerOfCurves: list[int]
    '''
        ...

    @staticmethod
    def cast (otherObject: PyGe.Entity2d)-> PyGe.CompositeCurve2d :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def copycast (otherObject: PyGe.Entity2d)-> PyGe.CompositeCurve2d :
        '''                             '''
        ...
    def getCurveList (self)-> list[PyGe.Curve3d] :
        '''                             '''
        ...
    def globalToLocalParam (self, param: float)-> tuple[float,int] :
        '''                             '''
        ...
    def localToGlobalParam (self, param: float, segNum: int)-> float :
        '''                             '''
        ...

    @overload
    def setCurveList (self, curveList: list[PyGe.Curve2d])-> None : ...
    @overload
    def setCurveList (self, curveList: list[PyGe.Curve2d], isOwnerOfCurves: list[int])-> None : ...
    def setCurveList (self, *args, **kwargs)-> None :
        '''Overloads:
    - curveList: list[PyGe.Curve2d]
    - curveList: list[PyGe.Curve2d], isOwnerOfCurves: list[int]
    '''
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

    @staticmethod
    def cast (otherObject: PyGe.Entity3d)-> PyGe.CompositeCurve3d :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def copycast (otherObject: PyGe.Entity3d)-> PyGe.CompositeCurve3d :
        '''                             '''
        ...
    def getCurveList (self)-> list[PyGe.Curve3d] :
        '''                             '''
        ...
    def globalToLocalParam (self, param: float)-> tuple[float,int] :
        '''                             '''
        ...
    def localToGlobalParam (self, param: float, segNum: int)-> float :
        '''                             '''
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

class Cone(Surface):

    @overload
    def __init__ (self, /)-> None : ...
    @overload
    def __init__ (self, cosineAngle: float, sineAngle: float, baseOrigin: PyGe.Point3d, baseRadius: float, axisOfSymmetry: PyGe.Vector3d)-> None : ...
    @overload
    def __init__ (self, cosineAngle: float, sineAngle: float, baseOrigin: PyGe.Point3d, baseRadius: float, axisOfSymmetry: PyGe.Vector3d, refAxis: PyGe.Vector3d, height: PyGe.Interval, startAngle: float, endAngle: float)-> None : ...
    def __init__ (self, *args, **kwargs)-> None :
        '''Overloads:
    - None: Any
    - cosineAngle: float, sineAngle: float, baseOrigin: PyGe.Point3d, baseRadius: float, axisOfSymmetry: PyGe.Vector3d
    - cosineAngle: float, sineAngle: float, baseOrigin: PyGe.Point3d, baseRadius: float, axisOfSymmetry: PyGe.Vector3d, refAxis: PyGe.Vector3d, height: PyGe.Interval, startAngle: float, endAngle: float
    '''
        ...
    def apex (self)-> PyGe.Point3d :
        '''                             '''
        ...
    def axisOfSymmetry (self)-> PyGe.Vector3d :
        '''                             '''
        ...
    def baseCenter (self)-> PyGe.Point3d :
        '''                             '''
        ...
    def baseRadius (self)-> float :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PyGe.Entity3d)-> PyGe.Cone :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def copycast (otherObject: PyGe.Entity3d)-> PyGe.Cone :
        '''                             '''
        ...
    def getAngles (self)-> tuple[float,float] :
        '''                             '''
        ...
    def getHalfAngle (self)-> tuple[float,float] :
        '''                             '''
        ...
    def getHeight (self)-> PyGe.Interval :
        '''                             '''
        ...
    def halfAngle (self)-> float :
        '''                             '''
        ...
    def heightAt (self, val: float)-> float :
        '''                             '''
        ...
    def intersectWith (self, val: PyGe.LinearEnt3d, tol: PyGe.Tol=None)-> tuple[bool,int,PyGe.Point3d,PyGe.Point3d] :
        '''                             '''
        ...
    def isClosed (self, tol: PyGe.Tol=None)-> bool :
        '''                             '''
        ...
    def isOuterNormal (self)-> bool :
        '''                             '''
        ...
    def refAxis (self)-> PyGe.Vector3d :
        '''                             '''
        ...

    @overload
    def set (self, cosineAngle: float, sineAngle: float, baseOrigin: PyGe.Point3d, baseRadius: float, axisOfSymmetry: PyGe.Vector3d)-> None : ...
    @overload
    def set (self, cosineAngle: float, sineAngle: float, baseOrigin: PyGe.Point3d, baseRadius: float, axisOfSymmetry: PyGe.Vector3d, refAxis: PyGe.Vector3d, height: PyGe.Interval, startAngle: float, endAngle: float)-> None : ...
    def set (self, *args, **kwargs)-> None :
        '''Overloads:
    - cosineAngle: float, sineAngle: float, baseOrigin: PyGe.Point3d, baseRadius: float, axisOfSymmetry: PyGe.Vector3d
    - cosineAngle: float, sineAngle: float, baseOrigin: PyGe.Point3d, baseRadius: float, axisOfSymmetry: PyGe.Vector3d, refAxis: PyGe.Vector3d, height: PyGe.Interval, startAngle: float, endAngle: float
    '''
        ...
    def setAngles (self, startAngle: float, endAngle: float)-> None :
        '''                             '''
        ...
    def setBaseRadius (self, val: float)-> None :
        '''                             '''
        ...
    def setHeight (self, val: PyGe.Interval)-> None :
        '''                             '''
        ...

class CubicSplineCurve2d(SplineEnt2d):

    @overload
    def __init__ (self, /)-> None : ...
    @overload
    def __init__ (self, curve: PyGe.Curve2d, epsilon: float)-> None : ...
    @overload
    def __init__ (self, fitPnts: list[PyGe.Point2d], tol: PyGe.Tol)-> None : ...
    @overload
    def __init__ (self, fitPnts: list[PyGe.Point2d], startDeriv: PyGe.Vector2d, endDeriv: PyGe.Vector2d,tol: PyGe.Tol)-> None : ...
    @overload
    def __init__ (self, knots: PyGe.KnotVector, fitPnts: list[PyGe.Point2d], firstDerivs: list[PyGe.Point2d], isPeriodic: bool)-> None : ...
    def __init__ (self, *args, **kwargs)-> None :
        '''Overloads:
    - None: Any
    - curve: PyGe.Curve2d, epsilon: float
    - fitPnts: list[PyGe.Point2d], tol: PyGe.Tol
    - fitPnts: list[PyGe.Point2d], startDeriv: PyGe.Vector2d, endDeriv: PyGe.Vector2d,tol: PyGe.Tol
    - knots: PyGe.KnotVector, fitPnts: list[PyGe.Point2d], firstDerivs: list[PyGe.Point2d], isPeriodic: bool
    '''
        ...

    @staticmethod
    def cast (otherObject: PyGe.Entity2d)-> PyGe.CubicSplineCurve2d :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def copycast (otherObject: PyGe.Entity2d)-> PyGe.CubicSplineCurve2d :
        '''                             '''
        ...
    def firstDerivAt (self, val: int)-> PyGe.Vector2d :
        '''                             '''
        ...
    def fitPointAt (self, val: int)-> PyGe.Point2d :
        '''                             '''
        ...
    def numFitPoints (self)-> int :
        '''                             '''
        ...
    def setFirstDerivAt (self, val: int, pt: PyGe.Vector2d)-> None :
        '''                             '''
        ...
    def setFitPointAt (self, val: int, pt: PyGe.Point2d)-> None :
        '''                             '''
        ...

class CubicSplineCurve3d(SplineEnt3d):

    @overload
    def __init__ (self, /)-> None : ...
    @overload
    def __init__ (self, curve: PyGe.Curve3d, epsilon: float)-> None : ...
    @overload
    def __init__ (self, fitPnts: list[PyGe.Point3d], tol: PyGe.Tol)-> None : ...
    @overload
    def __init__ (self, fitPnts: list[PyGe.Point3d], startDeriv: PyGe.Vector3d, endDeriv: PyGe.Vector3d, tol: PyGe.Tol)-> None : ...
    @overload
    def __init__ (self, knots: PyGe.KnotVector, fitPnts: list[PyGe.Point3d], firstDerivs: list[PyGe.Vector3d], isPeriodic: bool)-> None : ...
    def __init__ (self, *args, **kwargs)-> None :
        '''Overloads:
    - None: Any
    - curve: PyGe.Curve3d, epsilon: float
    - fitPnts: list[PyGe.Point3d], tol: PyGe.Tol
    - fitPnts: list[PyGe.Point3d], startDeriv: PyGe.Vector3d, endDeriv: PyGe.Vector3d, tol: PyGe.Tol
    - knots: PyGe.KnotVector, fitPnts: list[PyGe.Point3d], firstDerivs: list[PyGe.Vector3d], isPeriodic: bool
    '''
        ...

    @staticmethod
    def cast (otherObject: PyGe.Entity3d)-> PyGe.CubicSplineCurve3d :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def copycast (otherObject: PyGe.Entity3d)-> PyGe.CubicSplineCurve3d :
        '''                             '''
        ...
    def firstDerivAt (self, idx: int)-> PyGe.Vector3d :
        '''                             '''
        ...
    def fitPointAt (self, idx: int)-> PyGe.Point3d :
        '''                             '''
        ...
    def numFitPoints (self)-> int :
        '''                             '''
        ...
    def setFirstDerivAt (self, idx: int, vec: PyGe.Vector3d)-> None :
        '''                             '''
        ...
    def setFitPointAt (self, idx: int, pt: PyGe.Point3d)-> None :
        '''                             '''
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
    def explode (self, val : PyGe.Interval = None)-> list[PyGe.Curve2d] :
        '''                             '''
        ...
    def getClosestPointTo (self, other : PyGe.Point2d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve2d :
        '''                             '''
        ...
    def getClosestPointsTo (self, other : PyGe.Curve2d, tol : PyGe.Tol=None)-> tuple[PyGe.Point3d,PyGe.Point3d] :
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
    def getSamplePoints (self, numSample: int)-> tuple[list[PyGe.Point2d],list[float]] : ...
    @overload
    def getSamplePoints (self, fromParam: float, toParam: float, approxEps: float)-> tuple[list[PyGe.Point2d],list[float]] : ...
    def getSamplePoints (self, *args, **kwargs)-> tuple[list[PyGe.Point2d],list[float]] :
        '''Overloads:
    - numSample: int
    - fromParam: float, toParam: float, approxEps: float
    '''
        ...
    def getSplitCurves (self, param : float)-> tuple[PyGe.Curve2d,PyGe.Curve2d] :
        '''                             '''
        ...
    def getStartPoint (self)-> PyGe.Point2d :
        '''                             '''
        ...
    def getTrimmedOffset (self, dist : float, extensionType : PyGe.OffsetCrvExtType, tol : PyGe.Tol=None)-> list[PyGe.Curve2d] :
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
    def isDegenerate (self, tol : PyGe.Tol=None)-> tuple[bool,PyGe.Entity2d] :
        '''                             '''
        ...
    def isLinear (self, tol : PyGe.Tol=None)-> tuple[bool,PyGe.Line2d] :
        '''                             '''
        ...
    def isOn (self, pt : float | PyGe.Point2d, tol : PyGe.Tol=None)-> tuple :
        '''                             '''
        ...
    def isPeriodic (self)-> tuple[bool,float] :
        '''                             '''
        ...
    def length (self, frm : float, to : float, tol : float = None)-> float :
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
    def setInterval (self, val : PyGe.Interval = None)-> None :
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
    def explode (self, val : PyGe.Interval = None)-> list[PyGe.Curve3d] :
        '''Explodes the curve into its individual components. If the curve is a composite curve, then explodedCurves contains the list of component curves of the composite. If the curve is a spline, then it is exploded at the points of C1 discontinuity and explodedCurves contains a copy of each continuous sub-curve. This function returns Adesk::kTrue if the curve was exploded (that is, the curve was a composite or a discontinuous spline) and Adesk::kFalse otherwise. The number of entries returned in newExplodedCurves is always the same as the number of entries in explodedCurves. Each flag in newExplodedCurves indicates whether the corresponding curve in explodedCurves was created with the new operator. If the flag is 1, then it is the responsibility of the caller to delete the curve. If the flag is 0, the curve is deleted by gelib and the caller should not attempt to delete it. If no intrvl parameter is supplied, then the interval is taken to be the entire curve. '''
        ...
    def getClosestPointTo (self, other : PyGe.Point3d, tol : PyGe.Tol=None)-> PyGe.PointOnCurve3d :
        '''Finds the closest point on this curve to the input point. This function is the same as closestPointTo(), except that the closest point is returned as an AcGePointOnCurve3d object.'''
        ...
    def getClosestPointsTo (self, other : PyGe.Curve3d, tol : PyGe.Tol=None)-> tuple[PyGe.Point3d,PyGe.Point3d] :
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
    def getProjClosestPointsTo (self, pt : PyGe.Curve3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> tuple[PyGe.PointOnCurve3d,PyGe.PointOnCurve3d] :
        '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
        ...

    @overload
    def getSamplePoints (self, numSample: int)-> tuple[list[PyGe.Point3d],list[float]] : ...
    @overload
    def getSamplePoints (self, fromParam: float, toParam: float, approxEps: float)-> tuple[list[PyGe.Point3d],list[float]] : ...
    def getSamplePoints (self, *args, **kwargs)-> tuple[list[PyGe.Point3d],list[float]] :
        '''Overloads:
    - numSample: int
    - fromParam: float, toParam: float, approxEps: float
    
	-Returns the specified number of points on the curve. The points are equally spaced by parameter value. So if the interval of the curve [0,1] and numSample is 5, the parameter values of the returned points are 0, 0.25, 0.5, 0.75, and 1.-'''
        ...
    def getSplitCurves (self, param : float)-> tuple[PyGe.Curve3d,PyGe.Curve3d] :
        '''Returns two segments which are obtained by splitting the curve at the input parameter value. If the specified parameter value does not lie within the parametric interval of the curve or if it corresponds to the start point or endpoint of the curve, then piece1 and piece2 are set to null. This function uses the new to create the curve segments whose addresses are returned in piece1 and piece2. It is the responsibility of the caller to delete these objects. '''
        ...
    def getStartPoint (self)-> PyGe.Point3d :
        '''                             '''
        ...
    def getTrimmedOffset (self, dist : float, planeNormal : PyGe.Vector3d, extensionType : PyGe.OffsetCrvExtType, tol : PyGe.Tol=None)-> list[PyGe.Curve3d] :
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
    def isCoplanarWith (self, curve : PyGe.Curve3d, tol : PyGe.Tol=None)-> tuple[bool,PyGe.Plane] :
        '''Returns Adesk::kTrue if both curve are planar and lie in the same plane. The plane parameter is only valid if this function returns a value of Adesk::kTrue.'''
        ...
    def isDegenerate (self, tol : PyGe.Tol=None)-> tuple[bool,PyGe.Entity3d] :
        '''Determines if the curve is degenerate and if so returns the type of entity which the curve degenerates into. For example, if the curve is a circle with a radius of 0 then degenerateType is set to AcGe::kPoint3d. If the curve is an ellipse with a minor radius of 0 and a major radius of 1, then degenerateType is set to AcGe::kLineSeg3d. The degenerateType parameter is only set to something meaningful when this function returns a value of Adesk::kTrue.'''
        ...
    def isLinear (self, tol : PyGe.Tol=None)-> tuple[bool,PyGe.Line3d] :
        '''Determines if curve is linear. This function returns an infinite line even if the curve is not infinite. The line parameter contains meaningful data only if this function returns a value of Adesk::kTrue.'''
        ...
    def isOn (self, pt : float | PyGe.Point3d, tol : PyGe.Tol=None)-> tuple :
        '''Determines if input parameter value is within valid parametric range of curve.'''
        ...
    def isPeriodic (self)-> tuple[bool,float] :
        '''Determines if the curve is periodic. The curve is periodic if and only if it is closed and the two points evalPoint(t) and evalPoint(t+period) are always the same point for all values of t.'''
        ...
    def isPlanar (self, tol : PyGe.Tol=None)-> tuple[bool,PyGe.Plane] :
        '''Determines if curve is planar. If the curve is a line, then this function returns an arbitrary plane that contains the line. The plane parameter contains meaningful data only if this function returns a value of Adesk::kTrue. '''
        ...
    def length (self, frm : float, to : float, tol : float = None)-> float :
        '''Returns the arc length of the curve between the two parameter values.'''
        ...
    def orthoBoundBlock (self, range : PyGe.Interval = None)-> PyGe.BoundBlock3d :
        '''Returns the bounding box of the curve. The sides of the returned box are parallel to the coordinate axes.'''
        ...
    def orthoProject (self, projectionPlane : PyGe.Plane, tol : PyGe.Tol=None)-> PyGe.Entity3d :
        '''Returns the entity that is the orthogonal projection of the curve onto the projection plane. The returned entity may not be of the same type as the original curve and may not even be a curve (for instance, a line projects into a point if it is orthogonal to the projection plane). The returned entity is created with the new and it is the responsibility of the caller to delete it.'''
        ...
    def paramAtLength (self, datumParam : float, length : float, posParamDir : bool=True, tol : float=None)-> float :
        '''Returns the parameter value of the point whose arc length distance (from the point with parameter value datumParam) is the input length. In other words, ift = paramAtLength (datumParam, len, posParamDir, tol) then length (t, datumParam, tol) is (approximately) equal to len. If posParamDir is set to Adesk::kTrue, then the returned parameter value is greater than datumParam. Otherwise it will be less than datumParam. '''
        ...
    def paramOf (self, pt : PyGe.Point3d, tol : PyGe.Tol=None)-> float :
        '''Returns the parameter value of pnt. This function assumes that pnt lies on the curve and does not verify this. If pnt does not lie on the curve, this function will return unpredictable results. If it is not known whether pnt lies on the curve, the user should not call this function but should instead call AcGeCurve3d::isOn (pnt, param, tol). '''
        ...
    def projClosestPointTo (self, pt : PyGe.Point3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.Point3d :
        '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
        ...
    def projClosestPointsTo (self, pt : PyGe.Curve3d, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> tuple[PyGe.Point3d,PyGe.Point3d] :
        '''Finds the point on the curve which when projected onto a plane whose normal is projectDirection is the closest point on the projected curve to the input point. This function is mainly used by graphics where projectDirection is the line of sight. In this case, this function returns the point on the curve that appears to be closest to the input point (but may not be the actual closest point). This function is the same as projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a AcGePointOnCurve3d object instead of a AcGePoint3d object.'''
        ...
    def project (self, projectionPlane : PyGe.Plane, projDir : PyGe.Vector3d, tol : PyGe.Tol=None)-> PyGe.Entity3d :
        '''Returns the entity that is the projection of the curve onto the projection plane in the specified direction. The projectDirection vector must not be parallel to the projection plane. The returned entity may not be of the same type as the original curve and may not even be a curve (for instance, a line projects into a point if it is parallel to projectDirection). The returned entity is created with the new and it is the responsibility of the caller to delete it.'''
        ...
    def reverseParam (self)-> None :
        '''Reverses the parametric direction of the curve. The point set of the curve is unchanged, but the direction of the curve is reversed.'''
        ...
    def setInterval (self, val : PyGe.Interval = None)-> None :
        '''Sets the domain of the curve to the input interval.'''
        ...

class CurveCurveInt2d(Entity2d):

    @overload
    def __init__ (self, /)-> None : ...
    @overload
    def __init__ (self, curve1: PyGe.Curve2d, curve2: PyGe.Curve2d)-> None : ...
    @overload
    def __init__ (self, curve1: PyGe.Curve2d, curve2: PyGe.Curve2d, tol: PyGe.Tol)-> None : ...
    @overload
    def __init__ (self, curve1: PyGe.Curve2d, curve2: PyGe.Curve2d, range1: PyGe.Interval, range2: PyGe.Interval)-> None : ...
    @overload
    def __init__ (self, curve1: PyGe.Curve2d, curve2: PyGe.Curve2d, range1: PyGe.Interval, range2: PyGe.Interval, tol: PyGe.Tol)-> None : ...
    def __init__ (self, *args, **kwargs)-> None :
        '''Overloads:
    - None: Any
    - curve1: PyGe.Curve2d, curve2: PyGe.Curve2d
    - curve1: PyGe.Curve2d, curve2: PyGe.Curve2d, tol: PyGe.Tol
    - curve1: PyGe.Curve2d, curve2: PyGe.Curve2d, range1: PyGe.Interval, range2: PyGe.Interval
    - curve1: PyGe.Curve2d, curve2: PyGe.Curve2d, range1: PyGe.Interval, range2: PyGe.Interval, tol: PyGe.Tol
    '''
        ...

    @staticmethod
    def cast (otherObject: PyGe.Entity2d)-> PyGe.CurveCurveInt2d :
        '''                             '''
        ...
    def changeCurveOrder (self)-> None :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def copycast (otherObject: PyGe.Entity2d)-> PyGe.CurveCurveInt2d :
        '''                             '''
        ...
    def curve1 (self)-> PyGe.Curve2d :
        '''                             '''
        ...
    def curve2 (self)-> PyGe.Curve2d :
        '''                             '''
        ...
    def getIntConfigs (self, intNum: int)-> tuple :
        '''                             '''
        ...
    def getIntParams (self, intNum: int)-> tuple[float,float] :
        '''                             '''
        ...
    def getIntRanges (self)-> tuple[PyGe.Interval,PyGe.Interval] :
        '''                             '''
        ...
    def getOverlapRanges (self, intNum: int)-> tuple[PyGe.Interval,PyGe.Interval] :
        '''                             '''
        ...
    def getPointOnCurve1 (self, intNum: int)-> PyGe.PointOnCurve2d :
        '''                             '''
        ...
    def getPointOnCurve2 (self, intNum: int)-> PyGe.PointOnCurve2d :
        '''                             '''
        ...
    def intPoint (self, intNum: int)-> PyGe.Point2d :
        '''                             '''
        ...
    def intPointTol (self, intNum: int)-> float :
        '''                             '''
        ...
    def isTangential (self, intNum: int)-> bool :
        '''                             '''
        ...
    def isTransversal (self, intNum: int)-> bool :
        '''                             '''
        ...
    def numIntPoints (self)-> int :
        '''                             '''
        ...
    def orderWrt1 (self)-> PyGe.CurveCurveInt2d :
        '''                             '''
        ...
    def orderWrt2 (self)-> PyGe.CurveCurveInt2d :
        '''                             '''
        ...
    def overlapCount (self)-> int :
        '''                             '''
        ...
    def overlapDirection (self)-> bool :
        '''                             '''
        ...
    def tolerance (self)-> PyGe.Tol :
        '''                             '''
        ...

class CurveCurveInt3d(Entity3d):

    @overload
    def __init__ (self, /)-> None : ...
    @overload
    def __init__ (self, curve1: PyGe.Curve3d, curve2: PyGe.Curve3d)-> None : ...
    @overload
    def __init__ (self, curve1: PyGe.Curve3d, curve2: PyGe.Curve3d, planeNormal: PyGe.Vector3d, tol: PyGe.Tol)-> None : ...
    @overload
    def __init__ (self, curve1: PyGe.Curve3d, curve2: PyGe.Curve3d, range1: PyGe.Interval, range2: PyGe.Interval)-> None : ...
    @overload
    def __init__ (self, curve1: PyGe.Curve3d, curve2: PyGe.Curve3d, range1: PyGe.Interval, range2: PyGe.Interval, tol: PyGe.Tol)-> None : ...
    def __init__ (self, *args, **kwargs)-> None :
        '''Overloads:
    - None: Any
    - curve1: PyGe.Curve3d, curve2: PyGe.Curve3d
    - curve1: PyGe.Curve3d, curve2: PyGe.Curve3d, planeNormal: PyGe.Vector3d, tol: PyGe.Tol
    - curve1: PyGe.Curve3d, curve2: PyGe.Curve3d, range1: PyGe.Interval, range2: PyGe.Interval
    - curve1: PyGe.Curve3d, curve2: PyGe.Curve3d, range1: PyGe.Interval, range2: PyGe.Interval, tol: PyGe.Tol
    '''
        ...

    @staticmethod
    def cast (otherObject: PyGe.Entity3d)-> PyGe.CurveCurveInt3d :
        '''                             '''
        ...
    def changeCurveOrder (self)-> None :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def copycast (otherObject: PyGe.Entity3d)-> PyGe.CurveCurveInt3d :
        '''                             '''
        ...
    def curve1 (self)-> PyGe.Curve3d :
        '''                             '''
        ...
    def curve2 (self)-> PyGe.Curve3d :
        '''                             '''
        ...
    def getIntConfigs (self, intNum: int)-> tuple :
        '''                             '''
        ...
    def getIntParams (self, intNum: int)-> tuple[float,float] :
        '''                             '''
        ...
    def getIntRanges (self)-> tuple[PyGe.Interval,PyGe.Interval] :
        '''                             '''
        ...
    def getOverlapRanges (self, intNum: int)-> tuple[PyGe.Interval,PyGe.Interval] :
        '''                             '''
        ...
    def getPointOnCurve1 (self, intNum: int)-> PyGe.PointOnCurve3d :
        '''                             '''
        ...
    def getPointOnCurve2 (self, intNum: int)-> PyGe.PointOnCurve3d :
        '''                             '''
        ...
    def intPoint (self, intNum: int)-> PyGe.Point3d :
        '''                             '''
        ...
    def intPointTol (self, intNum: int)-> float :
        '''                             '''
        ...
    def isTangential (self, intNum: int)-> bool :
        '''                             '''
        ...
    def isTransversal (self, intNum: int)-> bool :
        '''                             '''
        ...
    def numIntPoints (self)-> int :
        '''                             '''
        ...
    def orderWrt1 (self)-> PyGe.CurveCurveInt3d :
        '''                             '''
        ...
    def orderWrt2 (self)-> PyGe.CurveCurveInt3d :
        '''                             '''
        ...
    def overlapCount (self)-> int :
        '''                             '''
        ...
    def overlapDirection (self)-> bool :
        '''                             '''
        ...
    def planeNormal (self)-> PyGe.Vector3d :
        '''                             '''
        ...
    def tolerance (self)-> PyGe.Tol :
        '''                             '''
        ...

class CurveSurfInt(Entity3d):

    @overload
    def __init__ (self, /)-> None : ...
    @overload
    def __init__ (self, curve: PyGe.Curve3d, surf: PyGe.Surface)-> None : ...
    @overload
    def __init__ (self, curve: PyGe.Curve3d, surf: PyGe.Surface, tol: PyGe.Tol)-> None : ...
    def __init__ (self, *args, **kwargs)-> None :
        '''Overloads:
    - None: Any
    - curve: PyGe.Curve3d, surf: PyGe.Surface
    - curve: PyGe.Curve3d, surf: PyGe.Surface, tol: PyGe.Tol
    '''
        ...

    @staticmethod
    def cast (otherObject: PyGe.Entity3d)-> PyGe.CurveSurfInt :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def copycast (otherObject: PyGe.Entity3d)-> PyGe.CurveSurfInt :
        '''                             '''
        ...
    def curve (self)-> PyGe.Curve3d :
        '''                             '''
        ...
    def getIntConfigs (self, intNum: int)-> tuple :
        '''                             '''
        ...
    def getIntParams (self, intNum: int)-> tuple[float,PyGe.Point2d] :
        '''                             '''
        ...
    def getPointOnCurve (self, intNum: int)-> PyGe.PointOnCurve3d :
        '''                             '''
        ...
    def getPointOnSurface (self, intNum: int)-> PyGe.PointOnSurface :
        '''                             '''
        ...
    def intPoint (self, intNum: int)-> PyGe.Point3d :
        '''                             '''
        ...
    def numIntPoints (self)-> int :
        '''                             '''
        ...

    @overload
    def set (self, curve: PyGe.Curve3d, surf: PyGe.Surface)-> None : ...
    @overload
    def set (self, curve: PyGe.Curve3d, surf: PyGe.Surface, tol: PyGe.Tol)-> None : ...
    def set (self, *args, **kwargs)-> None :
        '''Overloads:
    - curve: PyGe.Curve3d, surf: PyGe.Surface
    - curve: PyGe.Curve3d, surf: PyGe.Surface, tol: PyGe.Tol
    '''
        ...
    def surface (self)-> PyGe.Surface :
        '''                             '''
        ...
    def tolerance (self)-> PyGe.Tol :
        '''                             '''
        ...

class Cylinder(Surface):

    @overload
    def __init__ (self, /)-> None : ...
    @overload
    def __init__ (self, radius: float, origin: PyGe.Point3d, axisOfSymmetry: PyGe.Vector3d)-> None : ...
    @overload
    def __init__ (self, radius: float, origin: PyGe.Point3d, axisOfSymmetry: PyGe.Vector3d, refAxis: PyGe.Vector3d, height: PyGe.Interval, startAngle: float, endAngle: float)-> None : ...
    def __init__ (self, *args, **kwargs)-> None :
        '''Overloads:
    - None: Any
    - radius: float, origin: PyGe.Point3d, axisOfSymmetry: PyGe.Vector3d
    - radius: float, origin: PyGe.Point3d, axisOfSymmetry: PyGe.Vector3d, refAxis: PyGe.Vector3d, height: PyGe.Interval, startAngle: float, endAngle: float
    '''
        ...
    def axisOfSymmetry (self)-> PyGe.Vector3d :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PyGe.Entity3d)-> PyGe.Cylinder :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def copycast (otherObject: PyGe.Entity3d)-> PyGe.Cylinder :
        '''                             '''
        ...
    def getAngles (self)-> tuple[float,float] :
        '''                             '''
        ...
    def getHeight (self)-> PyGe.Interval :
        '''                             '''
        ...
    def heightAt (self, u: float)-> float :
        '''                             '''
        ...
    def intersectWith (self, val: PyGe.LinearEnt3d, tol: PyGe.Tol=None)-> tuple[bool,int,PyGe.Point3d,PyGe.Point3d] :
        '''                             '''
        ...
    def isClosed (self, tol: PyGe.Tol=None)-> bool :
        '''                             '''
        ...
    def isOuterNormal (self)-> bool :
        '''                             '''
        ...
    def origin (self)-> PyGe.Point3d :
        '''                             '''
        ...
    def radius (self)-> float :
        '''                             '''
        ...
    def refAxis (self)-> PyGe.Vector3d :
        '''                             '''
        ...

    @overload
    def set (self, radius: float, origin: PyGe.Point3d, axisOfSymmetry: PyGe.Vector3d)-> None : ...
    @overload
    def set (self, radius: float, origin: PyGe.Point3d, axisOfSymmetry: PyGe.Vector3d, refAxis: PyGe.Vector3d, height: PyGe.Interval, startAngle: float, endAngle: float)-> None : ...
    def set (self, *args, **kwargs)-> None :
        '''Overloads:
    - radius: float, origin: PyGe.Point3d, axisOfSymmetry: PyGe.Vector3d
    - radius: float, origin: PyGe.Point3d, axisOfSymmetry: PyGe.Vector3d, refAxis: PyGe.Vector3d, height: PyGe.Interval, startAngle: float, endAngle: float
    '''
        ...
    def setAngles (self, start: float, end: float)-> None :
        '''                             '''
        ...
    def setHeight (self, val: PyGe.Interval)-> None :
        '''                             '''
        ...
    def setRadius (self, val: float)-> None :
        '''                             '''
        ...

class EllipArc2d(Curve2d):

    @overload
    def __init__ (self, /)-> None : ...
    @overload
    def __init__ (self, carc: PyGe.CircArc2d)-> None : ...
    @overload
    def __init__ (self, cent: PyGe.Point2d, majorAxis: PyGe.Vector2d, minorAxis: PyGe.Vector2d, majorRadius: float,minorRadius: float)-> None : ...
    @overload
    def __init__ (self, cent: PyGe.Point2d, majorAxis: PyGe.Vector2d, minorAxis: PyGe.Vector2d, majorRadius: float,minorRadius: float, startAngle: float, endAngle: float)-> None : ...
    def __init__ (self, *args, **kwargs)-> None :
        '''Overloads:
    - None: Any
    - carc: PyGe.CircArc2d
    - cent: PyGe.Point2d, majorAxis: PyGe.Vector2d, minorAxis: PyGe.Vector2d, majorRadius: float,minorRadius: float
    - cent: PyGe.Point2d, majorAxis: PyGe.Vector2d, minorAxis: PyGe.Vector2d, majorRadius: float,minorRadius: float, startAngle: float, endAngle: float
    '''
        ...

    @staticmethod
    def cast (otherObject: PyGe.Entity2d)-> PyGe.EllipArc2d :
        '''                             '''
        ...
    def center (self)-> PyGe.Point2d :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def copycast (otherObject: PyGe.Entity2d)-> PyGe.EllipArc2d :
        '''                             '''
        ...
    def endAng (self)-> float :
        '''                             '''
        ...
    def endPoint (self)-> PyGe.Point2d :
        '''                             '''
        ...
    def intersectWith (self, val: PyGe.LinearEnt2d, tol: PyGe.Tol = None)-> tuple[bool,int,PyGe.Point2d,PyGe.Point2d] :
        '''                             '''
        ...
    def isCircular (self, tol: PyGe.Tol=None)-> bool :
        '''                             '''
        ...
    def isClockWise (self)-> bool :
        '''                             '''
        ...
    def isInside (self, pt: PyGe.Point2d, tol: PyGe.Tol=None)-> bool :
        '''                             '''
        ...
    def majorAxis (self)-> PyGe.Vector2d :
        '''                             '''
        ...
    def majorRadius (self)-> float :
        '''                             '''
        ...
    def minorAxis (self)-> PyGe.Vector2d :
        '''                             '''
        ...
    def minorRadius (self)-> float :
        '''                             '''
        ...

    @overload
    def set (self, carc: PyGe.CircArc2d,)-> None : ...
    @overload
    def set (self, cent: PyGe.Point2d, majorAxis: PyGe.Vector2d, minorAxis: PyGe.Vector2d, majorRadius: float,minorRadius: float)-> None : ...
    @overload
    def set (self, cent: PyGe.Point2d, majorAxis: PyGe.Vector2d, minorAxis: PyGe.Vector2d, majorRadius: float,minorRadius: float, startAngle: float, endAngle: float)-> None : ...
    def set (self, *args, **kwargs)-> None :
        '''Overloads:
    - carc: PyGe.CircArc2d,
    - cent: PyGe.Point2d, majorAxis: PyGe.Vector2d, minorAxis: PyGe.Vector2d, majorRadius: float,minorRadius: float
    - cent: PyGe.Point2d, majorAxis: PyGe.Vector2d, minorAxis: PyGe.Vector2d, majorRadius: float,minorRadius: float, startAngle: float, endAngle: float
    '''
        ...
    def setAngles (self, startAngle: float, endAngle: float)-> None :
        '''                             '''
        ...
    def setAxes (self, majorAxis: PyGe.Vector2d, minorAxis: PyGe.Vector2d)-> None :
        '''                             '''
        ...
    def setCenter (self, pt: PyGe.Point2d)-> None :
        '''                             '''
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
    def startPoint (self)-> PyGe.Point2d :
        '''                             '''
        ...

class EllipArc3d(Curve3d):

    @overload
    def __init__ (self, /)-> None : ...
    @overload
    def __init__ (self, carc: PyGe.CircArc3d)-> None : ...
    @overload
    def __init__ (self, cent: PyGe.Point3d, majorAxis: PyGe.Vector3d, minorAxis: PyGe.Vector3d, majorRadius: float,minorRadius: float)-> None : ...
    @overload
    def __init__ (self, cent: PyGe.Point3d, majorAxis: PyGe.Vector3d, minorAxis: PyGe.Vector3d, majorRadius: float,minorRadius: float, startAngle: float, endAngle: float)-> None : ...
    def __init__ (self, *args, **kwargs)-> None :
        '''Overloads:
    - None: Any
    - carc: PyGe.CircArc3d
    - cent: PyGe.Point3d, majorAxis: PyGe.Vector3d, minorAxis: PyGe.Vector3d, majorRadius: float,minorRadius: float
    - cent: PyGe.Point3d, majorAxis: PyGe.Vector3d, minorAxis: PyGe.Vector3d, majorRadius: float,minorRadius: float, startAngle: float, endAngle: float
    '''
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
    def closestPointToPlane (self, plane: PyGe.PlanarEnt, tol: PyGe.Tol=None)-> tuple[PyGe.Point3d,PyGe.Point3d] :
        '''                             '''
        ...

    @staticmethod
    def copycast (otherObject: PyGe.Entity3d)-> PyGe.EllipArc3d :
        '''                             '''
        ...
    def endAng (self)-> float :
        '''                             '''
        ...
    def endPoint (self)-> PyGe.Point3d :
        '''                             '''
        ...
    def getPlane (self)-> PyGe.Plane :
        '''                             '''
        ...
    def intersectWith (self, other: PyGe.LinearEnt3d|PyGe.PlanarEnt, tol: PyGe.Tol=None)-> tuple[bool,int,PyGe.Point3d,PyGe.Point3d] :
        '''                             '''
        ...
    def isCircular (self, tol: PyGe.Tol=None)-> bool :
        '''                             '''
        ...
    def isInside (self, pt: PyGe.Point3d, tol: PyGe.Tol=None)-> bool :
        '''                             '''
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
    def normal (self)-> PyGe.Vector3d :
        '''                             '''
        ...
    def projIntersectWith (self, other: PyGe.LinearEnt3d, projDir: PyGe.Vector3d, tol: PyGe.Tol=None)-> tuple :
        '''                             '''
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
    def isOn (self, pt : PyGe.Point2d, tol : PyGe.Tol=None)-> bool :
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
    def isOn (self, pt : PyGe.Point3d, tol : PyGe.Tol=None)-> bool :
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

class ExternalBoundedSurface(Surface):
    def __init__ (self)-> None :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PyGe.Entity3d)-> PyGe.ExternalBoundedSurface :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def copycast (otherObject: PyGe.Entity3d)-> PyGe.ExternalBoundedSurface :
        '''                             '''
        ...

class ExternalCurve2d(Curve2d):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...

    @staticmethod
    def cast (otherObject: PyGe.Entity2d)-> PyGe.ExternalCurve2d :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def copycast (otherObject: PyGe.Entity2d)-> PyGe.ExternalCurve2d :
        '''                             '''
        ...

class ExternalCurve3d(Curve3d):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...

    @staticmethod
    def cast (otherObject: PyGe.Entity3d)-> PyGe.ExternalCurve3d :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def copycast (otherObject: PyGe.Entity3d)-> PyGe.ExternalCurve3d :
        '''                             '''
        ...
    def externalCurveKind (self)-> PyGe.ExternalEntityKind :
        '''                             '''
        ...
    def getNativeCurve (self)-> PyGe.Curve3d :
        '''                             '''
        ...
    def isCircArc (self)-> bool :
        '''                             '''
        ...
    def isDefined (self)-> bool :
        '''                             '''
        ...
    def isEllipArc (self)-> bool :
        '''                             '''
        ...
    def isLine (self)-> bool :
        '''                             '''
        ...
    def isLineSeg (self)-> bool :
        '''                             '''
        ...
    def isNurbCurve (self)-> bool :
        '''                             '''
        ...
    def isOwnerOfCurve (self)-> bool :
        '''                             '''
        ...
    def isRay (self)-> bool :
        '''                             '''
        ...
    def setToOwnCurve (self)-> None :
        '''                             '''
        ...

class ExternalEntityKind(object):
    def kAcisEntity (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kExternalEntityUndefined (self, *args, **kwargs)-> None :
        '''None'''
        ...

class ExternalSurface(Surface):
    def __init__ (self)-> None :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PyGe.Entity3d)-> PyGe.ExternalSurface :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def copycast (otherObject: PyGe.Entity3d)-> PyGe.ExternalSurface :
        '''                             '''
        ...

class Interval(object):

    @overload
    def __init__ (self, /)-> None : ...
    @overload
    def __init__ (self, lower: float, upper: float)-> None : ...
    @overload
    def __init__ (self, bounded:bool, upper: float)-> None : ...
    def __init__ (self, *args, **kwargs)-> None :
        '''Overloads:
    - None: Any
    - lower: float, upper: float
    - bounded:bool, upper: float
    '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def contains (self, val: PyGe.Interval|float)-> bool :
        '''                             '''
        ...
    def element (self)-> float :
        '''                             '''
        ...
    def getBounds (self)-> tuple[float,float] :
        '''                             '''
        ...
    def getMerge (self, val: float)-> PyGe.Interval :
        '''                             '''
        ...
    def intersectWith (self, val: PyGe.Interval)-> tuple[bool,PyGe.Interval] :
        '''                             '''
        ...
    def isBounded (self)-> bool :
        '''                             '''
        ...
    def isBoundedAbove (self)-> bool :
        '''                             '''
        ...
    def isBoundedBelow (self)-> bool :
        '''                             '''
        ...
    def isContinuousAtUpper (self, val: PyGe.Interval)-> bool :
        '''                             '''
        ...
    def isDisjoint (self, val: PyGe.Interval)-> bool :
        '''                             '''
        ...
    def isEqualAtLower (self, val: PyGe.Interval|float)-> bool :
        '''                             '''
        ...
    def isEqualAtUpper (self, val: PyGe.Interval|float)-> bool :
        '''                             '''
        ...
    def isGreater (self, val: PyGe.Interval|float)-> bool :
        '''                             '''
        ...
    def isGreaterOrEqual (self, val: PyGe.Interval|float)-> bool :
        '''                             '''
        ...
    def isLess (self, val: PyGe.Interval|float)-> bool :
        '''                             '''
        ...
    def isLessOrEqual (self, val: PyGe.Interval|float)-> bool :
        '''                             '''
        ...
    def isOverlapAtUpper (self, val: PyGe.Interval)-> tuple[bool,PyGe.Interval] :
        '''                             '''
        ...
    def isPeriodicallyOn (self, val: float)-> tuple[bool,float] :
        '''                             '''
        ...
    def isSingleton (self)-> bool :
        '''                             '''
        ...
    def isUnBounded (self)-> bool :
        '''                             '''
        ...
    def length (self)-> float :
        '''                             '''
        ...
    def lowerBound (self)-> float :
        '''                             '''
        ...

    @overload
    def set (self, /)-> None : ...
    @overload
    def set (self, lower: float, upper: float)-> None : ...
    @overload
    def set (self, bounded:bool, upper: float)-> None : ...
    def set (self, *args, **kwargs)-> None :
        '''Overloads:
    - None: Any
    - lower: float, upper: float
    - bounded:bool, upper: float
    '''
        ...
    def setLower (self, val: float)-> None :
        '''                             '''
        ...
    def setTolerance (self, val: float)-> None :
        '''                             '''
        ...
    def setUpper (self, val: float)-> None :
        '''                             '''
        ...
    def subtract (self, val: PyGe.Interval)-> tuple[int,PyGe.Interval,PyGe.Interval] :
        '''                             '''
        ...
    def tolerance (self)-> float :
        '''                             '''
        ...
    def upperBound (self)-> float :
        '''                             '''
        ...

class KnotParameterization(object):
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

class KnotVector(object):

    @overload
    def __init__ (self, /)-> None : ...
    @overload
    def __init__ (self, size: int, growSize: int)-> None : ...
    @overload
    def __init__ (self, data: list[float])-> None : ...
    @overload
    def __init__ (self, plusMult: int, other: PyGe.KnotVector)-> None : ...
    def __init__ (self, *args, **kwargs)-> None :
        '''Overloads:
    - None: Any
    - size: int, growSize: int
    - data: list[float]
    - plusMult: int, other: PyGe.KnotVector
    '''
        ...

    @overload
    def append (self, val:float)-> int : ...
    @overload
    def append (self, tail: PyGe.KnotVector)-> int : ...
    @overload
    def append (self, tail: PyGe.KnotVector, knotRatio: float)-> int : ...
    def append (self, *args, **kwargs)-> int :
        '''Overloads:
    - val:float
    - tail: PyGe.KnotVector
    - tail: PyGe.KnotVector, knotRatio: float
    '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def contains (self, param: float)-> bool :
        '''                             '''
        ...
    def endParam (self)-> float :
        '''                             '''
        ...
    def getDistinctKnots (self)-> list[float] :
        '''                             '''
        ...
    def getInterval (self, ord: int, param: float)-> tuple[int,PyGe.Interval] :
        '''                             '''
        ...
    def growLength (self)-> int :
        '''                             '''
        ...
    def insert (self, u: float)-> None :
        '''                             '''
        ...
    def insertAt (self, idx: int, u: float, multiplicity: int)-> None :
        '''                             '''
        ...
    def isEmpty (self)-> bool :
        '''                             '''
        ...
    def isEqualTo (self, other: PyGe.KnotVector)-> bool :
        '''                             '''
        ...
    def isOn (self, knot: float)-> bool :
        '''                             '''
        ...
    def length (self)-> int :
        '''                             '''
        ...
    def logicalLength (self)-> int :
        '''                             '''
        ...
    def multiplicityAt (self, idx: int)-> int :
        '''                             '''
        ...
    def multiplicityAtParam (self, param: float)-> int :
        '''                             '''
        ...
    def numIntervals (self)-> int :
        '''                             '''
        ...
    def physicalLength (self)-> int :
        '''                             '''
        ...
    def removeAt (self, idx: int)-> None :
        '''                             '''
        ...
    def removeSubVector (self, start: int, end: int)-> None :
        '''                             '''
        ...
    def reverse (self)-> None :
        '''                             '''
        ...
    def setGrowLength (self, length: int)-> None :
        '''                             '''
        ...
    def setLogicalLength (self, length: int)-> None :
        '''                             '''
        ...
    def setPhysicalLength (self, length: int)-> None :
        '''                             '''
        ...
    def setRange (self, lower: float, upper: float)-> None :
        '''                             '''
        ...
    def setTolerance (self, tol: float)-> None :
        '''                             '''
        ...
    def split (self, param: float, multilast: int, multifirst: int)-> tuple[PyGe.KnotVector,PyGe.KnotVector] :
        '''                             '''
        ...
    def startParam (self)-> float :
        '''                             '''
        ...
    def tolerance (self)-> float :
        '''                             '''
        ...

class Line2d(LinearEnt2d):

    @overload
    def __init__ (self, /)-> None : ...
    @overload
    def __init__ (self, start: PyGe.Point3d, direction: PyGe.Vector2d)-> None : ...
    @overload
    def __init__ (self, start: PyGe.Point3d, end: PyGe.Point3d)-> None : ...
    def __init__ (self, *args, **kwargs)-> None :
        '''Overloads:
    - None: Any
    - start: PyGe.Point3d, direction: PyGe.Vector2d
    - start: PyGe.Point3d, end: PyGe.Point3d
    '''
        ...

    @staticmethod
    def cast (otherObject: PyGe.Entity2d)-> PyGe.Line2d :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def copycast (otherObject: PyGe.Entity2d)-> PyGe.Line2d :
        '''                             '''
        ...
    def kXAxis (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kYAxis (self, *args, **kwargs)-> None :
        '''None'''
        ...

    @overload
    def set (self, start: PyGe.Point3d, direction: PyGe.Vector2d)-> None : ...
    @overload
    def set (self, start: PyGe.Point3d, end: PyGe.Point3d)-> None : ...
    def set (self, *args, **kwargs)-> None :
        '''Overloads:
    - start: PyGe.Point3d, direction: PyGe.Vector2d
    - start: PyGe.Point3d, end: PyGe.Point3d
    '''
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

    @staticmethod
    def cast (otherObject: PyGe.Entity3d)-> PyGe.Line3d :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def copycast (otherObject: PyGe.Entity3d)-> PyGe.Line3d :
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

class LineSeg2d(LinearEnt2d):

    @overload
    def __init__ (self, /)-> None : ...
    @overload
    def __init__ (self, start: PyGe.Point3d, direction: PyGe.Vector2d)-> None : ...
    @overload
    def __init__ (self, start: PyGe.Point3d, end: PyGe.Point3d)-> None : ...
    def __init__ (self, *args, **kwargs)-> None :
        '''Overloads:
    - None: Any
    - start: PyGe.Point3d, direction: PyGe.Vector2d
    - start: PyGe.Point3d, end: PyGe.Point3d
    '''
        ...
    def baryComb (self, blendCoeff: float)-> PyGe.Point2d :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PyGe.Entity2d)-> PyGe.LineSeg2d :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def copycast (otherObject: PyGe.Entity2d)-> PyGe.LineSeg2d :
        '''                             '''
        ...
    def endPoint (self)-> PyGe.Point2d :
        '''                             '''
        ...
    def getBisector (self)-> PyGe.Line2d :
        '''                             '''
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
    def midPoint (self)-> PyGe.Point2d :
        '''                             '''
        ...

    @overload
    def set (self, start: PyGe.Point3d, direction: PyGe.Vector2d)-> None : ...
    @overload
    def set (self, start: PyGe.Point3d, end: PyGe.Point3d)-> None : ...
    @overload
    def set (self, curve1: PyGe.Curve2d, curve2: PyGe.Curve2d)-> None : ...
    @overload
    def set (self, curve1: PyGe.Curve2d, pnt: PyGe.Point3d)-> None : ...
    def set (self, *args, **kwargs)-> None :
        '''Overloads:
    - start: PyGe.Point3d, direction: PyGe.Vector2d
    - start: PyGe.Point3d, end: PyGe.Point3d
    - curve1: PyGe.Curve2d, curve2: PyGe.Curve2d
    - curve1: PyGe.Curve2d, pnt: PyGe.Point3d
    '''
        ...
    def startPoint (self)-> PyGe.Point2d :
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
    def baryComb (self)-> PyGe.Point3d :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PyGe.Entity3d)-> PyGe.LineSeg3d :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def copycast (otherObject: PyGe.Entity3d)-> PyGe.LineSeg3d :
        '''                             '''
        ...
    def endPoint (self)-> PyGe.Point3d :
        '''                             '''
        ...
    def getBisector (self)-> PyGe.Plane :
        '''                             '''
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
    def startPoint (self)-> PyGe.Point3d :
        '''                             '''
        ...

class LinearEnt2d(Curve2d):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...

    @staticmethod
    def cast (otherObject: PyGe.Entity2d)-> PyGe.LinearEnt2d :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def copycast (otherObject: PyGe.Entity2d)-> PyGe.LinearEnt2d :
        '''                             '''
        ...
    def direction (self)-> PyGe.Vector2d :
        '''                             '''
        ...
    def getLine (self)-> PyGe.Line2d :
        '''                             '''
        ...
    def getPerpLine (self, pt: PyGe.Point2d)-> PyGe.Line2d :
        '''                             '''
        ...
    def intersectWith (self, other: PyGe.LinearEnt2d, tol: PyGe.Tol=None)-> tuple[bool,PyGe.Point2d] :
        '''                             '''
        ...
    def isColinearTo (self, other: PyGe.LinearEnt2d, tol: PyGe.Tol=None)-> bool :
        '''                             '''
        ...
    def isParallelTo (self, other: PyGe.LinearEnt2d, tol: PyGe.Tol=None)-> bool :
        '''                             '''
        ...
    def isPerpendicularTo (self, other: PyGe.LinearEnt2d, tol: PyGe.Tol=None)-> bool :
        '''                             '''
        ...
    def overlap (self, other: PyGe.LinearEnt2d, tol: PyGe.Tol=None)-> tuple[bool,PyGe.LinearEnt2d] :
        '''                             '''
        ...
    def pointOnLine (self)-> PyGe.Point2d :
        '''                             '''
        ...

class LinearEnt3d(Curve3d):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...

    @staticmethod
    def cast (otherObject: PyGe.Entity3d)-> PyGe.LinearEnt3d :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def copycast (otherObject: PyGe.Entity3d)-> PyGe.LinearEnt3d :
        '''                             '''
        ...
    def direction (self)-> PyGe.Vector3d :
        '''                             '''
        ...
    def getLine (self)-> PyGe.Line3d :
        '''                             '''
        ...
    def getPerpPlane (self, pt: PyGe.Point3d)-> PyGe.Plane :
        '''                             '''
        ...
    def intersectWith (self, other: PyGe.LinearEnt3d | PyGe.PlanarEnt, tol: PyGe.Tol=None)-> tuple[bool,PyGe.Point3d,PyGe.Point3d] :
        '''                             '''
        ...
    def isColinearTo (self, pt: PyGe.LinearEnt3d, tol: PyGe.Tol=None)-> bool :
        '''                             '''
        ...

    @overload
    def isOn (self, pnt: PyGe.Point3d)-> tuple[bool,float] : ...
    @overload
    def isOn (self, pnt: PyGe.Point3d, tol: PyGe.Tol)-> tuple[bool,float] : ...
    @overload
    def isOn (self, param: float)-> tuple[bool,float] : ...
    @overload
    def isOn (self, param: float, tol: PyGe.Tol)-> tuple[bool,float] : ...
    @overload
    def isOn (self, plane: PyGe.Plane)-> tuple[bool,float] : ...
    @overload
    def isOn (self, plane: PyGe.Plane, tol: PyGe.Tol)-> tuple[bool,float] : ...
    def isOn (self, *args, **kwargs)-> tuple[bool,float] :
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
    def overlap (self, other: PyGe.LinearEnt3d, tol: PyGe.Tol=None)-> tuple[bool,PyGe.LinearEnt3d] :
        '''                             '''
        ...
    def pointOnLine (self)-> PyGe.Point3d :
        '''                             '''
        ...
    def projIntersectWith (self, other: PyGe.LinearEnt3d, projDir: PyGe.Vector3d, tol: PyGe.Tol=None)-> tuple[bool,PyGe.Point3d,PyGe.Point3d] :
        '''                             '''
        ...

class Matrix2d(object):
    def __imul__ (self, xform: PyGe.Matrix2d)-> PyGe.Matrix2d :
        '''                             '''
        ...
    def __init__ (self)-> None :
        '''                             '''
        ...
    def __mul__ (self, xform: PyGe.Matrix2d)-> PyGe.Matrix2d :
        '''                             '''
        ...

    @staticmethod
    def alignCoordSys (fo: PyGe.Point2d,fe0: PyGe.Vector2d,fe1: PyGe.Vector2d,to: PyGe.Point2d,te0: PyGe.Vector2d,te1: PyGe.Vector2d)-> PyGe.Matrix2d :
        '''                             '''
        ...
    def det (self)-> float :
        '''                             '''
        ...
    def elementAt (self, row: int, col: int)-> float :
        '''                             '''
        ...
    def getCoordSystem (self, origin: PyGe.Point2d, e0: PyGe.Vector2d, e1: PyGe.Vector2d)-> None :
        '''                             '''
        ...
    def getTranslation (self)-> PyGe.Vector2d :
        '''                             '''
        ...
    def inverse (self)-> PyGe.Matrix2d :
        '''                             '''
        ...
    def invert (self)-> PyGe.Matrix2d :
        '''                             '''
        ...
    def isEqualTo (self, xform: PyGe.Matrix2d)-> bool :
        '''                             '''
        ...
    def isScaledOrtho (self, tol: PyGe.Tol=None)-> bool :
        '''                             '''
        ...
    def isSingular (self, tol: PyGe.Tol=None)-> bool :
        '''                             '''
        ...
    def isUniScaledOrtho (self, tol: PyGe.Tol=None)-> bool :
        '''                             '''
        ...
    def kIdentity (self, *args, **kwargs)-> None :
        '''None'''
        ...

    @staticmethod
    def mirroring (pt: PyGe.Point2d|PyGe.Line2d)-> PyGe.Matrix2d :
        '''                             '''
        ...
    def postMultBy (self, xform: PyGe.Matrix2d)-> PyGe.Matrix2d :
        '''                             '''
        ...
    def preMultBy (self, xform: PyGe.Matrix2d)-> PyGe.Matrix2d :
        '''                             '''
        ...

    @staticmethod
    def rotation (val: float,pt: PyGe.Point2d)-> PyGe.Matrix2d :
        '''                             '''
        ...
    def scale (self)-> float :
        '''                             '''
        ...

    @staticmethod
    def scaling (scaleAll:float,center: PyGe.Point2d)-> PyGe.Matrix2d :
        '''                             '''
        ...
    def setCoordSystem (self, origin: PyGe.Point2d, e0: PyGe.Vector2d, e1: PyGe.Vector2d)-> PyGe.Matrix2d :
        '''                             '''
        ...
    def setToAlignCoordSys (self, fo: PyGe.Point2d, fe0: PyGe.Vector2d, fe1: PyGe.Vector2d, to: PyGe.Point2d, te0: PyGe.Vector2d, te1: PyGe.Vector2d)-> PyGe.Matrix2d :
        '''                             '''
        ...
    def setToIdentity (self)-> PyGe.Matrix2d :
        '''                             '''
        ...
    def setToMirroring (self, pt: PyGe.Point2d|PyGe.Line2d)-> PyGe.Matrix2d :
        '''                             '''
        ...
    def setToProduct (self, xform1: PyGe.Matrix2d, xform2: PyGe.Matrix2d)-> PyGe.Matrix2d :
        '''                             '''
        ...
    def setToRotation (self, val: float, pt: PyGe.Point2d=PyGe.Point2d.kOrgin)-> PyGe.Matrix2d :
        '''                             '''
        ...
    def setToScaling (self, val: float, pt: PyGe.Point2d=PyGe.Point2d.kOrgin)-> PyGe.Matrix2d :
        '''                             '''
        ...
    def setToTranslation (self, vec: PyGe.Vector2d)-> PyGe.Matrix2d :
        '''                             '''
        ...
    def setTranslation (self, vec: PyGe.Vector2d)-> PyGe.Matrix2d :
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

    @overload
    def inverse (self, /)-> PyGe.Matrix3d : ...
    @overload
    def inverse (self, tol: PyGe.Tol)-> PyGe.Matrix3d : ...
    @overload
    def inverse (self, xform: PyGe.Matrix3d, tol: float)-> PyGe.Matrix3d : ...
    def inverse (self, *args, **kwargs)-> PyGe.Matrix3d :
        '''Overloads:
    - None: Any
    - tol: PyGe.Tol
    - xform: PyGe.Matrix3d, tol: float'''
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

    @overload
    def __init__ (self, /)-> None : ...
    @overload
    def __init__ (self, src: PyGe.Curve2d)-> None : ...
    @overload
    def __init__ (self, src: PyGe.LineSeg2d)-> None : ...
    @overload
    def __init__ (self, src: PyGe.EllipArc2d)-> None : ...
    @overload
    def __init__ (self, curve: PyGe.Curve2d, epsilon: float)-> None : ...
    @overload
    def __init__ (self, fitPnts: list[PyGe.Point2d], tol: PyGe.Tol)-> None : ...
    @overload
    def __init__ (self, degree: int, fitPolyline: PyGe.Polyline2d, isPeriodic: bool)-> None : ...
    @overload
    def __init__ (self, degree: int, knots: PyGe.KnotVector, cntrlPnts: list[PyGe.Point2d], isPeriodic: bool)-> None : ...
    @overload
    def __init__ (self, fitPoints: list[PyGe.Point2d], fitTangents: list[PyGe.Vector2d], fitTolerance: PyGe.Tol,isPeriodic: bool)-> None : ...
    @overload
    def __init__ (self, fitPoints: list[PyGe.Point2d], startTangent: PyGe.Vector2d, endTangent: PyGe.Vector2d, startTangentDefined: bool, endTangentDefined: bool, fitTolerance: PyGe.Tol)-> None : ...
    @overload
    def __init__ (self, fitPoints: list[PyGe.Point2d], startTangent: PyGe.Vector2d, endTangent: PyGe.Vector2d, startTangentDefined: bool, endTangentDefined: bool, knotParam: PyGe.KnotParameterization, fitTolerance: PyGe.Tol)-> None : ...
    def __init__ (self, *args, **kwargs)-> None :
        '''Overloads:
    - None: Any
    - src: PyGe.Curve2d
    - src: PyGe.LineSeg2d
    - src: PyGe.EllipArc2d
    - curve: PyGe.Curve2d, epsilon: float
    - fitPnts: list[PyGe.Point2d], tol: PyGe.Tol
    - degree: int, fitPolyline: PyGe.Polyline2d, isPeriodic: bool
    - degree: int, knots: PyGe.KnotVector, cntrlPnts: list[PyGe.Point2d], isPeriodic: bool
    - fitPoints: list[PyGe.Point2d], fitTangents: list[PyGe.Vector2d], fitTolerance: PyGe.Tol,isPeriodic: bool
    - fitPoints: list[PyGe.Point2d], startTangent: PyGe.Vector2d, endTangent: PyGe.Vector2d, startTangentDefined: bool, endTangentDefined: bool, fitTolerance: PyGe.Tol
    - fitPoints: list[PyGe.Point2d], startTangent: PyGe.Vector2d, endTangent: PyGe.Vector2d, startTangentDefined: bool, endTangentDefined: bool, knotParam: PyGe.KnotParameterization, fitTolerance: PyGe.Tol
    '''
        ...
    def addControlPointAt (self, newKnot: float, pt: PyGe.Point2d, weight: float)-> bool :
        '''                             '''
        ...
    def addFitPointAt (self, idx: int, pt: PyGe.Point2d)-> bool :
        '''                             '''
        ...
    def addKnot (self, val: float)-> None :
        '''                             '''
        ...
    def buildFitData (self, val: PyGe.KnotParameterization=None)-> bool :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PyGe.Entity2d)-> PyGe.NurbCurve2d :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def copycast (otherObject: PyGe.Entity2d)-> PyGe.NurbCurve2d :
        '''                             '''
        ...
    def deleteControlPointAt (self, val: int)-> bool :
        '''                             '''
        ...
    def deleteFitPointAt (self, idx: int)-> bool :
        '''                             '''
        ...
    def elevateDegree (self, val: int)-> None :
        '''                             '''
        ...
    def evalMode (self)-> bool :
        '''                             '''
        ...
    def getDefinitionData (self)-> tuple :
        '''                             '''
        ...
    def getFitData (self)-> tuple :
        '''                             '''
        ...
    def getFitPointAt (self, idx: int)-> tuple[bool,PyGe.Point2d] :
        '''                             '''
        ...
    def getFitTangents (self)-> tuple[bool.PyGe.Vector2d,PyGe.Vector2d] :
        '''                             '''
        ...
    def getFitTolerance (self)-> tuple[bool,PyGe.Tol] :
        '''                             '''
        ...
    def getParamsOfC1Discontinuity (self, tol: PyGe.Tol)-> tuple[bool,list[float]] :
        '''                             '''
        ...
    def getParamsOfG1Discontinuity (self, tol: PyGe.Tol)-> tuple[bool,list[float]] :
        '''                             '''
        ...
    def hardTrimByParams (self, newStartParam: float, newEndParam: float)-> None :
        '''                             '''
        ...
    def insertKnot (self, val: float)-> None :
        '''                             '''
        ...
    def joinWith (self, val: PyGe.NurbCurve2d)-> None :
        '''                             '''
        ...
    def makeClosed (self)-> None :
        '''                             '''
        ...
    def makeNonPeriodic (self)-> None :
        '''                             '''
        ...
    def makeOpen (self)-> None :
        '''                             '''
        ...
    def makePeriodic (self)-> None :
        '''                             '''
        ...
    def makeRational (self, val: float)-> None :
        '''                             '''
        ...
    def numFitPoints (self)-> int :
        '''                             '''
        ...
    def numWeights (self)-> int :
        '''                             '''
        ...
    def purgeFitData (self)-> bool :
        '''                             '''
        ...
    def setEvalMode (self, val: bool)-> None :
        '''                             '''
        ...

    @overload
    def setFitData (self, degree: int, fitPoints: list[PyGe.Point2d], fitTolerance: PyGe.Tol)-> None : ...
    @overload
    def setFitData (self, fitPoints: list[PyGe.Point2d], startTangent: PyGe.Vector2d, endTangent: PyGe.Vector2d, fitTolerance: PyGe.Tol)-> None : ...
    @overload
    def setFitData (self, fitPoints: list[PyGe.Point2d], startTangent: PyGe.Vector2d, endTangent: PyGe.Vector2d, knotParam: PyGe.KnotParameterization, fitTolerance: PyGe.Tol)-> None : ...
    @overload
    def setFitData (self, knots: PyGe.KnotVector, fitPoints: list[PyGe.Point2d], startTangent: PyGe.Vector2d, endTangent: PyGe.Vector2d, fitTolerance: PyGe.Tol, isPeriodic: bool)-> None : ...
    def setFitData (self, *args, **kwargs)-> None :
        '''Overloads:
    - degree: int, fitPoints: list[PyGe.Point2d], fitTolerance: PyGe.Tol
    - fitPoints: list[PyGe.Point2d], startTangent: PyGe.Vector2d, endTangent: PyGe.Vector2d, fitTolerance: PyGe.Tol
    - fitPoints: list[PyGe.Point2d], startTangent: PyGe.Vector2d, endTangent: PyGe.Vector2d, knotParam: PyGe.KnotParameterization, fitTolerance: PyGe.Tol
    - knots: PyGe.KnotVector, fitPoints: list[PyGe.Point2d], startTangent: PyGe.Vector2d, endTangent: PyGe.Vector2d, fitTolerance: PyGe.Tol, isPeriodic: bool 
    '''
        ...
    def setFitKnotParameterization (self, val: PyGe.KnotParameterization)-> bool :
        '''                             '''
        ...
    def setFitPointAt (self, idx: int, pt: PyGe.Point2d)-> bool :
        '''                             '''
        ...
    def setFitTangents (self, startTangent: PyGe.Vector2d, endTangent: PyGe.Vector2d)-> bool :
        '''                             '''
        ...
    def setFitTolerance (self, tol: PyGe.Tol)-> bool :
        '''                             '''
        ...
    def setWeightAt (self, idx: int, val: float)-> None :
        '''                             '''
        ...
    def weightAt (self, idx: int)-> float :
        '''                             '''
        ...

class NurbCurve3d(SplineEnt3d):

    @overload
    def __init__ (self, /)-> None : ...
    @overload
    def __init__ (self, src: PyGe.Curve3d)-> None : ...
    @overload
    def __init__ (self, src: PyGe.LineSeg3d)-> None : ...
    @overload
    def __init__ (self, src: PyGe.EllipArc3d)-> None : ...
    @overload
    def __init__ (self, curve: PyGe.Curve3d, epsilon: float)-> None : ...
    @overload
    def __init__ (self, fitPnts: list[PyGe.Point3d], tol: PyGe.Tol)-> None : ...
    @overload
    def __init__ (self, degree: int, fitPolyline: PyGe.Polyline3d, isPeriodic: bool)-> None : ...
    @overload
    def __init__ (self, degree: int, knots: PyGe.KnotVector, cntrlPnts: list[PyGe.Point3d], isPeriodic: bool)-> None : ...
    @overload
    def __init__ (self, fitPoints: list[PyGe.Point3d], fitTangents: list[PyGe.Vector3d], fitTolerance: PyGe.Tol,isPeriodic: bool)-> None : ...
    @overload
    def __init__ (self, fitPoints: list[PyGe.Point3d], startTangent: PyGe.Vector3d, endTangent: PyGe.Vector3d, startTangentDefined: bool, endTangentDefined: bool, fitTolerance: PyGe.Tol)-> None : ...
    @overload
    def __init__ (self, fitPoints: list[PyGe.Point3d], startTangent: PyGe.Vector3d, endTangent: PyGe.Vector3d, startTangentDefined: bool, endTangentDefined: bool, knotParam: PyGe.KnotParameterization, fitTolerance: PyGe.Tol)-> None : ...
    def __init__ (self, *args, **kwargs)-> None :
        '''Overloads:
    - None: Any
    - src: PyGe.Curve3d
    - src: PyGe.LineSeg3d
    - src: PyGe.EllipArc3d
    - curve: PyGe.Curve3d, epsilon: float
    - fitPnts: list[PyGe.Point3d], tol: PyGe.Tol
    - degree: int, fitPolyline: PyGe.Polyline3d, isPeriodic: bool
    - degree: int, knots: PyGe.KnotVector, cntrlPnts: list[PyGe.Point3d], isPeriodic: bool
    - fitPoints: list[PyGe.Point3d], fitTangents: list[PyGe.Vector3d], fitTolerance: PyGe.Tol,isPeriodic: bool
    - fitPoints: list[PyGe.Point3d], startTangent: PyGe.Vector3d, endTangent: PyGe.Vector3d, startTangentDefined: bool, endTangentDefined: bool, fitTolerance: PyGe.Tol
    - fitPoints: list[PyGe.Point3d], startTangent: PyGe.Vector3d, endTangent: PyGe.Vector3d, startTangentDefined: bool, endTangentDefined: bool, knotParam: PyGe.KnotParameterization, fitTolerance: PyGe.Tol
    '''
        ...
    def addControlPointAt (self, newKnot: float, pt: PyGe.Point3d, weight: float)-> bool :
        '''                             '''
        ...
    def addFitPointAt (self, idx: int, pt: PyGe.Point3d)-> bool :
        '''                             '''
        ...
    def addKnot (self, val: float)-> None :
        '''                             '''
        ...
    def buildFitData (self, val: PyGe.KnotParameterization=None)-> bool :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PyGe.Entity3d)-> PyGe.NurbCurve3d :
        '''                             '''
        ...

    @staticmethod
    def className (otherObject: PyGe.Entity3d)-> str :
        '''                             '''
        ...

    @staticmethod
    def copycast (otherObject: PyGe.Entity3d)-> PyGe.NurbCurve3d :
        '''                             '''
        ...
    def deleteControlPointAt (self, idx: int)-> bool :
        '''                             '''
        ...
    def deleteFitPointAt (self, idx: int)-> bool :
        '''                             '''
        ...
    def elevateDegree (self, val: int)-> None :
        '''                             '''
        ...
    def evalMode (self)-> bool :
        '''                             '''
        ...
    def getDefinitionData (self)-> tuple :
        '''                             '''
        ...
    def getFitData (self)-> tuple :
        '''                             '''
        ...
    def getFitPointAt (self, idx: int)-> tuple[bool,PyGe.Point3d] :
        '''                             '''
        ...
    def getFitTangents (self)-> tuple[bool.PyGe.Vector3d,PyGe.Vector3d,bool,bool] :
        '''                             '''
        ...
    def getFitTolerance (self)-> tuple[bool,PyGe.Tol] :
        '''                             '''
        ...
    def getParamsOfC1Discontinuity (self, tol: PyGe.Tol)-> tuple[bool,list[float]] :
        '''                             '''
        ...
    def getParamsOfG1Discontinuity (self, tol: PyGe.Tol)-> tuple[bool,list[float]] :
        '''                             '''
        ...
    def hardTrimByParams (self, newStartParam: float, newEndParam: float)-> None :
        '''                             '''
        ...
    def insertKnot (self, val: float)-> None :
        '''                             '''
        ...
    def joinWith (self, val: PyGe.NurbCurve3d)-> None :
        '''                             '''
        ...
    def makeClosed (self)-> None :
        '''                             '''
        ...
    def makeNonPeriodic (self)-> None :
        '''                             '''
        ...
    def makeOpen (self)-> None :
        '''                             '''
        ...
    def makePeriodic (self)-> None :
        '''                             '''
        ...
    def makeRational (self, val: float)-> None :
        '''                             '''
        ...
    def numFitPoints (self)-> int :
        '''                             '''
        ...
    def numWeights (self)-> int :
        '''                             '''
        ...
    def purgeFitData (self)-> bool :
        '''                             '''
        ...
    def setEvalMode (self, val: bool)-> None :
        '''                             '''
        ...

    @overload
    def setFitData (self, degree: int, fitPoints: list[PyGe.Point3d], fitTolerance: PyGe.Tol)-> None : ...
    @overload
    def setFitData (self, fitPoints: list[PyGe.Point3d], startTangent: PyGe.Vector3d, endTangent: PyGe.Vector3d, fitTolerance: PyGe.Tol)-> None : ...
    @overload
    def setFitData (self, fitPoints: list[PyGe.Point3d], startTangent: PyGe.Vector3d, endTangent: PyGe.Vector3d, knotParam: PyGe.KnotParameterization, fitTolerance: PyGe.Tol)-> None : ...
    @overload
    def setFitData (self, knots: PyGe.KnotVector, fitPoints: list[PyGe.Point3d], startTangent: PyGe.Vector3d, endTangent: PyGe.Vector3d, fitTolerance: PyGe.Tol, isPeriodic: bool)-> None : ...
    def setFitData (self, *args, **kwargs)-> None :
        '''Overloads:
    - degree: int, fitPoints: list[PyGe.Point3d], fitTolerance: PyGe.Tol
    - fitPoints: list[PyGe.Point3d], startTangent: PyGe.Vector3d, endTangent: PyGe.Vector3d, fitTolerance: PyGe.Tol
    - fitPoints: list[PyGe.Point3d], startTangent: PyGe.Vector3d, endTangent: PyGe.Vector3d, knotParam: PyGe.KnotParameterization, fitTolerance: PyGe.Tol
    - knots: PyGe.KnotVector, fitPoints: list[PyGe.Point3d], startTangent: PyGe.Vector3d, endTangent: PyGe.Vector3d, fitTolerance: PyGe.Tol, isPeriodic: bool 
    '''
        ...
    def setFitKnotParameterization (self, val: PyGe.KnotParameterization)-> bool :
        '''                             '''
        ...
    def setFitPointAt (self, idx: int, pt: PyGe.Point3d)-> bool :
        '''                             '''
        ...

    @overload
    def setFitTangents (self, startTangent: PyGe.Vector3d, endTangent: PyGe.Vector3d)-> bool : ...
    @overload
    def setFitTangents (self, startTangent: PyGe.Vector3d, endTangent: PyGe.Vector3d, startTangentDefined: bool, endTangentDefined: bool)-> bool : ...
    def setFitTangents (self, *args, **kwargs)-> bool :
        '''Overloads:
    - startTangent: PyGe.Vector3d, endTangent: PyGe.Vector3d
    - startTangent: PyGe.Vector3d, endTangent: PyGe.Vector3d, startTangentDefined: bool, endTangentDefined: bool
    '''
        ...
    def setFitTolerance (self, tol: PyGe.Tol)-> bool :
        '''                             '''
        ...
    def setWeightAt (self, idx: int, val: float)-> None :
        '''                             '''
        ...
    def weightAt (self, idx: int)-> float :
        '''                             '''
        ...

class NurbSurface(Surface):
    def __init__ (self)-> None :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PyGe.Entity3d)-> PyDb.NurbSurface :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def copycast (otherObject: PyGe.Entity3d)-> PyDb.NurbSurface :
        '''                             '''
        ...

class OffsetCrvExtType(object):
    def kChamfer (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kExtend (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kFillet (self, *args, **kwargs)-> None :
        '''None'''
        ...

class OffsetCurve2d(Curve2d):
    def __init__ (self, baseCurve: PyGe.Curve2d, offsetDistance: float)-> None :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PyGe.Entity2d)-> PyGe.OffsetCurve2d :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def copycast (otherObject: PyGe.Entity2d)-> PyGe.OffsetCurve2d :
        '''                             '''
        ...

class OffsetCurve3d(Curve3d):
    def __init__ (self, baseCurve: PyGe.Curve3d, planeNormal: PyGe.Vector3d, offsetDistance: float)-> None :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PyGe.Entity3d)-> PyGe.OffsetCurve3d :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def copycast (otherObject: PyGe.Entity3d)-> PyGe.OffsetCurve3d :
        '''                             '''
        ...
    def curve (self)-> PyGe.Curve3d :
        '''                             '''
        ...
    def normal (self)-> PyGe.Vector3d :
        '''                             '''
        ...
    def offsetDistance (self)-> float :
        '''                             '''
        ...
    def paramDirection (self)-> bool :
        '''                             '''
        ...
    def setCurve (self, val: PyGe.Curve3d)-> None :
        '''                             '''
        ...
    def setNormal (self, normal: PyGe.Vector3d)-> None :
        '''                             '''
        ...
    def setOffsetDistance (self, val: float)-> None :
        '''                             '''
        ...
    def transformation (self)-> PyGe.Matrix3d :
        '''                             '''
        ...

class OffsetSurface(Surface):
    def __init__ (self)-> None :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PyGe.Entity3d)-> PyGe.OffsetSurface :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def copycast (otherObject: PyGe.Entity3d)-> PyGe.OffsetSurface :
        '''                             '''
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
    def closestPointToLinearEnt (self, other: PyGe.LinearEnt3d, tol: PyGe.Tol=None)-> tuple[PyGe.Point3d,PyGe.Point3d] :
        '''                             '''
        ...
    def closestPointToPlanarEnt (self, other: PyGe.PlanarEnt, tol: PyGe.Tol=None)-> tuple[PyGe.Point3d,PyGe.Point3d] :
        '''                             '''
        ...

    @staticmethod
    def copycast (otherObject: PyGe.Entity3d)-> PyGe.PlanarEnt :
        '''                             '''
        ...
    def getCoefficients (self)-> tuple[float,float,float,float] :
        '''                             '''
        ...
    def getCoordSystem (self)-> tuple[PyGe.Point3d,PyGe.Vector3d,PyGe.Vector3d] :
        '''                             '''
        ...
    def intersectWith (self, other: PyGe.LinearEnt3d, tol: PyGe.Tol=None)-> tuple[bool,PyGe.Point3d] :
        '''                             '''
        ...
    def isCoplanarTo (self, other: PyGe.PlanarEnt, tol: PyGe.Tol=None)-> bool :
        '''                             '''
        ...
    def isParallelTo (self, other: PyGe.LinearEnt3d|PyGe.PlanarEnt, tol: PyGe.Tol=None)-> bool :
        '''                             '''
        ...
    def isPerpendicularTo (self, other: PyGe.LinearEnt3d|PyGe.PlanarEnt, tol: PyGe.Tol=None)-> bool :
        '''                             '''
        ...
    def normal (self)-> PyGe.Vector3d :
        '''                             '''
        ...
    def pointOnPlane (self)-> PyGe.Point3d :
        '''                             '''
        ...

class Plane(PlanarEnt):

    @overload
    def __init__ (self, /)-> None : ...
    @overload
    def __init__ (self, origin: PyGe.Point3d, normal: PyGe.Vector3d)-> None : ...
    @overload
    def __init__ (self, origin: PyGe.Point3d, uAxis: PyGe.Vector3d, vAxis: PyGe.Vector3d)-> None : ...
    @overload
    def __init__ (self, pntU: PyGe.Point3d, origin: PyGe.Point3d, pntV: PyGe.Point3d)-> None : ...
    @overload
    def __init__ (self, a: float, b: float, c: float, d: float)-> None : ...
    def __init__ (self, *args, **kwargs)-> None :
        '''Overloads:
    - None: Any
    - origin: PyGe.Point3d, normal: PyGe.Vector3d
    - origin: PyGe.Point3d, uAxis: PyGe.Vector3d, vAxis: PyGe.Vector3d
    - pntU: PyGe.Point3d, origin: PyGe.Point3d, pntV: PyGe.Point3d
    - a: float, b: float, c: float, d: float
    '''
        ...

    @staticmethod
    def cast (otherObject: PyGe.Entity3d)-> PyGe.Plane :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def copycast (otherObject: PyGe.Entity3d)-> PyGe.Plane :
        '''                             '''
        ...
    def intersectWith (self, val: PyGe.LinearEnt3d | PyGe.Plane | PyGe.BoundedPlane, tol: PyGe.Tol=None)-> tuple[bool,PyGe.Point3d] :
        '''                             '''
        ...

    @overload
    def set (self, origin: PyGe.Point3d, normal: PyGe.Vector3d)-> None : ...
    @overload
    def set (self, origin: PyGe.Point3d, uAxis: PyGe.Vector3d, vAxis: PyGe.Vector3d)-> None : ...
    @overload
    def set (self, pntU: PyGe.Point3d, origin: PyGe.Point3d, pntV: PyGe.Point3d)-> None : ...
    @overload
    def set (self, a: float, b: float, c: float, d: float)-> None : ...
    def set (self, *args, **kwargs)-> None :
        '''Overloads:
    - origin: PyGe.Point3d, normal: PyGe.Vector3d
    - origin: PyGe.Point3d, uAxis: PyGe.Vector3d, vAxis: PyGe.Vector3d
    - pntU: PyGe.Point3d, origin: PyGe.Point3d, pntV: PyGe.Point3d
    - a: float, b: float, c: float, d: float
    '''
        ...
    def signedDistanceTo (self, pt: PyGe.Point3d)-> float :
        '''                             '''
        ...

class Point2d(object):
    def __add__ (self, vec: PyGe.Vector3d)-> PyGe.Point2d :
        '''                             '''
        ...
    def __getitem__ (self, idx: int)-> float :
        '''                             '''
        ...
    def __imul__ (self, val: float)-> PyGe.Point2d :
        '''                             '''
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
    def __isub__ (self, vec: PyGe.Vector3d)-> PyGe.Point2d :
        '''                             '''
        ...
    def __itruediv__ (self, val: float)-> PyGe.Point2d :
        '''                             '''
        ...
    def __mul__ (self, val: float)-> PyGe.Point2d :
        '''                             '''
        ...
    def __setitem__ (self, idx: int, val: float)-> None :
        '''                             '''
        ...
    def __sub__ (self, other: PyGe.Point3d|PyGe.Vector3d)-> PyGe.Point2d :
        '''                             '''
        ...
    def __truediv__ (self, val: float)-> PyGe.Point2d :
        '''                             '''
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
    def mirror (self, pt: PyGe.Line2d)-> PyGe.Point2d :
        '''                             '''
        ...
    def rotateBy (self, val: float, pt: PyGe.Point2d=PyGe.Point2d.kOrgin)-> PyGe.Point2d :
        '''                             '''
        ...
    def scaleBy (self, val: float, pt: PyGe.Point2d=PyGe.Point2d.kOrgin)-> PyGe.Point2d :
        '''                             '''
        ...
    def set (self, xx: float, yy: float)-> PyGe.Point2d :
        '''                             '''
        ...
    def setToProduct (self, mat: PyGe.Matrix2d, pt: PyGe.Point2d)-> PyGe.Point2d :
        '''                             '''
        ...
    def setToSum (self, pt: PyGe.Point2d, vec: PyGe.Vector2d)-> PyGe.Point2d :
        '''                             '''
        ...
    def toList (self)-> list[float,float] :
        '''                             '''
        ...
    def toString (self)-> str :
        '''                             '''
        ...
    def toTuple (self)-> tuple[float,float] :
        '''                             '''
        ...
    def transformBy (self, xform: PyGe.Matrix2d)-> PyGe.Point2d :
        '''                             '''
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
    def toList (self)-> list[float,float,float] :
        '''                             '''
        ...
    def toString (self)-> str :
        '''                             '''
        ...
    def toTuple (self)-> tuple[float,float,float] :
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

class PointContainment(object):
    def kInside (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kOnBoundary (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def kOutside (self, *args, **kwargs)-> None :
        '''None'''
        ...

class PointEnt2d(Entity2d):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...

    @staticmethod
    def cast (otherObject: PyGe.Entity2d)-> PyGe.PointEnt2d :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def copycast (otherObject: PyGe.Entity2d)-> PyGe.PointEnt2d :
        '''                             '''
        ...
    def point2d (self)-> PyGe.Point2d :
        '''                             '''
        ...

class PointEnt3d(Entity3d):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...

    @staticmethod
    def cast (otherObject: PyGe.Entity3d)-> PyGe.PointEnt3d :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def copycast (otherObject: PyGe.Entity3d)-> PyGe.PointEnt3d :
        '''                             '''
        ...
    def point3d (self)-> PyGe.Point3d :
        '''                             '''
        ...

class PointOnCurve2d(PointEnt2d):

    @overload
    def __init__ (self, /)-> None : ...
    @overload
    def __init__ (self, curve: PyGe.Curve2d)-> None : ...
    @overload
    def __init__ (self, curve: PyGe.Curve2d, param: float)-> None : ...
    def __init__ (self, *args, **kwargs)-> None :
        '''Overloads:
    - None: Any
    - curve: PyGe.Curve2d
    - curve: PyGe.Curve2d, param: float
    '''
        ...

    @staticmethod
    def cast (otherObject: PyGe.Entity2d)-> PyGe.PointEnt2d :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def copycast (otherObject: PyGe.Entity2d)-> PyGe.PointOnCurve2d :
        '''                             '''
        ...
    def curve (self)-> PyGe.Curve2d :
        '''                             '''
        ...

    @overload
    def deriv (self, order: int)-> PyGe.Vector2d : ...
    @overload
    def deriv (self, order: int, param: float)-> PyGe.Vector2d : ...
    @overload
    def deriv (self, order: int, curve: PyGe.Curve2d, param: float)-> PyGe.Vector2d : ...
    def deriv (self, *args, **kwargs)-> PyGe.Vector2d :
        '''Overloads:
    - order: int
    - order: int, param: float
    - order: int, curve: PyGe.Curve2d, param: float
    '''
        ...
    def parameter (self)-> float :
        '''                             '''
        ...

    @overload
    def point (self, /)-> PyGe.Point2d : ...
    @overload
    def point (self, param: float)-> PyGe.Point2d : ...
    @overload
    def point (self, curve: PyGe.Curve2d, param: float)-> PyGe.Point2d : ...
    def point (self, *args, **kwargs)-> PyGe.Point2d :
        '''Overloads:
    - None: Any
    - param: float
    - curve: PyGe.Curve2d, param: float
    '''
        ...
    def setCurve (self, val: PyGe.Curve2d)-> None :
        '''                             '''
        ...
    def setParameter (self, val: float)-> None :
        '''                             '''
        ...

class PointOnCurve3d(PointEnt3d):

    @overload
    def __init__ (self, /)-> None : ...
    @overload
    def __init__ (self, curve: PyGe.Curve3d)-> None : ...
    @overload
    def __init__ (self, curve: PyGe.Curve3d, param: float)-> None : ...
    def __init__ (self, *args, **kwargs)-> None :
        '''Overloads:
    - None: Any
    - curve: PyGe.Curve3d
    - curve: PyGe.Curve3d, param: float
    '''
        ...

    @staticmethod
    def cast (otherObject: PyGe.Entity3d)-> PyGe.PointOnCurve3d :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def copycast (otherObject: PyGe.Entity3d)-> PyGe.PointOnCurve3d :
        '''                             '''
        ...
    def curvature (self, param: float=None)-> float :
        '''                             '''
        ...
    def curve (self)-> PyGe.Curve3d :
        '''                             '''
        ...

    @overload
    def deriv (self, order: int)-> PyGe.Vector3d : ...
    @overload
    def deriv (self, order: int, param: float)-> PyGe.Vector3d : ...
    @overload
    def deriv (self, order: int, curve: PyGe.Curve3d, param: float)-> PyGe.Vector3d : ...
    def deriv (self, *args, **kwargs)-> PyGe.Vector3d :
        '''Overloads:
    - order: int
    - order: int, param: float
    - order: int, curve: PyGe.Curve3d, param: float
    '''
        ...
    def isSingular (self)-> bool :
        '''                             '''
        ...
    def parameter (self)-> float :
        '''                             '''
        ...

    @overload
    def point (self, /)-> PyGe.Point3d : ...
    @overload
    def point (self, param: float)-> PyGe.Point3d : ...
    @overload
    def point (self, curve: PyGe.Curve3d, param: float)-> PyGe.Point3d : ...
    def point (self, *args, **kwargs)-> PyGe.Point3d :
        '''Overloads:
    - None: Any
    - param: float
    - curve: PyGe.Curve3d, param: float
    '''
        ...
    def setCurve (self, curve: PyGe.Curve3d)-> None :
        '''                             '''
        ...
    def setParameter (self, param: float)-> None :
        '''                             '''
        ...

class PointOnSurface(PointEnt3d):

    @overload
    def __init__ (self, /)-> None : ...
    @overload
    def __init__ (self, surface: PyGe.Surface)-> None : ...
    @overload
    def __init__ (self, surface: PyGe.Surface, pnt: PyGe.Point2d)-> None : ...
    def __init__ (self, *args, **kwargs)-> None :
        '''Overloads:
    - None: Any
    - surface: PyGe.Surface
    - surface: PyGe.Surface, pnt: PyGe.Point2d
    
    '''
        ...

    @staticmethod
    def cast (otherObject: PyGe.Entity3d)-> PyGe.PointOnSurface :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def copycast (otherObject: PyGe.Entity3d)-> PyGe.PointOnSurface :
        '''                             '''
        ...

    @overload
    def inverseTangentVector (self, vec: PyGe.Vector2d)-> PyGe.Vector2d : ...
    @overload
    def inverseTangentVector (self, vec: PyGe.Vector2d, param: PyGe.Vector2d)-> PyGe.Vector2d : ...
    @overload
    def inverseTangentVector (self, vec: PyGe.Vector2d, surface: PyGe.Surface, param: PyGe.Vector2d)-> PyGe.Vector2d : ...
    def inverseTangentVector (self, *args, **kwargs)-> PyGe.Vector2d :
        '''Overloads:
    - vec: PyGe.Vector2d
    - vec: PyGe.Vector2d, param: PyGe.Vector2d
    - vec: PyGe.Vector2d, surface: PyGe.Surface, param: PyGe.Vector2d
    '''
        ...

    @overload
    def mixedPartial (self, /)-> PyGe.Vector3d : ...
    @overload
    def mixedPartial (self, param: PyGe.Point2d)-> PyGe.Vector3d : ...
    @overload
    def mixedPartial (self, surface: PyGe.Surface, param: PyGe.Point2d)-> PyGe.Vector3d : ...
    def mixedPartial (self, *args, **kwargs)-> PyGe.Vector3d :
        '''Overloads:
    - None: Any
    - param: PyGe.Point2d
    - surface: PyGe.Surface, param: PyGe.Point2d
    '''
        ...

    @overload
    def normal (self, /)-> PyGe.Vector3d : ...
    @overload
    def normal (self, param: PyGe.Point2d)-> PyGe.Vector3d : ...
    @overload
    def normal (self, surface: PyGe.Surface, param: PyGe.Point2d)-> PyGe.Vector3d : ...
    def normal (self, *args, **kwargs)-> PyGe.Vector3d :
        '''Overloads:
    - None: Any
    - param: PyGe.Point2d
    - surface: PyGe.Surface, param: PyGe.Point2d
    '''
        ...
    def parameter (self)-> PyGe.Point2d :
        '''                             '''
        ...

    @overload
    def point (self, /)-> PyGe.Point3d : ...
    @overload
    def point (self, param: PyGe.Point2d)-> PyGe.Point3d : ...
    @overload
    def point (self, surface: PyGe.Surface, param: PyGe.Point2d)-> PyGe.Point3d : ...
    def point (self, *args, **kwargs)-> PyGe.Point3d :
        '''Overloads:
    - None: Any
    - param: PyGe.Point2d
    - surface: PyGe.Surface, param: PyGe.Point2d
    '''
        ...
    def setParameter (self, param: PyGe.Point2d)-> None :
        '''                             '''
        ...
    def setSurface (self, val: PyGe.Surface)-> None :
        '''                             '''
        ...
    def surface (self)-> PyGe.Surface :
        '''                             '''
        ...

    @overload
    def tangentVector (self, vec: PyGe.Vector2d)-> PyGe.Vector3d : ...
    @overload
    def tangentVector (self, vec: PyGe.Vector2d, param: PyGe.Vector2d)-> PyGe.Vector3d : ...
    @overload
    def tangentVector (self, vec: PyGe.Vector2d, surface: PyGe.Surface, param: PyGe.Vector2d)-> PyGe.Vector3d : ...
    def tangentVector (self, *args, **kwargs)-> PyGe.Vector3d :
        '''Overloads:
    - vec: PyGe.Vector2d
    - vec: PyGe.Vector2d, param: PyGe.Vector2d
    - vec: PyGe.Vector2d, surface: PyGe.Surface, param: PyGe.Vector2d
    '''
        ...

    @overload
    def uDeriv (self, order: int)-> PyGe.Vector3d : ...
    @overload
    def uDeriv (self, order: int, param: PyGe.Point2d)-> PyGe.Vector3d : ...
    @overload
    def uDeriv (self, order: int, surface: PyGe.Surface, param: PyGe.Point2d)-> PyGe.Vector3d : ...
    def uDeriv (self, *args, **kwargs)-> PyGe.Vector3d :
        '''Overloads:
    - order: int
    - order: int, param: PyGe.Point2d
    - order: int, surface: PyGe.Surface, param: PyGe.Point2d
    '''
        ...

    @overload
    def vDeriv (self, order: int)-> PyGe.Vector3d : ...
    @overload
    def vDeriv (self, order: int, param: PyGe.Point2d)-> PyGe.Vector3d : ...
    @overload
    def vDeriv (self, order: int, surface: PyGe.Surface, param: PyGe.Point2d)-> PyGe.Vector3d : ...
    def vDeriv (self, *args, **kwargs)-> PyGe.Vector3d :
        '''Overloads:
    - order: int
    - order: int, param: PyGe.Point2d
    - order: int, surface: PyGe.Surface, param: PyGe.Point2d
    '''
        ...

class Polyline2d(SplineEnt2d):

    @overload
    def __init__ (self, /)-> None : ...
    @overload
    def __init__ (self, points: list[PyGe.Point2d])-> None : ...
    @overload
    def __init__ (self, knots: PyGe.KnotVector, points: list[PyGe.Point2d])-> None : ...
    @overload
    def __init__ (self, crv: PyGe.Curve2d, apprEps: float)-> None : ...
    def __init__ (self, *args, **kwargs)-> None :
        '''Overloads:
    - None: Any
    - points: list[PyGe.Point2d]
    - knots: PyGe.KnotVector, points: list[PyGe.Point2d]- crv: PyGe.Curve2d, apprEps: float'''
        ...

    @staticmethod
    def cast (otherObject: PyGe.Entity2d)-> PyDb.Polyline2d :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def copycast (otherObject: PyGe.Entity2d)-> PyDb.Polyline2d :
        '''                             '''
        ...
    def fitPointAt (self, idx: int)-> PyGe.Point2d :
        '''                             '''
        ...
    def numFitPoints (self)-> int :
        '''                             '''
        ...
    def setFitPointAt (self, idx: int, pt: PyGe.Point2d)-> None :
        '''                             '''
        ...

class Polyline3d(SplineEnt3d):

    @overload
    def __init__ (self, /)-> None : ...
    @overload
    def __init__ (self, points: list[PyGe.Point3d])-> None : ...
    @overload
    def __init__ (self, knots: PyGe.KnotVector, points: list[PyGe.Point3d])-> None : ...
    @overload
    def __init__ (self, crv: PyGe.Curve3d, apprEps: float)-> None : ...
    def __init__ (self, *args, **kwargs)-> None :
        '''Overloads:
    - None: Any
    - points: list[PyGe.Point3d]
    - knots: PyGe.KnotVector, points: list[PyGe.Point3d]- crv: PyGe.Curve3d, apprEps: float'''
        ...

    @staticmethod
    def cast (otherObject: PyGe.Entity3d)-> PyDb.Polyline3d :
        '''                             '''
        ...

    @staticmethod
    def className (otherObject: PyGe.Entity3d)-> str :
        '''                             '''
        ...

    @staticmethod
    def copycast (otherObject: PyGe.Entity3d)-> PyDb.Polyline3d :
        '''                             '''
        ...
    def fitPointAt (self, idx: int)-> PyGe.Point3d :
        '''                             '''
        ...
    def numFitPoints (self)-> int :
        '''                             '''
        ...
    def setFitPointAt (self, idx: int, pt: PyGe.Point3d)-> None :
        '''                             '''
        ...

class Position2d(PointEnt2d):

    @overload
    def __init__ (self, /)-> None : ...
    @overload
    def __init__ (self, pnt: PyGe.Point2d)-> None : ...
    @overload
    def __init__ (self, x: float, y: float)-> None : ...
    def __init__ (self, *args, **kwargs)-> None :
        '''Overloads:
    - None: Any
    - pnt: PyGe.Point2d
    - x: float, y: float
    '''
        ...

    @staticmethod
    def cast (otherObject: PyGe.Entity2d)-> PyGe.Position2d :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def copycast (otherObject: PyGe.Entity2d)-> PyGe.Position2d :
        '''                             '''
        ...

    @overload
    def set (self, pnt: PyGe.Point2d)-> None : ...
    @overload
    def set (self, x: float, y: float)-> None : ...
    def set (self, *args, **kwargs)-> None :
        '''Overloads:
    - pnt: PyGe.Point2d
    - x: float, y: float
    '''
        ...

class Position3d(PointEnt3d):

    @overload
    def __init__ (self, /)-> None : ...
    @overload
    def __init__ (self, pnt: PyGe.Point3d)-> None : ...
    @overload
    def __init__ (self, x: float, y: float, z: float)-> None : ...
    def __init__ (self, *args, **kwargs)-> None :
        '''Overloads:
    - None: Any
    - pnt: PyGe.Point3d
    - x: float, y: float, z: float
    '''
        ...

    @staticmethod
    def cast (otherObject: PyGe.Entity3d)-> PyGe.Position3d :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def copycast (otherObject: PyGe.Entity3d)-> PyGe.Position3d :
        '''                             '''
        ...

    @overload
    def set (self, pnt: PyGe.Point3d)-> None : ...
    @overload
    def set (self, x: float, y: float, z: float)-> None : ...
    def set (self, *args, **kwargs)-> None :
        '''Overloads:
    - pnt: PyGe.Point3d
    - x: float, y: float, z: float
    '''
        ...

class Ray2d(LinearEnt2d):

    @overload
    def __init__ (self, /)-> None : ...
    @overload
    def __init__ (self, start: PyGe.Point3d, direction: PyGe.Vector2d)-> None : ...
    @overload
    def __init__ (self, start: PyGe.Point3d, end: PyGe.Point3d)-> None : ...
    def __init__ (self, *args, **kwargs)-> None :
        '''Overloads:
    - None: Any
    - start: PyGe.Point3d, direction: PyGe.Vector2d
    - start: PyGe.Point3d, end: PyGe.Point3d
    '''
        ...

    @staticmethod
    def cast (otherObject: PyGe.Entity2d)-> PyGe.Ray2d :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def copycast (otherObject: PyGe.Entity2d)-> PyGe.Ray2d :
        '''                             '''
        ...

    @overload
    def set (self, start: PyGe.Point3d, direction: PyGe.Vector2d)-> None : ...
    @overload
    def set (self, start: PyGe.Point3d, end: PyGe.Point3d)-> None : ...
    def set (self, *args, **kwargs)-> None :
        '''Overloads:
    - start: PyGe.Point3d, direction: PyGe.Vector2d
    - start: PyGe.Point3d, end: PyGe.Point3d
    '''
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

    @staticmethod
    def cast (otherObject: PyGe.Entity3d)-> PyGe.Ray3d :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def copycast (otherObject: PyGe.Entity3d)-> PyGe.Ray3d :
        '''                             '''
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
    def __getitem__ (self, idx: int)-> float :
        '''                             '''
        ...
    def __imul__ (self, val: float)-> PyGe.Scale3d :
        '''                             '''
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
    def __mul__ (self, val: float)-> PyGe.Scale3d :
        '''                             '''
        ...
    def __setitem__ (self, idx: int, val: float)-> None :
        '''                             '''
        ...
    def postMultBy (self, vec: PyGe.Vector3d)-> PyGe.Scale3d :
        '''                             '''
        ...
    def preMultBy (self, vec: PyGe.Vector3d)-> PyGe.Scale3d :
        '''                             '''
        ...

    @overload
    def setToProduct (self, sc: PyGe.Scale3d, s: float)-> PyGe.Scale3d : ...
    @overload
    def setToProduct (self, sc1: PyGe.Scale3d, sc2: PyGe.Scale3d)-> PyGe.Scale3d : ...
    def setToProduct (self, *args, **kwargs)-> PyGe.Scale3d :
        '''Overloads:
    - sc: PyGe.Scale3d, s: float
    - sc1: PyGe.Scale3d, sc2: PyGe.Scale3d
    '''
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
    def toString (self)-> str :
        '''                             '''
        ...

class Sphere(Surface):

    @overload
    def __init__ (self, /)-> None : ...
    @overload
    def __init__ (self, radius: float, center: PyGe.Point3d)-> None : ...
    @overload
    def __init__ (self, radius: float, center: PyGe.Point3d, northAxis: PyGe.Vector3d, refAxis: PyGe.Vector3d, startAngleU: float, endAngleU: float, startAngleV: float, endAngleV: float)-> None : ...
    def __init__ (self, *args, **kwargs)-> None :
        '''Overloads:
    - None: Any
    - radius: float, center: PyGe.Point3d
    - radius: float, center: PyGe.Point3d, northAxis: PyGe.Vector3d, refAxis: PyGe.Vector3d, startAngleU: float, endAngleU: float, startAngleV: float, endAngleV: float
    '''
        ...

    @staticmethod
    def cast (otherObject: PyGe.Entity3d)-> PyGe.Sphere :
        '''                             '''
        ...
    def center (self)-> PyGe.Point3d :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def copycast (otherObject: PyGe.Entity3d)-> PyGe.Sphere :
        '''                             '''
        ...
    def getAnglesInU (self)-> tuple[float,float] :
        '''                             '''
        ...
    def getAnglesInV (self)-> tuple[float,float] :
        '''                             '''
        ...
    def intersectWith (self, val: PyGe.LinearEnt3d, tol: PyGe.Tol=None)-> tuple[int,PyGe.Point3d,PyGe.Point3d] :
        '''                             '''
        ...
    def isClosed (self, tol: PyGe.Tol=None)-> bool :
        '''                             '''
        ...
    def isOuterNormal (self)-> bool :
        '''                             '''
        ...
    def northAxis (self)-> PyGe.Vector3d :
        '''                             '''
        ...
    def northPole (self)-> PyGe.Point3d :
        '''                             '''
        ...
    def radius (self)-> float :
        '''                             '''
        ...
    def refAxis (self)-> PyGe.Vector3d :
        '''                             '''
        ...

    @overload
    def set (self, radius: float, center: PyGe.Point3d)-> None : ...
    @overload
    def set (self, radius: float, center: PyGe.Point3d, northAxis: PyGe.Vector3d, refAxis: PyGe.Vector3d, startAngleU: float, endAngleU: float, startAngleV: float, endAngleV: float)-> None : ...
    def set (self, *args, **kwargs)-> None :
        '''Overloads:
    - radius: float, center: PyGe.Point3d
    - radius: float, center: PyGe.Point3d, northAxis: PyGe.Vector3d, refAxis: PyGe.Vector3d, startAngleU: float, endAngleU: float, startAngleV: float, endAngleV: float
    '''
        ...
    def setAnglesInU (self, start: float, end: float)-> None :
        '''                             '''
        ...
    def setAnglesInV (self, start: float, end: float)-> None :
        '''                             '''
        ...
    def setRadius (self, val: float)-> None :
        '''                             '''
        ...
    def southPole (self)-> PyGe.Point3d :
        '''                             '''
        ...

class SplineEnt2d(Curve2d):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...

    @staticmethod
    def cast (otherObject: PyGe.Entity2d)-> PyGe.SplineEnt2d :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def continuityAtKnot (self, idx: int, tol: PyGe.Tol=None)-> int :
        '''                             '''
        ...
    def controlPointAt (self, idx: int)-> PyGe.Point2d :
        '''                             '''
        ...

    @staticmethod
    def copycast (otherObject: PyGe.Entity2d)-> PyGe.SplineEnt2d :
        '''                             '''
        ...
    def degree (self)-> int :
        '''                             '''
        ...
    def endParam (self)-> float :
        '''                             '''
        ...
    def endPoint (self)-> PyGe.Point2d :
        '''                             '''
        ...
    def hasFitData (self)-> bool :
        '''                             '''
        ...
    def isRational (self)-> bool :
        '''                             '''
        ...
    def knotAt (self, idx: int)-> float :
        '''                             '''
        ...
    def knots (self)-> PyGe.KnotVector :
        '''                             '''
        ...
    def numControlPoints (self)-> int :
        '''                             '''
        ...
    def numKnots (self)-> int :
        '''                             '''
        ...
    def order (self)-> int :
        '''                             '''
        ...
    def setControlPointAt (self, idx: int, val: PyGe.Point2d)-> None :
        '''                             '''
        ...
    def setKnotAt (self, idx: int, val: float)-> None :
        '''                             '''
        ...
    def startParam (self)-> float :
        '''                             '''
        ...
    def startPoint (self)-> PyGe.Point2d :
        '''                             '''
        ...

class SplineEnt3d(Curve3d):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...

    @staticmethod
    def cast (otherObject: PyGe.Entity3d)-> PyGe.SplineEnt3d :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def continuityAtKnot (self, idx: int, tol: PyGe.Tol=None)-> int :
        '''                             '''
        ...
    def controlPointAt (self, idx: int)-> PyGe.Point3d :
        '''                             '''
        ...

    @staticmethod
    def copycast (otherObject: PyGe.Entity3d)-> PyGe.SplineEnt3d :
        '''                             '''
        ...
    def degree (self)-> int :
        '''                             '''
        ...
    def endParam (self)-> float :
        '''                             '''
        ...
    def endPoint (self)-> PyGe.Point3d :
        '''                             '''
        ...
    def hasFitData (self)-> bool :
        '''                             '''
        ...
    def isRational (self)-> bool :
        '''                             '''
        ...
    def knotAt (self, idx: int)-> float :
        '''                             '''
        ...
    def knots (self)-> PyGe.KnotVector :
        '''                             '''
        ...
    def numControlPoints (self)-> int :
        '''                             '''
        ...
    def numKnots (self)-> int :
        '''                             '''
        ...
    def order (self)-> int :
        '''                             '''
        ...
    def setControlPointAt (self, idx: int, val: PyGe.Point3d)-> None :
        '''                             '''
        ...
    def setKnotAt (self, idx: int, val: float)-> None :
        '''                             '''
        ...
    def startParam (self)-> float :
        '''                             '''
        ...
    def startPoint (self)-> PyGe.Point3d :
        '''                             '''
        ...

class SurfSurfInt(Entity3d):

    @overload
    def __init__ (self, /)-> None : ...
    @overload
    def __init__ (self, srf1: PyGe.Surface, srf2: PyGe.Surface)-> None : ...
    @overload
    def __init__ (self, srf1: PyGe.Surface, srf2: PyGe.Surface, tol: PyGe.Tol)-> None : ...
    def __init__ (self, *args, **kwargs)-> None :
        '''Overloads:
    - None: Any
    - srf1: PyGe.Surface, srf2: PyGe.Surface
    - srf1: PyGe.Surface, srf2: PyGe.Surface, tol: PyGe.Tol
    '''
        ...

    @staticmethod
    def cast (otherObject: PyGe.Entity3d)-> PyGe.SurfSurfInt :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def copycast (otherObject: PyGe.Entity3d)-> PyGe.SurfSurfInt :
        '''                             '''
        ...
    def getDimension (self, intNum: int)-> int :
        '''                             '''
        ...
    def getIntConfigs (self, intNum: int)-> tuple :
        '''                             '''
        ...
    def getIntPointParams (self, intNum: int)-> tuple[PyGe.Point2d,PyGe.Point2d] :
        '''                             '''
        ...
    def getType (self, intNum: int)-> int :
        '''                             '''
        ...
    def intCurve (self, intNum: int, isExternal: bool)-> PyGe.Curve3d :
        '''                             '''
        ...
    def intParamCurve (self, intNum: int, isExternal: bool, isFirst: bool)-> PyGe.Curve2d :
        '''                             '''
        ...
    def intPoint (self, intNum: int)-> PyGe.Point3d :
        '''                             '''
        ...
    def numResults (self)-> int :
        '''                             '''
        ...
    def set (self, srf1: PyGe.Surface, srf2: PyGe.Surface, tol: PyGe.Tol=None)-> None :
        '''                             '''
        ...
    def surface1 (self)-> PyGe.Surface :
        '''                             '''
        ...
    def surface2 (self)-> PyGe.Surface :
        '''                             '''
        ...
    def tolerance (self)-> PyGe.Tol :
        '''                             '''
        ...

class Surface(Entity3d):
    def __init__ (self, *args, **kwargs)-> None :
        '''Raises an exception
This class cannot be instantiated from Python'''
        ...

    @staticmethod
    def cast (otherObject: PyGe.Entity3d)-> PyGe.Surface :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...
    def closestPointTo (self, pt: PyGe.Point3d, tol: PyGe.Tol=None)-> PyGe.Point3d :
        '''                             '''
        ...

    @staticmethod
    def copycast (otherObject: PyGe.Entity3d)-> PyGe.Surface :
        '''                             '''
        ...
    def distanceTo (self, pt: PyGe.Point3d, tol: PyGe.Tol=None)-> float :
        '''                             '''
        ...

    @overload
    def evalPoint (self, param: PyGe.Point2d)-> PyGe.Point3d : ...
    @overload
    def evalPoint (self, param: PyGe.Point3d, derivOrd: int, vecs: list[PyGe.Vector3d])-> PyGe.Point3d : ...
    @overload
    def evalPoint (self, param: PyGe.Point3d, derivOrd: int, vecs: list[PyGe.Vector3d], normal: PyGe.Vector3d)-> PyGe.Point3d : ...
    def evalPoint (self, *args, **kwargs)-> PyGe.Point3d :
        '''Overloads:
    - param: PyGe.Point2d
    - param: PyGe.Point3d, derivOrd: int, vecs: list[PyGe.Vector3d]
    - param: PyGe.Point3d, derivOrd: int, vecs: list[PyGe.Vector3d], normal: PyGe.Vector3d
    '''
        ...
    def isClosedInU (self, tol: PyGe.Tol=None)-> bool :
        '''                             '''
        ...
    def isClosedInV (self, tol: PyGe.Tol=None)-> bool :
        '''                             '''
        ...
    def isNormalReversed (self)-> bool :
        '''                             '''
        ...

    @overload
    def isOn (self, pnt: PyGe.Point3d)-> bool : ...
    @overload
    def isOn (self, pnt: PyGe.Point3d, tol: PyGe.Tol = None)-> bool : ...
    @overload
    def isOn (self, pnt: PyGe.Point3d, paramPoint: PyGe.Point2d)-> bool : ...
    @overload
    def isOn (self, pnt: PyGe.Point3d, paramPoint: PyGe.Point2d, tol: PyGe.Tol = None)-> bool : ...
    def isOn (self, *args, **kwargs)-> bool :
        '''Overloads:
    - pnt: PyGe.Point3d
    - pnt: PyGe.Point3d, tol: PyGe.Tol = None
    - pnt: PyGe.Point3d, paramPoint: PyGe.Point2d
    - pnt: PyGe.Point3d, paramPoint: PyGe.Point2d, tol: PyGe.Tol = None
    '''
        ...
    def paramOf (self, pt: PyGe.Point3d, tol: PyGe.Tol=None)-> PyGe.Point2d :
        '''                             '''
        ...
    def reverseNormal (self)-> None :
        '''                             '''
        ...

class Tol(object):
    def __init__ (self)-> None :
        '''                             '''
        ...

    @staticmethod
    def current ()-> PyGe.Tol :
        '''                             '''
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

    @staticmethod
    def setGlobalTol (val: PyGe.Tol)-> None :
        '''                             '''
        ...

class Torus(Surface):
    def __init__ (self)-> None :
        '''                             '''
        ...

    @staticmethod
    def cast (otherObject: PyGe.Entity3d)-> PyGe.Torus :
        '''                             '''
        ...

    @staticmethod
    def className ()-> str :
        '''                             '''
        ...

    @staticmethod
    def copycast (otherObject: PyGe.Entity3d)-> PyGe.Torus :
        '''                             '''
        ...

class Vector2d(object):
    def __add__ (self, vec: PyGe.Vector2d)-> PyGe.Vector2d :
        '''                             '''
        ...
    def __getitem__ (self, idx: int)-> float :
        '''                             '''
        ...
    def __imul__ (self, val: float)-> PyGe.Vector2d :
        '''                             '''
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
    def __isub__ (self, vec: PyGe.Vector2d)-> PyGe.Vector2d :
        '''                             '''
        ...
    def __itruediv__ (self, val: float)-> PyGe.Vector2d :
        '''                             '''
        ...
    def __mul__ (self, val: float)-> PyGe.Vector2d :
        '''                             '''
        ...

    @overload
    def __rmul__ (self, val: float)-> PyGe.Vector2d : ...
    @overload
    def __rmul__ (self, xform: PyGe.Matrix2d)-> PyGe.Vector2d : ...
    def __rmul__ (self, *args, **kwargs)-> PyGe.Vector2d :
        '''Overloads:
    - val: float
    - xform: PyGe.Matrix2d
    '''
        ...
    def __setitem__ (self, idx: int, val: float)-> None :
        '''                             '''
        ...
    def __sub__ (self, vec: PyGe.Vector2d=None)-> PyGe.Vector2d :
        '''                             '''
        ...
    def __truediv__ (self, val: float)-> PyGe.Vector2d :
        '''                             '''
        ...
    def angle (self)-> float :
        '''                             '''
        ...
    def angleTo (self, vec: PyGe.Vector2d)-> float :
        '''                             '''
        ...
    def dotProduct (self, vec: PyGe.Vector2d)-> float :
        '''                             '''
        ...
    def isCodirectionalTo (self, vec: PyGe.Vector2d, tol: PyGe.Tol=None)-> bool :
        '''                             '''
        ...
    def isEqualTo (self, vec: PyGe.Vector3d, tol: PyGe.Tol=None)-> bool :
        '''                             '''
        ...
    def isParallelTo (self, vec: PyGe.Vector2d, tol: PyGe.Tol=None)-> bool :
        '''                             '''
        ...
    def isPerpendicularTo (self, vec: PyGe.Vector2d, tol: PyGe.Tol=None)-> bool :
        '''                             '''
        ...
    def isUnitLength (self, tol: PyGe.Tol=None)-> bool :
        '''                             '''
        ...
    def isZeroLength (self, tol: PyGe.Tol=None)-> bool :
        '''                             '''
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
    def mirror (self, vec: PyGe.Vector2d)-> PyGe.Vector2d :
        '''                             '''
        ...
    def negate (self)-> PyGe.Vector2d :
        '''                             '''
        ...
    def normal (self, tol: PyGe.Tol=None)-> PyGe.Vector2d :
        '''                             '''
        ...
    def normalize (self, tol: PyGe.Tol=None)-> PyGe.Vector2d :
        '''                             '''
        ...
    def rotateBy (self, val: float)-> PyGe.Vector2d :
        '''                             '''
        ...
    def set (self, xx: float, yy: float)-> PyGe.Vector2d :
        '''                             '''
        ...

    @overload
    def setToProduct (self, vec: PyGe.Vector2d, s: float)-> PyGe.Vector2d : ...
    @overload
    def setToProduct (self, xform: PyGe.Matrix2d, vec: PyGe.Vector3d)-> PyGe.Vector2d : ...
    def setToProduct (self, *args, **kwargs)-> PyGe.Vector2d :
        '''Overloads:
    - vec: PyGe.Vector2d, s: float
    - xform: PyGe.Matrix2d, vec: PyGe.Vector3d
    '''
        ...
    def setToSum (self, v1: PyGe.Vector2d, v2: PyGe.Vector2d)-> PyGe.Vector2d :
        '''                             '''
        ...
    def toList (self)-> list[float,float] :
        '''                             '''
        ...
    def toString (self)-> str :
        '''                             '''
        ...
    def toTuple (self)-> tuple[float,float] :
        '''                             '''
        ...
    def transformBy (self, xform: PyGe.Matrix2d)-> PyGe.Vector2d :
        '''                             '''
        ...
    def x (self, *args, **kwargs)-> None :
        '''None'''
        ...
    def y (self, *args, **kwargs)-> None :
        '''None'''
        ...

class Vector3d(object):
    def __add__ (self, vec: PyGe.Vector3d)-> PyGe.Vector3d :
        '''                             '''
        ...
    def __getitem__ (self, idx: int)-> float :
        '''                             '''
        ...
    def __imul__ (self, val: float)-> PyGe.Vector3d :
        '''                             '''
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
    def __isub__ (self, vec: PyGe.Vector3d)-> PyGe.Vector3d :
        '''                             '''
        ...
    def __itruediv__ (self, val: float)-> PyGe.Vector3d :
        '''                             '''
        ...
    def __mul__ (self, val: float)-> PyGe.Vector3d :
        '''                             '''
        ...
    def __rmul__ (self, val:  float|PyGe.Matrix3d)-> PyGe.Vector3d :
        '''                             '''
        ...
    def __setitem__ (self, idx: int, val: float)-> None :
        '''                             '''
        ...
    def __sub__ (self, vec: PyGe.Vector3d)-> PyGe.Vector3d :
        '''                             '''
        ...
    def __truediv__ (self, val: float)-> PyGe.Vector3d :
        '''                             '''
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
    def setToProduct (self, vec: PyGe.Vector3d, s: float)-> PyGe.Vector3d : ...
    @overload
    def setToProduct (self, xform: PyGe.Matrix3d, vec: PyGe.Vector3d)-> PyGe.Vector3d : ...
    def setToProduct (self, *args, **kwargs)-> PyGe.Vector3d :
        '''Overloads:
    - vec: PyGe.Vector3d, s: float
    - xform: PyGe.Matrix3d, vec: PyGe.Vector3d
    '''
        ...
    def setToSum (self, v1: PyGe.Vector3d, v2: PyGe.Vector3d)-> PyGe.Vector3d :
        '''Sets this vector to the sum of the vector v1 and vector v2. Returns the reference to this vector.'''
        ...
    def toList (self)-> list[float,float,float] :
        '''                             '''
        ...
    def toString (self)-> str :
        '''                             '''
        ...
    def toTuple (self)-> tuple[float,float,float] :
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
