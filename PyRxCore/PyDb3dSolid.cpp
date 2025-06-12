#include "stdafx.h"
#include "PyDb3dSolid.h"
#include "PyDbObjectId.h"
#include "PyDbCurve.h"
#include "PyGePlane.h"
#include "PyDbSurface.h"

using namespace boost::python;

void makePyDb3dSolidWrapper()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";


    constexpr const std::string_view createRevolvedSolidOverloads = "Overloads:\n"
        "- pRevEnt: PyDb.Entity, axisPnt: PyGe.Point3d, axisDir: PyGe.Vector3d, revAngle: float, startAngle: float, revolveOptions: PyDb.RevolveOptions\n"
        "- pRevEnt: PyDb.Entity,faceSubentId:PyDb.SubentId, axisPnt: PyGe.Point3d, axisDir: PyGe.Vector3d, revAngle: float, startAngle: float, revolveOptions: PyDb.RevolveOptions\n";

    constexpr const std::string_view createSweptSolidOverloads = "Overloads:\n"
        "- pSweepEnt: PyDb.Entity, pPathEnt: PyDb.Entity, sweepOptions: PyDb.SweepOptions\n"
        "- pSweepEnt: PyDb.Entity, faceSubentId:PyDb.SubentId, pPathEnt: PyDb.Entity, sweepOptions: PyDb.SweepOptions\n";

    constexpr const std::string_view createExtrudedSolidOverloads = "Overloads:\n"
        "- pSweepEnt: PyDb.Entity, directionVec: PyGe.Vector3d, sweepOptions: PyDb.SweepOptions\n"
        "- pSweepEnt: PyDb.Entity, faceSubentId:PyDb.SubentId, directionVec: PyGe.Vector3d, sweepOptions: PyDb.SweepOptions\n"
        "- pSweepEnt: PyDb.Entity, faceSubentId:PyDb.SubentId, height: float, sweepOptions: PyDb.SweepOptions\n";

    PyDocString DS("PyDb.Solid3d");
    class_<PyDb3dSolid, bases<PyDbEntity>>("Solid3d")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.CTOR(ctords, 1270)))
        .def("createBox", &PyDb3dSolid::createBox, DS.ARGS({ "xLen: float","yLen: float" ,"zLen: float" }))
        .def("createFrustum", &PyDb3dSolid::createFrustum, DS.ARGS({ "height: float","xRadius: float","yRadius: float","topXRadius: float" }))
        .def("createSphere", &PyDb3dSolid::createSphere, DS.ARGS({ "radius: float" }))
        .def("createTorus", &PyDb3dSolid::createTorus, DS.ARGS({ "majorRadius: float", "minorRadius: float" }))
        .def("createPyramid", &PyDb3dSolid::createPyramid1)
        .def("createPyramid", &PyDb3dSolid::createPyramid2, DS.ARGS({ "height: float","sides: int","radius: float","topRadius: float=0.0" }))
        .def("createWedge", &PyDb3dSolid::createWedge, DS.ARGS({ "xLen: float","yLen: float" ,"zLen: float" }))
        .def("extrude", &PyDb3dSolid::extrude1)
        .def("extrude", &PyDb3dSolid::extrude2, DS.ARGS({ "region: PyDb.Region","height: float","taperAngle: float=0.0" }))
        .def("extrudeAlongPath", &PyDb3dSolid::extrudeAlongPath1)
        .def("extrudeAlongPath", &PyDb3dSolid::extrudeAlongPath2, DS.ARGS({ "region: PyDb.Region","path: PyDb.Curve","taperAngle: float=0.0" }))
        .def("createRevolvedSolid", &PyDb3dSolid::createRevolvedSolid1)
        .def("createRevolvedSolid", &PyDb3dSolid::createRevolvedSolid2, DS.OVRL(createRevolvedSolidOverloads))
        .def("createSweptSolid", &PyDb3dSolid::createSweptSolid1)
        .def("createSweptSolid", &PyDb3dSolid::createSweptSolid2, DS.OVRL(createSweptSolidOverloads))
        .def("createExtrudedSolid", &PyDb3dSolid::createExtrudedSolid1)
        .def("createExtrudedSolid", &PyDb3dSolid::createExtrudedSolid2)
        .def("createExtrudedSolid", &PyDb3dSolid::createExtrudedSolid3, DS.OVRL(createExtrudedSolidOverloads))
        .def("createFrom", &PyDb3dSolid::createFrom, DS.ARGS({ "val: PyDb.Entity" }))
        .def("getArea", &PyDb3dSolid::getArea, DS.ARGS())
        .def("checkInterference", &PyDb3dSolid::checkInterference, DS.ARGS({ "val: PyDb.Solid3d","createNewSolid: bool" }))
        .def("getMassProp", &PyDb3dSolid::getMassProp, DS.ARGS())
        .def("isNull", &PyDb3dSolid::isNull, DS.ARGS())
        .def("getSection", &PyDb3dSolid::getSection, DS.ARGS({ "plane: PyGe.Plane" }))
        .def("stlOut", &PyDb3dSolid::stlOut1)
        .def("stlOut", &PyDb3dSolid::stlOut2, DS.ARGS({ "fileName: str","asciiFormat: bool","maxSurfaceDeviation: float = 0.0 " }))
        .def("booleanOper", &PyDb3dSolid::booleanOper, DS.ARGS({ "operation: PyDb.BoolOperType", "solid: PyDb.Solid3d" }))
        .def("getSlice", &PyDb3dSolid::getSlice1)
        .def("getSlice", &PyDb3dSolid::getSlice2, DS.ARGS({ "plane: PyGe.Plane|PyDb.Surface","getNegHalfToo: bool" }))
        .def("numChanges", &PyDb3dSolid::numChanges, DS.ARGS())
        .def("copyEdge", &PyDb3dSolid::copyEdge, DS.ARGS({ "subentId: PyDb.SubentId" }))
        .def("copyFace", &PyDb3dSolid::copyFace, DS.ARGS({ "subentId: PyDb.SubentId" }))
        .def("extrudeFaces", &PyDb3dSolid::extrudeFaces, DS.ARGS({ "subentIds: list[PyDb.SubentId]","height: float", "taper: float" }))
        .def("extrudeFacesAlongPath", &PyDb3dSolid::extrudeFacesAlongPath, DS.ARGS({ "subentIds: list[PyDb.SubentId]","path: PyDb.Curve" }))
        .def("imprintEntity", &PyDb3dSolid::imprintEntity, DS.ARGS({ "pEntity: PyDb.Entity" }))
        .def("cleanBody", &PyDb3dSolid::cleanBody, DS.ARGS())
        .def("offsetBody", &PyDb3dSolid::offsetBody, DS.ARGS({ "offsetDistance: float" }))
        .def("offsetFaces", &PyDb3dSolid::offsetFaces, DS.ARGS({ "faceSubentIds: list[PyDb.SubentId]", "offsetDistance: float" }))
        .def("removeFaces", &PyDb3dSolid::removeFaces, DS.ARGS({ "faceSubentIds: list[PyDb.SubentId]" }))
        .def("separateBody", &PyDb3dSolid::separateBody, DS.ARGS())
        .def("shellBody", &PyDb3dSolid::shellBody, DS.ARGS({ "faceSubentIds: list[PyDb.SubentId]", "offsetDistance: float" }))
        .def("taperFaces", &PyDb3dSolid::taperFaces, DS.ARGS({ "faceSubentIds: list[PyDb.SubentId]", "basePoint: PyGe.Point3d","draftVector: PyGe.Vector3d", "draftAngle: float" }))
        .def("transformFaces", &PyDb3dSolid::transformFaces, DS.ARGS({ "faceSubentIds: list[PyDb.SubentId]", "xform: PyGe.Matrix2d" }))
        .def("setSubentColor", &PyDb3dSolid::setSubentColor, DS.ARGS({ "faceSubentId: PyDb.SubentId", "clr: PyDb.AcCmColor" }))
        .def("getSubentColor", &PyDb3dSolid::getSubentColor, DS.ARGS({ "faceSubentId: PyDb.SubentId" }))
        .def("setSubentMaterial", &PyDb3dSolid::setSubentMaterial, DS.ARGS({ "faceSubentId: PyDb.SubentId", "id: PyDb.ObjectId" }))
        .def("getSubentMaterial", &PyDb3dSolid::getSubentMaterial, DS.ARGS({ "faceSubentId: PyDb.SubentId" }))
        .def("recordHistory", &PyDb3dSolid::recordHistory, DS.ARGS())
        .def("setRecordHistory", &PyDb3dSolid::setRecordHistory, DS.ARGS({ "val: bool" }))
        .def("showHistory", &PyDb3dSolid::showHistory, DS.ARGS())
        .def("setShowHistory", &PyDb3dSolid::setShowHistory, DS.ARGS({ "val: bool" }))
        .def("chamferEdges", &PyDb3dSolid::chamferEdges, DS.ARGS({ "edgeSubentIds: list[PyDb.SubentId]","faceSubentId: PyDb.SubentId","baseDist: float","otherDist: float" }))
        .def("filletEdges", &PyDb3dSolid::filletEdges, DS.ARGS({ "edgeSubentIds: list[PyDb.SubentId]","radius: list[float]","startSetback: list[float]","endSetback: list[float]" }))
        .def("usesGraphicsCache", &PyDb3dSolid::usesGraphicsCache, DS.ARGS())
        .def("createSculptedSolid", &PyDb3dSolid::createSculptedSolid, DS.ARGS({ "limitingBodies: list[PyDb.Entity]","limitingFlags: list[int]" }))
        .def("projectOnToSolid", &PyDb3dSolid::projectOnToSolid, DS.ARGS({ "pEntityToProject: PyDb.Entity","projectionDirection: PyGe.Vector3d" }))
        .def("className", &PyDb3dSolid::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDb3dSolid::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDb3dSolid::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDb3dSolid::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyDb3dSolid::PyDb3dSolid(AcDb3dSolid* ptr, bool autoDelete)
    : PyDbEntity(ptr, autoDelete)
{
}

PyDb3dSolid::PyDb3dSolid()
    : PyDbEntity(new AcDb3dSolid(), true)
{
}

PyDb3dSolid::PyDb3dSolid(const PyDbObjectId& id)
    : PyDbEntity(openAcDbObject<AcDb3dSolid>(id), false)
{
}

PyDb3dSolid::PyDb3dSolid(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbEntity(openAcDbObject<AcDb3dSolid>(id, mode), false)
{
}

PyDb3dSolid::PyDb3dSolid(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbEntity(openAcDbObject<AcDb3dSolid>(id, mode, erased), false)
{
}

void PyDb3dSolid::createBox(double xLen, double yLen, double zLen) const
{
    return PyThrowBadEs(impObj()->createBox(xLen, yLen, zLen));
}

void PyDb3dSolid::createFrustum(double height, double xRadius, double yRadius, double topXRadius) const
{
    return PyThrowBadEs(impObj()->createFrustum(height, xRadius, yRadius, topXRadius));
}

void PyDb3dSolid::createSphere(double radius) const
{
    return PyThrowBadEs(impObj()->createSphere(radius));
}

void PyDb3dSolid::createTorus(double majorRadius, double minorRadius) const
{
    return PyThrowBadEs(impObj()->createTorus(majorRadius, minorRadius));
}

void PyDb3dSolid::createPyramid1(double height, int sides, double radius) const
{
    return PyThrowBadEs(impObj()->createPyramid(height, sides, radius));
}

void PyDb3dSolid::createPyramid2(double height, int sides, double radius, double topRadius) const
{
    return PyThrowBadEs(impObj()->createPyramid(height, sides, radius, topRadius));
}

void PyDb3dSolid::createWedge(double xLen, double yLen, double zLen) const
{
    return PyThrowBadEs(impObj()->createWedge(xLen, yLen, zLen));
}

void PyDb3dSolid::extrude1(const PyDbRegion& region, double height) const
{
    return PyThrowBadEs(impObj()->extrude(region.impObj(), height));
}

void PyDb3dSolid::extrude2(const PyDbRegion& region, double height, double taperAngle) const
{
    return PyThrowBadEs(impObj()->extrude(region.impObj(), height, taperAngle));
}

void PyDb3dSolid::extrudeAlongPath1(const PyDbRegion& region, const PyDbCurve& path) const
{
    return PyThrowBadEs(impObj()->extrudeAlongPath(region.impObj(), path.impObj()));
}

void PyDb3dSolid::extrudeAlongPath2(const PyDbRegion& region, const PyDbCurve& path, double taperAngle) const
{
    return PyThrowBadEs(impObj()->extrudeAlongPath(region.impObj(), path.impObj(), taperAngle));
}

void PyDb3dSolid::createRevolvedSolid1(const PyDbEntity& pRevEnt, const AcGePoint3d& axisPnt, const AcGeVector3d& axisDir, double revAngle, double startAngle, PyDbRevolveOptions& revolveOptions) const
{
    return PyThrowBadEs(impObj()->createRevolvedSolid(pRevEnt.impObj(), axisPnt, axisDir, revAngle, startAngle, *revolveOptions.impObj()));
}

void PyDb3dSolid::createRevolvedSolid2(const PyDbEntity& pRevEnt, const PyDbSubentId& faceSubentId, const AcGePoint3d& axisPnt, const AcGeVector3d& axisDir, double revAngle, double startAngle, PyDbRevolveOptions& revolveOptions) const
{
    return PyThrowBadEs(impObj()->createRevolvedSolid(pRevEnt.impObj(), *faceSubentId.impObj(), axisPnt, axisDir, revAngle, startAngle, *revolveOptions.impObj()));
}

void PyDb3dSolid::createSweptSolid1(const PyDbEntity& pSweepEnt, const  PyDbEntity& pPathEnt, PyDbSweepOptions& sweepOptions) const
{
    return PyThrowBadEs(impObj()->createSweptSolid(pSweepEnt.impObj(), pPathEnt.impObj(), *sweepOptions.impObj()));
}

void PyDb3dSolid::createSweptSolid2(const PyDbEntity& pSweepEnt, const PyDbSubentId& faceSubentId, PyDbEntity& pPathEnt, PyDbSweepOptions& sweepOptions) const
{
    return PyThrowBadEs(impObj()->createSweptSolid(pSweepEnt.impObj(), *faceSubentId.impObj(), pPathEnt.impObj(), *sweepOptions.impObj()));
}

void PyDb3dSolid::createExtrudedSolid1(const PyDbEntity& pSweepEnt, const AcGeVector3d& directionVec, PyDbSweepOptions& sweepOptions) const
{
    return PyThrowBadEs(impObj()->createExtrudedSolid(pSweepEnt.impObj(), directionVec, *sweepOptions.impObj()));
}

void PyDb3dSolid::createExtrudedSolid2(const PyDbEntity& pSweepEnt, const PyDbSubentId& faceSubentId, const AcGeVector3d& directionVec, PyDbSweepOptions& sweepOptions) const
{
    return PyThrowBadEs(impObj()->createExtrudedSolid(pSweepEnt.impObj(), *faceSubentId.impObj(), directionVec, *sweepOptions.impObj()));
}

void PyDb3dSolid::createExtrudedSolid3(const PyDbEntity& pSweepEnt, const PyDbSubentId& faceSubentId, double height, PyDbSweepOptions& sweepOptions) const
{
    return PyThrowBadEs(impObj()->createExtrudedSolid(pSweepEnt.impObj(), *faceSubentId.impObj(), height, *sweepOptions.impObj()));
}

void PyDb3dSolid::createFrom(const PyDbEntity& pFromEntity) const
{
    return PyThrowBadEs(impObj()->createFrom(pFromEntity.impObj()));
}

double PyDb3dSolid::getArea() const
{
    double area = 0;
    PyThrowBadEs(impObj()->getArea(area));
    return area;
}

boost::python::tuple PyDb3dSolid::checkInterference(const PyDb3dSolid& otherSolid, Adesk::Boolean createNewSolid) const
{
    PyAutoLockGIL lock;
    Adesk::Boolean solidsInterfere = false;
    AcDb3dSolid* commonVolumeSolid = nullptr;
    PyThrowBadEs(impObj()->checkInterference(otherSolid.impObj(), createNewSolid, solidsInterfere, commonVolumeSolid));
    return boost::python::make_tuple(solidsInterfere, PyDb3dSolid(commonVolumeSolid, true));
}

boost::python::tuple PyDb3dSolid::getMassProp() const
{
    PyAutoLockGIL lock;
    double volume = 0;
    AcGePoint3d centroid;
    AcGePoint3d momInertia;
    AcGePoint3d prodInertia;
    AcGePoint3d prinMoments;
    AcGeVector3d prinAxes[3];
    AcGePoint3d radiiGyration;
    AcDbExtents extents;
    PyThrowBadEs(impObj()->getMassProp(volume, centroid, asDblArray(momInertia),
        asDblArray(prodInertia), asDblArray(prinMoments), prinAxes, asDblArray(radiiGyration), extents));
    return boost::python::make_tuple(volume, centroid, momInertia, prodInertia, prinMoments, prinAxes[0], prinAxes[1], prinAxes[2], radiiGyration, extents);
}

Adesk::Boolean PyDb3dSolid::isNull() const
{
    return impObj()->isNull();
}

PyDbRegion PyDb3dSolid::getSection(const PyGePlane& plane) const
{
    AcDbRegion* sectionRegion = nullptr;
    PyThrowBadEs(impObj()->getSection(*plane.impObj(), sectionRegion));
    return PyDbRegion(sectionRegion, true);
}

void PyDb3dSolid::stlOut1(const std::string& fileName, Adesk::Boolean asciiFormat) const
{
    return PyThrowBadEs(impObj()->stlOut(utf8_to_wstr(fileName).c_str(), asciiFormat));
}

void PyDb3dSolid::stlOut2(const std::string& fileName, Adesk::Boolean asciiFormat, double maxSurfaceDeviation) const
{
    return PyThrowBadEs(impObj()->stlOut(utf8_to_wstr(fileName).c_str(), asciiFormat, maxSurfaceDeviation));
}

void PyDb3dSolid::booleanOper(AcDb::BoolOperType operation, PyDb3dSolid& solid) const
{
    return PyThrowBadEs(impObj()->booleanOper(operation, solid.impObj()));
}

PyDb3dSolid PyDb3dSolid::getSlice1(const PyGePlane& plane, Adesk::Boolean getNegHalfToo) const
{
    AcDb3dSolid* negHalfSolid = nullptr;
    PyThrowBadEs(impObj()->getSlice(*plane.impObj(), getNegHalfToo, negHalfSolid));
    return PyDb3dSolid(negHalfSolid, true);
}

PyDb3dSolid PyDb3dSolid::getSlice2(const PyDbSurface& plane, Adesk::Boolean getNegHalfToo) const
{
    AcDb3dSolid* negHalfSolid = nullptr;
    PyThrowBadEs(impObj()->getSlice(plane.impObj(), getNegHalfToo, negHalfSolid));
    return PyDb3dSolid(negHalfSolid, true);
}

Adesk::UInt32 PyDb3dSolid::numChanges() const
{
    return impObj()->numChanges();
}

PyDbEntity PyDb3dSolid::copyEdge(const PyDbSubentId& subentId) const
{
    AcDbEntity* newEntity = nullptr;
    PyThrowBadEs(impObj()->copyEdge(*subentId.impObj(), newEntity));
    return PyDbEntity(newEntity, true);
}

PyDbEntity PyDb3dSolid::copyFace(const PyDbSubentId& subentId) const
{
    AcDbEntity* newEntity = nullptr;
    PyThrowBadEs(impObj()->copyFace(*subentId.impObj(), newEntity));
    return PyDbEntity(newEntity, true);
}

void PyDb3dSolid::extrudeFaces(const boost::python::list& faceSubentIds, double height, double taper) const
{
    return PyThrowBadEs(impObj()->extrudeFaces(PyListToPyDbSubentIdPtrArray(faceSubentIds), height, taper));
}

void PyDb3dSolid::extrudeFacesAlongPath(boost::python::list& faceSubentIds, const PyDbCurve& path) const
{
    return PyThrowBadEs(impObj()->extrudeFacesAlongPath(PyListToPyDbSubentIdPtrArray(faceSubentIds), path.impObj()));
}

void PyDb3dSolid::imprintEntity(const PyDbEntity& pEntity) const
{
    return PyThrowBadEs(impObj()->imprintEntity(pEntity.impObj()));
}

void PyDb3dSolid::cleanBody() const
{
    return PyThrowBadEs(impObj()->cleanBody());
}

void PyDb3dSolid::offsetBody(double offsetDistance) const
{
    return PyThrowBadEs(impObj()->offsetBody(offsetDistance));
}

void PyDb3dSolid::offsetFaces(const boost::python::list& faceSubentIds, double offsetDistance) const
{
    return PyThrowBadEs(impObj()->offsetFaces(PyListToPyDbSubentIdPtrArray(faceSubentIds), offsetDistance));
}

void PyDb3dSolid::removeFaces(const boost::python::list& faceSubentIds) const
{
    return PyThrowBadEs(impObj()->removeFaces(PyListToPyDbSubentIdPtrArray(faceSubentIds)));
}

boost::python::list PyDb3dSolid::separateBody() const
{
    PyAutoLockGIL lock;
    AcArray<AcDb3dSolid*> newSolids;
    PyThrowBadEs(impObj()->separateBody(newSolids));
    boost::python::list pyList;
    for (auto item : newSolids)
        pyList.append(PyDb3dSolid(item, true));
    return pyList;
}

void PyDb3dSolid::shellBody(const boost::python::list& faceSubentIds, double offsetDistance) const
{
    PyThrowBadEs(impObj()->shellBody(PyListToPyDbSubentIdPtrArray(faceSubentIds), offsetDistance));
}

void PyDb3dSolid::taperFaces(const boost::python::list& faceSubentIds, const AcGePoint3d& basePoint, const AcGeVector3d& draftVector, double draftAngle) const
{
    PyThrowBadEs(impObj()->taperFaces(PyListToPyDbSubentIdPtrArray(faceSubentIds), basePoint, draftVector, draftAngle));
}

void PyDb3dSolid::transformFaces(const boost::python::list& faceSubentIds, const AcGeMatrix3d& matrix) const
{
    PyThrowBadEs(impObj()->transformFaces(PyListToPyDbSubentIdPtrArray(faceSubentIds), matrix));
}

void PyDb3dSolid::setSubentColor(const PyDbSubentId& subentId, const AcCmColor& color) const
{
    PyThrowBadEs(impObj()->setSubentColor(*subentId.impObj(), color));
}

AcCmColor PyDb3dSolid::getSubentColor(const PyDbSubentId& subentId) const
{
    AcCmColor clr;
    PyThrowBadEs(impObj()->getSubentColor(*subentId.impObj(), clr));
    return clr;
}

void PyDb3dSolid::setSubentMaterial(const PyDbSubentId& subentId, const PyDbObjectId& matId) const
{
    return PyThrowBadEs(impObj()->setSubentMaterial(*subentId.impObj(), matId.m_id));
}

PyDbObjectId PyDb3dSolid::getSubentMaterial(const PyDbSubentId& subentId) const
{
    PyDbObjectId id;
    PyThrowBadEs(impObj()->getSubentMaterial(*subentId.impObj(), id.m_id));
    return id;
}

bool PyDb3dSolid::recordHistory() const
{
    return impObj()->recordHistory();
}

void PyDb3dSolid::setRecordHistory(bool bRecord) const
{
    return PyThrowBadEs(impObj()->setRecordHistory(bRecord));
}

bool PyDb3dSolid::showHistory() const
{
    return impObj()->showHistory();
}

void PyDb3dSolid::setShowHistory(bool bShow) const
{
    return PyThrowBadEs(impObj()->setShowHistory(bShow));
}

void PyDb3dSolid::chamferEdges(const boost::python::list& edgeSubentIds, const PyDbSubentId& baseFaceSubentId, double baseDist, double otherDist) const
{
    return PyThrowBadEs(impObj()->chamferEdges(PyListToPyDbSubentIdPtrArray(edgeSubentIds), *baseFaceSubentId.impObj(), baseDist, otherDist));
}

void PyDb3dSolid::filletEdges(const boost::python::list& edgeSubentIds, boost::python::list& radius, boost::python::list& startSetback, boost::python::list& endSetback) const
{
    const auto& _edgeSubentIds = PyListToPyDbSubentIdPtrArray(edgeSubentIds);
    const AcGeDoubleArray& _radius = PyListToDoubleArray(radius);
    const AcGeDoubleArray& _startSetback = PyListToDoubleArray(startSetback);
    const AcGeDoubleArray& _endSetback = PyListToDoubleArray(endSetback);
    return PyThrowBadEs(impObj()->filletEdges(_edgeSubentIds, _radius, _startSetback, _endSetback));
}

bool PyDb3dSolid::usesGraphicsCache() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->usesGraphicsCache();
#endif
}

void PyDb3dSolid::createSculptedSolid(const boost::python::list& limitingBodies, const boost::python::list& limitingFlags) const
{
    const auto& _limitingBodies = PyListToPyDbEntityPtrArray(limitingBodies);
    const AcGeIntArray& _limitingFlags = PyListToIntArray(limitingFlags);
    return PyThrowBadEs(impObj()->createSculptedSolid(_limitingBodies, _limitingFlags));
}

boost::python::list PyDb3dSolid::projectOnToSolid(const PyDbEntity& pEntityToProject, const AcGeVector3d& projectionDirection) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    PyAutoLockGIL lock;
    AcArray<AcDbEntity*> projectedEntities;
    PyThrowBadEs(impObj()->projectOnToSolid(pEntityToProject.impObj(), projectionDirection, projectedEntities));
    boost::python::list pyList;
    for (auto item : projectedEntities)
        pyList.append(PyDbEntity(item, true));
    return pyList;
#endif
}

std::string PyDb3dSolid::className()
{
    return "AcDb3dSolid";
}

PyRxClass PyDb3dSolid::desc()
{
    return PyRxClass(AcDb3dSolid::desc(), false);
}

PyDb3dSolid PyDb3dSolid::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDb3dSolid, AcDb3dSolid>(src);
}

