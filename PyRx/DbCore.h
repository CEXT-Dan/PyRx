#pragma once

class PyDbObject;
class PyDbObjectId;
class PyDbEntity;

void makeDbCoreWrapper();

class DbCore
{
public:
    static bool entDel(const PyDbObjectId& id);
    static boost::python::list entGet(const PyDbObjectId& id);
    static PyDbObjectId entLast();
    static bool entMod(const boost::python::list& list);
    static PyDbObjectId entNext(const PyDbObjectId& id);
    static bool entUpd(const PyDbObjectId& id);
    static PyDbObject openDbObject(const PyDbObjectId& id, AcDb::OpenMode mode);
    static PyDbEntity openDbEntity(const PyDbObjectId& id, AcDb::OpenMode mode);
    static bool regApp(const std::string& app);
    static Acad::ErrorStatus updateDimension(const PyDbObjectId& id);
    static boost::python::list resbufTest(const boost::python::list& list);
};

