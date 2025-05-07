#include "stdafx.h"
#include "PySmSheetSetMgr.h"


#if defined(_ARXTARGET) || defined(_BRXTARGET) 
#include "PySmSheetSetMgrImpl.h"
#include "PyDbObject.h"
#include "PyDbEval.h"
#include "PyDbDatabase.h"
#include "PyDbObjectId.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------------
//PySmObjectCast
template<typename T>
inline T PySmObjectCast(const PySmPersist& src)
{
    T dest(nullptr);
    PySmPersist rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

//-----------------------------------------------------------------------------------------
//PySmPersist
void makePySmPersistWrapper()
{
    PyDocString DS("Persist");
    class_<PySmPersist>("Persist", boost::python::no_init)
        .def("getIsDirty", &PySmPersist::getIsDirty, DS.ARGS())
        .def("getTypeName", &PySmPersist::getTypeName, DS.ARGS())
        .def("initNew", &PySmPersist::initNew, DS.ARGS({ "owner: PySm.Persist" }))
        .def("getOwner", &PySmPersist::getOwner, DS.ARGS())
        .def("setOwner", &PySmPersist::setOwner, DS.ARGS({ "owner: PySm.Persist" }))
        .def("getDatabase", &PySmPersist::getDatabase, DS.ARGS())
        .def("getObjectId", &PySmPersist::getObjectId, DS.ARGS())
        .def("clear", &PySmPersist::clear, DS.ARGS())
        .def("isNull", &PySmPersist::isNull, DS.ARGS())
        .def("cast", &PySmPersist::cast, DS.SARGS({ "otherObject: PySm.Persist" })).staticmethod("cast")
        .def("className", &PySmPersist::className, DS.SARGS()).staticmethod("className")
        ;
}

PySmPersist::PySmPersist(PySmPersistImpl* ptr)
{
    if (ptr != nullptr)
        m_pyImp.reset(new PySmPersistImpl(ptr->impObj()));
}

PySmPersist::PySmPersist(const PySmPersistImpl& other)
    : m_pyImp(new PySmPersistImpl(other))
{
}

bool PySmPersist::getIsDirty() const
{
    return impObj()->GetIsDirty();
}

std::string PySmPersist::getTypeName() const
{
    return wstr_to_utf8(impObj()->GetTypeName());
}

void PySmPersist::initNew(const PySmPersist& owner)
{
    impObj()->InitNew(*owner.impObj());
}

PySmPersist PySmPersist::getOwner() const
{
    return PySmPersist(impObj()->GetOwner());
}

void PySmPersist::setOwner(const PySmPersist& owner)
{
    impObj()->SetOwner(*owner.impObj());
}

PySmDatabase PySmPersist::getDatabase() const
{
    return PySmDatabase(impObj()->GetDatabase());
}

PySmObjectId PySmPersist::getObjectId() const
{
    return PySmObjectId(impObj()->GetObjectId());
}

void PySmPersist::clear()
{
    impObj()->Clear();
}

bool PySmPersist::isNull() const
{
    if (m_pyImp != nullptr)
        return impObj()->IsNull();
    return true;
}

PySmPersist PySmPersist::cast(const PySmPersist& src)
{
    return PySmObjectCast<PySmPersist>(src);
}

std::string PySmPersist::className()
{
    return "AcSmPersist";
}

PySmPersistImpl* PySmPersist::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}

//-----------------------------------------------------------------------------------------
//PySmAcDbDatabase
void makePySmAcDbDatabaseWrapper()
{
    PyDocString DS("DbDatabase");
    class_<PySmAcDbDatabase>("DbDatabase", boost::python::no_init)
        .def("getAcDbDatabase", &PySmAcDbDatabase::getAcDbDatabase, DS.ARGS())
        .def("className", &PySmAcDbDatabase::className, DS.SARGS()).staticmethod("className")
        ;
}

PySmAcDbDatabase::PySmAcDbDatabase(PySmAcDbDatabaseImpl* ptr)
{
    if (ptr != nullptr)
        m_pyImp.reset(new PySmAcDbDatabaseImpl(ptr->impObj()));
}

PySmAcDbDatabase::PySmAcDbDatabase(const PySmAcDbDatabaseImpl& other)
    : m_pyImp(new PySmAcDbDatabaseImpl(other))
{
}

PyDbDatabase PySmAcDbDatabase::getAcDbDatabase() const
{
    return PyDbDatabase(impObj()->GetAcDbDatabase());
}

std::string PySmAcDbDatabase::className()
{
    return "AcSmAcDbDatabase";
}

PySmAcDbDatabaseImpl* PySmAcDbDatabase::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}

//-----------------------------------------------------------------------------------------
//PySmObjectId
void makePySmObjectIdWrapper()
{
    PyDocString DS("ObjectId");
    class_<PySmObjectId>("ObjectId", boost::python::no_init)
        .def("getHandle", &PySmObjectId::getHandle, DS.ARGS())
        .def("getDatabase", &PySmObjectId::getDatabase, DS.ARGS())
        .def("getPersistObject", &PySmObjectId::getPersistObject, DS.ARGS())
        .def("getOwner", &PySmObjectId::getOwner, DS.ARGS())
        .def("isEqual", &PySmObjectId::isEqual, DS.ARGS({ "val: PySm.ObjectId" }))
        .def("isValid", &PySmObjectId::isValid, DS.ARGS())
        .def("className", &PySmObjectId::className, DS.SARGS()).staticmethod("className")
        ;
}

PySmObjectId::PySmObjectId(const PySmObjectIdImpl& other)
    : m_pyImp(new PySmObjectIdImpl(other))
{
}

std::string PySmObjectId::getHandle() const
{
    return wstr_to_utf8(impObj()->GetHandle());
}

PySmDatabase PySmObjectId::getDatabase() const
{
    return PySmDatabase(impObj()->GetDatabase());
}

PySmPersist PySmObjectId::getPersistObject() const
{
    return PySmPersist(impObj()->GetPersistObject());
}

PySmPersist PySmObjectId::getOwner() const
{
    return PySmPersist(impObj()->GetOwner());
}

bool PySmObjectId::isEqual(const PySmObjectId& other)
{
    return impObj()->IsEqual(*other.impObj());
}

bool PySmObjectId::isValid()
{
    return impObj()->IsValid();
}

std::string PySmObjectId::className()
{
    return "AcSmObjectId";
}

PySmObjectIdImpl* PySmObjectId::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}

//-----------------------------------------------------------------------------------------
//PySmCustomPropertyValue
void makePySmCustomPropertyValueWrapper()
{
    PyDocString DS("CustomPropertyValue");
    class_<PySmCustomPropertyValue, bases<PySmPersist>>("CustomPropertyValue")
        .def(init<>(DS.ARGS()))
        .def("getValue", &PySmCustomPropertyValue::getValue, DS.ARGS())
        .def("setValue", &PySmCustomPropertyValue::setValue1)
        .def("setValue", &PySmCustomPropertyValue::setValue2)
        .def("setValue", &PySmCustomPropertyValue::setValue3)
        .def("setValue", &PySmCustomPropertyValue::setValue4, DS.ARGS({ "val: PyDb.AcValue|str|int|float" }))
        .def("getFlags", &PySmCustomPropertyValue::getFlags, DS.ARGS())
        .def("setFlags", &PySmCustomPropertyValue::setFlags, DS.ARGS({ "flags: PySm.PropertyFlags" }))
        .def("cast", &PySmCustomPropertyValue::cast, DS.SARGS({ "otherObject: PySm.Persist" })).staticmethod("cast")
        .def("className", &PySmCustomPropertyValue::className, DS.SARGS()).staticmethod("className")
        ;

    enum_<SmPropertyFlags>("PropertyFlags")
        .value("kEmpty", SmPropertyFlags::EMPTY)
        .value("kSheetSetProp", SmPropertyFlags::CUSTOM_SHEETSET_PROP)
        .value("kSheetProp", SmPropertyFlags::CUSTOM_SHEET_PROP)
        .value("kSubSetProp", SmPropertyFlags::CUSTOM_SUBSET_PROP)
        .value("kIsChild", SmPropertyFlags::IS_CHILD)
        .export_values()
        ;

    enum_<SmObjectReferenceFlags>("ObjectReferenceFlags")
        .value("kSoftPointer", SmObjectReferenceFlags::AcSmObjectReference_SoftPointer)
        .value("kHardPointer", SmObjectReferenceFlags::AcSmObjectReference_HardPointer)
        .export_values()
        ;
}

PySmCustomPropertyValue::PySmCustomPropertyValue()
    : PySmCustomPropertyValue(new PySmCustomPropertyValueImpl())
{
}

PySmCustomPropertyValue::PySmCustomPropertyValue(PySmCustomPropertyValueImpl* ptr)
    : PySmPersist(ptr)
{
}

PySmCustomPropertyValue::PySmCustomPropertyValue(const PySmCustomPropertyValueImpl& other)
    : PySmPersist(other)
{
}

PyDbAcValue PySmCustomPropertyValue::getValue() const
{
    return PyDbAcValue(impObj()->GetValue());
}

void PySmCustomPropertyValue::setValue1(const PyDbAcValue& acVal)
{
    impObj()->SetValue(*acVal.impObj());
}

void PySmCustomPropertyValue::setValue2(const std::string& str)
{
    AcValue val{ utf8_to_wstr(str).c_str() };
    impObj()->SetValue(val);
}

void PySmCustomPropertyValue::setValue3(int ival)
{
    AcValue acval{ Adesk::Int32(ival) };
    impObj()->SetValue(acval);
}

void PySmCustomPropertyValue::setValue4(double fval)
{
    AcValue val{ fval };
    impObj()->SetValue(val);
}

SmPropertyFlags PySmCustomPropertyValue::getFlags() const
{
    return static_cast<SmPropertyFlags>(impObj()->GetFlags());
}

void PySmCustomPropertyValue::setFlags(SmPropertyFlags flags)
{
    impObj()->SetFlags(static_cast<PropertyFlags>(flags));
}

PySmCustomPropertyValue PySmCustomPropertyValue::cast(const PySmPersist& src)
{
    return PySmObjectCast<PySmCustomPropertyValue>(src);
}

std::string PySmCustomPropertyValue::className()
{
    return "AcSmCustomPropertyValue";
}

PySmCustomPropertyValueImpl* PySmCustomPropertyValue::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PySmCustomPropertyValueImpl*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PySmCustomPropertyBag
void makePySmCustomPropertyBagWrapper()
{
    PyDocString DS("CustomPropertyBag");
    class_<PySmCustomPropertyBag, bases<PySmPersist>>("CustomPropertyBag")
        .def(init<>(DS.ARGS()))
        .def("hasProperty", &PySmCustomPropertyBag::hasProperty, DS.ARGS({ "prop: str" }))
        .def("getProperty", &PySmCustomPropertyBag::getProperty, DS.ARGS({ "prop: str" }))
        .def("setProperty", &PySmCustomPropertyBag::setProperty, DS.ARGS({ "prop: str" ,"val: PySm.CustomPropertyValue" }))
        .def("getProperties", &PySmCustomPropertyBag::getProperties, DS.ARGS())
        .def("getPropertyValues", &PySmCustomPropertyBag::getPropertyValues, DS.ARGS())
        .def("cast", &PySmCustomPropertyBag::cast, DS.SARGS({ "otherObject: PySm.Persist" })).staticmethod("cast")
        .def("className", &PySmCustomPropertyBag::className, DS.SARGS()).staticmethod("className")
        ;
}

