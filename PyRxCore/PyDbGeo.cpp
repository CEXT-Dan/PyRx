#include "stdafx.h"
#include "PyDbGeo.h"
#include "PyDbObjectId.h"
#include "PyDbMText.h"

using namespace boost::python;

//----------------------------------------------------------------------------------------
//PyDbGeoData
void makePyDbGeoDataWrapper()
{

    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    PyDocString DS("GeoData");
    class_<PyDbGeoData, bases<PyDbObject>>("GeoData")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.CTOR(ctords, 4797)))
        .def("blockTableRecordId", &PyDbGeoData::blockTableRecordId, DS.ARGS(4805))
        .def("setBlockTableRecordId", &PyDbGeoData::setBlockTableRecordId, DS.ARGS({ "id : PyDb.ObjectId" }, 4837))
        .def("postToDb", &PyDbGeoData::postToDb, DS.ARGS(4831))
        .def("eraseFromDb", &PyDbGeoData::eraseFromDb, DS.ARGS(4815))
        .def("coordinateType", &PyDbGeoData::coordinateType, DS.ARGS(4808))
        .def("setCoordinateType", &PyDbGeoData::setCoordinateType, DS.ARGS({ "val : PyDb.GeoTypeOfCoordinates" }, 4840))
        .def("designPoint", &PyDbGeoData::designPoint, DS.ARGS(4809))
        .def("setDesignPoint", &PyDbGeoData::setDesignPoint, DS.ARGS({ "pt : PyGe.Point3d" }, 4841))
        .def("referencePoint", &PyDbGeoData::referencePoint, DS.ARGS(4832))
        .def("setReferencePoint", &PyDbGeoData::setReferencePoint, DS.ARGS({ "pt : PyGe.Point3d" }, 4851))
        .def("horizontalUnitScale", &PyDbGeoData::horizontalUnitScale, DS.ARGS(4823))
        .def("horizontalUnits", &PyDbGeoData::horizontalUnits, DS.ARGS(4823))
        .def("setHorizontalUnitScale", &PyDbGeoData::setHorizontalUnitScale, DS.ARGS({ "val : float" }, 4845))
        .def("setHorizontalUnits", &PyDbGeoData::setHorizontalUnits, DS.ARGS({ "val : PyDb.UnitsValue" }, 4845))
        .def("verticalUnitScale", &PyDbGeoData::verticalUnitScale, DS.ARGS(4866))
        .def("verticalUnits", &PyDbGeoData::verticalUnits, DS.ARGS(4865))
        .def("setVerticalUnitScale", &PyDbGeoData::setVerticalUnitScale, DS.ARGS({ "val : float" }, 4866))
        .def("setVerticalUnits", &PyDbGeoData::setVerticalUnits, DS.ARGS({ "val : PyDb.UnitsValue" }, 4858))
        .def("coordinateSystem", &PyDbGeoData::coordinateSystem, DS.ARGS(4807))
        .def("setCoordinateSystem", &PyDbGeoData::setCoordinateSystem, DS.ARGS({ "val : str" }, 4839))
        .def("upDirection", &PyDbGeoData::upDirection, DS.ARGS(4864))
        .def("setUpDirection", &PyDbGeoData::setUpDirection, DS.ARGS({ "vec : PyGe.Vector3d" }, 4856))
        .def("northDirection", &PyDbGeoData::northDirection, DS.ARGS(4824))
        .def("northDirectionVector", &PyDbGeoData::northDirectionVector, DS.ARGS(4825))
        .def("setNorthDirectionVector", &PyDbGeoData::setNorthDirectionVector, DS.ARGS({ "vec : PyGe.Vector2d" }, 4847))
        .def("scaleEstimationMethod", &PyDbGeoData::scaleEstimationMethod, DS.ARGS(4834))
        .def("setScaleEstimationMethod", &PyDbGeoData::setScaleEstimationMethod, DS.ARGS({ "val : PyDb.GeoScaleEstimationMethod" }, 4852))
        .def("scaleFactor", &PyDbGeoData::scaleFactor, DS.ARGS(4835))
        .def("setScaleFactor", &PyDbGeoData::setScaleFactor, DS.ARGS({ "val : float" }, 4853))
        .def("doSeaLevelCorrection", &PyDbGeoData::doSeaLevelCorrection, DS.ARGS(4810))
        .def("setDoSeaLevelCorrection", &PyDbGeoData::setDoSeaLevelCorrection, DS.ARGS({ "val : bool" }, 4842))
        .def("seaLevelElevation", &PyDbGeoData::seaLevelElevation, DS.ARGS(4836))
        .def("setSeaLevelElevation", &PyDbGeoData::setSeaLevelElevation, DS.ARGS({ "val : float" }, 4854))
        .def("coordinateProjectionRadius", &PyDbGeoData::coordinateProjectionRadius, DS.ARGS(4806))
        .def("setCoordinateProjectionRadius", &PyDbGeoData::setCoordinateProjectionRadius, DS.ARGS({ "val : float" }, 4838))
        .def("geoRSSTag", &PyDbGeoData::geoRSSTag, DS.ARGS(4816))
        .def("setGeoRSSTag", &PyDbGeoData::setGeoRSSTag, DS.ARGS({ "val : str" }, 4843))
        .def("observationFrom", &PyDbGeoData::observationFrom, DS.ARGS(4829))
        .def("setObservationFrom", &PyDbGeoData::setObservationFrom, DS.ARGS({ "val : str" }, 4849))
        .def("observationTo", &PyDbGeoData::observationTo, DS.ARGS(4830))
        .def("setObservationTo", &PyDbGeoData::setObservationTo, DS.ARGS({ "val : str" }, 4850))
        .def("observationCoverage", &PyDbGeoData::observationCoverage, DS.ARGS(4828))
        .def("setObservationCoverage", &PyDbGeoData::setObservationCoverage, DS.ARGS({ "val : str" }, 4848))
        .def("numMeshPoints", &PyDbGeoData::numMeshPoints, DS.ARGS(4827))
        .def("getMeshPointMap", &PyDbGeoData::getMeshPointMap, DS.ARGS({ "idx : int" }, 4818))
        .def("getMeshPointMaps", &PyDbGeoData::getMeshPointMaps, DS.ARGS(4819))
        .def("addMeshPointMap", &PyDbGeoData::addMeshPointMap, DS.ARGS({ "idx : int","src : PyGe.Point2d","dest : PyGe.Point2d" }, 4804))
        .def("setMeshPointMaps", &PyDbGeoData::setMeshPointMaps, DS.ARGS({ "src : list[PyGe.Point2d]", "dest : list[PyGe.Point2d]" }, 4846))
        .def("resetMeshPointMaps", &PyDbGeoData::resetMeshPointMaps, DS.ARGS(4833))
        .def("numMeshFaces", &PyDbGeoData::numMeshFaces, DS.ARGS(4826))
        .def("getMeshFace", &PyDbGeoData::getMeshFace, DS.ARGS({ "idx : int" }, 4817))
        .def("addMeshFace", &PyDbGeoData::addMeshFace, DS.ARGS({ "idx : int","p0 : int","p1 : int","p2 : int" }, 4803))
        .def("updateTransformationMatrix", &PyDbGeoData::updateTransformationMatrix, DS.ARGS(4863))
        .def("transformToLonLatAlt", &PyDbGeoData::transformToLonLatAlt1)
        .def("transformToLonLatAlt", &PyDbGeoData::transformToLonLatAlt2, DS.ARGS({ "pt : PyGe.Point3d | float" }, 4861))
        .def("transformFromLonLatAlt", &PyDbGeoData::transformFromLonLatAlt1)
        .def("transformFromLonLatAlt", &PyDbGeoData::transformFromLonLatAlt2, DS.ARGS({ "pt : PyGe.Point3d | float" }, 4860))
        .def("className", &PyDbGeoData::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbGeoData::desc, DS.SARGS(15560)).staticmethod("desc")
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
    : PyDbObject(openAcDbObject<AcDbGeoData>(id, mode, erased), false)
{
}

