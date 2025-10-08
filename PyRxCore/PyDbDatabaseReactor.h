#pragma once
#include "PyRxObject.h"

#pragma pack (push, 8)
class PyDbObject;
class PyDbDatabase;
class PyDbDatabaseReactor;

void makePyDbDatabaseReactorWrapper();

class PyDbDatabaseReactorImpl : public AcDbDatabaseReactor
{
public:
    explicit PyDbDatabaseReactorImpl(PyDbDatabaseReactor* backPtr);
    virtual ~PyDbDatabaseReactorImpl() override = default;
    virtual void objectAppended(const AcDbDatabase* pDb, const AcDbObject* pObj) override;
    virtual void objectUnAppended(const AcDbDatabase* pDb, const AcDbObject* pObj) override;
    virtual void objectReAppended(const AcDbDatabase* pDb, const AcDbObject* pObj) override;
    virtual void objectOpenedForModify(const AcDbDatabase* pDb, const AcDbObject* pObj)override;
    virtual void objectModified(const AcDbDatabase* pDb, const AcDbObject* pObj) override;
    virtual void objectErased(const AcDbDatabase* pDb, const AcDbObject* pObj, Adesk::Boolean bErased) override;
    virtual void headerSysVarWillChange(const AcDbDatabase* pDb, const ACHAR* name) override;
    virtual void headerSysVarChanged(const AcDbDatabase* pDb, const ACHAR* name, Adesk::Boolean bSuccess) override;
    virtual void proxyResurrectionCompleted(const AcDbDatabase* pDb, const ACHAR* appname, AcDbObjectIdArray& objects) override;
    virtual void goodbye(const AcDbDatabase* pDb) override;

public:
    PyDbDatabaseReactor* impObj(const std::source_location& src = std::source_location::current()) const;
    PyDbDatabaseReactor* m_backPtr = nullptr;
};

class PyDbDatabaseReactor : public PyRxObject, public boost::python::wrapper<PyDbDatabaseReactor>
{
public:
    PyDbDatabaseReactor();
    virtual ~PyDbDatabaseReactor() override = default;
    void objectAppended(const PyDbDatabase& pDb, const PyDbObject& pObj);
    void objectUnAppended(const PyDbDatabase& pDb, const PyDbObject& pObj);
    void objectReAppended(const PyDbDatabase& pDb, const PyDbObject& pObj);
    void objectOpenedForModify(const PyDbDatabase& pDb, const PyDbObject& pObj);
    void objectModified(const PyDbDatabase& pDb, const PyDbObject& pObj);
    void objectErased(const PyDbDatabase& pDb, const PyDbObject& pObj, bool bErased);
    void headerSysVarWillChange(const PyDbDatabase& pDb, const std::string& name);
    void headerSysVarChanged(const PyDbDatabase& pDb, const std::string& name, bool bSuccess);
    void proxyResurrectionCompleted(const PyDbDatabase& pDb, const std::string& appname, boost::python::list& objects);
    void goodbye(const PyDbDatabase& pDb);

public:
    static PyRxClass    desc();
    static std::string  className();
public:
    AcDbDatabaseReactor* impObj(const std::source_location& src = std::source_location::current()) const;

public:
    bool reg_objectAppended = true;
    bool reg_objectUnAppended = true;
    bool reg_objectReAppended = true;
    bool reg_objectOpenedForModify = true;
    bool reg_objectModified = true;
    bool reg_objectErased = true;
    bool reg_headerSysVarWillChange = true;
    bool reg_headerSysVarChanged = true;
    bool reg_proxyResurrectionCompleted = true;
    bool reg_goodbye = true;
};

#pragma pack (pop)
