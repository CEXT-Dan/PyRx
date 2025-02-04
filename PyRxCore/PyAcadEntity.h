#pragma once

#include "PyAcadDbObject.h"
#pragma pack (push, 8)

class PyIAcadEntityImpl;
class PyIAcad3DFaceImpl;
class PyIAcadPolygonMeshImpl;
class PyIAcad3DPolylineImpl;
class PyIAcadArcImpl;
class PyIAcadAttributeImpl;
class PyIAcadRegionImpl;
class PyIAcad3DSolidImpl;
class PyIAcadCircleImpl;

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

//----------------------------------------------------------------------------------------
//PyAcad3DPolyline
void makePyAcad3DPolylineWrapper();

class PyAcad3DPolyline : public PyAcadEntity
{
public:
    PyAcad3DPolyline() = default;
    PyAcad3DPolyline(std::shared_ptr<PyIAcad3DPolylineImpl> ptr);
    virtual ~PyAcad3DPolyline() override = default;
    static PyAcad3DPolyline cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcad3DPolylineImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadArc
void makePyAcadArcWrapper();

class PyAcadArc : public PyAcadEntity
{
public:
    PyAcadArc() = default;
    PyAcadArc(std::shared_ptr<PyIAcadArcImpl> ptr);
    virtual ~PyAcadArc() override = default;
    static PyAcadArc cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadArcImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadAttribute
void makePyAcadAttributeWrapper();

class PyAcadAttribute : public PyAcadEntity
{
public:
    PyAcadAttribute() = default;
    PyAcadAttribute(std::shared_ptr<PyIAcadAttributeImpl> ptr);
    virtual ~PyAcadAttribute() override = default;
    static PyAcadAttribute cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadAttributeImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadRegion
void makePyAcadRegionWrapper();

class PyAcadRegion : public PyAcadEntity
{
public:
    PyAcadRegion() = default;
    PyAcadRegion(std::shared_ptr<PyIAcadRegionImpl> ptr);
    virtual ~PyAcadRegion() override = default;
    static PyAcadRegion cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadRegionImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcad3DSolid
void makePyAcad3DSolidWrapper();

class PyAcad3DSolid : public PyAcadEntity
{
public:
    PyAcad3DSolid() = default;
    PyAcad3DSolid(std::shared_ptr<PyIAcad3DSolidImpl> ptr);
    virtual ~PyAcad3DSolid() override = default;
    static PyAcad3DSolid cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcad3DSolidImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadCircle
void makePyAcadCircleWrapper();

class PyAcadCircle : public PyAcadEntity
{
public:
    PyAcadCircle() = default;
    PyAcadCircle(std::shared_ptr<PyIAcadCircleImpl> ptr);
    virtual ~PyAcadCircle() override = default;
    static PyAcadCircle cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadCircleImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};



#pragma pack (pop)