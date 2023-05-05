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
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("getAt", &PyDbSymbolTable::getAt)
        .def<bool(PyDbSymbolTable::*)(const std::string&)>("has", &PyDbSymbolTable::has)
        .def<bool(PyDbSymbolTable::*)(const PyDbObjectId&)>("has", &PyDbSymbolTable::has)
        .def("recordIds", &PyDbSymbolTable::recordIds)
        .def("className", &PyDbSymbolTable::className).staticmethod("className")
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
    this->resetImp(pobj, false, true);
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
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
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->has(utf8_to_wstr(entryName).c_str());
}

bool PyDbSymbolTable::has(const PyDbObjectId& entryid)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->has(entryid.m_id);
}

boost::python::list PyDbSymbolTable::recordIds()
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();

    AcDbSymbolTableIterator* pIter = nullptr;
    if(imp->newIterator(pIter) != eOk)
        throw PyNullObject();

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

AcDbSymbolTable* PyDbSymbolTable::impObj() const
{
    return static_cast<AcDbSymbolTable*>(m_pImp.get());
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
    AcDbDimStyleTableIterator* pIter = nullptr;
    if (impObj()->newIterator(pIter) != eOk)
        throw PyNullObject();

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

AcDbDimStyleTable* PyDbDimStyleTable::impObj() const
{
    if (m_pImp == nullptr)
        throw PyNullObject();
    return static_cast<AcDbDimStyleTable*>(m_pImp.get());
}
