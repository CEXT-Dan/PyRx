#include "stdafx.h"
#include "PyDbSurface.h"
#include "PyDbObjectId.h"

#ifdef SOLID3D_SUPPORT

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
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("className", &PyDbSurface::className).staticmethod("className")
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

std::string PyDbSurface::className()
{
    return "AcDbSurface";
}

AcDbSurface* PyDbSurface::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbSurface*>(m_pImp.get());
}

//----------------------------------------------------------------------
//AcDbExtrudedSurface
void makeAcDbExtrudedSurfaceWrapper()
{
    class_<PyDbExtrudedSurface, bases<PyDbSurface>>("ExtrudedSurface")
        .def(init<>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("className", &PyDbExtrudedSurface::className).staticmethod("className")
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
std::string PyDbExtrudedSurface::className()
{
    return "AcDbExtrudedSurface";
}

AcDbExtrudedSurface* PyDbExtrudedSurface::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbExtrudedSurface*>(m_pImp.get());
}

//----------------------------------------------------------------------
//AcDbLoftedSurface 
void makeAcDbLoftedSurfaceWrapper()
{
#if defined(GRXAPP) || defined(ZRXAPP)
#else
    class_<PyDbLoftedSurface, bases<PyDbSurface>>("LoftedSurface")
        .def(init<>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("className", &PyDbLoftedSurface::className).staticmethod("className")
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

std::string PyDbLoftedSurface::className()
{
    return "AcDbLoftedSurface";
}

AcDbLoftedSurface* PyDbLoftedSurface::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbLoftedSurface*>(m_pImp.get());
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
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("className", &PyDbNurbSurface::className).staticmethod("className")
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

std::string PyDbNurbSurface::className()
{
    return "AcDbNurbSurface";
}

AcDbNurbSurface* PyDbNurbSurface::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbNurbSurface*>(m_pImp.get());
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
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("className", &PyDbPlaneSurface::className).staticmethod("className")
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

std::string PyDbPlaneSurface::className()
{
    return "AcDbPlaneSurface";
}

AcDbPlaneSurface* PyDbPlaneSurface::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbPlaneSurface*>(m_pImp.get());
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
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("className", &PyDbRevolvedSurface::className).staticmethod("className")
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

std::string PyDbRevolvedSurface::className()
{
    return "AcDbPlaneSurface";
}

AcDbRevolvedSurface* PyDbRevolvedSurface::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbRevolvedSurface*>(m_pImp.get());
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
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("className", &PyDbSweptSurface::className).staticmethod("className")
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

std::string PyDbSweptSurface::className()
{
    return "AcDbPlaneSurface";
}

AcDbSweptSurface* PyDbSweptSurface::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbSweptSurface*>(m_pImp.get());
}
#endif

#endif //SOLID3D_SUPPORT