#include "stdafx.h"
#include "PyAcadObjectImpl.h"

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

void PyIAcadAcCmColorImpl::SetColorMethod(PyAcColorMethod flags)
{
    AcColorMethod _flags = (AcColorMethod)flags;
    PyThrowBadHr(impObj()->put_ColorMethod(_flags));
}

PyAcColor PyIAcadAcCmColorImpl::GetColorIndex() const
{
    AcColor val = (AcColor)PyAcColor::pyacByBlock;
    PyThrowBadHr(impObj()->get_ColorIndex(&val));
    return (PyAcColor)val;
}

void PyIAcadAcCmColorImpl::SetColorIndex(PyAcColor val)
{
    PyThrowBadHr(impObj()->put_ColorIndex(AcColor(val)));
}

void PyIAcadAcCmColorImpl::SetColorBookColor(const CString& colorName, const CString& bookName)
{
    _bstr_t bstrcolorName{ colorName };
    _bstr_t bstrbookName{ bookName };
    PyThrowBadHr(impObj()->SetColorBookColor(bstrcolorName, bstrbookName));
}

PyAcColorMethod PyIAcadAcCmColorImpl::GetColorMethod() const
{

    AcColorMethod val = (AcColorMethod)PyAcColorMethod::pyacColorMethodByLayer;
    PyThrowBadHr(impObj()->get_ColorMethod(&val));
    return (PyAcColorMethod)val;
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
//IAcadSectionTypeSettingsImpl
PyIAcadSectionTypeSettingsImpl::PyIAcadSectionTypeSettingsImpl(IAcadSectionTypeSettings* ptr)
    : m_pimpl(ptr)
{
}

PyAcSectionGeneration PyIAcadSectionTypeSettingsImpl::GetGenerationOptions() const
{
    AcSectionGeneration val =  (AcSectionGeneration)PyAcSectionGeneration::pyacSectionGenerationDestinationFile;
    PyThrowBadHr(impObj()->get_GenerationOptions(&val));
    return (PyAcSectionGeneration)val;
}

void PyIAcadSectionTypeSettingsImpl::SetGenerationOptions(PyAcSectionGeneration val)
{
    AcSectionGeneration _val = (AcSectionGeneration)val;
    PyThrowBadHr(impObj()->put_GenerationOptions(_val));
}

IAcadSectionTypeSettings* PyIAcadSectionTypeSettingsImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadSectionTypeSettings*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadDatabasePreferencesImpl
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
//PyIAcadPreferencesFilesImpl
PyIAcadPreferencesFilesImpl::PyIAcadPreferencesFilesImpl(IAcadPreferencesFiles* ptr)
    : m_pimpl(ptr)
{
}

IAcadPreferencesFiles* PyIAcadPreferencesFilesImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadPreferencesFiles*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadPreferencesDisplayImpl
PyIAcadPreferencesDisplayImpl::PyIAcadPreferencesDisplayImpl(IAcadPreferencesDisplay* ptr)
    : m_pimpl(ptr)
{
}

IAcadPreferencesDisplay* PyIAcadPreferencesDisplayImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadPreferencesDisplay*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadPreferencesOpenSaveImpl
PyIAcadPreferencesOpenSaveImpl::PyIAcadPreferencesOpenSaveImpl(IAcadPreferencesOpenSave* ptr)
    : m_pimpl(ptr)
{
}

IAcadPreferencesOpenSave* PyIAcadPreferencesOpenSaveImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadPreferencesOpenSave*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadPreferencesOutputImpl
PyIAcadPreferencesOutputImpl::PyIAcadPreferencesOutputImpl(IAcadPreferencesOutput* ptr)
    : m_pimpl(ptr)
{
}

IAcadPreferencesOutput* PyIAcadPreferencesOutputImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadPreferencesOutput*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadPreferencesSystemImpl
PyIAcadPreferencesSystemImpl::PyIAcadPreferencesSystemImpl(IAcadPreferencesSystem* ptr)
    : m_pimpl(ptr)
{
}

IAcadPreferencesSystem* PyIAcadPreferencesSystemImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadPreferencesSystem*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadPreferencesUserImpl
PyIAcadPreferencesUserImpl::PyIAcadPreferencesUserImpl(IAcadPreferencesUser* ptr)
    : m_pimpl(ptr)
{
}

IAcadPreferencesUser* PyIAcadPreferencesUserImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadPreferencesUser*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadPreferencesDraftingImpl
PyIAcadPreferencesDraftingImpl::PyIAcadPreferencesDraftingImpl(IAcadPreferencesDrafting* ptr)
    : m_pimpl(ptr)
{
}

IAcadPreferencesDrafting* PyIAcadPreferencesDraftingImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadPreferencesDrafting*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadPreferencesSelectionImpl
PyIAcadPreferencesSelectionImpl::PyIAcadPreferencesSelectionImpl(IAcadPreferencesSelection* ptr)
    : m_pimpl(ptr)
{
}

IAcadPreferencesSelection* PyIAcadPreferencesSelectionImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadPreferencesSelection*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadPreferencesProfilesImpl
PyIAcadPreferencesProfilesImpl::PyIAcadPreferencesProfilesImpl(IAcadPreferencesProfiles* ptr)
    : m_pimpl(ptr)
{
}

IAcadPreferencesProfiles* PyIAcadPreferencesProfilesImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadPreferencesProfiles*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadPreferencesImpl
PyIAcadPreferencesImpl::PyIAcadPreferencesImpl(IAcadPreferences* ptr)
    : m_pimpl(ptr)
{
}

PyIAcadPreferencesFilesPtr PyIAcadPreferencesImpl::GetFiles() const
{
    IAcadPreferencesFiles* ptr = nullptr;
    PyThrowBadHr(impObj()->get_Files(&ptr));
    return std::make_unique<PyIAcadPreferencesFilesImpl>(ptr);
}

PyIAcadPreferencesDisplayPtr PyIAcadPreferencesImpl::GetDisplay() const
{
    IAcadPreferencesDisplay* ptr = nullptr;
    PyThrowBadHr(impObj()->get_Display(&ptr));
    return std::make_unique<PyIAcadPreferencesDisplayImpl>(ptr);
}

PyIAcadPreferencesOpenSavePtr PyIAcadPreferencesImpl::GetOpenSave() const
{
    IAcadPreferencesOpenSave* ptr = nullptr;
    PyThrowBadHr(impObj()->get_OpenSave(&ptr));
    return std::make_unique<PyIAcadPreferencesOpenSaveImpl>(ptr);
}

PyIAcadPreferencesOutputPtr PyIAcadPreferencesImpl::GetOutput() const
{
    IAcadPreferencesOutput* ptr = nullptr;
    PyThrowBadHr(impObj()->get_Output(&ptr));
    return std::make_unique<PyIAcadPreferencesOutputImpl>(ptr);
}

PyIAcadPreferencesSystemPtr PyIAcadPreferencesImpl::GetSystem() const
{
    IAcadPreferencesSystem* ptr = nullptr;
    PyThrowBadHr(impObj()->get_System(&ptr));
    return std::make_unique<PyIAcadPreferencesSystemImpl>(ptr);
}

PyIAcadPreferencesUserPtr PyIAcadPreferencesImpl::GetUser() const
{
    IAcadPreferencesUser* ptr = nullptr;
    PyThrowBadHr(impObj()->get_User(&ptr));
    return std::make_unique<PyIAcadPreferencesUserImpl>(ptr);
}

PyIAcadPreferencesDraftingPtr PyIAcadPreferencesImpl::GetDrafting() const
{
    IAcadPreferencesDrafting* ptr = nullptr;
    PyThrowBadHr(impObj()->get_Drafting(&ptr));
    return std::make_unique<PyIAcadPreferencesDraftingImpl>(ptr);
}

PyIAcadPreferencesSelectionPtr PyIAcadPreferencesImpl::GetSelection() const
{
    IAcadPreferencesSelection* ptr = nullptr;
    PyThrowBadHr(impObj()->get_Selection(&ptr));
    return std::make_unique<PyIAcadPreferencesSelectionImpl>(ptr);
}

PyIAcadPreferencesProfilesPtr PyIAcadPreferencesImpl::GetProfiles() const
{
    IAcadPreferencesProfiles* ptr = nullptr;
    PyThrowBadHr(impObj()->get_Profiles(&ptr));
    return std::make_unique<PyIAcadPreferencesProfilesImpl>(ptr);
}

IAcadPreferences* PyIAcadPreferencesImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadPreferences*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadSummaryInfoImpl
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
//PyIAcadDynamicBlockReferencePropertyImpl
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
//PyIAcadIdPairImpl
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
//PyIAcadShadowDisplayImpl
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
//PyIAcadPlotImpl
PyIAcadPlotImpl::PyIAcadPlotImpl(IAcadPlot* ptr)
    : m_pimpl(ptr)
{
}

IAcadPlot* PyIAcadPlotImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadPlot*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadMenuBarImpl
PyIAcadMenuBarImpl::PyIAcadMenuBarImpl(IAcadMenuBar* ptr)
    : m_pimpl(ptr)
{
}

IAcadMenuBar* PyIAcadMenuBarImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadMenuBar*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadMenuGroupsImpl
PyIAcadMenuGroupsImpl::PyIAcadMenuGroupsImpl(IAcadMenuGroups* ptr)
    : m_pimpl(ptr)
{
}

IAcadMenuGroups* PyIAcadMenuGroupsImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadMenuGroups*>(m_pimpl.GetInterfacePtr());
}
