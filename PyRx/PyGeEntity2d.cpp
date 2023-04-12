#include "stdafx.h"
#include "PyGeEntity2d.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------------
//PyGeEntity2d wrapper
void makePyGeEntity2dWrapper()
{
    static auto wrapper = class_<PyGeEntity2d>("Entity3d", boost::python::no_init)
        .def("isKindOf", &PyGeEntity2d::isKindOf)
        .def("type", &PyGeEntity2d::type)
        .def("copy", &PyGeEntity2d::copy)
        .def("isEqualTo", &PyGeEntity2d::isEqualTo1)
        .def("isEqualTo", &PyGeEntity2d::isEqualTo2)
        .def("transformBy", &PyGeEntity2d::transformBy, return_value_policy<reference_existing_object>())
        .def("translateBy", &PyGeEntity2d::translateBy, return_value_policy<reference_existing_object>())
        .def("rotateBy", &PyGeEntity2d::rotateBy1, return_value_policy<reference_existing_object>())
        .def("rotateBy", &PyGeEntity2d::rotateBy2, return_value_policy<reference_existing_object>())
        //.def("mirror", &PyGeEntity2d::mirror, return_value_policy<reference_existing_object>())
        .def("scaleBy", &PyGeEntity2d::scaleBy1, return_value_policy<reference_existing_object>())
        .def("scaleBy", &PyGeEntity2d::scaleBy2, return_value_policy<reference_existing_object>())
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
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isKindOf(entType);
}

AcGe::EntityId PyGeEntity2d::type() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->type();
}

PyGeEntity2d PyGeEntity2d::copy() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return PyGeEntity2d(imp->copy());
}

Adesk::Boolean PyGeEntity2d::isEqualTo1(const PyGeEntity2d& ent) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    if (ent.isNull())
        throw PyNullObject();
    return imp->isEqualTo(*ent.impObj());
}

Adesk::Boolean PyGeEntity2d::isEqualTo2(const PyGeEntity2d& ent, const AcGeTol& tol) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    if (ent.isNull())
        throw PyNullObject();
    return imp->isEqualTo(*ent.impObj(), tol);
}

PyGeEntity2d& PyGeEntity2d::transformBy(const AcGeMatrix2d& xfm)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    imp->transformBy(xfm);
    return *this;
}

PyGeEntity2d& PyGeEntity2d::translateBy(const AcGeVector2d& translateVec)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    imp->translateBy(translateVec);
    return *this;
}

PyGeEntity2d& PyGeEntity2d::rotateBy1(double angle)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    imp->rotateBy(angle);
    return *this;
}

PyGeEntity2d& PyGeEntity2d::rotateBy2(double angle, const AcGePoint2d& origin)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    imp->rotateBy(angle, origin);
    return *this;
}

PyGeEntity2d& PyGeEntity2d::scaleBy1(double scaleFactor)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    imp->scaleBy(scaleFactor);
    return *this;
}

PyGeEntity2d& PyGeEntity2d::scaleBy2(double scaleFactor, const AcGePoint2d& wrtPoint)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    imp->scaleBy(scaleFactor, wrtPoint);
    return *this;
}

Adesk::Boolean PyGeEntity2d::isOn1(const AcGePoint2d& pnt) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isOn(pnt);
}

Adesk::Boolean PyGeEntity2d::isOn2(const AcGePoint2d& pnt, const AcGeTol& tol) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isOn(pnt, tol);
}

bool PyGeEntity2d::isNull() const
{
    return m_imp == nullptr;
}

std::string PyGeEntity2d::className()
{
    return "AcGeEntity2d";
}

AcGeEntity2d* PyGeEntity2d::impObj() const
{
    return m_imp.get();
}
