#include "stdafx.h"
#include "PyDbSymbolTable.h"
#include "PyDbSymbolTableRecord.h"


using namespace boost::python;

//---------------------------------------------------------------------------------------- -
//PyDbSymbolTable wrapper
void makePyDbSymbolTableWrapper()
{
    PyDocString DS("SymbolTable");
    class_<PyDbSymbolTable, bases<PyDbObject>>("SymbolTable", boost::python::no_init)
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>(DS.ARGS({ "id: ObjectId", "mode: PyDb.OpenMode=PyDb.OpenMode.kForRead" })))
        .def("getAt", &PyDbSymbolTable::getAt, DS.ARGS({ "val: str" }, 9072))
        .def("add", &PyDbSymbolTable::add, DS.ARGS({ "val: PyDb.SymbolTableRecord" }, 9071))
        .def("has", &PyDbSymbolTable::has1)
        .def("has", &PyDbSymbolTable::has2, DS.ARGS({ "val: str|PyDb.ObjectId" }, 9074))
        .def("toDict", &PyDbSymbolTable::toDict, DS.ARGS())
        .def("recordIds", &PyDbSymbolTable::recordIds, DS.ARGS())
        .def("desc", &PyDbSymbolTable::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cast", &PyDbSymbolTable::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        .def("className", &PyDbSymbolTable::className, DS.SARGS()).staticmethod("className")
        .def("cloneFrom", &PyDbSymbolTable::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")

        .def("__iter__", range(&PyDbSymbolTable::begin, &PyDbBlockTable::end))
        .def("__getitem__", &PyDbSymbolTable::getAt, DS.ARGS({ "val: str" }))
        .def("__contains__", &PyDbSymbolTable::has1)
        .def("__contains__", &PyDbSymbolTable::has2, DS.ARGS({ "val: str|PyDb.ObjectId" }))
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
    : PyDbObject(openAcDbObject<AcDbSymbolTable>(id, mode), true)
{
}

PyDbObjectId PyDbSymbolTable::getAt(const std::string& entryName)
{
    AcDbObjectId id;
    PyThrowBadEs(impObj()->getAt(utf8_to_wstr(entryName).c_str(), id));
    return PyDbObjectId(id);
}

bool PyDbSymbolTable::has1(const std::string& entryName)
{
    return impObj()->has(utf8_to_wstr(entryName).c_str());
}

bool PyDbSymbolTable::has2(const PyDbObjectId& entryid)
{
    return impObj()->has(entryid.m_id);
}

PyDbObjectId PyDbSymbolTable::add(const PyDbSymbolTableRecord& pRecord)
{
    PyDbObjectId id;
    PyThrowBadEs(impObj()->add(id.m_id, pRecord.impObj()));
    return id;
}

boost::python::list PyDbSymbolTable::recordIds()
{
    PyAutoLockGIL lock;
    AcDbSymbolTableIterator* pIter = nullptr;
    PyThrowBadEs(impObj()->newIterator(pIter));
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
    PyThrowBadEs(impObj()->newIterator(pIter));
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
                    const std::string& utf8name = wstr_to_utf8(name);
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
    return PyDbObjectCloneFrom<PyDbSymbolTable, AcDbSymbolTable>(src);
}

PyDbSymbolTable PyDbSymbolTable::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbSymbolTable>(src);
}

AcDbSymbolTable* PyDbSymbolTable::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<AcDbSymbolTable*>(m_pyImp.get());
}

void PyDbSymbolTable::filliterator()
{
    auto [es, iter] = makeAcDbSymbolTableIterator(*impObj());
    if (es == eOk)
    {
        PyDbObjectId id;
        m_iterable.clear();
        for (iter->start(); !iter->done(); iter->step())
        {
            if (iter->getRecordId(id.m_id) == eOk)
                m_iterable.push_back(id);
        }
    }
    PyThrowBadEs(es);
}

