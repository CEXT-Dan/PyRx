#pragma once

#include "PyGeCurve3d.h"

//-----------------------------------------------------------------------------------------
//PyGeSplineEnt3d wrapper
void makePyGeSplineEnt3dWrapper();
class PyGeSplineEnt3d : public PyGeCurve3d
{
public:
    PyGeSplineEnt3d(AcGeEntity3d* pEnt);
    static std::string className();
public:
    AcGeSplineEnt3d* impObj() const;
};


//-----------------------------------------------------------------------------------------
//AcGeCubicSplineCurve3d wrapper
void makAcGeCubicSplineCurve3dWrapper();
class PyGeCubicSplineCurve3d : public PyGeSplineEnt3d
{
public:
    PyGeCubicSplineCurve3d();
    PyGeCubicSplineCurve3d(AcGeEntity3d* pEnt);
    static std::string className();
public:
    AcGeCubicSplineCurve3d* impObj() const;
};


//-----------------------------------------------------------------------------------------
//AcGeNurbCurve3d  wrapper
void makAcGeNurbCurve3dWrapper();
class PyGeNurbCurve3d : public PyGeSplineEnt3d
{
public:
    PyGeNurbCurve3d();
    PyGeNurbCurve3d(AcGeEntity3d* pEnt);
    static std::string className();
public:
    AcGeNurbCurve3d* impObj() const;
};


//-----------------------------------------------------------------------------------------
//PyGePolyline3d  wrapper
void makAcGePolyline3dWrapper();
class PyGePolyline3d : public PyGeSplineEnt3d
{
public:
    PyGePolyline3d();
    PyGePolyline3d(AcGeEntity3d* pEnt);
    static std::string className();
public:
    AcGePolyline3d* impObj() const;
};






