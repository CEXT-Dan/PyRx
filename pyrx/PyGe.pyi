from __future__ import annotations

from typing import Any, ClassVar, Collection, Self, overload

from pyrx import Ge as PyGe
from pyrx.doc_utils.boost_meta import _BoostPythonEnum

Helix: EntityId  # 80
k0Arg1: AcGeError  # 2
k0Arg2: AcGeError  # 3
k0This: AcGeError  # 1
kAcisEntity: ExternalEntityKind  # 0
kArg1InsideThis: AcGeError  # 11
kArg1OnThis: AcGeError  # 10
kArg1TooBig: AcGeError  # 9
kAugPolyline2d: EntityId  # 35
kAugPolyline3d: EntityId  # 41
kBezierCurve3d: EntityId  # 66
kBoundBlock2d: EntityId  # 61
kBoundBlock3d: EntityId  # 62
kBoundedPlane: EntityId  # 9
kChamfer: OffsetCrvExtType  # 1
kChord: KnotParameterization  # 0
kCircArc2d: EntityId  # 10
kCircArc3d: EntityId  # 11
kClipBoundary2d: EntityId  # 76
kCompositeCrv2d: EntityId  # 46
kCompositeCrv3d: EntityId  # 47
kCone: EntityId  # 32
kConic2d: EntityId  # 12
kConic3d: EntityId  # 13
kCubicSplineCurve2d: EntityId  # 38
kCubicSplineCurve3d: EntityId  # 44
kCurve2d: EntityId  # 14
kCurve3d: EntityId  # 15
kCurveBoundedSurface: EntityId  # 53
kCurveCurveInt2d: EntityId  # 59
kCurveCurveInt3d: EntityId  # 60
kCurveSampleData: EntityId  # 72
kCurveSurfaceInt: EntityId  # 78
kCustomParameterization: KnotParameterization  # 15
kCylinder: EntityId  # 30
kDSpline2d: EntityId  # 37
kDSpline3d: EntityId  # 43
kEllipArc2d: EntityId  # 16
kEllipArc3d: EntityId  # 17
kEllipCone: EntityId  # 73
kEllipCylinder: EntityId  # 74
kEntity2d: EntityId  # 0
kEntity3d: EntityId  # 1
kEnvelope2d: EntityId  # 52
kEqualArg1Arg2: AcGeError  # 5
kEqualArg1Arg3: AcGeError  # 6
kEqualArg2Arg3: AcGeError  # 7
kExtend: OffsetCrvExtType  # 2
kExternalBoundedSurface: EntityId  # 58
kExternalCurve2d: EntityId  # 55
kExternalCurve3d: EntityId  # 54
kExternalEntityUndefined: ExternalEntityKind  # 1
kExternalObject: EntityId  # 77
kExternalSurface: EntityId  # 48
kFillet: OffsetCrvExtType  # 0
kFitData3d: EntityId  # 68
kHatch: EntityId  # 69
kInside: PointContainment  # 0
kIntervalBoundBlock: EntityId  # 75
kLeftLeft: AcGeXConfig  # 16
kLeftOverlap: AcGeXConfig  # 256
kLeftRight: AcGeXConfig  # 4
kLine2d: EntityId  # 18
kLine3d: EntityId  # 19
kLineSeg2d: EntityId  # 22
kLineSeg3d: EntityId  # 23
kLinearEnt2d: EntityId  # 20
kLinearEnt3d: EntityId  # 21
kLinearlyDependentArg1Arg2Arg3: AcGeError  # 8
kNotDefined: AcGeXConfig  # 1
kNotDefinedKnotParam: KnotParameterization  # 16
kNurbCurve2d: EntityId  # 36
kNurbCurve3d: EntityId  # 42
kNurbSurface: EntityId  # 49
kObject: EntityId  # 67
kOffsetCurve2d: EntityId  # 63
kOffsetCurve3d: EntityId  # 64
kOffsetSurface: EntityId  # 51
kOk: AcGeError  # 0
kOnBoundary: PointContainment  # 2
kOutside: PointContainment  # 1
kOverlapEnd: AcGeXConfig  # 8192
kOverlapLeft: AcGeXConfig  # 512
kOverlapOverlap: AcGeXConfig  # 16384
kOverlapRight: AcGeXConfig  # 2048
kOverlapStart: AcGeXConfig  # 4096
kPerpendicularArg1Arg2: AcGeError  # 4
kPlanarEnt: EntityId  # 24
kPlane: EntityId  # 25
kPointEnt2d: EntityId  # 2
kPointEnt3d: EntityId  # 3
kPointLeft: AcGeXConfig  # 64
kPointOnCurve2d: EntityId  # 6
kPointOnCurve3d: EntityId  # 7
kPointOnSurface: EntityId  # 8
kPointRight: AcGeXConfig  # 128
kPolyline2d: EntityId  # 34
kPolyline3d: EntityId  # 40
kPolynomCurve3d: EntityId  # 65
kPosition2d: EntityId  # 4
kPosition3d: EntityId  # 5
kRay2d: EntityId  # 26
kRay3d: EntityId  # 27
kRightLeft: AcGeXConfig  # 8
kRightOverlap: AcGeXConfig  # 1024
kRightRight: AcGeXConfig  # 32
kSSIAntiTangent: AcGeSSIType  # 2
kSSICoincident: AcGeSSIConfig  # 3
kSSIIn: AcGeSSIConfig  # 2
kSSIOut: AcGeSSIConfig  # 1
kSSITangent: AcGeSSIType  # 1
kSSITransverse: AcGeSSIType  # 0
kSSIUnknown: AcGeSSIConfig  # 0
kSphere: EntityId  # 29
kSplineEnt2d: EntityId  # 33
kSplineEnt3d: EntityId  # 39
kSqrtChord: KnotParameterization  # 1
kSurface: EntityId  # 28
kSurfaceCurve2dTo3d: EntityId  # 56
kSurfaceCurve3dTo2d: EntityId  # 57
kSurfaceSurfaceInt: EntityId  # 79
kTorus: EntityId  # 31
kTrimmedCrv2d: EntityId  # 45
kTrimmedCurve2d: EntityId  # 70
kTrimmedCurve3d: EntityId  # 71
kTrimmedSurface: EntityId  # 50
kUniform: KnotParameterization  # 2
kUnknown: AcGeXConfig  # 2
kXCoincident: AcGeCSIConfig  # 5
kXCoincidentUnbounded: AcGeCSIConfig  # 6
kXIn: AcGeCSIConfig  # 2
kXOut: AcGeCSIConfig  # 1
kXTanIn: AcGeCSIConfig  # 4
kXTanOut: AcGeCSIConfig  # 3
kXUnknown: AcGeCSIConfig  # 0

class AcGeCSIConfig(_BoostPythonEnum):
    kXUnknown: ClassVar[Self]  # 0
    kXOut: ClassVar[Self]  # 1
    kXIn: ClassVar[Self]  # 2
    kXTanOut: ClassVar[Self]  # 3
    kXTanIn: ClassVar[Self]  # 4
    kXCoincident: ClassVar[Self]  # 5
    kXCoincidentUnbounded: ClassVar[Self]  # 6

class AcGeError(_BoostPythonEnum):
    kOk: ClassVar[Self]  # 0
    k0This: ClassVar[Self]  # 1
    k0Arg1: ClassVar[Self]  # 2
    k0Arg2: ClassVar[Self]  # 3
    kPerpendicularArg1Arg2: ClassVar[Self]  # 4
    kEqualArg1Arg2: ClassVar[Self]  # 5
    kEqualArg1Arg3: ClassVar[Self]  # 6
    kEqualArg2Arg3: ClassVar[Self]  # 7
    kLinearlyDependentArg1Arg2Arg3: ClassVar[Self]  # 8
    kArg1TooBig: ClassVar[Self]  # 9
    kArg1OnThis: ClassVar[Self]  # 10
    kArg1InsideThis: ClassVar[Self]  # 11

class AcGeSSIConfig(_BoostPythonEnum):
    kSSIUnknown: ClassVar[Self]  # 0
    kSSIOut: ClassVar[Self]  # 1
    kSSIIn: ClassVar[Self]  # 2
    kSSICoincident: ClassVar[Self]  # 3

class AcGeSSIType(_BoostPythonEnum):
    kSSITransverse: ClassVar[Self]  # 0
    kSSITangent: ClassVar[Self]  # 1
    kSSIAntiTangent: ClassVar[Self]  # 2

class AcGeXConfig(_BoostPythonEnum):
    kNotDefined: ClassVar[Self]  # 1
    kUnknown: ClassVar[Self]  # 2
    kLeftRight: ClassVar[Self]  # 4
    kRightLeft: ClassVar[Self]  # 8
    kLeftLeft: ClassVar[Self]  # 16
    kRightRight: ClassVar[Self]  # 32
    kPointLeft: ClassVar[Self]  # 64
    kPointRight: ClassVar[Self]  # 128
    kLeftOverlap: ClassVar[Self]  # 256
    kOverlapLeft: ClassVar[Self]  # 512
    kRightOverlap: ClassVar[Self]  # 1024
    kOverlapRight: ClassVar[Self]  # 2048
    kOverlapStart: ClassVar[Self]  # 4096
    kOverlapEnd: ClassVar[Self]  # 8192
    kOverlapOverlap: ClassVar[Self]  # 16384

class AutoTol:
    def __init__(self, /) -> None: ...
    def __reduce__(self, /) -> Any: ...
    def equalPoint(self, /) -> float: ...
    def equalVector(self, /) -> float: ...
    def setEqualPoint(self, val: float, /) -> None: ...
    def setEqualVector(self, val: float, /) -> None: ...

class BoundBlock2d(PyGe.Entity2d):
    @overload
    def __init__(self, /) -> None:
        """
        This class provides a two-dimensional bounding volume implementation. Bounding blocks may
        exist in two forms: as an ordinary coordinate-aligned bounding box and as a parallelogram.
        """
    @overload
    def __init__(self, pt1: PyGe.Point2d, pt2: PyGe.Point2d, /) -> None:
        """
        This class provides a two-dimensional bounding volume implementation. Bounding blocks may
        exist in two forms: as an ordinary coordinate-aligned bounding box and as a parallelogram.
        """
    @overload
    def __init__(self, base: PyGe.Point2d, dir1: PyGe.Vector2d, dir2: PyGe.Vector2d, /) -> None:
        """
        This class provides a two-dimensional bounding volume implementation. Bounding blocks may
        exist in two forms: as an ordinary coordinate-aligned bounding box and as a parallelogram.
        """
    @overload
    def __init__(self, *args) -> None:
        """
        This class provides a two-dimensional bounding volume implementation. Bounding blocks may
        exist in two forms: as an ordinary coordinate-aligned bounding box and as a parallelogram.
        """
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def cast(otherObject: PyGe.Entity2d, /) -> BoundBlock2d: ...
    @staticmethod
    def className() -> str: ...
    def contains(self, pt: PyGe.Point2d, /) -> bool: ...
    @staticmethod
    def copycast(otherObject: PyGe.Entity2d, /) -> BoundBlock2d: ...
    def extend(self, pt: PyGe.Point2d, /) -> None: ...
    def getBasePoint(self, /) -> Point2d: ...
    def getDirection1(self, /) -> Vector2d: ...
    def getDirection2(self, /) -> Vector2d: ...
    def getMaxPoint(self, /) -> Point2d: ...
    def getMinPoint(self, /) -> Point2d: ...
    def isBox(self, /) -> bool: ...
    def isDisjoint(self, block: PyGe.BoundBlock2d, /) -> bool: ...
    @overload
    def set(self, pt1: PyGe.Point2d, pt2: PyGe.Point2d, /) -> None: ...
    @overload
    def set(self, base: PyGe.Point2d, dir1: PyGe.Vector2d, dir2: PyGe.Vector2d, /) -> None: ...
    @overload
    def set(self, *args) -> None: ...
    def setToBox(self, val: bool, /) -> None: ...
    def swell(self, val: float, /) -> None: ...

class BoundBlock3d(PyGe.Entity3d):
    @overload
    def __init__(self, /) -> None:
        """
        This class provides spatial dimensional bounding volume implementation. Bounding blocks may
        exist in two forms: as an ordinary coordinate-aligned bounding box and as a parallelepiped.
        """
    @overload
    def __init__(
        self, base: PyGe.Point3d, dir1: PyGe.Vector3d, dir2: PyGe.Vector3d, dir3: PyGe.Vector3d, /
    ) -> None:
        """
        This class provides spatial dimensional bounding volume implementation. Bounding blocks may
        exist in two forms: as an ordinary coordinate-aligned bounding box and as a parallelepiped.
        """
    @overload
    def __init__(self, *args) -> None:
        """
        This class provides spatial dimensional bounding volume implementation. Bounding blocks may
        exist in two forms: as an ordinary coordinate-aligned bounding box and as a parallelepiped.
        """
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def cast(otherObject: PyGe.Entity3d, /) -> BoundBlock3d: ...
    @staticmethod
    def className() -> str: ...
    def contains(self, pt: PyGe.Point3d, /) -> bool: ...
    @staticmethod
    def copycast(otherObject: PyGe.Entity3d, /) -> BoundBlock3d: ...
    def extend(self, pt: PyGe.Point3d, /) -> None: ...
    def getBasePoint(self, /) -> Point3d: ...
    def getDirection1(self, /) -> Vector3d: ...
    def getDirection3(self, /) -> Vector3d: ...
    def getMaxPoint(self, /) -> Point3d: ...
    def getMinPoint(self, /) -> Point3d: ...
    def isBox(self, /) -> bool: ...
    def isDisjoint(self, block: PyGe.BoundBlock3d, /) -> bool: ...
    @overload
    def set(self, pt1: PyGe.Point3d, pt2: PyGe.Point3d, /) -> None: ...
    @overload
    def set(
        self, base: PyGe.Point3d, dir1: PyGe.Vector3d, dir2: PyGe.Vector3d, dir3: PyGe.Vector3d, /
    ) -> None: ...
    @overload
    def set(self, *args) -> None: ...
    def setToBox(self, val: bool, /) -> None: ...
    def swell(self, val: float, /) -> None: ...

class BoundedPlane(PyGe.PlanarEnt):
    @overload
    def __init__(self, /) -> None:
        """
        Represents a bounded planar parametric surface.
        """
    @overload
    def __init__(self, origin: PyGe.Point3d, uVec: PyGe.Vector3d, vVec: PyGe.Vector3d, /) -> None:
        """
        Represents a bounded planar parametric surface.
        """
    @overload
    def __init__(self, p1: PyGe.Point3d, origin: PyGe.Point3d, p2: PyGe.Point3d, /) -> None:
        """
        Represents a bounded planar parametric surface.
        """
    @overload
    def __init__(self, *args) -> None:
        """
        Represents a bounded planar parametric surface.
        """
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def cast(otherObject: PyGe.Entity3d, /) -> BoundedPlane: ...
    @staticmethod
    def className() -> str: ...
    @staticmethod
    def copycast(otherObject: PyGe.Entity3d, /) -> BoundedPlane: ...
    def intersectWith(
        self, val: PyGe.LinearEnt3d | PyGe.Plane | PyGe.BoundedPlane, tol: PyGe.Tol = ..., /
    ) -> tuple[bool, PyGe.LineSeg3d]: ...
    @overload
    def set(self, origin: PyGe.Point3d, uVec: PyGe.Vector3d, vVec: PyGe.Vector3d, /) -> None: ...
    @overload
    def set(self, p1: PyGe.Point3d, origin: PyGe.Point3d, p2: PyGe.Point3d, /) -> None: ...
    @overload
    def set(self, *args) -> None: ...

class CircArc2d(PyGe.Curve2d):
    @overload
    def __init__(self, /) -> None:
        """
        Represents both full circles and circular arcs in 2D space.
        """
    @overload
    def __init__(self, cent: PyGe.Point2d, radius: float, /) -> None:
        """
        Represents both full circles and circular arcs in 2D space.
        """
    @overload
    def __init__(
        self, cent: PyGe.Point2d, radius: float, startAngle: float, endAngle: float, /
    ) -> None:
        """
        Represents both full circles and circular arcs in 2D space.
        """
    @overload
    def __init__(
        self,
        cent: PyGe.Point2d,
        radius: float,
        startAngle: float,
        endAngle: float,
        refVec: PyGe.Vector2d,
        isClockWise: bool,
        /,
    ) -> None:
        """
        Represents both full circles and circular arcs in 2D space.
        """
    @overload
    def __init__(
        self, startPoint: PyGe.Point2d, pnt: PyGe.Point2d, endPoint: PyGe.Point2d, /
    ) -> None:
        """
        Represents both full circles and circular arcs in 2D space.
        """
    @overload
    def __init__(
        self, startPoint: PyGe.Point2d, endPoint: PyGe.Point2d, bulge: float, bulgeFlag: bool, /
    ) -> None:
        """
        Represents both full circles and circular arcs in 2D space.
        """
    @overload
    def __init__(self, *args) -> None:
        """
        Represents both full circles and circular arcs in 2D space.
        """
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def cast(otherObject: PyGe.Entity2d, /) -> CircArc2d: ...
    def center(self, /) -> Point2d: ...
    @staticmethod
    def className() -> str: ...
    @staticmethod
    def copycast(otherObject: PyGe.Entity2d, /) -> CircArc2d: ...
    def endAng(self, /) -> float: ...
    def endPoint(self, /) -> Point2d: ...
    def intersectWith(
        self, val: PyGe.CircArc2d | PyGe.LinearEnt2d, tol: PyGe.Tol = ..., /
    ) -> tuple[bool, int, PyGe.Point2d, PyGe.Point2d]: ...
    def isClockWise(self, /) -> bool: ...
    def isInside(self, pt: PyGe.Point2d, tol: PyGe.Tol = ..., /) -> bool: ...
    def radius(self, /) -> float: ...
    def refVec(self, /) -> Vector2d: ...
    @overload
    def set(self, cent: PyGe.Point2d, radius: float, /) -> None: ...
    @overload
    def set(
        self,
        cent: PyGe.Point2d,
        radius: float,
        startAngle: float,
        endAngle: float,
        refVec: PyGe.Vector2d,
        isClockWise: bool,
        /,
    ) -> None: ...
    @overload
    def set(
        self, startPoint: PyGe.Point2d, pnt: PyGe.Point2d, endPoint: PyGe.Point2d, /
    ) -> None: ...
    @overload
    def set(
        self, startPoint: PyGe.Point2d, endPoint: PyGe.Point2d, bulge: float, bulgeFlag: bool, /
    ) -> None: ...
    @overload
    def set(self, curve1: PyGe.Curve2d, curve2: PyGe.Curve2d, radius: float, /) -> None: ...
    @overload
    def set(self, curve1: PyGe.Curve2d, curve2: PyGe.Curve2d, curve3: PyGe.Curve2d, /) -> None: ...
    @overload
    def set(self, *args) -> None: ...
    def setAngles(self, startAng: float, endAng: float, /) -> None: ...
    def setCenter(self, pt: PyGe.Point2d, /) -> None: ...
    def setRadius(self, val: float, /) -> None: ...
    def setRefVec(self, /) -> None: ...
    def setToComplement(self, /) -> None: ...
    def startAng(self, /) -> float: ...
    def startPoint(self, /) -> Point2d: ...
    def tangent(
        self, pt: PyGe.Point2d, tol: PyGe.Tol = ..., /
    ) -> tuple[bool, PyGe.Line3d, PyGe.AcGeError]: ...

class CircArc3d(PyGe.Curve3d):
    @overload
    def __init__(self, /) -> None:
        """
        Represents both full circles and circular arcs in 3D space.
        """
    @overload
    def __init__(self, cent: PyGe.Point3d, nrm: PyGe.Vector3d, radius: float, /) -> None:
        """
        Represents both full circles and circular arcs in 3D space.
        """
    @overload
    def __init__(
        self,
        cent: PyGe.Point3d,
        nrm: PyGe.Vector3d,
        refVec: PyGe.Vector3d,
        radius: float,
        startAngle: float,
        endAngle: float,
        /,
    ) -> None:
        """
        Represents both full circles and circular arcs in 3D space.
        """
    @overload
    def __init__(
        self, startPoint: PyGe.Point3d, pnt: PyGe.Point3d, endPoint: PyGe.Point3d, /
    ) -> None:
        """
        Represents both full circles and circular arcs in 3D space.
        """
    @overload
    def __init__(self, *args) -> None:
        """
        Represents both full circles and circular arcs in 3D space.
        """
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def cast(otherObject: PyGe.Entity3d, /) -> CircArc3d: ...
    def center(self, /) -> Point3d: ...
    @staticmethod
    def className() -> str: ...
    def closestPointToPlane(
        self, plane: PyGe.PlanarEnt, tol: PyGe.Tol = ..., /
    ) -> tuple[PyGe.Point3d, PyGe.Point3d]: ...
    @staticmethod
    def copycast(otherObject: PyGe.Entity3d, /) -> CircArc3d: ...
    def endAng(self, /) -> float: ...
    def endPoint(self, /) -> Point3d: ...
    def getPlane(self, /) -> Plane: ...
    def intersectWith(
        self, other: PyGe.CircArc3d | PyGe.LinearEnt3d | PyGe.PlanarEnt, tol: PyGe.Tol = ..., /
    ) -> tuple[bool, int, PyGe.Point3d, PyGe.Point3d]: ...
    def isInside(self, pt: PyGe.Point3d, tol: PyGe.Tol = ..., /) -> bool: ...
    def normal(self, /) -> Vector3d: ...
    def projIntersectWith(
        self, other: PyGe.LinearEnt3d, projDir: PyGe.Vector3d, tol: PyGe.Tol = ..., /
    ) -> tuple: ...
    def radius(self, /) -> float: ...
    def refVec(self, /) -> Vector3d: ...
    @overload
    def set(self, cent: PyGe.Point3d, nrm: PyGe.Vector3d, radius: float, /) -> None: ...
    @overload
    def set(
        self,
        cent: PyGe.Point3d,
        nrm: PyGe.Vector3d,
        refVec: PyGe.Vector3d,
        radius: float,
        startAngle: float,
        endAngle: float,
        /,
    ) -> None: ...
    @overload
    def set(
        self, startPoint: PyGe.Point3d, pnt: PyGe.Point3d, endPoint: PyGe.Point3d, /
    ) -> None: ...
    @overload
    def set(self, curve1: PyGe.Curve3d, curve2: PyGe.Curve3d, radius: float, /) -> None: ...
    @overload
    def set(self, curve1: PyGe.Curve3d, curve2: PyGe.Curve3d, curve3: PyGe.Curve3d, /) -> None: ...
    @overload
    def set(self, *args) -> None: ...
    def setAngles(self, val: float, /) -> None: ...
    def setAxes(self, vec: PyGe.Vector3d, refvec: PyGe.Vector3d, /) -> None: ...
    def setCenter(self, pt: PyGe.Point3d, /) -> None: ...
    def setRadius(self, val: float, /) -> None: ...
    def startAng(self, /) -> float: ...
    def startPoint(self, /) -> Point3d: ...
    def tangent(self, pt: PyGe.Point3d, tol: PyGe.Tol = ..., /) -> tuple[bool, PyGe.Line3d]: ...

class ClipBoundary2d(PyGe.Entity2d):
    @overload
    def __init__(self, /) -> None:
        """
        This class defines a planar clipping object for clipping arbitrary 2D polygons or polylines
        to 2D convex open or closed polyline curves or rectangles. The implementation is similar to
        the Sutherland-Hodgman pipeline clipping algorithm. Detailed edge information can
        optionally be generated to track the source of each clipped output segment. This
        information can be used to control edge display or to efficiently stitch together output
        from multiple clip boundaries (possibly from decomposing a non-convex clip boundary into
        multiple convex boundaries). Information about the spatial relationship between the clipped
        polygon or polyline and the clip region is also generated.
        """
    @overload
    def __init__(self, cornerA: PyGe.Point2d, cornerB: PyGe.Point2d, /) -> None:
        """
        This class defines a planar clipping object for clipping arbitrary 2D polygons or polylines
        to 2D convex open or closed polyline curves or rectangles. The implementation is similar to
        the Sutherland-Hodgman pipeline clipping algorithm. Detailed edge information can
        optionally be generated to track the source of each clipped output segment. This
        information can be used to control edge display or to efficiently stitch together output
        from multiple clip boundaries (possibly from decomposing a non-convex clip boundary into
        multiple convex boundaries). Information about the spatial relationship between the clipped
        polygon or polyline and the clip region is also generated.
        """
    @overload
    def __init__(self, clipBoundary: list[PyGe.Point2d], /) -> None:
        """
        This class defines a planar clipping object for clipping arbitrary 2D polygons or polylines
        to 2D convex open or closed polyline curves or rectangles. The implementation is similar to
        the Sutherland-Hodgman pipeline clipping algorithm. Detailed edge information can
        optionally be generated to track the source of each clipped output segment. This
        information can be used to control edge display or to efficiently stitch together output
        from multiple clip boundaries (possibly from decomposing a non-convex clip boundary into
        multiple convex boundaries). Information about the spatial relationship between the clipped
        polygon or polyline and the clip region is also generated.
        """
    @overload
    def __init__(self, *args) -> None:
        """
        This class defines a planar clipping object for clipping arbitrary 2D polygons or polylines
        to 2D convex open or closed polyline curves or rectangles. The implementation is similar to
        the Sutherland-Hodgman pipeline clipping algorithm. Detailed edge information can
        optionally be generated to track the source of each clipped output segment. This
        information can be used to control edge display or to efficiently stitch together output
        from multiple clip boundaries (possibly from decomposing a non-convex clip boundary into
        multiple convex boundaries). Information about the spatial relationship between the clipped
        polygon or polyline and the clip region is also generated.
        """
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def cast(otherObject: PyGe.Entity2d, /) -> ClipBoundary2d: ...
    @staticmethod
    def className() -> str: ...
    @staticmethod
    def copycast(otherObject: PyGe.Entity2d, /) -> ClipBoundary2d: ...

