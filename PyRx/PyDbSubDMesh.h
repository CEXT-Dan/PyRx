#pragma once
#include "dbSubD.h"
#include "PyDbEntity.h"

class PyDbSurface;
class PyDb3dSolid;
class PyGePlane;

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

    void            setSubDMesh(const boost::python::list& vertexArray, const boost::python::list& faceArray, int subDLevel);
    void            setSphere(double radius, int divAxis, int divHeight, int subDLevel);
    void            setCylinder(double majorRadius, double minorRadius, double height, int divAxis, int divHeight, int divCap, int subDLevel);
    void            setCone(double majorRadius, double minorRadius, double height, int divAxis, int divHeight, int divCap, double radiusRatio, int subDLevel);
    void            setTorus(double majorRadius, int divSection, int divSweepPath, double sectionRadiusRatio, double sectionRotate, int subDLevel);
    void            setBox(double xLen, double yLen, double zLen, int divX, int divY, int divZ, int subDLevel);
    void            setWedge(double xLen, double yLen, double zLen, int divLength, int divWidth, int divHeight, int divSlope, int divCap, int subDLevel);
    void            setPyramid(double radius, double height, int divLength, int divHeight, int divCap, int nSides, double radiusRatio, int subDLevel);
    void            subdDivideUp();
    void            subdDivideDown();
    void            subdRefine1();
    void            subdRefine2(const boost::python::list& subentPaths);
    Adesk::Int32    subdLevel();
    void            splitFace(const PyDbSubentId& subentFaceId, const PyDbSubentId& subent0, const AcGePoint3d& point0, const PyDbSubentId& subent1, const AcGePoint3d& point1);
    void            extrudeFaces1(const boost::python::list& subentPaths,double length, const AcGeVector3d& dir, double taper);
    void            extrudeFaces2(const boost::python::list& subentPaths, const boost::python::list& alongPath, double taper);
    void            extrudeConnectedFaces1(const boost::python::list& subentPaths, double length, const AcGeVector3d& dir, double taper);
    void            extrudeConnectedFaces2(const boost::python::list& subentPaths, const boost::python::list& alongPath, double taper);

    void            mergeFaces(const boost::python::list& subentPaths);
    void            collapse(const PyDbSubentId& subent);
    void            cap(const boost::python::list& edgePaths);
    void            spin(const PyDbSubentId& subent);

    bool            isWatertight() const;
    Adesk::Int32    numOfFaces() const;
    Adesk::Int32    numOfSubDividedFaces() const;
    Adesk::Int32    numOfSubDividedFacesAt(const boost::python::list& subentPaths) const;

    Adesk::Int32    numOfVertices() const;
    Adesk::Int32    numOfSubDividedVertices() const;
    Adesk::Int32    numOfEdges() const;

    boost::python::list getVertices() const;
    boost::python::list getEdgeArray() const;
    boost::python::list getFaceArray() const;
    boost::python::list getNormalArray() const;
    boost::python::list getSubDividedVertices() const;
    boost::python::list getSubDividedFaceArray() const;
    boost::python::list getSubDividedNormalArray() const;

    AcGePoint3d     getVertexAt1(Adesk::Int32 nIndex) const;
    void            setVertexAt1(Adesk::Int32 nIndex, const AcGePoint3d& vertex);

    AcGePoint3d     getVertexAt2(const PyDbSubentId& id) const;
    void            setVertexAt2(const PyDbSubentId& id, const AcGePoint3d& vertex);

    AcGePoint3d     getSubDividedVertexAt1(Adesk::Int32 nIndex) const;
    AcGePoint3d     getSubDividedVertexAt2(const PyDbSubentId& id) const;

    void            setCrease1(double creaseVal);
    void            setCrease2(const boost::python::list& subentPaths, double creaseVal);

    boost::python::list getCrease1(const boost::python::list& subentPaths) const;
    double          getCrease2(const PyDbSubentId& id) const;

    boost::python::list getAdjacentSubentPath(const PyDbFullSubentPath& path, AcDb::SubentType type) const;
    boost::python::list getSubentPath(Adesk::Int32 nIndex, AcDb::SubentType type) const;


    PyDbSurface     convertToSurface1(bool bConvertAsSmooth, const PyDbSubentId& id) const;
    PyDbSurface     convertToSurface2(bool bConvertAsSmooth, bool optimize) const;
    PyDb3dSolid     convertToSolid(bool bConvertAsSmooth, bool optimize) const;

    AcCmColor       getSubentColor(const PyDbSubentId& id) const;
    void            setSubentColor(const PyDbSubentId& id, const AcCmColor& color);

    PyDbObjectId    getSubentMaterial(const PyDbSubentId& id) const;
    void            setSubentMaterial(const PyDbSubentId& id, const PyDbObjectId& material);

    //void            getSubentMaterialMapper(const AcDbSubentId& id, AcGiMapper& mapper) const;
    //void            setSubentMaterialMapper(const AcDbSubentId& id, const AcGiMapper& mapper);

    PyGePlane       getFacePlane(const PyDbSubentId& id) const;
    double          computeVolume() const;
    double          computeSurfaceArea() const;


    static std::string      className();
    static PyRxClass        desc();
    static PyDbSubDMesh     cloneFrom(const PyRxObject& src);
    static PyDbSubDMesh     cast(const PyRxObject& src);
public:
    inline  AcDbSubDMesh* impObj(const std::source_location& src = std::source_location::current()) const;
};

