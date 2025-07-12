#pragma once
#include "PyGeEntity3d.h"

#pragma pack (push, 8)
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
    PyGeCurve3d(const AcGeEntity3d* pEnt);
    virtual ~PyGeCurve3d() override = default;
    PyGeInterval            getInterval() const;
    AcGePoint3d             getStartPoint() const;
    AcGePoint3d             getEndPoint() const;
    void                    reverseParam() const;
    void                    setInterval1() const;
    bool                    setInterval2(const PyGeInterval& intrvl) const;
    double                  distanceTo1(const AcGePoint3d& pnt) const;
    double                  distanceTo2(const AcGePoint3d& pnt, const AcGeTol& tol) const;
    double                  distanceTo3(const PyGeCurve3d&) const;
    double                  distanceTo4(const PyGeCurve3d&, const AcGeTol& tol) const;
    AcGePoint3d             closestPointTo1(const AcGePoint3d& pnt) const;
    AcGePoint3d             closestPointTo2(const AcGePoint3d& pnt, const AcGeTol& tol) const;
    boost::python::tuple    closestPointTo3(const PyGeCurve3d& curve3d) const;
    boost::python::tuple    closestPointTo4(const PyGeCurve3d& curve3d, const AcGeTol& tol) const;
    PyGePointOnCurve3d      getClosestPointTo1(const AcGePoint3d& pnt) const;
    PyGePointOnCurve3d      getClosestPointTo2(const AcGePoint3d& pnt, const AcGeTol& tol) const;
    boost::python::tuple    getClosestPointsTo1(const PyGeCurve3d& curve) const;
    boost::python::tuple    getClosestPointsTo2(const PyGeCurve3d& curve, const AcGeTol& tol) const;
    AcGePoint3d             projClosestPointTo1(const AcGePoint3d& pnt, const AcGeVector3d& projectDirection) const;
    AcGePoint3d             projClosestPointTo2(const AcGePoint3d& pnt, const AcGeVector3d& projectDirection, const AcGeTol& tol) const;
    boost::python::tuple    projClosestPointsTo1(const PyGeCurve3d& curve3d, const AcGeVector3d& projectDirection) const;
    boost::python::tuple    projClosestPointsTo2(const PyGeCurve3d& curve3d, const AcGeVector3d& projectDirection, const AcGeTol& tol) const;
    PyGePointOnCurve3d      getProjClosestPointTo1(const AcGePoint3d& pnt, const AcGeVector3d& projectDirection) const;
    PyGePointOnCurve3d      getProjClosestPointTo2(const AcGePoint3d& pnt, const AcGeVector3d& projectDirection, const AcGeTol& tol) const;
    boost::python::tuple    getProjClosestPointsTo1(const PyGeCurve3d& curve3d, const AcGeVector3d& projectDirection) const;
    boost::python::tuple    getProjClosestPointsTo2(const PyGeCurve3d& curve3d, const AcGeVector3d& projectDirection, const AcGeTol& tol) const;
    PyGePointOnCurve3d      getNormalPoint1(const AcGePoint3d& pnt) const;
    PyGePointOnCurve3d      getNormalPoint2(const AcGePoint3d& pnt, const AcGeTol& tol) const;
    PyGeBoundBlock3d        boundBlock1() const;
    PyGeBoundBlock3d        boundBlock2(const PyGeInterval& range) const;
    PyGeBoundBlock3d        orthoBoundBlock1() const;
    PyGeBoundBlock3d        orthoBoundBlock2(const PyGeInterval& range) const;
    PyGeEntity3d            project1(const PyGePlane& projectionPlane, const AcGeVector3d& projectDirection) const;
    PyGeEntity3d            project2(const PyGePlane& projectionPlane, const AcGeVector3d& projectDirection, const AcGeTol& tol) const;
    PyGeEntity3d            orthoProject1(const PyGePlane& projectionPlane) const;
    PyGeEntity3d            orthoProject2(const PyGePlane& projectionPlane, const AcGeTol& tol) const;
    boost::python::tuple    isOn1(const AcGePoint3d& pnt) const;
    boost::python::tuple    isOn2(const AcGePoint3d& pnt, const AcGeTol& tol) const;
    boost::python::tuple    isOn3(double param) const;
    boost::python::tuple    isOn4(double param, const AcGeTol& tol) const;
    double                  paramOf1(const AcGePoint3d& pnt) const;
    double                  paramOf2(const AcGePoint3d& pnt, const AcGeTol& tol) const;
    boost::python::list     getTrimmedOffset1(double distance, const AcGeVector3d& planeNormal, AcGe::OffsetCrvExtType extensionType) const;
    boost::python::list     getTrimmedOffset2(double distance, const AcGeVector3d& planeNormal, AcGe::OffsetCrvExtType extensionType, const AcGeTol& tol) const;
    Adesk::Boolean          isClosed1() const;
    Adesk::Boolean          isClosed2(const AcGeTol& tol) const;
    boost::python::tuple    isPlanar1() const;
    boost::python::tuple    isPlanar2(const AcGeTol& tol) const;
    boost::python::tuple    isLinear1() const;
    boost::python::tuple    isLinear2(const AcGeTol& tol) const;
    boost::python::tuple    isCoplanarWith1(const PyGeCurve3d& curve3d) const;
    boost::python::tuple    isCoplanarWith2(const PyGeCurve3d& curve3d, const AcGeTol& tol) const;
    boost::python::tuple    isPeriodic() const;
    double                  length1(double fromParam, double toParam) const;
    double                  length2(double fromParam, double toParam, double tol) const;
    double                  paramAtLength1(double datumParam, double length) const;
    double                  paramAtLength2(double datumParam, double length, Adesk::Boolean posParamDir, double tol) const;
    double                  area1(double startParam, double endParam) const;
    double                  area2(double startParam, double endParam, const AcGeTol& tol) const;
    boost::python::tuple    isDegenerate1() const;
    boost::python::tuple    isDegenerate2(const AcGeTol& tol) const;
    boost::python::tuple    getSplitCurves(double param) const;
    boost::python::list     explode1() const;
    boost::python::list     explode2(const PyGeInterval& interval) const;
    bool                    hasStartPoint() const;
    bool                    hasEndPoint() const;
    AcGePoint3d             evalPoint1(double param) const;
    boost::python::tuple    evalPoint2(double param, int numDeriv) const;
    boost::python::tuple    getSamplePoints1(int numSample) const;
    boost::python::tuple    getSamplePoints2(double fromParam, double toParam, double approxEps) const;
    static PyGeCurve3d      cast(const PyGeEntity3d& src);
    static PyGeCurve3d      copycast(const PyGeEntity3d& src);
    static std::string      className();
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
    virtual ~PyGeCircArc3d() override = default;
    boost::python::tuple    closestPointToPlane1(const PyGePlanarEnt& plane) const;
    boost::python::tuple    closestPointToPlane2(const PyGePlanarEnt& plane, const AcGeTol& tol) const;
    boost::python::tuple    intersectWith1(const PyGeLinearEnt3d& line) const;
    boost::python::tuple    intersectWith2(const PyGeLinearEnt3d& line, const AcGeTol& tol) const;
    boost::python::tuple    intersectWith3(const PyGeCircArc3d& line) const;
    boost::python::tuple    intersectWith4(const PyGeCircArc3d& line, const AcGeTol& tol) const;
    boost::python::tuple    intersectWith5(const PyGePlanarEnt& line) const;
    boost::python::tuple    intersectWith6(const PyGePlanarEnt& line, const AcGeTol& tol) const;
    boost::python::tuple    projIntersectWith1(const PyGeLinearEnt3d& line, const AcGeVector3d& projDir) const;
    boost::python::tuple    projIntersectWith2(const PyGeLinearEnt3d& line, const AcGeVector3d& projDir, const AcGeTol& tol) const;
    boost::python::tuple    tangent1(const AcGePoint3d& pnt) const;
    boost::python::tuple    tangent2(const AcGePoint3d& pnt, const AcGeTol& tol) const;
    PyGePlane               getPlane() const;
    Adesk::Boolean          isInside1(const AcGePoint3d& pnt) const;
    Adesk::Boolean          isInside2(const AcGePoint3d& pnt, const AcGeTol& tol) const;
    AcGePoint3d             center() const;
    AcGeVector3d            normal() const;
    AcGeVector3d            refVec() const;
    double                  radius() const;
    double                  startAng() const;
    double                  endAng() const;
    AcGePoint3d             startPoint() const;
    AcGePoint3d             endPoint() const;
    void                    setCenter(const AcGePoint3d&) const;
    void                    setAxes(const AcGeVector3d& normal, const AcGeVector3d& refVec) const;
    void                    setRadius(double) const;
    void                    setAngles(double startAngle, double endAngle) const;
    void                    set1(const AcGePoint3d& cent, const AcGeVector3d& nrm, double radius) const;
    void                    set2(const AcGePoint3d& cent, const AcGeVector3d& nrm, const AcGeVector3d& refVec, double radius, double startAngle, double endAngle) const;
    void                    set3(const AcGePoint3d& startPoint, const AcGePoint3d& pnt, const AcGePoint3d& endPoint) const;
    void                    set4(const PyGeCurve3d& curve1, const PyGeCurve3d& curve2, double radius) const;
    void                    set5(const PyGeCurve3d& curve1, const PyGeCurve3d& curve2, const PyGeCurve3d& curve3) const;
    static PyGeCircArc3d    cast(const PyGeEntity3d& src);
    static PyGeCircArc3d    copycast(const PyGeEntity3d& src);
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
    PyGeCompositeCurve3d(const boost::python::list& curveList);
    PyGeCompositeCurve3d(const boost::python::list& curveList, const boost::python::list& isOwnerOfCurves);
    PyGeCompositeCurve3d(AcGeEntity3d* pEnt);
    virtual ~PyGeCompositeCurve3d() override = default;
    boost::python::list getCurveList() const;
    void                setCurveList1(const boost::python::list& curveList) const;
    void                setCurveList2(const boost::python::list& curveList, const boost::python::list& isOwnerOfCurves) const;
    boost::python::tuple globalToLocalParam(double param) const;
    double				 localToGlobalParam(double param, int segNum) const;

    static boost::python::list  createFromLineSeg3dArray(const boost::python::list& curveList);
    static PyGeCompositeCurve3d cast(const PyGeEntity3d& src);
    static PyGeCompositeCurve3d copycast(const PyGeEntity3d& src);
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
    PyGeEllipArc3d(AcGeEntity3d* pEnt);
