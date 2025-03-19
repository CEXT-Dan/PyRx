#pragma once
#include "PyAcadDbObjectImpl.h"

class PyIAcadAcCmColorImpl;

//------------------------------------------------------------------------------------
//PyIAcadSubEntityImpl
#ifndef _GRXTARGET
class PyIAcadSubEntityImpl
{
public:
    explicit PyIAcadSubEntityImpl(IAcadSubEntity* ptr);
    virtual ~PyIAcadSubEntityImpl() = default;
    IAcadSubEntity* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadSubEntityPtr m_pimpl;
};
#endif

//------------------------------------------------------------------------------------
//PyIAcadMLeaderLeader
#ifndef _GRXTARGET
class PyIAcadMLeaderLeaderImpl : public PyIAcadSubEntityImpl
{
public:
    explicit PyIAcadMLeaderLeaderImpl(IAcadMLeaderLeader* ptr);
    virtual ~PyIAcadMLeaderLeaderImpl() = default;
    IAcadMLeaderLeader* impObj(const std::source_location& src = std::source_location::current()) const;
};
#endif

//------------------------------------------------------------------------------------
//PyIAcadSubEntSolidFaceImpl
#ifndef _GRXTARGET
class PyIAcadSubEntSolidFaceImpl : public PyIAcadSubEntityImpl
{
public:
    explicit PyIAcadSubEntSolidFaceImpl(IAcadSubEntSolidFace* ptr);
    virtual ~PyIAcadSubEntSolidFaceImpl() = default;
    IAcadSubEntSolidFace* impObj(const std::source_location& src = std::source_location::current()) const;
};
#endif

//------------------------------------------------------------------------------------
//PyIAcadSubDMeshFaceImpl
#ifndef _GRXTARGET
#ifndef _BRXTARGET
class PyIAcadSubDMeshFaceImpl : public PyIAcadSubEntityImpl
{
public:
    explicit PyIAcadSubDMeshFaceImpl(IAcadSubDMeshFace* ptr);
    virtual ~PyIAcadSubDMeshFaceImpl() = default;
    IAcadSubDMeshFace* impObj(const std::source_location& src = std::source_location::current()) const;
};
#endif
#endif

//------------------------------------------------------------------------------------
//PyIAcadSubDMeshEdgeImpl
#ifndef _GRXTARGET
#ifndef _BRXTARGET
class PyIAcadSubDMeshEdgeImpl : public PyIAcadSubEntityImpl
{
public:
    explicit PyIAcadSubDMeshEdgeImpl(IAcadSubDMeshEdge* ptr);
    virtual ~PyIAcadSubDMeshEdgeImpl() = default;
    IAcadSubDMeshEdge* impObj(const std::source_location& src = std::source_location::current()) const;
};
#endif
#endif

//------------------------------------------------------------------------------------
//PyIAcadSubDMeshVertexImpl
#ifndef _GRXTARGET
#ifndef _BRXTARGET
class PyIAcadSubDMeshVertexImpl : public PyIAcadSubEntityImpl
{
public:
    explicit PyIAcadSubDMeshVertexImpl(IAcadSubDMeshVertex* ptr);
    virtual ~PyIAcadSubDMeshVertexImpl() = default;
    IAcadSubDMeshVertex* impObj(const std::source_location& src = std::source_location::current()) const;
};
#endif
#endif

//------------------------------------------------------------------------------------
//PyIAcadEntityImpl1
class PyIAcadEntityImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadEntityImpl(IAcadEntity* ptr);
    virtual ~PyIAcadEntityImpl() override = default;

    PyIAcadAcCmColorPtr     GetTrueColor() const;
    void                    SetTrueColor(const PyIAcadAcCmColorImpl& val) const;
    CString                 GetLayer() const;
    void                    SetLayer(const CString& val) const;
    CString                 GetLinetype() const;
    void                    SetLinetype(const CString& val) const;
    double                  GetLinetypeScale() const;
    void                    SetLinetypeScale(double val) const;
    bool                    GetVisible() const;
    void                    SetVisible(bool bVisible) const;
    PyIAcadEntityPtrArray   ArrayPolar(int numberOfObjects, double angleToFill, const AcGePoint3d& centerPoint) const;
    PyIAcadEntityPtrArray   ArrayRectangular(int nRows, int nColumns, int nLevels, double rowDist, double colDist, double levelDist) const;
    void                    Highlight(bool highlight) const;
    PyIAcadEntityPtr        Copy() const;
    void                    Move(const AcGePoint3d& fromPoint, const AcGePoint3d& toPoint) const;
    void                    Rotate(const AcGePoint3d& basePoint, double rotationAngle) const;
    void                    Rotate3D(const AcGePoint3d& point1, const AcGePoint3d& point2, double rotationAngle) const;
    PyIAcadEntityPtr        Mirror(const AcGePoint3d& point1, const AcGePoint3d& point2) const;
    PyIAcadEntityPtr        Mirror3D(const AcGePoint3d& point1, const AcGePoint3d& point2, const AcGePoint3d& point3) const;
    void                    ScaleEntity(const AcGePoint3d& basePoint, double scaleFactor) const;
    void                    TransformBy(const AcGeMatrix3d& xform) const;
    void                    Update() const;
    void                    GetBoundingBox(AcGePoint3d& minPoint, AcGePoint3d& maxPoint) const;
    std::vector<AcGePoint3d> IntersectWith(const PyIAcadEntityImpl& intersectObject, PyAcExtendOption option) const;
    CString                 GetPlotStyleName() const;
    void                    SetPlotStyleName(const CString& val) const;
    PyAcLineWeight          GetLineweight() const;
    void                    SetLineweight(PyAcLineWeight lw) const;
    CString                 GetEntityTransparency() const;
    void                    SetEntityTransparency(const CString& val) const;
    PyIAcadHyperlinksPtr    GetHyperlinks() const;
    CString                 GetMaterial() const;
    void                    SetMaterial(const CString& val) const;
    CString                 GetEntityName() const;
    long                    GetEntityType() const;
    PyAcColor               GetColor() const;
    void                    SetColor(PyAcColor color) const;

    IAcadEntity* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcadPViewportImpl
