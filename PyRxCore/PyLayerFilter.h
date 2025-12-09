#pragma once
#include "PyRxObject.h"

#pragma pack (push, 8)

class PyDbLayerTableRecord;
class PyDbDatabase;
class PyDbObjectId;

//class AcLyRelExpr
//{
//public:
//    virtual ~AcLyRelExpr() {}
//
//    virtual const ACHAR* getVariable() const = 0;
//    virtual const ACHAR* getConstant() const = 0;
//};
//
////represents a term of the form:
////a AND b
//class AcLyAndExpr
//{
//public:
//    virtual ~AcLyAndExpr() {}
//    virtual const AcArray<AcLyRelExpr*>& getRelExprs() const = 0;
//};
//
////represents an expression of the form:
////(a AND b) OR (c AND d) OR (e AND f)
//class AcLyBoolExpr
//{
//public:
//    virtual ~AcLyBoolExpr() {}
//    virtual const AcArray<AcLyAndExpr*>& getAndExprs() const = 0;
//};

//------------------------------------------------------------------------------------
//PyLyLayerFilter
void makePyLyLayerFilterWrapper();

class PyLyLayerFilter : public PyRxObject
{
public:
    PyLyLayerFilter();
    PyLyLayerFilter(AcLyLayerFilter* pt, bool autoDelete);
    virtual ~PyLyLayerFilter() = default;
    const std::string       name() const;
    void                    setName(const std::string& name) const;
    bool                    allowRename() const;
    PyLyLayerFilter         parent() const;
    boost::python::list     getNestedFilters() const;
    void                    addNested(PyLyLayerFilter& filter) const;
    void                    removeNested(PyLyLayerFilter& filter) const;
    void                    generateNested() const;
    bool                    dynamicallyGenerated() const;
    bool                    allowNested() const;
    bool                    allowDelete() const;
    bool                    isProxy() const;
    bool                    isIdFilter() const;
    bool                    filter(PyDbLayerTableRecord& layer) const;
    int                     showEditor() const;
    const std::string       filterExpression() const;
    void                    setFilterExpression(const std::string& expr) const;
    //virtual const AcLyBoolExpr* filterExpressionTree() const;
    bool                    compareTo(const PyLyLayerFilter& pOther) const;

    static PyRxClass    desc();
    static std::string  className();
public:
    AcLyLayerFilter* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyLyLayerGroup
void makePyLyLayerGroupWrapper();
class PyLyLayerGroup : public PyLyLayerFilter
{
public:
    PyLyLayerGroup();
    PyLyLayerGroup(AcLyLayerGroup* pt, bool autoDelete);
    virtual ~PyLyLayerGroup() = default;
    void                addLayerId(const PyDbObjectId& id) const;
    void                removeLayerId(const PyDbObjectId& id) const;
    boost::python::list layerIds() const;
    static PyRxClass    desc();
    static std::string  className();
public:
    AcLyLayerGroup* impObj(const std::source_location& src = std::source_location::current()) const;
};

//------------------------------------------------------------------------------------
//PyLayerFilterManager
void makePyLayerFilterManagerWrapper();

class PyLayerFilterManager
{
public:
    PyLayerFilterManager();
    PyLayerFilterManager(PyDbDatabase& db);
    ~PyLayerFilterManager() = default;
    boost::python::tuple getFilters();
    void setFilters1(boost::python::tuple& pyList);
    void setFilters2(PyLyLayerFilter& root, PyLyLayerFilter& current);
public:
    AcLyLayerFilterManager* imp = nullptr;
};

#pragma pack (pop)



