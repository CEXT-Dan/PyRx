#pragma once

#pragma pack (push, 8)

class PyIAcadAcCmColorImpl;
class PyIAcadHyperlinkImpl;
class PyIAcadHyperlinksImpl;
class PyIAcadSectionTypeSettingsImpl;
class PyIAcadDatabasePreferencesImpl;
class PyIAcadPreferencesFilesImpl;
class PyIAcadPreferencesDisplayImpl;
class PyIAcadPreferencesOpenSaveImpl;
class PyIAcadPreferencesOutputImpl;
class PyIAcadPreferencesSystemImpl;
class PyIAcadPreferencesUserImpl;
class PyIAcadPreferencesDraftingImpl;
class PyIAcadPreferencesSelectionImpl;
class PyIAcadPreferencesProfilesImpl;
class PyIAcadPreferencesImpl;
class PyIAcadSummaryInfoImpl;
class PyIAcadDynamicBlockReferencePropertyImpl;
class PyIAcadIdPairImpl;
#ifndef _BRXTARGET
class PyIAcadShadowDisplayImpl;
#endif
class PyIAcadPlotImpl;
class PyIAcadMenuBarImpl;
class PyIAcadMenuGroupImpl;
class PyIAcadMenuGroupsImpl;
class PyIAcadPopupMenuItemImpl;
class PyIAcadPopupMenuImpl;
class PyIAcadPopupMenusImpl;
class PyIAcadToolbarItemImpl;
class PyIAcadToolbarImpl;
class PyIAcadToolbarsImpl;

//----------------------------------------------------------------------------------------
//PyAcadAcCmColor
void makePyAcadAcCmColorWrapper();

class PyAcadAcCmColor
{
public:
    PyAcadAcCmColor(PyIAcadAcCmColorImpl* ptr);
    virtual ~PyAcadAcCmColor() = default;
    static std::string  className();
public:
    PyIAcadAcCmColorImpl* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    std::shared_ptr<PyIAcadAcCmColorImpl> m_pyImp;
};

//----------------------------------------------------------------------------------------
//PyAcadHyperlink
void makePyAcadHyperlinkWrapper();

class PyAcadHyperlink
{
public:
    PyAcadHyperlink(PyIAcadHyperlinkImpl* ptr);
    virtual ~PyAcadHyperlink() = default;
    static std::string  className();
public:
    PyIAcadHyperlinkImpl* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    std::shared_ptr<PyIAcadHyperlinkImpl> m_pyImp;
};

//----------------------------------------------------------------------------------------
//PyAcadHyperlinks
void makePyAcadHyperlinksWrapper();

class PyAcadHyperlinks
{
public:
    PyAcadHyperlinks(PyIAcadHyperlinksImpl* ptr);
    virtual ~PyAcadHyperlinks() = default;
    static std::string  className();
public:
    PyIAcadHyperlinksImpl* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    std::shared_ptr<PyIAcadHyperlinksImpl> m_pyImp;
};

//----------------------------------------------------------------------------------------
//PyAcadSectionTypeSettings
void makePyAcadSectionTypeSettingsWrapper();

class PyAcadSectionTypeSettings
{
public:
    PyAcadSectionTypeSettings(PyIAcadSectionTypeSettingsImpl* ptr);
    virtual ~PyAcadSectionTypeSettings() = default;
    static std::string  className();
public:
    PyIAcadSectionTypeSettingsImpl* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    std::shared_ptr<PyIAcadSectionTypeSettingsImpl> m_pyImp;
};

//----------------------------------------------------------------------------------------
//PyAcadDatabasePreferences
void makePyAcadDatabasePreferencesWrapper();

class PyAcadDatabasePreferences
{
public:
    PyAcadDatabasePreferences(PyIAcadDatabasePreferencesImpl* ptr);
    virtual ~PyAcadDatabasePreferences() = default;
    static std::string  className();
public:
    PyIAcadDatabasePreferencesImpl* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    std::shared_ptr<PyIAcadDatabasePreferencesImpl> m_pyImp;
};

