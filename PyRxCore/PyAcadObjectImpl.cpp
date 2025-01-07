#include "stdafx.h"
#include "PyAcadObjectImpl.h"

#ifdef PYRXDEBUG
//------------------------------------------------------------------------------------
//PyIAcadObjectImpl
PyIAcadObjectImpl::PyIAcadObjectImpl(IAcadObject* ptr)
    : m_pimpl(ptr)
{
}

IAcadObject* PyIAcadObjectImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadObject*>(m_pimpl.GetInterfacePtr());
}

#endif