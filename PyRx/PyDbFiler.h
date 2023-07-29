#pragma once
#include "PyRxObject.h"

class PyDbObjectId;
class PyDbSoftOwnershipId;
class PyDbHardOwnershipId;

//-----------------------------------------------------------------------------------------
//PyDbDwgFiler
void makePyDbDwgFilerWrapper();
class PyDbDwgFiler : public PyRxObject
{
    PyDbDwgFiler(AcDbDwgFiler* ptr, bool autoDelete);
    virtual ~PyDbDwgFiler() = default;

    Acad::ErrorStatus   filerStatus() const;
    AcDb::FilerType     filerType() const;
    void                setFilerStatus(Acad::ErrorStatus es);
    void                resetFilerStatus();
    boost::python::tuple dwgVersion() const;
    AcDb::MaintenanceReleaseVersion extendedDwgMaintenanceReleaseVersion() const;

    PyDbObjectId        readHardOwnershipId();
    void                writeHardOwnershipId(const PyDbObjectId& id);
    PyDbObjectId        readSoftOwnershipId();
    void                writeSoftOwnershipId(const PyDbObjectId& id);
    PyDbObjectId        readHardPointerId();
    void                writeHardPointerId(const PyDbObjectId& id);
    PyDbObjectId        readSoftPointerId();
    void                writeSoftPointerId(const PyDbObjectId& id);

    static PyRxClass    desc();
    static std::string  className();
public:
    inline AcDbDwgFiler* impObj(const std::source_location& src = std::source_location::current()) const;
};