class PyIAcadPViewportImpl : public PyIAcadEntityImpl
{
public:
    explicit PyIAcadPViewportImpl(IAcadPViewport* ptr);
    virtual ~PyIAcadPViewportImpl() override = default;
    AcGePoint3d         GetCenter() const;
    void                SetCenter(const AcGePoint3d& val) const;
    AcGeVector3d        GetDirection() const;
    void                SetDirection(const AcGeVector3d& val) const;
    bool                GetGridOn() const;
    void                SetGridOn(bool bVisible) const;
    double              GetHeight() const;
    void                SetHeight(double val) const;
    double              GetWidth() const;
    void                SetWidth(double val) const;
    bool                GetViewportOn() const;
    void                SetViewportOn(bool bVisible) const;
    bool                GetClipped() const;
    bool                GetDisplayLocked() const;
    void                SetDisplayLocked(bool bVisible) const;
    PyAcViewportScale   GetStandardScale() const;
    void                SetStandardScale(PyAcViewportScale val) const;
    double              GetCustomScale() const;
    void                SetCustomScale(double val) const;
    CString             GetStyleSheet() const;
    void                SetStyleSheet(const CString& val) const;
    bool                GetUCSPerViewport() const;
    void                SetUCSPerViewport(bool UCSSaved) const;
    AcGePoint2d         GetSnapBasePoint() const;
    void                SetSnapBasePoint(const AcGePoint2d& val) const;
    bool                GetSnapOn() const;
    void                SetSnapOn(bool UCSSaved) const;
    double              GetSnapRotationAngle() const;
    void                SetSnapRotationAngle(double val) const;
    bool                GetUCSIconOn() const;
    void                SetUCSIconOn(bool bIconOn) const;
    bool                GetUCSIconAtOrigin() const;
    void                SetUCSIconAtOrigin(bool bIconAtOrigin) const;
    void                GetGridSpacing(double& XSpacing, double& YSpacing) const;
    void                SetGridSpacing(double XSpacing, double YSpacing) const;
    void                GetSnapSpacing(double& XSpacing, double& YSpacing) const;
    void                SetSnapSpacing(double XSpacing, double YSpacing) const;
    void                Display(bool bStatus) const;
    double              GetTwistAngle() const;
    void                SetTwistAngle(double val) const;
    double              GetLensLength() const;
    void                SetLensLength(double val) const;
    bool                GetRemoveHiddenLines() const;
    void                SetRemoveHiddenLines(bool bRemoval) const;
    AcGePoint3d         GetTarget() const;
    void                SetTarget(const AcGePoint3d& val) const;
    long                GetArcSmoothness() const;
    void                SetArcSmoothness(long val) const;
    int                 GetVisualStyle() const;
    void                SetVisualStyle(int val) const;
    int                 GetShadePlot() const;
    void                SetShadePlot(int val) const;
    PyIAcadViewPtr      GetModelView() const;
    void                SetModelView(const  PyIAcadViewImpl& val) const;
    PyIAcadViewPtr      GetSheetView() const;
    void                SetSheetView(const  PyIAcadViewImpl& val) const;
    AcDbObjectId        GetLabelBlockId() const;
    void                SetLabelBlockId(const AcDbObjectId& id) const;
    bool                GetHasSheetView() const;
    void                SyncModelView() const;
    int                 GetStandardScale2() const;
    void                SetStandardScale2(int val) const;
    bool                GetLayerPropertyOverrides() const;

    IAcadPViewport* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadPViewportPtr = std::unique_ptr<PyIAcadPViewportImpl>;

//------------------------------------------------------------------------------------
//PyIAcad3DFaceImpl
class PyIAcad3DFaceImpl : public PyIAcadEntityImpl
{
public:
    explicit PyIAcad3DFaceImpl(IAcad3DFace* ptr);
    virtual ~PyIAcad3DFaceImpl() override = default;
    AcGePoint3dArray        GetCoordinates() const;
    void                    SetCoordinates(const AcGePoint3d& p1, const AcGePoint3d& p2, const AcGePoint3d& p3, const AcGePoint3d& p4) const;
    bool                    GetInvisibleEdge(int index) const;
    void                    SetInvisibleEdge(int index, bool flag) const;
    AcGePoint3d             GetCoordinate(int index) const;
    void                    SetCoordinate(int index, const AcGePoint3d& val) const;

    IAcad3DFace* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcad3DFacePtr = std::unique_ptr<PyIAcad3DFaceImpl>;

//------------------------------------------------------------------------------------
//PyIAcadPolygonMeshImpl
class PyIAcadPolygonMeshImpl : public PyIAcadEntityImpl
{
public:
    explicit PyIAcadPolygonMeshImpl(IAcadPolygonMesh* ptr);
    virtual ~PyIAcadPolygonMeshImpl() override = default;

    Point3dCoordinates      GetCoordinates() const;
    void                    SetCoordinates(const Point3dCoordinates& coords) const;
    bool                    GetMClose() const;
    void                    SetMClose(bool val) const;
    bool                    GetNClose() const;
    void                    SetNClose(bool val) const;
    long                    GetMDensity() const;
    void                    SetMDensity(long val) const;
    long                    GetNDensity() const;
    void                    SetNDensity(long val) const;
    long                    GetMVertexCount() const;
    long                    GetNVertexCount() const;
    PyAcPolymeshType        GetType() const;
    void                    SetType(PyAcPolymeshType val) const;
    void                    AppendVertex(const AcGePoint3d& val) const;
    PyIAcadEntityPtrArray   Explode() const;
    AcGePoint3d             GetCoordinate(int index) const;
    void                    SetCoordinate(int index, const AcGePoint3d& val) const;

    IAcadPolygonMesh* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadPolygonMeshPtr = std::unique_ptr<PyIAcadPolygonMeshImpl>;

//------------------------------------------------------------------------------------
//PyIAcad3DPolylineImpl
class PyIAcad3DPolylineImpl : public PyIAcadEntityImpl
{
public:
    explicit PyIAcad3DPolylineImpl(IAcad3DPolyline* ptr);
    virtual ~PyIAcad3DPolylineImpl() override = default;

    Point3dCoordinates      GetCoordinates() const;
    void                    SetCoordinates(const Point3dCoordinates& coords) const;
    void                    AppendVertex(const AcGePoint3d& val) const;
    PyIAcadEntityPtrArray   Explode() const;
    AcGePoint3d             GetCoordinate(int index) const;
    void                    SetCoordinate(int index, const AcGePoint3d& val) const;
    PyAc3DPolylineType      GetType() const;
    void                    SetType(PyAc3DPolylineType val) const;
    bool                    GetClosed() const;
    void                    SetClosed(bool val) const;
    double                  GetLength() const;

    IAcad3DPolyline* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcad3DPolylinePtr = std::unique_ptr<PyIAcad3DPolylineImpl>;

//------------------------------------------------------------------------------------
//PyIAcadArcImpl
class PyIAcadArcImpl : public PyIAcadEntityImpl
{
public:
    explicit PyIAcadArcImpl(IAcadArc* ptr);
    virtual ~PyIAcadArcImpl() override = default;

    AcGePoint3d             GetStartPoint() const;
    AcGePoint3d             GetCenter() const;
    void                    SetCenter(const AcGePoint3d& val) const;
    AcGePoint3d             GetEndPoint() const;
    double                  GetRadius() const;
    void                    SetRadius(double val) const;
    double                  GetStartAngle() const;
    void                    SetStartAngle(double val) const;
    double                  GetEndAngle() const;
    void                    SetEndAngle(double val) const;
    double                  GetTotalAngle() const;
    double                  GetArcLength() const;
    double                  GetThickness() const;
    void                    SetThickness(double val) const;
    PyIAcadEntityPtrArray   Offset(double val) const;
    double                  GetArea() const;
    AcGeVector3d            GetNormal() const;
    void                    SetNormal(const AcGeVector3d& val) const;

    IAcadArc* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadArcPtr = std::unique_ptr<PyIAcadArcImpl>;

//------------------------------------------------------------------------------------
//PyIAcadAttributeImpl
class PyIAcadAttributeImpl : public PyIAcadEntityImpl
{
public:
    explicit PyIAcadAttributeImpl(IAcadAttribute* ptr);
    virtual ~PyIAcadAttributeImpl() override = default;

