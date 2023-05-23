#include "stdafx.h"
#include "PyGiCommonDraw.h"
#include "PyGiDrawable.h"

using namespace boost::python;
void makePyGiCommonDrawWrapper()
{
	class_<PyGiCommonDraw, bases<PyRxObject>>("CommonDraw", boost::python::no_init)
		.def("className", &PyGiCommonDraw::className).staticmethod("className")
		.def("desc", &PyGiCommonDraw::desc).staticmethod("desc")
		;
}

PyGiCommonDraw::PyGiCommonDraw(AcGiCommonDraw* ptr, bool autoDelete)
	: PyRxObject(ptr, autoDelete, false)
{
}

std::string PyGiCommonDraw::className()
{
	return "AcGiCommonDraw";
}

PyRxClass PyGiCommonDraw::desc()
{
	return PyRxClass(AcGiCommonDraw::desc(), false);
}

AcGiCommonDraw* PyGiCommonDraw::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
	if (m_pImp == nullptr)
		throw PyNullObject(src);
	return static_cast<AcGiCommonDraw*>(m_pImp.get());
}

//-----------------------------------------------------------------------------------------
//PyGiWorldDraw 
void makePyGiWorldDrawWrapper()
{
	class_<PyGiWorldDraw, bases<PyGiCommonDraw>>("WorldDraw", boost::python::no_init)
		.def("draw", &PyGiWorldDraw::draw)
		.def("className", &PyGiWorldDraw::className).staticmethod("className")
		.def("desc", &PyGiWorldDraw::desc).staticmethod("desc")
		;
}

PyGiWorldDraw::PyGiWorldDraw(AcGiWorldDraw* ptr, bool autoDelete)
	: PyGiCommonDraw(ptr, autoDelete)
{
}

bool PyGiWorldDraw::draw(PyGiDrawable& drawable)
{
	return impObj()->geometry().draw(drawable.impObj());
}

std::string PyGiWorldDraw::className()
{
	return "AcGiWorldDraw";
}

PyRxClass PyGiWorldDraw::desc()
{
	return PyRxClass(AcGiWorldDraw::desc(), false);
}

AcGiWorldDraw* PyGiWorldDraw::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
	if (m_pImp == nullptr)
		throw PyNullObject(src);
	return static_cast<AcGiWorldDraw*>(m_pImp.get());
}

//-----------------------------------------------------------------------------------------
//PyGiViewportDraw
void makeAcGiViewportDrawWrapper()
{
	class_<PyGiViewportDraw, bases<PyGiCommonDraw>>("ViewportDraw", boost::python::no_init)
		.def("draw", &PyGiViewportDraw::draw)
		.def("className", &PyGiViewportDraw::className).staticmethod("className")
		.def("desc", &PyGiViewportDraw::desc).staticmethod("desc")
		;
}

PyGiViewportDraw::PyGiViewportDraw(AcGiViewportDraw* ptr, bool autoDelete)
	: PyGiCommonDraw(ptr, autoDelete)
{
}

bool PyGiViewportDraw::draw(PyGiDrawable& drawable)
{
	return impObj()->geometry().draw(drawable.impObj());
}

std::string PyGiViewportDraw::className()
{
	return "AcGiViewportDraw";
}

PyRxClass PyGiViewportDraw::desc()
{
	return PyRxClass(AcGiViewportDraw::desc(), false);
}

AcGiViewportDraw* PyGiViewportDraw::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
	if (m_pImp == nullptr)
		throw PyNullObject(src);
	return static_cast<AcGiViewportDraw*>(m_pImp.get());
}
