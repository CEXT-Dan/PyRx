#pragma once


#if defined(_ARXTARGET) || defined(_BRXTARGET) 

class PySmPersistImpl;
class PySmSheetSetMgrImpl;
class PySmComponentImpl;
class PySmDatabaseImpl;

//-----------------------------------------------------------------------------------------
//PySmPersist
void makePySmPersistWrapper();
class PySmPersist
{
public:
    PySmPersist(PySmPersistImpl* ptr);
    PySmPersist(PySmPersistImpl& other);

    std::string        getTypeName() const;
    static std::string className();
public:
    inline PySmPersistImpl* impObj(const std::source_location& src = std::source_location::current()) const;
    std::shared_ptr<PySmPersistImpl> m_pyImp = nullptr;
};

//-----------------------------------------------------------------------------------------
//PySmComponent
void makePySmComponentWrapper();
class PySmComponent : public PySmPersist
{
public:
    PySmComponent(PySmComponentImpl* ptr);
    PySmComponent(PySmComponentImpl& other);
;
    static std::string className();
public:
    inline PySmComponentImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};


//-----------------------------------------------------------------------------------------
//PySmSmDatabase
void makePySmDatabaseWrapper();
class PySmDatabase : public PySmComponent
{
public:
    PySmDatabase(PySmDatabaseImpl* ptr);
    PySmDatabase(PySmDatabaseImpl& other);
    ;
    static std::string className();
public:
    inline PySmDatabaseImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};



//-----------------------------------------------------------------------------------------
//PySmSheetSetMgr
void makePySmSheetSetMgrWrapper();
class PySmSheetSetMgr
{
public:
    PySmSheetSetMgr();
    boost::python::list databases() const;
    static std::string className();
public:
    inline PySmSheetSetMgrImpl* impObj(const std::source_location& src = std::source_location::current()) const;
    std::shared_ptr<PySmSheetSetMgrImpl> m_pyImp = nullptr;
};

#endif