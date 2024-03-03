#include "stdafx.h"
#include "PyGsView.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------------
//PyGsGraphicsKernel
void makePyGsKernelDescriptorWrapper()
{

}

PyGsKernelDescriptor::PyGsKernelDescriptor(const AcGsKernelDescriptor& kernel)
    : PyGiKernelDescriptor(kernel)
{

}

void PyGsKernelDescriptor::addSupport(const std::string& capability)
{
    impObj()->addSupport(AcUniqueString::Intern(utf8_to_wstr(capability).c_str()));
}

AcGsKernelDescriptor* PyGsKernelDescriptor::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<AcGsKernelDescriptor*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PyGsGraphicsKernel
void makePyGsGraphicsKernelWrapper()
{

}

PyGsGraphicsKernel::PyGsGraphicsKernel(const AcGsGraphicsKernel& Kernel)
    : PyGiGraphicsKernel(Kernel)
{
}

AcGsGraphicsKernel* PyGsGraphicsKernel::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<AcGsGraphicsKernel*>(m_pyImp.get());
}


//-----------------------------------------------------------------------------------------
//PyGsView
void makePyGsViewWrapper()
{
    PyDocString DS("PyGsView");
    class_<PyGsView>("GsView", boost::python::no_init)
        .def("isNullObj", &PyGsView::isNullObj, DS.ARGS())
        .def("position", &PyGsView::position, DS.ARGS())
        .def("className", &PyGsView::className, DS.SARGS()).staticmethod("className")
        ;
}

struct PyGsViewDeleter
{
    inline PyGsViewDeleter(bool autoDelete)
        : m_autoDelete(autoDelete)
    {
    }

    inline void operator()(AcGsView* p) const
    {
        if (p == nullptr)
            return;
        else if (!m_autoDelete)
            return;
        else
            delete p;
    }
    bool m_autoDelete = true; //destroyAutoCADView?
};

PyGsView::PyGsView(AcGsView* impl, bool autodelete)
    : m_pyImp(impl, PyGsViewDeleter(autodelete))
{
}

bool PyGsView::isNullObj()
{
    return m_pyImp == nullptr;
}

PyGsGraphicsKernel PyGsView::graphicsKernel()
{
   return PyGsGraphicsKernel(impObj()->graphicsKernel());
}

void PyGsView::setViewport(const AcGePoint2d& lowerLeft, const AcGePoint2d& upperRight)
{
    impObj()->setViewport(lowerLeft, upperRight);
}

boost::python::tuple PyGsView::getViewport()
{
    AcGePoint2d lowerLeft;
    AcGePoint2d upperRight;
    impObj()->getViewport(lowerLeft, upperRight);
    return boost::python::make_tuple(lowerLeft, upperRight);
}

void PyGsView::setViewportBorderVisibility(bool bVisible)
{
    impObj()->setViewportBorderVisibility(bVisible);
}

bool PyGsView::isViewportBorderVisible(void) const
{
    return impObj()->isViewportBorderVisible();
}

void PyGsView::setView1(const AcGePoint3d& position, const AcGePoint3d& target, const AcGeVector3d& upVector, double fieldWidth, double fieldHeight)
{
    impObj()->setView(position, target, upVector, fieldWidth, fieldHeight);
}

void PyGsView::setView2(const AcGePoint3d& position, const AcGePoint3d& target, const AcGeVector3d& upVector, double fieldWidth, double fieldHeight, AcGsView::Projection projection)
{
    impObj()->setView(position, target, upVector, fieldWidth, fieldHeight, projection);
}

AcGePoint3d PyGsView::position(void) const
{
    return impObj()->position();
}

AcGePoint3d PyGsView::target(void) const
{
    return impObj()->target();
}

AcGeVector3d PyGsView::upVector(void) const
{
    return impObj()->upVector();
}

bool PyGsView::isPerspective(void) const
{
    return impObj()->isPerspective();
}

double PyGsView::fieldWidth(void) const
{
    return impObj()->fieldWidth();
}

double PyGsView::fieldHeight(void) const
{
    return impObj()->fieldHeight();
}

void PyGsView::setEnableFrontClip(bool enable)
{
    impObj()->setEnableFrontClip(enable);
}

bool PyGsView::isFrontClipped(void) const
{
    return impObj()->isFrontClipped();
}

void PyGsView::setFrontClip(double distance)
{
    impObj()->setFrontClip(distance);
}

double PyGsView::frontClip(void) const
{
    return impObj()->frontClip();
}

void PyGsView::setEnableBackClip(bool enable)
{
    impObj()->setEnableBackClip(enable);
}

bool PyGsView::isBackClipped(void) const
{
    return impObj()->isBackClipped();
}

void PyGsView::setBackClip(double distance)
{
    impObj()->setBackClip(distance);
}

double PyGsView::backClip(void) const
{
    return impObj()->backClip();
}

AcGeMatrix3d PyGsView::viewingMatrix(void) const
{
    return impObj()->viewingMatrix();
}

AcGeMatrix3d PyGsView::projectionMatrix(void) const
{
    return impObj()->projectionMatrix();
}

AcGeMatrix3d PyGsView::screenMatrix(void) const
{
    return impObj()->screenMatrix();
}

AcGeMatrix3d PyGsView::worldToDeviceMatrix(void) const
{
    return impObj()->worldToDeviceMatrix();
}

AcGeMatrix3d PyGsView::objectToDeviceMatrix(void) const
{
    return impObj()->objectToDeviceMatrix();
}

std::string PyGsView::className()
{
    return "AcGsView";
}

AcGsView* PyGsView::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return m_pyImp.get();
}
