#pragma once

#include "PyDbDatabase.h "

#pragma pack (push, 8)
class PyAcEditor;
class PyTransactionManager;
class PyEdInputPointManager;
class PyAutoDocLock;

void makePyApDocumentWrapper();

//-----------------------------------------------------------------------------------------
//PyApDocument
class PyApDocument : public PyRxObject
{
public:
    PyApDocument(const AcApDocument* ptr);
    PyApDocument(AcApDocument* ptr, bool autoDelete);
    virtual ~PyApDocument() override = default;

    PyAcEditor              editor();
    PyDbDatabase            database() const;
    std::string             fileName() const;
    AcApDocument::SaveFormat formatForSave() const;
    AcAp::DocLockMode       lockMode1() const;
    AcAp::DocLockMode       lockMode2(bool bIncludeMyLocks) const;
    AcAp::DocLockMode       myLockMode() const;
    bool                    isQuiescent() const;
    std::string             docTitle() const;
    void                    setDocTitle(const std::string& title) const;
    bool                    isReadOnly() const;
    int                     getCountOfLispList() const;
    boost::python::tuple    getItemOfLispList(int nIndex) const;
    bool                    isCommandInputInactive() const;
    void                    pushDbmod() const;
    void                    popDbmod() const;
    void                    upgradeDocOpen() const;
    void                    downgradeDocOpen(bool bPromptForSave) const;
    PyTransactionManager    transactionManager() const;
    PyEdInputPointManager   inputPointManager() const;
    boost::python::object   getUserData();
    void                    setUserData(const boost::python::object& data);
    PyAutoDocLock           autoLock() const;

    static PyObject*/*    */getWxWindow();
    static UINT_PTR         docWnd();
    static std::string      className();
public:
    AcApDocument* impObj(const std::source_location& src = std::source_location::current()) const;
};

#pragma pack (pop)