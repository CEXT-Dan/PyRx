#include "stdafx.h"
#include "PySmSheetSetMgrImpl.h"

#if defined(_ARXTARGET) || defined(_BRXTARGET) 

#if defined(_ARXTARGET)
#include "axboiler.h"
#endif

#if defined(_BRXTARGET)//TODO: link error
extern HRESULT AcAxGetIUnknownOfObject(LPUNKNOWN*, AcDbObjectId&, LPDISPATCH);
extern HRESULT AcAxGetIUnknownOfObject(LPUNKNOWN*, AcDbObject*, LPDISPATCH);
extern HRESULT AcAxGetDatabase(AcDbDatabase* pDb, LPDISPATCH pAppDisp, LPDISPATCH* pDisp);
#endif

static IAcadObject* GetIAcadObjectFromAcDbObjectId(AcDbObjectId& eid)
{
    IUnknown* pUnk = nullptr;
    LPDISPATCH pAppDisp = acedGetIDispatch(false);
    if (AcAxGetIUnknownOfObject(&pUnk, eid, pAppDisp) == S_OK && pUnk) {
        IAcadObject* pObj = nullptr;
        if (pUnk->QueryInterface(IID_IAcadObject, (void**)&pObj) == S_OK && pObj) {
            return pObj;
        }
    }
    return nullptr;
}

static IAcadObject* GetIAcadObjectFromAcDbObject(AcDbObject* pSrcObject)
{
    IUnknown* pUnk = nullptr;
    LPDISPATCH pAppDisp = acedGetIDispatch(false);
    if (AcAxGetIUnknownOfObject(&pUnk, pSrcObject, pAppDisp) == S_OK && pUnk) {
        IAcadObject* pObj = nullptr;
        if (pUnk->QueryInterface(IID_IAcadObject, (void**)&pObj) == S_OK && pObj) {
            return pObj;
        }
    }
    return nullptr;
}

static IAcadDatabase* GetIAcadDatabaseFromAcDbDatabse(AcDbDatabase* pSrcObject)
{
    LPDISPATCH pUnk = nullptr;
    LPDISPATCH pAppDisp = acedGetIDispatch(false);
    if (AcAxGetDatabase(pSrcObject, pAppDisp, &pUnk) == S_OK && pUnk) {
        IAcadDatabase* pObj = nullptr;
        if (pUnk->QueryInterface(IID_IAcadDatabase, (void**)&pObj) == S_OK && pObj) {
            return pObj;
        }
    }
    return nullptr;
}

//----------------------------------------------------------------------------------------
//PySmPersist
PySmPersistImpl::PySmPersistImpl(IAcSmPersist* other)
{
    if (other != nullptr)
        m_pimpl.Attach(other);
}

bool PySmPersistImpl::GetIsDirty() const
{
    VARIANT_BOOL rtVal;
    PyThrowBadHr(impObj()->GetIsDirty(&rtVal));
    return rtVal == VARIANT_TRUE;
}

CString PySmPersistImpl::GetTypeName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->GetTypeName(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PySmPersistImpl::InitNew(const PySmPersistImpl& owner)
{
    PyThrowBadHr(impObj()->InitNew(owner.impObj()));
}

PySmPersistImpl PySmPersistImpl::GetOwner() const
{
    IAcSmPersist* rtVal = nullptr;
    PyThrowBadHr(impObj()->GetOwner(&rtVal));
    return PySmPersistImpl(rtVal);
}

void PySmPersistImpl::SetOwner(const PySmPersistImpl& owner)
{
    PyThrowBadHr(impObj()->SetOwner(owner.impObj()));
}

PySmDatabaseImpl PySmPersistImpl::GetDatabase() const
{
    IAcSmDatabase* rtVal = nullptr;
    PyThrowBadHr(impObj()->GetDatabase(&rtVal));
    return PySmDatabaseImpl(rtVal);
}

PySmObjectIdImpl PySmPersistImpl::GetObjectId() const
{
    IAcSmObjectId* rtVal = nullptr;
    PyThrowBadHr(impObj()->GetObjectId(&rtVal));
    return PySmObjectIdImpl(rtVal);
}

void PySmPersistImpl::Clear()
{
    PyThrowBadHr(impObj()->Clear());
}

bool PySmPersistImpl::IsNull()
{
    return impObj() == nullptr;
}

void PySmPersistImpl::swap(PySmPersistImpl& other)
{
    std::swap(m_pimpl, other.m_pimpl);
}

IAcSmPersist* PySmPersistImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<IAcSmPersist*>(m_pimpl.GetInterfacePtr());
}

//-----------------------------------------------------------------------------------------
//PySmAcDbDatabase
PySmAcDbDatabaseImpl::PySmAcDbDatabaseImpl(IAcSmAcDbDatabase* other)
{
    if (other != nullptr)
        m_pimpl.Attach(other);
}

IAcadDatabasePtr PySmAcDbDatabaseImpl::GetIAcadDatabase()
{
    IAcadDatabase* axdb;
    PyThrowBadHr(m_pimpl->GetIAcadDatabase(&axdb));
    return IAcadDatabasePtr{ axdb };
}

AcDbDatabase* PySmAcDbDatabaseImpl::GetAcDbDatabase()
{
    LPVOID pDb;// eewww, LPVOID is prettier than void* though : |
    PyThrowBadHr(m_pimpl->GetAcDbDatabase(&pDb));
    return  reinterpret_cast<AcDbDatabase*>(pDb);
}

IAcSmAcDbDatabase* PySmAcDbDatabaseImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<IAcSmAcDbDatabase*>(m_pimpl.GetInterfacePtr());
}

//-----------------------------------------------------------------------------------------
//IAcSmObjectId
PySmObjectIdImpl::PySmObjectIdImpl(IAcSmObjectId* other)
{
    if (other != nullptr)
        m_pimpl.Attach(other);
}