PyDbObjectId PyDbGeoData::blockTableRecordId() const
{
    return PyDbObjectId(impObj()->blockTableRecordId());
}

void PyDbGeoData::setBlockTableRecordId(const PyDbObjectId& Id) const
{
    PyThrowBadEs(impObj()->setBlockTableRecordId(Id.m_id));
}

PyDbObjectId PyDbGeoData::postToDb() const
{
    PyDbObjectId id;
    PyThrowBadEs(impObj()->postToDb(id.m_id));
    return id;
}

void PyDbGeoData::eraseFromDb() const
{
    PyThrowBadEs(impObj()->eraseFromDb());
}

AcDbGeoData::TypeOfCoordinates PyDbGeoData::coordinateType() const
{
    return impObj()->coordinateType();
}

void PyDbGeoData::setCoordinateType(AcDbGeoData::TypeOfCoordinates designCoordinateType) const
{
    PyThrowBadEs(impObj()->setCoordinateType(designCoordinateType));
}

AcGePoint3d PyDbGeoData::designPoint() const
{
    return impObj()->designPoint();
}

void PyDbGeoData::setDesignPoint(const AcGePoint3d& point) const
{
    PyThrowBadEs(impObj()->setDesignPoint(point));
}

AcGePoint3d PyDbGeoData::referencePoint() const
{
    return impObj()->referencePoint();
}