class CompositeCurve2d(PyGe.Curve2d):
    @overload
    def __init__(self, /) -> None:
        """
        Represents a composite curve, which is a single curve that consists of any number of
        component curves that are connected end-to-end. For instance, a composite curve could
        consist of four straight line segments that form a square. Each of the component curves
        must be bounded curves, which means that infinite lines and rays may not be used as
        component curves of a composite. A composite curve object stores a list of pointers to the
        component curves. The start parameter of a composite is 0.0. The parameter value at the
        endpoint of the first component curve is the approximate length of the first curve (call
        this value l1). The parameter value at the endpoint of the second curve is l1 plus the
        approximate length of the second curve, and so forth.
        """
    @overload
    def __init__(self, curveList: list[PyGe.Curve2d], /) -> None:
        """
        Represents a composite curve, which is a single curve that consists of any number of
        component curves that are connected end-to-end. For instance, a composite curve could
        consist of four straight line segments that form a square. Each of the component curves
        must be bounded curves, which means that infinite lines and rays may not be used as
        component curves of a composite. A composite curve object stores a list of pointers to the
        component curves. The start parameter of a composite is 0.0. The parameter value at the
        endpoint of the first component curve is the approximate length of the first curve (call
        this value l1). The parameter value at the endpoint of the second curve is l1 plus the
        approximate length of the second curve, and so forth.
        """
    @overload
    def __init__(self, curveList: list[PyGe.Curve2d], isOwnerOfCurves: list[int], /) -> None:
        """
        Represents a composite curve, which is a single curve that consists of any number of
        component curves that are connected end-to-end. For instance, a composite curve could
        consist of four straight line segments that form a square. Each of the component curves
        must be bounded curves, which means that infinite lines and rays may not be used as
        component curves of a composite. A composite curve object stores a list of pointers to the
        component curves. The start parameter of a composite is 0.0. The parameter value at the
        endpoint of the first component curve is the approximate length of the first curve (call
        this value l1). The parameter value at the endpoint of the second curve is l1 plus the
        approximate length of the second curve, and so forth.
        """
    @overload
    def __init__(self, *args) -> None:
        """
        Represents a composite curve, which is a single curve that consists of any number of
        component curves that are connected end-to-end. For instance, a composite curve could
        consist of four straight line segments that form a square. Each of the component curves
        must be bounded curves, which means that infinite lines and rays may not be used as
        component curves of a composite. A composite curve object stores a list of pointers to the
        component curves. The start parameter of a composite is 0.0. The parameter value at the
        endpoint of the first component curve is the approximate length of the first curve (call
        this value l1). The parameter value at the endpoint of the second curve is l1 plus the
        approximate length of the second curve, and so forth.
        """
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def cast(otherObject: PyGe.Entity2d, /) -> CompositeCurve2d: ...
    @staticmethod
    def className() -> str: ...
    @staticmethod
    def copycast(otherObject: PyGe.Entity2d, /) -> CompositeCurve2d: ...
    def getCurveList(self, /) -> list[PyGe.Curve3d]: ...
    def globalToLocalParam(self, param: float, /) -> tuple[float, int]: ...
    def localToGlobalParam(self, param: float, segNum: int, /) -> float: ...
    @overload
    def setCurveList(self, curveList: list[PyGe.Curve2d], /) -> None: ...
    @overload
    def setCurveList(
        self, curveList: list[PyGe.Curve2d], isOwnerOfCurves: list[int], /
    ) -> None: ...
    @overload
    def setCurveList(self, *args) -> None: ...

class CompositeCurve3d(PyGe.Curve3d):
    @overload
    def __init__(self, /) -> None:
        """
        Represents a composite curve, which is a single curve that consists of any number of
        component curves that are connected end-to-end. For instance, a composite curve could
        consist of four straight line segments that form a square. Each of the component curves
        must be bounded curves, which means that infinite lines and rays may not be used as
        component curves of a composite. The component curves are not required to all lie in the
        same plane. A composite curve object stores a list of pointers to the component curves. The
        start parameter of a composite is 0.0. The parameter value at the endpoint of the first
        component curve is the approximate length of the first curve (call this value l1). The
        parameter value at the endpoint of the second curve is l1 plus the approximate length of
        the second curve, etc.
        """
    @overload
    def __init__(self, curveList: list[PyGe.Curve3d], /) -> None:
        """
        Represents a composite curve, which is a single curve that consists of any number of
        component curves that are connected end-to-end. For instance, a composite curve could
        consist of four straight line segments that form a square. Each of the component curves
        must be bounded curves, which means that infinite lines and rays may not be used as
        component curves of a composite. The component curves are not required to all lie in the
        same plane. A composite curve object stores a list of pointers to the component curves. The
        start parameter of a composite is 0.0. The parameter value at the endpoint of the first
        component curve is the approximate length of the first curve (call this value l1). The
        parameter value at the endpoint of the second curve is l1 plus the approximate length of
        the second curve, etc.
        """
    @overload
    def __init__(self, curveList: list[PyGe.Curve3d], isOwnerOfCurves: list[int], /) -> None:
        """
        Represents a composite curve, which is a single curve that consists of any number of
        component curves that are connected end-to-end. For instance, a composite curve could
        consist of four straight line segments that form a square. Each of the component curves
        must be bounded curves, which means that infinite lines and rays may not be used as
        component curves of a composite. The component curves are not required to all lie in the
        same plane. A composite curve object stores a list of pointers to the component curves. The
        start parameter of a composite is 0.0. The parameter value at the endpoint of the first
        component curve is the approximate length of the first curve (call this value l1). The
        parameter value at the endpoint of the second curve is l1 plus the approximate length of
        the second curve, etc.
        """
    @overload
    def __init__(self, *args) -> None:
        """
        Represents a composite curve, which is a single curve that consists of any number of
        component curves that are connected end-to-end. For instance, a composite curve could
        consist of four straight line segments that form a square. Each of the component curves
        must be bounded curves, which means that infinite lines and rays may not be used as
        component curves of a composite. The component curves are not required to all lie in the
        same plane. A composite curve object stores a list of pointers to the component curves. The
        start parameter of a composite is 0.0. The parameter value at the endpoint of the first
        component curve is the approximate length of the first curve (call this value l1). The
        parameter value at the endpoint of the second curve is l1 plus the approximate length of
        the second curve, etc.
        """
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def cast(otherObject: PyGe.Entity3d, /) -> CompositeCurve3d: ...
    @staticmethod
    def className() -> str: ...
    @staticmethod
    def copycast(otherObject: PyGe.Entity3d, /) -> CompositeCurve3d: ...
    @staticmethod
    def createFromLineSeg3dArray(seg: list[PyGe.LineSeg3d], /) -> list: ...
    def getCurveList(self, /) -> list[PyGe.Curve3d]: ...
    def globalToLocalParam(self, param: float, /) -> tuple[float, int]: ...
    def localToGlobalParam(self, param: float, segNum: int, /) -> float: ...
    @overload
    def setCurveList(self, curveList: list[PyGe.Curve3d], /) -> None: ...
    @overload
    def setCurveList(
        self, curveList: list[PyGe.Curve3d], isOwnerOfCurves: list[int], /
    ) -> None: ...
    @overload
    def setCurveList(self, *args) -> None: ...

class Cone(PyGe.Surface):
    @overload
    def __init__(self, /) -> None:
        """
        Represents a bounded right circular cone.
        """
    @overload
    def __init__(
        self,
        cosineAngle: float,
        sineAngle: float,
        baseOrigin: PyGe.Point3d,
        baseRadius: float,
        axisOfSymmetry: PyGe.Vector3d,
        /,
    ) -> None:
        """
        Represents a bounded right circular cone.
        """
    @overload
    def __init__(
        self,
        cosineAngle: float,
        sineAngle: float,
        baseOrigin: PyGe.Point3d,
        baseRadius: float,
        axisOfSymmetry: PyGe.Vector3d,
        refAxis: PyGe.Vector3d,
        height: PyGe.Interval,
        startAngle: float,
        endAngle: float,
        /,
    ) -> None:
        """
        Represents a bounded right circular cone.
        """
    @overload
    def __init__(self, *args) -> None:
        """
        Represents a bounded right circular cone.
        """
    def __reduce__(self, /) -> Any: ...
    def apex(self, /) -> Point3d: ...
    def axisOfSymmetry(self, /) -> Vector3d: ...
    def baseCenter(self, /) -> Point3d: ...
    def baseRadius(self, /) -> float: ...
    @staticmethod
    def cast(otherObject: PyGe.Entity3d, /) -> Cone: ...
    @staticmethod
    def className() -> str: ...
    @staticmethod
    def copycast(otherObject: PyGe.Entity3d, /) -> Cone: ...
    def getAngles(self, /) -> tuple[float, float]: ...
    def getHalfAngle(self, /) -> tuple[float, float]: ...
    def getHeight(self, /) -> Interval: ...
    def halfAngle(self, /) -> float: ...
    def heightAt(self, val: float, /) -> float: ...
    def intersectWith(
        self, val: PyGe.LinearEnt3d, tol: PyGe.Tol = ..., /
    ) -> tuple[bool, int, PyGe.Point3d, PyGe.Point3d]: ...
    def isClosed(self, tol: PyGe.Tol = ..., /) -> bool: ...
    def isOuterNormal(self, /) -> bool: ...
    def refAxis(self, /) -> Vector3d: ...
    @overload
    def set(
        self,
        cosineAngle: float,
        sineAngle: float,
        baseOrigin: PyGe.Point3d,
        baseRadius: float,
        axisOfSymmetry: PyGe.Vector3d,
        /,
    ) -> None: ...
    @overload
    def set(
        self,
        cosineAngle: float,
        sineAngle: float,
        baseOrigin: PyGe.Point3d,
        baseRadius: float,
        axisOfSymmetry: PyGe.Vector3d,
        refAxis: PyGe.Vector3d,
        height: PyGe.Interval,
        startAngle: float,
        endAngle: float,
        /,
    ) -> None: ...
    @overload
    def set(self, *args) -> None: ...
    def setAngles(self, startAngle: float, endAngle: float, /) -> None: ...
    def setBaseRadius(self, val: float, /) -> None: ...
    def setHeight(self, val: PyGe.Interval, /) -> None: ...

class CubicSplineCurve2d(PyGe.SplineEnt2d):
    @overload
    def __init__(self, /) -> None:
        """
        Represent an interpolation cubic spline in 2D space.
        """
    @overload
    def __init__(self, curve: PyGe.Curve2d, epsilon: float, /) -> None:
        """
        Represent an interpolation cubic spline in 2D space.
        """
    @overload
    def __init__(self, fitPnts: list[PyGe.Point2d], tol: PyGe.Tol, /) -> None:
        """
        Represent an interpolation cubic spline in 2D space.
        """
    @overload
    def __init__(
        self,
        fitPnts: list[PyGe.Point2d],
        startDeriv: PyGe.Vector2d,
        endDeriv: PyGe.Vector2d,
        tol: PyGe.Tol,
        /,
    ) -> None:
        """
        Represent an interpolation cubic spline in 2D space.
        """
    @overload
    def __init__(
        self,
        knots: PyGe.KnotVector,
        fitPnts: list[PyGe.Point2d],
        firstDerivs: list[PyGe.Point2d],
        isPeriodic: bool,
        /,
    ) -> None:
        """
        Represent an interpolation cubic spline in 2D space.
        """
    @overload
    def __init__(self, *args) -> None:
        """
        Represent an interpolation cubic spline in 2D space.
        """
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def cast(otherObject: PyGe.Entity2d, /) -> CubicSplineCurve2d: ...
    @staticmethod
    def className() -> str: ...
    @staticmethod
    def copycast(otherObject: PyGe.Entity2d, /) -> CubicSplineCurve2d: ...
    def firstDerivAt(self, val: int, /) -> Vector2d: ...
    def fitPointAt(self, val: int, /) -> Point2d: ...
    def numFitPoints(self, /) -> int: ...
    def setFirstDerivAt(self, val: int, pt: PyGe.Vector2d, /) -> None: ...
    def setFitPointAt(self, val: int, pt: PyGe.Point2d, /) -> None: ...

class CubicSplineCurve3d(PyGe.SplineEnt3d):
    @overload
    def __init__(self, /) -> None:
        """
        Represents an interpolation cubic spline in 3D space.
        """
    @overload
    def __init__(self, curve: PyGe.Curve3d, epsilon: float, /) -> None:
        """
        Represents an interpolation cubic spline in 3D space.
        """
    @overload
    def __init__(self, fitPnts: list[PyGe.Point3d], tol: PyGe.Tol, /) -> None:
        """
        Represents an interpolation cubic spline in 3D space.
        """
    @overload
    def __init__(
        self,
        fitPnts: list[PyGe.Point3d],
        startDeriv: PyGe.Vector3d,
        endDeriv: PyGe.Vector3d,
        tol: PyGe.Tol,
        /,
    ) -> None:
        """
        Represents an interpolation cubic spline in 3D space.
        """
    @overload
    def __init__(
        self,
        knots: PyGe.KnotVector,
        fitPnts: list[PyGe.Point3d],
        firstDerivs: list[PyGe.Vector3d],
        isPeriodic: bool,
        /,
    ) -> None:
        """
        Represents an interpolation cubic spline in 3D space.
        """
    @overload
    def __init__(self, *args) -> None:
        """
        Represents an interpolation cubic spline in 3D space.
        """
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def cast(otherObject: PyGe.Entity3d, /) -> CubicSplineCurve3d: ...
    @staticmethod
    def className() -> str: ...
    @staticmethod
    def copycast(otherObject: PyGe.Entity3d, /) -> CubicSplineCurve3d: ...
    def firstDerivAt(self, idx: int, /) -> Vector3d: ...
    def fitPointAt(self, idx: int, /) -> Point3d: ...
    def numFitPoints(self, /) -> int: ...
    def setFirstDerivAt(self, idx: int, vec: PyGe.Vector3d, /) -> None: ...
    def setFitPointAt(self, idx: int, pt: PyGe.Point3d, /) -> None: ...

class Curve2d(PyGe.Entity2d):
    def __init__(self) -> None:
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /) -> Any: ...
    def area(self, startParam: float, endParam: float, tol: float = ..., /) -> float: ...
    def boundBlock(self, range: PyGe.Interval = ..., /) -> BoundBlock2d: ...
    @staticmethod
    def cast(otherObject: PyGe.Curve2d, /) -> Curve2d: ...
    @staticmethod
    def className() -> str: ...
    def closestPointTo(
        self, other: PyGe.Point2d | PyGe.Curve2d, tol: PyGe.Tol = ..., /
    ) -> Point2d: ...
    @staticmethod
    def copycast(otherObject: PyGe.Curve2d, /) -> Curve2d: ...
    def distanceTo(self, pt: PyGe.Point2d | PyGe.Curve2d, tol: PyGe.Tol = ..., /) -> float: ...
    def evalPoint(self, param: float, numDeriv: int = 1, /) -> Point2d: ...
    def explode(self, val: PyGe.Interval = ..., /) -> list[PyGe.Curve2d]: ...
    def getClosestPointTo(self, other: PyGe.Point2d, tol: PyGe.Tol = ..., /) -> PointOnCurve2d: ...
    def getClosestPointsTo(
        self, other: PyGe.Curve2d, tol: PyGe.Tol = ..., /
    ) -> tuple[PyGe.Point3d, PyGe.Point3d]: ...
    def getEndPoint(self, /) -> Point2d: ...
    def getInterval(self, /) -> Interval: ...
    def getNormalPoint(self, pnt: PyGe.Point2d, tol: PyGe.Tol = ..., /) -> PointOnCurve2d: ...
    @overload
    def getSamplePoints(self, numSample: int, /) -> tuple[list[PyGe.Point2d], list[float]]: ...
    @overload
    def getSamplePoints(
        self, fromParam: float, toParam: float, approxEps: float, /
    ) -> tuple[list[PyGe.Point2d], list[float]]: ...
    @overload
    def getSamplePoints(self, *args) -> tuple[list[PyGe.Point2d], list[float]]: ...
    def getSplitCurves(self, param: float, /) -> tuple[PyGe.Curve2d, PyGe.Curve2d]: ...
    def getStartPoint(self, /) -> Point2d: ...
    def getTrimmedOffset(
        self, dist: float, extensionType: PyGe.OffsetCrvExtType, tol: PyGe.Tol = ..., /
    ) -> list[PyGe.Curve2d]: ...
    def hasEndPoint(self, /) -> bool: ...
    def hasStartPoint(self, /) -> bool: ...
    def isClosed(self, tol: PyGe.Tol = ..., /) -> bool: ...
    def isDegenerate(self, tol: PyGe.Tol = ..., /) -> tuple[bool, PyGe.Entity2d]: ...
    def isLinear(self, tol: PyGe.Tol = ..., /) -> tuple[bool, PyGe.Line2d]: ...
    def isOn(self, pt: float | PyGe.Point2d, tol: PyGe.Tol = ..., /) -> tuple: ...
    def isPeriodic(self, /) -> tuple[bool, float]: ...
    def length(self, frm: float, to: float, tol: float = ..., /) -> float: ...
    def orthoBoundBlock(self, range: PyGe.Interval = ..., /) -> BoundBlock2d: ...
    def paramAtLength(
        self, datumParam: float, length: float, posParamDir: bool = True, tol: float = ..., /
    ) -> float: ...
    def paramOf(self, pt: PyGe.Point2d, tol: PyGe.Tol = ..., /) -> float: ...
    def reverseParam(self, /) -> None: ...
    def setInterval(self, val: PyGe.Interval = ..., /) -> None: ...

