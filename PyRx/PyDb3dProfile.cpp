#include "stdafx.h"
#include "PyDb3dProfile.h"
#include "PyDbEntity.h"

using namespace boost::python;
//-----------------------------------------------------------------------------------------
//PyDb3dProfile
void makePyDb3dProfileWrapper()
{
    PyDocString DS("Profile3d");
    class_<PyDb3dProfile, bases<PyRxObject>>("Profile3d")
        .def(init<>())
        .def(init<const PyDbEntity&>())
        .def(init<const AcDb3dProfile&>())
        .def("desc", &PyRxClass::desc, DS.SARGS()).staticmethod("desc")
        .def("className", &PyRxClass::className, DS.SARGS()).staticmethod("className")
        ;
}

PyDb3dProfile::PyDb3dProfile()
    : PyDb3dProfile(new AcDb3dProfile(), true)
{
}

PyDb3dProfile::PyDb3dProfile(const PyDbEntity& pent)
    : PyDb3dProfile(new AcDb3dProfile(pent.impObj()), true)
{
}

PyDb3dProfile::PyDb3dProfile(const AcDb3dProfile& src)
    : PyDb3dProfile(new AcDb3dProfile(src), true)
{
}

PyRxClass PyDb3dProfile::desc()
{
    return PyRxClass(AcDb3dProfile::desc(), false);
}

PyDb3dProfile::PyDb3dProfile(AcDb3dProfile* ptr, bool autoDelete)
    :PyRxObject(ptr, autoDelete, false)
{
}

std::string PyDb3dProfile::className()
{
    return "AcDb3dProfile";
}

AcDb3dProfile* PyDb3dProfile::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDb3dProfile*>(m_pyImp.get());
}
