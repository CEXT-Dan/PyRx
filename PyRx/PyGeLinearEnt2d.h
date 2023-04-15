#pragma once
#include "PyGeCurve2d.h"
//-----------------------------------------------------------------------------------------
//AcGeLinearEnt2d wrapper
void makeAcGeLinearEnt2dWrapper();
class PyGeLinearEnt2d : public PyGeCurve2d
{
public:
    PyGeLinearEnt2d(AcGeEntity2d* pEnt);
    static std::string className();
public:
    AcGeLinearEnt2d* impObj() const;
};

//-----------------------------------------------------------------------------------------
//AcGeLine2d  wrapper
void makeAcGeLine2dWrapper();
class PyGeLine2d : public PyGeLinearEnt2d
{
public:
    PyGeLine2d();
    PyGeLine2d(const AcGeLine2d& pEnt);
    PyGeLine2d(AcGeEntity2d* pEnt);
    static std::string className();
public:
    AcGeLine2d* impObj() const;
};

//-----------------------------------------------------------------------------------------
//AcGeLineSeg2d  wrapper
void makePyGeLineSeg2dWrapper();
class PyGeLineSeg2d : public PyGeLinearEnt2d
{
public:
    PyGeLineSeg2d();
    PyGeLineSeg2d(AcGeEntity2d* pEnt);
    static std::string className();
public:
    AcGeLineSeg2d* impObj() const;
};

//-----------------------------------------------------------------------------------------
//AcGeRay2d  wrapper
void makeAcGeRay2dWrapper();
class PyGeRay2d : public PyGeLinearEnt2d
{
public:
    PyGeRay2d();
    PyGeRay2d(AcGeEntity2d* pEnt);
    static std::string className();
public:
    AcGeRay2d* impObj() const;
};



