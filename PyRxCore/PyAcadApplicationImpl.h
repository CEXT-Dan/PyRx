#pragma once
#include "PyAcadEntityImpl.h "
#include "PyAcadDimensionImpl.h"
#include "PyAcadTableImpl.h"

class PyIAcadDocumentsImpl;
using PyIAcadDocumentsPtr = std::unique_ptr<PyIAcadDocumentsImpl>;
class PyIAcadSelectionSetImpl;
using PyIAcadSelectionSetPtr = std::unique_ptr<PyIAcadSelectionSetImpl>;
class PyIAcadSelectionSetsImpl;
using PyIAcadSelectionSetsPtr = std::unique_ptr<PyIAcadSelectionSetsImpl>;
class PyIAcadUtilityImpl;
using PyIAcadUtilityPtr = std::unique_ptr<PyIAcadUtilityImpl>;
class PyIAcadSecurityParamsImpl;
using PyIAcadSecurityParamsPtr = std::unique_ptr<PyIAcadSecurityParamsImpl>;
using PyIAcadRegionPtrArray = std::vector<std::shared_ptr<PyIAcadRegionImpl>>;

//------------------------------------------------------------------------------------
//PyIAcadBlockImpl
class PyIAcadBlockImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadBlockImpl(IAcadBlock* ptr);
    virtual ~PyIAcadBlockImpl() = default;
    PyIAcadEntityPtr            GetItem(long ind) const;
    long                        GetCount() const;
    PyIAcadEntityPtrArray       GetIter() const;
    CString                     GetName() const;
    void                        SetName(const CString& val) const;
    AcGePoint3d                 GetOrigin() const;
    void                        SetOrigin(const AcGePoint3d& val) const;
    void                        Unload() const;
    void                        Reload() const;
    void                        Bind(bool bPrefixName) const;
    void                        Detach() const;
    PyIAcadDatabasePtr          GetXRefDatabase() const;
    CString                     GetPath() const;
    void                        SetPath(const CString& val) const;
    CString                     GetComments() const;
    void                        SetComments(const CString& val) const;
    PyAcInsertUnits             GetUnits() const;
    void                        SetUnits(PyAcInsertUnits val) const;
    bool                        GetExplodable() const;
    void                        SetExplodable(bool val) const;
    PyAcBlockScaling            GetBlockScaling() const;
    void                        SetBlockScaling(PyAcBlockScaling val) const;
    bool                        GetIsDynamicBlock() const;
    bool                        GetIsLayout() const;
    PyIAcadLayoutPtr            GetLayout() const;
    bool                        GetIsXRef() const;
    PyIAcadObjectPtr            AddCustomObject(const CString& val) const;
    PyIAcad3DFacePtr            Add3DFace(const AcGePoint3d& p1, const AcGePoint3d& p2, const AcGePoint3d& p3, const AcGePoint3d& p4) const;
    PyIAcadPolygonMeshPtr       Add3DMesh(int M, int N, const std::vector<AcGePoint3d>& points) const;
    PyIAcad3DPolylinePtr        Add3DPoly(const std::vector<AcGePoint3d>& points) const;
    PyIAcadArcPtr               AddArc(const AcGePoint3d& center, double radius, double startAngle, double endAngle) const;
    PyIAcadAttributePtr         AddAttribute(double Height, PyAcAttributeMode mode, const CString& prompt, const AcGePoint3d& insertionPoint, const CString& tag, const CString& value) const;
    PyIAcad3DSolidPtr           AddBox(const AcGePoint3d& origin, double length, double width, double height) const;
    PyIAcadCirclePtr            AddCircle(const AcGePoint3d& center, double radius) const;
    PyIAcad3DSolidPtr           AddCone(const AcGePoint3d& center, double baseRadius, double height) const;
    PyIAcad3DSolidPtr           AddCylinder(const AcGePoint3d& center, double radius, double height) const;
    PyIAcadDimAlignedPtr        AddDimAligned(const AcGePoint3d& extLine1Point, const AcGePoint3d& extLine2Point, const AcGePoint3d& textPosition) const;
    PyIAcadDimAngularPtr        AddDimAngular(const AcGePoint3d& angleVertex, const AcGePoint3d& firstEndPoint, const AcGePoint3d& secondEndPoint, const AcGePoint3d& textPosition) const;
    PyIAcadDimDiametricPtr      AddDimDiametric(const AcGePoint3d& chordPoint, const AcGePoint3d& farChordPoint, double leaderLength) const;
    PyIAcadDimRotatedPtr        AddDimRotated(const AcGePoint3d& extLine1Point, const AcGePoint3d& extLine2Point, const AcGePoint3d& dimLineLocation, double rotationAngle) const;
    PyIAcadDimOrdinatePtr       AddDimOrdinate(const AcGePoint3d& definitionPoint, const AcGePoint3d& leaderEndPoint, int UseXAxis) const;
    PyIAcadDimRadialPtr         AddDimRadial(const AcGePoint3d& center, const AcGePoint3d& chordPoint, double leaderLength) const;
    PyIAcadDimRadialLargePtr    AddDimRadialLarge(const AcGePoint3d& center, const AcGePoint3d& chordPoint, const AcGePoint3d& overrideCenter, const AcGePoint3d& jogPoint, double jogAngle) const;
    PyIAcadDim3PointAngularPtr  AddDim3PointAngular(const AcGePoint3d& angleVertex, const AcGePoint3d& firstEndPoint, const AcGePoint3d& secondEndPoint, const AcGePoint3d& textPosition) const;
    PyIAcadDimArcLengthPtr      AddDimArc(const AcGePoint3d& arcCenter, const AcGePoint3d& firstEndPoint, const AcGePoint3d& secondEndPoint, const AcGePoint3d& arcPoint) const;
    PyIAcadEllipsePtr           AddEllipse(const AcGePoint3d& center, const AcGeVector3d& majorAxis, double radiusRatio) const;
    PyIAcad3DSolidPtr           AddEllipticalCone(const AcGePoint3d& center, double majorRadius, double minorRadius, double height) const;
    PyIAcad3DSolidPtr           AddEllipticalCylinder(const AcGePoint3d& center, double majorRadius, double minorRadius, double height) const;
    PyIAcad3DSolidPtr           AddExtrudedSolid(const PyIAcadRegionImpl& impl, double height, double taperAngle) const;
    PyIAcad3DSolidPtr           AddExtrudedSolidAlongPath(const PyIAcadRegionImpl& regionImpl, const PyIAcadEntityImpl& entityImpl) const;
    PyIAcadLeaderPtr            AddLeader(const std::vector<AcGePoint3d>& points, const PyIAcadEntityImpl& annotation, PyAcLeaderType lt) const;
    PyIAcadMTextPtr             AddMText(const AcGePoint3d& insertionPoint, double width, const CString& text) const;
    PyIAcadPointPtr             AddPoint(const AcGePoint3d& point) const;
    PyIAcadLWPolylinePtr        AddLightWeightPolyline(const std::vector<AcGePoint2d>& points) const;
    PyIAcadPolylinePtr          AddPolyline(const std::vector<AcGePoint3d>& points) const;
    PyIAcadRayPtr               AddRay(const AcGePoint3d& p1, const AcGePoint3d& p2) const;
    PyIAcadRegionPtrArray       AddRegion(const std::vector<PyIAcadEntityImpl>& curves) const;
    PyIAcad3DSolidPtr           AddRevolvedSolid(const PyIAcadRegionImpl& impl, const AcGePoint3d& axisPoint, const AcGeVector3d& axisDir, double angle) const;
    PyIAcadShapePtr             AddShape(const CString& name, const AcGePoint3d& insertionPoint, double scaleFactor, double rotationAngle) const;
    PyIAcadSolidPtr             AddSolid(const AcGePoint3d& p1, const AcGePoint3d& p2, const AcGePoint3d& p3, const AcGePoint3d& p4) const;
    PyIAcad3DSolidPtr           AddSphere(const AcGePoint3d& center, double radius) const;
    PyIAcadSplinePtr            AddSpline(const std::vector<AcGePoint3d>& points, const AcGeVector3d& startTangent, const AcGeVector3d& endTangent) const;
    PyIAcadTextPtr              AddText(const CString& textValue, const AcGePoint3d& insertionPoint, double height) const;
    PyIAcadTolerancePtr         AddTolerance(const CString& textValue, const AcGePoint3d& insertionPoint, const AcGeVector3d& direction) const;
    PyIAcad3DSolidPtr           AddTorus(const AcGePoint3d& center, double torusRadius, double tubeRadius) const;
    PyIAcad3DSolidPtr           AddWedge(const AcGePoint3d& center, double length, double width, double height) const;
    PyIAcadXlinePtr             AddXline(const AcGePoint3d& p1, const AcGePoint3d& p2) const;
    PyIAcadBlockReferencePtr    InsertBlock(const AcGePoint3d& insertionPoint, const CString& name, const AcGeScale3d& scale, double rotation) const;
    PyIAcadHatchPtr             AddHatch(int patternType, const CString& patternName, bool associativity, PyAcHatchObjectType ht) const;
    PyIAcadRasterImagePtr       AddRaster(const CString& imageFileName, const AcGePoint3d& insertionPoint, double scaleFactor, double rotationAngle) const;
    PyIAcadLinePtr              AddLine(const AcGePoint3d& startPoint, const AcGePoint3d& endPoint) const;
    PyIAcadMInsertBlockPtr      AddMInsertBlock(const AcGePoint3d& point, const CString& name, const AcGeScale3d& scale, double rotation, long numRows, long numCols, long RowSpacing, long ColumnSpacing) const;
    PyIAcadPolyfaceMeshPtr      AddPolyfaceMesh(const std::vector<AcGePoint3d>& points, const std::vector<Adesk::Int16>& faces) const;
    PyIAcadMLinePtr             AddMLine(const std::vector<AcGePoint3d>& points) const;
    PyIAcadExternalReferencePtr AttachExternalReference(const CString& path, const CString& name, const AcGePoint3d& InsertionPoint, const AcGeScale3d& scale, double rotation, bool bOverlay) const;
    PyIAcadTablePtr             AddTable(const AcGePoint3d& insertionPoint, int numRows, int numColumns, double rowHeight, double colWidth) const;
    PyIAcadSectionPtr           AddSection(const AcGePoint3d& fromPoint, const AcGePoint3d& toPoint, const AcGeVector3d& planeVector) const;
    PyIAcadMLeaderPtr           AddMLeader(const std::vector<AcGePoint3d>& points) const;
