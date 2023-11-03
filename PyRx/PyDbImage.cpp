#include "stdafx.h"
#include "PyDbImage.h"
#include "PyDbObjectId.h"
#include "PyDbDictionary.h"
#include "dbwipe.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------
//PyDbImage
void makePyDbImageWrapper()
{
    class_<PyDbImage, bases<PyDbEntity>>("Image", boost::python::no_init)
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("className", &PyDbImage::className).staticmethod("className")
        .def("desc", &PyDbImage::desc).staticmethod("desc")
        .def("cloneFrom", &PyDbImage::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbImage::cast).staticmethod("cast")
        ;
}

PyDbImage::PyDbImage(AcDbImage* ptr, bool autoDelete)
    : PyDbEntity(ptr, autoDelete)
{
}

PyDbImage::PyDbImage(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbEntity(openAcDbObject<AcDbImage>(id, mode), false)
{
}

PyDbImage::PyDbImage(const PyDbObjectId& id)
    : PyDbImage(id, AcDb::OpenMode::kForRead)
{
}

std::string PyDbImage::className()
{
    return "AcDbImage";
}

PyRxClass PyDbImage::desc()
{
    return PyRxClass(AcDbImage::desc(), false);
}

PyDbImage PyDbImage::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbImage::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbImage(static_cast<AcDbImage*>(src.impObj()->clone()), true);
}

PyDbImage PyDbImage::cast(const PyRxObject& src)
{
    PyDbImage dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbImage* PyDbImage::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbImage*>(m_pyImp.get());
}


//-----------------------------------------------------------------------------------
//PyDbRasterImageDef
void makePyDbRasterImageDefWrapper()
{
    class_<PyDbRasterImageDef, bases<PyDbObject>>("RasterImageDef")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("setSourceFileName", &PyDbRasterImageDef::setSourceFileName)
        .def("setActiveFileName", &PyDbRasterImageDef::setActiveFileName)
        .def("searchForActivePath", &PyDbRasterImageDef::searchForActivePath)
        .def("sourceFileName", &PyDbRasterImageDef::sourceFileName)
        .def("activeFileName", &PyDbRasterImageDef::activeFileName)
        .def("embed", &PyDbRasterImageDef::embed)
        .def("isEmbedded", &PyDbRasterImageDef::isEmbedded)
        .def("load", &PyDbRasterImageDef::load)
        .def("unload", &PyDbRasterImageDef::unload1)
        .def("unload", &PyDbRasterImageDef::unload2)
        .def("isLoaded", &PyDbRasterImageDef::isLoaded)
        .def("size", &PyDbRasterImageDef::size)
        .def("fileType", &PyDbRasterImageDef::fileType)
        .def("entityCount", &PyDbRasterImageDef::entityCount)
        .def("updateEntities", &PyDbRasterImageDef::updateEntities)
        .def("setResolutionMMPerPixel", &PyDbRasterImageDef::setResolutionMMPerPixel)
        .def("resolutionMMPerPixel", &PyDbRasterImageDef::resolutionMMPerPixel)
        .def("setResolutionUnits", &PyDbRasterImageDef::setResolutionUnits)
        .def("resolutionUnits", &PyDbRasterImageDef::resolutionUnits)
        .def("createImageDictionary", &PyDbRasterImageDef::createImageDictionary).staticmethod("createImageDictionary")
        .def("imageDictionary", &PyDbRasterImageDef::imageDictionary).staticmethod("imageDictionary")
        .def("suggestName", &PyDbRasterImageDef::suggestName).staticmethod("suggestName")
        .def("className", &PyDbRasterImageDef::className).staticmethod("className")
        .def("desc", &PyDbRasterImageDef::desc).staticmethod("desc")
        .def("cloneFrom", &PyDbRasterImageDef::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbRasterImageDef::cast).staticmethod("cast")
        ;

    enum_<AcDbRasterImageDef::Units>("ImageUnits")
        .value("kNone", AcDbRasterImageDef::Units::kNone)
        .value("kMillimeter", AcDbRasterImageDef::Units::kMillimeter)
        .value("kCentimeter", AcDbRasterImageDef::Units::kCentimeter)
        .value("kMeter", AcDbRasterImageDef::Units::kMeter)
        .value("kKilometer", AcDbRasterImageDef::Units::kKilometer)
        .value("kInch", AcDbRasterImageDef::Units::kInch)
        .value("kFoot", AcDbRasterImageDef::Units::kFoot)
        .value("kYard", AcDbRasterImageDef::Units::kYard)
        .value("kMile", AcDbRasterImageDef::Units::kMile)
        .value("kMicroinches", AcDbRasterImageDef::Units::kMicroinches)
        .value("kMils", AcDbRasterImageDef::Units::kMils)
        .value("kAngstroms", AcDbRasterImageDef::Units::kAngstroms)
        .value("kNanometers", AcDbRasterImageDef::Units::kNanometers)
        .value("kMicrons", AcDbRasterImageDef::Units::kMicrons)
        .value("kDecimeters", AcDbRasterImageDef::Units::kDecimeters)
        .value("kDekameters", AcDbRasterImageDef::Units::kDekameters)
        .value("kHectometers", AcDbRasterImageDef::Units::kHectometers)
        .value("kGigameters", AcDbRasterImageDef::Units::kGigameters)
        .value("kAstronomical", AcDbRasterImageDef::Units::kAstronomical)
        .value("kLightYears", AcDbRasterImageDef::Units::kLightYears)
        .value("kParsecs", AcDbRasterImageDef::Units::kParsecs)
        .export_values()
        ;
}

