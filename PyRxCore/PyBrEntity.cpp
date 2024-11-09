#include "stdafx.h"
#include "PyBrEntity.h"
#include "PyGeBoundBlock3d.h"
#include "PyGeLinearEnt3d.h"

void makePyBrEntityWrapper()
{

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
    PyAutoLockGIL lock;
    AcGe::PointContainment containment;
    AcBrEntity* container = nullptr;
    PyThrowBadBr(impObj()->getPointContainment(point, containment, container));
    return boost::python::make_tuple(containment, PyBrEntity{ container , true });
}

boost::python::tuple PyBrEntity::getLineContainment(const PyGeLinearEnt3d& line, const Adesk::UInt32 numHitsWanted)
{
    PyAutoLockGIL lock;
    Adesk::UInt32 numHitsFound = 0;
    AcBrHit* hits = nullptr;
    PyThrowBadBr(impObj()->getLineContainment(*line.impObj(), numHitsWanted, numHitsFound, hits));

    //TODO:
    PyThrowBadEs(eNotImplementedYet); //AcBrHitArray not PyBrEntity
    return boost::python::make_tuple(numHitsFound, PyBrEntity{ hits , true });
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

PyRxClass PyBrEntity::desc()
{
    return PyRxClass(AcRxClass::desc(), false);
}

std::string  PyBrEntity::className()
{
    return std::string{ "AcRxClass" };
}

AcBrEntity* PyBrEntity::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcBrEntity*>(m_pyImp.get());
}
