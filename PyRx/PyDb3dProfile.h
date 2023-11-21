#pragma once
#include "PyRxObject.h"

class PyDbEntity;

//-----------------------------------------------------------------------------------------
//PyDb3dProfile
void makePyDb3dProfileWrapper();

class PyDb3dProfile : public PyRxObject
{
public:
    PyDb3dProfile();
    PyDb3dProfile(const PyDbEntity& pent);
    PyDb3dProfile(const AcDb3dProfile& src);
    PyDb3dProfile(AcDb3dProfile* ptr, bool autoDelete);
    virtual ~PyDb3dProfile() override = default;

    PyDbEntity  entity() const;
    bool        isClosed() const;
    bool        isPlanar() const;
    bool        isSubent() const;
    bool        isFace() const;
    bool        isEdge() const;
    bool        isValid() const;

    static PyRxClass    desc();
    static std::string  className();

public:
    inline AcDb3dProfile* impObj(const std::source_location& src = std::source_location::current()) const;
};

