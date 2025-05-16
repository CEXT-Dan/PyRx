#pragma once
#include "PyDbEntity.h"
#include "dbGeoData.h"
#include "AcDbGeoPositionMarker.h"
#include "AcDbGeoCoordinateSystem.h"

#pragma pack (push, 8)
class PyDbMText;
class PyDbObjectId;

//----------------------------------------------------------------------------------------
//PyDbGeoData
void makePyDbGeoDataWrapper();

class PyDbGeoData : public PyDbObject
{
public:
    PyDbGeoData();
    PyDbGeoData(AcDbGeoData* ptr, bool autoDelete);
    PyDbGeoData(const PyDbObjectId& id);
    PyDbGeoData(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbGeoData(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    virtual ~PyDbGeoData() override = default;

    PyDbObjectId        blockTableRecordId() const;
    void                setBlockTableRecordId(const PyDbObjectId& Id) const;
    PyDbObjectId        postToDb() const;
    void                eraseFromDb() const;
    AcDbGeoData::TypeOfCoordinates coordinateType() const;
    void                setCoordinateType(AcDbGeoData::TypeOfCoordinates designCoordinateType) const;
    AcGePoint3d         designPoint() const;
    void                setDesignPoint(const AcGePoint3d& point) const;
    AcGePoint3d         referencePoint() const;
    void                setReferencePoint(const AcGePoint3d& point) const;
    double              horizontalUnitScale() const;
    AcDb::UnitsValue    horizontalUnits() const;
    void                setHorizontalUnitScale(double horzUnitScale) const;
    void                setHorizontalUnits(AcDb::UnitsValue horizUnits) const;
    double              verticalUnitScale() const;
    AcDb::UnitsValue    verticalUnits() const;
    void                setVerticalUnitScale(double vertUnitScale) const;
    void                setVerticalUnits(AcDb::UnitsValue vertUnits) const;
    std::string         coordinateSystem() const;
    void                setCoordinateSystem(const std::string& coordinateSystem) const;
#ifdef NEVER //TODO
    static Acad::ErrorStatus       setValidateCoordinateSystemCallback(ACDBGEODATA_VALIDATE_CS pFuncValidateCs);
    static ACDBGEODATA_VALIDATE_CS getValidateCoordinateSystemCallback();
#endif
    AcGeVector3d        upDirection() const;
    void                setUpDirection(const AcGeVector3d& vec) const;
    double              northDirection() const;
    AcGeVector2d        northDirectionVector() const;
    void                setNorthDirectionVector(const AcGeVector2d& north) const;
    AcDbGeoData::ScaleEstimationMethod scaleEstimationMethod() const;
    void                setScaleEstimationMethod(AcDbGeoData::ScaleEstimationMethod value) const;
    double              scaleFactor() const;
    void                setScaleFactor(double value) const;
    bool                doSeaLevelCorrection() const;
    void                setDoSeaLevelCorrection(bool seaLevelCorrectionOn) const;
    double              seaLevelElevation() const;
    void                setSeaLevelElevation(double value) const;
    double              coordinateProjectionRadius() const;
    void                setCoordinateProjectionRadius(double value) const;
    std::string         geoRSSTag() const;
    void                setGeoRSSTag(const std::string& rssTag) const;
    std::string         observationFrom() const;
    void                setObservationFrom(const std::string& from) const;
    std::string         observationTo() const;
    void                setObservationTo(const std::string& to) const;
    std::string         observationCoverage() const;
    void                setObservationCoverage(const std::string& coverage) const;
    int                 numMeshPoints() const;
    boost::python::tuple getMeshPointMap(int index) const;
    boost::python::tuple getMeshPointMaps() const;
    void                 addMeshPointMap(int index, const AcGePoint2d& sourcePt, const AcGePoint2d& destPt) const;
    void                 setMeshPointMaps(const boost::python::object& sourcePts, const boost::python::object& destPts) const;
    void                 resetMeshPointMaps() const;
    int                  numMeshFaces() const;
    boost::python::tuple getMeshFace(int faceIndex) const;
    void                 addMeshFace(int faceIndex, int p0, int p1, int p2) const;
    void                 updateTransformationMatrix() const;
    AcGePoint3d          transformToLonLatAlt1(const AcGePoint3d& dwgPt) const;
    boost::python::tuple transformToLonLatAlt2(double x, double y, double z) const;
    AcGePoint3d          transformFromLonLatAlt1(const AcGePoint3d& geoPt) const;
    boost::python::tuple transformFromLonLatAlt2(double lon, double lat, double alt) const;

#ifdef NEVER //TODO
    static  Acad::ErrorStatus setTransformCallbacks(const ACHAR* zoneDescription, ACDBGEODATA_GEOGRAPHICTODWG pFuncGeoToDwg, ACDBGEODATA_DWGTOGEOGRAPHIC pFuncDwgToGeo);
    static  const ACHAR* getTransformCallbacks(ACDBGEODATA_GEOGRAPHICTODWG& pFuncGeoToDwg, ACDBGEODATA_DWGTOGEOGRAPHIC& pFuncDwgToGeo);
#endif

public:
    static PyRxClass        desc();
    static std::string      className();
    static PyDbGeoData      cloneFrom(const PyRxObject& src);
    static PyDbGeoData      cast(const PyRxObject& src);
public:
    AcDbGeoData* impObj(const std::source_location& src = std::source_location::current()) const;
};

#ifdef NEVER //TODO
Acad::ErrorStatus acdbGetGeoDataTransform(AcDbDatabase* pDbSource, AcDbDatabase* pDbTarget, AcGePoint3d& insertionPt, double& rotation, double& scale);
Acad::ErrorStatus acdbRegisterGeoDataReactor(AcDbGeoDataReactor* reactor);
void              acdbRemoveGeoDataReactor(AcDbGeoDataReactor* reactor);
#endif

//----------------------------------------------------------------------------------------
//PyDbGeoPositionMarker
void makePyDbGeoPositionMarkerWrapper();
class PyDbGeoPositionMarker : public PyDbEntity
{
public:
    PyDbGeoPositionMarker();
    PyDbGeoPositionMarker(const AcGePoint3d& position, double radius, double landingGap);
    PyDbGeoPositionMarker(AcDbGeoPositionMarker* ptr, bool autoDelete);
    PyDbGeoPositionMarker(const PyDbObjectId& id);
    PyDbGeoPositionMarker(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbGeoPositionMarker(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    inline virtual ~PyDbGeoPositionMarker() override = default;

    AcGePoint3d         position() const;
    void                setPosition(const AcGePoint3d& position) const;
    double              radius() const;
    void                setRadius(double radius) const;
    std::string         text() const;
    void                setText(const std::string& text) const;
    PyDbMText           mtext() const;
    void                setMText(const PyDbMText& pMText) const;
    bool                mtextVisible() const;
    void                setMTextVisible(bool visible) const;
    double              landingGap() const;
    void                setLandingGap(double landingGap) const;
    bool                enableFrameText() const;
    void                setEnableFrameText(bool enableFrameText) const;
    AcDbGeoPositionMarker::TextAlignmentType textAlignmentType() const;
    void                setTextAlignmentType(AcDbGeoPositionMarker::TextAlignmentType textAlignmentType) const;
    std::string         notes() const;
    void                setNotes(const std::string& notes) const;
    AcGePoint3d         geoPosition() const;
    void                setGeoPosition(const AcGePoint3d& position) const;
    boost::python::tuple latLonAlt() const;
    void                setLatLonAlt(double lat, double lon, double alt) const;
    AcGeVector3d        normal() const;
    PyDbObjectId        textStyle() const;

public:
    static PyRxClass                desc();
    static std::string              className();
    static PyDbGeoPositionMarker    cloneFrom(const PyRxObject& src);
    static PyDbGeoPositionMarker    cast(const PyRxObject& src);
public:
    inline AcDbGeoPositionMarker* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyDbGeoCoordinateSystem
void makePyDbGeoCoordinateSystemWrapper();
class PyDbGeoCoordinateSystem
{
public:
    PyDbGeoCoordinateSystem(AcDbGeoCoordinateSystem* ptr);
    ~PyDbGeoCoordinateSystem() = default;

    std::string                     getId() const;
    int                             getEpsgCode() const;
    AcDbGeoCoordinateSystem::Type   getType() const;
    std::string                     getDescription() const;
    AcDb::UnitsValue                getUnit() const;
    AcDbGeoCoordinateSystem::Unit   getGeoUnit() const;
    double                          getUnitScale() const;
    AcDbGeoCoordinateSystem::ProjectionCode getProjectionCode() const;
    boost::python::tuple            getDatum() const;
    boost::python::tuple            getEllipsoid() const;
    AcGeVector2d                    getOffset() const;
    AcDbExtents2d                   getCartesianExtents() const;
    AcDbExtents2d                   getGeodeticExtents() const;
    std::string                     getXmlRepresentation() const;
    std::string                     getWktRepresentation() const;

    //virtual Acad::ErrorStatus getProjectionParameters(AcArray<AcDbGeoProjectionParameter>& prjParams,
    //    bool includeSpecialParams) const = 0;

    static PyDbGeoCoordinateSystem create(const std::string& coordSysIdOrFullDef);
    static std::string             className();
public:
    AcDbGeoCoordinateSystem* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<AcDbGeoCoordinateSystem>m_pyImp;
};

//----------------------------------------------------------------------------------------
//PyDbGeoCoordinateSystemTransformer
void makePyDbGeoCoordinateSystemTransformerWrapper();
class PyDbGeoCoordinateSystemTransformer
{
public:
    PyDbGeoCoordinateSystemTransformer(AcDbGeoCoordinateSystemTransformer* ptr);
    ~PyDbGeoCoordinateSystemTransformer() = default;
    std::string         getSourceCoordinateSystemId() const;
    std::string         getTargetCoordinateSystemId() const;
    AcGePoint3d         transformPoint(const AcGePoint3d& pointIn) const;
    boost::python::list transformPoints(const boost::python::list& pointsIn) const;
    static PyDbGeoCoordinateSystemTransformer create(const std::string& sourceCoordSysId, const std::string& targetCoordSysId);
    static std::string                        className();
public:
    AcDbGeoCoordinateSystemTransformer*       impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<AcDbGeoCoordinateSystemTransformer>m_pyImp;
};




#pragma pack (pop)
