#include "stdafx.h"
#include "PyAcadTableImpl.h"

//------------------------------------------------------------------------------------
//PyIAcadTableImpl
PyIAcadTableImpl::PyIAcadTableImpl(IAcadTable* ptr)
    : PyIAcadEntityImpl(ptr)
{
}

IAcadTable* PyIAcadTableImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadTable*>(m_pimpl.GetInterfacePtr());
}