class Curve3d(PyGe.Entity3d):
    def __init__(self) -> None:
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /) -> Any: ...
    def area(self, startParam: float, endParam: float, tol: float = ..., /) -> float:
        """
        Returns the area of the interval of the curve defined by startParam and endParam. Returns
        Adesk::kTrue if area was successfully computed to within the specified tolerance. If the
        curve is not planar, then the area cannot be calculated and a value of Adesk::kFalse is
        returned. If the points at startParam and endParam are the same, then this function returns
        the area of the closed curve. If the points are different, then this function connects the
        two points with a line segment and return the signed area between the curve and the line
        segment. If the line segment does not intersect the curve at any points between startParam
        and endParam, then the returned area is positive. If the line segment intersects the curves
        at any points between startParam and endParam, then the returned area is the sum of the
        sub-areas created by the intersection of the line segment with the curve. Each sub-area has
        a positive or negative area, depending on whether the curve lies above or below the line
        segment. The total area returned by this function can therefore be positive, negative, or
        0.
        """
    def boundBlock(self, range: PyGe.Interval = ..., /) -> BoundBlock3d:
        """
        Returns the bounding box of the curve. The sides of the returned box are parallel to the
        coordinate axes.
        """
    @staticmethod
    def cast(otherObject: PyGe.Curve3d, /) -> Curve3d: ...
    @staticmethod
    def className() -> str: ...
    def closestPointTo(
        self, other: PyGe.Point3d | PyGe.Curve3d, tol: PyGe.Tol = ..., /
    ) -> Point3d:
        """
        Finds the closest point on this curve to the input point. This function is the same as
        closestPointTo(), except that the closest point is returned as an AcGePointOnCurve3d
        object.
        """
    @staticmethod
    def copycast(otherObject: PyGe.Curve3d, /) -> Curve3d: ...
    def distanceTo(self, pt: PyGe.Point3d | PyGe.Curve3d, tol: PyGe.Tol = ..., /) -> float:
        """
        Returns the distance between the input point and the closest point on this curve.
        """
    def evalPoint(self, param: float, numDeriv: int = 1, /) -> Point3d:
        """
        Returns the point on the curve that corresponds to the input parameter value. Also returns
        the number of derivative vectors that are specified in numDeriv. The numDeriv parameter
        should not be set larger than 2.
        """
    def explode(self, val: PyGe.Interval = ..., /) -> list[PyGe.Curve3d]:
        """
        Explodes the curve into its individual components. If the curve is a composite curve, then
        explodedCurves contains the list of component curves of the composite. If the curve is a
        spline, then it is exploded at the points of C1 discontinuity and explodedCurves contains a
        copy of each continuous sub-curve. This function returns Adesk::kTrue if the curve was
        exploded (that is, the curve was a composite or a discontinuous spline) and Adesk::kFalse
        otherwise. The number of entries returned in newExplodedCurves is always the same as the
        number of entries in explodedCurves. Each flag in newExplodedCurves indicates whether the
        corresponding curve in explodedCurves was created with the new operator. If the flag is 1,
        then it is the responsibility of the caller to delete the curve. If the flag is 0, the
        curve is deleted by gelib and the caller should not attempt to delete it. If no intrvl
        parameter is supplied, then the interval is taken to be the entire curve.
        """
    def getClosestPointTo(self, other: PyGe.Point3d, tol: PyGe.Tol = ..., /) -> PointOnCurve3d:
        """
        Finds the closest point on this curve to the input point. This function is the same as
        closestPointTo(), except that the closest point is returned as an AcGePointOnCurve3d
        object.
        """
    def getClosestPointsTo(
        self, other: PyGe.Curve3d, tol: PyGe.Tol = ..., /
    ) -> tuple[PyGe.Point3d, PyGe.Point3d]:
        """
        Finds the point on the curve which when projected onto a plane whose normal is
        projectDirection is the closest point on the projected curve to the input point. This
        function is mainly used by graphics where projectDirection is the line of sight. In this
        case, this function returns the point on the curve that appears to be closest to the input
        point (but may not be the actual closest point). This function is the same as
        projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a
        AcGePointOnCurve3d object instead of a AcGePoint3d object.
        """
    def getEndPoint(self, /) -> Point3d: ...
    def getInterval(self, /) -> Interval:
        """
        Returns the parametric range of the curve. The function evalPoint(double) always returns a
        point on this curve when called with a value within the returned interval.
        """
    def getNormalPoint(self, pnt: PyGe.Point3d, tol: PyGe.Tol = ..., /) -> PointOnCurve3d:
        """
        Finds the point on the input curve whose normal passes through the input point. The
        returned point lies on a plane that also contains the input point and is perpendicular to
        the curve tangent at that point. The returned point is therefore at a local minimum or a
        local maximum from the input point. The curve does not need to be planar. If the curve is
        planar, the input point does not need to lie in the plane of the curve. On input, the
        second parameter is assumed to contain the parameter value of an initial guess. If there is
        more than one normal point on the curve, the returned point will be the one whose parameter
        value is closest to the input parameter value.
        """
    def getProjClosestPointTo(
        self, pt: PyGe.Point3d, projDir: PyGe.Vector3d, tol: PyGe.Tol = ..., /
    ) -> PointOnCurve3d:
        """
        Finds the point on the curve which when projected onto a plane whose normal is
        projectDirection is the closest point on the projected curve to the input point. This
        function is mainly used by graphics where projectDirection is the line of sight. In this
        case, this function returns the point on the curve that appears to be closest to the input
        point (but may not be the actual closest point). This function is the same as
        projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a
        AcGePointOnCurve3d object instead of a AcGePoint3d object.
        """
    def getProjClosestPointsTo(
        self, pt: PyGe.Curve3d, projDir: PyGe.Vector3d, tol: PyGe.Tol = ..., /
    ) -> tuple[PyGe.PointOnCurve3d, PyGe.PointOnCurve3d]:
        """
        Finds the point on the curve which when projected onto a plane whose normal is
        projectDirection is the closest point on the projected curve to the input point. This
        function is mainly used by graphics where projectDirection is the line of sight. In this
        case, this function returns the point on the curve that appears to be closest to the input
        point (but may not be the actual closest point). This function is the same as
        projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a
        AcGePointOnCurve3d object instead of a AcGePoint3d object.
        """
    @overload
    def getSamplePoints(self, numSample: int, /) -> tuple[list[PyGe.Point3d], list[float]]:
        """
        Returns the specified number of points on the curve. The points are equally spaced by
        parameter value. So if the interval of the curve [0,1] and numSample is 5, the parameter
        values of the returned points are 0, 0.25, 0.5, 0.75, and 1.
        """
    @overload
    def getSamplePoints(
        self, fromParam: float, toParam: float, approxEps: float, /
    ) -> tuple[list[PyGe.Point3d], list[float]]:
        """
        Returns the specified number of points on the curve. The points are equally spaced by
        parameter value. So if the interval of the curve [0,1] and numSample is 5, the parameter
        values of the returned points are 0, 0.25, 0.5, 0.75, and 1.
        """
    @overload
    def getSamplePoints(self, *args) -> tuple[list[PyGe.Point3d], list[float]]:
        """
        Returns the specified number of points on the curve. The points are equally spaced by
        parameter value. So if the interval of the curve [0,1] and numSample is 5, the parameter
        values of the returned points are 0, 0.25, 0.5, 0.75, and 1.
        """
    def getSplitCurves(self, param: float, /) -> tuple[PyGe.Curve3d, PyGe.Curve3d]:
        """
        Returns two segments which are obtained by splitting the curve at the input parameter
        value. If the specified parameter value does not lie within the parametric interval of the
        curve or if it corresponds to the start point or endpoint of the curve, then piece1 and
        piece2 are set to null. This function uses the new to create the curve segments whose
        addresses are returned in piece1 and piece2. It is the responsibility of the caller to
        delete these objects.
        """
    def getStartPoint(self, /) -> Point3d: ...
    def getTrimmedOffset(
        self,
        dist: float,
        planeNormal: PyGe.Vector3d,
        extensionType: PyGe.OffsetCrvExtType,
        tol: PyGe.Tol = ...,
        /,
    ) -> list[PyGe.Curve3d]:
        """
        Returns one or more offset curves that represent the trimmed offset of the curve. The curve
        must be planar and planeNormal must be perpendicular to the plane of the curve. The
        positive direction of offset at a point on the curve is taken to be the cross product of
        planeNormal with the tangent vector at that point. The curve may be offset in either of two
        directions by specifying a positive or negative offset distance; planeNormal determines
        which direction is the positive direction of offset. The returned offset curves are trimmed
        so that they do not contain any points of self-intersection. Each curve that is returned in
        offsetCurveList is created with the new and it is the responsibility of the caller to
        delete these curves. Each curve that is returned in offsetCurveList is a connected curve
        and may be a composite curve if the offset curve had to be trimmed to remove
        self-intersecting loops. offsetCurveList only contains more than one curve if the offset
        operation produces multiple curves which are not connected. If the original curve contains
        points of C1 discontinuity and the direction of offset causes the offset curve to be
        disjoint (for instance, if the original curve is a composite curve that is a rectangle and
        the direction of offset is to the outside of the rectangle), then the offset curve is
        closed with an arc or a line segment, or the curves are simply extended depending on the
        value of extensionType.
        """
    def hasEndPoint(self, /) -> bool:
        """
        Returns Adesk::kTrue if curve has an endpoint. A return value of Adesk::kFalse means that
        the parametric interval of the curve does not have an upper bound. The endPnt parameter
        contains meaningful data only if this function returns a value of Adesk::kTrue.
        """
    def hasStartPoint(self, /) -> bool:
        """
        Returns Adesk::kTrue if curve has a start point. A return value of Adesk::kFalse means that
        the parametric interval of the curve does not have a lower bound. The startPnt parameter
        contains meaningful data only if this function returns a value of Adesk::kTrue.
        """
    def isClosed(self, tol: PyGe.Tol = ..., /) -> bool:
        """
        Determines if start point and endpoint of curve are the same.
        """
    def isCoplanarWith(
        self, curve: PyGe.Curve3d, tol: PyGe.Tol = ..., /
    ) -> tuple[bool, PyGe.Plane]:
        """
        Returns Adesk::kTrue if both curve are planar and lie in the same plane. The plane
        parameter is only valid if this function returns a value of Adesk::kTrue.
        """
    def isDegenerate(self, tol: PyGe.Tol = ..., /) -> tuple[bool, PyGe.Entity3d]:
        """
        Determines if the curve is degenerate and if so returns the type of entity which the curve
        degenerates into. For example, if the curve is a circle with a radius of 0 then
        degenerateType is set to AcGe::kPoint3d. If the curve is an ellipse with a minor radius of
        0 and a major radius of 1, then degenerateType is set to AcGe::kLineSeg3d. The
        degenerateType parameter is only set to something meaningful when this function returns a
        value of Adesk::kTrue.
        """
    def isLinear(self, tol: PyGe.Tol = ..., /) -> tuple[bool, PyGe.Line3d]:
        """
        Determines if curve is linear. This function returns an infinite line even if the curve is
        not infinite. The line parameter contains meaningful data only if this function returns a
        value of Adesk::kTrue.
        """
    def isOn(self, pt: float | PyGe.Point3d, tol: PyGe.Tol = ..., /) -> tuple:
        """
        Determines if input parameter value is within valid parametric range of curve.
        """
    def isPeriodic(self, /) -> tuple[bool, float]:
        """
        Determines if the curve is periodic. The curve is periodic if and only if it is closed and
        the two points evalPoint(t) and evalPoint(t+period) are always the same point for all
        values of t.
        """
    def isPlanar(self, tol: PyGe.Tol = ..., /) -> tuple[bool, PyGe.Plane]:
        """
        Determines if curve is planar. If the curve is a line, then this function returns an
        arbitrary plane that contains the line. The plane parameter contains meaningful data only
        if this function returns a value of Adesk::kTrue.
        """
    def length(self, frm: float, to: float, tol: float = ..., /) -> float:
        """
        Returns the arc length of the curve between the two parameter values.
        """
    def orthoBoundBlock(self, range: PyGe.Interval = ..., /) -> BoundBlock3d:
        """
        Returns the bounding box of the curve. The sides of the returned box are parallel to the
        coordinate axes.
        """
    def orthoProject(self, projectionPlane: PyGe.Plane, tol: PyGe.Tol = ..., /) -> Entity3d:
        """
        Returns the entity that is the orthogonal projection of the curve onto the projection
        plane. The returned entity may not be of the same type as the original curve and may not
        even be a curve (for instance, a line projects into a point if it is orthogonal to the
        projection plane). The returned entity is created with the new and it is the responsibility
        of the caller to delete it.
        """
    def paramAtLength(
        self, datumParam: float, length: float, posParamDir: bool = True, tol: float = ..., /
    ) -> float:
        """
        Returns the parameter value of the point whose arc length distance (from the point with
        parameter value datumParam) is the input length. In other words, if t = paramAtLength
        (datumParam, len, posParamDir, tol) then length (t, datumParam, tol) is (approximately)
        equal to len. If posParamDir is set to Adesk::kTrue, then the returned parameter value is
        greater than datumParam. Otherwise it will be less than datumParam.
        """
    def paramOf(self, pt: PyGe.Point3d, tol: PyGe.Tol = ..., /) -> float:
        """
        Returns the parameter value of pnt. This function assumes that pnt lies on the curve and
        does not verify this. If pnt does not lie on the curve, this function will return
        unpredictable results. If it is not known whether pnt lies on the curve, the user should
        not call this function but should instead call AcGeCurve3d::isOn (pnt, param, tol).
        """
    def projClosestPointTo(
        self, pt: PyGe.Point3d, projDir: PyGe.Vector3d, tol: PyGe.Tol = ..., /
    ) -> Point3d:
        """
        Finds the point on the curve which when projected onto a plane whose normal is
        projectDirection is the closest point on the projected curve to the input point. This
        function is mainly used by graphics where projectDirection is the line of sight. In this
        case, this function returns the point on the curve that appears to be closest to the input
        point (but may not be the actual closest point). This function is the same as
        projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a
        AcGePointOnCurve3d object instead of a AcGePoint3d object.
        """
    def projClosestPointsTo(
        self, pt: PyGe.Curve3d, projDir: PyGe.Vector3d, tol: PyGe.Tol = ..., /
    ) -> tuple[PyGe.Point3d, PyGe.Point3d]:
        """
        Finds the point on the curve which when projected onto a plane whose normal is
        projectDirection is the closest point on the projected curve to the input point. This
        function is mainly used by graphics where projectDirection is the line of sight. In this
        case, this function returns the point on the curve that appears to be closest to the input
        point (but may not be the actual closest point). This function is the same as
        projClosestPointTo(const AcGePoint3d&, ...) but returns the closest point as a
        AcGePointOnCurve3d object instead of a AcGePoint3d object.
        """
    def project(
        self, projectionPlane: PyGe.Plane, projDir: PyGe.Vector3d, tol: PyGe.Tol = ..., /
    ) -> Entity3d:
        """
        Returns the entity that is the projection of the curve onto the projection plane in the
        specified direction. The projectDirection vector must not be parallel to the projection
        plane. The returned entity may not be of the same type as the original curve and may not
        even be a curve (for instance, a line projects into a point if it is parallel to
        projectDirection). The returned entity is created with the new and it is the responsibility
        of the caller to delete it.
        """
    def reverseParam(self, /) -> None:
        """
        Reverses the parametric direction of the curve. The point set of the curve is unchanged,
        but the direction of the curve is reversed.
        """
    def setInterval(self, val: PyGe.Interval = ..., /) -> None:
        """
        Sets the domain of the curve to the input interval.
        """

class CurveCurveInt2d(PyGe.Entity2d):
    @overload
    def __init__(self, /) -> None:
        """
        Represents the intersection set of two curves. There are special case intersectWith()
        functions in the AcGeLinearEnt2d, AcGeCircArc2d, and AcGeEllipArc2d classes to find the
        points of intersection between two lines, a line and an arc, an arc and an arc, or a line
        and an ellipse. However, there is no general intersectWith() function to find the points of
        intersection between two general curves. This can only be done by constructing an object of
        this class. Objects of this class are constructed by specifying the two curves that are to
        be intersected. It is also possible to specify a specific interval of each curve that is to
        be intersected. Pointers to these curves are then stored as data members of this class.
        This class contains query methods that return the intersection points and intervals of
        overlap between the two curves. There are also methods that return information about each
        intersection point, such as whether the intersection is a tangential or transversal
        intersection. Points of self-intersection of a curve can be found by passing the same curve
        in both parameters of the constructor.
        """
    @overload
    def __init__(self, curve1: PyGe.Curve2d, curve2: PyGe.Curve2d, /) -> None:
        """
        Represents the intersection set of two curves. There are special case intersectWith()
        functions in the AcGeLinearEnt2d, AcGeCircArc2d, and AcGeEllipArc2d classes to find the
        points of intersection between two lines, a line and an arc, an arc and an arc, or a line
        and an ellipse. However, there is no general intersectWith() function to find the points of
        intersection between two general curves. This can only be done by constructing an object of
        this class. Objects of this class are constructed by specifying the two curves that are to
        be intersected. It is also possible to specify a specific interval of each curve that is to
        be intersected. Pointers to these curves are then stored as data members of this class.
        This class contains query methods that return the intersection points and intervals of
        overlap between the two curves. There are also methods that return information about each
        intersection point, such as whether the intersection is a tangential or transversal
        intersection. Points of self-intersection of a curve can be found by passing the same curve
        in both parameters of the constructor.
        """
    @overload
    def __init__(self, curve1: PyGe.Curve2d, curve2: PyGe.Curve2d, tol: PyGe.Tol, /) -> None:
        """
        Represents the intersection set of two curves. There are special case intersectWith()
        functions in the AcGeLinearEnt2d, AcGeCircArc2d, and AcGeEllipArc2d classes to find the
        points of intersection between two lines, a line and an arc, an arc and an arc, or a line
        and an ellipse. However, there is no general intersectWith() function to find the points of
        intersection between two general curves. This can only be done by constructing an object of
        this class. Objects of this class are constructed by specifying the two curves that are to
        be intersected. It is also possible to specify a specific interval of each curve that is to
        be intersected. Pointers to these curves are then stored as data members of this class.
        This class contains query methods that return the intersection points and intervals of
        overlap between the two curves. There are also methods that return information about each
        intersection point, such as whether the intersection is a tangential or transversal
        intersection. Points of self-intersection of a curve can be found by passing the same curve
        in both parameters of the constructor.
        """
    @overload
    def __init__(
        self,
        curve1: PyGe.Curve2d,
        curve2: PyGe.Curve2d,
        range1: PyGe.Interval,
        range2: PyGe.Interval,
        /,
    ) -> None:
        """
        Represents the intersection set of two curves. There are special case intersectWith()
        functions in the AcGeLinearEnt2d, AcGeCircArc2d, and AcGeEllipArc2d classes to find the
        points of intersection between two lines, a line and an arc, an arc and an arc, or a line
        and an ellipse. However, there is no general intersectWith() function to find the points of
        intersection between two general curves. This can only be done by constructing an object of
        this class. Objects of this class are constructed by specifying the two curves that are to
        be intersected. It is also possible to specify a specific interval of each curve that is to
        be intersected. Pointers to these curves are then stored as data members of this class.
        This class contains query methods that return the intersection points and intervals of
        overlap between the two curves. There are also methods that return information about each
        intersection point, such as whether the intersection is a tangential or transversal
        intersection. Points of self-intersection of a curve can be found by passing the same curve
        in both parameters of the constructor.
        """
    @overload
    def __init__(
        self,
        curve1: PyGe.Curve2d,
        curve2: PyGe.Curve2d,
        range1: PyGe.Interval,
        range2: PyGe.Interval,
        tol: PyGe.Tol,
        /,
    ) -> None:
        """
        Represents the intersection set of two curves. There are special case intersectWith()
        functions in the AcGeLinearEnt2d, AcGeCircArc2d, and AcGeEllipArc2d classes to find the
        points of intersection between two lines, a line and an arc, an arc and an arc, or a line
        and an ellipse. However, there is no general intersectWith() function to find the points of
        intersection between two general curves. This can only be done by constructing an object of
        this class. Objects of this class are constructed by specifying the two curves that are to
        be intersected. It is also possible to specify a specific interval of each curve that is to
        be intersected. Pointers to these curves are then stored as data members of this class.
        This class contains query methods that return the intersection points and intervals of
        overlap between the two curves. There are also methods that return information about each
        intersection point, such as whether the intersection is a tangential or transversal
        intersection. Points of self-intersection of a curve can be found by passing the same curve
        in both parameters of the constructor.
        """
    @overload
    def __init__(self, *args) -> None:
        """
        Represents the intersection set of two curves. There are special case intersectWith()
        functions in the AcGeLinearEnt2d, AcGeCircArc2d, and AcGeEllipArc2d classes to find the
        points of intersection between two lines, a line and an arc, an arc and an arc, or a line
        and an ellipse. However, there is no general intersectWith() function to find the points of
        intersection between two general curves. This can only be done by constructing an object of
        this class. Objects of this class are constructed by specifying the two curves that are to
        be intersected. It is also possible to specify a specific interval of each curve that is to
        be intersected. Pointers to these curves are then stored as data members of this class.
        This class contains query methods that return the intersection points and intervals of
        overlap between the two curves. There are also methods that return information about each
        intersection point, such as whether the intersection is a tangential or transversal
        intersection. Points of self-intersection of a curve can be found by passing the same curve
        in both parameters of the constructor.
        """
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def cast(otherObject: PyGe.Entity2d, /) -> CurveCurveInt2d: ...
    def changeCurveOrder(self, /) -> None: ...
    @staticmethod
    def className() -> str: ...
    @staticmethod
    def copycast(otherObject: PyGe.Entity2d, /) -> CurveCurveInt2d: ...
    def curve1(self, /) -> Curve2d: ...
    def curve2(self, /) -> Curve2d: ...
    def getIntConfigs(self, intNum: int, /) -> tuple: ...
    def getIntParams(self, intNum: int, /) -> tuple[float, float]: ...
    def getIntRanges(self, /) -> tuple[PyGe.Interval, PyGe.Interval]: ...
    def getOverlapRanges(self, intNum: int, /) -> tuple[PyGe.Interval, PyGe.Interval]: ...
    def getPointOnCurve1(self, intNum: int, /) -> PointOnCurve2d: ...
    def getPointOnCurve2(self, intNum: int, /) -> PointOnCurve2d: ...
    def intPoint(self, intNum: int, /) -> Point2d: ...
    def intPointTol(self, intNum: int, /) -> float: ...
    def isTangential(self, intNum: int, /) -> bool: ...
    def isTransversal(self, intNum: int, /) -> bool: ...
    def numIntPoints(self, /) -> int: ...
    def orderWrt1(self, /) -> CurveCurveInt2d: ...
    def orderWrt2(self, /) -> CurveCurveInt2d: ...
    def overlapCount(self, /) -> int: ...
    def overlapDirection(self, /) -> bool: ...
    def tolerance(self, /) -> Tol: ...

class CurveCurveInt3d(PyGe.Entity3d):
    @overload
    def __init__(self, /) -> None:
        """
        Represents the intersection set of two curves. There are special case intersectWith()
        functions in the AcGeLinearEnt3d, AcGeCircArc3d, and AcGeEllipArc3d classes to find the
        points of intersection between two lines, a line and an arc, an arc and an arc, or a line
        and an ellipse. However, there is no general intersectWith() function to find the points of
        intersection between two general curves. This can only be done by constructing an object of
        this class. Objects of this class are constructed by specifying the two curves that are to
        be intersected. It is also possible to specify a specific interval of each curve that is to
        be intersected. Pointers to these curves are then stored as data members of this class.
        This class contains query methods that return the intersection points and intervals of
        overlap between the two curves. There are also methods that return information about each
        intersection point, such as whether the intersection is a tangential or transversal
        intersection. Points of self-intersection of a curve can be found by passing the same curve
        in both parameters of the constructor.
        """
    @overload
    def __init__(self, curve1: PyGe.Curve3d, curve2: PyGe.Curve3d, /) -> None:
        """
        Represents the intersection set of two curves. There are special case intersectWith()
        functions in the AcGeLinearEnt3d, AcGeCircArc3d, and AcGeEllipArc3d classes to find the
        points of intersection between two lines, a line and an arc, an arc and an arc, or a line
        and an ellipse. However, there is no general intersectWith() function to find the points of
        intersection between two general curves. This can only be done by constructing an object of
        this class. Objects of this class are constructed by specifying the two curves that are to
        be intersected. It is also possible to specify a specific interval of each curve that is to
        be intersected. Pointers to these curves are then stored as data members of this class.
        This class contains query methods that return the intersection points and intervals of
        overlap between the two curves. There are also methods that return information about each
        intersection point, such as whether the intersection is a tangential or transversal
        intersection. Points of self-intersection of a curve can be found by passing the same curve
        in both parameters of the constructor.
        """
    @overload
    def __init__(
        self,
        curve1: PyGe.Curve3d,
        curve2: PyGe.Curve3d,
        planeNormal: PyGe.Vector3d,
        tol: PyGe.Tol,
        /,
    ) -> None:
        """
        Represents the intersection set of two curves. There are special case intersectWith()
        functions in the AcGeLinearEnt3d, AcGeCircArc3d, and AcGeEllipArc3d classes to find the
        points of intersection between two lines, a line and an arc, an arc and an arc, or a line
        and an ellipse. However, there is no general intersectWith() function to find the points of
        intersection between two general curves. This can only be done by constructing an object of
        this class. Objects of this class are constructed by specifying the two curves that are to
        be intersected. It is also possible to specify a specific interval of each curve that is to
        be intersected. Pointers to these curves are then stored as data members of this class.
        This class contains query methods that return the intersection points and intervals of
        overlap between the two curves. There are also methods that return information about each
        intersection point, such as whether the intersection is a tangential or transversal
        intersection. Points of self-intersection of a curve can be found by passing the same curve
        in both parameters of the constructor.
        """
    @overload
    def __init__(
        self,
        curve1: PyGe.Curve3d,
        curve2: PyGe.Curve3d,
        range1: PyGe.Interval,
        range2: PyGe.Interval,
        /,
    ) -> None:
        """
        Represents the intersection set of two curves. There are special case intersectWith()
        functions in the AcGeLinearEnt3d, AcGeCircArc3d, and AcGeEllipArc3d classes to find the
        points of intersection between two lines, a line and an arc, an arc and an arc, or a line
        and an ellipse. However, there is no general intersectWith() function to find the points of
        intersection between two general curves. This can only be done by constructing an object of
        this class. Objects of this class are constructed by specifying the two curves that are to
        be intersected. It is also possible to specify a specific interval of each curve that is to
        be intersected. Pointers to these curves are then stored as data members of this class.
        This class contains query methods that return the intersection points and intervals of
        overlap between the two curves. There are also methods that return information about each
        intersection point, such as whether the intersection is a tangential or transversal
        intersection. Points of self-intersection of a curve can be found by passing the same curve
        in both parameters of the constructor.
        """
    @overload
    def __init__(
        self,
        curve1: PyGe.Curve3d,
        curve2: PyGe.Curve3d,
        range1: PyGe.Interval,
        range2: PyGe.Interval,
        tol: PyGe.Tol,
        /,
    ) -> None:
        """
        Represents the intersection set of two curves. There are special case intersectWith()
        functions in the AcGeLinearEnt3d, AcGeCircArc3d, and AcGeEllipArc3d classes to find the
        points of intersection between two lines, a line and an arc, an arc and an arc, or a line
        and an ellipse. However, there is no general intersectWith() function to find the points of
        intersection between two general curves. This can only be done by constructing an object of
        this class. Objects of this class are constructed by specifying the two curves that are to
        be intersected. It is also possible to specify a specific interval of each curve that is to
        be intersected. Pointers to these curves are then stored as data members of this class.
        This class contains query methods that return the intersection points and intervals of
        overlap between the two curves. There are also methods that return information about each
        intersection point, such as whether the intersection is a tangential or transversal
        intersection. Points of self-intersection of a curve can be found by passing the same curve
        in both parameters of the constructor.
        """
    @overload
    def __init__(self, *args) -> None:
        """
        Represents the intersection set of two curves. There are special case intersectWith()
        functions in the AcGeLinearEnt3d, AcGeCircArc3d, and AcGeEllipArc3d classes to find the
        points of intersection between two lines, a line and an arc, an arc and an arc, or a line
        and an ellipse. However, there is no general intersectWith() function to find the points of
        intersection between two general curves. This can only be done by constructing an object of
        this class. Objects of this class are constructed by specifying the two curves that are to
        be intersected. It is also possible to specify a specific interval of each curve that is to
        be intersected. Pointers to these curves are then stored as data members of this class.
        This class contains query methods that return the intersection points and intervals of
        overlap between the two curves. There are also methods that return information about each
        intersection point, such as whether the intersection is a tangential or transversal
        intersection. Points of self-intersection of a curve can be found by passing the same curve
        in both parameters of the constructor.
        """
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def cast(otherObject: PyGe.Entity3d, /) -> CurveCurveInt3d: ...
    def changeCurveOrder(self, /) -> None: ...
    @staticmethod
    def className() -> str: ...
    @staticmethod
    def copycast(otherObject: PyGe.Entity3d, /) -> CurveCurveInt3d: ...
    def curve1(self, /) -> Curve3d: ...
    def curve2(self, /) -> Curve3d: ...
    def getIntConfigs(self, intNum: int, /) -> tuple: ...
    def getIntParams(self, intNum: int, /) -> tuple[float, float]: ...
    def getIntRanges(self, /) -> tuple[PyGe.Interval, PyGe.Interval]: ...
    def getOverlapRanges(self, intNum: int, /) -> tuple[PyGe.Interval, PyGe.Interval]: ...
    def getPointOnCurve1(self, intNum: int, /) -> PointOnCurve3d: ...
    def getPointOnCurve2(self, intNum: int, /) -> PointOnCurve3d: ...
    def intPoint(self, intNum: int, /) -> Point3d: ...
    def intPointTol(self, intNum: int, /) -> float: ...
    def isTangential(self, intNum: int, /) -> bool: ...
    def isTransversal(self, intNum: int, /) -> bool: ...
    def numIntPoints(self, /) -> int: ...
    def orderWrt1(self, /) -> CurveCurveInt3d: ...
    def orderWrt2(self, /) -> CurveCurveInt3d: ...
    def overlapCount(self, /) -> int: ...
    def overlapDirection(self, /) -> bool: ...
    def planeNormal(self, /) -> Vector3d: ...
    def set(self, c1: PyGe.Curve3d, c2: PyGe.Curve3d, /) -> None: ...
    def tolerance(self, /) -> Tol: ...

