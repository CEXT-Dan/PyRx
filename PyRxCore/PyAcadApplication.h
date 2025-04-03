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

class PyAcadTable;

class PyAcadDimAligned;
class PyAcadDimAngular;
class PyAcadDimDiametric;
class PyAcadDimRotated;
class PyAcadDimOrdinate;
class PyAcadDimRadial;
class PyAcadDimRadialLarge;
class PyAcadDim3PointAngular;
class PyAcadDimArcLength;

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
//PyAcadGroup
void makePyAcadGroupWrapper();

class PyAcadGroup : public PyAcadObject
{
public:
    PyAcadGroup() = default;
    PyAcadGroup(std::shared_ptr<PyIAcadGroupImpl> ptr);
    virtual ~PyAcadGroup() override = default;

    PyAcadEntity        item(long ind) const;
    boost::python::list items() const;
    long                count() const;
    void                setTrueColor(const PyAcadAcCmColor& val) const;
    void                setLayer(const std::string& val) const;
    void                setLinetype(const std::string& val) const;
    void                setLinetypeScale(double val) const;
    void                setVisible(bool val) const;
    void                highlight(bool val) const;
    void                setPlotStyleName(const std::string& val) const;
    void                setLineWeight(PyAcLineWeight val) const;
    std::string         name() const;
    void                setName(const std::string& val) const;
    void                appendItems(const boost::python::object& objects) const;
    void                removeItems(const boost::python::object& objects) const;
    void                update() const;
    void                setMaterial(const std::string& val) const;
    void                setColor(PyAcColor val) const;

    static PyAcadGroup cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadGroupImpl* impObj(const std::source_location& src = std::source_location::current()) const;
    void filliterator();
    PyAcadEntityArray::iterator begin();
    PyAcadEntityArray::iterator end();
    PyAcadEntityArray m_iterable{ 0 };
};

//----------------------------------------------------------------------------------------
//PyAcadGroups
void makePyAcadGroupsWrapper();

