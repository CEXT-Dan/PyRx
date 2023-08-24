#pragma once
class PyRxClass;

// if the object is dbo, close it and return out
// objects that derived from PyDbObject have m_isDbObject set to true
// id the object is some sort of global pointer or should not be deleted m_autoDelete should be false
// examples would be document or current database
// note: PyDbObject::cast resets the pointer, which call this, but it's not a double delete
// define PyRxDebug when running unit tests


//this crashes for objects that are opened in a side database
//and the side database is deleted. one idea is to store an objectID here
//use AcDbObjectId.isValid()
struct PyRxObjectDeleter
{
    inline PyRxObjectDeleter(bool autoDelete, bool isDbObject)
        : m_autoDelete(autoDelete), m_isDbObject(isDbObject)
    {
    }

    inline bool isDbroThenClose(AcRxObject* p) const
    {
#ifdef NEVER
        if (IsBadReadPtr(p, sizeof(AcRxObject)))
            return true;
#endif
        if (!m_isDbObject)
        {
            return false;
        }
        else if (m_forceKeepAlive)
        {
            return true;
        }
        else if (p->isA()->isDerivedFrom(AcDbObject::desc()))//very negligible impact on performance .01 @ 50,000 entities  
        {
            auto dbo = static_cast<AcDbObject*>(p);
            if (!dbo->objectId().isNull())
            {
                if (auto es = dbo->close(); es != eOk)
                    acutPrintf(_T("\nStatus = %ls in %ls: "), acadErrorStatusText(es), __FUNCTIONW__);
                return true;
            }
        }
        return false;
    }

    inline void operator()(AcRxObject* p) const
    {
        if (p == nullptr) [[unlikely]]
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
    inline virtual ~PyRxObject() = default;
    bool operator==(const PyRxObject& rhs) const;
    bool operator!=(const PyRxObject& rhs) const;
    PyRxClass           isA() const;
    bool                isKindOf(const PyRxClass& aClass);
    void                forceKeepAlive(bool flag);
    void                dispose();
    bool                isNullObj();
    int                 implRefCount();
    PyRxObject          queryX(const PyRxClass& protocolClass) const;
    static PyRxClass    desc();
    static std::string  className();
public:
    inline AcRxObject* impObj(const std::source_location& src = std::source_location::current()) const;

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
    inline AcRxClass* impObj(const std::source_location& src = std::source_location::current()) const;
};

