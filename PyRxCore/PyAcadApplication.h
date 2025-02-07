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

class PyAcadSummaryInfo;
class PyAcadDocument;
class PyAcadMenuBar;
class PyAcadMenuBar;
class PyAcadMenuGroups;
class PyAcadPreferences;
class PyAcadModelSpace;
class PyAcadPaperSpace;
class PyAcadEntity;

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
    explicit PyAcadDatabase(std::shared_ptr<PyIAcadDatabaseImpl> ptr) noexcept;
    virtual ~PyAcadDatabase() = default;
    PyAcadModelSpace      modelSpace() const;
    PyAcadPaperSpace      paperSpace() const;
    PyAcadSummaryInfo     summaryInfo() const;
    static std::string    className();
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
    std::string           name() const;
    PyAcadDatabase        database();
    static std::string    className();
public:
    PyIAcadDocumentImpl* impObj(const std::source_location& src = std::source_location::current()) const;
public:
};