class CurveSurfInt(PyGe.Entity3d):
    @overload
    def __init__(self, /) -> None:
        """
        This class holds data for intersections of a 3D curve and a surface.
        """
    @overload
    def __init__(self, curve: PyGe.Curve3d, surf: PyGe.Surface, /) -> None:
        """
        This class holds data for intersections of a 3D curve and a surface.
        """
    @overload
    def __init__(self, curve: PyGe.Curve3d, surf: PyGe.Surface, tol: PyGe.Tol, /) -> None:
        """
        This class holds data for intersections of a 3D curve and a surface.
        """
    @overload
    def __init__(self, *args) -> None:
        """
        This class holds data for intersections of a 3D curve and a surface.
        """
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def cast(otherObject: PyGe.Entity3d, /) -> CurveSurfInt: ...
    @staticmethod
    def className() -> str: ...
    @staticmethod
    def copycast(otherObject: PyGe.Entity3d, /) -> CurveSurfInt: ...
    def curve(self, /) -> Curve3d: ...
    def getIntConfigs(self, intNum: int, /) -> tuple: ...
    def getIntParams(self, intNum: int, /) -> tuple[float, PyGe.Point2d]: ...
    def getPointOnCurve(self, intNum: int, /) -> PointOnCurve3d: ...
    def getPointOnSurface(self, intNum: int, /) -> PointOnSurface: ...
    def intPoint(self, intNum: int, /) -> Point3d: ...
    def numIntPoints(self, /) -> int: ...
    @overload
    def set(self, curve: PyGe.Curve3d, surf: PyGe.Surface, /) -> None: ...
    @overload
    def set(self, curve: PyGe.Curve3d, surf: PyGe.Surface, tol: PyGe.Tol, /) -> None: ...
    @overload
    def set(self, *args) -> None: ...
    def surface(self, /) -> PyGe.Surface: ...
    def tolerance(self, /) -> Tol: ...

class Cylinder(PyGe.Surface):
    @overload
    def __init__(self, /) -> None:
        """
        Represents a bounded cylinder surface.
        """
    @overload
    def __init__(
        self, radius: float, origin: PyGe.Point3d, axisOfSymmetry: PyGe.Vector3d, /
    ) -> None:
        """
        Represents a bounded cylinder surface.
        """
    @overload
    def __init__(
        self,
        radius: float,
        origin: PyGe.Point3d,
        axisOfSymmetry: PyGe.Vector3d,
        refAxis: PyGe.Vector3d,
        height: PyGe.Interval,
        startAngle: float,
        endAngle: float,
        /,
    ) -> None:
        """
        Represents a bounded cylinder surface.
        """
    @overload
    def __init__(self, *args) -> None:
        """
        Represents a bounded cylinder surface.
        """
    def __reduce__(self, /) -> Any: ...
    def axisOfSymmetry(self, /) -> Vector3d: ...
    @staticmethod
    def cast(otherObject: PyGe.Entity3d, /) -> Cylinder: ...
    @staticmethod
    def className() -> str: ...
    @staticmethod
    def copycast(otherObject: PyGe.Entity3d, /) -> Cylinder: ...
    def getAngles(self, /) -> tuple[float, float]: ...
    def getHeight(self, /) -> Interval: ...
    def heightAt(self, u: float, /) -> float: ...
    def intersectWith(
        self, val: PyGe.LinearEnt3d, tol: PyGe.Tol = ..., /
    ) -> tuple[bool, int, PyGe.Point3d, PyGe.Point3d]: ...
    def isClosed(self, tol: PyGe.Tol = ..., /) -> bool: ...
    def isOuterNormal(self, /) -> bool: ...
    def origin(self, /) -> Point3d: ...
    def radius(self, /) -> float: ...
    def refAxis(self, /) -> Vector3d: ...
    @overload
    def set(
        self, radius: float, origin: PyGe.Point3d, axisOfSymmetry: PyGe.Vector3d, /
    ) -> None: ...
    @overload
    def set(
        self,
        radius: float,
        origin: PyGe.Point3d,
        axisOfSymmetry: PyGe.Vector3d,
        refAxis: PyGe.Vector3d,
        height: PyGe.Interval,
        startAngle: float,
        endAngle: float,
        /,
    ) -> None: ...
    @overload
    def set(self, *args) -> None: ...
    def setAngles(self, start: float, end: float, /) -> None: ...
    def setHeight(self, val: PyGe.Interval, /) -> None: ...
    def setRadius(self, val: float, /) -> None: ...

class EllipArc2d(PyGe.Curve2d):
    @overload
    def __init__(self, /) -> None:
        """
        Represents both full ellipses and elliptical arcs in 2D space.
        """
    @overload
    def __init__(self, carc: PyGe.CircArc2d, /) -> None:
        """
        Represents both full ellipses and elliptical arcs in 2D space.
        """
    @overload
    def __init__(
        self,
        cent: PyGe.Point2d,
        majorAxis: PyGe.Vector2d,
        minorAxis: PyGe.Vector2d,
        majorRadius: float,
        minorRadius: float,
        /,
    ) -> None:
        """
        Represents both full ellipses and elliptical arcs in 2D space.
        """
    @overload
    def __init__(
        self,
        cent: PyGe.Point2d,
        majorAxis: PyGe.Vector2d,
        minorAxis: PyGe.Vector2d,
        majorRadius: float,
        minorRadius: float,
        startAngle: float,
        endAngle: float,
        /,
    ) -> None:
        """
        Represents both full ellipses and elliptical arcs in 2D space.
        """
    @overload
    def __init__(self, *args) -> None:
        """
        Represents both full ellipses and elliptical arcs in 2D space.
        """
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def cast(otherObject: PyGe.Entity2d, /) -> EllipArc2d: ...
    def center(self, /) -> Point2d: ...
    @staticmethod
    def className() -> str: ...
    @staticmethod
    def copycast(otherObject: PyGe.Entity2d, /) -> EllipArc2d: ...
    def endAng(self, /) -> float: ...
    def endPoint(self, /) -> Point2d: ...
    def intersectWith(
        self, val: PyGe.LinearEnt2d, tol: PyGe.Tol = ..., /
    ) -> tuple[bool, int, PyGe.Point2d, PyGe.Point2d]: ...
    def isCircular(self, tol: PyGe.Tol = ..., /) -> bool: ...
    def isClockWise(self, /) -> bool: ...
    def isInside(self, pt: PyGe.Point2d, tol: PyGe.Tol = ..., /) -> bool: ...
    def majorAxis(self, /) -> Vector2d: ...
    def majorRadius(self, /) -> float: ...
    def minorAxis(self, /) -> Vector2d: ...
    def minorRadius(self, /) -> float: ...
    @overload
    def set(self, carc: PyGe.CircArc2d, /) -> None: ...
    @overload
    def set(
        self,
        cent: PyGe.Point2d,
        majorAxis: PyGe.Vector2d,
        minorAxis: PyGe.Vector2d,
        majorRadius: float,
        minorRadius: float,
        /,
    ) -> None: ...
    @overload
    def set(
        self,
        cent: PyGe.Point2d,
        majorAxis: PyGe.Vector2d,
        minorAxis: PyGe.Vector2d,
        majorRadius: float,
        minorRadius: float,
        startAngle: float,
        endAngle: float,
        /,
    ) -> None: ...
    @overload
    def set(self, *args) -> None: ...
    def setAngles(self, startAngle: float, endAngle: float, /) -> None: ...
    def setAxes(self, majorAxis: PyGe.Vector2d, minorAxis: PyGe.Vector2d, /) -> None: ...
    def setCenter(self, pt: PyGe.Point2d, /) -> None: ...
    def setMajorRadius(self, val: float, /) -> None: ...
    def setMinorRadius(self, val: float, /) -> None: ...
    def startAng(self, /) -> float: ...
    def startPoint(self, /) -> Point2d: ...

class EllipArc3d(PyGe.Curve3d):
    @overload
    def __init__(self, /) -> None:
        """
        Represents both full ellipses and elliptical arcs in 3D space.
        """
    @overload
    def __init__(self, carc: PyGe.CircArc3d, /) -> None:
        """
        Represents both full ellipses and elliptical arcs in 3D space.
        """
    @overload
    def __init__(
        self,
        cent: PyGe.Point3d,
        majorAxis: PyGe.Vector3d,
        minorAxis: PyGe.Vector3d,
        majorRadius: float,
        minorRadius: float,
        /,
    ) -> None:
        """
        Represents both full ellipses and elliptical arcs in 3D space.
        """
    @overload
    def __init__(
        self,
        cent: PyGe.Point3d,
        majorAxis: PyGe.Vector3d,
        minorAxis: PyGe.Vector3d,
        majorRadius: float,
        minorRadius: float,
        startAngle: float,
        endAngle: float,
        /,
    ) -> None:
        """
        Represents both full ellipses and elliptical arcs in 3D space.
        """
    @overload
    def __init__(self, *args) -> None:
        """
        Represents both full ellipses and elliptical arcs in 3D space.
        """
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def cast(otherObject: PyGe.Entity3d, /) -> EllipArc3d: ...
    def center(self, /) -> Point3d: ...
    @staticmethod
    def className() -> str: ...
    def closestPointToPlane(
        self, plane: PyGe.PlanarEnt, tol: PyGe.Tol = ..., /
    ) -> tuple[PyGe.Point3d, PyGe.Point3d]: ...
    @staticmethod
    def copycast(otherObject: PyGe.Entity3d, /) -> EllipArc3d: ...
    def endAng(self, /) -> float: ...
    def endPoint(self, /) -> Point3d: ...
    def getPlane(self, /) -> Plane: ...
    def intersectWith(
        self, other: PyGe.LinearEnt3d | PyGe.PlanarEnt, tol: PyGe.Tol = ..., /
    ) -> tuple[bool, int, PyGe.Point3d, PyGe.Point3d]: ...
    def isCircular(self, tol: PyGe.Tol = ..., /) -> bool: ...
    def isInside(self, pt: PyGe.Point3d, tol: PyGe.Tol = ..., /) -> bool: ...
    def majorAxis(self, /) -> Vector3d: ...
    def majorRadius(self, /) -> float: ...
    def minorAxis(self, /) -> Vector3d: ...
    def minorRadius(self, /) -> float: ...
    def normal(self, /) -> Vector3d: ...
    def projIntersectWith(
        self, other: PyGe.LinearEnt3d, projDir: PyGe.Vector3d, tol: PyGe.Tol = ..., /
    ) -> tuple: ...
    @overload
    def set(self, carc: PyGe.CircArc3d, /) -> None: ...
    @overload
    def set(
        self,
        cent: PyGe.Point3d,
        majorAxis: PyGe.Vector3d,
        minorAxis: PyGe.Vector3d,
        majorRadius: float,
        minorRadius: float,
        /,
    ) -> None: ...
    @overload
    def set(
        self,
        cent: PyGe.Point3d,
        majorAxis: PyGe.Vector3d,
        minorAxis: PyGe.Vector3d,
        majorRadius: float,
        minorRadius: float,
        startAngle: float,
        endAngle: float,
        /,
    ) -> None: ...
    @overload
    def set(self, *args) -> None: ...
    def setAngles(self, startAngle: float, endAngle: float, /) -> None: ...
    def setAxes(self, majorAxis: PyGe.Vector3d, minorAxis: PyGe.Vector3d, /) -> None: ...
    def setCenter(self, pt: PyGe.Point3d, /) -> None: ...
    def setMajorRadius(self, val: float, /) -> None: ...
    def setMinorRadius(self, val: float, /) -> None: ...
    def startAng(self, /) -> float: ...
    def startPoint(self, /) -> Point3d: ...

class Entity2d:
    def __hash__(self, /) -> int: ...
    def __init__(self) -> None:
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __ne__(self, /) -> bool: ...
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def className() -> str: ...
    def copy(self, /) -> Entity2d: ...
    @staticmethod
    def copycast(otherObject: PyGe.Entity2d, /) -> Entity2d: ...
    def isEqualTo(self, val: PyGe.Entity2d, tol: PyGe.Tol = ..., /) -> bool: ...
    def isKindOf(self, val: PyGe.EntityId, /) -> bool: ...
    def isNull(self, /) -> bool: ...
    def isOn(self, pt: PyGe.Point2d, tol: PyGe.Tol = ..., /) -> bool: ...
    def mirror(self, val: PyGe.Line2d, /) -> None: ...
    def rotateBy(self, angle: float, pt: PyGe.Point2d = PyGe.Point2d.kOrgin, /) -> None: ...
    def scaleBy(self, scaleFactor: float, pt: PyGe.Point2d = PyGe.Point2d.kOrgin, /) -> None: ...
    def transformBy(self, val: PyGe.Matrix2d, /) -> None: ...
    def translateBy(self, vec: PyGe.Vector2d, /) -> None: ...
    def type(self, /) -> EntityId: ...

class Entity3d:
    def __hash__(self, /) -> int: ...
    def __init__(self) -> None:
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __ne__(self, /) -> bool: ...
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def className() -> str: ...
    def copy(self, /) -> Entity3d:
        """
        Returns a pointer to a copy of this entity. This copy is created using the new and it is
        the responsibility of the caller to delete it.
        """
    @staticmethod
    def copycast(otherObject: PyGe.Entity3d, /) -> Entity3d: ...
    def isEqualTo(self, val: PyGe.Entity3d, tol: PyGe.Tol = ..., /) -> bool:
        """
        Determines if two entities are equal to each other. Two entities are considered to be equal
        only if they are of the same type and they represent the same 3D point set. For instance,
        if the two entities are of types AcGeCircArc3d and AcGeEllipArc3d then they are not
        considered equal even if the ellipse is completely coincident with the circle. Also, two
        curves are not considered equal unless they have the same parameterization. For instance,
        two infinite coincident lines are not considered equal if they have different scaling in
        their parameterization.
        """
    def isKindOf(self, val: PyGe.EntityId, /) -> bool: ...
    def isNull(self, /) -> bool: ...
    def isOn(self, pt: PyGe.Point3d, tol: PyGe.Tol = ..., /) -> bool:
        """
        Returns Adesk::kTrue if pnt lies on entity; otherwise, returns Adesk::kFalse.
        """
    def mirror(self, val: PyGe.Plane, /) -> None:
        """
        Transforms the entity by mirroring it across the input plane.
        """
    def rotateBy(self, angle: float, vec: PyGe.Vector3d, pt: PyGe.Point3d = "origin", /) -> None:
        """
        Rotates the entity by the input angle about the line defined by the input point and vector.
        """
    def scaleBy(self, scaleFactor: float, pt: PyGe.Point3d = "origin", /) -> None:
        """
        Scales the entity about the input point by the input scale factor. Input scale factor must
        be greater than 0.
        """
    def transformBy(self, val: PyGe.Matrix3d, /) -> None:
        """
        Transforms the entity by applying the input matrix.
        """
    def translateBy(self, vec: PyGe.Vector3d, /) -> None:
        """
        Translates the entity by the input vector.
        """
    def type(self, /) -> EntityId:
        """
        Returns the type of the entity.
        """

class EntityId(_BoostPythonEnum):
    kEntity2d: ClassVar[Self]  # 0
    kEntity3d: ClassVar[Self]  # 1
    kPointEnt2d: ClassVar[Self]  # 2
    kPointEnt3d: ClassVar[Self]  # 3
    kPosition2d: ClassVar[Self]  # 4
    kPosition3d: ClassVar[Self]  # 5
    kPointOnCurve2d: ClassVar[Self]  # 6
    kPointOnCurve3d: ClassVar[Self]  # 7
    kPointOnSurface: ClassVar[Self]  # 8
    kBoundedPlane: ClassVar[Self]  # 9
    kCircArc2d: ClassVar[Self]  # 10
    kCircArc3d: ClassVar[Self]  # 11
    kConic2d: ClassVar[Self]  # 12
    kConic3d: ClassVar[Self]  # 13
    kCurve2d: ClassVar[Self]  # 14
    kCurve3d: ClassVar[Self]  # 15
    kEllipArc2d: ClassVar[Self]  # 16
    kEllipArc3d: ClassVar[Self]  # 17
    kLine2d: ClassVar[Self]  # 18
    kLine3d: ClassVar[Self]  # 19
    kLinearEnt2d: ClassVar[Self]  # 20
    kLinearEnt3d: ClassVar[Self]  # 21
    kLineSeg2d: ClassVar[Self]  # 22
    kLineSeg3d: ClassVar[Self]  # 23
    kPlanarEnt: ClassVar[Self]  # 24
    kPlane: ClassVar[Self]  # 25
    kRay2d: ClassVar[Self]  # 26
    kRay3d: ClassVar[Self]  # 27
    kSurface: ClassVar[Self]  # 28
    kSphere: ClassVar[Self]  # 29
    kCylinder: ClassVar[Self]  # 30
    kTorus: ClassVar[Self]  # 31
    kCone: ClassVar[Self]  # 32
    kSplineEnt2d: ClassVar[Self]  # 33
    kPolyline2d: ClassVar[Self]  # 34
    kAugPolyline2d: ClassVar[Self]  # 35
    kNurbCurve2d: ClassVar[Self]  # 36
    kDSpline2d: ClassVar[Self]  # 37
    kCubicSplineCurve2d: ClassVar[Self]  # 38
    kSplineEnt3d: ClassVar[Self]  # 39
    kPolyline3d: ClassVar[Self]  # 40
    kAugPolyline3d: ClassVar[Self]  # 41
    kNurbCurve3d: ClassVar[Self]  # 42
    kDSpline3d: ClassVar[Self]  # 43
    kCubicSplineCurve3d: ClassVar[Self]  # 44
    kTrimmedCrv2d: ClassVar[Self]  # 45
    kCompositeCrv2d: ClassVar[Self]  # 46
    kCompositeCrv3d: ClassVar[Self]  # 47
    kExternalSurface: ClassVar[Self]  # 48
    kNurbSurface: ClassVar[Self]  # 49
    kTrimmedSurface: ClassVar[Self]  # 50
    kOffsetSurface: ClassVar[Self]  # 51
    kEnvelope2d: ClassVar[Self]  # 52
    kCurveBoundedSurface: ClassVar[Self]  # 53
    kExternalCurve3d: ClassVar[Self]  # 54
    kExternalCurve2d: ClassVar[Self]  # 55
    kSurfaceCurve2dTo3d: ClassVar[Self]  # 56
    kSurfaceCurve3dTo2d: ClassVar[Self]  # 57
    kExternalBoundedSurface: ClassVar[Self]  # 58
    kCurveCurveInt2d: ClassVar[Self]  # 59
    kCurveCurveInt3d: ClassVar[Self]  # 60
    kBoundBlock2d: ClassVar[Self]  # 61
    kBoundBlock3d: ClassVar[Self]  # 62
    kOffsetCurve2d: ClassVar[Self]  # 63
    kOffsetCurve3d: ClassVar[Self]  # 64
    kPolynomCurve3d: ClassVar[Self]  # 65
    kBezierCurve3d: ClassVar[Self]  # 66
    kObject: ClassVar[Self]  # 67
    kFitData3d: ClassVar[Self]  # 68
    kHatch: ClassVar[Self]  # 69
    kTrimmedCurve2d: ClassVar[Self]  # 70
    kTrimmedCurve3d: ClassVar[Self]  # 71
    kCurveSampleData: ClassVar[Self]  # 72
    kEllipCone: ClassVar[Self]  # 73
    kEllipCylinder: ClassVar[Self]  # 74
    kIntervalBoundBlock: ClassVar[Self]  # 75
    kClipBoundary2d: ClassVar[Self]  # 76
    kExternalObject: ClassVar[Self]  # 77
    kCurveSurfaceInt: ClassVar[Self]  # 78
    kSurfaceSurfaceInt: ClassVar[Self]  # 79
    Helix: ClassVar[Self]  # 80

class ExternalBoundedSurface(PyGe.Surface):
    def __init__(self, /) -> None:
        """
        AcGeExternalBoundedSurface class is a representation of a bounded surface defined outside
        of the geometry library. A logical view of this class is as follows: An instance of
        AcGeExternalBoundedSurface consists of an instance of AcGeExternalSurface representing the
        unbounded surface geometry, together with a collection of instances of AcGeCurveBoundary,
        each representing a boundary on the unbounded surface. It is important to realize that the
        representation is geometric. No topological information is represented in this class. This
        assertion is made explicit by deriving this class from AcGeSurface. A typical use of
        AcGeExternalBoundedSurface would be to represent an ACIS FACE (that is, faces on Designer
        and Autosurf models) as a bounded surface. Clearly, an instance of
        AcGeExternalBoundedSurface can be used as any other AcGeSurface. Operations that are well
        defined on bounded surfaces can accommodate the boundaries within the algorithms (an
        example is closest point). Alternatively, a knowledge of the precise definition of the
        external entity allows direct access to the external entity in its native form. This access
        is more efficient because it avoids the level of indirection that is incurred when
        accessing the external entity through GeLib interface.
        """
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def cast(otherObject: PyGe.Entity3d, /) -> ExternalBoundedSurface: ...
    @staticmethod
    def className() -> str: ...
    @staticmethod
    def copycast(otherObject: PyGe.Entity3d, /) -> ExternalBoundedSurface: ...

class ExternalCurve2d(PyGe.Curve2d):
    def __init__(self) -> None:
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def cast(otherObject: PyGe.Entity2d, /) -> ExternalCurve2d: ...
    @staticmethod
    def className() -> str: ...
    @staticmethod
    def copycast(otherObject: PyGe.Entity2d, /) -> ExternalCurve2d: ...

class ExternalCurve3d(PyGe.Curve3d):
    def __init__(self) -> None:
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def cast(otherObject: PyGe.Entity3d, /) -> ExternalCurve3d: ...
    @staticmethod
    def className() -> str: ...
    @staticmethod
    def copycast(otherObject: PyGe.Entity3d, /) -> ExternalCurve3d: ...
    def externalCurveKind(self, /) -> ExternalEntityKind: ...
    def getNativeCurve(self, /) -> Curve3d: ...
    def isCircArc(self, /) -> bool: ...
    def isDefined(self, /) -> bool: ...
    def isEllipArc(self, /) -> bool: ...
    def isLine(self, /) -> bool: ...
    def isLineSeg(self, /) -> bool: ...
    def isNurbCurve(self, /) -> bool: ...
    def isOwnerOfCurve(self, /) -> bool: ...
    def isRay(self, /) -> bool: ...
    def setToOwnCurve(self, /) -> None: ...

class ExternalEntityKind(_BoostPythonEnum):
    kAcisEntity: ClassVar[Self]  # 0
    kExternalEntityUndefined: ClassVar[Self]  # 1

class ExternalSurface(PyGe.Surface):
    def __init__(self, /) -> None:
        """
        AcGeExternalSurface class is a representation for an unbounded (other than by the
        parametric bounds of the surface) surface geometry that has its definition external to
        GeLib. Since AcGeExternalSurface is a AcGeSurface, these external entities can be treated
        as any other GeLib surface. Certain external surface points sets may have corresponding
        native representations in GeLib. In such cases, it is possible to obtain such GeLib
        representations. However, the surface definitions of native GeLib surfaces differ from the
        definition of external entities. An example of such a difference is differing surface
        parameterizations. A typical use of AcGeExternalSurface is to represent a ShapeManager
        surface. Clearly, an instance of AcGeExternalSurface can be used as any other AcGeSurface.
        Alternatively, a knowledge of the precise definition of the external entity allows direct
        access to the external entity in its native form. This access is more efficient since it
        avoids the level of indirection that is incurred when accessing the external entity through
        GeLib interface.
        """
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def cast(otherObject: PyGe.Entity3d, /) -> ExternalSurface: ...
    @staticmethod
    def className() -> str: ...
    @staticmethod
    def copycast(otherObject: PyGe.Entity3d, /) -> ExternalSurface: ...

