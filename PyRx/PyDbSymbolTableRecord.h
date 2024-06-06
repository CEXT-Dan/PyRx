#pragma once
#include "PyDbObject.h"
#include "PyDbObjectId.h"
#include "dbdynblk.h"

#pragma pack (push, 8)
class PyDbEntity;
class PyDbBlockBegin;
class PyDbBlockEnd;
class PyDbAnnotationScale;
class PyGsView;


void makePyDbSymbolTableRecordWrapper();

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
    void                setName(const std::string& name);
    bool                isDependent() const;
    bool                isResolved() const;
    bool                isRenamable() const;
    std::string         name();
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
void makePyDbDimStyleTableRecordWrapper();
class PyDbDimStyleTableRecord : public PyDbSymbolTableRecord
{
public:
    PyDbDimStyleTableRecord();
    PyDbDimStyleTableRecord(AcDbDimStyleTableRecord* ptr, bool autoDelete);
    PyDbDimStyleTableRecord(const PyDbObjectId& id);
    PyDbDimStyleTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbDimStyleTableRecord() override = default;

    PyDbObjectId     arrowId(AcDb::DimArrowFlags whichArrow) const;
    int              dimadec() const;
    bool             dimalt() const;
    int              dimaltd() const;
    double           dimaltf() const;
    double           dimaltrnd() const;
    int              dimalttd() const;
    int              dimalttz() const;
    int              dimaltu() const;
    int              dimaltz() const;
    std::string      dimapost() const;
    int              dimarcsym() const;
    double           dimasz() const;
    int              dimatfit() const;
    int              dimaunit() const;
    int              dimazin() const;
    PyDbObjectId     dimblk() const;
    PyDbObjectId     dimblk1() const;
    PyDbObjectId     dimblk2() const;
    double           dimcen() const;
    AcCmColor        dimclrd() const;
    AcCmColor        dimclre() const;
    AcCmColor        dimclrt() const;
    int              dimdec() const;
    double           dimdle() const;
    double           dimdli() const;
    char             dimdsep() const;
    double           dimexe() const;
    double           dimexo() const;
    int              dimfrac() const;
    double           dimgap() const;
    double           dimjogang() const;
    int              dimjust() const;
    PyDbObjectId     dimldrblk() const;
    double           dimlfac() const;
    bool             dimlim() const;
    PyDbObjectId     dimltex1() const;
    PyDbObjectId     dimltex2() const;
    PyDbObjectId     dimltype() const;
    int              dimlunit() const;
    AcDb::LineWeight dimlwd() const;
    AcDb::LineWeight dimlwe() const;
    std::string      dimpost() const;
    double           dimrnd() const;
    bool             dimsah() const;
    double           dimscale() const;
    bool             dimsd1() const;
    bool             dimsd2() const;
    bool             dimse1() const;
    bool             dimse2() const;
    bool             dimsoxd() const;
    int              dimtad() const;
    int              dimtdec() const;
    double           dimtfac() const;
    int              dimtfill() const;
    AcCmColor        dimtfillclr() const;
    bool             dimtih() const;
    bool             dimtix() const;
    double           dimtm() const;
    int              dimtmove() const;
    bool             dimtofl() const;
    bool             dimtoh() const;
    bool             dimtol() const;
    int              dimtolj() const;
    double           dimtp() const;
    double           dimtsz() const;
    double           dimtvp() const;
    PyDbObjectId     dimtxsty() const;
    double           dimtxt() const;
    int              dimtzin() const;
    bool             dimupt() const;
    int              dimzin() const;
    bool             dimfxlenOn() const;
    double           dimfxlen() const;
    bool             dimtxtdirection() const;
    double           dimmzf() const;
    std::string      dimmzs() const;
    double           dimaltmzf() const;
    std::string      dimaltmzs() const;

