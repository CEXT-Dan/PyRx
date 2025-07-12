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
    if (AcAxGetIUnknownOfObject(&pUnk, eid, pAppDisp) == S_OK && pUnk)
    {
        IAcadObject* pObj = nullptr;
        if (pUnk->QueryInterface(IID_IAcadObject, (void**)&pObj) == S_OK && pObj)
            return pObj;
    }
    return nullptr;
}

static IAcadObject* GetIAcadObjectFromAcDbObject(AcDbObject* pSrcObject)
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

static IAcadDatabase* GetIAcadDatabaseFromAcDbDatabse(AcDbDatabase* pSrcObject)
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

//----------------------------------------------------------------------------------------
//PySmPersist
PySmPersistImpl::PySmPersistImpl(IAcSmPersist* other)
{
    if (other != nullptr)
        m_pimpl.Attach(other);
}

bool PySmPersistImpl::GetIsDirty() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->GetIsDirty(&rtVal));
    return rtVal != VARIANT_FALSE;
}

CString PySmPersistImpl::GetTypeName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->GetTypeName(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PySmPersistImpl::InitNew(const PySmPersistImpl& owner) const
{
    PyThrowBadHr(impObj()->InitNew(owner.impObj()));
}

PySmPersistImpl PySmPersistImpl::GetOwner() const
{
    IAcSmPersist* rtVal = nullptr;
    PyThrowBadHr(impObj()->GetOwner(&rtVal));
    return PySmPersistImpl(rtVal);
}

void PySmPersistImpl::SetOwner(const PySmPersistImpl& owner) const
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

void PySmPersistImpl::Clear() const
{
    PyThrowBadHr(impObj()->Clear());
}

bool PySmPersistImpl::IsNull() const
{
    return m_pimpl == nullptr;
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

IAcadDatabasePtr PySmAcDbDatabaseImpl::GetIAcadDatabase() const
{
    IAcadDatabase* axdb = nullptr;
    PyThrowBadHr(m_pimpl->GetIAcadDatabase(&axdb));
    return IAcadDatabasePtr{ axdb };
}

AcDbDatabase* PySmAcDbDatabaseImpl::GetAcDbDatabase() const
{
    LPVOID pDb;// eewww, LPVOID is prettier than void* though : |
    PyThrowBadHr(m_pimpl->GetAcDbDatabase(&pDb));
    return reinterpret_cast<AcDbDatabase*>(pDb);
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

bool PySmObjectIdImpl::IsEqual(const PySmObjectIdImpl& other) const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->IsEqual(other.impObj(), &rtVal));
    return rtVal != VARIANT_FALSE;
}

bool PySmObjectIdImpl::IsValid() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->IsValid(&rtVal));
    return rtVal != VARIANT_FALSE;
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

void PySmFileReferenceImpl::SetFileName(const CString& csVal) const
{
    _bstr_t bstrVal{ csVal };
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
    PyThrowBadHr(impObj()->ResolveFileName(&bstrVal.GetBSTR()));
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

void PySmAcDbObjectReferenceImpl::SetAcDbHandle(AcDbHandle& hwnd) const
{
    std::array<wchar_t, AcDbHandle::kStrSiz> buffer{ 0 };
    hwnd.getIntoAsciiBuffer(buffer.data(), buffer.size());
    _bstr_t bstrHwnd{ buffer.data() };
    PyThrowBadHr(impObj()->SetAcDbHandle(bstrHwnd));
}

AcDbHandle PySmAcDbObjectReferenceImpl::GetAcDbHandle() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->GetAcDbHandle(&bstrVal.GetBSTR()));
    return AcDbHandle{ bstrVal };
}

PySmAcDbDatabaseImpl PySmAcDbObjectReferenceImpl::GetAcSmAcDbDatabase() const
{
    IAcSmAcDbDatabase* ptr = nullptr;
    PyThrowBadHr(impObj()->GetAcSmAcDbDatabase(&ptr));
    return PySmAcDbDatabaseImpl(ptr);
}

void PySmAcDbObjectReferenceImpl::SetAcDbObject(AcDbObject* pDbObj) const
{
    IAcadObjectPtr pAxObj(GetIAcadObjectFromAcDbObject(pDbObj));
    PyThrowBadHr(impObj()->SetAcDbObject(pAxObj));
}

AcDbHandle PySmAcDbObjectReferenceImpl::ResolveAcDbObject(AcDbDatabase* pDb) const
{
    _bstr_t bstrVal;
    IAcadDatabasePtr axDb = GetIAcadDatabaseFromAcDbDatabse(pDb);
    PyThrowBadHr(impObj()->ResolveAcDbObject(axDb, &bstrVal.GetBSTR()));
    return AcDbHandle{ bstrVal };
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

void PySmNamedAcDbObjectReferenceImpl::SetName(const CString& name) const
{
    _bstr_t bstrVal{ name };
    PyThrowBadHr(impObj()->SetName(bstrVal));
}

CString PySmNamedAcDbObjectReferenceImpl::GetName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->GetName(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PySmNamedAcDbObjectReferenceImpl::SetOwnerAcDbHandle(const AcDbHandle& hwnd) const
{
    std::array<wchar_t, AcDbHandle::kStrSiz> buffer{ 0 };
    hwnd.getIntoAsciiBuffer(buffer.data(), buffer.size());
    _bstr_t bstrHwnd{ buffer.data() };
    PyThrowBadHr(impObj()->SetOwnerAcDbHandle(bstrHwnd));
}

AcDbHandle PySmNamedAcDbObjectReferenceImpl::GetOwnerAcDbHandle() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->GetOwnerAcDbHandle(&bstrVal.GetBSTR()));
    return AcDbHandle{ bstrVal };
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
#ifdef _ARXTARGET
    return AcValue(varVal);
#else
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
#endif // _ARXTARGET
}

