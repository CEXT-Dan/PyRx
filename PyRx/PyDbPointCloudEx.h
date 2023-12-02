#pragma once
#include "PyDbEntity.h"
#include "AcDbPointCloudEx.h"
#include "AcDbPointCloudDefEx.h"

class PyDbObjectId;
class PyDbDatabase;

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

    static std::string          className();
    static PyRxClass            desc();
    static PyDbPointCloudEx     cloneFrom(const PyRxObject& src);
    static PyDbPointCloudEx     cast(const PyRxObject& src);
public:
    inline AcDbPointCloudEx* impObj(const std::source_location& src = std::source_location::current()) const;
};

