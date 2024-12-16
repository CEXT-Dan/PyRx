#pragma once

#if defined(_ARXTARGET) || defined(_BRXTARGET) 

#if defined(_BRXTARGET250)
#import "axbricscaddb1.tlb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#import "axbricscadsm.tlb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#endif

#if defined(_ARXTARGET240)
#import "axdb24enu.tlb"  raw_interfaces_only, raw_native_types, no_namespace, named_guids
#import "acsmcomponents24.tlb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#endif

#if defined(_ARXTARGET250)
#import "axdb25enu.tlb"  raw_interfaces_only, raw_native_types, no_namespace, named_guids
#import "acsmcomponents25.tlb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#endif

class PySmDatabaseImpl;
class PySmObjectIdImpl;
class PySmComponentImpl;
class PySmSheetSelSetImpl;
class PySmFileReferenceImpl;
class PySmSheetViewImpl;
class PySmCalloutBlocksImpl;
class PySmViewCategoryImpl;
class PySmProjectPointLocationImpl;
class PySmAcDbBlockRecordReferenceImpl;
class PySmSheetImpl;

using PySmComponentArray = std::vector<PySmComponentImpl>;
using PySmSheetSelSetArray = std::vector<PySmSheetSelSetImpl>;
using PySmFileReferenceArray = std::vector<PySmFileReferenceImpl>;
using PySmSheetViewArray = std::vector<PySmSheetViewImpl>;
using PySmViewCategoryArray = std::vector<PySmViewCategoryImpl>;
using PySmProjectPointLocationArray = std::vector<PySmProjectPointLocationImpl>;
using PySmAcDbBlockRecordReferenceArray = std::vector<PySmAcDbBlockRecordReferenceImpl>;
using PySmSheetArray = std::vector<PySmSheetImpl>;


//-----------------------------------------------------------------------------------------
//PySmPersist
class PySmPersistImpl
{
public:
    PySmPersistImpl(IAcSmPersist* other);
    PySmPersistImpl(const PySmPersistImpl& other) = default;
    virtual ~PySmPersistImpl() = default;

    bool                GetIsDirty() const;
    CString             GetTypeName() const;
    void                InitNew(const PySmPersistImpl& owner);
    PySmPersistImpl     GetOwner() const;
    void                SetOwner(const PySmPersistImpl& owner);
    PySmDatabaseImpl    GetDatabase() const;
    PySmObjectIdImpl    GetObjectId() const;
    void                Clear();
    bool                IsNull();
    void                swap(PySmPersistImpl& other);

public:
    IAcSmPersist* impObj(const std::source_location& src = std::source_location::current()) const;
    IAcSmPersistPtr     m_pimpl;
};

//-----------------------------------------------------------------------------------------
//PySmAcDbDatabase
class PySmAcDbDatabaseImpl
{
public:
    PySmAcDbDatabaseImpl(IAcSmAcDbDatabase* other);
    PySmAcDbDatabaseImpl(const PySmAcDbDatabaseImpl& other) = default;
    virtual ~PySmAcDbDatabaseImpl() = default;

    IAcadDatabasePtr    GetIAcadDatabase();
    AcDbDatabase* GetAcDbDatabase();

public:
    IAcSmAcDbDatabase* impObj(const std::source_location& src = std::source_location::current()) const;
    IAcSmAcDbDatabasePtr  m_pimpl;
};

//-----------------------------------------------------------------------------------------
//IAcSmObjectId
class PySmObjectIdImpl
{
public:
    PySmObjectIdImpl(IAcSmObjectId* other);
    PySmObjectIdImpl(const PySmObjectIdImpl& other) = default;
    virtual ~PySmObjectIdImpl() = default;
    CString             GetHandle() const;
    PySmDatabaseImpl    GetDatabase() const;
    PySmPersistImpl     GetPersistObject() const;
    PySmPersistImpl     GetOwner() const;
    bool                IsEqual(const PySmObjectIdImpl& other);
    bool                IsValid();
public:
    IAcSmObjectId* impObj(const std::source_location& src = std::source_location::current()) const;
    IAcSmObjectIdPtr m_pimpl;
};

