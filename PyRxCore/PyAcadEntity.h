#pragma once

#include "PyAcadObject.h"
#include "PyAcadDbObject.h"
#include "PyAcAxCommon.h"

#pragma pack (push, 8)

//----------------------------------------------------------------------------------------
//Impl forwards
class PyIAcadEntityImpl;
class PyIAcad3DFaceImpl;
class PyIAcadPolygonMeshImpl;
class PyIAcad3DPolylineImpl;
class PyIAcadArcImpl;
class PyIAcadAttributeImpl;
class PyIAcadRegionImpl;
class PyIAcad3DSolidImpl;
class PyIAcadCircleImpl;
class PyIAcadDimensionImpl;
class PyIAcadDimAlignedImpl;
class PyIAcadDimAngularImpl;
class PyIAcadDimDiametricImpl;
class PyIAcadDimRotatedImpl;
class PyIAcadDimOrdinateImpl;
class PyIAcadDimRadialImpl;
class PyIAcadDim3PointAngularImpl;
class PyIAcadDimArcLengthImpl;
class PyIAcadDimRadialLargeImpl;
class PyIAcadEllipseImpl;
class PyIAcadLeaderImpl;
class PyIAcadMTextImpl;
class PyIAcadPointImpl;
class PyIAcadLWPolylineImpl;
class PyIAcadPolylineImpl;
class PyIAcadRayImpl;
class PyIAcadShapeImpl;
class PyIAcadSolidImpl;
class PyIAcadSplineImpl;
class PyIAcadTextImpl;
class PyIAcadToleranceImpl;
class PyIAcadTraceImpl;
class PyIAcadXlineImpl;
class PyIAcadBlockReferenceImpl;
class PyIAcadHatchImpl;
class PyIAcadRasterImageImpl;
class PyIAcadLineImpl;
class PyIAcadMInsertBlockImpl;
class PyIAcadPolyfaceMeshImpl;
class PyIAcadMLineImpl;
class PyIAcadExternalReferenceImpl;
class PyIAcadTableImpl;
class PyIAcadSectionImpl;
class PyIAcadMLeaderImpl;
class PyAcadAcCmColor;
class PyAcadAcCmColorImpl;
class PyAcadHyperlinks;
class PyAcadHyperlinksImpl;
class PyIAcadPViewportImpl;
class PyIAcadAttributeReferenceImpl;

//----------------------------------------------------------------------------------------
//PyAcadEntity
void makePyAcadEntityWrapper();

class PyAcadEntity : public PyAcadObject
{
public:
    PyAcadEntity() = default;
    PyAcadEntity(std::shared_ptr<PyIAcadEntityImpl> ptr);
    virtual ~PyAcadEntity() override = default;
    PyAcadAcCmColor         trueColor() const;
    void                    setTrueColor(const PyAcadAcCmColor& val) const;
    std::string             layer() const;
    void                    setLayer(const std::string& val) const;
    std::string             linetype() const;
    void                    setLinetype(const  std::string& val) const;
    double                  linetypeScale() const;
    void                    setLinetypeScale(double val) const;
    bool                    isVisible() const;
    void                    setVisible(bool bVisible) const;
    boost::python::list     arrayPolar(int numberOfObjects, double angleToFill, const AcGePoint3d& centerPoint) const;
    boost::python::list     arrayRectangular(int nRows, int nColumns, int nLevels, double rowDist, double colDist, double levelDist) const;
    void                    highlight(bool highlight) const;
    PyAcadEntity            copy() const;
    void                    move(const AcGePoint3d& fromPoint, const AcGePoint3d& toPoint) const;
    void                    rotate(const AcGePoint3d& basePoint, double rotationAngle) const;
    void                    rotate3D(const AcGePoint3d& point1, const AcGePoint3d& point2, double rotationAngle) const;
    PyAcadEntity            mirror(const AcGePoint3d& point1, const AcGePoint3d& point2) const;
    PyAcadEntity            mirror3D(const AcGePoint3d& point1, const AcGePoint3d& point2, const AcGePoint3d& point3) const;
    void                    scaleEntity(const AcGePoint3d& basePoint, double scaleFactor) const;
    void                    transformBy(const AcGeMatrix3d& xform) const;
    void                    update() const;
    boost::python::tuple    boundingBox() const;
    boost::python::list     intersectWith(const PyAcadEntity& intersectObject, PyAcExtendOption option) const;
    std::string             plotStyleName() const;
    void                    setPlotStyleName(const std::string& val) const;
    PyAcLineWeight          lineweight() const;
    void                    setLineweight(PyAcLineWeight lw) const;
    std::string             entityTransparency() const;
    void                    setEntityTransparency(const std::string& val) const;
    PyAcadHyperlinks        hyperlinks() const;
    std::string             material() const;
    void                    setMaterial(const std::string& val) const;
    std::string             entityName() const;
    long                    entityType() const;
    PyAcColor               color() const;
    void                    setColor(PyAcColor color) const;

    static PyAcadEntity     cast(const PyAcadObject& src);
    static std::string      className();
public:
    PyIAcadEntityImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadPViewport
void makePyAcadPViewportWrapper();

class PyAcadPViewport : public PyAcadEntity
{
public:
    PyAcadPViewport() = default;
    PyAcadPViewport(std::shared_ptr<PyIAcadPViewportImpl> ptr);
    virtual ~PyAcadPViewport() override = default;

    AcGePoint3d         center() const;
    void                setCenter(const AcGePoint3d& val) const;
    AcGeVector3d        direction() const;
    void                setDirection(const AcGeVector3d& val) const;
    bool                gridOn() const;
    void                setGridOn(bool bVisible) const;
    double              height() const;
    void                setHeight(double val) const;
    double              width() const;
    void                setWidth(double val) const;
    bool                viewportOn() const;
    void                setViewportOn(bool bVisible) const;
    bool                clipped() const;
    bool                displayLocked() const;
    void                setDisplayLocked(bool bVisible) const;
    PyAcViewportScale   standardScale() const;
    void                setStandardScale(PyAcViewportScale val) const;
    double              customScale() const;
    void                setCustomScale(double val) const;
    std::string         styleSheet() const;
    void                setStyleSheet(const std::string& val) const;
    bool                ucsPerViewport() const;
    void                setUCSPerViewport(bool UCSSaved) const;
    AcGePoint2d         snapBasePoint() const;
    void                setSnapBasePoint(const AcGePoint2d& val) const;
    bool                snapOn() const;
    void                setSnapOn(bool UCSSaved) const;
    double              snapRotationAngle() const;
    void                setSnapRotationAngle(double val) const;
    bool                ucsIconOn() const;
    void                setUCSIconOn(bool bIconOn) const;
    bool                ucsIconAtOrigin() const;
    void                setUCSIconAtOrigin(bool bIconAtOrigin) const;
    boost::python::tuple    gridSpacing() const;
    void                    setGridSpacing(double XSpacing, double YSpacing) const;
    boost::python::tuple    snapSpacing() const;
    void                    setSnapSpacing(double XSpacing, double YSpacing) const;
    void                display(bool bStatus) const;
    double              twistAngle() const;
    void                setTwistAngle(double val) const;
    double              lensLength() const;
    void                setLensLength(double val) const;
    bool                removeHiddenLines() const;
    void                setRemoveHiddenLines(bool bRemoval) const;
    AcGePoint3d         target() const;
    void                setTarget(const AcGePoint3d& val) const;
    long                arcSmoothness() const;
    void                setArcSmoothness(long val) const;
    int                 visualStyle() const;
    void                setVisualStyle(int val) const;
    int                 shadePlot() const;
    void                setShadePlot(int val) const;
    PyAcadView          modelView() const;
    void                setModelView(const PyAcadView& val) const;
    PyAcadView          sheetView() const;
    void                setSheetView(const PyAcadView& val) const;
    PyDbObjectId        labelBlockId() const;
    void                setLabelBlockId(const PyDbObjectId& id) const;
    bool                hasSheetView() const;
    void                syncModelView() const;
    int                 standardScale2() const;
    void                setStandardScale2(int val) const;
    bool                layerPropertyOverrides() const;

