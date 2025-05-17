#pragma once
#include "PyRxObject.h"

#pragma pack (push, 8)
class PyDbEntity;
class AcDbJoinEntityPE;
class PyGeEntity3d;
class PyDbSubentId;
class PyDbDatabase;
class PyGeCurve3d;
class PyGeSurface;
class AcDbAssocPersSubentIdPE;

//TODO:
//AcDbAnnotativeObjectPE
//OPMPerInstancePropertyExtension

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

class PyDbAssocPersSubentIdPE : public PyRxObject
{
public:
    PyDbAssocPersSubentIdPE(const PyRxObject& PE);
    PyDbAssocPersSubentIdPE(AcDbAssocPersSubentIdPE* ptr, bool autoDelete);
    virtual ~PyDbAssocPersSubentIdPE() override = default;
    boost::python::list  getAllSubentities1(const PyDbEntity& pEntity, AcDb::SubentType subentType) const;
    boost::python::list  getAllSubentities2(const PyDbEntity& pEntity, PyRxClass& subentType) const;

    boost::python::tuple getEdgeVertexSubentities(const PyDbEntity& pEntity, const PyDbSubentId& subentId) const;
    boost::python::tuple getSplineEdgeVertexSubentities(const PyDbEntity& pEntity, const PyDbSubentId& subentId) const;
    PyGeEntity3d         getSubentityGeometry(const PyDbEntity& pEntity, const PyDbSubentId& subentId) const;

    AcGePoint3d          getVertexSubentityGeometry(const PyDbEntity& pEntity, const PyDbSubentId& subentId) const;
    PyGeCurve3d          getEdgeSubentityGeometry(const PyDbEntity& pEntity, const PyDbSubentId& subentId) const;
    PyGeSurface          getFaceSubentityGeometry(const PyDbEntity& pEntity, const PyDbSubentId& subentId) const;

    static PyRxClass     desc();
    static std::string   className();

public:
    AcDbAssocPersSubentIdPE* impObj(const std::source_location& src = std::source_location::current()) const;
};
#pragma pack (pop)
