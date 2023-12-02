#include "stdafx.h"
#include "PyDbPointCloudEx.h"
#include "PyDbObjectId.h"
#include "PyDbDatabase.h"
#include "PyGePlane.h"
#include "AcPointCloud.h"

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
        .def("load", &PyDbPointCloudDefEx::load)
        .def("unload", &PyDbPointCloudDefEx::unload)
        .def("isLoaded", &PyDbPointCloudDefEx::isLoaded)
        .def("entityCount", &PyDbPointCloudDefEx::entityCount)
        .def("setSourceFileName", &PyDbPointCloudDefEx::setSourceFileName)
        .def("sourceFileName", &PyDbPointCloudDefEx::sourceFileName)
        .def("setActiveFileName", &PyDbPointCloudDefEx::setActiveFileName)
        .def("activeFileName", &PyDbPointCloudDefEx::activeFileName)
        .def("fileType", &PyDbPointCloudDefEx::fileType)
        .def("totalPointsCount", &PyDbPointCloudDefEx::totalPointsCount)
        .def("totalRegionsCount", &PyDbPointCloudDefEx::totalRegionsCount)
        .def("totalScansCount", &PyDbPointCloudDefEx::totalScansCount)
        .def("defaultWidth", &PyDbPointCloudDefEx::defaultWidth)
        .def("defaultLength", &PyDbPointCloudDefEx::defaultLength)
        .def("defaultHeight", &PyDbPointCloudDefEx::defaultHeight)
        .def("hasProperty", &PyDbPointCloudDefEx::hasProperty)
        .def("extents", &PyDbPointCloudDefEx::extents)
        .def("coordinateSystemName", &PyDbPointCloudDefEx::coordinateSystemName)
        .def("getRcsFilePath", &PyDbPointCloudDefEx::getRcsFilePath)
        .def("getAllRcsFilePaths", &PyDbPointCloudDefEx::getAllRcsFilePaths)
        .def("pointCloudExDictionary", &PyDbPointCloudDefEx::pointCloudExDictionary).staticmethod("pointCloudExDictionary")
        .def("createPointCloudExDictionary", &PyDbPointCloudDefEx::createPointCloudExDictionary).staticmethod("createPointCloudExDictionary")
        .def("classVersion", &PyDbPointCloudDefEx::classVersion).staticmethod("classVersion")
        .def("className", &PyDbPointCloudDefEx::className).staticmethod("className")
        .def("desc", &PyDbPointCloudDefEx::desc).staticmethod("desc")
        .def("cloneFrom", &PyDbPointCloudDefEx::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbPointCloudDefEx::cast).staticmethod("cast")
        ;

    enum_<AcDbPointCloudDefEx::PropState>("PointCloudPropertyState")
        .value("kNone", AcDbPointCloudDefEx::PropState::kNone)
        .value("kSome", AcDbPointCloudDefEx::PropState::kSome)
        .value("kAll", AcDbPointCloudDefEx::PropState::kAll)
        .export_values()
        ;

    enum_<AcDbPointCloudDefEx::Property>("PointCloudProperty")
        .value("kColor", AcDbPointCloudDefEx::Property::kColor)
        .value("kIntensity", AcDbPointCloudDefEx::Property::kIntensity)
        .value("kClassification", AcDbPointCloudDefEx::Property::kClassification)
        .value("kNormal", AcDbPointCloudDefEx::Property::kNormal)
        .value("kSegmentation", AcDbPointCloudDefEx::Property::kSegmentation)
        .value("kGeoGraphic", AcDbPointCloudDefEx::Property::kGeoGraphic)
        .export_values()
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

void PyDbPointCloudDefEx::load()
{
    PyThrowBadEs(impObj()->load());
}

void PyDbPointCloudDefEx::unload()
{
    PyThrowBadEs(impObj()->unload());
}

Adesk::Boolean PyDbPointCloudDefEx::isLoaded() const
{
    return impObj()->isLoaded();
}

