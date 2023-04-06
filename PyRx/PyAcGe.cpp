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
        .value("kEntity2d", AcGe::EntityId::kEntity2d)
        .value("kEntity3d", AcGe::EntityId::kEntity3d)
        .value("kPointEnt2d", AcGe::EntityId::kPointEnt2d)
        .value("kPointEnt3d", AcGe::EntityId::kPointEnt3d)
        .value("kPosition2d", AcGe::EntityId::kPosition2d)
        .value("kPosition3d", AcGe::EntityId::kPosition3d)
        .value("kPointOnCurve2d", AcGe::EntityId::kPointOnCurve2d)
        .value("kPointOnCurve3d", AcGe::EntityId::kPointOnCurve3d)
        .value("kPointOnSurface", AcGe::EntityId::kPointOnSurface)
        .value("kBoundedPlane", AcGe::EntityId::kBoundedPlane)
        .value("kCircArc2d", AcGe::EntityId::kCircArc2d)
        .value("kCircArc3d", AcGe::EntityId::kCircArc3d)
        .value("kConic2d", AcGe::EntityId::kConic2d)
        .value("kConic3d", AcGe::EntityId::kConic3d)
        .value("kCurve2d", AcGe::EntityId::kCurve2d)
        .value("kCurve3d", AcGe::EntityId::kCurve3d)
        .value("kEllipArc2d", AcGe::EntityId::kEllipArc2d)
        .value("kEllipArc3d", AcGe::EntityId::kEllipArc3d)
        .value("kLine2d", AcGe::EntityId::kLine2d)
        .value("kLine3d", AcGe::EntityId::kLine3d)
        .value("kLinearEnt2d", AcGe::EntityId::kLinearEnt2d)
        .value("kLinearEnt3d", AcGe::EntityId::kLinearEnt3d)
        .value("kLineSeg2d", AcGe::EntityId::kLineSeg2d)
        .value("kLineSeg3d", AcGe::EntityId::kLineSeg3d)
        .value("kPlanarEnt", AcGe::EntityId::kPlanarEnt)
        .value("kPlane", AcGe::EntityId::kPlane)
        .value("kRay2d", AcGe::EntityId::kRay2d)
        .value("kRay3d", AcGe::EntityId::kRay3d)
        .value("kSurface", AcGe::EntityId::kSurface)
        .value("kSphere", AcGe::EntityId::kSphere)
        .value("kCylinder", AcGe::EntityId::kCylinder)
        .value("kTorus", AcGe::EntityId::kTorus)
        .value("kCone", AcGe::EntityId::kCone)
        .value("kSplineEnt2d", AcGe::EntityId::kSplineEnt2d)
        .value("kPolyline2d", AcGe::EntityId::kPolyline2d)
        .value("kAugPolyline2d", AcGe::EntityId::kAugPolyline2d)
        .value("kNurbCurve2d", AcGe::EntityId::kNurbCurve2d)
        .value("kDSpline2d", AcGe::EntityId::kDSpline2d)
        .value("kCubicSplineCurve2d", AcGe::EntityId::kCubicSplineCurve2d)
        .value("kSplineEnt3d", AcGe::EntityId::kSplineEnt3d)
        .value("kPolyline3d", AcGe::EntityId::kPolyline3d)
        .value("kAugPolyline3d", AcGe::EntityId::kAugPolyline3d)
        .value("kNurbCurve3d", AcGe::EntityId::kNurbCurve3d)
        .value("kDSpline3d", AcGe::EntityId::kDSpline3d)
        .value("kCubicSplineCurve3d", AcGe::EntityId::kCubicSplineCurve3d)
        .value("kTrimmedCrv2d", AcGe::EntityId::kTrimmedCrv2d)
        .value("kCompositeCrv2d", AcGe::EntityId::kCompositeCrv2d)
        .value("kCompositeCrv3d", AcGe::EntityId::kCompositeCrv3d)
        .value("kExternalSurface", AcGe::EntityId::kExternalSurface)
        .value("kNurbSurface", AcGe::EntityId::kNurbSurface)
        .value("kTrimmedSurface", AcGe::EntityId::kTrimmedSurface)
        .value("kOffsetSurface", AcGe::EntityId::kOffsetSurface)
        .value("kEnvelope2d", AcGe::EntityId::kEnvelope2d)
        .value("kCurveBoundedSurface", AcGe::EntityId::kCurveBoundedSurface)
        .value("kExternalCurve3d", AcGe::EntityId::kExternalCurve3d)
        .value("kExternalCurve2d", AcGe::EntityId::kExternalCurve2d)
        .value("kSurfaceCurve2dTo3d", AcGe::EntityId::kSurfaceCurve2dTo3d)
        .value("kSurfaceCurve3dTo2d", AcGe::EntityId::kSurfaceCurve3dTo2d)
        .value("kExternalBoundedSurface", AcGe::EntityId::kExternalBoundedSurface)
        .value("kCurveCurveInt2d", AcGe::EntityId::kCurveCurveInt2d)
        .value("kCurveCurveInt3d", AcGe::EntityId::kCurveCurveInt3d)
        .value("kBoundBlock2d", AcGe::EntityId::kBoundBlock2d)
        .value("kBoundBlock3d", AcGe::EntityId::kBoundBlock3d)
        .value("kOffsetCurve2d", AcGe::EntityId::kOffsetCurve2d)
        .value("kOffsetCurve3d", AcGe::EntityId::kOffsetCurve3d)
        .value("kPolynomCurve3d", AcGe::EntityId::kPolynomCurve3d)
        .value("kBezierCurve3d", AcGe::EntityId::kBezierCurve3d)
        .value("kObject", AcGe::EntityId::kObject)
        .value("kFitData3d", AcGe::EntityId::kFitData3d)
        .value("kHatch", AcGe::EntityId::kHatch)
        .value("kTrimmedCurve2d", AcGe::EntityId::kTrimmedCurve2d)
        .value("kTrimmedCurve3d", AcGe::EntityId::kTrimmedCurve3d)
        .value("kCurveSampleData", AcGe::EntityId::kCurveSampleData)
        .value("kEllipCone", AcGe::EntityId::kEllipCone)
        .value("kEllipCylinder", AcGe::EntityId::kEllipCylinder)
        .value("kIntervalBoundBlock", AcGe::EntityId::kIntervalBoundBlock)
        .value("kClipBoundary2d", AcGe::EntityId::kClipBoundary2d)
        .value("kExternalObject", AcGe::EntityId::kExternalObject)
        .value("kCurveSurfaceInt", AcGe::EntityId::kCurveSurfaceInt)
        .value("kSurfaceSurfaceInt", AcGe::EntityId::kSurfaceSurfaceInt)
#ifndef BRXAPP
        .value("Helix", AcGe::EntityId::kHelix)
#endif // !BRXAPP 
        ;
};

void initPyGeModule()
{
    PyImport_AppendInittab(PyGeNamespace, &PyInit_PyGe);
}
