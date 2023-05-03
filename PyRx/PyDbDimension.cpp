#include "stdafx.h"
#include "PyDbDimension.h"

#include "PyDbObjectId.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------
//PyDbDimension
void makePyDbDimensionWrapper()
{
    class_<PyDbDimension, bases<PyDbEntity>>("Dimension", no_init)
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("className", &PyDbDimension::className).staticmethod("className")
        ;
}

PyDbDimension::PyDbDimension(AcDbDimension* ptr, bool autoDelete)
    : PyDbEntity(ptr, autoDelete)
{
}

PyDbDimension::PyDbDimension(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbEntity(nullptr, false)
{
    AcDbDimension* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbDimension>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
}

boost::python::tuple PyDbDimension::textDefinedSize() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    double width = 1;
    double height = 1;
    impObj()->textDefinedSize(width, height);
    return boost::python::make_tuple(width, height);
#endif
}

void PyDbDimension::setTextDefinedSize(double width, double height)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    impObj()->setTextDefinedSize(width, height);
#endif
}

void PyDbDimension::resetTextDefinedSize()
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    impObj()->resetTextDefinedSize();
#endif
}

AcGePoint3d PyDbDimension::textPosition() const
{
    return impObj()->textPosition();
}

Acad::ErrorStatus PyDbDimension::setTextPosition(const AcGePoint3d& val)
{
    return impObj()->setTextPosition(val);
}

Adesk::Boolean PyDbDimension::isUsingDefaultTextPosition() const
{
    return impObj()->isUsingDefaultTextPosition();
}

Acad::ErrorStatus PyDbDimension::useSetTextPosition()
{
    return impObj()->useSetTextPosition();
}

Acad::ErrorStatus PyDbDimension::useDefaultTextPosition()
{
    return impObj()->useDefaultTextPosition();
}

Acad::ErrorStatus PyDbDimension::setUsingDefaultTextPosition(bool val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setUsingDefaultTextPosition(val);
#endif
}

AcGeVector3d PyDbDimension::normal() const
{
    return impObj()->normal();
}

Acad::ErrorStatus PyDbDimension::setNormal(const AcGeVector3d& val)
{
    return impObj()->setNormal(val);
}

double PyDbDimension::elevation() const
{
    return impObj()->elevation();
}

Acad::ErrorStatus PyDbDimension::setElevation(double val)
{
    return impObj()->setElevation(val);
}

std::string PyDbDimension::dimensionText() const
{
    return wstr_to_utf8(impObj()->dimensionText());
}

Acad::ErrorStatus PyDbDimension::setDimensionText(const std::string& val)
{
    return impObj()->setDimensionText(utf8_to_wstr(val).c_str());
}

double PyDbDimension::textRotation() const
{
    return impObj()->textRotation();
}

Acad::ErrorStatus PyDbDimension::setTextRotation(double val)
{
    return impObj()->setTextRotation(val);
}

PyDbObjectId PyDbDimension::dimensionStyle() const
{
    return PyDbObjectId(impObj()->dimensionStyle());
}

Acad::ErrorStatus PyDbDimension::setDimensionStyle(const PyDbObjectId& val)
{
    return impObj()->setDimensionStyle(val.m_id);
}

AcDbMText::AttachmentPoint PyDbDimension::textAttachment() const
{
    return impObj()->textAttachment();
}

Acad::ErrorStatus PyDbDimension::setTextAttachment(AcDbMText::AttachmentPoint eAtt)
{
    return impObj()->setTextAttachment(eAtt);
}

AcDb::LineSpacingStyle PyDbDimension::textLineSpacingStyle() const
{
    return impObj()->textLineSpacingStyle();
}

Acad::ErrorStatus PyDbDimension::setTextLineSpacingStyle(AcDb::LineSpacingStyle eStyle)
{
    return impObj()->setTextLineSpacingStyle(eStyle);
}

double PyDbDimension::textLineSpacingFactor() const
{
    return impObj()->textLineSpacingFactor();
}

Acad::ErrorStatus PyDbDimension::setTextLineSpacingFactor(double dFactor)
{
    return impObj()->setTextLineSpacingFactor(dFactor);
}

