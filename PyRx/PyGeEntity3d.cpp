#include "stdafx.h"
#include "PyGeEntity3d.h"
#include "PyGePlane.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------------
//PyGeEntity3d wrapper
void makePyGeEntity3dWrapper()
{
    static auto wrapper = class_<PyGeEntity3d>("Entity3d", boost::python::no_init)
        .def("isKindOf", &PyGeEntity3d::isKindOf)
        .def("type", &PyGeEntity3d::type)
        .def("copy", &PyGeEntity3d::copy)
        .def("isEqualTo", &PyGeEntity3d::isEqualTo)
        .def("transformBy", &PyGeEntity3d::transformBy, return_value_policy<reference_existing_object>())
        .def("translateBy", &PyGeEntity3d::translateBy, return_value_policy<reference_existing_object>())
        .def("rotateBy", &PyGeEntity3d::rotateBy1, return_value_policy<reference_existing_object>())
        .def("rotateBy", &PyGeEntity3d::rotateBy2, return_value_policy<reference_existing_object>())
        .def("mirror", &PyGeEntity3d::mirror, return_value_policy<reference_existing_object>())
        .def("scaleBy", &PyGeEntity3d::scaleBy1, return_value_policy<reference_existing_object>())
        .def("scaleBy", &PyGeEntity3d::scaleBy2, return_value_policy<reference_existing_object>())
        .def("isOn", &PyGeEntity3d::isOn1)
        .def("isOn", &PyGeEntity3d::isOn2)
        .def("isNull", &PyGeEntity3d::isNull)
        .def("__eq__", &PyGeEntity3d::operator==)
        .def("__ne__", &PyGeEntity3d::operator!=)
        .def("className", &PyGeEntity3d::className).staticmethod("className")
        ;
}

PyGeEntity3d::PyGeEntity3d(AcGeEntity3d* pEnt)
    : m_imp(pEnt)
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

Adesk::Boolean PyGeEntity3d::isEqualTo(const PyGeEntity3d& ent, const AcGeTol& tol) const
{
    return impObj()->isEqualTo(*ent.impObj(), tol);
}

PyGeEntity3d& PyGeEntity3d::transformBy(const AcGeMatrix3d& xfm)
{
    impObj()->transformBy(xfm);
    return *this;
}

PyGeEntity3d& PyGeEntity3d::translateBy(const AcGeVector3d& translateVec)
{
    impObj()->translateBy(translateVec);
    return *this;
}

PyGeEntity3d& PyGeEntity3d::rotateBy1(double angle, const AcGeVector3d& vec)
{
    impObj()->rotateBy(angle,vec);
    return *this;
}

PyGeEntity3d& PyGeEntity3d::rotateBy2(double angle, const AcGeVector3d& vec, const AcGePoint3d& wrtPoint)
{
    impObj()->rotateBy(angle, vec, wrtPoint);
    return *this;
}

PyGeEntity3d& PyGeEntity3d::mirror(const PyGePlane& plane)
{
    impObj()->mirror(*plane.impObj());
    return *this;
}

PyGeEntity3d& PyGeEntity3d::scaleBy1(double scaleFactor)
{
    impObj()->scaleBy(scaleFactor);
    return *this;
}

PyGeEntity3d& PyGeEntity3d::scaleBy2(double scaleFactor, const AcGePoint3d& wrtPoint)
{
    impObj()->scaleBy(scaleFactor, wrtPoint);
    return *this;
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

AcGeEntity3d* PyGeEntity3d::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr)
        throw PyNullObject(src);
    return m_imp.get();
}
