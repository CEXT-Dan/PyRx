#pragma once
#include "PyDbSymbolTableRecord.h"
#include "PyDbObjectId.h"
class PyDbEntity;
class PyDbBlockBegin;
class PyDbBlockEnd;
void makeAcDbBlockTableRecordWrapper();
class PyDbBlockTableRecord : public PyDbSymbolTableRecord
{
public:
    PyDbBlockTableRecord(AcDbBlockTableRecord* ptr, bool autoDelete);
    PyDbBlockTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbBlockTableRecord() override = default;
    PyDbObjectId        appendAcDbEntity(const PyDbEntity& ent);
    boost::python::list objectIds();
    std::string         comments();
    Acad::ErrorStatus   setComments(const std::string& pString);
    std::string         pathName();
    Acad::ErrorStatus   setPathName(const std::string& pString);
    AcGePoint3d         origin() const;
    Acad::ErrorStatus   setOrigin(const AcGePoint3d& pt);
    Acad::ErrorStatus   openBlockBegin(PyDbBlockBegin& pBlockBegin, AcDb::OpenMode openMode);
    Acad::ErrorStatus   openBlockEnd(PyDbBlockEnd& pBlockBegin, AcDb::OpenMode openMode);
    bool                hasAttributeDefinitions() const;
    bool                isAnonymous() const;
    bool                isFromExternalReference() const;
    bool                isFromOverlayReference() const;
    Acad::ErrorStatus   setIsFromOverlayReference(bool bIsOverlay);
    bool                isLayout() const;
    PyDbObjectId        getLayoutId() const;
    Acad::ErrorStatus   setLayoutId(const PyDbObjectId& id);
    boost::python::list getBlockReferenceIds1();
    boost::python::list getBlockReferenceIds2(bool bDirectOnly, bool bForceValidity);
    boost::python::list getErasedBlockReferenceIds();
    PyDbDatabase        xrefDatabase(bool incUnres) const;
    bool                isUnloaded() const;
    Acad::ErrorStatus   setIsUnloaded(bool isUnloaded);
    AcDb::XrefStatus    xrefStatus() const;
    virtual Acad::ErrorStatus assumeOwnershipOf(const  boost::python::list& entitiesToMove);
    AcDbBlockTableRecord::BlockScaling blockScaling() const;
    Acad::ErrorStatus   setBlockScaling(AcDbBlockTableRecord::BlockScaling blockScaling);
    Acad::ErrorStatus   setExplodable(bool bExplodable);
    bool                explodable() const;
    Acad::ErrorStatus   setBlockInsertUnits(AcDb::UnitsValue insunits);
    AcDb::UnitsValue    blockInsertUnits() const;
    int                 postProcessAnnotativeBTR(bool bqueryOnly, bool bScale);
    Acad::ErrorStatus   addAnnoScalestoBlkRefs(bool bScale);
    static std::string  className();
    static PyRxClass    desc();
    static PyDbBlockTableRecord	cloneFrom(const PyRxObject& src);
    static PyDbBlockTableRecord cast(const PyRxObject& src);
public:
    AcDbBlockTableRecord* impObj(const std::source_location& src = std::source_location::current()) const;
};
