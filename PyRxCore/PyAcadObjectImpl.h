#pragma once
#include "PyAcad.h" 
#include "atlsafe.h"
#include "propvarutil.h"

#pragma pack (push, 8)

class PyIAcadMenuGroupsImpl;
using PyIAcadMenuGroupsPtr = std::unique_ptr<PyIAcadMenuGroupsImpl>;
class PyIAcadPopupMenuImpl;
using PyIAcadPopupMenuPtr = std::unique_ptr<PyIAcadPopupMenuImpl>;
class PyIAcadPopupMenusImpl;
using PyIAcadPopupMenusPtr = std::unique_ptr<PyIAcadPopupMenusImpl>;
class PyIAcadToolbarsImpl;
using PyIAcadToolbarsPtr = std::unique_ptr<PyIAcadToolbarsImpl>;

//------------------------------------------------------------------------------------
//PyIAcadAcCmColorImpl
class PyIAcadAcCmColorImpl
{
public:
    explicit PyIAcadAcCmColorImpl(IAcadAcCmColor* ptr);
    virtual ~PyIAcadAcCmColorImpl() = default;
    void            SetEntityColor(long val);
    long            GetEntityColor() const;
    CString         GetColorName() const;
    CString         GetBookName() const;
    void            SetNames(const CString& colorName, const CString& bookName);
    void            Delete();
    long            GetRed() const;
    long            GetGreen() const;
    long            GetBlue() const;
    void            SetRGB(long Red, long Green, long Blue);
    PyAcColorMethod GetColorMethod() const;
    void            SetColorMethod(PyAcColorMethod flags);
    PyAcColor       GetColorIndex() const;
    void            SetColorIndex(PyAcColor val);
    void            SetColorBookColor(const CString& colorName, const CString& bookName);
    IAcadAcCmColor* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadAcCmColorPtr m_pimpl;
};

//------------------------------------------------------------------------------------
//PyIAcadHyperlinkImpl
class PyIAcadHyperlinkImpl
{
public:
    explicit PyIAcadHyperlinkImpl(IAcadHyperlink* ptr);
    virtual ~PyIAcadHyperlinkImpl() = default;
    CString         GetURL() const;
    void            SetURL(const CString& val);
    CString         GetURLDescription() const;
    void            SetURLDescription(const CString& val);
    void            Delete();
    CString         GetURLNamedLocation() const;
    void            SetURLNamedLocation(const CString& val);
    IAcadHyperlink* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadHyperlinkPtr m_pimpl;
};

//------------------------------------------------------------------------------------
//PyIAcadHyperlinksImpl
class PyIAcadHyperlinksImpl
{
public:
    explicit PyIAcadHyperlinksImpl(IAcadHyperlinks* ptr);
    virtual ~PyIAcadHyperlinksImpl() = default;
    PyIAcadHyperlinkImpl    GetItem(long val);
    long                    GetCount() const;
    PyIAcadHyperlinkImpl    Add(const CString& name, const CString& description, const CString& namedLocation);
    IAcadHyperlinks* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadHyperlinksPtr m_pimpl;
};

//------------------------------------------------------------------------------------
//PyIAcadSectionTypeSettingsImpl
class PyIAcadSectionTypeSettingsImpl
{
public:
    explicit PyIAcadSectionTypeSettingsImpl(IAcadSectionTypeSettings* ptr);
    virtual ~PyIAcadSectionTypeSettingsImpl() = default;

    PyAcSectionGeneration   GetGenerationOptions() const;
    void                    SetGenerationOptions(PyAcSectionGeneration val);
    IAcadSectionTypeSettings* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadSectionTypeSettingsPtr m_pimpl;
    //IAcadSectionTypeSettings2
};