//----------------------------------------------------------------------------------------
//PyAcadPreferencesFiles
void makePyAcadPreferencesFilesWrapper();

class PyAcadPreferencesFiles
{
public:
    PyAcadPreferencesFiles(PyIAcadPreferencesFilesImpl* ptr);
    virtual ~PyAcadPreferencesFiles() = default;
    static std::string  className();
public:
    PyIAcadPreferencesFilesImpl* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    std::shared_ptr<PyIAcadPreferencesFilesImpl> m_pyImp;
};

//----------------------------------------------------------------------------------------
//PyAcadPreferencesDisplay
void makePyAcadPreferencesDisplayWrapper();

class PyAcadPreferencesDisplay
{
public:
    PyAcadPreferencesDisplay(PyIAcadPreferencesDisplayImpl* ptr);
    virtual ~PyAcadPreferencesDisplay() = default;
    static std::string  className();
public:
    PyIAcadPreferencesDisplayImpl* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    std::shared_ptr<PyIAcadPreferencesDisplayImpl> m_pyImp;
};

//----------------------------------------------------------------------------------------
//PyAcadPreferencesOpenSave
void makePyAcadPreferencesOpenSaveWrapper();

class PyAcadPreferencesOpenSave
{
public:
    PyAcadPreferencesOpenSave(PyIAcadPreferencesOpenSaveImpl* ptr);
    virtual ~PyAcadPreferencesOpenSave() = default;
    static std::string  className();
public:
    PyIAcadPreferencesOpenSaveImpl* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    std::shared_ptr<PyIAcadPreferencesOpenSaveImpl> m_pyImp;
};

//----------------------------------------------------------------------------------------
//PyAcadPreferencesOutput
void makePyAcadPreferencesOutputWrapper();

class PyAcadPreferencesOutput
{
public:
    PyAcadPreferencesOutput(PyIAcadPreferencesOutputImpl* ptr);
    virtual ~PyAcadPreferencesOutput() = default;
    static std::string  className();
public:
    PyIAcadPreferencesOutputImpl* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    std::shared_ptr<PyIAcadPreferencesOutputImpl> m_pyImp;
};

//----------------------------------------------------------------------------------------
//PyAcadPreferencesSystem
void makePyAcadPreferencesSystemWrapper();

class PyAcadPreferencesSystem
{
public:
    PyAcadPreferencesSystem(PyIAcadPreferencesSystemImpl* ptr);
    virtual ~PyAcadPreferencesSystem() = default;
    static std::string  className();
public:
    PyIAcadPreferencesSystemImpl* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    std::shared_ptr<PyIAcadPreferencesSystemImpl> m_pyImp;
};

//----------------------------------------------------------------------------------------
//PyAcadPreferencesUser
void makePyAcadPreferencesUserWrapper();

class PyAcadPreferencesUser
{
public:
    PyAcadPreferencesUser(PyIAcadPreferencesUserImpl* ptr);
    virtual ~PyAcadPreferencesUser() = default;
    static std::string  className();
public:
    PyIAcadPreferencesUserImpl* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    std::shared_ptr<PyIAcadPreferencesUserImpl> m_pyImp;
};

//----------------------------------------------------------------------------------------
//PyAcadPreferencesDrafting
void makePyAcadPreferencesDraftingWrapper();

class PyAcadPreferencesDrafting
{
public:
    PyAcadPreferencesDrafting(PyIAcadPreferencesDraftingImpl* ptr);
    virtual ~PyAcadPreferencesDrafting() = default;
    static std::string  className();
public:
    PyIAcadPreferencesDraftingImpl* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    std::shared_ptr<PyIAcadPreferencesDraftingImpl> m_pyImp;
};

//----------------------------------------------------------------------------------------
//PyAcadPreferencesSelection
void makePyAcadPreferencesSelectionWrapper();

class PyAcadPreferencesSelection
{
public:
    PyAcadPreferencesSelection(PyIAcadPreferencesSelectionImpl* ptr);
    virtual ~PyAcadPreferencesSelection() = default;
    static std::string  className();
public:
    PyIAcadPreferencesSelectionImpl* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    std::shared_ptr<PyIAcadPreferencesSelectionImpl> m_pyImp;
};

