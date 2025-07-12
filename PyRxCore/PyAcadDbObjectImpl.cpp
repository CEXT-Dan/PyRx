#include "stdafx.h"
#include "PyAcadDbObjectImpl.h"
#include "PyAcadEntityImpl.h"
#include "PyAcadApplicationImpl.h"
#include "axmat3d.h"

//------------------------------------------------------------------------------------
// PyIAcad helpers
// this is duplicate code for sheet sets, though not for ZwCad or GsStar
#if defined(_ZRXTARGET)
extern HRESULT ZcAxGetIUnknownOfObject(LPUNKNOWN*, ZcDbObjectId&, LPDISPATCH);
extern HRESULT ZcAxGetIUnknownOfObject(LPUNKNOWN*, ZcDbObject*, LPDISPATCH);
extern HRESULT ZcAxGetDatabase(ZcDbDatabase* pDb, LPDISPATCH pAppDisp, LPDISPATCH* pDisp);
#define IID_IAcadObject IID_IZcadObject
#define IID_IAcadDatabase IID_IZcadDatabase
#define AcAxGetIUnknownOfObject ZcAxGetIUnknownOfObject
#define AcAxGetDatabase ZcAxGetDatabase
#elif defined(_GRXTARGET)
extern HRESULT GcAxGetIUnknownOfObject(LPUNKNOWN*, GcDbObjectId&, LPDISPATCH);
extern HRESULT GcAxGetIUnknownOfObject(LPUNKNOWN*, GcDbObject*, LPDISPATCH);
extern HRESULT GcAxGetDatabase(GcDbDatabase* pDb, LPDISPATCH pAppDisp, LPDISPATCH* pDisp);
#define IID_IAcadObject IID_IGcadObject
#define IID_IAcadDatabase IID_IGcadDatabase
#define AcAxGetIUnknownOfObject GcAxGetIUnknownOfObject
#define AcAxGetDatabase GcAxGetDatabase
#else
extern HRESULT AcAxGetIUnknownOfObject(LPUNKNOWN*, AcDbObjectId&, LPDISPATCH);
extern HRESULT AcAxGetIUnknownOfObject(LPUNKNOWN*, AcDbObject*, LPDISPATCH);
extern HRESULT AcAxGetDatabase(AcDbDatabase* pDb, LPDISPATCH pAppDisp, LPDISPATCH* pDisp);
#endif

IAcadObject* GetIAcadObjectFromAcDbObjectId(const AcDbObjectId& id)
{
    AcDbObjectId _id(id);
    IUnknown* pUnk = nullptr;
    LPDISPATCH pAppDisp = acedGetIDispatch(false);
    if (AcAxGetIUnknownOfObject(&pUnk, _id, pAppDisp) == S_OK && pUnk)
    {
        IAcadObject* pObj = nullptr;
        if (pUnk->QueryInterface(IID_IAcadObject, (void**)&pObj) == S_OK && pObj)
            return pObj;
    }
    return nullptr;
}

IAcadObject* GetIAcadObjectFromAcDbObject(AcDbObject* pSrcObject)
{
    IUnknown* pUnk = nullptr;
    LPDISPATCH pAppDisp = acedGetIDispatch(false);
    if (AcAxGetIUnknownOfObject(&pUnk, pSrcObject, pAppDisp) == S_OK && pUnk)
    {
        IAcadObject* pObj = nullptr;
        if (pUnk->QueryInterface(IID_IAcadObject, (void**)&pObj) == S_OK && pObj)
            return pObj;
    }
    return nullptr;
}

IAcadDatabase* GetIAcadDatabaseFromAcDbDatabse(AcDbDatabase* pSrcObject)
{
    LPDISPATCH pUnk = nullptr;
    LPDISPATCH pAppDisp = acedGetIDispatch(false);
    if (AcAxGetDatabase(pSrcObject, pAppDisp, &pUnk) == S_OK && pUnk)
    {
        IAcadDatabase* pObj = nullptr;
        if (pUnk->QueryInterface(IID_IAcadDatabase, (void**)&pObj) == S_OK && pObj)
            return pObj;
    }
    return nullptr;
}

//------------------------------------------------------------------------------------
//PyIAcadObjectImpl
PyIAcadObjectImpl::PyIAcadObjectImpl(IAcadObject* ptr)
    : m_pimpl(ptr)
{
}

CString PyIAcadObjectImpl::GetHandle() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Handle(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

CString PyIAcadObjectImpl::GetObjectName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_ObjectName(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

TypedVariants PyIAcadObjectImpl::GetXData(const CString& appName) const
{
    _variant_t xdataTypes;
    _variant_t xdataValues;
    _bstr_t bstrAppName{ appName };
    TypedVariants typedVariants;
    PyThrowBadHr(impObj()->GetXData(bstrAppName, &xdataTypes.GetVARIANT(), &xdataValues.GetVARIANT()));
    PyThrowBadHr(VariantToTypedVariants(xdataTypes, xdataValues, typedVariants));
    return typedVariants;
}

void PyIAcadObjectImpl::SetXData(const TypedVariants& typedVariants) const
{
    _variant_t xdataTypes;
    _variant_t xdataValues;
    PyThrowBadHr(TypedVariantsToVariants(typedVariants, xdataTypes, xdataValues));
    PyThrowBadHr(impObj()->SetXData(xdataTypes, xdataValues));
}

void PyIAcadObjectImpl::Delete() const
{
    PyThrowBadHr(impObj()->Delete());
}

LONG_PTR PyIAcadObjectImpl::GetObjectId() const
{
    LONG_PTR id = 0;
    PyThrowBadHr(impObj()->get_ObjectID(&id));
    return id;
}

LONG_PTR PyIAcadObjectImpl::GetOwnerId() const
{
    LONG_PTR id = 0;
    PyThrowBadHr(impObj()->get_OwnerID(&id));
    return id;
}

PyIAcadDatabasePtr PyIAcadObjectImpl::GetDatabase() const
{
    IAcadDatabase* pDb = nullptr;
    PyThrowBadHr(impObj()->get_Database(&pDb));
    return std::make_unique<PyIAcadDatabaseImpl>(pDb);
}

bool PyIAcadObjectImpl::GetHasExtensionDictionary() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_HasExtensionDictionary(&rtVal));
    return rtVal != VARIANT_FALSE;
}

PyIAcadDictionaryPtr PyIAcadObjectImpl::GetExtensionDictionary() const
{
    IAcadDictionary* pval = nullptr;
    PyThrowBadHr(impObj()->GetExtensionDictionary(&pval));
    return std::make_unique<PyIAcadDictionaryImpl>(pval);
}

PyIAcadDocumentPtr PyIAcadObjectImpl::GetDocument() const
{
    LPDISPATCH lpdsp = nullptr;
    PyThrowBadHr(impObj()->get_Document(&lpdsp));
    return std::make_unique<PyIAcadDocumentImpl>(static_cast<IAcadDocument*>(lpdsp));
}

void PyIAcadObjectImpl::Erase() const
{
    PyThrowBadHr(impObj()->Erase());
}

bool PyIAcadObjectImpl::IsEqualTo(const PyIAcadObjectImpl& other) const
{
    return other.m_pimpl == m_pimpl;
}

bool PyIAcadObjectImpl::IsNull() const
{
    return m_pimpl == nullptr;
}

std::size_t PyIAcadObjectImpl::hash() const
{
    return std::hash<IAcadObject*>{}((IAcadObject*)m_pimpl);
}

AcDbObjectId PyIAcadObjectImpl::id() const
{
    LONG_PTR id = 0;
    AcDbObjectId oid;
    PyThrowBadHr(impObj()->get_ObjectID(&id));
    return oid.setFromOldId(id);
}

IAcadObject* PyIAcadObjectImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadObject*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadPlotConfigurationImpl
PyIAcadPlotConfigurationImpl::PyIAcadPlotConfigurationImpl(IAcadPlotConfiguration* ptr)
    : PyIAcadObjectImpl(ptr)
{
}

CString PyIAcadPlotConfigurationImpl::GetName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Name(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadPlotConfigurationImpl::SetName(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_Name(bstrval));
}

CString PyIAcadPlotConfigurationImpl::GetConfigName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_ConfigName(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadPlotConfigurationImpl::SetConfigName(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_ConfigName(bstrval));
}

CString PyIAcadPlotConfigurationImpl::GetCanonicalMediaName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_CanonicalMediaName(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadPlotConfigurationImpl::SetCanonicalMediaName(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_CanonicalMediaName(bstrval));
}

PyAcPlotPaperUnits PyIAcadPlotConfigurationImpl::GetPaperUnits() const
{
    AcPlotPaperUnits rtVal = (AcPlotPaperUnits)PyAcPlotPaperUnits::pyacInches;
    PyThrowBadHr(impObj()->get_PaperUnits(&rtVal));
    return (PyAcPlotPaperUnits)rtVal;
}

void PyIAcadPlotConfigurationImpl::SetPaperUnits(PyAcPlotPaperUnits val) const
{
    PyThrowBadHr(impObj()->put_PaperUnits((AcPlotPaperUnits)val));
}

