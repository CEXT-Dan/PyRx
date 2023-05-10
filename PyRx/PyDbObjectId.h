#pragma once
#include "PyDbDatabase.h"

void makeAcDbObjectIdWrapper();

class PyDbObjectId
{
public:
    PyDbObjectId();
    PyDbObjectId(const AcDbObjectId& id);

    bool operator==(const PyDbObjectId& rhs) const;
    bool operator!=(const PyDbObjectId& rhs) const;

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


class AdsName
{
    std::array<int64_t, 2> m_data;
};