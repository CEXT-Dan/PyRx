#include "stdafx.h"
#include "PyDbObject.h"
#include "PyDbDatabase.h"
#include "PyDbObjectId.h"

using namespace boost::python;

void makeAcDbObjectWrapper()
{
    static auto wrapper = class_<PyDbObject, bases<PyGiDrawable>>("DbObject", boost::python::no_init)
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("objectId", &PyDbObject::objectId)
        .def("ownerId", &PyDbObject::ownerId)
        .def("setOwnerId", &PyDbObject::setOwnerId)
        .def("database", &PyDbObject::database)

#ifdef NEVER
        .def("databaseToUse", &PyDbObject::databaseToUse)
        .def("intendedDatabase", &PyDbObject::intendedDatabase)
        .def("setIntendedDatabase", &PyDbObject::setIntendedDatabase)
#endif
        .def("createExtensionDictionary", &PyDbObject::createExtensionDictionary)
        .def("extensionDictionary", &PyDbObject::extensionDictionary)
        .def("releaseExtensionDictionary", &PyDbObject::releaseExtensionDictionary)
        .def("upgradeOpen", &PyDbObject::upgradeOpen)
        .def("upgradeFromNotify", &PyDbObject::upgradeFromNotify)
        .def("downgradeOpen", &PyDbObject::downgradeOpen)
        .def("downgradeToNotify", &PyDbObject::downgradeToNotify)
        .def("erase", &PyDbObject::erase)
        .def("className", &PyDbObject::className)
        .def("close", &PyDbObject::close)
        .def("cancel", &PyDbObject::cancel)
        .def("handOverTo", &PyDbObject::handOverTo)
        .def("swapIdWith", &PyDbObject::swapIdWith)
        .def("xDataTransformBy", &PyDbObject::xDataTransformBy)

        .def("isEraseStatusToggled", &PyDbObject::isEraseStatusToggled)
        .def("isErased", &PyDbObject::isErased)
        .def("isReadEnabled", &PyDbObject::isReadEnabled)
        .def("isWriteEnabled", &PyDbObject::isWriteEnabled)
        .def("isNotifyEnabled", &PyDbObject::isNotifyEnabled)
        .def("isModified", &PyDbObject::isModified)
        .def("isModifiedXData", &PyDbObject::isModifiedXData)
        .def("isModifiedGraphics", &PyDbObject::isModifiedGraphics)
        .def("isNewObject", &PyDbObject::isNewObject)
        .def("isNotifying", &PyDbObject::isNotifying)
        .def("isUndoing", &PyDbObject::isUndoing)
        .def("isCancelling", &PyDbObject::isCancelling)
        .def("isReallyClosing", &PyDbObject::isReallyClosing)
        .def("isTransactionResident", &PyDbObject::isTransactionResident)
        .def("isAProxy", &PyDbObject::isAProxy)
        .def("assertReadEnabled", &PyDbObject::assertReadEnabled)
        .def("assertWriteEnabled", &PyDbObject::assertWriteEnabled)
        .def("assertNotifyEnabled", &PyDbObject::assertNotifyEnabled)
        .def("isUndoRecordingDisabled", &PyDbObject::isUndoRecordingDisabled)
        .def("disableUndoRecording", &PyDbObject::disableUndoRecording)
        .def("addPersistentReactor", &PyDbObject::addPersistentReactor)
        .def("removePersistentReactor", &PyDbObject::removePersistentReactor)
        .def("hasPersistentReactor", &PyDbObject::hasPersistentReactor)
        ;
}

//-----------------------------------------------------------------------------------------
//PyDbObject
PyDbObject::PyDbObject(AcDbObject* ptr, bool autoDelete)
    : PyGiDrawable(ptr, autoDelete)
{
}

PyDbObject::PyDbObject(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyGiDrawable(nullptr, true)
{
    AcDbObject* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbObject>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    m_pImp = pobj;
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
}

PyDbObject::~PyDbObject()
{
    if (m_pImp != nullptr)
    {
        AcDbObject* pDbo = static_cast<AcDbObject*>(m_pImp);
        if (!pDbo->objectId().isNull())
        {
            pDbo->close();
            m_bAutoDelete = false;
        }
    }
}

PyDbObjectId PyDbObject::objectId() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(imp->objectId());
    throw PyNullObject();
}

PyDbObjectId PyDbObject::ownerId() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(imp->ownerId());
    throw PyNullObject();
}

Acad::ErrorStatus PyDbObject::setOwnerId(const PyDbObjectId& objId)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setOwnerId(objId.m_id);
    throw PyNullObject();
}

PyDbDatabase PyDbObject::database() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbDatabase(imp->database());
    throw PyNullObject();
}

#ifdef NEVER
PyDbDatabase PyDbObject::databaseToUse() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbDatabase(imp->databaseToUse());
    throw PyNullObject();
}

PyDbDatabase PyDbObject::intendedDatabase() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbDatabase(imp->intendedDatabase());
    throw PyNullObject();
}

Acad::ErrorStatus PyDbObject::setIntendedDatabase(const PyDbDatabase& db)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->setIntendedDatabase(db.impObj());
    throw PyNullObject();
}
#endif

Acad::ErrorStatus PyDbObject::createExtensionDictionary()
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->createExtensionDictionary();
    throw PyNullObject();
}

