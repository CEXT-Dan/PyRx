#include "stdafx.h"
#include "PyDbSymbolTable.h"
#include "PyDbObjectId.h"
#include "PyDbSymbolTableRecord.h"


using namespace boost::python;

//---------------------------------------------------------------------------------------- -
//PyDbSymbolTable wrapper
void makeAcDbSymbolTableWrapper()
{
    class_<PyDbSymbolTable, bases<PyDbObject>>("SymbolTable", boost::python::no_init)
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("getAt", &PyDbSymbolTable::getAt)
        .def("add", &PyDbSymbolTable::add)
        .def<bool(PyDbSymbolTable::*)(const std::string&)>("has", &PyDbSymbolTable::has)
        .def<bool(PyDbSymbolTable::*)(const PyDbObjectId&)>("has", &PyDbSymbolTable::has)
        .def("ids", &PyDbSymbolTable::ids)
        .def("toDict", &PyDbSymbolTable::toDict)
        .def("className", &PyDbSymbolTable::className).staticmethod("className")
        .def("desc", &PyDbSymbolTable::desc).staticmethod("desc")
        .def("cloneFrom", &PyDbSymbolTable::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbSymbolTable::cast).staticmethod("cast")
        .def("__getitem__", &PyDbSymbolTable::getAt)
        ;
}

//---------------------------------------------------------------------------------------- -
//PyDbSymbolTable
PyDbSymbolTable::PyDbSymbolTable(AcDbSymbolTable* ptr, bool autoDelete)
    : PyDbObject(ptr, autoDelete)
{
}

PyDbSymbolTable::PyDbSymbolTable(const PyDbObjectId& id)
    : PyDbSymbolTable(id, AcDb::OpenMode::kForRead)
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

PyDbObjectId PyDbSymbolTable::add(const PyDbSymbolTableRecord& pRecord)
{
    PyDbObjectId recordId;
    if (auto es = impObj()->add(recordId.m_id, pRecord.impObj()); es != eOk)
        throw PyAcadErrorStatus(es);
    return recordId;
}

boost::python::list PyDbSymbolTable::ids()
{
    PyAutoLockGIL lock;
    AcDbSymbolTableIterator* pIter = nullptr;
    if (impObj()->newIterator(pIter) != eOk)
        throw PyAcadErrorStatus(eOutOfMemory);

    boost::python::list _items;
    for (std::unique_ptr<AcDbSymbolTableIterator> iter(pIter); !iter->done(); iter->step())
    {
        PyDbObjectId id;
        if (iter->getRecordId(id.m_id) == eOk)
            _items.append(id);
    }
    return _items;
}

