#pragma once
#include "PyRxObject.h"

//-----------------------------------------------------------------------------------------
//PyGiSubEntityTraits
void makePyGiSubEntityTraitsWrapper();

class PyGiSubEntityTraits : public PyRxObject
{
public:
    PyGiSubEntityTraits(AcGiSubEntityTraits* ptr, bool autoDelete);
    virtual ~PyGiSubEntityTraits() override = default;

    void        setColor(const Adesk::UInt16 color);

    static std::string	className();
    static PyRxClass	desc();
public:
    AcGiSubEntityTraits* impObj(const std::source_location& src = std::source_location::current()) const;
};



//-----------------------------------------------------------------------------------------
//PyGiDrawableTraits
void makePyGiDrawableTraitsWrapper();

class PyGiDrawableTraits : public PyGiSubEntityTraits
{
public:
    PyGiDrawableTraits(AcGiDrawableTraits* ptr, bool autoDelete);
    virtual ~PyGiDrawableTraits() override = default;
    static std::string	className();
    static PyRxClass	desc();
public:
    AcGiDrawableTraits* impObj(const std::source_location& src = std::source_location::current()) const;
};