void PyDbGeoData::setReferencePoint(const AcGePoint3d& point) const
{
    PyThrowBadEs(impObj()->setReferencePoint(point));
}

double PyDbGeoData::horizontalUnitScale() const
{
    return impObj()->horizontalUnitScale();
}

AcDb::UnitsValue PyDbGeoData::horizontalUnits() const
{
    return impObj()->horizontalUnits();
}

void PyDbGeoData::setHorizontalUnitScale(double horzUnitScale) const
{
    PyThrowBadEs(impObj()->setHorizontalUnitScale(horzUnitScale));
}

void PyDbGeoData::setHorizontalUnits(AcDb::UnitsValue horizUnits) const
{
    PyThrowBadEs(impObj()->setHorizontalUnits(horizUnits));
}

double PyDbGeoData::verticalUnitScale() const
{
    return impObj()->verticalUnitScale();
}

AcDb::UnitsValue PyDbGeoData::verticalUnits() const
{
    return impObj()->verticalUnits();
}

void PyDbGeoData::setVerticalUnitScale(double vertUnitScale) const
{
    PyThrowBadEs(impObj()->setVerticalUnitScale(vertUnitScale));
}

void PyDbGeoData::setVerticalUnits(AcDb::UnitsValue vertUnits) const
{
    PyThrowBadEs(impObj()->setVerticalUnits(vertUnits));
}

std::string PyDbGeoData::coordinateSystem() const
{
    return wstr_to_utf8(impObj()->coordinateSystem());
}

void PyDbGeoData::setCoordinateSystem(const std::string& coordinateSystem) const
{
    PyThrowBadEs(impObj()->setCoordinateSystem(utf8_to_wstr(coordinateSystem).c_str()));
}

AcGeVector3d PyDbGeoData::upDirection() const
{
    return impObj()->upDirection();
}

void PyDbGeoData::setUpDirection(const AcGeVector3d& vec) const
{
    PyThrowBadEs(impObj()->setUpDirection(vec));
}

double PyDbGeoData::northDirection() const
{
    return impObj()->northDirection();
}

AcGeVector2d PyDbGeoData::northDirectionVector() const
{
    return impObj()->northDirectionVector();
}

void PyDbGeoData::setNorthDirectionVector(const AcGeVector2d& north) const
{
    PyThrowBadEs(impObj()->setNorthDirectionVector(north));
}

AcDbGeoData::ScaleEstimationMethod PyDbGeoData::scaleEstimationMethod() const
{
    return impObj()->scaleEstimationMethod();
}

void PyDbGeoData::setScaleEstimationMethod(AcDbGeoData::ScaleEstimationMethod value) const
{
    PyThrowBadEs(impObj()->setScaleEstimationMethod(value));
}