std::vector<PyDbObjectId>::iterator PyDbSymbolTable::begin()
{
    return m_iterable.begin();
}

std::vector<PyDbObjectId>::iterator PyDbSymbolTable::end()
{
    filliterator();
    return m_iterable.end();
}


//---------------------------------------------------------------------------------------- -
//AcDbDimStyleTable
void makePyDbDimStyleTableWrapper()
{
    PyDocString DS("DimStyleTable");
    class_<PyDbDimStyleTable, bases<PyDbSymbolTable>>("DimStyleTable", boost::python::no_init)
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>(DS.ARGS({ "id: ObjectId", "mode: PyDb.OpenMode=PyDb.OpenMode.kForRead" })))
        .def("add", &PyDbDimStyleTable::add, DS.ARGS({ "val: PyDb.DimStyleTableRecord" }, 4046))
        .def("className", &PyDbDimStyleTable::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbDimStyleTable::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbDimStyleTable::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbDimStyleTable::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyDbDimStyleTable::PyDbDimStyleTable(AcDbDimStyleTable* ptr, bool autoDelete)
    : PyDbSymbolTable(ptr, autoDelete)
{
}

PyDbDimStyleTable::PyDbDimStyleTable(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbSymbolTable(openAcDbObject<AcDbDimStyleTable>(id, mode), false)
{
}

PyDbDimStyleTable::PyDbDimStyleTable(const PyDbObjectId& id)
    : PyDbDimStyleTable(id, AcDb::OpenMode::kForRead)
{
}

PyDbObjectId PyDbDimStyleTable::add(const PyDbDimStyleTableRecord& entry)
{
    PyDbObjectId id;
    PyThrowBadEs(impObj()->add(id.m_id, entry.impObj()));
    return id;
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
    return PyDbObjectCloneFrom<PyDbDimStyleTable, AcDbDimStyleTable>(src);
}

PyDbDimStyleTable PyDbDimStyleTable::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbDimStyleTable>(src);
}

AcDbDimStyleTable* PyDbDimStyleTable::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<AcDbDimStyleTable*>(m_pyImp.get());
}


