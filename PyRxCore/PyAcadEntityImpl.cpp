#include "stdafx.h"
#include "PyAcadEntityImpl.h"
#include "PyAcadObjectImpl.h"

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

void PyIAcadEntityImpl::SetLayer(const CString& val)const
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

void PyIAcadEntityImpl::SetLinetype(const CString& val)const
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

void PyIAcadEntityImpl::SetLinetypeScale(double val)const
{
    PyThrowBadHr(impObj()->put_LinetypeScale(val));
}

bool PyIAcadEntityImpl::GetVisible() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_Visible(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadEntityImpl::SetVisible(bool bVisible)const
{
    PyThrowBadHr(impObj()->put_Visible(bVisible ? VARIANT_TRUE : VARIANT_FALSE));
}

PyIAcadEntityPtrArray PyIAcadEntityImpl::ArrayPolar(int numberOfObjects, double angleToFill, const AcGePoint3d& centerPoint)const
{
    _variant_t vtents;
    _variant_t vtcenterPoint;
    PyThrowBadHr(AcGePoint3dToVariant(vtcenterPoint.GetVARIANT(), centerPoint));
    PyThrowBadHr(impObj()->ArrayPolar(numberOfObjects, angleToFill, vtcenterPoint, &vtents.GetVARIANT()));
    PyIAcadEntityPtrArray vec;
    PyThrowBadHr(VariantToPyIAcadEntityPtrArray(vtents, vec));
    return vec;
}

PyIAcadEntityPtrArray PyIAcadEntityImpl::ArrayRectangular(int nRows, int nColumns, int nLevels, double rowDist, double colDist, double levelDist) const
{
    _variant_t vtents;
    PyThrowBadHr(impObj()->ArrayRectangular(nRows, nColumns, nLevels, rowDist, colDist, levelDist, &vtents.GetVARIANT()));
    PyIAcadEntityPtrArray vec;
    PyThrowBadHr(VariantToPyIAcadEntityPtrArray(vtents, vec));
    return vec;
}

void PyIAcadEntityImpl::Highlight(bool highlight) const
{
    PyThrowBadHr(impObj()->Highlight(highlight ? VARIANT_TRUE : VARIANT_FALSE));
}

PyIAcadEntityPtr PyIAcadEntityImpl::Copy() const
{
    LPDISPATCH lpdisp = nullptr;
    PyThrowBadHr(impObj()->Copy(&lpdisp));
    return std::make_unique<PyIAcadEntityImpl>(static_cast<IAcadEntity*>(lpdisp));
}

void PyIAcadEntityImpl::Move(const AcGePoint3d& fromPoint, const AcGePoint3d& toPoint) const
{
    _variant_t vtfromPoint;
    _variant_t vttoPoint;
    PyThrowBadHr(AcGePoint3dToVariant(vtfromPoint.GetVARIANT(), fromPoint));
    PyThrowBadHr(AcGePoint3dToVariant(vttoPoint.GetVARIANT(), toPoint));
    PyThrowBadHr(impObj()->Move(vtfromPoint, vttoPoint));
}

void PyIAcadEntityImpl::Rotate(const AcGePoint3d& basePoint, double rotationAngle) const
{
    _variant_t vtbasePoint;
    PyThrowBadHr(AcGePoint3dToVariant(vtbasePoint.GetVARIANT(), basePoint));
    PyThrowBadHr(impObj()->Rotate(vtbasePoint, rotationAngle));
}

void PyIAcadEntityImpl::Rotate3D(const AcGePoint3d& point1, const AcGePoint3d& point2, double rotationAngle) const
{
    _variant_t vtpoint1;
    _variant_t vtpoint2;
    PyThrowBadHr(AcGePoint3dToVariant(vtpoint1.GetVARIANT(), point1));
    PyThrowBadHr(AcGePoint3dToVariant(vtpoint2.GetVARIANT(), point2));
    PyThrowBadHr(impObj()->Rotate3D(vtpoint1, vtpoint2, rotationAngle));
}

PyIAcadEntityPtr PyIAcadEntityImpl::Mirror(const AcGePoint3d& point1, const AcGePoint3d& point2) const
{
    _variant_t vtpoint1;
    _variant_t vtpoint2;
    LPDISPATCH lpdisp = nullptr;
    PyThrowBadHr(AcGePoint3dToVariant(vtpoint1.GetVARIANT(), point1));
    PyThrowBadHr(AcGePoint3dToVariant(vtpoint2.GetVARIANT(), point2));
    PyThrowBadHr(impObj()->Mirror(vtpoint1, vtpoint2, &lpdisp));
    return std::make_unique<PyIAcadEntityImpl>(static_cast<IAcadEntity*>(lpdisp));
}

PyIAcadEntityPtr PyIAcadEntityImpl::Mirror3D(const AcGePoint3d& point1, const AcGePoint3d& point2, const AcGePoint3d& point3) const
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

void PyIAcadEntityImpl::ScaleEntity(const AcGePoint3d& basePoint, double scaleFactor) const
{
    _variant_t vtbasePoint;
    PyThrowBadHr(AcGePoint3dToVariant(vtbasePoint.GetVARIANT(), basePoint));
    PyThrowBadHr(impObj()->ScaleEntity(vtbasePoint, scaleFactor));
}

void PyIAcadEntityImpl::TransformBy(const AcGeMatrix3d& xform) const
{
    AcAxDocLock axlock;
    AcDbEntityPointer pEnt(id(), AcDb::OpenMode::kForWrite);
    PyThrowBadEs(pEnt.openStatus());
    PyThrowBadEs(pEnt->transformBy(xform));
}

void PyIAcadEntityImpl::Update() const
{
    PyThrowBadHr(impObj()->Update());
}

void PyIAcadEntityImpl::GetBoundingBox(AcGePoint3d& minPoint, AcGePoint3d& maxPoint) const
{
    _variant_t vtminPoint;
    _variant_t vtmaxPoint;
    PyThrowBadHr(impObj()->GetBoundingBox(&vtminPoint.GetVARIANT(), &vtmaxPoint.GetVARIANT()));
    PyThrowBadHr(VariantToAcGePoint3d(vtminPoint, minPoint));
    PyThrowBadHr(VariantToAcGePoint3d(vtmaxPoint, maxPoint));
}

std::vector<AcGePoint3d> PyIAcadEntityImpl::IntersectWith(const PyIAcadEntityImpl& intersectObject, PyAcExtendOption option) const
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

void PyIAcadEntityImpl::SetPlotStyleName(const CString& val) const
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

void PyIAcadEntityImpl::SetLineweight(PyAcLineWeight lw) const
{
    PyThrowBadHr(impObj()->put_Lineweight((AcLineWeight)lw));
}

CString PyIAcadEntityImpl::GetEntityTransparency() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_EntityTransparency(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadEntityImpl::SetEntityTransparency(const CString& val) const
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

void PyIAcadEntityImpl::SetMaterial(const CString& val) const
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

void PyIAcadEntityImpl::SetColor(PyAcColor color) const
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

void PyIAcadPViewportImpl::SetCenter(const AcGePoint3d& val) const
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

void PyIAcadPViewportImpl::SetDirection(const AcGeVector3d& val) const
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

void PyIAcadPViewportImpl::SetGridOn(bool bVisible) const
{
    PyThrowBadHr(impObj()->put_GridOn(bVisible ? VARIANT_TRUE : VARIANT_FALSE));
}

double PyIAcadPViewportImpl::GetHeight() const
{
    double rtVal = 0.0;
    PyThrowBadHr(impObj()->get_Height(&rtVal));
    return rtVal;
}

void PyIAcadPViewportImpl::SetHeight(double val) const
{
    PyThrowBadHr(impObj()->put_Height(val));
}

double PyIAcadPViewportImpl::GetWidth() const
{
    double rtVal = 0.0;
    PyThrowBadHr(impObj()->get_Width(&rtVal));
    return rtVal;
}

void PyIAcadPViewportImpl::SetWidth(double val) const
{
    PyThrowBadHr(impObj()->put_Width(val));
}

bool PyIAcadPViewportImpl::GetViewportOn() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_ViewportOn(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPViewportImpl::SetViewportOn(bool bVisible) const
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

void PyIAcadPViewportImpl::SetDisplayLocked(bool bVisible) const
{
    PyThrowBadHr(impObj()->put_DisplayLocked(bVisible ? VARIANT_TRUE : VARIANT_FALSE));
}

PyAcViewportScale PyIAcadPViewportImpl::GetStandardScale() const
{
    AcViewportScale rtVal = (AcViewportScale)PyAcViewportScale::pyacVpScaleToFit;
    PyThrowBadHr(impObj()->get_StandardScale(&rtVal));
    return (PyAcViewportScale)rtVal;
}

void PyIAcadPViewportImpl::SetStandardScale(PyAcViewportScale val) const
{
    PyThrowBadHr(impObj()->put_StandardScale((AcViewportScale)val));
}

double PyIAcadPViewportImpl::GetCustomScale() const
{
    double rtVal = 0.0;
    PyThrowBadHr(impObj()->get_CustomScale(&rtVal));
    return rtVal;
}

void PyIAcadPViewportImpl::SetCustomScale(double val) const
{
    PyThrowBadHr(impObj()->put_CustomScale(val));
}

CString PyIAcadPViewportImpl::GetStyleSheet() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_StyleSheet(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadPViewportImpl::SetStyleSheet(const CString& val) const
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

void PyIAcadPViewportImpl::SetUCSPerViewport(bool UCSSaved) const
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

void PyIAcadPViewportImpl::SetSnapBasePoint(const AcGePoint2d& val) const
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

void PyIAcadPViewportImpl::SetSnapOn(bool UCSSaved) const
{
    PyThrowBadHr(impObj()->put_SnapOn(UCSSaved ? VARIANT_TRUE : VARIANT_FALSE));
}

double PyIAcadPViewportImpl::GetSnapRotationAngle() const
{
    double rtVal = 0.0;
    PyThrowBadHr(impObj()->get_SnapRotationAngle(&rtVal));
    return rtVal;
}

void PyIAcadPViewportImpl::SetSnapRotationAngle(double val) const
{
    PyThrowBadHr(impObj()->put_SnapRotationAngle(val));
}

bool PyIAcadPViewportImpl::GetUCSIconOn() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_UCSIconOn(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPViewportImpl::SetUCSIconOn(bool bIconOn) const
{
    PyThrowBadHr(impObj()->put_UCSIconOn(bIconOn ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadPViewportImpl::GetUCSIconAtOrigin() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_UCSIconAtOrigin(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPViewportImpl::SetUCSIconAtOrigin(bool bIconAtOrigin) const
{
    PyThrowBadHr(impObj()->put_UCSIconAtOrigin(bIconAtOrigin ? VARIANT_TRUE : VARIANT_FALSE));
}

void PyIAcadPViewportImpl::GetGridSpacing(double& XSpacing, double& YSpacing) const
{
    PyThrowBadHr(impObj()->GetGridSpacing(&XSpacing, &YSpacing));
}

void PyIAcadPViewportImpl::SetGridSpacing(double XSpacing, double YSpacing) const
{
    PyThrowBadHr(impObj()->SetGridSpacing(XSpacing, YSpacing));
}

void PyIAcadPViewportImpl::GetSnapSpacing(double& XSpacing, double& YSpacing) const
{
    PyThrowBadHr(impObj()->GetSnapSpacing(&XSpacing, &YSpacing));
}

void PyIAcadPViewportImpl::SetSnapSpacing(double XSpacing, double YSpacing) const
{
    PyThrowBadHr(impObj()->SetSnapSpacing(XSpacing, YSpacing));
}

void PyIAcadPViewportImpl::Display(bool bStatus) const
{
    PyThrowBadHr(impObj()->Display(bStatus ? VARIANT_TRUE : VARIANT_FALSE));
}

double PyIAcadPViewportImpl::GetTwistAngle() const
{
    double rtVal = 0.0;
    PyThrowBadHr(impObj()->get_TwistAngle(&rtVal));
    return rtVal;
}

void PyIAcadPViewportImpl::SetTwistAngle(double val) const
{
    PyThrowBadHr(impObj()->put_TwistAngle(val));
}

double PyIAcadPViewportImpl::GetLensLength() const
{
    double rtVal = 0.0;
    PyThrowBadHr(impObj()->get_LensLength(&rtVal));
    return rtVal;
}

void PyIAcadPViewportImpl::SetLensLength(double val) const
{
    PyThrowBadHr(impObj()->put_LensLength(val));
}

bool PyIAcadPViewportImpl::GetRemoveHiddenLines() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_RemoveHiddenLines(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPViewportImpl::SetRemoveHiddenLines(bool bRemoval) const
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

void PyIAcadPViewportImpl::SetTarget(const AcGePoint3d& val) const
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

void PyIAcadPViewportImpl::SetArcSmoothness(long val) const
{
    PyThrowBadHr(impObj()->put_ArcSmoothness(val));
}

int PyIAcadPViewportImpl::GetVisualStyle() const
{
    int rtVal = 0;
    PyThrowBadHr(impObj()->get_VisualStyle(&rtVal));
    return rtVal;
}

void PyIAcadPViewportImpl::SetVisualStyle(int val) const
{
    PyThrowBadHr(impObj()->put_VisualStyle(val));
}

int PyIAcadPViewportImpl::GetShadePlot() const
{
    int rtVal = 0;
    PyThrowBadHr(impObj()->get_ShadePlot(&rtVal));
    return rtVal;
}

void PyIAcadPViewportImpl::SetShadePlot(int val) const
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
#if defined(_GRXTARGET250)
    LONG rtVal = 0;
#else
    LONG_PTR rtVal = 0;
#endif
    PyThrowBadHr(impObj()->get_LabelBlockId(&rtVal));
    AcDbObjectId id;
    id.setFromOldId((LONG_PTR)rtVal);
    return id;
}

void PyIAcadPViewportImpl::SetLabelBlockId(const AcDbObjectId& id) const
{
#if defined(_GRXTARGET250)
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

void PyIAcadPViewportImpl::SyncModelView() const
{
    PyThrowBadHr(impObj()->SyncModelView());
}

int PyIAcadPViewportImpl::GetStandardScale2() const
{
    int rtVal = 0;
    PyThrowBadHr(impObj()->get_StandardScale2(&rtVal));
    return rtVal;
}

void PyIAcadPViewportImpl::SetStandardScale2(int val) const
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
    std::array<double, 12> doubles{};
    PyThrowBadHr(VariantToDoubleArray(coords, doubles.data(), doubles.size(), &pcElem));
    AcGePoint3dArray pnts;
    pnts.append(AcGePoint3d{ doubles.at(0),doubles.at(1),doubles.at(2) });
    pnts.append(AcGePoint3d{ doubles.at(3),doubles.at(4),doubles.at(5) });
    pnts.append(AcGePoint3d{ doubles.at(6),doubles.at(7),doubles.at(8) });
    pnts.append(AcGePoint3d{ doubles.at(9),doubles.at(10),doubles.at(11) });
    return pnts;
}

void PyIAcad3DFaceImpl::SetCoordinates(const AcGePoint3d& p1, const AcGePoint3d& p2, const AcGePoint3d& p3, const AcGePoint3d& p4) const
{
    constexpr size_t sz = sizeof(AcGePoint3d);
    std::array<double, 12> doubles{};
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

void PyIAcad3DFaceImpl::SetInvisibleEdge(int index, bool flag) const
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

void PyIAcad3DFaceImpl::SetCoordinate(int index, const AcGePoint3d& val) const
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

void PyIAcadPolygonMeshImpl::SetCoordinates(const Point3dCoordinates& coords) const
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

void PyIAcadPolygonMeshImpl::SetMClose(bool val) const
{
    PyThrowBadHr(impObj()->put_MClose(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadPolygonMeshImpl::GetNClose() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_NClose(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPolygonMeshImpl::SetNClose(bool val) const
{
    PyThrowBadHr(impObj()->put_NClose(val ? VARIANT_TRUE : VARIANT_FALSE));
}

long PyIAcadPolygonMeshImpl::GetMDensity() const
{
    long rtVal = 0;
    PyThrowBadHr(impObj()->get_MDensity(&rtVal));
    return rtVal;
}

void PyIAcadPolygonMeshImpl::SetMDensity(long val) const
{
    PyThrowBadHr(impObj()->put_MDensity(val));
}

long PyIAcadPolygonMeshImpl::GetNDensity() const
{
    long rtVal = 0;
    PyThrowBadHr(impObj()->get_NDensity(&rtVal));
    return rtVal;
}

void PyIAcadPolygonMeshImpl::SetNDensity(long val) const
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

void PyIAcadPolygonMeshImpl::SetType(PyAcPolymeshType val) const
{
    PyThrowBadHr(impObj()->put_Type((AcPolymeshType)val));
}

void PyIAcadPolygonMeshImpl::AppendVertex(const AcGePoint3d& val) const
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

void PyIAcadPolygonMeshImpl::SetCoordinate(int index, const AcGePoint3d& val) const
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

void PyIAcad3DPolylineImpl::SetCoordinates(const Point3dCoordinates& coords) const
{
    _variant_t vtcoords;
    PyThrowBadHr(AcGePoint3dsToVariant(vtcoords, coords));
    PyThrowBadHr(impObj()->put_Coordinates(vtcoords));
}

void PyIAcad3DPolylineImpl::AppendVertex(const AcGePoint3d& val) const
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

void PyIAcad3DPolylineImpl::SetCoordinate(int index, const AcGePoint3d& val) const
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

void PyIAcad3DPolylineImpl::SetType(PyAc3DPolylineType val) const
{
    PyThrowBadHr(impObj()->put_Type((Ac3DPolylineType)val));
}

bool PyIAcad3DPolylineImpl::GetClosed() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_Closed(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcad3DPolylineImpl::SetClosed(bool val) const
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

void PyIAcadArcImpl::SetCenter(const AcGePoint3d& val) const
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

void PyIAcadArcImpl::SetRadius(double val) const
{
    PyThrowBadHr(impObj()->put_Radius(val));
}

double PyIAcadArcImpl::GetStartAngle() const
{
    double rtVal = 0.0;
    PyThrowBadHr(impObj()->get_StartAngle(&rtVal));
    return rtVal;
}

void PyIAcadArcImpl::SetStartAngle(double val) const
{
    PyThrowBadHr(impObj()->put_StartAngle(val));
}

double PyIAcadArcImpl::GetEndAngle() const
{
    double rtVal = 0.0;
    PyThrowBadHr(impObj()->get_EndAngle(&rtVal));
    return rtVal;
}

void PyIAcadArcImpl::SetEndAngle(double val) const
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

void PyIAcadArcImpl::SetThickness(double val) const
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

void PyIAcadArcImpl::SetNormal(const AcGeVector3d& val) const
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

void PyIAcadAttributeImpl::SetFieldLength(long val) const
{
    PyThrowBadHr(impObj()->put_FieldLength(val));
}

CString PyIAcadAttributeImpl::GetTagString() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_TagString(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadAttributeImpl::SetTagString(const CString& val) const
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

void PyIAcadAttributeImpl::SetPromptString(const CString& val) const
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

void PyIAcadAttributeImpl::SetTextString(const CString& val) const
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

void PyIAcadAttributeImpl::SetStyleName(const CString& val) const
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

void PyIAcadAttributeImpl::SetAlignment(PyAcAlignment val) const
{
    PyThrowBadHr(impObj()->put_Alignment((AcAlignment)val));
}

PyAcHorizontalAlignment PyIAcadAttributeImpl::GetHorizontalAlignment() const
{
    AcHorizontalAlignment rtVal = (AcHorizontalAlignment)PyAcHorizontalAlignment::pyacHorizontalAlignmentLeft;
    PyThrowBadHr(impObj()->get_HorizontalAlignment(&rtVal));
    return (PyAcHorizontalAlignment)rtVal;
}

void PyIAcadAttributeImpl::SetHorizontalAlignment(PyAcHorizontalAlignment val) const
{
    PyThrowBadHr(impObj()->put_HorizontalAlignment((AcHorizontalAlignment)val));
}

PyAcVerticalAlignment PyIAcadAttributeImpl::GetVerticalAlignment() const
{
    AcVerticalAlignment rtVal = (AcVerticalAlignment)PyAcVerticalAlignment::pyacVerticalAlignmentBaseline;
    PyThrowBadHr(impObj()->get_VerticalAlignment(&rtVal));
    return (PyAcVerticalAlignment)rtVal;
}

void PyIAcadAttributeImpl::SetVerticalAlignment(PyAcVerticalAlignment val) const
{
    PyThrowBadHr(impObj()->put_VerticalAlignment((AcVerticalAlignment)val));
}

double PyIAcadAttributeImpl::GetHeight() const
{
    double rtVal = 0;
    PyThrowBadHr(impObj()->get_Height(&rtVal));
    return rtVal;
}

void PyIAcadAttributeImpl::SetHeight(double val) const
{
    PyThrowBadHr(impObj()->put_Height(val));
}

double PyIAcadAttributeImpl::GetRotation() const
{
    double rtVal = 0;
    PyThrowBadHr(impObj()->get_Rotation(&rtVal));
    return rtVal;
}

void PyIAcadAttributeImpl::SetRotation(double val) const
{
    PyThrowBadHr(impObj()->put_Rotation(val));
}

double PyIAcadAttributeImpl::GetScaleFactor() const
{
    double rtVal = 0;
    PyThrowBadHr(impObj()->get_ScaleFactor(&rtVal));
    return rtVal;
}

void PyIAcadAttributeImpl::SetScaleFactor(double val) const
{
    PyThrowBadHr(impObj()->put_ScaleFactor(val));
}

double PyIAcadAttributeImpl::GetObliqueAngle() const
{
    double rtVal = 0;
    PyThrowBadHr(impObj()->get_ObliqueAngle(&rtVal));
    return rtVal;
}

void PyIAcadAttributeImpl::SetObliqueAngle(double val) const
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

void PyIAcadAttributeImpl::SetTextAlignmentPoint(const AcGePoint3d& val) const
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

void PyIAcadAttributeImpl::SetInsertionPoint(const AcGePoint3d& val) const
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

void PyIAcadAttributeImpl::SetNormal(const AcGeVector3d& val) const
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

void PyIAcadAttributeImpl::SetTextGenerationFlag(long val) const
{
    PyThrowBadHr(impObj()->put_TextGenerationFlag(val));
}

double PyIAcadAttributeImpl::GetThickness() const
{
    double rtVal = 0.0;
    PyThrowBadHr(impObj()->get_Thickness(&rtVal));
    return rtVal;
}

void PyIAcadAttributeImpl::SetThickness(double val) const
{
    PyThrowBadHr(impObj()->put_Thickness(val));
}

long PyIAcadAttributeImpl::GetMode() const
{
    long rtVal = 0;
    PyThrowBadHr(impObj()->get_Mode(&rtVal));
    return rtVal;
}

void PyIAcadAttributeImpl::SetMode(long val) const
{
    PyThrowBadHr(impObj()->put_Mode(val));
}

bool PyIAcadAttributeImpl::GetUpsideDown() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_UpsideDown(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadAttributeImpl::SetUpsideDown(bool val) const
{
    PyThrowBadHr(impObj()->put_UpsideDown(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadAttributeImpl::GetBackward() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_Backward(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadAttributeImpl::SetBackward(bool val) const
{
    PyThrowBadHr(impObj()->put_Backward(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadAttributeImpl::GetInvisible() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_Invisible(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadAttributeImpl::SetInvisible(bool val) const
{
    PyThrowBadHr(impObj()->put_Invisible(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadAttributeImpl::GetConstant() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_Constant(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadAttributeImpl::SetConstant(bool val) const
{
    PyThrowBadHr(impObj()->put_Constant(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadAttributeImpl::GetVerify() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_Verify(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadAttributeImpl::SetVerify(bool val) const
{
    PyThrowBadHr(impObj()->put_Verify(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadAttributeImpl::GetPreset() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_Preset(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadAttributeImpl::SetPreset(bool val) const
{
    PyThrowBadHr(impObj()->put_Preset(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadAttributeImpl::GetLockPosition() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_LockPosition(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadAttributeImpl::SetLockPosition(bool val) const
{
    PyThrowBadHr(impObj()->put_LockPosition(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadAttributeImpl::GetMTextAttribute() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_MTextAttribute(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadAttributeImpl::SetMTextAttribute(bool val) const
{
    PyThrowBadHr(impObj()->put_MTextAttribute(val ? VARIANT_TRUE : VARIANT_FALSE));
}

CString PyIAcadAttributeImpl::GetMTextAttributeContent() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_MTextAttributeContent(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadAttributeImpl::SetMTextAttributeContent(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_MTextAttributeContent(bstrval));
}

void PyIAcadAttributeImpl::UpdateMTextAttribute() const
{
    PyThrowBadHr(impObj()->UpdateMTextAttribute());
}

double PyIAcadAttributeImpl::GetMTextBoundaryWidth() const
{
    double rtVal = 0;
    PyThrowBadHr(impObj()->get_MTextBoundaryWidth(&rtVal));
    return rtVal;
}

void PyIAcadAttributeImpl::SetMTextBoundaryWidth(double val) const
{
    PyThrowBadHr(impObj()->put_MTextBoundaryWidth(val));
}

PyAcDrawingDirection PyIAcadAttributeImpl::GetMTextDrawingDirection() const
{
    AcDrawingDirection rtVal = (AcDrawingDirection)PyAcDrawingDirection::pyacLeftToRight;
    PyThrowBadHr(impObj()->get_MTextDrawingDirection(&rtVal));
    return (PyAcDrawingDirection)rtVal;
}

void PyIAcadAttributeImpl::SetMTextDrawingDirection(PyAcDrawingDirection val) const
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

void PyIAcadAttributeReferenceImpl::SetHeight(double val) const
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

void PyIAcadAttributeReferenceImpl::SetAlignment(PyAcAlignment val) const
{
    PyThrowBadHr(impObj()->put_Alignment((AcAlignment)val));
}

void PyIAcadAttributeReferenceImpl::SetHorizontalAlignment(PyAcHorizontalAlignment val) const
{
    PyThrowBadHr(impObj()->put_HorizontalAlignment((AcHorizontalAlignment)val));
}

PyAcVerticalAlignment PyIAcadAttributeReferenceImpl::GetVerticalAlignment() const
{
    AcVerticalAlignment rtVal = (AcVerticalAlignment)PyAcVerticalAlignment::pyacVerticalAlignmentBaseline;
    PyThrowBadHr(impObj()->get_VerticalAlignment(&rtVal));
    return (PyAcVerticalAlignment)rtVal;
}

void PyIAcadAttributeReferenceImpl::SetVerticalAlignment(PyAcVerticalAlignment val) const
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

void PyIAcadAttributeReferenceImpl::SetInsertionPoint(const AcGePoint3d& val) const
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

void PyIAcadAttributeReferenceImpl::SetNormal(const AcGeVector3d& val) const
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

void PyIAcadAttributeReferenceImpl::SetObliqueAngle(double val) const
{
    PyThrowBadHr(impObj()->put_ObliqueAngle(val));
}

double PyIAcadAttributeReferenceImpl::GetRotation() const
{
    double rtVal = 0;
    PyThrowBadHr(impObj()->get_Rotation(&rtVal));
    return rtVal;
}

void PyIAcadAttributeReferenceImpl::SetRotation(double val) const
{
    PyThrowBadHr(impObj()->put_Rotation(val));
}

double PyIAcadAttributeReferenceImpl::GetScaleFactor() const
{
    double rtVal = 0;
    PyThrowBadHr(impObj()->get_ScaleFactor(&rtVal));
    return rtVal;
}

void PyIAcadAttributeReferenceImpl::SetScaleFactor(double val) const
{
    PyThrowBadHr(impObj()->put_ScaleFactor(val));
}

CString PyIAcadAttributeReferenceImpl::GetStyleName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_StyleName(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadAttributeReferenceImpl::SetStyleName(const CString& val) const
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

void PyIAcadAttributeReferenceImpl::SetTagString(const CString& val) const
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

void PyIAcadAttributeReferenceImpl::SetTextAlignmentPoint(const AcGePoint3d& val) const
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

void PyIAcadAttributeReferenceImpl::SetTextGenerationFlag(long val) const
{
    PyThrowBadHr(impObj()->put_TextGenerationFlag(val));
}

CString PyIAcadAttributeReferenceImpl::GetTextString() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_TextString(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadAttributeReferenceImpl::SetTextString(const CString& val) const
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

void PyIAcadAttributeReferenceImpl::SetThickness(double val) const
{
    PyThrowBadHr(impObj()->put_Thickness(val));
}

long PyIAcadAttributeReferenceImpl::GetFieldLength() const
{
    long rtVal = 0;
    PyThrowBadHr(impObj()->get_FieldLength(&rtVal));
    return rtVal;
}

void PyIAcadAttributeReferenceImpl::SetFieldLength(long val) const
{
    PyThrowBadHr(impObj()->put_FieldLength(val));
}

bool PyIAcadAttributeReferenceImpl::GetUpsideDown() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_UpsideDown(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadAttributeReferenceImpl::SetUpsideDown(bool val) const
{
    PyThrowBadHr(impObj()->put_UpsideDown(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadAttributeReferenceImpl::GetBackward() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_Backward(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadAttributeReferenceImpl::SetBackward(bool val) const
{
    PyThrowBadHr(impObj()->put_Backward(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadAttributeReferenceImpl::GetInvisible() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_Invisible(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadAttributeReferenceImpl::SetInvisible(bool val) const
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

void PyIAcadAttributeReferenceImpl::SetMTextAttribute(bool val) const
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

void PyIAcadAttributeReferenceImpl::SetMTextAttributeContent(const CString& val) const
{
#if defined(_GRXTARGET250)
    throw PyNotimplementedByHost{};
#else
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_MTextAttributeContent(bstrval));
#endif
}

void PyIAcadAttributeReferenceImpl::UpdateMTextAttribute() const
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

void PyIAcadAttributeReferenceImpl::SetMTextBoundaryWidth(double val) const
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

void PyIAcadAttributeReferenceImpl::SetMTextDrawingDirection(PyAcDrawingDirection val) const
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

PyIAcad3DSolidPtr PyIAcad3DSolidImpl::CheckInterference(const PyIAcad3DSolidImpl& solid, bool createInterferenceSolid, bool& outSolidsInterfere) const
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

std::unique_ptr<PyIAcad3DSolidImpl> PyIAcad3DSolidImpl::SliceSolid(const AcGePoint3d& p1, const AcGePoint3d& p2, const AcGePoint3d& p3, bool negative) const
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

PyIAcadRegionPtr PyIAcad3DSolidImpl::SectionSolid(const AcGePoint3d& p1, const AcGePoint3d& p2, const AcGePoint3d& p3) const
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

void PyIAcad3DSolidImpl::SetPosition(const AcGePoint3d& val) const
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

void PyIAcad3DSolidImpl::SetHistory(bool val) const
{
    PyThrowBadHr(impObj()->put_History(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcad3DSolidImpl::GetShowHistory() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_ShowHistory(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcad3DSolidImpl::SetShowHistory(bool val) const
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

void PyIAcadCircleImpl::SetCenter(const AcGePoint3d& val) const
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

void PyIAcadCircleImpl::SetRadius(double val) const
{
    PyThrowBadHr(impObj()->put_Radius(val));
}

double PyIAcadCircleImpl::GetDiameter() const
{
    double rtVal;
    PyThrowBadHr(impObj()->get_Diameter(&rtVal));
    return rtVal;
}

void PyIAcadCircleImpl::SetDiameter(double val) const
{
    PyThrowBadHr(impObj()->put_Diameter(val));
}

double PyIAcadCircleImpl::GetCircumference() const
{
    double rtVal;
    PyThrowBadHr(impObj()->get_Circumference(&rtVal));
    return rtVal;
}

void PyIAcadCircleImpl::SetCircumference(double val) const
{
    PyThrowBadHr(impObj()->put_Circumference(val));
}

double PyIAcadCircleImpl::GetArea() const
{
    double rtVal;
    PyThrowBadHr(impObj()->get_Area(&rtVal));
    return rtVal;
}

void PyIAcadCircleImpl::SetArea(double val) const
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

void PyIAcadCircleImpl::SetNormal(const AcGeVector3d& val) const
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

void PyIAcadCircleImpl::SetThickness(double val) const
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

AcGePoint3d PyIAcadEllipseImpl::GetStartPoint() const
{
    _variant_t vtval;
    AcGePoint3d rtVal;
    PyThrowBadHr(impObj()->get_StartPoint(&vtval));
    PyThrowBadHr(VariantToAcGePoint3d(vtval, rtVal));
    return rtVal;
}

AcGePoint3d PyIAcadEllipseImpl::GetEndPoint() const
{
    _variant_t vtval;
    AcGePoint3d rtVal;
    PyThrowBadHr(impObj()->get_EndPoint(&vtval));
    PyThrowBadHr(VariantToAcGePoint3d(vtval, rtVal));
    return rtVal;
}

AcGePoint3d PyIAcadEllipseImpl::GetCenter() const
{
    _variant_t vtval;
    AcGePoint3d rtVal;
    PyThrowBadHr(impObj()->get_Center(&vtval));
    PyThrowBadHr(VariantToAcGePoint3d(vtval, rtVal));
    return rtVal;
}

void PyIAcadEllipseImpl::SetCenter(const AcGePoint3d& val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGePoint3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_Center(vtval));
}

double PyIAcadEllipseImpl::GetMajorRadius() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_MajorRadius(&rtval));
    return rtval;
}

void PyIAcadEllipseImpl::SetMajorRadius(double val) const
{
    PyThrowBadHr(impObj()->put_MajorRadius(val));
}

double PyIAcadEllipseImpl::GetMinorRadius() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_MinorRadius(&rtval));
    return rtval;
}

void PyIAcadEllipseImpl::SetMinorRadius(double val) const
{
    PyThrowBadHr(impObj()->put_MinorRadius(val));
}

double PyIAcadEllipseImpl::GetRadiusRatio() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_RadiusRatio(&rtval));
    return rtval;
}

void PyIAcadEllipseImpl::SetRadiusRatio(double val) const
{
    PyThrowBadHr(impObj()->put_RadiusRatio(val));
}

double PyIAcadEllipseImpl::GetStartAngle() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_StartAngle(&rtval));
    return rtval;
}

void PyIAcadEllipseImpl::SetStartAngle(double val) const
{
    PyThrowBadHr(impObj()->put_StartAngle(val));
}

double PyIAcadEllipseImpl::GetEndAngle() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_EndAngle(&rtval));
    return rtval;
}

void PyIAcadEllipseImpl::SetEndAngle(double val) const
{
    PyThrowBadHr(impObj()->put_EndAngle(val));
}

double PyIAcadEllipseImpl::GetStartParameter() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_StartParameter(&rtval));
    return rtval;
}

void PyIAcadEllipseImpl::SetStartParameter(double val) const
{
    PyThrowBadHr(impObj()->put_StartParameter(val));
}

double PyIAcadEllipseImpl::GetEndParameter() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_EndParameter(&rtval));
    return rtval;
}

void PyIAcadEllipseImpl::SetEndParameter(double val) const
{
    PyThrowBadHr(impObj()->put_EndParameter(val));
}

AcGeVector3d PyIAcadEllipseImpl::GetMajorAxis() const
{
    _variant_t vtval;
    AcGeVector3d rtVal;
    PyThrowBadHr(impObj()->get_MajorAxis(&vtval));
    PyThrowBadHr(VariantToAcGeVector3d(vtval, rtVal));
    return rtVal;
}

void PyIAcadEllipseImpl::SetMajorAxis(AcGeVector3d val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGeVector3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_MajorAxis(vtval));
}

AcGeVector3d PyIAcadEllipseImpl::GetMinorAxis() const
{
    _variant_t vtval;
    AcGeVector3d rtVal;
    PyThrowBadHr(impObj()->get_MinorAxis(&vtval));
    PyThrowBadHr(VariantToAcGeVector3d(vtval, rtVal));
    return rtVal;
}

AcGeVector3d PyIAcadEllipseImpl::GetNormal() const
{
    _variant_t vtval;
    AcGeVector3d rtVal;
    PyThrowBadHr(impObj()->get_Normal(&vtval));
    PyThrowBadHr(VariantToAcGeVector3d(vtval, rtVal));
    return rtVal;
}

void PyIAcadEllipseImpl::SetNormal(AcGeVector3d val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGeVector3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_Normal(vtval));
}

double PyIAcadEllipseImpl::GetArea() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_Area(&rtval));
    return rtval;
}

PyIAcadEntityPtrArray PyIAcadEllipseImpl::Offset(double val) const
{
    _variant_t vtents;
    PyIAcadEntityPtrArray vec;
    PyThrowBadHr(impObj()->Offset(val, &vtents.GetVARIANT()));
    PyThrowBadHr(VariantToPyIAcadEntityPtrArray(vtents, vec));
    return vec;
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

Point3dCoordinates PyIAcadLeaderImpl::GetCoordinates() const
{
    _variant_t vtcoords;
    Point3dCoordinates coords;
    PyThrowBadHr(impObj()->get_Coordinates(&vtcoords.GetVARIANT()));
    PyThrowBadHr(VariantToAcGePoint3ds(vtcoords, coords));
    return coords;
}

void PyIAcadLeaderImpl::SetCoordinates(const Point3dCoordinates& coords) const
{
    _variant_t vtcoords;
    PyThrowBadHr(AcGePoint3dsToVariant(vtcoords, coords));
    PyThrowBadHr(impObj()->put_Coordinates(vtcoords));
}

AcGeVector3d PyIAcadLeaderImpl::GetNormal() const
{
    _variant_t vtval;
    AcGeVector3d rtVal;
    PyThrowBadHr(impObj()->get_Normal(&vtval));
    PyThrowBadHr(VariantToAcGeVector3d(vtval, rtVal));
    return rtVal;
}

CString PyIAcadLeaderImpl::GetStyleName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_StyleName(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadLeaderImpl::SetStyleName(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_StyleName(bstrval));
}

PyAcLeaderType PyIAcadLeaderImpl::GetType() const
{
    AcLeaderType rtVal = (AcLeaderType)PyAcLeaderType::pyacLineNoArrow;
    PyThrowBadHr(impObj()->get_Type(&rtVal));
    return (PyAcLeaderType)rtVal;
}

void PyIAcadLeaderImpl::SetType(PyAcLeaderType val) const
{
    PyThrowBadHr(impObj()->put_Type((AcLeaderType)val));
}

void PyIAcadLeaderImpl::Evaluate() const
{
    PyThrowBadHr(impObj()->Evaluate());
}

AcGePoint3d PyIAcadLeaderImpl::GetCoordinate(int index) const
{
    _variant_t vtval;
    AcGePoint3d rtVal;
    PyThrowBadHr(impObj()->get_Coordinate(index, &vtval));
    PyThrowBadHr(VariantToAcGePoint3d(vtval, rtVal));
    return rtVal;
}

void PyIAcadLeaderImpl::SetCoordinate(int index, const AcGePoint3d& val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGePoint3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_Coordinate(index, vtval));
}

PyIAcadEntityPtr PyIAcadLeaderImpl::GetAnnotation() const
{
    IAcadEntity* ptr = nullptr;
    PyThrowBadHr(impObj()->get_Annotation(&ptr));
    return std::make_unique<PyIAcadEntityImpl>(ptr);
}

void PyIAcadLeaderImpl::SetAnnotation(const PyIAcadEntityImpl& val) const
{
    PyThrowBadHr(impObj()->put_Annotation(val.impObj()));
}

double PyIAcadLeaderImpl::GetArrowheadSize() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_ArrowheadSize(&rtval));
    return rtval;
}

void PyIAcadLeaderImpl::SetArrowheadSize(double val) const
{
    PyThrowBadHr(impObj()->put_ArrowheadSize(val));
}

PyAcDimArrowheadType PyIAcadLeaderImpl::GetArrowheadType() const
{
    AcDimArrowheadType rtVal = (AcDimArrowheadType)PyAcDimArrowheadType::pyacArrowDefault;
    PyThrowBadHr(impObj()->get_ArrowheadType(&rtVal));
    return (PyAcDimArrowheadType)rtVal;
}

void PyIAcadLeaderImpl::SetArrowheadType(PyAcDimArrowheadType val) const
{
    PyThrowBadHr(impObj()->put_ArrowheadType((AcDimArrowheadType)val));
}

PyAcColor PyIAcadLeaderImpl::GetDimensionLineColor() const
{
    AcColor rtVal = (AcColor)PyAcColor::pyacRed;
    PyThrowBadHr(impObj()->get_DimensionLineColor(&rtVal));
    return (PyAcColor)rtVal;
}

void PyIAcadLeaderImpl::SetDimensionLineColor(PyAcColor val) const
{
    PyThrowBadHr(impObj()->put_DimensionLineColor((AcColor)val));
}

PyAcLineWeight PyIAcadLeaderImpl::GetDimensionLineWeight() const
{
    AcLineWeight rtVal = (AcLineWeight)PyAcLineWeight::pyacLnWt000;
    PyThrowBadHr(impObj()->get_DimensionLineWeight(&rtVal));
    return (PyAcLineWeight)rtVal;
}

void PyIAcadLeaderImpl::SetDimensionLineWeight(PyAcLineWeight val) const
{
    PyThrowBadHr(impObj()->put_DimensionLineWeight((AcLineWeight)val));
}

double PyIAcadLeaderImpl::GetScaleFactor() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_ScaleFactor(&rtval));
    return rtval;
}

void PyIAcadLeaderImpl::SetScaleFactor(double val) const
{
    PyThrowBadHr(impObj()->put_ScaleFactor(val));
}

PyAcDimVerticalJustification PyIAcadLeaderImpl::GetVerticalTextPosition() const
{
    AcDimVerticalJustification rtVal = (AcDimVerticalJustification)PyAcDimVerticalJustification::pyacVertCentered;
    PyThrowBadHr(impObj()->get_VerticalTextPosition(&rtVal));
    return (PyAcDimVerticalJustification)rtVal;
}

void PyIAcadLeaderImpl::SetVerticalTextPosition(PyAcDimVerticalJustification val) const
{
    PyThrowBadHr(impObj()->put_VerticalTextPosition((AcDimVerticalJustification)val));
}

double PyIAcadLeaderImpl::GetTextGap() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_TextGap(&rtval));
    return rtval;
}

void PyIAcadLeaderImpl::SetTextGap(double val) const
{
    PyThrowBadHr(impObj()->put_TextGap(val));
}

CString PyIAcadLeaderImpl::GetArrowheadBlock() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_ArrowheadBlock(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadLeaderImpl::SetArrowheadBlock(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_ArrowheadBlock(bstrval));
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

CString PyIAcadMTextImpl::GetText() const
{
    AcAxDocLock lock;
    AcDbObjectPointer<AcDbMText> mt(id());
    return mt->text();
}

CString PyIAcadMTextImpl::GetTextString() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_TextString(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadMTextImpl::SetTextString(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_TextString(bstrval));
}

CString PyIAcadMTextImpl::GetStyleName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_StyleName(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadMTextImpl::SetStyleName(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_StyleName(bstrval));
}

PyAcAttachmentPoint PyIAcadMTextImpl::GetAttachmentPoint() const
{
    AcAttachmentPoint rtVal = (AcAttachmentPoint)PyAcAttachmentPoint::pyacAttachmentPointTopLeft;
    PyThrowBadHr(impObj()->get_AttachmentPoint(&rtVal));
    return (PyAcAttachmentPoint)rtVal;
}

void PyIAcadMTextImpl::SetAttachmentPoint(PyAcAttachmentPoint val) const
{
    PyThrowBadHr(impObj()->put_AttachmentPoint((AcAttachmentPoint)val));
}

PyAcDrawingDirection PyIAcadMTextImpl::GetDrawingDirection() const
{
    AcDrawingDirection rtVal = (AcDrawingDirection)PyAcDrawingDirection::pyacLeftToRight;
    PyThrowBadHr(impObj()->get_DrawingDirection(&rtVal));
    return (PyAcDrawingDirection)rtVal;
}

void PyIAcadMTextImpl::SetDrawingDirection(PyAcDrawingDirection val) const
{
    PyThrowBadHr(impObj()->put_DrawingDirection((AcDrawingDirection)val));
}

double PyIAcadMTextImpl::GetWidth() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_Width(&rtval));
    return rtval;
}

void PyIAcadMTextImpl::SetWidth(double val) const
{
    PyThrowBadHr(impObj()->put_Width(val));
}

double PyIAcadMTextImpl::GetHeight() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_Height(&rtval));
    return rtval;
}

void PyIAcadMTextImpl::SetHeight(double val) const
{
    PyThrowBadHr(impObj()->put_Height(val));
}

double PyIAcadMTextImpl::GetRotation() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_Rotation(&rtval));
    return rtval;
}

void PyIAcadMTextImpl::SetRotation(double val) const
{
    PyThrowBadHr(impObj()->put_Rotation(val));
}

AcGePoint3d PyIAcadMTextImpl::GetInsertionPoint() const
{
    _variant_t vtval;
    AcGePoint3d rtVal;
    PyThrowBadHr(impObj()->get_InsertionPoint(&vtval));
    PyThrowBadHr(VariantToAcGePoint3d(vtval, rtVal));
    return rtVal;
}

void PyIAcadMTextImpl::SetInsertionPoint(const AcGePoint3d& val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGePoint3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_InsertionPoint(vtval));
}

AcGeVector3d PyIAcadMTextImpl::GetNormal() const
{
    AcGeVector3d val;
    _variant_t coord;
    PyThrowBadHr(impObj()->get_Normal(&coord.GetVARIANT()));
    PyThrowBadHr(VariantToAcGeVector3d(coord, val));
    return val;
}

void PyIAcadMTextImpl::SetNormal(const AcGeVector3d& val) const
{
    _variant_t coord;
    PyThrowBadHr(AcGeVector3dToVariant(coord.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_Normal(coord));
}

double PyIAcadMTextImpl::GetLineSpacingFactor() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_LineSpacingFactor(&rtval));
    return rtval;
}

void PyIAcadMTextImpl::SetLineSpacingFactor(double val) const
{
    PyThrowBadHr(impObj()->put_LineSpacingFactor(val));
}

PyAcLineSpacingStyle PyIAcadMTextImpl::GetLineSpacingStyle() const
{
    AcLineSpacingStyle rtVal = (AcLineSpacingStyle)PyAcAttachmentPoint::pyacAttachmentPointTopLeft;
    PyThrowBadHr(impObj()->get_LineSpacingStyle(&rtVal));
    return (PyAcLineSpacingStyle)rtVal;
}

void PyIAcadMTextImpl::SetLineSpacingStyle(PyAcLineSpacingStyle val) const
{
    PyThrowBadHr(impObj()->put_LineSpacingStyle((AcLineSpacingStyle)val));
}

double PyIAcadMTextImpl::GetLineSpacingDistance() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_LineSpacingDistance(&rtval));
    return rtval;
}

void PyIAcadMTextImpl::SetLineSpacingDistance(double val) const
{
    PyThrowBadHr(impObj()->put_LineSpacingDistance(val));
}

bool PyIAcadMTextImpl::GetBackgroundFill() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_BackgroundFill(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadMTextImpl::SetBackgroundFill(bool val) const
{
    PyThrowBadHr(impObj()->put_BackgroundFill(val ? VARIANT_TRUE : VARIANT_FALSE));
}

CString PyIAcadMTextImpl::GetFieldCode() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->FieldCode(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
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

AcGePoint3d PyIAcadPointImpl::GetCoordinates() const
{
    _variant_t vtval;
    AcGePoint3d rtVal;
    PyThrowBadHr(impObj()->get_Coordinates(&vtval));
    PyThrowBadHr(VariantToAcGePoint3d(vtval, rtVal));
    return rtVal;
}

void PyIAcadPointImpl::SetCoordinates(const AcGePoint3d& val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGePoint3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_Coordinates(vtval));
}

AcGeVector3d PyIAcadPointImpl::GetNormal() const
{
    AcGeVector3d val;
    _variant_t coord;
    PyThrowBadHr(impObj()->get_Normal(&coord.GetVARIANT()));
    PyThrowBadHr(VariantToAcGeVector3d(coord, val));
    return val;
}

void PyIAcadPointImpl::SetNormal(const AcGeVector3d& val) const
{
    _variant_t coord;
    PyThrowBadHr(AcGeVector3dToVariant(coord.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_Normal(coord));
}

double PyIAcadPointImpl::GetThickness() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_Thickness(&rtval));
    return rtval;
}

void PyIAcadPointImpl::SetThickness(double val) const
{
    PyThrowBadHr(impObj()->put_Thickness(val));
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

Point2dCoordinates PyIAcadLWPolylineImpl::GetCoordinates() const
{
    _variant_t vtcoords;
    Point2dCoordinates coords;
    PyThrowBadHr(impObj()->get_Coordinates(&vtcoords));
    PyThrowBadHr(VariantToAcGePoint2ds(vtcoords, coords));
    return coords;
}

void PyIAcadLWPolylineImpl::SetCoordinates(const Point2dCoordinates& coords) const
{
    _variant_t vtcoords;
    PyThrowBadHr(AcGePoint2dsToVariant(vtcoords, coords));
    PyThrowBadHr(impObj()->put_Coordinates(vtcoords));
}

AcGeVector3d PyIAcadLWPolylineImpl::GetNormal() const
{
    AcGeVector3d val;
    _variant_t coord;
    PyThrowBadHr(impObj()->get_Normal(&coord.GetVARIANT()));
    PyThrowBadHr(VariantToAcGeVector3d(coord, val));
    return val;
}

void PyIAcadLWPolylineImpl::SetNormal(const AcGeVector3d& val) const
{
    _variant_t coord;
    PyThrowBadHr(AcGeVector3dToVariant(coord.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_Normal(coord));
}

double PyIAcadLWPolylineImpl::GetThickness() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_Thickness(&rtval));
    return rtval;
}

void PyIAcadLWPolylineImpl::SetThickness(double val) const
{
    PyThrowBadHr(impObj()->put_Thickness(val));
}

void PyIAcadLWPolylineImpl::AddVertex(int index, const AcGePoint2d& coord) const
{
    _variant_t vtcoord;
    PyThrowBadHr(AcGePoint2dToVariant(vtcoord, coord));
    PyThrowBadHr(impObj()->AddVertex(index, vtcoord));
}

PyIAcadEntityPtrArray PyIAcadLWPolylineImpl::Explode() const
{
    _variant_t vtents;
    PyIAcadEntityPtrArray vec;
    PyThrowBadHr(impObj()->Explode(&vtents.GetVARIANT()));
    PyThrowBadHr(VariantToPyIAcadEntityPtrArray(vtents, vec));
    return vec;
}

double PyIAcadLWPolylineImpl::GetBulge(int index) const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->GetBulge(index, &rtval));
    return rtval;
}

void PyIAcadLWPolylineImpl::SetBulge(int index, double val) const
{
    PyThrowBadHr(impObj()->SetBulge(index, val));
}

void PyIAcadLWPolylineImpl::GetWidth(int index, double& startWidth, double& endWidth) const
{
    PyThrowBadHr(impObj()->GetWidth(index, &startWidth, &endWidth));
}

void PyIAcadLWPolylineImpl::SetWidth(int index, double startWidth, double endWidth) const
{
    PyThrowBadHr(impObj()->SetWidth(index, startWidth, endWidth));
}

double PyIAcadLWPolylineImpl::GetConstantWidth() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_ConstantWidth(&rtval));
    return rtval;
}

void PyIAcadLWPolylineImpl::SetConstantWidth(double val) const
{
    PyThrowBadHr(impObj()->put_ConstantWidth(val));
}

PyIAcadEntityPtrArray PyIAcadLWPolylineImpl::Offset(double val) const
{
    _variant_t vtents;
    PyIAcadEntityPtrArray vec;
    PyThrowBadHr(impObj()->Offset(val, &vtents.GetVARIANT()));
    PyThrowBadHr(VariantToPyIAcadEntityPtrArray(vtents, vec));
    return vec;
}

double PyIAcadLWPolylineImpl::GetElevation() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_Elevation(&rtval));
    return rtval;
}

void PyIAcadLWPolylineImpl::SetElevation(double val) const
{
    PyThrowBadHr(impObj()->put_Elevation(val));
}

double PyIAcadLWPolylineImpl::GetArea() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_Area(&rtval));
    return rtval;
}

AcGePoint2d PyIAcadLWPolylineImpl::GetCoordinate(int index) const
{
    _variant_t vtval;
    AcGePoint2d rtVal;
    PyThrowBadHr(impObj()->get_Coordinate(index, &vtval));
    PyThrowBadHr(VariantToAcGePoint2d(vtval, rtVal));
    return rtVal;
}

void PyIAcadLWPolylineImpl::SetCoordinate(int index, const AcGePoint2d& val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGePoint2dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_Coordinate(index, vtval));
}

bool PyIAcadLWPolylineImpl::GetClosed() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_Closed(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadLWPolylineImpl::SetClosed(bool val) const
{
    PyThrowBadHr(impObj()->put_Closed(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadLWPolylineImpl::GetLinetypeGeneration() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_LinetypeGeneration(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadLWPolylineImpl::SetLinetypeGeneration(bool val) const
{
    PyThrowBadHr(impObj()->put_LinetypeGeneration(val ? VARIANT_TRUE : VARIANT_FALSE));
}

double PyIAcadLWPolylineImpl::GetLength() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_Length(&rtval));
    return rtval;
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

Point3dCoordinates PyIAcadPolylineImpl::GetCoordinates() const
{
    _variant_t vtcoords;
    Point3dCoordinates coords;
    PyThrowBadHr(impObj()->get_Coordinates(&vtcoords));
    PyThrowBadHr(VariantToAcGePoint3ds(vtcoords, coords));
    return coords;
}

void PyIAcadPolylineImpl::SetCoordinates(const Point3dCoordinates& coords) const
{
    _variant_t vtcoords;
    PyThrowBadHr(AcGePoint3dsToVariant(vtcoords, coords));
    PyThrowBadHr(impObj()->put_Coordinates(vtcoords));
}

AcGeVector3d PyIAcadPolylineImpl::GetNormal() const
{
    AcGeVector3d val;
    _variant_t coord;
    PyThrowBadHr(impObj()->get_Normal(&coord.GetVARIANT()));
    PyThrowBadHr(VariantToAcGeVector3d(coord, val));
    return val;
}

void PyIAcadPolylineImpl::SetNormal(const AcGeVector3d& val) const
{
    _variant_t coord;
    PyThrowBadHr(AcGeVector3dToVariant(coord.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_Normal(coord));
}

double PyIAcadPolylineImpl::GetThickness() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_Thickness(&rtval));
    return rtval;
}

void PyIAcadPolylineImpl::SetThickness(double val) const
{
    PyThrowBadHr(impObj()->put_Thickness(val));
}

PyIAcadEntityPtrArray PyIAcadPolylineImpl::Explode() const
{
    _variant_t vtents;
    PyIAcadEntityPtrArray vec;
    PyThrowBadHr(impObj()->Explode(&vtents.GetVARIANT()));
    PyThrowBadHr(VariantToPyIAcadEntityPtrArray(vtents, vec));
    return vec;
}

double PyIAcadPolylineImpl::GetBulge(int index) const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->GetBulge(index, &rtval));
    return rtval;
}

void PyIAcadPolylineImpl::SetBulge(int index, double val) const
{
    PyThrowBadHr(impObj()->SetBulge(index, val));
}

void PyIAcadPolylineImpl::GetWidth(int index, double& startWidth, double& endWidth) const
{
    PyThrowBadHr(impObj()->GetWidth(index, &startWidth, &endWidth));
}

void PyIAcadPolylineImpl::SetWidth(int index, double startWidth, double endWidth) const
{
    PyThrowBadHr(impObj()->SetWidth(index, startWidth, endWidth));
}


double PyIAcadPolylineImpl::GetConstantWidth() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_ConstantWidth(&rtval));
    return rtval;
}

void PyIAcadPolylineImpl::SetConstantWidth(double val) const
{
    PyThrowBadHr(impObj()->put_ConstantWidth(val));
}

PyIAcadEntityPtrArray PyIAcadPolylineImpl::Offset(double val) const
{
    _variant_t vtents;
    PyIAcadEntityPtrArray vec;
    PyThrowBadHr(impObj()->Offset(val, &vtents.GetVARIANT()));
    PyThrowBadHr(VariantToPyIAcadEntityPtrArray(vtents, vec));
    return vec;
}

double PyIAcadPolylineImpl::GetElevation() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_Elevation(&rtval));
    return rtval;
}

void PyIAcadPolylineImpl::SetElevation(double val) const
{
    PyThrowBadHr(impObj()->put_Elevation(val));
}

double PyIAcadPolylineImpl::GetArea() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_Area(&rtval));
    return rtval;
}

AcGePoint3d PyIAcadPolylineImpl::GetCoordinate(int index) const
{
    _variant_t vtval;
    AcGePoint3d rtVal;
    PyThrowBadHr(impObj()->get_Coordinate(index, &vtval));
    PyThrowBadHr(VariantToAcGePoint3d(vtval, rtVal));
    return rtVal;
}

void PyIAcadPolylineImpl::SetCoordinate(int index, const AcGePoint3d& val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGePoint3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_Coordinate(index, vtval));
}

bool PyIAcadPolylineImpl::GetClosed() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_Closed(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPolylineImpl::SetClosed(bool val) const
{
    PyThrowBadHr(impObj()->put_Closed(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadPolylineImpl::GetLinetypeGeneration() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_LinetypeGeneration(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPolylineImpl::SetLinetypeGeneration(bool val) const
{
    PyThrowBadHr(impObj()->put_LinetypeGeneration(val ? VARIANT_TRUE : VARIANT_FALSE));
}

double PyIAcadPolylineImpl::GetLength() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_Length(&rtval));
    return rtval;
}

PyAcPolylineType PyIAcadPolylineImpl::GetType() const
{
    AcPolylineType rtVal = (AcPolylineType)PyAcPolylineType::pyacSimplePoly;
    PyThrowBadHr(impObj()->get_Type(&rtVal));
    return (PyAcPolylineType)rtVal;
}

void PyIAcadPolylineImpl::SetType(PyAcPolylineType val) const
{
    PyThrowBadHr(impObj()->put_Type((AcPolylineType)val));
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

AcGePoint3d PyIAcadRayImpl::GetBasePoint() const
{
    _variant_t vtval;
    AcGePoint3d rtVal;
    PyThrowBadHr(impObj()->get_BasePoint(&vtval));
    PyThrowBadHr(VariantToAcGePoint3d(vtval, rtVal));
    return rtVal;
}

void PyIAcadRayImpl::SetBasePoint(const AcGePoint3d& val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGePoint3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_BasePoint(vtval));
}

AcGePoint3d PyIAcadRayImpl::GetSecondPoint() const
{
    _variant_t vtval;
    AcGePoint3d rtVal;
    PyThrowBadHr(impObj()->get_SecondPoint(&vtval));
    PyThrowBadHr(VariantToAcGePoint3d(vtval, rtVal));
    return rtVal;
}

void PyIAcadRayImpl::SetSecondPoint(const AcGePoint3d& val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGePoint3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_SecondPoint(vtval));
}

AcGeVector3d PyIAcadRayImpl::GetDirectionVector() const
{
    _variant_t vtval;
    AcGeVector3d rtVal;
    PyThrowBadHr(impObj()->get_DirectionVector(&vtval));
    PyThrowBadHr(VariantToAcGeVector3d(vtval, rtVal));
    return rtVal;
}

void PyIAcadRayImpl::SetDirectionVector(const AcGeVector3d& val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGeVector3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_SecondPoint(vtval));
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

AcGePoint3d PyIAcadShapeImpl::GetInsertionPoint() const
{
    _variant_t vtval;
    AcGePoint3d rtVal;
    PyThrowBadHr(impObj()->get_InsertionPoint(&vtval));
    PyThrowBadHr(VariantToAcGePoint3d(vtval, rtVal));
    return rtVal;
}

void PyIAcadShapeImpl::SetInsertionPoint(const AcGePoint3d& val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGePoint3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_InsertionPoint(vtval));
}

CString PyIAcadShapeImpl::GetName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Name(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadShapeImpl::SetName(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_Name(bstrval));
}

double PyIAcadShapeImpl::GetHeight() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_Height(&rtval));
    return rtval;
}

void PyIAcadShapeImpl::SetHeight(double val) const
{
    PyThrowBadHr(impObj()->put_Height(val));
}

double PyIAcadShapeImpl::GetRotation() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_Rotation(&rtval));
    return rtval;
}

void PyIAcadShapeImpl::SetRotation(double val) const
{
    PyThrowBadHr(impObj()->put_Rotation(val));
}

double PyIAcadShapeImpl::GetScaleFactor() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_ScaleFactor(&rtval));
    return rtval;
}

void PyIAcadShapeImpl::SetScaleFactor(double val) const
{
    PyThrowBadHr(impObj()->put_ScaleFactor(val));
}

double PyIAcadShapeImpl::GetObliqueAngle() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_ObliqueAngle(&rtval));
    return rtval;
}

void PyIAcadShapeImpl::SetObliqueAngle(double val) const
{
    PyThrowBadHr(impObj()->put_ObliqueAngle(val));
}

AcGeVector3d PyIAcadShapeImpl::GetNormal() const
{
    AcGeVector3d val;
    _variant_t coord;
    PyThrowBadHr(impObj()->get_Normal(&coord.GetVARIANT()));
    PyThrowBadHr(VariantToAcGeVector3d(coord, val));
    return val;
}

void PyIAcadShapeImpl::SetNormal(const AcGeVector3d& val) const
{
    _variant_t coord;
    PyThrowBadHr(AcGeVector3dToVariant(coord.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_Normal(coord));
}

double PyIAcadShapeImpl::GetThickness() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_Thickness(&rtval));
    return rtval;
}

void PyIAcadShapeImpl::SetThickness(double val) const
{
    PyThrowBadHr(impObj()->put_Thickness(val));
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

Point3dCoordinates PyIAcadSolidImpl::GetCoordinates() const
{
    _variant_t vtcoords;
    Point3dCoordinates coords;
    PyThrowBadHr(impObj()->get_Coordinates(&vtcoords));
    PyThrowBadHr(VariantToAcGePoint3ds(vtcoords, coords));
    return coords;
}

void PyIAcadSolidImpl::SetCoordinates(const Point3dCoordinates& coords) const
{
    _variant_t vtcoords;
    PyThrowBadHr(AcGePoint3dsToVariant(vtcoords, coords));
    PyThrowBadHr(impObj()->put_Coordinates(vtcoords));
}

AcGeVector3d PyIAcadSolidImpl::GetNormal() const
{
    AcGeVector3d val;
    _variant_t coord;
    PyThrowBadHr(impObj()->get_Normal(&coord.GetVARIANT()));
    PyThrowBadHr(VariantToAcGeVector3d(coord, val));
    return val;
}

void PyIAcadSolidImpl::SetNormal(const AcGeVector3d& val) const
{
    _variant_t coord;
    PyThrowBadHr(AcGeVector3dToVariant(coord.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_Normal(coord));
}

double PyIAcadSolidImpl::GetThickness() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_Thickness(&rtval));
    return rtval;
}

void PyIAcadSolidImpl::SetThickness(double val) const
{
    PyThrowBadHr(impObj()->put_Thickness(val));
}

AcGePoint3d PyIAcadSolidImpl::GetCoordinate(int index) const
{
    _variant_t vtval;
    AcGePoint3d rtVal;
    PyThrowBadHr(impObj()->get_Coordinate(index, &vtval));
    PyThrowBadHr(VariantToAcGePoint3d(vtval, rtVal));
    return rtVal;
}

void PyIAcadSolidImpl::SetCoordinate(int index, const AcGePoint3d& val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGePoint3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_Coordinate(index, vtval));
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

long PyIAcadSplineImpl::GetNumberOfControlPoints() const
{
    long rtval = 0.0;
    PyThrowBadHr(impObj()->get_NumberOfControlPoints(&rtval));
    return rtval;
}

Point3dCoordinates PyIAcadSplineImpl::GetControlPoints() const
{
    _variant_t vtcoords;
    Point3dCoordinates coords;
    PyThrowBadHr(impObj()->get_ControlPoints(&vtcoords));
    PyThrowBadHr(VariantToAcGePoint3ds(vtcoords, coords));
    return coords;
}

void PyIAcadSplineImpl::SetControlPoints(const Point3dCoordinates& coords) const
{
    _variant_t vtcoords;
    PyThrowBadHr(AcGePoint3dsToVariant(vtcoords, coords));
    PyThrowBadHr(impObj()->put_ControlPoints(vtcoords));
}

Point3dCoordinates PyIAcadSplineImpl::GetFitPoints() const
{
    _variant_t vtcoords;
    Point3dCoordinates coords;
    PyThrowBadHr(impObj()->get_FitPoints(&vtcoords));
    PyThrowBadHr(VariantToAcGePoint3ds(vtcoords, coords));
    return coords;
}

void PyIAcadSplineImpl::SetFitPoints(const Point3dCoordinates& coords) const
{
    _variant_t vtcoords;
    PyThrowBadHr(AcGePoint3dsToVariant(vtcoords, coords));
    PyThrowBadHr(impObj()->put_FitPoints(vtcoords));
}

long PyIAcadSplineImpl::GetDegree() const
{
    long rtval = 0.0;
    PyThrowBadHr(impObj()->get_Degree(&rtval));
    return rtval;
}

bool PyIAcadSplineImpl::GetClosed() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_Closed(&rtVal));
    return rtVal != VARIANT_FALSE;
}

