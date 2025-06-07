#include "stdafx.h"
#include "PyBrEntity.h"
#include "PyGeBoundBlock3d.h"
#include "PyGeCurve3d.h"
#include "PyGeLinearEnt3d.h"
#include "PyDb3dSolid.h"
#include "PyDbSurface.h"
#include "PyGeSurface.h"

using namespace boost::python;
//-----------------------------------------------------------------------------------------
// PyBrHit
void makePyBrHitWrapper()
{
    PyDocString DS("Hit");
    class_<PyBrHit, bases<PyRxObject>>("Hit")
        .def(init<>(DS.ARGS()))
        .def("isEqualTo", &PyBrHit::isEqualTo, DS.ARGS({ "otherObject: PyRx.RxObject" }))
        .def("isNull", &PyBrHit::isNull, DS.ARGS())
        .def("getEntityHit", &PyBrHit::getEntityHit, DS.ARGS())
        .def("getEntityEntered", &PyBrHit::getEntityEntered, DS.ARGS())
        .def("getEntityAssociated", &PyBrHit::getEntityAssociated, DS.ARGS())
        .def("getPoint", &PyBrHit::getPoint, DS.ARGS())
        .def("getValidationLevel", &PyBrHit::getValidationLevel, DS.ARGS())
        .def("setValidationLevel", &PyBrHit::setValidationLevel, DS.ARGS({ "val: PyBr.ValidationLevel" }))
        .def("brepChanged", &PyBrHit::brepChanged, DS.ARGS())
        .def("className", &PyBrHit::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrHit::desc, DS.SARGS(15560)).staticmethod("desc")
        ;
}

PyBrHit::PyBrHit()
    : PyBrHit(new AcBrHit(), true)
{
}

PyBrHit::PyBrHit(const AcBrHit src)
    : PyBrHit(new AcBrHit(src), true)
{
}

PyBrHit::PyBrHit(const AcRxObject* ptr)
    :PyRxObject(ptr)
{
}

PyBrHit::PyBrHit(AcRxObject* ptr, bool autoDelete)
    :PyRxObject(ptr, autoDelete, false)
{
}

Adesk::Boolean PyBrHit::isEqualTo(const PyRxObject& other) const
{
    return impObj()->isEqualTo(other.impObj());
}

Adesk::Boolean PyBrHit::isNull() const
{
    return impObj()->isNull();
}

PyBrEntity PyBrHit::getEntityHit() const
{
    AcBrEntity* hit = nullptr;
    PyThrowBadBr(impObj()->getEntityHit(hit));
    return PyBrEntity(hit, true);
}

PyBrEntity PyBrHit::getEntityEntered() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    AcBrEntity* hit = nullptr;
    PyThrowBadBr(impObj()->getEntityEntered(hit));
    return PyBrEntity(hit, true);
#endif
}

PyBrEntity PyBrHit::getEntityAssociated() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    AcBrEntity* hit = nullptr;
    PyThrowBadBr(impObj()->getEntityAssociated(hit));
    return PyBrEntity(hit, true);
#endif
}

AcGePoint3d PyBrHit::getPoint() const
{
    AcGePoint3d pt;
    PyThrowBadBr(impObj()->getPoint(pt));
    return pt;
}

void PyBrHit::setValidationLevel(const AcBr::ValidationLevel& validationLevel) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    PyThrowBadBr(impObj()->setValidationLevel(validationLevel));
#endif
}

AcBr::ValidationLevel PyBrHit::getValidationLevel() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    AcBr::ValidationLevel val;
    PyThrowBadBr(impObj()->getValidationLevel(val));
    return val;
#endif
}

Adesk::Boolean PyBrHit::brepChanged() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->brepChanged();
#endif
}

PyRxClass PyBrHit::desc()
{
    return PyRxClass(AcBrHit::desc(), false);
}

std::string  PyBrHit::className()
{
    return std::string{ "AcBrHit" };
}

