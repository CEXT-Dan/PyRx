#pragma once

#include "PyDbEntity.h"
#include "dbextrudedsurf.h"
#include "dbloftedsurf.h"
#include "dbnurbsurf.h"
#include "dbplanesurf.h"
#include "dbrevolvedsurf.h"
#include "dbsweptsurf.h"

class PyDbObjectId;
class PyDb3dProfile;
class PyDbSweepOptions;
class PyDbExtrudedSurface;

//----------------------------------------------------------------------
//PyDbSurface
void makePyDbSurfaceWrapper();

class PyDbSurface : public PyDbEntity
{
public:
    PyDbSurface();
    PyDbSurface(AcDbSurface* ptr, bool autoDelete);
    PyDbSurface(const PyDbObjectId& id);
    PyDbSurface(const PyDbObjectId& id, AcDb::OpenMode mode);


    double                  getArea() const;
    Adesk::UInt16           uIsolineDensity() const;
    void                    setUIsolineDensity(Adesk::UInt16 numIsolines);
    Adesk::UInt16           vIsolineDensity() const;
    void                    setVIsolineDensity(Adesk::UInt16 numIsolines);
    AcDbSurface::WireframeType  getWireframeType() const;
    void                    setWireframeType(AcDbSurface::WireframeType type);
    double                  getPerimeter() const;
    PyDbObjectId            creationActionBodyId() const;
    boost::python::list     modificationActionBodyIds() const;
	void                    extendEdges(boost::python::list& edges, double extDist, AcDbSurface::EdgeExtensionType extOption, bool  bAssociativeEnabled);
    boost::python::tuple    rayTest(const AcGePoint3d& rayBasePoint, const AcGeVector3d& rayDir,double rayRadius) const;

    // Acad::ErrorStatus ACDB_PORT convertToNurbSurface(AcDbNurbSurfaceArray& nsArray);
    boost::python::list projectOnToSurface(const PyDbEntity& ent, const AcGeVector3d& projectionDirection);


    static PyDbSurface          createFrom(const PyDbEntity& pFromEntity);
    static PyDbExtrudedSurface  createExtrudedSurface(PyDb3dProfile& pSweep, const AcGeVector3d& directionVec, PyDbSweepOptions& sweepOptions);


      
    static std::string      className();
    static PyRxClass        desc();
    static PyDbSurface		cloneFrom(const PyRxObject& src);
    static PyDbSurface      cast(const PyRxObject& src);
public:
    AcDbSurface* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------
//AcDbExtrudedSurface
void makePyDbExtrudedSurfaceWrapper();

class PyDbExtrudedSurface : public PyDbSurface
{
public:
    PyDbExtrudedSurface();
    PyDbExtrudedSurface(AcDbExtrudedSurface* ptr, bool autoDelete);
    PyDbExtrudedSurface(const PyDbObjectId& id);
    PyDbExtrudedSurface(const PyDbObjectId& id, AcDb::OpenMode mode);
    static std::string  className();
    static PyRxClass    desc();
    static PyDbExtrudedSurface cloneFrom(const PyRxObject& src);
    static PyDbExtrudedSurface cast(const PyRxObject& src);
public:
    AcDbExtrudedSurface* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------
//AcDbLoftedSurface 
void makePyDbLoftedSurfaceWrapper();

class PyDbLoftedSurface : public PyDbSurface
{
public:
    PyDbLoftedSurface();
    PyDbLoftedSurface(AcDbLoftedSurface* ptr, bool autoDelete);
    PyDbLoftedSurface(const PyDbObjectId& id);
    PyDbLoftedSurface(const PyDbObjectId& id, AcDb::OpenMode mode);
    static std::string  className();
    static PyRxClass    desc();
    static PyDbLoftedSurface cloneFrom(const PyRxObject& src);
    static PyDbLoftedSurface cast(const PyRxObject& src);
public:
    AcDbLoftedSurface* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------
//PyDbNurbSurface 
void makePyDbNurbSurfaceWrapper();

class PyDbNurbSurface : public PyDbSurface
{
public:
    PyDbNurbSurface();
    PyDbNurbSurface(AcDbNurbSurface* ptr, bool autoDelete);
    PyDbNurbSurface(const PyDbObjectId& id);
    PyDbNurbSurface(const PyDbObjectId& id, AcDb::OpenMode mode);
    static std::string  className();
    static PyRxClass    desc();
    static PyDbNurbSurface cloneFrom(const PyRxObject& src);
    static PyDbNurbSurface cast(const PyRxObject& src);
public:
    AcDbNurbSurface* impObj(const std::source_location& src = std::source_location::current()) const;
};


//----------------------------------------------------------------------
//AcDbPlaneSurface  
void makePyDbPlaneSurfaceWrapper();

class PyDbPlaneSurface : public PyDbSurface
{
public:
    PyDbPlaneSurface();
    PyDbPlaneSurface(AcDbPlaneSurface* ptr, bool autoDelete);
    PyDbPlaneSurface(const PyDbObjectId& id);
    PyDbPlaneSurface(const PyDbObjectId& id, AcDb::OpenMode mode);
    static std::string  className();
    static PyRxClass    desc();
    static PyDbPlaneSurface cloneFrom(const PyRxObject& src);
    static PyDbPlaneSurface cast(const PyRxObject& src);
public:
    AcDbPlaneSurface* impObj(const std::source_location& src = std::source_location::current()) const;
};


//----------------------------------------------------------------------
//PyDbRevolvedSurface  
void makePyDbRevolvedSurfaceWrapper();

class PyDbRevolvedSurface : public PyDbSurface
{
public:
    PyDbRevolvedSurface();
    PyDbRevolvedSurface(AcDbRevolvedSurface* ptr, bool autoDelete);
    PyDbRevolvedSurface(const PyDbObjectId& id);
    PyDbRevolvedSurface(const PyDbObjectId& id, AcDb::OpenMode mode);
    static std::string  className();
    static PyRxClass    desc();
    static PyDbRevolvedSurface cloneFrom(const PyRxObject& src);
    static PyDbRevolvedSurface cast(const PyRxObject& src);
public:
    AcDbRevolvedSurface* impObj(const std::source_location& src = std::source_location::current()) const;
};


//----------------------------------------------------------------------
//AcDbSweptSurface  
void makePyDbSweptSurfaceWrapper();

class PyDbSweptSurface : public PyDbSurface
{
public:
    PyDbSweptSurface();
    PyDbSweptSurface(AcDbSweptSurface* ptr, bool autoDelete);
    PyDbSweptSurface(const PyDbObjectId& id);
    PyDbSweptSurface(const PyDbObjectId& id, AcDb::OpenMode mode);
    static std::string  className();
    static PyRxClass    desc();
    static PyDbSweptSurface cloneFrom(const PyRxObject& src);
    static PyDbSweptSurface cast(const PyRxObject& src);
public:
    AcDbSweptSurface* impObj(const std::source_location& src = std::source_location::current()) const;
};


