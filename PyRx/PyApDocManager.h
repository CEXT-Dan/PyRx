#pragma once

#include "PyRxObject.h"

class PyApDocument;

void makeAcApDocManagerWrapper();
//-----------------------------------------------------------------------------------------
//PyApDocManager
class PyApDocManager : public PyRxObject
{
public:
    PyApDocManager();
    PyApDocManager(AcApDocManager* ptr, bool autoDelete);
    virtual ~PyApDocManager() override = default;

    PyApDocument curDocument();

    Acad::ErrorStatus lockDocument1(PyApDocument& pDoc);
    Acad::ErrorStatus lockDocument2(PyApDocument& pDoc, AcAp::DocLockMode mode);
    Acad::ErrorStatus lockDocument3(PyApDocument& pDoc, AcAp::DocLockMode mode, const std::string& pGlobalCmdName, const std::string pLocalCmdName, bool prompt);

    Acad::ErrorStatus unlockDocument(PyApDocument& pDoc);

    static std::string className();

public:
    AcApDocManager* impObj() const;
};

