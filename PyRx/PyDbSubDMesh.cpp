#include "stdafx.h"
#include "PyDbSubDMesh.h"
#include "PyDbObjectId.h"
#include "PyDbSurface.h"
#include "PyDb3dSolid.h"
#include "PyGePlane.h"

using namespace boost::python;

void makePyDbSubDMeshWrapper()
{
    PyDocString DS("PyDb.SubDMesh");
    class_<PyDbSubDMesh, bases<PyDbEntity>>("SubDMesh")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: PyDb.ObjectId", "mode:  PyDb.OpenMode=PyDb.OpenMode.kForRead", "erased: bool=False" })))

        .def("setSubDMesh", &PyDbSubDMesh::setSubDMesh)
        .def("setSphere", &PyDbSubDMesh::setSphere)
        .def("setCylinder", &PyDbSubDMesh::setCylinder)
        .def("setCone", &PyDbSubDMesh::setCone)
        .def("setTorus", &PyDbSubDMesh::setTorus)
        .def("setBox", &PyDbSubDMesh::setBox)
        .def("setWedge", &PyDbSubDMesh::setWedge)
        .def("setPyramid", &PyDbSubDMesh::setPyramid)
        .def("subdDivideUp", &PyDbSubDMesh::subdDivideUp)
        .def("subdDivideDown", &PyDbSubDMesh::subdDivideDown)
        .def("subdRefine", &PyDbSubDMesh::subdRefine1)
        .def("subdRefine", &PyDbSubDMesh::subdRefine2)
        .def("subdLevel", &PyDbSubDMesh::subdLevel)
        .def("splitFace", &PyDbSubDMesh::splitFace)
        .def("extrudeFaces", &PyDbSubDMesh::extrudeFaces1)
        .def("extrudeFaces", &PyDbSubDMesh::extrudeFaces2)
        .def("extrudeConnectedFaces", &PyDbSubDMesh::extrudeConnectedFaces1)
        .def("extrudeConnectedFaces", &PyDbSubDMesh::extrudeConnectedFaces2)
        .def("mergeFaces", &PyDbSubDMesh::mergeFaces)
        .def("collapse", &PyDbSubDMesh::collapse)
        .def("cap", &PyDbSubDMesh::cap)
        .def("spin", &PyDbSubDMesh::spin)
        .def("isWatertight", &PyDbSubDMesh::isWatertight, DS.ARGS())
        .def("numOfFaces", &PyDbSubDMesh::numOfFaces, DS.ARGS())
        .def("numOfSubDividedFaces", &PyDbSubDMesh::numOfSubDividedFaces, DS.ARGS())
        .def("numOfSubDividedFacesAt", &PyDbSubDMesh::numOfSubDividedFacesAt)
        .def("numOfVertices", &PyDbSubDMesh::numOfVertices, DS.ARGS())
        .def("numOfSubDividedVertices", &PyDbSubDMesh::numOfSubDividedVertices, DS.ARGS())
        .def("numOfEdges", &PyDbSubDMesh::numOfEdges, DS.ARGS())
        .def("getVertices", &PyDbSubDMesh::getVertices, DS.ARGS())
        .def("getEdgeArray", &PyDbSubDMesh::getEdgeArray, DS.ARGS())
        .def("getFaceArray", &PyDbSubDMesh::getFaceArray, DS.ARGS())
        .def("getNormalArray", &PyDbSubDMesh::getNormalArray, DS.ARGS())
        .def("getSubDividedVertices", &PyDbSubDMesh::getSubDividedVertices, DS.ARGS())
        .def("getSubDividedFaceArray", &PyDbSubDMesh::getSubDividedFaceArray, DS.ARGS())
        .def("getSubDividedNormalArray", &PyDbSubDMesh::getSubDividedNormalArray, DS.ARGS())
        .def("getVertexAt", &PyDbSubDMesh::getVertexAt1)
        .def("getVertexAt", &PyDbSubDMesh::getVertexAt2)
        .def("setVertexAt", &PyDbSubDMesh::setVertexAt1)
        .def("setVertexAt", &PyDbSubDMesh::setVertexAt2)
        .def("getSubDividedVertexAt", &PyDbSubDMesh::getSubDividedVertexAt1)
        .def("getSubDividedVertexAt", &PyDbSubDMesh::getSubDividedVertexAt2)
        .def("setCrease", &PyDbSubDMesh::setCrease1)
        .def("setCrease", &PyDbSubDMesh::setCrease2)
        .def("getCrease", &PyDbSubDMesh::getCrease1)
        .def("getCrease", &PyDbSubDMesh::getCrease2)
        .def("getAdjacentSubentPath", &PyDbSubDMesh::getAdjacentSubentPath)
        .def("getSubentPath", &PyDbSubDMesh::getSubentPath)
        .def("convertToSurface", &PyDbSubDMesh::convertToSurface1)
        .def("convertToSurface", &PyDbSubDMesh::convertToSurface2)
        .def("convertToSolid", &PyDbSubDMesh::convertToSolid)
        .def("getSubentColor", &PyDbSubDMesh::getSubentColor)
        .def("setSubentColor", &PyDbSubDMesh::setSubentColor)
        .def("getSubentMaterial", &PyDbSubDMesh::getSubentMaterial)
        .def("setSubentMaterial", &PyDbSubDMesh::setSubentMaterial)
        .def("getFacePlane", &PyDbSubDMesh::getFacePlane)
        .def("computeVolume", &PyDbSubDMesh::computeVolume, DS.ARGS())
        .def("computeSurfaceArea", &PyDbSubDMesh::computeSurfaceArea, DS.ARGS())

        .def("className", &PyDbSubDMesh::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbSubDMesh::desc, DS.SARGS()).staticmethod("desc")
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

void PyDbSubDMesh::setSubDMesh(const boost::python::list& vertexArray, const boost::python::list& faceArray, int subDLevel)
{
    PyThrowBadEs(impObj()->setSubDMesh(PyListToPoint3dArray(vertexArray), PyListToInt32Array(faceArray), subDLevel));
}

void PyDbSubDMesh::setSphere(double radius, int divAxis, int divHeight, int subDLevel)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->setSphere(radius, divAxis, divHeight, subDLevel));
#endif
}

