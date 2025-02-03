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