public:
    IAcadBlock* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadBlockPtr = std::unique_ptr<PyIAcadBlockImpl>;
using PyIAcadBlockPtrArray = std::vector<std::shared_ptr<PyIAcadBlockImpl>>;

//------------------------------------------------------------------------------------
//PyIAcadModelSpaceImpl
class PyIAcadModelSpaceImpl : public PyIAcadBlockImpl
{
public:
    explicit PyIAcadModelSpaceImpl(IAcadBlock* ptr);
    virtual ~PyIAcadModelSpaceImpl() = default;
    IAcadModelSpace* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadModelSpacePtr = std::unique_ptr<PyIAcadModelSpaceImpl>;

//------------------------------------------------------------------------------------
//PyIAcadPaperSpaceImpl
class PyIAcadPaperSpaceImpl : public PyIAcadBlockImpl
{
public:
    explicit PyIAcadPaperSpaceImpl(IAcadBlock* ptr);
    virtual ~PyIAcadPaperSpaceImpl() = default;
    PyIAcadPViewportPtr AddPViewport(const AcGePoint3d& center, double width, double height) const;
public:
    IAcadPaperSpace* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadPaperSpacePtr = std::unique_ptr<PyIAcadPaperSpaceImpl>;

//------------------------------------------------------------------------------------
//PyIAcadBlocksImpl
class PyIAcadBlocksImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadBlocksImpl(IAcadBlocks* ptr);
    virtual ~PyIAcadBlocksImpl() = default;