class Interval:
    def __ge__(self, val: PyGe.Interval | float, /) -> bool: ...
    def __gt__(self, val: PyGe.Interval | float, /) -> bool: ...
    @overload
    def __init__(self, /) -> None:
        """
        Represents a finite or semi-infinite interval as the real axis whose bounds are defined
        with some given tolerance.
        """
    @overload
    def __init__(self, lower: float, upper: float, /) -> None:
        """
        Represents a finite or semi-infinite interval as the real axis whose bounds are defined
        with some given tolerance.
        """
    @overload
    def __init__(self, bounded: bool, upper: float, /) -> None:
        """
        Represents a finite or semi-infinite interval as the real axis whose bounds are defined
        with some given tolerance.
        """
    @overload
    def __init__(self, *args) -> None:
        """
        Represents a finite or semi-infinite interval as the real axis whose bounds are defined
        with some given tolerance.
        """
    def __le__(self, val: PyGe.Interval | float, /) -> bool: ...
    def __lt__(self, val: PyGe.Interval | float, /) -> bool: ...
    def __ne__(self, val: PyGe.Interval, /) -> bool: ...
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def className() -> str: ...
    def contains(self, val: PyGe.Interval | float, /) -> bool: ...
    def element(self, /) -> float: ...
    def getBounds(self, /) -> tuple[float, float]: ...
    def getMerge(self, val: float, /) -> Interval: ...
    def intersectWith(self, val: PyGe.Interval, /) -> tuple[bool, PyGe.Interval]: ...
    def isBounded(self, /) -> bool: ...
    def isBoundedAbove(self, /) -> bool: ...
    def isBoundedBelow(self, /) -> bool: ...
    def isContinuousAtUpper(self, val: PyGe.Interval, /) -> bool: ...
    def isDisjoint(self, val: PyGe.Interval, /) -> bool: ...
    def isEqualAtLower(self, val: PyGe.Interval | float, /) -> bool: ...
    def isEqualAtUpper(self, val: PyGe.Interval | float, /) -> bool: ...
    def isGreater(self, val: PyGe.Interval | float, /) -> bool: ...
    def isGreaterOrEqual(self, val: PyGe.Interval | float, /) -> bool: ...
    def isLess(self, val: PyGe.Interval | float, /) -> bool: ...
    def isLessOrEqual(self, val: PyGe.Interval | float, /) -> bool: ...
    def isOverlapAtUpper(self, val: PyGe.Interval, /) -> tuple[bool, PyGe.Interval]: ...
    def isPeriodicallyOn(self, val: float, /) -> tuple[bool, float]: ...
    def isSingleton(self, /) -> bool: ...
    def isUnBounded(self, /) -> bool: ...
    def length(self, /) -> float: ...
    def lowerBound(self, /) -> float: ...
    @overload
    def set(self, /) -> None: ...
    @overload
    def set(self, lower: float, upper: float, /) -> None: ...
    @overload
    def set(self, bounded: bool, upper: float, /) -> None: ...
    @overload
    def set(self, *args) -> None: ...
    def setLower(self, val: float, /) -> None: ...
    def setTolerance(self, val: float, /) -> None: ...
    def setUpper(self, val: float, /) -> None: ...
    def subtract(self, val: PyGe.Interval, /) -> tuple[int, PyGe.Interval, PyGe.Interval]: ...
    def tolerance(self, /) -> float: ...
    def upperBound(self, /) -> float: ...

class KnotParameterization(_BoostPythonEnum):
    kChord: ClassVar[Self]  # 0
    kSqrtChord: ClassVar[Self]  # 1
    kUniform: ClassVar[Self]  # 2
    kCustomParameterization: ClassVar[Self]  # 15
    kNotDefinedKnotParam: ClassVar[Self]  # 16

class KnotVector:
    @overload
    def __init__(self, /) -> None:
        """
        Represents an ordered non-decreasing sequence of numbers used in several spline entities.
        """
    @overload
    def __init__(self, size: int, growSize: int, /) -> None:
        """
        Represents an ordered non-decreasing sequence of numbers used in several spline entities.
        """
    @overload
    def __init__(self, data: list[float], /) -> None:
        """
        Represents an ordered non-decreasing sequence of numbers used in several spline entities.
        """
    @overload
    def __init__(self, plusMult: int, other: PyGe.KnotVector, /) -> None:
        """
        Represents an ordered non-decreasing sequence of numbers used in several spline entities.
        """
    @overload
    def __init__(self, *args) -> None:
        """
        Represents an ordered non-decreasing sequence of numbers used in several spline entities.
        """
    def __reduce__(self, /) -> Any: ...
    @overload
    def append(self, val: float, /) -> int: ...
    @overload
    def append(self, tail: PyGe.KnotVector, /) -> int: ...
    @overload
    def append(self, tail: PyGe.KnotVector, knotRatio: float, /) -> int: ...
    @overload
    def append(self, *args) -> int: ...
    @staticmethod
    def className() -> str: ...
    def contains(self, param: float, /) -> bool: ...
    def endParam(self, /) -> float: ...
    def getDistinctKnots(self, /) -> list[float]: ...
    def getInterval(self, ord: int, param: float, /) -> tuple[int, PyGe.Interval]: ...
    def growLength(self, /) -> int: ...
    def insert(self, u: float, /) -> None: ...
    def insertAt(self, idx: int, u: float, multiplicity: int, /) -> None: ...
    def isEmpty(self, /) -> bool: ...
    def isEqualTo(self, other: PyGe.KnotVector, /) -> bool: ...
    def isOn(self, knot: float, /) -> bool: ...
    def length(self, /) -> int: ...
    def logicalLength(self, /) -> int: ...
    def multiplicityAt(self, idx: int, /) -> int: ...
    def multiplicityAtParam(self, param: float, /) -> int: ...
    def numIntervals(self, /) -> int: ...
    def physicalLength(self, /) -> int: ...
    def removeAt(self, idx: int, /) -> None: ...
    def removeSubVector(self, start: int, end: int, /) -> None: ...
    def reverse(self, /) -> None: ...
    def setGrowLength(self, length: int, /) -> None: ...
    def setLogicalLength(self, length: int, /) -> None: ...
    def setPhysicalLength(self, length: int, /) -> None: ...
    def setRange(self, lower: float, upper: float, /) -> None: ...
    def setTolerance(self, tol: float, /) -> None: ...
    def split(
        self, param: float, multilast: int, multifirst: int, /
    ) -> tuple[PyGe.KnotVector, PyGe.KnotVector]: ...
    def startParam(self, /) -> float: ...
    def tolerance(self, /) -> float: ...

class Line2d(PyGe.LinearEnt2d):
    @overload
    def __init__(self, /) -> None:
        """
        Represents an unbounded line in 2D space.
        """
    @overload
    def __init__(self, start: PyGe.Point3d, direction: PyGe.Vector2d, /) -> None:
        """
        Represents an unbounded line in 2D space.
        """
    @overload
    def __init__(self, start: PyGe.Point3d, end: PyGe.Point3d, /) -> None:
        """
        Represents an unbounded line in 2D space.
        """
    @overload
    def __init__(self, *args) -> None:
        """
        Represents an unbounded line in 2D space.
        """
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def cast(otherObject: PyGe.Entity2d, /) -> Line2d: ...
    @staticmethod
    def className() -> str: ...
    @staticmethod
    def copycast(otherObject: PyGe.Entity2d, /) -> Line2d: ...
    kXAxis: PyGe.Line2d
    kYAxis: PyGe.Line2d
    @overload
    def set(self, start: PyGe.Point3d, direction: PyGe.Vector2d, /) -> None: ...
    @overload
    def set(self, start: PyGe.Point3d, end: PyGe.Point3d, /) -> None: ...
    @overload
    def set(self, *args) -> None: ...

class Line3d(PyGe.LinearEnt3d):
    @overload
    def __init__(self, /) -> None:
        """
        Represents an unbounded line in 3D space.
        """
    @overload
    def __init__(self, startPoint: PyGe.Point3d, endPoint: PyGe.Point3d, /) -> None:
        """
        Represents an unbounded line in 3D space.
        """
    @overload
    def __init__(self, startPoint: PyGe.Point3d, direction: PyGe.Vector3d, /) -> None:
        """
        Represents an unbounded line in 3D space.
        """
    @overload
    def __init__(self, *args) -> None:
        """
        Represents an unbounded line in 3D space.
        """
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def cast(otherObject: PyGe.Entity3d, /) -> Line3d: ...
    @staticmethod
    def className() -> str: ...
    @staticmethod
    def copycast(otherObject: PyGe.Entity3d, /) -> Line3d: ...
    kXAxis: PyGe.Line3d
    kYAxis: PyGe.Line3d
    kZAxis: PyGe.Line3d
    @overload
    def set(self, startPoint: PyGe.Point3d, endPoint: PyGe.Point3d, /) -> None: ...
    @overload
    def set(self, startPoint: PyGe.Point3d, direction: PyGe.Vector3d, /) -> None: ...
    @overload
    def set(self, *args) -> None: ...

class LineSeg2d(PyGe.LinearEnt2d):
    @overload
    def __init__(self, /) -> None:
        """
        Represents a bounded line segment in 2D space.
        """
    @overload
    def __init__(self, start: PyGe.Point3d, direction: PyGe.Vector2d, /) -> None:
        """
        Represents a bounded line segment in 2D space.
        """
    @overload
    def __init__(self, start: PyGe.Point3d, end: PyGe.Point3d, /) -> None:
        """
        Represents a bounded line segment in 2D space.
        """
    @overload
    def __init__(self, *args) -> None:
        """
        Represents a bounded line segment in 2D space.
        """
    def __reduce__(self, /) -> Any: ...
    def baryComb(self, blendCoeff: float, /) -> Point2d: ...
    @staticmethod
    def cast(otherObject: PyGe.Entity2d, /) -> LineSeg2d: ...
    @staticmethod
    def className() -> str: ...
    @staticmethod
    def copycast(otherObject: PyGe.Entity2d, /) -> LineSeg2d: ...
    def endPoint(self, /) -> Point2d: ...
    def getBisector(self, /) -> Line2d: ...
    @overload
    def length(self, /) -> float: ...
    @overload
    def length(self, fromParam: float, toParam: float, /) -> float: ...
    @overload
    def length(self, fromParam: float, toParam: float, tol: float, /) -> float: ...
    @overload
    def length(self, *args) -> float: ...
    def midPoint(self, /) -> Point2d: ...
    @overload
    def set(self, start: PyGe.Point3d, direction: PyGe.Vector2d, /) -> None: ...
    @overload
    def set(self, start: PyGe.Point3d, end: PyGe.Point3d, /) -> None: ...
    @overload
    def set(self, curve1: PyGe.Curve2d, curve2: PyGe.Curve2d, /) -> None: ...
    @overload
    def set(self, curve1: PyGe.Curve2d, pnt: PyGe.Point3d, /) -> None: ...
    @overload
    def set(self, *args) -> None: ...
    def startPoint(self, /) -> Point2d: ...

class LineSeg3d(PyGe.LinearEnt3d):
    @overload
    def __init__(self, /) -> None:
        """
        Represents a bounded line segment in 3D space.
        """
    @overload
    def __init__(self, startPoint: PyGe.Point3d, endPoint: PyGe.Point3d, /) -> None:
        """
        Represents a bounded line segment in 3D space.
        """
    @overload
    def __init__(self, startPoint: PyGe.Point3d, direction: PyGe.Vector3d, /) -> None:
        """
        Represents a bounded line segment in 3D space.
        """
    @overload
    def __init__(self, *args) -> None:
        """
        Represents a bounded line segment in 3D space.
        """
    def __reduce__(self, /) -> Any: ...
    def baryComb(self, /) -> Point3d: ...
    @staticmethod
    def cast(otherObject: PyGe.Entity3d, /) -> LineSeg3d: ...
    @staticmethod
    def className() -> str: ...
    @staticmethod
    def copycast(otherObject: PyGe.Entity3d, /) -> LineSeg3d: ...
    def endPoint(self, /) -> Point3d: ...
    def getBisector(self, /) -> Plane: ...
    @overload
    def length(self, /) -> float: ...
    @overload
    def length(self, fromParam: float, toParam: float, /) -> float: ...
    @overload
    def length(self, fromParam: float, toParam: float, tol: float, /) -> float: ...
    @overload
    def length(self, *args) -> float: ...
    def midPoint(self, /) -> Point3d: ...
    @overload
    def set(self, startPoint: PyGe.Point3d, endPoint: PyGe.Point3d, /) -> None: ...
    @overload
    def set(self, startPoint: PyGe.Point3d, direction: PyGe.Vector3d, /) -> None: ...
    @overload
    def set(self, *args) -> None: ...
    def startPoint(self, /) -> Point3d: ...

class LinearEnt2d(PyGe.Curve2d):
    def __init__(self) -> None:
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def cast(otherObject: PyGe.Entity2d, /) -> LinearEnt2d: ...
    @staticmethod
    def className() -> str: ...
    @staticmethod
    def copycast(otherObject: PyGe.Entity2d, /) -> LinearEnt2d: ...
    def direction(self, /) -> Vector2d: ...
    def getLine(self, /) -> Line2d: ...
    def getPerpLine(self, pt: PyGe.Point2d, /) -> Line2d: ...
    def intersectWith(
        self, other: PyGe.LinearEnt2d, tol: PyGe.Tol = ..., /
    ) -> tuple[bool, PyGe.Point2d]: ...
    def isColinearTo(self, other: PyGe.LinearEnt2d, tol: PyGe.Tol = ..., /) -> bool: ...
    def isParallelTo(self, other: PyGe.LinearEnt2d, tol: PyGe.Tol = ..., /) -> bool: ...
    def isPerpendicularTo(self, other: PyGe.LinearEnt2d, tol: PyGe.Tol = ..., /) -> bool: ...
    def overlap(
        self, other: PyGe.LinearEnt2d, tol: PyGe.Tol = ..., /
    ) -> tuple[bool, PyGe.LinearEnt2d]: ...
    def pointOnLine(self, /) -> Point2d: ...

class LinearEnt3d(PyGe.Curve3d):
    def __init__(self) -> None:
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def cast(otherObject: PyGe.Entity3d, /) -> LinearEnt3d: ...
    @staticmethod
    def className() -> str: ...
    @staticmethod
    def copycast(otherObject: PyGe.Entity3d, /) -> LinearEnt3d: ...
    def direction(self, /) -> Vector3d: ...
    def getLine(self, /) -> Line3d: ...
    def getPerpPlane(self, pt: PyGe.Point3d, /) -> Plane: ...
    def intersectWith(
        self, other: PyGe.LinearEnt3d | PyGe.PlanarEnt, tol: PyGe.Tol = ..., /
    ) -> tuple[bool, PyGe.Point3d]: ...
    def isColinearTo(self, pt: PyGe.LinearEnt3d, tol: PyGe.Tol = ..., /) -> bool: ...
    @overload
    def isOn(self, pnt: PyGe.Point3d, /) -> tuple[bool, float]: ...
    @overload
    def isOn(self, pnt: PyGe.Point3d, tol: PyGe.Tol, /) -> tuple[bool, float]: ...
    @overload
    def isOn(self, param: float, /) -> tuple[bool, float]: ...
    @overload
    def isOn(self, param: float, tol: PyGe.Tol, /) -> tuple[bool, float]: ...
    @overload
    def isOn(self, plane: PyGe.Plane, /) -> tuple[bool, float]: ...
    @overload
    def isOn(self, plane: PyGe.Plane, tol: PyGe.Tol, /) -> tuple[bool, float]: ...
    @overload
    def isOn(self, *args) -> tuple[bool, float]: ...
    @overload
    def isParallelTo(self, line: PyGe.LinearEnt3d, /) -> bool: ...
    @overload
    def isParallelTo(self, line: PyGe.LinearEnt3d, tol: PyGe.Tol, /) -> bool: ...
    @overload
    def isParallelTo(self, line: PyGe.PlanarEnt, /) -> bool: ...
    @overload
    def isParallelTo(self, line: PyGe.PlanarEnt, tol: PyGe.Tol, /) -> bool: ...
    @overload
    def isParallelTo(self, *args) -> bool: ...
    @overload
    def isPerpendicularTo(self, line: PyGe.LinearEnt3d, /) -> bool: ...
    @overload
    def isPerpendicularTo(self, line: PyGe.LinearEnt3d, tol: PyGe.Tol, /) -> bool: ...
    @overload
    def isPerpendicularTo(self, line: PyGe.PlanarEnt, /) -> bool: ...
    @overload
    def isPerpendicularTo(self, line: PyGe.PlanarEnt, tol: PyGe.Tol, /) -> bool: ...
    @overload
    def isPerpendicularTo(self, *args) -> bool: ...
    def overlap(
        self, other: PyGe.LinearEnt3d, tol: PyGe.Tol = ..., /
    ) -> tuple[bool, PyGe.LinearEnt3d]: ...
    def pointOnLine(self, /) -> Point3d: ...
    def projIntersectWith(
        self, other: PyGe.LinearEnt3d, projDir: PyGe.Vector3d, tol: PyGe.Tol = ..., /
    ) -> tuple[bool, PyGe.Point3d, PyGe.Point3d]: ...

class Matrix2d:
    def __imul__(self, xform: PyGe.Matrix2d, /) -> Matrix2d: ...
    @overload
    def __init__(self, /) -> None: ...
    @overload
    def __init__(self, entry: Collection[Collection[float]], /) -> None: ...
    @overload
    def __init__(self, *args) -> None: ...
    def __mul__(self, xform: PyGe.Matrix2d, /) -> Matrix2d: ...
    def __ne__(self, other: PyGe.Matrix2d, /) -> bool: ...
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def alignCoordSys(
        fo: PyGe.Point2d,
        fe0: PyGe.Vector2d,
        fe1: PyGe.Vector2d,
        to: PyGe.Point2d,
        te0: PyGe.Vector2d,
        te1: PyGe.Vector2d,
        /,
    ) -> Matrix2d: ...
    def det(self, /) -> float: ...
    def elementAt(self, row: int, col: int, /) -> float: ...
    @staticmethod
    def fromCollection(entry: Collection[Collection[float]], /) -> Matrix2d: ...
    def getCoordSystem(
        self, origin: PyGe.Point2d, e0: PyGe.Vector2d, e1: PyGe.Vector2d, /
    ) -> None: ...
    def getTranslation(self, /) -> Vector2d: ...
    def inverse(self, /) -> Matrix2d: ...
    def invert(self, /) -> Matrix2d: ...
    def isEqualTo(self, xform: PyGe.Matrix2d, /) -> bool: ...
    def isScaledOrtho(self, tol: PyGe.Tol = ..., /) -> bool: ...
    def isSingular(self, tol: PyGe.Tol = ..., /) -> bool: ...
    def isUniScaledOrtho(self, tol: PyGe.Tol = ..., /) -> bool: ...
    kIdentity: PyGe.Matrix2d
    @staticmethod
    def mirroring(pt: PyGe.Point2d | PyGe.Line2d, /) -> Matrix2d: ...
    def origin(self, /) -> Point2d: ...
    def postMultBy(self, xform: PyGe.Matrix2d, /) -> Matrix2d: ...
    def preMultBy(self, xform: PyGe.Matrix2d, /) -> Matrix2d: ...
    @staticmethod
    def rotation(val: float, pt: PyGe.Point2d, /) -> Matrix2d: ...
    def scale(self, /) -> float: ...
    def scale2d(self, /) -> Scale2d: ...
    @staticmethod
    def scaling(scaleAll: float, center: PyGe.Point2d, /) -> Matrix2d: ...
    def setCoordSystem(
        self, origin: PyGe.Point2d, e0: PyGe.Vector2d, e1: PyGe.Vector2d, /
    ) -> Matrix2d: ...
    def setToAlignCoordSys(
        self,
        fo: PyGe.Point2d,
        fe0: PyGe.Vector2d,
        fe1: PyGe.Vector2d,
        to: PyGe.Point2d,
        te0: PyGe.Vector2d,
        te1: PyGe.Vector2d,
        /,
    ) -> Matrix2d: ...
    def setToIdentity(self, /) -> Matrix2d: ...
    def setToMirroring(self, pt: PyGe.Point2d | PyGe.Line2d, /) -> Matrix2d: ...
    def setToProduct(self, xform1: PyGe.Matrix2d, xform2: PyGe.Matrix2d, /) -> Matrix2d: ...
    def setToRotation(self, val: float, pt: PyGe.Point2d = PyGe.Point2d.kOrgin, /) -> Matrix2d: ...
    def setToScaling(self, val: float, pt: PyGe.Point2d = PyGe.Point2d.kOrgin, /) -> Matrix2d: ...
    def setToTranslation(self, vec: PyGe.Vector2d, /) -> Matrix2d: ...
    def setTranslation(self, vec: PyGe.Vector2d, /) -> Matrix2d: ...
    def toList(self, /) -> list: ...
    def toString(self, /) -> str: ...
    def toTuple(self, /) -> tuple: ...
    @staticmethod
    def translation(vec: PyGe.Vector2d, /) -> Matrix2d: ...
    def transpose(self, /) -> Matrix2d: ...
    def transposeIt(self, /) -> Matrix2d: ...
    def xAxis(self, /) -> Vector2d: ...
    def yAxis(self, /) -> Vector2d: ...

class Matrix3d:
    def __imul__(self, xform: PyGe.Matrix3d, /) -> Matrix3d: ...
    @overload
    def __init__(self, /) -> None: ...
    @overload
    def __init__(self, entry: Collection[Collection[float]], /) -> None: ...
    @overload
    def __init__(self, *args) -> None: ...
    def __mul__(self, xform: PyGe.Matrix3d, /) -> Matrix3d: ...
    def __ne__(self, other: PyGe.Matrix3d, /) -> bool: ...
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def alignCoordSys(
        fromOrigin: PyGe.Point3d,
        fromXAxis: PyGe.Vector3d,
        fromYAxis: PyGe.Vector3d,
        fromZAxis: PyGe.Vector3d,
        toOrigin: PyGe.Point3d,
        toXAxis: PyGe.Vector3d,
        toYAxis: PyGe.Vector3d,
        toZAxis: PyGe.Vector3d,
        /,
    ) -> Matrix3d: ...
    def convertToLocal(self, normal: PyGe.Vector3d, elev: float, /) -> Matrix2d: ...
    def det(self, /) -> float: ...
    def elementAt(self, row: int, col: int, /) -> float: ...
    @staticmethod
    def fromCollection(entry: Collection[Collection[float]], /) -> Matrix3d: ...
    def getCoordSystem(
        self, origin: PyGe.Point3d, x: PyGe.Vector3d, y: PyGe.Vector3d, z: PyGe.Vector3d, /
    ) -> None: ...
    def getTranslation(self, /) -> Vector3d: ...
    @overload
    def inverse(self, /) -> Matrix3d: ...
    @overload
    def inverse(self, tol: PyGe.Tol, /) -> Matrix3d: ...
    @overload
    def inverse(self, xform: PyGe.Matrix3d, tol: float, /) -> Matrix3d: ...
    @overload
    def inverse(self, *args) -> Matrix3d: ...
    def invert(self, /) -> Matrix3d: ...
    def isEqualTo(self, other: PyGe.Matrix3d, tol: PyGe.Tol = ..., /) -> bool: ...
    def isScaledOrtho(self, val: PyGe.Tol = ..., /) -> bool: ...
    def isSingular(self, val: PyGe.Tol = ..., /) -> bool: ...
    def isUniScaledOrtho(self, val: PyGe.Tol = ..., /) -> bool: ...
    kIdentity: PyGe.Matrix3d
    @staticmethod
    def mirroring(val: PyGe.Point3d | PyGe.Plane | PyGe.Line3d, /) -> Matrix3d: ...
    def norm(self, /) -> float: ...
    def origin(self, /) -> Point3d: ...
    @staticmethod
    def planeToWorld(val: PyGe.Vector3d | PyGe.Plane, /) -> Matrix3d: ...
    def postMultBy(self, val: PyGe.Matrix3d, /) -> Matrix3d: ...
    def preMultBy(self, val: PyGe.Matrix3d, /) -> Matrix3d: ...
    @staticmethod
    def projection(projectionPlane: PyGe.Plane, projectDir: PyGe.Vector3d, /) -> Matrix3d: ...
    @staticmethod
    def rotation(angle: float, axis: PyGe.Vector3d, center: PyGe.Point3d, /) -> Matrix3d: ...
    def scale(self, /) -> float: ...
    def scale3d(self, /) -> Scale3d: ...
    @staticmethod
    def scaling(val: float, center: PyGe.Point3d, /) -> Matrix3d: ...
    def setCoordSystem(
        self, origin: PyGe.Point3d, x: PyGe.Vector3d, y: PyGe.Vector3d, z: PyGe.Vector3d, /
    ) -> Matrix3d: ...
    def setToAlignCoordSys(
        self,
        fromOrigin: PyGe.Point3d,
        fromXAxis: PyGe.Vector3d,
        fromYAxis: PyGe.Vector3d,
        fromZAxis: PyGe.Vector3d,
        toOrigin: PyGe.Point3d,
        toXAxis: PyGe.Vector3d,
        toYAxis: PyGe.Vector3d,
        toZAxis: PyGe.Vector3d,
        /,
    ) -> Matrix3d: ...
    def setToIdentity(self, /) -> Matrix3d: ...
    @overload
    def setToMirroring(self, val: PyGe.Plane, /) -> None: ...
    @overload
    def setToMirroring(self, val: PyGe.Line3d, /) -> None: ...
    @overload
    def setToMirroring(self, val: PyGe.Point3d, /) -> None: ...
    @overload
    def setToMirroring(self, *args) -> None: ...
    def setToPlaneToWorld(self, val: PyGe.Vector3d | PyGe.Plane, /) -> None: ...
    def setToProduct(self, mat1: PyGe.Matrix3d, mat2: PyGe.Matrix3d, /) -> Matrix3d: ...
    def setToProjection(
        self, projectionPlane: PyGe.Plane, projectDir: PyGe.Vector3d, /
    ) -> Matrix3d: ...
    def setToRotation(
        self, angle: float, axis: PyGe.Vector3d, center: PyGe.Point3d = PyGe.Point3d.kOrigin, /
    ) -> Matrix3d: ...
    def setToScaling(
        self, val: float, center: PyGe.Point3d = PyGe.Point3d.kOrigin, /
    ) -> Matrix3d: ...
    def setToTranslation(self, val: PyGe.Vector3d, /) -> Matrix3d: ...
    def setToWorldToPlane(self, val: PyGe.Vector3d | PyGe.Plane, /) -> None: ...
    def setTranslation(self, val: PyGe.Vector2d, /) -> Matrix3d: ...
    def toList(self, /) -> list: ...
    def toString(self, /) -> str: ...
    def toTuple(self, /) -> tuple: ...
    @staticmethod
    def translation(val: PyGe.Vector3d, /) -> Matrix3d: ...
    def transpose(self, /) -> Matrix3d: ...
    def transposeIt(self, /) -> Matrix3d: ...
    @staticmethod
    def worldToPlane(val: PyGe.Vector3d | PyGe.Plane, /) -> Matrix3d: ...
    def xAxis(self, /) -> Vector3d: ...
    def yAxis(self, /) -> Vector3d: ...
    def zAxis(self, /) -> Vector3d: ...

