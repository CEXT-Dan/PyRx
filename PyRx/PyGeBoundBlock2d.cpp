#include "stdafx.h"
#include "PyGeBoundBlock2d.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------------
//PyGeBoundBlock2d wrapper
void makePyGeBoundBlock2dWrapper()
{
    static auto wrapper = class_<PyGeBoundBlock2d, bases<PyGeEntity2d>> ("BoundBlock2d")
        .def(init<>())
        .def(init<const AcGePoint2d&, const AcGePoint2d&>())
        .def(init<const AcGePoint2d&, const AcGeVector2d&, const AcGeVector2d&>())
        .def("className", &PyGeEntity2d::className).staticmethod("className")
        ;
}

PyGeBoundBlock2d::PyGeBoundBlock2d()
   : PyGeEntity2d(new AcGeBoundBlock2d())

{
}

PyGeBoundBlock2d::PyGeBoundBlock2d(AcGeEntity2d* pEnt)
    : PyGeEntity2d(pEnt)
{
}

PyGeBoundBlock2d::PyGeBoundBlock2d(const AcGePoint2d& point1, const AcGePoint2d& point2)
    : PyGeEntity2d(new AcGeBoundBlock2d(point1, point2))
{
}

PyGeBoundBlock2d::PyGeBoundBlock2d(const AcGePoint2d& base, const AcGeVector2d& dir1, const AcGeVector2d& dir2)
    : PyGeEntity2d(new AcGeBoundBlock2d(base, dir1, dir2))
{
}

PyGeBoundBlock2d::PyGeBoundBlock2d(const AcGeBoundBlock2d& block)
    : PyGeEntity2d(new AcGeBoundBlock2d(block))
{
}

std::string PyGeBoundBlock2d::className()
{
    return "AcGeBoundBlock2d";
}

AcGeBoundBlock2d* PyGeBoundBlock2d::impObj() const
{
    return static_cast<AcGeBoundBlock2d*>(m_imp.get());
}