void PyDbSubDMesh::setCylinder(double majorRadius, double minorRadius, double height, int divAxis, int divHeight, int divCap, int subDLevel)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->setCylinder(majorRadius, minorRadius, height, divAxis, divHeight, divCap, subDLevel));
#endif
}

void PyDbSubDMesh::setCone(double majorRadius, double minorRadius, double height, int divAxis, int divHeight, int divCap, double radiusRatio, int subDLevel)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->setCone(majorRadius, minorRadius, height, divAxis, divHeight, divCap, radiusRatio, subDLevel));
#endif
}

void PyDbSubDMesh::setTorus(double majorRadius, int divSection, int divSweepPath, double sectionRadiusRatio, double sectionRotate, int subDLevel)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->setTorus(majorRadius, divSection, divSweepPath, sectionRadiusRatio, sectionRotate, subDLevel));
#endif
}

void PyDbSubDMesh::setBox(double xLen, double yLen, double zLen, int divX, int divY, int divZ, int subDLevel)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->setBox(xLen, yLen, zLen, divX, divY, divZ, subDLevel));
#endif
}

void PyDbSubDMesh::setWedge(double xLen, double yLen, double zLen, int divLength, int divWidth, int divHeight, int divSlope, int divCap, int subDLevel)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->setWedge(xLen, yLen, zLen, divLength, divWidth, divHeight, divSlope, divCap,subDLevel));
#endif
}

void PyDbSubDMesh::setPyramid(double radius, double height, int divLength, int divHeight, int divCap, int nSides, double radiusRatio, int subDLevel)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->setPyramid(radius, height, divLength, divHeight, divCap, nSides, radiusRatio, subDLevel));
#endif
}

void PyDbSubDMesh::subdDivideUp()
{
    PyThrowBadEs(impObj()->subdDivideUp());
}

void PyDbSubDMesh::subdDivideDown()
{
    PyThrowBadEs(impObj()->subdDivideDown());
}

void PyDbSubDMesh::subdRefine1()
{
    PyThrowBadEs(impObj()->subdRefine());
}

void PyDbSubDMesh::subdRefine2(const boost::python::list& subentPaths)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->subdRefine(PyListToPyDbFullSubentPathArray(subentPaths)));
#endif
}

Adesk::Int32 PyDbSubDMesh::subdLevel()
{
    Adesk::Int32 result;
    PyThrowBadEs(impObj()->subdLevel(result));
    return result;
}

void PyDbSubDMesh::splitFace(const PyDbSubentId& subentFaceId, const PyDbSubentId& subent0, const AcGePoint3d& point0, const PyDbSubentId& subent1, const AcGePoint3d& point1)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->splitFace(*subentFaceId.impObj(),* subent0.impObj(), point0,*subent1.impObj(), point1));
#endif
}

