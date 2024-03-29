#include "stdafx.h"
#include "PyDbSurface.h"
#include "PyDbObjectId.h"
#include "PyDb3dSolid.h"
#include "PyDb3dProfile.h"

using namespace boost::python;
//----------------------------------------------------------------------
//PyDbSurface
void makePyDbSurfaceWrapper()
{
    class_<PyDbSurface, bases<PyDbEntity>>("Surface")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())

        .def("getArea", &PyDbSurface::getArea)
        .def("uIsolineDensity", &PyDbSurface::uIsolineDensity)
        .def("setUIsolineDensity", &PyDbSurface::setUIsolineDensity)
        .def("vIsolineDensity", &PyDbSurface::vIsolineDensity)
        .def("setVIsolineDensity", &PyDbSurface::setVIsolineDensity)
        .def("getWireframeType", &PyDbSurface::getWireframeType)
        .def("setWireframeType", &PyDbSurface::setWireframeType)
        .def("getPerimeter", &PyDbSurface::getPerimeter)
        .def("creationActionBodyId", &PyDbSurface::creationActionBodyId)
        .def("modificationActionBodyIds", &PyDbSurface::modificationActionBodyIds)
        .def("extendEdges", &PyDbSurface::extendEdges)
        .def("rayTest", &PyDbSurface::rayTest)
        .def("projectOnToSurface", &PyDbSurface::projectOnToSurface)
        .def("createFrom", &PyDbSurface::createFrom).staticmethod("createFrom")
#if !defined(_BRXTARGET240)
        .def("createExtrudedSurface", &PyDbSurface::createExtrudedSurface).staticmethod("createExtrudedSurface")
#endif
        .def("className", &PyDbSurface::className).staticmethod("className")
        .def("desc", &PyDbSurface::desc).staticmethod("desc")
        .def("cloneFrom", &PyDbSurface::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbSurface::cast).staticmethod("cast")
        ;


    //enums
    enum_<AcDbSurface::EdgeExtensionType>("SurfaceEdgeExtensionType")
        .value("kExtendEdge", AcDbSurface::EdgeExtensionType::kExtendEdge)
        .value("kStretchEdge", AcDbSurface::EdgeExtensionType::kStretchEdge)
        .export_values()
        ;
    enum_<AcDbSurface::WireframeType>("SurfaceWireframeType")
        .value("kIsolines", AcDbSurface::WireframeType::kIsolines)
        .value("kIsoparms", AcDbSurface::WireframeType::kIsoparms)
        .export_values()
        ;
}

PyDbSurface::PyDbSurface()
    : PyDbEntity(new AcDbSurface(), true)
{
}

PyDbSurface::PyDbSurface(AcDbSurface* ptr, bool autoDelete)
    : PyDbEntity(ptr, autoDelete)
{
}

PyDbSurface::PyDbSurface(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbEntity(openAcDbObject<AcDbSurface>(id, mode), false)
{
}

PyDbSurface::PyDbSurface(const PyDbObjectId& id)
    : PyDbSurface(id, AcDb::OpenMode::kForRead)
{
}

double PyDbSurface::getArea() const
{
    double area = 0;
    PyThrowBadEs(impObj()->getArea(area));
    return area;
}

Adesk::UInt16 PyDbSurface::uIsolineDensity() const
{
    return impObj()->uIsolineDensity();
}

void PyDbSurface::setUIsolineDensity(Adesk::UInt16 numIsolines)
{
    PyThrowBadEs(impObj()->setUIsolineDensity(numIsolines));
}

Adesk::UInt16 PyDbSurface::vIsolineDensity() const
{
    return impObj()->vIsolineDensity();
}

void PyDbSurface::setVIsolineDensity(Adesk::UInt16 numIsolines)
{
    PyThrowBadEs(impObj()->setVIsolineDensity(numIsolines));
}

AcDbSurface::WireframeType PyDbSurface::getWireframeType() const
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return impObj()->getWireframeType();
#endif
}

void PyDbSurface::setWireframeType(AcDbSurface::WireframeType type)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    PyThrowBadEs(impObj()->setWireframeType(type));
#endif
}

double PyDbSurface::getPerimeter() const
{
    double perimeter = 0;
    PyThrowBadEs(impObj()->getPerimeter(perimeter));
    return perimeter;
}

PyDbObjectId PyDbSurface::creationActionBodyId() const
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyDbObjectId(impObj()->creationActionBodyId());
#endif
}

boost::python::list PyDbSurface::modificationActionBodyIds() const
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    AcDbObjectIdArray modificationActionBodyIds;
    PyThrowBadEs(impObj()->modificationActionBodyIds(modificationActionBodyIds));
    return ObjectIdArrayToPyList(modificationActionBodyIds);
