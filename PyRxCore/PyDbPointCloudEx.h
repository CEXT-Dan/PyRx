#pragma once

#if !defined(_BRXTARGET260)

#include "PyDbObject.h"
#include "PyDbEntity.h"

#include "AcPointCloud.h"
#include "AcDbPointCloudColorMap.h"
#include "AcDbPointCloudEx.h"
#include "AcDbPointCloudDefEx.h"
#include "AcDbPointCloudCrop.h"

#pragma pack (push, 8)
class PyRxObject;
class PyDbObjectId;
class PyDbDatabase;

//-----------------------------------------------------------------------------------
//PyDbPointCloudCrop
void makePyDbPointCloudCropWrapper();
class PyDbPointCloudCrop
{
public:
    PyDbPointCloudCrop();
    PyDbPointCloudCrop(const AcDbPointCloudCrop& other);
    ~PyDbPointCloudCrop() = default;
    void                        clear() const;
    bool                        isValid() const;
    AcDbPointCloudCrop::CropType type() const;
    void                         setCropType(AcDbPointCloudCrop::CropType type) const;
    bool                        isInside() const;
    void                        setInside(bool bInside) const;
    bool                        isInverted() const;
    void                        setInvert(bool toInvert) const;
    boost::python::tuple        getCropPlane() const;
    void                        setCropPlane(const PyGePlane& plane) const;
    int                         length() const;
    void                        set(const boost::python::list& points) const;
    boost::python::list         get() const;
public:
    static std::string          className();
public:
    AcDbPointCloudCrop* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<AcDbPointCloudCrop > m_pyImp;
};

//-----------------------------------------------------------------------------------
//PyDbPointCloudColorRamp
void makePyDbPointCloudClassificationColorRampWrapper();
class PyDbPointCloudClassificationColorRamp
{
public:
    PyDbPointCloudClassificationColorRamp();
    ~PyDbPointCloudClassificationColorRamp() = default;

    Adesk::Int32                numColors() const;
    AcCmEntityColor             color(int c) const;
    void                        setColor(int c, const AcCmEntityColor& color) const;
    bool                        visibility(int c) const;
    void                        setVisibility(int c, bool visibility) const;
    void                        setFrom(const PyDbPointCloudClassificationColorRamp& source) const;
    std::string                 name() const;
    void                        setName(const  std::string& name) const;

public:
    static std::string          className();
public:
    AcDbPointCloudClassificationColorRamp* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<AcDbPointCloudClassificationColorRamp> m_pyImp;
};


//-----------------------------------------------------------------------------------
//PyDbPointCloudColorRamp
void makePyDbPointCloudColorRampWrapper();
class PyDbPointCloudColorRamp
{
public:
    PyDbPointCloudColorRamp();
    ~PyDbPointCloudColorRamp() = default;

    Adesk::Int32                numColors() const;
    void                        setNumColors(Adesk::Int32 count) const;
    AcCmEntityColor             color(int c) const;
    void                        setColor(int c, const AcCmEntityColor& color) const;
    bool                        visibility(int c) const;
    void                        setVisibility(int c, bool visibility) const;
    void                        setFrom(const PyDbPointCloudColorRamp& source) const;
    std::string                 name() const;
    void                        setName(const  std::string& name) const;

public:
    static std::string          className();
public:
    AcDbPointCloudColorRamp*    impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<AcDbPointCloudColorRamp> m_pyImp;
};

//-----------------------------------------------------------------------------------
//PyDbPointCloudColorMap
void makePyDbPointCloudColorMapWrapper();

