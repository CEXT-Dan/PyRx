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

    PyGeSplineEnt2d&  setKnotAt(int idx, double val);
    AcGePoint2d       controlPointAt(int idx) const;
    PyGeSplineEnt2d&  setControlPointAt(int idx, const AcGePoint2d& pnt);

    static std::string className();
public:
    AcGeSplineEnt2d* impObj() const;
};


//-----------------------------------------------------------------------------------------
//AcGeCubicSplineCurve2d wrapper
void makAcGeCubicSplineCurve2dWrapper();
class PyGeCubicSplineCurve2d : public PyGeSplineEnt2d
{
public:
    PyGeCubicSplineCurve2d();
    PyGeCubicSplineCurve2d(AcGeEntity2d* pEnt);
    static std::string className();
public:
    AcGeCubicSplineCurve2d* impObj() const;
};


//-----------------------------------------------------------------------------------------
//AcGeNurbCurve2d  wrapper
void makAcGeNurbCurve2dWrapper();
class PyGeNurbCurve2d : public PyGeSplineEnt2d
{
public:
    PyGeNurbCurve2d();
    PyGeNurbCurve2d(AcGeEntity2d* pEnt);
    static std::string className();
public:
    AcGeNurbCurve2d* impObj() const;
};


//-----------------------------------------------------------------------------------------
//PyGePolyline2d  wrapper
void makAcGePolyline2dWrapper();
class PyGePolyline2d : public PyGeSplineEnt2d
{
public:
    PyGePolyline2d();
    PyGePolyline2d(AcGeEntity2d* pEnt);
    static std::string className();
public:
    AcGePolyline2d* impObj() const;
};







