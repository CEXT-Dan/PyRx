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
#if defined(_ARXTARGET) //TODO: make helper
    if (vtents.vt == (VT_ARRAY | VT_DISPATCH) && vtents.parray != nullptr)
    {
        CComSafeArray<IDispatch*> sa(vtents.parray);
        auto numEnts = sa.GetCount();
        for (int idx = 0; idx < numEnts; idx++)
            vec.emplace_back(std::make_shared<PyIAcadEntityImpl>((IAcadEntity*)sa[idx].p));
    }
#else
    if (vtents.vt == (VT_ARRAY | VT_VARIANT) && vtents.parray != nullptr)
    {
        CComSafeArray<VARIANT> sa(vtents.parray);
        auto numEnts = sa.GetCount();
        for (int idx = 0; idx < numEnts; idx++)
        {
            const VARIANT& item = sa[idx];
            vec.emplace_back(std::make_shared<PyIAcadEntityImpl>((IAcadEntity*)item.pdispVal));
        }
    }
#endif
    return vec;
}

PyIAcadEntityPtrArray PyIAcadEntityImpl::ArrayRectangular(int nRows, int nColumns, int nLevels, double rowDist, double colDist, double levelDist)
{
    _variant_t vtents;
    PyThrowBadHr(impObj()->ArrayRectangular(nRows, nColumns, nLevels, rowDist, colDist, levelDist, &vtents.GetVARIANT()));
    PyIAcadEntityPtrArray vec;
#if defined(_ARXTARGET)
    if (vtents.vt == (VT_ARRAY | VT_DISPATCH) && vtents.parray != nullptr)
    {
        CComSafeArray<IDispatch*> sa(vtents.parray);
        auto numEnts = sa.GetCount();
        for (int idx = 0; idx < numEnts; idx++)
            vec.emplace_back(std::make_shared<PyIAcadEntityImpl>((IAcadEntity*)sa[idx].p));
    }
#else
    if (vtents.vt == (VT_ARRAY | VT_VARIANT) && vtents.parray != nullptr)
    {
        CComSafeArray<VARIANT> sa(vtents.parray);
        auto numEnts = sa.GetCount();
        for (int idx = 0; idx < numEnts; idx++)
        {
            const VARIANT& item = sa[idx];
            vec.emplace_back(std::make_shared<PyIAcadEntityImpl>((IAcadEntity*)item.pdispVal));
        }
    }
#endif
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
