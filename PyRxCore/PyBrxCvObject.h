#pragma once


#ifdef BRXAPP

#include "PyDbCurve.h"
#include "BrxCvDbObject.h"
#include "BrxCvDbEntity.h"
#include "BrxCvDbCurve.h"
#include "BrxCvDbSubObject.h"

class PyDbObjectId;
class PyDbDatabase;

//-----------------------------------------------------------------------------------
//PyBrxCvDbSubObject
void makePyBrxCvDbSubObjectWrapper();

class PyBrxCvDbSubObject : public PyRxObject
{
public:

    PyBrxCvDbSubObject(BrxCvDbSubObject* ptr, bool autoDelete);
    virtual ~PyBrxCvDbSubObject() override = default;

    std::string             name() const;
    bool                    setName(const std::string& szName);
    std::string             description() const;
    bool                    setDescription(const std::string& szDescription);
    static std::string      className();
    static PyRxClass        desc();
    static PyBrxCvDbSubObject  cast(const PyRxObject& src);

public:
    inline BrxCvDbSubObject* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyBrxCvDbObject
void makePyBrxCvDbObjectWrapper();

class PyBrxCvDbObject : public PyDbObject
{
public:
    PyBrxCvDbObject(const PyDbObjectId& id);
    PyBrxCvDbObject(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyBrxCvDbObject(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    PyBrxCvDbObject(BrxCvDbObject* ptr, bool autoDelete);
    virtual ~PyBrxCvDbObject() override = default;

    std::string                 name() const;
    bool                        setName(const std::string& szName);
    std::string                 description() const;
    bool                        setDescription(const std::string& szDescription);

    static std::string          className();
    static PyRxClass            desc();
    static PyBrxCvDbObject      cloneFrom(const PyRxObject& src);
    static PyBrxCvDbObject      cast(const PyRxObject& src);

public:
    inline BrxCvDbObject* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyBrxCvDbEntity
void makePyBrxCvDbEntityWrapper();

class PyBrxCvDbEntity : public PyDbEntity
{
public:
    PyBrxCvDbEntity(const PyDbObjectId& id);
    PyBrxCvDbEntity(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyBrxCvDbEntity(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    PyBrxCvDbEntity(BrxCvDbEntity* ptr, bool autoDelete);
    virtual ~PyBrxCvDbEntity() override = default;

    std::string             name() const;
    bool                    setName(const std::string& szName);
    std::string             description() const;
    bool                    setDescription(const std::string& szDescription);

    static std::string      className();
    static PyRxClass        desc();
    static PyBrxCvDbEntity  cloneFrom(const PyRxObject& src);
    static PyBrxCvDbEntity  cast(const PyRxObject& src);
public:
    inline BrxCvDbEntity* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyBrxCvDbCurve
void makePyBrxCvDbCurveWrapper();

class PyBrxCvDbCurve : public PyDbCurve
{
public:
    PyBrxCvDbCurve(const PyDbObjectId& id);
    PyBrxCvDbCurve(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyBrxCvDbCurve(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    PyBrxCvDbCurve(BrxCvDbCurve* ptr, bool autoDelete);
    virtual ~PyBrxCvDbCurve() override = default;

    std::string                 name() const;
    bool                        setName(const std::string& szName);
    std::string                 description() const;
    bool                        setDescription(const std::string& szDescription);

    static std::string          className();
    static PyRxClass            desc();
    static PyBrxCvDbCurve       cloneFrom(const PyRxObject& src);
    static PyBrxCvDbCurve       cast(const PyRxObject& src);

public:
    inline BrxCvDbCurve* impObj(const std::source_location& src = std::source_location::current()) const;
};
#endif//BRXAPP
