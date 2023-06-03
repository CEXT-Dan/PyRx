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
    std::string repr();
    std::string str();
    PyDbDatabase database() const;
    PyDbDatabase originalDatabase() const;
    PyRxClass objectClass() const;
    bool isDerivedFrom(const PyRxClass& other) const;
    std::size_t hash();

public:
    AcDbObjectId m_id;
};

//
void makeAdsNameWrapper();
class AdsName
{
public:
    PyDbObjectId toObjectId() const;
    void fromObjectId(const PyDbObjectId& id);
public:
    std::array<int64_t, 2> m_data;
};

//
void makePyDbHardPointerIdWrapper();
class PyDbHardPointerId : public PyDbObjectId
{
public:
    PyDbHardPointerId();
    PyDbHardPointerId(const PyDbObjectId& id);
    PyDbHardPointerId& operator =(const PyDbHardPointerId& rhs);
    PyDbHardPointerId& operator =(const PyDbObjectId& rhs);
    bool operator==(const PyDbHardPointerId& rhs) const;
    bool operator!=(const PyDbHardPointerId& rhs) const;
public:
    AcDbHardPointerId m_id;
};

//
void makePySoftPointerIdWrapper();
class PyDbSoftPointerId : public PyDbObjectId
{
public:
    PyDbSoftPointerId();
    PyDbSoftPointerId(const PyDbObjectId& id);
    PyDbSoftPointerId& operator =(const PyDbSoftPointerId& rhs);
    PyDbSoftPointerId& operator =(const PyDbObjectId& rhs);
    bool operator==(const PyDbSoftPointerId& rhs) const;
    bool operator!=(const PyDbSoftPointerId& rhs) const;
public:
    AcDbSoftPointerId m_id;
};