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

PyIAcadAcCmColorPtr PyIAcadEntityImpl::GetTrueColor() const
{
    IAcadAcCmColor* ptr = nullptr;
    PyThrowBadHr(impObj()->get_TrueColor(&ptr));
    return std::make_unique<PyIAcadAcCmColorImpl>(ptr);
}

void PyIAcadEntityImpl::SetTrueColor(const PyIAcadAcCmColorImpl& val) const
{
    PyThrowBadHr(impObj()->put_TrueColor(val.impObj()));
}

CString PyIAcadEntityImpl::GetLayer() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Layer(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadEntityImpl::SetLayer(const CString& val)
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_Layer(bstrval));
}

CString PyIAcadEntityImpl::GetLinetype() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Linetype(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadEntityImpl::SetLinetype(const CString& val)
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_Linetype(bstrval));
}

double PyIAcadEntityImpl::GetLinetypeScale() const
{
    double rtVal;
    PyThrowBadHr(impObj()->get_LinetypeScale(&rtVal));
    return rtVal;
}

void PyIAcadEntityImpl::SetLinetypeScale(double val)
{
    PyThrowBadHr(impObj()->put_LinetypeScale(val));
}

bool PyIAcadEntityImpl::GetVisible() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_Visible(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadEntityImpl::SetVisible(bool bVisible)
{
    PyThrowBadHr(impObj()->put_Visible(bVisible ? VARIANT_TRUE : VARIANT_FALSE));
}

PyIAcadEntityPtrArray PyIAcadEntityImpl::ArrayPolar(int numberOfObjects, double angleToFill, const AcGePoint3d& centerPoint)
{
    _variant_t vtents;
    _variant_t vtcenterPoint;
    PyThrowBadHr(AcGePoint3dToVariant(vtcenterPoint.GetVARIANT(), centerPoint));
    PyThrowBadHr(impObj()->ArrayPolar(numberOfObjects, angleToFill, vtcenterPoint, &vtents.GetVARIANT()));
    PyIAcadEntityPtrArray vec;
    PyThrowBadHr(VariantToPyIAcadEntityPtrArray(vtents, vec));
    return vec;
}

PyIAcadEntityPtrArray PyIAcadEntityImpl::ArrayRectangular(int nRows, int nColumns, int nLevels, double rowDist, double colDist, double levelDist)
{
    _variant_t vtents;
    PyThrowBadHr(impObj()->ArrayRectangular(nRows, nColumns, nLevels, rowDist, colDist, levelDist, &vtents.GetVARIANT()));
    PyIAcadEntityPtrArray vec;
    PyThrowBadHr(VariantToPyIAcadEntityPtrArray(vtents, vec));
    return vec;
}

void PyIAcadEntityImpl::Highlight(bool highlight)
{
    PyThrowBadHr(impObj()->Highlight(highlight ? VARIANT_TRUE : VARIANT_FALSE));
}

PyIAcadEntityPtr PyIAcadEntityImpl::Copy()
{
    LPDISPATCH lpdisp = nullptr;
    PyThrowBadHr(impObj()->Copy(&lpdisp));
    return std::make_unique<PyIAcadEntityImpl>(static_cast<IAcadEntity*>(lpdisp));
}

void PyIAcadEntityImpl::Move(const AcGePoint3d& fromPoint, const AcGePoint3d& toPoint)
{
    _variant_t vtfromPoint;
    _variant_t vttoPoint;
    PyThrowBadHr(AcGePoint3dToVariant(vtfromPoint.GetVARIANT(), fromPoint));
    PyThrowBadHr(AcGePoint3dToVariant(vttoPoint.GetVARIANT(), toPoint));
    PyThrowBadHr(impObj()->Move(vtfromPoint, vttoPoint));
}

void PyIAcadEntityImpl::Rotate(const AcGePoint3d& basePoint, double rotationAngle)
{
    _variant_t vtbasePoint;
    PyThrowBadHr(AcGePoint3dToVariant(vtbasePoint.GetVARIANT(), basePoint));
    PyThrowBadHr(impObj()->Rotate(vtbasePoint, rotationAngle));
}

void PyIAcadEntityImpl::Rotate3D(const AcGePoint3d& point1, const AcGePoint3d& point2, double rotationAngle)
{
    _variant_t vtpoint1;
    _variant_t vtpoint2;
    PyThrowBadHr(AcGePoint3dToVariant(vtpoint1.GetVARIANT(), point1));
    PyThrowBadHr(AcGePoint3dToVariant(vtpoint2.GetVARIANT(), point2));
    PyThrowBadHr(impObj()->Rotate3D(vtpoint1, vtpoint2, rotationAngle));
}

PyIAcadEntityPtr PyIAcadEntityImpl::Mirror(const AcGePoint3d& point1, const AcGePoint3d& point2)
{
    _variant_t vtpoint1;
    _variant_t vtpoint2;
    LPDISPATCH lpdisp = nullptr;
    PyThrowBadHr(AcGePoint3dToVariant(vtpoint1.GetVARIANT(), point1));
    PyThrowBadHr(AcGePoint3dToVariant(vtpoint2.GetVARIANT(), point2));
    PyThrowBadHr(impObj()->Mirror(vtpoint1, vtpoint2, &lpdisp));
    return std::make_unique<PyIAcadEntityImpl>(static_cast<IAcadEntity*>(lpdisp));
}

PyIAcadEntityPtr PyIAcadEntityImpl::Mirror3D(const AcGePoint3d& point1, const AcGePoint3d& point2, const AcGePoint3d& point3)
{
    _variant_t vtpoint1;
    _variant_t vtpoint2;
    _variant_t vtpoint3;
    LPDISPATCH lpdisp = nullptr;
    PyThrowBadHr(AcGePoint3dToVariant(vtpoint1.GetVARIANT(), point1));
    PyThrowBadHr(AcGePoint3dToVariant(vtpoint2.GetVARIANT(), point2));
    PyThrowBadHr(AcGePoint3dToVariant(vtpoint3.GetVARIANT(), point3));
    PyThrowBadHr(impObj()->Mirror3D(vtpoint1, vtpoint2, vtpoint3, &lpdisp));
    return std::make_unique<PyIAcadEntityImpl>(static_cast<IAcadEntity*>(lpdisp));
}

void PyIAcadEntityImpl::ScaleEntity(const AcGePoint3d& basePoint, double scaleFactor)
{
    _variant_t vtbasePoint;
    PyThrowBadHr(AcGePoint3dToVariant(vtbasePoint.GetVARIANT(), basePoint));
    PyThrowBadHr(impObj()->ScaleEntity(vtbasePoint, scaleFactor));
}

void PyIAcadEntityImpl::TransformBy(const AcGeMatrix3d& xform)
{
    //TODO: use AcAxMatrix3d;
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

void PyIAcadEntityImpl::Update()
{
    PyThrowBadHr(impObj()->Update());
}

void PyIAcadEntityImpl::GetBoundingBox(AcGePoint3d& minPoint, AcGePoint3d& maxPoint)
{
    _variant_t vtminPoint;
    _variant_t vtmaxPoint;
    PyThrowBadHr(impObj()->GetBoundingBox(&vtminPoint.GetVARIANT(), &vtmaxPoint.GetVARIANT()));
    PyThrowBadHr(VariantToAcGePoint3d(vtminPoint, minPoint));
    PyThrowBadHr(VariantToAcGePoint3d(vtmaxPoint, maxPoint));
}

std::vector<AcGePoint3d> PyIAcadEntityImpl::IntersectWith(const PyIAcadEntityImpl& intersectObject, PyAcExtendOption option)
{
    _variant_t vtinters;
    PyThrowBadHr(impObj()->IntersectWith(intersectObject.impObj(), (AcExtendOption)option, &vtinters.GetVARIANT()));
    std::vector<AcGePoint3d> vec;
    PyThrowBadHr(VariantToAcGePoint3ds(vtinters, vec));
    return vec;
}

CString PyIAcadEntityImpl::GetPlotStyleName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_PlotStyleName(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadEntityImpl::SetPlotStyleName(const CString& val)
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_PlotStyleName(bstrval));
}

PyAcLineWeight PyIAcadEntityImpl::GetLineweight() const
{
    AcLineWeight lw = (AcLineWeight)PyAcLineWeight::pyacLnWt000;
    PyThrowBadHr(impObj()->get_Lineweight(&lw));
    return (PyAcLineWeight)lw;
}

void PyIAcadEntityImpl::SetLineweight(PyAcLineWeight lw)
{
    PyThrowBadHr(impObj()->put_Lineweight((AcLineWeight)lw));
}

CString PyIAcadEntityImpl::GetEntityTransparency() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_EntityTransparency(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadEntityImpl::SetEntityTransparency(const CString& val)
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_EntityTransparency(bstrval));
}

PyIAcadHyperlinksPtr PyIAcadEntityImpl::GetHyperlinks() const
{
    IAcadHyperlinks* pVal = nullptr;
    PyThrowBadHr(impObj()->get_Hyperlinks(&pVal));
    return std::make_unique<PyIAcadHyperlinksImpl>(pVal);
}