PySmCustomPropertyBag::PySmCustomPropertyBag()
    : PySmCustomPropertyBag(new PySmCustomPropertyBagImpl())
{
}

PySmCustomPropertyBag::PySmCustomPropertyBag(PySmCustomPropertyBagImpl* ptr)
    : PySmPersist(ptr)
{
}

PySmCustomPropertyBag::PySmCustomPropertyBag(const PySmCustomPropertyBagImpl& other)
    : PySmPersist(other)
{
}

bool PySmCustomPropertyBag::hasProperty(const std::string& propName) const
{
    for (const auto& i : impObj()->GetProperties())
    {
        if (i.first.CompareNoCase(utf8_to_wstr(propName).c_str()) == 0)
            return true;
    }
    return false;
}

PySmCustomPropertyValue PySmCustomPropertyBag::getProperty(const std::string& propName) const
{
    return PySmCustomPropertyValue(impObj()->GetProperty(utf8_to_wstr(propName).c_str()));
}

void PySmCustomPropertyBag::setProperty(const std::string& propName, const PySmCustomPropertyValue& prop)
{
    impObj()->SetProperty(utf8_to_wstr(propName).c_str(), *prop.impObj());
}

boost::python::list PySmCustomPropertyBag::getProperties() const
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (const auto& i : impObj()->GetProperties())
        pylist.append(boost::python::make_tuple(wstr_to_utf8(i.first), PySmCustomPropertyValue(i.second)));
    return pylist;
}

boost::python::list PySmCustomPropertyBag::getPropertyValues() const
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (const auto& i : impObj()->GetPropertyValues())
        pylist.append(boost::python::make_tuple(wstr_to_utf8(i.first), PyDbAcValue(i.second)));
    return pylist;
}

PySmCustomPropertyBag PySmCustomPropertyBag::cast(const PySmPersist& src)
{
    return PySmObjectCast<PySmCustomPropertyBag>(src);
}

std::string PySmCustomPropertyBag::className()
{
    return "AcSmCustomPropertyBag";
}

PySmCustomPropertyBagImpl* PySmCustomPropertyBag::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PySmCustomPropertyBagImpl*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PySmFileReference
void makePySmFileReferenceWrapper()
{
    PyDocString DS("FileReference");
    class_<PySmFileReference, bases<PySmPersist>>("FileReference")
        .def(init<>(DS.ARGS()))
        .def("setFileName", &PySmFileReference::setFileName, DS.ARGS({ "fname: str" }))
        .def("getFileName", &PySmFileReference::getFileName, DS.ARGS())
        .def("getFileName", &PySmFileReference::resolveFileName, DS.ARGS())
        .def("cast", &PySmFileReference::cast, DS.SARGS({ "otherObject: PySm.Persist" })).staticmethod("cast")
        .def("className", &PySmFileReference::className, DS.SARGS()).staticmethod("className")
        ;
}

PySmFileReference::PySmFileReference()
    : PySmFileReference(new PySmFileReferenceImpl())
{
}

PySmFileReference::PySmFileReference(PySmFileReferenceImpl* ptr)
    : PySmPersist(ptr)
{
}

PySmFileReference::PySmFileReference(const PySmFileReferenceImpl& other)
    : PySmPersist(other)
{
}

void PySmFileReference::setFileName(const std::string& csVal)
{
    impObj()->SetFileName(utf8_to_wstr(csVal).c_str());
}

std::string PySmFileReference::getFileName() const
{
    return wstr_to_utf8(impObj()->GetFileName());
}

std::string PySmFileReference::resolveFileName() const
{
    return wstr_to_utf8(impObj()->ResolveFileName());
}

PySmFileReference PySmFileReference::cast(const PySmPersist& src)
{
    return PySmObjectCast<PySmFileReference>(src);
}

std::string PySmFileReference::className()
{
    return "AcSmFileReference";
}

PySmFileReferenceImpl* PySmFileReference::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PySmFileReferenceImpl*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PySmAcDbObjectReference
void makePySmAcDbObjectReferenceWrapper()
{
    PyDocString DS("DbObjectReference");
    class_<PySmAcDbObjectReference, bases<PySmFileReference>>("DbObjectReference")
        .def(init<>(DS.ARGS()))
        .def("setAcDbHandle", &PySmAcDbObjectReference::setAcDbHandle, DS.ARGS({ "handle: PyDb.Handle" }))
        .def("getAcDbHandle", &PySmAcDbObjectReference::getAcDbHandle, DS.ARGS())
        .def("getAcSmAcDbDatabase", &PySmAcDbObjectReference::getAcSmAcDbDatabase, DS.ARGS())
        .def("setAcDbObject", &PySmAcDbObjectReference::setAcDbObject, DS.ARGS({ "obj: PyDb.Object" }))
        .def("resolveAcDbObject", &PySmAcDbObjectReference::resolveAcDbObject, DS.ARGS({ "db: PyDb.Database" }))
        .def("cast", &PySmAcDbObjectReference::cast, DS.SARGS({ "otherObject: PySm.Persist" })).staticmethod("cast")
        .def("className", &PySmAcDbObjectReference::className, DS.SARGS()).staticmethod("className")
        ;
}

PySmAcDbObjectReference::PySmAcDbObjectReference()
    : PySmAcDbObjectReference(new PySmAcDbObjectReferenceImpl())
{
}

PySmAcDbObjectReference::PySmAcDbObjectReference(PySmAcDbObjectReferenceImpl* ptr)
    : PySmFileReference(ptr)
{
}

PySmAcDbObjectReference::PySmAcDbObjectReference(const PySmAcDbObjectReferenceImpl& other)
    : PySmFileReference(other)
{
}

PySmAcDbObjectReference PySmAcDbObjectReference::cast(const PySmPersist& src)
{
    return PySmObjectCast<PySmAcDbObjectReference>(src);
}

void PySmAcDbObjectReference::setAcDbHandle(PyDbHandle& hwnd)
{
    impObj()->SetAcDbHandle(hwnd.m_hnd);
}

PyDbHandle PySmAcDbObjectReference::getAcDbHandle() const
{
    return PyDbHandle(impObj()->GetAcDbHandle());
}

PySmAcDbDatabase PySmAcDbObjectReference::getAcSmAcDbDatabase() const
{
    return PySmAcDbDatabase(impObj()->GetAcSmAcDbDatabase());
}

void PySmAcDbObjectReference::setAcDbObject(PyDbObject& pDbObj)
{
    impObj()->SetAcDbObject(pDbObj.impObj());
}

PyDbHandle PySmAcDbObjectReference::resolveAcDbObject(PyDbDatabase& pDb)
{
    return PyDbHandle(impObj()->ResolveAcDbObject(pDb.impObj()));
}

std::string PySmAcDbObjectReference::className()
{
    return "AcSmAcDbObjectReference";
}

PySmAcDbObjectReferenceImpl* PySmAcDbObjectReference::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PySmAcDbObjectReferenceImpl*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PySmNamedAcDbObjectReference
void makePySmNamedAcDbObjectReferenceWrapper()
{
    PyDocString DS("NamedDbObjectReference");
    class_<PySmNamedAcDbObjectReference, bases<PySmAcDbObjectReference>>("NamedDbObjectReference")
        .def(init<>(DS.ARGS()))
        .def("setName", &PySmNamedAcDbObjectReference::setName, DS.ARGS({ "val: str" }))
        .def("getName", &PySmNamedAcDbObjectReference::getName, DS.ARGS())
        .def("setOwnerAcDbHandle", &PySmNamedAcDbObjectReference::SetOwnerAcDbHandle, DS.ARGS({ "val: PyDb.Handle" }))
        .def("getOwnerAcDbHandle", &PySmNamedAcDbObjectReference::GetOwnerAcDbHandle, DS.ARGS())
        .def("cast", &PySmNamedAcDbObjectReference::cast, DS.SARGS({ "otherObject: PySm.Persist" })).staticmethod("cast")
        .def("className", &PySmNamedAcDbObjectReference::className, DS.SARGS()).staticmethod("className")
        ;
}

PySmNamedAcDbObjectReference::PySmNamedAcDbObjectReference()
    : PySmNamedAcDbObjectReference(new PySmNamedAcDbObjectReferenceImpl())
{
}

PySmNamedAcDbObjectReference::PySmNamedAcDbObjectReference(PySmNamedAcDbObjectReferenceImpl* ptr)
    : PySmAcDbObjectReference(ptr)
{
}

PySmNamedAcDbObjectReference::PySmNamedAcDbObjectReference(const PySmNamedAcDbObjectReferenceImpl& other)
    : PySmAcDbObjectReference(other)
{
}

PySmNamedAcDbObjectReference PySmNamedAcDbObjectReference::cast(const PySmPersist& src)
{
    return PySmObjectCast<PySmNamedAcDbObjectReference>(src);
}

std::string PySmNamedAcDbObjectReference::getName() const
{
    return wstr_to_utf8(impObj()->GetName());
}

void PySmNamedAcDbObjectReference::setName(const std::string& val)
{
    return impObj()->SetName(utf8_to_wstr(val).c_str());
}

void PySmNamedAcDbObjectReference::SetOwnerAcDbHandle(PyDbHandle& hwnd)
{
    impObj()->SetOwnerAcDbHandle(hwnd.m_hnd);
}

PyDbHandle PySmNamedAcDbObjectReference::GetOwnerAcDbHandle() const
{
    return PyDbHandle(impObj()->GetOwnerAcDbHandle());
}

std::string PySmNamedAcDbObjectReference::className()
{
    return "AcSmNamedAcDbObjectReference";
}

PySmNamedAcDbObjectReferenceImpl* PySmNamedAcDbObjectReference::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PySmNamedAcDbObjectReferenceImpl*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PySmAcDbLayoutReference
void makePySmAcDbLayoutReferenceWrapper()
{
    PyDocString DS("DbLayoutReference");
    class_<PySmAcDbLayoutReference, bases<PySmNamedAcDbObjectReference>>("DbLayoutReference")
        .def(init<>(DS.ARGS()))
        .def("cast", &PySmAcDbLayoutReference::cast, DS.SARGS({ "otherObject: PySm.Persist" })).staticmethod("cast")
        .def("className", &PySmAcDbLayoutReference::className, DS.SARGS()).staticmethod("className")
        ;
}

