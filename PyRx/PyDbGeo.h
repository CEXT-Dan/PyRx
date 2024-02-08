#pragma once
#include "PyDbEntity.h"
#include "dbGeoData.h"
#include "AcDbGeoPositionMarker.h"

class PyDbMText;

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
    inline virtual ~PyDbGeoData() override = default;

public:
    static PyRxClass        desc();
    static std::string      className();
    static PyDbGeoData      cloneFrom(const PyRxObject& src);
    static PyDbGeoData      cast(const PyRxObject& src);
public:
    inline AcDbGeoData* impObj(const std::source_location& src = std::source_location::current()) const;
};

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

