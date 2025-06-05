#include "stdafx.h"
#include "PyDbSubDMesh.h"
#include "PyDbObjectId.h"
#include "PyDbSurface.h"
#include "PyDb3dSolid.h"
#include "PyGePlane.h"

using namespace boost::python;

void makePyDbSubDMeshWrapper()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    constexpr const std::string_view extrudeFacesOverloads = "Overloads:\n"
        "- subentPaths: list[PyDb.FullSubentPath], length: float, dir: PyGe.Vector3d, taper: float\n"
        "- subentPaths: list[PyDb.FullSubentPath], alongPath: list[PyGe.Point3d], taper: float\n";

    constexpr const std::string_view extrudeConnectedFacesOverloads = "Overloads:\n"
        "- subentPaths: list[PyDb.FullSubentPath], length: float, dir: PyGe.Vector3d, taper: float\n"
        "- subentPaths: list[PyDb.FullSubentPath], alongPath: list[PyGe.Point3d], taper: float\n";

    constexpr const std::string_view setCreaseOverloads = "Overloads:\n"
        "- creaseVal: float\n"
        "- subentPaths: list[PyDb.FullSubentPath], creaseVal: float\n";

    constexpr const std::string_view getCreaseOverloads = "Overloads:\n"
        "- id: int|PyDb.SubentId\n"
        "- subentPaths: list[PyDb.FullSubentPath]\n";

    constexpr const std::string_view convertToSurfaceOverloads = "Overloads:\n"
        "- bConvertAsSmooth: bool, id: PyDb.SubentId\n"
        "- bConvertAsSmooth: bool, optimize: bool\n";

    PyDocString DS("PyDb.SubDMesh");
    class_<PyDbSubDMesh, bases<PyDbEntity>>("SubDMesh")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.CTOR(ctords, 8769)))
        .def("setSubDMesh", &PyDbSubDMesh::setSubDMesh, DS.ARGS({ "vertexArray: list[PyGe.Point3d]", "faceArray: list[int]", "subDLevel: int" }, 8815))
        .def("setSphere", &PyDbSubDMesh::setSphere, DS.ARGS({ "radius: float","divAxis: int","divHeight: int","subDLevel: int" }, 8814))
        .def("setCylinder", &PyDbSubDMesh::setCylinder, DS.ARGS({ "majorRadius: float","minorRadius: float","height: float", "divAxis: int","divHeight: int","divCap: int","subDLevel: int" }, 8812))
        .def("setCone", &PyDbSubDMesh::setCone, DS.ARGS({ "majorRadius: float","minorRadius: float","height: float", "divAxis: int","divHeight: int","divCap: int","radiusRatio: float","subDLevel: int" }, 8810))
        .def("setTorus", &PyDbSubDMesh::setTorus, DS.ARGS({ "majorRadius: float", "divSection: int", "divSweepPath: int","sectionRadiusRatio: float","sectionRotate: float","subDLevel: int" }, 8819))
        .def("setBox", &PyDbSubDMesh::setBox, DS.ARGS({ "xLen: float","yLen: float","zLen: float","divX: int","divY: int","divZ: int","subDLevel: int" }, 8809))
        .def("setWedge", &PyDbSubDMesh::setWedge, DS.ARGS({ "xLen: float","yLen: float","zLen: float","divLength: int","divWidth: int","divHeight: int","divSlope: int","divCap: int","subDLevel: int" }, 8824))
        .def("setPyramid", &PyDbSubDMesh::setPyramid, DS.ARGS({ "radius: float","height: float","divLength: int","divHeight: int","divCap: int","nSides: int","radiusRatio: float","subDLevel: int" }, 8813))
        .def("subdDivideUp", &PyDbSubDMesh::subdDivideUp, DS.ARGS(8828))
        .def("subdDivideDown", &PyDbSubDMesh::subdDivideDown, DS.ARGS(8827))
        .def("subdRefine", &PyDbSubDMesh::subdRefine1)
        .def("subdRefine", &PyDbSubDMesh::subdRefine2, DS.ARGS({ "subentPaths: list[PyDb.FullSubentPath] = ..." }, 8830))
        .def("subdLevel", &PyDbSubDMesh::subdLevel, DS.ARGS(8829))
        .def("splitFace", &PyDbSubDMesh::splitFace, DS.ARGS({ "subentFaceId: PyDb.SubentId", "subent0: PyDb.SubentId", "point0: PyGe.Point3d","subent1: PyDb.SubentId", "point1: PyGe.Point3d" }, 8826))
        .def("extrudeFaces", &PyDbSubDMesh::extrudeFaces1)
        .def("extrudeFaces", &PyDbSubDMesh::extrudeFaces2, DS.OVRL(extrudeFacesOverloads, 8781))
        .def("extrudeConnectedFaces", &PyDbSubDMesh::extrudeConnectedFaces1)
        .def("extrudeConnectedFaces", &PyDbSubDMesh::extrudeConnectedFaces2, DS.OVRL(extrudeConnectedFacesOverloads, 8780))
        .def("mergeFaces", &PyDbSubDMesh::mergeFaces, DS.ARGS({ "subentPaths: list[PyDb.FullSubentPath]" }, 8802))
        .def("collapse", &PyDbSubDMesh::collapse, DS.ARGS({ "subentFaceId: PyDb.SubentId" }, 8773))
        .def("cap", &PyDbSubDMesh::cap, DS.ARGS({ "subentPaths: list[PyDb.FullSubentPath]" }, 8772))
        .def("spin", &PyDbSubDMesh::spin, DS.ARGS({ "subentFaceId: PyDb.SubentId" }, 8825))
        .def("isWatertight", &PyDbSubDMesh::isWatertight, DS.ARGS(8801))
        .def("numOfFaces", &PyDbSubDMesh::numOfFaces, DS.ARGS(8804))
        .def("numOfSubDividedFaces", &PyDbSubDMesh::numOfSubDividedFaces, DS.ARGS(8805))
        .def("numOfSubDividedFacesAt", &PyDbSubDMesh::numOfSubDividedFacesAt, DS.ARGS({ "subentPaths: list[PyDb.FullSubentPath]" }, 8806))
        .def("numOfVertices", &PyDbSubDMesh::numOfVertices, DS.ARGS(8808))
        .def("numOfSubDividedVertices", &PyDbSubDMesh::numOfSubDividedVertices, DS.ARGS(8807))
        .def("numOfEdges", &PyDbSubDMesh::numOfEdges, DS.ARGS(8803))
        .def("getVertices", &PyDbSubDMesh::getVertices, DS.ARGS(8800))
        .def("getEdgeArray", &PyDbSubDMesh::getEdgeArray, DS.ARGS(8784))
        .def("getFaceArray", &PyDbSubDMesh::getFaceArray, DS.ARGS(8785))
        .def("getNormalArray", &PyDbSubDMesh::getNormalArray, DS.ARGS(8787))
        .def("getSubDividedVertices", &PyDbSubDMesh::getSubDividedVertices, DS.ARGS(8791))
        .def("getSubDividedFaceArray", &PyDbSubDMesh::getSubDividedFaceArray, DS.ARGS(8788))
        .def("getSubDividedNormalArray", &PyDbSubDMesh::getSubDividedNormalArray, DS.ARGS(8789))
        .def("getVertexAt", &PyDbSubDMesh::getVertexAt1)
        .def("getVertexAt", &PyDbSubDMesh::getVertexAt2, DS.ARGS({ "id: int|PyDb.SubentId" }, 8796))
        .def("setVertexAt", &PyDbSubDMesh::setVertexAt1)
        .def("setVertexAt", &PyDbSubDMesh::setVertexAt2, DS.ARGS({ "id: int|PyDb.SubentId","pt: PyGe.Point3d" }, 8820))
        .def("getSubDividedVertexAt", &PyDbSubDMesh::getSubDividedVertexAt1)
        .def("getSubDividedVertexAt", &PyDbSubDMesh::getSubDividedVertexAt2, DS.ARGS({ "id: int|PyDb.SubentId" }, 8790))
        .def("setCrease", &PyDbSubDMesh::setCrease1)
        .def("setCrease", &PyDbSubDMesh::setCrease2, DS.OVRL(setCreaseOverloads, 8811))
        .def("getCrease", &PyDbSubDMesh::getCrease1)
        .def("getCrease", &PyDbSubDMesh::getCrease2, DS.OVRL(getCreaseOverloads, 8783))
        .def("getAdjacentSubentPath", &PyDbSubDMesh::getAdjacentSubentPath, DS.ARGS({ "path: PyDb.FullSubentPath", "stype: PyDb.SubentType" }, 8782))
        .def("getSubentPath", &PyDbSubDMesh::getSubentPath, DS.ARGS({ "index: int", "stype: PyDb.SubentType" }, 8795))
        .def("convertToSurface", &PyDbSubDMesh::convertToSurface1)
        .def("convertToSurface", &PyDbSubDMesh::convertToSurface2, DS.OVRL(convertToSurfaceOverloads, 8778))
        .def("convertToSolid", &PyDbSubDMesh::convertToSolid, DS.ARGS({ "bConvertAsSmooth: bool","optimize: bool" }, 8777))
        .def("getSubentColor", &PyDbSubDMesh::getSubentColor, DS.ARGS({ "id: PyDb.SubentId" }, 8792))
        .def("setSubentColor", &PyDbSubDMesh::setSubentColor, DS.ARGS({ "id: PyDb.SubentId","clr: PyDb.Color" }, 8816))
        .def("getSubentMaterial", &PyDbSubDMesh::getSubentMaterial, DS.ARGS({ "id: PyDb.SubentId" }, 8793))
        .def("setSubentMaterial", &PyDbSubDMesh::setSubentMaterial, DS.ARGS({ "id: PyDb.SubentId","materialId: PyDb.ObjectId" }, 8817))
        .def("getFacePlane", &PyDbSubDMesh::getFacePlane, DS.ARGS({ "id: PyDb.SubentId" }, 8786))
        .def("computeVolume", &PyDbSubDMesh::computeVolume, DS.ARGS(8776))
        .def("computeSurfaceArea", &PyDbSubDMesh::computeSurfaceArea, DS.ARGS(8775))
        .def("className", &PyDbSubDMesh::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbSubDMesh::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbSubDMesh::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbSubDMesh::cast, DS.SARGS({ "otherObject:  PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyDbSubDMesh::PyDbSubDMesh()
    : PyDbSubDMesh(new AcDbSubDMesh(), true)
{
}

PyDbSubDMesh::PyDbSubDMesh(const PyDbObjectId& id)
    : PyDbSubDMesh(openAcDbObject<AcDbSubDMesh>(id), false)
{
}

PyDbSubDMesh::PyDbSubDMesh(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbSubDMesh(openAcDbObject<AcDbSubDMesh>(id, mode), false)
{
}

PyDbSubDMesh::PyDbSubDMesh(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbSubDMesh(openAcDbObject<AcDbSubDMesh>(id, mode, erased), false)
{
}

PyDbSubDMesh::PyDbSubDMesh(AcDbSubDMesh* ptr, bool autoDelete)
    : PyDbEntity(ptr, autoDelete)
{
}

void PyDbSubDMesh::setSubDMesh(const boost::python::list& vertexArray, const boost::python::list& faceArray, int subDLevel) const
{
    PyThrowBadEs(impObj()->setSubDMesh(PyListToPoint3dArray(vertexArray), PyListToInt32Array(faceArray), subDLevel));
}

void PyDbSubDMesh::setSphere(double radius, int divAxis, int divHeight, int subDLevel) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->setSphere(radius, divAxis, divHeight, subDLevel));
#endif
}

void PyDbSubDMesh::setCylinder(double majorRadius, double minorRadius, double height, int divAxis, int divHeight, int divCap, int subDLevel) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->setCylinder(majorRadius, minorRadius, height, divAxis, divHeight, divCap, subDLevel));
#endif
}

void PyDbSubDMesh::setCone(double majorRadius, double minorRadius, double height, int divAxis, int divHeight, int divCap, double radiusRatio, int subDLevel) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->setCone(majorRadius, minorRadius, height, divAxis, divHeight, divCap, radiusRatio, subDLevel));
#endif
}

