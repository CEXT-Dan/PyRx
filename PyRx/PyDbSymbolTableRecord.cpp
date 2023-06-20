#include "stdafx.h"
#include "PyDbSymbolTableRecord.h"
#include "PyDbObjectId.h"

using namespace boost::python;
//---------------------------------------------------------------------------------------- -
// PyDbSymbolTableRecord  wrapper
void makeAcDbSymbolTableRecordWrapper()
{
    class_<PyDbSymbolTableRecord, bases<PyDbObject>>("SymbolTableRecord", boost::python::no_init)
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("getName", &PyDbSymbolTableRecord::getName)
        .def("setName", &PyDbSymbolTableRecord::setName)
        .def("isDependent", &PyDbSymbolTableRecord::isDependent)
        .def("isResolved", &PyDbSymbolTableRecord::isResolved)
        .def("isRenamable", &PyDbSymbolTableRecord::isRenamable)
        .def("className", &PyDbSymbolTableRecord::className).staticmethod("className")
        .def("desc", &PyDbSymbolTableRecord::desc).staticmethod("desc")
        .def("cloneFrom", &PyDbSymbolTableRecord::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbSymbolTableRecord::cast).staticmethod("cast")
        ;
}

//---------------------------------------------------------------------------------------- -
// PyDbSymbolTableRecord 
PyDbSymbolTableRecord::PyDbSymbolTableRecord(AcDbSymbolTableRecord* ptr, bool autoDelete)
    : PyDbObject(ptr, autoDelete)
{
}

PyDbSymbolTableRecord::PyDbSymbolTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbObject(nullptr, false)
{
    AcDbSymbolTableRecord* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbSymbolTableRecord>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
}

std::string PyDbSymbolTableRecord::getName()
{
    AcString arxName;
    impObj()->getName(arxName);
    return wstr_to_utf8(arxName);
}

Acad::ErrorStatus PyDbSymbolTableRecord::setName(const std::string name)
{
    return impObj()->setName(utf8_to_wstr(name).c_str());
}

bool PyDbSymbolTableRecord::isDependent() const
{
    return impObj()->isDependent();
}

bool PyDbSymbolTableRecord::isResolved() const
{
    return impObj()->isResolved();
}

bool PyDbSymbolTableRecord::isRenamable() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->isRenamable();
#endif
}

std::string PyDbSymbolTableRecord::className()
{
    return "AcDbSymbolTableRecord";
}

PyRxClass PyDbSymbolTableRecord::desc()
{
    return PyRxClass(AcDbSymbolTableRecord::desc(), false);
}

PyDbSymbolTableRecord PyDbSymbolTableRecord::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbSymbolTableRecord::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbSymbolTableRecord(static_cast<AcDbSymbolTableRecord*>(src.impObj()->clone()), true);
}

