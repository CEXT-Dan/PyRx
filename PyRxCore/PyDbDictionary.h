#pragma once
#include "PyDbObject.h"

#pragma pack (push, 8)

//---------------------------------------------------------------------------------------- -
//PyDbDictionary
void makePyDbDictionaryWrapper();

class PyDbDictionary : public PyDbObject
{
public:
    PyDbDictionary();
    PyDbDictionary(AcDbDictionary* ptr, bool autoDelete);
    PyDbDictionary(const PyDbObjectId& id);
    PyDbDictionary(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbDictionary(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    virtual ~PyDbDictionary() override = default;
    PyDbObjectId            getAt(const std::string& entryName) const;
    PyDbObjectId            getAtEx(const std::string& entryName) const;
    bool                    has1(const std::string& entryName) const;
    bool                    has2(const PyDbObjectId& id) const;
    std::string             nameAt(const PyDbObjectId& id) const;
    Adesk::UInt32           numEntries() const;
    PyDbObjectId            setAt(const std::string& srchKey, PyDbObject& newValue) const;
    void                    remove1(const std::string& key) const;
    void                    remove2(const std::string& key, PyDbObjectId& returnId) const;
    void                    remove3(const PyDbObjectId& objId) const;
    bool                    setName(const std::string& oldName, const std::string& newName) const;
    boost::python::dict     toDict() const;
    static std::string      className();
    static PyRxClass        desc();
    static PyDbDictionary   cloneFrom(const PyRxObject& src);
    static PyDbDictionary   cast(const PyRxObject& src);
public:
    AcDbDictionary* impObj(const std::source_location& src = std::source_location::current()) const;
};

//---------------------------------------------------------------------------------------- -
//PyDbDictionaryWithDefault
void makePyDbDictionaryWithDefaultWrapper();

class PyDbDictionaryWithDefault : public PyDbDictionary
{
public:
    PyDbDictionaryWithDefault();
    PyDbDictionaryWithDefault(const PyDbObjectId& id);
    PyDbDictionaryWithDefault(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbDictionaryWithDefault(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    PyDbDictionaryWithDefault(AcDbDictionaryWithDefault* ptr, bool autoDelete);
    virtual ~PyDbDictionaryWithDefault() override = default;

    PyDbObjectId            defaultId() const;
    void                    setDefaultId(const PyDbObjectId& newid);
    boost::python::tuple    getObjectBirthVersion() const;
   
    static std::string      className();
    static PyRxClass        desc();
    static PyDbDictionaryWithDefault   cloneFrom(const PyRxObject& src);
    static PyDbDictionaryWithDefault   cast(const PyRxObject& src);
public:
    AcDbDictionaryWithDefault* impObj(const std::source_location& src = std::source_location::current()) const;
};

#pragma pack (pop)
