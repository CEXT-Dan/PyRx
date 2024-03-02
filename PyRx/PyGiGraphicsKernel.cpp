#include "stdafx.h"
#include "PyGiGraphicsKernel.h"

using namespace boost::python;

void makePyGiKernelDescriptorWrapper()
{
    class_<PyGiKernelDescriptor>("GiKernelDescriptor", boost::python::no_init)
        .def("className", &PyGiKernelDescriptor::className).staticmethod("className")
        ;
}

PyGiKernelDescriptor::PyGiKernelDescriptor(const AcGiKernelDescriptor& kernel)
    : impl(kernel)
{
}

bool PyGiKernelDescriptor::supports(const PyGiKernelDescriptor& desc) const
{
    return impl.supports(desc.impl);
}


std::string PyGiKernelDescriptor::className()
{
    return "AcGiKernelDescriptor";
}

//-----------------------------------------------------------------------------------------
//PyGiGraphicsKernel
void makePyGiGraphicsKernelWrapper()
{
    class_<PyGiGraphicsKernel>("GiGraphicsKernel", boost::python::no_init)
        .def("getDescriptor", &PyGiGraphicsKernel::getDescriptor)
        .def("className", &PyGiGraphicsKernel::className).staticmethod("className")
        ;
}

PyGiGraphicsKernel::PyGiGraphicsKernel(const AcGiGraphicsKernel& Kernel)
    : impl(Kernel)
{
}

const PyGiKernelDescriptor PyGiGraphicsKernel::getDescriptor(void)
{
    return PyGiKernelDescriptor(impl.getDescriptor());
}

std::string PyGiGraphicsKernel::className()
{
    return "AcGiGraphicsKernel";
}

