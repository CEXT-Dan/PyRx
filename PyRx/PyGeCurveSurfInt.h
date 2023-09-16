#pragma once
#include "PyGeEntity3d.h"

class PyGeCurve3d;
class PyGeSurface;

void makePyGeCurveSurfIntWrapper();
class PyGeCurveSurfInt : public PyGeEntity3d
{
public:
    PyGeCurveSurfInt();
    PyGeCurveSurfInt(const AcGeCurveSurfInt& src);
    PyGeCurveSurfInt(const PyGeCurve3d& crv, const PyGeSurface& srf);
    PyGeCurveSurfInt(const PyGeCurve3d& crv, const PyGeSurface& srf, const AcGeTol& tol);
    PyGeCurveSurfInt(AcGeEntity3d* pEnt);

    PyGeCurve3d             curve() const;
    PyGeSurface             surface() const;
    AcGeTol                 tolerance() const;
    int                     numIntPoints() const;
    AcGePoint3d             intPoint(int intNum) const;

    boost::python::tuple    getIntParams(int intNum) const;
    boost::python::tuple    getPointOnCurve(int intNum) const;
    boost::python::tuple    getPointOnSurface(int intNum) const;
    boost::python::tuple    getIntConfigs(int intNum) const;

    void                    set1(const PyGeCurve3d& cvr, const PyGeSurface& srf);
    void                    set2(const PyGeCurve3d& cvr, const PyGeSurface& srf, const AcGeTol& tol);

    static PyGeCurveSurfInt copycast(const PyGeEntity3d& src);
    static std::string className();
public:
    AcGeCurveSurfInt* impObj(const std::source_location& src = std::source_location::current()) const;
};