AcBrHit* PyBrHit::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcBrHit*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
// PyBrEntity
void makePyBrEntityWrapper()
{
    PyDocString DS("Entity");
    class_<PyBrEntity, bases<PyRxObject>>("Entity", no_init)
        .def("isEqualTo", &PyBrEntity::isEqualTo, DS.ARGS({ "otherObject: PyRx.RxObject" }))
        .def("isNull", &PyBrEntity::isNull, DS.ARGS())
        .def("getSubentPath", &PyBrEntity::getSubentPath, DS.ARGS())
        .def("setSubentPath", &PyBrEntity::setSubentPath, DS.ARGS({ "val: PyDb.FullSubentPath" }))
        .def("checkEntity", &PyBrEntity::checkEntity, DS.ARGS())
        .def("getBoundBlock", &PyBrEntity::getBoundBlock, DS.ARGS())
        .def("getPointContainment", &PyBrEntity::getPointContainment, DS.ARGS({ "pt: PyGe.Point3d" }))
        .def("getLineContainment", &PyBrEntity::getLineContainment, DS.ARGS({ "line: PyGe.LinearEnt3d", "numHitsWanted: int" }))
        .def("getBrep", &PyBrEntity::getBrep, DS.ARGS())
        .def("getValidationLevel", &PyBrEntity::getValidationLevel, DS.ARGS())
        .def("setValidationLevel", &PyBrEntity::setValidationLevel, DS.ARGS({ "val: PyBr.ValidationLevel" }))
        .def("brepChanged", &PyBrEntity::brepChanged, DS.ARGS())
        .def("getMassProps", &PyBrEntity::getMassProps1)
        .def("getMassProps", &PyBrEntity::getMassProps2, DS.ARGS({ "density: float = ...","tolRequired: float = ..." }))
        .def("getVolume", &PyBrEntity::getVolume1)
        .def("getVolume", &PyBrEntity::getVolume2, DS.ARGS({ "tolRequired: float = ..." }))
        .def("getSurfaceArea", &PyBrEntity::getSurfaceArea1)
        .def("getSurfaceArea", &PyBrEntity::getSurfaceArea2, DS.ARGS({ "tolRequired: float = ..." }))
        .def("getPerimeterLength", &PyBrEntity::getPerimeterLength1)
        .def("getPerimeterLength", &PyBrEntity::getPerimeterLength2, DS.ARGS({ "tolRequired: float = ..." }))
        .def("className", &PyBrEntity::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrEntity::desc, DS.SARGS(15560)).staticmethod("desc")
        ;
}

PyBrEntity::PyBrEntity(const AcRxObject* ptr)
    :PyRxObject(ptr)
{
}

PyBrEntity::PyBrEntity(AcRxObject* ptr, bool autoDelete)
    :PyRxObject(ptr, autoDelete, false)
{
}

Adesk::Boolean PyBrEntity::isEqualTo(const PyRxObject& other) const
{
    return impObj()->isEqualTo(other.impObj());
}

Adesk::Boolean PyBrEntity::isNull() const
{
    return impObj()->isNull();
}

PyDbFullSubentPath PyBrEntity::getSubentPath() const
{
    AcDbFullSubentPath path;
    PyThrowBadBr(impObj()->getSubentPath(path));
    return PyDbFullSubentPath{ path };
}

void PyBrEntity::setSubentPath(PyDbFullSubentPath& subpath) const
{
    PyThrowBadBr(impObj()->setSubentPath(subpath.pyImp));
}

Adesk::Boolean PyBrEntity::checkEntity() const
{
    return impObj()->checkEntity();
}

PyGeBoundBlock3d PyBrEntity::getBoundBlock() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    AcGeBoundBlock3d block;
    PyThrowBadBr(impObj()->getBoundBlock(block));
    return PyGeBoundBlock3d{ block };
#endif;
}

boost::python::tuple PyBrEntity::getPointContainment(const AcGePoint3d& point) const
{
    AcGe::PointContainment containment;
    AcBrEntity* container = nullptr;
    PyThrowBadBr(impObj()->getPointContainment(point, containment, container));
    PyAutoLockGIL lock;
    return boost::python::make_tuple(PyBrEntity{ container , true }, containment);
}

boost::python::list PyBrEntity::getLineContainment(const PyGeLinearEnt3d& line, const Adesk::UInt32 numHitsWanted) const
{
    Adesk::UInt32 numHitsFound = 0;
    AcBrHit* hits = nullptr;
    PyThrowBadBr(impObj()->getLineContainment(*line.impObj(), numHitsWanted, numHitsFound, hits));
    PyAutoLockGIL lock;
    boost::python::list pylist;
    if (hits == nullptr)
        return pylist;
    for (size_t idx = 0; idx < numHitsFound; idx++)
        pylist.append(PyBrHit(hits[idx]));
    return pylist;
}