    static PyAcadPViewport cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadPViewportImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcad3DFace
void makePyAcad3DFaceWrapper();

class PyAcad3DFace : public PyAcadEntity
{
public:
    PyAcad3DFace() = default;
    PyAcad3DFace(std::shared_ptr<PyIAcad3DFaceImpl> ptr);
    virtual ~PyAcad3DFace() override = default;
    boost::python::list coordinates() const;
    void                setCoordinates(const AcGePoint3d& p1, const AcGePoint3d& p2, const AcGePoint3d& p3, const AcGePoint3d& p4) const;
    bool                invisibleEdge(int index) const;
    void                setInvisibleEdge(int index, bool flag) const;
    AcGePoint3d         coordinate(int index) const;
    void                setCoordinate(int index, const AcGePoint3d& val) const;
    static PyAcad3DFace cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcad3DFaceImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadPolygonMesh
void makePyAcadPolygonMeshWrapper();

class PyAcadPolygonMesh : public PyAcadEntity
{
public:
    PyAcadPolygonMesh() = default;
    PyAcadPolygonMesh(std::shared_ptr<PyIAcadPolygonMeshImpl> ptr);
    virtual ~PyAcadPolygonMesh() override = default;

    boost::python::list     coordinates() const;
    void                    setCoordinates(const boost::python::object& coords) const;
    bool                    mClose() const;
    void                    setMClose(bool val) const;
    bool                    nClose() const;
    void                    setNClose(bool val) const;
    long                    mDensity() const;
    void                    setMDensity(long val) const;
    long                    nDensity() const;
    void                    setNDensity(long val) const;
    long                    mVertexCount() const;
    long                    nVertexCount() const;
    PyAcPolymeshType        getType() const;
    void                    setType(PyAcPolymeshType val) const;
    void                    appendVertex(const AcGePoint3d& val) const;
    boost::python::list     explode() const;
    AcGePoint3d             coordinate(int index) const;
    void                    setCoordinate(int index, const AcGePoint3d& val) const;

    static PyAcadPolygonMesh cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadPolygonMeshImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcad3DPolyline
void makePyAcad3DPolylineWrapper();

class PyAcad3DPolyline : public PyAcadEntity
{
public:
    PyAcad3DPolyline() = default;
    PyAcad3DPolyline(std::shared_ptr<PyIAcad3DPolylineImpl> ptr);
    virtual ~PyAcad3DPolyline() override = default;

    boost::python::list     coordinates() const;
    void                    setCoordinates(const boost::python::object& coords) const;
    void                    appendVertex(const AcGePoint3d& val) const;
    boost::python::list     explode() const;
    AcGePoint3d             coordinate(int index) const;
    void                    setCoordinate(int index, const AcGePoint3d& val) const;
    PyAc3DPolylineType      getType() const;
    void                    setType(PyAc3DPolylineType val) const;
    bool                    isClosed() const;
    void                    setClosed(bool val) const;
    double                  length() const;

    static PyAcad3DPolyline cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcad3DPolylineImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadArc
void makePyAcadArcWrapper();

class PyAcadArc : public PyAcadEntity
{
public:
    PyAcadArc() = default;
    PyAcadArc(std::shared_ptr<PyIAcadArcImpl> ptr);
    virtual ~PyAcadArc() override = default;

    AcGePoint3d             startPoint() const;
    AcGePoint3d             center() const;
    void                    setCenter(const AcGePoint3d& val) const;
    AcGePoint3d             endPoint() const;
    double                  radius() const;
    void                    setRadius(double val) const;
    double                  startAngle() const;
    void                    setStartAngle(double val) const;
    double                  endAngle() const;
    void                    setEndAngle(double val) const;
    double                  totalAngle() const;
    double                  arcLength() const;
    double                  thickness() const;
    void                    setThickness(double val) const;
    boost::python::list     offset(double val) const;
    double                  area() const;
    AcGeVector3d            normal() const;
    void                    setNormal(const AcGeVector3d& val) const;

    static PyAcadArc cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadArcImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadAttribute
void makePyAcadAttributeWrapper();

class PyAcadAttribute : public PyAcadEntity
{
public:
    PyAcadAttribute() = default;
    PyAcadAttribute(std::shared_ptr<PyIAcadAttributeImpl> ptr);
    virtual ~PyAcadAttribute() override = default;

