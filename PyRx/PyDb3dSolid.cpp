#include "stdafx.h"
#include "PyDb3dSolid.h"
#include "PyDbObjectId.h"
#include "PyDbCurve.h"

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
    : PyDbEntity(nullptr, false)
{
    AcDb3dSolid* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDb3dSolid>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
}

PyDb3dSolid::PyDb3dSolid(const PyDbObjectId& id)
    : PyDb3dSolid(id, AcDb::OpenMode::kForRead)
{
}

Acad::ErrorStatus PyDb3dSolid::createBox(double xLen, double yLen, double zLen)
{
    return impObj()->createBox(xLen, yLen, zLen);
}

Acad::ErrorStatus PyDb3dSolid::createFrustum(double height, double xRadius, double yRadius, double topXRadius)
{
    return impObj()->createFrustum(height, xRadius, yRadius, topXRadius);
}

Acad::ErrorStatus PyDb3dSolid::createSphere(double radius)
{
    return impObj()->createSphere(radius);
}

Acad::ErrorStatus PyDb3dSolid::createTorus(double majorRadius, double minorRadius)
{
    return impObj()->createTorus(majorRadius, minorRadius);
}

Acad::ErrorStatus PyDb3dSolid::createPyramid1(double height, int sides, double radius)
{
    return impObj()->createPyramid(height, sides, radius);
}

Acad::ErrorStatus PyDb3dSolid::createPyramid2(double height, int sides, double radius, double topRadius)
{
    return impObj()->createPyramid(height, sides, radius, topRadius);
}

Acad::ErrorStatus PyDb3dSolid::createWedge(double xLen, double yLen, double zLen)
{
    return impObj()->createWedge(xLen, yLen, zLen);
}

Acad::ErrorStatus PyDb3dSolid::extrude1(const PyDbRegion& region, double height)
{
    return impObj()->extrude(region.impObj(), height);
}

Acad::ErrorStatus PyDb3dSolid::extrude2(const PyDbRegion& region, double height, double taperAngle)
{
    return impObj()->extrude(region.impObj(), height, taperAngle);
}

Acad::ErrorStatus PyDb3dSolid::extrudeAlongPath1(const PyDbRegion& region, const PyDbCurve& path)
{
    return impObj()->extrudeAlongPath(region.impObj(), path.impObj());
}

Acad::ErrorStatus PyDb3dSolid::extrudeAlongPath2(const PyDbRegion& region, const PyDbCurve& path, double taperAngle)
{
    return impObj()->extrudeAlongPath(region.impObj(), path.impObj(), taperAngle);
}

Acad::ErrorStatus PyDb3dSolid::createRevolvedSolid1(PyDbEntity& pRevEnt, const AcGePoint3d& axisPnt, const AcGeVector3d& axisDir, double revAngle, double startAngle, PyDbRevolveOptions& revolveOptions)
{
    return impObj()->createRevolvedSolid(pRevEnt.impObj(), axisPnt, axisDir, revAngle, startAngle, *revolveOptions.impObj());
}

Acad::ErrorStatus PyDb3dSolid::createRevolvedSolid2(PyDbEntity& pRevEnt, const PyDbSubentId& faceSubentId, const AcGePoint3d& axisPnt, const AcGeVector3d& axisDir, double revAngle, double startAngle, PyDbRevolveOptions& revolveOptions)
{
    return impObj()->createRevolvedSolid(pRevEnt.impObj(), *faceSubentId.impObj(), axisPnt, axisDir, revAngle, startAngle, *revolveOptions.impObj());
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
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
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
    : PyDbEntity(nullptr, false)
{
    AcDbRegion* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbRegion>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
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
#ifdef ARXAPP
    AcArray<AcDbEntity*> acCurveSegments;
    auto vec = py_list_to_std_vector<PyDbEntity>(curveSegments);
    for (auto& item : vec)
        acCurveSegments.append(item.impObj());
    AcArray<AcDbRegion*> regions;
    if (auto es = AcDbRegion::createFromCurves(acCurveSegments, regions); es != eOk)
        throw PyAcadErrorStatus(es);
    for (auto item : regions)
        pyRegions.append(PyDbRegion(item, true));
#else
    AcDbVoidPtrArray acCurveSegments;
    auto vec = py_list_to_std_vector<PyDbEntity>(curveSegments);
    for (auto& item : vec)
        acCurveSegments.append(item.impObj());
    AcDbVoidPtrArray regions;
    if (auto es = AcDbRegion::createFromCurves(acCurveSegments, regions); es != eOk)
        throw PyAcadErrorStatus(es);
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
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbRegion*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyDbBody
void makeAcDbBodyWrapper()
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
    : PyDbEntity(nullptr, false)
{
    AcDbBody* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbBody>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
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
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    PyAutoLockGIL lock;
    bool closed = false;
    bool planar = false;
    bool endPointsOnAxis = false;
    if (auto es = impObj()->checkRevolveCurve(ent.impObj(), axisPnt, axisDir, closed, endPointsOnAxis, planar, displayErrorMessages); es != eOk)
        throw PyAcadErrorStatus(es);
    return boost::python::make_tuple(closed, endPointsOnAxis, planar);
#endif
}

AcDbRevolveOptions* PyDbRevolveOptions::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
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

Acad::ErrorStatus PyDbSweepOptions::setSweepEntityTransform2(boost::python::list& sweepEntities)
{
    return setSweepEntityTransform3(sweepEntities, false);
}

Acad::ErrorStatus PyDbSweepOptions::setSweepEntityTransform3(boost::python::list& sweepEntities, bool displayErrorMessages)
{
    AcArray<AcDbEntity*> _sweepEntities;
    auto vec = py_list_to_std_vector<PyDbEntity>(sweepEntities);
    for (auto& item : vec)
        _sweepEntities.append(item.impObj());
    return impObj()->setSweepEntityTransform(_sweepEntities, displayErrorMessages);
}

bool PyDbSweepOptions::getPathEntityTransform(AcGeMatrix3d& mat)
{
    return impObj()->getPathEntityTransform(mat);
}

void PyDbSweepOptions::setPathEntityTransform1(AcGeMatrix3d& mat)
{
    return impObj()->setPathEntityTransform(mat);
}

Acad::ErrorStatus PyDbSweepOptions::setPathEntityTransform2(PyDbEntity& pPathEnt)
{
    return impObj()->setPathEntityTransform(pPathEnt.impObj());
}

Acad::ErrorStatus PyDbSweepOptions::setPathEntityTransform3(PyDbEntity& pPathEnt, bool displayErrorMessages)
{
    return impObj()->setPathEntityTransform(pPathEnt.impObj(), displayErrorMessages);
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
    double approxArcLen =0;
    if (auto es = impObj()->checkSweepCurve(pSweepEnt.impObj(), planarity, pnt, vec, closed, approxArcLen, displayErrorMessages); es != eOk)
        throw PyAcadErrorStatus(es);
    return boost::python::make_tuple(planarity, pnt, vec, closed, approxArcLen);
}

Acad::ErrorStatus PyDbSweepOptions::checkPathCurve1(PyDbEntity& pPathEnt)
{
    return impObj()->checkPathCurve(pPathEnt.impObj());
}

Acad::ErrorStatus PyDbSweepOptions::checkPathCurve2(PyDbEntity& pPathEnt, bool displayErrorMessages)
{
    return impObj()->checkPathCurve(pPathEnt.impObj(), displayErrorMessages);
}

AcDbSweepOptions* PyDbSweepOptions::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbSweepOptions*>(m_pyImp.get());
}