PyBrBrep PyBrEntity::getBrep() const
{
    AcBrBrep br;
    PyThrowBadBr(impObj()->getBrep(br));
    return PyBrBrep{ br };
}

void PyBrEntity::setValidationLevel(const AcBr::ValidationLevel level) const
{
    PyThrowBadBr(impObj()->setValidationLevel(level));
}

AcBr::ValidationLevel PyBrEntity::getValidationLevel() const
{
    AcBr::ValidationLevel level;
    PyThrowBadBr(impObj()->getValidationLevel(level));
    return level;
}

Adesk::Boolean PyBrEntity::brepChanged() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->brepChanged();
#endif
}

boost::python::tuple PyBrEntity::getMassProps1() const
{
    AcBrMassProps props;
    PyThrowBadBr(impObj()->getMassProps(props));
    PyAutoLockGIL lock;
    return boost::python::make_tuple(props, boost::python::object());
}

boost::python::tuple PyBrEntity::getMassProps2(double density, double tolRequired) const
{
    double tolAchieved = 0.0;
    AcBrMassProps props;
    PyThrowBadBr(impObj()->getMassProps(props, density, tolRequired, tolAchieved));
    PyAutoLockGIL lock;
    return boost::python::make_tuple(props, tolAchieved);
}

boost::python::tuple PyBrEntity::getVolume1() const
{
    double volume = 0.0;
    PyThrowBadBr(impObj()->getVolume(volume));
    PyAutoLockGIL lock;
    return boost::python::make_tuple(volume, boost::python::object());
}

boost::python::tuple PyBrEntity::getVolume2(double tolRequired) const
{
    double volume = 0.0;
    double tolAchieved = 0.0;
    PyThrowBadBr(impObj()->getVolume(volume, tolRequired, tolAchieved));
    PyAutoLockGIL lock;
    return boost::python::make_tuple(volume, tolAchieved);
}

boost::python::tuple PyBrEntity::getSurfaceArea1() const
{
    double area = 0.0;
    PyThrowBadBr(impObj()->getSurfaceArea(area));
    PyAutoLockGIL lock;
    return boost::python::make_tuple(area, boost::python::object());
}

boost::python::tuple PyBrEntity::getSurfaceArea2(double tolRequired) const
{
    double area = 0.0;
    double tolAchieved = 0.0;
    PyThrowBadBr(impObj()->getVolume(area, tolRequired, tolAchieved));
    PyAutoLockGIL lock;
    return boost::python::make_tuple(area, tolAchieved);
}

boost::python::tuple PyBrEntity::getPerimeterLength1() const
{
    double perimeter = 0.0;
    PyThrowBadBr(impObj()->getPerimeterLength(perimeter));
    PyAutoLockGIL lock;
    return boost::python::make_tuple(perimeter, boost::python::object());
}

boost::python::tuple PyBrEntity::getPerimeterLength2(double tolRequired) const
{
    double perimeter = 0.0;
    double tolAchieved = 0.0;
    PyThrowBadBr(impObj()->getPerimeterLength(perimeter, tolRequired, tolAchieved));
    PyAutoLockGIL lock;
    return boost::python::make_tuple(perimeter, tolAchieved);
}

PyRxClass PyBrEntity::desc()
{
    return PyRxClass(AcBrEntity::desc(), false);
}

std::string  PyBrEntity::className()
{
    return std::string{ "AcBrEntity" };
}

AcBrEntity* PyBrEntity::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcBrEntity*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
// PyBrBrep
void makePyBrBrepWrapper()
{
    PyDocString DS("Brep");
    class_<PyBrBrep, bases<PyBrEntity>>("Brep")
        .def(init<>())
        .def(init<const PyDbEntity&>(DS.ARGS({ "entity: PyDb.Entity = ..." })))
        .def("set", &PyBrBrep::set, DS.ARGS({ "entity: PyDb.Entity" }))
        .def("getSolid", &PyBrBrep::getSolid, DS.ARGS())
        .def("getSurface", &PyBrBrep::getSurface, DS.ARGS())
        .def("className", &PyBrBrep::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrBrep::desc, DS.SARGS(15560)).staticmethod("desc")
        ;
}

PyBrBrep::PyBrBrep()
    :PyBrBrep(new AcBrBrep(), true)
{
}

PyBrBrep::PyBrBrep(const PyDbEntity& ent)
    :PyBrBrep(new AcBrBrep(), true)
{
    set(ent);
}

