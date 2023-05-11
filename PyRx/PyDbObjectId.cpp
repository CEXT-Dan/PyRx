#include "stdafx.h"
#include "PyDbObjectId.h"


using namespace boost::python;


//---------------------------------------------------------------------------------
// wrapper
void makeAcDbObjectIdWrapper()
{
    class_<PyDbObjectId>("ObjectId")
        .def(init<>())
        .def("asOldId", &PyDbObjectId::asOldId)
        .def("isNull", &PyDbObjectId::isNull)
        .def("isResident", &PyDbObjectId::isResident)
        .def("isValid", &PyDbObjectId::isValid)
        .def("isWellBehaved", &PyDbObjectId::isWellBehaved)
        .def("setFromOldId", &PyDbObjectId::setFromOldId, return_self<>())
        .def("database", &PyDbObjectId::database)
        .def("originalDatabase", &PyDbObjectId::originalDatabase)
        .def("convertToRedirectedId", &PyDbObjectId::convertToRedirectedId)
        .def("objectClass", &PyDbObjectId::objectClass)

        //operators
        .def("__eq__", &PyDbObjectId::operator==)
        .def("__ne__", &PyDbObjectId::operator!=)
        ;
}

//---------------------------------------------------------------------------------
//PyDbObjectId
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
#ifdef BRXAPP
    return m_id.isValid();
#else
    return m_id.isWellBehaved();
#endif // GRXAPP
}

bool PyDbObjectId::convertToRedirectedId()
{
#ifdef BRXAPP
    m_id.convertToRedirectedId();
    return !m_id.isNull();
#else
    return m_id.convertToRedirectedId();
#endif // GRXAPP
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


//AdsName
void makeAdsNameWrapper()
{
    class_<AdsName>("AdsName")
        .def("toObjectId", &AdsName::toObjectId)
        .def("fromObjectId", &AdsName::fromObjectId)
        ;
}

PyDbObjectId AdsName::toObjectId() const
{
    AcDbObjectId id;
    if (auto es = acdbGetObjectId(id, m_data.data()); es != eOk)
        throw PyAcadErrorStatus(es);
    return PyDbObjectId(id);
}

void AdsName::fromObjectId(const PyDbObjectId& id)
{
    ads_name name = { 0L };
    if(auto es = acdbGetAdsName(name, id.m_id); es != eOk)
        throw PyAcadErrorStatus(es);
    m_data[0] = name[0];
    m_data[1] = name[1];
}


//
void makePyDbHardPointerIdWrapper()
{
    class_<PyDbHardPointerId, bases<PyDbObjectId>>("HardPointerId")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def("__eq__", &PyDbHardPointerId::operator==)
        .def("__ne__", &PyDbHardPointerId::operator!=)
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

bool PyDbHardPointerId::operator!=(const PyDbHardPointerId& rhs) const
{
    return m_id != rhs.m_id;
}

bool PyDbHardPointerId::operator==(const PyDbHardPointerId& rhs) const
{
    return m_id == rhs.m_id;
}
//
//
void makePySoftPointerIdWrapper()
{
    class_<PyDbSoftPointerId, bases<PyDbObjectId>>("SoftPointerId")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def("__eq__", &PyDbSoftPointerId::operator==)
        .def("__ne__", &PyDbSoftPointerId::operator!=)
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

bool PyDbSoftPointerId::operator!=(const PyDbSoftPointerId& rhs) const
{
    return m_id != rhs.m_id;
}

bool PyDbSoftPointerId::operator==(const PyDbSoftPointerId& rhs) const
{
    return m_id == rhs.m_id;
}
