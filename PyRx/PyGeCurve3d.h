#pragma once
#include "PyGeEntity3d.h"

class PyGeInterval;
class PyGePointOnCurve3d;
//-----------------------------------------------------------------------------------
//PyGeCurve3d
void makPyGeCurve3dWrapper();
class PyGeCurve3d : public PyGeEntity3d
{
public:
    PyGeCurve3d(AcGeEntity3d* pEnt);
    PyGeInterval getInterval() const;
    AcGePoint3d getStartPoint() const;
    AcGePoint3d getEndPoint() const;
    PyGeCurve3d& reverseParam();
    PyGeCurve3d& setInterval1();
    bool setInterval2(const PyGeInterval& intrvl);

    double  distanceTo1(const AcGePoint3d& pnt) const;
    double  distanceTo2(const AcGePoint3d& pnt, const AcGeTol& tol) const;
    double  distanceTo3(const PyGeCurve3d&) const;
    double  distanceTo4(const PyGeCurve3d&, const AcGeTol& tol) const;

    AcGePoint3d closestPointTo1(const AcGePoint3d& pnt) const;
    AcGePoint3d closestPointTo2(const AcGePoint3d& pnt, const AcGeTol& tol) const;
    boost::python::tuple  closestPointTo3(const PyGeCurve3d& curve2d) const;
    boost::python::tuple  closestPointTo4(const PyGeCurve3d& curve2d, const AcGeTol& tol) const;

    PyGePointOnCurve3d getClosestPointTo1(const AcGePoint3d& pnt);
    PyGePointOnCurve3d getClosestPointTo2(const AcGePoint3d& pnt, const AcGeTol& tol);

    boost::python::tuple getClosestPointsTo1(const PyGeCurve3d& curve);
    boost::python::tuple getClosestPointsTo2(const PyGeCurve3d& curve, const AcGeTol& tol);

    AcGePoint3d projClosestPointTo1(const AcGePoint3d& pnt, const AcGeVector3d& projectDirection) const;
    AcGePoint3d projClosestPointTo2(const AcGePoint3d& pnt, const AcGeVector3d& projectDirection, const AcGeTol& tol) const;

    boost::python::tuple projClosestPointsTo1(const AcGeCurve3d& curve3d, const AcGeVector3d& projectDirection) const;
    boost::python::tuple projClosestPointsTo1(const AcGeCurve3d& curve3d, const AcGeVector3d& projectDirection, const AcGeTol& tol) const;

    PyGePointOnCurve3d getProjClosestPointTo1(const AcGePoint3d& pnt, const AcGeVector3d& projectDirection) const;
    PyGePointOnCurve3d getProjClosestPointTo2(const AcGePoint3d& pnt, const AcGeVector3d& projectDirection, const AcGeTol& tol) const;

    boost::python::tuple getProjClosestPointsTo1(const PyGeCurve3d& curve3d, const AcGeVector3d& projectDirection) const;
    boost::python::tuple getProjClosestPointsTo2(const PyGeCurve3d& curve3d, const AcGeVector3d& projectDirection, const AcGeTol& tol) const;

    PyGePointOnCurve3d getNormalPoint1(const AcGePoint3d& pnt);
    PyGePointOnCurve3d getNormalPoint2(const AcGePoint3d& pnt, const AcGeTol& tol);



    static std::string className();
public:
    AcGeCurve3d* impObj() const;
};

//-----------------------------------------------------------------------------------
//AcGeCircArc3d
void makAcGeCircArc3dWrapper();
class PyGeCircArc3d : public PyGeCurve3d
{
public:
    PyGeCircArc3d();
    PyGeCircArc3d(AcGeEntity3d* pEnt);
    static std::string className();
public:
    AcGeCircArc3d* impObj() const;
};

//-----------------------------------------------------------------------------------
//AcGeCompositeCurve3d
void makAcGeCompositeCurve3dWrapper();
class PyGeCompositeCurve3d : public PyGeCurve3d
{
public:
    PyGeCompositeCurve3d();
    PyGeCompositeCurve3d(AcGeEntity3d* pEnt);
    static std::string className();
public:
    AcGeCompositeCurve3d* impObj() const;
};


//-----------------------------------------------------------------------------------------
//AcGeCircArc3d wrapper
void makeAcGeEllipArc3dWrapper();
class PyGeEllipArc3d : public PyGeCurve3d
{
public:
    PyGeEllipArc3d();
    PyGeEllipArc3d(AcGeEntity3d* pEnt);
    static std::string className();
public:
    AcGeEllipArc3d* impObj() const;
};

//-----------------------------------------------------------------------------------------
//PyGeExternalCurve3d wrapper
void makeAcGeExternalCurve3dWrapper();
class PyGeExternalCurve3d : public PyGeCurve3d
{
public:
    PyGeExternalCurve3d(AcGeEntity3d* pEnt);
    static std::string className();
public:
    AcGeExternalCurve3d* impObj() const;
};

//-----------------------------------------------------------------------------------------
//AcGeOffsetCurve3d wrapper
void makeAcGeOffsetCurve3dWrapper();
class PyGeOffsetCurve3d : public PyGeCurve3d
{
public:
    PyGeOffsetCurve3d(const PyGeCurve3d& baseCurve, const AcGeVector3d& planeNormal,double offsetDistance);
    PyGeOffsetCurve3d(AcGeEntity3d* pEnt);
    static std::string className();
public:
    AcGeOffsetCurve3d* impObj() const;
};