    PyIAcadBlockPtr         GetItem(long ind) const;
    long                    GetCount() const;
    PyIAcadBlockPtr         Add(const AcGePoint3d& insertionPoint, const CString& name) const;
    PyIAcadBlockPtrArray    GetIter() const;
public:
    IAcadBlocks* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadBlocksPtr = std::unique_ptr<PyIAcadBlocksImpl>;


//------------------------------------------------------------------------------------
//PyAcadStateImpl
class PyIAcadStateImpl
{
public:
    explicit PyIAcadStateImpl(IAcadState* ptr);
    ~PyIAcadStateImpl() = default;
    bool getIsQuiescent() const;
public:
    IAcadState* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadStatePtr m_pimpl;
};
using PyIAcadStateImplPtr = std::unique_ptr<PyIAcadStateImpl>;

//------------------------------------------------------------------------------------
//PyIAcadDatabaseImpl
class PyIAcadDatabaseImpl
{
public:
    explicit PyIAcadDatabaseImpl(IAcadDatabase* ptr);
    virtual ~PyIAcadDatabaseImpl() = default;

    PyIAcadModelSpacePtr    GetModelSpace() const;
    PyIAcadPaperSpacePtr    GetPaperSpace() const;
    PyIAcadBlocksPtr        GetBlocks() const;
    PyIAcadObjectPtrArray   CopyObjects(const std::vector<PyIAcadObjectImpl>& objs, const PyIAcadObjectImpl& owner) const;
    PyIAcadGroupsPtr        GetGroups() const;
    PyIAcadDimStylesPtr     GetDimStyles() const;
    PyIAcadLayersPtr        GetLayers() const;
    PyIAcadLineTypesPtr     GetLineTypes() const;
    PyIAcadDictionariesPtr  GetDictionaries() const;
    PyIAcadRegisteredApplicationsPtr GetRegisteredApplications() const;
    PyIAcadTextStylesPtr    GetTextStyles() const;
    PyIAcadUCSsPtr          GetUserCoordinateSystems() const;
    PyIAcadViewsPtr         GetViews() const;
    PyIAcadViewportsPtr     GetViewports() const;
    double                  GetElevationModelSpace() const;
    void                    SetElevationModelSpace(double val) const;
    double                  GetElevationPaperSpace() const;
    void                    SetElevationPaperSpace(double val) const;
    void                    GetLimits(AcGePoint2d& min, AcGePoint2d& max) const;
    void                    SetLimits(const AcGePoint2d& min, const AcGePoint2d& max) const;
    PyIAcadObjectPtr        HandleToObject(const CString& val) const;
    PyIAcadObjectPtr        ObjectIdToObject(const AcDbObjectId& val) const;
    PyIAcadLayoutsPtr       GetLayouts() const;
    PyIAcadPlotConfigurationsPtr GetPlotConfigurations() const;
    PyIAcadDatabasePreferencesPtr GetPreferences() const;
    PyIAcadSummaryInfoPtr   GetSummaryInfo()const;
    PyIAcadSectionManagerPtr GetSectionManager() const;
    PyIAcadMaterialsPtr     GetMaterials() const;
public:
    IAcadDatabase* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadDatabasePtr m_pimpl;
};
using PyIAcadDatabasePtr = std::unique_ptr<PyIAcadDatabaseImpl>;

//------------------------------------------------------------------------------------
//PyIAcadDocumentImpl
class PyIAcadDocumentImpl;
using PyIAcadDocumentPtr = std::unique_ptr<PyIAcadDocumentImpl>;
class PyIAcadDocumentImpl : public PyIAcadDatabaseImpl
{
public:
    explicit PyIAcadDocumentImpl(IAcadDocument* ptr);
    virtual ~PyIAcadDocumentImpl() override = default;
    PyIAcadPlotPtr              GetPlot() const;
    PyIAcadLayerPtr             GetActiveLayer() const;
    void                        SetActiveLayer(const PyIAcadLayerImpl& obj) const;
    PyIAcadLineTypePtr          GetActiveLinetype() const;
    void                        SetActiveLinetype(const PyIAcadLineTypeImpl& obj) const;
    PyIAcadDimStylePtr          GetActiveDimStyle() const;
    void                        SetActiveDimStyle(const PyIAcadDimStyleImpl& obj) const;
    PyIAcadTextStylePtr         GetActiveTextStyle() const;
    void                        SetActiveTextStyle(const PyIAcadTextStyleImpl& obj) const;
    PyIAcadUCSPtr               GetActiveUCS() const;
    void                        SetActiveUCS(const PyIAcadUCSImpl& obj) const;
    PyIAcadViewportPtr          GetActiveViewport() const;
    void                        SetActiveViewport(const PyIAcadViewportImpl& obj) const;
    PyIAcadPViewportPtr         GetActivePViewport() const;
    void                        SetActivePViewport(const PyIAcadPViewportImpl& obj) const;
    PyAcActiveSpace             GetActiveSpace() const;
    void                        SetActiveSpace(PyAcActiveSpace sp) const;
    PyIAcadSelectionSetsPtr     GetSelectionSets() const;
    PyIAcadSelectionSetPtr      GetActiveSelectionSet() const;
    CString                     GetName() const;
    CString                     GetFullName() const;
    CString                     GetPath() const;
    bool                        GetObjectSnapMode() const;
    void                        SetObjectSnapMode(bool flag) const;
    bool                        GetReadOnly() const;
    bool                        GetSaved() const;
    bool                        GetMSpace() const;
    void                        SetMSpace(bool flag) const;
    PyIAcadUtilityPtr           GetUtility() const;
    PyIAcadDocumentPtr          Open(const CString& path) const;
    void                        AuditInfo(bool flag) const;
    PyIAcadBlockReferencePtr    Import(const CString& path, const AcGePoint3d& InsertionPoint, double ScaleFactor) const;
    void                        Export(const CString& fileName, const CString& extension, const PyIAcadSelectionSetImpl& sset) const;
    PyIAcadDocumentPtr          New(const CString& path) const;
    void                        Save() const;
    void                        SaveAs(const CString& fileName) const;
    void                        SaveAs(const CString& fileName, PyAcSaveAsType saType) const;
    void                        SaveAs(const CString& fileName, PyAcSaveAsType saType, const PyIAcadSecurityParamsImpl& pr) const;
    void                        Wblock(const CString& fileName, const PyIAcadSelectionSetImpl& sset) const;
    void                        PurgeAll() const;
    TypedVariant                GetVariable(const CString& name) const;
    void                        SetVariable(const CString& name, const TypedVariant& tv) const;
    void                        LoadShapeFile(const CString& name) const;
    void                        Regen(PyAcRegenType rt) const;
    PyIAcadSelectionSetPtr      GetPickfirstSelectionSet() const;
    bool                        IsActive() const;
    void                        Activate() const;
    void                        Close() const;
    void                        Close(bool SaveChanges) const;
    void                        Close(bool SaveChanges, const CString& fileName) const;
    PyAcWindowState             GetWindowState() const;
    void                        SetWindowState(PyAcWindowState val) const;
    int                         GetWidth() const;
    void                        SetWidth(int val) const;
    int                         GetHeight() const;
    void                        SetHeight(int val) const;
    PyIAcadLayoutPtr            GetActiveLayout() const;
    void                        SetActiveLayout(const PyIAcadLayoutImpl& val) const;
    void                        SendCommand(const CString& cmd) const;
    void                        PostCommand(const CString& cmd) const;
    LONG_PTR                    GetHWND() const;
    CString                     GetWindowTitle() const;
    void                        StartUndoMark() const;
    void                        EndUndoMark() const;
    PyIAcadDatabasePtr          GetDatabase() const;
    PyIAcadMaterialPtr          GetActiveMaterial() const;
    void                        SetActiveMaterial(const PyIAcadMaterialImpl& val) const;
public:
    IAcadDocument* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcadDocumentsImpl
class PyIAcadDocumentsImpl
{
public:
    explicit PyIAcadDocumentsImpl(IAcadDocuments* ptr);
    ~PyIAcadDocumentsImpl() = default;
    long                GetCount() const;
    PyIAcadDocumentPtr  Add() const;
    PyIAcadDocumentPtr  Add(const CString& _template) const;
    void                Close() const;
    PyIAcadDocumentPtr  GetItem(long index) const;
    PyIAcadDocumentPtr  Open(const CString& path, bool readOnly) const;
public:
    IAcadDocuments* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadDocumentsPtr m_pimpl;
};
using PyIAcadDocumentsPtr = std::unique_ptr<PyIAcadDocumentsImpl>;

//------------------------------------------------------------------------------------
//PyAcadApplicationImpl
class PyAcadApplicationImpl
{
public:
    PyAcadApplicationImpl();
    PyAcadApplicationImpl(IAcadApplication* ptr);
    ~PyAcadApplicationImpl() = default;
    void                    Eval(const CString& csVal) const;
    PyIAcadStateImplPtr     GetAcadState() const;
    wstringArray            ListArx() const;
    void                    LoadArx(const CString& csVal) const;
    void                    LoadDVB(const CString& csVal) const;
    void                    Quit() const;
    void                    RunMacro(const CString& csVal) const;
    void                    UnloadArx(const CString& csVal) const;
    void                    UnloadDVB(const CString& csVal) const;
    void                    Update() const;
    void                    ZoomAll() const;
    void                    ZoomCenter(const AcGePoint3d& pnt, double magnify) const;
    void                    ZoomExtents() const;
    void                    ZoomPickWindow() const;
    void                    ZoomPrevious() const;
    void                    ZoomScaled(double magnify, PyAcZoomScaleType scaletype) const;
    PyIAcadDocumentPtr      GetActiveDocument() const;
    void                    SetActiveDocument(const PyIAcadDocumentImpl& val) const;
    CString                 GetCaption() const;
    void                    SetCaption(const CString& val);
    PyIAcadDocumentsPtr     GetDocuments() const;//
    CString                 GetFullName() const;
    int                     GetHeight() const;
    void                    SetHeight(int val) const;
    LONG_PTR                GetHWND() const;
    long                    GetLocaleId() const;
    PyIAcadMenuBarPtr       GetMenuBar() const;
    PyIAcadMenuGroupsPtr    GetMenuGroups() const;
    CString                 GetName() const;
    CString                 GetPath() const;
    PyIAcadPreferencesPtr   GetPreferences() const;
    CString                 GetVersion() const;
    bool                    GetVisible() const;
    void                    SetVisible(bool val) const;
    int                     GetWidth() const;
    void                    SetWidth(int val) const;
    int                     GetWindowLeft() const;
    void                    SetWindowLeft(int val) const;
    PyAcWindowState         GetWindowState() const;
    void                    SetWindowState(PyAcWindowState val) const;
    int                     GetWindowTop() const;
    void                    SetWindowTop(int val) const;