//-----------------------------------------------------------------------------------------
//PySmFileReference
class PySmFileReferenceImpl : public PySmPersistImpl
{
public:
    PySmFileReferenceImpl();
    PySmFileReferenceImpl(IAcSmFileReference* other);
    PySmFileReferenceImpl(const PySmFileReferenceImpl& other) = default;
    virtual ~PySmFileReferenceImpl() override = default;
    void        SetFileName(const CString& csVal);
    CString     GetFileName() const;
    CString     ResolveFileName() const;
    IAcSmFileReference* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PySmAcDbObjectReference
class PySmAcDbObjectReferenceImpl : public PySmFileReferenceImpl
{
public:
    PySmAcDbObjectReferenceImpl();
    PySmAcDbObjectReferenceImpl(IAcSmAcDbObjectReference* other);
    PySmAcDbObjectReferenceImpl(const PySmAcDbObjectReferenceImpl& other) = default;
    virtual ~PySmAcDbObjectReferenceImpl() override = default;

    void        SetAcDbHandle(AcDbHandle& hwnd);
    AcDbHandle  GetAcDbHandle() const;
    PySmAcDbDatabaseImpl GetAcSmAcDbDatabase() const;
    void        SetAcDbObject(AcDbObject* pDbObj);
    AcDbHandle  ResolveAcDbObject(AcDbDatabase* pDb);

    IAcSmAcDbObjectReference* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PySmNamedAcDbObjectReference
class PySmNamedAcDbObjectReferenceImpl : public PySmAcDbObjectReferenceImpl
{
public:
    PySmNamedAcDbObjectReferenceImpl();
    PySmNamedAcDbObjectReferenceImpl(IAcSmNamedAcDbObjectReference* other);
    PySmNamedAcDbObjectReferenceImpl(const PySmNamedAcDbObjectReferenceImpl& other) = default;
    virtual ~PySmNamedAcDbObjectReferenceImpl() override = default;
    void        SetName(const CString& name);
    CString     GetName() const;
    void        SetOwnerAcDbHandle(const AcDbHandle& hwnd);
    AcDbHandle  GetOwnerAcDbHandle() const;

    IAcSmNamedAcDbObjectReference* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PySmAcDbLayoutReference
class PySmAcDbLayoutReferenceImpl : public PySmNamedAcDbObjectReferenceImpl
{
public:
    PySmAcDbLayoutReferenceImpl();
    PySmAcDbLayoutReferenceImpl(IAcSmAcDbLayoutReference* other);
    PySmAcDbLayoutReferenceImpl(const PySmAcDbLayoutReferenceImpl& other) = default;
    virtual ~PySmAcDbLayoutReferenceImpl() override = default;
    IAcSmAcDbLayoutReference* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PySmAcDbViewReference
class PySmAcDbViewReferenceImpl : public PySmNamedAcDbObjectReferenceImpl
{
public:
    PySmAcDbViewReferenceImpl();
    PySmAcDbViewReferenceImpl(IAcSmAcDbViewReference* other);
    PySmAcDbViewReferenceImpl(const PySmAcDbViewReferenceImpl& other) = default;
    virtual ~PySmAcDbViewReferenceImpl() override = default;
    IAcSmAcDbViewReference* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PySmAcDbBlockRecordReference
class PySmAcDbBlockRecordReferenceImpl : public PySmNamedAcDbObjectReferenceImpl
{
public:
    PySmAcDbBlockRecordReferenceImpl();
    PySmAcDbBlockRecordReferenceImpl(IAcSmAcDbBlockRecordReference* other);
    PySmAcDbBlockRecordReferenceImpl(const PySmAcDbBlockRecordReferenceImpl& other) = default;
    virtual ~PySmAcDbBlockRecordReferenceImpl() override = default;
    IAcSmAcDbBlockRecordReference* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PySmCustomPropertyValue
class PySmCustomPropertyValueImpl : public PySmPersistImpl
{
public:
    PySmCustomPropertyValueImpl();
    PySmCustomPropertyValueImpl(IAcSmCustomPropertyValue* other);
    PySmCustomPropertyValueImpl(const PySmCustomPropertyValueImpl& other) = default;
    virtual ~PySmCustomPropertyValueImpl() override = default;
    AcValue         GetValue() const;
    void            SetValue(const AcValue& acVal);
    PropertyFlags   GetFlags() const;
    void            SetFlags(PropertyFlags flags);
    IAcSmCustomPropertyValue* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PySmCustomPropertyBag
class PySmCustomPropertyBagImpl : public PySmPersistImpl
{
public:
    PySmCustomPropertyBagImpl();
    PySmCustomPropertyBagImpl(IAcSmCustomPropertyBag* other);
    PySmCustomPropertyBagImpl(const PySmCustomPropertyBagImpl& other) = default;
    virtual ~PySmCustomPropertyBagImpl() override = default;