//---------------------------------------------------------------------------------------- -
//PyDbBlockTable
void makePyDbBlockTableWrapper()
{
    PyDocString DS("BlockTable");
    class_<PyDbBlockTable, bases<PyDbSymbolTable>>("BlockTable", boost::python::no_init)
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>(DS.ARGS({ "id: ObjectId", "mode: PyDb.OpenMode=PyDb.OpenMode.kForRead" })))
        .def("add", &PyDbBlockTable::add, DS.ARGS({ "block : BlockTableRecord" }, 2598))
        .def("className", &PyDbBlockTable::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbBlockTable::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbBlockTable::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbBlockTable::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyDbBlockTable::PyDbBlockTable(AcDbBlockTable* ptr, bool autoDelete)
    : PyDbSymbolTable(ptr, autoDelete)
{
}

PyDbBlockTable::PyDbBlockTable(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbSymbolTable(openAcDbObject<AcDbBlockTable>(id, mode), false)
{
}

PyDbBlockTable::PyDbBlockTable(const PyDbObjectId& id)
    : PyDbBlockTable(id, AcDb::OpenMode::kForRead)
{
}

PyDbObjectId PyDbBlockTable::add(const PyDbBlockTableRecord& entry)
{
    PyDbObjectId id;
    if (auto es = impObj()->add(id.m_id, entry.impObj()); es != eOk)
        throw PyAcadErrorStatus(es);
    return id;
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
    return PyDbObjectCloneFrom<PyDbBlockTable, AcDbBlockTable>(src);
}

PyDbBlockTable PyDbBlockTable::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbBlockTable>(src);
}

AcDbBlockTable* PyDbBlockTable::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<AcDbBlockTable*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
//PyDbTextStyleTable
void makePyDbTextStyleTableWrapper()
{
    PyDocString DS("TextStyleTable");
    class_<PyDbTextStyleTable, bases<PyDbSymbolTable>>("TextStyleTable", boost::python::no_init)
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>(DS.ARGS({ "id: ObjectId", "mode: PyDb.OpenMode=PyDb.OpenMode.kForRead" })))
        .def("add", &PyDbTextStyleTable::add, DS.ARGS({ "val: PyDb.TextStyleTableRecord" }, 9717))
        .def("className", &PyDbTextStyleTable::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbTextStyleTable::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbTextStyleTable::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbTextStyleTable::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
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
    : PyDbSymbolTable(openAcDbObject<AcDbTextStyleTable>(id, mode), false)
{
}

PyDbObjectId PyDbTextStyleTable::add(const PyDbTextStyleTableRecord& entry)
{
    PyDbObjectId id;
    PyThrowBadEs(impObj()->add(id.m_id, entry.impObj()));
    return id;
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
    return PyDbObjectCloneFrom<PyDbTextStyleTable, AcDbTextStyleTable>(src);
}

PyDbTextStyleTable PyDbTextStyleTable::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbTextStyleTable>(src);
}

AcDbTextStyleTable* PyDbTextStyleTable::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<AcDbTextStyleTable*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
//PyDbLinetypeTable
void makePyDbLinetypeTableWrapper()
{
    PyDocString DS("LinetypeTable");
    class_<PyDbLinetypeTable, bases<PyDbSymbolTable>>("LinetypeTable", boost::python::no_init)
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>(DS.ARGS({ "id: ObjectId", "mode: PyDb.OpenMode=PyDb.OpenMode.kForRead" })))
        .def("add", &PyDbLinetypeTable::add, DS.ARGS({ "val: PyDb.LinetypeTableRecord" }, 6066))
        .def("desc", &PyDbLinetypeTable::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cast", &PyDbLinetypeTable::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        .def("cloneFrom", &PyDbLinetypeTable::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("className", &PyDbLinetypeTable::className, DS.SARGS()).staticmethod("className")
        ;
}

PyDbLinetypeTable::PyDbLinetypeTable(AcDbLinetypeTable* ptr, bool autoDelete)
    : PyDbSymbolTable(ptr, autoDelete)
{
}

PyDbLinetypeTable::PyDbLinetypeTable(const PyDbObjectId& id)
    : PyDbLinetypeTable(id, AcDb::OpenMode::kForRead)
{
}

PyDbLinetypeTable::PyDbLinetypeTable(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbSymbolTable(openAcDbObject<AcDbLinetypeTable>(id, mode), false)
{
}

PyDbObjectId PyDbLinetypeTable::add(const PyDbLinetypeTableRecord& entry)
{
    PyDbObjectId id;
    PyThrowBadEs(impObj()->add(id.m_id, entry.impObj()));
    return id;
}

std::string PyDbLinetypeTable::className()
{
    return "AcDbLinetypeTable";
}

PyRxClass PyDbLinetypeTable::desc()
{
    return PyRxClass(AcDbLinetypeTable::desc(), false);
}

PyDbLinetypeTable PyDbLinetypeTable::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbLinetypeTable, AcDbLinetypeTable>(src);
}

PyDbLinetypeTable PyDbLinetypeTable::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbLinetypeTable>(src);
}

AcDbLinetypeTable* PyDbLinetypeTable::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<AcDbLinetypeTable*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
//PyDbRegAppTable
void makePyDbRegAppTableWrapper()
{
    PyDocString DS("RegAppTable");
    class_<PyDbRegAppTable, bases<PyDbSymbolTable>>("RegAppTable", boost::python::no_init)
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>(DS.ARGS({ "id: ObjectId", "mode: PyDb.OpenMode=PyDb.OpenMode.kForRead" })))
        .def("add", &PyDbRegAppTable::add, DS.ARGS({ "val: PyDb.RegAppTableRecord" }, 8150))
        .def("desc", &PyDbRegAppTable::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cast", &PyDbRegAppTable::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        .def("cloneFrom", &PyDbRegAppTable::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("className", &PyDbRegAppTable::className, DS.SARGS()).staticmethod("className")
        ;
}