//------------------------------------------------------------------------------------
//PyIAcadDatabasePreferencesImpl
class PyIAcadDatabasePreferences
{
public:
    explicit PyIAcadDatabasePreferences(IAcadDatabasePreferences* ptr);
    virtual ~PyIAcadDatabasePreferences() = default;
    IAcadDatabasePreferences* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadDatabasePreferencesPtr m_pimpl;
};

//------------------------------------------------------------------------------------
//PyIAcadPreferencesFilesImpl
class PyIAcadPreferencesFilesImpl
{
public:
    explicit PyIAcadPreferencesFilesImpl(IAcadPreferencesFiles* ptr);
    virtual ~PyIAcadPreferencesFilesImpl() = default;
    IAcadPreferencesFiles* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadPreferencesFilesPtr m_pimpl;
};
using PyIAcadPreferencesFilesPtr = std::unique_ptr<PyIAcadPreferencesFilesImpl>;

//------------------------------------------------------------------------------------
//PyIAcadPreferencesDisplayImpl
class PyIAcadPreferencesDisplayImpl
{
public:
    explicit PyIAcadPreferencesDisplayImpl(IAcadPreferencesDisplay* ptr);
    virtual ~PyIAcadPreferencesDisplayImpl() = default;
    IAcadPreferencesDisplay* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadPreferencesDisplayPtr m_pimpl;
};
using PyIAcadPreferencesDisplayPtr = std::unique_ptr<PyIAcadPreferencesDisplayImpl>;

//------------------------------------------------------------------------------------
//PyIAcadPreferencesOpenSaveImpl
class PyIAcadPreferencesOpenSaveImpl
{
public:
    explicit PyIAcadPreferencesOpenSaveImpl(IAcadPreferencesOpenSave* ptr);
    virtual ~PyIAcadPreferencesOpenSaveImpl() = default;
    IAcadPreferencesOpenSave* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadPreferencesOpenSavePtr m_pimpl;
};
using PyIAcadPreferencesOpenSavePtr = std::unique_ptr<PyIAcadPreferencesOpenSaveImpl>;

//------------------------------------------------------------------------------------
//PyIAcadPreferencesOutputImpl
class PyIAcadPreferencesOutputImpl
{
public:
    explicit PyIAcadPreferencesOutputImpl(IAcadPreferencesOutput* ptr);
    virtual ~PyIAcadPreferencesOutputImpl() = default;
    IAcadPreferencesOutput* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadPreferencesOutputPtr m_pimpl;
};
using PyIAcadPreferencesOutputPtr = std::unique_ptr<PyIAcadPreferencesOutputImpl>;

//------------------------------------------------------------------------------------
//PyIAcadPreferencesSystemImpl
class PyIAcadPreferencesSystemImpl
{
public:
    explicit PyIAcadPreferencesSystemImpl(IAcadPreferencesSystem* ptr);
    virtual ~PyIAcadPreferencesSystemImpl() = default;
    IAcadPreferencesSystem* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadPreferencesSystemPtr m_pimpl;
};
using PyIAcadPreferencesSystemPtr = std::unique_ptr<PyIAcadPreferencesSystemImpl>;

//------------------------------------------------------------------------------------
//PyIAcadPreferencesUserImpl
class PyIAcadPreferencesUserImpl
{
public:
    explicit PyIAcadPreferencesUserImpl(IAcadPreferencesUser* ptr);
    virtual ~PyIAcadPreferencesUserImpl() = default;
    IAcadPreferencesUser* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadPreferencesUserPtr m_pimpl;
};
using PyIAcadPreferencesUserPtr = std::unique_ptr<PyIAcadPreferencesUserImpl>;

//------------------------------------------------------------------------------------
//PyIAcadPreferencesDraftingImpl
class PyIAcadPreferencesDraftingImpl
{
public:
    explicit PyIAcadPreferencesDraftingImpl(IAcadPreferencesDrafting* ptr);
    virtual ~PyIAcadPreferencesDraftingImpl() = default;
    IAcadPreferencesDrafting* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadPreferencesDraftingPtr m_pimpl;
};
using PyIAcadPreferencesDraftingPtr = std::unique_ptr<PyIAcadPreferencesDraftingImpl>;

