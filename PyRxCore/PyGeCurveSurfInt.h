#pragma once
#include "PyGeEntity3d.h"

#pragma pack (push, 8)

class PyGeCurve3d;
class PyGeSurface;
class PyGePointOnCurve3d;
class PyGePointOnSurface;


void makePyGeCurveSurfIntWrapper();
class PyGeCurveSurfInt : public PyGeEntity3d
{
#if !defined(_BRXTARGET260)
public:
    PyGeCurveSurfInt();
    PyGeCurveSurfInt(const AcGeCurveSurfInt& src);
    PyGeCurveSurfInt(const PyGeCurve3d& crv, const PyGeSurface& srf);
    PyGeCurveSurfInt(const PyGeCurve3d& crv, const PyGeSurface& srf, const AcGeTol& tol);
    PyGeCurveSurfInt(AcGeEntity3d* pEnt);
    virtual ~PyGeCurveSurfInt() override = default;

    PyGeCurve3d             curve() const;
    PyGeSurface             surface() const;
    AcGeTol                 tolerance() const;
    int                     numIntPoints() const;
    AcGePoint3d             intPoint(int intNum) const;

    boost::python::tuple    getIntParams(int intNum) const;
    PyGePointOnCurve3d      getPointOnCurve(int intNum) const;
    PyGePointOnSurface      getPointOnSurface(int intNum) const;
    boost::python::tuple    getIntConfigs(int intNum) const;

    void                    set1(const PyGeCurve3d& cvr, const PyGeSurface& srf) const;
    void                    set2(const PyGeCurve3d& cvr, const PyGeSurface& srf, const AcGeTol& tol) const;

    static PyGeCurveSurfInt cast(const PyGeEntity3d& src);
    static PyGeCurveSurfInt copycast(const PyGeEntity3d& src);
    static std::string className();
public:
    AcGeCurveSurfInt* impObj(const std::source_location& src = std::source_location::current()) const;
#endif

};

#pragma pack (pop)

