#pragma once

#include "PyGeCurve3d.h"


//-----------------------------------------------------------------------------------
//PyGeLinearEnt3d
void makPyGeLinearEnt3dWrapper();
class PyGeLinearEnt3d : public PyGeCurve3d
{
public:
    PyGeLinearEnt3d(AcGeEntity3d* pEnt);
    static std::string className();
public:
    AcGeLinearEnt3d* impObj() const;
};

//-----------------------------------------------------------------------------------
//AcGeLine3d
void makAcGeLine3dWrapper();
class PyGeLine3d : public PyGeLinearEnt3d
{
public:
    PyGeLine3d();
    PyGeLine3d(AcGeEntity3d* pEnt);
    static std::string className();
public:
    AcGeLine3d* impObj() const;
};


//-----------------------------------------------------------------------------------
//PyGeLineSeg3d
void makPyGeLineSeg3dWrapper();
class PyGeLineSeg3d : public PyGeLinearEnt3d
{
public:
    PyGeLineSeg3d();
    PyGeLineSeg3d(AcGeEntity3d* pEnt);
    static std::string className();
public:
    AcGeLineSeg3d* impObj() const;
};


//-----------------------------------------------------------------------------------
//AcGeRay3d
void makAcGeRay3ddWrapper();
class PyGeRay3d : public PyGeLinearEnt3d
{
public:
    PyGeRay3d();
    PyGeRay3d(AcGeEntity3d* pEnt);
    static std::string className();
public:
    AcGeRay3d* impObj() const;
};