PySmAcDbLayoutReference::PySmAcDbLayoutReference()
    : PySmAcDbLayoutReference(new PySmAcDbLayoutReferenceImpl())
{
}

PySmAcDbLayoutReference::PySmAcDbLayoutReference(PySmAcDbLayoutReferenceImpl* ptr)
    : PySmNamedAcDbObjectReference(ptr)
{
}

PySmAcDbLayoutReference::PySmAcDbLayoutReference(const PySmAcDbLayoutReferenceImpl& other)
    : PySmNamedAcDbObjectReference(other)
{
}

PySmAcDbLayoutReference PySmAcDbLayoutReference::cast(const PySmPersist& src)
{
    return PySmObjectCast<PySmAcDbLayoutReference>(src);
}

std::string PySmAcDbLayoutReference::className()
{
    return "AcSmAcDbLayoutReference";
}

PySmAcDbLayoutReferenceImpl* PySmAcDbLayoutReference::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PySmAcDbLayoutReferenceImpl*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PySmAcDbViewReference
void makePySmAcDbViewReferenceWrapper()
{
    PyDocString DS("DbViewReference");
    class_<PySmAcDbViewReference, bases<PySmNamedAcDbObjectReference>>("DbViewReference")
        .def(init<>(DS.ARGS()))
        .def("cast", &PySmAcDbViewReference::cast, DS.SARGS({ "otherObject: PySm.Persist" })).staticmethod("cast")
        .def("className", &PySmAcDbViewReference::className, DS.SARGS()).staticmethod("className")
        ;
}

PySmAcDbViewReference::PySmAcDbViewReference()
    : PySmAcDbViewReference(new PySmAcDbViewReferenceImpl())
{
}

PySmAcDbViewReference::PySmAcDbViewReference(PySmAcDbViewReferenceImpl* ptr)
    : PySmNamedAcDbObjectReference(ptr)
{
}

PySmAcDbViewReference::PySmAcDbViewReference(const PySmAcDbViewReferenceImpl& other)
    : PySmNamedAcDbObjectReference(other)
{
}

PySmAcDbViewReference PySmAcDbViewReference::cast(const PySmPersist& src)
{
    return PySmObjectCast<PySmAcDbViewReference>(src);
}

std::string PySmAcDbViewReference::className()
{
    return "AcSmAcDbLayoutReference";
}

PySmAcDbViewReferenceImpl* PySmAcDbViewReference::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PySmAcDbViewReferenceImpl*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PySmAcDbBlockRecordReference
void makePySmAcDbBlockRecordReferenceWrapper()
{
    PyDocString DS("DbBlockRecordReference");
    class_<PySmAcDbBlockRecordReference, bases<PySmNamedAcDbObjectReference>>("DbBlockRecordReference")
        .def(init<>(DS.ARGS()))
        .def("cast", &PySmAcDbBlockRecordReference::cast, DS.SARGS({ "otherObject: PySm.Persist" })).staticmethod("cast")
        .def("className", &PySmAcDbBlockRecordReference::className, DS.SARGS()).staticmethod("className")
        ;
}

PySmAcDbBlockRecordReference::PySmAcDbBlockRecordReference()
    : PySmAcDbBlockRecordReference(new PySmAcDbBlockRecordReferenceImpl())
{
}

PySmAcDbBlockRecordReference::PySmAcDbBlockRecordReference(PySmAcDbBlockRecordReferenceImpl* ptr)
    : PySmNamedAcDbObjectReference(ptr)
{
}

PySmAcDbBlockRecordReference::PySmAcDbBlockRecordReference(const PySmAcDbBlockRecordReferenceImpl& other)
    : PySmNamedAcDbObjectReference(other)
{
}

PySmAcDbBlockRecordReference PySmAcDbBlockRecordReference::cast(const PySmPersist& src)
{
    return PySmObjectCast<PySmAcDbBlockRecordReference>(src);
}

std::string PySmAcDbBlockRecordReference::className()
{
    return "AcSmAcDbBlockRecordReference";
}

PySmAcDbBlockRecordReferenceImpl* PySmAcDbBlockRecordReference::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PySmAcDbBlockRecordReferenceImpl*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PySmProjectPointLocation
void makePySmProjectPointLocationWrapper()
{
    PyDocString DS("ProjectPointLocation");
    class_<PySmProjectPointLocation, bases<PySmPersist>>("ProjectPointLocation")
        .def(init<>(DS.ARGS()))
        .def("getURL", &PySmProjectPointLocation::getURL, DS.ARGS())
        .def("getURL", &PySmProjectPointLocation::setURL, DS.ARGS({ "val: str" }))
        .def("getFolder", &PySmProjectPointLocation::getFolder, DS.ARGS())
        .def("setFolder", &PySmProjectPointLocation::setFolder, DS.ARGS({ "val: str" }))
        .def("getUsername", &PySmProjectPointLocation::getUsername, DS.ARGS())
        .def("setUsername", &PySmProjectPointLocation::setUsername, DS.ARGS({ "val: str" }))
        .def("getPassword", &PySmProjectPointLocation::getPassword, DS.ARGS())
        .def("setPassword", &PySmProjectPointLocation::setPassword, DS.ARGS({ "val: str" }))
        .def("getResourceType", &PySmProjectPointLocation::getResourceType, DS.ARGS())
        .def("setResourceType", &PySmProjectPointLocation::setResourceType, DS.ARGS({ "val: int" }))
        .def("cast", &PySmProjectPointLocation::cast, DS.SARGS({ "otherObject: PySm.Persist" })).staticmethod("cast")
        .def("className", &PySmProjectPointLocation::className, DS.SARGS()).staticmethod("className")
        ;
}

PySmProjectPointLocation::PySmProjectPointLocation()
    : PySmProjectPointLocation(new PySmProjectPointLocationImpl())
{
}

PySmProjectPointLocation::PySmProjectPointLocation(PySmProjectPointLocationImpl* ptr)
    : PySmPersist(ptr)
{
}

PySmProjectPointLocation::PySmProjectPointLocation(const PySmProjectPointLocationImpl& other)
    : PySmPersist(other)
{
}

std::string PySmProjectPointLocation::getURL() const
{
    return wstr_to_utf8(impObj()->GetURL());
}

void PySmProjectPointLocation::setURL(const std::string& csVal)
{
    impObj()->SetURL(utf8_to_wstr(csVal).c_str());
}

std::string PySmProjectPointLocation::getFolder() const
{
    return wstr_to_utf8(impObj()->GetFolder());
}

void PySmProjectPointLocation::setFolder(const std::string& csVal)
{
    impObj()->SetFolder(utf8_to_wstr(csVal).c_str());
}

std::string PySmProjectPointLocation::getUsername() const
{
    return wstr_to_utf8(impObj()->GetUsername());
}

void PySmProjectPointLocation::setUsername(const std::string& csVal)
{
    impObj()->SetUsername(utf8_to_wstr(csVal).c_str());
}

std::string PySmProjectPointLocation::getPassword() const
{
    return wstr_to_utf8(impObj()->GetPassword());
}

void PySmProjectPointLocation::setPassword(const std::string& csVal)
{
    impObj()->SetPassword(utf8_to_wstr(csVal).c_str());
}

long PySmProjectPointLocation::getResourceType() const
{
    return impObj()->GetResourceType();
}

void PySmProjectPointLocation::setResourceType(long val)
{
    impObj()->SetResourceType(val);
}

PySmProjectPointLocation PySmProjectPointLocation::cast(const PySmPersist& src)
{
    return PySmObjectCast<PySmProjectPointLocation>(src);
}

std::string PySmProjectPointLocation::className()
{
    return "AcSmProjectPointLocation";
}

PySmProjectPointLocationImpl* PySmProjectPointLocation::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PySmProjectPointLocationImpl*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PySmObjectReference
void makePySmObjectReferenceWrapper()
{
    PyDocString DS("ObjectReference");
    class_<PySmObjectReference, bases<PySmPersist>>("ObjectReference")
        .def(init<>(DS.ARGS()))
        .def("setReferencedObject", &PySmObjectReference::setReferencedObject, DS.ARGS({ "val: PySm.Persist" }))
        .def("getReferencedObject", &PySmObjectReference::getReferencedObject, DS.ARGS())
        .def("setReferenceFlags", &PySmObjectReference::setReferenceFlags, DS.ARGS({ "val: PySm.ObjectReferenceFlags" }))
        .def("getReferenceFlags", &PySmObjectReference::getReferenceFlags, DS.ARGS())
        .def("cast", &PySmObjectReference::cast, DS.SARGS({ "otherObject: PySm.Persist" })).staticmethod("cast")
        .def("className", &PySmObjectReference::className, DS.SARGS()).staticmethod("className")
        ;
}

PySmObjectReference::PySmObjectReference()
    : PySmObjectReference(new PySmObjectReferenceImpl())
{
}

PySmObjectReference::PySmObjectReference(PySmObjectReferenceImpl* ptr)
    : PySmPersist(ptr)
{
}

PySmObjectReference::PySmObjectReference(const PySmObjectReferenceImpl& other)
    : PySmPersist(other)
{
}

void PySmObjectReference::setReferencedObject(PySmPersist& pObject)
{
    impObj()->SetReferencedObject(*pObject.impObj());
}

PySmPersist PySmObjectReference::getReferencedObject() const
{
    return PySmPersist(impObj()->GetReferencedObject());
}

SmObjectReferenceFlags PySmObjectReference::getReferenceFlags() const
{
    return static_cast<SmObjectReferenceFlags>(impObj()->GetReferenceFlags());
}

void PySmObjectReference::setReferenceFlags(SmObjectReferenceFlags flags)
{
    impObj()->SetReferenceFlags(static_cast<AcSmObjectReferenceFlags>(flags));
}

PySmObjectReference PySmObjectReference::cast(const PySmPersist& src)
{
    return PySmObjectCast<PySmObjectReference>(src);
}

std::string PySmObjectReference::className()
{
    return "AcSmObjectReference";
}

PySmObjectReferenceImpl* PySmObjectReference::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PySmObjectReferenceImpl*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PySmPersistProxy
void makePySmPersistProxyWrapper()
{
    PyDocString DS("PersistProxy");
    class_<PySmPersistProxy, bases<PySmPersist>>("PersistProxy")
        .def(init<>(DS.ARGS()))
        .def("cast", &PySmPersistProxy::cast, DS.SARGS({ "otherObject: PySm.Persist" })).staticmethod("cast")
        .def("className", &PySmPersistProxy::className, DS.SARGS()).staticmethod("className")
        ;
}

PySmPersistProxy::PySmPersistProxy()
    : PySmPersistProxy(new PySmPersistProxyImpl())
{
}

PySmPersistProxy::PySmPersistProxy(PySmPersistProxyImpl* ptr)
    : PySmPersist(ptr)
{
}

PySmPersistProxy::PySmPersistProxy(const PySmPersistProxyImpl& other)
    : PySmPersist(other)
{
}