//----------------------------------------------------------------------------------------
//PyAcadPreferencesProfiles
void makePyAcadPreferencesProfilesWrapper();

class PyAcadPreferencesProfiles
{
public:
    PyAcadPreferencesProfiles(PyIAcadPreferencesProfilesImpl* ptr);
    virtual ~PyAcadPreferencesProfiles() = default;
    static std::string  className();
public:
    PyIAcadPreferencesProfilesImpl* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    std::shared_ptr<PyIAcadPreferencesProfilesImpl> m_pyImp;
};

//----------------------------------------------------------------------------------------
//PyAcadPreferences
void makePyAcadPreferencesWrapper();

class PyAcadPreferences
{
public:
    PyAcadPreferences(PyIAcadPreferencesImpl* ptr);
    virtual ~PyAcadPreferences() = default;
    static std::string  className();
public:
    PyIAcadPreferencesImpl* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    std::shared_ptr<PyIAcadPreferencesImpl> m_pyImp;
};

//----------------------------------------------------------------------------------------
//PyAcadSummaryInfo
void makePyAcadSummaryInfoWrapper();

class PyAcadSummaryInfo
{
public:
    PyAcadSummaryInfo(PyIAcadSummaryInfoImpl* ptr);
    virtual ~PyAcadSummaryInfo() = default;
    static std::string  className();
public:
    PyIAcadSummaryInfoImpl* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    std::shared_ptr<PyIAcadSummaryInfoImpl> m_pyImp;
};

//----------------------------------------------------------------------------------------
//PyAcadDynamicBlockReferenceProperty
void makePyAcadDynamicBlockReferencePropertyWrapper();

class PyAcadDynamicBlockReferenceProperty
{
public:
    PyAcadDynamicBlockReferenceProperty(PyIAcadDynamicBlockReferencePropertyImpl* ptr);
    virtual ~PyAcadDynamicBlockReferenceProperty() = default;
    static std::string  className();
public:
    PyIAcadDynamicBlockReferencePropertyImpl* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    std::shared_ptr<PyIAcadDynamicBlockReferencePropertyImpl> m_pyImp;
};

//----------------------------------------------------------------------------------------
//PyAcadIdPair
void makePyAcadIdPairWrapper();

class PyAcadIdPair
{
public:
    PyAcadIdPair(PyIAcadIdPairImpl* ptr);
    virtual ~PyAcadIdPair() = default;
    static std::string  className();
public:
    PyIAcadIdPairImpl* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    std::shared_ptr<PyIAcadIdPairImpl> m_pyImp;
};

//----------------------------------------------------------------------------------------
//PyAcadShadowDisplay
#ifndef _BRXTARGET
void makePyAcadShadowDisplayWrapper();

class PyAcadShadowDisplay
{
public:
    PyAcadShadowDisplay(PyIAcadShadowDisplayImpl* ptr);
    virtual ~PyAcadShadowDisplay() = default;
    static std::string  className();
public:
    PyIAcadShadowDisplayImpl* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    std::shared_ptr<PyIAcadShadowDisplayImpl> m_pyImp;
};
#endif

//----------------------------------------------------------------------------------------
//PyAcadPlot
void makePyAcadPlotWrapper();

class PyAcadPlot
{
public:
    PyAcadPlot(PyIAcadPlotImpl* ptr);
    virtual ~PyAcadPlot() = default;
    static std::string  className();
public:
    PyIAcadPlotImpl* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    std::shared_ptr<PyIAcadPlotImpl> m_pyImp;
};

//----------------------------------------------------------------------------------------
//PyAcadMenuBar
void makePyAcadMenuBarWrapper();

class PyAcadMenuBar
{
public:
    PyAcadMenuBar(std::shared_ptr<PyIAcadMenuBarImpl> ptr);
    virtual ~PyAcadMenuBar() = default;
    static std::string  className();
public:
    PyIAcadMenuBarImpl* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    std::shared_ptr<PyIAcadMenuBarImpl> m_pyImp;
};

