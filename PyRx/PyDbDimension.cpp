#include "stdafx.h"
#include "PyDbDimension.h"

#include "PyDbObjectId.h"
#include "PyDbMtext.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------
//PyDbDimension
void makePyDbDimensionWrapper()
{
    class_<PyDbDimension, bases<PyDbEntity>>("Dimension", no_init)
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("textDefinedSize", &PyDbDimension::textDefinedSize)
        .def("setTextDefinedSize", &PyDbDimension::setTextDefinedSize)
        .def("resetTextDefinedSize", &PyDbDimension::resetTextDefinedSize)
        .def("textPosition", &PyDbDimension::textPosition)
        .def("setTextPosition", &PyDbDimension::setTextPosition)
        .def("isUsingDefaultTextPosition", &PyDbDimension::isUsingDefaultTextPosition)
        .def("useSetTextPosition", &PyDbDimension::useSetTextPosition)
        .def("useDefaultTextPosition", &PyDbDimension::useDefaultTextPosition)
        .def("setUsingDefaultTextPosition", &PyDbDimension::setUsingDefaultTextPosition)
        .def("normal", &PyDbDimension::normal)
        .def("setNormal", &PyDbDimension::setNormal)
        .def("elevation", &PyDbDimension::elevation)
        .def("setElevation", &PyDbDimension::setElevation)
        .def("dimensionText", &PyDbDimension::dimensionText)
        .def("setDimensionText", &PyDbDimension::setDimensionText)
        .def("textRotation", &PyDbDimension::textRotation)
        .def("setTextRotation", &PyDbDimension::setTextRotation)
        .def("dimensionStyle", &PyDbDimension::dimensionStyle)
        .def("setDimensionStyle", &PyDbDimension::setDimensionStyle)
        .def("textAttachment", &PyDbDimension::textAttachment)
        .def("setTextAttachment", &PyDbDimension::setTextAttachment)
        .def("textLineSpacingStyle", &PyDbDimension::textLineSpacingStyle)
        .def("setTextLineSpacingStyle", &PyDbDimension::setTextLineSpacingStyle)
        .def("textLineSpacingFactor", &PyDbDimension::textLineSpacingFactor)
        .def("setTextLineSpacingFactor", &PyDbDimension::setTextLineSpacingFactor)
        .def("setDimstyleData", &PyDbDimension::setDimstyleData)
        .def("horizontalRotation", &PyDbDimension::horizontalRotation)
        .def("setHorizontalRotation", &PyDbDimension::setHorizontalRotation)
        .def("dimBlockId", &PyDbDimension::dimBlockId)
        .def("setDimBlockId", &PyDbDimension::setDimBlockId)
        .def("dimBlockPosition", &PyDbDimension::dimBlockPosition)
        .def("setDimBlockPosition", &PyDbDimension::setDimBlockPosition)
        .def("recomputeDimBlock", &PyDbDimension::recomputeDimBlock1)
        .def("recomputeDimBlock", &PyDbDimension::recomputeDimBlock2)
        .def("generateLayout", &PyDbDimension::generateLayout)
        .def("measurement", &PyDbDimension::measurement)
        .def("formatMeasurement", &PyDbDimension::formatMeasurement1)
        .def("formatMeasurement", &PyDbDimension::formatMeasurement2)
        .def("isDynamicDimension", &PyDbDimension::isDynamicDimension)
        .def("setDynamicDimension", &PyDbDimension::setDynamicDimension)
        .def("dimLineLinetype", &PyDbDimension::dimLineLinetype)
        .def("setDimLineLinetype", &PyDbDimension::setDimLineLinetype)
        .def("dimExt1Linetype", &PyDbDimension::dimExt1Linetype)
        .def("setDimExt1Linetype", &PyDbDimension::setDimExt1Linetype)
        .def("dimExt2Linetype", &PyDbDimension::dimExt2Linetype)
        .def("setDimExt2Linetype", &PyDbDimension::setDimExt2Linetype)
        .def("removeTextField", &PyDbDimension::removeTextField)
        .def("fieldToMText", &PyDbDimension::fieldToMText)
        .def("fieldFromMText", &PyDbDimension::fieldFromMText)
        .def("isHorizontalRefTextRotation", &PyDbDimension::isHorizontalRefTextRotation)
        .def("setHorizontalRefTextRotation", &PyDbDimension::setHorizontalRefTextRotation)
        .def("getArrowFirstIsFlipped", &PyDbDimension::getArrowFirstIsFlipped)
        .def("getArrowSecondIsFlipped", &PyDbDimension::getArrowSecondIsFlipped)
        .def("setArrowFirstIsFlipped", &PyDbDimension::setArrowFirstIsFlipped)
        .def("setArrowSecondIsFlipped", &PyDbDimension::setArrowSecondIsFlipped)
        .def("blockTransform", &PyDbDimension::blockTransform)
        .def("inspection", &PyDbDimension::inspection)
        .def("setInspection", &PyDbDimension::setInspection)
        .def("inspectionFrame", &PyDbDimension::inspectionFrame)
        .def("setInspectionFrame", &PyDbDimension::setInspectionFrame)
        .def("inspectionLabel", &PyDbDimension::inspectionLabel)
        .def("setInspectionLabel", &PyDbDimension::setInspectionLabel)
        .def("isConstraintObject", &PyDbDimension::isConstraintObject)
        .def("isConstraintDynamic", &PyDbDimension::isConstraintDynamic)
        .def("setConstraintDynamic", &PyDbDimension::setConstraintDynamic)
        .def("shouldParticipateInOPM", &PyDbDimension::shouldParticipateInOPM)
        .def("setShouldParticipateInOPM", &PyDbDimension::setShouldParticipateInOPM)
        .def("centerMarkSize", &PyDbDimension::centerMarkSize)
        .def("prefix", &PyDbDimension::prefix)
        .def("setPrefix", &PyDbDimension::setPrefix)
        .def("suffix", &PyDbDimension::suffix)
        .def("setSuffix", &PyDbDimension::setSuffix)
        .def("alternateSuffix", &PyDbDimension::alternateSuffix)
        .def("setAlternateSuffix", &PyDbDimension::setAlternateSuffix)
        .def("alternatePrefix", &PyDbDimension::alternatePrefix)
        .def("setAlternatePrefix", &PyDbDimension::setAlternatePrefix)
        .def("suppressAngularLeadingZeros", &PyDbDimension::suppressAngularLeadingZeros)
        .def("suppressAngularTrailingZeros", &PyDbDimension::suppressAngularTrailingZeros)
        .def("setSuppressAngularTrailingZeros", &PyDbDimension::setSuppressAngularTrailingZeros)
        .def("altSuppressZeroInches", &PyDbDimension::altSuppressZeroInches)
        .def("setAltSuppressZeroInches", &PyDbDimension::setAltSuppressZeroInches)
        .def("altSuppressZeroFeet", &PyDbDimension::altSuppressZeroFeet)
        .def("setAltSuppressZeroFeet", &PyDbDimension::setAltSuppressZeroFeet)
        .def("altSuppressTrailingZeros", &PyDbDimension::altSuppressTrailingZeros)
        .def("setAltSuppressTrailingZeros", &PyDbDimension::setAltSuppressTrailingZeros)
        .def("altToleranceSuppressLeadingZeros", &PyDbDimension::altToleranceSuppressLeadingZeros)
        .def("setAltToleranceSuppressLeadingZeros", &PyDbDimension::setAltToleranceSuppressLeadingZeros)
        .def("altToleranceSuppressZeroInches", &PyDbDimension::altToleranceSuppressZeroInches)
        .def("setAltToleranceSuppressZeroInches", &PyDbDimension::setAltToleranceSuppressZeroInches)
        .def("altToleranceSuppressZeroFeet", &PyDbDimension::altToleranceSuppressZeroFeet)
        .def("setAltToleranceSuppressZeroFeet", &PyDbDimension::setAltToleranceSuppressZeroFeet)
        .def("altToleranceSuppressTrailingZeros", &PyDbDimension::altToleranceSuppressTrailingZeros)
        .def("setAltToleranceSuppressTrailingZeros", &PyDbDimension::setAltToleranceSuppressTrailingZeros)
        .def("suppressZeroFeet", &PyDbDimension::suppressZeroFeet)
        .def("setSuppressZeroFeet", &PyDbDimension::setSuppressZeroFeet)
        .def("suppressTrailingZeros", &PyDbDimension::suppressTrailingZeros)
        .def("setSuppressTrailingZeros", &PyDbDimension::setSuppressTrailingZeros)
        .def("suppressLeadingZeros", &PyDbDimension::suppressLeadingZeros)
        .def("setSuppressLeadingZeros", &PyDbDimension::setSuppressLeadingZeros)
        .def("suppressZeroInches", &PyDbDimension::suppressZeroInches)
        .def("setSuppressZeroInches", &PyDbDimension::setSuppressZeroInches)
        .def("altSuppressLeadingZeros", &PyDbDimension::altSuppressLeadingZeros)
        .def("setAltSuppressLeadingZeros", &PyDbDimension::setAltSuppressLeadingZeros)
        .def("toleranceSuppressZeroFeet", &PyDbDimension::toleranceSuppressZeroFeet)
        .def("setToleranceSuppressZeroFeet", &PyDbDimension::setToleranceSuppressZeroFeet)
        .def("toleranceSuppressTrailingZeros", &PyDbDimension::toleranceSuppressTrailingZeros)
        .def("setToleranceSuppressTrailingZeros", &PyDbDimension::setToleranceSuppressTrailingZeros)
        .def("toleranceSuppressLeadingZeros", &PyDbDimension::toleranceSuppressLeadingZeros)
        .def("setToleranceSuppressLeadingZeros", &PyDbDimension::setToleranceSuppressLeadingZeros)
        .def("toleranceSuppressZeroInches", &PyDbDimension::toleranceSuppressZeroInches)
        .def("setToleranceSuppressZeroInches", &PyDbDimension::setToleranceSuppressZeroInches)
        .def("className", &PyDbDimension::className).staticmethod("className")
        ;

#ifndef BRXAPP
    enum_<AcDbDimension::DimInspect>("DimInspect")
        .value("kShapeRemove", AcDbDimension::DimInspect::kShapeRemove)
        .value("kShapeRound", AcDbDimension::DimInspect::kShapeRound)
        .value("kShapeAngular", AcDbDimension::DimInspect::kShapeAngular)
        .value("kShapeNone", AcDbDimension::DimInspect::kShapeNone)
        .value("kShapeLabel", AcDbDimension::DimInspect::kShapeLabel)
        .value("kShapeRate", AcDbDimension::DimInspect::kShapeRate)
        .export_values()
        ;
#endif

#ifndef BRXAPP
    enum_<AcDbDimension::CenterMarkType>("CenterMarkType")
        .value("kMark", AcDbDimension::CenterMarkType::kMark)
        .value("kLine", AcDbDimension::CenterMarkType::kLine)
        .value("kNone", AcDbDimension::CenterMarkType::kNone)
        .export_values()
        ;
#endif
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
    PyAutoLockGIL lock;
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
    impObj()->measurement(m);
    return m;
}