void PyDbSubDMesh::setTorus(double majorRadius, int divSection, int divSweepPath, double sectionRadiusRatio, double sectionRotate, int subDLevel) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->setTorus(majorRadius, divSection, divSweepPath, sectionRadiusRatio, sectionRotate, subDLevel));
#endif
}

void PyDbSubDMesh::setBox(double xLen, double yLen, double zLen, int divX, int divY, int divZ, int subDLevel) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->setBox(xLen, yLen, zLen, divX, divY, divZ, subDLevel));
#endif
}

void PyDbSubDMesh::setWedge(double xLen, double yLen, double zLen, int divLength, int divWidth, int divHeight, int divSlope, int divCap, int subDLevel) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->setWedge(xLen, yLen, zLen, divLength, divWidth, divHeight, divSlope, divCap, subDLevel));
#endif
}

void PyDbSubDMesh::setPyramid(double radius, double height, int divLength, int divHeight, int divCap, int nSides, double radiusRatio, int subDLevel) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->setPyramid(radius, height, divLength, divHeight, divCap, nSides, radiusRatio, subDLevel));
#endif
}

void PyDbSubDMesh::subdDivideUp() const
{
    PyThrowBadEs(impObj()->subdDivideUp());
}

void PyDbSubDMesh::subdDivideDown() const
{
    PyThrowBadEs(impObj()->subdDivideDown());
}