PySmPersistProxy PySmPersistProxy::cast(const PySmPersist& src)
{
    return PySmObjectCast<PySmPersistProxy>(src);
}

std::string PySmPersistProxy::className()
{
    return "AcSmPersistProxy";
}

PySmPersistProxyImpl* PySmPersistProxy::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PySmPersistProxyImpl*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PySmPublishOption
void makePySmPublishOptionsWrapper()
{
    PyDocString DS("PublishOptions");
    class_<PySmPublishOptions, bases<PySmPersist>>("PublishOptions")
        .def(init<>(DS.ARGS()))
        .def("getDefaultOutputdir", &PySmPublishOptions::getDefaultOutputdir, DS.ARGS())
        .def("setDefaultOutputdir", &PySmPublishOptions::setDefaultOutputdir, DS.ARGS({ "val: PySm.FileReference" }))
        .def("getDwfType", &PySmPublishOptions::getDwfType, DS.ARGS())
        .def("setDwfType", &PySmPublishOptions::setDwfType, DS.ARGS({ "val: bool" }))
        .def("getPromptForName", &PySmPublishOptions::getPromptForName, DS.ARGS())
        .def("setPromptForName", &PySmPublishOptions::setPromptForName, DS.ARGS({ "val: bool" }))
        .def("getUsePassword", &PySmPublishOptions::getUsePassword, DS.ARGS())
        .def("setUsePassword", &PySmPublishOptions::setUsePassword, DS.ARGS({ "val: bool" }))
        .def("getPromptForPassword", &PySmPublishOptions::getPromptForPassword, DS.ARGS())
        .def("setPromptForPassword", &PySmPublishOptions::setPromptForPassword, DS.ARGS({ "val: bool" }))
        .def("getLayerInfo", &PySmPublishOptions::getLayerInfo, DS.ARGS())
        .def("setLayerInfo", &PySmPublishOptions::setLayerInfo, DS.ARGS({ "val: bool" }))
        .def("getUnrecognizedData", &PySmPublishOptions::getUnrecognizedData, DS.ARGS())
        .def("setUnrecognizedData", &PySmPublishOptions::setUnrecognizedData, DS.ARGS({ "val: PySm.CustomPropertyBag" }))
        .def("getUnrecognizedSections", &PySmPublishOptions::getUnrecognizedSections, DS.ARGS())
        .def("setUnrecognizedSections", &PySmPublishOptions::setUnrecognizedSections, DS.ARGS({ "val: PySm.CustomPropertyBag" }))
        .def("getIncludeSheetSetData", &PySmPublishOptions::getIncludeSheetSetData, DS.ARGS())
        .def("setIncludeSheetSetData", &PySmPublishOptions::setIncludeSheetSetData, DS.ARGS({ "val: bool" }))
        .def("getIncludeSheetData", &PySmPublishOptions::getIncludeSheetData, DS.ARGS())
        .def("setIncludeSheetData", &PySmPublishOptions::setIncludeSheetData, DS.ARGS({ "val: bool" }))
        .def("getEplotFormat", &PySmPublishOptions::getEplotFormat, DS.ARGS())
        .def("setEplotFormat", &PySmPublishOptions::setEplotFormat, DS.ARGS({ "val: int" }))
        .def("getLinesMerge", &PySmPublishOptions::getLinesMerge, DS.ARGS())
        .def("setLinesMerge", &PySmPublishOptions::setLinesMerge, DS.ARGS({ "val: bool" }))
        .def("getDefaultFilename", &PySmPublishOptions::getDefaultFilename, DS.ARGS())
        .def("setDefaultFilename", &PySmPublishOptions::setDefaultFilename, DS.ARGS({ "val: str" }))
        .def("cast", &PySmPublishOptions::cast, DS.SARGS({ "otherObject: PySm.Persist" })).staticmethod("cast")
        .def("className", &PySmPublishOptions::className, DS.SARGS()).staticmethod("className")
        ;
}

PySmPublishOptions::PySmPublishOptions()
    : PySmPublishOptions(new PySmPublishOptionsImpl())
{
}

PySmPublishOptions::PySmPublishOptions(PySmPublishOptionsImpl* ptr)
    : PySmPersist(ptr)
{
}

PySmPublishOptions::PySmPublishOptions(const PySmPublishOptionsImpl& other)
    : PySmPersist(other)
{
}

PySmFileReference PySmPublishOptions::getDefaultOutputdir() const
{
    return PySmFileReference(impObj()->GetDefaultOutputdir());
}

void PySmPublishOptions::setDefaultOutputdir(PySmFileReference& val)
{
    impObj()->SetDefaultOutputdir(*val.impObj());
}

bool PySmPublishOptions::getDwfType() const
{
    return impObj()->GetDwfType();
}

void PySmPublishOptions::setDwfType(bool val)
{
    impObj()->SetDwfType(val);
}

bool PySmPublishOptions::getPromptForName() const
{
    return impObj()->GetPromptForName();
}

void PySmPublishOptions::setPromptForName(bool val)
{
    impObj()->SetPromptForName(val);
}

bool PySmPublishOptions::getUsePassword() const
{
    return impObj()->GetUsePassword();
}

void PySmPublishOptions::setUsePassword(bool val)
{
    impObj()->SetUsePassword(val);
}

bool PySmPublishOptions::getPromptForPassword() const
{
    return impObj()->GetPromptForPassword();
}

void PySmPublishOptions::setPromptForPassword(bool val)
{
    impObj()->SetPromptForPassword(val);
}

bool PySmPublishOptions::getLayerInfo() const
{
    return impObj()->GetLayerInfo();
}

void PySmPublishOptions::setLayerInfo(bool val)
{
    impObj()->SetLayerInfo(val);
}

PySmCustomPropertyBag PySmPublishOptions::getUnrecognizedData() const
{
    return PySmCustomPropertyBag(impObj()->GetUnrecognizedData());
}

void PySmPublishOptions::setUnrecognizedData(PySmCustomPropertyBag& val)
{
    impObj()->SetUnrecognizedData(*val.impObj());
}

PySmCustomPropertyBag PySmPublishOptions::getUnrecognizedSections() const
{
    return PySmCustomPropertyBag(impObj()->GetUnrecognizedSections());
}

void PySmPublishOptions::setUnrecognizedSections(PySmCustomPropertyBag& val)
{
    impObj()->SetUnrecognizedSections(*val.impObj());
}

bool PySmPublishOptions::getIncludeSheetSetData() const
{
    return impObj()->GetIncludeSheetSetData();
}

void PySmPublishOptions::setIncludeSheetSetData(bool val)
{
    impObj()->SetIncludeSheetSetData(val);
}

bool PySmPublishOptions::getIncludeSheetData() const
{
    return impObj()->GetIncludeSheetData();
}

void PySmPublishOptions::setIncludeSheetData(bool val)
{
    impObj()->SetIncludeSheetData(val);
}

long PySmPublishOptions::getEplotFormat() const
{
    return impObj()->GetEplotFormat();
}

void PySmPublishOptions::setEplotFormat(long val)
{
    impObj()->SetEplotFormat(val);
}

bool PySmPublishOptions::getLinesMerge() const
{
    return impObj()->GetLinesMerge();
}

void PySmPublishOptions::setLinesMerge(bool val)
{
    impObj()->SetLinesMerge(val);
}

std::string PySmPublishOptions::getDefaultFilename() const
{
    return wstr_to_utf8(impObj()->GetDefaultFilename());
}

void PySmPublishOptions::setDefaultFilename(const std::string& csVal)
{
    impObj()->SetDefaultFilename(utf8_to_wstr(csVal).c_str());
}

PySmPublishOptions PySmPublishOptions::cast(const PySmPersist& src)
{
    return PySmObjectCast<PySmPublishOptions>(src);
}

std::string PySmPublishOptions::className()
{
    return "AcSmPublishOptions";
}

PySmPublishOptionsImpl* PySmPublishOptions::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PySmPublishOptionsImpl*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PySmComponent
void makePySmComponentWrapper()
{
    PyDocString DS("Component");
    class_<PySmComponent, bases<PySmPersist>>("Component", boost::python::no_init)
        .def("getName", &PySmComponent::getName, DS.ARGS())
        .def("setName", &PySmComponent::setName, DS.ARGS({ "name: str" }))
        .def("getDesc", &PySmComponent::getDesc, DS.ARGS())
        .def("setDesc", &PySmComponent::setDesc, DS.ARGS({ "desc: str" }))
        .def("getCustomPropertyBag", &PySmComponent::getCustomPropertyBag, DS.ARGS())
        .def("cast", &PySmComponent::cast, DS.SARGS({ "otherObject: PySm.Persist" })).staticmethod("cast")
        .def("className", &PySmComponent::className, DS.SARGS()).staticmethod("className")
        ;
}

PySmComponent::PySmComponent(PySmComponentImpl* ptr)
    : PySmPersist(ptr)
{
}

PySmComponent::PySmComponent(const PySmComponentImpl& other)
    : PySmPersist(other)
{
}

std::string PySmComponent::getName() const
{
    return wstr_to_utf8(impObj()->GetName());
}

void PySmComponent::setName(const std::string& csName)
{
    impObj()->SetName(utf8_to_wstr(csName).c_str());
}

std::string PySmComponent::getDesc() const
{
    return wstr_to_utf8(impObj()->GetDesc());
}

void PySmComponent::setDesc(const std::string& csDesc)
{
    impObj()->SetDesc(utf8_to_wstr(csDesc).c_str());
}

PySmCustomPropertyBag PySmComponent::getCustomPropertyBag() const
{
    return PySmCustomPropertyBag(impObj()->GetCustomPropertyBag());
}

PySmComponent PySmComponent::cast(const PySmPersist& src)
{
    return PySmObjectCast<PySmComponent>(src);
}

std::string PySmComponent::className()
{
    return "AcSmComponent";
}

PySmComponentImpl* PySmComponent::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PySmComponentImpl*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PycSmSheetSelSet
void makePySmSheetSelSetWrapper()
{
    PyDocString DS("SheetSelSet");
    class_<PySmSheetSelSet, bases<PySmComponent>>("SheetSelSet")
        .def(init<>(DS.ARGS()))
        .def("add", &PySmSheetSelSet::add, DS.ARGS({ "val: PySm.Component" }))
        .def("remove", &PySmSheetSelSet::remove, DS.ARGS())
        .def("getComponents", &PySmSheetSelSet::getComponents, DS.ARGS())
        .def("cast", &PySmSheetSelSet::cast, DS.SARGS({ "otherObject: PySm.Persist" })).staticmethod("cast")
        .def("className", &PySmSheetSelSet::className, DS.SARGS()).staticmethod("className")
        ;
}

PySmSheetSelSet::PySmSheetSelSet()
    : PySmSheetSelSet(new PySmSheetSelSetImpl())
{
}

PySmSheetSelSet::PySmSheetSelSet(PySmSheetSelSetImpl* ptr)
    : PySmComponent(ptr)
{
}

