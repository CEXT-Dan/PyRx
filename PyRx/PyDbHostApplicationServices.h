#pragma once
#include "PyDbDatabase.h"

void makeAcDbHostApplicationServicesWrapper();

class PyDbHostApplicationServices
{
public:
    PyDbDatabase workingDatabase() const;

protected:
    AcDbHostApplicationServices* pDbHostApp = acdbHostApplicationServices();
};