std::string PyDbDimension::formatMeasurement1(double measurement)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    AcString str;
    impObj()->formatMeasurement(str, measurement);
    return wstr_to_utf8(str);
#endif
}

std::string PyDbDimension::formatMeasurement2(double measurement, const std::string& dimensionText)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    AcString str;
    impObj()->formatMeasurement(str, measurement, utf8_to_wstr(dimensionText).c_str());
    return wstr_to_utf8(str);
#endif
}

bool PyDbDimension::isDynamicDimension() const
{
    return impObj()->isDynamicDimension();
}

Acad::ErrorStatus PyDbDimension::setDynamicDimension(bool newVal)
{
    return impObj()->setDynamicDimension(newVal);
}

PyDbObjectId PyDbDimension::dimLineLinetype() const
{
    return PyDbObjectId(impObj()->dimLineLinetype());
}

Acad::ErrorStatus PyDbDimension::setDimLineLinetype(const PyDbObjectId& linetype)
{
    return impObj()->setDimLineLinetype(linetype.m_id);
}

PyDbObjectId PyDbDimension::dimExt1Linetype() const
{
    return PyDbObjectId(impObj()->dimExt1Linetype());
}

Acad::ErrorStatus PyDbDimension::setDimExt1Linetype(const PyDbObjectId& linetype)
{
    return impObj()->setDimExt1Linetype(linetype.m_id);
}

PyDbObjectId PyDbDimension::dimExt2Linetype() const
{
    return PyDbObjectId(impObj()->dimExt2Linetype());
}

Acad::ErrorStatus PyDbDimension::setDimExt2Linetype(const PyDbObjectId& linetype)
{
    return impObj()->setDimExt2Linetype(linetype.m_id);
}

Acad::ErrorStatus PyDbDimension::removeTextField()
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->removeTextField();
#endif
}

Acad::ErrorStatus PyDbDimension::fieldToMText(PyDbMText& pDimMText)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->fieldToMText(pDimMText.impObj());
#endif
}

Acad::ErrorStatus PyDbDimension::fieldFromMText(PyDbMText& pDimMText)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->fieldFromMText(pDimMText.impObj());
#endif
}

bool PyDbDimension::isHorizontalRefTextRotation() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->isHorizontalRefTextRotation();
#endif
}

Acad::ErrorStatus PyDbDimension::setHorizontalRefTextRotation(bool newVal)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setHorizontalRefTextRotation(newVal);
#endif
}

bool PyDbDimension::getArrowFirstIsFlipped() const
{
    return impObj()->getArrowFirstIsFlipped();
}

bool PyDbDimension::getArrowSecondIsFlipped() const
{
    return impObj()->getArrowSecondIsFlipped();
}

Acad::ErrorStatus PyDbDimension::setArrowFirstIsFlipped(bool bIsFlipped)
{
    return impObj()->setArrowFirstIsFlipped(bIsFlipped);
}

Acad::ErrorStatus PyDbDimension::setArrowSecondIsFlipped(bool bIsFlipped)
{
    return impObj()->setArrowSecondIsFlipped(bIsFlipped);
}

AcGeMatrix3d PyDbDimension::blockTransform() const
{
    return impObj()->blockTransform();
}

bool PyDbDimension::inspection() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->inspection();
#endif
}

Acad::ErrorStatus PyDbDimension::setInspection(bool val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setInspection(val);
#endif
}

int PyDbDimension::inspectionFrame() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->inspectionFrame();
#endif
}

Acad::ErrorStatus PyDbDimension::setInspectionFrame(int frame)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setInspectionFrame(frame);
#endif
}

const std::string PyDbDimension::inspectionLabel() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return wstr_to_utf8(impObj()->inspectionLabel());
#endif
}

Acad::ErrorStatus PyDbDimension::setInspectionLabel(const std::string& label)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setInspectionLabel(utf8_to_wstr(label).c_str());
#endif
}

boost::python::tuple PyDbDimension::isConstraintObject() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    PyAutoLockGIL lock;
    bool hasExpression = false;
    bool isReferenceConstraint = false;
    bool flag = impObj()->isConstraintObject(hasExpression, isReferenceConstraint);
    return boost::python::make_tuple(flag, hasExpression, isReferenceConstraint);
#endif
}

bool PyDbDimension::isConstraintDynamic(void) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->isConstraintDynamic();
#endif
}

Acad::ErrorStatus PyDbDimension::setConstraintDynamic(bool bDynamic)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setConstraintDynamic(bDynamic);
#endif
}

bool PyDbDimension::shouldParticipateInOPM(void) const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->shouldParticipateInOPM();
#endif
}

void PyDbDimension::setShouldParticipateInOPM(bool bShouldParticipate)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setShouldParticipateInOPM(bShouldParticipate);
#endif
}

double PyDbDimension::centerMarkSize() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->centerMarkSize();
#endif
}

std::string PyDbDimension::prefix() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    AcString sPrefix;
    impObj()->prefix(sPrefix);
    return wstr_to_utf8(sPrefix);
#endif
}

Acad::ErrorStatus PyDbDimension::setPrefix(const std::string& val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setPrefix(utf8_to_wstr(val).c_str());
#endif
}

std::string PyDbDimension::suffix() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    AcString _suffix;
    impObj()->suffix(_suffix);
    return wstr_to_utf8(_suffix);