PyDb3dSolid PyDb3dSolid::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDb3dSolid>(src);
}

AcDb3dSolid* PyDb3dSolid::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDb3dSolid*>(m_pyImp.get());
}


//-----------------------------------------------------------------------------------
//PyDbRegion
void makePyDbRegionWrapper()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n";

    PyDocString DS("PyDb.Region");
    class_<PyDbRegion, bases<PyDbEntity>>("Region")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>(DS.CTOR(ctords, 8157)))
        .def("isNull", &PyDbRegion::isNull, DS.ARGS())
        .def("createFromCurves", &PyDbRegion::createFromCurves, DS.SARGS({ "curves: list[PyDb.Curve]" })).staticmethod("createFromCurves")
        .def("className", &PyDbRegion::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbRegion::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbRegion::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbRegion::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyDbRegion::PyDbRegion()
    : PyDbEntity(new AcDbRegion(), true)
{
}

PyDbRegion::PyDbRegion(AcDbRegion* ptr, bool autoDelete)
    : PyDbEntity(ptr, autoDelete)
{
}

PyDbRegion::PyDbRegion(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbEntity(openAcDbObject<AcDbRegion>(id, mode), false)
{
}

PyDbRegion::PyDbRegion(const PyDbObjectId& id)
    : PyDbRegion(id, AcDb::OpenMode::kForRead)
{
}

Adesk::Boolean PyDbRegion::isNull() const
{
    return impObj()->isNull();
}

boost::python::list PyDbRegion::createFromCurves(const boost::python::list& curveSegments)
{
    PyAutoLockGIL lock;
    boost::python::list pyRegions;
#if defined(_ARXTARGET) && (_ARXTARGET >= 242)
    AcArray<AcDbEntity*> acCurveSegments;
    auto vec = py_list_to_std_vector<PyDbEntity>(curveSegments);
    for (auto& item : vec)
        acCurveSegments.append(item.impObj());
    AcArray<AcDbRegion*> regions;
    PyThrowBadEs(AcDbRegion::createFromCurves(acCurveSegments, regions));
    for (auto item : regions)
        pyRegions.append(PyDbRegion(item, true));
#else
    AcDbVoidPtrArray acCurveSegments;
    auto vec = py_list_to_std_vector<PyDbEntity>(curveSegments);
    for (auto& item : vec)
        acCurveSegments.append(item.impObj());
    AcDbVoidPtrArray regions;
    PyThrowBadEs(AcDbRegion::createFromCurves(acCurveSegments, regions));
    for (auto item : regions)
        pyRegions.append(PyDbRegion((AcDbRegion*)item, true));
#endif
    return pyRegions;
}

std::string PyDbRegion::className()
{
    return "AcDbRegion";
}

PyRxClass PyDbRegion::desc()
{
    return PyRxClass(AcDbRegion::desc(), false);
}

PyDbRegion PyDbRegion::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbRegion, AcDbRegion>(src);
}

PyDbRegion PyDbRegion::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbRegion>(src);
}

