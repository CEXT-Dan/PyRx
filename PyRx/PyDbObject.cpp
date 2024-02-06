#include "stdafx.h"
#include "PyDbObject.h"
#include "PyDbEntity.h"
#include "PyDbDatabase.h"
#include "PyDbObjectId.h"
#include "ResultBuffer.h"
#include "PyDbField.h"
#include "PyDbFiler.h"
#include "PyDbIdMapping.h"

using namespace boost::python;

void makePyDbObjectWrapper()
{
    PyDocString DS("DbObject");
    class_<PyDbObject, bases<PyGiDrawable>>("DbObject", boost::python::no_init)
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: PyDb.ObjectId", "mode: OpenMode=kForRead", "erased: bool=False" })))
        .def("objectId", &PyDbObject::objectId, DS.ARGS())
        .def("ownerId", &PyDbObject::ownerId, DS.ARGS())
        .def("setOwnerId", &PyDbObject::setOwnerId, DS.ARGS({ "owner: PyDb.ObjectId" }))
        .def("database", &PyDbObject::database, DS.ARGS())
#ifdef NEVER
        .def("databaseToUse", &PyDbObject::databaseToUse)
        .def("intendedDatabase", &PyDbObject::intendedDatabase)
        .def("setIntendedDatabase", &PyDbObject::setIntendedDatabase)
#endif
        .def("createExtensionDictionary", &PyDbObject::createExtensionDictionary, DS.ARGS())
        .def("extensionDictionary", &PyDbObject::extensionDictionary, DS.ARGS())
        .def("releaseExtensionDictionary", &PyDbObject::releaseExtensionDictionary, DS.ARGS())
        .def("upgradeOpen", &PyDbObject::upgradeOpen, DS.ARGS())
        .def("upgradeFromNotify", &PyDbObject::upgradeFromNotify, DS.ARGS({ "wasWritable: bool" }))
        .def("downgradeOpen", &PyDbObject::downgradeOpen, DS.ARGS())
        .def("downgradeToNotify", &PyDbObject::downgradeToNotify, DS.ARGS({ "wasWritable: bool" }))
        .def("erase", &PyDbObject::erase1)
        .def("erase", &PyDbObject::erase2, DS.ARGS({ "erasing : bool=True" }))
        .def("close", &PyDbObject::close, DS.ARGS())
        .def("cancel", &PyDbObject::cancel, DS.ARGS())
        .def("handOverTo", &PyDbObject::handOverTo, DS.ARGS({ "newObject: PyDb.DbObject", "keepXData: bool", "keepExtDict: bool" }))
        .def("swapIdWith", &PyDbObject::swapIdWith, DS.ARGS({ "otherId: PyDb.DbObject", "swapXdata: bool", "swapExtDict: bool" }))
        .def("hasXData", &PyDbObject::hasXData, DS.ARGS({ "appname: str" }))
        .def("setXData", &PyDbObject::setXData, DS.ARGS({ "xdata: list" }))
        .def("xData", &PyDbObject::xData1, DS.ARGS({ "appname: str" }))
        .def("xData", &PyDbObject::xData2, DS.ARGS({ "appname: str = None" }))
        .def("xDataTransformBy", &PyDbObject::xDataTransformBy, DS.ARGS({ "xform: PyGe.Matrix3d" }))
        .def("isEraseStatusToggled", &PyDbObject::isEraseStatusToggled, DS.ARGS())
        .def("isErased", &PyDbObject::isErased, DS.ARGS())
        .def("isReadEnabled", &PyDbObject::isReadEnabled, DS.ARGS())
        .def("isWriteEnabled", &PyDbObject::isWriteEnabled, DS.ARGS())
        .def("isNotifyEnabled", &PyDbObject::isNotifyEnabled, DS.ARGS())
        .def("isModified", &PyDbObject::isModified, DS.ARGS())
        .def("isModifiedXData", &PyDbObject::isModifiedXData, DS.ARGS())
        .def("isModifiedGraphics", &PyDbObject::isModifiedGraphics, DS.ARGS())
        .def("isNewObject", &PyDbObject::isNewObject, DS.ARGS())
        .def("isNotifying", &PyDbObject::isNotifying, DS.ARGS())
        .def("isUndoing", &PyDbObject::isUndoing, DS.ARGS())
        .def("isCancelling", &PyDbObject::isCancelling, DS.ARGS())
        .def("isReallyClosing", &PyDbObject::isReallyClosing, DS.ARGS())
        .def("isTransactionResident", &PyDbObject::isTransactionResident, DS.ARGS())
        .def("isAProxy", &PyDbObject::isAProxy, DS.ARGS())
        .def("assertReadEnabled", &PyDbObject::assertReadEnabled, DS.ARGS())
        .def("assertWriteEnabled", &PyDbObject::assertWriteEnabled, DS.ARGS())
        .def("assertNotifyEnabled", &PyDbObject::assertNotifyEnabled, DS.ARGS())
        .def("isUndoRecordingDisabled", &PyDbObject::isUndoRecordingDisabled, DS.ARGS())
        .def("disableUndoRecording", &PyDbObject::disableUndoRecording, DS.ARGS({ "disable: bool" }))
        .def("addPersistentReactor", &PyDbObject::addPersistentReactor, DS.ARGS({ "id: PyDb.ObjectId" }))
        .def("removePersistentReactor", &PyDbObject::removePersistentReactor, DS.ARGS({ "id: PyDb.ObjectId" }))
        .def("hasPersistentReactor", &PyDbObject::hasPersistentReactor, DS.ARGS({ "id: PyDb.ObjectId" }))
        .def("hasFields", &PyDbObject::hasFields, DS.ARGS())
        .def("getField", &PyDbObject::getField1)
        .def("getField", &PyDbObject::getField2, DS.ARGS({ "prop: str=TEXT" }))
        .def("setField", &PyDbObject::setField1)
        .def("setField", &PyDbObject::setField2, DS.ARGS({ "prop: str=TEXT", "obj: Field" }))
        .def("getHandle", &PyDbObject::getHandle, DS.ARGS())
        .def("removeField", &PyDbObject::removeField1)
        .def("removeField", &PyDbObject::removeField2, DS.ARGS({ "id: str|ObjectId" }))
        .def("getFieldDictionary", &PyDbObject::getFieldDictionary, DS.ARGS())
        .def("addReactor", &PyDbObject::addReactor, DS.ARGS({ "reactor: DbObjectReactor" }))
        .def("removeReactor", &PyDbObject::removeReactor, DS.ARGS({ "reactor: DbObjectReactor" }))
        .def("snoop", &PyDbObject::snoop, DS.ARGS({ " filer : PyDb.SnoopDwgFiler" }))
        .def("deepClone", &PyDbObject::deepClone1)
        .def("deepClone", &PyDbObject::deepClone2, DS.ARGS({ "owner: PyDb.DbObject" ,"mapping: PyDb.IdMapping","isPrimary:bool=True" }))
        .def("wblockClone", &PyDbObject::wblockClone1)
        .def("wblockClone", &PyDbObject::wblockClone2, DS.ARGS({ "owner: PyRx.RxObject" ,"mapping: PyDb.IdMapping","isPrimary:bool=True" }))
        .def("xmitPropagateModify", &PyDbObject::xmitPropagateModify, DS.ARGS())
        .def("setAcDbObjectIdsInFlux", &PyDbObject::setAcDbObjectIdsInFlux, DS.ARGS())
        .def("isAcDbObjectIdsInFlux", &PyDbObject::isAcDbObjectIdsInFlux, DS.ARGS())
        .def("desc", &PyDbObject::desc, DS.SARGS()).staticmethod("desc")
        .def("className", &PyDbObject::className, DS.SARGS()).staticmethod("className")
        .def("cloneFrom", &PyDbObject::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbObject::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

//-----------------------------------------------------------------------------------------
//PyDbObject
PyDbObject::PyDbObject(AcDbObject* ptr, bool autoDelete)
    : PyGiDrawable(ptr, autoDelete, true)
{
}

PyDbObject::PyDbObject(const PyDbObjectId& id)
    : PyGiDrawable(openAcDbObject<AcDbObject>(id, AcDb::OpenMode::kForRead), false, true)
{
}

PyDbObject::PyDbObject(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyGiDrawable(openAcDbObject<AcDbObject>(id, mode), false, true)
{
}

PyDbObject::PyDbObject(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyGiDrawable(openAcDbObject<AcDbObject>(id, mode, erased), false, true)
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

void PyDbObject::setOwnerId(const PyDbObjectId& objId)
{
    return PyThrowBadEs(impObj()->setOwnerId(objId.m_id));
}

PyDbDatabase PyDbObject::database() const
{
    return PyDbDatabase(impObj()->database());
}

void PyDbObject::createExtensionDictionary()
{
    return PyThrowBadEs(impObj()->createExtensionDictionary());
}

PyDbObjectId PyDbObject::extensionDictionary() const
{
    return PyDbObjectId(impObj()->extensionDictionary());
}

void PyDbObject::releaseExtensionDictionary()
{
    return PyThrowBadEs(impObj()->releaseExtensionDictionary());
}

void PyDbObject::close()
{
    return PyThrowBadEs(impObj()->close());
}

void PyDbObject::upgradeOpen()
{
    return PyThrowBadEs(impObj()->upgradeOpen());
}

void PyDbObject::upgradeFromNotify(Adesk::Boolean& wasWritable)
{
    return PyThrowBadEs(impObj()->upgradeFromNotify(wasWritable));
}

void PyDbObject::downgradeOpen()
{
    return PyThrowBadEs(impObj()->downgradeOpen());
}

void PyDbObject::downgradeToNotify(Adesk::Boolean wasWritable)
{
    return PyThrowBadEs(impObj()->downgradeToNotify(wasWritable));
}

void PyDbObject::cancel()
{
    return PyThrowBadEs(impObj()->cancel());
}

void PyDbObject::erase1()
{
    return PyThrowBadEs(impObj()->erase());
}

void PyDbObject::erase2(Adesk::Boolean erasing)
{
    return PyThrowBadEs(impObj()->erase(erasing));
}

void PyDbObject::handOverTo(PyDbObject& newObject, Adesk::Boolean keepXData, Adesk::Boolean keepExtDict)
{
    return PyThrowBadEs(impObj()->handOverTo(newObject.impObj(), keepXData, keepExtDict));
}

void PyDbObject::swapIdWith(PyDbObjectId& otherId, Adesk::Boolean swapXdata, Adesk::Boolean swapExtDict)
{
    return PyThrowBadEs(impObj()->swapIdWith(otherId.m_id, swapXdata, swapExtDict));
}

bool PyDbObject::hasXData(const std::string& regappName)
{
    AcResBufPtr pData(impObj()->xData(utf8_to_wstr(regappName).c_str()));
    return pData.get() != nullptr;
}

void PyDbObject::setXData(const boost::python::list& xdata)
{
    AcResBufPtr pData(listToResbuf(xdata));
    if (!impObj()->isWriteEnabled())
        PyThrowBadEs(eNotOpenForWrite);
    PyThrowBadEs(impObj()->setXData(pData.get()));
}

boost::python::list PyDbObject::xData1() const
{
    AcResBufPtr pData(impObj()->xData());
    return resbufToList(pData.get());
}

boost::python::list PyDbObject::xData2(const std::string& regappName) const
{
    AcResBufPtr pData(impObj()->xData(utf8_to_wstr(regappName).c_str()));
    return resbufToList(pData.get());
}

void PyDbObject::xDataTransformBy(const AcGeMatrix3d& xform)
{
    return PyThrowBadEs(impObj()->xDataTransformBy(xform));
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

void PyDbObject::addPersistentReactor(const PyDbObjectId& objId)
{
    return PyThrowBadEs(impObj()->addPersistentReactor(objId.m_id));
}

void PyDbObject::removePersistentReactor(const PyDbObjectId& objId)
{
    return PyThrowBadEs(impObj()->removePersistentReactor(objId.m_id));
}

bool PyDbObject::hasPersistentReactor(const PyDbObjectId& objId) const
{
    return impObj()->hasPersistentReactor(objId.m_id);
}

bool PyDbObject::hasFields(void) const
{
    return impObj()->hasFields();
}

PyDbObjectId PyDbObject::getField1()
{
    AcDbObjectId id;
    PyThrowBadEs(impObj()->getField(L"TEXT", id));
    return PyDbObjectId(id);
}

PyDbObjectId PyDbObject::getField2(const std::string& propName)
{
    AcDbObjectId id;
    PyThrowBadEs(impObj()->getField(utf8_to_wstr(propName).c_str(), id));
    return PyDbObjectId(id);
}

PyDbObjectId PyDbObject::setField1(PyDbField& pField)
{
    AcDbObjectId id;
    PyThrowBadEs(impObj()->setField(L"TEXT", pField.impObj(), id));
    return PyDbObjectId(id);
}

PyDbObjectId PyDbObject::setField2(const std::string& propName, PyDbField& pField)
{
    AcDbObjectId id;
    PyThrowBadEs(impObj()->setField(utf8_to_wstr(propName).c_str(), pField.impObj(), id));
    return PyDbObjectId(id);
}

PyDbHandle PyDbObject::getHandle() const
{
    PyDbHandle handle;
    impObj()->getAcDbHandle(handle.m_hnd);
    return handle;
}

void PyDbObject::removeField1(const PyDbObjectId& fieldId)
{
    return PyThrowBadEs(impObj()->removeField(fieldId.m_id));
}

void PyDbObject::removeField2(const std::string& propName)
{
    return PyThrowBadEs(impObj()->removeField(utf8_to_wstr(propName).c_str()));
}

PyDbObjectId PyDbObject::getFieldDictionary(void) const
{
    return PyDbObjectId(impObj()->getFieldDictionary());
}

void PyDbObject::addReactor(PyDbObjectReactor& pReactor) const
{
    return PyThrowBadEs(impObj()->addReactor(pReactor.impObj()));
}

void PyDbObject::removeReactor(PyDbObjectReactor& pReactor) const
{
    return PyThrowBadEs(impObj()->removeReactor(pReactor.impObj()));
}

void PyDbObject::snoop(PyDbSnoopDwgFiler& filer)
{
    return PyThrowBadEs(impObj()->dwgOut(std::addressof(filer)));
}

PyDbObject PyDbObject::deepClone1(PyDbObject& pOwnerObject, PyDbIdMapping& idMap)
{
    return deepClone2(pOwnerObject, idMap, true);
}

PyDbObject PyDbObject::deepClone2(PyDbObject& pOwnerObject, PyDbIdMapping& idMap, Adesk::Boolean isPrimary)
{
    AcDbObject* pClonedObject = nullptr;
    PyThrowBadEs(impObj()->deepClone(pOwnerObject.impObj(), pClonedObject, *idMap.impObj()));
    return PyDbObject(pClonedObject, true);
}

PyDbObject PyDbObject::wblockClone1(PyRxObject& pOwnerObject, PyDbIdMapping& idMap)
{
    return wblockClone2(pOwnerObject, idMap, true);
}

PyDbObject PyDbObject::wblockClone2(PyRxObject& pOwnerObject, PyDbIdMapping& idMap, Adesk::Boolean isPrimary)
{
    AcDbObject* pClonedObject = nullptr;
    PyThrowBadEs(impObj()->wblockClone(pOwnerObject.impObj(), pClonedObject, *idMap.impObj()));
    return PyDbObject(pClonedObject, true);
}

void PyDbObject::xmitPropagateModify() const
{
    impObj()->xmitPropagateModify();
}

void PyDbObject::setAcDbObjectIdsInFlux()
{
    impObj()->setAcDbObjectIdsInFlux();
}

Adesk::Boolean PyDbObject::isAcDbObjectIdsInFlux() const
{
    return impObj()->isAcDbObjectIdsInFlux();
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
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<AcDbObject*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
//PyDbObjectReactorImpl
PyDbObjectReactorImpl::PyDbObjectReactorImpl(PyDbObjectReactor* ptr)
    : m_backPtr(ptr)
{
}

void PyDbObjectReactorImpl::cancelled(const AcDbObject* src)
{
    const auto imp = impObj();
    if (imp->reg_cancelled)
    {
        PyDbObject obj(const_cast<AcDbObject*>(src), false);
        obj.forceKeepAlive(true);
        imp->cancelled(obj);
    }
}

void PyDbObjectReactorImpl::copied(const AcDbObject* src, const AcDbObject* newObj)
{
    const auto imp = impObj();
    if (imp->reg_copied)
    {
        PyDbObject obj(const_cast<AcDbObject*>(src), false);
        PyDbObject obj2(const_cast<AcDbObject*>(newObj), false);
        obj.forceKeepAlive(true);
        obj2.forceKeepAlive(true);
        imp->copied(obj, obj2);
    }
}


void PyDbObjectReactorImpl::erased(const AcDbObject* src, Adesk::Boolean bErasing)
{
    const auto imp = impObj();
    if (imp->reg_erased)
    {
        PyDbObject obj(const_cast<AcDbObject*>(src), false);
        obj.forceKeepAlive(true);
        imp->erased(obj, bErasing);
    }
}

void PyDbObjectReactorImpl::goodbye(const AcDbObject* ptr)
{
    const auto imp = impObj();
    if (imp->reg_goodbye)
    {
        PyDbObject obj(const_cast<AcDbObject*>(ptr), false);
        obj.forceKeepAlive(true);
        imp->goodbye(obj);
    }
}

void PyDbObjectReactorImpl::openedForModify(const AcDbObject* ptr)
{
    const auto imp = impObj();
    if (imp->reg_openedForModify)
    {
        PyDbObject obj(const_cast<AcDbObject*>(ptr), false);
        obj.forceKeepAlive(true);
        imp->openedForModify(obj);
    }
}

void PyDbObjectReactorImpl::modified(const AcDbObject* ptr)
{
    const auto imp = impObj();
    if (imp->reg_modified)
    {
        PyDbObject obj(const_cast<AcDbObject*>(ptr), false);
        obj.forceKeepAlive(true);
        imp->modified(obj);
    }
}

void PyDbObjectReactorImpl::subObjModified(const AcDbObject* ptr, const AcDbObject* subObj)
{
    const auto imp = impObj();
    if (imp->reg_subObjModified)
    {
        PyDbObject obj(const_cast<AcDbObject*>(ptr), false);
        PyDbObject obj2(const_cast<AcDbObject*>(subObj), false);
        obj.forceKeepAlive(true);
        obj2.forceKeepAlive(true);
        imp->subObjModified(obj, obj2);
    }
}

void PyDbObjectReactorImpl::modifyUndone(const AcDbObject* ptr)
{
    const auto imp = impObj();
    if (imp->reg_modifyUndone)
    {
        PyDbObject obj(const_cast<AcDbObject*>(ptr), false);
        obj.forceKeepAlive(true);
        imp->modifyUndone(obj);
    }
}

void PyDbObjectReactorImpl::modifiedXData(const AcDbObject* ptr)
{
    const auto imp = impObj();
    if (imp->reg_modifiedXData)
    {
        PyDbObject obj(const_cast<AcDbObject*>(ptr), false);
        obj.forceKeepAlive(true);
        imp->modifiedXData(obj);
    }
}

void PyDbObjectReactorImpl::unappended(const AcDbObject* ptr)
{
    const auto imp = impObj();
    if (imp->reg_unappended)
    {
        PyDbObject obj(const_cast<AcDbObject*>(ptr), false);
        obj.forceKeepAlive(true);
        imp->unappended(obj);
    }
}

void PyDbObjectReactorImpl::reappended(const AcDbObject* ptr)
{
    const auto imp = impObj();
    if (imp->reg_reappended)
    {
        PyDbObject obj(const_cast<AcDbObject*>(ptr), false);
        obj.forceKeepAlive(true);
        imp->reappended(obj);
    }
}

void PyDbObjectReactorImpl::objectClosed(const AcDbObjectId id)
{
    const auto imp = impObj();
    if (imp->reg_objectClosed)
    {
        PyDbObjectId obj(id);
        imp->objectClosed(obj);
    }
}

PyDbObjectReactor* PyDbObjectReactorImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_backPtr == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return m_backPtr;
}

//---------------------------------------------------------------------------------------- -
//PyDbObjectReactor
void makePyDbObjectReactorWrapper()
{
    PyDocString DS("DbObjectReactor");
    class_<PyDbObjectReactor, bases<PyRxObject>>("DbObjectReactor")
        .def(init<>())
        .def("cancelled", &PyDbObjectReactor::cancelled, DS.ARGS({ "obj: PyDb.DbObject" }))
        .def("copied", &PyDbObjectReactor::copied, DS.ARGS({ "obj: PyDb.DbObject","newObj: PyDb.DbObject" }))
        .def("erased", &PyDbObjectReactor::erased, DS.ARGS({ "obj: PyDb.DbObject", "flag: bool" }))
        .def("goodbye", &PyDbObjectReactor::goodbye, DS.ARGS({ "obj: PyDb.DbObject" }))
        .def("openedForModify", &PyDbObjectReactor::openedForModify, DS.ARGS({ "obj: PyDb.DbObject" }))
        .def("modified", &PyDbObjectReactor::modified, DS.ARGS({ "obj: PyDb.DbObject" }))
        .def("subObjModified", &PyDbObjectReactor::subObjModified, DS.ARGS({ "obj: PyDb.DbObject","subObj: PyDb.DbObject" }))
        .def("modifyUndone", &PyDbObjectReactor::modifyUndone, DS.ARGS({ "obj: PyDb.DbObject" }))
        .def("modifiedXData", &PyDbObjectReactor::modifiedXData, DS.ARGS({ "obj: PyDb.DbObject" }))
        .def("unappended", &PyDbObjectReactor::unappended, DS.ARGS({ "obj: PyDb.DbObject" }))
        .def("reappended", &PyDbObjectReactor::reappended, DS.ARGS({ "obj: PyDb.DbObject" }))
        .def("objectClosed", &PyDbObjectReactor::objectClosed, DS.ARGS({ "obj: PyDb.ObjectId" }))
        .def("desc", &PyDbObjectReactor::desc, DS.SARGS()).staticmethod("desc")
        .def("className", &PyDbObjectReactor::className, DS.SARGS()).staticmethod("className")
        ;
}

PyDbObjectReactor::PyDbObjectReactor()
    : PyRxObject(new PyDbObjectReactorImpl(this), true, false), boost::python::wrapper<PyDbObjectReactor>()
{
}

void PyDbObjectReactor::cancelled(const PyDbObject& pObj)
{
    PyAutoLockGIL lock;
    try
    {
        if (override f = this->get_override("cancelled"))
            f(pObj);
        else
            reg_cancelled = false;
    }
    catch (...)
    {
        reg_cancelled = false;
        printExceptionMsg();
    }
}

void PyDbObjectReactor::copied(const PyDbObject& src, const PyDbObject& newObj)
{
    PyAutoLockGIL lock;
    try
    {
        if (override f = this->get_override("copied"))
            f(src, newObj);
        else
            reg_copied = false;
    }
    catch (...)
    {
        reg_copied = false;
        printExceptionMsg();
    }
}

void PyDbObjectReactor::erased(const PyDbObject& src, Adesk::Boolean bErasing)
{
    PyAutoLockGIL lock;
    try
    {
        if (override f = this->get_override("erased"))
            f(src, bErasing);
        else
            reg_erased = false;
    }
    catch (...)
    {
        reg_erased = false;
        printExceptionMsg();
    }
}

void PyDbObjectReactor::goodbye(const PyDbObject& ptr)
{
    PyAutoLockGIL lock;
    try
    {
        if (override f = this->get_override("goodbye"))
            f(ptr);
        else
            reg_goodbye = false;
    }
    catch (...)
    {
        reg_goodbye = false;
        printExceptionMsg();
    }
}

void PyDbObjectReactor::openedForModify(const PyDbObject& ptr)
{
    PyAutoLockGIL lock;
    try
    {
        if (override f = this->get_override("openedForModify"))
            f(ptr);
        else
            reg_openedForModify = false;
    }
    catch (...)
    {
        reg_openedForModify = false;
        printExceptionMsg();
    }
}

void PyDbObjectReactor::modified(const PyDbObject& ptr)
{
    PyAutoLockGIL lock;
    try
    {
        if (override f = this->get_override("modified"))
            f(ptr);
        else
            reg_modified = false;
    }
    catch (...)
    {
        reg_modified = false;
        printExceptionMsg();
    }
}

void PyDbObjectReactor::subObjModified(const PyDbObject& ptr, const PyDbObject& subObj)
{
    PyAutoLockGIL lock;
    try
    {
        if (override f = this->get_override("subObjModified"))
            f(ptr, subObj);
        else
            reg_subObjModified = false;
    }
    catch (...)
    {
        reg_subObjModified = false;
        printExceptionMsg();
    }
}

void PyDbObjectReactor::modifyUndone(const PyDbObject& ptr)
{
    PyAutoLockGIL lock;
    try
    {
        if (override f = this->get_override("modifyUndone"))
            f(ptr);
        else
            reg_modifyUndone = false;
    }
    catch (...)
    {
        reg_modifyUndone = false;
        printExceptionMsg();
    }
}

void PyDbObjectReactor::modifiedXData(const PyDbObject& ptr)
{
    PyAutoLockGIL lock;
    try
    {
        if (override f = this->get_override("modifiedXData"))
            f(ptr);
        else
            reg_modifiedXData = false;
    }
    catch (...)
    {
        reg_modifiedXData = false;
        printExceptionMsg();
    }
}

void PyDbObjectReactor::unappended(const PyDbObject& ptr)
{
    PyAutoLockGIL lock;
    try
    {
        if (override f = this->get_override("unappended"))
            f(ptr);
        else
            reg_unappended = false;
    }
    catch (...)
    {
        reg_unappended = false;
        printExceptionMsg();
    }
}

void PyDbObjectReactor::reappended(const PyDbObject& ptr)
{
    PyAutoLockGIL lock;
    try
    {
        if (override f = this->get_override("reappended"))
            f(ptr);
        else
            reg_reappended = false;
    }
    catch (...)
    {
        reg_reappended = false;
        printExceptionMsg();
    }
}

void PyDbObjectReactor::objectClosed(const PyDbObjectId& id)
{
    PyAutoLockGIL lock;
    try
    {
        if (override f = this->get_override("objectClosed"))
            f(id);
        else
            reg_objectClosed = false;
    }
    catch (...)
    {
        reg_objectClosed = false;
        printExceptionMsg();
    }
}

PyRxClass PyDbObjectReactor::desc()
{
    return PyRxClass(AcDbObjectReactor::desc(), false);
}

std::string PyDbObjectReactor::className()
{
    return "AcDbObjectReactor";
}

AcDbObjectReactor* PyDbObjectReactor::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<AcDbObjectReactor*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
//AcDbEntityReactorImpl
AcDbEntityReactorImpl::AcDbEntityReactorImpl(PyDbEntityReactor* ptr)
    : m_backPtr(ptr)
{
}

void AcDbEntityReactorImpl::cancelled(const AcDbObject* src)
{
    const auto imp = impObj();
    if (imp->reg_cancelled)
    {
        PyDbObject obj(const_cast<AcDbObject*>(src), false);
        obj.forceKeepAlive(true);
        imp->cancelled(obj);
    }
}

void AcDbEntityReactorImpl::copied(const AcDbObject* src, const AcDbObject* newObj)
{
    const auto imp = impObj();
    if (imp->reg_copied)
    {
        PyDbObject obj(const_cast<AcDbObject*>(src), false);
        PyDbObject obj2(const_cast<AcDbObject*>(newObj), false);
        obj.forceKeepAlive(true);
        obj2.forceKeepAlive(true);
        imp->copied(obj, obj2);
    }
}

void AcDbEntityReactorImpl::erased(const AcDbObject* src, Adesk::Boolean bErasing)
{
    const auto imp = impObj();
    if (imp->reg_erased)
    {
        PyDbObject obj(const_cast<AcDbObject*>(src), false);
        obj.forceKeepAlive(true);
        imp->erased(obj, bErasing);
    }
}

void AcDbEntityReactorImpl::goodbye(const AcDbObject* ptr)
{
    const auto imp = impObj();
    if (imp->reg_goodbye)
    {
        PyDbObject obj(const_cast<AcDbObject*>(ptr), false);
        obj.forceKeepAlive(true);
        imp->goodbye(obj);
    }
}

void AcDbEntityReactorImpl::openedForModify(const AcDbObject* ptr)
{
    const auto imp = impObj();
    if (imp->reg_openedForModify)
    {
        PyDbObject obj(const_cast<AcDbObject*>(ptr), false);
        obj.forceKeepAlive(true);
        imp->openedForModify(obj);
    }
}

void AcDbEntityReactorImpl::modified(const AcDbObject* ptr)
{
    const auto imp = impObj();
    if (imp->reg_modified)
    {
        PyDbObject obj(const_cast<AcDbObject*>(ptr), false);
        obj.forceKeepAlive(true);
        imp->modified(obj);
    }
}

void AcDbEntityReactorImpl::subObjModified(const AcDbObject* ptr, const AcDbObject* subObj)
{
    const auto imp = impObj();
    if (imp->reg_subObjModified)
    {
        PyDbObject obj(const_cast<AcDbObject*>(ptr), false);
        PyDbObject obj2(const_cast<AcDbObject*>(subObj), false);
        obj.forceKeepAlive(true);
        obj2.forceKeepAlive(true);
        imp->subObjModified(obj, obj2);
    }
}

void AcDbEntityReactorImpl::modifyUndone(const AcDbObject* ptr)
{
    const auto imp = impObj();
    if (imp->reg_modifyUndone)
    {
        PyDbObject obj(const_cast<AcDbObject*>(ptr), false);
        obj.forceKeepAlive(true);
        imp->modifyUndone(obj);
    }
}

void AcDbEntityReactorImpl::modifiedXData(const AcDbObject* ptr)
{
    const auto imp = impObj();
    if (imp->reg_modifiedXData)
    {
        PyDbObject obj(const_cast<AcDbObject*>(ptr), false);
        obj.forceKeepAlive(true);
        imp->modifiedXData(obj);
    }
}

void AcDbEntityReactorImpl::unappended(const AcDbObject* ptr)
{
    const auto imp = impObj();
    if (imp->reg_unappended)
    {
        PyDbObject obj(const_cast<AcDbObject*>(ptr), false);
        obj.forceKeepAlive(true);
        imp->unappended(obj);
    }
}

void AcDbEntityReactorImpl::reappended(const AcDbObject* ptr)
{
    const auto imp = impObj();
    if (imp->reg_reappended)
    {
        PyDbObject obj(const_cast<AcDbObject*>(ptr), false);
        obj.forceKeepAlive(true);
        imp->reappended(obj);
    }
}

void AcDbEntityReactorImpl::objectClosed(const AcDbObjectId id)
{
    const auto imp = impObj();
    if (imp->reg_objectClosed)
    {
        PyDbObjectId obj(id);
        imp->objectClosed(obj);
    }
}

void AcDbEntityReactorImpl::modifiedGraphics(const AcDbEntity* ent)
{
    const auto imp = impObj();
    if (imp->reg_modifiedGraphics)
    {
        PyDbEntity obj(const_cast<AcDbEntity*>(ent), false);
        obj.forceKeepAlive(true);
        imp->modifiedGraphics(obj);
    }
}

void AcDbEntityReactorImpl::dragCloneToBeDeleted(const AcDbEntity* pOriginalObj, const AcDbEntity* pClone)
{
    const auto imp = impObj();
    if (imp->reg_modifiedGraphics)
    {
        PyDbEntity obj1(const_cast<AcDbEntity*>(pOriginalObj), false);
        PyDbEntity obj2(const_cast<AcDbEntity*>(pOriginalObj), false);
        obj1.forceKeepAlive(true);
        obj2.forceKeepAlive(true);
        imp->dragCloneToBeDeleted(obj1, obj2);
    }
}

PyDbEntityReactor* AcDbEntityReactorImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_backPtr == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return m_backPtr;
}

//---------------------------------------------------------------------------------------- -
//PyDbEntityReactor
void makePyDbEntityReactorWrapper()
{
    PyDocString DS("EntityReactor");
    class_<PyDbEntityReactor, bases<PyRxObject>>("EntityReactor")
        .def(init<>())
        .def("cancelled", &PyDbEntityReactor::cancelled, DS.ARGS({ "obj: PyDb.DbObject" }))
        .def("copied", &PyDbEntityReactor::copied, DS.ARGS({ "obj: PyDb.DbObject","newObj: PyDb.DbObject" }))
        .def("erased", &PyDbEntityReactor::erased, DS.ARGS({ "obj: PyDb.DbObject", "flag: bool" }))
        .def("goodbye", &PyDbEntityReactor::goodbye, DS.ARGS({ "obj: PyDb.DbObject" }))
        .def("openedForModify", &PyDbEntityReactor::openedForModify, DS.ARGS({ "obj: PyDb.DbObject" }))
        .def("modified", &PyDbEntityReactor::modified, DS.ARGS({ "obj: PyDb.DbObject" }))
        .def("subObjModified", &PyDbEntityReactor::subObjModified, DS.ARGS({ "obj: PyDb.DbObject","subObj: PyDb.DbObject" }))
        .def("modifyUndone", &PyDbEntityReactor::modifyUndone, DS.ARGS({ "obj: PyDb.DbObject" }))
        .def("modifiedXData", &PyDbEntityReactor::modifiedXData, DS.ARGS({ "obj: PyDb.DbObject" }))
        .def("unappended", &PyDbEntityReactor::unappended, DS.ARGS({ "obj: PyDb.DbObject" }))
        .def("reappended", &PyDbEntityReactor::reappended, DS.ARGS({ "obj: PyDb.DbObject" }))
        .def("objectClosed", &PyDbEntityReactor::objectClosed, DS.ARGS({ "obj: PyDb.ObjectId" }))
        .def("modifiedGraphics", &PyDbEntityReactor::modifiedGraphics, DS.ARGS({ "obj: PyDb.Entity" }))
        .def("dragCloneToBeDeleted", &PyDbEntityReactor::dragCloneToBeDeleted, DS.ARGS({ "obj: PyDb.Entity","clone: PyDb.Entity" }))
        .def("desc", &PyDbEntityReactor::desc, DS.SARGS()).staticmethod("desc")
        .def("className", &PyDbEntityReactor::className, DS.SARGS()).staticmethod("className")
        ;
}

PyDbEntityReactor::PyDbEntityReactor()
    : PyRxObject(new AcDbEntityReactorImpl(this), true, false)
{
}

void PyDbEntityReactor::cancelled(const PyDbObject& pObj)
{
    PyAutoLockGIL lock;
    try
    {
        if (override f = this->get_override("cancelled"))
            f(pObj);
        else
            reg_cancelled = false;
    }
    catch (...)
    {
        reg_cancelled = false;
        printExceptionMsg();
    }
}

void PyDbEntityReactor::copied(const PyDbObject& src, const PyDbObject& newObj)
{
    PyAutoLockGIL lock;
    try
    {
        if (override f = this->get_override("copied"))
            f(src, newObj);
        else
            reg_copied = false;
    }
    catch (...)
    {
        reg_copied = false;
        printExceptionMsg();
    }
}

void PyDbEntityReactor::erased(const PyDbObject& src, bool bErasing)
{
    PyAutoLockGIL lock;
    try
    {
        if (override f = this->get_override("erased"))
            f(src, bErasing);
        else
            reg_erased = false;
    }
    catch (...)
    {
        reg_erased = false;
        printExceptionMsg();
    }
}

void PyDbEntityReactor::goodbye(const PyDbObject& ptr)
{
    PyAutoLockGIL lock;
    try
    {
        if (override f = this->get_override("goodbye"))
            f(ptr);
        else
            reg_goodbye = false;
    }
    catch (...)
    {
        reg_goodbye = false;
        printExceptionMsg();
    }
}

void PyDbEntityReactor::openedForModify(const PyDbObject& ptr)
{
    PyAutoLockGIL lock;
    try
    {
        if (override f = this->get_override("openedForModify"))
            f(ptr);
        else
            reg_openedForModify = false;
    }
    catch (...)
    {
        reg_openedForModify = false;
        printExceptionMsg();
    }
}

void PyDbEntityReactor::modified(const PyDbObject& ptr)
{
    PyAutoLockGIL lock;
    try
    {
        if (override f = this->get_override("modified"))
            f(ptr);
        else
            reg_modified = false;
    }
    catch (...)
    {
        reg_modified = false;
        printExceptionMsg();
    }
}

void PyDbEntityReactor::subObjModified(const PyDbObject& ptr, const PyDbObject& subObj)
{
    PyAutoLockGIL lock;
    try
    {
        if (override f = this->get_override("subObjModified"))
            f(ptr, subObj);
        else
            reg_subObjModified = false;
    }
    catch (...)
    {
        reg_subObjModified = false;
        printExceptionMsg();
    }
}

void PyDbEntityReactor::modifyUndone(const PyDbObject& ptr)
{
    PyAutoLockGIL lock;
    try
    {
        if (override f = this->get_override("modifyUndone"))
            f(ptr);
        else
            reg_modifyUndone = false;
    }
    catch (...)
    {
        reg_modifyUndone = false;
        printExceptionMsg();
    }
}

void PyDbEntityReactor::modifiedXData(const PyDbObject& ptr)
{
    PyAutoLockGIL lock;
    try
    {
        if (override f = this->get_override("modifiedXData"))
            f(ptr);
        else
            reg_modifiedXData = false;
    }
    catch (...)
    {
        reg_modifiedXData = false;
        printExceptionMsg();
    }
}

void PyDbEntityReactor::unappended(const PyDbObject& ptr)
{
    PyAutoLockGIL lock;
    try
    {
        if (override f = this->get_override("unappended"))
            f(ptr);
        else
            reg_unappended = false;
    }
    catch (...)
    {
        reg_unappended = false;
        printExceptionMsg();
    }
}

void PyDbEntityReactor::reappended(const PyDbObject& ptr)
{
    PyAutoLockGIL lock;
    try
    {
        if (override f = this->get_override("reappended"))
            f(ptr);
        else
            reg_reappended = false;
    }
    catch (...)
    {
        reg_reappended = false;
        printExceptionMsg();
    }
}

void PyDbEntityReactor::objectClosed(const PyDbObjectId& id)
{
    PyAutoLockGIL lock;
    try
    {
        if (override f = this->get_override("objectClosed"))
            f(id);
        else
            reg_objectClosed = false;
    }
    catch (...)
    {
        reg_objectClosed = false;
        printExceptionMsg();
    }
}

void PyDbEntityReactor::modifiedGraphics(const PyDbEntity& ent)
{
    PyAutoLockGIL lock;
    try
    {
        if (override f = this->get_override("modifiedGraphics"))
            f(ent);
        else
            reg_modifiedGraphics = false;
    }
    catch (...)
    {
        reg_modifiedGraphics = false;
        printExceptionMsg();
    }
}

void PyDbEntityReactor::dragCloneToBeDeleted(const PyDbEntity& pOriginalObj, const PyDbEntity& pClone)
{
    PyAutoLockGIL lock;
    try
    {
        if (override f = this->get_override("dragCloneToBeDeleted"))
            f(pOriginalObj, pClone);
        else
            reg_dragCloneToBeDeleted = false;
    }
    catch (...)
    {
        reg_dragCloneToBeDeleted = false;
        printExceptionMsg();
    }
}

PyRxClass PyDbEntityReactor::desc()
{
    return PyRxClass(AcDbEntityReactor::desc(), false);
}

std::string PyDbEntityReactor::className()
{
    return "AcDbEntityReactor";
}

AcDbEntityReactor* PyDbEntityReactor::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<AcDbEntityReactor*>(m_pyImp.get());
}
