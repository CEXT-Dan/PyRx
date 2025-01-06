#pragma once

#ifdef PYRXDEBUG

#include "PyAcad.h" 
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
    AcColorMethod   GetColorMethod() const;
    void            SetColorMethod(AcColorMethod flags);
    AcColor         GetColorIndex() const;
    void            SetColorIndex(AcColor val);
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
//PyIAcadSectionTypeSettings
class PyIAcadSectionTypeSettingsImpl
{
public:
    explicit PyIAcadSectionTypeSettingsImpl(IAcadSectionTypeSettings* ptr);
    virtual ~PyIAcadSectionTypeSettingsImpl() = default;

    AcSectionGeneration     GetGenerationOptions() const;
    void                    SetGenerationOptions(AcSectionGeneration val);
    IAcadSectionTypeSettings* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadSectionTypeSettingsPtr m_pimpl;
    //IAcadSectionTypeSettings2
};

//------------------------------------------------------------------------------------
//PyIAcadDatabasePreferences
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
//PyIAcadSummaryInfo
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
//PyIAcadDynamicBlockReferenceProperty
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
//PyIAcadIdPair
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
//PyIAcadShadowDisplay
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
//PyIAcadSubEntity
#ifndef _GRXTARGET
class PyIAcadSubEntity
{
public:
    explicit PyIAcadSubEntity(IAcadSubEntity* ptr);
    virtual ~PyIAcadSubEntity() = default;
    IAcadSubEntity* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadSubEntityPtr m_pimpl;
};
#endif

//------------------------------------------------------------------------------------
//PyIAcadMLeaderLeader
#ifndef _GRXTARGET
class PyIAcadMLeaderLeader : public PyIAcadSubEntity
{
public:
    explicit PyIAcadMLeaderLeader(IAcadMLeaderLeader* ptr);
    virtual ~PyIAcadMLeaderLeader() = default;
    IAcadMLeaderLeader* impObj(const std::source_location& src = std::source_location::current()) const;
};
#endif

//------------------------------------------------------------------------------------
//PyIAcadSubEntSolidFace
#ifndef _GRXTARGET
class PyIAcadSubEntSolidFace : public PyIAcadSubEntity
{
public:
    explicit PyIAcadSubEntSolidFace(IAcadSubEntSolidFace* ptr);
    virtual ~PyIAcadSubEntSolidFace() = default;
    IAcadSubEntSolidFace* impObj(const std::source_location& src = std::source_location::current()) const;
};
#endif

//------------------------------------------------------------------------------------
//PyIAcadObjectImpl
class PyIAcadObjectImpl
{
public:
    explicit PyIAcadObjectImpl(IAcadObject* ptr);
    virtual ~PyIAcadObjectImpl() = default;
    IAcadObject* impObj(const std::source_location& src = std::source_location::current()) const;
protected:
    IAcadObjectPtr m_pimpl;
};

//------------------------------------------------------------------------------------
//PyIAcadEntityImpl
class PyIAcadEntityImpl : public PyIAcadObjectImpl
{
public:
    explicit PyIAcadEntityImpl(IAcadEntity* ptr);
    virtual ~PyIAcadEntityImpl() override = default;
    IAcadEntity* impObj(const std::source_location& src = std::source_location::current()) const;
};


#endif