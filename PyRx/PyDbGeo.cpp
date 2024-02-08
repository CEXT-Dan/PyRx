#include "stdafx.h"
#include "PyDbGeo.h"
#include "PyDbObjectId.h"
#include "PyDbMText.h"

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
        .def("position", &PyDbGeoPositionMarker::position, DS.ARGS())
        .def("setPosition", &PyDbGeoPositionMarker::setPosition, DS.ARGS({ "pt : PyGe.Point3d" }))
        .def("radius", &PyDbGeoPositionMarker::radius, DS.ARGS())
        .def("setRadius", &PyDbGeoPositionMarker::setRadius, DS.ARGS({ "val : float" }))
        .def("text", &PyDbGeoPositionMarker::text, DS.ARGS())
        .def("setText", &PyDbGeoPositionMarker::setText, DS.ARGS({ "val : str" }))
        .def("mtext", &PyDbGeoPositionMarker::mtext, DS.ARGS())
        .def("setMText", &PyDbGeoPositionMarker::setMText, DS.ARGS({ "val : PyDb.MText.M" }))
        .def("mtextVisible", &PyDbGeoPositionMarker::mtextVisible, DS.ARGS())
        .def("setMTextVisible", &PyDbGeoPositionMarker::setMTextVisible, DS.ARGS({ "val : bool" }))
        .def("landingGap", &PyDbGeoPositionMarker::landingGap, DS.ARGS())
        .def("setLandingGap", &PyDbGeoPositionMarker::setLandingGap, DS.ARGS({ "val : float" }))
        .def("enableFrameText", &PyDbGeoPositionMarker::enableFrameText, DS.ARGS())
        .def("setEnableFrameText", &PyDbGeoPositionMarker::setEnableFrameText, DS.ARGS({ "val : bool" }))
        .def("textAlignmentType", &PyDbGeoPositionMarker::textAlignmentType, DS.ARGS())
        .def("setTextAlignmentType", &PyDbGeoPositionMarker::setTextAlignmentType, DS.ARGS({ "val : PyDb.GeoTextAlignmentType" }))
        .def("notes", &PyDbGeoPositionMarker::notes, DS.ARGS())
        .def("setNotes", &PyDbGeoPositionMarker::setNotes, DS.ARGS({ "val : str" }))
        .def("geoPosition", &PyDbGeoPositionMarker::geoPosition, DS.ARGS())
        .def("setGeoPosition", &PyDbGeoPositionMarker::setGeoPosition, DS.ARGS({ "pt : PyGe.Point3d" }))
        .def("latLonAlt", &PyDbGeoPositionMarker::latLonAlt, DS.ARGS())
        .def("setLatLonAlt", &PyDbGeoPositionMarker::setLatLonAlt, DS.ARGS({ "lat : float","lon : float", "alt : float" }))
        .def("normal", &PyDbGeoPositionMarker::normal, DS.ARGS())
        .def("textStyle", &PyDbGeoPositionMarker::textStyle, DS.ARGS())
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

AcGePoint3d PyDbGeoPositionMarker::position() const
{
    return impObj()->position();
}

void PyDbGeoPositionMarker::setPosition(const AcGePoint3d& position)
{
    PyThrowBadEs(impObj()->setPosition(position));
}

double PyDbGeoPositionMarker::radius() const
{
    return impObj()->radius();
}

void PyDbGeoPositionMarker::setRadius(double radius)
{
    PyThrowBadEs(impObj()->setRadius(radius));
}

std::string PyDbGeoPositionMarker::text() const
{
    return wstr_to_utf8(impObj()->text());
}

void PyDbGeoPositionMarker::setText(const std::string& text)
{
    PyThrowBadEs(impObj()->setText(utf8_to_wstr(text).c_str()));
}

PyDbMText PyDbGeoPositionMarker::mtext() const
{
    return PyDbMText(impObj()->mtext(),true);
}

void PyDbGeoPositionMarker::setMText(const PyDbMText& pMText)
{
    PyThrowBadEs(impObj()->setMText(pMText.impObj()));
}

bool PyDbGeoPositionMarker::mtextVisible() const
{
    return impObj()->mtextVisible();
}

void PyDbGeoPositionMarker::setMTextVisible(bool visible)
{
    PyThrowBadEs(impObj()->setMTextVisible(visible));
}

double PyDbGeoPositionMarker::landingGap() const
{
    return impObj()->landingGap();
}

void PyDbGeoPositionMarker::setLandingGap(double landingGap)
{
    PyThrowBadEs(impObj()->setLandingGap(landingGap));
}

bool PyDbGeoPositionMarker::enableFrameText() const
{
    return impObj()->enableFrameText();
}

void PyDbGeoPositionMarker::setEnableFrameText(bool enableFrameText)
{
    PyThrowBadEs(impObj()->setEnableFrameText(enableFrameText));
}

AcDbGeoPositionMarker::TextAlignmentType PyDbGeoPositionMarker::textAlignmentType() const
{
    return impObj()->textAlignmentType();
}

void PyDbGeoPositionMarker::setTextAlignmentType(AcDbGeoPositionMarker::TextAlignmentType textAlignmentType)
{
    PyThrowBadEs(impObj()->setTextAlignmentType(textAlignmentType));
}

std::string PyDbGeoPositionMarker::notes() const
{
    return wstr_to_utf8(impObj()->notes());
}

void PyDbGeoPositionMarker::setNotes(const std::string& notes)
{
    PyThrowBadEs(impObj()->setNotes(utf8_to_wstr(notes).c_str()));
}

AcGePoint3d PyDbGeoPositionMarker::geoPosition() const
{
    return impObj()->geoPosition();
}

void PyDbGeoPositionMarker::setGeoPosition(const AcGePoint3d& position)
{
    PyThrowBadEs(impObj()->setGeoPosition(position));
}

boost::python::tuple PyDbGeoPositionMarker::latLonAlt() const
{
    double lat = 0; 
    double lon = 0; 
    double alt = 0;
    PyAutoLockGIL lock;
    PyThrowBadEs(impObj()->latLonAlt(lat, lon, alt));
    return boost::python::make_tuple(lat, lon, alt);
}

void PyDbGeoPositionMarker::setLatLonAlt(double lat, double lon, double alt)
{
    PyThrowBadEs(impObj()->setLatLonAlt(lat, lon, alt));
}

AcGeVector3d PyDbGeoPositionMarker::normal() const
{
    return impObj()->normal();
}

PyDbObjectId PyDbGeoPositionMarker::textStyle() const
{
    return PyDbObjectId(impObj()->textStyle());
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
