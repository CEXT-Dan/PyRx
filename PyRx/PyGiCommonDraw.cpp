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
	if (m_pyImp == nullptr)
		throw PyNullObject(src);
	return static_cast<AcGiCommonDraw*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PyGiWorldDraw 
void makePyGiWorldDrawWrapper()
{
	class_<PyGiWorldDraw, bases<PyGiCommonDraw>>("WorldDraw", boost::python::no_init)
		.def("worldGeometry", &PyGiWorldDraw::geometry)
		.def("className", &PyGiWorldDraw::className).staticmethod("className")
		.def("desc", &PyGiWorldDraw::desc).staticmethod("desc")
		;
}

PyGiWorldDraw::PyGiWorldDraw(AcGiWorldDraw* ptr, bool autoDelete)
	: PyGiCommonDraw(ptr, autoDelete)
{
}

PyGiWorldGeometry PyGiWorldDraw::geometry() const
{
	return PyGiWorldGeometry(std::addressof(impObj()->geometry()), false);
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
	if (m_pyImp == nullptr)
		throw PyNullObject(src);
	return static_cast<AcGiWorldDraw*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PyGiViewportDraw
void makeAcGiViewportDrawWrapper()
{
	class_<PyGiViewportDraw, bases<PyGiCommonDraw>>("ViewportDraw", boost::python::no_init)
		.def("viewportGeometry", &PyGiViewportDraw::geometry)
		.def("className", &PyGiViewportDraw::className).staticmethod("className")
		.def("desc", &PyGiViewportDraw::desc).staticmethod("desc")
		;
}

PyGiViewportDraw::PyGiViewportDraw(AcGiViewportDraw* ptr, bool autoDelete)
	: PyGiCommonDraw(ptr, autoDelete)
{
}

PyGiViewportGeometry PyGiViewportDraw::geometry() const
{
	return PyGiViewportGeometry(std::addressof(impObj()->geometry()), false);
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
	if (m_pyImp == nullptr)
		throw PyNullObject(src);
	return static_cast<AcGiViewportDraw*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PyGiGeometry
void makeAcGiGeometryWrapper()
{
	class_<PyGiGeometry, bases<PyRxObject>>("Geometry", boost::python::no_init)

		.def("getModelToWorldTransform", &PyGiGeometry::getModelToWorldTransform)
		.def("getWorldToModelTransform", &PyGiGeometry::getWorldToModelTransform)
		.def("pushModelTransform", &PyGiGeometry::pushModelTransform1)
		.def("pushModelTransform", &PyGiGeometry::pushModelTransform2)
		.def("popModelTransform", &PyGiGeometry::popModelTransform)
		.def("draw", &PyGiGeometry::draw)
		.def("className", &PyGiGeometry::className).staticmethod("className")
		.def("desc", &PyGiGeometry::desc).staticmethod("desc")
		;
}

PyGiGeometry::PyGiGeometry(AcGiGeometry* ptr, bool autoDelete)
	: PyRxObject(ptr, autoDelete, false)
{
}

AcGeMatrix3d PyGiGeometry::getModelToWorldTransform() const
{
	AcGeMatrix3d mat;
	impObj()->getModelToWorldTransform(mat);
	return mat;
}

AcGeMatrix3d PyGiGeometry::getWorldToModelTransform() const
{
	AcGeMatrix3d mat;
	impObj()->getWorldToModelTransform(mat);
	return mat;
}

Adesk::Boolean PyGiGeometry::pushModelTransform1(const AcGeVector3d& vNormal)
{
	return impObj()->pushModelTransform(vNormal);
}

Adesk::Boolean PyGiGeometry::pushModelTransform2(const AcGeMatrix3d& xMat)
{
	return impObj()->pushModelTransform(xMat);
}

Adesk::Boolean PyGiGeometry::popModelTransform()
{
	return impObj()->popModelTransform();
}

Adesk::Boolean PyGiGeometry::draw(PyGiDrawable& drawable)
{
	return impObj()->draw(drawable.impObj());
}

std::string PyGiGeometry::className()
{
	return "AcGiGeometry";
}

PyRxClass PyGiGeometry::desc()
{
	return PyRxClass(AcGiGeometry::desc(), false);
}

AcGiGeometry* PyGiGeometry::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
	if (m_pyImp == nullptr)
		throw PyNullObject(src);
	return static_cast<AcGiGeometry*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//PyGiWorldGeometry
void makeAcGiWorldGeometryWrapper()
{
	class_<PyGiWorldGeometry, bases<PyGiGeometry>>("WorldGeometry", boost::python::no_init)
		.def("className", &PyGiGeometry::className).staticmethod("className")
		.def("desc", &PyGiGeometry::desc).staticmethod("desc")
		;
}

PyGiWorldGeometry::PyGiWorldGeometry(AcGiWorldGeometry* ptr, bool autoDelete)
	: PyGiGeometry(ptr, autoDelete)
{
}

std::string PyGiWorldGeometry::className()
{
	return "AcGiWorldGeometry";
}

PyRxClass PyGiWorldGeometry::desc()
{
	return PyRxClass(AcGiWorldGeometry::desc(), false);
}

AcGiWorldGeometry* PyGiWorldGeometry::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
	if (m_pyImp == nullptr)
		throw PyNullObject(src);
	return static_cast<AcGiWorldGeometry*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
//AcGiViewportGeometry
void makeAcGiViewportGeometryWrapper()
{
	class_<PyGiViewportGeometry, bases<PyGiGeometry>>("ViewportGeometry", boost::python::no_init)
		.def("className", &PyGiGeometry::className).staticmethod("className")
		.def("desc", &PyGiGeometry::desc).staticmethod("desc")
		;
}

PyGiViewportGeometry::PyGiViewportGeometry(AcGiViewportGeometry* ptr, bool autoDelete)
	: PyGiGeometry(ptr, autoDelete)
{
}

std::string PyGiViewportGeometry::className()
{
	return "AcGiViewportGeometry";
}

PyRxClass PyGiViewportGeometry::desc()
{
	return PyRxClass(AcGiViewportGeometry::desc(), false);
}

AcGiViewportGeometry* PyGiViewportGeometry::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
	if (m_pyImp == nullptr)
		throw PyNullObject(src);
	return static_cast<AcGiViewportGeometry*>(m_pyImp.get());
}
