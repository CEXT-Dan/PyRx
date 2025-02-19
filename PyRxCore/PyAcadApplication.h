#pragma once

#include "PyAcAxCommon.h"
#include "PyAcadObject.h"
#include "PyAcadDbObject.h"
#include "PyAcadEntity.h"

class PyIAcadStateImpl;
class PyAcadState;
class PyAcadApplicationImpl;
class PyIAcadDocumentsImpl;
class PyAcadDocuments;
class PyIAcadDatabaseImpl;
class PyAcadDatabase;
class PyIAcadDocumentImpl;
class PyIAcadBlocksImpl;
class PyIAcadUtilityImpl;
class PyIAcadSecurityParamsImpl;
class PyIAcadSelectionSetImpl;
class PyIAcadSelectionSetsImpl;

class PyAcadSummaryInfo;
class PyAcadDocument;
class PyAcadMenuBar;
class PyAcadMenuBar;
class PyAcadMenuGroups;
class PyAcadPreferences;
class PyAcadModelSpace;
class PyAcadPaperSpace;
class PyAcadEntity;
class PyAcadUtility;
class PyAcadSecurityParams;
class PyAcadSelectionSet;
class PyAcadSelectionSets;


//----------------------------------------------------------------------------------------
//PyAcadBlock
void makePyAcadBlockWrapper();

