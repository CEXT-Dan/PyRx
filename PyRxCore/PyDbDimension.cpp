#include "stdafx.h"
#include "PyDbDimension.h"
#include "PyDbObjectId.h"
#include "PyDbMtext.h"



using namespace boost::python;

//-----------------------------------------------------------------------------------
//PyDbDimension
void makePyDbDimensionWrapper()
{
    constexpr const std::string_view setDimstyleDataOverloads = "Overloads:\n"
        "- id: PyDb.ObjectId\n"
        "- rec: PyDb.DimStyleTableRecord\n";

    constexpr const std::string_view formatMeasurementOverloads = "Overloads:\n"
        "- measurement: float\n"
        "- measurement: float, dimensionText: str\n";

    PyDocString DS("PyDb.Dimension");
    class_<PyDbDimension, bases<PyDbEntity>>("Dimension", no_init)
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>(DS.ARGS({ "id: PyDb.ObjectId", "mode: PyDb.OpenMode=PyDb.OpenMode.kForRead", "erased: bool=False" })))
        .def("textDefinedSize", &PyDbDimension::textDefinedSize, DS.ARGS())
        .def("setTextDefinedSize", &PyDbDimension::setTextDefinedSize, DS.ARGS({ "width : float", "height : float" }))
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
        .def("setElevation", &PyDbDimension::setElevation, DS.ARGS({ "val : float" }))
        .def("dimensionText", &PyDbDimension::dimensionText, DS.ARGS())
        .def("setDimensionText", &PyDbDimension::setDimensionText, DS.ARGS({ "val : str" }))
        .def("textRotation", &PyDbDimension::textRotation, DS.ARGS())
        .def("setTextRotation", &PyDbDimension::setTextRotation, DS.ARGS({ "val : float" }))
        .def("dimensionStyle", &PyDbDimension::dimensionStyle, DS.ARGS())
        .def("setDimensionStyle", &PyDbDimension::setDimensionStyle, DS.ARGS({ "val : PyDb.ObjectId" }))
        .def("textAttachment", &PyDbDimension::textAttachment, DS.ARGS())
        .def("setTextAttachment", &PyDbDimension::setTextAttachment, DS.ARGS({ "val : PyDb.MTextAttachmentPoint" }))
        .def("textLineSpacingStyle", &PyDbDimension::textLineSpacingStyle, DS.ARGS())
        .def("setTextLineSpacingStyle", &PyDbDimension::setTextLineSpacingStyle, DS.ARGS({ "val : PyDb.LineSpacingStyle" }))
        .def("textLineSpacingFactor", &PyDbDimension::textLineSpacingFactor, DS.ARGS())
        .def("setTextLineSpacingFactor", &PyDbDimension::setTextLineSpacingFactor, DS.ARGS({ "val : float" }))
        .def("getDimstyleData", &PyDbDimension::getDimstyleData, DS.ARGS())
        .def("setDimstyleData", &PyDbDimension::setDimstyleData1)
        .def("setDimstyleData", &PyDbDimension::setDimstyleData2, DS.OVRL(setDimstyleDataOverloads))
        .def("horizontalRotation", &PyDbDimension::horizontalRotation, DS.ARGS())
        .def("setHorizontalRotation", &PyDbDimension::setHorizontalRotation, DS.ARGS({ "val : float" }))
        .def("dimBlockId", &PyDbDimension::dimBlockId, DS.ARGS())
        .def("setDimBlockId", &PyDbDimension::setDimBlockId, DS.ARGS({ "val : PyDb.ObjectId" }))
        .def("dimBlockPosition", &PyDbDimension::dimBlockPosition, DS.ARGS())
        .def("setDimBlockPosition", &PyDbDimension::setDimBlockPosition, DS.ARGS({ "val : PyGe.Point3d" }))
        .def("recomputeDimBlock", &PyDbDimension::recomputeDimBlock1)
        .def("recomputeDimBlock", &PyDbDimension::recomputeDimBlock2, DS.ARGS({ "force : bool=False" }))
        .def("generateLayout", &PyDbDimension::generateLayout, DS.ARGS())
        .def("measurement", &PyDbDimension::measurement, DS.ARGS())
        .def("formatMeasurement", &PyDbDimension::formatMeasurement1)
        .def("formatMeasurement", &PyDbDimension::formatMeasurement2, DS.OVRL(formatMeasurementOverloads))
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
        .def("desc", &PyDbDimension::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbDimension::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbDimension::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
        ;

#if !defined (_BRXTARGET240)
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

#if !defined (_BRXTARGET240)
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
    : PyDbEntity(openAcDbObject<AcDbDimension>(id, mode), false)
{
}

PyDbDimension::PyDbDimension(const PyDbObjectId& id)
    : PyDbDimension(id, AcDb::OpenMode::kForRead)
{
}

PyDbDimension::PyDbDimension(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbEntity(openAcDbObject<AcDbDimension>(id, mode, erased), false)
{
}

boost::python::tuple PyDbDimension::textDefinedSize() const
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
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
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    impObj()->setTextDefinedSize(width, height);
#endif
}

void PyDbDimension::resetTextDefinedSize()
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    impObj()->resetTextDefinedSize();
#endif
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
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setUsingDefaultTextPosition(val));
#endif
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
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    AcString str;
    PyThrowBadEs(impObj()->formatMeasurement(str, measurement));
    return wstr_to_utf8(str);
