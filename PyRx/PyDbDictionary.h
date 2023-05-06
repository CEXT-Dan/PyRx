#pragma once
#include "PyDbObject.h"

void makeAcDbDictionaryWrapper();

//---------------------------------------------------------------------------------------- -
//PyDbDictionary
class PyDbDictionary : public PyDbObject
{
public:
    PyDbDictionary(AcDbDictionary* ptr, bool autoDelete);
    PyDbDictionary(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbDictionary() override = default;
    PyDbObjectId getAt(const std::string& entryName);
    bool has(const std::string& entryName);
    boost::python::dict asDict();

    static std::string className();
public:
    AcDbDictionary* impObj(const std::source_location& src = std::source_location::current()) const;
};