bool PyIAcadSplineImpl::GetIsPlanar() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_IsPlanar(&rtVal));
    return rtVal != VARIANT_FALSE;
}

bool PyIAcadSplineImpl::GetIsRational() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_IsRational(&rtVal));
    return rtVal != VARIANT_FALSE;
}

bool PyIAcadSplineImpl::GetIsPeriodic() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_IsPeriodic(&rtVal));
    return rtVal != VARIANT_FALSE;
}

AcGeVector3d PyIAcadSplineImpl::GetStartTangent() const
{
    _variant_t vtval;
    AcGeVector3d rtVal;
    PyThrowBadHr(impObj()->get_StartTangent(&vtval));
    PyThrowBadHr(VariantToAcGeVector3d(vtval, rtVal));
    return rtVal;
}

void PyIAcadSplineImpl::SetStartTangent(const AcGeVector3d& val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGeVector3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_StartTangent(vtval));
}

AcGeVector3d PyIAcadSplineImpl::GetEndTangent() const
{
    _variant_t vtval;
    AcGeVector3d rtVal;
    PyThrowBadHr(impObj()->get_EndTangent(&vtval));
    PyThrowBadHr(VariantToAcGeVector3d(vtval, rtVal));
    return rtVal;
}

void PyIAcadSplineImpl::SetEndTangent(const AcGeVector3d& val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGeVector3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_EndTangent(vtval));
}

