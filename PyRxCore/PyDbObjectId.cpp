#include "stdafx.h"
#include "PyDbObjectId.h"
#include "PyAcadDbObject.h"

#include <boost/python/suite/indexing/vector_indexing_suite.hpp>

using namespace boost::python;

//---------------------------------------------------------------------------------
// PyDbObjectId
void makePyDbObjectIdWrapper()
{
    class_<PyDbObjectIdArray>("ObjectIdArray")
        .def(boost::python::vector_indexing_suite<PyDbObjectIdArray>());

    PyDocString DS("PyDb.ObjectId");
    class_<PyDbObjectId>("ObjectId")
        .def(init<>(DS.ARGS(7057)))
        .def("asOldId", &PyDbObjectId::asOldId, DS.ARGS(7075))
        .def("isNull", &PyDbObjectId::isNull, DS.ARGS(7081))
        .def("isResident", &PyDbObjectId::isResident, DS.ARGS(7082))
        .def("isValid", &PyDbObjectId::isValid, DS.ARGS(7083))
        .def("isWellBehaved", &PyDbObjectId::isWellBehaved, DS.ARGS(7084))
        .def("setFromOldId", &PyDbObjectId::setFromOldId, DS.ARGS({ "oldId : int" }, 7088))
        .def("database", &PyDbObjectId::database, DS.ARGS(7077))
        .def("originalDatabase", &PyDbObjectId::originalDatabase, DS.ARGS(7087))
        .def("convertToRedirectedId", &PyDbObjectId::convertToRedirectedId, DS.ARGS(7076))
        .def("isErased", &PyDbObjectId::isErased, DS.ARGS(7080))
        .def("isEffectivelyErased", &PyDbObjectId::isEffectivelyErased, DS.ARGS(7079))
        .def("objectLeftOnDisk", &PyDbObjectId::objectLeftOnDisk, DS.ARGS())
        .def("handle", &PyDbObjectId::handle, DS.ARGS(7078))
        .def("nonForwardedHandle", &PyDbObjectId::nonForwardedHandle, DS.ARGS(7085))
        .def("objectClass", &PyDbObjectId::objectClass, DS.ARGS(7086))
        .def("isDerivedFrom", &PyDbObjectId::isDerivedFrom, DS.ARGS({ "desc : PyRx.RxClass" }, 15281))
        .def("acadObject", &PyDbObjectId::acadObject, DS.ARGS())
        .def("fromOldId", &PyDbObjectId::fromOldId, DS.SARGS({ "oldId : int" }, 7088)).staticmethod("fromOldId")
        .def("__str__", &PyDbObjectId::str)
        .def("__repr__", &PyDbObjectId::repr)
        .def("__hash__", &PyDbObjectId::hash)
        //operators
        .def("__eq__", &PyDbObjectId::operator==)
        .def("__ne__", &PyDbObjectId::operator!=)
        .def("__lt__", &PyDbObjectId::operator<)
        .def("__gt__", &PyDbObjectId::operator>)
        .def("__le__", &PyDbObjectId::operator<=)
        .def("__ge__", &PyDbObjectId::operator>=)
        ;
}

PyDbObjectId::PyDbObjectId(const AcDbObjectId& id)
    : m_id(id)
{
}

PyDbObjectId::PyDbObjectId()
{
}

bool PyDbObjectId::operator==(const PyDbObjectId& rhs) const
{
    return m_id == rhs.m_id;
}

bool PyDbObjectId::operator!=(const PyDbObjectId& rhs) const
{
    return m_id != rhs.m_id;
}

bool PyDbObjectId::operator<(const PyDbObjectId& rhs) const
{
    return m_id < rhs.m_id;
}

bool PyDbObjectId::operator>(const PyDbObjectId& rhs) const
{
    return m_id > rhs.m_id;
}

bool PyDbObjectId::operator<=(const PyDbObjectId& rhs) const
{
    return m_id <= rhs.m_id;
}