bool PyIAcadPlotConfigurationImpl::GetPlotViewportBorders() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_PlotViewportBorders(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPlotConfigurationImpl::SetPlotViewportBorders(bool val) const
{
    PyThrowBadHr(impObj()->put_PlotViewportBorders(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadPlotConfigurationImpl::GetShowPlotStyles() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_ShowPlotStyles(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPlotConfigurationImpl::SetShowPlotStyles(bool val) const
{
    PyThrowBadHr(impObj()->put_ShowPlotStyles(val ? VARIANT_TRUE : VARIANT_FALSE));
}

PyAcPlotRotation PyIAcadPlotConfigurationImpl::GetPlotRotation() const
{
    AcPlotRotation rtVal = (AcPlotRotation)PyAcPlotRotation::pyac0degrees;
    PyThrowBadHr(impObj()->get_PlotRotation(&rtVal));
    return (PyAcPlotRotation)rtVal;
}

void PyIAcadPlotConfigurationImpl::SetPlotRotation(PyAcPlotRotation val) const
{
    PyThrowBadHr(impObj()->put_PlotRotation((AcPlotRotation)val));
}

bool PyIAcadPlotConfigurationImpl::GetCenterPlot() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_CenterPlot(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPlotConfigurationImpl::SetCenterPlot(bool val) const
{
    PyThrowBadHr(impObj()->put_CenterPlot(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadPlotConfigurationImpl::GetPlotHidden() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_PlotHidden(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPlotConfigurationImpl::SetPlotHidden(bool val) const
{
    PyThrowBadHr(impObj()->put_PlotHidden(val ? VARIANT_TRUE : VARIANT_FALSE));
}

PyAcPlotType PyIAcadPlotConfigurationImpl::GetPlotType() const
{
    AcPlotType rtVal = (AcPlotType)PyAcPlotType::pyacDisplay;
    PyThrowBadHr(impObj()->get_PlotType(&rtVal));
    return (PyAcPlotType)rtVal;
}

void PyIAcadPlotConfigurationImpl::SetPlotType(PyAcPlotType val) const
{
    PyThrowBadHr(impObj()->put_PlotType((AcPlotType)val));
}

CString PyIAcadPlotConfigurationImpl::GetViewToPlot() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_ViewToPlot(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadPlotConfigurationImpl::SetViewToPlot(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_ViewToPlot(bstrval));
}

bool PyIAcadPlotConfigurationImpl::GetUseStandardScale() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_UseStandardScale(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPlotConfigurationImpl::SetUseStandardScale(bool val) const
{
    PyThrowBadHr(impObj()->put_UseStandardScale(val ? VARIANT_TRUE : VARIANT_FALSE));
}

PyAcPlotScale PyIAcadPlotConfigurationImpl::GetStandardScale() const
{
    AcPlotScale rtVal = (AcPlotScale)PyAcPlotScale::pyacScaleToFit;
    PyThrowBadHr(impObj()->get_StandardScale(&rtVal));
    return (PyAcPlotScale)rtVal;
}

void PyIAcadPlotConfigurationImpl::SetStandardScale(PyAcPlotScale val) const
{
    PyThrowBadHr(impObj()->put_StandardScale((AcPlotScale)val));
}

void PyIAcadPlotConfigurationImpl::GetCustomScale(double& numerator, double& denominator) const
{
    PyThrowBadHr(impObj()->GetCustomScale(&numerator, &denominator));
}

void PyIAcadPlotConfigurationImpl::SetCustomScale(double numerator, double denominator) const
{
    PyThrowBadHr(impObj()->SetCustomScale(numerator, denominator));
}

bool PyIAcadPlotConfigurationImpl::GetScaleLineweights() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_ScaleLineweights(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPlotConfigurationImpl::SetScaleLineweights(bool val) const
{
    PyThrowBadHr(impObj()->put_ScaleLineweights(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadPlotConfigurationImpl::GetPlotWithLineweights() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_PlotWithLineweights(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPlotConfigurationImpl::SetPlotWithLineweights(bool val) const
{
    PyThrowBadHr(impObj()->put_PlotWithLineweights(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadPlotConfigurationImpl::GetPlotViewportsFirst() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_PlotViewportsFirst(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPlotConfigurationImpl::SetPlotViewportsFirst(bool val) const
{
    PyThrowBadHr(impObj()->put_PlotViewportsFirst(val ? VARIANT_TRUE : VARIANT_FALSE));
}

CString PyIAcadPlotConfigurationImpl::GetStyleSheet() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_StyleSheet(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadPlotConfigurationImpl::SetStyleSheet(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_StyleSheet(bstrval));
}

void PyIAcadPlotConfigurationImpl::GetPaperMargins(AcGePoint2d& lowerLeft, AcGePoint2d& upperRight) const
{
    _variant_t vtlowerLeft;
    _variant_t vtupperRight;
    PyThrowBadHr(impObj()->GetPaperMargins(&vtlowerLeft.GetVARIANT(), &vtupperRight.GetVARIANT()));
    PyThrowBadHr(VariantToAcGePoint2d(vtlowerLeft, lowerLeft));
    PyThrowBadHr(VariantToAcGePoint2d(vtupperRight, upperRight));
}

void PyIAcadPlotConfigurationImpl::GetPaperSize(double& width, double& height) const
{
    PyThrowBadHr(impObj()->GetPaperSize(&width, &height));
}

AcGePoint2d PyIAcadPlotConfigurationImpl::GetPlotOrigin() const
{
    AcGePoint2d origin;
    _variant_t vtorigin;
    PyThrowBadHr(impObj()->get_PlotOrigin(&vtorigin.GetVARIANT()));
    PyThrowBadHr(VariantToAcGePoint2d(vtorigin, origin));
    return origin;
}

void PyIAcadPlotConfigurationImpl::SetPlotOrigin(const AcGePoint2d& orgin) const
{
    AcGePoint2d origin;
    _variant_t vtorigin;
    PyThrowBadHr(AcGePoint2dToVariant(vtorigin, origin));
    PyThrowBadHr(impObj()->put_PlotOrigin(vtorigin));
}

void PyIAcadPlotConfigurationImpl::GetWindowToPlot(AcGePoint2d& lowerLeft, AcGePoint2d& upperRight) const
{
    _variant_t vtlowerLeft;
    _variant_t vtupperRight;
    PyThrowBadHr(impObj()->GetWindowToPlot(&vtlowerLeft.GetVARIANT(), &vtupperRight.GetVARIANT()));
    PyThrowBadHr(VariantToAcGePoint2d(vtlowerLeft, lowerLeft));
    PyThrowBadHr(VariantToAcGePoint2d(vtupperRight, upperRight));
}

void PyIAcadPlotConfigurationImpl::SetWindowToPlot(const AcGePoint2d& lowerLeft, const AcGePoint2d& upperRight) const
{
    _variant_t vtlowerLeft;
    _variant_t vtupperRight;
    PyThrowBadHr(AcGePoint2dToVariant(vtlowerLeft, lowerLeft));
    PyThrowBadHr(AcGePoint2dToVariant(vtupperRight, upperRight));
    PyThrowBadHr(impObj()->SetWindowToPlot(vtlowerLeft, vtupperRight));
}

bool PyIAcadPlotConfigurationImpl::GetPlotWithPlotStyles() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_PlotWithPlotStyles(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPlotConfigurationImpl::SetPlotWithPlotStyles(bool val) const
{
    PyThrowBadHr(impObj()->put_PlotWithPlotStyles(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadPlotConfigurationImpl::GetModelType() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_ModelType(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadPlotConfigurationImpl::CopyFrom(const PyIAcadPlotConfigurationImpl& val) const
{
    PyThrowBadHr(impObj()->CopyFrom(val.impObj()));
}

wstringArray PyIAcadPlotConfigurationImpl::GetCanonicalMediaNames() const
{
    _variant_t vtstrs;
    wstringArray strs;
    PyThrowBadHr(impObj()->GetCanonicalMediaNames(&vtstrs.GetVARIANT()));
    PyThrowBadHr(VariantTowstringArray(vtstrs, strs));
    return strs;
}

wstringArray PyIAcadPlotConfigurationImpl::GetPlotDeviceNames() const
{
    _variant_t vtstrs;
    wstringArray strs;
    PyThrowBadHr(impObj()->GetPlotDeviceNames(&vtstrs.GetVARIANT()));
    PyThrowBadHr(VariantTowstringArray(vtstrs, strs));
    return strs;
}

wstringArray PyIAcadPlotConfigurationImpl::GetPlotStyleTableNames() const
{
    _variant_t vtstrs;
    wstringArray strs;
    PyThrowBadHr(impObj()->GetPlotStyleTableNames(&vtstrs.GetVARIANT()));
    PyThrowBadHr(VariantTowstringArray(vtstrs, strs));
    return strs;
}

void PyIAcadPlotConfigurationImpl::RefreshPlotDeviceInfo() const
{
    PyThrowBadHr(impObj()->RefreshPlotDeviceInfo());
}

CString PyIAcadPlotConfigurationImpl::GetLocaleMediaName(const CString& name) const
{
    _bstr_t bstrVal;
    _bstr_t bstrname{ name };
    PyThrowBadHr(impObj()->GetLocaleMediaName(bstrname, &bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

IAcadPlotConfiguration* PyIAcadPlotConfigurationImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadPlotConfiguration*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadLayoutImpl
PyIAcadLayoutImpl::PyIAcadLayoutImpl(IAcadLayout* ptr)
    : PyIAcadPlotConfigurationImpl(ptr)
{
}

PyIAcadBlockPtr PyIAcadLayoutImpl::GetBlock() const
{
    IAcadBlock* pBlock = nullptr;
    PyThrowBadHr(impObj()->get_Block(&pBlock));
    return std::make_unique<PyIAcadBlockImpl>(pBlock);
}

long PyIAcadLayoutImpl::GetTabOrder() const
{
    long rtval = 0;
    PyThrowBadHr(impObj()->get_TabOrder(&rtval));
    return rtval;
}

void PyIAcadLayoutImpl::SetTabOrder(long val) const
{
    PyThrowBadHr(impObj()->put_TabOrder(val));
}

IAcadLayout* PyIAcadLayoutImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadLayout*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadSectionSettingsImpl
PyIAcadSectionSettingsImpl::PyIAcadSectionSettingsImpl(IAcadSectionSettings* ptr)
    : PyIAcadObjectImpl(ptr)
{
}

PyAcSectionType PyIAcadSectionSettingsImpl::GetCurrentSectionType() const
{
    AcSectionType rtVal = (AcSectionType)PyAcSectionType::pyacSectionTypeLiveSection;
    PyThrowBadHr(impObj()->get_CurrentSectionType(&rtVal));
    return (PyAcSectionType)rtVal;
}

void PyIAcadSectionSettingsImpl::SetCurrentSectionType(PyAcSectionType val) const
{
    PyThrowBadHr(impObj()->put_CurrentSectionType((AcSectionType)val));
}

PyIAcadSectionTypeSettingsPtr PyIAcadSectionSettingsImpl::GetSectionTypeSettings(PyAcSectionType secType) const
{
    IAcadSectionTypeSettings* ptr = nullptr;
    PyThrowBadHr(impObj()->GetSectionTypeSettings((AcSectionType)secType, &ptr));
    return std::make_unique<PyIAcadSectionTypeSettingsImpl>(ptr);
}

IAcadSectionSettings* PyIAcadSectionSettingsImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadSectionSettings*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadViewImpl
PyIAcadViewImpl::PyIAcadViewImpl(IAcadView* ptr)
    : PyIAcadObjectImpl(ptr)
{
}

AcGePoint3d PyIAcadViewImpl::GetCenter() const
{
    _variant_t vtval;
    AcGePoint3d rtVal;
    PyThrowBadHr(impObj()->get_Center(&vtval));
    PyThrowBadHr(VariantToAcGePoint3d(vtval, rtVal));
    return rtVal;
}

void PyIAcadViewImpl::SetCenter(const AcGePoint3d& val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGePoint3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_Center(vtval));
}

double PyIAcadViewImpl::GetHeight() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_Height(&rtval));
    return rtval;
}

void PyIAcadViewImpl::SetHeight(double val) const
{
    PyThrowBadHr(impObj()->put_Height(val));
}

double PyIAcadViewImpl::GetWidth() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_Width(&rtval));
    return rtval;
}

void PyIAcadViewImpl::SetWidth(double val) const
{
    PyThrowBadHr(impObj()->put_Width(val));
}

AcGePoint3d PyIAcadViewImpl::GetTarget() const
{
    _variant_t vtval;
    AcGePoint3d rtVal;
    PyThrowBadHr(impObj()->get_Target(&vtval));
    PyThrowBadHr(VariantToAcGePoint3d(vtval, rtVal));
    return rtVal;
}

void PyIAcadViewImpl::SetTarget(const AcGePoint3d& val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGePoint3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_Target(vtval));
}

AcGeVector3d PyIAcadViewImpl::GetDirection() const
{
    AcGeVector3d val;
    _variant_t coord;
    PyThrowBadHr(impObj()->get_Direction(&coord.GetVARIANT()));
    PyThrowBadHr(VariantToAcGeVector3d(coord, val));
    return val;
}

void PyIAcadViewImpl::SetDirection(const AcGeVector3d& val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGeVector3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_Direction(vtval));
}

CString PyIAcadViewImpl::GetName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Name(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadViewImpl::SetName(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_Name(bstrval));
}

CString PyIAcadViewImpl::GetCategoryName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_CategoryName(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadViewImpl::SetCategoryName(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_CategoryName(bstrval));
}

AcDbObjectId PyIAcadViewImpl::GetLayoutId() const
{
    AcDbObjectId id;
    LONG_PTR rtval = 0;
    PyThrowBadHr(impObj()->get_LayoutId(&rtval));
    id.setFromOldId(rtval);
    return id;
}

void PyIAcadViewImpl::SetLayoutId(const AcDbObjectId& val) const
{
    PyThrowBadHr(impObj()->put_LayoutId(val.asOldId()));
}

CString PyIAcadViewImpl::GetLayerState() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_LayerState(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadViewImpl::SetLayerState(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_LayerState(bstrval));
}

bool PyIAcadViewImpl::GetHasVpAssociation() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_HasVpAssociation(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadViewImpl::SetHasVpAssociation(bool val) const
{
    PyThrowBadHr(impObj()->put_HasVpAssociation(val ? VARIANT_TRUE : VARIANT_FALSE));
}

IAcadView* PyIAcadViewImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadView*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadGroupImpl
PyIAcadGroupImpl::PyIAcadGroupImpl(IAcadGroup* ptr)
    : PyIAcadObjectImpl(ptr)
{
}

PyIAcadEntityPtr PyIAcadGroupImpl::GetItem(long ind) const
{
    _variant_t vtind{ ind };
    IAcadEntity* ptr = nullptr;
    PyThrowBadHr(impObj()->Item(vtind, &ptr));
    return std::make_unique<PyIAcadEntityImpl>(ptr);
}

PyIAcadEntityPtrArray PyIAcadGroupImpl::GetIter() const
{
    IUnknownPtr pUnk;
    IEnumVARIANTPtr vtenum;
    PyIAcadEntityPtrArray vec;
    PyThrowBadHr(impObj()->get__NewEnum((IUnknown**)&pUnk));
    PyThrowBadHr(pUnk->QueryInterface(IID_IEnumVARIANT, (void**)&vtenum));
    {
        HRESULT hr = S_OK;
        for (unsigned long idx = 0, iout = 0; hr == S_OK; idx++)
        {
            _variant_t item;
            if (hr = vtenum->Next(1, &item.GetVARIANT(), &iout); hr == S_OK)
                vec.emplace_back(std::make_shared<PyIAcadEntityImpl>((IAcadEntity*)(IDispatch*)item));
        }
    }
    return vec;
}

long PyIAcadGroupImpl::GetCount() const
{
    long ind = 0;
    PyThrowBadHr(impObj()->get_Count(&ind));
    return ind;
}

void PyIAcadGroupImpl::SetTrueColor(const PyIAcadAcCmColorImpl& val) const
{
    PyThrowBadHr(impObj()->put_TrueColor(val.impObj()));
}

void PyIAcadGroupImpl::SetLayer(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_Layer(bstrval));
}

void PyIAcadGroupImpl::SetLinetype(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_Linetype(bstrval));
}

void PyIAcadGroupImpl::SetLinetypeScale(double val) const
{
    PyThrowBadHr(impObj()->put_LinetypeScale(val));
}

void PyIAcadGroupImpl::SetVisible(bool val) const
{
    PyThrowBadHr(impObj()->put_Visible(val ? VARIANT_TRUE : VARIANT_FALSE));
}

void PyIAcadGroupImpl::Highlight(bool val) const
{
    PyThrowBadHr(impObj()->Highlight(val ? VARIANT_TRUE : VARIANT_FALSE));
}

void PyIAcadGroupImpl::SetPlotStyleName(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_PlotStyleName(bstrval));
}

void PyIAcadGroupImpl::SetLineWeight(PyAcLineWeight val) const
{
    PyThrowBadHr(impObj()->put_Lineweight((AcLineWeight)val));
}

CString PyIAcadGroupImpl::GetName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Name(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadGroupImpl::SetName(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_Name(bstrval));
}

void PyIAcadGroupImpl::AppendItems(const PyIAcadEntityImplArray& entities) const
{
    _variant_t  vtentities;
    PyThrowBadHr(PyIAcadEntityImplArrayToVariant(vtentities, entities));
    PyThrowBadHr(impObj()->AppendItems(vtentities));
}

void PyIAcadGroupImpl::RemoveItems(const PyIAcadEntityImplArray& entities) const
{
    _variant_t  vtentities;
    PyThrowBadHr(PyIAcadEntityImplArrayToVariant(vtentities, entities));;
    PyThrowBadHr(impObj()->RemoveItems(vtentities));
}

void PyIAcadGroupImpl::Update() const
{
    PyThrowBadHr(impObj()->Update());
}

void PyIAcadGroupImpl::SetMaterial(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_Material(bstrval));
}

void PyIAcadGroupImpl::SetColor(PyAcColor val) const
{
    PyThrowBadHr(impObj()->put_color((AcColor)val));
}

IAcadGroup* PyIAcadGroupImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadGroup*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadGroupsImpl
PyIAcadGroupsImpl::PyIAcadGroupsImpl(IAcadGroups* ptr)
    : PyIAcadObjectImpl(ptr)
{
}

PyIAcadGroupPtr PyIAcadGroupsImpl::GetItem(long ind) const
{
    _variant_t vtind{ ind };
    IAcadGroup* ptr = nullptr;
    PyThrowBadHr(impObj()->Item(vtind, &ptr));
    return std::make_unique<PyIAcadGroupImpl>(ptr);
}

long PyIAcadGroupsImpl::GetCount() const
{
    long ind = 0;
    PyThrowBadHr(impObj()->get_Count(&ind));
    return ind;
}

PyIAcadGroupPtr PyIAcadGroupsImpl::Add(const CString& name) const
{
    _bstr_t bstrVal{ name };
    IAcadGroup* ptr = nullptr;
    PyThrowBadHr(impObj()->Add(bstrVal, &ptr));
    return std::make_unique<PyIAcadGroupImpl>(ptr);
}

PyIAcadGroupPtrArray PyIAcadGroupsImpl::GetIter() const
{
    IUnknownPtr pUnk;
    IEnumVARIANTPtr vtenum;
    PyIAcadGroupPtrArray vec;
    PyThrowBadHr(impObj()->get__NewEnum((IUnknown**)&pUnk));
    PyThrowBadHr(pUnk->QueryInterface(IID_IEnumVARIANT, (void**)&vtenum));
    {
        HRESULT hr = S_OK;
        for (unsigned long idx = 0, iout = 0; hr == S_OK; idx++)
        {
            _variant_t item;
            if (hr = vtenum->Next(1, &item.GetVARIANT(), &iout); hr == S_OK)
                vec.emplace_back(std::make_shared<PyIAcadGroupImpl>((IAcadGroup*)(IDispatch*)item));
        }
    }
    return vec;
}

IAcadGroups* PyIAcadGroupsImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadGroups*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadDimStyleImpl
PyIAcadDimStyleImpl::PyIAcadDimStyleImpl(IAcadDimStyle* ptr)
    : PyIAcadObjectImpl(ptr)
{
}

CString PyIAcadDimStyleImpl::GetName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Name(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadDimStyleImpl::SetName(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_Name(bstrval));
}

void PyIAcadDimStyleImpl::CopyFrom(const PyIAcadObjectImpl& val) const
{
    PyThrowBadHr(impObj()->CopyFrom(val.impObj()));
}

IAcadDimStyle* PyIAcadDimStyleImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadDimStyle*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadDimStylesImpl
PyIAcadDimStylesImpl::PyIAcadDimStylesImpl(IAcadDimStyles* ptr)
    : PyIAcadObjectImpl(ptr)
{
}

PyIAcadDimStylePtr PyIAcadDimStylesImpl::GetItem(long ind) const
{
    _variant_t vtind{ ind };
    IAcadDimStyle* ptr = nullptr;
    PyThrowBadHr(impObj()->Item(vtind, &ptr));
    return std::make_unique<PyIAcadDimStyleImpl>(ptr);
}

long PyIAcadDimStylesImpl::GetCount() const
{
    long ind = 0;
    PyThrowBadHr(impObj()->get_Count(&ind));
    return ind;
}

PyIAcadDimStylePtr PyIAcadDimStylesImpl::Add(const CString& name) const
{
    _bstr_t bstrVal{ name };
    IAcadDimStyle* ptr = nullptr;
    PyThrowBadHr(impObj()->Add(bstrVal, &ptr));
    return std::make_unique<PyIAcadDimStyleImpl>(ptr);
}

PyIAcadDimStylePtrArray PyIAcadDimStylesImpl::GetIter() const
{
    IUnknownPtr pUnk;
    IEnumVARIANTPtr vtenum;
    PyIAcadDimStylePtrArray vec;
    PyThrowBadHr(impObj()->get__NewEnum((IUnknown**)&pUnk));
    PyThrowBadHr(pUnk->QueryInterface(IID_IEnumVARIANT, (void**)&vtenum));
    {
        HRESULT hr = S_OK;
        for (unsigned long idx = 0, iout = 0; hr == S_OK; idx++)
        {
            _variant_t item;
            if (hr = vtenum->Next(1, &item.GetVARIANT(), &iout); hr == S_OK)
                vec.emplace_back(std::make_shared<PyIAcadDimStyleImpl>((IAcadDimStyle*)(IDispatch*)item));
        }
    }
    return vec;
}

IAcadDimStyles* PyIAcadDimStylesImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadDimStyles*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadLayerImpl
PyIAcadLayerImpl::PyIAcadLayerImpl(IAcadLayer* ptr)
    : PyIAcadObjectImpl(ptr)
{
}

PyAcColor PyIAcadLayerImpl::GetColor() const
{
    AcColor rtVal = (AcColor)PyAcColor::pyacByLayer;
    PyThrowBadHr(impObj()->get_color(&rtVal));
    return (PyAcColor)rtVal;
}

void PyIAcadLayerImpl::SetColor(PyAcColor val) const
{
    PyThrowBadHr(impObj()->put_color((AcColor)val));
}

PyIAcadAcCmColorPtr PyIAcadLayerImpl::GetTrueColor() const
{
    IAcadAcCmColor* ptr = nullptr;
    PyThrowBadHr(impObj()->get_TrueColor(&ptr));
    return std::make_unique<PyIAcadAcCmColorImpl>(ptr);
}

void PyIAcadLayerImpl::SetTrueColor(const PyIAcadAcCmColorImpl& val) const
{
    PyThrowBadHr(impObj()->put_TrueColor(val.impObj()));
}

bool PyIAcadLayerImpl::GetFreeze() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_Freeze(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadLayerImpl::SetFreeze(bool val) const
{
    PyThrowBadHr(impObj()->put_Freeze(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadLayerImpl::GetLayerOn() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_LayerOn(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadLayerImpl::SetLayerOn(bool val) const
{
    PyThrowBadHr(impObj()->put_LayerOn(val ? VARIANT_TRUE : VARIANT_FALSE));
}

CString PyIAcadLayerImpl::GetLinetype() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Linetype(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadLayerImpl::SetLinetype(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_Linetype(bstrval));
}

bool PyIAcadLayerImpl::GetLock() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_Lock(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadLayerImpl::SetLock(bool val) const
{
    PyThrowBadHr(impObj()->put_Lock(val ? VARIANT_TRUE : VARIANT_FALSE));
}

CString PyIAcadLayerImpl::GetName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Name(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadLayerImpl::SetName(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_Name(bstrval));
}

bool PyIAcadLayerImpl::GetPlottable() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_Plottable(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadLayerImpl::SetPlottable(bool val) const
{
    PyThrowBadHr(impObj()->put_Plottable(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadLayerImpl::GetViewportDefault() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_ViewportDefault(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadLayerImpl::SetViewportDefault(bool val) const
{
    PyThrowBadHr(impObj()->put_ViewportDefault(val ? VARIANT_TRUE : VARIANT_FALSE));
}

CString PyIAcadLayerImpl::GetPlotStyleName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_PlotStyleName(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadLayerImpl::SetPlotStyleName(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_PlotStyleName(bstrval));
}

PyAcLineWeight PyIAcadLayerImpl::GetLineweight() const
{
    AcLineWeight rtVal = (AcLineWeight)PyAcLineWeight::pyacLnWt000;
    PyThrowBadHr(impObj()->get_Lineweight(&rtVal));
    return (PyAcLineWeight)rtVal;
}

void PyIAcadLayerImpl::SetLineWeight(PyAcLineWeight val) const
{
    PyThrowBadHr(impObj()->put_Lineweight((AcLineWeight)val));
}

CString PyIAcadLayerImpl::GetDescription() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Description(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadLayerImpl::SetDescription(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_Description(bstrval));
}

bool PyIAcadLayerImpl::GetUsed() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_Used(&rtVal));
    return rtVal != VARIANT_FALSE;
}

CString PyIAcadLayerImpl::GetMaterial() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Material(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadLayerImpl::SetMaterial(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_Material(bstrval));
}

IAcadLayer* PyIAcadLayerImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadLayer*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadLayersImpl
PyIAcadLayersImpl::PyIAcadLayersImpl(IAcadLayers* ptr)
    : PyIAcadObjectImpl(ptr)
{
}

PyIAcadLayerPtr PyIAcadLayersImpl::GetItem(long ind) const
{
    _variant_t vtind{ ind };
    IAcadLayer* ptr = nullptr;
    PyThrowBadHr(impObj()->Item(vtind, &ptr));
    return std::make_unique<PyIAcadLayerImpl>(ptr);
}

long PyIAcadLayersImpl::GetCount() const
{
    long ind = 0;
    PyThrowBadHr(impObj()->get_Count(&ind));
    return ind;
}

PyIAcadLayerPtr PyIAcadLayersImpl::Add(const CString& name) const
{
    _bstr_t bstrVal{ name };
    IAcadLayer* ptr = nullptr;
    PyThrowBadHr(impObj()->Add(bstrVal, &ptr));
    return std::make_unique<PyIAcadLayerImpl>(ptr);
}

PyIAcadLayerPtrArray PyIAcadLayersImpl::GetIter() const
{
    IUnknownPtr pUnk;
    IEnumVARIANTPtr vtenum;
    PyIAcadLayerPtrArray vec;
    PyThrowBadHr(impObj()->get__NewEnum((IUnknown**)&pUnk));
    PyThrowBadHr(pUnk->QueryInterface(IID_IEnumVARIANT, (void**)&vtenum));
    {
        HRESULT hr = S_OK;
        for (unsigned long idx = 0, iout = 0; hr == S_OK; idx++)
        {
            _variant_t item;
            if (hr = vtenum->Next(1, &item.GetVARIANT(), &iout); hr == S_OK)
                vec.emplace_back(std::make_shared<PyIAcadLayerImpl>((IAcadLayer*)(IDispatch*)item));
        }
    }
    return vec;
}

IAcadLayers* PyIAcadLayersImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadLayers*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadLineTypeImpl
PyIAcadLineTypeImpl::PyIAcadLineTypeImpl(IAcadLineType* ptr)
    : PyIAcadObjectImpl(ptr)
{
}

CString PyIAcadLineTypeImpl::GetName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Name(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadLineTypeImpl::SetName(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_Name(bstrval));
}

CString PyIAcadLineTypeImpl::GetDescription() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Description(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadLineTypeImpl::SetDescription(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_Description(bstrval));
}

IAcadLineType* PyIAcadLineTypeImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadLineType*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadLineTypesImpl
PyIAcadLineTypesImpl::PyIAcadLineTypesImpl(IAcadLineTypes* ptr)
    : PyIAcadObjectImpl(ptr)
{
}

PyIAcadLineTypePtr PyIAcadLineTypesImpl::GetItem(long ind) const
{
    _variant_t vtind{ ind };
    IAcadLineType* ptr = nullptr;
    PyThrowBadHr(impObj()->Item(vtind, &ptr));
    return std::make_unique<PyIAcadLineTypeImpl>(ptr);

}

long PyIAcadLineTypesImpl::GetCount() const
{
    long ind = 0;
    PyThrowBadHr(impObj()->get_Count(&ind));
    return ind;
}

PyIAcadLineTypePtr PyIAcadLineTypesImpl::Add(const CString& name) const
{
    _bstr_t bstrVal{ name };
    IAcadLineType* ptr = nullptr;
    PyThrowBadHr(impObj()->Add(bstrVal, &ptr));
    return std::make_unique<PyIAcadLineTypeImpl>(ptr);
}

PyIAcadLineTypePtrArray PyIAcadLineTypesImpl::GetIter() const
{
    IUnknownPtr pUnk;
    IEnumVARIANTPtr vtenum;
    PyIAcadLineTypePtrArray vec;
    PyThrowBadHr(impObj()->get__NewEnum((IUnknown**)&pUnk));
    PyThrowBadHr(pUnk->QueryInterface(IID_IEnumVARIANT, (void**)&vtenum));
    {
        HRESULT hr = S_OK;
        for (unsigned long idx = 0, iout = 0; hr == S_OK; idx++)
        {
            _variant_t item;
            if (hr = vtenum->Next(1, &item.GetVARIANT(), &iout); hr == S_OK)
                vec.emplace_back(std::make_shared<PyIAcadLineTypeImpl>((IAcadLineType*)(IDispatch*)item));
        }
    }
    return vec;
}

IAcadLineTypes* PyIAcadLineTypesImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadLineTypes*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadXRecordImpl
PyIAcadXRecordImpl::PyIAcadXRecordImpl(IAcadXRecord* ptr)
    : PyIAcadObjectImpl(ptr)
{
}

CString PyIAcadXRecordImpl::GetName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Name(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadXRecordImpl::SetName(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_Name(bstrval));
}

TypedVariants PyIAcadXRecordImpl::GetXRecordData() const
{
    _variant_t xdataTypes;
    _variant_t xdataValues;
    TypedVariants typedVariants;
    PyThrowBadHr(impObj()->GetXRecordData(&xdataTypes.GetVARIANT(), &xdataValues.GetVARIANT()));
    PyThrowBadHr(VariantToTypedVariants(xdataTypes, xdataValues, typedVariants));
    return typedVariants;
}

void PyIAcadXRecordImpl::SetXRecordData(const TypedVariants& typedVariants) const
{
    _variant_t xdataTypes;
    _variant_t xdataValues;
    PyThrowBadHr(TypedVariantsToVariants(typedVariants, xdataTypes, xdataValues));
    PyThrowBadHr(impObj()->SetXRecordData(xdataTypes, xdataValues));
}

bool PyIAcadXRecordImpl::GetTranslateIDs() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_TranslateIDs(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadXRecordImpl::SetTranslateIDs(bool val) const
{
    PyThrowBadHr(impObj()->put_TranslateIDs(val ? VARIANT_TRUE : VARIANT_FALSE));
}

IAcadXRecord* PyIAcadXRecordImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadXRecord*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadDictionaryImpl
PyIAcadDictionaryImpl::PyIAcadDictionaryImpl(IAcadDictionary* ptr)
    : PyIAcadObjectImpl(ptr)
{
}

CString PyIAcadDictionaryImpl::GetName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Name(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

CString PyIAcadDictionaryImpl::GetName(const PyIAcadObjectImpl& src) const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->GetName(src.impObj(), &bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

PyIAcadObjectPtr PyIAcadDictionaryImpl::GetObject(const CString& objectName) const
{
    IAcadObject* pObj = nullptr;
    _bstr_t bstrobjectName{ objectName };
    PyThrowBadHr(impObj()->GetObject(bstrobjectName, &pObj));
    return std::make_unique<PyIAcadObjectImpl>(pObj);
}

PyIAcadObjectPtr PyIAcadDictionaryImpl::Remove(const CString& objectName) const
{
    IAcadObject* pObj = nullptr;
    _bstr_t bstrobjectName{ objectName };
    PyThrowBadHr(impObj()->Remove(bstrobjectName, &pObj));
    return std::make_unique<PyIAcadObjectImpl>(pObj);
}

void PyIAcadDictionaryImpl::Rename(const CString& oldName, const CString& newName) const
{
    _bstr_t bstroldName{ oldName };
    _bstr_t bstrnewName{ newName };
    PyThrowBadHr(impObj()->Rename(bstroldName, bstrnewName));
}

void PyIAcadDictionaryImpl::Replace(const CString& oldName, const PyIAcadObjectImpl& src) const
{
    _bstr_t bstroldName{ oldName };
    PyThrowBadHr(impObj()->Replace(bstroldName, src.impObj()));
}

PyIAcadObjectPtr PyIAcadDictionaryImpl::GetItem(long idx) const
{
    _variant_t vtidx{ idx };
    IAcadObject* pObj = nullptr;
    PyThrowBadHr(impObj()->Item(vtidx, &pObj));
    return std::make_unique<PyIAcadObjectImpl>(pObj);
}

PyIAcadObjectPtrArray PyIAcadDictionaryImpl::GetIter() const
{
    IUnknownPtr pUnk;
    IEnumVARIANTPtr vtenum;
    PyIAcadObjectPtrArray vec;
    PyThrowBadHr(impObj()->get__NewEnum((IUnknown**)&pUnk));
    PyThrowBadHr(pUnk->QueryInterface(IID_IEnumVARIANT, (void**)&vtenum));
    {
        HRESULT hr = S_OK;
        for (unsigned long idx = 0, iout = 0; hr == S_OK; idx++)
        {
            _variant_t item;
            if (hr = vtenum->Next(1, &item.GetVARIANT(), &iout); hr == S_OK)
                vec.emplace_back(std::make_shared<PyIAcadObjectImpl>((IAcadObject*)(IDispatch*)item));
        }
    }
    return vec;
}

long PyIAcadDictionaryImpl::GetCount() const
{
    long rtval = 0;
    PyThrowBadHr(impObj()->get_Count(&rtval));
    return rtval;
}

PyIAcadXRecordPtr PyIAcadDictionaryImpl::AddXRecord(const CString& keyword) const
{
    IAcadXRecord* pObj = nullptr;
    _bstr_t bstrkeyword{ keyword };
    PyThrowBadHr(impObj()->AddXRecord(bstrkeyword, &pObj));
    return std::make_unique<PyIAcadXRecordImpl>(pObj);
}

void PyIAcadDictionaryImpl::SetName(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_Name(bstrval));
}

PyIAcadObjectPtr PyIAcadDictionaryImpl::AddObject(const CString& keyword, const CString& objectName) const
{
    IAcadObject* pObj = nullptr;
    _bstr_t bstrkeyword{ keyword };
    _bstr_t bstrobjectName{ objectName };
    PyThrowBadHr(impObj()->AddObject(bstrkeyword, bstrobjectName, &pObj));
    return std::make_unique<PyIAcadObjectImpl>(pObj);
}

IAcadDictionary* PyIAcadDictionaryImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadDictionary*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadDictionariesImpl
PyIAcadDictionariesImpl::PyIAcadDictionariesImpl(IAcadDictionaries* ptr)
    : PyIAcadObjectImpl(ptr)
{
}

PyIAcadDictionaryPtr PyIAcadDictionariesImpl::GetItem(long ind) const
{
    _variant_t vtind{ ind };
    IAcadObject* ptr = nullptr;
    PyThrowBadHr(impObj()->Item(vtind, &ptr));
    return std::make_unique<PyIAcadDictionaryImpl>((IAcadDictionary*)ptr);
}

long PyIAcadDictionariesImpl::GetCount() const
{
    long ind = 0;
    PyThrowBadHr(impObj()->get_Count(&ind));
    return ind;
}

PyIAcadDictionaryPtr PyIAcadDictionariesImpl::Add(const CString& name) const
{
    _bstr_t bstrVal{ name };
    IAcadDictionary* ptr = nullptr;
    PyThrowBadHr(impObj()->Add(bstrVal, &ptr));
    return std::make_unique<PyIAcadDictionaryImpl>((IAcadDictionary*)ptr);
}

PyIAcadDictionaryPtrArray PyIAcadDictionariesImpl::GetIter() const
{
    IUnknownPtr pUnk;
    IEnumVARIANTPtr vtenum;
    PyIAcadDictionaryPtrArray vec;
    PyThrowBadHr(impObj()->get__NewEnum((IUnknown**)&pUnk));
    PyThrowBadHr(pUnk->QueryInterface(IID_IEnumVARIANT, (void**)&vtenum));
    {
        HRESULT hr = S_OK;
        for (unsigned long idx = 0, iout = 0; hr == S_OK; idx++)
        {
            _variant_t item;
            if (hr = vtenum->Next(1, &item.GetVARIANT(), &iout); hr == S_OK)
                vec.emplace_back(std::make_shared<PyIAcadDictionaryImpl>((IAcadDictionary*)(IDispatch*)item));
        }
    }
    return vec;
}

IAcadDictionaries* PyIAcadDictionariesImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadDictionaries*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadRegisteredApplicationImpl
PyIAcadRegisteredApplicationImpl::PyIAcadRegisteredApplicationImpl(IAcadRegisteredApplication* ptr)
    : PyIAcadObjectImpl(ptr)
{
}

CString PyIAcadRegisteredApplicationImpl::GetName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Name(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadRegisteredApplicationImpl::SetName(const CString& val) const
{
    _bstr_t bstrVal{ val };
    PyThrowBadHr(impObj()->put_Name(bstrVal));
}

IAcadRegisteredApplication* PyIAcadRegisteredApplicationImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadRegisteredApplication*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadRegisteredApplicationsImpl
PyIAcadRegisteredApplicationsImpl::PyIAcadRegisteredApplicationsImpl(IAcadRegisteredApplications* ptr)
    : PyIAcadObjectImpl(ptr)
{
}

PyIAcadRegisteredApplicationPtr PyIAcadRegisteredApplicationsImpl::GetItem(long ind) const
{
    _variant_t vtind{ ind };
    IAcadRegisteredApplication* ptr = nullptr;
    PyThrowBadHr(impObj()->Item(vtind, &ptr));
    return std::make_unique<PyIAcadRegisteredApplicationImpl>(ptr);
}

long PyIAcadRegisteredApplicationsImpl::GetCount() const
{
    long ind = 0;
    PyThrowBadHr(impObj()->get_Count(&ind));
    return ind;
}

PyIAcadRegisteredApplicationPtr PyIAcadRegisteredApplicationsImpl::Add(const CString& name) const
{
    _bstr_t bstrVal{ name };
    IAcadRegisteredApplication* ptr = nullptr;
    PyThrowBadHr(impObj()->Add(bstrVal, &ptr));
    return std::make_unique<PyIAcadRegisteredApplicationImpl>(ptr);
}

PyIAcadRegisteredApplicationPtrArray PyIAcadRegisteredApplicationsImpl::GetIter() const
{
    IUnknownPtr pUnk;
    IEnumVARIANTPtr vtenum;
    PyIAcadRegisteredApplicationPtrArray vec;
    PyThrowBadHr(impObj()->get__NewEnum((IUnknown**)&pUnk));
    PyThrowBadHr(pUnk->QueryInterface(IID_IEnumVARIANT, (void**)&vtenum));
    {
        HRESULT hr = S_OK;
        for (unsigned long idx = 0, iout = 0; hr == S_OK; idx++)
        {
            _variant_t item;
            if (hr = vtenum->Next(1, &item.GetVARIANT(), &iout); hr == S_OK)
                vec.emplace_back(std::make_shared<PyIAcadRegisteredApplicationImpl>((IAcadRegisteredApplication*)(IDispatch*)item));
        }
    }
    return vec;
}

IAcadRegisteredApplications* PyIAcadRegisteredApplicationsImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadRegisteredApplications*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadTextStyleImpl
PyIAcadTextStyleImpl::PyIAcadTextStyleImpl(IAcadTextStyle* ptr)
    : PyIAcadObjectImpl(ptr)
{
}

CString PyIAcadTextStyleImpl::GetBigFontFile() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_BigFontFile(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadTextStyleImpl::SetBigFontFile(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_BigFontFile(bstrval));
}

CString PyIAcadTextStyleImpl::GetFontFile() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_fontFile(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadTextStyleImpl::SetFontFile(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_fontFile(bstrval));
}

double PyIAcadTextStyleImpl::GetHeight() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_Height(&rtval));
    return rtval;
}

void PyIAcadTextStyleImpl::SetHeight(double val) const
{
    PyThrowBadHr(impObj()->put_Height(val));
}

double PyIAcadTextStyleImpl::GetLastHeight() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_LastHeight(&rtval));
    return rtval;
}

void PyIAcadTextStyleImpl::SetLastHeight(double val) const
{
    PyThrowBadHr(impObj()->put_LastHeight(val));
}

CString PyIAcadTextStyleImpl::GetName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Name(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

double PyIAcadTextStyleImpl::GetObliqueAngle() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_ObliqueAngle(&rtval));
    return rtval;
}

void PyIAcadTextStyleImpl::SetObliqueAngle(double val) const
{
    PyThrowBadHr(impObj()->put_ObliqueAngle(val));
}

long PyIAcadTextStyleImpl::GetTextGenerationFlag() const
{
#if defined (_GRXTARGET260)
    throw PyNotimplementedByHost{};
#else
    long rtval = 0;
    PyThrowBadHr(impObj()->get_TextGenerationFlag(&rtval));
    return rtval;
#endif
}

void PyIAcadTextStyleImpl::SetTextGenerationFlag(long val) const
{
#if defined (_GRXTARGET260)
    throw PyNotimplementedByHost{};
#else
    PyThrowBadHr(impObj()->put_TextGenerationFlag(val));
#endif
}

double PyIAcadTextStyleImpl::GetWidth() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_Width(&rtval));
    return rtval;
}

void PyIAcadTextStyleImpl::SetWidth(double val) const
{
    PyThrowBadHr(impObj()->put_Width(val));
}

boost::python::tuple PyIAcadTextStyleImpl::GetFont() const
{
    PyAutoLockGIL lock;
    _bstr_t bstrTypeFace;
    VARIANT_BOOL rtBold = VARIANT_FALSE;
    VARIANT_BOOL rtItalic = VARIANT_FALSE;
    long rtCharset = 0;
    long rtPitchAndFamily = 0;
    PyThrowBadHr(impObj()->GetFont(&bstrTypeFace.GetBSTR(), &rtBold, &rtItalic, &rtCharset, &rtPitchAndFamily));
    return boost::python::make_tuple(wstr_to_utf8(bstrTypeFace), rtBold != VARIANT_FALSE, rtItalic != VARIANT_FALSE, rtCharset, rtPitchAndFamily);
}

void PyIAcadTextStyleImpl::SetFont(const CString& typeFace, bool bold, bool italic, long charset, long pitchAndFamily) const
{
    _bstr_t bstrTypeFace{ typeFace };
    PyThrowBadHr(impObj()->SetFont(bstrTypeFace, bold ? VARIANT_TRUE : VARIANT_FALSE, italic ? VARIANT_TRUE : VARIANT_FALSE, charset, pitchAndFamily));
}

IAcadTextStyle* PyIAcadTextStyleImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadTextStyle*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadTextStylesImpl
PyIAcadTextStylesImpl::PyIAcadTextStylesImpl(IAcadTextStyles* ptr)
    : PyIAcadObjectImpl(ptr)
{
}

PyIAcadTextStylePtr PyIAcadTextStylesImpl::GetItem(long ind) const
{
    _variant_t vtind{ ind };
    IAcadTextStyle* ptr = nullptr;
    PyThrowBadHr(impObj()->Item(vtind, &ptr));
    return std::make_unique<PyIAcadTextStyleImpl>(ptr);
}

long PyIAcadTextStylesImpl::GetCount() const
{
    long ind = 0;
    PyThrowBadHr(impObj()->get_Count(&ind));
    return ind;

}

PyIAcadTextStylePtr PyIAcadTextStylesImpl::Add(const CString& name) const
{
    _bstr_t bstrVal{ name };
    IAcadTextStyle* ptr = nullptr;
    PyThrowBadHr(impObj()->Add(bstrVal, &ptr));
    return std::make_unique<PyIAcadTextStyleImpl>(ptr);
}

PyIAcadTextStylePtrArray PyIAcadTextStylesImpl::GetIter() const
{
    IUnknownPtr pUnk;
    IEnumVARIANTPtr vtenum;
    PyIAcadTextStylePtrArray vec;
    PyThrowBadHr(impObj()->get__NewEnum((IUnknown**)&pUnk));
    PyThrowBadHr(pUnk->QueryInterface(IID_IEnumVARIANT, (void**)&vtenum));
    {
        HRESULT hr = S_OK;
        for (unsigned long idx = 0, iout = 0; hr == S_OK; idx++)
        {
            _variant_t item;
            if (hr = vtenum->Next(1, &item.GetVARIANT(), &iout); hr == S_OK)
                vec.emplace_back(std::make_shared<PyIAcadTextStyleImpl>((IAcadTextStyle*)(IDispatch*)item));
        }
    }
    return vec;
}

IAcadTextStyles* PyIAcadTextStylesImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadTextStyles*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadUCSImpl
PyIAcadUCSImpl::PyIAcadUCSImpl(IAcadUCS* ptr)
    : PyIAcadObjectImpl(ptr)
{
}

CString PyIAcadUCSImpl::GetName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Name(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadUCSImpl::SetName(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_Name(bstrval));
}

AcGePoint3d PyIAcadUCSImpl::GetOrigin() const
{
    _variant_t vtval;
    AcGePoint3d rtVal;
    PyThrowBadHr(impObj()->get_Origin(&vtval));
    PyThrowBadHr(VariantToAcGePoint3d(vtval, rtVal));
    return rtVal;
}

void PyIAcadUCSImpl::SetOrigin(const AcGePoint3d& val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGePoint3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_Origin(vtval));
}

AcGeVector3d PyIAcadUCSImpl::GetXVector() const
{
    AcGeVector3d val;
    _variant_t coord;
    PyThrowBadHr(impObj()->get_XVector(&coord.GetVARIANT()));
    PyThrowBadHr(VariantToAcGeVector3d(coord, val));
    return val;
}

void PyIAcadUCSImpl::SetXVector(const AcGeVector3d& val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGeVector3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_XVector(vtval));
}

AcGeVector3d PyIAcadUCSImpl::GetYVector() const
{
    AcGeVector3d val;
    _variant_t coord;
    PyThrowBadHr(impObj()->get_YVector(&coord.GetVARIANT()));
    PyThrowBadHr(VariantToAcGeVector3d(coord, val));
    return val;
}

void PyIAcadUCSImpl::SetYVector(const AcGeVector3d& val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGeVector3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_YVector(vtval));
}

AcGeMatrix3d PyIAcadUCSImpl::GetUCSMatrix() const
{
#if defined (_ZRXTARGET250)
    auto orgin = GetOrigin();
    auto vx = GetXVector();
    auto vy = GetYVector();
    AcGeMatrix3d mat;
    mat.setCoordSystem(orgin, vx, vy, vx.crossProduct(vy));
    return mat;
#else
    _variant_t vtxf;
    AcAxMatrix3d axMat;
    PyThrowBadHr(impObj()->GetUCSMatrix(&vtxf.GetVARIANT()));
    return(AcGeMatrix3d)AcAxMatrix3d(vtxf);
#endif
}

IAcadUCS* PyIAcadUCSImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadUCS*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadUCSsImpl
PyIAcadUCSsImpl::PyIAcadUCSsImpl(IAcadUCSs* ptr)
    : PyIAcadObjectImpl(ptr)
{
}

PyIAcadUCSPtr PyIAcadUCSsImpl::GetItem(long ind) const
{
    _variant_t vtind{ ind };
    IAcadUCS* ptr = nullptr;
    PyThrowBadHr(impObj()->Item(vtind, &ptr));
    return std::make_unique<PyIAcadUCSImpl>(ptr);
}

long PyIAcadUCSsImpl::GetCount() const
{
    long ind = 0;
    PyThrowBadHr(impObj()->get_Count(&ind));
    return ind;
}

PyIAcadUCSPtr PyIAcadUCSsImpl::Add(const AcGePoint3d& origin, const AcGeVector3d& xAxis, const AcGeVector3d& yAxis, const CString& name) const
{
    variant_t vtorigin;
    variant_t vtxAxis;
    variant_t vtyAxis;
    _bstr_t bstrVal{ name };
    IAcadUCS* ptr = nullptr;
    PyThrowBadHr(AcGePoint3dToVariant(vtorigin.GetVARIANT(), origin));
    PyThrowBadHr(AcGeVector3dToVariant(vtxAxis.GetVARIANT(), xAxis));
    PyThrowBadHr(AcGeVector3dToVariant(vtyAxis.GetVARIANT(), yAxis));
    PyThrowBadHr(impObj()->Add(vtorigin, vtxAxis, vtyAxis, bstrVal, &ptr));
    return std::make_unique<PyIAcadUCSImpl>(ptr);
}

PyIAcadUCSPtrArray PyIAcadUCSsImpl::GetIter() const
{
    IUnknownPtr pUnk;
    IEnumVARIANTPtr vtenum;
    PyIAcadUCSPtrArray vec;
    PyThrowBadHr(impObj()->get__NewEnum((IUnknown**)&pUnk));
    PyThrowBadHr(pUnk->QueryInterface(IID_IEnumVARIANT, (void**)&vtenum));
    {
        HRESULT hr = S_OK;
        for (unsigned long idx = 0, iout = 0; hr == S_OK; idx++)
        {
            _variant_t item;
            if (hr = vtenum->Next(1, &item.GetVARIANT(), &iout); hr == S_OK)
                vec.emplace_back(std::make_shared<PyIAcadUCSImpl>((IAcadUCS*)(IDispatch*)item));
        }
    }
    return vec;
}

IAcadUCSs* PyIAcadUCSsImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadUCSs*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadViewsImpl
PyIAcadViewsImpl::PyIAcadViewsImpl(IAcadViews* ptr)
    : PyIAcadObjectImpl(ptr)
{
}

PyIAcadViewPtr PyIAcadViewsImpl::GetItem(long ind) const
{
    _variant_t vtind{ ind };
    IAcadView* ptr = nullptr;
    PyThrowBadHr(impObj()->Item(vtind, &ptr));
    return std::make_unique<PyIAcadViewImpl>(ptr);
}

long PyIAcadViewsImpl::GetCount() const
{
    long ind = 0;
    PyThrowBadHr(impObj()->get_Count(&ind));
    return ind;
}

PyIAcadViewPtr PyIAcadViewsImpl::Add(const CString& name) const
{
    _bstr_t bstrVal{ name };
    IAcadView* ptr = nullptr;
    PyThrowBadHr(impObj()->Add(bstrVal, &ptr));
    return std::make_unique<PyIAcadViewImpl>(ptr);
}

PyIAcadViewPtrArray PyIAcadViewsImpl::GetIter() const
{
    IUnknownPtr pUnk;
    IEnumVARIANTPtr vtenum;
    PyIAcadViewPtrArray vec;
    PyThrowBadHr(impObj()->get__NewEnum((IUnknown**)&pUnk));
    PyThrowBadHr(pUnk->QueryInterface(IID_IEnumVARIANT, (void**)&vtenum));
    {
        HRESULT hr = S_OK;
        for (unsigned long idx = 0, iout = 0; hr == S_OK; idx++)
        {
            _variant_t item;
            if (hr = vtenum->Next(1, &item.GetVARIANT(), &iout); hr == S_OK)
                vec.emplace_back(std::make_shared<PyIAcadViewImpl>((IAcadView*)(IDispatch*)item));
        }
    }
    return vec;
}

IAcadViews* PyIAcadViewsImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadViews*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadViewportImpl
PyIAcadViewportImpl::PyIAcadViewportImpl(IAcadViewport* ptr)
    : PyIAcadObjectImpl(ptr)
{
}

AcGePoint3d PyIAcadViewportImpl::GetCenter() const
{
    _variant_t vtval;
    AcGePoint3d rtVal;
    PyThrowBadHr(impObj()->get_Center(&vtval));
    PyThrowBadHr(VariantToAcGePoint3d(vtval, rtVal));
    return rtVal;
}

void PyIAcadViewportImpl::SetCenter(const AcGePoint3d& val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGePoint3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_Center(vtval));
}

double PyIAcadViewportImpl::GetHeight() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_Height(&rtval));
    return rtval;
}

void PyIAcadViewportImpl::SetHeight(double val) const
{
    PyThrowBadHr(impObj()->put_Height(val));
}

double PyIAcadViewportImpl::GetWidth() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_Width(&rtval));
    return rtval;
}

void PyIAcadViewportImpl::SetWidth(double val) const
{
    PyThrowBadHr(impObj()->put_Width(val));
}

AcGePoint3d PyIAcadViewportImpl::GetTarget() const
{
    _variant_t vtval;
    AcGePoint3d rtVal;
    PyThrowBadHr(impObj()->get_Target(&vtval));
    PyThrowBadHr(VariantToAcGePoint3d(vtval, rtVal));
    return rtVal;
}

void PyIAcadViewportImpl::SetTarget(const AcGePoint3d& val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGePoint3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_Target(vtval));
}

AcGeVector3d PyIAcadViewportImpl::GetDirection() const
{
    AcGeVector3d val;
    _variant_t coord;
    PyThrowBadHr(impObj()->get_Direction(&coord.GetVARIANT()));
    PyThrowBadHr(VariantToAcGeVector3d(coord, val));
    return val;
}

void PyIAcadViewportImpl::SetDirection(const AcGeVector3d& val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGeVector3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_Direction(vtval));
}

CString PyIAcadViewportImpl::GetName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Name(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadViewportImpl::SetName(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_Name(bstrval));
}

bool PyIAcadViewportImpl::GetGridOn() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_GridOn(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadViewportImpl::SetGridOn(bool val) const
{
    PyThrowBadHr(impObj()->put_GridOn(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadViewportImpl::GetOrthoOn() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_GridOn(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadViewportImpl::SetOrthoOn(bool val) const
{
    PyThrowBadHr(impObj()->put_GridOn(val ? VARIANT_TRUE : VARIANT_FALSE));
}

AcGePoint3d PyIAcadViewportImpl::GetSnapBasePoint() const
{
    _variant_t vtval;
    AcGePoint3d rtVal;
    PyThrowBadHr(impObj()->get_SnapBasePoint(&vtval));
    PyThrowBadHr(VariantToAcGePoint3d(vtval, rtVal));
    return rtVal;
}

void PyIAcadViewportImpl::SetSnapBasePoint(const AcGePoint3d& val) const
{
    _variant_t vtval;
    PyThrowBadHr(AcGePoint3dToVariant(vtval.GetVARIANT(), val));
    PyThrowBadHr(impObj()->put_SnapBasePoint(vtval));
}

bool PyIAcadViewportImpl::GetSnapOn() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_SnapOn(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadViewportImpl::SetSnapOn(bool val) const
{
    PyThrowBadHr(impObj()->put_SnapOn(val ? VARIANT_TRUE : VARIANT_FALSE));
}

double PyIAcadViewportImpl::GetSnapRotationAngle() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_SnapRotationAngle(&rtval));
    return rtval;
}

void PyIAcadViewportImpl::SetSnapRotationAngle(double val) const
{
    PyThrowBadHr(impObj()->put_SnapRotationAngle(val));
}

bool PyIAcadViewportImpl::GetUCSIconOn() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_UCSIconOn(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadViewportImpl::SetUCSIconOn(bool val) const
{
    PyThrowBadHr(impObj()->put_UCSIconOn(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadViewportImpl::GetUCSIconAtOrigin() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_UCSIconAtOrigin(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PyIAcadViewportImpl::SetUCSIconAtOrigin(bool val) const
{
    PyThrowBadHr(impObj()->put_UCSIconAtOrigin(val ? VARIANT_TRUE : VARIANT_FALSE));
}

AcGePoint2d PyIAcadViewportImpl::GetLowerLeftCorner() const
{
    _variant_t vtval;
    AcGePoint2d rtVal;
    PyThrowBadHr(impObj()->get_LowerLeftCorner(&vtval));
    PyThrowBadHr(VariantToAcGePoint2d(vtval, rtVal));
    return rtVal;
}

AcGePoint2d PyIAcadViewportImpl::GetUpperRightCorner() const
{
    _variant_t vtval;
    AcGePoint2d rtVal;
    PyThrowBadHr(impObj()->get_UpperRightCorner(&vtval));
    PyThrowBadHr(VariantToAcGePoint2d(vtval, rtVal));
    return rtVal;
}

void PyIAcadViewportImpl::Split(PyAcViewportSplitType val) const
{
    PyThrowBadHr(impObj()->Split((AcViewportSplitType)val));
}

void PyIAcadViewportImpl::GetGridSpacing(double& XSpacing, double& YSpacing) const
{
    PyThrowBadHr(impObj()->GetGridSpacing(&XSpacing, &YSpacing));
}

void PyIAcadViewportImpl::SetGridSpacing(double XSpacing, double YSpacing) const
{
    PyThrowBadHr(impObj()->SetGridSpacing(XSpacing, YSpacing));
}

void PyIAcadViewportImpl::GetSnapSpacing(double& XSpacing, double& YSpacing) const
{
    PyThrowBadHr(impObj()->GetSnapSpacing(&XSpacing, &YSpacing));
}

void PyIAcadViewportImpl::SetSnapSpacing(double XSpacing, double YSpacing) const
{
    PyThrowBadHr(impObj()->SetSnapSpacing(XSpacing, YSpacing));
}

void PyIAcadViewportImpl::SetView(const PyIAcadViewImpl& scr) const
{
    PyThrowBadHr(impObj()->SetView(scr.impObj()));
}

long PyIAcadViewportImpl::GetArcSmoothness() const
{
    long rtval = 0;
    PyThrowBadHr(impObj()->get_ArcSmoothness(&rtval));
    return rtval;
}

void PyIAcadViewportImpl::SetArcSmoothness(long val) const
{
    PyThrowBadHr(impObj()->put_ArcSmoothness(val));
}

IAcadViewport* PyIAcadViewportImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadViewport*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadViewportsImpl
PyIAcadViewportsImpl::PyIAcadViewportsImpl(IAcadViewports* ptr)
    : PyIAcadObjectImpl(ptr)
{
}

PyIAcadViewportPtr PyIAcadViewportsImpl::GetItem(long ind) const
{
    _variant_t vtind{ ind };
    IAcadViewport* ptr = nullptr;
    PyThrowBadHr(impObj()->Item(vtind, &ptr));
    return std::make_unique<PyIAcadViewportImpl>(ptr);
}

long PyIAcadViewportsImpl::GetCount() const
{
    long ind = 0;
    PyThrowBadHr(impObj()->get_Count(&ind));
    return ind;
}

PyIAcadViewportPtr PyIAcadViewportsImpl::Add(const CString& name) const
{
    _bstr_t bstrVal{ name };
    IAcadViewport* ptr = nullptr;
    PyThrowBadHr(impObj()->Add(bstrVal, &ptr));
    return std::make_unique<PyIAcadViewportImpl>(ptr);
}

PyIAcadViewportPtrArray PyIAcadViewportsImpl::GetIter() const
{
    IUnknownPtr pUnk;
    IEnumVARIANTPtr vtenum;
    PyIAcadViewportPtrArray vec;
    PyThrowBadHr(impObj()->get__NewEnum((IUnknown**)&pUnk));
    PyThrowBadHr(pUnk->QueryInterface(IID_IEnumVARIANT, (void**)&vtenum));
    {
        HRESULT hr = S_OK;
        for (unsigned long idx = 0, iout = 0; hr == S_OK; idx++)
        {
            _variant_t item;
            if (hr = vtenum->Next(1, &item.GetVARIANT(), &iout); hr == S_OK)
                vec.emplace_back(std::make_shared<PyIAcadViewportImpl>((IAcadViewport*)(IDispatch*)item));
        }
    }
    return vec;
}

IAcadViewports* PyIAcadViewportsImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadViewports*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadPlotConfigurationsImpl
PyIAcadPlotConfigurationsImpl::PyIAcadPlotConfigurationsImpl(IAcadPlotConfigurations* ptr)
    : PyIAcadObjectImpl(ptr)
{
}

PyIAcadPlotConfigurationPtr PyIAcadPlotConfigurationsImpl::GetItem(long ind) const
{
    _variant_t vtind{ ind };
    IAcadPlotConfiguration* ptr = nullptr;
    PyThrowBadHr(impObj()->Item(vtind, &ptr));
    return std::make_unique<PyIAcadPlotConfigurationImpl>(ptr);
}

long PyIAcadPlotConfigurationsImpl::GetCount() const
{
    long ind = 0;
    PyThrowBadHr(impObj()->get_Count(&ind));
    return ind;
}

PyIAcadPlotConfigurationPtr PyIAcadPlotConfigurationsImpl::Add(const CString& name) const
{
    _bstr_t bstrVal{ name };
    IAcadPlotConfiguration* ptr = nullptr;
    PyThrowBadHr(impObj()->Add(bstrVal, vtMissing, &ptr));
    return std::make_unique<PyIAcadPlotConfigurationImpl>(ptr);
}

PyIAcadPlotConfigurationPtrArray PyIAcadPlotConfigurationsImpl::GetIter() const
{
    IUnknownPtr pUnk;
    IEnumVARIANTPtr vtenum;
    PyIAcadPlotConfigurationPtrArray vec;
    PyThrowBadHr(impObj()->get__NewEnum((IUnknown**)&pUnk));
    PyThrowBadHr(pUnk->QueryInterface(IID_IEnumVARIANT, (void**)&vtenum));
    {
        HRESULT hr = S_OK;
        for (unsigned long idx = 0, iout = 0; hr == S_OK; idx++)
        {
            _variant_t item;
            if (hr = vtenum->Next(1, &item.GetVARIANT(), &iout); hr == S_OK)
                vec.emplace_back(std::make_shared<PyIAcadPlotConfigurationImpl>((IAcadPlotConfiguration*)(IDispatch*)item));
        }
    }
    return vec;
}

IAcadPlotConfigurations* PyIAcadPlotConfigurationsImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadPlotConfigurations*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadSectionManagerImpl
PyIAcadSectionManagerImpl::PyIAcadSectionManagerImpl(IAcadSectionManager* ptr)
    : PyIAcadObjectImpl(ptr)
{
}

PyIAcadSectionPtr PyIAcadSectionManagerImpl::GetItem(long ind) const
{
    _variant_t vtind{ ind };
    IAcadSection* ptr = nullptr;
    PyThrowBadHr(impObj()->Item(vtind, &ptr));
    return std::make_unique<PyIAcadSectionImpl>(ptr);
}

long PyIAcadSectionManagerImpl::GetCount() const
{
    long ind = 0;
    PyThrowBadHr(impObj()->get_Count(&ind));
    return ind;
}

PyIAcadSectionPtr PyIAcadSectionManagerImpl::GetLiveSection() const
{
    IAcadSection* ptr = nullptr;
    PyThrowBadHr(impObj()->GetLiveSection(&ptr));
    return std::make_unique<PyIAcadSectionImpl>(ptr);
}

CString PyIAcadSectionManagerImpl::GetUniqueSectionName(const CString& val) const
{
    _bstr_t bstrrtVal;
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->GetUniqueSectionName(bstrval, &bstrrtVal.GetBSTR()));
    return (LPCTSTR)bstrrtVal;
}

IAcadSectionManager* PyIAcadSectionManagerImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadSectionManager*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadMaterialImpl
PyIAcadMaterialImpl::PyIAcadMaterialImpl(IAcadMaterial* ptr)
    : PyIAcadObjectImpl(ptr)
{
}

CString PyIAcadMaterialImpl::GetDescription() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Description(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadMaterialImpl::SetDescription(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_Description(bstrval));
}

CString PyIAcadMaterialImpl::GetName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Name(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadMaterialImpl::SetName(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_Name(bstrval));
}

IAcadMaterial* PyIAcadMaterialImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadMaterial*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadMaterialsImpl
PyIAcadMaterialsImpl::PyIAcadMaterialsImpl(IAcadMaterials* ptr)
    : PyIAcadObjectImpl(ptr)
{
}

PyIAcadMaterialPtr PyIAcadMaterialsImpl::GetItem(long ind) const
{
    _variant_t vtind{ ind };
    IAcadMaterial* ptr = nullptr;
    PyThrowBadHr(impObj()->Item(vtind, &ptr));
    return std::make_unique<PyIAcadMaterialImpl>(ptr);
}

long PyIAcadMaterialsImpl::GetCount() const
{
    long ind = 0;
    PyThrowBadHr(impObj()->get_Count(&ind));
    return ind;
}

PyIAcadMaterialPtr PyIAcadMaterialsImpl::Add(const CString& name) const
{
    _bstr_t bstrVal{ name };
    IAcadMaterial* ptr = nullptr;
    PyThrowBadHr(impObj()->Add(bstrVal, &ptr));
    return std::make_unique<PyIAcadMaterialImpl>(ptr);
}

PyIAcadMaterialPtrArray PyIAcadMaterialsImpl::GetIter() const
{
    IUnknownPtr pUnk;
    IEnumVARIANTPtr vtenum;
    PyIAcadMaterialPtrArray vec;
    PyThrowBadHr(impObj()->get__NewEnum((IUnknown**)&pUnk));
    PyThrowBadHr(pUnk->QueryInterface(IID_IEnumVARIANT, (void**)&vtenum));
    {
        HRESULT hr = S_OK;
        for (unsigned long idx = 0, iout = 0; hr == S_OK; idx++)
        {
            _variant_t item;
            if (hr = vtenum->Next(1, &item.GetVARIANT(), &iout); hr == S_OK)
                vec.emplace_back(std::make_shared<PyIAcadMaterialImpl>((IAcadMaterial*)(IDispatch*)item));
        }
    }
    return vec;
}

IAcadMaterials* PyIAcadMaterialsImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadMaterials*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadTableStyleImpl
PyIAcadTableStyleImpl::PyIAcadTableStyleImpl(IAcadTableStyle* ptr)
    : PyIAcadObjectImpl(ptr)
{
}

CString PyIAcadTableStyleImpl::GetName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Name(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadTableStyleImpl::SetName(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_Name(bstrval));
}

CString PyIAcadTableStyleImpl::GetDescription() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Description(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadTableStyleImpl::SetDescription(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_Description(bstrval));
}

long PyIAcadTableStyleImpl::GetBitFlags() const
{
    long rtval = 0;
    PyThrowBadHr(impObj()->get_BitFlags(&rtval));
    return rtval;
}

void PyIAcadTableStyleImpl::SetBitFlags(long val) const
{
    PyThrowBadHr(impObj()->put_BitFlags(val));
}

PyAcTableDirection PyIAcadTableStyleImpl::GetFlowDirection() const
{
    AcTableDirection rtval = (AcTableDirection)PyAcTableDirection::pyacTableTopToBottom;
    PyThrowBadHr(impObj()->get_FlowDirection(&rtval));
    return (PyAcTableDirection)rtval;
}

void PyIAcadTableStyleImpl::SetFlowDirections(PyAcTableDirection val) const
{
    PyThrowBadHr(impObj()->put_FlowDirection((AcTableDirection)val));
}

double PyIAcadTableStyleImpl::GetHorzCellMargin() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_HorzCellMargin(&rtval));
    return rtval;
}

void PyIAcadTableStyleImpl::SetHorzCellMargin(double val) const
{
    PyThrowBadHr(impObj()->put_HorzCellMargin(val));
}

double PyIAcadTableStyleImpl::GetVertCellMargin() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_VertCellMargin(&rtval));
    return rtval;
}

void PyIAcadTableStyleImpl::SetVertCellMargin(double val) const
{
    PyThrowBadHr(impObj()->put_VertCellMargin(val));
}

bool PyIAcadTableStyleImpl::GetTitleSuppressed() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_TitleSuppressed(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadTableStyleImpl::SetTitleSuppressed(bool val) const
{
    PyThrowBadHr(impObj()->put_TitleSuppressed(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PyIAcadTableStyleImpl::GetHeaderSuppressed() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_HeaderSuppressed(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadTableStyleImpl::SetHeaderSuppressed(bool val) const
{
    PyThrowBadHr(impObj()->put_HeaderSuppressed(val ? VARIANT_TRUE : VARIANT_FALSE));
}

void PyIAcadTableStyleImpl::CreateCellStyle(const CString& cellStyle) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    _bstr_t bstrcellStyle{ cellStyle };
    PyThrowBadHr(impObj()->CreateCellStyle(bstrcellStyle));
#endif
}

void PyIAcadTableStyleImpl::CreateCellStyleFromStyle(const CString& cellStyle, const CString& sourceCellStyle) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    _bstr_t bstrcellStyle{ cellStyle };
    _bstr_t bstrsourceCellStyle{ sourceCellStyle };
    PyThrowBadHr(impObj()->CreateCellStyleFromStyle(bstrcellStyle, bstrsourceCellStyle));
#endif
}

void PyIAcadTableStyleImpl::RenameCellStyle(const CString& oldName, const CString& newName) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    _bstr_t bstroldName{ oldName };
    _bstr_t bstrnewName{ newName };
    PyThrowBadHr(impObj()->RenameCellStyle(bstroldName, bstrnewName));
#endif
}

void PyIAcadTableStyleImpl::DeleteCellStyle(const CString& cellStyle) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    _bstr_t bstrcellStyle{ cellStyle };
    PyThrowBadHr(impObj()->DeleteCellStyle(bstrcellStyle));
#endif
}

CString PyIAcadTableStyleImpl::GetUniqueCellStyleName(const CString& basename) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    _bstr_t bstrVal;
    _bstr_t bstrbasename{ basename };
    PyThrowBadHr(impObj()->GetUniqueCellStyleName(bstrbasename, &bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
#endif
}

bool PyIAcadTableStyleImpl::GetIsCellStyleInUse(const CString& cellStyle) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    _bstr_t bstrcellStyle{ cellStyle };
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->GetIsCellStyleInUse(bstrcellStyle, &rtval));
    return rtval != VARIANT_FALSE;
#endif
}

long PyIAcadTableStyleImpl::GetNumCellStyles() const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    long rtval = 0;
    PyThrowBadHr(impObj()->get_NumCellStyles(&rtval));
    return rtval;
#endif
}

wstringArray PyIAcadTableStyleImpl::GetCellStyles() const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    wstringArray styles;
    _variant_t vtstyles;
    PyThrowBadHr(impObj()->GetCellStyles(&vtstyles.GetVARIANT()));
    PyThrowBadHr(VariantTowstringArray(vtstyles, styles));
    return styles;
#endif
}

AcDbObjectId PyIAcadTableStyleImpl::GetTextStyleId(const CString& cellStyle) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    AcDbObjectId id;
    LONG_PTR rtval = 0;
    _bstr_t bstrcellStyle{ cellStyle };
    PyThrowBadHr(impObj()->GetTextStyleId(bstrcellStyle, &rtval));
    return id.setFromOldId(rtval);
#endif
}

void PyIAcadTableStyleImpl::SetTextStyleId(const CString& cellStyle, const AcDbObjectId& oid) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    _bstr_t bstrcellStyle{ cellStyle };
    PyThrowBadHr(impObj()->SetTextStyleId(bstrcellStyle, oid.asOldId()));
#endif
}

double PyIAcadTableStyleImpl::GetTextHeight2(const CString& cellStyle) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    double rtval = 0;
    _bstr_t bstrcellStyle{ cellStyle };
    PyThrowBadHr(impObj()->GetTextHeight2(bstrcellStyle, &rtval));
    return rtval;
#endif
}

void PyIAcadTableStyleImpl::SetTextHeight2(const CString& cellStyle, double height) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    _bstr_t bstrcellStyle{ cellStyle };
    PyThrowBadHr(impObj()->SetTextHeight2(bstrcellStyle, height));
#endif
}

PyAcCellAlignment PyIAcadTableStyleImpl::GetAlignment2(const CString& cellStyle) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    AcCellAlignment rtval = (AcCellAlignment)PyAcCellAlignment::pyacTopLeft;
    _bstr_t bstrcellStyle{ cellStyle };
    PyThrowBadHr(impObj()->GetAlignment2(bstrcellStyle, &rtval));
    return (PyAcCellAlignment)rtval;
#endif
}

void PyIAcadTableStyleImpl::SetAlignment2(const CString& cellStyle, PyAcCellAlignment val) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    _bstr_t bstrcellStyle{ cellStyle };
    PyThrowBadHr(impObj()->SetAlignment2(bstrcellStyle, (AcCellAlignment)val));
#endif
}

PyIAcadAcCmColorPtr PyIAcadTableStyleImpl::GetColor2(const CString& cellStyle) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    IAcadAcCmColor* rtval = nullptr;
    _bstr_t bstrcellStyle{ cellStyle };
    PyThrowBadHr(impObj()->GetColor2(bstrcellStyle, &rtval));
    return std::make_unique<PyIAcadAcCmColorImpl>(rtval);
#endif
}

void PyIAcadTableStyleImpl::SetColor2(const CString& cellStyle, const PyIAcadAcCmColorImpl& val) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    _bstr_t bstrcellStyle{ cellStyle };
    PyThrowBadHr(impObj()->SetColor2(bstrcellStyle, val.impObj()));
#endif
}

PyIAcadAcCmColorPtr PyIAcadTableStyleImpl::GetBackgroundColor2(const CString& cellStyle) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    IAcadAcCmColor* rtval = nullptr;
    _bstr_t bstrcellStyle{ cellStyle };
    PyThrowBadHr(impObj()->GetBackgroundColor2(bstrcellStyle, &rtval));
    return std::make_unique<PyIAcadAcCmColorImpl>(rtval);
#endif
}

void PyIAcadTableStyleImpl::SetBackgroundColor2(const CString& cellStyle, const PyIAcadAcCmColorImpl& val) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    _bstr_t bstrcellStyle{ cellStyle };
    PyThrowBadHr(impObj()->SetBackgroundColor2(bstrcellStyle, val.impObj()));
#endif
}

boost::python::tuple PyIAcadTableStyleImpl::GetDataType2(const CString& cellStyle) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    PyAutoLockGIL lock;
    AcValueDataType pDataType = (AcValueDataType)PyAcValueDataType::pyacUnknownDataType;
    AcValueUnitType pUnitType = (AcValueUnitType)PyAcValueUnitType::pyacUnitless;
    _bstr_t bstrcellStyle{ cellStyle };
    PyThrowBadHr(impObj()->GetDataType2(bstrcellStyle, &pDataType, &pUnitType));
    return boost::python::make_tuple(PyAcValueDataType(pDataType), PyAcValueUnitType(pUnitType));
#endif
}

void PyIAcadTableStyleImpl::SetDataType2(const CString& cellStyle, PyAcValueDataType nDataType, PyAcValueUnitType nUnitType) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    _bstr_t bstrcellStyle{ cellStyle };
    PyThrowBadHr(impObj()->SetDataType2(bstrcellStyle, (AcValueDataType)nDataType, (AcValueUnitType)nUnitType));
#endif
}

CString PyIAcadTableStyleImpl::GetFormat2(const CString& cellStyle) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    _bstr_t bstrVal;
    _bstr_t bstrcellStyle{ cellStyle };
    PyThrowBadHr(impObj()->GetFormat2(bstrcellStyle, &bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
#endif
}

void PyIAcadTableStyleImpl::SetFormat2(const CString& cellStyle, const CString& val) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    _bstr_t bstrval{ val };
    _bstr_t bstrcellStyle{ cellStyle };
    PyThrowBadHr(impObj()->SetFormat2(bstrcellStyle, bstrval));
#endif
}

int PyIAcadTableStyleImpl::GetCellClass(const CString& cellStyle) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    int rtval = 0;
    _bstr_t bstrcellStyle{ cellStyle };
    PyThrowBadHr(impObj()->GetCellClass(bstrcellStyle, &rtval));
    return rtval;
#endif
}

void PyIAcadTableStyleImpl::SetCellClass(const CString& cellStyle, int val) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    _bstr_t bstrcellStyle{ cellStyle };
    PyThrowBadHr(impObj()->SetCellClass(bstrcellStyle, val));
#endif
}

double PyIAcadTableStyleImpl::GetRotation(const CString& cellStyle) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    double rtval = 0;
    _bstr_t bstrcellStyle{ cellStyle };
    PyThrowBadHr(impObj()->GetRotation(bstrcellStyle, &rtval));
    return rtval;
#endif
}