PyBrBrep::PyBrBrep(const AcBrBrep& src)
    :PyBrBrep(new AcBrBrep(src), true)
{
}

PyBrBrep::PyBrBrep(const AcRxObject* ptr)
    : PyBrEntity(ptr)
{
}

PyBrBrep::PyBrBrep(AcRxObject* ptr, bool autoDelete)
    : PyBrEntity(ptr, autoDelete)
{
}

void PyBrBrep::set(const PyDbEntity& entity) const
{
    PyThrowBadBr(impObj()->set(*entity.impObj()));
}

PyDb3dSolid PyBrBrep::getSolid() const
{
    AcDb3dSolid* pSolid = nullptr;
    PyThrowBadBr(impObj()->get(pSolid));
    return PyDb3dSolid{ pSolid, true };
}

PyDbSurface PyBrBrep::getSurface() const
{
    AcDbSurface* pSurface = nullptr;
    PyThrowBadBr(impObj()->get(pSurface));
    return PyDbSurface{ pSurface, true };
}

PyRxClass PyBrBrep::desc()
{
    return PyRxClass(AcBrBrep::desc(), false);
}

std::string PyBrBrep::className()
{
    return std::string{ "AcBrBrep" };
}

AcBrBrep* PyBrBrep::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcBrBrep*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
// PyBrComplex
void makePyBrComplexWrapper()
{
    PyDocString DS("Complex");
    class_<PyBrComplex, bases<PyBrEntity>>("Complex")
        .def(init<>(DS.ARGS()))
        .def("className", &PyBrComplex::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrComplex::desc, DS.SARGS(15560)).staticmethod("desc")
        ;
}

PyBrComplex::PyBrComplex()
    : PyBrEntity(new AcBrComplex(), true)
{
}

PyBrComplex::PyBrComplex(const AcBrComplex& src)
    : PyBrEntity(new AcBrComplex(src), true)
{
}

PyBrComplex::PyBrComplex(const AcRxObject* ptr)
    : PyBrEntity(ptr)
{
}

PyBrComplex::PyBrComplex(AcRxObject* ptr, bool autoDelete)
    : PyBrEntity(ptr, autoDelete)
{
}

PyRxClass PyBrComplex::desc()
{
    return PyRxClass(AcBrComplex::desc(), false);
}

std::string PyBrComplex::className()
{
    return std::string{ "AcBrComplex" };
}

AcBrComplex* PyBrComplex::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcBrComplex*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
// PyBrEdge
void makePyBrEdgeWrapper()
{
    PyDocString DS("Edge");
    class_<PyBrEdge, bases<PyBrEntity>>("Edge")
        .def(init<>())
        .def("getCurveType", &PyBrEdge::getCurveType, DS.ARGS())
        .def("getCurve", &PyBrEdge::getCurve, DS.ARGS())
        .def("getOrientToCurve", &PyBrEdge::getOrientToCurve, DS.ARGS())
        .def("getVertex1", &PyBrEdge::getVertex1, DS.ARGS())
        .def("getVertex2", &PyBrEdge::getVertex2, DS.ARGS())
        .def("className", &PyBrEdge::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrEdge::desc, DS.SARGS(15560)).staticmethod("desc")
        ;
}

PyBrEdge::PyBrEdge()
    : PyBrEdge(new AcBrEdge(), true)
{
}

PyBrEdge::PyBrEdge(const AcBrEdge& srx)
    : PyBrEdge(new AcBrEdge(srx), true)
{
}

PyBrEdge::PyBrEdge(const AcRxObject* ptr)
    : PyBrEntity(ptr)
{
}

PyBrEdge::PyBrEdge(AcRxObject* ptr, bool autoDelete)
    : PyBrEntity(ptr, autoDelete)
{
}

AcGe::EntityId PyBrEdge::getCurveType() const
{
    AcGe::EntityId type = AcGe::EntityId::kCurve3d;
    PyThrowBadBr(impObj()->getCurveType(type));
    return type;
}

PyGeExternalCurve3d PyBrEdge::getCurve() const
{
    AcGeCurve3d* val = nullptr;
    PyThrowBadBr(impObj()->getCurve(val));
    if (val != nullptr && val->type() != AcGe::kExternalCurve3d)
        PyThrowBadEs(Acad::eNotThatKindOfClass);
    return PyGeExternalCurve3d(static_cast<AcGeExternalCurve3d*>(val));
}