    long                    fieldLength() const;
    void                    setFieldLength(long val) const;
    std::string             tagString() const;
    void                    setTagString(const std::string& val) const;
    std::string             promptString() const;
    void                    setPromptString(const std::string& val) const;
    std::string             textString() const;
    void                    setTextString(const std::string& val) const;
    std::string             styleName() const;
    void                    setStyleName(const std::string& val) const;
    PyAcAlignment           alignment() const;
    void                    setAlignment(PyAcAlignment val) const;
    PyAcHorizontalAlignment horizontalAlignment() const;
    void                    setHorizontalAlignment(PyAcHorizontalAlignment val) const;
    PyAcVerticalAlignment   verticalAlignment() const;
    void                    setVerticalAlignment(PyAcVerticalAlignment val) const;
    double                  height() const;
    void                    setHeight(double val) const;
    double                  rotation() const;
    void                    setRotation(double val) const;
    double                  scaleFactor() const;
    void                    setScaleFactor(double val) const;
    double                  obliqueAngle() const;
    void                    setObliqueAngle(double val) const;
    AcGePoint3d             textAlignmentPoint() const;
    void                    setTextAlignmentPoint(const AcGePoint3d& val) const;
    AcGePoint3d             insertionPoint() const;
    void                    setInsertionPoint(const AcGePoint3d& val) const;
    AcGeVector3d            normal() const;
    void                    setNormal(const AcGeVector3d& val) const;
    long                    textGenerationFlag() const;
    void                    setTextGenerationFlag(long val) const;
    double                  thickness() const;
    void                    setThickness(double val) const;
    long                    mode() const;
    void                    setMode(long val) const;
    bool                    upsideDown() const;
    void                    setUpsideDown(bool val) const;
    bool                    backward() const;
    void                    setBackward(bool val) const;
    bool                    invisible() const;
    void                    setInvisible(bool val) const;
    bool                    constant() const;
    void                    setConstant(bool val) const;
    bool                    verify() const;
    void                    setVerify(bool val) const;
    bool                    preset() const;
    void                    setPreset(bool val) const;
    bool                    lockPosition() const;
    void                    setLockPosition(bool val) const;
    bool                    isMTextAttribute() const;
    void                    setIsMTextAttribute(bool val) const;
    std::string             mtextAttributeContent() const;
    void                    setMTextAttributeContent(const std::string& val) const;
    void                    updateMTextAttribute() const;
    double                  mtextBoundaryWidth() const;
    void                    setMTextBoundaryWidth(double val) const;
    PyAcDrawingDirection    mtextDrawingDirection() const;
    void                    setMTextDrawingDirection(PyAcDrawingDirection val) const;

    static PyAcadAttribute cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadAttributeImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadAttributeReference
void makePyAcadAttributeReferenceWrapper();

class PyAcadAttributeReference : public PyAcadEntity
{
public:
    PyAcadAttributeReference() = default;
    PyAcadAttributeReference(std::shared_ptr<PyIAcadAttributeReferenceImpl> ptr);
    virtual ~PyAcadAttributeReference() override = default;

    double                  height() const;
    void                    setHeight(double val) const;
    PyAcAlignment           alignment() const;
    void                    setAlignment(PyAcAlignment val) const;
    PyAcHorizontalAlignment horizontalAlignment() const;
    void                    setHorizontalAlignment(PyAcHorizontalAlignment val) const;
    PyAcVerticalAlignment   verticalAlignment() const;
    void                    setVerticalAlignment(PyAcVerticalAlignment val) const;
    AcGePoint3d             insertionPoint() const;
    void                    setInsertionPoint(const AcGePoint3d& val) const;
    AcGeVector3d            normal() const;
    void                    setNormal(const AcGeVector3d& val) const;
    double                  obliqueAngle() const;
    void                    setObliqueAngle(double val) const;
    double                  rotation() const;
    void                    setRotation(double val) const;
    double                  scaleFactor() const;
    void                    setScaleFactor(double val) const;
    std::string             styleName() const;
    void                    setStyleName(const std::string& val) const;
    std::string             tagString() const;
    void                    setTagString(const std::string& val) const;
    AcGePoint3d             textAlignmentPoint() const;
    void                    setTextAlignmentPoint(const AcGePoint3d& val) const;
    long                    textGenerationFlag() const;
    void                    setTextGenerationFlag(long val) const;
    std::string             textString() const;
    void                    setTextString(const std::string& val) const;
    double                  thickness() const;
    void                    setThickness(double val) const;
    long                    fieldLength() const;
    void                    setFieldLength(long val) const;
    bool                    upsideDown() const;
    void                    setUpsideDown(bool val) const;
    bool                    backward() const;
    void                    setBackward(bool val) const;
    bool                    invisible() const;
    void                    setInvisible(bool val) const;
    bool                    constant() const;
    bool                    lockPosition() const;
    bool                    isMTextAttribute() const;
    void                    setIsMTextAttribute(bool val) const;
    std::string             mtextAttributeContent() const;
    void                    setMTextAttributeContent(const std::string& val) const;
    void                    updateMTextAttribute() const;
    double                  mtextBoundaryWidth() const;
    void                    setMTextBoundaryWidth(double val) const;
    PyAcDrawingDirection    mtextDrawingDirection() const;
    void                    setMTextDrawingDirection(PyAcDrawingDirection val) const;

    static PyAcadAttributeReference cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadAttributeReferenceImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadRegion
void makePyAcadRegionWrapper();

class PyAcadRegion : public PyAcadEntity
{
public:
    PyAcadRegion() = default;
    PyAcadRegion(std::shared_ptr<PyIAcadRegionImpl> ptr);
    virtual ~PyAcadRegion() override = default;

    double                  area() const;
    AcGePoint2d             centroid() const;
    AcGePoint3d             momentOfInertia() const;
    AcGeVector3d            normal() const;
    double                  perimeter() const;
    boost::python::list     principalDirections() const;
    AcGePoint3d             principalMoments() const;
    AcGePoint3d             radiiOfGyration() const;
    void                    boolean(PyAcBooleanType val, const PyAcadRegion& region) const;
    boost::python::list     explode() const;

    static PyAcadRegion cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadRegionImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcad3DSolid
void makePyAcad3DSolidWrapper();

class PyAcad3DSolid : public PyAcadEntity
{
public:
    PyAcad3DSolid() = default;
    PyAcad3DSolid(std::shared_ptr<PyIAcad3DSolidImpl> ptr);
    virtual ~PyAcad3DSolid() override = default;

    AcGePoint3d         centroid() const;
    AcGePoint3d         momentOfInertia() const;
    boost::python::tuple principalDirections() const;
    AcGePoint3d         principalMoments() const;
    AcGePoint3d         productOfInertia() const;
    AcGePoint3d         radiiOfGyration() const;
    double              volume() const;
    void                boolean(PyAcBooleanType val, const PyAcad3DSolid& solid) const;
    boost::python::tuple checkInterference(const PyAcad3DSolid& solid, bool createInterferenceSolid) const;
    PyAcad3DSolid       sliceSolid(const AcGePoint3d& p1, const AcGePoint3d& p2, const AcGePoint3d& p3, bool negative) const;
    PyAcadRegion        sectionSolid(const AcGePoint3d& p1, const AcGePoint3d& p2, const AcGePoint3d& p3) const;
    std::string         solidType() const;
    AcGePoint3d         position() const;
    void                setPosition(const AcGePoint3d& val) const;
    bool                history() const;
    void                setHistory(bool val) const;
    bool                showHistory() const;
    void                setShowHistory(bool val) const;

    static PyAcad3DSolid cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcad3DSolidImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadCircle
void makePyAcadCircleWrapper();

class PyAcadCircle : public PyAcadEntity
{
public:
    PyAcadCircle() = default;
    PyAcadCircle(std::shared_ptr<PyIAcadCircleImpl> ptr);
    virtual ~PyAcadCircle() override = default;

