#include "stdafx.h"
#include "PyDbSubDMesh.h"
#include "PyDbObjectId.h"

using namespace boost::python;

void makePyDbSubDMeshWrapper()
{
    PyDocString DS("PyDb.Entity");
    class_<PyDbSubDMesh, bases<PyDbEntity>>("SubDMesh")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: PyDb.ObjectId", "mode:  PyDb.OpenMode=kForRead", "erased: bool=False" })))
        
        .def("className", &PyDbSubDMesh::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbSubDMesh::desc, DS.SARGS()).staticmethod("desc")
        .def("cloneFrom", &PyDbSubDMesh::cloneFrom, DS.SARGS({ "otherObject: RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbSubDMesh::cast, DS.SARGS({ "otherObject: RxObject" })).staticmethod("cast")
        ;
}

PyDbSubDMesh::PyDbSubDMesh()
    : PyDbSubDMesh(new AcDbSubDMesh(), true)
{
}

PyDbSubDMesh::PyDbSubDMesh(const PyDbObjectId& id)
    : PyDbSubDMesh(openAcDbObject<AcDbSubDMesh>(id), false)
{
}

PyDbSubDMesh::PyDbSubDMesh(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbSubDMesh(openAcDbObject<AcDbSubDMesh>(id, mode), false)
{
}

PyDbSubDMesh::PyDbSubDMesh(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbSubDMesh(openAcDbObject<AcDbSubDMesh>(id, mode, erased), false)
{
}

PyDbSubDMesh::PyDbSubDMesh(AcDbSubDMesh* ptr, bool autoDelete)
  : PyDbEntity(ptr, autoDelete)
{
}

void PyDbSubDMesh::setSubDMesh(const boost::python::list& vertexArray, const boost::python::list& faceArray, int subDLevel)
{
    PyThrowBadEs(impObj()->setSubDMesh(PyListToPoint3dArray(vertexArray), PyListToInt32Array(faceArray), subDLevel));
}

void PyDbSubDMesh::setSphere(double radius, int divAxis, int divHeight, int subDLevel)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->setSphere(radius, divAxis, divHeight, subDLevel));
#endif
}

void PyDbSubDMesh::setCylinder(double majorRadius, double minorRadius, double height, int divAxis, int divHeight, int divCap, int subDLevel)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->setCylinder(majorRadius, minorRadius, height, divAxis, divHeight, divCap, subDLevel));
#endif
}

std::string PyDbSubDMesh::className()
{
    return "AcDbSubDMesh";
}

PyRxClass PyDbSubDMesh::desc()
{
    return PyRxClass(AcDbSubDMesh::desc(), false);
}

PyDbSubDMesh PyDbSubDMesh::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbSubDMesh::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbSubDMesh(static_cast<AcDbSubDMesh*>(src.impObj()->clone()), true);
}

PyDbSubDMesh PyDbSubDMesh::cast(const PyRxObject& src)
{
    PyDbSubDMesh dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbSubDMesh* PyDbSubDMesh::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<AcDbSubDMesh*>(m_pyImp.get());
}