PyDbRegAppTable::PyDbRegAppTable(AcDbRegAppTable* ptr, bool autoDelete)
    : PyDbSymbolTable(ptr, autoDelete)
{
}

PyDbRegAppTable::PyDbRegAppTable(const PyDbObjectId& id)
    : PyDbRegAppTable(id, AcDb::OpenMode::kForRead)
{
}

PyDbRegAppTable::PyDbRegAppTable(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbSymbolTable(openAcDbObject<AcDbRegAppTable>(id, mode), false)
{
}

PyDbObjectId PyDbRegAppTable::add(const PyDbRegAppTableRecord& entry)
{
    PyDbObjectId id;
    PyThrowBadEs(impObj()->add(id.m_id, entry.impObj()));
    return id;
}

std::string PyDbRegAppTable::className()
{
    return "AcDbRegAppTable";
}

PyRxClass PyDbRegAppTable::desc()
{
    return PyRxClass(AcDbRegAppTable::desc(), false);
}

PyDbRegAppTable PyDbRegAppTable::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbRegAppTable, AcDbRegAppTable>(src);
}

PyDbRegAppTable PyDbRegAppTable::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbRegAppTable>(src);
}

AcDbRegAppTable* PyDbRegAppTable::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<AcDbRegAppTable*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
//PyDbUCSTable
void makePyDbUCSTableWrapper()
{
    PyDocString DS("UCSTable");
    class_<PyDbUCSTable, bases<PyDbSymbolTable>>("UCSTable", boost::python::no_init)
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>(DS.ARGS({ "id: ObjectId", "mode: PyDb.OpenMode=PyDb.OpenMode.kForRead" })))
        .def("add", &PyDbUCSTable::add, DS.ARGS({ "val: PyDb.UCSTableRecord" }, 9826))
        .def("desc", &PyDbUCSTable::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cast", &PyDbUCSTable::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        .def("cloneFrom", &PyDbUCSTable::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("className", &PyDbUCSTable::className, DS.SARGS()).staticmethod("className")
        ;
}

PyDbUCSTable::PyDbUCSTable(AcDbUCSTable* ptr, bool autoDelete)
    : PyDbSymbolTable(ptr, autoDelete)
{
}

PyDbUCSTable::PyDbUCSTable(const PyDbObjectId& id)
    : PyDbUCSTable(id, AcDb::OpenMode::kForRead)
{
}

PyDbUCSTable::PyDbUCSTable(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbSymbolTable(openAcDbObject<AcDbUCSTable>(id, mode), false)
{
}

PyDbObjectId PyDbUCSTable::add(const PyDbUCSTableRecord& entry)
{
    PyDbObjectId id;
    PyThrowBadEs(impObj()->add(id.m_id, entry.impObj()));
    return id;
}

std::string PyDbUCSTable::className()
{
    return "AcDbUCSTable";
}

PyRxClass PyDbUCSTable::desc()
{
    return PyRxClass(AcDbUCSTable::desc(), false);
}

PyDbUCSTable PyDbUCSTable::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbUCSTable, AcDbUCSTable>(src);
}

PyDbUCSTable PyDbUCSTable::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbUCSTable>(src);
}

AcDbUCSTable* PyDbUCSTable::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<AcDbUCSTable*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
//PyDbLayerTable
void makePyDbLayerTableWrapper()
{
    PyDocString DS("LayerTable");
    class_<PyDbLayerTable, bases<PyDbSymbolTable>>("LayerTable", boost::python::no_init)
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>(DS.ARGS({ "id: ObjectId", "mode: PyDb.OpenMode=PyDb.OpenMode.kForRead" })))
        .def("add", &PyDbLayerTable::add, DS.ARGS({ "val: PyDb.LayerTableRecord" }, 5819))
        .def("desc", &PyDbLayerTable::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cast", &PyDbLayerTable::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        .def("cloneFrom", &PyDbLayerTable::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("className", &PyDbLayerTable::className, DS.SARGS()).staticmethod("className")
        ;
}

