#pragma once
#pragma pack (push, 8)
class PyRxClass;

//-----------------------------------------------------------------------------------------
//PyRxObject
void makePyRxObjectWrapper();

struct PyRxObjectDeleter
{
    inline PyRxObjectDeleter(bool autoDelete, bool isDbObject)
        : m_autoDelete(autoDelete), m_isDbObject(isDbObject)
    {
    }

    inline bool isDbroThenClose(AcRxObject* p) const
    {
        if (m_isDbObject)
        {
            AcDbObject* pDbo = static_cast<AcDbObject*>(p);
            if (!pDbo->objectId().isNull())
            {
                if (const auto es = pDbo->close(); es != eOk) [[unlikely]]
                    acutPrintf(_T("\nStatus = %ls in %ls: "), acadErrorStatusText(es), __FUNCTIONW__);
                return true;
            }
        }
        return false;
    }

    inline void operator()(AcRxObject* p) const
    {
        if (p == nullptr)
            return;
        if (m_forceKeepAlive)
            return;
        else if (m_internalClosed)
            return;
        else if (isDbroThenClose(p))
            return;
        else if (!m_autoDelete)
            return;
        else
            delete p;
    }

    inline bool isAutoDelete() const
    {
        return m_autoDelete;
    }

    inline void setAutoDelete(bool flag)
    {
        m_autoDelete = flag;
    }

    inline bool isKeptAlive() const
    {
        return m_forceKeepAlive;
    }

    inline void setKeepAlive(bool flag)
    {
        m_forceKeepAlive = flag;
    }

    inline bool isInternalClosed() const
    {
        return m_internalClosed;
    }

    inline void setInternalClosed(bool flag)
    {
        m_internalClosed = flag;
    }

    bool m_autoDelete = true;
    bool m_isDbObject = false;
    bool m_forceKeepAlive = false;
    bool m_internalClosed = false;
};

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

AcRxClassArray PyListToAcRxClassArray(const boost::python::object& iterable);



#pragma pack (pop)