    PySmCustomPropertyValueImpl GetProperty(const CString& propName) const;
    void                        SetProperty(const CString& propName, const PySmCustomPropertyValueImpl& prop);
    std::vector<std::pair<CString, PySmCustomPropertyValueImpl>> GetProperties() const;
    std::vector<std::pair<CString, AcValue>> GetPropertyValues() const;
    IAcSmCustomPropertyBag* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PySmObjectReference
class PySmObjectReferenceImpl : public PySmPersistImpl
{
public:
    PySmObjectReferenceImpl();
    PySmObjectReferenceImpl(IAcSmObjectReference* other);
    PySmObjectReferenceImpl(const PySmObjectReferenceImpl& other) = default;

    void            SetReferencedObject(const PySmPersistImpl& pObject);
    PySmPersistImpl GetReferencedObject() const;
    AcSmObjectReferenceFlags GetReferenceFlags() const;
    void                     SetReferenceFlags(AcSmObjectReferenceFlags flags);

    virtual ~PySmObjectReferenceImpl() override = default;
    IAcSmObjectReference* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PySmProjectPointLocation
class PySmProjectPointLocationImpl : public PySmPersistImpl
{
public:
    PySmProjectPointLocationImpl();
    PySmProjectPointLocationImpl(IAcSmProjectPointLocation* other);
    PySmProjectPointLocationImpl(const PySmProjectPointLocationImpl& other) = default;
    virtual ~PySmProjectPointLocationImpl() override = default;

    CString     GetURL() const;
    void        SetURL(const CString& csVal);
    CString     GetFolder() const;
    void        SetFolder(const CString& csVal);
    CString     GetUsername() const;
    void        SetUsername(const CString& csVal);
    CString     GetPassword() const;
    void        SetPassword(const CString& csVal);
    long        GetResourceType() const;
    void        SetResourceType(long val);

    IAcSmProjectPointLocation* impObj(const std::source_location& src = std::source_location::current()) const;
#if defined(_ARXTARGET)
    IAcSmProjectPointLocation2* impObj2(const std::source_location& src = std::source_location::current()) const;
#endif
};

//-----------------------------------------------------------------------------------------
//PySmPersistProxy
class PySmPersistProxyImpl : public PySmPersistImpl
{
public:
    PySmPersistProxyImpl();
    PySmPersistProxyImpl(IAcSmPersistProxy* other);
    PySmPersistProxyImpl(const PySmPersistProxyImpl& other) = default;
    virtual ~PySmPersistProxyImpl() override = default;

    //TODO: looks pretty advanced
    //virtual HRESULT __stdcall SetClassID(/*[in]*/ GUID classID) = 0;
    //virtual HRESULT __stdcall SetTypeName(/*[in]*/ BSTR value) = 0;
    //virtual HRESULT __stdcall GetRawData(unsigned char** ppData,long* pBufSize) = 0;

