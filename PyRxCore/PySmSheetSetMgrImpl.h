#pragma once

#pragma pack (push, 8)

#if defined(_ARXTARGET) || defined(_BRXTARGET) 

#if defined(_BRXTARGET) && (_BRXTARGET <= 260)
#import "axbricscaddb1.tlb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#import "axbricscadsm.tlb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#endif

#if defined(_ARXTARGET) && (_ARXTARGET <= 243)
#import "acax24ENU.tlb"  raw_interfaces_only, raw_native_types, no_namespace, named_guids
#import "acsmcomponents24.tlb" raw_interfaces_only, raw_native_types, no_namespace, named_guids
#endif

#if defined(_ARXTARGET) && (_ARXTARGET >= 250) && (_ARXTARGET <= 251)
#import "acax25ENU.tlb"  raw_interfaces_only, raw_native_types, no_namespace, named_guids
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
    void                InitNew(const PySmPersistImpl& owner) const;
    PySmPersistImpl     GetOwner() const;
    void                SetOwner(const PySmPersistImpl& owner) const;
    PySmDatabaseImpl    GetDatabase() const;
    PySmObjectIdImpl    GetObjectId() const;
    void                Clear() const;
    bool                IsNull() const;
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

    IAcadDatabasePtr    GetIAcadDatabase() const;
    AcDbDatabase* GetAcDbDatabase() const;

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
    bool                IsEqual(const PySmObjectIdImpl& other) const;
    bool                IsValid() const;
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
    void        SetFileName(const CString& csVal) const;
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

    void        SetAcDbHandle(AcDbHandle& hwnd) const;
    AcDbHandle  GetAcDbHandle() const;
    PySmAcDbDatabaseImpl GetAcSmAcDbDatabase() const;
    void        SetAcDbObject(AcDbObject* pDbObj) const;
    AcDbHandle  ResolveAcDbObject(AcDbDatabase* pDb) const;

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
    void        SetName(const CString& name) const;
    CString     GetName() const;
    void        SetOwnerAcDbHandle(const AcDbHandle& hwnd) const;
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
    void            SetValue(const AcValue& acVal) const;
    PropertyFlags   GetFlags() const;
    void            SetFlags(PropertyFlags flags) const;
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
    void                        SetProperty(const CString& propName, const PySmCustomPropertyValueImpl& prop) const;
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

    void            SetReferencedObject(const PySmPersistImpl& pObject) const;
    PySmPersistImpl GetReferencedObject() const;
    AcSmObjectReferenceFlags GetReferenceFlags() const;
    void                     SetReferenceFlags(AcSmObjectReferenceFlags flags) const;

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
    void        SetURL(const CString& csVal) const;
    CString     GetFolder() const;
    void        SetFolder(const CString& csVal) const;
    CString     GetUsername() const;
    void        SetUsername(const CString& csVal) const;
    CString     GetPassword() const;
    void        SetPassword(const CString& csVal) const;
    long        GetResourceType() const;
    void        SetResourceType(long val) const;

    IAcSmProjectPointLocation* impObj(const std::source_location& src = std::source_location::current()) const;
#if !defined(_BRXTARGET240)
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
    void                    SetDefaultOutputdir(const PySmFileReferenceImpl& val) const;
    bool                    GetDwfType() const;
    void                    SetDwfType(bool val) const;
    bool                    GetPromptForName() const;
    void                    SetPromptForName(bool val) const;
    bool                    GetUsePassword() const;
    void                    SetUsePassword(bool val) const;
    bool                    GetPromptForPassword() const;
    void                    SetPromptForPassword(bool val) const;
    bool                    GetLayerInfo() const;
    void                    SetLayerInfo(bool val) const;

    PySmCustomPropertyBagImpl   GetUnrecognizedData() const;
    void                        SetUnrecognizedData(const PySmCustomPropertyBagImpl& val) const;
    PySmCustomPropertyBagImpl   GetUnrecognizedSections() const;
    void                        SetUnrecognizedSections(const PySmCustomPropertyBagImpl& val) const;

    //2
    bool                    GetIncludeSheetSetData() const;
    void                    SetIncludeSheetSetData(bool val) const;
    bool                    GetIncludeSheetData() const;
    void                    SetIncludeSheetData(bool val) const;

    //3
    long                    GetEplotFormat() const;
    void                    SetEplotFormat(long val) const;

    //4
    bool                    GetLinesMerge() const;
    void                    SetLinesMerge(bool val) const;
    CString                 GetDefaultFilename() const;
    void                    SetDefaultFilename(const CString& csVal) const;

    IAcSmPublishOptions* impObj(const std::source_location& src = std::source_location::current()) const;
