#pragma once

#include "PyGePlanarEnt.h"

class PyGeLinearEnt3d;
class PyGeBoundedPlane;

//-----------------------------------------------------------------------------------------
//PyGePlane wrapper
void makePyGePlaneWrapper();
class PyGePlane : public PyGePlanarEnt
{
public:
    PyGePlane();
    PyGePlane(AcGePlane* pEnt);
    PyGePlane(const AcGePlane& ent);
    PyGePlane(const AcGePoint3d& origin, const AcGeVector3d& normal);
    PyGePlane(const AcGePoint3d& pntU, const AcGePoint3d& org, const AcGePoint3d& pntV);
    PyGePlane(const AcGePoint3d& org, const AcGeVector3d& uAxis, const AcGeVector3d& vAxis);
    PyGePlane(double a, double b, double c, double d);
    PyGePlane(AcGeEntity3d* pEnt);
    ~PyGePlane() = default;
    double     signedDistanceTo(const AcGePoint3d& pnt) const;
    boost::python::tuple intersectWith1(const PyGeLinearEnt3d& linEnt) const;
    boost::python::tuple intersectWith2(const PyGeLinearEnt3d& linEnt, const AcGeTol& tol) const;
    boost::python::tuple intersectWith3(const PyGePlane& otherPln) const;
    boost::python::tuple intersectWith4(const PyGePlane& otherPln, const AcGeTol& tol) const;
    boost::python::tuple intersectWith5(const PyGeBoundedPlane& bndPln) const;
    boost::python::tuple intersectWith6(const PyGeBoundedPlane& bndPln, const AcGeTol& tol) const;
    void set1(const AcGePoint3d& pnt, const AcGeVector3d& normal);
    void set2(const AcGePoint3d& pntU, const AcGePoint3d& org, const AcGePoint3d& pntV);
    void set3(double a, double b, double c, double d);
    void set4(const AcGePoint3d& org, const AcGeVector3d& uAxis, const AcGeVector3d& vAxis);

    static std::string className();
public:
    AcGePlane* impObj(const std::source_location& src = std::source_location::current()) const;
};


//-----------------------------------------------------------------------------------------
//PyGeBoundedPlane wrapper
void makePyGeBoundedPlaneWrapper();
class PyGeBoundedPlane : public PyGePlanarEnt
{
public:
    PyGeBoundedPlane();
    PyGeBoundedPlane(AcGeBoundedPlane* pEnt);
    PyGeBoundedPlane(const AcGeBoundedPlane& plane);
    PyGeBoundedPlane(const AcGePoint3d& origin, const AcGeVector3d& uVec, const AcGeVector3d& vVec);
    PyGeBoundedPlane(const AcGePoint3d& p1, const AcGePoint3d& origin, const AcGePoint3d& p2);
    boost::python::tuple intersectWith1(const PyGeLinearEnt3d& linEnt) const;
    boost::python::tuple intersectWith2(const PyGeLinearEnt3d& linEnt, const AcGeTol& tol) const;
    boost::python::tuple intersectWith3(const PyGePlane& otherPln) const;
    boost::python::tuple intersectWith4(const PyGePlane& otherPln, const AcGeTol& tol) const;
    boost::python::tuple intersectWith5(const PyGeBoundedPlane& bndPln) const;
    boost::python::tuple intersectWith6(const PyGeBoundedPlane& bndPln, const AcGeTol& tol) const;
    void set1(const AcGePoint3d& origin, const AcGeVector3d& uVec,const AcGeVector3d& vVec);
    void set2(const AcGePoint3d& p1, const AcGePoint3d& origin, const AcGePoint3d& p2);
    static std::string className();
public:
    AcGeBoundedPlane* impObj(const std::source_location& src = std::source_location::current()) const;
};