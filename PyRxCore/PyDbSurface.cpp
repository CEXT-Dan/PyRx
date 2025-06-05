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
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    PyDocString DS("Surface");
    class_<PyDbSurface, bases<PyDbEntity>>("Surface")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.CTOR(ctords, 8909)))
        .def("getArea", &PyDbSurface::getArea, DS.ARGS())
        .def("uIsolineDensity", &PyDbSurface::uIsolineDensity, DS.ARGS())
        .def("setUIsolineDensity", &PyDbSurface::setUIsolineDensity, DS.ARGS({ "numIsolines: int" }))
        .def("vIsolineDensity", &PyDbSurface::vIsolineDensity, DS.ARGS())
        .def("setVIsolineDensity", &PyDbSurface::setVIsolineDensity, DS.ARGS({ "numIsolines: int" }))
        .def("getWireframeType", &PyDbSurface::getWireframeType, DS.ARGS())
        .def("setWireframeType", &PyDbSurface::setWireframeType, DS.ARGS({ "val: PyDb.SurfaceWireframeType" }))
        .def("getPerimeter", &PyDbSurface::getPerimeter, DS.ARGS())
        .def("creationActionBodyId", &PyDbSurface::creationActionBodyId, DS.ARGS())
        .def("modificationActionBodyIds", &PyDbSurface::modificationActionBodyIds, DS.ARGS())
        .def("extendEdges", &PyDbSurface::extendEdges, DS.ARGS({ "subEnts: list[PyDb.FullSubentPath]","extDist: float","extOption: SurfaceEdgeExtensionType","bAssociativeEnabled: bool" }))
        .def("rayTest", &PyDbSurface::rayTest, DS.ARGS({ "rayBasePoint: PyGe.Point3d","rayDir: PyGe.Vector3d","rayRadius: float" }))
        .def("projectOnToSurface", &PyDbSurface::projectOnToSurface, DS.ARGS({ "object: PyDb.Entity","projectionDirection: PyGe.Vector3d" }))
        .def("createFrom", &PyDbSurface::createFrom, DS.SARGS({ "val: PyDb.Entity" })).staticmethod("createFrom")
#if !defined(_BRXTARGET250)
        .def("createExtrudedSurface", &PyDbSurface::createExtrudedSurface,
            DS.SARGS({ "pSweep: PyDb.Profile3d","directionVec: PyGe.Vector3d","sweepOptions: PyDb.SweepOptions" }, 8933)).staticmethod("createExtrudedSurface")
#endif
#if !defined(_BRXTARGET250)
        .def("createRevolvedSurface", &PyDbSurface::createRevolvedSurface,
            DS.SARGS({ "pRev: PyDb.Profile3d","axisPnt: PyGe.Point3d","axisDir: PyGe.Vector3d","revAngle: float","startAngle: float","sweepOptions: PyDb.SweepOptions" }, 8941)).staticmethod("createRevolvedSurface")
#endif
        .def("className", &PyDbSurface::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbSurface::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbSurface::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbSurface::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
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

PyDbSurface::PyDbSurface(const PyDbObjectId& id)
    : PyDbEntity(openAcDbObject<AcDbSurface>(id), false)
{
}

PyDbSurface::PyDbSurface(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbEntity(openAcDbObject<AcDbSurface>(id, mode), false)
{
}

PyDbSurface::PyDbSurface(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbEntity(openAcDbObject<AcDbSurface>(id, mode, erased), false)
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

void PyDbSurface::setUIsolineDensity(Adesk::UInt16 numIsolines) const
{
    PyThrowBadEs(impObj()->setUIsolineDensity(numIsolines));
}

Adesk::UInt16 PyDbSurface::vIsolineDensity() const
{
    return impObj()->vIsolineDensity();
}

void PyDbSurface::setVIsolineDensity(Adesk::UInt16 numIsolines) const
{
    PyThrowBadEs(impObj()->setVIsolineDensity(numIsolines));
}

AcDbSurface::WireframeType PyDbSurface::getWireframeType() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return impObj()->getWireframeType();
#endif
}

void PyDbSurface::setWireframeType(AcDbSurface::WireframeType type) const
{
#if defined(_BRXTARGET250)
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
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    return PyDbObjectId(impObj()->creationActionBodyId());
#endif
}

boost::python::list PyDbSurface::modificationActionBodyIds() const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    AcDbObjectIdArray modificationActionBodyIds;
    PyThrowBadEs(impObj()->modificationActionBodyIds(modificationActionBodyIds));
    return ObjectIdArrayToPyList(modificationActionBodyIds);
#endif
}

void PyDbSurface::extendEdges(boost::python::list& edges, double extDist, AcDbSurface::EdgeExtensionType extOption, bool bAssociativeEnabled) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    auto _edges = PyListToPyDbFullSubentPathArray(edges);
    PyThrowBadEs(impObj()->extendEdges(_edges, extDist, extOption, bAssociativeEnabled));
#endif
}

