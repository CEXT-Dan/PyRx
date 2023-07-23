#pragma once
#include "PyRxObject.h"

class PyDbEntity;
class AcDbJoinEntityPE;

//-----------------------------------------------------------------------------------------
//PyDbJoinEntityPE
void makePyDbJoinEntityPEWrapper();

class PyDbJoinEntityPE : public PyRxObject
{
public:
    PyDbJoinEntityPE(const PyRxObject& PE);
    PyDbJoinEntityPE(AcDbJoinEntityPE* ptr, bool autoDelete);
    virtual ~PyDbJoinEntityPE() override = default;
    bool joinEntity1(PyDbEntity& pPrimaryEntity, PyDbEntity& pSecondaryEntity) const;
    bool joinEntity2(PyDbEntity& pPrimaryEntity, PyDbEntity& pSecondaryEntity, const AcGeTol& tol) const;
    boost::python::list joinEntities1(PyDbEntity& pPrimaryEntity, const boost::python::list& otherEntities) const;
    boost::python::list joinEntities2(PyDbEntity& pPrimaryEntity, const boost::python::list& otherEntities, const AcGeTol& tol) const;
    static PyRxClass    desc();
    static std::string  className();

public:
    AcDbJoinEntityPE* impObj(const std::source_location& src = std::source_location::current()) const;
};

