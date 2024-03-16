#pragma once
#include "dbSubD.h"
#include "PyDbEntity.h"


//-------------------------------------------------------------------------------------------------------------
//PyDbSubDMesh
void makePyDbSubDMeshWrapper();

class PyDbSubDMesh : public PyDbEntity
{
public:
    PyDbSubDMesh();
    PyDbSubDMesh(const PyDbObjectId& id);
    PyDbSubDMesh(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyDbSubDMesh(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    PyDbSubDMesh(AcDbSubDMesh* ptr, bool autoDelete);
    inline virtual ~PyDbSubDMesh() override = default;

    void setSubDMesh(const boost::python::list& vertexArray, const boost::python::list& faceArray, int subDLevel);
    void setSphere(double radius,int divAxis,int divHeight,int subDLevel);
    void setCylinder(double majorRadius,double minorRadius,double height,int divAxis,int divHeight, int divCap,int subDLevel);
    

    static std::string      className();
    static PyRxClass        desc();
    static PyDbSubDMesh     cloneFrom(const PyRxObject& src);
    static PyDbSubDMesh     cast(const PyRxObject& src);
public:
    inline  AcDbSubDMesh* impObj(const std::source_location& src = std::source_location::current()) const;
};

