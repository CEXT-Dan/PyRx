#include "stdafx.h"
#include "PyDbSection.h"
#include "PyDbObjectId.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------
//PyDbSection
void makePyDbSectionWrapper()
{
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- pts: list[PyGe.Point3d], verticalDir: PyGe.Vector3d\n"
        "- pts: list[PyGe.Point3d], verticalDir: PyGe.Vector3d, vecViewingDir: PyGe.Vector3d\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    PyDocString DS("PyDb.Section");
    class_<PyDbSection, bases<PyDbEntity>>("Section")
        .def(init<>())
        .def(init<const boost::python::list&, const AcGeVector3d&>())
        .def(init<const boost::python::list&, const AcGeVector3d&, const AcGeVector3d&>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.CTOR(ctords)))
        .def("className", &PyDbSection::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbSection::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbSection::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbSection::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;
}

PyDbSection::PyDbSection()
    : PyDbSection::PyDbSection(new AcDbSection(), true)
{
}

PyDbSection::PyDbSection(const boost::python::list& pts, const AcGeVector3d& verticalDir)
    : PyDbSection::PyDbSection(new AcDbSection(PyListToPoint3dArray(pts), verticalDir), true)
{
}

PyDbSection::PyDbSection(const boost::python::list& pts, const AcGeVector3d& verticalDir, const AcGeVector3d& vecViewingDir)
    : PyDbSection::PyDbSection(new AcDbSection(PyListToPoint3dArray(pts), verticalDir, vecViewingDir), true)
{
}

PyDbSection::PyDbSection(const PyDbObjectId& id)
    : PyDbSection(openAcDbObject<AcDbSection>(id, AcDb::OpenMode::kForRead), false)
{
}

PyDbSection::PyDbSection(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbSection(openAcDbObject<AcDbSection>(id, mode), false)
{
}

PyDbSection::PyDbSection(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbSection(openAcDbObject<AcDbSection>(id, mode, erased), false)
{
}

PyDbSection::PyDbSection(AcDbSection* ptr, bool autoDelete)
    : PyDbEntity(ptr, autoDelete)
{
}

std::string PyDbSection::className()
{
    return "AcDbSection";
}

PyRxClass PyDbSection::desc()
{
    return PyRxClass(AcDbText::desc(), false);
}

PyDbSection PyDbSection::cloneFrom(const PyRxObject& src)
{
    return PyDbObjectCloneFrom<PyDbSection, AcDbSection>(src);
}

PyDbSection PyDbSection::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbSection>(src);
}

AcDbSection* PyDbSection::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<AcDbSection*>(m_pyImp.get());
}
