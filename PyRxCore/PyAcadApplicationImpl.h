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
    void                        SetExplodable(bool val);
    PyAcBlockScaling            GetBlockScaling() const;
    void                        SetBlockScaling(PyAcBlockScaling val) const;
    bool                        GetIsDynamicBlock() const;
    bool                        GetIsLayout() const;
    PyIAcadLayoutPtr            GetLayout() const;
    bool                        GetIsXRef() const;
    PyIAcadObjectPtr            AddCustomObject(const CString& val);
    PyIAcad3DFacePtr            Add3DFace(const AcGePoint3d& p1, const AcGePoint3d& p2, const AcGePoint3d& p3, const AcGePoint3d& p4);
    PyIAcadPolygonMeshPtr       Add3DMesh(int M, int N, const std::vector<AcGePoint3d>& points);
    PyIAcad3DPolylinePtr        Add3DPoly(const std::vector<AcGePoint3d>& points);
    PyIAcadArcPtr               AddArc(const AcGePoint3d& center, double radius, double startAngle, double endAngle);
    PyIAcadAttributePtr         AddAttribute(double Height, PyAcAttributeMode mode, const CString& prompt, const AcGePoint3d& insertionPoint, const CString& tag, const CString& value);
    PyIAcad3DSolidPtr           AddBox(const AcGePoint3d& origin, double length, double width, double height);
    PyIAcadCirclePtr            AddCircle(const AcGePoint3d& center, double radius);
    PyIAcad3DSolidPtr           AddCone(const AcGePoint3d& center, double baseRadius, double height);
    PyIAcad3DSolidPtr           AddCylinder(const AcGePoint3d& center, double radius, double height);
    PyIAcadDimAlignedPtr        AddDimAligned(const AcGePoint3d& extLine1Point, const AcGePoint3d& extLine2Point, const AcGePoint3d& textPosition);
    PyIAcadDimAngularPtr        AddDimAngular(const AcGePoint3d& angleVertex, const AcGePoint3d& firstEndPoint, const AcGePoint3d& secondEndPoint, const AcGePoint3d& textPosition);
    PyIAcadDimDiametricPtr      AddDimDiametric(const AcGePoint3d& chordPoint, const AcGePoint3d& farChordPoint, double leaderLength);
    PyIAcadDimRotatedPtr        AddDimRotated(const AcGePoint3d& extLine1Point, const AcGePoint3d& extLine2Point, const AcGePoint3d& dimLineLocation, double rotationAngle);
    PyIAcadDimOrdinatePtr       AddDimOrdinate(const AcGePoint3d& definitionPoint, const AcGePoint3d& leaderEndPoint, int UseXAxis);
    PyIAcadDimRadialPtr         AddDimRadial(const AcGePoint3d& center, const AcGePoint3d& chordPoint, double leaderLength);
    PyIAcadDimRadialLargePtr    AddDimRadialLarge(const AcGePoint3d& center, const AcGePoint3d& chordPoint, const AcGePoint3d& overrideCenter, const AcGePoint3d& jogPoint, double jogAngle);
    PyIAcadDim3PointAngularPtr  AddDim3PointAngular(const AcGePoint3d& angleVertex, const AcGePoint3d& firstEndPoint, const AcGePoint3d& secondEndPoint, const AcGePoint3d& textPosition);
    PyIAcadDimArcLengthPtr      AddDimArc(const AcGePoint3d& arcCenter, const AcGePoint3d& firstEndPoint, const AcGePoint3d& secondEndPoint, const AcGePoint3d& arcPoint);
    PyIAcadEllipsePtr           AddEllipse(const AcGePoint3d& center, const AcGeVector3d& majorAxis, double radiusRatio);
    PyIAcad3DSolidPtr           AddEllipticalCone(const AcGePoint3d& center, double majorRadius, double minorRadius, double height);
    PyIAcad3DSolidPtr           AddEllipticalCylinder(const AcGePoint3d& center, double majorRadius, double minorRadius, double height);
    PyIAcad3DSolidPtr           AddExtrudedSolid(const PyIAcadRegionImpl& impl, double height, double taperAngle);
    PyIAcad3DSolidPtr           AddExtrudedSolidAlongPath(const PyIAcadRegionImpl& regionImpl, const PyIAcadEntityImpl& entityImpl);
    PyIAcadLeaderPtr            AddLeader(const std::vector<AcGePoint3d>& points, const PyIAcadEntityImpl& annotation, PyAcLeaderType lt);
    PyIAcadMTextPtr             AddMText(const AcGePoint3d& insertionPoint, double width, const CString& text);
    PyIAcadPointPtr             AddPoint(const AcGePoint3d& point);
    PyIAcadLWPolylinePtr        AddLightWeightPolyline(const std::vector<AcGePoint2d>& points);
    PyIAcadPolylinePtr          AddPolyline(const std::vector<AcGePoint3d>& points);
    PyIAcadRayPtr               AddRay(const AcGePoint3d& p1, const AcGePoint3d& p2);
    PyIAcadRegionPtrArray       AddRegion(const std::vector<PyIAcadEntityImpl>& curves);
    PyIAcad3DSolidPtr           AddRevolvedSolid(const PyIAcadRegionImpl& impl, const AcGePoint3d& axisPoint, const AcGeVector3d& axisDir, double angle);
    PyIAcadShapePtr             AddShape(const CString& name, const AcGePoint3d& insertionPoint, double scaleFactor, double rotationAngle);
    PyIAcadSolidPtr             AddSolid(const AcGePoint3d& p1, const AcGePoint3d& p2, const AcGePoint3d& p3, const AcGePoint3d& p4);
    PyIAcad3DSolidPtr           AddSphere(const AcGePoint3d& center, double radius);
    PyIAcadSplinePtr            AddSpline(const std::vector<AcGePoint3d>& points, const AcGeVector3d& startTangent, const AcGeVector3d& endTangent);
    PyIAcadTextPtr              AddText(const CString& textValue, const AcGePoint3d& insertionPoint, double height);
    PyIAcadTolerancePtr         AddTolerance(const CString& textValue, const AcGePoint3d& insertionPoint, const AcGeVector3d& direction);
    PyIAcad3DSolidPtr           AddTorus(const AcGePoint3d& center, double torusRadius, double tubeRadius);
    PyIAcad3DSolidPtr           AddWedge(const AcGePoint3d& center, double length, double width, double height);
    PyIAcadXlinePtr             AddXline(const AcGePoint3d& p1, const AcGePoint3d& p2);
    PyIAcadBlockReferencePtr    InsertBlock(const AcGePoint3d& insertionPoint, const CString& name, const AcGeScale3d& scale, double rotation);
    PyIAcadHatchPtr             AddHatch(int patternType, const CString& patternName, bool associativity, PyAcHatchObjectType ht);
    PyIAcadRasterImagePtr       AddRaster(const CString& imageFileName, const AcGePoint3d& insertionPoint, double scaleFactor, double rotationAngle);
    PyIAcadLinePtr              AddLine(const AcGePoint3d& startPoint, const AcGePoint3d& endPoint);
    PyIAcadMInsertBlockPtr      AddMInsertBlock(const AcGePoint3d& point, const CString& name, const AcGeScale3d& scale, double rotation, long numRows, long numCols, long RowSpacing, long ColumnSpacing);
    PyIAcadPolyfaceMeshPtr      AddPolyfaceMesh(const std::vector<AcGePoint3d>& points, const std::vector<Adesk::Int16>& faces);
    PyIAcadMLinePtr             AddMLine(const std::vector<AcGePoint3d>& points);
    PyIAcadExternalReferencePtr AttachExternalReference(const CString& path, const CString& name, const AcGePoint3d& InsertionPoint, const AcGeScale3d& scale, double rotation, bool bOverlay);
    PyIAcadTablePtr             AddTable(const AcGePoint3d& insertionPoint, int numRows, int numColumns, double rowHeight, double colWidth);
    PyIAcadSectionPtr           AddSection(const AcGePoint3d& fromPoint, const AcGePoint3d& toPoint, const AcGeVector3d& planeVector);
    PyIAcadMLeaderPtr           AddMLeader(const std::vector<AcGePoint3d>& points);
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
    PyIAcadPViewportPtr AddPViewport(const AcGePoint3d& center, double width, double height);
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
    PyIAcadObjectPtrArray   CopyObjects(const std::vector<PyIAcadObjectImpl>& objs, const PyIAcadObjectImpl& owner);
    PyIAcadGroupsPtr        GetGroups() const;
    PyIAcadDimStylesPtr     GetDimStyles() const;
    PyIAcadLayersPtr        GetLayers() const;
    PyIAcadLineTypesPtr     GetLineTypes() const;
    PyIAcadDictionariesPtr  GetDictionaries() const;
    PyIAcadRegisteredApplicationsPtr GetRegisteredApplications();
    PyIAcadTextStylesPtr    GetTextStyles();
    PyIAcadUCSsPtr          GetUserCoordinateSystems();
    PyIAcadViewsPtr         GetViews();
    PyIAcadViewportsPtr     GetViewports();
    double                  GetElevationModelSpace() const;
    void                    SetElevationModelSpace(double val);
    double                  GetElevationPaperSpace() const;
    void                    SetElevationPaperSpace(double val);
    void                    GetLimits(AcGePoint2d& min, AcGePoint2d& max);
    void                    SetLimits(const AcGePoint2d& min, const AcGePoint2d& max);
    PyIAcadObjectPtr        HandleToObject(const CString& val);
    PyIAcadObjectPtr        ObjectIdToObject(const AcDbObjectId& val);
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
    void                        SetActiveLayer(const PyIAcadLayerImpl& obj);
    PyIAcadLineTypePtr          GetActiveLinetype() const;
    void                        SetActiveLinetype(const PyIAcadLineTypeImpl& obj);
    PyIAcadDimStylePtr          GetActiveDimStyle() const;
    void                        SetActiveDimStyle(const PyIAcadDimStyleImpl& obj);
    PyIAcadTextStylePtr         GetActiveTextStyle() const;
    void                        SetActiveTextStyle(const PyIAcadTextStyleImpl& obj);
    PyIAcadUCSPtr               GetActiveUCS() const;
    void                        SetActiveUCS(const PyIAcadUCSImpl& obj);
    PyIAcadViewportPtr          GetActiveViewport() const;
    void                        SetActiveViewport(const PyIAcadViewportImpl& obj);
    PyIAcadPViewportPtr         GetActivePViewport() const;
    void                        SetActivePViewport(const PyIAcadPViewportImpl& obj);
    PyAcActiveSpace             GetActiveSpace() const;
    void                        SetActiveSpace(PyAcActiveSpace sp) const;
    PyIAcadSelectionSetsPtr     GetSelectionSets() const;
    PyIAcadSelectionSetPtr      GetActiveSelectionSet() const;
    CString                     GetName() const;
    CString                     GetFullName() const;
    CString                     GetPath() const;
    bool                        GetObjectSnapMode() const;
    void                        SetObjectSnapMode(bool flag);
    bool                        GetReadOnly() const;
    bool                        GetSaved() const;
    bool                        GetMSpace() const;
    void                        SetMSpace(bool flag);
    PyIAcadUtilityPtr           GetUtility() const;
    PyIAcadDocumentPtr          Open(const CString& path);
    void                        AuditInfo(bool flag);
    PyIAcadBlockReferencePtr    Import(const CString& path, const AcGePoint3d& InsertionPoint, double ScaleFactor);
    void                        Export(const CString& fileName, const CString& extension, const PyIAcadSelectionSetImpl& sset);
    PyIAcadDocumentPtr          New(const CString& path);
    void                        Save();
    void                        SaveAs(const CString& fileName);
    void                        SaveAs(const CString& fileName, PyAcSaveAsType saType);
    void                        SaveAs(const CString& fileName, PyAcSaveAsType saType, const PyIAcadSecurityParamsImpl& pr);
    void                        Wblock(const CString& fileName, const PyIAcadSelectionSetImpl& sset);
    void                        PurgeAll();
    TypedVariant                GetVariable(const CString& name);
    void                        SetVariable(const CString& name, const TypedVariant& tv);
    void                        LoadShapeFile(const CString& name);
    void                        Regen(PyAcRegenType rt);
    PyIAcadSelectionSetPtr      GetPickfirstSelectionSet() const;
    bool                        IsActive();
    void                        Activate();
    void                        Close();
    void                        Close(bool SaveChanges);
    void                        Close(bool SaveChanges, const CString& fileName);
    PyAcWindowState             GetWindowState() const;
    void                        SetWindowState(PyAcWindowState val);
    int                         GetWidth() const;
    void                        SetWidth(int val);
    int                         GetHeight() const;
    void                        SetHeight(int val);
    PyIAcadLayoutPtr            GetActiveLayout() const;
    void                        SetActiveLayout(const PyIAcadLayoutImpl& val);
    void                        SendCommand(const CString& cmd);
    void                        PostCommand(const CString& cmd);
    LONG_PTR                    GetHWND() const;
    CString                     GetWindowTitle() const;
    void                        StartUndoMark();
    void                        EndUndoMark();
    PyIAcadDatabasePtr          GetDatabase() const;
    PyIAcadMaterialPtr          GetActiveMaterial() const;
    void                        SetActiveMaterial(const PyIAcadMaterialImpl& val);
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
    PyIAcadDocumentPtr  Add();
    PyIAcadDocumentPtr  Add(const CString& _template);
    void                Close();
    PyIAcadDocumentPtr  GetItem(long index) const;
    PyIAcadDocumentPtr  Open(const CString& path, bool readOnly);
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
    PyIAcadStateImplPtr     GetAcadState();
    wstringArray            ListArx();
    void                    LoadArx(const CString& csVal);
    void                    LoadDVB(const CString& csVal);
    void                    Quit();
    void                    RunMacro(const CString& csVal);
    void                    UnloadArx(const CString& csVal);
    void                    UnloadDVB(const CString& csVal);
    void                    Update();
    void                    ZoomAll();
    void                    ZoomCenter(const AcGePoint3d& pnt, double magnify);
    void                    ZoomExtents();
    void                    ZoomPickWindow();
    void                    ZoomPrevious();
    void                    ZoomScaled(double magnify, PyAcZoomScaleType scaletype);
    PyIAcadDocumentPtr      GetActiveDocument() const;
    void                    SetActiveDocument(const PyIAcadDocumentImpl& val) const;
    CString                 GetCaption() const;
    void                    SetCaption(const CString& val);
    PyIAcadDocumentsPtr     GetDocuments() const;//
    CString                 GetFullName() const;
    int                     GetHeight() const;
    void                    SetHeight(int val);
    LONG_PTR                GetHWND() const;
    long                    GetLocaleId() const;
    PyIAcadMenuBarPtr       GetMenuBar() const;
    PyIAcadMenuGroupsPtr    GetMenuGroups() const;
    CString                 GetName() const;
    CString                 GetPath() const;
    PyIAcadPreferencesPtr   GetPreferences();
    CString                 GetVersion() const;
    bool                    GetVisible() const;
    void                    SetVisible(bool val);
    int                     GetWidth() const;
    void                    SetWidth(int val);
    int                     GetWindowLeft() const;
    void                    SetWindowLeft(int val);
    PyAcWindowState         GetWindowState() const;
    void                    SetWindowState(PyAcWindowState val);
    int                     GetWindowTop() const;
    void                    SetWindowTop(int val);

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

    double              AngleToReal(const CString& angle, PyAcAngleUnits unit);
    CString             AngleToString(double angle, PyAcAngleUnits unit, int precision);
    double              DistanceToReal(const CString& dist, PyAcUnits unit);
    CString             RealToString(double angle, PyAcUnits unit, int precision);
    AcGePoint3d         TranslateCoordinates(const AcGePoint3d& point, PyAcCoordinateSystem fromCoordSystem, PyAcCoordinateSystem toCoordSystem, int displacement);
    AcGePoint3d         TranslateCoordinates(const AcGePoint3d& point, PyAcCoordinateSystem fromCoordSystem, PyAcCoordinateSystem toCoordSystem, int displacement, const AcGeVector3d& normal);
    void                InitializeUserInput(int bits, const CString& keyWordList);
    int                 GetInteger(const CString& prompt);
    double              GetReal(const CString& prompt);
    CString             GetInput();
    CString             GetKeyword(const CString& prompt);
    CString             GetString(int hasSpaces, const CString& prompt);
    double              GetAngle(const CString& prompt);
    double              GetAngle(const AcGePoint3d& point, const CString& prompt);
    double              AngleFromXAxis(const AcGePoint3d& startPoint, const AcGePoint3d& endPoint);
    AcGePoint3d         GetCorner(const AcGePoint3d& point, const CString& prompt);
    double              GetDistance(const AcGePoint3d& point, const CString& prompt);
    double              GetOrientation(const AcGePoint3d& point, const CString& prompt);
    AcGePoint3d         GetPoint(const CString& prompt);
    AcGePoint3d         GetPoint(const AcGePoint3d& point, const CString& prompt);
    AcGePoint3d         PolarPoint(const AcGePoint3d& point, double angle, double distance);
    PyIAcadEntityPtr    GetEntity(const CString& prompt, AcGePoint3d& hitpoint);
    void                Prompt(const CString& prompt);
    PyIAcadEntityPtr    GetSubEntity(const CString& prompt, AcGePoint3d& hp, AcGeMatrix3d& xf, std::vector<AcDbObjectId>& ids);
    bool                IsURL(const CString& URL);
    CString             GetRemoteFile(const CString& URL, bool ignoreCache);
    void                PutRemoteFile(const CString& URL, const CString& localFile);
    bool                IsRemoteFile(const CString& localFile, CString& URL);
    bool                LaunchBrowserDialog(const CString& title, const CString& caption, const CString& URL, const CString& regkey, bool bnEnabled, CString& selectedURL);
    void                SendModelessOperationStart(const CString& context);
    void                SendModelessOperationEnded(const CString& context);
    CString             GetObjectIdString(const  PyIAcadEntityImpl& obj, bool bHex);

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

    PyIAcadEntityPtr        GetItem(long ind);
    long                    GetCount() const;
    PyIAcadEntityPtrArray   GetIter() const;
    CString                 GetName() const;
    void                    Highlight(bool flag);
    void                    Erase();
    void                    Update();
    void                    AddItems(const std::vector<PyIAcadEntityImpl>& items);
    void                    RemoveItems(const std::vector<PyIAcadEntityImpl>& items);
    void                    Clear();
    void                    Delete();
    void                    SelectAll(const TypedVariants& tvs);
    void                    SelectOnScreen(const TypedVariants& tvs);
    void                    SelectWindow(const AcGePoint3d& pt1, const AcGePoint3d& pt2, const TypedVariants& tvs);
    void                    SelectCrossing(const AcGePoint3d& pt1, const AcGePoint3d& pt2, const TypedVariants& tvs);
    void                    SelectFence(const std::vector<AcGePoint3d>& pts, const TypedVariants& tvs);
    void                    SelectWindowPolygon(const std::vector<AcGePoint3d>& pts, const TypedVariants& tvs);
    void                    SelectCrossingPolygon(const std::vector<AcGePoint3d>& pts, const TypedVariants& tvs);
    void                    SelectLast();
    void                    SelectAtPoint(const AcGePoint3d& pt1, const TypedVariants& tvs);

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
    PyIAcadSelectionSetPtr  Add(const CString& name);
    PyIAcadSelectionSetPtr  GetItem(long index) const;
    IAcadSelectionSets* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadSelectionSetsPtr m_pimpl;
};
using PyIAcadSelectionSetsPtr = std::unique_ptr<PyIAcadSelectionSetsImpl>;