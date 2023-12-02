#include "stdafx.h"
#include "PyDbPointCloudEx.h"
#include "PyDbObjectId.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------
//PyDbPointCloudDefEx
void makePyDbPointCloudDefExWrapper()
{
    PyDocString DS("PointCloudDefEx");
    class_<PyDbPointCloudDefEx, bases<PyDbObject>>("PointCloudDefEx", boost::python::no_init)
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: ObjectId", "mode: OpenMode=kForRead", "erased: bool=False" })))
        .def("className", &PyDbPointCloudDefEx::className).staticmethod("className")
        .def("desc", &PyDbPointCloudDefEx::desc).staticmethod("desc")
        .def("cloneFrom", &PyDbPointCloudDefEx::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbPointCloudDefEx::cast).staticmethod("cast")
        ;
}

PyDbPointCloudDefEx::PyDbPointCloudDefEx()
    : PyDbPointCloudDefEx(new AcDbPointCloudDefEx(), true)
{
}

PyDbPointCloudDefEx::PyDbPointCloudDefEx(const PyDbObjectId& id)
    : PyDbPointCloudDefEx(openAcDbObject<AcDbPointCloudDefEx>(id, AcDb::OpenMode::kForRead), false)
{
}

PyDbPointCloudDefEx::PyDbPointCloudDefEx(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbPointCloudDefEx(openAcDbObject<AcDbPointCloudDefEx>(id, mode), false)
{
}

PyDbPointCloudDefEx::PyDbPointCloudDefEx(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbPointCloudDefEx(openAcDbObject<AcDbPointCloudDefEx>(id, mode, erased), false)
{
}

PyDbPointCloudDefEx::PyDbPointCloudDefEx(AcDbPointCloudDefEx* ptr, bool autoDelete)
    : PyDbObject(ptr, autoDelete)
{
}

std::string PyDbPointCloudDefEx::className()
{
    return "AcDbPointCloudDefEx";
}

PyRxClass PyDbPointCloudDefEx::desc()
{
    return PyRxClass(AcDbPointCloudDefEx::desc(), false);
}

PyDbPointCloudDefEx PyDbPointCloudDefEx::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbPointCloudDefEx::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbPointCloudDefEx(static_cast<AcDbPointCloudDefEx*>(src.impObj()->clone()), true);
}

PyDbPointCloudDefEx PyDbPointCloudDefEx::cast(const PyRxObject& src)
{
    PyDbPointCloudDefEx dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbPointCloudDefEx* PyDbPointCloudDefEx::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<AcDbPointCloudDefEx*>(m_pyImp.get());
}


//-----------------------------------------------------------------------------------
//PyDbPointCloudEx
void makePyDbPointCloudExWrapper()
{
    PyDocString DS("PointCloudEx");
    class_<PyDbPointCloudEx, bases<PyDbEntity>>("PointCloudEx")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: ObjectId", "mode: OpenMode=kForRead", "erased: bool=False" })))
        .def("className", &PyDbPointCloudEx::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbPointCloudEx::desc, DS.SARGS()).staticmethod("desc")
        .def("cloneFrom", &PyDbPointCloudEx::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbPointCloudEx::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}


PyDbPointCloudEx::PyDbPointCloudEx()
    : PyDbPointCloudEx(new AcDbPointCloudEx(), true)
{
}

PyDbPointCloudEx::PyDbPointCloudEx(AcDbPointCloudEx* ptr, bool autoDelete)
    : PyDbEntity(ptr, autoDelete)
{
}

PyDbPointCloudEx::PyDbPointCloudEx(const PyDbObjectId& id)
    : PyDbPointCloudEx(openAcDbObject<AcDbPointCloudEx>(id, AcDb::kForRead), false)
{
}

PyDbPointCloudEx::PyDbPointCloudEx(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbPointCloudEx(openAcDbObject<AcDbPointCloudEx>(id, mode), false)
{
}

PyDbPointCloudEx::PyDbPointCloudEx(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbPointCloudEx(openAcDbObject<AcDbPointCloudEx>(id, mode, erased), false)
{
}

std::string PyDbPointCloudEx::className()
{
    return "AcDbPointCloudEx";
}

PyRxClass PyDbPointCloudEx::desc()
{
    return PyRxClass(AcDbPointCloudEx::desc(), false);
}

PyDbPointCloudEx PyDbPointCloudEx::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbPointCloudEx::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbPointCloudEx(static_cast<AcDbPointCloudEx*>(src.impObj()->clone()), true);
}

PyDbPointCloudEx PyDbPointCloudEx::cast(const PyRxObject& src)
{
    PyDbPointCloudEx dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbPointCloudEx* PyDbPointCloudEx::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<AcDbPointCloudEx*>(m_pyImp.get());
}
