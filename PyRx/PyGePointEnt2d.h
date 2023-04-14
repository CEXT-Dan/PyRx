#pragma once
#include "PyGeEntity2d.h"

//-----------------------------------------------------------------------------------------
//PyGePointEnt2d wrapper
void makePyGePointEnt2dWrapper();

class PyGePointEnt2d : public PyGeEntity2d
{
public:
    PyGePointEnt2d(AcGeEntity2d* pEnt);
    static std::string className();
public:
    AcGePointEnt2d* impObj() const;
};

//-----------------------------------------------------------------------------------------
//PyGePointOnCurve2d wrapper
void makePyGePointOnCurve2dWrapper();

class PyGePointOnCurve2d : public PyGePointEnt2d
{
public:
    PyGePointOnCurve2d();
    PyGePointOnCurve2d(AcGeEntity2d* pEnt);
    static std::string className();
public:
    AcGePointOnCurve2d* impObj() const;
};

//-----------------------------------------------------------------------------------------
//AcGePosition2d wrapper
void makeAcGePosition2dWrapper();

class PyGePosition2d : public PyGePointEnt2d
{
public:
    PyGePosition2d();
    PyGePosition2d(AcGeEntity2d* pEnt);
    static std::string className();
public:
    AcGePosition2d* impObj() const;
};