void PyDbSubDMesh::extrudeFaces1(const boost::python::list& subentPaths, double length, const AcGeVector3d& dir, double taper)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->extrudeFaces(PyListToPyDbFullSubentPathArray(subentPaths), length, dir, taper));
#endif
}

void PyDbSubDMesh::extrudeFaces2(const boost::python::list& subentPaths, const boost::python::list& alongPath, double taper)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->extrudeFaces(PyListToPyDbFullSubentPathArray(subentPaths), PyListToPoint3dArray(alongPath), taper));
#endif
}

void PyDbSubDMesh::extrudeConnectedFaces1(const boost::python::list& subentPaths, double length, const AcGeVector3d& dir, double taper)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->extrudeConnectedFaces(PyListToPyDbFullSubentPathArray(subentPaths), length, dir, taper));
#endif
}

void PyDbSubDMesh::extrudeConnectedFaces2(const boost::python::list& subentPaths, const boost::python::list& alongPath, double taper)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->extrudeConnectedFaces(PyListToPyDbFullSubentPathArray(subentPaths), PyListToPoint3dArray(alongPath), taper));
#endif
}

void PyDbSubDMesh::mergeFaces(const boost::python::list& subentPaths)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->mergeFaces(PyListToPyDbFullSubentPathArray(subentPaths)));
#endif
}

void PyDbSubDMesh::collapse(const PyDbSubentId& subent)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->collapse(*subent.impObj()));
#endif
}

void PyDbSubDMesh::cap(const boost::python::list& edgePaths)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->cap(PyListToPyDbFullSubentPathArray(edgePaths)));
#endif
}

void PyDbSubDMesh::spin(const PyDbSubentId& subent)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->spin(*subent.impObj()));
#endif
}

bool PyDbSubDMesh::isWatertight() const
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
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
    PyThrowBadEs(impObj()->numOfSubDividedFacesAt(PyListToPyDbFullSubentPathArray(subentPaths),result));
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
    PyThrowBadEs(impObj()->getVertexAt(nIndex,result));
    return result;
}

AcGePoint3d PyDbSubDMesh::getVertexAt2(const PyDbSubentId& id) const
{
    AcGePoint3d result;
    PyThrowBadEs(impObj()->getVertexAt(*id.impObj(), result));
    return result;
}

void PyDbSubDMesh::setVertexAt1(Adesk::Int32 nIndex, const AcGePoint3d& vertex)
{
    PyThrowBadEs(impObj()->setVertexAt(nIndex, vertex));
}

void PyDbSubDMesh::setVertexAt2(const PyDbSubentId& id, const AcGePoint3d& vertex)
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

void PyDbSubDMesh::setCrease1(double creaseVal)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->setCrease(creaseVal));
#endif
}

void PyDbSubDMesh::setCrease2(const boost::python::list& subentPaths, double creaseVal)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->setCrease(PyListToPyDbFullSubentPathArray(subentPaths), creaseVal));
#endif
}

boost::python::list PyDbSubDMesh::getCrease1(const boost::python::list& subentPaths) const
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    AcArray<double> result;
    PyThrowBadEs(impObj()->getCrease(PyListToPyDbFullSubentPathArray(subentPaths), result));
    return DoubleArrayToPyList(result);
#endif
}

double PyDbSubDMesh::getCrease2(const PyDbSubentId& id) const
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
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
    PyThrowBadEs(impObj()->getAdjacentSubentPath(path.m_pyImp, type, result));
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

void PyDbSubDMesh::setSubentColor(const PyDbSubentId& id, const AcCmColor& color)
{
    PyThrowBadEs(impObj()->setSubentColor(*id.impObj(), color));
}

PyDbObjectId PyDbSubDMesh::getSubentMaterial(const PyDbSubentId& id) const
{
    PyDbObjectId result;
    PyThrowBadEs(impObj()->getSubentMaterial(*id.impObj(), result.m_id));
    return result;
}

void PyDbSubDMesh::setSubentMaterial(const PyDbSubentId& id, const PyDbObjectId& material)
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
    if (!src.impObj()->isKindOf(AcDbSubDMesh::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbSubDMesh(static_cast<AcDbSubDMesh*>(src.impObj()->clone()), true);
}

PyDbSubDMesh PyDbSubDMesh::cast(const PyRxObject& src)
{
    PyDbSubDMesh dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbSubDMesh* PyDbSubDMesh::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<AcDbSubDMesh*>(m_pyImp.get());
}