AcDbRegion* PyDbRegion::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbRegion*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyDbBody
void makePyDbBodyWrapper()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n";

    PyDocString DS("Body");
    class_<PyDbBody, bases<PyDbEntity>>("Body")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>(DS.CTOR(ctords, 2605)))
        .def("className", &PyDbBody::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbBody::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbBody::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbBody::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyDbBody::PyDbBody()
    : PyDbEntity(new AcDbBody(), true)
{
}

PyDbBody::PyDbBody(AcDbBody* ptr, bool autoDelete)
    : PyDbEntity(ptr, autoDelete)
{
}

PyDbBody::PyDbBody(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbEntity(openAcDbObject<AcDbBody>(id, mode), false)
{
}

PyDbBody::PyDbBody(const PyDbObjectId& id)
    : PyDbBody(id, AcDb::OpenMode::kForRead)
{
}

std::string PyDbBody::className()
{
    return "AcDbBody";
}

PyRxClass PyDbBody::desc()
{
    return PyRxClass(AcDbBody::desc(), false);
}

PyDbBody PyDbBody::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbBody, AcDbBody>(src);
}

PyDbBody PyDbBody::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbBody>(src);
}

AcDbBody* PyDbBody::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbBody*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyDbRevolveOptions
void makePyDbRevolveOptionsWrapper()
{
    PyDocString DS("RevolveOptions");
    class_<PyDbRevolveOptions>("RevolveOptions")
        .def(init<>(DS.ARGS(8289)))
        .def("draftAngle", &PyDbRevolveOptions::draftAngle, DS.ARGS())
        .def("setDraftAngle", &PyDbRevolveOptions::setDraftAngle, DS.ARGS({ "val: float" }))
        .def("twistAngle", &PyDbRevolveOptions::twistAngle, DS.ARGS())
        .def("setTwistAngle", &PyDbRevolveOptions::setTwistAngle, DS.ARGS({ "val: float" }))
        .def("closeToAxis", &PyDbRevolveOptions::closeToAxis, DS.ARGS())
        .def("setCloseToAxis", &PyDbRevolveOptions::setCloseToAxis, DS.ARGS({ "val: bool" }))
        .def("checkRevolveCurve", &PyDbRevolveOptions::checkRevolveCurve1)
        .def("checkRevolveCurve", &PyDbRevolveOptions::checkRevolveCurve2, DS.ARGS({ "ent: PyDb.Entity","axisPnt: PyGe.Point3d","axisDir: PyGe.Vector3d","displayErrorMessages: bool=False" }))
        ;
}

