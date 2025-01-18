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





#pragma pack (pop)