#pragma once
#include "PyAcadObjectImpl.h"

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
    PyAcColor         GetColorIndex() const;
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

    PyAcSectionGeneration     GetGenerationOptions() const;
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
