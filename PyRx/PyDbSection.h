#pragma once
#include "PyDbEntity.h"
#include "DbSection.h"

//-----------------------------------------------------------------------------------
//PyDbSection
void makePyDbSectionWrapper();
class PyDbSection : public PyDbEntity
{
public:
    PyDbSection();
    PyDbSection(const boost::python::list& pts, const AcGeVector3d& verticalDir);
    PyDbSection(const boost::python::list& pts, const AcGeVector3d& verticalDir, const AcGeVector3d& vecViewingDir);
    PyDbSection(const PyDbObjectId& id);
    PyDbSection(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbSection(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    PyDbSection(AcDbSection* ptr, bool autoDelete);

    virtual ~PyDbSection() override = default;

    static std::string  className();
    static PyRxClass    desc();
    static PyDbSection	cloneFrom(const PyRxObject& src);
    static PyDbSection  cast(const PyRxObject& src);
public:
    inline AcDbSection* impObj(const std::source_location& src = std::source_location::current()) const;
};
