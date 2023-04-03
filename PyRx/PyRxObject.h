#pragma once
#include "boost/shared_ptr.hpp"
class PyRxClass;

void makeAcRxObjectWrapper();
//-----------------------------------------------------------------------------------------
//PyRxObject
class PyRxObject
{
public:
    PyRxObject(AcRxObject* ptr, bool autoDelete);
    virtual ~PyRxObject();

    bool operator==(const PyRxObject& rhs) const;
    bool operator!=(const PyRxObject& rhs) const;

    virtual PyRxClass isA() const;
    void deleteNativeObject();
    bool isNull();
    static std::string className();

public:
    AcRxObject* impObj() const;

protected:
    AcRxObject* m_pImp = nullptr;
    bool m_bAutoDelete = false;
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

