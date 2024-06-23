#include "stdafx.h"
#include "PySmSheetSetMgrImpl.h"

#if defined(_ARXTARGET) || defined(_BRXTARGET) 

//-----------------------------------------------------------------------------------------
//PySmPersist
PySmPersistImpl::PySmPersistImpl(IAcSmPersist* other)
{
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

IAcSmComponent* PySmComponentImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<IAcSmComponent*>(m_pimpl.GetInterfacePtr());
}

//-----------------------------------------------------------------------------------------
//PySmSmDatabase
PySmSmDatabaseImpl::PySmSmDatabaseImpl(IAcSmDatabase* other)
    : PySmComponentImpl(other)
{
}


IAcSmDatabase* PySmSmDatabaseImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<IAcSmDatabase*>(m_pimpl.GetInterfacePtr());
}


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
    HRESULT hr = S_OK;
    IAcSmDatabase *pDb = nullptr;
    _bstr_t bstrName(filename);
    if (FAILED(hr = impObj()->CreateDatabase(bstrName, NULL, TRUE, &pDb)))
    {
        acutPrintf(_T("\nError: Cannot create database!"));
        if (E_INVALIDARG == hr)
            acutPrintf(_T("\n File name invalid!"));
    }
    return PySmSmDatabaseImpl(pDb);
}

PySmSmDatabaseImpl PySmSheetSetMgrImpl::CreateDatabase(const CString& filename, const CString& templatefilename, bool bAlwaysCreate)
{
    HRESULT hr = S_OK;
    IAcSmDatabase* pDb = nullptr;
    _bstr_t bstrName(filename);
    _bstr_t bstrTemplate(templatefilename);
    BOOL flag = bAlwaysCreate ? TRUE : FALSE;
    if (FAILED(hr = impObj()->CreateDatabase(bstrName, bstrTemplate, flag, &pDb)))
    {
        acutPrintf(_T("\nError: Cannot create database!"));
        if (E_INVALIDARG == hr)
            acutPrintf(_T("\nFile name invalid!"));
    }
    return PySmSmDatabaseImpl(pDb);
}

PySmSmDatabaseImpl PySmSheetSetMgrImpl::OpenDatabase(const CString& filename)
{
    IAcSmDatabase* pDb = nullptr;
    _bstr_t bstrName(filename);
    if (FAILED(impObj()->OpenDatabase(bstrName, TRUE, &pDb)))
        acutPrintf(_T("\nFailed! %ls"), __FUNCTIONW__);
    return PySmSmDatabaseImpl(pDb);
}

PySmSmDatabaseImpl PySmSheetSetMgrImpl::FindOpenDatabase(const CString& filename)
{
    IAcSmDatabase* pDb = nullptr;
    _bstr_t bstrName(filename);
    if (FAILED(impObj()->FindOpenDatabase(bstrName, &pDb)))
        acutPrintf(_T("\nFailed! %ls"), __FUNCTIONW__);
    return PySmSmDatabaseImpl(pDb);
}

void PySmSheetSetMgrImpl::CloseAll()
{
    if (FAILED(impObj()->CloseAll()))
        acutPrintf(_T("\nFailed! %ls"), __FUNCTIONW__);
}

void PySmSheetSetMgrImpl::Close(PySmSmDatabaseImpl& db)
{
    if (FAILED(impObj()->Close(db.impObj())))
        acutPrintf(_T("\nFailed! %ls"), __FUNCTIONW__);
}

IAcSmSheetSetMgr* PySmSheetSetMgrImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<IAcSmSheetSetMgr*>(m_pimpl.GetInterfacePtr());
}

#endif