Acad::ErrorStatus PyDbDimension::setDimstyleData(const PyDbObjectId& newDataId)
{
    return impObj()->setDimstyleData(newDataId.m_id);
}

double PyDbDimension::horizontalRotation() const
{
    return impObj()->horizontalRotation();
}

Acad::ErrorStatus PyDbDimension::setHorizontalRotation(double newVal)
{
    return impObj()->setHorizontalRotation(newVal);
}

PyDbObjectId PyDbDimension::dimBlockId() const
{
    return PyDbObjectId(impObj()->dimBlockId());
}

Acad::ErrorStatus PyDbDimension::setDimBlockId(const PyDbObjectId& val)
{
    return impObj()->setDimBlockId(val.m_id);
}

AcGePoint3d PyDbDimension::dimBlockPosition() const
{
    return impObj()->dimBlockPosition();
}

Acad::ErrorStatus PyDbDimension::setDimBlockPosition(const AcGePoint3d& val)
{
    return impObj()->setDimBlockPosition(val);
}

Acad::ErrorStatus PyDbDimension::recomputeDimBlock1()
{
    return impObj()->recomputeDimBlock();
}

Acad::ErrorStatus PyDbDimension::recomputeDimBlock2(bool forceUpdate)
{
    return impObj()->recomputeDimBlock(forceUpdate);
}

Acad::ErrorStatus PyDbDimension::generateLayout()
{
    return impObj()->generateLayout();
}

double PyDbDimension::measurement()
{
    double m = 0;
    return impObj()->measurement(m);
    return m;
}

std::string PyDbDimension::className()
{
    return "AcDbRegion";
}

AcDbDimension* PyDbDimension::impObj() const
{
    if (m_pImp == nullptr)
        throw PyNullObject();
    return static_cast<AcDbDimension*>(m_pImp.get());
}

