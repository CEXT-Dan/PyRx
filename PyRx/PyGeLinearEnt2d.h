#pragma once
#include "PyGeCurve2d.h"
class PyGeLine2d;
//-----------------------------------------------------------------------------------------
//AcGeLinearEnt2d wrapper
void makePyGeLinearEnt2dWrapper();
class PyGeLinearEnt2d : public PyGeCurve2d
{
public:
    PyGeLinearEnt2d(AcGeEntity2d* pEnt);

    boost::python::tuple intersectWith1(const PyGeLinearEnt2d& line);
    boost::python::tuple intersectWith2(const PyGeLinearEnt2d& line, const AcGeTol& tol);
    boost::python::tuple  overlap1(const PyGeLinearEnt2d& line) const;
    boost::python::tuple  overlap2(const PyGeLinearEnt2d& line, const AcGeTol& tol) const;
    Adesk::Boolean  isParallelTo1(const PyGeLinearEnt2d& line) const;
    Adesk::Boolean  isParallelTo2(const PyGeLinearEnt2d& line, const AcGeTol& tol) const;
    Adesk::Boolean  isPerpendicularTo1(const PyGeLinearEnt2d& line) const;
    Adesk::Boolean  isPerpendicularTo2(const PyGeLinearEnt2d& line, const AcGeTol& tol) const;
    Adesk::Boolean  isColinearTo1(const PyGeLinearEnt2d& line) const;
    Adesk::Boolean  isColinearTo2(const PyGeLinearEnt2d& line, const AcGeTol& tol) const;
    PyGeLine2d      getPerpLine(const AcGePoint2d& pnt) const;
    PyGeLine2d      getLine() const;
    AcGePoint2d     pointOnLine() const;
    AcGeVector2d    direction() const;
    static std::string className();
public:
    AcGeLinearEnt2d* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//AcGeLine2d  wrapper
void makePyGeLine2dWrapper();
class PyGeLine2d : public PyGeLinearEnt2d
{
public:
    PyGeLine2d();
    PyGeLine2d(const AcGeLine2d& pEnt);
    PyGeLine2d(const AcGePoint2d& pnt, const AcGeVector2d& vec);
    PyGeLine2d(const AcGePoint2d& pnt1, const AcGePoint2d& pnt2);
    PyGeLine2d(AcGeEntity2d* pEnt);
    static PyGeLine2d kXAxis();
    static PyGeLine2d kYAxis();
    PyGeLine2d& set1(const AcGePoint2d& pnt, const AcGeVector2d& vec);
    PyGeLine2d& set2(const AcGePoint2d& pnt1, const AcGePoint2d& pnt2);
    static std::string className();
public:
    AcGeLine2d* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//AcGeLineSeg2d  wrapper
void makePyGeLineSeg2dWrapper();
class PyGeLineSeg2d : public PyGeLinearEnt2d
{
public:
    PyGeLineSeg2d();
    PyGeLineSeg2d(const AcGeLineSeg2d& src);
    PyGeLineSeg2d(const AcGePoint2d& pnt1, const AcGePoint2d& pnt2);
    PyGeLineSeg2d(const AcGePoint2d& pnt, const AcGeVector2d& vec);
    PyGeLineSeg2d(AcGeEntity2d* pEnt);
    PyGeLineSeg2d&  set1(const AcGePoint2d& pnt, const AcGeVector2d& vec);
    PyGeLineSeg2d&  set2(const AcGePoint2d& pnt1, const AcGePoint2d& pnt2);
    PyGeLineSeg2d&  set3(const PyGeCurve2d& curve1, const PyGeCurve2d& curve2);
    PyGeLineSeg2d&  set4(const PyGeCurve2d& curve, const AcGePoint2d& point);
    PyGeLine2d      getBisector() const;
    AcGePoint2d     baryComb(double blendCoeff) const;
    AcGePoint2d     startPoint() const;
    AcGePoint2d     midPoint() const;
    AcGePoint2d     endPoint() const;
    double          length1() const;
    double          length2(double fromParam, double toParam) const;
    double          length3(double fromParam, double toParam, double tol) const;
    static std::string className();
public:
    AcGeLineSeg2d* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//AcGeRay2d  wrapper
void makePyGeRay2dWrapper();
class PyGeRay2d : public PyGeLinearEnt2d
{
public:
    PyGeRay2d();
    PyGeRay2d(const AcGeRay2d& line);
    PyGeRay2d(const AcGePoint2d& pnt, const AcGeVector2d& vec);
    PyGeRay2d(const AcGePoint2d& pnt1, const AcGePoint2d& pnt2);
    PyGeRay2d(AcGeEntity2d* pEnt);

    PyGeRay2d&      set1(const AcGePoint2d& pnt, const AcGeVector2d& vec);
    PyGeRay2d&      set2(const AcGePoint2d& pnt1, const AcGePoint2d& pnt2);
    static std::string className();
public:
    AcGeRay2d* impObj(const std::source_location& src = std::source_location::current()) const;
};



