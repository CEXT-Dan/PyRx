#include "stdafx.h"
#include "PyGiParameter.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------------
// PyGiParameter
void makePyGiParameterWrapper()
{
    PyDocString DS("Parameter");
    class_<PyGiParameter, bases<PyRxCopyOnWriteObject>>("Parameter", no_init)
        .def("cast", &PyGiParameter::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        .def("className", &PyGiParameter::className).staticmethod("className")
        .def("desc", &PyGiParameter::desc).staticmethod("desc")
        ;
}

PyGiParameter::PyGiParameter(AcGiParameter* ptr, bool autoDelete)
    : PyRxCopyOnWriteObject(ptr, autoDelete)
{
}

PyRxClass PyGiParameter::desc()
{
    return PyRxClass(AcGiParameter::desc(), false);
}

std::string PyGiParameter::className()
{
    return "AcGiParameter";
}

PyGiParameter PyGiParameter::cast(const PyRxObject& src)
{
    return PyRxCopyOnWriteObjectCast<PyGiParameter>(src);
}

AcGiParameter* PyGiParameter::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcGiParameter*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
// PyGiEdgeData
void makePyGiEdgeDataWrapper()
{
    PyDocString DS("EdgeData");
    class_<PyGiEdgeData, bases<PyGiParameter>>("EdgeData")
        .def(init<>())
        .def("cast", &PyGiEdgeData::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        .def("className", &PyGiEdgeData::className).staticmethod("className")
        .def("desc", &PyGiEdgeData::desc).staticmethod("desc")
        ;
}

PyGiEdgeData::PyGiEdgeData()
: PyGiEdgeData(new AcGiEdgeData(), true)
{
}

PyGiEdgeData::PyGiEdgeData(AcGiEdgeData* ptr, bool autoDelete)
    : PyGiParameter(ptr, autoDelete)
{
}

PyRxClass PyGiEdgeData::desc()
{
    return PyRxClass(AcGiEdgeData::desc(), false);
}

std::string PyGiEdgeData::className()
{
    return "AcGiEdgeData";
}

PyGiEdgeData PyGiEdgeData::cast(const PyRxObject& src)
{
    return PyRxCopyOnWriteObjectCast<PyGiEdgeData>(src);
}

AcGiEdgeData* PyGiEdgeData::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcGiEdgeData*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
// PyGiFaceData
void makePyGiFaceDataWrapper()
{
    PyDocString DS("FaceData");
    class_<PyGiFaceData, bases<PyGiParameter>>("FaceData")
        .def(init<>())
        .def("cast", &PyGiFaceData::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        .def("className", &PyGiFaceData::className).staticmethod("className")
        .def("desc", &PyGiFaceData::desc).staticmethod("desc")
        ;
}

PyGiFaceData::PyGiFaceData()
    : PyGiParameter(new AcGiFaceData(), true)
{
}

PyGiFaceData::PyGiFaceData(AcGiFaceData* ptr, bool autoDelete)
    : PyGiParameter(ptr, autoDelete)
{
}

PyRxClass PyGiFaceData::desc()
{
    return PyRxClass(AcGiFaceData::desc(), false);
}

std::string PyGiFaceData::className()
{
    return "AcGiFaceData";
}

PyGiFaceData PyGiFaceData::cast(const PyRxObject& src)
{
    return PyRxCopyOnWriteObjectCast<PyGiFaceData>(src);
}

AcGiFaceData* PyGiFaceData::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcGiFaceData*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
// PyGiMapper
void makePyGiMapperWrapper()
{
    PyDocString DS("Mapper");
    class_<PyGiMapper, bases<PyGiParameter>>("Mapper")
        .def(init<>())
        .def("cast", &PyGiMapper::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        .def("className", &PyGiMapper::className).staticmethod("className")
        .def("desc", &PyGiMapper::desc).staticmethod("desc")
        ;
}

PyGiMapper::PyGiMapper()
    : PyGiMapper(new AcGiMapper(), true)
{
}

PyGiMapper::PyGiMapper(AcGiMapper* ptr, bool autoDelete)
    : PyGiParameter(ptr, autoDelete)
{
}

PyRxClass PyGiMapper::desc()
{
    return PyRxClass(AcGiMapper::desc(), false);
}

std::string PyGiMapper::className()
{
    return "AcGiMapper";
}

PyGiMapper PyGiMapper::cast(const PyRxObject& src)
{
    return PyRxCopyOnWriteObjectCast<PyGiMapper>(src);
}

AcGiMapper* PyGiMapper::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcGiMapper*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
// PyGiPolyline
void makePyGiPolylineWrapper()
{
    PyDocString DS("Polyline");
#if defined(_BRXTARGET270)
    class_<PyGiPolyline, bases<PyGiParameter>>("Polyline")
#else
    class_<PyGiPolyline, bases<PyRxObject>>("Polyline")
#endif
        .def(init<>())
        .def("cast", &PyGiPolyline::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        .def("className", &PyGiPolyline::className).staticmethod("className")
        .def("desc", &PyGiPolyline::desc).staticmethod("desc")
        ;
}

PyGiPolyline::PyGiPolyline()
    : PyGiPolyline(new AcGiPolyline(), true)
{
}

PyGiPolyline::PyGiPolyline(AcGiPolyline* ptr, bool autoDelete)
#if defined(_BRXTARGET270)
    : PyRxObject(ptr, autoDelete, false)
#else
    : PyGiParameter(ptr, autoDelete)
#endif
{
}

PyRxClass PyGiPolyline::desc()
{
    return PyRxClass(AcGiPolyline::desc(), false);
}

std::string PyGiPolyline::className()
{
    return "AcGiPolyline";
}

PyGiPolyline PyGiPolyline::cast(const PyRxObject& src)
{
    return PyRxCopyOnWriteObjectCast<PyGiPolyline>(src);
}

AcGiPolyline* PyGiPolyline::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcGiPolyline*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
// PyGiTextStyle
void makePyGiTextStyleWrapper()
{
    PyDocString DS("TextStyle");
    class_<PyGiTextStyle, bases<PyGiParameter>>("TextStyle", no_init)
        .def("cast", &PyGiTextStyle::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        .def("className", &PyGiTextStyle::className).staticmethod("className")
        .def("desc", &PyGiTextStyle::desc).staticmethod("desc")
        ;
}


PyGiTextStyle::PyGiTextStyle(AcGiTextStyle* ptr, bool autoDelete)
    : PyGiParameter(ptr, autoDelete)
{
}


PyRxClass PyGiTextStyle::desc()
{
    return PyRxClass(AcGiTextStyle::desc(), false);
}

std::string PyGiTextStyle::className()
{
    return "AcGiTextStyle";
}

PyGiTextStyle PyGiTextStyle::cast(const PyRxObject& src)
{
    return PyRxCopyOnWriteObjectCast<PyGiTextStyle>(src);
}

AcGiTextStyle* PyGiTextStyle::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcGiTextStyle*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------------
// PyGiTextStyle
void makePyGiVertexDataWrapper()
{
    PyDocString DS("VertexData");
    class_<PyGiVertexData, bases<PyGiParameter>>("VertexData")
        .def(init<>())
        .def("cast", &PyGiVertexData::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        .def("className", &PyGiVertexData::className).staticmethod("className")
        .def("desc", &PyGiVertexData::desc).staticmethod("desc")
        ;
}

PyGiVertexData::PyGiVertexData()
    : PyGiVertexData(new AcGiVertexData(), true)
{
}

PyGiVertexData::PyGiVertexData(AcGiVertexData* ptr, bool autoDelete)
    : PyGiParameter(ptr, autoDelete)
{
}

PyRxClass PyGiVertexData::desc()
{
    return PyRxClass(AcGiVertexData::desc(), false);
}

std::string PyGiVertexData::className()
{
    return "AcGiVertexData";
}

PyGiVertexData PyGiVertexData::cast(const PyRxObject& src)
{
    return PyRxCopyOnWriteObjectCast<PyGiVertexData>(src);
}

AcGiVertexData* PyGiVertexData::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcGiVertexData*>(m_pyImp.get());
}
