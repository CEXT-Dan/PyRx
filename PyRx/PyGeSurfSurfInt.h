#pragma once
#include "PyGeEntity3d.h"

class PyGeSurface;
class PyGeCurve2d;
class PyGeCurve3d;

void makePyGeSurfSurfIntWrapper();

class PyGeSurfSurfInt :public PyGeEntity3d
{
public:
    PyGeSurfSurfInt();
    PyGeSurfSurfInt(const PyGeSurface& srf1, const PyGeSurface& srf2);
    PyGeSurfSurfInt(const PyGeSurface& srf1,  const PyGeSurface& srf2, const AcGeTol& tol);
    PyGeSurfSurfInt(AcGeSurfSurfInt* pEnt, bool autoDelete = false);
    PyGeSurface          surface1() const;
    PyGeSurface          surface2() const;
    AcGeTol              tolerance() const;
    int                  numResults();

    PyGeCurve3d          intCurve(int intNum, Adesk::Boolean isExternal) const;
    PyGeCurve2d          intParamCurve(int num, Adesk::Boolean isExternal, Adesk::Boolean isFirst) const;
    AcGePoint3d          intPoint(int intNum) const;
    boost::python::tuple getIntPointParams(int intNum) const;
    boost::python::tuple getIntConfigs(int intNum) const;

    int		             getDimension(int intNum) const;
    int                  getType(int intNum) const;
    void                 set1(const PyGeSurface& srf1, const PyGeSurface& srf2);
    void                 set2(const PyGeSurface& srf1, const PyGeSurface& srf2, const AcGeTol& tol);

    static std::string className();
public:
    AcGeSurfSurfInt* impObj(const std::source_location& src = std::source_location::current()) const;
};

