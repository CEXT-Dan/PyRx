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

    double priorSize() const;
    Acad::ErrorStatus setPriorSize(double priorSize);

    static std::string className();
public:
    AcDbTextStyleTableRecord* impObj() const;
};