    AcGePoint3d             center() const;
    void                    setCenter(const AcGePoint3d& val) const;
    double                  radius() const;
    void                    setRadius(double val) const;
    double                  diameter() const;
    void                    setDiameter(double val) const;
    double                  circumference() const;
    void                    setCircumference(double val) const;
    double                  area() const;
    void                    setArea(double val) const;
    AcGeVector3d            normal() const;
    void                    setNormal(const AcGeVector3d& val) const;
    double                  thickness() const;
    void                    setThickness(double val) const;
    boost::python::list     offset(double val) const;

    static PyAcadCircle cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadCircleImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadEllipse
void makePyAcadEllipseWrapper();

class PyAcadEllipse : public PyAcadEntity
{
public:
    PyAcadEllipse() = default;
    PyAcadEllipse(std::shared_ptr<PyIAcadEllipseImpl> ptr);
    virtual ~PyAcadEllipse() override = default;

    AcGePoint3d             startPoint() const;
    AcGePoint3d             endPoint() const;
    AcGePoint3d             center() const;
    void                    setCenter(const AcGePoint3d& val) const;
    double                  majorRadius() const;
    void                    setMajorRadius(double val) const;
    double                  minorRadius() const;
    void                    setMinorRadius(double val) const;
    double                  radiusRatio() const;
    void                    setRadiusRatio(double val) const;
    double                  startAngle() const;
    void                    setStartAngle(double val) const;
    double                  endAngle() const;
    void                    setEndAngle(double val) const;
    double                  startParameter() const;
    void                    setStartParameter(double val) const;
    double                  endParameter() const;
    void                    setEndParameter(double val) const;
    AcGeVector3d            majorAxis() const;
    void                    setMajorAxis(AcGeVector3d val) const;
    AcGeVector3d            minorAxis() const;
    AcGeVector3d            normal() const;
    void                    setNormal(AcGeVector3d val) const;
    double                  area() const;
    boost::python::list     offset(double val) const;

    static PyAcadEllipse cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadEllipseImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadLeader
void makePyAcadLeaderWrapper();

class PyAcadLeader : public PyAcadEntity
{
public:
    PyAcadLeader() = default;
    PyAcadLeader(std::shared_ptr<PyIAcadLeaderImpl> ptr);
    virtual ~PyAcadLeader() override = default;

    boost::python::list     coordinates() const;
    void                    setCoordinates(const boost::python::object& coords) const;
    AcGeVector3d            normal() const;
    std::string             styleName() const;
    void                    setStyleName(const std::string& val) const;
    PyAcLeaderType          leaderType() const;
    void                    setLeaderType(PyAcLeaderType val) const;
    void                    evaluate() const;
    AcGePoint3d             coordinate(int index) const;
    void                    setCoordinate(int index, const AcGePoint3d& val) const;
    PyAcadEntity            annotation() const;
    void                    setAnnotation(const PyAcadEntity& val) const;
    double                  arrowheadSize() const;
    void                    setArrowheadSize(double val) const;
    PyAcDimArrowheadType    arrowheadType() const;
    void                    setArrowheadType(PyAcDimArrowheadType val) const;
    PyAcColor               dimensionLineColor() const;
    void                    setDimensionLineColor(PyAcColor val) const;
    PyAcLineWeight          dimensionLineWeight() const;
    void                    setDimensionLineWeight(PyAcLineWeight val) const;
    double                  scaleFactor() const;
    void                    setScaleFactor(double val) const;
    PyAcDimVerticalJustification    verticalTextPosition() const;
    void                            setVerticalTextPosition(PyAcDimVerticalJustification val) const;
    double                  textGap() const;
    void                    setTextGap(double val) const;
    std::string             arrowheadBlock() const;
    void                    setArrowheadBlock(const std::string& val) const;

    static PyAcadLeader cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadLeaderImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadMText
void makePyAcadMTextWrapper();

class PyAcadMText : public PyAcadEntity
{
public:
    PyAcadMText() = default;
    PyAcadMText(std::shared_ptr<PyIAcadMTextImpl> ptr);
    virtual ~PyAcadMText() override = default;

    std::string             text() const;
    std::string             textString() const;
    void                    setTextString(const std::string& val) const;
    std::string             styleName() const;
    void                    setStyleName(const std::string& val) const;
    PyAcAttachmentPoint     attachmentPoint() const;
    void                    setAttachmentPoint(PyAcAttachmentPoint val) const;
    PyAcDrawingDirection    drawingDirection() const;
    void                    setDrawingDirection(PyAcDrawingDirection val) const;
    double                  width() const;
    void                    setWidth(double val) const;
    double                  height() const;
    void                    setHeight(double val) const;
    double                  rotation() const;
    void                    setRotation(double val) const;
    AcGePoint3d             insertionPoint() const;
    void                    setInsertionPoint(const AcGePoint3d& val) const;
    AcGeVector3d            normal() const;
    void                    setNormal(const AcGeVector3d& val) const;
    double                  lineSpacingFactor() const;
    void                    setLineSpacingFactor(double val) const;
    PyAcLineSpacingStyle    lineSpacingStyle() const;
    void                    setLineSpacingStyle(PyAcLineSpacingStyle val) const;
    double                  lineSpacingDistance() const;
    void                    setLineSpacingDistance(double val) const;
    bool                    backgroundFill() const;
    void                    setBackgroundFill(bool val) const;
    std::string             fieldCode() const;

    static PyAcadMText cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadMTextImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadPoint
void makePyAcadPointWrapper();

class PyAcadPoint : public PyAcadEntity
{
public:
    PyAcadPoint() = default;
    PyAcadPoint(std::shared_ptr<PyIAcadPointImpl> ptr);
    virtual ~PyAcadPoint() override = default;
    AcGePoint3d             coordinates() const;
    void                    setCoordinates(const AcGePoint3d& val) const;
    AcGeVector3d            normal() const;
    void                    setNormal(const AcGeVector3d& val) const;
    double                  thickness() const;
    void                    setThickness(double val) const;
    static PyAcadPoint cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadPointImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadLWPolyline
void makePyAcadLWPolylineWrapper();

class PyAcadLWPolyline : public PyAcadEntity
{
public:
    PyAcadLWPolyline() = default;
    PyAcadLWPolyline(std::shared_ptr<PyIAcadLWPolylineImpl> ptr);
    virtual ~PyAcadLWPolyline() override = default;

    boost::python::list     coordinates() const;
    void                    setCoordinates(const boost::python::object& coords) const;
    AcGeVector3d            normal() const;
    void                    setNormal(const AcGeVector3d& val) const;
    double                  thickness() const;
    void                    setThickness(double val) const;
    void                    addVertex(int index, const AcGePoint2d& val) const;
    boost::python::list     explode() const;
    double                  bulge(int index) const;
    void                    setBulge(int index, double val) const;
    boost::python::tuple    width(int index) const;
    void                    setWidth(int index, double startWidth, double endWidth) const;
    double                  constantWidth() const;
    void                    setConstantWidth(double val) const;
    boost::python::list     offset(double val) const;
    double                  elevation() const;
    void                    setElevation(double val) const;
    double                  area() const;
    AcGePoint2d             coordinate(int index) const;
    void                    setCoordinate(int index, const AcGePoint2d& val) const;
    bool                    isClosed() const;
    void                    setClosed(bool val) const;
    bool                    linetypeGeneration() const;
    void                    setLinetypeGeneration(bool val) const;
    double                  length() const;

