#pragma once


#if defined(_ARXTARGET) || defined(_BRXTARGET) 
class PyDbAcValue;
class PyDbObject;
class PySmPersistImpl;
class PySmObjectIdImpl;
class PySmSheetSetMgrImpl;
class PySmComponentImpl;
class PySmDatabaseImpl;
class PySmSubsetImpl;
class PySmSheetSetImpl;
class PySmSheetImpl;
class PySmCustomPropertyValueImpl;
class PySmCustomPropertyBagImpl;
class PySmFileReferenceImpl;
class PySmPublishOptionsImpl;
class PySmPersistProxyImpl;
class PySmObjectReferenceImpl;
class PySmProjectPointLocationImpl;
class PySmCalloutBlocksImpl;
class PySmSheetSelSetImpl;
class PySmSheetSelSetsImpl;
class PySmResourcesImpl;
class PySmProjectPointLocationsImpl;
class PySmSheetViewImpl;
class PySmSheetViewsImpl;
class PySmViewCategoryImpl;
class PySmViewCategoriesImpl;
class PySmAcDbDatabaseImpl;
class PySmAcDbObjectReferenceImpl;
class PySmNamedAcDbObjectReferenceImpl;
class PySmAcDbLayoutReferenceImpl;
class PySmAcDbViewReferenceImpl;
class PySmAcDbBlockRecordReferenceImpl;

class PySmObjectId;
class PySmDatabase;
class PyDbDatabase;
class PyDbHandle;

//aligned with COM's PropertyFlags
enum class SmPropertyFlags : int
{
    EMPTY = 0,
    CUSTOM_SHEETSET_PROP = 1,
    CUSTOM_SHEET_PROP = 2,
    CUSTOM_SUBSET_PROP = 4,
    IS_CHILD = 8
};

enum class SmLockStatus : int
{
    AcSmLockStatus_UnLocked = 0,
    AcSmLockStatus_Locked_Local = 1,
    AcSmLockStatus_Locked_Remote = 2,
    AcSmLockStatus_Locked_ReadOnly = 4,
    AcSmLockStatus_Locked_NotConnected = 8,
    AcSmLockStatus_Locked_AccessDenied = 16
};

enum class SmObjectReferenceFlags : int
{
    AcSmObjectReference_SoftPointer = 1,
    AcSmObjectReference_HardPointer = 2
};


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
    PySmObjectId       getObjectId() const;
    void               clear();
    bool               isNull() const;

    static PySmPersist cast(const PySmPersist& src);
    static std::string className();
public:
    inline PySmPersistImpl* impObj(const std::source_location& src = std::source_location::current()) const;
    std::shared_ptr<PySmPersistImpl> m_pyImp = nullptr;
};

//-----------------------------------------------------------------------------------------
//PySmAcDbDatabase
void makePySmAcDbDatabaseWrapper();
class PySmAcDbDatabase
{
public:
    PySmAcDbDatabase(PySmAcDbDatabaseImpl* ptr);
    PySmAcDbDatabase(const PySmAcDbDatabaseImpl& other);
    PyDbDatabase getAcDbDatabase() const;
    static std::string className();
public:
    inline PySmAcDbDatabaseImpl* impObj(const std::source_location& src = std::source_location::current()) const;
    std::shared_ptr<PySmAcDbDatabaseImpl> m_pyImp = nullptr;
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
//PySmCustomPropertyValue
void makePySmCustomPropertyValueWrapper();
class PySmCustomPropertyValue : public PySmPersist
{
public:
    PySmCustomPropertyValue();
    PySmCustomPropertyValue(PySmCustomPropertyValueImpl* ptr);
    PySmCustomPropertyValue(const PySmCustomPropertyValueImpl& other);

    //TODO these should be python objects
    PyDbAcValue     getValue() const;
    void            setValue(const PyDbAcValue& acVal);
    SmPropertyFlags getFlags() const;
    void            setFlags(SmPropertyFlags flags);