PyDbLayerTable::PyDbLayerTable(AcDbLayerTable* ptr, bool autoDelete)
    : PyDbSymbolTable(ptr, autoDelete)
{
}

PyDbLayerTable::PyDbLayerTable(const PyDbObjectId& id)
    : PyDbLayerTable(id, AcDb::OpenMode::kForRead)
{
}

PyDbLayerTable::PyDbLayerTable(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbSymbolTable(openAcDbObject<AcDbLayerTable>(id, mode), false)
{
}

PyDbObjectId PyDbLayerTable::add(const PyDbLayerTableRecord& entry)
{
    PyDbObjectId id;
    PyThrowBadEs(impObj()->add(id.m_id, entry.impObj()));
    return id;
}

std::string PyDbLayerTable::className()
{
    return "AcDbLayerTable";
}

PyRxClass PyDbLayerTable::desc()
{
    return PyRxClass(AcDbLayerTable::desc(), false);
}

PyDbLayerTable PyDbLayerTable::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbLayerTable, AcDbLayerTable>(src);
}

PyDbLayerTable PyDbLayerTable::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbLayerTable>(src);
}

AcDbLayerTable* PyDbLayerTable::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<AcDbLayerTable*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
//PyDbAbstractViewTable 
void makePyDbAbstractViewTableWrapper()
{
    PyDocString DS("AbstractViewTable");
    class_<PyDbAbstractViewTable, bases<PyDbSymbolTable>>("AbstractViewTable", boost::python::no_init)
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>(DS.ARGS({ "id: ObjectId", "mode: PyDb.OpenMode=PyDb.OpenMode.kForRead" })))
        .def("add", &PyDbAbstractViewTable::add, DS.ARGS({ "val: PyDb.AbstractViewTableRecord" }, 1404))
        .def("desc", &PyDbAbstractViewTable::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cast", &PyDbAbstractViewTable::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        .def("cloneFrom", &PyDbAbstractViewTable::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("className", &PyDbAbstractViewTable::className, DS.SARGS()).staticmethod("className")
        ;
}

PyDbAbstractViewTable::PyDbAbstractViewTable(AcDbAbstractViewTable* ptr, bool autoDelete)
    : PyDbSymbolTable(ptr, autoDelete)
{
}

PyDbAbstractViewTable::PyDbAbstractViewTable(const PyDbObjectId& id)
    : PyDbAbstractViewTable(id, AcDb::OpenMode::kForRead)
{
}

PyDbAbstractViewTable::PyDbAbstractViewTable(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbSymbolTable(openAcDbObject<AcDbAbstractViewTable>(id, mode), false)
{
}

PyDbObjectId PyDbAbstractViewTable::add(const PyDbAbstractViewTableRecord& entry)
{
    return PyDbSymbolTable::add(entry);
}

std::string PyDbAbstractViewTable::className()
{
    return "AcDbAbstractViewTable";
}

PyRxClass PyDbAbstractViewTable::desc()
{
    return PyRxClass(AcDbAbstractViewTable::desc(), false);
}

PyDbAbstractViewTable PyDbAbstractViewTable::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbAbstractViewTable, AcDbAbstractViewTable>(src);
}

PyDbAbstractViewTable PyDbAbstractViewTable::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbAbstractViewTable>(src);
}

