#pragma once


#if defined(_ARXTARGET) || defined(_BRXTARGET) 

class PyDbObject;
class PySmPersistImpl;
class PySmSheetSetMgrImpl;
class PySmComponentImpl;
class PySmDatabaseImpl;
class PySmSubsetImpl;
class PySmSheetSetImpl;
class PySmSheetImpl;


//-----------------------------------------------------------------------------------------
//PySmPersist
void makePySmPersistWrapper();
class PySmPersist
{
public:
    PySmPersist(PySmPersistImpl* ptr);
    PySmPersist(const PySmPersistImpl& other);

    std::string        getTypeName() const;
    static PySmPersist cast(const PySmPersist& src);
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
    PySmComponent(const PySmComponentImpl& other);

    std::string     getName() const;
    void            setName(const std::string& csName);
    std::string     getDesc() const;
    void            setDesc(const std::string& csDesc);

    static PySmComponent cast(const PySmPersist& src);
    static std::string   className();
public:
    inline PySmComponentImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PySmSubset
void makePySmSubsetWrapper();
class PySmSubset : public PySmComponent
{
public:
    PySmSubset(PySmSubsetImpl* ptr);
    PySmSubset(const PySmSubsetImpl& other);
    static PySmSubset  cast(const PySmPersist& src);
    static std::string className();
public:
    inline PySmSubsetImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PySmSheet
void makePySmSheetWrapper();
class PySmSheet : public PySmComponent
{
public:
    PySmSheet(PySmSheetImpl* ptr);
    PySmSheet(const PySmSheetImpl& other);
    static PySmSheet cast(const PySmPersist& src);
    static std::string className();
public:
    inline PySmSheetImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PySmSheetSet
void makePySmSheetSetWrapper();
class PySmSheetSet : public PySmSubset
{
public:
    PySmSheetSet(PySmSheetSetImpl* ptr);
    PySmSheetSet(const PySmSheetSetImpl& other);
    static PySmSheetSet cast(const PySmPersist& src);
    static std::string className();
public:
    inline PySmSheetSetImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};


//-----------------------------------------------------------------------------------------
//PySmSmDatabase
void makePySmDatabaseWrapper();
class PySmDatabase : public PySmComponent
{
public:
    PySmDatabase(PySmDatabaseImpl* ptr);
    PySmDatabase(const PySmDatabaseImpl& other);
    boost::python::list smObjects();
    static PySmDatabase cast(const PySmPersist& src);
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
    PySmDatabase         createDatabase1(const std::string& filename);
    PySmDatabase         createDatabase2(const std::string& filename, const std::string& templatefilename, bool bAlwaysCreate);
    PySmDatabase         openDatabase(const std::string& filename);
    PySmDatabase         findOpenDatabase(const std::string& filename);
    void                 closeAll();
    void                 close(PySmDatabase& db);
    boost::python::tuple getParentSheetSet(const std::string& dwg, const std::string& layout);
    boost::python::tuple getSheetFromLayout(PyDbObject& pAcDbLayout);
    boost::python::list  databases() const;
    static std::string   className();
public:
    inline PySmSheetSetMgrImpl* impObj(const std::source_location& src = std::source_location::current()) const;
    std::shared_ptr<PySmSheetSetMgrImpl> m_pyImp = nullptr;
};

#endif