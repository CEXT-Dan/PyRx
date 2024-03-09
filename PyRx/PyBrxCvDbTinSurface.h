#pragma once

#include "BrxCvDbTinSurface.h"

class PyDbObjectId;
//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceConstraint
void makePyBrxCvDbTinSurfaceConstraintWrapper();

class PyBrxCvDbTinSurfaceConstraint
{
public:
    PyBrxCvDbTinSurfaceConstraint();
    PyBrxCvDbTinSurfaceConstraint(BrxCvDbTinSurfaceConstraint::ETinConstraintType type);
    PyBrxCvDbTinSurfaceConstraint(BrxCvDbTinSurfaceConstraint* ptr);
    virtual ~PyBrxCvDbTinSurfaceConstraint() = default;

    BrxCvDbTinSurfaceConstraint::ETinConstraintType constraintType() const;
    void                setData1(Adesk::UInt64 id, const boost::python::list& points);
    void                setData2(const PyDbObjectId& id, double midOrdinateDist);
    boost::python::list data() const;
    Adesk::UInt64       id() const;
    void                setMidOrdinateDistance(double midOrdinateDist);
    double              midOrdinateDistance() const;
    void                setIsDbResident(bool isResident);
    bool                isDbResident() const;

    static std::string  className();
public:
    inline BrxCvDbTinSurfaceConstraint* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<BrxCvDbTinSurfaceConstraint> m_pyImp;
};

//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceBreakline
void makePyBrxCvDbTinSurfaceBreaklineWrapper();

class PyBrxCvDbTinSurfaceBreakline : public PyBrxCvDbTinSurfaceConstraint
{
public:
    PyBrxCvDbTinSurfaceBreakline(BrxCvDbTinSurfaceBreakline::ETinBreaklineType type);
    BrxCvDbTinSurfaceBreakline::ETinIntersectionElevation intersectionElevation() const;
    void setIntersectionElevation(const BrxCvDbTinSurfaceBreakline::ETinIntersectionElevation elevationType);
    static std::string  className();
public:
    inline BrxCvDbTinSurfaceBreakline* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceWall
void makePyBrxCvDbTinSurfaceWallWrapper();

class PyBrxCvDbTinSurfaceWall : public PyBrxCvDbTinSurfaceConstraint
{
public:
    PyBrxCvDbTinSurfaceWall(BrxCvDbTinSurfaceWall::ETinWallType wallType);
    virtual ~PyBrxCvDbTinSurfaceWall() override = default;
    BrxCvDbTinSurfaceWall::ETinWallType wallType() const;
    BrxCvDbTinSurfaceWall::ETinWallSide wallSide() const;
    double              height() const;
    void                setHeight(double height);
    void                setWallSide(BrxCvDbTinSurfaceWall::ETinWallSide side);
    static std::string  className();
public:
    inline BrxCvDbTinSurfaceWall* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyBrxCvDbTinSurfaceBoundary
void makePyBrxCvDbTinSurfaceBoundaryWrapper();

class PyBrxCvDbTinSurfaceBoundary : public PyBrxCvDbTinSurfaceConstraint
{
public:
    PyBrxCvDbTinSurfaceBoundary(BrxCvDbTinSurfaceBoundary::ETinBoundaryType boundaryType);
    virtual ~PyBrxCvDbTinSurfaceBoundary() override = default;
    BrxCvDbTinSurfaceBoundary::ETinBoundaryType boundaryType() const;
    static std::string  className();
public:
    inline BrxCvDbTinSurfaceBoundary* impObj(const std::source_location& src = std::source_location::current()) const;
};