CString PySmObjectIdImpl::GetHandle() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->GetHandle(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

PySmDatabaseImpl PySmObjectIdImpl::GetDatabase() const
{
    IAcSmDatabase* pVal = nullptr;
    PyThrowBadHr(impObj()->GetDatabase(&pVal));
    return PySmDatabaseImpl(pVal);
}

PySmPersistImpl PySmObjectIdImpl::GetPersistObject() const
{
    IAcSmPersist* pVal = nullptr;
    PyThrowBadHr(impObj()->GetPersistObject(&pVal));
    return PySmPersistImpl(pVal);
}

PySmPersistImpl PySmObjectIdImpl::GetOwner() const
{
    IAcSmPersist* pVal = nullptr;
    PyThrowBadHr(impObj()->GetOwner(&pVal));
    return PySmPersistImpl(pVal);
}

bool PySmObjectIdImpl::IsEqual(const PySmObjectIdImpl& other)
{
    VARIANT_BOOL rtVal;
    PyThrowBadHr(impObj()->IsEqual(other.impObj(), &rtVal));
    return rtVal == VARIANT_TRUE;
}

bool PySmObjectIdImpl::IsValid()
{
    VARIANT_BOOL rtVal;
    PyThrowBadHr(impObj()->IsValid(&rtVal));
    return rtVal == VARIANT_TRUE;
}

IAcSmObjectId* PySmObjectIdImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<IAcSmObjectId*>(m_pimpl.GetInterfacePtr());
}

//-----------------------------------------------------------------------------------------
//PySmFileReference
PySmFileReferenceImpl::PySmFileReferenceImpl()
    : PySmPersistImpl(nullptr)
{
    PyThrowBadHr(m_pimpl.CreateInstance(CLSID_AcSmFileReference));
}

PySmFileReferenceImpl::PySmFileReferenceImpl(IAcSmFileReference* other)
    : PySmPersistImpl(other)
{
}

void PySmFileReferenceImpl::SetFileName(const CString& csVal)
{
    _bstr_t bstrVal(csVal);
    PyThrowBadHr(impObj()->SetFileName(bstrVal));
}

CString PySmFileReferenceImpl::GetFileName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->GetFileName(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

CString PySmFileReferenceImpl::ResolveFileName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->GetFileName(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

IAcSmFileReference* PySmFileReferenceImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<IAcSmFileReference*>(m_pimpl.GetInterfacePtr());
}

//-----------------------------------------------------------------------------------------
//PySmAcDbObjectReference
PySmAcDbObjectReferenceImpl::PySmAcDbObjectReferenceImpl()
    : PySmFileReferenceImpl(nullptr)
{
    PyThrowBadHr(m_pimpl.CreateInstance(CLSID_AcSmAcDbObjectReference));
}

PySmAcDbObjectReferenceImpl::PySmAcDbObjectReferenceImpl(IAcSmAcDbObjectReference* other)
    : PySmFileReferenceImpl(other)
{
}

IAcSmAcDbObjectReference* PySmAcDbObjectReferenceImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<IAcSmAcDbObjectReference*>(m_pimpl.GetInterfacePtr());
}

//-----------------------------------------------------------------------------------------
//PySmNamedAcDbObjectReference
PySmNamedAcDbObjectReferenceImpl::PySmNamedAcDbObjectReferenceImpl()
    : PySmAcDbObjectReferenceImpl(nullptr)
{
    PyThrowBadHr(m_pimpl.CreateInstance(CLSID_AcSmNamedAcDbObjectReference));
}

PySmNamedAcDbObjectReferenceImpl::PySmNamedAcDbObjectReferenceImpl(IAcSmNamedAcDbObjectReference* other)
    : PySmAcDbObjectReferenceImpl(other)
{
}

IAcSmNamedAcDbObjectReference* PySmNamedAcDbObjectReferenceImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<IAcSmNamedAcDbObjectReference*>(m_pimpl.GetInterfacePtr());
}

//-----------------------------------------------------------------------------------------
//IAcSmAcDbLayoutReference
PySmAcDbLayoutReferenceImpl::PySmAcDbLayoutReferenceImpl()
    : PySmNamedAcDbObjectReferenceImpl(nullptr)
{
    PyThrowBadHr(m_pimpl.CreateInstance(CLSID_AcSmAcDbLayoutReference));
}

PySmAcDbLayoutReferenceImpl::PySmAcDbLayoutReferenceImpl(IAcSmAcDbLayoutReference* other)
    : PySmNamedAcDbObjectReferenceImpl(other)
{
}

IAcSmAcDbLayoutReference* PySmAcDbLayoutReferenceImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<IAcSmAcDbLayoutReference*>(m_pimpl.GetInterfacePtr());
}

//-----------------------------------------------------------------------------------------
//PySmAcDbViewReference
PySmAcDbViewReferenceImpl::PySmAcDbViewReferenceImpl()
    : PySmNamedAcDbObjectReferenceImpl(nullptr)
{
    PyThrowBadHr(m_pimpl.CreateInstance(CLSID_AcSmAcDbViewReference));
}

PySmAcDbViewReferenceImpl::PySmAcDbViewReferenceImpl(IAcSmAcDbViewReference* other)
    : PySmNamedAcDbObjectReferenceImpl(other)
{
}

IAcSmAcDbViewReference* PySmAcDbViewReferenceImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<IAcSmAcDbViewReference*>(m_pimpl.GetInterfacePtr());
}

//-----------------------------------------------------------------------------------------
//PySmAcDbBlockRecordReference
PySmAcDbBlockRecordReferenceImpl::PySmAcDbBlockRecordReferenceImpl()
    : PySmNamedAcDbObjectReferenceImpl(nullptr)
{
    PyThrowBadHr(m_pimpl.CreateInstance(CLSID_AcSmAcDbBlockRecordReference));
}

PySmAcDbBlockRecordReferenceImpl::PySmAcDbBlockRecordReferenceImpl(IAcSmAcDbBlockRecordReference* other)
    : PySmNamedAcDbObjectReferenceImpl(other)
{
}

IAcSmAcDbBlockRecordReference* PySmAcDbBlockRecordReferenceImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<IAcSmAcDbBlockRecordReference*>(m_pimpl.GetInterfacePtr());
}

