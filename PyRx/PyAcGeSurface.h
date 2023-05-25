#pragma once
#include "PyGeEntity3d.h"
class PyGeInterval;
class PyGePointOnSurface;
//-----------------------------------------------------------------------------------------
//AcGeSurface wrapper
void makeAcGeSurfaceWrapper();
class PyAcGeSurface : public PyGeEntity3d
{
protected:
    PyAcGeSurface() = default;
public:
    PyAcGeSurface(AcGeSurface* pEnt);
    PyAcGeSurface(AcGeEntity3d* pEnt);
    ~PyAcGeSurface() = default;
    AcGePoint2d     paramOf(const AcGePoint3d& pnt) const;
    AcGePoint2d     paramOfTol(const AcGePoint3d& pnt, const AcGeTol& tol) const;
    Adesk::Boolean  isOn1(const AcGePoint3d& pnt) const;
    Adesk::Boolean  isOn2(const AcGePoint3d& pnt, const AcGeTol& tol) const;
    Adesk::Boolean  isOn3(const AcGePoint3d& pnt, AcGePoint2d& paramPoint) const;
    Adesk::Boolean  isOn4(const AcGePoint3d& pnt, AcGePoint2d& paramPoint, const AcGeTol& tol) const;
    AcGePoint3d     closestPointTo1(const AcGePoint3d& pnt) const;
    AcGePoint3d     closestPointTo2(const AcGePoint3d& pnt, const AcGeTol& tol) const;
    PyGePointOnSurface getClosestPointTo1(const AcGePoint3d& pnt) const;
    PyGePointOnSurface getClosestPointTo2(const AcGePoint3d& pnt, const AcGeTol& tol) const;
    double          distanceTo1(const AcGePoint3d& pnt) const;
    double          distanceTo2(const AcGePoint3d& pnt, const AcGeTol& tol) const;
    Adesk::Boolean  isNormalReversed() const;
    PyAcGeSurface& reverseNormal();
    void            getEnvelope(PyGeInterval& intrvlX, PyGeInterval& intrvlY) const;
    Adesk::Boolean  isClosedInU1() const;
    Adesk::Boolean  isClosedInU2(const AcGeTol& tol) const;
    Adesk::Boolean  isClosedInV1() const;
    Adesk::Boolean  isClosedInV2(const AcGeTol& tol) const;
    AcGePoint3d     evalPoint1(const AcGePoint2d& param) const;
    AcGePoint3d     evalPoint2(const AcGePoint2d& param, int derivOrd, boost::python::list& derivatives) const;
    AcGePoint3d     evalPoint3(const AcGePoint2d& param, int derivOrd, boost::python::list& derivatives, AcGeVector3d& normal) const;
    static std::string className();
public:
    AcGeSurface* impObj(const std::source_location& src = std::source_location::current()) const;
};