boost::python::dict PyDbSymbolTable::toDict()
{
    PyAutoLockGIL lock;
  
    AcDbSymbolTableIterator* pIter = nullptr;
    if (impObj()->newIterator(pIter) != eOk)
        throw PyAcadErrorStatus(eOutOfMemory);

    boost::python::dict _items;
    for (std::unique_ptr<AcDbSymbolTableIterator> iter(pIter); !iter->done(); iter->step())
    {
        PyDbObjectId id;
        if (iter->getRecordId(id.m_id) == eOk)
        {
            AcDbSymbolTableRecordPointer<AcDbSymbolTableRecord> record(id.m_id, AcDb::kForRead);
            if (record.openStatus() == eOk)
            {
                const TCHAR* name = nullptr;
                if (record->getName(name) == eOk)
                {
                    std::string utf8name = wstr_to_utf8(name);
                    _items[utf8name] = id;
                }
            }
        }
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

PyDbSymbolTable PyDbSymbolTable::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbSymbolTable::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbSymbolTable(static_cast<AcDbSymbolTable*>(src.impObj()->clone()), true);
}

PyDbSymbolTable PyDbSymbolTable::cast(const PyRxObject& src)
{
    PyDbSymbolTable dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
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
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("add", &PyDbDimStyleTable::add)
        .def("className", &PyDbDimStyleTable::className).staticmethod("className")
        .def("desc", &PyDbDimStyleTable::desc).staticmethod("desc")
        .def("cloneFrom", &PyDbDimStyleTable::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbDimStyleTable::cast).staticmethod("cast")
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

PyDbDimStyleTable::PyDbDimStyleTable(const PyDbObjectId& id)
    : PyDbDimStyleTable(id, AcDb::OpenMode::kForRead)
{
}

PyDbObjectId PyDbDimStyleTable::add(const PyDbDimStyleTableRecord& entry)
{
    AcDbObjectId id;
    if (auto es = impObj()->add(id, entry.impObj()); es != eOk)
        throw PyAcadErrorStatus(es);
    return PyDbObjectId(id);
}

std::string PyDbDimStyleTable::className()
{
    return "AcDbDimStyleTable";
}

PyRxClass PyDbDimStyleTable::desc()
{
    return PyRxClass(AcDbDimStyleTable::desc(), false);
}

PyDbDimStyleTable PyDbDimStyleTable::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbDimStyleTable::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbDimStyleTable(static_cast<AcDbDimStyleTable*>(src.impObj()->clone()), true);
}

PyDbDimStyleTable PyDbDimStyleTable::cast(const PyRxObject& src)
{
    PyDbDimStyleTable dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
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
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("add", &PyDbBlockTable::add)
        .def("className", &PyDbBlockTable::className).staticmethod("className")
        .def("desc", &PyDbBlockTable::desc).staticmethod("desc")
        .def("cloneFrom", &PyDbBlockTable::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbBlockTable::cast).staticmethod("cast")
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


PyDbBlockTable::PyDbBlockTable(const PyDbObjectId& id)
    : PyDbBlockTable(id, AcDb::OpenMode::kForRead)
{
}

PyDbObjectId PyDbBlockTable::add(const PyDbBlockTableRecord& entry)
{
    AcDbObjectId id;
    if (auto es = impObj()->add(id, entry.impObj()); es != eOk)
        throw PyAcadErrorStatus(es);
    return PyDbObjectId(id);
}

std::string PyDbBlockTable::className()
{
    return "AcDbBlockTable";
}

PyRxClass PyDbBlockTable::desc()
{
    return PyRxClass(AcDbBlockTable::desc(), false);
}

PyDbBlockTable PyDbBlockTable::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbBlockTable::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbBlockTable(static_cast<AcDbBlockTable*>(src.impObj()->clone()), true);
}

PyDbBlockTable PyDbBlockTable::cast(const PyRxObject& src)
{
    PyDbBlockTable dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbBlockTable* PyDbBlockTable::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbBlockTable*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
//PyDbTextStyleTable
void makePyDbTextStyleTableWrapper()
{
    class_<PyDbTextStyleTable, bases<PyDbSymbolTable>>("BlockTable", boost::python::no_init)
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("add", &PyDbTextStyleTable::add)
        .def("className", &PyDbTextStyleTable::className).staticmethod("className")
        .def("desc", &PyDbTextStyleTable::desc).staticmethod("desc")
        .def("cloneFrom", &PyDbTextStyleTable::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbTextStyleTable::cast).staticmethod("cast")
        ;
}

PyDbTextStyleTable::PyDbTextStyleTable(AcDbTextStyleTable* ptr, bool autoDelete)
    : PyDbSymbolTable(ptr, autoDelete)
{
}

PyDbTextStyleTable::PyDbTextStyleTable(const PyDbObjectId& id)
    : PyDbTextStyleTable(id, AcDb::OpenMode::kForRead)
{
}

PyDbTextStyleTable::PyDbTextStyleTable(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbSymbolTable(nullptr, false)
{
    AcDbTextStyleTable* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbTextStyleTable>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
}

PyDbObjectId PyDbTextStyleTable::add(const PyDbTextStyleTableRecord& entry)
{
    AcDbObjectId id;
    if (auto es = impObj()->add(id, entry.impObj()); es != eOk)
        throw PyAcadErrorStatus(es);
    return PyDbObjectId(id);
}

std::string PyDbTextStyleTable::className()
{
    return "AcDbTextStyleTable";
}

PyRxClass PyDbTextStyleTable::desc()
{
    return PyRxClass(AcDbTextStyleTable::desc(), false);
}

PyDbTextStyleTable PyDbTextStyleTable::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbTextStyleTable::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbTextStyleTable(static_cast<AcDbTextStyleTable*>(src.impObj()->clone()), true);
}

PyDbTextStyleTable PyDbTextStyleTable::cast(const PyRxObject& src)
{
    PyDbTextStyleTable dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbTextStyleTable* PyDbTextStyleTable::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbTextStyleTable*>(m_pyImp.get());
}
