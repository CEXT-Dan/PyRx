#include "stdafx.h"
#include "PyDbGroup.h"
#include "PyDbObjectId.h"

using namespace boost::python;

void makePyDbGroupWrapper()
{
    PyDocString DS("Group");
    class_<PyDbGroup, bases<PyDbObject>>("Group")
        .def(init<>())
        .def(init<const std::string&>())
        .def(init<const std::string&, bool>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        
        .def("desc", &PyDbGroup::desc, DS.SARGS()).staticmethod("desc")
        .def("className", &PyDbGroup::className, DS.SARGS()).staticmethod("className")
        .def("cloneFrom", &PyDbGroup::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbGroup::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyDbGroup::PyDbGroup()
    : PyDbGroup(new AcDbGroup(),true)
{
}

PyDbGroup::PyDbGroup(const std::string& grpDesc)
    : PyDbGroup(new AcDbGroup(utf8_to_wstr(grpDesc).c_str()), true)
{
}

PyDbGroup::PyDbGroup(const std::string& grpDesc, bool selectable)
    : PyDbGroup(new AcDbGroup(utf8_to_wstr(grpDesc).c_str(), selectable), true)
{
}

PyDbGroup::PyDbGroup(AcDbGroup* ptr, bool autoDelete)
    : PyDbObject(ptr, autoDelete)
{
}

PyDbGroup::PyDbGroup(const PyDbObjectId& id)
    : PyDbGroup(id, AcDb::OpenMode::kForRead)
{
}

PyDbGroup::PyDbGroup(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbGroup(openAcDbObject<AcDbGroup>(id, mode), false)
{
}

PyRxClass PyDbGroup::desc()
{
    return PyRxClass(AcDbGroup::desc(), false);
}

std::string PyDbGroup::className()
{
    return "AcDbGroup";
}

PyDbGroup PyDbGroup::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbGroup::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbGroup(static_cast<AcDbGroup*>(src.impObj()->clone()), true);
}

PyDbGroup PyDbGroup::cast(const PyRxObject& src)
{
    PyDbGroup dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbGroup* PyDbGroup::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]]
        throw PyNullObject(src);
        return static_cast<AcDbGroup*>(m_pyImp.get());
}
