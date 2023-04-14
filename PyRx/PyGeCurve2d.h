#pragma once
#include "PyGeEntity2d.h"

class PyGeInterval;
class PyGePointOnCurve2d;
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
    AcGePoint2d closestPointTo3(const PyGeCurve2d& curve2d, AcGePoint2d& pntOnOtherCrv) const;
    AcGePoint2d closestPointTo4(const PyGeCurve2d& curve2d, AcGePoint2d& pntOnOtherCrv, const AcGeTol& tol) const;

    PyGePointOnCurve2d getClosestPointTo1(const AcGePoint2d& pnt);
    PyGePointOnCurve2d getClosestPointTo2(const AcGePoint2d& pnt, const AcGeTol& tol);

    boost::python::tuple getClosestPointsTo1(const PyGeCurve2d& curve);
    boost::python::tuple getClosestPointsTo2(const PyGeCurve2d& curve, const AcGeTol& tol);

    PyGePointOnCurve2d getNormalPoint1(const AcGePoint2d& pnt);
    PyGePointOnCurve2d getNormalPoint2(const AcGePoint2d& pnt, const AcGeTol& tol);

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
