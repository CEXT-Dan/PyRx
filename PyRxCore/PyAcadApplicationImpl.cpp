#include "stdafx.h"
#include "PyAcadApplicationImpl.h"

//------------------------------------------------------------------------------------
//PyIAcadBlockImpl
PyIAcadBlockImpl::PyIAcadBlockImpl(IAcadBlock* ptr)
    : PyIAcadObjectImpl(ptr)
{
}

PyIAcadEntityPtr PyIAcadBlockImpl::GetItem(long ind) const
{
    _variant_t vtind{ ind };
    IAcadEntity* ptr = nullptr;
    PyThrowBadHr(impObj()->Item(vtind, &ptr));
    return std::make_unique<PyIAcadEntityImpl>(ptr);
}

long PyIAcadBlockImpl::GetCount() const
{
    long ind = 0;
    PyThrowBadHr(impObj()->get_Count(&ind));
    return ind;
}

PyIAcadEntityPtrArray PyIAcadBlockImpl::GetIter() const
{
    const auto len = GetCount();
    PyIAcadEntityPtrArray vec;
    vec.reserve(len);

    IUnknownPtr pUnk;
    PyThrowBadHr(impObj()->get__NewEnum((IUnknown**)&pUnk));

    IEnumVARIANTPtr vtenum;
    PyThrowBadHr(pUnk->QueryInterface(IID_IEnumVARIANT, (void**)&vtenum));

    for (unsigned long idx = 0, iout = 0; idx < len; idx++)
    {
        _variant_t item;
        vtenum->Next(1, &item.GetVARIANT(), &iout);
        vec.emplace_back(std::make_shared<PyIAcadEntityImpl>((IAcadEntity*)(IDispatch*)item));
    }
    return vec;
}

CString PyIAcadBlockImpl::GetName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Name(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadBlockImpl::SetName(const CString& val) const
{
    _bstr_t bstrVal{ val };
    PyThrowBadHr(impObj()->put_Name(bstrVal));
}

AcGePoint3d PyIAcadBlockImpl::GetOrigin() const
{
    AcGePoint3d pnt;
    _variant_t vtval;
    PyThrowBadHr(impObj()->get_Origin(&vtval.GetVARIANT()));
    PyThrowBadHr(VariantToAcGePoint3d(vtval, pnt));
    return pnt;
}

void PyIAcadBlockImpl::SetOrigin(const AcGePoint3d& val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGePoint3dToVariant(vtval.GetVARIANT(), val));
}

PyIAcadObjectPtr PyIAcadBlockImpl::AddCustomObject(const CString& val)
{
    _bstr_t bstrVal{ val };
    IDispatch* pDisp = nullptr;
    PyThrowBadHr(impObj()->AddCustomObject(bstrVal, &pDisp));
    return std::make_unique<PyIAcadObjectImpl>((IAcadObject*)pDisp);
}

PyIAcad3DFacePtr PyIAcadBlockImpl::Add3DFace(const AcGePoint3d& p1, const AcGePoint3d& p2, const AcGePoint3d& p3, const AcGePoint3d& p4)
{
    _variant_t vtp1;
    _variant_t vtp2;
    _variant_t vtp3;
    _variant_t vtp4;
    IAcad3DFace* pVal = nullptr;
    PyThrowBadHr(AcGePoint3dToVariant(vtp1.GetVARIANT(), p1));
    PyThrowBadHr(AcGePoint3dToVariant(vtp2.GetVARIANT(), p2));
    PyThrowBadHr(AcGePoint3dToVariant(vtp3.GetVARIANT(), p3));
    PyThrowBadHr(AcGePoint3dToVariant(vtp4.GetVARIANT(), p4));
    PyThrowBadHr(impObj()->Add3DFace(vtp1, vtp2, vtp3, vtp4, &pVal));
    return std::make_unique<PyIAcad3DFaceImpl>(pVal);
}

PyIAcadPolygonMeshPtr PyIAcadBlockImpl::Add3DMesh(int M, int N, const std::vector<AcGePoint3d>& points)
{
    _variant_t vtcoords;
    std::vector<double> doubles;
    doubles.reserve(points.size() * 3);
    for (const auto& point : points)
    {
        doubles.push_back(point.x);
        doubles.push_back(point.y);
        doubles.push_back(point.z);
    }
    PyThrowBadHr(InitVariantFromDoubleArray(doubles.data(), doubles.size(), &vtcoords.GetVARIANT()));
    IAcadPolygonMesh* pMesh = nullptr;
    PyThrowBadHr(impObj()->Add3DMesh(M, N, vtcoords, &pMesh));
    return std::make_unique<PyIAcadPolygonMeshImpl>(pMesh);
}

PyIAcad3DPolylinePtr PyIAcadBlockImpl::Add3DPoly(const std::vector<AcGePoint3d>& points)
{
    _variant_t vtcoords;
    std::vector<double> doubles;
    doubles.reserve(points.size() * 3);
    for (const auto& point : points)
    {
        doubles.push_back(point.x);
        doubles.push_back(point.y);
        doubles.push_back(point.z);
    }
    PyThrowBadHr(InitVariantFromDoubleArray(doubles.data(), doubles.size(), &vtcoords.GetVARIANT()));
    IAcad3DPolyline* pEnt = nullptr;
    PyThrowBadHr(impObj()->Add3DPoly(vtcoords, &pEnt));
    return std::make_unique<PyIAcad3DPolylineImpl>(pEnt);
}

PyIAcadArcPtr PyIAcadBlockImpl::AddArc(const AcGePoint3d& center, double radius, double startAngle, double endAngle)
{
    _variant_t vtcenter;
    PyThrowBadHr(AcGePoint3dToVariant(vtcenter.GetVARIANT(), center));
    IAcadArc* pEnt = nullptr;
    PyThrowBadHr(impObj()->AddArc(vtcenter, radius, startAngle, endAngle, &pEnt));
    return std::make_unique<PyIAcadArcImpl>(pEnt);
}

PyIAcadAttributePtr PyIAcadBlockImpl::AddAttribute(double Height, PyAcAttributeMode mode, const CString& prompt, const AcGePoint3d& insertionPoint, const CString& tag, const CString& value)
{
    _bstr_t bstrprompt{ prompt };
    _variant_t vtinsertionPoint;
    PyThrowBadHr(AcGePoint3dToVariant(vtinsertionPoint.GetVARIANT(), insertionPoint));
    _bstr_t bstrtag{ tag };
    _bstr_t bstrvalue{ value };
    IAcadAttribute* pEnt = nullptr;
    PyThrowBadHr(impObj()->AddAttribute(Height, (AcAttributeMode)mode, bstrprompt, vtinsertionPoint, bstrtag, bstrvalue, &pEnt));
    return std::make_unique<PyIAcadAttributeImpl>(pEnt);
}

PyIAcad3DSolidPtr PyIAcadBlockImpl::AddBox(const AcGePoint3d& origin, double length, double width, double height)
{
    _variant_t vtorigin;
    IAcad3DSolid* pEnt = nullptr;
    PyThrowBadHr(AcGePoint3dToVariant(vtorigin.GetVARIANT(), origin));
    PyThrowBadHr(impObj()->AddBox(vtorigin, length, width, height, &pEnt));
    return std::make_unique<PyIAcad3DSolidImpl>(pEnt);
}

PyIAcadCirclePtr PyIAcadBlockImpl::AddCircle(const AcGePoint3d& center, double radius)
{
    _variant_t vtcenter;
    IAcadCircle* pEnt = nullptr;
    PyThrowBadHr(AcGePoint3dToVariant(vtcenter.GetVARIANT(), center));
    PyThrowBadHr(impObj()->AddCircle(vtcenter, radius, &pEnt));
    return  std::make_unique<PyIAcadCircleImpl>(pEnt);
}

PyIAcad3DSolidPtr PyIAcadBlockImpl::AddCone(const AcGePoint3d& center, double baseRadius, double height)
{
    _variant_t vtcenter;
    IAcad3DSolid* pEnt = nullptr;
    PyThrowBadHr(AcGePoint3dToVariant(vtcenter.GetVARIANT(), center));
    PyThrowBadHr(impObj()->AddCone(vtcenter, baseRadius, height, &pEnt));
    return std::make_unique<PyIAcad3DSolidImpl>(pEnt);
}

PyIAcad3DSolidPtr PyIAcadBlockImpl::AddCylinder(const AcGePoint3d& center, double radius, double height)
{
    _variant_t vtcenter;
    IAcad3DSolid* pEnt = nullptr;
    PyThrowBadHr(AcGePoint3dToVariant(vtcenter.GetVARIANT(), center));
    PyThrowBadHr(impObj()->AddCylinder(vtcenter, radius, height, &pEnt));
    return std::make_unique<PyIAcad3DSolidImpl>(pEnt);
}

