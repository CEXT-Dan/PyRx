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
    void                setBlockTableRecordId(const PyDbObjectId& Id);
    PyDbObjectId        postToDb();
    void                eraseFromDb();
    AcDbGeoData::TypeOfCoordinates coordinateType() const;
    void                setCoordinateType(AcDbGeoData::TypeOfCoordinates designCoordinateType);
    AcGePoint3d         designPoint() const;
    void                setDesignPoint(const AcGePoint3d& point);
    AcGePoint3d         referencePoint() const;
    void                setReferencePoint(const AcGePoint3d& point);
    double              horizontalUnitScale() const;
    AcDb::UnitsValue    horizontalUnits() const;
    void                setHorizontalUnitScale(double horzUnitScale);
    void                setHorizontalUnits(AcDb::UnitsValue horizUnits);
    double              verticalUnitScale() const;
    AcDb::UnitsValue    verticalUnits() const;
    void                setVerticalUnitScale(double vertUnitScale);
    void                setVerticalUnits(AcDb::UnitsValue vertUnits);
    std::string         coordinateSystem() const;
    void                setCoordinateSystem(const std::string& coordinateSystem);
#ifdef NEVER //TODO
    static Acad::ErrorStatus       setValidateCoordinateSystemCallback(ACDBGEODATA_VALIDATE_CS pFuncValidateCs);
    static ACDBGEODATA_VALIDATE_CS getValidateCoordinateSystemCallback();
#endif
    AcGeVector3d        upDirection() const;
    void                setUpDirection(const AcGeVector3d& vec);
    double              northDirection() const;
    AcGeVector2d        northDirectionVector() const;
    void                setNorthDirectionVector(const AcGeVector2d& north);
    AcDbGeoData::ScaleEstimationMethod scaleEstimationMethod() const;
    void                setScaleEstimationMethod(AcDbGeoData::ScaleEstimationMethod value);
    double              scaleFactor() const;
    void                setScaleFactor(double value);
    bool                doSeaLevelCorrection() const;
    void                setDoSeaLevelCorrection(bool seaLevelCorrectionOn);
    double              seaLevelElevation() const;
    void                setSeaLevelElevation(double value);
    double              coordinateProjectionRadius() const;
    void                setCoordinateProjectionRadius(double value);
    std::string         geoRSSTag() const;
    void                setGeoRSSTag(const std::string& rssTag);
    std::string         observationFrom() const;
    void                setObservationFrom(const std::string& from);
    std::string         observationTo() const;
    void                setObservationTo(const std::string& to);
    std::string         observationCoverage() const;
    void                setObservationCoverage(const std::string& coverage);
    int                 numMeshPoints() const;
    boost::python::tuple getMeshPointMap(int index) const;
    boost::python::tuple getMeshPointMaps() const;
    void                 addMeshPointMap(int index, const AcGePoint2d& sourcePt, const AcGePoint2d& destPt);
    void                 setMeshPointMaps(const boost::python::object& sourcePts, const boost::python::object& destPts);
    void                 resetMeshPointMaps();
    int                  numMeshFaces() const;
    boost::python::tuple getMeshFace(int faceIndex) const;
    void                 addMeshFace(int faceIndex, int p0, int p1, int p2);
    void                 updateTransformationMatrix();
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
    void                setPosition(const AcGePoint3d& position);
    double              radius() const;
    void                setRadius(double radius);
    std::string         text() const;
    void                setText(const std::string& text);
    PyDbMText           mtext() const;
    void                setMText(const PyDbMText& pMText);
    bool                mtextVisible() const;
    void                setMTextVisible(bool visible);
    double              landingGap() const;
    void                setLandingGap(double landingGap);
    bool                enableFrameText() const;
    void                setEnableFrameText(bool enableFrameText);
    AcDbGeoPositionMarker::TextAlignmentType textAlignmentType() const;
    void                setTextAlignmentType(AcDbGeoPositionMarker::TextAlignmentType textAlignmentType);
    std::string         notes() const;
    void                setNotes(const std::string& notes);
    AcGePoint3d         geoPosition() const;
    void                setGeoPosition(const AcGePoint3d& position);
    boost::python::tuple latLonAlt() const;
    void                setLatLonAlt(double lat, double lon, double alt);
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


#pragma pack (pop)
