#pragma once
#include "boost/shared_ptr.hpp"
class PyRxClass;

struct PyRxObjectDeleter
{
    inline PyRxObjectDeleter(bool autoDelete, bool isDbObject)
        : m_autoDelete(autoDelete), m_isDbObject(isDbObject)
    {
    }

    inline bool isdbro(AcRxObject* p) const
    {
        if (!m_isDbObject)
            return false;
        if (p == nullptr)
            return false;
        if (p->isA()->isDerivedFrom(AcDbObject::desc()))
        {
            const auto dbo = static_cast<AcDbObject*>(p);
            if (!dbo->objectId().isNull())
            {
                dbo->close();
                return true;
            }
        }
        return false;
    }

    inline void operator()(AcRxObject* p) const
    {
        if (isdbro(p))
            return;
        if (!m_autoDelete)
            return;
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
    PyRxObject(AcRxObject* ptr, bool autoDelete, bool isDbObject);
    virtual ~PyRxObject();

    bool operator==(const PyRxObject& rhs) const;
    bool operator!=(const PyRxObject& rhs) const;

    virtual PyRxClass isA() const;
    virtual void resetImp(AcRxObject* ptr, bool autoDelete, bool isDbObject);
    bool isNull();
    static std::string className();
public:
    AcRxObject* impObj() const;

protected:
    std::shared_ptr<AcRxObject> m_pImp;
};


void makeAcRxClassWrapper();
//-----------------------------------------------------------------------------------------
//PrRxClass
class PyRxClass : public PyRxObject
{
public:
    PyRxClass(AcRxClass* ptr, bool autoDelete);
    virtual ~PyRxClass() override = default;
    std::string name();
    static std::string className();

public:
    AcRxClass* impObj() const;
};

