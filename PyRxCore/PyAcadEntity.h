#pragma once

#include "PyAcadDbObject.h"
#pragma pack (push, 8)

class PyIAcadEntityImpl;
class PyIAcad3DFaceImpl;
class PyIAcadPolygonMeshImpl;

//----------------------------------------------------------------------------------------
//PyAcadEntity
void makePyAcadEntityWrapper();

class PyAcadEntity : public PyAcadObject
{
public:
    PyAcadEntity() = default;
    PyAcadEntity(std::shared_ptr<PyIAcadEntityImpl> ptr);
    virtual ~PyAcadEntity() override = default;

    void    transformBy(const AcGeMatrix3d& xform);
    
    static PyAcadEntity cast(const PyAcadObject& src);
    static std::string  className();
public:
    PyIAcadEntityImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcad3DFace
void makePyAcad3DFaceWrapper();

class PyAcad3DFace : public PyAcadEntity
{
public:
    PyAcad3DFace() = default;
    PyAcad3DFace(std::shared_ptr<PyIAcad3DFaceImpl> ptr);
    virtual ~PyAcad3DFace() override = default;
    boost::python::list coordinates() const;
    void                setCoordinates(const AcGePoint3d& p1, const AcGePoint3d& p2, const AcGePoint3d& p3, const AcGePoint3d& p4);
    bool                invisibleEdge(int index) const;
    void                setInvisibleEdge(int index, bool flag) const;
    AcGePoint3d         coordinate(int index) const;
    void                setCoordinate(int index, const AcGePoint3d& val);
    static PyAcad3DFace cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcad3DFaceImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadPolygonMesh
void makePyAcadPolygonMeshWrapper();

class PyAcadPolygonMesh : public PyAcadEntity
{
public:
    PyAcadPolygonMesh() = default;
    PyAcadPolygonMesh(std::shared_ptr<PyIAcadPolygonMeshImpl> ptr);
    virtual ~PyAcadPolygonMesh() override = default;
    static PyAcadPolygonMesh cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadPolygonMeshImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};




#pragma pack (pop)