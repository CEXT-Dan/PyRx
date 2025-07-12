#pragma once
#include "PyDbEntity.h"
#include "AcDbGeoTypes.h"

#pragma pack (push, 8)
class PyDbObjectId;
class PyDbDictionary;


#include "dbwipe.h"
#include "AcDbGeoMap.h"


//-----------------------------------------------------------------------------------
//PyDbImage
void makePyDbImageWrapper();
class PyDbImage : public PyDbEntity
{
public:
    PyDbImage(AcDbImage* ptr, bool autoDelete);
    PyDbImage(const PyDbObjectId& id);
    PyDbImage(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbImage(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    virtual ~PyDbImage() override = default;

public:
    static std::string  className();
    static PyRxClass    desc();
    static PyDbImage	cloneFrom(const PyRxObject& src);
    static PyDbImage    cast(const PyRxObject& src);
public:
    AcDbImage* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyDbRasterImageDef
void makePyDbRasterImageDefWrapper();

class PyDbRasterImageDef : public PyDbObject
{
public:
    PyDbRasterImageDef();
    PyDbRasterImageDef(AcDbRasterImageDef* ptr, bool autoDelete);
    PyDbRasterImageDef(const PyDbObjectId& id);
    PyDbRasterImageDef(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbRasterImageDef(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    virtual ~PyDbRasterImageDef() override = default;
    void                setSourceFileName(const std::string& pPathName) const;
    void                setActiveFileName(const std::string& pPathName) const;
    std::string         searchForActivePath() const;
    std::string         sourceFileName() const;
    std::string         activeFileName() const;
    void                embed() const;
    Adesk::Boolean      isEmbedded() const;
    void                load() const;
    void                unload1() const;
    void                unload2(Adesk::Boolean modifyDatabase) const;
    Adesk::Boolean      isLoaded() const;
    AcGeVector2d        size() const;
    std::string         fileType() const;
    int                 entityCount() const;
    void                updateEntities() const;
    void                setResolutionMMPerPixel(const AcGeVector2d& resMMPerPixel) const;
    AcGeVector2d        resolutionMMPerPixel() const;
    void                setResolutionUnits(AcDbRasterImageDef::Units units) const;
    AcDbRasterImageDef::Units resolutionUnits() const;
    static PyDbObjectId createImageDictionary(PyDbDatabase& pDb);
    static PyDbObjectId imageDictionary(PyDbDatabase& pDb);
    static std::string  suggestName(PyDbDictionary& dict, const std::string& pPathName);
public:
    static std::string  className();
    static PyRxClass    desc();
    static PyDbRasterImageDef   cloneFrom(const PyRxObject& src);
    static PyDbRasterImageDef   cast(const PyRxObject& src);
public:
    AcDbRasterImageDef* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyDbRasterImageDefReactor
void makePyDbRasterImageDefReactorWrapper();
class PyDbRasterImageDefReactor : public PyDbObject
{
public:
    PyDbRasterImageDefReactor();
    PyDbRasterImageDefReactor(AcDbRasterImageDefReactor* ptr, bool autoDelete);
    PyDbRasterImageDefReactor(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbRasterImageDefReactor(const PyDbObjectId& id);
    virtual ~PyDbRasterImageDefReactor() override = default;

    static void         setEnable(Adesk::Boolean enable);
public:
    static std::string  className();
    static PyRxClass    desc();
    static PyDbRasterImageDefReactor	cloneFrom(const PyRxObject& src);
    static PyDbRasterImageDefReactor    cast(const PyRxObject& src);
public:
    AcDbRasterImageDefReactor* impObj(const std::source_location& src = std::source_location::current()) const;
};


//-----------------------------------------------------------------------------------
//AcDbRasterImage
void makePyDbRasterImageWrapper();

class PyDbRasterImage : public PyDbImage
{
public:
    PyDbRasterImage();
    PyDbRasterImage(AcDbRasterImage* ptr, bool autoDelete);
    PyDbRasterImage(const PyDbObjectId& id);
    PyDbRasterImage(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbRasterImage() override = default;
    void                setImageDefId(const PyDbObjectId& imageId) const;
    PyDbObjectId        imageDefId() const;
    void                setReactorId(const PyDbObjectId& reactorId) const;
    PyDbObjectId        reactorId() const;
    Adesk::Boolean      setOrientation(const AcGePoint3d& origin, const AcGeVector3d& uCorner, const AcGeVector3d& vOnPlane) const;
    boost::python::tuple getOrientation() const;
    AcGeVector2d        scale() const;
    AcGeVector2d        imageSize1() const;
    AcGeVector2d        imageSize2(Adesk::Boolean bGetCachedValue) const;
    void                setClipBoundaryToWholeImage(AcGeVector2d& size) const;
    boost::python::list clipBoundary() const;
    AcDbRasterImage::ClipBoundaryType  clipBoundaryType() const;
    Adesk::Boolean      isClipped() const;
    boost::python::list getVertices() const;
    AcGeMatrix3d        getPixelToModelTransform() const;
    void                setDisplayOpt(AcDbRasterImage::ImageDisplayOpt option, Adesk::Boolean bValue) const;
    Adesk::Boolean      isSetDisplayOpt(AcDbRasterImage::ImageDisplayOpt option) const;
    void                setBrightness(Adesk::Int8 value) const;
    Adesk::Int8         brightness() const;
    void                setContrast(Adesk::Int8 value) const;
    Adesk::Int8         contrast() const;
    void                setFade(Adesk::Int8 value) const;
    Adesk::Int8         fade() const;
    Adesk::Boolean      isClipInverted() const;
    void                setClipInverted(Adesk::Boolean newVal) const;
    double              width() const;
    double              height() const;
    double              imageHeight() const;
    double              imageWidth() const;
    void                setHeight(double val) const;
    void                setWidth(double val) const;
    AcGePoint3d         position() const;
    double              rotation() const;
    void                setRotation(double rotation) const;
    bool                isImageShown() const;
    void                setShowImage(bool value) const;
    bool                isImageTransparent() const;
    void                setImageTransparency(bool value) const;
    bool                isShownClipped() const;
    void                setShowClipped(bool value) const;
public:
    static std::string  className();
    static PyRxClass    desc();
    static PyDbRasterImage	  cloneFrom(const PyRxObject& src);
    static PyDbRasterImage    cast(const PyRxObject& src);
public:
    AcDbRasterImage* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyDbWipeout
void makePyDbWipeoutWrapper();

class PyDbWipeout : public PyDbRasterImage
{
public:
    PyDbWipeout();
    PyDbWipeout(const boost::python::list& pylist, const AcGeVector3d& vec);
    PyDbWipeout(AcDbWipeout* ptr, bool autoDelete);
    PyDbWipeout(const PyDbObjectId& id);
    PyDbWipeout(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbWipeout(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    virtual ~PyDbWipeout() override = default;


    Adesk::Boolean  frame() const;
    void            setFrom(const boost::python::list& pylist, const AcGeVector3d& vec) const;

public:
    static std::string  className();
    static PyRxClass    desc();
    static PyDbWipeout  cloneFrom(const PyRxObject& src);
    static PyDbWipeout  cast(const PyRxObject& src);
public:
    AcDbWipeout* impObj(const std::source_location& src = std::source_location::current()) const;
};


//-----------------------------------------------------------------------------------
//PyDbGeoMap
void makePyDbGeoMapWrapper();

class PyDbGeoMap : public PyDbRasterImage
{
public:
    PyDbGeoMap(AcGeoMapType mapType, AcGeoMapResolution resolution, unsigned int levelOfDetail);
#if defined(_BRXTARGET260)
    //Not in BRX
#else
    PyDbGeoMap(const PyDbObjectId& viewportId, bool isViewportSpecific);
#endif
    PyDbGeoMap(AcDbGeoMap* ptr, bool autoDelete);
    PyDbGeoMap(const PyDbObjectId& id);
    PyDbGeoMap(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbGeoMap(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    virtual ~PyDbGeoMap() override = default;

    AcGePoint3d			bottomLeftPt() const;
    double				height() const;
    double				width() const;
    AcGePoint3d			imageBottomLeftPt() const;
    double				imageHeight() const;
    double				imageWidth() const;
    AcGeoMapResolution	resolution() const;
    void			    setResolution(AcGeoMapResolution resolution) const;
    unsigned int		LOD() const;
    AcGeoMapType		mapType() const;
    void			    setMapType(AcGeoMapType mapType) const;
    Adesk::Boolean		isOutOfDate() const;
    Adesk::Boolean		updateMapImage1() const;
    Adesk::Boolean		updateMapImage2(Adesk::Boolean bReset) const;

public:
    static std::string  className();
    static PyRxClass    desc();
    static PyDbGeoMap   cloneFrom(const PyRxObject& src);
    static PyDbGeoMap   cast(const PyRxObject& src);
public:
    AcDbGeoMap* impObj(const std::source_location& src = std::source_location::current()) const;
};
#pragma pack (pop)