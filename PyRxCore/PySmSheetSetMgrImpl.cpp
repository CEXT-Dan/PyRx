#include "stdafx.h"
#include "PySmSheetSetMgrImpl.h"

#if defined(_ARXTARGET) || defined(_BRXTARGET) 

#if defined(_ARXTARGET)
#include "axboiler.h"
#endif

#if defined(_BRXTARGET)//TODO: link error
extern HRESULT AcAxGetIUnknownOfObject(LPUNKNOWN*, AcDbObjectId&, LPDISPATCH);
extern HRESULT AcAxGetIUnknownOfObject(LPUNKNOWN*, AcDbObject*, LPDISPATCH);
#endif

static IAcadObject* GetIAcadObjectFromAcDbObjectId(AcDbObjectId& eid)
{
    IUnknown* pUnk = nullptr;
    LPDISPATCH disp = acedGetIDispatch(false);
    if (AcAxGetIUnknownOfObject(&pUnk, eid, disp) == S_OK && pUnk) {
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
    LPDISPATCH disp = acedGetIDispatch(false);
    if (AcAxGetIUnknownOfObject(&pUnk, pSrcObject, disp) == S_OK && pUnk) {
        IAcadObject* pObj = nullptr;
        if (pUnk->QueryInterface(IID_IAcadObject, (void**)&pObj) == S_OK && pObj) {
            return pObj;
        }
    }
    return nullptr;
}


//----------------------------------------------------------------------------------------
//PySmPersist
PySmPersistImpl::PySmPersistImpl(IAcSmPersist* other)
{
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

PySmSmDatabaseImpl PySmPersistImpl::GetDatabase() const
{
    IAcSmDatabase* rtVal = nullptr;
    PyThrowBadHr(impObj()->GetDatabase(&rtVal));
    return PySmSmDatabaseImpl(rtVal);
}

PySmObjectIdImpl PySmPersistImpl::GetObjectId() const
{
    IAcSmObjectId* rtVal = nullptr;
    PyThrowBadHr(impObj()->GetObjectId(&rtVal));
    return PySmObjectIdImpl(rtVal);
}

IAcSmPersist* PySmPersistImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<IAcSmPersist*>(m_pimpl.GetInterfacePtr());
}

//-----------------------------------------------------------------------------------------
//IAcSmObjectId
PySmObjectIdImpl::PySmObjectIdImpl(IAcSmObjectId* other)
{
    m_pimpl.Attach(other);
}

CString PySmObjectIdImpl::GetHandle() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->GetHandle(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

PySmSmDatabaseImpl PySmObjectIdImpl::GetDatabase() const
{
    IAcSmDatabase* pVal = nullptr;
    PyThrowBadHr(impObj()->GetDatabase(&pVal));
    return PySmSmDatabaseImpl(pVal);
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

IAcSmComponent* PySmComponentImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<IAcSmComponent*>(m_pimpl.GetInterfacePtr());
}

//-----------------------------------------------------------------------------------------
//PySmSubset
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

//-----------------------------------------------------------------------------------------
//PySmSheetSet
PySmSheetSetImpl::PySmSheetSetImpl(IAcSmSheetSet* other)
    : PySmSubsetImpl(other)
{
}

IAcSmSheetSet* PySmSheetSetImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<IAcSmSheetSet*>(m_pimpl.GetInterfacePtr());
}

//-----------------------------------------------------------------------------------------
//PySmSheetImpl
PySmSheetImpl::PySmSheetImpl(IAcSmSheet* other)
    : PySmComponentImpl(other)
{
}

IAcSmSheet* PySmSheetImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<IAcSmSheet*>(m_pimpl.GetInterfacePtr());
}

//-----------------------------------------------------------------------------------------
//PySmSmDatabase
PySmSmDatabaseImpl::PySmSmDatabaseImpl(IAcSmDatabase* other)
    : PySmComponentImpl(other)
{
}

void PySmSmDatabaseImpl::LockDb()
{
    PyThrowBadHr(impObj()->LockDb(impObj()));
}

void PySmSmDatabaseImpl::UnlockDb(bool commit)
{
    auto b = commit ? VARIANT_TRUE : VARIANT_FALSE;
    PyThrowBadHr(impObj()->UnlockDb(impObj(), b));
}

