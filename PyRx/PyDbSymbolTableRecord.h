#pragma once
#include "PyDbObject.h"

class PyDbEntity;
class PyDbBlockBegin;
class PyDbBlockEnd;
class PyDbObjectId;
class PyDbAnnotationScale;


void makeAcDbSymbolTableRecordWrapper();

//---------------------------------------------------------------------------------------- -
// PyDbSymbolTableRecord 
class PyDbSymbolTableRecord : public PyDbObject
{
public:
    PyDbSymbolTableRecord(AcDbSymbolTableRecord* ptr, bool autoDelete);
    PyDbSymbolTableRecord(const PyDbObjectId& id);
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
    PyDbDimStyleTableRecord(const PyDbObjectId& id);
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
    PyDbAbstractViewTableRecord(const PyDbObjectId& id);
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
    PyDbViewportTableRecord(const PyDbObjectId& id);
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
    PyDbViewTableRecord(const PyDbObjectId& id);
    PyDbViewTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbViewTableRecord() override = default;
    Acad::ErrorStatus   setParametersFromViewport(PyDbObjectId& objId);
    bool                isPaperspaceView() const;
    void                setIsPaperspaceView(bool pspace);
    bool                isUcsAssociatedToView() const;
    Acad::ErrorStatus   disassociateUcsFromView();
    std::string         getCategoryName() const;
    Acad::ErrorStatus   setCategoryName(const std::string& categoryName);
    std::string         getLayerState() const;
    Acad::ErrorStatus   setLayerState(const std::string& layerStateName);
    PyDbObjectId        getLayout() const;
    Acad::ErrorStatus   setLayout(const PyDbObjectId& layoutId);
    bool                isViewAssociatedToViewport() const;
    Acad::ErrorStatus   setViewAssociatedToViewport(bool bVPflag);
    bool                isCameraPlottable() const;
    Acad::ErrorStatus   setIsCameraPlottable(bool plottable);
    PyDbObjectId        liveSection() const;
    Acad::ErrorStatus   setLiveSection(const PyDbObjectId& liveSectionId);
    PyDbObjectId        camera() const;
    Acad::ErrorStatus   setCamera(const PyDbObjectId& cameraId);
    PyDbAnnotationScale annotationScale() const;
    Acad::ErrorStatus   setAnnotationScale(const PyDbAnnotationScale& pScaleObj);
    PyDbObjectId        sunId() const;
    Acad::ErrorStatus   setSun1(PyDbObjectId& retId, PyDbObject& pSun);
    Acad::ErrorStatus   setSun2(PyDbObjectId& retId, PyDbObject& pSun, bool eraseOldSun);

public:
    static std::string className();
    static PyRxClass desc();
    static PyDbViewTableRecord cloneFrom(const PyRxObject& src);
    static PyDbViewTableRecord cast(const PyRxObject& src);
public:
    AcDbViewTableRecord* impObj(const std::source_location& src = std::source_location::current()) const;
};

