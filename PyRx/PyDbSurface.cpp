#include "stdafx.h"
#include "PyDbSurface.h"
#include "PyDbObjectId.h"

#include "dbextrudedsurf.h"
#include "dbloftedsurf.h"
#include "dbnurbsurf.h"
#include "dbplanesurf.h"
#include "dbrevolvedsurf.h"
#include "dbsweptsurf.h"

using namespace boost::python;
//----------------------------------------------------------------------
//PyDbSurface
void makePyDbSurfaceWrapper()
{
    class_<PyDbSurface, bases<PyDbEntity>>("Surface")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("className", &PyDbSurface::className).staticmethod("className")
        .def("desc", &PyDbSurface::desc).staticmethod("desc")
        .def("cloneFrom", &PyDbSurface::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbSurface::cast).staticmethod("cast")
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
    : PyDbEntity(nullptr, false)
{
    AcDbSurface* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbSurface>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
}

PyDbSurface::PyDbSurface(const PyDbObjectId& id)
    : PyDbSurface(id, AcDb::OpenMode::kForRead)
{
}

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
    PyDbSurface dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbSurface* PyDbSurface::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbSurface*>(m_pyImp.get());
}

//----------------------------------------------------------------------
//AcDbExtrudedSurface
void makeAcDbExtrudedSurfaceWrapper()
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
    : PyDbSurface(nullptr, false)
{
    AcDbSurface* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbSurface>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
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
    PyDbExtrudedSurface dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbExtrudedSurface* PyDbExtrudedSurface::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbExtrudedSurface*>(m_pyImp.get());
}

//----------------------------------------------------------------------
//AcDbLoftedSurface 
void makeAcDbLoftedSurfaceWrapper()
{
#if defined(GRXAPP) || defined(ZRXAPP)
#else
    class_<PyDbLoftedSurface, bases<PyDbSurface>>("LoftedSurface")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("className", &PyDbLoftedSurface::className).staticmethod("className")
        .def("desc", &PyDbLoftedSurface::desc).staticmethod("desc")
        .def("cloneFrom", &PyDbLoftedSurface::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbLoftedSurface::cast).staticmethod("cast")
        ;
#endif
}

#if defined(GRXAPP) || defined(ZRXAPP)
#else
PyDbLoftedSurface::PyDbLoftedSurface()
    : PyDbSurface(new AcDbLoftedSurface(), true)
{
}

PyDbLoftedSurface::PyDbLoftedSurface(AcDbLoftedSurface* ptr, bool autoDelete)
    : PyDbSurface(ptr, autoDelete)
{
}

