#include "stdafx.h"
#include "stdafx.h"
#include "PyDbImage.h"
#include "PyDbObjectId.h"
#include "PyDbDictionary.h"


using namespace boost::python;

//-----------------------------------------------------------------------------------
//PyDbImage
void makePyDbImageWrapper()
{
    PyDocString DS("Image");
    class_<PyDbImage, bases<PyDbEntity>>("Image", boost::python::no_init)
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: PyDb.ObjectId", "mode: PyDb.OpenMode = PyDb.OpenMode.kForRead", "erased: bool=False" }, 5602)))
        .def("className", &PyDbImage::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbImage::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbImage::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbImage::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
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

PyDbImage::PyDbImage(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbEntity(openAcDbObject<AcDbImage>(id, mode, erased), false)
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
    return PyDbObjectCloneFrom<PyDbImage, AcDbImage>(src);
}

PyDbImage PyDbImage::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbImage>(src);
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
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    PyDocString DS("RasterImageDef");
    class_<PyDbRasterImageDef, bases<PyDbObject>>("RasterImageDef")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.CTOR(ctords, 7956)))
        .def("setSourceFileName", &PyDbRasterImageDef::setSourceFileName, DS.ARGS({ "val: str" }))
        .def("setActiveFileName", &PyDbRasterImageDef::setActiveFileName, DS.ARGS({ "val: str" }))
        .def("searchForActivePath", &PyDbRasterImageDef::searchForActivePath, DS.ARGS())
        .def("sourceFileName", &PyDbRasterImageDef::sourceFileName, DS.ARGS())
        .def("activeFileName", &PyDbRasterImageDef::activeFileName, DS.ARGS())
        .def("embed", &PyDbRasterImageDef::embed, DS.ARGS())
        .def("isEmbedded", &PyDbRasterImageDef::isEmbedded, DS.ARGS())
        .def("load", &PyDbRasterImageDef::load, DS.ARGS())
        .def("unload", &PyDbRasterImageDef::unload1)
        .def("unload", &PyDbRasterImageDef::unload2, DS.ARGS({ "val: bool=True" }))
        .def("isLoaded", &PyDbRasterImageDef::isLoaded, DS.ARGS())
        .def("size", &PyDbRasterImageDef::size, DS.ARGS())
        .def("fileType", &PyDbRasterImageDef::fileType, DS.ARGS())
        .def("entityCount", &PyDbRasterImageDef::entityCount, DS.ARGS())
        .def("updateEntities", &PyDbRasterImageDef::updateEntities, DS.ARGS())
        .def("setResolutionMMPerPixel", &PyDbRasterImageDef::setResolutionMMPerPixel, DS.ARGS({ "vec: PyGe.Vector2d" }))
        .def("resolutionMMPerPixel", &PyDbRasterImageDef::resolutionMMPerPixel, DS.ARGS())
        .def("setResolutionUnits", &PyDbRasterImageDef::setResolutionUnits, DS.ARGS({ "val: PyDb.ImageUnits" }))
        .def("resolutionUnits", &PyDbRasterImageDef::resolutionUnits, DS.ARGS())
        .def("createImageDictionary", &PyDbRasterImageDef::createImageDictionary, DS.SARGS({ "db: PyDb.Database" })).staticmethod("createImageDictionary")
        .def("imageDictionary", &PyDbRasterImageDef::imageDictionary, DS.SARGS({ "db: PyDb.Database" })).staticmethod("imageDictionary")
        .def("suggestName", &PyDbRasterImageDef::suggestName, DS.SARGS({ "db: PyDb.Dictionary","name: str" })).staticmethod("suggestName")
        .def("className", &PyDbRasterImageDef::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbRasterImageDef::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbRasterImageDef::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbRasterImageDef::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
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

PyDbRasterImageDef::PyDbRasterImageDef(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbObject(openAcDbObject<AcDbRasterImageDef>(id, mode, erased), false)
{
}

void PyDbRasterImageDef::setSourceFileName(const std::string& pPathName) const
{
    return PyThrowBadEs(impObj()->setSourceFileName(utf8_to_wstr(pPathName).c_str()));
}

void PyDbRasterImageDef::setActiveFileName(const std::string& pPathName) const
{
    return PyThrowBadEs(impObj()->setActiveFileName(utf8_to_wstr(pPathName).c_str()));
}

std::string PyDbRasterImageDef::searchForActivePath() const
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

void PyDbRasterImageDef::embed() const
{
    return PyThrowBadEs(impObj()->embed());
}

Adesk::Boolean PyDbRasterImageDef::isEmbedded() const
{
    return impObj()->isEmbedded();
}

void PyDbRasterImageDef::load() const
{
    return PyThrowBadEs(impObj()->load());
}

void PyDbRasterImageDef::unload1() const
{
    return PyThrowBadEs(impObj()->unload());
}

void PyDbRasterImageDef::unload2(Adesk::Boolean modifyDatabase) const
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

void PyDbRasterImageDef::setResolutionMMPerPixel(const AcGeVector2d& resMMPerPixel) const
{
    return PyThrowBadEs(impObj()->setResolutionMMPerPixel(resMMPerPixel));
}

AcGeVector2d PyDbRasterImageDef::resolutionMMPerPixel() const
{
    return impObj()->resolutionMMPerPixel();
}

void PyDbRasterImageDef::setResolutionUnits(AcDbRasterImageDef::Units units) const
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
    return PyDbObjectCloneFrom<PyDbRasterImageDef, AcDbRasterImageDef>(src);
}

PyDbRasterImageDef PyDbRasterImageDef::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbRasterImageDef>(src);
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
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n";

    PyDocString DS("RasterImageDefReactor");
    class_<PyDbRasterImageDefReactor, bases<PyDbObject>>("RasterImageDefReactor")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>(DS.CTOR(ctords, 7965)))
        .def("setEnable", &PyDbRasterImageDefReactor::setEnable, DS.SARGS({ "val: bool" })).staticmethod("setEnable")
        .def("className", &PyDbRasterImageDefReactor::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbRasterImageDefReactor::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbRasterImageDefReactor::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbRasterImageDefReactor::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
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
    return PyDbObjectCloneFrom<PyDbRasterImageDefReactor, AcDbRasterImageDefReactor>(src);
}

