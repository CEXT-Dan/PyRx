#include "stdafx.h"
#include "PyAcGe.h"

using namespace boost::python;


std::string AcGeVector2ToString(const AcGeVector2d& p)
{
    return std::format("({},{})", p.x, p.y);
}

std::string AcGePoint2dToString(const AcGePoint2d& p)
{
    return std::format("({},{})", p.x, p.y);
}

std::string AcGeVector3dToString(const AcGeVector3d& p)
{
    return std::format("({},{},{})", p.x, p.y, p.z);
}

std::string AcGePoint3dToString(const AcGePoint3d& p)
{
   return std::format("({},{},{})", p.x, p.y, p.z);
}

static auto makeAcGePoint2dWrapper()
{
    static auto wrapper = class_<AcGePoint2d>("Point2d")
        .def(init<>())
        .def(init<double, double>())
        .def("distanceTo", &AcGePoint2d::distanceTo)
        .def("transformBy", &AcGePoint2d::transformBy, return_value_policy<reference_existing_object>())
        .def_readwrite("x", &AcGePoint2d::x)
        .def_readwrite("y", &AcGePoint2d::y)
        .def_readonly("kOrigin", &AcGePoint2d::kOrigin)
        .def("toString", &AcGePoint2dToString)
        ;
    return wrapper;
}

static auto makeAcGeVector2dWrapper()
{
    static auto wrapper = class_<AcGeVector2d>("Vector2d")
        .def(init<>())
        .def(init<double, double>())
        .def_readonly("kXAxis", &AcGeVector2d::kXAxis)
        .def_readonly("kYAxis", &AcGeVector2d::kYAxis)
        .def("toString", &AcGeVector2ToString)
        ;
    return wrapper;
}

static auto makeAcGeMatrix2dWrapper()
{
    static auto wrapper = class_<AcGeMatrix2d>("Matrix2d")
        .def("scale", &AcGeMatrix2d::scale)
        .def("setToScaling", &AcGeMatrix2d::setToScaling, return_value_policy<reference_existing_object>())
        .def("setToRotation", &AcGeMatrix2d::setToRotation, return_value_policy<reference_existing_object>())
        ;
    return wrapper;
}

static auto makeAcGePoint3dWrapper()
{
    static auto wrapper = class_<AcGePoint3d>("Point3d")
        .def(init<>())
        .def(init<double, double, double>())
        .def("distanceTo", &AcGePoint3d::distanceTo)
        .def("transformBy", &AcGePoint3d::transformBy, return_value_policy<reference_existing_object>())
        .def_readwrite("x", &AcGePoint3d::x)
        .def_readwrite("y", &AcGePoint3d::y)
        .def_readwrite("z", &AcGePoint3d::z)
        .def_readonly("kOrigin", &AcGePoint3d::kOrigin)
        .def("toString", &AcGePoint3dToString)
        ;
    return wrapper;
}

void makeAcGeTolWrapper()
{
    static auto wrapper = class_<AcGeTol>("GeTol")
        .def(init<>())
        .def_readonly("equalPoint", &AcGeTol::equalPoint)
        .def_readonly("equalVector", &AcGeTol::equalVector)
        .def_readonly("setEqualPoint", &AcGeTol::setEqualPoint)
        .def_readonly("setEqualVector", &AcGeTol::setEqualVector)
        ;
}

static auto makeAcGeVector3dWrapper()
{
    static auto wrapper = class_<AcGeVector3d>("Vector3d")
        .def(init<>())
        .def(init<double, double, double>())
        .def_readonly("kXAxis", &AcGeVector3d::kXAxis)
        .def_readonly("kYAxis", &AcGeVector3d::kYAxis)
        .def_readonly("kZAxis", &AcGeVector3d::kZAxis)
        .def("toString", &AcGeVector3dToString)
        ;
    return wrapper;
}

static auto makeAcGeMatrix3dWrapper()
{
    static auto wrapper = class_<AcGeMatrix3d>("Matrix3d")
        .def("scale", &AcGeMatrix3d::scale)
        .def("setToScaling", &AcGeMatrix3d::setToScaling, return_value_policy<reference_existing_object>())
        .def("setToRotation", &AcGeMatrix3d::setToRotation, return_value_policy<reference_existing_object>())
        ;
    return wrapper;
}

