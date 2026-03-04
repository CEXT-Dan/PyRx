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

//-----------------------------------------------------------------------------------------
//PyDbGripOverrule
void makePyDbGripOverruleWrapper();

class PyDbGripOverrule : public PyRxOverrule, public AcDbGripOverrule, public boost::python::wrapper<PyDbGripOverrule>
{
public:
    PyDbGripOverrule();
    virtual ~PyDbGripOverrule() override = default;

    virtual bool		        isApplicable(const AcRxObject* pOverruledSubject) const override;

    virtual Acad::ErrorStatus   getGripPoints(const AcDbEntity* pSubject, AcGePoint3dArray& gripPoints, AcDbIntArray& osnapModes, AcDbIntArray& geomIds) override;
    virtual Acad::ErrorStatus   moveGripPointsAt(AcDbEntity* pSubject, const AcDbIntArray& indices, const AcGeVector3d& offset) override;
    virtual Acad::ErrorStatus   getStretchPoints(const AcDbEntity* pSubject, AcGePoint3dArray& stretchPoints) override;
    virtual Acad::ErrorStatus   moveStretchPointsAt(AcDbEntity* pSubject, const AcDbIntArray& indices, const AcGeVector3d& offset) override;
    virtual void                gripStatus(AcDbEntity* pSubject, const AcDb::GripStat status) override;

    bool			    isApplicableWr(const PyRxObject& pOverruledSubject) const;
    Acad::ErrorStatus   getGripPointsWr(const PyDbEntity& pSubject, boost::python::list& gripPoints, boost::python::list& osnapModes, boost::python::list& geomIds);
    Acad::ErrorStatus   moveGripPointsAtsWr(const PyDbEntity& pSubject, boost::python::list& indices, const AcGeVector3d& offset);
    Acad::ErrorStatus   getStretchPointsWr(const PyDbEntity& pSubject, boost::python::list& stretchPoints);
    Acad::ErrorStatus   moveStretchPointsAt(const PyDbEntity& pSubject, const boost::python::list& indices, const AcGeVector3d& offset);
    void                gripStatusWr(const PyDbEntity& pSubject, const AcDb::GripStat status);


    static std::string  className();
    static PyRxClass    desc();
public:
    AcDbOsnapOverrule* impObj(const std::source_location& src = std::source_location::current()) const;

public:
    mutable bool reg_isApplicable = true;
    mutable bool reg_getGripPoints = true;
    mutable bool reg_moveGripPointsAt = true;
    mutable bool reg_getStretchPoints = true;
    mutable bool reg_moveStretchPointsAt = true;
};

#pragma pack (pop)
