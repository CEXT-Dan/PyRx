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

    AcString            text() const;
    void                setText(const AcString& text);

    PyDbMText           mtext() const;
    void                setMText(const PyDbMText& pMText);

public:
    static PyRxClass                desc();
    static std::string              className();
    static PyDbGeoPositionMarker    cloneFrom(const PyRxObject& src);
    static PyDbGeoPositionMarker    cast(const PyRxObject& src);
public:
    inline AcDbGeoPositionMarker* impObj(const std::source_location& src = std::source_location::current()) const;
};

