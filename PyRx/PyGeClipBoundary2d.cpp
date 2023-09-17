#include "stdafx.h"
#include "PyGeClipBoundary2d.h"
using namespace boost::python;

//-----------------------------------------------------------------------------------------
//PyGeClipBoundary2d wrapper
void makePyGeClipBoundary2dWrapper()
{
    class_<PyGeClipBoundary2d, bases<PyGeEntity2d>>("ClipBoundary2d")
        .def(init<>())
        .def(init<const AcGePoint2d&, const AcGePoint2d&>())
        .def(init<const boost::python::list&>())
        .def("copycast", &PyGeClipBoundary2d::copycast).staticmethod("copycast")
        .def("className", &PyGeClipBoundary2d::className).staticmethod("className")
        ;
}

PyGeClipBoundary2d::PyGeClipBoundary2d()
    : PyGeEntity2d(new AcGeClipBoundary2d())
{
}

PyGeClipBoundary2d::PyGeClipBoundary2d(AcGeEntity2d* pEnt)
    : PyGeEntity2d(pEnt)
{
}

PyGeClipBoundary2d::PyGeClipBoundary2d(const AcGePoint2d& cornerA, const AcGePoint2d& cornerB)
    : PyGeEntity2d(new AcGeClipBoundary2d(cornerA, cornerB))
{
}

PyGeClipBoundary2d::PyGeClipBoundary2d(const boost::python::list& clipBoundary)
    : PyGeEntity2d(nullptr)
{
    PyAutoLockGIL lock;
    auto vec = py_list_to_std_vector<AcGePoint2d>(clipBoundary);
    AcGePoint2dArray _clipBoundary;
    for (const auto& item : vec)
        _clipBoundary.append(item);
    m_imp.reset(new AcGeClipBoundary2d(_clipBoundary));
}

PyGeClipBoundary2d::PyGeClipBoundary2d(const AcGeClipBoundary2d& src)
    : PyGeEntity2d(src.copy())
{
}

PyGeClipBoundary2d PyGeClipBoundary2d::cast(const PyGeEntity2d& src)
{
    if (!src.impObj()->isKindOf(AcGe::EntityId::kClipBoundary2d))
        PyThrowBadEs(Acad::eNotThatKindOfClass);
    return PyGeEntity2dCast<PyGeClipBoundary2d>(src);
}

PyGeClipBoundary2d PyGeClipBoundary2d::copycast(const PyGeEntity2d& src)
{
    if (!src.impObj()->isKindOf(AcGe::EntityId::kClipBoundary2d))
        PyThrowBadEs(Acad::eNotThatKindOfClass);
    return PyGeClipBoundary2d(src.impObj()->copy());
}

std::string PyGeClipBoundary2d::className()
{
    return "AcGeClipBoundary2d";
}

AcGeClipBoundary2d* PyGeClipBoundary2d::impObj() const
{
    return static_cast<AcGeClipBoundary2d*>(m_imp.get());
}