PyDbRevolveOptions::PyDbRevolveOptions()
    : m_pyImp(new AcDbRevolveOptions())
{
}

PyDbRevolveOptions::PyDbRevolveOptions(const AcDbRevolveOptions& src)
    : m_pyImp(new AcDbRevolveOptions(src))
{
}

double PyDbRevolveOptions::draftAngle() const
{
    return impObj()->draftAngle();
}

void PyDbRevolveOptions::setDraftAngle(double ang) const
{
    return impObj()->setDraftAngle(ang);
}

double PyDbRevolveOptions::twistAngle() const
{
    return impObj()->twistAngle();
}

void PyDbRevolveOptions::setTwistAngle(double ang) const
{
    return impObj()->setTwistAngle(ang);
}

bool PyDbRevolveOptions::closeToAxis() const
{
    return impObj()->closeToAxis();
}

void PyDbRevolveOptions::setCloseToAxis(bool val) const
{
    return impObj()->setCloseToAxis(val);
}

boost::python::tuple PyDbRevolveOptions::checkRevolveCurve1(PyDbEntity& ent, const AcGePoint3d& axisPnt, const AcGeVector3d& axisDir) const
{
    return checkRevolveCurve2(ent, axisPnt, axisDir, false);
}

boost::python::tuple PyDbRevolveOptions::checkRevolveCurve2(PyDbEntity& ent, const AcGePoint3d& axisPnt, const AcGeVector3d& axisDir, bool displayErrorMessages) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    PyAutoLockGIL lock;
    bool closed = false;
    bool planar = false;
    bool endPointsOnAxis = false;
    PyThrowBadEs(impObj()->checkRevolveCurve(ent.impObj(), axisPnt, axisDir, closed, endPointsOnAxis, planar, displayErrorMessages));
    return boost::python::make_tuple(closed, endPointsOnAxis, planar);
