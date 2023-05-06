#pragma once

#include "PyGiDrawable.h"


class PyDbObjectId;
class PyDbDatabase;

void makeAcDbObjectWrapper();
//---------------------------------------------------------------------------------------- -
//PyDbObject
class PyDbObject : public PyGiDrawable
{
public:
    PyDbObject(AcDbObject* ptr, bool autoDelete);
    PyDbObject(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbObject() override;

    PyDbObjectId objectId() const;
    PyDbObjectId ownerId() const;
    virtual Acad::ErrorStatus setOwnerId(const PyDbObjectId& objId);

    PyDbDatabase database() const;

    Acad::ErrorStatus createExtensionDictionary();
    PyDbObjectId extensionDictionary() const;
    Acad::ErrorStatus releaseExtensionDictionary();

    Acad::ErrorStatus close();

    Acad::ErrorStatus upgradeOpen();
    Acad::ErrorStatus upgradeFromNotify(Adesk::Boolean& wasWritable);
    Acad::ErrorStatus downgradeOpen();
    Acad::ErrorStatus downgradeToNotify(Adesk::Boolean wasWritable);

    Acad::ErrorStatus cancel();
    Acad::ErrorStatus erase();

    Acad::ErrorStatus handOverTo(PyDbObject& newObject, Adesk::Boolean keepXData, Adesk::Boolean keepExtDict);
    Acad::ErrorStatus swapIdWith(PyDbObjectId& otherId,Adesk::Boolean swapXdata, Adesk::Boolean swapExtDict);


    virtual Acad::ErrorStatus setXData(const boost::python::list& xdata);
    virtual boost::python::list xData(const std::string& regappName) const;
    Acad::ErrorStatus xDataTransformBy(const AcGeMatrix3d& xform);

    Adesk::Boolean isEraseStatusToggled() const;
    Adesk::Boolean isErased() const;
    Adesk::Boolean isReadEnabled() const;
    Adesk::Boolean isWriteEnabled() const;
    Adesk::Boolean isNotifyEnabled() const;
    Adesk::Boolean isModified() const;
    Adesk::Boolean isModifiedXData() const;
    Adesk::Boolean isModifiedGraphics() const;
    Adesk::Boolean isNewObject() const;
    Adesk::Boolean isNotifying() const;
    Adesk::Boolean isUndoing() const;
    Adesk::Boolean isCancelling() const;
    Adesk::Boolean isReallyClosing() const;
    Adesk::Boolean isTransactionResident() const;
    Adesk::Boolean isAProxy() const;


    void assertReadEnabled() const;
    void assertWriteEnabled();
    void assertNotifyEnabled() const;

    bool isUndoRecordingDisabled() const;
    void disableUndoRecording(Adesk::Boolean disable);

    Acad::ErrorStatus addPersistentReactor(const PyDbObjectId& objId);
    Acad::ErrorStatus removePersistentReactor(const PyDbObjectId& objId);

    bool hasPersistentReactor(const PyDbObjectId& objId) const;

    static std::string className();

public:
    AcDbObject* impObj(const std::source_location& src = std::source_location::current()) const;
};