    static PySmCustomPropertyValue cast(const PySmPersist& src);
    static std::string   className();
public:
    inline PySmCustomPropertyValueImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PySmCustomPropertyBag
void makePySmCustomPropertyBagWrapper();
class PySmCustomPropertyBag : public PySmPersist
{
public:
    PySmCustomPropertyBag();
    PySmCustomPropertyBag(PySmCustomPropertyBagImpl* ptr);
    PySmCustomPropertyBag(const PySmCustomPropertyBagImpl& other);
    PySmCustomPropertyValue getProperty(const std::string& propName) const;
    void                    setProperty(const std::string& propName, const PySmCustomPropertyValue& prop);
    boost::python::list     getProperties() const;
    boost::python::list     getPropertyValues() const;
    static PySmCustomPropertyBag cast(const PySmPersist& src);
    static std::string   className();
public:
    inline PySmCustomPropertyBagImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PySmFileReference
void makePySmFileReferenceWrapper();
class PySmFileReference : public PySmPersist
{
public:
    PySmFileReference();
    PySmFileReference(PySmFileReferenceImpl* ptr);
    PySmFileReference(const PySmFileReferenceImpl& other);
    void            setFileName(const std::string& csVal);
    std::string     getFileName() const;
    std::string     resolveFileName() const;
    static PySmFileReference cast(const PySmPersist& src);
    static std::string   className();
public:
    inline PySmFileReferenceImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PySmAcDbObjectReference
void makePySmAcDbObjectReferenceWrapper();
class PySmAcDbObjectReference : public PySmFileReference
{
public:
    PySmAcDbObjectReference();
    PySmAcDbObjectReference(PySmAcDbObjectReferenceImpl* ptr);
    PySmAcDbObjectReference(const PySmAcDbObjectReferenceImpl& other);
    static PySmAcDbObjectReference cast(const PySmPersist& src);

    void        setAcDbHandle(PyDbHandle& hwnd);
    PyDbHandle  getAcDbHandle() const;
    PySmAcDbDatabase getAcSmAcDbDatabase() const;
    void        setAcDbObject(PyDbObject& pDbObj);
    PyDbHandle  resolveAcDbObject(PyDbDatabase& pDb);

    static std::string   className();
public:
    inline PySmAcDbObjectReferenceImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PySmNamedAcDbObjectReference
void makePySmNamedAcDbObjectReferenceWrapper();
class PySmNamedAcDbObjectReference : public PySmAcDbObjectReference
{
public:
    PySmNamedAcDbObjectReference();
    PySmNamedAcDbObjectReference(PySmNamedAcDbObjectReferenceImpl* ptr);
    PySmNamedAcDbObjectReference(const PySmNamedAcDbObjectReferenceImpl& other);
    static PySmNamedAcDbObjectReference cast(const PySmPersist& src);

    void        SetOwnerAcDbHandle(PyDbHandle& hwnd);
    PyDbHandle  GetOwnerAcDbHandle() const;

    static std::string   className();
public:
    inline PySmNamedAcDbObjectReferenceImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PySmAcDbLayoutReference
void makePySmAcDbLayoutReferenceWrapper();
class PySmAcDbLayoutReference : public PySmNamedAcDbObjectReference
{
public:
    PySmAcDbLayoutReference();
    PySmAcDbLayoutReference(PySmAcDbLayoutReferenceImpl* ptr);
    PySmAcDbLayoutReference(const PySmAcDbLayoutReferenceImpl& other);
    static PySmAcDbLayoutReference cast(const PySmPersist& src);
    static std::string   className();
public:
    inline PySmAcDbLayoutReferenceImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PySmAcDbViewReference
void makePySmAcDbViewReferenceWrapper();
class PySmAcDbViewReference : public PySmNamedAcDbObjectReference
{
public:
    PySmAcDbViewReference();
    PySmAcDbViewReference(PySmAcDbViewReferenceImpl* ptr);
    PySmAcDbViewReference(const PySmAcDbViewReferenceImpl& other);
    static PySmAcDbViewReference cast(const PySmPersist& src);
    static std::string   className();
public:
    inline PySmAcDbViewReferenceImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PySmAcDbBlockRecordReference
void makePySmAcDbBlockRecordReferenceWrapper();
class PySmAcDbBlockRecordReference : public PySmNamedAcDbObjectReference
{
public:
    PySmAcDbBlockRecordReference();
    PySmAcDbBlockRecordReference(PySmAcDbBlockRecordReferenceImpl* ptr);
    PySmAcDbBlockRecordReference(const PySmAcDbBlockRecordReferenceImpl& other);
    static PySmAcDbBlockRecordReference cast(const PySmPersist& src);
    static std::string   className();
public:
    inline PySmAcDbBlockRecordReferenceImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PySmProjectPointLocation
void makePySmProjectPointLocationWrapper();
class PySmProjectPointLocation : public PySmPersist
{
public:
    PySmProjectPointLocation();
    PySmProjectPointLocation(PySmProjectPointLocationImpl* ptr);
    PySmProjectPointLocation(const PySmProjectPointLocationImpl& other);