    IAcSmPersistProxy* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PySmPublishOption
class PySmPublishOptionsImpl : public PySmPersistImpl
{
public:
    PySmPublishOptionsImpl();
    PySmPublishOptionsImpl(IAcSmPublishOptions* other);
    PySmPublishOptionsImpl(const PySmPublishOptionsImpl& other) = default;
    virtual ~PySmPublishOptionsImpl() override = default;

    PySmFileReferenceImpl   GetDefaultOutputdir() const;
    void                    SetDefaultOutputdir(const PySmFileReferenceImpl& val);
    bool                    GetDwfType() const;
    void                    SetDwfType(bool val);
    bool                    GetPromptForName() const;
    void                    SetPromptForName(bool val);
    bool                    GetUsePassword() const;
    void                    SetUsePassword(bool val);
    bool                    GetPromptForPassword() const;
    void                    SetPromptForPassword(bool val);
    bool                    GetLayerInfo() const;
    void                    SetLayerInfo(bool val);

    PySmCustomPropertyBagImpl   GetUnrecognizedData() const;
    void                        SetUnrecognizedData(const PySmCustomPropertyBagImpl& val);
    PySmCustomPropertyBagImpl   GetUnrecognizedSections() const;
    void                        SetUnrecognizedSections(const PySmCustomPropertyBagImpl& val);

    //2
    bool                    GetIncludeSheetSetData() const;
    void                    SetIncludeSheetSetData(bool val);
    bool                    GetIncludeSheetData() const;
    void                    SetIncludeSheetData(bool val);

    //3
    long                    GetEplotFormat() const;
    void                    SetEplotFormat(long val);

    //4
    bool                    GetLinesMerge() const;
    void                    SetLinesMerge(bool val);
    CString                 GetDefaultFilename() const;
    void                    SetDefaultFilename(const CString& csVal);

    IAcSmPublishOptions* impObj(const std::source_location& src = std::source_location::current()) const;
#if defined(_ARXTARGET)
    IAcSmPublishOptions2* impObj2(const std::source_location& src = std::source_location::current()) const;
#endif
#if defined(_ARXTARGET)
    IAcSmPublishOptions3* impObj3(const std::source_location& src = std::source_location::current()) const;
#endif
#if defined(_ARXTARGET)
    IAcSmPublishOptions4* impObj4(const std::source_location& src = std::source_location::current()) const;
#endif
};

//-----------------------------------------------------------------------------------------
//PySmComponent
class PySmComponentImpl : public PySmPersistImpl
{
public:
    PySmComponentImpl(IAcSmComponent* other);
    PySmComponentImpl(const PySmComponentImpl& other) = default;
    virtual ~PySmComponentImpl() override = default;
    CString         GetName() const;
    void            SetName(const CString& csName);
    CString         GetDesc() const;
    void            SetDesc(const CString& csDesc);
    PySmCustomPropertyBagImpl GetCustomPropertyBag() const;
    IAcSmComponent* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PySmSheetSelSet
class PySmSheetSelSetImpl : public PySmComponentImpl
{
public:
    PySmSheetSelSetImpl();
    PySmSheetSelSetImpl(IAcSmSheetSelSet* other);
    PySmSheetSelSetImpl(const PySmSheetSelSetImpl& other) = default;
    virtual ~PySmSheetSelSetImpl() override = default;

    void    Add(const PySmComponentImpl& val);
    void    Remove(const PySmComponentImpl& val);
    PySmComponentArray GetComponents() const;

    IAcSmSheetSelSet* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PySmSheetSelSets
class PySmSheetSelSetsImpl : public PySmComponentImpl
{
public:
    PySmSheetSelSetsImpl();
    PySmSheetSelSetsImpl(IAcSmSheetSelSets* other);
    PySmSheetSelSetsImpl(const PySmSheetSelSetsImpl& other) = default;
    virtual ~PySmSheetSelSetsImpl() override = default;

