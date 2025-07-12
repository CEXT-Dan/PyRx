#pragma once
#include "PyGeEntity2d.h"

#pragma pack (push, 8)
class PyGeInterval;
class PyGePointOnCurve2d;
class PyGeBoundBlock2d;
class PyGeLinearEnt2d;
//-----------------------------------------------------------------------------------------
//PyGeCurve2d wrapper
void makePyGeCurve2dWrapper();
class PyGeCurve2d : public PyGeEntity2d
{
public:
    PyGeCurve2d(AcGeEntity2d* pEnt);
    PyGeCurve2d(const AcGeEntity2d* pEnt);
    virtual ~PyGeCurve2d() override = default;
    PyGeInterval            getInterval() const;
    AcGePoint2d             getStartPoint() const;
    AcGePoint2d             getEndPoint() const;
    void                    reverseParam() const;
    void                    setInterval1() const;
    Adesk::Boolean          setInterval2(const PyGeInterval& intrvl) const;
    double                  distanceTo1(const AcGePoint2d& pnt) const;
    double                  distanceTo2(const AcGePoint2d& pnt, const AcGeTol& tol) const;
    double                  distanceTo3(const PyGeCurve2d&) const;
    double                  distanceTo4(const PyGeCurve2d&, const AcGeTol& tol) const;
    AcGePoint2d             closestPointTo1(const AcGePoint2d& pnt) const;
    AcGePoint2d             closestPointTo2(const AcGePoint2d& pnt, const AcGeTol& tol) const;
    boost::python::tuple    closestPointTo3(const PyGeCurve2d& curve2d) const;
    boost::python::tuple    closestPointTo4(const PyGeCurve2d& curve2d, const AcGeTol& tol) const;
    PyGePointOnCurve2d      getClosestPointTo1(const AcGePoint2d& pnt) const;
    PyGePointOnCurve2d      getClosestPointTo2(const AcGePoint2d& pnt, const AcGeTol& tol) const;
    boost::python::tuple    getClosestPointsTo1(const PyGeCurve2d& curve) const;
    boost::python::tuple    getClosestPointsTo2(const PyGeCurve2d& curve, const AcGeTol& tol) const;
    PyGePointOnCurve2d      getNormalPoint1(const AcGePoint2d& pnt) const;
    PyGePointOnCurve2d      getNormalPoint2(const AcGePoint2d& pnt, const AcGeTol& tol) const;
    boost::python::tuple    isOn1(const AcGePoint2d& pnt) const;
    boost::python::tuple    isOn2(const AcGePoint2d& pnt, const AcGeTol& tol) const;
    boost::python::tuple    isOn3(double param) const;
    boost::python::tuple    isOn4(double param, const AcGeTol& tol) const;
    double                  paramOf1(const AcGePoint2d& pnt) const;
    double                  paramOf2(const AcGePoint2d& pnt, const AcGeTol& tol) const;
    boost::python::list     getTrimmedOffset1(double distance, AcGe::OffsetCrvExtType extensionType) const;
    boost::python::list     getTrimmedOffset2(double distance, AcGe::OffsetCrvExtType extensionType, const AcGeTol& tol) const;
    Adesk::Boolean          isClosed1() const;
    Adesk::Boolean          isClosed2(const AcGeTol& tol) const;
    boost::python::tuple    isPeriodic() const;
    boost::python::tuple    isLinear1() const;
    boost::python::tuple    isLinear2(const AcGeTol& tol) const;
    double                  length1(double fromParam, double toParam) const;
    double                  length2(double fromParam, double toParam, double tol) const;
    double                  paramAtLength1(double datumParam, double length) const;
    double                  paramAtLength2(double datumParam, double length, Adesk::Boolean posParamDir, double tol) const;
    double                  area1(double startParam, double endParam) const;
    double                  area2(double startParam, double endParam, const AcGeTol& tol) const;
    boost::python::tuple    isDegenerate1() const;
    boost::python::tuple    isDegenerate2(const AcGeTol& tol) const;
    boost::python::list     explode1() const;
    boost::python::list     explode2(const PyGeInterval& interval) const;
    PyGeBoundBlock2d        boundBlock1() const;
    PyGeBoundBlock2d        boundBlock2(const PyGeInterval& range) const;
    PyGeBoundBlock2d        orthoBoundBlock1() const;
    PyGeBoundBlock2d        orthoBoundBlock2(const PyGeInterval& range) const;
    bool                    hasStartPoint() const;
    bool                    hasEndPoint() const;
    AcGePoint2d             evalPoint1(double param) const;
    boost::python::tuple    evalPoint2(double param, int numDeriv) const;
    boost::python::list     getSamplePoints1(int numSample) const;
    boost::python::tuple    getSamplePoints2(double fromParam, double toParam, double approxEps) const;
    boost::python::tuple    getSplitCurves(double param) const;
    static PyGeCurve2d      cast(const PyGeEntity2d& src);
    static PyGeCurve2d      copycast(const PyGeEntity2d& src);
    static std::string      className();
public:
    AcGeCurve2d* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//AcGeCircArc2d wrapper
void makePyGeCircArc2dWrapper();
class PyGeCircArc2d : public PyGeCurve2d
{
public:
    PyGeCircArc2d();
    PyGeCircArc2d(const AcGeCircArc2d& src);
    PyGeCircArc2d(const AcGePoint2d& cent, double radius);
    PyGeCircArc2d(const AcGePoint2d& cent, double radius, double startAngle, double endAngle);
    PyGeCircArc2d(const AcGePoint2d& cent, double radius, double startAngle, double endAngle, const AcGeVector2d& refVec, Adesk::Boolean isClockWise);
    PyGeCircArc2d(const AcGePoint2d& startPoint, const AcGePoint2d& point, const AcGePoint2d& endPoint);
    PyGeCircArc2d(const AcGePoint2d& startPoint, const AcGePoint2d& endPoint, double bulge, bool bulgeFlag);
    PyGeCircArc2d(AcGeEntity2d* pEnt);
    boost::python::tuple    intersectWith1(const PyGeLinearEnt2d& line) const;
    boost::python::tuple    intersectWith2(const PyGeLinearEnt2d& line, const AcGeTol& tol) const;
    boost::python::tuple    intersectWith3(const PyGeCircArc2d& arc) const;
    boost::python::tuple    intersectWith4(const PyGeCircArc2d& arc, const AcGeTol& tol) const;
    boost::python::tuple    tangent1(const AcGePoint2d& pnt) const;
    boost::python::tuple    tangent2(const AcGePoint2d& pnt, const AcGeTol& tol) const;
    Adesk::Boolean          isInside1(const AcGePoint2d& pnt) const;
    Adesk::Boolean          isInside2(const AcGePoint2d& pnt, const AcGeTol& tol) const;
    AcGePoint2d             center() const;
    double                  radius() const;
    double                  startAng() const;
    double                  endAng() const;
    Adesk::Boolean          isClockWise() const;
    AcGeVector2d            refVec() const;
    AcGePoint2d             startPoint() const;
    AcGePoint2d             endPoint() const;
    void                    setCenter(const AcGePoint2d& cent) const;
    void                    setRadius(double radius) const;
    void                    setAngles(double startAng, double endAng) const;
    void                    setToComplement() const;
    void                    setRefVec(const AcGeVector2d& vec) const;
    void                    set1(const AcGePoint2d& cent, double radius) const;
    void                    set2(const AcGePoint2d& cent, double radius, double ang1, double ang2, const AcGeVector2d& refVec, Adesk::Boolean isClockWise) const;
    void                    set3(const AcGePoint2d& startPoint, const AcGePoint2d& pnt, const AcGePoint2d& endPoint) const;
    void                    set4(const AcGePoint2d& startPoint, const AcGePoint2d& endPoint, double bulge, Adesk::Boolean bulgeFlag) const;
    void                    set5(const PyGeCurve2d& curve1, const PyGeCurve2d& curve2, double radius) const;
    void                    set6(const PyGeCurve2d& curve1, const PyGeCurve2d& curve2, const PyGeCurve2d& curve3) const;
    static PyGeCircArc2d    cast(const PyGeEntity2d& src);
    static PyGeCircArc2d    copycast(const PyGeEntity2d& src);
    static std::string className();
public:
    AcGeCircArc2d* impObj(const std::source_location& src = std::source_location::current()) const;
};
//-----------------------------------------------------------------------------------------
//AcGeCircArc2d wrapper
void makePyGeEllipArc2Wrapper();
class PyGeEllipArc2d : public PyGeCurve2d
{
#if !defined(_BRXTARGET260)

public:
    PyGeEllipArc2d();
    PyGeEllipArc2d(const AcGeEllipArc2d& ell);
    PyGeEllipArc2d(const PyGeCircArc2d& arc);
    PyGeEllipArc2d(const AcGePoint2d& cent, const AcGeVector2d& majorAxis, const AcGeVector2d& minorAxis, double majorRadius, double minorRadius);
    PyGeEllipArc2d(const AcGePoint2d& cent, const AcGeVector2d& majorAxis, const AcGeVector2d& minorAxis, double majorRadius, double minorRadius, double startAngle, double endAngle);
    PyGeEllipArc2d(AcGeEntity2d* pEnt);
    boost::python::tuple      intersectWith1(const PyGeLinearEnt2d& line) const;
    boost::python::tuple    intersectWith2(const PyGeLinearEnt2d& line, const AcGeTol& tol) const;
    Adesk::Boolean          isCircular1() const;
    Adesk::Boolean          isCircular2(const AcGeTol& tol) const;
    Adesk::Boolean          isInside1(const AcGePoint2d& pnt) const;
    Adesk::Boolean          isInside2(const AcGePoint2d& pnt, const AcGeTol& tol) const;
    AcGePoint2d             center() const;
    double                  minorRadius() const;
    double                  majorRadius() const;
    AcGeVector2d            minorAxis() const;
    AcGeVector2d            majorAxis() const;
    double                  startAng() const;
    double                  endAng() const;
    AcGePoint2d             startPoint() const;
    AcGePoint2d             endPoint() const;
    Adesk::Boolean          isClockWise() const;
    void                    setCenter(const AcGePoint2d& cent) const;
    void                    setMinorRadius(double rad) const;
    void                    setMajorRadius(double rad) const;
    void                    setAxes(const AcGeVector2d& majorAxis, const AcGeVector2d& minorAxis) const;
    void                    setAngles(double startAngle, double endAngle) const;
    void                    set1(const AcGePoint2d& cent, const AcGeVector2d& majorAxis, const AcGeVector2d& minorAxis, double majorRadius, double minorRadius) const;
    void                    set2(const AcGePoint2d& cent, const AcGeVector2d& majorAxis, const AcGeVector2d& minorAxis, double majorRadius, double minorRadius, double startAngle, double endAngle) const;
    void                    set3(const PyGeCircArc2d& arc) const;
    static PyGeEllipArc2d   cast(const PyGeEntity2d& src);
    static PyGeEllipArc2d   copycast(const PyGeEntity2d& src);
    static std::string      className();
public:
    AcGeEllipArc2d* impObj(const std::source_location& src = std::source_location::current()) const;
#endif
};
//-----------------------------------------------------------------------------------------
//PyGeExternalCurve2d wrapper
void makePyGeExternalCurve2dWrapper();
class PyGeExternalCurve2d : public PyGeCurve2d
{
#if !defined(_BRXTARGET260)
public:
    PyGeExternalCurve2d(AcGeEntity2d* pEnt);
    static PyGeExternalCurve2d cast(const PyGeEntity2d& src);
    static PyGeExternalCurve2d copycast(const PyGeEntity2d& src);
    static std::string className();
public:
    AcGeExternalCurve2d* impObj(const std::source_location& src = std::source_location::current()) const;
#endif
};
//-----------------------------------------------------------------------------------------
//AcGeOffsetCurve2d wrapper
void makePyGeOffsetCurve2dWrapper();
class PyGeOffsetCurve2d : public PyGeCurve2d
{
#if !defined(_BRXTARGET260)
public:
    PyGeOffsetCurve2d(const PyGeCurve2d& baseCurve, double offsetDistance);
    PyGeOffsetCurve2d(AcGeEntity2d* pEnt);
    static PyGeOffsetCurve2d cast(const PyGeEntity2d& src);
    static PyGeOffsetCurve2d copycast(const PyGeEntity2d& src);
    static std::string className();
public:
    AcGeOffsetCurve2d* impObj(const std::source_location& src = std::source_location::current()) const;
#endif
};
//-----------------------------------------------------------------------------------------
//AcGeCompositeCurve2d wrapper
void makePyGeCompositeCurve2dWrapper();
class PyGeCompositeCurve2d : public PyGeCurve2d
{
public:
    PyGeCompositeCurve2d();
    PyGeCompositeCurve2d(const boost::python::list& curveList);
    PyGeCompositeCurve2d(const boost::python::list& curveList, const boost::python::list& isOwnerOfCurves);
    PyGeCompositeCurve2d(const AcGeCompositeCurve2d& pEnt);
    PyGeCompositeCurve2d(AcGeEntity2d* pEnt);

    boost::python::list getCurveList() const;
    void                setCurveList1(const boost::python::list& curveList) const;
    void                setCurveList2(const boost::python::list& curveList, const boost::python::list& isOwnerOfCurves) const;
    boost::python::tuple globalToLocalParam(double param) const;
    double				 localToGlobalParam(double param, int segNum) const;

    static PyGeCompositeCurve2d cast(const PyGeEntity2d& src);
    static PyGeCompositeCurve2d copycast(const PyGeEntity2d& src);
    static std::string className();
public:
    AcGeCompositeCurve2d* impObj(const std::source_location& src = std::source_location::current()) const;
};

#pragma pack (pop)