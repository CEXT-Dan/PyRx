#include "stdafx.h"
#include "PyAcadEntityImpl.h"

//------------------------------------------------------------------------------------
//PyIAcadSubEntityImpl
#ifndef _GRXTARGET
PyIAcadSubEntityImpl::PyIAcadSubEntityImpl(IAcadSubEntity* ptr)
    : m_pimpl(ptr)
{
}

IAcadSubEntity* PyIAcadSubEntityImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadSubEntity*>(m_pimpl.GetInterfacePtr());
}
#endif

//------------------------------------------------------------------------------------
//PyIAcadMLeaderLeaderImpl
#ifndef _GRXTARGET
PyIAcadMLeaderLeaderImpl::PyIAcadMLeaderLeaderImpl(IAcadMLeaderLeader* ptr)
    : PyIAcadSubEntityImpl(ptr)
{
}

IAcadMLeaderLeader* PyIAcadMLeaderLeaderImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadMLeaderLeader*>(m_pimpl.GetInterfacePtr());
}
#endif

//------------------------------------------------------------------------------------
//PyIAcadSubEntSolidFaceImpl
#ifndef _GRXTARGET
PyIAcadSubEntSolidFaceImpl::PyIAcadSubEntSolidFaceImpl(IAcadSubEntSolidFace* ptr)
    : PyIAcadSubEntityImpl(ptr)
{
}

IAcadSubEntSolidFace* PyIAcadSubEntSolidFaceImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadSubEntSolidFace*>(m_pimpl.GetInterfacePtr());
}
#endif

//------------------------------------------------------------------------------------
//PyIAcadSubDMeshFaceImpl
#ifndef _GRXTARGET
#ifndef _BRXTARGET
PyIAcadSubDMeshFaceImpl::PyIAcadSubDMeshFaceImpl(IAcadSubDMeshFace* ptr)
    : PyIAcadSubEntityImpl(ptr)
{
}

IAcadSubDMeshFace* PyIAcadSubDMeshFaceImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadSubDMeshFace*>(m_pimpl.GetInterfacePtr());
}
#endif
#endif

//------------------------------------------------------------------------------------
//PyIAcadSubDMeshEdgeImpl
#ifndef _GRXTARGET
#ifndef _BRXTARGET
PyIAcadSubDMeshEdgeImpl::PyIAcadSubDMeshEdgeImpl(IAcadSubDMeshEdge* ptr)
    : PyIAcadSubEntityImpl(ptr)
{
}

IAcadSubDMeshEdge* PyIAcadSubDMeshEdgeImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadSubDMeshEdge*>(m_pimpl.GetInterfacePtr());
}
#endif
#endif

//------------------------------------------------------------------------------------
//PyIAcadSubDMeshVertexImpl
#ifndef _GRXTARGET
#ifndef _BRXTARGET
PyIAcadSubDMeshVertexImpl::PyIAcadSubDMeshVertexImpl(IAcadSubDMeshVertex* ptr)
    : PyIAcadSubEntityImpl(ptr)
{
}

IAcadSubDMeshVertex* PyIAcadSubDMeshVertexImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadSubDMeshVertex*>(m_pimpl.GetInterfacePtr());
}
#endif
#endif

//-----------------------------------------------------------------------------------
//PyIAcadEntityImpl
PyIAcadEntityImpl::PyIAcadEntityImpl(IAcadEntity* ptr)
    : PyIAcadObjectImpl(ptr)
{
}

