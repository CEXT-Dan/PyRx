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
    Adesk::Int16        number()  const;
    AcGePoint2d         lowerLeftCorner() const;
    void                setLowerLeftCorner(const AcGePoint2d& pt);
    AcGePoint2d         upperRightCorner() const;
    void                setUpperRightCorner(const AcGePoint2d& pt);
    bool                ucsFollowMode() const;
    void                setUcsFollowMode(bool enabled);
    Adesk::UInt16       circleSides() const;
    void                setCircleSides(Adesk::UInt16 circleSides);
    bool                fastZoomsEnabled() const;
    void                setFastZoomsEnabled(bool enabled);
    bool                iconEnabled() const;
    void                setIconEnabled(bool enabled);
    bool                iconAtOrigin() const;
    void                setIconAtOrigin(bool atOrigin);
    bool                gridEnabled() const;
    void                setGridEnabled(bool enabled);
    AcGePoint2d         gridIncrements() const;
    void                setGridIncrements(const AcGePoint2d& base);
    bool                snapEnabled() const;
    void                setSnapEnabled(bool enabled);
    bool                isometricSnapEnabled() const;
    void                setIsometricSnapEnabled(bool enabled);
    Adesk::Int16        snapPair() const;
    void                setSnapPair(Adesk::Int16 pairType);
    double              snapAngle() const;
    void                setSnapAngle(double angle);
    AcGePoint2d         snapBase() const;
    void                setSnapBase(const AcGePoint2d& base);
    AcGePoint2d         snapIncrements() const;
    void                setSnapIncrements(const AcGePoint2d& base);
    //void                setGsView(AcGsView* pView);
    //AcGsView*           gsView() const;
    bool                isUcsSavedWithViewport() const;
    void                setUcsPerViewport(bool ucsvp);
    bool                isGridBoundToLimits() const;
    void                setGridBoundToLimits(bool enabled);
    bool                isGridAdaptive() const;
    void                setGridAdaptive(bool enabled);
    bool                isGridSubdivisionRestricted() const;
    void                setGridSubdivisionRestricted(bool enabled);
    bool                isGridFollow() const;
    void                setGridFollow(bool enabled);
    Adesk::Int16        gridMajor() const;
    void                setGridMajor(Adesk::Int16 value);
    Acad::ErrorStatus   setBackground(const PyDbObjectId& backgroundId);
    PyDbObjectId        previousBackground1() const;
    PyDbObjectId        previousBackground2(AcGiDrawable::DrawableType type) const;
    Acad::ErrorStatus   setPreviousBackground1(PyDbObjectId& backgroundId);
    Acad::ErrorStatus   setPreviousBackground2(PyDbObjectId& backgroundId, AcGiDrawable::DrawableType type, bool bForcedSwitch);
    bool                previousBackgroundForcedSwitch(void) const;

public:
    static std::string  className();
    static PyRxClass    desc();
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