#include "stdafx.h"
#include "PyDbEnts.h"
#include "PyDbObjectId.h"
#include "PyGeLinearEnt2d.h"
#include "PyGeLinearEnt3d.h"
#include "PyGeCurve2d.h"
#include "PyGeCurve3d.h"
#include "PyDbMText.h"
#include "PyDbEval.h"

using namespace boost::python;
//-----------------------------------------------------------------------------------
//PyDbText
void makePyDbTextWrapper()
{
    PyDocString DS("Text");
    class_<PyDbText, bases<PyDbEntity>>("Text")
        .def(init<>())
        .def(init<AcGePoint3d&, const std::string&>())
        .def(init<AcGePoint3d&, const std::string&, PyDbObjectId&, double, double>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("position", &PyDbText::position, DS.ARGS())
        .def("setPosition", &PyDbText::setPosition, DS.ARGS({ "pos : PyGe.Point3d" }))
        .def("alignmentPoint", &PyDbText::alignmentPoint, DS.ARGS())
        .def("setAlignmentPoint", &PyDbText::setAlignmentPoint, DS.ARGS({ "val : PyGe.Point3d" }))
        .def("isDefaultAlignment", &PyDbText::isDefaultAlignment, DS.ARGS())
        .def("normal", &PyDbText::normal, DS.ARGS())
        .def("setNormal", &PyDbText::setNormal, DS.ARGS({ "val : PyGe.Vector3d" }))
        .def("thickness", &PyDbText::thickness, DS.ARGS())
        .def("setThickness", &PyDbText::setThickness, DS.ARGS({ "val : float" }))
        .def("oblique", &PyDbText::oblique, DS.ARGS())
        .def("setOblique", &PyDbText::setOblique, DS.ARGS({ "val : float" }))
        .def("rotation", &PyDbText::rotation, DS.ARGS())
        .def("setRotation", &PyDbText::setRotation, DS.ARGS({ "val : float" }))
        .def("height", &PyDbText::height, DS.ARGS())
        .def("setHeight", &PyDbText::setHeight, DS.ARGS({ "val : float" }))
        .def("widthFactor", &PyDbText::widthFactor, DS.ARGS())
        .def("setWidthFactor", &PyDbText::setWidthFactor, DS.ARGS({ "val : float" }))
        .def("textString", &PyDbText::textString, DS.ARGS())
        .def("setTextString", &PyDbText::setTextString, DS.ARGS({ "val : str" }))
        .def("textStyle", &PyDbText::textStyle, DS.ARGS())
        .def("setTextStyle", &PyDbText::setTextStyle, DS.ARGS({ "val : ObjectId" }))
        .def("isMirroredInX", &PyDbText::isMirroredInX, DS.ARGS())
        .def("mirrorInX", &PyDbText::mirrorInX, DS.ARGS({ "val : bool" }))
        .def("isMirroredInY", &PyDbText::isMirroredInY, DS.ARGS())
        .def("mirrorInY", &PyDbText::mirrorInY, DS.ARGS({ "val : bool" }))
        .def("horizontalMode", &PyDbText::horizontalMode, DS.ARGS())
        .def("setHorizontalMode", &PyDbText::setHorizontalMode, DS.ARGS({ "val : TextHorzMode" }))
        .def("verticalMode", &PyDbText::verticalMode, DS.ARGS())
        .def("setVerticalMode", &PyDbText::setVerticalMode, DS.ARGS({ "val : TextVertMode" }))
        .def("correctSpelling", &PyDbText::correctSpelling, DS.ARGS())
        .def("adjustAlignment", &PyDbText::adjustAlignment, DS.ARGS({ "val : Database" }))
        .def("convertFieldToText", &PyDbText::convertFieldToText, DS.ARGS())
        .def("hitTest", &PyDbText::hitTest, DS.ARGS({ "val : PyGe.Point3d" }))
        .def("getBoundingPoints", &PyDbText::getBoundingPoints, DS.ARGS())
        .def("justification", &PyDbText::justification, DS.ARGS())
        .def("setJustification", &PyDbText::setJustification, DS.ARGS({ "val : TextAlignment" }))
        .def("className", &PyDbText::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbText::desc, DS.SARGS()).staticmethod("desc")
        .def("cloneFrom", &PyDbText::cloneFrom, DS.SARGS({ "otherObject: RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbText::cast, DS.SARGS({ "otherObject: RxObject" })).staticmethod("cast")
        ;

    enum_<AcDbText::AcTextAlignment>("TextAlignment")
        .value("kTextAlignmentLeft", AcDbText::AcTextAlignment::kTextAlignmentLeft)
        .value("kTextAlignmentCenter", AcDbText::AcTextAlignment::kTextAlignmentCenter)
        .value("kTextAlignmentRight", AcDbText::AcTextAlignment::kTextAlignmentRight)
        .value("kTextAlignmentAligned", AcDbText::AcTextAlignment::kTextAlignmentAligned)
        .value("kTextAlignmentMiddle", AcDbText::AcTextAlignment::kTextAlignmentMiddle)
        .value("kTextAlignmentFit", AcDbText::AcTextAlignment::kTextAlignmentFit)
        .value("kTextAlignmentTopLeft", AcDbText::AcTextAlignment::kTextAlignmentTopLeft)
        .value("kTextAlignmentTopCenter", AcDbText::AcTextAlignment::kTextAlignmentTopCenter)
        .value("kTextAlignmentTopRight", AcDbText::AcTextAlignment::kTextAlignmentTopRight)
        .value("kTextAlignmentMiddleLeft", AcDbText::AcTextAlignment::kTextAlignmentMiddleLeft)
        .value("kTextAlignmentMiddleCenter", AcDbText::AcTextAlignment::kTextAlignmentMiddleCenter)
        .value("kTextAlignmentMiddleRight", AcDbText::AcTextAlignment::kTextAlignmentMiddleRight)
        .value("kTextAlignmentBottomLeft", AcDbText::AcTextAlignment::kTextAlignmentBottomLeft)
        .value("kTextAlignmentBottomCenter", AcDbText::AcTextAlignment::kTextAlignmentBottomCenter)
        .value("kTextAlignmentBottomRight", AcDbText::AcTextAlignment::kTextAlignmentBottomRight)
        .export_values()
        ;
}

PyDbText::PyDbText()
    : PyDbText::PyDbText(new AcDbText(), true)
{
}

PyDbText::PyDbText(const AcGePoint3d& position, const std::string& text)
    : PyDbText::PyDbText(new AcDbText(position, utf8_to_wstr(text).c_str()), true)
{
}

PyDbText::PyDbText(const AcGePoint3d& position, const std::string& text, PyDbObjectId& style, double height, double rotation)
    : PyDbText::PyDbText(new AcDbText(position, utf8_to_wstr(text).c_str(), style.m_id, height, rotation), true)
{
}

PyDbText::PyDbText(AcDbText* ptr, bool autoDelete)
    : PyDbEntity(ptr, autoDelete)
{
}

PyDbText::PyDbText(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbEntity(openAcDbObject<AcDbText>(id, mode), false)
{
}

PyDbText::PyDbText(const PyDbObjectId& id)
    : PyDbText(id, AcDb::OpenMode::kForRead)
{
}

AcGePoint3d PyDbText::position() const
{
    return impObj()->position();
}

void PyDbText::setPosition(const AcGePoint3d& val)
{
    return PyThrowBadEs(impObj()->setPosition(val));
}

AcGePoint3d PyDbText::alignmentPoint() const
{
    return impObj()->alignmentPoint();
}

void PyDbText::setAlignmentPoint(const AcGePoint3d& val)
{
    return PyThrowBadEs(impObj()->setAlignmentPoint(val));
}

Adesk::Boolean PyDbText::isDefaultAlignment() const
{
    return impObj()->isDefaultAlignment();
}

AcGeVector3d PyDbText::normal() const
{
    return impObj()->normal();
}

void PyDbText::setNormal(const AcGeVector3d& val)
{
    return PyThrowBadEs(impObj()->setNormal(val));
}

double PyDbText::thickness() const
{
    return impObj()->thickness();
}

void PyDbText::setThickness(double val)
{
    return PyThrowBadEs(impObj()->setThickness(val));
}

double PyDbText::oblique() const
{
    return impObj()->oblique();
}

void PyDbText::setOblique(double val)
{
    return PyThrowBadEs(impObj()->setOblique(val));
}

double PyDbText::rotation() const
{
    return impObj()->rotation();
}

void PyDbText::setRotation(double val)
{
    return PyThrowBadEs(impObj()->setRotation(val));
}

double PyDbText::height() const
{
    return impObj()->height();
}

void PyDbText::setHeight(double val)
{
    return PyThrowBadEs(impObj()->setHeight(val));
}

double PyDbText::widthFactor() const
{
    return impObj()->widthFactor();
}

void PyDbText::setWidthFactor(double val)
{
    return PyThrowBadEs(impObj()->setWidthFactor(val));
}

std::string PyDbText::textString() const
{
    return wstr_to_utf8(impObj()->textStringConst());
}

void PyDbText::setTextString(const std::string& val)
{
    return PyThrowBadEs(impObj()->setTextString(utf8_to_wstr(val).c_str()));
}

PyDbObjectId PyDbText::textStyle() const
{
    return PyDbObjectId(impObj()->textStyle());
}

void PyDbText::setTextStyle(const PyDbObjectId& val)
{
    return PyThrowBadEs(impObj()->setTextStyle(val.m_id));
}

Adesk::Boolean PyDbText::isMirroredInX() const
{
    return impObj()->isMirroredInX();
}

void PyDbText::mirrorInX(Adesk::Boolean val)
{
    return PyThrowBadEs(impObj()->mirrorInX(val));
}

Adesk::Boolean PyDbText::isMirroredInY() const
{
    return impObj()->isMirroredInY();
}

void PyDbText::mirrorInY(Adesk::Boolean val)
{
    return PyThrowBadEs(impObj()->mirrorInY(val));
}

AcDb::TextHorzMode PyDbText::horizontalMode() const
{
    return impObj()->horizontalMode();
}

void PyDbText::setHorizontalMode(AcDb::TextHorzMode val)
{
    return PyThrowBadEs(impObj()->setHorizontalMode(val));
}

AcDb::TextVertMode PyDbText::verticalMode() const
{
    return impObj()->verticalMode();
}

void PyDbText::setVerticalMode(AcDb::TextVertMode val)
{
    return PyThrowBadEs(impObj()->setVerticalMode(val));
}

int PyDbText::correctSpelling()
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return impObj()->correctSpelling();
#endif
}

void PyDbText::adjustAlignment(const PyDbDatabase& pDb)
{
    return PyThrowBadEs(impObj()->adjustAlignment(pDb.impObj()));
}

void PyDbText::convertFieldToText()
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->convertFieldToText());
#endif
}

bool PyDbText::hitTest(const AcGePoint3d& ptHit) const
{
#if _ZRXTARGET == 240 || _GRXTARGET == 240 || _BRXTARGET == 240
    throw PyNotimplementedByHost();
#else
    return impObj()->hitTest(ptHit);
#endif
}

boost::python::list PyDbText::getBoundingPoints() const
{
#if _ZRXTARGET == 240 || _GRXTARGET == 240
    throw PyNotimplementedByHost();
#else
    AcGePoint3dArray boundingPoints;
    impObj()->getBoundingPoints(boundingPoints);
    if (boundingPoints.length() == 0)
    {
        PyThrowBadEs(impObj()->draw());
        impObj()->getBoundingPoints(boundingPoints);
    }
    return Point3dArrayToPyList(boundingPoints);
#endif
}

AcDbText::AcTextAlignment PyDbText::justification() const
{
    return impObj()->justification();
}

void PyDbText::setJustification(AcDbText::AcTextAlignment val)
{
    return PyThrowBadEs(impObj()->setJustification(val));
}

std::string PyDbText::className()
{
    return "AcDbText";
}

PyRxClass PyDbText::desc()
{
    return PyRxClass(AcDbText::desc(), false);
}

PyDbText PyDbText::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbText::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbText(static_cast<AcDbText*>(src.impObj()->clone()), true);
}

PyDbText PyDbText::cast(const PyRxObject& src)
{
    PyDbText dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbText* PyDbText::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbText*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyDbAttributeDefinition
void makePyDbAttributeDefinitionWrapper()
{
    PyDocString DS("AttributeDefinition");
    class_<PyDbAttributeDefinition, bases<PyDbText>>("AttributeDefinition")
        .def(init<>())
        .def(init<const AcGePoint3d&, const std::string&, const std::string&, const std::string&, const PyDbObjectId&>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("prompt", &PyDbAttributeDefinition::prompt, DS.ARGS())
        .def("setPrompt", &PyDbAttributeDefinition::setPrompt, DS.ARGS({ "val : str" }))
        .def("tag", &PyDbAttributeDefinition::tag, DS.ARGS())
        .def("setTag", &PyDbAttributeDefinition::setTag, DS.ARGS({ "val : str" }))
        .def("isInvisible", &PyDbAttributeDefinition::isInvisible, DS.ARGS())
        .def("setInvisible", &PyDbAttributeDefinition::setInvisible, DS.ARGS({ "val : bool" }))
        .def("isConstant", &PyDbAttributeDefinition::isConstant, DS.ARGS())
        .def("setConstant", &PyDbAttributeDefinition::setConstant, DS.ARGS({ "val : bool" }))
        .def("isVerifiable", &PyDbAttributeDefinition::isVerifiable, DS.ARGS())
        .def("setVerifiable", &PyDbAttributeDefinition::setVerifiable, DS.ARGS({ "val : bool" }))
        .def("isPreset", &PyDbAttributeDefinition::isPreset, DS.ARGS())
        .def("setPreset", &PyDbAttributeDefinition::setPreset, DS.ARGS({ "val : bool" }))
        .def("fieldLength", &PyDbAttributeDefinition::fieldLength, DS.ARGS())
        .def("setFieldLength", &PyDbAttributeDefinition::setFieldLength, DS.ARGS({ "val : int" }))
        .def("adjustAlignment", &PyDbAttributeDefinition::adjustAlignment, DS.ARGS({ "val : Database" }))
        .def("lockPositionInBlock", &PyDbAttributeDefinition::lockPositionInBlock, DS.ARGS())
        .def("setLockPositionInBlock", &PyDbAttributeDefinition::setLockPositionInBlock, DS.ARGS({ "val : bool" }))
        .def("isMTextAttributeDefinition", &PyDbAttributeDefinition::isMTextAttributeDefinition, DS.ARGS())
        .def("convertIntoMTextAttributeDefinition", &PyDbAttributeDefinition::convertIntoMTextAttributeDefinition, DS.ARGS({ "val : bool" }))
        .def("updateMTextAttributeDefinition", &PyDbAttributeDefinition::updateMTextAttributeDefinition, DS.ARGS())
        .def("getMTextAttributeDefinition", &PyDbAttributeDefinition::getMTextAttributeDefinition, DS.ARGS())
        .def("setMTextAttributeDefinition", &PyDbAttributeDefinition::setMTextAttributeDefinition, DS.ARGS({ "val : MText" }))
        .def("className", &PyDbAttributeDefinition::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbAttributeDefinition::desc, DS.SARGS()).staticmethod("desc")
        .def("cloneFrom", &PyDbAttributeDefinition::cloneFrom, DS.SARGS({ "otherObject: RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbAttributeDefinition::cast, DS.SARGS({ "otherObject: RxObject" })).staticmethod("cast")
        ;
}

PyDbAttributeDefinition::PyDbAttributeDefinition()
    : PyDbText(new AcDbAttributeDefinition(), true)
{
}

PyDbAttributeDefinition::PyDbAttributeDefinition(const AcGePoint3d& position, const std::string& text, const std::string& tag, const std::string& prompt, const PyDbObjectId& style)
    : PyDbText(new AcDbAttributeDefinition(position, utf8_to_wstr(text).c_str(), utf8_to_wstr(tag).c_str(), utf8_to_wstr(prompt).c_str(), style.m_id), true)
{
}

PyDbAttributeDefinition::PyDbAttributeDefinition(AcDbAttributeDefinition* ptr, bool autoDelete)
    : PyDbText(ptr, autoDelete)
{
}

PyDbAttributeDefinition::PyDbAttributeDefinition(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbText(openAcDbObject<AcDbAttributeDefinition>(id, mode), false)
{
}

PyDbAttributeDefinition::PyDbAttributeDefinition(const PyDbObjectId& id)
    : PyDbAttributeDefinition(id, AcDb::OpenMode::kForRead)
{
}

std::string PyDbAttributeDefinition::prompt() const
{
    return wstr_to_utf8(impObj()->promptConst());
}

void PyDbAttributeDefinition::setPrompt(const std::string& val)
{
    return PyThrowBadEs(impObj()->setPrompt(utf8_to_wstr(val).c_str()));
}

std::string PyDbAttributeDefinition::tag() const
{
    return wstr_to_utf8(impObj()->tagConst());
}

void PyDbAttributeDefinition::setTag(const std::string& val)
{
    return PyThrowBadEs(impObj()->setTag(utf8_to_wstr(val).c_str()));
}

Adesk::Boolean PyDbAttributeDefinition::isInvisible() const
{
    return impObj()->isInvisible();
}

void PyDbAttributeDefinition::setInvisible(Adesk::Boolean val)
{
    return PyThrowBadEs(impObj()->setInvisible(val));
}

Adesk::Boolean PyDbAttributeDefinition::isConstant() const
{
    return impObj()->isConstant();
}

void PyDbAttributeDefinition::setConstant(Adesk::Boolean val)
{
    return PyThrowBadEs(impObj()->setConstant(val));
}

Adesk::Boolean PyDbAttributeDefinition::isVerifiable() const
{
    return impObj()->isVerifiable();
}

void PyDbAttributeDefinition::setVerifiable(Adesk::Boolean val)
{
    return PyThrowBadEs(impObj()->setVerifiable(val));
}

Adesk::Boolean PyDbAttributeDefinition::isPreset() const
{
    return impObj()->isPreset();
}

void PyDbAttributeDefinition::setPreset(Adesk::Boolean val)
{
    return PyThrowBadEs(impObj()->setPreset(val));
}

Adesk::UInt16 PyDbAttributeDefinition::fieldLength() const
{
    return impObj()->fieldLength();
}

void PyDbAttributeDefinition::setFieldLength(Adesk::UInt16 val)
{
    return PyThrowBadEs(impObj()->setFieldLength(val));
}

void PyDbAttributeDefinition::adjustAlignment(const PyDbDatabase& pDb)
{
    return PyThrowBadEs(impObj()->adjustAlignment(pDb.impObj()));
}

bool PyDbAttributeDefinition::lockPositionInBlock() const
{
    return impObj()->lockPositionInBlock();
}

void PyDbAttributeDefinition::setLockPositionInBlock(bool bValue)
{
    return PyThrowBadEs(impObj()->setLockPositionInBlock(bValue));
}

bool PyDbAttributeDefinition::isMTextAttributeDefinition() const
{
    return impObj()->isMTextAttributeDefinition();
}

PyDbMText PyDbAttributeDefinition::getMTextAttributeDefinition() const
{
    AcDbMText* ptr = impObj()->getMTextAttributeDefinition();
    if (ptr == nullptr)
        throw PyNullObject(std::source_location::current());
    return PyDbMText(ptr, true);
}

void PyDbAttributeDefinition::setMTextAttributeDefinition(const PyDbMText& mt)
{
    return PyThrowBadEs(impObj()->setMTextAttributeDefinition(mt.impObj()));
}

void PyDbAttributeDefinition::convertIntoMTextAttributeDefinition(Adesk::Boolean val)
{
    return PyThrowBadEs(impObj()->convertIntoMTextAttributeDefinition(val));
}

void PyDbAttributeDefinition::updateMTextAttributeDefinition()
{
    return PyThrowBadEs(impObj()->updateMTextAttributeDefinition());
}

std::string PyDbAttributeDefinition::className()
{
    return "AcDbAttributeDefinition";
}

PyRxClass PyDbAttributeDefinition::desc()
{
    return PyRxClass(AcDbAttributeDefinition::desc(), false);
}

PyDbAttributeDefinition PyDbAttributeDefinition::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbAttributeDefinition::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbAttributeDefinition(static_cast<AcDbAttributeDefinition*>(src.impObj()->clone()), true);
}

PyDbAttributeDefinition PyDbAttributeDefinition::cast(const PyRxObject& src)
{
    PyDbAttributeDefinition dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbAttributeDefinition* PyDbAttributeDefinition::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbAttributeDefinition*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyDbAttribute
void makePyDbAttributeWrapper()
{
    PyDocString DS("AttributeReference");
    class_<PyDbAttribute, bases<PyDbText>>("AttributeReference")
        .def(init<>())
        .def(init<const AcGePoint3d&, const std::string&, const std::string&, const PyDbObjectId&>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("tag", &PyDbAttribute::tag, DS.ARGS())
        .def("setTag", &PyDbAttribute::setTag, DS.ARGS({ "val : str" }))
        .def("isInvisible", &PyDbAttribute::isInvisible, DS.ARGS())
        .def("setInvisible", &PyDbAttribute::setInvisible, DS.ARGS({ "val : bool" }))
        .def("isConstant", &PyDbAttribute::isConstant, DS.ARGS())
        .def("isVerifiable", &PyDbAttribute::isVerifiable, DS.ARGS())
        .def("isPreset", &PyDbAttribute::isPreset, DS.ARGS())
        .def("fieldLength", &PyDbAttribute::fieldLength, DS.ARGS())
        .def("setFieldLength", &PyDbAttribute::setFieldLength, DS.ARGS({ "val : int" }))
        .def<void(PyDbAttribute::*)(const AcGeMatrix3d&)>("setAttributeFromBlock", &PyDbAttribute::setAttributeFromBlock)
        .def<void(PyDbAttribute::*)(const PyDbAttributeDefinition&, const AcGeMatrix3d&)>("setAttributeFromBlock", &PyDbAttribute::setAttributeFromBlock)
        .def("lockPositionInBlock", &PyDbAttribute::lockPositionInBlock, DS.ARGS())
        .def("setLockPositionInBlock", &PyDbAttribute::setLockPositionInBlock, DS.ARGS({ "val : bool" }))
        .def("isMTextAttribute", &PyDbAttribute::isMTextAttribute, DS.ARGS())
        .def("getMTextAttribute", &PyDbAttribute::getMTextAttribute, DS.ARGS())
        .def("setMTextAttribute", &PyDbAttribute::setMTextAttribute, DS.ARGS({ "val : MText" }))
        .def("convertIntoMTextAttribute", &PyDbAttribute::convertIntoMTextAttribute, DS.ARGS({ "val : bool" }))
        .def("updateMTextAttribute", &PyDbAttribute::updateMTextAttribute, DS.ARGS())
        .def("isReallyLocked", &PyDbAttribute::isReallyLocked, DS.ARGS())
        .def("className", &PyDbAttribute::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbAttribute::desc, DS.SARGS()).staticmethod("desc")
        .def("cloneFrom", &PyDbAttribute::cloneFrom, DS.SARGS({ "otherObject: RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbAttribute::cast, DS.SARGS({ "otherObject: RxObject" })).staticmethod("cast")
        ;
}

PyDbAttribute::PyDbAttribute()
    : PyDbText(new AcDbAttribute(), true)
{
}

PyDbAttribute::PyDbAttribute(const AcGePoint3d& position, const std::string& text, const std::string& tag, const PyDbObjectId& style)
    : PyDbText(new AcDbAttribute(position, utf8_to_wstr(text).c_str(), utf8_to_wstr(tag).c_str(), style.m_id), true)
{
}

PyDbAttribute::PyDbAttribute(AcDbAttribute* ptr, bool autoDelete)
    : PyDbText(ptr, autoDelete)
{
}

PyDbAttribute::PyDbAttribute(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbText(openAcDbObject<AcDbAttribute>(id, mode), false)
{
}

PyDbAttribute::PyDbAttribute(const PyDbObjectId& id)
    : PyDbAttribute(id, AcDb::OpenMode::kForRead)
{
}

std::string PyDbAttribute::tag() const
{
    return wstr_to_utf8(impObj()->tagConst());
}

void PyDbAttribute::setTag(const std::string& val)
{
    return PyThrowBadEs(impObj()->setTag(utf8_to_wstr(val).c_str()));
}

Adesk::Boolean PyDbAttribute::isInvisible() const
{
    return impObj()->isInvisible();
}

void PyDbAttribute::setInvisible(Adesk::Boolean val)
{
    return PyThrowBadEs(impObj()->setInvisible(val));
}

Adesk::Boolean PyDbAttribute::isConstant() const
{
    return impObj()->isConstant();
}

Adesk::Boolean PyDbAttribute::isVerifiable() const
{
    return impObj()->isVerifiable();
}

Adesk::Boolean PyDbAttribute::isPreset() const
{
    return impObj()->isPreset();
}

Adesk::UInt16 PyDbAttribute::fieldLength() const
{
    return impObj()->isPreset();
}

void PyDbAttribute::setFieldLength(Adesk::UInt16 val)
{
    return PyThrowBadEs(impObj()->setFieldLength(val));
}

void PyDbAttribute::setAttributeFromBlock(const AcGeMatrix3d& blkXform)
{
    return PyThrowBadEs(impObj()->setAttributeFromBlock(blkXform));
}

void PyDbAttribute::setAttributeFromBlock(const PyDbAttributeDefinition& pAttdef, const AcGeMatrix3d& blkXform)
{
    return PyThrowBadEs(impObj()->setAttributeFromBlock(pAttdef.impObj(), blkXform));
}

bool PyDbAttribute::lockPositionInBlock() const
{
    return impObj()->lockPositionInBlock();
}

void PyDbAttribute::setLockPositionInBlock(bool bValue)
{
    return PyThrowBadEs(impObj()->setLockPositionInBlock(bValue));
}

bool PyDbAttribute::isMTextAttribute() const
{
    return impObj()->isMTextAttribute();
}

PyDbMText PyDbAttribute::getMTextAttribute() const
{
    return PyDbMText(impObj()->getMTextAttribute(), true);
}

void PyDbAttribute::setMTextAttribute(PyDbMText& mt)
{
    return PyThrowBadEs(impObj()->setMTextAttribute(mt.impObj()));
}

void PyDbAttribute::convertIntoMTextAttribute(Adesk::Boolean val)
{
    return PyThrowBadEs(impObj()->convertIntoMTextAttribute(val));
}

void PyDbAttribute::updateMTextAttribute()
{
    return PyThrowBadEs(impObj()->updateMTextAttribute());
}

bool PyDbAttribute::isReallyLocked() const
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return impObj()->isReallyLocked();
#endif
}

std::string PyDbAttribute::className()
{
    return "AcDbAttribute";
}

PyRxClass PyDbAttribute::desc()
{
    return PyRxClass(AcDbAttribute::desc(), false);
}

PyDbAttribute PyDbAttribute::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbAttribute::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbAttribute(static_cast<AcDbAttribute*>(src.impObj()->clone()), true);
}

PyDbAttribute PyDbAttribute::cast(const PyRxObject& src)
{
    PyDbAttribute dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbAttribute* PyDbAttribute::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbAttribute*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyDbBlockReference
void makePyDbBlockReferenceWrapper()
{
    PyDocString DS("BlockReference");
    class_<PyDbBlockReference, bases<PyDbEntity>>("BlockReference")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const AcGePoint3d&, const PyDbObjectId&>())
        .def("blockTableRecord", &PyDbBlockReference::blockTableRecord, DS.ARGS())
        .def("setBlockTableRecord", &PyDbBlockReference::setBlockTableRecord, DS.ARGS({ "val : ObjectId" }))
        .def("position", &PyDbBlockReference::position, DS.ARGS())
        .def("setPosition", &PyDbBlockReference::setPosition, DS.ARGS({ "val : PyGe.Point3d" }))
        .def("scaleFactors", &PyDbBlockReference::scaleFactors, DS.ARGS())
        .def("nonAnnotationScaleFactors", &PyDbBlockReference::nonAnnotationScaleFactors, DS.ARGS())
        .def("setScaleFactors", &PyDbBlockReference::setScaleFactors, DS.ARGS({ "val : PyGe.Scale3d" }))
        .def("rotation", &PyDbBlockReference::rotation, DS.ARGS())
        .def("setRotation", &PyDbBlockReference::setRotation, DS.ARGS({ "val : float" }))
        .def("normal", &PyDbBlockReference::normal, DS.ARGS())
        .def("setNormal", &PyDbBlockReference::setNormal, DS.ARGS({ "val : PyGe.Vector3d" }))
        .def("blockTransform", &PyDbBlockReference::blockTransform, DS.ARGS())
        .def("nonAnnotationBlockTransform", &PyDbBlockReference::nonAnnotationBlockTransform, DS.ARGS())
        .def("setBlockTransform", &PyDbBlockReference::setBlockTransform, DS.ARGS({ "val : PyGe.Matrix3d" }))
        .def("appendAttribute", &PyDbBlockReference::appendAttribute, DS.ARGS({ "val : Attribute" }))
        .def("attributeIds", &PyDbBlockReference::attributeIds, DS.ARGS())
        .def("treatAsAcDbBlockRefForExplode", &PyDbBlockReference::treatAsAcDbBlockRefForExplode, DS.ARGS())
        .def("geomExtentsBestFit", &PyDbBlockReference::geomExtentsBestFit1)
        .def("geomExtentsBestFit", &PyDbBlockReference::geomExtentsBestFit2, DS.ARGS({ "val : PyGe.Matrix3d=kIdentity" }))
        .def("explodeToOwnerSpace", &PyDbBlockReference::explodeToOwnerSpace, DS.ARGS())
        .def("getBlockName", &PyDbBlockReference::getBlockName, DS.ARGS())
        .def("className", &PyDbBlockReference::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbBlockReference::desc, DS.SARGS()).staticmethod("desc")
        .def("cloneFrom", &PyDbBlockReference::cloneFrom, DS.SARGS({ "otherObject: RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbBlockReference::cast, DS.SARGS({ "otherObject: RxObject" })).staticmethod("cast")
        ;
}

PyDbBlockReference::PyDbBlockReference()
    : PyDbBlockReference(new AcDbBlockReference(), true)
{
}

PyDbBlockReference::PyDbBlockReference(const AcGePoint3d& position, const PyDbObjectId& blockTableRec)
    : PyDbBlockReference(new AcDbBlockReference(position, blockTableRec.m_id), true)
{
}

PyDbBlockReference::PyDbBlockReference(AcDbBlockReference* ptr, bool autoDelete)
    : PyDbEntity(ptr, autoDelete)
{
}

PyDbBlockReference::PyDbBlockReference(const PyDbObjectId& id)
    : PyDbBlockReference(id, AcDb::OpenMode::kForRead)
{
}

PyDbBlockReference::PyDbBlockReference(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbEntity(openAcDbObject<AcDbBlockReference>(id, mode), false)
{
}

PyDbObjectId PyDbBlockReference::blockTableRecord() const
{
    return PyDbObjectId(impObj()->blockTableRecord());
}

void PyDbBlockReference::setBlockTableRecord(const PyDbObjectId& val)
{
    return PyThrowBadEs(impObj()->setBlockTableRecord(val.m_id));
}

AcGePoint3d PyDbBlockReference::position() const
{
    return impObj()->position();
}

void PyDbBlockReference::setPosition(const AcGePoint3d& val)
{
    return PyThrowBadEs(impObj()->setPosition(val));
}

AcGeScale3d PyDbBlockReference::scaleFactors() const
{
    return impObj()->scaleFactors();
}

AcGeScale3d PyDbBlockReference::nonAnnotationScaleFactors() const
{
    return impObj()->nonAnnotationScaleFactors();
}

void PyDbBlockReference::setScaleFactors(const AcGeScale3d& scale)
{
    return PyThrowBadEs(impObj()->setScaleFactors(scale));
}

double PyDbBlockReference::rotation() const
{
    return impObj()->rotation();
}

void PyDbBlockReference::setRotation(double newVal)
{
    return PyThrowBadEs(impObj()->setRotation(newVal));
}

AcGeVector3d PyDbBlockReference::normal() const
{
    return impObj()->normal();
}

void PyDbBlockReference::setNormal(const AcGeVector3d& newVal)
{
    return PyThrowBadEs(impObj()->setNormal(newVal));
}

AcGeMatrix3d PyDbBlockReference::blockTransform() const
{
    return impObj()->blockTransform();
}

AcGeMatrix3d PyDbBlockReference::nonAnnotationBlockTransform() const
{
    return impObj()->nonAnnotationBlockTransform();
}

void PyDbBlockReference::setBlockTransform(const AcGeMatrix3d& val)
{
    return PyThrowBadEs(impObj()->setBlockTransform(val));
}

PyDbObjectId PyDbBlockReference::appendAttribute(PyDbAttribute& att)
{
    AcDbObjectId id;
    PyThrowBadEs(impObj()->appendAttribute(id, att.impObj()));
    return PyDbObjectId(id);
}

boost::python::list PyDbBlockReference::attributeIds() const
{
    PyAutoLockGIL lock;
    AcDbObjectId id;
    boost::python::list ids;
    for (std::unique_ptr<AcDbObjectIterator> iter(impObj()->attributeIterator()); !iter->done(); iter->step())
        ids.append(PyDbObjectId(iter->objectId()));
    return ids;
}

Adesk::Boolean PyDbBlockReference::treatAsAcDbBlockRefForExplode() const
{
    return impObj()->treatAsAcDbBlockRefForExplode();
}

AcDbExtents PyDbBlockReference::geomExtentsBestFit1() const
{
    return geomExtentsBestFit2(AcGeMatrix3d::kIdentity);
}

AcDbExtents PyDbBlockReference::geomExtentsBestFit2(const AcGeMatrix3d& parentXform) const
{
    AcDbExtents ex;
    PyThrowBadEs(impObj()->geomExtentsBestFit(ex, parentXform));
    return ex;
}

void PyDbBlockReference::explodeToOwnerSpace() const
{
    return PyThrowBadEs(impObj()->explodeToOwnerSpace());
}

std::string PyDbBlockReference::getBlockName() const
{
    AcString name;
    AcDbBlockTableRecordPointer bBlock(impObj()->blockTableRecord());
    if (bBlock.openStatus() == eOk)
        PyThrowBadEs(bBlock->getName(name));
    return wstr_to_utf8(name);
}

std::string PyDbBlockReference::className()
{
    return "AcDbBlockReference";
}

PyRxClass PyDbBlockReference::desc()
{
    return PyRxClass(AcDbBlockReference::desc(), false);
}

PyDbBlockReference PyDbBlockReference::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbBlockReference::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbBlockReference(static_cast<AcDbBlockReference*>(src.impObj()->clone()), true);
}

PyDbBlockReference PyDbBlockReference::cast(const PyRxObject& src)
{
    PyDbBlockReference dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbBlockReference* PyDbBlockReference::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbBlockReference*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyDbDynBlockReference
void makePyDbDynBlockReferenceWrapper() //TODO: Make test
{
    PyDocString DS("DynBlockReference");
    class_<PyDbDynBlockReference>("DynBlockReference", no_init)
        .def(init<const PyDbObjectId&>(DS.ARGS({ "val : ObjectId" })))
        .def("isDynamicBlock", &PyDbDynBlockReference::isDynamicBlock1, DS.ARGS())
        .def("blockId", &PyDbDynBlockReference::blockId, DS.ARGS())
        .def("resetBlock", &PyDbDynBlockReference::resetBlock, DS.ARGS())
        .def("convertToStaticBlock", &PyDbDynBlockReference::convertToStaticBlock1)
        .def("convertToStaticBlock", &PyDbDynBlockReference::convertToStaticBlock2, DS.ARGS({ "val : str=None" }))
        .def("dynamicBlockTableRecord", &PyDbDynBlockReference::dynamicBlockTableRecord, DS.ARGS())
        .def("anonymousBlockTableRecord", &PyDbDynBlockReference::anonymousBlockTableRecord, DS.ARGS())
        .def("getBlockProperties", &PyDbDynBlockReference::getBlockProperties, DS.ARGS())
        .def("getIsDynamicBlock", &PyDbDynBlockReference::isDynamicBlock2, DS.SARGS({ "otherObject: ObjectId" })).staticmethod("getIsDynamicBlock")
        .def("className", &PyDbDynBlockReference::className, DS.SARGS()).staticmethod("className")
        ;
}

PyDbDynBlockReference::PyDbDynBlockReference(const PyDbObjectId& id)
    : m_imp(new AcDbDynBlockReference(id.m_id))
{
}

bool PyDbDynBlockReference::isDynamicBlock1() const
{
    return impObj()->isDynamicBlock();
}

PyDbObjectId PyDbDynBlockReference::blockId() const
{
    return PyDbObjectId(impObj()->blockId());
}

void PyDbDynBlockReference::resetBlock()
{
    return PyThrowBadEs(impObj()->resetBlock());
}

void PyDbDynBlockReference::convertToStaticBlock1()
{
    return PyThrowBadEs(impObj()->convertToStaticBlock());
}

void PyDbDynBlockReference::convertToStaticBlock2(const std::string& newBlockName)
{
    return PyThrowBadEs(impObj()->convertToStaticBlock(utf8_to_wstr(newBlockName).c_str()));
}

PyDbObjectId PyDbDynBlockReference::dynamicBlockTableRecord() const
{
    return PyDbObjectId(impObj()->dynamicBlockTableRecord());
}

PyDbObjectId PyDbDynBlockReference::anonymousBlockTableRecord() const
{
    return PyDbObjectId(impObj()->anonymousBlockTableRecord());
}

boost::python::list PyDbDynBlockReference::getBlockProperties() const
{
    PyAutoLockGIL lock;
    boost::python::list pyList;
    AcDbDynBlockReferencePropertyArray properties;
    impObj()->getBlockProperties(properties);
    for (const auto& item : properties)
        pyList.append(PyDbDynBlockReferenceProperty(item));
    return pyList;
}

bool PyDbDynBlockReference::isDynamicBlock2(const PyDbObjectId& blockTableRecordId)
{
    return AcDbDynBlockReference::isDynamicBlock(blockTableRecordId.m_id);
}

std::string PyDbDynBlockReference::className()
{
    return "AcDbDynBlockReference";
}

AcDbDynBlockReference* PyDbDynBlockReference::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbDynBlockReference*>(m_imp.get());
}

//-----------------------------------------------------------------------------------
//DbMInsertBlock
void makePyDbMInsertBlockeWrapper()
{
    PyDocString DS("MInsertBlock");
    class_<PyDbMInsertBlock, bases<PyDbBlockReference>>("MInsertBlock")
        .def(init<>())
        .def(init<AcGePoint3d&, const PyDbObjectId&, Adesk::UInt16, Adesk::UInt16, double, double>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("columns", &PyDbMInsertBlock::columns, DS.ARGS())
        .def("setColumns", &PyDbMInsertBlock::setColumns, DS.ARGS({ "val : int" }))
        .def("rows", &PyDbMInsertBlock::rows, DS.ARGS())
        .def("setRows", &PyDbMInsertBlock::setRows, DS.ARGS({ "val : int" }))
        .def("columnSpacing", &PyDbMInsertBlock::columnSpacing, DS.ARGS())
        .def("setColumnSpacing", &PyDbMInsertBlock::setColumnSpacing, DS.ARGS({ "val : float" }))
        .def("rowSpacing", &PyDbMInsertBlock::rowSpacing, DS.ARGS())
        .def("setRowSpacing", &PyDbMInsertBlock::setRowSpacing, DS.ARGS({ "val : float" }))
        .def("className", &PyDbMInsertBlock::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbMInsertBlock::desc, DS.SARGS()).staticmethod("desc")
        .def("cloneFrom", &PyDbMInsertBlock::cloneFrom, DS.SARGS({ "otherObject: RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbMInsertBlock::cast, DS.SARGS({ "otherObject: RxObject" })).staticmethod("cast")
        ;
}

PyDbMInsertBlock::PyDbMInsertBlock()
    : PyDbMInsertBlock(new AcDbMInsertBlock(), true)
{
}

PyDbMInsertBlock::PyDbMInsertBlock(const AcGePoint3d& position, const PyDbObjectId& blockTableRec, Adesk::UInt16 columns, Adesk::UInt16 rows, double colSpacing, double rowSpacing)
    : PyDbMInsertBlock(new AcDbMInsertBlock(position, blockTableRec.m_id, columns, rows, colSpacing, rowSpacing), true)
{
}

PyDbMInsertBlock::PyDbMInsertBlock(AcDbMInsertBlock* ptr, bool autoDelete)
    : PyDbBlockReference(ptr, autoDelete)
{
}

PyDbMInsertBlock::PyDbMInsertBlock(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbBlockReference(openAcDbObject<AcDbMInsertBlock>(id, mode), false)
{
}

PyDbMInsertBlock::PyDbMInsertBlock(const PyDbObjectId& id)
    : PyDbMInsertBlock(id, AcDb::OpenMode::kForRead)
{
}

Adesk::UInt16 PyDbMInsertBlock::columns() const
{
    return impObj()->columns();
}

void PyDbMInsertBlock::setColumns(Adesk::UInt16 val)
{
    return PyThrowBadEs(impObj()->setColumns(val));
}

Adesk::UInt16 PyDbMInsertBlock::rows() const
{
    return impObj()->rows();
}

void PyDbMInsertBlock::setRows(Adesk::UInt16 val)
{
    return PyThrowBadEs(impObj()->setRows(val));
}

double PyDbMInsertBlock::columnSpacing() const
{
    return impObj()->columnSpacing();
}

void PyDbMInsertBlock::setColumnSpacing(double val)
{
    return PyThrowBadEs(impObj()->setColumnSpacing(val));
}

double PyDbMInsertBlock::rowSpacing() const
{
    return impObj()->rowSpacing();
}

void PyDbMInsertBlock::setRowSpacing(double val)
{
    return PyThrowBadEs(impObj()->setRowSpacing(val));
}

std::string PyDbMInsertBlock::className()
{
    return "AcDbMInsertBlock";
}

PyRxClass PyDbMInsertBlock::desc()
{
    return PyRxClass(AcDbMInsertBlock::desc(), false);
}

PyDbMInsertBlock PyDbMInsertBlock::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbMInsertBlock::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbMInsertBlock(static_cast<AcDbMInsertBlock*>(src.impObj()->clone()), true);
}

PyDbMInsertBlock PyDbMInsertBlock::cast(const PyRxObject& src)
{
    PyDbMInsertBlock dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbMInsertBlock* PyDbMInsertBlock::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbMInsertBlock*>(m_pyImp.get());
}

//-------------------------------------------------------------------------------------------------------------
//PyDbVertex
void makePyDbVertexWrapper()
{
    PyDocString DS("Vertex");
    class_<PyDbVertex, bases<PyDbEntity>>("Vertex", boost::python::no_init)
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("className", &PyDbVertex::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbVertex::desc, DS.SARGS()).staticmethod("desc")
        .def("cloneFrom", &PyDbVertex::cloneFrom, DS.SARGS({ "otherObject: RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbVertex::cast, DS.SARGS({ "otherObject: RxObject" })).staticmethod("cast")
        ;
}

PyDbVertex::PyDbVertex()
    : PyDbEntity(new AcDbVertex(), true)
{
}

PyDbVertex::PyDbVertex(AcDbVertex* ptr, bool autoDelete)
    : PyDbEntity(ptr, autoDelete)
{
}

PyDbVertex::PyDbVertex(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbEntity(openAcDbObject<AcDbVertex>(id, mode), false)
{
}

PyDbVertex::PyDbVertex(const PyDbObjectId& id)
    : PyDbVertex(id, AcDb::OpenMode::kForRead)
{
}

std::string PyDbVertex::className()
{
    return "AcDbVertex";
}

PyRxClass PyDbVertex::desc()
{
    return PyRxClass(AcDbVertex::desc(), false);
}

PyDbVertex PyDbVertex::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbVertex::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbVertex(static_cast<AcDbVertex*>(src.impObj()->clone()), true);
}

PyDbVertex PyDbVertex::cast(const PyRxObject& src)
{
    PyDbVertex dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbVertex* PyDbVertex::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbVertex*>(m_pyImp.get());
}

//-------------------------------------------------------------------------------------------------------------
//PyDb2dVertex
void makePyDb2dVertexWrapper()
{
    PyDocString DS("Vertex2d");
    class_<PyDb2dVertex, bases<PyDbVertex>>("Vertex2d")
        .def(init<>())
        .def(init<const AcGePoint3d&>())
#if !defined(_BRXTARGET240)
        .def(init<const AcGePoint3d&, double, double, double, double, Adesk::Int32>())
#endif
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("vertexType", &PyDb2dVertex::vertexType, DS.ARGS())
        .def("position", &PyDb2dVertex::position, DS.ARGS())
        .def("setPosition", &PyDb2dVertex::setPosition, DS.ARGS({ "val : PyGe.Point3d" }))
        .def("startWidth", &PyDb2dVertex::startWidth, DS.ARGS())
        .def("setStartWidth", &PyDb2dVertex::setStartWidth, DS.ARGS({ "val : float" }))
        .def("endWidth", &PyDb2dVertex::endWidth, DS.ARGS())
        .def("setEndWidth", &PyDb2dVertex::setEndWidth, DS.ARGS({ "val : float" }))
        .def("bulge", &PyDb2dVertex::bulge, DS.ARGS())
        .def("setBulge", &PyDb2dVertex::setBulge, DS.ARGS({ "val : float" }))
        .def("isTangentUsed", &PyDb2dVertex::isTangentUsed, DS.ARGS())
        .def("useTangent", &PyDb2dVertex::useTangent, DS.ARGS())
        .def("ignoreTangent", &PyDb2dVertex::ignoreTangent, DS.ARGS())
        .def("setTangentUsed", &PyDb2dVertex::setTangentUsed, DS.ARGS({ "val : bool" }))
        .def("tangent", &PyDb2dVertex::tangent, DS.ARGS())
        .def("setTangent", &PyDb2dVertex::setTangent, DS.ARGS({ "val : float" }))
        .def("setVertexIdentifier", &PyDb2dVertex::setVertexIdentifier, DS.ARGS({ "val : int" }))
        .def("vertexIdentifier", &PyDb2dVertex::vertexIdentifier, DS.ARGS())
        .def("className", &PyDb2dVertex::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDb2dVertex::desc, DS.SARGS()).staticmethod("desc")
        .def("cloneFrom", &PyDb2dVertex::cloneFrom, DS.SARGS({ "otherObject: RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDb2dVertex::cast, DS.SARGS({ "otherObject: RxObject" })).staticmethod("cast")
        ;
}

PyDb2dVertex::PyDb2dVertex()
    : PyDb2dVertex(new AcDb2dVertex(), true)
{
}

PyDb2dVertex::PyDb2dVertex(const AcGePoint3d& pos)
    : PyDb2dVertex(new AcDb2dVertex(pos), true)
{
}

#if !defined(_BRXTARGET240)
PyDb2dVertex::PyDb2dVertex(const AcGePoint3d& pos, double bulge, double startWidth, double endWidth, double tangent, Adesk::Int32 vertexIdentifier)
    : PyDb2dVertex(new AcDb2dVertex(pos, bulge, startWidth, endWidth, tangent, vertexIdentifier), true)
{
}
#endif

PyDb2dVertex::PyDb2dVertex(AcDb2dVertex* ptr, bool autoDelete)
    : PyDbVertex(ptr, autoDelete)
{
}

PyDb2dVertex::PyDb2dVertex(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbVertex(openAcDbObject<AcDb2dVertex>(id, mode), false)
{
}

PyDb2dVertex::PyDb2dVertex(const PyDbObjectId& id)
    : PyDb2dVertex(id, AcDb::OpenMode::kForRead)
{
}

AcDb::Vertex2dType PyDb2dVertex::vertexType() const
{
    return impObj()->vertexType();
}

AcGePoint3d PyDb2dVertex::position() const
{
    return impObj()->position();
}

void PyDb2dVertex::setPosition(const AcGePoint3d& val)
{
    return PyThrowBadEs(impObj()->setPosition(val));
}

double PyDb2dVertex::startWidth() const
{
    return impObj()->startWidth();
}

void PyDb2dVertex::setStartWidth(double newVal)
{
    return PyThrowBadEs(impObj()->setStartWidth(newVal));
}

double PyDb2dVertex::endWidth() const
{
    return impObj()->endWidth();
}

void PyDb2dVertex::setEndWidth(double newVal)
{
    return PyThrowBadEs(impObj()->setEndWidth(newVal));
}

double PyDb2dVertex::bulge() const
{
    return impObj()->bulge();
}

void PyDb2dVertex::setBulge(double newVal)
{
    return PyThrowBadEs(impObj()->setBulge(newVal));
}

Adesk::Boolean PyDb2dVertex::isTangentUsed() const
{
    return impObj()->isTangentUsed();
}

void PyDb2dVertex::useTangent()
{
    return PyThrowBadEs(impObj()->useTangent());
}

void PyDb2dVertex::ignoreTangent()
{
    return PyThrowBadEs(impObj()->ignoreTangent());
}

void PyDb2dVertex::setTangentUsed(Adesk::Boolean val)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setTangentUsed(val));
#endif
}

double PyDb2dVertex::tangent() const
{
    return impObj()->tangent();
}

void PyDb2dVertex::setTangent(double newVal)
{
    return PyThrowBadEs(impObj()->setTangent(newVal));
}

void PyDb2dVertex::setVertexIdentifier(Adesk::Int32 suggestedValue)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setVertexIdentifier(suggestedValue));
#endif
}

int PyDb2dVertex::vertexIdentifier() const
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return impObj()->vertexIdentifier();
#endif
}

std::string PyDb2dVertex::className()
{
    return "AcDb2dVertex";
}

PyRxClass PyDb2dVertex::desc()
{
    return PyRxClass(AcDb2dVertex::desc(), false);
}

PyDb2dVertex PyDb2dVertex::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDb2dVertex::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDb2dVertex(static_cast<AcDb2dVertex*>(src.impObj()->clone()), true);
}

PyDb2dVertex PyDb2dVertex::cast(const PyRxObject& src)
{
    PyDb2dVertex dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDb2dVertex* PyDb2dVertex::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDb2dVertex*>(m_pyImp.get());
}

//-------------------------------------------------------------------------------------------------------------
//AcDb3dPolylineVertex
void makePyDb3dPolylineVertexWrapper()
{
    PyDocString DS("Polyline3dVertex");
    class_<PyDb3dPolylineVertex, bases<PyDbVertex>>("Polyline3dVertex")
        .def(init<>())
        .def(init<const AcGePoint3d&>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("vertexType", &PyDb3dPolylineVertex::vertexType, DS.ARGS())
        .def("position", &PyDb3dPolylineVertex::position, DS.ARGS())
        .def("setPosition", &PyDb3dPolylineVertex::setPosition, DS.ARGS({ "val : PyGe.Point3d" }))
        .def("className", &PyDb3dPolylineVertex::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDb3dPolylineVertex::desc, DS.SARGS()).staticmethod("desc")
        .def("cloneFrom", &PyDb3dPolylineVertex::cloneFrom, DS.SARGS({ "otherObject: RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDb3dPolylineVertex::cast, DS.SARGS({ "otherObject: RxObject" })).staticmethod("cast")
        ;
}

PyDb3dPolylineVertex::PyDb3dPolylineVertex()
    : PyDb3dPolylineVertex(new AcDb3dPolylineVertex(), true)
{
}

PyDb3dPolylineVertex::PyDb3dPolylineVertex(const AcGePoint3d& pos)
    : PyDb3dPolylineVertex(new AcDb3dPolylineVertex(pos), true)
{
}

PyDb3dPolylineVertex::PyDb3dPolylineVertex(AcDb3dPolylineVertex* ptr, bool autoDelete)
    : PyDbVertex(ptr, autoDelete)
{
}

PyDb3dPolylineVertex::PyDb3dPolylineVertex(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbVertex(openAcDbObject<AcDb3dPolylineVertex>(id, mode), false)
{
}

PyDb3dPolylineVertex::PyDb3dPolylineVertex(const PyDbObjectId& id)
    : PyDb3dPolylineVertex(id, AcDb::OpenMode::kForRead)
{
}

AcDb::Vertex3dType PyDb3dPolylineVertex::vertexType() const
{
    return impObj()->vertexType();
}

AcGePoint3d PyDb3dPolylineVertex::position() const
{
    return impObj()->position();
}

void PyDb3dPolylineVertex::setPosition(const AcGePoint3d& val)
{
    return PyThrowBadEs(impObj()->setPosition(val));
}

std::string PyDb3dPolylineVertex::className()
{
    return "AcDb3dPolylineVertex";
}

PyRxClass PyDb3dPolylineVertex::desc()
{
    return PyRxClass(AcDb3dPolylineVertex::desc(), false);
}

PyDb3dPolylineVertex PyDb3dPolylineVertex::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbEntity::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDb3dPolylineVertex(static_cast<AcDb3dPolylineVertex*>(src.impObj()->clone()), true);
}

PyDb3dPolylineVertex PyDb3dPolylineVertex::cast(const PyRxObject& src)
{
    PyDb3dPolylineVertex dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDb3dPolylineVertex* PyDb3dPolylineVertex::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDb3dPolylineVertex*>(m_pyImp.get());
}

//-------------------------------------------------------------------------------------------------------------
//AcDbPolygonMeshVertex
void makePyDbPolygonMeshVertexWrapper()
{
    PyDocString DS("PolygonMeshVertex");
    class_<PyDbPolygonMeshVertex, bases<PyDbVertex>>("PolygonMeshVertex")
        .def(init<>())
        .def(init<const AcGePoint3d&>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("vertexType", &PyDbPolygonMeshVertex::vertexType, DS.ARGS())
        .def("position", &PyDbPolygonMeshVertex::position, DS.ARGS())
        .def("setPosition", &PyDbPolygonMeshVertex::setPosition, DS.ARGS({ "val : PyGe.Point3d" }))
        .def("className", &PyDbPolygonMeshVertex::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbPolygonMeshVertex::desc, DS.SARGS()).staticmethod("desc")
        .def("cloneFrom", &PyDbPolygonMeshVertex::cloneFrom, DS.SARGS({ "otherObject: RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbPolygonMeshVertex::cast, DS.SARGS({ "otherObject: RxObject" })).staticmethod("cast")
        ;
}

PyDbPolygonMeshVertex::PyDbPolygonMeshVertex()
    : PyDbPolygonMeshVertex(new AcDbPolygonMeshVertex(), true)
{
}

PyDbPolygonMeshVertex::PyDbPolygonMeshVertex(const AcGePoint3d& pos)
    : PyDbPolygonMeshVertex(new AcDbPolygonMeshVertex(pos), true)
{
}

PyDbPolygonMeshVertex::PyDbPolygonMeshVertex(AcDbPolygonMeshVertex* ptr, bool autoDelete)
    : PyDbVertex(ptr, autoDelete)
{
}

PyDbPolygonMeshVertex::PyDbPolygonMeshVertex(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbVertex(openAcDbObject<AcDbPolygonMeshVertex>(id, mode), false)
{
}

PyDbPolygonMeshVertex::PyDbPolygonMeshVertex(const PyDbObjectId& id)
    : PyDbPolygonMeshVertex(id, AcDb::OpenMode::kForRead)
{
}

AcDb::Vertex3dType PyDbPolygonMeshVertex::vertexType() const
{
    return impObj()->vertexType();
}

AcGePoint3d PyDbPolygonMeshVertex::position() const
{
    return impObj()->position();
}

void PyDbPolygonMeshVertex::setPosition(const AcGePoint3d& val)
{
    return PyThrowBadEs(impObj()->setPosition(val));
}

std::string PyDbPolygonMeshVertex::className()
{
    return "AcDbPolygonMeshVertex";
}

PyRxClass PyDbPolygonMeshVertex::desc()
{
    return PyRxClass(AcDbPolygonMeshVertex::desc(), false);
}

PyDbPolygonMeshVertex PyDbPolygonMeshVertex::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbPolygonMeshVertex::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbPolygonMeshVertex(static_cast<AcDbPolygonMeshVertex*>(src.impObj()->clone()), true);
}

PyDbPolygonMeshVertex PyDbPolygonMeshVertex::cast(const PyRxObject& src)
{
    PyDbPolygonMeshVertex dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbPolygonMeshVertex* PyDbPolygonMeshVertex::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbPolygonMeshVertex*>(m_pyImp.get());
}

//-------------------------------------------------------------------------------------------------------------
//AcDbPolygonMeshVertex
void makePyDbPolyFaceMeshVertexWrapper()
{
    PyDocString DS("PolyFaceMeshVertex");
    class_<PyDbPolyFaceMeshVertex, bases<PyDbVertex>>("PolyFaceMeshVertex")
        .def(init<>())
        .def(init<const AcGePoint3d&>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("position", &PyDbPolyFaceMeshVertex::position, DS.ARGS())
        .def("setPosition", &PyDbPolyFaceMeshVertex::setPosition, DS.ARGS({ "val : PyGe.Point3d" }))
        .def("className", &PyDbPolyFaceMeshVertex::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbPolyFaceMeshVertex::desc, DS.SARGS()).staticmethod("desc")
        .def("cloneFrom", &PyDbPolyFaceMeshVertex::cloneFrom, DS.SARGS({ "otherObject: RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbPolyFaceMeshVertex::cast, DS.SARGS({ "otherObject: RxObject" })).staticmethod("cast")
        ;
}

PyDbPolyFaceMeshVertex::PyDbPolyFaceMeshVertex()
    : PyDbPolyFaceMeshVertex(new AcDbPolyFaceMeshVertex(), true)
{
}

PyDbPolyFaceMeshVertex::PyDbPolyFaceMeshVertex(const AcGePoint3d& pos)
    : PyDbPolyFaceMeshVertex(new AcDbPolyFaceMeshVertex(pos), true)
{
}

PyDbPolyFaceMeshVertex::PyDbPolyFaceMeshVertex(AcDbPolyFaceMeshVertex* ptr, bool autoDelete)
    : PyDbVertex(ptr, autoDelete)
{
}

PyDbPolyFaceMeshVertex::PyDbPolyFaceMeshVertex(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbVertex(openAcDbObject<AcDbPolyFaceMeshVertex>(id, mode), false)
{
}

PyDbPolyFaceMeshVertex::PyDbPolyFaceMeshVertex(const PyDbObjectId& id)
    : PyDbPolyFaceMeshVertex(id, AcDb::OpenMode::kForRead)
{
}

AcGePoint3d PyDbPolyFaceMeshVertex::position() const
{
    return impObj()->position();
}

void PyDbPolyFaceMeshVertex::setPosition(const AcGePoint3d& val)
{
    return PyThrowBadEs(impObj()->setPosition(val));
}

std::string PyDbPolyFaceMeshVertex::className()
{
    return "AcDbPolyFaceMeshVertex";
}

PyRxClass PyDbPolyFaceMeshVertex::desc()
{
    return PyRxClass(AcDbPolyFaceMeshVertex::desc(), false);
}

PyDbPolyFaceMeshVertex PyDbPolyFaceMeshVertex::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbPolyFaceMeshVertex::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbPolyFaceMeshVertex(static_cast<AcDbPolyFaceMeshVertex*>(src.impObj()->clone()), true);
}

PyDbPolyFaceMeshVertex PyDbPolyFaceMeshVertex::cast(const PyRxObject& src)
{
    PyDbPolyFaceMeshVertex dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbPolyFaceMeshVertex* PyDbPolyFaceMeshVertex::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbPolyFaceMeshVertex*>(m_pyImp.get());
}

//-------------------------------------------------------------------------------------------------------------
//AcDbFaceRecord
void makePyDbFaceRecordWrapper()
{
    PyDocString DS("FaceRecord");
    class_<PyDbFaceRecord, bases<PyDbVertex>>("FaceRecord")
        .def(init<>())
        .def(init<Adesk::Int16, Adesk::Int16, Adesk::Int16, Adesk::Int16>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("getVertexAt", &PyDbFaceRecord::getVertexAt, DS.ARGS({ "val : int" }))
        .def("setVertexAt", &PyDbFaceRecord::setVertexAt, DS.ARGS({ "val : int",  "idx : int" }))
        .def("isEdgeVisibleAt", &PyDbFaceRecord::isEdgeVisibleAt, DS.ARGS({ "val : int" }))
        .def("makeEdgeVisibleAt", &PyDbFaceRecord::makeEdgeVisibleAt, DS.ARGS({ "val : int" }))
        .def("makeEdgeInvisibleAt", &PyDbFaceRecord::makeEdgeInvisibleAt, DS.ARGS({ "val : int" }))
        .def("className", &PyDbFaceRecord::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbFaceRecord::desc, DS.SARGS()).staticmethod("desc")
        .def("cloneFrom", &PyDbFaceRecord::cloneFrom, DS.SARGS({ "otherObject: RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbFaceRecord::cast, DS.SARGS({ "otherObject: RxObject" })).staticmethod("cast")
        ;
}

PyDbFaceRecord::PyDbFaceRecord()
    :PyDbFaceRecord(new AcDbFaceRecord(), true)
{
}

PyDbFaceRecord::PyDbFaceRecord(Adesk::Int16 vtx0, Adesk::Int16 vtx1, Adesk::Int16 vtx2, Adesk::Int16 vtx3)
    : PyDbFaceRecord(new AcDbFaceRecord(vtx0, vtx1, vtx2, vtx3), true)
{
}

PyDbFaceRecord::PyDbFaceRecord(AcDbFaceRecord* ptr, bool autoDelete)
    : PyDbVertex(ptr, autoDelete)
{
}

PyDbFaceRecord::PyDbFaceRecord(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbVertex(openAcDbObject<AcDbFaceRecord>(id, mode), false)
{
}

PyDbFaceRecord::PyDbFaceRecord(const PyDbObjectId& id)
    : PyDbFaceRecord(id, AcDb::OpenMode::kForRead)
{
}

Adesk::Int16 PyDbFaceRecord::getVertexAt(Adesk::UInt16 faceIdx) const
{
    Adesk::Int16 vtxIdx = 0;
    PyThrowBadEs(impObj()->getVertexAt(faceIdx, vtxIdx));
    return vtxIdx;
}

void PyDbFaceRecord::setVertexAt(Adesk::UInt16 faceIdx, Adesk::Int16 vtxIdx)
{
    return PyThrowBadEs(impObj()->setVertexAt(faceIdx, vtxIdx));
}

Adesk::Boolean PyDbFaceRecord::isEdgeVisibleAt(Adesk::UInt16 faceIndex) const
{
    Adesk::Boolean flag = false;
    PyThrowBadEs(impObj()->isEdgeVisibleAt(faceIndex, flag));
    return flag;
}

void PyDbFaceRecord::makeEdgeVisibleAt(Adesk::UInt16 faceIndex)
{
    return PyThrowBadEs(impObj()->makeEdgeVisibleAt(faceIndex));
}

void PyDbFaceRecord::makeEdgeInvisibleAt(Adesk::UInt16 faceIndex)
{
    return PyThrowBadEs(impObj()->makeEdgeInvisibleAt(faceIndex));
}

std::string PyDbFaceRecord::className()
{
    return "AcDbFaceRecord";
}

PyRxClass PyDbFaceRecord::desc()
{
    return PyRxClass(AcDbFaceRecord::desc(), false);
}

PyDbFaceRecord PyDbFaceRecord::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbFaceRecord::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbFaceRecord(static_cast<AcDbFaceRecord*>(src.impObj()->clone()), true);
}

PyDbFaceRecord PyDbFaceRecord::cast(const PyRxObject& src)
{
    PyDbFaceRecord dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbFaceRecord* PyDbFaceRecord::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbFaceRecord*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyDbPoint
void makePyDbPointWrapper()
{
    PyDocString DS("Point");
    class_<PyDbPoint, bases<PyDbEntity>>("Point")
        .def(init<>())
        .def(init<AcGePoint3d&>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("position", &PyDbPoint::position, DS.ARGS())
        .def("setPosition", &PyDbPoint::setPosition, DS.ARGS({ "val : PyGe.Point3d" }))
        .def("thickness", &PyDbPoint::thickness, DS.ARGS())
        .def("setThickness", &PyDbPoint::setThickness, DS.ARGS({ "val : float" }))
        .def("normal", &PyDbPoint::normal, DS.ARGS())
        .def("setNormal", &PyDbPoint::setNormal, DS.ARGS({ "val : PyGe.Vector3d" }))
        .def("ecsRotation", &PyDbPoint::ecsRotation, DS.ARGS())
        .def("setEcsRotation", &PyDbPoint::setEcsRotation, DS.ARGS({ "val : float" }))
        .def("className", &PyDbPoint::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbPoint::desc, DS.SARGS()).staticmethod("desc")
        .def("cloneFrom", &PyDbPoint::cloneFrom, DS.SARGS({ "otherObject: RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbPoint::cast, DS.SARGS({ "otherObject: RxObject" })).staticmethod("cast")
        ;
}

PyDbPoint::PyDbPoint()
    : PyDbPoint::PyDbPoint(new AcDbPoint(), true)
{
}

PyDbPoint::PyDbPoint(const AcGePoint3d& point)
    : PyDbPoint::PyDbPoint(new AcDbPoint(point), true)
{
}

PyDbPoint::PyDbPoint(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbPoint::PyDbPoint(openAcDbObject<AcDbPoint>(id, mode), false)
{
}

PyDbPoint::PyDbPoint(const PyDbObjectId& id)
    : PyDbPoint(id, AcDb::OpenMode::kForRead)
{
}

PyDbPoint::PyDbPoint(AcDbPoint* ptr, bool autoDelete)
    : PyDbEntity(ptr, autoDelete)
{
}

AcGePoint3d PyDbPoint::position() const
{
    return impObj()->position();
}

void PyDbPoint::setPosition(const AcGePoint3d& val)
{
    return PyThrowBadEs(impObj()->setPosition(val));
}

double PyDbPoint::thickness() const
{
    return impObj()->thickness();
}

void PyDbPoint::setThickness(double val)
{
    return PyThrowBadEs(impObj()->setThickness(val));
}

AcGeVector3d PyDbPoint::normal() const
{
    return impObj()->normal();
}

void PyDbPoint::setNormal(const AcGeVector3d& val)
{
    return PyThrowBadEs(impObj()->setNormal(val));
}

double PyDbPoint::ecsRotation() const
{
    return impObj()->ecsRotation();
}

void PyDbPoint::setEcsRotation(double val)
{
    return PyThrowBadEs(impObj()->setEcsRotation(val));
}

std::string PyDbPoint::className()
{
    return "AcDbPoint";
}

PyRxClass PyDbPoint::desc()
{
    return PyRxClass(AcDbPoint::desc(), false);
}

PyDbPoint PyDbPoint::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbPoint::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbPoint(static_cast<AcDbPoint*>(src.impObj()->clone()), true);
}

PyDbPoint PyDbPoint::cast(const PyRxObject& src)
{
    PyDbPoint dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbPoint* PyDbPoint::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbPoint*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyDb2dPolyline
AcGePoint3dArray& listToAcGePoint3dArrayRef(const boost::python::list& list)
{
    PyAutoLockGIL lock;
    //TODO: maybe this can be done better
    auto vec = py_list_to_std_vector<AcGePoint3d>(list);
    static AcGePoint3dArray arr;
    arr.removeAll();
    for (const AcGePoint3d& pnt : vec)
        arr.append(pnt);
    return arr;
}

void makePyDb2dPolylineWrapper()
{
    PyDocString DS("Polyline2d");
    class_<PyDb2dPolyline, bases<PyDbCurve>>("Polyline2d")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<AcDb::Poly2dType, const boost::python::list&, Adesk::Boolean>())
        .def("polyType", &PyDb2dPolyline::polyType)
        .def("setPolyType", &PyDb2dPolyline::setPolyType)
        .def("convertToPolyType", &PyDb2dPolyline::convertToPolyType)
        .def("makeClosed", &PyDb2dPolyline::makeClosed)
        .def("makeOpen", &PyDb2dPolyline::makeOpen)
        .def("setClosed", &PyDb2dPolyline::setClosed)
        .def("constantWidth", &PyDb2dPolyline::constantWidth)
        .def("setConstantWidth", &PyDb2dPolyline::setConstantWidth)
        .def("length", &PyDb2dPolyline::length)
        .def("defaultStartWidth", &PyDb2dPolyline::defaultStartWidth)
        .def("setDefaultStartWidth", &PyDb2dPolyline::setDefaultStartWidth)
        .def("defaultEndWidth", &PyDb2dPolyline::defaultEndWidth)
        .def("setDefaultEndWidth", &PyDb2dPolyline::setDefaultEndWidth)
        .def("thickness", &PyDb2dPolyline::thickness)
        .def("setThickness", &PyDb2dPolyline::setThickness)
        .def("normal", &PyDb2dPolyline::normal)
        .def("setNormal", &PyDb2dPolyline::setNormal)
        .def("elevation", &PyDb2dPolyline::elevation)
        .def("setElevation", &PyDb2dPolyline::setElevation)
        .def("isLinetypeGenerationOn", &PyDb2dPolyline::isLinetypeGenerationOn)
        .def("setLinetypeGenerationOn", &PyDb2dPolyline::setLinetypeGenerationOn)
        .def("setLinetypeGenerationOff", &PyDb2dPolyline::setLinetypeGenerationOff)
        .def("straighten", &PyDb2dPolyline::straighten)
        .def<void(PyDb2dPolyline::*)(void)>("splineFit", &PyDb2dPolyline::splineFit)
        .def<void(PyDb2dPolyline::*)(AcDb::Poly2dType, Adesk::Int16)>("splineFit", &PyDb2dPolyline::splineFit)
        .def<void(PyDb2dPolyline::*)(const PyDb2dVertex&)>("appendVertex", &PyDb2dPolyline::appendVertex)
        .def<void(PyDb2dPolyline::*)(PyDbObjectId&, const PyDb2dVertex&)>("appendVertex", &PyDb2dPolyline::appendVertex)
        .def<void(PyDb2dPolyline::*)(const PyDb2dVertex&, PyDb2dVertex&)>("insertVertexAt", &PyDb2dPolyline::insertVertexAt)
        .def<void(PyDb2dPolyline::*)(PyDbObjectId&, const PyDbObjectId&, PyDb2dVertex&)>("insertVertexAt", &PyDb2dPolyline::insertVertexAt)
        .def("openVertex", &PyDb2dPolyline::openVertex)
        .def("openSequenceEnd", &PyDb2dPolyline::openSequenceEnd)
        .def("vertexIds", &PyDb2dPolyline::vertexIds)
        .def("vertexPosition", &PyDb2dPolyline::vertexPosition)
        .def("makeClosedIfStartAndEndVertexCoincide", &PyDb2dPolyline::makeClosedIfStartAndEndVertexCoincide)
        .def("className", &PyDb2dPolyline::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDb2dPolyline::desc, DS.SARGS()).staticmethod("desc")
        .def("cloneFrom", &PyDb2dPolyline::cloneFrom, DS.SARGS({ "otherObject: RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDb2dPolyline::cast, DS.SARGS({ "otherObject: RxObject" })).staticmethod("cast")
        ;
}

PyDb2dPolyline::PyDb2dPolyline()
    : PyDbCurve(new AcDb2dPolyline(), true)
{
}

PyDb2dPolyline::PyDb2dPolyline(AcDb2dPolyline* ptr, bool autoDelete)
    : PyDbCurve(ptr, autoDelete)
{
}

PyDb2dPolyline::PyDb2dPolyline(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbCurve(openAcDbObject<AcDb2dPolyline>(id, mode), false)
{
}

PyDb2dPolyline::PyDb2dPolyline(AcDb::Poly2dType type, const boost::python::list& vertices, Adesk::Boolean closed)
    : PyDbCurve(new AcDb2dPolyline(type, listToAcGePoint3dArrayRef(vertices), 0.0, closed), true)
{
}

PyDb2dPolyline::PyDb2dPolyline(const PyDbObjectId& id)
    : PyDb2dPolyline(id, AcDb::OpenMode::kForRead)
{
}

AcDb::Poly2dType PyDb2dPolyline::polyType() const
{
    return impObj()->polyType();
}

void PyDb2dPolyline::setPolyType(AcDb::Poly2dType val)
{
    return PyThrowBadEs(impObj()->setPolyType(val));
}

void PyDb2dPolyline::convertToPolyType(AcDb::Poly2dType val)
{
    return PyThrowBadEs(impObj()->convertToPolyType(val));
}

void PyDb2dPolyline::makeClosed()
{
    return PyThrowBadEs(impObj()->makeClosed());
}

void PyDb2dPolyline::makeOpen()
{
    return PyThrowBadEs(impObj()->makeOpen());
}

void PyDb2dPolyline::setClosed(Adesk::Boolean val)
{
    return PyThrowBadEs(impObj()->setClosed(val));
}

double PyDb2dPolyline::constantWidth() const
{
    double val;
    PyThrowBadEs(impObj()->constantWidth(val));
    return val;
}

void PyDb2dPolyline::setConstantWidth(double val)
{
    return PyThrowBadEs(impObj()->setConstantWidth(val));
}

double PyDb2dPolyline::length() const
{
    double val;
    PyThrowBadEs(impObj()->length(val));
    return val;
}

double PyDb2dPolyline::defaultStartWidth() const
{
    return impObj()->defaultStartWidth();
}

void PyDb2dPolyline::setDefaultStartWidth(double val)
{
    return PyThrowBadEs(impObj()->setDefaultStartWidth(val));
}

double PyDb2dPolyline::defaultEndWidth() const
{
    return impObj()->defaultEndWidth();
}

void PyDb2dPolyline::setDefaultEndWidth(double val)
{
    return PyThrowBadEs(impObj()->setDefaultEndWidth(val));
}

double PyDb2dPolyline::thickness() const
{
    return impObj()->thickness();
}

void PyDb2dPolyline::setThickness(double val)
{
    return PyThrowBadEs(impObj()->setThickness(val));
}

AcGeVector3d PyDb2dPolyline::normal() const
{
    return impObj()->normal();
}

void PyDb2dPolyline::setNormal(const AcGeVector3d& val)
{
    return PyThrowBadEs(impObj()->setNormal(val));
}

double PyDb2dPolyline::elevation() const
{
    return impObj()->elevation();
}

void PyDb2dPolyline::setElevation(double val)
{
    return PyThrowBadEs(impObj()->setElevation(val));
}

Adesk::Boolean PyDb2dPolyline::isLinetypeGenerationOn() const
{
    return impObj()->isLinetypeGenerationOn();
}

void PyDb2dPolyline::setLinetypeGenerationOn()
{
    return PyThrowBadEs(impObj()->setLinetypeGenerationOn());
}

void PyDb2dPolyline::setLinetypeGenerationOff()
{
    return PyThrowBadEs(impObj()->setLinetypeGenerationOff());
}

void PyDb2dPolyline::straighten()
{
    return PyThrowBadEs(impObj()->straighten());
}

void PyDb2dPolyline::splineFit()
{
    return PyThrowBadEs(impObj()->splineFit());
}

void PyDb2dPolyline::splineFit(AcDb::Poly2dType splineType, Adesk::Int16 splineSegs)
{
    return PyThrowBadEs(impObj()->splineFit(splineType, splineSegs));
}

void PyDb2dPolyline::appendVertex(const PyDb2dVertex& vt)
{
    return PyThrowBadEs(impObj()->appendVertex(vt.impObj()));
}

void PyDb2dPolyline::appendVertex(PyDbObjectId& id, const PyDb2dVertex& vt)
{
    return PyThrowBadEs(impObj()->appendVertex(id.m_id, vt.impObj()));
}

void PyDb2dPolyline::insertVertexAt(const PyDb2dVertex& pIndexVert, PyDb2dVertex& pNewVertex)
{
    return PyThrowBadEs(impObj()->insertVertexAt(pIndexVert.impObj(), pNewVertex.impObj()));
}

void PyDb2dPolyline::insertVertexAt(PyDbObjectId& newVertId, const PyDbObjectId& indexVertId, PyDb2dVertex& pNewVertex)
{
    return PyThrowBadEs(impObj()->insertVertexAt(newVertId.m_id, indexVertId.m_id, pNewVertex.impObj()));
}

void PyDb2dPolyline::openVertex(PyDb2dVertex& vt, const PyDbObjectId& vertId, AcDb::OpenMode mode) const
{
    vt = PyDb2dVertex(vertId, mode);
}

void PyDb2dPolyline::openSequenceEnd(PyDbSequenceEnd& end, AcDb::OpenMode mode)
{
    AcDbSequenceEnd* pEnd = nullptr;
    PyThrowBadEs(impObj()->openSequenceEnd(pEnd, mode));
    end = PyDbSequenceEnd(pEnd, true);
}

boost::python::list PyDb2dPolyline::vertexIds() const
{
    PyAutoLockGIL lock;
    boost::python::list ids;
    for (std::unique_ptr<AcDbObjectIterator> iter(impObj()->vertexIterator()); !iter->done(); iter->step())
        ids.append(iter->objectId());
    return ids;
}

AcGePoint3d PyDb2dPolyline::vertexPosition(const AcDb2dVertex& vert) const
{
    return impObj()->vertexPosition(vert);
}

void PyDb2dPolyline::makeClosedIfStartAndEndVertexCoincide(double distTol)
{
#if defined(_GRXTARGET240) || (_BRXTARGET == 240)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->makeClosedIfStartAndEndVertexCoincide(distTol));
#endif
}

std::string PyDb2dPolyline::className()
{
    return "AcDb2dPolyline";
}

PyRxClass PyDb2dPolyline::desc()
{
    return PyRxClass(AcDb2dPolyline::desc(), false);
}

PyDb2dPolyline PyDb2dPolyline::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbEntity::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDb2dPolyline(static_cast<AcDb2dPolyline*>(src.impObj()->clone()), true);
}

PyDb2dPolyline PyDb2dPolyline::cast(const PyRxObject& src)
{
    PyDb2dPolyline dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDb2dPolyline* PyDb2dPolyline::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDb2dPolyline*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyDb3dPolyline
void makePyDb3dPolylineWrapper()
{
    PyDocString DS("Polyline3d");
    class_<PyDb3dPolyline, bases<PyDbCurve>>("Polyline3d")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<AcDb::Poly3dType, const boost::python::list&, Adesk::Boolean>())
        .def("length", &PyDb3dPolyline::length)
        .def("setClosed", &PyDb3dPolyline::setClosed)
        .def("makeClosed", &PyDb3dPolyline::makeClosed)
        .def("makeOpen", &PyDb3dPolyline::makeOpen)
        .def("polyType", &PyDb3dPolyline::polyType)
        .def("setPolyType", &PyDb3dPolyline::setPolyType)
        .def("convertToPolyType", &PyDb3dPolyline::convertToPolyType)
        .def("straighten", &PyDb3dPolyline::straighten)
        .def<void(PyDb3dPolyline::*)(void)>("splineFit", &PyDb3dPolyline::splineFit)
        .def<void(PyDb3dPolyline::*)(AcDb::Poly3dType, Adesk::Int16)>("splineFit", &PyDb3dPolyline::splineFit)
        .def<void(PyDb3dPolyline::*)(const PyDb3dPolylineVertex&)>("appendVertex", &PyDb3dPolyline::appendVertex)
        .def<void(PyDb3dPolyline::*)(PyDbObjectId&, const PyDb3dPolylineVertex&)>("appendVertex", &PyDb3dPolyline::appendVertex)
        .def<void(PyDb3dPolyline::*)(const PyDb3dPolylineVertex&, PyDb3dPolylineVertex&)>("insertVertexAt", &PyDb3dPolyline::insertVertexAt)
        .def<void(PyDb3dPolyline::*)(PyDbObjectId&, const PyDbObjectId&, PyDb3dPolylineVertex&)>("insertVertexAt", &PyDb3dPolyline::insertVertexAt)
        .def("openVertex", &PyDb3dPolyline::openVertex)
        .def("openSequenceEnd", &PyDb3dPolyline::openSequenceEnd)
        .def("vertexIds", &PyDb3dPolyline::vertexIds)
        .def("className", &PyDb3dPolyline::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDb3dPolyline::desc, DS.SARGS()).staticmethod("desc")
        .def("cloneFrom", &PyDb3dPolyline::cloneFrom, DS.SARGS({ "otherObject: RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDb3dPolyline::cast, DS.SARGS({ "otherObject: RxObject" })).staticmethod("cast")
        ;
}

PyDb3dPolyline::PyDb3dPolyline()
    : PyDbCurve(new AcDb3dPolyline(), true)
{
}

PyDb3dPolyline::PyDb3dPolyline(AcDb3dPolyline* ptr, bool autoDelete)
    : PyDbCurve(ptr, true)
{
}

PyDb3dPolyline::PyDb3dPolyline(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbCurve(openAcDbObject<AcDb3dPolyline>(id, mode), false)
{
}

PyDb3dPolyline::PyDb3dPolyline(AcDb::Poly3dType pt, const boost::python::list& vertices, Adesk::Boolean closed)
    : PyDbCurve(new AcDb3dPolyline(pt, listToAcGePoint3dArrayRef(vertices), closed), true)
{
}

PyDb3dPolyline::PyDb3dPolyline(const PyDbObjectId& id)
    : PyDb3dPolyline(id, AcDb::OpenMode::kForNotify)
{
}

double PyDb3dPolyline::length() const
{
    double val;
    PyThrowBadEs(impObj()->length(val));
    return val;
}

void PyDb3dPolyline::setClosed(Adesk::Boolean val)
{
    return PyThrowBadEs(impObj()->setClosed(val));
}

void PyDb3dPolyline::makeClosed()
{
    return PyThrowBadEs(impObj()->makeClosed());
}

void PyDb3dPolyline::makeOpen()
{
    return PyThrowBadEs(impObj()->makeOpen());
}

AcDb::Poly3dType PyDb3dPolyline::polyType() const
{
    return impObj()->polyType();
}

void PyDb3dPolyline::setPolyType(AcDb::Poly3dType val)
{
    return PyThrowBadEs(impObj()->setPolyType(val));
}

void PyDb3dPolyline::convertToPolyType(AcDb::Poly3dType val)
{
    return PyThrowBadEs(impObj()->convertToPolyType(val));
}

void PyDb3dPolyline::straighten()
{
    return PyThrowBadEs(impObj()->straighten());
}

void PyDb3dPolyline::splineFit()
{
    return PyThrowBadEs(impObj()->splineFit());
}

void PyDb3dPolyline::splineFit(AcDb::Poly3dType splineType, Adesk::Int16 splineSegs)
{
    return PyThrowBadEs(impObj()->splineFit(splineType, splineSegs));
}

void PyDb3dPolyline::appendVertex(const PyDb3dPolylineVertex& vt)
{
    return PyThrowBadEs(impObj()->appendVertex(vt.impObj()));
}

void PyDb3dPolyline::appendVertex(PyDbObjectId& id, const PyDb3dPolylineVertex& vt)
{
    return PyThrowBadEs(impObj()->appendVertex(id.m_id, vt.impObj()));
}

void PyDb3dPolyline::insertVertexAt(const PyDb3dPolylineVertex& pIndexVert, PyDb3dPolylineVertex& pNewVertex)
{
    return PyThrowBadEs(impObj()->insertVertexAt(pIndexVert.impObj(), pNewVertex.impObj()));
}

void PyDb3dPolyline::insertVertexAt(PyDbObjectId& newVertId, const PyDbObjectId& indexVertId, PyDb3dPolylineVertex& pNewVertex)
{
    return PyThrowBadEs(impObj()->insertVertexAt(newVertId.m_id, indexVertId.m_id, pNewVertex.impObj()));
}

void PyDb3dPolyline::openVertex(PyDb3dPolylineVertex& vt, const PyDbObjectId& vertId, AcDb::OpenMode mode) const
{
    vt = PyDb3dPolylineVertex(vertId, mode);
}

void PyDb3dPolyline::openSequenceEnd(PyDbSequenceEnd& end, AcDb::OpenMode mode)
{
    AcDbSequenceEnd* pEnd = nullptr;
    PyThrowBadEs(impObj()->openSequenceEnd(pEnd, mode));
    end = PyDbSequenceEnd(pEnd, true);
}

boost::python::list PyDb3dPolyline::vertexIds() const
{
    PyAutoLockGIL lock;
    boost::python::list ids;
    for (std::unique_ptr<AcDbObjectIterator> iter(impObj()->vertexIterator()); !iter->done(); iter->step())
        ids.append(iter->objectId());
    return ids;
}

std::string PyDb3dPolyline::className()
{
    return "AcDb3dPolyline";
}

PyRxClass PyDb3dPolyline::desc()
{
    return PyRxClass(AcDb3dPolyline::desc(), false);
}

PyDb3dPolyline PyDb3dPolyline::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDb3dPolyline::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDb3dPolyline(static_cast<AcDb3dPolyline*>(src.impObj()->clone()), true);
}

PyDb3dPolyline PyDb3dPolyline::cast(const PyRxObject& src)
{
    PyDb3dPolyline dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDb3dPolyline* PyDb3dPolyline::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDb3dPolyline*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyDbArc
void makePyDbArcWrapper()
{
    PyDocString DS("Arc");
    class_<PyDbArc, bases<PyDbCurve>>("Arc")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const AcGePoint3d&, double, double, double>())
        .def(init<const AcGePoint3d&, const AcGeVector3d&, double, double, double>())
        .def("center", &PyDbArc::center, DS.ARGS())
        .def("setCenter", &PyDbArc::setCenter, DS.ARGS({ "val:PyGe.Point3d" }))
        .def("radius", &PyDbArc::radius, DS.ARGS())
        .def("setRadius", &PyDbArc::setRadius, DS.ARGS({ "val:float" }))
        .def("startAngle", &PyDbArc::startAngle, DS.ARGS())
        .def("setStartAngle", &PyDbArc::setStartAngle, DS.ARGS({ "val:float" }))
        .def("endAngle", &PyDbArc::endAngle, DS.ARGS())
        .def("setEndAngle", &PyDbArc::setEndAngle, DS.ARGS({ "val:float" }))
        .def("totalAngle", &PyDbArc::totalAngle, DS.ARGS())
        .def("length", &PyDbArc::length, DS.ARGS())
        .def("thickness", &PyDbArc::thickness, DS.ARGS())
        .def("setThickness", &PyDbArc::setThickness, DS.ARGS({ "val:float" }))
        .def("normal", &PyDbArc::normal, DS.ARGS())
        .def("setNormal", &PyDbArc::setNormal, DS.ARGS({ "val:PyGe.Vector3d" }))
        .def("getAcGeCurve", &PyDbArc::getAcGeCurve1)
        .def("getAcGeCurve", &PyDbArc::getAcGeCurve2, DS.ARGS({ "tol: Tol = default" }))
        .def("className", &PyDbArc::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbArc::desc, DS.SARGS()).staticmethod("desc")
        .def("cloneFrom", &PyDbArc::cloneFrom, DS.SARGS({ "otherObject: RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbArc::cast, DS.SARGS({ "otherObject: RxObject" })).staticmethod("cast")
        ;
}

PyDbArc::PyDbArc()
    : PyDbCurve(new AcDbArc(), true)
{
}

PyDbArc::PyDbArc(AcDbArc* ptr, bool autoDelete)
    : PyDbCurve(ptr, autoDelete)
{
}

PyDbArc::PyDbArc(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbCurve(openAcDbObject<AcDbArc>(id, mode), false)
{
}

PyDbArc::PyDbArc(const AcGePoint3d& center, double radius, double startAngle, double endAngle)
    : PyDbCurve(new AcDbArc(center, radius, startAngle, endAngle), true)
{
}

PyDbArc::PyDbArc(const AcGePoint3d& center, const AcGeVector3d& normal, double radius, double startAngle, double endAngle)
    : PyDbCurve(new AcDbArc(center, normal, radius, startAngle, endAngle), true)
{
}

PyDbArc::PyDbArc(const PyDbObjectId& id)
    : PyDbArc(id, AcDb::OpenMode::kForRead)
{
}

AcGePoint3d PyDbArc::center() const
{
    return impObj()->center();
}

void PyDbArc::setCenter(const AcGePoint3d& val)
{
    return PyThrowBadEs(impObj()->setCenter(val));
}

double PyDbArc::radius() const
{
    return impObj()->radius();
}

void PyDbArc::setRadius(double val)
{
    return PyThrowBadEs(impObj()->setRadius(val));
}

double PyDbArc::startAngle() const
{
    return impObj()->startAngle();
}

void PyDbArc::setStartAngle(double val)
{
    return PyThrowBadEs(impObj()->setStartAngle(val));
}

double PyDbArc::endAngle() const
{
    return impObj()->endAngle();
}

void PyDbArc::setEndAngle(double val)
{
    return PyThrowBadEs(impObj()->setEndAngle(val));
}

double PyDbArc::totalAngle() const
{
    return impObj()->totalAngle();
}

double PyDbArc::length() const
{
    return impObj()->length();
}

double PyDbArc::thickness() const
{
    return impObj()->thickness();
}

void PyDbArc::setThickness(double val)
{
    return PyThrowBadEs(impObj()->setThickness(val));
}

AcGeVector3d PyDbArc::normal() const
{
    return impObj()->normal();
}

void PyDbArc::setNormal(const AcGeVector3d& val)
{
    return PyThrowBadEs(impObj()->setNormal(val));
}

PyGeCircArc3d PyDbArc::getAcGeCurve1() const
{
    AcGeCurve3d* pGeCurve = nullptr;
    PyThrowBadEs(impObj()->getAcGeCurve(pGeCurve));
    return PyGeCircArc3d(pGeCurve);
}

PyGeCircArc3d PyDbArc::getAcGeCurve2(const AcGeTol& tol) const
{
    AcGeCurve3d* pGeCurve = nullptr;
    PyThrowBadEs(impObj()->getAcGeCurve(pGeCurve, tol));
    return PyGeCircArc3d(pGeCurve);
}

std::string PyDbArc::className()
{
    return "AcDbArc";
}

PyRxClass PyDbArc::desc()
{
    return PyRxClass(AcDbArc::desc(), false);
}

PyDbArc PyDbArc::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbArc::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbArc(static_cast<AcDbArc*>(src.impObj()->clone()), true);
}

PyDbArc PyDbArc::cast(const PyRxObject& src)
{
    PyDbArc dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbArc* PyDbArc::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbArc*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyDbCircle
void makePyDbCircleWrapper()
{
    PyDocString DS("Circle");
    class_<PyDbCircle, bases<PyDbCurve>>("Circle")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const AcGePoint3d&, const AcGeVector3d&, double>())
        .def("center", &PyDbCircle::center, DS.ARGS())
        .def("setCenter", &PyDbCircle::setCenter, DS.ARGS({ "val:PyGe.Point3d" }))
        .def("radius", &PyDbCircle::radius, DS.ARGS())
        .def("setRadius", &PyDbCircle::setRadius, DS.ARGS({ "val:float" }))
        .def("thickness", &PyDbCircle::thickness, DS.ARGS())
        .def("setThickness", &PyDbCircle::setThickness, DS.ARGS({ "val:float" }))
        .def("normal", &PyDbCircle::normal, DS.ARGS())
        .def("setNormal", &PyDbCircle::setNormal, DS.ARGS({ "val:PyGe.Vector3d" }))
        .def("circumference", &PyDbCircle::circumference, DS.ARGS())
        .def("setCircumference", &PyDbCircle::setCircumference, DS.ARGS({ "val:float" }))
        .def("diameter", &PyDbCircle::diameter, DS.ARGS())
        .def("setDiameter", &PyDbCircle::setDiameter, DS.ARGS({ "val:float" }))
        .def("getAcGeCurve", &PyDbCircle::getAcGeCurve1)
        .def("getAcGeCurve", &PyDbCircle::getAcGeCurve2, DS.ARGS({ "tol: Tol = default" }))
        .def("className", &PyDbCircle::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbCircle::desc, DS.SARGS()).staticmethod("desc")
        .def("cloneFrom", &PyDbCircle::cloneFrom, DS.SARGS({ "otherObject: RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbCircle::cast, DS.SARGS({ "otherObject: RxObject" })).staticmethod("cast")
        ;
}

PyDbCircle::PyDbCircle()
    : PyDbCurve(new AcDbCircle(), true)
{
}

PyDbCircle::PyDbCircle(AcDbCircle* ptr, bool autoDelete)
    : PyDbCurve(ptr, autoDelete)
{
}

PyDbCircle::PyDbCircle(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbCurve(openAcDbObject<AcDbCircle>(id, mode), false)
{
}

PyDbCircle::PyDbCircle(const AcGePoint3d& cntr, const AcGeVector3d& nrm, double radius)
    : PyDbCurve(new AcDbCircle(cntr, nrm, radius), true)
{
}

PyDbCircle::PyDbCircle(const PyDbObjectId& id)
    : PyDbCircle(id, AcDb::OpenMode::kForRead)
{
}

AcGePoint3d PyDbCircle::center() const
{
    return impObj()->center();
}

void PyDbCircle::setCenter(const AcGePoint3d& val)
{
    return PyThrowBadEs(impObj()->setCenter(val));
}

double PyDbCircle::radius() const
{
    return impObj()->radius();
}

void PyDbCircle::setRadius(double val)
{
    return PyThrowBadEs(impObj()->setRadius(val));
}

double PyDbCircle::thickness() const
{
    return impObj()->thickness();
}

void PyDbCircle::setThickness(double val)
{
    return PyThrowBadEs(impObj()->setThickness(val));
}

AcGeVector3d PyDbCircle::normal() const
{
    return impObj()->normal();
}

void PyDbCircle::setNormal(const AcGeVector3d& val)
{
    return PyThrowBadEs(impObj()->setNormal(val));
}

double PyDbCircle::circumference() const
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return impObj()->circumference();
#endif
}

void PyDbCircle::setCircumference(double val)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setCircumference(val));
#endif
}

double PyDbCircle::diameter() const
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return impObj()->diameter();
#endif
}

void PyDbCircle::setDiameter(double val)
{
#if defined(_BRXTARGET) && _BRXTARGET <= 240
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->setDiameter(val));
#endif
}

PyGeCircArc3d PyDbCircle::getAcGeCurve1() const
{
    AcGeCurve3d* pGeCurve = nullptr;
    PyThrowBadEs(impObj()->getAcGeCurve(pGeCurve));
    return PyGeCircArc3d(pGeCurve);
}

PyGeCircArc3d PyDbCircle::getAcGeCurve2(const AcGeTol& tol) const
{
    AcGeCurve3d* pGeCurve = nullptr;
    PyThrowBadEs(impObj()->getAcGeCurve(pGeCurve, tol));
    return PyGeCircArc3d(pGeCurve);
}

std::string PyDbCircle::className()
{
    return "AcDbCircle";
}

PyRxClass PyDbCircle::desc()
{
    return PyRxClass(AcDbCircle::desc(), false);
}

PyDbCircle PyDbCircle::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbCircle::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbCircle(static_cast<AcDbCircle*>(src.impObj()->clone()), true);
}

PyDbCircle PyDbCircle::cast(const PyRxObject& src)
{
    PyDbCircle dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbCircle* PyDbCircle::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbCircle*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyDbLine
void makePyDbLineWrapper()
{
    PyDocString DS("Line");
    class_<PyDbLine, bases<PyDbCurve>>("Line")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const AcGePoint3d&, const AcGePoint3d&>())
        .def("startPoint", &PyDbLine::startPoint, DS.ARGS())
        .def("setStartPoint", &PyDbLine::setStartPoint, DS.ARGS({ "val:PyGe.Point3d" }))
        .def("endPoint", &PyDbLine::endPoint, DS.ARGS())
        .def("setEndPoint", &PyDbLine::setEndPoint, DS.ARGS({ "val:PyGe.Point3d" }))
        .def("thickness", &PyDbLine::thickness, DS.ARGS())
        .def("setThickness", &PyDbLine::setThickness, DS.ARGS({ "val:float" }))
        .def("normal", &PyDbLine::normal, DS.ARGS())
        .def("setNormal", &PyDbLine::setNormal, DS.ARGS({ "val:PyGe.Vector3d" }))
        .def("getOffsetCurvesGivenPlaneNormal", &PyDbLine::getOffsetCurvesGivenPlaneNormal, DS.ARGS({ "val:PyGe.Vector3d","offset:float" }))
        .def("getAcGeCurve", &PyDbLine::getAcGeCurve1)
        .def("getAcGeCurve", &PyDbLine::getAcGeCurve2, DS.ARGS({ "tol: Tol = default" }))
        .def("className", &PyDbLine::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbLine::desc, DS.SARGS()).staticmethod("desc")
        .def("cloneFrom", &PyDbLine::cloneFrom, DS.SARGS({ "otherObject: RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbLine::cast, DS.SARGS({ "otherObject: RxObject" })).staticmethod("cast")
        ;
}

PyDbLine::PyDbLine()
    : PyDbCurve(new AcDbLine(), true)
{
}

PyDbLine::PyDbLine(AcDbLine* ptr, bool autoDelete)
    : PyDbCurve(ptr, autoDelete)
{
}

PyDbLine::PyDbLine(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbCurve(openAcDbObject<AcDbLine>(id, mode), false)
{
}

PyDbLine::PyDbLine(const AcGePoint3d& start, const AcGePoint3d& end)
    : PyDbCurve(new AcDbLine(start, end), true)
{
}

PyDbLine::PyDbLine(const PyDbObjectId& id)
    : PyDbLine(id, AcDb::OpenMode::kForRead)
{
}

AcGePoint3d PyDbLine::startPoint() const
{
    return impObj()->startPoint();
}

void PyDbLine::setStartPoint(const AcGePoint3d& val)
{
    return PyThrowBadEs(impObj()->setStartPoint(val));
}

AcGePoint3d PyDbLine::endPoint() const
{
    return impObj()->endPoint();
}

void PyDbLine::setEndPoint(const AcGePoint3d& val)
{
    return PyThrowBadEs(impObj()->setEndPoint(val));
}

double PyDbLine::thickness() const
{
    return impObj()->thickness();
}

void PyDbLine::setThickness(double val)
{
    return PyThrowBadEs(impObj()->setThickness(val));
}

AcGeVector3d PyDbLine::normal() const
{
    return impObj()->normal();
}

void PyDbLine::setNormal(const AcGeVector3d& val)
{
    return PyThrowBadEs(impObj()->setNormal(val));
}

PyGeLineSeg3d PyDbLine::getAcGeCurve1() const
{
    AcGeCurve3d* pGeCurve = nullptr;
    PyThrowBadEs(impObj()->getAcGeCurve(pGeCurve));
    return PyGeLineSeg3d(pGeCurve);
}

PyGeLineSeg3d PyDbLine::getAcGeCurve2(const AcGeTol& tol) const
{
    AcGeCurve3d* pGeCurve = nullptr;
    PyThrowBadEs(impObj()->getAcGeCurve(pGeCurve, tol));
    return PyGeLineSeg3d(pGeCurve);
}

std::string PyDbLine::className()
{
    return "AcDbLine";
}

PyRxClass PyDbLine::desc()
{
    return PyRxClass(AcDbLine::desc(), false);
}

PyDbLine PyDbLine::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbLine::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbLine(static_cast<AcDbLine*>(src.impObj()->clone()), true);
}

PyDbLine PyDbLine::cast(const PyRxObject& src)
{
    PyDbLine dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbLine* PyDbLine::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbLine*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyDbPolyline
void makePyDbPolylineWrapper()
{
    PyDocString DS("Polyline");
    class_<PyDbPolyline, bases<PyDbCurve>>("Polyline")
        .def(init<>())
        .def(init<unsigned int>())
        .def(init<const boost::python::list&>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("getPoint3dAt", &PyDbPolyline::getPoint3dAt, DS.ARGS({ "idx:int" }))
        .def("getPoint2dAt", &PyDbPolyline::getPoint2dAt, DS.ARGS({ "idx:int" }))
        .def("segType", &PyDbPolyline::segType, DS.ARGS({ "idx:int" }))
        .def("onSegAt", &PyDbPolyline::onSegAt, DS.ARGS({ "idx:int","pt2d:PyGe.Point2d","param:float" }))
        .def("getLineSeg2dAt", &PyDbPolyline::getLineSeg2dAt, DS.ARGS({ "idx:int" }))
        .def("getLineSeg3dAt", &PyDbPolyline::getLineSeg3dAt, DS.ARGS({ "idx:int" }))
        .def("getArcSeg2dAt", &PyDbPolyline::getArcSeg2dAt, DS.ARGS({ "idx:int" }))
        .def("getArcSeg3dAt", &PyDbPolyline::getArcSeg3dAt, DS.ARGS({ "idx:int" }))
        .def("setClosed", &PyDbPolyline::setClosed, DS.ARGS({ "val:bool" }))
        .def("setPlinegen", &PyDbPolyline::setPlinegen, DS.ARGS({ "val:bool" }))
        .def("setElevation", &PyDbPolyline::setElevation, DS.ARGS({ "elev:float" }))
        .def("setThickness", &PyDbPolyline::setThickness, DS.ARGS({ "val:float" }))
        .def("setConstantWidth", &PyDbPolyline::setConstantWidth, DS.ARGS({ "width:float" }))
        .def("setNormal", &PyDbPolyline::setNormal, DS.ARGS({ "val:PyGe.Vector3d" }))
        .def("isOnlyLines", &PyDbPolyline::isOnlyLines, DS.ARGS())
        .def("hasPlinegen", &PyDbPolyline::hasPlinegen, DS.ARGS())
        .def("elevation", &PyDbPolyline::elevation, DS.ARGS())
        .def("thickness", &PyDbPolyline::thickness, DS.ARGS())
        .def("getConstantWidth", &PyDbPolyline::getConstantWidth, DS.ARGS())
        .def("normal", &PyDbPolyline::normal, DS.ARGS())
        .def("addVertexAt", &PyDbPolyline::addVertexAt1)
        .def("addVertexAt", &PyDbPolyline::addVertexAt2, DS.ARGS({ "idx:int","pt2d:PyGe.Point2d","bulge:float=0.0","startWidth:float=0.0","endWidth:float=0.0" }))
        .def("removeVertexAt", &PyDbPolyline::removeVertexAt, DS.ARGS({ "idx:int" }))
        .def("numVerts", &PyDbPolyline::numVerts, DS.ARGS())
        .def("getBulgeAt", &PyDbPolyline::getBulgeAt, DS.ARGS({ "idx:int" }))
        .def("getStartWidthAt", &PyDbPolyline::getStartWidthAt, DS.ARGS({ "idx:int" }))
        .def("getEndWidthAt", &PyDbPolyline::getEndWidthAt, DS.ARGS({ "idx:int" }))
        .def("setPointAt", &PyDbPolyline::setPointAt, DS.ARGS({ "idx:int" ,"pt2d:PyGe.Point2d" }))
        .def("setBulgeAt", &PyDbPolyline::setBulgeAt, DS.ARGS({ "idx:int" ,"bulge:float" }))
        .def("setWidthsAt", &PyDbPolyline::setWidthsAt, DS.ARGS({ "idx:int" ,"startWidth:float","endWidth:float" }))
        .def("minimizeMemory", &PyDbPolyline::minimizeMemory, DS.ARGS())
        .def("maximizeMemory", &PyDbPolyline::maximizeMemory, DS.ARGS())
        .def("reset", &PyDbPolyline::reset, DS.ARGS({ "reuse:bool" ,"numVerts:int" }))
        .def("hasBulges", &PyDbPolyline::hasBulges, DS.ARGS())
        .def("hasVertexIdentifiers", &PyDbPolyline::hasVertexIdentifiers, DS.ARGS())
        .def("hasWidth", &PyDbPolyline::hasWidth, DS.ARGS())
        .def("makeClosedIfStartAndEndVertexCoincide", &PyDbPolyline::makeClosedIfStartAndEndVertexCoincide, DS.ARGS({ "distTol:float" }))
        .def("getEcs", &PyDbPolyline::getEcs, DS.ARGS())
        .def("getAcGeCurve", &PyDbPolyline::getAcGeCurve1)
        .def("getAcGeCurve", &PyDbPolyline::getAcGeCurve2, DS.ARGS({ "tol: Tol = default" }))
        .def("toPoint2dList", &PyDbPolyline::toPoint2dList, DS.ARGS())
        .def("toPoint3dList", &PyDbPolyline::toPoint3dList, DS.ARGS())
        .def("toList", &PyDbPolyline::toList, DS.ARGS())
        .def("className", &PyDbPolyline::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbPolyline::desc, DS.SARGS()).staticmethod("desc")
        .def("cloneFrom", &PyDbPolyline::cloneFrom, DS.SARGS({ "otherObject: RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbPolyline::cast, DS.SARGS({ "otherObject: RxObject" })).staticmethod("cast")
        ;

    enum_<AcDbPolyline::SegType>("SegType")
        .value("kLine", AcDbPolyline::SegType::kLine)
        .value("kArc", AcDbPolyline::SegType::kArc)
        .value("kCoincident", AcDbPolyline::SegType::kCoincident)
        .value("kPoint", AcDbPolyline::SegType::kPoint)
        .value("kEmpty", AcDbPolyline::SegType::kEmpty)
        ;
}

PyDbPolyline::PyDbPolyline()
    : PyDbCurve(new AcDbPolyline(), true)
{
}

PyDbPolyline::PyDbPolyline(unsigned int num_verts)
    : PyDbCurve(new AcDbPolyline(num_verts), true)
{
}

PyDbPolyline::PyDbPolyline(AcDbPolyline* ptr, bool autoDelete)
    : PyDbCurve(ptr, autoDelete)
{
}

PyDbPolyline::PyDbPolyline(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbCurve(openAcDbObject<AcDbPolyline>(id, mode), false)
{
}

PyDbPolyline::PyDbPolyline(const PyDbObjectId& id)
    : PyDbPolyline(id, AcDb::OpenMode::kForRead)
{
}

PyDbPolyline::PyDbPolyline(const boost::python::list& pnts)
    : PyDbCurve(new AcDbPolyline(boost::python::len(pnts)), true)
{
    if (boost::python::len(pnts) == 0)
        return;

    const extract<AcGePoint2d> extractor2d(pnts[0]);
    if (extractor2d.check())
    {
        const auto& vec = py_list_to_std_vector<AcGePoint2d>(pnts);
        for (int i = 0; i < vec.size(); i++)
            impObj()->addVertexAt(i, vec[i]);
        return;
    }
    const extract<AcGePoint3d> extractor3d(pnts[0]);
    if (extractor3d.check())
    {
        const auto& vec = py_list_to_std_vector<AcGePoint3d>(pnts);
        for (int i = 0; i < vec.size(); i++)
            impObj()->addVertexAt(i, AcGePoint2d(vec[i].x, vec[i].y));
        return;
    }
    const extract<boost::python::tuple> extractorTpl(pnts[0]);
    if (extractorTpl.check())
    {
        auto vec = std::vector<boost::python::tuple>(boost::python::stl_input_iterator<boost::python::tuple>(pnts),
            boost::python::stl_input_iterator<boost::python::tuple>());

        for (int i = 0; i < vec.size(); i++)
        {
            auto nlen = boost::python::len(vec[i]);
            if (nlen > 1)
                impObj()->addVertexAt(i, py_list_to_point2d(vec[i]));
        }
        return;
    }
    const extract<boost::python::list> extractorList(pnts[0]);
    if (extractorList.check())
    {
        auto vec = std::vector<boost::python::list>(boost::python::stl_input_iterator<boost::python::list>(pnts),
            boost::python::stl_input_iterator<boost::python::list>());

        for (int i = 0; i < vec.size(); i++)
        {
            auto nlen = boost::python::len(vec[i]);
            if (nlen > 1)
                impObj()->addVertexAt(i, py_list_to_point2d(vec[i]));
        }
        return;
    }
}

AcGePoint3d PyDbPolyline::getPoint3dAt(unsigned int idx) const
{
    AcGePoint3d pnt;
    if (auto es = impObj()->getPointAt(idx, pnt); es != eOk)
        throw PyAcadErrorStatus(es);
    return pnt;
}

AcGePoint2d PyDbPolyline::getPoint2dAt(unsigned int idx) const
{
    AcGePoint2d pnt;
    if (auto es = impObj()->getPointAt(idx, pnt); es != eOk)
        throw PyAcadErrorStatus(es);
    return pnt;
}

AcDbPolyline::SegType PyDbPolyline::segType(unsigned int index) const
{
    return impObj()->segType(index);
}

Adesk::Boolean PyDbPolyline::onSegAt(unsigned int index, const AcGePoint2d& pt2d, double param) const
{
    double _param = param;
    return impObj()->onSegAt(index, pt2d, _param);
}

PyGeLineSeg2d PyDbPolyline::getLineSeg2dAt(unsigned int index)
{
    AcGeLineSeg2d seg;
    if (auto es = impObj()->getLineSegAt(index, seg); es != eOk)
        throw PyAcadErrorStatus(es);
    return PyGeLineSeg2d(seg.copy());
}

PyGeLineSeg3d PyDbPolyline::getLineSeg3dAt(unsigned int index)
{
    AcGeLineSeg3d seg;
    if (auto es = impObj()->getLineSegAt(index, seg); es != eOk)
        throw PyAcadErrorStatus(es);
    return PyGeLineSeg3d(seg.copy());
}

PyGeCircArc2d PyDbPolyline::getArcSeg2dAt(unsigned int index)
{
    AcGeCircArc2d seg;
    if (auto es = impObj()->getArcSegAt(index, seg); es != eOk)
        throw PyAcadErrorStatus(es);
    return PyGeCircArc2d(seg.copy());
}

PyGeCircArc3d PyDbPolyline::getArcSeg3dAt(unsigned int index)
{
    AcGeCircArc3d seg;
    if (auto es = impObj()->getArcSegAt(index, seg); es != eOk)
        throw PyAcadErrorStatus(es);
    return PyGeCircArc3d(seg.copy());
}

void PyDbPolyline::setClosed(Adesk::Boolean val)
{
    impObj()->setClosed(val);
}

void PyDbPolyline::setPlinegen(Adesk::Boolean val)
{
    impObj()->setPlinegen(val);
}

void PyDbPolyline::setElevation(double val)
{
    impObj()->setElevation(val);
}

void PyDbPolyline::setThickness(double val)
{
    return PyThrowBadEs(impObj()->setThickness(val));
}

void PyDbPolyline::setConstantWidth(double val)
{
    return PyThrowBadEs(impObj()->setConstantWidth(val));
}

void PyDbPolyline::setNormal(const AcGeVector3d& val)
{
    return PyThrowBadEs(impObj()->setNormal(val));
}

Adesk::Boolean PyDbPolyline::isOnlyLines() const
{
    return impObj()->isOnlyLines();
}

Adesk::Boolean PyDbPolyline::hasPlinegen() const
{
    return impObj()->hasPlinegen();
}

double PyDbPolyline::elevation() const
{
    return impObj()->elevation();
}

double PyDbPolyline::thickness() const
{
    return impObj()->thickness();
}

double PyDbPolyline::getConstantWidth() const
{
    double w;
    if (auto es = impObj()->getConstantWidth(w); es != eOk)
        throw PyAcadErrorStatus(es);
    return w;
}

AcGeVector3d PyDbPolyline::normal() const
{
    return impObj()->normal();
}

void PyDbPolyline::addVertexAt1(unsigned int index, const AcGePoint2d& pnt)
{
    return PyThrowBadEs(impObj()->addVertexAt(index, pnt, 0.0, 0.0, 0.0));
}

void PyDbPolyline::addVertexAt2(unsigned int index, const AcGePoint2d& pnt, double bulge, double startWidth, double endWidth)
{
    return PyThrowBadEs(impObj()->addVertexAt(index, pnt, bulge, startWidth, endWidth));
}

void PyDbPolyline::removeVertexAt(unsigned int index)
{
    return PyThrowBadEs(impObj()->removeVertexAt(index));
}

unsigned int PyDbPolyline::numVerts() const
{
    return impObj()->numVerts();
}

double PyDbPolyline::getBulgeAt(unsigned int index) const
{
    double w;
    PyThrowBadEs(impObj()->getBulgeAt(index, w));
    return w;
}

double PyDbPolyline::getStartWidthAt(unsigned int index) const
{
    double s, e;
    PyThrowBadEs(impObj()->getWidthsAt(index, s, e));
    return s;
}

double PyDbPolyline::getEndWidthAt(unsigned int index) const
{
    double s, e;
    PyThrowBadEs(impObj()->getWidthsAt(index, s, e));
    return e;
}

void PyDbPolyline::setPointAt(unsigned int index, const AcGePoint2d& pt)
{
    return PyThrowBadEs(impObj()->setPointAt(index, pt));
}

void PyDbPolyline::setBulgeAt(unsigned int index, double bulge)
{
    return PyThrowBadEs(impObj()->setBulgeAt(index, bulge));
}

void PyDbPolyline::setWidthsAt(unsigned int index, double startWidth, double endWidth)
{
    return PyThrowBadEs(impObj()->setWidthsAt(index, startWidth, endWidth));
}

void PyDbPolyline::minimizeMemory()
{
    return PyThrowBadEs(impObj()->minimizeMemory());
}

void PyDbPolyline::maximizeMemory()
{
    return PyThrowBadEs(impObj()->maximizeMemory());
}

void PyDbPolyline::reset(Adesk::Boolean reuse, unsigned int numVerts)
{
    impObj()->reset(reuse, numVerts);
}

Adesk::Boolean PyDbPolyline::hasBulges() const
{
    return impObj()->hasBulges();
}

Adesk::Boolean PyDbPolyline::hasVertexIdentifiers() const
{
    return impObj()->hasVertexIdentifiers();
}

Adesk::Boolean PyDbPolyline::hasWidth() const
{
    return impObj()->hasWidth();
}

void PyDbPolyline::makeClosedIfStartAndEndVertexCoincide(double distTol)
{
#if defined(_GRXTARGET240) || (_BRXTARGET == 240)
    throw PyNotimplementedByHost();
#else
    return PyThrowBadEs(impObj()->makeClosedIfStartAndEndVertexCoincide(distTol));
#endif
}

PyGeCompositeCurve3d PyDbPolyline::getAcGeCurve1() const
{
    AcGeCurve3d* pGeCurve = nullptr;
    PyThrowBadEs(impObj()->getAcGeCurve(pGeCurve));
    return PyGeCompositeCurve3d(pGeCurve);
}

PyGeCompositeCurve3d PyDbPolyline::getAcGeCurve2(const AcGeTol& tol) const
{
    AcGeCurve3d* pGeCurve = nullptr;
    PyThrowBadEs(impObj()->getAcGeCurve(pGeCurve, tol));
    return PyGeCompositeCurve3d(pGeCurve);
}

boost::python::list PyDbPolyline::toPoint2dList()
{
    PyAutoLockGIL lock;
    boost::python::list pyList;
    const size_t count = impObj()->numVerts();
    for (int idx = 0; idx < count; idx++)
    {
        AcGePoint2d pnt;
        PyThrowBadEs(impObj()->getPointAt(idx, pnt));
        pyList.append(pnt);
    }
    return pyList;
}

boost::python::list PyDbPolyline::toPoint3dList()
{
    PyAutoLockGIL lock;
    boost::python::list pyList;
    const size_t count = impObj()->numVerts();
    for (int idx = 0; idx < count; idx++)
    {
        AcGePoint3d pnt;
        PyThrowBadEs(impObj()->getPointAt(idx, pnt));
        pyList.append(pnt);
    }
    return pyList;
}

boost::python::list PyDbPolyline::toList()
{
    PyAutoLockGIL lock;
    boost::python::list pyList;
    const size_t count = impObj()->numVerts();
    for (int idx = 0; idx < count; idx++)
    {
        AcGePoint2d pnt;
        PyThrowBadEs(impObj()->getPointAt(idx, pnt));
        pyList.append(boost::python::make_tuple(pnt.x, pnt.y));
    }
    return pyList;
}

std::string PyDbPolyline::className()
{
    return "AcDbPolyline";
}

PyRxClass PyDbPolyline::desc()
{
    return PyRxClass(AcDbPolyline::desc(), false);
}

PyDbPolyline PyDbPolyline::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbPolyline::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbPolyline(static_cast<AcDbPolyline*>(src.impObj()->clone()), true);
}

PyDbPolyline PyDbPolyline::cast(const PyRxObject& src)
{
    PyDbPolyline dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbPolyline* PyDbPolyline::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbPolyline*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//PyDbDace
void makePyDbFaceWrapper()
{
    PyDocString DS("Face");
    class_<PyDbFace, bases<PyDbEntity>>("Face")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&>())
        .def(init<const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&>())
        .def(init<const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&, Adesk::Boolean, Adesk::Boolean, Adesk::Boolean, Adesk::Boolean>())
        .def(init<const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&, const AcGePoint3d&, Adesk::Boolean, Adesk::Boolean, Adesk::Boolean, Adesk::Boolean>())
        .def("getVertexAt", &PyDbFace::getVertexAt, DS.ARGS({ "vIndex:int" }))
        .def("setVertexAt", &PyDbFace::setVertexAt, DS.ARGS({ "vIndex:int","pnt:PyGe.Point3d" }))
        .def("isEdgeVisibleAt", &PyDbFace::isEdgeVisibleAt, DS.ARGS({ "vIndex:int" }))
        .def("makeEdgeVisibleAt", &PyDbFace::makeEdgeVisibleAt, DS.ARGS({ "vIndex:int" }))
        .def("makeEdgeInvisibleAt", &PyDbFace::makeEdgeInvisibleAt, DS.ARGS({ "vIndex:int" }))
        .def("className", &PyDbFace::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbFace::desc, DS.SARGS()).staticmethod("desc")
        .def("cloneFrom", &PyDbFace::cloneFrom, DS.SARGS({ "otherObject: RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbFace::cast, DS.SARGS({ "otherObject: RxObject" })).staticmethod("cast")
        ;
}

PyDbFace::PyDbFace()
    : PyDbEntity(new AcDbFace(), true)
{
}

PyDbFace::PyDbFace(const PyDbObjectId& id)
    : PyDbFace(id, AcDb::OpenMode::kForRead)
{
}

PyDbFace::PyDbFace(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbEntity(openAcDbObject<AcDbFace>(id, mode), false)
{
}

PyDbFace::PyDbFace(AcDbFace* ptr, bool autoDelete)
    : PyDbEntity(ptr, autoDelete)
{
}

PyDbFace::PyDbFace(const AcGePoint3d& pt0, const AcGePoint3d& pt1, const AcGePoint3d& pt2)
    : PyDbEntity(new AcDbFace(pt0, pt1, pt2, Adesk::kTrue, Adesk::kTrue, Adesk::kTrue, Adesk::kTrue), true)
{
}

PyDbFace::PyDbFace(const AcGePoint3d& pt0, const AcGePoint3d& pt1, const AcGePoint3d& pt2, const AcGePoint3d& pt3)
    : PyDbEntity(new AcDbFace(pt0, pt1, pt2, pt3, Adesk::kTrue, Adesk::kTrue, Adesk::kTrue, Adesk::kTrue), true)
{
}

PyDbFace::PyDbFace(const AcGePoint3d& pt0, const AcGePoint3d& pt1, const AcGePoint3d& pt2, Adesk::Boolean e0vis, Adesk::Boolean e1vis, Adesk::Boolean e2vis, Adesk::Boolean e3vis)
    : PyDbEntity(new AcDbFace(pt0, pt1, pt2, e0vis, e1vis, e2vis, e3vis), true)
{
}

PyDbFace::PyDbFace(const AcGePoint3d& pt0, const AcGePoint3d& pt1, const AcGePoint3d& pt2, const AcGePoint3d& pt3, Adesk::Boolean e0vis, Adesk::Boolean e1vis, Adesk::Boolean e2vis, Adesk::Boolean e3vis)
    : PyDbEntity(new AcDbFace(pt0, pt1, pt2, pt3, e0vis, e1vis, e2vis, e3vis), true)
{
}

AcGePoint3d PyDbFace::getVertexAt(Adesk::UInt16 val) const
{
    AcGePoint3d rPoint;
    PyThrowBadEs(impObj()->getVertexAt(val, rPoint));
    return rPoint;
}

void PyDbFace::setVertexAt(Adesk::UInt16 val, const AcGePoint3d& pnt)
{
    return PyThrowBadEs(impObj()->setVertexAt(val, pnt));
}

Adesk::Boolean PyDbFace::isEdgeVisibleAt(Adesk::UInt16 val) const
{
    Adesk::Boolean rval;
    PyThrowBadEs(impObj()->isEdgeVisibleAt(val, rval));
    return rval;
}

void PyDbFace::makeEdgeVisibleAt(Adesk::UInt16 val)
{
    return PyThrowBadEs(impObj()->makeEdgeVisibleAt(val));
}

void PyDbFace::makeEdgeInvisibleAt(Adesk::UInt16 val)
{
    return PyThrowBadEs(impObj()->makeEdgeInvisibleAt(val));
}

std::string PyDbFace::className()
{
    return "AcDbFace";
}

PyRxClass PyDbFace::desc()
{
    return PyRxClass(AcDbFace::desc(), false);
}

PyDbFace PyDbFace::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbFace::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbFace(static_cast<AcDbFace*>(src.impObj()->clone()), true);
}

PyDbFace PyDbFace::cast(const PyRxObject& src)
{
    PyDbFace dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbFace* PyDbFace::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbFace*>(m_pyImp.get());
}

//-----------------------------------------------------------------------------------
//AcDbFcf
void makePyDbFcfWrapper()
{
    PyDocString DS("Fcf");
    class_<PyDbFcf, bases<PyDbEntity>>("Fcf")
        .def(init<>())
        .def(init<const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def(init<const std::string&, const AcGePoint3d&, const AcGeVector3d&, const AcGeVector3d&>())
        .def("setText", &PyDbFcf::setText, DS.ARGS({ "val:str" }))
        .def("text", &PyDbFcf::text, DS.ARGS())
        .def("textAll", &PyDbFcf::textAll, DS.ARGS())
        .def("setLocation", &PyDbFcf::setLocation, DS.ARGS({ "val:PyGe.Point3d" }))
        .def("location", &PyDbFcf::location, DS.ARGS())
        .def("setOrientation", &PyDbFcf::setOrientation, DS.ARGS({ "normal:PyGe.Vector3d","direction:PyGe.Vector3d" }))
        .def("normal", &PyDbFcf::normal, DS.ARGS())
        .def("direction", &PyDbFcf::direction, DS.ARGS())
        .def("getBoundingPoints", &PyDbFcf::getBoundingPoints, DS.ARGS())
        .def("getBoundingPline", &PyDbFcf::getBoundingPline, DS.ARGS())
        .def("setDimensionStyle", &PyDbFcf::setDimensionStyle, DS.ARGS({ "val:PyDb.ObjectId" }))
        .def("dimensionStyle", &PyDbFcf::dimensionStyle, DS.ARGS())
        .def("getDimstyleData", &PyDbFcf::getDimstyleData, DS.ARGS())
        .def("setDimstyleData", &PyDbFcf::setDimstyleData2, DS.ARGS({ "val:PyDb.DimStyleTableRecord" }))
        .def("setDimstyleData", &PyDbFcf::setDimstyleData1, DS.ARGS({ "val:PyDb.ObjectId" }))
        .def("setDimVars", &PyDbFcf::setDimVars, DS.ARGS())
        .def("dimclrd", &PyDbFcf::dimclrd, DS.ARGS())
        .def("dimclrt", &PyDbFcf::dimclrt, DS.ARGS())
        .def("dimgap", &PyDbFcf::dimgap, DS.ARGS())
        .def("dimscale", &PyDbFcf::dimscale, DS.ARGS())
        .def("dimtxsty", &PyDbFcf::dimtxsty, DS.ARGS())
        .def("dimtxt", &PyDbFcf::dimtxt, DS.ARGS())
        .def("setDimclrd", &PyDbFcf::setDimclrd, DS.ARGS({ "val:Color" }))
        .def("setDimclrt", &PyDbFcf::setDimclrt, DS.ARGS({ "val:Color" }))
        .def("setDimgap", &PyDbFcf::setDimgap, DS.ARGS({ "val:float" }))
        .def("setDimscale", &PyDbFcf::setDimscale, DS.ARGS({ "val:float" }))
        .def("setDimtxsty", &PyDbFcf::setDimtxsty)
        .def("setDimtxt", &PyDbFcf::setDimtxt, DS.ARGS({ "val:float" }))
        .def("className", &PyDbFcf::className, DS.SARGS()).staticmethod("className")
        .def("desc", &PyDbFcf::desc, DS.SARGS()).staticmethod("desc")
        .def("cloneFrom", &PyDbFcf::cloneFrom, DS.SARGS({ "otherObject: RxObject" })).staticmethod("cloneFrom")
        .def("cast", &PyDbFcf::cast, DS.SARGS({ "otherObject: RxObject" })).staticmethod("cast")
        ;
}

PyDbFcf::PyDbFcf()
    : PyDbEntity(new AcDbFcf(), true)
{
}

PyDbFcf::PyDbFcf(AcDbFcf* ptr, bool autoDelete)
    : PyDbEntity(ptr, autoDelete)
{
}

PyDbFcf::PyDbFcf(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbEntity(openAcDbObject<AcDbFcf>(id, mode), false)
{
}

PyDbFcf::PyDbFcf(const std::string& str, const AcGePoint3d& pnt, const AcGeVector3d& normal, const AcGeVector3d& direction)
    : PyDbEntity(new AcDbFcf(utf8_to_wstr(str).c_str(), pnt, normal, direction), true)
{
}

PyDbFcf::PyDbFcf(const PyDbObjectId& id)
    : PyDbFcf(id, AcDb::OpenMode::kForRead)
{
}

void PyDbFcf::setText(const std::string& val)
{
    impObj()->setText(utf8_to_wstr(val).c_str());
}

std::string PyDbFcf::text(int lineNo) const
{
    return wstr_to_utf8(impObj()->text(lineNo));
}

std::string PyDbFcf::textAll() const
{
    return wstr_to_utf8(impObj()->text());
}

void PyDbFcf::setLocation(const AcGePoint3d& val)
{
    impObj()->setLocation(val);
}

AcGePoint3d PyDbFcf::location() const
{
    return impObj()->location();
}

void PyDbFcf::setOrientation(const AcGeVector3d& norm, const AcGeVector3d& dir)
{
    impObj()->setOrientation(norm, dir);
}

AcGeVector3d PyDbFcf::normal() const
{
    return impObj()->normal();
}

AcGeVector3d PyDbFcf::direction() const
{
    return impObj()->direction();
}

boost::python::list PyDbFcf::getBoundingPoints() const
{
    PyAutoLockGIL loc;
    AcGePoint3dArray a;
    boost::python::list l;
    impObj()->getBoundingPoints(a);
    for (auto& p : a)
        l.append(p);
    return l;
}

boost::python::list PyDbFcf::getBoundingPline() const
{
    PyAutoLockGIL loc;
    AcGePoint3dArray a;
    boost::python::list l;
    impObj()->getBoundingPline(a);
    for (auto& p : a)
        l.append(p);
    return l;
}

void PyDbFcf::setDimensionStyle(const PyDbHardPointerId& id)
{
    impObj()->setDimensionStyle(id.m_id);
}

PyDbHardPointerId PyDbFcf::dimensionStyle() const
{
    return PyDbHardPointerId(impObj()->dimensionStyle());
}

PyDbDimStyleTableRecord PyDbFcf::getDimstyleData() const
{
    AcDbDimStyleTableRecord* pSyle = nullptr;
    PyThrowBadEs(impObj()->getDimstyleData(pSyle));
    return PyDbDimStyleTableRecord(pSyle, true);
}

void PyDbFcf::setDimstyleData2(const PyDbDimStyleTableRecord& pNewData)
{
    return PyThrowBadEs(impObj()->setDimstyleData(pNewData.impObj()));
}

void PyDbFcf::setDimstyleData1(const PyDbObjectId& newDataId)
{
    return PyThrowBadEs(impObj()->setDimstyleData(newDataId.m_id));
}

void PyDbFcf::setDimVars()
{
    impObj()->setDimVars();
}

AcCmColor PyDbFcf::dimclrd() const
{
    return impObj()->dimclrd();
}

AcCmColor PyDbFcf::dimclrt() const
{
    return impObj()->dimclrt();
}

double PyDbFcf::dimgap() const
{
    return impObj()->dimgap();
}

double PyDbFcf::dimscale() const
{
    return impObj()->dimscale();
}

PyDbObjectId PyDbFcf::dimtxsty() const
{
    return PyDbObjectId(impObj()->dimtxsty());
}

double PyDbFcf::dimtxt() const
{
    return impObj()->dimtxt();
}

void PyDbFcf::setDimclrd(AcCmColor& val)
{
    return PyThrowBadEs(impObj()->setDimclrd(val));
}

void PyDbFcf::setDimclrt(AcCmColor& val)
{
    return PyThrowBadEs(impObj()->setDimclrt(val));
}

void PyDbFcf::setDimgap(double val)
{
    return PyThrowBadEs(impObj()->setDimgap(val));
}

void PyDbFcf::setDimscale(double val)
{
    return PyThrowBadEs(impObj()->setDimscale(val));
}

void PyDbFcf::setDimtxsty(PyDbObjectId& val)
{
    return PyThrowBadEs(impObj()->setDimtxsty(val.m_id));
}

void PyDbFcf::setDimtxt(double val)
{
    return PyThrowBadEs(impObj()->setDimtxt(val));
}

std::string PyDbFcf::className()
{
    return "AcDbFcf";
}

PyRxClass PyDbFcf::desc()
{
    return PyRxClass(AcDbFcf::desc(), false);
}

PyDbFcf PyDbFcf::cloneFrom(const PyRxObject& src)
{
    if (!src.impObj()->isKindOf(AcDbFcf::desc()))
        throw PyAcadErrorStatus(eNotThatKindOfClass);
    return PyDbFcf(static_cast<AcDbFcf*>(src.impObj()->clone()), true);
}

PyDbFcf PyDbFcf::cast(const PyRxObject& src)
{
    PyDbFcf dest(nullptr, false);
    PyRxObject rxo = src;
    std::swap(rxo.m_pyImp, dest.m_pyImp);
    return dest;
}

AcDbFcf* PyDbFcf::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<AcDbFcf*>(m_pyImp.get());
}