//-----------------------------------------------------------------------------------------
//PySmCustomPropertyValue
PySmCustomPropertyValueImpl::PySmCustomPropertyValueImpl()
    : PySmPersistImpl(nullptr)
{
    PyThrowBadHr(m_pimpl.CreateInstance(CLSID_AcSmCustomPropertyValue));
}

PySmCustomPropertyValueImpl::PySmCustomPropertyValueImpl(IAcSmCustomPropertyValue* other)
    : PySmPersistImpl(other)
{
}

AcValue PySmCustomPropertyValueImpl::GetValue() const
{
    //TODO: TEST
    _variant_t varVal = {};
    PyThrowBadHr(impObj()->GetValue(&varVal.GetVARIANT()));
    switch (varVal.vt)
    {
        case VT_I2:
            return AcValue(Adesk::Int32(varVal.iVal));
        case VT_I4:
            return AcValue(Adesk::Int32(varVal.lVal));
        case VT_R4:
            return AcValue(varVal.fltVal);
        case VT_R8:
            return AcValue(varVal.dblVal);
        case VT_BSTR:
            return AcValue(varVal.bstrVal);
        default:
            break;
    }
    return AcValue();
}

void PySmCustomPropertyValueImpl::SetValue(const AcValue& acVal)
{
    //TODO: TEST
    _variant_t varVal = {};
    switch (acVal.dataType())
    {
        case AcValue::kLong:
        {
            Adesk::Int32 val = acVal;
            varVal = _variant_t(int32_t(val));
        }
        break;
        case AcValue::kDouble:
        {
            double val = acVal;
            varVal = _variant_t(val);
        }
        break;
        case AcValue::kString:
        {
            const wchar_t* val = acVal;
            varVal = _variant_t(val);
        }
        break;
        default:
            PyThrowBadEs(eInvalidInput);
    }
    PyThrowBadHr(impObj()->SetValue(varVal));
}

PropertyFlags PySmCustomPropertyValueImpl::GetFlags() const
{
    PropertyFlags flags;
    PyThrowBadHr(impObj()->GetFlags(&flags));
    return flags;
}

void PySmCustomPropertyValueImpl::SetFlags(PropertyFlags flags)
{
    PyThrowBadHr(impObj()->SetFlags(flags));
}

IAcSmCustomPropertyValue* PySmCustomPropertyValueImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<IAcSmCustomPropertyValue*>(m_pimpl.GetInterfacePtr());
}

//-----------------------------------------------------------------------------------------
//PySmCustomPropertyBag
PySmCustomPropertyBagImpl::PySmCustomPropertyBagImpl()
    : PySmPersistImpl(nullptr)
{
    PyThrowBadHr(m_pimpl.CreateInstance(CLSID_AcSmCustomPropertyBag));
}

PySmCustomPropertyBagImpl::PySmCustomPropertyBagImpl(IAcSmCustomPropertyBag* other)
    : PySmPersistImpl(other)
{
}

PySmCustomPropertyValueImpl PySmCustomPropertyBagImpl::GetProperty(const CString& propName) const
{
    _bstr_t bstrName(propName);
    IAcSmCustomPropertyValue* pProp = nullptr;
    PyThrowBadHr(impObj()->GetProperty(bstrName, &pProp));
    return PySmCustomPropertyValueImpl(pProp);
}

void PySmCustomPropertyBagImpl::SetProperty(const CString& propName, const PySmCustomPropertyValueImpl& prop)
{
    _bstr_t bstrName(propName);
    PyThrowBadHr(impObj()->SetProperty(bstrName, prop.impObj()));
}

std::vector<std::pair<CString, PySmCustomPropertyValueImpl>> PySmCustomPropertyBagImpl::GetProperties() const
{
    std::vector<std::pair<CString, PySmCustomPropertyValueImpl>> v;
    IAcSmEnumPropertyPtr iter;
    PyThrowBadHr(impObj()->GetPropertyEnumerator(&iter));
    _bstr_t bstrName;
    IAcSmCustomPropertyValue* pAxProp = nullptr;
    while (SUCCEEDED(iter->Next(&bstrName.GetBSTR(), &pAxProp)) && pAxProp != nullptr)
    {
        v.push_back(std::make_pair(CString((LPCTSTR)bstrName), PySmCustomPropertyValueImpl(pAxProp)));
        pAxProp = nullptr;
        bstrName = _bstr_t{};
    }
    return v;
}

std::vector<std::pair<CString, AcValue>> PySmCustomPropertyBagImpl::GetPropertyValues() const
{
    std::vector<std::pair<CString, AcValue>> v;
    IAcSmEnumPropertyPtr iter;
    PyThrowBadHr(impObj()->GetPropertyEnumerator(&iter));
    _bstr_t bstrName;
    IAcSmCustomPropertyValue* pAxProp = nullptr;
    while (SUCCEEDED(iter->Next(&bstrName.GetBSTR(), &pAxProp)) && pAxProp != nullptr)
    {
        PySmCustomPropertyValueImpl prop(pAxProp);
        v.push_back(std::make_pair(CString((LPCTSTR)bstrName), prop.GetValue()));
        pAxProp = nullptr;
        bstrName = _bstr_t{};
    }
    return v;
}

IAcSmCustomPropertyBag* PySmCustomPropertyBagImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<IAcSmCustomPropertyBag*>(m_pimpl.GetInterfacePtr());
}

//-----------------------------------------------------------------------------------------
//PySmObjectReference
PySmObjectReferenceImpl::PySmObjectReferenceImpl()
    : PySmPersistImpl(nullptr)
{
#if defined(_BRXTARGET)
    throw PyNotimplementedByHost();
#else
    PyThrowBadHr(m_pimpl.CreateInstance(CLSID_AcSmObjectReference));
#endif
}

PySmObjectReferenceImpl::PySmObjectReferenceImpl(IAcSmObjectReference* other)
    : PySmPersistImpl(other)
{
}