#endif
}

std::string PyDbDimension::formatMeasurement2(double measurement, const std::string& dimensionText)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    AcString str;
    PyThrowBadEs(impObj()->formatMeasurement(str, measurement, utf8_to_wstr(dimensionText).c_str()));
    return wstr_to_utf8(str);
#endif
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
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->removeTextField());
#endif
}

void PyDbDimension::fieldToMText(PyDbMText& pDimMText)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->fieldToMText(pDimMText.impObj()));
#endif
}

void PyDbDimension::fieldFromMText(PyDbMText& pDimMText)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->fieldFromMText(pDimMText.impObj()));
#endif
}

bool PyDbDimension::isHorizontalRefTextRotation() const
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return impObj()->isHorizontalRefTextRotation();
#endif
}

void PyDbDimension::setHorizontalRefTextRotation(bool newVal)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setHorizontalRefTextRotation(newVal));
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
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return impObj()->inspection();
#endif
}

void PyDbDimension::setInspection(bool val)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setInspection(val));
#endif
}

int PyDbDimension::inspectionFrame() const
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return impObj()->inspectionFrame();
#endif
}

void PyDbDimension::setInspectionFrame(int frame)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setInspectionFrame(frame));
#endif
}

const std::string PyDbDimension::inspectionLabel() const
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return wstr_to_utf8(impObj()->inspectionLabel());
#endif
}

void PyDbDimension::setInspectionLabel(const std::string& label)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setInspectionLabel(utf8_to_wstr(label).c_str()));
#endif
}

boost::python::tuple PyDbDimension::isConstraintObject() const
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
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
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return impObj()->isConstraintDynamic();
#endif
}

void PyDbDimension::setConstraintDynamic(bool bDynamic)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setConstraintDynamic(bDynamic));
#endif
}

bool PyDbDimension::shouldParticipateInOPM(void) const
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return impObj()->shouldParticipateInOPM();
#endif
}

void PyDbDimension::setShouldParticipateInOPM(bool bShouldParticipate)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return impObj()->setShouldParticipateInOPM(bShouldParticipate);
#endif
}

double PyDbDimension::centerMarkSize() const
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return impObj()->centerMarkSize();
#endif
}

std::string PyDbDimension::prefix() const
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    AcString sPrefix;
    PyThrowBadEs(impObj()->prefix(sPrefix));
    return wstr_to_utf8(sPrefix);
#endif
}

void PyDbDimension::setPrefix(const std::string& val)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setPrefix(utf8_to_wstr(val).c_str()));
#endif
}

std::string PyDbDimension::suffix() const
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    AcString _suffix;
    PyThrowBadEs(impObj()->suffix(_suffix));
    return wstr_to_utf8(_suffix);
#endif
}

void PyDbDimension::setSuffix(const std::string& val)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setSuffix(utf8_to_wstr(val).c_str()));
#endif
}

std::string PyDbDimension::alternateSuffix() const
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    AcString _sval;
    PyThrowBadEs(impObj()->alternateSuffix(_sval));
    return wstr_to_utf8(_sval);
#endif
}

void PyDbDimension::setAlternateSuffix(const std::string& val)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setAlternateSuffix(utf8_to_wstr(val).c_str()));
#endif
}

std::string PyDbDimension::alternatePrefix() const
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    AcString _sval;
    impObj()->alternatePrefix(_sval);
    return wstr_to_utf8(_sval);
#endif
}

void PyDbDimension::setAlternatePrefix(const std::string& val)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setAlternatePrefix(utf8_to_wstr(val).c_str()));
#endif
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
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return impObj()->altSuppressZeroInches();
#endif
}

void PyDbDimension::setAltSuppressZeroInches(bool val)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setAltSuppressZeroInches(val));
#endif
}

bool PyDbDimension::altSuppressZeroFeet() const
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return impObj()->altSuppressZeroFeet();
#endif
}

void PyDbDimension::setAltSuppressZeroFeet(bool val)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setAltSuppressZeroFeet(val));
#endif
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
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return impObj()->altToleranceSuppressZeroInches();
#endif
}

void PyDbDimension::setAltToleranceSuppressZeroInches(bool val)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setAltToleranceSuppressZeroInches(val));
#endif
}

bool PyDbDimension::altToleranceSuppressZeroFeet() const
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return impObj()->altToleranceSuppressZeroFeet();
#endif
}

void PyDbDimension::setAltToleranceSuppressZeroFeet(bool val)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setAltToleranceSuppressZeroFeet(val));
#endif
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
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return impObj()->suppressZeroFeet();
#endif
}

void PyDbDimension::setSuppressZeroFeet(bool val)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setSuppressZeroFeet(val));
#endif
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
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return impObj()->suppressZeroInches();
#endif
}

void PyDbDimension::setSuppressZeroInches(bool val)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setSuppressZeroInches(val));
#endif
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
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return impObj()->toleranceSuppressZeroFeet();
#endif
}

void PyDbDimension::setToleranceSuppressZeroFeet(bool val)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setToleranceSuppressZeroFeet(val));
#endif
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
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return impObj()->toleranceSuppressZeroInches();
#endif
}