bool PyDbObjectId::operator>=(const PyDbObjectId& rhs) const
{
    return m_id >= rhs.m_id;
}

INT_PTR PyDbObjectId::asOldId() const
{
    return m_id.asOldId();
}

void PyDbObjectId::setFromOldId(INT_PTR oldId)
{
    m_id.setFromOldId(oldId);
}

bool PyDbObjectId::isNull() const
{
    return m_id.isNull();
}

bool PyDbObjectId::isResident() const
{
    return m_id.isResident();
}

bool PyDbObjectId::isValid() const
{
    return m_id.isValid();
}

bool PyDbObjectId::isWellBehaved() const
{
    return m_id.isWellBehaved();
}

bool PyDbObjectId::convertToRedirectedId()
{
    return m_id.convertToRedirectedId();
}

bool PyDbObjectId::isErased() const
{
    return m_id.isErased();
}

bool PyDbObjectId::isEffectivelyErased() const
{
    return m_id.isEffectivelyErased();
}

bool PyDbObjectId::objectLeftOnDisk() const
{
    return m_id.objectLeftOnDisk();
}

PyDbHandle PyDbObjectId::handle() const
{
    return PyDbHandle(m_id.handle());
}

PyDbHandle PyDbObjectId::nonForwardedHandle() const
{
    return PyDbHandle(m_id.nonForwardedHandle());
}

std::string PyDbObjectId::repr() const
{
    return std::format("{}.ObjectId({:x})", PyDbNamespace, (INT_PTR)(AcDbStub*)m_id);
}

std::string PyDbObjectId::str() const
{
    return std::format("{:x}", (INT_PTR)(AcDbStub*)m_id);
}

PyDbDatabase PyDbObjectId::database() const
{
    return PyDbDatabase(m_id.database());
}

PyDbDatabase PyDbObjectId::originalDatabase() const
{
    return PyDbDatabase(m_id.originalDatabase());
}

PyRxClass PyDbObjectId::objectClass() const
{
    return PyRxClass(m_id.objectClass(), false);
}

bool PyDbObjectId::isDerivedFrom(const PyRxClass& other) const
{
    return m_id.objectClass()->isDerivedFrom(other.impObj());
}

std::size_t PyDbObjectId::hash() const
{
    return std::hash<AcDbStub*>{}(static_cast<AcDbStub*>(m_id));
}

PyAcadObject PyDbObjectId::acadObject() const
{
    return PyAcadObject(m_id);
}

PyDbObjectId PyDbObjectId::fromOldId(INT_PTR oldId)
{
    PyDbObjectId id;
    id.setFromOldId(oldId);
    return id;
}

//---------------------------------------------------------------------------------
// AdsName
void makePyAdsNameWrapper()
{
    PyDocString DS("AdsName");
    class_<AdsName>("AdsName")
        .def(init<>(DS.ARGS()))
        .def("toObjectId", &AdsName::toObjectId, DS.ARGS())
        .def("fromObjectId", &AdsName::fromObjectId, DS.ARGS({ "id: PyDb.ObjectId" }))
        ;
}

PyDbObjectId AdsName::toObjectId() const
{
    AcDbObjectId id;
    PyThrowBadEs(acdbGetObjectId(id, m_data.data()));
    return PyDbObjectId(id);
}

void AdsName::fromObjectId(const PyDbObjectId& id)
{
    ads_name name = { 0L };
    PyThrowBadEs(acdbGetAdsName(name, id.m_id));
    m_data[0] = name[0];
    m_data[1] = name[1];
}

//---------------------------------------------------------------------------------
// PyDbHardPointerId
void makePyDbHardPointerIdWrapper()
{
    PyDocString DS("HardPointerId");
    class_<PyDbHardPointerId, bases<PyDbObjectId>>("HardPointerId")
        .def(init<>())
        .def(init<const PyDbObjectId&>(DS.ARGS({ "id: PyDb.ObjectId=PyDb.ObjectId.kNull" })))
        ;
    implicitly_convertible<PyDbHardPointerId, PyDbObjectId>();
}