PyIAcadDimAlignedPtr PyIAcadBlockImpl::AddDimAligned(const AcGePoint3d& extLine1Point, const AcGePoint3d& extLine2Point, const AcGePoint3d& textPosition)
{
    _variant_t vtextLine1Point;
    _variant_t vtextLine2Point;
    _variant_t vttextPosition;
    IAcadDimAligned* pEnt = nullptr;
    PyThrowBadHr(AcGePoint3dToVariant(vtextLine1Point.GetVARIANT(), extLine1Point));
    PyThrowBadHr(AcGePoint3dToVariant(vtextLine2Point.GetVARIANT(), extLine2Point));
    PyThrowBadHr(AcGePoint3dToVariant(vttextPosition.GetVARIANT(), textPosition));
    PyThrowBadHr(impObj()->AddDimAligned(vtextLine1Point, vtextLine2Point, vttextPosition, &pEnt));
    return std::make_unique<PyIAcadDimAlignedImpl>(pEnt);
}

PyIAcadDimAngularPtr PyIAcadBlockImpl::AddDimAngular(const AcGePoint3d& angleVertex, const AcGePoint3d& firstEndPoint, const AcGePoint3d& secondEndPoint, const AcGePoint3d& textPosition)
{
    _variant_t vtangleVertex;
    _variant_t vtfirstEndPoint;
    _variant_t vtsecondEndPoint;
    _variant_t vttextPosition;
    IAcadDimAngular* pEnt = nullptr;
    PyThrowBadHr(AcGePoint3dToVariant(vtangleVertex.GetVARIANT(), angleVertex));
    PyThrowBadHr(AcGePoint3dToVariant(vtfirstEndPoint.GetVARIANT(), firstEndPoint));
    PyThrowBadHr(AcGePoint3dToVariant(vtsecondEndPoint.GetVARIANT(), secondEndPoint));
    PyThrowBadHr(AcGePoint3dToVariant(vttextPosition.GetVARIANT(), textPosition));
    PyThrowBadHr(impObj()->AddDimAngular(vtangleVertex, vtfirstEndPoint, vtsecondEndPoint, vttextPosition, &pEnt));
    return std::make_unique<PyIAcadDimAngularImpl>(pEnt);
}

PyIAcadDimDiametricPtr PyIAcadBlockImpl::AddDimDiametric(const AcGePoint3d& chordPoint, const AcGePoint3d& farChordPoint, double leaderLength)
{
    _variant_t vtchordPoint;
    _variant_t vtfarChordPoint;
    IAcadDimDiametric* pEnt = nullptr;
    PyThrowBadHr(AcGePoint3dToVariant(vtchordPoint.GetVARIANT(), chordPoint));
    PyThrowBadHr(AcGePoint3dToVariant(vtfarChordPoint.GetVARIANT(), farChordPoint));
    PyThrowBadHr(impObj()->AddDimDiametric(vtchordPoint, vtfarChordPoint, leaderLength, &pEnt));
    return std::make_unique<PyIAcadDimDiametricImpl>(pEnt);
}

PyIAcadDimRotatedPtr PyIAcadBlockImpl::AddDimRotated(const AcGePoint3d& extLine1Point, const AcGePoint3d& extLine2Point, const AcGePoint3d& dimLineLocation, double rotationAngle)
{
    _variant_t vtextLine1Point;
    _variant_t vtextLine2Point;
    _variant_t vtdimLineLocation;
    IAcadDimRotated* pEnt = nullptr;
    PyThrowBadHr(AcGePoint3dToVariant(vtextLine1Point.GetVARIANT(), extLine1Point));
    PyThrowBadHr(AcGePoint3dToVariant(vtextLine2Point.GetVARIANT(), extLine2Point));
    PyThrowBadHr(AcGePoint3dToVariant(vtdimLineLocation.GetVARIANT(), dimLineLocation));
    PyThrowBadHr(impObj()->AddDimRotated(vtextLine1Point, vtextLine2Point, vtdimLineLocation, rotationAngle, &pEnt));
    return std::make_unique<PyIAcadDimRotatedImpl>(pEnt);
}

PyIAcadDimOrdinatePtr PyIAcadBlockImpl::AddDimOrdinate(const AcGePoint3d& definitionPoint, const AcGePoint3d& leaderEndPoint, int UseXAxis)
{
    _variant_t vtdefinitionPoint;
    _variant_t vtleaderEndPoint;
    IAcadDimOrdinate* pEnt = nullptr;
    PyThrowBadHr(AcGePoint3dToVariant(vtdefinitionPoint.GetVARIANT(), definitionPoint));
    PyThrowBadHr(AcGePoint3dToVariant(vtleaderEndPoint.GetVARIANT(), leaderEndPoint));
    PyThrowBadHr(impObj()->AddDimOrdinate(vtdefinitionPoint, vtleaderEndPoint, UseXAxis, &pEnt));
    return std::make_unique<PyIAcadDimOrdinateImpl>(pEnt);

}

PyIAcadDimRadialPtr PyIAcadBlockImpl::AddDimRadial(const AcGePoint3d& center, const AcGePoint3d& chordPoint, double leaderLength)
{
    _variant_t vtcenter;
    _variant_t vtchordPoint;
    IAcadDimRadial* pEnt = nullptr;
    PyThrowBadHr(AcGePoint3dToVariant(vtcenter.GetVARIANT(), center));
    PyThrowBadHr(AcGePoint3dToVariant(vtchordPoint.GetVARIANT(), chordPoint));
    PyThrowBadHr(impObj()->AddDimRadial(vtcenter, vtchordPoint, leaderLength, &pEnt));
    return std::make_unique<PyIAcadDimRadialImpl>(pEnt);
}

PyIAcadDimRadialLargePtr PyIAcadBlockImpl::AddDimRadialLarge(const AcGePoint3d& center, const AcGePoint3d& chordPoint, const AcGePoint3d& overrideCenter, const AcGePoint3d& jogPoint, double jogAngle)
{
    _variant_t vtcenter;
    _variant_t vtchordPoint;
    _variant_t vtoverrideCenter;
    _variant_t vtjogPoint;
    IAcadDimRadialLarge* pEnt = nullptr;
    PyThrowBadHr(AcGePoint3dToVariant(vtcenter.GetVARIANT(), center));
    PyThrowBadHr(AcGePoint3dToVariant(vtchordPoint.GetVARIANT(), chordPoint));
    PyThrowBadHr(AcGePoint3dToVariant(vtoverrideCenter.GetVARIANT(), overrideCenter));
    PyThrowBadHr(AcGePoint3dToVariant(vtjogPoint.GetVARIANT(), jogPoint));
    PyThrowBadHr(impObj()->AddDimRadialLarge(vtcenter, vtchordPoint, vtoverrideCenter, vtjogPoint, jogAngle, &pEnt));
    return std::make_unique<PyIAcadDimRadialLargeImpl>(pEnt);
}

PyIAcadDim3PointAngularPtr PyIAcadBlockImpl::AddDim3PointAngular(const AcGePoint3d& angleVertex, const AcGePoint3d& firstEndPoint, const AcGePoint3d& secondEndPoint, const AcGePoint3d& textPosition)
{
    _variant_t vtangleVertex;
    _variant_t vtfirstEndPoint;
    _variant_t vtsecondEndPoint;
    _variant_t vttextPosition;
    IAcadDim3PointAngular* pEnt = nullptr;
    PyThrowBadHr(AcGePoint3dToVariant(vtangleVertex.GetVARIANT(), angleVertex));
    PyThrowBadHr(AcGePoint3dToVariant(vtfirstEndPoint.GetVARIANT(), firstEndPoint));
    PyThrowBadHr(AcGePoint3dToVariant(vtsecondEndPoint.GetVARIANT(), secondEndPoint));
    PyThrowBadHr(AcGePoint3dToVariant(vttextPosition.GetVARIANT(), textPosition));
    PyThrowBadHr(impObj()->AddDim3PointAngular(vtangleVertex, vtfirstEndPoint, vtsecondEndPoint, vttextPosition, &pEnt));
    return std::make_unique<PyIAcadDim3PointAngularImpl>(pEnt);
}

PyIAcadDimArcLengthPtr PyIAcadBlockImpl::AddDimArc(const AcGePoint3d& arcCenter, const AcGePoint3d& firstEndPoint, const AcGePoint3d& secondEndPoint, const AcGePoint3d& arcPoint)
{
    _variant_t vtarcCenter;
    _variant_t vtfirstEndPoint;
    _variant_t vtsecondEndPoint;
    _variant_t vtarcPoint;
    IAcadDimArcLength* pEnt = nullptr;
    PyThrowBadHr(AcGePoint3dToVariant(vtarcCenter.GetVARIANT(), arcCenter));
    PyThrowBadHr(AcGePoint3dToVariant(vtfirstEndPoint.GetVARIANT(), firstEndPoint));
    PyThrowBadHr(AcGePoint3dToVariant(vtsecondEndPoint.GetVARIANT(), secondEndPoint));
    PyThrowBadHr(AcGePoint3dToVariant(vtarcPoint.GetVARIANT(), arcPoint));
    PyThrowBadHr(impObj()->AddDimArc(vtarcCenter, vtfirstEndPoint, vtsecondEndPoint, vtarcPoint, &pEnt));
    return std::make_unique<PyIAcadDimArcLengthImpl>(pEnt);
}

