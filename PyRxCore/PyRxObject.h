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
    bool                isKindOf(const PyRxClass& aClass);
    void                forceKeepAlive(bool flag);
    void                dispose();
    bool                isNullObj();
    int                 implRefCount();
    void                copyFrom(PyRxObject& obj);
    PyRxObject          queryX(const PyRxClass& protocolClass) const;
    AcRx::Ordering      comparedTo(const PyRxObject& other) const;
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
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
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
    std::string         name();
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
    auto vec = py_list_to_std_vector<PyRxClass>(iterable);
    AcRxClassArray arr;
    arr.setPhysicalLength(vec.size());
    for (auto& item : vec)
        arr.append(item.impObj());
    return arr;
}
#pragma pack (pop)