class NurbCurve2d(PyGe.SplineEnt2d):
    @overload
    def __init__(self, /) -> None:
        """
        Represents non-uniform rational B-spline in 2D space.
        """
    @overload
    def __init__(self, src: PyGe.Curve2d, /) -> None:
        """
        Represents non-uniform rational B-spline in 2D space.
        """
    @overload
    def __init__(self, src: PyGe.LineSeg2d, /) -> None:
        """
        Represents non-uniform rational B-spline in 2D space.
        """
    @overload
    def __init__(self, src: PyGe.EllipArc2d, /) -> None:
        """
        Represents non-uniform rational B-spline in 2D space.
        """
    @overload
    def __init__(self, curve: PyGe.Curve2d, epsilon: float, /) -> None:
        """
        Represents non-uniform rational B-spline in 2D space.
        """
    @overload
    def __init__(self, fitPnts: list[PyGe.Point2d], tol: PyGe.Tol, /) -> None:
        """
        Represents non-uniform rational B-spline in 2D space.
        """
    @overload
    def __init__(self, degree: int, fitPolyline: PyGe.Polyline2d, isPeriodic: bool, /) -> None:
        """
        Represents non-uniform rational B-spline in 2D space.
        """
    @overload
    def __init__(
        self,
        degree: int,
        knots: PyGe.KnotVector,
        cntrlPnts: list[PyGe.Point2d],
        isPeriodic: bool,
        /,
    ) -> None:
        """
        Represents non-uniform rational B-spline in 2D space.
        """
    @overload
    def __init__(
        self,
        fitPoints: list[PyGe.Point2d],
        fitTangents: list[PyGe.Vector2d],
        fitTolerance: PyGe.Tol,
        isPeriodic: bool,
        /,
    ) -> None:
        """
        Represents non-uniform rational B-spline in 2D space.
        """
    @overload
    def __init__(
        self,
        fitPoints: list[PyGe.Point2d],
        startTangent: PyGe.Vector2d,
        endTangent: PyGe.Vector2d,
        startTangentDefined: bool,
        endTangentDefined: bool,
        fitTolerance: PyGe.Tol,
        /,
    ) -> None:
        """
        Represents non-uniform rational B-spline in 2D space.
        """
    @overload
    def __init__(
        self,
        fitPoints: list[PyGe.Point2d],
        startTangent: PyGe.Vector2d,
        endTangent: PyGe.Vector2d,
        startTangentDefined: bool,
        endTangentDefined: bool,
        knotParam: PyGe.KnotParameterization,
        fitTolerance: PyGe.Tol,
        /,
    ) -> None:
        """
        Represents non-uniform rational B-spline in 2D space.
        """
    @overload
    def __init__(self, *args) -> None:
        """
        Represents non-uniform rational B-spline in 2D space.
        """
    def __reduce__(self, /) -> Any: ...
    def addControlPointAt(self, newKnot: float, pt: PyGe.Point2d, weight: float, /) -> bool: ...
    def addFitPointAt(self, idx: int, pt: PyGe.Point2d, /) -> bool: ...
    def addKnot(self, val: float, /) -> None: ...
    def buildFitData(self, val: PyGe.KnotParameterization = ..., /) -> bool: ...
    @staticmethod
    def cast(otherObject: PyGe.Entity2d, /) -> NurbCurve2d: ...
    @staticmethod
    def className() -> str: ...
    @staticmethod
    def copycast(otherObject: PyGe.Entity2d, /) -> NurbCurve2d: ...
    def deleteControlPointAt(self, val: int, /) -> bool: ...
    def deleteFitPointAt(self, idx: int, /) -> bool: ...
    def elevateDegree(self, val: int, /) -> None: ...
    def evalMode(self, /) -> bool: ...
    def getDefinitionData(self, /) -> tuple: ...
    def getFitData(self, /) -> tuple: ...
    def getFitPointAt(self, idx: int, /) -> tuple[bool, PyGe.Point2d]: ...
    def getFitTangents(self, /) -> tuple[bool, PyGe.Vector2d, PyGe.Vector2d]: ...
    def getFitTolerance(self, /) -> tuple[bool, PyGe.Tol]: ...
    def getParamsOfC1Discontinuity(self, tol: PyGe.Tol, /) -> tuple[bool, list[float]]: ...
    def getParamsOfG1Discontinuity(self, tol: PyGe.Tol, /) -> tuple[bool, list[float]]: ...
    def hardTrimByParams(self, newStartParam: float, newEndParam: float, /) -> None: ...
    def insertKnot(self, val: float, /) -> None: ...
    def joinWith(self, val: PyGe.NurbCurve2d, /) -> None: ...
    def makeClosed(self, /) -> None: ...
    def makeNonPeriodic(self, /) -> None: ...
    def makeOpen(self, /) -> None: ...
    def makePeriodic(self, /) -> None: ...
    def makeRational(self, val: float, /) -> None: ...
    def numFitPoints(self, /) -> int: ...
    def numWeights(self, /) -> int: ...
    def purgeFitData(self, /) -> bool: ...
    def setEvalMode(self, val: bool, /) -> None: ...
    @overload
    def setFitData(
        self, degree: int, fitPoints: list[PyGe.Point2d], fitTolerance: PyGe.Tol, /
    ) -> None: ...
    @overload
    def setFitData(
        self,
        fitPoints: list[PyGe.Point2d],
        startTangent: PyGe.Vector2d,
        endTangent: PyGe.Vector2d,
        fitTolerance: PyGe.Tol,
        /,
    ) -> None: ...
    @overload
    def setFitData(
        self,
        fitPoints: list[PyGe.Point2d],
        startTangent: PyGe.Vector2d,
        endTangent: PyGe.Vector2d,
        knotParam: PyGe.KnotParameterization,
        fitTolerance: PyGe.Tol,
        /,
    ) -> None: ...
    @overload
    def setFitData(
        self,
        knots: PyGe.KnotVector,
        fitPoints: list[PyGe.Point2d],
        startTangent: PyGe.Vector2d,
        endTangent: PyGe.Vector2d,
        fitTolerance: PyGe.Tol,
        isPeriodic: bool,
        /,
    ) -> None: ...
    @overload
    def setFitData(self, *args) -> None: ...
    def setFitKnotParameterization(self, val: PyGe.KnotParameterization, /) -> bool: ...
    def setFitPointAt(self, idx: int, pt: PyGe.Point2d, /) -> bool: ...
    def setFitTangents(
        self, startTangent: PyGe.Vector2d, endTangent: PyGe.Vector2d, /
    ) -> bool: ...
    def setFitTolerance(self, tol: PyGe.Tol, /) -> bool: ...
    def setWeightAt(self, idx: int, val: float, /) -> None: ...
    def weightAt(self, idx: int, /) -> float: ...

class NurbCurve3d(PyGe.SplineEnt3d):
    @overload
    def __init__(self, /) -> None:
        """
        Represents non-uniform rational B-spline in 3D space.
        """
    @overload
    def __init__(self, src: PyGe.Curve3d, /) -> None:
        """
        Represents non-uniform rational B-spline in 3D space.
        """
    @overload
    def __init__(self, src: PyGe.LineSeg3d, /) -> None:
        """
        Represents non-uniform rational B-spline in 3D space.
        """
    @overload
    def __init__(self, src: PyGe.EllipArc3d, /) -> None:
        """
        Represents non-uniform rational B-spline in 3D space.
        """
    @overload
    def __init__(self, curve: PyGe.Curve3d, epsilon: float, /) -> None:
        """
        Represents non-uniform rational B-spline in 3D space.
        """
    @overload
    def __init__(self, fitPnts: list[PyGe.Point3d], tol: PyGe.Tol, /) -> None:
        """
        Represents non-uniform rational B-spline in 3D space.
        """
    @overload
    def __init__(self, degree: int, fitPolyline: PyGe.Polyline3d, isPeriodic: bool, /) -> None:
        """
        Represents non-uniform rational B-spline in 3D space.
        """
    @overload
    def __init__(
        self,
        degree: int,
        knots: PyGe.KnotVector,
        cntrlPnts: list[PyGe.Point3d],
        isPeriodic: bool,
        /,
    ) -> None:
        """
        Represents non-uniform rational B-spline in 3D space.
        """
    @overload
    def __init__(
        self,
        fitPoints: list[PyGe.Point3d],
        fitTangents: list[PyGe.Vector3d],
        fitTolerance: PyGe.Tol,
        isPeriodic: bool,
        /,
    ) -> None:
        """
        Represents non-uniform rational B-spline in 3D space.
        """
    @overload
    def __init__(
        self,
        fitPoints: list[PyGe.Point3d],
        startTangent: PyGe.Vector3d,
        endTangent: PyGe.Vector3d,
        startTangentDefined: bool,
        endTangentDefined: bool,
        fitTolerance: PyGe.Tol,
        /,
    ) -> None:
        """
        Represents non-uniform rational B-spline in 3D space.
        """
    @overload
    def __init__(
        self,
        fitPoints: list[PyGe.Point3d],
        startTangent: PyGe.Vector3d,
        endTangent: PyGe.Vector3d,
        startTangentDefined: bool,
        endTangentDefined: bool,
        knotParam: PyGe.KnotParameterization,
        fitTolerance: PyGe.Tol,
        /,
    ) -> None:
        """
        Represents non-uniform rational B-spline in 3D space.
        """
    @overload
    def __init__(self, *args) -> None:
        """
        Represents non-uniform rational B-spline in 3D space.
        """
    def __reduce__(self, /) -> Any: ...
    def addControlPointAt(self, newKnot: float, pt: PyGe.Point3d, weight: float, /) -> bool: ...
    def addFitPointAt(self, idx: int, pt: PyGe.Point3d, /) -> bool: ...
    def addKnot(self, val: float, /) -> None: ...
    def buildFitData(self, val: PyGe.KnotParameterization = ..., /) -> bool: ...
    @staticmethod
    def cast(otherObject: PyGe.Entity3d, /) -> NurbCurve3d: ...
    @staticmethod
    def className(otherObject: PyGe.Entity3d, /) -> str: ...
    @staticmethod
    def copycast(otherObject: PyGe.Entity3d, /) -> NurbCurve3d: ...
    def deleteControlPointAt(self, idx: int, /) -> bool: ...
    def deleteFitPointAt(self, idx: int, /) -> bool: ...
    def elevateDegree(self, val: int, /) -> None: ...
    def evalMode(self, /) -> bool: ...
    def getDefinitionData(self, /) -> tuple: ...
    def getFitData(self, /) -> tuple: ...
    def getFitPointAt(self, idx: int, /) -> tuple[bool, PyGe.Point3d]: ...
    def getFitTangents(self, /) -> tuple[bool, PyGe.Vector3d, PyGe.Vector3d, bool, bool]: ...
    def getFitTolerance(self, /) -> tuple[bool, PyGe.Tol]: ...
    def getParamsOfC1Discontinuity(self, tol: PyGe.Tol, /) -> tuple[bool, list[float]]: ...
    def getParamsOfG1Discontinuity(self, tol: PyGe.Tol, /) -> tuple[bool, list[float]]: ...
    def hardTrimByParams(self, newStartParam: float, newEndParam: float, /) -> None: ...
    def insertKnot(self, val: float, /) -> None: ...
    def joinWith(self, val: PyGe.NurbCurve3d, /) -> None: ...
    def makeClosed(self, /) -> None: ...
    def makeNonPeriodic(self, /) -> None: ...
    def makeOpen(self, /) -> None: ...
    def makePeriodic(self, /) -> None: ...
    def makeRational(self, val: float, /) -> None: ...
    def numFitPoints(self, /) -> int: ...
    def numWeights(self, /) -> int: ...
    def purgeFitData(self, /) -> bool: ...
    def setEvalMode(self, val: bool, /) -> None: ...
    @overload
    def setFitData(
        self, degree: int, fitPoints: list[PyGe.Point3d], fitTolerance: PyGe.Tol, /
    ) -> None: ...
    @overload
    def setFitData(
        self,
        fitPoints: list[PyGe.Point3d],
        startTangent: PyGe.Vector3d,
        endTangent: PyGe.Vector3d,
        fitTolerance: PyGe.Tol,
        /,
    ) -> None: ...
    @overload
    def setFitData(
        self,
        fitPoints: list[PyGe.Point3d],
        startTangent: PyGe.Vector3d,
        endTangent: PyGe.Vector3d,
        knotParam: PyGe.KnotParameterization,
        fitTolerance: PyGe.Tol,
        /,
    ) -> None: ...
    @overload
    def setFitData(
        self,
        knots: PyGe.KnotVector,
        fitPoints: list[PyGe.Point3d],
        startTangent: PyGe.Vector3d,
        endTangent: PyGe.Vector3d,
        fitTolerance: PyGe.Tol,
        isPeriodic: bool,
        /,
    ) -> None: ...
    @overload
    def setFitData(self, *args) -> None: ...
    def setFitKnotParameterization(self, val: PyGe.KnotParameterization, /) -> bool: ...
    def setFitPointAt(self, idx: int, pt: PyGe.Point3d, /) -> bool: ...
    @overload
    def setFitTangents(
        self, startTangent: PyGe.Vector3d, endTangent: PyGe.Vector3d, /
    ) -> bool: ...
    @overload
    def setFitTangents(
        self,
        startTangent: PyGe.Vector3d,
        endTangent: PyGe.Vector3d,
        startTangentDefined: bool,
        endTangentDefined: bool,
        /,
    ) -> bool: ...
    @overload
    def setFitTangents(self, *args) -> bool: ...
    def setFitTolerance(self, tol: PyGe.Tol, /) -> bool: ...
    def setWeightAt(self, idx: int, val: float, /) -> None: ...
    def weightAt(self, idx: int, /) -> float: ...

class NurbSurface(PyGe.Surface):
    def __init__(self, /) -> None:
        """
        Represents generic NURB parametric surface.
        """
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def cast(otherObject: PyGe.Entity3d, /) -> NurbSurface: ...
    @staticmethod
    def className() -> str: ...
    @staticmethod
    def copycast(otherObject: PyGe.Entity3d, /) -> NurbSurface: ...

class OffsetCrvExtType(_BoostPythonEnum):
    kFillet: ClassVar[Self]  # 0
    kChamfer: ClassVar[Self]  # 1
    kExtend: ClassVar[Self]  # 2

class OffsetCurve2d(PyGe.Curve2d):
    def __init__(self, baseCurve: PyGe.Curve2d, offsetDistance: float, /) -> None: ...
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def cast(otherObject: PyGe.Entity2d, /) -> OffsetCurve2d: ...
    @staticmethod
    def className() -> str: ...
    @staticmethod
    def copycast(otherObject: PyGe.Entity2d, /) -> OffsetCurve2d: ...

class OffsetCurve3d(PyGe.Curve3d):
    def __init__(
        self, baseCurve: PyGe.Curve3d, planeNormal: PyGe.Vector3d, offsetDistance: float, /
    ) -> None: ...
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def cast(otherObject: PyGe.Entity3d, /) -> OffsetCurve3d: ...
    @staticmethod
    def className() -> str: ...
    @staticmethod
    def copycast(otherObject: PyGe.Entity3d, /) -> OffsetCurve3d: ...
    def curve(self, /) -> Curve3d: ...
    def normal(self, /) -> Vector3d: ...
    def offsetDistance(self, /) -> float: ...
    def paramDirection(self, /) -> bool: ...
    def setCurve(self, val: PyGe.Curve3d, /) -> None: ...
    def setNormal(self, normal: PyGe.Vector3d, /) -> None: ...
    def setOffsetDistance(self, val: float, /) -> None: ...
    def transformation(self, /) -> Matrix3d: ...

class OffsetSurface(PyGe.Surface):
    def __init__(self, /) -> None:
        """
        Represents an offset object.
        """
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def cast(otherObject: PyGe.Entity3d, /) -> OffsetSurface: ...
    @staticmethod
    def className() -> str: ...
    @staticmethod
    def copycast(otherObject: PyGe.Entity3d, /) -> OffsetSurface: ...

class PlanarEnt(PyGe.Surface):
    def __init__(self) -> None:
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def cast(otherObject: PyGe.Entity3d, /) -> PlanarEnt: ...
    @staticmethod
    def className() -> str: ...
    def closestPointToLinearEnt(
        self, other: PyGe.LinearEnt3d, tol: PyGe.Tol = ..., /
    ) -> tuple[PyGe.Point3d, PyGe.Point3d]: ...
    def closestPointToPlanarEnt(
        self, other: PyGe.PlanarEnt, tol: PyGe.Tol = ..., /
    ) -> tuple[PyGe.Point3d, PyGe.Point3d]: ...
    @staticmethod
    def copycast(otherObject: PyGe.Entity3d, /) -> PlanarEnt: ...
    def getCoefficients(self, /) -> tuple[float, float, float, float]: ...
    def getCoordSystem(self, /) -> tuple[PyGe.Point3d, PyGe.Vector3d, PyGe.Vector3d]: ...
    def intersectWith(
        self, other: PyGe.LinearEnt3d, tol: PyGe.Tol = ..., /
    ) -> tuple[bool, PyGe.Point3d]: ...
    def isCoplanarTo(self, other: PyGe.PlanarEnt, tol: PyGe.Tol = ..., /) -> bool: ...
    def isParallelTo(
        self, other: PyGe.LinearEnt3d | PyGe.PlanarEnt, tol: PyGe.Tol = ..., /
    ) -> bool: ...
    def isPerpendicularTo(
        self, other: PyGe.LinearEnt3d | PyGe.PlanarEnt, tol: PyGe.Tol = ..., /
    ) -> bool: ...
    def normal(self, /) -> Vector3d: ...
    def pointOnPlane(self, /) -> Point3d: ...

class Plane(PyGe.PlanarEnt):
    @overload
    def __init__(self, /) -> None:
        """
        Class AcGePlane represents a parameterized infinite plane in 3D space.
        """
    @overload
    def __init__(self, origin: PyGe.Point3d, normal: PyGe.Vector3d, /) -> None:
        """
        Class AcGePlane represents a parameterized infinite plane in 3D space.
        """
    @overload
    def __init__(
        self, origin: PyGe.Point3d, uAxis: PyGe.Vector3d, vAxis: PyGe.Vector3d, /
    ) -> None:
        """
        Class AcGePlane represents a parameterized infinite plane in 3D space.
        """
    @overload
    def __init__(self, pntU: PyGe.Point3d, origin: PyGe.Point3d, pntV: PyGe.Point3d, /) -> None:
        """
        Class AcGePlane represents a parameterized infinite plane in 3D space.
        """
    @overload
    def __init__(self, a: float, b: float, c: float, d: float, /) -> None:
        """
        Class AcGePlane represents a parameterized infinite plane in 3D space.
        """
    @overload
    def __init__(self, *args) -> None:
        """
        Class AcGePlane represents a parameterized infinite plane in 3D space.
        """
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def cast(otherObject: PyGe.Entity3d, /) -> Plane: ...
    @staticmethod
    def className() -> str: ...
    @staticmethod
    def copycast(otherObject: PyGe.Entity3d, /) -> Plane: ...
    def intersectWith(
        self, val: PyGe.LinearEnt3d | PyGe.Plane | PyGe.BoundedPlane, tol: PyGe.Tol = ..., /
    ) -> tuple[bool, PyGe.Point3d]: ...
    @overload
    def set(self, origin: PyGe.Point3d, normal: PyGe.Vector3d, /) -> None: ...
    @overload
    def set(self, origin: PyGe.Point3d, uAxis: PyGe.Vector3d, vAxis: PyGe.Vector3d, /) -> None: ...
    @overload
    def set(self, pntU: PyGe.Point3d, origin: PyGe.Point3d, pntV: PyGe.Point3d, /) -> None: ...
    @overload
    def set(self, a: float, b: float, c: float, d: float, /) -> None: ...
    @overload
    def set(self, *args) -> None: ...
    def signedDistanceTo(self, pt: PyGe.Point3d, /) -> float: ...

class Point2d:
    def __add__(self, vec: PyGe.Vector2d, /) -> Point2d: ...
    def __getinitargs__(self, /) -> tuple: ...
    def __getitem__(self, idx: int, /) -> float: ...
    def __hash__(self, /) -> int: ...
    def __iadd__(self, vec: PyGe.Vector2d, /) -> Point2d: ...
    def __imul__(self, val: float, /) -> Point2d: ...
    @overload
    def __init__(self, /) -> None: ...
    @overload
    def __init__(self, x: float, y: float, /) -> None: ...
    @overload
    def __init__(self, *args) -> None: ...
    def __isub__(self, vec: PyGe.Vector2d, /) -> Point2d: ...
    def __itruediv__(self, val: float, /) -> Point2d: ...
    def __len__(self, /) -> int: ...
    def __mul__(self, val: float, /) -> Point2d: ...
    def __ne__(self, other: PyGe.Point2d, /) -> bool: ...
    def __reduce__(self, /) -> Any: ...
    def __setitem__(self, idx: int, val: float, /) -> None: ...
    def __sub__(self, other: PyGe.Point2d | PyGe.Vector2d, /) -> Point2d: ...
    def __truediv__(self, val: float, /) -> Point2d: ...
    def asVector(self, /) -> Vector2d: ...
    def distanceTo(self, pt: PyGe.Point2d, /) -> float: ...
    def isEqualTo(self, pt: PyGe.Point2d, tol: PyGe.Tol = ..., /) -> bool: ...
    kOrigin: PyGe.Point2d
    def mirror(self, pt: PyGe.Line2d, /) -> Point2d: ...
    def rotateBy(self, val: float, pt: PyGe.Point2d = PyGe.Point2d.kOrgin, /) -> Point2d: ...
    def scaleBy(self, val: float, pt: PyGe.Point2d = PyGe.Point2d.kOrgin, /) -> Point2d: ...
    def set(self, xx: float, yy: float, /) -> Point2d: ...
    def setToProduct(self, mat: PyGe.Matrix2d, pt: PyGe.Point2d, /) -> Point2d: ...
    def setToSum(self, pt: PyGe.Point2d, vec: PyGe.Vector2d, /) -> Point2d: ...
    def to3d(self, /) -> Point3d: ...
    def toList(self, /) -> list[float]: ...
    def toString(self, /) -> str: ...
    def toTuple(self, /) -> tuple[float, float]: ...
    def transformBy(self, xform: PyGe.Matrix2d, /) -> Point2d: ...
    @property
    def x(self, /) -> float: ...
    @property
    def y(self, /) -> float: ...

class Point2dArray:
    def __contains__(self, /) -> bool: ...
    def __delitem__(self, /) -> None: ...
    def __getitem__(self, /) -> object: ...
    def __init__(self, /) -> None: ...
    def __iter__(self, /) -> object: ...
    def __len__(self, /) -> int: ...
    def __reduce__(self, /) -> Any: ...
    def __setitem__(self, /) -> None: ...
    def append(self, /) -> None: ...
    def convexHull(self, /) -> Point2dArray: ...
    def convexHullIndexes(self, /) -> list: ...
    def extend(self, /) -> None: ...
    def sortByDistFrom(self, basePnt: PyGe.Point2d, /) -> None: ...
    def sortByX(self, /) -> None: ...
    def sortByY(self, /) -> None: ...
    def to3d(self, /) -> Point3dArray: ...
    def transformBy(self, mat: PyGe.Matrix2d, /) -> None:
        """
        Transform this pre-multiplying it the matrix leftSide. Returns the reference to this point.
        Result is the same as setToProduct(leftSide, *this).
        """