    static PyAcadLWPolyline cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadLWPolylineImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadPolyline
void makePyAcadPolylineWrapper();

class PyAcadPolyline : public PyAcadEntity
{
public:
    PyAcadPolyline() = default;
    PyAcadPolyline(std::shared_ptr<PyIAcadPolylineImpl> ptr);
    virtual ~PyAcadPolyline() override = default;

    boost::python::list     coordinates() const;
    void                    setCoordinates(const boost::python::object& coords) const;
    AcGeVector3d            normal() const;
    void                    setNormal(const AcGeVector3d& val) const;
    double                  thickness() const;
    void                    setThickness(double val) const;
    boost::python::list     explode() const;
    double                  bulge(int index) const;
    void                    setBulge(int index, double val) const;
    boost::python::tuple    width(int index) const;
    void                    setWidth(int index, double startWidth, double endWidth) const;
    double                  constantWidth() const;
    void                    setConstantWidth(double val) const;
    boost::python::list     offset(double val) const;
    double                  elevation() const;
    void                    setElevation(double val) const;
    double                  area() const;
    AcGePoint3d             coordinate(int index) const;
    void                    setCoordinate(int index, const AcGePoint3d& val) const;
    bool                    isClosed() const;
    void                    setClosed(bool val) const;
    bool                    linetypeGeneration() const;
    void                    setLinetypeGeneration(bool val) const;
    double                  length() const;

    static PyAcadPolyline cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadPolylineImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadRay
void makePyAcadRayWrapper();

class PyAcadRay : public PyAcadEntity
{
public:
    PyAcadRay() = default;
    PyAcadRay(std::shared_ptr<PyIAcadRayImpl> ptr);
    virtual ~PyAcadRay() override = default;

    AcGePoint3d             basePoint() const;
    void                    setBasePoint(const AcGePoint3d& val) const;
    AcGePoint3d             secondPoint() const;
    void                    setSecondPoint(const AcGePoint3d& val) const;
    AcGeVector3d            directionVector() const;
    void                    setDirectionVector(const AcGeVector3d& val) const;

    static PyAcadRay cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadRayImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadShape
void makePyAcadShapeWrapper();

class PyAcadShape : public PyAcadEntity
{
public:
    PyAcadShape() = default;
    PyAcadShape(std::shared_ptr<PyIAcadShapeImpl> ptr);
    virtual ~PyAcadShape() override = default;

    AcGePoint3d     insertionPoint() const;
    void            setInsertionPoint(const AcGePoint3d& val) const;
    std::string     name() const;
    void            setName(const std::string& val) const;
    double          height() const;
    void            setHeight(double val) const;
    double          rotation() const;
    void            setRotation(double val) const;
    double          scaleFactor() const;
    void            setScaleFactor(double val) const;
    double          obliqueAngle() const;
    void            setObliqueAngle(double val) const;
    AcGeVector3d    normal() const;
    void            setNormal(const AcGeVector3d& val) const;
    double          thickness() const;
    void            setThickness(double val) const;

    static PyAcadShape cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadShapeImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadSolid
void makePyAcadSolidWrapper();

class PyAcadSolid : public PyAcadEntity
{
public:
    PyAcadSolid() = default;
    PyAcadSolid(std::shared_ptr<PyIAcadSolidImpl> ptr);
    virtual ~PyAcadSolid() override = default;

    boost::python::list coordinates() const;
    void                setCoordinates(const boost::python::object& coords) const;
    AcGeVector3d        normal() const;
    void                setNormal(const AcGeVector3d& val) const;
    double              thickness() const;
    void                setThickness(double val) const;
    AcGePoint3d         coordinate(int index) const;
    void                setCoordinate(int index, const AcGePoint3d& val) const;

    static PyAcadSolid cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadSolidImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadSpline
void makePyAcadSplineWrapper();

class PyAcadSpline : public PyAcadEntity
{
public:
    PyAcadSpline() = default;
    PyAcadSpline(std::shared_ptr<PyIAcadSplineImpl> ptr);
    virtual ~PyAcadSpline() override = default;

    long                    numberOfControlPoints() const;
    boost::python::list     controlPoints() const;
    void                    setControlPoints(const boost::python::object& coords) const;
    boost::python::list     fitPoints() const;
    void                    setFitPoints(const boost::python::object& coords) const;
    long                    degree() const;
    bool                    closed() const;
    bool                    isPlanar() const;
    bool                    isRational() const;
    bool                    isPeriodic() const;
    AcGeVector3d            startTangent() const;
    void                    setStartTangent(const AcGeVector3d& val) const;
    AcGeVector3d            endTangent() const;
    void                    setEndTangent(const AcGeVector3d& val) const;
    double                  fitTolerance() const;
    void                    setFitTolerance(double val) const;
    double                  area() const;
    AcGePoint3d             controlPoint(int index) const;
    void                    setControlPoint(int index, const AcGePoint3d& val) const;
    AcGePoint3d             fitPoint(int index) const;
    void                    setFitPoint(int index, const AcGePoint3d& val) const;
    double                  weight(int index) const;
    void                    setWeight(int index, double val) const;
    void                    addFitPoint(int index, const AcGePoint3d& val) const;
    void                    deleteFitPoint(int index) const;
    void                    elevateOrder(int index) const;
    boost::python::list     offset(double val) const;
    void                    purgeFitData() const;
    void                    reverse() const;
    boost::python::list     knots() const;
    void                    setKnots(const boost::python::object& val) const;
    boost::python::list     weights() const;
    void                    setWeights(const boost::python::object& val) const;
    PyAcSplineKnotParameterizationType  knotParameterization() const;
    void                                setKnotParameterization(PyAcSplineKnotParameterizationType val) const;
    PyAcSplineFrameType     splineFrame() const;
    void                    setSplineFrame(PyAcSplineFrameType val) const;
    PyAcSplineMethodType    splineMethod() const;
    void                    setSplineMethod(PyAcSplineMethodType val) const;
    long                    degree2() const;
    void                    setDegree2(long val) const;
    bool                    closed2() const;
    void                    setClosed2(bool val) const;

    static PyAcadSpline cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadSplineImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadText
void makePyAcadTextWrapper();

class PyAcadText : public PyAcadEntity
{
public:
    PyAcadText() = default;
    PyAcadText(std::shared_ptr<PyIAcadTextImpl> ptr);
    virtual ~PyAcadText() override = default;

