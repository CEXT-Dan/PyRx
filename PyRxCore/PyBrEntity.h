#pragma once

#include "PyDbEntity.h"
#pragma pack (push, 8)

class PyGeBoundBlock3d;


//-----------------------------------------------------------------------------------------
//PyBrEntity
void makePyBrEntityWrapper();

class PyBrEntity : public PyRxObject
{
public:
    PyBrEntity(const AcRxObject* ptr);
    PyBrEntity(AcRxObject* ptr, bool autoDelete);
    inline virtual ~PyBrEntity() = default;

    Adesk::Boolean              isEqualTo(const PyRxObject& other) const;
    Adesk::Boolean              isNull() const;

    PyDbFullSubentPath          getSubentPath() const;
    void                        setSubentPath(PyDbFullSubentPath& subpath);

    Adesk::Boolean		        checkEntity() const;
    PyGeBoundBlock3d            getBoundBlock() const;

    boost::python::tuple        getPointContainment(const AcGePoint3d& point);



    static PyRxClass            desc();
    static std::string          className();
public:
    inline AcBrEntity* impObj(const std::source_location& src = std::source_location::current()) const;
};


#pragma pack (pop)