#include "stdafx.h"
#include "PyDbSymbolTable.h"
#include "PyDbObjectId.h"
#include "PyDbSymbolTableRecord.h"
#include "PyDbBlockTableRecord.h"

using namespace boost::python;

//---------------------------------------------------------------------------------------- -
//PyDbSymbolTable wrapper
void makeAcDbSymbolTableWrapper()
{
    class_<PyDbSymbolTable, bases<PyDbObject>>("SymbolTable", boost::python::no_init)
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("getAt", &PyDbSymbolTable::getAt)
        .def<bool(PyDbSymbolTable::*)(const std::string&)>("has", &PyDbSymbolTable::has)
        .def<bool(PyDbSymbolTable::*)(const PyDbObjectId&)>("has", &PyDbSymbolTable::has)
        .def("recordIds", &PyDbSymbolTable::recordIds)
        .def("className", &PyDbSymbolTable::className).staticmethod("className")
        .def("desc", &PyDbSymbolTable::desc).staticmethod("desc")
        ;
}

//---------------------------------------------------------------------------------------- -
//PyDbSymbolTable
PyDbSymbolTable::PyDbSymbolTable(AcDbSymbolTable* ptr, bool autoDelete)
    : PyDbObject(ptr, autoDelete)
{
}

PyDbSymbolTable::PyDbSymbolTable(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbObject(nullptr, true)
{
    AcDbSymbolTable* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbSymbolTable>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);;
}

PyDbObjectId PyDbSymbolTable::getAt(const std::string& entryName)
{
    AcDbObjectId id;
    if (auto es = impObj()->getAt(utf8_to_wstr(entryName).c_str(), id); es != eOk)
        throw PyAcadErrorStatus(es);
    return PyDbObjectId(id);
}

bool PyDbSymbolTable::has(const std::string& entryName)
{
    return impObj()->has(utf8_to_wstr(entryName).c_str());
}

bool PyDbSymbolTable::has(const PyDbObjectId& entryid)
{
    return impObj()->has(entryid.m_id);
}

boost::python::list PyDbSymbolTable::recordIds()
{
    PyAutoLockGIL lock;
    AcDbSymbolTableIterator* pIter = nullptr;
    if (impObj()->newIterator(pIter) != eOk)
        throw PyAcadErrorStatus(eOutOfMemory);

    boost::python::list _items;
    for (std::unique_ptr<AcDbSymbolTableIterator> iter(pIter); !iter->done(); iter->step())
    {
        AcDbObjectId id;
        if (iter->getRecordId(id) == eOk)
            _items.append(PyDbObjectId(id));
    }
    return _items;
}

std::string PyDbSymbolTable::className()
{
    return "AcDbSymbolTable";
}

PyRxClass PyDbSymbolTable::desc()
{
    return PyRxClass(AcDbSymbolTable::desc(), false);
}

AcDbSymbolTable* PyDbSymbolTable::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbSymbolTable*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
//AcDbDimStyleTable
void makePyDbDimStyleTableWrapper()
{
    class_<PyDbDimStyleTable, bases<PyDbSymbolTable>>("DimStyleTable", boost::python::no_init)
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("getAt", &PyDbDimStyleTable::getAt)
        .def("add", &PyDbDimStyleTable::add)
        .def("recordIds", &PyDbSymbolTable::recordIds)
        .def("className", &PyDbDimStyleTable::className).staticmethod("className")
        .def("desc", &PyDbDimStyleTable::desc).staticmethod("desc")
        ;
}

PyDbDimStyleTable::PyDbDimStyleTable(AcDbDimStyleTable* ptr, bool autoDelete)
    : PyDbSymbolTable(ptr, autoDelete)
{
}

