#include "stdafx.h"
#include "PyDbDimension.h"
#include "PyDbObjectId.h"
#include "PyDbMtext.h"



using namespace boost::python;

//-----------------------------------------------------------------------------------
//PyDbDimension
void makePyDbDimensionWrapper()
{
    PyDocString DS("Dimension");
    class_<PyDbDimension, bases<PyDbEntity>>("Dimension", no_init)
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("textDefinedSize", &PyDbDimension::textDefinedSize, DS.ARGS())
        .def("setTextDefinedSize", &PyDbDimension::setTextDefinedSize, DS.ARGS({ "width : real", "height : real" }))
        .def("resetTextDefinedSize", &PyDbDimension::resetTextDefinedSize, DS.ARGS())
        .def("textPosition", &PyDbDimension::textPosition, DS.ARGS())
        .def("setTextPosition", &PyDbDimension::setTextPosition, DS.ARGS({ "val : PyGe.Point3d" }))
        .def("isUsingDefaultTextPosition", &PyDbDimension::isUsingDefaultTextPosition, DS.ARGS())
        .def("useSetTextPosition", &PyDbDimension::useSetTextPosition, DS.ARGS())
        .def("useDefaultTextPosition", &PyDbDimension::useDefaultTextPosition, DS.ARGS())
        .def("setUsingDefaultTextPosition", &PyDbDimension::setUsingDefaultTextPosition, DS.ARGS({ "val : bool" }))
        .def("normal", &PyDbDimension::normal, DS.ARGS())
        .def("setNormal", &PyDbDimension::setNormal, DS.ARGS({ "val : PyGe.Vector3d" }))
        .def("elevation", &PyDbDimension::elevation, DS.ARGS())
        .def("setElevation", &PyDbDimension::setElevation, DS.ARGS({ "val : real" }))
        .def("dimensionText", &PyDbDimension::dimensionText, DS.ARGS())
        .def("setDimensionText", &PyDbDimension::setDimensionText, DS.ARGS({ "val : str" }))
        .def("textRotation", &PyDbDimension::textRotation, DS.ARGS())
        .def("setTextRotation", &PyDbDimension::setTextRotation, DS.ARGS({ "val : real" }))
        .def("dimensionStyle", &PyDbDimension::dimensionStyle, DS.ARGS())
        .def("setDimensionStyle", &PyDbDimension::setDimensionStyle, DS.ARGS({ "val : PyDb.ObjectId" }))
        .def("textAttachment", &PyDbDimension::textAttachment, DS.ARGS())
        .def("setTextAttachment", &PyDbDimension::setTextAttachment, DS.ARGS({ "val : PyDb.MTextAttachmentPoint" }))
        .def("textLineSpacingStyle", &PyDbDimension::textLineSpacingStyle, DS.ARGS())
        .def("setTextLineSpacingStyle", &PyDbDimension::setTextLineSpacingStyle, DS.ARGS({ "val : PyDb.LineSpacingStyle" }))
        .def("textLineSpacingFactor", &PyDbDimension::textLineSpacingFactor, DS.ARGS())
        .def("setTextLineSpacingFactor", &PyDbDimension::setTextLineSpacingFactor, DS.ARGS({ "val : real" }))
        .def("getDimstyleData", &PyDbDimension::getDimstyleData, DS.ARGS())
        .def("setDimstyleData", &PyDbDimension::setDimstyleData1)
        .def("setDimstyleData", &PyDbDimension::setDimstyleData2)
        .def("horizontalRotation", &PyDbDimension::horizontalRotation, DS.ARGS())
        .def("setHorizontalRotation", &PyDbDimension::setHorizontalRotation, DS.ARGS({ "val : real" }))
        .def("dimBlockId", &PyDbDimension::dimBlockId, DS.ARGS())
        .def("setDimBlockId", &PyDbDimension::setDimBlockId, DS.ARGS({ "val : PyDb.ObjectId" }))
        .def("dimBlockPosition", &PyDbDimension::dimBlockPosition, DS.ARGS())
        .def("setDimBlockPosition", &PyDbDimension::setDimBlockPosition, DS.ARGS({ "val : PyGe.Point3d" }))
        .def("recomputeDimBlock", &PyDbDimension::recomputeDimBlock1)
        .def("recomputeDimBlock", &PyDbDimension::recomputeDimBlock2, DS.ARGS({ "force : bool=False" }))
        .def("generateLayout", &PyDbDimension::generateLayout, DS.ARGS())
        .def("measurement", &PyDbDimension::measurement, DS.ARGS())
        .def("formatMeasurement", &PyDbDimension::formatMeasurement1)
        .def("formatMeasurement", &PyDbDimension::formatMeasurement2)
        .def("isDynamicDimension", &PyDbDimension::isDynamicDimension, DS.ARGS())
        .def("setDynamicDimension", &PyDbDimension::setDynamicDimension, DS.ARGS({ "val : bool" }))
        .def("dimLineLinetype", &PyDbDimension::dimLineLinetype, DS.ARGS())
        .def("setDimLineLinetype", &PyDbDimension::setDimLineLinetype, DS.ARGS({ "val : PyDb.ObjectId" }))
        .def("dimExt1Linetype", &PyDbDimension::dimExt1Linetype, DS.ARGS())
        .def("setDimExt1Linetype", &PyDbDimension::setDimExt1Linetype, DS.ARGS({ "val : PyDb.ObjectId" }))
        .def("dimExt2Linetype", &PyDbDimension::dimExt2Linetype, DS.ARGS())
        .def("setDimExt2Linetype", &PyDbDimension::setDimExt2Linetype, DS.ARGS({ "val : PyDb.ObjectId" }))
        .def("removeTextField", &PyDbDimension::removeTextField, DS.ARGS())
        .def("fieldToMText", &PyDbDimension::fieldToMText, DS.ARGS({ "ref : PyDb.MText" }))
        .def("fieldFromMText", &PyDbDimension::fieldFromMText, DS.ARGS({ "ref : PyDb.MText" }))
        .def("isHorizontalRefTextRotation", &PyDbDimension::isHorizontalRefTextRotation, DS.ARGS())
        .def("setHorizontalRefTextRotation", &PyDbDimension::setHorizontalRefTextRotation, DS.ARGS({ "val : bool" }))
        .def("getArrowFirstIsFlipped", &PyDbDimension::getArrowFirstIsFlipped, DS.ARGS())
        .def("getArrowSecondIsFlipped", &PyDbDimension::getArrowSecondIsFlipped, DS.ARGS())
        .def("setArrowFirstIsFlipped", &PyDbDimension::setArrowFirstIsFlipped, DS.ARGS({ "val : bool" }))
        .def("setArrowSecondIsFlipped", &PyDbDimension::setArrowSecondIsFlipped, DS.ARGS({ "val : bool" }))
        .def("blockTransform", &PyDbDimension::blockTransform, DS.ARGS())
        .def("inspection", &PyDbDimension::inspection, DS.ARGS())
        .def("setInspection", &PyDbDimension::setInspection, DS.ARGS({ "val : bool" }))
        .def("inspectionFrame", &PyDbDimension::inspectionFrame, DS.ARGS())
        .def("setInspectionFrame", &PyDbDimension::setInspectionFrame, DS.ARGS({ "val : int" }))
        .def("inspectionLabel", &PyDbDimension::inspectionLabel, DS.ARGS())
        .def("setInspectionLabel", &PyDbDimension::setInspectionLabel, DS.ARGS({ "val : str" }))
        .def("isConstraintObject", &PyDbDimension::isConstraintObject, DS.ARGS())
        .def("isConstraintDynamic", &PyDbDimension::isConstraintDynamic, DS.ARGS())
        .def("setConstraintDynamic", &PyDbDimension::setConstraintDynamic, DS.ARGS({ "val : bool" }))
        .def("shouldParticipateInOPM", &PyDbDimension::shouldParticipateInOPM, DS.ARGS())
        .def("setShouldParticipateInOPM", &PyDbDimension::setShouldParticipateInOPM, DS.ARGS({ "val : bool" }))
        .def("centerMarkSize", &PyDbDimension::centerMarkSize, DS.ARGS())
        .def("prefix", &PyDbDimension::prefix, DS.ARGS())
        .def("setPrefix", &PyDbDimension::setPrefix, DS.ARGS({ "val : str" }))
        .def("suffix", &PyDbDimension::suffix, DS.ARGS())
        .def("setSuffix", &PyDbDimension::setSuffix, DS.ARGS({ "val : str" }))
        .def("alternateSuffix", &PyDbDimension::alternateSuffix, DS.ARGS())
        .def("setAlternateSuffix", &PyDbDimension::setAlternateSuffix, DS.ARGS({ "val : str" }))
        .def("alternatePrefix", &PyDbDimension::alternatePrefix, DS.ARGS())
        .def("setAlternatePrefix", &PyDbDimension::setAlternatePrefix, DS.ARGS({ "val : str" }))
        .def("suppressAngularLeadingZeros", &PyDbDimension::suppressAngularLeadingZeros, DS.ARGS())
        .def("suppressAngularTrailingZeros", &PyDbDimension::suppressAngularTrailingZeros, DS.ARGS())
        .def("setSuppressAngularTrailingZeros", &PyDbDimension::setSuppressAngularTrailingZeros, DS.ARGS({ "val : bool" }))
        .def("altSuppressZeroInches", &PyDbDimension::altSuppressZeroInches, DS.ARGS())
        .def("setAltSuppressZeroInches", &PyDbDimension::setAltSuppressZeroInches, DS.ARGS({ "val : bool" }))
        .def("altSuppressZeroFeet", &PyDbDimension::altSuppressZeroFeet, DS.ARGS())
        .def("setAltSuppressZeroFeet", &PyDbDimension::setAltSuppressZeroFeet, DS.ARGS({ "val : bool" }))
        .def("altSuppressTrailingZeros", &PyDbDimension::altSuppressTrailingZeros, DS.ARGS())
        .def("setAltSuppressTrailingZeros", &PyDbDimension::setAltSuppressTrailingZeros, DS.ARGS({ "val : bool" }))
        .def("altToleranceSuppressLeadingZeros", &PyDbDimension::altToleranceSuppressLeadingZeros, DS.ARGS())
        .def("setAltToleranceSuppressLeadingZeros", &PyDbDimension::setAltToleranceSuppressLeadingZeros, DS.ARGS({ "val : bool" }))
        .def("altToleranceSuppressZeroInches", &PyDbDimension::altToleranceSuppressZeroInches, DS.ARGS())
        .def("setAltToleranceSuppressZeroInches", &PyDbDimension::setAltToleranceSuppressZeroInches, DS.ARGS({ "val : bool" }))
        .def("altToleranceSuppressZeroFeet", &PyDbDimension::altToleranceSuppressZeroFeet, DS.ARGS())
        .def("setAltToleranceSuppressZeroFeet", &PyDbDimension::setAltToleranceSuppressZeroFeet, DS.ARGS({ "val : bool" }))
        .def("altToleranceSuppressTrailingZeros", &PyDbDimension::altToleranceSuppressTrailingZeros, DS.ARGS())
        .def("setAltToleranceSuppressTrailingZeros", &PyDbDimension::setAltToleranceSuppressTrailingZeros, DS.ARGS({ "val : bool" }))
        .def("suppressZeroFeet", &PyDbDimension::suppressZeroFeet, DS.ARGS())
        .def("setSuppressZeroFeet", &PyDbDimension::setSuppressZeroFeet, DS.ARGS({ "val : bool" }))
        .def("suppressTrailingZeros", &PyDbDimension::suppressTrailingZeros, DS.ARGS())
        .def("setSuppressTrailingZeros", &PyDbDimension::setSuppressTrailingZeros, DS.ARGS({ "val : bool" }))
        .def("suppressLeadingZeros", &PyDbDimension::suppressLeadingZeros, DS.ARGS())
        .def("setSuppressLeadingZeros", &PyDbDimension::setSuppressLeadingZeros, DS.ARGS({ "val : bool" }))
        .def("suppressZeroInches", &PyDbDimension::suppressZeroInches, DS.ARGS())
        .def("setSuppressZeroInches", &PyDbDimension::setSuppressZeroInches, DS.ARGS({ "val : bool" }))
        .def("altSuppressLeadingZeros", &PyDbDimension::altSuppressLeadingZeros, DS.ARGS())
        .def("setAltSuppressLeadingZeros", &PyDbDimension::setAltSuppressLeadingZeros, DS.ARGS({ "val : bool" }))
        .def("toleranceSuppressZeroFeet", &PyDbDimension::toleranceSuppressZeroFeet, DS.ARGS())
        .def("setToleranceSuppressZeroFeet", &PyDbDimension::setToleranceSuppressZeroFeet, DS.ARGS({ "val : bool" }))
        .def("toleranceSuppressTrailingZeros", &PyDbDimension::toleranceSuppressTrailingZeros, DS.ARGS())
        .def("setToleranceSuppressTrailingZeros", &PyDbDimension::setToleranceSuppressTrailingZeros, DS.ARGS({ "val : bool" }))
        .def("toleranceSuppressLeadingZeros", &PyDbDimension::toleranceSuppressLeadingZeros, DS.ARGS())
        .def("setToleranceSuppressLeadingZeros", &PyDbDimension::setToleranceSuppressLeadingZeros, DS.ARGS({ "val : bool" }))
        .def("toleranceSuppressZeroInches", &PyDbDimension::toleranceSuppressZeroInches, DS.ARGS())
        .def("setToleranceSuppressZeroInches", &PyDbDimension::setToleranceSuppressZeroInches, DS.ARGS({ "val : bool" }))
        .def("className", &PyDbDimension::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbDimension::desc, DS.SARGS()).staticmethod("desc")
        .def("cloneFrom", &PyDbDimension::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbDimension::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;

    enum_<AcDbDimension::DimInspect>("DimInspect")
        .value("kShapeRemove", AcDbDimension::DimInspect::kShapeRemove)
        .value("kShapeRound", AcDbDimension::DimInspect::kShapeRound)
        .value("kShapeAngular", AcDbDimension::DimInspect::kShapeAngular)
        .value("kShapeNone", AcDbDimension::DimInspect::kShapeNone)
        .value("kShapeLabel", AcDbDimension::DimInspect::kShapeLabel)
        .value("kShapeRate", AcDbDimension::DimInspect::kShapeRate)
        .export_values()
        ;

    enum_<AcDbDimension::CenterMarkType>("CenterMarkType")
        .value("kMark", AcDbDimension::CenterMarkType::kMark)
        .value("kLine", AcDbDimension::CenterMarkType::kLine)
        .value("kNone", AcDbDimension::CenterMarkType::kNone)
        .export_values()
        ;
}

PyDbDimension::PyDbDimension(AcDbDimension* ptr, bool autoDelete)
    : PyDbEntity(ptr, autoDelete)
{
}

PyDbDimension::PyDbDimension(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbEntity(openAcDbObject<AcDbDimension>(id, mode), false)
{
}

PyDbDimension::PyDbDimension(const PyDbObjectId& id)
    : PyDbDimension(id, AcDb::OpenMode::kForRead)
{
}

boost::python::tuple PyDbDimension::textDefinedSize() const
{
    PyAutoLockGIL lock;
    double width = 1;
    double height = 1;
    impObj()->textDefinedSize(width, height);
    return boost::python::make_tuple(width, height);
}

void PyDbDimension::setTextDefinedSize(double width, double height)
{
    impObj()->setTextDefinedSize(width, height);
}

void PyDbDimension::resetTextDefinedSize()
{
    impObj()->resetTextDefinedSize();
}

AcGePoint3d PyDbDimension::textPosition() const
{
    return impObj()->textPosition();
}

void PyDbDimension::setTextPosition(const AcGePoint3d& val)
{
    return PyThrowBadEs(impObj()->setTextPosition(val));
}

Adesk::Boolean PyDbDimension::isUsingDefaultTextPosition() const
{
    return impObj()->isUsingDefaultTextPosition();
}

void PyDbDimension::useSetTextPosition()
{
    return PyThrowBadEs(impObj()->useSetTextPosition());
}

void PyDbDimension::useDefaultTextPosition()
{
    return PyThrowBadEs(impObj()->useDefaultTextPosition());
}

void PyDbDimension::setUsingDefaultTextPosition(bool val)
{
    return PyThrowBadEs(impObj()->setUsingDefaultTextPosition(val));
}

AcGeVector3d PyDbDimension::normal() const
{
    return impObj()->normal();
}

void PyDbDimension::setNormal(const AcGeVector3d& val)
{
    return PyThrowBadEs(impObj()->setNormal(val));
}

double PyDbDimension::elevation() const
{
    return impObj()->elevation();
}

void PyDbDimension::setElevation(double val)
{
    return PyThrowBadEs(impObj()->setElevation(val));
}

std::string PyDbDimension::dimensionText() const
{
    return wstr_to_utf8(impObj()->dimensionText());
}

void PyDbDimension::setDimensionText(const std::string& val)
{
    return PyThrowBadEs(impObj()->setDimensionText(utf8_to_wstr(val).c_str()));
}

double PyDbDimension::textRotation() const
{
    return impObj()->textRotation();
}

void PyDbDimension::setTextRotation(double val)
{
    return PyThrowBadEs(impObj()->setTextRotation(val));
}

PyDbObjectId PyDbDimension::dimensionStyle() const
{
    return PyDbObjectId(impObj()->dimensionStyle());
}

void PyDbDimension::setDimensionStyle(const PyDbObjectId& val)
{
    return PyThrowBadEs(impObj()->setDimensionStyle(val.m_id));
}

AcDbMText::AttachmentPoint PyDbDimension::textAttachment() const
{
    return impObj()->textAttachment();
}

void PyDbDimension::setTextAttachment(AcDbMText::AttachmentPoint eAtt)
{
    return PyThrowBadEs(impObj()->setTextAttachment(eAtt));
}

AcDb::LineSpacingStyle PyDbDimension::textLineSpacingStyle() const
{
    return impObj()->textLineSpacingStyle();
}

void PyDbDimension::setTextLineSpacingStyle(AcDb::LineSpacingStyle eStyle)
{
    return PyThrowBadEs(impObj()->setTextLineSpacingStyle(eStyle));
}

double PyDbDimension::textLineSpacingFactor() const
{
    return impObj()->textLineSpacingFactor();
}

void PyDbDimension::setTextLineSpacingFactor(double dFactor)
{
    return PyThrowBadEs(impObj()->setTextLineSpacingFactor(dFactor));
}

PyDbDimStyleTableRecord PyDbDimension::getDimstyleData() const
{
    AcDbDimStyleTableRecord* pSyle = nullptr;
    PyThrowBadEs(impObj()->getDimstyleData(pSyle));
    return PyDbDimStyleTableRecord(pSyle, true);
}

void PyDbDimension::setDimstyleData2(const PyDbDimStyleTableRecord& pNewData)
{
    return PyThrowBadEs(impObj()->setDimstyleData(pNewData.impObj()));
}

void PyDbDimension::setDimstyleData1(const PyDbObjectId& newDataId)
{
    return PyThrowBadEs(impObj()->setDimstyleData(newDataId.m_id));
}

double PyDbDimension::horizontalRotation() const
{
    return impObj()->horizontalRotation();
}

void PyDbDimension::setHorizontalRotation(double newVal)
{
    return PyThrowBadEs(impObj()->setHorizontalRotation(newVal));
}

PyDbObjectId PyDbDimension::dimBlockId() const
{
    return PyDbObjectId(impObj()->dimBlockId());
}

void PyDbDimension::setDimBlockId(const PyDbObjectId& val)
{
    return PyThrowBadEs(impObj()->setDimBlockId(val.m_id));
}

AcGePoint3d PyDbDimension::dimBlockPosition() const
{
    return impObj()->dimBlockPosition();
}

void PyDbDimension::setDimBlockPosition(const AcGePoint3d& val)
{
    return PyThrowBadEs(impObj()->setDimBlockPosition(val));
}

void PyDbDimension::recomputeDimBlock1()
{
    return PyThrowBadEs(impObj()->recomputeDimBlock());
}

void PyDbDimension::recomputeDimBlock2(bool forceUpdate)
{
    return PyThrowBadEs(impObj()->recomputeDimBlock(forceUpdate));
}

void PyDbDimension::generateLayout()
{
    return PyThrowBadEs(impObj()->generateLayout());
}

double PyDbDimension::measurement()
{
    double m = 0;
    PyThrowBadEs(impObj()->measurement(m));
    return m;
}

std::string PyDbDimension::formatMeasurement1(double measurement)
{
    AcString str;
    PyThrowBadEs(impObj()->formatMeasurement(str, measurement));
    return wstr_to_utf8(str);
}

std::string PyDbDimension::formatMeasurement2(double measurement, const std::string& dimensionText)
{
    AcString str;
    PyThrowBadEs(impObj()->formatMeasurement(str, measurement, utf8_to_wstr(dimensionText).c_str()));
    return wstr_to_utf8(str);
}

bool PyDbDimension::isDynamicDimension() const
{
    return impObj()->isDynamicDimension();
}

void PyDbDimension::setDynamicDimension(bool newVal)
{
    return PyThrowBadEs(impObj()->setDynamicDimension(newVal));
}

PyDbObjectId PyDbDimension::dimLineLinetype() const
{
    return PyDbObjectId(impObj()->dimLineLinetype());
}

void PyDbDimension::setDimLineLinetype(const PyDbObjectId& linetype)
{
    return PyThrowBadEs(impObj()->setDimLineLinetype(linetype.m_id));
}

PyDbObjectId PyDbDimension::dimExt1Linetype() const
{
    return PyDbObjectId(impObj()->dimExt1Linetype());
}

void PyDbDimension::setDimExt1Linetype(const PyDbObjectId& linetype)
{
    return PyThrowBadEs(impObj()->setDimExt1Linetype(linetype.m_id));
}

PyDbObjectId PyDbDimension::dimExt2Linetype() const
{
    return PyDbObjectId(impObj()->dimExt2Linetype());
}

void PyDbDimension::setDimExt2Linetype(const PyDbObjectId& linetype)
{
    return PyThrowBadEs(impObj()->setDimExt2Linetype(linetype.m_id));
}

void PyDbDimension::removeTextField()
{
    return PyThrowBadEs(impObj()->removeTextField());
}

void PyDbDimension::fieldToMText(PyDbMText& pDimMText)
{
    return PyThrowBadEs(impObj()->fieldToMText(pDimMText.impObj()));
}

void PyDbDimension::fieldFromMText(PyDbMText& pDimMText)
{
    return PyThrowBadEs(impObj()->fieldFromMText(pDimMText.impObj()));
}

bool PyDbDimension::isHorizontalRefTextRotation() const
{
    return impObj()->isHorizontalRefTextRotation();
}

void PyDbDimension::setHorizontalRefTextRotation(bool newVal)
{
    return PyThrowBadEs(impObj()->setHorizontalRefTextRotation(newVal));
}

bool PyDbDimension::getArrowFirstIsFlipped() const
{
    return impObj()->getArrowFirstIsFlipped();
}

bool PyDbDimension::getArrowSecondIsFlipped() const
{
    return impObj()->getArrowSecondIsFlipped();
}

void PyDbDimension::setArrowFirstIsFlipped(bool bIsFlipped)
{
    return PyThrowBadEs(impObj()->setArrowFirstIsFlipped(bIsFlipped));
}

void PyDbDimension::setArrowSecondIsFlipped(bool bIsFlipped)
{
    return PyThrowBadEs(impObj()->setArrowSecondIsFlipped(bIsFlipped));
}

AcGeMatrix3d PyDbDimension::blockTransform() const
{
    return impObj()->blockTransform();
}

bool PyDbDimension::inspection() const
{
    return impObj()->inspection();
}

void PyDbDimension::setInspection(bool val)
{
    return PyThrowBadEs(impObj()->setInspection(val));
}

int PyDbDimension::inspectionFrame() const
{
    return impObj()->inspectionFrame();
}

void PyDbDimension::setInspectionFrame(int frame)
{
    return PyThrowBadEs(impObj()->setInspectionFrame(frame));
}

const std::string PyDbDimension::inspectionLabel() const
{
    return wstr_to_utf8(impObj()->inspectionLabel());
}

void PyDbDimension::setInspectionLabel(const std::string& label)
{
    return PyThrowBadEs(impObj()->setInspectionLabel(utf8_to_wstr(label).c_str()));
}

boost::python::tuple PyDbDimension::isConstraintObject() const
{
    PyAutoLockGIL lock;
    bool hasExpression = false;
    bool isReferenceConstraint = false;
    bool flag = impObj()->isConstraintObject(hasExpression, isReferenceConstraint);
    return boost::python::make_tuple(flag, hasExpression, isReferenceConstraint);
}

bool PyDbDimension::isConstraintDynamic(void) const
{
    return impObj()->isConstraintDynamic();
}

void PyDbDimension::setConstraintDynamic(bool bDynamic)
{
    return PyThrowBadEs(impObj()->setConstraintDynamic(bDynamic));
}

bool PyDbDimension::shouldParticipateInOPM(void) const
{
    return impObj()->shouldParticipateInOPM();
}

void PyDbDimension::setShouldParticipateInOPM(bool bShouldParticipate)
{
    return impObj()->setShouldParticipateInOPM(bShouldParticipate);
}

double PyDbDimension::centerMarkSize() const
{
    return impObj()->centerMarkSize();
}

std::string PyDbDimension::prefix() const
{
    AcString sPrefix;
    PyThrowBadEs(impObj()->prefix(sPrefix));
    return wstr_to_utf8(sPrefix);
}

void PyDbDimension::setPrefix(const std::string& val)
{
    return PyThrowBadEs(impObj()->setPrefix(utf8_to_wstr(val).c_str()));
}

std::string PyDbDimension::suffix() const
{
    AcString _suffix;
    PyThrowBadEs(impObj()->suffix(_suffix));
    return wstr_to_utf8(_suffix);
}

void PyDbDimension::setSuffix(const std::string& val)
{
    return PyThrowBadEs(impObj()->setSuffix(utf8_to_wstr(val).c_str()));
}

std::string PyDbDimension::alternateSuffix() const
{
    AcString _sval;
    PyThrowBadEs(impObj()->alternateSuffix(_sval));
    return wstr_to_utf8(_sval);
}

void PyDbDimension::setAlternateSuffix(const std::string& val)
{
    return PyThrowBadEs(impObj()->setAlternateSuffix(utf8_to_wstr(val).c_str()));
}

std::string PyDbDimension::alternatePrefix() const
{
    AcString _sval;
    impObj()->alternatePrefix(_sval);
    return wstr_to_utf8(_sval);
}

void PyDbDimension::setAlternatePrefix(const std::string& val)
{
    return PyThrowBadEs(impObj()->setAlternatePrefix(utf8_to_wstr(val).c_str()));
}

bool PyDbDimension::suppressAngularLeadingZeros() const
{
    return impObj()->suppressAngularLeadingZeros();
}

void PyDbDimension::setSuppressAngularLeadingZeros(bool val)
{
    return PyThrowBadEs(impObj()->setSuppressAngularLeadingZeros(val));
}

bool PyDbDimension::suppressAngularTrailingZeros() const
{
    return impObj()->suppressAngularLeadingZeros();
}

void PyDbDimension::setSuppressAngularTrailingZeros(bool val)
{
    return PyThrowBadEs(impObj()->setSuppressAngularTrailingZeros(val));
}

bool PyDbDimension::altSuppressZeroInches() const
{
    return impObj()->altSuppressZeroInches();
}

void PyDbDimension::setAltSuppressZeroInches(bool val)
{
    return PyThrowBadEs(impObj()->setAltSuppressZeroInches(val));
}

bool PyDbDimension::altSuppressZeroFeet() const
{
    return impObj()->altSuppressZeroFeet();
}

void PyDbDimension::setAltSuppressZeroFeet(bool val)
{
    return PyThrowBadEs(impObj()->setAltSuppressZeroFeet(val));
}

bool PyDbDimension::altSuppressTrailingZeros() const
{
    return impObj()->altSuppressTrailingZeros();
}

void PyDbDimension::setAltSuppressTrailingZeros(bool val)
{
    return PyThrowBadEs(impObj()->setAltSuppressTrailingZeros(val));
}

bool PyDbDimension::altToleranceSuppressLeadingZeros() const
{
    return impObj()->altToleranceSuppressLeadingZeros();
}

void PyDbDimension::setAltToleranceSuppressLeadingZeros(bool val)
{
    return PyThrowBadEs(impObj()->setAltToleranceSuppressLeadingZeros(val));
}

bool PyDbDimension::altToleranceSuppressZeroInches() const
{
    return impObj()->altToleranceSuppressZeroInches();
}

void PyDbDimension::setAltToleranceSuppressZeroInches(bool val)
{
    return PyThrowBadEs(impObj()->setAltToleranceSuppressZeroInches(val));
}

bool PyDbDimension::altToleranceSuppressZeroFeet() const
{
    return impObj()->altToleranceSuppressZeroFeet();
}

void PyDbDimension::setAltToleranceSuppressZeroFeet(bool val)
{
    return PyThrowBadEs(impObj()->setAltToleranceSuppressZeroFeet(val));
}

bool PyDbDimension::altToleranceSuppressTrailingZeros() const
{
    return impObj()->altToleranceSuppressTrailingZeros();
}

void PyDbDimension::setAltToleranceSuppressTrailingZeros(bool val)
{
    return PyThrowBadEs(impObj()->setAltToleranceSuppressTrailingZeros(val));
}

bool PyDbDimension::suppressZeroFeet() const
{
    return impObj()->suppressZeroFeet();
}

void PyDbDimension::setSuppressZeroFeet(bool val)
{
    return PyThrowBadEs(impObj()->setSuppressZeroFeet(val));
}

bool PyDbDimension::suppressTrailingZeros() const
{
    return impObj()->suppressTrailingZeros();
}

void PyDbDimension::setSuppressTrailingZeros(bool val)
{
    return PyThrowBadEs(impObj()->setSuppressTrailingZeros(val));
}

bool PyDbDimension::suppressLeadingZeros() const
{
    return impObj()->suppressLeadingZeros();
}

void PyDbDimension::setSuppressLeadingZeros(bool val)
{
    return PyThrowBadEs(impObj()->setSuppressLeadingZeros(val));
}

bool PyDbDimension::suppressZeroInches() const
{
    return impObj()->suppressZeroInches();
}

void PyDbDimension::setSuppressZeroInches(bool val)
{
    return PyThrowBadEs(impObj()->setSuppressZeroInches(val));
}

bool PyDbDimension::altSuppressLeadingZeros() const
{
    return impObj()->altSuppressLeadingZeros();
}

void PyDbDimension::setAltSuppressLeadingZeros(bool val)
{
    return PyThrowBadEs(impObj()->setAltSuppressLeadingZeros(val));
}

bool PyDbDimension::toleranceSuppressZeroFeet() const
{
    return impObj()->toleranceSuppressZeroFeet();
}

void PyDbDimension::setToleranceSuppressZeroFeet(bool val)
{
    return PyThrowBadEs(impObj()->setToleranceSuppressZeroFeet(val));
}

bool PyDbDimension::toleranceSuppressTrailingZeros() const
{
    return impObj()->toleranceSuppressTrailingZeros();
}

void PyDbDimension::setToleranceSuppressTrailingZeros(bool val)
{
    return PyThrowBadEs(impObj()->setToleranceSuppressTrailingZeros(val));
}

bool PyDbDimension::toleranceSuppressLeadingZeros() const
{
    return impObj()->toleranceSuppressLeadingZeros();
}

void PyDbDimension::setToleranceSuppressLeadingZeros(bool val)
{
    return PyThrowBadEs(impObj()->setToleranceSuppressLeadingZeros(val));
}

bool PyDbDimension::toleranceSuppressZeroInches() const
{
    return impObj()->toleranceSuppressZeroInches();
}

void PyDbDimension::setToleranceSuppressZeroInches(bool val)
{
    return PyThrowBadEs(impObj()->setToleranceSuppressZeroInches(val));
}

AcDbDimension::CenterMarkType PyDbDimension::centerMarkType() const
{
    return impObj()->centerMarkType();
}

std::string PyDbDimension::className()
{
    return "AcDbRegion";
}

PyRxClass PyDbDimension::desc()
{
    return PyRxClass(AcDbDimension::desc(), false);
}

PyDbDimension PyDbDimension::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbDimension::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbDimension(static_cast<AcDbDimension*>(src.impObj()->clone()), true);
}

PyDbDimension PyDbDimension::cast(const PyRxObject& src)
{
    PyDbDimension dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbDimension* PyDbDimension::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbDimension*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyDb2LineAngularDimension
void makePyDb2LineAngularDimensionWrapper()
{
    class_<PyDb2LineAngularDimension, bases<PyDbDimension>>("LineAngularDimension2")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
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
        .def("desc", &PyDb2LineAngularDimension::desc).staticmethod("desc")
        .def("cloneFrom", &PyDb2LineAngularDimension::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDb2LineAngularDimension::cast).staticmethod("cast")
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

PyDb2LineAngularDimension::PyDb2LineAngularDimension(const PyDbObjectId& id)
    : PyDb2LineAngularDimension(id, AcDb::OpenMode::kForRead)
{
}

PyDb2LineAngularDimension::PyDb2LineAngularDimension(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbDimension(openAcDbObject<AcDb2LineAngularDimension>(id, mode), false)
{
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

void PyDb2LineAngularDimension::setArcPoint(const AcGePoint3d& val)
{
    return PyThrowBadEs(impObj()->setArcPoint(val));
}

AcGePoint3d PyDb2LineAngularDimension::xLine1Start() const
{
    return impObj()->xLine1Start();
}

void PyDb2LineAngularDimension::setXLine1Start(const AcGePoint3d& val)
{
    return PyThrowBadEs(impObj()->setXLine1Start(val));
}

AcGePoint3d PyDb2LineAngularDimension::xLine1End() const
{
    return impObj()->xLine1End();
}

void PyDb2LineAngularDimension::setXLine1End(const AcGePoint3d& val)
{
    return PyThrowBadEs(impObj()->setXLine1End(val));
}

AcGePoint3d PyDb2LineAngularDimension::xLine2Start() const
{
    return impObj()->xLine2Start();
}

void PyDb2LineAngularDimension::setXLine2Start(const AcGePoint3d& val)
{
    return PyThrowBadEs(impObj()->setXLine2Start(val));
}

AcGePoint3d PyDb2LineAngularDimension::xLine2End() const
{
    return impObj()->xLine2End();
}

void PyDb2LineAngularDimension::setXLine2End(const AcGePoint3d& val)
{
    return PyThrowBadEs(impObj()->setXLine2End(val));
}

bool PyDb2LineAngularDimension::extArcOn() const
{
    return impObj()->extArcOn();
}

void PyDb2LineAngularDimension::setExtArcOn(bool value)
{
    return PyThrowBadEs(impObj()->setExtArcOn(value));
}

std::string PyDb2LineAngularDimension::className()
{
    return "AcDb2LineAngularDimension";
}

PyRxClass PyDb2LineAngularDimension::desc()
{
    return PyRxClass(AcDb2LineAngularDimension::desc(), false);
}

PyDb2LineAngularDimension PyDb2LineAngularDimension::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDb2LineAngularDimension::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDb2LineAngularDimension(static_cast<AcDb2LineAngularDimension*>(src.impObj()->clone()), true);
}

PyDb2LineAngularDimension PyDb2LineAngularDimension::cast(const PyRxObject& src)
{
    PyDb2LineAngularDimension dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDb2LineAngularDimension* PyDb2LineAngularDimension::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDb2LineAngularDimension*>(m_pyImp.get());
}


//-----------------------------------------------------------------------------------
//AcDb3PointAngularDimension
void makePyDb3PointAngularDimensionWrapper()
{
    class_<PyDb3PointAngularDimension, bases<PyDbDimension>>("Point3AngularDimension")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
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
        .def("desc", &PyDb3PointAngularDimension::desc).staticmethod("desc")
        .def("cloneFrom", &PyDb3PointAngularDimension::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDb3PointAngularDimension::cast).staticmethod("cast")
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

PyDb3PointAngularDimension::PyDb3PointAngularDimension(const PyDbObjectId& id)
    : PyDb3PointAngularDimension(id, AcDb::OpenMode::kForRead)
{
}

PyDb3PointAngularDimension::PyDb3PointAngularDimension(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbDimension(openAcDbObject<AcDb3PointAngularDimension>(id, mode), false)
{
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

void PyDb3PointAngularDimension::setArcPoint(const AcGePoint3d& val)
{
    return PyThrowBadEs(impObj()->setArcPoint(val));
}

AcGePoint3d PyDb3PointAngularDimension::xLine1Point() const
{
    return impObj()->xLine1Point();
}

void PyDb3PointAngularDimension::setXLine1Point(const AcGePoint3d& val)
{
    return PyThrowBadEs(impObj()->setXLine1Point(val));
}

AcGePoint3d PyDb3PointAngularDimension::xLine2Point() const
{
    return impObj()->xLine1Point();
}

void PyDb3PointAngularDimension::setXLine2Point(const AcGePoint3d& val)
{
    return PyThrowBadEs(impObj()->setXLine2Point(val));
}

AcGePoint3d PyDb3PointAngularDimension::centerPoint() const
{
    return impObj()->centerPoint();
}

void PyDb3PointAngularDimension::setCenterPoint(const AcGePoint3d& val)
{
    return PyThrowBadEs(impObj()->setCenterPoint(val));
}

bool PyDb3PointAngularDimension::extArcOn() const
{
    return impObj()->extArcOn();
}

void PyDb3PointAngularDimension::setExtArcOn(bool value)
{
    return PyThrowBadEs(impObj()->setExtArcOn(value));
}

std::string PyDb3PointAngularDimension::className()
{
    return "AcDb3PointAngularDimension";
}

PyRxClass PyDb3PointAngularDimension::desc()
{
    return PyRxClass(AcDb3PointAngularDimension::desc(), false);
}

PyDb3PointAngularDimension PyDb3PointAngularDimension::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDb3PointAngularDimension::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDb3PointAngularDimension(static_cast<AcDb3PointAngularDimension*>(src.impObj()->clone()), true);
}

PyDb3PointAngularDimension PyDb3PointAngularDimension::cast(const PyRxObject& src)
{
    PyDb3PointAngularDimension dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDb3PointAngularDimension* PyDb3PointAngularDimension::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDb3PointAngularDimension*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//AcDbAlignedDimension
void makePyDbAlignedDimensionWrapper()
{
    class_<PyDbAlignedDimension, bases<PyDbDimension>>("AlignedDimension")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
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
        .def("desc", &PyDbAlignedDimension::desc).staticmethod("desc")
        .def("cloneFrom", &PyDbAlignedDimension::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbAlignedDimension::cast).staticmethod("cast")
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

PyDbAlignedDimension::PyDbAlignedDimension(const PyDbObjectId& id)
    : PyDbAlignedDimension(id, AcDb::OpenMode::kForRead)
{
}

PyDbAlignedDimension::PyDbAlignedDimension(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbDimension(openAcDbObject<AcDbAlignedDimension>(id, mode), false)
{
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

void PyDbAlignedDimension::setXLine1Point(const AcGePoint3d& val)
{
    return PyThrowBadEs(impObj()->setXLine1Point(val));
}

AcGePoint3d PyDbAlignedDimension::xLine2Point() const
{
    return impObj()->xLine2Point();
}

void PyDbAlignedDimension::setXLine2Point(const AcGePoint3d& val)
{
    return PyThrowBadEs(impObj()->setXLine2Point(val));
}

AcGePoint3d PyDbAlignedDimension::dimLinePoint() const
{
    return impObj()->dimLinePoint();
}

void PyDbAlignedDimension::setDimLinePoint(const AcGePoint3d& val)
{
    return PyThrowBadEs(impObj()->setDimLinePoint(val));
}

double PyDbAlignedDimension::oblique() const
{
    return impObj()->oblique();
}

void PyDbAlignedDimension::setOblique(double val)
{
    return PyThrowBadEs(impObj()->setOblique(val));
}

bool PyDbAlignedDimension::jogSymbolOn() const
{
    return impObj()->jogSymbolOn();
}

void PyDbAlignedDimension::setJogSymbolOn(bool value)
{
    return PyThrowBadEs(impObj()->setJogSymbolOn(value));
}

AcGePoint3d PyDbAlignedDimension::jogSymbolPosition() const
{
    return impObj()->jogSymbolPosition();
}

void PyDbAlignedDimension::setJogSymbolPosition(const AcGePoint3d& pt)
{
    return PyThrowBadEs(impObj()->setJogSymbolPosition(pt));
}

std::string PyDbAlignedDimension::className()
{
    return "AcDbAlignedDimension";
}

PyRxClass PyDbAlignedDimension::desc()
{
    return PyRxClass(AcDbAlignedDimension::desc(), false);
}

PyDbAlignedDimension PyDbAlignedDimension::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbAlignedDimension::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbAlignedDimension(static_cast<AcDbAlignedDimension*>(src.impObj()->clone()), true);

}

PyDbAlignedDimension PyDbAlignedDimension::cast(const PyRxObject& src)
{
    PyDbAlignedDimension dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbAlignedDimension* PyDbAlignedDimension::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbAlignedDimension*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//AcDbArcDimension
void makePyDbArcDimensionWrapper()
{
    class_<PyDbArcDimension, bases<PyDbDimension>>("ArcDimension")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
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
        .def("desc", &PyDbArcDimension::desc).staticmethod("desc")
        .def("cloneFrom", &PyDbArcDimension::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbArcDimension::cast).staticmethod("cast")
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

PyDbArcDimension::PyDbArcDimension(const PyDbObjectId& id)
    : PyDbArcDimension(id, AcDb::OpenMode::kForRead)
{
}

PyDbArcDimension::PyDbArcDimension(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbDimension(openAcDbObject<AcDbArcDimension>(id, mode), false)
{
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

void PyDbArcDimension::setArcPoint(const AcGePoint3d& arcPt)
{
    return PyThrowBadEs(impObj()->setArcPoint(arcPt));
}

AcGePoint3d PyDbArcDimension::xLine1Point() const
{
    return impObj()->xLine1Point();
}

void PyDbArcDimension::setXLine1Point(const AcGePoint3d& xLine1Pt)
{
    return PyThrowBadEs(impObj()->setXLine1Point(xLine1Pt));
}

AcGePoint3d PyDbArcDimension::xLine2Point() const
{
    return impObj()->xLine2Point();
}

void PyDbArcDimension::setXLine2Point(const AcGePoint3d& xLine2Pt)
{
    return PyThrowBadEs(impObj()->setXLine2Point(xLine2Pt));
}

AcGePoint3d PyDbArcDimension::centerPoint() const
{
    return impObj()->centerPoint();
}

void PyDbArcDimension::setCenterPoint(const AcGePoint3d& ctrPt)
{
    return PyThrowBadEs(impObj()->setCenterPoint(ctrPt));
}

bool PyDbArcDimension::isPartial() const
{
    return impObj()->isPartial();
}

void PyDbArcDimension::setIsPartial(bool partial)
{
    return PyThrowBadEs(impObj()->setIsPartial(partial));
}

double PyDbArcDimension::arcStartParam() const
{
    return impObj()->arcStartParam();
}

void PyDbArcDimension::setArcStartParam(double arcParam)
{
    return PyThrowBadEs(impObj()->setArcStartParam(arcParam));
}

double PyDbArcDimension::arcEndParam() const
{
    return impObj()->arcEndParam();
}

void PyDbArcDimension::setArcEndParam(double arcParam)
{
    return PyThrowBadEs(impObj()->setArcEndParam(arcParam));
}

bool PyDbArcDimension::hasLeader() const
{
    return impObj()->hasLeader();
}

void PyDbArcDimension::setHasLeader(bool leaderVal)
{
    return PyThrowBadEs(impObj()->setHasLeader(leaderVal));
}

AcGePoint3d PyDbArcDimension::leader1Point() const
{
    return impObj()->leader1Point();
}

void PyDbArcDimension::setLeader1Point(const AcGePoint3d& ldr1Pt)
{
    return PyThrowBadEs(impObj()->setLeader1Point(ldr1Pt));
}

AcGePoint3d PyDbArcDimension::leader2Point() const
{
    return impObj()->leader2Point();
}

void PyDbArcDimension::setLeader2Point(const AcGePoint3d& ldr2Pt)
{
    return PyThrowBadEs(impObj()->setLeader2Point(ldr2Pt));
}

int PyDbArcDimension::arcSymbolType() const
{
    return impObj()->arcSymbolType();
}

void PyDbArcDimension::setArcSymbolType(int symbol)
{
    return PyThrowBadEs(impObj()->setArcSymbolType(symbol));
}

std::string PyDbArcDimension::className()
{
    return "AcDbArcDimension";
}

PyRxClass PyDbArcDimension::desc()
{
    return PyRxClass(AcDbArcDimension::desc(), false);
}

PyDbArcDimension PyDbArcDimension::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbArcDimension::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbArcDimension(static_cast<AcDbArcDimension*>(src.impObj()->clone()), true);
}

PyDbArcDimension PyDbArcDimension::cast(const PyRxObject& src)
{
    PyDbArcDimension dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbArcDimension* PyDbArcDimension::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbArcDimension*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//AcDbDiametricDimension
void makePyDbDiametricDimensionWrapper()
{
    class_<PyDbDiametricDimension, bases<PyDbDimension>>("DiametricDimension")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
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
        .def("desc", &PyDbDiametricDimension::desc).staticmethod("desc")
        .def("cloneFrom", &PyDbDiametricDimension::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbDiametricDimension::cast).staticmethod("cast")
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

PyDbDiametricDimension::PyDbDiametricDimension(const PyDbObjectId& id)
    : PyDbDiametricDimension(id, AcDb::OpenMode::kForRead)
{
}

PyDbDiametricDimension::PyDbDiametricDimension(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbDimension(openAcDbObject<AcDbDiametricDimension>(id, mode), false)
{
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

void PyDbDiametricDimension::setLeaderLength(double val)
{
    return PyThrowBadEs(impObj()->setLeaderLength(val));
}

AcGePoint3d PyDbDiametricDimension::chordPoint() const
{
    return impObj()->chordPoint();
}

void PyDbDiametricDimension::setChordPoint(const AcGePoint3d& val)
{
    return PyThrowBadEs(impObj()->setChordPoint(val));
}

AcGePoint3d PyDbDiametricDimension::farChordPoint() const
{
    return impObj()->farChordPoint();
}

void PyDbDiametricDimension::setFarChordPoint(const AcGePoint3d& val)
{
    return PyThrowBadEs(impObj()->setFarChordPoint(val));
}

double PyDbDiametricDimension::extArcStartAngle() const
{
    return impObj()->extArcStartAngle();
}

void PyDbDiametricDimension::setExtArcStartAngle(double newAngle)
{
    return PyThrowBadEs(impObj()->setExtArcStartAngle(newAngle));
}

double PyDbDiametricDimension::extArcEndAngle() const
{
    return impObj()->extArcEndAngle();
}

void PyDbDiametricDimension::setExtArcEndAngle(double newAngle)
{
    return PyThrowBadEs(impObj()->setExtArcEndAngle(newAngle));
}

std::string PyDbDiametricDimension::className()
{
    return "AcDbDiametricDimension";
}

PyRxClass PyDbDiametricDimension::desc()
{
    return PyRxClass(AcDbDiametricDimension::desc(), false);
}

PyDbDiametricDimension PyDbDiametricDimension::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbDiametricDimension::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbDiametricDimension(static_cast<AcDbDiametricDimension*>(src.impObj()->clone()), true);
}

PyDbDiametricDimension PyDbDiametricDimension::cast(const PyRxObject& src)
{
    PyDbDiametricDimension dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbDiametricDimension* PyDbDiametricDimension::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbDiametricDimension*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//AcDbOrdinateDimension
void makePyDbOrdinateDimensionWrapper()
{
    class_<PyDbOrdinateDimension, bases<PyDbDimension>>("OrdinateDimension")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
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
        .def("desc", &PyDbOrdinateDimension::desc).staticmethod("desc")
        .def("cloneFrom", &PyDbOrdinateDimension::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbOrdinateDimension::cast).staticmethod("cast")
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

PyDbOrdinateDimension::PyDbOrdinateDimension(const PyDbObjectId& id)
    : PyDbOrdinateDimension(id, AcDb::OpenMode::kForRead)
{
}

PyDbOrdinateDimension::PyDbOrdinateDimension(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbDimension(openAcDbObject<AcDbOrdinateDimension>(id, mode), false)
{
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

void PyDbOrdinateDimension::useXAxis()
{
    return PyThrowBadEs(impObj()->useXAxis());
}

void PyDbOrdinateDimension::useYAxis()
{
    return PyThrowBadEs(impObj()->useYAxis());
}

void PyDbOrdinateDimension::setUsingXAxis(bool value)
{
    return PyThrowBadEs(impObj()->setUsingXAxis(value));
}

void PyDbOrdinateDimension::setUsingYAxis(bool value)
{
    return PyThrowBadEs(impObj()->setUsingYAxis(value));
}

AcGePoint3d PyDbOrdinateDimension::origin() const
{
    return impObj()->origin();
}

void PyDbOrdinateDimension::setOrigin(const AcGePoint3d& val)
{
    return PyThrowBadEs(impObj()->setOrigin(val));
}

AcGePoint3d PyDbOrdinateDimension::definingPoint() const
{
    return impObj()->definingPoint();
}

void PyDbOrdinateDimension::setDefiningPoint(const AcGePoint3d& val)
{
    return PyThrowBadEs(impObj()->setDefiningPoint(val));
}

AcGePoint3d PyDbOrdinateDimension::leaderEndPoint() const
{
    return impObj()->leaderEndPoint();
}

void PyDbOrdinateDimension::setLeaderEndPoint(const AcGePoint3d& val)
{
    return PyThrowBadEs(impObj()->setLeaderEndPoint(val));
}

std::string PyDbOrdinateDimension::className()
{
    return "AcDbOrdinateDimension";
}

PyRxClass PyDbOrdinateDimension::desc()
{
    return PyRxClass(AcDbOrdinateDimension::desc(), false);
}

PyDbOrdinateDimension PyDbOrdinateDimension::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbOrdinateDimension::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbOrdinateDimension(static_cast<AcDbOrdinateDimension*>(src.impObj()->clone()), true);
}

PyDbOrdinateDimension PyDbOrdinateDimension::cast(const PyRxObject& src)
{
    PyDbOrdinateDimension dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbOrdinateDimension* PyDbOrdinateDimension::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbOrdinateDimension*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//AcDbRadialDimension
void makePyDbRadialDimensionWrapper()
{
    class_<PyDbRadialDimension, bases<PyDbDimension>>("RadialDimension")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
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
        .def("desc", &PyDbRadialDimension::desc).staticmethod("desc")
        .def("cloneFrom", &PyDbRadialDimension::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbRadialDimension::cast).staticmethod("cast")
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

PyDbRadialDimension::PyDbRadialDimension(const PyDbObjectId& id)
    : PyDbRadialDimension(id, AcDb::OpenMode::kForRead)
{
}

PyDbRadialDimension::PyDbRadialDimension(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbDimension(openAcDbObject<AcDbRadialDimension>(id, mode), false)
{
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

void PyDbRadialDimension::setLeaderLength(double val)
{
    return PyThrowBadEs(impObj()->setLeaderLength(val));
}

AcGePoint3d PyDbRadialDimension::center() const
{
    return impObj()->center();
}

void PyDbRadialDimension::setCenter(const AcGePoint3d& val)
{
    return PyThrowBadEs(impObj()->setCenter(val));
}

AcGePoint3d PyDbRadialDimension::chordPoint() const
{
    return impObj()->chordPoint();
}

void PyDbRadialDimension::setChordPoint(const AcGePoint3d& val)
{
    return PyThrowBadEs(impObj()->setChordPoint(val));
}

double PyDbRadialDimension::extArcStartAngle() const
{
    return impObj()->extArcStartAngle();
}

void PyDbRadialDimension::setExtArcStartAngle(double newAngle)
{
    return PyThrowBadEs(impObj()->setExtArcStartAngle(newAngle));
}

double PyDbRadialDimension::extArcEndAngle() const
{
    return impObj()->extArcEndAngle();
}

void PyDbRadialDimension::setExtArcEndAngle(double newAngle)
{
    return PyThrowBadEs(impObj()->setExtArcEndAngle(newAngle));
}

std::string PyDbRadialDimension::className()
{
    return "AcDbRadialDimension";
}

PyRxClass PyDbRadialDimension::desc()
{
    return PyRxClass(AcDbRadialDimension::desc(), false);
}

PyDbRadialDimension PyDbRadialDimension::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbRadialDimension::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbRadialDimension(static_cast<AcDbRadialDimension*>(src.impObj()->clone()), true);
}

PyDbRadialDimension PyDbRadialDimension::cast(const PyRxObject& src)
{
    PyDbRadialDimension dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbRadialDimension* PyDbRadialDimension::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbRadialDimension*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//AcDbRadialDimensionLarge
void makePyDbRadialDimensionLargeWrapper()
{
    class_<PyDbRadialDimensionLarge, bases<PyDbDimension>>("RadialDimensionLarge")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
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
        .def("desc", &PyDbRadialDimensionLarge::desc).staticmethod("desc")
        .def("cloneFrom", &PyDbRadialDimensionLarge::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbRadialDimensionLarge::cast).staticmethod("cast")
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

PyDbRadialDimensionLarge::PyDbRadialDimensionLarge(const PyDbObjectId& id)
    : PyDbRadialDimensionLarge(id, AcDb::OpenMode::kForRead)
{
}

PyDbRadialDimensionLarge::PyDbRadialDimensionLarge(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbDimension(openAcDbObject<AcDbRadialDimensionLarge>(id, mode), false)
{
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

void PyDbRadialDimensionLarge::setCenter(const AcGePoint3d& centerPoint)
{
    return PyThrowBadEs(impObj()->setCenter(centerPoint));
}

AcGePoint3d PyDbRadialDimensionLarge::chordPoint() const
{
    return impObj()->chordPoint();
}

void PyDbRadialDimensionLarge::setChordPoint(const AcGePoint3d& chordPoint)
{
    return PyThrowBadEs(impObj()->setChordPoint(chordPoint));
}

AcGePoint3d PyDbRadialDimensionLarge::overrideCenter() const
{
    return impObj()->overrideCenter();
}

void PyDbRadialDimensionLarge::setOverrideCenter(const AcGePoint3d& overrideCenterPoint)
{
    return PyThrowBadEs(impObj()->setOverrideCenter(overrideCenterPoint));
}

AcGePoint3d PyDbRadialDimensionLarge::jogPoint() const
{
    return impObj()->jogPoint();
}

void PyDbRadialDimensionLarge::setJogPoint(const AcGePoint3d& jogPoint)
{
    return PyThrowBadEs(impObj()->setJogPoint(jogPoint));
}

double PyDbRadialDimensionLarge::jogAngle() const
{
    return impObj()->jogAngle();
}

void PyDbRadialDimensionLarge::setJogAngle(double jogAngle)
{
    return PyThrowBadEs(impObj()->setJogAngle(jogAngle));
}

void PyDbRadialDimensionLarge::setOverrideCenterPP(const AcGePoint3d& overrideCenterPointPP)
{
    return PyThrowBadEs(impObj()->setOverrideCenterPP(overrideCenterPointPP));
}

void PyDbRadialDimensionLarge::setJogPointPP(const AcGePoint3d& jogPointPP)
{
    return PyThrowBadEs(impObj()->setJogPointPP(jogPointPP));
}

void PyDbRadialDimensionLarge::setTextPositionPP(const AcGePoint3d& textPointPP)
{
    return PyThrowBadEs(impObj()->setTextPositionPP(textPointPP));
}

double PyDbRadialDimensionLarge::extArcStartAngle() const
{
    return impObj()->extArcStartAngle();
}

void PyDbRadialDimensionLarge::setExtArcStartAngle(double newAngle)
{
    return PyThrowBadEs(impObj()->setExtArcStartAngle(newAngle));
}

double PyDbRadialDimensionLarge::extArcEndAngle() const
{
    return impObj()->extArcEndAngle();
}

void PyDbRadialDimensionLarge::setExtArcEndAngle(double newAngle)
{
    return PyThrowBadEs(impObj()->setExtArcEndAngle(newAngle));
}

std::string PyDbRadialDimensionLarge::className()
{
    return "AcDbRadialDimension";
}

PyRxClass PyDbRadialDimensionLarge::desc()
{
    return PyRxClass(AcDbRadialDimensionLarge::desc(), false);
}

PyDbRadialDimensionLarge PyDbRadialDimensionLarge::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbRadialDimensionLarge::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbRadialDimensionLarge(static_cast<AcDbRadialDimensionLarge*>(src.impObj()->clone()), true);
}

PyDbRadialDimensionLarge PyDbRadialDimensionLarge::cast(const PyRxObject& src)
{
    PyDbRadialDimensionLarge dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbRadialDimensionLarge* PyDbRadialDimensionLarge::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbRadialDimensionLarge*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//AcDbRotatedDimension
void makePyDbRotatedDimensionWrapper()
{
    class_<PyDbRotatedDimension, bases<PyDbDimension>>("RotatedDimension")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
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
        .def("desc", &PyDbRotatedDimension::desc).staticmethod("desc")
        .def("cloneFrom", &PyDbRotatedDimension::cloneFrom).staticmethod("cloneFrom")
        .def("cast", &PyDbRotatedDimension::cast).staticmethod("cast")
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

PyDbRotatedDimension::PyDbRotatedDimension(const PyDbObjectId& id)
    : PyDbRotatedDimension(id, AcDb::OpenMode::kForRead)
{
}

PyDbRotatedDimension::PyDbRotatedDimension(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbDimension(openAcDbObject<AcDbRotatedDimension>(id, mode), false)
{
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

void PyDbRotatedDimension::setXLine1Point(const AcGePoint3d& val)
{
    return PyThrowBadEs(impObj()->setXLine1Point(val));
}

AcGePoint3d PyDbRotatedDimension::xLine2Point() const
{
    return impObj()->xLine2Point();
}

void PyDbRotatedDimension::setXLine2Point(const AcGePoint3d& val)
{
    return PyThrowBadEs(impObj()->setXLine2Point(val));
}

AcGePoint3d PyDbRotatedDimension::dimLinePoint() const
{
    return impObj()->dimLinePoint();
}

void PyDbRotatedDimension::setDimLinePoint(const AcGePoint3d& val)
{
    return PyThrowBadEs(impObj()->setDimLinePoint(val));
}

double PyDbRotatedDimension::oblique() const
{
    return impObj()->oblique();
}

void PyDbRotatedDimension::setOblique(double val)
{
    return PyThrowBadEs(impObj()->setOblique(val));
}

double PyDbRotatedDimension::rotation() const
{
    return impObj()->rotation();
}

void PyDbRotatedDimension::setRotation(double val)
{
    return PyThrowBadEs(impObj()->setRotation(val));
}

bool PyDbRotatedDimension::jogSymbolOn() const
{
    return impObj()->jogSymbolOn();
}

void PyDbRotatedDimension::setJogSymbolOn(bool val)
{
    return PyThrowBadEs(impObj()->setJogSymbolOn(val));
}

AcGePoint3d PyDbRotatedDimension::jogSymbolPosition() const
{
    return impObj()->jogSymbolPosition();
}

void PyDbRotatedDimension::setJogSymbolPosition(const AcGePoint3d& val)
{
    return PyThrowBadEs(impObj()->setJogSymbolPosition(val));
}

std::string PyDbRotatedDimension::className()
{
    return "AcDbRotatedDimension";
}

PyRxClass PyDbRotatedDimension::desc()
{
    return PyRxClass(AcDbRotatedDimension::desc(), false);
}

PyDbRotatedDimension PyDbRotatedDimension::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbRotatedDimension::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbRotatedDimension(static_cast<AcDbRotatedDimension*>(src.impObj()->clone()), true);
}

PyDbRotatedDimension PyDbRotatedDimension::cast(const PyRxObject& src)
{
    PyDbRotatedDimension dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbRotatedDimension* PyDbRotatedDimension::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbRotatedDimension*>(m_pyImp.get());
}