#endif
}

void PyDbSurface::extendEdges(boost::python::list& edges, double extDist, AcDbSurface::EdgeExtensionType extOption, bool bAssociativeEnabled)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    auto _edges = PyListToPyDbFullSubentPathArray(edges);
    PyThrowBadEs(impObj()->extendEdges(_edges, extDist, extOption, bAssociativeEnabled));
#endif
}

boost::python::tuple PyDbSurface::rayTest(const AcGePoint3d& rayBasePoint, const AcGeVector3d& rayDir, double rayRadius) const
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    PyAutoLockGIL lock;
    AcArray<AcDbSubentId> subEntIds;
    AcGeDoubleArray parameters;
    PyThrowBadEs(impObj()->rayTest(rayBasePoint, rayDir, rayRadius, subEntIds, parameters));
    return boost::python::make_tuple(SubentIdArrayToPyList(subEntIds), DoubleArrayToPyList(parameters));
#endif
}

boost::python::list PyDbSurface::projectOnToSurface(const PyDbEntity& ent, const AcGeVector3d& projectionDirection)
{
    PyAutoLockGIL lock;
    AcArray<AcDbEntity*> projectedEntities;
    PyThrowBadEs(impObj()->projectOnToSurface(ent.impObj(), projectionDirection, projectedEntities));
    boost::python::list pyList;
    for (auto item : projectedEntities)
        pyList.append(PyDbEntity(item, true));
    return pyList;
}

PyDbSurface PyDbSurface::createFrom(const PyDbEntity& pFromEntity)
{
    AcDbSurface* pNewSurface = nullptr;
    PyThrowBadEs(AcDbSurface::createFrom(pFromEntity.impObj(), pNewSurface));
    return PyDbSurface(pNewSurface, true);
}

#if !defined(_BRXTARGET240)
PyDbExtrudedSurface PyDbSurface::createExtrudedSurface(PyDb3dProfile& pSweep, const AcGeVector3d& directionVec, PyDbSweepOptions& sweepOptions)
{
    AcDbExtrudedSurface* newExtrudedSurface = nullptr;
    PyThrowBadEs(AcDbSurface::createExtrudedSurface(pSweep.impObj(), directionVec, *sweepOptions.impObj(), newExtrudedSurface));
    return PyDbExtrudedSurface(newExtrudedSurface, true);
}
#endif

std::string PyDbSurface::className()
{
    return "AcDbSurface";
}

PyRxClass PyDbSurface::desc()
{
    return PyRxClass(AcDbSurface::desc(), false);
}

PyDbSurface PyDbSurface::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbSurface::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbSurface(static_cast<AcDbSurface*>(src.impObj()->clone()), true);
}

PyDbSurface PyDbSurface::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbSurface>(src);
}

AcDbSurface* PyDbSurface::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<AcDbSurface*>(m_pyImp.get());
}

//----------------------------------------------------------------------
//AcDbExtrudedSurface
void makePyDbExtrudedSurfaceWrapper()
{
    class_<PyDbExtrudedSurface, bases<PyDbSurface>>("ExtrudedSurface")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("className", &PyDbExtrudedSurface::className).staticmethod("className")
        .def("desc", &PyDbExtrudedSurface::desc).staticmethod("desc")
        .def("cloneFrom", &PyDbExtrudedSurface::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbExtrudedSurface::cast).staticmethod("cast")
        ;
}

PyDbExtrudedSurface::PyDbExtrudedSurface()
    : PyDbSurface(new AcDbSurface(), true)
{
}

PyDbExtrudedSurface::PyDbExtrudedSurface(AcDbExtrudedSurface* ptr, bool autoDelete)
    : PyDbSurface(ptr, autoDelete)
{
}

PyDbExtrudedSurface::PyDbExtrudedSurface(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbSurface(openAcDbObject<AcDbExtrudedSurface>(id, mode), false)
{
}

PyDbExtrudedSurface::PyDbExtrudedSurface(const PyDbObjectId& id)
    : PyDbExtrudedSurface(id, AcDb::OpenMode::kForRead)
{
}

std::string PyDbExtrudedSurface::className()
{
    return "AcDbExtrudedSurface";
}

PyRxClass PyDbExtrudedSurface::desc()
{
    return PyRxClass(AcDbExtrudedSurface::desc(), false);
}

PyDbExtrudedSurface PyDbExtrudedSurface::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbExtrudedSurface::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbExtrudedSurface(static_cast<AcDbExtrudedSurface*>(src.impObj()->clone()), true);
}

