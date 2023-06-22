#pragma once
#include "PyRxObject.h"

class AcDbObjectContext;
class AcDbAnnotationScale;

//-----------------------------------------------------------------------------------------
//PyDbObjectContext
void makePyDbObjectContextWrapper();

class PyDbObjectContext : public PyRxObject
{
#ifndef ZRXAPP
public:
    PyDbObjectContext(AcDbObjectContext* pt);
    virtual ~PyDbObjectContext() = default;
    std::string           getName() const;
    Acad::ErrorStatus     setName(std::string& name);
    Adesk::LongPtr        uniqueIdentifier() const;
    std::string           collectionName() const;
    static PyRxClass      desc();
    static std::string    className();
public:
    AcDbObjectContext* impObj(const std::source_location& src = std::source_location::current()) const;
#endif
};


//-----------------------------------------------------------------------------------------
// PyDbAnnotationScale
void makePyDbAnnotationScaleWrapper();

class PyDbAnnotationScale : public PyDbObjectContext
{
#ifndef ZRXAPP
public:
    PyDbAnnotationScale();
    PyDbAnnotationScale(AcDbAnnotationScale* pt);
    virtual ~PyDbAnnotationScale() = default;

    Acad::ErrorStatus   copyFrom(const PyRxObject& val);
    std::string         collectionName() const;
    Adesk::LongPtr      uniqueIdentifier() const;
    std::string         getName() const;
    double              getPaperUnits() const;
    double              getDrawingUnits() const;
    double              getScale() const;
    bool                getIsTemporaryScale() const;
    Acad::ErrorStatus   setName(std::string& val);
    Acad::ErrorStatus   setPaperUnits(double val);
    Acad::ErrorStatus   setDrawingUnits(double val);
    bool                matchScaleId(Adesk::LongPtr val) const;
    static PyRxClass    desc();
    static std::string  className();
public:
    AcDbAnnotationScale* impObj(const std::source_location& src = std::source_location::current()) const;
#endif
};