//------------------------------------------------------------------------------------
//PyIAcadPreferencesSelectionImpl
class PyIAcadPreferencesSelectionImpl
{
public:
    explicit PyIAcadPreferencesSelectionImpl(IAcadPreferencesSelection* ptr);
    virtual ~PyIAcadPreferencesSelectionImpl() = default;
    IAcadPreferencesSelection* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadPreferencesSelectionPtr m_pimpl;
};
using PyIAcadPreferencesSelectionPtr = std::unique_ptr<PyIAcadPreferencesSelectionImpl>;

//------------------------------------------------------------------------------------
//PyIAcadPreferencesProfilesImpl
class PyIAcadPreferencesProfilesImpl
{
public:
    explicit PyIAcadPreferencesProfilesImpl(IAcadPreferencesProfiles* ptr);
    virtual ~PyIAcadPreferencesProfilesImpl() = default;
    IAcadPreferencesProfiles* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadPreferencesProfilesPtr m_pimpl;
};
using PyIAcadPreferencesProfilesPtr = std::unique_ptr<PyIAcadPreferencesProfilesImpl>;


//------------------------------------------------------------------------------------
//PyIAcadPreferencesImpl
class PyIAcadPreferencesImpl
{
public:
    explicit PyIAcadPreferencesImpl(IAcadPreferences* ptr);
    virtual ~PyIAcadPreferencesImpl() = default;
    PyIAcadPreferencesFilesPtr      GetFiles() const;
    PyIAcadPreferencesDisplayPtr    GetDisplay() const;
    PyIAcadPreferencesOpenSavePtr   GetOpenSave() const;
    PyIAcadPreferencesOutputPtr     GetOutput() const;
    PyIAcadPreferencesSystemPtr     GetSystem() const;
    PyIAcadPreferencesUserPtr       GetUser() const;
    PyIAcadPreferencesDraftingPtr   GetDrafting() const;
    PyIAcadPreferencesSelectionPtr  GetSelection() const;
    PyIAcadPreferencesProfilesPtr   GetProfiles() const;
    IAcadPreferences* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadPreferencesPtr m_pimpl;
};
using PyIAcadPreferencesPtr = std::unique_ptr<PyIAcadPreferencesImpl>;

//------------------------------------------------------------------------------------
//PyIAcadSummaryInfoImpl
class PyIAcadSummaryInfo
{
public:
    explicit PyIAcadSummaryInfo(IAcadSummaryInfo* ptr);
    virtual ~PyIAcadSummaryInfo() = default;
    IAcadSummaryInfo* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadSummaryInfoPtr m_pimpl;
};

//------------------------------------------------------------------------------------
//PyIAcadDynamicBlockReferencePropertyImpl
class PyIAcadDynamicBlockReferenceProperty
{
public:
    explicit PyIAcadDynamicBlockReferenceProperty(IAcadDynamicBlockReferenceProperty* ptr);
    virtual ~PyIAcadDynamicBlockReferenceProperty() = default;
    IAcadDynamicBlockReferenceProperty* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadDynamicBlockReferencePropertyPtr m_pimpl;
};

//------------------------------------------------------------------------------------
//PyIAcadIdPairImpl
class PyIAcadIdPair
{
public:
    explicit PyIAcadIdPair(IAcadIdPair* ptr);
    virtual ~PyIAcadIdPair() = default;
    IAcadIdPair* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadIdPairPtr m_pimpl;
};

//------------------------------------------------------------------------------------
//PyIAcadShadowDisplayImpl
#ifndef _BRXTARGET
class PyIAcadShadowDisplay
{
public:
    explicit PyIAcadShadowDisplay(IAcadShadowDisplay* ptr);
    virtual ~PyIAcadShadowDisplay() = default;
    IAcadShadowDisplay* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadShadowDisplayPtr m_pimpl;
};
#endif

