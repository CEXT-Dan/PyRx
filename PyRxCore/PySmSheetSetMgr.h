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

class PySmViewCategory;
class PySmCalloutBlocks;
class PySmSheet;

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
    virtual ~PySmPersist() = default;

    bool               getIsDirty() const;
    std::string        getTypeName() const;
    void               initNew(const PySmPersist& owner) const;
    PySmPersist        getOwner() const;
    void               setOwner(const PySmPersist& owner) const;
    PySmDatabase       getDatabase() const;
    PySmObjectId       getObjectId() const;
    void               clear() const;
    bool               isNull() const;

    static PySmPersist cast(const PySmPersist& src);
    static std::string className();
public:
    PySmPersistImpl* impObj(const std::source_location& src = std::source_location::current()) const;
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
    ~PySmAcDbDatabase() = default;
    PyDbDatabase getAcDbDatabase() const;
    static std::string className();
public:
    PySmAcDbDatabaseImpl* impObj(const std::source_location& src = std::source_location::current()) const;
    std::shared_ptr<PySmAcDbDatabaseImpl> m_pyImp = nullptr;
};

//-----------------------------------------------------------------------------------------
//PySmObjectId
void makePySmObjectIdWrapper();
class PySmObjectId
{
public:
    PySmObjectId(const PySmObjectIdImpl& other);
    ~PySmObjectId() = default;
    std::string         getHandle() const;
    PySmDatabase        getDatabase() const;
    PySmPersist         getPersistObject() const;
    PySmPersist         getOwner() const;
    bool                isEqual(const PySmObjectId& other) const;
    bool                isValid() const;
    static std::string  className();
public:
    PySmObjectIdImpl* impObj(const std::source_location& src = std::source_location::current()) const;
public:
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
    virtual ~PySmCustomPropertyValue() = default;

    //TODO these should be python objects
    PyDbAcValue     getValue() const;
    void            setValue1(const PyDbAcValue& acVal) const;
    void            setValue2(const std::string& str) const;
    void            setValue3(int ival) const;
    void            setValue4(double fval) const;
    SmPropertyFlags getFlags() const;
    void            setFlags(SmPropertyFlags flags) const;

    static PySmCustomPropertyValue cast(const PySmPersist& src);
    static std::string   className();
public:
    PySmCustomPropertyValueImpl* impObj(const std::source_location& src = std::source_location::current()) const;
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
    virtual ~PySmCustomPropertyBag() override = default;
    bool                    hasProperty(const std::string& propName) const;
    PySmCustomPropertyValue getProperty(const std::string& propName) const;
    void                    setProperty(const std::string& propName, const PySmCustomPropertyValue& prop) const;
    boost::python::list     getProperties() const;
    boost::python::list     getPropertyValues() const;
    static PySmCustomPropertyBag cast(const PySmPersist& src);
    static std::string   className();
public:
    PySmCustomPropertyBagImpl* impObj(const std::source_location& src = std::source_location::current()) const;
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
    virtual ~PySmFileReference() override = default;

    void            setFileName(const std::string& csVal) const;
    std::string     getFileName() const;
    std::string     resolveFileName() const;
    static PySmFileReference cast(const PySmPersist& src);
    static std::string   className();
public:
    PySmFileReferenceImpl* impObj(const std::source_location& src = std::source_location::current()) const;
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
    virtual ~PySmAcDbObjectReference() override = default;

    static PySmAcDbObjectReference cast(const PySmPersist& src);

    void        setAcDbHandle(PyDbHandle& hwnd) const;
    PyDbHandle  getAcDbHandle() const;
    PySmAcDbDatabase getAcSmAcDbDatabase() const;
    void        setAcDbObject(PyDbObject& pDbObj) const;
    PyDbHandle  resolveAcDbObject(PyDbDatabase& pDb) const;

    static std::string   className();
public:
    PySmAcDbObjectReferenceImpl* impObj(const std::source_location& src = std::source_location::current()) const;
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
    virtual ~PySmNamedAcDbObjectReference() override = default;

    static PySmNamedAcDbObjectReference cast(const PySmPersist& src);

    std::string getName() const;
    void        setName(const std::string& val) const;

    void        SetOwnerAcDbHandle(PyDbHandle& hwnd) const;
    PyDbHandle  GetOwnerAcDbHandle() const;

    static std::string   className();
public:
    PySmNamedAcDbObjectReferenceImpl* impObj(const std::source_location& src = std::source_location::current()) const;
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
    virtual ~PySmAcDbLayoutReference() override = default;

    static PySmAcDbLayoutReference cast(const PySmPersist& src);
    static std::string   className();
public:
    PySmAcDbLayoutReferenceImpl* impObj(const std::source_location& src = std::source_location::current()) const;
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
    virtual ~PySmAcDbViewReference() override = default;

