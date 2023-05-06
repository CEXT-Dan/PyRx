#include "stdafx.h"
#include "PyDb3dSolid.h"
#include "PyDbObjectId.h"

#ifdef SOLID3D_SUPPORT

using namespace boost::python;

void makePyDb3dSolidWrapper()
{
    class_<PyDb3dSolid, bases<PyDbEntity>>("3dSolid")
        .def(init<>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("createBox", &PyDb3dSolid::createBox)
        .def("createFrustum", &PyDb3dSolid::createFrustum)
        .def("createSphere", &PyDb3dSolid::createSphere)
        .def("createTorus", &PyDb3dSolid::createTorus)
        .def("createPyramid", &PyDb3dSolid::createPyramid1)
        .def("createPyramid", &PyDb3dSolid::createPyramid2)
        .def("createWedge", &PyDb3dSolid::createWedge)
        .def("className", &PyDb3dSolid::className).staticmethod("className")
        ;
}

PyDb3dSolid::PyDb3dSolid(AcDb3dSolid* ptr, bool autoDelete)
    : PyDbEntity(ptr, autoDelete)
{
}

PyDb3dSolid::PyDb3dSolid()
    : PyDbEntity(new AcDb3dSolid(), true)
{
}

PyDb3dSolid::PyDb3dSolid(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbEntity(nullptr, false)
{
    AcDb3dSolid* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDb3dSolid>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
}

Acad::ErrorStatus PyDb3dSolid::createBox(double xLen, double yLen, double zLen)
{
    return impObj()->createBox(xLen, yLen, zLen);
}

Acad::ErrorStatus PyDb3dSolid::createFrustum(double height, double xRadius, double yRadius, double topXRadius)
{
    return impObj()->createFrustum(height, xRadius, yRadius, topXRadius);
}

Acad::ErrorStatus PyDb3dSolid::createSphere(double radius)
{
    return impObj()->createSphere(radius);
}

Acad::ErrorStatus PyDb3dSolid::createTorus(double majorRadius, double minorRadius)
{
    return impObj()->createTorus(majorRadius, minorRadius);
}

Acad::ErrorStatus PyDb3dSolid::createPyramid1(double height, int sides, double radius)
{
    return impObj()->createPyramid(height, sides, radius);
}

Acad::ErrorStatus PyDb3dSolid::createPyramid2(double height, int sides, double radius, double topRadius)
{
    return impObj()->createPyramid(height, sides, radius, topRadius);
}

Acad::ErrorStatus PyDb3dSolid::createWedge(double xLen, double yLen, double zLen)
{
    return impObj()->createWedge(xLen, yLen, zLen);
}

std::string PyDb3dSolid::className()
{
    return "AcDb3dSolid";
}

AcDb3dSolid* PyDb3dSolid::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDb3dSolid*>(m_pImp.get());
}



//-----------------------------------------------------------------------------------
//PyDbRegion
void makePyDbRegionWrapper()
{
    class_<PyDbRegion, bases<PyDbEntity>>("Region")
        .def(init<>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("className", &PyDbRegion::className).staticmethod("className")
        ;
}

PyDbRegion::PyDbRegion()
    : PyDbEntity(new AcDbRegion(), true)
{
}

PyDbRegion::PyDbRegion(AcDbRegion* ptr, bool autoDelete)
    : PyDbEntity(ptr, autoDelete)
{
}

PyDbRegion::PyDbRegion(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbEntity(nullptr, false)
{
    AcDbRegion* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbRegion>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
}

std::string PyDbRegion::className()
{
    return "AcDbRegion";
}

AcDbRegion* PyDbRegion::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbRegion*>(m_pImp.get());
}

//-----------------------------------------------------------------------------------
//PyDbBody
void makeAcDbBodyWrapper()
{
    class_<PyDbBody, bases<PyDbEntity>>("Body")
        .def(init<>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("className", &PyDbBody::className).staticmethod("className")
        ;
}

PyDbBody::PyDbBody()
    : PyDbEntity(new AcDbBody(), true)
{
}

PyDbBody::PyDbBody(AcDbBody* ptr, bool autoDelete)
    : PyDbEntity(ptr, autoDelete)
{
}

PyDbBody::PyDbBody(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbEntity(nullptr, false)
{
    AcDbBody* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbBody>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
}

std::string PyDbBody::className()
{
    return "AcDbBody";
}

AcDbBody* PyDbBody::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbBody*>(m_pImp.get());
}


#endif// SOLID3D_SUPPORT