#endif
}

AcDbRevolveOptions* PyDbRevolveOptions::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbRevolveOptions*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyDbSweepOptions
void makePyDbSweepOptionsWrapper()
{
    constexpr const std::string_view setSweepEntityTransformOverloads = "Overloads:\n"
        "- mat: PyGe.Matrix3d\n"
        "- sweepEntities: list[PyDb.Entity]\n"
        "- sweepEntities: list[PyDb.Entity], displayErrorMessages: bool\n";

    constexpr const std::string_view setPathEntityTransformOverloads = "Overloads:\n"
        "- mat: PyGe.Matrix3d\n"
        "- pPathEnt: PyDb.Entity\n"
        "- pPathEnt: PyDb.Entity, displayErrorMessages: bool\n";

    PyDocString DS("SweepOptions");
    class_<PyDbSweepOptions>("SweepOptions")
        .def(init<>(DS.ARGS(8985)))
        .def("draftAngle", &PyDbSweepOptions::draftAngle, DS.ARGS())
        .def("setDraftAngle", &PyDbSweepOptions::setDraftAngle, DS.ARGS({ "val: float" }))
        .def("startDraftDist", &PyDbSweepOptions::startDraftDist, DS.ARGS())
        .def("setStartDraftDist", &PyDbSweepOptions::setStartDraftDist, DS.ARGS({ "val: float" }))
        .def("endDraftDist", &PyDbSweepOptions::endDraftDist, DS.ARGS())
        .def("setEndDraftDist", &PyDbSweepOptions::setEndDraftDist, DS.ARGS({ "val: float" }))
        .def("twistAngle", &PyDbSweepOptions::twistAngle, DS.ARGS())
        .def("setTwistAngle", &PyDbSweepOptions::setTwistAngle, DS.ARGS({ "val: float" }))
        .def("scaleFactor", &PyDbSweepOptions::scaleFactor, DS.ARGS())
        .def("setScaleFactor", &PyDbSweepOptions::setScaleFactor, DS.ARGS({ "val: float" }))
        .def("alignAngle", &PyDbSweepOptions::alignAngle, DS.ARGS())
        .def("setAlignAngle", &PyDbSweepOptions::setAlignAngle, DS.ARGS({ "val: float" }))
        .def("align", &PyDbSweepOptions::align, DS.ARGS())
        .def("setAlign", &PyDbSweepOptions::setAlign, DS.ARGS({ "val: PyDb.SweepAlignOption" }))
        .def("miterOption", &PyDbSweepOptions::miterOption, DS.ARGS())
        .def("setMiterOption", &PyDbSweepOptions::setMiterOption, DS.ARGS({ "val: PyDb.SweepMiterOption" }))
        .def("alignStart", &PyDbSweepOptions::alignStart, DS.ARGS())
        .def("setAlignStart", &PyDbSweepOptions::setAlignStart, DS.ARGS({ "val: bool" }))
        .def("basePoint", &PyDbSweepOptions::basePoint, DS.ARGS())
        .def("setBasePoint", &PyDbSweepOptions::setBasePoint, DS.ARGS({ "pt: PyGe.Point3d" }))
        .def("bank", &PyDbSweepOptions::bank, DS.ARGS())
        .def("setBank", &PyDbSweepOptions::setBank, DS.ARGS({ "val: bool" }))
        .def("checkIntersections", &PyDbSweepOptions::checkIntersections, DS.ARGS())
        .def("setCheckIntersections", &PyDbSweepOptions::setCheckIntersections, DS.ARGS({ "val: bool" }))
        .def("twistRefVec", &PyDbSweepOptions::twistRefVec, DS.ARGS())
        .def("setTwistRefVec", &PyDbSweepOptions::setTwistRefVec, DS.ARGS({ "vec: PyGe.Vector3d" }))
        .def("getSweepEntityTransform", &PyDbSweepOptions::getSweepEntityTransform, DS.ARGS({ "xform: PyGe.Matrix3d" }))
        .def("setSweepEntityTransform", &PyDbSweepOptions::setSweepEntityTransform1)
        .def("setSweepEntityTransform", &PyDbSweepOptions::setSweepEntityTransform2)
        .def("setSweepEntityTransform", &PyDbSweepOptions::setSweepEntityTransform3, DS.OVRL(setSweepEntityTransformOverloads))
        .def("getPathEntityTransform", &PyDbSweepOptions::getPathEntityTransform, DS.ARGS({ "xform: PyGe.Matrix3d" }))
        .def("setPathEntityTransform", &PyDbSweepOptions::setPathEntityTransform1)
        .def("setPathEntityTransform", &PyDbSweepOptions::setPathEntityTransform2)
        .def("setPathEntityTransform", &PyDbSweepOptions::setPathEntityTransform3, DS.OVRL(setPathEntityTransformOverloads))
        .def("checkSweepCurve", &PyDbSweepOptions::checkSweepCurve1)
        .def("checkSweepCurve", &PyDbSweepOptions::checkSweepCurve2, DS.ARGS({ "pPathEnt: PyDb.Entity","displayErrorMessages: bool=False" }))
        .def("checkPathCurve", &PyDbSweepOptions::checkPathCurve1)
        .def("checkPathCurve", &PyDbSweepOptions::checkPathCurve2, DS.ARGS({ "pPathEnt: PyDb.Entity","displayErrorMessages: bool=False" }))
        ;
    enum_<AcDbSweepOptions::AlignOption>("SweepAlignOption")
        .value("kNoAlignment", AcDbSweepOptions::AlignOption::kNoAlignment)
        .value("kAlignSweepEntityToPath", AcDbSweepOptions::AlignOption::kAlignSweepEntityToPath)
        .value("kTranslateSweepEntityToPath", AcDbSweepOptions::AlignOption::kTranslateSweepEntityToPath)
        .value("kTranslatePathToSweepEntity", AcDbSweepOptions::AlignOption::kTranslatePathToSweepEntity)
        .export_values()
        ;
    enum_<AcDbSweepOptions::MiterOption>("SweepMiterOption")
        .value("kDefaultMiter", AcDbSweepOptions::MiterOption::kDefaultMiter)
        .value("kOldMiter", AcDbSweepOptions::MiterOption::kOldMiter)
        .value("kNewMiter", AcDbSweepOptions::MiterOption::kNewMiter)
        .value("kCrimpMiter", AcDbSweepOptions::MiterOption::kCrimpMiter)
        .value("kBendMiter", AcDbSweepOptions::MiterOption::kBendMiter)
        .export_values()
        ;
}

