#include "stdafx.h"
#include "PyAcadDbObjectImpl.h"
#include "PyAcadEntityImpl.h"
#include "PyAcadApplicationImpl.h"
#include "axmat3d.h"

//------------------------------------------------------------------------------------
//PyIAcad helpers
// 
//this is duplicate code for sheetsets, though not for Zw or Gs
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
    TypedVariants typedVariants;
    try
    {
        _variant_t xdataTypes = {};
        _variant_t xdataValues = {};
        _bstr_t bstrAppName{ appName };
        CHECKHR(impObj()->GetXData(bstrAppName, &xdataTypes.GetVARIANT(), &xdataValues.GetVARIANT()));

        auto xdataTypeLen = VariantGetElementCount(xdataTypes);
        auto xdataDalueLen = VariantGetElementCount(xdataValues);
        if (xdataTypeLen != xdataDalueLen)
            return typedVariants;

        CComSafeArray<VARIANT> safeVariantArray;
        if (safeVariantArray.Attach(xdataValues.parray) == S_OK)
        {
            for (auto idx = 0; idx < xdataTypeLen; idx++)
            {
                int16_t xdcode = 0;
                CHECKHR(VariantGetInt16Elem(xdataTypes, idx, &xdcode));
                const auto& variantItem = safeVariantArray.GetAt(idx);
                if (IsVariantString(variantItem))
                {
                    std::wstring val(wcslen(variantItem.bstrVal) + 1, '\0');
                    if (CHECKHR(VariantToString(variantItem, val.data(), val.size())))
                        typedVariants.emplace_back(TypedVariant{ xdcode, val });
                }
                else if (variantItem.vt == VT_I2 || variantItem.vt == VT_UI2)
                {
                    int16_t val = 0;
                    if (CHECKHR(VariantToInt16(variantItem, &val)))
                        typedVariants.emplace_back(TypedVariant{ xdcode, val });
                }
                else if (variantItem.vt == VT_I4 || variantItem.vt == VT_UI4)
                {
                    int32_t val = 0;
                    if (CHECKHR(VariantToInt32(variantItem, &val)))
                        typedVariants.emplace_back(TypedVariant{ xdcode, val });
                }
                else if (variantItem.vt == VT_R4 || variantItem.vt == VT_R8)
                {
                    double val = .0;
                    if (CHECKHR(VariantToDouble(variantItem, &val)))
                        typedVariants.emplace_back(TypedVariant{ xdcode, val });
                }
                else if (IsVariantArray(variantItem))
                {
                    AcGePoint3d val;
                    ULONG pcElem = 0;
                    constexpr ULONG szof = sizeof(AcGePoint3d) / sizeof(double);
                    if (CHECKHR(VariantToDoubleArray(variantItem, asDblArray(val), szof, &pcElem)))
                        typedVariants.emplace_back(TypedVariant{ xdcode, val });
                }
                else
                {
                    //TODO: Binary Data?
                    acutPrintf(_T("\nUnrecognised variant %ls, %ld"), __FUNCTIONW__, __LINE__);
                }
            }
            xdataValues.Detach();
        }
    }
    catch (...)
    {
        acutPrintf(_T("\nError Fail@ = %ls"), __FUNCTIONW__);
    }
    return typedVariants;
}

