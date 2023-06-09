#pragma once
#include "PyRxObject.h"
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
    Acad::ErrorStatus   endTransaction();
    Acad::ErrorStatus   abortTransaction();
    int                 numActiveTransactions();
    int                 numOpenedObjects();
    PyTransaction       topTransaction();
    Acad::ErrorStatus   addNewlyCreatedDBRObject1(PyDbObject& obj);
    Acad::ErrorStatus   addNewlyCreatedDBRObject2(PyDbObject& obj, bool add);

    boost::python::list getAllObjects();
    PyDbObject          getObject1(const PyDbObjectId &id);
    PyDbObject          getObject2(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbObject          getObject3(const PyDbObjectId& id, AcDb::OpenMode mode, bool openErasedObject);
    Acad::ErrorStatus   queueForGraphicsFlush();
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
    Acad::ErrorStatus   enableGraphicsFlush(bool doEnable);
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


