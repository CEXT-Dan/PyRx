#pragma once

#if !defined(_BRXTARGET240)

#include "PyDbObject.h"
#include "PyDbEntity.h"

#include "AcPointCloud.h"
#include "AcDbPointCloudColorMap.h"
#include "AcDbPointCloudEx.h"
#include "AcDbPointCloudDefEx.h"


class PyRxObject;
class PyDbObjectId;
class PyDbDatabase;

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
    void                        setColor(int c, const AcCmEntityColor& color);
    bool                        visibility(int c) const;
    void                        setVisibility(int c, bool visibility);
    void                        setFrom(const PyDbPointCloudClassificationColorRamp& source);
    std::string                 name() const;
    void                        setName(const  std::string& name);

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
    void                        setNumColors(Adesk::Int32 count);
    AcCmEntityColor             color(int c) const;
    void                        setColor(int c, const AcCmEntityColor& color);
    bool                        visibility(int c) const;
    void                        setVisibility(int c, bool visibility);
    void                        setFrom(const PyDbPointCloudColorRamp& source);
    std::string                 name() const;
    void                        setName(const  std::string& name);

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
    bool                        setDefaultIntensityColorScheme(const std::string& GUID);
    std::string                 defaultElevationColorScheme() const;
    bool                        setDefaultElevationColorScheme(const std::string& GUID);
    std::string                 defaultClassificationColorScheme() const;
    bool                        setDefaultClassificationColorScheme(const std::string& GUID);
    boost::python::list         colorSchemeGUIDs() const;
    bool                        hasColorScheme(const std::string& GUID) const;
    bool                        deleteColorScheme(const std::string& GUID);
    boost::python::list         classificationSchemeGUIDs() const;
    bool                        hasClassificationScheme(const std::string& GUID) const;
    bool                        deleteClassificationScheme(const std::string& GUID);
    boost::python::list         getColorSchemeInUse() const;
    boost::python::list         getClassificationColorSchemeInUse() const;

    boost::python::tuple        colorScheme(const std::string& GUID);
    bool                        setColorScheme(const std::string& GUID, const PyDbPointCloudColorRamp& source);

    boost::python::tuple        classificationScheme(const std::string& GUID);
    bool                        setClassificationScheme(const std::string& GUID, const PyDbPointCloudClassificationColorRamp& source);

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

    void                        load();
    void                        unload();
    Adesk::Boolean              isLoaded() const;
    boost::python::tuple        entityCount() const;
    void                        setSourceFileName(const std::string& pPathName);
    std::string                 sourceFileName() const;
    void                        setActiveFileName(const std::string& pPathName);
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

    void                        setPointCloudDefExId(const PyDbObjectId& defExId);
    PyDbObjectId                pointCloudDefExId() const;
    void                        setReactorId(const PyDbObjectId& reactorId);
    PyDbObjectId                reactorId() const;
    bool                        locked()const;
    void                        setLocked(bool locked);
    double                      scale() const;
    void                        setScale(double val);
    double                      rotation() const;
    void                        setRotation(double val);
    AcGePoint3d                 location() const;
    void                        setLocation(const AcGePoint3d& pt);
    AcDbExtents                 getNativeCloudExtent() const;
    unsigned int                getVisiblePointCount() const;
    unsigned int                getLoadedVisiblePointCount() const;
    unsigned int                getDisplayedVisiblePointCount() const;
    bool                        setActiveFileName(const std::string& strActiveFileName);
    boost::python::tuple        getActiveFileName() const;
    std::string                 getPointCloudName() const;
    void                        setPointCloudName(const std::string& name);
    int                         getCroppingCount() const;

    //AcDbPointCloudCrop*       getPointCloudCropping(int index);
    //const AcDbPointCloudCrop* getPointCloudCroppingConst(int index) const;
    //void                      addCroppingBoundary(const AcDbPointCloudCrop& cropping);

    void                        clearCropping();
    void                        removeLastCropping();
    bool                        getCroppingInvert() const;
    void                        setCroppingInvert(bool invert);
    void                        setInCreatingCroppingMode(bool  bCreating);
    bool                        showCropped() const;
    void                        setStylizationType(AcDbPointCloudEx::StylizationType type);
    AcDbPointCloudEx::StylizationType stylizationType() const;
    std::string                 getCurrentColorScheme() const;
    void                        setCurrentColorScheme(const std::string& guid);
    std::string                 getColorSchemeForStylization(AcDbPointCloudEx::StylizationType type) const;
    void                        setColorSchemeForStylization(const std::string& guid, AcDbPointCloudEx::StylizationType type);
    bool                        showIntensityAsGradient() const;
    void                        setShowIntensityAsGradient(bool b);
    Adesk::Int32                minIntensity() const;
    Adesk::Int32                maxIntensity() const;
    void                        setMinMaxIntensity(int min, int max);
    AcDbPointCloudEx::DispOptionOutOfRange intensityOutOfRangeBehavior() const;
    void                        setIntensityOutOfRangeBehavior(AcDbPointCloudEx::DispOptionOutOfRange dispOp);
    bool                        showElevationAsGradient() const;
    void                        setShowElevationAsGradient(bool b);
    double                      minElevation() const;
    double                      maxElevation() const;
    void                        setMinMaxElevation(double min, double max);
    bool                        elevationApplyToFixedRange() const;
    void                        setElevationApplyToFixedRange(bool val);
    AcDbPointCloudEx::DispOptionOutOfRange elevationOutOfRangeBehavior() const;
    void                        setElevationOutOfRangeBehavior(AcDbPointCloudEx::DispOptionOutOfRange dispOp);

    //void                      getLimitBox(AcDbPointCloudExLimitBox& limitBox) const;
    //Acad::ErrorStatus         setLimitBox(const AcDbPointCloudExLimitBox& limitBox);

    void                        resetLimitBox();
    void                        setHighlightLimitboxBoundary(bool val);

    //const AcPointCloudItemArray* getPointCloudDataList() const;
    //AcPointCloudItem* findScanItem(const AcString& scanGuid);
    //AcPointCloudItem* findRegionItem(int regionId);

    void                        setScanVisibility(const std::string& scanGuid, bool bVisible);
    void                        setAllScansVisibility(bool bVisible);
    void                        setRegionVisibility(int regionId, bool bVisible);
    void                        setAllRegionsVisibility1(bool bVisible);
    void                        setAllRegionsVisibility2(bool bVisible, bool includeUnassigned);
    void                        setAllScansVisibilityByRegion(int regionId, bool bVisible);
    boost::python::tuple        getScanViewInfo(const std::string& scanGuid) const;
    void                        resetScanRegionVisibility();
    void                        setAllScanHighlight(bool bHighlight);
    void                        setAllRegionHighlight1(bool bHighlight);
    void                        setAllRegionHighlight2(bool bHighlight, bool bIncludeUnassignedPoints);
    void                        applyGeoLocation1();
    void                        applyGeoLocation2(bool useDrawingGeo, const std::string& geoCS);
    void                        updateGeoLocation();
    bool                        geolocate() const;


    void                        clearSpatialFilters();
    void                        clearAttributeFilters();

    boost::python::tuple        getPlaneOrPointAt(const AcGeMatrix3d& viewXform, const AcGePoint3d& pickPt);
    boost::python::tuple        getPlaneBoundaryAt(const AcGeMatrix3d& viewXform, const AcGePoint3d& pickPt);
    AcGeMatrix3d                objectToWorldMatrix() const;
    boost::python::tuple        getCandidatePlane(int x, int y) const;
    boost::python::tuple        getCylinderAt(const AcGeMatrix3d& viewXform, const AcGePoint3d& pickPt);

    //const AcDbPointCloudCropStateManager* cropStatesManagerConst() const;
    //AcDbPointCloudCropStateManager* cropStatesManager();

    double                      getMinDistPrecision() const;
    boost::python::tuple        detectPointBelonger(const AcGePoint3d& ptInWCS) const;

    boost::python::list         getCustomOsnapInfo(AcDbPointCloudEx::PointCloudOSnapMode snapMode, const AcGePoint3d& pickPoint, const AcGePoint3d& lastPoint, const AcGeMatrix3d& viewXform);


    static PyDbObjectId         attachPointCloud(const std::string& pointCloudFile, AcGePoint3d& location, double scale, double rotation, PyDbDatabase& pDb);
    static std::string          className();
    static PyRxClass            desc();
    static PyDbPointCloudEx     cloneFrom(const PyRxObject& src);
    static PyDbPointCloudEx     cast(const PyRxObject& src);
public:
    inline AcDbPointCloudEx* impObj(const std::source_location& src = std::source_location::current()) const;
};

#endif