AcDbAbstractViewTable* PyDbAbstractViewTable::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<AcDbAbstractViewTable*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
//PyDbViewportTable 
void makePyDbViewportTableWrapper()
{
    PyDocString DS("ViewportTable");
    class_<PyDbViewportTable, bases<PyDbAbstractViewTable>>("ViewportTable")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>(DS.ARGS({ "id: ObjectId", "mode: PyDb.OpenMode=PyDb.OpenMode.kForRead" })))
        .def("add", &PyDbViewportTable::add, DS.ARGS({ "val: PyDb.AbstractViewTableRecord" }, 10013))
        .def("desc", &PyDbViewportTable::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cast", &PyDbViewportTable::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        .def("cloneFrom", &PyDbViewportTable::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("className", &PyDbViewportTable::className, DS.SARGS()).staticmethod("className")
        ;
}

PyDbViewportTable::PyDbViewportTable()
    : PyDbViewportTable(new AcDbViewportTable(), true)
{
}

PyDbViewportTable::PyDbViewportTable(const PyDbObjectId& id)
    : PyDbViewportTable(openAcDbObject<AcDbViewportTable>(id, AcDb::OpenMode::kForRead), false)
{
}

PyDbViewportTable::PyDbViewportTable(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbViewportTable(openAcDbObject<AcDbViewportTable>(id, mode), false)
{
}

PyDbViewportTable::PyDbViewportTable(AcDbViewportTable* ptr, bool autoDelete)
    : PyDbAbstractViewTable(ptr, autoDelete)
{
}

PyDbObjectId PyDbViewportTable::add(const PyDbViewportTableRecord& entry)
{
    return PyDbAbstractViewTable::add(entry);
}

std::string PyDbViewportTable::className()
{
    return "AcDbViewportTable";
}

PyRxClass PyDbViewportTable::desc()
{
    return PyRxClass(AcDbViewportTable::desc(), false);
}

PyDbViewportTable PyDbViewportTable::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbViewportTable, AcDbViewportTable>(src);
}

PyDbViewportTable PyDbViewportTable::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbViewportTable>(src);
}

AcDbViewportTable* PyDbViewportTable::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<AcDbViewportTable*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
//PyDbViewTable 
void makePyDbViewTableWrapper()
{
    PyDocString DS("ViewTable");
    class_<PyDbViewTable, bases<PyDbAbstractViewTable>>("ViewTable")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>(DS.ARGS({ "id: ObjectId", "mode: PyDb.OpenMode=PyDb.OpenMode.kForRead" })))
        .def("add", &PyDbAbstractViewTable::add, DS.ARGS({ "val: PyDb.AbstractViewTableRecord" }, 10255))
        .def("desc", &PyDbAbstractViewTable::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cast", &PyDbAbstractViewTable::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        .def("cloneFrom", &PyDbAbstractViewTable::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("className", &PyDbAbstractViewTable::className, DS.SARGS()).staticmethod("className")
        ;
}

PyDbViewTable::PyDbViewTable()
    : PyDbViewTable(new AcDbViewTable(), true)
{
}

PyDbViewTable::PyDbViewTable(const PyDbObjectId& id)
    : PyDbViewTable(openAcDbObject<AcDbViewTable>(id, AcDb::OpenMode::kForRead), false)
{
}

PyDbViewTable::PyDbViewTable(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbViewTable(openAcDbObject<AcDbViewTable>(id, mode), false)
{
}

PyDbViewTable::PyDbViewTable(AcDbViewTable* ptr, bool autoDelete)
    : PyDbAbstractViewTable(ptr, autoDelete)
{
}

PyDbObjectId PyDbViewTable::add(const PyDbViewTableRecord& entry)
{
    return PyDbAbstractViewTable::add(entry);
}

std::string PyDbViewTable::className()
{
    return "AcDbViewTable";
}

PyRxClass PyDbViewTable::desc()
{
    return PyRxClass(AcDbViewTable::desc(), false);
}

PyDbViewTable PyDbViewTable::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbViewTable, AcDbViewTable>(src);
}

PyDbViewTable PyDbViewTable::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbViewTable>(src);
}

AcDbViewTable* PyDbViewTable::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<AcDbViewTable*>(m_pyImp.get());
}
