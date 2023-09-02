#pragma once
#include "PyGeEntity3d.h"
class PyGeInterval;
class PyGePointOnCurve3d;
class PyGeBoundBlock3d;
class PyGePlane;
class PyGePlanarEnt;
class PyGeLinearEnt3d;
//-----------------------------------------------------------------------------------
//PyGeCurve3d
void makePyGeCurve3dWrapper();
class PyGeCurve3d : public PyGeEntity3d
{
public:
    PyGeCurve3d(AcGeEntity3d* pEnt);
    PyGeInterval    getInterval() const;
    AcGePoint3d     getStartPoint() const;
    AcGePoint3d     getEndPoint() const;
    PyGeCurve3d&    reverseParam();
    PyGeCurve3d&    setInterval1();
    bool            setInterval2(const PyGeInterval& intrvl);
    double          distanceTo1(const AcGePoint3d& pnt) const;
    double          distanceTo2(const AcGePoint3d& pnt, const AcGeTol& tol) const;
    double          distanceTo3(const PyGeCurve3d&) const;
    double          distanceTo4(const PyGeCurve3d&, const AcGeTol& tol) const;
    AcGePoint3d     closestPointTo1(const AcGePoint3d& pnt) const;
    AcGePoint3d     closestPointTo2(const AcGePoint3d& pnt, const AcGeTol& tol) const;
    boost::python::tuple  closestPointTo3(const PyGeCurve3d& curve2d) const;
    boost::python::tuple  closestPointTo4(const PyGeCurve3d& curve2d, const AcGeTol& tol) const;
    PyGePointOnCurve3d    getClosestPointTo1(const AcGePoint3d& pnt);
    PyGePointOnCurve3d    getClosestPointTo2(const AcGePoint3d& pnt, const AcGeTol& tol);
    boost::python::tuple  getClosestPointsTo1(const PyGeCurve3d& curve);
    boost::python::tuple  getClosestPointsTo2(const PyGeCurve3d& curve, const AcGeTol& tol);
    AcGePoint3d     projClosestPointTo1(const AcGePoint3d& pnt, const AcGeVector3d& projectDirection) const;
    AcGePoint3d     projClosestPointTo2(const AcGePoint3d& pnt, const AcGeVector3d& projectDirection, const AcGeTol& tol) const;
    boost::python::tuple projClosestPointsTo1(const PyGeCurve3d& curve3d, const AcGeVector3d& projectDirection) const;
    boost::python::tuple projClosestPointsTo2(const PyGeCurve3d& curve3d, const AcGeVector3d& projectDirection, const AcGeTol& tol) const;
    PyGePointOnCurve3d   getProjClosestPointTo1(const AcGePoint3d& pnt, const AcGeVector3d& projectDirection) const;
    PyGePointOnCurve3d   getProjClosestPointTo2(const AcGePoint3d& pnt, const AcGeVector3d& projectDirection, const AcGeTol& tol) const;
    boost::python::tuple getProjClosestPointsTo1(const PyGeCurve3d& curve3d, const AcGeVector3d& projectDirection) const;
    boost::python::tuple getProjClosestPointsTo2(const PyGeCurve3d& curve3d, const AcGeVector3d& projectDirection, const AcGeTol& tol) const;
    PyGePointOnCurve3d getNormalPoint1(const AcGePoint3d& pnt);
    PyGePointOnCurve3d getNormalPoint2(const AcGePoint3d& pnt, const AcGeTol& tol);
    PyGeBoundBlock3d   boundBlock1() const;
    PyGeBoundBlock3d   boundBlock2(const PyGeInterval& range) const;
    PyGeBoundBlock3d   orthoBoundBlock1() const;
    PyGeBoundBlock3d   orthoBoundBlock2(const PyGeInterval& range) const;
    PyGeEntity3d    project1(const PyGePlane& projectionPlane, const AcGeVector3d& projectDirection) const;
    PyGeEntity3d    project2(const PyGePlane& projectionPlane, const AcGeVector3d& projectDirection, const AcGeTol& tol) const;
    PyGeEntity3d    orthoProject1(const PyGePlane& projectionPlane) const;
    PyGeEntity3d    orthoProject2(const PyGePlane& projectionPlane, const AcGeTol& tol) const;
    bool            isOn1(const AcGePoint3d& pnt) const;
    bool            isOn2(const AcGePoint3d& pnt, const AcGeTol& tol) const;
    bool            isOn3(const AcGePoint3d& pnt, double& param) const;
    bool            isOn4(const AcGePoint3d& pnt, double& param, const AcGeTol& tol) const;
    bool            isOn5(double param) const;
    bool            isOn6(double param, const AcGeTol& tol) const;
    double          paramOf1(const AcGePoint3d& pnt) const;
    double          paramOf2(const AcGePoint3d& pnt, const AcGeTol& tol) const;
    boost::python::list getTrimmedOffset1(double distance, const AcGeVector3d& planeNormal, AcGe::OffsetCrvExtType extensionType) const;
    boost::python::list getTrimmedOffset2(double distance, const AcGeVector3d& planeNormal, AcGe::OffsetCrvExtType extensionType, const AcGeTol& tol) const;
    Adesk::Boolean  isClosed1() const;
    Adesk::Boolean  isClosed2(const AcGeTol& tol) const;
    boost::python::tuple isPlanar1() const;
    boost::python::tuple isPlanar2(const AcGeTol& tol) const;
    boost::python::tuple isLinear1() const;
    boost::python::tuple isLinear2(const AcGeTol& tol) const;
    boost::python::tuple isCoplanarWith1(const PyGeCurve3d& curve3d) const;
    boost::python::tuple isCoplanarWith2(const PyGeCurve3d& curve3d, const AcGeTol& tol) const;
    boost::python::tuple isPeriodic() const;
    double          length1(double fromParam, double toParam) const;
    double          length2(double fromParam, double toParam, double tol) const;
    double          paramAtLength1(double datumParam, double length) const;
    double          paramAtLength2(double datumParam, double length, Adesk::Boolean posParamDir, double tol) const;
    double          area1(double startParam, double endParam) const;
    double          area2(double startParam, double endParam, const AcGeTol& tol) const;
    boost::python::tuple isDegenerate1() const;
    boost::python::tuple isDegenerate2(const AcGeTol& tol) const;
    boost::python::tuple getSplitCurves(double param);
    boost::python::list explode1();
    boost::python::list explode2(const PyGeInterval& interval);
    bool            hasStartPoint() const;
    bool            hasEndPoint() const;
    AcGePoint3d     evalPoint1(double param) const;
    boost::python::tuple evalPoint2(double param, int numDeriv) const;
    boost::python::list  getSamplePoints1(int numSample) const;
    boost::python::list  getSamplePoints2(double fromParam, double toParam, double approxEps) const;
    static std::string   className();
public:
    AcGeCurve3d* impObj(const std::source_location& src = std::source_location::current()) const;
};
//-----------------------------------------------------------------------------------
//AcGeCircArc3d
void makePyGeCircArc3dWrapper();
class PyGeCircArc3d : public PyGeCurve3d
{
public:
    PyGeCircArc3d();
    PyGeCircArc3d(const AcGeCircArc3d& arc);
    PyGeCircArc3d(const AcGePoint3d& cent, const AcGeVector3d& nrm, double radius);
    PyGeCircArc3d(const AcGePoint3d& cent, const AcGeVector3d& nrm, const AcGeVector3d& refVec, double radius, double startAngle, double endAngle);
    PyGeCircArc3d(const AcGePoint3d& startPoint, const AcGePoint3d& pnt, const AcGePoint3d& endPoint);
    PyGeCircArc3d(AcGeEntity3d* pEnt);
    boost::python::tuple closestPointToPlane1(const PyGePlanarEnt& plane);
    boost::python::tuple closestPointToPlane2(const PyGePlanarEnt& plane, const AcGeTol& tol);
    boost::python::tuple intersectWith1(const PyGeLinearEnt3d& line);
    boost::python::tuple intersectWith2(const PyGeLinearEnt3d& line, const AcGeTol& tol);
    boost::python::tuple intersectWith3(const PyGeCircArc3d& line);
    boost::python::tuple intersectWith4(const PyGeCircArc3d& line, const AcGeTol& tol);
    boost::python::tuple intersectWith5(const PyGePlanarEnt& line);
    boost::python::tuple intersectWith6(const PyGePlanarEnt& line, const AcGeTol& tol);
    boost::python::tuple projIntersectWith1(const PyGeLinearEnt3d& line, const AcGeVector3d& projDir);
    boost::python::tuple projIntersectWith2(const PyGeLinearEnt3d& line, const AcGeVector3d& projDir, const AcGeTol& tol);
    boost::python::tuple tangent1(const AcGePoint3d& pnt) const;
    boost::python::tuple tangent2(const AcGePoint3d& pnt, const AcGeTol& tol) const;
    PyGePlane      getPlane();
    Adesk::Boolean isInside1(const AcGePoint3d& pnt) const;
    Adesk::Boolean isInside2(const AcGePoint3d& pnt, const AcGeTol& tol) const;
    AcGePoint3d    center() const;
    AcGeVector3d   normal() const;
    AcGeVector3d   refVec() const;
    double         radius() const;
    double         startAng() const;
    double         endAng() const;
    AcGePoint3d    startPoint() const;
    AcGePoint3d    endPoint() const;
    PyGeCircArc3d& setCenter(const AcGePoint3d&);
    PyGeCircArc3d& setAxes(const AcGeVector3d& normal, const AcGeVector3d& refVec);
    PyGeCircArc3d& setRadius(double);
    PyGeCircArc3d& setAngles(double startAngle, double endAngle);
    PyGeCircArc3d& set1(const AcGePoint3d& cent, const AcGeVector3d& nrm, double radius);
    PyGeCircArc3d& set2(const AcGePoint3d& cent, const AcGeVector3d& nrm, const AcGeVector3d& refVec, double radius, double startAngle, double endAngle);
    PyGeCircArc3d& set3(const AcGePoint3d& startPoint, const AcGePoint3d& pnt, const AcGePoint3d& endPoint);
    PyGeCircArc3d& set4(const PyGeCurve3d& curve1, const PyGeCurve3d& curve2, double radius);
    PyGeCircArc3d& set5(const PyGeCurve3d& curve1, const PyGeCurve3d& curve2, const PyGeCurve3d& curve3);
    static std::string className();
public:
    AcGeCircArc3d* impObj(const std::source_location& src = std::source_location::current()) const;
};
//-----------------------------------------------------------------------------------
//AcGeCompositeCurve3d
void makePyGeCompositeCurve3dWrapper();
class PyGeCompositeCurve3d : public PyGeCurve3d
{
public:
    PyGeCompositeCurve3d();
    PyGeCompositeCurve3d(AcGeEntity3d* pEnt);
    static std::string className();
public:
    AcGeCompositeCurve3d* impObj(const std::source_location& src = std::source_location::current()) const;
};
//-----------------------------------------------------------------------------------------
//AcGeCircArc3d wrapper
void makePyGeEllipArc3dWrapper();
class PyGeEllipArc3d : public PyGeCurve3d
{
public:
    PyGeEllipArc3d();
    PyGeEllipArc3d(const AcGeEllipArc3d& ell);
    PyGeEllipArc3d(AcGeEntity3d* pEnt);
    PyGeEllipArc3d(const PyGeCircArc3d& arc);
    PyGeEllipArc3d(const AcGePoint3d& cent, const AcGeVector3d& majorAxis, const AcGeVector3d& minorAxis, double majorRadius, double minorRadius);
    PyGeEllipArc3d(const AcGePoint3d& cent, const AcGeVector3d& majorAxis, const AcGeVector3d& minorAxis, double majorRadius, double minorRadius, double ang1, double ang2);
    boost::python::tuple closestPointToPlane1(const PyGePlanarEnt& plane);
    boost::python::tuple closestPointToPlane2(const PyGePlanarEnt& plane, const AcGeTol& tol);
    boost::python::tuple intersectWith1(const PyGeLinearEnt3d& line);
    boost::python::tuple intersectWith2(const PyGeLinearEnt3d& line, const AcGeTol& tol);
    boost::python::tuple intersectWith3(const PyGePlanarEnt& line);
    boost::python::tuple intersectWith4(const PyGePlanarEnt& line, const AcGeTol& tol);
    boost::python::tuple projIntersectWith1(const PyGeLinearEnt3d& line, const AcGeVector3d& projDir);
    boost::python::tuple projIntersectWith2(const PyGeLinearEnt3d& line, const AcGeVector3d& projDir, const AcGeTol& tol);
    PyGePlane      getPlane();
    Adesk::Boolean isCircular1() const;
    Adesk::Boolean isCircular2(const AcGeTol& tol) const;
    Adesk::Boolean isInside1(const AcGePoint3d& pnt) const;
    Adesk::Boolean isInside2(const AcGePoint3d& pnt, const AcGeTol& tol) const;
    AcGePoint3d    center() const;
    double         minorRadius() const;
    double         majorRadius() const;
    AcGeVector3d   minorAxis() const;
    AcGeVector3d   majorAxis() const;
    AcGeVector3d   normal() const;
    double         startAng() const;
    double         endAng() const;
    AcGePoint3d    startPoint() const;
    AcGePoint3d    endPoint() const;
    PyGeEllipArc3d& setCenter(const AcGePoint3d& cent);
    PyGeEllipArc3d& setMinorRadius(double rad);
    PyGeEllipArc3d& setMajorRadius(double rad);
    PyGeEllipArc3d& setAxes(const AcGeVector3d& majorAxis, const AcGeVector3d& minorAxis);
    PyGeEllipArc3d& setAngles(double startAngle, double endAngle);
    PyGeEllipArc3d& set1(const AcGePoint3d& cent, const AcGeVector3d& majorAxis, const AcGeVector3d& minorAxis, double majorRadius, double minorRadius);
    PyGeEllipArc3d& set2(const AcGePoint3d& cent, const AcGeVector3d& majorAxis, const AcGeVector3d& minorAxis, double majorRadius, double minorRadius, double startAngle, double endAngle);
    PyGeEllipArc3d& set3(const PyGeCircArc3d&);
    static std::string className();
public:
    AcGeEllipArc3d* impObj(const std::source_location& src = std::source_location::current()) const;
};
//-----------------------------------------------------------------------------------------
//PyGeExternalCurve3d wrapper
void makePyGeExternalCurve3dWrapper();
class PyGeExternalCurve3d : public PyGeCurve3d
{
public:
    PyGeExternalCurve3d(AcGeEntity3d* pEnt);
    static std::string className();
public:
    AcGeExternalCurve3d* impObj(const std::source_location& src = std::source_location::current()) const;
};
//-----------------------------------------------------------------------------------------
//AcGeOffsetCurve3d wrapper
void makePyGeOffsetCurve3dWrapper();
class PyGeOffsetCurve3d : public PyGeCurve3d
{
public:
    PyGeOffsetCurve3d(const PyGeCurve3d& baseCurve, const AcGeVector3d& planeNormal, double offsetDistance);
    PyGeOffsetCurve3d(AcGeEntity3d* pEnt);
    static std::string className();
public:
    AcGeOffsetCurve3d* impObj(const std::source_location& src = std::source_location::current()) const;
};