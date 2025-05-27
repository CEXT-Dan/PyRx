#pragma once
#pragma pack (push, 8)
#include "PyGiGraphicsKernel.h"

//-----------------------------------------------------------------------------------------
//PyGsGraphicsKernel
void makePyGsKernelDescriptorWrapper();

class PyGsKernelDescriptor : PyGiKernelDescriptor
{
public:
    PyGsKernelDescriptor(const AcGsKernelDescriptor& kernel);
    virtual ~PyGsKernelDescriptor() override = default;
    void addSupport(const std::string& capability) const;
    static std::string  className();

public:
    AcGsKernelDescriptor* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PyGsGraphicsKernel
void makePyGsGraphicsKernelWrapper();

class PyGsGraphicsKernel : PyGiGraphicsKernel
{
public:
    PyGsGraphicsKernel(const AcGsGraphicsKernel& Kernel);
    virtual ~PyGsGraphicsKernel() override = default;
    void        addRef(void) const;
    bool        delRef(void) const;
    bool        isCompatibleWith(const PyGsKernelDescriptor& descriptor) const;


    static std::string  className();

public:
    AcGsGraphicsKernel* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------------
//PyGsView
void makePyGsViewWrapper();

class PyGsView
{
public:
    PyGsView(AcGsView* impl, bool autodelete);
    ~PyGsView() = default;

    bool                isNullObj() const;
    PyGsGraphicsKernel  graphicsKernel() const;


    void                setViewport(const AcGePoint2d& lowerLeft, const AcGePoint2d& upperRight) const;
    boost::python::tuple getViewport() const;

    void                setViewportBorderVisibility(bool bVisible) const;
    bool                isViewportBorderVisible(void) const;
    void                setView1(const AcGePoint3d& position, const AcGePoint3d& target, const AcGeVector3d& upVector, double fieldWidth, double fieldHeight) const;
    void                setView2(const AcGePoint3d& position, const AcGePoint3d& target, const AcGeVector3d& upVector, double fieldWidth, double fieldHeight, AcGsView::Projection projection) const;

    AcGePoint3d         position(void) const;
    AcGePoint3d         target(void) const;
    AcGeVector3d        upVector(void) const;
    bool                isPerspective(void) const;
    double              fieldWidth(void) const;
    double              fieldHeight(void) const;


    void                setEnableFrontClip(bool enable) const;
    bool                isFrontClipped(void) const;
    void                setFrontClip(double distance) const;
    double              frontClip(void) const;

    void                setEnableBackClip(bool enable) const;
    bool                isBackClipped(void) const;
    void                setBackClip(double distance) const;
    double              backClip(void) const;

    AcGeMatrix3d        viewingMatrix(void) const;
    AcGeMatrix3d        projectionMatrix(void) const;
    AcGeMatrix3d        screenMatrix(void) const;
    AcGeMatrix3d        worldToDeviceMatrix(void) const;
    AcGeMatrix3d        objectToDeviceMatrix(void) const;


    static std::string  className();
public:
    AcGsView* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<AcGsView> m_pyImp = nullptr;
};
#pragma pack (pop)