    long                    GetFieldLength() const;
    void                    SetFieldLength(long val) const;
    CString                 GetTagString() const;
    void                    SetTagString(const CString& val) const;
    CString                 GetPromptString() const;
    void                    SetPromptString(const CString& val) const;
    CString                 GetTextString() const;
    void                    SetTextString(const CString& val) const;
    CString                 GetStyleName() const;
    void                    SetStyleName(const CString& val) const;
    PyAcAlignment           GetAlignment() const;
    void                    SetAlignment(PyAcAlignment val) const;
    PyAcHorizontalAlignment GetHorizontalAlignment() const;
    void                    SetHorizontalAlignment(PyAcHorizontalAlignment val) const;
    PyAcVerticalAlignment   GetVerticalAlignment() const;
    void                    SetVerticalAlignment(PyAcVerticalAlignment val) const;
    double                  GetHeight() const;
    void                    SetHeight(double val) const;
    double                  GetRotation() const;
    void                    SetRotation(double val) const;
    double                  GetScaleFactor() const;
    void                    SetScaleFactor(double val) const;
    double                  GetObliqueAngle() const;
    void                    SetObliqueAngle(double val) const;
    AcGePoint3d             GetTextAlignmentPoint() const;
    void                    SetTextAlignmentPoint(const AcGePoint3d& val) const;
    AcGePoint3d             GetInsertionPoint() const;
    void                    SetInsertionPoint(const AcGePoint3d& val) const;
    AcGeVector3d            GetNormal() const;
    void                    SetNormal(const AcGeVector3d& val) const;
    long                    GetTextGenerationFlag() const;
    void                    SetTextGenerationFlag(long val) const;
    double                  GetThickness() const;
    void                    SetThickness(double val) const;
    long                    GetMode() const;
    void                    SetMode(long val) const;
    bool                    GetUpsideDown() const;
    void                    SetUpsideDown(bool val) const;
    bool                    GetBackward() const;
    void                    SetBackward(bool val) const;
    bool                    GetInvisible() const;
    void                    SetInvisible(bool val) const;
    bool                    GetConstant() const;
    void                    SetConstant(bool val) const;
    bool                    GetVerify() const;
    void                    SetVerify(bool val) const;
    bool                    GetPreset() const;
    void                    SetPreset(bool val) const;
    bool                    GetLockPosition() const;
    void                    SetLockPosition(bool val) const;
    bool                    GetMTextAttribute() const;
    void                    SetMTextAttribute(bool val) const;
    CString                 GetMTextAttributeContent() const;
    void                    SetMTextAttributeContent(const CString& val) const;
    void                    UpdateMTextAttribute() const;
    double                  GetMTextBoundaryWidth() const;
    void                    SetMTextBoundaryWidth(double val) const;
    PyAcDrawingDirection    GetMTextDrawingDirection() const;
    void                    SetMTextDrawingDirection(PyAcDrawingDirection val) const;

    IAcadAttribute* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadAttributePtr = std::unique_ptr<PyIAcadAttributeImpl>;

//------------------------------------------------------------------------------------
//PyIAcadAttributeReferenceImpl
class PyIAcadAttributeReferenceImpl : public PyIAcadEntityImpl
{
public:
    explicit PyIAcadAttributeReferenceImpl(IAcadAttributeReference* ptr);
    virtual ~PyIAcadAttributeReferenceImpl() override = default;

    double                  GetHeight() const;
    void                    SetHeight(double val) const;
    PyAcAlignment           GetAlignment() const;
    void                    SetAlignment(PyAcAlignment val) const;
    PyAcHorizontalAlignment GetHorizontalAlignment() const;
    void                    SetHorizontalAlignment(PyAcHorizontalAlignment val) const;
    PyAcVerticalAlignment   GetVerticalAlignment() const;
    void                    SetVerticalAlignment(PyAcVerticalAlignment val) const;
    AcGePoint3d             GetInsertionPoint() const;
    void                    SetInsertionPoint(const AcGePoint3d& val) const;
    AcGeVector3d            GetNormal() const;
    void                    SetNormal(const AcGeVector3d& val) const;
    double                  GetObliqueAngle() const;
    void                    SetObliqueAngle(double val) const;
    double                  GetRotation() const;
    void                    SetRotation(double val) const;
    double                  GetScaleFactor() const;
    void                    SetScaleFactor(double val) const;
    CString                 GetStyleName() const;
    void                    SetStyleName(const CString& val) const;
    CString                 GetTagString() const;
    void                    SetTagString(const CString& val) const;
    AcGePoint3d             GetTextAlignmentPoint() const;
    void                    SetTextAlignmentPoint(const AcGePoint3d& val) const;
    long                    GetTextGenerationFlag() const;
    void                    SetTextGenerationFlag(long val) const;
    CString                 GetTextString() const;
    void                    SetTextString(const CString& val) const;
    double                  GetThickness() const;
    void                    SetThickness(double val) const;
    long                    GetFieldLength() const;
    void                    SetFieldLength(long val) const;
    bool                    GetUpsideDown() const;
    void                    SetUpsideDown(bool val) const;
    bool                    GetBackward() const;
    void                    SetBackward(bool val) const;
    bool                    GetInvisible() const;
    void                    SetInvisible(bool val) const;
    bool                    GetConstant() const;
    bool                    GetLockPosition() const;
    bool                    GetMTextAttribute() const;
    void                    SetMTextAttribute(bool val) const;
    CString                 GetMTextAttributeContent() const;
    void                    SetMTextAttributeContent(const CString& val) const;
    void                    UpdateMTextAttribute() const;
    double                  GetMTextBoundaryWidth() const;
    void                    SetMTextBoundaryWidth(double val) const;
    PyAcDrawingDirection    GetMTextDrawingDirection() const;
    void                    SetMTextDrawingDirection(PyAcDrawingDirection val) const;

    IAcadAttributeReference* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadAttributeReferencePtr = std::unique_ptr<PyIAcadAttributeReferenceImpl>;

//------------------------------------------------------------------------------------
//PyIAcadRegionImpl
class PyIAcadRegionImpl : public PyIAcadEntityImpl
{
public:
    explicit PyIAcadRegionImpl(IAcadRegion* ptr);
    virtual ~PyIAcadRegionImpl() override = default;

    double                  GetArea() const;
    AcGePoint2d             GetCentroid() const;
    AcGePoint3d             GetMomentOfInertia() const;
    AcGeVector3d            GetNormal() const;
    double                  GetPerimeter() const;
    Vector3dDirections      GetPrincipalDirections() const;
    AcGePoint3d             GetPrincipalMoments() const;
    AcGePoint3d             GetRadiiOfGyration() const;
    void                    Boolean(PyAcBooleanType val, const PyIAcadRegionImpl& region) const;
    PyIAcadEntityPtrArray   Explode() const;

    IAcadRegion* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadRegionPtr = std::unique_ptr<PyIAcadRegionImpl>;

//------------------------------------------------------------------------------------
//PyIAcad3DSolidImpl
class PyIAcad3DSolidImpl : public PyIAcadEntityImpl
{
public:
    explicit PyIAcad3DSolidImpl(IAcad3DSolid* ptr);
    virtual ~PyIAcad3DSolidImpl() override = default;

    AcGePoint3d             GetCentroid() const;
    AcGePoint3d             GetMomentOfInertia() const;
    Vector3dDirections      GetPrincipalDirections() const;
    AcGePoint3d             GetPrincipalMoments() const;
    AcGePoint3d             GetProductOfInertia() const;
    AcGePoint3d             GetRadiiOfGyration() const;
    double                  GetVolume() const;
    void                    Boolean(PyAcBooleanType val, const PyIAcad3DSolidImpl& solid) const;
    std::unique_ptr<PyIAcad3DSolidImpl> CheckInterference(const PyIAcad3DSolidImpl& solid, bool createInterferenceSolid, bool& outSolidsInterfere) const;
    std::unique_ptr<PyIAcad3DSolidImpl> SliceSolid(const AcGePoint3d& p1, const AcGePoint3d& p2, const AcGePoint3d& p3, bool negative) const;
    PyIAcadRegionPtr        SectionSolid(const AcGePoint3d& p1, const AcGePoint3d& p2, const AcGePoint3d& p3) const;
    CString                 GetSolidType() const;
    AcGePoint3d             GetPosition() const;
    void                    SetPosition(const AcGePoint3d& val) const;
    bool                    GetHistory() const;
    void                    SetHistory(bool val) const;
    bool                    GetShowHistory() const;
    void                    SetShowHistory(bool val) const;

