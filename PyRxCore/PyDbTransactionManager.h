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

    PyTransaction       startTransaction();
    void                endTransaction();
    void                abortTransaction();
    int                 numActiveTransactions();
    int                 numOpenedObjects();
    PyTransaction       topTransaction();
    void                addNewlyCreatedDBRObject1(PyDbObject& obj);
    void                addNewlyCreatedDBRObject2(PyDbObject& obj, bool add);

    boost::python::list getAllObjects();
    PyDbObject          getObject1(const PyDbObjectId &id);
    PyDbObject          getObject2(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbObject          getObject3(const PyDbObjectId& id, AcDb::OpenMode mode, bool openErasedObject);
    void   queueForGraphicsFlush();
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
    void                enableGraphicsFlush(bool doEnable);
    void                flushGraphics();
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

    PyDbObject          getObject1(const PyDbObjectId& id);
    PyDbObject          getObject2(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbObject          getObject3(const PyDbObjectId& id, AcDb::OpenMode mode, bool openErasedObject);
    boost::python::list getAllObjects();
    int                 numOpenedObjects();
public:
    static PyRxClass desc();
    static std::string className();
public:
    AcTransaction* impObj(const std::source_location& src = std::source_location::current()) const;
};
#pragma pack (pop)