void PyIAcadTableStyleImpl::SetRotation(const CString& cellStyle, double val) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    _bstr_t bstrcellStyle{ cellStyle };
    PyThrowBadHr(impObj()->SetRotation(bstrcellStyle, val));
#endif
}

bool PyIAcadTableStyleImpl::GetIsMergeAllEnabled(const CString& cellStyle) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    VARIANT_BOOL rtval = VARIANT_FALSE;
    _bstr_t bstrcellStyle{ cellStyle };
    PyThrowBadHr(impObj()->GetIsMergeAllEnabled(bstrcellStyle, &rtval));
    return rtval != VARIANT_FALSE;
#endif
}

void PyIAcadTableStyleImpl::EnableMergeAll(const CString& cellStyle, bool val) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    _bstr_t bstrcellStyle{ cellStyle };
    PyThrowBadHr(impObj()->EnableMergeAll(bstrcellStyle, val ? VARIANT_TRUE : VARIANT_FALSE));
#endif
}

PyAcLineWeight PyIAcadTableStyleImpl::GetGridLineWeight2(const CString& cellStyle, PyAcGridLineType gridLineType) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    AcLineWeight rtval = (AcLineWeight)PyAcLineWeight::pyacLnWt000;
    _bstr_t bstrcellStyle{ cellStyle };
    PyThrowBadHr(impObj()->GetGridLineWeight2(bstrcellStyle, (AcGridLineType)gridLineType, &rtval));
    return (PyAcLineWeight)rtval;