PySmSheetSetImpl PySmSmDatabaseImpl::GetSheetSet()
{
    IAcSmSheetSet* pSheet = nullptr;
    PyThrowBadHr(impObj()->GetSheetSet(&pSheet));
    return PySmSheetSetImpl(pSheet);
}

IAcSmDatabase* PySmSmDatabaseImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
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
            acutPrintf(_T("\n Error Cannot get sheet set manager!!"));
    }
}

PySmSmDatabaseImpl PySmSheetSetMgrImpl::CreateDatabase(const CString& filename)
{
    IAcSmDatabase* pDb = nullptr;
    _bstr_t bstrName(filename);
    PyThrowBadHr(impObj()->CreateDatabase(bstrName, NULL, TRUE, &pDb));
    return PySmSmDatabaseImpl(pDb);
}

PySmSmDatabaseImpl PySmSheetSetMgrImpl::CreateDatabase(const CString& filename, const CString& templatefilename, bool bAlwaysCreate)
{
    IAcSmDatabase* pDb = nullptr;
    _bstr_t bstrName(filename);
    _bstr_t bstrTemplate(templatefilename);
    BOOL flag = bAlwaysCreate ? TRUE : FALSE;
    PyThrowBadHr(impObj()->CreateDatabase(bstrName, bstrTemplate, bAlwaysCreate, &pDb));
    return PySmSmDatabaseImpl(pDb);
}

PySmSmDatabaseImpl PySmSheetSetMgrImpl::OpenDatabase(const CString& filename)
{
    IAcSmDatabase* pDb = nullptr;
    _bstr_t bstrName(filename);
    PyThrowBadHr(impObj()->OpenDatabase(bstrName, TRUE, &pDb));
    return PySmSmDatabaseImpl(pDb);
}

PySmSmDatabaseImpl PySmSheetSetMgrImpl::FindOpenDatabase(const CString& filename)
{
    IAcSmDatabase* pDb = nullptr;
    _bstr_t bstrName(filename);
    PyThrowBadHr(impObj()->FindOpenDatabase(bstrName, &pDb));
    return PySmSmDatabaseImpl(pDb);
}

void PySmSheetSetMgrImpl::CloseAll()
{
    PyThrowBadHr(impObj()->CloseAll());
}

void PySmSheetSetMgrImpl::Close(PySmSmDatabaseImpl& db)
{
    PyThrowBadHr(impObj()->Close(db.impObj()));
}

std::pair<PySmSmDatabaseImpl, PySmSheetSetImpl> PySmSheetSetMgrImpl::GetParentSheetSet(const CString& dwg, const CString& layout)
{
    IAcSmDatabase* pDb = nullptr;
    IAcSmSheetSet* pSheet = nullptr;
    _bstr_t bstrDwg(dwg);
    _bstr_t bstrLayout(layout);
    PyThrowBadHr(impObj()->GetParentSheetSet(bstrDwg, bstrLayout, &pSheet, &pDb));
    return std::pair(PySmSmDatabaseImpl(pDb), PySmSheetSetImpl(pSheet));
}

std::pair<PySmSmDatabaseImpl, PySmSheetImpl> PySmSheetSetMgrImpl::GetSheetFromLayout(AcDbObject* pAcDbLayout)
{
    if (pAcDbLayout == nullptr)
        throw PyNullObject();
    IAcSmDatabase* pAxDb = nullptr;
    IAcSmSheet* pSheet = nullptr;
    IAcadObjectPtr pAxLayout (GetIAcadObjectFromAcDbObject(pAcDbLayout));
    PyThrowBadHr(impObj()->GetSheetFromLayout(pAxLayout, &pSheet, &pAxDb));
    return std::pair(PySmSmDatabaseImpl(pAxDb), PySmSheetImpl(pSheet));
}

std::vector< PySmSmDatabaseImpl> PySmSheetSetMgrImpl::GetDatabaseEnumerator()
{
    std::vector<PySmSmDatabaseImpl> v;
    IAcSmEnumDatabasePtr iter;
    PyThrowBadHr(impObj()->GetDatabaseEnumerator(&iter));
    IAcSmDatabase* pAxDb = nullptr;
    while (SUCCEEDED(iter->Next(&pAxDb)) && pAxDb != nullptr)
        v.push_back(PySmSmDatabaseImpl(pAxDb));
    return v;
}

IAcSmSheetSetMgr* PySmSheetSetMgrImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<IAcSmSheetSetMgr*>(m_pimpl.GetInterfacePtr());
}

#endif