PyIAcadEllipsePtr PyIAcadBlockImpl::AddEllipse(const AcGePoint3d& center, const AcGeVector3d& majorAxis, double radiusRatio)
{
    _variant_t vtcenter;
    _variant_t vtmajorAxis;
    IAcadEllipse* pEnt = nullptr;
    PyThrowBadHr(AcGePoint3dToVariant(vtcenter.GetVARIANT(), center));
    PyThrowBadHr(AcGeVector3dToVariant(vtmajorAxis.GetVARIANT(), majorAxis));
    PyThrowBadHr(impObj()->AddEllipse(vtcenter, vtmajorAxis, radiusRatio, &pEnt));
    return std::make_unique<PyIAcadEllipseImpl>(pEnt);
}

PyIAcad3DSolidPtr PyIAcadBlockImpl::AddEllipticalCone(const AcGePoint3d& center, double majorRadius, double minorRadius, double height)
{
    _variant_t vtcenter;
    IAcad3DSolid* pEnt = nullptr;
    PyThrowBadHr(AcGePoint3dToVariant(vtcenter.GetVARIANT(), center));
    PyThrowBadHr(impObj()->AddEllipticalCone(vtcenter, majorRadius, minorRadius, height, &pEnt));
    return std::make_unique<PyIAcad3DSolidImpl>(pEnt);
}

PyIAcad3DSolidPtr PyIAcadBlockImpl::AddEllipticalCylinder(const AcGePoint3d& center, double majorRadius, double minorRadius, double height)
{
    _variant_t vtcenter;
    IAcad3DSolid* pEnt = nullptr;
    PyThrowBadHr(AcGePoint3dToVariant(vtcenter.GetVARIANT(), center));
    PyThrowBadHr(impObj()->AddEllipticalCylinder(vtcenter, majorRadius, minorRadius, height, &pEnt));
    return std::make_unique<PyIAcad3DSolidImpl>(pEnt);
}

PyIAcad3DSolidPtr PyIAcadBlockImpl::AddExtrudedSolid(const PyIAcadRegionImpl& impl, double height, double taperAngle)
{
    IAcad3DSolid* pEnt = nullptr;
    PyThrowBadHr(impObj()->AddExtrudedSolid(impl.impObj(), height, height, &pEnt));
    return std::make_unique<PyIAcad3DSolidImpl>(pEnt);
}

PyIAcad3DSolidPtr PyIAcadBlockImpl::AddExtrudedSolidAlongPath(const PyIAcadRegionImpl& regionImpl, const PyIAcadEntityImpl& entityImpl)
{
    IAcad3DSolid* pEnt = nullptr;
    PyThrowBadHr(impObj()->AddExtrudedSolidAlongPath(regionImpl.impObj(), entityImpl.impObj(), &pEnt));
    return std::make_unique<PyIAcad3DSolidImpl>(pEnt);
}

PyIAcadLeaderPtr PyIAcadBlockImpl::AddLeader(const std::vector<AcGePoint3d>& points, const PyIAcadEntityImpl& annotation, PyAcLeaderType lt)
{
    _variant_t vtcoords;
    IAcadLeader* pEnt = nullptr;
    PyThrowBadHr(AcGePoint3dsToVariant(vtcoords.GetVARIANT(),points));
    PyThrowBadHr(impObj()->AddLeader(vtcoords, annotation.impObj(), (AcLeaderType)lt, &pEnt));
    return std::make_unique<PyIAcadLeaderImpl>(pEnt);
}

PyIAcadMTextPtr PyIAcadBlockImpl::AddMText(const AcGePoint3d& insertionPoint, double width, const CString& text)
{
    _bstr_t bstrVal{ text };
    _variant_t vtinsertionPoint;
    IAcadMText* pEnt = nullptr;
    PyThrowBadHr(AcGePoint3dToVariant(vtinsertionPoint.GetVARIANT(), insertionPoint));
    PyThrowBadHr(impObj()->AddMText(vtinsertionPoint, width, bstrVal, &pEnt));
    return std::make_unique<PyIAcadMTextImpl>(pEnt);
}

PyIAcadPointPtr PyIAcadBlockImpl::AddPoint(const AcGePoint3d& point)
{
    _variant_t vtpoint;
    IAcadPoint* pEnt = nullptr;
    PyThrowBadHr(AcGePoint3dToVariant(vtpoint.GetVARIANT(), point));
    PyThrowBadHr(impObj()->AddPoint(vtpoint,&pEnt));
    return std::make_unique<PyIAcadPointImpl>(pEnt);
}

PyIAcadLWPolylinePtr PyIAcadBlockImpl::AddLightWeightPolyline(const std::vector<AcGePoint2d>& points)
{
    _variant_t vtcoords;
    IAcadLWPolyline* pEnt = nullptr;
    PyThrowBadHr(AcGePoint2dsToVariant(vtcoords.GetVARIANT(), points));
    PyThrowBadHr(impObj()->AddLightWeightPolyline(vtcoords, &pEnt));
    return std::make_unique<PyIAcadLWPolylineImpl>(pEnt);
}

PyIAcadPolylinePtr PyIAcadBlockImpl::AddPolyline(const std::vector<AcGePoint3d>& points)
{
    _variant_t vtcoords;
    IAcadPolyline* pEnt = nullptr;
    PyThrowBadHr(AcGePoint3dsToVariant(vtcoords.GetVARIANT(), points));
    PyThrowBadHr(impObj()->AddPolyline(vtcoords, &pEnt));
    return std::make_unique<PyIAcadPolylineImpl>(pEnt);
}

PyIAcadRayPtr PyIAcadBlockImpl::AddRay(const AcGePoint3d& p1, const AcGePoint3d& p2)
{
    _variant_t vtp1;
    _variant_t vtp2;
    IAcadRay* pEnt = nullptr;
    PyThrowBadHr(AcGePoint3dToVariant(vtp1.GetVARIANT(), p1));
    PyThrowBadHr(AcGePoint3dToVariant(vtp2.GetVARIANT(), p2));
    PyThrowBadHr(impObj()->AddRay(vtp1, vtp2, &pEnt));
    return std::make_unique<PyIAcadRayImpl>(pEnt);
}

PyIAcadRegionPtrArray PyIAcadBlockImpl::AddRegion(const std::vector<PyIAcadEntityImpl>& curves)
{
    _variant_t vtregions;
    CComSafeArray<IDispatch*> safeVariantArray(curves.size());
    for (size_t idx = 0; idx < curves.size(); idx++)
        safeVariantArray[int(idx)] = (IDispatch*)(IAcadEntity*)curves[idx].impObj();
    VARIANT icurves;
    VariantInit(&icurves);
    icurves.vt = VT_ARRAY | VT_DISPATCH;
    icurves.parray = safeVariantArray;
    PyThrowBadHr(impObj()->AddRegion(icurves, &vtregions.GetVARIANT()));
    PyIAcadRegionPtrArray vec;
#if defined(_BRXTARGET250)
    if (vtregions.vt == (VT_ARRAY | VT_VARIANT) && vtregions.parray != nullptr)
    {
        CComSafeArray<VARIANT> sa(vtregions.parray);
        auto regionsLen = sa.GetCount();
        for (int idx = 0; idx < regionsLen; idx++)
        {
            const VARIANT& item = sa[idx];
            vec.emplace_back(std::make_shared<PyIAcadRegionImpl>((IAcadRegion*)item.pdispVal));
        }
    }
#else
    if (vtregions.vt == (VT_ARRAY | VT_DISPATCH) && vtregions.parray != nullptr)
    {
        CComSafeArray<IDispatch*> sa(vtregions.parray);
        auto regionsLen = sa.GetCount();
        for (int idx = 0; idx < regionsLen; idx++)
            vec.emplace_back(std::make_shared<PyIAcadRegionImpl>((IAcadRegion*)sa[idx].p));
    }
#endif
    return vec;
}

PyIAcad3DSolidPtr PyIAcadBlockImpl::AddRevolvedSolid(const PyIAcadRegionImpl& impl, const AcGePoint3d& axisPoint, const AcGeVector3d& axisDir, double angle)
{
    _variant_t vtaxisPoint;
    _variant_t vtaxisDir;
    IAcad3DSolid* pEnt = nullptr;
    PyThrowBadHr(AcGePoint3dToVariant(vtaxisPoint.GetVARIANT(), axisPoint));
    PyThrowBadHr(AcGeVector3dToVariant(vtaxisDir.GetVARIANT(), axisDir));
    PyThrowBadHr(impObj()->AddRevolvedSolid(impl.impObj(), vtaxisPoint, vtaxisDir, angle, &pEnt));
    return std::make_unique<PyIAcad3DSolidImpl>(pEnt);
}

PyIAcadShapePtr PyIAcadBlockImpl::AddShape(const CString& name, const AcGePoint3d& insertionPoint, double scaleFactor, double rotationAngle)
{
    _bstr_t bstrname{ name };
    _variant_t vtinsertionPoint;
    IAcadShape* pEnt = nullptr;
    PyThrowBadHr(AcGePoint3dToVariant(vtinsertionPoint.GetVARIANT(), insertionPoint));
    PyThrowBadHr(impObj()->AddShape(bstrname, vtinsertionPoint, scaleFactor, rotationAngle , &pEnt));
    return std::make_unique<PyIAcadShapeImpl>(pEnt);
}

