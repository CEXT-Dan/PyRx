#pragma once
#include "PyGeEntity3d.h"

#pragma pack (push, 8)

class PyGeSurface;
class PyGeCurve2d;
class PyGeCurve3d;

void makePyGeSurfSurfIntWrapper();

class PyGeSurfSurfInt :public PyGeEntity3d
{
#if !defined(_BRXTARGET260)
public:
    PyGeSurfSurfInt();
    PyGeSurfSurfInt(const PyGeSurface& srf1, const PyGeSurface& srf2);
    PyGeSurfSurfInt(const PyGeSurface& srf1, const PyGeSurface& srf2, const AcGeTol& tol);
    PyGeSurfSurfInt(AcGeEntity3d* pEnt);
    PyGeSurfSurfInt(AcGeSurfSurfInt* pEnt);
    virtual ~PyGeSurfSurfInt() override = default;
    PyGeSurface          surface1() const;
    PyGeSurface          surface2() const;
    AcGeTol              tolerance() const;
    int                  numResults() const;

    PyGeCurve3d          intCurve(int intNum, Adesk::Boolean isExternal) const;
    PyGeCurve2d          intParamCurve(int num, Adesk::Boolean isExternal, Adesk::Boolean isFirst) const;
    AcGePoint3d          intPoint(int intNum) const;
    boost::python::tuple getIntPointParams(int intNum) const;
    boost::python::tuple getIntConfigs(int intNum) const;

    int		             getDimension(int intNum) const;
    int                  getType(int intNum) const;
    void                 set1(const PyGeSurface& srf1, const PyGeSurface& srf2) const;
    void                 set2(const PyGeSurface& srf1, const PyGeSurface& srf2, const AcGeTol& tol) const;

    static PyGeSurfSurfInt cast(const PyGeEntity3d& src);
    static PyGeSurfSurfInt copycast(const PyGeEntity3d& src);
    static std::string className();
public:
    AcGeSurfSurfInt* impObj(const std::source_location& src = std::source_location::current()) const;
#endif
};

#pragma pack (pop)