    std::string getURL() const;
    void        setURL(const std::string& csVal);
    std::string getFolder() const;
    void        setFolder(const std::string& csVal);
    std::string getUsername() const;
    void        setUsername(const std::string& csVal);
    std::string getPassword() const;
    void        setPassword(const std::string& csVal);
    long        getResourceType() const;
    void        setResourceType(long val);

    static PySmProjectPointLocation cast(const PySmPersist& src);
    static std::string              className();
public:
    inline PySmProjectPointLocationImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PySmObjectReference
void makePySmObjectReferenceWrapper();
class PySmObjectReference : public PySmPersist
{
public:
    PySmObjectReference();
    PySmObjectReference(PySmObjectReferenceImpl* ptr);
    PySmObjectReference(const PySmObjectReferenceImpl& other);
    static PySmObjectReference cast(const PySmPersist& src);
    static std::string         className();
public:
    inline PySmObjectReferenceImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PySmPersistProxy
void makePySmPersistProxyWrapper();
class PySmPersistProxy : public PySmPersist
{
public:
    PySmPersistProxy();
    PySmPersistProxy(PySmPersistProxyImpl* ptr);
    PySmPersistProxy(const PySmPersistProxyImpl& other);
    static PySmPersistProxy cast(const PySmPersist& src);
    static std::string      className();
public:
    inline PySmPersistProxyImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PySmPublishOption
void makePySmPublishOptioneWrapper();
class PySmPublishOptions : public PySmPersist
{
public:
    PySmPublishOptions();
    PySmPublishOptions(PySmPublishOptionsImpl* ptr);
    PySmPublishOptions(const PySmPublishOptionsImpl& other);
    static PySmPublishOptions cast(const PySmPersist& src);
    static std::string   className();
public:
    inline PySmPublishOptionsImpl* impObj(const std::source_location& src = std::source_location::current()) const;
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
    PySmCustomPropertyBag getCustomPropertyBag() const;