PyDbHardPointerId::PyDbHardPointerId()
{
}

PyDbHardPointerId::PyDbHardPointerId(const PyDbObjectId& id)
    : m_id(id.m_id)
{
}

PyDbHardPointerId& PyDbHardPointerId::operator=(const PyDbObjectId& rhs)
{
    m_id = rhs.m_id;
    return *this;
}

PyDbHardPointerId& PyDbHardPointerId::operator=(const PyDbHardPointerId& rhs)
{
    m_id = rhs.m_id;
    return *this;
}

//-----------------------------------------------------------------------------------------
//PyDbHardOwnershipId
void makePyDbAcDbHardOwnershipIdWrapper()
{
    PyDocString DS("HardOwnershipId");
    class_<PyDbHardOwnershipId, bases<PyDbObjectId>>("HardOwnershipId")
        .def(init<>())
        .def(init<const PyDbObjectId&>(DS.ARGS({ "id: PyDb.ObjectId=PyDb.ObjectId.kNull" })))
        ;
    implicitly_convertible<PyDbHardOwnershipId, PyDbObjectId>();
}

PyDbHardOwnershipId::PyDbHardOwnershipId()
{
}

PyDbHardOwnershipId::PyDbHardOwnershipId(const PyDbObjectId& id)
    : m_id(id.m_id)
{
}

PyDbHardOwnershipId& PyDbHardOwnershipId::operator=(const PyDbObjectId& rhs)
{
    m_id = rhs.m_id;
    return *this;
}

PyDbHardOwnershipId& PyDbHardOwnershipId::operator=(const PyDbHardOwnershipId& rhs)
{
    m_id = rhs.m_id;
    return *this;
}

//---------------------------------------------------------------------------------
// PyDbSoftPointerId
void makePySoftPointerIdWrapper()
{
    PyDocString DS("SoftPointerId");
    class_<PyDbSoftPointerId, bases<PyDbObjectId>>("SoftPointerId")
        .def(init<>())
        .def(init<const PyDbObjectId&>(DS.ARGS({ "id: PyDb.ObjectId=PyDb.ObjectId.kNull" })))
        ;
    implicitly_convertible<PyDbSoftPointerId, PyDbObjectId>();
}

PyDbSoftPointerId::PyDbSoftPointerId()
{
}

PyDbSoftPointerId::PyDbSoftPointerId(const PyDbObjectId& id)
    : m_id(id.m_id)
{
}

PyDbSoftPointerId& PyDbSoftPointerId::operator=(const PyDbObjectId& rhs)
{
    m_id = rhs.m_id;
    return *this;
}

PyDbSoftPointerId& PyDbSoftPointerId::operator=(const PyDbSoftPointerId& rhs)
{
    m_id = rhs.m_id;
    return *this;
}
//-----------------------------------------------------------------------------------------
//PyDbSoftOwnershipId

void makePyDbSoftOwnershipIdWrapper()
{
    PyDocString DS("SoftOwnershipId");
    class_<PyDbSoftOwnershipId, bases<PyDbObjectId>>("SoftOwnershipId")
        .def(init<>())
        .def(init<const PyDbObjectId&>(DS.ARGS({ "id: PyDb.ObjectId=PyDb.ObjectId.kNull" })))
        ;
    implicitly_convertible<PyDbSoftOwnershipId, PyDbObjectId>();
}

PyDbSoftOwnershipId::PyDbSoftOwnershipId()
{
}

PyDbSoftOwnershipId::PyDbSoftOwnershipId(const PyDbObjectId& id)
    : m_id(id.m_id)
{
}

PyDbSoftOwnershipId& PyDbSoftOwnershipId::operator=(const PyDbObjectId& rhs)
{
    m_id = rhs.m_id;
    return *this;
}

PyDbSoftOwnershipId& PyDbSoftOwnershipId::operator=(const PyDbSoftOwnershipId& rhs)
{
    m_id = rhs.m_id;
    return *this;
}

