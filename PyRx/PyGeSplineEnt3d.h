#pragma once

#include "PyGeCurve3d.h"

class PyGeKnotVector;
//-----------------------------------------------------------------------------------------
//PyGeSplineEnt3d wrapper
void makePyGeSplineEnt3dWrapper();
class PyGeSplineEnt3d : public PyGeCurve3d
{
public:
    PyGeSplineEnt3d(AcGeEntity3d* pEnt);
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
    AcGePoint3d       startPoint() const;
    AcGePoint3d       endPoint() const;
    Adesk::Boolean    hasFitData() const;
    double            knotAt(int idx) const;
    PyGeSplineEnt3d&  setKnotAt(int idx, double val);
    AcGePoint3d       controlPointAt(int idx) const;
    PyGeSplineEnt3d&  setControlPointAt(int idx, const AcGePoint3d& pnt);
    static std::string className();
public:
    AcGeSplineEnt3d* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//AcGeCubicSplineCurve3d wrapper
void makePyGeCubicSplineCurve3dWrapper();
class PyGeCubicSplineCurve3d : public PyGeSplineEnt3d
{
public:
    PyGeCubicSplineCurve3d();
    PyGeCubicSplineCurve3d(AcGeEntity3d* pEnt);
    static std::string className();
public:
    AcGeCubicSplineCurve3d* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//AcGeNurbCurve3d  wrapper
void makePyGeNurbCurve3dWrapper();
class PyGeNurbCurve3d : public PyGeSplineEnt3d
{
public:
    PyGeNurbCurve3d();
    PyGeNurbCurve3d(AcGeEntity3d* pEnt);
    static std::string className();
public:
    AcGeNurbCurve3d* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PyGePolyline3d  wrapper
void makePyGePolyline3dWrapper();
class PyGePolyline3d : public PyGeSplineEnt3d
{
public:
    PyGePolyline3d();
    PyGePolyline3d(AcGeEntity3d* pEnt);
    PyGePolyline3d(const AcGePolyline3d& src);
    PyGePolyline3d(const boost::python::list& points);
    PyGePolyline3d(const PyGeKnotVector& knots, const boost::python::list& points);
#if !defined(_BRXTARGET) && (_BRXTARGET <= 23)
    PyGePolyline3d(const PyGeCurve3d& crv, double apprEps);
#endif

    int              numFitPoints() const;
    AcGePoint3d      fitPointAt(int idx) const;
    PyGeSplineEnt3d& setFitPointAt(int idx, const AcGePoint3d& point);


    static std::string className();
public:
    AcGePolyline3d* impObj(const std::source_location& src = std::source_location::current()) const;
};






