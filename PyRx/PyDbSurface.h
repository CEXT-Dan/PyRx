#pragma once

#include "PyDbEntity.h"

#ifdef SOLID3D_SUPPORT

class PyDbObjectId;
class AcDbLoftedSurface;
class AcDbPlaneSurface;

//----------------------------------------------------------------------
//PyDbSurface
void makePyDbSurfaceWrapper();

class PyDbSurface : public PyDbEntity
{
public:
    PyDbSurface();
    PyDbSurface(AcDbSurface* ptr, bool autoDelete);
    PyDbSurface(const PyDbObjectId& id, AcDb::OpenMode mode);
    static std::string className();
public:
    AcDbSurface* impObj() const;
};

//----------------------------------------------------------------------
//AcDbExtrudedSurface
void makeAcDbExtrudedSurfaceWrapper();

class PyDbExtrudedSurface : public PyDbSurface
{
public:
    PyDbExtrudedSurface();
    PyDbExtrudedSurface(AcDbExtrudedSurface* ptr, bool autoDelete);
    PyDbExtrudedSurface(const PyDbObjectId& id, AcDb::OpenMode mode);
    static std::string className();
public:
    AcDbExtrudedSurface* impObj() const;
};

//----------------------------------------------------------------------
//AcDbLoftedSurface 
void makeAcDbLoftedSurfaceWrapper();

#if defined(GRXAPP) || defined(ZRXAPP)
#else
class PyDbLoftedSurface : public PyDbSurface
{
public:
    PyDbLoftedSurface();
    PyDbLoftedSurface(AcDbLoftedSurface* ptr, bool autoDelete);
    PyDbLoftedSurface(const PyDbObjectId& id, AcDb::OpenMode mode);
    static std::string className();
public:
    AcDbLoftedSurface* impObj() const;
};
#endif

//----------------------------------------------------------------------
//PyDbNurbSurface 
void makePyDbNurbSurfaceWrapper();

#if defined(GRXAPP) || defined(ZRXAPP)
#else
class PyDbNurbSurface : public PyDbSurface
{
public:
    PyDbNurbSurface();
    PyDbNurbSurface(AcDbNurbSurface* ptr, bool autoDelete);
    PyDbNurbSurface(const PyDbObjectId& id, AcDb::OpenMode mode);
    static std::string className();
public:
    AcDbNurbSurface* impObj() const;
};
#endif

//----------------------------------------------------------------------
//AcDbPlaneSurface  
void makePyDbPlaneSurfaceWrapper();

#if defined(GRXAPP) || defined(ZRXAPP)
#else
class PyDbPlaneSurface : public PyDbSurface
{
public:
    PyDbPlaneSurface();
    PyDbPlaneSurface(AcDbPlaneSurface* ptr, bool autoDelete);
    PyDbPlaneSurface(const PyDbObjectId& id, AcDb::OpenMode mode);
    static std::string className();
public:
    AcDbPlaneSurface* impObj() const;
};
#endif

//----------------------------------------------------------------------
//PyDbRevolvedSurface  
void makePyDbRevolvedSurfaceWrapper();

#if defined(GRXAPP) || defined(ZRXAPP)
#else
class PyDbRevolvedSurface : public PyDbSurface
{
public:
    PyDbRevolvedSurface();
    PyDbRevolvedSurface(AcDbRevolvedSurface* ptr, bool autoDelete);
    PyDbRevolvedSurface(const PyDbObjectId& id, AcDb::OpenMode mode);
    static std::string className();
public:
    AcDbRevolvedSurface* impObj() const;
};
#endif

//----------------------------------------------------------------------
//AcDbSweptSurface  
void makePyDbSweptSurfaceWrapper();

#if defined(GRXAPP) || defined(ZRXAPP)
#else
class PyDbSweptSurface : public PyDbSurface
{
public:
    PyDbSweptSurface();
    PyDbSweptSurface(AcDbSweptSurface* ptr, bool autoDelete);
    PyDbSweptSurface(const PyDbObjectId& id, AcDb::OpenMode mode);
    static std::string className();
public:
    AcDbSweptSurface* impObj() const;
};
#endif


#endif //SOLID3D_SUPPORT