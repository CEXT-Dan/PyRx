#pragma once
#pragma pack (push, 8)

//-----------------------------------------------------------------------------------------
//PyGiKernelDescriptor
void makePyGiKernelDescriptorWrapper();

class PyGiKernelDescriptor
{
public:
    PyGiKernelDescriptor(const AcGiKernelDescriptor& kernel);
    virtual ~PyGiKernelDescriptor() = default;
    bool                supports(const PyGiKernelDescriptor& desc) const;
    static std::string  className();

    AcGiKernelDescriptor* impObj(const std::source_location& src = std::source_location::current()) const;

public:
    std::shared_ptr<AcGiKernelDescriptor> m_pyImp = nullptr;
};

//-----------------------------------------------------------------------------------------
//PyGiGraphicsKernel
void makePyGiGraphicsKernelWrapper();

class PyGiGraphicsKernel
{
public:
    PyGiGraphicsKernel(const AcGiGraphicsKernel& Kernel);
    virtual ~PyGiGraphicsKernel() = default;
    const PyGiKernelDescriptor  getDescriptor(void);
    static std::string          className();

    AcGiGraphicsKernel* impObj(const std::source_location& src = std::source_location::current()) const;

public:
    std::shared_ptr<AcGiGraphicsKernel> m_pyImp = nullptr;
};

class PyGiContext
{

};

#pragma pack (pop)
