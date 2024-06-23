#pragma once

#if defined(_ARXTARGET) || defined(_BRXTARGET) 

//-----------------------------------------------------------------------------------------
//PySmPersist
class PySmPersistImpl
{
public:
    explicit PySmPersistImpl(IAcSmPersist* other);
    virtual ~PySmPersistImpl() = default;
    IAcSmPersist* impObj(const std::source_location& src = std::source_location::current()) const;
    IAcSmPersistPtr m_pimpl;
};

//-----------------------------------------------------------------------------------------
//PySmComponent
class PySmComponentImpl : public PySmPersistImpl
{
public:
    explicit PySmComponentImpl(IAcSmComponent* other);
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
class PySmSmDatabaseImpl : public PySmComponentImpl
{
public:
    explicit PySmSmDatabaseImpl(IAcSmDatabase* other);
    virtual ~PySmSmDatabaseImpl() override = default;

    void        LockDb();
    void        UnlockDb(bool commit);

    PySmSheetSetImpl  GetSheetSet();
    IAcSmDatabase* impObj(const std::source_location& src = std::source_location::current()) const;
};


class PySmSheetSetMgrImpl
{
public:
    PySmSheetSetMgrImpl();
    PySmSmDatabaseImpl CreateDatabase(const CString& filename);
    PySmSmDatabaseImpl CreateDatabase(const CString& filename, const CString& templatefilename, bool bAlwaysCreate);
    PySmSmDatabaseImpl OpenDatabase(const CString& filename);
    PySmSmDatabaseImpl FindOpenDatabase(const CString& filename);
    void CloseAll();
    void Close(PySmSmDatabaseImpl& db);

    //int Register(IAcSmEvents eventHandler);
    //void Unregister(int cookie);

    //AcSmDatabase GetParentSheetSet(string dwg, string layout, out AcSmSheetSet sheetSet);
    //AcSmDatabase GetSheetFromLayout(AcadObject pAcDbLayout, out AcSmSheet sheet);
    //IAcSmEnumDatabase GetDatabaseEnumerator();

    IAcSmSheetSetMgr* impObj(const std::source_location& src = std::source_location::current()) const;
    IAcSmSheetSetMgrPtr m_pimpl;
};

#endif

