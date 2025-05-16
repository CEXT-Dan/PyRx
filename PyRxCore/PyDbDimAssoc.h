#pragma once
#include "PyDbObject.h"
#include "dbdimassoc.h"
#include "dbdimptref.h"

#pragma pack (push, 8)
class PyDbObjectId;
class PyDbIdMapping;
class PyDbPointRef;
class PyDbOsnapPointRef;

//-------------------------------------------------------------------------------------------------------------
//PyDbDimAssoc
void makePyDbDimAssocWrapper();


class PyDbDimAssoc : public PyDbObject
{
public:

    PyDbDimAssoc();
    PyDbDimAssoc(const PyDbObjectId& id);
    PyDbDimAssoc(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbDimAssoc(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    PyDbDimAssoc(AcDbDimAssoc* ptr, bool autoDelete);
    virtual ~PyDbDimAssoc() override = default;
    PyDbObjectId            dimObjId() const;
    void                    setDimObjId(const PyDbObjectId& dimId) const;
    void                    setAssocFlag1(int ptType, bool value) const;
    void                    setAssocFlag2(int assocFlg) const;
    bool                    assocFlag2(int ptType) const;
    int                     assocFlag1(void) const;
    void                    setPointRef(int ptType, PyDbPointRef& ptRef) const;
    PyDbPointRef            pointRef(int ptType) const;
    PyDbOsnapPointRef       osnapPointRef(int ptType) const;
    void                    setRotatedDimType(AcDbDimAssoc::RotatedDimType dimType) const;
    AcDbDimAssoc::RotatedDimType rotatedDimType() const;
    void                    addToPointRefReactor() const;
    void                    addToDimensionReactor1() const;
    void                    addToDimensionReactor2(bool isAdd) const;
    void                    removePointRef(int ptType) const;
    void                    updateDimension1() const;
    void                    updateDimension2(bool update) const;
    void                    updateDimension3(bool update, bool skipReactors) const;
    void                    removeAssociativity1() const;
    void                    removeAssociativity2(bool force) const;
    bool                    isTransSpatial() const;
    void                    setTransSpatial(bool value) const;
    void                    startCmdWatcher() const;
    void                    startOopsWatcher1() const;
    void                    startOopsWatcher2(bool bAddAll) const;
    void                    removeOopsWatcher(void) const;
    void                    restoreAssocFromOopsWatcher(void) const;
    bool                    hasOopsWatcher(void) const;
    PyDbObjectId            post1(const PyDbObjectId& dimId) const;
    PyDbObjectId            post2(const PyDbObjectId& dimId, bool isActive) const;
    boost::python::list     getDimAssocGeomIds() const;
    bool                    isAllGeomErased() const;
    void                    swapReferences(const PyDbIdMapping& idMap) const;
    void                    updateFillet(const boost::python::list& ids) const;
    void                    updateAssociativity(const boost::python::list& ids) const;
    void                    updateXrefSubentPath() const;
    void                    updateSubentPath(PyDbIdMapping& idMap) const;
    void                    updateDueToMirror(bool wasInMirror) const;

    static PyRxClass      desc();
    static std::string    className();
    static PyDbDimAssoc   cloneFrom(const PyRxObject& src);
    static PyDbDimAssoc   cast(const PyRxObject& src);
public:
    AcDbDimAssoc* impObj(const std::source_location& src = std::source_location::current()) const;
};
#pragma pack (pop)