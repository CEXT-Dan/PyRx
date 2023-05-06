#include "stdafx.h"
#include "PyDbObject.h"
#include "PyDbDatabase.h"
#include "PyDbObjectId.h"
#include "ResultBuffer.h"
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
        .def("className", &PyDbObject::className).staticmethod("className")
        .def("close", &PyDbObject::close)
        .def("cancel", &PyDbObject::cancel)
        .def("handOverTo", &PyDbObject::handOverTo)
        .def("swapIdWith", &PyDbObject::swapIdWith)
        .def("setXData", &PyDbObject::setXData)
        .def("xData", &PyDbObject::xData)
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
    : PyGiDrawable(ptr, autoDelete, true)
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

Acad::ErrorStatus PyDbObject::erase()
{
    return impObj()->erase();
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

std::string PyDbObject::className()
{
    return "AcDbObject";
}

AcDbObject* PyDbObject::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbObject*>(m_pImp.get());
}

