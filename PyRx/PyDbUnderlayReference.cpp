#include "stdafx.h"
#include "PyDbUnderlayReference.h"
#include "PyDbObjectId.h"

using namespace boost::python;

void makePyDbUnderlayReferenceWrapper()
{
    class_<PyDbUnderlayReference, bases<PyDbEntity>>("UnderlayReference", boost::python::no_init)
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("className", &PyDbUnderlayReference::className).staticmethod("className")
        .def("desc", &PyDbUnderlayReference::desc).staticmethod("desc")
        .def("cloneFrom", &PyDbUnderlayReference::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbUnderlayReference::cast).staticmethod("cast")
        ;
}

PyDbUnderlayReference::PyDbUnderlayReference(AcDbUnderlayReference* ptr, bool autoDelete)
    : PyDbEntity(ptr, autoDelete)
{
}

PyDbUnderlayReference::PyDbUnderlayReference(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbEntity(nullptr, false)
{
    AcDbUnderlayReference* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbUnderlayReference>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
}

std::string PyDbUnderlayReference::className()
{
    return "AcDbUnderlayReference";
}

PyRxClass PyDbUnderlayReference::desc()
{
    return PyRxClass(AcDbUnderlayReference::desc(), false);
}

PyDbUnderlayReference PyDbUnderlayReference::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbUnderlayReference::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbUnderlayReference(static_cast<AcDbUnderlayReference*>(src.impObj()->clone()), true);
}

PyDbUnderlayReference PyDbUnderlayReference::cast(const PyRxObject& src)
{
    PyDbUnderlayReference dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbUnderlayReference* PyDbUnderlayReference::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbUnderlayReference*>(m_pyImp.get());
}


//-----------------------------------------------------------------------------------
//PyDbUnderlayDefinition
void makePyDbUnderlayDefinitionWrapper()
{
    class_<PyDbUnderlayDefinition, bases<PyDbObject>>("UnderlayDefinition", boost::python::no_init)
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("className", &PyDbUnderlayDefinition::className).staticmethod("className")
        .def("desc", &PyDbUnderlayDefinition::desc).staticmethod("desc")
        .def("cloneFrom", &PyDbUnderlayDefinition::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbUnderlayDefinition::cast).staticmethod("cast")
        ;
}

PyDbUnderlayDefinition::PyDbUnderlayDefinition(AcDbUnderlayDefinition* ptr, bool autoDelete)
    : PyDbObject(ptr, autoDelete)
{
}

PyDbUnderlayDefinition::PyDbUnderlayDefinition(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbObject(nullptr, false)
{
    AcDbUnderlayDefinition* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbUnderlayDefinition>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
}

std::string PyDbUnderlayDefinition::className()
{
    return "AcDbUnderlayDefinition";
}

PyRxClass PyDbUnderlayDefinition::desc()
{
    return PyRxClass(AcDbUnderlayDefinition::desc(), false);
}

PyDbUnderlayDefinition PyDbUnderlayDefinition::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbUnderlayDefinition::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbUnderlayDefinition(static_cast<AcDbUnderlayDefinition*>(src.impObj()->clone()), true);
}

PyDbUnderlayDefinition PyDbUnderlayDefinition::cast(const PyRxObject& src)
{
    PyDbUnderlayDefinition dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbUnderlayDefinition* PyDbUnderlayDefinition::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbUnderlayDefinition*>(m_pyImp.get());
}
