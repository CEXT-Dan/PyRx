#include "stdafx.h"
#include "PyBrEntity.h"

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