IAcSmObjectReference* PySmObjectReferenceImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<IAcSmObjectReference*>(m_pimpl.GetInterfacePtr());
}


//-----------------------------------------------------------------------------------------
//PySmProjectPointLocation
PySmProjectPointLocationImpl::PySmProjectPointLocationImpl()
    : PySmPersistImpl(nullptr)
{
    PyThrowBadHr(m_pimpl.CreateInstance(CLSID_AcSmProjectPointLocation));
}

PySmProjectPointLocationImpl::PySmProjectPointLocationImpl(IAcSmProjectPointLocation* other)
    : PySmPersistImpl(other)
{
}

IAcSmProjectPointLocation* PySmProjectPointLocationImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<IAcSmProjectPointLocation*>(m_pimpl.GetInterfacePtr());
}

#if defined(_ARXTARGET)
IAcSmProjectPointLocation2* PySmProjectPointLocationImpl::impObj2(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl != nullptr)
    {
        IAcSmProjectPointLocation2* pObj = nullptr;
        if (m_pimpl->QueryInterface(IID_IAcSmProjectPointLocation2, (void**)&pObj) == S_OK && pObj) {
            return pObj;
        }
    }
    throw PyNullObject(src);
}
#endif

//-----------------------------------------------------------------------------------------
//PySmPersistProxy
PySmPersistProxyImpl::PySmPersistProxyImpl()
    : PySmPersistImpl(nullptr)
{
#if defined(_BRXTARGET)
    throw PyNotimplementedByHost();
#else
    PyThrowBadHr(m_pimpl.CreateInstance(CLSID_AcSmPersistProxy));
#endif
}

PySmPersistProxyImpl::PySmPersistProxyImpl(IAcSmPersistProxy* other)
    : PySmPersistImpl(other)
{
}

IAcSmPersistProxy* PySmPersistProxyImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<IAcSmPersistProxy*>(m_pimpl.GetInterfacePtr());
}

//-----------------------------------------------------------------------------------------
//PySmPublishOption
PySmPublishOptionsImpl::PySmPublishOptionsImpl()
    : PySmPersistImpl(nullptr)
{
    PyThrowBadHr(m_pimpl.CreateInstance(CLSID_AcSmPublishOptions));
}

PySmPublishOptionsImpl::PySmPublishOptionsImpl(IAcSmPublishOptions* other)
    : PySmPersistImpl(other)
{
}

IAcSmPublishOptions* PySmPublishOptionsImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<IAcSmPublishOptions*>(m_pimpl.GetInterfacePtr());
}

#if defined(_ARXTARGET)
IAcSmPublishOptions2* PySmPublishOptionsImpl::impObj2(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl != nullptr)
    {
        IAcSmPublishOptions2* pObj = nullptr;
        if (m_pimpl->QueryInterface(IID_IAcSmPublishOptions2, (void**)&pObj) == S_OK && pObj) {
            return pObj;
        }
    }
    throw PyNullObject(src);
}
#endif
#if defined(_ARXTARGET)
IAcSmPublishOptions3* PySmPublishOptionsImpl::impObj3(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl != nullptr)
    {
        IAcSmPublishOptions3* pObj = nullptr;
        if (m_pimpl->QueryInterface(IID_IAcSmPublishOptions3, (void**)&pObj) == S_OK && pObj) {
            return pObj;
        }
    }
    throw PyNullObject(src);
}
#endif
#if defined(_ARXTARGET)
IAcSmPublishOptions4* PySmPublishOptionsImpl::impObj4(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl != nullptr)
    {
        IAcSmPublishOptions4* pObj = nullptr;
        if (m_pimpl->QueryInterface(IID_IAcSmPublishOptions4, (void**)&pObj) == S_OK && pObj) {
            return pObj;
        }
    }
    throw PyNullObject(src);
}
#endif

//-----------------------------------------------------------------------------------------
//PySmComponent
PySmComponentImpl::PySmComponentImpl(IAcSmComponent* other)
    : PySmPersistImpl(other)
{
}

CString PySmComponentImpl::GetName() const
{
    _bstr_t bstrName;
    PyThrowBadHr(impObj()->GetName(&bstrName.GetBSTR()));
    return (LPCTSTR)bstrName;
}

void PySmComponentImpl::SetName(const CString& csName)
{
    _bstr_t bstrName(csName);
    PyThrowBadHr(impObj()->SetName(bstrName));
}

CString PySmComponentImpl::GetDesc() const
{
    _bstr_t bstrDesc;
    PyThrowBadHr(impObj()->GetDesc(&bstrDesc.GetBSTR()));
    return (LPCTSTR)bstrDesc;
}

void PySmComponentImpl::SetDesc(const CString& csDesc)
{
    _bstr_t bstrDesc(csDesc);
    PyThrowBadHr(impObj()->SetDesc(bstrDesc));
}

PySmCustomPropertyBagImpl PySmComponentImpl::GetCustomPropertyBag() const
{
    IAcSmCustomPropertyBag* pBag = nullptr;
    PyThrowBadHr(impObj()->GetCustomPropertyBag(&pBag));
    return PySmCustomPropertyBagImpl(pBag);
}

IAcSmComponent* PySmComponentImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<IAcSmComponent*>(m_pimpl.GetInterfacePtr());
}

//-----------------------------------------------------------------------------------------
//PycSmSheetSelSet
PySmSheetSelSetImpl::PySmSheetSelSetImpl()
    : PySmComponentImpl(nullptr)
{
    PyThrowBadHr(m_pimpl.CreateInstance(CLSID_AcSmSheetSelSet));
}

PySmSheetSelSetImpl::PySmSheetSelSetImpl(IAcSmSheetSelSet* other)
    : PySmComponentImpl(other)
{
}

IAcSmSheetSelSet* PySmSheetSelSetImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<IAcSmSheetSelSet*>(m_pimpl.GetInterfacePtr());
}