#endif
}

void PyIAcadTableStyleImpl::SetGridLineWeight2(const CString& cellStyle, PyAcGridLineType gridLineType, PyAcLineWeight val) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    _bstr_t bstrcellStyle{ cellStyle };
    PyThrowBadHr(impObj()->SetGridLineWeight2(bstrcellStyle, (AcGridLineType)gridLineType, (AcLineWeight)val));
#endif
}

PyIAcadAcCmColorPtr PyIAcadTableStyleImpl::GetGridColor2(const CString& cellStyle, PyAcGridLineType gridLineType) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    IAcadAcCmColor* pColor = nullptr;
    _bstr_t bstrcellStyle{ cellStyle };
    PyThrowBadHr(impObj()->GetGridColor2(bstrcellStyle, (AcGridLineType)gridLineType, &pColor));
    return std::make_unique<PyIAcadAcCmColorImpl>(pColor);
#endif
}

void PyIAcadTableStyleImpl::SetGridColor2(const CString& cellStyle, PyAcGridLineType gridLineType, const PyIAcadAcCmColorImpl& val) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    _bstr_t bstrcellStyle{ cellStyle };
    PyThrowBadHr(impObj()->SetGridColor2(bstrcellStyle, (AcGridLineType)gridLineType, val.impObj()));
