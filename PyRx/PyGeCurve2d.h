#pragma once
#include "PyGeEntity2d.h"

class PyGeInterval;
class PyGePointOnCurve2d;
class PyGeBoundBlock2d;
//-----------------------------------------------------------------------------------------
//PyGeCurve2d wrapper
void makePyGeCurve2dWrapper();

class PyGeCurve2d : public PyGeEntity2d
{
public:
    PyGeCurve2d(AcGeEntity2d* pEnt);

    PyGeInterval getInterval() const;
    AcGePoint2d getStartPoint() const;
    AcGePoint2d getEndPoint() const;
    PyGeCurve2d& reverseParam();
    PyGeCurve2d& setInterval1();
    Adesk::Boolean setInterval2(const PyGeInterval& intrvl);

    double  distanceTo1(const AcGePoint2d& pnt) const;
    double  distanceTo2(const AcGePoint2d& pnt, const AcGeTol& tol) const;
    double  distanceTo3(const PyGeCurve2d&) const;
    double  distanceTo4(const PyGeCurve2d&, const AcGeTol& tol) const;

    AcGePoint2d closestPointTo1(const AcGePoint2d& pnt) const;
    AcGePoint2d closestPointTo2(const AcGePoint2d& pnt, const AcGeTol& tol) const;
    boost::python::tuple  closestPointTo3(const PyGeCurve2d& curve2d) const;
    boost::python::tuple  closestPointTo4(const PyGeCurve2d& curve2d, const AcGeTol& tol) const;

    PyGePointOnCurve2d getClosestPointTo1(const AcGePoint2d& pnt);
    PyGePointOnCurve2d getClosestPointTo2(const AcGePoint2d& pnt, const AcGeTol& tol);

    boost::python::tuple getClosestPointsTo1(const PyGeCurve2d& curve);
    boost::python::tuple getClosestPointsTo2(const PyGeCurve2d& curve, const AcGeTol& tol);

    PyGePointOnCurve2d getNormalPoint1(const AcGePoint2d& pnt);
    PyGePointOnCurve2d getNormalPoint2(const AcGePoint2d& pnt, const AcGeTol& tol);

    Adesk::Boolean isOn1(const AcGePoint2d& pnt) const;
    Adesk::Boolean isOn2(const AcGePoint2d& pnt, const AcGeTol& tol) const;

    Adesk::Boolean isOn3(const AcGePoint2d& pnt, double& param) const;
    Adesk::Boolean isOn4(const AcGePoint2d& pnt, double& param, const AcGeTol& tol) const;

    Adesk::Boolean isOn5(double param) const;
    Adesk::Boolean isOn6(double param, const AcGeTol& tol) const;

    double  paramOf1(const AcGePoint2d& pnt) const;
    double  paramOf2(const AcGePoint2d& pnt, const AcGeTol& tol) const;

    boost::python::list getTrimmedOffset1(double distance, AcGe::OffsetCrvExtType extensionType) const;
    boost::python::list getTrimmedOffset2(double distance, AcGe::OffsetCrvExtType extensionType, const AcGeTol& tol) const;

    Adesk::Boolean isClosed1() const;
    Adesk::Boolean isClosed2(const AcGeTol& tol) const;
    boost::python::tuple isPeriodic() const;
    boost::python::tuple isLinear1() const;
    boost::python::tuple isLinear2(const AcGeTol& tol) const;

    double length1(double fromParam, double toParam) const;
    double length2(double fromParam, double toParam, double tol) const;

    double  paramAtLength1(double datumParam, double length) const;
    double  paramAtLength2(double datumParam, double length, Adesk::Boolean posParamDir, double tol) const;

    double area1(double startParam, double endParam) const;
    double area2(double startParam, double endParam, const AcGeTol& tol) const;

    boost::python::tuple isDegenerate1() const;
    boost::python::tuple isDegenerate2(const AcGeTol& tol) const;

    boost::python::list explode1();
    boost::python::list explode2(const PyGeInterval& interval);

    PyGeBoundBlock2d  boundBlock1() const;
    PyGeBoundBlock2d  boundBlock2(const PyGeInterval& range) const;

    PyGeBoundBlock2d  orthoBoundBlock1() const;
    PyGeBoundBlock2d  orthoBoundBlock2(const PyGeInterval& range) const;

    bool hasStartPoint() const;
    bool hasEndPoint() const;

    AcGePoint2d evalPoint1(double param) const;
    boost::python::tuple evalPoint2(double param, int numDeriv) const;

    boost::python::list getSamplePoints1(int numSample) const;
    boost::python::list getSamplePoints2(double fromParam, double toParam, double approxEps) const;

    static std::string className();
public:
    AcGeCurve2d* impObj() const;
};


//-----------------------------------------------------------------------------------------
//AcGeCircArc2d wrapper
void makeAcGeCircArc2dWrapper();
class PyGeCircArc2d : public PyGeCurve2d
{
public:
    PyGeCircArc2d();
    PyGeCircArc2d(AcGeEntity2d* pEnt);
    static std::string className();
public:
    AcGeCircArc2d* impObj() const;
};

//-----------------------------------------------------------------------------------------
//AcGeCircArc2d wrapper
void makeAcGeEllipArc2Wrapper();
class PyGeEllipArc2d : public PyGeCurve2d
{
public:
    PyGeEllipArc2d();
    PyGeEllipArc2d(AcGeEntity2d* pEnt);
    static std::string className();
public:
    AcGeEllipArc2d* impObj() const;
};

//-----------------------------------------------------------------------------------------
//PyGeExternalCurve2d wrapper
void makeAcGeExternalCurve2dWrapper();
class PyGeExternalCurve2d : public PyGeCurve2d
{
public:
    PyGeExternalCurve2d(AcGeEntity2d* pEnt);
    static std::string className();
public:
    AcGeExternalCurve2d* impObj() const;
};


//-----------------------------------------------------------------------------------------
//AcGeOffsetCurve2d wrapper
void makeAcGeOffsetCurve2dWrapper();
class PyGeOffsetCurve2d : public PyGeCurve2d
{
public:
    PyGeOffsetCurve2d(const PyGeCurve2d& baseCurve, double offsetDistance);
    PyGeOffsetCurve2d(AcGeEntity2d* pEnt);
    static std::string className();
public:
    AcGeOffsetCurve2d* impObj() const;
};


//-----------------------------------------------------------------------------------------
//AcGeCompositeCurve2d wrapper
void makeAcGeCompositeCurve2dWrapper();
class PyGeCompositeCurve2d : public PyGeCurve2d
{
public:
    PyGeCompositeCurve2d();
    PyGeCompositeCurve2d(AcGeEntity2d* pEnt);
    static std::string className();
public:
    AcGeCompositeCurve2d* impObj() const;
};