PySmSheetSelSet::PySmSheetSelSet(const PySmSheetSelSetImpl& other)
    : PySmComponent(other)
{
}

void PySmSheetSelSet::add(PySmComponent& val)
{
    impObj()->Add(*val.impObj());
}

void PySmSheetSelSet::remove(PySmComponent& val)
{
    impObj()->Remove(*val.impObj());
}

boost::python::list PySmSheetSelSet::getComponents() const
{
    const auto& v = impObj()->GetComponents();
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (const auto& i : v)
        pylist.append(PySmComponent(i));
    return pylist;
}

PySmSheetSelSet PySmSheetSelSet::cast(const PySmPersist& src)
{
    return PySmObjectCast<PySmSheetSelSet>(src);
}

std::string PySmSheetSelSet::className()
{
    return "AcSmSheetSelSet";
}

PySmSheetSelSetImpl* PySmSheetSelSet::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PySmSheetSelSetImpl*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PycSmSheetSelSets
void makePySmSheetSelSetsWrapper()
{
    PyDocString DS("SheetSelSets");
    class_<PySmSheetSelSets, bases<PySmComponent>>("SheetSelSets")
        .def(init<>(DS.ARGS()))
        .def("add", &PySmSheetSelSets::add, DS.ARGS({ "name: str","desc: str" }))
        .def("remove", &PySmSheetSelSets::remove, DS.ARGS({ "val: PySm.SheetSelSet" }))
        .def("getSheetSelSets", &PySmSheetSelSets::getSheetSelSets, DS.ARGS())
        .def("cast", &PySmSheetSelSets::cast, DS.SARGS({ "otherObject: PySm.Persist" })).staticmethod("cast")
        .def("className", &PySmSheetSelSets::className, DS.SARGS()).staticmethod("className")
        ;
}

PySmSheetSelSets::PySmSheetSelSets()
    : PySmSheetSelSets(new PySmSheetSelSetsImpl())
{
}

PySmSheetSelSets::PySmSheetSelSets(PySmSheetSelSetsImpl* ptr)
    : PySmComponent(ptr)
{
}

PySmSheetSelSets::PySmSheetSelSets(const PySmSheetSelSetsImpl& other)
    : PySmComponent(other)
{
}

PySmSheetSelSet PySmSheetSelSets::add(const std::string& name, const std::string& desc)
{
    return PySmSheetSelSet(impObj()->Add(utf8_to_wstr(name).c_str(), utf8_to_wstr(desc).c_str()));
}

void PySmSheetSelSets::remove(PySmSheetSelSet& ss)
{
    impObj()->Remove(*ss.impObj());
}

boost::python::list PySmSheetSelSets::getSheetSelSets() const
{
    const auto& v = impObj()->GetSheetSelSets();
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (const auto& i : v)
        pylist.append(PySmSheetSelSet(i));
    return pylist;
}

PySmSheetSelSets PySmSheetSelSets::cast(const PySmPersist& src)
{
    return PySmObjectCast<PySmSheetSelSets>(src);
}

std::string PySmSheetSelSets::className()
{
    return "AcSmSheetSelSets";
}

PySmSheetSelSetsImpl* PySmSheetSelSets::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PySmSheetSelSetsImpl*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PySmSheetView
void makePySmSheetViewWrapper()
{
    PyDocString DS("SheetView");
    class_<PySmSheetView, bases<PySmComponent>>("SheetView")
        .def(init<>(DS.ARGS()))
        .def("getNamedView", &PySmSheetView::getNamedView, DS.ARGS())
        .def("setNamedView", &PySmSheetView::setNamedView, DS.ARGS({ "val: PySm.AcDbViewReference" }))
        .def("getCategory", &PySmSheetView::getCategory, DS.ARGS())
        .def("setCategory", &PySmSheetView::setCategory, DS.ARGS({ "val: PySm.ViewCategory" }))
        .def("getNumber", &PySmSheetView::getNumber, DS.ARGS())
        .def("setNumber", &PySmSheetView::setNumber, DS.ARGS({ "val: str" }))
        .def("getTitle", &PySmSheetView::getTitle, DS.ARGS())
        .def("setTitle", &PySmSheetView::setTitle, DS.ARGS({ "val: str" }))
        .def("cast", &PySmSheetView::cast, DS.SARGS({ "otherObject: PySm.Persist" })).staticmethod("cast")
        .def("className", &PySmSheetView::className, DS.SARGS()).staticmethod("className")
        ;
}

PySmSheetView::PySmSheetView()
    : PySmSheetView(new PySmSheetViewImpl())
{
}

PySmSheetView::PySmSheetView(PySmSheetViewImpl* ptr)
    : PySmComponent(ptr)
{
}

PySmSheetView::PySmSheetView(const PySmSheetViewImpl& other)
    : PySmComponent(other)
{
}

PySmAcDbViewReference PySmSheetView::getNamedView() const
{
    return PySmAcDbViewReference(impObj()->GetNamedView());
}

void PySmSheetView::setNamedView(PySmAcDbViewReference& view)
{
    impObj()->SetNamedView(*view.impObj());
}

PySmViewCategory PySmSheetView::getCategory() const
{
    return PySmViewCategory(impObj()->GetCategory());
}

void PySmSheetView::setCategory(PySmViewCategory& view)
{
    impObj()->SetCategory(*view.impObj());
}

std::string PySmSheetView::getNumber() const
{
    return wstr_to_utf8(impObj()->GetNumber());
}

void PySmSheetView::setNumber(const std::string& csVal)
{
    impObj()->SetNumber(utf8_to_wstr(csVal).c_str());
}

std::string PySmSheetView::getTitle() const
{
    return wstr_to_utf8(impObj()->GetTitle());
}

void PySmSheetView::setTitle(const std::string& csVal)
{
    impObj()->SetTitle(utf8_to_wstr(csVal).c_str());
}

PySmSheetView PySmSheetView::cast(const PySmPersist& src)
{
    return PySmObjectCast<PySmSheetView>(src);
}

std::string PySmSheetView::className()
{
    return "AcSmSheetView";
}

PySmSheetViewImpl* PySmSheetView::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PySmSheetViewImpl*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PySmSheetViews
void makePySmSheetViewsWrapper()
{
    PyDocString DS("SheetViews");
    class_<PySmSheetViews, bases<PySmComponent>>("SheetViews")
        .def(init<>(DS.ARGS()))
        .def("getSheetViews", &PySmSheetViews::getSheetViews, DS.ARGS())
        .def("sync", &PySmSheetViews::sync, DS.ARGS({ "val: PySm.AcDbLayoutReference","db: PyDb.Database" }))
        .def("cast", &PySmSheetViews::cast, DS.SARGS({ "otherObject: PySm.Persist" })).staticmethod("cast")
        .def("className", &PySmSheetViews::className, DS.SARGS()).staticmethod("className")
        ;
}

PySmSheetViews::PySmSheetViews()
    : PySmSheetViews(new PySmSheetViewsImpl())
{
}

PySmSheetViews::PySmSheetViews(PySmSheetViewsImpl* ptr)
    : PySmComponent(ptr)
{
}

PySmSheetViews::PySmSheetViews(const PySmSheetViewsImpl& other)
    : PySmComponent(other)
{
}

boost::python::list PySmSheetViews::getSheetViews() const
{
    const auto& v = impObj()->GetSheetViews();
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (const auto& i : v)
        pylist.append(PySmSheetView(i));
    return pylist;
}

void PySmSheetViews::sync(PySmAcDbLayoutReference& lref, PyDbDatabase& pDb)
{
    impObj()->Sync(*lref.impObj(), pDb.impObj());
}

PySmSheetViews PySmSheetViews::cast(const PySmPersist& src)
{
    return PySmObjectCast<PySmSheetViews>(src);
}

std::string PySmSheetViews::className()
{
    return "AcSmSheetViews";
}

PySmSheetViewsImpl* PySmSheetViews::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PySmSheetViewsImpl*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PySmProjectPointLocations
void makePySmProjectPointLocationsWrapper()
{
    PyDocString DS("ProjectPointLocations");
    class_<PySmProjectPointLocations, bases<PySmComponent>>("ProjectPointLocations")
        .def(init<>(DS.ARGS()))
        .def("getLocation", &PySmProjectPointLocations::getLocation, DS.ARGS({ "locationName: str" }))
        .def("removeLocation", &PySmProjectPointLocations::removeLocation, DS.ARGS({ "val: PySm.ProjectPointLocation" }))
        .def("addNewLocation", &PySmProjectPointLocations::addNewLocation, DS.ARGS({ "name: str","url: str","folder: str","username: str","password: str" }))
        .def("cast", &PySmProjectPointLocations::cast, DS.SARGS({ "otherObject: PySm.Persist" })).staticmethod("cast")
        .def("className", &PySmProjectPointLocations::className, DS.SARGS()).staticmethod("className")
        ;
}

PySmProjectPointLocations::PySmProjectPointLocations()
    : PySmProjectPointLocations(new PySmProjectPointLocationsImpl())
{
}

PySmProjectPointLocations::PySmProjectPointLocations(PySmProjectPointLocationsImpl* ptr)
    : PySmComponent(ptr)
{
}

PySmProjectPointLocations::PySmProjectPointLocations(const PySmProjectPointLocationsImpl& other)
    : PySmComponent(other)
{
}

PySmProjectPointLocation PySmProjectPointLocations::getLocation(const std::string& locationName) const
{
    return PySmProjectPointLocation(impObj()->GetLocation(utf8_to_wstr(locationName).c_str()));
}

void PySmProjectPointLocations::removeLocation(PySmProjectPointLocation& val)
{
    impObj()->RemoveLocation(*val.impObj());
}

PySmProjectPointLocation PySmProjectPointLocations::addNewLocation(const std::string& name,
    const std::string& url, const std::string& folder, const std::string& username, const std::string& password)
{
    return PySmProjectPointLocation(impObj()->AddNewLocation(
        utf8_to_wstr(name).c_str(),
        utf8_to_wstr(url).c_str(),
        utf8_to_wstr(folder).c_str(),
        utf8_to_wstr(username).c_str(),
        utf8_to_wstr(password).c_str()));
}

boost::python::list PySmProjectPointLocations::getProjectPointLocations() const
{
    const auto& v = impObj()->GetProjectPointLocations();
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (const auto& i : v)
        pylist.append(PySmProjectPointLocation(i));
    return pylist;
}

PySmProjectPointLocations PySmProjectPointLocations::cast(const PySmPersist& src)
{
    return PySmObjectCast<PySmProjectPointLocations>(src);
}

std::string PySmProjectPointLocations::className()
{
    return "AcSmProjectPointLocations";
}

