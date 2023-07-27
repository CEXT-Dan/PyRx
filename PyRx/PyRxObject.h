#pragma once
class PyRxClass;

// if the object is dbo, close it and return out
// objects that derived from PyDbObject have m_isDbObject set to true
// id the object is some sort of global pointer or should not be deleted m_autoDelete should be false
// examples would be document or current database
// note: PyDbObject::cast resets the pointer, which call this, but it's not a double delete
// define PyRxDebug when running unit tests

struct PyRxObjectDeleter
{
    inline PyRxObjectDeleter(bool autoDelete, bool isDbObject)
        : m_autoDelete(autoDelete), m_isDbObject(isDbObject)
    {
    }

    inline bool isDbroThenClose(AcRxObject* p) const
    {
        try
        {
            if (!m_isDbObject)
            {
                return false;
            }
            else if (p->isA()->isDerivedFrom(AcDbObject::desc()))
            {
                const auto dbo = static_cast<AcDbObject*>(p);
                if (!dbo->objectId().isNull())
                {
#ifdef PyRxDebug
                    if (auto es = dbo->close(); es != eOk)
                        acutPrintf(_T("\nStatus = %ls in %ls: "), acadErrorStatusText(es), __FUNCTIONW__);
#else
                    dbo->close();
#endif
                    return true;
                }
            }
        }
        catch (...)
        {

        }
        return false;
    }

    inline void operator()(AcRxObject* p) const
    {
        if (p == nullptr)
            return;
        else if (m_forceKeepAlive)
            return;
        else if (isDbroThenClose(p))
            return;
        else if (!m_autoDelete)
            return;
        else
            delete p;
    }

    bool m_autoDelete = true;
    bool m_isDbObject = false;
    bool m_forceKeepAlive = false;
};

//-----------------------------------------------------------------------------------------
//PyRxObject
void makeAcRxObjectWrapper();

class PyRxObject
{
public:
    PyRxObject(const AcRxObject* ptr);
    PyRxObject(AcRxObject* ptr, bool autoDelete, bool isDbObject);
    virtual ~PyRxObject();
    bool operator==(const PyRxObject& rhs) const;
    bool operator!=(const PyRxObject& rhs) const;
    PyRxClass           isA() const;
    void                resetImp(AcRxObject* ptr, bool autoDelete, bool isDbObject);
    void                forceKeepAlive(bool flag);
    bool                isNullObj();
    int                 implRefCount();
    PyRxObject          queryX(const PyRxClass& protocolClass) const;
    static PyRxClass    desc();
    static std::string  className();
public:
    AcRxObject* impObj(const std::source_location& src = std::source_location::current()) const;

public:
    std::shared_ptr<AcRxObject> m_pyImp;
};


//-----------------------------------------------------------------------------------------
//PyRxClass
void makeAcRxClassWrapper();

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
    static PyRxClass    desc();
    static std::string  className();

public:
    AcRxClass* impObj(const std::source_location& src = std::source_location::current()) const;
};

