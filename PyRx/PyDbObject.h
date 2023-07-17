#pragma once
#include "PyGiDrawable.h"
class PyDbObjectId;
class PyDbDatabase;
class PyDbField;
class PyDbHandle;
void makePyDbObjectWrapper();
//---------------------------------------------------------------------------------------- -
//PyDbObject
class PyDbObject : public PyGiDrawable
{
public:
    PyDbObject(AcDbObject* ptr, bool autoDelete);
    PyDbObject(const PyDbObjectId&);
    PyDbObject(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbObject() override;
    PyDbObjectId        objectId() const;
    PyDbObjectId        ownerId() const;
    void                setOwnerId(const PyDbObjectId& objId);
    PyDbDatabase        database() const;
    void                createExtensionDictionary();
    PyDbObjectId        extensionDictionary() const;
    void                releaseExtensionDictionary();
    void                close();
    void                upgradeOpen();
    void                upgradeFromNotify(Adesk::Boolean& wasWritable);
    void                downgradeOpen();
    void                downgradeToNotify(Adesk::Boolean wasWritable);
    void                cancel();
    void                erase1();
    void                erase2(Adesk::Boolean erasing);
    void                handOverTo(PyDbObject& newObject, Adesk::Boolean keepXData, Adesk::Boolean keepExtDict);
    void                swapIdWith(PyDbObjectId& otherId, Adesk::Boolean swapXdata, Adesk::Boolean swapExtDict);
    void                setXData(const boost::python::list& xdata);
    virtual boost::python::list xData(const std::string& regappName) const;
    void                xDataTransformBy(const AcGeMatrix3d& xform);
    Adesk::Boolean      isEraseStatusToggled() const;
    Adesk::Boolean      isErased() const;
    Adesk::Boolean      isReadEnabled() const;
    Adesk::Boolean      isWriteEnabled() const;
    Adesk::Boolean      isNotifyEnabled() const;
    Adesk::Boolean      isModified() const;
    Adesk::Boolean      isModifiedXData() const;
    Adesk::Boolean      isModifiedGraphics() const;
    Adesk::Boolean      isNewObject() const;
    Adesk::Boolean      isNotifying() const;
    Adesk::Boolean      isUndoing() const;
    Adesk::Boolean      isCancelling() const;
    Adesk::Boolean      isReallyClosing() const;
    Adesk::Boolean      isTransactionResident() const;
    Adesk::Boolean      isAProxy() const;
    void                assertReadEnabled() const;
    void                assertWriteEnabled();
    void                assertNotifyEnabled() const;
    bool                isUndoRecordingDisabled() const;
    void                disableUndoRecording(Adesk::Boolean disable);
    void                addPersistentReactor(const PyDbObjectId& objId);
    void                removePersistentReactor(const PyDbObjectId& objId);
    bool                hasPersistentReactor(const PyDbObjectId& objId) const;
    bool                hasFields(void) const;
    PyDbObjectId        getField1();
    PyDbObjectId        getField2(const std::string& propName);
    PyDbObjectId        setField1(PyDbField& pField);
    PyDbObjectId        setField2(const std::string& propName, PyDbField& pField);
    PyDbHandle          getHandle() const;
    void                removeField1(const PyDbObjectId& fieldId);
    void                removeField2(const std::string& propName);
    PyDbObjectId        getFieldDictionary(void) const;
    static PyRxClass    desc();
    static std::string  className();
    static PyDbObject   cloneFrom(const PyRxObject& src);
    static PyDbObject   cast(const PyRxObject& src);
public:
    AcDbObject* impObj(const std::source_location& src = std::source_location::current()) const;
};
