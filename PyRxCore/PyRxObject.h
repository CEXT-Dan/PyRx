#pragma once
#pragma pack (push, 8)
class PyRxClass;

//-----------------------------------------------------------------------------------------
//PyRxObject
void makePyRxObjectWrapper();

class PyRxObject
{
public:
    PyRxObject(const AcRxObject* ptr);
    PyRxObject(AcRxObject* ptr, bool autoDelete, bool isDbObject);
    virtual ~PyRxObject() = default;
    bool operator==(const PyRxObject& rhs) const;
    bool operator!=(const PyRxObject& rhs) const;
    PyRxClass           isA() const;
    bool                isDerivedFrom(const PyRxClass& other) const;
    bool                isKindOf(const PyRxClass& aClass) const;
    void                forceKeepAlive(bool flag) const;
    bool                isKeptAlive() const;
    void                setInternalClosed(bool flag) const;
    bool                isInternalClosed() const;
    bool                isAutoDelete() const;
    void                setAutoDelete(bool flag) const;
    void                dispose();
    bool                isNullObj() const;
    int                 implRefCount() const;
    INT_PTR             intPtr();
    void                copyFrom(PyRxObject& obj) const;
    PyRxObject          queryX(const PyRxClass& protocolClass) const;
    AcRx::Ordering      comparedTo(const PyRxObject& other) const;
    std::size_t         hash() const;
    static PyRxClass    desc();
    static std::string  className();
public:
    AcRxObject* impObj(const std::source_location& src = std::source_location::current()) const;

public:
    std::shared_ptr<AcRxObject> m_pyImp;
};

template<typename T>
inline T PyRxObjectCast(const PyRxObject& src)
{
    T dest(nullptr, false, false);
    dest.m_pyImp = src.m_pyImp;
    return dest;
}

//-----------------------------------------------------------------------------------------
//PyRxClass
void makePyRxClassWrapper();

class PyRxClass : public PyRxObject
{
public:
    PyRxClass(AcRxClass* ptr, bool autoDelete);
    virtual ~PyRxClass() override = default;
    bool                isDerivedFrom(const PyRxClass& other) const;
    std::string         name() const;
    std::string         appName() const;
    std::string         dxfName() const;
    PyRxObject          queryX(const PyRxClass& protocolClass) const;
    PyRxClass           myParent() const;
    static PyRxClass    desc();
    static std::string  className();

public:
    AcRxClass* impObj(const std::source_location& src = std::source_location::current()) const;
};

inline AcRxClassArray PyListToAcRxClassArray(const boost::python::object& iterable) 
{
    PyAutoLockGIL lock;
    AcRxClassArray arr;
    int length = boost::python::len(iterable);
    arr.setPhysicalLength(length);
    boost::python::stl_input_iterator<PyRxClass> begin(iterable), end;
    for (auto it = begin; it != end; ++it) {
        arr.append(it->impObj());
    }
    return arr;
}


#pragma pack (pop)