boost::python::tuple PyDbPointCloudDefEx::entityCount() const
{
    PyAutoLockGIL lock;
    Adesk::Boolean pbLocked = false;
    auto val = impObj()->entityCount(&pbLocked);
    return boost::python::make_tuple(val, pbLocked);
}

void PyDbPointCloudDefEx::setSourceFileName(const std::string& pPathName)
{
    PyThrowBadEs(impObj()->setSourceFileName(utf8_to_wstr(pPathName).c_str()));
}

std::string PyDbPointCloudDefEx::sourceFileName() const
{
    return wstr_to_utf8(impObj()->sourceFileName());
}

void PyDbPointCloudDefEx::setActiveFileName(const std::string& pPathName)
{
    PyThrowBadEs(impObj()->setActiveFileName(utf8_to_wstr(pPathName).c_str()));
}

std::string PyDbPointCloudDefEx::activeFileName() const
{
    return wstr_to_utf8(impObj()->activeFileName());
}

std::string PyDbPointCloudDefEx::fileType() const
{
    return wstr_to_utf8(impObj()->fileType());
}

unsigned long long PyDbPointCloudDefEx::totalPointsCount() const
{
    return impObj()->totalPointsCount();
}

int PyDbPointCloudDefEx::totalRegionsCount() const
{
    return impObj()->totalRegionsCount();
}

int PyDbPointCloudDefEx::totalScansCount() const
{
    return impObj()->totalScansCount();
}

double PyDbPointCloudDefEx::defaultWidth() const
{
    return impObj()->defaultWidth();
}

double PyDbPointCloudDefEx::defaultLength() const
{
    return impObj()->defaultLength();
}

double PyDbPointCloudDefEx::defaultHeight() const
{
    return impObj()->defaultHeight();
}

AcDbPointCloudDefEx::PropState PyDbPointCloudDefEx::hasProperty(AcDbPointCloudDefEx::Property prop) const
{
    return impObj()->hasProperty(prop);
}

AcDbExtents PyDbPointCloudDefEx::extents() const
{
    return impObj()->extents();
}

std::string PyDbPointCloudDefEx::coordinateSystemName() const
{
    return wstr_to_utf8(impObj()->coordinateSystemName());
}

std::string PyDbPointCloudDefEx::getRcsFilePath(const std::string& guid) const
{
    return wstr_to_utf8(impObj()->getRcsFilePath(utf8_to_wstr(guid).c_str()));
}

boost::python::list PyDbPointCloudDefEx::getAllRcsFilePaths() const
{
    PyAutoLockGIL lock;
    AcStringArray strlist;
    impObj()->getAllRcsFilePaths(strlist);
    boost::python::list pylist;
    for (const auto& item : strlist)
        pylist(wstr_to_utf8(item));
    return pylist;
}

PyDbObjectId PyDbPointCloudDefEx::pointCloudExDictionary(PyDbDatabase& pDb)
{
    return AcDbPointCloudDefEx::pointCloudExDictionary(pDb.impObj());
}

void PyDbPointCloudDefEx::createPointCloudExDictionary(PyDbDatabase& pDb, PyDbObjectId& dictId)
{
    PyThrowBadEs(AcDbPointCloudDefEx::createPointCloudExDictionary(pDb.impObj(), dictId.m_id));
}