#if !defined(_BRXTARGET250)
    PyGeEllipArc3d(const AcGeEllipArc3d& ell);
    PyGeEllipArc3d(const PyGeCircArc3d& arc);
#endif
    PyGeEllipArc3d(const AcGePoint3d& cent, const AcGeVector3d& majorAxis, const AcGeVector3d& minorAxis, double majorRadius, double minorRadius);
    PyGeEllipArc3d(const AcGePoint3d& cent, const AcGeVector3d& majorAxis, const AcGeVector3d& minorAxis, double majorRadius, double minorRadius, double ang1, double ang2);
    virtual ~PyGeEllipArc3d() override = default;
    boost::python::tuple    closestPointToPlane1(const PyGePlanarEnt& plane) const;
    boost::python::tuple    closestPointToPlane2(const PyGePlanarEnt& plane, const AcGeTol& tol) const;
    boost::python::tuple    intersectWith1(const PyGeLinearEnt3d& line) const;
    boost::python::tuple    intersectWith2(const PyGeLinearEnt3d& line, const AcGeTol& tol) const;
    boost::python::tuple    intersectWith3(const PyGePlanarEnt& line) const;
    boost::python::tuple    intersectWith4(const PyGePlanarEnt& line, const AcGeTol& tol) const;
    boost::python::tuple    projIntersectWith1(const PyGeLinearEnt3d& line, const AcGeVector3d& projDir) const;
    boost::python::tuple    projIntersectWith2(const PyGeLinearEnt3d& line, const AcGeVector3d& projDir, const AcGeTol& tol) const;
    PyGePlane               getPlane() const;
    Adesk::Boolean          isCircular1() const;
    Adesk::Boolean          isCircular2(const AcGeTol& tol) const;
    Adesk::Boolean          isInside1(const AcGePoint3d& pnt) const;
    Adesk::Boolean          isInside2(const AcGePoint3d& pnt, const AcGeTol& tol) const;
    AcGePoint3d             center() const;
    double                  minorRadius() const;
    double                  majorRadius() const;
    AcGeVector3d            minorAxis() const;
    AcGeVector3d            majorAxis() const;
    AcGeVector3d            normal() const;
    double                  startAng() const;
    double                  endAng() const;
    AcGePoint3d             startPoint() const;
    AcGePoint3d             endPoint() const;
    void                    setCenter(const AcGePoint3d& cent) const;
    void                    setMinorRadius(double rad) const;
    void                    setMajorRadius(double rad) const;
    void                    setAxes(const AcGeVector3d& majorAxis, const AcGeVector3d& minorAxis) const;
    void                    setAngles(double startAngle, double endAngle) const;
    void                    set1(const AcGePoint3d& cent, const AcGeVector3d& majorAxis, const AcGeVector3d& minorAxis, double majorRadius, double minorRadius) const;
    void                    set2(const AcGePoint3d& cent, const AcGeVector3d& majorAxis, const AcGeVector3d& minorAxis, double majorRadius, double minorRadius, double startAngle, double endAngle) const;
    void                    set3(const PyGeCircArc3d&) const;
    static PyGeEllipArc3d   cast(const PyGeEntity3d& src);
    static PyGeEllipArc3d   copycast(const PyGeEntity3d& src);
    static std::string      className();
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
    virtual ~PyGeExternalCurve3d() override = default;

    Adesk::Boolean isLine() const;
    Adesk::Boolean isRay() const;
    Adesk::Boolean isLineSeg() const;
    Adesk::Boolean isCircArc() const;
    Adesk::Boolean isEllipArc() const;
    Adesk::Boolean isNurbCurve() const;
    Adesk::Boolean isDefined() const;
    Adesk::Boolean isOwnerOfCurve() const;
    void           setToOwnCurve() const;
    PyGeCurve3d    getNativeCurve() const;
    AcGe::ExternalEntityKind externalCurveKind() const;

    static PyGeExternalCurve3d cast(const PyGeEntity3d& src);
    static PyGeExternalCurve3d copycast(const PyGeEntity3d& src);
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
    virtual ~PyGeOffsetCurve3d() override = default;

    PyGeCurve3d             curve() const;
    AcGeVector3d            normal() const;
    double                  offsetDistance() const;
    Adesk::Boolean		    paramDirection() const;
    AcGeMatrix3d		    transformation() const;

    void                    setCurve(const PyGeCurve3d& baseCurve) const;
    void                    setNormal(const AcGeVector3d& planeNormal) const;
    void                    setOffsetDistance(double offsetDistance) const;

    static PyGeOffsetCurve3d cast(const PyGeEntity3d& src);
    static PyGeOffsetCurve3d copycast(const PyGeEntity3d& src);
    static std::string className();
public:
    AcGeOffsetCurve3d* impObj(const std::source_location& src = std::source_location::current()) const;
};

#pragma pack (pop)