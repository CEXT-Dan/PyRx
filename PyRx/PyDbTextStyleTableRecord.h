#pragma once
#include "PyDbSymbolTableRecord.h"

class PyDbObjectId;

void makeTextStyleTableRecordWrapper();

class PyDbTextStyleTableRecord : public PyDbSymbolTableRecord
{
public:
    PyDbTextStyleTableRecord(AcDbTextStyleTableRecord* ptr, bool autoDelete);
    PyDbTextStyleTableRecord(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbTextStyleTableRecord() override = default;

    Adesk::Boolean isShapeFile() const;
    void setIsShapeFile(Adesk::Boolean shape);

    Adesk::Boolean isVertical() const;
    void setIsVertical(Adesk::Boolean vertical);

    double textSize() const;
    Acad::ErrorStatus setTextSize(double size);

    double xScale() const;
    Acad::ErrorStatus setXScale(double xScale);

    double obliquingAngle() const;
    Acad::ErrorStatus setObliquingAngle(double obliquingAngle);

    Adesk::UInt8 flagBits() const;
    void setFlagBits(Adesk::UInt8 flagBits);

    double priorSize() const;
    Acad::ErrorStatus setPriorSize(double priorSize);

    std::string fileName();
    Acad::ErrorStatus setFileName(const std::string& path);

    std::string bigFontFileName();
    Acad::ErrorStatus setBigFontFileName(const std::string& path);

    Acad::ErrorStatus setFont(const std::string& pTypeface, bool bold,bool italic, int charset, int pitch,int family, bool bAllowMissingFont);
    boost::python::tuple font();

    static std::string className();
    static PyRxClass desc();
public:
    AcDbTextStyleTableRecord* impObj(const std::source_location& src = std::source_location::current()) const;
};

