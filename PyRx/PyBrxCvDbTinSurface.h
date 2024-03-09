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