#endif
}

bool PyIAcadTableStyleImpl::GetGridVisibility2(const CString& cellStyle, PyAcGridLineType gridLineType) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    VARIANT_BOOL rtval = VARIANT_FALSE;
    _bstr_t bstrcellStyle{ cellStyle };
    PyThrowBadHr(impObj()->GetGridVisibility2(bstrcellStyle, (AcGridLineType)gridLineType, &rtval));
    return rtval != VARIANT_FALSE;
#endif
}

void PyIAcadTableStyleImpl::SetGridVisibility2(const CString& cellStyle, PyAcGridLineType gridLineType, bool val) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    _bstr_t bstrcellStyle{ cellStyle };
    PyThrowBadHr(impObj()->SetGridVisibility2(bstrcellStyle, (AcGridLineType)gridLineType, val ? VARIANT_TRUE : VARIANT_FALSE));
#endif
}

AcDbObjectId PyIAcadTableStyleImpl::GetTemplateId() const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    AcDbObjectId id;
    LONG_PTR rtval = 0;
    PyThrowBadHr(impObj()->get_TemplateId(&rtval));
    return id.setFromOldId(rtval);
#endif
}

void PyIAcadTableStyleImpl::SetTemplateId(const AcDbObjectId& val) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    PyThrowBadHr(impObj()->put_TemplateId(val.asOldId()));
#endif
}