    IAcad3DSolid* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcad3DSolidPtr = std::unique_ptr<PyIAcad3DSolidImpl>;

//------------------------------------------------------------------------------------
//PyIAcadCircleImpl
class PyIAcadCircleImpl : public PyIAcadEntityImpl
{
public:
    explicit PyIAcadCircleImpl(IAcadCircle* ptr);
    virtual ~PyIAcadCircleImpl() override = default;

    AcGePoint3d             GetCenter() const;
    void                    SetCenter(const AcGePoint3d& val) const;
    double                  GetRadius() const;
    void                    SetRadius(double val) const;
    double                  GetDiameter() const;
    void                    SetDiameter(double val) const;
    double                  GetCircumference() const;
    void                    SetCircumference(double val) const;
    double                  GetArea() const;
    void                    SetArea(double val) const;
    AcGeVector3d            GetNormal() const;
    void                    SetNormal(const AcGeVector3d& val) const;
    double                  GetThickness() const;
    void                    SetThickness(double val) const;
    PyIAcadEntityPtrArray   Offset(double val) const;

    IAcadCircle* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadCirclePtr = std::unique_ptr<PyIAcadCircleImpl>;

//------------------------------------------------------------------------------------
//PyIAcadEllipseImpl
class PyIAcadEllipseImpl : public PyIAcadEntityImpl
{
public:
    explicit PyIAcadEllipseImpl(IAcadEllipse* ptr);
    virtual ~PyIAcadEllipseImpl() override = default;

    AcGePoint3d             GetStartPoint() const;
    AcGePoint3d             GetEndPoint() const;
    AcGePoint3d             GetCenter() const;
    void                    SetCenter(const AcGePoint3d& val) const;
    double                  GetMajorRadius() const;
    void                    SetMajorRadius(double val) const;
    double                  GetMinorRadius() const;
    void                    SetMinorRadius(double val) const;
    double                  GetRadiusRatio() const;
    void                    SetRadiusRatio(double val) const;
    double                  GetStartAngle() const;
    void                    SetStartAngle(double val) const;
    double                  GetEndAngle() const;
    void                    SetEndAngle(double val) const;
    double                  GetStartParameter() const;
    void                    SetStartParameter(double val) const;
    double                  GetEndParameter() const;
    void                    SetEndParameter(double val) const;
    AcGeVector3d            GetMajorAxis() const;
    void                    SetMajorAxis(AcGeVector3d val) const;
    AcGeVector3d            GetMinorAxis() const;
    AcGeVector3d            GetNormal() const;
    void                    SetNormal(AcGeVector3d val) const;
    double                  GetArea() const;
    PyIAcadEntityPtrArray   Offset(double val) const;

    IAcadEllipse* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadEllipsePtr = std::unique_ptr<PyIAcadEllipseImpl>;

//------------------------------------------------------------------------------------
//PyIAcadLeaderImpl
class PyIAcadLeaderImpl : public PyIAcadEntityImpl
{
public:
    explicit PyIAcadLeaderImpl(IAcadLeader* ptr);
    virtual ~PyIAcadLeaderImpl() override = default;

    Point3dCoordinates      GetCoordinates() const;
    void                    SetCoordinates(const Point3dCoordinates& coords) const;
    AcGeVector3d            GetNormal() const;
    CString                 GetStyleName() const;
    void                    SetStyleName(const CString& val) const;
    PyAcLeaderType          GetType() const;
    void                    SetType(PyAcLeaderType val) const;
    void                    Evaluate() const;
    AcGePoint3d             GetCoordinate(int index) const;
    void                    SetCoordinate(int index, const AcGePoint3d& val) const;
    PyIAcadEntityPtr        GetAnnotation() const;
    void                    SetAnnotation(const PyIAcadEntityImpl& val) const;
    double                  GetArrowheadSize() const;
    void                    SetArrowheadSize(double val) const;
    PyAcDimArrowheadType    GetArrowheadType() const;
    void                    SetArrowheadType(PyAcDimArrowheadType val) const;
    PyAcColor               GetDimensionLineColor() const;
    void                    SetDimensionLineColor(PyAcColor val) const;
    PyAcLineWeight          GetDimensionLineWeight() const;
    void                    SetDimensionLineWeight(PyAcLineWeight val) const;
    double                  GetScaleFactor() const;
    void                    SetScaleFactor(double val) const;
    PyAcDimVerticalJustification    GetVerticalTextPosition() const;
    void                            SetVerticalTextPosition(PyAcDimVerticalJustification val) const;
    double                  GetTextGap() const;
    void                    SetTextGap(double val) const;
    CString                 GetArrowheadBlock() const;
    void                    SetArrowheadBlock(const CString& val) const;

    IAcadLeader* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadLeaderPtr = std::unique_ptr<PyIAcadLeaderImpl>;

//------------------------------------------------------------------------------------
//PyIAcadMTextImpl
class PyIAcadMTextImpl : public PyIAcadEntityImpl
{
public:
    explicit PyIAcadMTextImpl(IAcadMText* ptr);
    virtual ~PyIAcadMTextImpl() override = default;

    CString                 GetText() const;
    CString                 GetTextString() const;
    void                    SetTextString(const CString& val) const;
    CString                 GetStyleName() const;
    void                    SetStyleName(const CString& val) const;
    PyAcAttachmentPoint     GetAttachmentPoint() const;
    void                    SetAttachmentPoint(PyAcAttachmentPoint val) const;
    PyAcDrawingDirection    GetDrawingDirection() const;
    void                    SetDrawingDirection(PyAcDrawingDirection val) const;
    double                  GetWidth() const;
    void                    SetWidth(double val) const;
    double                  GetHeight() const;
    void                    SetHeight(double val) const;
    double                  GetRotation() const;
    void                    SetRotation(double val) const;
    AcGePoint3d             GetInsertionPoint() const;
    void                    SetInsertionPoint(const AcGePoint3d& val) const;
    AcGeVector3d            GetNormal() const;
    void                    SetNormal(const AcGeVector3d& val) const;
    double                  GetLineSpacingFactor() const;
    void                    SetLineSpacingFactor(double val) const;
    PyAcLineSpacingStyle    GetLineSpacingStyle() const;
    void                    SetLineSpacingStyle(PyAcLineSpacingStyle val) const;
    double                  GetLineSpacingDistance() const;
    void                    SetLineSpacingDistance(double val) const;
    bool                    GetBackgroundFill() const;
    void                    SetBackgroundFill(bool val) const;
    CString                 GetFieldCode() const;

    IAcadMText* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadMTextPtr = std::unique_ptr<PyIAcadMTextImpl>;

//------------------------------------------------------------------------------------
//PyIAcadPointImpl
class PyIAcadPointImpl : public PyIAcadEntityImpl
{
public:
    explicit PyIAcadPointImpl(IAcadPoint* ptr);
    virtual ~PyIAcadPointImpl() override = default;

    AcGePoint3d             GetCoordinates() const;
    void                    SetCoordinates(const AcGePoint3d& val) const;
    AcGeVector3d            GetNormal() const;
    void                    SetNormal(const AcGeVector3d& val) const;
    double                  GetThickness() const;
    void                    SetThickness(double val) const;

    IAcadPoint* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadPointPtr = std::unique_ptr<PyIAcadPointImpl>;

//------------------------------------------------------------------------------------
//PyIAcadLWPolylineImpl
class PyIAcadLWPolylineImpl : public PyIAcadEntityImpl
{
public:
    explicit PyIAcadLWPolylineImpl(IAcadLWPolyline* ptr);
    virtual ~PyIAcadLWPolylineImpl() override = default;

