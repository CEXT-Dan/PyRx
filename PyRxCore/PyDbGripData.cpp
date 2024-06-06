#include "stdafx.h"
#include "PyDbGripData.h"

using namespace boost::python;

void makePyDbGripDataWrapper()
{
    PyDocString DS("GripData");
    class_<PyDbGripData>("GripData")
        .def(init<>(DS.ARGS()))
        .def("gripPoint", &PyDbGripData::gripPoint, DS.ARGS())
        .def("setGripPoint", &PyDbGripData::setGripPoint, DS.ARGS({ "pt: PyGe.Point3d" }))
        .def("className", &PyDbGripData::className, DS.SARGS()).staticmethod("className")
        ;
}

PyDbGripData::PyDbGripData()
    : m_imp(new AcDbGripData())
{
}

PyDbGripData::PyDbGripData(AcDbGripData* ptr)
    : m_imp(ptr)
{
}

AcGePoint3d PyDbGripData::gripPoint() const
{
    return impObj()->gripPoint();
}

void PyDbGripData::setGripPoint(const AcGePoint3d& pt)
{
    impObj()->setGripPoint(pt);
}

std::string PyDbGripData::className()
{
    return "AcDbGripData";
}

AcDbGripData* PyDbGripData::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return m_imp.get();
}