class PyAcadBlock : public PyAcadObject
{
public:
    PyAcadBlock() = default;
    PyAcadBlock(std::shared_ptr<PyIAcadBlockImpl> ptr);
    virtual ~PyAcadBlock() = default;
    long                    count() const;
    PyAcadEntity            item(long ind) const;
    boost::python::list     entities() const;
    std::string             name() const;
    void                    setName(const std::string& val);
    AcGePoint3d             origin() const;
    void                    setOrigin(const AcGePoint3d& val) const;
    void                    unload() const;
    void                    reload() const;
    void                    bind(bool bPrefixName) const;
    void                    detach() const;
    PyAcadDatabase          xrefDatabase() const;
    std::string             path() const;
    void                    setPath(const std::string& val) const;
    std::string             comments() const;
    void                    setComments(const std::string& val) const;
    PyAcInsertUnits         units() const;
    void                    setUnits(PyAcInsertUnits val) const;
    bool                    isExplodable() const;
    void                    setExplodable(bool val);
    PyAcBlockScaling        blockScaling() const;
    void                    setBlockScaling(PyAcBlockScaling val) const;
    bool                    isDynamicBlock() const;
    bool                    isLayout() const;
    PyAcadLayout            layout() const;
    bool                    isXRef() const;
    PyAcadObject            addCustomObject(const std::string& val);
    PyAcad3DFace            add3DFace(const AcGePoint3d& p1, const AcGePoint3d& p2, const AcGePoint3d& p3, const AcGePoint3d& p4);
    PyAcadPolygonMesh       add3DMesh(int M, int N, const boost::python::object& iterable);
    PyAcad3DPolyline        add3DPoly(const boost::python::object& iterable);
    PyAcadArc               addArc(const AcGePoint3d& center, double radius, double startAngle, double endAngle);
    PyAcadAttribute         addAttribute(double height, PyAcAttributeMode mode, const std::string& prompt, const AcGePoint3d& insertionPoint, const std::string& tag, const std::string& value);
    PyAcad3DSolid           addBox(const AcGePoint3d& origin, double length, double width, double height);
    PyAcadCircle            addCircle(const AcGePoint3d& center, double radius);
    PyAcad3DSolid           addCone(const AcGePoint3d& center, double baseRadius, double height);
    PyAcad3DSolid           addCylinder(const AcGePoint3d& center, double radius, double height);
    PyAcadDimAligned        addDimAligned(const AcGePoint3d& extLine1Point, const AcGePoint3d& extLine2Point, const AcGePoint3d& textPosition);
    PyAcadDimAngular        addDimAngular(const AcGePoint3d& angleVertex, const AcGePoint3d& firstEndPoint, const AcGePoint3d& secondEndPoint, const AcGePoint3d& textPosition);
    PyAcadDimDiametric      addDimDiametric(const AcGePoint3d& chordPoint, const AcGePoint3d& farChordPoint, double leaderLength);
    PyAcadDimRotated        addDimRotated(const AcGePoint3d& extLine1Point, const AcGePoint3d& extLine2Point, const AcGePoint3d& dimLineLocation, double rotationAngle);
    PyAcadDimOrdinate       addDimOrdinate(const AcGePoint3d& definitionPoint, const AcGePoint3d& leaderEndPoint, int UseXAxis);
    PyAcadDimRadial         addDimRadial(const AcGePoint3d& center, const AcGePoint3d& chordPoint, double leaderLength);
    PyAcadDimRadialLarge    addDimRadialLarge(const AcGePoint3d& center, const AcGePoint3d& chordPoint, const AcGePoint3d& overrideCenter, const AcGePoint3d& jogPoint, double jogAngle);
    PyAcadDim3PointAngular  addDim3PointAngular(const AcGePoint3d& angleVertex, const AcGePoint3d& firstEndPoint, const AcGePoint3d& secondEndPoint, const AcGePoint3d& textPosition);
    PyAcadDimArcLength      addDimArc(const AcGePoint3d& arcCenter, const AcGePoint3d& firstEndPoint, const AcGePoint3d& secondEndPoint, const AcGePoint3d& arcPoint);
    PyAcadEllipse           addEllipse(const AcGePoint3d& center, const AcGeVector3d& majorAxis, double radiusRatio);
    PyAcad3DSolid           addEllipticalCone(const AcGePoint3d& center, double majorRadius, double minorRadius, double height);
    PyAcad3DSolid           addEllipticalCylinder(const AcGePoint3d& center, double majorRadius, double minorRadius, double height);
    PyAcad3DSolid           addExtrudedSolid(const PyAcadRegion& impl, double height, double taperAngle);
    PyAcad3DSolid           addExtrudedSolidAlongPath(const PyAcadRegion& region, const PyAcadEntity& entity);
    PyAcadLeader            addLeader(const boost::python::object& points, const PyAcadEntity& annotation, PyAcLeaderType lt);
    PyAcadMText             addMText(const AcGePoint3d& insertionPoint, double width, const std::string& text);
    PyAcadPoint             addPoint(const AcGePoint3d& point);
    PyAcadLWPolyline        addLightWeightPolyline(const boost::python::object& points);
    PyAcadPolyline          addPolyline(const boost::python::object& points);
    PyAcadRay               addRay(const AcGePoint3d& p1, const AcGePoint3d& p2);
    boost::python::list     addRegion(const boost::python::object& curves);
    PyAcad3DSolid           addRevolvedSolid(const PyAcadRegion& region, const AcGePoint3d& axisPoint, const AcGeVector3d& axisDir, double angle);
    PyAcadShape             addShape(const std::string& name, const AcGePoint3d& insertionPoint, double scaleFactor, double rotationAngle);
    PyAcadSolid             addSolid(const AcGePoint3d& p1, const AcGePoint3d& p2, const AcGePoint3d& p3, const AcGePoint3d& p4);
    PyAcad3DSolid           addSphere(const AcGePoint3d& center, double radius);
    PyAcadSpline            addSpline(const boost::python::object& points, const AcGeVector3d& startTangent, const AcGeVector3d& endTangent);
    PyAcadText              addText(const  std::string& textValue, const AcGePoint3d& insertionPoint, double height);
    PyAcadTolerance         addTolerance(const std::string& textValue, const AcGePoint3d& insertionPoint, const AcGeVector3d& direction);
    PyAcad3DSolid           addTorus(const AcGePoint3d& center, double torusRadius, double tubeRadius);
    PyAcad3DSolid           addWedge(const AcGePoint3d& center, double length, double width, double height);
    PyAcadXline             addXline(const AcGePoint3d& p1, const AcGePoint3d& p2);
    PyAcadBlockReference    insertBlock(const AcGePoint3d& insertionPoint, const std::string& name, const AcGeScale3d& scale, double rotation);
    PyAcadHatch             addHatch(int patternType, const std::string& patternName, bool associativity);
    PyAcadRasterImage       addRaster(const std::string& imageFileName, const AcGePoint3d& insertionPoint, double scaleFactor, double rotationAngle);
    PyAcadLine              addLine(const AcGePoint3d& startPoint, const AcGePoint3d& endPoint);
    PyAcadMInsertBlock      addMInsertBlock(const AcGePoint3d& point, const std::string& name, const AcGeScale3d& scale, double rotation, long numRows, long numCols, long rowSpacing, long rolumnSpacing);
    PyAcadPolyfaceMesh      addPolyfaceMesh(const boost::python::object& points, const boost::python::object& faces);
    PyAcadMLine             addMLine(const boost::python::object& points);
    PyAcadExternalReference attachExternalReference(const std::string& path, const std::string& name, const AcGePoint3d& InsertionPoint, const AcGeScale3d& scale, double rotation, bool bOverlay);
    PyAcadTable             addTable(const AcGePoint3d& insertionPoint, int numRows, int numColumns, double rowHeight, double colWidth);
    PyAcadSection           addSection(const AcGePoint3d& fromPoint, const AcGePoint3d& toPoint, const AcGeVector3d& planeVector);
    PyAcadMLeader           addMLeader(const boost::python::object& points);
    static PyAcadBlock      cast(const PyAcadObject& src);
    static std::string      className();
public:
    PyIAcadBlockImpl* impObj(const std::source_location& src = std::source_location::current()) const;
    void filliterator();
    std::vector<PyAcadEntity>::iterator begin();
    std::vector<PyAcadEntity>::iterator end();
    std::vector<PyAcadEntity> m_iterable{ 0 };
};