CString PyIAcadEntityImpl::GetMaterial() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Material(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadEntityImpl::SetMaterial(const CString& val)
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_Material(bstrval));
}

CString PyIAcadEntityImpl::GetEntityName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_EntityName(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

long PyIAcadEntityImpl::GetEntityType() const
{
    long rtVal = 0;
    PyThrowBadHr(impObj()->get_EntityType(&rtVal));
    return rtVal;
}

PyAcColor PyIAcadEntityImpl::GetColor() const
{
    AcColor color = (AcColor)PyAcColor::pyacByBlock;
    PyThrowBadHr(impObj()->get_color(&color));
    return (PyAcColor)color;
}

void PyIAcadEntityImpl::SetColor(PyAcColor color)
{
    PyThrowBadHr(impObj()->put_color((AcColor)color));
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

AcGePoint3d PyIAcadPViewportImpl::GetCenter() const
{
    AcGePoint3d val;
    _variant_t vtval;
    PyThrowBadHr(impObj()->get_Center(&vtval.GetVARIANT()));
    PyThrowBadHr(VariantToAcGePoint3d(vtval, val));
    return val;
}

void PyIAcadPViewportImpl::SetCenter(const AcGePoint3d& val)
{
    _variant_t vtval;
    PyThrowBadHr(AcGePoint3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_Center(vtval));
}

AcGeVector3d PyIAcadPViewportImpl::GetDirection() const
{
    AcGeVector3d val;
    _variant_t vtval;
    PyThrowBadHr(impObj()->get_Direction(&vtval.GetVARIANT()));
    PyThrowBadHr(VariantToAcGeVector3d(vtval, val));
    return val;
}

void PyIAcadPViewportImpl::SetDirection(const AcGeVector3d& val)
{
    _variant_t vtval;
    PyThrowBadHr(AcGeVector3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_Direction(vtval));
}

bool PyIAcadPViewportImpl::GetGridOn() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_GridOn(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPViewportImpl::SetGridOn(bool bVisible)
{
    PyThrowBadHr(impObj()->put_GridOn(bVisible ? VARIANT_TRUE : VARIANT_FALSE));
}

double PyIAcadPViewportImpl::GetHeight() const
{
    double rtVal = 0.0;
    PyThrowBadHr(impObj()->get_Height(&rtVal));
    return rtVal;
}

void PyIAcadPViewportImpl::SetHeight(double val)
{
    PyThrowBadHr(impObj()->put_Height(val));
}

double PyIAcadPViewportImpl::GetWidth() const
{
    double rtVal = 0.0;
    PyThrowBadHr(impObj()->get_Width(&rtVal));
    return rtVal;
}

void PyIAcadPViewportImpl::SetWidth(double val)
{
    PyThrowBadHr(impObj()->put_Width(val));
}

bool PyIAcadPViewportImpl::GetViewportOn() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_ViewportOn(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPViewportImpl::SetViewportOn(bool bVisible)
{
    PyThrowBadHr(impObj()->put_ViewportOn(bVisible ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadPViewportImpl::GetClipped() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_Clipped(&rtVal));
    return rtVal != VARIANT_FALSE;
}

bool PyIAcadPViewportImpl::GetDisplayLocked() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_DisplayLocked(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPViewportImpl::SetDisplayLocked(bool bVisible)
{
    PyThrowBadHr(impObj()->put_DisplayLocked(bVisible ? VARIANT_TRUE : VARIANT_FALSE));
}

PyAcViewportScale PyIAcadPViewportImpl::GetStandardScale() const
{
    AcViewportScale rtVal = (AcViewportScale)PyAcViewportScale::pyacVpScaleToFit;
    PyThrowBadHr(impObj()->get_StandardScale(&rtVal));
    return (PyAcViewportScale)rtVal;
}

void PyIAcadPViewportImpl::SetStandardScale(PyAcViewportScale val)
{
    PyThrowBadHr(impObj()->put_StandardScale((AcViewportScale)val));
}

double PyIAcadPViewportImpl::GetCustomScale() const
{
    double rtVal = 0.0;
    PyThrowBadHr(impObj()->get_CustomScale(&rtVal));
    return rtVal;
}

void PyIAcadPViewportImpl::SetCustomScale(double val)
{
    PyThrowBadHr(impObj()->put_CustomScale(val));
}

CString PyIAcadPViewportImpl::GetStyleSheet() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_StyleSheet(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadPViewportImpl::SetStyleSheet(const CString& val)
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_StyleSheet(bstrval));
}

bool PyIAcadPViewportImpl::GetUCSPerViewport() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_UCSPerViewport(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPViewportImpl::SetUCSPerViewport(bool UCSSaved)
{
    PyThrowBadHr(impObj()->put_UCSPerViewport(UCSSaved ? VARIANT_TRUE : VARIANT_FALSE));
}

AcGePoint2d PyIAcadPViewportImpl::GetSnapBasePoint() const
{
    AcGePoint2d val;
    _variant_t vtval;
    PyThrowBadHr(impObj()->get_SnapBasePoint(&vtval.GetVARIANT()));
    PyThrowBadHr(VariantToAcGePoint2d(vtval, val));
    return val;
}

void PyIAcadPViewportImpl::SetSnapBasePoint(const AcGePoint2d& val)
{
    _variant_t vtval;
    PyThrowBadHr(AcGePoint2dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_SnapBasePoint(vtval));
}

bool PyIAcadPViewportImpl::GetSnapOn() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_SnapOn(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPViewportImpl::SetSnapOn(bool UCSSaved)
{
    PyThrowBadHr(impObj()->put_SnapOn(UCSSaved ? VARIANT_TRUE : VARIANT_FALSE));
}

double PyIAcadPViewportImpl::GetSnapRotationAngle() const
{
    double rtVal = 0.0;
    PyThrowBadHr(impObj()->get_SnapRotationAngle(&rtVal));
    return rtVal;
}

void PyIAcadPViewportImpl::SetSnapRotationAngle(double val)
{
    PyThrowBadHr(impObj()->put_SnapRotationAngle(val));
}

bool PyIAcadPViewportImpl::GetUCSIconOn() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_UCSIconOn(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPViewportImpl::SetUCSIconOn(bool bIconOn)
{
    PyThrowBadHr(impObj()->put_UCSIconOn(bIconOn ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadPViewportImpl::GetUCSIconAtOrigin() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_UCSIconAtOrigin(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPViewportImpl::SetUCSIconAtOrigin(bool bIconAtOrigin)
{
    PyThrowBadHr(impObj()->put_UCSIconAtOrigin(bIconAtOrigin ? VARIANT_TRUE : VARIANT_FALSE));
}

void PyIAcadPViewportImpl::GetGridSpacing(double& XSpacing, double& YSpacing)
{
    PyThrowBadHr(impObj()->GetGridSpacing(&XSpacing, &YSpacing));
}

void PyIAcadPViewportImpl::SetGridSpacing(double XSpacing, double YSpacing)
{
    PyThrowBadHr(impObj()->SetGridSpacing(XSpacing, YSpacing));
}

void PyIAcadPViewportImpl::GetSnapSpacing(double& XSpacing, double& YSpacing)
{
    PyThrowBadHr(impObj()->GetSnapSpacing(&XSpacing, &YSpacing));
}

void PyIAcadPViewportImpl::SetSnapSpacing(double XSpacing, double YSpacing)
{
    PyThrowBadHr(impObj()->SetSnapSpacing(XSpacing, YSpacing));
}

void PyIAcadPViewportImpl::Display(bool bStatus)
{
    PyThrowBadHr(impObj()->Display(bStatus ? VARIANT_TRUE : VARIANT_FALSE));
}

double PyIAcadPViewportImpl::GetTwistAngle() const
{
    double rtVal = 0.0;
    PyThrowBadHr(impObj()->get_TwistAngle(&rtVal));
    return rtVal;
}

void PyIAcadPViewportImpl::SetTwistAngle(double val)
{
    PyThrowBadHr(impObj()->put_TwistAngle(val));
}

double PyIAcadPViewportImpl::GetLensLength() const
{
    double rtVal = 0.0;
    PyThrowBadHr(impObj()->get_LensLength(&rtVal));
    return rtVal;
}

void PyIAcadPViewportImpl::SetLensLength(double val)
{
    PyThrowBadHr(impObj()->put_LensLength(val));
}

bool PyIAcadPViewportImpl::GetRemoveHiddenLines() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_RemoveHiddenLines(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPViewportImpl::SetRemoveHiddenLines(bool bRemoval)
{
    PyThrowBadHr(impObj()->put_RemoveHiddenLines(bRemoval ? VARIANT_TRUE : VARIANT_FALSE));
}

AcGePoint3d PyIAcadPViewportImpl::GetTarget() const
{
    AcGePoint3d val;
    _variant_t vtval;
    PyThrowBadHr(impObj()->get_Target(&vtval.GetVARIANT()));
    PyThrowBadHr(VariantToAcGePoint3d(vtval, val));
    return val;
}

void PyIAcadPViewportImpl::SetTarget(const AcGePoint3d& val)
{
    _variant_t vtval;
    PyThrowBadHr(AcGePoint3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_Target(vtval));
}

long PyIAcadPViewportImpl::GetArcSmoothness() const
{
    long rtVal = 0;
    PyThrowBadHr(impObj()->get_ArcSmoothness(&rtVal));
    return rtVal;
}

void PyIAcadPViewportImpl::SetArcSmoothness(long val)
{
    PyThrowBadHr(impObj()->put_ArcSmoothness(val));
}

int PyIAcadPViewportImpl::GetVisualStyle() const
{
    int rtVal = 0;
    PyThrowBadHr(impObj()->get_VisualStyle(&rtVal));
    return rtVal;
}

void PyIAcadPViewportImpl::SetVisualStyle(int val)
{
    PyThrowBadHr(impObj()->put_VisualStyle(val));
}

int PyIAcadPViewportImpl::GetShadePlot() const
{
    int rtVal = 0;
    PyThrowBadHr(impObj()->get_ShadePlot(&rtVal));
    return rtVal;
}

void PyIAcadPViewportImpl::SetShadePlot(int val)
{
    PyThrowBadHr(impObj()->put_ShadePlot(val));
}

PyIAcadViewPtr PyIAcadPViewportImpl::GetModelView() const
{
    IAcadView* View = nullptr;
    PyThrowBadHr(impObj()->get_ModelView(&View));
    return std::make_unique<PyIAcadViewImpl>(View);
}

void PyIAcadPViewportImpl::SetModelView(const PyIAcadViewImpl& val) const
{
    PyThrowBadHr(impObj()->put_ModelView(val.impObj()));
}

PyIAcadViewPtr PyIAcadPViewportImpl::GetSheetView() const
{
    IAcadView* View = nullptr;
    PyThrowBadHr(impObj()->get_SheetView(&View));
    return std::make_unique<PyIAcadViewImpl>(View);
}

void PyIAcadPViewportImpl::SetSheetView(const PyIAcadViewImpl& val) const
{
    PyThrowBadHr(impObj()->put_SheetView(val.impObj()));
}

AcDbObjectId PyIAcadPViewportImpl::GetLabelBlockId() const
{
#if defined(_GRXTARGET)
    LONG rtVal = 0;
#else
    LONG_PTR rtVal = 0;
#endif
    PyThrowBadHr(impObj()->get_LabelBlockId(&rtVal));
    AcDbObjectId id;
    id.setFromOldId((LONG_PTR)rtVal);
    return id;
}

void PyIAcadPViewportImpl::SetLabelBlockId(const AcDbObjectId& id)
{
#if defined(_GRXTARGET)
    PyThrowBadHr(impObj()->put_LabelBlockId((LONG*)id.asOldId()));
#elif defined(_BRXTARGET)
    PyThrowBadHr(impObj()->put_LabelBlockId((LONG_PTR)id.asOldId()));
#else
    PyThrowBadHr(impObj()->put_LabelBlockId((LONG_PTR*)id.asOldId()));
#endif
}

bool PyIAcadPViewportImpl::GetHasSheetView() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_HasSheetView(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPViewportImpl::SyncModelView()
{
    PyThrowBadHr(impObj()->SyncModelView());
}

int PyIAcadPViewportImpl::GetStandardScale2() const
{
    int rtVal = 0;
    PyThrowBadHr(impObj()->get_StandardScale2(&rtVal));
    return rtVal;
}

void PyIAcadPViewportImpl::SetStandardScale2(int val)
{
    PyThrowBadHr(impObj()->put_StandardScale2(val));
}

bool PyIAcadPViewportImpl::GetLayerPropertyOverrides() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_LayerPropertyOverrides(&rtVal));
    return rtVal != VARIANT_FALSE;
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
    PyThrowBadHr(impObj()->GetInvisibleEdge(index, &rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcad3DFaceImpl::SetInvisibleEdge(int index, bool flag)
{
    PyThrowBadHr(impObj()->SetInvisibleEdge(index, flag ? VARIANT_TRUE : VARIANT_FALSE));
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
    _variant_t coord;
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

Point3dCoordinates PyIAcadPolygonMeshImpl::GetCoordinates() const
{
    _variant_t vtcoords;
    Point3dCoordinates coords;
    PyThrowBadHr(impObj()->get_Coordinates(&vtcoords.GetVARIANT()));
    PyThrowBadHr(VariantToAcGePoint3ds(vtcoords, coords));
    return coords;
}

void PyIAcadPolygonMeshImpl::SetCoordinates(const Point3dCoordinates& coords)
{
    _variant_t vtcoords;
    PyThrowBadHr(AcGePoint3dsToVariant(vtcoords, coords));
    PyThrowBadHr(impObj()->put_Coordinates(vtcoords));
}

bool PyIAcadPolygonMeshImpl::GetMClose() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_MClose(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPolygonMeshImpl::SetMClose(bool val)
{
    PyThrowBadHr(impObj()->put_MClose(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadPolygonMeshImpl::GetNClose() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_NClose(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPolygonMeshImpl::SetNClose(bool val)
{
    PyThrowBadHr(impObj()->put_NClose(val ? VARIANT_TRUE : VARIANT_FALSE));
}

long PyIAcadPolygonMeshImpl::GetMDensity() const
{
    long rtVal = 0;
    PyThrowBadHr(impObj()->get_MDensity(&rtVal));
    return rtVal;
}

void PyIAcadPolygonMeshImpl::SetMDensity(long val)
{
    PyThrowBadHr(impObj()->put_MDensity(val));
}

long PyIAcadPolygonMeshImpl::GetNDensity() const
{
    long rtVal = 0;
    PyThrowBadHr(impObj()->get_NDensity(&rtVal));
    return rtVal;
}

void PyIAcadPolygonMeshImpl::SetNDensity(long val)
{
    PyThrowBadHr(impObj()->put_NDensity(val));
}

long PyIAcadPolygonMeshImpl::GetMVertexCount() const
{
    long rtVal = 0;
    PyThrowBadHr(impObj()->get_MVertexCount(&rtVal));
    return rtVal;
}

long PyIAcadPolygonMeshImpl::GetNVertexCount() const
{
    long rtVal = 0;
    PyThrowBadHr(impObj()->get_NVertexCount(&rtVal));
    return rtVal;
}

PyAcPolymeshType PyIAcadPolygonMeshImpl::GetType() const
{
    AcPolymeshType rtVal = (AcPolymeshType)PyAcPolymeshType::pyacSimpleMesh;
    PyThrowBadHr(impObj()->get_Type(&rtVal));
    return (PyAcPolymeshType)rtVal;
}

void PyIAcadPolygonMeshImpl::SetType(PyAcPolymeshType val)
{
    PyThrowBadHr(impObj()->put_Type((AcPolymeshType)val));
}

void PyIAcadPolygonMeshImpl::AppendVertex(const AcGePoint3d& val)
{
    _variant_t vtval;
    PyThrowBadHr(AcGePoint3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->AppendVertex(vtval));
}

PyIAcadEntityPtrArray PyIAcadPolygonMeshImpl::Explode() const
{
    _variant_t vtents;
    PyIAcadEntityPtrArray vec;
    PyThrowBadHr(impObj()->Explode(&vtents.GetVARIANT()));
    PyThrowBadHr(VariantToPyIAcadEntityPtrArray(vtents, vec));
    return vec;
}

AcGePoint3d PyIAcadPolygonMeshImpl::GetCoordinate(int index) const
{
    AcGePoint3d val;
    _variant_t coord;
    PyThrowBadHr(impObj()->get_Coordinate(index, &coord.GetVARIANT()));
    PyThrowBadHr(VariantToAcGePoint3d(coord, val));
    return val;
}

void PyIAcadPolygonMeshImpl::SetCoordinate(int index, const AcGePoint3d& val)
{
    _variant_t coord;
    PyThrowBadHr(AcGePoint3dToVariant(coord.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_Coordinate(index, coord));
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

Point3dCoordinates PyIAcad3DPolylineImpl::GetCoordinates() const
{
    _variant_t vtcoords;
    Point3dCoordinates coords;
    PyThrowBadHr(impObj()->get_Coordinates(&vtcoords.GetVARIANT()));
    PyThrowBadHr(VariantToAcGePoint3ds(vtcoords, coords));
    return coords;
}

void PyIAcad3DPolylineImpl::SetCoordinates(const Point3dCoordinates& coords)
{
    _variant_t vtcoords;
    PyThrowBadHr(AcGePoint3dsToVariant(vtcoords, coords));
    PyThrowBadHr(impObj()->put_Coordinates(vtcoords));
}

void PyIAcad3DPolylineImpl::AppendVertex(const AcGePoint3d& val)
{
    _variant_t vtval;
    PyThrowBadHr(AcGePoint3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->AppendVertex(vtval));
}

PyIAcadEntityPtrArray PyIAcad3DPolylineImpl::Explode() const
{
    _variant_t vtents;
    PyIAcadEntityPtrArray vec;
    PyThrowBadHr(impObj()->Explode(&vtents.GetVARIANT()));
    PyThrowBadHr(VariantToPyIAcadEntityPtrArray(vtents, vec));
    return vec;
}

AcGePoint3d PyIAcad3DPolylineImpl::GetCoordinate(int index) const
{
    AcGePoint3d val;
    _variant_t coord;
    PyThrowBadHr(impObj()->get_Coordinate(index, &coord.GetVARIANT()));
    PyThrowBadHr(VariantToAcGePoint3d(coord, val));
    return val;
}

void PyIAcad3DPolylineImpl::SetCoordinate(int index, const AcGePoint3d& val)
{
    _variant_t coord;
    PyThrowBadHr(AcGePoint3dToVariant(coord.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_Coordinate(index, coord));
}

PyAc3DPolylineType PyIAcad3DPolylineImpl::GetType() const
{
    Ac3DPolylineType rtVal = (Ac3DPolylineType)PyAc3DPolylineType::pyacSimple3DPoly;
    PyThrowBadHr(impObj()->get_Type(&rtVal));
    return (PyAc3DPolylineType)rtVal;
}

void PyIAcad3DPolylineImpl::SetType(PyAc3DPolylineType val)
{
    PyThrowBadHr(impObj()->put_Type((Ac3DPolylineType)val));
}

bool PyIAcad3DPolylineImpl::GetClosed() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_Closed(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcad3DPolylineImpl::SetClosed(bool val)
{
    PyThrowBadHr(impObj()->put_Closed(val ? VARIANT_TRUE : VARIANT_FALSE));
}

double PyIAcad3DPolylineImpl::GetLength() const
{
    double rtVal = 0.0;
    PyThrowBadHr(impObj()->get_Length(&rtVal));
    return rtVal;
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

AcGePoint3d PyIAcadArcImpl::GetStartPoint() const
{
    AcGePoint3d val;
    _variant_t coord;
    PyThrowBadHr(impObj()->get_StartPoint(&coord.GetVARIANT()));
    PyThrowBadHr(VariantToAcGePoint3d(coord, val));
    return val;
}

AcGePoint3d PyIAcadArcImpl::GetCenter() const
{
    AcGePoint3d val;
    _variant_t coord;
    PyThrowBadHr(impObj()->get_Center(&coord.GetVARIANT()));
    PyThrowBadHr(VariantToAcGePoint3d(coord, val));
    return val;
}

void PyIAcadArcImpl::SetCenter(const AcGePoint3d& val)
{
    _variant_t coord;
    PyThrowBadHr(AcGePoint3dToVariant(coord.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_Center(coord));
}

AcGePoint3d PyIAcadArcImpl::GetEndPoint() const
{
    AcGePoint3d val;
    _variant_t coord;
    PyThrowBadHr(impObj()->get_EndPoint(&coord.GetVARIANT()));
    PyThrowBadHr(VariantToAcGePoint3d(coord, val));
    return val;
}

double PyIAcadArcImpl::GetRadius() const
{
    double rtVal = 0.0;
    PyThrowBadHr(impObj()->get_Radius(&rtVal));
    return rtVal;
}

void PyIAcadArcImpl::SetRadius(double val)
{
    PyThrowBadHr(impObj()->put_Radius(val));
}

double PyIAcadArcImpl::GetStartAngle() const
{
    double rtVal = 0.0;
    PyThrowBadHr(impObj()->get_StartAngle(&rtVal));
    return rtVal;
}

void PyIAcadArcImpl::SetStartAngle(double val)
{
    PyThrowBadHr(impObj()->put_StartAngle(val));
}

double PyIAcadArcImpl::GetEndAngle() const
{
    double rtVal = 0.0;
    PyThrowBadHr(impObj()->get_EndAngle(&rtVal));
    return rtVal;
}

void PyIAcadArcImpl::SetEndAngle(double val)
{
    PyThrowBadHr(impObj()->put_EndAngle(val));
}

double PyIAcadArcImpl::GetTotalAngle() const
{
    double rtVal = 0.0;
    PyThrowBadHr(impObj()->get_TotalAngle(&rtVal));
    return rtVal;
}

double PyIAcadArcImpl::GetArcLength() const
{
    double rtVal = 0.0;
    PyThrowBadHr(impObj()->get_ArcLength(&rtVal));
    return rtVal;
}

double PyIAcadArcImpl::GetThickness() const
{
    double rtVal = 0.0;
    PyThrowBadHr(impObj()->get_Thickness(&rtVal));
    return rtVal;
}

void PyIAcadArcImpl::SetThickness(double val)
{
    PyThrowBadHr(impObj()->put_Thickness(val));
}

PyIAcadEntityPtrArray PyIAcadArcImpl::Offset(double val) const
{
    _variant_t vtents;
    PyIAcadEntityPtrArray vec;
    PyThrowBadHr(impObj()->Offset(val, &vtents.GetVARIANT()));
    PyThrowBadHr(VariantToPyIAcadEntityPtrArray(vtents, vec));
    return vec;
}

double PyIAcadArcImpl::GetArea() const
{
    double rtVal = 0.0;
    PyThrowBadHr(impObj()->get_Area(&rtVal));
    return rtVal;
}

AcGeVector3d PyIAcadArcImpl::GetNormal() const
{
    AcGeVector3d val;
    _variant_t coord;
    PyThrowBadHr(impObj()->get_Normal(&coord.GetVARIANT()));
    PyThrowBadHr(VariantToAcGeVector3d(coord, val));
    return val;
}

void PyIAcadArcImpl::SetNormal(const AcGeVector3d& val)
{
    _variant_t coord;
    PyThrowBadHr(AcGeVector3dToVariant(coord.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_Normal(coord));
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

long PyIAcadAttributeImpl::GetFieldLength() const
{
    long rtVal = 0;
    PyThrowBadHr(impObj()->get_FieldLength(&rtVal));
    return rtVal;
}

void PyIAcadAttributeImpl::SetFieldLength(long val)
{
    PyThrowBadHr(impObj()->put_FieldLength(val));
}

CString PyIAcadAttributeImpl::GetTagString() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_TagString(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadAttributeImpl::SetTagString(const CString& val)
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_TagString(bstrval));
}

CString PyIAcadAttributeImpl::GetPromptString() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_PromptString(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadAttributeImpl::SetPromptString(const CString& val)
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_PromptString(bstrval));
}

CString PyIAcadAttributeImpl::GetTextString() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_TextString(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadAttributeImpl::SetTextString(const CString& val)
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_TextString(bstrval));
}

CString PyIAcadAttributeImpl::GetStyleName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_StyleName(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadAttributeImpl::SetStyleName(const CString& val)
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_StyleName(bstrval));
}

PyAcAlignment PyIAcadAttributeImpl::GetAlignment() const
{
    AcAlignment rtVal = (AcAlignment)PyAcAlignment::pyacAlignmentLeft;
    PyThrowBadHr(impObj()->get_Alignment(&rtVal));
    return (PyAcAlignment)rtVal;
}

void PyIAcadAttributeImpl::SetAlignment(PyAcAlignment val)
{
    PyThrowBadHr(impObj()->put_Alignment((AcAlignment)val));
}

PyAcHorizontalAlignment PyIAcadAttributeImpl::GetHorizontalAlignment() const
{
    AcHorizontalAlignment rtVal = (AcHorizontalAlignment)PyAcHorizontalAlignment::pyacHorizontalAlignmentLeft;
    PyThrowBadHr(impObj()->get_HorizontalAlignment(&rtVal));
    return (PyAcHorizontalAlignment)rtVal;
}

void PyIAcadAttributeImpl::SetHorizontalAlignment(PyAcHorizontalAlignment val)
{
    PyThrowBadHr(impObj()->put_HorizontalAlignment((AcHorizontalAlignment)val));
}

PyAcVerticalAlignment PyIAcadAttributeImpl::GetVerticalAlignment() const
{
    AcVerticalAlignment rtVal = (AcVerticalAlignment)PyAcVerticalAlignment::pyacVerticalAlignmentBaseline;
    PyThrowBadHr(impObj()->get_VerticalAlignment(&rtVal));
    return (PyAcVerticalAlignment)rtVal;
}

void PyIAcadAttributeImpl::SetVerticalAlignment(PyAcVerticalAlignment val)
{
    PyThrowBadHr(impObj()->put_VerticalAlignment((AcVerticalAlignment)val));
}

double PyIAcadAttributeImpl::GetHeight() const
{
    double rtVal = 0;
    PyThrowBadHr(impObj()->get_Height(&rtVal));
    return rtVal;
}

void PyIAcadAttributeImpl::SetHeight(double val)
{
    PyThrowBadHr(impObj()->put_Height(val));
}

double PyIAcadAttributeImpl::GetRotation() const
{
    double rtVal = 0;
    PyThrowBadHr(impObj()->get_Rotation(&rtVal));
    return rtVal;
}

void PyIAcadAttributeImpl::SetRotation(double val)
{
    PyThrowBadHr(impObj()->put_Rotation(val));
}

double PyIAcadAttributeImpl::GetScaleFactor() const
{
    double rtVal = 0;
    PyThrowBadHr(impObj()->get_ScaleFactor(&rtVal));
    return rtVal;
}

void PyIAcadAttributeImpl::SetScaleFactor(double val)
{
    PyThrowBadHr(impObj()->put_ScaleFactor(val));
}

double PyIAcadAttributeImpl::GetObliqueAngle() const
{
    double rtVal = 0;
    PyThrowBadHr(impObj()->get_ObliqueAngle(&rtVal));
    return rtVal;
}

void PyIAcadAttributeImpl::SetObliqueAngle(double val)
{
    PyThrowBadHr(impObj()->put_ObliqueAngle(val));
}

AcGePoint3d PyIAcadAttributeImpl::GetTextAlignmentPoint() const
{
    AcGePoint3d val;
    _variant_t vtval;
    PyThrowBadHr(impObj()->get_TextAlignmentPoint(&vtval.GetVARIANT()));
    PyThrowBadHr(VariantToAcGePoint3d(vtval, val));
    return val;
}

void PyIAcadAttributeImpl::SetTextAlignmentPoint(const AcGePoint3d& val)
{
    _variant_t vtval;
    PyThrowBadHr(AcGePoint3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_TextAlignmentPoint(vtval));
}

AcGePoint3d PyIAcadAttributeImpl::GetInsertionPoint() const
{
    AcGePoint3d val;
    _variant_t vtval;
    PyThrowBadHr(impObj()->get_InsertionPoint(&vtval.GetVARIANT()));
    PyThrowBadHr(VariantToAcGePoint3d(vtval, val));
    return val;
}

void PyIAcadAttributeImpl::SetInsertionPoint(const AcGePoint3d& val)
{
    _variant_t vtval;
    PyThrowBadHr(AcGePoint3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_InsertionPoint(vtval));
}

AcGeVector3d PyIAcadAttributeImpl::GetNormal() const
{
    AcGeVector3d val;
    _variant_t vtval;
    PyThrowBadHr(impObj()->get_Normal(&vtval.GetVARIANT()));
    PyThrowBadHr(VariantToAcGeVector3d(vtval, val));
    return val;
}

void PyIAcadAttributeImpl::SetNormal(const AcGeVector3d& val)
{
    _variant_t vtval;
    PyThrowBadHr(AcGeVector3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_Normal(vtval));
}

long PyIAcadAttributeImpl::GetTextGenerationFlag() const
{
    long rtVal = 0;
    PyThrowBadHr(impObj()->get_TextGenerationFlag(&rtVal));
    return rtVal;
}

void PyIAcadAttributeImpl::SetTextGenerationFlag(long val)
{
    PyThrowBadHr(impObj()->put_TextGenerationFlag(val));
}

double PyIAcadAttributeImpl::GetThickness() const
{
    double rtVal = 0.0;
    PyThrowBadHr(impObj()->get_Thickness(&rtVal));
    return rtVal;
}

void PyIAcadAttributeImpl::SetThickness(double val)
{
    PyThrowBadHr(impObj()->put_Thickness(val));
}

long PyIAcadAttributeImpl::GetMode() const
{
    long rtVal = 0;
    PyThrowBadHr(impObj()->get_Mode(&rtVal));
    return rtVal;
}

void PyIAcadAttributeImpl::SetMode(long val)
{
    PyThrowBadHr(impObj()->put_Mode(val));
}

bool PyIAcadAttributeImpl::GetUpsideDown() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_UpsideDown(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadAttributeImpl::SetUpsideDown(bool val)
{
    PyThrowBadHr(impObj()->put_UpsideDown(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadAttributeImpl::GetBackward() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_Backward(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadAttributeImpl::SetBackward(bool val)
{
    PyThrowBadHr(impObj()->put_Backward(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadAttributeImpl::GetInvisible() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_Invisible(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadAttributeImpl::SetInvisible(bool val)
{
    PyThrowBadHr(impObj()->put_Invisible(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadAttributeImpl::GetConstant() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_Constant(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadAttributeImpl::SetConstant(bool val)
{
    PyThrowBadHr(impObj()->put_Constant(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadAttributeImpl::GetVerify() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_Verify(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadAttributeImpl::SetVerify(bool val)
{
    PyThrowBadHr(impObj()->put_Verify(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadAttributeImpl::GetPreset() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_Preset(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadAttributeImpl::SetPreset(bool val)
{
    PyThrowBadHr(impObj()->put_Preset(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadAttributeImpl::GetLockPosition() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_LockPosition(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadAttributeImpl::SetLockPosition(bool val)
{
    PyThrowBadHr(impObj()->put_LockPosition(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadAttributeImpl::GetMTextAttribute() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_MTextAttribute(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadAttributeImpl::SetMTextAttribute(bool val)
{
    PyThrowBadHr(impObj()->put_MTextAttribute(val ? VARIANT_TRUE : VARIANT_FALSE));
}

CString PyIAcadAttributeImpl::GetMTextAttributeContent() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_MTextAttributeContent(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadAttributeImpl::SetMTextAttributeContent(const CString& val)
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_MTextAttributeContent(bstrval));
}

void PyIAcadAttributeImpl::UpdateMTextAttribute()
{
    PyThrowBadHr(impObj()->UpdateMTextAttribute());
}

double PyIAcadAttributeImpl::GetMTextBoundaryWidth() const
{
    double rtVal = 0;
    PyThrowBadHr(impObj()->get_MTextBoundaryWidth(&rtVal));
    return rtVal;
}

void PyIAcadAttributeImpl::SetMTextBoundaryWidth(double val)
{
    PyThrowBadHr(impObj()->put_MTextBoundaryWidth(val));
}

PyAcDrawingDirection PyIAcadAttributeImpl::GetMTextDrawingDirection() const
{
    AcDrawingDirection rtVal = (AcDrawingDirection)PyAcDrawingDirection::pyacLeftToRight;
    PyThrowBadHr(impObj()->get_MTextDrawingDirection(&rtVal));
    return (PyAcDrawingDirection)rtVal;
}

void PyIAcadAttributeImpl::SetMTextDrawingDirection(PyAcDrawingDirection val)
{
    PyThrowBadHr(impObj()->put_MTextDrawingDirection((AcDrawingDirection)val));
}

IAcadAttribute* PyIAcadAttributeImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadAttribute*>(m_pimpl.GetInterfacePtr());
}


//------------------------------------------------------------------------------------
//PyIAcadAttributeReferenceImpl
PyIAcadAttributeReferenceImpl::PyIAcadAttributeReferenceImpl(IAcadAttributeReference* ptr)
    : PyIAcadEntityImpl(ptr)
{
}


double PyIAcadAttributeReferenceImpl::GetHeight() const
{
    double rtVal = 0;
    PyThrowBadHr(impObj()->get_Height(&rtVal));
    return rtVal;
}

void PyIAcadAttributeReferenceImpl::SetHeight(double val)
{
    PyThrowBadHr(impObj()->put_Height(val));
}

PyAcHorizontalAlignment PyIAcadAttributeReferenceImpl::GetHorizontalAlignment() const
{
    AcHorizontalAlignment rtVal = (AcHorizontalAlignment)PyAcHorizontalAlignment::pyacHorizontalAlignmentLeft;
    PyThrowBadHr(impObj()->get_HorizontalAlignment(&rtVal));
    return (PyAcHorizontalAlignment)rtVal;
}

PyAcAlignment PyIAcadAttributeReferenceImpl::GetAlignment() const
{
    AcAlignment rtVal = (AcAlignment)PyAcAlignment::pyacAlignmentLeft;
    PyThrowBadHr(impObj()->get_Alignment(&rtVal));
    return (PyAcAlignment)rtVal;
}

void PyIAcadAttributeReferenceImpl::SetAlignment(PyAcAlignment val)
{
    PyThrowBadHr(impObj()->put_Alignment((AcAlignment)val));
}

void PyIAcadAttributeReferenceImpl::SetHorizontalAlignment(PyAcHorizontalAlignment val)
{
    PyThrowBadHr(impObj()->put_HorizontalAlignment((AcHorizontalAlignment)val));
}

PyAcVerticalAlignment PyIAcadAttributeReferenceImpl::GetVerticalAlignment() const
{
    AcVerticalAlignment rtVal = (AcVerticalAlignment)PyAcVerticalAlignment::pyacVerticalAlignmentBaseline;
    PyThrowBadHr(impObj()->get_VerticalAlignment(&rtVal));
    return (PyAcVerticalAlignment)rtVal;
}

void PyIAcadAttributeReferenceImpl::SetVerticalAlignment(PyAcVerticalAlignment val)
{
    PyThrowBadHr(impObj()->put_VerticalAlignment((AcVerticalAlignment)val));
}

AcGePoint3d PyIAcadAttributeReferenceImpl::GetInsertionPoint() const
{
    AcGePoint3d val;
    _variant_t vtval;
    PyThrowBadHr(impObj()->get_InsertionPoint(&vtval.GetVARIANT()));
    PyThrowBadHr(VariantToAcGePoint3d(vtval, val));
    return val;
}

void PyIAcadAttributeReferenceImpl::SetInsertionPoint(const AcGePoint3d& val)
{
    _variant_t vtval;
    PyThrowBadHr(AcGePoint3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_InsertionPoint(vtval));
}

AcGeVector3d PyIAcadAttributeReferenceImpl::GetNormal() const
{
    AcGeVector3d val;
    _variant_t vtval;
    PyThrowBadHr(impObj()->get_Normal(&vtval.GetVARIANT()));
    PyThrowBadHr(VariantToAcGeVector3d(vtval, val));
    return val;
}

void PyIAcadAttributeReferenceImpl::SetNormal(const AcGeVector3d& val)
{
    _variant_t vtval;
    PyThrowBadHr(AcGeVector3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_Normal(vtval));
}
double PyIAcadAttributeReferenceImpl::GetObliqueAngle() const
{
    double rtVal = 0;
    PyThrowBadHr(impObj()->get_ObliqueAngle(&rtVal));
    return rtVal;
}

void PyIAcadAttributeReferenceImpl::SetObliqueAngle(double val)
{
    PyThrowBadHr(impObj()->put_ObliqueAngle(val));
}

double PyIAcadAttributeReferenceImpl::GetRotation() const
{
    double rtVal = 0;
    PyThrowBadHr(impObj()->get_Rotation(&rtVal));
    return rtVal;
}

void PyIAcadAttributeReferenceImpl::SetRotation(double val)
{
    PyThrowBadHr(impObj()->put_Rotation(val));
}

double PyIAcadAttributeReferenceImpl::GetScaleFactor() const
{
    double rtVal = 0;
    PyThrowBadHr(impObj()->get_ScaleFactor(&rtVal));
    return rtVal;
}

void PyIAcadAttributeReferenceImpl::SetScaleFactor(double val)
{
    PyThrowBadHr(impObj()->put_ScaleFactor(val));
}

CString PyIAcadAttributeReferenceImpl::GetStyleName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_StyleName(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadAttributeReferenceImpl::SetStyleName(const CString& val)
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_StyleName(bstrval));
}

CString PyIAcadAttributeReferenceImpl::GetTagString() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_TagString(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadAttributeReferenceImpl::SetTagString(const CString& val)
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_TagString(bstrval));
}

AcGePoint3d PyIAcadAttributeReferenceImpl::GetTextAlignmentPoint() const
{
    AcGePoint3d val;
    _variant_t vtval;
    PyThrowBadHr(impObj()->get_TextAlignmentPoint(&vtval.GetVARIANT()));
    PyThrowBadHr(VariantToAcGePoint3d(vtval, val));
    return val;
}

void PyIAcadAttributeReferenceImpl::SetTextAlignmentPoint(const AcGePoint3d& val)
{
    _variant_t vtval;
    PyThrowBadHr(AcGePoint3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_TextAlignmentPoint(vtval));
}

long PyIAcadAttributeReferenceImpl::GetTextGenerationFlag() const
{
    long rtVal = 0;
    PyThrowBadHr(impObj()->get_TextGenerationFlag(&rtVal));
    return rtVal;
}

void PyIAcadAttributeReferenceImpl::SetTextGenerationFlag(long val)
{
    PyThrowBadHr(impObj()->put_TextGenerationFlag(val));
}

CString PyIAcadAttributeReferenceImpl::GetTextString() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_TextString(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadAttributeReferenceImpl::SetTextString(const CString& val)
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_TextString(bstrval));
}

double PyIAcadAttributeReferenceImpl::GetThickness() const
{
    double rtVal = 0.0;
    PyThrowBadHr(impObj()->get_Thickness(&rtVal));
    return rtVal;
}

void PyIAcadAttributeReferenceImpl::SetThickness(double val)
{
    PyThrowBadHr(impObj()->put_Thickness(val));
}

long PyIAcadAttributeReferenceImpl::GetFieldLength() const
{
    long rtVal = 0;
    PyThrowBadHr(impObj()->get_FieldLength(&rtVal));
    return rtVal;
}

void PyIAcadAttributeReferenceImpl::SetFieldLength(long val)
{
    PyThrowBadHr(impObj()->put_FieldLength(val));
}

bool PyIAcadAttributeReferenceImpl::GetUpsideDown() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_UpsideDown(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadAttributeReferenceImpl::SetUpsideDown(bool val)
{
    PyThrowBadHr(impObj()->put_UpsideDown(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadAttributeReferenceImpl::GetBackward() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_Backward(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadAttributeReferenceImpl::SetBackward(bool val)
{
    PyThrowBadHr(impObj()->put_Backward(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadAttributeReferenceImpl::GetInvisible() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_Invisible(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadAttributeReferenceImpl::SetInvisible(bool val)
{
    PyThrowBadHr(impObj()->put_Invisible(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadAttributeReferenceImpl::GetConstant() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_Constant(&rtVal));
    return rtVal != VARIANT_FALSE;
}

bool PyIAcadAttributeReferenceImpl::GetLockPosition() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_LockPosition(&rtVal));
    return rtVal != VARIANT_FALSE;
}

bool PyIAcadAttributeReferenceImpl::GetMTextAttribute() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_MTextAttribute(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadAttributeReferenceImpl::SetMTextAttribute(bool val)
{
    PyThrowBadHr(impObj()->put_MTextAttribute(val ? VARIANT_TRUE : VARIANT_FALSE));
}

CString PyIAcadAttributeReferenceImpl::GetMTextAttributeContent() const
{
#if defined(_GRXTARGET250)
    throw PyNotimplementedByHost{};
#else
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_MTextAttributeContent(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
#endif
}

void PyIAcadAttributeReferenceImpl::SetMTextAttributeContent(const CString& val)
{
#if defined(_GRXTARGET250)
    throw PyNotimplementedByHost{};
#else
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_MTextAttributeContent(bstrval));
#endif
}

void PyIAcadAttributeReferenceImpl::UpdateMTextAttribute()
{
#if defined(_GRXTARGET250)
    throw PyNotimplementedByHost{};
#else
    PyThrowBadHr(impObj()->UpdateMTextAttribute());
#endif
}

double PyIAcadAttributeReferenceImpl::GetMTextBoundaryWidth() const
{
#if defined(_GRXTARGET250)
    throw PyNotimplementedByHost{};
#else
    double rtVal = 0;
    PyThrowBadHr(impObj()->get_MTextBoundaryWidth(&rtVal));
    return rtVal;
#endif
}

void PyIAcadAttributeReferenceImpl::SetMTextBoundaryWidth(double val)
{
#if defined(_GRXTARGET250)
    throw PyNotimplementedByHost{};
#else
    PyThrowBadHr(impObj()->put_MTextBoundaryWidth(val));
#endif
}

PyAcDrawingDirection PyIAcadAttributeReferenceImpl::GetMTextDrawingDirection() const
{
#if defined(_GRXTARGET250)
    throw PyNotimplementedByHost{};
#else
    AcDrawingDirection rtVal = (AcDrawingDirection)PyAcDrawingDirection::pyacLeftToRight;
    PyThrowBadHr(impObj()->get_MTextDrawingDirection(&rtVal));
    return (PyAcDrawingDirection)rtVal;
#endif
}

void PyIAcadAttributeReferenceImpl::SetMTextDrawingDirection(PyAcDrawingDirection val)
{
#if defined(_GRXTARGET250)
    throw PyNotimplementedByHost{};
#else
    PyThrowBadHr(impObj()->put_MTextDrawingDirection((AcDrawingDirection)val));
#endif
}

IAcadAttributeReference* PyIAcadAttributeReferenceImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadAttributeReference*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadRegionImpl
PyIAcadRegionImpl::PyIAcadRegionImpl(IAcadRegion* ptr)
    : PyIAcadEntityImpl(ptr)
{
}

double PyIAcadRegionImpl::GetArea() const
{
    double rtVal = 0.0;
    PyThrowBadHr(impObj()->get_Area(&rtVal));
    return rtVal;
}

AcGePoint2d PyIAcadRegionImpl::GetCentroid() const
{
    AcGePoint2d rtVal;
    _variant_t vtval;
    PyThrowBadHr(impObj()->get_Centroid(&vtval));
    PyThrowBadHr(VariantToAcGePoint2d(vtval, rtVal));
    return rtVal;
}

AcGePoint3d PyIAcadRegionImpl::GetMomentOfInertia() const
{
    AcGePoint3d rtVal;
    _variant_t vtval;
    PyThrowBadHr(impObj()->get_MomentOfInertia(&vtval));
    PyThrowBadHr(VariantToAcGePoint3d(vtval, rtVal));
    return rtVal;
}

AcGeVector3d PyIAcadRegionImpl::GetNormal() const
{
    AcGeVector3d val;
    _variant_t vtval;
    PyThrowBadHr(impObj()->get_Normal(&vtval.GetVARIANT()));
    PyThrowBadHr(VariantToAcGeVector3d(vtval, val));
    return val;
}

double PyIAcadRegionImpl::GetPerimeter() const
{
    double rtVal = 0.0;
    PyThrowBadHr(impObj()->get_Perimeter(&rtVal));
    return rtVal;
}

Vector3dDirections PyIAcadRegionImpl::GetPrincipalDirections() const
{
    Vector3dDirections points;
    _variant_t vtval;
    PyThrowBadHr(impObj()->get_PrincipalDirections(&vtval.GetVARIANT()));
    PyThrowBadHr(VariantToAcGeVector3ds(vtval, points));
    return points;
}

AcGePoint3d PyIAcadRegionImpl::GetPrincipalMoments() const
{
    AcGePoint3d rtVal;
    _variant_t vtval;
    PyThrowBadHr(impObj()->get_PrincipalMoments(&vtval));
    PyThrowBadHr(VariantToAcGePoint3d(vtval, rtVal));
    return rtVal;
}

AcGePoint3d PyIAcadRegionImpl::GetRadiiOfGyration() const
{
    AcGePoint3d rtVal;
    _variant_t vtval;
    PyThrowBadHr(impObj()->get_RadiiOfGyration(&vtval));
    PyThrowBadHr(VariantToAcGePoint3d(vtval, rtVal));
    return rtVal;
}

void PyIAcadRegionImpl::Boolean(PyAcBooleanType val, const PyIAcadRegionImpl& region) const
{
    PyThrowBadHr(impObj()->Boolean((AcBooleanType)val, region.impObj()));
}

PyIAcadEntityPtrArray PyIAcadRegionImpl::Explode() const
{
    _variant_t vtents;
    PyIAcadEntityPtrArray vec;
    PyThrowBadHr(impObj()->Explode(&vtents.GetVARIANT()));
    PyThrowBadHr(VariantToPyIAcadEntityPtrArray(vtents, vec));
    return vec;
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

AcGePoint3d PyIAcad3DSolidImpl::GetCentroid() const
{
    AcGePoint3d rtVal;
    _variant_t vtval;
    PyThrowBadHr(impObj()->get_Centroid(&vtval));
    PyThrowBadHr(VariantToAcGePoint3d(vtval, rtVal));
    return rtVal;
}

AcGePoint3d PyIAcad3DSolidImpl::GetMomentOfInertia() const
{
    AcGePoint3d rtVal;
    _variant_t vtval;
    PyThrowBadHr(impObj()->get_MomentOfInertia(&vtval));
    PyThrowBadHr(VariantToAcGePoint3d(vtval, rtVal));
    return rtVal;
}

Vector3dDirections PyIAcad3DSolidImpl::GetPrincipalDirections() const
{
    Vector3dDirections points;
    _variant_t vtval;
    PyThrowBadHr(impObj()->get_PrincipalDirections(&vtval.GetVARIANT()));
    PyThrowBadHr(VariantToAcGeVector3ds(vtval, points));
    return points;
}

AcGePoint3d PyIAcad3DSolidImpl::GetPrincipalMoments() const
{
    AcGePoint3d rtVal;
    _variant_t vtval;
    PyThrowBadHr(impObj()->get_PrincipalMoments(&vtval));
    PyThrowBadHr(VariantToAcGePoint3d(vtval, rtVal));
    return rtVal;
}

AcGePoint3d PyIAcad3DSolidImpl::GetProductOfInertia() const
{
    AcGePoint3d rtVal;
    _variant_t vtval;
    PyThrowBadHr(impObj()->get_ProductOfInertia(&vtval));
    PyThrowBadHr(VariantToAcGePoint3d(vtval, rtVal));
    return rtVal;
}

AcGePoint3d PyIAcad3DSolidImpl::GetRadiiOfGyration() const
{
    AcGePoint3d rtVal;
    _variant_t vtval;
    PyThrowBadHr(impObj()->get_RadiiOfGyration(&vtval));
    PyThrowBadHr(VariantToAcGePoint3d(vtval, rtVal));
    return rtVal;
}

double PyIAcad3DSolidImpl::GetVolume() const
{
    double rtVal = 0.0;
    PyThrowBadHr(impObj()->get_Volume(&rtVal));
    return rtVal;
}

void PyIAcad3DSolidImpl::Boolean(PyAcBooleanType val, const PyIAcad3DSolidImpl& solid) const
{
    PyThrowBadHr(impObj()->Boolean((AcBooleanType)val, solid.impObj()));
}

PyIAcad3DSolidPtr PyIAcad3DSolidImpl::CheckInterference(const PyIAcad3DSolidImpl& solid, bool createInterferenceSolid, bool& outSolidsInterfere)
{
#if defined(_GRXTARGET)
    throw PyNotimplementedByHost{};
#else
    IAcad3DSolid* ptr = nullptr;
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->CheckInterference(solid.impObj(), createInterferenceSolid ? VARIANT_TRUE : VARIANT_FALSE, &rtVal, &ptr));
    outSolidsInterfere = (rtVal == VARIANT_TRUE);
    return std::make_unique<PyIAcad3DSolidImpl>(ptr);
#endif
}

std::unique_ptr<PyIAcad3DSolidImpl> PyIAcad3DSolidImpl::SliceSolid(const AcGePoint3d& p1, const AcGePoint3d& p2, const AcGePoint3d& p3, bool negative)
{
    _variant_t vtp1;
    _variant_t vtp2;
    _variant_t vtp3;
    IAcad3DSolid* ptr = nullptr;
    PyThrowBadHr(AcGePoint3dToVariant(vtp1.GetVARIANT(), p1));
    PyThrowBadHr(AcGePoint3dToVariant(vtp2.GetVARIANT(), p2));
    PyThrowBadHr(AcGePoint3dToVariant(vtp3.GetVARIANT(), p3));
    PyThrowBadHr(impObj()->SliceSolid(vtp1, vtp2, vtp3, negative ? VARIANT_TRUE : VARIANT_FALSE, &ptr));
    return std::make_unique<PyIAcad3DSolidImpl>(ptr);
}

PyIAcadRegionPtr PyIAcad3DSolidImpl::SectionSolid(const AcGePoint3d& p1, const AcGePoint3d& p2, const AcGePoint3d& p3)
{
    _variant_t vtp1;
    _variant_t vtp2;
    _variant_t vtp3;
    IAcadRegion* ptr = nullptr;
    PyThrowBadHr(AcGePoint3dToVariant(vtp1.GetVARIANT(), p1));
    PyThrowBadHr(AcGePoint3dToVariant(vtp2.GetVARIANT(), p2));
    PyThrowBadHr(AcGePoint3dToVariant(vtp3.GetVARIANT(), p3));
    PyThrowBadHr(impObj()->SectionSolid(vtp1, vtp2, vtp3, &ptr));
    return std::make_unique<PyIAcadRegionImpl>(ptr);

}

CString PyIAcad3DSolidImpl::GetSolidType() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_SolidType(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

AcGePoint3d PyIAcad3DSolidImpl::GetPosition() const
{
    AcGePoint3d rtVal;
    _variant_t vtval;
    PyThrowBadHr(impObj()->get_Position(&vtval));
    PyThrowBadHr(VariantToAcGePoint3d(vtval, rtVal));
    return rtVal;
}

void PyIAcad3DSolidImpl::SetPosition(const AcGePoint3d& val)
{
    _variant_t vtval;
    PyThrowBadHr(AcGePoint3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_Position(vtval));

}

bool PyIAcad3DSolidImpl::GetHistory() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_History(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcad3DSolidImpl::SetHistory(bool val)
{
    PyThrowBadHr(impObj()->put_History(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcad3DSolidImpl::GetShowHistory() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_ShowHistory(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcad3DSolidImpl::SetShowHistory(bool val)
{
    PyThrowBadHr(impObj()->put_ShowHistory(val ? VARIANT_TRUE : VARIANT_FALSE));
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

AcGePoint3d PyIAcadCircleImpl::GetCenter() const
{
    AcGePoint3d rtVal;
    _variant_t vtval;
    PyThrowBadHr(impObj()->get_Center(&vtval));
    PyThrowBadHr(VariantToAcGePoint3d(vtval, rtVal));
    return rtVal;
}

void PyIAcadCircleImpl::SetCenter(const AcGePoint3d& val)
{
    _variant_t coord;
    PyThrowBadHr(AcGePoint3dToVariant(coord.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_Center(coord));
}

double PyIAcadCircleImpl::GetRadius() const
{
    double rtVal;
    PyThrowBadHr(impObj()->get_Radius(&rtVal));
    return rtVal;
}

void PyIAcadCircleImpl::SetRadius(double val)
{
    PyThrowBadHr(impObj()->put_Radius(val));
}

double PyIAcadCircleImpl::GetDiameter() const
{
    double rtVal;
    PyThrowBadHr(impObj()->get_Diameter(&rtVal));
    return rtVal;
}

void PyIAcadCircleImpl::SetDiameter(double val)
{
    PyThrowBadHr(impObj()->put_Diameter(val));
}

double PyIAcadCircleImpl::GetCircumference() const
{
    double rtVal;
    PyThrowBadHr(impObj()->get_Circumference(&rtVal));
    return rtVal;
}

void PyIAcadCircleImpl::SetCircumference(double val)
{
    PyThrowBadHr(impObj()->put_Circumference(val));
}

double PyIAcadCircleImpl::GetArea() const
{
    double rtVal;
    PyThrowBadHr(impObj()->get_Area(&rtVal));
    return rtVal;
}

void PyIAcadCircleImpl::SetArea(double val)
{
    PyThrowBadHr(impObj()->put_Area(val));
}

AcGeVector3d PyIAcadCircleImpl::GetNormal() const
{
    AcGeVector3d val;
    _variant_t coord;
    PyThrowBadHr(impObj()->get_Normal(&coord.GetVARIANT()));
    PyThrowBadHr(VariantToAcGeVector3d(coord, val));
    return val;
}

void PyIAcadCircleImpl::SetNormal(const AcGeVector3d& val)
{
    _variant_t coord;
    PyThrowBadHr(AcGeVector3dToVariant(coord.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_Normal(coord));
}

double PyIAcadCircleImpl::GetThickness() const
{
    double rtVal;
    PyThrowBadHr(impObj()->get_Thickness(&rtVal));
    return rtVal;
}

void PyIAcadCircleImpl::SetThickness(double val)
{
    PyThrowBadHr(impObj()->put_Thickness(val));
}

PyIAcadEntityPtrArray PyIAcadCircleImpl::Offset(double val) const
{
    _variant_t vtents;
    PyIAcadEntityPtrArray vec;
    PyThrowBadHr(impObj()->Offset(val, &vtents.GetVARIANT()));
    PyThrowBadHr(VariantToPyIAcadEntityPtrArray(vtents, vec));
    return vec;
}

IAcadCircle* PyIAcadCircleImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadCircle*>(m_pimpl.GetInterfacePtr());
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

AcGePoint3d PyIAcadBlockReferenceImpl::GetInsertionPoint() const
{
    _variant_t vtval;
    AcGePoint3d rtVal;
    PyThrowBadHr(impObj()->get_InsertionPoint(&vtval));
    PyThrowBadHr(VariantToAcGePoint3d(vtval, rtVal));
    return rtVal;
}

void PyIAcadBlockReferenceImpl::SetInsertionPoint(const AcGePoint3d& val)
{
    _variant_t coord;
    PyThrowBadHr(AcGePoint3dToVariant(coord.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_InsertionPoint(coord));
}

CString PyIAcadBlockReferenceImpl::GetName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Name(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadBlockReferenceImpl::SetName(const CString& val)
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_Name(bstrval));
}

AcGeVector3d PyIAcadBlockReferenceImpl::GetNormal() const
{
    _variant_t vtval;
    AcGeVector3d rtVal;
    PyThrowBadHr(impObj()->get_Normal(&vtval));
    PyThrowBadHr(VariantToAcGeVector3d(vtval, rtVal));
    return rtVal;
}

void PyIAcadBlockReferenceImpl::SetNormal(const AcGeVector3d& val)
{
    _variant_t vtval;
    PyThrowBadHr(AcGeVector3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_Normal(vtval));
}

double PyIAcadBlockReferenceImpl::GetRotation() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_Rotation(&rtval));
    return rtval;
}

void PyIAcadBlockReferenceImpl::SetRotation(double val)
{
    PyThrowBadHr(impObj()->put_Rotation(val));
}

double PyIAcadBlockReferenceImpl::GetXScaleFactor() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_XScaleFactor(&rtval));
    return rtval;
}

void PyIAcadBlockReferenceImpl::SetXScaleFactor(double val)
{
    PyThrowBadHr(impObj()->put_XScaleFactor(val));
}

double PyIAcadBlockReferenceImpl::GetYScaleFactor() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_YScaleFactor(&rtval));
    return rtval;
}

void PyIAcadBlockReferenceImpl::SetYScaleFactor(double val)
{
    PyThrowBadHr(impObj()->put_YScaleFactor(val));
}

double PyIAcadBlockReferenceImpl::GetZScaleFactor() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_ZScaleFactor(&rtval));
    return rtval;
}

void PyIAcadBlockReferenceImpl::SetZScaleFactor(double val)
{
    PyThrowBadHr(impObj()->put_ZScaleFactor(val));
}

PyIAcadEntityPtrArray PyIAcadBlockReferenceImpl::Explode() const
{
    _variant_t vtents;
    PyIAcadEntityPtrArray vec;
    PyThrowBadHr(impObj()->Explode(&vtents.GetVARIANT()));
    PyThrowBadHr(VariantToPyIAcadEntityPtrArray(vtents, vec));
    return vec;
}

PyIAcadAttributeRefPtrArray PyIAcadBlockReferenceImpl::GetAttributes() const
{
    _variant_t vtents;
    PyIAcadAttributeRefPtrArray vec;
    PyThrowBadHr(impObj()->GetAttributes(&vtents.GetVARIANT()));
    PyThrowBadHr(VariantToPyIAcadAttributeRefPtrArray(vtents, vec));
    return vec;
}

PyIAcadAttributeRefPtrArray PyIAcadBlockReferenceImpl::GetConstantAttributes() const
{
    _variant_t vtents;
    PyIAcadAttributeRefPtrArray vec;
    PyThrowBadHr(impObj()->GetConstantAttributes(&vtents.GetVARIANT()));
    PyThrowBadHr(VariantToPyIAcadAttributeRefPtrArray(vtents, vec));
    return vec;
}

PyIAcadDynRefPropPtrArray PyIAcadBlockReferenceImpl::GetDynamicBlockProperties() const
{
    _variant_t vtents;
    PyIAcadDynRefPropPtrArray vec;
    PyThrowBadHr(impObj()->GetDynamicBlockProperties(&vtents.GetVARIANT()));
    PyThrowBadHr(VariantToPyIAcadDynRefPropertyPtrArray(vtents, vec));
    return vec;
}

bool PyIAcadBlockReferenceImpl::GetHasAttributes() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_HasAttributes(&rtVal));
    return rtVal != VARIANT_FALSE;
}

CString PyIAcadBlockReferenceImpl::GetEffectiveName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_EffectiveName(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

bool PyIAcadBlockReferenceImpl::GetIsDynamicBlock() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_IsDynamicBlock(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadBlockReferenceImpl::ResetBlock() const
{
    PyThrowBadHr(impObj()->ResetBlock());
}

void PyIAcadBlockReferenceImpl::ConvertToAnonymousBlock() const
{
    PyThrowBadHr(impObj()->ConvertToAnonymousBlock());
}

void PyIAcadBlockReferenceImpl::ConvertToStaticBlock(const CString& newBlockName) const
{
    _bstr_t bstrval{ newBlockName };
    PyThrowBadHr(impObj()->ConvertToStaticBlock(bstrval));
}

double PyIAcadBlockReferenceImpl::GetXEffectiveScaleFactor() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_XEffectiveScaleFactor(&rtval));
    return rtval;
}

void PyIAcadBlockReferenceImpl::SetXEffectiveScaleFactor(double val)
{
    PyThrowBadHr(impObj()->put_XEffectiveScaleFactor(val));
}

double PyIAcadBlockReferenceImpl::GetYEffectiveScaleFactor() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_YEffectiveScaleFactor(&rtval));
    return rtval;
}

void PyIAcadBlockReferenceImpl::SetYEffectiveScaleFactor(double val)
{
    PyThrowBadHr(impObj()->put_YEffectiveScaleFactor(val));
}

double PyIAcadBlockReferenceImpl::GetZEffectiveScaleFactor() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_ZEffectiveScaleFactor(&rtval));
    return rtval;
}

void PyIAcadBlockReferenceImpl::SetZEffectiveScaleFactor(double val)
{
    PyThrowBadHr(impObj()->put_ZEffectiveScaleFactor(val));
}

CString PyIAcadBlockReferenceImpl::GetInsUnits() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_InsUnits(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

double PyIAcadBlockReferenceImpl::GetInsUnitsFactor() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_InsUnitsFactor(&rtval));
    return rtval;
}

IAcadBlockReference* PyIAcadBlockReferenceImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadBlockReference*>(m_pimpl.GetInterfacePtr());
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
//PyIAcadExternalReferenceImpl
PyIAcadExternalReferenceImpl::PyIAcadExternalReferenceImpl(IAcadExternalReference* ptr)
    : PyIAcadBlockReferenceImpl(ptr)
{
}

IAcadExternalReference* PyIAcadExternalReferenceImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadExternalReference*>(m_pimpl.GetInterfacePtr());
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

//------------------------------------------------------------------------------------
//PyIAcadTableImpl
PyIAcadTableImpl::PyIAcadTableImpl(IAcadTable* ptr)
    : PyIAcadEntityImpl(ptr)
{
}

IAcadTable* PyIAcadTableImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadTable*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadSectionImpl
PyIAcadSectionImpl::PyIAcadSectionImpl(IAcadSection* ptr)
    : PyIAcadEntityImpl(ptr)
{
}

IAcadSection* PyIAcadSectionImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadSection*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadMLeaderImpl
PyIAcadMLeaderImpl::PyIAcadMLeaderImpl(IAcadMLeader* ptr)
    : PyIAcadEntityImpl(ptr)
{
}

IAcadMLeader* PyIAcadMLeaderImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadMLeader*>(m_pimpl.GetInterfacePtr());
}
