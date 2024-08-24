#pragma once
#include "PyRxObject.h"

#if defined (_ARXTARGET)
#include "AcDbAssocPersSubentIdPE.h"
#endif


#pragma pack (push, 8)
class PyDbEntity;
class AcDbJoinEntityPE;
class PyGeEntity3d;
class PyDbSubentId;

//-----------------------------------------------------------------------------------------
//PyDbJoinEntityPE
void makePyDbJoinEntityPEWrapper();

#if defined (_ARXTARGET) || defined (_BRXTARGET)
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
#endif

//-----------------------------------------------------------------------------------------
//PyDbAssocPersSubentIdPE
void makePyDbAssocPersSubentIdPEWrapper();

#if defined (_ARXTARGET)
class PyDbAssocPersSubentIdPE : public PyRxObject
{
public:
    PyDbAssocPersSubentIdPE(const PyRxObject& PE);
    PyDbAssocPersSubentIdPE(AcDbAssocPersSubentIdPE* ptr, bool autoDelete);
    virtual ~PyDbAssocPersSubentIdPE() override = default;
    boost::python::list getAllSubentities(const PyDbEntity& pEntity, AcDb::SubentType subentType);
    PyGeEntity3d        getSubentityGeometry(const PyDbEntity& pEntity,const PyDbSubentId& subentId);
    static PyRxClass    desc();
    static std::string  className();

public:
    AcDbAssocPersSubentIdPE* impObj(const std::source_location& src = std::source_location::current()) const;
};
#endif

#pragma pack (pop)


//AcDbAnnotativeObjectPE TODO:

//OPMPerInstancePropertyExtension