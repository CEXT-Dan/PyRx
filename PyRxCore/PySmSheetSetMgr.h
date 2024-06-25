#pragma once


#if defined(_ARXTARGET) || defined(_BRXTARGET) 

class PyDbObject;
class PySmPersistImpl;
class PySmObjectIdImpl;
class PySmSheetSetMgrImpl;
class PySmComponentImpl;
class PySmDatabaseImpl;
class PySmSubsetImpl;
class PySmSheetSetImpl;
class PySmSheetImpl;

class PySmObjectId;
class PySmDatabase;


//-----------------------------------------------------------------------------------------
//PySmPersist
void makePySmPersistWrapper();
class PySmPersist
{
public:
    PySmPersist(PySmPersistImpl* ptr);
    PySmPersist(const PySmPersistImpl& other);

    bool               getIsDirty() const;
    std::string        getTypeName() const;
    void               initNew(const PySmPersist& owner);
    PySmPersist        getOwner() const;
    void               setOwner(const PySmPersist& owner);
    PySmDatabase       getDatabase() const;
    //PySmObjectId       getObjectId() const;

    static PySmPersist cast(const PySmPersist& src);
    static std::string className();
public:
    inline PySmPersistImpl* impObj(const std::source_location& src = std::source_location::current()) const;
    std::shared_ptr<PySmPersistImpl> m_pyImp = nullptr;
};

//-----------------------------------------------------------------------------------------
//PySmObjectId
void makePySmObjectIdWrapper();
class PySmObjectId
{
public:
    PySmObjectId(const PySmObjectIdImpl& other);
    std::string         getHandle() const;
    PySmDatabase        getDatabase() const;
    PySmPersist         getPersistObject() const;
    PySmPersist         getOwner() const;
    bool                isEqual(const PySmObjectId& other);
    bool                isValid();
    static std::string  className();
public:
    inline PySmObjectIdImpl* impObj(const std::source_location& src = std::source_location::current()) const;
    std::shared_ptr<PySmObjectIdImpl> m_pyImp = nullptr;
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

    std::string     getNumber() const;
    void            setNumber(const std::string& csVal);
    std::string     getTitle() const;
    void            setTitle(const std::string& csVal);
    bool            getDoNotPlot() const;
    void            setDoNotPlot(bool flag);
    //GetLayout
    //SetLayout
    //GetSheetViews
    std::string     getRevisionDate() const;
    void            setRevisionDate(const std::string& csVal);
    std::string     getIssuePurpose() const;
    void            setIssuePurpose(const std::string& csVal);
    std::string     getCategory() const;
    void            setCategory(const std::string& csVal);

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


    //void                loadFromFile(const CString& filename);
    //CString             getFileName() const;
    //void                setFileName(const CString& filename);
    //CString             getTemplateDstFileName() const;
    //PySmSheetSetImpl    getSheetSet() const;
    //AcSmLockStatus      getLockStatus() const;
    //boost::python::tuple getLockOwnerInfo() const;

    void                lockDb();
    void                unlockDb(bool commit);

    boost::python::list getPersistObjects();
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