//-----------------------------------------------------------------------------------------
//PycSmSheetSelSets
PySmSheetSelSetsImpl::PySmSheetSelSetsImpl()
    : PySmComponentImpl(nullptr)
{
    PyThrowBadHr(m_pimpl.CreateInstance(CLSID_AcSmSheetSelSets));
}

PySmSheetSelSetsImpl::PySmSheetSelSetsImpl(IAcSmSheetSelSets* other)
    : PySmComponentImpl(other)
{
}

IAcSmSheetSelSets* PySmSheetSelSetsImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<IAcSmSheetSelSets*>(m_pimpl.GetInterfacePtr());
}

//-----------------------------------------------------------------------------------------
//PycSmSheetSelSets
PySmResourcesImpl::PySmResourcesImpl()
    : PySmComponentImpl(nullptr)
{
    PyThrowBadHr(m_pimpl.CreateInstance(CLSID_AcSmResources));
}

PySmResourcesImpl::PySmResourcesImpl(IAcSmResources* other)
    : PySmComponentImpl(other)
{
}

IAcSmResources* PySmResourcesImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<IAcSmResources*>(m_pimpl.GetInterfacePtr());
}

//-----------------------------------------------------------------------------------------
//PySmViewCategory
PySmViewCategoryImpl::PySmViewCategoryImpl()
    : PySmComponentImpl(nullptr)
{
    PyThrowBadHr(m_pimpl.CreateInstance(CLSID_AcSmViewCategory));
}

PySmViewCategoryImpl::PySmViewCategoryImpl(IAcSmViewCategory* other)
    : PySmComponentImpl(other)
{
}

IAcSmViewCategory* PySmViewCategoryImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<IAcSmViewCategory*>(m_pimpl.GetInterfacePtr());
}

//-----------------------------------------------------------------------------------------
//PySmViewCategories
PySmViewCategoriesImpl::PySmViewCategoriesImpl()
    : PySmComponentImpl(nullptr)
{
    PyThrowBadHr(m_pimpl.CreateInstance(CLSID_AcSmViewCategories));
}

PySmViewCategoriesImpl::PySmViewCategoriesImpl(IAcSmViewCategories* other)
    : PySmComponentImpl(other)
{
}

IAcSmViewCategories* PySmViewCategoriesImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<IAcSmViewCategories*>(m_pimpl.GetInterfacePtr());
}

//-----------------------------------------------------------------------------------------
//PySmSheetView
PySmSheetViewImpl::PySmSheetViewImpl()
    : PySmComponentImpl(nullptr)
{
    PyThrowBadHr(m_pimpl.CreateInstance(CLSID_AcSmSheetView));
}

PySmSheetViewImpl::PySmSheetViewImpl(IAcSmSheetView* other)
    : PySmComponentImpl(other)
{
}

IAcSmSheetView* PySmSheetViewImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<IAcSmSheetView*>(m_pimpl.GetInterfacePtr());
}


//-----------------------------------------------------------------------------------------
//PySmSheetViews
PySmSheetViewsImpl::PySmSheetViewsImpl()
    : PySmComponentImpl(nullptr)
{
    PyThrowBadHr(m_pimpl.CreateInstance(CLSID_AcSmSheetViews));
}

PySmSheetViewsImpl::PySmSheetViewsImpl(IAcSmSheetViews* other)
    : PySmComponentImpl(other)
{
}

IAcSmSheetViews* PySmSheetViewsImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<IAcSmSheetViews*>(m_pimpl.GetInterfacePtr());
}

//-----------------------------------------------------------------------------------------
//PySmProjectPointLocations
PySmProjectPointLocationsImpl::PySmProjectPointLocationsImpl()
    : PySmComponentImpl(nullptr)
{
    PyThrowBadHr(m_pimpl.CreateInstance(CLSID_AcSmProjectPointLocations));
}

PySmProjectPointLocationsImpl::PySmProjectPointLocationsImpl(IAcSmProjectPointLocations* other)
    : PySmComponentImpl(other)
{
}

IAcSmProjectPointLocations* PySmProjectPointLocationsImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<IAcSmProjectPointLocations*>(m_pimpl.GetInterfacePtr());
}

//-----------------------------------------------------------------------------------------
//IAcSmCalloutBlocks
PySmCalloutBlocksImpl::PySmCalloutBlocksImpl()
    : PySmComponentImpl(nullptr)
{
    PyThrowBadHr(m_pimpl.CreateInstance(CLSID_AcSmCalloutBlocks));
}

PySmCalloutBlocksImpl::PySmCalloutBlocksImpl(IAcSmCalloutBlocks* other)
    : PySmComponentImpl(other)
{
}

IAcSmCalloutBlocks* PySmCalloutBlocksImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<IAcSmCalloutBlocks*>(m_pimpl.GetInterfacePtr());
}

//-----------------------------------------------------------------------------------------
//PySmSubsetImpl
PySmSubsetImpl::PySmSubsetImpl()
    : PySmComponentImpl(nullptr)
{
    PyThrowBadHr(m_pimpl.CreateInstance(CLSID_AcSmSubset));
}

PySmSubsetImpl::PySmSubsetImpl(IAcSmSubset* other)
    : PySmComponentImpl(other)
{
}

IAcSmSubset* PySmSubsetImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<IAcSmSubset*>(m_pimpl.GetInterfacePtr());
}

#if defined(_ARXTARGET)
IAcSmSubset2* PySmSubsetImpl::impObj2(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl != nullptr)
    {
        IAcSmSubset2* pObj = nullptr;
        if (m_pimpl->QueryInterface(IID_IAcSmSubset2, (void**)&pObj) == S_OK && pObj) {
            return pObj;
        }
    }
    throw PyNullObject(src);
}
#endif

//-----------------------------------------------------------------------------------------
//PySmSheetSetImpl
PySmSheetSetImpl::PySmSheetSetImpl()
    : PySmSubsetImpl(nullptr)
{
    PyThrowBadHr(m_pimpl.CreateInstance(CLSID_AcSmSheetSet));
}

PySmSheetSetImpl::PySmSheetSetImpl(IAcSmSheetSet* other)
    : PySmSubsetImpl(other)
{
}