PyDbRasterImageDef::PyDbRasterImageDef()
    : PyDbObject(new AcDbRasterImageDef(), true)
{
}

PyDbRasterImageDef::PyDbRasterImageDef(AcDbRasterImageDef* ptr, bool autoDelete)
    : PyDbObject(ptr, autoDelete)
{
}

PyDbRasterImageDef::PyDbRasterImageDef(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbObject(openAcDbObject<AcDbRasterImageDef>(id, mode), false)
{
}

PyDbRasterImageDef::PyDbRasterImageDef(const PyDbObjectId& id)
    : PyDbRasterImageDef(id, AcDb::OpenMode::kForRead)
{
}

void PyDbRasterImageDef::setSourceFileName(const std::string& pPathName)
{
    return PyThrowBadEs(impObj()->setSourceFileName(utf8_to_wstr(pPathName).c_str()));
}

void PyDbRasterImageDef::setActiveFileName(const std::string& pPathName)
{
    return PyThrowBadEs(impObj()->setActiveFileName(utf8_to_wstr(pPathName).c_str()));
}

std::string PyDbRasterImageDef::searchForActivePath()
{
    return wstr_to_utf8(impObj()->searchForActivePath());
}

std::string PyDbRasterImageDef::sourceFileName() const
{
    return wstr_to_utf8(impObj()->sourceFileName());
}

std::string PyDbRasterImageDef::activeFileName() const
{
    return wstr_to_utf8(impObj()->activeFileName());
}

void PyDbRasterImageDef::embed()
{
    return PyThrowBadEs(impObj()->embed());
}

Adesk::Boolean PyDbRasterImageDef::isEmbedded() const
{
    return impObj()->isEmbedded();
}

void PyDbRasterImageDef::load()
{
    return PyThrowBadEs(impObj()->load());
}

void PyDbRasterImageDef::unload1()
{
    return PyThrowBadEs(impObj()->unload());
}

void PyDbRasterImageDef::unload2(Adesk::Boolean modifyDatabase)
{
    return PyThrowBadEs(impObj()->unload(modifyDatabase));
}

Adesk::Boolean PyDbRasterImageDef::isLoaded() const
{
    return impObj()->isLoaded();
}

AcGeVector2d PyDbRasterImageDef::size() const
{
    return impObj()->size();
}

std::string PyDbRasterImageDef::fileType() const
{
    return wstr_to_utf8(impObj()->fileType());
}

int PyDbRasterImageDef::entityCount() const
{
    return impObj()->entityCount();
}

void PyDbRasterImageDef::updateEntities() const
{
    return impObj()->updateEntities();
}

void PyDbRasterImageDef::setResolutionMMPerPixel(const AcGeVector2d& resMMPerPixel)
{
    return PyThrowBadEs(impObj()->setResolutionMMPerPixel(resMMPerPixel));
}

AcGeVector2d PyDbRasterImageDef::resolutionMMPerPixel() const
{
    return impObj()->resolutionMMPerPixel();
}

void PyDbRasterImageDef::setResolutionUnits(AcDbRasterImageDef::Units units)
{
    return impObj()->setResolutionUnits(units);
}

AcDbRasterImageDef::Units PyDbRasterImageDef::resolutionUnits() const
{
    return impObj()->resolutionUnits();
}

PyDbObjectId PyDbRasterImageDef::createImageDictionary(PyDbDatabase& pDb)
{
    PyDbObjectId id;
    PyThrowBadEs(AcDbRasterImageDef::createImageDictionary(pDb.impObj(), id.m_id));
    return id;
}

PyDbObjectId PyDbRasterImageDef::imageDictionary(PyDbDatabase& pDb)
{
    return PyDbObjectId(AcDbRasterImageDef::imageDictionary(pDb.impObj()));
}

std::string PyDbRasterImageDef::suggestName(PyDbDictionary& dict, const std::string& pPathName)
{
    ACHAR newImageName[AcDbRasterImageDef::kMaxSuggestNameSize];
    AcDbRasterImageDef::suggestName(dict.impObj(), utf8_to_wstr(pPathName).c_str(), newImageName, AcDbRasterImageDef::kMaxSuggestNameSize);
    return wstr_to_utf8(newImageName);
}

std::string PyDbRasterImageDef::className()
{
    return "AcDbRasterImageDef";
}

PyRxClass PyDbRasterImageDef::desc()
{
    return PyRxClass(AcDbRasterImageDef::desc(), false);
}

PyDbRasterImageDef PyDbRasterImageDef::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbRasterImageDef::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbRasterImageDef(static_cast<AcDbRasterImageDef*>(src.impObj()->clone()), true);
}