PySmProjectPointLocationsImpl* PySmProjectPointLocations::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PySmProjectPointLocationsImpl*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PySmSmResources
void makePySmSmResourcesWrapper()
{
    PyDocString DS("Resources");
    class_<PySmSmResources, bases<PySmComponent>>("Resources")
        .def(init<>(DS.ARGS()))
        .def("add", &PySmSmResources::add, DS.ARGS({ "val: PySm.FileReference" }))
        .def("remove", &PySmSmResources::remove, DS.ARGS({ "val: PySm.FileReference" }))
        .def("getFileReferences", &PySmSmResources::getFileReferences, DS.ARGS())
        .def("cast", &PySmSmResources::cast, DS.SARGS({ "otherObject: PySm.Persist" })).staticmethod("cast")
        .def("className", &PySmSmResources::className, DS.SARGS()).staticmethod("className")
        ;
}

PySmSmResources::PySmSmResources()
    : PySmSmResources(new PySmResourcesImpl())
{
}

PySmSmResources::PySmSmResources(PySmResourcesImpl* ptr)
    : PySmComponent(ptr)
{
}

PySmSmResources::PySmSmResources(const PySmResourcesImpl& other)
    : PySmComponent(other)
{
}

void PySmSmResources::add(PySmFileReference& val)
{
    impObj()->Add(*val.impObj());
}

void PySmSmResources::remove(PySmFileReference& val)
{
    impObj()->Remove(*val.impObj());
}

boost::python::list PySmSmResources::getFileReferences()
{
    const auto& v = impObj()->GetFileReferences();
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (const auto& i : v)
        pylist.append(PySmFileReference(i));
    return pylist;
}

PySmSmResources PySmSmResources::cast(const PySmPersist& src)
{
    return PySmObjectCast<PySmSmResources>(src);
}

std::string PySmSmResources::className()
{
    return "AcSmResources";
}

PySmResourcesImpl* PySmSmResources::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PySmResourcesImpl*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PySmViewCategory
void makePySmViewCategoryWrapper()
{
    PyDocString DS("ViewCategory");
    class_<PySmViewCategory, bases<PySmComponent>>("ViewCategory")
        .def(init<>(DS.ARGS()))
        .def("getSheetViews", &PySmViewCategory::getSheetViews, DS.ARGS())
        .def("getCalloutBlocks", &PySmViewCategory::getCalloutBlocks, DS.ARGS())
        .def("cast", &PySmViewCategory::cast, DS.SARGS({ "otherObject: PySm.Persist" })).staticmethod("cast")
        .def("className", &PySmViewCategory::className, DS.SARGS()).staticmethod("className")
        ;
}

PySmViewCategory::PySmViewCategory()
    : PySmViewCategory(new PySmViewCategoryImpl())
{
}

PySmViewCategory::PySmViewCategory(PySmViewCategoryImpl* ptr)
    : PySmComponent(ptr)
{
}

PySmViewCategory::PySmViewCategory(const PySmViewCategoryImpl& other)
    : PySmComponent(other)
{
}

boost::python::list PySmViewCategory::getSheetViews()
{
    const auto& v = impObj()->GetSheetViews();
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (const auto& i : v)
        pylist.append(PySmSheetView(i));
    return pylist;
}

PySmCalloutBlocks PySmViewCategory::getCalloutBlocks()
{
    return PySmCalloutBlocks(impObj()->GetCalloutBlocks());
}

PySmViewCategory PySmViewCategory::cast(const PySmPersist& src)
{
    return PySmObjectCast<PySmViewCategory>(src);
}

std::string PySmViewCategory::className()
{
    return "AcSmViewCategory";
}

PySmViewCategoryImpl* PySmViewCategory::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PySmViewCategoryImpl*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PySmViewCategories
void makePySmViewCategoriesWrapper()
{
    PyDocString DS("ViewCategories");
    class_<PySmViewCategories, bases<PySmComponent>>("ViewCategories")
        .def(init<>(DS.ARGS()))
        .def("getViewCategories", &PySmViewCategories::getViewCategories, DS.ARGS())
        .def("createViewCategory", &PySmViewCategories::createViewCategory, DS.ARGS({ "name: str", "desc: str", "id: str" }))
        .def("removeViewCategory", &PySmViewCategories::removeViewCategory, DS.ARGS({ "val: PySm.ViewCategory" }))
        .def("getDefaultViewCategory", &PySmViewCategories::getDefaultViewCategory, DS.ARGS())
        .def("cast", &PySmViewCategories::cast, DS.SARGS({ "otherObject: PySm.Persist" })).staticmethod("cast")
        .def("className", &PySmViewCategories::className, DS.SARGS()).staticmethod("className")
        ;
}

PySmViewCategories::PySmViewCategories()
    : PySmViewCategories(new PySmViewCategoriesImpl())
{
}

PySmViewCategories::PySmViewCategories(PySmViewCategoriesImpl* ptr)
    : PySmComponent(ptr)
{
}

PySmViewCategories::PySmViewCategories(const PySmViewCategoriesImpl& other)
    : PySmComponent(other)
{
}

boost::python::list PySmViewCategories::getViewCategories()
{
    const auto& v = impObj()->GetPySmViewCategorys();
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (const auto& i : v)
        pylist.append(PySmViewCategory(i));
    return pylist;
}

PySmViewCategory PySmViewCategories::createViewCategory(const std::string& csName, const std::string& csDesc, const std::string& csId)
{
    return PySmViewCategory(impObj()->CreateViewCategory(utf8_to_wstr(csName).c_str(), utf8_to_wstr(csDesc).c_str(), utf8_to_wstr(csId).c_str()));
}

void PySmViewCategories::removeViewCategory(PySmViewCategory& cat)
{
    impObj()->RemoveViewCategory(*cat.impObj());
}

PySmViewCategory PySmViewCategories::getDefaultViewCategory()
{
    return PySmViewCategory(impObj()->GetDefaultViewCategory());
}

PySmViewCategories PySmViewCategories::cast(const PySmPersist& src)
{
    return PySmObjectCast<PySmViewCategories>(src);
}

std::string PySmViewCategories::className()
{
    return "AcSmViewCategories";
}

PySmViewCategoriesImpl* PySmViewCategories::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PySmViewCategoriesImpl*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PySmCalloutBlocks
void makePySmCalloutBlocksWrapper()
{
    PyDocString DS("CalloutBlocks");
    class_<PySmCalloutBlocks, bases<PySmComponent>>("CalloutBlocks")
        .def(init<>(DS.ARGS()))
        .def("add", &PySmCalloutBlocks::add, DS.ARGS({ "val: PySm.DbBlockRecordReference" }))
        .def("remove", &PySmCalloutBlocks::remove, DS.ARGS({ "val: PySm.DbBlockRecordReference" }))
        .def("getDbBlockRecordReferences", &PySmCalloutBlocks::getDbBlockRecordReferences, DS.ARGS())
        .def("cast", &PySmCalloutBlocks::cast, DS.SARGS({ "otherObject: PySm.Persist" })).staticmethod("cast")
        .def("className", &PySmCalloutBlocks::className, DS.SARGS()).staticmethod("className")
        ;
}

PySmCalloutBlocks::PySmCalloutBlocks()
    : PySmCalloutBlocks(new PySmCalloutBlocksImpl())
{
}

PySmCalloutBlocks::PySmCalloutBlocks(PySmCalloutBlocksImpl* ptr)
    : PySmComponent(ptr)
{
}

PySmCalloutBlocks::PySmCalloutBlocks(const PySmCalloutBlocksImpl& other)
    : PySmComponent(other)
{
}

void PySmCalloutBlocks::add(PySmAcDbBlockRecordReference& blkRef)
{
    impObj()->Add(*blkRef.impObj());
}

void PySmCalloutBlocks::remove(PySmAcDbBlockRecordReference& blkRef)
{
    impObj()->Remove(*blkRef.impObj());
}

boost::python::list PySmCalloutBlocks::getDbBlockRecordReferences() const
{
    const auto& v = impObj()->getAcDbBlockRecordReferences();
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (const auto& i : v)
        pylist.append(PySmAcDbBlockRecordReference(i));
    return pylist;
}

PySmCalloutBlocks PySmCalloutBlocks::cast(const PySmPersist& src)
{
    return PySmObjectCast<PySmCalloutBlocks>(src);
}

std::string PySmCalloutBlocks::className()
{
    return "AcSmCalloutBlocks";
}

PySmCalloutBlocksImpl* PySmCalloutBlocks::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PySmCalloutBlocksImpl*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PySmSubset
void makePySmSubsetWrapper()
{
    PyDocString DS("Subset");
    class_<PySmSubset, bases<PySmComponent>>("Subset")
        .def(init<>(DS.ARGS()))
        .def("getNewSheetLocation", &PySmSubset::getNewSheetLocation, DS.ARGS())
        .def("setNewSheetLocation", &PySmSubset::setNewSheetLocation, DS.ARGS({ "val: PySm.FileReference" }))
        .def("getDefDwtLayout", &PySmSubset::getDefDwtLayout, DS.ARGS())
        .def("setDefDwtLayout", &PySmSubset::setDefDwtLayout, DS.ARGS({ "val: PySm.DbLayoutReference" }))
        .def("getPromptForDwt", &PySmSubset::getPromptForDwt, DS.ARGS())
        .def("setPromptForDwt", &PySmSubset::setPromptForDwt, DS.ARGS({ "val: bool" }))
        .def("getSheets", &PySmSubset::getSheets, DS.ARGS())
        .def("addNewSheet", &PySmSubset::addNewSheet, DS.ARGS({ "name: str","desc: str" }))
        .def("insertComponentFirst", &PySmSubset::insertComponentFirst, DS.ARGS({ "newSheet: PySm.Component" }))
        .def("insertComponent", &PySmSubset::insertComponent, DS.ARGS({ "newSheet: PySm.Component","beforeSheet: PySm.Component" }))
        .def("insertComponentAfter", &PySmSubset::insertComponentAfter, DS.ARGS({ "newSheet: PySm.Component","afterSheet: PySm.Component" }))
        .def("importSheet", &PySmSubset::importSheet, DS.ARGS({ "val: PySm.DbLayoutReference" }))
        .def("removeSheet", &PySmSubset::removeSheet, DS.ARGS({ "val: PySm.Sheet" }))
        .def("createSubset", &PySmSubset::createSubset, DS.ARGS({ "name: str","desc: str" }))
        .def("removeSubset", &PySmSubset::removeSubset, DS.ARGS({ "val: PySm.Subset" }))
        .def("updateInMemoryDwgHints", &PySmSubset::updateInMemoryDwgHints, DS.ARGS())
        .def("getOverrideSheetPublish", &PySmSubset::getOverrideSheetPublish, DS.ARGS())
        .def("setOverrideSheetPublish", &PySmSubset::setOverrideSheetPublish, DS.ARGS({ "val: bool" }))
        .def("cast", &PySmSubset::cast, DS.SARGS({ "otherObject: PySm.Persist" })).staticmethod("cast")
        .def("className", &PySmSubset::className, DS.SARGS()).staticmethod("className")
        ;
}

PySmSubset::PySmSubset()
    : PySmSubset(new PySmSubsetImpl())
{
}