class PyDbPointCloudColorMap : public PyDbObject
{
public:
    PyDbPointCloudColorMap(const PyDbObjectId& id);
    PyDbPointCloudColorMap(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbPointCloudColorMap(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    PyDbPointCloudColorMap(AcDbPointCloudColorMap* ptr, bool autoDelete);
    virtual ~PyDbPointCloudColorMap() override = default;

    std::string                 defaultIntensityColorScheme() const;
    bool                        setDefaultIntensityColorScheme(const std::string& GUID) const;
    std::string                 defaultElevationColorScheme() const;
    bool                        setDefaultElevationColorScheme(const std::string& GUID) const;
    std::string                 defaultClassificationColorScheme() const;
    bool                        setDefaultClassificationColorScheme(const std::string& GUID) const;
    boost::python::list         colorSchemeGUIDs() const;
    bool                        hasColorScheme(const std::string& GUID) const;
    bool                        deleteColorScheme(const std::string& GUID) const;
    boost::python::list         classificationSchemeGUIDs() const;
    bool                        hasClassificationScheme(const std::string& GUID) const;
    bool                        deleteClassificationScheme(const std::string& GUID) const;
    boost::python::list         getColorSchemeInUse() const;
    boost::python::list         getClassificationColorSchemeInUse() const;

    boost::python::tuple        colorScheme(const std::string& GUID) const;
    bool                        setColorScheme(const std::string& GUID, const PyDbPointCloudColorRamp& source) const;

    boost::python::tuple        classificationScheme(const std::string& GUID) const;
    bool                        setClassificationScheme(const std::string& GUID, const PyDbPointCloudClassificationColorRamp& source) const;

    static PyDbObjectId         getColorMap(PyDbDatabase& pDb);
public:
    static std::string          className();
    static PyRxClass            desc();
    static PyDbPointCloudColorMap  cloneFrom(const PyRxObject& src);
    static PyDbPointCloudColorMap  cast(const PyRxObject& src);
public:
    AcDbPointCloudColorMap* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyDbPointCloudDefEx
void makePyDbPointCloudDefExWrapper();

class PyDbPointCloudDefEx : public PyDbObject
{
public:
    PyDbPointCloudDefEx();
    PyDbPointCloudDefEx(const PyDbObjectId& id);
    PyDbPointCloudDefEx(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbPointCloudDefEx(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    PyDbPointCloudDefEx(AcDbPointCloudDefEx* ptr, bool autoDelete);
    virtual ~PyDbPointCloudDefEx() override = default;

    void                        load() const;
    void                        unload() const;
    Adesk::Boolean              isLoaded() const;
    boost::python::tuple        entityCount() const;
    void                        setSourceFileName(const std::string& pPathName) const;
    std::string                 sourceFileName() const;
    void                        setActiveFileName(const std::string& pPathName) const;
    std::string                 activeFileName() const;
    std::string                 fileType() const;
    unsigned long long          totalPointsCount() const;
    int                         totalRegionsCount() const;
    int                         totalScansCount() const;
    double                      defaultWidth() const;
    double                      defaultLength() const;
    double                      defaultHeight() const;
    AcDbPointCloudDefEx::PropState hasProperty(AcDbPointCloudDefEx::Property prop) const;
    AcDbExtents                 extents() const;
    std::string                 coordinateSystemName() const;
    std::string                 getRcsFilePath(const std::string& guid) const;
    boost::python::list         getAllRcsFilePaths() const;

    static PyDbObjectId         pointCloudExDictionary(PyDbDatabase& pDb);
    static void                 createPointCloudExDictionary(PyDbDatabase& pDb, PyDbObjectId& dictId);
    static int                  classVersion();

public:
    static std::string          className();
    static PyRxClass            desc();
    static PyDbPointCloudDefEx  cloneFrom(const PyRxObject& src);
    static PyDbPointCloudDefEx  cast(const PyRxObject& src);
public:
    AcDbPointCloudDefEx* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyDbPointCloudEx
void makePyDbPointCloudExWrapper();

class PyDbPointCloudEx : public PyDbEntity
{
public:
    PyDbPointCloudEx();
    PyDbPointCloudEx(const PyDbObjectId& id);
    PyDbPointCloudEx(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbPointCloudEx(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    PyDbPointCloudEx(AcDbPointCloudEx* ptr, bool autoDelete);
    virtual ~PyDbPointCloudEx() override = default;

    void                        setPointCloudDefExId(const PyDbObjectId& defExId) const;
    PyDbObjectId                pointCloudDefExId() const;
    void                        setReactorId(const PyDbObjectId& reactorId) const;
    PyDbObjectId                reactorId() const;
    bool                        locked()const;
    void                        setLocked(bool locked) const;
    double                      scale() const;
    void                        setScale(double val) const;
    double                      rotation() const;
    void                        setRotation(double val) const;
    AcGePoint3d                 location() const;
    void                        setLocation(const AcGePoint3d& pt) const;
    AcDbExtents                 getNativeCloudExtent() const;
    unsigned int                getVisiblePointCount() const;
    unsigned int                getLoadedVisiblePointCount() const;
    unsigned int                getDisplayedVisiblePointCount() const;
    bool                        setActiveFileName(const std::string& strActiveFileName) const;
    boost::python::tuple        getActiveFileName() const;
    std::string                 getPointCloudName() const;
    void                        setPointCloudName(const std::string& name) const;
    int                         getCroppingCount() const;

    PyDbPointCloudCrop          getPointCloudCropping(int index) const;
    void                        addCroppingBoundary(const PyDbPointCloudCrop& cropping) const;

    void                        clearCropping() const;
    void                        removeLastCropping() const;
    bool                        getCroppingInvert() const;
    void                        setCroppingInvert(bool invert) const;
    void                        setInCreatingCroppingMode(bool  bCreating) const;
    bool                        showCropped() const;
    void                        setStylizationType(AcDbPointCloudEx::StylizationType type) const;
    AcDbPointCloudEx::StylizationType stylizationType() const;
    std::string                 getCurrentColorScheme() const;
    void                        setCurrentColorScheme(const std::string& guid) const;
    std::string                 getColorSchemeForStylization(AcDbPointCloudEx::StylizationType type) const;
    void                        setColorSchemeForStylization(const std::string& guid, AcDbPointCloudEx::StylizationType type) const;
    bool                        showIntensityAsGradient() const;
    void                        setShowIntensityAsGradient(bool b) const;
    Adesk::Int32                minIntensity() const;
    Adesk::Int32                maxIntensity() const;
    void                        setMinMaxIntensity(int min, int max) const;
    AcDbPointCloudEx::DispOptionOutOfRange intensityOutOfRangeBehavior() const;
    void                        setIntensityOutOfRangeBehavior(AcDbPointCloudEx::DispOptionOutOfRange dispOp) const;
    bool                        showElevationAsGradient() const;
    void                        setShowElevationAsGradient(bool b) const;
    double                      minElevation() const;
    double                      maxElevation() const;
    void                        setMinMaxElevation(double min, double max) const;
    bool                        elevationApplyToFixedRange() const;
    void                        setElevationApplyToFixedRange(bool val) const;
    AcDbPointCloudEx::DispOptionOutOfRange elevationOutOfRangeBehavior() const;
    void                        setElevationOutOfRangeBehavior(AcDbPointCloudEx::DispOptionOutOfRange dispOp) const;

    //void                      getLimitBox(AcDbPointCloudExLimitBox& limitBox) const;
    //Acad::ErrorStatus         setLimitBox(const AcDbPointCloudExLimitBox& limitBox) const;

    void                        resetLimitBox() const;
    void                        setHighlightLimitboxBoundary(bool val) const;

    //const AcPointCloudItemArray* getPointCloudDataList() const;
    //AcPointCloudItem* findScanItem(const AcString& scanGuid) const;
    //AcPointCloudItem* findRegionItem(int regionId) const;

    void                        setScanVisibility(const std::string& scanGuid, bool bVisible) const;
    void                        setAllScansVisibility(bool bVisible) const;
    void                        setRegionVisibility(int regionId, bool bVisible) const;
    void                        setAllRegionsVisibility1(bool bVisible) const;
    void                        setAllRegionsVisibility2(bool bVisible, bool includeUnassigned) const;
    void                        setAllScansVisibilityByRegion(int regionId, bool bVisible) const;
    boost::python::tuple        getScanViewInfo(const std::string& scanGuid) const;
    void                        resetScanRegionVisibility() const;
    void                        setAllScanHighlight(bool bHighlight) const;
    void                        setAllRegionHighlight1(bool bHighlight) const;
    void                        setAllRegionHighlight2(bool bHighlight, bool bIncludeUnassignedPoints) const;
    void                        applyGeoLocation1() const;
    void                        applyGeoLocation2(bool useDrawingGeo, const std::string& geoCS) const;
    void                        updateGeoLocation() const;
    bool                        geolocate() const;


    void                        clearSpatialFilters() const;
    void                        clearAttributeFilters() const;

    boost::python::tuple        getPlaneOrPointAt(const AcGeMatrix3d& viewXform, const AcGePoint3d& pickPt) const;
    boost::python::tuple        getPlaneBoundaryAt(const AcGeMatrix3d& viewXform, const AcGePoint3d& pickPt) const;
    AcGeMatrix3d                objectToWorldMatrix() const;
    boost::python::tuple        getCandidatePlane(int x, int y) const;
    boost::python::tuple        getCylinderAt(const AcGeMatrix3d& viewXform, const AcGePoint3d& pickPt) const;

    //const AcDbPointCloudCropStateManager* cropStatesManagerConst() const;
    //AcDbPointCloudCropStateManager* cropStatesManager() const;

    double                      getMinDistPrecision() const;
    boost::python::tuple        detectPointBelonger(const AcGePoint3d& ptInWCS) const;

    boost::python::list         getCustomOsnapInfo(AcDbPointCloudEx::PointCloudOSnapMode snapMode, const AcGePoint3d& pickPoint, const AcGePoint3d& lastPoint, const AcGeMatrix3d& viewXform) const;


    static PyDbObjectId         attachPointCloud(const std::string& pointCloudFile, AcGePoint3d& location, double scale, double rotation, PyDbDatabase& pDb);
    static std::string          className();
    static PyRxClass            desc();
    static PyDbPointCloudEx     cloneFrom(const PyRxObject& src);
    static PyDbPointCloudEx     cast(const PyRxObject& src);
public:
    inline AcDbPointCloudEx* impObj(const std::source_location& src = std::source_location::current()) const;
};

#endif

#pragma pack (pop)