    //internal
    static bool             runTest();
public:
    IAcadApplication* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadApplicationPtr m_pimpl;
};
using PyAcadApplicationPtr = std::unique_ptr<PyAcadApplicationImpl>;

//------------------------------------------------------------------------------------
//IAcadUtilityImpl
class PyIAcadUtilityImpl
{
public:
    explicit PyIAcadUtilityImpl(IAcadUtility* ptr);
    virtual ~PyIAcadUtilityImpl() = default;

    double              AngleToReal(const CString& angle, PyAcAngleUnits unit) const;
    CString             AngleToString(double angle, PyAcAngleUnits unit, int precision) const;
    double              DistanceToReal(const CString& dist, PyAcUnits unit) const;
    CString             RealToString(double angle, PyAcUnits unit, int precision) const;
    AcGePoint3d         TranslateCoordinates(const AcGePoint3d& point, PyAcCoordinateSystem fromCoordSystem, PyAcCoordinateSystem toCoordSystem, int displacement) const;
    AcGePoint3d         TranslateCoordinates(const AcGePoint3d& point, PyAcCoordinateSystem fromCoordSystem, PyAcCoordinateSystem toCoordSystem, int displacement, const AcGeVector3d& normal) const;
    void                InitializeUserInput(int bits, const CString& keyWordList) const;
    int                 GetInteger(const CString& prompt) const;
    double              GetReal(const CString& prompt) const;
    CString             GetInput() const;
    CString             GetKeyword(const CString& prompt) const;
    CString             GetString(int hasSpaces, const CString& prompt) const;
    double              GetAngle(const CString& prompt) const;
    double              GetAngle(const AcGePoint3d& point, const CString& prompt) const;
    double              AngleFromXAxis(const AcGePoint3d& startPoint, const AcGePoint3d& endPoint) const;
    AcGePoint3d         GetCorner(const AcGePoint3d& point, const CString& prompt) const;
    double              GetDistance(const AcGePoint3d& point, const CString& prompt) const;
    double              GetOrientation(const AcGePoint3d& point, const CString& prompt) const;
    AcGePoint3d         GetPoint(const CString& prompt) const;
    AcGePoint3d         GetPoint(const AcGePoint3d& point, const CString& prompt) const;
    AcGePoint3d         PolarPoint(const AcGePoint3d& point, double angle, double distance) const;
    PyIAcadEntityPtr    GetEntity(const CString& prompt, AcGePoint3d& hitpoint) const;
    void                Prompt(const CString& prompt) const;
    PyIAcadEntityPtr    GetSubEntity(const CString& prompt, AcGePoint3d& hp, AcGeMatrix3d& xf, std::vector<AcDbObjectId>& ids) const;
    bool                IsURL(const CString& URL) const;
    CString             GetRemoteFile(const CString& URL, bool ignoreCache) const;
    void                PutRemoteFile(const CString& URL, const CString& localFile) const;
    bool                IsRemoteFile(const CString& localFile, CString& URL) const;
    bool                LaunchBrowserDialog(const CString& title, const CString& caption, const CString& URL, const CString& regkey, bool bnEnabled, CString& selectedURL) const;
    void                SendModelessOperationStart(const CString& context) const;
    void                SendModelessOperationEnded(const CString& context) const;
    CString             GetObjectIdString(const  PyIAcadEntityImpl& obj, bool bHex) const;