void PyDbDimension::setToleranceSuppressZeroInches(bool val)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setToleranceSuppressZeroInches(val));
#endif
}

#if !defined(_BRXTARGET240)
AcDbDimension::CenterMarkType PyDbDimension::centerMarkType() const
{
    return impObj()->centerMarkType();
}
#endif

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
    return PyDbObjectCloneFrom<PyDbDimension, AcDbDimension>(src);
}

PyDbDimension PyDbDimension::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbDimension>(src);
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
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- xL1Start: PyGe.Point3d, xL1End: PyGe.Point3d, xL2Start: PyGe.Point3d, xL2End: PyGe.Point3d, arcPnt: PyGe.Point3d\n"
        "- xL1Start: PyGe.Point3d, xL1End: PyGe.Point3d, xL2Start: PyGe.Point3d, xL2End: PyGe.Point3d, arcPnt: PyGe.Point3d, dimText: str\n"
        "- xL1Start: PyGe.Point3d, xL1End: PyGe.Point3d, xL2Start: PyGe.Point3d, xL2End: PyGe.Point3d, arcPnt: PyGe.Point3d, dimText: str, id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    PyDocString DS("PyDb.LineAngularDimension2");
    class_<PyDb2LineAngularDimension, bases<PyDbDimension>>("LineAngularDimension2")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>())
        .def(init<const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&>())
        .def(init<const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&, const std::string&>())
        .def(init<const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&, const std::string&, const PyDbObjectId&>(DS.CTOR(ctords)))
        .def("arcPoint", &PyDb2LineAngularDimension::arcPoint, DS.ARGS())
        .def("setArcPoint", &PyDb2LineAngularDimension::setArcPoint, DS.ARGS({ "pt : PyGe.Point3d" }))
        .def("xLine1Start", &PyDb2LineAngularDimension::xLine1Start, DS.ARGS())
        .def("setXLine1Start", &PyDb2LineAngularDimension::setXLine1Start, DS.ARGS({ "pt : PyGe.Point3d" }))
        .def("xLine1End", &PyDb2LineAngularDimension::xLine1End, DS.ARGS())
        .def("setXLine1End", &PyDb2LineAngularDimension::setXLine1End, DS.ARGS({ "pt : PyGe.Point3d" }))
        .def("xLine2Start", &PyDb2LineAngularDimension::xLine2Start, DS.ARGS())
        .def("setXLine2Start", &PyDb2LineAngularDimension::setXLine2Start, DS.ARGS({ "pt : PyGe.Point3d" }))
        .def("xLine2End", &PyDb2LineAngularDimension::xLine2End, DS.ARGS())
        .def("setXLine2End", &PyDb2LineAngularDimension::setXLine2End, DS.ARGS({ "pt : PyGe.Point3d" }))
        .def("extArcOn", &PyDb2LineAngularDimension::extArcOn, DS.ARGS())
        .def("setExtArcOn", &PyDb2LineAngularDimension::setExtArcOn, DS.ARGS({ "val : bool" }))
        .def("className", &PyDb2LineAngularDimension::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDb2LineAngularDimension::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDb2LineAngularDimension::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDb2LineAngularDimension::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
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

PyDb2LineAngularDimension::PyDb2LineAngularDimension(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbDimension(openAcDbObject<AcDb2LineAngularDimension>(id, mode, erased), false)
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
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return impObj()->extArcOn();
#endif
}

void PyDb2LineAngularDimension::setExtArcOn(bool value)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setExtArcOn(value));
#endif
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
    return PyDbObjectCloneFrom<PyDb2LineAngularDimension, AcDb2LineAngularDimension>(src);
}

PyDb2LineAngularDimension PyDb2LineAngularDimension::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDb2LineAngularDimension>(src);
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
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- centerPoint: PyGe.point3d, xL1Start: PyGe.Point3d, xL1End: PyGe.Point3d, arcPnt: PyGe.Point3d\n"
        "- centerPoint: PyGe.point3d, xL1Start: PyGe.Point3d, xL1End: PyGe.Point3d, arcPnt: PyGe.Point3d, dimText: str\n"
        "- centerPoint: PyGe.point3d, xL1Start: PyGe.Point3d, xL1End: PyGe.Point3d, arcPnt: PyGe.Point3d, dimText: str, id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    PyDocString DS("PyDb.Point3AngularDimension");
    class_<PyDb3PointAngularDimension, bases<PyDbDimension>>("Point3AngularDimension")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>())
        .def(init<const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&>())
        .def(init<const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&, const std::string&>())
        .def(init<const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&, const std::string&, const PyDbObjectId&>(DS.CTOR(ctords)))
        .def("arcPoint", &PyDb3PointAngularDimension::arcPoint, DS.ARGS())
        .def("setArcPoint", &PyDb3PointAngularDimension::setArcPoint, DS.ARGS({ "pt : PyGe.Point3d" }))
        .def("xLine1Point", &PyDb3PointAngularDimension::xLine1Point, DS.ARGS())
        .def("setXLine1Point", &PyDb3PointAngularDimension::setXLine1Point, DS.ARGS({ "pt : PyGe.Point3d" }))
        .def("xLine2Point", &PyDb3PointAngularDimension::xLine2Point, DS.ARGS())
        .def("setXLine2Point", &PyDb3PointAngularDimension::setXLine2Point, DS.ARGS({ "pt : PyGe.Point3d" }))
        .def("centerPoint", &PyDb3PointAngularDimension::centerPoint, DS.ARGS())
        .def("setCenterPoint", &PyDb3PointAngularDimension::setCenterPoint, DS.ARGS({ "pt : PyGe.Point3d" }))
        .def("extArcOn", &PyDb3PointAngularDimension::extArcOn, DS.ARGS())
        .def("setExtArcOn", &PyDb3PointAngularDimension::setExtArcOn, DS.ARGS({ "val : bool" }))
        .def("className", &PyDb3PointAngularDimension::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDb3PointAngularDimension::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDb3PointAngularDimension::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDb3PointAngularDimension::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
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

PyDb3PointAngularDimension::PyDb3PointAngularDimension(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbDimension(openAcDbObject<AcDb3PointAngularDimension>(id, mode, erased), false)
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
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return impObj()->extArcOn();
#endif
}

void PyDb3PointAngularDimension::setExtArcOn(bool value)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setExtArcOn(value));
#endif
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
    return PyDbObjectCloneFrom<PyDb3PointAngularDimension, AcDb3PointAngularDimension>(src);
}