    static PySmAcDbViewReference cast(const PySmPersist& src);
    static std::string   className();
public:
    PySmAcDbViewReferenceImpl* impObj(const std::source_location& src = std::source_location::current()) const;
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
    virtual ~PySmAcDbBlockRecordReference() override = default;

    static PySmAcDbBlockRecordReference cast(const PySmPersist& src);
    static std::string   className();
public:
    PySmAcDbBlockRecordReferenceImpl* impObj(const std::source_location& src = std::source_location::current()) const;
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
    virtual ~PySmProjectPointLocation() override = default;

    std::string getURL() const;
    void        setURL(const std::string& csVal) const;
    std::string getFolder() const;
    void        setFolder(const std::string& csVal) const;
    std::string getUsername() const;
    void        setUsername(const std::string& csVal) const;
    std::string getPassword() const;
    void        setPassword(const std::string& csVal) const;
    long        getResourceType() const;
    void        setResourceType(long val) const;

    static PySmProjectPointLocation cast(const PySmPersist& src);
    static std::string              className();
public:
    PySmProjectPointLocationImpl* impObj(const std::source_location& src = std::source_location::current()) const;
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
    virtual ~PySmObjectReference() override = default;

    void                    setReferencedObject(PySmPersist& pObject) const;
    PySmPersist             getReferencedObject() const;
    SmObjectReferenceFlags  getReferenceFlags() const;
    void                    setReferenceFlags(SmObjectReferenceFlags flags) const;
    static PySmObjectReference cast(const PySmPersist& src);
    static std::string         className();
public:
    PySmObjectReferenceImpl* impObj(const std::source_location& src = std::source_location::current()) const;
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
    virtual ~PySmPersistProxy() override = default;

    static PySmPersistProxy cast(const PySmPersist& src);
    static std::string      className();
public:
    PySmPersistProxyImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PySmPublishOption
void makePySmPublishOptionsWrapper();
class PySmPublishOptions : public PySmPersist
{
public:
    PySmPublishOptions();
    PySmPublishOptions(PySmPublishOptionsImpl* ptr);
    PySmPublishOptions(const PySmPublishOptionsImpl& other);
    virtual ~PySmPublishOptions() override = default;

    PySmFileReference       getDefaultOutputdir() const;
    void                    setDefaultOutputdir(PySmFileReference& val) const;
    bool                    getDwfType() const;
    void                    setDwfType(bool val) const;
    bool                    getPromptForName() const;
    void                    setPromptForName(bool val) const;
    bool                    getUsePassword() const;
    void                    setUsePassword(bool val) const;
    bool                    getPromptForPassword() const;
    void                    setPromptForPassword(bool val) const;
    bool                    getLayerInfo() const;
    void                    setLayerInfo(bool val) const;
    PySmCustomPropertyBag   getUnrecognizedData() const;
    void                    setUnrecognizedData(const PySmCustomPropertyBag& val) const;
    PySmCustomPropertyBag   getUnrecognizedSections() const;
    void                    setUnrecognizedSections(const PySmCustomPropertyBag& val) const;
    bool                    getIncludeSheetSetData() const;
    void                    setIncludeSheetSetData(bool val) const;
    bool                    getIncludeSheetData() const;
    void                    setIncludeSheetData(bool val) const;
    long                    getEplotFormat() const;
    void                    setEplotFormat(long val) const;
    bool                    getLinesMerge() const;
    void                    setLinesMerge(bool val) const;
    std::string             getDefaultFilename() const;
    void                    setDefaultFilename(const std::string& csVal) const;

    static PySmPublishOptions cast(const PySmPersist& src);
    static std::string   className();
public:
    PySmPublishOptionsImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PySmComponent
void makePySmComponentWrapper();
class PySmComponent : public PySmPersist
{
public:
    PySmComponent(PySmComponentImpl* ptr);
    PySmComponent(const PySmComponentImpl& other);
    virtual ~PySmComponent() override = default;

    std::string     getName() const;
    void            setName(const std::string& csName) const;
    std::string     getDesc() const;
    void            setDesc(const std::string& csDesc) const;
    PySmCustomPropertyBag getCustomPropertyBag() const;

    static PySmComponent cast(const PySmPersist& src);
    static std::string   className();
public:
    PySmComponentImpl* impObj(const std::source_location& src = std::source_location::current()) const;
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
    virtual ~PySmSheetSelSet() override = default;

    void    add(PySmComponent& val) const;
    void    remove(PySmComponent& val) const;
    boost::python::list getComponents() const;