PyDbRasterImageDef PyDbRasterImageDef::cast(const PyRxObject& src)
{
    PyDbRasterImageDef dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbRasterImageDef* PyDbRasterImageDef::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbRasterImageDef*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyDbRasterImageDefReactor
void makePyDbRasterImageDefReactorWrapper()
{
    class_<PyDbRasterImageDefReactor, bases<PyDbObject>>("RasterImageDefReactor")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("setEnable", &PyDbRasterImageDefReactor::setEnable).staticmethod("setEnable")
        .def("className", &PyDbRasterImageDefReactor::className).staticmethod("className")
        .def("desc", &PyDbRasterImageDefReactor::desc).staticmethod("desc")
        .def("cloneFrom", &PyDbRasterImageDefReactor::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbRasterImageDefReactor::cast).staticmethod("cast")
        ;
}

PyDbRasterImageDefReactor::PyDbRasterImageDefReactor()
    : PyDbObject(new AcDbRasterImageDefReactor(), true)
{
}

PyDbRasterImageDefReactor::PyDbRasterImageDefReactor(AcDbRasterImageDefReactor* ptr, bool autoDelete)
    : PyDbObject(ptr, autoDelete)
{
}

PyDbRasterImageDefReactor::PyDbRasterImageDefReactor(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbObject(openAcDbObject<AcDbRasterImageDefReactor>(id, mode), false)
{
}

PyDbRasterImageDefReactor::PyDbRasterImageDefReactor(const PyDbObjectId& id)
    : PyDbRasterImageDefReactor(id, AcDb::OpenMode::kForRead)
{
}

void PyDbRasterImageDefReactor::setEnable(Adesk::Boolean enable)
{
    AcDbRasterImageDefReactor::setEnable(enable);
}

std::string PyDbRasterImageDefReactor::className()
{
    return "AcDbRasterImageDefReactor";
}

PyRxClass PyDbRasterImageDefReactor::desc()
{
    return PyRxClass(AcDbRasterImageDefReactor::desc(), false);
}

PyDbRasterImageDefReactor PyDbRasterImageDefReactor::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbRasterImageDefReactor::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbRasterImageDefReactor(static_cast<AcDbRasterImageDefReactor*>(src.impObj()->clone()), true);
}

PyDbRasterImageDefReactor PyDbRasterImageDefReactor::cast(const PyRxObject& src)
{
    PyDbRasterImageDefReactor dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbRasterImageDefReactor* PyDbRasterImageDefReactor::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbRasterImageDefReactor*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//AcDbRasterImage
void makePyDbRasterImageWrapper()
{
    class_<PyDbRasterImage, bases<PyDbImage>>("RasterImage")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("setImageDefId", &PyDbRasterImage::setImageDefId)
        .def("imageDefId", &PyDbRasterImage::imageDefId)
        .def("setReactorId", &PyDbRasterImage::setReactorId)
        .def("reactorId", &PyDbRasterImage::reactorId)
        .def("setOrientation", &PyDbRasterImage::setOrientation)
        .def("getOrientation", &PyDbRasterImage::getOrientation)
        .def("scale", &PyDbRasterImage::scale)
        .def("imageSize", &PyDbRasterImage::imageSize1)
        .def("imageSize", &PyDbRasterImage::imageSize2)
        .def("setClipBoundaryToWholeImage", &PyDbRasterImage::setClipBoundaryToWholeImage)
        .def("clipBoundary", &PyDbRasterImage::clipBoundary)
        .def("clipBoundaryType", &PyDbRasterImage::clipBoundaryType)
        .def("isClipped", &PyDbRasterImage::isClipped)
        .def("getVertices", &PyDbRasterImage::getVertices)
        .def("getPixelToModelTransform", &PyDbRasterImage::getPixelToModelTransform)
        .def("setDisplayOpt", &PyDbRasterImage::setDisplayOpt)
        .def("isSetDisplayOpt", &PyDbRasterImage::isSetDisplayOpt)
        .def("setBrightness", &PyDbRasterImage::setBrightness)
        .def("brightness", &PyDbRasterImage::brightness)
        .def("setContrast", &PyDbRasterImage::setContrast)
        .def("contrast", &PyDbRasterImage::contrast)
        .def("setFade", &PyDbRasterImage::setFade)
        .def("fade", &PyDbRasterImage::fade)
        .def("isClipInverted", &PyDbRasterImage::isClipInverted)
        .def("setClipInverted", &PyDbRasterImage::setClipInverted)
        .def("width", &PyDbRasterImage::width)
        .def("height", &PyDbRasterImage::height)
        .def("imageHeight", &PyDbRasterImage::imageHeight)
        .def("imageWidth", &PyDbRasterImage::imageWidth)
        .def("setHeight", &PyDbRasterImage::setHeight)
        .def("setWidth", &PyDbRasterImage::setWidth)
        .def("position", &PyDbRasterImage::position)
        .def("rotation", &PyDbRasterImage::rotation)
        .def("setRotation", &PyDbRasterImage::setRotation)
        .def("isImageShown", &PyDbRasterImage::isImageShown)
        .def("setShowImage", &PyDbRasterImage::setShowImage)
        .def("isImageTransparent", &PyDbRasterImage::isImageTransparent)
        .def("setImageTransparency", &PyDbRasterImage::setImageTransparency)
        .def("isShownClipped", &PyDbRasterImage::isShownClipped)
        .def("setShowClipped", &PyDbRasterImage::setShowClipped)
        .def("className", &PyDbRasterImage::className).staticmethod("className")
        .def("desc", &PyDbRasterImage::desc).staticmethod("desc")
        .def("cloneFrom", &PyDbRasterImage::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbRasterImage::cast).staticmethod("cast")
        ;
    enum_<AcDbRasterImage::ClipBoundaryType>("ClipBoundaryType")
        .value("kInvalid", AcDbRasterImage::ClipBoundaryType::kInvalid)
        .value("kRect", AcDbRasterImage::ClipBoundaryType::kRect)
        .value("kPoly", AcDbRasterImage::ClipBoundaryType::kPoly)
        .export_values()
        ;
    enum_<AcDbRasterImage::ImageDisplayOpt>("ImageDisplayOpt")
        .value("kShow", AcDbRasterImage::ImageDisplayOpt::kShow)
        .value("kShowUnAligned", AcDbRasterImage::ImageDisplayOpt::kShowUnAligned)
        .value("kClip", AcDbRasterImage::ImageDisplayOpt::kClip)
        .value("kTransparent", AcDbRasterImage::ImageDisplayOpt::kTransparent)
        .export_values()
        ;
}

PyDbRasterImage::PyDbRasterImage()
    : PyDbImage(new AcDbRasterImage(), true)
{
}

PyDbRasterImage::PyDbRasterImage(AcDbRasterImage* ptr, bool autoDelete)
    : PyDbImage(ptr, autoDelete)
{
}

PyDbRasterImage::PyDbRasterImage(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbImage(openAcDbObject<AcDbRasterImage>(id, mode), false)
{
}

PyDbRasterImage::PyDbRasterImage(const PyDbObjectId& id)
    : PyDbRasterImage(id, AcDb::OpenMode::kForRead)
{
}

void PyDbRasterImage::setImageDefId(const PyDbObjectId& imageId)
{
    return PyThrowBadEs(impObj()->setImageDefId(imageId.m_id));
}

PyDbObjectId PyDbRasterImage::imageDefId() const
{
    return PyDbObjectId(impObj()->imageDefId());
}

void PyDbRasterImage::setReactorId(const PyDbObjectId& reactorId)
{
    return impObj()->setReactorId(reactorId.m_id);
}

PyDbObjectId PyDbRasterImage::reactorId() const
{
    return PyDbObjectId(impObj()->reactorId());
}

Adesk::Boolean PyDbRasterImage::setOrientation(const AcGePoint3d& origin, const AcGeVector3d& uCorner, const AcGeVector3d& vOnPlane)
{
    return impObj()->setOrientation(origin, uCorner, vOnPlane);
}

void PyDbRasterImage::getOrientation(AcGePoint3d& origin, AcGeVector3d& u, AcGeVector3d& v) const
{
    return impObj()->getOrientation(origin, u, v);
}

AcGeVector2d PyDbRasterImage::scale() const
{
    return impObj()->scale();
}

AcGeVector2d PyDbRasterImage::imageSize1() const
{
    return impObj()->imageSize();
}

AcGeVector2d PyDbRasterImage::imageSize2(Adesk::Boolean bGetCachedValue) const
{
    return impObj()->imageSize(bGetCachedValue);
}

void PyDbRasterImage::setClipBoundaryToWholeImage(AcGeVector2d& size)
{
    return PyThrowBadEs(impObj()->setClipBoundaryToWholeImage(size));
}

boost::python::list PyDbRasterImage::clipBoundary() const
{
    return Point2dArrayToPyList(impObj()->clipBoundary());
}

AcDbRasterImage::ClipBoundaryType PyDbRasterImage::clipBoundaryType() const
{
    return impObj()->clipBoundaryType();
}

Adesk::Boolean PyDbRasterImage::isClipped() const
{
    return impObj()->isClipped();
}

boost::python::list PyDbRasterImage::getVertices() const
{
    AcGePoint3dArray verts;
    PyThrowBadEs(impObj()->getVertices(verts));
    return Point3dArrayToPyList(verts);
}

AcGeMatrix3d PyDbRasterImage::getPixelToModelTransform() const
{
    AcGeMatrix3d x;
    PyThrowBadEs(impObj()->getPixelToModelTransform(x));
    return x;
}

void PyDbRasterImage::setDisplayOpt(AcDbRasterImage::ImageDisplayOpt option, Adesk::Boolean bValue)
{
    return impObj()->setDisplayOpt(option, bValue);
}

Adesk::Boolean PyDbRasterImage::isSetDisplayOpt(AcDbRasterImage::ImageDisplayOpt option) const
{
    return impObj()->isSetDisplayOpt(option);
}

void PyDbRasterImage::setBrightness(Adesk::Int8 value)
{
    return PyThrowBadEs(impObj()->setBrightness(value));
}

Adesk::Int8 PyDbRasterImage::brightness() const
{
    return impObj()->brightness();
}

void PyDbRasterImage::setContrast(Adesk::Int8 value)
{
    return PyThrowBadEs(impObj()->setContrast(value));
}

Adesk::Int8 PyDbRasterImage::contrast() const
{
    return impObj()->contrast();
}

void PyDbRasterImage::setFade(Adesk::Int8 value)
{
    return PyThrowBadEs(impObj()->setFade(value));
}

Adesk::Int8 PyDbRasterImage::fade() const
{
    return impObj()->fade();
}

Adesk::Boolean PyDbRasterImage::isClipInverted() const
{
    return impObj()->isClipInverted();
}

void PyDbRasterImage::setClipInverted(Adesk::Boolean newVal)
{
    return impObj()->setClipInverted(newVal);
}

double PyDbRasterImage::width() const
{
    return impObj()->width();
}

double PyDbRasterImage::height() const
{
    return impObj()->height();
}

double PyDbRasterImage::imageHeight() const
{
    return impObj()->imageHeight();
}

double PyDbRasterImage::imageWidth() const
{
    return impObj()->imageWidth();
}

void PyDbRasterImage::setHeight(double val)
{
    return PyThrowBadEs(impObj()->setHeight(val));
}

void PyDbRasterImage::setWidth(double val)
{
    return PyThrowBadEs(impObj()->setWidth(val));
}

AcGePoint3d PyDbRasterImage::position() const
{
    return impObj()->position();
}

double PyDbRasterImage::rotation() const
{
    return impObj()->rotation();
}

void PyDbRasterImage::setRotation(double rotation)
{
    return PyThrowBadEs(impObj()->setRotation(rotation));
}

bool PyDbRasterImage::isImageShown() const
{
    return impObj()->isImageShown();
}

void PyDbRasterImage::setShowImage(bool value)
{
    return impObj()->setShowImage(value);
}

bool PyDbRasterImage::isImageTransparent() const
{
    return impObj()->isImageTransparent();
}

void PyDbRasterImage::setImageTransparency(bool value)
{
    return impObj()->setImageTransparency(value);
}

bool PyDbRasterImage::isShownClipped() const
{
    return impObj()->isShownClipped();
}

void PyDbRasterImage::setShowClipped(bool value)
{
    return impObj()->setShowClipped(value);
}

std::string PyDbRasterImage::className()
{
    return "AcDbRasterImage";
}

PyRxClass PyDbRasterImage::desc()
{
    return PyRxClass(AcDbRasterImage::desc(), false);
}

PyDbRasterImage PyDbRasterImage::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbRasterImage::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbRasterImage(static_cast<AcDbRasterImage*>(src.impObj()->clone()), true);
}

PyDbRasterImage PyDbRasterImage::cast(const PyRxObject& src)
{
    PyDbRasterImage dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbRasterImage* PyDbRasterImage::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbRasterImage*>(m_pyImp.get());
}


//-----------------------------------------------------------------------------------
//AcDbRasterImage
void makePyDbWipeoutWrapper()
{
    PyDocString DS("Wipeout");
    class_<PyDbWipeout, bases<PyDbRasterImage>>("Wipeout")
        .def(init<>())
        .def(init<const boost::python::list&, const AcGeVector3d&>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>())
        .def("frame", &PyDbWipeout::frame,DS.ARGS())
        .def("setFrom", &PyDbWipeout::setFrom, DS.ARGS({ "points : list[PyGe.Point2d]", "normal : PyGe.Vector3d" }))
        .def("className", &PyDbWipeout::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbWipeout::desc, DS.SARGS()).staticmethod("desc")
        .def("cloneFrom", &PyDbWipeout::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbWipeout::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

static AcDbWipeout* PyDbWipeoutFactory()
{
    PyThrowBadEs(AcDbWipeout::createImageDefinition());
    return new AcDbWipeout();
}


PyDbWipeout::PyDbWipeout()
    : PyDbWipeout(PyDbWipeoutFactory(), true)
{
}

PyDbWipeout::PyDbWipeout(const boost::python::list& pylist, const AcGeVector3d& vec)
    : PyDbWipeout(PyDbWipeoutFactory(), true)
{
    setFrom(pylist, vec);
}

PyDbWipeout::PyDbWipeout(AcDbWipeout* ptr, bool autoDelete)
    : PyDbRasterImage(ptr, autoDelete)
{
}

PyDbWipeout::PyDbWipeout(const PyDbObjectId& id)
    : PyDbWipeout(openAcDbObject<AcDbWipeout>(id, AcDb::kForRead), false)
{
}

PyDbWipeout::PyDbWipeout(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbWipeout(openAcDbObject<AcDbWipeout>(id, mode), false)
{
}

PyDbWipeout::PyDbWipeout(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbWipeout(openAcDbObject<AcDbWipeout>(id, mode, erased), false)
{
}

Adesk::Boolean PyDbWipeout::frame() const
{
    return impObj()->frame();
}

void PyDbWipeout::setFrom(const boost::python::list& pylist, const AcGeVector3d& normal)
{
    double scale= normal.z;
    AcGePoint2d minPoint(normal.x, normal.y);
    auto pnts = PyListToPoint2dArray(pylist);

    PyThrowBadEs(AcDbWipeout::fitPointsToImage(pnts, minPoint, scale, true));
    PyThrowBadEs(impObj()->setClipBoundary(AcDbRasterImage::kPoly, pnts));

    AcGeVector3d uCorner(scale, 0.0, 0.0);
    AcGeVector3d vOnPlane(0.0, scale, 0.0);
    AcGePoint3d origin; (minPoint.x, minPoint.y, 0.0);

    ads_point tmp = { 0.0,0.0,0.0 };
    acdbEcs2Wcs(asDblArray(origin), tmp, asDblArray(normal), false);
    origin = asPnt3d(tmp);

    acdbEcs2Wcs(asDblArray(uCorner), tmp, asDblArray(normal), true);
    uCorner = asVec3d(tmp);

    acdbEcs2Wcs(asDblArray(vOnPlane), tmp, asDblArray(normal), true);
    vOnPlane = asVec3d(tmp);

    impObj()->setOrientation(origin, uCorner, vOnPlane);
}

std::string PyDbWipeout::className()
{
    return "AcDbWipeout";
}

PyRxClass PyDbWipeout::desc()
{
    return PyRxClass(AcDbWipeout::desc(), false);
}

PyDbWipeout PyDbWipeout::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbWipeout::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbWipeout(static_cast<AcDbWipeout*>(src.impObj()->clone()), true);
}

PyDbWipeout PyDbWipeout::cast(const PyRxObject& src)
{
    PyDbWipeout dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbWipeout* PyDbWipeout::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbWipeout*>(m_pyImp.get());
}
