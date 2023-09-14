#pragma once

#include "PyGeCurve2d.h"

class PyGeKnotVector;

//-----------------------------------------------------------------------------------------
//PyGeSplineEnt2d wrapper
void makePyGeSplineEnt2dWrapper();
class PyGeSplineEnt2d : public PyGeCurve2d
{
public:
    PyGeSplineEnt2d(AcGeEntity2d* pEnt);

    Adesk::Boolean    isRational() const;
    int               degree() const;
    int               order() const;
    int               numKnots() const;
    PyGeKnotVector    knots() const;
    int               numControlPoints() const;
    int               continuityAtKnot1(int idx) const;
    int               continuityAtKnot2(int idx, const AcGeTol& tol) const;
    double            startParam() const;
    double            endParam() const;
    AcGePoint2d       startPoint() const;
    AcGePoint2d       endPoint() const;
    Adesk::Boolean    hasFitData() const;
    double            knotAt(int idx) const;
    void              setKnotAt(int idx, double val);
    AcGePoint2d       controlPointAt(int idx) const;
    void              setControlPointAt(int idx, const AcGePoint2d& pnt);
    static std::string className();
public:
    AcGeSplineEnt2d* impObj(const std::source_location& src = std::source_location::current()) const;
};


//-----------------------------------------------------------------------------------------
//AcGeCubicSplineCurve2d wrapper
void makePyGeCubicSplineCurve2dWrapper();
class PyGeCubicSplineCurve2d : public PyGeSplineEnt2d
{
public:
    PyGeCubicSplineCurve2d();
    PyGeCubicSplineCurve2d(AcGeEntity2d* pEnt);
    static std::string className();
public:
    AcGeCubicSplineCurve2d* impObj(const std::source_location& src = std::source_location::current()) const;
};


//-----------------------------------------------------------------------------------------
//AcGeNurbCurve2d  wrapper
void makePyGeNurbCurve2dWrapper();
class PyGeNurbCurve2d : public PyGeSplineEnt2d
{
public:
    PyGeNurbCurve2d();
    PyGeNurbCurve2d(AcGeEntity2d* pEnt);
    static std::string className();
public:
    AcGeNurbCurve2d* impObj(const std::source_location& src = std::source_location::current()) const;
};


//-----------------------------------------------------------------------------------------
//PyGePolyline2d  wrapper
void makePyGePolyline2dWrapper();
class PyGePolyline2d : public PyGeSplineEnt2d
{
public:
    PyGePolyline2d();
    PyGePolyline2d(const AcGePolyline2d& src);
    PyGePolyline2d(const boost::python::list& points);
    PyGePolyline2d(const PyGeKnotVector& knots, const boost::python::list& points);
    PyGePolyline2d(const PyGeCurve2d& crv, double apprEps);
    PyGePolyline2d(AcGeEntity2d* pEnt);
    int              numFitPoints() const;
    AcGePoint2d      fitPointAt(int idx) const;
    void             setFitPointAt(int idx, const AcGePoint2d& point);
    static std::string className();
public:
    AcGePolyline2d* impObj(const std::source_location& src = std::source_location::current()) const;
};