//---------------------------------------------------------------------------------------- -
// PyDbBlockTableRecord
void makeAcDbBlockTableRecordWrapper();
class PyDbBlockTableRecord : public PyDbSymbolTableRecord
{
public:
    PyDbBlockTableRecord();
    PyDbBlockTableRecord(AcDbBlockTableRecord* ptr, bool autoDelete);
    PyDbBlockTableRecord(const PyDbObjectId& id);
    PyDbBlockTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbBlockTableRecord() override = default;
    PyDbObjectId        appendAcDbEntity(const PyDbEntity& ent);
    boost::python::list objectIds();
    std::string         comments();
    Acad::ErrorStatus   setComments(const std::string& pString);
    std::string         pathName();
    Acad::ErrorStatus   setPathName(const std::string& pString);
    AcGePoint3d         origin() const;
    Acad::ErrorStatus   setOrigin(const AcGePoint3d& pt);
    Acad::ErrorStatus   openBlockBegin(PyDbBlockBegin& pBlockBegin, AcDb::OpenMode openMode);
    Acad::ErrorStatus   openBlockEnd(PyDbBlockEnd& pBlockBegin, AcDb::OpenMode openMode);
    bool                hasAttributeDefinitions() const;
    bool                isAnonymous() const;
    bool                isFromExternalReference() const;
    bool                isFromOverlayReference() const;
    Acad::ErrorStatus   setIsFromOverlayReference(bool bIsOverlay);
    bool                isLayout() const;
    PyDbObjectId        getLayoutId() const;
    Acad::ErrorStatus   setLayoutId(const PyDbObjectId& id);
    boost::python::list getBlockReferenceIds1();
    boost::python::list getBlockReferenceIds2(bool bDirectOnly, bool bForceValidity);
    boost::python::list getErasedBlockReferenceIds();
    PyDbDatabase        xrefDatabase(bool incUnres) const;
    bool                isUnloaded() const;
    Acad::ErrorStatus   setIsUnloaded(bool isUnloaded);
    AcDb::XrefStatus    xrefStatus() const;
    virtual Acad::ErrorStatus assumeOwnershipOf(const  boost::python::list& entitiesToMove);
    AcDbBlockTableRecord::BlockScaling blockScaling() const;
    Acad::ErrorStatus   setBlockScaling(AcDbBlockTableRecord::BlockScaling blockScaling);
    Acad::ErrorStatus   setExplodable(bool bExplodable);
    bool                explodable() const;
    Acad::ErrorStatus   setBlockInsertUnits(AcDb::UnitsValue insunits);
    AcDb::UnitsValue    blockInsertUnits() const;
    int                 postProcessAnnotativeBTR(bool bqueryOnly, bool bScale);
    Acad::ErrorStatus   addAnnoScalestoBlkRefs(bool bScale);
    static std::string  className();
    static PyRxClass    desc();
    static PyDbBlockTableRecord	cloneFrom(const PyRxObject& src);
    static PyDbBlockTableRecord cast(const PyRxObject& src);
public:
    AcDbBlockTableRecord* impObj(const std::source_location& src = std::source_location::current()) const;
};

//---------------------------------------------------------------------------------------- -
// PyDbLayerTableRecord
void makeAcDbLayerTableRecordWrapper();
class PyDbLayerTableRecord : public PyDbSymbolTableRecord
{
public:
    PyDbLayerTableRecord();
    PyDbLayerTableRecord(AcDbLayerTableRecord* ptr, bool autoDelete);
    PyDbLayerTableRecord(const PyDbObjectId& id);
    PyDbLayerTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbLayerTableRecord() override = default;
    bool              isFrozen() const;
    Acad::ErrorStatus setIsFrozen(bool frozen);
    bool              isOff() const;
    void              setIsOff(bool off);
    bool              VPDFLT() const;
    void              setVPDFLT(bool frozen);
    bool              isLocked() const;
    void              setIsLocked(bool locked);
    AcCmColor         color() const;
    void              setColor(const AcCmColor& color);
    AcCmEntityColor   entityColor(void) const;
    AcCmTransparency  transparency(void) const;
    Acad::ErrorStatus setTransparency(const AcCmTransparency& trans);
    PyDbObjectId      linetypeObjectId() const;
    Acad::ErrorStatus setLinetypeObjectId(const PyDbObjectId& id);
    PyDbObjectId      materialId() const;
    Acad::ErrorStatus setMaterialId(const PyDbObjectId& id);
    bool              isPlottable() const;
    Acad::ErrorStatus setIsPlottable(bool plot);
    AcDb::LineWeight  lineWeight() const;
    Acad::ErrorStatus setLineWeight(AcDb::LineWeight weight);
    std::string       plotStyleName() const;
    PyDbObjectId      plotStyleNameId() const;
    Acad::ErrorStatus setPlotStyleName(const std::string& newName);
    Acad::ErrorStatus setPlotStyleName(const PyDbObjectId& newId);
    bool              isInUse() const;
    std::string       description() const;
    Acad::ErrorStatus setDescription(const std::string& description);
    bool              isHidden() const;
    Acad::ErrorStatus setIsHidden(bool on);
    static bool       isHiddenS(const PyDbObjectId& id);
    AcCmColor         color(const PyDbObjectId& viewportId) const;
    Acad::ErrorStatus setColor(const AcCmColor& color, const PyDbObjectId& viewportId);
    AcDb::LineWeight  lineWeight(const PyDbObjectId& viewportId) const;
    Acad::ErrorStatus setLineWeight(AcDb::LineWeight weight, const PyDbObjectId& viewportId);
    std::string       plotStyleName(const PyDbObjectId& viewportId) const;
    PyDbObjectId      plotStyleNameId(const PyDbObjectId& viewportId) const;
    Acad::ErrorStatus setPlotStyleName(const std::string& newName, const PyDbObjectId& viewportId);
    Acad::ErrorStatus setPlotStyleName(const PyDbObjectId& newId, const PyDbObjectId& viewportId);
    AcCmTransparency  transparency(const PyDbObjectId& viewportId) const;
    Acad::ErrorStatus setTransparency(const AcCmTransparency& trans, const PyDbObjectId& viewportId);
    Acad::ErrorStatus removeColorOverride(const PyDbObjectId& viewportId);
    Acad::ErrorStatus removeLinetypeOverride(const PyDbObjectId& viewportId);
    Acad::ErrorStatus removeLineWeightOverride(const PyDbObjectId& viewportId);
    Acad::ErrorStatus removePlotStyleOverride(const PyDbObjectId& viewportId);
    Acad::ErrorStatus removeTransparencyOverride(const PyDbObjectId& viewportId);
    Acad::ErrorStatus removeViewportOverrides(const PyDbObjectId& viewportId);
    Acad::ErrorStatus removeAllOverrides();
    bool              hasOverrides(const PyDbObjectId& viewportId) const;
    bool              hasAnyOverrides() const;
    bool              isReconciled() const;
    Acad::ErrorStatus setIsReconciled(bool bReconcile);
    static bool       isReconciledS(const PyDbObjectId& id);
    static std::string className();
    static PyRxClass  desc();
    static PyDbLayerTableRecord	cloneFrom(const PyRxObject& src);
    static PyDbLayerTableRecord cast(const PyRxObject& src);
public:
    AcDbLayerTableRecord* impObj(const std::source_location& src = std::source_location::current()) const;
};