Adesk::Boolean PyBrEdge::getOrientToCurve() const
{
    Adesk::Boolean bOrientToCurve = Adesk::kFalse;
    PyThrowBadBr(impObj()->getOrientToCurve(bOrientToCurve));
    return bOrientToCurve;
}

PyBrVertex PyBrEdge::getVertex1() const
{
    AcBrVertex vertex;
    PyThrowBadBr(impObj()->getVertex1(vertex));
    return PyBrVertex(vertex);
}

PyBrVertex PyBrEdge::getVertex2() const
{
    AcBrVertex vertex;
    PyThrowBadBr(impObj()->getVertex2(vertex));
    return PyBrVertex(vertex);
}

PyRxClass PyBrEdge::desc()
{
    return PyRxClass(AcBrEdge::desc(), false);
}

std::string PyBrEdge::className()
{
    return std::string{ "AcBrEdge" };
}

AcBrEdge* PyBrEdge::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcBrEdge*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
// PyBrFace
void makePyBrFaceWrapper()
{
    PyDocString DS("Face");
    class_<PyBrFace, bases<PyBrEntity>>("Face")
        .def(init<>(DS.ARGS()))
        .def("getSurfaceType", &PyBrFace::getSurfaceType, DS.ARGS())
        .def("getSurface", &PyBrFace::getSurface, DS.ARGS())
        .def("getOrientToSurface", &PyBrFace::getOrientToSurface, DS.ARGS())
        .def("getArea", &PyBrFace::getArea, DS.ARGS())
        .def("getAreaWithTol", &PyBrFace::getAreaWithTol, DS.ARGS({ "tolRequired: float" }))
        .def("getShell", &PyBrFace::getShell, DS.ARGS())
        .def("className", &PyBrFace::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrFace::desc, DS.SARGS(15560)).staticmethod("desc")
        ;
}

PyBrFace::PyBrFace()
    : PyBrFace(new AcBrFace(), true)
{
}

PyBrFace::PyBrFace(const AcBrFace& src)
    : PyBrFace(new AcBrFace(src), true)
{
}

PyBrFace::PyBrFace(const AcRxObject* ptr)
    : PyBrEntity(ptr)
{
}

PyBrFace::PyBrFace(AcRxObject* ptr, bool autoDelete)
    : PyBrEntity(ptr, autoDelete)
{
}

AcGe::EntityId PyBrFace::getSurfaceType() const
{
    AcGe::EntityId id = AcGe::EntityId::kSurface;
    PyThrowBadBr(impObj()->getSurfaceType(id));
    return id;
}

PyGeSurface PyBrFace::getSurface() const
{
    AcGeSurface* surface = nullptr;
    PyThrowBadBr(impObj()->getSurface(surface));
    return PyGeSurface(surface);
}

Adesk::Boolean PyBrFace::getOrientToSurface() const
{
    Adesk::Boolean bOrientToSurface = Adesk::kFalse;
    PyThrowBadBr(impObj()->getOrientToSurface(bOrientToSurface));
    return bOrientToSurface;
}

double PyBrFace::getArea() const
{
    double area = 0.0;
    PyThrowBadBr(impObj()->getArea(area));
    PyAutoLockGIL lock;
    return area;
}

boost::python::tuple PyBrFace::getAreaWithTol(double tolRequired) const
{
    double area = 0.0;
    double tolAchieved = 0.0;
#if !defined(_ARXTARGET)
    throw PyNotimplementedByHost();
#else
    PyThrowBadBr(impObj()->getArea(area, &tolRequired, &tolAchieved));
#endif
    PyAutoLockGIL lock;
    return boost::python::make_tuple(area, tolAchieved);
}

PyBrShell PyBrFace::getShell() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    AcBrShell shell;
    PyThrowBadBr(impObj()->getShell(shell));
    return PyBrShell(shell);
#endif
}

PyRxClass PyBrFace::desc()
{
    return PyRxClass(AcBrFace::desc(), false);
}

std::string PyBrFace::className()
{
    return std::string{ "AcBrFace" };
}

AcBrFace* PyBrFace::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcBrFace*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
// PyBrLoop
void makePyBrLoopWrapper()
{
    PyDocString DS("Loop");
    class_<PyBrLoop, bases<PyBrEntity>>("Loop")
        .def(init<>(DS.ARGS()))
        .def("getFace", &PyBrLoop::getFace, DS.ARGS())
        .def("getType", &PyBrLoop::getType, DS.ARGS())
        .def("className", &PyBrLoop::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrLoop::desc, DS.SARGS(15560)).staticmethod("desc")
        ;
}

