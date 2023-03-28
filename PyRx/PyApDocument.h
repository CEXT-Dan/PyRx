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
    virtual  ~PyApDocument() override;
    PyDbDatabase database() const;
    PyAcEditor editor();
    static std::string className();
public:
    AcApDocument* impObj() const;
};

