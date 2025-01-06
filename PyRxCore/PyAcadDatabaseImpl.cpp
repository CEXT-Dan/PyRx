#include "stdafx.h"
#include "PyAcadDatabaseImpl.h"

#ifdef PYRXDEBUG
//------------------------------------------------------------------------------------
//PyIAcadAcCmColorImpl
PyIAcadAcCmColorImpl::PyIAcadAcCmColorImpl(IAcadAcCmColor* ptr)
    : m_pimpl(ptr)
{
}

void PyIAcadAcCmColorImpl::SetEntityColor(long val)
{
    PyThrowBadHr(impObj()->put_EntityColor(val));
}

long PyIAcadAcCmColorImpl::GetEntityColor() const
{
    long val = 0;
    PyThrowBadHr(impObj()->get_EntityColor(&val));
    return val;
}

CString PyIAcadAcCmColorImpl::GetColorName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_ColorName(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

CString PyIAcadAcCmColorImpl::GetBookName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_BookName(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadAcCmColorImpl::SetNames(const CString& colorName, const CString& bookName)
{
    _bstr_t bstrcolorName{ colorName };
    _bstr_t bstrbookName{ bookName };
    PyThrowBadHr(impObj()->SetNames(bstrcolorName, bstrbookName));
}

void PyIAcadAcCmColorImpl::Delete()
{
    PyThrowBadHr(impObj()->Delete());
}

long PyIAcadAcCmColorImpl::GetRed() const
{
    long val = 0;
    PyThrowBadHr(impObj()->get_Red(&val));
    return val;
}

long PyIAcadAcCmColorImpl::GetGreen() const
{
    long val = 0;
    PyThrowBadHr(impObj()->get_Green(&val));
    return val;
}

long PyIAcadAcCmColorImpl::GetBlue() const
{
    long val = 0;
    PyThrowBadHr(impObj()->get_Blue(&val));
    return val;
}

void PyIAcadAcCmColorImpl::SetRGB(long Red, long Green, long Blue)
{
    PyThrowBadHr(impObj()->SetRGB(Red, Green, Blue));
}

void PyIAcadAcCmColorImpl::SetColorMethod(AcColorMethod flags)
{
    PyThrowBadHr(impObj()->put_ColorMethod(flags));
}

AcColor PyIAcadAcCmColorImpl::GetColorIndex() const
{
#if defined(_ZRXTARGET)
    AcColor val = AcColor::zcByBlock;
#elif defined(_GRXTARGET)
    AcColor val = AcColor::gcByBlock;
#else
    AcColor val = AcColor::acByBlock;
#endif

    PyThrowBadHr(impObj()->get_ColorIndex(&val));
    return val;
}

void PyIAcadAcCmColorImpl::SetColorIndex(AcColor val)
{
    PyThrowBadHr(impObj()->put_ColorIndex(val));
}

void PyIAcadAcCmColorImpl::SetColorBookColor(const CString& colorName, const CString& bookName)
{
    _bstr_t bstrcolorName{ colorName };
    _bstr_t bstrbookName{ bookName };
    PyThrowBadHr(impObj()->SetColorBookColor(bstrcolorName, bstrbookName));
}

AcColorMethod PyIAcadAcCmColorImpl::GetColorMethod() const
{
#if defined(_ZRXTARGET)
    AcColorMethod val = AcColorMethod::zcColorMethodByLayer;
#elif defined(_GRXTARGET)
    AcColorMethod val = AcColorMethod::gcColorMethodByLayer;
#else
    AcColorMethod val = AcColorMethod::acColorMethodByLayer;
#endif
    PyThrowBadHr(impObj()->get_ColorMethod(&val));
    return val;
}

IAcadAcCmColor* PyIAcadAcCmColorImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadAcCmColor*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadEntityImpl
PyIAcadHyperlinkImpl::PyIAcadHyperlinkImpl(IAcadHyperlink* ptr)
    : m_pimpl(ptr)
{
}

CString PyIAcadHyperlinkImpl::GetURL() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_URL(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadHyperlinkImpl::SetURL(const CString& val)
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_URL(bstrval));
}

CString PyIAcadHyperlinkImpl::GetURLDescription() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_URLDescription(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadHyperlinkImpl::SetURLDescription(const CString& val)
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_URLDescription(bstrval));
}