void PyDbSubDMesh::subdRefine1() const
{
    PyThrowBadEs(impObj()->subdRefine());
}

void PyDbSubDMesh::subdRefine2(const boost::python::object& subentPaths) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->subdRefine(PyListToPyDbFullSubentPathArray(subentPaths)));
#endif
}

Adesk::Int32 PyDbSubDMesh::subdLevel() const
{
    Adesk::Int32 result;
    PyThrowBadEs(impObj()->subdLevel(result));
    return result;
}

void PyDbSubDMesh::splitFace(const PyDbSubentId& subentFaceId, const PyDbSubentId& subent0, const AcGePoint3d& point0, const PyDbSubentId& subent1, const AcGePoint3d& point1) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->splitFace(*subentFaceId.impObj(), *subent0.impObj(), point0, *subent1.impObj(), point1));
#endif
}

void PyDbSubDMesh::extrudeFaces1(const boost::python::list& subentPaths, double length, const AcGeVector3d& dir, double taper) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->extrudeFaces(PyListToPyDbFullSubentPathArray(subentPaths), length, dir, taper));
#endif
}

void PyDbSubDMesh::extrudeFaces2(const boost::python::list& subentPaths, const boost::python::list& alongPath, double taper) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->extrudeFaces(PyListToPyDbFullSubentPathArray(subentPaths), PyListToPoint3dArray(alongPath), taper));
#endif
}

