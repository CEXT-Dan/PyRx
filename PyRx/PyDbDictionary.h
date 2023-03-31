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
    boost::python::list keyValuePairs();

public:
    AcDbDictionary* impObj() const;
};
