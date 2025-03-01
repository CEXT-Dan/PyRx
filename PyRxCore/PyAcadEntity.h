#pragma once

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
    void                    setLayer(const std::string& val);
    std::string             linetype() const;
    void                    setLinetype(const  std::string& val);
    double                  linetypeScale() const;
    void                    setLinetypeScale(double val);
    bool                    isVisible() const;
    void                    setVisible(bool bVisible);
    boost::python::list     arrayPolar(int numberOfObjects, double angleToFill, const AcGePoint3d& centerPoint);
    boost::python::list     arrayRectangular(int nRows, int nColumns, int nLevels, double rowDist, double colDist, double levelDist);
    void                    highlight(bool highlight);
    PyAcadEntity            copy();
    void                    move(const AcGePoint3d& fromPoint, const AcGePoint3d& toPoint);
    void                    rotate(const AcGePoint3d& basePoint, double rotationAngle);
    void                    rotate3D(const AcGePoint3d& point1, const AcGePoint3d& point2, double rotationAngle);
    PyAcadEntity            mirror(const AcGePoint3d& point1, const AcGePoint3d& point2);
    PyAcadEntity            mirror3D(const AcGePoint3d& point1, const AcGePoint3d& point2, const AcGePoint3d& point3);
    void                    scaleEntity(const AcGePoint3d& basePoint, double scaleFactor);
    void                    transformBy(const AcGeMatrix3d& xform);
    void                    update();
    boost::python::tuple    boundingBox();
    boost::python::list     intersectWith(const PyAcadEntity& intersectObject, PyAcExtendOption option);
    std::string             plotStyleName() const;
    void                    setPlotStyleName(const std::string& val);
    PyAcLineWeight          lineweight() const;
    void                    setLineweight(PyAcLineWeight lw);
    std::string             entityTransparency() const;
    void                    setEntityTransparency(const std::string& val);
    PyAcadHyperlinks        hyperlinks() const;
    std::string             material() const;
    void                    setMaterial(const std::string& val);
    std::string             entityName() const;
    long                    entityType() const;
    PyAcColor               color() const;
    void                    setColor(PyAcColor color);

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
    void                setCenter(const AcGePoint3d& val);
    AcGeVector3d        direction() const;
    void                setDirection(const AcGeVector3d& val);
    bool                gridOn() const;
    void                setGridOn(bool bVisible);
    double              height() const;
    void                setHeight(double val);
    double              width() const;
    void                setWidth(double val);
    bool                viewportOn() const;
    void                setViewportOn(bool bVisible);
    bool                clipped() const;
    bool                displayLocked() const;
    void                setDisplayLocked(bool bVisible);
    PyAcViewportScale   standardScale() const;
    void                setStandardScale(PyAcViewportScale val);
    double              customScale() const;
    void                setCustomScale(double val);
    std::string         styleSheet() const;
    void                setStyleSheet(const std::string& val);
    bool                ucsPerViewport() const;
    void                setUCSPerViewport(bool UCSSaved);
    AcGePoint2d         snapBasePoint() const;
    void                setSnapBasePoint(const AcGePoint2d& val);
    bool                snapOn() const;
    void                setSnapOn(bool UCSSaved);
    double              snapRotationAngle() const;
    void                setSnapRotationAngle(double val);
    bool                ucsIconOn() const;
    void                setUCSIconOn(bool bIconOn);
    bool                ucsIconAtOrigin() const;
    void                setUCSIconAtOrigin(bool bIconAtOrigin);
    boost::python::tuple    gridSpacing();
    void                    setGridSpacing(double XSpacing, double YSpacing);
    boost::python::tuple    snapSpacing();
    void                    setSnapSpacing(double XSpacing, double YSpacing);
    void                display(bool bStatus);
    double              twistAngle() const;
    void                setTwistAngle(double val);
    double              lensLength() const;
    void                setLensLength(double val);
    bool                removeHiddenLines() const;
    void                setRemoveHiddenLines(bool bRemoval);
    AcGePoint3d         target() const;
    void                setTarget(const AcGePoint3d& val);
    long                arcSmoothness() const;
    void                setArcSmoothness(long val);
    int                 visualStyle() const;
    void                setVisualStyle(int val);
    int                 shadePlot() const;
    void                setShadePlot(int val);
    PyAcadView          modelView() const;
    void                setModelView(const PyAcadView& val) const;
    PyAcadView          sheetView() const;
    void                setSheetView(const PyAcadView& val) const;
    PyDbObjectId        labelBlockId() const;
    void                setLabelBlockId(const PyDbObjectId& id);
    bool                hasSheetView() const;
    void                syncModelView();
    int                 standardScale2() const;
    void                setStandardScale2(int val);
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
    void                setCoordinates(const AcGePoint3d& p1, const AcGePoint3d& p2, const AcGePoint3d& p3, const AcGePoint3d& p4);
    bool                invisibleEdge(int index) const;
    void                setInvisibleEdge(int index, bool flag) const;
    AcGePoint3d         coordinate(int index) const;
    void                setCoordinate(int index, const AcGePoint3d& val);
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
    void                    setCoordinates(const boost::python::object& coords);
    bool                    mClose() const;
    void                    setMClose(bool val);
    bool                    nClose() const;
    void                    setNClose(bool val);
    long                    mDensity() const;
    void                    setMDensity(long val);
    long                    nDensity() const;
    void                    setNDensity(long val);
    long                    mVertexCount() const;
    long                    nVertexCount() const;
    PyAcPolymeshType        getType() const;
    void                    setType(PyAcPolymeshType val);
    void                    appendVertex(const AcGePoint3d& val);
    boost::python::list     explode() const;
    AcGePoint3d             coordinate(int index) const;
    void                    setCoordinate(int index, const AcGePoint3d& val);

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
    void                    setCoordinates(const boost::python::object& coords);
    void                    appendVertex(const AcGePoint3d& val);
    boost::python::list     explode() const;
    AcGePoint3d             coordinate(int index) const;
    void                    setCoordinate(int index, const AcGePoint3d& val);
    PyAc3DPolylineType      getType() const;
    void                    setType(PyAc3DPolylineType val);
    bool                    isClosed() const;
    void                    setClosed(bool val);
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
    void                    setCenter(const AcGePoint3d& val);
    AcGePoint3d             endPoint() const;
    double                  radius() const;
    void                    setRadius(double val);
    double                  startAngle() const;
    void                    setStartAngle(double val);
    double                  endAngle() const;
    void                    setEndAngle(double val);
    double                  totalAngle() const;
    double                  arcLength() const;
    double                  thickness() const;
    void                    setThickness(double val);
    boost::python::list     offset(double val) const;
    double                  area() const;
    AcGeVector3d            normal() const;
    void                    setNormal(const AcGeVector3d& val);

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
    void                    setFieldLength(long val);
    std::string             tagString() const;
    void                    setTagString(const std::string& val);
    std::string             promptString() const;
    void                    setPromptString(const std::string& val);
    std::string             textString() const;
    void                    setTextString(const std::string& val);
    std::string             styleName() const;
    void                    setStyleName(const std::string& val);
    PyAcAlignment           alignment() const;
    void                    setAlignment(PyAcAlignment val);
    PyAcHorizontalAlignment horizontalAlignment() const;
    void                    setHorizontalAlignment(PyAcHorizontalAlignment val);
    PyAcVerticalAlignment   verticalAlignment() const;
    void                    setVerticalAlignment(PyAcVerticalAlignment val);
    double                  height() const;
    void                    setHeight(double val);
    double                  rotation() const;
    void                    setRotation(double val);
    double                  scaleFactor() const;
    void                    setScaleFactor(double val);
    double                  obliqueAngle() const;
    void                    setObliqueAngle(double val);
    AcGePoint3d             textAlignmentPoint() const;
    void                    setTextAlignmentPoint(const AcGePoint3d& val);
    AcGePoint3d             insertionPoint() const;
    void                    setInsertionPoint(const AcGePoint3d& val);
    AcGeVector3d            normal() const;
    void                    setNormal(const AcGeVector3d& val);
    long                    textGenerationFlag() const;
    void                    setTextGenerationFlag(long val);
    double                  thickness() const;
    void                    setThickness(double val);
    long                    mode() const;
    void                    setMode(long val);
    bool                    upsideDown() const;
    void                    setUpsideDown(bool val);
    bool                    backward() const;
    void                    setBackward(bool val);
    bool                    invisible() const;
    void                    setInvisible(bool val);
    bool                    constant() const;
    void                    setConstant(bool val);
    bool                    verify() const;
    void                    setVerify(bool val);
    bool                    preset() const;
    void                    setPreset(bool val);
    bool                    lockPosition() const;
    void                    setLockPosition(bool val);
    bool                    isMTextAttribute() const;
    void                    setIsMTextAttribute(bool val);
    std::string             mtextAttributeContent() const;
    void                    setMTextAttributeContent(const std::string& val);
    void                    updateMTextAttribute();
    double                  mtextBoundaryWidth() const;
    void                    setMTextBoundaryWidth(double val);
    PyAcDrawingDirection    mtextDrawingDirection() const;
    void                    setMTextDrawingDirection(PyAcDrawingDirection val);

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
    void                    setHeight(double val);
    PyAcAlignment           alignment() const;
    void                    setAlignment(PyAcAlignment val);
    PyAcHorizontalAlignment horizontalAlignment() const;
    void                    setHorizontalAlignment(PyAcHorizontalAlignment val);
    PyAcVerticalAlignment   verticalAlignment() const;
    void                    setVerticalAlignment(PyAcVerticalAlignment val);
    AcGePoint3d             insertionPoint() const;
    void                    setInsertionPoint(const AcGePoint3d& val);
    AcGeVector3d            normal() const;
    void                    setNormal(const AcGeVector3d& val);
    double                  obliqueAngle() const;
    void                    setObliqueAngle(double val);
    double                  rotation() const;
    void                    setRotation(double val);
    double                  scaleFactor() const;
    void                    setScaleFactor(double val);
    std::string             styleName() const;
    void                    setStyleName(const std::string& val);
    std::string             tagString() const;
    void                    setTagString(const std::string& val);
    AcGePoint3d             textAlignmentPoint() const;
    void                    setTextAlignmentPoint(const AcGePoint3d& val);
    long                    textGenerationFlag() const;
    void                    setTextGenerationFlag(long val);
    std::string             textString() const;
    void                    setTextString(const std::string& val);
    double                  thickness() const;
    void                    setThickness(double val);
    long                    fieldLength() const;
    void                    setFieldLength(long val);
    bool                    upsideDown() const;
    void                    setUpsideDown(bool val);
    bool                    backward() const;
    void                    setBackward(bool val);
    bool                    invisible() const;
    void                    setInvisible(bool val);
    bool                    constant() const;
    bool                    lockPosition() const;
    bool                    isMTextAttribute() const;
    void                    setIsMTextAttribute(bool val);
    std::string             mtextAttributeContent() const;
    void                    setMTextAttributeContent(const std::string& val);
    void                    updateMTextAttribute();
    double                  mtextBoundaryWidth() const;
    void                    setMTextBoundaryWidth(double val);
    PyAcDrawingDirection    mtextDrawingDirection() const;
    void                    setMTextDrawingDirection(PyAcDrawingDirection val);

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
    boost::python::tuple checkInterference(const PyAcad3DSolid& solid, bool createInterferenceSolid);
    PyAcad3DSolid       sliceSolid(const AcGePoint3d& p1, const AcGePoint3d& p2, const AcGePoint3d& p3, bool negative);
    PyAcadRegion        sectionSolid(const AcGePoint3d& p1, const AcGePoint3d& p2, const AcGePoint3d& p3);
    std::string         solidType() const;
    AcGePoint3d         position() const;
    void                setPosition(const AcGePoint3d& val);
    bool                history() const;
    void                setHistory(bool val);
    bool                showHistory() const;
    void                setShowHistory(bool val);

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
    void                    setCenter(const AcGePoint3d& val);
    double                  radius() const;
    void                    setRadius(double val);
    double                  diameter() const;
    void                    setDiameter(double val);
    double                  circumference() const;
    void                    setCircumference(double val);
    double                  area() const;
    void                    setArea(double val);
    AcGeVector3d            normal() const;
    void                    setNormal(const AcGeVector3d& val);
    double                  thickness() const;
    void                    setThickness(double val);
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
    void                    setCenter(const AcGePoint3d& val);
    double                  majorRadius() const;
    void                    setMajorRadius(double val);
    double                  minorRadius() const;
    void                    setMinorRadius(double val);
    double                  radiusRatio() const;
    void                    setRadiusRatio(double val);
    double                  startAngle() const;
    void                    setStartAngle(double val);
    double                  endAngle() const;
    void                    setEndAngle(double val);
    double                  startParameter() const;
    void                    setStartParameter(double val);
    double                  endParameter() const;
    void                    setEndParameter(double val);
    AcGeVector3d            majorAxis() const;
    void                    setMajorAxis(AcGeVector3d val);
    AcGeVector3d            minorAxis() const;
    AcGeVector3d            normal() const;
    void                    setNormal(AcGeVector3d val);
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
    void                    setCoordinates(const boost::python::object& coords);
    AcGeVector3d            normal() const;
    std::string             styleName() const;
    void                    setStyleName(const std::string& val);
    PyAcLeaderType          leaderType() const;
    void                    setLeaderType(PyAcLeaderType val) const;
    void                    evaluate();
    AcGePoint3d             coordinate(int index) const;
    void                    setCoordinate(int index, const AcGePoint3d& val);
    PyAcadEntity            annotation() const;
    void                    setAnnotation(const PyAcadEntity& val);
    double                  arrowheadSize() const;
    void                    setArrowheadSize(double val);
    PyAcDimArrowheadType    arrowheadType() const;
    void                    setArrowheadType(PyAcDimArrowheadType val) const;
    PyAcColor               dimensionLineColor() const;
    void                    setDimensionLineColor(PyAcColor val) const;
    PyAcLineWeight          dimensionLineWeight() const;
    void                    setDimensionLineWeight(PyAcLineWeight val);
    double                  scaleFactor() const;
    void                    setScaleFactor(double val);
    PyAcDimVerticalJustification    verticalTextPosition() const;
    void                            setVerticalTextPosition(PyAcDimVerticalJustification val) const;
    double                  textGap() const;
    void                    setTextGap(double val);
    std::string             arrowheadBlock() const;
    void                    setArrowheadBlock(const std::string& val);

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
    void                    setTextString(const std::string& val);
    std::string             styleName() const;
    void                    setStyleName(const std::string& val);
    PyAcAttachmentPoint     attachmentPoint() const;
    void                    setAttachmentPoint(PyAcAttachmentPoint val);
    PyAcDrawingDirection    drawingDirection() const;
    void                    setDrawingDirection(PyAcDrawingDirection val);
    double                  width() const;
    void                    setWidth(double val);
    double                  height() const;
    void                    setHeight(double val);
    double                  rotation() const;
    void                    setRotation(double val);
    AcGePoint3d             insertionPoint() const;
    void                    setInsertionPoint(const AcGePoint3d& val);
    AcGeVector3d            normal() const;
    void                    setNormal(const AcGeVector3d& val);
    double                  lineSpacingFactor() const;
    void                    setLineSpacingFactor(double val);
    PyAcLineSpacingStyle    lineSpacingStyle() const;
    void                    setLineSpacingStyle(PyAcLineSpacingStyle val);
    double                  lineSpacingDistance() const;
    void                    setLineSpacingDistance(double val);
    bool                    backgroundFill() const;
    void                    setBackgroundFill(bool val);
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
    void                    setCoordinates(const AcGePoint3d& val);
    AcGeVector3d            normal() const;
    void                    setNormal(const AcGeVector3d& val);
    double                  thickness() const;
    void                    setThickness(double val);
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
    void                    setCoordinates(const boost::python::object& coords);
    AcGeVector3d            normal() const;
    void                    setNormal(const AcGeVector3d& val);
    double                  thickness() const;
    void                    setThickness(double val);
    void                    addVertex(int index, const AcGePoint2d& val);
    boost::python::list     explode() const;
    double                  bulge(int index) const;
    void                    setBulge(int index, double val);
    boost::python::tuple    width(int index) const;
    void                    setWidth(int index, double startWidth, double endWidth);
    double                  constantWidth() const;
    void                    setConstantWidth(double val);
    boost::python::list     offset(double val) const;
    double                  elevation() const;
    void                    setElevation(double val);
    double                  area() const;
    AcGePoint2d             coordinate(int index) const;
    void                    setCoordinate(int index, const AcGePoint2d& val);
    bool                    isClosed() const;
    void                    setClosed(bool val);
    bool                    linetypeGeneration() const;
    void                    setLinetypeGeneration(bool val);
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
    void                    setCoordinates(const boost::python::object& coords);
    AcGeVector3d            normal() const;
    void                    setNormal(const AcGeVector3d& val);
    double                  thickness() const;
    void                    setThickness(double val);
    boost::python::list     explode() const;
    double                  bulge(int index) const;
    void                    setBulge(int index, double val);
    boost::python::tuple    width(int index) const;
    void                    setWidth(int index, double startWidth, double endWidth);
    double                  constantWidth() const;
    void                    setConstantWidth(double val);
    boost::python::list     offset(double val) const;
    double                  elevation() const;
    void                    setElevation(double val);
    double                  area() const;
    AcGePoint3d             coordinate(int index) const;
    void                    setCoordinate(int index, const AcGePoint3d& val);
    bool                    isClosed() const;
    void                    setClosed(bool val);
    bool                    linetypeGeneration() const;
    void                    setLinetypeGeneration(bool val);
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
    void                    setBasePoint(const AcGePoint3d& val);
    AcGePoint3d             secondPoint() const;
    void                    setSecondPoint(const AcGePoint3d& val);
    AcGeVector3d            directionVector() const;
    void                    setDirectionVector(const AcGeVector3d& val);

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

    AcGePoint3d             insertionPoint() const;
    void                    setInsertionPoint(const AcGePoint3d& val);
    std::string             name() const;
    void                    setName(const std::string& val);
    double                  height() const;
    void                    setHeight(double val);
    double                  rotation() const;
    void                    setRotation(double val);
    double                  scaleFactor() const;
    void                    setScaleFactor(double val);
    double                  obliqueAngle() const;
    void                    setObliqueAngle(double val);
    AcGeVector3d            normal() const;
    void                    setNormal(const AcGeVector3d& val);
    double                  thickness() const;
    void                    setThickness(double val);

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

    boost::python::list     coordinates() const;
    void                    setCoordinates(const boost::python::object& coords);
    AcGeVector3d            normal() const;
    void                    setNormal(const AcGeVector3d& val);
    double                  thickness() const;
    void                    setThickness(double val);
    AcGePoint3d             coordinate(int index) const;
    void                    setCoordinate(int index, const AcGePoint3d& val);

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
    void                    setControlPoints(const boost::python::object& coords);
    boost::python::list     fitPoints() const;
    void                    setFitPoints(const boost::python::object& coords);
    long                    degree() const;
    bool                    closed() const;
    bool                    isPlanar() const;
    bool                    isRational() const;
    bool                    isPeriodic() const;
    AcGeVector3d            startTangent() const;
    void                    setStartTangent(const AcGeVector3d& val);
    AcGeVector3d            endTangent() const;
    void                    setEndTangent(const AcGeVector3d& val);
    double                  fitTolerance() const;
    void                    setFitTolerance(double val);
    double                  area() const;
    AcGePoint3d             controlPoint(int index) const;
    void                    setControlPoint(int index, const AcGePoint3d& val);
    AcGePoint3d             fitPoint(int index) const;
    void                    setFitPoint(int index, const AcGePoint3d& val);
    double                  weight(int index) const;
    void                    setWeight(int index, double val);
    void                    addFitPoint(int index, const AcGePoint3d& val);
    void                    deleteFitPoint(int index);
    void                    elevateOrder(int index);
    boost::python::list     offset(double val) const;
    void                    purgeFitData();
    void                    reverse();
    boost::python::list     knots() const;
    void                    setKnots(const boost::python::object& val);
    boost::python::list     weights() const;
    void                    setWeights(const boost::python::object& val);
    PyAcSplineKnotParameterizationType  knotParameterization() const;
    void                                setKnotParameterization(PyAcSplineKnotParameterizationType val);
    PyAcSplineFrameType     splineFrame() const;
    void                    setSplineFrame(PyAcSplineFrameType val);
    PyAcSplineMethodType    splineMethod() const;
    void                    setSplineMethod(PyAcSplineMethodType val);
    long                    degree2() const;
    void                    setDegree2(long val);
    bool                    closed2() const;
    void                    setClosed2(bool val);

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
    void                setInsertionPoint(const AcGePoint3d& val);
    std::string         name() const;
    void                setName(const std::string& val);
    AcGeVector3d        normal() const;
    void                setNormal(const AcGeVector3d& val);
    double              rotation() const;
    void                setRotation(double val);
    double              xScaleFactor() const;
    void                setXScaleFactor(double val);
    double              yScaleFactor() const;
    void                setYScaleFactor(double val);
    double              zScaleFactor() const;
    void                setZScaleFactor(double val);
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
    void                setXEffectiveScaleFactor(double val);
    double              yEffectiveScaleFactor() const;
    void                setYEffectiveScaleFactor(double val);
    double              zEffectiveScaleFactor() const;
    void                setZEffectiveScaleFactor(double val);
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

    void        setColumns(long val);
    long        columns() const;
    void        setRows(long val);
    long        rows() const;
    void        setColumnSpacing(double val);
    double      columnSpacing() const;
    void        setRowSpacing(double val);
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

    std::string             path() const;
    void                    setPath(const std::string& val);
    bool                    layerPropertyOverrides() const;

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
    static PyAcadMLeader cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadMLeaderImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

#pragma pack (pop)