void PyDbSubDMesh::extrudeConnectedFaces1(const boost::python::list& subentPaths, double length, const AcGeVector3d& dir, double taper) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->extrudeConnectedFaces(PyListToPyDbFullSubentPathArray(subentPaths), length, dir, taper));
#endif
}

void PyDbSubDMesh::extrudeConnectedFaces2(const boost::python::list& subentPaths, const boost::python::list& alongPath, double taper) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->extrudeConnectedFaces(PyListToPyDbFullSubentPathArray(subentPaths), PyListToPoint3dArray(alongPath), taper));
#endif
}

void PyDbSubDMesh::mergeFaces(const boost::python::list& subentPaths) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->mergeFaces(PyListToPyDbFullSubentPathArray(subentPaths)));
#endif
}

void PyDbSubDMesh::collapse(const PyDbSubentId& subent) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->collapse(*subent.impObj()));
#endif
}

void PyDbSubDMesh::cap(const boost::python::list& edgePaths) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->cap(PyListToPyDbFullSubentPathArray(edgePaths)));
#endif
}

void PyDbSubDMesh::spin(const PyDbSubentId& subent) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->spin(*subent.impObj()));
#endif
}

bool PyDbSubDMesh::isWatertight() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    bool result = false;
    PyThrowBadEs(impObj()->isWatertight(result));
    return result;
#endif
}

Adesk::Int32 PyDbSubDMesh::numOfFaces() const
{
    Adesk::Int32 result = 0;
    PyThrowBadEs(impObj()->numOfFaces(result));
    return result;
}

Adesk::Int32 PyDbSubDMesh::numOfSubDividedFaces() const
{
    Adesk::Int32 result = 0;
    PyThrowBadEs(impObj()->numOfSubDividedFaces(result));
    return result;
}

