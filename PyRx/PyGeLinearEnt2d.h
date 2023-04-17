#pragma once
#include "PyGeCurve2d.h"
class PyGeLine2d;
//-----------------------------------------------------------------------------------------
//AcGeLinearEnt2d wrapper
void makeAcGeLinearEnt2dWrapper();
class PyGeLinearEnt2d : public PyGeCurve2d
{
public:
    PyGeLinearEnt2d(AcGeEntity2d* pEnt);

    boost::python::tuple intersectWith1(const PyGeLinearEnt2d& line);
    boost::python::tuple intersectWith2(const PyGeLinearEnt2d& line, const AcGeTol& tol);

    boost::python::tuple  overlap1(const PyGeLinearEnt2d& line) const;
    boost::python::tuple  overlap2(const PyGeLinearEnt2d& line, const AcGeTol& tol) const;

    Adesk::Boolean isParallelTo1(const PyGeLinearEnt2d& line) const;
    Adesk::Boolean isParallelTo2(const PyGeLinearEnt2d& line, const AcGeTol& tol) const;

    Adesk::Boolean   isPerpendicularTo1(const PyGeLinearEnt2d& line) const;
    Adesk::Boolean   isPerpendicularTo2(const PyGeLinearEnt2d& line,const AcGeTol& tol) const;

    Adesk::Boolean   isColinearTo1(const PyGeLinearEnt2d& line) const;
    Adesk::Boolean   isColinearTo2(const PyGeLinearEnt2d& line, const AcGeTol& tol) const;

    PyGeLine2d getPerpLine(const AcGePoint2d& pnt) const;
    PyGeLine2d getLine() const;

    AcGePoint2d      pointOnLine() const;
    AcGeVector2d     direction() const;

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



