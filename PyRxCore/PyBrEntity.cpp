#include "stdafx.h"
#include "PyBrEntity.h"
#include "PyGeBoundBlock3d.h"
#include "PyGeLinearEnt3d.h"
#include "PyDb3dSolid.h"

using namespace boost::python;
//-----------------------------------------------------------------------------------------
// PyBrHit
void makePyBrHitWrapper()
{
    PyDocString DS("Hit");
    class_<PyBrHit, bases<PyRxObject>>("Hit")
        .def(init<>())
        .def("isEqualTo", &PyBrHit::isEqualTo, DS.ARGS({ "otherObject: PyRx.RxObject" }))
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

void PyBrHit::setValidationLevel(const AcBr::ValidationLevel& validationLevel)
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

void PyBrEntity::setSubentPath(PyDbFullSubentPath& subpath)
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

boost::python::tuple PyBrEntity::getPointContainment(const AcGePoint3d& point)
{
    AcGe::PointContainment containment;
    AcBrEntity* container = nullptr;
    PyThrowBadBr(impObj()->getPointContainment(point, containment, container));
    PyAutoLockGIL lock;
    return boost::python::make_tuple(PyBrEntity{ container , true }, containment);
}

boost::python::list PyBrEntity::getLineContainment(const PyGeLinearEnt3d& line, const Adesk::UInt32 numHitsWanted)
{
    Adesk::UInt32 numHitsFound = 0;
    AcBrHit* hits = nullptr;
    PyThrowBadBr(impObj()->getLineContainment(*line.impObj(), numHitsWanted, numHitsFound, hits));
    PyAutoLockGIL lock;
    boost::python::list pylist;
    if (hits == nullptr)
        PyThrowBadEs(eNullPtr);
    for (size_t idx = 0; idx < numHitsFound; idx++)
        pylist.append(PyBrHit(hits[idx]));
    return pylist;
}

PyBrBrep PyBrEntity::getBrep()
{
    AcBrBrep br;
    PyThrowBadBr(impObj()->getBrep(br));
    return PyBrBrep{ br };
}

void PyBrEntity::setValidationLevel(const AcBr::ValidationLevel level)
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

boost::python::tuple PyBrEntity::getMassProps1()
{
    AcBrMassProps props;
    PyThrowBadBr(impObj()->getMassProps(props));
    PyAutoLockGIL lock;
    return boost::python::make_tuple(props, boost::python::object());
}

boost::python::tuple PyBrEntity::getMassProps2(double density, double tolRequired)
{
    double tolAchieved = 0.0;
    AcBrMassProps props;
    PyThrowBadBr(impObj()->getMassProps(props, density, tolRequired));
    PyAutoLockGIL lock;
    return boost::python::make_tuple(props, tolAchieved);
}

boost::python::tuple PyBrEntity::getVolume1()
{
    double volume = 0.0;
    PyThrowBadBr(impObj()->getVolume(volume));
    PyAutoLockGIL lock;
    return boost::python::make_tuple(volume, boost::python::object());
}

boost::python::tuple PyBrEntity::getVolume2(double density, double tolRequired)
{
    double volume = 0.0;
    double tolAchieved = 0.0;
    PyThrowBadBr(impObj()->getVolume(volume, tolAchieved));
    PyAutoLockGIL lock;
    return boost::python::make_tuple(volume, tolAchieved);
}

boost::python::tuple PyBrEntity::getSurfaceArea1()
{
    double area = 0.0;
    PyThrowBadBr(impObj()->getSurfaceArea(area));
    PyAutoLockGIL lock;
    return boost::python::make_tuple(area, boost::python::object());
}

boost::python::tuple PyBrEntity::getSurfaceArea2(double density, double tolRequired)
{
    double area = 0.0;
    double tolAchieved = 0.0;
    PyThrowBadBr(impObj()->getVolume(area, tolAchieved));
    PyAutoLockGIL lock;
    return boost::python::make_tuple(area, tolAchieved);
}

boost::python::tuple PyBrEntity::getPerimeterLength1()
{
    double perimeter = 0.0;
    PyThrowBadBr(impObj()->getPerimeterLength(perimeter));
    PyAutoLockGIL lock;
    return boost::python::make_tuple(perimeter, boost::python::object());
}

boost::python::tuple PyBrEntity::getPerimeterLength2(double density, double tolRequired)
{
    double perimeter = 0.0;
    double tolAchieved = 0.0;
    PyThrowBadBr(impObj()->getPerimeterLength(perimeter, tolAchieved));
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
        .def("className", &PyBrBrep::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrBrep::desc, DS.SARGS(15560)).staticmethod("desc")
        ;
}

PyBrBrep::PyBrBrep()
    :PyBrBrep(new AcBrBrep(), true)
{
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

AcBr::Relation PyBrBrep::getPointRelationToBrep(const AcGePoint3d& point) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    AcBr::Relation relation;
    PyThrowBadBr(impObj()->getPointRelationToBrep(point, relation));
    return relation;
#endif
}

AcBr::Relation PyBrBrep::getCurveRelationToBrep(const AcGeCurve3d& curve) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    AcBr::Relation relation;
    PyThrowBadBr(impObj()->getCurveRelationToBrep(curve, relation));
    return relation;
#endif
}

void PyBrBrep::set(const PyDbEntity& entity)
{
    PyThrowBadBr(impObj()->set(*entity.impObj()));
}

PyDb3dSolid PyBrBrep::getSolid()
{
    AcDb3dSolid* pSolid = nullptr;
    PyThrowBadBr(impObj()->get(pSolid));
    return PyDb3dSolid{ pSolid, true };
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
        .def(init<>())
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
        .def(init<>())
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
    class_<PyBrFace, bases<PyBrEntity>>("Loop")
        .def(init<>())
        .def("className", &PyBrFace::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyBrFace::desc, DS.SARGS(15560)).staticmethod("desc")
        ;
}

PyBrLoop::PyBrLoop()
    : PyBrLoop(new AcBrLoop(), true)
{
}

PyBrLoop::PyBrLoop(const AcBrLoop& src)
    : PyBrLoop(new AcBrLoop(src),true)
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
        .def(init<>())
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
        .def(init<>())
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
