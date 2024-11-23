#pragma once
#ifdef BRXAPP
#ifndef _BRXTARGET240
class PyDbObjectId;
class PyDbAcValue;

void makePyBrxDbPropertiesWrapper();

class PyBrxDbProperties
{
public:
    static void                 dumpAll(const PyDbObjectId& id);
    static boost::python::list  listAll(const PyDbObjectId& id);
    static boost::python::tuple isValid(const PyDbObjectId& id, const std::string& propertyName);
    static boost::python::tuple isReadOnly(const PyDbObjectId& id, const std::string& propertyName);
    static PyDbAcValue          getValue(const PyDbObjectId& id, const std::string& propertyName);
    static void                 setValue(const PyDbObjectId& id, const std::string& propertyName, const PyDbAcValue& value);
};

#endif
#endif