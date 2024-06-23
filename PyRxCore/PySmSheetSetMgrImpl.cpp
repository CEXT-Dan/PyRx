#include "stdafx.h"
#include "PySmSheetSetMgrImpl.h"

#if defined(_ARXTARGET) || defined(_BRXTARGET) 

//-----------------------------------------------------------------------------------------
//PySmPersist
PySmPersistImpl::PySmPersistImpl(IAcSmPersist* other)
{
    if (other != nullptr)
        m_pimpl.Attach(other);
}

IAcSmPersist* PySmPersistImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<IAcSmPersist*>(m_pimpl.GetInterfacePtr());
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
    if(HRESULT hr = impObj()->GetName(&bstrName.GetBSTR());  FAILED(hr))
        acutPrintf(_T("\nFailed! %lx %ls"), hr, __FUNCTIONW__);
    return (LPCTSTR)bstrName;
}

void PySmComponentImpl::SetName(const CString& csName)
{
    _bstr_t bstrName(csName);
    if(HRESULT hr = impObj()->SetName(bstrName); FAILED(hr))
        acutPrintf(_T("\nFailed! %lx %ls"), hr , __FUNCTIONW__);
}

CString PySmComponentImpl::GetDesc() const
{
    _bstr_t bstrDesc;
    if (HRESULT hr = impObj()->GetDesc(&bstrDesc.GetBSTR());  FAILED(hr))
        acutPrintf(_T("\nFailed! %lx %ls"), hr, __FUNCTIONW__);
    return (LPCTSTR)bstrDesc;
}

void PySmComponentImpl::SetDesc(const CString& csDesc)
{
    _bstr_t bstrDesc(csDesc);
    if (HRESULT hr = impObj()->SetDesc(bstrDesc); FAILED(hr))
        acutPrintf(_T("\nFailed! %lx %ls"), hr, __FUNCTIONW__);
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
    if (HRESULT hr = impObj()->LockDb(impObj()); FAILED(hr))
        acutPrintf(_T("\nFailed! %lx %ls"), hr, __FUNCTIONW__);
}

void PySmSmDatabaseImpl::UnlockDb(bool commit)
{
    auto b = commit ? VARIANT_TRUE : VARIANT_FALSE;
    if (HRESULT hr = impObj()->UnlockDb(impObj(),b); FAILED(hr))
        acutPrintf(_T("\nFailed! %lx %ls"), hr, __FUNCTIONW__);
}

PySmSheetSetImpl PySmSmDatabaseImpl::GetSheetSet()
{
    IAcSmSheetSet* pSheet = nullptr;
    if (HRESULT hr = impObj()->GetSheetSet(&pSheet); FAILED(hr))
        acutPrintf(_T("\nFailed! %lx %ls"), hr, __FUNCTIONW__);
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
    if(HRESULT hr = impObj()->CreateDatabase(bstrName, NULL, TRUE, &pDb); FAILED(hr))
    {
        acutPrintf(_T("\nFailed! %lx %ls"), hr, __FUNCTIONW__);
        if (E_INVALIDARG == hr)
            acutPrintf(_T("\n File name invalid!"));
    }
    return PySmSmDatabaseImpl(pDb);
}

PySmSmDatabaseImpl PySmSheetSetMgrImpl::CreateDatabase(const CString& filename, const CString& templatefilename, bool bAlwaysCreate)
{
    IAcSmDatabase* pDb = nullptr;
    _bstr_t bstrName(filename);
    _bstr_t bstrTemplate(templatefilename);
    BOOL flag = bAlwaysCreate ? TRUE : FALSE;
    if (HRESULT hr = impObj()->CreateDatabase(bstrName, bstrTemplate, bAlwaysCreate, &pDb); FAILED(hr))
    {
        acutPrintf(_T("\nFailed! %lx %ls"), hr, __FUNCTIONW__);
        if (E_INVALIDARG == hr)
            acutPrintf(_T("\nFile name invalid!"));
    }
    return PySmSmDatabaseImpl(pDb);
}

PySmSmDatabaseImpl PySmSheetSetMgrImpl::OpenDatabase(const CString& filename)
{
    IAcSmDatabase* pDb = nullptr;
    _bstr_t bstrName(filename);

    if (HRESULT hr = impObj()->OpenDatabase(bstrName,TRUE, &pDb); FAILED(hr))
        acutPrintf(_T("\nFailed! %lx %ls"), hr, __FUNCTIONW__);
    return PySmSmDatabaseImpl(pDb);
}

PySmSmDatabaseImpl PySmSheetSetMgrImpl::FindOpenDatabase(const CString& filename)
{
    IAcSmDatabase* pDb = nullptr;
    _bstr_t bstrName(filename);
    if (HRESULT hr = impObj()->FindOpenDatabase(bstrName, &pDb); FAILED(hr))
        acutPrintf(_T("\nFailed! %lx %ls"), hr, __FUNCTIONW__);
    return PySmSmDatabaseImpl(pDb);
}

void PySmSheetSetMgrImpl::CloseAll()
{
    if (HRESULT hr = impObj()->CloseAll(); FAILED(hr))
        acutPrintf(_T("\nFailed! %lx %ls"), hr, __FUNCTIONW__);
}

void PySmSheetSetMgrImpl::Close(PySmSmDatabaseImpl& db)
{
    if (HRESULT hr = impObj()->Close(db.impObj()); FAILED(hr))
        acutPrintf(_T("\nFailed! %lx %ls"), hr, __FUNCTIONW__);
}

IAcSmSheetSetMgr* PySmSheetSetMgrImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<IAcSmSheetSetMgr*>(m_pimpl.GetInterfacePtr());
}

#endif
