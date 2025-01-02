#include "stdafx.h"
#include "PyAcadApplicationImpl.h"


#ifdef PYRXDEBUG
#include "propvarutil.h"

PyAcadApplicationImpl::PyAcadApplicationImpl()
 : m_pimpl(acedGetIDispatch(FALSE))
{
}

void PyAcadApplicationImpl::Eval(const CString& csVal) const
{
    _bstr_t bstrVal{ csVal };
    PyThrowBadHr(impObj()->Eval(bstrVal));
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
    InitVariantFromDoubleArray(asDblArray(pnt), 3, &rtVal);
    PyThrowBadHr(impObj()->ZoomCenter(rtVal,magnify));
}

bool PyAcadApplicationImpl::runTest()
{
    PyAcadApplicationImpl app;
    app.ZoomCenter(AcGePoint3d(0,0,0),10);
    return true;
}

IAcadApplication* PyAcadApplicationImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadApplication*>(m_pimpl.GetInterfacePtr());
}

#endif