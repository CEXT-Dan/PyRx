#include "stdafx.h"
#include "PyDbImage.h"
#include "PyDbObjectId.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------
//PyDbImage
void makePyDbImageWrapper()
{
    class_<PyDbImage, bases<PyDbEntity>>("Image", boost::python::no_init)
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("className", &PyDbImage::className).staticmethod("className")
        .def("desc", &PyDbImage::desc).staticmethod("desc")
        .def("cloneFrom", &PyDbImage::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbImage::cast).staticmethod("cast")
        ;
}

PyDbImage::PyDbImage(AcDbImage* ptr, bool autoDelete)
    : PyDbEntity(ptr, autoDelete)
{
}

PyDbImage::PyDbImage(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbEntity(nullptr, false)
{
    AcDbImage* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbImage>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
}

std::string PyDbImage::className()
{
    return "AcDbImage";
}

PyRxClass PyDbImage::desc()
{
    return PyRxClass(AcDbImage::desc(), false);
}

PyDbImage PyDbImage::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbImage::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbImage(static_cast<AcDbImage*>(src.impObj()->clone()), true);
}

PyDbImage PyDbImage::cast(const PyRxObject& src)
{
    PyDbImage dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbImage* PyDbImage::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbImage*>(m_pyImp.get());
}


//-----------------------------------------------------------------------------------
//PyDbRasterImageDef
void makePyDbRasterImageDefWrapper()
{
    class_<PyDbRasterImageDef, bases<PyDbObject>>("RasterImageDef")
        .def(init<>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("className", &PyDbRasterImageDef::className).staticmethod("className")
        .def("desc", &PyDbRasterImageDef::desc).staticmethod("desc")
        .def("cloneFrom", &PyDbRasterImageDef::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbRasterImageDef::cast).staticmethod("cast")
        ;
}

PyDbRasterImageDef::PyDbRasterImageDef()
    : PyDbObject(new AcDbRasterImageDef(), true)
{
}

PyDbRasterImageDef::PyDbRasterImageDef(AcDbRasterImageDef* ptr, bool autoDelete)
    : PyDbObject(ptr, autoDelete)
{
}

PyDbRasterImageDef::PyDbRasterImageDef(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbObject(nullptr, false)
{
    AcDbRasterImageDef* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbRasterImageDef>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
}

std::string PyDbRasterImageDef::className()
{
    return "AcDbRasterImageDef";
}

PyRxClass PyDbRasterImageDef::desc()
{
    return PyRxClass(AcDbRasterImageDef::desc(), false);
}

PyDbRasterImageDef PyDbRasterImageDef::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbRasterImageDef::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbRasterImageDef(static_cast<AcDbRasterImageDef*>(src.impObj()->clone()), true);
}

PyDbRasterImageDef PyDbRasterImageDef::cast(const PyRxObject& src)
{
    PyDbRasterImageDef dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbRasterImageDef* PyDbRasterImageDef::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbRasterImageDef*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//AcDbRasterImage
void makePyDbRasterImageWrapper()
{
    class_<PyDbRasterImage, bases<PyDbImage>>("RasterImage")
        .def(init<>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("className", &PyDbRasterImage::className).staticmethod("className")
        .def("desc", &PyDbRasterImage::desc).staticmethod("desc")
        .def("cloneFrom", &PyDbRasterImage::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbRasterImage::cast).staticmethod("cast")
        ;
}

PyDbRasterImage::PyDbRasterImage()
  : PyDbImage(new AcDbRasterImage(), true)
{
}

PyDbRasterImage::PyDbRasterImage(AcDbRasterImage* ptr, bool autoDelete)
    : PyDbImage(ptr, autoDelete)
{

}

PyDbRasterImage::PyDbRasterImage(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbImage(nullptr, false)
{
    AcDbRasterImage* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbRasterImage>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
}

std::string PyDbRasterImage::className()
{
    return "AcDbRasterImage";
}

PyRxClass PyDbRasterImage::desc()
{
    return PyRxClass(AcDbRasterImage::desc(), false);
}

PyDbRasterImage PyDbRasterImage::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbRasterImage::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbRasterImage(static_cast<AcDbRasterImage*>(src.impObj()->clone()), true);
}

PyDbRasterImage PyDbRasterImage::cast(const PyRxObject& src)
{
    PyDbRasterImage dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbRasterImage* PyDbRasterImage::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbRasterImage*>(m_pyImp.get());
}