PyDbExtrudedSurface PyDbExtrudedSurface::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbExtrudedSurface>(src);
}

AcDbExtrudedSurface* PyDbExtrudedSurface::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbExtrudedSurface*>(m_pyImp.get());
}

//----------------------------------------------------------------------
//AcDbLoftedSurface 
void makePyDbLoftedSurfaceWrapper()
{
    class_<PyDbLoftedSurface, bases<PyDbSurface>>("LoftedSurface")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("className", &PyDbLoftedSurface::className).staticmethod("className")
        .def("desc", &PyDbLoftedSurface::desc).staticmethod("desc")
        .def("cloneFrom", &PyDbLoftedSurface::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbLoftedSurface::cast).staticmethod("cast")
        ;
}

PyDbLoftedSurface::PyDbLoftedSurface()
    : PyDbSurface(new AcDbLoftedSurface(), true)
{
}

PyDbLoftedSurface::PyDbLoftedSurface(AcDbLoftedSurface* ptr, bool autoDelete)
    : PyDbSurface(ptr, autoDelete)
{
}

PyDbLoftedSurface::PyDbLoftedSurface(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbSurface(openAcDbObject<AcDbLoftedSurface>(id, mode), false)
{
}

PyDbLoftedSurface::PyDbLoftedSurface(const PyDbObjectId& id)
    : PyDbLoftedSurface(id, AcDb::OpenMode::kForRead)
{
}

std::string PyDbLoftedSurface::className()
{
    return "AcDbLoftedSurface";
}

PyRxClass PyDbLoftedSurface::desc()
{
    return PyRxClass(AcDbLoftedSurface::desc(), false);
}

PyDbLoftedSurface PyDbLoftedSurface::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbLoftedSurface::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbLoftedSurface(static_cast<AcDbLoftedSurface*>(src.impObj()->clone()), true);
}

PyDbLoftedSurface PyDbLoftedSurface::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbLoftedSurface>(src);
}

AcDbLoftedSurface* PyDbLoftedSurface::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<AcDbLoftedSurface*>(m_pyImp.get());
}

//----------------------------------------------------------------------
//PyDbNurbSurface 
void makePyDbNurbSurfaceWrapper()
{
    class_<PyDbNurbSurface, bases<PyDbSurface>>("NurbSurface")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("className", &PyDbNurbSurface::className).staticmethod("className")
        .def("desc", &PyDbNurbSurface::desc).staticmethod("desc")
        .def("cloneFrom", &PyDbNurbSurface::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbNurbSurface::cast).staticmethod("cast")
        ;
}

PyDbNurbSurface::PyDbNurbSurface()
    : PyDbSurface(new AcDbNurbSurface(), true)
{
}

PyDbNurbSurface::PyDbNurbSurface(AcDbNurbSurface* ptr, bool autoDelete)
    : PyDbSurface(ptr, autoDelete)
{
}

PyDbNurbSurface::PyDbNurbSurface(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbSurface(openAcDbObject<AcDbNurbSurface>(id, mode), false)
{
}

PyDbNurbSurface::PyDbNurbSurface(const PyDbObjectId& id)
    : PyDbNurbSurface(id, AcDb::OpenMode::kForRead)
{
}

std::string PyDbNurbSurface::className()
{
    return "AcDbNurbSurface";
}

PyRxClass PyDbNurbSurface::desc()
{
    return PyRxClass(AcDbNurbSurface::desc(), false);
}

PyDbNurbSurface PyDbNurbSurface::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbNurbSurface::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbNurbSurface(static_cast<AcDbNurbSurface*>(src.impObj()->clone()), true);
}

PyDbNurbSurface PyDbNurbSurface::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbNurbSurface>(src);
}

AcDbNurbSurface* PyDbNurbSurface::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<AcDbNurbSurface*>(m_pyImp.get());
}
//----------------------------------------------------------------------
//AcDbPlaneSurface  
void makePyDbPlaneSurfaceWrapper()
{
    class_<PyDbPlaneSurface, bases<PyDbSurface>>("PlaneSurface")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("className", &PyDbPlaneSurface::className).staticmethod("className")
        .def("desc", &PyDbPlaneSurface::desc).staticmethod("desc")
        .def("cloneFrom", &PyDbPlaneSurface::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbPlaneSurface::cast).staticmethod("cast")
        ;
}

PyDbPlaneSurface::PyDbPlaneSurface()
    : PyDbSurface(new AcDbPlaneSurface(), true)
{
}

PyDbPlaneSurface::PyDbPlaneSurface(AcDbPlaneSurface* ptr, bool autoDelete)
    : PyDbSurface(ptr, autoDelete)
{
}