    Point2dCoordinates      GetCoordinates() const;
    void                    SetCoordinates(const Point2dCoordinates& coords) const;
    AcGeVector3d            GetNormal() const;
    void                    SetNormal(const AcGeVector3d& val) const;
    double                  GetThickness() const;
    void                    SetThickness(double val) const;
    void                    AddVertex(int index, const AcGePoint2d& val) const;
    PyIAcadEntityPtrArray   Explode() const;
    double                  GetBulge(int index) const;
    void                    SetBulge(int index, double val) const;
    void                    GetWidth(int index, double& startWidth, double& endWidth) const;
    void                    SetWidth(int index, double startWidth, double endWidth) const;
    double                  GetConstantWidth() const;
    void                    SetConstantWidth(double val) const;
    PyIAcadEntityPtrArray   Offset(double val) const;
    double                  GetElevation() const;
    void                    SetElevation(double val) const;
    double                  GetArea() const;
    AcGePoint2d             GetCoordinate(int index) const;
    void                    SetCoordinate(int index, const AcGePoint2d& val) const;
    bool                    GetClosed() const;
    void                    SetClosed(bool val) const;
    bool                    GetLinetypeGeneration() const;
    void                    SetLinetypeGeneration(bool val) const;
    double                  GetLength() const;

    IAcadLWPolyline* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadLWPolylinePtr = std::unique_ptr<PyIAcadLWPolylineImpl>;

//------------------------------------------------------------------------------------
//PyIAcadPolylineImpl
class PyIAcadPolylineImpl : public PyIAcadEntityImpl
{
public:
    explicit PyIAcadPolylineImpl(IAcadPolyline* ptr);
    virtual ~PyIAcadPolylineImpl() override = default;

    Point3dCoordinates      GetCoordinates() const;
    void                    SetCoordinates(const Point3dCoordinates& coords) const;
    AcGeVector3d            GetNormal() const;
    void                    SetNormal(const AcGeVector3d& val) const;
    double                  GetThickness() const;
    void                    SetThickness(double val) const;
    PyIAcadEntityPtrArray   Explode() const;
    double                  GetBulge(int index) const;
    void                    SetBulge(int index, double val) const;
    void                    GetWidth(int index, double& startWidth, double& endWidth) const;
    void                    SetWidth(int index, double startWidth, double endWidth) const;
    double                  GetConstantWidth() const;
    void                    SetConstantWidth(double val) const;
    PyIAcadEntityPtrArray   Offset(double val) const;
    double                  GetElevation() const;
    void                    SetElevation(double val) const;
    double                  GetArea() const;
    AcGePoint3d             GetCoordinate(int index) const;
    void                    SetCoordinate(int index, const AcGePoint3d& val) const;
    bool                    GetClosed() const;
    void                    SetClosed(bool val) const;
    bool                    GetLinetypeGeneration() const;
    void                    SetLinetypeGeneration(bool val) const;
    double                  GetLength() const;
    PyAcPolylineType        GetType() const;
    void                    SetType(PyAcPolylineType val) const;

    IAcadPolyline* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadPolylinePtr = std::unique_ptr<PyIAcadPolylineImpl>;

//------------------------------------------------------------------------------------
//PyIAcadRayImpl
class PyIAcadRayImpl : public PyIAcadEntityImpl
{
public:
    explicit PyIAcadRayImpl(IAcadRay* ptr);
    virtual ~PyIAcadRayImpl() override = default;

    AcGePoint3d             GetBasePoint() const;
    void                    SetBasePoint(const AcGePoint3d& val) const;
    AcGePoint3d             GetSecondPoint() const;
    void                    SetSecondPoint(const AcGePoint3d& val) const;
    AcGeVector3d            GetDirectionVector() const;
    void                    SetDirectionVector(const AcGeVector3d& val) const;

    IAcadRay* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadRayPtr = std::unique_ptr<PyIAcadRayImpl>;

//------------------------------------------------------------------------------------
//PyIAcadShapeImpl
class PyIAcadShapeImpl : public PyIAcadEntityImpl
{
public:
    explicit PyIAcadShapeImpl(IAcadShape* ptr);
    virtual ~PyIAcadShapeImpl() override = default;

    AcGePoint3d             GetInsertionPoint() const;
    void                    SetInsertionPoint(const AcGePoint3d& val) const;
    CString                 GetName() const;
    void                    SetName(const CString& val) const;
    double                  GetHeight() const;
    void                    SetHeight(double val) const;
    double                  GetRotation() const;
    void                    SetRotation(double val) const;
    double                  GetScaleFactor() const;
    void                    SetScaleFactor(double val) const;
    double                  GetObliqueAngle() const;
    void                    SetObliqueAngle(double val) const;
    AcGeVector3d            GetNormal() const;
    void                    SetNormal(const AcGeVector3d& val) const;
    double                  GetThickness() const;
    void                    SetThickness(double val) const;

    IAcadShape* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadShapePtr = std::unique_ptr<PyIAcadShapeImpl>;

//------------------------------------------------------------------------------------
//PyIAcadSolidImpl
class PyIAcadSolidImpl : public PyIAcadEntityImpl
{
public:
    explicit PyIAcadSolidImpl(IAcadSolid* ptr);
    virtual ~PyIAcadSolidImpl() override = default;

    Point3dCoordinates      GetCoordinates() const;
    void                    SetCoordinates(const Point3dCoordinates& coords) const;
    AcGeVector3d            GetNormal() const;
    void                    SetNormal(const AcGeVector3d& val) const;
    double                  GetThickness() const;
    void                    SetThickness(double val) const;
    AcGePoint3d             GetCoordinate(int index) const;
    void                    SetCoordinate(int index, const AcGePoint3d& val) const;

    IAcadSolid* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadSolidPtr = std::unique_ptr<PyIAcadSolidImpl>;

//------------------------------------------------------------------------------------
//PyIAcadSplineImpl
class PyIAcadSplineImpl : public PyIAcadEntityImpl
{
public:
    explicit PyIAcadSplineImpl(IAcadSpline* ptr);
    virtual ~PyIAcadSplineImpl() override = default;

    long                    GetNumberOfControlPoints() const;
    Point3dCoordinates      GetControlPoints() const;
    void                    SetControlPoints(const Point3dCoordinates& coords) const;
    Point3dCoordinates      GetFitPoints() const;
    void                    SetFitPoints(const Point3dCoordinates& coords) const;
    long                    GetDegree() const;
    bool                    GetClosed() const;
    bool                    GetIsPlanar() const;
    bool                    GetIsRational() const;
    bool                    GetIsPeriodic() const;
    AcGeVector3d            GetStartTangent() const;
    void                    SetStartTangent(const AcGeVector3d& val) const;
    AcGeVector3d            GetEndTangent() const;
    void                    SetEndTangent(const AcGeVector3d& val) const;
    double                  GetFitTolerance() const;
    void                    SetFitTolerance(double val) const;
    double                  GetArea() const;
    AcGePoint3d             GetControlPoint(int index) const;
    void                    SetControlPoint(int index, const AcGePoint3d& val) const;
    AcGePoint3d             GetFitPoint(int index) const;
    void                    SetFitPoint(int index, const AcGePoint3d& val) const;
    double                  GetWeight(int index) const;
    void                    SetWeight(int index, double val) const;
    void                    AddFitPoint(int index, const AcGePoint3d& val) const;
    void                    DeleteFitPoint(int index) const;
    void                    ElevateOrder(int index) const;
    PyIAcadEntityPtrArray   Offset(double val) const;
    void                    PurgeFitData() const;
    void                    Reverse() const;
    Vector3dDirections      GetKnots() const;
    void                    SetKnots(const Vector3dDirections& val) const;
    Doubles                 GetWeights() const;
    void                    SetWeights(const Doubles& val) const;
    PyAcSplineKnotParameterizationType  GetKnotParameterization() const;
    void                                SetKnotParameterization(PyAcSplineKnotParameterizationType val) const;
    PyAcSplineFrameType     GetSplineFrame() const;
    void                    SetSplineFrame(PyAcSplineFrameType val) const;
    PyAcSplineMethodType    GetSplineMethod() const;
    void                    SetSplineMethod(PyAcSplineMethodType val) const;
    long                    GetDegree2() const;
    void                    SetDegree2(long val) const;
    bool                    GetClosed2() const;
    void                    SetClosed2(bool val) const;

