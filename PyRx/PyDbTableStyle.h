#pragma once
#include "PyDbObject.h"

class PyDbObjectId;

void makeAcDbTableStyleWrapper();

class PyDbTableStyle : public PyDbObject
{
public:
    PyDbTableStyle();
    PyDbTableStyle(AcDbObject* ptr, bool autoDelete);
    PyDbTableStyle(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbTableStyle() override = default;

    std::string getName();
    Acad::ErrorStatus setName(const std::string& pszName);

    std::string description(void) const;
    Acad::ErrorStatus  setDescription(const std::string& pszDescription);

    virtual Adesk::UInt32       bitFlags() const;
    virtual Acad::ErrorStatus   setBitFlags(Adesk::UInt32 flags);

    virtual AcDb::FlowDirection flowDirection(void) const;
    virtual Acad::ErrorStatus   setFlowDirection(AcDb::FlowDirection flow);


    static std::string className();

public:
    AcDbTableStyle* impObj() const;
};

