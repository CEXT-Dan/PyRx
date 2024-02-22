#pragma once
#include "PyRxObject.h"
#include "dbAnnotationScale.h"
#include "dbObjContext.h"
#include "dbObjectContextCollection.h"

//-----------------------------------------------------------------------------------------
//PyDbObjectContextCollection
void makePyDbObjectContextCollectionWrapper();

class PyDbObjectContextCollection : public PyRxObject
{
public:
    PyDbObjectContextCollection(AcDbObjectContextCollection* pt);
    virtual ~PyDbObjectContextCollection() override = default;
    static PyRxClass      desc();
    static std::string    className();
public:
    AcDbObjectContextCollection* impObj(const std::source_location& src = std::source_location::current()) const;
};


//-----------------------------------------------------------------------------------------
//PyDbObjectContextManager
void makePyDbObjectContextManagerWrapper();

class PyDbObjectContextManager : public PyRxObject
{
public:
    PyDbObjectContextManager(AcDbObjectContextManager* pt);
    virtual ~PyDbObjectContextManager() override = default;
    static PyRxClass      desc();
    static std::string    className();
public:
    AcDbObjectContextManager* impObj(const std::source_location& src = std::source_location::current()) const;
};


//-----------------------------------------------------------------------------------------
//PyDbObjectContext
void makePyDbObjectContextWrapper();

class PyDbObjectContext : public PyRxObject
{
public:
    PyDbObjectContext(AcDbObjectContext* pt);
    PyDbObjectContext(AcDbObjectContext* pt, bool autoDelete, bool isDbOject);
    virtual ~PyDbObjectContext() override = default;
    std::string           getName() const;
    void                  setName(const std::string& name);
    Adesk::LongPtr        uniqueIdentifier() const;
    std::string           collectionName() const;
    static PyRxClass      desc();
    static std::string    className();
public:
    AcDbObjectContext* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
// PyDbAnnotationScale
void makePyDbAnnotationScaleWrapper();

class PyDbAnnotationScale : public PyDbObjectContext
{
public:
    PyDbAnnotationScale();
    PyDbAnnotationScale(AcDbAnnotationScale* pt);
    PyDbAnnotationScale(AcDbAnnotationScale* pt, bool autoDelete, bool isDbOject);
    virtual ~PyDbAnnotationScale() override = default;
    void   copyFrom(const PyRxObject& val);
    double              getPaperUnits() const;
    double              getDrawingUnits() const;
    double              getScale() const;
    bool                getIsTemporaryScale() const;
    void                setPaperUnits(double val);
    void                setDrawingUnits(double val);
    bool                matchScaleId(Adesk::LongPtr val) const;
    static PyRxClass    desc();
    static std::string  className();
public:
    AcDbAnnotationScale* impObj(const std::source_location& src = std::source_location::current()) const;
};