void PyIAcadObjectImpl::SetXData(const TypedVariants& typedVariants)
{
    try
    {
        CComSafeArray<int16_t> safeCodesArray(typedVariants.size());
        CComSafeArray<VARIANT> safeVariantArray(typedVariants.size());
        for (size_t idx = 0; idx < typedVariants.size(); idx++)
        {
            const auto& typedVariant = typedVariants.at(idx);
            safeCodesArray[int(idx)] = typedVariant.code;
            TypedVariant::ETypeCode eType = static_cast<TypedVariant::ETypeCode>(typedVariant.variant.index());
            switch (eType)
            {
                case TypedVariant::kInt16:
                {
                    auto& v = safeVariantArray[int(idx)];
                    const auto& tv = std::get<TypedVariant::kInt16>(typedVariant.variant);
                    CHECKHR(InitVariantFromInt16(tv, &v));
                    break;
                }
                case TypedVariant::kInt32:
                {
                    auto& v = safeVariantArray[int(idx)];
                    const auto& tv = std::get<TypedVariant::kInt32>(typedVariant.variant);
                    CHECKHR(InitVariantFromInt32(tv, &v));
                    break;
                }
                case TypedVariant::kFloat:
                {
                    auto& v = safeVariantArray[int(idx)];
                    const auto& tv = std::get<TypedVariant::kFloat>(typedVariant.variant);
                    CHECKHR(InitVariantFromDouble(tv, &v));
                    break;
                }
                case TypedVariant::kPoint3d:
                {
                    auto& v = safeVariantArray[int(idx)];
                    constexpr ULONG szof = sizeof(AcGePoint3d) / sizeof(double);
                    const auto& tv = std::get<TypedVariant::kPoint3d>(typedVariant.variant);
                    CHECKHR(InitVariantFromDoubleArray(asDblArray(tv), szof, &v));
                    break;
                }
                case TypedVariant::kString:
                {
                    auto& v = safeVariantArray[int(idx)];
                    const auto& tv = std::get<TypedVariant::ETypeCode::kString>(typedVariant.variant);
                    CHECKHR(InitVariantFromString(tv.data(), &v));
                    break;
                }
            }
        }

        VARIANT xdataTypes;
        VariantInit(&xdataTypes);
        xdataTypes.vt = VT_ARRAY | VT_I2;
        xdataTypes.parray = safeCodesArray;

        VARIANT xdataValues;
        VariantInit(&xdataValues);
        xdataValues.vt = VT_ARRAY | VT_VARIANT;
        xdataValues.parray = safeVariantArray;

        if (auto hr = impObj()->SetXData(xdataTypes, xdataValues); hr != S_OK)
            acutPrintf(_T("\nError Fail HR-0x%X  = %ls, %ld"), hr, __FUNCTIONW__, __LINE__);
    }
    catch (...)
    {
        acutPrintf(_T("\nError Fail@ = %ls"), __FUNCTIONW__);
    }
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
    oid.setFromOldId(id);
    return oid;
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
    //TODO: duplicate code with xdtata!!
    TypedVariants typedVariants;
    try
    {
        _variant_t xdataTypes = {};
        _variant_t xdataValues = {};
        CHECKHR(impObj()->GetXRecordData(&xdataTypes.GetVARIANT(), &xdataValues.GetVARIANT()));

        auto xdataTypeLen = VariantGetElementCount(xdataTypes);
        auto xdataDalueLen = VariantGetElementCount(xdataValues);
        if (xdataTypeLen != xdataDalueLen)
            return typedVariants;

        CComSafeArray<VARIANT> safeVariantArray;
        if (safeVariantArray.Attach(xdataValues.parray) == S_OK)
        {
            for (auto idx = 0; idx < xdataTypeLen; idx++)
            {
                int16_t xdcode = 0;
                CHECKHR(VariantGetInt16Elem(xdataTypes, idx, &xdcode));
                const auto& variantItem = safeVariantArray.GetAt(idx);
                if (IsVariantString(variantItem))
                {
                    std::wstring val(wcslen(variantItem.bstrVal) + 1, '\0');
                    if (CHECKHR(VariantToString(variantItem, val.data(), val.size())))
                        typedVariants.emplace_back(TypedVariant{ xdcode, val });
                }
                else if (variantItem.vt == VT_I2 || variantItem.vt == VT_UI2)
                {
                    int16_t val = 0;
                    if (CHECKHR(VariantToInt16(variantItem, &val)))
                        typedVariants.emplace_back(TypedVariant{ xdcode, val });
                }
                else if (variantItem.vt == VT_I4 || variantItem.vt == VT_UI4)
                {
                    int32_t val = 0;
                    if (CHECKHR(VariantToInt32(variantItem, &val)))
                        typedVariants.emplace_back(TypedVariant{ xdcode, val });
                }
                else if (variantItem.vt == VT_R4 || variantItem.vt == VT_R8)
                {
                    double val = .0;
                    if (CHECKHR(VariantToDouble(variantItem, &val)))
                        typedVariants.emplace_back(TypedVariant{ xdcode, val });
                }
                else if (IsVariantArray(variantItem))
                {
                    AcGePoint3d val;
                    ULONG pcElem = 0;
                    constexpr ULONG szof = sizeof(AcGePoint3d) / sizeof(double);
                    if (CHECKHR(VariantToDoubleArray(variantItem, asDblArray(val), szof, &pcElem)))
                        typedVariants.emplace_back(TypedVariant{ xdcode, val });
                }
                else
                {
                    //TODO: Binary Data?
                    acutPrintf(_T("\nUnrecognised variant %ls, %ld"), __FUNCTIONW__, __LINE__);
                }
            }
            xdataValues.Detach();
        }
    }
    catch (...)
    {
        acutPrintf(_T("\nError Fail@ = %ls"), __FUNCTIONW__);
    }
    return typedVariants;
}