#if !defined(_BRXTARGET240)
    IAcSmPublishOptions2* impObj2(const std::source_location& src = std::source_location::current()) const;
#endif
#if !defined(_BRXTARGET260)
    IAcSmPublishOptions3* impObj3(const std::source_location& src = std::source_location::current()) const;
#endif
#if !defined(_BRXTARGET260)
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
    void            SetName(const CString& csName) const;
    CString         GetDesc() const;
    void            SetDesc(const CString& csDesc) const;
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

    void    Add(const PySmComponentImpl& val) const;
    void    Remove(const PySmComponentImpl& val) const;
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

    PySmSheetSelSetImpl Add(const CString& name, const CString& desc) const;
    void Remove(const PySmSheetSelSetImpl& ss) const;
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

    void        Add(const PySmFileReferenceImpl& val) const;
    void        Remove(const PySmFileReferenceImpl& val) const;
    PySmFileReferenceArray GetFileReferences() const;

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

    PySmSheetViewArray      GetSheetViews() const;
    PySmCalloutBlocksImpl   GetCalloutBlocks() const;

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

    PySmViewCategoryArray   GetPySmViewCategorys() const; //gramma
    PySmViewCategoryImpl    CreateViewCategory(const CString& csName, const CString& csDesc, const CString& csId) const;
    void                    RemoveViewCategory(const PySmViewCategoryImpl& cat) const;
    PySmViewCategoryImpl    GetDefaultViewCategory() const;

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
    void                        SetNamedView(const PySmAcDbViewReferenceImpl& view) const;
    PySmViewCategoryImpl        GetCategory() const;
    void                        SetCategory(const PySmViewCategoryImpl& view) const;
    CString                     GetNumber() const;
    void                        SetNumber(const CString& csVal) const;
    CString                     GetTitle() const;
    void                        SetTitle(const CString& csVal) const;

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
    void               Sync(const PySmAcDbLayoutReferenceImpl& lref, AcDbDatabase* pDb) const;

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
    void RemoveLocation(const PySmProjectPointLocationImpl& val) const;
    PySmProjectPointLocationImpl AddNewLocation(const CString& name, const CString& url, const CString& folder, const CString& username, const CString& password) const;
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

    void Add(const PySmAcDbBlockRecordReferenceImpl& blkRef) const;
    void Remove(const PySmAcDbBlockRecordReferenceImpl& blkRef) const;
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

    PySmFileReferenceImpl GetNewSheetLocation() const;
    void SetNewSheetLocation(const PySmFileReferenceImpl& fref) const;

    PySmAcDbLayoutReferenceImpl GetDefDwtLayout() const;
    void SetDefDwtLayout(const PySmAcDbLayoutReferenceImpl& fref) const;

    bool GetPromptForDwt() const;
    void SetPromptForDwt(bool val) const;

    PySmSheetArray  GetSheets() const;
    PySmSheetImpl   AddNewSheet(const CString& name, const CString& desc) const;

    void InsertComponentFirst(const PySmComponentImpl& newSheet) const;
    void InsertComponent(const PySmComponentImpl& newSheet, const PySmComponentImpl& beforeComp) const;
    void InsertComponentAfter(const PySmComponentImpl& newSheet, const PySmComponentImpl& afterComp) const;

    PySmSheetImpl ImportSheet(const PySmAcDbLayoutReferenceImpl& fref) const;
    void RemoveSheet(const PySmSheetImpl& val) const;

    PySmSubsetImpl CreateSubset(const CString& name, const CString& desc) const;
    void RemoveSubset(const PySmSubsetImpl& val) const;
    void UpdateInMemoryDwgHints() const;

    bool GetOverrideSheetPublish() const;
    void SetOverrideSheetPublish(bool val) const;


    IAcSmSubset* impObj(const std::source_location& src = std::source_location::current()) const;