PySmFileReferenceImpl PySmSheetSetImpl::GetAltPageSetups() const
{
    IAcSmFileReference* ptr = nullptr;
    PyThrowBadHr(impObj()->GetAltPageSetups(&ptr));
    return PySmFileReferenceImpl(ptr);
}

void PySmSheetSetImpl::SetAltPageSetups(const PySmFileReferenceImpl& alt)
{
    PyThrowBadHr(impObj()->SetAltPageSetups(alt.impObj()));
}

PySmNamedAcDbObjectReferenceImpl PySmSheetSetImpl::GetDefAltPageSetup() const
{
    IAcSmNamedAcDbObjectReference* ptr = nullptr;
    PyThrowBadHr(impObj()->GetDefAltPageSetup(&ptr));
    return PySmNamedAcDbObjectReferenceImpl(ptr);
}

void PySmSheetSetImpl::SetDefAltPageSetup(const PySmNamedAcDbObjectReferenceImpl& alt)
{
    PyThrowBadHr(impObj()->SetAltPageSetups(alt.impObj()));
}

bool PySmSheetSetImpl::GetPromptForDwgName() const
{
    VARIANT_BOOL flag;
    PyThrowBadHr(impObj()->GetPromptForDwgName(&flag));
    return flag == VARIANT_TRUE;
}

void PySmSheetSetImpl::SetPromptForDwgName(bool flag)
{
    PyThrowBadHr(impObj()->SetPromptForDwgName(flag == true ? VARIANT_TRUE : VARIANT_FALSE));
}

PySmSheetSelSetsImpl PySmSheetSetImpl::GetSheetSelSets() const
{
    IAcSmSheetSelSets* ptr = nullptr;
    PyThrowBadHr(impObj()->GetSheetSelSets(&ptr));
    return PySmSheetSelSetsImpl(ptr);
}

PySmResourcesImpl PySmSheetSetImpl::GetResources() const
{
    IAcSmResources* ptr = nullptr;
    PyThrowBadHr(impObj()->GetResources(&ptr));
    return PySmResourcesImpl(ptr);
}

PySmCalloutBlocksImpl PySmSheetSetImpl::GetCalloutBlocks() const
{
    IAcSmCalloutBlocks* ptr = nullptr;
    PyThrowBadHr(impObj()->GetCalloutBlocks(&ptr));
    return PySmCalloutBlocksImpl(ptr);
}

PySmViewCategoriesImpl PySmSheetSetImpl::GetViewCategories() const
{
    IAcSmViewCategories* ptr = nullptr;
    PyThrowBadHr(impObj()->GetViewCategories(&ptr));
    return PySmViewCategoriesImpl(ptr);
}

PySmAcDbBlockRecordReferenceImpl PySmSheetSetImpl::GetDefLabelBlk() const
{
    IAcSmAcDbBlockRecordReference* ptr = nullptr;
    PyThrowBadHr(impObj()->GetDefLabelBlk(&ptr));
    return PySmAcDbBlockRecordReferenceImpl(ptr);
}

void PySmSheetSetImpl::SetDefLabelBlk(const PySmAcDbBlockRecordReferenceImpl& blk)
{
    PyThrowBadHr(impObj()->SetDefLabelBlk(blk.impObj()));
}

PySmPublishOptionsImpl PySmSheetSetImpl::GetPublishOptions() const
{
    IAcSmPublishOptions* ptr = nullptr;
    PyThrowBadHr(impObj()->GetPublishOptions(&ptr));
    return PySmPublishOptionsImpl(ptr);
}

void PySmSheetSetImpl::Sync(AcDbDatabase* pDb)
{
    IAcadDatabasePtr pAxDb = GetIAcadDatabaseFromAcDbDatabse(pDb);
    PyThrowBadHr(impObj()->Sync(pAxDb));
}

void PySmSheetSetImpl::UpdateSheetCustomProps()
{
    PyThrowBadHr(impObj()->UpdateSheetCustomProps());
}

IAcSmSheetSet* PySmSheetSetImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<IAcSmSheetSet*>(m_pimpl.GetInterfacePtr());
}

#if defined(_ARXTARGET)
IAcSmSheetSet2* PySmSheetSetImpl::impObj2(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl != nullptr)
    {
        IAcSmSheetSet2* pObj = nullptr;
        if (m_pimpl->QueryInterface(IID_IAcSmSheetSet2, (void**)&pObj) == S_OK && pObj) {
            return pObj;
        }
    }
    throw PyNullObject(src);
}
#endif

//-----------------------------------------------------------------------------------------
//PySmSheetImpl
PySmSheetImpl::PySmSheetImpl()
    : PySmComponentImpl(nullptr)
{
    PyThrowBadHr(m_pimpl.CreateInstance(CLSID_AcSmSheet));
}

PySmSheetImpl::PySmSheetImpl(IAcSmSheet* other)
    : PySmComponentImpl(other)
{
}