    void             setDimadec(int v);
    void             setDimalt(bool v);
    void             setDimaltd(int v);
    void             setDimaltf(double v);
    void             setDimaltmzf(double v);
    void             setDimaltmzs(const std::string& v);
    void             setDimaltrnd(double v);
    void             setDimalttd(int v);
    void             setDimalttz(int v);
    void             setDimaltu(int v);
    void             setDimaltz(int v);
    void             setDimapost(const std::string& v);
    void             setDimarcsym(int v);
    void             setDimasz(double v);
    void             setDimatfit(int v);
    void             setDimaunit(int v);
    void             setDimazin(int v);
    void             setDimblkId(const PyDbObjectId& v);
    void             setDimblk1Id(const PyDbObjectId& v);
    void             setDimblk2Id(const PyDbObjectId& v);
    void             setDimcen(double v);
    void             setDimclrd(const AcCmColor& v);
    void             setDimclre(const AcCmColor& v);
    void             setDimclrt(const AcCmColor& v);
    void             setDimdec(int v);
    void             setDimdle(double v);
    void             setDimdli(double v);
    void             setDimdsep(char v);
    void             setDimexe(double v);
    void             setDimexo(double v);
    void             setDimfrac(int v);
    void             setDimgap(double v);
    void             setDimjogang(double v);
    void             setDimjust(int v);
    void             setDimldrblkId(const PyDbObjectId& v);
    void             setDimlfac(double v);
    void             setDimlim(bool v);
    void             setDimltex1(const PyDbObjectId& v);
    void             setDimltex2(const PyDbObjectId& v);
    void             setDimltype(const PyDbObjectId& v);
    void             setDimlunit(int v);
    void             setDimlwd(AcDb::LineWeight v);
    void             setDimlwe(AcDb::LineWeight v);
    void             setDimmzf(double v);
    void             setDimmzs(const std::string& v);
    void             setDimpost(const std::string& v);
    void             setDimrnd(double v);
    void             setDimsah(bool v);
    void             setDimscale(double v);
    void             setDimsd1(bool v);
    void             setDimsd2(bool v);
    void             setDimse1(bool v);
    void             setDimse2(bool v);
    void             setDimsoxd(bool v);
    void             setDimtad(int v);
    void             setDimtdec(int v);
    void             setDimtfac(double v);
    void             setDimtfill(int v);
    void             setDimtfillclr(const AcCmColor& v);
    void             setDimtih(bool v);
    void             setDimtix(bool v);
    void             setDimtm(double v);
    void             setDimtmove(int v);
    void             setDimtofl(bool v);
    void             setDimtoh(bool v);
    void             setDimtol(bool v);
    void             setDimtolj(int v);
    void             setDimtp(double v);
    void             setDimtsz(double v);
    void             setDimtvp(double v);
    void             setDimtxsty(const PyDbObjectId& v);
    void             setDimtxt(double v);
    void             setDimtxtdirection(bool v);
    void             setDimtzin(int v);
    void             setDimupt(bool v);
    void             setDimzin(int v);
    void             setDimblk(const std::string& v);
    void             setDimblk1(const std::string& v);
    void             setDimblk2(const std::string& v);
    void             setDimldrblk(const std::string& v);
    void             setDimfxlenOn(bool v);
    void             setDimfxlen(double v);
    bool             isModifiedForRecompute() const;

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
#ifdef NEVER // this causes a linker error in AutoCAD
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
    void                setBackground(const PyDbObjectId& backgroundId);
    PyDbObjectId        visualStyle() const;
    void                setVisualStyle(const PyDbObjectId& visualStyleId);
    bool                isDefaultLightingOn() const;
    void                setDefaultLightingOn(bool on);
    AcGiViewportTraits::DefaultLightingType defaultLightingType() const;
    void                setDefaultLightingType(AcGiViewportTraits::DefaultLightingType typ);
    double              brightness() const;
    void                setBrightness(double val);
    double              contrast() const;
    void                setContrast(double val);
    AcCmColor           ambientLightColor() const;
    void                setAmbientLightColor(const AcCmColor& clr);
    PyDbObjectId        sunId() const;
    void                setSun1(PyDbObjectId& retId, PyDbObject& pSun);
    void                setSun2(PyDbObjectId& retId, PyDbObject& pSun, bool eraseOldSun);
    //void toneOperatorParameters(AcGiToneOperatorParameters& params) const;
    //void setToneOperatorParameters(const AcGiToneOperatorParameters& params);
    boost::python::tuple getUcs() const;
    boost::python::tuple isUcsOrthographic() const;
    PyDbObjectId        ucsName() const;
    double              elevation() const;
    void                setUcs1(const AcGePoint3d& origin, const AcGeVector3d& xAxis, const AcGeVector3d& yAxis);
    void                setUcs2(AcDb::OrthographicView view);
    void                setUcs3(const PyDbObjectId& ucsId);
    void                setUcsToWorld();
    void                setElevation(double elev);
    boost::python::tuple isViewOrthographic() const;
    void                setViewDirection2(AcDb::OrthographicView view);

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
    void                setGsView(PyGsView& pView);
    PyGsView            gsView() const;
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
    void                setBackground(const PyDbObjectId& backgroundId);
    PyDbObjectId        previousBackground1() const;
    PyDbObjectId        previousBackground2(AcGiDrawable::DrawableType type) const;
    void                setPreviousBackground1(PyDbObjectId& backgroundId);
    void                setPreviousBackground2(PyDbObjectId& backgroundId, AcGiDrawable::DrawableType type, bool bForcedSwitch);
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
    void                setParametersFromViewport(PyDbObjectId& objId);
    bool                isPaperspaceView() const;
    void                setIsPaperspaceView(bool pspace);
    bool                isUcsAssociatedToView() const;
    void                disassociateUcsFromView();
    std::string         getCategoryName() const;
    void                setCategoryName(const std::string& categoryName);
    std::string         getLayerState() const;
    void                setLayerState(const std::string& layerStateName);
    PyDbObjectId        getLayout() const;
    void                setLayout(const PyDbObjectId& layoutId);
    bool                isViewAssociatedToViewport() const;
    void                setViewAssociatedToViewport(bool bVPflag);
    bool                isCameraPlottable() const;
    void                setIsCameraPlottable(bool plottable);
    PyDbObjectId        liveSection() const;
    void                setLiveSection(const PyDbObjectId& liveSectionId);
    PyDbObjectId        camera() const;
    void                setCamera(const PyDbObjectId& cameraId);
    PyDbAnnotationScale annotationScale() const;
    void                setAnnotationScale(const PyDbAnnotationScale& pScaleObj);
    PyDbObjectId        sunId() const;
    void                setSun1(PyDbObjectId& retId, PyDbObject& pSun);
    void                setSun2(PyDbObjectId& retId, PyDbObject& pSun, bool eraseOldSun);

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
void makePyDbBlockTableRecordWrapper();
class PyDbBlockTableRecord : public PyDbSymbolTableRecord
{
public:
    PyDbBlockTableRecord();
    PyDbBlockTableRecord(AcDbBlockTableRecord* ptr, bool autoDelete);
    PyDbBlockTableRecord(const PyDbObjectId& id);
    PyDbBlockTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbBlockTableRecord() override = default;
    PyDbObjectId        appendAcDbEntity(const PyDbEntity& ent);
    boost::python::list appendAcDbEntities(const boost::python::list& entities);
    boost::python::list objectIds();
    boost::python::list objectIdsOfType(const PyRxClass& _class);
    std::string         comments();
    void                setComments(const std::string& pString);
    std::string         pathName();
    void                setPathName(const std::string& pString);
    AcGePoint3d         origin() const;
    void                setOrigin(const AcGePoint3d& pt);
    void                openBlockBegin(PyDbBlockBegin& pBlockBegin, AcDb::OpenMode openMode);
    void                openBlockEnd(PyDbBlockEnd& pBlockBegin, AcDb::OpenMode openMode);
    bool                hasAttributeDefinitions() const;
    bool                  hasPreviewIcon() const;
    boost::python::object getPreviewIcon() const;
    void                clearPreviewIcon() const;
    bool                isAnonymous() const;
    bool                isDynamicBlock();
    bool                isFromExternalReference() const;
    bool                isFromOverlayReference() const;
    void                setIsFromOverlayReference(bool bIsOverlay);
    bool                isLayout() const;
    PyDbObjectId        getLayoutId() const;
    void                setLayoutId(const PyDbObjectId& id);
    boost::python::list getBlockReferenceIds1();
    boost::python::list getBlockReferenceIds2(bool bDirectOnly, bool bForceValidity);
    boost::python::list getErasedBlockReferenceIds();
    PyDbDatabase        xrefDatabase(bool incUnres) const;
    bool                isUnloaded() const;
    void                setIsUnloaded(bool isUnloaded);
    AcDb::XrefStatus    xrefStatus() const;
    virtual void        assumeOwnershipOf(const  boost::python::list& entitiesToMove);
    AcDbBlockTableRecord::BlockScaling blockScaling() const;
    void                setBlockScaling(AcDbBlockTableRecord::BlockScaling blockScaling);
    void                setExplodable(bool bExplodable);
    bool                explodable() const;
    void                setBlockInsertUnits(AcDb::UnitsValue insunits);
    AcDb::UnitsValue    blockInsertUnits() const;
    int                 postProcessAnnotativeBTR(bool bqueryOnly, bool bScale);
    void                addAnnoScalestoBlkRefs(bool bScale);
    static std::string  className();
    static PyRxClass    desc();
    static PyDbBlockTableRecord	cloneFrom(const PyRxObject& src);
    static PyDbBlockTableRecord cast(const PyRxObject& src);
public:
    AcDbBlockTableRecord* impObj(const std::source_location& src = std::source_location::current()) const;