PySmSubset::PySmSubset(PySmSubsetImpl* ptr)
    : PySmComponent(ptr)
{
}

PySmSubset::PySmSubset(const PySmSubsetImpl& other)
    : PySmComponent(other)
{
}

PySmFileReference PySmSubset::getNewSheetLocation()
{
    return PySmFileReference(impObj()->GetNewSheetLocation());
}

void PySmSubset::setNewSheetLocation(PySmFileReference& fref)
{
    impObj()->SetNewSheetLocation(*fref.impObj());
}

PySmAcDbLayoutReference PySmSubset::getDefDwtLayout() const
{
    return PySmAcDbLayoutReference(impObj()->GetDefDwtLayout());
}

void PySmSubset::setDefDwtLayout(PySmAcDbLayoutReference& fref)
{
    impObj()->SetDefDwtLayout(*fref.impObj());
}

bool PySmSubset::getPromptForDwt() const
{
    return impObj()->GetPromptForDwt();
}

void PySmSubset::setPromptForDwt(bool val)
{
    impObj()->SetPromptForDwt(val);
}

boost::python::list PySmSubset::getSheets() const
{
    const auto& v = impObj()->GetSheets();
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (const auto& i : v)
        pylist.append(PySmSheet(i));
    return pylist;
}

PySmSheet PySmSubset::addNewSheet(const std::string& name, const std::string& desc)
{
    return PySmSheet(impObj()->AddNewSheet(utf8_to_wstr(name).c_str(), utf8_to_wstr(desc).c_str()));
}

void PySmSubset::insertComponentFirst(PySmComponent& newSheet)
{
    impObj()->InsertComponentFirst(*newSheet.impObj());
}

void PySmSubset::insertComponent(PySmComponent& newSheet, PySmComponent& beforeComp)
{
    impObj()->InsertComponent(*newSheet.impObj(), *beforeComp.impObj());
}

void PySmSubset::insertComponentAfter(PySmComponent& newSheet, PySmComponent& afterComp)
{
    impObj()->InsertComponent(*newSheet.impObj(), *afterComp.impObj());
}

PySmSheet PySmSubset::importSheet(PySmAcDbLayoutReference& fref)
{
    return PySmSheet(impObj()->ImportSheet(*fref.impObj()));
}

void PySmSubset::removeSheet(PySmSheet& val)
{
    impObj()->RemoveSheet(*val.impObj());
}

PySmSubset PySmSubset::createSubset(const std::string& name, const std::string& desc)
{
    return PySmSubset(impObj()->CreateSubset(utf8_to_wstr(name).c_str(), utf8_to_wstr(desc).c_str()));
}

void PySmSubset::removeSubset(PySmSubset& val)
{
    impObj()->RemoveSubset(*val.impObj());
}

void PySmSubset::updateInMemoryDwgHints()
{
    impObj()->UpdateInMemoryDwgHints();
}

bool PySmSubset::getOverrideSheetPublish() const
{
    return impObj()->GetOverrideSheetPublish();
}

void PySmSubset::setOverrideSheetPublish(bool val)
{
    impObj()->SetOverrideSheetPublish(val);
}

PySmSubset PySmSubset::cast(const PySmPersist& src)
{
    return PySmObjectCast<PySmSubset>(src);
}

std::string PySmSubset::className()
{
    return "AcSmSubset";
}

PySmSubsetImpl* PySmSubset::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PySmSubsetImpl*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PySmSheet
void makePySmSheetWrapper()
{
    PyDocString DS("Sheet");
    class_<PySmSheet, bases<PySmComponent>>("Sheet")
        .def(init<>(DS.ARGS()))
        .def("getNumber", &PySmSheet::getNumber, DS.ARGS())
        .def("setNumber", &PySmSheet::setNumber, DS.ARGS({ "number: str" }))
        .def("getTitle", &PySmSheet::getTitle, DS.ARGS())
        .def("setTitle", &PySmSheet::setTitle, DS.ARGS({ "title: str" }))
        .def("getDoNotPlot", &PySmSheet::getDoNotPlot, DS.ARGS())
        .def("setDoNotPlot", &PySmSheet::setDoNotPlot, DS.ARGS({ "flag: bool" }))
        .def("getRevisionNumber", &PySmSheet::getRevisionNumber, DS.ARGS())
        .def("setRevisionNumber", &PySmSheet::setRevisionNumber, DS.ARGS({ "number: str" }))
        .def("getRevisionDate", &PySmSheet::getRevisionDate, DS.ARGS())
        .def("setRevisionDate", &PySmSheet::setRevisionDate, DS.ARGS({ "date: str" }))
        .def("getIssuePurpose", &PySmSheet::getIssuePurpose, DS.ARGS())
        .def("setIssuePurpose", &PySmSheet::setIssuePurpose, DS.ARGS({ "why: str" }))
        .def("getCategory", &PySmSheet::getCategory, DS.ARGS())
        .def("setCategory", &PySmSheet::setCategory, DS.ARGS({ "cat: str" }))
        .def("getLayout", &PySmSheet::getLayout, DS.ARGS())
        .def("setLayout", &PySmSheet::setLayout, DS.ARGS({ "layout: PySm.DbLayoutReference" }))
        .def("getSheetViews", &PySmSheet::getSheetViews, DS.ARGS())
        .def("cast", &PySmSheet::cast, DS.SARGS({ "otherObject: PySm.Persist" })).staticmethod("cast")
        .def("className", &PySmSheet::className, DS.SARGS()).staticmethod("className")
        ;
}

PySmSheet::PySmSheet()
    : PySmSheet(new PySmSheetImpl())
{
}

PySmSheet::PySmSheet(PySmSheetImpl* ptr)
    : PySmComponent(ptr)
{
}

PySmSheet::PySmSheet(const PySmSheetImpl& other)
    : PySmComponent(other)
{
}

std::string PySmSheet::getNumber() const
{
    return wstr_to_utf8(impObj()->GetNumber());
}

void PySmSheet::setNumber(const std::string& csVal)
{
    impObj()->SetNumber(utf8_to_wstr(csVal).c_str());
}

std::string PySmSheet::getTitle() const
{
    return wstr_to_utf8(impObj()->GetTitle());
}

void PySmSheet::setTitle(const std::string& csVal)
{
    impObj()->SetTitle(utf8_to_wstr(csVal).c_str());
}

bool PySmSheet::getDoNotPlot() const
{
    return impObj()->GetDoNotPlot();
}

void PySmSheet::setDoNotPlot(bool flag)
{
    impObj()->SetDoNotPlot(flag);
}

PySmAcDbLayoutReference PySmSheet::getLayout()
{
    return PySmAcDbLayoutReference(impObj()->GetLayout());
}

void PySmSheet::setLayout(PySmAcDbLayoutReference& val)
{
    impObj()->SetLayout(*val.impObj());
}

PySmSheetViews PySmSheet::getSheetViews() const
{
    return PySmSheetViews(impObj()->GetSheetViews());
}

std::string PySmSheet::getRevisionNumber() const
{
    return wstr_to_utf8(impObj()->GetRevisionNumber());
}

void PySmSheet::setRevisionNumber(const std::string& csVal)
{
    impObj()->SetRevisionNumber(utf8_to_wstr(csVal).c_str());
}

std::string PySmSheet::getRevisionDate() const
{
    return wstr_to_utf8(impObj()->GetRevisionDate());
}

void PySmSheet::setRevisionDate(const std::string& csVal)
{
    impObj()->SetRevisionDate(utf8_to_wstr(csVal).c_str());
}

std::string PySmSheet::getIssuePurpose() const
{
    return wstr_to_utf8(impObj()->GetIssuePurpose());
}

void PySmSheet::setIssuePurpose(const std::string& csVal)
{
    impObj()->SetIssuePurpose(utf8_to_wstr(csVal).c_str());
}

std::string PySmSheet::getCategory() const
{
    return wstr_to_utf8(impObj()->GetCategory());
}

void PySmSheet::setCategory(const std::string& csVal)
{
    impObj()->SetCategory(utf8_to_wstr(csVal).c_str());
}

PySmSheet PySmSheet::cast(const PySmPersist& src)
{
    return PySmObjectCast<PySmSheet>(src);
}

std::string PySmSheet::className()
{
    return "AcSmSheet";
}

PySmSheetImpl* PySmSheet::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PySmSheetImpl*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PySmSheetSet
void makePySmSheetSetWrapper()
{
    PyDocString DS("SheetSet");
    class_<PySmSheetSet, bases<PySmSubset>>("SheetSet")
        .def(init<>(DS.ARGS()))
        .def("getAltPageSetups", &PySmSheetSet::getAltPageSetups, DS.ARGS())
        .def("setAltPageSetups", &PySmSheetSet::setAltPageSetups, DS.ARGS({ "val: PySm.FileReference" }))
        .def("getDefAltPageSetup", &PySmSheetSet::getDefAltPageSetup, DS.ARGS())
        .def("setDefAltPageSetup", &PySmSheetSet::setDefAltPageSetup, DS.ARGS({ "val: PySm.NamedDbObjectReference" }))
        .def("getPromptForDwgName", &PySmSheetSet::getPromptForDwgName, DS.ARGS())
        .def("setPromptForDwgName", &PySmSheetSet::setPromptForDwgName, DS.ARGS({ "val: bool" }))
        .def("getSheetSelSets", &PySmSheetSet::getSheetSelSets, DS.ARGS())
        .def("getResources", &PySmSheetSet::getResources, DS.ARGS())
        .def("getCalloutBlocks", &PySmSheetSet::getCalloutBlocks, DS.ARGS())
        .def("getViewCategories", &PySmSheetSet::getViewCategories, DS.ARGS())
        .def("getDefLabelBlk", &PySmSheetSet::getDefLabelBlk, DS.ARGS())
        .def("setDefLabelBlk", &PySmSheetSet::setDefLabelBlk, DS.ARGS({ "val: PySm.DbBlockRecordReference" }))
        .def("getPublishOptions", &PySmSheetSet::getPublishOptions, DS.ARGS())
        .def("sync", &PySmSheetSet::sync, DS.ARGS({ "db: PyDb.Database" }))
        .def("updateSheetCustomProps", &PySmSheetSet::updateSheetCustomProps, DS.ARGS())
        .def("cast", &PySmSheetSet::cast, DS.SARGS({ "otherObject: PySm.Persist" })).staticmethod("cast")
        .def("className", &PySmSheetSet::className, DS.SARGS()).staticmethod("className")
        ;
}

PySmSheetSet::PySmSheetSet()
    : PySmSheetSet(new PySmSheetSetImpl())
{
}

PySmSheetSet::PySmSheetSet(PySmSheetSetImpl* ptr)
    : PySmSubset(ptr)
{
}

PySmSheetSet::PySmSheetSet(const PySmSheetSetImpl& other)
    : PySmSubset(other)
{
}