    static PySmComponent cast(const PySmPersist& src);
    static std::string   className();
public:
    inline PySmComponentImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PycSmSheetSelSet
void makePySmSheetSelSetWrapper();
class PySmSheetSelSet : public PySmComponent
{
public:
    PySmSheetSelSet();
    PySmSheetSelSet(PySmSheetSelSetImpl* ptr);
    PySmSheetSelSet(const PySmSheetSelSetImpl& other);
    static PySmSheetSelSet  cast(const PySmPersist& src);
    static std::string       className();
public:
    inline PySmSheetSelSetImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PycSmSheetSelSets
void makePySmSheetSelSetsWrapper();
class PySmSheetSelSets : public PySmComponent
{
public:
    PySmSheetSelSets();
    PySmSheetSelSets(PySmSheetSelSetsImpl* ptr);
    PySmSheetSelSets(const PySmSheetSelSetsImpl& other);
    static PySmSheetSelSets  cast(const PySmPersist& src);
    static std::string       className();
public:
    inline PySmSheetSelSetsImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PySmSheetView
void makePySmSheetViewWrapper();
class PySmSheetView : public PySmComponent
{
public:
    PySmSheetView();
    PySmSheetView(PySmSheetViewImpl* ptr);
    PySmSheetView(const PySmSheetViewImpl& other);
    static PySmSheetView  cast(const PySmPersist& src);
    static std::string     className();
public:
    inline PySmSheetViewImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PySmSheetViews
void makePySmSheetViewsWrapper();
class PySmSheetViews : public PySmComponent
{
public:
    PySmSheetViews();
    PySmSheetViews(PySmSheetViewsImpl* ptr);
    PySmSheetViews(const PySmSheetViewsImpl& other);
    static PySmSheetViews  cast(const PySmPersist& src);
    static std::string     className();
public:
    inline PySmSheetViewsImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PySmProjectPointLocations
void makePySmProjectPointLocationsWrapper();
class PySmProjectPointLocations : public PySmComponent
{
public:
    PySmProjectPointLocations();
    PySmProjectPointLocations(PySmProjectPointLocationsImpl* ptr);
    PySmProjectPointLocations(const PySmProjectPointLocationsImpl& other);
    static PySmProjectPointLocations  cast(const PySmPersist& src);
    static std::string      className();
public:
    inline PySmProjectPointLocationsImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PySmSmResources
void makePySmSmResourcesWrapper();
class PySmSmResources : public PySmComponent
{
public:
    PySmSmResources();
    PySmSmResources(PySmResourcesImpl* ptr);
    PySmSmResources(const PySmResourcesImpl& other);
    static PySmSmResources  cast(const PySmPersist& src);
    static std::string      className();
public:
    inline PySmResourcesImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PySmViewCategory
void makePySmViewCategoryWrapper();
class PySmViewCategory : public PySmComponent
{
public:
    PySmViewCategory();
    PySmViewCategory(PySmViewCategoryImpl* ptr);
    PySmViewCategory(const PySmViewCategoryImpl& other);
    static PySmViewCategory  cast(const PySmPersist& src);
    static std::string       className();
public:
    inline PySmViewCategoryImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PySmViewCategories
void makePySmViewCategoriesWrapper();
class PySmViewCategories : public PySmComponent
{
public:
    PySmViewCategories();
    PySmViewCategories(PySmViewCategoriesImpl* ptr);
    PySmViewCategories(const PySmViewCategoriesImpl& other);
    static PySmViewCategories  cast(const PySmPersist& src);
    static std::string         className();
public:
    inline PySmViewCategoriesImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PySmCalloutBlocks
void makePySmCalloutBlocksWrapper();
class PySmCalloutBlocks : public PySmComponent
{
public:
    PySmCalloutBlocks();
    PySmCalloutBlocks(PySmCalloutBlocksImpl* ptr);
    PySmCalloutBlocks(const PySmCalloutBlocksImpl& other);
    static PySmCalloutBlocks  cast(const PySmPersist& src);
    static std::string        className();
public:
    inline PySmCalloutBlocksImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PySmSubset
void makePySmSubsetWrapper();
class PySmSubset : public PySmComponent
{
public:
    PySmSubset();
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
    PySmSheet();
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
    std::string     getRevisionNumber() const;
    void            setRevisionNumber(const std::string& csVal);
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
    PySmSheetSet();
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
    PySmDatabase();
    PySmDatabase(PySmDatabaseImpl* ptr);
    PySmDatabase(const PySmDatabaseImpl& other);
    void                loadFromFile(const std::string& filename);
    std::string         getFileName() const;
    void                setFileName(const std::string& filename);
    std::string         getTemplateDstFileName() const;
    PySmSheetSet        getSheetSet() const;
    SmLockStatus        getLockStatus() const;
    boost::python::tuple getLockOwnerInfo() const;
    void                lockDb();
    void                unlockDb(bool commit);
    boost::python::list getPersistObjects();
    static PySmDatabase cast(const PySmPersist& src);
    static std::string  className();
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

#ifdef PYRXDEBUG
    static bool          runTest();
#endif

public:
    inline PySmSheetSetMgrImpl* impObj(const std::source_location& src = std::source_location::current()) const;
    std::shared_ptr<PySmSheetSetMgrImpl> m_pyImp = nullptr;
};

#endif