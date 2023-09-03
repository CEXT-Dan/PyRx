#include "stdafx.h"
#include "PyDbObjectId.h"

using namespace boost::python;

//---------------------------------------------------------------------------------
// PyDbObjectId
void makePyDbObjectIdWrapper()
{
    PyDocString DS("ObjectId");
    class_<PyDbObjectId>("ObjectId")
        .def(init<>())
        .def("asOldId", &PyDbObjectId::asOldId, DS.ARGS())
        .def("isNull", &PyDbObjectId::isNull, DS.ARGS())
        .def("isResident", &PyDbObjectId::isResident, DS.ARGS())
        .def("isValid", &PyDbObjectId::isValid, DS.ARGS())
        .def("isWellBehaved", &PyDbObjectId::isWellBehaved, DS.ARGS())
        .def("setFromOldId", &PyDbObjectId::setFromOldId, DS.ARGS({ "val : int" }), return_self<>())
        .def("database", &PyDbObjectId::database, DS.ARGS())
        .def("originalDatabase", &PyDbObjectId::originalDatabase, DS.ARGS())
        .def("convertToRedirectedId", &PyDbObjectId::convertToRedirectedId, DS.ARGS())
        .def("isErased", &PyDbObjectId::isErased, DS.ARGS())
        .def("isEffectivelyErased", &PyDbObjectId::isEffectivelyErased, DS.ARGS())
        .def("objectLeftOnDisk", &PyDbObjectId::objectLeftOnDisk, DS.ARGS())
        .def("handle", &PyDbObjectId::handle, DS.ARGS())
        .def("nonForwardedHandle", &PyDbObjectId::nonForwardedHandle, DS.ARGS())
        .def("objectClass", &PyDbObjectId::objectClass, DS.ARGS())
        .def("isDerivedFrom", &PyDbObjectId::isDerivedFrom, DS.ARGS({ "desc : PyRx.RxClass" }))
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

PyDbObjectId& PyDbObjectId::setFromOldId(INT_PTR oldId)
{
    m_id.setFromOldId(oldId);
    return *this;
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

std::string PyDbObjectId::repr()
{
    return std::format("<{}.ObjectId({:x})>", PyDbNamespace, (INT_PTR)(AcDbStub*)m_id);
}

std::string PyDbObjectId::str()
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

std::size_t PyDbObjectId::hash()
{
    return (std::size_t)(AcDbStub*)m_id;
}

//---------------------------------------------------------------------------------
// AdsName
void makePyAdsNameWrapper()
{
    class_<AdsName>("AdsName")
        .def("toObjectId", &AdsName::toObjectId)
        .def("fromObjectId", &AdsName::fromObjectId)
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
    class_<PyDbHardPointerId, bases<PyDbObjectId>>("HardPointerId")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
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
    class_<PyDbHardOwnershipId, bases<PyDbObjectId>>("HardOwnershipId")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
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
    class_<PyDbSoftPointerId, bases<PyDbObjectId>>("SoftPointerId")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
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
    class_<PyDbSoftOwnershipId, bases<PyDbObjectId>>("SoftOwnershipId")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
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
    class_<PyDbHandle>("Handle")
        .def(init<>())
        .def(init<int, int>())
        .def(init<const std::string&>())
        .def(init<const Adesk::UInt64&>())
        .def("isNull", &PyDbHandle::isNull)
        .def("setNull", &PyDbHandle::setNull)
        .def("low", &PyDbHandle::low)
        .def("high", &PyDbHandle::high)
        .def("setLow", &PyDbHandle::setLow)
        .def("setHigh", &PyDbHandle::setHigh)
        .def("setValue", &PyDbHandle::setValue)
        .def("isOne", &PyDbHandle::isOne)
        .def("value", &PyDbHandle::value)
        .def("increment", &PyDbHandle::increment)
        .def("decrement", &PyDbHandle::decrement)
        .def("toString", &PyDbHandle::toString)
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
        throw PyAcadErrorStatus(eBrokenHandle);
    return wstr_to_utf8(buf);
}

std::string PyDbHandle::repr() const
{
    return std::format("{}.Handle object {:x}>", PyDbNamespace, value());
}

std::size_t PyDbHandle::hash()
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
    class_<PyDbXrefObjectId>("XrefObjectId")
        .def(init<>())
        .def("isValid", &PyDbXrefObjectId::isValid)
        .def("isXref", &PyDbXrefObjectId::isXref)
        .def("isNull", &PyDbXrefObjectId::isNull)
        .def("setNull", &PyDbXrefObjectId::setNull)
        .def("setXrefId", &PyDbXrefObjectId::setXrefId)
        .def("getXrefId", &PyDbXrefObjectId::getXrefId)
        .def("setLocalId", &PyDbXrefObjectId::setLocalId)
        .def("getLocalId", &PyDbXrefObjectId::getLocalId)
        .def("resolveObjectId", &PyDbXrefObjectId::resolveObjectId)
        //operators
        .def("__eq__", &PyDbXrefObjectId::operator==)
        .def("__ne__", &PyDbXrefObjectId::operator!=)
        ;
}

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
