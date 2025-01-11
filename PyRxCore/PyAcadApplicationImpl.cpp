#include "stdafx.h"
#include "PyAcadApplicationImpl.h"


#ifdef PYRX_IN_PROGRESS_PYAX


//------------------------------------------------------------------------------------
//PyAcadStateImpl
PyAcadStateImpl::PyAcadStateImpl(IAcadState* ptr)
    : m_pimpl(ptr)
{
}

bool PyAcadStateImpl::getIsQuiescent() const
{
    VARIANT_BOOL rtVal;
    PyThrowBadHr(impObj()->get_IsQuiescent(&rtVal));
    return rtVal == VARIANT_TRUE;
}

IAcadState* PyAcadStateImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadState*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadDatabaseImpl
PyIAcadDatabaseImpl::PyIAcadDatabaseImpl(IAcadDatabase* ptr)
    : m_pimpl(ptr)
{
}


IAcadDatabase* PyIAcadDatabaseImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadDatabase*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadDocumentImpl
PyIAcadDocumentImpl::PyIAcadDocumentImpl(IAcadDocument* ptr)
    : PyIAcadDatabaseImpl(ptr)
{
}

IAcadDocument* PyIAcadDocumentImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadDocument*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadDocumentsImpl
PyIAcadDocumentsImpl::PyIAcadDocumentsImpl(IAcadDocuments* ptr)
    : m_pimpl(ptr)
{
}

long PyIAcadDocumentsImpl::GetCount() const
{
    long val = 0;
    PyThrowBadHr(impObj()->get_Count(&val));
    return val;
}

PyIAcadDocumentImpl PyIAcadDocumentsImpl::Add()
{
    VARIANT rtVal;
    VariantInit(&rtVal);
    IAcadDocument* ptr = nullptr;
    PyThrowBadHr(impObj()->Add(rtVal, &ptr));
    return PyIAcadDocumentImpl(ptr);
}

PyIAcadDocumentImpl PyIAcadDocumentsImpl::Add(const CString& _template)
{
    _variant_t val{ static_cast<const wchar_t*>(_template) };
    IAcadDocument* ptr = nullptr;
    PyThrowBadHr(impObj()->Add(val, &ptr));
    return PyIAcadDocumentImpl(ptr);
}

void PyIAcadDocumentsImpl::Close()
{
    PyThrowBadHr(impObj()->Close());
}

PyIAcadDocumentImpl PyIAcadDocumentsImpl::GetItem(long index)
{
    _variant_t val{ index };
    IAcadDocument* ptr = nullptr;
    PyThrowBadHr(impObj()->Item(val, &ptr));
    return PyIAcadDocumentImpl(ptr);
}

PyIAcadDocumentImpl PyIAcadDocumentsImpl::Open(const CString& path, bool readOnly)
{
    VARIANT passwd;
    VariantInit(&passwd);// no longer supported
    _bstr_t bstrpath{ path };
    _variant_t breadOnly{ readOnly };
    IAcadDocument* ptr = nullptr;
    PyThrowBadHr(impObj()->Open(bstrpath, breadOnly, passwd, &ptr));
    return PyIAcadDocumentImpl(ptr);
}

IAcadDocuments* PyIAcadDocumentsImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadDocuments*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyAcadApplicationImpl
PyAcadApplicationImpl::PyAcadApplicationImpl()
    : m_pimpl(acedGetIDispatch(TRUE))
{
}

PyAcadApplicationImpl::PyAcadApplicationImpl(IAcadApplication* ptr)
    : m_pimpl(ptr)
{
}

void PyAcadApplicationImpl::Eval(const CString& csVal) const
{
    _bstr_t bstrVal{ csVal };
    PyThrowBadHr(impObj()->Eval(bstrVal));
}

PyAcadStateImpl PyAcadApplicationImpl::GetAcadState()
{
    IAcadState* ptr = nullptr;
#if defined(_ZRXTARGET)
    PyThrowBadHr(impObj()->GetZcadState(&ptr));
#elif defined(_GRXTARGET)
    PyThrowBadHr(impObj()->GetAcadState(&ptr));
#else
    PyThrowBadHr(impObj()->GetAcadState(&ptr));
#endif
    return PyAcadStateImpl(ptr);
}