PyDbRasterImageDefReactor PyDbRasterImageDefReactor::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbRasterImageDefReactor>(src);
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
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    PyDocString DS("RasterImage");
    class_<PyDbRasterImage, bases<PyDbImage>>("RasterImage")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>(DS.CTOR(ctords)))
        .def("setImageDefId", &PyDbRasterImage::setImageDefId, DS.ARGS({ "id: PyDb.ObjectId" }))
        .def("imageDefId", &PyDbRasterImage::imageDefId, DS.ARGS())
        .def("setReactorId", &PyDbRasterImage::setReactorId, DS.ARGS({ "id: PyDb.ObjectId" }))
        .def("reactorId", &PyDbRasterImage::reactorId, DS.ARGS())
        .def("setOrientation", &PyDbRasterImage::setOrientation, DS.ARGS({ "pt: PyGe.Point3d","u: PyGe.Vector3d","v: PyGe.Vector3d" }))
        .def("getOrientation", &PyDbRasterImage::getOrientation, DS.ARGS())
        .def("scale", &PyDbRasterImage::scale, DS.ARGS())
        .def("imageSize", &PyDbRasterImage::imageSize1)
        .def("imageSize", &PyDbRasterImage::imageSize2, DS.ARGS({ "val: bool=True" }))
        .def("setClipBoundaryToWholeImage", &PyDbRasterImage::setClipBoundaryToWholeImage, DS.ARGS({ "vec: PyGe.Vector2d" }))
        .def("clipBoundary", &PyDbRasterImage::clipBoundary, DS.ARGS())
        .def("clipBoundaryType", &PyDbRasterImage::clipBoundaryType, DS.ARGS())
        .def("isClipped", &PyDbRasterImage::isClipped, DS.ARGS())
        .def("getVertices", &PyDbRasterImage::getVertices, DS.ARGS())
        .def("getPixelToModelTransform", &PyDbRasterImage::getPixelToModelTransform, DS.ARGS())
        .def("setDisplayOpt", &PyDbRasterImage::setDisplayOpt, DS.ARGS({ "opt: PyDb.ImageDisplayOpt","val: bool" }))
        .def("isSetDisplayOpt", &PyDbRasterImage::isSetDisplayOpt, DS.ARGS({ "val: PyDb.ImageDisplayOpt" }))
        .def("setBrightness", &PyDbRasterImage::setBrightness, DS.ARGS({ "val: int" }))
        .def("brightness", &PyDbRasterImage::brightness, DS.ARGS())
        .def("setContrast", &PyDbRasterImage::setContrast, DS.ARGS({ "val: int" }))
        .def("contrast", &PyDbRasterImage::contrast, DS.ARGS())
        .def("setFade", &PyDbRasterImage::setFade, DS.ARGS({ "val: int" }))
        .def("fade", &PyDbRasterImage::fade, DS.ARGS())
        .def("isClipInverted", &PyDbRasterImage::isClipInverted, DS.ARGS())
        .def("setClipInverted", &PyDbRasterImage::setClipInverted, DS.ARGS({ "val: bool" }))
        .def("width", &PyDbRasterImage::width, DS.ARGS())
        .def("height", &PyDbRasterImage::height, DS.ARGS())
        .def("imageHeight", &PyDbRasterImage::imageHeight, DS.ARGS())
        .def("imageWidth", &PyDbRasterImage::imageWidth, DS.ARGS())
        .def("setHeight", &PyDbRasterImage::setHeight, DS.ARGS({ "val: float" }))
        .def("setWidth", &PyDbRasterImage::setWidth, DS.ARGS({ "val: float" }))
        .def("position", &PyDbRasterImage::position, DS.ARGS())
        .def("rotation", &PyDbRasterImage::rotation, DS.ARGS())
        .def("setRotation", &PyDbRasterImage::setRotation, DS.ARGS({ "val: float" }))
        .def("isImageShown", &PyDbRasterImage::isImageShown, DS.ARGS())
        .def("setShowImage", &PyDbRasterImage::setShowImage, DS.ARGS({ "val: bool" }))
        .def("isImageTransparent", &PyDbRasterImage::isImageTransparent, DS.ARGS())
        .def("setImageTransparency", &PyDbRasterImage::setImageTransparency, DS.ARGS({ "val: bool" }))
        .def("isShownClipped", &PyDbRasterImage::isShownClipped, DS.ARGS())
        .def("setShowClipped", &PyDbRasterImage::setShowClipped, DS.ARGS({ "val: bool" }))
        .def("className", &PyDbRasterImage::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbRasterImage::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbRasterImage::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbRasterImage::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
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

void PyDbRasterImage::setImageDefId(const PyDbObjectId& imageId) const
{
    return PyThrowBadEs(impObj()->setImageDefId(imageId.m_id));
}

PyDbObjectId PyDbRasterImage::imageDefId() const
{
    return PyDbObjectId(impObj()->imageDefId());
}

void PyDbRasterImage::setReactorId(const PyDbObjectId& reactorId) const
{
    return impObj()->setReactorId(reactorId.m_id);
}

PyDbObjectId PyDbRasterImage::reactorId() const
{
    return PyDbObjectId(impObj()->reactorId());
}

Adesk::Boolean PyDbRasterImage::setOrientation(const AcGePoint3d& origin, const AcGeVector3d& uCorner, const AcGeVector3d& vOnPlane) const
{
    return impObj()->setOrientation(origin, uCorner, vOnPlane);
}

boost::python::tuple PyDbRasterImage::getOrientation() const
{
    AcGePoint3d origin;
    AcGeVector3d u;
    AcGeVector3d v;
    impObj()->getOrientation(origin, u, v);
    PyAutoLockGIL lock;
    return boost::python::make_tuple(origin, u, v);
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

void PyDbRasterImage::setClipBoundaryToWholeImage(AcGeVector2d& size) const
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

void PyDbRasterImage::setDisplayOpt(AcDbRasterImage::ImageDisplayOpt option, Adesk::Boolean bValue) const
{
    return impObj()->setDisplayOpt(option, bValue);
}

Adesk::Boolean PyDbRasterImage::isSetDisplayOpt(AcDbRasterImage::ImageDisplayOpt option) const
{
    return impObj()->isSetDisplayOpt(option);
}

void PyDbRasterImage::setBrightness(Adesk::Int8 value) const
{
    return PyThrowBadEs(impObj()->setBrightness(value));
}

Adesk::Int8 PyDbRasterImage::brightness() const
{
    return impObj()->brightness();
}

void PyDbRasterImage::setContrast(Adesk::Int8 value) const
{
    return PyThrowBadEs(impObj()->setContrast(value));
}

Adesk::Int8 PyDbRasterImage::contrast() const
{
    return impObj()->contrast();
}

void PyDbRasterImage::setFade(Adesk::Int8 value) const
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

void PyDbRasterImage::setClipInverted(Adesk::Boolean newVal) const
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

void PyDbRasterImage::setHeight(double val) const
{
    return PyThrowBadEs(impObj()->setHeight(val));
}

void PyDbRasterImage::setWidth(double val) const
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

void PyDbRasterImage::setRotation(double rotation) const
{
    return PyThrowBadEs(impObj()->setRotation(rotation));
}

bool PyDbRasterImage::isImageShown() const
{
    return impObj()->isImageShown();
}

void PyDbRasterImage::setShowImage(bool value) const
{
    return impObj()->setShowImage(value);
}

bool PyDbRasterImage::isImageTransparent() const
{
    return impObj()->isImageTransparent();
}

void PyDbRasterImage::setImageTransparency(bool value) const
{
    return impObj()->setImageTransparency(value);
}

bool PyDbRasterImage::isShownClipped() const
{
    return impObj()->isShownClipped();
}

void PyDbRasterImage::setShowClipped(bool value) const
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
    return PyDbObjectCloneFrom<PyDbRasterImage, AcDbRasterImage>(src);
}

PyDbRasterImage PyDbRasterImage::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbRasterImage>(src);
}