#endif
}

Acad::ErrorStatus PyDbDimension::setSuffix(const std::string& val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setSuffix(utf8_to_wstr(val).c_str());
#endif
}

std::string PyDbDimension::alternateSuffix() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    AcString _sval;
    impObj()->alternateSuffix(_sval);
    return wstr_to_utf8(_sval);
#endif
}

Acad::ErrorStatus PyDbDimension::setAlternateSuffix(const std::string& val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setAlternateSuffix(utf8_to_wstr(val).c_str());
#endif
}

std::string PyDbDimension::alternatePrefix() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    AcString _sval;
    impObj()->alternatePrefix(_sval);
    return wstr_to_utf8(_sval);
#endif
}

Acad::ErrorStatus PyDbDimension::setAlternatePrefix(const std::string& val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setAlternatePrefix(utf8_to_wstr(val).c_str());
#endif
}

bool PyDbDimension::suppressAngularLeadingZeros() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->suppressAngularLeadingZeros();
#endif
}

Acad::ErrorStatus PyDbDimension::setSuppressAngularLeadingZeros(bool val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setSuppressAngularLeadingZeros(val);
#endif
}

bool PyDbDimension::suppressAngularTrailingZeros() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->suppressAngularLeadingZeros();
#endif
}

Acad::ErrorStatus PyDbDimension::setSuppressAngularTrailingZeros(bool val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setSuppressAngularTrailingZeros(val);
#endif
}

bool PyDbDimension::altSuppressZeroInches() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->altSuppressZeroInches();
#endif
}

Acad::ErrorStatus PyDbDimension::setAltSuppressZeroInches(bool val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setAltSuppressZeroInches(val);
#endif
}

bool PyDbDimension::altSuppressZeroFeet() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->altSuppressZeroFeet();
#endif
}

Acad::ErrorStatus PyDbDimension::setAltSuppressZeroFeet(bool val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setAltSuppressZeroFeet(val);
#endif
}

bool PyDbDimension::altSuppressTrailingZeros() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->altSuppressTrailingZeros();
#endif
}

Acad::ErrorStatus PyDbDimension::setAltSuppressTrailingZeros(bool val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setAltSuppressTrailingZeros(val);
#endif
}

bool PyDbDimension::altToleranceSuppressLeadingZeros() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->altToleranceSuppressLeadingZeros();
#endif
}

Acad::ErrorStatus PyDbDimension::setAltToleranceSuppressLeadingZeros(bool val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setAltToleranceSuppressLeadingZeros(val);
#endif
}

bool PyDbDimension::altToleranceSuppressZeroInches() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->altToleranceSuppressZeroInches();
#endif
}

Acad::ErrorStatus PyDbDimension::setAltToleranceSuppressZeroInches(bool val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setAltToleranceSuppressZeroInches(val);
#endif
}

bool PyDbDimension::altToleranceSuppressZeroFeet() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->altToleranceSuppressZeroFeet();
#endif
}

Acad::ErrorStatus PyDbDimension::setAltToleranceSuppressZeroFeet(bool val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setAltToleranceSuppressZeroFeet(val);
#endif
}

bool PyDbDimension::altToleranceSuppressTrailingZeros() const
{
    return impObj()->altToleranceSuppressTrailingZeros();
}

Acad::ErrorStatus PyDbDimension::setAltToleranceSuppressTrailingZeros(bool val)
{
    return impObj()->setAltToleranceSuppressTrailingZeros(val);
}

bool PyDbDimension::suppressZeroFeet() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->suppressZeroFeet();
#endif
}

Acad::ErrorStatus PyDbDimension::setSuppressZeroFeet(bool val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setSuppressZeroFeet(val);
#endif
}

bool PyDbDimension::suppressTrailingZeros() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->suppressTrailingZeros();
#endif
}

Acad::ErrorStatus PyDbDimension::setSuppressTrailingZeros(bool val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setSuppressTrailingZeros(val);
#endif
}

bool PyDbDimension::suppressLeadingZeros() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->suppressLeadingZeros();
#endif
}

Acad::ErrorStatus PyDbDimension::setSuppressLeadingZeros(bool val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setSuppressLeadingZeros(val);
#endif
}

bool PyDbDimension::suppressZeroInches() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->suppressZeroInches();
#endif
}

Acad::ErrorStatus PyDbDimension::setSuppressZeroInches(bool val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setSuppressZeroInches(val);
#endif
}

bool PyDbDimension::altSuppressLeadingZeros() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->altSuppressLeadingZeros();
#endif
}

Acad::ErrorStatus PyDbDimension::setAltSuppressLeadingZeros(bool val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setAltSuppressLeadingZeros(val);
#endif
}

bool PyDbDimension::toleranceSuppressZeroFeet() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->toleranceSuppressZeroFeet();
#endif
}

Acad::ErrorStatus PyDbDimension::setToleranceSuppressZeroFeet(bool val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setToleranceSuppressZeroFeet(val);
#endif
}

bool PyDbDimension::toleranceSuppressTrailingZeros() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->toleranceSuppressTrailingZeros();
#endif
}

Acad::ErrorStatus PyDbDimension::setToleranceSuppressTrailingZeros(bool val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setToleranceSuppressTrailingZeros(val);
#endif
}

bool PyDbDimension::toleranceSuppressLeadingZeros() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->toleranceSuppressLeadingZeros();
#endif
}

Acad::ErrorStatus PyDbDimension::setToleranceSuppressLeadingZeros(bool val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setToleranceSuppressLeadingZeros(val);
#endif
}

bool PyDbDimension::toleranceSuppressZeroInches() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->toleranceSuppressZeroInches();
#endif
}

Acad::ErrorStatus PyDbDimension::setToleranceSuppressZeroInches(bool val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setToleranceSuppressZeroInches(val);
#endif
}

#ifndef BRXAPP
AcDbDimension::CenterMarkType PyDbDimension::centerMarkType() const
{
    return impObj()->centerMarkType();
}
#endif
std::string PyDbDimension::className()
{
    return "AcDbRegion";
}

AcDbDimension* PyDbDimension::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbDimension*>(m_pImp.get());
}