PyDbLoftedSurface::PyDbLoftedSurface(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbSurface(nullptr, false)
{
    AcDbLoftedSurface* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbLoftedSurface>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
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
    PyDbLoftedSurface dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbLoftedSurface* PyDbLoftedSurface::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbLoftedSurface*>(m_pyImp.get());
}
#endif


//----------------------------------------------------------------------
//PyDbNurbSurface 
void makePyDbNurbSurfaceWrapper()
{
#if defined(GRXAPP) || defined(ZRXAPP)
#else
    class_<PyDbNurbSurface, bases<PyDbSurface>>("NurbSurface")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("className", &PyDbNurbSurface::className).staticmethod("className")
        .def("desc", &PyDbNurbSurface::desc).staticmethod("desc")
        .def("cloneFrom", &PyDbNurbSurface::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbNurbSurface::cast).staticmethod("cast")
        ;
#endif
}


#if defined(GRXAPP) || defined(ZRXAPP)
#else
PyDbNurbSurface::PyDbNurbSurface()
    : PyDbSurface(new AcDbNurbSurface(), true)
{
}

PyDbNurbSurface::PyDbNurbSurface(AcDbNurbSurface* ptr, bool autoDelete)
    : PyDbSurface(ptr, autoDelete)
{
}

PyDbNurbSurface::PyDbNurbSurface(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbSurface(nullptr, false)
{
    AcDbNurbSurface* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbNurbSurface>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
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
    PyDbNurbSurface dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbNurbSurface* PyDbNurbSurface::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbNurbSurface*>(m_pyImp.get());
}
#endif

//----------------------------------------------------------------------
//AcDbPlaneSurface  
void makePyDbPlaneSurfaceWrapper()
{
#if defined(GRXAPP) || defined(ZRXAPP)
#else
    class_<PyDbPlaneSurface, bases<PyDbSurface>>("PlaneSurface")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("className", &PyDbPlaneSurface::className).staticmethod("className")
        .def("desc", &PyDbPlaneSurface::desc).staticmethod("desc")
        .def("cloneFrom", &PyDbPlaneSurface::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbPlaneSurface::cast).staticmethod("cast")
        ;
#endif
}

#if defined(GRXAPP) || defined(ZRXAPP)
#else
PyDbPlaneSurface::PyDbPlaneSurface()
    : PyDbSurface(new AcDbPlaneSurface(), true)
{
}

PyDbPlaneSurface::PyDbPlaneSurface(AcDbPlaneSurface* ptr, bool autoDelete)
    : PyDbSurface(ptr, autoDelete)
{
}

PyDbPlaneSurface::PyDbPlaneSurface(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbSurface(nullptr, false)
{
    AcDbPlaneSurface* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbPlaneSurface>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
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
    PyDbPlaneSurface dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbPlaneSurface* PyDbPlaneSurface::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbPlaneSurface*>(m_pyImp.get());
}
#endif


//----------------------------------------------------------------------
//AcDbPlaneSurface  
void makePyDbRevolvedSurfaceWrapper()
{
#if defined(GRXAPP) || defined(ZRXAPP)
#else
    class_<PyDbRevolvedSurface, bases<PyDbSurface>>("RevolvedSurface")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("className", &PyDbRevolvedSurface::className).staticmethod("className")
        .def("desc", &PyDbRevolvedSurface::desc).staticmethod("desc")
        .def("cloneFrom", &PyDbRevolvedSurface::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbRevolvedSurface::cast).staticmethod("cast")
        ;
#endif
}

#if defined(GRXAPP) || defined(ZRXAPP)
#else
PyDbRevolvedSurface::PyDbRevolvedSurface()
    : PyDbSurface(new AcDbPlaneSurface(), true)
{
}

PyDbRevolvedSurface::PyDbRevolvedSurface(AcDbRevolvedSurface* ptr, bool autoDelete)
    : PyDbSurface(ptr, autoDelete)
{
}

PyDbRevolvedSurface::PyDbRevolvedSurface(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbSurface(nullptr, false)
{
    AcDbPlaneSurface* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbPlaneSurface>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
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
    PyDbRevolvedSurface dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbRevolvedSurface* PyDbRevolvedSurface::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbRevolvedSurface*>(m_pyImp.get());
}
#endif

//----------------------------------------------------------------------
//AcDbPlaneSurface  
void makePyDbSweptSurfaceWrapper()
{
#if defined(GRXAPP) || defined(ZRXAPP)
#else
    class_<PyDbSweptSurface, bases<PyDbSurface>>("SweptSurface")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("className", &PyDbSweptSurface::className).staticmethod("className")
        .def("desc", &PyDbSweptSurface::desc).staticmethod("desc")
        .def("cloneFrom", &PyDbSweptSurface::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbSweptSurface::cast).staticmethod("cast")
        ;
#endif
}

#if defined(GRXAPP) || defined(ZRXAPP)
#else
PyDbSweptSurface::PyDbSweptSurface()
    : PyDbSurface(new AcDbPlaneSurface(), true)
{
}

PyDbSweptSurface::PyDbSweptSurface(AcDbSweptSurface* ptr, bool autoDelete)
    : PyDbSurface(ptr, autoDelete)
{
}

PyDbSweptSurface::PyDbSweptSurface(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbSurface(nullptr, false)
{
    AcDbPlaneSurface* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbPlaneSurface>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
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
    PyDbSweptSurface dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbSweptSurface* PyDbSweptSurface::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbSweptSurface*>(m_pyImp.get());
}
#endif