PyDbObjectId PyDbObject::extensionDictionary() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return PyDbObjectId(imp->extensionDictionary());
    throw PyNullObject();
}

Acad::ErrorStatus PyDbObject::releaseExtensionDictionary()
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->releaseExtensionDictionary();
    throw PyNullObject();
}

Acad::ErrorStatus PyDbObject::close()
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->close();
    throw PyNullObject();
}

Acad::ErrorStatus PyDbObject::upgradeOpen()
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->upgradeOpen();
    throw PyNullObject();
}

Acad::ErrorStatus PyDbObject::upgradeFromNotify(Adesk::Boolean& wasWritable)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->upgradeFromNotify(wasWritable);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbObject::downgradeOpen()
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->downgradeOpen();
    throw PyNullObject();
}

Acad::ErrorStatus PyDbObject::downgradeToNotify(Adesk::Boolean wasWritable)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->downgradeToNotify(wasWritable);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbObject::cancel()
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->cancel();
    throw PyNullObject();
}

Acad::ErrorStatus PyDbObject::erase()
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->erase();
    throw PyNullObject();
}

Acad::ErrorStatus PyDbObject::handOverTo(PyDbObject& newObject, Adesk::Boolean keepXData, Adesk::Boolean keepExtDict)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->handOverTo(newObject.impObj(), keepXData, keepExtDict);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbObject::swapIdWith(PyDbObjectId& otherId, Adesk::Boolean swapXdata, Adesk::Boolean swapExtDict)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->swapIdWith(otherId.m_id, swapXdata, swapExtDict);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbObject::xDataTransformBy(const AcGeMatrix3d& xform)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->xDataTransformBy(xform);
    throw PyNullObject();
}

Adesk::Boolean PyDbObject::isEraseStatusToggled() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->isEraseStatusToggled();
    throw PyNullObject();
}

Adesk::Boolean PyDbObject::isErased() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->isErased();
    throw PyNullObject();
}

Adesk::Boolean PyDbObject::isReadEnabled() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->isReadEnabled();
    throw PyNullObject();
}

Adesk::Boolean PyDbObject::isWriteEnabled() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->isWriteEnabled();
    throw PyNullObject();
}

Adesk::Boolean PyDbObject::isNotifyEnabled() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->isNotifyEnabled();
    throw PyNullObject();
}

Adesk::Boolean PyDbObject::isModified() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->isModified();
    throw PyNullObject();
}

Adesk::Boolean PyDbObject::isModifiedXData() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->isModifiedXData();
    throw PyNullObject();
}

Adesk::Boolean PyDbObject::isModifiedGraphics() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->isModifiedGraphics();
    throw PyNullObject();
}

Adesk::Boolean PyDbObject::isNewObject() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->isNewObject();
    throw PyNullObject();
}

Adesk::Boolean PyDbObject::isNotifying() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->isNotifying();
    throw PyNullObject();
}

Adesk::Boolean PyDbObject::isUndoing() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->isUndoing();
    throw PyNullObject();
}

Adesk::Boolean PyDbObject::isCancelling() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->isCancelling();
    throw PyNullObject();
}

Adesk::Boolean PyDbObject::isReallyClosing() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->isReallyClosing();
    throw PyNullObject();
}

Adesk::Boolean PyDbObject::isTransactionResident() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->isTransactionResident();
    throw PyNullObject();
}

Adesk::Boolean PyDbObject::isAProxy() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->isAProxy();
    throw PyNullObject();
}

void PyDbObject::assertReadEnabled() const
{
    auto imp = impObj();
    if (imp != nullptr)
        imp->assertReadEnabled();
    throw PyNullObject();
}

void PyDbObject::assertWriteEnabled()
{
    auto imp = impObj();
    if (imp != nullptr)
        imp->assertWriteEnabled();
    throw PyNullObject();
}

void PyDbObject::assertNotifyEnabled() const
{
    auto imp = impObj();
    if (imp != nullptr)
        imp->assertNotifyEnabled();
    throw PyNullObject();
}

bool PyDbObject::isUndoRecordingDisabled() const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->isUndoRecordingDisabled();
    throw PyNullObject();
}

void PyDbObject::disableUndoRecording(Adesk::Boolean disable)
{
    auto imp = impObj();
    if (imp != nullptr)
        imp->disableUndoRecording(disable);
    throw PyNullObject();
}

Acad::ErrorStatus PyDbObject::addPersistentReactor(const PyDbObjectId& objId)
{
#ifdef BRXAPP
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    imp->addPersistentReactor(objId.m_id);
    return eOk;
#else
    auto imp = impObj();
    if (imp != nullptr)
        return imp->addPersistentReactor(objId.m_id);
    throw PyNullObject();
#endif
}

Acad::ErrorStatus PyDbObject::removePersistentReactor(const PyDbObjectId& objId)
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->removePersistentReactor(objId.m_id);
    throw PyNullObject();
}

bool PyDbObject::hasPersistentReactor(const PyDbObjectId& objId) const
{
    auto imp = impObj();
    if (imp != nullptr)
        return imp->hasPersistentReactor(objId.m_id);
    throw PyNullObject();
}

std::string PyDbObject::className()
{
    return "AcDbObject";
}

AcDbObject* PyDbObject::impObj() const
{
    return static_cast<AcDbObject*>(m_pImp);
}
