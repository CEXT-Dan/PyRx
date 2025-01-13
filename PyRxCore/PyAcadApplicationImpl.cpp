#include "stdafx.h"
#include "PyAcadApplicationImpl.h"

//------------------------------------------------------------------------------------
//PyAcadStateImpl
PyIAcadStateImpl::PyIAcadStateImpl(IAcadState* ptr)
    : m_pimpl(ptr)
{
}

bool PyIAcadStateImpl::getIsQuiescent() const
{
    VARIANT_BOOL rtVal;
    PyThrowBadHr(impObj()->get_IsQuiescent(&rtVal));
    return rtVal == VARIANT_TRUE;
}

IAcadState* PyIAcadStateImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
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

PyIAcadPlotPtr PyIAcadDocumentImpl::GetPlot() const
{
    IAcadPlot* ptr = nullptr;
    PyThrowBadHr(impObj()->get_Plot(&ptr));
    return std::make_unique<PyIAcadPlotImpl>(ptr);
}

PyIAcadLayerPtr PyIAcadDocumentImpl::GetActiveLayer() const
{
    IAcadLayer* ptr = nullptr;
    PyThrowBadHr(impObj()->get_ActiveLayer(&ptr));
    return std::make_unique<PyIAcadLayerImpl>(ptr);
}

void PyIAcadDocumentImpl::SetActiveLayer(const PyIAcadLayerImpl& obj)
{
    PyThrowBadHr(impObj()->put_ActiveLayer(obj.impObj()));
}

PyIAcadLineTypePtr PyIAcadDocumentImpl::GetActiveLinetype() const
{
    IAcadLineType* ptr = nullptr;
    PyThrowBadHr(impObj()->get_ActiveLinetype(&ptr));
    return std::make_unique<PyIAcadLineTypeImpl>(ptr);
}

void PyIAcadDocumentImpl::SetActiveLinetype(const PyIAcadLineTypeImpl& obj)
{
    PyThrowBadHr(impObj()->put_ActiveLinetype(obj.impObj()));
}

PyIAcadDimStylePtr PyIAcadDocumentImpl::GetActiveDimStyle() const
{
    IAcadDimStyle* ptr = nullptr;
    PyThrowBadHr(impObj()->get_ActiveDimStyle(&ptr));
    return std::make_unique<PyIAcadDimStyleImpl>(ptr);
}

void PyIAcadDocumentImpl::SetActiveDimStyle(const PyIAcadDimStyleImpl& obj)
{
    PyThrowBadHr(impObj()->put_ActiveDimStyle(obj.impObj()));
}

PyIAcadTextStylePtr PyIAcadDocumentImpl::GetActiveTextStyle() const
{
    IAcadTextStyle* ptr = nullptr;
    PyThrowBadHr(impObj()->get_ActiveTextStyle(&ptr));
    return std::make_unique<PyIAcadTextStyleImpl>(ptr);
}

void PyIAcadDocumentImpl::SetActiveTextStyle(const PyIAcadTextStyleImpl& obj)
{
    PyThrowBadHr(impObj()->put_ActiveTextStyle(obj.impObj()));
}

PyIAcadUCSPtr PyIAcadDocumentImpl::GetActiveUCS() const
{
    IAcadUCS* ptr = nullptr;
    PyThrowBadHr(impObj()->get_ActiveUCS(&ptr));
    return std::make_unique<PyIAcadUCSImpl>(ptr);
}

void PyIAcadDocumentImpl::SetActiveUCS(const PyIAcadUCSImpl& obj)
{
    PyThrowBadHr(impObj()->put_ActiveUCS(obj.impObj()));
}

PyIAcadViewportPtr PyIAcadDocumentImpl::GetActiveViewport() const
{
    IAcadViewport* ptr = nullptr;
    PyThrowBadHr(impObj()->get_ActiveViewport(&ptr));
    return std::make_unique<PyIAcadViewportImpl>(ptr);
}

void PyIAcadDocumentImpl::SetActiveViewport(const PyIAcadViewportImpl& obj)
{
    PyThrowBadHr(impObj()->put_ActiveViewport(obj.impObj()));
}

PyIAcadPViewportPtr PyIAcadDocumentImpl::GetActivePViewport() const
{
    IAcadPViewport* ptr = nullptr;
    PyThrowBadHr(impObj()->get_ActivePViewport(&ptr));
    return std::make_unique<PyIAcadPViewportImpl>(ptr);
}