void PyIAcadHyperlinkImpl::Delete()
{
    PyThrowBadHr(impObj()->Delete());
}

CString PyIAcadHyperlinkImpl::GetURLNamedLocation() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_URLNamedLocation(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadHyperlinkImpl::SetURLNamedLocation(const CString& val)
{
    _bstr_t bstrval{ val };
    PyThrowBadHr(impObj()->put_URLNamedLocation(bstrval));
}

IAcadHyperlink* PyIAcadHyperlinkImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadHyperlink*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadHyperlinksImpl
PyIAcadHyperlinksImpl::PyIAcadHyperlinksImpl(IAcadHyperlinks* ptr)
    : m_pimpl(ptr)
{
}

PyIAcadHyperlinkImpl PyIAcadHyperlinksImpl::GetItem(long val)
{
    IAcadHyperlink* ptr = nullptr;
    PyThrowBadHr(impObj()->Item(val, &ptr));
    return PyIAcadHyperlinkImpl(ptr);
}

long PyIAcadHyperlinksImpl::GetCount() const
{
    long val = 0;
    PyThrowBadHr(impObj()->get_Count(&val));
    return val;
}

PyIAcadHyperlinkImpl PyIAcadHyperlinksImpl::Add(const CString& name, const CString& description, const CString& namedLocation)
{
    IAcadHyperlink* ptr = nullptr;
    _bstr_t bstrname{ name };
    _variant_t bstrdescription{ static_cast<const wchar_t*>(description) };
    _variant_t bstrnamedLocation{ static_cast<const wchar_t*>(namedLocation) };
    PyThrowBadHr(impObj()->Add(bstrname, bstrdescription, bstrnamedLocation, &ptr));
    return PyIAcadHyperlinkImpl(ptr);
}

IAcadHyperlinks* PyIAcadHyperlinksImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadHyperlinks*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//IAcadSectionTypeSettings
PyIAcadSectionTypeSettingsImpl::PyIAcadSectionTypeSettingsImpl(IAcadSectionTypeSettings* ptr)
    : m_pimpl(ptr)
{
}

AcSectionGeneration PyIAcadSectionTypeSettingsImpl::GetGenerationOptions() const
{
#if defined(_ZRXTARGET)
    AcSectionGeneration val = AcSectionGeneration::zcSectionGenerationDestinationFile;
#elif defined(_GRXTARGET)
    AcSectionGeneration val = AcSectionGeneration::gcSectionGenerationDestinationFile;
#else
    AcSectionGeneration val = AcSectionGeneration::acSectionGenerationDestinationFile;
#endif
    PyThrowBadHr(impObj()->get_GenerationOptions(&val));
    return val;
}

void PyIAcadSectionTypeSettingsImpl::SetGenerationOptions(AcSectionGeneration val)
{
    PyThrowBadHr(impObj()->put_GenerationOptions(val));
}

IAcadSectionTypeSettings* PyIAcadSectionTypeSettingsImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadSectionTypeSettings*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadDatabasePreferences
PyIAcadDatabasePreferences::PyIAcadDatabasePreferences(IAcadDatabasePreferences* ptr)
    : m_pimpl(ptr)
{
}


IAcadDatabasePreferences* PyIAcadDatabasePreferences::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadDatabasePreferences*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadSummaryInfo
PyIAcadSummaryInfo::PyIAcadSummaryInfo(IAcadSummaryInfo* ptr)
    : m_pimpl(ptr)
{
}

IAcadSummaryInfo* PyIAcadSummaryInfo::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadSummaryInfo*>(m_pimpl.GetInterfacePtr());
}


//------------------------------------------------------------------------------------
//PyIAcadDynamicBlockReferenceProperty
PyIAcadDynamicBlockReferenceProperty::PyIAcadDynamicBlockReferenceProperty(IAcadDynamicBlockReferenceProperty* ptr)
    : m_pimpl(ptr)
{
}