void PyIAcadEntityImpl::TransformBy(const AcGeMatrix3d& xform)
{
    static SAFEARRAYBOUND bounds[2];
    bounds[0].cElements = 4;
    bounds[0].lLbound = 0;
    bounds[1].cElements = 4;
    bounds[1].lLbound = 0;

    long ind[2];
    CComSafeArray<double> sm;
    sm.Create(bounds, 2);
    {
        //0
        ind[0] = 0;
        ind[1] = 0;
        sm.MultiDimSetAt(ind, xform.entry[0][0]);
        ind[0] = 0;
        ind[1] = 1;
        sm.MultiDimSetAt(ind, xform.entry[0][1]);
        ind[0] = 0;
        ind[1] = 2;
        sm.MultiDimSetAt(ind, xform.entry[0][2]);
        ind[0] = 0;
        ind[1] = 3;
        sm.MultiDimSetAt(ind, xform.entry[0][3]);
        //1
        ind[0] = 1;
        ind[1] = 0;
        sm.MultiDimSetAt(ind, xform.entry[1][0]);
        ind[0] = 1;
        ind[1] = 1;
        sm.MultiDimSetAt(ind, xform.entry[1][1]);
        ind[0] = 1;
        ind[1] = 2;
        sm.MultiDimSetAt(ind, xform.entry[1][2]);
        ind[0] = 1;
        ind[1] = 3;
        sm.MultiDimSetAt(ind, xform.entry[1][3]);
        //2
        ind[0] = 2;
        ind[1] = 0;
        sm.MultiDimSetAt(ind, xform.entry[2][0]);
        ind[0] = 2;
        ind[1] = 1;
        sm.MultiDimSetAt(ind, xform.entry[2][1]);
        ind[0] = 2;
        ind[1] = 2;
        sm.MultiDimSetAt(ind, xform.entry[2][2]);
        ind[0] = 2;
        ind[1] = 3;
        sm.MultiDimSetAt(ind, xform.entry[2][3]);
        //3
        ind[0] = 3;
        ind[1] = 0;
        sm.MultiDimSetAt(ind, xform.entry[3][0]);
        ind[0] = 3;
        ind[1] = 1;
        sm.MultiDimSetAt(ind, xform.entry[3][1]);
        ind[0] = 3;
        ind[1] = 2;
        sm.MultiDimSetAt(ind, xform.entry[3][2]);
        ind[0] = 3;
        ind[1] = 3;
        sm.MultiDimSetAt(ind, xform.entry[3][3]);
    }
    VARIANT axform;
    VariantInit(&axform);
    axform.vt = VT_ARRAY | VT_R8;
    axform.parray = sm;
    PyThrowBadHr(impObj()->TransformBy(axform));
}

IAcadEntity* PyIAcadEntityImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadEntity*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadPViewportImpl
PyIAcadPViewportImpl::PyIAcadPViewportImpl(IAcadPViewport* ptr)
    : PyIAcadEntityImpl(ptr)
{
}

IAcadPViewport* PyIAcadPViewportImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadPViewport*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcad3DFaceImpl
PyIAcad3DFaceImpl::PyIAcad3DFaceImpl(IAcad3DFace* ptr)
    : PyIAcadEntityImpl(ptr)
{
}

AcGePoint3dArray PyIAcad3DFaceImpl::GetCoordinates() const
{
    _variant_t coords;
    PyThrowBadHr(impObj()->get_Coordinates(&coords.GetVARIANT()));
    unsigned long pcElem = 0;
    std::array<double, 12> doubles;
    PyThrowBadHr(VariantToDoubleArray(coords, doubles.data(), doubles.size(), &pcElem));
    AcGePoint3dArray pnts;
    pnts.append(AcGePoint3d{ doubles.at(0),doubles.at(1),doubles.at(2) });
    pnts.append(AcGePoint3d{ doubles.at(3),doubles.at(4),doubles.at(5) });
    pnts.append(AcGePoint3d{ doubles.at(6),doubles.at(7),doubles.at(8) });
    pnts.append(AcGePoint3d{ doubles.at(9),doubles.at(10),doubles.at(11) });
    return pnts;
}