PyDbSweepOptions::PyDbSweepOptions()
    : m_pyImp(new AcDbSweepOptions())
{
}

PyDbSweepOptions::PyDbSweepOptions(const AcDbSweepOptions& src)
    : m_pyImp(new AcDbSweepOptions(src))
{
}

double PyDbSweepOptions::draftAngle() const
{
    return impObj()->draftAngle();
}

void PyDbSweepOptions::setDraftAngle(double ang) const
{
    return impObj()->setDraftAngle(ang);
}

double PyDbSweepOptions::startDraftDist() const
{
    return impObj()->startDraftDist();
}

void PyDbSweepOptions::setStartDraftDist(double val) const
{
    return impObj()->setStartDraftDist(val);
}

double PyDbSweepOptions::endDraftDist() const
{
    return impObj()->endDraftDist();
}

void PyDbSweepOptions::setEndDraftDist(double val) const
{
    return impObj()->setEndDraftDist(val);
}

double PyDbSweepOptions::twistAngle() const
{
    return impObj()->twistAngle();
}

void PyDbSweepOptions::setTwistAngle(double ang) const
{
    return impObj()->setTwistAngle(ang);
}

double PyDbSweepOptions::scaleFactor() const
{
    return impObj()->scaleFactor();
}

void PyDbSweepOptions::setScaleFactor(double val) const
{
    return impObj()->setScaleFactor(val);
}

