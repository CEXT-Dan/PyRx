#pragma once
#include "PyGeCurve3d.h"

#pragma pack (push, 8)
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
    virtual ~PyGeLinearEnt3d() override = default;
    boost::python::tuple    intersectWith1(const PyGeLinearEnt3d& line) const;
    boost::python::tuple    intersectWith2(const PyGeLinearEnt3d& line, const AcGeTol& tol) const;
    boost::python::tuple    intersectWith3(const PyGePlanarEnt& line) const;
    boost::python::tuple    intersectWith4(const PyGePlanarEnt& line, const AcGeTol& tol) const;
    boost::python::tuple    projIntersectWith1(const PyGeLinearEnt3d& line, const AcGeVector3d& projDir) const;
    boost::python::tuple    projIntersectWith2(const PyGeLinearEnt3d& line, const AcGeVector3d& projDir, const AcGeTol& tol) const;
    boost::python::tuple    overlap1(const PyGeLinearEnt3d& line) const;
    boost::python::tuple    overlap2(const PyGeLinearEnt3d& line, const AcGeTol& tol) const;
    boost::python::tuple    isOn1(const AcGePoint3d& pnt) const;
    boost::python::tuple    isOn2(const AcGePoint3d& pnt, const AcGeTol& tol) const;
    Adesk::Boolean          isOn3(const double param) const;
    Adesk::Boolean          isOn4(const double param, const AcGeTol& tol) const;
    Adesk::Boolean          isOn5(const PyGePlane& plane) const;
    Adesk::Boolean          isOn6(const PyGePlane& plane, const AcGeTol& tol) const;
    Adesk::Boolean          isParallelTo1(const PyGeLinearEnt3d& line) const;
    Adesk::Boolean          isParallelTo2(const PyGeLinearEnt3d& line, const AcGeTol& tol) const;
    Adesk::Boolean          isParallelTo3(const PyGePlanarEnt& plane) const;
    Adesk::Boolean          isParallelTo4(const PyGePlanarEnt& plane, const AcGeTol& tol) const;
    Adesk::Boolean          isPerpendicularTo1(const PyGeLinearEnt3d& line) const;
    Adesk::Boolean          isPerpendicularTo2(const PyGeLinearEnt3d& line, const AcGeTol& tol) const;
    Adesk::Boolean          isPerpendicularTo3(const PyGePlanarEnt& plane) const;
    Adesk::Boolean          isPerpendicularTo4(const PyGePlanarEnt& plane, const AcGeTol& tol) const;
    Adesk::Boolean          isColinearTo1(const PyGeLinearEnt3d& line) const;
    Adesk::Boolean          isColinearTo2(const PyGeLinearEnt3d& line, const AcGeTol& tol) const;
    PyGePlane               getPerpPlane(const AcGePoint3d& pnt) const;
    AcGePoint3d             pointOnLine() const;
    AcGeVector3d            direction() const;
    PyGeLine3d              getLine() const;
    static PyGeLinearEnt3d  cast(const PyGeEntity3d& src);
    static PyGeLinearEnt3d  copycast(const PyGeEntity3d& src);
    static std::string      className();
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
    virtual ~PyGeLine3d() override = default;
    static PyGeLine3d kXAxis();
    static PyGeLine3d kYAxis();
    static PyGeLine3d kZAxis();
    void              set1(const AcGePoint3d& pnt, const AcGeVector3d& vec) const;
    void              set2(const AcGePoint3d& pnt1, const AcGePoint3d& pnt2) const;
    static PyGeLine3d  cast(const PyGeEntity3d& src);
    static PyGeLine3d  copycast(const PyGeEntity3d& src);
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
    virtual ~PyGeLineSeg3d() override = default;
    PyGePlane      getBisector() const;
    AcGePoint3d    baryComb(double blendCoeff) const;
    AcGePoint3d    startPoint() const;
    AcGePoint3d    midPoint() const;
    AcGePoint3d    endPoint() const;
    double         length1() const;
    double         length2(double fromParam, double toParam) const;
    double         length3(double fromParam, double toParam, double tol) const;
    void           set1(const AcGePoint3d& pnt, const AcGeVector3d& vec) const;
    void           set2(const AcGePoint3d& pnt1, const AcGePoint3d& pnt2) const;
    static PyGeLineSeg3d  cast(const PyGeEntity3d& src);
    static PyGeLineSeg3d  copycast(const PyGeEntity3d& src);
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
    virtual ~PyGeRay3d() override = default;
    void   set1(const AcGePoint3d& pnt, const AcGeVector3d& vec) const;
    void   set2(const AcGePoint3d& pnt1, const AcGePoint3d& pnt2) const;
    static PyGeRay3d   cast(const PyGeEntity3d& src);
    static PyGeRay3d   copycast(const PyGeEntity3d& src);
    static std::string className();
public:
    AcGeRay3d* impObj(const std::source_location& src = std::source_location::current()) const;
};

#pragma pack (pop)
