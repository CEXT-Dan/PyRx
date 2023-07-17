#pragma once
#include "PyGeCurve3d.h"
class PyGePlanarEnt;
class PyGePlane;
class PyGeLine3d;
//-----------------------------------------------------------------------------------
//PyGeLinearEnt3d
void makePyGeLinearEnt3dWrapper();
class PyGeLinearEnt3d : public PyGeCurve3d
{
public:
    PyGeLinearEnt3d(AcGeEntity3d* pEnt);
    boost::python::tuple intersectWith1(const PyGeLinearEnt3d& line) const;
    boost::python::tuple intersectWith2(const PyGeLinearEnt3d& line, const AcGeTol& tol) const;
    boost::python::tuple intersectWith3(const PyGePlanarEnt& line) const;
    boost::python::tuple intersectWith4(const PyGePlanarEnt& line, const AcGeTol& tol) const;
    boost::python::tuple projIntersectWith1(const PyGeLinearEnt3d& line, const AcGeVector3d& projDir) const;
    boost::python::tuple projIntersectWith2(const PyGeLinearEnt3d& line, const AcGeVector3d& projDir, const AcGeTol& tol) const;
    boost::python::tuple overlap1(const PyGeLinearEnt3d& line) const;
    boost::python::tuple overlap2(const PyGeLinearEnt3d& line, const AcGeTol& tol) const;
    boost::python::tuple isOn1(const AcGePoint3d& pnt) const;
    boost::python::tuple isOn2(const AcGePoint3d& pnt, const AcGeTol& tol) const;
    Adesk::Boolean isOn3(const double param) const;
    Adesk::Boolean isOn4(const double param, const AcGeTol& tol) const;
    Adesk::Boolean isOn5(const PyGePlane& plane) const;
    Adesk::Boolean isOn6(const PyGePlane& plane, const AcGeTol& tol) const;
    Adesk::Boolean isParallelTo1(const PyGeLinearEnt3d& line) const;
    Adesk::Boolean isParallelTo2(const PyGeLinearEnt3d& line, const AcGeTol& tol) const;
    Adesk::Boolean isParallelTo3(const PyGePlanarEnt& plane) const;
    Adesk::Boolean isParallelTo4(const PyGePlanarEnt& plane, const AcGeTol& tol) const;
    Adesk::Boolean isPerpendicularTo1(const PyGeLinearEnt3d& line) const;
    Adesk::Boolean isPerpendicularTo2(const PyGeLinearEnt3d& line, const AcGeTol& tol) const;
    Adesk::Boolean isPerpendicularTo3(const PyGePlanarEnt& plane) const;
    Adesk::Boolean isPerpendicularTo4(const PyGePlanarEnt& plane, const AcGeTol& tol) const;
    Adesk::Boolean isColinearTo1(const PyGeLinearEnt3d& line) const;
    Adesk::Boolean isColinearTo2(const PyGeLinearEnt3d& line, const AcGeTol& tol) const;
    PyGePlane      getPerpPlane(const AcGePoint3d& pnt) const;
    AcGePoint3d    pointOnLine() const;
    AcGeVector3d   direction() const;
    PyGeLine3d     getLine() const;
    static std::string className();
public:
    AcGeLinearEnt3d* impObj(const std::source_location& src = std::source_location::current()) const;
};
//-----------------------------------------------------------------------------------
//AcGeLine3d
void makePyGeLine3dWrapper();
class PyGeLine3d : public PyGeLinearEnt3d
{
public:
    PyGeLine3d();
    PyGeLine3d(const AcGeLine3d& src);
    PyGeLine3d(const AcGePoint3d& pnt, const AcGeVector3d& vec);
    PyGeLine3d(const AcGePoint3d& pnt1, const AcGePoint3d& pnt2);
    PyGeLine3d(AcGeEntity3d* pEnt);
    static PyGeLine3d kXAxis();
    static PyGeLine3d kYAxis();
    static PyGeLine3d kZAxis();
    PyGeLine3d& set1(const AcGePoint3d& pnt, const AcGeVector3d& vec);
    PyGeLine3d& set2(const AcGePoint3d& pnt1, const AcGePoint3d& pnt2);
    static std::string className();
public:
    AcGeLine3d* impObj(const std::source_location& src = std::source_location::current()) const;
};
//-----------------------------------------------------------------------------------
//PyGeLineSeg3d
void makePyGeLineSeg3dWrapper();
class PyGeLineSeg3d : public PyGeLinearEnt3d
{
public:
    PyGeLineSeg3d();
    PyGeLineSeg3d(const AcGePoint3d& pnt, const AcGeVector3d& vec);
    PyGeLineSeg3d(const AcGePoint3d& pnt1, const AcGePoint3d& pnt2);
    PyGeLineSeg3d(AcGeEntity3d* pEnt);
    PyGeLineSeg3d(const AcGeLineSeg3d& src);
    PyGePlane      getBisector() const;
    AcGePoint3d    baryComb(double blendCoeff) const;
    AcGePoint3d    startPoint() const;
    AcGePoint3d    midPoint() const;
    AcGePoint3d    endPoint() const;
    double         length1() const;
    double         length2(double fromParam, double toParam) const;
    double         length3(double fromParam, double toParam, double tol) const;
    PyGeLineSeg3d& set1(const AcGePoint3d& pnt, const AcGeVector3d& vec);
    PyGeLineSeg3d& set2(const AcGePoint3d& pnt1, const AcGePoint3d& pnt2);
    static std::string className();
public:
    AcGeLineSeg3d* impObj(const std::source_location& src = std::source_location::current()) const;
};
//-----------------------------------------------------------------------------------
//AcGeRay3d
void makePyGeRay3ddWrapper();
class PyGeRay3d : public PyGeLinearEnt3d
{
public:
    PyGeRay3d();
    PyGeRay3d(const AcGeRay3d& line);
    PyGeRay3d(const AcGePoint3d& pnt, const AcGeVector3d& vec);
    PyGeRay3d(const AcGePoint3d& pnt1, const AcGePoint3d& pnt2);
    PyGeRay3d(AcGeEntity3d* pEnt);
    PyGeRay3d& set1(const AcGePoint3d& pnt, const AcGeVector3d& vec);
    PyGeRay3d& set2(const AcGePoint3d& pnt1, const AcGePoint3d& pnt2);
    static std::string className();
public:
    AcGeRay3d* impObj(const std::source_location& src = std::source_location::current()) const;
};