double PyDbSweepOptions::alignAngle() const
{
    return impObj()->alignAngle();
}

void PyDbSweepOptions::setAlignAngle(double ang) const
{
    return impObj()->setAlignAngle(ang);
}

AcDbSweepOptions::AlignOption PyDbSweepOptions::align() const
{
    return impObj()->align();
}

void PyDbSweepOptions::setAlign(AcDbSweepOptions::AlignOption val) const
{
    return impObj()->setAlign(val);
}

AcDbSweepOptions::MiterOption PyDbSweepOptions::miterOption() const
{
    return impObj()->miterOption();
}

void PyDbSweepOptions::setMiterOption(AcDbSweepOptions::MiterOption val) const
{
    return impObj()->setMiterOption(val);
}

bool PyDbSweepOptions::alignStart() const
{
    return impObj()->alignStart();
}

void PyDbSweepOptions::setAlignStart(bool val) const
{
    return impObj()->setAlignStart(val);
}

AcGePoint3d PyDbSweepOptions::basePoint() const
{
    return impObj()->basePoint();
}

void PyDbSweepOptions::setBasePoint(AcGePoint3d& pnt) const
{
    return impObj()->setBasePoint(pnt);
}

bool PyDbSweepOptions::bank() const
{
    return impObj()->bank();
}

