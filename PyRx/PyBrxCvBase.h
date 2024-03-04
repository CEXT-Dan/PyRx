#pragma once

#ifdef BRXAPP
#include "PyDbCurve.h"
#include "BrxCvDbObject.h"
#include "BrxCvDbEntity.h"
#include "BrxCvDbCurve.h"
#include "BrxCvCivil3dConverter.h"

class PyDbObjectId;
class PyDbDatabase;

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

    std::string     name() const;
    bool            setName(const std::string& szName);
    std::string     description() const;
    bool            setDescription(const std::string& szDescription);

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

    std::string     name() const;
    bool            setName(const std::string& szName);
    std::string     description() const;
    bool            setDescription(const std::string& szDescription);

    static std::string       className();
    static PyRxClass         desc();
    static PyBrxCvDbEntity   cloneFrom(const PyRxObject& src);
    static PyBrxCvDbEntity   cast(const PyRxObject& src);
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

    std::string     name() const;
    bool            setName(const std::string& szName);
    std::string     description() const;
    bool            setDescription(const std::string& szDescription);

    static std::string          className();
    static PyRxClass            desc();
    static PyBrxCvDbCurve       cloneFrom(const PyRxObject& src);
    static PyBrxCvDbCurve       cast(const PyRxObject& src);

public:
    inline BrxCvDbCurve* impObj(const std::source_location& src = std::source_location::current()) const;
};


//-----------------------------------------------------------------------------------
//PyBrxCvCivil3dEntityInfo
void makePyBrxCvCivil3dEntityInfoWrapper();

class PyBrxCvCivil3dEntityInfo
{
public:
    PyBrxCvCivil3dEntityInfo();
    PyBrxCvCivil3dEntityInfo(const BrxCvCivil3dEntityInfo& info);
    ~PyBrxCvCivil3dEntityInfo() = default;

    bool                    isNull() const;
    std::string             name() const;
    std::string             description() const;
    PyDbObjectId            objectId() const;

    BrxCvCivil3dEntityInfo::Civil3dEntityType       type() const;
    BrxCvCivil3dEntityInfo::Civil3dAlignmentType    alignmentType() const;
    BrxCvCivil3dEntityInfo::Civil3dProfileType      profileType() const;

    PyBrxCvCivil3dEntityInfo  baseAlignment() const;
    PyBrxCvCivil3dEntityInfo  baseSurface() const;
    boost::python::list       profiles() const;
    static std::string        className();

    inline BrxCvCivil3dEntityInfo* impObj(const std::source_location& src = std::source_location::current()) const;

public:
    std::shared_ptr <BrxCvCivil3dEntityInfo> pimpl;
};


//-----------------------------------------------------------------------------------
//PyBrxCvCivil3dConverter
void makePyBrxCvCivil3dConverterWrapper();

class PyBrxCvCivil3dConverter
{
public:
    PyBrxCvCivil3dConverter();
    PyBrxCvCivil3dConverter(const PyDbDatabase& sourceDb, PyDbDatabase& targetDb, BrxCvCivil3dConverter::Civil3dLabels doLabels);
    bool                        isValid() const;
    boost::python::list         getCivilEntities() const;
    boost::python::list         convert(const boost::python::list& entitiesToConvert);
    boost::python::list         attachedLabels(const PyBrxCvCivil3dEntityInfo& civilEntity) const;
    boost::python::list         unattachedLabels() const;
    boost::python::list         getInsertedEntities() const;
    static std::string          className();
public:
    inline BrxCvCivil3dConverter* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<BrxCvCivil3dConverter> impl;
};

#endif//BRXAPP

