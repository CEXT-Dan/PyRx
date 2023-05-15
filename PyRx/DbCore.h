#pragma once

class PyDbObject;
class PyDbObjectId;
class PyDbEntity;

void makeDbCoreWrapper();

class DbCore
{
public:
    static int regApp(const std::string& app);
    static PyDbObject openDbObject(const PyDbObjectId& id, AcDb::OpenMode mode);
    static PyDbEntity openDbEntity(const PyDbObjectId& id, AcDb::OpenMode mode);
};