    static PySmSheetSelSet  cast(const PySmPersist& src);
    static std::string      className();
public:
    PySmSheetSelSetImpl* impObj(const std::source_location& src = std::source_location::current()) const;
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
    virtual ~PySmSheetSelSets() override = default;

    PySmSheetSelSet add(const std::string& name, const std::string& desc) const;
    void            remove(const PySmSheetSelSet& ss) const;
    boost::python::list getSheetSelSets() const;

    static PySmSheetSelSets  cast(const PySmPersist& src);
    static std::string       className();
public:
    PySmSheetSelSetsImpl* impObj(const std::source_location& src = std::source_location::current()) const;
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
    virtual ~PySmSheetView() override = default;

    PySmAcDbViewReference   getNamedView() const;
    void                    setNamedView(PySmAcDbViewReference& view) const;
    PySmViewCategory        getCategory() const;
    void                    setCategory(PySmViewCategory& view) const;
    std::string             getNumber() const;
    void                    setNumber(const std::string& csVal) const;
    std::string             getTitle() const;
    void                    setTitle(const  std::string& csVal) const;
    static PySmSheetView    cast(const PySmPersist& src);
    static std::string      className();
public:
    PySmSheetViewImpl* impObj(const std::source_location& src = std::source_location::current()) const;
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
    virtual ~PySmSheetViews() override = default;

    boost::python::list     getSheetViews() const;
    void                    sync(const PySmAcDbLayoutReference& lref, const PyDbDatabase& pDb) const;
    static PySmSheetViews   cast(const PySmPersist& src);
    static std::string      className();
public:
    PySmSheetViewsImpl* impObj(const std::source_location& src = std::source_location::current()) const;
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
    virtual ~PySmProjectPointLocations() override = default;

    PySmProjectPointLocation    getLocation(const std::string& locationName) const;
    void                        removeLocation(const PySmProjectPointLocation& val) const;

    PySmProjectPointLocation    addNewLocation(const std::string& name,
        const std::string& url, const std::string& folder, const std::string& username, const std::string& password) const;

    boost::python::list         getProjectPointLocations() const;

    static PySmProjectPointLocations  cast(const PySmPersist& src);
    static std::string      className();
public:
    PySmProjectPointLocationsImpl* impObj(const std::source_location& src = std::source_location::current()) const;
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
    virtual ~PySmSmResources() override = default;

    void                add(const PySmFileReference& val) const;
    void                remove(const PySmFileReference& val) const;
    boost::python::list getFileReferences() const;

    static PySmSmResources  cast(const PySmPersist& src);
    static std::string      className();
public:
    PySmResourcesImpl* impObj(const std::source_location& src = std::source_location::current()) const;
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
    virtual ~PySmViewCategory() override = default;

    boost::python::list     getSheetViews() const;
    PySmCalloutBlocks       getCalloutBlocks() const;

    static PySmViewCategory  cast(const PySmPersist& src);
    static std::string       className();
public:
    PySmViewCategoryImpl* impObj(const std::source_location& src = std::source_location::current()) const;
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
    virtual ~PySmViewCategories() override = default;

    boost::python::list getViewCategories() const;
    PySmViewCategory    createViewCategory(const std::string& csName, const std::string& csDesc, const std::string& csId) const;
    void                removeViewCategory(const PySmViewCategory& cat) const;
    PySmViewCategory    getDefaultViewCategory() const;

    static PySmViewCategories  cast(const PySmPersist& src);
    static std::string         className();
public:
    PySmViewCategoriesImpl* impObj(const std::source_location& src = std::source_location::current()) const;
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
    virtual ~PySmCalloutBlocks() override = default;

    void add(const PySmAcDbBlockRecordReference& blkRef) const;
    void remove(const PySmAcDbBlockRecordReference& blkRef) const;
    boost::python::list getDbBlockRecordReferences() const;

    static PySmCalloutBlocks  cast(const PySmPersist& src);
    static std::string        className();
public:
    PySmCalloutBlocksImpl* impObj(const std::source_location& src = std::source_location::current()) const;
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
    virtual ~PySmSubset() override = default;