//-----------------------------------------------------------------------------------
//PyDb2LineAngularDimension
void makePyDb2LineAngularDimensionWrapper()
{
    class_<PyDb2LineAngularDimension, bases<PyDbDimension>>("LineAngularDimension2")
        .def(init<>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("className", &PyDb2LineAngularDimension::className).staticmethod("className")
        ;
}

PyDb2LineAngularDimension::PyDb2LineAngularDimension()
    : PyDbDimension(new AcDb2LineAngularDimension(), true)
{
}

PyDb2LineAngularDimension::PyDb2LineAngularDimension(AcDb2LineAngularDimension* ptr, bool autoDelete)
    : PyDbDimension(ptr, autoDelete)
{
}

PyDb2LineAngularDimension::PyDb2LineAngularDimension(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbDimension(nullptr, false)
{
    AcDb2LineAngularDimension* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDb2LineAngularDimension>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
}

std::string PyDb2LineAngularDimension::className()
{
    return "AcDb2LineAngularDimension";
}

AcDb2LineAngularDimension* PyDb2LineAngularDimension::impObj() const
{
    if (m_pImp == nullptr)
        throw PyNullObject();
    return static_cast<AcDb2LineAngularDimension*>(m_pImp.get());
}


//-----------------------------------------------------------------------------------
//AcDb3PointAngularDimension
void makeAcDb3PointAngularDimensionWrapper()
{
    class_<PyDb3PointAngularDimension, bases<PyDbDimension>>("Point3AngularDimension")
        .def(init<>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("className", &PyDb3PointAngularDimension::className).staticmethod("className")
        ;
}

PyDb3PointAngularDimension::PyDb3PointAngularDimension()
    : PyDbDimension(new AcDb3PointAngularDimension(), true)
{
}

PyDb3PointAngularDimension::PyDb3PointAngularDimension(AcDb3PointAngularDimension* ptr, bool autoDelete)
    : PyDbDimension(ptr, autoDelete)
{
}

PyDb3PointAngularDimension::PyDb3PointAngularDimension(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbDimension(nullptr, false)
{
    AcDb3PointAngularDimension* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDb3PointAngularDimension>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
}

std::string PyDb3PointAngularDimension::className()
{
    return "AcDb3PointAngularDimension";
}

AcDb3PointAngularDimension* PyDb3PointAngularDimension::impObj() const
{
    if (m_pImp == nullptr)
        throw PyNullObject();
    return static_cast<AcDb3PointAngularDimension*>(m_pImp.get());
}

//-----------------------------------------------------------------------------------
//AcDbAlignedDimension
void makeAlignedDimensionWrapper()
{
    class_<PyDbAlignedDimension, bases<PyDbDimension>>("AlignedDimension")
        .def(init<>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("className", &PyDbAlignedDimension::className).staticmethod("className")
        ;
}

PyDbAlignedDimension::PyDbAlignedDimension()
    : PyDbDimension(new AcDbAlignedDimension(), true)
{
}

PyDbAlignedDimension::PyDbAlignedDimension(AcDbAlignedDimension* ptr, bool autoDelete)
    : PyDbDimension(ptr, autoDelete)
{
}

PyDbAlignedDimension::PyDbAlignedDimension(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbDimension(nullptr, false)
{
    AcDbAlignedDimension* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbAlignedDimension>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
}

std::string PyDbAlignedDimension::className()
{
    return "AcDbAlignedDimension";
}

AcDbAlignedDimension* PyDbAlignedDimension::impObj() const
{
    if (m_pImp == nullptr)
        throw PyNullObject();
    return static_cast<AcDbAlignedDimension*>(m_pImp.get());
}

//-----------------------------------------------------------------------------------
//AcDbArcDimension
void makeArcDimensionWrapper()
{
    class_<PyDbArcDimension, bases<PyDbDimension>>("ArcDimension")
        .def(init<>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("className", &PyDbArcDimension::className).staticmethod("className")
        ;
}

PyDbArcDimension::PyDbArcDimension()
    : PyDbDimension(new AcDbArcDimension(), true)
{
}

PyDbArcDimension::PyDbArcDimension(AcDbArcDimension* ptr, bool autoDelete)
    : PyDbDimension(ptr, autoDelete)
{
}

PyDbArcDimension::PyDbArcDimension(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbDimension(nullptr, false)
{
    AcDbArcDimension* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbArcDimension>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
}

std::string PyDbArcDimension::className()
{
    return "AcDbArcDimension";
}

AcDbArcDimension* PyDbArcDimension::impObj() const
{
    if (m_pImp == nullptr)
        throw PyNullObject();
    return static_cast<AcDbArcDimension*>(m_pImp.get());
}

//-----------------------------------------------------------------------------------
//AcDbDiametricDimension
void makeDiametricDimensionWrapper()
{
    class_<PyDbDiametricDimension, bases<PyDbDimension>>("DiametricDimension")
        .def(init<>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("className", &PyDbDiametricDimension::className).staticmethod("className")
        ;
}

PyDbDiametricDimension::PyDbDiametricDimension()
    : PyDbDimension(new AcDbDiametricDimension(), true)
{
}

PyDbDiametricDimension::PyDbDiametricDimension(AcDbDiametricDimension* ptr, bool autoDelete)
    : PyDbDimension(ptr, autoDelete)
{
}

PyDbDiametricDimension::PyDbDiametricDimension(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbDimension(nullptr, false)
{
    AcDbDiametricDimension* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbDiametricDimension>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
}

std::string PyDbDiametricDimension::className()
{
    return "AcDbDiametricDimension";
}

AcDbDiametricDimension* PyDbDiametricDimension::impObj() const
{
    if (m_pImp == nullptr)
        throw PyNullObject();
    return static_cast<AcDbDiametricDimension*>(m_pImp.get());
}

//-----------------------------------------------------------------------------------
//AcDbOrdinateDimension
void makeOrdinateDimensionWrapper()
{
    class_<PyDbOrdinateDimension, bases<PyDbDimension>>("OrdinateDimension")
        .def(init<>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("className", &PyDbOrdinateDimension::className).staticmethod("className")
        ;
}

PyDbOrdinateDimension::PyDbOrdinateDimension()
    : PyDbDimension(new AcDbOrdinateDimension(), true)
{
}

PyDbOrdinateDimension::PyDbOrdinateDimension(AcDbOrdinateDimension* ptr, bool autoDelete)
    : PyDbDimension(ptr, autoDelete)
{
}

PyDbOrdinateDimension::PyDbOrdinateDimension(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbDimension(nullptr, false)
{
    AcDbOrdinateDimension* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbOrdinateDimension>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
}

std::string PyDbOrdinateDimension::className()
{
    return "AcDbOrdinateDimension";
}

AcDbOrdinateDimension* PyDbOrdinateDimension::impObj() const
{
    if (m_pImp == nullptr)
        throw PyNullObject();
    return static_cast<AcDbOrdinateDimension*>(m_pImp.get());
}

//-----------------------------------------------------------------------------------
//AcDbRadialDimension
void makeRadialDimensionWrapper()
{
    class_<PyDbRadialDimension, bases<PyDbDimension>>("RadialDimension")
        .def(init<>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("className", &PyDbRadialDimension::className).staticmethod("className")
        ;
}

PyDbRadialDimension::PyDbRadialDimension()
    : PyDbDimension(new AcDbRadialDimension(), true)
{
}

PyDbRadialDimension::PyDbRadialDimension(AcDbRadialDimension* ptr, bool autoDelete)
    : PyDbDimension(ptr, autoDelete)
{
}

PyDbRadialDimension::PyDbRadialDimension(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbDimension(nullptr, false)
{
    AcDbRadialDimension* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbRadialDimension>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
}

std::string PyDbRadialDimension::className()
{
    return "AcDbRadialDimension";
}

AcDbRadialDimension* PyDbRadialDimension::impObj() const
{
    if (m_pImp == nullptr)
        throw PyNullObject();
    return static_cast<AcDbRadialDimension*>(m_pImp.get());
}

//-----------------------------------------------------------------------------------
//AcDbRadialDimensionLarge
void makeRadialDimensionLargeWrapper()
{
    class_<PyDbRadialDimensionLarge, bases<PyDbDimension>>("RadialDimensionLarge")
        .def(init<>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("className", &PyDbRadialDimensionLarge::className).staticmethod("className")
        ;
}

PyDbRadialDimensionLarge::PyDbRadialDimensionLarge()
    : PyDbDimension(new AcDbRadialDimensionLarge(), true)
{
}

PyDbRadialDimensionLarge::PyDbRadialDimensionLarge(AcDbRadialDimensionLarge* ptr, bool autoDelete)
    : PyDbDimension(ptr, autoDelete)
{
}

PyDbRadialDimensionLarge::PyDbRadialDimensionLarge(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbDimension(nullptr, false)
{
    AcDbRadialDimensionLarge* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbRadialDimensionLarge>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
}

std::string PyDbRadialDimensionLarge::className()
{
    return "AcDbRadialDimension";
}

AcDbRadialDimensionLarge* PyDbRadialDimensionLarge::impObj() const
{
    if (m_pImp == nullptr)
        throw PyNullObject();
    return static_cast<AcDbRadialDimensionLarge*>(m_pImp.get());
}


//-----------------------------------------------------------------------------------
//AcDbRotatedDimension
void makeRotatedDimensionWrapper()
{
    class_<PyDbRotatedDimension, bases<PyDbDimension>>("RotatedDimension")
        .def(init<>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("className", &PyDbRotatedDimension::className).staticmethod("className")
        ;
}

PyDbRotatedDimension::PyDbRotatedDimension()
    : PyDbDimension(new AcDbRotatedDimension(), true)
{
}

PyDbRotatedDimension::PyDbRotatedDimension(AcDbRotatedDimension* ptr, bool autoDelete)
    : PyDbDimension(ptr, autoDelete)
{
}

PyDbRotatedDimension::PyDbRotatedDimension(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbDimension(nullptr, false)
{
    AcDbRotatedDimension* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbRotatedDimension>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    this->resetImp(pobj, false, true);
}

std::string PyDbRotatedDimension::className()
{
    return "AcDbRotatedDimension";
}

AcDbRotatedDimension* PyDbRotatedDimension::impObj() const
{
    if (m_pImp == nullptr)
        throw PyNullObject();
    return static_cast<AcDbRotatedDimension*>(m_pImp.get());
}