void PyIAcadXRecordImpl::SetXRecordData(const TypedVariants& typedVariants)
{
    try
    {
        //TODO: duplicate code with xdtata!!
        CComSafeArray<int16_t> safeCodesArray(typedVariants.size());
        CComSafeArray<VARIANT> safeVariantArray(typedVariants.size());
        for (size_t idx = 0; idx < typedVariants.size(); idx++)
        {
            const auto& typedVariant = typedVariants.at(idx);
            safeCodesArray[int(idx)] = typedVariant.code;
            TypedVariant::ETypeCode eType = static_cast<TypedVariant::ETypeCode>(typedVariant.variant.index());
            switch (eType)
            {
                case TypedVariant::kInt16:
                {
                    auto& v = safeVariantArray[int(idx)];
                    const auto& tv = std::get<TypedVariant::kInt16>(typedVariant.variant);
                    CHECKHR(InitVariantFromInt16(tv, &v));
                    break;
                }
                case TypedVariant::kInt32:
                {
                    auto& v = safeVariantArray[int(idx)];
                    const auto& tv = std::get<TypedVariant::kInt32>(typedVariant.variant);
                    CHECKHR(InitVariantFromInt32(tv, &v));
                    break;
                }
                case TypedVariant::kFloat:
                {
                    auto& v = safeVariantArray[int(idx)];
                    const auto& tv = std::get<TypedVariant::kFloat>(typedVariant.variant);
                    CHECKHR(InitVariantFromDouble(tv, &v));
                    break;
                }
                case TypedVariant::kPoint3d:
                {
                    auto& v = safeVariantArray[int(idx)];
                    constexpr ULONG szof = sizeof(AcGePoint3d) / sizeof(double);
                    const auto& tv = std::get<TypedVariant::kPoint3d>(typedVariant.variant);
                    CHECKHR(InitVariantFromDoubleArray(asDblArray(tv), szof, &v));
                    break;
                }
                case TypedVariant::kString:
                {
                    auto& v = safeVariantArray[int(idx)];
                    const auto& tv = std::get<TypedVariant::ETypeCode::kString>(typedVariant.variant);
                    CHECKHR(InitVariantFromString(tv.data(), &v));
                    break;
                }
            }
        }

        VARIANT xdataTypes;
        VariantInit(&xdataTypes);
        xdataTypes.vt = VT_ARRAY | VT_I2;
        xdataTypes.parray = safeCodesArray;

        VARIANT xdataValues;
        VariantInit(&xdataValues);
        xdataValues.vt = VT_ARRAY | VT_VARIANT;
        xdataValues.parray = safeVariantArray;

        if (auto hr = impObj()->SetXRecordData(xdataTypes, xdataValues); hr != S_OK)
            acutPrintf(_T("\nError Fail HR-0x%X  = %ls, %ld"), hr, __FUNCTIONW__, __LINE__);
    }
    catch (...)
    {
        acutPrintf(_T("\nError Fail@ = %ls"), __FUNCTIONW__);
    }
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
#if defined (_GRXTARGET250)
    throw PyNotimplementedByHost{};
#else
    long rtval = 0;
    PyThrowBadHr(impObj()->get_TextGenerationFlag(&rtval));
    return rtval;
#endif
}

void PyIAcadTextStyleImpl::SetTextGenerationFlag(long val) const
{
#if defined (_GRXTARGET250)
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

IAcadSortentsTable* PyIAcadSortentsTableImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadSortentsTable*>(m_pimpl.GetInterfacePtr());
}