PyDb3PointAngularDimension PyDb3PointAngularDimension::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDb3PointAngularDimension>(src);
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
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- xLine1Point: PyGe.Point3d, xLine2Point: PyGe.Point3d, dimLinePoint: PyGe.Point3d\n"
        "- xLine1Point: PyGe.Point3d, xLine2Point: PyGe.Point3d, dimLinePoint: PyGe.Point3d, dimText: str\n"
        "- xLine1Point: PyGe.Point3d, xLine2Point: PyGe.Point3d, dimLinePoint: PyGe.Point3d, dimText: str, id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    PyDocString DS("PyDb.AlignedDimension");
    class_<PyDbAlignedDimension, bases<PyDbDimension>>("AlignedDimension")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>())
        .def(init<const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&>())
        .def(init<const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&, const std::string&>())
        .def(init<const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&, const std::string&, const PyDbObjectId& >(DS.CTOR(ctords)))
        .def("xLine1Point", &PyDbAlignedDimension::xLine1Point, DS.ARGS())
        .def("setXLine1Point", &PyDbAlignedDimension::setXLine1Point, DS.ARGS({ "pt : PyGe.Point3d" }))
        .def("xLine2Point", &PyDbAlignedDimension::xLine2Point, DS.ARGS())
        .def("setXLine2Point", &PyDbAlignedDimension::setXLine2Point, DS.ARGS({ "pt : PyGe.Point3d" }))
        .def("dimLinePoint", &PyDbAlignedDimension::dimLinePoint, DS.ARGS())
        .def("setDimLinePoint", &PyDbAlignedDimension::setDimLinePoint, DS.ARGS({ "pt : PyGe.Point3d" }))
        .def("oblique", &PyDbAlignedDimension::oblique, DS.ARGS())
        .def("setOblique", &PyDbAlignedDimension::setOblique, DS.ARGS({ "val : float" }))
        .def("jogSymbolOn", &PyDbAlignedDimension::jogSymbolOn, DS.ARGS())
        .def("setJogSymbolOn", &PyDbAlignedDimension::setJogSymbolOn, DS.ARGS({ "val : bool" }))
        .def("jogSymbolPosition", &PyDbAlignedDimension::jogSymbolPosition, DS.ARGS())
        .def("setJogSymbolPosition", &PyDbAlignedDimension::setJogSymbolPosition, DS.ARGS({ "pt : PyGe.Point3d" }))
        .def("className", &PyDbAlignedDimension::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbAlignedDimension::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbAlignedDimension::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbAlignedDimension::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
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

PyDbAlignedDimension::PyDbAlignedDimension(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbDimension(openAcDbObject<AcDbAlignedDimension>(id, mode, erased), false)
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
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return impObj()->jogSymbolOn();
#endif
}

void PyDbAlignedDimension::setJogSymbolOn(bool value)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setJogSymbolOn(value));
#endif
}

AcGePoint3d PyDbAlignedDimension::jogSymbolPosition() const
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return impObj()->jogSymbolPosition();
#endif
}

void PyDbAlignedDimension::setJogSymbolPosition(const AcGePoint3d& pt)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setJogSymbolPosition(pt));
#endif
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
    return PyDbObjectCloneFrom<PyDbAlignedDimension, AcDbAlignedDimension>(src);
}