//---------------------------------------------------------------------------------------- -
// PyDbTextStyleTableRecord
void makePyDbTextStyleTableRecordWrapper();
class PyDbTextStyleTableRecord : public PyDbSymbolTableRecord
{
public:
    PyDbTextStyleTableRecord();
    PyDbTextStyleTableRecord(AcDbTextStyleTableRecord* ptr, bool autoDelete);
    PyDbTextStyleTableRecord(const PyDbObjectId& id);
    PyDbTextStyleTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbTextStyleTableRecord() override = default;
    Adesk::Boolean      isShapeFile() const;
    void                setIsShapeFile(Adesk::Boolean shape);
    Adesk::Boolean      isVertical() const;
    void                setIsVertical(Adesk::Boolean vertical);
    double              textSize() const;
    Acad::ErrorStatus   setTextSize(double size);
    double              xScale() const;
    Acad::ErrorStatus   setXScale(double xScale);
    double              obliquingAngle() const;
    Acad::ErrorStatus   setObliquingAngle(double obliquingAngle);
    Adesk::UInt8        flagBits() const;
    void                setFlagBits(Adesk::UInt8 flagBits);
    double              priorSize() const;
    Acad::ErrorStatus   setPriorSize(double priorSize);
    std::string         fileName();
    Acad::ErrorStatus   setFileName(const std::string& path);
    std::string         bigFontFileName();
    Acad::ErrorStatus   setBigFontFileName(const std::string& path);
    Acad::ErrorStatus   setFont(const std::string& pTypeface, bool bold, bool italic, int charset, int pitch, int family, bool bAllowMissingFont);
    boost::python::tuple font();
public:
    static std::string  className();
    static PyRxClass    desc();
    static PyDbTextStyleTableRecord cloneFrom(const PyRxObject& src);
    static PyDbTextStyleTableRecord cast(const PyRxObject& src);
public:
    AcDbTextStyleTableRecord* impObj(const std::source_location& src = std::source_location::current()) const;
};

//---------------------------------------------------------------------------------------- -
// PyDbUCSTableRecord
void makePyDbUCSTableRecordWrapper();