    IAcadUtility* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadUtilityPtr m_pimpl;
};
using PyIAcadUtilityPtr = std::unique_ptr<PyIAcadUtilityImpl>;

//------------------------------------------------------------------------------------
//PyIAcadSecurityParamsImpl
class PyIAcadSecurityParamsImpl
{
public:
    explicit PyIAcadSecurityParamsImpl(IAcadSecurityParams* ptr);
    virtual ~PyIAcadSecurityParamsImpl() = default;
    IAcadSecurityParams* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadSecurityParamsPtr m_pimpl;
};

//------------------------------------------------------------------------------------
//PyIAcadSelectionSetImpl
class PyIAcadSelectionSetImpl
{
public:
    explicit PyIAcadSelectionSetImpl(IAcadSelectionSet* ptr);
    virtual ~PyIAcadSelectionSetImpl() = default;

    PyIAcadEntityPtr        GetItem(long ind) const;
    long                    GetCount() const;
    PyIAcadEntityPtrArray   GetIter() const;
    CString                 GetName() const;
    void                    Highlight(bool flag) const;
    void                    Erase() const;
    void                    Update() const;
    void                    AddItems(const std::vector<PyIAcadEntityImpl>& items) const;
    void                    RemoveItems(const std::vector<PyIAcadEntityImpl>& items) const;
    void                    Clear() const;
    void                    Delete() const;
    void                    SelectAll(const TypedVariants& tvs) const;
    void                    SelectOnScreen(const TypedVariants& tvs) const;
    void                    SelectWindow(const AcGePoint3d& pt1, const AcGePoint3d& pt2, const TypedVariants& tvs) const;
    void                    SelectCrossing(const AcGePoint3d& pt1, const AcGePoint3d& pt2, const TypedVariants& tvs) const;
    void                    SelectFence(const std::vector<AcGePoint3d>& pts, const TypedVariants& tvs) const;
    void                    SelectWindowPolygon(const std::vector<AcGePoint3d>& pts, const TypedVariants& tvs) const;
    void                    SelectCrossingPolygon(const std::vector<AcGePoint3d>& pts, const TypedVariants& tvs) const;
    void                    SelectLast() const;
    void                    SelectAtPoint(const AcGePoint3d& pt1, const TypedVariants& tvs) const;

    IAcadSelectionSet* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadSelectionSetPtr m_pimpl;
};
using PyIAcadSelectionSetPtr = std::unique_ptr<PyIAcadSelectionSetImpl>;

//------------------------------------------------------------------------------------
//PyIAcadSelectionSetsImpl
class PyIAcadSelectionSetsImpl
{
public:
    explicit PyIAcadSelectionSetsImpl(IAcadSelectionSets* ptr);
    virtual ~PyIAcadSelectionSetsImpl() = default;
    long                    GetCount() const;
    PyIAcadSelectionSetPtr  Add(const CString& name) const;
    PyIAcadSelectionSetPtr  GetItem(long index) const;
    IAcadSelectionSets* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadSelectionSetsPtr m_pimpl;
};
using PyIAcadSelectionSetsPtr = std::unique_ptr<PyIAcadSelectionSetsImpl>;