double PyIAcadSplineImpl::GetFitTolerance() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_FitTolerance(&rtval));
    return rtval;
}

void PyIAcadSplineImpl::SetFitTolerance(double val) const
{
    PyThrowBadHr(impObj()->put_FitTolerance(val));
}

double PyIAcadSplineImpl::GetArea() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_Area(&rtval));
    return rtval;
}

AcGePoint3d PyIAcadSplineImpl::GetControlPoint(int index) const
{
    _variant_t vtval;
    AcGePoint3d rtVal;
    PyThrowBadHr(impObj()->GetControlPoint(index, &vtval));
    PyThrowBadHr(VariantToAcGePoint3d(vtval, rtVal));
    return rtVal;
}

void PyIAcadSplineImpl::SetControlPoint(int index, const AcGePoint3d& val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGePoint3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->SetControlPoint(index, vtval));
}

AcGePoint3d PyIAcadSplineImpl::GetFitPoint(int index) const
{
    _variant_t vtval;
    AcGePoint3d rtVal;
    PyThrowBadHr(impObj()->GetFitPoint(index, &vtval));
    PyThrowBadHr(VariantToAcGePoint3d(vtval, rtVal));
    return rtVal;
}

void PyIAcadSplineImpl::SetFitPoint(int index, const AcGePoint3d& val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGePoint3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->SetFitPoint(index, vtval));
}