//-----------------------------------------------------------------------------------
//PyDb2LineAngularDimension
void makePyDb2LineAngularDimensionWrapper()
{
    class_<PyDb2LineAngularDimension, bases<PyDbDimension>>("LineAngularDimension2")
        .def(init<>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&>())
        .def(init<const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&, const std::string&>())
        .def(init<const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&, const std::string&, const PyDbObjectId&>())
        .def("arcPoint", &PyDb2LineAngularDimension::arcPoint)
        .def("setArcPoint", &PyDb2LineAngularDimension::setArcPoint)
        .def("xLine1Start", &PyDb2LineAngularDimension::xLine1Start)
        .def("setXLine1Start", &PyDb2LineAngularDimension::setXLine1Start)
        .def("xLine1End", &PyDb2LineAngularDimension::xLine1End)
        .def("setXLine1End", &PyDb2LineAngularDimension::setXLine1End)
        .def("xLine2Start", &PyDb2LineAngularDimension::xLine2Start)
        .def("setXLine2Start", &PyDb2LineAngularDimension::setXLine2Start)
        .def("xLine2End", &PyDb2LineAngularDimension::xLine2End)
        .def("setXLine2End", &PyDb2LineAngularDimension::setXLine2End)
        .def("extArcOn", &PyDb2LineAngularDimension::extArcOn)
        .def("setExtArcOn", &PyDb2LineAngularDimension::setExtArcOn)
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

PyDb2LineAngularDimension::PyDb2LineAngularDimension(const AcGePoint3d& xLine1Start,
    const AcGePoint3d& xLine1End, const AcGePoint3d& xLine2Start, const AcGePoint3d& xLine2End, const AcGePoint3d& arcPoint)
    : PyDbDimension(new AcDb2LineAngularDimension(xLine1Start, xLine1End, xLine2Start, xLine2End, arcPoint), true)
{
}

PyDb2LineAngularDimension::PyDb2LineAngularDimension(const AcGePoint3d& xLine1Start,
    const AcGePoint3d& xLine1End, const AcGePoint3d& xLine2Start, const AcGePoint3d& xLine2End, const AcGePoint3d& arcPoint, const std::string& dimText)
    : PyDbDimension(new AcDb2LineAngularDimension(xLine1Start, xLine1End, xLine2Start, xLine2End, arcPoint, utf8_to_wstr(dimText).c_str()), true)
{
}

PyDb2LineAngularDimension::PyDb2LineAngularDimension(const AcGePoint3d& xLine1Start, const AcGePoint3d& xLine1End,
    const AcGePoint3d& xLine2Start, const AcGePoint3d& xLine2End, const AcGePoint3d& arcPoint, const std::string& dimText, const PyDbObjectId& dimStyle)
    : PyDbDimension(new AcDb2LineAngularDimension(xLine1Start, xLine1End, xLine2Start, xLine2End, arcPoint, utf8_to_wstr(dimText).c_str(), dimStyle.m_id), true)
{
}

AcGePoint3d PyDb2LineAngularDimension::arcPoint() const
{
    return impObj()->arcPoint();
}

Acad::ErrorStatus PyDb2LineAngularDimension::setArcPoint(const AcGePoint3d& val)
{
    return impObj()->setArcPoint(val);
}

AcGePoint3d PyDb2LineAngularDimension::xLine1Start() const
{
    return impObj()->xLine1Start();
}

Acad::ErrorStatus PyDb2LineAngularDimension::setXLine1Start(const AcGePoint3d& val)
{
    return impObj()->setXLine1Start(val);
}

AcGePoint3d PyDb2LineAngularDimension::xLine1End() const
{
    return impObj()->xLine1End();
}

Acad::ErrorStatus PyDb2LineAngularDimension::setXLine1End(const AcGePoint3d& val)
{
    return impObj()->setXLine1End(val);
}

AcGePoint3d PyDb2LineAngularDimension::xLine2Start() const
{
    return impObj()->xLine2Start();
}

Acad::ErrorStatus PyDb2LineAngularDimension::setXLine2Start(const AcGePoint3d& val)
{
    return impObj()->setXLine2Start(val);
}

AcGePoint3d PyDb2LineAngularDimension::xLine2End() const
{
    return impObj()->xLine2End();
}

Acad::ErrorStatus PyDb2LineAngularDimension::setXLine2End(const AcGePoint3d& val)
{
    return impObj()->setXLine2End(val);
}

bool PyDb2LineAngularDimension::extArcOn() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->extArcOn();
#endif
}

Acad::ErrorStatus PyDb2LineAngularDimension::setExtArcOn(bool value)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setExtArcOn(value);
#endif
}

std::string PyDb2LineAngularDimension::className()
{
    return "AcDb2LineAngularDimension";
}

AcDb2LineAngularDimension* PyDb2LineAngularDimension::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDb2LineAngularDimension*>(m_pImp.get());
}


//-----------------------------------------------------------------------------------
//AcDb3PointAngularDimension
void makeAcDb3PointAngularDimensionWrapper()
{
    class_<PyDb3PointAngularDimension, bases<PyDbDimension>>("Point3AngularDimension")
        .def(init<>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&>())
        .def(init<const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&, const std::string&>())
        .def(init<const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&, const std::string&, const PyDbObjectId&>())
        .def("arcPoint", &PyDb3PointAngularDimension::arcPoint)
        .def("setArcPoint", &PyDb3PointAngularDimension::setArcPoint)
        .def("xLine1Point", &PyDb3PointAngularDimension::xLine1Point)
        .def("setXLine1Point", &PyDb3PointAngularDimension::setXLine1Point)
        .def("xLine2Point", &PyDb3PointAngularDimension::xLine2Point)
        .def("setXLine2Point", &PyDb3PointAngularDimension::setXLine2Point)
        .def("centerPoint", &PyDb3PointAngularDimension::centerPoint)
        .def("setCenterPoint", &PyDb3PointAngularDimension::setCenterPoint)
        .def("extArcOn", &PyDb3PointAngularDimension::extArcOn)
        .def("setExtArcOn", &PyDb3PointAngularDimension::setExtArcOn)
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

PyDb3PointAngularDimension::PyDb3PointAngularDimension(const AcGePoint3d& centerPoint, const AcGePoint3d& xLine1Point, const AcGePoint3d& xLine2Point, const AcGePoint3d& arcPoint)
    : PyDbDimension(new AcDb3PointAngularDimension(centerPoint, xLine1Point, xLine2Point, arcPoint), true)
{
}

PyDb3PointAngularDimension::PyDb3PointAngularDimension(const AcGePoint3d& centerPoint, const AcGePoint3d& xLine1Point, const AcGePoint3d& xLine2Point, const AcGePoint3d& arcPoint, const std::string& dimText)
    : PyDbDimension(new AcDb3PointAngularDimension(centerPoint, xLine1Point, xLine2Point, arcPoint, utf8_to_wstr(dimText).c_str()), true)
{
}

PyDb3PointAngularDimension::PyDb3PointAngularDimension(const AcGePoint3d& centerPoint, const AcGePoint3d& xLine1Point, const AcGePoint3d& xLine2Point, const AcGePoint3d& arcPoint, const std::string& dimText, const PyDbObjectId& dimStyle)
    : PyDbDimension(new AcDb3PointAngularDimension(centerPoint, xLine1Point, xLine2Point, arcPoint, utf8_to_wstr(dimText).c_str(), dimStyle.m_id), true)
{
}

AcGePoint3d PyDb3PointAngularDimension::arcPoint() const
{
    return impObj()->arcPoint();
}

Acad::ErrorStatus PyDb3PointAngularDimension::setArcPoint(const AcGePoint3d& val)
{
    return impObj()->setArcPoint(val);
}

AcGePoint3d PyDb3PointAngularDimension::xLine1Point() const
{
    return impObj()->xLine1Point();
}

Acad::ErrorStatus PyDb3PointAngularDimension::setXLine1Point(const AcGePoint3d& val)
{
    return impObj()->setXLine1Point(val);
}

AcGePoint3d PyDb3PointAngularDimension::xLine2Point() const
{
    return impObj()->xLine1Point();
}

Acad::ErrorStatus PyDb3PointAngularDimension::setXLine2Point(const AcGePoint3d& val)
{
    return impObj()->setXLine2Point(val);
}

AcGePoint3d PyDb3PointAngularDimension::centerPoint() const
{
    return impObj()->centerPoint();
}

Acad::ErrorStatus PyDb3PointAngularDimension::setCenterPoint(const AcGePoint3d& val)
{
    return impObj()->setCenterPoint(val);
}

bool PyDb3PointAngularDimension::extArcOn() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->extArcOn();
#endif
}

Acad::ErrorStatus PyDb3PointAngularDimension::setExtArcOn(bool value)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setExtArcOn(value);
#endif
}

std::string PyDb3PointAngularDimension::className()
{
    return "AcDb3PointAngularDimension";
}

AcDb3PointAngularDimension* PyDb3PointAngularDimension::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDb3PointAngularDimension*>(m_pImp.get());
}