//----------------------------------------------------------------------------------------
//PyModelSpace
void makePyModelSpaceWrapper();

class PyAcadModelSpace : public PyAcadBlock
{
public:
    PyAcadModelSpace() = default;
    PyAcadModelSpace(std::shared_ptr<PyIAcadModelSpaceImpl> ptr);
    virtual ~PyAcadModelSpace() override = default;
    static PyAcadModelSpace cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadModelSpaceImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyPaperSpace
void makePyPaperSpaceWrapper();

class PyAcadPaperSpace : public PyAcadBlock
{
public:
    PyAcadPaperSpace() = default;
    PyAcadPaperSpace(std::shared_ptr<PyIAcadPaperSpaceImpl> ptr);
    virtual ~PyAcadPaperSpace() override = default;
    static PyAcadPaperSpace cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadPaperSpaceImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadBlocks
void makePyAcadBlocksWrapper();

class PyAcadBlocks : public PyAcadObject
{
public:
    PyAcadBlocks() = default;
    PyAcadBlocks(std::shared_ptr<PyIAcadBlocksImpl> ptr);
    virtual ~PyAcadBlocks() override = default;
    PyAcadBlock         item(long ind) const;
    long                count() const;
    PyAcadBlock         add(const AcGePoint3d& insertionPoint, const std::string& name) const;
    boost::python::list blocks() const;

    static PyAcadBlocks cast(const PyAcadObject& src);
    static std::string  className();
public:
    PyIAcadBlocksImpl* impObj(const std::source_location& src = std::source_location::current()) const;
    void filliterator();
    std::vector<PyAcadBlock>::iterator begin();
    std::vector<PyAcadBlock>::iterator end();
    std::vector<PyAcadBlock> m_iterable{ 0 };
};

//------------------------------------------------------------------------------------
//PyAcadState
void makePyAcadStateWrapper();

class PyAcadState
{
public:
    explicit PyAcadState(std::shared_ptr<PyIAcadStateImpl> ptr);
    virtual ~PyAcadState() = default;
    bool                isQuiescent() const;
    static std::string  className();
public:
    PyIAcadStateImpl* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<PyIAcadStateImpl> m_pyImp;
};

//----------------------------------------------------------------------------------------
//PyAcadApplication
void makePyAcadApplicationWrapper();

class PyAcadApplication
{
public:
    PyAcadApplication();
    virtual ~PyAcadApplication() = default;

    void                    eval(const std::string& sval) const;
    PyAcadState             acadState();
    boost::python::list     listArx() const;
    void                    loadArx(const std::string& sval);
    void                    loadDVB(const std::string& sval);
    void                    quit();
    void                    runMacro(const std::string& sval);
    void                    unloadArx(const std::string& sval);
    void                    unloadDVB(const std::string& sval);
    void                    update();
    void                    zoomAll();
    void                    zoomCenter(const AcGePoint3d& pnt, double magnify);
    void                    zoomExtents();
    void                    zoomPickWindow();
    void                    zoomPrevious();
    void                    zoomScaled(double magnify, PyAcZoomScaleType scaletype);
    PyAcadDocument          activeDocument() const;
    void                    setActiveDocument(const PyAcadDocument& val) const;
    std::string             caption() const;
    void                    setCaption(const std::string& val);
    PyAcadDocuments         documents() const;
    std::string             fullName() const;
    int                     getHeight() const;
    void                    setHeight(int val);
    LONG_PTR                getHWND() const;
    long                    localeId() const;
    PyAcadMenuBar           menuBar() const;
    PyAcadMenuGroups        menuGroups() const;
    std::string             getName() const;
    std::string             getPath() const;
    PyAcadPreferences       preferences();
    //StatusId();
    std::string             version() const;
    bool                    isVisible() const;
    void                    setVisible(bool val);
    int                     getWidth() const;
    void                    setWidth(int val);
    int                     getWindowLeft() const;
    void                    setWindowLeft(int val);
    PyAcWindowState         getWindowState() const;
    void                    setWindowState(PyAcWindowState val);
    int                     getWindowTop() const;
    void                    setWindowTop(int val);
    static std::string      className();

