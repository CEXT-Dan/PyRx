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
    static PyAcadAttribute cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadAttributeImpl* impObj(const std::source_location& src = std::source_location::current()) const;
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
    static PyAcadCircle cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadCircleImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadDimension
void makePyAcadDimensionWrapper();

class PyAcadDimension : public PyAcadEntity
{
public:
    PyAcadDimension() = default;
    PyAcadDimension(std::shared_ptr<PyIAcadDimensionImpl> ptr);
    virtual ~PyAcadDimension() override = default;
    static PyAcadDimension cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadDimensionImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadDimAligned
void makePyAcadDimAlignedWrapper();

class PyAcadDimAligned : public PyAcadDimension
{
public:
    PyAcadDimAligned() = default;
    PyAcadDimAligned(std::shared_ptr<PyIAcadDimAlignedImpl> ptr);
    virtual ~PyAcadDimAligned() override = default;
    static PyAcadDimAligned cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadDimAlignedImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadDimAngular
void makePyAcadDimAngularWrapper();

class PyAcadDimAngular : public PyAcadDimension
{
public:
    PyAcadDimAngular() = default;
    PyAcadDimAngular(std::shared_ptr<PyIAcadDimAngularImpl> ptr);
    virtual ~PyAcadDimAngular() override = default;
    static PyAcadDimAngular cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadDimAngularImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadDimDiametric
void makePyAcadDimDiametricWrapper();

class PyAcadDimDiametric : public PyAcadDimension
{
public:
    PyAcadDimDiametric() = default;
    PyAcadDimDiametric(std::shared_ptr<PyIAcadDimDiametricImpl> ptr);
    virtual ~PyAcadDimDiametric() override = default;
    static PyAcadDimDiametric cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadDimDiametricImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadDimRotated
void makePyAcadDimRotatedWrapper();

class PyAcadDimRotated : public PyAcadDimension
{
public:
    PyAcadDimRotated() = default;
    PyAcadDimRotated(std::shared_ptr<PyIAcadDimRotatedImpl> ptr);
    virtual ~PyAcadDimRotated() override = default;
    static PyAcadDimRotated cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadDimRotatedImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadDimOrdinate
void makePyAcadDimOrdinateWrapper();

class PyAcadDimOrdinate : public PyAcadDimension
{
public:
    PyAcadDimOrdinate() = default;
    PyAcadDimOrdinate(std::shared_ptr<PyIAcadDimOrdinateImpl> ptr);
    virtual ~PyAcadDimOrdinate() override = default;
    static PyAcadDimOrdinate cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadDimOrdinateImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadDimRadial
void makePyAcadDimRadialWrapper();

class PyAcadDimRadial : public PyAcadDimension
{
public:
    PyAcadDimRadial() = default;
    PyAcadDimRadial(std::shared_ptr<PyIAcadDimRadialImpl> ptr);
    virtual ~PyAcadDimRadial() override = default;
    static PyAcadDimRadial cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadDimRadialImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadDim3PointAngular
void makePyAcadDim3PointAngularWrapper();

class PyAcadDim3PointAngular : public PyAcadDimension
{
public:
    PyAcadDim3PointAngular() = default;
    PyAcadDim3PointAngular(std::shared_ptr<PyIAcadDim3PointAngularImpl> ptr);
    virtual ~PyAcadDim3PointAngular() override = default;
    static PyAcadDim3PointAngular cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadDim3PointAngularImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadDimArcLength
void makePyAcadDimArcLengthWrapper();

class PyAcadDimArcLength : public PyAcadDimension
{
public:
    PyAcadDimArcLength() = default;
    PyAcadDimArcLength(std::shared_ptr<PyIAcadDimArcLengthImpl> ptr);
    virtual ~PyAcadDimArcLength() override = default;
    static PyAcadDimArcLength cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadDimArcLengthImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadDimRadialLarge
void makePyAcadDimRadialLargeWrapper();

class PyAcadDimRadialLarge : public PyAcadDimension
{
public:
    PyAcadDimRadialLarge() = default;
    PyAcadDimRadialLarge(std::shared_ptr<PyIAcadDimRadialLargeImpl> ptr);
    virtual ~PyAcadDimRadialLarge() override = default;
    static PyAcadDimRadialLarge cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadDimRadialLargeImpl* impObj(const std::source_location& src = std::source_location::current()) const;
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
//PyAcadTable
void makePyAcadTableWrapper();

class PyAcadTable : public PyAcadEntity
{
public:
    PyAcadTable() = default;
    PyAcadTable(std::shared_ptr<PyIAcadTableImpl> ptr);
    virtual ~PyAcadTable() override = default;
    static PyAcadTable cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadTableImpl* impObj(const std::source_location& src = std::source_location::current()) const;
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