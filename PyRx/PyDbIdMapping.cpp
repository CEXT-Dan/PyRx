#include "stdafx.h"
#include "PyDbIdMapping.h"
#include "PyDbObjectId.h"

using namespace boost::python;

//----------------------------------------------------------------------------------------
//PyIdPair
void makePyIdPairWrapper()
{
    class_<PyIdPair>("IdPair")
        .def(init<>())
        .def(init<const PyDbObjectId&, const PyDbObjectId &, bool>())
        .def(init<const PyDbObjectId&, const PyDbObjectId&, bool,bool,bool>())
        .def("key", &PyIdPair::key)
        .def("value", &PyIdPair::value)
        .def("isCloned", &PyIdPair::isCloned)
        .def("isPrimary", &PyIdPair::isPrimary)
        .def("isOwnerXlated", &PyIdPair::isOwnerXlated)
        .def("setKey", &PyIdPair::setKey)
        .def("setValue", &PyIdPair::setValue)
        .def("setIsCloned", &PyIdPair::setIsCloned)
        .def("setIsPrimary", &PyIdPair::setIsPrimary)
        .def("setIsOwnerXlated", &PyIdPair::setIsOwnerXlated)
        ;
}

PyIdPair::PyIdPair()
{
}

PyIdPair::PyIdPair(const AcDbIdPair& idpair)
    : m_imp(idpair)
{
}

PyIdPair::PyIdPair(const PyDbObjectId& key, const PyDbObjectId& value, bool isCloned)
    : m_imp(key.m_id, value.m_id, isCloned)
{
}

PyIdPair::PyIdPair(const PyDbObjectId& key, const PyDbObjectId& value, bool isCloned, bool isPrimary, bool isOwnerXlated)
    : m_imp(key.m_id, value.m_id, isCloned, isPrimary, isOwnerXlated)
{
}

PyDbObjectId PyIdPair::key() const
{
    return PyDbObjectId(m_imp.key());
}

PyDbObjectId PyIdPair::value() const
{
    return PyDbObjectId(m_imp.value());
}

bool PyIdPair::isCloned() const
{
    return m_imp.isCloned();
}

bool PyIdPair::isPrimary() const
{
    return m_imp.isPrimary();
}

bool PyIdPair::isOwnerXlated() const
{
    return m_imp.isOwnerXlated();
}

void PyIdPair::setKey(const PyDbObjectId& _key)
{
    m_imp.setKey(_key.m_id);
}

void PyIdPair::setValue(const PyDbObjectId& _value)
{
    m_imp.setKey(_value.m_id);
}

void PyIdPair::setIsCloned(bool isCloned)
{
    m_imp.setIsCloned(isCloned);
}

void PyIdPair::setIsPrimary(bool isPrimary)
{
    m_imp.setIsCloned(isPrimary);
}

void PyIdPair::setIsOwnerXlated(bool isOwnerXlated)
{
    m_imp.setIsCloned(isOwnerXlated);
}

//----------------------------------------------------------------------------------------
//PyDbIdMapping
void makePyDbIdMappingWrapper()
{
    class_<PyDbIdMapping>("IdMapping")
        .def(init<>())
        .def("assign", &PyDbIdMapping::assign)
        .def("compute", &PyDbIdMapping::compute)
        .def("change", &PyDbIdMapping::change)
        .def("del", &PyDbIdMapping::del)
        .def("destDb", &PyDbIdMapping::destDb)
        .def("setDestDb", &PyDbIdMapping::setDestDb)
        .def("origDb", &PyDbIdMapping::origDb)
        .def("deepCloneContext", &PyDbIdMapping::deepCloneContext)
        .def("duplicateRecordCloning", &PyDbIdMapping::duplicateRecordCloning)
        .def("idPairs", &PyDbIdMapping::idPairs)
        ;
}

struct PyDbIdMappingDeleter
{
    inline PyDbIdMappingDeleter(bool forceKeepAlive = false)
        : m_forceKeepAlive(forceKeepAlive)
    {
    }

    inline void operator()(AcDbIdMapping* p) const
    {
        if (p == nullptr)
            return;
        else if (m_forceKeepAlive)
            return;
        else
            delete p;
    }
    bool m_forceKeepAlive = false;
};

PyDbIdMapping::PyDbIdMapping()
    : m_pyImp(new AcDbIdMapping(), PyDbIdMappingDeleter())
{
}

PyDbIdMapping::PyDbIdMapping(const AcDbIdMapping& mapping)
    : m_pyImp(const_cast<AcDbIdMapping*>(std::addressof(mapping)), PyDbIdMappingDeleter(true))
{
}

void PyDbIdMapping::assign(const PyIdPair& idpair)
{
    PyThrowBadEs(impObj()->assign(idpair.m_imp));
}

bool PyDbIdMapping::compute(PyIdPair& idpair) const
{
   return impObj()->compute(idpair.m_imp);
}

bool PyDbIdMapping::change(const PyIdPair& idpair) const
{
    return impObj()->change(idpair.m_imp);
}

bool PyDbIdMapping::del(const PyDbObjectId& key)
{
    return impObj()->del(key.m_id);
}

PyDbDatabase PyDbIdMapping::destDb() const
{
    AcDbDatabase* db = nullptr;
    PyThrowBadEs(impObj()->destDb(db));
    return PyDbDatabase(db);
}

PyDbDatabase PyDbIdMapping::origDb() const
{
    AcDbDatabase* db = nullptr;
    PyThrowBadEs(impObj()->origDb(db));
    return PyDbDatabase(db);
}

void PyDbIdMapping::setDestDb(const PyDbDatabase& db)
{
    PyThrowBadEs(impObj()->setDestDb(db.impObj()));
}

AcDb::DeepCloneType PyDbIdMapping::deepCloneContext() const
{
    return impObj()->deepCloneContext();
}

AcDb::DuplicateRecordCloning PyDbIdMapping::duplicateRecordCloning() const
{
    return impObj()->duplicateRecordCloning();
}

boost::python::list PyDbIdMapping::idPairs()
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    AcDbIdMappingIter iMapIter(*impObj());
    for (iMapIter.start(); !iMapIter.done(); iMapIter.next())
    {
        AcDbIdPair idPair;
        if (iMapIter.getMap(idPair))
            pylist.append(PyIdPair(idPair));
    }
    return pylist;
}

AcDbIdMapping* PyDbIdMapping::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbIdMapping*>(m_pyImp.get());
}