PyBrLoop::PyBrLoop()
    : PyBrLoop(new AcBrLoop(), true)
{
}

PyBrLoop::PyBrLoop(const AcBrLoop& src)
    : PyBrLoop(new AcBrLoop(src), true)
{
}

PyBrLoop::PyBrLoop(const AcRxObject* ptr)
    : PyBrEntity(ptr)
{
}

PyBrLoop::PyBrLoop(AcRxObject* ptr, bool autoDelete)
    : PyBrEntity(ptr, autoDelete)
{
}

PyBrFace PyBrLoop::getFace() const
{
    AcBrFace face;
    PyThrowBadBr(impObj()->getFace(face));
    return PyBrFace(face);
}

AcBr::LoopType PyBrLoop::getType() const
{
    AcBr::LoopType lt;
    PyThrowBadBr(impObj()->getType(lt));
    return lt;
}

PyRxClass PyBrLoop::desc()
{
    return PyRxClass(AcBrLoop::desc(), false);
}

std::string PyBrLoop::className()
{
    return std::string{ "AcBrLoop" };
}

AcBrLoop* PyBrLoop::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcBrLoop*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
// PyBrShell
void makePyBrShellWrapper()
{
    PyDocString DS("Shell");
    class_<PyBrShell, bases<PyBrEntity>>("Shell")
        .def(init<>(DS.ARGS()))
        .def("getComplex", &PyBrShell::getComplex, DS.ARGS())
        .def("getType", &PyBrShell::getType, DS.ARGS())
        .def("className", &PyBrShell::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrShell::desc, DS.SARGS(15560)).staticmethod("desc")
        ;
}

PyBrShell::PyBrShell()
    : PyBrShell(new AcBrShell(), true)
{
}

PyBrShell::PyBrShell(const AcBrShell& src)
    : PyBrShell(new AcBrShell(src), true)
{
}

PyBrShell::PyBrShell(const AcRxObject* ptr)
    : PyBrEntity(ptr)
{
}

PyBrShell::PyBrShell(AcRxObject* ptr, bool autoDelete)
    : PyBrEntity(ptr, autoDelete)
{
}

PyBrComplex PyBrShell::getComplex() const
{
    AcBrComplex complex;
    PyThrowBadBr(impObj()->getComplex(complex));
    return PyBrComplex(complex);
}

AcBr::ShellType PyBrShell::getType() const
{
    AcBr::ShellType shellType;
    PyThrowBadBr(impObj()->getType(shellType));
    return shellType;
}

PyRxClass PyBrShell::desc()
{
    return PyRxClass(AcBrShell::desc(), false);
}

std::string PyBrShell::className()
{
    return std::string{ "AcBrShell" };
}

AcBrShell* PyBrShell::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcBrShell*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
// PyBrVertex
void makePyBrVertexWrapper()
{
    PyDocString DS("Vertex");
    class_<PyBrVertex, bases<PyBrEntity>>("Vertex")
        .def(init<>(DS.ARGS()))
        .def("getPoint", &PyBrVertex::getPoint, DS.ARGS())
        .def("className", &PyBrVertex::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrVertex::desc, DS.SARGS(15560)).staticmethod("desc")
        ;
}

PyBrVertex::PyBrVertex()
    : PyBrVertex(new AcBrVertex(), true)
{
}

PyBrVertex::PyBrVertex(const AcBrVertex& src)
    : PyBrVertex(new AcBrVertex(src), true)
{
}

PyBrVertex::PyBrVertex(const AcRxObject* ptr)
    : PyBrEntity(ptr)
{
}

PyBrVertex::PyBrVertex(AcRxObject* ptr, bool autoDelete)
    : PyBrEntity(ptr, autoDelete)
{
}

AcGePoint3d PyBrVertex::getPoint() const
{
    AcGePoint3d point;
    PyThrowBadBr(impObj()->getPoint(point));
    return point;
}

PyRxClass PyBrVertex::desc()
{
    return PyRxClass(AcBrVertex::desc(), false);
}

std::string PyBrVertex::className()
{
    return std::string{ "AcBrVertex" };
}

