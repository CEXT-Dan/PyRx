#include "stdafx.h"
#include "PyGsView.h"

using namespace boost::python;

void makePyGsViewWrapper()
{
    PyDocString DS("PyGsView");
    class_<PyGsView>("GsView", boost::python::no_init)
        .def("className", &PyGsView::className, DS.SARGS()).staticmethod("className")
        ;
}

PyGsView::PyGsView(AcGsView* impl)
{
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
    return m_pyImp;
}
