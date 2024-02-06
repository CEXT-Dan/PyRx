#include "stdafx.h"
#include "PyDbIdMapping.h"
#include "PyDbObjectId.h"

using namespace boost::python;

//----------------------------------------------------------------------------------------
//PyIdPair
void makePyIdPairWrapper()
{
    PyDocString DS("IdPair");
    class_<PyIdPair>("IdPair")
        .def(init<>())
        .def(init<const PyDbObjectId&, const PyDbObjectId&, bool>())
        .def(init<const PyDbObjectId&, const PyDbObjectId&, bool, bool, bool>())
        .def("key", &PyIdPair::key, DS.ARGS())
        .def("value", &PyIdPair::value, DS.ARGS())
        .def("isCloned", &PyIdPair::isCloned, DS.ARGS())
        .def("isPrimary", &PyIdPair::isPrimary, DS.ARGS())
        .def("isOwnerXlated", &PyIdPair::isOwnerXlated, DS.ARGS())
        .def("setKey", &PyIdPair::setKey, DS.ARGS({ "val : PyDb.ObjectId" }))
        .def("setValue", &PyIdPair::setValue, DS.ARGS({ "val : PyDb.ObjectId" }))
        .def("setIsCloned", &PyIdPair::setIsCloned, DS.ARGS({ "val : bool" }))
        .def("setIsPrimary", &PyIdPair::setIsPrimary, DS.ARGS({ "val : bool" }))
        .def("setIsOwnerXlated", &PyIdPair::setIsOwnerXlated, DS.ARGS({ "val : bool" }))
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
    PyDocString DS("IdMapping");
    class_<PyDbIdMapping>("IdMapping")
        .def(init<>())
        .def("assign", &PyDbIdMapping::assign, DS.ARGS({ "pair: PyDb.IdPair" }))
        .def("compute", &PyDbIdMapping::compute, DS.ARGS({ "pair: PyDb.IdPair" }))
        .def("change", &PyDbIdMapping::change, DS.ARGS({ "pair: PyDb.IdPair" }))
        .def("remove", &PyDbIdMapping::del, DS.ARGS({ "key: PyDb.ObjectId" }))
        .def("destDb", &PyDbIdMapping::destDb, DS.ARGS())
        .def("setDestDb", &PyDbIdMapping::setDestDb, DS.ARGS({ "dest: PyDb.Database" }))
        .def("origDb", &PyDbIdMapping::origDb, DS.ARGS())
        .def("deepCloneContext", &PyDbIdMapping::deepCloneContext, DS.ARGS())
        .def("duplicateRecordCloning", &PyDbIdMapping::duplicateRecordCloning, DS.ARGS())
        .def("idPairs", &PyDbIdMapping::idPairs, DS.ARGS())
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

//TODO: test! AutoCAD .NET seems to have a memcpy 
PyDbIdMapping::PyDbIdMapping(const AcDbIdMapping& mapping)
    : m_pyImp(new AcDbIdMapping(), PyDbIdMappingDeleter())
{
    memcpy_s(m_pyImp.get(), sizeof(AcDbIdMapping), std::addressof(mapping), sizeof(AcDbIdMapping));
}

//TODO: test for UB this is for PyDbObjectOverrule where we know the scope.
PyDbIdMapping::PyDbIdMapping(const AcDbIdMapping& mapping, bool forceKeepAlive)
    : m_pyImp(const_cast<AcDbIdMapping*>(std::addressof(mapping)), PyDbIdMappingDeleter(forceKeepAlive))
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

void PyDbIdMapping::forceKeepAlive(bool flag)
{
    auto del_p = std::get_deleter<PyDbIdMappingDeleter>(m_pyImp);
    if (del_p != nullptr)
        del_p->m_forceKeepAlive = flag;
    else
        PyThrowBadEs(Acad::eNotApplicable);
}

AcDbIdMapping* PyDbIdMapping::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbIdMapping*>(m_pyImp.get());
}
