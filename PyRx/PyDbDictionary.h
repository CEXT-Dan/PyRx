#pragma once
#include "PyDbObject.h"
class PyDbDictionary : public PyDbObject
{
public:
    PyDbDictionary(AcDbDictionary* ptr, bool autoDelete);
    PyDbDictionary(const PyDbObjectId& id, AcDb::OpenMode mode);
    virtual ~PyDbDictionary() override = default;

    PyDbObjectId getAt(const std::string& entryName);

public:
    AcDbDictionary* impObj() const;
};