    std::string             textString() const;
    void                    setTextString(const std::string& val) const;
    std::string             styleName() const;
    void                    setStyleName(const std::string& val) const;
    PyAcAlignment           alignment() const;
    void                    setAlignment(PyAcAlignment val) const;
    PyAcHorizontalAlignment horizontalAlignment() const;
    void                    setHorizontalAlignment(PyAcHorizontalAlignment val) const;
    PyAcVerticalAlignment   verticalAlignment() const;
    void                    setVerticalAlignment(PyAcVerticalAlignment val) const;
    double                  height() const;
    void                    setHeight(double val) const;
    double                  rotation() const;
    void                    setRotation(double val) const;
    double                  scaleFactor() const;
    void                    setScaleFactor(double val) const;
    double                  obliqueAngle() const;
    void                    setObliqueAngle(double val) const;
    AcGePoint3d             textAlignmentPoint() const;
    void                    setTextAlignmentPoint(const AcGePoint3d& val) const;
    AcGePoint3d             insertionPoint() const;
    void                    setInsertionPoint(const AcGePoint3d& val) const;
    AcGeVector3d            normal() const;
    void                    setNormal(const AcGeVector3d& val) const;
    long                    textGenerationFlag() const;
    void                    setTextGenerationFlag(long val) const;
    double                  thickness() const;
    void                    setThickness(double val) const;
    bool                    upsideDown() const;
    void                    setUpsideDown(bool val) const;
    bool                    backward() const;
    void                    setBackward(bool val) const;
    std::string             fieldCode() const;

    static PyAcadText cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadTextImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadTolerance
void makePyAcadToleranceWrapper();

class PyAcadTolerance : public PyAcadEntity
{
public:
    PyAcadTolerance() = default;
    PyAcadTolerance(std::shared_ptr<PyIAcadToleranceImpl> ptr);
    virtual ~PyAcadTolerance() override = default;

    AcGeVector3d    directionVector() const;
    void            setDirectionVector(const AcGeVector3d& val) const;
    AcGePoint3d     insertionPoint() const;
    void            setInsertionPoint(const AcGePoint3d& val) const;
    AcGeVector3d    normal() const;
    void            setNormal(const AcGeVector3d& val) const;
    std::string     styleName() const;
    void            setStyleName(const std::string& val) const;
    PyAcColor       textColor() const;
    void            setTextColor(PyAcColor val) const;
    std::string     textString() const;
    void            setTextString(const std::string& val) const;
    std::string     textStyle() const;
    void            setTextStyle(const std::string& val) const;
    double          textHeight() const;
    void            setTextHeight(double val) const;
    double          scaleFactor() const;
    void            setScaleFactor(double val) const;
    PyAcColor       dimensionLineColor() const;
    void            setDimensionLineColor(PyAcColor val) const;

    static PyAcadTolerance cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadToleranceImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadTrace
void makePyAcadTraceWrapper();

class PyAcadTrace : public PyAcadEntity
{
public:
    PyAcadTrace() = default;
    PyAcadTrace(std::shared_ptr<PyIAcadTraceImpl> ptr);
    virtual ~PyAcadTrace() override = default;

    boost::python::list coordinates() const;
    void                setCoordinates(const boost::python::object& coords) const;
    AcGeVector3d        normal() const;
    void                setNormal(const AcGeVector3d& val) const;
    double              thickness() const;
    void                setThickness(double val) const;
    AcGePoint3d         coordinate(int index) const;
    void                setCoordinate(int index, const AcGePoint3d& val) const;

    static PyAcadTrace cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadTraceImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadXline
void makePyAcadXlineWrapper();

class PyAcadXline : public PyAcadEntity
{
public:
    PyAcadXline() = default;
    PyAcadXline(std::shared_ptr<PyIAcadXlineImpl> ptr);
    virtual ~PyAcadXline() override = default;

    AcGePoint3d         basePoint() const;
    void                setBasePoint(const AcGePoint3d& val) const;
    AcGePoint3d         secondPoint() const;
    void                setSecondPoint(const AcGePoint3d& val) const;
    AcGeVector3d        directionVector() const;
    void                setDirectionVector(const AcGeVector3d& val) const;
    boost::python::list offset(double val) const;

    static PyAcadXline cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadXlineImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadBlockReference
void makePyAcadBlockReferenceWrapper();

class PyAcadBlockReference : public PyAcadEntity
{
public:
    PyAcadBlockReference() = default;
    PyAcadBlockReference(std::shared_ptr<PyIAcadBlockReferenceImpl> ptr);
    virtual ~PyAcadBlockReference() override = default;

    AcGePoint3d         insertionPoint() const;
    void                setInsertionPoint(const AcGePoint3d& val) const;
    std::string         name() const;
    void                setName(const std::string& val) const;
    AcGeVector3d        normal() const;
    void                setNormal(const AcGeVector3d& val) const;
    double              rotation() const;
    void                setRotation(double val) const;
    double              xScaleFactor() const;
    void                setXScaleFactor(double val) const;
    double              yScaleFactor() const;
    void                setYScaleFactor(double val) const;
    double              zScaleFactor() const;
    void                setZScaleFactor(double val) const;
    boost::python::list explode() const;
    boost::python::list attributes() const;
    boost::python::list constantAttributes() const;
    boost::python::list dynamicBlockProperties() const;
    bool                hasAttributes() const;
    std::string         effectiveName() const;
    bool                isDynamicBlock() const;
    void                resetBlock() const;
    void                convertToAnonymousBlock() const;
    void                convertToStaticBlock(const std::string& newBlockName) const;
    double              xEffectiveScaleFactor() const;
    void                setXEffectiveScaleFactor(double val) const;
    double              yEffectiveScaleFactor() const;
    void                setYEffectiveScaleFactor(double val) const;
    double              zEffectiveScaleFactor() const;
    void                setZEffectiveScaleFactor(double val) const;
    std::string         insUnits() const;
    double              insUnitsFactor() const;

    static PyAcadBlockReference cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadBlockReferenceImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadHatch
void makePyAcadHatchWrapper();

class PyAcadHatch : public PyAcadEntity
{
public:
    PyAcadHatch() = default;
    PyAcadHatch(std::shared_ptr<PyIAcadHatchImpl> ptr);
    virtual ~PyAcadHatch() override = default;