    // TODO: iterator buffer, I don't know how to expose AcDbBlockTableRecordIterator
    // memory hog? at least we're in cache... BTY. end is called first
    void filliterator();
    std::vector<PyDbObjectId>::iterator begin();
    std::vector<PyDbObjectId>::iterator end();
    std::vector<PyDbObjectId> m_iterable{ 0 };
};


//---------------------------------------------------------------------------------------- -
// PyDbDynBlockTableRecord

#if defined(_BRXTARGET) && (_BRXTARGET <= 240)
class AcDbDynBlockTableRecord
{
public:
    AcDbDynBlockTableRecord(const AcDbObjectId& id)
    {
    }
    bool isDynamicBlock() const
    {
        throw PyNotimplementedByHost();
        return false;
    }
};
#endif

void makePyDbDynBlockTableRecordWrapper();
class PyAcDbDynBlockTableRecord
{
public:
    PyAcDbDynBlockTableRecord(const PyDbObjectId& id);
    bool                isDynamicBlock() const;
    PyDbObjectId        blockTableRecordId() const;
    boost::python::list getAnonymousBlockIds() const;
    void                updateAnonymousBlocks() const;
    static bool         getIsDynamicBlock(const PyDbBlockTableRecord& pBlockTableRecord);
    static std::string  className();
public:
    inline AcDbDynBlockTableRecord* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<AcDbDynBlockTableRecord> m_imp;
};


//---------------------------------------------------------------------------------------- -
// PyDbLayerTableRecord
void makePyDbLayerTableRecordWrapper();
class PyDbLayerTableRecord : public PyDbSymbolTableRecord
{
public:
    PyDbLayerTableRecord();
    PyDbLayerTableRecord(AcDbLayerTableRecord* ptr, bool autoDelete);
    PyDbLayerTableRecord(const PyDbObjectId& id);
    PyDbLayerTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbLayerTableRecord() override = default;
    bool              isFrozen() const;
    void              setIsFrozen(bool frozen);
    bool              isOff() const;
    void              setIsOff(bool off);
    bool              VPDFLT() const;
    void              setVPDFLT(bool frozen);
    bool              isLocked() const;
    void              setIsLocked(bool locked);
    AcCmColor         color1() const;
    void              setColor1(const AcCmColor& color);
    AcCmEntityColor   entityColor(void) const;
    AcCmTransparency  transparency1(void) const;
    void              setTransparency1(const AcCmTransparency& trans);
    PyDbObjectId      linetypeObjectId() const;
    void              setLinetypeObjectId(const PyDbObjectId& id);
    PyDbObjectId      materialId() const;
    void              setMaterialId(const PyDbObjectId& id);
    bool              isPlottable() const;
    void              setIsPlottable(bool plot);
    AcDb::LineWeight  lineWeight1() const;
    void              setLineWeight1(AcDb::LineWeight weight);
    std::string       plotStyleName1() const;
    PyDbObjectId      plotStyleNameId1() const;
    void              setPlotStyleName1(const std::string& newName);
    void              setPlotStyleName2(const PyDbObjectId& newId);
    bool              isInUse() const;
    std::string       description() const;
    void              setDescription(const std::string& description);
    bool              isHidden() const;
    void              setIsHidden(bool on);
    static bool       isHiddenS(const PyDbObjectId& id);
    AcCmColor         color2(const PyDbObjectId& viewportId) const;
    void              setColor2(const AcCmColor& color, const PyDbObjectId& viewportId);
    AcDb::LineWeight  lineWeight2(const PyDbObjectId& viewportId) const;
    void              setLineWeight2(AcDb::LineWeight weight, const PyDbObjectId& viewportId);
    std::string       plotStyleName2(const PyDbObjectId& viewportId) const;
    PyDbObjectId      plotStyleNameId2(const PyDbObjectId& viewportId) const;
    void              setPlotStyleName3(const std::string& newName, const PyDbObjectId& viewportId);
    void              setPlotStyleName4(const PyDbObjectId& newId, const PyDbObjectId& viewportId);
    AcCmTransparency  transparency2(const PyDbObjectId& viewportId) const;
    void              setTransparency2(const AcCmTransparency& trans, const PyDbObjectId& viewportId);
    void              removeColorOverride(const PyDbObjectId& viewportId);
    void              removeLinetypeOverride(const PyDbObjectId& viewportId);
    void              removeLineWeightOverride(const PyDbObjectId& viewportId);
    void              removePlotStyleOverride(const PyDbObjectId& viewportId);
    void              removeTransparencyOverride(const PyDbObjectId& viewportId);
    void              removeViewportOverrides(const PyDbObjectId& viewportId);
    void              removeAllOverrides();
    bool              hasOverrides(const PyDbObjectId& viewportId) const;
    bool              hasAnyOverrides() const;
    bool              isReconciled() const;
    void              setIsReconciled(bool bReconcile);
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
    void                setTextSize(double size);
    double              xScale() const;
    void                setXScale(double xScale);
    double              obliquingAngle() const;
    void                setObliquingAngle(double obliquingAngle);
    Adesk::UInt8        flagBits() const;
    void                setFlagBits(Adesk::UInt8 flagBits);
    double              priorSize() const;
    void                setPriorSize(double priorSize);
    std::string         fileName();
    void                setFileName(const std::string& path);
    std::string         bigFontFileName();
    void                setBigFontFileName(const std::string& path);
    void                setFont(const std::string& pTypeface, bool bold, bool italic, int charset, int pitch, int family, bool bAllowMissingFont);
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
    void                setUcsBaseOrigin(const AcGePoint3d& origin, AcDb::OrthographicView view);
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
    void                setComments(const std::string& pstring);
    double              patternLength() const;
    void                setPatternLength(double patternLength);
    int                 numDashes() const;
    void                setNumDashes(int count);
    double              dashLengthAt(int index) const;
    void                setDashLengthAt(int index, double value);
    PyDbObjectId        shapeStyleAt(int index) const;
    void                setShapeStyleAt(int index, PyDbObjectId& id);
    int                 shapeNumberAt(int index) const;
    void                setShapeNumberAt(int index, int shapeNumber);
    AcGeVector2d        shapeOffsetAt(int index) const;
    void                setShapeOffsetAt(int index, const AcGeVector2d& offset);
    double              shapeScaleAt(int index) const;
    void                setShapeScaleAt(int index, double scale);
    bool                isScaledToFit() const;
    void                setIsScaledToFit(bool scaledToFit);
    bool                shapeIsUcsOrientedAt(int index) const;
    void                setShapeIsUcsOrientedAt(int index, bool isUcsOriented);
    bool                shapeIsUprightAt(int index) const;
    void                setShapeIsUprightAt(int index, bool isUpright);
    double              shapeRotationAt(int index) const;
    void                setShapeRotationAt(int index, double rotation);
    std::string         textAt(int index);
    void                setTextAt(int index, const std::string& pstring);

public:
    static std::string  className();
    static PyRxClass    desc();
    static PyDbLinetypeTableRecord cloneFrom(const PyRxObject& src);
    static PyDbLinetypeTableRecord cast(const PyRxObject& src);
public:
    AcDbLinetypeTableRecord* impObj(const std::source_location& src = std::source_location::current()) const;
};
#pragma pack (pop)
