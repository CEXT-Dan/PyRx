#pragma once
#include "PyRxObject.h"
#include "dbdimptref.h"

class PyDbObjectId;

//-----------------------------------------------------------------------------------------
//PyDbPointRef
void makePyDbPointRefWrapper();

class PyDbPointRef : public PyRxObject
{
public:
    PyDbPointRef(const AcDbPointRef* ptr);
    PyDbPointRef(AcDbPointRef* ptr, bool autoDelete);
    virtual ~PyDbPointRef() override = default;
    static PyRxClass       desc();
    static std::string     className();

public:
    AcDbPointRef* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PyDbOsnapPointRef
void makePyDbOsnapPointRefWrapper();

class PyDbOsnapPointRef : public PyDbPointRef
{
#if !defined(_BRXTARGET240)
public:
    PyDbOsnapPointRef();
    PyDbOsnapPointRef(const AcGePoint3d& refPt);
    PyDbOsnapPointRef(const AcDbOsnapPointRef* ptr);
    PyDbOsnapPointRef(AcDbOsnapPointRef* ptr, bool autoDelete);
    virtual ~PyDbOsnapPointRef() override = default;
    AcDbPointRef::OsnapType osnapType() const;
    void                    setOsnapType(AcDbPointRef::OsnapType osnType);

    void                    setIdPath(PyDbObjectId& id, AcDb::SubentType type, Adesk::GsMarker gsMarker);

    void                    setPoint(const AcGePoint3d& pt);
    AcGePoint3d             point() const;

    static PyRxClass        desc();
    static std::string      className();

public:
    AcDbOsnapPointRef* impObj(const std::source_location& src = std::source_location::current()) const;
#endif
};