class PyDbUCSTableRecord : public PyDbSymbolTableRecord
{
public:
    PyDbUCSTableRecord();
    PyDbUCSTableRecord(AcDbUCSTableRecord* ptr, bool autoDelete);
    PyDbUCSTableRecord(const PyDbObjectId& id);
    PyDbUCSTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbUCSTableRecord() override = default;
    AcGePoint3d         origin() const;
    void                setOrigin(const AcGePoint3d& newOrigin);
    AcGeVector3d        xAxis() const;
    void                setXAxis(const AcGeVector3d& xAxis);
    AcGeVector3d        yAxis() const;
    void                setYAxis(const AcGeVector3d& yAxis);
    AcGePoint3d         ucsBaseOrigin(AcDb::OrthographicView view) const;
    Acad::ErrorStatus   setUcsBaseOrigin(const AcGePoint3d& origin, AcDb::OrthographicView view);
public:
    static std::string  className();
    static PyRxClass    desc();
    static PyDbUCSTableRecord cloneFrom(const PyRxObject& src);
    static PyDbUCSTableRecord cast(const PyRxObject& src);
public:
    AcDbUCSTableRecord* impObj(const std::source_location& src = std::source_location::current()) const;
};

//---------------------------------------------------------------------------------------- -
// PyDbRegAppTableRecord
void makePyDbRegAppTableRecordWrapper();

class PyDbRegAppTableRecord : public PyDbSymbolTableRecord
{
public:
    PyDbRegAppTableRecord();
    PyDbRegAppTableRecord(AcDbRegAppTableRecord* ptr, bool autoDelete);
    PyDbRegAppTableRecord(const PyDbObjectId& id);
    PyDbRegAppTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbRegAppTableRecord() override = default;
public:
    static std::string  className();
    static PyRxClass    desc();
    static PyDbRegAppTableRecord cloneFrom(const PyRxObject& src);
    static PyDbRegAppTableRecord cast(const PyRxObject& src);
public:
    AcDbRegAppTableRecord* impObj(const std::source_location& src = std::source_location::current()) const;
};

//---------------------------------------------------------------------------------------- -
// PyDbLinetypeTableRecord
void makePyDbLinetypeTableRecordWrapper();

class PyDbLinetypeTableRecord : public PyDbSymbolTableRecord
{
public:
    PyDbLinetypeTableRecord();
    PyDbLinetypeTableRecord(AcDbLinetypeTableRecord* ptr, bool autoDelete);
    PyDbLinetypeTableRecord(const PyDbObjectId& id);
    PyDbLinetypeTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbLinetypeTableRecord() override = default;
    std::string         comments() const;
    Acad::ErrorStatus   setComments(const std::string& pstring);
    double              patternLength() const;
    Acad::ErrorStatus   setPatternLength(double patternLength);
    int                 numDashes() const;
    Acad::ErrorStatus   setNumDashes(int count);
    double              dashLengthAt(int index) const;
    Acad::ErrorStatus   setDashLengthAt(int index, double value);
    PyDbObjectId        shapeStyleAt(int index) const;
    Acad::ErrorStatus   setShapeStyleAt(int index, PyDbObjectId& id);
    int                 shapeNumberAt(int index) const;
    Acad::ErrorStatus   setShapeNumberAt(int index, int shapeNumber);
    AcGeVector2d        shapeOffsetAt(int index) const;
    Acad::ErrorStatus   setShapeOffsetAt(int index, const AcGeVector2d& offset);
    double              shapeScaleAt(int index) const;
    Acad::ErrorStatus   setShapeScaleAt(int index, double scale);
    bool                isScaledToFit() const;
    void                setIsScaledToFit(bool scaledToFit);
    bool                shapeIsUcsOrientedAt(int index) const;
    Acad::ErrorStatus   setShapeIsUcsOrientedAt(int index, bool isUcsOriented);
    bool                shapeIsUprightAt(int index) const;
    Acad::ErrorStatus   setShapeIsUprightAt(int index, bool isUpright);
    double              shapeRotationAt(int index) const;
    Acad::ErrorStatus   setShapeRotationAt(int index, double rotation);
    std::string         textAt(int index);
    Acad::ErrorStatus   setTextAt(int index, const std::string& pstring);

public:
    static std::string  className();
    static PyRxClass    desc();
    static PyDbLinetypeTableRecord cloneFrom(const PyRxObject& src);
    static PyDbLinetypeTableRecord cast(const PyRxObject& src);
public:
    AcDbLinetypeTableRecord* impObj(const std::source_location& src = std::source_location::current()) const;
};
