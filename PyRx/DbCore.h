#pragma once

class PyDbObject;
class PyDbObjectId;
class PyDbEntity;

void makeDbCoreWrapper();

class DbCore
{
public:
    static boost::python::list entGet(const PyDbObjectId& id);
    static int entMod(const boost::python::list& list);
    static PyDbObject openDbObject(const PyDbObjectId& id, AcDb::OpenMode mode);
    static PyDbEntity openDbEntity(const PyDbObjectId& id, AcDb::OpenMode mode);
    static int regApp(const std::string& app);
    static Acad::ErrorStatus updateDimension(const PyDbObjectId& id);
};