double PyIAcadSplineImpl::GetWeight(int index) const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->GetWeight(index, &rtval));
    return rtval;
}

void PyIAcadSplineImpl::SetWeight(int index, double val) const
{
    PyThrowBadHr(impObj()->SetWeight(index, val));
}

void PyIAcadSplineImpl::AddFitPoint(int index, const AcGePoint3d& val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGePoint3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->AddFitPoint(index, vtval));
}

void PyIAcadSplineImpl::DeleteFitPoint(int index) const
{
    PyThrowBadHr(impObj()->DeleteFitPoint(index));
}

void PyIAcadSplineImpl::ElevateOrder(int index) const
{
    PyThrowBadHr(impObj()->ElevateOrder(index));
}

PyIAcadEntityPtrArray PyIAcadSplineImpl::Offset(double val) const
{
    _variant_t vtents;
    PyIAcadEntityPtrArray vec;
    PyThrowBadHr(impObj()->Offset(val, &vtents.GetVARIANT()));
    PyThrowBadHr(VariantToPyIAcadEntityPtrArray(vtents, vec));
    return vec;
}

void PyIAcadSplineImpl::PurgeFitData() const
{
    PyThrowBadHr(impObj()->PurgeFitData());
}

void PyIAcadSplineImpl::Reverse() const
{
    PyThrowBadHr(impObj()->Reverse());
}