double PyDbGeoData::scaleFactor() const
{
    return impObj()->scaleFactor();
}

void PyDbGeoData::setScaleFactor(double value) const
{
    PyThrowBadEs(impObj()->setScaleFactor(value));
}

bool PyDbGeoData::doSeaLevelCorrection() const
{
    return impObj()->doSeaLevelCorrection();
}

void PyDbGeoData::setDoSeaLevelCorrection(bool seaLevelCorrectionOn) const
{
    PyThrowBadEs(impObj()->setDoSeaLevelCorrection(seaLevelCorrectionOn));
}

double PyDbGeoData::seaLevelElevation() const
{
    return impObj()->seaLevelElevation();
}

void PyDbGeoData::setSeaLevelElevation(double value) const
{
    PyThrowBadEs(impObj()->setSeaLevelElevation(value));
}

double PyDbGeoData::coordinateProjectionRadius() const
{
    return impObj()->coordinateProjectionRadius();
}

void PyDbGeoData::setCoordinateProjectionRadius(double value) const
{
    PyThrowBadEs(impObj()->setCoordinateProjectionRadius(value));
}

std::string PyDbGeoData::geoRSSTag() const
{
    return wstr_to_utf8(impObj()->geoRSSTag());
}

void PyDbGeoData::setGeoRSSTag(const std::string& rssTag) const
{
    PyThrowBadEs(impObj()->setGeoRSSTag(utf8_to_wstr(rssTag).c_str()));
}

std::string PyDbGeoData::observationFrom() const
{
    return wstr_to_utf8(impObj()->observationFrom());
}

void PyDbGeoData::setObservationFrom(const std::string& from) const
{
    PyThrowBadEs(impObj()->setObservationFrom(utf8_to_wstr(from).c_str()));
}

std::string PyDbGeoData::observationTo() const
{
    return wstr_to_utf8(impObj()->observationTo());
}

void PyDbGeoData::setObservationTo(const std::string& to) const
{
    PyThrowBadEs(impObj()->setObservationTo(utf8_to_wstr(to).c_str()));
}

std::string PyDbGeoData::observationCoverage() const
{
    return wstr_to_utf8(impObj()->observationCoverage());
}

void PyDbGeoData::setObservationCoverage(const std::string& coverage) const
{
    PyThrowBadEs(impObj()->setObservationCoverage(utf8_to_wstr(coverage).c_str()));
}

int PyDbGeoData::numMeshPoints() const
{
    return impObj()->numMeshPoints();
}

boost::python::tuple PyDbGeoData::getMeshPointMap(int index) const
{
    PyAutoLockGIL lock;
    AcGePoint2d sourcePt;
    AcGePoint2d destPt;
    PyThrowBadEs(impObj()->getMeshPointMap(index, sourcePt, destPt));
    return boost::python::make_tuple(sourcePt, destPt);
}

boost::python::tuple PyDbGeoData::getMeshPointMaps() const
{
    PyAutoLockGIL lock;
    AcGePoint2dArray sourcePts;
    AcGePoint2dArray destPts;
    PyThrowBadEs(impObj()->getMeshPointMaps(sourcePts, destPts));
    return boost::python::make_tuple(Point2dArrayToPyList(sourcePts), Point2dArrayToPyList(destPts));
}

void PyDbGeoData::addMeshPointMap(int index, const AcGePoint2d& sourcePt, const AcGePoint2d& destPt) const
{
    PyThrowBadEs(impObj()->addMeshPointMap(index, sourcePt, destPt));
}

void PyDbGeoData::setMeshPointMaps(const boost::python::object& sourcePts, const boost::python::object& destPts) const
{
    PyAutoLockGIL lock;
    PyThrowBadEs(impObj()->setMeshPointMaps(PyListToPoint2dArray(sourcePts), PyListToPoint2dArray(destPts)));
}

void PyDbGeoData::resetMeshPointMaps() const
{
    PyThrowBadEs(impObj()->resetMeshPointMaps());
}

int PyDbGeoData::numMeshFaces() const
{
    return impObj()->numMeshFaces();
}

