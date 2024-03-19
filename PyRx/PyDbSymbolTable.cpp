#include "stdafx.h"
#include "PyDbSymbolTable.h"
#include "PyDbObjectId.h"
#include "PyDbSymbolTableRecord.h"


using namespace boost::python;

//---------------------------------------------------------------------------------------- -
//PyDbSymbolTable wrapper
void makePyDbSymbolTableWrapper()
{
    class_<PyDbSymbolTable, bases<PyDbObject>>("SymbolTable", boost::python::no_init)
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("getAt", &PyDbSymbolTable::getAt)
        .def("add", &PyDbSymbolTable::add)
        .def("has", &PyDbSymbolTable::has1)
        .def("has", &PyDbSymbolTable::has2)
        .def("toDict", &PyDbSymbolTable::toDict)
        .def("recordIds", &PyDbSymbolTable::recordIds)
        .def("desc", &PyDbSymbolTable::desc).staticmethod("desc")
        .def("cast", &PyDbSymbolTable::cast).staticmethod("cast")
        .def("className", &PyDbSymbolTable::className).staticmethod("className")
        .def("cloneFrom", &PyDbSymbolTable::cloneFrom).staticmethod("cloneFrom")
        .def("__getitem__", &PyDbSymbolTable::getAt)
        .def("__contains__", &PyDbSymbolTable::has1)
        .def("__contains__", &PyDbSymbolTable::has2)
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
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
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
        .def(init<const PyDbObjectId&, AcDb::OpenMode>(DS.ARGS({ "id: ObjectId", "mode: PyDb.OpenMode.kForRead" })))
        .def("add", &PyDbBlockTable::add, DS.ARGS({ "block : BlockTableRecord" }))
        .def("className", &PyDbBlockTable::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbBlockTable::desc, DS.SARGS()).staticmethod("desc")
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
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<AcDbBlockTable*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
//PyDbTextStyleTable
void makePyDbTextStyleTableWrapper()
{
    class_<PyDbTextStyleTable, bases<PyDbSymbolTable>>("TextStyleTable", boost::python::no_init)
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
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<AcDbTextStyleTable*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
//PyDbLinetypeTable
void makePyDbLinetypeTableWrapper()
{
    class_<PyDbLinetypeTable, bases<PyDbSymbolTable>>("LinetypeTable", boost::python::no_init)
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("add", &PyDbLinetypeTable::add)
        .def("desc", &PyDbLinetypeTable::desc).staticmethod("desc")
        .def("cast", &PyDbLinetypeTable::cast).staticmethod("cast")
        .def("cloneFrom", &PyDbLinetypeTable::cloneFrom).staticmethod("cloneFrom")
        .def("className", &PyDbLinetypeTable::className).staticmethod("className")
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
    if (!src.impObj()->isKindOf(AcDbLinetypeTable::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbLinetypeTable(static_cast<AcDbLinetypeTable*>(src.impObj()->clone()), true);
}

PyDbLinetypeTable PyDbLinetypeTable::cast(const PyRxObject& src)
{
    PyDbLinetypeTable dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
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
    class_<PyDbRegAppTable, bases<PyDbSymbolTable>>("RegAppTable", boost::python::no_init)
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("add", &PyDbRegAppTable::add)
        .def("desc", &PyDbRegAppTable::desc).staticmethod("desc")
        .def("cast", &PyDbRegAppTable::cast).staticmethod("cast")
        .def("cloneFrom", &PyDbRegAppTable::cloneFrom).staticmethod("cloneFrom")
        .def("className", &PyDbRegAppTable::className).staticmethod("className")
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
    if (!src.impObj()->isKindOf(AcDbRegAppTable::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbRegAppTable(static_cast<AcDbRegAppTable*>(src.impObj()->clone()), true);
}

PyDbRegAppTable PyDbRegAppTable::cast(const PyRxObject& src)
{
    PyDbRegAppTable dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
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
    class_<PyDbUCSTable, bases<PyDbSymbolTable>>("UCSTable", boost::python::no_init)
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("add", &PyDbUCSTable::add)
        .def("desc", &PyDbUCSTable::desc).staticmethod("desc")
        .def("cast", &PyDbUCSTable::cast).staticmethod("cast")
        .def("cloneFrom", &PyDbUCSTable::cloneFrom).staticmethod("cloneFrom")
        .def("className", &PyDbUCSTable::className).staticmethod("className")
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
    if (!src.impObj()->isKindOf(AcDbUCSTable::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbUCSTable(static_cast<AcDbUCSTable*>(src.impObj()->clone()), true);
}

PyDbUCSTable PyDbUCSTable::cast(const PyRxObject& src)
{
    PyDbUCSTable dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
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
    class_<PyDbLayerTable, bases<PyDbSymbolTable>>("LayerTable", boost::python::no_init)
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("add", &PyDbLayerTable::add)
        .def("desc", &PyDbLayerTable::desc).staticmethod("desc")
        .def("cast", &PyDbLayerTable::cast).staticmethod("cast")
        .def("cloneFrom", &PyDbLayerTable::cloneFrom).staticmethod("cloneFrom")
        .def("className", &PyDbLayerTable::className).staticmethod("className")
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
    if (!src.impObj()->isKindOf(AcDbLayerTable::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbLayerTable(static_cast<AcDbLayerTable*>(src.impObj()->clone()), true);
}

PyDbLayerTable PyDbLayerTable::cast(const PyRxObject& src)
{
    PyDbLayerTable dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
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
    class_<PyDbAbstractViewTable, bases<PyDbSymbolTable>>("AbstractViewTable", boost::python::no_init)
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("add", &PyDbAbstractViewTable::add)
        .def("desc", &PyDbAbstractViewTable::desc).staticmethod("desc")
        .def("cast", &PyDbAbstractViewTable::cast).staticmethod("cast")
        .def("cloneFrom", &PyDbAbstractViewTable::cloneFrom).staticmethod("cloneFrom")
        .def("className", &PyDbAbstractViewTable::className).staticmethod("className")
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
    if (!src.impObj()->isKindOf(AcDbAbstractViewTable::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbAbstractViewTable(static_cast<AcDbAbstractViewTable*>(src.impObj()->clone()), true);
}

PyDbAbstractViewTable PyDbAbstractViewTable::cast(const PyRxObject& src)
{
    PyDbAbstractViewTable dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
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
    class_<PyDbViewportTable, bases<PyDbAbstractViewTable>>("ViewportTable")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("add", &PyDbAbstractViewTable::add)
        .def("desc", &PyDbAbstractViewTable::desc).staticmethod("desc")
        .def("cast", &PyDbAbstractViewTable::cast).staticmethod("cast")
        .def("cloneFrom", &PyDbAbstractViewTable::cloneFrom).staticmethod("cloneFrom")
        .def("className", &PyDbAbstractViewTable::className).staticmethod("className")
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
    if (!src.impObj()->isKindOf(AcDbViewportTable::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbViewportTable(static_cast<AcDbViewportTable*>(src.impObj()->clone()), true);
}

PyDbViewportTable PyDbViewportTable::cast(const PyRxObject& src)
{
    PyDbViewportTable dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
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
    class_<PyDbViewTable, bases<PyDbAbstractViewTable>>("ViewTable")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("add", &PyDbAbstractViewTable::add)
        .def("desc", &PyDbAbstractViewTable::desc).staticmethod("desc")
        .def("cast", &PyDbAbstractViewTable::cast).staticmethod("cast")
        .def("cloneFrom", &PyDbAbstractViewTable::cloneFrom).staticmethod("cloneFrom")
        .def("className", &PyDbAbstractViewTable::className).staticmethod("className")
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
    if (!src.impObj()->isKindOf(AcDbViewTable::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbViewTable(static_cast<AcDbViewTable*>(src.impObj()->clone()), true);
}

PyDbViewTable PyDbViewTable::cast(const PyRxObject& src)
{
    PyDbViewTable dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbViewTable* PyDbViewTable::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<AcDbViewTable*>(m_pyImp.get());
}
