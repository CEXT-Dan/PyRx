#include "stdafx.h"
#include "PyDb3dSolid.h"
#include "PyDbObjectId.h"
#include "PyDbCurve.h"
#include "PyGePlane.h"
#include "PyDbSurface.h"

using namespace boost::python;

void makePyDb3dSolidWrapper()
{
    class_<PyDb3dSolid, bases<PyDbEntity>>("Solid3d")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("createBox", &PyDb3dSolid::createBox)
        .def("createFrustum", &PyDb3dSolid::createFrustum)
        .def("createSphere", &PyDb3dSolid::createSphere)
        .def("createTorus", &PyDb3dSolid::createTorus)
        .def("createPyramid", &PyDb3dSolid::createPyramid1)
        .def("createPyramid", &PyDb3dSolid::createPyramid2)
        .def("createWedge", &PyDb3dSolid::createWedge)
        .def("extrude", &PyDb3dSolid::extrude1)
        .def("extrude", &PyDb3dSolid::extrude2)
        .def("extrudeAlongPath", &PyDb3dSolid::extrudeAlongPath1)
        .def("extrudeAlongPath", &PyDb3dSolid::extrudeAlongPath2)
        .def("createRevolvedSolid", &PyDb3dSolid::createRevolvedSolid1)
        .def("createRevolvedSolid", &PyDb3dSolid::createRevolvedSolid2)
        .def("createSweptSolid", &PyDb3dSolid::createSweptSolid1)
        .def("createSweptSolid", &PyDb3dSolid::createSweptSolid2)
        .def("createExtrudedSolid", &PyDb3dSolid::createExtrudedSolid1)
        .def("createExtrudedSolid", &PyDb3dSolid::createExtrudedSolid2)
        .def("createExtrudedSolid", &PyDb3dSolid::createExtrudedSolid3)
        .def("createFrom", &PyDb3dSolid::createFrom)
        .def("getArea", &PyDb3dSolid::getArea)
        .def("checkInterference", &PyDb3dSolid::checkInterference)
        .def("getMassProp", &PyDb3dSolid::getMassProp)
        .def("isNull", &PyDb3dSolid::isNull)
        .def("getSection", &PyDb3dSolid::getSection)
        .def("stlOut", &PyDb3dSolid::stlOut1)
        .def("stlOut", &PyDb3dSolid::stlOut2)
        .def("booleanOper", &PyDb3dSolid::booleanOper)
        .def("getSlice", &PyDb3dSolid::getSlice1)
        .def("getSlice", &PyDb3dSolid::getSlice2)
        .def("numChanges", &PyDb3dSolid::numChanges)
        .def("copyEdge", &PyDb3dSolid::copyEdge)
        .def("copyFace", &PyDb3dSolid::copyFace)
        .def("extrudeFaces", &PyDb3dSolid::extrudeFaces)
        .def("extrudeFacesAlongPath", &PyDb3dSolid::extrudeFacesAlongPath)
        .def("imprintEntity", &PyDb3dSolid::imprintEntity)
        .def("cleanBody", &PyDb3dSolid::cleanBody)
        .def("offsetBody", &PyDb3dSolid::offsetBody)
        .def("offsetFaces", &PyDb3dSolid::offsetFaces)
        .def("removeFaces", &PyDb3dSolid::removeFaces)
        .def("separateBody", &PyDb3dSolid::separateBody)
        .def("shellBody", &PyDb3dSolid::shellBody)
        .def("taperFaces", &PyDb3dSolid::taperFaces)
        .def("transformFaces", &PyDb3dSolid::transformFaces)
        .def("setSubentColor", &PyDb3dSolid::setSubentColor)
        .def("getSubentColor", &PyDb3dSolid::getSubentColor)
        .def("setSubentMaterial", &PyDb3dSolid::setSubentMaterial)
        .def("getSubentMaterial", &PyDb3dSolid::getSubentMaterial)
        .def("recordHistory", &PyDb3dSolid::recordHistory)
        .def("setRecordHistory", &PyDb3dSolid::setRecordHistory)
        .def("showHistory", &PyDb3dSolid::showHistory)
        .def("setShowHistory", &PyDb3dSolid::setShowHistory)
        .def("chamferEdges", &PyDb3dSolid::chamferEdges)
        .def("filletEdges", &PyDb3dSolid::filletEdges)
        .def("usesGraphicsCache", &PyDb3dSolid::usesGraphicsCache)
        .def("createSculptedSolid", &PyDb3dSolid::createSculptedSolid)
        .def("projectOnToSolid", &PyDb3dSolid::projectOnToSolid)
        .def("className", &PyDb3dSolid::className).staticmethod("className")
        .def("desc", &PyDb3dSolid::desc).staticmethod("desc")
        .def("cloneFrom", &PyDb3dSolid::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDb3dSolid::cast).staticmethod("cast")
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

PyDb3dSolid::PyDb3dSolid(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbEntity(openAcDbObject<AcDb3dSolid>(id, mode), false)
{
}

PyDb3dSolid::PyDb3dSolid(const PyDbObjectId& id)
    : PyDb3dSolid(id, AcDb::OpenMode::kForRead)
{
}

void PyDb3dSolid::createBox(double xLen, double yLen, double zLen)
{
    return PyThrowBadEs(impObj()->createBox(xLen, yLen, zLen));
}

void PyDb3dSolid::createFrustum(double height, double xRadius, double yRadius, double topXRadius)
{
    return PyThrowBadEs(impObj()->createFrustum(height, xRadius, yRadius, topXRadius));
}

void PyDb3dSolid::createSphere(double radius)
{
    return PyThrowBadEs(impObj()->createSphere(radius));
}

void PyDb3dSolid::createTorus(double majorRadius, double minorRadius)
{
    return PyThrowBadEs(impObj()->createTorus(majorRadius, minorRadius));
}

void PyDb3dSolid::createPyramid1(double height, int sides, double radius)
{
    return PyThrowBadEs(impObj()->createPyramid(height, sides, radius));
}

void PyDb3dSolid::createPyramid2(double height, int sides, double radius, double topRadius)
{
    return PyThrowBadEs(impObj()->createPyramid(height, sides, radius, topRadius));
}

void PyDb3dSolid::createWedge(double xLen, double yLen, double zLen)
{
    return PyThrowBadEs(impObj()->createWedge(xLen, yLen, zLen));
}

void PyDb3dSolid::extrude1(const PyDbRegion& region, double height)
{
    return PyThrowBadEs(impObj()->extrude(region.impObj(), height));
}

void PyDb3dSolid::extrude2(const PyDbRegion& region, double height, double taperAngle)
{
    return PyThrowBadEs(impObj()->extrude(region.impObj(), height, taperAngle));
}

void PyDb3dSolid::extrudeAlongPath1(const PyDbRegion& region, const PyDbCurve& path)
{
    return PyThrowBadEs(impObj()->extrudeAlongPath(region.impObj(), path.impObj()));
}

void PyDb3dSolid::extrudeAlongPath2(const PyDbRegion& region, const PyDbCurve& path, double taperAngle)
{
    return PyThrowBadEs(impObj()->extrudeAlongPath(region.impObj(), path.impObj(), taperAngle));
}

void PyDb3dSolid::createRevolvedSolid1(PyDbEntity& pRevEnt, const AcGePoint3d& axisPnt, const AcGeVector3d& axisDir, double revAngle, double startAngle, PyDbRevolveOptions& revolveOptions)
{
    return PyThrowBadEs(impObj()->createRevolvedSolid(pRevEnt.impObj(), axisPnt, axisDir, revAngle, startAngle, *revolveOptions.impObj()));
}

void PyDb3dSolid::createRevolvedSolid2(PyDbEntity& pRevEnt, const PyDbSubentId& faceSubentId, const AcGePoint3d& axisPnt, const AcGeVector3d& axisDir, double revAngle, double startAngle, PyDbRevolveOptions& revolveOptions)
{
    return PyThrowBadEs(impObj()->createRevolvedSolid(pRevEnt.impObj(), *faceSubentId.impObj(), axisPnt, axisDir, revAngle, startAngle, *revolveOptions.impObj()));
}

void PyDb3dSolid::createSweptSolid1(PyDbEntity& pSweepEnt, PyDbEntity& pPathEnt, PyDbSweepOptions& sweepOptions)
{
    return PyThrowBadEs(impObj()->createSweptSolid(pSweepEnt.impObj(), pPathEnt.impObj(), *sweepOptions.impObj()));
}

void PyDb3dSolid::createSweptSolid2(PyDbEntity& pSweepEnt, const PyDbSubentId& faceSubentId, PyDbEntity& pPathEnt, PyDbSweepOptions& sweepOptions)
{
    return PyThrowBadEs(impObj()->createSweptSolid(pSweepEnt.impObj(), *faceSubentId.impObj(), pPathEnt.impObj(), *sweepOptions.impObj()));
}

void PyDb3dSolid::createExtrudedSolid1(PyDbEntity& pSweepEnt, const AcGeVector3d& directionVec, PyDbSweepOptions& sweepOptions)
{
    return PyThrowBadEs(impObj()->createExtrudedSolid(pSweepEnt.impObj(), directionVec, *sweepOptions.impObj()));
}

void PyDb3dSolid::createExtrudedSolid2(PyDbEntity& pSweepEnt, const PyDbSubentId& faceSubentId, const AcGeVector3d& directionVec, PyDbSweepOptions& sweepOptions)
{
    return PyThrowBadEs(impObj()->createExtrudedSolid(pSweepEnt.impObj(), *faceSubentId.impObj(), directionVec, *sweepOptions.impObj()));
}

void PyDb3dSolid::createExtrudedSolid3(PyDbEntity& pSweepEnt, const PyDbSubentId& faceSubentId, double height, PyDbSweepOptions& sweepOptions)
{
    return PyThrowBadEs(impObj()->createExtrudedSolid(pSweepEnt.impObj(), *faceSubentId.impObj(), height, *sweepOptions.impObj()));
}

void PyDb3dSolid::createFrom(const PyDbEntity& pFromEntity)
{
    return PyThrowBadEs(impObj()->createFrom(pFromEntity.impObj()));
}

double PyDb3dSolid::getArea() const
{
    double area = 0;
    PyThrowBadEs(impObj()->getArea(area));
    return area;
}

boost::python::tuple PyDb3dSolid::checkInterference(const PyDb3dSolid& otherSolid, Adesk::Boolean createNewSolid)
{
    PyAutoLockGIL lock;
    Adesk::Boolean solidsInterfere = false;
    AcDb3dSolid* commonVolumeSolid = nullptr;
    PyThrowBadEs(impObj()->checkInterference(otherSolid.impObj(), createNewSolid, solidsInterfere, commonVolumeSolid));
    return boost::python::make_tuple(solidsInterfere, PyDb3dSolid(commonVolumeSolid, true));
}

boost::python::tuple PyDb3dSolid::getMassProp()
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

PyDbRegion PyDb3dSolid::getSection(const PyGePlane& plane)
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

void PyDb3dSolid::booleanOper(AcDb::BoolOperType operation, PyDb3dSolid& solid)
{
    return PyThrowBadEs(impObj()->booleanOper(operation, solid.impObj()));
}

PyDb3dSolid PyDb3dSolid::getSlice1(const PyGePlane& plane, Adesk::Boolean getNegHalfToo)
{
    AcDb3dSolid* negHalfSolid = nullptr;
    PyThrowBadEs(impObj()->getSlice(*plane.impObj(), getNegHalfToo, negHalfSolid));
    return PyDb3dSolid(negHalfSolid, true);
}

PyDb3dSolid PyDb3dSolid::getSlice2(const PyDbSurface& plane, Adesk::Boolean getNegHalfToo)
{
    AcDb3dSolid* negHalfSolid = nullptr;
    PyThrowBadEs(impObj()->getSlice(plane.impObj(), getNegHalfToo, negHalfSolid));
    return PyDb3dSolid(negHalfSolid, true);
}

Adesk::UInt32 PyDb3dSolid::numChanges() const
{
    return impObj()->numChanges();
}

PyDbEntity PyDb3dSolid::copyEdge(const PyDbSubentId& subentId)
{
    AcDbEntity* newEntity = nullptr;
    PyThrowBadEs(impObj()->copyEdge(*subentId.impObj(), newEntity));
    return PyDbEntity(newEntity, true);
}

PyDbEntity PyDb3dSolid::copyFace(const PyDbSubentId& subentId)
{
    AcDbEntity* newEntity = nullptr;
    PyThrowBadEs(impObj()->copyFace(*subentId.impObj(), newEntity));
    return PyDbEntity(newEntity, true);
}

void PyDb3dSolid::extrudeFaces(const boost::python::list& faceSubentIds, double height, double taper)
{
    return PyThrowBadEs(impObj()->extrudeFaces(PyListToPyDbSubentIdPtrArray(faceSubentIds), height, taper));
}

void PyDb3dSolid::extrudeFacesAlongPath(boost::python::list& faceSubentIds, const PyDbCurve& path)
{
    return PyThrowBadEs(impObj()->extrudeFacesAlongPath(PyListToPyDbSubentIdPtrArray(faceSubentIds), path.impObj()));
}

void PyDb3dSolid::imprintEntity(const PyDbEntity& pEntity)
{
    return PyThrowBadEs(impObj()->imprintEntity(pEntity.impObj()));
}

void PyDb3dSolid::cleanBody()
{
    return PyThrowBadEs(impObj()->cleanBody());
}

void PyDb3dSolid::offsetBody(double offsetDistance)
{
    return PyThrowBadEs(impObj()->offsetBody(offsetDistance));
}

void PyDb3dSolid::offsetFaces(const boost::python::list& faceSubentIds, double offsetDistance)
{
    return PyThrowBadEs(impObj()->offsetFaces(PyListToPyDbSubentIdPtrArray(faceSubentIds), offsetDistance));
}

void PyDb3dSolid::removeFaces(const boost::python::list& faceSubentIds)
{
    return PyThrowBadEs(impObj()->removeFaces(PyListToPyDbSubentIdPtrArray(faceSubentIds)));
}

boost::python::list PyDb3dSolid::separateBody()
{
    PyAutoLockGIL lock;
    AcArray<AcDb3dSolid*> newSolids;
    PyThrowBadEs(impObj()->separateBody(newSolids));
    boost::python::list pyList;
    for (auto item : newSolids)
        pyList.append(PyDb3dSolid(item, true));
    return pyList;
}

void PyDb3dSolid::shellBody(const boost::python::list& faceSubentIds, double offsetDistance)
{
    PyThrowBadEs(impObj()->shellBody(PyListToPyDbSubentIdPtrArray(faceSubentIds), offsetDistance));
}

void PyDb3dSolid::taperFaces(const boost::python::list& faceSubentIds, const AcGePoint3d& basePoint, const AcGeVector3d& draftVector, double draftAngle)
{
    PyThrowBadEs(impObj()->taperFaces(PyListToPyDbSubentIdPtrArray(faceSubentIds), basePoint, draftVector, draftAngle));
}

void PyDb3dSolid::transformFaces(const boost::python::list& faceSubentIds, const AcGeMatrix3d& matrix)
{
    PyThrowBadEs(impObj()->transformFaces(PyListToPyDbSubentIdPtrArray(faceSubentIds), matrix));
}

void PyDb3dSolid::setSubentColor(const PyDbSubentId& subentId, const AcCmColor& color)
{
    PyThrowBadEs(impObj()->setSubentColor(*subentId.impObj(), color));
}

AcCmColor PyDb3dSolid::getSubentColor(const PyDbSubentId& subentId) const
{
    AcCmColor clr;
    PyThrowBadEs(impObj()->getSubentColor(*subentId.impObj(), clr));
    return clr;
}

void PyDb3dSolid::setSubentMaterial(const PyDbSubentId& subentId, PyDbObjectId& matId)
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

void PyDb3dSolid::setRecordHistory(bool bRecord)
{
    return PyThrowBadEs(impObj()->setRecordHistory(bRecord));
}

bool PyDb3dSolid::showHistory() const
{
    return impObj()->showHistory();
}

void PyDb3dSolid::setShowHistory(bool bShow)
{
    return PyThrowBadEs(impObj()->setShowHistory(bShow));
}

void PyDb3dSolid::chamferEdges(const boost::python::list& edgeSubentIds, const PyDbSubentId& baseFaceSubentId, double baseDist, double otherDist)
{
    return PyThrowBadEs(impObj()->chamferEdges(PyListToPyDbSubentIdPtrArray(edgeSubentIds), *baseFaceSubentId.impObj(), baseDist, otherDist));
}

void PyDb3dSolid::filletEdges(const boost::python::list& edgeSubentIds, boost::python::list& radius, boost::python::list& startSetback, boost::python::list& endSetback)
{
    const auto& _edgeSubentIds = PyListToPyDbSubentIdPtrArray(edgeSubentIds);
    const AcGeDoubleArray& _radius = PyListToDoubleArray(radius);
    const AcGeDoubleArray& _startSetback = PyListToDoubleArray(startSetback);
    const AcGeDoubleArray& _endSetback = PyListToDoubleArray(endSetback);
    return PyThrowBadEs(impObj()->filletEdges(_edgeSubentIds, _radius, _startSetback, _endSetback));
}

bool PyDb3dSolid::usesGraphicsCache()
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return impObj()->usesGraphicsCache();
#endif
}

void PyDb3dSolid::createSculptedSolid(const boost::python::list& limitingBodies, const boost::python::list& limitingFlags)
{
    const auto& _limitingBodies = PyListToPyDbEntityPtrArray(limitingBodies);
    const AcGeIntArray& _limitingFlags = PyListToIntArray(limitingFlags);
    return PyThrowBadEs(impObj()->createSculptedSolid(_limitingBodies, _limitingFlags));
}

boost::python::list PyDb3dSolid::projectOnToSolid(const PyDbEntity& pEntityToProject, const AcGeVector3d& projectionDirection) const
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
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
    if (!src.impObj()->isKindOf(AcDb3dSolid::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDb3dSolid(static_cast<AcDb3dSolid*>(src.impObj()->clone()), true);
}

PyDb3dSolid PyDb3dSolid::cast(const PyRxObject& src)
{
    PyDb3dSolid dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
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
    class_<PyDbRegion, bases<PyDbEntity>>("Region")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("isNull", &PyDbRegion::isNull)
        .def("createFromCurves", &PyDbRegion::createFromCurves).staticmethod("createFromCurves")
        .def("className", &PyDbRegion::className).staticmethod("className")
        .def("desc", &PyDbRegion::desc).staticmethod("desc")
        .def("cloneFrom", &PyDbRegion::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbRegion::cast).staticmethod("cast")
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
    if (!src.impObj()->isKindOf(AcDbRegion::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbRegion(static_cast<AcDbRegion*>(src.impObj()->clone()), true);
}

PyDbRegion PyDbRegion::cast(const PyRxObject& src)
{
    PyDbRegion dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
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
    class_<PyDbBody, bases<PyDbEntity>>("Body")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("className", &PyDbBody::className).staticmethod("className")
        .def("desc", &PyDbBody::desc).staticmethod("desc")
        .def("cloneFrom", &PyDbBody::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbBody::cast).staticmethod("cast")
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
    if (!src.impObj()->isKindOf(AcDbBody::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbBody(static_cast<AcDbBody*>(src.impObj()->clone()), true);
}

PyDbBody PyDbBody::cast(const PyRxObject& src)
{
    PyDbBody dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
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
    class_<PyDbRevolveOptions>("RevolveOptions")
        .def(init<>())
        .def("draftAngle", &PyDbRevolveOptions::draftAngle)
        .def("setDraftAngle", &PyDbRevolveOptions::setDraftAngle)
        .def("twistAngle", &PyDbRevolveOptions::twistAngle)
        .def("setTwistAngle", &PyDbRevolveOptions::setTwistAngle)
        .def("closeToAxis", &PyDbRevolveOptions::closeToAxis)
        .def("setCloseToAxis", &PyDbRevolveOptions::setCloseToAxis)
        .def("checkRevolveCurve", &PyDbRevolveOptions::checkRevolveCurve1)
        .def("checkRevolveCurve", &PyDbRevolveOptions::checkRevolveCurve2)
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

void PyDbRevolveOptions::setDraftAngle(double ang)
{
    return impObj()->setDraftAngle(ang);
}

double PyDbRevolveOptions::twistAngle() const
{
    return impObj()->twistAngle();
}

void PyDbRevolveOptions::setTwistAngle(double ang)
{
    return impObj()->setTwistAngle(ang);
}

bool PyDbRevolveOptions::closeToAxis() const
{
    return impObj()->closeToAxis();
}

void PyDbRevolveOptions::setCloseToAxis(bool val)
{
    return impObj()->setCloseToAxis(val);
}

boost::python::tuple PyDbRevolveOptions::checkRevolveCurve1(PyDbEntity& ent, const AcGePoint3d& axisPnt, const AcGeVector3d& axisDir)
{
    return checkRevolveCurve2(ent, axisPnt, axisDir, false);
}

boost::python::tuple PyDbRevolveOptions::checkRevolveCurve2(PyDbEntity& ent, const AcGePoint3d& axisPnt, const AcGeVector3d& axisDir, bool displayErrorMessages)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
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
    class_<PyDbSweepOptions>("SweepOptions")
        .def(init<>())
        .def("draftAngle", &PyDbSweepOptions::draftAngle)
        .def("setDraftAngle", &PyDbSweepOptions::setDraftAngle)
        .def("startDraftDist", &PyDbSweepOptions::startDraftDist)
        .def("setStartDraftDist", &PyDbSweepOptions::setStartDraftDist)
        .def("endDraftDist", &PyDbSweepOptions::endDraftDist)
        .def("setEndDraftDist", &PyDbSweepOptions::setEndDraftDist)
        .def("twistAngle", &PyDbSweepOptions::twistAngle)
        .def("setTwistAngle", &PyDbSweepOptions::setTwistAngle)
        .def("scaleFactor", &PyDbSweepOptions::scaleFactor)
        .def("setScaleFactor", &PyDbSweepOptions::setScaleFactor)
        .def("alignAngle", &PyDbSweepOptions::alignAngle)
        .def("setAlignAngle", &PyDbSweepOptions::setAlignAngle)
        .def("align", &PyDbSweepOptions::align)
        .def("setAlign", &PyDbSweepOptions::setAlign)
        .def("miterOption", &PyDbSweepOptions::miterOption)
        .def("setMiterOption", &PyDbSweepOptions::setMiterOption)
        .def("alignStart", &PyDbSweepOptions::alignStart)
        .def("setAlignStart", &PyDbSweepOptions::setAlignStart)
        .def("basePoint", &PyDbSweepOptions::basePoint)
        .def("setBasePoint", &PyDbSweepOptions::setBasePoint)
        .def("bank", &PyDbSweepOptions::bank)
        .def("setBank", &PyDbSweepOptions::setBank)
        .def("checkIntersections", &PyDbSweepOptions::checkIntersections)
        .def("setCheckIntersections", &PyDbSweepOptions::setCheckIntersections)
        .def("twistRefVec", &PyDbSweepOptions::twistRefVec)
        .def("setTwistRefVec", &PyDbSweepOptions::setTwistRefVec)
        .def("getSweepEntityTransform", &PyDbSweepOptions::getSweepEntityTransform)
        .def("setSweepEntityTransform", &PyDbSweepOptions::setSweepEntityTransform1)
        .def("setSweepEntityTransform", &PyDbSweepOptions::setSweepEntityTransform2)
        .def("setSweepEntityTransform", &PyDbSweepOptions::setSweepEntityTransform3)
        .def("getPathEntityTransform", &PyDbSweepOptions::getPathEntityTransform)
        .def("setPathEntityTransform", &PyDbSweepOptions::setPathEntityTransform1)
        .def("setPathEntityTransform", &PyDbSweepOptions::setPathEntityTransform2)
        .def("setPathEntityTransform", &PyDbSweepOptions::setPathEntityTransform3)
        .def("checkSweepCurve", &PyDbSweepOptions::checkSweepCurve1)
        .def("checkSweepCurve", &PyDbSweepOptions::checkSweepCurve2)
        .def("checkPathCurve", &PyDbSweepOptions::checkPathCurve1)
        .def("checkPathCurve", &PyDbSweepOptions::checkPathCurve2)
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

void PyDbSweepOptions::setDraftAngle(double ang)
{
    return impObj()->setDraftAngle(ang);
}

double PyDbSweepOptions::startDraftDist() const
{
    return impObj()->startDraftDist();
}

void PyDbSweepOptions::setStartDraftDist(double val)
{
    return impObj()->setStartDraftDist(val);
}

double PyDbSweepOptions::endDraftDist() const
{
    return impObj()->endDraftDist();
}

void PyDbSweepOptions::setEndDraftDist(double val)
{
    return impObj()->setEndDraftDist(val);
}

double PyDbSweepOptions::twistAngle() const
{
    return impObj()->twistAngle();
}

void PyDbSweepOptions::setTwistAngle(double ang)
{
    return impObj()->setTwistAngle(ang);
}

double PyDbSweepOptions::scaleFactor() const
{
    return impObj()->scaleFactor();
}

void PyDbSweepOptions::setScaleFactor(double val)
{
    return impObj()->setScaleFactor(val);
}

double PyDbSweepOptions::alignAngle() const
{
    return impObj()->alignAngle();
}

void PyDbSweepOptions::setAlignAngle(double ang)
{
    return impObj()->setAlignAngle(ang);
}

AcDbSweepOptions::AlignOption PyDbSweepOptions::align() const
{
    return impObj()->align();
}

void PyDbSweepOptions::setAlign(AcDbSweepOptions::AlignOption val)
{
    return impObj()->setAlign(val);
}

AcDbSweepOptions::MiterOption PyDbSweepOptions::miterOption() const
{
    return impObj()->miterOption();
}

void PyDbSweepOptions::setMiterOption(AcDbSweepOptions::MiterOption val)
{
    return impObj()->setMiterOption(val);
}

bool PyDbSweepOptions::alignStart() const
{
    return impObj()->alignStart();
}

void PyDbSweepOptions::setAlignStart(bool val)
{
    return impObj()->setAlignStart(val);
}

AcGePoint3d PyDbSweepOptions::basePoint() const
{
    return impObj()->basePoint();
}

void PyDbSweepOptions::setBasePoint(AcGePoint3d& pnt)
{
    return impObj()->setBasePoint(pnt);
}

bool PyDbSweepOptions::bank() const
{
    return impObj()->bank();
}

void PyDbSweepOptions::setBank(bool val)
{
    return impObj()->setBank(val);
}

bool PyDbSweepOptions::checkIntersections() const
{
    return impObj()->checkIntersections();
}

void PyDbSweepOptions::setCheckIntersections(bool val)
{
    return impObj()->setCheckIntersections(val);
}

AcGeVector3d PyDbSweepOptions::twistRefVec() const
{
    return impObj()->twistRefVec();
}

void PyDbSweepOptions::setTwistRefVec(const AcGeVector3d& vec)
{
    return impObj()->setTwistRefVec(vec);
}

bool PyDbSweepOptions::getSweepEntityTransform(AcGeMatrix3d& mat)
{
    return impObj()->getSweepEntityTransform(mat);
}

void PyDbSweepOptions::setSweepEntityTransform1(AcGeMatrix3d& mat)
{
    return impObj()->setSweepEntityTransform(mat);
}

void PyDbSweepOptions::setSweepEntityTransform2(boost::python::list& sweepEntities)
{
    return setSweepEntityTransform3(sweepEntities, false);
}

void PyDbSweepOptions::setSweepEntityTransform3(boost::python::list& sweepEntities, bool displayErrorMessages)
{
    AcArray<AcDbEntity*> _sweepEntities;
    auto vec = py_list_to_std_vector<PyDbEntity>(sweepEntities);
    for (auto& item : vec)
        _sweepEntities.append(item.impObj());
    return PyThrowBadEs(impObj()->setSweepEntityTransform(_sweepEntities, displayErrorMessages));
}

bool PyDbSweepOptions::getPathEntityTransform(AcGeMatrix3d& mat)
{
    return impObj()->getPathEntityTransform(mat);
}

void PyDbSweepOptions::setPathEntityTransform1(AcGeMatrix3d& mat)
{
    return impObj()->setPathEntityTransform(mat);
}

void PyDbSweepOptions::setPathEntityTransform2(PyDbEntity& pPathEnt)
{
    return PyThrowBadEs(impObj()->setPathEntityTransform(pPathEnt.impObj()));
}

void PyDbSweepOptions::setPathEntityTransform3(PyDbEntity& pPathEnt, bool displayErrorMessages)
{
    return PyThrowBadEs(impObj()->setPathEntityTransform(pPathEnt.impObj(), displayErrorMessages));
}

boost::python::tuple PyDbSweepOptions::checkSweepCurve1(PyDbEntity& pSweepEnt)
{
    return checkSweepCurve2(pSweepEnt, false);
}

boost::python::tuple PyDbSweepOptions::checkSweepCurve2(PyDbEntity& pSweepEnt, bool displayErrorMessages)
{
    PyAutoLockGIL lock;
    AcDb::Planarity planarity;
    AcGePoint3d pnt;
    AcGeVector3d vec;
    bool closed = false;
    double approxArcLen = 0;
    if (auto es = impObj()->checkSweepCurve(pSweepEnt.impObj(), planarity, pnt, vec, closed, approxArcLen, displayErrorMessages); es != eOk)
        throw PyAcadErrorStatus(es);
    return boost::python::make_tuple(planarity, pnt, vec, closed, approxArcLen);
}

void PyDbSweepOptions::checkPathCurve1(PyDbEntity& pPathEnt)
{
    return PyThrowBadEs(impObj()->checkPathCurve(pPathEnt.impObj()));
}

void PyDbSweepOptions::checkPathCurve2(PyDbEntity& pPathEnt, bool displayErrorMessages)
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