boost::python::tuple PyDbGeoData::getMeshFace(int faceIndex) const
{
    PyAutoLockGIL lock;
    int p0 = 0;
    int p1 = 0;
    int p2 = 0;
    PyThrowBadEs(impObj()->getMeshFace(faceIndex, p0, p1, p2));
    return boost::python::make_tuple(p0, p1, p2);
}

void PyDbGeoData::addMeshFace(int faceIndex, int p0, int p1, int p2) const
{
    PyThrowBadEs(impObj()->addMeshFace(faceIndex, p0, p1, p2));
}

void PyDbGeoData::updateTransformationMatrix() const
{
    PyThrowBadEs(impObj()->updateTransformationMatrix());
}

AcGePoint3d PyDbGeoData::transformToLonLatAlt1(const AcGePoint3d& dwgPt) const
{
    AcGePoint3d geoPt;
    PyThrowBadEs(impObj()->transformToLonLatAlt(dwgPt, geoPt));
    return geoPt;
}

boost::python::tuple PyDbGeoData::transformToLonLatAlt2(double x, double y, double z) const
{
    PyAutoLockGIL lock;
    double lon = 0;
    double lat = 0;
    double alt = 0;
    PyThrowBadEs(impObj()->transformToLonLatAlt(x, y, z, lon, lat, alt));
    return boost::python::make_tuple(lon, lat, alt);
}

AcGePoint3d PyDbGeoData::transformFromLonLatAlt1(const AcGePoint3d& geoPt) const
{
    AcGePoint3d dwgPt;
    PyThrowBadEs(impObj()->transformFromLonLatAlt(geoPt, dwgPt));
    return dwgPt;
}

boost::python::tuple PyDbGeoData::transformFromLonLatAlt2(double lon, double lat, double alt) const
{
    PyAutoLockGIL lock;
    double x = 0;
    double y = 0;
    double z = 0;
    PyThrowBadEs(impObj()->transformFromLonLatAlt(lon, lat, alt, x, y, z));
    return boost::python::make_tuple(x, y, z);
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
    return PyDbObjectCloneFrom<PyDbGeoData, AcDbGeoData>(src);
}

PyDbGeoData PyDbGeoData::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbGeoData>(src);
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
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- position: PyGe.Point3d, radius: float, landingGap: float\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    PyDocString DS("GeoPositionMarker");
    class_<PyDbGeoPositionMarker, bases<PyDbEntity>>("GeoPositionMarker")
        .def(init<>())
        .def(init<const AcGePoint3d&, double, double>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.CTOR(ctords)))
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
        .def("desc", &PyDbGeoPositionMarker::desc, DS.SARGS(15560)).staticmethod("desc")
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

void PyDbGeoPositionMarker::setPosition(const AcGePoint3d& position) const
{
    PyThrowBadEs(impObj()->setPosition(position));
}

double PyDbGeoPositionMarker::radius() const
{
    return impObj()->radius();
}

void PyDbGeoPositionMarker::setRadius(double radius) const
{
    PyThrowBadEs(impObj()->setRadius(radius));
}

std::string PyDbGeoPositionMarker::text() const
{
    return wstr_to_utf8(impObj()->text());
}

void PyDbGeoPositionMarker::setText(const std::string& text) const
{
    PyThrowBadEs(impObj()->setText(utf8_to_wstr(text).c_str()));
}

PyDbMText PyDbGeoPositionMarker::mtext() const
{
    return PyDbMText(impObj()->mtext(), true);
}

void PyDbGeoPositionMarker::setMText(const PyDbMText& pMText) const
{
    PyThrowBadEs(impObj()->setMText(pMText.impObj()));
}

bool PyDbGeoPositionMarker::mtextVisible() const
{
    return impObj()->mtextVisible();
}

void PyDbGeoPositionMarker::setMTextVisible(bool visible) const
{
    PyThrowBadEs(impObj()->setMTextVisible(visible));
}

double PyDbGeoPositionMarker::landingGap() const
{
    return impObj()->landingGap();
}

void PyDbGeoPositionMarker::setLandingGap(double landingGap) const
{
    PyThrowBadEs(impObj()->setLandingGap(landingGap));
}