AcDbRasterImage* PyDbRasterImage::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbRasterImage*>(m_pyImp.get());
}


//-----------------------------------------------------------------------------------
//PyDbWipeout
void makePyDbWipeoutWrapper()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- points: list[PyGe.Point2d], normal: PyGe.Vector3d\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    PyDocString DS("Wipeout");
    class_<PyDbWipeout, bases<PyDbRasterImage>>("Wipeout")
        .def(init<>())
        .def(init<const boost::python::list&, const AcGeVector3d&>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.CTOR(ctords, 10298)))
        .def("frame", &PyDbWipeout::frame, DS.ARGS())
        .def("setFrom", &PyDbWipeout::setFrom, DS.ARGS({ "points : list[PyGe.Point2d]", "normal : PyGe.Vector3d" }))
        .def("className", &PyDbWipeout::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbWipeout::desc, DS.SARGS(15560)).staticmethod("desc")
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

void PyDbWipeout::setFrom(const boost::python::list& pylist, const AcGeVector3d& normal) const
{
    double scale = normal.z;
    AcGePoint2d minPoint(normal.x, normal.y);
    auto pnts = PyListToPoint2dArray(pylist);

    PyThrowBadEs(AcDbWipeout::fitPointsToImage(pnts, minPoint, scale, true));
    PyThrowBadEs(impObj()->setClipBoundary(AcDbRasterImage::kPoly, pnts));

    AcGeVector3d uCorner(scale, 0.0, 0.0);
    AcGeVector3d vOnPlane(0.0, scale, 0.0);
    AcGePoint3d origin(minPoint.x, minPoint.y, 0.0);

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
    return PyDbObjectCloneFrom<PyDbWipeout, AcDbWipeout>(src);
}

