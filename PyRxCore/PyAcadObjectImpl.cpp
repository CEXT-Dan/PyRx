#include "stdafx.h"
#include "PyAcadObjectImpl.h"

#ifdef PYRX_IN_PROGRESS_PYAX
#include "PyAcadApplicationImpl.h"

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
            xdataValues.Detach();

        for (auto idx = 0; idx < xdataTypeLen; idx++)
        {
            int16_t xdcode = 0;
            CHECKHR(VariantGetInt16Elem(xdataTypes, idx, &xdcode));
            const auto& variantItem = safeVariantArray.GetAt(idx);
            if (IsVariantString(variantItem))
            {
                std::wstring val(wcslen(variantItem.bstrVal) + 1, '\0');
                if(CHECKHR(VariantToString(variantItem, val.data(), val.size())))
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
                constexpr ULONG s = sizeof(AcGePoint3d) / sizeof(double);
                if (CHECKHR(VariantToDoubleArray(variantItem, asDblArray(val), s, &pcElem)))
                    typedVariants.emplace_back(TypedVariant{ xdcode, val });
            }
            else
            {
                //TODO: Binary Data?
                acutPrintf(_T("\nUnrecognised variant %ls, %ld"), __FUNCTIONW__, __LINE__);
            }
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
                    constexpr ULONG sz = sizeof(AcGePoint3d) / sizeof(double);
                    const auto& tv = std::get<TypedVariant::kPoint3d>(typedVariant.variant);
                    CHECKHR(InitVariantFromDoubleArray(asDblArray(tv), sz, &v));
                    break;
                }
                case TypedVariant::kString:
                {
                    auto& v = safeVariantArray[int(idx)];
                    const auto& tv = std::get<size_t(TypedVariant::ETypeCode::kString)>(typedVariant.variant);
                    CHECKHR(InitVariantFromString(tv.data(), &v));
                    break;
                }
            }
        }
        _variant_t  xdataTypes = {};
        xdataTypes.vt = VT_ARRAY | VT_I2;
        xdataTypes.parray = safeCodesArray.Detach();

        _variant_t  xdataValues = {};
        xdataValues.vt = VT_ARRAY | VT_VARIANT;
        xdataValues.parray = safeVariantArray.Detach();

        if (auto hr = impObj()->SetXData(xdataTypes, xdataValues); hr != S_OK)
            acutPrintf(_T("\nError Fail HR-0x%X  = %ls, %ld"), hr, __FUNCTIONW__, __LINE__);
    }
    catch (...)
    {
        acutPrintf(_T("\nError Fail@ = %ls"), __FUNCTIONW__);
    }
}

void PyIAcadObjectImpl::Delete()
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

PyAcadApplicationImpl PyIAcadObjectImpl::GetApplication() const
{
    LPDISPATCH lpdsp = nullptr;
    PyThrowBadHr(impObj()->get_Application(&lpdsp));
    return PyAcadApplicationImpl(static_cast<IAcadApplication*>(lpdsp));
}

PyIAcadDatabaseImpl PyIAcadObjectImpl::GetDatabase() const
{
    IAcadDatabase* pDb = nullptr;
    PyThrowBadHr(impObj()->get_Database(&pDb));
    return PyIAcadDatabaseImpl(pDb);
}

bool PyIAcadObjectImpl::GetHasExtensionDictionary() const
{
    VARIANT_BOOL rtVal;
    PyThrowBadHr(impObj()->get_HasExtensionDictionary(&rtVal));
    return rtVal == VARIANT_TRUE;
}

PyIAcadDictionaryImpl PyIAcadObjectImpl::GetExtensionDictionary() const
{
    IAcadDictionary* pval = nullptr;
    PyThrowBadHr(impObj()->GetExtensionDictionary(&pval));
    return PyIAcadDictionaryImpl(pval);
}

PyIAcadDocumentImpl PyIAcadObjectImpl::GetDocument() const
{
    LPDISPATCH lpdsp = nullptr;
    PyThrowBadHr(impObj()->get_Document(&lpdsp));
    return PyIAcadDocumentImpl(static_cast<IAcadDocument*>(lpdsp));
}

void PyIAcadObjectImpl::Erase()
{
    PyThrowBadHr(impObj()->Erase());
}

bool PyIAcadObjectImpl::IsEqualTo(const PyIAcadObjectImpl& other)
{
    return other.m_pimpl == m_pimpl;
}

bool PyIAcadObjectImpl::IsNull()
{
    return m_pimpl == nullptr;
}

std::size_t PyIAcadObjectImpl::hash() const
{
    return std::hash<IAcadObject*>{}((IAcadObject*)m_pimpl);
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

IAcadPlotConfiguration* PyIAcadPlotConfigurationImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadPlotConfiguration*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadSectionSettingsImpl
PyIAcadSectionSettingsImpl::PyIAcadSectionSettingsImpl(IAcadSectionSettings* ptr)
    : PyIAcadObjectImpl(ptr)
{
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

IAcadPlotConfigurations* PyIAcadPlotConfigurationsImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadPlotConfigurations*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadSectionManagerImpl
PyIAcadSectionManagerImpl::PyIAcadSectionManagerImpl(IAcadPlotConfigurations* ptr)
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
PyIAcadMaterialsImpl::PyIAcadMaterialsImpl(IAcadMaterial* ptr)
    : PyIAcadObjectImpl(ptr)
{
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
//PyIAcadBlockImpl
PyIAcadBlockImpl::PyIAcadBlockImpl(IAcadBlock* ptr)
    : PyIAcadObjectImpl(ptr)
{
}

IAcadBlock* PyIAcadBlockImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadBlock*>(m_pimpl.GetInterfacePtr());
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
//PyIAcadLayoutsImpl
PyIAcadLayoutsImpl::PyIAcadLayoutsImpl(IAcadLayouts* ptr)
    : PyIAcadObjectImpl(ptr)
{
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

#endif