    IAcadSpline* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadSplinePtr = std::unique_ptr<PyIAcadSplineImpl>;

//------------------------------------------------------------------------------------
//PyIAcadTextImpl
class PyIAcadTextImpl : public PyIAcadEntityImpl
{
public:
    explicit PyIAcadTextImpl(IAcadText* ptr);
    virtual ~PyIAcadTextImpl() override = default;

    CString                 GetTextString() const;
    void                    SetTextString(const CString& val) const;
    CString                 GetStyleName() const;
    void                    SetStyleName(const CString& val) const;
    PyAcAlignment           GetAlignment() const;
    void                    SetAlignment(PyAcAlignment val) const;
    PyAcHorizontalAlignment GetHorizontalAlignment() const;
    void                    SetHorizontalAlignment(PyAcHorizontalAlignment val) const;
    PyAcVerticalAlignment   GetVerticalAlignment() const;
    void                    SetVerticalAlignment(PyAcVerticalAlignment val) const;
    double                  GetHeight() const;
    void                    SetHeight(double val) const;
    double                  GetRotation() const;
    void                    SetRotation(double val) const;
    double                  GetScaleFactor() const;
    void                    SetScaleFactor(double val) const;
    double                  GetObliqueAngle() const;
    void                    SetObliqueAngle(double val) const;
    AcGePoint3d             GetTextAlignmentPoint() const;
    void                    SetTextAlignmentPoint(const AcGePoint3d& val) const;
    AcGePoint3d             GetInsertionPoint() const;
    void                    SetInsertionPoint(const AcGePoint3d& val) const;
    AcGeVector3d            GetNormal() const;
    void                    SetNormal(const AcGeVector3d& val) const;
    long                    GetTextGenerationFlag() const;
    void                    SetTextGenerationFlag(long val) const;
    double                  GetThickness() const;
    void                    SetThickness(double val) const;
    bool                    GetUpsideDown() const;
    void                    SetUpsideDown(bool val) const;
    bool                    GetBackward() const;
    void                    SetBackward(bool val) const;
    CString                 GetFieldCode() const;

    IAcadText* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadTextPtr = std::unique_ptr<PyIAcadTextImpl>;

//------------------------------------------------------------------------------------
//PyIAcadToleranceImpl
class PyIAcadToleranceImpl : public PyIAcadEntityImpl
{
public:
    explicit PyIAcadToleranceImpl(IAcadTolerance* ptr);
    virtual ~PyIAcadToleranceImpl() override = default;

    AcGeVector3d            GetDirectionVector() const;
    void                    SetDirectionVector(const AcGeVector3d& val) const;
    AcGePoint3d             GetInsertionPoint() const;
    void                    SetInsertionPoint(const AcGePoint3d& val) const;
    AcGeVector3d            GetNormal() const;
    void                    SetNormal(const AcGeVector3d& val) const;
    CString                 GetStyleName() const;
    void                    SetStyleName(const CString& val) const;
    PyAcColor               GetTextColor() const;
    void                    SetTextColor(PyAcColor val) const;
    CString                 GetTextString() const;
    void                    SetTextString(const CString& val) const;
    CString                 GetTextStyle() const;
    void                    SetTextStyle(const CString& val) const;
    double                  GetTextHeight() const;
    void                    SetTextHeight(double val) const;
    double                  GetScaleFactor() const;
    void                    SetScaleFactor(double val) const;
    PyAcColor               GetDimensionLineColor() const;
    void                    SetDimensionLineColor(PyAcColor val) const;

    IAcadTolerance* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadTolerancePtr = std::unique_ptr<PyIAcadToleranceImpl>;

//------------------------------------------------------------------------------------
//PyIAcadTraceImpl
class PyIAcadTraceImpl : public PyIAcadEntityImpl
{
public:
    explicit PyIAcadTraceImpl(IAcadTrace* ptr);
    virtual ~PyIAcadTraceImpl() override = default;

    Point3dCoordinates      GetCoordinates() const;
    void                    SetCoordinates(const Point3dCoordinates& coords) const;
    AcGeVector3d            GetNormal() const;
    void                    SetNormal(const AcGeVector3d& val) const;
    double                  GetThickness() const;
    void                    SetThickness(double val) const;
    AcGePoint3d             GetCoordinate(int index) const;
    void                    SetCoordinate(int index, const AcGePoint3d& val) const;

    IAcadTrace* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadTracePtr = std::unique_ptr<PyIAcadTraceImpl>;

//------------------------------------------------------------------------------------
//PyIAcadXlineImpl
class PyIAcadXlineImpl : public PyIAcadEntityImpl
{
public:
    explicit PyIAcadXlineImpl(IAcadXline* ptr);
    virtual ~PyIAcadXlineImpl() override = default;

    AcGePoint3d             GetBasePoint() const;
    void                    SetBasePoint(const AcGePoint3d& val) const;
    AcGePoint3d             GetSecondPoint() const;
    void                    SetSecondPoint(const AcGePoint3d& val) const;
    AcGeVector3d            GetDirectionVector() const;
    void                    SetDirectionVector(const AcGeVector3d& val) const;
    PyIAcadEntityPtrArray   Offset(double val) const;

    IAcadXline* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadXlinePtr = std::unique_ptr<PyIAcadXlineImpl>;

//------------------------------------------------------------------------------------
//PyIAcadBlockReferenceImpl
class PyIAcadBlockReferenceImpl : public PyIAcadEntityImpl
{
public:
    explicit PyIAcadBlockReferenceImpl(IAcadBlockReference* ptr);
    virtual ~PyIAcadBlockReferenceImpl() override = default;

    AcGePoint3d             GetInsertionPoint() const;
    void                    SetInsertionPoint(const AcGePoint3d& val) const;
    CString                 GetName() const;
    void                    SetName(const CString& val) const;
    AcGeVector3d            GetNormal() const;
    void                    SetNormal(const AcGeVector3d& val) const;
    double                  GetRotation() const;
    void                    SetRotation(double val) const;
    double                  GetXScaleFactor() const;
    void                    SetXScaleFactor(double val) const;
    double                  GetYScaleFactor() const;
    void                    SetYScaleFactor(double val) const;
    double                  GetZScaleFactor() const;
    void                    SetZScaleFactor(double val) const;
    PyIAcadEntityPtrArray   Explode() const;
    PyIAcadAttributeRefPtrArray     GetAttributes() const;
    PyIAcadAttributeRefPtrArray     GetConstantAttributes() const;
    PyIAcadDynRefPropPtrArray       GetDynamicBlockProperties() const;
    bool                    GetHasAttributes() const;
    CString                 GetEffectiveName() const;
    bool                    GetIsDynamicBlock() const;
    void                    ResetBlock() const;
    void                    ConvertToAnonymousBlock() const;
    void                    ConvertToStaticBlock(const CString& newBlockName) const;
    double                  GetXEffectiveScaleFactor() const;
    void                    SetXEffectiveScaleFactor(double val) const;
    double                  GetYEffectiveScaleFactor() const;
    void                    SetYEffectiveScaleFactor(double val) const;
    double                  GetZEffectiveScaleFactor() const;
    void                    SetZEffectiveScaleFactor(double val) const;
    CString                 GetInsUnits() const;
    double                  GetInsUnitsFactor() const;