Vector3dDirections PyIAcadSplineImpl::GetKnots() const
{
    _variant_t vtcoords;
    Vector3dDirections coords;
    PyThrowBadHr(impObj()->get_Knots(&vtcoords));
    PyThrowBadHr(VariantToAcGeVector3ds(vtcoords, coords));
    return coords;
}

void PyIAcadSplineImpl::SetKnots(const Vector3dDirections& coords) const
{
    _variant_t vtcoords;
    PyThrowBadHr(AcGeVector3dsToVariant(vtcoords, coords));
    PyThrowBadHr(impObj()->put_Knots(vtcoords));
}

Doubles PyIAcadSplineImpl::GetWeights() const
{
    _variant_t vtcoords;
    Doubles coords;
    PyThrowBadHr(VariantToDoubleArray(vtcoords, coords));
    PyThrowBadHr(impObj()->put_Knots(vtcoords));
    return coords;
}

void PyIAcadSplineImpl::SetWeights(const Doubles& val) const
{
    _variant_t vtcoords;
    PyThrowBadHr(DoubleArrayToVariant(vtcoords, val));
    PyThrowBadHr(impObj()->put_Weights(vtcoords));
}

PyAcSplineKnotParameterizationType PyIAcadSplineImpl::GetKnotParameterization() const
{
#if defined(_BRXTARGET260) || defined(_GRXTARGET250) || defined(_ZRXTARGET250)
    throw PyNotimplementedByHost{};
#else
    AcSplineKnotParameterizationType rtVal = (AcSplineKnotParameterizationType)PyAcSplineKnotParameterizationType::pyacChord;
    PyThrowBadHr(impObj()->get_KnotParameterization(&rtVal));
    return (PyAcSplineKnotParameterizationType)rtVal;
#endif
}

void PyIAcadSplineImpl::SetKnotParameterization(PyAcSplineKnotParameterizationType val) const
{
#if defined(_BRXTARGET260) || defined(_GRXTARGET250) || defined(_ZRXTARGET250)
    throw PyNotimplementedByHost{};
#else
    PyThrowBadHr(impObj()->put_KnotParameterization((AcSplineKnotParameterizationType)val));
#endif
}

PyAcSplineFrameType PyIAcadSplineImpl::GetSplineFrame() const
{
#if defined(_BRXTARGET260) || defined(_GRXTARGET250) || defined(_ZRXTARGET250)
    throw PyNotimplementedByHost{};
#else
    AcSplineFrameType rtVal = (AcSplineFrameType)PyAcSplineFrameType::pyacShow;
    PyThrowBadHr(impObj()->get_SplineFrame(&rtVal));
    return (PyAcSplineFrameType)rtVal;
#endif
}

void PyIAcadSplineImpl::SetSplineFrame(PyAcSplineFrameType val) const
{
#if defined(_BRXTARGET260) || defined(_GRXTARGET250) || defined(_ZRXTARGET250)
    throw PyNotimplementedByHost{};
#else
    PyThrowBadHr(impObj()->put_SplineFrame((AcSplineFrameType)val));
#endif
}

PyAcSplineMethodType PyIAcadSplineImpl::GetSplineMethod() const
{
#if defined(_BRXTARGET260) || defined(_GRXTARGET250) || defined(_ZRXTARGET250)
    throw PyNotimplementedByHost{};
#else
    AcSplineMethodType rtVal = (AcSplineMethodType)PyAcSplineMethodType::pyacFit;
    PyThrowBadHr(impObj()->get_SplineMethod(&rtVal));
    return (PyAcSplineMethodType)rtVal;
#endif
}

void PyIAcadSplineImpl::SetSplineMethod(PyAcSplineMethodType val) const
{
#if defined(_BRXTARGET260) || defined(_GRXTARGET250) || defined(_ZRXTARGET250)
    throw PyNotimplementedByHost{};
#else
    PyThrowBadHr(impObj()->put_SplineMethod((AcSplineMethodType)val));
#endif
}

long PyIAcadSplineImpl::GetDegree2() const
{
#if defined(_BRXTARGET260) || defined(_GRXTARGET250) || defined(_ZRXTARGET250)
    throw PyNotimplementedByHost{};
#else
    long rtval = 0.0;
    PyThrowBadHr(impObj()->get_Degree2(&rtval));
    return rtval;
#endif
}

void PyIAcadSplineImpl::SetDegree2(long val) const
{
#if defined(_BRXTARGET260) || defined(_GRXTARGET250) || defined(_ZRXTARGET250)
    throw PyNotimplementedByHost{};
#else
    PyThrowBadHr(impObj()->put_Degree2(val));
#endif
}

bool PyIAcadSplineImpl::GetClosed2() const
{
#if defined(_BRXTARGET260) || defined(_GRXTARGET250) || defined(_ZRXTARGET250)
    throw PyNotimplementedByHost{};
#else
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_Closed2(&rtVal));
    return rtVal != VARIANT_FALSE;
#endif
}

void PyIAcadSplineImpl::SetClosed2(bool val) const
{
#if defined(_BRXTARGET260) || defined(_GRXTARGET250) || defined(_ZRXTARGET250)
    throw PyNotimplementedByHost{};
#else
    PyThrowBadHr(impObj()->put_Closed2(val));
#endif
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

CString PyIAcadTextImpl::GetTextString() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_TextString(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadTextImpl::SetTextString(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_TextString(bstrval));
}

CString PyIAcadTextImpl::GetStyleName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_StyleName(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadTextImpl::SetStyleName(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_StyleName(bstrval));
}

PyAcAlignment PyIAcadTextImpl::GetAlignment() const
{
    AcAlignment rtVal = (AcAlignment)PyAcAlignment::pyacAlignmentLeft;
    PyThrowBadHr(impObj()->get_Alignment(&rtVal));
    return (PyAcAlignment)rtVal;
}

void PyIAcadTextImpl::SetAlignment(PyAcAlignment val) const
{
    PyThrowBadHr(impObj()->put_Alignment((AcAlignment)val));
}

PyAcHorizontalAlignment PyIAcadTextImpl::GetHorizontalAlignment() const
{
    AcHorizontalAlignment rtVal = (AcHorizontalAlignment)PyAcHorizontalAlignment::pyacHorizontalAlignmentLeft;
    PyThrowBadHr(impObj()->get_HorizontalAlignment(&rtVal));
    return (PyAcHorizontalAlignment)rtVal;
}

void PyIAcadTextImpl::SetHorizontalAlignment(PyAcHorizontalAlignment val) const
{
    PyThrowBadHr(impObj()->put_HorizontalAlignment((AcHorizontalAlignment)val));
}

PyAcVerticalAlignment PyIAcadTextImpl::GetVerticalAlignment() const
{
    AcVerticalAlignment rtVal = (AcVerticalAlignment)PyAcVerticalAlignment::pyacVerticalAlignmentBaseline;
    PyThrowBadHr(impObj()->get_VerticalAlignment(&rtVal));
    return (PyAcVerticalAlignment)rtVal;
}

void PyIAcadTextImpl::SetVerticalAlignment(PyAcVerticalAlignment val) const
{
    PyThrowBadHr(impObj()->put_VerticalAlignment((AcVerticalAlignment)val));
}

double PyIAcadTextImpl::GetHeight() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_Height(&rtval));
    return rtval;
}

void PyIAcadTextImpl::SetHeight(double val) const
{
    PyThrowBadHr(impObj()->put_Height(val));
}

double PyIAcadTextImpl::GetRotation() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_Rotation(&rtval));
    return rtval;
}

void PyIAcadTextImpl::SetRotation(double val) const
{
    PyThrowBadHr(impObj()->put_Rotation(val));
}

double PyIAcadTextImpl::GetScaleFactor() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_ScaleFactor(&rtval));
    return rtval;
}

void PyIAcadTextImpl::SetScaleFactor(double val) const
{
    PyThrowBadHr(impObj()->put_ScaleFactor(val));
}

double PyIAcadTextImpl::GetObliqueAngle() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_ObliqueAngle(&rtval));
    return rtval;
}

void PyIAcadTextImpl::SetObliqueAngle(double val) const
{
    PyThrowBadHr(impObj()->put_ObliqueAngle(val));
}

AcGePoint3d PyIAcadTextImpl::GetTextAlignmentPoint() const
{
    _variant_t vtval;
    AcGePoint3d rtVal;
    PyThrowBadHr(impObj()->get_TextAlignmentPoint(&vtval));
    PyThrowBadHr(VariantToAcGePoint3d(vtval, rtVal));
    return rtVal;
}

void PyIAcadTextImpl::SetTextAlignmentPoint(const AcGePoint3d& val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGePoint3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_TextAlignmentPoint(vtval));
}

AcGePoint3d PyIAcadTextImpl::GetInsertionPoint() const
{
    _variant_t vtval;
    AcGePoint3d rtVal;
    PyThrowBadHr(impObj()->get_InsertionPoint(&vtval));
    PyThrowBadHr(VariantToAcGePoint3d(vtval, rtVal));
    return rtVal;
}

void PyIAcadTextImpl::SetInsertionPoint(const AcGePoint3d& val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGePoint3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_InsertionPoint(vtval));
}

AcGeVector3d PyIAcadTextImpl::GetNormal() const
{
    AcGeVector3d val;
    _variant_t coord;
    PyThrowBadHr(impObj()->get_Normal(&coord.GetVARIANT()));
    PyThrowBadHr(VariantToAcGeVector3d(coord, val));
    return val;
}

void PyIAcadTextImpl::SetNormal(const AcGeVector3d& val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGeVector3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_Normal(vtval));
}

long PyIAcadTextImpl::GetTextGenerationFlag() const
{
    long rtval = 0.0;
    PyThrowBadHr(impObj()->get_TextGenerationFlag(&rtval));
    return rtval;
}

void PyIAcadTextImpl::SetTextGenerationFlag(long val) const
{
    PyThrowBadHr(impObj()->put_TextGenerationFlag(val));
}

double PyIAcadTextImpl::GetThickness() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_Thickness(&rtval));
    return rtval;
}

void PyIAcadTextImpl::SetThickness(double val) const
{
    PyThrowBadHr(impObj()->put_Thickness(val));
}

bool PyIAcadTextImpl::GetUpsideDown() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_UpsideDown(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadTextImpl::SetUpsideDown(bool val) const
{
    PyThrowBadHr(impObj()->put_UpsideDown(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadTextImpl::GetBackward() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_Backward(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadTextImpl::SetBackward(bool val) const
{
    PyThrowBadHr(impObj()->put_Backward(val ? VARIANT_TRUE : VARIANT_FALSE));
}

CString PyIAcadTextImpl::GetFieldCode() const
{
#if defined(_ZRXTARGET250)
    throw PyNotimplementedByHost{};
#else
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->FieldCode(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
#endif
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

AcGeVector3d PyIAcadToleranceImpl::GetDirectionVector() const
{
    AcGeVector3d val;
    _variant_t coord;
    PyThrowBadHr(impObj()->get_DirectionVector(&coord.GetVARIANT()));
    PyThrowBadHr(VariantToAcGeVector3d(coord, val));
    return val;
}

void PyIAcadToleranceImpl::SetDirectionVector(const AcGeVector3d& val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGeVector3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_DirectionVector(vtval));
}

AcGePoint3d PyIAcadToleranceImpl::GetInsertionPoint() const
{
    _variant_t vtval;
    AcGePoint3d rtVal;
    PyThrowBadHr(impObj()->get_InsertionPoint(&vtval));
    PyThrowBadHr(VariantToAcGePoint3d(vtval, rtVal));
    return rtVal;
}

void PyIAcadToleranceImpl::SetInsertionPoint(const AcGePoint3d& val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGePoint3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_InsertionPoint(vtval));
}

AcGeVector3d PyIAcadToleranceImpl::GetNormal() const
{
    AcGeVector3d val;
    _variant_t coord;
    PyThrowBadHr(impObj()->get_Normal(&coord.GetVARIANT()));
    PyThrowBadHr(VariantToAcGeVector3d(coord, val));
    return val;
}

void PyIAcadToleranceImpl::SetNormal(const AcGeVector3d& val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGeVector3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_Normal(vtval));
}

CString PyIAcadToleranceImpl::GetStyleName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_StyleName(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadToleranceImpl::SetStyleName(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_StyleName(bstrval));
}

PyAcColor PyIAcadToleranceImpl::GetTextColor() const
{
    AcColor rtVal = (AcColor)PyAcColor::pyacByLayer;
    PyThrowBadHr(impObj()->get_TextColor(&rtVal));
    return (PyAcColor)rtVal;
}

void PyIAcadToleranceImpl::SetTextColor(PyAcColor val) const
{
    PyThrowBadHr(impObj()->put_TextColor((AcColor)val));
}

CString PyIAcadToleranceImpl::GetTextString() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_TextString(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadToleranceImpl::SetTextString(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_TextString(bstrval));
}

CString PyIAcadToleranceImpl::GetTextStyle() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_TextStyle(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadToleranceImpl::SetTextStyle(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_TextStyle(bstrval));
}

double PyIAcadToleranceImpl::GetTextHeight() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_TextHeight(&rtval));
    return rtval;
}

void PyIAcadToleranceImpl::SetTextHeight(double val) const
{
    PyThrowBadHr(impObj()->put_TextHeight(val));
}

double PyIAcadToleranceImpl::GetScaleFactor() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_ScaleFactor(&rtval));
    return rtval;
}

void PyIAcadToleranceImpl::SetScaleFactor(double val) const
{
    PyThrowBadHr(impObj()->put_ScaleFactor(val));
}

PyAcColor PyIAcadToleranceImpl::GetDimensionLineColor() const
{
    AcColor rtVal = (AcColor)PyAcColor::pyacByLayer;
    PyThrowBadHr(impObj()->get_DimensionLineColor(&rtVal));
    return (PyAcColor)rtVal;
}

void PyIAcadToleranceImpl::SetDimensionLineColor(PyAcColor val) const
{
    PyThrowBadHr(impObj()->put_DimensionLineColor((AcColor)val));
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

Point3dCoordinates PyIAcadTraceImpl::GetCoordinates() const
{
    _variant_t vtcoords;
    Point3dCoordinates coords;
    PyThrowBadHr(impObj()->get_Coordinates(&vtcoords));
    PyThrowBadHr(VariantToAcGePoint3ds(vtcoords, coords));
    return coords;
}

void PyIAcadTraceImpl::SetCoordinates(const Point3dCoordinates& coords) const
{
    _variant_t vtcoords;
    PyThrowBadHr(AcGePoint3dsToVariant(vtcoords, coords));
    PyThrowBadHr(impObj()->put_Coordinates(vtcoords));
}

AcGeVector3d PyIAcadTraceImpl::GetNormal() const
{
    AcGeVector3d val;
    _variant_t coord;
    PyThrowBadHr(impObj()->get_Normal(&coord.GetVARIANT()));
    PyThrowBadHr(VariantToAcGeVector3d(coord, val));
    return val;
}

void PyIAcadTraceImpl::SetNormal(const AcGeVector3d& val) const
{
    _variant_t coord;
    PyThrowBadHr(AcGeVector3dToVariant(coord.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_Normal(coord));
}

double PyIAcadTraceImpl::GetThickness() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_Thickness(&rtval));
    return rtval;
}

void PyIAcadTraceImpl::SetThickness(double val) const
{
    PyThrowBadHr(impObj()->put_Thickness(val));
}

AcGePoint3d PyIAcadTraceImpl::GetCoordinate(int index) const
{
    _variant_t vtval;
    AcGePoint3d rtVal;
    PyThrowBadHr(impObj()->get_Coordinate(index, &vtval));
    PyThrowBadHr(VariantToAcGePoint3d(vtval, rtVal));
    return rtVal;
}

void PyIAcadTraceImpl::SetCoordinate(int index, const AcGePoint3d& val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGePoint3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_Coordinate(index, vtval));
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

AcGePoint3d PyIAcadXlineImpl::GetBasePoint() const
{
    _variant_t vtval;
    AcGePoint3d rtVal;
    PyThrowBadHr(impObj()->get_BasePoint(&vtval));
    PyThrowBadHr(VariantToAcGePoint3d(vtval, rtVal));
    return rtVal;
}