boost::python::tuple PyDbSurface::rayTest(const AcGePoint3d& rayBasePoint, const AcGeVector3d& rayDir, double rayRadius) const
{
#if defined(_BRXTARGET250)
    throw PyNotimplementedByHost();
#else
    PyAutoLockGIL lock;
    AcArray<AcDbSubentId> subEntIds;
    AcGeDoubleArray parameters;
    PyThrowBadEs(impObj()->rayTest(rayBasePoint, rayDir, rayRadius, subEntIds, parameters));
    return boost::python::make_tuple(SubentIdArrayToPyList(subEntIds), DoubleArrayToPyList(parameters));
#endif
}

boost::python::list PyDbSurface::projectOnToSurface(const PyDbEntity& ent, const AcGeVector3d& projectionDirection) const
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

#if !defined(_BRXTARGET250)
PyDbExtrudedSurface PyDbSurface::createExtrudedSurface(PyDb3dProfile& pSweep, const AcGeVector3d& directionVec, PyDbSweepOptions& sweepOptions)
{
    AcDbExtrudedSurface* newExtrudedSurface = nullptr;
    PyThrowBadEs(AcDbSurface::createExtrudedSurface(pSweep.impObj(), directionVec, *sweepOptions.impObj(), newExtrudedSurface));
    return PyDbExtrudedSurface(newExtrudedSurface, true);
}
#endif

