#pragma once
#include "PyGeEntity3d.h"

#pragma pack (push, 8)

class PyGeCurve3d;
class PyGeSurface;

//-------------------------------------------------------------------------------------------------------
//PyGePointEnt3d
void makePyGePointEnt3dWrapper();
class PyGePointEnt3d : public PyGeEntity3d
{
public:
    PyGePointEnt3d(AcGeEntity3d* src);
    AcGePoint3d         point3d() const;
    static PyGePointEnt3d cast(const PyGeEntity3d& src);
    static PyGePointEnt3d copycast(const PyGeEntity3d& src);
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

    static PyGePointOnCurve3d cast(const PyGeEntity3d& src);
    static PyGePointOnCurve3d copycast(const PyGeEntity3d& src);
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
    PyGePointOnSurface(const PyGeSurface& surf);
    PyGePointOnSurface(const PyGeSurface& surf, const AcGePoint2d& param);
    PyGePointOnSurface(const AcGePointOnSurface& src);
    PyGePointOnSurface(AcGeEntity3d* src);

    PyGeSurface         surface() const;
    AcGePoint2d         parameter() const;

    AcGePoint3d         point1() const;
    AcGePoint3d         point2(const AcGePoint2d& param);
    AcGePoint3d         point3(const PyGeSurface& surf, const AcGePoint2d& param);

    AcGeVector3d        normal1() const;
    AcGeVector3d        normal2(const AcGePoint2d& param);
    AcGeVector3d        normal3(const PyGeSurface& surf, const AcGePoint2d& param);

    AcGeVector3d        uDeriv1(int order) const;
    AcGeVector3d        uDeriv2(int order, const AcGePoint2d& param);
    AcGeVector3d        uDeriv3(int order, const PyGeSurface& surf, const AcGePoint2d& param);

    AcGeVector3d        vDeriv1(int order) const;
    AcGeVector3d        vDeriv2(int order, const AcGePoint2d& param);
    AcGeVector3d        vDeriv3(int order, const PyGeSurface& surf, const AcGePoint2d& param);

    AcGeVector3d        mixedPartial1() const;
    AcGeVector3d        mixedPartial2(const AcGePoint2d& param);
    AcGeVector3d        mixedPartial3(const PyGeSurface& surf, const AcGePoint2d& param);

    AcGeVector3d        tangentVector1(const AcGeVector2d& vec) const;
    AcGeVector3d        tangentVector2(const AcGeVector2d& vec, const AcGePoint2d& param);
    AcGeVector3d        tangentVector3(const AcGeVector2d& vec, const PyGeSurface& vecSurf, const AcGePoint2d& param);

    AcGeVector2d        inverseTangentVector1(const AcGeVector3d& vec) const;
    AcGeVector2d        inverseTangentVector2(const AcGeVector3d& vec, const AcGePoint2d& param);
    AcGeVector2d        inverseTangentVector3(const AcGeVector3d& vec, const PyGeSurface& surf, const AcGePoint2d& param);

    void                setSurface(const PyGeSurface& surf);
    void                setParameter(const AcGePoint2d& param);

    static PyGePointOnSurface cast(const PyGeEntity3d& src);
    static PyGePointOnSurface copycast(const PyGeEntity3d& src);
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
    PyGePosition3d(const AcGePoint3d& pnt);
    PyGePosition3d(double x, double y, double z);
    PyGePosition3d(AcGeEntity3d* src);

    void set1(const AcGePoint3d& pnt);
    void set2(double x, double y, double z);
    static PyGePosition3d cast(const PyGeEntity3d& src);
    static PyGePosition3d copycast(const PyGeEntity3d& src);
    static std::string className();
public:
    AcGePosition3d* impObj(const std::source_location& src = std::source_location::current()) const;
};
#pragma pack (pop)