//-----------------------------------------------------------------------------------
//AcDbAlignedDimension
void makeAlignedDimensionWrapper()
{
    class_<PyDbAlignedDimension, bases<PyDbDimension>>("AlignedDimension")
        .def(init<>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&>())
        .def(init<const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&, const std::string&>())
        .def(init<const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&, const std::string&, const PyDbObjectId& >())
        .def("xLine1Point", &PyDbAlignedDimension::xLine1Point)
        .def("setXLine1Point", &PyDbAlignedDimension::setXLine1Point)
        .def("xLine2Point", &PyDbAlignedDimension::xLine2Point)
        .def("setXLine2Point", &PyDbAlignedDimension::setXLine2Point)
        .def("dimLinePoint", &PyDbAlignedDimension::dimLinePoint)
        .def("setDimLinePoint", &PyDbAlignedDimension::setDimLinePoint)
        .def("oblique", &PyDbAlignedDimension::oblique)
        .def("setOblique", &PyDbAlignedDimension::setOblique)
        .def("jogSymbolOn", &PyDbAlignedDimension::jogSymbolOn)
        .def("setJogSymbolOn", &PyDbAlignedDimension::setJogSymbolOn)
        .def("jogSymbolPosition", &PyDbAlignedDimension::jogSymbolPosition)
        .def("setJogSymbolPosition", &PyDbAlignedDimension::setJogSymbolPosition)
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

PyDbAlignedDimension::PyDbAlignedDimension(const AcGePoint3d& xLine1Point, const AcGePoint3d& xLine2Point, const AcGePoint3d& dimLinePoint)
    : PyDbDimension(new AcDbAlignedDimension(xLine1Point, xLine2Point, dimLinePoint), true)
{
}

PyDbAlignedDimension::PyDbAlignedDimension(const AcGePoint3d& xLine1Point, const AcGePoint3d& xLine2Point, const AcGePoint3d& dimLinePoint, const std::string& dimText)
    : PyDbDimension(new AcDbAlignedDimension(xLine1Point, xLine2Point, dimLinePoint, utf8_to_wstr(dimText).c_str()), true)
{
}

PyDbAlignedDimension::PyDbAlignedDimension(const AcGePoint3d& xLine1Point, const AcGePoint3d& xLine2Point, const AcGePoint3d& dimLinePoint, const std::string& dimText, const PyDbObjectId& dimStyle)
    : PyDbDimension(new AcDbAlignedDimension(xLine1Point, xLine2Point, dimLinePoint, utf8_to_wstr(dimText).c_str(), dimStyle.m_id), true)
{
}

AcGePoint3d PyDbAlignedDimension::xLine1Point() const
{
    return impObj()->xLine1Point();
}

Acad::ErrorStatus PyDbAlignedDimension::setXLine1Point(const AcGePoint3d& val)
{
    return impObj()->setXLine1Point(val);
}

AcGePoint3d PyDbAlignedDimension::xLine2Point() const
{
    return impObj()->xLine2Point();
}

Acad::ErrorStatus PyDbAlignedDimension::setXLine2Point(const AcGePoint3d& val)
{
    return impObj()->setXLine2Point(val);
}

AcGePoint3d PyDbAlignedDimension::dimLinePoint() const
{
    return impObj()->dimLinePoint();
}

Acad::ErrorStatus PyDbAlignedDimension::setDimLinePoint(const AcGePoint3d& val)
{
    return impObj()->setDimLinePoint(val);
}

double PyDbAlignedDimension::oblique() const
{
    return impObj()->oblique();
}

Acad::ErrorStatus PyDbAlignedDimension::setOblique(double val)
{
    return impObj()->setOblique(val);
}

bool PyDbAlignedDimension::jogSymbolOn() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->jogSymbolOn();
#endif
}

Acad::ErrorStatus PyDbAlignedDimension::setJogSymbolOn(bool value)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setJogSymbolOn(value);
#endif
}

AcGePoint3d PyDbAlignedDimension::jogSymbolPosition() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->jogSymbolPosition();
#endif
}

Acad::ErrorStatus PyDbAlignedDimension::setJogSymbolPosition(const AcGePoint3d& pt)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setJogSymbolPosition(pt);
#endif
}

std::string PyDbAlignedDimension::className()
{
    return "AcDbAlignedDimension";
}

AcDbAlignedDimension* PyDbAlignedDimension::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbAlignedDimension*>(m_pImp.get());
}

//-----------------------------------------------------------------------------------
//AcDbArcDimension
void makeArcDimensionWrapper()
{
    class_<PyDbArcDimension, bases<PyDbDimension>>("ArcDimension")
        .def(init<>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init <const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&>())
        .def(init <const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&, const std::string&>())
        .def(init <const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&, const std::string&, const PyDbObjectId&>())
        .def("arcPoint", &PyDbArcDimension::arcPoint)
        .def("setArcPoint", &PyDbArcDimension::setArcPoint)
        .def("xLine1Point", &PyDbArcDimension::xLine1Point)
        .def("setXLine1Point", &PyDbArcDimension::setXLine1Point)
        .def("xLine2Point", &PyDbArcDimension::xLine2Point)
        .def("setXLine2Point", &PyDbArcDimension::setXLine2Point)
        .def("centerPoint", &PyDbArcDimension::centerPoint)
        .def("setCenterPoint", &PyDbArcDimension::setCenterPoint)
        .def("isPartial", &PyDbArcDimension::isPartial)
        .def("setIsPartial", &PyDbArcDimension::setIsPartial)
        .def("arcStartParam", &PyDbArcDimension::arcStartParam)
        .def("setArcStartParam", &PyDbArcDimension::setArcStartParam)
        .def("arcEndParam", &PyDbArcDimension::arcEndParam)
        .def("setArcEndParam", &PyDbArcDimension::setArcEndParam)
        .def("hasLeader", &PyDbArcDimension::hasLeader)
        .def("setHasLeader", &PyDbArcDimension::setHasLeader)
        .def("leader1Point", &PyDbArcDimension::leader1Point)
        .def("setLeader1Point", &PyDbArcDimension::setLeader1Point)
        .def("leader2Point", &PyDbArcDimension::leader2Point)
        .def("setLeader2Point", &PyDbArcDimension::setLeader2Point)
        .def("arcSymbolType", &PyDbArcDimension::arcSymbolType)
        .def("setArcSymbolType", &PyDbArcDimension::setArcSymbolType)
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

PyDbArcDimension::PyDbArcDimension(const AcGePoint3d& centerPoint, const AcGePoint3d& xLine1Point, const AcGePoint3d& xLine2Point, const AcGePoint3d& arcPoint)
    : PyDbDimension(new AcDbArcDimension(centerPoint, xLine1Point, xLine2Point, arcPoint), true)
{
}

PyDbArcDimension::PyDbArcDimension(const AcGePoint3d& centerPoint, const AcGePoint3d& xLine1Point, const AcGePoint3d& xLine2Point, const AcGePoint3d& arcPoint, const std::string& dimText)
    : PyDbDimension(new AcDbArcDimension(centerPoint, xLine1Point, xLine2Point, arcPoint, utf8_to_wstr(dimText).c_str()), true)
{
}

PyDbArcDimension::PyDbArcDimension(const AcGePoint3d& centerPoint, const AcGePoint3d& xLine1Point, const AcGePoint3d& xLine2Point, const AcGePoint3d& arcPoint, const std::string& dimText, const PyDbObjectId& styleId)
    : PyDbDimension(new AcDbArcDimension(centerPoint, xLine1Point, xLine2Point, arcPoint, utf8_to_wstr(dimText).c_str(), styleId.m_id), true)
{
}

AcGePoint3d PyDbArcDimension::arcPoint() const
{
    return impObj()->arcPoint();
}

Acad::ErrorStatus PyDbArcDimension::setArcPoint(const AcGePoint3d& arcPt)
{
    return impObj()->setArcPoint(arcPt);
}

AcGePoint3d PyDbArcDimension::xLine1Point() const
{
    return impObj()->xLine1Point();
}

Acad::ErrorStatus PyDbArcDimension::setXLine1Point(const AcGePoint3d& xLine1Pt)
{
    return impObj()->setXLine1Point(xLine1Pt);
}

AcGePoint3d PyDbArcDimension::xLine2Point() const
{
    return impObj()->xLine2Point();
}

Acad::ErrorStatus PyDbArcDimension::setXLine2Point(const AcGePoint3d& xLine2Pt)
{
    return impObj()->setXLine2Point(xLine2Pt);
}

AcGePoint3d PyDbArcDimension::centerPoint() const
{
    return impObj()->centerPoint();
}

Acad::ErrorStatus PyDbArcDimension::setCenterPoint(const AcGePoint3d& ctrPt)
{
    return impObj()->setCenterPoint(ctrPt);
}

bool PyDbArcDimension::isPartial() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->isPartial();
#endif
}

Acad::ErrorStatus PyDbArcDimension::setIsPartial(bool partial)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setIsPartial(partial);
#endif
}

double PyDbArcDimension::arcStartParam() const
{
    return impObj()->arcStartParam();
}

Acad::ErrorStatus PyDbArcDimension::setArcStartParam(double arcParam)
{
    return impObj()->setArcStartParam(arcParam);
}

double PyDbArcDimension::arcEndParam() const
{
    return impObj()->arcEndParam();
}

Acad::ErrorStatus PyDbArcDimension::setArcEndParam(double arcParam)
{
    return impObj()->setArcEndParam(arcParam);
}

