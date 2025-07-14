#pragma once

#include "PyRxObject.h"
#include "PyRxOverrule.h"
#include "dbobjectoverrule.h"
#include "dbentityoverrule.h"

#pragma pack (push, 8)

class PyDbObjectId;
class PyDbObject;
class PyDbIdMapping;
class PyDbDimension;
class PyDbDimStyleTableRecord;
class PyDbObjectOverrule;
class PyDbEntity;

//-----------------------------------------------------------------------------------------
//PyDbObjectOverrule
void makePyDbObjectOverruleWrapper();

class PyDbObjectOverrule : public PyRxOverrule, public AcDbObjectOverrule, public boost::python::wrapper<PyDbObjectOverrule>
{
public:
    PyDbObjectOverrule();
    virtual ~PyDbObjectOverrule() override = default;

    virtual bool			    isApplicable(const AcRxObject* pOverruledSubject) const override;
    virtual Acad::ErrorStatus   open(AcDbObject* pSubject, AcDb::OpenMode mode) override;
    virtual Acad::ErrorStatus   close(AcDbObject* pSubject) override;
    virtual Acad::ErrorStatus   cancel(AcDbObject* pSubject) override;
    virtual Acad::ErrorStatus   erase(AcDbObject* pSubject, Adesk::Boolean erasing) override;
    virtual Acad::ErrorStatus   deepClone(const AcDbObject* pSubject, AcDbObject* pOwnerObject, AcDbObject*& pClonedObject, AcDbIdMapping& idMap, Adesk::Boolean isPrimary) override;
    virtual Acad::ErrorStatus   wblockClone(const AcDbObject* pSubject, AcRxObject* pOwnerObject, AcDbObject*& pClonedObject, AcDbIdMapping& idMap, Adesk::Boolean isPrimary) override;

    bool			    isApplicableWr(const PyRxObject& pOverruledSubject) const;
    Acad::ErrorStatus   openWr(PyDbObject& pSubject, AcDb::OpenMode mode);
    Acad::ErrorStatus   closeWr(PyDbObject& pSubject);
    Acad::ErrorStatus   cancelWr(PyDbObject& pSubject);
    Acad::ErrorStatus   eraseWr(PyDbObject& pSubject, Adesk::Boolean erasing);
    Acad::ErrorStatus   deepCloneWr(const AcDbObject* pSubject, AcDbObject* pOwnerObject, AcDbObject*& pClonedObject, AcDbIdMapping& idMap, Adesk::Boolean isPrimary);
    Acad::ErrorStatus   wblockCloneWr(const AcDbObject* pSubject, AcRxObject* pOwnerObject, AcDbObject*& pClonedObject, AcDbIdMapping& idMap, Adesk::Boolean isPrimary);

    Acad::ErrorStatus   baseOpen(PyDbObject& pSubject, AcDb::OpenMode mode);
    Acad::ErrorStatus   baseClose(PyDbObject& pSubject);
    Acad::ErrorStatus   baseCancel(PyDbObject& pSubject);
    Acad::ErrorStatus   baseErase(PyDbObject& pSubject, Adesk::Boolean erasing);

    PyDbObject          baseDeepClone(const PyDbObject& pSubject, PyDbObject& pOwnerObject, PyDbIdMapping& idMap, Adesk::Boolean isPrimary);
    PyDbObject          baseWblockClone(const PyDbObject& pSubject, PyRxObject& pOwnerObject, PyDbIdMapping& idMap, Adesk::Boolean isPrimary);

    static std::string  className();
    static PyRxClass    desc();

public:
    AcDbObjectOverrule* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    mutable bool reg_isApplicable = true;
    mutable bool reg_open = true;
    mutable bool reg_close = true;
    mutable bool reg_cancel = true;
    mutable bool reg_erase = true;
    mutable bool reg_deepClone = true;
    mutable bool reg_wblockClone = true;
};

//-----------------------------------------------------------------------------------------
//PyDbOsnapOverrule
void makePyDbOsnapOverruleWrapper();

class PyDbOsnapOverrule : public PyRxOverrule, public AcDbOsnapOverrule, public boost::python::wrapper<PyDbOsnapOverrule>
{
public:
    PyDbOsnapOverrule();
    virtual ~PyDbOsnapOverrule() override = default;

    virtual bool		      isApplicable(const AcRxObject* pOverruledSubject) const override;
    virtual bool              isContentSnappable(const AcDbEntity* pSubject) override;

    virtual Acad::ErrorStatus getOsnapPoints(
        const AcDbEntity* pSubject,
        AcDb::OsnapMode     osnapMode,
        Adesk::GsMarker     gsSelectionMark,
        const AcGePoint3d& pickPoint,
        const AcGePoint3d& lastPoint,
        const AcGeMatrix3d& viewXform,
        AcGePoint3dArray& snapPoints,
        AcDbIntArray& geomIds) override;

    virtual Acad::ErrorStatus getOsnapPoints(
        const AcDbEntity* pSubject,
        AcDb::OsnapMode     osnapMode,
        Adesk::GsMarker     gsSelectionMark,
        const AcGePoint3d& pickPoint,
        const AcGePoint3d& lastPoint,
        const AcGeMatrix3d& viewXform,
        AcGePoint3dArray& snapPoints,
        AcDbIntArray& geomIds,
        const AcGeMatrix3d& insertionMat)override;

    bool			    isApplicableWr(const PyRxObject& pOverruledSubject) const;
    bool                isContentSnappableWr(const PyDbEntity& pSubject);
    bool                baseIsContentSnappable(const PyDbEntity& pSubject);

    boost::python::tuple   getOsnapPointsWr(
        PyDbEntity& pSubject,
        AcDb::OsnapMode osnapMode,
        Adesk::GsMarker gsSelectionMark,
        const AcGePoint3d& pickPoint,
        const AcGePoint3d& lastPoint,
        const AcGeMatrix3d& viewXform);

    boost::python::tuple getOsnapPointsXWr(
        PyDbEntity& pSubject,
        AcDb::OsnapMode osnapMode,
        Adesk::GsMarker gsSelectionMark,
        const AcGePoint3d& pickPoint,
        const AcGePoint3d& lastPoint,
        const AcGeMatrix3d& viewXform,
        const AcGeMatrix3d& insertionMat);

    boost::python::tuple  baseGetOsnapPoints(
        PyDbEntity& pSubject,
        AcDb::OsnapMode     osnapMode,
        Adesk::GsMarker     gsSelectionMark,
        const AcGePoint3d& pickPoint,
        const AcGePoint3d& lastPoint,
        const AcGeMatrix3d& viewXform);

    boost::python::tuple   baseGetOsnapPointsX(
        PyDbEntity& pSubject,
        AcDb::OsnapMode     osnapMode,
        Adesk::GsMarker     gsSelectionMark,
        const AcGePoint3d& pickPoint,
        const AcGePoint3d& lastPoint,
        const AcGeMatrix3d& viewXform,
        const AcGeMatrix3d& insertionMat);


    static std::string  className();
    static PyRxClass    desc();
public:
    AcDbOsnapOverrule* impObj(const std::source_location& src = std::source_location::current()) const;

public:
    mutable bool reg_isApplicable = true;
    mutable bool reg_isContentSnappable = true;
    mutable bool reg_getOsnapPoints = true;
    mutable bool reg_getOsnapPointsXform = true;
};

#pragma pack (pop)