//---------------------------------------------------------------------------------
// PyDbHandle
struct PyDbHandledpickle : boost::python::pickle_suite
{
    static boost::python::tuple getinitargs(const PyDbHandle& p)
    {
        return boost::python::make_tuple(p.toString());
    }
};

void makePyDbHandleWrapper()
{
    constexpr const std::string_view ctor = "Overloads:\n"
        "- None: Any\n"
        "- low: int, high: int\n"
        "- strVal: str\n"
        "- int64Val: int\n";

    PyDocString DS("PyDb.Handle");
    class_<PyDbHandle>("Handle")
        .def(init<>())
        .def(init<int, int>())
        .def(init<const std::string&>())
        .def(init<const Adesk::UInt64&>(DS.CTOR(ctor)))
        .def("isNull", &PyDbHandle::isNull, DS.ARGS())
        .def("setNull", &PyDbHandle::setNull, DS.ARGS())
        .def("low", &PyDbHandle::low, DS.ARGS())
        .def("high", &PyDbHandle::high, DS.ARGS())
        .def("setLow", &PyDbHandle::setLow, DS.ARGS({ "val: int" }))
        .def("setHigh", &PyDbHandle::setHigh, DS.ARGS({ "val: int" }))
        .def("setValue", &PyDbHandle::setValue, DS.ARGS({ "val: int" }))
        .def("isOne", &PyDbHandle::isOne, DS.ARGS())
        .def("value", &PyDbHandle::value, DS.ARGS())
        .def("increment", &PyDbHandle::increment, DS.ARGS())
        .def("decrement", &PyDbHandle::decrement, DS.ARGS())
        .def("toString", &PyDbHandle::toString, DS.ARGS())
        .def_pickle(PyDbHandledpickle())
        .def("__str__", &PyDbHandle::toString)
        .def("__repr__", &PyDbHandle::repr)
        .def("__hash__", &PyDbHandle::hash)
        //operators
        .def("__eq__", &PyDbHandle::operator==)
        .def("__ne__", &PyDbHandle::operator!=)
        ;
}

PyDbHandle::PyDbHandle()
{
}

PyDbHandle::PyDbHandle(int lo, int hi)
    : m_hnd(lo, hi)
{
}

PyDbHandle::PyDbHandle(const std::string& src)
    : m_hnd(utf8_to_wstr(src).c_str())
{
}

PyDbHandle::PyDbHandle(const Adesk::UInt64 src)
    : m_hnd(src)
{
}

bool PyDbHandle::isNull() const
{
    return m_hnd.isNull();
}

void PyDbHandle::setNull()
{
    return m_hnd.setNull();
}

Adesk::UInt32 PyDbHandle::low() const
{
    return m_hnd.low();
}

Adesk::UInt32 PyDbHandle::high() const
{
    return m_hnd.high();
}

void PyDbHandle::setLow(Adesk::UInt32 low)
{
    return m_hnd.setLow(low);
}

void PyDbHandle::setHigh(Adesk::UInt32 high)
{
    return m_hnd.setLow(high);
}

void PyDbHandle::setValue(Adesk::UInt64 src)
{
    m_hnd = src;
}

bool PyDbHandle::isOne(void) const
{
    return m_hnd.isOne();
}

Adesk::UInt64 PyDbHandle::value() const
{
    Adesk::UInt64 val = m_hnd;
    return val;
}

std::string PyDbHandle::toString() const
{
    wchar_t buf[AcDbHandle::kStrSiz] = { 0 };
    if (m_hnd.getIntoAsciiBuffer(buf, AcDbHandle::kStrSiz) != true)
        throw PyErrorStatusException(eBrokenHandle);
    return wstr_to_utf8(buf);
}

std::string PyDbHandle::repr() const
{
    return std::format("{}.Handle({:x})", PyDbNamespace, value());
}

std::size_t PyDbHandle::hash() const
{
    return (std::size_t)value();
}

