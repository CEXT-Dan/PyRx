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

    Adesk::UInt32       bitFlags() const;
    Acad::ErrorStatus   setBitFlags(Adesk::UInt32 flags);

    AcDb::FlowDirection flowDirection(void) const;
    Acad::ErrorStatus   setFlowDirection(AcDb::FlowDirection flow);

    virtual double horzCellMargin(void) const;
    Acad::ErrorStatus setHorzCellMargin(double dCellMargin);

    double vertCellMargin(void) const;
    Acad::ErrorStatus setVertCellMargin(double dCellMargin);

    bool isTitleSuppressed(void) const;
    Acad::ErrorStatus suppressTitleRow(bool bValue);

    bool isHeaderSuppressed(void) const;
    Acad::ErrorStatus suppressHeaderRow(bool bValue);

    PyDbObjectId        textStyle(AcDb::RowType rowType) const;
    Acad::ErrorStatus   setTextStyle(const PyDbObjectId& id, AcDb::RowType rowType);


    static std::string className();

public:
    AcDbTableStyle* impObj() const;
};