    PySmSheetSelSetImpl Add(const CString& name, const CString& desc);
    void Remove(const PySmSheetSelSetImpl& ss);
    PySmSheetSelSetArray GetSheetSelSets() const;

    IAcSmSheetSelSets* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PySmSmResources
class PySmResourcesImpl : public PySmComponentImpl
{
public:
    PySmResourcesImpl();
    PySmResourcesImpl(IAcSmResources* other);
    PySmResourcesImpl(const PySmResourcesImpl& other) = default;
    virtual ~PySmResourcesImpl() override = default;

    void        Add(const PySmFileReferenceImpl& val);
    void        Remove(const PySmFileReferenceImpl& val);
    PySmFileReferenceArray GetFileReferences();

    IAcSmResources* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PySmViewCategory
class PySmViewCategoryImpl : public PySmComponentImpl
{
public:
    PySmViewCategoryImpl();
    PySmViewCategoryImpl(IAcSmViewCategory* other);
    PySmViewCategoryImpl(const PySmViewCategoryImpl& other) = default;
    virtual ~PySmViewCategoryImpl() override = default;

    PySmSheetViewArray      GetSheetViews();
    PySmCalloutBlocksImpl   GetCalloutBlocks();

    IAcSmViewCategory* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PySmViewCategories
class PySmViewCategoriesImpl : public PySmComponentImpl
{
public:
    PySmViewCategoriesImpl();
    PySmViewCategoriesImpl(IAcSmViewCategories* other);
    PySmViewCategoriesImpl(const PySmViewCategoriesImpl& other) = default;
    virtual ~PySmViewCategoriesImpl() override = default;

    PySmViewCategoryArray   GetPySmViewCategorys(); //gramma
    PySmViewCategoryImpl    CreateViewCategory(const CString& csName, const CString& csDesc, const CString& csId);
    void                    RemoveViewCategory(const PySmViewCategoryImpl& cat);
    PySmViewCategoryImpl    GetDefaultViewCategory();

    IAcSmViewCategories* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PySmSheetView
class PySmSheetViewImpl : public PySmComponentImpl
{
public:
    PySmSheetViewImpl();
    PySmSheetViewImpl(IAcSmSheetView* other);
    PySmSheetViewImpl(const PySmSheetViewImpl& other) = default;
    virtual ~PySmSheetViewImpl() override = default;

    PySmAcDbViewReferenceImpl   GetNamedView() const;
    void SetNamedView(const PySmAcDbViewReferenceImpl& view);

    PySmViewCategoryImpl        GetCategory() const;
    void SetCategory(const PySmViewCategoryImpl& view);

    CString GetNumber() const;
    void    SetNumber(const CString& csVal);

    CString GetTitle() const;
    void    SetTitle(const CString& csVal);

    IAcSmSheetView* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PySmSheetViews
class PySmSheetViewsImpl : public PySmComponentImpl
{
public:
    PySmSheetViewsImpl();
    PySmSheetViewsImpl(IAcSmSheetViews* other);
    PySmSheetViewsImpl(const PySmSheetViewsImpl& other) = default;
    virtual ~PySmSheetViewsImpl() override = default;

    PySmSheetViewArray GetSheetViews() const;
    void               Sync(const PySmAcDbLayoutReferenceImpl& lref, AcDbDatabase* pDb);

    IAcSmSheetViews* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PySmProjectPointLocations
class PySmProjectPointLocationsImpl : public PySmComponentImpl
{
public:
    PySmProjectPointLocationsImpl();
    PySmProjectPointLocationsImpl(IAcSmProjectPointLocations* other);
    PySmProjectPointLocationsImpl(const PySmProjectPointLocationsImpl& other) = default;
    virtual ~PySmProjectPointLocationsImpl() override = default;

    PySmProjectPointLocationImpl GetLocation(const CString& locationName) const;
    void RemoveLocation(const PySmProjectPointLocationImpl& val);
    PySmProjectPointLocationImpl AddNewLocation(const CString& name, const CString& url, const CString& folder, const CString& username, const CString& password);
    PySmProjectPointLocationArray GetProjectPointLocations() const;