void PyIAcad3DFaceImpl::SetCoordinates(const AcGePoint3d& p1, const AcGePoint3d& p2, const AcGePoint3d& p3, const AcGePoint3d& p4)
{
    constexpr size_t sz = sizeof(double) * 3;
    std::array<double, 12> doubles;
    memcpy(doubles.data() + 0, asDblArray(p1), sz);
    memcpy(doubles.data() + 3, asDblArray(p2), sz);
    memcpy(doubles.data() + 6, asDblArray(p3), sz);
    memcpy(doubles.data() + 9, asDblArray(p4), sz);
    _variant_t coords;
    PyThrowBadHr(InitVariantFromDoubleArray(doubles.data(), doubles.size(), &coords.GetVARIANT()));
    PyThrowBadHr(impObj()->put_Coordinates(coords));
}

bool PyIAcad3DFaceImpl::GetInvisibleEdge(int index) const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->GetInvisibleEdge(index ,&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcad3DFaceImpl::SetInvisibleEdge(int index, bool flag)
{
    PyThrowBadHr(impObj()->SetInvisibleEdge(index,flag ? VARIANT_TRUE : VARIANT_FALSE));
}

AcGePoint3d PyIAcad3DFaceImpl::GetCoordinate(int index) const
{
    AcGePoint3d val;
    _variant_t coord;
    PyThrowBadHr(impObj()->get_Coordinate(index, &coord.GetVARIANT()));
    PyThrowBadHr(VariantToAcGePoint3d(coord, val));
    return val;
}

void PyIAcad3DFaceImpl::SetCoordinate(int index, const AcGePoint3d& val)
{
    variant_t coord;
    PyThrowBadHr(AcGePoint3dToVariant(coord.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_Coordinate(index, coord));
}

IAcad3DFace* PyIAcad3DFaceImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcad3DFace*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadPolygonMeshImpl
PyIAcadPolygonMeshImpl::PyIAcadPolygonMeshImpl(IAcadPolygonMesh* ptr)
    : PyIAcadEntityImpl(ptr)
{
}

IAcadPolygonMesh* PyIAcadPolygonMeshImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadPolygonMesh*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcad3DPolylineImpl
PyIAcad3DPolylineImpl::PyIAcad3DPolylineImpl(IAcad3DPolyline* ptr)
    : PyIAcadEntityImpl(ptr)
{
}

IAcad3DPolyline* PyIAcad3DPolylineImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcad3DPolyline*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadArcImpl
PyIAcadArcImpl::PyIAcadArcImpl(IAcadArc* ptr)
    : PyIAcadEntityImpl(ptr)
{
}

IAcadArc* PyIAcadArcImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadArc*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadAttributeImpl
PyIAcadAttributeImpl::PyIAcadAttributeImpl(IAcadAttribute* ptr)
    : PyIAcadEntityImpl(ptr)
{
}

IAcadAttribute* PyIAcadAttributeImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadAttribute*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadRegionImpl
PyIAcadRegionImpl::PyIAcadRegionImpl(IAcadRegion* ptr)
    : PyIAcadEntityImpl(ptr)
{
}

IAcadRegion* PyIAcadRegionImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadRegion*>(m_pimpl.GetInterfacePtr());
}
//------------------------------------------------------------------------------------
//PyIAcad3DSolidImpl
PyIAcad3DSolidImpl::PyIAcad3DSolidImpl(IAcad3DSolid* ptr)
    : PyIAcadEntityImpl(ptr)
{
}

IAcad3DSolid* PyIAcad3DSolidImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcad3DSolid*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadCircleImpl
PyIAcadCircleImpl::PyIAcadCircleImpl(IAcadCircle* ptr)
    : PyIAcadEntityImpl(ptr)
{
}

IAcadCircle* PyIAcadCircleImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadCircle*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadDimensionImpl
PyIAcadDimensionImpl::PyIAcadDimensionImpl(IAcadDimension* ptr)
    : PyIAcadEntityImpl(ptr)
{
}

IAcadDimension* PyIAcadDimensionImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadDimension*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadDimensionImpl
PyIAcadDimAlignedImpl::PyIAcadDimAlignedImpl(IAcadDimAligned* ptr)
    : PyIAcadDimensionImpl(ptr)
{
}

IAcadDimAligned* PyIAcadDimAlignedImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadDimAligned*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadDimAngularImpl
PyIAcadDimAngularImpl::PyIAcadDimAngularImpl(IAcadDimAngular* ptr)
    : PyIAcadDimensionImpl(ptr)
{
}

IAcadDimAngular* PyIAcadDimAngularImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadDimAngular*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadDimDiametricImpl
PyIAcadDimDiametricImpl::PyIAcadDimDiametricImpl(IAcadDimDiametric* ptr)
    : PyIAcadDimensionImpl(ptr)
{
}

IAcadDimDiametric* PyIAcadDimDiametricImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadDimDiametric*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadDimRotatedImpl
PyIAcadDimRotatedImpl::PyIAcadDimRotatedImpl(IAcadDimRotated* ptr)
    : PyIAcadDimensionImpl(ptr)
{
}


IAcadDimRotated* PyIAcadDimRotatedImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadDimRotated*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadDimOrdinateImpl
PyIAcadDimOrdinateImpl::PyIAcadDimOrdinateImpl(IAcadDimOrdinate* ptr)
    : PyIAcadDimensionImpl(ptr)
{
}

IAcadDimOrdinate* PyIAcadDimOrdinateImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadDimOrdinate*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadDimRadialImpl
PyIAcadDimRadialImpl::PyIAcadDimRadialImpl(IAcadDimRadial* ptr)
    : PyIAcadDimensionImpl(ptr)
{
}

IAcadDimRadial* PyIAcadDimRadialImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadDimRadial*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadDim3PointAngularImpl
PyIAcadDim3PointAngularImpl::PyIAcadDim3PointAngularImpl(IAcadDim3PointAngular* ptr)
    : PyIAcadDimensionImpl(ptr)
{
}

IAcadDim3PointAngular* PyIAcadDim3PointAngularImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadDim3PointAngular*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadDimArcLengthImpl
PyIAcadDimArcLengthImpl::PyIAcadDimArcLengthImpl(IAcadDimArcLength* ptr)
    : PyIAcadDimensionImpl(ptr)
{
}

IAcadDimArcLength* PyIAcadDimArcLengthImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadDimArcLength*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadDimRadialLargeImpl
PyIAcadDimRadialLargeImpl::PyIAcadDimRadialLargeImpl(IAcadDimRadialLarge* ptr)
    : PyIAcadDimensionImpl(ptr)
{
}

IAcadDimRadialLarge* PyIAcadDimRadialLargeImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadDimRadialLarge*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadEllipseImpl
PyIAcadEllipseImpl::PyIAcadEllipseImpl(IAcadEllipse* ptr)
    : PyIAcadEntityImpl(ptr)
{
}

IAcadEllipse* PyIAcadEllipseImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadEllipse*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadLeaderImpl
PyIAcadLeaderImpl::PyIAcadLeaderImpl(IAcadLeader* ptr)
    : PyIAcadEntityImpl(ptr)
{
}

IAcadLeader* PyIAcadLeaderImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadLeader*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadMTextImpl
PyIAcadMTextImpl::PyIAcadMTextImpl(IAcadMText* ptr)
    : PyIAcadEntityImpl(ptr)
{
}

IAcadMText* PyIAcadMTextImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadMText*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadPointImpl
PyIAcadPointImpl::PyIAcadPointImpl(IAcadPoint* ptr)
    : PyIAcadEntityImpl(ptr)
{
}

IAcadPoint* PyIAcadPointImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadPoint*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadLWPolylineImpl
PyIAcadLWPolylineImpl::PyIAcadLWPolylineImpl(IAcadLWPolyline* ptr)
    : PyIAcadEntityImpl(ptr)
{
}

IAcadLWPolyline* PyIAcadLWPolylineImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadLWPolyline*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadPolylineImpl
PyIAcadPolylineImpl::PyIAcadPolylineImpl(IAcadPolyline* ptr)
    : PyIAcadEntityImpl(ptr)
{
}

IAcadPolyline* PyIAcadPolylineImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadPolyline*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadRayImpl
PyIAcadRayImpl::PyIAcadRayImpl(IAcadRay* ptr)
    : PyIAcadEntityImpl(ptr)
{
}

IAcadRay* PyIAcadRayImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadRay*>(m_pimpl.GetInterfacePtr());
}