PyDbAlignedDimension PyDbAlignedDimension::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbAlignedDimension>(src);
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
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- centerPoint: PyGe.point3d, xLine1Point: PyGe.Point3d, xLine2Point: PyGe.Point3d, arcPnt: PyGe.Point3d\n"
        "- centerPoint: PyGe.point3d, xLine1Point: PyGe.Point3d, xLine2Point: PyGe.Point3d, arcPnt: PyGe.Point3d, dimText: str\n"
        "- centerPoint: PyGe.point3d, xLine1Point: PyGe.Point3d, xLine2Point: PyGe.Point3d, arcPnt: PyGe.Point3d, dimText: str, id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    PyDocString DS("PyDb.ArcDimension");
    class_<PyDbArcDimension, bases<PyDbDimension>>("ArcDimension")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>())
        .def(init <const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&>())
        .def(init <const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&, const std::string&>())
        .def(init <const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&, const std::string&, const PyDbObjectId&>(DS.CTOR(ctords)))
        .def("arcPoint", &PyDbArcDimension::arcPoint, DS.ARGS())
        .def("setArcPoint", &PyDbArcDimension::setArcPoint, DS.ARGS({ "pt : PyGe.Point3d" }))
        .def("xLine1Point", &PyDbArcDimension::xLine1Point, DS.ARGS())
        .def("setXLine1Point", &PyDbArcDimension::setXLine1Point, DS.ARGS({ "pt : PyGe.Point3d" }))
        .def("xLine2Point", &PyDbArcDimension::xLine2Point, DS.ARGS())
        .def("setXLine2Point", &PyDbArcDimension::setXLine2Point, DS.ARGS({ "pt : PyGe.Point3d" }))
        .def("centerPoint", &PyDbArcDimension::centerPoint, DS.ARGS())
        .def("setCenterPoint", &PyDbArcDimension::setCenterPoint, DS.ARGS({ "pt : PyGe.Point3d" }))
        .def("isPartial", &PyDbArcDimension::isPartial, DS.ARGS())
        .def("setIsPartial", &PyDbArcDimension::setIsPartial, DS.ARGS({ "val : bool" }))
        .def("arcStartParam", &PyDbArcDimension::arcStartParam, DS.ARGS())
        .def("setArcStartParam", &PyDbArcDimension::setArcStartParam, DS.ARGS({ "val : float" }))
        .def("arcEndParam", &PyDbArcDimension::arcEndParam, DS.ARGS())
        .def("setArcEndParam", &PyDbArcDimension::setArcEndParam, DS.ARGS({ "val : float" }))
        .def("hasLeader", &PyDbArcDimension::hasLeader, DS.ARGS())
        .def("setHasLeader", &PyDbArcDimension::setHasLeader, DS.ARGS({ "val : bool" }))
        .def("leader1Point", &PyDbArcDimension::leader1Point, DS.ARGS())
        .def("setLeader1Point", &PyDbArcDimension::setLeader1Point, DS.ARGS({ "pt : PyGe.Point3d" }))
        .def("leader2Point", &PyDbArcDimension::leader2Point, DS.ARGS())
        .def("setLeader2Point", &PyDbArcDimension::setLeader2Point, DS.ARGS({ "pt : PyGe.Point3d" }))
        .def("arcSymbolType", &PyDbArcDimension::arcSymbolType, DS.ARGS())
        .def("setArcSymbolType", &PyDbArcDimension::setArcSymbolType, DS.ARGS({ "val : int" }))
        .def("className", &PyDbArcDimension::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbArcDimension::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbArcDimension::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbArcDimension::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
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

PyDbArcDimension::PyDbArcDimension(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbDimension(openAcDbObject<AcDbArcDimension>(id, mode, erased), false)
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
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return impObj()->isPartial();
#endif
}

void PyDbArcDimension::setIsPartial(bool partial)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setIsPartial(partial));
#endif
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
    return PyDbObjectCloneFrom<PyDbArcDimension, AcDbArcDimension>(src);
}

PyDbArcDimension PyDbArcDimension::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbArcDimension>(src);
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
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- chordPoint: PyGe.point3d, farChordPoint: PyGe.Point3d, leaderLength: float\n"
        "- chordPoint: PyGe.point3d, farChordPoint: PyGe.Point3d, leaderLength: float, dimText: str\n"
        "- chordPoint: PyGe.point3d, farChordPoint: PyGe.Point3d, leaderLength: float, dimText: str, id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    PyDocString DS("PyDb.DiametricDimension");
    class_<PyDbDiametricDimension, bases<PyDbDimension>>("DiametricDimension")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>())
        .def(init<const AcGePoint3d&, const AcGePoint3d&, double>())
        .def(init<const AcGePoint3d&, const AcGePoint3d&, double, const std::string&>())
        .def(init<const AcGePoint3d&, const AcGePoint3d&, double, const std::string&, const PyDbObjectId&>(DS.CTOR(ctords)))
        .def("leaderLength", &PyDbDiametricDimension::leaderLength, DS.ARGS())
        .def("setLeaderLength", &PyDbDiametricDimension::setLeaderLength, DS.ARGS({ "val : float" }))
        .def("chordPoint", &PyDbDiametricDimension::chordPoint, DS.ARGS())
        .def("setChordPoint", &PyDbDiametricDimension::setChordPoint, DS.ARGS({ "pt : PyGe.Point3d" }))
        .def("farChordPoint", &PyDbDiametricDimension::farChordPoint, DS.ARGS())
        .def("setFarChordPoint", &PyDbDiametricDimension::setFarChordPoint, DS.ARGS({ "pt : PyGe.Point3d" }))
        .def("extArcStartAngle", &PyDbDiametricDimension::extArcStartAngle, DS.ARGS())
        .def("setExtArcStartAngle", &PyDbDiametricDimension::setExtArcStartAngle, DS.ARGS({ "val : float" }))
        .def("extArcEndAngle", &PyDbDiametricDimension::extArcEndAngle, DS.ARGS())
        .def("setExtArcEndAngle", &PyDbDiametricDimension::setExtArcEndAngle, DS.ARGS({ "val : float" }))
        .def("className", &PyDbDiametricDimension::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbDiametricDimension::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbDiametricDimension::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbDiametricDimension::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
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

PyDbDiametricDimension::PyDbDiametricDimension(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbDimension(openAcDbObject<AcDbDiametricDimension>(id, mode, erased), false)
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
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return impObj()->extArcStartAngle();
#endif
}

void PyDbDiametricDimension::setExtArcStartAngle(double newAngle)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setExtArcStartAngle(newAngle));
#endif
}

