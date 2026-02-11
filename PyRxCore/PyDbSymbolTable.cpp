#include "stdafx.h"
#include "PyDbSymbolTable.h"
#include "PyDbSymbolTableRecord.h"


using namespace boost::python;

struct SymbolTable_Iterator
{
    std::shared_ptr<AcDbSymbolTableIterator> pbtriter;
    Acad::ErrorStatus es = eOk;

    explicit SymbolTable_Iterator(const PyDbSymbolTable& btr)
    {
        AcDbSymbolTableIterator* _piter = nullptr;
        es = btr.impObj()->newIterator(_piter);
        if (es == eOk)
            pbtriter.reset(_piter);
        else
            PyThrowBadEs(es);
    }

    boost::python::tuple next() const
    {
        if (!pbtriter || pbtriter->done())
        {
            PyErr_SetString(PyExc_StopIteration, "End of Table");
            boost::python::throw_error_already_set();
        }
        AcString name;
        PyDbObjectId id;
        PyThrowBadEs(pbtriter->getRecordId(id.m_id));
        AcDbSymbolTableRecordPointer<AcDbSymbolTableRecord> ptr(id.m_id);
        PyThrowBadEs(ptr.openStatus());
        PyThrowBadEs(ptr->getName(name));
        pbtriter->step();
        return boost::python::make_tuple(wstr_to_utf8(name), id);
    }

    SymbolTable_Iterator& iter() { return *this; }
};