    IAcSmProjectPointLocations* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PySmCalloutBlocks
class PySmCalloutBlocksImpl : public PySmComponentImpl
{
public:
    PySmCalloutBlocksImpl();
    PySmCalloutBlocksImpl(IAcSmCalloutBlocks* other);
    PySmCalloutBlocksImpl(const PySmCalloutBlocksImpl& other) = default;
    virtual ~PySmCalloutBlocksImpl() override = default;

    void Add(const PySmAcDbBlockRecordReferenceImpl& blkRef);
    void Remove(const PySmAcDbBlockRecordReferenceImpl& blkRef);
    PySmAcDbBlockRecordReferenceArray getAcDbBlockRecordReferences() const;

    IAcSmCalloutBlocks* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PySmSubsetImpl
class PySmSubsetImpl : public PySmComponentImpl
{
public:
    PySmSubsetImpl();
    PySmSubsetImpl(IAcSmSubset* other);
    PySmSubsetImpl(const PySmSubsetImpl& other) = default;
    virtual ~PySmSubsetImpl() override = default;

    PySmFileReferenceImpl GetNewSheetLocation();
    void SetNewSheetLocation(const PySmFileReferenceImpl& fref);

    PySmAcDbLayoutReferenceImpl GetDefDwtLayout() const;
    void SetDefDwtLayout(const PySmAcDbLayoutReferenceImpl& fref);

    bool GetPromptForDwt() const;
    void SetPromptForDwt(bool val);

    PySmSheetArray  GetSheets() const;
    PySmSheetImpl   AddNewSheet(const CString& name, const CString& desc);

    void InsertComponentFirst(const PySmComponentImpl& newSheet);
    void InsertComponent(const PySmComponentImpl& newSheet, const PySmComponentImpl& beforeComp);
    void InsertComponentAfter(const PySmComponentImpl& newSheet, const PySmComponentImpl& afterComp);

    PySmSheetImpl ImportSheet(const PySmAcDbLayoutReferenceImpl& fref);
    void RemoveSheet(const PySmSheetImpl& val);

    PySmSubsetImpl CreateSubset(const CString& name, const CString& desc);
    void RemoveSubset(const PySmSubsetImpl& val);
    void UpdateInMemoryDwgHints();

    bool GetOverrideSheetPublish() const;
    void SetOverrideSheetPublish(bool val);


    IAcSmSubset* impObj(const std::source_location& src = std::source_location::current()) const;
#if defined(_ARXTARGET)
    IAcSmSubset2* impObj2(const std::source_location& src = std::source_location::current()) const;
#endif
};

//-----------------------------------------------------------------------------------------
//PySmSheetSet
class PySmSheetSetImpl : public PySmSubsetImpl
{
public:
    PySmSheetSetImpl();
    PySmSheetSetImpl(IAcSmSheetSet* other);
    PySmSheetSetImpl(const PySmSheetSetImpl& other) = default;
    virtual ~PySmSheetSetImpl() override = default;

    PySmFileReferenceImpl   GetAltPageSetups() const;
    void                    SetAltPageSetups(const PySmFileReferenceImpl& alt);
    PySmNamedAcDbObjectReferenceImpl GetDefAltPageSetup() const;
    void                    SetDefAltPageSetup(const PySmNamedAcDbObjectReferenceImpl& alt);
    bool                    GetPromptForDwgName() const;
    void                    SetPromptForDwgName(bool flag);
    PySmSheetSelSetsImpl    GetSheetSelSets() const;
    PySmResourcesImpl       GetResources() const;
    PySmCalloutBlocksImpl   GetCalloutBlocks() const;
    PySmViewCategoriesImpl  GetViewCategories() const;
    PySmAcDbBlockRecordReferenceImpl GetDefLabelBlk() const;
    void                             SetDefLabelBlk(const PySmAcDbBlockRecordReferenceImpl& blk);
    PySmPublishOptionsImpl   GetPublishOptions() const;
    void                     Sync(AcDbDatabase* pDb);
    void                     UpdateSheetCustomProps();

