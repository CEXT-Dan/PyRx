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
//AcGeCircArc3d
void makAcGeCircArc3dWrapper();
class PyGeCircArc3d : public PyGeCurve3d
{
public:
    PyGeCircArc3d();
    PyGeCircArc3d(AcGeEntity3d* pEnt);
    static std::string className();
public:
    AcGeCircArc3d* impObj() const;
};

//-----------------------------------------------------------------------------------
//AcGeCompositeCurve3d
void makAcGeCompositeCurve3dWrapper();
class PyGeCompositeCurve3d : public PyGeCurve3d
{
public:
    PyGeCompositeCurve3d();
    PyGeCompositeCurve3d(AcGeEntity3d* pEnt);
    static std::string className();
public:
    AcGeCompositeCurve3d* impObj() const;
};


//-----------------------------------------------------------------------------------------
//AcGeCircArc3d wrapper
void makeAcGeEllipArc3dWrapper();
class PyGeEllipArc3d : public PyGeCurve3d
{
public:
    PyGeEllipArc3d();
    PyGeEllipArc3d(AcGeEntity3d* pEnt);
    static std::string className();
public:
    AcGeEllipArc3d* impObj() const;
};

//-----------------------------------------------------------------------------------------
//PyGeExternalCurve3d wrapper
void makeAcGeExternalCurve3dWrapper();
class PyGeExternalCurve3d : public PyGeCurve3d
{
public:
    PyGeExternalCurve3d(AcGeEntity3d* pEnt);
    static std::string className();
public:
    AcGeExternalCurve3d* impObj() const;
};

//-----------------------------------------------------------------------------------------
//AcGeOffsetCurve3d wrapper
void makeAcGeOffsetCurve3dWrapper();
class PyGeOffsetCurve3d : public PyGeCurve3d
{
public:
    PyGeOffsetCurve3d(const PyGeCurve3d& baseCurve, const AcGeVector3d& planeNormal,double offsetDistance);
    PyGeOffsetCurve3d(AcGeEntity3d* pEnt);
    static std::string className();
public:
    AcGeOffsetCurve3d* impObj() const;
};