#pragma once
#include "PyDbEntity.h"

class PyDbObjectId;
class PyDbDictionary;

//-----------------------------------------------------------------------------------
//PyDbImage
void makePyDbImageWrapper();
class PyDbImage : public PyDbEntity
{
public:
    PyDbImage(AcDbImage* ptr, bool autoDelete);
    PyDbImage(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbImage() override = default;
    
public:
    static std::string  className();
    static PyRxClass    desc();
    static PyDbImage	cloneFrom(const PyRxObject & src);
    static PyDbImage    cast(const PyRxObject & src);
public:
    AcDbImage* impObj(const std::source_location & src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyDbRasterImageDef
void makePyDbRasterImageDefWrapper();

class PyDbRasterImageDef : public PyDbObject
{
public:
    PyDbRasterImageDef();
    PyDbRasterImageDef(AcDbRasterImageDef* ptr, bool autoDelete);
    PyDbRasterImageDef(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbRasterImageDef() override = default;
    Acad::ErrorStatus   setSourceFileName(const std::string& pPathName);
    Acad::ErrorStatus   setActiveFileName(const std::string& pPathName);
    std::string         searchForActivePath();
    std::string         sourceFileName() const;
    std::string         activeFileName() const;
    Acad::ErrorStatus   embed();
    Adesk::Boolean      isEmbedded() const;
    Acad::ErrorStatus   load();
    Acad::ErrorStatus   unload1();
    Acad::ErrorStatus   unload2(Adesk::Boolean modifyDatabase);
    Adesk::Boolean      isLoaded() const;
    AcGeVector2d        size() const;
    std::string         fileType() const;
    int                 entityCount() const;
    void                updateEntities() const;
    Acad::ErrorStatus   setResolutionMMPerPixel(const AcGeVector2d& resMMPerPixel);
    AcGeVector2d        resolutionMMPerPixel() const;
    void                setResolutionUnits(AcDbRasterImageDef::Units units);
    AcDbRasterImageDef::Units resolutionUnits() const;
    static PyDbObjectId createImageDictionary(PyDbDatabase& pDb);
    static PyDbObjectId imageDictionary(PyDbDatabase& pDb);
    static std::string  suggestName(PyDbDictionary& dict, const std::string& pPathName);
public:
    static std::string  className();
    static PyRxClass    desc();
    static PyDbRasterImageDef   cloneFrom(const PyRxObject & src);
    static PyDbRasterImageDef   cast(const PyRxObject & src);
public:
    AcDbRasterImageDef* impObj(const std::source_location & src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//AcDbRasterImage
void makePyDbRasterImageWrapper();

class PyDbRasterImage : public PyDbImage
{
public:
    PyDbRasterImage();
    PyDbRasterImage(AcDbRasterImage* ptr, bool autoDelete);
    PyDbRasterImage(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbRasterImage() override = default;
    Acad::ErrorStatus   setImageDefId(const PyDbObjectId& imageId);
    PyDbObjectId        imageDefId() const;
    void                setReactorId(const PyDbObjectId& reactorId);
    PyDbObjectId        reactorId() const;
    Adesk::Boolean      setOrientation(const AcGePoint3d& origin,const AcGeVector3d& uCorner, const AcGeVector3d& vOnPlane);
    void                getOrientation(AcGePoint3d& origin, AcGeVector3d& u, AcGeVector3d& v) const;
    AcGeVector2d        scale() const;
    AcGeVector2d        imageSize1() const;
    AcGeVector2d        imageSize2(Adesk::Boolean bGetCachedValue) const;
    Acad::ErrorStatus   setClipBoundaryToWholeImage(AcGeVector2d& size);
    boost::python::list clipBoundary() const;
    AcDbRasterImage::ClipBoundaryType  clipBoundaryType() const;
    Adesk::Boolean      isClipped() const;
    boost::python::list getVertices() const;
    AcGeMatrix3d        getPixelToModelTransform() const;
    void                setDisplayOpt(AcDbRasterImage::ImageDisplayOpt option, Adesk::Boolean bValue);
    Adesk::Boolean      isSetDisplayOpt(AcDbRasterImage::ImageDisplayOpt option) const;
    Acad::ErrorStatus   setBrightness(Adesk::Int8 value);
    Adesk::Int8         brightness() const;
    Acad::ErrorStatus   setContrast(Adesk::Int8 value);
    Adesk::Int8         contrast() const;
    Acad::ErrorStatus   setFade(Adesk::Int8 value);
    Adesk::Int8         fade() const;
    Adesk::Boolean      isClipInverted() const;
    void                setClipInverted(Adesk::Boolean newVal);
    double              width() const;
    double              height() const;
    double              imageHeight() const;
    double              imageWidth() const;
    Acad::ErrorStatus   setHeight(double val);
    Acad::ErrorStatus   setWidth(double val);
    AcGePoint3d         position() const;
    double              rotation() const;
    Acad::ErrorStatus   setRotation(double rotation);
    bool                isImageShown() const;
    void                setShowImage(bool value);
    bool                isImageTransparent() const;
    void                setImageTransparency(bool value);
    bool                isShownClipped() const;
    void                setShowClipped(bool value);
public:
    static std::string  className();
    static PyRxClass    desc();
    static PyDbRasterImage	  cloneFrom(const PyRxObject & src);
    static PyDbRasterImage    cast(const PyRxObject & src);
public:
    AcDbRasterImage* impObj(const std::source_location & src = std::source_location::current()) const;
};

