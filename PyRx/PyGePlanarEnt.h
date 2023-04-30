#pragma once
#include "PyAcGeSurface.h"


class PyGeLineSeg3d;
class PyGeLinearEnt3d;
class PyGeCircArc3d;

//-----------------------------------------------------------------------------------------
//AcGeSurface wrapper
void makeAcGePlanarEntWrapper();
class PyGePlanarEnt : public PyAcGeSurface
{
protected:
    PyGePlanarEnt() = default;
public:
    PyGePlanarEnt(AcGePlanarEnt* pEnt);
    PyGePlanarEnt(AcGeEntity3d* pEnt);
    ~PyGePlanarEnt() = default;

    boost::python::tuple intersectWith1(const PyGeLinearEnt3d& linEnt) const;
    boost::python::tuple intersectWith2(const PyGeLinearEnt3d& linEnt, const AcGeTol& tol) const;

    boost::python::tuple closestPointToLinearEnt1(const PyGeLinearEnt3d& line) const;
    boost::python::tuple closestPointToLinearEnt2(const PyGeLinearEnt3d& line, const AcGeTol& tol) const;

    boost::python::tuple closestPointToPlanarEnt1(const PyGePlanarEnt& line) const;
    boost::python::tuple closestPointToPlanarEnt2(const PyGePlanarEnt& line, const AcGeTol& tol) const;

    Adesk::Boolean isParallelTo1(const PyGeLinearEnt3d& linEnt) const;
    Adesk::Boolean isParallelTo2(const PyGeLinearEnt3d& linEnt, const AcGeTol& tol) const;

    Adesk::Boolean isParallelTo3(const PyGePlanarEnt& otherPlnEnt) const;
    Adesk::Boolean isParallelTo4(const PyGePlanarEnt& otherPlnEnt, const AcGeTol& tol) const;

    Adesk::Boolean isPerpendicularTo1(const PyGeLinearEnt3d& linEnt) const;
    Adesk::Boolean isPerpendicularTo2(const PyGeLinearEnt3d& linEnt, const AcGeTol& tol) const;

    Adesk::Boolean isPerpendicularTo3(const PyGePlanarEnt& linEnt) const;
    Adesk::Boolean isPerpendicularTo4(const PyGePlanarEnt& linEnt, const AcGeTol& tol) const;

    Adesk::Boolean isCoplanarTo1(const PyGePlanarEnt& otherPlnEnt) const;
    Adesk::Boolean isCoplanarTo2(const PyGePlanarEnt& otherPlnEnt, const AcGeTol& tol) const;

    AcGePoint3d    pointOnPlane() const;
    AcGeVector3d   normal() const;

    boost::python::tuple getCoefficients() const;
    boost::python::tuple getCoordSystem() const;

    static std::string className();
public:
    AcGePlanarEnt* impObj() const;
};