    PySmFileReference   getNewSheetLocation() const;
    void                setNewSheetLocation(const PySmFileReference& fref) const;
    PySmAcDbLayoutReference getDefDwtLayout() const;
    void                    setDefDwtLayout(const PySmAcDbLayoutReference& fref) const;
    bool                getPromptForDwt() const;
    void                setPromptForDwt(bool val) const;
    boost::python::list getSheets() const;
    PySmSheet           addNewSheet(const std::string& name, const std::string& desc) const;
    void                insertComponentFirst(const PySmComponent& newSheet) const;
    void                insertComponent(const PySmComponent& newSheet, const PySmComponent& beforeComp) const;
    void                insertComponentAfter(const PySmComponent& newSheet, const PySmComponent& afterComp) const;
    PySmSheet           importSheet(const PySmAcDbLayoutReference& fref) const;
    void                removeSheet(const PySmSheet& val) const;
    PySmSubset          createSubset(const std::string& name, const std::string& desc) const;
    void                removeSubset(const PySmSubset& val) const;
    void                updateInMemoryDwgHints() const;
    bool                getOverrideSheetPublish() const;
    void                setOverrideSheetPublish(bool val) const;
    static PySmSubset   cast(const PySmPersist& src);
    static std::string  className();
public:
    PySmSubsetImpl* impObj(const std::source_location& src = std::source_location::current()) const;
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
    virtual ~PySmSheet() override = default;

    std::string     getNumber() const;
    void            setNumber(const std::string& csVal) const;
    std::string     getTitle() const;
    void            setTitle(const std::string& csVal) const;
    bool            getDoNotPlot() const;
    void            setDoNotPlot(bool flag) const;

    PySmAcDbLayoutReference getLayout() const;
    void setLayout(const PySmAcDbLayoutReference& val) const;
    PySmSheetViews getSheetViews() const;

    std::string     getRevisionNumber() const;
    void            setRevisionNumber(const std::string& csVal) const;
    std::string     getRevisionDate() const;
    void            setRevisionDate(const std::string& csVal) const;
    std::string     getIssuePurpose() const;
    void            setIssuePurpose(const std::string& csVal) const;
    std::string     getCategory() const;
    void            setCategory(const std::string& csVal) const;

    static PySmSheet cast(const PySmPersist& src);
    static std::string className();
public:
    PySmSheetImpl* impObj(const std::source_location& src = std::source_location::current()) const;
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
    virtual ~PySmSheetSet() override = default;

    PySmFileReference   getAltPageSetups() const;
    void                setAltPageSetups(const PySmFileReference& alt) const;

    PySmNamedAcDbObjectReference getDefAltPageSetup() const;
    void                         setDefAltPageSetup(const PySmNamedAcDbObjectReference& alt) const;

    bool                    getPromptForDwgName() const;
    void                    setPromptForDwgName(bool flag) const;
    PySmSheetSelSets        getSheetSelSets() const;
    PySmSmResources         getResources() const;
    PySmCalloutBlocks       getCalloutBlocks() const;
    PySmViewCategories      getViewCategories() const;
    PySmAcDbBlockRecordReference getDefLabelBlk() const;
    void                         setDefLabelBlk(const PySmAcDbBlockRecordReference& blk) const;
    PySmPublishOptions       getPublishOptions() const;
    void                     sync(const PyDbDatabase& pDb) const;
    void                     updateSheetCustomProps() const;

    static PySmSheetSet cast(const PySmPersist& src);
    static std::string className();
public:
    PySmSheetSetImpl* impObj(const std::source_location& src = std::source_location::current()) const;
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
    virtual ~PySmDatabase() override = default;

    void                loadFromFile(const std::string& filename) const;
    std::string         getFileName() const;
    void                setFileName(const std::string& filename) const;
    std::string         getTemplateDstFileName() const;
    PySmSheetSet        getSheetSet() const;
    SmLockStatus        getLockStatus() const;
    boost::python::tuple getLockOwnerInfo() const;
    void                lockDb() const;
    void                unlockDb(bool commit) const;
    boost::python::list getPersistObjects() const;
    static PySmDatabase cast(const PySmPersist& src);
    static std::string  className();
public:
    PySmDatabaseImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PySmSheetSetMgr
void makePySmSheetSetMgrWrapper();
class PySmSheetSetMgr
{
public:
    PySmSheetSetMgr();
    ~PySmSheetSetMgr() = default;

    PySmDatabase         createDatabase1(const std::string& filename) const;
    PySmDatabase         createDatabase2(const std::string& filename, const std::string& templatefilename, bool bAlwaysCreate) const;
    PySmDatabase         openDatabase(const std::string& filename) const;
    PySmDatabase         findOpenDatabase(const std::string& filename) const;
    void                 closeAll() const;
    void                 close(const PySmDatabase& db) const;
    boost::python::tuple getParentSheetSet(const std::string& dwg, const std::string& layout) const;
    boost::python::tuple getSheetFromLayout(const PyDbObject& pAcDbLayout) const;
    boost::python::list  getDatabases() const;
    static std::string   className();

#ifdef PYRXDEBUG
    static bool          runTest();
#endif


public:
    PySmSheetSetMgrImpl* impObj(const std::source_location& src = std::source_location::current()) const;
    std::shared_ptr<PySmSheetSetMgrImpl> m_pyImp = nullptr;
};

#endif