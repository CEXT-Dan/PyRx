#include "stdafx.h"
#include "PyGeEntity2d.h"
#include "PyGeLinearEnt2d.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------------
//PyGeEntity2d wrapper
void makePyGeEntity2dWrapper()
{
    static auto wrapper = class_<PyGeEntity2d>("Entity2d", boost::python::no_init)
        .def("isKindOf", &PyGeEntity2d::isKindOf)
        .def("type", &PyGeEntity2d::type)
        .def("copy", &PyGeEntity2d::copy)
        .def("isEqualTo", &PyGeEntity2d::isEqualTo1)
        .def("isEqualTo", &PyGeEntity2d::isEqualTo2)
        .def("transformBy", &PyGeEntity2d::transformBy, return_self<>())
        .def("translateBy", &PyGeEntity2d::translateBy, return_self<>())
        .def("rotateBy", &PyGeEntity2d::rotateBy1, return_self<>())
        .def("rotateBy", &PyGeEntity2d::rotateBy2, return_self<>())
        .def("mirror", &PyGeEntity2d::mirror, return_self<>())
        .def("scaleBy", &PyGeEntity2d::scaleBy1, return_self<>())
        .def("scaleBy", &PyGeEntity2d::scaleBy2, return_self<>())
        .def("isOn", &PyGeEntity2d::isOn1)
        .def("isOn", &PyGeEntity2d::isOn2)
        .def("isNull", &PyGeEntity2d::isNull)
        .def("__eq__", &PyGeEntity2d::operator==)
        .def("__ne__", &PyGeEntity2d::operator!=)
        .def("className", &PyGeEntity2d::className).staticmethod("className")
        ;
}

PyGeEntity2d::PyGeEntity2d(AcGeEntity2d* pEnt)
    : m_imp(pEnt)
{
}

bool PyGeEntity2d::operator==(PyGeEntity2d const& rhs) const
{
    if (!isNull() && !rhs.isNull())
        return *impObj() == *rhs.impObj();
    return false;
}

bool PyGeEntity2d::operator!=(PyGeEntity2d const& rhs) const
{
    if (!isNull() && !rhs.isNull())
        return *impObj() != *rhs.impObj();
    return false;
}

Adesk::Boolean PyGeEntity2d::isKindOf(AcGe::EntityId entType) const
{
    return impObj()->isKindOf(entType);
}

AcGe::EntityId PyGeEntity2d::type() const
{
    return impObj()->type();
}

PyGeEntity2d PyGeEntity2d::copy() const
{
    return PyGeEntity2d(impObj()->copy());
}

Adesk::Boolean PyGeEntity2d::isEqualTo1(const PyGeEntity2d& ent) const
{
    return impObj()->isEqualTo(*ent.impObj());
}

Adesk::Boolean PyGeEntity2d::isEqualTo2(const PyGeEntity2d& ent, const AcGeTol& tol) const
{
    return impObj()->isEqualTo(*ent.impObj(), tol);
}

PyGeEntity2d& PyGeEntity2d::transformBy(const AcGeMatrix2d& xfm)
{
    impObj()->transformBy(xfm);
    return *this;
}

PyGeEntity2d& PyGeEntity2d::translateBy(const AcGeVector2d& translateVec)
{
    impObj()->translateBy(translateVec);
    return *this;
}

PyGeEntity2d& PyGeEntity2d::rotateBy1(double angle)
{
    impObj()->rotateBy(angle);
    return *this;
}

PyGeEntity2d& PyGeEntity2d::rotateBy2(double angle, const AcGePoint2d& origin)
{
    impObj()->rotateBy(angle, origin);
    return *this;
}

PyGeEntity2d& PyGeEntity2d::mirror(const PyGeLine2d& plane)
{
    impObj()->mirror(*plane.impObj());
    return *this;
}

PyGeEntity2d& PyGeEntity2d::scaleBy1(double scaleFactor)
{
    impObj()->scaleBy(scaleFactor);
    return *this;
}

PyGeEntity2d& PyGeEntity2d::scaleBy2(double scaleFactor, const AcGePoint2d& wrtPoint)
{
    impObj()->scaleBy(scaleFactor, wrtPoint);
    return *this;
}

Adesk::Boolean PyGeEntity2d::isOn1(const AcGePoint2d& pnt) const
{
    return impObj()->isOn(pnt);
}

Adesk::Boolean PyGeEntity2d::isOn2(const AcGePoint2d& pnt, const AcGeTol& tol) const
{
    return impObj()->isOn(pnt, tol);
}

bool PyGeEntity2d::isNull() const
{
    return m_imp == nullptr;
}

std::string PyGeEntity2d::className()
{
    return "AcGeEntity2d";
}

AcGeEntity2d* PyGeEntity2d::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr)
        throw PyNullObject(src);
    return m_imp.get();
}
