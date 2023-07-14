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
    bool operator<(const PyDbObjectId& rhs) const;
    bool operator>(const PyDbObjectId& rhs) const;
    bool operator<=(const PyDbObjectId& rhs) const;
    bool operator>=(const PyDbObjectId& rhs) const;
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
    std::array<int64_t, 2> m_data = { 0 };
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

//
void makePyDbHandleWrapper();
class PyDbHandle
{
public:
    PyDbHandle();
    PyDbHandle(int lo, int hi);
    PyDbHandle(const std::string& src );
    PyDbHandle(const Adesk::UInt64 src);
    bool           isNull() const;
    void           setNull();
    Adesk::UInt32  low() const;
    Adesk::UInt32  high() const;
    void           setLow(Adesk::UInt32 low);
    void           setHigh(Adesk::UInt32 high);
    void           setValue(Adesk::UInt64);
    bool           isOne(void) const;
    Adesk::UInt64  value() const;
    std::string    toString() const;
    std::string    repr() const;
    std::size_t    hash();
    bool operator==(const PyDbHandle& rhs) const;
    bool operator!=(const PyDbHandle& rhs) const;


public:
    AcDbHandle m_hnd;
};

void makePyDbXrefObjectIdWrapper();

class PyDbXrefObjectId
{
public:
    PyDbXrefObjectId();
    PyDbXrefObjectId(const AcDbXrefObjectId& id);
    bool operator== (const PyDbXrefObjectId& other) const;
    bool operator!= (const PyDbXrefObjectId& other) const;
    bool                isValid(void) const;
    bool                isXref(void) const;
    bool                isNull(void) const;
    void                setNull(void);
    void                setXrefId(PyDbObjectId& xrefBlkId, const PyDbHandle& hObject);
    void                getXrefId(PyDbObjectId& xrefBlkId, PyDbHandle& hObject) const;
    void                setLocalId(PyDbObjectId& objId);
    void                getLocalId(PyDbObjectId& objId) const;
    void                resolveObjectId(PyDbObjectId& id) const;
public:
#if defined(_BRXTARGET) && (_BRXTARGET <= 23)
    int m_imp;
#else
    AcDbXrefObjectId m_imp;
#endif

};