    IAcadBlockReference* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadBlockReferencePtr = std::unique_ptr<PyIAcadBlockReferenceImpl>;

//------------------------------------------------------------------------------------
//PyIAcadMInsertBlockImpl
class PyIAcadMInsertBlockImpl : public PyIAcadBlockReferenceImpl
{
public:
    explicit PyIAcadMInsertBlockImpl(IAcadMInsertBlock* ptr);
    virtual ~PyIAcadMInsertBlockImpl() override = default;

    void        SetColumns(long val) const;
    long        GetColumns() const;
    void        SetRows(long val) const;
    long        GetRows() const;
    void        SetColumnSpacing(double val) const;
    double      GetColumnSpacing() const;
    void        SetRowSpacing(double val) const;
    double      GetRowSpacing() const;

    IAcadMInsertBlock* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadMInsertBlockPtr = std::unique_ptr<PyIAcadMInsertBlockImpl>;

//------------------------------------------------------------------------------------
//PyIAcadExternalReferenceImpl
class PyIAcadExternalReferenceImpl : public PyIAcadBlockReferenceImpl
{
public:
    explicit PyIAcadExternalReferenceImpl(IAcadExternalReference* ptr);
    virtual ~PyIAcadExternalReferenceImpl() override = default;

    CString                 GetPath() const;
    void                    SetPath(const CString& val) const;
    bool                    GetLayerPropertyOverrides() const;

    IAcadExternalReference* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadExternalReferencePtr = std::unique_ptr<PyIAcadExternalReferenceImpl>;


//------------------------------------------------------------------------------------
//PyIAcadHatchImpl
class PyIAcadHatchImpl : public PyIAcadEntityImpl
{
public:
    explicit PyIAcadHatchImpl(IAcadHatch* ptr);
    virtual ~PyIAcadHatchImpl() override = default;

    AcGeVector3d            GetNormal() const;
    void                    SetNormal(const AcGeVector3d& val) const;
    long                    GetNumberOfLoops() const;
    PyAcPatternType         GetPatternType() const;
    CString                 GetPatternName() const;
    double                  GetPatternAngle() const;
    void                    SetPatternAngle(double val) const;
    double                  GetPatternScale() const;
    void                    SetPatternScale(double val) const;
    double                  GetPatternSpace() const;
    void                    SetPatternSpace(double val) const;
    PyAcISOPenWidth         GetISOPenWidth() const;
    void                    SetISOPenWidth(PyAcISOPenWidth val) const;
    bool                    GetPatternDouble() const;
    void                    SetPatternDouble(bool val) const;
    double                  GetElevation() const;
    void                    SetElevation(double val) const;
    bool                    GetAssociativeHatch() const;
    void                    SetAssociativeHatch(bool val) const;
    PyAcHatchStyle          GetHatchStyle() const;
    void                    SetHatchStyle(PyAcHatchStyle val) const;
    void                    SetPattern(int patternType, const CString& name) const;
    void                    AppendOuterLoop(const PyIAcadEntityImplArray& objectArray) const;
    void                    AppendInnerLoop(const PyIAcadEntityImplArray& objectArray) const;
    void                    InsertLoopAt(int index, PyAcLoopType loopType, const PyIAcadEntityImplArray& objectArray) const;
    PyIAcadEntityPtrArray   GetLoopAt(int index) const;
    void                    Evaluate() const;
    PyIAcadAcCmColorPtr     GetGradientColor1() const;
    void                    SetGradientColor1(const PyIAcadAcCmColorImpl& val) const;
    PyIAcadAcCmColorPtr     GetGradientColor2() const;
    void                    SetGradientColor2(const PyIAcadAcCmColorImpl& val) const;
    double                  GetGradientAngle() const;
    void                    SetGradientAngle(double val) const;
    bool                    GetGradientCentered() const;
    void                    SetGradientCentered(bool val) const;
    CString                 GetGradientName() const;
    void                    SetGradientName(const CString& val) const;
    PyAcHatchObjectType     GetHatchObjectType() const;
    void                    SetHatchObjectType(PyAcHatchObjectType val) const;
    double                  GetArea() const;
    AcGePoint3d             GetOrigin() const;
    void                    SetOrigin(const AcGePoint3d& val) const;
    PyIAcadAcCmColorPtr     GetBackgroundColor() const;
    void                    SetBackgroundColor(const PyIAcadAcCmColorImpl& val) const;

    IAcadHatch* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadHatchPtr = std::unique_ptr<PyIAcadHatchImpl>;

//------------------------------------------------------------------------------------
//PyIAcadRasterImageImpl
class PyIAcadRasterImageImpl : public PyIAcadEntityImpl
{
public:
    explicit PyIAcadRasterImageImpl(IAcadRasterImage* ptr);
    virtual ~PyIAcadRasterImageImpl() override = default;

    long            GetBrightness() const;
    void            SetBrightness(long val) const;
    long            GetContrast() const;
    void            SetContrast(long val) const;
    long            GetFade() const;
    void            SetFade(long val) const;
    AcGePoint3d     GetOrigin() const;
    void            SetOrigin(const AcGePoint3d& val) const;
    double          GetRotation() const;
    void            SetRotation(double val) const;
    double          GetImageWidth() const;
    void            SetImageWidth(double val) const;
    double          GetImageHeight() const;
    void            SetImageHeight(double val) const;
    CString         GetName() const;
    void            SetName(const CString& val) const;
    CString         GetImageFile() const;
    void            SetImageFile(const CString& val) const;
    bool            GetImageVisibility() const;
    void            SetImageVisibility(bool val) const;
    bool            GetClippingEnabled() const;
    void            SetClippingEnabled(bool val) const;
    bool            GetTransparency() const;
    void            SetTransparency(bool val) const;
    void            SetClipBoundary(const Point2dCoordinates& val) const;
    double          GetHeight() const;
    double          GetWidth() const;
    bool            GetShowRotation() const;
    void            SetShowRotation(bool val) const;
    double          GetScaleFactor() const;
    void            SetScaleFactor(double val) const;

    IAcadRasterImage* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadRasterImagePtr = std::unique_ptr<PyIAcadRasterImageImpl>;

//------------------------------------------------------------------------------------
//PyIAcadLineImpl
class PyIAcadLineImpl : public PyIAcadEntityImpl
{
public:
    explicit PyIAcadLineImpl(IAcadLine* ptr);
    virtual ~PyIAcadLineImpl() override = default;

    AcGePoint3d             GetStartPoint() const;
    void                    SetStartPoint(const AcGePoint3d& val) const;
    AcGePoint3d             GetEndPoint() const;
    void                    SetEndPoint(const AcGePoint3d& val) const;
    AcGeVector3d            GetNormal() const;
    void                    SetNormal(const AcGeVector3d& val) const;
    PyIAcadEntityPtrArray   Offset(double val) const;
    double                  GetThickness() const;
    void                    SetThickness(double val) const;
    AcGeVector3d            GetDelta() const;
    double                  GetLength() const;
    double                  GetAngle() const;