class Point2dTree:
    def __init__(self, points: Collection[PyGe.Point2d], /) -> None: ...
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def className() -> str: ...
    def inputPoints(self, /) -> Point2dArray: ...
    def knnSearch(self, point: PyGe.Point2d, num_closest: int, /) -> tuple: ...
    def radiusSearch(self, point: PyGe.Point2d, radius: float, /) -> tuple: ...

class Point3d:
    def __add__(self, vec: PyGe.Vector3d, /) -> Point3d: ...
    def __getinitargs__(self, /) -> tuple: ...
    def __getitem__(self, idx: int, /) -> float: ...
    def __hash__(self, /) -> int: ...
    def __iadd__(self, vec: PyGe.Vector3d, /) -> Point3d: ...
    def __imul__(self, val: float, /) -> Point3d: ...
    @overload
    def __init__(self, /) -> None: ...
    @overload
    def __init__(self, floats: tuple[float] | list[float], /) -> None: ...
    @overload
    def __init__(self, x: float, y: float, z: float, /) -> None: ...
    @overload
    def __init__(self, pln: PyGe.PlanarEnt, pnt2d: PyGe.Point2d, /) -> None: ...
    @overload
    def __init__(self, *args) -> None: ...
    def __isub__(self, vec: PyGe.Vector3d, /) -> Point3d: ...
    def __itruediv__(self, val: float, /) -> Point3d: ...
    def __len__(self, /) -> int: ...
    def __mul__(self, val: float, /) -> Point3d: ...
    def __ne__(self, pt: PyGe.Point3d, /) -> bool: ...
    def __reduce__(self, /) -> Any: ...
    def __rmul__(self, val: float | PyGe.Matrix3d, /) -> Point3d: ...
    def __setitem__(self, idx: int, val: float, /) -> None: ...
    def __sub__(self, val: PyGe.Vector3d | PyGe.Point3d, /) -> Vector3d: ...
    def __truediv__(self, val: float, /) -> Point3d: ...
    def asVector(self, /) -> Vector3d:
        """
        Converts 3D point into 3D vector with the same set of coordinates ( see AcGeVector3d ).
        Return value is a class AcGeVector3d.
        """
    def convert2d(self, pln: PyGe.PlanarEnt, /) -> Point2d:
        """
        Returns 2D point with the coordinates corresponding to the decomposition of the vector
        *this - p in the basis uAxis, vAxis in the planar entity, where p, uAxis, and vAxis can
        found by function call pln.get(p, uAxis, vAxis). Contract: This 3D point assumed to be on
        the planar entity pln.
        """
    def distanceTo(self, pnt: PyGe.Point3d, /) -> float:
        """
        Evaluates and returns distance from this point to the point pnt.
        """
    def isEqualTo(self, pnt: PyGe.Point3d, tol: PyGe.Tol = ..., /) -> bool:
        """
        Checks if this point is within the distance tol.equalPoint() from the point pnt. The
        default value of the tolerance class tol is AcGeContext::gTol. Returns Adesk::kTrue if this
        condition is met and Adesk::kFalse otherwise.
        """
    kOrigin: PyGe.Point3d
    def mirror(self, pln: PyGe.Plane, /) -> Point3d:
        """
        Returns the 3D point that is the result of mirroring of this point with respect to the
        plane pln.
        """
    def orthoProject(self, pln: PyGe.Plane, /) -> Point3d:
        """
        Returns 3D point that is the result of the orthogonal projection of this point into the
        plane pln.
        """
    def project(self, pln: PyGe.Plane, vec: PyGe.Vector3d, /) -> Point3d:
        """
        Returns 3D point that is the result of the parallel projection of this point into the plane
        pln. The direction of projection is defined by vector vec.
        """
    def rotateBy(
        self, angle: float, vec: PyGe.Vector3d, wrtPoint: PyGe.Point3d = PyGe.Point3d.kOrigin, /
    ) -> Point3d:
        """
        Returns 3D point that is the result of rotation of this point around the line with
        direction vector vec passing through the point wrtPoint. Rotation angle is given by the
        argument angle, where positive direction of rotation is defined by the right-hand rule.
        """
    def scaleBy(self, factor: float, pnt: PyGe.Point3d = "orgin", /) -> Point3d:
        """
        Returns 3D point that is the result of scaling of this point with respect to the 3D point
        wrtPoint by scale factor scaleFactor.
        """
    @overload
    def set(self, x: float, y: float, z: float, /) -> Point3d: ...
    @overload
    def set(self, pl: PyGe.PlanarEnt, pt2d: PyGe.Point2d, /) -> Point3d: ...
    @overload
    def set(self, *args) -> Point3d: ...
    def setToProduct(self, mat: PyGe.Matrix3d, pnt: PyGe.Point3d, /) -> Point3d:
        """
        Sets this point to the product of matrix mat and point pnt. The order of multiplication is
        mat*pnt, where points are considered as columns. Returns the reference to this point.
        """
    def setToSum(self, pnt: PyGe.Point3d, vec: PyGe.Vector3d, /) -> Point3d:
        """
        Sets this point to the sum of the pnt and vector vec. Returns the reference to this point.
        """
    def to2d(self, /) -> Point2d: ...
    def toList(self, /) -> list[float]: ...
    def toString(self, /) -> str: ...
    def toTuple(self, /) -> tuple[float, float, float]: ...
    def transformBy(self, mat: PyGe.Matrix3d, /) -> Point3d:
        """
        Transform this pre-multiplying it the matrix leftSide. Returns the reference to this point.
        Result is the same as setToProduct(leftSide, *this).
        """
    @property
    def x(self, /) -> float: ...
    @property
    def y(self, /) -> float: ...
    @property
    def z(self, /) -> float: ...

class Point3dArray:
    def __contains__(self, /) -> bool: ...
    def __delitem__(self, /) -> None: ...
    def __getitem__(self, /) -> object: ...
    def __init__(self, /) -> None: ...
    def __iter__(self, /) -> object: ...
    def __len__(self, /) -> int: ...
    def __reduce__(self, /) -> Any: ...
    def __setitem__(self, /) -> None: ...
    def append(self, /) -> None: ...
    def convexHull(self, /) -> Point3dArray: ...
    def convexHullIndexes(self, /) -> list: ...
    def extend(self, /) -> None: ...
    def isPlanar(self, /) -> tuple[bool, PyGe.Plane]: ...
    def sortByDistFrom(self, basePnt: PyGe.Point3d, /) -> None: ...
    def sortByX(self, /) -> None: ...
    def sortByY(self, /) -> None: ...
    def sortByZ(self, /) -> None: ...
    def to2d(self, /) -> Point2dArray: ...
    def transformBy(self, mat: PyGe.Matrix3d, /) -> None:
        """
        Transform this pre-multiplying it the matrix leftSide. Returns the reference to this point.
        Result is the same as setToProduct(leftSide, *this).
        """

class Point3dTree:
    def __init__(self, points: Collection[PyGe.Point3d], /) -> None: ...
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def className() -> str: ...
    def inputPoints(self, /) -> Point3dArray: ...
    def knnSearch(self, point: PyGe.Point3d, num_closest: int, /) -> tuple: ...
    def radiusSearch(self, point: PyGe.Point3d, radius: float, /) -> tuple: ...

class PointContainment(_BoostPythonEnum):
    kInside: ClassVar[Self]  # 0
    kOutside: ClassVar[Self]  # 1
    kOnBoundary: ClassVar[Self]  # 2

class PointEnt2d(PyGe.Entity2d):
    def __init__(self) -> None:
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def cast(otherObject: PyGe.Entity2d, /) -> PointEnt2d: ...
    @staticmethod
    def className() -> str: ...
    @staticmethod
    def copycast(otherObject: PyGe.Entity2d, /) -> PointEnt2d: ...
    def point2d(self, /) -> Point2d: ...

class PointEnt3d(PyGe.Entity3d):
    def __init__(self) -> None:
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def cast(otherObject: PyGe.Entity3d, /) -> PointEnt3d: ...
    @staticmethod
    def className() -> str: ...
    @staticmethod
    def copycast(otherObject: PyGe.Entity3d, /) -> PointEnt3d: ...
    def point3d(self, /) -> Point3d: ...

class PointOnCurve2d(PyGe.PointEnt2d):
    @overload
    def __init__(self, /) -> None:
        """
        Represents a point on a 2D parametric curve. This class encapsulates all of the geometric
        information of a point on a 2D curve, including its parameter value, 2D coordinates, and
        derivatives.
        """
    @overload
    def __init__(self, curve: PyGe.Curve2d, /) -> None:
        """
        Represents a point on a 2D parametric curve. This class encapsulates all of the geometric
        information of a point on a 2D curve, including its parameter value, 2D coordinates, and
        derivatives.
        """
    @overload
    def __init__(self, curve: PyGe.Curve2d, param: float, /) -> None:
        """
        Represents a point on a 2D parametric curve. This class encapsulates all of the geometric
        information of a point on a 2D curve, including its parameter value, 2D coordinates, and
        derivatives.
        """
    @overload
    def __init__(self, *args) -> None:
        """
        Represents a point on a 2D parametric curve. This class encapsulates all of the geometric
        information of a point on a 2D curve, including its parameter value, 2D coordinates, and
        derivatives.
        """
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def cast(otherObject: PyGe.Entity2d, /) -> PointEnt2d: ...
    @staticmethod
    def className() -> str: ...
    @staticmethod
    def copycast(otherObject: PyGe.Entity2d, /) -> PointOnCurve2d: ...
    def curve(self, /) -> Curve2d: ...
    @overload
    def deriv(self, order: int, /) -> Vector2d: ...
    @overload
    def deriv(self, order: int, param: float, /) -> Vector2d: ...
    @overload
    def deriv(self, order: int, curve: PyGe.Curve2d, param: float, /) -> Vector2d: ...
    @overload
    def deriv(self, *args) -> Vector2d: ...
    def parameter(self, /) -> float: ...
    @overload
    def point(self, /) -> Point2d: ...
    @overload
    def point(self, param: float, /) -> Point2d: ...
    @overload
    def point(self, curve: PyGe.Curve2d, param: float, /) -> Point2d: ...
    @overload
    def point(self, *args) -> Point2d: ...
    def setCurve(self, val: PyGe.Curve2d, /) -> None: ...
    def setParameter(self, val: float, /) -> None: ...

class PointOnCurve3d(PyGe.PointEnt3d):
    @overload
    def __init__(self, /) -> None:
        """
        Represents a point on a 3D parametric curve. This class encapsulates all of the geometric
        information of a point on a 3D curve including its parameter value, 3D coordinates, and
        derivatives.
        """
    @overload
    def __init__(self, curve: PyGe.Curve3d, /) -> None:
        """
        Represents a point on a 3D parametric curve. This class encapsulates all of the geometric
        information of a point on a 3D curve including its parameter value, 3D coordinates, and
        derivatives.
        """
    @overload
    def __init__(self, curve: PyGe.Curve3d, param: float, /) -> None:
        """
        Represents a point on a 3D parametric curve. This class encapsulates all of the geometric
        information of a point on a 3D curve including its parameter value, 3D coordinates, and
        derivatives.
        """
    @overload
    def __init__(self, *args) -> None:
        """
        Represents a point on a 3D parametric curve. This class encapsulates all of the geometric
        information of a point on a 3D curve including its parameter value, 3D coordinates, and
        derivatives.
        """
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def cast(otherObject: PyGe.Entity3d, /) -> PointOnCurve3d: ...
    @staticmethod
    def className() -> str: ...
    @staticmethod
    def copycast(otherObject: PyGe.Entity3d, /) -> PointOnCurve3d: ...
    def curvature(self, param: float = ..., /) -> float: ...
    def curve(self, /) -> Curve3d: ...
    @overload
    def deriv(self, order: int, /) -> Vector3d: ...
    @overload
    def deriv(self, order: int, param: float, /) -> Vector3d: ...
    @overload
    def deriv(self, order: int, curve: PyGe.Curve3d, param: float, /) -> Vector3d: ...
    @overload
    def deriv(self, *args) -> Vector3d: ...
    def isSingular(self, /) -> bool: ...
    def parameter(self, /) -> float: ...
    @overload
    def point(self, /) -> Point3d: ...
    @overload
    def point(self, param: float, /) -> Point3d: ...
    @overload
    def point(self, curve: PyGe.Curve3d, param: float, /) -> Point3d: ...
    @overload
    def point(self, *args) -> Point3d: ...
    def setCurve(self, curve: PyGe.Curve3d, /) -> None: ...
    def setParameter(self, param: float, /) -> None: ...

class PointOnSurface(PyGe.PointEnt3d):
    @overload
    def __init__(self, /) -> None:
        """
        Represents a point on a surface. This class encapsulates all of the geometric information
        of a point on a surface, including its parameter value, 3D coordinates, derivatives, and
        normal vector.
        """
    @overload
    def __init__(self, surface: PyGe.Surface, /) -> None:
        """
        Represents a point on a surface. This class encapsulates all of the geometric information
        of a point on a surface, including its parameter value, 3D coordinates, derivatives, and
        normal vector.
        """
    @overload
    def __init__(self, surface: PyGe.Surface, pnt: PyGe.Point2d, /) -> None:
        """
        Represents a point on a surface. This class encapsulates all of the geometric information
        of a point on a surface, including its parameter value, 3D coordinates, derivatives, and
        normal vector.
        """
    @overload
    def __init__(self, *args) -> None:
        """
        Represents a point on a surface. This class encapsulates all of the geometric information
        of a point on a surface, including its parameter value, 3D coordinates, derivatives, and
        normal vector.
        """
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def cast(otherObject: PyGe.Entity3d, /) -> PointOnSurface: ...
    @staticmethod
    def className() -> str: ...
    @staticmethod
    def copycast(otherObject: PyGe.Entity3d, /) -> PointOnSurface: ...
    @overload
    def inverseTangentVector(self, vec: PyGe.Vector2d, /) -> Vector2d: ...
    @overload
    def inverseTangentVector(self, vec: PyGe.Vector2d, param: PyGe.Vector2d, /) -> Vector2d: ...
    @overload
    def inverseTangentVector(
        self, vec: PyGe.Vector2d, surface: PyGe.Surface, param: PyGe.Vector2d, /
    ) -> Vector2d: ...
    @overload
    def inverseTangentVector(self, *args) -> Vector2d: ...
    @overload
    def mixedPartial(self, /) -> Vector3d: ...
    @overload
    def mixedPartial(self, param: PyGe.Point2d, /) -> Vector3d: ...
    @overload
    def mixedPartial(self, surface: PyGe.Surface, param: PyGe.Point2d, /) -> Vector3d: ...
    @overload
    def mixedPartial(self, *args) -> Vector3d: ...
    @overload
    def normal(self, /) -> Vector3d: ...
    @overload
    def normal(self, param: PyGe.Point2d, /) -> Vector3d: ...
    @overload
    def normal(self, surface: PyGe.Surface, param: PyGe.Point2d, /) -> Vector3d: ...
    @overload
    def normal(self, *args) -> Vector3d: ...
    def parameter(self, /) -> Point2d: ...
    @overload
    def point(self, /) -> Point3d: ...
    @overload
    def point(self, param: PyGe.Point2d, /) -> Point3d: ...
    @overload
    def point(self, surface: PyGe.Surface, param: PyGe.Point2d, /) -> Point3d: ...
    @overload
    def point(self, *args) -> Point3d: ...
    def setParameter(self, param: PyGe.Point2d, /) -> None: ...
    def setSurface(self, val: PyGe.Surface, /) -> None: ...
    def surface(self, /) -> PyGe.Surface: ...
    @overload
    def tangentVector(self, vec: PyGe.Vector2d, /) -> Vector3d: ...
    @overload
    def tangentVector(self, vec: PyGe.Vector2d, param: PyGe.Vector2d, /) -> Vector3d: ...
    @overload
    def tangentVector(
        self, vec: PyGe.Vector2d, surface: PyGe.Surface, param: PyGe.Vector2d, /
    ) -> Vector3d: ...
    @overload
    def tangentVector(self, *args) -> Vector3d: ...
    @overload
    def uDeriv(self, order: int, /) -> Vector3d: ...
    @overload
    def uDeriv(self, order: int, param: PyGe.Point2d, /) -> Vector3d: ...
    @overload
    def uDeriv(self, order: int, surface: PyGe.Surface, param: PyGe.Point2d, /) -> Vector3d: ...
    @overload
    def uDeriv(self, *args) -> Vector3d: ...
    @overload
    def vDeriv(self, order: int, /) -> Vector3d: ...
    @overload
    def vDeriv(self, order: int, param: PyGe.Point2d, /) -> Vector3d: ...
    @overload
    def vDeriv(self, order: int, surface: PyGe.Surface, param: PyGe.Point2d, /) -> Vector3d: ...
    @overload
    def vDeriv(self, *args) -> Vector3d: ...

class Polyline2d(PyGe.SplineEnt2d):
    @overload
    def __init__(self, /) -> None:
        """
        Represents a piecewise linear spline entity in 2D space.
        """
    @overload
    def __init__(self, points: list[PyGe.Point2d], /) -> None:
        """
        Represents a piecewise linear spline entity in 2D space.
        """
    @overload
    def __init__(self, knots: PyGe.KnotVector, points: list[PyGe.Point2d], /) -> None:
        """
        Represents a piecewise linear spline entity in 2D space.
        """
    @overload
    def __init__(self, crv: PyGe.Curve2d, apprEps: float, /) -> None:
        """
        Represents a piecewise linear spline entity in 2D space.
        """
    @overload
    def __init__(self, *args) -> None:
        """
        Represents a piecewise linear spline entity in 2D space.
        """
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def cast(otherObject: PyGe.Entity2d, /) -> Polyline2d: ...
    @staticmethod
    def className() -> str: ...
    @staticmethod
    def copycast(otherObject: PyGe.Entity2d, /) -> Polyline2d: ...
    def fitPointAt(self, idx: int, /) -> Point2d: ...
    def numFitPoints(self, /) -> int: ...
    def setFitPointAt(self, idx: int, pt: PyGe.Point2d, /) -> None: ...

class Polyline3d(PyGe.SplineEnt3d):
    @overload
    def __init__(self, /) -> None:
        """
        Represents a piecewise linear spline entity in 3D space.
        """
    @overload
    def __init__(self, points: list[PyGe.Point3d], /) -> None:
        """
        Represents a piecewise linear spline entity in 3D space.
        """
    @overload
    def __init__(self, knots: PyGe.KnotVector, points: list[PyGe.Point3d], /) -> None:
        """
        Represents a piecewise linear spline entity in 3D space.
        """
    @overload
    def __init__(self, crv: PyGe.Curve3d, apprEps: float, /) -> None:
        """
        Represents a piecewise linear spline entity in 3D space.
        """
    @overload
    def __init__(self, *args) -> None:
        """
        Represents a piecewise linear spline entity in 3D space.
        """
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def cast(otherObject: PyGe.Entity3d, /) -> Polyline3d: ...
    @staticmethod
    def className(otherObject: PyGe.Entity3d, /) -> str: ...
    @staticmethod
    def copycast(otherObject: PyGe.Entity3d, /) -> Polyline3d: ...
    def fitPointAt(self, idx: int, /) -> Point3d: ...
    def numFitPoints(self, /) -> int: ...
    def setFitPointAt(self, idx: int, pt: PyGe.Point3d, /) -> None: ...

class Position2d(PyGe.PointEnt2d):
    @overload
    def __init__(self, /) -> None:
        """
        Represents a point in 2D space.
        """
    @overload
    def __init__(self, pnt: PyGe.Point2d, /) -> None:
        """
        Represents a point in 2D space.
        """
    @overload
    def __init__(self, x: float, y: float, /) -> None:
        """
        Represents a point in 2D space.
        """
    @overload
    def __init__(self, *args) -> None:
        """
        Represents a point in 2D space.
        """
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def cast(otherObject: PyGe.Entity2d, /) -> Position2d: ...
    @staticmethod
    def className() -> str: ...
    @staticmethod
    def copycast(otherObject: PyGe.Entity2d, /) -> Position2d: ...
    @overload
    def set(self, pnt: PyGe.Point2d, /) -> None: ...
    @overload
    def set(self, x: float, y: float, /) -> None: ...
    @overload
    def set(self, *args) -> None: ...

class Position3d(PyGe.PointEnt3d):
    @overload
    def __init__(self, /) -> None:
        """
        Represents a point in 3D space.
        """
    @overload
    def __init__(self, pnt: PyGe.Point3d, /) -> None:
        """
        Represents a point in 3D space.
        """
    @overload
    def __init__(self, x: float, y: float, z: float, /) -> None:
        """
        Represents a point in 3D space.
        """
    @overload
    def __init__(self, *args) -> None:
        """
        Represents a point in 3D space.
        """
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def cast(otherObject: PyGe.Entity3d, /) -> Position3d: ...
    @staticmethod
    def className() -> str: ...
    @staticmethod
    def copycast(otherObject: PyGe.Entity3d, /) -> Position3d: ...
    @overload
    def set(self, pnt: PyGe.Point3d, /) -> None: ...
    @overload
    def set(self, x: float, y: float, z: float, /) -> None: ...
    @overload
    def set(self, *args) -> None: ...

class Ray2d(PyGe.LinearEnt2d):
    @overload
    def __init__(self, /) -> None:
        """
        Represents a half-bounded line in 2D space. An AcGeRay2d object either has a start point
        but no endpoint, or has an endpoint but no start point.
        """
    @overload
    def __init__(self, start: PyGe.Point3d, direction: PyGe.Vector2d, /) -> None:
        """
        Represents a half-bounded line in 2D space. An AcGeRay2d object either has a start point
        but no endpoint, or has an endpoint but no start point.
        """
    @overload
    def __init__(self, start: PyGe.Point3d, end: PyGe.Point3d, /) -> None:
        """
        Represents a half-bounded line in 2D space. An AcGeRay2d object either has a start point
        but no endpoint, or has an endpoint but no start point.
        """
    @overload
    def __init__(self, *args) -> None:
        """
        Represents a half-bounded line in 2D space. An AcGeRay2d object either has a start point
        but no endpoint, or has an endpoint but no start point.
        """
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def cast(otherObject: PyGe.Entity2d, /) -> Ray2d: ...
    @staticmethod
    def className() -> str: ...
    @staticmethod
    def copycast(otherObject: PyGe.Entity2d, /) -> Ray2d: ...
    @overload
    def set(self, start: PyGe.Point3d, direction: PyGe.Vector2d, /) -> None: ...
    @overload
    def set(self, start: PyGe.Point3d, end: PyGe.Point3d, /) -> None: ...
    @overload
    def set(self, *args) -> None: ...

class Ray3d(PyGe.LinearEnt3d):
    @overload
    def __init__(self, /) -> None:
        """
        Represents a half-bounded line in 3D space. An AcGeRay3 object either has a start point but
        no endpoint, or has an endpoint but no start point.
        """
    @overload
    def __init__(self, startPoint: PyGe.Point3d, endPoint: PyGe.Point3d, /) -> None:
        """
        Represents a half-bounded line in 3D space. An AcGeRay3 object either has a start point but
        no endpoint, or has an endpoint but no start point.
        """
    @overload
    def __init__(self, startPoint: PyGe.Point3d, direction: PyGe.Vector3d, /) -> None:
        """
        Represents a half-bounded line in 3D space. An AcGeRay3 object either has a start point but
        no endpoint, or has an endpoint but no start point.
        """
    @overload
    def __init__(self, *args) -> None:
        """
        Represents a half-bounded line in 3D space. An AcGeRay3 object either has a start point but
        no endpoint, or has an endpoint but no start point.
        """
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def cast(otherObject: PyGe.Entity3d, /) -> Ray3d: ...
    @staticmethod
    def className() -> str: ...
    @staticmethod
    def copycast(otherObject: PyGe.Entity3d, /) -> Ray3d: ...
    @overload
    def set(self, startPoint: PyGe.Point3d, endPoint: PyGe.Point3d, /) -> None: ...
    @overload
    def set(self, startPoint: PyGe.Point3d, direction: PyGe.Vector3d, /) -> None: ...
    @overload
    def set(self, *args) -> None: ...