//------------------------------------------------------------------------------------
//PyIAcadPlotImpl
class PyIAcadPlotImpl
{
public:
    explicit PyIAcadPlotImpl(IAcadPlot* ptr);
    virtual ~PyIAcadPlotImpl() = default;
    IAcadPlot* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadPlotPtr m_pimpl;
};
using PyIAcadPlotPtr = std::unique_ptr<PyIAcadPlotImpl>;

//------------------------------------------------------------------------------------
//PyIAcadMenuBarImpl
class PyIAcadMenuBarImpl
{
public:
    explicit PyIAcadMenuBarImpl(IAcadMenuBar* ptr);
    virtual ~PyIAcadMenuBarImpl() = default;
    IAcadMenuBar* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadMenuBarPtr m_pimpl;
};
using PyIAcadMenuBarPtr = std::unique_ptr<PyIAcadMenuBarImpl>;

//------------------------------------------------------------------------------------
//PyIAcadMenuGroupImpl
class PyIAcadMenuGroupImpl
{
public:
    explicit PyIAcadMenuGroupImpl(IAcadMenuGroup* ptr);
    virtual ~PyIAcadMenuGroupImpl() = default;
    PyIAcadMenuGroupsPtr    GetParent() const;
    CString                 GetName() const;
    PyAcMenuGroupType       GetType() const;
    CString                 GetMenuFileName() const;
    PyIAcadPopupMenusPtr    GetMenus() const;
    PyIAcadToolbarsPtr      GetToolbars() const;
    void                    Save(PyAcMenuFileType menuType);
    void                    SaveAs(const CString& menuFileName, PyAcMenuFileType menuType);
    IAcadMenuGroup* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadMenuGroupPtr m_pimpl;
};
using PyIAcadMenuGroupPtr = std::unique_ptr<PyIAcadMenuGroupImpl>;

//------------------------------------------------------------------------------------
//PyIAcadMenuGroupsImpl
class PyIAcadMenuGroupsImpl
{
public:
    explicit PyIAcadMenuGroupsImpl(IAcadMenuGroups* ptr);
    virtual ~PyIAcadMenuGroupsImpl() = default;
    long                GetCount() const;
    PyIAcadMenuGroupPtr GetItem(long index) const;
    PyIAcadMenuGroupPtr Load(const CString& menuFileName);
    PyIAcadMenuGroupPtr Load(const CString& menuFileName, const PyIAcadMenuGroupImpl& BaseMenu);
    IAcadMenuGroups*    impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadMenuGroupsPtr m_pimpl;
}; 

//------------------------------------------------------------------------------------
//PyIAcadPopupMenuImpl
class PyIAcadPopupMenuImpl
{
public:
    explicit PyIAcadPopupMenuImpl(IAcadPopupMenu* ptr);
    virtual ~PyIAcadPopupMenuImpl() = default;
    IAcadPopupMenu* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadPopupMenuPtr m_pimpl;
};
using PyIAcadPopupMenuPtr = std::unique_ptr<PyIAcadPopupMenuImpl>;

//------------------------------------------------------------------------------------
//PyIAcadPopupMenusImpl
class PyIAcadPopupMenusImpl
{
public:
    explicit PyIAcadPopupMenusImpl(IAcadPopupMenus* ptr);
    virtual ~PyIAcadPopupMenusImpl() = default;
    IAcadPopupMenus* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadPopupMenusPtr m_pimpl;
};

//------------------------------------------------------------------------------------
//PyIAcadToolbarsImpl
class PyIAcadToolbarsImpl
{
public:
    explicit PyIAcadToolbarsImpl(IAcadToolbars* ptr);
    virtual ~PyIAcadToolbarsImpl() = default;
    IAcadToolbars* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadToolbarsPtr m_pimpl;
};



#pragma pack (pop)
