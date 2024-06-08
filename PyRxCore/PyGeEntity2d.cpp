#include "stdafx.h"
#include "PyGeEntity2d.h"
#include "PyGeLinearEnt2d.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------------
//PyGeEntity2d wrapper
void makePyGeEntity2dWrapper()
{
    PyDocString DS("Entity2d");
    class_<PyGeEntity2d>("Entity2d", boost::python::no_init)
        .def("isKindOf", &PyGeEntity2d::isKindOf, DS.ARGS({ "val : PyGe.EntityId" }))
        .def("type", &PyGeEntity2d::type, DS.ARGS())
        .def("copy", &PyGeEntity2d::copy, DS.ARGS())
        .def("isEqualTo", &PyGeEntity2d::isEqualTo1)
        .def("isEqualTo", &PyGeEntity2d::isEqualTo2, DS.ARGS({ "val : PyGe.Entity2d","tol : PyGe.Tol=None" }))
        .def("transformBy", &PyGeEntity2d::transformBy, DS.ARGS({ "val : PyGe.Matrix2d" }))
        .def("translateBy", &PyGeEntity2d::translateBy, DS.ARGS({ "vec : PyGe.Vector2d" }))
        .def("rotateBy", &PyGeEntity2d::rotateBy1)
        .def("rotateBy", &PyGeEntity2d::rotateBy2, DS.ARGS({ "angle : float","pt : PyGe.Point3d=PyGe.Point2d.kOrgin" }))
        .def("mirror", &PyGeEntity2d::mirror, DS.ARGS({ "val : PyGe.Line2d" }))
        .def("scaleBy", &PyGeEntity2d::scaleBy1)
        .def("scaleBy", &PyGeEntity2d::scaleBy2, DS.ARGS({ "scaleFactor : float","pt : PyGe.Point2d=PyGe.Point2d.kOrgin" }))
        .def("isOn", &PyGeEntity2d::isOn1)
        .def("isOn", &PyGeEntity2d::isOn2, DS.ARGS({ "pt : PyGe.Point2d","tol : PyGe.Tol=None" }))
        .def("isNull", &PyGeEntity2d::isNull, DS.ARGS())
        .def("__eq__", &PyGeEntity2d::operator==)
        .def("__ne__", &PyGeEntity2d::operator!=)
        .def("copycast", &PyGeEntity2d::copycast, DS.SARGS({ "otherObject: PyGe.Entity2d" })).staticmethod("copycast")
        .def("className", &PyGeEntity2d::className, DS.SARGS()).staticmethod("className")
        ;
}

struct PyGePyGeEntity2dDeleter
{
    inline PyGePyGeEntity2dDeleter(bool autoDelete)
        : m_autoDelete(autoDelete)
    {
    }

    inline void operator()(AcGeEntity2d* p) const
    {
        if (!m_autoDelete)
            return;
        else
            delete p;
    }
    bool m_autoDelete = true;
};

PyGeEntity2d::PyGeEntity2d(AcGeEntity2d* pEnt)
    : m_imp(pEnt, PyGePyGeEntity2dDeleter(true))
{
}

PyGeEntity2d::PyGeEntity2d(const AcGeEntity2d* pEnt)
    : m_imp(const_cast<AcGeEntity2d*>(pEnt), PyGePyGeEntity2dDeleter(false))
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

void PyGeEntity2d::transformBy(const AcGeMatrix2d& xfm)
{
    impObj()->transformBy(xfm);
}

void PyGeEntity2d::translateBy(const AcGeVector2d& translateVec)
{
    impObj()->translateBy(translateVec);
}

void PyGeEntity2d::rotateBy1(double angle)
{
    impObj()->rotateBy(angle);
}

void PyGeEntity2d::rotateBy2(double angle, const AcGePoint2d& origin)
{
    impObj()->rotateBy(angle, origin);
}

void PyGeEntity2d::mirror(const PyGeLine2d& plane)
{
    impObj()->mirror(*plane.impObj());
}

void PyGeEntity2d::scaleBy1(double scaleFactor)
{
    impObj()->scaleBy(scaleFactor);
}

void PyGeEntity2d::scaleBy2(double scaleFactor, const AcGePoint2d& wrtPoint)
{
    impObj()->scaleBy(scaleFactor, wrtPoint);
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

PyGeEntity2d PyGeEntity2d::copycast(const PyGeEntity2d& src)
{
    if (!src.impObj()->isKindOf(AcGe::EntityId::kEntity2d))
        PyThrowBadEs(Acad::eInvalidInput);
    return PyGeEntity2d(src.impObj()->copy());
}

std::string PyGeEntity2d::className()
{
    return "AcGeEntity2d";
}

AcGeEntity2d* PyGeEntity2d::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return m_imp.get();
}