PyDbSymbolTableRecord PyDbSymbolTableRecord::cast(const PyRxObject& src)
{
    PyDbSymbolTableRecord dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbSymbolTableRecord* PyDbSymbolTableRecord::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbSymbolTableRecord*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
// PyDbDimStyleTableRecord 
void makeAcDbDimStyleTableRecordWrapper()
{
    class_<PyDbDimStyleTableRecord, bases<PyDbSymbolTableRecord>>("DimStyleTableRecord")
        .def(init<>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("className", &PyDbDimStyleTableRecord::className).staticmethod("className")
        .def("desc", &PyDbDimStyleTableRecord::desc).staticmethod("desc")
        .def("cloneFrom", &PyDbDimStyleTableRecord::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbDimStyleTableRecord::cast).staticmethod("cast")
        ;
}

PyDbDimStyleTableRecord::PyDbDimStyleTableRecord()
    : PyDbSymbolTableRecord(new AcDbDimStyleTableRecord(), true)
{
}

PyDbDimStyleTableRecord::PyDbDimStyleTableRecord(AcDbDimStyleTableRecord* ptr, bool autoDelete)
    : PyDbSymbolTableRecord(ptr, autoDelete)
{
}

PyDbDimStyleTableRecord::PyDbDimStyleTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbSymbolTableRecord(nullptr, false)
{
    AcDbDimStyleTableRecord* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbDimStyleTableRecord>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
}

std::string PyDbDimStyleTableRecord::className()
{
    return "AcDbDimStyleTableRecord";
}

PyRxClass PyDbDimStyleTableRecord::desc()
{
    return PyRxClass(AcDbDimStyleTableRecord::desc(), false);
}

PyDbDimStyleTableRecord PyDbDimStyleTableRecord::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbDimStyleTableRecord::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbDimStyleTableRecord(static_cast<AcDbDimStyleTableRecord*>(src.impObj()->clone()), true);
}

PyDbDimStyleTableRecord PyDbDimStyleTableRecord::cast(const PyRxObject& src)
{
    PyDbDimStyleTableRecord dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbDimStyleTableRecord* PyDbDimStyleTableRecord::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbDimStyleTableRecord*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
// PyDbAbstractViewTableRecord
void makePyDbAbstractViewTableRecordWrapper()
{
    class_<PyDbAbstractViewTableRecord, bases<PyDbSymbolTableRecord>>("AbstractViewTableRecord", boost::python::no_init)
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("className", &PyDbAbstractViewTableRecord::className).staticmethod("className")
        .def("desc", &PyDbAbstractViewTableRecord::desc).staticmethod("desc")
        .def("cloneFrom", &PyDbAbstractViewTableRecord::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbAbstractViewTableRecord::cast).staticmethod("cast")
        ;
}
#ifdef NEVER
PyDbAbstractViewTableRecord::PyDbAbstractViewTableRecord()
    : PyDbSymbolTableRecord(new AcDbAbstractViewTableRecord(), true)
{
}
#endif

PyDbAbstractViewTableRecord::PyDbAbstractViewTableRecord(AcDbAbstractViewTableRecord* ptr, bool autoDelete)
    : PyDbSymbolTableRecord(ptr, autoDelete)
{
}

PyDbAbstractViewTableRecord::PyDbAbstractViewTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbSymbolTableRecord(nullptr, false)
{
    AcDbAbstractViewTableRecord* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbAbstractViewTableRecord>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
}

std::string PyDbAbstractViewTableRecord::className()
{
    return "AcDbAbstractViewTableRecord";
}

PyRxClass PyDbAbstractViewTableRecord::desc()
{
    return PyRxClass(AcDbAbstractViewTableRecord::desc(), false);
}

PyDbAbstractViewTableRecord PyDbAbstractViewTableRecord::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbAbstractViewTableRecord::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbAbstractViewTableRecord(static_cast<AcDbAbstractViewTableRecord*>(src.impObj()->clone()), true);
}

PyDbAbstractViewTableRecord PyDbAbstractViewTableRecord::cast(const PyRxObject& src)
{
    PyDbAbstractViewTableRecord dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbAbstractViewTableRecord* PyDbAbstractViewTableRecord::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbAbstractViewTableRecord*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
// PyDbViewportTableRecord
void makePyDbViewportTableRecordWrapper()
{
    class_<PyDbViewportTableRecord, bases<PyDbAbstractViewTableRecord>>("ViewportTableRecord")
        .def(init<>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("className", &PyDbViewportTableRecord::className).staticmethod("className")
        .def("desc", &PyDbViewportTableRecord::desc).staticmethod("desc")
        .def("cloneFrom", &PyDbViewportTableRecord::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbViewportTableRecord::cast).staticmethod("cast")
        ;
}

PyDbViewportTableRecord::PyDbViewportTableRecord()
    : PyDbAbstractViewTableRecord(new AcDbViewportTableRecord(), true)
{
}

PyDbViewportTableRecord::PyDbViewportTableRecord(AcDbViewportTableRecord* ptr, bool autoDelete)
    : PyDbAbstractViewTableRecord(ptr, autoDelete)
{
}

PyDbViewportTableRecord::PyDbViewportTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbAbstractViewTableRecord(nullptr, false)
{
    AcDbViewportTableRecord* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbViewportTableRecord>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
}

std::string PyDbViewportTableRecord::className()
{
    return "AcDbViewportTableRecord";
}

PyRxClass PyDbViewportTableRecord::desc()
{
    return PyRxClass(AcDbViewportTableRecord::desc(), false);
}

PyDbViewportTableRecord PyDbViewportTableRecord::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbViewportTableRecord::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbViewportTableRecord(static_cast<AcDbViewportTableRecord*>(src.impObj()->clone()), true);
}

PyDbViewportTableRecord PyDbViewportTableRecord::cast(const PyRxObject& src)
{
    PyDbViewportTableRecord dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbViewportTableRecord* PyDbViewportTableRecord::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbViewportTableRecord*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
// PyDbViewTableRecord
void makePyDbViewTableRecordWrapper()
{
    class_<PyDbViewTableRecord, bases<PyDbAbstractViewTableRecord>>("ViewTableRecord")
        .def(init<>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("getLayout", &PyDbViewTableRecord::getLayout)
        .def("setLayout", &PyDbViewTableRecord::setLayout)
        .def("className", &PyDbViewTableRecord::className).staticmethod("className")
        .def("desc", &PyDbViewTableRecord::desc).staticmethod("desc")
        .def("cloneFrom", &PyDbViewTableRecord::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbViewTableRecord::cast).staticmethod("cast")
        ;
}

PyDbViewTableRecord::PyDbViewTableRecord()
    : PyDbAbstractViewTableRecord(new AcDbViewTableRecord(), true)
{
}

PyDbViewTableRecord::PyDbViewTableRecord(AcDbViewTableRecord* ptr, bool autoDelete)
    : PyDbAbstractViewTableRecord(ptr, autoDelete)
{
}

PyDbViewTableRecord::PyDbViewTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbAbstractViewTableRecord(nullptr, false)
{
    AcDbViewTableRecord* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbViewTableRecord>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
}

PyDbObjectId PyDbViewTableRecord::getLayout() const
{
    PyDbObjectId id;
    if (auto es = impObj()->getLayout(id.m_id); es != eOk)
        throw PyAcadErrorStatus(es);
    return id;
}

Acad::ErrorStatus PyDbViewTableRecord::setLayout(const PyDbObjectId& layoutId)
{
    return impObj()->setLayout(layoutId.m_id);
}

std::string PyDbViewTableRecord::className()
{
    return "AcDbViewTableRecord";
}

PyRxClass PyDbViewTableRecord::desc()
{
    return PyRxClass(AcDbViewTableRecord::desc(), false);
}

PyDbViewTableRecord PyDbViewTableRecord::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbViewTableRecord::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbViewTableRecord(static_cast<AcDbViewTableRecord*>(src.impObj()->clone()), true);
}

PyDbViewTableRecord PyDbViewTableRecord::cast(const PyRxObject& src)
{
    PyDbViewTableRecord dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbViewTableRecord* PyDbViewTableRecord::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbViewTableRecord*>(m_pyImp.get());
}
