#include "stdafx.h"
#include "PyDbObjectId.h"


using namespace boost::python;


//---------------------------------------------------------------------------------
// wrapper
void makeAcDbObjectIdWrapper()
{
    static auto wrapper = class_<PyDbObjectId>("DbObjectId")
        .def(init<>())
        .def("asOldId", &PyDbObjectId::asOldId)
        .def("isNull", &PyDbObjectId::isNull)
        .def("isResident", &PyDbObjectId::isResident)
        .def("isValid", &PyDbObjectId::isValid)
        .def("isWellBehaved", &PyDbObjectId::isWellBehaved)
        .def("setFromOldId", &PyDbObjectId::setFromOldId, return_value_policy<reference_existing_object>())
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