void PyIAcadXlineImpl::SetBasePoint(const AcGePoint3d& val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGePoint3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_BasePoint(vtval));
}

AcGePoint3d PyIAcadXlineImpl::GetSecondPoint() const
{
    _variant_t vtval;
    AcGePoint3d rtVal;
    PyThrowBadHr(impObj()->get_SecondPoint(&vtval));
    PyThrowBadHr(VariantToAcGePoint3d(vtval, rtVal));
    return rtVal;
}

void PyIAcadXlineImpl::SetSecondPoint(const AcGePoint3d& val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGePoint3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_SecondPoint(vtval));
}

AcGeVector3d PyIAcadXlineImpl::GetDirectionVector() const
{
    _variant_t vtval;
    AcGeVector3d rtVal;
    PyThrowBadHr(impObj()->get_DirectionVector(&vtval));
    PyThrowBadHr(VariantToAcGeVector3d(vtval, rtVal));
    return rtVal;
}

void PyIAcadXlineImpl::SetDirectionVector(const AcGeVector3d& val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGeVector3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_SecondPoint(vtval));
}

PyIAcadEntityPtrArray PyIAcadXlineImpl::Offset(double val) const
{
    _variant_t vtents;
    PyIAcadEntityPtrArray vec;
    PyThrowBadHr(impObj()->Offset(val, &vtents.GetVARIANT()));
    PyThrowBadHr(VariantToPyIAcadEntityPtrArray(vtents, vec));
    return vec;
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

void PyIAcadBlockReferenceImpl::SetInsertionPoint(const AcGePoint3d& val) const
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

void PyIAcadBlockReferenceImpl::SetName(const CString& val) const
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

void PyIAcadBlockReferenceImpl::SetNormal(const AcGeVector3d& val) const
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

void PyIAcadBlockReferenceImpl::SetRotation(double val) const
{
    PyThrowBadHr(impObj()->put_Rotation(val));
}

double PyIAcadBlockReferenceImpl::GetXScaleFactor() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_XScaleFactor(&rtval));
    return rtval;
}

void PyIAcadBlockReferenceImpl::SetXScaleFactor(double val) const
{
    PyThrowBadHr(impObj()->put_XScaleFactor(val));
}

double PyIAcadBlockReferenceImpl::GetYScaleFactor() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_YScaleFactor(&rtval));
    return rtval;
}

void PyIAcadBlockReferenceImpl::SetYScaleFactor(double val) const
{
    PyThrowBadHr(impObj()->put_YScaleFactor(val));
}

double PyIAcadBlockReferenceImpl::GetZScaleFactor() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_ZScaleFactor(&rtval));
    return rtval;
}

void PyIAcadBlockReferenceImpl::SetZScaleFactor(double val) const
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

void PyIAcadBlockReferenceImpl::SetXEffectiveScaleFactor(double val) const
{
    PyThrowBadHr(impObj()->put_XEffectiveScaleFactor(val));
}

double PyIAcadBlockReferenceImpl::GetYEffectiveScaleFactor() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_YEffectiveScaleFactor(&rtval));
    return rtval;
}

void PyIAcadBlockReferenceImpl::SetYEffectiveScaleFactor(double val) const
{
    PyThrowBadHr(impObj()->put_YEffectiveScaleFactor(val));
}

double PyIAcadBlockReferenceImpl::GetZEffectiveScaleFactor() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_ZEffectiveScaleFactor(&rtval));
    return rtval;
}

void PyIAcadBlockReferenceImpl::SetZEffectiveScaleFactor(double val) const
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

void PyIAcadMInsertBlockImpl::SetColumns(long val) const
{
    PyThrowBadHr(impObj()->put_Columns(val));
}

long PyIAcadMInsertBlockImpl::GetColumns() const
{
    long val = 0;
    PyThrowBadHr(impObj()->get_Columns(&val));
    return val;
}

void PyIAcadMInsertBlockImpl::SetRows(long val) const
{
    PyThrowBadHr(impObj()->put_Rows(val));
}

long PyIAcadMInsertBlockImpl::GetRows() const
{
    long val = 0;
    PyThrowBadHr(impObj()->get_Rows(&val));
    return val;
}

void PyIAcadMInsertBlockImpl::SetColumnSpacing(double val) const
{
    PyThrowBadHr(impObj()->put_ColumnSpacing(val));
}

double PyIAcadMInsertBlockImpl::GetColumnSpacing() const
{
    double val = 0;
    PyThrowBadHr(impObj()->get_ColumnSpacing(&val));
    return val;
}

void PyIAcadMInsertBlockImpl::SetRowSpacing(double val) const
{
    PyThrowBadHr(impObj()->put_RowSpacing(val));
}

double PyIAcadMInsertBlockImpl::GetRowSpacing() const
{
    double val = 0;
    PyThrowBadHr(impObj()->get_RowSpacing(&val));
    return val;
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

CString PyIAcadExternalReferenceImpl::GetPath() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Path(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadExternalReferenceImpl::SetPath(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_Path(bstrval));
}

bool PyIAcadExternalReferenceImpl::GetLayerPropertyOverrides() const
{
#if defined(_BRXTARGET260) || defined(_GRXTARGET250)
    throw PyNotimplementedByHost{};
#else
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_LayerPropertyOverrides(&rtVal));
    return rtVal != VARIANT_FALSE;
#endif
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

AcGeVector3d PyIAcadHatchImpl::GetNormal() const
{
    AcGeVector3d val;
    _variant_t coord;
    PyThrowBadHr(impObj()->get_Normal(&coord.GetVARIANT()));
    PyThrowBadHr(VariantToAcGeVector3d(coord, val));
    return val;
}

void PyIAcadHatchImpl::SetNormal(const AcGeVector3d& val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGeVector3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_Normal(vtval));
}

long PyIAcadHatchImpl::GetNumberOfLoops() const
{
    long rtval = 0.0;
    PyThrowBadHr(impObj()->get_NumberOfLoops(&rtval));
    return rtval;
}

PyAcPatternType PyIAcadHatchImpl::GetPatternType() const
{
    AcPatternType rtVal = (AcPatternType)PyAcPatternType::pyacHatchPatternTypeUserDefined;
    PyThrowBadHr(impObj()->get_PatternType(&rtVal));
    return (PyAcPatternType)rtVal;
}

CString PyIAcadHatchImpl::GetPatternName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_PatternName(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

double PyIAcadHatchImpl::GetPatternAngle() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_PatternAngle(&rtval));
    return rtval;
}

void PyIAcadHatchImpl::SetPatternAngle(double val) const
{
    PyThrowBadHr(impObj()->put_PatternAngle(val));
}

double PyIAcadHatchImpl::GetPatternScale() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_PatternScale(&rtval));
    return rtval;
}

void PyIAcadHatchImpl::SetPatternScale(double val) const
{
    PyThrowBadHr(impObj()->put_PatternScale(val));
}

double PyIAcadHatchImpl::GetPatternSpace() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_PatternSpace(&rtval));
    return rtval;
}

void PyIAcadHatchImpl::SetPatternSpace(double val) const
{
    PyThrowBadHr(impObj()->put_PatternSpace(val));
}

PyAcISOPenWidth PyIAcadHatchImpl::GetISOPenWidth() const
{
    AcISOPenWidth rtval = (AcISOPenWidth)PyAcISOPenWidth::pyacPenWidthUnk;
    PyThrowBadHr(impObj()->get_ISOPenWidth(&rtval));
    return (PyAcISOPenWidth)rtval;
}

void PyIAcadHatchImpl::SetISOPenWidth(PyAcISOPenWidth val) const
{
    PyThrowBadHr(impObj()->put_ISOPenWidth((AcISOPenWidth)val));
}

bool PyIAcadHatchImpl::GetPatternDouble() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_PatternDouble(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadHatchImpl::SetPatternDouble(bool val) const
{
    PyThrowBadHr(impObj()->put_PatternDouble(val ? VARIANT_TRUE : VARIANT_FALSE));
}

double PyIAcadHatchImpl::GetElevation() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_Elevation(&rtval));
    return rtval;
}

void PyIAcadHatchImpl::SetElevation(double val) const
{
    PyThrowBadHr(impObj()->put_Elevation(val));
}

bool PyIAcadHatchImpl::GetAssociativeHatch() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_AssociativeHatch(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadHatchImpl::SetAssociativeHatch(bool val) const
{
    PyThrowBadHr(impObj()->put_AssociativeHatch(val ? VARIANT_TRUE : VARIANT_FALSE));
}

PyAcHatchStyle PyIAcadHatchImpl::GetHatchStyle() const
{
    AcHatchStyle rtval = (AcHatchStyle)PyAcHatchStyle::pyacHatchStyleNormal;
    PyThrowBadHr(impObj()->get_HatchStyle(&rtval));
    return (PyAcHatchStyle)rtval;
}

void PyIAcadHatchImpl::SetHatchStyle(PyAcHatchStyle val) const
{
    PyThrowBadHr(impObj()->put_HatchStyle((AcHatchStyle)val));
}

void PyIAcadHatchImpl::SetPattern(int patternType, const CString& name) const
{
    _bstr_t bstrval{ name };
    PyThrowBadHr(impObj()->SetPattern(patternType, bstrval));
}

void PyIAcadHatchImpl::AppendOuterLoop(const PyIAcadEntityImplArray& objectArray) const
{
    _variant_t vtobjects;
    PyThrowBadHr(PyIAcadEntityImplArrayToVariant(vtobjects, objectArray));
    PyThrowBadHr(impObj()->AppendOuterLoop(vtobjects));
}

void PyIAcadHatchImpl::AppendInnerLoop(const PyIAcadEntityImplArray& objectArray) const
{
    _variant_t vtobjects;
    PyThrowBadHr(PyIAcadEntityImplArrayToVariant(vtobjects, objectArray));
    PyThrowBadHr(impObj()->AppendInnerLoop(vtobjects));
}

void PyIAcadHatchImpl::InsertLoopAt(int index, PyAcLoopType loopType, const PyIAcadEntityImplArray& objectArray) const
{
    _variant_t vtobjects;
    PyThrowBadHr(PyIAcadEntityImplArrayToVariant(vtobjects, objectArray));
    PyThrowBadHr(impObj()->InsertLoopAt(index, (AcLoopType)loopType, vtobjects));
}

PyIAcadEntityPtrArray PyIAcadHatchImpl::GetLoopAt(int index) const
{
    _variant_t vtents;
    PyIAcadEntityPtrArray vec;
    PyThrowBadHr(impObj()->GetLoopAt(index, &vtents.GetVARIANT()));
    PyThrowBadHr(VariantToPyIAcadEntityPtrArray(vtents, vec));
    return vec;
}

void PyIAcadHatchImpl::Evaluate() const
{
    PyThrowBadHr(impObj()->Evaluate());
}

PyIAcadAcCmColorPtr PyIAcadHatchImpl::GetGradientColor1() const
{
    IAcadAcCmColor* rtVal = nullptr;
    PyThrowBadHr(impObj()->get_GradientColor1(&rtVal));
    return std::make_unique<PyIAcadAcCmColorImpl>(rtVal);
}

void PyIAcadHatchImpl::SetGradientColor1(const PyIAcadAcCmColorImpl& val) const
{
    PyThrowBadHr(impObj()->put_GradientColor1(val.impObj()));
}

PyIAcadAcCmColorPtr PyIAcadHatchImpl::GetGradientColor2() const
{
    IAcadAcCmColor* rtVal = nullptr;
    PyThrowBadHr(impObj()->get_GradientColor2(&rtVal));
    return std::make_unique<PyIAcadAcCmColorImpl>(rtVal);
}

void PyIAcadHatchImpl::SetGradientColor2(const PyIAcadAcCmColorImpl& val) const
{
    PyThrowBadHr(impObj()->put_GradientColor2(val.impObj()));
}

double PyIAcadHatchImpl::GetGradientAngle() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_GradientAngle(&rtval));
    return rtval;
}

void PyIAcadHatchImpl::SetGradientAngle(double val) const
{
    PyThrowBadHr(impObj()->put_GradientAngle(val));
}

bool PyIAcadHatchImpl::GetGradientCentered() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_GradientCentered(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadHatchImpl::SetGradientCentered(bool val) const
{
    PyThrowBadHr(impObj()->put_GradientCentered(val ? VARIANT_TRUE : VARIANT_FALSE));
}

CString PyIAcadHatchImpl::GetGradientName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_GradientName(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadHatchImpl::SetGradientName(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_GradientName(bstrval));
}

PyAcHatchObjectType PyIAcadHatchImpl::GetHatchObjectType() const
{
    AcHatchObjectType rtVal = (AcHatchObjectType)PyAcHatchObjectType::pyacHatchObject;
    PyThrowBadHr(impObj()->get_HatchObjectType(&rtVal));
    return (PyAcHatchObjectType)rtVal;
}

void PyIAcadHatchImpl::SetHatchObjectType(PyAcHatchObjectType val) const
{
    PyThrowBadHr(impObj()->put_HatchObjectType((AcHatchObjectType)val));
}

double PyIAcadHatchImpl::GetArea() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_Area(&rtval));
    return rtval;
}

AcGePoint3d PyIAcadHatchImpl::GetOrigin() const
{
    _variant_t vtval;
    AcGePoint3d rtVal;
    PyThrowBadHr(impObj()->get_Origin(&vtval));
    PyThrowBadHr(VariantToAcGePoint3d(vtval, rtVal));
    return rtVal;
}

void PyIAcadHatchImpl::SetOrigin(const AcGePoint3d& val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGePoint3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_Origin(vtval));
}

PyIAcadAcCmColorPtr PyIAcadHatchImpl::GetBackgroundColor() const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost{};
#else
    IAcadAcCmColor* rtVal = nullptr;
    PyThrowBadHr(impObj()->get_BackgroundColor(&rtVal));
    return std::make_unique<PyIAcadAcCmColorImpl>(rtVal);
#endif
}

void PyIAcadHatchImpl::SetBackgroundColor(const PyIAcadAcCmColorImpl& val) const
{
#if defined(_BRXTARGET260)
    throw PyNotimplementedByHost{};
#else
    PyThrowBadHr(impObj()->put_BackgroundColor(val.impObj()));
#endif
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

long PyIAcadRasterImageImpl::GetBrightness() const
{
    long rtval = 0.0;
    PyThrowBadHr(impObj()->get_Brightness(&rtval));
    return rtval;
}

void PyIAcadRasterImageImpl::SetBrightness(long val) const
{
    PyThrowBadHr(impObj()->put_Brightness(val));
}

long PyIAcadRasterImageImpl::GetContrast() const
{
    long rtval = 0.0;
    PyThrowBadHr(impObj()->get_Contrast(&rtval));
    return rtval;
}

void PyIAcadRasterImageImpl::SetContrast(long val) const
{
    PyThrowBadHr(impObj()->put_Contrast(val));
}

long PyIAcadRasterImageImpl::GetFade() const
{
    long rtval = 0.0;
    PyThrowBadHr(impObj()->get_Fade(&rtval));
    return rtval;
}

void PyIAcadRasterImageImpl::SetFade(long val) const
{
    PyThrowBadHr(impObj()->put_Fade(val));
}

AcGePoint3d PyIAcadRasterImageImpl::GetOrigin() const
{
    _variant_t vtval;
    AcGePoint3d rtVal;
    PyThrowBadHr(impObj()->get_Origin(&vtval));
    PyThrowBadHr(VariantToAcGePoint3d(vtval, rtVal));
    return rtVal;
}

void PyIAcadRasterImageImpl::SetOrigin(const AcGePoint3d& val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGePoint3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_Origin(vtval));
}

double PyIAcadRasterImageImpl::GetRotation() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_Rotation(&rtval));
    return rtval;
}

void PyIAcadRasterImageImpl::SetRotation(double val) const
{
    PyThrowBadHr(impObj()->put_Rotation(val));
}

double PyIAcadRasterImageImpl::GetImageWidth() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_ImageWidth(&rtval));
    return rtval;
}

void PyIAcadRasterImageImpl::SetImageWidth(double val) const
{
    PyThrowBadHr(impObj()->put_ImageWidth(val));
}

double PyIAcadRasterImageImpl::GetImageHeight() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_ImageHeight(&rtval));
    return rtval;
}

void PyIAcadRasterImageImpl::SetImageHeight(double val) const
{
    PyThrowBadHr(impObj()->put_ImageHeight(val));
}

CString PyIAcadRasterImageImpl::GetName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Name(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadRasterImageImpl::SetName(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_Name(bstrval));
}

CString PyIAcadRasterImageImpl::GetImageFile() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_ImageFile(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadRasterImageImpl::SetImageFile(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_ImageFile(bstrval));
}