class PyAcadGroups : public PyAcadObject
{
public:
    PyAcadGroups() = default;
    PyAcadGroups(std::shared_ptr<PyIAcadGroupsImpl> ptr);
    virtual ~PyAcadGroups() override = default;
    long                count() const;
    PyAcadGroup         item(long index) const;
    PyAcadGroup         add(const std::string& name) const;
    boost::python::list items() const;
    static PyAcadGroups cast(const PyAcadObject& src);
    static std::string  className();
public:
    PyIAcadGroupsImpl* impObj(const std::source_location& src = std::source_location::current()) const;
    void filliterator();
    std::vector<PyAcadGroup>::iterator begin();
    std::vector<PyAcadGroup>::iterator end();
    std::vector<PyAcadGroup> m_iterable{ 0 };
};

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
    void                    setName(const std::string& val) const;
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
    void                    setExplodable(bool val) const;
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
    boost::python::list     addRegion(const boost::python::object& curves) const;
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
    PyAcadHatch             addHatch(int patternType, const std::string& patternName, bool associativity, PyAcHatchObjectType ht);
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
    PyAcadPViewport         addPViewport(const AcGePoint3d& center, double width, double height);
    static PyAcadPaperSpace cast(const PyAcadObject& src);
    static std::string      className();
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
    bool                has(const std::string& name) const;
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
    PyAcadState             acadState() const;
    boost::python::list     listArx() const;
    void                    loadArx(const std::string& sval) const;
    void                    loadDVB(const std::string& sval) const;
    void                    quit() const;
    void                    runMacro(const std::string& sval) const;
    void                    unloadArx(const std::string& sval) const;
    void                    unloadDVB(const std::string& sval) const;
    void                    update() const;
    void                    zoomAll() const;
    void                    zoomCenter(const AcGePoint3d& pnt, double magnify) const;
    void                    zoomExtents() const;
    void                    zoomPickWindow() const;
    void                    zoomPrevious() const;
    void                    zoomScaled(double magnify, PyAcZoomScaleType scaletype) const;
    PyAcadDocument          activeDocument() const;
    void                    setActiveDocument(const PyAcadDocument& val) const;
    std::string             caption() const;
    void                    setCaption(const std::string& val) const;
    PyAcadDocuments         documents() const;
    std::string             fullName() const;
    int                     getHeight() const;
    void                    setHeight(int val) const;
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
    void                    setVisible(bool val) const;
    int                     getWidth() const;
    void                    setWidth(int val) const;
    int                     getWindowLeft() const;
    void                    setWindowLeft(int val) const;
    PyAcWindowState         getWindowState() const;
    void                    setWindowState(PyAcWindowState val) const;
    int                     getWindowTop() const;
    void                    setWindowTop(int val) const;
    static std::string      className();

    //internal 
    static bool             runTest();
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
    PyAcadDocument      add1() const;
    PyAcadDocument      add2(const std::string& _template) const;
    void                close() const;
    PyAcadDocument      item(long index) const;
    PyAcadDocument      open(const std::string& path, bool readOnly) const;
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
    boost::python::list         copyObjects(const boost::python::object& objs, const PyAcadObject& owner) const;
    PyAcadGroups                groups() const;
    PyAcadDimStyles             dimStyles() const;
    PyAcadLayers                layers() const;
    PyAcadLineTypes             lineTypes() const;
    PyAcadDictionaries          dictionaries() const;
    PyAcadRegisteredApplications registeredApplications() const;
    PyAcadTextStyles            textStyles() const;
    PyAcadUCSs                  userCoordinateSystems() const;
    PyAcadViews                 views() const;
    PyAcadViewports             viewports() const;
    double                      elevationModelSpace() const;
    void                        setElevationModelSpace(double val) const;
    double                      elevationPaperSpace() const;
    void                        setElevationPaperSpace(double val) const;
    boost::python::tuple        limits() const;
    void                        setLimits(boost::python::tuple minmax) const;
    PyAcadObject                handleToObject(const std::string& val) const;
    PyAcadObject                objectIdToObject(const PyDbObjectId& val) const;
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
    void                    setActiveLayer(const PyAcadLayer& obj) const;
    PyAcadLineType          activeLinetype() const;
    void                    setActiveLinetype(const PyAcadLineType& obj) const;
    PyAcadDimStyle          activeDimStyle() const;
    void                    setActiveDimStyle(const PyAcadDimStyle& obj) const;
    PyAcadTextStyle         activeTextStyle() const;
    void                    setActiveTextStyle(const PyAcadTextStyle& obj) const;
    PyAcadUCS               activeUCS() const;
    void                    setActiveUCS(const PyAcadUCS& obj) const;
    PyAcadViewport          activeViewport() const;
    void                    setActiveViewport(const PyAcadViewport& obj) const;
    PyAcadPViewport         activePViewport() const;
    void                    setActivePViewport(const PyAcadPViewport& obj) const;
    PyAcActiveSpace         activeSpace() const;
    void                    setActiveSpace(PyAcActiveSpace sp) const;
    PyAcadSelectionSets     selectionSets() const;
    PyAcadSelectionSet      activeSelectionSet() const;
    std::string             name() const;
    std::string             fullName() const;
    std::string             path() const;
    bool                    objectSnapMode() const;
    void                    setObjectSnapMode(bool flag) const;
    bool                    isReadOnly() const;
    bool                    isSaved() const;
    bool                    mSpace() const;
    void                    setMSpace(bool flag) const;
    PyAcadUtility           utility() const;
    PyAcadDocument          open(const std::string& path) const;
    void                    auditInfo(bool flag) const;
    PyAcadBlockReference    importFile(const std::string& path, const AcGePoint3d& InsertionPoint, double scaleFactor) const;
    void                    exportToFile(const std::string& fileName, const std::string& extension, const PyAcadSelectionSet& sset) const;
    PyAcadDocument          newDoc(const std::string& path) const;
    void                    save() const;
    void                    saveAs1(const std::string& fileName) const;
    void                    saveAs2(const std::string& fileName, PyAcSaveAsType saType) const;
    void                    saveAs3(const std::string& fileName, PyAcSaveAsType saType, const PyAcadSecurityParams& pr) const;
    void                    wblock(const std::string& fileName, const PyAcadSelectionSet& sset) const;
    void                    purgeAll() const;
    boost::python::object   getVariable(const std::string& name) const;
    void                    setVariable(const std::string& name, const boost::python::object& obj) const;
    void                    loadShapeFile(const std::string& name) const;
    void                    regen(PyAcRegenType rt) const;
    PyAcadSelectionSet      pickfirstSelectionSet() const;
    bool                    isActive() const;
    void                    activate() const;
    void                    close1() const;
    void                    close2(bool saveChanges) const;
    void                    close3(bool saveChanges, const std::string& fileName) const;
    PyAcWindowState         windowState() const;
    void                    setWindowState(PyAcWindowState val) const;
    int                     width() const;
    void                    setWidth(int val) const;
    int                     height() const;
    void                    setHeight(int val) const;
    PyAcadLayout            activeLayout() const;
    void                    setActiveLayout(const PyAcadLayout& val) const;
    void                    sendCommand(const std::string& cmd) const;
    void                    postCommand(const std::string& cmd) const;
    LONG_PTR                HWND() const;
    std::string             windowTitle() const;
    void                    startUndoMark() const;
    void                    endUndoMark() const;
    PyAcadDatabase          database() const;
    PyAcadMaterial          activeMaterial() const;
    void                    setActiveMaterial(const PyAcadMaterial& val) const;

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

    double                  angleToReal(const std::string& angle, PyAcAngleUnits unit) const;
    std::string             angleToString(double angle, PyAcAngleUnits unit, int precision) const;
    double                  distanceToReal(const std::string& dist, PyAcUnits unit) const;
    std::string             realToString(double angle, PyAcUnits unit, int precision) const;
    AcGePoint3d             translateCoordinates1(const AcGePoint3d& point, PyAcCoordinateSystem fromCoordSystem, PyAcCoordinateSystem toCoordSystem, int displacement) const;
    AcGePoint3d             translateCoordinates2(const AcGePoint3d& point, PyAcCoordinateSystem fromCoordSystem, PyAcCoordinateSystem toCoordSystem, int displacement, const AcGeVector3d& normal) const;
    void                    initializeUserInput(int bits, const std::string& keyWordList) const;
    int                     getInteger(const std::string& prompt) const;
    double                  getReal(const std::string& prompt) const;
    std::string             getInput() const;
    std::string             getKeyword(const std::string& prompt) const;
    std::string             getString(int hasSpaces, const std::string& prompt) const;
    double                  getAngle1(const std::string& prompt) const;
    double                  getAngle2(const AcGePoint3d& point, const std::string& prompt) const;
    double                  angleFromXAxis(const AcGePoint3d& startPoint, const AcGePoint3d& endPoint) const;
    AcGePoint3d             getCorner(const AcGePoint3d& point, const std::string& prompt) const;
    double                  getDistance(const AcGePoint3d& point, const std::string& prompt) const;
    double                  getOrientation(const AcGePoint3d& point, const std::string& prompt) const;
    AcGePoint3d             getPoint1(const std::string& prompt) const;
    AcGePoint3d             getPoint2(const AcGePoint3d& point, const std::string& prompt) const;
    AcGePoint3d             polarPoint(const AcGePoint3d& point, double angle, double distance) const;
    boost::python::tuple    getEntity(const std::string& prompt) const;
    void                    prompt(const std::string& prompt) const;
    boost::python::tuple    getSubEntity(const std::string& prompt) const;
    bool                    isURL(const std::string& URL) const;
    std::string             getRemoteFile(const std::string& URL, bool ignoreCache) const;
    void                    putRemoteFile(const std::string& URL, const std::string& localFile) const;
    boost::python::tuple    isRemoteFile(const std::string& localFile) const;
    boost::python::tuple    launchBrowserDialog(const std::string& title, const std::string& caption, const std::string& URL, const std::string& regkey, bool bnEnabled) const;
    void                    sendModelessOperationStart(const std::string& context) const;
    void                    sendModelessOperationEnded(const std::string& context) const;
    std::string             getObjectIdString(const PyAcadEntity& obj, bool bHex) const;

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
    void                _delete() const;
    std::string         name() const;
    void                highlight(bool flag) const;
    void                erase() const;
    void                update() const;
    void                addItems(const boost::python::object& pyents) const;
    void                removeItems(const boost::python::object& pyents) const;
    void                clear() const;
    boost::python::list entities() const;
    void                selectAll1() const;
    void                selectAll2(const boost::python::object& filter) const;
    void                selectOnScreen1() const;
    void                selectOnScreen2(const boost::python::object& filter) const;
    void                selectLast() const;
    void                selectWindow1(const AcGePoint3d& pt1, const AcGePoint3d& pt2) const;
    void                selectWindow2(const AcGePoint3d& pt1, const AcGePoint3d& pt2, const boost::python::object& filter) const;
    void                selectCrossing1(const AcGePoint3d& pt1, const AcGePoint3d& pt2) const;
    void                selectCrossing2(const AcGePoint3d& pt1, const AcGePoint3d& pt2, const boost::python::object& filter) const;
    void                selectFence1(const boost::python::object& points) const;
    void                selectFence2(const boost::python::object& points, const boost::python::object& filter) const;
    void                selectWindowPolygon1(const boost::python::object& points) const;
    void                selectWindowPolygon2(const boost::python::object& points, const boost::python::object& filter) const;
    void                selectCrossingPolygon1(const boost::python::object& points) const;
    void                selectCrossingPolygon2(const boost::python::object& points, const boost::python::object& filter) const;
    void                selectAtPoint1(const AcGePoint3d& pt1) const;
    void                selectAtPoint2(const AcGePoint3d& pt1, const boost::python::object& filter) const;
    static std::string  className();
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
    PyAcadSelectionSet      add(const std::string& name) const;
    PyAcadSelectionSet      item(long index) const;
    static std::string      className();
public:
    PyIAcadSelectionSetsImpl* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    std::shared_ptr<PyIAcadSelectionSetsImpl> m_pyImp;
};