wstringArray PyAcadApplicationImpl::ListArx()
{
    VARIANT rtVal;
    VariantInit(&rtVal);
#if defined(_ZRXTARGET)
    PyThrowBadHr(impObj()->ListZrx(&rtVal));
#elif defined(_GRXTARGET)
    PyThrowBadHr(impObj()->ListGrx(&rtVal));
#else
    PyThrowBadHr(impObj()->ListArx(&rtVal));
#endif
    ULONG pcElem = 0;
    PWSTR* prgsz = nullptr;
    std::vector<std::wstring> vec;
    if (VariantToStringArrayAlloc(rtVal, &prgsz, &pcElem) == S_OK)
    {
        vec = std::vector<std::wstring>(prgsz, prgsz + pcElem);
        CoTaskMemFree(prgsz);
    }
    return vec;
}

void PyAcadApplicationImpl::LoadArx(const CString& csVal)
{
    _bstr_t bstrVal{ csVal };
#if defined(_ZRXTARGET)
    PyThrowBadHr(impObj()->LoadZrx(bstrVal));
#elif defined(_GRXTARGET)
    PyThrowBadHr(impObj()->LoadGrx(bstrVal));
#else
    PyThrowBadHr(impObj()->LoadArx(bstrVal));
#endif
}

void PyAcadApplicationImpl::LoadDVB(const CString& csVal)
{
#if defined(_ZRXTARGET)
    throw PyNotimplementedByHost();
#else
    _bstr_t bstrVal{ csVal };
    PyThrowBadHr(impObj()->LoadDVB(bstrVal));
#endif
}

void PyAcadApplicationImpl::Quit()
{
    PyThrowBadHr(impObj()->Quit());
}

void PyAcadApplicationImpl::RunMacro(const CString& csVal)
{
    _bstr_t bstrVal{ csVal };
    PyThrowBadHr(impObj()->RunMacro(bstrVal));
}

void PyAcadApplicationImpl::UnloadArx(const CString& csVal)
{
    _bstr_t bstrVal{ csVal };
#if defined(_ZRXTARGET)
    PyThrowBadHr(impObj()->UnloadZrx(bstrVal));
#elif defined(_GRXTARGET)
    PyThrowBadHr(impObj()->UnloadGrx(bstrVal));
#else
    PyThrowBadHr(impObj()->UnloadArx(bstrVal));
#endif
}

void PyAcadApplicationImpl::UnloadDVB(const CString& csVal)
{
#if defined(_ZRXTARGET)
    throw PyNotimplementedByHost();
#else
    _bstr_t bstrVal{ csVal };
    PyThrowBadHr(impObj()->UnloadDVB(bstrVal));
#endif
}

void PyAcadApplicationImpl::Update()
{
    PyThrowBadHr(impObj()->Update());
}

void PyAcadApplicationImpl::ZoomAll()
{
    PyThrowBadHr(impObj()->ZoomAll());
}

void PyAcadApplicationImpl::ZoomCenter(const AcGePoint3d& pnt, double magnify)
{
    VARIANT rtVal;
    VariantInit(&rtVal);
    constexpr ULONG s = sizeof(pnt) / sizeof(double);
    PyThrowBadHr(InitVariantFromDoubleArray(asDblArray(pnt), s, &rtVal));
    PyThrowBadHr(impObj()->ZoomCenter(rtVal, magnify));
}

void PyAcadApplicationImpl::ZoomExtents()
{
    PyThrowBadHr(impObj()->ZoomExtents());
}

void PyAcadApplicationImpl::ZoomPickWindow()
{
    PyThrowBadHr(impObj()->ZoomPickWindow());
}

void PyAcadApplicationImpl::ZoomPrevious()
{
    PyThrowBadHr(impObj()->ZoomPickWindow());
}

void PyAcadApplicationImpl::ZoomScaled(double magnify, AcZoomScaleType scaletype)
{
    PyThrowBadHr(impObj()->ZoomScaled(magnify, scaletype));
}

PyIAcadDocumentImpl PyAcadApplicationImpl::GetActiveDocument() const
{
    IAcadDocument* ptr = nullptr;
    PyThrowBadHr(impObj()->get_ActiveDocument(&ptr));
    return PyIAcadDocumentImpl(ptr);
}

void PyAcadApplicationImpl::SetActiveDocument(const PyIAcadDocumentImpl& val) const
{
    PyThrowBadHr(impObj()->put_ActiveDocument(val.impObj()));
}

