#include "stdafx.h"
#include "PyDbObject.h"
#include "PyDbDatabase.h"
#include "PyDbObjectId.h"
#include "ResultBuffer.h"
#include "PyDbField.h"

using namespace boost::python;

void makeAcDbObjectWrapper()
{
    PyDocString DS("DbObject");
    class_<PyDbObject, bases<PyGiDrawable>>("DbObject", boost::python::no_init)
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>(DS.CLASSARGS({ "id: ObjectId", "mode: OpenMode=kForRead" })))
        .def("objectId", &PyDbObject::objectId, DS.CLASSARGS())
        .def("ownerId", &PyDbObject::ownerId, DS.CLASSARGS())
        .def("setOwnerId", &PyDbObject::setOwnerId, DS.CLASSARGS({ "owner: ObjectId" }))
        .def("database", &PyDbObject::database, DS.CLASSARGS())
#ifdef NEVER
        .def("databaseToUse", &PyDbObject::databaseToUse)
        .def("intendedDatabase", &PyDbObject::intendedDatabase)
        .def("setIntendedDatabase", &PyDbObject::setIntendedDatabase)
#endif
        .def("createExtensionDictionary", &PyDbObject::createExtensionDictionary, DS.CLASSARGS())
        .def("extensionDictionary", &PyDbObject::extensionDictionary, DS.CLASSARGS())
        .def("releaseExtensionDictionary", &PyDbObject::releaseExtensionDictionary, DS.CLASSARGS())
        .def("upgradeOpen", &PyDbObject::upgradeOpen, DS.CLASSARGS())
        .def("upgradeFromNotify", &PyDbObject::upgradeFromNotify, DS.CLASSARGS({ "wasWritable: bool" }))
        .def("downgradeOpen", &PyDbObject::downgradeOpen, DS.CLASSARGS())
        .def("downgradeToNotify", &PyDbObject::downgradeToNotify, DS.CLASSARGS({ "wasWritable: bool" }))
        .def("erase", &PyDbObject::erase1, DS.CLASSARGS())
        .def("erase", &PyDbObject::erase2)
        .def("close", &PyDbObject::close, DS.CLASSARGS())
        .def("cancel", &PyDbObject::cancel, DS.CLASSARGS())
        .def("handOverTo", &PyDbObject::handOverTo, DS.CLASSARGS({ "newObject: DbObject", "keepXData: bool", "keepExtDict: bool" }))
        .def("swapIdWith", &PyDbObject::swapIdWith, DS.CLASSARGS({ "otherId: DbObject", "swapXdata: bool", "swapExtDict: bool" }))
        .def("setXData", &PyDbObject::setXData, DS.CLASSARGS({ "xdata: list" }))
        .def("xData", &PyDbObject::xData, DS.CLASSARGS({ "appname: str" }))
        .def("xDataTransformBy", &PyDbObject::xDataTransformBy, DS.CLASSARGS({ "xform: AcGeMatrix3d" }))
        .def("isEraseStatusToggled", &PyDbObject::isEraseStatusToggled, DS.CLASSARGS())
        .def("isErased", &PyDbObject::isErased, DS.CLASSARGS())
        .def("isReadEnabled", &PyDbObject::isReadEnabled, DS.CLASSARGS())
        .def("isWriteEnabled", &PyDbObject::isWriteEnabled, DS.CLASSARGS())
        .def("isNotifyEnabled", &PyDbObject::isNotifyEnabled, DS.CLASSARGS())
        .def("isModified", &PyDbObject::isModified, DS.CLASSARGS())
        .def("isModifiedXData", &PyDbObject::isModifiedXData, DS.CLASSARGS())
        .def("isModifiedGraphics", &PyDbObject::isModifiedGraphics, DS.CLASSARGS())
        .def("isNewObject", &PyDbObject::isNewObject, DS.CLASSARGS())
        .def("isNotifying", &PyDbObject::isNotifying, DS.CLASSARGS())
        .def("isUndoing", &PyDbObject::isUndoing, DS.CLASSARGS())
        .def("isCancelling", &PyDbObject::isCancelling, DS.CLASSARGS())
        .def("isReallyClosing", &PyDbObject::isReallyClosing, DS.CLASSARGS())
        .def("isTransactionResident", &PyDbObject::isTransactionResident, DS.CLASSARGS())
        .def("isAProxy", &PyDbObject::isAProxy, DS.CLASSARGS())
        .def("assertReadEnabled", &PyDbObject::assertReadEnabled, DS.CLASSARGS())
        .def("assertWriteEnabled", &PyDbObject::assertWriteEnabled, DS.CLASSARGS())
        .def("assertNotifyEnabled", &PyDbObject::assertNotifyEnabled, DS.CLASSARGS())
        .def("isUndoRecordingDisabled", &PyDbObject::isUndoRecordingDisabled, DS.CLASSARGS())
        .def("disableUndoRecording", &PyDbObject::disableUndoRecording, DS.CLASSARGS({ "disable: bool" }))
        .def("addPersistentReactor", &PyDbObject::addPersistentReactor, DS.CLASSARGS({ "id: ObjectId" }))
        .def("removePersistentReactor", &PyDbObject::removePersistentReactor, DS.CLASSARGS({ "id: ObjectId" }))
        .def("hasPersistentReactor", &PyDbObject::hasPersistentReactor, DS.CLASSARGS({ "id: ObjectId" }))
        .def("hasFields", &PyDbObject::hasFields, DS.CLASSARGS())
        .def("getField", &PyDbObject::getField1, DS.CLASSARGS())
        .def("getField", &PyDbObject::getField2)
        .def("setField", &PyDbObject::setField1, DS.CLASSARGS({ "obj: Field" }))
        .def("setField", &PyDbObject::setField2)
        .def("getHandle", &PyDbObject::getHandle, DS.CLASSARGS())
        .def("removeField", &PyDbObject::removeField1, DS.CLASSARGS({ "id: ObjectId" }))
        .def("removeField", &PyDbObject::removeField2)
        .def("getFieldDictionary", &PyDbObject::getFieldDictionary, DS.CLASSARGS())
        .def("desc", &PyDbObject::desc, DS.CLASSARGSSTATIC()).staticmethod("desc")
        .def("className", &PyDbObject::className, DS.CLASSARGSSTATIC()).staticmethod("className")
        .def("cloneFrom", &PyDbObject::cloneFrom, DS.CLASSARGSSTATIC({ "otherObject: RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbObject::cast, DS.CLASSARGSSTATIC({ "otherObject: RxObject" })).staticmethod("cast")
        ;
}

//-----------------------------------------------------------------------------------------
//PyDbObject
PyDbObject::PyDbObject(AcDbObject* ptr, bool autoDelete)
    : PyGiDrawable(ptr, autoDelete, true)
{
}

PyDbObject::PyDbObject(const PyDbObjectId& id)
    : PyDbObject(id, AcDb::OpenMode::kForRead)
{
}

PyDbObject::PyDbObject(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyGiDrawable(nullptr, true, true)
{
    AcDbObject* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbObject>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
}

PyDbObject::~PyDbObject()
{
}

PyDbObjectId PyDbObject::objectId() const
{
    return PyDbObjectId(impObj()->objectId());
}

PyDbObjectId PyDbObject::ownerId() const
{
    return PyDbObjectId(impObj()->ownerId());
}

Acad::ErrorStatus PyDbObject::setOwnerId(const PyDbObjectId& objId)
{
    return impObj()->setOwnerId(objId.m_id);
}

PyDbDatabase PyDbObject::database() const
{
    return PyDbDatabase(impObj()->database());
}

Acad::ErrorStatus PyDbObject::createExtensionDictionary()
{
    return impObj()->createExtensionDictionary();
}

PyDbObjectId PyDbObject::extensionDictionary() const
{
    return PyDbObjectId(impObj()->extensionDictionary());
}

Acad::ErrorStatus PyDbObject::releaseExtensionDictionary()
{
    return impObj()->releaseExtensionDictionary();
}

Acad::ErrorStatus PyDbObject::close()
{
    return impObj()->close();
}

Acad::ErrorStatus PyDbObject::upgradeOpen()
{
    return impObj()->upgradeOpen();
}

Acad::ErrorStatus PyDbObject::upgradeFromNotify(Adesk::Boolean& wasWritable)
{
    return impObj()->upgradeFromNotify(wasWritable);
}

Acad::ErrorStatus PyDbObject::downgradeOpen()
{
    return impObj()->downgradeOpen();
}

Acad::ErrorStatus PyDbObject::downgradeToNotify(Adesk::Boolean wasWritable)
{
    return impObj()->downgradeToNotify(wasWritable);
}

Acad::ErrorStatus PyDbObject::cancel()
{
    return impObj()->cancel();
}

Acad::ErrorStatus PyDbObject::erase1()
{
    return impObj()->erase();
}

Acad::ErrorStatus PyDbObject::erase2(Adesk::Boolean erasing)
{
    return impObj()->erase(erasing);
}

Acad::ErrorStatus PyDbObject::handOverTo(PyDbObject& newObject, Adesk::Boolean keepXData, Adesk::Boolean keepExtDict)
{
    return impObj()->handOverTo(newObject.impObj(), keepXData, keepExtDict);
}

Acad::ErrorStatus PyDbObject::swapIdWith(PyDbObjectId& otherId, Adesk::Boolean swapXdata, Adesk::Boolean swapExtDict)
{
    return impObj()->swapIdWith(otherId.m_id, swapXdata, swapExtDict);
}

Acad::ErrorStatus PyDbObject::setXData(const boost::python::list& xdata)
{
    AcResBufPtr pData(listToResbuf(xdata));
    if (!impObj()->isWriteEnabled())
        return eNotOpenForWrite;
    return impObj()->setXData(pData.get());
}

boost::python::list PyDbObject::xData(const std::string& regappName) const
{
    AcResBufPtr pData(impObj()->xData(utf8_to_wstr(regappName).c_str()));
    return resbufToList(pData.get());
}

Acad::ErrorStatus PyDbObject::xDataTransformBy(const AcGeMatrix3d& xform)
{
    return impObj()->xDataTransformBy(xform);
}

Adesk::Boolean PyDbObject::isEraseStatusToggled() const
{
    return impObj()->isEraseStatusToggled();
}

Adesk::Boolean PyDbObject::isErased() const
{
    return impObj()->isErased();
}

Adesk::Boolean PyDbObject::isReadEnabled() const
{
    return impObj()->isReadEnabled();
}

Adesk::Boolean PyDbObject::isWriteEnabled() const
{
    return impObj()->isWriteEnabled();
}

Adesk::Boolean PyDbObject::isNotifyEnabled() const
{
    return impObj()->isNotifyEnabled();
}

Adesk::Boolean PyDbObject::isModified() const
{
    return impObj()->isModified();
}

Adesk::Boolean PyDbObject::isModifiedXData() const
{
    return impObj()->isModifiedXData();
}

Adesk::Boolean PyDbObject::isModifiedGraphics() const
{
    return impObj()->isModifiedGraphics();
}

Adesk::Boolean PyDbObject::isNewObject() const
{
    return impObj()->isNewObject();
}

Adesk::Boolean PyDbObject::isNotifying() const
{
    return impObj()->isNotifying();
}

Adesk::Boolean PyDbObject::isUndoing() const
{
    return impObj()->isUndoing();
}

Adesk::Boolean PyDbObject::isCancelling() const
{
    return impObj()->isCancelling();
}

Adesk::Boolean PyDbObject::isReallyClosing() const
{
    return impObj()->isReallyClosing();
}

Adesk::Boolean PyDbObject::isTransactionResident() const
{
    return impObj()->isTransactionResident();
}

Adesk::Boolean PyDbObject::isAProxy() const
{
    return impObj()->isAProxy();
}

void PyDbObject::assertReadEnabled() const
{
    impObj()->assertReadEnabled();
}

void PyDbObject::assertWriteEnabled()
{
    impObj()->assertWriteEnabled();
}

void PyDbObject::assertNotifyEnabled() const
{
    impObj()->assertNotifyEnabled();
}

bool PyDbObject::isUndoRecordingDisabled() const
{
    return impObj()->isUndoRecordingDisabled();
}

void PyDbObject::disableUndoRecording(Adesk::Boolean disable)
{
    impObj()->disableUndoRecording(disable);
}

Acad::ErrorStatus PyDbObject::addPersistentReactor(const PyDbObjectId& objId)
{
#ifdef BRXAPP
    impObj()->addPersistentReactor(objId.m_id);
    return eOk;
#else
    return impObj()->addPersistentReactor(objId.m_id);
#endif
}

Acad::ErrorStatus PyDbObject::removePersistentReactor(const PyDbObjectId& objId)
{
    return impObj()->removePersistentReactor(objId.m_id);
}

bool PyDbObject::hasPersistentReactor(const PyDbObjectId& objId) const
{
    return impObj()->hasPersistentReactor(objId.m_id);
}

bool PyDbObject::hasFields(void) const
{
    return  impObj()->hasFields();
}

PyDbObjectId PyDbObject::getField1()
{
    AcDbObjectId id;
    if (auto es = impObj()->getField(L"TEXT", id); es != eOk)
        throw PyAcadErrorStatus(es);
    return PyDbObjectId(id);
}

PyDbObjectId PyDbObject::getField2(const std::string& propName)
{
    AcDbObjectId id;
    if (auto es = impObj()->getField(utf8_to_wstr(propName).c_str(), id); es != eOk)
        throw PyAcadErrorStatus(es);
    return PyDbObjectId(id);
}

PyDbObjectId PyDbObject::setField1(PyDbField& pField)
{
    AcDbObjectId id;
    if (auto es = impObj()->setField(L"TEXT", pField.impObj(), id); es != eOk)
        throw PyAcadErrorStatus(es);
    return PyDbObjectId(id);
}

PyDbObjectId PyDbObject::setField2(const std::string& propName, PyDbField& pField)
{
    AcDbObjectId id;
    if (auto es = impObj()->setField(utf8_to_wstr(propName).c_str(), pField.impObj(), id); es != eOk)
        throw PyAcadErrorStatus(es);
    return PyDbObjectId(id);
}

PyDbHandle PyDbObject::getHandle() const
{
    PyDbHandle handle;
    impObj()->getAcDbHandle(handle.m_hnd);
    return handle;
}

Acad::ErrorStatus PyDbObject::removeField1(const PyDbObjectId& fieldId)
{
    return impObj()->removeField(fieldId.m_id);
}

Acad::ErrorStatus PyDbObject::removeField2(const std::string& propName)
{
    return impObj()->removeField(utf8_to_wstr(propName).c_str());
}

PyDbObjectId PyDbObject::getFieldDictionary(void) const
{
    return PyDbObjectId(impObj()->getFieldDictionary());
}

PyRxClass PyDbObject::desc()
{
    return PyRxClass(AcDbObject::desc(), false);
}

std::string PyDbObject::className()
{
    return "AcDbObject";
}

PyDbObject PyDbObject::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbObject::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbObject(static_cast<AcDbObject*>(src.impObj()->clone()), true);
}

PyDbObject PyDbObject::cast(const PyRxObject& src)
{
    PyDbObject dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbObject* PyDbObject::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbObject*>(m_pyImp.get());
}