void PyIAcadTableStyleImpl::SetTemplateId(const AcDbObjectId& val, PyAcMergeCellStyleOption option) const
{
#ifdef _GRXTARGET260
    throw PyNotimplementedByHost{};
#else
    PyThrowBadHr(impObj()->SetTemplateId(val.asOldId(), (AcMergeCellStyleOption)option));
#endif
}

IAcadTableStyle* PyIAcadTableStyleImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadTableStyle*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadMLeaderStyleImpl
PyIAcadMLeaderStyleImpl::PyIAcadMLeaderStyleImpl(IAcadMLeaderStyle* ptr)
    : PyIAcadObjectImpl(ptr)
{
}

CString PyIAcadMLeaderStyleImpl::GetName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Name(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadMLeaderStyleImpl::SetName(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_Name(bstrval));
}

CString PyIAcadMLeaderStyleImpl::GetDescription() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Description(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadMLeaderStyleImpl::SetDescription(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_Description(bstrval));
}

long PyIAcadMLeaderStyleImpl::GetBitFlags() const
{
    long rtval = 0;
    PyThrowBadHr(impObj()->get_BitFlags(&rtval));
    return rtval;
}

void PyIAcadMLeaderStyleImpl::SetBitFlags(long val) const
{
    PyThrowBadHr(impObj()->put_BitFlags(val));
}