//------------------------------------------------------------------------------------
//PyIAcadShapeImpl
PyIAcadShapeImpl::PyIAcadShapeImpl(IAcadShape* ptr)
    : PyIAcadEntityImpl(ptr)
{
}

IAcadShape* PyIAcadShapeImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadShape*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadSolidImpl
PyIAcadSolidImpl::PyIAcadSolidImpl(IAcadSolid* ptr)
    : PyIAcadEntityImpl(ptr)
{
}

IAcadSolid* PyIAcadSolidImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadSolid*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadSplineImpl
PyIAcadSplineImpl::PyIAcadSplineImpl(IAcadSpline* ptr)
    : PyIAcadEntityImpl(ptr)
{
}


IAcadSpline* PyIAcadSplineImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadSpline*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadTextImpl
PyIAcadTextImpl::PyIAcadTextImpl(IAcadText* ptr)
    : PyIAcadEntityImpl(ptr)
{
}

IAcadText* PyIAcadTextImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadText*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadToleranceImpl
PyIAcadToleranceImpl::PyIAcadToleranceImpl(IAcadTolerance* ptr)
    : PyIAcadEntityImpl(ptr)
{
}

IAcadTolerance* PyIAcadToleranceImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadTolerance*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadTraceImpl
PyIAcadTraceImpl::PyIAcadTraceImpl(IAcadTrace* ptr)
    : PyIAcadEntityImpl(ptr)
{
}