double PyDbDiametricDimension::extArcEndAngle() const
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return impObj()->extArcEndAngle();
#endif
}

void PyDbDiametricDimension::setExtArcEndAngle(double newAngle)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setExtArcEndAngle(newAngle));
#endif
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
    return PyDbObjectCloneFrom<PyDbDiametricDimension, AcDbDiametricDimension>(src);
}

PyDbDiametricDimension PyDbDiametricDimension::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbDiametricDimension>(src);
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
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- useXAxis: bool, definingPoint: PyGe.Point3d, leaderEndPoint: PyGe.Point3d\n"
        "- useXAxis: bool, definingPoint: PyGe.Point3d, leaderEndPoint: PyGe.Point3d, dimText: str\n"
        "- useXAxis: bool, definingPoint: PyGe.Point3d, leaderEndPoint: PyGe.Point3d, dimText: str, id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    PyDocString DS("PyDb.OrdinateDimension");
    class_<PyDbOrdinateDimension, bases<PyDbDimension>>("OrdinateDimension")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<Adesk::Boolean, const AcGePoint3d&, const AcGePoint3d&>())
        .def(init<Adesk::Boolean, const AcGePoint3d&, const AcGePoint3d&, const std::string&>())
        .def(init<Adesk::Boolean, const AcGePoint3d&, const AcGePoint3d&, const std::string&, const PyDbObjectId&>(DS.CTOR(ctords)))
        .def("isUsingXAxis", &PyDbOrdinateDimension::isUsingXAxis, DS.ARGS())
        .def("isUsingYAxis", &PyDbOrdinateDimension::isUsingYAxis, DS.ARGS())
        .def("useXAxis", &PyDbOrdinateDimension::useXAxis, DS.ARGS())
        .def("useYAxis", &PyDbOrdinateDimension::useYAxis, DS.ARGS())
        .def("setUsingXAxis", &PyDbOrdinateDimension::setUsingXAxis, DS.ARGS({ "val : bool" }))
        .def("setUsingYAxis", &PyDbOrdinateDimension::setUsingYAxis, DS.ARGS({ "val : bool" }))
        .def("origin", &PyDbOrdinateDimension::origin, DS.ARGS())
        .def("setOrigin", &PyDbOrdinateDimension::setOrigin, DS.ARGS({ "pt : PyGe.Point3d" }))
        .def("definingPoint", &PyDbOrdinateDimension::definingPoint, DS.ARGS())
        .def("setDefiningPoint", &PyDbOrdinateDimension::setDefiningPoint, DS.ARGS({ "pt : PyGe.Point3d" }))
        .def("leaderEndPoint", &PyDbOrdinateDimension::leaderEndPoint, DS.ARGS())
        .def("setLeaderEndPoint", &PyDbOrdinateDimension::setLeaderEndPoint, DS.ARGS({ "pt : PyGe.Point3d" }))
        .def("className", &PyDbOrdinateDimension::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbOrdinateDimension::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbOrdinateDimension::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbOrdinateDimension::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
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

PyDbOrdinateDimension::PyDbOrdinateDimension(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbDimension(openAcDbObject<AcDbOrdinateDimension>(id, mode, erased), false)
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

#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setUsingXAxis(value));
#endif
}

void PyDbOrdinateDimension::setUsingYAxis(bool value)
{

#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setUsingYAxis(value));
#endif
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
    return PyDbObjectCloneFrom<PyDbOrdinateDimension, AcDbOrdinateDimension>(src);
}

PyDbOrdinateDimension PyDbOrdinateDimension::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbOrdinateDimension>(src);
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
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- center: PyGe.Point3d, chordPoint: PyGe.Point3d,length:float\n"
        "- center: PyGe.Point3d, chordPoint: PyGe.Point3d,length:float, dimText: str\n"
        "- center: PyGe.Point3d, chordPoint: PyGe.Point3d,length:float, dimText: str, id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    PyDocString DS("PyDb.RadialDimension");
    class_<PyDbRadialDimension, bases<PyDbDimension>>("RadialDimension")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>())
        .def(init<const AcGePoint3d&, const AcGePoint3d&, double>())
        .def(init<const AcGePoint3d&, const AcGePoint3d&, double, const std::string&>())
        .def(init<const AcGePoint3d&, const AcGePoint3d&, double, const std::string&, const PyDbObjectId&>(DS.CTOR(ctords)))
        .def("leaderLength", &PyDbRadialDimension::leaderLength, DS.ARGS())
        .def("setLeaderLength", &PyDbRadialDimension::setLeaderLength, DS.ARGS({ "val : float" }))
        .def("center", &PyDbRadialDimension::center, DS.ARGS())
        .def("setCenter", &PyDbRadialDimension::setCenter, DS.ARGS({ "pt : PyGe.Point3d" }))
        .def("chordPoint", &PyDbRadialDimension::chordPoint, DS.ARGS())
        .def("setChordPoint", &PyDbRadialDimension::setChordPoint, DS.ARGS({ "pt : PyGe.Point3d" }))
        .def("extArcStartAngle", &PyDbRadialDimension::extArcStartAngle, DS.ARGS())
        .def("setExtArcStartAngle", &PyDbRadialDimension::setExtArcStartAngle, DS.ARGS({ "val : float" }))
        .def("extArcEndAngle", &PyDbRadialDimension::extArcEndAngle, DS.ARGS())
        .def("setExtArcEndAngle", &PyDbRadialDimension::setExtArcEndAngle, DS.ARGS({ "val : float" }))
        .def("className", &PyDbRadialDimension::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbRadialDimension::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbRadialDimension::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbRadialDimension::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
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

PyDbRadialDimension::PyDbRadialDimension(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbDimension(openAcDbObject<AcDbRadialDimension>(id, mode, erased), false)
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
    return PyDbObjectCloneFrom<PyDbRadialDimension, AcDbRadialDimension>(src);
}

PyDbRadialDimension PyDbRadialDimension::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbRadialDimension>(src);
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
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- center: PyGe.Point3d, chordPoint: PyGe.Point3d, overrideCenter: PyGe.Point3d, jogPoint: PyGe.Point3d, jogAngle: float\n"
        "- center: PyGe.Point3d, chordPoint: PyGe.Point3d, overrideCenter: PyGe.Point3d, jogPoint: PyGe.Point3d, jogAngle: float, dimText: str\n"
        "- center: PyGe.Point3d, chordPoint: PyGe.Point3d, overrideCenter: PyGe.Point3d, jogPoint: PyGe.Point3d, jogAngle: float, dimText: str, id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    PyDocString DS("PyDb.RadialDimensionLarge");
    class_<PyDbRadialDimensionLarge, bases<PyDbDimension>>("RadialDimensionLarge")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode, bool>())
        .def(init<const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&, double>())
        .def(init<const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&, double, const std::string&>())
        .def(init<const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&, double, const std::string&, const PyDbObjectId&>(DS.CTOR(ctords)))
        .def("center", &PyDbRadialDimensionLarge::center, DS.ARGS())
        .def("setCenter", &PyDbRadialDimensionLarge::setCenter, DS.ARGS({ "pt : PyGe.Point3d" }))
        .def("chordPoint", &PyDbRadialDimensionLarge::chordPoint, DS.ARGS())
        .def("setChordPoint", &PyDbRadialDimensionLarge::setChordPoint, DS.ARGS({ "pt : PyGe.Point3d" }))
        .def("overrideCenter", &PyDbRadialDimensionLarge::overrideCenter, DS.ARGS())
        .def("setOverrideCenter", &PyDbRadialDimensionLarge::setOverrideCenter, DS.ARGS({ "pt : PyGe.Point3d" }))
        .def("jogPoint", &PyDbRadialDimensionLarge::jogPoint, DS.ARGS())
        .def("setJogPoint", &PyDbRadialDimensionLarge::setJogPoint, DS.ARGS({ "pt : PyGe.Point3d" }))
        .def("jogAngle", &PyDbRadialDimensionLarge::jogAngle, DS.ARGS())
        .def("setJogAngle", &PyDbRadialDimensionLarge::setJogAngle, DS.ARGS({ "val : float" }))
        .def("setOverrideCenterPP", &PyDbRadialDimensionLarge::setOverrideCenterPP, DS.ARGS({ "pt : PyGe.Point3d" }))
        .def("setJogPointPP", &PyDbRadialDimensionLarge::setJogPointPP, DS.ARGS({ "pt : PyGe.Point3d" }))
        .def("setTextPositionPP", &PyDbRadialDimensionLarge::setTextPositionPP, DS.ARGS({ "pt : PyGe.Point3d" }))
        .def("extArcStartAngle", &PyDbRadialDimensionLarge::extArcStartAngle, DS.ARGS())
        .def("setExtArcStartAngle", &PyDbRadialDimensionLarge::setExtArcStartAngle, DS.ARGS({ "val : float" }))
        .def("extArcEndAngle", &PyDbRadialDimensionLarge::extArcEndAngle, DS.ARGS())
        .def("setExtArcEndAngle", &PyDbRadialDimensionLarge::setExtArcEndAngle, DS.ARGS({ "val : float" }))
        .def("className", &PyDbRadialDimensionLarge::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbRadialDimensionLarge::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbRadialDimensionLarge::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbRadialDimensionLarge::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
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

PyDbRadialDimensionLarge::PyDbRadialDimensionLarge(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbDimension(openAcDbObject<AcDbRadialDimensionLarge>(id, mode, erased), false)
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
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setOverrideCenterPP(overrideCenterPointPP));
#endif
}

