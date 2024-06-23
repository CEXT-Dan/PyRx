#pragma once

#if defined(_ARXTARGET) || defined(_BRXTARGET) 

//-----------------------------------------------------------------------------------------
//PySmPersist
class PySmPersistImpl
{
public:
    PySmPersistImpl(IAcSmPersist* other);
    IAcSmPersist* impObj(const std::source_location& src = std::source_location::current()) const;
    IAcSmPersistPtr m_pimpl;
};

//-----------------------------------------------------------------------------------------
//PySmComponent
class PySmComponentImpl : public PySmPersistImpl
{
public:
    PySmComponentImpl(IAcSmComponent* other);
    IAcSmComponent* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PySmComponent
class PySmSmDatabaseImpl : public PySmComponentImpl
{
public:
    PySmSmDatabaseImpl(IAcSmDatabase* other);
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

