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

//------------------------------------------------------------------------------------
//PyIAcadPlotConfigurationImpl
PyIAcadPlotConfigurationImpl::PyIAcadPlotConfigurationImpl(IAcadPlotConfiguration* ptr)
    : PyIAcadObjectImpl(ptr)
{
}

IAcadPlotConfiguration* PyIAcadPlotConfigurationImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadPlotConfiguration*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadSectionSettingsImpl
PyIAcadSectionSettingsImpl::PyIAcadSectionSettingsImpl(IAcadSectionSettings* ptr)
    : PyIAcadObjectImpl(ptr)
{
}

IAcadSectionSettings* PyIAcadSectionSettingsImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadSectionSettings*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadViewImpl
PyIAcadViewImpl::PyIAcadViewImpl(IAcadView* ptr)
    : PyIAcadObjectImpl(ptr)
{
}

IAcadView* PyIAcadViewImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadView*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadGroupImpl
PyIAcadGroupImpl::PyIAcadGroupImpl(IAcadGroup* ptr)
    : PyIAcadObjectImpl(ptr)
{
}

IAcadGroup* PyIAcadGroupImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadGroup*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadGroupsImpl
PyIAcadGroupsImpl::PyIAcadGroupsImpl(IAcadGroups* ptr)
    : PyIAcadObjectImpl(ptr)
{
}

IAcadGroups* PyIAcadGroupsImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadGroups*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadDimStyleImpl
PyIAcadDimStyleImpl::PyIAcadDimStyleImpl(IAcadDimStyle* ptr)
    : PyIAcadObjectImpl(ptr)
{
}

IAcadDimStyle* PyIAcadDimStyleImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadDimStyle*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadDimStylesImpl
PyIAcadDimStylesImpl::PyIAcadDimStylesImpl(IAcadDimStyles* ptr)
    : PyIAcadObjectImpl(ptr)
{
}

IAcadDimStyles* PyIAcadDimStylesImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadDimStyles*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadLayerImpl
PyIAcadLayerImpl::PyIAcadLayerImpl(IAcadLayer* ptr)
    : PyIAcadObjectImpl(ptr)
{
}

IAcadLayer* PyIAcadLayerImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadLayer*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadLayersImpl
PyIAcadLayersImpl::PyIAcadLayersImpl(IAcadLayers* ptr)
    : PyIAcadObjectImpl(ptr)
{
}

IAcadLayers* PyIAcadLayersImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadLayers*>(m_pimpl.GetInterfacePtr());
}

#endif
