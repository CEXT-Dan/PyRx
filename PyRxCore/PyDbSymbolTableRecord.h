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
    PyDbSymbolTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    virtual ~PyDbSymbolTableRecord() override = default;
    std::string         getName() const;
    void                setName(const std::string& name) const;
    bool                isDependent() const;
    bool                isResolved() const;
    bool                isRenamable() const;
    std::string         name() const;
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
    PyDbDimStyleTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
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

    void             setDimadec(int v) const;
    void             setDimalt(bool v) const;
    void             setDimaltd(int v) const;
    void             setDimaltf(double v) const;
    void             setDimaltmzf(double v) const;
    void             setDimaltmzs(const std::string& v) const;
    void             setDimaltrnd(double v) const;
    void             setDimalttd(int v) const;
    void             setDimalttz(int v) const;
    void             setDimaltu(int v) const;
    void             setDimaltz(int v) const;
    void             setDimapost(const std::string& v) const;
    void             setDimarcsym(int v) const;
    void             setDimasz(double v) const;
    void             setDimatfit(int v) const;
    void             setDimaunit(int v) const;
    void             setDimazin(int v) const;
    void             setDimblkId(const PyDbObjectId& v) const;
    void             setDimblk1Id(const PyDbObjectId& v) const;
    void             setDimblk2Id(const PyDbObjectId& v) const;
    void             setDimcen(double v) const;
    void             setDimclrd(const AcCmColor& v) const;
    void             setDimclre(const AcCmColor& v) const;
    void             setDimclrt(const AcCmColor& v) const;
    void             setDimdec(int v) const;
    void             setDimdle(double v) const;
    void             setDimdli(double v) const;
    void             setDimdsep(char v) const;
    void             setDimexe(double v) const;
    void             setDimexo(double v) const;
    void             setDimfrac(int v) const;
    void             setDimgap(double v) const;
    void             setDimjogang(double v) const;
    void             setDimjust(int v) const;
    void             setDimldrblkId(const PyDbObjectId& v) const;
    void             setDimlfac(double v) const;
    void             setDimlim(bool v) const;
    void             setDimltex1(const PyDbObjectId& v) const;
    void             setDimltex2(const PyDbObjectId& v) const;
    void             setDimltype(const PyDbObjectId& v) const;
    void             setDimlunit(int v) const;
    void             setDimlwd(AcDb::LineWeight v) const;
    void             setDimlwe(AcDb::LineWeight v) const;
    void             setDimmzf(double v) const;
    void             setDimmzs(const std::string& v) const;
    void             setDimpost(const std::string& v) const;
    void             setDimrnd(double v) const;
    void             setDimsah(bool v) const;
    void             setDimscale(double v) const;
    void             setDimsd1(bool v) const;
    void             setDimsd2(bool v) const;
    void             setDimse1(bool v) const;
    void             setDimse2(bool v) const;
    void             setDimsoxd(bool v) const;
    void             setDimtad(int v) const;
    void             setDimtdec(int v) const;
    void             setDimtfac(double v) const;
    void             setDimtfill(int v) const;
    void             setDimtfillclr(const AcCmColor& v) const;
    void             setDimtih(bool v) const;
    void             setDimtix(bool v) const;
    void             setDimtm(double v) const;
    void             setDimtmove(int v) const;
    void             setDimtofl(bool v) const;
    void             setDimtoh(bool v) const;
    void             setDimtol(bool v) const;
    void             setDimtolj(int v) const;
    void             setDimtp(double v) const;
    void             setDimtsz(double v) const;
    void             setDimtvp(double v) const;
    void             setDimtxsty(const PyDbObjectId& v) const;
    void             setDimtxt(double v) const;
    void             setDimtxtdirection(bool v) const;
    void             setDimtzin(int v) const;
    void             setDimupt(bool v) const;
    void             setDimzin(int v) const;
    void             setDimblk(const std::string& v) const;
    void             setDimblk1(const std::string& v) const;
    void             setDimblk2(const std::string& v) const;
    void             setDimldrblk(const std::string& v) const;
    void             setDimfxlenOn(bool v) const;
    void             setDimfxlen(double v) const;
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
    PyDbAbstractViewTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    virtual ~PyDbAbstractViewTableRecord() override = default;
    AcGePoint2d         centerPoint() const;
    void                setCenterPoint(const AcGePoint2d& val) const;
    double              height() const;
    void                setHeight(double val) const;
    double              width() const;
    void                setWidth(double val) const;
    AcGePoint3d         target() const;
    void                setTarget(const AcGePoint3d& target) const;
    AcGeVector3d        viewDirection() const;
    void                setViewDirection1(const AcGeVector3d& viewDirection) const;
    double              viewTwist() const;
    void                setViewTwist(double angle) const;
    double              lensLength() const;
    void                setLensLength(double length) const;
    double              frontClipDistance() const;
    void                setFrontClipDistance(double distance) const;
    double              backClipDistance() const;
    void                setBackClipDistance(double distance) const;
    bool                perspectiveEnabled() const;
    void                setPerspectiveEnabled(bool enabled) const;
    bool                frontClipEnabled() const;
    void                setFrontClipEnabled(bool enabled) const;
    bool                backClipEnabled() const;
    void                setBackClipEnabled(bool enabled) const;
    bool                frontClipAtEye() const;
    void                setFrontClipAtEye(bool atEye) const;
    PyDbObjectId        background() const;
    void                setBackground(const PyDbObjectId& backgroundId) const;
    PyDbObjectId        visualStyle() const;
    void                setVisualStyle(const PyDbObjectId& visualStyleId) const;
    bool                isDefaultLightingOn() const;
    void                setDefaultLightingOn(bool on) const;
    AcGiViewportTraits::DefaultLightingType defaultLightingType() const;
    void                setDefaultLightingType(AcGiViewportTraits::DefaultLightingType typ) const;
    double              brightness() const;
    void                setBrightness(double val) const;
    double              contrast() const;
    void                setContrast(double val) const;
    AcCmColor           ambientLightColor() const;
    void                setAmbientLightColor(const AcCmColor& clr) const;
    PyDbObjectId        sunId() const;
    void                setSun1(PyDbObjectId& retId, PyDbObject& pSun) const;
    void                setSun2(PyDbObjectId& retId, PyDbObject& pSun, bool eraseOldSun) const;
    //void toneOperatorParameters(AcGiToneOperatorParameters& params) const;
    //void setToneOperatorParameters(const AcGiToneOperatorParameters& params) const;
    boost::python::tuple getUcs() const;
    boost::python::tuple isUcsOrthographic() const;
    PyDbObjectId        ucsName() const;
    double              elevation() const;
    void                setUcs1(const AcGePoint3d& origin, const AcGeVector3d& xAxis, const AcGeVector3d& yAxis) const;
    void                setUcs2(AcDb::OrthographicView view) const;
    void                setUcs3(const PyDbObjectId& ucsId) const;
    void                setUcsToWorld() const;
    void                setElevation(double elev) const;
    boost::python::tuple isViewOrthographic() const;
    void                setViewDirection2(AcDb::OrthographicView view) const;

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
    PyDbViewportTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    virtual ~PyDbViewportTableRecord() override = default;
    Adesk::Int16        number()  const;
    AcGePoint2d         lowerLeftCorner() const;
    void                setLowerLeftCorner(const AcGePoint2d& pt) const;
    AcGePoint2d         upperRightCorner() const;
    void                setUpperRightCorner(const AcGePoint2d& pt) const;
    bool                ucsFollowMode() const;
    void                setUcsFollowMode(bool enabled) const;
    Adesk::UInt16       circleSides() const;
    void                setCircleSides(Adesk::UInt16 circleSides) const;
    bool                fastZoomsEnabled() const;
    void                setFastZoomsEnabled(bool enabled) const;
    bool                iconEnabled() const;
    void                setIconEnabled(bool enabled) const;
    bool                iconAtOrigin() const;
    void                setIconAtOrigin(bool atOrigin) const;
    bool                gridEnabled() const;
    void                setGridEnabled(bool enabled) const;
    AcGePoint2d         gridIncrements() const;
    void                setGridIncrements(const AcGePoint2d& base) const;
    bool                snapEnabled() const;
    void                setSnapEnabled(bool enabled) const;
    bool                isometricSnapEnabled() const;
    void                setIsometricSnapEnabled(bool enabled) const;
    Adesk::Int16        snapPair() const;
    void                setSnapPair(Adesk::Int16 pairType) const;
    double              snapAngle() const;
    void                setSnapAngle(double angle) const;
    AcGePoint2d         snapBase() const;
    void                setSnapBase(const AcGePoint2d& base) const;
    AcGePoint2d         snapIncrements() const;
    void                setSnapIncrements(const AcGePoint2d& base) const;
    void                setGsView(PyGsView& pView) const;
    PyGsView            gsView() const;
    bool                isUcsSavedWithViewport() const;
    void                setUcsPerViewport(bool ucsvp) const;
    bool                isGridBoundToLimits() const;
    void                setGridBoundToLimits(bool enabled) const;
    bool                isGridAdaptive() const;
    void                setGridAdaptive(bool enabled) const;
    bool                isGridSubdivisionRestricted() const;
    void                setGridSubdivisionRestricted(bool enabled) const;
    bool                isGridFollow() const;
    void                setGridFollow(bool enabled) const;
    Adesk::Int16        gridMajor() const;
    void                setGridMajor(Adesk::Int16 value) const;
    void                setBackground(const PyDbObjectId& backgroundId) const;
    PyDbObjectId        previousBackground1() const;
    PyDbObjectId        previousBackground2(AcGiDrawable::DrawableType type) const;
    void                setPreviousBackground1(PyDbObjectId& backgroundId) const;
    void                setPreviousBackground2(PyDbObjectId& backgroundId, AcGiDrawable::DrawableType type, bool bForcedSwitch) const;
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
    PyDbViewTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    virtual ~PyDbViewTableRecord() override = default;
    void                setParametersFromViewport(PyDbObjectId& objId) const;
    bool                isPaperspaceView() const;
    void                setIsPaperspaceView(bool pspace) const;
    bool                isUcsAssociatedToView() const;
    void                disassociateUcsFromView() const;
    std::string         getCategoryName() const;
    void                setCategoryName(const std::string& categoryName) const;
    std::string         getLayerState() const;
    void                setLayerState(const std::string& layerStateName) const;
    PyDbObjectId        getLayout() const;
    void                setLayout(const PyDbObjectId& layoutId) const;
    bool                isViewAssociatedToViewport() const;
    void                setViewAssociatedToViewport(bool bVPflag) const;
    bool                isCameraPlottable() const;
    void                setIsCameraPlottable(bool plottable) const;
    PyDbObjectId        liveSection() const;
    void                setLiveSection(const PyDbObjectId& liveSectionId) const;
    PyDbObjectId        camera() const;
    void                setCamera(const PyDbObjectId& cameraId) const;
    PyDbAnnotationScale annotationScale() const;
    void                setAnnotationScale(const PyDbAnnotationScale& pScaleObj) const;
    PyDbObjectId        sunId() const;
    void                setSun1(PyDbObjectId& retId, PyDbObject& pSun) const;
    void                setSun2(PyDbObjectId& retId, PyDbObject& pSun, bool eraseOldSun) const;

