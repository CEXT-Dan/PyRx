#pragma once
#include "PyAcadDbObjectImpl.h"
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

    void    TransformBy(const AcGeMatrix3d& xform);
    IAcadEntity* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcadPViewportImpl
class PyIAcadPViewportImpl;
using PyIAcadPViewportPtr = std::unique_ptr<PyIAcadPViewportImpl>;
class PyIAcadPViewportImpl : public PyIAcadEntityImpl
{
public:
    explicit PyIAcadPViewportImpl(IAcadPViewport* ptr);
    virtual ~PyIAcadPViewportImpl() override = default;
    IAcadPViewport* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyIAcad3DFaceImpl
class PyIAcad3DFaceImpl : public PyIAcadEntityImpl
{
public:
    explicit PyIAcad3DFaceImpl(IAcad3DFace* ptr);
    virtual ~PyIAcad3DFaceImpl() override = default;
    AcGePoint3dArray        GetCoordinates() const;
    void                    SetCoordinates(const AcGePoint3d& p1, const AcGePoint3d& p2, const AcGePoint3d& p3, const AcGePoint3d& p4);
    bool                    GetInvisibleEdge(int index) const;
    void                    SetInvisibleEdge(int index, bool flag);
    AcGePoint3d             GetCoordinate(int index) const;
    void                    SetCoordinate(int index, const AcGePoint3d& val);

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
    IAcadAttribute* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadAttributePtr = std::unique_ptr<PyIAcadAttributeImpl>;

//------------------------------------------------------------------------------------
//PyIAcadRegionImpl
class PyIAcadRegionImpl : public PyIAcadEntityImpl
{
public:
    explicit PyIAcadRegionImpl(IAcadRegion* ptr);
    virtual ~PyIAcadRegionImpl() override = default;
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
    IAcadCircle* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadCirclePtr = std::unique_ptr<PyIAcadCircleImpl>;

//------------------------------------------------------------------------------------
//PyIAcadDimensionImpl
class PyIAcadDimensionImpl : public PyIAcadEntityImpl
{
public:
    explicit PyIAcadDimensionImpl(IAcadDimension* ptr);
    virtual ~PyIAcadDimensionImpl() override = default;
    IAcadDimension* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadDimensionPtr = std::unique_ptr<PyIAcadDimensionImpl>;

//------------------------------------------------------------------------------------
//PyIAcadDimAlignedImpl
class PyIAcadDimAlignedImpl : public PyIAcadDimensionImpl
{
public:
    explicit PyIAcadDimAlignedImpl(IAcadDimAligned* ptr);
    virtual ~PyIAcadDimAlignedImpl() override = default;
    IAcadDimAligned* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadDimAlignedPtr = std::unique_ptr<PyIAcadDimAlignedImpl>;

//------------------------------------------------------------------------------------
//PyIAcadDimAngularImpl
class PyIAcadDimAngularImpl : public PyIAcadDimensionImpl
{
public:
    explicit PyIAcadDimAngularImpl(IAcadDimAngular* ptr);
    virtual ~PyIAcadDimAngularImpl() override = default;
    IAcadDimAngular* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadDimAngularPtr = std::unique_ptr<PyIAcadDimAngularImpl>;

//------------------------------------------------------------------------------------
//PyIAcadDimDiametricImpl
class PyIAcadDimDiametricImpl : public PyIAcadDimensionImpl
{
public:
    explicit PyIAcadDimDiametricImpl(IAcadDimDiametric* ptr);
    virtual ~PyIAcadDimDiametricImpl() override = default;
    IAcadDimDiametric* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadDimDiametricPtr = std::unique_ptr<PyIAcadDimDiametricImpl>;

//------------------------------------------------------------------------------------
//PyIAcadDimRotatedImpl
class PyIAcadDimRotatedImpl : public PyIAcadDimensionImpl
{
public:
    explicit PyIAcadDimRotatedImpl(IAcadDimRotated* ptr);
    virtual ~PyIAcadDimRotatedImpl() override = default;
    IAcadDimRotated* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadDimRotatedPtr = std::unique_ptr<PyIAcadDimRotatedImpl>;

//------------------------------------------------------------------------------------
//PyIAcadDimOrdinateImpl
class PyIAcadDimOrdinateImpl : public PyIAcadDimensionImpl
{
public:
    explicit PyIAcadDimOrdinateImpl(IAcadDimOrdinate* ptr);
    virtual ~PyIAcadDimOrdinateImpl() override = default;
    IAcadDimOrdinate* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadDimOrdinatePtr = std::unique_ptr<PyIAcadDimOrdinateImpl>;

//------------------------------------------------------------------------------------
//PyIAcadDimRadialImpl
class PyIAcadDimRadialImpl : public PyIAcadDimensionImpl
{
public:
    explicit PyIAcadDimRadialImpl(IAcadDimRadial* ptr);
    virtual ~PyIAcadDimRadialImpl() override = default;
    IAcadDimRadial* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadDimRadialPtr = std::unique_ptr<PyIAcadDimRadialImpl>;

//------------------------------------------------------------------------------------
//PyIAcadDim3PointAngularImpl
class PyIAcadDim3PointAngularImpl : public PyIAcadDimensionImpl
{
public:
    explicit PyIAcadDim3PointAngularImpl(IAcadDim3PointAngular* ptr);
    virtual ~PyIAcadDim3PointAngularImpl() override = default;
    IAcadDim3PointAngular* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadDim3PointAngularPtr = std::unique_ptr<PyIAcadDim3PointAngularImpl>;

//------------------------------------------------------------------------------------
//PyIAcadDimArcLengthImpl
class PyIAcadDimArcLengthImpl : public PyIAcadDimensionImpl
{
public:
    explicit PyIAcadDimArcLengthImpl(IAcadDimArcLength* ptr);
    virtual ~PyIAcadDimArcLengthImpl() override = default;
    IAcadDimArcLength* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadDimArcLengthPtr = std::unique_ptr<PyIAcadDimArcLengthImpl>;

//------------------------------------------------------------------------------------
//PyIAcadDimRadialLargeImpl
class PyIAcadDimRadialLargeImpl : public PyIAcadDimensionImpl
{
public:
    explicit PyIAcadDimRadialLargeImpl(IAcadDimRadialLarge* ptr);
    virtual ~PyIAcadDimRadialLargeImpl() override = default;
    IAcadDimRadialLarge* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadDimRadialLargePtr = std::unique_ptr<PyIAcadDimRadialLargeImpl>;

//------------------------------------------------------------------------------------
//PyIAcadEllipseImpl
class PyIAcadEllipseImpl : public PyIAcadEntityImpl
{
public:
    explicit PyIAcadEllipseImpl(IAcadEllipse* ptr);
    virtual ~PyIAcadEllipseImpl() override = default;
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
    IAcadMLine* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadMLinePtr = std::unique_ptr<PyIAcadMLineImpl>;

//------------------------------------------------------------------------------------
//PyIAcadTableImpl
class PyIAcadTableImpl : public PyIAcadEntityImpl
{
public:
    explicit PyIAcadTableImpl(IAcadTable* ptr);
    virtual ~PyIAcadTableImpl() override = default;
    IAcadTable* impObj(const std::source_location& src = std::source_location::current()) const;
};
using PyIAcadTablePtr = std::unique_ptr<PyIAcadTableImpl>;