    AcGeVector3d        normal() const;
    void                setNormal(const AcGeVector3d& val) const;
    long                numberOfLoops() const;
    PyAcPatternType     patternType() const;
    std::string         patternName() const;
    double              patternAngle() const;
    void                setPatternAngle(double val) const;
    double              patternScale() const;
    void                setPatternScale(double val) const;
    double              patternSpace() const;
    void                setPatternSpace(double val) const;
    PyAcISOPenWidth     isoPenWidth() const;
    void                setISOPenWidth(PyAcISOPenWidth val) const;
    bool                patternDouble() const;
    void                setPatternDouble(bool val) const;
    double              elevation() const;
    void                setElevation(double val) const;
    bool                associativeHatch() const;
    void                setAssociativeHatch(bool val) const;
    PyAcHatchStyle      hatchStyle() const;
    void                setHatchStyle(PyAcHatchStyle val) const;
    void                setPattern(int patternType, const std::string& name) const;
    void                appendOuterLoop(const boost::python::object& objectArray) const;
    void                appendInnerLoop(const boost::python::object& objectArray) const;
    void                insertLoopAt(int index, PyAcLoopType loopType, const boost::python::object& objectArray) const;
    boost::python::list loopAt(int index) const;
    void                evaluate() const;
    PyAcadAcCmColor     gradientColor1() const;
    void                setGradientColor1(const PyAcadAcCmColor& val) const;
    PyAcadAcCmColor     gradientColor2() const;
    void                setGradientColor2(const PyAcadAcCmColor& val) const;
    double              gradientAngle() const;
    void                setGradientAngle(double val) const;
    bool                gradientCentered() const;
    void                setGradientCentered(bool val) const;
    std::string         gradientName() const;
    void                setGradientName(const std::string& val) const;
    PyAcHatchObjectType hatchObjectType() const;
    void                setHatchObjectType(PyAcHatchObjectType val) const;
    double              area() const;
    AcGePoint3d         origin() const;
    void                setOrigin(const AcGePoint3d& val) const;
    PyAcadAcCmColor     backgroundColor() const;
    void                setBackgroundColor(const PyAcadAcCmColor& val) const;

    static PyAcadHatch cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadHatchImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadRasterImage
void makePyAcadRasterImageWrapper();

class PyAcadRasterImage : public PyAcadEntity
{
public:
    PyAcadRasterImage() = default;
    PyAcadRasterImage(std::shared_ptr<PyIAcadRasterImageImpl> ptr);
    virtual ~PyAcadRasterImage() override = default;

    long            brightness() const;
    void            setBrightness(long val) const;
    long            contrast() const;
    void            setContrast(long val) const;
    long            fade() const;
    void            setFade(long val) const;
    AcGePoint3d     origin() const;
    void            setOrigin(const AcGePoint3d& val) const;
    double          rotation() const;
    void            setRotation(double val) const;
    double          imageWidth() const;
    void            setImageWidth(double val) const;
    double          imageHeight() const;
    void            setImageHeight(double val) const;
    std::string     name() const;
    void            setName(const std::string& val) const;
    std::string     imageFile() const;
    void            setImageFile(const std::string& val) const;
    bool            imageVisibility() const;
    void            setImageVisibility(bool val) const;
    bool            clippingEnabled() const;
    void            setClippingEnabled(bool val) const;
    bool            transparency() const;
    void            setTransparency(bool val) const;
    void            clipBoundary(const boost::python::object& val) const;
    double          height() const;
    double          width() const;
    bool            showRotation() const;
    void            setShowRotation(bool val) const;
    double          scaleFactor() const;
    void            setScaleFactor(double val) const;

    static PyAcadRasterImage cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadRasterImageImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadLine
void makePyAcadLineWrapper();

class PyAcadLine : public PyAcadEntity
{
public:
    PyAcadLine() = default;
    PyAcadLine(std::shared_ptr<PyIAcadLineImpl> ptr);
    virtual ~PyAcadLine() override = default;

    AcGePoint3d             startPoint() const;
    void                    setStartPoint(const AcGePoint3d& val) const;
    AcGePoint3d             endPoint() const;
    void                    setEndPoint(const AcGePoint3d& val) const;
    AcGeVector3d            normal() const;
    void                    setNormal(const AcGeVector3d& val) const;
    boost::python::list     offset(double val) const;
    double                  thickness() const;
    void                    setThickness(double val) const;
    AcGeVector3d            delta() const;
    double                  length() const;
    double                  angle() const;

    static PyAcadLine cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadLineImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadMInsertBlock
void makePyAcadMInsertBlockWrapper();

class PyAcadMInsertBlock : public PyAcadBlockReference
{
public:
    PyAcadMInsertBlock() = default;
    PyAcadMInsertBlock(std::shared_ptr<PyIAcadMInsertBlockImpl> ptr);
    virtual ~PyAcadMInsertBlock() override = default;

    void        setColumns(long val) const;
    long        columns() const;
    void        setRows(long val) const;
    long        rows() const;
    void        setColumnSpacing(double val) const;
    double      columnSpacing() const;
    void        setRowSpacing(double val) const;
    double      rowSpacing() const;

    static PyAcadMInsertBlock cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadMInsertBlockImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadExternalReference
void makePyAcadExternalReferenceWrapper();

class PyAcadExternalReference : public PyAcadBlockReference
{
public:
    PyAcadExternalReference() = default;
    PyAcadExternalReference(std::shared_ptr<PyIAcadExternalReferenceImpl> ptr);
    virtual ~PyAcadExternalReference() override = default;

    std::string     path() const;
    void            setPath(const std::string& val) const;
    bool            layerPropertyOverrides() const;

    static PyAcadExternalReference cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadExternalReferenceImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadPolyfaceMesh
void makePyAcadPolyfaceMeshWrapper();

class PyAcadPolyfaceMesh : public PyAcadEntity
{
public:
    PyAcadPolyfaceMesh() = default;
    PyAcadPolyfaceMesh(std::shared_ptr<PyIAcadPolyfaceMeshImpl> ptr);
    virtual ~PyAcadPolyfaceMesh() override = default;

    boost::python::list     coordinates() const;
    void                    setCoordinates(const boost::python::object& coords) const;
    AcGePoint3d             coordinate(int index) const;
    void                    setCoordinate(int index, const AcGePoint3d& val) const;
    long                    numberOfVertices() const;
    long                    numberOfFaces() const;
    void                    setFaces(const boost::python::object& coords) const;

    static PyAcadPolyfaceMesh cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadPolyfaceMeshImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadMLine
void makePyAcadMLineWrapper();

class PyAcadMLine : public PyAcadEntity
{
public:
    PyAcadMLine() = default;
    PyAcadMLine(std::shared_ptr<PyIAcadMLineImpl> ptr);
    virtual ~PyAcadMLine() override = default;

    std::string            styleName() const;
    boost::python::list    coordinates() const;
    void                   setCoordinates(const boost::python::object& coords) const;
    PyAcMLineJustification justification() const;
    void                   setJustification(PyAcMLineJustification val) const;
    double                 mlineScale() const;
    void                   setMLineScale(double val) const;

    static PyAcadMLine cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadMLineImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadSection
void makePyAcadSectionWrapper();

class PyAcadSection : public PyAcadEntity
{
public:
    PyAcadSection() = default;
    PyAcadSection(std::shared_ptr<PyIAcadSectionImpl> ptr);
    virtual ~PyAcadSection() override = default;

