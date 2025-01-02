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

std::vector<std::wstring> PyAcadApplicationImpl::ListArx()
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

bool PyAcadApplicationImpl::runTest()
{
    PyAcadApplicationImpl app;
    for (const auto& item : app.ListArx())
        acutPrintf(_T("\n%ls"), item.c_str());
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