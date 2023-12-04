#pragma once
#include "PyGeEntity2d.h"
class PyGeCurve2d;
//-----------------------------------------------------------------------------------------
//PyGePointEnt2d wrapper
void makePyGePointEnt2dWrapper();

class PyGePointEnt2d : public PyGeEntity2d
{
public:
    PyGePointEnt2d(AcGeEntity2d* pEnt);
    AcGePoint2d     point2d() const;
    static PyGePointEnt2d cast(const PyGeEntity2d& src);
    static PyGePointEnt2d copycast(const PyGeEntity2d& src);
    static std::string className();
public:
    AcGePointEnt2d* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PyGePointOnCurve2d wrapper
void makePyGePointOnCurve2dWrapper();

class PyGePointOnCurve2d : public PyGePointEnt2d
{
public:
    PyGePointOnCurve2d();
    PyGePointOnCurve2d(const AcGePointOnCurve2d& src);
    PyGePointOnCurve2d(const PyGeCurve2d& crv);
    PyGePointOnCurve2d(const PyGeCurve2d& crv, double param);
    PyGePointOnCurve2d(AcGeEntity2d* pEnt);
    const PyGeCurve2d   curve() const;
    double              parameter() const;
    AcGePoint2d         point1() const;
    AcGePoint2d         point2(double param);
    AcGePoint2d         point3(const PyGeCurve2d& crv, double param);
    AcGeVector2d        deriv1(int order) const;
    AcGeVector2d        deriv2(int order, double param);
    AcGeVector2d        deriv3(int order, const PyGeCurve2d& crv, double param);
#ifdef NEVER //acad link error
    Adesk::Boolean      isSingular1() const;
    Adesk::Boolean      isSingular2(const AcGeTol& tol) const;
#endif

#ifdef NEVER //acad link error
    boost::python::tuple   curvature();
    boost::python::tuple   curvature(double param);
#endif
   void setCurve(const PyGeCurve2d& crv);
   void setParameter(double param);

    static PyGePointOnCurve2d copy(const PyGeEntity2d& src);
    static PyGePointOnCurve2d copycast(const PyGeEntity2d& src);
    static std::string className();
public:
    AcGePointOnCurve2d* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//AcGePosition2d wrapper
void makePyGePosition2dWrapper();

class PyGePosition2d : public PyGePointEnt2d
{
public:
    PyGePosition2d();
    PyGePosition2d(const AcGePoint2d& pnt);
    PyGePosition2d(double x, double y);
#if !defined(_BRXTARGET240)
    PyGePosition2d(const AcGePosition2d& pos);
#endif
    PyGePosition2d(AcGeEntity2d* pEnt);
    void set1(const AcGePoint2d&);
    void set2(double x, double y);
    static PyGePosition2d cast(const PyGeEntity2d& src);
    static PyGePosition2d copycast(const PyGeEntity2d& src);
    static std::string className();
public:
    AcGePosition2d* impObj(const std::source_location& src = std::source_location::current()) const;
};