AcBrVertex* PyBrVertex::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcBrVertex*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
// PyBrMeshEntity
void makePyBrMeshEntityWrapper()
{
    PyDocString DS("MeshEntity");
    class_<PyBrMeshEntity, bases<PyRxObject>>("MeshEntity", no_init)
        .def("isEqualTo", &PyBrMeshEntity::isEqualTo, DS.ARGS({ "otherObject: PyRx.RxObject" }))
        .def("isNull", &PyBrMeshEntity::isNull, DS.ARGS())
        .def("getEntityAssociated", &PyBrMeshEntity::getEntityAssociated, DS.ARGS())
        .def("getValidationLevel", &PyBrMeshEntity::getValidationLevel, DS.ARGS())
        .def("setValidationLevel", &PyBrMeshEntity::setValidationLevel, DS.ARGS({ "val: PyBr.ValidationLevel" }))
        .def("brepChanged", &PyBrMeshEntity::brepChanged, DS.ARGS())
        .def("className", &PyBrMeshEntity::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrMeshEntity::desc, DS.SARGS(15560)).staticmethod("desc")
        ;
}

PyBrMeshEntity::PyBrMeshEntity(const AcRxObject* ptr)
    : PyRxObject(ptr)
{
}

PyBrMeshEntity::PyBrMeshEntity(AcRxObject* ptr, bool autoDelete)
    : PyRxObject(ptr, autoDelete, false)
{
}

Adesk::Boolean PyBrMeshEntity::isEqualTo(const PyRxObject& other) const
{
    return impObj()->isEqualTo(other.impObj());
}

Adesk::Boolean PyBrMeshEntity::isNull() const
{
    return impObj()->isNull();
}

PyBrEntity PyBrMeshEntity::getEntityAssociated() const
{
    AcBrEntity* hit = nullptr;
    PyThrowBadBr(impObj()->getEntityAssociated(hit));
    return PyBrEntity(hit, true);
}

void PyBrMeshEntity::setValidationLevel(const AcBr::ValidationLevel& validationLevel) const
{
    PyThrowBadBr(impObj()->setValidationLevel(validationLevel));
}

AcBr::ValidationLevel PyBrMeshEntity::getValidationLevel() const
{
    AcBr::ValidationLevel val;
    PyThrowBadBr(impObj()->getValidationLevel(val));
    return val;
}

Adesk::Boolean PyBrMeshEntity::brepChanged() const
{
    return impObj()->brepChanged();
}

PyRxClass PyBrMeshEntity::desc()
{
    return PyRxClass(AcBrMeshEntity::desc(), false);
}

std::string PyBrMeshEntity::className()
{
    return std::string{ "AcBrMeshEntity" };
}

AcBrMeshEntity* PyBrMeshEntity::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcBrMeshEntity*>(m_pyImp.get());
}


//-----------------------------------------------------------------------------------------
// PyBrElement
void makePyBrElementWrapper()
{
    PyDocString DS("Element");
    class_<PyBrElement, bases<PyBrMeshEntity>>("Element", no_init)
        .def("className", &PyBrElement::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrElement::desc, DS.SARGS(15560)).staticmethod("desc")
        ;
}

PyBrElement::PyBrElement(const AcRxObject* ptr)
    : PyBrMeshEntity(ptr)
{
}

PyBrElement::PyBrElement(AcRxObject* ptr, bool autoDelete)
    : PyBrMeshEntity(ptr, autoDelete)
{
}

PyRxClass PyBrElement::desc()
{
    return PyRxClass(AcBrElement::desc(), false);
}

std::string PyBrElement::className()
{
    return std::string{ "AcBrElement" };
}

AcBrElement* PyBrElement::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcBrElement*>(m_pyImp.get());
}


//-----------------------------------------------------------------------------------------
// PyBrElement2d
void makePyBrElement2dWrapper()
{
    PyDocString DS("Element2d");
    class_<PyBrElement2d, bases<PyBrElement>>("Element2d")
        .def(init<>(DS.ARGS()))
        .def("getNormal", &PyBrElement2d::getNormal, DS.ARGS())
        .def("className", &PyBrElement2d::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrElement2d::desc, DS.SARGS(15560)).staticmethod("desc")
        ;
}

PyBrElement2d::PyBrElement2d()
    : PyBrElement(new AcBrElement2d(), true)
{
}