void PySmCustomPropertyValueImpl::SetValue(const AcValue& acVal) const
{
    //TODO: TEST
    _variant_t varVal = {};
#ifdef _ARXTARGET
    acVal.get(varVal.GetVARIANT());
#else
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
#endif // _ARXTARGET
    PyThrowBadHr(impObj()->SetValue(varVal));
}

PropertyFlags PySmCustomPropertyValueImpl::GetFlags() const
{
    PropertyFlags flags;
    PyThrowBadHr(impObj()->GetFlags(&flags));
    return flags;
}

void PySmCustomPropertyValueImpl::SetFlags(PropertyFlags flags) const
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
    _bstr_t bstrName{ propName };
    IAcSmCustomPropertyValue* pProp = nullptr;
    PyThrowBadHr(impObj()->GetProperty(bstrName, &pProp));
    return PySmCustomPropertyValueImpl(pProp);
}

void PySmCustomPropertyBagImpl::SetProperty(const CString& propName, const PySmCustomPropertyValueImpl& prop) const
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

void PySmObjectReferenceImpl::SetReferencedObject(const PySmPersistImpl& pObject) const
{
    PyThrowBadHr(impObj()->SetReferencedObject(pObject.impObj()));
}

PySmPersistImpl PySmObjectReferenceImpl::GetReferencedObject() const
{
    IAcSmPersist* ptr = nullptr;
    PyThrowBadHr(impObj()->GetReferencedObject(&ptr));
    return PySmPersistImpl(ptr);
}

AcSmObjectReferenceFlags PySmObjectReferenceImpl::GetReferenceFlags() const
{
    AcSmObjectReferenceFlags flags = AcSmObjectReference_SoftPointer;
    PyThrowBadHr(impObj()->GetReferenceFlags(&flags));
    return flags;
}