PyDbDimStyleTable::PyDbDimStyleTable(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbSymbolTable(nullptr, false)
{
    AcDbDimStyleTable* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbDimStyleTable>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
}

PyDbObjectId PyDbDimStyleTable::getAt(const std::string& entryName)
{
    AcDbObjectId id;
    if (auto es = impObj()->getAt(utf8_to_wstr(entryName).c_str(), id); es != eOk)
        throw PyAcadErrorStatus(es);
    return PyDbObjectId(id);
}

PyDbObjectId PyDbDimStyleTable::add(const PyDbDimStyleTableRecord& entry)
{
    AcDbObjectId id;
    if (auto es = impObj()->add(id, entry.impObj()); es != eOk)
        throw PyAcadErrorStatus(es);
    return PyDbObjectId(id);
}

boost::python::list PyDbDimStyleTable::recordIds()
{
    PyAutoLockGIL lock;
    AcDbDimStyleTableIterator* pIter = nullptr;
    if (impObj()->newIterator(pIter) != eOk)
        throw PyAcadErrorStatus(eOutOfMemory);

    boost::python::list _items;
    for (std::unique_ptr<AcDbDimStyleTableIterator> iter(pIter); !iter->done(); iter->step())
    {
        AcDbObjectId id;
        if (iter->getRecordId(id) == eOk)
            _items.append(PyDbObjectId(id));
    }
    return _items;
}

std::string PyDbDimStyleTable::className()
{
    return "AcDbDimStyleTable";
}

PyRxClass PyDbDimStyleTable::desc()
{
    return PyRxClass(AcDbDimStyleTable::desc(), false);
}

AcDbDimStyleTable* PyDbDimStyleTable::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbDimStyleTable*>(m_pyImp.get());
}


//---------------------------------------------------------------------------------------- -
//PyDbBlockTable
void makePyDbBlockTableWrapper()
{
    class_<PyDbBlockTable, bases<PyDbSymbolTable>>("BlockTable", boost::python::no_init)
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("getAt", &PyDbBlockTable::getAt)
        .def("add", &PyDbBlockTable::add)
        .def("recordIds", &PyDbBlockTable::recordIds)
        .def("className", &PyDbBlockTable::className).staticmethod("className")
        .def("desc", &PyDbBlockTable::desc).staticmethod("desc")

        ;
}

PyDbBlockTable::PyDbBlockTable(AcDbBlockTable* ptr, bool autoDelete)
    : PyDbSymbolTable(ptr, autoDelete)
{
}

PyDbBlockTable::PyDbBlockTable(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbSymbolTable(nullptr, false)
{
    AcDbBlockTable* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbBlockTable>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
}

PyDbObjectId PyDbBlockTable::getAt(const std::string& entryName)
{
    AcDbObjectId id;
    if (auto es = impObj()->getAt(utf8_to_wstr(entryName).c_str(), id); es != eOk)
        throw PyAcadErrorStatus(es);
    return PyDbObjectId(id);
}

PyDbObjectId PyDbBlockTable::add(const PyDbBlockTableRecord& entry)
{
    AcDbObjectId id;
    if (auto es = impObj()->add(id, entry.impObj()); es != eOk)
        throw PyAcadErrorStatus(es);
    return PyDbObjectId(id);
}

boost::python::list PyDbBlockTable::recordIds()
{
    PyAutoLockGIL lock;
    AcDbBlockTableIterator* pIter = nullptr;
    if (impObj()->newIterator(pIter) != eOk)
        throw PyAcadErrorStatus(eOutOfMemory);

    boost::python::list _items;
    for (std::unique_ptr<AcDbBlockTableIterator> iter(pIter); !iter->done(); iter->step())
    {
        AcDbObjectId id;
        if (iter->getRecordId(id) == eOk)
            _items.append(PyDbObjectId(id));
    }
    return _items;
}

std::string PyDbBlockTable::className()
{
    return "AcDbBlockTable";
}

PyRxClass PyDbBlockTable::desc()
{
    return PyRxClass(AcDbBlockTable::desc(), false);
}

AcDbBlockTable* PyDbBlockTable::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbBlockTable*>(m_pyImp.get());
}
