#pragma once
#include "PyGeEntity3d.h"


//-----------------------------------------------------------------------------------
//PyGeCurve3d
void makPyGeCurve3dWrapper();
class PyGeCurve3d : public PyGeEntity3d
{
public:
    PyGeCurve3d(AcGeEntity3d* pEnt);
    static std::string className();
public:
    AcGeCurve3d* impObj() const;
};

//-----------------------------------------------------------------------------------
//PyGeLinearEnt2d
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
//PyGeLineSeg2d
void makPyGeLineSeg3dWrapper();
class PyGeLineSeg3d : public PyGeLinearEnt3d
{
public:
    PyGeLineSeg3d(AcGeEntity3d* pEnt);
    static std::string className();
public:
    AcGeLineSeg3d* impObj() const;
};