bool PyDbGeoPositionMarker::enableFrameText() const
{
    return impObj()->enableFrameText();
}

void PyDbGeoPositionMarker::setEnableFrameText(bool enableFrameText) const
{
    PyThrowBadEs(impObj()->setEnableFrameText(enableFrameText));
}

AcDbGeoPositionMarker::TextAlignmentType PyDbGeoPositionMarker::textAlignmentType() const
{
    return impObj()->textAlignmentType();
}

void PyDbGeoPositionMarker::setTextAlignmentType(AcDbGeoPositionMarker::TextAlignmentType textAlignmentType) const
{
    PyThrowBadEs(impObj()->setTextAlignmentType(textAlignmentType));
}

std::string PyDbGeoPositionMarker::notes() const
{
    return wstr_to_utf8(impObj()->notes());
}

void PyDbGeoPositionMarker::setNotes(const std::string& notes) const
{
    PyThrowBadEs(impObj()->setNotes(utf8_to_wstr(notes).c_str()));
}

AcGePoint3d PyDbGeoPositionMarker::geoPosition() const
{
    return impObj()->geoPosition();
}

void PyDbGeoPositionMarker::setGeoPosition(const AcGePoint3d& position) const
{
    PyThrowBadEs(impObj()->setGeoPosition(position));
}

boost::python::tuple PyDbGeoPositionMarker::latLonAlt() const
{
    PyAutoLockGIL lock;
    double lat = 0;
    double lon = 0;
    double alt = 0;
    PyThrowBadEs(impObj()->latLonAlt(lat, lon, alt));
    return boost::python::make_tuple(lat, lon, alt);
}

void PyDbGeoPositionMarker::setLatLonAlt(double lat, double lon, double alt) const
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
    return PyDbObjectCloneFrom<PyDbGeoPositionMarker, AcDbGeoPositionMarker>(src);
}

PyDbGeoPositionMarker PyDbGeoPositionMarker::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbGeoPositionMarker>(src);
}

AcDbGeoPositionMarker* PyDbGeoPositionMarker::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbGeoPositionMarker*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyDbGeoCoordinateSystem
void makePyDbGeoCoordinateSystemWrapper()
{
    PyDocString DS("GeoCoordinateSystem");
    class_<PyDbGeoCoordinateSystem>("GeoCoordinateSystem", no_init)
        .def("getId", &PyDbGeoCoordinateSystem::getId, DS.ARGS())
        .def("getEpsgCode", &PyDbGeoCoordinateSystem::getEpsgCode, DS.ARGS())
        .def("getType", &PyDbGeoCoordinateSystem::getType, DS.ARGS())
        .def("getDescription", &PyDbGeoCoordinateSystem::getDescription, DS.ARGS())
        .def("getUnit", &PyDbGeoCoordinateSystem::getUnit, DS.ARGS())
        .def("getGeoUnit", &PyDbGeoCoordinateSystem::getGeoUnit, DS.ARGS())
        .def("getUnitScale", &PyDbGeoCoordinateSystem::getUnitScale, DS.ARGS())
        .def("getProjectionCode", &PyDbGeoCoordinateSystem::getProjectionCode, DS.ARGS())
        .def("getDatum", &PyDbGeoCoordinateSystem::getDatum, DS.ARGS())
        .def("getEllipsoid", &PyDbGeoCoordinateSystem::getEllipsoid, DS.ARGS())
        .def("getOffset", &PyDbGeoCoordinateSystem::getOffset, DS.ARGS())
        .def("getCartesianExtents", &PyDbGeoCoordinateSystem::getCartesianExtents, DS.ARGS())
        .def("getGeodeticExtents", &PyDbGeoCoordinateSystem::getGeodeticExtents, DS.ARGS())
        .def("getXmlRepresentation", &PyDbGeoCoordinateSystem::getXmlRepresentation, DS.ARGS())
        .def("getWktRepresentation", &PyDbGeoCoordinateSystem::getWktRepresentation, DS.ARGS())
        .def("create", &PyDbGeoCoordinateSystem::create, DS.SARGS({ "val : str" })).staticmethod("create")
        .def("className", &PyDbGeoCoordinateSystem::className, DS.SARGS()).staticmethod("className")
        ;
}


