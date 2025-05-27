#pragma once
#include "PyRxObject.h"

#pragma pack (push, 8)
class PyDbObject;
class PyDbObjectId;
class PyTransaction;

//-----------------------------------------------------------------------------
//----- PyDbTransactionManager
void makePyDbTransactionManager();

class PyDbTransactionManager : public PyRxObject
{
public:
    PyDbTransactionManager();   
    PyDbTransactionManager(AcDbTransactionManager* ptr);
    virtual ~PyDbTransactionManager() override = default;

    PyTransaction       startTransaction() const;
    void                endTransaction() const;
    void                abortTransaction() const;
    int                 numActiveTransactions() const;
    int                 numOpenedObjects() const;
    PyTransaction       topTransaction() const;
    void                addNewlyCreatedDBRObject1(PyDbObject& obj) const;
    void                addNewlyCreatedDBRObject2(PyDbObject& obj, bool add) const;

    boost::python::list getAllObjects() const;
    PyDbObject          getObject1(const PyDbObjectId &id) const;
    PyDbObject          getObject2(const PyDbObjectId& id, AcDb::OpenMode mode) const;
    PyDbObject          getObject3(const PyDbObjectId& id, AcDb::OpenMode mode, bool openErasedObject) const;
    void   queueForGraphicsFlush() const;
public:
    static PyRxClass desc();
    static std::string className();
public:
    AcDbTransactionManager* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------
//----- AcTransactionManager  ** this is init in PyAp Module!!!
void makePyTransactionManagerManager();

class PyTransactionManager : public PyDbTransactionManager
{
public:
    PyTransactionManager();
    PyTransactionManager(AcTransactionManager* ptr);
    virtual ~PyTransactionManager() override = default;
    void                enableGraphicsFlush(bool doEnable) const;
    void                flushGraphics() const;
public:
    static PyRxClass desc();
    static std::string className();
public:
    AcTransactionManager* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------
//----- PyTransaction
void makePyTransaction();

class PyTransaction : public PyRxObject
{
public:
    explicit PyTransaction(AcTransaction* ptr);
    virtual ~PyTransaction() override = default;

    PyDbObject          getObject1(const PyDbObjectId& id) const;
    PyDbObject          getObject2(const PyDbObjectId& id, AcDb::OpenMode mode) const;
    PyDbObject          getObject3(const PyDbObjectId& id, AcDb::OpenMode mode, bool openErasedObject) const;
    boost::python::list getAllObjects() const;
    int                 numOpenedObjects() const;
public:
    static PyRxClass desc();
    static std::string className();
public:
    AcTransaction* impObj(const std::source_location& src = std::source_location::current()) const;
};
#pragma pack (pop)