#if !defined(_BRXTARGET240)
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
    void                    SetAltPageSetups(const PySmFileReferenceImpl& alt) const;
    PySmNamedAcDbObjectReferenceImpl GetDefAltPageSetup() const;
    void                    SetDefAltPageSetup(const PySmNamedAcDbObjectReferenceImpl& alt) const;
    bool                    GetPromptForDwgName() const;
    void                    SetPromptForDwgName(bool flag) const;
    PySmSheetSelSetsImpl    GetSheetSelSets() const;
    PySmResourcesImpl       GetResources() const;
    PySmCalloutBlocksImpl   GetCalloutBlocks() const;
    PySmViewCategoriesImpl  GetViewCategories() const;
    PySmAcDbBlockRecordReferenceImpl GetDefLabelBlk() const;
    void                             SetDefLabelBlk(const PySmAcDbBlockRecordReferenceImpl& blk) const;
    PySmPublishOptionsImpl   GetPublishOptions() const;
    void                     Sync(AcDbDatabase* pDb) const;
    void                     UpdateSheetCustomProps() const;

    IAcSmSheetSet* impObj(const std::source_location& src = std::source_location::current()) const;
#if !defined(_BRXTARGET240)
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
    void        SetNumber(const CString& csVal) const;
    CString     GetTitle() const;
    void        SetTitle(const CString& csVal) const;

    bool        GetDoNotPlot() const;
    void        SetDoNotPlot(bool flag) const;
    PySmAcDbLayoutReferenceImpl GetLayout() const;
    void SetLayout(const PySmAcDbLayoutReferenceImpl& val) const;
    PySmSheetViewsImpl GetSheetViews() const;

    CString     GetRevisionNumber() const;
    void        SetRevisionNumber(const CString& csVal) const;
    CString     GetRevisionDate() const;
    void        SetRevisionDate(const CString& csVal) const;
    CString     GetIssuePurpose() const;
    void        SetIssuePurpose(const CString& csVal) const;
    CString     GetCategory() const;
    void        SetCategory(const CString& csVal) const;

    IAcSmSheet* impObj(const std::source_location& src = std::source_location::current()) const;
#if !defined(_BRXTARGET260)
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
    void                LoadFromFile(const CString& filename) const;
    CString             GetFileName() const;
    void                SetFileName(const CString& filename) const;
    CString             GetTemplateDstFileName() const;
    PySmSheetSetImpl    GetSheetSet() const;
    AcSmLockStatus      GetLockStatus() const;
    std::pair<CString, CString>     GetLockOwnerInfo() const;
    std::vector<PySmPersistImpl>    GetEnumerator() const;

    void                LockDb() const;
    void                UnlockDb(bool commit) const;
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
    void              CloseAll() const;
    void              Close(const PySmDatabaseImpl& db) const;

    //int Register(IAcSmEvents eventHandler) const;
    //void Unregister(int cookie) const;

    std::pair<PySmDatabaseImpl, PySmSheetSetImpl> GetParentSheetSet(const CString& dwg, const CString& layout) const;
    std::pair<PySmDatabaseImpl, PySmSheetImpl>    GetSheetFromLayout(AcDbObject* pAcDbLayout) const;
    std::vector<PySmDatabaseImpl>                 GetDatabaseEnumerator() const;

#ifdef PYRXDEBUG
    static bool       runTest();
#endif

public:
    IAcSmSheetSetMgr* impObj(const std::source_location& src = std::source_location::current()) const;
    IAcSmSheetSetMgrPtr m_pimpl;
};

#endif

#pragma pack (pop)