    std::string                 name() const;
    void                        setName(const std::string& val) const;
    PyAcSectionState            state() const;
    void                        setState(PyAcSectionState val) const;
    AcGeVector3d                viewingDirection() const;
    void                        setViewingDirection(const AcGeVector3d& val) const;
    AcGeVector3d                verticalDirection() const;
    void                        setVerticalDirection(const AcGeVector3d& val) const;
    AcGeVector3d                normal() const;
    bool                        liveSectionEnabled() const;
    void                        setLiveSectionEnabled(bool val) const;
    int                         indicatorTransparency() const;
    void                        setIndicatorTransparency(int val) const;
    PyAcadAcCmColor             indicatorFillColor() const;
    void                        setIndicatorFillColor(const  PyAcadAcCmColor& val) const;
    double                      elevation() const;
    void                        setElevation(double val) const;
    double                      topHeight() const;
    void                        setTopHeight(double val) const;
    double                      bottomHeight() const;
    void                        setBottomHeight(double val) const;
    int                         numVertices() const;
    boost::python::list         vertices() const;
    void                        setVertices(const boost::python::object& coords) const;
    AcGePoint3d                 coordinate(int index) const;
    void                        setCoordinate(int index, const AcGePoint3d& val) const;
    void                        addVertex(int index, const AcGePoint3d& val) const;
    void                        removeVertex(int index) const;
    boost::python::tuple        hitTest(const AcGePoint3d& val) const;
    void                        createJog(const AcGePoint3d& val) const;
    PyAcadSectionSettings       settings() const;
    boost::python::tuple        generateSectionGeometry(const PyAcadEntity& val) const;

    static PyAcadSection cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadSectionImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadMLeader
void makePyAcadMLeaderWrapper();

class PyAcadMLeader : public PyAcadEntity
{
public:
    PyAcadMLeader() = default;
    PyAcadMLeader(std::shared_ptr<PyIAcadMLeaderImpl> ptr);
    virtual ~PyAcadMLeader() override = default;

    double                  scaleFactor() const;
    void                    setScaleFactor(double val) const;
    PyAcMLeaderType         leaderType() const;
    void                    setLeaderType(PyAcMLeaderType val) const;
    PyAcadAcCmColor         leaderLineColor() const;
    void                    setLeaderLineColor(const PyAcadAcCmColor& val) const;
    std::string             leaderLinetype() const;
    void                    setLeaderLinetype(const std::string& val) const;
    PyAcLineWeight          leaderLineWeight() const;
    void                    setLeaderLineWeight(PyAcLineWeight val) const;
    PyAcDimArrowheadType    arrowheadType() const;
    void                    setArrowheadType(PyAcDimArrowheadType val) const;
    double                  arrowheadSize() const;
    void                    setArrowheadSize(double val) const;
    bool                    dogLegged() const;
    void                    setDogLegged(bool val) const;
    double                  doglegLength() const;
    void                    setDoglegLength(double val) const;
    std::string             contentBlockName() const;
    void                    setContentBlockName(const std::string& val) const;
    PyAcBlockConnectionType blockConnectionType() const;
    void                    setBlockConnectionType(PyAcBlockConnectionType val) const;
    double                  blockScale() const;
    void                    setBlockScale(double val) const;
    std::string             textString() const;
    void                    setTextString(const std::string& val) const;
    std::string             textStyleName() const;
    void                    setTextStyleName(const std::string& val) const;
    PyAcAttachmentPoint     textJustify() const;
    void                    setTextJustify(PyAcAttachmentPoint val) const;
    PyAcDrawingDirection    textDirection() const;
    void                    setTextDirection(PyAcDrawingDirection val) const;
    double                  textWidth() const;
    void                    setTextWidth(double val) const;
    double                  textHeight() const;
    void                    setTextHeight(double val) const;
    double                  textRotation() const;
    void                    setTextRotation(double val) const;
    double                  textLineSpacingFactor() const;
    void                    setTextLineSpacingFactor(double val) const;
    double                  textLineSpacingDistance() const;
    void                    setTextLineSpacingDistance(double val) const;
    PyAcLineSpacingStyle    textLineSpacingStyle() const;
    void                    setTextLineSpacingStyle(PyAcLineSpacingStyle val) const;
    bool                    textBackgroundFill() const;
    void                    setTextBackgroundFill(bool val) const;
    PyAcTextAttachmentType  textLeftAttachmentType() const;
    void                    setTextLeftAttachmentType(PyAcTextAttachmentType val) const;
    PyAcTextAttachmentType  textRightAttachmentType() const;
    void                    setTextRightAttachmentType(PyAcTextAttachmentType val) const;
    double                  landingGap() const;
    void                    setLandingGap(double val) const;
    std::string             arrowheadBlock() const;
    void                    setArrowheadBlock(const std::string& val) const;
    PyAcPredefBlockType     contentBlockType() const;
    void                    setContentBlockType(PyAcPredefBlockType val) const;
    int                     leaderCount() const;
    int                     addLeader() const;
    void                    removeLeader(int val) const;
    int                     addLeaderLine(int leaderIndex, const boost::python::object& coords) const;
    int                     addLeaderLineEx(const boost::python::object& coords) const;
    void                    removeLeaderLine(int val) const;
    void                    setLeaderLineVertices(int leaderIndex, const boost::python::object& coords) const;
    boost::python::list     leaderLineVertices(int leaderIndex) const;
    PyAcMLeaderContentType  contentType() const;
    void                    setContentType(PyAcMLeaderContentType val) const;
    int                     leaderIndex(int leaderLineIndex) const;
    boost::python::list     leaderLineIndexes(int leaderLineIndex) const;
    int                     vertexCount(int leaderLineIndex) const;
    bool                    textFrameDisplay() const;
    void                    setTextFrameDisplay(bool val) const;
    std::string             styleName() const;
    void                    setStyleName(const std::string& val) const;
    AcGeVector3d            doglegDirection(int leaderIndex) const;
    void                    setDoglegDirection(int leaderIndex, const AcGeVector3d& val) const;
    std::string             blockAttributeValue(const PyDbObjectId& id) const;
    void                    setBlockAttributeValue(const PyDbObjectId& id, const std::string& val) const;
    PyAcTextAttachmentDirection     textAttachmentDirection() const;
    void                            setTextAttachmentDirection(PyAcTextAttachmentDirection val) const;
    PyAcVerticalTextAttachmentType  textTopAttachmentType() const;
    void                            setTextTopAttachmentType(PyAcVerticalTextAttachmentType val) const;
    PyAcVerticalTextAttachmentType  textBottomAttachmentType() const;
    void                            setTextBottomAttachmentType(PyAcVerticalTextAttachmentType val) const;

    static PyAcadMLeader cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadMLeaderImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

#pragma pack (pop)