void PySmObjectReferenceImpl::SetReferenceFlags(AcSmObjectReferenceFlags flags) const
{
    PyThrowBadHr(impObj()->SetReferenceFlags(flags));
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

CString PySmProjectPointLocationImpl::GetURL() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->GetURL(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PySmProjectPointLocationImpl::SetURL(const CString& csVal) const
{
    _bstr_t bstrVal{ csVal };
    PyThrowBadHr(impObj()->SetURL(bstrVal));
}

CString PySmProjectPointLocationImpl::GetFolder() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->GetFolder(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PySmProjectPointLocationImpl::SetFolder(const CString& csVal) const
{
    _bstr_t bstrVal{ csVal };
    PyThrowBadHr(impObj()->SetFolder(bstrVal));
}

CString PySmProjectPointLocationImpl::GetUsername() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->GetUsername(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PySmProjectPointLocationImpl::SetUsername(const CString& csVal) const
{
    _bstr_t bstrVal{ csVal };
    PyThrowBadHr(impObj()->SetUsername(bstrVal));
}

CString PySmProjectPointLocationImpl::GetPassword() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->GetPassword(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PySmProjectPointLocationImpl::SetPassword(const CString& csVal) const
{
    _bstr_t bstrVal{ csVal };
    PyThrowBadHr(impObj()->SetPassword(bstrVal));
}

long PySmProjectPointLocationImpl::GetResourceType() const
{
#if defined(_BRXTARGET240)
    throw PyNotimplementedByHost();
    return 0;
#else
    long val = 0;
    PyThrowBadHr(impObj2()->GetResourceType(&val));
    return val;
#endif
}

void PySmProjectPointLocationImpl::SetResourceType(long val) const
{
#if defined(_BRXTARGET240)
    throw PyNotimplementedByHost();
#else
    PyThrowBadHr(impObj2()->SetResourceType(val));
#endif
}

IAcSmProjectPointLocation* PySmProjectPointLocationImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcSmProjectPointLocation*>(m_pimpl.GetInterfacePtr());
}

#if !defined(_BRXTARGET240)
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

PySmFileReferenceImpl PySmPublishOptionsImpl::GetDefaultOutputdir() const
{
    IAcSmFileReference* ptr = nullptr;
    PyThrowBadHr(impObj()->GetDefaultOutputdir(&ptr));
    return PySmFileReferenceImpl(ptr);
}

void PySmPublishOptionsImpl::SetDefaultOutputdir(const PySmFileReferenceImpl& val) const
{
    PyThrowBadHr(impObj()->SetDefaultOutputdir(val.impObj()));
}

bool PySmPublishOptionsImpl::GetDwfType() const
{
    VARIANT_BOOL flag = VARIANT_FALSE;
    PyThrowBadHr(impObj()->GetDwfType(&flag));
    return flag == VARIANT_TRUE;
}

void PySmPublishOptionsImpl::SetDwfType(bool val) const
{
    PyThrowBadHr(impObj()->SetDwfType(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PySmPublishOptionsImpl::GetPromptForName() const
{
    VARIANT_BOOL flag = VARIANT_FALSE;
    PyThrowBadHr(impObj()->GetPromptForName(&flag));
    return flag == VARIANT_TRUE;
}

void PySmPublishOptionsImpl::SetPromptForName(bool val) const
{
    PyThrowBadHr(impObj()->SetPromptForName(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PySmPublishOptionsImpl::GetUsePassword() const
{
    VARIANT_BOOL flag = VARIANT_FALSE;
    PyThrowBadHr(impObj()->GetUsePassword(&flag));
    return flag == VARIANT_TRUE;
}

void PySmPublishOptionsImpl::SetUsePassword(bool val) const
{
    PyThrowBadHr(impObj()->SetUsePassword(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PySmPublishOptionsImpl::GetPromptForPassword() const
{
    VARIANT_BOOL flag = VARIANT_FALSE;
    PyThrowBadHr(impObj()->GetPromptForPassword(&flag));
    return flag == VARIANT_TRUE;
}

void PySmPublishOptionsImpl::SetPromptForPassword(bool val) const
{
    PyThrowBadHr(impObj()->SetPromptForPassword(val ? VARIANT_TRUE : VARIANT_FALSE));
}

bool PySmPublishOptionsImpl::GetLayerInfo() const
{
    VARIANT_BOOL flag = VARIANT_FALSE;
    PyThrowBadHr(impObj()->GetLayerInfo(&flag));
    return flag == VARIANT_TRUE;
}

void PySmPublishOptionsImpl::SetLayerInfo(bool val) const
{
    PyThrowBadHr(impObj()->SetLayerInfo(val ? VARIANT_TRUE : VARIANT_FALSE));
}

PySmCustomPropertyBagImpl PySmPublishOptionsImpl::GetUnrecognizedData() const
{
    IAcSmCustomPropertyBag* ptr = nullptr;
    PyThrowBadHr(impObj()->GetUnrecognizedData(&ptr));
    return PySmCustomPropertyBagImpl(ptr);
}

void PySmPublishOptionsImpl::SetUnrecognizedData(const PySmCustomPropertyBagImpl& val) const
{
    PyThrowBadHr(impObj()->SetUnrecognizedData(val.impObj()));
}

PySmCustomPropertyBagImpl PySmPublishOptionsImpl::GetUnrecognizedSections() const
{
    IAcSmCustomPropertyBag* ptr = nullptr;
    PyThrowBadHr(impObj()->GetUnrecognizedSections(&ptr));
    return PySmCustomPropertyBagImpl(ptr);
}

void PySmPublishOptionsImpl::SetUnrecognizedSections(const PySmCustomPropertyBagImpl& val) const
{
    PyThrowBadHr(impObj()->SetUnrecognizedSections(val.impObj()));
}

bool PySmPublishOptionsImpl::GetIncludeSheetSetData() const
{
#if defined(_BRXTARGET240)
    throw PyNotimplementedByHost();
#else
    VARIANT_BOOL flag = VARIANT_FALSE;
    PyThrowBadHr(impObj2()->GetIncludeSheetSetData(&flag));
    return flag == VARIANT_TRUE;
#endif
}

void PySmPublishOptionsImpl::SetIncludeSheetSetData(bool val) const
{
#if defined(_BRXTARGET240)
    throw PyNotimplementedByHost();
#else
    PyThrowBadHr(impObj2()->SetIncludeSheetSetData(val ? VARIANT_TRUE : VARIANT_FALSE));
#endif
}

bool PySmPublishOptionsImpl::GetIncludeSheetData() const
{
#if defined(_BRXTARGET240)
    throw PyNotimplementedByHost();
#else
    VARIANT_BOOL flag = VARIANT_FALSE;
    PyThrowBadHr(impObj2()->GetIncludeSheetData(&flag));
    return flag == VARIANT_TRUE;
#endif
}

void PySmPublishOptionsImpl::SetIncludeSheetData(bool val) const
{
#if defined(_BRXTARGET240)
    throw PyNotimplementedByHost();
#else
    PyThrowBadHr(impObj2()->SetIncludeSheetData(val ? VARIANT_TRUE : VARIANT_FALSE));
#endif
}

long PySmPublishOptionsImpl::GetEplotFormat() const
{
#if defined(_BRXTARGET)
    throw PyNotimplementedByHost();
#else
    long val = 0;
    PyThrowBadHr(impObj3()->GetEplotFormat(&val));
    return val;
#endif
}

void PySmPublishOptionsImpl::SetEplotFormat(long val) const
{
#if defined(_BRXTARGET)
    throw PyNotimplementedByHost();
#else
    PyThrowBadHr(impObj3()->SetEplotFormat(val));
#endif
}

bool PySmPublishOptionsImpl::GetLinesMerge() const
{
#if defined(_BRXTARGET)
    throw PyNotimplementedByHost();
#else
    VARIANT_BOOL flag = VARIANT_FALSE;
    PyThrowBadHr(impObj4()->GetLinesMerge(&flag));
    return flag == VARIANT_TRUE;
#endif
}

void PySmPublishOptionsImpl::SetLinesMerge(bool val) const
{
#if defined(_BRXTARGET)
    throw PyNotimplementedByHost();
#else
    PyThrowBadHr(impObj4()->SetLinesMerge(val ? VARIANT_TRUE : VARIANT_FALSE));
#endif
}

CString PySmPublishOptionsImpl::GetDefaultFilename() const
{
#if defined(_BRXTARGET)
    throw PyNotimplementedByHost();
#else
    _bstr_t bstrVal;
    PyThrowBadHr(impObj4()->GetDefaultFilename(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
#endif
}

void PySmPublishOptionsImpl::SetDefaultFilename(const CString& csVal) const
{
#if defined(_BRXTARGET)
    throw PyNotimplementedByHost();
#else
    _bstr_t bstrVal{ csVal };
    PyThrowBadHr(impObj4()->SetDefaultFilename(bstrVal));
#endif
}

IAcSmPublishOptions* PySmPublishOptionsImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcSmPublishOptions*>(m_pimpl.GetInterfacePtr());
}

#if !defined(_BRXTARGET240)
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
#if !defined(_BRXTARGET260)
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
#if !defined(_BRXTARGET260)
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

void PySmComponentImpl::SetName(const CString& csName) const
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

void PySmComponentImpl::SetDesc(const CString& csDesc) const
{
    _bstr_t bstrDesc{ csDesc };
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

void PySmSheetSelSetImpl::Add(const PySmComponentImpl& val) const
{
    PyThrowBadHr(impObj()->Add(val.impObj()));
}

void PySmSheetSelSetImpl::Remove(const PySmComponentImpl& val) const
{
    PyThrowBadHr(impObj()->Remove(val.impObj()));
}

PySmComponentArray PySmSheetSelSetImpl::GetComponents() const
{
    PySmComponentArray v;
    IAcSmEnumComponentPtr iter;
    PyThrowBadHr(impObj()->GetEnumerator(&iter));
    IAcSmComponent* pAx = nullptr;
    while (SUCCEEDED(iter->Next(&pAx)) && pAx != nullptr)
        v.push_back(PySmComponentImpl(pAx));
    return v;
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

PySmSheetSelSetImpl PySmSheetSelSetsImpl::Add(const CString& name, const CString& desc) const
{
    _bstr_t bstrName{ name };
    _bstr_t bstrDeck{ desc };
    IAcSmSheetSelSet* ptr = nullptr;
    PyThrowBadHr(impObj()->Add(bstrName, bstrDeck, &ptr));
    return PySmSheetSelSetImpl(ptr);
}

void PySmSheetSelSetsImpl::Remove(const PySmSheetSelSetImpl& ss) const
{
    PyThrowBadHr(impObj()->Remove(ss.impObj()));
}

PySmSheetSelSetArray PySmSheetSelSetsImpl::GetSheetSelSets() const
{
    PySmSheetSelSetArray v;
    IAcSmEnumSheetSelSetPtr iter;
    PyThrowBadHr(impObj()->GetEnumerator(&iter));
    IAcSmSheetSelSet* pAx = nullptr;
    while (SUCCEEDED(iter->Next(&pAx)) && pAx != nullptr)
        v.push_back(PySmSheetSelSetImpl(pAx));
    return v;
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

void PySmResourcesImpl::Add(const PySmFileReferenceImpl& val) const
{
    PyThrowBadHr(impObj()->Add(val.impObj()));
}

void PySmResourcesImpl::Remove(const PySmFileReferenceImpl& val) const
{
    PyThrowBadHr(impObj()->Remove(val.impObj()));
}

PySmFileReferenceArray PySmResourcesImpl::GetFileReferences() const
{
    PySmFileReferenceArray v;
    IAcSmEnumFileReferencePtr iter;
    PyThrowBadHr(impObj()->GetEnumerator(&iter));
    IAcSmFileReference* pAx = nullptr;
    while (SUCCEEDED(iter->Next(&pAx)) && pAx != nullptr)
        v.push_back(PySmFileReferenceImpl(pAx));
    return v;
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

PySmSheetViewArray PySmViewCategoryImpl::GetSheetViews() const
{
    PySmSheetViewArray v;
    IAcSmEnumSheetViewPtr iter;
    PyThrowBadHr(impObj()->GetSheetViewEnumerator(&iter));
    IAcSmSheetView* pAx = nullptr;
    while (SUCCEEDED(iter->Next(&pAx)) && pAx != nullptr)
        v.push_back(PySmSheetViewImpl(pAx));
    return v;
}

PySmCalloutBlocksImpl PySmViewCategoryImpl::GetCalloutBlocks() const
{
    IAcSmCalloutBlocks* ptr = nullptr;
    PyThrowBadHr(impObj()->GetCalloutBlocks(&ptr));
    return PySmCalloutBlocksImpl(ptr);
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

PySmViewCategoryArray PySmViewCategoriesImpl::GetPySmViewCategorys() const
{
    PySmViewCategoryArray v;
    IAcSmEnumViewCategoryPtr iter;
    PyThrowBadHr(impObj()->GetEnumerator(&iter));
    IAcSmViewCategory* pAx = nullptr;
    while (SUCCEEDED(iter->Next(&pAx)) && pAx != nullptr)
        v.push_back(PySmViewCategoryImpl(pAx));
    return v;
}

PySmViewCategoryImpl PySmViewCategoriesImpl::CreateViewCategory(const CString& csName, const CString& csDesc, const CString& csId) const
{
    _bstr_t bstrName{ csName };
    _bstr_t bstrDesc{ csDesc };
    _bstr_t bstrId{ csId };
    IAcSmViewCategory* ptr = nullptr;
    PyThrowBadHr(impObj()->CreateViewCategory(bstrName, bstrDesc, bstrId, &ptr));
    return PySmViewCategoryImpl(ptr);
}

void PySmViewCategoriesImpl::RemoveViewCategory(const PySmViewCategoryImpl& cat) const
{
    PyThrowBadHr(impObj()->RemoveViewCategory(cat.impObj()));
}

PySmViewCategoryImpl PySmViewCategoriesImpl::GetDefaultViewCategory() const
{
    IAcSmViewCategory* ptr = nullptr;
    PyThrowBadHr(impObj()->GetDefaultViewCategory(&ptr));
    return PySmViewCategoryImpl(ptr);
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

PySmAcDbViewReferenceImpl PySmSheetViewImpl::GetNamedView() const
{
    IAcSmAcDbViewReference* ptr = nullptr;
    PyThrowBadHr(impObj()->GetNamedView(&ptr));
    return PySmAcDbViewReferenceImpl(ptr);
}

void PySmSheetViewImpl::SetNamedView(const PySmAcDbViewReferenceImpl& view) const
{
    PyThrowBadHr(impObj()->SetNamedView(view.impObj()));
}

PySmViewCategoryImpl PySmSheetViewImpl::GetCategory() const
{
    IAcSmViewCategory* ptr = nullptr;
    PyThrowBadHr(impObj()->GetCategory(&ptr));
    return PySmViewCategoryImpl(ptr);
}

void PySmSheetViewImpl::SetCategory(const PySmViewCategoryImpl& view) const
{
    PyThrowBadHr(impObj()->SetCategory(view.impObj()));
}

CString PySmSheetViewImpl::GetNumber() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->GetNumber(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PySmSheetViewImpl::SetNumber(const CString& csVal) const
{
    _bstr_t bstrVal{ csVal };
    PyThrowBadHr(impObj()->SetNumber(bstrVal));
}

CString PySmSheetViewImpl::GetTitle() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->GetTitle(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PySmSheetViewImpl::SetTitle(const CString& csVal) const
{
    _bstr_t bstrVal{ csVal };
    PyThrowBadHr(impObj()->SetTitle(bstrVal));
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

PySmSheetViewArray PySmSheetViewsImpl::GetSheetViews() const
{
    PySmSheetViewArray v;
    IAcSmEnumSheetViewPtr iter;
    PyThrowBadHr(impObj()->GetEnumerator(&iter));
    IAcSmSheetView* pAx = nullptr;
    while (SUCCEEDED(iter->Next(&pAx)) && pAx != nullptr)
        v.push_back(PySmSheetViewImpl(pAx));
    return v;
}

void PySmSheetViewsImpl::Sync(const PySmAcDbLayoutReferenceImpl& lref, AcDbDatabase* pDb) const
{
    IAcadDatabasePtr pAxDb = GetIAcadDatabaseFromAcDbDatabse(pDb);
    PyThrowBadHr(impObj()->Sync(lref.impObj(), pAxDb));
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

PySmProjectPointLocationImpl PySmProjectPointLocationsImpl::GetLocation(const CString& locationName) const
{
    _bstr_t bstrVal{ locationName };
    IAcSmProjectPointLocation* ptr = nullptr;
    PyThrowBadHr(impObj()->GetLocation(bstrVal, &ptr));
    return PySmProjectPointLocationImpl(ptr);
}

void PySmProjectPointLocationsImpl::RemoveLocation(const PySmProjectPointLocationImpl& val) const
{
    PyThrowBadHr(impObj()->RemoveLocation(val.impObj()));
}

PySmProjectPointLocationImpl PySmProjectPointLocationsImpl::AddNewLocation(const CString& name, const CString& url, const CString& folder, const CString& username, const CString& password) const
{
    _bstr_t bstrname{ name };
    _bstr_t bstrurl{ url };
    _bstr_t bstrfolder{ folder };
    _bstr_t bstrusername{ username };
    _bstr_t bstrpassword{ password };
    IAcSmProjectPointLocation* ptr = nullptr;
    PyThrowBadHr(impObj()->AddNewLocation(bstrname, bstrurl, bstrfolder, bstrusername, bstrpassword, &ptr));
    return PySmProjectPointLocationImpl(ptr);
}

PySmProjectPointLocationArray PySmProjectPointLocationsImpl::GetProjectPointLocations() const
{
    PySmProjectPointLocationArray v;
    IAcSmEnumProjectPointLocationPtr iter;
    PyThrowBadHr(impObj()->GetEnumerator(&iter));
    IAcSmProjectPointLocation* pAx = nullptr;
    while (SUCCEEDED(iter->Next(&pAx)) && pAx != nullptr)
        v.push_back(PySmProjectPointLocationImpl(pAx));
    return v;
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

void PySmCalloutBlocksImpl::Add(const PySmAcDbBlockRecordReferenceImpl& blkRef) const
{
    PyThrowBadHr(impObj()->Add(blkRef.impObj()));
}

void PySmCalloutBlocksImpl::Remove(const PySmAcDbBlockRecordReferenceImpl& blkRef) const
{
    PyThrowBadHr(impObj()->Remove(blkRef.impObj()));
}

PySmAcDbBlockRecordReferenceArray PySmCalloutBlocksImpl::getAcDbBlockRecordReferences() const
{
    PySmAcDbBlockRecordReferenceArray v;
    IAcSmEnumAcDbBlockRecordReferencePtr iter;
    PyThrowBadHr(impObj()->GetEnumerator(&iter));
    IAcSmAcDbBlockRecordReference* pAx = nullptr;
    while (SUCCEEDED(iter->Next(&pAx)) && pAx != nullptr)
        v.push_back(PySmAcDbBlockRecordReferenceImpl(pAx));
    return v;
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

PySmFileReferenceImpl PySmSubsetImpl::GetNewSheetLocation() const
{
    IAcSmFileReference* ptr = nullptr;
    PyThrowBadHr(impObj()->GetNewSheetLocation(&ptr));
    return PySmFileReferenceImpl(ptr);
}

void PySmSubsetImpl::SetNewSheetLocation(const PySmFileReferenceImpl& fref) const
{
    PyThrowBadHr(impObj()->SetNewSheetLocation(fref.impObj()));
}

PySmAcDbLayoutReferenceImpl PySmSubsetImpl::GetDefDwtLayout() const
{
    IAcSmAcDbLayoutReference* ptr = nullptr;
    PyThrowBadHr(impObj()->GetDefDwtLayout(&ptr));
    return PySmAcDbLayoutReferenceImpl(ptr);
}

void PySmSubsetImpl::SetDefDwtLayout(const PySmAcDbLayoutReferenceImpl& fref) const
{
    PyThrowBadHr(impObj()->SetDefDwtLayout(fref.impObj()));
}

bool PySmSubsetImpl::GetPromptForDwt() const
{
    VARIANT_BOOL flag = VARIANT_FALSE;
    PyThrowBadHr(impObj()->GetPromptForDwt(&flag));
    return flag == VARIANT_TRUE;
}

void PySmSubsetImpl::SetPromptForDwt(bool val) const
{
    PyThrowBadHr(impObj()->SetPromptForDwt(val ? VARIANT_TRUE : VARIANT_FALSE));
}

PySmSheetArray PySmSubsetImpl::GetSheets() const
{
    PySmSheetArray v;
    IAcSmEnumComponentPtr iter;
    PyThrowBadHr(impObj()->GetSheetEnumerator(&iter));
    IAcSmComponent* pAx = nullptr;
    while (SUCCEEDED(iter->Next(&pAx)) && pAx != nullptr)
        v.push_back(PySmSheetImpl(static_cast<IAcSmSheet*>(pAx)));
    return v;
}

PySmSheetImpl PySmSubsetImpl::AddNewSheet(const CString& name, const CString& desc) const
{
    IAcSmSheet* ptr = nullptr;
    _bstr_t bstrname{ name };
    _bstr_t bstrdesc{ desc };
    PyThrowBadHr(impObj()->AddNewSheet(bstrname, bstrdesc, &ptr));
    return PySmSheetImpl(ptr);
}

void PySmSubsetImpl::InsertComponentFirst(const PySmComponentImpl& newSheet) const
{
    PyThrowBadHr(impObj()->InsertComponent(newSheet.impObj(), nullptr));//ok
}

void PySmSubsetImpl::InsertComponent(const PySmComponentImpl& newSheet, const  PySmComponentImpl& beforeComp) const
{
    PyThrowBadHr(impObj()->InsertComponent(newSheet.impObj(), beforeComp.impObj()));
}

void PySmSubsetImpl::InsertComponentAfter(const PySmComponentImpl& newSheet, const PySmComponentImpl& afterComp) const
{
    PyThrowBadHr(impObj()->InsertComponentAfter(newSheet.impObj(), afterComp.impObj()));
}

PySmSheetImpl PySmSubsetImpl::ImportSheet(const PySmAcDbLayoutReferenceImpl& fref) const
{
    IAcSmSheet* ptr = nullptr;
    PyThrowBadHr(impObj()->ImportSheet(fref.impObj(), &ptr));
    return PySmSheetImpl(ptr);
}

void PySmSubsetImpl::RemoveSheet(const PySmSheetImpl& val) const
{
    PyThrowBadHr(impObj()->RemoveSheet(val.impObj()));
}

PySmSubsetImpl PySmSubsetImpl::CreateSubset(const CString& name, const CString& desc) const
{
    IAcSmSubset* ptr = nullptr;
    _bstr_t bstrname{ name };
    _bstr_t bstrdesc{ desc };
    PyThrowBadHr(impObj()->CreateSubset(bstrname, bstrdesc, &ptr));
    return PySmSubsetImpl(ptr);
}

void PySmSubsetImpl::RemoveSubset(const PySmSubsetImpl& val) const
{
    PyThrowBadHr(impObj()->RemoveSubset(val.impObj()));
}

void PySmSubsetImpl::UpdateInMemoryDwgHints() const
{
    PyThrowBadHr(impObj()->UpdateInMemoryDwgHints());
}

bool PySmSubsetImpl::GetOverrideSheetPublish() const
{
#if defined(_BRXTARGET240)
    throw PyNotimplementedByHost();
#else
    VARIANT_BOOL flag = VARIANT_FALSE;
    PyThrowBadHr(impObj2()->GetOverrideSheetPublish(&flag));
    return flag == VARIANT_TRUE;
#endif
}

void PySmSubsetImpl::SetOverrideSheetPublish(bool val) const
{
#if defined(_BRXTARGET240)
    throw PyNotimplementedByHost();
#else
    PyThrowBadHr(impObj2()->SetOverrideSheetPublish(val ? VARIANT_TRUE : VARIANT_FALSE));
#endif
}

IAcSmSubset* PySmSubsetImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcSmSubset*>(m_pimpl.GetInterfacePtr());
}

#if !defined(_BRXTARGET240)
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

void PySmSheetSetImpl::SetAltPageSetups(const PySmFileReferenceImpl& alt) const
{
    PyThrowBadHr(impObj()->SetAltPageSetups(alt.impObj()));
}

PySmNamedAcDbObjectReferenceImpl PySmSheetSetImpl::GetDefAltPageSetup() const
{
    IAcSmNamedAcDbObjectReference* ptr = nullptr;
    PyThrowBadHr(impObj()->GetDefAltPageSetup(&ptr));
    return PySmNamedAcDbObjectReferenceImpl(ptr);
}

void PySmSheetSetImpl::SetDefAltPageSetup(const PySmNamedAcDbObjectReferenceImpl& alt) const
{
    PyThrowBadHr(impObj()->SetAltPageSetups(alt.impObj()));
}

bool PySmSheetSetImpl::GetPromptForDwgName() const
{
    VARIANT_BOOL flag = VARIANT_FALSE;
    PyThrowBadHr(impObj()->GetPromptForDwgName(&flag));
    return flag == VARIANT_TRUE;
}

void PySmSheetSetImpl::SetPromptForDwgName(bool flag) const
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

void PySmSheetSetImpl::SetDefLabelBlk(const PySmAcDbBlockRecordReferenceImpl& blk) const
{
    PyThrowBadHr(impObj()->SetDefLabelBlk(blk.impObj()));
}

PySmPublishOptionsImpl PySmSheetSetImpl::GetPublishOptions() const
{
    IAcSmPublishOptions* ptr = nullptr;
    PyThrowBadHr(impObj()->GetPublishOptions(&ptr));
    return PySmPublishOptionsImpl(ptr);
}

void PySmSheetSetImpl::Sync(AcDbDatabase* pDb) const
{
    IAcadDatabasePtr pAxDb = GetIAcadDatabaseFromAcDbDatabse(pDb);
    PyThrowBadHr(impObj()->Sync(pAxDb));
}

void PySmSheetSetImpl::UpdateSheetCustomProps() const
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

#if !defined(_BRXTARGET260)
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

void PySmSheetImpl::SetNumber(const CString& csVal) const
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

void PySmSheetImpl::SetTitle(const CString& csVal) const
{
    _bstr_t bstrVal(csVal);
    PyThrowBadHr(impObj()->SetTitle(bstrVal));
}

bool PySmSheetImpl::GetDoNotPlot() const
{
    VARIANT_BOOL rtVal = VARIANT_FALSE;
    PyThrowBadHr(impObj()->GetDoNotPlot(&rtVal));
    return rtVal != VARIANT_FALSE;
}

void PySmSheetImpl::SetDoNotPlot(bool flag) const
{
    PyThrowBadHr(impObj()->SetDoNotPlot(flag ? VARIANT_TRUE : VARIANT_FALSE));
}

PySmAcDbLayoutReferenceImpl PySmSheetImpl::GetLayout() const
{
    IAcSmAcDbLayoutReference* ptr = nullptr;
    PyThrowBadHr(impObj()->GetLayout(&ptr));
    return PySmAcDbLayoutReferenceImpl(ptr);
}

void PySmSheetImpl::SetLayout(const PySmAcDbLayoutReferenceImpl& val) const
{
    PyThrowBadHr(impObj()->SetLayout(val.impObj()));
}

PySmSheetViewsImpl PySmSheetImpl::GetSheetViews() const
{
    IAcSmSheetViews* ptr = nullptr;
    PyThrowBadHr(impObj()->GetSheetViews(&ptr));
    return PySmSheetViewsImpl(ptr);
}

CString PySmSheetImpl::GetRevisionNumber() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    _bstr_t bstrVal;
    PyThrowBadHr(impObj2()->GetRevisionNumber(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
#endif
}

void PySmSheetImpl::SetRevisionNumber(const CString& csVal) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    _bstr_t bstrVal(csVal);
    PyThrowBadHr(impObj2()->SetRevisionNumber(bstrVal));
#endif
}

CString PySmSheetImpl::GetRevisionDate() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    _bstr_t bstrVal;
    PyThrowBadHr(impObj2()->GetRevisionDate(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
#endif
}

void PySmSheetImpl::SetRevisionDate(const CString& csVal) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    _bstr_t bstrVal(csVal);
    PyThrowBadHr(impObj2()->SetRevisionDate(bstrVal));
#endif
}

CString PySmSheetImpl::GetIssuePurpose() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    _bstr_t bstrVal;
    PyThrowBadHr(impObj2()->GetIssuePurpose(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
#endif
}

void PySmSheetImpl::SetIssuePurpose(const CString& csVal) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    _bstr_t bstrVal(csVal);
    PyThrowBadHr(impObj2()->SetIssuePurpose(bstrVal));
#endif
}

CString PySmSheetImpl::GetCategory() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    _bstr_t bstrVal;
    PyThrowBadHr(impObj2()->GetCategory(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
#endif
}

void PySmSheetImpl::SetCategory(const CString& csVal) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
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

#if !defined(_BRXTARGET250)
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

void PySmDatabaseImpl::LoadFromFile(const CString& filename) const
{
    _bstr_t bstrFilename(filename);
    PyThrowBadHr(impObj()->LoadFromFile(bstrFilename));
}

CString PySmDatabaseImpl::GetFileName() const
{
    _bstr_t bstrFilename;
    PyThrowBadHr(impObj()->GetFileName(&bstrFilename.GetBSTR()));
    return (LPCTSTR)bstrFilename;
}

void PySmDatabaseImpl::SetFileName(const CString& filename) const
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

void PySmDatabaseImpl::LockDb() const
{
    PyThrowBadHr(impObj()->LockDb(impObj()));
}

void PySmDatabaseImpl::UnlockDb(bool commit) const
{
    PyThrowBadHr(impObj()->UnlockDb(impObj(), commit ? VARIANT_TRUE : VARIANT_FALSE));
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

void PySmSheetSetMgrImpl::CloseAll() const
{
    PyThrowBadHr(impObj()->CloseAll());
}

void PySmSheetSetMgrImpl::Close(const PySmDatabaseImpl& db) const
{
    PyThrowBadHr(impObj()->Close(db.impObj()));
}

std::pair<PySmDatabaseImpl, PySmSheetSetImpl> PySmSheetSetMgrImpl::GetParentSheetSet(const CString& dwg, const CString& layout) const
{
    IAcSmDatabase* pDb = nullptr;
    IAcSmSheetSet* pSheet = nullptr;
    _bstr_t bstrDwg{ dwg };
    _bstr_t bstrLayout{ layout };
    PyThrowBadHr(impObj()->GetParentSheetSet(bstrDwg, bstrLayout, &pSheet, &pDb));
    return std::pair(PySmDatabaseImpl(pDb), PySmSheetSetImpl(pSheet));
}

std::pair<PySmDatabaseImpl, PySmSheetImpl> PySmSheetSetMgrImpl::GetSheetFromLayout(AcDbObject* pAcDbLayout) const
{
    if (pAcDbLayout == nullptr)
        throw PyNullObject();
    IAcSmDatabase* pAxDb = nullptr;
    IAcSmSheet* pSheet = nullptr;
    IAcadObjectPtr pAxLayout(GetIAcadObjectFromAcDbObject(pAcDbLayout));
    PyThrowBadHr(impObj()->GetSheetFromLayout(pAxLayout, &pSheet, &pAxDb));
    return std::pair(PySmDatabaseImpl(pAxDb), PySmSheetImpl(pSheet));
}

std::vector<PySmDatabaseImpl> PySmSheetSetMgrImpl::GetDatabaseEnumerator() const
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
bool PySmSheetSetMgrImpl::runTest()
{
    IAcSmSheetSetMgrPtr ssMgr;
    if (FAILED(ssMgr.CreateInstance(CLSID_AcSmSheetSetMgr)))
        acutPrintf(_T("\nError Cannot get sheet set manager!!: "));

    IAcSmEnumDatabasePtr iter;
    ssMgr->GetDatabaseEnumerator(&iter);

    int cnt = 0;
    IAcSmDatabasePtr pAxDb = nullptr;
    while (SUCCEEDED(iter->Next(&pAxDb)) && pAxDb != nullptr)
    {
        IAcSmEnumPersistPtr iter;
        pAxDb->GetEnumerator(&iter);

        IAcSmPersistPtr pAx = nullptr;
        while (SUCCEEDED(iter->Next(&pAx)) && pAx != nullptr)
        {
            _bstr_t typeName;
            pAx->GetTypeName(&typeName.GetBSTR());
            acutPrintf(_T("\nTypeName = %ls"), (const TCHAR*)typeName);
        }
    }
    return true;
}
#endif

IAcSmSheetSetMgr* PySmSheetSetMgrImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcSmSheetSetMgr*>(m_pimpl.GetInterfacePtr());
}
#endif
