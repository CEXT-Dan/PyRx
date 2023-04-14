#pragma once
#include "PyGeEntity2d.h"

//-----------------------------------------------------------------------------------------
//PyGeCurve2d wrapper
void makePyGeCurve2dWrapper();

class PyGeCurve2d : public PyGeEntity2d
{
public:
    PyGeCurve2d(AcGeEntity2d* pEnt);
    static std::string className();
public:
    AcGeCurve2d* impObj() const;
};


//-----------------------------------------------------------------------------------------
//AcGeCircArc2d wrapper
void makeAcGeCircArc2dWrapper();
class PyGeCircArc2d : public PyGeCurve2d
{
public:
    PyGeCircArc2d();
    PyGeCircArc2d(AcGeEntity2d* pEnt);
    static std::string className();
public:
    AcGeCircArc2d* impObj() const;
};

//-----------------------------------------------------------------------------------------
//AcGeCircArc2d wrapper
void makeAcGeEllipArc2Wrapper();
class PyGeEllipArc2d : public PyGeCurve2d
{
public:
    PyGeEllipArc2d();
    PyGeEllipArc2d(AcGeEntity2d* pEnt);
    static std::string className();
public:
    AcGeEllipArc2d* impObj() const;
};

//-----------------------------------------------------------------------------------------
//PyGeExternalCurve2d wrapper
void makeAcGeExternalCurve2dWrapper();
class PyGeExternalCurve2d : public PyGeCurve2d
{
public:
    PyGeExternalCurve2d(AcGeEntity2d* pEnt);
    static std::string className();
public:
    AcGeExternalCurve2d* impObj() const;
};


//-----------------------------------------------------------------------------------------
//AcGeOffsetCurve2d wrapper
void makeAcGeOffsetCurve2dWrapper();
class PyGeOffsetCurve2d : public PyGeCurve2d
{
public:
    PyGeOffsetCurve2d(const PyGeCurve2d& baseCurve, double offsetDistance);
    PyGeOffsetCurve2d(AcGeEntity2d* pEnt);
    static std::string className();
public:
    AcGeOffsetCurve2d* impObj() const;
};
