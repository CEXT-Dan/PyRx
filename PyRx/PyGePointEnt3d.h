#pragma once
#include "PyGeEntity3d.h"

class PyGeCurve3d;


//-------------------------------------------------------------------------------------------------------
//PyGePointEnt3d
void makePyGePointEnt3dWrapper();
class PyGePointEnt3d : public PyGeEntity3d
{
public:
    PyGePointEnt3d(AcGeEntity3d* src);
    AcGePoint3d         point3d() const;
    static std::string className();
public:
    AcGePointEnt3d* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-------------------------------------------------------------------------------------------------------
//PyGePointOnCurve3d
void makePyGePointOnCurve3dWrapper();
class PyGePointOnCurve3d : public PyGePointEnt3d
{
public:
    PyGePointOnCurve3d();
    PyGePointOnCurve3d(const PyGeCurve3d& crv);
    PyGePointOnCurve3d(const PyGeCurve3d& crv, double param);

    PyGePointOnCurve3d(const AcGePointOnCurve3d& src);
    PyGePointOnCurve3d(AcGeEntity3d* src);

    PyGeCurve3d         curve() const;
    double              parameter() const;
    AcGePoint3d         point1() const;
    AcGePoint3d         point2(double param);
    AcGePoint3d         point3(const PyGeCurve3d& crv, double param);

    AcGeVector3d        deriv1(int order) const;
    AcGeVector3d        deriv2(int order, double param);
    AcGeVector3d        deriv3(int order, const PyGeCurve3d& crv, double param);

    Adesk::Boolean      isSingular() const;
    double     	        curvature1();
    double     	        curvature2(double param);

    void                setCurve(const PyGeCurve3d& crv);
    void                setParameter(double param);

    static std::string  className();
public:
    AcGePointOnCurve3d* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-------------------------------------------------------------------------------------------------------
//PyGePointOnSurface
void makePyGePointOnSurfaceWrapper();
class PyGePointOnSurface : public PyGePointEnt3d
{
public:
    PyGePointOnSurface();
    PyGePointOnSurface(AcGeEntity3d* src);
    static std::string className();
public:
    AcGePointOnSurface* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-------------------------------------------------------------------------------------------------------
//PyGePosition3d
void makePyGePosition3dWrapper();
class PyGePosition3d : public PyGePointEnt3d
{
public:
    PyGePosition3d();
    PyGePosition3d(AcGeEntity3d* src);
    static std::string className();
public:
    AcGePosition3d* impObj(const std::source_location& src = std::source_location::current()) const;
};