class Scale2d:
    def __getitem__(self, idx: int, /) -> float: ...
    def __imul__(self, val: float, /) -> Scale2d: ...
    @overload
    def __init__(self, /) -> None: ...
    @overload
    def __init__(self, factor: float, /) -> None: ...
    @overload
    def __init__(self, xFactor: float, yFactor: float, /) -> None: ...
    @overload
    def __init__(self, *args) -> None: ...
    def __len__(self, /) -> int: ...
    def __mul__(self, val: float, /) -> Scale2d: ...
    def __ne__(self, other: PyGe.Scale2d, /) -> bool: ...
    def __reduce__(self, /) -> Any: ...
    def __setitem__(self, idx: int, val: float, /) -> None: ...
    def postMultBy(self, right: PyGe.Scale2d, /) -> Scale2d: ...
    def preMultBy(self, left: PyGe.Scale2d, /) -> Scale2d: ...
    @overload
    def setToProduct(self, sclVec1: PyGe.Scale2d, s: float, /) -> Scale2d: ...
    @overload
    def setToProduct(self, sclVec1: PyGe.Scale2d, ssclVec2: PyGe.Scale2d, /) -> Scale2d: ...
    @overload
    def setToProduct(self, *args) -> Scale2d: ...
    @property
    def sx(self, /) -> float: ...
    @property
    def sy(self, /) -> float: ...
    def toString(self, /) -> str: ...

class Scale3d:
    def __getitem__(self, idx: int, /) -> float: ...
    def __imul__(self, val: float, /) -> Scale3d: ...
    @overload
    def __init__(self, /) -> None: ...
    @overload
    def __init__(self, factor: float, /) -> None: ...
    @overload
    def __init__(self, sx: float, sy: float, sz: float, /) -> None: ...
    @overload
    def __init__(self, *args) -> None: ...
    def __len__(self, /) -> int: ...
    def __mul__(self, val: float, /) -> Scale3d: ...
    def __ne__(self, other: PyGe.Scale3d, /) -> bool: ...
    def __reduce__(self, /) -> Any: ...
    def __setitem__(self, idx: int, val: float, /) -> None: ...
    def postMultBy(self, vec: PyGe.Vector3d, /) -> Scale3d: ...
    def preMultBy(self, vec: PyGe.Vector3d, /) -> Scale3d: ...
    @overload
    def setToProduct(self, sc: PyGe.Scale3d, s: float, /) -> Scale3d: ...
    @overload
    def setToProduct(self, sc1: PyGe.Scale3d, sc2: PyGe.Scale3d, /) -> Scale3d: ...
    @overload
    def setToProduct(self, *args) -> Scale3d: ...
    @property
    def sx(self, /) -> float: ...
    @property
    def sy(self, /) -> float: ...
    @property
    def sz(self, /) -> float: ...
    def toString(self, /) -> str: ...

class Sphere(PyGe.Surface):
    @overload
    def __init__(self, /) -> None:
        """
        Represents a spherical surface.
        """
    @overload
    def __init__(self, radius: float, center: PyGe.Point3d, /) -> None:
        """
        Represents a spherical surface.
        """
    @overload
    def __init__(
        self,
        radius: float,
        center: PyGe.Point3d,
        northAxis: PyGe.Vector3d,
        refAxis: PyGe.Vector3d,
        startAngleU: float,
        endAngleU: float,
        startAngleV: float,
        endAngleV: float,
        /,
    ) -> None:
        """
        Represents a spherical surface.
        """
    @overload
    def __init__(self, *args) -> None:
        """
        Represents a spherical surface.
        """
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def cast(otherObject: PyGe.Entity3d, /) -> Sphere: ...
    def center(self, /) -> Point3d: ...
    @staticmethod
    def className() -> str: ...
    @staticmethod
    def copycast(otherObject: PyGe.Entity3d, /) -> Sphere: ...
    def getAnglesInU(self, /) -> tuple[float, float]: ...
    def getAnglesInV(self, /) -> tuple[float, float]: ...
    def intersectWith(
        self, val: PyGe.LinearEnt3d, tol: PyGe.Tol = ..., /
    ) -> tuple[int, PyGe.Point3d, PyGe.Point3d]: ...
    def isClosed(self, tol: PyGe.Tol = ..., /) -> bool: ...
    def isOuterNormal(self, /) -> bool: ...
    def northAxis(self, /) -> Vector3d: ...
    def northPole(self, /) -> Point3d: ...
    def radius(self, /) -> float: ...
    def refAxis(self, /) -> Vector3d: ...
    @overload
    def set(self, radius: float, center: PyGe.Point3d, /) -> None: ...
    @overload
    def set(
        self,
        radius: float,
        center: PyGe.Point3d,
        northAxis: PyGe.Vector3d,
        refAxis: PyGe.Vector3d,
        startAngleU: float,
        endAngleU: float,
        startAngleV: float,
        endAngleV: float,
        /,
    ) -> None: ...
    @overload
    def set(self, *args) -> None: ...
    def setAnglesInU(self, start: float, end: float, /) -> None: ...
    def setAnglesInV(self, start: float, end: float, /) -> None: ...
    def setRadius(self, val: float, /) -> None: ...
    def southPole(self, /) -> Point3d: ...

class SplineEnt2d(PyGe.Curve2d):
    def __init__(self) -> None:
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def cast(otherObject: PyGe.Entity2d, /) -> SplineEnt2d: ...
    @staticmethod
    def className() -> str: ...
    def continuityAtKnot(self, idx: int, tol: PyGe.Tol = ..., /) -> int: ...
    def controlPointAt(self, idx: int, /) -> Point2d: ...
    @staticmethod
    def copycast(otherObject: PyGe.Entity2d, /) -> SplineEnt2d: ...
    def degree(self, /) -> int: ...
    def endParam(self, /) -> float: ...
    def endPoint(self, /) -> Point2d: ...
    def hasFitData(self, /) -> bool: ...
    def isRational(self, /) -> bool: ...
    def knotAt(self, idx: int, /) -> float: ...
    def knots(self, /) -> KnotVector: ...
    def numControlPoints(self, /) -> int: ...
    def numKnots(self, /) -> int: ...
    def order(self, /) -> int: ...
    def setControlPointAt(self, idx: int, val: PyGe.Point2d, /) -> None: ...
    def setKnotAt(self, idx: int, val: float, /) -> None: ...
    def startParam(self, /) -> float: ...
    def startPoint(self, /) -> Point2d: ...

class SplineEnt3d(PyGe.Curve3d):
    def __init__(self) -> None:
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def cast(otherObject: PyGe.Entity3d, /) -> SplineEnt3d: ...
    @staticmethod
    def className() -> str: ...
    def continuityAtKnot(self, idx: int, tol: PyGe.Tol = ..., /) -> int: ...
    def controlPointAt(self, idx: int, /) -> Point3d: ...
    @staticmethod
    def copycast(otherObject: PyGe.Entity3d, /) -> SplineEnt3d: ...
    def degree(self, /) -> int: ...
    def endParam(self, /) -> float: ...
    def endPoint(self, /) -> Point3d: ...
    def hasFitData(self, /) -> bool: ...
    def isRational(self, /) -> bool: ...
    def knotAt(self, idx: int, /) -> float: ...
    def knots(self, /) -> KnotVector: ...
    def numControlPoints(self, /) -> int: ...
    def numKnots(self, /) -> int: ...
    def order(self, /) -> int: ...
    def setControlPointAt(self, idx: int, val: PyGe.Point3d, /) -> None: ...
    def setKnotAt(self, idx: int, val: float, /) -> None: ...
    def startParam(self, /) -> float: ...
    def startPoint(self, /) -> Point3d: ...

class SurfSurfInt(PyGe.Entity3d):
    @overload
    def __init__(self, /) -> None:
        """
        This class holds data for intersections of two surfaces.
        """
    @overload
    def __init__(self, srf1: PyGe.Surface, srf2: PyGe.Surface, /) -> None:
        """
        This class holds data for intersections of two surfaces.
        """
    @overload
    def __init__(self, srf1: PyGe.Surface, srf2: PyGe.Surface, tol: PyGe.Tol, /) -> None:
        """
        This class holds data for intersections of two surfaces.
        """
    @overload
    def __init__(self, *args) -> None:
        """
        This class holds data for intersections of two surfaces.
        """
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def cast(otherObject: PyGe.Entity3d, /) -> SurfSurfInt: ...
    @staticmethod
    def className() -> str: ...
    @staticmethod
    def copycast(otherObject: PyGe.Entity3d, /) -> SurfSurfInt: ...
    def getDimension(self, intNum: int, /) -> int: ...
    def getIntConfigs(self, intNum: int, /) -> tuple: ...
    def getIntPointParams(self, intNum: int, /) -> tuple[PyGe.Point2d, PyGe.Point2d]: ...
    def getType(self, intNum: int, /) -> int: ...
    def intCurve(self, intNum: int, isExternal: bool, /) -> Curve3d: ...
    def intParamCurve(self, intNum: int, isExternal: bool, isFirst: bool, /) -> Curve2d: ...
    def intPoint(self, intNum: int, /) -> Point3d: ...
    def numResults(self, /) -> int: ...
    def set(self, srf1: PyGe.Surface, srf2: PyGe.Surface, tol: PyGe.Tol = ..., /) -> None: ...
    def surface1(self, /) -> PyGe.Surface: ...
    def surface2(self, /) -> PyGe.Surface: ...
    def tolerance(self, /) -> Tol: ...

class Surface(PyGe.Entity3d):
    def __init__(self) -> None:
        """
        Raises an exception.
        This class cannot be instantiated from Python.
        """
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def cast(otherObject: PyGe.Entity3d, /) -> PyGe.Surface: ...
    @staticmethod
    def className() -> str: ...
    def closestPointTo(self, pt: PyGe.Point3d, tol: PyGe.Tol = ..., /) -> Point3d: ...
    @staticmethod
    def copycast(otherObject: PyGe.Entity3d, /) -> PyGe.Surface: ...
    def distanceTo(self, pt: PyGe.Point3d, tol: PyGe.Tol = ..., /) -> float: ...
    @overload
    def evalPoint(self, param: PyGe.Point2d, /) -> Point3d: ...
    @overload
    def evalPoint(
        self, param: PyGe.Point3d, derivOrd: int, vecs: list[PyGe.Vector3d], /
    ) -> Point3d: ...
    @overload
    def evalPoint(
        self,
        param: PyGe.Point3d,
        derivOrd: int,
        vecs: list[PyGe.Vector3d],
        normal: PyGe.Vector3d,
        /,
    ) -> Point3d: ...
    @overload
    def evalPoint(self, *args) -> Point3d: ...
    def isClosedInU(self, tol: PyGe.Tol = ..., /) -> bool: ...
    def isClosedInV(self, tol: PyGe.Tol = ..., /) -> bool: ...
    def isNormalReversed(self, /) -> bool: ...
    @overload
    def isOn(self, pnt: PyGe.Point3d, /) -> bool: ...
    @overload
    def isOn(self, pnt: PyGe.Point3d, tol: PyGe.Tol = ..., /) -> bool: ...
    @overload
    def isOn(self, pnt: PyGe.Point3d, paramPoint: PyGe.Point2d, /) -> bool: ...
    @overload
    def isOn(
        self, pnt: PyGe.Point3d, paramPoint: PyGe.Point2d, tol: PyGe.Tol = ..., /
    ) -> bool: ...
    @overload
    def isOn(self, *args) -> bool: ...
    def paramOf(self, pt: PyGe.Point3d, tol: PyGe.Tol = ..., /) -> Point2d: ...
    def reverseNormal(self, /) -> None: ...

class Tol:
    def __init__(self, /) -> None: ...
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def current() -> Tol: ...
    def equalPoint(self, /) -> float: ...
    def equalVector(self, /) -> float: ...
    def setEqualPoint(self, val: float, /) -> None: ...
    def setEqualVector(self, val: float, /) -> None: ...
    @staticmethod
    def setGlobalTol(val: PyGe.Tol, /) -> None: ...

class Torus(PyGe.Surface):
    def __init__(self, /) -> None:
        """
        Represents toroidal segment.
        """
    def __reduce__(self, /) -> Any: ...
    @staticmethod
    def cast(otherObject: PyGe.Entity3d, /) -> Torus: ...
    @staticmethod
    def className() -> str: ...
    @staticmethod
    def copycast(otherObject: PyGe.Entity3d, /) -> Torus: ...

class Vector2d:
    def __add__(self, vec: PyGe.Vector2d, /) -> Vector2d: ...
    def __getinitargs__(self, /) -> tuple: ...
    def __getitem__(self, idx: int, /) -> float: ...
    def __hash__(self, /) -> int: ...
    def __iadd__(self, vec: PyGe.Vector2d, /) -> Vector2d: ...
    def __imul__(self, val: float, /) -> Vector2d: ...
    @overload
    def __init__(self, /) -> None: ...
    @overload
    def __init__(self, x: float, y: float, /) -> None: ...
    @overload
    def __init__(self, *args) -> None: ...
    def __isub__(self, vec: PyGe.Vector2d, /) -> Vector2d: ...
    def __itruediv__(self, val: float, /) -> Vector2d: ...
    def __len__(self, /) -> int: ...
    def __mul__(self, val: float, /) -> Vector2d: ...
    def __ne__(self, other: PyGe.Vector2d, /) -> bool: ...
    def __reduce__(self, /) -> Any: ...
    @overload
    def __rmul__(self, val: float, /) -> Vector2d: ...
    @overload
    def __rmul__(self, xform: PyGe.Matrix2d, /) -> Vector2d: ...
    @overload
    def __rmul__(self, *args) -> Vector2d: ...
    def __setitem__(self, idx: int, val: float, /) -> None: ...
    def __sub__(self, /) -> Vector2d: ...
    def __truediv__(self, val: float, /) -> Vector2d: ...
    def angle(self, /) -> float: ...
    def angleTo(self, vec: PyGe.Vector2d, /) -> float: ...
    def dotProduct(self, vec: PyGe.Vector2d, /) -> float: ...
    def isCodirectionalTo(self, vec: PyGe.Vector2d, tol: PyGe.Tol = ..., /) -> bool: ...
    def isEqualTo(self, vec: PyGe.Vector3d, tol: PyGe.Tol = ..., /) -> bool: ...
    def isParallelTo(self, vec: PyGe.Vector2d, tol: PyGe.Tol = ..., /) -> bool: ...
    def isPerpendicularTo(self, vec: PyGe.Vector2d, tol: PyGe.Tol = ..., /) -> bool: ...
    def isUnitLength(self, tol: PyGe.Tol = ..., /) -> bool: ...
    def isZeroLength(self, tol: PyGe.Tol = ..., /) -> bool: ...
    kIdentity: PyGe.Vector2d
    kXAxis: PyGe.Vector2d
    kYAxis: PyGe.Vector2d
    def length(self, /) -> float: ...
    def lengthSqrd(self, /) -> float: ...
    def mirror(self, vec: PyGe.Vector2d, /) -> Vector2d: ...
    def negate(self, /) -> Vector2d: ...
    def normal(self, tol: PyGe.Tol = ..., /) -> Vector2d: ...
    def normalize(self, tol: PyGe.Tol = ..., /) -> Vector2d: ...
    def rotateBy(self, val: float, /) -> Vector2d: ...
    def set(self, xx: float, yy: float, /) -> Vector2d: ...
    @overload
    def setToProduct(self, vec: PyGe.Vector2d, s: float, /) -> Vector2d: ...
    @overload
    def setToProduct(self, xform: PyGe.Matrix2d, vec: PyGe.Vector3d, /) -> Vector2d: ...
    @overload
    def setToProduct(self, *args) -> Vector2d: ...
    def setToSum(self, v1: PyGe.Vector2d, v2: PyGe.Vector2d, /) -> Vector2d: ...
    def toList(self, /) -> list[float]: ...
    def toString(self, /) -> str: ...
    def toTuple(self, /) -> tuple[float, float]: ...
    def transformBy(self, xform: PyGe.Matrix2d, /) -> Vector2d: ...
    @property
    def x(self, /) -> float: ...
    @property
    def y(self, /) -> float: ...

class Vector3d:
    def __add__(self, vec: PyGe.Vector3d, /) -> Vector3d: ...
    def __getinitargs__(self, /) -> tuple: ...
    def __getitem__(self, idx: int, /) -> float: ...
    def __hash__(self, /) -> int: ...
    def __iadd__(self, vec: PyGe.Vector3d, /) -> Vector3d: ...
    def __imul__(self, val: float, /) -> Vector3d: ...
    @overload
    def __init__(self, /) -> None: ...
    @overload
    def __init__(self, floats: tuple[float] | list[float], /) -> None: ...
    @overload
    def __init__(self, x: float, y: float, z: float, /) -> None: ...
    @overload
    def __init__(self, pln: PyGe.PlanarEnt, pnt2d: PyGe.Vector2d, /) -> None: ...
    @overload
    def __init__(self, *args) -> None: ...
    def __isub__(self, vec: PyGe.Vector3d, /) -> Vector3d: ...
    def __itruediv__(self, val: float, /) -> Vector3d: ...
    def __len__(self, /) -> int: ...
    def __mul__(self, val: float, /) -> Vector3d: ...
    def __ne__(self, vec: PyGe.Vector3d, /) -> bool: ...
    def __reduce__(self, /) -> Any: ...
    def __rmul__(self, val: float | PyGe.Matrix3d, /) -> Vector3d: ...
    def __setitem__(self, idx: int, val: float, /) -> None: ...
    def __sub__(self, vec: PyGe.Vector3d, /) -> Vector3d: ...
    def __truediv__(self, val: float, /) -> Vector3d: ...
    def angleOnPlane(self, pln: PyGe.PlanarEnt, /) -> float:
        """
        Returns the angle between the orthogonal projection of this vector into the plane through
        the origin with the same normal as planar entity pln and the zeroth basis vector v0 of the
        planar entity pln provided by the function pln.getCoordSystem (p, v0, v1).
        """
    def angleTo(self, vec: PyGe.Vector3d, ref: PyGe.Vector3d = ..., /) -> float:
        """
        Returns the angle between this vector and the vector vec in the range [0, Pi].
        """
    def convert2d(self, pln: PyGe.PlanarEnt, /) -> Vector2d:
        """
        Returns 2D vector with the coordinates corresponding to the decomposition of this vector in
        the basis uAxis, vAxis in the planar entity pln, where uAxis and vAxis can be found by
        function call pln.get(p, uAxis, vAxis). Contract: This 3D vector is assumed to be parallel
        to the planar entity pln.
        """
    def crossProduct(self, vec: PyGe.Vector3d, /) -> Vector3d:
        """
        Returns the cross product of this vector and vector vec.
        """
    def dotProduct(self, vec: PyGe.Vector3d, /) -> float:
        """
        Returns the dot product of this vector and vector v.
        """
    def isCodirectionalTo(self, vec: PyGe.Vector3d, tol: PyGe.Tol = ..., /) -> bool:
        """
        Checks if this vector is codirectional to the vector vec. Namely, it checks if after
        normalization this vector is within the distance tol.equalVector() from the normalization
        of the vector vec. Returns Adesk::kTrue if this condition is met and Adesk::kFalse
        otherwise.
        """
    def isEqualTo(self, vec: PyGe.Vector3d, tol: PyGe.Tol = ..., /) -> bool:
        """
        Checks if this vector is within the distance tol.equalVector() from the vector vec. The
        default value of the tolerance class tol is AcGeContext::gTol. Returns Adesk::kTrue if this
        condition is met and Adesk::kFalse otherwise.
        """
    def isParallelTo(self, vec: PyGe.Vector3d, tol: PyGe.Tol = ..., /) -> bool:
        """
        Checks if this vector is parallel to the vector vec. Namely, it checks if after
        normalization (and negation, in the case of negative dot product with the vector vec), this
        vector is within the distance tol.equalVector() from the normalization of the vector vec.
        Returns Adesk::kTrue if this condition is met and Adesk::kFalse otherwise.
        """
    def isPerpendicularTo(self, vec: PyGe.Vector3d, tol: PyGe.Tol = ..., /) -> bool:
        """
        Checks if this vector is perpendicular to the vector vec. Namely, it checks if after
        normalization the dot product of this vector with the normalization of the vector vec is
        less than tol.equalVector() in absolute value. Returns Adesk::kTrue if this condition is
        met and Adesk::kFalse otherwise.
        """
    def isUnitLength(self, tol: PyGe.Tol = ..., /) -> bool:
        """
        Returns Adesk::kTrue if this vector is equal to its normalization. Returns Adesk::kFalse
        otherwise.
        """
    def isZeroLength(self, tol: PyGe.Tol = ..., /) -> bool:
        """
        Returns Adesk::kTrue if this vector is a zero length vector, Adesk::kFalse otherwise.
        """
    kIdentity: PyGe.Vector3d
    kXAxis: PyGe.Vector3d
    kYAxis: PyGe.Vector3d
    kZAxis: PyGe.Vector3d
    def largestElement(self, /) -> int:
        """
        Returns the index of the largest absolute value coordinate of this vector.
        """
    def length(self, /) -> float:
        """
        Returns the Euclidean length of this vector.
        """
    def lengthSqrd(self, /) -> float:
        """
        Returns the square of the Euclidean length of this vector.
        """
    def mirror(self, normalToPlane: PyGe.Vector3d, /) -> Vector3d:
        """
        Returns the 3D vector which is the result of mirroring of this vector with respect to the
        plane with the normal normalToPlane passing through the origin.
        """
    def negate(self, /) -> Vector3d:
        """
        Negates this vector, namely sets it to be equal to the vector (-x,-y). Returns the
        reference to this vector.
        """
    def normal(self, tol: PyGe.Tol = ..., /) -> Vector3d:
        """
        Returns the unit vector codirectional to this vector. The vector is not normalized if its
        length is less than tol.equalVector(), in which case the returned vector is the same as
        this vector.
        """
    def normalize(self, /) -> Vector3d:
        """
        Sets this vector to the unit vector codirectional to this vector. Returns the reference to
        this vector. This vector is not normalized if its length is less than tol.equalVector(), in
        which case it remains unchanged. The flag argument will be set to the following value to
        indicate if a failure may have occurred: k0This.
        """
    def orthoProject(self, planeNormal: PyGe.Vector3d, tol: PyGe.Tol = ..., /) -> Vector3d:
        """
        Returns a 3D vector which is the result of the orthogonal projection of this point into the
        plane with normal planeNormal passing through the origin.
        """
    def perpVector(self, /) -> Vector3d:
        """
        Returns a vector orthogonal to this vector. The choice of the orthogonal vector is
        determined by the function AcGeContext::gOrthoVector.
        """
    def project(self, pln: PyGe.Vector3d, dir: PyGe.Vector3d, tol: PyGe.Tol = ..., /) -> Vector3d:
        """
        Returns the 3D vector that is the result of the parallel projection of this vector into the
        plane with normal planeNormal passing through the origin. The direction of projection is
        defined by vector projectDirection.
        """
    def rotateBy(self, angle: float, axis: PyGe.Vector3d, /) -> Vector3d:
        """
        Returns 3D point which is the result of rotation of this vector around the line with axis
        passing through the origin. Rotation angle is given by the argument ang, where positive
        direction of rotation is defined by the right-hand rule.
        """
    def rotateTo(
        self, vec: PyGe.Vector3d, axis: PyGe.Vector3d = PyGe.Vector3d.kIdentity, /
    ) -> Matrix3d:
        """
        Returns a matrix mat such that matX this vector yields the argument vector vec. There is no
        unique matrix to represent a rotation from this vector to vec when they are parallel and in
        opposite directions. In this case, the argument axis is used (if it is perpendicular to
        this vector) to uniquely determine the resultant matrix. axis defaults to the zero-length
        vector, in which case an arbitrary (but correct) matrix will be returned that rotates this
        vector to vec. Contract: This vector and vec must be non-zero length.
        """
    @overload
    def set(self, x: float, y: float, z: float, /) -> Vector3d: ...
    @overload
    def set(self, pln: PyGe.PlanarEnt, pnt2d: PyGe.Vector2d, /) -> Vector3d: ...
    @overload
    def set(self, *args) -> Vector3d: ...
    @overload
    def setToProduct(self, vec: PyGe.Vector3d, s: float, /) -> Vector3d: ...
    @overload
    def setToProduct(self, xform: PyGe.Matrix3d, vec: PyGe.Vector3d, /) -> Vector3d: ...
    @overload
    def setToProduct(self, *args) -> Vector3d: ...
    def setToSum(self, v1: PyGe.Vector3d, v2: PyGe.Vector3d, /) -> Vector3d:
        """
        Sets this vector to the sum of the vector v1 and vector v2. Returns the reference to this
        vector.
        """
    def toList(self, /) -> list[float]: ...
    def toString(self, /) -> str: ...
    def toTuple(self, /) -> tuple[float, float, float]: ...
    def transformBy(self, xform: PyGe.Matrix3d, /) -> Vector3d:
        """
        Transform this vector by pre-multiplying it by the matrix leftSide. Returns the reference
        to this vector. Result is the same as setToProduct(leftSide, *this).
        """
    @property
    def x(self, /) -> float: ...
    @property
    def y(self, /) -> float: ...
    @property
    def z(self, /) -> float: ...