PyAcMLeaderContentType PyIAcadMLeaderStyleImpl::GetContentType() const
{
    AcMLeaderContentType rtval = (AcMLeaderContentType)PyAcMLeaderContentType::pyacNoneContent;
    PyThrowBadHr(impObj()->get_ContentType(&rtval));
    return (PyAcMLeaderContentType)rtval;
}

void PyIAcadMLeaderStyleImpl::SetContentType(PyAcMLeaderContentType val) const
{
    PyThrowBadHr(impObj()->put_ContentType((AcMLeaderContentType)val));
}

PyAcDrawMLeaderOrderType PyIAcadMLeaderStyleImpl::GetDrawMLeaderOrderType() const
{
    AcDrawMLeaderOrderType rtval = (AcDrawMLeaderOrderType)PyAcDrawMLeaderOrderType::pyacDrawContentFirst;
    PyThrowBadHr(impObj()->get_DrawMLeaderOrderType(&rtval));
    return (PyAcDrawMLeaderOrderType)rtval;
}

void PyIAcadMLeaderStyleImpl::SetDrawMLeaderOrderType(PyAcMLeaderContentType val) const
{
    PyThrowBadHr(impObj()->put_DrawMLeaderOrderType((AcDrawMLeaderOrderType)val));
}

PyAcDrawLeaderOrderType PyIAcadMLeaderStyleImpl::GetDrawLeaderOrderType() const
{
    AcDrawLeaderOrderType rtval = (AcDrawLeaderOrderType)PyAcDrawLeaderOrderType::pyacDrawLeaderHeadFirst;
    PyThrowBadHr(impObj()->get_DrawLeaderOrderType(&rtval));
    return (PyAcDrawLeaderOrderType)rtval;
}

void PyIAcadMLeaderStyleImpl::SetDrawLeaderOrderType(PyAcDrawLeaderOrderType val) const
{
    PyThrowBadHr(impObj()->put_DrawLeaderOrderType((AcDrawLeaderOrderType)val));
}

int PyIAcadMLeaderStyleImpl::GetMaxLeaderSegmentsPoints() const
{
    int rtval = 0;
    PyThrowBadHr(impObj()->get_MaxLeaderSegmentsPoints(&rtval));
    return rtval;
}

void PyIAcadMLeaderStyleImpl::SetMaxLeaderSegmentsPoints(int val) const
{
    PyThrowBadHr(impObj()->put_MaxLeaderSegmentsPoints(val));
}

PyAcSegmentAngleType PyIAcadMLeaderStyleImpl::GetFirstSegmentAngleConstraint() const
{
    AcSegmentAngleType rtval = (AcSegmentAngleType)PyAcSegmentAngleType::pyacDegreesAny;
    PyThrowBadHr(impObj()->get_FirstSegmentAngleConstraint(&rtval));
    return (PyAcSegmentAngleType)rtval;
}

void PyIAcadMLeaderStyleImpl::SetFirstSegmentAngleConstraint(PyAcSegmentAngleType val) const
{
    PyThrowBadHr(impObj()->put_FirstSegmentAngleConstraint((AcSegmentAngleType)val));
}

PyAcSegmentAngleType PyIAcadMLeaderStyleImpl::GetSecondSegmentAngleConstraint() const
{
    AcSegmentAngleType rtval = (AcSegmentAngleType)PyAcSegmentAngleType::pyacDegreesAny;
    PyThrowBadHr(impObj()->get_SecondSegmentAngleConstraint(&rtval));
    return (PyAcSegmentAngleType)rtval;
}

void PyIAcadMLeaderStyleImpl::SetSecondSegmentAngleConstraint(PyAcSegmentAngleType val) const
{
    PyThrowBadHr(impObj()->put_SecondSegmentAngleConstraint((AcSegmentAngleType)val));
}

PyAcMLeaderType PyIAcadMLeaderStyleImpl::GetLeaderLineType() const
{
#ifdef _BRXTARGET260
    throw PyNotimplementedByHost{};
#else
    AcMLeaderType rtval = (AcMLeaderType)PyAcMLeaderType::pyacInVisibleLeader;
    PyThrowBadHr(impObj()->get_LeaderLinetype(&rtval));
    return (PyAcMLeaderType)rtval;
#endif
}

void PyIAcadMLeaderStyleImpl::SetLeaderLineType(PyAcMLeaderType val) const
{
#ifdef _BRXTARGET260
    throw PyNotimplementedByHost{};
#else
    PyThrowBadHr(impObj()->put_LeaderLinetype((AcMLeaderType)val));
#endif
}

PyIAcadAcCmColorPtr PyIAcadMLeaderStyleImpl::GetLeaderLineColor() const
{
    IAcadAcCmColor* rtval = nullptr;
    PyThrowBadHr(impObj()->get_LeaderLineColor(&rtval));
    return std::make_unique<PyIAcadAcCmColorImpl>(rtval);
}

void PyIAcadMLeaderStyleImpl::SetLeaderLineColor(const PyIAcadAcCmColorImpl& val) const
{
    PyThrowBadHr(impObj()->put_LeaderLineColor(val.impObj()));
}

CString PyIAcadMLeaderStyleImpl::GetLeaderLineTypeId() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_LeaderLineTypeId(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadMLeaderStyleImpl::SetLeaderLineTypeId(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_LeaderLineTypeId(bstrval));
}

PyAcLineWeight PyIAcadMLeaderStyleImpl::GetLeaderLineWeight() const
{
    AcLineWeight rtval = (AcLineWeight)PyAcLineWeight::pyacLnWt000;
    PyThrowBadHr(impObj()->get_LeaderLineWeight(&rtval));
    return (PyAcLineWeight)rtval;
}

void PyIAcadMLeaderStyleImpl::SetLeaderLineWeight(PyAcLineWeight val) const
{
    PyThrowBadHr(impObj()->put_LeaderLineWeight((AcLineWeight)val));
}

bool PyIAcadMLeaderStyleImpl::GetEnableLanding() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_EnableLanding(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadMLeaderStyleImpl::SetEnableLanding(bool val) const
{
    PyThrowBadHr(impObj()->put_EnableLanding(val ? VARIANT_TRUE : VARIANT_FALSE));
}

double PyIAcadMLeaderStyleImpl::GetLandingGap() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_LandingGap(&rtval));
    return rtval;
}

void PyIAcadMLeaderStyleImpl::SetLandingGap(double val) const
{
    PyThrowBadHr(impObj()->put_LandingGap(val));
}

bool PyIAcadMLeaderStyleImpl::GetEnableDogleg() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_EnableDogleg(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadMLeaderStyleImpl::SetEnableDogleg(bool val) const
{
    PyThrowBadHr(impObj()->put_EnableDogleg(val ? VARIANT_TRUE : VARIANT_FALSE));
}

double PyIAcadMLeaderStyleImpl::GetDoglegLength() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_DoglegLength(&rtval));
    return rtval;
}

void PyIAcadMLeaderStyleImpl::SetDoglegLength(double val) const
{
    PyThrowBadHr(impObj()->put_DoglegLength(val));
}

CString PyIAcadMLeaderStyleImpl::GetArrowSymbol() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_ArrowSymbol(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadMLeaderStyleImpl::SetArrowSymbol(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_ArrowSymbol(bstrval));
}

double PyIAcadMLeaderStyleImpl::GetArrowSize() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_ArrowSize(&rtval));
    return rtval;
}

void PyIAcadMLeaderStyleImpl::SetArrowSize(double val) const
{
    PyThrowBadHr(impObj()->put_ArrowSize(val));
}

CString PyIAcadMLeaderStyleImpl::GetTextStyle() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_TextStyle(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadMLeaderStyleImpl::SetTextStyle(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_TextStyle(bstrval));
}

PyAcTextAttachmentDirection PyIAcadMLeaderStyleImpl::GetTextAttachmentDirection() const
{
#ifdef _BRXTARGET260
    throw PyNotimplementedByHost{};
#else
    AcTextAttachmentDirection rtval = (AcTextAttachmentDirection)PyAcTextAttachmentDirection::pyacAttachmentHorizontal;
    PyThrowBadHr(impObj()->get_TextAttachmentDirection(&rtval));
    return (PyAcTextAttachmentDirection)rtval;
#endif
}

void PyIAcadMLeaderStyleImpl::SetTextAttachmentDirection(PyAcTextAttachmentDirection val) const
{
#ifdef _BRXTARGET260
    throw PyNotimplementedByHost{};
#else
    PyThrowBadHr(impObj()->put_TextAttachmentDirection((AcTextAttachmentDirection)val));
#endif
}

PyAcTextAttachmentType PyIAcadMLeaderStyleImpl::GetTextLeftAttachmentType() const
{
    AcTextAttachmentType rtval = (AcTextAttachmentType)PyAcTextAttachmentType::pyacAttachmentTopOfTop;
    PyThrowBadHr(impObj()->get_TextLeftAttachmentType(&rtval));
    return (PyAcTextAttachmentType)rtval;
}

void PyIAcadMLeaderStyleImpl::SetTextLeftAttachmentType(PyAcTextAttachmentType val) const
{
    PyThrowBadHr(impObj()->put_TextLeftAttachmentType((AcTextAttachmentType)val));
}

