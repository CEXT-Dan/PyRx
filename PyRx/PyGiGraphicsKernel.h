#pragma once


//-----------------------------------------------------------------------------------------
//PyGiKernelDescriptor
void makePyGiKernelDescriptorWrapper();

class PyGiKernelDescriptor
{
public:
    PyGiKernelDescriptor(const AcGiKernelDescriptor& kernel);
    bool supports(const PyGiKernelDescriptor& desc) const;

    static std::string className();

public:
    AcGiKernelDescriptor impl;
};

//-----------------------------------------------------------------------------------------
//PyGiGraphicsKernel
void makePyGiGraphicsKernelWrapper();

class PyGiGraphicsKernel
{
public:
    PyGiGraphicsKernel(const AcGiGraphicsKernel& Kernel);
    const PyGiKernelDescriptor getDescriptor(void);
    static std::string className();

public:
    AcGiGraphicsKernel impl;
};

class PyGiContext
{

};