bool PyDbArcDimension::hasLeader() const
{
    return impObj()->hasLeader();
}

Acad::ErrorStatus PyDbArcDimension::setHasLeader(bool leaderVal)
{
    return impObj()->setHasLeader(leaderVal);
}

AcGePoint3d PyDbArcDimension::leader1Point() const
{
    return impObj()->leader1Point();
}

Acad::ErrorStatus PyDbArcDimension::setLeader1Point(const AcGePoint3d& ldr1Pt)
{
    return impObj()->setLeader1Point(ldr1Pt);
}

AcGePoint3d PyDbArcDimension::leader2Point() const
{
    return impObj()->leader2Point();
}

Acad::ErrorStatus PyDbArcDimension::setLeader2Point(const AcGePoint3d& ldr2Pt)
{
    return impObj()->setLeader2Point(ldr2Pt);
}

int PyDbArcDimension::arcSymbolType() const
{
    return impObj()->arcSymbolType();
}

Acad::ErrorStatus PyDbArcDimension::setArcSymbolType(int symbol)
{
    return impObj()->setArcSymbolType(symbol);
}

std::string PyDbArcDimension::className()
{
    return "AcDbArcDimension";
}

AcDbArcDimension* PyDbArcDimension::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbArcDimension*>(m_pImp.get());
}

//-----------------------------------------------------------------------------------
//AcDbDiametricDimension
void makeDiametricDimensionWrapper()
{
    class_<PyDbDiametricDimension, bases<PyDbDimension>>("DiametricDimension")
        .def(init<>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const AcGePoint3d&, const AcGePoint3d&, double>())
        .def(init<const AcGePoint3d&, const AcGePoint3d&, double, const std::string&>())
        .def(init<const AcGePoint3d&, const AcGePoint3d&, double, const std::string&, const PyDbObjectId&>())
        .def("leaderLength", &PyDbDiametricDimension::leaderLength)
        .def("setLeaderLength", &PyDbDiametricDimension::setLeaderLength)
        .def("chordPoint", &PyDbDiametricDimension::chordPoint)
        .def("setChordPoint", &PyDbDiametricDimension::setChordPoint)
        .def("farChordPoint", &PyDbDiametricDimension::farChordPoint)
        .def("setFarChordPoint", &PyDbDiametricDimension::setFarChordPoint)
        .def("extArcStartAngle", &PyDbDiametricDimension::extArcStartAngle)
        .def("setExtArcStartAngle", &PyDbDiametricDimension::setExtArcStartAngle)
        .def("extArcEndAngle", &PyDbDiametricDimension::extArcEndAngle)
        .def("setExtArcEndAngle", &PyDbDiametricDimension::setExtArcEndAngle)
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

PyDbDiametricDimension::PyDbDiametricDimension(const AcGePoint3d& chordPoint, const AcGePoint3d& farChordPoint, double leaderLength)
    : PyDbDimension(new AcDbDiametricDimension(chordPoint, farChordPoint, leaderLength), true)
{
}

PyDbDiametricDimension::PyDbDiametricDimension(const AcGePoint3d& chordPoint, const AcGePoint3d& farChordPoint, double leaderLength, const std::string& dimText)
    : PyDbDimension(new AcDbDiametricDimension(chordPoint, farChordPoint, leaderLength, utf8_to_wstr(dimText).c_str()), true)
{
}

PyDbDiametricDimension::PyDbDiametricDimension(const AcGePoint3d& chordPoint, const AcGePoint3d& farChordPoint, double leaderLength, const std::string& dimText, const PyDbObjectId& styleId)
    : PyDbDimension(new AcDbDiametricDimension(chordPoint, farChordPoint, leaderLength, utf8_to_wstr(dimText).c_str(), styleId.m_id), true)
{
}

double PyDbDiametricDimension::leaderLength() const
{
    return impObj()->leaderLength();
}

Acad::ErrorStatus PyDbDiametricDimension::setLeaderLength(double val)
{
    return impObj()->setLeaderLength(val);
}

AcGePoint3d PyDbDiametricDimension::chordPoint() const
{
    return impObj()->chordPoint();
}

Acad::ErrorStatus PyDbDiametricDimension::setChordPoint(const AcGePoint3d& val)
{
    return impObj()->setChordPoint(val);
}

AcGePoint3d PyDbDiametricDimension::farChordPoint() const
{
    return impObj()->farChordPoint();
}

Acad::ErrorStatus PyDbDiametricDimension::setFarChordPoint(const AcGePoint3d& val)
{
    return impObj()->setFarChordPoint(val);
}

double PyDbDiametricDimension::extArcStartAngle() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->extArcStartAngle();
#endif
}

Acad::ErrorStatus PyDbDiametricDimension::setExtArcStartAngle(double newAngle)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setExtArcStartAngle(newAngle);
#endif
}

double PyDbDiametricDimension::extArcEndAngle() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->extArcEndAngle();
#endif
}

Acad::ErrorStatus PyDbDiametricDimension::setExtArcEndAngle(double newAngle)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setExtArcEndAngle(newAngle);
#endif
}

std::string PyDbDiametricDimension::className()
{
    return "AcDbDiametricDimension";
}

AcDbDiametricDimension* PyDbDiametricDimension::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbDiametricDimension*>(m_pImp.get());
}

//-----------------------------------------------------------------------------------
//AcDbOrdinateDimension
void makeOrdinateDimensionWrapper()
{
    class_<PyDbOrdinateDimension, bases<PyDbDimension>>("OrdinateDimension")
        .def(init<>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<Adesk::Boolean, const AcGePoint3d&, const AcGePoint3d&>())
        .def(init<Adesk::Boolean, const AcGePoint3d&, const AcGePoint3d&, const std::string&>())
        .def(init<Adesk::Boolean, const AcGePoint3d&, const AcGePoint3d&, const std::string&, const PyDbObjectId&>())
        .def("isUsingXAxis", &PyDbOrdinateDimension::isUsingXAxis)
        .def("isUsingYAxis", &PyDbOrdinateDimension::isUsingYAxis)
        .def("useXAxis", &PyDbOrdinateDimension::useXAxis)
        .def("useYAxis", &PyDbOrdinateDimension::useYAxis)
        .def("setUsingXAxis", &PyDbOrdinateDimension::setUsingXAxis)
        .def("setUsingYAxis", &PyDbOrdinateDimension::setUsingYAxis)
        .def("origin", &PyDbOrdinateDimension::origin)
        .def("setOrigin", &PyDbOrdinateDimension::setOrigin)
        .def("definingPoint", &PyDbOrdinateDimension::definingPoint)
        .def("setDefiningPoint", &PyDbOrdinateDimension::setDefiningPoint)
        .def("leaderEndPoint", &PyDbOrdinateDimension::leaderEndPoint)
        .def("setLeaderEndPoint", &PyDbOrdinateDimension::setLeaderEndPoint)
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

PyDbOrdinateDimension::PyDbOrdinateDimension(Adesk::Boolean useXAxis, const AcGePoint3d& definingPoint, const AcGePoint3d& leaderEndPoint)
    : PyDbDimension(new AcDbOrdinateDimension(useXAxis, definingPoint, leaderEndPoint), true)
{
}

PyDbOrdinateDimension::PyDbOrdinateDimension(Adesk::Boolean useXAxis, const AcGePoint3d& definingPoint, const AcGePoint3d& leaderEndPoint, const std::string& dimText)
    : PyDbDimension(new AcDbOrdinateDimension(useXAxis, definingPoint, leaderEndPoint, utf8_to_wstr(dimText).c_str()), true)
{
}

PyDbOrdinateDimension::PyDbOrdinateDimension(Adesk::Boolean useXAxis, const AcGePoint3d& definingPoint, const AcGePoint3d& leaderEndPoint, const std::string& dimText, const PyDbObjectId& styleId)
    : PyDbDimension(new AcDbOrdinateDimension(useXAxis, definingPoint, leaderEndPoint, utf8_to_wstr(dimText).c_str(), styleId.m_id), true)
{
}

Adesk::Boolean PyDbOrdinateDimension::isUsingXAxis() const
{
    return impObj()->isUsingXAxis();
}

Adesk::Boolean PyDbOrdinateDimension::isUsingYAxis() const
{
    return impObj()->isUsingYAxis();
}

Acad::ErrorStatus PyDbOrdinateDimension::useXAxis()
{
    return impObj()->useXAxis();
}

Acad::ErrorStatus PyDbOrdinateDimension::useYAxis()
{
    return impObj()->useYAxis();
}

Acad::ErrorStatus PyDbOrdinateDimension::setUsingXAxis(bool value)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setUsingXAxis(value);
#endif
}

