#pragma once

#include "PyRxObject.h"

class PyApDocument;

void makeAcApDocManagerWrapper();
//-----------------------------------------------------------------------------------------
//PyApDocManager
class PyApDocManager : public PyRxObject
{
public:
    PyApDocManager(AcApDocManager* ptr, bool autoDelete);
    virtual ~PyApDocManager() override = default;

    PyApDocument curDocument();
    static std::string className();
public:
    AcApDocManager* impObj() const;
};

