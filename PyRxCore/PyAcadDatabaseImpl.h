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