    //internal 
    static bool             runTest(const AcDbObjectId& id);
public:
    PyAcadApplicationImpl* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<PyAcadApplicationImpl> m_pyImp;
};

//----------------------------------------------------------------------------------------
//PyAcadDocuments
void makePyAcadDocumentsWrapper();

class PyAcadDocuments
{
public:
    explicit PyAcadDocuments(std::shared_ptr<PyIAcadDocumentsImpl> ptr) noexcept;
    virtual ~PyAcadDocuments() = default;
    long                count() const;
    PyAcadDocument      add1();
    PyAcadDocument      add2(const std::string& _template);
    void                close();
    PyAcadDocument      item(long index);
    PyAcadDocument      open(const std::string& path, bool readOnly);
    static std::string  className();
public:
    PyIAcadDocumentsImpl* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<PyIAcadDocumentsImpl> m_pyImp;
};


//----------------------------------------------------------------------------------------
//PyAcadDatabase
void makePyAcadDatabaseWrapper();

class PyAcadDatabase
{
public:
    PyAcadDatabase(AcDbDatabase* ptr) noexcept;
    PyAcadDatabase(std::shared_ptr<PyIAcadDatabaseImpl> ptr) noexcept;
    virtual ~PyAcadDatabase() = default;

    PyAcadModelSpace            modelSpace() const;
    PyAcadPaperSpace            paperSpace() const;
    PyAcadBlocks                blocks() const;
    boost::python::list         copyObjects(const boost::python::list& objs, const PyAcadObject& owner);
    PyAcadGroups                groups() const;
    PyAcadDimStyles             dimStyles() const;
    PyAcadLayers                layers() const;
    PyAcadLineTypes             lineTypes() const;
    PyAcadDictionaries          dictionaries() const;
    PyAcadRegisteredApplications registeredApplications();
    PyAcadTextStyles            textStyles();
    PyAcadUCSs                  userCoordinateSystems();
    PyAcadViews                 views();
    PyAcadViewports             viewports();
    double                      elevationModelSpace() const;
    void                        setElevationModelSpace(double val);
    double                      elevationPaperSpace() const;
    void                        setElevationPaperSpace(double val);
    boost::python::tuple        limits();
    void                        setLimits(boost::python::tuple minmax);
    PyAcadObject                handleToObject(const std::string& val);
    PyAcadObject                objectIdToObject(const PyDbObjectId& val);
    PyAcadLayouts               layouts() const;
    PyAcadPlotConfigurations    plotConfigurations() const;
    PyAcadDatabasePreferences   preferences() const;
    PyAcadSummaryInfo           summaryInfo() const;
    PyAcadSectionManager        sectionManager() const;
    PyAcadMaterials             materials() const;

    static std::string          className();
public:
    PyIAcadDatabaseImpl* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<PyIAcadDatabaseImpl> m_pyImp;
};

//----------------------------------------------------------------------------------------
//PyAcadDocument
void makePyAcadDocumentWrapper();

class PyAcadDocument : public PyAcadDatabase
{
public:
    explicit PyAcadDocument(std::shared_ptr<PyIAcadDocumentImpl> ptr);
    virtual ~PyAcadDocument() = default;

