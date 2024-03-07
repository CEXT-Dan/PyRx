#pragma once

#include "PyBrxCvObject.h"

#ifdef BRXAPP
#include "BrxCvDbObjectManager.h"
#include "BrxCvDbFileFormatManager.h"
class PyDbObjectId;

//-----------------------------------------------------------------------------------
//PyBrxCvDbObjectManager
void makePyBrxCvDbObjectManagerWrapper();

class PyBrxCvDbObjectManager : public PyBrxCvDbObject
{
public:
    PyBrxCvDbObjectManager(const PyDbObjectId& id);
    PyBrxCvDbObjectManager(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyBrxCvDbObjectManager(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    PyBrxCvDbObjectManager(BrxCvDbObjectManager* ptr, bool autoDelete);
    virtual ~PyBrxCvDbObjectManager() override = default;

    Adesk::UInt32       elementCount();
    boost::python::list ids();
    boost::python::list names();
    PyDbObjectId        idAt1(const Adesk::UInt32 index);
    PyDbObjectId        idAt2(const std::string& szName);
    std::string         nameAt(const Adesk::UInt32 index);
    bool                has1(const PyDbObjectId& id);
    bool                has2(const  std::string& szName);
    bool                remove1(const PyDbObjectId& id);
    bool                remove2(const std::string& szName);

    static std::string          className();
    static PyRxClass            desc();
    static PyBrxCvDbObjectManager      cloneFrom(const PyRxObject& src);
    static PyBrxCvDbObjectManager      cast(const PyRxObject& src);

public:
    inline BrxCvDbObjectManager* impObj(const std::source_location& src = std::source_location::current()) const;
};


//-----------------------------------------------------------------------------------
// PyBrxCvDbFileFormatManager
void makePyBrxCvDbFileFormatManagerWrapper();

class PyBrxCvDbFileFormatManager : public PyBrxCvDbObjectManager
{
public:
    PyBrxCvDbFileFormatManager(const PyDbObjectId& id);
    PyBrxCvDbFileFormatManager(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyBrxCvDbFileFormatManager(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    PyBrxCvDbFileFormatManager(BrxCvDbFileFormatManager* ptr, bool autoDelete);
    virtual ~PyBrxCvDbFileFormatManager() override = default;

    boost::python::list                 applicableFileFormats(const std::string& fileName);
    boost::python::list                 allFileFormats();

    static PyDbObjectId                 getManager(PyDbDatabase& db);
    static PyBrxCvDbFileFormatManager   openManager(PyDbDatabase& db, AcDb::OpenMode mode);

    static std::string                  className();
    static PyRxClass                    desc();
    static PyBrxCvDbFileFormatManager   cloneFrom(const PyRxObject& src);
    static PyBrxCvDbFileFormatManager   cast(const PyRxObject& src);

public:
    inline BrxCvDbFileFormatManager* impObj(const std::source_location& src = std::source_location::current()) const;
};



#endif//BRXAPP