CString PyAcadApplicationImpl::GetCaption() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Caption(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

PyIAcadDocumentsImpl PyAcadApplicationImpl::getDocuments() const
{
    IAcadDocuments* ptr = nullptr;
    PyThrowBadHr(impObj()->get_Documents(&ptr));
    return PyIAcadDocumentsImpl(ptr);
}

CString PyAcadApplicationImpl::GetFullName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_FullName(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

int PyAcadApplicationImpl::GetHeight() const
{
    int val = 0;
    PyThrowBadHr(impObj()->get_Height(&val));
    return val;
}

void PyAcadApplicationImpl::SetHeight(int val)
{
    PyThrowBadHr(impObj()->put_Height(val));
}

LONG_PTR PyAcadApplicationImpl::GetHWND() const
{
    LONG_PTR val = 0;
    PyThrowBadHr(impObj()->get_HWND(&val));
    return val;
}

long PyAcadApplicationImpl::GetLocaleId() const
{
    long val = 0;
    PyThrowBadHr(impObj()->get_LocaleId(&val));
    return val;
}

CString PyAcadApplicationImpl::GetName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Name(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

CString PyAcadApplicationImpl::GetPath() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Path(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

CString PyAcadApplicationImpl::GetVersion() const
{
    _bstr_t bstrVal;
#if defined(_BRXTARGET)
    throw PyNotimplementedByHost();
#else
    PyThrowBadHr(impObj()->get_Version(&bstrVal.GetBSTR()));
#endif
    return (LPCTSTR)bstrVal;
}

bool PyAcadApplicationImpl::GetVisible() const
{
    VARIANT_BOOL rtVal;
    PyThrowBadHr(impObj()->get_Visible(&rtVal));
    return rtVal == VARIANT_TRUE;
}

void PyAcadApplicationImpl::SetVisible(bool val)
{
    VARIANT_BOOL rtVal = val ? 1 : 0;
    PyThrowBadHr(impObj()->put_Visible(rtVal));
}

int PyAcadApplicationImpl::GetWidth() const
{
    int val = 0;
    PyThrowBadHr(impObj()->get_Width(&val));
    return val;
}

void PyAcadApplicationImpl::SetWidth(int val)
{
    PyThrowBadHr(impObj()->put_Width(val));
}

int PyAcadApplicationImpl::GetWindowLeft() const
{
    int val = 0;
    PyThrowBadHr(impObj()->get_WindowLeft(&val));
    return val;
}

void PyAcadApplicationImpl::SetWindowLeft(int val)
{
    PyThrowBadHr(impObj()->put_WindowLeft(val));
}

AcWindowState PyAcadApplicationImpl::GetWindowState() const
{
    AcWindowState val = static_cast<AcWindowState>(1);
    PyThrowBadHr(impObj()->get_WindowState(&val));
    return val;
}

void PyAcadApplicationImpl::SetWindowState(AcWindowState val)
{
    PyThrowBadHr(impObj()->put_WindowState(val));
}

int PyAcadApplicationImpl::GetWindowTop() const
{
    int val = 0;
    PyThrowBadHr(impObj()->get_WindowTop(&val));
    return val;
}

void PyAcadApplicationImpl::SetWindowTop(int val)
{
    PyThrowBadHr(impObj()->put_WindowTop(val));
}

IAcadObject* GetIAcadObject(const AcDbObjectId& id)
{
    AcDbObjectPointer<AcDbEntity> pent(id);
    return GetIAcadObjectFromAcDbObject(pent);
}

bool PyAcadApplicationImpl::runTest(const AcDbObjectId& id)
{
    //AcDbObjectPointer<AcDbEntity> pent(id);
    //auto obj = GetIAcadObjectFromAcDbObject(pent);

    auto obj = GetIAcadObject(id);
    // 
    //auto obj = GetIAcadObjectFromAcDbObjectId(id);

    if (obj != nullptr)
    {
        PyIAcadObjectImpl tmp(obj);
        acutPrintf(_T("\nHandle = %ls"), (const wchar_t*)tmp.GetHandle());
        acutPrintf(_T("\nObjectName = %ls"), (const wchar_t*)tmp.GetObjectName());

        //
        const auto data = tmp.GetXData("PYRX");
        tmp.SetXData(data);
    }
    return true;
}

IAcadApplication* PyAcadApplicationImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadApplication*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//IAcadUtilityImpl
PyIAcadUtility::PyIAcadUtility(IAcadUtility* ptr)
    : m_pimpl(ptr)
{
}

IAcadUtility* PyIAcadUtility::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadUtility*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadSecurityParamsImpl
PyIAcadSecurityParams::PyIAcadSecurityParams(IAcadSecurityParams* ptr)
    : m_pimpl(ptr)
{
}

IAcadSecurityParams* PyIAcadSecurityParams::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadSecurityParams*>(m_pimpl.GetInterfacePtr());
}

#endif