void PyDbSweepOptions::setBank(bool val) const
{
    return impObj()->setBank(val);
}

bool PyDbSweepOptions::checkIntersections() const
{
    return impObj()->checkIntersections();
}

void PyDbSweepOptions::setCheckIntersections(bool val) const
{
    return impObj()->setCheckIntersections(val);
}

AcGeVector3d PyDbSweepOptions::twistRefVec() const
{
    return impObj()->twistRefVec();
}

void PyDbSweepOptions::setTwistRefVec(const AcGeVector3d& vec) const
{
    return impObj()->setTwistRefVec(vec);
}

bool PyDbSweepOptions::getSweepEntityTransform(AcGeMatrix3d& mat) const
{
    return impObj()->getSweepEntityTransform(mat);
}

void PyDbSweepOptions::setSweepEntityTransform1(AcGeMatrix3d& mat) const
{
    return impObj()->setSweepEntityTransform(mat);
}

void PyDbSweepOptions::setSweepEntityTransform2(boost::python::list& sweepEntities) const
{
    return setSweepEntityTransform3(sweepEntities, false);
}

void PyDbSweepOptions::setSweepEntityTransform3(boost::python::list& sweepEntities, bool displayErrorMessages) const
{
    AcArray<AcDbEntity*> _sweepEntities;
    auto vec = py_list_to_std_vector<PyDbEntity>(sweepEntities);
    for (auto& item : vec)
        _sweepEntities.append(item.impObj());
    return PyThrowBadEs(impObj()->setSweepEntityTransform(_sweepEntities, displayErrorMessages));
}

bool PyDbSweepOptions::getPathEntityTransform(AcGeMatrix3d& mat) const
{
    return impObj()->getPathEntityTransform(mat);
}

void PyDbSweepOptions::setPathEntityTransform1(AcGeMatrix3d& mat) const
{
    return impObj()->setPathEntityTransform(mat);
}

void PyDbSweepOptions::setPathEntityTransform2(PyDbEntity& pPathEnt) const
{
    return PyThrowBadEs(impObj()->setPathEntityTransform(pPathEnt.impObj()));
}

void PyDbSweepOptions::setPathEntityTransform3(PyDbEntity& pPathEnt, bool displayErrorMessages) const
{
    return PyThrowBadEs(impObj()->setPathEntityTransform(pPathEnt.impObj(), displayErrorMessages));
}

boost::python::tuple PyDbSweepOptions::checkSweepCurve1(PyDbEntity& pSweepEnt) const
{
    return checkSweepCurve2(pSweepEnt, false);
}

boost::python::tuple PyDbSweepOptions::checkSweepCurve2(PyDbEntity& pSweepEnt, bool displayErrorMessages) const
{
    PyAutoLockGIL lock;
    AcGePoint3d pnt;
    AcGeVector3d vec;
    bool closed = false;
    double approxArcLen = 0;
    AcDb::Planarity planarity = AcDb::kNonPlanar;
    if (auto es = impObj()->checkSweepCurve(pSweepEnt.impObj(), planarity, pnt, vec, closed, approxArcLen, displayErrorMessages); es != eOk)
        throw PyErrorStatusException(es);
    return boost::python::make_tuple(planarity, pnt, vec, closed, approxArcLen);
}

void PyDbSweepOptions::checkPathCurve1(PyDbEntity& pPathEnt) const
{
    return PyThrowBadEs(impObj()->checkPathCurve(pPathEnt.impObj()));
}

void PyDbSweepOptions::checkPathCurve2(PyDbEntity& pPathEnt, bool displayErrorMessages) const
{
    return PyThrowBadEs(impObj()->checkPathCurve(pPathEnt.impObj(), displayErrorMessages));
}

AcDbSweepOptions* PyDbSweepOptions::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbSweepOptions*>(m_pyImp.get());
}