void PyIAcadDocumentImpl::SetActivePViewport(const PyIAcadPViewportImpl& obj)
{
    PyThrowBadHr(impObj()->put_ActivePViewport(obj.impObj()));
}

CString PyIAcadDocumentImpl::GetName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Name(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
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

PyIAcadDocumentPtr PyIAcadDocumentsImpl::Add()
{
    VARIANT rtVal;
    VariantInit(&rtVal);
    IAcadDocument* ptr = nullptr;
    PyThrowBadHr(impObj()->Add(rtVal, &ptr));
    return std::make_unique<PyIAcadDocumentImpl>(ptr);
}

PyIAcadDocumentPtr PyIAcadDocumentsImpl::Add(const CString& _template)
{
    _variant_t val{ static_cast<const wchar_t*>(_template) };
    IAcadDocument* ptr = nullptr;
    PyThrowBadHr(impObj()->Add(val, &ptr));
    return std::make_unique<PyIAcadDocumentImpl>(ptr);
}

void PyIAcadDocumentsImpl::Close()
{
    PyThrowBadHr(impObj()->Close());
}

PyIAcadDocumentPtr PyIAcadDocumentsImpl::GetItem(long index)
{
    _variant_t val{ index };
    IAcadDocument* ptr = nullptr;
    PyThrowBadHr(impObj()->Item(val, &ptr));
    return std::make_unique<PyIAcadDocumentImpl>(ptr);
}

PyIAcadDocumentPtr PyIAcadDocumentsImpl::Open(const CString& path, bool readOnly)
{
    VARIANT passwd;
    VariantInit(&passwd);// no longer supported
    _bstr_t bstrpath{ path };
    _variant_t breadOnly{ readOnly };
    IAcadDocument* ptr = nullptr;
    PyThrowBadHr(impObj()->Open(bstrpath, breadOnly, passwd, &ptr));
    return std::make_unique<PyIAcadDocumentImpl>(ptr);
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

PyIAcadStateImplPtr PyAcadApplicationImpl::GetAcadState()
{
    IAcadState* ptr = nullptr;
#if defined(_ZRXTARGET)
    PyThrowBadHr(impObj()->GetZcadState(&ptr));
#elif defined(_GRXTARGET)
    PyThrowBadHr(impObj()->GetAcadState(&ptr));
#else
    PyThrowBadHr(impObj()->GetAcadState(&ptr));
#endif
    return std::make_unique<PyIAcadStateImpl>(ptr);
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

void PyAcadApplicationImpl::ZoomScaled(double magnify, PyAcZoomScaleType scaletype)
{
    AcZoomScaleType _scaletype = (AcZoomScaleType)scaletype;
    PyThrowBadHr(impObj()->ZoomScaled(magnify, _scaletype));
}

PyIAcadDocumentPtr PyAcadApplicationImpl::GetActiveDocument() const
{
    IAcadDocument* ptr = nullptr;
    PyThrowBadHr(impObj()->get_ActiveDocument(&ptr));
    return std::make_unique<PyIAcadDocumentImpl>(ptr);
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

PyIAcadDocumentsPtr PyAcadApplicationImpl::GetDocuments() const
{
    IAcadDocuments* ptr = nullptr;
    PyThrowBadHr(impObj()->get_Documents(&ptr));
    return std::make_unique<PyIAcadDocumentsImpl>(ptr);
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

PyAcWindowState PyAcadApplicationImpl::GetWindowState() const
{
    AcWindowState val = (AcWindowState)PyAcWindowState::pyacNorm;
    PyThrowBadHr(impObj()->get_WindowState(&val));
    return (PyAcWindowState)val;
}

void PyAcadApplicationImpl::SetWindowState(PyAcWindowState val)
{
    AcWindowState _val = AcWindowState(val);
    PyThrowBadHr(impObj()->put_WindowState(_val));
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

bool PyAcadApplicationImpl::runTest(const AcDbObjectId& id)
{
    auto icobj = GetIAcadObjectFromAcDbObjectId(id);

    if (icobj != nullptr)
    {
        PyIAcadObjectImpl tmp(icobj);
        acutPrintf(_T("\nHandle = %ls"), (const wchar_t*)tmp.GetHandle());
        acutPrintf(_T("\nObjectName = %ls"), (const wchar_t*)tmp.GetObjectName());


        auto app = tmp.GetApplication();
        acutPrintf(_T("\nGetApplication = %ls"), (const wchar_t*)app.GetFullName());


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