#if !defined(_BRXTARGET250)
PyDbRevolvedSurface PyDbSurface::createRevolvedSurface(PyDb3dProfile& pRev, const AcGePoint3d& axisPnt, const AcGeVector3d& axisDir, double revAngle, double startAngle, PyDbRevolveOptions& options)
{
    AcDbRevolvedSurface* newSurface = nullptr;
    PyThrowBadEs(AcDbSurface::createRevolvedSurface(pRev.impObj(), axisPnt, axisDir, revAngle, startAngle, *options.impObj(), newSurface));
    return PyDbRevolvedSurface(newSurface, true);
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
    return PyDbObjectCloneFrom<PyDbSurface, AcDbSurface>(src);
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
    PyDocString DS("ExtrudedSurface");
    class_<PyDbExtrudedSurface, bases<PyDbSurface>>("ExtrudedSurface")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: PyDb.ObjectId", "mode: PyDb.OpenMode = PyDb.OpenMode.kForRead", "erased: bool=False" })))
        .def("className", &PyDbExtrudedSurface::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbExtrudedSurface::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbExtrudedSurface::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbExtrudedSurface::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
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

PyDbExtrudedSurface::PyDbExtrudedSurface(const PyDbObjectId& id)
    : PyDbSurface(openAcDbObject<AcDbExtrudedSurface>(id), false)
{
}

PyDbExtrudedSurface::PyDbExtrudedSurface(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbSurface(openAcDbObject<AcDbExtrudedSurface>(id, mode), false)
{
}

PyDbExtrudedSurface::PyDbExtrudedSurface(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbSurface(openAcDbObject<AcDbExtrudedSurface>(id, mode, erased), false)
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
    return PyDbObjectCloneFrom<PyDbExtrudedSurface, AcDbExtrudedSurface>(src);
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
    PyDocString DS("LoftedSurface");
    class_<PyDbLoftedSurface, bases<PyDbSurface>>("LoftedSurface")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: PyDb.ObjectId", "mode: PyDb.OpenMode = PyDb.OpenMode.kForRead", "erased: bool=False" })))
        .def("className", &PyDbLoftedSurface::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbLoftedSurface::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbLoftedSurface::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbLoftedSurface::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
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

PyDbLoftedSurface::PyDbLoftedSurface(const PyDbObjectId& id)
    : PyDbSurface(openAcDbObject<AcDbLoftedSurface>(id), false)
{
}

PyDbLoftedSurface::PyDbLoftedSurface(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbSurface(openAcDbObject<AcDbLoftedSurface>(id, mode), false)
{
}

PyDbLoftedSurface::PyDbLoftedSurface(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbSurface(openAcDbObject<AcDbLoftedSurface>(id, mode, erased), false)
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
    return PyDbObjectCloneFrom<PyDbLoftedSurface, AcDbLoftedSurface>(src);
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
    PyDocString DS("NurbSurface");
    class_<PyDbNurbSurface, bases<PyDbSurface>>("NurbSurface")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: PyDb.ObjectId", "mode: PyDb.OpenMode = PyDb.OpenMode.kForRead", "erased: bool=False" })))
        .def("className", &PyDbNurbSurface::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbNurbSurface::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbNurbSurface::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbNurbSurface::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
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

PyDbNurbSurface::PyDbNurbSurface(const PyDbObjectId& id)
    : PyDbSurface(openAcDbObject<AcDbNurbSurface>(id), false)
{
}

PyDbNurbSurface::PyDbNurbSurface(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbSurface(openAcDbObject<AcDbNurbSurface>(id, mode), false)
{
}

PyDbNurbSurface::PyDbNurbSurface(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbSurface(openAcDbObject<AcDbNurbSurface>(id, mode, erased), false)
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
    return PyDbObjectCloneFrom<PyDbNurbSurface, AcDbNurbSurface>(src);
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
    PyDocString DS("PlaneSurface");
    class_<PyDbPlaneSurface, bases<PyDbSurface>>("PlaneSurface")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: PyDb.ObjectId", "mode: PyDb.OpenMode = PyDb.OpenMode.kForRead", "erased: bool=False" })))
        .def("className", &PyDbPlaneSurface::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbPlaneSurface::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbPlaneSurface::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbPlaneSurface::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
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

PyDbPlaneSurface::PyDbPlaneSurface(const PyDbObjectId& id)
    : PyDbSurface(openAcDbObject<AcDbPlaneSurface>(id), false)
{
}

PyDbPlaneSurface::PyDbPlaneSurface(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbSurface(openAcDbObject<AcDbPlaneSurface>(id, mode), false)
{
}

PyDbPlaneSurface::PyDbPlaneSurface(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbSurface(openAcDbObject<AcDbPlaneSurface>(id, mode, erased), false)
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
    return PyDbObjectCloneFrom<PyDbPlaneSurface, AcDbPlaneSurface>(src);
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
    PyDocString DS("RevolvedSurface");
    class_<PyDbRevolvedSurface, bases<PyDbSurface>>("RevolvedSurface")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: PyDb.ObjectId", "mode: PyDb.OpenMode = PyDb.OpenMode.kForRead", "erased: bool=False" })))
        .def("className", &PyDbRevolvedSurface::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbRevolvedSurface::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbRevolvedSurface::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbRevolvedSurface::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
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

PyDbRevolvedSurface::PyDbRevolvedSurface(const PyDbObjectId& id)
    : PyDbSurface(openAcDbObject<AcDbRevolvedSurface>(id), false)
{
}

PyDbRevolvedSurface::PyDbRevolvedSurface(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbSurface(openAcDbObject<AcDbRevolvedSurface>(id, mode), false)
{
}

PyDbRevolvedSurface::PyDbRevolvedSurface(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbSurface(openAcDbObject<AcDbRevolvedSurface>(id, mode, erased), false)
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
    return PyDbObjectCloneFrom<PyDbRevolvedSurface, AcDbRevolvedSurface>(src);
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
    PyDocString DS("SweptSurface");
    class_<PyDbSweptSurface, bases<PyDbSurface>>("SweptSurface")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: PyDb.ObjectId", "mode: PyDb.OpenMode = PyDb.OpenMode.kForRead", "erased: bool=False" })))
        .def("className", &PyDbSweptSurface::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbSweptSurface::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbSweptSurface::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbSweptSurface::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
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

PyDbSweptSurface::PyDbSweptSurface(const PyDbObjectId& id)
    : PyDbSurface(openAcDbObject<AcDbSweptSurface>(id), false)
{
}

PyDbSweptSurface::PyDbSweptSurface(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbSurface(openAcDbObject<AcDbSweptSurface>(id, mode), false)
{
}

PyDbSweptSurface::PyDbSweptSurface(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbSurface(openAcDbObject<AcDbSweptSurface>(id, mode, erased), false)
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
    return PyDbObjectCloneFrom<PyDbSweptSurface, AcDbSweptSurface>(src);
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