PyIAcadSolidPtr PyIAcadBlockImpl::AddSolid(const AcGePoint3d& p1, const AcGePoint3d& p2, const AcGePoint3d& p3, const AcGePoint3d& p4)
{
    _variant_t vtp1;
    _variant_t vtp2;
    _variant_t vtp3;
    _variant_t vtp4;
    IAcadSolid* pEnt = nullptr;
    PyThrowBadHr(AcGePoint3dToVariant(vtp1.GetVARIANT(), p1));
    PyThrowBadHr(AcGePoint3dToVariant(vtp2.GetVARIANT(), p2));
    PyThrowBadHr(AcGePoint3dToVariant(vtp3.GetVARIANT(), p3));
    PyThrowBadHr(AcGePoint3dToVariant(vtp4.GetVARIANT(), p4));
    PyThrowBadHr(impObj()->AddSolid(vtp1, vtp2, vtp3, vtp4, &pEnt));
    return std::make_unique<PyIAcadSolidImpl>(pEnt);
}

PyIAcad3DSolidPtr PyIAcadBlockImpl::AddSphere(const AcGePoint3d& center, double radius)
{
    _variant_t vtcenter;
    IAcad3DSolid* pEnt = nullptr;
    PyThrowBadHr(AcGePoint3dToVariant(vtcenter.GetVARIANT(), center));
    PyThrowBadHr(impObj()->AddSphere(vtcenter, radius, &pEnt));
    return std::make_unique<PyIAcad3DSolidImpl>(pEnt);
}

PyIAcadSplinePtr PyIAcadBlockImpl::AddSpline(const std::vector<AcGePoint3d>& points, const AcGeVector3d& startTangent, const AcGeVector3d& endTangent)
{
    _variant_t vtcoords;
    _variant_t vtstartTangent;
    _variant_t vtendTangent;
    IAcadSpline* pEnt = nullptr;
    PyThrowBadHr(AcGePoint3dsToVariant(vtcoords.GetVARIANT(), points));
    PyThrowBadHr(AcGeVector3dToVariant(vtstartTangent.GetVARIANT(), startTangent));
    PyThrowBadHr(AcGeVector3dToVariant(vtendTangent.GetVARIANT(), endTangent));
    PyThrowBadHr(impObj()->AddSpline(vtcoords, vtstartTangent, vtendTangent, &pEnt));
    return std::make_unique<PyIAcadSplineImpl>(pEnt);
}

PyIAcadTextPtr PyIAcadBlockImpl::AddText(const CString& textValue, const AcGePoint3d& insertionPoint, double height)
{
    _bstr_t bstrtextValue{ textValue };
    _variant_t vtinsertionPoint;
    IAcadText* pEnt = nullptr;
    PyThrowBadHr(AcGePoint3dToVariant(vtinsertionPoint.GetVARIANT(), insertionPoint));
    PyThrowBadHr(impObj()->AddText(bstrtextValue, vtinsertionPoint, height, &pEnt));
    return std::make_unique<PyIAcadTextImpl>(pEnt);
}

PyIAcadTolerancePtr PyIAcadBlockImpl::AddTolerance(const CString& textValue, const AcGePoint3d& insertionPoint, const AcGeVector3d& direction)
{
    _bstr_t bstrtextValue{ textValue };
    _variant_t vtinsertionPoint;
    _variant_t vtdirection;
    IAcadTolerance* pEnt = nullptr;
    PyThrowBadHr(AcGePoint3dToVariant(vtinsertionPoint.GetVARIANT(), insertionPoint));
    PyThrowBadHr(AcGeVector3dToVariant(vtdirection.GetVARIANT(), direction));
    PyThrowBadHr(impObj()->AddTolerance(bstrtextValue, vtinsertionPoint, vtdirection, &pEnt));
    return std::make_unique<PyIAcadToleranceImpl>(pEnt);
}

PyIAcad3DSolidPtr PyIAcadBlockImpl::AddTorus(const AcGePoint3d& center, double torusRadius, double tubeRadius)
{
    _variant_t vtcenter;
    IAcad3DSolid* pEnt = nullptr;
    PyThrowBadHr(AcGePoint3dToVariant(vtcenter.GetVARIANT(), center));
    PyThrowBadHr(impObj()->AddTorus(vtcenter, torusRadius, tubeRadius ,&pEnt));
    return std::make_unique<PyIAcad3DSolidImpl>(pEnt);
}

PyIAcad3DSolidPtr PyIAcadBlockImpl::AddWedge(const AcGePoint3d& center, double length, double width, double height)
{
    _variant_t vtcenter;
    IAcad3DSolid* pEnt = nullptr;
    PyThrowBadHr(AcGePoint3dToVariant(vtcenter.GetVARIANT(), center));
    PyThrowBadHr(impObj()->AddWedge(vtcenter, length, width, height, &pEnt));
    return std::make_unique<PyIAcad3DSolidImpl>(pEnt);
}

PyIAcadXlinePtr PyIAcadBlockImpl::AddXline(const AcGePoint3d& p1, const AcGePoint3d& p2)
{
    _variant_t vtp1;
    _variant_t vtp2;
    IAcadXline* pEnt = nullptr;
    PyThrowBadHr(AcGePoint3dToVariant(vtp1.GetVARIANT(), p1));
    PyThrowBadHr(AcGePoint3dToVariant(vtp2.GetVARIANT(), p2));
    PyThrowBadHr(impObj()->AddXline(vtp1, vtp2, &pEnt));
    return std::make_unique<PyIAcadXlineImpl>(pEnt);

}

PyIAcadBlockReferencePtr PyIAcadBlockImpl::InsertBlock(const AcGePoint3d& insertionPoint, const CString& name, const AcGeScale3d& scale, double rotation)
{
    _bstr_t bstrname{ name };
    _variant_t vtinsertionPoint;
    IAcadBlockReference* pEnt = nullptr;
    PyThrowBadHr(AcGePoint3dToVariant(vtinsertionPoint.GetVARIANT(), insertionPoint));
    PyThrowBadHr(impObj()->InsertBlock(vtinsertionPoint, bstrname, scale.sx, scale.sy, scale.sx, rotation, vtMissing, &pEnt));
    return std::make_unique<PyIAcadBlockReferenceImpl>(pEnt);
}

PyIAcadHatchPtr PyIAcadBlockImpl::AddHatch(int patternType, const CString& patternName, bool associativity)
{
    _bstr_t bstrpatternName{ patternName };
    IAcadHatch* pEnt = nullptr;
    PyThrowBadHr(impObj()->AddHatch(patternType, bstrpatternName, associativity ? VARIANT_TRUE : VARIANT_FALSE, vtMissing, &pEnt));
    return std::make_unique<PyIAcadHatchImpl>(pEnt);
}

PyIAcadRasterImagePtr PyIAcadBlockImpl::AddRaster(const CString& imageFileName, const AcGePoint3d& insertionPoint, double scaleFactor, double rotationAngle)
{
    _bstr_t bstrimageFileName{ imageFileName };
    _variant_t vtinsertionPoint;
    IAcadRasterImage* pEnt = nullptr;
    PyThrowBadHr(AcGePoint3dToVariant(vtinsertionPoint.GetVARIANT(), insertionPoint));
    PyThrowBadHr(impObj()->AddRaster(bstrimageFileName,vtinsertionPoint, scaleFactor, rotationAngle, &pEnt));
    return std::make_unique<PyIAcadRasterImageImpl>(pEnt);
}

PyIAcadLinePtr PyIAcadBlockImpl::AddLine(const AcGePoint3d& startPoint, const AcGePoint3d& endPoint)
{
    _variant_t vtstartPoint;
    _variant_t vtendPoint;
    IAcadLine* pEnt = nullptr;
    PyThrowBadHr(AcGePoint3dToVariant(vtstartPoint.GetVARIANT(), startPoint));
    PyThrowBadHr(AcGePoint3dToVariant(vtendPoint.GetVARIANT(), endPoint));
    PyThrowBadHr(impObj()->AddLine(vtstartPoint, vtendPoint, &pEnt));
    return std::make_unique<PyIAcadLineImpl>(pEnt);
}

PyIAcadMInsertBlockPtr PyIAcadBlockImpl::AddMInsertBlock(const AcGePoint3d& point, const CString& name, const AcGeScale3d& scale, double rotation, long numRows, long numCols, long rowSpacing, long columnSpacing)
{
    _variant_t vtpoint;
    _bstr_t bstrname{ name };
    IAcadMInsertBlock* pEnt = nullptr;
    PyThrowBadHr(AcGePoint3dToVariant(vtpoint.GetVARIANT(), point));
    PyThrowBadHr(impObj()->AddMInsertBlock(vtpoint, bstrname, scale.sx, scale.sy, scale.sz, rotation , numRows , numCols , rowSpacing , columnSpacing, vtMissing, &pEnt));
    return std::make_unique<PyIAcadMInsertBlockImpl>(pEnt);
}

PyIAcadPolyfaceMeshPtr PyIAcadBlockImpl::AddPolyfaceMesh(const std::vector<AcGePoint3d>& points, const std::vector<Adesk::Int16>& faces)
{
    _variant_t vtcoords;
    _variant_t vtfaces;
    IAcadPolyfaceMesh* pEnt = nullptr;
    PyThrowBadHr(AcGePoint3dsToVariant(vtcoords.GetVARIANT(), points));
    PyThrowBadHr(InitVariantFromInt16Array(faces.data(), faces.size(), &vtfaces.GetVARIANT()));
    PyThrowBadHr(impObj()->AddPolyfaceMesh(vtcoords, vtfaces, &pEnt));
    return std::make_unique<PyIAcadPolyfaceMeshImpl>(pEnt);
}

