#include "stdafx.h"
#include "PyAcadDimension.h"
#include "PyAcadDimensionImpl.h"
#include "PyAcadEntityImpl.h"
#include "PyAcadObjectImpl.h"

using namespace boost::python;

//----------------------------------------------------------------------------------------
//PyAcadDimension
void makePyAcadDimensionWrapper()
{
    PyDocString DS("AcadDimension");
    class_<PyAcadDimension, bases<PyAcadEntity>>("AcadDimension", boost::python::no_init)
        .def("normal", &PyAcadDimension::normal, DS.ARGS())
        .def("setNormal", &PyAcadDimension::setNormal, DS.ARGS({ "val:PyGe.Vector3d" }))
        .def("rotation", &PyAcadDimension::rotation, DS.ARGS())
        .def("setRotation", &PyAcadDimension::setRotation, DS.ARGS({ "val:float" }))
        .def("textPosition", &PyAcadDimension::textPosition, DS.ARGS())
        .def("setTextPosition", &PyAcadDimension::setTextPosition, DS.ARGS({ "val:PyGe.Point3d" }))
        .def("textRotation", &PyAcadDimension::textRotation, DS.ARGS())
        .def("setTextRotation", &PyAcadDimension::setTextRotation, DS.ARGS({ "val:float" }))
        .def("textOverride", &PyAcadDimension::textOverride, DS.ARGS())
        .def("setTextOverride", &PyAcadDimension::setTextOverride, DS.ARGS({ "val:str" }))
        .def("styleName", &PyAcadDimension::styleName, DS.ARGS())
        .def("setStyleName", &PyAcadDimension::setStyleName, DS.ARGS({ "val:str" }))
        .def("textColor", &PyAcadDimension::textColor, DS.ARGS())
        .def("setTextColor", &PyAcadDimension::setTextColor, DS.ARGS({ "val:PyAx.AcColor" }))
        .def("decimalSeparator", &PyAcadDimension::decimalSeparator, DS.ARGS())
        .def("setDecimalSeparator", &PyAcadDimension::setDecimalSeparator, DS.ARGS({ "val:str" }))
        .def("textGap", &PyAcadDimension::textGap, DS.ARGS())
        .def("setTextGap", &PyAcadDimension::setTextGap, DS.ARGS({ "val:float" }))
        .def("textPrefix", &PyAcadDimension::textPrefix, DS.ARGS())
        .def("setTextPrefix", &PyAcadDimension::setTextPrefix, DS.ARGS({ "val:str" }))
        .def("textSuffix", &PyAcadDimension::textSuffix, DS.ARGS())
        .def("setTextSuffix", &PyAcadDimension::setTextSuffix, DS.ARGS({ "val:str" }))
        .def("scaleFactor", &PyAcadDimension::scaleFactor, DS.ARGS())
        .def("setScaleFactor", &PyAcadDimension::setScaleFactor, DS.ARGS({ "val:float" }))
        .def("verticalTextPosition", &PyAcadDimension::verticalTextPosition, DS.ARGS())
        .def("setVerticalTextPosition", &PyAcadDimension::setVerticalTextPosition, DS.ARGS({ "val:PyAx.AcDimVerticalJustification" }))
        .def("tolerancePrecision", &PyAcadDimension::tolerancePrecision, DS.ARGS())
        .def("setTolerancePrecision", &PyAcadDimension::setTolerancePrecision, DS.ARGS({ "val:PyAx.AcDimPrecision" }))
        .def("toleranceHeightScale", &PyAcadDimension::toleranceHeightScale, DS.ARGS())
        .def("setToleranceHeightScale", &PyAcadDimension::setToleranceHeightScale, DS.ARGS({ "val:float" }))
        .def("toleranceLowerLimit", &PyAcadDimension::toleranceLowerLimit, DS.ARGS())
        .def("setToleranceLowerLimit", &PyAcadDimension::setToleranceLowerLimit, DS.ARGS({ "val:float" }))
        .def("textMovement", &PyAcadDimension::textMovement, DS.ARGS())
        .def("setTextMovement", &PyAcadDimension::setTextMovement, DS.ARGS({ "val:PyAx.AcDimTextMovement" }))
        .def("toleranceDisplay", &PyAcadDimension::toleranceDisplay, DS.ARGS())
        .def("setToleranceDisplay", &PyAcadDimension::setToleranceDisplay, DS.ARGS({ "val:PyAx.AcDimToleranceMethod" }))
        .def("toleranceJustification", &PyAcadDimension::toleranceJustification, DS.ARGS())
        .def("setToleranceJustification", &PyAcadDimension::setToleranceJustification, DS.ARGS({ "val:PyAx.AcDimToleranceJustify" }))
        .def("toleranceUpperLimit", &PyAcadDimension::toleranceUpperLimit, DS.ARGS())
        .def("setToleranceUpperLimit", &PyAcadDimension::setToleranceUpperLimit, DS.ARGS({ "val:float" }))
        .def("textStyle", &PyAcadDimension::textStyle, DS.ARGS())
        .def("setTextStyle", &PyAcadDimension::setTextStyle, DS.ARGS({ "val:str" }))
        .def("textHeight", &PyAcadDimension::textHeight, DS.ARGS())
        .def("setTextHeight", &PyAcadDimension::setTextHeight, DS.ARGS({ "val:float" }))
        .def("suppressLeadingZeros", &PyAcadDimension::suppressLeadingZeros, DS.ARGS())
        .def("setSuppressLeadingZeros", &PyAcadDimension::setSuppressLeadingZeros, DS.ARGS({ "val:bool" }))
        .def("suppressTrailingZeros", &PyAcadDimension::suppressTrailingZeros, DS.ARGS())
        .def("setSuppressTrailingZeros", &PyAcadDimension::setSuppressTrailingZeros, DS.ARGS({ "val:bool" }))
        .def("toleranceSuppressLeadingZeros", &PyAcadDimension::toleranceSuppressLeadingZeros, DS.ARGS())
        .def("setToleranceSuppressLeadingZeros", &PyAcadDimension::setToleranceSuppressLeadingZeros, DS.ARGS({ "val:bool" }))
        .def("toleranceSuppressTrailingZeros", &PyAcadDimension::toleranceSuppressTrailingZeros, DS.ARGS())
        .def("setToleranceSuppressTrailingZeros", &PyAcadDimension::setToleranceSuppressTrailingZeros, DS.ARGS({ "val:bool" }))
        .def("textFill", &PyAcadDimension::textFill, DS.ARGS())
        .def("setTextFill", &PyAcadDimension::setTextFill, DS.ARGS({ "val:bool" }))
        .def("textFillColor", &PyAcadDimension::textFillColor, DS.ARGS())
        .def("setTextFillColor", &PyAcadDimension::setTextFillColor, DS.ARGS({ "val:PyAx.AcColor" }))
        .def("dimTxtDirection", &PyAcadDimension::dimTxtDirection, DS.ARGS())
        .def("setDimTxtDirection", &PyAcadDimension::setDimTxtDirection, DS.ARGS({ "val:bool" }))
        .def("cast", &PyAcadDimension::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadDimension::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadDimension::PyAcadDimension(std::shared_ptr<PyIAcadDimensionImpl> ptr)
    : PyAcadEntity(ptr)
{
}

AcGeVector3d PyAcadDimension::normal() const
{
    return impObj()->GetNormal();
}

void PyAcadDimension::setNormal(const AcGeVector3d& val) const
{
    impObj()->SetNormal(val);
}

double PyAcadDimension::rotation() const
{
    return impObj()->GetRotation();
}

void PyAcadDimension::setRotation(double val) const
{
    impObj()->SetRotation(val);
}

AcGePoint3d PyAcadDimension::textPosition() const
{
    return impObj()->GetTextPosition();
}

void PyAcadDimension::setTextPosition(const AcGePoint3d& val) const
{
    impObj()->SetTextPosition(val);
}

double PyAcadDimension::textRotation() const
{
    return impObj()->GetTextRotation();
}

void PyAcadDimension::setTextRotation(double val) const
{
    impObj()->SetTextRotation(val);
}

std::string PyAcadDimension::textOverride() const
{
    return wstr_to_utf8(impObj()->GetTextOverride());
}

void PyAcadDimension::setTextOverride(const std::string& val) const
{
    impObj()->SetTextOverride(utf8_to_wstr(val).c_str());
}

std::string PyAcadDimension::styleName() const
{
    return wstr_to_utf8(impObj()->GetStyleName());
}

void PyAcadDimension::setStyleName(const std::string& val) const
{
    impObj()->SetStyleName(utf8_to_wstr(val).c_str());
}

PyAcColor PyAcadDimension::textColor() const
{
    return impObj()->GetTextColor();
}

void PyAcadDimension::setTextColor(PyAcColor val) const
{
    impObj()->SetTextColor(val);
}

std::string PyAcadDimension::decimalSeparator() const
{
    return wstr_to_utf8(impObj()->GetDecimalSeparator());
}

void PyAcadDimension::setDecimalSeparator(const std::string& val) const
{
    impObj()->SetDecimalSeparator(utf8_to_wstr(val).c_str());
}

double PyAcadDimension::textGap() const
{
    return impObj()->GetTextGap();
}

void PyAcadDimension::setTextGap(double val) const
{
    impObj()->SetTextGap(val);
}

std::string PyAcadDimension::textPrefix() const
{
    return wstr_to_utf8(impObj()->GetTextPrefix());
}

void PyAcadDimension::setTextPrefix(const std::string& val) const
{
    impObj()->SetTextPrefix(utf8_to_wstr(val).c_str());
}

std::string PyAcadDimension::textSuffix() const
{
    return wstr_to_utf8(impObj()->GetTextSuffix());
}

void PyAcadDimension::setTextSuffix(const std::string& val) const
{
    impObj()->SetTextSuffix(utf8_to_wstr(val).c_str());
}

double PyAcadDimension::scaleFactor() const
{
    return impObj()->GetScaleFactor();
}

void PyAcadDimension::setScaleFactor(double val) const
{
    impObj()->SetScaleFactor(val);
}

PyAcDimVerticalJustification PyAcadDimension::verticalTextPosition() const
{
    return impObj()->GetVerticalTextPosition();
}

void PyAcadDimension::setVerticalTextPosition(PyAcDimVerticalJustification val) const
{
    impObj()->SetVerticalTextPosition(val);
}

PyAcDimPrecision PyAcadDimension::tolerancePrecision() const
{
    return impObj()->GetTolerancePrecision();
}

void PyAcadDimension::setTolerancePrecision(PyAcDimPrecision val) const
{
    impObj()->SetTolerancePrecision(val);
}

double PyAcadDimension::toleranceHeightScale() const
{
    return impObj()->GetToleranceHeightScale();
}

void PyAcadDimension::setToleranceHeightScale(double val) const
{
    impObj()->SetToleranceHeightScale(val);
}

double PyAcadDimension::toleranceLowerLimit() const
{
    return impObj()->GetToleranceLowerLimit();
}

void PyAcadDimension::setToleranceLowerLimit(double val) const
{
    impObj()->SetToleranceLowerLimit(val);
}

PyAcDimTextMovement PyAcadDimension::textMovement() const
{
    return impObj()->GetTextMovement();
}

void PyAcadDimension::setTextMovement(PyAcDimTextMovement val) const
{
    impObj()->SetTextMovement(val);
}

PyAcDimToleranceMethod PyAcadDimension::toleranceDisplay() const
{
    return impObj()->GetToleranceDisplay();
}

void PyAcadDimension::setToleranceDisplay(PyAcDimToleranceMethod val) const
{
    impObj()->SetToleranceDisplay(val);
}

PyAcDimToleranceJustify PyAcadDimension::toleranceJustification() const
{
    return impObj()->GetToleranceJustification();
}

void PyAcadDimension::setToleranceJustification(PyAcDimToleranceJustify val) const
{
    impObj()->SetToleranceJustification(val);
}

double PyAcadDimension::toleranceUpperLimit() const
{
    return impObj()->GetToleranceUpperLimit();
}

void PyAcadDimension::setToleranceUpperLimit(double val) const
{
    impObj()->SetToleranceUpperLimit(val);
}

std::string PyAcadDimension::textStyle() const
{
    return wstr_to_utf8(impObj()->GetTextStyle());
}

void PyAcadDimension::setTextStyle(const std::string& val) const
{
    impObj()->SetTextStyle(utf8_to_wstr(val).c_str());
}

double PyAcadDimension::textHeight() const
{
    return impObj()->GetTextHeight();
}

void PyAcadDimension::setTextHeight(double val) const
{
    impObj()->SetTextHeight(val);
}

bool PyAcadDimension::suppressLeadingZeros() const
{
    return impObj()->GetSuppressLeadingZeros();
}

void PyAcadDimension::setSuppressLeadingZeros(bool val) const
{
    impObj()->SetSuppressLeadingZeros(val);
}

bool PyAcadDimension::suppressTrailingZeros() const
{
    return impObj()->GetSuppressTrailingZeros();
}

void PyAcadDimension::setSuppressTrailingZeros(bool val) const
{
    impObj()->SetSuppressTrailingZeros(val);
}

bool PyAcadDimension::toleranceSuppressLeadingZeros() const
{
    return impObj()->GetToleranceSuppressLeadingZeros();
}

void PyAcadDimension::setToleranceSuppressLeadingZeros(bool val) const
{
    impObj()->SetToleranceSuppressLeadingZeros(val);
}

bool PyAcadDimension::toleranceSuppressTrailingZeros() const
{
    return impObj()->GetToleranceSuppressTrailingZeros();
}

void PyAcadDimension::setToleranceSuppressTrailingZeros(bool val) const
{
    impObj()->SetToleranceSuppressTrailingZeros(val);
}

bool PyAcadDimension::textFill() const
{
    return impObj()->GetTextFill();
}

void PyAcadDimension::setTextFill(bool val) const
{
    impObj()->SetTextFill(val);
}

PyAcColor PyAcadDimension::textFillColor() const
{
    return impObj()->GetTextFillColor();
}

void PyAcadDimension::setTextFillColor(PyAcColor val) const
{
    impObj()->SetTextFillColor(val);
}

bool PyAcadDimension::dimTxtDirection() const
{
    return impObj()->GetDimTxtDirection();
}

void PyAcadDimension::setDimTxtDirection(bool val) const
{
    impObj()->SetDimTxtDirection(val);
}

PyAcadDimension PyAcadDimension::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadDimension>(src);
}

std::string PyAcadDimension::className()
{
    return "AcadDimension";
}

PyIAcadDimensionImpl* PyAcadDimension::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadDimensionImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadDimAligned
void makePyAcadDimAlignedWrapper()
{
    PyDocString DS("AcadDimAligned");
    class_<PyAcadDimAligned, bases<PyAcadDimension>>("AcadDimAligned", boost::python::no_init)
        .def("cast", &PyAcadDimAligned::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadDimAligned::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadDimAligned::PyAcadDimAligned(std::shared_ptr<PyIAcadDimAlignedImpl> ptr)
    : PyAcadDimension(ptr)
{
}

PyAcadDimAligned PyAcadDimAligned::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadDimAligned>(src);
}

std::string PyAcadDimAligned::className()
{
    return "AcadDimAligned";
}

PyIAcadDimAlignedImpl* PyAcadDimAligned::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadDimAlignedImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadDimAngular
void makePyAcadDimAngularWrapper()
{
    PyDocString DS("AcadDimAngular");
    class_<PyAcadDimAngular, bases<PyAcadDimension>>("AcadDimAngular", boost::python::no_init)
        .def("cast", &PyAcadDimAngular::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadDimAngular::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadDimAngular::PyAcadDimAngular(std::shared_ptr<PyIAcadDimAngularImpl> ptr)
    : PyAcadDimension(ptr)
{
}

PyAcadDimAngular PyAcadDimAngular::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadDimAngular>(src);
}

std::string PyAcadDimAngular::className()
{
    return "AcadDimAngular";
}

PyIAcadDimAngularImpl* PyAcadDimAngular::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadDimAngularImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadDimDiametric
void makePyAcadDimDiametricWrapper()
{
    PyDocString DS("AcadDimDiametric");
    class_<PyAcadDimDiametric, bases<PyAcadDimension>>("AcadDimDiametric", boost::python::no_init)
        .def("cast", &PyAcadDimDiametric::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadDimDiametric::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadDimDiametric::PyAcadDimDiametric(std::shared_ptr<PyIAcadDimDiametricImpl> ptr)
    : PyAcadDimension(ptr)
{
}

PyAcadDimDiametric PyAcadDimDiametric::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadDimDiametric>(src);
}

std::string PyAcadDimDiametric::className()
{
    return "AcadDimDiametric";
}

PyIAcadDimDiametricImpl* PyAcadDimDiametric::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadDimDiametricImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadDimRotated
void makePyAcadDimRotatedWrapper()
{
    PyDocString DS("AcadDimRotated");
    class_<PyAcadDimRotated, bases<PyAcadDimension>>("AcadDimRotated", boost::python::no_init)
        .def("cast", &PyAcadDimRotated::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadDimRotated::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadDimRotated::PyAcadDimRotated(std::shared_ptr<PyIAcadDimRotatedImpl> ptr)
    : PyAcadDimension(ptr)
{
}

PyAcadDimRotated PyAcadDimRotated::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadDimRotated>(src);
}

std::string PyAcadDimRotated::className()
{
    return "AcadDimRotated";
}

PyIAcadDimRotatedImpl* PyAcadDimRotated::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadDimRotatedImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadDimOrdinate
void makePyAcadDimOrdinateWrapper()
{
    PyDocString DS("AcadDimOrdinate");
    class_<PyAcadDimOrdinate, bases<PyAcadDimension>>("AcadDimOrdinate", boost::python::no_init)
        .def("cast", &PyAcadDimOrdinate::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadDimOrdinate::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadDimOrdinate::PyAcadDimOrdinate(std::shared_ptr<PyIAcadDimOrdinateImpl> ptr)
    : PyAcadDimension(ptr)
{
}

PyAcadDimOrdinate PyAcadDimOrdinate::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadDimOrdinate>(src);
}

std::string PyAcadDimOrdinate::className()
{
    return "AcadDimOrdinate";
}

PyIAcadDimOrdinateImpl* PyAcadDimOrdinate::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadDimOrdinateImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadDimRadial
void makePyAcadDimRadialWrapper()
{
    PyDocString DS("AcadDimRadial");
    class_<PyAcadDimRadial, bases<PyAcadDimension>>("AcadDimRadial", boost::python::no_init)
        .def("cast", &PyAcadDimRadial::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadDimRadial::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadDimRadial::PyAcadDimRadial(std::shared_ptr<PyIAcadDimRadialImpl> ptr)
    : PyAcadDimension(ptr)
{
}

PyAcadDimRadial PyAcadDimRadial::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadDimRadial>(src);
}

std::string PyAcadDimRadial::className()
{
    return "AcadDimRadial";
}

PyIAcadDimRadialImpl* PyAcadDimRadial::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadDimRadialImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadDim3PointAngular
void makePyAcadDim3PointAngularWrapper()
{
    PyDocString DS("AcadDim3PointAngular");
    class_<PyAcadDim3PointAngular, bases<PyAcadDimension>>("AcadDim3PointAngular", boost::python::no_init)
        .def("cast", &PyAcadDim3PointAngular::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadDim3PointAngular::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadDim3PointAngular::PyAcadDim3PointAngular(std::shared_ptr<PyIAcadDim3PointAngularImpl> ptr)
    : PyAcadDimension(ptr)
{
}

PyAcadDim3PointAngular PyAcadDim3PointAngular::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadDim3PointAngular>(src);
}

std::string PyAcadDim3PointAngular::className()
{
    return "AcadDim3PointAngular";
}

PyIAcadDim3PointAngularImpl* PyAcadDim3PointAngular::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadDim3PointAngularImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadDimArcLength
void makePyAcadDimArcLengthWrapper()
{
    PyDocString DS("AcadDimArcLength");
    class_<PyAcadDimArcLength, bases<PyAcadDimension>>("AcadDimArcLength", boost::python::no_init)
        .def("cast", &PyAcadDimArcLength::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadDimArcLength::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadDimArcLength::PyAcadDimArcLength(std::shared_ptr<PyIAcadDimArcLengthImpl> ptr)
    : PyAcadDimension(ptr)
{
}

PyAcadDimArcLength PyAcadDimArcLength::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadDimArcLength>(src);
}

std::string PyAcadDimArcLength::className()
{
    return "AcadDimArcLength";
}

PyIAcadDimArcLengthImpl* PyAcadDimArcLength::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadDimArcLengthImpl*>(m_pyImp.get());
}

//----------------------------------------------------------------------------------------
//PyAcadDimRadialLarge
void makePyAcadDimRadialLargeWrapper()
{
    PyDocString DS("AcadDimRadialLarge");
    class_<PyAcadDimRadialLarge, bases<PyAcadDimension>>("AcadDimRadialLarge", boost::python::no_init)
        .def("cast", &PyAcadDimRadialLarge::cast, DS.SARGS({ "otherObject: PyAx.AcadObject" })).staticmethod("cast")
        .def("className", &PyAcadDimRadialLarge::className, DS.SARGS()).staticmethod("className")
        ;
}

PyAcadDimRadialLarge::PyAcadDimRadialLarge(std::shared_ptr<PyIAcadDimRadialLargeImpl> ptr)
    : PyAcadDimension(ptr)
{
}

PyAcadDimRadialLarge PyAcadDimRadialLarge::cast(const PyAcadObject& src)
{
    return PyAcadObjectCast<PyAcadDimRadialLarge>(src);
}

std::string PyAcadDimRadialLarge::className()
{
    return "AcadDimRadialLarge";
}

PyIAcadDimRadialLargeImpl* PyAcadDimRadialLarge::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<PyIAcadDimRadialLargeImpl*>(m_pyImp.get());
}