PyDbPlaneSurface::PyDbPlaneSurface(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbSurface(openAcDbObject<AcDbPlaneSurface>(id, mode), false)
{
}

PyDbPlaneSurface::PyDbPlaneSurface(const PyDbObjectId& id)
    : PyDbPlaneSurface(id, AcDb::OpenMode::kForRead)
{
}

std::string PyDbPlaneSurface::className()
{
    return "AcDbPlaneSurface";
}

PyRxClass PyDbPlaneSurface::desc()
{
    return PyRxClass(AcDbPlaneSurface::desc(), false);
}

PyDbPlaneSurface PyDbPlaneSurface::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbPlaneSurface::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbPlaneSurface(static_cast<AcDbPlaneSurface*>(src.impObj()->clone()), true);
}

PyDbPlaneSurface PyDbPlaneSurface::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbPlaneSurface>(src);
}

AcDbPlaneSurface* PyDbPlaneSurface::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<AcDbPlaneSurface*>(m_pyImp.get());
}

//----------------------------------------------------------------------
//AcDbPlaneSurface  
void makePyDbRevolvedSurfaceWrapper()
{
    class_<PyDbRevolvedSurface, bases<PyDbSurface>>("RevolvedSurface")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("className", &PyDbRevolvedSurface::className).staticmethod("className")
        .def("desc", &PyDbRevolvedSurface::desc).staticmethod("desc")
        .def("cloneFrom", &PyDbRevolvedSurface::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbRevolvedSurface::cast).staticmethod("cast")
        ;
}

PyDbRevolvedSurface::PyDbRevolvedSurface()
    : PyDbSurface(new AcDbRevolvedSurface(), true)
{
}

PyDbRevolvedSurface::PyDbRevolvedSurface(AcDbRevolvedSurface* ptr, bool autoDelete)
    : PyDbSurface(ptr, autoDelete)
{
}

PyDbRevolvedSurface::PyDbRevolvedSurface(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbSurface(openAcDbObject<AcDbRevolvedSurface>(id, mode), false)
{
}

PyDbRevolvedSurface::PyDbRevolvedSurface(const PyDbObjectId& id)
    : PyDbRevolvedSurface(id, AcDb::OpenMode::kForRead)
{
}

std::string PyDbRevolvedSurface::className()
{
    return "AcDbPlaneSurface";
}

PyRxClass PyDbRevolvedSurface::desc()
{
    return PyRxClass(AcDbRevolvedSurface::desc(), false);
}

PyDbRevolvedSurface PyDbRevolvedSurface::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbRevolvedSurface::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbRevolvedSurface(static_cast<AcDbRevolvedSurface*>(src.impObj()->clone()), true);
}

PyDbRevolvedSurface PyDbRevolvedSurface::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbRevolvedSurface>(src);
}

AcDbRevolvedSurface* PyDbRevolvedSurface::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<AcDbRevolvedSurface*>(m_pyImp.get());
}

//----------------------------------------------------------------------
//AcDbPlaneSurface  
void makePyDbSweptSurfaceWrapper()
{
    class_<PyDbSweptSurface, bases<PyDbSurface>>("SweptSurface")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("className", &PyDbSweptSurface::className).staticmethod("className")
        .def("desc", &PyDbSweptSurface::desc).staticmethod("desc")
        .def("cloneFrom", &PyDbSweptSurface::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbSweptSurface::cast).staticmethod("cast")
        ;
}

PyDbSweptSurface::PyDbSweptSurface()
    : PyDbSurface(new AcDbPlaneSurface(), true)
{
}

PyDbSweptSurface::PyDbSweptSurface(AcDbSweptSurface* ptr, bool autoDelete)
    : PyDbSurface(ptr, autoDelete)
{
}

PyDbSweptSurface::PyDbSweptSurface(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbSurface(openAcDbObject<AcDbSweptSurface>(id, mode), false)
{
}

PyDbSweptSurface::PyDbSweptSurface(const PyDbObjectId& id)
    : PyDbSweptSurface(id, AcDb::OpenMode::kForRead)
{
}

std::string PyDbSweptSurface::className()
{
    return "AcDbPlaneSurface";
}

PyRxClass PyDbSweptSurface::desc()
{
    return PyRxClass(AcDbSweptSurface::desc(), false);
}

PyDbSweptSurface PyDbSweptSurface::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbSweptSurface::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbSweptSurface(static_cast<AcDbSweptSurface*>(src.impObj()->clone()), true);
}

PyDbSweptSurface PyDbSweptSurface::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbSweptSurface>(src);
}

AcDbSweptSurface* PyDbSweptSurface::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<AcDbSweptSurface*>(m_pyImp.get());
}