Acad::ErrorStatus PyDbOrdinateDimension::setUsingYAxis(bool value)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setUsingYAxis(value);
#endif
}

AcGePoint3d PyDbOrdinateDimension::origin() const
{
    return impObj()->origin();
}

Acad::ErrorStatus PyDbOrdinateDimension::setOrigin(const AcGePoint3d& val)
{
    return impObj()->setOrigin(val);
}

AcGePoint3d PyDbOrdinateDimension::definingPoint() const
{
    return impObj()->definingPoint();
}

Acad::ErrorStatus PyDbOrdinateDimension::setDefiningPoint(const AcGePoint3d& val)
{
    return impObj()->setDefiningPoint(val);
}

AcGePoint3d PyDbOrdinateDimension::leaderEndPoint() const
{
    return impObj()->leaderEndPoint();
}

Acad::ErrorStatus PyDbOrdinateDimension::setLeaderEndPoint(const AcGePoint3d& val)
{
    return impObj()->setLeaderEndPoint(val);
}

std::string PyDbOrdinateDimension::className()
{
    return "AcDbOrdinateDimension";
}

AcDbOrdinateDimension* PyDbOrdinateDimension::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbOrdinateDimension*>(m_pImp.get());
}

//-----------------------------------------------------------------------------------
//AcDbRadialDimension
void makeRadialDimensionWrapper()
{
    class_<PyDbRadialDimension, bases<PyDbDimension>>("RadialDimension")
        .def(init<>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const AcGePoint3d&, const AcGePoint3d&, double>())
        .def(init<const AcGePoint3d&, const AcGePoint3d&, double, const std::string&>())
        .def(init<const AcGePoint3d&, const AcGePoint3d&, double, const std::string&, const PyDbObjectId&>())
        .def("leaderLength", &PyDbRadialDimension::leaderLength)
        .def("setLeaderLength", &PyDbRadialDimension::setLeaderLength)
        .def("center", &PyDbRadialDimension::center)
        .def("setCenter", &PyDbRadialDimension::setCenter)
        .def("chordPoint", &PyDbRadialDimension::chordPoint)
        .def("setChordPoint", &PyDbRadialDimension::setChordPoint)
        .def("extArcStartAngle", &PyDbRadialDimension::extArcStartAngle)
        .def("setExtArcStartAngle", &PyDbRadialDimension::setExtArcStartAngle)
        .def("extArcEndAngle", &PyDbRadialDimension::extArcEndAngle)
        .def("setExtArcEndAngle", &PyDbRadialDimension::setExtArcEndAngle)
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

PyDbRadialDimension::PyDbRadialDimension(const AcGePoint3d& center, const AcGePoint3d& chordPoint, double leaderLength)
    : PyDbDimension(new AcDbRadialDimension(center, chordPoint, leaderLength), true)
{
}

PyDbRadialDimension::PyDbRadialDimension(const AcGePoint3d& center, const AcGePoint3d& chordPoint, double leaderLength, const std::string& dimText)
    : PyDbDimension(new AcDbRadialDimension(center, chordPoint, leaderLength, utf8_to_wstr(dimText).c_str()), true)
{
}

PyDbRadialDimension::PyDbRadialDimension(const AcGePoint3d& center, const AcGePoint3d& chordPoint, double leaderLength, const std::string& dimText, const PyDbObjectId& styleId)
    : PyDbDimension(new AcDbRadialDimension(center, chordPoint, leaderLength, utf8_to_wstr(dimText).c_str(), styleId.m_id), true)
{
}

double PyDbRadialDimension::leaderLength() const
{
    return impObj()->leaderLength();
}

Acad::ErrorStatus PyDbRadialDimension::setLeaderLength(double val)
{
    return impObj()->setLeaderLength(val);
}

AcGePoint3d PyDbRadialDimension::center() const
{
    return impObj()->center();
}

Acad::ErrorStatus PyDbRadialDimension::setCenter(const AcGePoint3d& val)
{
    return impObj()->setCenter(val);
}

AcGePoint3d PyDbRadialDimension::chordPoint() const
{
    return impObj()->chordPoint();
}

Acad::ErrorStatus PyDbRadialDimension::setChordPoint(const AcGePoint3d& val)
{
    return impObj()->setChordPoint(val);
}

double PyDbRadialDimension::extArcStartAngle() const
{
    return impObj()->extArcStartAngle();
}

Acad::ErrorStatus PyDbRadialDimension::setExtArcStartAngle(double newAngle)
{
    return impObj()->setExtArcStartAngle(newAngle);
}

double PyDbRadialDimension::extArcEndAngle() const
{
    return impObj()->extArcEndAngle();
}

Acad::ErrorStatus PyDbRadialDimension::setExtArcEndAngle(double newAngle)
{
    return impObj()->setExtArcEndAngle(newAngle);
}

std::string PyDbRadialDimension::className()
{
    return "AcDbRadialDimension";
}

AcDbRadialDimension* PyDbRadialDimension::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbRadialDimension*>(m_pImp.get());
}

//-----------------------------------------------------------------------------------
//AcDbRadialDimensionLarge
void makeRadialDimensionLargeWrapper()
{
    class_<PyDbRadialDimensionLarge, bases<PyDbDimension>>("RadialDimensionLarge")
        .def(init<>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&, double>())
        .def(init<const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&, double, const std::string&>())
        .def(init<const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&, double, const std::string&, const PyDbObjectId&>())
        .def("center", &PyDbRadialDimensionLarge::center)
        .def("setCenter", &PyDbRadialDimensionLarge::setCenter)
        .def("chordPoint", &PyDbRadialDimensionLarge::chordPoint)
        .def("setChordPoint", &PyDbRadialDimensionLarge::setChordPoint)
        .def("overrideCenter", &PyDbRadialDimensionLarge::overrideCenter)
        .def("setOverrideCenter", &PyDbRadialDimensionLarge::setOverrideCenter)
        .def("jogPoint", &PyDbRadialDimensionLarge::jogPoint)
        .def("setJogPoint", &PyDbRadialDimensionLarge::setJogPoint)
        .def("jogAngle", &PyDbRadialDimensionLarge::jogAngle)
        .def("setJogAngle", &PyDbRadialDimensionLarge::setJogAngle)
        .def("setOverrideCenterPP", &PyDbRadialDimensionLarge::setOverrideCenterPP)
        .def("setJogPointPP", &PyDbRadialDimensionLarge::setJogPointPP)
        .def("setTextPositionPP", &PyDbRadialDimensionLarge::setTextPositionPP)
        .def("extArcStartAngle", &PyDbRadialDimensionLarge::extArcStartAngle)
        .def("setExtArcStartAngle", &PyDbRadialDimensionLarge::setExtArcStartAngle)
        .def("extArcEndAngle", &PyDbRadialDimensionLarge::extArcEndAngle)
        .def("setExtArcEndAngle", &PyDbRadialDimensionLarge::setExtArcEndAngle)
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

PyDbRadialDimensionLarge::PyDbRadialDimensionLarge(const AcGePoint3d& center, const AcGePoint3d& chordPoint, const AcGePoint3d& overrideCenter, const AcGePoint3d& jogPoint, double jogAngle)
    : PyDbDimension(new AcDbRadialDimensionLarge(center, chordPoint, overrideCenter, jogPoint, jogAngle), true)
{
}

PyDbRadialDimensionLarge::PyDbRadialDimensionLarge(const AcGePoint3d& center, const AcGePoint3d& chordPoint, const AcGePoint3d& overrideCenter, const AcGePoint3d& jogPoint, double jogAngle, const std::string& dimText)
    : PyDbDimension(new AcDbRadialDimensionLarge(center, chordPoint, overrideCenter, jogPoint, jogAngle, utf8_to_wstr(dimText).c_str()), true)
{
}

PyDbRadialDimensionLarge::PyDbRadialDimensionLarge(const AcGePoint3d& center, const AcGePoint3d& chordPoint, const AcGePoint3d& overrideCenter, const AcGePoint3d& jogPoint, double jogAngle, const std::string& dimText, const PyDbObjectId& styleId)
    : PyDbDimension(new AcDbRadialDimensionLarge(center, chordPoint, overrideCenter, jogPoint, jogAngle, utf8_to_wstr(dimText).c_str(), styleId.m_id), true)
{
}

AcGePoint3d PyDbRadialDimensionLarge::center() const
{
    return impObj()->center();
}

Acad::ErrorStatus PyDbRadialDimensionLarge::setCenter(const AcGePoint3d& centerPoint)
{
    return impObj()->setCenter(centerPoint);
}

AcGePoint3d PyDbRadialDimensionLarge::chordPoint() const
{
    return impObj()->chordPoint();
}

Acad::ErrorStatus PyDbRadialDimensionLarge::setChordPoint(const AcGePoint3d& chordPoint)
{
    return impObj()->setChordPoint(chordPoint);
}

AcGePoint3d PyDbRadialDimensionLarge::overrideCenter() const
{
    return impObj()->overrideCenter();
}

Acad::ErrorStatus PyDbRadialDimensionLarge::setOverrideCenter(const AcGePoint3d& overrideCenterPoint)
{
    return impObj()->setOverrideCenter(overrideCenterPoint);
}

AcGePoint3d PyDbRadialDimensionLarge::jogPoint() const
{
    return impObj()->jogPoint();
}

Acad::ErrorStatus PyDbRadialDimensionLarge::setJogPoint(const AcGePoint3d& jogPoint)
{
    return impObj()->setJogPoint(jogPoint);
}

double PyDbRadialDimensionLarge::jogAngle() const
{
    return impObj()->jogAngle();
}

Acad::ErrorStatus PyDbRadialDimensionLarge::setJogAngle(double jogAngle)
{
    return impObj()->setJogAngle(jogAngle);
}

Acad::ErrorStatus PyDbRadialDimensionLarge::setOverrideCenterPP(const AcGePoint3d& overrideCenterPointPP)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setOverrideCenterPP(overrideCenterPointPP);
#endif
}