//---------------------------------------------------------------------------------------- -
//PyDbSymbolTable wrapper
void makePyDbSymbolTableWrapper()
{
    class_<SymbolTable_Iterator>("SymbolTableIterator", no_init)
        .def("__iter__", &SymbolTable_Iterator::iter, return_internal_reference<>())
        .def("__next__", &SymbolTable_Iterator::next);

    PyDocString DS("SymbolTable");
    class_<PyDbSymbolTable, bases<PyDbObject>>("SymbolTable", boost::python::no_init)
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: PyDb.ObjectId", "mode: PyDb.OpenMode = PyDb.OpenMode.kForRead", "erased: bool=False" })))
        .def("getAt", &PyDbSymbolTable::getAt, DS.ARGS({ "val: str" }, 9072))
        .def("add", &PyDbSymbolTable::add, DS.ARGS({ "val: PyDb.SymbolTableRecord" }, 9071))
        .def("has", &PyDbSymbolTable::has1)
        .def("has", &PyDbSymbolTable::has2, DS.ARGS({ "val: str|PyDb.ObjectId" }, 9074))
        .def("asDict", &PyDbSymbolTable::toDict, DS.ARGS())
        .def("toDict", &PyDbSymbolTable::toDict, DS.ARGS())
        .def("recordIds", &PyDbSymbolTable::recordIds, DS.ARGS())
        .def("desc", &PyDbSymbolTable::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cast", &PyDbSymbolTable::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        .def("className", &PyDbSymbolTable::className, DS.SARGS()).staticmethod("className")
        .def("cloneFrom", &PyDbSymbolTable::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("__iter__", +[](const PyDbSymbolTable& self) {return SymbolTable_Iterator(self); })
        .def("__getitem__", &PyDbSymbolTable::getAtEx, DS.ARGS({ "val: str" }))
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
    : PyDbObject(openAcDbObject<AcDbSymbolTable>(id), true)
{
}

PyDbSymbolTable::PyDbSymbolTable(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbObject(openAcDbObject<AcDbSymbolTable>(id, mode), true)
{
}

PyDbSymbolTable::PyDbSymbolTable(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbObject(openAcDbObject<AcDbSymbolTable>(id, mode, erased), true)
{
}

PyDbObjectId PyDbSymbolTable::getAt(const std::string& entryName) const
{
    AcDbObjectId id;
    PyThrowBadEs(impObj()->getAt(utf8_to_wstr(entryName).c_str(), id));
    return PyDbObjectId(id);
}

PyDbObjectId PyDbSymbolTable::getAtEx(const std::string& entryName) const
{
    AcDbObjectId id;
    const auto es = impObj()->getAt(utf8_to_wstr(entryName).c_str(), id);
    if (es == Acad::eKeyNotFound)
        throw PyRxEKeyError(entryName);
    PyThrowBadEs(es);
    return PyDbObjectId(id);
}

bool PyDbSymbolTable::has1(const std::string& entryName) const
{
    return impObj()->has(utf8_to_wstr(entryName).c_str());
}

bool PyDbSymbolTable::has2(const PyDbObjectId& entryid) const
{
    return impObj()->has(entryid.m_id);
}

PyDbObjectId PyDbSymbolTable::add(const PyDbSymbolTableRecord& pRecord) const
{
    PyDbObjectId id;
    if (!impObj()->isWriteEnabled())
        PyThrowBadEs(eNotOpenForWrite);
    PyThrowBadEs(impObj()->add(id.m_id, pRecord.impObj()));
    return id;
}

boost::python::list PyDbSymbolTable::recordIds() const
{
    auto [es, iter] = makeAcDbSymbolTableIterator(*impObj());
    PyThrowBadEs(es);
    PyAutoLockGIL lock;
    boost::python::list _items;
    for (iter->start(); !iter->done(); iter->step())
    {
        PyDbObjectId id;
        if (iter->getRecordId(id.m_id) == eOk)
            _items.append(id);
    }
    return _items;
}

boost::python::dict PyDbSymbolTable::toDict() const
{
    auto [es, iter] = makeAcDbSymbolTableIterator(*impObj());
    PyThrowBadEs(es);
    PyAutoLockGIL lock;
    boost::python::dict _items;
    for (iter->start(); !iter->done(); iter->step())
    {
        AcString name;
        PyDbObjectId id;
        if (iter->getRecordId(id.m_id) == eOk)
        {
            AcDbSymbolTableRecordPointer<AcDbSymbolTableRecord> record(id.m_id, AcDb::kForRead);
            if (record.openStatus() == eOk)
            {
                if (record->getName(name) == eOk)
                    _items[wstr_to_utf8(name)] = id;
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

//---------------------------------------------------------------------------------------- -
//AcDbDimStyleTable
void makePyDbDimStyleTableWrapper()
{
    PyDocString DS("DimStyleTable");
    class_<PyDbDimStyleTable, bases<PyDbSymbolTable>>("DimStyleTable", boost::python::no_init)
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: PyDb.ObjectId", "mode: PyDb.OpenMode = PyDb.OpenMode.kForRead", "erased: bool=False" })))
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

PyDbDimStyleTable::PyDbDimStyleTable(const PyDbObjectId& id)
    : PyDbSymbolTable(openAcDbObject<AcDbDimStyleTable>(id), false)
{
}

PyDbDimStyleTable::PyDbDimStyleTable(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbSymbolTable(openAcDbObject<AcDbDimStyleTable>(id, mode), false)
{
}

PyDbDimStyleTable::PyDbDimStyleTable(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbSymbolTable(openAcDbObject<AcDbDimStyleTable>(id, mode, erased), false)
{
}

PyDbObjectId PyDbDimStyleTable::add(const PyDbDimStyleTableRecord& entry) const
{
    PyDbObjectId id;
    if (!impObj()->isWriteEnabled())
        PyThrowBadEs(eNotOpenForWrite);
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
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: PyDb.ObjectId", "mode: PyDb.OpenMode = PyDb.OpenMode.kForRead", "erased: bool=False" })))
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

PyDbBlockTable::PyDbBlockTable(const PyDbObjectId& id)
    : PyDbSymbolTable(openAcDbObject<AcDbBlockTable>(id), false)
{
}

PyDbBlockTable::PyDbBlockTable(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbSymbolTable(openAcDbObject<AcDbBlockTable>(id, mode), false)
{
}

PyDbBlockTable::PyDbBlockTable(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbSymbolTable(openAcDbObject<AcDbBlockTable>(id, mode, erased), false)
{
}

PyDbObjectId PyDbBlockTable::add(const PyDbBlockTableRecord& entry) const
{
    PyDbObjectId id;
    if (!impObj()->isWriteEnabled())
        PyThrowBadEs(eNotOpenForWrite);
    PyThrowBadEs(impObj()->add(id.m_id, entry.impObj()));
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
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: PyDb.ObjectId", "mode: PyDb.OpenMode = PyDb.OpenMode.kForRead", "erased: bool=False" })))
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
    : PyDbSymbolTable(openAcDbObject<AcDbTextStyleTable>(id), false)
{
}

PyDbTextStyleTable::PyDbTextStyleTable(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbSymbolTable(openAcDbObject<AcDbTextStyleTable>(id, mode), false)
{
}

PyDbTextStyleTable::PyDbTextStyleTable(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbSymbolTable(openAcDbObject<AcDbTextStyleTable>(id, mode, erased), false)
{
}

PyDbObjectId PyDbTextStyleTable::add(const PyDbTextStyleTableRecord& entry) const
{
    PyDbObjectId id;
    if (!impObj()->isWriteEnabled())
        PyThrowBadEs(eNotOpenForWrite);
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
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: PyDb.ObjectId", "mode: PyDb.OpenMode = PyDb.OpenMode.kForRead", "erased: bool=False" })))
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
    : PyDbSymbolTable(openAcDbObject<AcDbLinetypeTable>(id), false)
{
}

PyDbLinetypeTable::PyDbLinetypeTable(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbSymbolTable(openAcDbObject<AcDbLinetypeTable>(id, mode), false)
{
}

PyDbLinetypeTable::PyDbLinetypeTable(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbSymbolTable(openAcDbObject<AcDbLinetypeTable>(id, mode, erased), false)
{
}

PyDbObjectId PyDbLinetypeTable::add(const PyDbLinetypeTableRecord& entry) const
{
    PyDbObjectId id;
    if (!impObj()->isWriteEnabled())
        PyThrowBadEs(eNotOpenForWrite);
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
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: PyDb.ObjectId", "mode: PyDb.OpenMode = PyDb.OpenMode.kForRead", "erased: bool=False" })))
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
    : PyDbSymbolTable(openAcDbObject<AcDbRegAppTable>(id), false)
{
}

PyDbRegAppTable::PyDbRegAppTable(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbSymbolTable(openAcDbObject<AcDbRegAppTable>(id, mode), false)
{
}

PyDbRegAppTable::PyDbRegAppTable(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbSymbolTable(openAcDbObject<AcDbRegAppTable>(id, mode, erased), false)
{
}

PyDbObjectId PyDbRegAppTable::add(const PyDbRegAppTableRecord& entry) const
{
    PyDbObjectId id;
    if (!impObj()->isWriteEnabled())
        PyThrowBadEs(eNotOpenForWrite);
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
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: PyDb.ObjectId", "mode: PyDb.OpenMode = PyDb.OpenMode.kForRead", "erased: bool=False" })))
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
    : PyDbSymbolTable(openAcDbObject<AcDbUCSTable>(id), false)
{
}

PyDbUCSTable::PyDbUCSTable(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbSymbolTable(openAcDbObject<AcDbUCSTable>(id, mode), false)
{
}

PyDbUCSTable::PyDbUCSTable(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbSymbolTable(openAcDbObject<AcDbUCSTable>(id, mode, erased), false)
{
}

PyDbObjectId PyDbUCSTable::add(const PyDbUCSTableRecord& entry) const
{
    PyDbObjectId id;
    if (!impObj()->isWriteEnabled())
        PyThrowBadEs(eNotOpenForWrite);
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
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: PyDb.ObjectId", "mode: PyDb.OpenMode = PyDb.OpenMode.kForRead", "erased: bool=False" })))
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
    : PyDbSymbolTable(openAcDbObject<AcDbLayerTable>(id), false)
{
}

PyDbLayerTable::PyDbLayerTable(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbSymbolTable(openAcDbObject<AcDbLayerTable>(id, mode), false)
{
}

PyDbLayerTable::PyDbLayerTable(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbSymbolTable(openAcDbObject<AcDbLayerTable>(id, mode, erased), false)
{
}

PyDbObjectId PyDbLayerTable::add(const PyDbLayerTableRecord& entry) const
{
    PyDbObjectId id;
    if (!impObj()->isWriteEnabled())
        PyThrowBadEs(eNotOpenForWrite);
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
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: PyDb.ObjectId", "mode: PyDb.OpenMode = PyDb.OpenMode.kForRead", "erased: bool=False" })))
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
    : PyDbSymbolTable(openAcDbObject<AcDbAbstractViewTable>(id), false)
{
}

PyDbAbstractViewTable::PyDbAbstractViewTable(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbSymbolTable(openAcDbObject<AcDbAbstractViewTable>(id, mode), false)
{
}

PyDbAbstractViewTable::PyDbAbstractViewTable(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbSymbolTable(openAcDbObject<AcDbAbstractViewTable>(id, mode, erased), false)
{
}

PyDbObjectId PyDbAbstractViewTable::add(const PyDbAbstractViewTableRecord& entry)
{
    if (!impObj()->isWriteEnabled())
        PyThrowBadEs(eNotOpenForWrite);
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
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: PyDb.ObjectId", "mode: PyDb.OpenMode = PyDb.OpenMode.kForRead", "erased: bool=False" })))
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
    : PyDbViewportTable(openAcDbObject<AcDbViewportTable>(id), false)
{
}

PyDbViewportTable::PyDbViewportTable(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbViewportTable(openAcDbObject<AcDbViewportTable>(id, mode), false)
{
}

PyDbViewportTable::PyDbViewportTable(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbViewportTable(openAcDbObject<AcDbViewportTable>(id, mode, erased), false)
{
}

PyDbViewportTable::PyDbViewportTable(AcDbViewportTable* ptr, bool autoDelete)
    : PyDbAbstractViewTable(ptr, autoDelete)
{
}

PyDbObjectId PyDbViewportTable::add(const PyDbViewportTableRecord& entry)
{
    if (!impObj()->isWriteEnabled())
        PyThrowBadEs(eNotOpenForWrite);
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
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: PyDb.ObjectId", "mode: PyDb.OpenMode = PyDb.OpenMode.kForRead", "erased: bool=False" })))
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

PyDbViewTable::PyDbViewTable(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbViewTable(openAcDbObject<AcDbViewTable>(id, mode, erased), false)
{
}

PyDbViewTable::PyDbViewTable(AcDbViewTable* ptr, bool autoDelete)
    : PyDbAbstractViewTable(ptr, autoDelete)
{
}

PyDbObjectId PyDbViewTable::add(const PyDbViewTableRecord& entry)
{
    if (!impObj()->isWriteEnabled())
        PyThrowBadEs(eNotOpenForWrite);
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