void PyDbHandle::increment(void)
{
    m_hnd.increment();
}

void PyDbHandle::decrement(void)
{
    m_hnd.decrement();
}

bool PyDbHandle::operator!=(const PyDbHandle& rhs) const
{
    return m_hnd != rhs.m_hnd;
}

bool PyDbHandle::operator==(const PyDbHandle& rhs) const
{
    return m_hnd == rhs.m_hnd;
}

//---------------------------------------------------------------------------------
// PyDbXrefObjectId
void makePyDbXrefObjectIdWrapper()
{
#if !defined(_BRXTARGET250)
    PyDocString DS("XrefObjectId");
    class_<PyDbXrefObjectId>("XrefObjectId")
        .def(init<>(DS.ARGS()))
        .def("isValid", &PyDbXrefObjectId::isValid, DS.ARGS())
        .def("isXref", &PyDbXrefObjectId::isXref, DS.ARGS())
        .def("isNull", &PyDbXrefObjectId::isNull, DS.ARGS())
        .def("setNull", &PyDbXrefObjectId::setNull, DS.ARGS())
        .def("setXrefId", &PyDbXrefObjectId::setXrefId, DS.ARGS({ "id: PyDb.ObjectId","hwnd: PyDb.Handle" }))
        .def("getXrefId", &PyDbXrefObjectId::getXrefId, DS.ARGS({ "id: PyDb.ObjectId","hwnd: PyDb.Handle" }))
        .def("setLocalId", &PyDbXrefObjectId::setLocalId, DS.ARGS({ "id: PyDb.ObjectId" }))
        .def("getLocalId", &PyDbXrefObjectId::getLocalId, DS.ARGS({ "id: PyDb.ObjectId" }))
        .def("resolveObjectId", &PyDbXrefObjectId::resolveObjectId, DS.ARGS({ "id: PyDb.ObjectId" }))
        //operators
        .def("__eq__", &PyDbXrefObjectId::operator==)
        .def("__ne__", &PyDbXrefObjectId::operator!=)
        ;
#endif
}

#if !defined(_BRXTARGET250)
PyDbXrefObjectId::PyDbXrefObjectId()
{
}

PyDbXrefObjectId::PyDbXrefObjectId(const AcDbXrefObjectId& id)
    : m_imp(id)
{
}

bool PyDbXrefObjectId::isValid(void) const
{
    return m_imp.isValid();
}

bool PyDbXrefObjectId::isXref(void) const
{
    return m_imp.isXref();
}

bool PyDbXrefObjectId::isNull(void) const
{
    return m_imp.isNull();
}

void PyDbXrefObjectId::setNull(void)
{
    return PyThrowBadEs(m_imp.setNull());
}

void PyDbXrefObjectId::setXrefId(PyDbObjectId& xrefBlkId, const PyDbHandle& hObject)
{
    return PyThrowBadEs(m_imp.setXrefId(xrefBlkId.m_id, hObject.m_hnd));
}

void PyDbXrefObjectId::getXrefId(PyDbObjectId& xrefBlkId, PyDbHandle& hObject) const
{
    return PyThrowBadEs(m_imp.getXrefId(xrefBlkId.m_id, hObject.m_hnd));
}

void PyDbXrefObjectId::setLocalId(PyDbObjectId& objId)
{
    return PyThrowBadEs(m_imp.setLocalId(objId.m_id));
}

void PyDbXrefObjectId::getLocalId(PyDbObjectId& objId) const
{
    return PyThrowBadEs(m_imp.getLocalId(objId.m_id));
}

void PyDbXrefObjectId::resolveObjectId(PyDbObjectId& id) const
{
    return PyThrowBadEs(m_imp.resolveObjectId(id.m_id));
}

bool PyDbXrefObjectId::operator!=(const PyDbXrefObjectId& other) const
{
    return m_imp != other.m_imp;
}

bool PyDbXrefObjectId::operator==(const PyDbXrefObjectId& other) const
{
    return m_imp == other.m_imp;
}
#endif