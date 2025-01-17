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
    AcSectionGeneration val = (AcSectionGeneration)PyAcSectionGeneration::pyacSectionGenerationDestinationFile;
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
//PyIAcadMenuGroupImpl
PyIAcadMenuGroupImpl::PyIAcadMenuGroupImpl(IAcadMenuGroup* ptr)
    : m_pimpl(ptr)
{
}

PyIAcadMenuGroupsPtr PyIAcadMenuGroupImpl::GetParent() const
{
    IAcadMenuGroups* ptr = nullptr;
    PyThrowBadHr(impObj()->get_Parent(&ptr));
    return std::make_unique<PyIAcadMenuGroupsImpl>(ptr);
}

CString PyIAcadMenuGroupImpl::GetName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Name(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

PyAcMenuGroupType PyIAcadMenuGroupImpl::GetType() const
{
    AcMenuGroupType mtype = static_cast<AcMenuGroupType>(PyAcMenuGroupType::pyacBaseMenuGroup);
    PyThrowBadHr(impObj()->get_Type(&mtype));
    return static_cast<PyAcMenuGroupType>(mtype);
}

CString PyIAcadMenuGroupImpl::GetMenuFileName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_MenuFileName(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

PyIAcadPopupMenusPtr PyIAcadMenuGroupImpl::GetMenus() const
{
    IAcadPopupMenus* ptr = nullptr;
    PyThrowBadHr(impObj()->get_Menus(&ptr));
    return std::make_unique<PyIAcadPopupMenusImpl>(ptr);
}

PyIAcadToolbarsPtr PyIAcadMenuGroupImpl::GetToolbars() const
{
    IAcadToolbars* ptr = nullptr;
    PyThrowBadHr(impObj()->get_Toolbars(&ptr));
    return std::make_unique<PyIAcadToolbarsImpl>(ptr);
}

void PyIAcadMenuGroupImpl::Save(PyAcMenuFileType menuType)
{
    PyThrowBadHr(impObj()->Save(AcMenuFileType(menuType)));
}

void PyIAcadMenuGroupImpl::SaveAs(const CString& menuFileName, PyAcMenuFileType menuType)
{
    _bstr_t bstrmenuFileName{ menuFileName };
    PyThrowBadHr(impObj()->SaveAs(bstrmenuFileName, AcMenuFileType(menuType)));
}

void PyIAcadMenuGroupImpl::Unload()
{
    PyThrowBadHr(impObj()->Unload());
}

IAcadMenuGroup* PyIAcadMenuGroupImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadMenuGroup*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadMenuGroupsImpl
PyIAcadMenuGroupsImpl::PyIAcadMenuGroupsImpl(IAcadMenuGroups* ptr)
    : m_pimpl(ptr)
{
}

long PyIAcadMenuGroupsImpl::GetCount() const
{
    long val = 0;
    PyThrowBadHr(impObj()->get_Count(&val));
    return val;
}

PyIAcadMenuGroupPtr PyIAcadMenuGroupsImpl::GetItem(long index) const
{
    _variant_t val{ index };
    IAcadMenuGroup* ptr = nullptr;
    PyThrowBadHr(impObj()->Item(val, &ptr));
    return std::make_unique<PyIAcadMenuGroupImpl>(ptr);
}

PyIAcadMenuGroupPtr PyIAcadMenuGroupsImpl::Load(const CString& menuFileName)
{
    IAcadMenuGroup* ptr = nullptr;
    _bstr_t bstrmenuFileName{ menuFileName };
    PyThrowBadHr(impObj()->Load(bstrmenuFileName, vtMissing, &ptr));
    return std::make_unique<PyIAcadMenuGroupImpl>(ptr);
}

PyIAcadMenuGroupPtr PyIAcadMenuGroupsImpl::Load(const CString& menuFileName, const PyIAcadMenuGroupImpl& BaseMenu)
{
    IAcadMenuGroup* ptr = nullptr;
    _bstr_t bstrmenuFileName{ menuFileName };
    _variant_t vtBaseMenu{ static_cast<IDispatch*>(BaseMenu.impObj()) };
    PyThrowBadHr(impObj()->Load(bstrmenuFileName, vtBaseMenu, &ptr));
    return std::make_unique<PyIAcadMenuGroupImpl>(ptr);
}

IAcadMenuGroups* PyIAcadMenuGroupsImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadMenuGroups*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadPopupMenuItemImpl
PyIAcadPopupMenuItemImpl::PyIAcadPopupMenuItemImpl(IAcadPopupMenuItem* ptr)
    : m_pimpl(ptr)
{
}

PyIAcadPopupMenuPtr PyIAcadPopupMenuItemImpl::GetParent() const
{
    IAcadPopupMenu* ptr = nullptr;
    PyThrowBadHr(impObj()->get_Parent(&ptr));
    return std::make_unique<PyIAcadPopupMenuImpl>(ptr);
}

CString PyIAcadPopupMenuItemImpl::GetLabel() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Label(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadPopupMenuItemImpl::SetLabel(const CString& val)
{
    _bstr_t bstrVal{ val };
    PyThrowBadHr(impObj()->put_Label(bstrVal));
}

CString PyIAcadPopupMenuItemImpl::GetTagString() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_TagString(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadPopupMenuItemImpl::SetTagString(const CString& val)
{
    _bstr_t bstrVal{ val };
    PyThrowBadHr(impObj()->put_TagString(bstrVal));
}

bool PyIAcadPopupMenuItemImpl::GetEnable() const
{
    VARIANT_BOOL rtVal;
    PyThrowBadHr(impObj()->get_Enable(&rtVal));
    return rtVal == VARIANT_TRUE;
}

void PyIAcadPopupMenuItemImpl::SetEnable(bool val)
{
    VARIANT_BOOL rtVal = val ? 1 : 0;
    PyThrowBadHr(impObj()->put_Enable(rtVal));
}

bool PyIAcadPopupMenuItemImpl::GetCheck() const
{
    VARIANT_BOOL rtVal;
    PyThrowBadHr(impObj()->get_Check(&rtVal));
    return rtVal == VARIANT_TRUE;
}

void PyIAcadPopupMenuItemImpl::SetCheck(bool val)
{
    VARIANT_BOOL rtVal = val ? 1 : 0;
    PyThrowBadHr(impObj()->put_Enable(rtVal));
}

PyAcMenuItemType PyIAcadPopupMenuItemImpl::GetType() const
{
    AcMenuItemType val = (AcMenuItemType)PyAcMenuItemType::pyacMenuItem;
    PyThrowBadHr(impObj()->get_Type(&val));
    return (PyAcMenuItemType)val;
}

PyIAcadPopupMenuPtr PyIAcadPopupMenuItemImpl::GetSubMenu() const
{
    IAcadPopupMenu* ptr = nullptr;
    PyThrowBadHr(impObj()->get_SubMenu(&ptr));
    return std::make_unique<PyIAcadPopupMenuImpl>(ptr);
}

CString PyIAcadPopupMenuItemImpl::GetMacro() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Macro(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadPopupMenuItemImpl::SetMacro(const CString& val)
{
    _bstr_t bstrVal{ val };
    PyThrowBadHr(impObj()->put_Macro(bstrVal));
}

int PyIAcadPopupMenuItemImpl::GetIndex() const
{
    int idx = 0;
    PyThrowBadHr(impObj()->get_Index(&idx));
    return idx;
}

CString PyIAcadPopupMenuItemImpl::GetCaption() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Caption(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

CString PyIAcadPopupMenuItemImpl::GetHelpString() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_HelpString(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadPopupMenuItemImpl::SetHelpString(const CString& val)
{
    _bstr_t bstrVal{ val };
    PyThrowBadHr(impObj()->put_HelpString(bstrVal));
}

void PyIAcadPopupMenuItemImpl::Delete()
{
    PyThrowBadHr(impObj()->Delete());
}

int PyIAcadPopupMenuItemImpl::GetEndSubMenuLevel() const
{
    int idx = 0;
    PyThrowBadHr(impObj()->get_EndSubMenuLevel(&idx));
    return idx;
}

void PyIAcadPopupMenuItemImpl::SetEndSubMenuLevel(int idx) const
{
    PyThrowBadHr(impObj()->put_EndSubMenuLevel(idx));
}

IAcadPopupMenuItem* PyIAcadPopupMenuItemImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadPopupMenuItem*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadPopupMenuImpl
PyIAcadPopupMenuImpl::PyIAcadPopupMenuImpl(IAcadPopupMenu* ptr)
    : m_pimpl(ptr)
{
}

long PyIAcadPopupMenuImpl::GetCount() const
{
    long index = 0;
    PyThrowBadHr(impObj()->get_Count(&index));
    return index;
}

PyIAcadPopupMenuItemPtr PyIAcadPopupMenuImpl::GetItem(long index) const
{
    _variant_t val{ index };
    IAcadPopupMenuItem* ptr = nullptr;
    PyThrowBadHr(impObj()->Item(val, &ptr));
    return std::make_unique<PyIAcadPopupMenuItemImpl>(ptr);
}

PyIAcadPopupMenusPtr PyIAcadPopupMenuImpl::GetParent() const
{
    IDispatch* ptr = nullptr;
    PyThrowBadHr(impObj()->get_Parent(&ptr));
    return std::make_unique<PyIAcadPopupMenusImpl>((IAcadPopupMenus*)ptr);
}

CString PyIAcadPopupMenuImpl::GetName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Name(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadPopupMenuImpl::SetName(const CString& val)
{
    _bstr_t bstrVal{ val };
    PyThrowBadHr(impObj()->put_Name(bstrVal));
}

CString PyIAcadPopupMenuImpl::GetNameNoMnemonic() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_NameNoMnemonic(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

bool PyIAcadPopupMenuImpl::GetShortcutMenu() const
{
    VARIANT_BOOL rtVal;
    PyThrowBadHr(impObj()->get_ShortcutMenu(&rtVal));
    return rtVal == VARIANT_TRUE;
}

bool PyIAcadPopupMenuImpl::GetOnMenuBar() const
{
    VARIANT_BOOL rtVal;
    PyThrowBadHr(impObj()->get_OnMenuBar(&rtVal));
    return rtVal == VARIANT_TRUE;
}

PyIAcadPopupMenuItemPtr PyIAcadPopupMenuImpl::AddMenuItem(long index, const CString& label, const CString& macro)
{
    _variant_t vtindex{ index };
    _bstr_t bstrlabel{ label };
    _bstr_t bstrmacro{ macro };
    IAcadPopupMenuItem* ptr;
    PyThrowBadHr(impObj()->AddMenuItem(vtindex, bstrlabel, bstrmacro, &ptr));
    return std::make_unique<PyIAcadPopupMenuItemImpl>(ptr);

}

PyIAcadPopupMenuPtr PyIAcadPopupMenuImpl::AddSubMenu(long index, const CString& label)
{
    _variant_t vtindex{ index };
    _bstr_t bstrlabel{ label };
    IAcadPopupMenu* ptr;
    PyThrowBadHr(impObj()->AddSubMenu(vtindex, bstrlabel, &ptr));
    return std::make_unique<PyIAcadPopupMenuImpl>(ptr);
}

PyIAcadPopupMenuItemPtr PyIAcadPopupMenuImpl::AddSeparator(long index) const
{
    _variant_t vtindex{ index };
    IAcadPopupMenuItem* ptr;
    PyThrowBadHr(impObj()->AddSeparator(vtindex, &ptr));
    return std::make_unique<PyIAcadPopupMenuItemImpl>(ptr);
}

void PyIAcadPopupMenuImpl::InsertInMenuBar(long index) const
{
    _variant_t vtindex{ index };
    PyThrowBadHr(impObj()->InsertInMenuBar(vtindex));
}

void PyIAcadPopupMenuImpl::RemoveFromMenuBar() const
{
    PyThrowBadHr(impObj()->RemoveFromMenuBar());
}

CString PyIAcadPopupMenuImpl::GetTagString() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_TagString(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

IAcadPopupMenu* PyIAcadPopupMenuImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadPopupMenu*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadPopupMenusImpl
PyIAcadPopupMenusImpl::PyIAcadPopupMenusImpl(IAcadPopupMenus* ptr)
    : m_pimpl(ptr)
{
}

long PyIAcadPopupMenusImpl::GetCount() const
{
    long index = 0;
    PyThrowBadHr(impObj()->get_Count(&index));
    return index;
}

PyIAcadPopupMenuPtr PyIAcadPopupMenusImpl::GetItem(long index) const
{
    _variant_t val{ index };
    IAcadPopupMenu* ptr = nullptr;
    PyThrowBadHr(impObj()->Item(val, &ptr));
    return std::make_unique<PyIAcadPopupMenuImpl>(ptr);
}

PyIAcadMenuGroupPtr PyIAcadPopupMenusImpl::GetParent() const
{
    IAcadMenuGroup* ptr = nullptr;
    PyThrowBadHr(impObj()->get_Parent(&ptr));
    return std::make_unique<PyIAcadMenuGroupImpl>(ptr);
}

PyIAcadPopupMenuPtr PyIAcadPopupMenusImpl::Add(const CString& toolbarName)
{
    _bstr_t bstrVal{ toolbarName };
    IAcadPopupMenu* ptr = nullptr;
    PyThrowBadHr(impObj()->Add(bstrVal, &ptr));
    return std::make_unique<PyIAcadPopupMenuImpl>(ptr);
}

void PyIAcadPopupMenusImpl::InsertMenuInMenuBar(const CString& menuName, long index)
{
    _bstr_t bstrVal{ menuName };
    _variant_t vtindex{ index };
    PyThrowBadHr(impObj()->InsertMenuInMenuBar(bstrVal, vtindex));
}

void PyIAcadPopupMenusImpl::RemoveMenuFromMenuBar(long index)
{
    _variant_t vtindex{ index };
    PyThrowBadHr(impObj()->RemoveMenuFromMenuBar(vtindex));
}

IAcadPopupMenus* PyIAcadPopupMenusImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadPopupMenus*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadToolbarItemImpl
PyIAcadToolbarItemImpl::PyIAcadToolbarItemImpl(IAcadToolbarItem* ptr)
    : m_pimpl(ptr)
{
}

PyIAcadToolbarPtr PyIAcadToolbarItemImpl::GetParent() const
{
    IAcadToolbar* ptr = nullptr;
    PyThrowBadHr(impObj()->get_Parent(&ptr));
    return std::make_unique<PyIAcadToolbarImpl>(ptr);
}

CString PyIAcadToolbarItemImpl::GetName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Name(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadToolbarItemImpl::SetName(const CString& val)
{
    _bstr_t bstrVal{ val };
    PyThrowBadHr(impObj()->put_Name(bstrVal));
}

CString PyIAcadToolbarItemImpl::GetTagString() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_TagString(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadToolbarItemImpl::SetTagString(const CString& val)
{
    _bstr_t bstrVal{ val };
    PyThrowBadHr(impObj()->put_TagString(bstrVal));
}

PyAcToolbarItemType PyIAcadToolbarItemImpl::GetType() const
{
    AcToolbarItemType val = static_cast<AcToolbarItemType>(PyAcToolbarItemType::pyacToolbarButton);
    PyThrowBadHr(impObj()->get_Type(&val));
    return static_cast<PyAcToolbarItemType>(val);
}

CString PyIAcadToolbarItemImpl::GetMacro() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Macro(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadToolbarItemImpl::SetMacro(const CString& val)
{
    _bstr_t bstrVal{ val };
    PyThrowBadHr(impObj()->put_Macro(bstrVal));
}

int PyIAcadToolbarItemImpl::GetIndex() const
{
    int index = 0;
    PyThrowBadHr(impObj()->get_Index(&index));
    return index;
}

CString PyIAcadToolbarItemImpl::GetHelpString() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_HelpString(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadToolbarItemImpl::SetHelpString(const CString& val) const
{
    _bstr_t bstrVal{ val };
    PyThrowBadHr(impObj()->put_HelpString(bstrVal));
}

std::pair<CString, CString> PyIAcadToolbarItemImpl::GetBitmaps() const
{
    _bstr_t bstrSmallIconName;
    _bstr_t bstrLargeIconName;
    PyThrowBadHr(impObj()->GetBitmaps(&bstrSmallIconName.GetBSTR(), &bstrLargeIconName.GetBSTR()));
    return { CString{(LPCTSTR)bstrSmallIconName}, CString{(LPCTSTR)bstrLargeIconName} };
}

void PyIAcadToolbarItemImpl::SetBitmaps(const CString& smallIconName, const CString& largeIconName)
{
    _bstr_t bstrsmallIconName{ smallIconName };
    _bstr_t bstrslargeIconName{ largeIconName };
    PyThrowBadHr(impObj()->SetBitmaps(bstrsmallIconName, bstrslargeIconName));
}

void PyIAcadToolbarItemImpl::AttachToolbarToFlyout(const CString& menuGroupName, const CString& toolbarName)
{
    _bstr_t bstrmenuGroupName{ menuGroupName };
    _bstr_t bstrtoolbarName{ toolbarName };
    PyThrowBadHr(impObj()->AttachToolbarToFlyout(bstrmenuGroupName, bstrtoolbarName));
}

void PyIAcadToolbarItemImpl::Delete()
{
    PyThrowBadHr(impObj()->Delete());
}

CString PyIAcadToolbarItemImpl::GetCommandDisplayName() const
{
#if defined(_BRXTARGET)
    throw PyNotimplementedByHost();
#else
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_CommandDisplayName(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
#endif
}

void PyIAcadToolbarItemImpl::SetCommandDisplayName(const CString& val)
{
#if defined(_BRXTARGET)
    throw PyNotimplementedByHost();
#else
    _bstr_t bstrVal{ val };
    PyThrowBadHr(impObj()->put_CommandDisplayName(bstrVal));
#endif
}

IAcadToolbarItem* PyIAcadToolbarItemImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadToolbarItem*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadToolbarImpl
PyIAcadToolbarImpl::PyIAcadToolbarImpl(IAcadToolbar* ptr)
    : m_pimpl(ptr)
{
}

long PyIAcadToolbarImpl::GetCount() const
{
    long val = 0;
    PyThrowBadHr(impObj()->get_Count(&val));
    return val;
}

PyIAcadToolbarItemPtr PyIAcadToolbarImpl::GetItem(long index) const
{
    _variant_t val{ index };
    IAcadToolbarItem* ptr = nullptr;
    PyThrowBadHr(impObj()->Item(val, &ptr));
    return std::make_unique<PyIAcadToolbarItemImpl>(ptr);
}

PyIAcadToolbarsPtr PyIAcadToolbarImpl::GetParent() const
{
    IDispatch* ptr = nullptr;
    PyThrowBadHr(impObj()->get_Parent(&ptr));
    return std::make_unique<PyIAcadToolbarsImpl>(static_cast<IAcadToolbars*>(ptr));
}

CString PyIAcadToolbarImpl::GetName() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_Name(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadToolbarImpl::SetName(const CString& name)
{
    _bstr_t bstrVal{ name };
    PyThrowBadHr(impObj()->put_Name(bstrVal));
}

bool PyIAcadToolbarImpl::GetVisible() const
{
    VARIANT_BOOL rtVal;
    PyThrowBadHr(impObj()->get_Visible(&rtVal));
    return rtVal == VARIANT_TRUE;
}

void PyIAcadToolbarImpl::SetVisible(bool val)
{
    VARIANT_BOOL rtVal = val ? 1 : 0;
    PyThrowBadHr(impObj()->put_Visible(rtVal));
}

PyAcToolbarDockStatus PyIAcadToolbarImpl::GetDockStatus() const
{
    AcToolbarDockStatus rtVal = AcToolbarDockStatus(PyAcToolbarDockStatus::pyacToolbarDockBottom);
    PyThrowBadHr(impObj()->get_DockStatus(&rtVal));
    return static_cast<PyAcToolbarDockStatus>(rtVal);
}

bool PyIAcadToolbarImpl::GetLargeButtons() const
{
    VARIANT_BOOL rtVal;
    PyThrowBadHr(impObj()->get_LargeButtons(&rtVal));
    return rtVal == VARIANT_TRUE;
}

int PyIAcadToolbarImpl::GetLeft() const
{
    int rtVal = 0;
    PyThrowBadHr(impObj()->get_left(&rtVal));
    return rtVal;
}

void PyIAcadToolbarImpl::SetLeft(int val)
{
    PyThrowBadHr(impObj()->put_left(val));
}

int PyIAcadToolbarImpl::GetTop() const
{
    int rtVal = 0;
    PyThrowBadHr(impObj()->get_top(&rtVal));
    return rtVal;
}

void PyIAcadToolbarImpl::SetTop(int val)
{
    PyThrowBadHr(impObj()->put_top(val));
}

int PyIAcadToolbarImpl::GetWidth() const
{
    int rtVal = 0;
    PyThrowBadHr(impObj()->get_Width(&rtVal));
    return rtVal;
}

int PyIAcadToolbarImpl::GetHeight() const
{
    int rtVal = 0;
    PyThrowBadHr(impObj()->get_Height(&rtVal));
    return rtVal;
}

int PyIAcadToolbarImpl::GetFloatingRows() const
{
    int rtVal = 0;
    PyThrowBadHr(impObj()->get_FloatingRows(&rtVal));
    return rtVal;
}

void PyIAcadToolbarImpl::SetFloatingRows(int val)
{
    PyThrowBadHr(impObj()->put_FloatingRows(val));
}

CString PyIAcadToolbarImpl::GetHelpString() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_HelpString(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

void PyIAcadToolbarImpl::SetHelpString(const CString& val) const
{
    _bstr_t bstrVal{ val };
    PyThrowBadHr(impObj()->put_HelpString(bstrVal));
}

PyIAcadToolbarItemPtr PyIAcadToolbarImpl::AddToolbarButton(int index, const CString& name, const CString& helpstr, const CString& macro, bool flyoutButton)
{
    _variant_t vtindex{ index };
    _bstr_t bstrname{ name };
    _bstr_t bstrhelpstr{ helpstr };
    _bstr_t bstrmacro{ macro };
    _variant_t vtflyoutButton{ flyoutButton };
    IAcadToolbarItem* ptr = nullptr;
    PyThrowBadHr(impObj()->AddToolbarButton(vtindex, bstrname, bstrhelpstr, bstrmacro, vtflyoutButton, &ptr));
    return std::make_unique<PyIAcadToolbarItemImpl>(ptr);
}

void PyIAcadToolbarImpl::Dock(PyAcToolbarDockStatus val)
{
    PyThrowBadHr(impObj()->Dock((AcToolbarDockStatus)val));
}

void PyIAcadToolbarImpl::Float(int top, int teft, int numberFloatRows)
{
    PyThrowBadHr(impObj()->Float(top, teft, numberFloatRows));
}

void PyIAcadToolbarImpl::Delete()
{
    PyThrowBadHr(impObj()->Delete());
}

CString PyIAcadToolbarImpl::GetTagString() const
{
    _bstr_t bstrVal;
    PyThrowBadHr(impObj()->get_TagString(&bstrVal.GetBSTR()));
    return (LPCTSTR)bstrVal;
}

IAcadToolbar* PyIAcadToolbarImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadToolbar*>(m_pimpl.GetInterfacePtr());
}

//------------------------------------------------------------------------------------
//PyIAcadToolbarsImpl
PyIAcadToolbarsImpl::PyIAcadToolbarsImpl(IAcadToolbars* ptr)
    : m_pimpl(ptr)
{
}

long PyIAcadToolbarsImpl::GetCount() const
{
    long val = 0;
    PyThrowBadHr(impObj()->get_Count(&val));
    return val;
}

PyIAcadToolbarPtr PyIAcadToolbarsImpl::GetItem(long index) const
{
    _variant_t val{ index };
    IAcadToolbar* ptr = nullptr;
    PyThrowBadHr(impObj()->Item(val, &ptr));
    return std::make_unique<PyIAcadToolbarImpl>(ptr);
}

PyIAcadMenuGroupPtr PyIAcadToolbarsImpl::GetParent() const
{
    IAcadMenuGroup* ptr = nullptr;
    PyThrowBadHr(impObj()->get_Parent(&ptr));
    return std::make_unique<PyIAcadMenuGroupImpl>(ptr);
}

bool PyIAcadToolbarsImpl::GetLargeButtons() const
{
    VARIANT_BOOL rtVal;
    PyThrowBadHr(impObj()->get_LargeButtons(&rtVal));
    return rtVal == VARIANT_TRUE;
}

void PyIAcadToolbarsImpl::SetLargeButtons(bool val) const
{
    VARIANT_BOOL rtVal = val ? 1 : 0;
    PyThrowBadHr(impObj()->put_LargeButtons(rtVal));
}

PyIAcadToolbarPtr PyIAcadToolbarsImpl::Add(const CString& toolbarName)
{
    _bstr_t bstrtoolbarName{ toolbarName };
    IAcadToolbar* ptr = nullptr;
    PyThrowBadHr(impObj()->Add(bstrtoolbarName, &ptr));
    return std::make_unique<PyIAcadToolbarImpl>(ptr);
}

IAcadToolbars* PyIAcadToolbarsImpl::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pimpl == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<IAcadToolbars*>(m_pimpl.GetInterfacePtr());
}
