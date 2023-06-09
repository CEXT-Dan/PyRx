#pragma once
class PyRxClass;

struct PyRxObjectDeleter
{
    inline PyRxObjectDeleter(bool autoDelete, bool isDbObject)
        : m_autoDelete(autoDelete), m_isDbObject(isDbObject)
    {
    }

    inline bool isDbroThenClose(AcRxObject* p) const
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
        else
        {
            return false;
        }
    }

    inline void operator()(AcRxObject* p) const
    {
#ifdef PyRxDebug
        std::wstring name;
        if (p != nullptr)
            name = p->isA()->name();
#endif
        if (p == nullptr)
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
};
void makeAcRxObjectWrapper();
//-----------------------------------------------------------------------------------------
//PyRxObject
class PyRxObject
{
public:
    PyRxObject(const AcRxObject* ptr);
    PyRxObject(AcRxObject* ptr, bool autoDelete, bool isDbObject);
    virtual ~PyRxObject();

    bool operator==(const PyRxObject& rhs) const;
    bool operator!=(const PyRxObject& rhs) const;

    PyRxClass isA() const;
    void resetImp(AcRxObject* ptr, bool autoDelete, bool isDbObject);
    bool isNull();
    int refCount();

    static PyRxClass desc();
    static std::string className();
public:
    AcRxObject* impObj(const std::source_location& src = std::source_location::current()) const;

public:
    std::shared_ptr<AcRxObject> m_pyImp;
};


void makeAcRxClassWrapper();
//-----------------------------------------------------------------------------------------
//PrRxClass
class PyRxClass : public PyRxObject
{
public:
    PyRxClass(AcRxClass* ptr, bool autoDelete);
    virtual ~PyRxClass() override = default;
    bool isDerivedFrom(const PyRxClass& other) const;
    std::string name();
    static PyRxClass desc();
    static std::string className();

public:
    AcRxClass* impObj(const std::source_location& src = std::source_location::current()) const;
};