bool PyIAcadRasterImageImpl::GetImageVisibility() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_ImageVisibility(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadRasterImageImpl::SetImageVisibility(bool val) const
{
    PyThrowBadHr(impObj()->put_ImageVisibility(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadRasterImageImpl::GetClippingEnabled() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_ClippingEnabled(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadRasterImageImpl::SetClippingEnabled(bool val) const
{
    PyThrowBadHr(impObj()->put_ClippingEnabled(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadRasterImageImpl::GetTransparency() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_transparency(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadRasterImageImpl::SetTransparency(bool val) const
{
    PyThrowBadHr(impObj()->put_transparency(val ? VARIANT_TRUE : VARIANT_FALSE));
}

void PyIAcadRasterImageImpl::SetClipBoundary(const Point2dCoordinates& val) const
{
    _variant_t vtcoords;
    Point2dCoordinates coords;
    PyThrowBadHr(AcGePoint2dsToVariant(vtcoords, coords));
    PyThrowBadHr(impObj()->ClipBoundary(vtcoords));
}

double PyIAcadRasterImageImpl::GetHeight() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_Height(&rtval));
    return rtval;
}

double PyIAcadRasterImageImpl::GetWidth() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_Width(&rtval));
    return rtval;
}

bool PyIAcadRasterImageImpl::GetShowRotation() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_ShowRotation(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadRasterImageImpl::SetShowRotation(bool val) const
{
    PyThrowBadHr(impObj()->put_ShowRotation(val ? VARIANT_TRUE : VARIANT_FALSE));
}

double PyIAcadRasterImageImpl::GetScaleFactor() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_ScaleFactor(&rtval));
    return rtval;
}

void PyIAcadRasterImageImpl::SetScaleFactor(double val) const
{
    PyThrowBadHr(impObj()->put_ScaleFactor(val));
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

AcGePoint3d PyIAcadLineImpl::GetStartPoint() const
{
    _variant_t vtval;
    AcGePoint3d rtVal;
    PyThrowBadHr(impObj()->get_StartPoint(&vtval));
    PyThrowBadHr(VariantToAcGePoint3d(vtval, rtVal));
    return rtVal;
}

void PyIAcadLineImpl::SetStartPoint(const AcGePoint3d& val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGePoint3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_StartPoint(vtval));
}

AcGePoint3d PyIAcadLineImpl::GetEndPoint() const
{
    _variant_t vtval;
    AcGePoint3d rtVal;
    PyThrowBadHr(impObj()->get_EndPoint(&vtval));
    PyThrowBadHr(VariantToAcGePoint3d(vtval, rtVal));
    return rtVal;
}

void PyIAcadLineImpl::SetEndPoint(const AcGePoint3d& val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGePoint3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_EndPoint(vtval));
}

AcGeVector3d PyIAcadLineImpl::GetNormal() const
{
    AcGeVector3d val;
    _variant_t coord;
    PyThrowBadHr(impObj()->get_Normal(&coord.GetVARIANT()));
    PyThrowBadHr(VariantToAcGeVector3d(coord, val));
    return val;
}

void PyIAcadLineImpl::SetNormal(const AcGeVector3d& val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGeVector3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_Normal(vtval));
}

PyIAcadEntityPtrArray PyIAcadLineImpl::Offset(double val) const
{
    _variant_t vtents;
    PyIAcadEntityPtrArray vec;
    PyThrowBadHr(impObj()->Offset(val, &vtents.GetVARIANT()));
    PyThrowBadHr(VariantToPyIAcadEntityPtrArray(vtents, vec));
    return vec;
}

double PyIAcadLineImpl::GetThickness() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_Thickness(&rtval));
    return rtval;
}

void PyIAcadLineImpl::SetThickness(double val) const
{
    PyThrowBadHr(impObj()->put_Thickness(val));
}

AcGeVector3d PyIAcadLineImpl::GetDelta() const
{
    AcGeVector3d val;
    _variant_t coord;
    PyThrowBadHr(impObj()->get_Delta(&coord.GetVARIANT()));
    PyThrowBadHr(VariantToAcGeVector3d(coord, val));
    return val;
}

double PyIAcadLineImpl::GetLength() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_Length(&rtval));
    return rtval;
}

double PyIAcadLineImpl::GetAngle() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_Angle(&rtval));
    return rtval;
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

Point3dCoordinates PyIAcadPolyfaceMeshImpl::GetCoordinates() const
{
    _variant_t vtcoords;
    Point3dCoordinates coords;
    PyThrowBadHr(impObj()->get_Coordinates(&vtcoords.GetVARIANT()));
    PyThrowBadHr(VariantToAcGePoint3ds(vtcoords, coords));
    return coords;
}

void PyIAcadPolyfaceMeshImpl::SetCoordinates(const Point3dCoordinates& coords) const
{
    _variant_t vtcoords;
    PyThrowBadHr(AcGePoint3dsToVariant(vtcoords, coords));
    PyThrowBadHr(impObj()->put_Coordinates(vtcoords));
}

AcGePoint3d PyIAcadPolyfaceMeshImpl::GetCoordinate(int index) const
{
    _variant_t vtval;
    AcGePoint3d rtVal;
    PyThrowBadHr(impObj()->get_Coordinate(index, &vtval));
    PyThrowBadHr(VariantToAcGePoint3d(vtval, rtVal));
    return rtVal;
}

void PyIAcadPolyfaceMeshImpl::SetCoordinate(int index, const AcGePoint3d& val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGePoint3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_Coordinate(index, vtval));
}

long PyIAcadPolyfaceMeshImpl::GetNumberOfVertices() const
{
    long rtval = 0.0;
    PyThrowBadHr(impObj()->get_NumberOfVertices(&rtval));
    return rtval;
}

long PyIAcadPolyfaceMeshImpl::GetNumberOfFaces() const
{
    long rtval = 0.0;
    PyThrowBadHr(impObj()->get_NumberOfFaces(&rtval));
    return rtval;
}

void PyIAcadPolyfaceMeshImpl::SetFaces(const Longs& coords) const
{
    _variant_t vtval;
    PyThrowBadHr(InitVariantFromInt32Array(coords.data(), coords.size(), &vtval.GetVARIANT()));
    PyThrowBadHr(impObj()->put_Faces(vtval));
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

CString PyIAcadMLineImpl::GetStyleName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_StyleName(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

Point3dCoordinates PyIAcadMLineImpl::GetCoordinates() const
{
    _variant_t vtcoords;
    Point3dCoordinates coords;
    PyThrowBadHr(impObj()->get_Coordinates(&vtcoords.GetVARIANT()));
    PyThrowBadHr(VariantToAcGePoint3ds(vtcoords, coords));
    return coords;
}

void PyIAcadMLineImpl::SetCoordinates(const Point3dCoordinates& coords) const
{
    _variant_t vtcoords;
    PyThrowBadHr(AcGePoint3dsToVariant(vtcoords, coords));
    PyThrowBadHr(impObj()->put_Coordinates(vtcoords));
}

PyAcMLineJustification PyIAcadMLineImpl::GetJustification() const
{
    AcMLineJustification rtVal = (AcMLineJustification)PyAcMLineJustification::pyacTop;
    PyThrowBadHr(impObj()->get_Justification(&rtVal));
    return (PyAcMLineJustification)rtVal;
}

void PyIAcadMLineImpl::SetJustification(PyAcMLineJustification val) const
{
    PyThrowBadHr(impObj()->put_Justification((AcMLineJustification)val));
}

double PyIAcadMLineImpl::GetMLineScale() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_MLineScale(&rtval));
    return rtval;
}

void PyIAcadMLineImpl::SetMLineScale(double val) const
{
    PyThrowBadHr(impObj()->put_MLineScale(val));
}

IAcadMLine* PyIAcadMLineImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadMLine*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadSectionImpl
PyIAcadSectionImpl::PyIAcadSectionImpl(IAcadSection* ptr)
    : PyIAcadEntityImpl(ptr)
{
}

CString PyIAcadSectionImpl::GetName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Name(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadSectionImpl::SetName(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_Name(bstrval));
}

PyAcSectionState PyIAcadSectionImpl::GetState() const
{
    AcSectionState rtval = (AcSectionState)PyAcSectionState::pyacSectionStatePlane;
    PyThrowBadHr(impObj()->get_State(&rtval));
    return (PyAcSectionState)rtval;
}

void PyIAcadSectionImpl::SetState(PyAcSectionState val) const
{
    PyThrowBadHr(impObj()->put_State((AcSectionState)val));
}

AcGeVector3d PyIAcadSectionImpl::GetViewingDirection() const
{
    AcGeVector3d rtval;
    _variant_t coord;
    PyThrowBadHr(impObj()->get_ViewingDirection(&coord.GetVARIANT()));
    PyThrowBadHr(VariantToAcGeVector3d(coord, rtval));
    return rtval;
}

void PyIAcadSectionImpl::SetViewingDirection(const AcGeVector3d& val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGeVector3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_ViewingDirection(vtval));
}

AcGeVector3d PyIAcadSectionImpl::GetVerticalDirection() const
{
    AcGeVector3d rtval;
    _variant_t coord;
    PyThrowBadHr(impObj()->get_VerticalDirection(&coord.GetVARIANT()));
    PyThrowBadHr(VariantToAcGeVector3d(coord, rtval));
    return rtval;
}

void PyIAcadSectionImpl::SetVerticalDirection(const AcGeVector3d& val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGeVector3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_VerticalDirection(vtval));
}

AcGeVector3d PyIAcadSectionImpl::GetNormal() const
{
    AcGeVector3d rtval;
    _variant_t coord;
    PyThrowBadHr(impObj()->get_Normal(&coord.GetVARIANT()));
    PyThrowBadHr(VariantToAcGeVector3d(coord, rtval));
    return rtval;
}

bool PyIAcadSectionImpl::GetLiveSectionEnabled() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_LiveSectionEnabled(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadSectionImpl::SetLiveSectionEnabled(bool val) const
{
    PyThrowBadHr(impObj()->put_LiveSectionEnabled(val ? VARIANT_TRUE : VARIANT_FALSE));
}

int PyIAcadSectionImpl::GetIndicatorTransparency() const
{
    int rtval = 0;
    PyThrowBadHr(impObj()->get_IndicatorTransparency(&rtval));
    return rtval;
}

void PyIAcadSectionImpl::SetIndicatorTransparency(int val) const
{
    PyThrowBadHr(impObj()->put_IndicatorTransparency(val));
}

PyIAcadAcCmColorPtr PyIAcadSectionImpl::GetIndicatorFillColor() const
{
    IAcadAcCmColor* rtval = nullptr;
    PyThrowBadHr(impObj()->get_IndicatorFillColor(&rtval));
    return std::make_unique<PyIAcadAcCmColorImpl>(rtval);
}

void PyIAcadSectionImpl::SetIndicatorFillColor(const PyIAcadAcCmColorImpl& val) const
{
    PyThrowBadHr(impObj()->put_IndicatorFillColor(val.impObj()));
}

double PyIAcadSectionImpl::GetElevation() const
{
    double rtval = 0;
    PyThrowBadHr(impObj()->get_Elevation(&rtval));
    return rtval;
}

void PyIAcadSectionImpl::SetElevation(double val) const
{
    PyThrowBadHr(impObj()->put_Elevation(val));
}

double PyIAcadSectionImpl::GetTopHeight() const
{
    double rtval = 0;
    PyThrowBadHr(impObj()->get_TopHeight(&rtval));
    return rtval;
}

void PyIAcadSectionImpl::SetTopHeight(double val) const
{
    PyThrowBadHr(impObj()->put_TopHeight(val));
}

double PyIAcadSectionImpl::GetBottomHeight() const
{
    double rtval = 0;
    PyThrowBadHr(impObj()->get_BottomHeight(&rtval));
    return rtval;
}

void PyIAcadSectionImpl::SetBottomHeight(double val) const
{
    PyThrowBadHr(impObj()->put_BottomHeight(val));
}

int PyIAcadSectionImpl::GetNumVertices() const
{
    int rtval = 0;
    PyThrowBadHr(impObj()->get_NumVertices(&rtval));
    return rtval;
}

Point3dCoordinates PyIAcadSectionImpl::GetVertices() const
{
    _variant_t vtcoords;
    Point3dCoordinates coords;
    PyThrowBadHr(impObj()->get_Vertices(&vtcoords.GetVARIANT()));
    PyThrowBadHr(VariantToAcGePoint3ds(vtcoords, coords));
    return coords;
}

void PyIAcadSectionImpl::SetVertices(const Point3dCoordinates& coords) const
{
    _variant_t vtcoords;
    PyThrowBadHr(AcGePoint3dsToVariant(vtcoords, coords));
    PyThrowBadHr(impObj()->put_Vertices(vtcoords));
}

AcGePoint3d PyIAcadSectionImpl::GetCoordinate(int index) const
{
    _variant_t vtval;
    AcGePoint3d rtVal;
    PyThrowBadHr(impObj()->get_Coordinate(index, &vtval));
    PyThrowBadHr(VariantToAcGePoint3d(vtval, rtVal));
    return rtVal;
}

void PyIAcadSectionImpl::SetCoordinate(int index, const AcGePoint3d& val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGePoint3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_Coordinate(index, vtval));
}

void PyIAcadSectionImpl::AddVertex(int index, const AcGePoint3d& val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGePoint3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->AddVertex(index, vtval));
}

void PyIAcadSectionImpl::RemoveVertex(int index) const
{
    PyThrowBadHr(impObj()->RemoveVertex(index));
}

boost::python::tuple PyIAcadSectionImpl::HitTest(const AcGePoint3d& hit) const
{
    PyAutoLockGIL lock;
    _variant_t varPtHit;
    _variant_t vtPtOnSegment;
    AcGePoint3d rtvtPtOnSegment;
    int segmentIndex = 0;
    VARIANT_BOOL bhit = VARIANT_FALSE;
    AcSectionSubItem subItem = (AcSectionSubItem)PyAcSectionSubItem::pyacSectionSubItemkNone;
    PyThrowBadHr(AcGePoint3dToVariant(varPtHit.GetVARIANT(), hit));
    PyThrowBadHr(impObj()->HitTest(varPtHit, &bhit, &segmentIndex, &vtPtOnSegment.GetVARIANT(), &subItem));
    PyThrowBadHr(VariantToAcGePoint3d(vtPtOnSegment, rtvtPtOnSegment));
    return boost::python::make_tuple(bhit ? VARIANT_TRUE : VARIANT_FALSE, segmentIndex, rtvtPtOnSegment, (PyAcSectionSubItem)subItem);
}

void PyIAcadSectionImpl::CreateJog(const AcGePoint3d& val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGePoint3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->CreateJog(vtval));
}

PyIAcadSectionSettingsPtr PyIAcadSectionImpl::GetSettings() const
{
    IAcadSectionSettings* pUnk = nullptr;
    PyThrowBadHr(impObj()->get_Settings(&pUnk));
    return std::make_unique<PyIAcadSectionSettingsImpl>(pUnk);
}

void PyIAcadSectionImpl::GenerateSectionGeometry(
    const PyIAcadEntityImpl& val,
    PyIAcadEntityPtrArray& vecIntersectionBoundaryObjs,
    PyIAcadEntityPtrArray& vecIntersectionFillObjs,
    PyIAcadEntityPtrArray& vecBackgroudnObjs,
    PyIAcadEntityPtrArray& vecForegroudObjs,
    PyIAcadEntityPtrArray& vecCurveTangencyObjs) const
{
    _variant_t vtIntersectionBoundaryObjs;
    _variant_t vtIntersectionFillObjs;
    _variant_t vtBackgroudnObjs;
    _variant_t vtForegroudObjs;
    _variant_t vtCurveTangencyObjs;
    PyThrowBadHr(impObj()->GenerateSectionGeometry(val.impObj(), &vtIntersectionBoundaryObjs.GetVARIANT(), &vtIntersectionFillObjs.GetVARIANT(),
        &vtBackgroudnObjs.GetVARIANT(), &vtForegroudObjs.GetVARIANT(), &vtCurveTangencyObjs.GetVARIANT()));
    PyThrowBadHr(VariantToPyIAcadEntityPtrArray(vtIntersectionBoundaryObjs, vecIntersectionBoundaryObjs));
    PyThrowBadHr(VariantToPyIAcadEntityPtrArray(vtIntersectionFillObjs, vecIntersectionFillObjs));
    PyThrowBadHr(VariantToPyIAcadEntityPtrArray(vtBackgroudnObjs, vecBackgroudnObjs));
    PyThrowBadHr(VariantToPyIAcadEntityPtrArray(vtForegroudObjs, vecForegroudObjs));
    PyThrowBadHr(VariantToPyIAcadEntityPtrArray(vtCurveTangencyObjs, vecCurveTangencyObjs));
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

double PyIAcadMLeaderImpl::GetScaleFactor() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_ScaleFactor(&rtval));
    return rtval;
}

void PyIAcadMLeaderImpl::SetScaleFactor(double val) const
{
    PyThrowBadHr(impObj()->put_ScaleFactor(val));
}

PyAcMLeaderType PyIAcadMLeaderImpl::GetLeaderType() const
{
    AcMLeaderType rtVal = (AcMLeaderType)PyAcMLeaderType::pyacInVisibleLeader;
    PyThrowBadHr(impObj()->get_LeaderType(&rtVal));
    return (PyAcMLeaderType)rtVal;
}

void PyIAcadMLeaderImpl::SetLeaderType(PyAcMLeaderType val) const
{
    PyThrowBadHr(impObj()->put_LeaderType((AcMLeaderType)val));
}

PyIAcadAcCmColorPtr PyIAcadMLeaderImpl::GetLeaderLineColor() const
{
    IAcadAcCmColor* rtVal = nullptr;
    PyThrowBadHr(impObj()->get_LeaderLineColor(&rtVal));
    return std::make_unique<PyIAcadAcCmColorImpl>(rtVal);
}