Adesk::Int32 PyDbSubDMesh::numOfSubDividedFacesAt(const boost::python::list& subentPaths) const
{
    Adesk::Int32 result = 0;
    PyThrowBadEs(impObj()->numOfSubDividedFacesAt(PyListToPyDbFullSubentPathArray(subentPaths), result));
    return result;
}

Adesk::Int32 PyDbSubDMesh::numOfVertices() const
{
    Adesk::Int32 result = 0;
    PyThrowBadEs(impObj()->numOfVertices(result));
    return result;
}

Adesk::Int32 PyDbSubDMesh::numOfSubDividedVertices() const
{
    Adesk::Int32 result = 0;
    PyThrowBadEs(impObj()->numOfSubDividedVertices(result));
    return result;
}

Adesk::Int32 PyDbSubDMesh::numOfEdges() const
{
    Adesk::Int32 result = 0;
    PyThrowBadEs(impObj()->numOfEdges(result));
    return result;
}

boost::python::list PyDbSubDMesh::getVertices() const
{
    AcGePoint3dArray result;
    PyThrowBadEs(impObj()->getVertices(result));
    return Point3dArrayToPyList(result);
}

boost::python::list PyDbSubDMesh::getEdgeArray() const
{
    AcArray<Adesk::Int32> result;
    PyThrowBadEs(impObj()->getEdgeArray(result));
    return Int32ArrayToPyList(result);
}

boost::python::list PyDbSubDMesh::getFaceArray() const
{
    AcArray<Adesk::Int32> result;
    PyThrowBadEs(impObj()->getFaceArray(result));
    return Int32ArrayToPyList(result);
}

boost::python::list PyDbSubDMesh::getNormalArray() const
{
    AcGeVector3dArray result;
    PyThrowBadEs(impObj()->getNormalArray(result));
    return Vector3dArrayToPyList(result);
}

boost::python::list PyDbSubDMesh::getSubDividedVertices() const
{
    AcGePoint3dArray result;
    PyThrowBadEs(impObj()->getSubDividedVertices(result));
    return Point3dArrayToPyList(result);
}

boost::python::list PyDbSubDMesh::getSubDividedFaceArray() const
{
    AcArray<Adesk::Int32> result;
    PyThrowBadEs(impObj()->getSubDividedFaceArray(result));
    return Int32ArrayToPyList(result);
}

boost::python::list PyDbSubDMesh::getSubDividedNormalArray() const
{
    AcGeVector3dArray result;
    PyThrowBadEs(impObj()->getSubDividedNormalArray(result));
    return Vector3dArrayToPyList(result);
}

AcGePoint3d PyDbSubDMesh::getVertexAt1(Adesk::Int32 nIndex) const
{
    AcGePoint3d result;
    PyThrowBadEs(impObj()->getVertexAt(nIndex, result));
    return result;
}

AcGePoint3d PyDbSubDMesh::getVertexAt2(const PyDbSubentId& id) const
{
    AcGePoint3d result;
    PyThrowBadEs(impObj()->getVertexAt(*id.impObj(), result));
    return result;
}

void PyDbSubDMesh::setVertexAt1(Adesk::Int32 nIndex, const AcGePoint3d& vertex) const
{
    PyThrowBadEs(impObj()->setVertexAt(nIndex, vertex));
}

void PyDbSubDMesh::setVertexAt2(const PyDbSubentId& id, const AcGePoint3d& vertex) const
{
    PyThrowBadEs(impObj()->setVertexAt(*id.impObj(), vertex));
}

AcGePoint3d PyDbSubDMesh::getSubDividedVertexAt1(Adesk::Int32 nIndex) const
{
    AcGePoint3d result;
    PyThrowBadEs(impObj()->getSubDividedVertexAt(nIndex, result));
    return result;
}

AcGePoint3d PyDbSubDMesh::getSubDividedVertexAt2(const PyDbSubentId& id) const
{
    AcGePoint3d result;
    PyThrowBadEs(impObj()->getSubDividedVertexAt(*id.impObj(), result));
    return result;
}

void PyDbSubDMesh::setCrease1(double creaseVal) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->setCrease(creaseVal));
#endif
}

void PyDbSubDMesh::setCrease2(const boost::python::list& subentPaths, double creaseVal) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->setCrease(PyListToPyDbFullSubentPathArray(subentPaths), creaseVal));
#endif
}