    IAcSmSheetSet* impObj(const std::source_location& src = std::source_location::current()) const;
#if defined(_ARXTARGET)
    IAcSmSheetSet2* impObj2(const std::source_location& src = std::source_location::current()) const;
#endif
};

//-----------------------------------------------------------------------------------------
//PySmSheetImpl
class PySmSheetImpl : public PySmComponentImpl
{
public:
    PySmSheetImpl();
    PySmSheetImpl(IAcSmSheet* other);
    PySmSheetImpl(const PySmSheetImpl& other) = default;
    virtual ~PySmSheetImpl() override = default;

    CString     GetNumber() const;
    void        SetNumber(const CString& csVal);
    CString     GetTitle() const;
    void        SetTitle(const CString& csVal);

    bool        GetDoNotPlot() const;
    void        SetDoNotPlot(bool flag);
    PySmAcDbLayoutReferenceImpl GetLayout();
    void SetLayout(const PySmAcDbLayoutReferenceImpl& val);
    PySmSheetViewsImpl GetSheetViews() const;

    CString     GetRevisionNumber() const;
    void        SetRevisionNumber(const CString& csVal);
    CString     GetRevisionDate() const;
    void        SetRevisionDate(const CString& csVal);
    CString     GetIssuePurpose() const;
    void        SetIssuePurpose(const CString& csVal);
    CString     GetCategory() const;
    void        SetCategory(const CString& csVal);

    IAcSmSheet* impObj(const std::source_location& src = std::source_location::current()) const;
#if defined(_ARXTARGET)
    IAcSmSheet2* impObj2(const std::source_location& src = std::source_location::current()) const;
#endif
};

//-----------------------------------------------------------------------------------------
//PySmComponent
class PySmDatabaseImpl : public PySmComponentImpl
{
public:
    PySmDatabaseImpl();
    PySmDatabaseImpl(IAcSmDatabase* other);
    PySmDatabaseImpl(const PySmDatabaseImpl& other) = default;
    virtual ~PySmDatabaseImpl() override = default;
    void                LoadFromFile(const CString& filename);
    CString             GetFileName() const;
    void                SetFileName(const CString& filename);
    CString             GetTemplateDstFileName() const;
    PySmSheetSetImpl    GetSheetSet() const;
    AcSmLockStatus      GetLockStatus() const;
    std::pair<CString, CString>     GetLockOwnerInfo() const;
    std::vector<PySmPersistImpl>    GetEnumerator() const;

    void                LockDb();
    void                UnlockDb(bool commit);
    IAcSmDatabase* impObj(const std::source_location& src = std::source_location::current()) const;
};

class PySmSheetSetMgrImpl
{
public:
    PySmSheetSetMgrImpl();
    PySmDatabaseImpl  CreateDatabase(const CString& filename);
    PySmDatabaseImpl  CreateDatabase(const CString& filename, const CString& templatefilename, bool bAlwaysCreate);
    PySmDatabaseImpl  OpenDatabase(const CString& filename);
    PySmDatabaseImpl  FindOpenDatabase(const CString& filename);
    void              CloseAll();
    void              Close(const PySmDatabaseImpl& db);

    //int Register(IAcSmEvents eventHandler);
    //void Unregister(int cookie);

    std::pair<PySmDatabaseImpl, PySmSheetSetImpl> GetParentSheetSet(const CString& dwg, const CString& layout);
    std::pair<PySmDatabaseImpl, PySmSheetImpl>    GetSheetFromLayout(AcDbObject* pAcDbLayout);
    std::vector<PySmDatabaseImpl>                 GetDatabaseEnumerator();

#ifdef PYRXDEBUG
    static bool       runTest();
#endif

public:
    IAcSmSheetSetMgr* impObj(const std::source_location& src = std::source_location::current()) const;
    IAcSmSheetSetMgrPtr m_pimpl;
};

#endif