PyDbGeoCoordinateSystem::PyDbGeoCoordinateSystem(AcDbGeoCoordinateSystem* ptr)
    :m_pyImp(ptr)
{
}

std::string PyDbGeoCoordinateSystem::getId() const
{
    AcString coordSysId;
    PyThrowBadEs(impObj()->getId(coordSysId));
    return wstr_to_utf8(coordSysId);
}

int PyDbGeoCoordinateSystem::getEpsgCode() const
{
    int epsgCode = 0;
    PyThrowBadEs(impObj()->getEpsgCode(epsgCode));
    return epsgCode;
}

AcDbGeoCoordinateSystem::Type PyDbGeoCoordinateSystem::getType() const
{
    AcDbGeoCoordinateSystem::Type _type;
    PyThrowBadEs(impObj()->getType(_type));
    return _type;
}

std::string PyDbGeoCoordinateSystem::getDescription() const
{
    AcString coordSysDesc;
    PyThrowBadEs(impObj()->getDescription(coordSysDesc));
    return wstr_to_utf8(coordSysDesc);
}

AcDb::UnitsValue PyDbGeoCoordinateSystem::getUnit() const
{
    AcDb::UnitsValue unit;
    PyThrowBadEs(impObj()->getUnit(unit));
    return unit;
}

AcDbGeoCoordinateSystem::Unit PyDbGeoCoordinateSystem::getGeoUnit() const
{
    AcDbGeoCoordinateSystem::Unit unit;
    PyThrowBadEs(impObj()->getUnit(unit));
    return unit;
}

double PyDbGeoCoordinateSystem::getUnitScale() const
{
    double unitScale = 1;
    PyThrowBadEs(impObj()->getUnitScale(unitScale));
    return unitScale;
}

AcDbGeoCoordinateSystem::ProjectionCode PyDbGeoCoordinateSystem::getProjectionCode() const
{
    AcDbGeoCoordinateSystem::ProjectionCode code;
    PyThrowBadEs(impObj()->getProjectionCode(code));
    return code;
}

boost::python::tuple PyDbGeoCoordinateSystem::getDatum() const
{
    PyAutoLockGIL lock;
    AcDbGeoDatum datum;
    PyThrowBadEs(impObj()->getDatum(datum));
    return boost::python::make_tuple(wstr_to_utf8(datum.id), wstr_to_utf8(datum.desc));
}

boost::python::tuple PyDbGeoCoordinateSystem::getEllipsoid() const
{
    PyAutoLockGIL lock;
    AcDbGeoEllipsoid val;
    PyThrowBadEs(impObj()->getEllipsoid(val));
    return boost::python::make_tuple(wstr_to_utf8(val.id), wstr_to_utf8(val.desc), val.polarRadius, val.eccentricity);
}

AcGeVector2d PyDbGeoCoordinateSystem::getOffset() const
{
    AcGeVector2d val;
    PyThrowBadEs(impObj()->getOffset(val));
    return val;
}

AcDbExtents2d PyDbGeoCoordinateSystem::getCartesianExtents() const
{
    AcDbExtents2d val;
    PyThrowBadEs(impObj()->getCartesianExtents(val));
    return val;
}

AcDbExtents2d PyDbGeoCoordinateSystem::getGeodeticExtents() const
{
    AcDbExtents2d val;
    PyThrowBadEs(impObj()->getGeodeticExtents(val));
    return val;
}

std::string PyDbGeoCoordinateSystem::getXmlRepresentation() const
{
    AcString val;
    PyThrowBadEs(impObj()->getXmlRepresentation(val));
    return wstr_to_utf8(val);
}

std::string PyDbGeoCoordinateSystem::getWktRepresentation() const
{
    AcString val;
    PyThrowBadEs(impObj()->getWktRepresentation(val));
    return wstr_to_utf8(val);
}