boost::python::list PyDbSubDMesh::getCrease1(const boost::python::list& subentPaths) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    AcArray<double> result;
    PyThrowBadEs(impObj()->getCrease(PyListToPyDbFullSubentPathArray(subentPaths), result));
    return DoubleArrayToPyList(result);
#endif
}

double PyDbSubDMesh::getCrease2(const PyDbSubentId& id) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    double result;
    PyThrowBadEs(impObj()->getCrease(*id.impObj(), result));
    return result;
#endif
}

boost::python::list PyDbSubDMesh::getAdjacentSubentPath(const PyDbFullSubentPath& path, AcDb::SubentType type) const
{
    AcDbFullSubentPathArray result;
    PyThrowBadEs(impObj()->getAdjacentSubentPath(path.pyImp, type, result));
    return FullSubentPathArrayToPyList(result);
}

boost::python::list PyDbSubDMesh::getSubentPath(Adesk::Int32 nIndex, AcDb::SubentType type) const
{
    AcDbFullSubentPathArray result;
    PyThrowBadEs(impObj()->getSubentPath(nIndex, type, result));
    return FullSubentPathArrayToPyList(result);
}

PyDbSurface PyDbSubDMesh::convertToSurface1(bool bConvertAsSmooth, const PyDbSubentId& id) const
{
    AcDbSurface* pSurface = nullptr;
    PyThrowBadEs(impObj()->convertToSurface(bConvertAsSmooth, id.impObj(), pSurface));
    return PyDbSurface(pSurface, true);
}

PyDbSurface PyDbSubDMesh::convertToSurface2(bool bConvertAsSmooth, bool optimize) const
{
    AcDbSurface* pSurface = nullptr;
    PyThrowBadEs(impObj()->convertToSurface(bConvertAsSmooth, optimize, pSurface));
    return PyDbSurface(pSurface, true);
}

PyDb3dSolid PyDbSubDMesh::convertToSolid(bool bConvertAsSmooth, bool optimize) const
{
    AcDb3dSolid* pSolid = nullptr;
    PyThrowBadEs(impObj()->convertToSolid(bConvertAsSmooth, optimize, pSolid));
    return PyDb3dSolid(pSolid, true);
}

AcCmColor PyDbSubDMesh::getSubentColor(const PyDbSubentId& id) const
{
    AcCmColor result;
    PyThrowBadEs(impObj()->getSubentColor(*id.impObj(), result));
    return result;
}

void PyDbSubDMesh::setSubentColor(const PyDbSubentId& id, const AcCmColor& color) const
{
    PyThrowBadEs(impObj()->setSubentColor(*id.impObj(), color));
}

PyDbObjectId PyDbSubDMesh::getSubentMaterial(const PyDbSubentId& id) const
{
    PyDbObjectId result;
    PyThrowBadEs(impObj()->getSubentMaterial(*id.impObj(), result.m_id));
    return result;
}

void PyDbSubDMesh::setSubentMaterial(const PyDbSubentId& id, const PyDbObjectId& material) const
{
    PyThrowBadEs(impObj()->setSubentMaterial(*id.impObj(), material.m_id));
}

PyGePlane PyDbSubDMesh::getFacePlane(const PyDbSubentId& id) const
{
    AcGePlane result;
    PyThrowBadEs(impObj()->getFacePlane(*id.impObj(), result));
    return PyGePlane(result);
}

double PyDbSubDMesh::computeVolume() const
{
    double result;
    PyThrowBadEs(impObj()->computeVolume(result));
    return result;
}

double PyDbSubDMesh::computeSurfaceArea() const
{
    double result;
    PyThrowBadEs(impObj()->computeSurfaceArea(result));
    return result;
}

std::string PyDbSubDMesh::className()
{
    return "AcDbSubDMesh";
}

PyRxClass PyDbSubDMesh::desc()
{
    return PyRxClass(AcDbSubDMesh::desc(), false);
}

PyDbSubDMesh PyDbSubDMesh::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbSubDMesh, AcDbSubDMesh>(src);
}

PyDbSubDMesh PyDbSubDMesh::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbSubDMesh>(src);
}

AcDbSubDMesh* PyDbSubDMesh::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbSubDMesh*>(m_pyImp.get());
}