void PyDbRadialDimensionLarge::setJogPointPP(const AcGePoint3d& jogPointPP)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setJogPointPP(jogPointPP));
#endif
}

void PyDbRadialDimensionLarge::setTextPositionPP(const AcGePoint3d& textPointPP)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setTextPositionPP(textPointPP));
#endif
}

double PyDbRadialDimensionLarge::extArcStartAngle() const
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return impObj()->extArcStartAngle();
#endif
}

void PyDbRadialDimensionLarge::setExtArcStartAngle(double newAngle)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setExtArcStartAngle(newAngle));
#endif
}

double PyDbRadialDimensionLarge::extArcEndAngle() const
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return impObj()->extArcEndAngle();
#endif
}

void PyDbRadialDimensionLarge::setExtArcEndAngle(double newAngle)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setExtArcEndAngle(newAngle));
#endif
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
    return PyDbObjectCloneFrom<PyDbRadialDimensionLarge, AcDbRadialDimensionLarge>(src);
}

PyDbRadialDimensionLarge PyDbRadialDimensionLarge::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbRadialDimensionLarge>(src);
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
    constexpr const std::string_view ctords = "Overloads:\n"
        "- None: Any\n"
        "- rotation: float, xl1: PyGe.Point3d, xl2: PyGe.Point3d, dimLinePoint: PyGe.Point3d\n"
        "- rotation: float, xl1: PyGe.Point3d, xl2: PyGe.Point3d, dimLinePoint: PyGe.Point3d, dimText: str\n"
        "- rotation: float, xl1: PyGe.Point3d, xl2: PyGe.Point3d, dimLinePoint: PyGe.Point3d, dimText: str, id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode\n"
        "- id: PyDb.ObjectId, mode: PyDb.OpenMode, erased: bool\n";

    PyDocString DS("PyDb.RotatedDimension");
    class_<PyDbRotatedDimension, bases<PyDbDimension>>("RotatedDimension")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<double, const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&>())
        .def(init<double, const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&, const std::string&>())
        .def(init<double, const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&, const std::string&, const PyDbObjectId&>(DS.CTOR(ctords)))
        .def("xLine1Point", &PyDbRotatedDimension::xLine1Point, DS.ARGS())
        .def("setXLine1Point", &PyDbRotatedDimension::setXLine1Point, DS.ARGS({ "pt : PyGe.Point3d" }))
        .def("xLine2Point", &PyDbRotatedDimension::xLine2Point, DS.ARGS())
        .def("setXLine2Point", &PyDbRotatedDimension::setXLine2Point, DS.ARGS({ "pt : PyGe.Point3d" }))
        .def("dimLinePoint", &PyDbRotatedDimension::dimLinePoint, DS.ARGS())
        .def("setDimLinePoint", &PyDbRotatedDimension::setDimLinePoint, DS.ARGS({ "pt : PyGe.Point3d" }))
        .def("oblique", &PyDbRotatedDimension::oblique, DS.ARGS())
        .def("setOblique", &PyDbRotatedDimension::setOblique, DS.ARGS({ "val : float" }))
        .def("rotation", &PyDbRotatedDimension::rotation, DS.ARGS())
        .def("setRotation", &PyDbRotatedDimension::setRotation, DS.ARGS({ "val : float" }))
        .def("jogSymbolOn", &PyDbRotatedDimension::jogSymbolOn, DS.ARGS())
        .def("setJogSymbolOn", &PyDbRotatedDimension::setJogSymbolOn, DS.ARGS({ "val : bool" }))
        .def("jogSymbolPosition", &PyDbRotatedDimension::jogSymbolPosition, DS.ARGS())
        .def("setJogSymbolPosition", &PyDbRotatedDimension::setJogSymbolPosition, DS.ARGS({ "pt : PyGe.Point3d" }))
        .def("className", &PyDbRotatedDimension::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbRotatedDimension::desc, DS.SARGS(15560)).staticmethod("desc")
        .def("cloneFrom", &PyDbRotatedDimension::cloneFrom, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbRotatedDimension::cast, DS.SARGS({ "otherObject: PyRx.RxObject" })).staticmethod("cast")
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

PyDbRotatedDimension::PyDbRotatedDimension(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased)
    : PyDbDimension(openAcDbObject<AcDbRotatedDimension>(id, mode, erased), false)
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
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return impObj()->jogSymbolOn();
#endif
}

void PyDbRotatedDimension::setJogSymbolOn(bool val)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setJogSymbolOn(val));
#endif
}

AcGePoint3d PyDbRotatedDimension::jogSymbolPosition() const
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return impObj()->jogSymbolPosition();
#endif
}

void PyDbRotatedDimension::setJogSymbolPosition(const AcGePoint3d& val)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setJogSymbolPosition(val));
#endif
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
    return PyDbObjectCloneFrom<PyDbRotatedDimension, AcDbRotatedDimension>(src);
}

PyDbRotatedDimension PyDbRotatedDimension::cast(const PyRxObject& src)
{
    return PyDbObjectCast<PyDbRotatedDimension>(src);
}

AcDbRotatedDimension* PyDbRotatedDimension::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
        }
    return static_cast<AcDbRotatedDimension*>(m_pyImp.get());
}
