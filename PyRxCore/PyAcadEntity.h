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
class PyIAcadDimensionImpl;
class PyIAcadDimAlignedImpl;
class PyIAcadDimAngularImpl;
class PyIAcadDimDiametricImpl;
class PyIAcadDimRotatedImpl;
class PyIAcadDimOrdinateImpl;
class PyIAcadDimRadialImpl;
class PyIAcadDim3PointAngularImpl;
class PyIAcadDimArcLengthImpl;
class PyIAcadDimRadialLargeImpl;


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

//----------------------------------------------------------------------------------------
//PyAcadDimension
void makePyAcadDimensionWrapper();

class PyAcadDimension : public PyAcadEntity
{
public:
    PyAcadDimension() = default;
    PyAcadDimension(std::shared_ptr<PyIAcadDimensionImpl> ptr);
    virtual ~PyAcadDimension() override = default;
    static PyAcadDimension cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadDimensionImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadDimAligned
void makePyAcadDimAlignedWrapper();

class PyAcadDimAligned : public PyAcadDimension
{
public:
    PyAcadDimAligned() = default;
    PyAcadDimAligned(std::shared_ptr<PyIAcadDimAlignedImpl> ptr);
    virtual ~PyAcadDimAligned() override = default;
    static PyAcadDimAligned cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadDimAlignedImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadDimAngular
void makePyAcadDimAngularWrapper();

class PyAcadDimAngular : public PyAcadDimension
{
public:
    PyAcadDimAngular() = default;
    PyAcadDimAngular(std::shared_ptr<PyIAcadDimAngularImpl> ptr);
    virtual ~PyAcadDimAngular() override = default;
    static PyAcadDimAngular cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadDimAngularImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadDimDiametric
void makePyAcadDimDiametricWrapper();

class PyAcadDimDiametric : public PyAcadDimension
{
public:
    PyAcadDimDiametric() = default;
    PyAcadDimDiametric(std::shared_ptr<PyIAcadDimDiametricImpl> ptr);
    virtual ~PyAcadDimDiametric() override = default;
    static PyAcadDimDiametric cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadDimDiametricImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadDimRotated
void makePyAcadDimRotatedWrapper();

class PyAcadDimRotated : public PyAcadDimension
{
public:
    PyAcadDimRotated() = default;
    PyAcadDimRotated(std::shared_ptr<PyIAcadDimRotatedImpl> ptr);
    virtual ~PyAcadDimRotated() override = default;
    static PyAcadDimRotated cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadDimRotatedImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadDimOrdinate
void makePyAcadDimOrdinateWrapper();

class PyAcadDimOrdinate : public PyAcadDimension
{
public:
    PyAcadDimOrdinate() = default;
    PyAcadDimOrdinate(std::shared_ptr<PyIAcadDimOrdinateImpl> ptr);
    virtual ~PyAcadDimOrdinate() override = default;
    static PyAcadDimOrdinate cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadDimOrdinateImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadDimRadial
void makePyAcadDimRadialWrapper();

class PyAcadDimRadial : public PyAcadDimension
{
public:
    PyAcadDimRadial() = default;
    PyAcadDimRadial(std::shared_ptr<PyIAcadDimRadialImpl> ptr);
    virtual ~PyAcadDimRadial() override = default;
    static PyAcadDimRadial cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadDimRadialImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadDim3PointAngular
void makePyAcadDim3PointAngularWrapper();

class PyAcadDim3PointAngular : public PyAcadDimension
{
public:
    PyAcadDim3PointAngular() = default;
    PyAcadDim3PointAngular(std::shared_ptr<PyIAcadDim3PointAngularImpl> ptr);
    virtual ~PyAcadDim3PointAngular() override = default;
    static PyAcadDim3PointAngular cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadDim3PointAngularImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadDimArcLength
void makePyAcadDimArcLengthWrapper();

class PyAcadDimArcLength : public PyAcadDimension
{
public:
    PyAcadDimArcLength() = default;
    PyAcadDimArcLength(std::shared_ptr<PyIAcadDimArcLengthImpl> ptr);
    virtual ~PyAcadDimArcLength() override = default;
    static PyAcadDimArcLength cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadDimArcLengthImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};

//----------------------------------------------------------------------------------------
//PyAcadDimRadialLarge
void makePyAcadDimRadialLargeWrapper();

class PyAcadDimRadialLarge : public PyAcadDimension
{
public:
    PyAcadDimRadialLarge() = default;
    PyAcadDimRadialLarge(std::shared_ptr<PyIAcadDimRadialLargeImpl> ptr);
    virtual ~PyAcadDimRadialLarge() override = default;
    static PyAcadDimRadialLarge cast(const PyAcadObject& src);
    static std::string className();
public:
    PyIAcadDimRadialLargeImpl* impObj(const std::source_location& src = std::source_location::current()) const;
};



#pragma pack (pop)