static auto makeAcGeScale3dWrapper()
{
    static auto wrapper = class_<AcGeScale3d>("Scale3d")
        .def_readwrite("sx", &AcGeScale3d::sx)
        .def_readwrite("sy", &AcGeScale3d::sy)
        .def_readwrite("sz", &AcGeScale3d::sz)
        ;
    return wrapper;
}

static auto makeAcGeScale2dWrapper()
{
    static auto wrapper = class_<AcGeScale2d>("Scale2d")
        .def_readwrite("sx", &AcGeScale2d::sx)
        .def_readwrite("sy", &AcGeScale2d::sy)
        ;
    return wrapper;
}

BOOST_PYTHON_MODULE(PyGe)
{
#ifndef  PyRxDebug
    docstring_options local_docstring_options(false, true, false);
#endif // ! PyRxDebug

    makeAcGeTolWrapper();
    makeAcGePoint2dWrapper();
    makeAcGeVector2dWrapper();
    makeAcGeMatrix2dWrapper();

    makeAcGePoint3dWrapper();
    makeAcGeVector3dWrapper();
    makeAcGeMatrix3dWrapper();

    makeAcGeScale3dWrapper();
    makeAcGeScale2dWrapper();

    enum_<AcGe::EntityId>("EntityId")
        .value("Entity2d", AcGe::EntityId::kEntity2d)
        .value("Entity3d", AcGe::EntityId::kEntity3d)
        .value("PointEnt2d", AcGe::EntityId::kPointEnt2d)
        .value("PointEnt3d", AcGe::EntityId::kPointEnt3d)
        .value("Position2d", AcGe::EntityId::kPosition2d)
        .value("Position3d", AcGe::EntityId::kPosition3d)
        .value("PointOnCurve2d", AcGe::EntityId::kPointOnCurve2d)
        .value("PointOnCurve3d", AcGe::EntityId::kPointOnCurve3d)
        .value("PointOnSurface", AcGe::EntityId::kPointOnSurface)
        .value("BoundedPlane", AcGe::EntityId::kBoundedPlane)
        .value("CircArc2d", AcGe::EntityId::kCircArc2d)
        .value("CircArc3d", AcGe::EntityId::kCircArc3d)
        .value("Conic2d", AcGe::EntityId::kConic2d)
        .value("Conic3d", AcGe::EntityId::kConic3d)
        .value("Curve2d", AcGe::EntityId::kCurve2d)
        .value("Curve3d", AcGe::EntityId::kCurve3d)
        .value("EllipArc2d", AcGe::EntityId::kEllipArc2d)
        .value("EllipArc3d", AcGe::EntityId::kEllipArc3d)
        .value("Line2d", AcGe::EntityId::kLine2d)
        .value("Line3d", AcGe::EntityId::kLine3d)
        .value("LinearEnt2d", AcGe::EntityId::kLinearEnt2d)
        .value("LinearEnt3d", AcGe::EntityId::kLinearEnt3d)
        .value("LineSeg2d", AcGe::EntityId::kLineSeg2d)
        .value("LineSeg3d", AcGe::EntityId::kLineSeg3d)
        .value("PlanarEnt", AcGe::EntityId::kPlanarEnt)
        .value("Plane", AcGe::EntityId::kPlane)
        .value("Ray2d", AcGe::EntityId::kRay2d)
        .value("Ray3d", AcGe::EntityId::kRay3d)
        .value("Surface", AcGe::EntityId::kSurface)
        .value("Sphere", AcGe::EntityId::kSphere)
        .value("Cylinder", AcGe::EntityId::kCylinder)
        .value("Torus", AcGe::EntityId::kTorus)
        .value("Cone", AcGe::EntityId::kCone)
        .value("SplineEnt2d", AcGe::EntityId::kSplineEnt2d)
        .value("Polyline2d", AcGe::EntityId::kPolyline2d)
        .value("AugPolyline2d", AcGe::EntityId::kAugPolyline2d)
        .value("NurbCurve2d", AcGe::EntityId::kNurbCurve2d)
        .value("DSpline2d", AcGe::EntityId::kDSpline2d)
        .value("CubicSplineCurve2d", AcGe::EntityId::kCubicSplineCurve2d)
        .value("SplineEnt3d", AcGe::EntityId::kSplineEnt3d)
        .value("Polyline3d", AcGe::EntityId::kPolyline3d)
        .value("AugPolyline3d", AcGe::EntityId::kAugPolyline3d)
        .value("NurbCurve3d", AcGe::EntityId::kNurbCurve3d)
        .value("DSpline3d", AcGe::EntityId::kDSpline3d)
        .value("CubicSplineCurve3d", AcGe::EntityId::kCubicSplineCurve3d)
        .value("TrimmedCrv2d", AcGe::EntityId::kTrimmedCrv2d)
        .value("CompositeCrv2d", AcGe::EntityId::kCompositeCrv2d)
        .value("CompositeCrv3d", AcGe::EntityId::kCompositeCrv3d)
        .value("ExternalSurface", AcGe::EntityId::kExternalSurface)
        .value("NurbSurface", AcGe::EntityId::kNurbSurface)
        .value("TrimmedSurface", AcGe::EntityId::kTrimmedSurface)
        .value("OffsetSurface", AcGe::EntityId::kOffsetSurface)
        .value("Envelope2d", AcGe::EntityId::kEnvelope2d)
        .value("CurveBoundedSurface", AcGe::EntityId::kCurveBoundedSurface)
        .value("ExternalCurve3d", AcGe::EntityId::kExternalCurve3d)
        .value("ExternalCurve2d", AcGe::EntityId::kExternalCurve2d)
        .value("SurfaceCurve2dTo3d", AcGe::EntityId::kSurfaceCurve2dTo3d)
        .value("SurfaceCurve3dTo2d", AcGe::EntityId::kSurfaceCurve3dTo2d)
        .value("ExternalBoundedSurface", AcGe::EntityId::kExternalBoundedSurface)
        .value("CurveCurveInt2d", AcGe::EntityId::kCurveCurveInt2d)
        .value("CurveCurveInt3d", AcGe::EntityId::kCurveCurveInt3d)
        .value("BoundBlock2d", AcGe::EntityId::kBoundBlock2d)
        .value("BoundBlock3d", AcGe::EntityId::kBoundBlock3d)
        .value("OffsetCurve2d", AcGe::EntityId::kOffsetCurve2d)
        .value("OffsetCurve3d", AcGe::EntityId::kOffsetCurve3d)
        .value("PolynomCurve3d", AcGe::EntityId::kPolynomCurve3d)
        .value("BezierCurve3d", AcGe::EntityId::kBezierCurve3d)
        .value("Object", AcGe::EntityId::kObject)
        .value("FitData3d", AcGe::EntityId::kFitData3d)
        .value("Hatch", AcGe::EntityId::kHatch)
        .value("TrimmedCurve2d", AcGe::EntityId::kTrimmedCurve2d)
        .value("TrimmedCurve3d", AcGe::EntityId::kTrimmedCurve3d)
        .value("CurveSampleData", AcGe::EntityId::kCurveSampleData)
        .value("EllipCone", AcGe::EntityId::kEllipCone)
        .value("EllipCylinder", AcGe::EntityId::kEllipCylinder)
        .value("IntervalBoundBlock", AcGe::EntityId::kIntervalBoundBlock)
        .value("ClipBoundary2d", AcGe::EntityId::kClipBoundary2d)
        .value("ExternalObject", AcGe::EntityId::kExternalObject)
        .value("CurveSurfaceInt", AcGe::EntityId::kCurveSurfaceInt)
        .value("SurfaceSurfaceInt", AcGe::EntityId::kSurfaceSurfaceInt)
#ifndef BRXAPP
        .value("Helix", AcGe::EntityId::kHelix)
#endif // !BRXAPP 
        ;
};

void initPyGeModule()
{
    PyImport_AppendInittab(PyGeNamespace, &PyInit_PyGe);
}