PyIAcadMLinePtr PyIAcadBlockImpl::AddMLine(const std::vector<AcGePoint3d>& points)
{
    _variant_t vtcoords;
    IAcadMLine* pEnt = nullptr;
    PyThrowBadHr(AcGePoint3dsToVariant(vtcoords.GetVARIANT(), points));
    PyThrowBadHr(impObj()->AddMLine(vtcoords, &pEnt));
    return std::make_unique<PyIAcadMLineImpl>(pEnt);
}

PyIAcadExternalReferencePtr PyIAcadBlockImpl::AttachExternalReference(const CString& path, const CString& name, const AcGePoint3d& insertionPoint, const AcGeScale3d& scale, double rotation, bool bOverlay)
{
    _variant_t vtInsertionPoint;
    _bstr_t bstrpath{ path };
    _bstr_t bstrname{ name };
    IAcadExternalReference* pEnt = nullptr;
    PyThrowBadHr(AcGePoint3dToVariant(vtInsertionPoint.GetVARIANT(), insertionPoint));
    PyThrowBadHr(impObj()->AttachExternalReference(bstrpath, bstrname, vtInsertionPoint, scale.sx, scale.sy, scale.sz , rotation, bOverlay ? VARIANT_TRUE: VARIANT_FALSE, vtMissing, &pEnt));
    return std::make_unique<PyIAcadExternalReferenceImpl>(pEnt);
}

PyIAcadTablePtr PyIAcadBlockImpl::AddTable(const AcGePoint3d& insertionPoint, int numRows, int numColumns, double rowHeight, double colWidth)
{
    _variant_t vtInsertionPoint;
    IAcadTable* pEnt = nullptr;
    PyThrowBadHr(AcGePoint3dToVariant(vtInsertionPoint.GetVARIANT(), insertionPoint));
    PyThrowBadHr(impObj()->AddTable(vtInsertionPoint, numRows, numColumns , rowHeight , colWidth, &pEnt));
    return std::make_unique<PyIAcadTableImpl>(pEnt);
}

IAcadBlock* PyIAcadBlockImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadBlock*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadModelSpaceImpl
PyIAcadModelSpaceImpl::PyIAcadModelSpaceImpl(IAcadBlock* ptr)
    :PyIAcadBlockImpl(ptr)
{
}

IAcadModelSpace* PyIAcadModelSpaceImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadModelSpace*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadPaperSpaceImpl
PyIAcadPaperSpaceImpl::PyIAcadPaperSpaceImpl(IAcadBlock* ptr)
    :PyIAcadBlockImpl(ptr)
{
}

IAcadPaperSpace* PyIAcadPaperSpaceImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadPaperSpace*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadBlocksImpl
PyIAcadBlocksImpl::PyIAcadBlocksImpl(IAcadBlocks* ptr)
    : PyIAcadObjectImpl(ptr)
{
}

IAcadBlocks* PyIAcadBlocksImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadBlocks*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyAcadStateImpl
PyIAcadStateImpl::PyIAcadStateImpl(IAcadState* ptr)
    : m_pimpl(ptr)
{
}

bool PyIAcadStateImpl::getIsQuiescent() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_IsQuiescent(&rtVal));
    return rtVal != VARIANT_FALSE;
}

IAcadState* PyIAcadStateImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadState*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadDatabaseImpl
PyIAcadDatabaseImpl::PyIAcadDatabaseImpl(IAcadDatabase* ptr)
    : m_pimpl(ptr)
{
}

PyIAcadModelSpacePtr PyIAcadDatabaseImpl::GetModelSpace() const
{
    IAcadModelSpace* ptr = nullptr;
    PyThrowBadHr(impObj()->get_ModelSpace(&ptr));
    return std::make_unique<PyIAcadModelSpaceImpl>(ptr);
}

PyIAcadPaperSpacePtr PyIAcadDatabaseImpl::GetPaperSpace() const
{
    IAcadPaperSpace* ptr = nullptr;
    PyThrowBadHr(impObj()->get_PaperSpace(&ptr));
    return std::make_unique<PyIAcadPaperSpaceImpl>(ptr);
}

PyIAcadSummaryInfoPtr PyIAcadDatabaseImpl::GetSummaryInfo() const
{
    IAcadSummaryInfo* ptr = nullptr;
    PyThrowBadHr(impObj()->get_SummaryInfo(&ptr));
    return std::make_unique<PyIAcadSummaryInfoImpl>(ptr);
}

IAcadDatabase* PyIAcadDatabaseImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadDatabase*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadDocumentImpl
PyIAcadDocumentImpl::PyIAcadDocumentImpl(IAcadDocument* ptr)
    : PyIAcadDatabaseImpl(ptr)
{
}

PyIAcadPlotPtr PyIAcadDocumentImpl::GetPlot() const
{
    IAcadPlot* ptr = nullptr;
    PyThrowBadHr(impObj()->get_Plot(&ptr));
    return std::make_unique<PyIAcadPlotImpl>(ptr);
}

PyIAcadLayerPtr PyIAcadDocumentImpl::GetActiveLayer() const
{
    IAcadLayer* ptr = nullptr;
    PyThrowBadHr(impObj()->get_ActiveLayer(&ptr));
    return std::make_unique<PyIAcadLayerImpl>(ptr);
}

void PyIAcadDocumentImpl::SetActiveLayer(const PyIAcadLayerImpl& obj)
{
    PyThrowBadHr(impObj()->put_ActiveLayer(obj.impObj()));
}

PyIAcadLineTypePtr PyIAcadDocumentImpl::GetActiveLinetype() const
{
    IAcadLineType* ptr = nullptr;
    PyThrowBadHr(impObj()->get_ActiveLinetype(&ptr));
    return std::make_unique<PyIAcadLineTypeImpl>(ptr);
}

void PyIAcadDocumentImpl::SetActiveLinetype(const PyIAcadLineTypeImpl& obj)
{
    PyThrowBadHr(impObj()->put_ActiveLinetype(obj.impObj()));
}

PyIAcadDimStylePtr PyIAcadDocumentImpl::GetActiveDimStyle() const
{
    IAcadDimStyle* ptr = nullptr;
    PyThrowBadHr(impObj()->get_ActiveDimStyle(&ptr));
    return std::make_unique<PyIAcadDimStyleImpl>(ptr);
}

void PyIAcadDocumentImpl::SetActiveDimStyle(const PyIAcadDimStyleImpl& obj)
{
    PyThrowBadHr(impObj()->put_ActiveDimStyle(obj.impObj()));
}

PyIAcadTextStylePtr PyIAcadDocumentImpl::GetActiveTextStyle() const
{
    IAcadTextStyle* ptr = nullptr;
    PyThrowBadHr(impObj()->get_ActiveTextStyle(&ptr));
    return std::make_unique<PyIAcadTextStyleImpl>(ptr);
}

void PyIAcadDocumentImpl::SetActiveTextStyle(const PyIAcadTextStyleImpl& obj)
{
    PyThrowBadHr(impObj()->put_ActiveTextStyle(obj.impObj()));
}

PyIAcadUCSPtr PyIAcadDocumentImpl::GetActiveUCS() const
{
    IAcadUCS* ptr = nullptr;
    PyThrowBadHr(impObj()->get_ActiveUCS(&ptr));
    return std::make_unique<PyIAcadUCSImpl>(ptr);
}

void PyIAcadDocumentImpl::SetActiveUCS(const PyIAcadUCSImpl& obj)
{
    PyThrowBadHr(impObj()->put_ActiveUCS(obj.impObj()));
}

PyIAcadViewportPtr PyIAcadDocumentImpl::GetActiveViewport() const
{
    IAcadViewport* ptr = nullptr;
    PyThrowBadHr(impObj()->get_ActiveViewport(&ptr));
    return std::make_unique<PyIAcadViewportImpl>(ptr);
}

void PyIAcadDocumentImpl::SetActiveViewport(const PyIAcadViewportImpl& obj)
{
    PyThrowBadHr(impObj()->put_ActiveViewport(obj.impObj()));
}

PyIAcadPViewportPtr PyIAcadDocumentImpl::GetActivePViewport() const
{
    IAcadPViewport* ptr = nullptr;
    PyThrowBadHr(impObj()->get_ActivePViewport(&ptr));
    return std::make_unique<PyIAcadPViewportImpl>(ptr);
}

void PyIAcadDocumentImpl::SetActivePViewport(const PyIAcadPViewportImpl& obj)
{
    PyThrowBadHr(impObj()->put_ActivePViewport(obj.impObj()));
}

PyAcActiveSpace PyIAcadDocumentImpl::GetActiveSpace() const
{
    AcActiveSpace sp = (AcActiveSpace)PyAcActiveSpace::pyacModelSpace;
    PyThrowBadHr(impObj()->get_ActiveSpace(&sp));
    return static_cast<PyAcActiveSpace>(sp);
}

