#pragma once
#include "PyDbObject.h"


void makeAcDbSymbolTableRecordWrapper();

//---------------------------------------------------------------------------------------- -
// PyDbSymbolTableRecord 
class PyDbSymbolTableRecord : public PyDbObject
{
public:
    PyDbSymbolTableRecord(AcDbSymbolTableRecord* ptr, bool autoDelete);
    PyDbSymbolTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbSymbolTableRecord() override = default;
    std::string         getName();
    Acad::ErrorStatus   setName(const std::string name);
    bool                isDependent() const;
    bool                isResolved() const;
    bool                isRenamable() const;
public:
    static std::string  className();
    static PyRxClass    desc();
    static PyDbSymbolTableRecord cloneFrom(const PyRxObject& src);
    static PyDbSymbolTableRecord cast(const PyRxObject& src);
public:
    AcDbSymbolTableRecord* impObj(const std::source_location& src = std::source_location::current()) const;
};

//---------------------------------------------------------------------------------------- -
// PyDbDimStyleTableRecord 
void makeAcDbDimStyleTableRecordWrapper();
class PyDbDimStyleTableRecord : public PyDbSymbolTableRecord
{
public:
    PyDbDimStyleTableRecord();
    PyDbDimStyleTableRecord(AcDbDimStyleTableRecord* ptr, bool autoDelete);
    PyDbDimStyleTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbDimStyleTableRecord() override = default;
    //TODO: 
public:
    static std::string className();
    static PyRxClass desc();
    static PyDbDimStyleTableRecord cloneFrom(const PyRxObject& src);
    static PyDbDimStyleTableRecord cast(const PyRxObject& src);
public:
    AcDbDimStyleTableRecord* impObj(const std::source_location& src = std::source_location::current()) const;
};

//---------------------------------------------------------------------------------------- -
// PyDbAbstractViewTableRecord
void makePyDbAbstractViewTableRecordWrapper();

class PyDbAbstractViewTableRecord : public PyDbSymbolTableRecord
{
public:
#ifdef NEVER
    PyDbAbstractViewTableRecord();
#endif
    PyDbAbstractViewTableRecord(AcDbAbstractViewTableRecord* ptr, bool autoDelete);
    PyDbAbstractViewTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbAbstractViewTableRecord() override = default;
    AcGePoint2d         centerPoint() const;
    void                setCenterPoint(const AcGePoint2d& val);
    double              height() const;
    void                setHeight(double val);
    double              width() const;
    void                setWidth(double val);
    AcGePoint3d         target() const;
    void                setTarget(const AcGePoint3d& target);
    AcGeVector3d        viewDirection() const;
    void                setViewDirection1(const AcGeVector3d& viewDirection);
    double              viewTwist() const;
    void                setViewTwist(double angle);
    double              lensLength() const;
    void                setLensLength(double length);
    double              frontClipDistance() const;
    void                setFrontClipDistance(double distance);
    double              backClipDistance() const;
    void                setBackClipDistance(double distance);
    bool                perspectiveEnabled() const;
    void                setPerspectiveEnabled(bool enabled);
    bool                frontClipEnabled() const;
    void                setFrontClipEnabled(bool enabled);
    bool                backClipEnabled() const;
    void                setBackClipEnabled(bool enabled);
    bool                frontClipAtEye() const;
    void                setFrontClipAtEye(bool atEye);
    PyDbObjectId        background() const;
    Acad::ErrorStatus   setBackground(const PyDbObjectId& backgroundId);
    PyDbObjectId        visualStyle() const;
    Acad::ErrorStatus   setVisualStyle(const PyDbObjectId& visualStyleId);
    bool                isDefaultLightingOn() const;
    Acad::ErrorStatus   setDefaultLightingOn(bool on);
    AcGiViewportTraits::DefaultLightingType defaultLightingType() const;
    Acad::ErrorStatus   setDefaultLightingType(AcGiViewportTraits::DefaultLightingType typ);
    double              brightness() const;
    Acad::ErrorStatus   setBrightness(double val);
    double              contrast() const;
    Acad::ErrorStatus   setContrast(double val);
    AcCmColor           ambientLightColor() const;
    Acad::ErrorStatus   setAmbientLightColor(const AcCmColor& clr);
    PyDbObjectId        sunId() const;
    Acad::ErrorStatus   setSun1(PyDbObjectId& retId, PyDbObject& pSun);
    Acad::ErrorStatus   setSun2(PyDbObjectId& retId, PyDbObject& pSun, bool eraseOldSun);
    //Acad::ErrorStatus toneOperatorParameters(AcGiToneOperatorParameters& params) const;
    //Acad::ErrorStatus setToneOperatorParameters(const AcGiToneOperatorParameters& params);
    Acad::ErrorStatus   getUcs(AcGePoint3d& origin, AcGeVector3d& xAxis, AcGeVector3d& yAxis) const;
    boost::python::tuple isUcsOrthographic() const;
    PyDbObjectId        ucsName() const;
    double              elevation() const;
    Acad::ErrorStatus   setUcs1(const AcGePoint3d& origin, const AcGeVector3d& xAxis, const AcGeVector3d& yAxis);
    Acad::ErrorStatus   setUcs2(AcDb::OrthographicView view);
    Acad::ErrorStatus   setUcs3(const PyDbObjectId& ucsId);
    Acad::ErrorStatus   setUcsToWorld();
    Acad::ErrorStatus   setElevation(double elev);
    boost::python::tuple isViewOrthographic() const;
    Acad::ErrorStatus   setViewDirection2(AcDb::OrthographicView view);

public:
    static std::string className();
    static PyRxClass desc();
    static PyDbAbstractViewTableRecord cloneFrom(const PyRxObject& src);
    static PyDbAbstractViewTableRecord cast(const PyRxObject& src);
public:
    AcDbAbstractViewTableRecord* impObj(const std::source_location& src = std::source_location::current()) const;
};

//---------------------------------------------------------------------------------------- -
// PyDbViewportTableRecord
void makePyDbViewportTableRecordWrapper();

class PyDbViewportTableRecord : public PyDbAbstractViewTableRecord
{
public:
    PyDbViewportTableRecord();
    PyDbViewportTableRecord(AcDbViewportTableRecord* ptr, bool autoDelete);
    PyDbViewportTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbViewportTableRecord() override = default;
public:
    static std::string className();
    static PyRxClass desc();
    static PyDbViewportTableRecord cloneFrom(const PyRxObject& src);
    static PyDbViewportTableRecord cast(const PyRxObject& src);
public:
    AcDbViewportTableRecord* impObj(const std::source_location& src = std::source_location::current()) const;
};

//---------------------------------------------------------------------------------------- -
// PyDbViewTableRecord
void makePyDbViewTableRecordWrapper();

class PyDbViewTableRecord : public PyDbAbstractViewTableRecord
{
public:
    PyDbViewTableRecord();
    PyDbViewTableRecord(AcDbViewTableRecord* ptr, bool autoDelete);
    PyDbViewTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbViewTableRecord() override = default;

    PyDbObjectId getLayout() const;
    Acad::ErrorStatus setLayout(const PyDbObjectId& layoutId);

public:
    static std::string className();
    static PyRxClass desc();
    static PyDbViewTableRecord cloneFrom(const PyRxObject& src);
    static PyDbViewTableRecord cast(const PyRxObject& src);
public:
    AcDbViewTableRecord* impObj(const std::source_location& src = std::source_location::current()) const;
};