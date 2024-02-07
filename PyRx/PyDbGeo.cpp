#include "stdafx.h"
#include "PyDbGeo.h"
#include "PyDbObjectId.h"

using namespace boost::python;

//----------------------------------------------------------------------------------------
//PyDbGeoData
void makePyDbGeoDataWrapper()
{
    PyDocString DS("GeoData");
    class_<PyDbGeoData, bases<PyDbObject>>("GeoData")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: ObjectId", "mode: OpenMode=kForRead", "erased: bool=False" })))
        .def("className", &PyDbGeoData::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbGeoData::desc, DS.SARGS()).staticmethod("desc")
        .def("cloneFrom", &PyDbGeoData::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbGeoData::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyDbGeoData::PyDbGeoData()
    : PyDbObject(new AcDbGeoData(), true)
{
}

PyDbGeoData::PyDbGeoData(AcDbGeoData* ptr, bool autoDelete)
    : PyDbObject(ptr, autoDelete)
{
}

PyDbGeoData::PyDbGeoData(const PyDbObjectId& id)
    : PyDbObject(openAcDbObject<AcDbGeoData>(id, AcDb::OpenMode::kForRead), false)
{
}

PyDbGeoData::PyDbGeoData(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbObject(openAcDbObject<AcDbGeoData>(id, mode), false)
{
}

PyDbGeoData::PyDbGeoData(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbObject(openAcDbObject<AcDbGeoData>(id, mode, erased),false)
{
}

PyRxClass PyDbGeoData::desc()
{
    return PyRxClass(AcDbGeoData::desc(), false);
}

std::string PyDbGeoData::className()
{
    return "AcDbGeoData";
}

PyDbGeoData PyDbGeoData::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbGeoData::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbGeoData(static_cast<AcDbGeoData*>(src.impObj()->clone()), true);
}

PyDbGeoData PyDbGeoData::cast(const PyRxObject& src)
{
    PyDbGeoData dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbGeoData* PyDbGeoData::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<AcDbGeoData*>(m_pyImp.get());
}


//----------------------------------------------------------------------------------------
//PyDbGeoPositionMarker
void makePyDbGeoPositionMarkerWrapper()
{
    PyDocString DS("GeoPositionMarker");
    class_<PyDbGeoPositionMarker, bases<PyDbEntity>>("GeoPositionMarker")
        .def(init<>())
        .def(init<const AcGePoint3d&, double, double>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: ObjectId", "mode: OpenMode=kForRead", "erased: bool=False" })))
        .def("className", &PyDbGeoPositionMarker::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbGeoPositionMarker::desc, DS.SARGS()).staticmethod("desc")
        .def("cloneFrom", &PyDbGeoPositionMarker::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbGeoPositionMarker::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyDbGeoPositionMarker::PyDbGeoPositionMarker()
    : PyDbEntity(new AcDbGeoPositionMarker(), true)
{
}

PyDbGeoPositionMarker::PyDbGeoPositionMarker(const AcGePoint3d& position, double radius, double landingGap)
    : PyDbEntity(new AcDbGeoPositionMarker(position, radius, landingGap), true)
{
}

PyDbGeoPositionMarker::PyDbGeoPositionMarker(const PyDbObjectId& id)
    : PyDbEntity(openAcDbObject<AcDbGeoPositionMarker>(id, AcDb::OpenMode::kForRead), false)
{
}

PyDbGeoPositionMarker::PyDbGeoPositionMarker(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbEntity(openAcDbObject<AcDbGeoPositionMarker>(id, mode), false)
{
}

PyDbGeoPositionMarker::PyDbGeoPositionMarker(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbEntity(openAcDbObject<AcDbGeoPositionMarker>(id, mode, erased), false)
{
}

PyDbGeoPositionMarker::PyDbGeoPositionMarker(AcDbGeoPositionMarker* ptr, bool autoDelete)
    : PyDbEntity(ptr, autoDelete)
{
}

PyRxClass PyDbGeoPositionMarker::desc()
{
    return PyRxClass(AcDbGeoPositionMarker::desc(), false);
}

std::string PyDbGeoPositionMarker::className()
{
    return "AcDbGeoPositionMarker";
}

PyDbGeoPositionMarker PyDbGeoPositionMarker::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbGeoPositionMarker::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbGeoPositionMarker(static_cast<AcDbGeoPositionMarker*>(src.impObj()->clone()), true);
}

PyDbGeoPositionMarker PyDbGeoPositionMarker::cast(const PyRxObject& src)
{
    PyDbGeoPositionMarker dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbGeoPositionMarker* PyDbGeoPositionMarker::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<AcDbGeoPositionMarker*>(m_pyImp.get());
}