void PyIAcadDocumentImpl::SetActiveSpace(PyAcActiveSpace sp) const
{
    PyThrowBadHr(impObj()->put_ActiveSpace(static_cast<AcActiveSpace>(sp)));
}

PyIAcadSelectionSetsPtr PyIAcadDocumentImpl::GetSelectionSets() const
{
    IAcadSelectionSets* ptr = nullptr;
    PyThrowBadHr(impObj()->get_SelectionSets(&ptr));
    return std::make_unique<PyIAcadSelectionSetsImpl>(ptr);
}

PyIAcadSelectionSetPtr PyIAcadDocumentImpl::GetActiveSelectionSet() const
{
    IAcadSelectionSet* ptr = nullptr;
    PyThrowBadHr(impObj()->get_ActiveSelectionSet(&ptr));
    return std::make_unique<PyIAcadSelectionSetImpl>(ptr);
}

CString PyIAcadDocumentImpl::GetName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Name(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

CString PyIAcadDocumentImpl::GetFullName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_FullName(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

CString PyIAcadDocumentImpl::GetPath() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Path(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

bool PyIAcadDocumentImpl::GetObjectSnapMode() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_ObjectSnapMode(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadDocumentImpl::SetObjectSnapMode(bool flag)
{
    PyThrowBadHr(impObj()->put_ObjectSnapMode(flag ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadDocumentImpl::GetReadOnly() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_ReadOnly(&rtVal));
    return rtVal != VARIANT_FALSE;
}

bool PyIAcadDocumentImpl::GetSaved() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_Saved(&rtVal));
    return rtVal != VARIANT_FALSE;
}

bool PyIAcadDocumentImpl::GetMSpace() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_MSpace(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadDocumentImpl::SetMSpace(bool flag)
{
    PyThrowBadHr(impObj()->put_MSpace(flag ? VARIANT_TRUE : VARIANT_FALSE));
}

PyIAcadUtilityPtr PyIAcadDocumentImpl::GetUtility() const
{
    IAcadUtility* ptr = nullptr;
    PyThrowBadHr(impObj()->get_Utility(&ptr));
    return std::make_unique<PyIAcadUtilityImpl>(ptr);
}

PyIAcadDocumentPtr PyIAcadDocumentImpl::Open(const CString& path)
{
    VARIANT passwd;
    VariantInit(&passwd);// no longer supported
    _bstr_t bstrpath{ path };
    IAcadDocument* ptr = nullptr;
    PyThrowBadHr(impObj()->Open(bstrpath, passwd, &ptr));
    return std::make_unique<PyIAcadDocumentImpl>(ptr);
}

void PyIAcadDocumentImpl::AuditInfo(bool flag)
{
    PyThrowBadHr(impObj()->AuditInfo(flag ? VARIANT_TRUE : VARIANT_FALSE));
}

PyIAcadBlockReferencePtr PyIAcadDocumentImpl::Import(const CString& path, const AcGePoint3d& InsertionPoint, double ScaleFactor)
{
    _bstr_t bstrpath{ path };
    VARIANT vaInsertionPoint;
    VariantInit(&vaInsertionPoint);
    constexpr ULONG s = sizeof(AcGePoint3d) / sizeof(double);
    PyThrowBadHr(InitVariantFromDoubleArray(asDblArray(InsertionPoint), s, &vaInsertionPoint));
    IDispatch* ptr = nullptr;
    PyThrowBadHr(impObj()->Import(bstrpath, vaInsertionPoint, ScaleFactor, &ptr));
    return std::make_unique<PyIAcadBlockReferenceImpl>((IAcadBlockReference*)ptr); //test
}

void PyIAcadDocumentImpl::Export(const CString& fileName, const CString& extension, const PyIAcadSelectionSetImpl& sset)
{
    _bstr_t bstrfileName{ fileName };
    _bstr_t bstrextension{ extension };
    PyThrowBadHr(impObj()->Export(bstrfileName, bstrextension, sset.impObj()));
}

PyIAcadDocumentPtr PyIAcadDocumentImpl::New(const CString& path)
{
    _bstr_t bstrpath{ path };
    IAcadDocument* ptr = nullptr;
    PyThrowBadHr(impObj()->New(bstrpath, &ptr));
    return std::make_unique<PyIAcadDocumentImpl>(ptr);
}

void PyIAcadDocumentImpl::Save()
{
    PyThrowBadHr(impObj()->Save());
}

void PyIAcadDocumentImpl::SaveAs(const CString& fileName)
{
    _bstr_t bstrpath{ fileName };
    PyThrowBadHr(impObj()->SaveAs(bstrpath));
}

void PyIAcadDocumentImpl::SaveAs(const CString& fileName, PyAcSaveAsType saType)
{
    _bstr_t bstrpath{ fileName };
    _variant_t vasaType{ saType };
    PyThrowBadHr(impObj()->SaveAs(bstrpath, vasaType));
}

void PyIAcadDocumentImpl::SaveAs(const CString& fileName, PyAcSaveAsType saType, const PyIAcadSecurityParamsImpl& pr)
{
    _bstr_t bstrpath{ fileName };
    _variant_t vasaType{ saType };
    _variant_t vapr{ (IDispatch*)pr.impObj() };
    PyThrowBadHr(impObj()->SaveAs(bstrpath, vasaType, vapr));
}

void PyIAcadDocumentImpl::Wblock(const CString& fileName, const PyIAcadSelectionSetImpl& sset)
{
    _bstr_t bstrpath{ fileName };
    PyThrowBadHr(impObj()->Wblock(bstrpath, sset.impObj()));
}

void PyIAcadDocumentImpl::PurgeAll()
{
    PyThrowBadHr(impObj()->PurgeAll());
}

TypedVariant PyIAcadDocumentImpl::GetVariable(const CString& name)
{
    _bstr_t bstrname{ name };
    _variant_t variantItem;
    PyThrowBadHr(impObj()->GetVariable(bstrname, &variantItem.GetVARIANT()));

    if (IsVariantString(variantItem))
    {
        std::wstring val(wcslen(variantItem.bstrVal) + 1, '\0');
        if (CHECKHR(VariantToString(variantItem, val.data(), val.size())))
            return TypedVariant{ RTSTR, val };
    }
    else if (variantItem.vt == VT_I2 || variantItem.vt == VT_UI2)
    {
        int16_t val = 0;
        if (CHECKHR(VariantToInt16(variantItem, &val)))
            return TypedVariant{ RTSHORT, val };
    }
    else if (variantItem.vt == VT_I4 || variantItem.vt == VT_UI4)
    {
        int32_t val = 0;
        if (CHECKHR(VariantToInt32(variantItem, &val)))
            return TypedVariant{ RTLONG, val };
    }
    else if (variantItem.vt == VT_R4 || variantItem.vt == VT_R8)
    {
        double val = .0;
        if (CHECKHR(VariantToDouble(variantItem, &val)))
            return TypedVariant{ RTREAL, val };
    }
    else if (IsVariantArray(variantItem))
    {
        AcGePoint3d val;
        ULONG pcElem = 0;
        constexpr ULONG szof = sizeof(AcGePoint3d) / sizeof(double);
        if (CHECKHR(VariantToDoubleArray(variantItem, asDblArray(val), szof, &pcElem)))
            return TypedVariant{ RT3DPOINT, val };
    }
    acutPrintf(_T("\nUnrecognised variant %ls, %ld"), __FUNCTIONW__, __LINE__);
    return TypedVariant{ RTNONE, 0 };
}

void PyIAcadDocumentImpl::SetVariable(const CString& name, const TypedVariant& tv)
{
    _variant_t variantOut;
    _bstr_t bstrname{ name };
    switch (tv.code)
    {
        case RTSHORT:
        {
            if (CHECKHR(InitVariantFromInt16(std::get<TypedVariant::kInt16>(tv.variant), &variantOut.GetVARIANT())))
                PyThrowBadHr(impObj()->SetVariable(bstrname, variantOut));
            return;
        }
        case RTLONG:
        {
            if (CHECKHR(InitVariantFromInt32(std::get<TypedVariant::kInt32>(tv.variant), &variantOut.GetVARIANT())))
                PyThrowBadHr(impObj()->SetVariable(bstrname, variantOut));
            return;
        }
        case RTREAL:
        {
            if (CHECKHR(InitVariantFromDouble(std::get<TypedVariant::kFloat>(tv.variant), &variantOut.GetVARIANT())))
                PyThrowBadHr(impObj()->SetVariable(bstrname, variantOut));
            return;
        }
        case RTSTR:
        {
            if (CHECKHR(InitVariantFromString(std::get<TypedVariant::kString>(tv.variant).c_str(), &variantOut.GetVARIANT())))
                PyThrowBadHr(impObj()->SetVariable(bstrname, variantOut));
            return;
        }
        case RT3DPOINT:
        {
            constexpr ULONG len = sizeof(AcGePoint3d) / sizeof(double);
            if (CHECKHR(InitVariantFromDoubleArray(asDblArray(std::get<TypedVariant::kPoint3d>(tv.variant)), len, &variantOut.GetVARIANT())))
                PyThrowBadHr(impObj()->SetVariable(bstrname, variantOut));
            return;
        }
        default:
        {
            acutPrintf(_T("\nUnrecognised variant %ls, %ld"), __FUNCTIONW__, __LINE__);
            break;
        }
    }
}

void PyIAcadDocumentImpl::LoadShapeFile(const CString& name)
{
    _bstr_t bstrpath{ name };
    PyThrowBadHr(impObj()->LoadShapeFile(bstrpath));
}

void PyIAcadDocumentImpl::Regen(PyAcRegenType rt)
{
    PyThrowBadHr(impObj()->Regen(AcRegenType(rt)));
}

PyIAcadSelectionSetPtr PyIAcadDocumentImpl::GetPickfirstSelectionSet() const
{
#if defined(_BRXTARGET250)
    IDispatch* ptr = nullptr;
    PyThrowBadHr(impObj()->get_PickfirstSelectionSet(&ptr));
    return std::make_unique<PyIAcadSelectionSetImpl>((IAcadSelectionSet*)ptr);
#else
    IAcadSelectionSet* ptr = nullptr;
    PyThrowBadHr(impObj()->get_PickfirstSelectionSet(&ptr));
    return std::make_unique<PyIAcadSelectionSetImpl>(ptr);
#endif
}

bool PyIAcadDocumentImpl::IsActive()
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_Active(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadDocumentImpl::Activate()
{
    PyThrowBadHr(impObj()->Activate());
}

void PyIAcadDocumentImpl::Close()
{
    PyThrowBadHr(impObj()->Close());
}

void PyIAcadDocumentImpl::Close(bool SaveChanges)
{
    _variant_t vtSaveChanges{ SaveChanges };
    PyThrowBadHr(impObj()->Close(vtSaveChanges));
}

void PyIAcadDocumentImpl::Close(bool SaveChanges, const CString& fileName)
{
    _variant_t vtSaveChanges{ SaveChanges };
    _variant_t vtFilename{ fileName };
    PyThrowBadHr(impObj()->Close(vtSaveChanges, vtFilename));
}

PyAcWindowState PyIAcadDocumentImpl::GetWindowState() const
{
    AcWindowState val = (AcWindowState)PyAcWindowState::pyacNorm;
    PyThrowBadHr(impObj()->get_WindowState(&val));
    return (PyAcWindowState)val;
}

void PyIAcadDocumentImpl::SetWindowState(PyAcWindowState val)
{
    PyThrowBadHr(impObj()->put_WindowState(AcWindowState(val)));
}

int PyIAcadDocumentImpl::GetWidth() const
{
    int val = 0;
    PyThrowBadHr(impObj()->get_Width(&val));
    return val;
}

void PyIAcadDocumentImpl::SetWidth(int val)
{
    PyThrowBadHr(impObj()->put_Width(val));
}

int PyIAcadDocumentImpl::GetHeight() const
{
    int val = 0;
    PyThrowBadHr(impObj()->get_Height(&val));
    return val;
}

void PyIAcadDocumentImpl::SetHeight(int val)
{
    PyThrowBadHr(impObj()->put_Height(val));
}

PyIAcadLayoutPtr PyIAcadDocumentImpl::GetActiveLayout() const
{
    IAcadLayout* ptr = nullptr;
    PyThrowBadHr(impObj()->get_ActiveLayout(&ptr));
    return std::make_unique<PyIAcadLayoutImpl>(ptr);
}

void PyIAcadDocumentImpl::SetActiveLayout(const PyIAcadLayoutImpl& val)
{
    PyThrowBadHr(impObj()->put_ActiveLayout(val.impObj()));
}

void PyIAcadDocumentImpl::SendCommand(const CString& cmd)
{
    _bstr_t bstrcmd{ cmd };
    PyThrowBadHr(impObj()->SendCommand(bstrcmd));
}

void PyIAcadDocumentImpl::PostCommand(const CString& cmd)
{
#if defined(_BRXTARGET250) || defined(_GRXTARGET240)
    throw PyNotimplementedByHost();
#else
    _bstr_t bstrcmd{ cmd };
    PyThrowBadHr(impObj()->PostCommand(bstrcmd));
#endif
}

LONG_PTR PyIAcadDocumentImpl::GetHWND() const
{
    LONG_PTR val = 0;
    PyThrowBadHr(impObj()->get_HWND(&val));
    return val;
}

CString PyIAcadDocumentImpl::GetWindowTitle() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_WindowTitle(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDocumentImpl::StartUndoMark()
{
    PyThrowBadHr(impObj()->StartUndoMark());
}

void PyIAcadDocumentImpl::EndUndoMark()
{
    PyThrowBadHr(impObj()->EndUndoMark());
}

PyIAcadDatabasePtr PyIAcadDocumentImpl::GetDatabase() const
{
#if defined(_BRXTARGET250)
    IAcadDatabase* ptr = nullptr;
    PyThrowBadHr(impObj()->get_database(&ptr));
    return std::make_unique<PyIAcadDatabaseImpl>(ptr);
#else
    IAcadDatabase* ptr = nullptr;
    PyThrowBadHr(impObj()->get_Database(&ptr));
    return std::make_unique<PyIAcadDatabaseImpl>(ptr);
#endif
}

PyIAcadMaterialPtr PyIAcadDocumentImpl::GetActiveMaterial() const
{
    IAcadMaterial* ptr = nullptr;
    PyThrowBadHr(impObj()->get_ActiveMaterial(&ptr));
    return std::make_unique<PyIAcadMaterialImpl>(ptr);
}

void PyIAcadDocumentImpl::SetActiveMaterial(const PyIAcadMaterialImpl& val)
{
    PyThrowBadHr(impObj()->put_ActiveMaterial(val.impObj()));
}

IAcadDocument* PyIAcadDocumentImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadDocument*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadDocumentsImpl
PyIAcadDocumentsImpl::PyIAcadDocumentsImpl(IAcadDocuments* ptr)
    : m_pimpl(ptr)
{
}

long PyIAcadDocumentsImpl::GetCount() const
{
    long val = 0;
    PyThrowBadHr(impObj()->get_Count(&val));
    return val;
}

PyIAcadDocumentPtr PyIAcadDocumentsImpl::Add()
{
    VARIANT rtVal;
    VariantInit(&rtVal);
    IAcadDocument* ptr = nullptr;
    PyThrowBadHr(impObj()->Add(rtVal, &ptr));
    return std::make_unique<PyIAcadDocumentImpl>(ptr);
}

PyIAcadDocumentPtr PyIAcadDocumentsImpl::Add(const CString& _template)
{
    _variant_t val{ static_cast<const wchar_t*>(_template) };
    IAcadDocument* ptr = nullptr;
    PyThrowBadHr(impObj()->Add(val, &ptr));
    return std::make_unique<PyIAcadDocumentImpl>(ptr);
}

void PyIAcadDocumentsImpl::Close()
{
    PyThrowBadHr(impObj()->Close());
}

PyIAcadDocumentPtr PyIAcadDocumentsImpl::GetItem(long index) const
{
    _variant_t val{ index };
    IAcadDocument* ptr = nullptr;
    PyThrowBadHr(impObj()->Item(val, &ptr));
    return std::make_unique<PyIAcadDocumentImpl>(ptr);
}

PyIAcadDocumentPtr PyIAcadDocumentsImpl::Open(const CString& path, bool readOnly)
{
    _bstr_t bstrpath{ path };
    _variant_t breadOnly{ readOnly };
    IAcadDocument* ptr = nullptr;
    PyThrowBadHr(impObj()->Open(bstrpath, breadOnly, vtMissing, &ptr));
    return std::make_unique<PyIAcadDocumentImpl>(ptr);
}

IAcadDocuments* PyIAcadDocumentsImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadDocuments*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyAcadApplicationImpl
PyAcadApplicationImpl::PyAcadApplicationImpl()
    : m_pimpl(acedGetIDispatch(FALSE))
{
}

PyAcadApplicationImpl::PyAcadApplicationImpl(IAcadApplication* ptr)
    : m_pimpl(ptr)
{
}

void PyAcadApplicationImpl::Eval(const CString& csVal) const
{
    _bstr_t bstrVal{ csVal };
    PyThrowBadHr(impObj()->Eval(bstrVal));
}

PyIAcadStateImplPtr PyAcadApplicationImpl::GetAcadState()
{
    IAcadState* ptr = nullptr;
#if defined(_ZRXTARGET)
    PyThrowBadHr(impObj()->GetZcadState(&ptr));
#elif defined(_GRXTARGET)
    PyThrowBadHr(impObj()->GetAcadState(&ptr));
#else
    PyThrowBadHr(impObj()->GetAcadState(&ptr));
#endif
    return std::make_unique<PyIAcadStateImpl>(ptr);
}

wstringArray PyAcadApplicationImpl::ListArx()
{
    VARIANT rtVal;
    VariantInit(&rtVal);
#if defined(_ZRXTARGET)
    PyThrowBadHr(impObj()->ListZrx(&rtVal));
#elif defined(_GRXTARGET)
    PyThrowBadHr(impObj()->ListGrx(&rtVal));
#else
    PyThrowBadHr(impObj()->ListArx(&rtVal));
#endif
    ULONG pcElem = 0;
    PWSTR* prgsz = nullptr;
    wstringArray vec;
    if (VariantToStringArrayAlloc(rtVal, &prgsz, &pcElem) == S_OK)
    {

        vec = wstringArray(prgsz, prgsz + pcElem);
        CoTaskMemFree(prgsz);
    }
    return vec;
}

void PyAcadApplicationImpl::LoadArx(const CString& csVal)
{
    _bstr_t bstrVal{ csVal };
#if defined(_ZRXTARGET)
    PyThrowBadHr(impObj()->LoadZrx(bstrVal));
#elif defined(_GRXTARGET)
    PyThrowBadHr(impObj()->LoadGrx(bstrVal));
#else
    PyThrowBadHr(impObj()->LoadArx(bstrVal));
#endif
}

void PyAcadApplicationImpl::LoadDVB(const CString& csVal)
{
#if defined(_ZRXTARGET)
    throw PyNotimplementedByHost();
#else
    _bstr_t bstrVal{ csVal };
    PyThrowBadHr(impObj()->LoadDVB(bstrVal));
#endif
}

void PyAcadApplicationImpl::Quit()
{
    PyThrowBadHr(impObj()->Quit());
}

void PyAcadApplicationImpl::RunMacro(const CString& csVal)
{
    _bstr_t bstrVal{ csVal };
    PyThrowBadHr(impObj()->RunMacro(bstrVal));
}

void PyAcadApplicationImpl::UnloadArx(const CString& csVal)
{
    _bstr_t bstrVal{ csVal };
#if defined(_ZRXTARGET)
    PyThrowBadHr(impObj()->UnloadZrx(bstrVal));
#elif defined(_GRXTARGET)
    PyThrowBadHr(impObj()->UnloadGrx(bstrVal));
#else
    PyThrowBadHr(impObj()->UnloadArx(bstrVal));
#endif
}

void PyAcadApplicationImpl::UnloadDVB(const CString& csVal)
{
#if defined(_ZRXTARGET)
    throw PyNotimplementedByHost();
#else
    _bstr_t bstrVal{ csVal };
    PyThrowBadHr(impObj()->UnloadDVB(bstrVal));
#endif
}

void PyAcadApplicationImpl::Update()
{
    PyThrowBadHr(impObj()->Update());
}

void PyAcadApplicationImpl::ZoomAll()
{
    PyThrowBadHr(impObj()->ZoomAll());
}

void PyAcadApplicationImpl::ZoomCenter(const AcGePoint3d& pnt, double magnify)
{
    VARIANT rtVal;
    VariantInit(&rtVal);
    constexpr ULONG s = sizeof(pnt) / sizeof(double);
    PyThrowBadHr(InitVariantFromDoubleArray(asDblArray(pnt), s, &rtVal));
    PyThrowBadHr(impObj()->ZoomCenter(rtVal, magnify));
}

void PyAcadApplicationImpl::ZoomExtents()
{
    PyThrowBadHr(impObj()->ZoomExtents());
}

void PyAcadApplicationImpl::ZoomPickWindow()
{
    PyThrowBadHr(impObj()->ZoomPickWindow());
}

void PyAcadApplicationImpl::ZoomPrevious()
{
    PyThrowBadHr(impObj()->ZoomPickWindow());
}

void PyAcadApplicationImpl::ZoomScaled(double magnify, PyAcZoomScaleType scaletype)
{
    AcZoomScaleType _scaletype = (AcZoomScaleType)scaletype;
    PyThrowBadHr(impObj()->ZoomScaled(magnify, _scaletype));
}

PyIAcadDocumentPtr PyAcadApplicationImpl::GetActiveDocument() const
{
    IAcadDocument* ptr = nullptr;
    PyThrowBadHr(impObj()->get_ActiveDocument(&ptr));
    return std::make_unique<PyIAcadDocumentImpl>(ptr);
}

void PyAcadApplicationImpl::SetActiveDocument(const PyIAcadDocumentImpl& val) const
{
    PyThrowBadHr(impObj()->put_ActiveDocument(val.impObj()));
}

CString PyAcadApplicationImpl::GetCaption() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Caption(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

PyIAcadDocumentsPtr PyAcadApplicationImpl::GetDocuments() const
{
    IAcadDocuments* ptr = nullptr;
    PyThrowBadHr(impObj()->get_Documents(&ptr));
    return std::make_unique<PyIAcadDocumentsImpl>(ptr);
}

CString PyAcadApplicationImpl::GetFullName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_FullName(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

int PyAcadApplicationImpl::GetHeight() const
{
    int val = 0;
    PyThrowBadHr(impObj()->get_Height(&val));
    return val;
}

void PyAcadApplicationImpl::SetHeight(int val)
{
    PyThrowBadHr(impObj()->put_Height(val));
}

LONG_PTR PyAcadApplicationImpl::GetHWND() const
{
    LONG_PTR val = 0;
    PyThrowBadHr(impObj()->get_HWND(&val));
    return val;
}

long PyAcadApplicationImpl::GetLocaleId() const
{
    long val = 0;
    PyThrowBadHr(impObj()->get_LocaleId(&val));
    return val;
}

PyIAcadMenuBarPtr PyAcadApplicationImpl::GetMenuBar() const
{
    IAcadMenuBar* ptr = nullptr;
    PyThrowBadHr(impObj()->get_MenuBar(&ptr));
    return std::make_unique<PyIAcadMenuBarImpl>(ptr);
}

PyIAcadMenuGroupsPtr PyAcadApplicationImpl::GetMenuGroups() const
{
    IAcadMenuGroups* ptr = nullptr;
    PyThrowBadHr(impObj()->get_MenuGroups(&ptr));
    return std::make_unique<PyIAcadMenuGroupsImpl>(ptr);
}

CString PyAcadApplicationImpl::GetName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Name(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

CString PyAcadApplicationImpl::GetPath() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Path(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

PyIAcadPreferencesPtr PyAcadApplicationImpl::GetPreferences()
{
    IAcadPreferences* ptr = nullptr;
    PyThrowBadHr(impObj()->get_Preferences(&ptr));
    return std::make_unique<PyIAcadPreferencesImpl>(ptr);
}

CString PyAcadApplicationImpl::GetVersion() const
{
    _bstr_t bstrVal;
#if defined(_BRXTARGET)
    throw PyNotimplementedByHost();
#else
    PyThrowBadHr(impObj()->get_Version(&bstrVal.GetBSTR()));
#endif
    return (LPCTSTR)bstrVal;
}

bool PyAcadApplicationImpl::GetVisible() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_Visible(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyAcadApplicationImpl::SetVisible(bool val)
{
    VARIANT_BOOL rtVal = val ? VARIANT_TRUE : VARIANT_FALSE;
    PyThrowBadHr(impObj()->put_Visible(rtVal));
}

int PyAcadApplicationImpl::GetWidth() const
{
    int val = 0;
    PyThrowBadHr(impObj()->get_Width(&val));
    return val;
}

void PyAcadApplicationImpl::SetWidth(int val)
{
    PyThrowBadHr(impObj()->put_Width(val));
}

int PyAcadApplicationImpl::GetWindowLeft() const
{
    int val = 0;
    PyThrowBadHr(impObj()->get_WindowLeft(&val));
    return val;
}

void PyAcadApplicationImpl::SetWindowLeft(int val)
{
    PyThrowBadHr(impObj()->put_WindowLeft(val));
}

PyAcWindowState PyAcadApplicationImpl::GetWindowState() const
{
    AcWindowState val = (AcWindowState)PyAcWindowState::pyacNorm;
    PyThrowBadHr(impObj()->get_WindowState(&val));
    return (PyAcWindowState)val;
}

void PyAcadApplicationImpl::SetWindowState(PyAcWindowState val)
{
    PyThrowBadHr(impObj()->put_WindowState(AcWindowState(val)));
}

int PyAcadApplicationImpl::GetWindowTop() const
{
    int val = 0;
    PyThrowBadHr(impObj()->get_WindowTop(&val));
    return val;
}

void PyAcadApplicationImpl::SetWindowTop(int val)
{
    PyThrowBadHr(impObj()->put_WindowTop(val));
}

bool PyAcadApplicationImpl::runTest(const AcDbObjectId& id)
{
    AcAxDocLock lock;
    return true;
}

IAcadApplication* PyAcadApplicationImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadApplication*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//IAcadUtilityImpl
PyIAcadUtilityImpl::PyIAcadUtilityImpl(IAcadUtility* ptr)
    : m_pimpl(ptr)
{
}

IAcadUtility* PyIAcadUtilityImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadUtility*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadSecurityParamsImpl
PyIAcadSecurityParamsImpl::PyIAcadSecurityParamsImpl(IAcadSecurityParams* ptr)
    : m_pimpl(ptr)
{
}

IAcadSecurityParams* PyIAcadSecurityParamsImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadSecurityParams*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadSelectionSetImpl
PyIAcadSelectionSetImpl::PyIAcadSelectionSetImpl(IAcadSelectionSet* ptr)
    : m_pimpl(ptr)
{
}

IAcadSelectionSet* PyIAcadSelectionSetImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadSelectionSet*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadSecurityParamsImpl
PyIAcadSelectionSetsImpl::PyIAcadSelectionSetsImpl(IAcadSelectionSets* ptr)
    : m_pimpl(ptr)
{
}

IAcadSelectionSets* PyIAcadSelectionSetsImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadSelectionSets*>(m_pimpl.GetInterfacePtr());
}