PyBrElement2d::PyBrElement2d(const AcBrElement2d& src)
    : PyBrElement(new AcBrElement2d(src), true)
{
}

PyBrElement2d::PyBrElement2d(const AcRxObject* ptr)
    : PyBrElement(ptr)
{
}

PyBrElement2d::PyBrElement2d(AcRxObject* ptr, bool autoDelete)
    : PyBrElement(ptr, autoDelete)
{
}

AcGeVector3d PyBrElement2d::getNormal() const
{
    AcGeVector3d val;
    PyThrowBadBr(impObj()->getNormal(val));
    return val;
}

PyRxClass PyBrElement2d::desc()
{
    return PyRxClass(AcBrElement2d::desc(), false);
}

std::string PyBrElement2d::className()
{
    return std::string{ "AcBrElement2d" };
}

AcBrElement2d* PyBrElement2d::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcBrElement2d*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
// PyBrMesh
void makePyBrMeshWrapper()
{
    PyDocString DS("Mesh");
    class_<PyBrMesh, bases<PyBrMeshEntity>>("Mesh", no_init)
        .def("className", &PyBrMesh::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrMesh::desc, DS.SARGS(15560)).staticmethod("desc")
        ;
}

PyBrMesh::PyBrMesh(const AcRxObject* ptr)
    : PyBrMeshEntity(ptr)
{
}

PyBrMesh::PyBrMesh(AcRxObject* ptr, bool autoDelete)
    : PyBrMeshEntity(ptr, autoDelete)
{
}

PyRxClass PyBrMesh::desc()
{
    return PyRxClass(AcBrMesh::desc(), false);
}

std::string PyBrMesh::className()
{
    return std::string{ "AcBrMesh" };
}

AcBrMesh* PyBrMesh::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcBrMesh*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
// PyBrMesh2d
void makePyBrMesh2dWrapper()
{
    PyDocString DS("Mesh2d");
    class_<PyBrMesh2d, bases<PyBrMesh>>("Mesh2d")
        .def(init<>(DS.ARGS()))
        .def("className", &PyBrMesh2d::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrMesh2d::desc, DS.SARGS(15560)).staticmethod("desc")
        ;
}

PyBrMesh2d::PyBrMesh2d()
    : PyBrMesh2d(new AcBrMesh2d(), true)
{
}

PyBrMesh2d::PyBrMesh2d(const AcBrMesh2d& src)
    : PyBrMesh2d(new AcBrMesh2d(src), true)
{
}

PyBrMesh2d::PyBrMesh2d(const AcRxObject* ptr)
    : PyBrMesh(ptr)
{
}

PyBrMesh2d::PyBrMesh2d(AcRxObject* ptr, bool autoDelete)
    : PyBrMesh(ptr, autoDelete)
{
}

PyRxClass PyBrMesh2d::desc()
{
    return PyRxClass(AcBrMesh2d::desc(), false);
}

std::string PyBrMesh2d::className()
{
    return std::string{ "AcBrMesh2d" };
}

AcBrMesh2d* PyBrMesh2d::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcBrMesh2d*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
// PyBrNode
void makePyBrNodeWrapper()
{
    PyDocString DS("Node");
    class_<PyBrNode, bases<PyBrMeshEntity>>("Node")
        .def(init<>(DS.ARGS()))
        .def("getPoint", &PyBrNode::getPoint, DS.ARGS())
        .def("className", &PyBrNode::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrNode::desc, DS.SARGS(15560)).staticmethod("desc")
        ;
}

PyBrNode::PyBrNode()
    : PyBrNode(new AcBrNode(), true)
{
}

PyBrNode::PyBrNode(const AcBrNode& src)
    : PyBrNode(new AcBrNode(src), true)
{
}

PyBrNode::PyBrNode(const AcRxObject* ptr)
    : PyBrMeshEntity(ptr)
{
}

PyBrNode::PyBrNode(AcRxObject* ptr, bool autoDelete)
    : PyBrMeshEntity(ptr, autoDelete)
{
}

AcGePoint3d PyBrNode::getPoint() const
{
    AcGePoint3d point;
    PyThrowBadBr(impObj()->getPoint(point));
    return point;
}

PyRxClass PyBrNode::desc()
{
    return PyRxClass(AcBrNode::desc(), false);
}

std::string PyBrNode::className()
{
    return std::string{ "AcBrNode" };
}

AcBrNode* PyBrNode::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcBrNode*>(m_pyImp.get());
}