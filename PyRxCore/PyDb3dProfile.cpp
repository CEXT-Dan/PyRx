#include "stdafx.h"
#include "PyDb3dProfile.h"
#include "PyDbEntity.h"

#if defined(_BRXTARGET250)
//
#else
using namespace boost::python;
//-----------------------------------------------------------------------------------------
//PyDb3dProfile
void makePyDb3dProfileWrapper()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- val: PyDb.Entity\n";

    PyDocString DS("Profile3d");
    class_<PyDb3dProfile, bases<PyRxObject>>("Profile3d")
        .def(init<>())
        .def(init<const PyDbEntity&>(DS.CTOR(ctords, 1254)))
        .def("isClosed", &PyDb3dProfile::isClosed, DS.ARGS())
        .def("isPlanar", &PyDb3dProfile::isPlanar, DS.ARGS())
        .def("isSubent", &PyDb3dProfile::isSubent, DS.ARGS())
        .def("isFace", &PyDb3dProfile::isFace, DS.ARGS())
        .def("isEdge", &PyDb3dProfile::isEdge, DS.ARGS())
        .def("isValid", &PyDb3dProfile::isValid, DS.ARGS())
        .def("desc", &PyDb3dProfile::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("className", &PyDb3dProfile::className, DS.SARGS()).staticmethod("className")
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

PyDbEntity PyDb3dProfile::entity() const
{
    return PyDbEntity(impObj()->entity(), true);
}

bool PyDb3dProfile::isClosed() const
{
    return impObj()->isClosed();
}

bool PyDb3dProfile::isPlanar() const
{
    return impObj()->isPlanar();
}

bool PyDb3dProfile::isSubent() const
{
    return impObj()->isSubent();
}

bool PyDb3dProfile::isFace() const
{
    return impObj()->isFace();
}

bool PyDb3dProfile::isEdge() const
{
    return impObj()->isEdge();
}

bool PyDb3dProfile::isValid() const
{
    return impObj()->isValid();
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
#endif