CString PySmSheetImpl::GetNumber() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->GetNumber(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PySmSheetImpl::SetNumber(const CString& csVal)
{
    _bstr_t bstrVal(csVal);
    PyThrowBadHr(impObj()->SetNumber(bstrVal));
}

CString PySmSheetImpl::GetTitle() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->GetTitle(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PySmSheetImpl::SetTitle(const CString& csVal)
{
    _bstr_t bstrVal(csVal);
    PyThrowBadHr(impObj()->SetTitle(bstrVal));
}

bool PySmSheetImpl::GetDoNotPlot() const
{
    VARIANT_BOOL rtVal;
    PyThrowBadHr(impObj()->GetDoNotPlot(&rtVal));
    return rtVal == VARIANT_TRUE;
}

void PySmSheetImpl::SetDoNotPlot(bool flag)
{
    PyThrowBadHr(impObj()->SetDoNotPlot(flag ? VARIANT_TRUE : VARIANT_FALSE));
}

CString PySmSheetImpl::GetRevisionNumber() const
{
#if defined(_BRXTARGET)
    throw PyNotimplementedByHost();
#elif defined(_ARXTARGET)
    _bstr_t bstrVal;
    PyThrowBadHr(impObj2()->GetRevisionNumber(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
#endif
}

void PySmSheetImpl::SetRevisionNumber(const CString& csVal)
{
#if defined(_BRXTARGET)
    throw PyNotimplementedByHost();
#elif defined(_ARXTARGET)
    _bstr_t bstrVal(csVal);
    PyThrowBadHr(impObj2()->SetRevisionNumber(bstrVal));
#endif
}

CString PySmSheetImpl::GetRevisionDate() const
{
#if defined(_BRXTARGET)
    throw PyNotimplementedByHost();
#elif defined(_ARXTARGET)
    _bstr_t bstrVal;
    PyThrowBadHr(impObj2()->GetRevisionDate(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
#endif
}

void PySmSheetImpl::SetRevisionDate(const CString& csVal)
{
#if defined(_BRXTARGET)
    throw PyNotimplementedByHost();
#elif defined(_ARXTARGET)
    _bstr_t bstrVal(csVal);
    PyThrowBadHr(impObj2()->SetRevisionDate(bstrVal));
#endif
}

CString PySmSheetImpl::GetIssuePurpose() const
{
#if defined(_BRXTARGET)
    throw PyNotimplementedByHost();
#elif defined(_ARXTARGET)
    _bstr_t bstrVal;
    PyThrowBadHr(impObj2()->GetIssuePurpose(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
#endif
}

void PySmSheetImpl::SetIssuePurpose(const CString& csVal)
{
#if defined(_BRXTARGET)
    throw PyNotimplementedByHost();
#elif defined(_ARXTARGET)
    _bstr_t bstrVal(csVal);
    PyThrowBadHr(impObj2()->SetIssuePurpose(bstrVal));
#endif
}

CString PySmSheetImpl::GetCategory() const
{
#if defined(_BRXTARGET)
    throw PyNotimplementedByHost();
#elif defined(_ARXTARGET)
    _bstr_t bstrVal;
    PyThrowBadHr(impObj2()->GetCategory(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
#endif
}

void PySmSheetImpl::SetCategory(const CString& csVal)
{
#if defined(_BRXTARGET)
    throw PyNotimplementedByHost();
#elif defined(_ARXTARGET)
    _bstr_t bstrVal(csVal);
    PyThrowBadHr(impObj2()->SetCategory(bstrVal));
#endif
}

IAcSmSheet* PySmSheetImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<IAcSmSheet*>(m_pimpl.GetInterfacePtr());
}

#if defined(_ARXTARGET)
IAcSmSheet2* PySmSheetImpl::impObj2(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl != nullptr)
    {
        IAcSmSheet2* pObj = nullptr;
        if (m_pimpl->QueryInterface(IID_IAcSmSheet2, (void**)&pObj) == S_OK && pObj) {
            return pObj;
        }
    }
    throw PyNullObject(src);
}
#endif

//-----------------------------------------------------------------------------------------
//PySmSmDatabase
PySmDatabaseImpl::PySmDatabaseImpl()
    : PySmComponentImpl(nullptr)
{
    PyThrowBadHr(m_pimpl.CreateInstance(CLSID_AcSmDatabase));
}

PySmDatabaseImpl::PySmDatabaseImpl(IAcSmDatabase* other)
    : PySmComponentImpl(other)
{
}

void PySmDatabaseImpl::LoadFromFile(const CString& filename)
{
    _bstr_t bstrFilename(filename);
    PyThrowBadHr(impObj()->SetName(bstrFilename));
}

CString PySmDatabaseImpl::GetFileName() const
{
    _bstr_t bstrFilename;
    PyThrowBadHr(impObj()->GetFileName(&bstrFilename.GetBSTR()));
    return (LPCTSTR)bstrFilename;
}

void PySmDatabaseImpl::SetFileName(const CString& filename)
{
    _bstr_t bstrFilename(filename);
    PyThrowBadHr(impObj()->SetFileName(bstrFilename));
}

CString PySmDatabaseImpl::GetTemplateDstFileName() const
{
    _bstr_t bstrFilename;
    PyThrowBadHr(impObj()->GetTemplateDstFileName(&bstrFilename.GetBSTR()));
    return (LPCTSTR)bstrFilename;
}

void PySmDatabaseImpl::LockDb()
{
    PyThrowBadHr(impObj()->LockDb(impObj()));
}

void PySmDatabaseImpl::UnlockDb(bool commit)
{
    auto b = commit ? VARIANT_TRUE : VARIANT_FALSE;
    PyThrowBadHr(impObj()->UnlockDb(impObj(), b));
}

PySmSheetSetImpl PySmDatabaseImpl::GetSheetSet() const
{
    IAcSmSheetSet* pSheet = nullptr;
    PyThrowBadHr(impObj()->GetSheetSet(&pSheet));
    return PySmSheetSetImpl(pSheet);
}

AcSmLockStatus PySmDatabaseImpl::GetLockStatus() const
{
    AcSmLockStatus st = AcSmLockStatus::AcSmLockStatus_UnLocked;
    PyThrowBadHr(impObj()->GetLockStatus(&st));
    return st;
}

std::pair<CString, CString> PySmDatabaseImpl::GetLockOwnerInfo() const
{
    _bstr_t bstrUserName;
    _bstr_t bstrMachineName;
    PyThrowBadHr(impObj()->GetLockOwnerInfo(&bstrUserName.GetBSTR(), &bstrMachineName.GetBSTR()));
    return std::make_pair(CString{ (LPCTSTR)bstrUserName }, CString{ (LPCTSTR)bstrMachineName });
}

std::vector<PySmPersistImpl> PySmDatabaseImpl::GetEnumerator() const
{
    std::vector<PySmPersistImpl> v;
    IAcSmEnumPersistPtr iter;
    PyThrowBadHr(impObj()->GetEnumerator(&iter));
    IAcSmPersist* pAx = nullptr;
    while (SUCCEEDED(iter->Next(&pAx)) && pAx != nullptr)
        v.push_back(PySmPersistImpl(pAx));
    return v;
}

IAcSmDatabase* PySmDatabaseImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<IAcSmDatabase*>(m_pimpl.GetInterfacePtr());
}

//-----------------------------------------------------------------------------------------
//PySmSheetSetMgr
PySmSheetSetMgrImpl::PySmSheetSetMgrImpl()
{
    if (m_pimpl == nullptr)
    {
        if (FAILED(m_pimpl.CreateInstance(CLSID_AcSmSheetSetMgr)))
            acutPrintf(_T("\nError Cannot get sheet set manager!!: "));
    }
}

PySmDatabaseImpl PySmSheetSetMgrImpl::CreateDatabase(const CString& filename)
{
    IAcSmDatabase* pDb = nullptr;
    _bstr_t bstrName(filename);
    PyThrowBadHr(impObj()->CreateDatabase(bstrName, NULL, TRUE, &pDb));
    return PySmDatabaseImpl(pDb);
}

PySmDatabaseImpl PySmSheetSetMgrImpl::CreateDatabase(const CString& filename, const CString& templatefilename, bool bAlwaysCreate)
{
    IAcSmDatabase* pDb = nullptr;
    _bstr_t bstrName(filename);
    _bstr_t bstrTemplate(templatefilename);
    BOOL flag = bAlwaysCreate ? TRUE : FALSE;
    PyThrowBadHr(impObj()->CreateDatabase(bstrName, bstrTemplate, bAlwaysCreate, &pDb));
    return PySmDatabaseImpl(pDb);
}

PySmDatabaseImpl PySmSheetSetMgrImpl::OpenDatabase(const CString& filename)
{
    IAcSmDatabase* pDb = nullptr;
    _bstr_t bstrName(filename);
    PyThrowBadHr(impObj()->OpenDatabase(bstrName, TRUE, &pDb));
    return PySmDatabaseImpl(pDb);
}

PySmDatabaseImpl PySmSheetSetMgrImpl::FindOpenDatabase(const CString& filename)
{
    IAcSmDatabase* pDb = nullptr;
    _bstr_t bstrName(filename);
    PyThrowBadHr(impObj()->FindOpenDatabase(bstrName, &pDb));
    return PySmDatabaseImpl(pDb);
}

void PySmSheetSetMgrImpl::CloseAll()
{
    PyThrowBadHr(impObj()->CloseAll());
}

void PySmSheetSetMgrImpl::Close(PySmDatabaseImpl& db)
{
    PyThrowBadHr(impObj()->Close(db.impObj()));
}

std::pair<PySmDatabaseImpl, PySmSheetSetImpl> PySmSheetSetMgrImpl::GetParentSheetSet(const CString& dwg, const CString& layout)
{
    IAcSmDatabase* pDb = nullptr;
    IAcSmSheetSet* pSheet = nullptr;
    _bstr_t bstrDwg(dwg);
    _bstr_t bstrLayout(layout);
    PyThrowBadHr(impObj()->GetParentSheetSet(bstrDwg, bstrLayout, &pSheet, &pDb));
    return std::pair(PySmDatabaseImpl(pDb), PySmSheetSetImpl(pSheet));
}

std::pair<PySmDatabaseImpl, PySmSheetImpl> PySmSheetSetMgrImpl::GetSheetFromLayout(AcDbObject* pAcDbLayout)
{
    if (pAcDbLayout == nullptr)
        throw PyNullObject();
    IAcSmDatabase* pAxDb = nullptr;
    IAcSmSheet* pSheet = nullptr;
    IAcadObjectPtr pAxLayout(GetIAcadObjectFromAcDbObject(pAcDbLayout));
    PyThrowBadHr(impObj()->GetSheetFromLayout(pAxLayout, &pSheet, &pAxDb));
    return std::pair(PySmDatabaseImpl(pAxDb), PySmSheetImpl(pSheet));
}

std::vector<PySmDatabaseImpl> PySmSheetSetMgrImpl::GetDatabaseEnumerator()
{
    std::vector<PySmDatabaseImpl> v;
    IAcSmEnumDatabasePtr iter;
    PyThrowBadHr(impObj()->GetDatabaseEnumerator(&iter));
    IAcSmDatabase* pAxDb = nullptr;
    while (SUCCEEDED(iter->Next(&pAxDb)) && pAxDb != nullptr)
        v.push_back(PySmDatabaseImpl(pAxDb));
    return v;
}

#ifdef PYRXDEBUG
static void printcomerr(HRESULT hr, std::string_view message)
{
    acutPrintf(utf8_to_wstr(std::format("\n{}, {}", std::system_category().message(hr), message)).c_str());
}
bool PySmSheetSetMgrImpl::runTest()
{
    IAcSmCustomPropertyValuePtr _cmpptr;
    {
        HRESULT hr = S_OK;
        
        hr = _cmpptr.CreateInstance(CLSID_AcSmCustomPropertyValue);
        printcomerr(hr, "_cmpptr.CreateInstance(CLSID_AcSmCustomPropertyValue)");

        IAcSmPersistPtr owner;
        hr = _cmpptr->GetOwner(&owner);
        printcomerr(hr, "_cmpptr->GetOwner");

        _bstr_t name;
        hr = _cmpptr->GetTypeName(&name.GetBSTR());
        printcomerr(hr, "_cmpptr->GetTypeName");
        acutPrintf(_T(" %ls"), (const wchar_t*)name);

        _variant_t v;
        hr = _cmpptr->GetValue(&v.GetVARIANT());
        printcomerr(hr, "_cmpptr->GetValue");

        VARIANT_BOOL rtVal;
        hr = _cmpptr->GetIsDirty(&rtVal);
        printcomerr(hr, "_cmpptr->GetIsDirty");
    }
    return true;
}
#endif PYRXDEBUG

IAcSmSheetSetMgr* PySmSheetSetMgrImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<IAcSmSheetSetMgr*>(m_pimpl.GetInterfacePtr());
}
#endif
