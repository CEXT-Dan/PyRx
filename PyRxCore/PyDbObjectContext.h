#pragma once
#include "PyRxObject.h"
#include "dbAnnotationScale.h"
#include "dbObjContext.h"
#include "dbObjectContextCollection.h"

class PyDbObject;
class PyDbObjectContext;

#pragma pack (push, 8)

//-----------------------------------------------------------------------------------------
//PyDbObjectContextCollection
void makePyDbObjectContextCollectionWrapper();

class PyDbObjectContextCollection : public PyRxObject
{
public:
    PyDbObjectContextCollection(AcDbObjectContextCollection* pt);
    virtual ~PyDbObjectContextCollection() override = default;

    std::string         name() const;
    PyDbObjectContext   currentContext(const PyDbObject& obj) const;
    void                setCurrentContext(const PyDbObjectContext& pContext) const;
    void                addContext(const PyDbObjectContext& pContext) const;
    void                removeContext(const std::string& contextName) const;
    void                lockContext(const PyDbObjectContext& pContext) const;
    void                unlockContext() const;
    bool                locked() const;
    PyDbObjectContext   getContext(const std::string& contextName) const;
    bool                hasContext(const std::string& contextName) const;
    boost::python::list toList1() const;
    boost::python::list toList2(const PyRxClass& _class) const;

    static PyRxClass    desc();
    static std::string  className();
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

    void                        registerContextCollection(const std::string& collectionName, const PyDbObjectContextCollection& pCollection) const;
    void                        unregisterContextCollection(const std::string& collectionName) const;
    PyDbObjectContextCollection contextCollection(const std::string& collectionName) const;
    static PyRxClass            desc();
    static std::string          className();
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
    PyDbObjectContext(AcDbObjectContext* pt, bool autoDelete);
    virtual ~PyDbObjectContext() override = default;

    std::string           getName() const;
    void                  setName(const std::string& name) const;
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
    PyDbAnnotationScale(AcDbAnnotationScale* pt, bool autoDelete);
    virtual ~PyDbAnnotationScale() override = default;

    double              getPaperUnits() const;
    double              getDrawingUnits() const;
    double              getScale() const;
    bool                getIsTemporaryScale() const;
    void                setPaperUnits(double val) const;
    void                setDrawingUnits(double val) const;
    bool                matchScaleId(Adesk::LongPtr val) const;
    static PyDbAnnotationScale cast(const PyDbObjectContext& other);
    static PyRxClass    desc();
    static std::string  className();
public:
    AcDbAnnotationScale* impObj(const std::source_location& src = std::source_location::current()) const;
};
#pragma pack (pop)