Acad::ErrorStatus PyDbRadialDimensionLarge::setJogPointPP(const AcGePoint3d& jogPointPP)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setJogPointPP(jogPointPP);
#endif
}

Acad::ErrorStatus PyDbRadialDimensionLarge::setTextPositionPP(const AcGePoint3d& textPointPP)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setTextPositionPP(textPointPP);
#endif
}

double PyDbRadialDimensionLarge::extArcStartAngle() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->extArcStartAngle();
#endif
}

Acad::ErrorStatus PyDbRadialDimensionLarge::setExtArcStartAngle(double newAngle)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setExtArcStartAngle(newAngle);
#endif
}

double PyDbRadialDimensionLarge::extArcEndAngle() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->extArcEndAngle();
#endif
}

Acad::ErrorStatus PyDbRadialDimensionLarge::setExtArcEndAngle(double newAngle)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setExtArcEndAngle(newAngle);
#endif
}

std::string PyDbRadialDimensionLarge::className()
{
    return "AcDbRadialDimension";
}

AcDbRadialDimensionLarge* PyDbRadialDimensionLarge::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbRadialDimensionLarge*>(m_pImp.get());
}

//-----------------------------------------------------------------------------------
//AcDbRotatedDimension
void makeRotatedDimensionWrapper()
{
    class_<PyDbRotatedDimension, bases<PyDbDimension>>("RotatedDimension")
        .def(init<>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<double, const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&>())
        .def(init<double, const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&, const std::string&>())
        .def(init<double, const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&, const std::string&, const PyDbObjectId&>())
        .def("xLine1Point", &PyDbRotatedDimension::xLine1Point)
        .def("setXLine1Point", &PyDbRotatedDimension::setXLine1Point)
        .def("xLine2Point", &PyDbRotatedDimension::xLine2Point)
        .def("setXLine2Point", &PyDbRotatedDimension::setXLine2Point)
        .def("dimLinePoint", &PyDbRotatedDimension::dimLinePoint)
        .def("setDimLinePoint", &PyDbRotatedDimension::setDimLinePoint)
        .def("oblique", &PyDbRotatedDimension::oblique)
        .def("setOblique", &PyDbRotatedDimension::setOblique)
        .def("rotation", &PyDbRotatedDimension::rotation)
        .def("setRotation", &PyDbRotatedDimension::setRotation)
        .def("jogSymbolOn", &PyDbRotatedDimension::jogSymbolOn)
        .def("setJogSymbolOn", &PyDbRotatedDimension::setJogSymbolOn)
        .def("jogSymbolPosition", &PyDbRotatedDimension::jogSymbolPosition)
        .def("setJogSymbolPosition", &PyDbRotatedDimension::setJogSymbolPosition)
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

PyDbRotatedDimension::PyDbRotatedDimension(double rotation, const AcGePoint3d& xLine1Point, const AcGePoint3d& xLine2Point, const AcGePoint3d& dimLinePoint)
    : PyDbDimension(new AcDbRotatedDimension(rotation, xLine1Point, xLine2Point, dimLinePoint), true)
{
}

PyDbRotatedDimension::PyDbRotatedDimension(double rotation, const AcGePoint3d& xLine1Point, const AcGePoint3d& xLine2Point, const AcGePoint3d& dimLinePoint, const std::string& dimText)
    : PyDbDimension(new AcDbRotatedDimension(rotation, xLine1Point, xLine2Point, dimLinePoint, utf8_to_wstr(dimText).c_str()), true)
{
}

PyDbRotatedDimension::PyDbRotatedDimension(double rotation, const AcGePoint3d& xLine1Point, const AcGePoint3d& xLine2Point, const AcGePoint3d& dimLinePoint, const std::string& dimText, const PyDbObjectId& styleId)
    : PyDbDimension(new AcDbRotatedDimension(rotation, xLine1Point, xLine2Point, dimLinePoint, utf8_to_wstr(dimText).c_str(), styleId.m_id), true)
{
}

AcGePoint3d PyDbRotatedDimension::xLine1Point() const
{
    return impObj()->xLine1Point();
}

Acad::ErrorStatus PyDbRotatedDimension::setXLine1Point(const AcGePoint3d& val)
{
    return impObj()->setXLine1Point(val);
}

AcGePoint3d PyDbRotatedDimension::xLine2Point() const
{
    return impObj()->xLine2Point();
}

Acad::ErrorStatus PyDbRotatedDimension::setXLine2Point(const AcGePoint3d& val)
{
    return impObj()->setXLine2Point(val);
}

AcGePoint3d PyDbRotatedDimension::dimLinePoint() const
{
    return impObj()->dimLinePoint();
}

Acad::ErrorStatus PyDbRotatedDimension::setDimLinePoint(const AcGePoint3d& val)
{
    return impObj()->setDimLinePoint(val);
}

double PyDbRotatedDimension::oblique() const
{
    return impObj()->oblique();
}

Acad::ErrorStatus PyDbRotatedDimension::setOblique(double val)
{
    return impObj()->setOblique(val);
}

double PyDbRotatedDimension::rotation() const
{
    return impObj()->rotation();
}

Acad::ErrorStatus PyDbRotatedDimension::setRotation(double val)
{
    return impObj()->setRotation(val);
}

bool PyDbRotatedDimension::jogSymbolOn() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->jogSymbolOn();
#endif
}

Acad::ErrorStatus PyDbRotatedDimension::setJogSymbolOn(bool val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setJogSymbolOn(val);
#endif
}

AcGePoint3d PyDbRotatedDimension::jogSymbolPosition() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->jogSymbolPosition();
#endif
}

Acad::ErrorStatus PyDbRotatedDimension::setJogSymbolPosition(const AcGePoint3d& val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    return impObj()->setJogSymbolPosition(val);
#endif
}

std::string PyDbRotatedDimension::className()
{
    return "AcDbRotatedDimension";
}

AcDbRotatedDimension* PyDbRotatedDimension::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pImp == nullptr)
        throw PyNullObject(src);
    return static_cast<AcDbRotatedDimension*>(m_pImp.get());
}