void PyIAcadMLeaderImpl::SetLeaderLineColor(const PyIAcadAcCmColorImpl& val) const
{
    PyThrowBadHr(impObj()->put_LeaderLineColor(val.impObj()));
}

CString PyIAcadMLeaderImpl::GetLeaderLinetype() const
{
    _bstr_t bstrVal;
#ifdef _BRXTARGET260
    PyThrowBadHr(impObj()->get_LeaderLineType(&bstrVal.GetBSTR()));
#else
    PyThrowBadHr(impObj()->get_LeaderLinetype(&bstrVal.GetBSTR()));
#endif
    return (LPCTSTR)bstrVal;
}

void PyIAcadMLeaderImpl::SetLeaderLinetype(const CString& val) const
{
    _bstr_t bstrval{ val };
#ifdef _BRXTARGET260
    PyThrowBadHr(impObj()->put_LeaderLineType(bstrval));
#else
    PyThrowBadHr(impObj()->put_LeaderLinetype(bstrval));
#endif
}

PyAcLineWeight PyIAcadMLeaderImpl::GetLeaderLineWeight() const
{
    AcLineWeight rtVal = (AcLineWeight)PyAcLineWeight::pyacLnWt000;
    PyThrowBadHr(impObj()->get_LeaderLineWeight(&rtVal));
    return (PyAcLineWeight)rtVal;
}

void PyIAcadMLeaderImpl::SetLeaderLineWeight(PyAcLineWeight val) const
{
    PyThrowBadHr(impObj()->put_LeaderLineWeight((AcLineWeight)val));
}

PyAcDimArrowheadType PyIAcadMLeaderImpl::GetArrowheadType() const
{
    AcDimArrowheadType rtVal = (AcDimArrowheadType)PyAcDimArrowheadType::pyacArrowDefault;
    PyThrowBadHr(impObj()->get_ArrowheadType(&rtVal));
    return (PyAcDimArrowheadType)rtVal;
}

void PyIAcadMLeaderImpl::SetArrowheadType(PyAcDimArrowheadType val) const
{
    PyThrowBadHr(impObj()->put_ArrowheadType((AcDimArrowheadType)val));
}

double PyIAcadMLeaderImpl::GetArrowheadSize() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_ArrowheadSize(&rtval));
    return rtval;
}

void PyIAcadMLeaderImpl::SetArrowheadSize(double val) const
{
    PyThrowBadHr(impObj()->put_ArrowheadSize(val));
}

bool PyIAcadMLeaderImpl::GetDogLegged() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_DogLegged(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadMLeaderImpl::SetDogLegged(bool val) const
{
    PyThrowBadHr(impObj()->put_DogLegged(val ? VARIANT_TRUE : VARIANT_FALSE));
}

double PyIAcadMLeaderImpl::GetDoglegLength() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_DoglegLength(&rtval));
    return rtval;
}

void PyIAcadMLeaderImpl::SetDoglegLength(double val) const
{
    PyThrowBadHr(impObj()->put_DoglegLength(val));
}

CString PyIAcadMLeaderImpl::GetContentBlockName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_ContentBlockName(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadMLeaderImpl::SetContentBlockName(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_ContentBlockName(bstrval));
}

PyAcBlockConnectionType PyIAcadMLeaderImpl::GetBlockConnectionType() const
{
    AcBlockConnectionType rtVal = (AcBlockConnectionType)PyAcBlockConnectionType::pyacConnectExtents;
    PyThrowBadHr(impObj()->get_BlockConnectionType(&rtVal));
    return (PyAcBlockConnectionType)rtVal;
}

void PyIAcadMLeaderImpl::SetBlockConnectionType(PyAcBlockConnectionType val) const
{
    PyThrowBadHr(impObj()->put_BlockConnectionType((AcBlockConnectionType)val));
}

double PyIAcadMLeaderImpl::GetBlockScale() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_BlockScale(&rtval));
    return rtval;
}

void PyIAcadMLeaderImpl::SetBlockScale(double val) const
{
    PyThrowBadHr(impObj()->put_BlockScale(val));
}

CString PyIAcadMLeaderImpl::GetTextString() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_TextString(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadMLeaderImpl::SetTextString(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_TextString(bstrval));
}

CString PyIAcadMLeaderImpl::GetTextStyleName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_TextStyleName(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadMLeaderImpl::SetTextStyleName(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_TextStyleName(bstrval));
}

PyAcAttachmentPoint PyIAcadMLeaderImpl::GetTextJustify() const
{
    AcAttachmentPoint rtVal = (AcAttachmentPoint)PyAcAttachmentPoint::pyacAttachmentPointTopLeft;
    PyThrowBadHr(impObj()->get_TextJustify(&rtVal));
    return (PyAcAttachmentPoint)rtVal;
}

void PyIAcadMLeaderImpl::SetTextJustify(PyAcAttachmentPoint val) const
{
    PyThrowBadHr(impObj()->put_TextJustify((AcAttachmentPoint)val));
}

PyAcDrawingDirection PyIAcadMLeaderImpl::GetTextDirection() const
{
    AcDrawingDirection rtVal = (AcDrawingDirection)PyAcDrawingDirection::pyacLeftToRight;
    PyThrowBadHr(impObj()->get_TextDirection(&rtVal));
    return (PyAcDrawingDirection)rtVal;
}

void PyIAcadMLeaderImpl::SetTextDirection(PyAcDrawingDirection val) const
{
    PyThrowBadHr(impObj()->put_TextDirection((AcDrawingDirection)val));
}

double PyIAcadMLeaderImpl::GetTextWidth() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_TextWidth(&rtval));
    return rtval;
}

void PyIAcadMLeaderImpl::SetTextWidth(double val) const
{
    PyThrowBadHr(impObj()->put_TextWidth(val));
}

double PyIAcadMLeaderImpl::GetTextHeight() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_TextHeight(&rtval));
    return rtval;
}

void PyIAcadMLeaderImpl::SetTextHeight(double val) const
{
    PyThrowBadHr(impObj()->put_TextHeight(val));
}

double PyIAcadMLeaderImpl::GetTextRotation() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_TextRotation(&rtval));
    return rtval;
}

void PyIAcadMLeaderImpl::SetTextRotation(double val) const
{
    PyThrowBadHr(impObj()->put_TextRotation(val));
}

double PyIAcadMLeaderImpl::GetTextLineSpacingFactor() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_TextLineSpacingFactor(&rtval));
    return rtval;
}

void PyIAcadMLeaderImpl::SetTextLineSpacingFactor(double val) const
{
    PyThrowBadHr(impObj()->put_TextLineSpacingFactor(val));
}

double PyIAcadMLeaderImpl::GetTextLineSpacingDistance() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_TextLineSpacingDistance(&rtval));
    return rtval;
}

void PyIAcadMLeaderImpl::SetTextLineSpacingDistance(double val) const
{
    PyThrowBadHr(impObj()->put_TextLineSpacingDistance(val));
}

PyAcLineSpacingStyle PyIAcadMLeaderImpl::GetTextLineSpacingStyle() const
{
    AcLineSpacingStyle rtVal = (AcLineSpacingStyle)PyAcLineSpacingStyle::pyacLineSpacingStyleAtLeast;
    PyThrowBadHr(impObj()->get_TextLineSpacingStyle(&rtVal));
    return (PyAcLineSpacingStyle)rtVal;
}

void PyIAcadMLeaderImpl::SetTextLineSpacingStyle(PyAcLineSpacingStyle val) const
{
    PyThrowBadHr(impObj()->put_TextLineSpacingStyle((AcLineSpacingStyle)val));
}

bool PyIAcadMLeaderImpl::GetTextBackgroundFill() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_TextBackgroundFill(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadMLeaderImpl::SetTextBackgroundFill(bool val) const
{
    PyThrowBadHr(impObj()->put_TextBackgroundFill(val ? VARIANT_TRUE : VARIANT_FALSE));
}

PyAcTextAttachmentDirection PyIAcadMLeaderImpl::GetTextAttachmentDirection() const
{
    AcTextAttachmentDirection rtVal = (AcTextAttachmentDirection)PyAcTextAttachmentDirection::pyacAttachmentHorizontal;
    PyThrowBadHr(impObj()->get_TextAttachmentDirection(&rtVal));
    return (PyAcTextAttachmentDirection)rtVal;
}

void PyIAcadMLeaderImpl::SetTextAttachmentDirection(PyAcTextAttachmentDirection val) const
{
    PyThrowBadHr(impObj()->put_TextAttachmentDirection((AcTextAttachmentDirection)val));
}

PyAcTextAttachmentType PyIAcadMLeaderImpl::GetTextLeftAttachmentType() const
{
    AcTextAttachmentType rtVal = (AcTextAttachmentType)PyAcTextAttachmentType::pyacAttachmentTopOfTop;
    PyThrowBadHr(impObj()->get_TextLeftAttachmentType(&rtVal));
    return (PyAcTextAttachmentType)rtVal;
}

void PyIAcadMLeaderImpl::SetTextLeftAttachmentType(PyAcTextAttachmentType val) const
{
    PyThrowBadHr(impObj()->put_TextLeftAttachmentType((AcTextAttachmentType)val));
}

PyAcTextAttachmentType PyIAcadMLeaderImpl::GetTextRightAttachmentType() const
{
    AcTextAttachmentType rtVal = (AcTextAttachmentType)PyAcTextAttachmentType::pyacAttachmentTopOfTop;
    PyThrowBadHr(impObj()->get_TextRightAttachmentType(&rtVal));
    return (PyAcTextAttachmentType)rtVal;
}

void PyIAcadMLeaderImpl::SetTextRightAttachmentType(PyAcTextAttachmentType val) const
{
    PyThrowBadHr(impObj()->put_TextRightAttachmentType((AcTextAttachmentType)val));
}

PyAcVerticalTextAttachmentType PyIAcadMLeaderImpl::GetTextTopAttachmentType() const
{
    AcVerticalTextAttachmentType rtVal = (AcVerticalTextAttachmentType)PyAcVerticalTextAttachmentType::pyacAttachmentCenter;
    PyThrowBadHr(impObj()->get_TextTopAttachmentType(&rtVal));
    return (PyAcVerticalTextAttachmentType)rtVal;
}

void PyIAcadMLeaderImpl::SetTextTopAttachmentType(PyAcVerticalTextAttachmentType val) const
{
    PyThrowBadHr(impObj()->put_TextTopAttachmentType((AcVerticalTextAttachmentType)val));
}

PyAcVerticalTextAttachmentType PyIAcadMLeaderImpl::GetTextBottomAttachmentType() const
{
    AcVerticalTextAttachmentType rtVal = (AcVerticalTextAttachmentType)PyAcVerticalTextAttachmentType::pyacAttachmentCenter;
    PyThrowBadHr(impObj()->get_TextBottomAttachmentType(&rtVal));
    return (PyAcVerticalTextAttachmentType)rtVal;
}

void PyIAcadMLeaderImpl::SetTextBottomAttachmentType(PyAcVerticalTextAttachmentType val) const
{
    PyThrowBadHr(impObj()->put_TextBottomAttachmentType((AcVerticalTextAttachmentType)val));
}

double PyIAcadMLeaderImpl::GetLandingGap() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_LandingGap(&rtval));
    return rtval;
}

void PyIAcadMLeaderImpl::SetLandingGap(double val) const
{
    PyThrowBadHr(impObj()->put_LandingGap(val));
}

CString PyIAcadMLeaderImpl::GetArrowheadBlock() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_ArrowheadBlock(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadMLeaderImpl::SetArrowheadBlock(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_ArrowheadBlock(bstrval));
}

PyAcPredefBlockType PyIAcadMLeaderImpl::GetContentBlockType() const
{
    AcPredefBlockType rtVal = (AcPredefBlockType)PyAcPredefBlockType::pyacBlockImperial;
    PyThrowBadHr(impObj()->get_ContentBlockType(&rtVal));
    return (PyAcPredefBlockType)rtVal;
}

void PyIAcadMLeaderImpl::SetContentBlockType(PyAcPredefBlockType val) const
{
    PyThrowBadHr(impObj()->put_ContentBlockType((AcPredefBlockType)val));
}

int PyIAcadMLeaderImpl::GetLeaderCount() const
{
    int rtval = 0;
    PyThrowBadHr(impObj()->get_LeaderCount(&rtval));
    return rtval;
}

int PyIAcadMLeaderImpl::AddLeader() const
{
    int rtval = 0;
    PyThrowBadHr(impObj()->AddLeader(&rtval));
    return rtval;
}

void PyIAcadMLeaderImpl::RemoveLeader(int val) const
{
    PyThrowBadHr(impObj()->RemoveLeader(val));
}

int PyIAcadMLeaderImpl::AddLeaderLine(int leaderIndex, const Point3dCoordinates& coords) const
{
    int rtval = 0;
    _variant_t vtcoords;
    PyThrowBadHr(AcGePoint3dsToVariant(vtcoords, coords));
    PyThrowBadHr(impObj()->AddLeaderLine(leaderIndex, vtcoords, &rtval));
    return rtval;
}

int PyIAcadMLeaderImpl::AddLeaderLineEx(const Point3dCoordinates& coords) const
{
    int rtval = 0;
    _variant_t vtcoords;
    PyThrowBadHr(AcGePoint3dsToVariant(vtcoords, coords));
    PyThrowBadHr(impObj()->AddLeaderLineEx(vtcoords, &rtval));
    return rtval;
}

void PyIAcadMLeaderImpl::RemoveLeaderLine(int val) const
{
    PyThrowBadHr(impObj()->RemoveLeaderLine(val));
}

void PyIAcadMLeaderImpl::SetLeaderLineVertices(int leaderIndex, const Point3dCoordinates& coords) const
{
    _variant_t vtcoords;
    PyThrowBadHr(AcGePoint3dsToVariant(vtcoords, coords));
    PyThrowBadHr(impObj()->SetLeaderLineVertices(leaderIndex, vtcoords));
}

Point3dCoordinates PyIAcadMLeaderImpl::GetLeaderLineVertices(int leaderIndex) const
{
    _variant_t vtcoords;
    Point3dCoordinates coords;
    PyThrowBadHr(impObj()->GetLeaderLineVertices(leaderIndex, &vtcoords.GetVARIANT()));
    PyThrowBadHr(VariantToAcGePoint3ds(vtcoords, coords));
    return coords;
}

PyAcMLeaderContentType PyIAcadMLeaderImpl::GetContentType() const
{
    AcMLeaderContentType rtVal = (AcMLeaderContentType)PyAcMLeaderContentType::pyacNoneContent;
    PyThrowBadHr(impObj()->get_ContentType(&rtVal));
    return (PyAcMLeaderContentType)rtVal;
}

void PyIAcadMLeaderImpl::SetContentType(PyAcMLeaderContentType val) const
{
    PyThrowBadHr(impObj()->put_ContentType((AcMLeaderContentType)val));
}

int PyIAcadMLeaderImpl::GetLeaderIndex(int leaderLineIndex) const
{
    int rtval = 0;
    PyThrowBadHr(impObj()->GetLeaderIndex(leaderLineIndex, &rtval));
    return rtval;
}

Longs PyIAcadMLeaderImpl::GetLeaderLineIndexes(int leaderLineIndex) const
{
    _variant_t vtcoords;
    Longs coords;
    PyThrowBadHr(impObj()->GetLeaderLineIndexes(leaderLineIndex, &vtcoords.GetVARIANT()));
    PyThrowBadHr(VariantToLongArray(vtcoords, coords));
    return coords;
}

int PyIAcadMLeaderImpl::GetVertexCount(int leaderLineIndex) const
{
    int rtval = 0;
    PyThrowBadHr(impObj()->GetVertexCount(leaderLineIndex, &rtval));
    return rtval;
}

bool PyIAcadMLeaderImpl::GetTextFrameDisplay() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_TextFrameDisplay(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadMLeaderImpl::SetTextFrameDisplay(bool val) const
{
    PyThrowBadHr(impObj()->put_TextFrameDisplay(val ? VARIANT_TRUE : VARIANT_FALSE));
}

CString PyIAcadMLeaderImpl::GetStyleName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_StyleName(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadMLeaderImpl::SetStyleName(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_StyleName(bstrval));
}

AcGeVector3d PyIAcadMLeaderImpl::GetDoglegDirection(int leaderIndex) const
{
    AcGeVector3d val;
    _variant_t coord;
    PyThrowBadHr(impObj()->GetDoglegDirection(leaderIndex, &coord.GetVARIANT()));
    PyThrowBadHr(VariantToAcGeVector3d(coord, val));
    return val;
}

void PyIAcadMLeaderImpl::SetDoglegDirection(int leaderIndex, const AcGeVector3d& val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGeVector3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->SetDoglegDirection(leaderIndex, vtval));
}

CString PyIAcadMLeaderImpl::GetBlockAttributeValue(const AcDbObjectId& id) const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->GetBlockAttributeValue(id.asOldId(), &bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadMLeaderImpl::SetBlockAttributeValue(const AcDbObjectId& id, const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->SetBlockAttributeValue(id.asOldId(), bstrval));
}

IAcadMLeader* PyIAcadMLeaderImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadMLeader*>(m_pimpl.GetInterfacePtr());
}