PyAcTextAttachmentType PyIAcadMLeaderStyleImpl::GetTextRightAttachmentType() const
{
    AcTextAttachmentType rtval = (AcTextAttachmentType)PyAcTextAttachmentType::pyacAttachmentTopOfTop;
    PyThrowBadHr(impObj()->get_TextRightAttachmentType(&rtval));
    return (PyAcTextAttachmentType)rtval;
}

void PyIAcadMLeaderStyleImpl::SetTextRightAttachmentType(PyAcTextAttachmentType val) const
{
    PyThrowBadHr(impObj()->put_TextRightAttachmentType((AcTextAttachmentType)val));
}

PyAcVerticalTextAttachmentType PyIAcadMLeaderStyleImpl::GetTextTopAttachmentType() const
{
#ifdef _BRXTARGET260
    throw PyNotimplementedByHost{};
#else
    AcVerticalTextAttachmentType rtval = (AcVerticalTextAttachmentType)PyAcVerticalTextAttachmentType::pyacAttachmentCenter;
    PyThrowBadHr(impObj()->get_TextTopAttachmentType(&rtval));
    return (PyAcVerticalTextAttachmentType)rtval;
#endif
}

void PyIAcadMLeaderStyleImpl::SetTextTopAttachmentType(PyAcVerticalTextAttachmentType val) const
{
#ifdef _BRXTARGET260
    throw PyNotimplementedByHost{};
#else
    PyThrowBadHr(impObj()->put_TextTopAttachmentType((AcVerticalTextAttachmentType)val));
#endif
}

PyAcVerticalTextAttachmentType PyIAcadMLeaderStyleImpl::GetTextBottomAttachmentType() const
{
#ifdef _BRXTARGET260
    throw PyNotimplementedByHost{};
#else
    AcVerticalTextAttachmentType rtval = (AcVerticalTextAttachmentType)PyAcVerticalTextAttachmentType::pyacAttachmentCenter;
    PyThrowBadHr(impObj()->get_TextBottomAttachmentType(&rtval));
    return (PyAcVerticalTextAttachmentType)rtval;
#endif
}

PyIAcadAcCmColorPtr PyIAcadMLeaderStyleImpl::GetTextColor() const
{
    IAcadAcCmColor* rtval = nullptr;
    PyThrowBadHr(impObj()->get_TextColor(&rtval));
    return std::make_unique<PyIAcadAcCmColorImpl>(rtval);
}

void PyIAcadMLeaderStyleImpl::SetTextColor(const PyIAcadAcCmColorImpl& val) const
{
    PyThrowBadHr(impObj()->put_TextColor(val.impObj()));
}

double PyIAcadMLeaderStyleImpl::GetTextHeight() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_TextHeight(&rtval));
    return rtval;
}

void PyIAcadMLeaderStyleImpl::SetTextHeight(double val) const
{
    PyThrowBadHr(impObj()->put_TextHeight(val));
}

bool PyIAcadMLeaderStyleImpl::GetEnableFrameText() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_EnableFrameText(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadMLeaderStyleImpl::SetEnableFrameText(bool val) const
{
    PyThrowBadHr(impObj()->put_EnableFrameText(val ? VARIANT_TRUE : VARIANT_FALSE));
}

double PyIAcadMLeaderStyleImpl::GetAlignSpace() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_AlignSpace(&rtval));
    return rtval;
}

void PyIAcadMLeaderStyleImpl::SetAlignSpace(double val) const
{
    PyThrowBadHr(impObj()->put_AlignSpace(val));
}

CString PyIAcadMLeaderStyleImpl::GetBlock() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Block(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadMLeaderStyleImpl::SetBlock(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_Block(bstrval));
}

PyIAcadAcCmColorPtr PyIAcadMLeaderStyleImpl::GetBlockColor() const
{
    IAcadAcCmColor* rtval = nullptr;
    PyThrowBadHr(impObj()->get_BlockColor(&rtval));
    return std::make_unique<PyIAcadAcCmColorImpl>(rtval);
}

void PyIAcadMLeaderStyleImpl::SetBlockColor(const PyIAcadAcCmColorImpl& val) const
{
    PyThrowBadHr(impObj()->put_BlockColor(val.impObj()));
}

bool PyIAcadMLeaderStyleImpl::GetEnableBlockScale() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_EnableBlockScale(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadMLeaderStyleImpl::SetEnableBlockScale(bool val) const
{
    PyThrowBadHr(impObj()->put_EnableBlockScale(val ? VARIANT_TRUE : VARIANT_FALSE));
}

double PyIAcadMLeaderStyleImpl::GetBlockScale() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_BlockScale(&rtval));
    return rtval;
}

void PyIAcadMLeaderStyleImpl::SetBlockScale(double val) const
{
    PyThrowBadHr(impObj()->put_BlockScale(val));
}

bool PyIAcadMLeaderStyleImpl::GetEnableBlockRotation() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_EnableBlockRotation(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadMLeaderStyleImpl::SetEnableBlockRotation(bool val) const
{
    PyThrowBadHr(impObj()->put_EnableBlockRotation(val ? VARIANT_TRUE : VARIANT_FALSE));
}

double PyIAcadMLeaderStyleImpl::GetBlockRotation() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_BlockRotation(&rtval));
    return rtval;
}

void PyIAcadMLeaderStyleImpl::SetBlockRotation(double val) const
{
    PyThrowBadHr(impObj()->put_BlockRotation(val));
}

PyAcBlockConnectionType PyIAcadMLeaderStyleImpl::GetBlockConnectionType() const
{
    AcBlockConnectionType rtval = (AcBlockConnectionType)PyAcBlockConnectionType::pyacConnectExtents;
    PyThrowBadHr(impObj()->get_BlockConnectionType(&rtval));
    return (PyAcBlockConnectionType)rtval;
}

void PyIAcadMLeaderStyleImpl::SetBlockConnectionType(PyAcBlockConnectionType val) const
{
    PyThrowBadHr(impObj()->put_BlockConnectionType((AcBlockConnectionType)val));
}

double PyIAcadMLeaderStyleImpl::GetScaleFactor() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_ScaleFactor(&rtval));
    return rtval;
}

void PyIAcadMLeaderStyleImpl::SetScaleFactor(double val) const
{
    PyThrowBadHr(impObj()->put_ScaleFactor(val));
}

bool PyIAcadMLeaderStyleImpl::GetOverwritePropChanged() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_OverwritePropChanged(&rtval));
    return rtval != VARIANT_FALSE;
}

bool PyIAcadMLeaderStyleImpl::GetAnnotative() const
{
    VARIANT_BOOL rtval = VARIANT_FALSE;
    PyThrowBadHr(impObj()->get_Annotative(&rtval));
    return rtval != VARIANT_FALSE;
}

void PyIAcadMLeaderStyleImpl::SetAnnotative(bool val) const
{
    PyThrowBadHr(impObj()->put_Annotative(val ? VARIANT_TRUE : VARIANT_FALSE));
}

double PyIAcadMLeaderStyleImpl::GetBreakSize() const
{
    double rtval = 0.0;
    PyThrowBadHr(impObj()->get_BreakSize(&rtval));
    return rtval;
}

void PyIAcadMLeaderStyleImpl::SetBreakSize(double val) const
{
    PyThrowBadHr(impObj()->put_BreakSize(val));
}

CString PyIAcadMLeaderStyleImpl::GetTextString() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_TextString(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadMLeaderStyleImpl::SetTextString(const CString& val) const
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_TextString(bstrval));
}

PyAcTextAngleType PyIAcadMLeaderStyleImpl::GetTextAngleType() const
{
    AcTextAngleType rtval = (AcTextAngleType)PyAcTextAngleType::pyacInsertAngle;
    PyThrowBadHr(impObj()->get_TextAngleType(&rtval));
    return (PyAcTextAngleType)rtval;
}

void PyIAcadMLeaderStyleImpl::SetTextAngleType(PyAcTextAngleType val) const
{
    PyThrowBadHr(impObj()->put_TextAngleType((AcTextAngleType)val));
}

PyAcTextAlignmentType PyIAcadMLeaderStyleImpl::GetTextAlignmentType() const
{
    AcTextAlignmentType rtval = (AcTextAlignmentType)PyAcTextAlignmentType::pyacLeftAlignment;
    PyThrowBadHr(impObj()->get_TextAlignmentType(&rtval));
    return (PyAcTextAlignmentType)rtval;
}

void PyIAcadMLeaderStyleImpl::SetTextAlignmentType(PyAcTextAlignmentType val) const
{
    PyThrowBadHr(impObj()->put_TextAlignmentType((AcTextAlignmentType)val));
}

void PyIAcadMLeaderStyleImpl::SetTextBottomAttachmentType(PyAcVerticalTextAttachmentType val) const
{
#ifdef _BRXTARGET260
    throw PyNotimplementedByHost{};
#else
    PyThrowBadHr(impObj()->put_TextBottomAttachmentType((AcVerticalTextAttachmentType)val));
#endif
}

IAcadMLeaderStyle* PyIAcadMLeaderStyleImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadMLeaderStyle*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadLayoutsImpl
PyIAcadLayoutsImpl::PyIAcadLayoutsImpl(IAcadLayouts* ptr)
    : PyIAcadObjectImpl(ptr)
{
}

PyIAcadLayoutPtr PyIAcadLayoutsImpl::GetItem(long ind) const
{
    _variant_t vtind{ ind };
    IAcadLayout* ptr = nullptr;
    PyThrowBadHr(impObj()->Item(vtind, &ptr));
    return std::make_unique<PyIAcadLayoutImpl>(ptr);
}

long PyIAcadLayoutsImpl::GetCount() const
{
    long ind = 0;
    PyThrowBadHr(impObj()->get_Count(&ind));
    return ind;
}

PyIAcadLayoutPtr PyIAcadLayoutsImpl::Add(const CString& name) const
{
    _bstr_t bstrVal{ name };
    IAcadLayout* ptr = nullptr;
    PyThrowBadHr(impObj()->Add(bstrVal, &ptr));
    return std::make_unique<PyIAcadLayoutImpl>(ptr);
}

PyIAcadLayoutPtrArray PyIAcadLayoutsImpl::GetIter() const
{
    IUnknownPtr pUnk;
    IEnumVARIANTPtr vtenum;
    PyIAcadLayoutPtrArray vec;
    PyThrowBadHr(impObj()->get__NewEnum((IUnknown**)&pUnk));
    PyThrowBadHr(pUnk->QueryInterface(IID_IEnumVARIANT, (void**)&vtenum));
    {
        HRESULT hr = S_OK;
        for (unsigned long idx = 0, iout = 0; hr == S_OK; idx++)
        {
            _variant_t item;
            if (hr = vtenum->Next(1, &item.GetVARIANT(), &iout); hr == S_OK)
                vec.emplace_back(std::make_shared<PyIAcadLayoutImpl>((IAcadLayout*)(IDispatch*)item));
        }
    }
    return vec;
}

IAcadLayouts* PyIAcadLayoutsImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadLayouts*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadSortentsTableImpl
PyIAcadSortentsTableImpl::PyIAcadSortentsTableImpl(IAcadSortentsTable* ptr)
    : PyIAcadObjectImpl(ptr)
{
}

void PyIAcadSortentsTableImpl::MoveToBottom(const PyIAcadEntityImplArray& ents) const
{
    _variant_t vtval;
    PyThrowBadHr(PyIAcadEntityImplArrayToVariant(vtval, ents));
    PyThrowBadHr(impObj()->MoveToBottom(vtval));
}

void PyIAcadSortentsTableImpl::MoveToTop(const PyIAcadEntityImplArray& ents) const
{
    _variant_t vtval;
    PyThrowBadHr(PyIAcadEntityImplArrayToVariant(vtval, ents));
    PyThrowBadHr(impObj()->MoveToTop(vtval));
}

void PyIAcadSortentsTableImpl::MoveBelow(const PyIAcadEntityImplArray& ents, const PyIAcadEntityImpl& target) const
{
    _variant_t vtval;
    PyThrowBadHr(PyIAcadEntityImplArrayToVariant(vtval, ents));
    PyThrowBadHr(impObj()->MoveBelow(vtval, target.impObj()));
}

void PyIAcadSortentsTableImpl::MoveAbove(const PyIAcadEntityImplArray& ents, const PyIAcadEntityImpl& target) const
{
    _variant_t vtval;
    PyThrowBadHr(PyIAcadEntityImplArrayToVariant(vtval, ents));
    PyThrowBadHr(impObj()->MoveAbove(vtval, target.impObj()));
}

void PyIAcadSortentsTableImpl::SwapOrder(const PyIAcadEntityImpl& left, const PyIAcadEntityImpl& right) const
{
    PyThrowBadHr(impObj()->SwapOrder(left.impObj(), right.impObj()));
}

PyIAcadBlockPtr PyIAcadSortentsTableImpl::Block() const
{
    IAcadBlock* pBlock = nullptr;
    PyThrowBadHr(impObj()->Block(&pBlock));
    return std::make_unique<PyIAcadBlockImpl>(pBlock);
}

PyIAcadEntityPtrArray PyIAcadSortentsTableImpl::GetFullDrawOrder(bool honorSortentsSysvar) const
{
    _variant_t vtents;
    PyIAcadEntityPtrArray vec;
    PyThrowBadHr(impObj()->GetFullDrawOrder(&vtents.GetVARIANT(), honorSortentsSysvar ? VARIANT_TRUE : VARIANT_FALSE));
    PyThrowBadHr(VariantToPyIAcadEntityPtrArray(vtents, vec));
    return vec;
}

PyIAcadEntityPtrArray PyIAcadSortentsTableImpl::GetRelativeDrawOrder(bool honorSortentsSysvar) const
{
    _variant_t vtents;
    PyIAcadEntityPtrArray vec;
    PyThrowBadHr(impObj()->GetRelativeDrawOrder(&vtents.GetVARIANT(), honorSortentsSysvar ? VARIANT_TRUE : VARIANT_FALSE));
    PyThrowBadHr(VariantToPyIAcadEntityPtrArray(vtents, vec));
    return vec;
}

void PyIAcadSortentsTableImpl::SetRelativeDrawOrder(const PyIAcadEntityImplArray& ents) const
{
    _variant_t vtval;
    PyThrowBadHr(PyIAcadEntityImplArrayToVariant(vtval, ents));
    PyThrowBadHr(impObj()->SetRelativeDrawOrder(vtval));
}

IAcadSortentsTable* PyIAcadSortentsTableImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadSortentsTable*>(m_pimpl.GetInterfacePtr());
}