public:
    static std::string className();
    static PyRxClass desc();
    static PyDbViewTableRecord cloneFrom(const PyRxObject& src);
    static PyDbViewTableRecord cast(const PyRxObject& src);
public:
    AcDbViewTableRecord* impObj(const std::source_location& src = std::source_location::current()) const;
};

//---------------------------------------------------------------------------------------- -
// PyDbSortentsTable
void makePyDbSortentsTableWrapper();
class PyDbSortentsTable : public PyDbObject
{
public:
    PyDbSortentsTable();
    PyDbSortentsTable(const PyDbObjectId& id);
    PyDbSortentsTable(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbSortentsTable(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    PyDbSortentsTable(AcDbSortentsTable* ptr, bool autoDelete);
    virtual ~PyDbSortentsTable() override = default;
    boost::python::tuple        sortAs(const PyDbObjectId& id) const;
    PyDbHandle                  getSortHandle(const PyDbObjectId& id) const;
    void                        remove(const PyDbObjectId& id) const;
    void                        moveToBottom(const boost::python::object& pylist) const;
    void                        moveToTop(const boost::python::object& pylist) const;
    void                        moveBelow(const boost::python::object& pylist, const PyDbObjectId& target) const;
    void                        moveAbove(const boost::python::object& pylist, const PyDbObjectId& target) const;
    void                        swapOrder(const PyDbObjectId& left, const PyDbObjectId& right) const;
    void                        setBlockId(const PyDbObjectId& id) const;
    PyDbObjectId                blockId() const;
    bool                        firstEntityIsDrawnBeforeSecond(const PyDbObjectId& first, const PyDbObjectId& second) const;
    boost::python::list         getFullDrawOrder(int mask) const;
    boost::python::list         getRelativeDrawOrder(int mask) const;
    void                        setRelativeDrawOrder(const boost::python::object& pylist) const;
    static std::string          className();
    static PyRxClass            desc();
    static PyDbSortentsTable	cloneFrom(const PyRxObject& src);
    static PyDbSortentsTable    cast(const PyRxObject& src);
public:
    inline AcDbSortentsTable* impObj(const std::source_location& src = std::source_location::current()) const;
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
    PyDbBlockTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    virtual ~PyDbBlockTableRecord() override = default;
    PyDbObjectId        appendAcDbEntity(const PyDbEntity& ent) const;
    boost::python::list appendAcDbEntities(const boost::python::object& entities) const;
    boost::python::list objectIds() const;
    boost::python::list objectIdsOfType(const PyRxClass& _class) const;
    boost::python::list objectIdsOfTypeList(const boost::python::list& _classes) const;//must be list
    PyDbObjectIdArray   objectIdArray1() const;
    PyDbObjectIdArray   objectIdArray2(const PyRxClass& _class) const;
    PyDbObjectIdArray   objectIdArray3(const boost::python::list& _classes) const;
    std::string         comments() const;
    void                setComments(const std::string& pString) const;
    std::string         pathName() const;
    void                setPathName(const std::string& pString) const;
    AcGePoint3d         origin() const;
    void                setOrigin(const AcGePoint3d& pt) const;
    void                openBlockBegin(PyDbBlockBegin& pBlockBegin, AcDb::OpenMode openMode) const;
    void                openBlockEnd(PyDbBlockEnd& pBlockBegin, AcDb::OpenMode openMode) const;
    bool                hasAttributeDefinitions() const;
    bool                  hasPreviewIcon() const;
    boost::python::object getPreviewIcon() const;
    void                clearPreviewIcon() const;
    bool                isAnonymous() const;
    bool                isDynamicBlock() const;
    bool                isFromExternalReference() const;
    bool                isFromOverlayReference() const;
    void                setIsFromOverlayReference(bool bIsOverlay) const;
    bool                isLayout() const;
    PyDbObjectId        getLayoutId() const;
    void                setLayoutId(const PyDbObjectId& id) const;
    boost::python::list getBlockReferenceIds1() const;
    boost::python::list getBlockReferenceIds2(bool bDirectOnly, bool bForceValidity) const;
    boost::python::list getErasedBlockReferenceIds() const;
    PyDbDatabase        xrefDatabase(bool incUnres) const;
    bool                isUnloaded() const;
    void                setIsUnloaded(bool isUnloaded) const;
    AcDb::XrefStatus    xrefStatus() const;
    virtual void        assumeOwnershipOf(const  boost::python::object& entitiesToMove) const;
    AcDbBlockTableRecord::BlockScaling blockScaling() const;
    void                setBlockScaling(AcDbBlockTableRecord::BlockScaling blockScaling) const;
    void                setExplodable(bool bExplodable) const;
    bool                explodable() const;
    void                setBlockInsertUnits(AcDb::UnitsValue insunits) const;
    AcDb::UnitsValue    blockInsertUnits() const;
    int                 postProcessAnnotativeBTR(bool bqueryOnly, bool bScale) const;
    void                addAnnoScalestoBlkRefs(bool bScale) const;
    PyDbSortentsTable   getSortentsTable1() const;
    PyDbSortentsTable   getSortentsTable2(AcDb::OpenMode openMode, bool createIfNecessary) const;
    std::string         effectiveName() const;

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
#if _BRXTARGET250
class AcDbDynBlockTableRecord
{
public:
    AcDbDynBlockTableRecord(const AcDbObjectId& id)
    {
        throw PyNotimplementedByHost();
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
    static bool         getIsDynamicBlock1(const PyDbObjectId& id);
    static bool         getIsDynamicBlock2(const PyDbBlockTableRecord& pBlockTableRecord);
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
    PyDbLayerTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    virtual ~PyDbLayerTableRecord() override = default;
    bool              isFrozen() const;
    void              setIsFrozen(bool frozen) const;
    bool              isOff() const;
    void              setIsOff(bool off) const;
    bool              VPDFLT() const;
    void              setVPDFLT(bool frozen) const;
    bool              isLocked() const;
    void              setIsLocked(bool locked) const;
    AcCmColor         color1() const;
    void              setColor1(const AcCmColor& color) const;
    AcCmEntityColor   entityColor(void) const;
    AcCmTransparency  transparency1(void) const;
    void              setTransparency1(const AcCmTransparency& trans) const;
    PyDbObjectId      linetypeObjectId() const;
    void              setLinetypeObjectId(const PyDbObjectId& id) const;
    PyDbObjectId      materialId() const;
    void              setMaterialId(const PyDbObjectId& id) const;
    bool              isPlottable() const;
    void              setIsPlottable(bool plot) const;
    AcDb::LineWeight  lineWeight1() const;
    void              setLineWeight1(AcDb::LineWeight weight) const;
    std::string       plotStyleName1() const;
    PyDbObjectId      plotStyleNameId1() const;
    void              setPlotStyleName1(const std::string& newName) const;
    void              setPlotStyleName2(const PyDbObjectId& newId) const;
    bool              isInUse() const;
    std::string       description() const;
    void              setDescription(const std::string& description) const;
    bool              isHidden() const;
    void              setIsHidden(bool on) const;
    static bool       isHiddenS(const PyDbObjectId& id);
    AcCmColor         color2(const PyDbObjectId& viewportId) const;
    void              setColor2(const AcCmColor& color, const PyDbObjectId& viewportId) const;
    AcDb::LineWeight  lineWeight2(const PyDbObjectId& viewportId) const;
    void              setLineWeight2(AcDb::LineWeight weight, const PyDbObjectId& viewportId) const;
    std::string       plotStyleName2(const PyDbObjectId& viewportId) const;
    PyDbObjectId      plotStyleNameId2(const PyDbObjectId& viewportId) const;
    void              setPlotStyleName3(const std::string& newName, const PyDbObjectId& viewportId) const;
    void              setPlotStyleName4(const PyDbObjectId& newId, const PyDbObjectId& viewportId) const;
    AcCmTransparency  transparency2(const PyDbObjectId& viewportId) const;
    void              setTransparency2(const AcCmTransparency& trans, const PyDbObjectId& viewportId) const;
    void              removeColorOverride(const PyDbObjectId& viewportId) const;
    void              removeLinetypeOverride(const PyDbObjectId& viewportId) const;
    void              removeLineWeightOverride(const PyDbObjectId& viewportId) const;
    void              removePlotStyleOverride(const PyDbObjectId& viewportId) const;
    void              removeTransparencyOverride(const PyDbObjectId& viewportId) const;
    void              removeViewportOverrides(const PyDbObjectId& viewportId) const;
    void              removeAllOverrides() const;
    bool              hasOverrides(const PyDbObjectId& viewportId) const;
    bool              hasAnyOverrides() const;
    bool              isReconciled() const;
    void              setIsReconciled(bool bReconcile) const;
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
    PyDbTextStyleTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    virtual ~PyDbTextStyleTableRecord() override = default;
    Adesk::Boolean      isShapeFile() const;
    void                setIsShapeFile(Adesk::Boolean shape) const;
    Adesk::Boolean      isVertical() const;
    void                setIsVertical(Adesk::Boolean vertical) const;
    double              textSize() const;
    void                setTextSize(double size) const;
    double              xScale() const;
    void                setXScale(double xScale) const;
    double              obliquingAngle() const;
    void                setObliquingAngle(double obliquingAngle) const;
    Adesk::UInt8        flagBits() const;
    void                setFlagBits(Adesk::UInt8 flagBits) const;
    double              priorSize() const;
    void                setPriorSize(double priorSize) const;
    std::string         fileName() const;
    void                setFileName(const std::string& path) const;
    std::string         bigFontFileName() const;
    void                setBigFontFileName(const std::string& path) const;
    void                setFont(const std::string& pTypeface, bool bold, bool italic, int charset, int pitch, int family, bool bAllowMissingFont) const;
    boost::python::tuple font() const;
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
    PyDbUCSTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    virtual ~PyDbUCSTableRecord() override = default;
    AcGePoint3d         origin() const;
    void                setOrigin(const AcGePoint3d& newOrigin) const;
    AcGeVector3d        xAxis() const;
    void                setXAxis(const AcGeVector3d& xAxis) const;
    AcGeVector3d        yAxis() const;
    void                setYAxis(const AcGeVector3d& yAxis) const;
    AcGePoint3d         ucsBaseOrigin(AcDb::OrthographicView view) const;
    void                setUcsBaseOrigin(const AcGePoint3d& origin, AcDb::OrthographicView view) const;
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
    PyDbRegAppTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
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
    PyDbLinetypeTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    virtual ~PyDbLinetypeTableRecord() override = default;
    std::string         comments() const;
    void                setComments(const std::string& pstring) const;
    double              patternLength() const;
    void                setPatternLength(double patternLength) const;
    int                 numDashes() const;
    void                setNumDashes(int count) const;
    double              dashLengthAt(int index) const;
    void                setDashLengthAt(int index, double value) const;
    PyDbObjectId        shapeStyleAt(int index) const;
    void                setShapeStyleAt(int index, PyDbObjectId& id) const;
    int                 shapeNumberAt(int index) const;
    void                setShapeNumberAt(int index, int shapeNumber) const;
    AcGeVector2d        shapeOffsetAt(int index) const;
    void                setShapeOffsetAt(int index, const AcGeVector2d& offset) const;
    double              shapeScaleAt(int index) const;
    void                setShapeScaleAt(int index, double scale) const;
    bool                isScaledToFit() const;
    void                setIsScaledToFit(bool scaledToFit) const;
    bool                shapeIsUcsOrientedAt(int index) const;
    void                setShapeIsUcsOrientedAt(int index, bool isUcsOriented) const;
    bool                shapeIsUprightAt(int index) const;
    void                setShapeIsUprightAt(int index, bool isUpright) const;
    double              shapeRotationAt(int index) const;
    void                setShapeRotationAt(int index, double rotation) const;
    std::string         textAt(int index) const;
    void                setTextAt(int index, const std::string& pstring) const;

public:
    static std::string  className();
    static PyRxClass    desc();
    static PyDbLinetypeTableRecord cloneFrom(const PyRxObject& src);
    static PyDbLinetypeTableRecord cast(const PyRxObject& src);
public:
    AcDbLinetypeTableRecord* impObj(const std::source_location& src = std::source_location::current()) const;
};
#pragma pack (pop)