IAcadTrace* PyIAcadTraceImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadTrace*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadXlineImpl
PyIAcadXlineImpl::PyIAcadXlineImpl(IAcadXline* ptr)
    : PyIAcadEntityImpl(ptr)
{
}

IAcadXline* PyIAcadXlineImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadXline*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadBlockReferenceImpl
PyIAcadBlockReferenceImpl::PyIAcadBlockReferenceImpl(IAcadBlockReference* ptr)
    : PyIAcadEntityImpl(ptr)
{
}

IAcadBlockReference* PyIAcadBlockReferenceImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadBlockReference*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadHatchImpl
PyIAcadHatchImpl::PyIAcadHatchImpl(IAcadHatch* ptr)
    : PyIAcadEntityImpl(ptr)
{
}

IAcadHatch* PyIAcadHatchImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadHatch*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadRasterImageImpl
PyIAcadRasterImageImpl::PyIAcadRasterImageImpl(IAcadRasterImage* ptr)
    : PyIAcadEntityImpl(ptr)
{
}

IAcadRasterImage* PyIAcadRasterImageImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadRasterImage*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadLineImpl
PyIAcadLineImpl::PyIAcadLineImpl(IAcadLine* ptr)
    : PyIAcadEntityImpl(ptr)
{
}

IAcadLine* PyIAcadLineImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadLine*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadMInsertBlockImpl
PyIAcadMInsertBlockImpl::PyIAcadMInsertBlockImpl(IAcadMInsertBlock* ptr)
    : PyIAcadBlockReferenceImpl(ptr)
{
}

IAcadMInsertBlock* PyIAcadMInsertBlockImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadMInsertBlock*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadPolyfaceMeshImpl
PyIAcadPolyfaceMeshImpl::PyIAcadPolyfaceMeshImpl(IAcadPolyfaceMesh* ptr)
    : PyIAcadEntityImpl(ptr)
{
}

IAcadPolyfaceMesh* PyIAcadPolyfaceMeshImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadPolyfaceMesh*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadMLineImpl
PyIAcadMLineImpl::PyIAcadMLineImpl(IAcadMLine* ptr)
    : PyIAcadEntityImpl(ptr)
{
}

IAcadMLine* PyIAcadMLineImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadMLine*>(m_pimpl.GetInterfacePtr());
}
