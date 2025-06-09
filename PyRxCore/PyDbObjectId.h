#pragma once
#include "PyDbDatabase.h"

#pragma pack (push, 8)

class PyAcadObject;
//-----------------------------------------------------------------------------------------
//PyDbObjectId
void makePyDbObjectIdWrapper();
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
    void          setFromOldId(INT_PTR oldId);
    bool          isNull() const;
    bool          isResident() const;
    bool          isValid() const;
    bool          isWellBehaved() const;
    bool          convertToRedirectedId();
    bool          isErased() const;
    bool          isEffectivelyErased() const;
    bool          objectLeftOnDisk() const;
    PyDbHandle    handle() const;
    PyDbHandle    nonForwardedHandle() const;
    std::string   repr() const;
    std::string   str() const;
    PyDbDatabase  database() const;
    PyDbDatabase  originalDatabase() const;
    PyRxClass     objectClass() const;
    bool          isDerivedFrom(const PyRxClass& other) const;
    std::size_t   hash() const;
    PyAcadObject  acadObject() const;
    static PyDbObjectId fromOldId(INT_PTR oldId);

public:
    AcDbObjectId m_id;
};

typedef std::vector<PyDbObjectId> PyDbObjectIdArray;

inline boost::python::list ObjectIdArrayToPyList(const AcDbObjectIdArray& arr)
{
    PyAutoLockGIL lock;
    boost::python::list pyList;
    for (const auto& id : arr)
        pyList.append(PyDbObjectId(id));
    return pyList;
}

inline AcDbObjectIdArray PyListToObjectIdArray(const boost::python::object& iterable)
{
    auto vec{ py_list_to_std_vector<PyDbObjectId>(iterable) };
    AcDbObjectIdArray arr;
    arr.setPhysicalLength(vec.size());
    for (auto& item : vec)
        arr.append(item.m_id);
    return arr;
}

template<typename T>
inline T* openAcDbObject(const PyDbObjectId& id, AcDb::OpenMode mode = AcDb::kForRead, bool erased = false)
{
    T* pobj = nullptr;
    PyThrowBadEs(acdbOpenObject<T>(pobj, id.m_id, mode, erased));
    return pobj;
}

//-----------------------------------------------------------------------------------------
//AdsName
void makePyAdsNameWrapper();
class AdsName
{
public:
    PyDbObjectId toObjectId() const;
    void fromObjectId(const PyDbObjectId& id);
public:
    std::array<int64_t, 2> m_data = { 0 };
};

//-----------------------------------------------------------------------------------------
//PyDbHardPointerId
void makePyDbHardPointerIdWrapper();
class PyDbHardPointerId : public PyDbObjectId
{
public:
    PyDbHardPointerId();
    PyDbHardPointerId(const PyDbObjectId& id);
    PyDbHardPointerId& operator =(const PyDbHardPointerId& rhs);
    PyDbHardPointerId& operator =(const PyDbObjectId& rhs);
public:
    AcDbHardPointerId m_id;
};

//-----------------------------------------------------------------------------------------
//PyDbHardOwnershipId
void makePyDbAcDbHardOwnershipIdWrapper();
class PyDbHardOwnershipId : public PyDbObjectId
{
public:
    PyDbHardOwnershipId();
    PyDbHardOwnershipId(const PyDbObjectId& id);
    PyDbHardOwnershipId& operator =(const PyDbHardOwnershipId& rhs);
    PyDbHardOwnershipId& operator =(const PyDbObjectId& rhs);
public:
    AcDbHardOwnershipId m_id;
};

//-----------------------------------------------------------------------------------------
//PyDbSoftPointerId
void makePySoftPointerIdWrapper();
class PyDbSoftPointerId : public PyDbObjectId
{
public:
    PyDbSoftPointerId();
    PyDbSoftPointerId(const PyDbObjectId& id);
    PyDbSoftPointerId& operator =(const PyDbSoftPointerId& rhs);
    PyDbSoftPointerId& operator =(const PyDbObjectId& rhs);
public:
    AcDbSoftPointerId m_id;
};

//-----------------------------------------------------------------------------------------
//PyDbSoftOwnershipId
void makePyDbSoftOwnershipIdWrapper();
class PyDbSoftOwnershipId : public PyDbObjectId
{
public:
    PyDbSoftOwnershipId();
    PyDbSoftOwnershipId(const PyDbObjectId& id);
    PyDbSoftOwnershipId& operator =(const PyDbSoftOwnershipId& rhs);
    PyDbSoftOwnershipId& operator =(const PyDbObjectId& rhs);
public:
    AcDbSoftOwnershipId m_id;
};

//-----------------------------------------------------------------------------------------
//PyDbHandle
void makePyDbHandleWrapper();
class PyDbHandle
{
public:
    PyDbHandle();
    PyDbHandle(int lo, int hi);
    PyDbHandle(const std::string& src);
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
    std::size_t    hash() const;
    void           increment(void);
    void           decrement(void);
    bool operator==(const PyDbHandle& rhs) const;
    bool operator!=(const PyDbHandle& rhs) const;

public:
    AcDbHandle m_hnd;
};

//-----------------------------------------------------------------------------------------
//PyDbXrefObjectId
void makePyDbXrefObjectIdWrapper();
class PyDbXrefObjectId
{
#if !defined(_BRXTARGET250)
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
    AcDbXrefObjectId m_imp;
#endif
};

#pragma pack (pop)