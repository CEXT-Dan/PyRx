#include "stdafx.h"
#include "PyGeEntity3d.h"
#include "PyGePlane.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------------
//PyGeEntity3d wrapper
void makePyGeEntity3dWrapper()
{
    class_<PyGeEntity3d>("Entity3d", boost::python::no_init)
        .def("isKindOf", &PyGeEntity3d::isKindOf)
        .def("type", &PyGeEntity3d::type)
        .def("copy", &PyGeEntity3d::copy)
        .def("isEqualTo", &PyGeEntity3d::isEqualTo1)
        .def("isEqualTo", &PyGeEntity3d::isEqualTo2)
        .def("transformBy", &PyGeEntity3d::transformBy)
        .def("translateBy", &PyGeEntity3d::translateBy)
        .def("rotateBy", &PyGeEntity3d::rotateBy1)
        .def("rotateBy", &PyGeEntity3d::rotateBy2)
        .def("mirror", &PyGeEntity3d::mirror)
        .def("scaleBy", &PyGeEntity3d::scaleBy1)
        .def("scaleBy", &PyGeEntity3d::scaleBy2)
        .def("isOn", &PyGeEntity3d::isOn1)
        .def("isOn", &PyGeEntity3d::isOn2)
        .def("isNull", &PyGeEntity3d::isNull)
        .def("__eq__", &PyGeEntity3d::operator==)
        .def("__ne__", &PyGeEntity3d::operator!=)
        .def("cast", &PyGeEntity3d::cast).staticmethod("cast")
        .def("className", &PyGeEntity3d::className).staticmethod("className")
        ;
}

//AcGeSurfSurfInt returns const AcGeSurface*
//we don't want to delete this, hence this
struct PyGeObjectDeleter
{
    inline PyGeObjectDeleter(bool autoDelete)
        : m_autoDelete(autoDelete)
    {
    }

    inline void operator()(AcGeEntity3d* p) const
    {
        if (!m_autoDelete)
            return;
        else
            delete p;
    }
    bool m_autoDelete = true;
};


PyGeEntity3d::PyGeEntity3d(const AcGeEntity3d* pEnt)
    : PyGeEntity3d(const_cast<AcGeEntity3d*>(pEnt), false)
{
}

PyGeEntity3d::PyGeEntity3d(AcGeEntity3d* pEnt, bool autoDelete /*= true*/)
    : m_imp(pEnt, PyGeObjectDeleter(autoDelete))
{
}

bool PyGeEntity3d::operator==(PyGeEntity3d const& rhs) const
{
    if (!isNull() && !rhs.isNull())
        return *impObj() == *rhs.impObj();
    return false;
}

bool PyGeEntity3d::operator!=(PyGeEntity3d const& rhs) const
{
    if (!isNull() && !rhs.isNull())
        return *impObj() != *rhs.impObj();
    return false;
}

Adesk::Boolean PyGeEntity3d::isKindOf(AcGe::EntityId entType) const
{
    return impObj()->isKindOf(entType);
}

AcGe::EntityId PyGeEntity3d::type() const
{
    return impObj()->type();
}

PyGeEntity3d PyGeEntity3d::copy() const
{
    return PyGeEntity3d(impObj()->copy());
}

Adesk::Boolean PyGeEntity3d::isEqualTo1(const PyGeEntity3d& ent) const
{
    return impObj()->isEqualTo(*ent.impObj());
}

Adesk::Boolean PyGeEntity3d::isEqualTo2(const PyGeEntity3d& ent, const AcGeTol& tol) const
{
    return impObj()->isEqualTo(*ent.impObj(), tol);
}

void PyGeEntity3d::transformBy(const AcGeMatrix3d& xfm)
{
    impObj()->transformBy(xfm);
}

void PyGeEntity3d::translateBy(const AcGeVector3d& translateVec)
{
    impObj()->translateBy(translateVec);
}

void PyGeEntity3d::rotateBy1(double angle, const AcGeVector3d& vec)
{
    impObj()->rotateBy(angle, vec);
}

void PyGeEntity3d::rotateBy2(double angle, const AcGeVector3d& vec, const AcGePoint3d& wrtPoint)
{
    impObj()->rotateBy(angle, vec, wrtPoint);
}

void PyGeEntity3d::mirror(const PyGePlane& plane)
{
    impObj()->mirror(*plane.impObj());
}

void PyGeEntity3d::scaleBy1(double scaleFactor)
{
    impObj()->scaleBy(scaleFactor);
}

void PyGeEntity3d::scaleBy2(double scaleFactor, const AcGePoint3d& wrtPoint)
{
    impObj()->scaleBy(scaleFactor, wrtPoint);
}

Adesk::Boolean PyGeEntity3d::isOn1(const AcGePoint3d& pnt) const
{
    return impObj()->isOn(pnt);
}

Adesk::Boolean PyGeEntity3d::isOn2(const AcGePoint3d& pnt, const AcGeTol& tol) const
{
    return impObj()->isOn(pnt, tol);
}

bool PyGeEntity3d::isNull() const
{
    return m_imp == nullptr;
}

std::string PyGeEntity3d::className()
{
    return "AcGeEntity3d";
}

PyGeEntity3d PyGeEntity3d::cast(const PyGeEntity3d& src)
{
    if (!src.impObj()->isKindOf(AcGe::EntityId::kEntity3d))
        PyThrowBadEs(Acad::eInvalidInput);
    return PyGeEntity3d(src.impObj()->copy());
}

AcGeEntity3d* PyGeEntity3d::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_imp.get();
}