    PyAcadPlot              plot() const;
    PyAcadLayer             activeLayer() const;
    void                    setActiveLayer(const PyAcadLayer& obj);
    PyAcadLineType          activeLinetype() const;
    void                    setActiveLinetype(const PyAcadLineType& obj);
    PyAcadDimStyle          activeDimStyle() const;
    void                    setActiveDimStyle(const PyAcadDimStyle& obj);
    PyAcadTextStyle         activeTextStyle() const;
    void                    setActiveTextStyle(const PyAcadTextStyle& obj);
    PyAcadUCS               activeUCS() const;
    void                    setActiveUCS(const PyAcadUCS& obj);
    PyAcadViewport          activeViewport() const;
    void                    setActiveViewport(const PyAcadViewport& obj);
    PyAcadPViewport         activePViewport() const;
    void                    setActivePViewport(const PyAcadPViewport& obj);
    PyAcActiveSpace         activeSpace() const;
    void                    setActiveSpace(PyAcActiveSpace sp) const;
    PyAcadSelectionSets     selectionSets() const;
    PyAcadSelectionSet      activeSelectionSet() const;
    std::string             name() const;
    std::string             fullName() const;
    std::string             path() const;
    bool                    objectSnapMode() const;
    void                    setObjectSnapMode(bool flag);
    bool                    isReadOnly() const;
    bool                    isSaved() const;
    bool                    mSpace() const;
    void                    setMSpace(bool flag);
    PyAcadUtility           utility() const;
    PyAcadDocument          open(const std::string& path);
    void                    auditInfo(bool flag);
    PyAcadBlockReference    importFile(const std::string& path, const AcGePoint3d& InsertionPoint, double scaleFactor);
    void                    exportToFile(const std::string& fileName, const std::string& extension, const PyAcadSelectionSet& sset);
    PyAcadDocument          newDoc(const std::string& path);
    void                    save();
    void                    saveAs1(const std::string& fileName);
    void                    saveAs2(const std::string& fileName, PyAcSaveAsType saType);
    void                    saveAs3(const std::string& fileName, PyAcSaveAsType saType, const PyAcadSecurityParams& pr);
    void                    wblock(const std::string& fileName, const PyAcadSelectionSet& sset);
    void                    purgeAll();
    boost::python::object   getVariable(const std::string& name);
    void                    setVariable(const std::string& name, const boost::python::object& obj);
    void                    loadShapeFile(const std::string& name);
    void                    regen(PyAcRegenType rt);
    PyAcadSelectionSet      pickfirstSelectionSet() const;
    bool                    isActive();
    void                    activate();
    void                    close1();
    void                    close2(bool saveChanges);
    void                    close3(bool saveChanges, const std::string& fileName);
    PyAcWindowState         windowState() const;
    void                    setWindowState(PyAcWindowState val);
    int                     width() const;
    void                    setWidth(int val);
    int                     height() const;
    void                    setHeight(int val);
    PyAcadLayout            activeLayout() const;
    void                    setActiveLayout(const PyAcadLayout& val);
    void                    sendCommand(const std::string& cmd);
    void                    postCommand(const std::string& cmd);
    LONG_PTR                HWND() const;
    std::string             windowTitle() const;
    void                    startUndoMark();
    void                    endUndoMark();
    PyAcadDatabase          database();
    PyAcadMaterial          activeMaterial() const;
    void                    setActiveMaterial(const PyAcadMaterial& val);

    static std::string  className();
public:
    PyIAcadDocumentImpl* impObj(const std::source_location& src = std::source_location::current()) const;
public:
};

//----------------------------------------------------------------------------------------
//PyAcadUtility
void makePyAcadUtilityWrapper();

class PyAcadUtility
{
public:
    PyAcadUtility() = default;
    PyAcadUtility(std::shared_ptr<PyIAcadUtilityImpl> ptr);
    virtual ~PyAcadUtility() = default;

