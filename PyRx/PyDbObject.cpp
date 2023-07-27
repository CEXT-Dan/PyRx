#include "stdafx.h"
#include "PyDbObject.h"
#include "PyDbDatabase.h"
#include "PyDbObjectId.h"
#include "ResultBuffer.h"
#include "PyDbField.h"

using namespace boost::python;

void makePyDbObjectWrapper()
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
        .def("getField", &PyDbObject::getField1)
        .def("getField", &PyDbObject::getField2, DS.CLASSARGS({ "prop: str=TEXT" }))
        .def("setField", &PyDbObject::setField1)
        .def("setField", &PyDbObject::setField2, DS.CLASSARGS({ "prop: str=TEXT", "obj: Field" }))
        .def("getHandle", &PyDbObject::getHandle, DS.CLASSARGS())
        .def("removeField", &PyDbObject::removeField1)
        .def("removeField", &PyDbObject::removeField2, DS.CLASSARGS({ "id: str|ObjectId" }))
        .def("getFieldDictionary", &PyDbObject::getFieldDictionary, DS.CLASSARGS())
        .def("addReactor", &PyDbObject::addReactor, DS.CLASSARGS({ "reactor: DbObjectReactor" }))
        .def("removeReactor", &PyDbObject::removeReactor, DS.CLASSARGS({ "reactor: DbObjectReactor" }))
        .def("desc", &PyDbObject::desc, DS.CLASSARGSSTATIC()).staticmethod("desc")
        .def("className", &PyDbObject::className, DS.CLASSARGSSTATIC()).staticmethod("className")
        .def("cloneFrom", &PyDbObject::cloneFrom, DS.CLASSARGSSTATIC({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbObject::cast, DS.CLASSARGSSTATIC({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
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

void PyDbObject::setXData(const boost::python::list& xdata)
{
    AcResBufPtr pData(listToResbuf(xdata));
    if (!impObj()->isWriteEnabled())
        PyThrowBadEs(eNotOpenForWrite);
    PyThrowBadEs(impObj()->setXData(pData.get()));
}

boost::python::list PyDbObject::xData(const std::string& regappName) const
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
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    impObj()->addPersistentReactor(objId.m_id);;
#else
    return PyThrowBadEs(impObj()->addPersistentReactor(objId.m_id));
#endif
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
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    impObj()->addReactor(pReactor.impObj());
#else
    return PyThrowBadEs(impObj()->addReactor(pReactor.impObj()));
#endif
}

void PyDbObject::removeReactor(PyDbObjectReactor& pReactor) const
{
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    impObj()->removeReactor(pReactor.impObj());
#else
    return PyThrowBadEs(impObj()->removeReactor(pReactor.impObj()));
#endif
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

//---------------------------------------------------------------------------------------- -
//PyDbObjectReactorImpl
ACRX_CONS_DEFINE_MEMBERS(PyDbObjectReactorImpl, AcDbObjectReactor, 1)
PyDbObjectReactorImpl::PyDbObjectReactorImpl(PyDbObjectReactor* ptr)
    : backPtr(ptr)
{
}

void PyDbObjectReactorImpl::cancelled(const AcDbObject* src)
{
    PyDbObject obj(const_cast<AcDbObject*>(src), false);
    obj.forceKeepAlive(true);
    impObj()->cancelled(obj);
}

void PyDbObjectReactorImpl::copied(const AcDbObject* src, const AcDbObject* newObj)
{
    PyDbObject obj(const_cast<AcDbObject*>(src), false);
    PyDbObject obj2(const_cast<AcDbObject*>(newObj), false);
    obj.forceKeepAlive(true);
    obj2.forceKeepAlive(true);
    impObj()->copied(obj, obj2);
}

#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
void PyDbObjectReactorImpl::erased(const AcDbObject* src, Adesk::Boolean bErasing)
{
    PyDbObject obj(const_cast<AcDbObject*>(src), false);
    obj.forceKeepAlive(true);
    impObj()->erased(obj, bErasing);
}
#else
void PyDbObjectReactorImpl::erased(const AcDbObject* src, bool bErasing)
{
    PyDbObject obj(const_cast<AcDbObject*>(src), false);
    obj.forceKeepAlive(true);
    impObj()->erased(obj, bErasing);
}
#endif

void PyDbObjectReactorImpl::goodbye(const AcDbObject* ptr)
{
    PyDbObject obj(const_cast<AcDbObject*>(ptr), false);
    obj.forceKeepAlive(true);
    impObj()->goodbye(obj);
}

void PyDbObjectReactorImpl::openedForModify(const AcDbObject* ptr)
{
    PyDbObject obj(const_cast<AcDbObject*>(ptr), false);
    obj.forceKeepAlive(true);
    impObj()->openedForModify(obj);
}

void PyDbObjectReactorImpl::modified(const AcDbObject* ptr)
{
    PyDbObject obj(const_cast<AcDbObject*>(ptr), false);
    obj.forceKeepAlive(true);
    impObj()->modified(obj);
}

void PyDbObjectReactorImpl::subObjModified(const AcDbObject* ptr, const AcDbObject* subObj)
{
    PyDbObject obj(const_cast<AcDbObject*>(ptr), false);
    PyDbObject obj2(const_cast<AcDbObject*>(subObj), false);
    obj.forceKeepAlive(true);
    obj2.forceKeepAlive(true);
    impObj()->subObjModified(obj, obj2);
}

void PyDbObjectReactorImpl::modifyUndone(const AcDbObject* ptr)
{
    PyDbObject obj(const_cast<AcDbObject*>(ptr), false);
    obj.forceKeepAlive(true);
    impObj()->modifyUndone(obj);
}

void PyDbObjectReactorImpl::modifiedXData(const AcDbObject* ptr)
{
    PyDbObject obj(const_cast<AcDbObject*>(ptr), false);
    obj.forceKeepAlive(true);
    impObj()->modifiedXData(obj);
}

void PyDbObjectReactorImpl::unappended(const AcDbObject* ptr)
{
    PyDbObject obj(const_cast<AcDbObject*>(ptr), false);
    obj.forceKeepAlive(true);
    impObj()->unappended(obj);
}

void PyDbObjectReactorImpl::reappended(const AcDbObject* ptr)
{
    PyDbObject obj(const_cast<AcDbObject*>(ptr), false);
    obj.forceKeepAlive(true);
    impObj()->reappended(obj);
}

void PyDbObjectReactorImpl::objectClosed(const AcDbObjectId id)
{
    PyDbObjectId obj(id);
    impObj()->objectClosed(obj);
}

PyDbObjectReactor* PyDbObjectReactorImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (backPtr == nullptr)
        throw PyNullObject(src);
    return backPtr;
}

//---------------------------------------------------------------------------------------- -
//PyDbObjectReactor
void makePyDbObjectReactorWrapper()
{
    PyDocString DS("DbObjectReactor");
    class_<PyDbObjectReactor, bases<PyRxObject>>("DbObjectReactor")
        .def(init<>())
        .def("cancelled", &PyDbObjectReactor::cancelled)
        .def("copied", &PyDbObjectReactor::copied)
        .def("erased", &PyDbObjectReactor::erased)
        .def("goodbye", &PyDbObjectReactor::goodbye)
        .def("openedForModify", &PyDbObjectReactor::openedForModify)
        .def("modified", &PyDbObjectReactor::modified)
        .def("subObjModified", &PyDbObjectReactor::subObjModified)
        .def("modifyUndone", &PyDbObjectReactor::modifyUndone)
        .def("modifiedXData", &PyDbObjectReactor::modifiedXData)
        .def("unappended", &PyDbObjectReactor::unappended)
        .def("reappended", &PyDbObjectReactor::reappended)
        .def("objectClosed", &PyDbObjectReactor::objectClosed)
        .def("desc", &PyDbObjectReactor::desc, DS.CLASSARGSSTATIC()).staticmethod("desc")
        .def("className", &PyDbObjectReactor::className, DS.CLASSARGSSTATIC()).staticmethod("className")
        ;
}

PyDbObjectReactor::PyDbObjectReactor()
    : PyRxObject(new PyDbObjectReactorImpl(this), true, false)
{
}

void PyDbObjectReactor::cancelled(const PyDbObject& pObj)
{
    if (!reg_cancelled)
        return;
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
    if (!reg_copied)
        return;
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

void PyDbObjectReactor::erased(const PyDbObject& src, bool bErasing)
{
    if (!reg_erased)
        return;
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
    if (!reg_goodbye)
        return;
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
    if (!reg_openedForModify)
        return;
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
    if (!reg_modified)
        return;
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
    if (!reg_subObjModified)
        return;
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
    if (!reg_modifyUndone)
        return;
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
    if (!reg_modifiedXData)
        return;
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
    if (!reg_unappended)
        return;
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
    if (!reg_reappended)
        return;
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
    if (!reg_objectClosed)
        return;
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
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbObjectReactor*>(m_pyImp.get());
}
