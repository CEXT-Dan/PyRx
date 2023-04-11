#pragma once
#include "PyGeEntity3d.h"
//-------------------------------------------------------------------------------------------------------
//PyGePointEnt3d
void makePyGePointEnt3dWrapper();
class PyGePointEnt3d : public PyGeEntity3d
{
public:
    PyGePointEnt3d(AcGeEntity3d* src);
    static std::string className();
public:
    AcGePointEnt3d* impObj() const;
};

//-------------------------------------------------------------------------------------------------------
//PyGePointOnCurve3d
void makePyGePointOnCurve3dWrapper();
class PyGePointOnCurve3d : public PyGePointEnt3d
{
public:
    PyGePointOnCurve3d();
    PyGePointOnCurve3d(AcGeEntity3d* src);
    static std::string className();
public:
    AcGePointOnCurve3d* impObj() const;
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
    AcGePointOnSurface* impObj() const;
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
    AcGePosition3d* impObj() const;
};