int PyDbPointCloudDefEx::classVersion()
{
    return AcDbPointCloudDefEx::classVersion();
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
        .def("setPointCloudDefExId", &PyDbPointCloudEx::setPointCloudDefExId)
        .def("pointCloudDefExId", &PyDbPointCloudEx::pointCloudDefExId)
        .def("setReactorId", &PyDbPointCloudEx::setReactorId)
        .def("reactorId", &PyDbPointCloudEx::reactorId)
        .def("locked", &PyDbPointCloudEx::locked)
        .def("setLocked", &PyDbPointCloudEx::setLocked)
        .def("scale", &PyDbPointCloudEx::scale)
        .def("setScale", &PyDbPointCloudEx::setScale)
        .def("rotation", &PyDbPointCloudEx::rotation)
        .def("setRotation", &PyDbPointCloudEx::setRotation)
        .def("location", &PyDbPointCloudEx::location)
        .def("setLocation", &PyDbPointCloudEx::setLocation)
        .def("getNativeCloudExtent", &PyDbPointCloudEx::getNativeCloudExtent)
        .def("getVisiblePointCount", &PyDbPointCloudEx::getVisiblePointCount)
        .def("getLoadedVisiblePointCount", &PyDbPointCloudEx::getLoadedVisiblePointCount)
        .def("getDisplayedVisiblePointCount", &PyDbPointCloudEx::getDisplayedVisiblePointCount)
        .def("setActiveFileName", &PyDbPointCloudEx::setActiveFileName)
        .def("getActiveFileName", &PyDbPointCloudEx::getActiveFileName)
        .def("getPointCloudName", &PyDbPointCloudEx::getPointCloudName)
        .def("setPointCloudName", &PyDbPointCloudEx::setPointCloudName)
        .def("getCroppingCount", &PyDbPointCloudEx::getCroppingCount)
        .def("clearCropping", &PyDbPointCloudEx::clearCropping)
        .def("removeLastCropping", &PyDbPointCloudEx::removeLastCropping)
        .def("getCroppingInvert", &PyDbPointCloudEx::getCroppingInvert)
        .def("setCroppingInvert", &PyDbPointCloudEx::setCroppingInvert)
        .def("setInCreatingCroppingMode", &PyDbPointCloudEx::setInCreatingCroppingMode)
        .def("showCropped", &PyDbPointCloudEx::showCropped)
        .def("setStylizationType", &PyDbPointCloudEx::setStylizationType)
        .def("stylizationType", &PyDbPointCloudEx::stylizationType)
        .def("getCurrentColorScheme", &PyDbPointCloudEx::getCurrentColorScheme)
        .def("setCurrentColorScheme", &PyDbPointCloudEx::setCurrentColorScheme)
        .def("getColorSchemeForStylization", &PyDbPointCloudEx::getColorSchemeForStylization)
        .def("setColorSchemeForStylization", &PyDbPointCloudEx::setColorSchemeForStylization)
        .def("showIntensityAsGradient", &PyDbPointCloudEx::showIntensityAsGradient)
        .def("setShowIntensityAsGradient", &PyDbPointCloudEx::setShowIntensityAsGradient)
        .def("minIntensity", &PyDbPointCloudEx::minIntensity)
        .def("maxIntensity", &PyDbPointCloudEx::maxIntensity)
        .def("setMinMaxIntensity", &PyDbPointCloudEx::setMinMaxIntensity)
        .def("intensityOutOfRangeBehavior", &PyDbPointCloudEx::intensityOutOfRangeBehavior)
        .def("setIntensityOutOfRangeBehavior", &PyDbPointCloudEx::setIntensityOutOfRangeBehavior)
        .def("showElevationAsGradient", &PyDbPointCloudEx::showElevationAsGradient)
        .def("setShowElevationAsGradient", &PyDbPointCloudEx::setShowElevationAsGradient)
        .def("minElevation", &PyDbPointCloudEx::minElevation)
        .def("maxElevation", &PyDbPointCloudEx::maxElevation)
        .def("setMinMaxElevation", &PyDbPointCloudEx::setMinMaxElevation)
        .def("elevationApplyToFixedRange", &PyDbPointCloudEx::elevationApplyToFixedRange)
        .def("setElevationApplyToFixedRange", &PyDbPointCloudEx::setElevationApplyToFixedRange)
        .def("elevationOutOfRangeBehavior", &PyDbPointCloudEx::elevationOutOfRangeBehavior)
        .def("setElevationOutOfRangeBehavior", &PyDbPointCloudEx::setElevationOutOfRangeBehavior)
        .def("resetLimitBox", &PyDbPointCloudEx::resetLimitBox)
        .def("setHighlightLimitboxBoundary", &PyDbPointCloudEx::setHighlightLimitboxBoundary)
        .def("setScanVisibility", &PyDbPointCloudEx::setScanVisibility)
        .def("setAllScansVisibility", &PyDbPointCloudEx::setAllScansVisibility)
        .def("setRegionVisibility", &PyDbPointCloudEx::setRegionVisibility)
        .def("setAllRegionsVisibility", &PyDbPointCloudEx::setAllRegionsVisibility1)
        .def("setAllRegionsVisibility", &PyDbPointCloudEx::setAllRegionsVisibility2)
        .def("setAllScansVisibilityByRegion", &PyDbPointCloudEx::setAllScansVisibilityByRegion)
        .def("getScanViewInfo", &PyDbPointCloudEx::getScanViewInfo)
        .def("resetScanRegionVisibility", &PyDbPointCloudEx::resetScanRegionVisibility)
        .def("setAllScanHighlight", &PyDbPointCloudEx::setAllScanHighlight)
        .def("setAllRegionHighlight", &PyDbPointCloudEx::setAllRegionHighlight1)
        .def("setAllRegionHighlight", &PyDbPointCloudEx::setAllRegionHighlight2)
        .def("applyGeoLocation", &PyDbPointCloudEx::applyGeoLocation1)
        .def("applyGeoLocation", &PyDbPointCloudEx::applyGeoLocation2)
        .def("updateGeoLocation", &PyDbPointCloudEx::updateGeoLocation)
        .def("geolocate", &PyDbPointCloudEx::geolocate)
        .def("clearSpatialFilters", &PyDbPointCloudEx::clearSpatialFilters)
        .def("clearAttributeFilters", &PyDbPointCloudEx::clearAttributeFilters)
        .def("getPlaneOrPointAt", &PyDbPointCloudEx::getPlaneOrPointAt)
        .def("getPlaneBoundaryAt", &PyDbPointCloudEx::getPlaneBoundaryAt)
        .def("objectToWorldMatrix", &PyDbPointCloudEx::objectToWorldMatrix)
        .def("getCandidatePlane", &PyDbPointCloudEx::getCandidatePlane)
        .def("getCylinderAt", &PyDbPointCloudEx::getCylinderAt)
        .def("getMinDistPrecision", &PyDbPointCloudEx::getMinDistPrecision)
        .def("detectPointBelonger", &PyDbPointCloudEx::detectPointBelonger)
        .def("getCustomOsnapInfo", &PyDbPointCloudEx::getCustomOsnapInfo)
        .def("attachPointCloud", &PyDbPointCloudEx::attachPointCloud, DS.SARGS()).staticmethod("attachPointCloud")
        .def("className", &PyDbPointCloudEx::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbPointCloudEx::desc, DS.SARGS()).staticmethod("desc")
        .def("cloneFrom", &PyDbPointCloudEx::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbPointCloudEx::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
    enum_<AcDbPointCloudEx::DispOptionOutOfRange>("PointCloudDispOptionOutOfRange")
        .value("kUseMinMaxColors", AcDbPointCloudEx::DispOptionOutOfRange::kUseMinMaxColors)
        .value("kUseRGBScanColors", AcDbPointCloudEx::DispOptionOutOfRange::kUseRGBScanColors)
        .value("kHidePoints", AcDbPointCloudEx::DispOptionOutOfRange::kHidePoints)
        .export_values()
        ;
    enum_<AcDbPointCloudEx::PointCloudOSnapMode>("PointCloudOSnapMode")
        .value("kOsModePNod", AcDbPointCloudEx::PointCloudOSnapMode::kOsModePNod)
        .value("kOsModePNea", AcDbPointCloudEx::PointCloudOSnapMode::kOsModePNea)
        .value("kOsModePPer", AcDbPointCloudEx::PointCloudOSnapMode::kOsModePPer)
        .value("kOsModePEdgeNea", AcDbPointCloudEx::PointCloudOSnapMode::kOsModePEdgeNea)
        .value("kOsModePEdgePer", AcDbPointCloudEx::PointCloudOSnapMode::kOsModePEdgePer)
        .value("kOsModePInt", AcDbPointCloudEx::PointCloudOSnapMode::kOsModePInt)
        .value("kOsModePCL", AcDbPointCloudEx::PointCloudOSnapMode::kOsModePCL)
        .value("kOsModePCorner", AcDbPointCloudEx::PointCloudOSnapMode::kOsModePCorner)
        .export_values()
        ;
    enum_<AcDbPointCloudEx::StylizationType>("PointCloudStylizationType")
        .value("kTrueColor", AcDbPointCloudEx::StylizationType::kTrueColor)
        .value("kSingleColor", AcDbPointCloudEx::StylizationType::kSingleColor)
        .value("kNormalRamp", AcDbPointCloudEx::StylizationType::kNormalRamp)
        .value("kHeightRamp", AcDbPointCloudEx::StylizationType::kHeightRamp)
        .value("kIntensityRamp", AcDbPointCloudEx::StylizationType::kIntensityRamp)
        .value("kClassificationRamp", AcDbPointCloudEx::StylizationType::kClassificationRamp)
        .export_values()
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

void PyDbPointCloudEx::setPointCloudDefExId(const PyDbObjectId& defExId)
{
    impObj()->setPointCloudDefExId(defExId.m_id);
}

PyDbObjectId PyDbPointCloudEx::pointCloudDefExId() const
{
    return PyDbObjectId(impObj()->pointCloudDefExId());
}

void PyDbPointCloudEx::setReactorId(const PyDbObjectId& reactorId)
{
    impObj()->setReactorId(reactorId.m_id);
}

PyDbObjectId PyDbPointCloudEx::reactorId() const
{
    return PyDbObjectId(impObj()->reactorId());
}

bool PyDbPointCloudEx::locked() const
{
    return impObj()->locked();
}

void PyDbPointCloudEx::setLocked(bool locked)
{
    return impObj()->setLocked(locked);
}

double PyDbPointCloudEx::scale() const
{
    return impObj()->scale();
}

void PyDbPointCloudEx::setScale(double val)
{
    PyThrowBadEs(impObj()->setScale(val));
}

double PyDbPointCloudEx::rotation() const
{
    return impObj()->rotation();
}

void PyDbPointCloudEx::setRotation(double val)
{
    PyThrowBadEs(impObj()->setRotation(val));
}

AcGePoint3d PyDbPointCloudEx::location() const
{
    return impObj()->location();
}

void PyDbPointCloudEx::setLocation(const AcGePoint3d& pt)
{
    PyThrowBadEs(impObj()->setLocation(pt));
}

AcDbExtents PyDbPointCloudEx::getNativeCloudExtent() const
{
    AcDbExtents extents;
    impObj()->getNativeCloudExtent(extents);
    return extents;
}

unsigned int PyDbPointCloudEx::getVisiblePointCount() const
{
    return impObj()->getVisiblePointCount();
}

unsigned int PyDbPointCloudEx::getLoadedVisiblePointCount() const
{
    return impObj()->getLoadedVisiblePointCount();
}

unsigned int PyDbPointCloudEx::getDisplayedVisiblePointCount() const
{
    return impObj()->getDisplayedVisiblePointCount();
}

bool PyDbPointCloudEx::setActiveFileName(const std::string& strActiveFileName)
{
    return impObj()->setActiveFileName(utf8_to_wstr(strActiveFileName).c_str());
}

boost::python::tuple PyDbPointCloudEx::getActiveFileName() const
{
    PyAutoLockGIL lock;
    AcString strActiveFileName;
    auto val = impObj()->getActiveFileName(strActiveFileName);
    return boost::python::make_tuple(val, wstr_to_utf8(strActiveFileName));
}

std::string PyDbPointCloudEx::getPointCloudName() const
{
    return wstr_to_utf8(impObj()->getPointCloudName());
}

void PyDbPointCloudEx::setPointCloudName(const std::string& name)
{
    PyThrowBadEs(impObj()->setPointCloudName((utf8_to_wstr(name).c_str())));
}

int PyDbPointCloudEx::getCroppingCount() const
{
    return impObj()->getCroppingCount();
}

void PyDbPointCloudEx::clearCropping()
{
    PyThrowBadEs(impObj()->clearCropping());
}

void PyDbPointCloudEx::removeLastCropping()
{
    PyThrowBadEs(impObj()->removeLastCropping());
}

bool PyDbPointCloudEx::getCroppingInvert() const
{
    return impObj()->getCroppingInvert();
}

void PyDbPointCloudEx::setCroppingInvert(bool invert)
{
    PyThrowBadEs(impObj()->setCroppingInvert(invert));
}

void PyDbPointCloudEx::setInCreatingCroppingMode(bool bCreating)
{
    impObj()->setInCreatingCroppingMode(bCreating);
}

bool PyDbPointCloudEx::showCropped() const
{
    return impObj()->showCropped();
}

void PyDbPointCloudEx::setStylizationType(AcDbPointCloudEx::StylizationType type)
{
    PyThrowBadEs(impObj()->setStylizationType(type));
}

AcDbPointCloudEx::StylizationType PyDbPointCloudEx::stylizationType() const
{
    return impObj()->stylizationType();
}

std::string PyDbPointCloudEx::getCurrentColorScheme() const
{
    return wstr_to_utf8(impObj()->getCurrentColorScheme());
}

void PyDbPointCloudEx::setCurrentColorScheme(const std::string& guid)
{
    PyThrowBadEs(impObj()->setCurrentColorScheme(utf8_to_wstr(guid).c_str()));
}

std::string PyDbPointCloudEx::getColorSchemeForStylization(AcDbPointCloudEx::StylizationType type) const
{
    return wstr_to_utf8(impObj()->getColorSchemeForStylization(type));
}

void PyDbPointCloudEx::setColorSchemeForStylization(const std::string& guid, AcDbPointCloudEx::StylizationType type)
{
    PyThrowBadEs(impObj()->setColorSchemeForStylization(utf8_to_wstr(guid).c_str(), type));
}

bool PyDbPointCloudEx::showIntensityAsGradient() const
{
    return impObj()->showIntensityAsGradient();
}

void PyDbPointCloudEx::setShowIntensityAsGradient(bool b)
{
    impObj()->setShowIntensityAsGradient(b);
}

Adesk::Int32 PyDbPointCloudEx::minIntensity() const
{
    return impObj()->minIntensity();
}

Adesk::Int32 PyDbPointCloudEx::maxIntensity() const
{
    return impObj()->maxIntensity();
}

void PyDbPointCloudEx::setMinMaxIntensity(int min, int max)
{
    PyThrowBadEs(impObj()->setMinMaxIntensity(min, max));
}

AcDbPointCloudEx::DispOptionOutOfRange PyDbPointCloudEx::intensityOutOfRangeBehavior() const
{
    return impObj()->intensityOutOfRangeBehavior();
}

void PyDbPointCloudEx::setIntensityOutOfRangeBehavior(AcDbPointCloudEx::DispOptionOutOfRange dispOp)
{
    impObj()->setIntensityOutOfRangeBehavior(dispOp);
}

bool PyDbPointCloudEx::showElevationAsGradient() const
{
    return impObj()->showElevationAsGradient();
}

void PyDbPointCloudEx::setShowElevationAsGradient(bool b)
{
    impObj()->setShowElevationAsGradient(b);
}

double PyDbPointCloudEx::minElevation() const
{
    return impObj()->minElevation();
}

double PyDbPointCloudEx::maxElevation() const
{
    return impObj()->maxElevation();
}

void PyDbPointCloudEx::setMinMaxElevation(double min, double max)
{
    PyThrowBadEs(impObj()->setMinMaxElevation(min, max));
}

bool PyDbPointCloudEx::elevationApplyToFixedRange() const
{
    return impObj()->elevationApplyToFixedRange();
}

void PyDbPointCloudEx::setElevationApplyToFixedRange(bool val)
{
    impObj()->setElevationApplyToFixedRange(val);
}

AcDbPointCloudEx::DispOptionOutOfRange PyDbPointCloudEx::elevationOutOfRangeBehavior() const
{
    return impObj()->elevationOutOfRangeBehavior();
}

void PyDbPointCloudEx::setElevationOutOfRangeBehavior(AcDbPointCloudEx::DispOptionOutOfRange dispOp)
{
    impObj()->setElevationOutOfRangeBehavior(dispOp);
}

void PyDbPointCloudEx::resetLimitBox()
{
    impObj()->resetLimitBox();
}

void PyDbPointCloudEx::setHighlightLimitboxBoundary(bool val)
{
    impObj()->setHighlightLimitboxBoundary(val);
}

void PyDbPointCloudEx::setScanVisibility(const std::string& scanGuid, bool bVisible)
{
    impObj()->setScanVisibility(utf8_to_wstr(scanGuid).c_str(), bVisible);
}

void PyDbPointCloudEx::setAllScansVisibility(bool bVisible)
{
    impObj()->setAllScansVisibility(bVisible);
}

void PyDbPointCloudEx::setRegionVisibility(int regionId, bool bVisible)
{
    impObj()->setRegionVisibility(regionId, bVisible);
}

void PyDbPointCloudEx::setAllRegionsVisibility1(bool bVisible)
{
    impObj()->setAllRegionsVisibility(bVisible);
}

void PyDbPointCloudEx::setAllRegionsVisibility2(bool bVisible, bool includeUnassigned)
{
    impObj()->setAllRegionsVisibility(bVisible, includeUnassigned);
}

void PyDbPointCloudEx::setAllScansVisibilityByRegion(int regionId, bool bVisible)
{
    impObj()->setAllScansVisibilityByRegion(regionId, bVisible);
}

boost::python::tuple PyDbPointCloudEx::getScanViewInfo(const std::string& scanGuid) const
{
    PyAutoLockGIL lock;
    AcGePoint3d origin;
    AcDbExtents extent;
    auto b = impObj()->getScanViewInfo(utf8_to_wstr(scanGuid).c_str(), origin, extent);
    return boost::python::make_tuple(b, origin, extent);
}

void PyDbPointCloudEx::resetScanRegionVisibility()
{
    impObj()->resetScanRegionVisibility();
}

void PyDbPointCloudEx::setAllScanHighlight(bool bHighlight)
{
    impObj()->setAllScanHighlight(bHighlight);
}

void PyDbPointCloudEx::setAllRegionHighlight1(bool bHighlight)
{
    impObj()->setAllRegionHighlight(bHighlight);
}

void PyDbPointCloudEx::setAllRegionHighlight2(bool bHighlight, bool bIncludeUnassignedPoints)
{
    impObj()->setAllRegionHighlight(bHighlight, bIncludeUnassignedPoints);
}

void PyDbPointCloudEx::applyGeoLocation1()
{
    impObj()->applyGeoLocation();
}

void PyDbPointCloudEx::applyGeoLocation2(bool useDrawingGeo, const std::string& geoCS)
{
    impObj()->applyGeoLocation(useDrawingGeo, utf8_to_wstr(geoCS).c_str());
}

void PyDbPointCloudEx::updateGeoLocation()
{
    impObj()->updateGeoLocation();
}

bool PyDbPointCloudEx::geolocate() const
{
    return impObj()->geolocate();
}

void PyDbPointCloudEx::clearSpatialFilters()
{
    impObj()->clearSpatialFilters();
}

void PyDbPointCloudEx::clearAttributeFilters()
{
    impObj()->clearAttributeFilters();
}

boost::python::tuple PyDbPointCloudEx::getPlaneOrPointAt(const AcGeMatrix3d& viewXform, const AcGePoint3d& pickPt)
{
    PyAutoLockGIL lock;
    AcGePoint3dArray points;
    auto val = impObj()->getPlaneOrPointAt(viewXform, pickPt, points);
    return boost::python::make_tuple(val, Point3dArrayToPyList(points));
}

boost::python::tuple PyDbPointCloudEx::getPlaneBoundaryAt(const AcGeMatrix3d& viewXform, const AcGePoint3d& pickPt)
{
    PyAutoLockGIL lock;
    AcGePoint3dArray points;
    auto val = impObj()->getPlaneBoundaryAt(viewXform, pickPt, points);
    return boost::python::make_tuple(val, Point3dArrayToPyList(points));
}

AcGeMatrix3d PyDbPointCloudEx::objectToWorldMatrix() const
{
    AcGeMatrix3d mat;
    impObj()->objectToWorldMatrix(mat);
    return mat;
}

boost::python::tuple PyDbPointCloudEx::getCandidatePlane(int x, int y) const
{
    PyAutoLockGIL lock;
    CPoint p(x, y);
    AcGePlane result;
    double distToEdge = 0;
    double objWidth = 0;
    double objHeight = 0;
    void* context = 0;
    PyThrowBadEs(impObj()->getCandidatePlane(p, result, distToEdge, objWidth, objHeight, context));
    return boost::python::make_tuple(PyGePlane(result), distToEdge, objWidth, objHeight, intptr_t(context));
}

boost::python::tuple PyDbPointCloudEx::getCylinderAt(const AcGeMatrix3d& viewXform, const AcGePoint3d& pickPt)
{
    PyAutoLockGIL lock;
    AcGePoint3d origin;
    AcGeVector3d axis;
    double height = 0;
    double radius = 0;
    PyThrowBadEs(impObj()->getCylinderAt(viewXform, pickPt, origin, axis, height, radius));
    return boost::python::make_tuple(origin, axis, height, radius);
}

double PyDbPointCloudEx::getMinDistPrecision() const
{
    double minDistPrecision = 0;
    PyThrowBadEs(impObj()->getMinDistPrecision(minDistPrecision));
    return minDistPrecision;
}

boost::python::tuple PyDbPointCloudEx::detectPointBelonger(const AcGePoint3d& ptInWCS) const
{
    PyAutoLockGIL lock;
    AcString scanGuid;
    Adesk::UInt16 segmentIndex;
    PyThrowBadEs(impObj()->detectPointBelonger(ptInWCS, scanGuid, segmentIndex));
    return boost::python::make_tuple(wstr_to_utf8(scanGuid), segmentIndex);
}

boost::python::list PyDbPointCloudEx::getCustomOsnapInfo(AcDbPointCloudEx::PointCloudOSnapMode snapMode, const AcGePoint3d& pickPoint, const AcGePoint3d& lastPoint, const AcGeMatrix3d& viewXform)
{
    PyAutoLockGIL lock;
    AcGePoint3dArray snapPoints;
    PyThrowBadEs(impObj()->getCustomOsnapInfo(snapMode, pickPoint, lastPoint, viewXform, snapPoints));
    return Point3dArrayToPyList(snapPoints);
}

PyDbObjectId PyDbPointCloudEx::attachPointCloud(const std::string& pointCloudFile, AcGePoint3d& location, double scale, double rotation, PyDbDatabase& pDb)
{
    PyDbObjectId newPointCloudExId;
    AcString str = utf8_to_wstr(pointCloudFile).c_str();
    PyThrowBadEs(acdbAttachPointCloudExEntity(newPointCloudExId.m_id, str, location, scale, rotation, pDb.impObj()));
    return newPointCloudExId;
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
