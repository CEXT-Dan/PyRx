#include "stdafx.h"
#include "PyAcadEntity.h"
#include "PyAcadEntityImpl.h"

using namespace boost::python;
//----------------------------------------------------------------------------------------
//PyAcadEntity
void makePyAcadEntityWrapper()
{
    PyDocString DS("AcadEntity");
    class_<PyAcadEntity, bases<PyAcadObject>>("AcadEntity", boost::python::no_init)
        .def("transformBy", &PyAcadEntity::transformBy, DS.ARGS({ "xform: PyGe.Matrix3d" }))
        .def("className", &PyAcadEntity::className, DS.SARGS()).staticmethod("className")
        .def("cast", &PyAcadEntity::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        ;
}

PyAcadEntity::PyAcadEntity(std::shared_ptr<PyIAcadEntityImpl> ptr)
    :PyAcadObject(ptr)
{
}

void PyAcadEntity::transformBy(const AcGeMatrix3d& xform)
{
    impObj()->TransformBy(xform);
}

PyAcadEntity PyAcadEntity::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadEntity>(src);
}

std::string PyAcadEntity::className()
{
    return "AcDbEntity";
}

PyIAcadEntityImpl* PyAcadEntity::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadEntityImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcad3DFace
void makePyAcad3DFaceWrapper()
{
    PyDocString DS("Acad3DFace");
    class_<PyAcad3DFace, bases<PyAcadEntity>>("Acad3DFace", boost::python::no_init)
        .def("coordinates", &PyAcad3DFace::coordinates, DS.ARGS())
        .def("setCoordinates", &PyAcad3DFace::setCoordinates, DS.ARGS({ "p1:PyGe.Point3d","p2:PyGe.Point3d","p3:PyGe.Point3d","p4:PyGe.Point3d" }))
        .def("invisibleEdge", &PyAcad3DFace::invisibleEdge, DS.ARGS({"index:int"}))
        .def("setInvisibleEdge", &PyAcad3DFace::setInvisibleEdge, DS.ARGS({ "index:int", "flag:bool"}))
        .def("coordinate", &PyAcad3DFace::coordinate, DS.ARGS({ "index:int" }))
        .def("setCoordinate", &PyAcad3DFace::setCoordinate, DS.ARGS({ "index:int", "point:PyGe.Point3d" }))
        .def("cast", &PyAcad3DFace::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcad3DFace::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcad3DFace::PyAcad3DFace(std::shared_ptr<PyIAcad3DFaceImpl> ptr)
    : PyAcadEntity(ptr)
{
}

boost::python::list PyAcad3DFace::coordinates() const
{
    return Point3dArrayToPyList(impObj()->GetCoordinates());
}

void PyAcad3DFace::setCoordinates(const AcGePoint3d& p1, const AcGePoint3d& p2, const AcGePoint3d& p3, const AcGePoint3d& p4)
{
    impObj()->SetCoordinates(p1, p2, p3, p4);
}

bool PyAcad3DFace::invisibleEdge(int index) const
{
    return impObj()->GetInvisibleEdge(index);
}

void PyAcad3DFace::setInvisibleEdge(int index, bool flag) const
{
    impObj()->SetInvisibleEdge(index, flag);
}

AcGePoint3d PyAcad3DFace::coordinate(int index) const
{
    return impObj()->GetCoordinate(index);
}

void PyAcad3DFace::setCoordinate(int index, const AcGePoint3d& val)
{
    impObj()->SetCoordinate(index, val);
}

PyAcad3DFace PyAcad3DFace::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcad3DFace>(src);
}

std::string PyAcad3DFace::className()
{
    return "Acad3DFace";
}

PyIAcad3DFaceImpl* PyAcad3DFace::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcad3DFaceImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadPolygonMesh
void makePyAcadPolygonMeshWrapper()
{
    PyDocString DS("AcadPolygonMesh");
    class_<PyAcadPolygonMesh, bases<PyAcadEntity>>("AcadPolygonMesh", boost::python::no_init)
        .def("cast", &PyAcadPolygonMesh::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadPolygonMesh::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadPolygonMesh::PyAcadPolygonMesh(std::shared_ptr<PyIAcadPolygonMeshImpl> ptr)
    : PyAcadEntity(ptr)
{
}

PyAcadPolygonMesh PyAcadPolygonMesh::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadPolygonMesh>(src);
}

std::string PyAcadPolygonMesh::className()
{
    return "AcadPolygonMesh";
}

PyIAcadPolygonMeshImpl* PyAcadPolygonMesh::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadPolygonMeshImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcad3DPolyline
void makePyAcad3DPolylineWrapper()
{
    PyDocString DS("Acad3DPolyline");
    class_<PyAcad3DPolyline, bases<PyAcadEntity>>("Acad3DPolyline", boost::python::no_init)
        .def("cast", &PyAcad3DPolyline::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcad3DPolyline::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcad3DPolyline::PyAcad3DPolyline(std::shared_ptr<PyIAcad3DPolylineImpl> ptr)
    : PyAcadEntity(ptr)
{
}

PyAcad3DPolyline PyAcad3DPolyline::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcad3DPolyline>(src);
}

std::string PyAcad3DPolyline::className()
{
    return "Acad3DPolyline";
}

PyIAcad3DPolylineImpl* PyAcad3DPolyline::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcad3DPolylineImpl*>(m_pyImp.get());
}