IAcadDynamicBlockReferenceProperty* PyIAcadDynamicBlockReferenceProperty::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadDynamicBlockReferenceProperty*>(m_pimpl.GetInterfacePtr());
}


//------------------------------------------------------------------------------------
//PyIAcadIdPair
PyIAcadIdPair::PyIAcadIdPair(IAcadIdPair* ptr)
    : m_pimpl(ptr)
{
}

IAcadIdPair* PyIAcadIdPair::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadIdPair*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadShadowDisplay
#ifndef _BRXTARGET
PyIAcadShadowDisplay::PyIAcadShadowDisplay(IAcadShadowDisplay* ptr)
    : m_pimpl(ptr)
{
}

IAcadShadowDisplay* PyIAcadShadowDisplay::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadShadowDisplay*>(m_pimpl.GetInterfacePtr());
}
#endif

//------------------------------------------------------------------------------------
//PyIAcadSubEntity
#ifndef _GRXTARGET
PyIAcadSubEntity::PyIAcadSubEntity(IAcadSubEntity* ptr)
    : m_pimpl(ptr)
{
}

IAcadSubEntity* PyIAcadSubEntity::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadSubEntity*>(m_pimpl.GetInterfacePtr());
}
#endif

//------------------------------------------------------------------------------------
//PyIAcadMLeaderLeader
#ifndef _GRXTARGET
PyIAcadMLeaderLeader::PyIAcadMLeaderLeader(IAcadMLeaderLeader* ptr)
    : PyIAcadSubEntity(ptr)
{
}

IAcadMLeaderLeader* PyIAcadMLeaderLeader::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadMLeaderLeader*>(m_pimpl.GetInterfacePtr());
}
#endif

//------------------------------------------------------------------------------------
//PyIAcadSubEntSolidFace
#ifndef _GRXTARGET
PyIAcadSubEntSolidFace::PyIAcadSubEntSolidFace(IAcadSubEntSolidFace* ptr)
    : PyIAcadSubEntity(ptr)
{
}

IAcadSubEntSolidFace* PyIAcadSubEntSolidFace::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadSubEntSolidFace*>(m_pimpl.GetInterfacePtr());
}
#endif

//------------------------------------------------------------------------------------
//PyIAcadSubDMeshFace
#ifndef _GRXTARGET
#ifndef _BRXTARGET
PyIAcadSubDMeshFace::PyIAcadSubDMeshFace(IAcadSubDMeshFace* ptr)
    : PyIAcadSubEntity(ptr)
{
}

IAcadSubDMeshFace* PyIAcadSubDMeshFace::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadSubDMeshFace*>(m_pimpl.GetInterfacePtr());
}
#endif
#endif

//------------------------------------------------------------------------------------
//PyIAcadSubDMeshEdge
#ifndef _GRXTARGET
#ifndef _BRXTARGET
PyIAcadSubDMeshEdge::PyIAcadSubDMeshEdge(IAcadSubDMeshEdge* ptr)
    : PyIAcadSubEntity(ptr)
{
}

IAcadSubDMeshEdge* PyIAcadSubDMeshEdge::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadSubDMeshEdge*>(m_pimpl.GetInterfacePtr());
}
#endif
#endif

//------------------------------------------------------------------------------------
//PyIAcadSubDMeshVertex
#ifndef _GRXTARGET
#ifndef _BRXTARGET
PyIAcadSubDMeshVertex::PyIAcadSubDMeshVertex(IAcadSubDMeshVertex* ptr)
    : PyIAcadSubEntity(ptr)
{
}

IAcadSubDMeshVertex* PyIAcadSubDMeshVertex::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadSubDMeshVertex*>(m_pimpl.GetInterfacePtr());
}
#endif
#endif

//------------------------------------------------------------------------------------
//PyIAcadSecurityParams
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
//PyIAcadEntityImpl
PyIAcadEntityImpl::PyIAcadEntityImpl(IAcadEntity* ptr)
    : PyIAcadObjectImpl(ptr)
{

}

IAcadEntity* PyIAcadEntityImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadEntity*>(m_pimpl.GetInterfacePtr());
}

#endif
