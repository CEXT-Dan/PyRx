#pragma once

#include "PyDbDatabase.h "

class PyAcEditor;

void makeAcApDocumentWrapper();

//-----------------------------------------------------------------------------------------
//PyApDocument
class PyApDocument : public PyRxObject
{
public:
    PyApDocument(AcApDocument* ptr, bool autoDelete);
    virtual ~PyApDocument() override = default;
    PyAcEditor editor();
    PyDbDatabase database() const;
    std::string fileName() const;
    AcApDocument::SaveFormat formatForSave() const;

    AcAp::DocLockMode lockMode1() const;
    AcAp::DocLockMode lockMode2(bool bIncludeMyLocks) const;
    AcAp::DocLockMode myLockMode() const;
    bool    isQuiescent() const;

    std::string docTitle() const;
    void setDocTitle(const std::string& title);

    bool isReadOnly() const;

    int getCountOfLispList() const;
    boost::python::tuple getItemOfLispList(int nIndex) const;

    bool isCommandInputInactive() const;

    void              pushDbmod();
    Acad::ErrorStatus popDbmod();

    Acad::ErrorStatus upgradeDocOpen();
    Acad::ErrorStatus downgradeDocOpen(bool bPromptForSave);

    static std::string className();
public:
    AcApDocument* impObj() const;
};