PyDbGeoCoordinateSystem PyDbGeoCoordinateSystem::create(const std::string& coordSysIdOrFullDef)
{
    AcDbGeoCoordinateSystem* ptr = nullptr;
    PyThrowBadEs(AcDbGeoCoordinateSystem::create(utf8_to_wstr(coordSysIdOrFullDef).c_str(), ptr));
    return  PyDbGeoCoordinateSystem(ptr);
}

std::string PyDbGeoCoordinateSystem::className()
{
    return "AcDbGeoCoordinateSystem";
}

AcDbGeoCoordinateSystem* PyDbGeoCoordinateSystem::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbGeoCoordinateSystem*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyDbGeoCoordinateSystemTransformer
void makePyDbGeoCoordinateSystemTransformerWrapper()
{
    PyDocString DS("GeoCoordinateSystemTransformer");
    class_<PyDbGeoCoordinateSystemTransformer>("GeoCoordinateSystemTransformer", no_init)
        .def("getSourceCoordinateSystemId", &PyDbGeoCoordinateSystemTransformer::getSourceCoordinateSystemId, DS.ARGS())
        .def("getSourceCoordinateSystemId", &PyDbGeoCoordinateSystemTransformer::getTargetCoordinateSystemId, DS.ARGS())
        .def("transformPoint", &PyDbGeoCoordinateSystemTransformer::transformPoint, DS.ARGS({ "pt: PyGe.Point3d" }))
        .def("transformPoints", &PyDbGeoCoordinateSystemTransformer::transformPoints, DS.ARGS({ "pts: list[PyGe.Point3d]" }))
        .def("create", &PyDbGeoCoordinateSystemTransformer::create, DS.SARGS({ "sourceCoordSysId : str","targetCoordSysId : str" })).staticmethod("create")
        .def("className", &PyDbGeoCoordinateSystemTransformer::className, DS.SARGS()).staticmethod("className")
        ;
}

PyDbGeoCoordinateSystemTransformer::PyDbGeoCoordinateSystemTransformer(AcDbGeoCoordinateSystemTransformer* ptr)
    :m_pyImp(ptr)
{
}

std::string PyDbGeoCoordinateSystemTransformer::getSourceCoordinateSystemId() const
{
    AcString val;
    PyThrowBadEs(impObj()->getSourceCoordinateSystemId(val));
    return wstr_to_utf8(val);
}

std::string PyDbGeoCoordinateSystemTransformer::getTargetCoordinateSystemId() const
{
    AcString val;
    PyThrowBadEs(impObj()->getTargetCoordinateSystemId(val));
    return wstr_to_utf8(val);
}

AcGePoint3d PyDbGeoCoordinateSystemTransformer::transformPoint(const AcGePoint3d& pointIn) const
{
    AcGePoint3d val;
    PyThrowBadEs(impObj()->transformPoint(pointIn, val));
    return val;
}

boost::python::list PyDbGeoCoordinateSystemTransformer::transformPoints(const boost::python::list& pointsIn) const
{
    AcGePoint3dArray pointsOut;
    const auto& _pntsin = PyListToPoint3dArray(pointsIn);
    PyThrowBadEs(impObj()->transformPoints(_pntsin, pointsOut));
    return Point3dArrayToPyList(pointsOut);
}

PyDbGeoCoordinateSystemTransformer PyDbGeoCoordinateSystemTransformer::create(const std::string& sourceCoordSysId, const std::string& targetCoordSysId)
{
    AcDbGeoCoordinateSystemTransformer* ptr = nullptr;
    PyThrowBadEs(AcDbGeoCoordinateSystemTransformer::create(utf8_to_wstr(sourceCoordSysId).c_str(), utf8_to_wstr(targetCoordSysId).c_str(), ptr));
    return PyDbGeoCoordinateSystemTransformer{ ptr };
}

std::string PyDbGeoCoordinateSystemTransformer::className()
{
    return "AcDbGeoCoordinateSystemTransformer";
}

AcDbGeoCoordinateSystemTransformer* PyDbGeoCoordinateSystemTransformer::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbGeoCoordinateSystemTransformer*>(m_pyImp.get());
}