//----------------------------------------------------------------------------------------
//PyAcadMenuGroup
void makePyAcadMenuGroupWrapper();

class PyAcadMenuGroup
{
public:
    PyAcadMenuGroup(std::shared_ptr<PyIAcadMenuGroupImpl> ptr);
    virtual ~PyAcadMenuGroup() = default;
    static std::string  className();
public:
    PyIAcadMenuGroupImpl* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    std::shared_ptr<PyIAcadMenuGroupImpl> m_pyImp;
};

//----------------------------------------------------------------------------------------
//PyAcadMenuGroups
void makePyAcadMenuGroupsWrapper();

class PyAcadMenuGroups
{
public:
    PyAcadMenuGroups(std::shared_ptr<PyIAcadMenuGroupsImpl> ptr);
    virtual ~PyAcadMenuGroups() = default;
    static std::string  className();
public:
    PyIAcadMenuGroupsImpl* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    std::shared_ptr<PyIAcadMenuGroupsImpl> m_pyImp;
};

//----------------------------------------------------------------------------------------
//PyAcadPopupMenuItem
void makePyAcadPopupMenuItemWrapper();

class PyAcadPopupMenuItem
{
public:
    PyAcadPopupMenuItem(std::shared_ptr<PyIAcadPopupMenuItemImpl> ptr);
    virtual ~PyAcadPopupMenuItem() = default;
    static std::string  className();
public:
    PyIAcadPopupMenuItemImpl* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    std::shared_ptr<PyIAcadPopupMenuItemImpl> m_pyImp;
};

//----------------------------------------------------------------------------------------
//PyAcadPopupMenu
void makePyAcadPopupMenuWrapper();

class PyAcadPopupMenu
{
public:
    PyAcadPopupMenu(std::shared_ptr<PyIAcadPopupMenuImpl> ptr);
    virtual ~PyAcadPopupMenu() = default;
    static std::string  className();
public:
    PyIAcadPopupMenuImpl* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    std::shared_ptr<PyIAcadPopupMenuImpl> m_pyImp;
};

//----------------------------------------------------------------------------------------
//PyAcadPopupMenus
void makePyAcadPopupMenusWrapper();

class PyAcadPopupMenus
{
public:
    PyAcadPopupMenus(std::shared_ptr<PyIAcadPopupMenusImpl> ptr);
    virtual ~PyAcadPopupMenus() = default;
    static std::string  className();
public:
    PyIAcadPopupMenusImpl* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    std::shared_ptr<PyIAcadPopupMenusImpl> m_pyImp;
};

//----------------------------------------------------------------------------------------
//PyAcadToolbarItem
void makePyAcadToolbarItemWrapper();

class PyAcadToolbarItem
{
public:
    PyAcadToolbarItem(std::shared_ptr<PyIAcadToolbarItemImpl> ptr);
    virtual ~PyAcadToolbarItem() = default;
    static std::string  className();
public:
    PyIAcadToolbarItemImpl* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    std::shared_ptr<PyIAcadToolbarItemImpl> m_pyImp;
};

//----------------------------------------------------------------------------------------
//PyAcadToolbar
void makePyAcadToolbarWrapper();

class PyAcadToolbar
{
public:
    PyAcadToolbar(std::shared_ptr<PyIAcadToolbarImpl> ptr);
    virtual ~PyAcadToolbar() = default;
    static std::string  className();
public:
    PyIAcadToolbarImpl* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    std::shared_ptr<PyIAcadToolbarImpl> m_pyImp;
};

//----------------------------------------------------------------------------------------
//PyAcadToolbars
void makePyAcadToolbarsWrapper();

class PyAcadToolbars
{
public:
    PyAcadToolbars(std::shared_ptr<PyIAcadToolbarsImpl> ptr);
    virtual ~PyAcadToolbars() = default;
    static std::string  className();
public:
    PyIAcadToolbarsImpl* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    std::shared_ptr<PyIAcadToolbarsImpl> m_pyImp;
};






#pragma pack (pop)