PySmFileReference PySmSheetSet::getAltPageSetups() const
{
    return PySmFileReference(impObj()->GetAltPageSetups());
}

void PySmSheetSet::setAltPageSetups(const PySmFileReference& alt)
{
    impObj()->SetAltPageSetups(*alt.impObj());
}

PySmNamedAcDbObjectReference PySmSheetSet::getDefAltPageSetup() const
{
    return PySmNamedAcDbObjectReference(impObj()->GetDefAltPageSetup());
}

void PySmSheetSet::setDefAltPageSetup(const PySmNamedAcDbObjectReference& alt)
{
    impObj()->SetDefAltPageSetup(*alt.impObj());
}

bool PySmSheetSet::getPromptForDwgName() const
{
    return  impObj()->GetPromptForDwgName();
}

void PySmSheetSet::setPromptForDwgName(bool flag)
{
    impObj()->SetPromptForDwgName(flag);
}

PySmSheetSelSets PySmSheetSet::getSheetSelSets() const
{
    return PySmSheetSelSets(impObj()->GetSheetSelSets());
}

PySmSmResources PySmSheetSet::getResources() const
{
    return PySmSmResources(impObj()->GetResources());
}

PySmCalloutBlocks PySmSheetSet::getCalloutBlocks() const
{
    return PySmCalloutBlocks(impObj()->GetCalloutBlocks());
}

PySmViewCategories PySmSheetSet::getViewCategories() const
{
    return PySmViewCategories(impObj()->GetViewCategories());
}

PySmAcDbBlockRecordReference PySmSheetSet::getDefLabelBlk() const
{
    return PySmAcDbBlockRecordReference(impObj()->GetDefLabelBlk());
}

void PySmSheetSet::setDefLabelBlk(const PySmAcDbBlockRecordReference& blk)
{
    impObj()->SetDefLabelBlk(*blk.impObj());
}

PySmPublishOptions PySmSheetSet::getPublishOptions() const
{
    return PySmPublishOptions(impObj()->GetPublishOptions());
}

void PySmSheetSet::sync(PyDbDatabase& pDb)
{
    impObj()->Sync(pDb.impObj());
}

void PySmSheetSet::updateSheetCustomProps()
{
    impObj()->UpdateSheetCustomProps();
}

PySmSheetSet PySmSheetSet::cast(const PySmPersist& src)
{
    return PySmObjectCast<PySmSheetSet>(src);
}

std::string PySmSheetSet::className()
{
    return "AcSmSheetSet";
}

PySmSheetSetImpl* PySmSheetSet::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PySmSheetSetImpl*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PySmSmDatabase
void makePySmDatabaseWrapper()
{
    PyDocString DS("PySm.SmDatabase");
    class_<PySmDatabase, bases<PySmComponent>>("SmDatabase")
        .def(init<>(DS.ARGS()))
        .def("loadFromFile", &PySmDatabase::loadFromFile, DS.ARGS({ "filename: str" }))
        .def("getFileName", &PySmDatabase::getFileName, DS.ARGS())
        .def("setFileName", &PySmDatabase::setFileName, DS.ARGS({ "filename: str" }))
        .def("getTemplateDstFileName", &PySmDatabase::getTemplateDstFileName, DS.ARGS())
        .def("getSheetSet", &PySmDatabase::getSheetSet, DS.ARGS())
        .def("getLockStatus", &PySmDatabase::getLockStatus, DS.ARGS())
        .def("getLockOwnerInfo", &PySmDatabase::getLockOwnerInfo, DS.ARGS())
        .def("lockDb", &PySmDatabase::lockDb, DS.ARGS())
        .def("unlockDb", &PySmDatabase::unlockDb, DS.ARGS({ "commit: bool" }))
        .def("getPersistObjects", &PySmDatabase::getPersistObjects, DS.ARGS())
        .def("cast", &PySmDatabase::cast, DS.SARGS({ "otherObject: PySm.Persist" })).staticmethod("cast")
        .def("className", &PySmDatabase::className, DS.SARGS()).staticmethod("className")
        ;

    enum_<SmLockStatus>("LockStatus")
        .value("kUnLocked", SmLockStatus::AcSmLockStatus_UnLocked)
        .value("kLockedLocal", SmLockStatus::AcSmLockStatus_Locked_Local)
        .value("kLockedRemote", SmLockStatus::AcSmLockStatus_Locked_Remote)
        .value("kLockedReadOnly", SmLockStatus::AcSmLockStatus_Locked_ReadOnly)
        .value("kLockedNotConnected", SmLockStatus::AcSmLockStatus_Locked_NotConnected)
        .value("kLockedAccessDenied", SmLockStatus::AcSmLockStatus_Locked_AccessDenied)
        .export_values()
        ;
}
PySmDatabase::PySmDatabase()
    : PySmDatabase(new PySmDatabaseImpl())
{
}

PySmDatabase::PySmDatabase(PySmDatabaseImpl* ptr)
    : PySmComponent(ptr)
{
}

PySmDatabase::PySmDatabase(const PySmDatabaseImpl& other)
    : PySmComponent(other)
{
}

void PySmDatabase::loadFromFile(const std::string& filename)
{
    impObj()->LoadFromFile(utf8_to_wstr(filename).c_str());
}

std::string PySmDatabase::getFileName() const
{
    return wstr_to_utf8(impObj()->GetFileName());
}

void PySmDatabase::setFileName(const std::string& filename)
{
    impObj()->SetFileName(utf8_to_wstr(filename).c_str());
}

std::string PySmDatabase::getTemplateDstFileName() const
{
    return wstr_to_utf8(impObj()->GetTemplateDstFileName());
}

PySmSheetSet PySmDatabase::getSheetSet() const
{
    return PySmSheetSet(impObj()->GetSheetSet());
}

SmLockStatus PySmDatabase::getLockStatus() const
{
    return SmLockStatus(impObj()->GetLockStatus());
}

boost::python::tuple PySmDatabase::getLockOwnerInfo() const
{
    PyAutoLockGIL lock;
    const auto& info = impObj()->GetLockOwnerInfo();
    return boost::python::make_tuple(wstr_to_utf8(info.first), wstr_to_utf8(info.second));
}

void PySmDatabase::lockDb()
{
    impObj()->LockDb();
}

void PySmDatabase::unlockDb(bool commit)
{
    impObj()->UnlockDb(commit);
}

boost::python::list PySmDatabase::getPersistObjects()
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    const auto& v = impObj()->GetEnumerator();
    for (const auto& i : v)
        pylist.append(PySmPersist(i));
    return pylist;
}

PySmDatabase PySmDatabase::cast(const PySmPersist& src)
{
    return PySmObjectCast<PySmDatabase>(src);
}

std::string PySmDatabase::className()
{
    return "AcSmDatabase";
}

PySmDatabaseImpl* PySmDatabase::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PySmDatabaseImpl*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PySmSheetSetMgr
void makePySmSheetSetMgrWrapper()
{
    constexpr const std::string_view createDatabaseOverloads = "Overloads:\n"
        "- filename: str\n"
        "- filename: str, template: str, bAlwaysCreate: bool\n";

    PyDocString DS("SheetSetMgr");
    class_<PySmSheetSetMgr>("SheetSetMgr")
        .def(init<>(DS.ARGS()))
        .def("createDatabase", &PySmSheetSetMgr::createDatabase1)
        .def("createDatabase", &PySmSheetSetMgr::createDatabase2, DS.OVRL(createDatabaseOverloads))
        .def("openDatabase", &PySmSheetSetMgr::openDatabase, DS.ARGS({ "filename: str" }))
        .def("findOpenDatabase", &PySmSheetSetMgr::findOpenDatabase, DS.ARGS({ "filename: str" }))
        .def("closeAll", &PySmSheetSetMgr::closeAll, DS.ARGS())
        .def("close", &PySmSheetSetMgr::close, DS.ARGS({ "smDb: PySm.Database" }))
        .def("getParentSheetSet", &PySmSheetSetMgr::getParentSheetSet, DS.ARGS({ "dwg: str","layout: str" }))
        .def("getSheetFromLayout", &PySmSheetSetMgr::getSheetFromLayout, DS.ARGS({ "layout: PyDb.Object" }))
        .def("getDatabases", &PySmSheetSetMgr::getDatabases, DS.ARGS())
        .def("className", &PySmSheetSetMgr::className, DS.SARGS()).staticmethod("className")
        ;
}

PySmSheetSetMgr::PySmSheetSetMgr()
    : m_pyImp(new PySmSheetSetMgrImpl())
{
}

PySmDatabase PySmSheetSetMgr::createDatabase1(const std::string& filename)
{
    return PySmDatabase(impObj()->CreateDatabase(utf8_to_wstr(filename).c_str()));
}

PySmDatabase PySmSheetSetMgr::createDatabase2(const std::string& filename, const std::string& templatefilename, bool bAlwaysCreate)
{
    return PySmDatabase(impObj()->CreateDatabase(utf8_to_wstr(filename).c_str(), utf8_to_wstr(templatefilename).c_str(), bAlwaysCreate));
}

PySmDatabase PySmSheetSetMgr::openDatabase(const std::string& filename)
{
    return PySmDatabase(impObj()->OpenDatabase(utf8_to_wstr(filename).c_str()));
}

PySmDatabase PySmSheetSetMgr::findOpenDatabase(const std::string& filename)
{
    return PySmDatabase(impObj()->FindOpenDatabase(utf8_to_wstr(filename).c_str()));
}

void PySmSheetSetMgr::closeAll()
{
    impObj()->CloseAll();
}

void PySmSheetSetMgr::close(PySmDatabase& db)
{
    impObj()->Close(*db.impObj());
}

boost::python::tuple PySmSheetSetMgr::getParentSheetSet(const std::string& dwg, const std::string& layout)
{
    PyAutoLockGIL lock;
    const auto& val = impObj()->GetParentSheetSet(utf8_to_wstr(dwg).c_str(), utf8_to_wstr(layout).c_str());
    return boost::python::make_tuple(PySmDatabase(val.first), PySmSheetSet(val.second));
}

boost::python::tuple PySmSheetSetMgr::getSheetFromLayout(PyDbObject& pAcDbLayout)
{
    PyAutoLockGIL lock;
    const auto& val = impObj()->GetSheetFromLayout(pAcDbLayout.impObj());
    return boost::python::make_tuple(PySmDatabase(val.first), PySmSheet(val.second));
}

boost::python::list PySmSheetSetMgr::getDatabases() const
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    const auto& v = impObj()->GetDatabaseEnumerator();
    for (const auto& i : v)
        pylist.append(PySmDatabase(i));
    return pylist;
}

std::string PySmSheetSetMgr::className()
{
    return "AcSmSheetSetMgr";
}

#ifdef PYRXDEBUG
bool PySmSheetSetMgr::runTest()
{
    return PySmSheetSetMgrImpl::runTest();
}
#endif

PySmSheetSetMgrImpl* PySmSheetSetMgr::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_pyImp.get();
}
#endif