PyDbWipeout PyDbWipeout::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbWipeout>(src);
}

AcDbWipeout* PyDbWipeout::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbWipeout*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyDbGeoMap

void makePyDbGeoMapWrapper()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- mapType: PyDb.AcGeoMapType, res: PyDb.AcGeoMapResolution, levelOfDetail: int\n"
        "- viewportId: PyDb.ObjectId, isViewportSpecific: bool\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    PyDocString DS("GeoMap");
    class_<PyDbGeoMap, bases<PyDbRasterImage>>("GeoMap", boost::python::no_init)
        .def(init<AcGeoMapType, AcGeoMapResolution, unsigned int>())
#if defined(_BRXTARGET250)
        //Not in BRX
#else
        .def(init<const PyDbObjectId&, bool>())
#endif
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.CTOR(ctords, 4870)))
        .def("bottomLeftPt", &PyDbGeoMap::bottomLeftPt, DS.ARGS())
        .def("height", &PyDbGeoMap::height, DS.ARGS())
        .def("width", &PyDbGeoMap::width, DS.ARGS())
        .def("imageBottomLeftPt", &PyDbGeoMap::imageBottomLeftPt, DS.ARGS())
        .def("imageHeight", &PyDbGeoMap::imageHeight, DS.ARGS())
        .def("imageWidth", &PyDbGeoMap::imageWidth, DS.ARGS())
        .def("resolution", &PyDbGeoMap::resolution, DS.ARGS())
        .def("setResolution", &PyDbGeoMap::setResolution, DS.ARGS({ "val : PyDb.AcGeoMapResolution" }))
        .def("LOD", &PyDbGeoMap::LOD, DS.ARGS())
        .def("mapType", &PyDbGeoMap::mapType, DS.ARGS())
        .def("setMapType", &PyDbGeoMap::setMapType, DS.ARGS({ "val : PyDb.AcGeoMapType" }))
        .def("isOutOfDate", &PyDbGeoMap::isOutOfDate, DS.ARGS())
        .def("updateMapImage", &PyDbGeoMap::updateMapImage1)
        .def("updateMapImage", &PyDbGeoMap::updateMapImage2, DS.ARGS({ "reset : bool = False" }))
        .def("className", &PyDbGeoMap::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbGeoMap::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbGeoMap::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbGeoMap::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyDbGeoMap::PyDbGeoMap(AcGeoMapType mapType, AcGeoMapResolution resolution, unsigned int levelOfDetail)
    : PyDbGeoMap(new AcDbGeoMap(mapType, resolution, levelOfDetail), true)
{
}

#if defined(_BRXTARGET250)
//Not in BRX
#else
PyDbGeoMap::PyDbGeoMap(const PyDbObjectId& viewportId, bool isViewportSpecific)
    : PyDbGeoMap(new AcDbGeoMap(viewportId.m_id, isViewportSpecific), true)
{
}
#endif

PyDbGeoMap::PyDbGeoMap(AcDbGeoMap* ptr, bool autoDelete)
    : PyDbRasterImage(ptr, autoDelete)
{
}

PyDbGeoMap::PyDbGeoMap(const PyDbObjectId& id)
    : PyDbGeoMap(openAcDbObject<AcDbGeoMap>(id, AcDb::kForRead), false)
{
}

PyDbGeoMap::PyDbGeoMap(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbGeoMap(openAcDbObject<AcDbGeoMap>(id, mode), false)
{
}

PyDbGeoMap::PyDbGeoMap(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbGeoMap(openAcDbObject<AcDbGeoMap>(id, mode, erased), false)
{
}

AcGePoint3d PyDbGeoMap::bottomLeftPt() const
{
    return impObj()->bottomLeftPt();
}

double PyDbGeoMap::height() const
{
    return impObj()->height();
}

double PyDbGeoMap::width() const
{
    return impObj()->width();
}

AcGePoint3d PyDbGeoMap::imageBottomLeftPt() const
{
    return impObj()->imageBottomLeftPt();
}

double PyDbGeoMap::imageHeight() const
{
    return impObj()->imageHeight();
}

double PyDbGeoMap::imageWidth() const
{
    return impObj()->imageWidth();
}

AcGeoMapResolution PyDbGeoMap::resolution() const
{
    return impObj()->resolution();
}

void PyDbGeoMap::setResolution(AcGeoMapResolution resolution) const
{
    PyThrowBadEs(impObj()->setResolution(resolution));
}

unsigned int PyDbGeoMap::LOD() const
{
    return impObj()->LOD();
}

AcGeoMapType PyDbGeoMap::mapType() const
{
    return impObj()->mapType();
}

void PyDbGeoMap::setMapType(AcGeoMapType mapType) const
{
    PyThrowBadEs(impObj()->setMapType(mapType));
}

Adesk::Boolean PyDbGeoMap::isOutOfDate() const
{
    return impObj()->isOutOfDate();
}

Adesk::Boolean PyDbGeoMap::updateMapImage1() const
{
    return impObj()->updateMapImage();
}

Adesk::Boolean PyDbGeoMap::updateMapImage2(Adesk::Boolean bReset) const
{
    return impObj()->updateMapImage(bReset);
}

std::string PyDbGeoMap::className()
{
    return "AcDbGeoMap";
}

PyRxClass PyDbGeoMap::desc()
{
    return PyRxClass(AcDbGeoMap::desc(), false);
}

PyDbGeoMap PyDbGeoMap::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbGeoMap, AcDbGeoMap>(src);
}

PyDbGeoMap PyDbGeoMap::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbGeoMap>(src);
}

AcDbGeoMap* PyDbGeoMap::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbGeoMap*>(m_pyImp.get());
}
