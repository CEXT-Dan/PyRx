#include "stdafx.h"
#include "PyDbSymbolTable.h"
#include "PyDbObjectId.h"

using namespace boost::python;

//---------------------------------------------------------------------------------------- -
//PyDbSymbolTable wrapper
void makeAcDbSymbolTableWrapper()
{
    static auto wrapper = class_<PyDbSymbolTable, bases<PyDbObject>>("SymbolTable", boost::python::no_init)
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("getAt", &PyDbSymbolTable::getAt)
        .def<bool(PyDbSymbolTable::*)(const std::string&)>("has", &PyDbSymbolTable::has)
        .def<bool(PyDbSymbolTable::*)(const PyDbObjectId&)>("has", &PyDbSymbolTable::has)
        .def("symbolIds", &PyDbSymbolTable::symbolIds)
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
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    AcDbObjectId id;
    imp->getAt(utf8_to_wstr(entryName).c_str(), id);
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

boost::python::list PyDbSymbolTable::symbolIds()
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