    double                  angleToReal(const std::string& angle, PyAcAngleUnits unit);
    std::string             angleToString(double angle, PyAcAngleUnits unit, int precision);
    double                  distanceToReal(const std::string& dist, PyAcUnits unit);
    std::string             realToString(double angle, PyAcUnits unit, int precision);
    AcGePoint3d             translateCoordinates1(const AcGePoint3d& point, PyAcCoordinateSystem fromCoordSystem, PyAcCoordinateSystem toCoordSystem, int displacement);
    AcGePoint3d             translateCoordinates2(const AcGePoint3d& point, PyAcCoordinateSystem fromCoordSystem, PyAcCoordinateSystem toCoordSystem, int displacement, const AcGeVector3d& normal);
    void                    initializeUserInput(int bits, const std::string& keyWordList);
    int                     getInteger(const std::string& prompt);
    double                  getReal(const std::string& prompt);
    std::string             getInput();
    std::string             getKeyword(const std::string& prompt);
    std::string             getString(int hasSpaces, const std::string& prompt);
    double                  getAngle1(const std::string& prompt);
    double                  getAngle2(const AcGePoint3d& point, const std::string& prompt);
    double                  angleFromXAxis(const AcGePoint3d& startPoint, const AcGePoint3d& endPoint);
    AcGePoint3d             getCorner(const AcGePoint3d& point, const std::string& prompt);
    double                  getDistance(const AcGePoint3d& point, const std::string& prompt);
    double                  getOrientation(const AcGePoint3d& point, const std::string& prompt);
    AcGePoint3d             getPoint1(const std::string& prompt);
    AcGePoint3d             getPoint2(const AcGePoint3d& point, const std::string& prompt);
    AcGePoint3d             polarPoint(const AcGePoint3d& point, double angle, double distance);
    boost::python::tuple    getEntity(const std::string& prompt);
    void                    prompt(const std::string& prompt);
    boost::python::tuple    getSubEntity(const std::string& prompt);
    bool                    isURL(const std::string& URL);
    std::string             getRemoteFile(const std::string& URL, bool ignoreCache);
    void                    putRemoteFile(const std::string& URL, const std::string& localFile);
    boost::python::tuple    isRemoteFile(const std::string& localFile);
    boost::python::tuple    launchBrowserDialog(const std::string& title, const std::string& caption, const std::string& URL, const std::string& regkey, bool bnEnabled);
    void                    sendModelessOperationStart(const std::string& context);
    void                    sendModelessOperationEnded(const std::string& context);
    std::string             getObjectIdString(const PyAcadEntity& obj, bool bHex);

    static std::string      className();
public:
    PyIAcadUtilityImpl* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    std::shared_ptr<PyIAcadUtilityImpl> m_pyImp;
};

//----------------------------------------------------------------------------------------
//PyAcadSecurityParams
void makePyAcadSecurityParamsWrapper();

class PyAcadSecurityParams
{
public:
    PyAcadSecurityParams() = default;
    PyAcadSecurityParams(std::shared_ptr<PyIAcadSecurityParamsImpl> ptr);
    virtual ~PyAcadSecurityParams() = default;
    static std::string className();
public:
    PyIAcadSecurityParamsImpl* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    std::shared_ptr<PyIAcadSecurityParamsImpl> m_pyImp;
};

//----------------------------------------------------------------------------------------
//PyAcadSelectionSet
void makePyAcadSelectionSetWrapper();

class PyAcadSelectionSet
{
public:
    PyAcadSelectionSet() = default;
    PyAcadSelectionSet(std::shared_ptr<PyIAcadSelectionSetImpl> ptr);
    virtual ~PyAcadSelectionSet() = default;
    long                count() const;
    PyAcadEntity        item(long ind) const;
    void                _delete();
    boost::python::list entities() const;
    void                selectAll1();
    void                selectAll2(const boost::python::object& filter);
    void                selectWindow1(const AcGePoint3d& pt1, const AcGePoint3d& pt2);
    void                selectWindow2(const AcGePoint3d& pt1, const AcGePoint3d& pt2, const boost::python::object& filter);
    void                selectCrossing1(const AcGePoint3d& pt1, const AcGePoint3d& pt2);
    void                selectCrossing2(const AcGePoint3d& pt1, const AcGePoint3d& pt2, const boost::python::object& filter);
    void                selectFence1(const boost::python::object& points);
    void                selectFence2(const boost::python::object& points, const boost::python::object& filter);

    static std::string className();
public:
    PyIAcadSelectionSetImpl* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    std::shared_ptr<PyIAcadSelectionSetImpl> m_pyImp;
public:
    void filliterator();
    std::vector<PyAcadEntity>::iterator begin();
    std::vector<PyAcadEntity>::iterator end();
    std::vector<PyAcadEntity> m_iterable{ 0 };
};

//----------------------------------------------------------------------------------------
//PyAcadSelectionSets
void makePyAcadSelectionSetsWrapper();

class PyAcadSelectionSets
{
public:
    PyAcadSelectionSets() = default;
    PyAcadSelectionSets(std::shared_ptr<PyIAcadSelectionSetsImpl> ptr);
    virtual ~PyAcadSelectionSets() = default;
    long                    count() const;
    PyAcadSelectionSet      add(const std::string& name);
    PyAcadSelectionSet      item(long index) const;
    static std::string className();
public:
    PyIAcadSelectionSetsImpl* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    std::shared_ptr<PyIAcadSelectionSetsImpl> m_pyImp;
};
