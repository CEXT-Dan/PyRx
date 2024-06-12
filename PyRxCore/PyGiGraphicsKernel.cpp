#include "stdafx.h"
#include "PyGiGraphicsKernel.h"

using namespace boost::python;

void makePyGiKernelDescriptorWrapper()
{
    PyDocString DS("GiKernelDescriptor");
    class_<PyGiKernelDescriptor>("GiKernelDescriptor", boost::python::no_init)
        .def("supports", &PyGiKernelDescriptor::supports, DS.ARGS(13289))
        .def("className", &PyGiKernelDescriptor::className).staticmethod("className")
        ;
}

PyGiKernelDescriptor::PyGiKernelDescriptor(const AcGiKernelDescriptor& kernel)
    : m_pyImp(new AcGiKernelDescriptor(kernel))
{
}

bool PyGiKernelDescriptor::supports(const PyGiKernelDescriptor& desc) const
{
    return impObj()->supports(*desc.impObj());
}


std::string PyGiKernelDescriptor::className()
{
    return "AcGiKernelDescriptor";
}

AcGiKernelDescriptor* PyGiKernelDescriptor::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return m_pyImp.get();
}

//-----------------------------------------------------------------------------------------
//PyGiGraphicsKernel
void makePyGiGraphicsKernelWrapper()
{
    PyDocString DS("GiGraphicsKernel");
    class_<PyGiGraphicsKernel>("GiGraphicsKernel", boost::python::no_init)
        .def("getDescriptor", &PyGiGraphicsKernel::getDescriptor, DS.ARGS(13217))
        .def("className", &PyGiGraphicsKernel::className).staticmethod("className")
        ;
}

PyGiGraphicsKernel::PyGiGraphicsKernel(const AcGiGraphicsKernel& Kernel)
    : m_pyImp(new AcGiGraphicsKernel(Kernel))
{
}

const PyGiKernelDescriptor PyGiGraphicsKernel::getDescriptor(void)
{
    return PyGiKernelDescriptor(impObj()->getDescriptor());
}

std::string PyGiGraphicsKernel::className()
{
    return "AcGiGraphicsKernel";
}

AcGiGraphicsKernel* PyGiGraphicsKernel::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return m_pyImp.get();
}

