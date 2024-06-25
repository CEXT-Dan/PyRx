#pragma once

#if defined(_ARXTARGET) || defined(_BRXTARGET) 

#if defined(_BRXTARGET240)
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

//-----------------------------------------------------------------------------------------
//PySmPersist
class PySmPersistImpl
{
public:
    explicit PySmPersistImpl(IAcSmPersist* other);
    PySmPersistImpl(const PySmPersistImpl& other) = default;
    virtual ~PySmPersistImpl() = default;

    bool                GetIsDirty() const;
    CString             GetTypeName() const;
    void                InitNew(const PySmPersistImpl& owner);
    PySmPersistImpl     GetOwner() const;
    void                SetOwner(const PySmPersistImpl& owner);
    PySmDatabaseImpl    GetDatabase() const;
    PySmObjectIdImpl    GetObjectId() const;
    void                swap(PySmPersistImpl& other);

public:
    IAcSmPersist* impObj(const std::source_location& src = std::source_location::current()) const;
    IAcSmPersistPtr     m_pimpl;
};

//-----------------------------------------------------------------------------------------
//IAcSmObjectId
class PySmObjectIdImpl
{
public:
    explicit PySmObjectIdImpl(IAcSmObjectId* other);
    virtual ~PySmObjectIdImpl() = default;
    CString             GetHandle() const;
    PySmDatabaseImpl    GetDatabase() const;
    PySmPersistImpl     GetPersistObject() const;
    PySmPersistImpl     GetOwner() const;
    bool                IsEqual(const PySmObjectIdImpl& other);
    bool                IsValid();
    IAcSmObjectId* impObj(const std::source_location& src = std::source_location::current()) const;
    IAcSmObjectIdPtr m_pimpl;
};

//-----------------------------------------------------------------------------------------
//PySmComponent
class PySmComponentImpl : public PySmPersistImpl
{
public:
    explicit PySmComponentImpl(IAcSmComponent* other);
    explicit PySmComponentImpl(const PySmComponentImpl& other) = default;
    virtual ~PySmComponentImpl() override = default;
    CString         GetName() const;
    void            SetName(const CString& csName);
    CString         GetDesc() const;
    void            SetDesc(const CString& csDesc);
    IAcSmComponent* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PySmSubset
class PySmSubsetImpl : public PySmComponentImpl
{
public:
    explicit PySmSubsetImpl(IAcSmSubset* other);
    virtual ~PySmSubsetImpl() override = default;
    IAcSmSubset* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PySmSheetSet
class PySmSheetSetImpl : public PySmSubsetImpl
{
public:
    explicit PySmSheetSetImpl(IAcSmSheetSet* other);
    virtual ~PySmSheetSetImpl() override = default;
    IAcSmSheetSet* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PySmSheetImpl
class PySmSheetImpl : public PySmComponentImpl
{
public:
    explicit PySmSheetImpl(IAcSmSheet* other);
    virtual ~PySmSheetImpl() override = default;
    IAcSmSheet* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PySmComponent
class PySmDatabaseImpl : public PySmComponentImpl
{
public:
    explicit PySmDatabaseImpl(IAcSmDatabase* other);
    explicit PySmDatabaseImpl(const PySmDatabaseImpl& other) = default;
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
    void              Close(PySmDatabaseImpl& db);

    //int Register(IAcSmEvents eventHandler);
    //void Unregister(int cookie);

    std::pair<PySmDatabaseImpl, PySmSheetSetImpl> GetParentSheetSet(const CString& dwg, const CString& layout);
    std::pair<PySmDatabaseImpl, PySmSheetImpl>    GetSheetFromLayout(AcDbObject* pAcDbLayout);
    std::vector<PySmDatabaseImpl>                 GetDatabaseEnumerator();

public:
    IAcSmSheetSetMgr* impObj(const std::source_location& src = std::source_location::current()) const;
    IAcSmSheetSetMgrPtr m_pimpl;
};

#endif