    IAcadLine* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadLinePtr = std::unique_ptr<PyIAcadLineImpl>;

//------------------------------------------------------------------------------------
//PyIAcadPolyfaceMeshImpl
class PyIAcadPolyfaceMeshImpl : public PyIAcadEntityImpl
{
public:
    explicit PyIAcadPolyfaceMeshImpl(IAcadPolyfaceMesh* ptr);
    virtual ~PyIAcadPolyfaceMeshImpl() override = default;

    Point3dCoordinates      GetCoordinates() const;
    void                    SetCoordinates(const Point3dCoordinates& coords) const;
    AcGePoint3d             GetCoordinate(int index) const;
    void                    SetCoordinate(int index, const AcGePoint3d& val) const;
    long                    GetNumberOfVertices() const;
    long                    GetNumberOfFaces() const;
    void                    SetFaces(const Longs& coords) const;

    IAcadPolyfaceMesh* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadPolyfaceMeshPtr = std::unique_ptr<PyIAcadPolyfaceMeshImpl>;

//------------------------------------------------------------------------------------
//PyIAcadMLineImpl
class PyIAcadMLineImpl : public PyIAcadEntityImpl
{
public:
    explicit PyIAcadMLineImpl(IAcadMLine* ptr);
    virtual ~PyIAcadMLineImpl() override = default;

    CString                GetStyleName() const;
    Point3dCoordinates     GetCoordinates() const;
    void                   SetCoordinates(const Point3dCoordinates& coords) const;
    PyAcMLineJustification GetJustification() const;
    void                   SetJustification(PyAcMLineJustification val) const;
    double                 GetMLineScale() const;
    void                   SetMLineScale(double val) const;


    IAcadMLine* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadMLinePtr = std::unique_ptr<PyIAcadMLineImpl>;

//------------------------------------------------------------------------------------
//PyIAcadSectionImpl
class PyIAcadSectionImpl : public PyIAcadEntityImpl
{
public:
    explicit PyIAcadSectionImpl(IAcadSection* ptr);
    virtual ~PyIAcadSectionImpl() override = default;
    IAcadSection* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadSectionPtr = std::unique_ptr<PyIAcadSectionImpl>;

//------------------------------------------------------------------------------------
//PyIAcadMLeaderImpl
class PyIAcadMLeaderImpl : public PyIAcadEntityImpl
{
public:
    explicit PyIAcadMLeaderImpl(IAcadMLeader* ptr);
    virtual ~PyIAcadMLeaderImpl() override = default;

    double                  GetScaleFactor() const;
    void                    SetScaleFactor(double val) const;
    PyAcMLeaderType         GetLeaderType() const;
    void                    SetLeaderType(PyAcMLeaderType val) const;
    PyIAcadAcCmColorPtr     GetLeaderLineColor() const;
    void                    SetLeaderLineColor(const PyIAcadAcCmColorImpl& val) const;
    CString                 GetLeaderLinetype() const;
    void                    SetLeaderLinetype(const CString& val) const;
    PyAcLineWeight          GetLeaderLineWeight() const;
    void                    SetLeaderLineWeight(PyAcLineWeight val) const;
    PyAcDimArrowheadType    GetArrowheadType() const;
    void                    SetArrowheadType(PyAcDimArrowheadType val) const;
    double                  GetArrowheadSize() const;
    void                    SetArrowheadSize(double val) const;
    bool                    GetDogLegged() const;
    void                    SetDogLegged(bool val) const;
    double                  GetDoglegLength() const;
    void                    SetDoglegLength(double val) const;
    CString                 GetContentBlockName() const;
    void                    SetContentBlockName(const CString& val) const;
    PyAcBlockConnectionType GetBlockConnectionType() const;
    void                    SetBlockConnectionType(PyAcBlockConnectionType val) const;
    double                  GetBlockScale() const;
    void                    SetBlockScale(double val) const;
    CString                 GetTextString() const;
    void                    SetTextString(const CString& val) const;
    CString                 GetTextStyleName() const;
    void                    SetTextStyleName(const CString& val) const;
    PyAcAttachmentPoint     GetTextJustify() const;
    void                    SetTextJustify(PyAcAttachmentPoint val) const;
    PyAcDrawingDirection    GetTextDirection() const;
    void                    SetTextDirection(PyAcDrawingDirection val) const;
    double                  GetTextWidth() const;
    void                    SetTextWidth(double val) const;
    double                  GetTextHeight() const;
    void                    SetTextHeight(double val) const;
    double                  GetTextRotation() const;
    void                    SetTextRotation(double val) const;
    double                  GetTextLineSpacingFactor() const;
    void                    SetTextLineSpacingFactor(double val) const;
    double                  GetTextLineSpacingDistance() const;
    void                    SetTextLineSpacingDistance(double val) const;
    PyAcLineSpacingStyle    GetTextLineSpacingStyle() const;
    void                    SetTextLineSpacingStyle(PyAcLineSpacingStyle val) const;
    bool                    GetTextBackgroundFill() const;
    void                    SetTextBackgroundFill(bool val) const;
    PyAcTextAttachmentType  GetTextLeftAttachmentType() const;
    void                    SetTextLeftAttachmentType(PyAcTextAttachmentType val) const;
    PyAcTextAttachmentType  GetTextRightAttachmentType() const;
    void                    SetTextRightAttachmentType(PyAcTextAttachmentType val) const;
    double                  GetLandingGap() const;
    void                    SetLandingGap(double val) const;
    CString                 GetArrowheadBlock() const;
    void                    SetArrowheadBlock(const CString& val) const;
    PyAcPredefBlockType     GetContentBlockType() const;
    void                    SetContentBlockType(PyAcPredefBlockType val) const;
    int                     GetLeaderCount() const;
    int                     AddLeader() const;
    void                    RemoveLeader(int val) const;
    int                     AddLeaderLine(int leaderIndex, const Point3dCoordinates& coords) const;
    int                     AddLeaderLineEx(const Point3dCoordinates& coords) const;
    void                    RemoveLeaderLine(int val) const;
    void                    SetLeaderLineVertices(int leaderIndex, const Point3dCoordinates& coords) const;
    Point3dCoordinates      GetLeaderLineVertices(int leaderIndex) const;
    PyAcMLeaderContentType  GetContentType() const;
    void                    SetContentType(PyAcMLeaderContentType val) const;
    int                     GetLeaderIndex(int leaderLineIndex) const;
    Longs                   GetLeaderLineIndexes(int leaderLineIndex) const;
    int                     GetVertexCount(int leaderLineIndex) const;
    bool                    GetTextFrameDisplay() const;
    void                    SetTextFrameDisplay(bool val) const;
    CString                 GetStyleName() const;
    void                    SetStyleName(const CString& val) const;
    AcGeVector3d            GetDoglegDirection(int leaderIndex) const;
    void                    SetDoglegDirection(int leaderIndex, const AcGeVector3d& val) const;
    CString                 GetBlockAttributeValue(const AcDbObjectId& id) const;
    void                    SetBlockAttributeValue(const AcDbObjectId& id, const CString& val) const;
    PyAcTextAttachmentDirection     GetTextAttachmentDirection() const;
    void                            SetTextAttachmentDirection(PyAcTextAttachmentDirection val) const;
    PyAcVerticalTextAttachmentType  GetTextTopAttachmentType() const;
    void                            SetTextTopAttachmentType(PyAcVerticalTextAttachmentType val) const;
    PyAcVerticalTextAttachmentType  GetTextBottomAttachmentType() const;
    void                            SetTextBottomAttachmentType(PyAcVerticalTextAttachmentType val) const;

    IAcadMLeader* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadMLeaderPtr = std::unique_ptr<PyIAcadMLeaderImpl>;
