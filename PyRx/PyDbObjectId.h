#pragma once
#include "PyDbDatabase.h"

void makeAcDbObjectIdWrapper();

class PyDbObjectId
{
public:
    PyDbObjectId();
    PyDbObjectId(const AcDbObjectId& id);
    INT_PTR asOldId() const;
    PyDbObjectId& setFromOldId(INT_PTR oldId);
    bool isNull() const;
    bool isResident() const;
    bool isValid() const;
    bool isWellBehaved() const;
    bool convertToRedirectedId();

    PyDbDatabase database() const;
    PyDbDatabase originalDatabase() const;
    PyRxClass objectClass() const;

public:
    AcDbObjectId m_id;
};

