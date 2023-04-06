#include "stdafx.h"
#include "PyDbEnts.h"
#include "PyDbObjectId.h"
using namespace boost::python;


//-----------------------------------------------------------------------------------
//PyDbText
void makePyDbTextWrapper()
{
    static auto wrapper = class_<PyDbText, bases<PyDbEntity>>("DbText")
        .def(init<>())
        .def(init<AcGePoint3d&, const std::string&>())
        .def(init<AcGePoint3d&, const std::string&, PyDbObjectId&, double, double>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("position", &PyDbText::position)
        .def("setPosition", &PyDbText::setPosition)
        .def("alignmentPoint", &PyDbText::alignmentPoint)
        .def("setAlignmentPoint", &PyDbText::setAlignmentPoint)
        .def("isDefaultAlignment", &PyDbText::isDefaultAlignment)
        .def("normal", &PyDbText::normal)
        .def("setNormal", &PyDbText::setNormal)
        .def("isPlanar", &PyDbText::isPlanar)
        .def("thickness", &PyDbText::thickness)
        .def("setThickness", &PyDbText::setThickness)
        .def("oblique", &PyDbText::oblique)
        .def("setOblique", &PyDbText::setOblique)
        .def("rotation", &PyDbText::rotation)
        .def("setRotation", &PyDbText::setRotation)
        .def("height", &PyDbText::height)
        .def("setHeight", &PyDbText::setHeight)
        .def("widthFactor", &PyDbText::widthFactor)
        .def("setWidthFactor", &PyDbText::setWidthFactor)
        .def("textString", &PyDbText::textString)
        .def("setTextString", &PyDbText::setTextString)
        .def("textStyle", &PyDbText::textStyle)
        .def("setTextStyle", &PyDbText::setTextStyle)
        .def("isMirroredInX", &PyDbText::isMirroredInX)
        .def("mirrorInX", &PyDbText::mirrorInX)
        .def("isMirroredInY", &PyDbText::isMirroredInY)
        .def("mirrorInY", &PyDbText::mirrorInY)
        .def("horizontalMode", &PyDbText::horizontalMode)
        .def("setHorizontalMode", &PyDbText::setHorizontalMode)
        .def("verticalMode", &PyDbText::verticalMode)
        .def("setVerticalMode", &PyDbText::setVerticalMode)
        .def("correctSpelling", &PyDbText::correctSpelling)
        .def("adjustAlignment", &PyDbText::adjustAlignment)
        .def("convertFieldToText", &PyDbText::convertFieldToText)
        .def("hitTest", &PyDbText::hitTest)
        .def("getBoundingPoints", &PyDbText::getBoundingPoints)
        .def("className", &PyDbText::className).staticmethod("className")
        ;


    enum_<AcDbText::AcTextAlignment>("AcTextAlignment")
        .value("TextAlignmentLeft", AcDbText::AcTextAlignment::kTextAlignmentLeft)
        .value("TextAlignmentCenter", AcDbText::AcTextAlignment::kTextAlignmentCenter)
        .value("TextAlignmentRight", AcDbText::AcTextAlignment::kTextAlignmentRight)
        .value("TextAlignmentAligned", AcDbText::AcTextAlignment::kTextAlignmentAligned)
        .value("TextAlignmentMiddle", AcDbText::AcTextAlignment::kTextAlignmentMiddle)
        .value("TextAlignmentFit", AcDbText::AcTextAlignment::kTextAlignmentFit)
        .value("TextAlignmentTopLeft", AcDbText::AcTextAlignment::kTextAlignmentTopLeft)
        .value("TextAlignmentTopCenter", AcDbText::AcTextAlignment::kTextAlignmentTopCenter)
        .value("TextAlignmentTopRight", AcDbText::AcTextAlignment::kTextAlignmentTopRight)
        .value("TextAlignmentMiddleLeft", AcDbText::AcTextAlignment::kTextAlignmentMiddleLeft)
        .value("TextAlignmentMiddleCenter", AcDbText::AcTextAlignment::kTextAlignmentMiddleCenter)
        .value("TextAlignmentMiddleRight", AcDbText::AcTextAlignment::kTextAlignmentMiddleRight)
        .value("TextAlignmentBottomLeft", AcDbText::AcTextAlignment::kTextAlignmentBottomLeft)
        .value("TextAlignmentBottomCenter", AcDbText::AcTextAlignment::kTextAlignmentBottomCenter)
        .value("TextAlignmentBottomRight", AcDbText::AcTextAlignment::kTextAlignmentBottomRight)
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
    : PyDbEntity(nullptr, false)
{
    AcDbText* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbText>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    m_pImp = pobj;
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
}

AcGePoint3d PyDbText::position() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->position();
}

Acad::ErrorStatus PyDbText::setPosition(const AcGePoint3d& val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setPosition(val);
}

AcGePoint3d PyDbText::alignmentPoint() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->alignmentPoint();
}

Acad::ErrorStatus PyDbText::setAlignmentPoint(const AcGePoint3d& val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setAlignmentPoint(val);
}

Adesk::Boolean PyDbText::isDefaultAlignment() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isDefaultAlignment();
}

AcGeVector3d PyDbText::normal() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->normal();
}

Acad::ErrorStatus PyDbText::setNormal(const AcGeVector3d& val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setNormal(val);
}

double PyDbText::thickness() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->thickness();
}

Acad::ErrorStatus PyDbText::setThickness(double val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setThickness(val);
}

double PyDbText::oblique() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->oblique();
}

Acad::ErrorStatus PyDbText::setOblique(double val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setOblique(val);
}

double PyDbText::rotation() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->rotation();
}

Acad::ErrorStatus PyDbText::setRotation(double val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setRotation(val);
}

double PyDbText::height() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->height();
}

Acad::ErrorStatus PyDbText::setHeight(double val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setHeight(val);
}

double PyDbText::widthFactor() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->widthFactor();
}

Acad::ErrorStatus PyDbText::setWidthFactor(double val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setWidthFactor(val);
}

std::string PyDbText::textString() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return wstr_to_utf8(imp->textStringConst());
}

Acad::ErrorStatus PyDbText::setTextString(std::string& val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setTextString(utf8_to_wstr(val).c_str());
}

PyDbObjectId PyDbText::textStyle() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return PyDbObjectId(imp->textStyle());
}

Acad::ErrorStatus PyDbText::setTextStyle(const PyDbObjectId& val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setTextStyle(val.m_id);
}

Adesk::Boolean PyDbText::isMirroredInX() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isMirroredInX();
}

Acad::ErrorStatus PyDbText::mirrorInX(Adesk::Boolean val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->mirrorInX(val);
}

Adesk::Boolean PyDbText::isMirroredInY() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isMirroredInY();
}

Acad::ErrorStatus PyDbText::mirrorInY(Adesk::Boolean val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->mirrorInY(val);
}

AcDb::TextHorzMode PyDbText::horizontalMode() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->horizontalMode();
}

Acad::ErrorStatus PyDbText::setHorizontalMode(AcDb::TextHorzMode val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setHorizontalMode(val);
}

AcDb::TextVertMode PyDbText::verticalMode() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->verticalMode();
}

Acad::ErrorStatus PyDbText::setVerticalMode(AcDb::TextVertMode val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setVerticalMode(val);
}

int PyDbText::correctSpelling()
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->correctSpelling();
#endif
}

Acad::ErrorStatus PyDbText::adjustAlignment(const PyDbDatabase& pDb)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->adjustAlignment(pDb.impObj());
#endif
}

Acad::ErrorStatus PyDbText::convertFieldToText()
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->convertFieldToText();
#endif
}

bool PyDbText::hitTest(const AcGePoint3d& ptHit) const
{
#ifdef ARXAPP
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->hitTest(ptHit);
#else
    throw PyNotimplementedByHost();
#endif // ARXAPP
}

boost::python::list PyDbText::getBoundingPoints() const
{
#ifdef ARXAPP
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    boost::python::list l;
    AcGePoint3dArray arr;
    imp->getBoundingPoints(arr);
    for (const auto& item : arr)
        l.append(item);
    return l;
#else
    throw PyNotimplementedByHost();
#endif // ARXAPP
}

AcDbText::AcTextAlignment PyDbText::justification() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->justification();
}

Acad::ErrorStatus PyDbText::setJustification(AcDbText::AcTextAlignment val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setJustification(val);
}

std::string PyDbText::className()
{
    return "AcDbText";
}

AcDbText* PyDbText::impObj() const
{
    return static_cast<AcDbText*>(m_pImp);
}

//-----------------------------------------------------------------------------------
//PyDbAttributeDefinition
void makePyDbAttributeDefinitionWrapper()
{
    static auto wrapper = class_<PyDbAttributeDefinition, bases<PyDbText>>("DbAttributeDefinition")
        .def(init<>())
        .def(init<const AcGePoint3d&, const std::string&, const std::string&, const std::string&, const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("prompt", &PyDbAttributeDefinition::prompt)
        .def("setPrompt", &PyDbAttributeDefinition::setPrompt)
        .def("tag", &PyDbAttributeDefinition::tag)
        .def("setTag", &PyDbAttributeDefinition::setTag)
        .def("isInvisible", &PyDbAttributeDefinition::isInvisible)
        .def("setInvisible", &PyDbAttributeDefinition::setInvisible)
        .def("isConstant", &PyDbAttributeDefinition::isConstant)
        .def("setConstant", &PyDbAttributeDefinition::setConstant)
        .def("isVerifiable", &PyDbAttributeDefinition::isVerifiable)
        .def("setVerifiable", &PyDbAttributeDefinition::setVerifiable)
        .def("isPreset", &PyDbAttributeDefinition::isPreset)
        .def("setPreset", &PyDbAttributeDefinition::setPreset)
        .def("fieldLength", &PyDbAttributeDefinition::fieldLength)
        .def("setFieldLength", &PyDbAttributeDefinition::setFieldLength)
        .def("adjustAlignment", &PyDbAttributeDefinition::adjustAlignment)
        .def("lockPositionInBlock", &PyDbAttributeDefinition::lockPositionInBlock)
        .def("setLockPositionInBlock", &PyDbAttributeDefinition::setLockPositionInBlock)
        .def("isMTextAttributeDefinition", &PyDbAttributeDefinition::isMTextAttributeDefinition)
        .def("convertIntoMTextAttributeDefinition", &PyDbAttributeDefinition::convertIntoMTextAttributeDefinition)
        .def("updateMTextAttributeDefinition", &PyDbAttributeDefinition::updateMTextAttributeDefinition)
        .def("className", &PyDbAttributeDefinition::className).staticmethod("className")
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
    : PyDbText(nullptr, false)
{
    AcDbAttributeDefinition* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbAttributeDefinition>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    m_pImp = pobj;
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
}

std::string PyDbAttributeDefinition::prompt() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return wstr_to_utf8(imp->promptConst());
}

Acad::ErrorStatus PyDbAttributeDefinition::setPrompt(const std::string& val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setPrompt(utf8_to_wstr(val).c_str());
}

std::string PyDbAttributeDefinition::tag() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return wstr_to_utf8(imp->tagConst());
}

Acad::ErrorStatus PyDbAttributeDefinition::setTag(const std::string& val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setTag(utf8_to_wstr(val).c_str());
}

Adesk::Boolean PyDbAttributeDefinition::isInvisible() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isInvisible();
}

Acad::ErrorStatus PyDbAttributeDefinition::setInvisible(Adesk::Boolean val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setInvisible(val);
}

Adesk::Boolean PyDbAttributeDefinition::isConstant() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isConstant();
}

Acad::ErrorStatus PyDbAttributeDefinition::setConstant(Adesk::Boolean val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setConstant(val);
}

Adesk::Boolean PyDbAttributeDefinition::isVerifiable() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isVerifiable();
}

Acad::ErrorStatus PyDbAttributeDefinition::setVerifiable(Adesk::Boolean val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setVerifiable(val);
}

Adesk::Boolean PyDbAttributeDefinition::isPreset() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isPreset();
}

Acad::ErrorStatus PyDbAttributeDefinition::setPreset(Adesk::Boolean val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setPreset(val);
}

Adesk::UInt16 PyDbAttributeDefinition::fieldLength() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->fieldLength();
}

Acad::ErrorStatus PyDbAttributeDefinition::setFieldLength(Adesk::UInt16 val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setFieldLength(val);
}

Acad::ErrorStatus PyDbAttributeDefinition::adjustAlignment(const PyDbDatabase& pDb)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->adjustAlignment(pDb.impObj());
}

bool PyDbAttributeDefinition::lockPositionInBlock() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->lockPositionInBlock();
}

Acad::ErrorStatus PyDbAttributeDefinition::setLockPositionInBlock(bool bValue)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setLockPositionInBlock(bValue);
}

bool PyDbAttributeDefinition::isMTextAttributeDefinition() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isMTextAttributeDefinition();
}

Acad::ErrorStatus PyDbAttributeDefinition::convertIntoMTextAttributeDefinition(Adesk::Boolean val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->convertIntoMTextAttributeDefinition(val);
}

Acad::ErrorStatus PyDbAttributeDefinition::updateMTextAttributeDefinition()
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->updateMTextAttributeDefinition();
}

std::string PyDbAttributeDefinition::className()
{
    return "AcDbAttributeDefinition";
}

AcDbAttributeDefinition* PyDbAttributeDefinition::impObj() const
{
    return static_cast<AcDbAttributeDefinition*>(m_pImp);
}

//-----------------------------------------------------------------------------------
//PyDbAttribute
void makePyDbAttributeWrapper()
{
    static auto wrapper = class_<PyDbAttribute, bases<PyDbText>>("DbAttribute")
        .def(init<>())
        .def(init<const AcGePoint3d&, const std::string&, const std::string&, const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("tag", &PyDbAttribute::tag)
        .def("setTag", &PyDbAttribute::setTag)
        .def("isInvisible", &PyDbAttribute::isInvisible)
        .def("setInvisible", &PyDbAttribute::setInvisible)
        .def("isConstant", &PyDbAttribute::isConstant)
        .def("isVerifiable", &PyDbAttribute::isVerifiable)
        .def("isPreset", &PyDbAttribute::isPreset)
        .def("fieldLength", &PyDbAttribute::fieldLength)
        .def("setFieldLength", &PyDbAttribute::setFieldLength)
        .def<Acad::ErrorStatus(PyDbAttribute::*)(const AcGeMatrix3d&)>("setAttributeFromBlock", &PyDbAttribute::setAttributeFromBlock)
        .def<Acad::ErrorStatus(PyDbAttribute::*)(const PyDbAttributeDefinition&, const AcGeMatrix3d&)>("setAttributeFromBlock", &PyDbAttribute::setAttributeFromBlock)
        .def("lockPositionInBlock", &PyDbAttribute::lockPositionInBlock)
        .def("setLockPositionInBlock", &PyDbAttribute::setLockPositionInBlock)
        .def("isMTextAttribute", &PyDbAttribute::isMTextAttribute)
        .def("convertIntoMTextAttribute", &PyDbAttribute::convertIntoMTextAttribute)
        .def("updateMTextAttribute", &PyDbAttribute::updateMTextAttribute)
        .def("isReallyLocked", &PyDbAttribute::isReallyLocked)
        .def("className", &PyDbAttributeDefinition::className).staticmethod("className")
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

PyDbAttribute::PyDbAttribute(AcDbAttributeDefinition* ptr, bool autoDelete)
    : PyDbText(ptr, autoDelete)
{
}

PyDbAttribute::PyDbAttribute(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbText(nullptr, false)
{
    AcDbAttribute* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbAttribute>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    m_pImp = pobj;
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
}

std::string PyDbAttribute::tag() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return wstr_to_utf8(imp->tagConst());
}

Acad::ErrorStatus PyDbAttribute::setTag(const std::string& val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setTag(utf8_to_wstr(val).c_str());
}

Adesk::Boolean PyDbAttribute::isInvisible() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isInvisible();
}

Acad::ErrorStatus PyDbAttribute::setInvisible(Adesk::Boolean val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setInvisible(val);
}

Adesk::Boolean PyDbAttribute::isConstant() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isConstant();
}

Adesk::Boolean PyDbAttribute::isVerifiable() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isVerifiable();
}

Adesk::Boolean PyDbAttribute::isPreset() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isPreset();
}

Adesk::UInt16 PyDbAttribute::fieldLength() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isPreset();
}

Acad::ErrorStatus PyDbAttribute::setFieldLength(Adesk::UInt16 val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setFieldLength(val);
}

Acad::ErrorStatus PyDbAttribute::setAttributeFromBlock(const AcGeMatrix3d& blkXform)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setAttributeFromBlock(blkXform);
}

Acad::ErrorStatus PyDbAttribute::setAttributeFromBlock(const PyDbAttributeDefinition& pAttdef, const AcGeMatrix3d& blkXform)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setAttributeFromBlock(pAttdef.impObj(), blkXform);
}

bool PyDbAttribute::lockPositionInBlock() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->lockPositionInBlock();
}

Acad::ErrorStatus PyDbAttribute::setLockPositionInBlock(bool bValue)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setLockPositionInBlock(bValue);
}

bool PyDbAttribute::isMTextAttribute() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isMTextAttribute();
}

Acad::ErrorStatus PyDbAttribute::convertIntoMTextAttribute(Adesk::Boolean val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->convertIntoMTextAttribute(val);
}

Acad::ErrorStatus PyDbAttribute::updateMTextAttribute()
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->updateMTextAttribute();
}

bool PyDbAttribute::isReallyLocked() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isReallyLocked();
#endif
}

std::string PyDbAttribute::className()
{
    return "AcDbAttribute";
}

AcDbAttribute* PyDbAttribute::impObj() const
{
    return static_cast<AcDbAttribute*>(m_pImp);
}

//-----------------------------------------------------------------------------------
//PyDbBlockReference
void makeDbBlockReferenceWrapper()
{
    static auto wrapper = class_<PyDbBlockReference, bases<PyDbEntity>>("DbBlockReference")
        .def(init<>())
        .def(init<AcGePoint3d&, const PyDbObjectId&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("blockTableRecord", &PyDbBlockReference::blockTableRecord)
        .def("setBlockTableRecord", &PyDbBlockReference::setBlockTableRecord)
        .def("position", &PyDbBlockReference::position)
        .def("setPosition", &PyDbBlockReference::setPosition)
        .def("scaleFactors", &PyDbBlockReference::scaleFactors)
        .def("nonAnnotationScaleFactors", &PyDbBlockReference::nonAnnotationScaleFactors)
        .def("setScaleFactors", &PyDbBlockReference::setScaleFactors)
        .def("rotation", &PyDbBlockReference::rotation)
        .def("setRotation", &PyDbBlockReference::setRotation)
        .def("normal", &PyDbBlockReference::normal)
        .def("setNormal", &PyDbBlockReference::setNormal)
        .def("isPlanar", &PyDbBlockReference::isPlanar)
        .def("blockTransform", &PyDbBlockReference::blockTransform)
        .def("nonAnnotationBlockTransform", &PyDbBlockReference::nonAnnotationBlockTransform)
        .def("setBlockTransform", &PyDbBlockReference::setBlockTransform)
        .def("appendAttribute", &PyDbBlockReference::appendAttribute)
        .def("attributeIds", &PyDbBlockReference::attributeIds)
        .def("treatAsAcDbBlockRefForExplode", &PyDbBlockReference::treatAsAcDbBlockRefForExplode)
        .def("geomExtentsBestFit", &PyDbBlockReference::geomExtentsBestFit)
        .def("explodeToOwnerSpace", &PyDbBlockReference::explodeToOwnerSpace)
        .def("className", &PyDbBlockReference::className).staticmethod("className")
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

PyDbBlockReference::PyDbBlockReference(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbEntity(nullptr, false)
{
    AcDbBlockReference* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbBlockReference>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    m_pImp = pobj;
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
}

PyDbObjectId PyDbBlockReference::blockTableRecord() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return PyDbObjectId(imp->blockTableRecord());
}

Acad::ErrorStatus PyDbBlockReference::setBlockTableRecord(const PyDbObjectId& val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setBlockTableRecord(val.m_id);
}

AcGePoint3d PyDbBlockReference::position() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->position();
}

Acad::ErrorStatus PyDbBlockReference::setPosition(const AcGePoint3d& val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setPosition(val);
}

AcGeScale3d PyDbBlockReference::scaleFactors() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->scaleFactors();
}

AcGeScale3d PyDbBlockReference::nonAnnotationScaleFactors() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->nonAnnotationScaleFactors();
}

Acad::ErrorStatus PyDbBlockReference::setScaleFactors(const AcGeScale3d& scale)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setScaleFactors(scale);
}

double PyDbBlockReference::rotation() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->rotation();
}

Acad::ErrorStatus PyDbBlockReference::setRotation(double newVal)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setRotation(newVal);
}

AcGeVector3d PyDbBlockReference::normal() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->normal();
}

Acad::ErrorStatus PyDbBlockReference::setNormal(const AcGeVector3d& newVal)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setNormal(newVal);
}

AcGeMatrix3d PyDbBlockReference::blockTransform() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->blockTransform();
}

AcGeMatrix3d PyDbBlockReference::nonAnnotationBlockTransform() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->nonAnnotationBlockTransform();
}

Acad::ErrorStatus PyDbBlockReference::setBlockTransform(const AcGeMatrix3d& val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setBlockTransform(val);
}

PyDbObjectId PyDbBlockReference::appendAttribute(PyDbAttribute& att)
{
    AcDbObjectId id;
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    if (auto es = imp->appendAttribute(id, att.impObj()); es != eOk)
        throw PyAcadErrorStatus(es);
    return PyDbObjectId(id);
}

boost::python::list PyDbBlockReference::attributeIds() const
{
    AcDbObjectId id;
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    boost::python::list ids;
    for (std::unique_ptr<AcDbObjectIterator> iter(imp->attributeIterator()); !iter->done(); iter->step())
        ids.append(PyDbObjectId(iter->objectId()));
    return ids;
}

Adesk::Boolean PyDbBlockReference::treatAsAcDbBlockRefForExplode() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->treatAsAcDbBlockRefForExplode();
}

Acad::ErrorStatus PyDbBlockReference::geomExtentsBestFit(AcDbExtents& extents, const AcGeMatrix3d& parentXform) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->geomExtentsBestFit(extents, parentXform);
}

Acad::ErrorStatus PyDbBlockReference::explodeToOwnerSpace() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->explodeToOwnerSpace();
}

std::string PyDbBlockReference::className()
{
    return "AcDbBlockReference";
}

AcDbBlockReference* PyDbBlockReference::impObj() const
{
    return static_cast<AcDbBlockReference*>(m_pImp);
}

//-----------------------------------------------------------------------------------
//PyDbBlockReference
void makeDbMInsertBlockeWrapper()
{
    static auto wrapper = class_<PyDbMInsertBlock, bases<PyDbBlockReference>>("DbMInsertBlock")
        .def(init<>())
        .def(init<AcGePoint3d&, const PyDbObjectId&, Adesk::UInt16, Adesk::UInt16, double, double>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("columns", &PyDbMInsertBlock::columns)
        .def("setColumns", &PyDbMInsertBlock::setColumns)
        .def("rows", &PyDbMInsertBlock::rows)
        .def("setRows", &PyDbMInsertBlock::setRows)
        .def("columnSpacing", &PyDbMInsertBlock::columnSpacing)
        .def("setColumnSpacing", &PyDbMInsertBlock::setColumnSpacing)
        .def("rowSpacing", &PyDbMInsertBlock::rowSpacing)
        .def("setRowSpacing", &PyDbMInsertBlock::setRowSpacing)
        .def("className", &PyDbMInsertBlock::className).staticmethod("className")
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
    : PyDbBlockReference(nullptr, false)
{
    AcDbMInsertBlock* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbMInsertBlock>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    m_pImp = pobj;
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
}

Adesk::UInt16 PyDbMInsertBlock::columns() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->columns();
}

Acad::ErrorStatus PyDbMInsertBlock::setColumns(Adesk::UInt16 val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setColumns(val);
}

Adesk::UInt16 PyDbMInsertBlock::rows() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->rows();
}

Acad::ErrorStatus PyDbMInsertBlock::setRows(Adesk::UInt16 val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setRows(val);
}

double PyDbMInsertBlock::columnSpacing() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->columnSpacing();
}

Acad::ErrorStatus PyDbMInsertBlock::setColumnSpacing(double val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setColumnSpacing(val);
}

double PyDbMInsertBlock::rowSpacing() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->rowSpacing();
}

Acad::ErrorStatus PyDbMInsertBlock::setRowSpacing(double val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setRowSpacing(val);
}

std::string PyDbMInsertBlock::className()
{
    return "AcDbMInsertBlock";
}

AcDbMInsertBlock* PyDbMInsertBlock::impObj() const
{
    return static_cast<AcDbMInsertBlock*>(m_pImp);
}

//-------------------------------------------------------------------------------------------------------------
//PyDbVertex
void makeAcDbVertexWrapper()
{
    static auto wrapper = class_<PyDbVertex, bases<PyDbEntity>>("DbVertex", boost::python::no_init)
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("className", &PyDbVertex::className).staticmethod("className")
        ;
}

PyDbVertex::PyDbVertex(AcDbVertex* ptr, bool autoDelete)
    : PyDbEntity(ptr, autoDelete)
{
}

PyDbVertex::PyDbVertex(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbEntity(nullptr, false)
{
    AcDbVertex* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbVertex>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    m_pImp = pobj;
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
}

std::string PyDbVertex::className()
{
    return "AcDbVertex";
}

AcDbVertex* PyDbVertex::impObj() const
{
    return static_cast<AcDbVertex*>(m_pImp);
}

//-------------------------------------------------------------------------------------------------------------
//PyDb2dVertex
void makePyDb2dVertexWrapper()
{
    static auto wrapper = class_<PyDb2dVertex, bases<PyDbVertex>>("Db2dVertex")
        .def(init<>())
        .def(init<const AcGePoint3d&>())
#ifndef BRXAPP
        .def(init<const AcGePoint3d&, double, double, double, double, Adesk::Int32>())
#endif
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("vertexType", &PyDb2dVertex::vertexType)
        .def("position", &PyDb2dVertex::position)
        .def("setPosition", &PyDb2dVertex::setPosition)
        .def("startWidth", &PyDb2dVertex::startWidth)
        .def("setStartWidth", &PyDb2dVertex::setStartWidth)
        .def("endWidth", &PyDb2dVertex::endWidth)
        .def("setEndWidth", &PyDb2dVertex::setEndWidth)
        .def("bulge", &PyDb2dVertex::bulge)
        .def("setBulge", &PyDb2dVertex::setBulge)
        .def("isTangentUsed", &PyDb2dVertex::isTangentUsed)
        .def("useTangent", &PyDb2dVertex::useTangent)
        .def("ignoreTangent", &PyDb2dVertex::ignoreTangent)
        .def("setTangentUsed", &PyDb2dVertex::setTangentUsed)
        .def("tangent", &PyDb2dVertex::tangent)
        .def("setTangent", &PyDb2dVertex::setTangent)
        .def("setVertexIdentifier", &PyDb2dVertex::setVertexIdentifier)
        .def("vertexIdentifier", &PyDb2dVertex::vertexIdentifier)
        .def("className", &PyDb2dVertex::className).staticmethod("className")
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

#ifndef BRXAPP
PyDb2dVertex::PyDb2dVertex(const AcGePoint3d& pos, double bulge, double startWidth, double endWidth, double tangent, Adesk::Int32 vertexIdentifier)
    : PyDb2dVertex(new AcDb2dVertex(pos, bulge, startWidth, endWidth, tangent, vertexIdentifier), true)
{
}
#endif // !BRXAPP

PyDb2dVertex::PyDb2dVertex(AcDb2dVertex* ptr, bool autoDelete)
    : PyDbVertex(ptr, autoDelete)
{
}

PyDb2dVertex::PyDb2dVertex(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbVertex(nullptr, false)
{
    AcDb2dVertex* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDb2dVertex>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    m_pImp = pobj;
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
}

AcDb::Vertex2dType PyDb2dVertex::vertexType() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->vertexType();
}

AcGePoint3d PyDb2dVertex::position() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->position();
}

Acad::ErrorStatus PyDb2dVertex::setPosition(const AcGePoint3d& val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setPosition(val);
}

double PyDb2dVertex::startWidth() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->startWidth();
}

Acad::ErrorStatus PyDb2dVertex::setStartWidth(double newVal)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setStartWidth(newVal);
}

double PyDb2dVertex::endWidth() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->endWidth();
}

Acad::ErrorStatus PyDb2dVertex::setEndWidth(double newVal)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setEndWidth(newVal);
}

double PyDb2dVertex::bulge() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->bulge();
}

Acad::ErrorStatus PyDb2dVertex::setBulge(double newVal)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setBulge(newVal);
}

Adesk::Boolean PyDb2dVertex::isTangentUsed() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isTangentUsed();
}

Acad::ErrorStatus PyDb2dVertex::useTangent()
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->useTangent();
}

Acad::ErrorStatus PyDb2dVertex::ignoreTangent()
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->ignoreTangent();
}

Acad::ErrorStatus PyDb2dVertex::setTangentUsed(Adesk::Boolean val)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else // !BRXAPP
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setTangentUsed(val);
#endif
}

double PyDb2dVertex::tangent() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->tangent();
}

Acad::ErrorStatus PyDb2dVertex::setTangent(double newVal)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setTangent(newVal);
}

Acad::ErrorStatus PyDb2dVertex::setVertexIdentifier(Adesk::Int32 suggestedValue)
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else // !BRXAPP
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setVertexIdentifier(suggestedValue);
#endif
}

int PyDb2dVertex::vertexIdentifier() const
{
#ifdef BRXAPP
    throw PyNotimplementedByHost();
#else // !BRXAPP
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->vertexIdentifier();
#endif
}

std::string PyDb2dVertex::className()
{
    return "AcDb2dVertex";
}

AcDb2dVertex* PyDb2dVertex::impObj() const
{
    return static_cast<AcDb2dVertex*>(m_pImp);
}


//-------------------------------------------------------------------------------------------------------------
//AcDb3dPolylineVertex
void makePyAcDb3dPolylineVertexWrapper()
{
    static auto wrapper = class_<PyDb3dPolylineVertex, bases<PyDbVertex>>("Db3dPolylineVertex")
        .def(init<>())
        .def(init<const AcGePoint3d&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("vertexType", &PyDb3dPolylineVertex::vertexType)
        .def("position", &PyDb3dPolylineVertex::position)
        .def("setPosition", &PyDb3dPolylineVertex::setPosition)
        .def("className", &PyDb3dPolylineVertex::className).staticmethod("className")
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
    : PyDbVertex(ptr,autoDelete)
{
}

PyDb3dPolylineVertex::PyDb3dPolylineVertex(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbVertex(nullptr, false)
{
    AcDb3dPolylineVertex* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDb3dPolylineVertex>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    m_pImp = pobj;
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
}

AcDb::Vertex3dType PyDb3dPolylineVertex::vertexType() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->vertexType();
}

AcGePoint3d PyDb3dPolylineVertex::position() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->position();
}

Acad::ErrorStatus PyDb3dPolylineVertex::setPosition(const AcGePoint3d& val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setPosition(val);
}

std::string PyDb3dPolylineVertex::className()
{
    return "AcDb3dPolylineVertex";
}

AcDb3dPolylineVertex* PyDb3dPolylineVertex::impObj() const
{
    return static_cast<AcDb3dPolylineVertex*>(m_pImp);
}

//-------------------------------------------------------------------------------------------------------------
//AcDbPolygonMeshVertex
void makePyAcDbPolygonMeshVertexWrapper()
{
    static auto wrapper = class_<PyDbPolygonMeshVertex, bases<PyDbVertex>>("DbPolygonMeshVertex")
        .def(init<>())
        .def(init<const AcGePoint3d&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("vertexType", &PyDbPolygonMeshVertex::vertexType)
        .def("position", &PyDbPolygonMeshVertex::position)
        .def("setPosition", &PyDbPolygonMeshVertex::setPosition)
        .def("className", &PyDbPolygonMeshVertex::className).staticmethod("className")
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
    : PyDbVertex(nullptr, false)
{
    AcDbPolygonMeshVertex* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbPolygonMeshVertex>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    m_pImp = pobj;
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
}

AcDb::Vertex3dType PyDbPolygonMeshVertex::vertexType() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->vertexType();
}

AcGePoint3d PyDbPolygonMeshVertex::position() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->position();
}

Acad::ErrorStatus PyDbPolygonMeshVertex::setPosition(const AcGePoint3d& val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setPosition(val);
}

std::string PyDbPolygonMeshVertex::className()
{
    return "AcDbPolygonMeshVertex";
}

AcDbPolygonMeshVertex* PyDbPolygonMeshVertex::impObj() const
{
    return static_cast<AcDbPolygonMeshVertex*>(m_pImp);
}

//-------------------------------------------------------------------------------------------------------------
//AcDbPolygonMeshVertex
void makePyDbPolyFaceMeshVertexWrapper()
{
    static auto wrapper = class_<PyDbPolyFaceMeshVertex, bases<PyDbVertex>>("DbPolyFaceMeshVertex")
        .def(init<>())
        .def(init<const AcGePoint3d&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("position", &PyDbPolyFaceMeshVertex::position)
        .def("setPosition", &PyDbPolyFaceMeshVertex::setPosition)
        .def("className", &PyDbPolyFaceMeshVertex::className).staticmethod("className")
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
    : PyDbVertex(nullptr, false)
{
    AcDbPolyFaceMeshVertex* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbPolyFaceMeshVertex>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    m_pImp = pobj;
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
}

AcGePoint3d PyDbPolyFaceMeshVertex::position() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->position();
}

Acad::ErrorStatus PyDbPolyFaceMeshVertex::setPosition(const AcGePoint3d& val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setPosition(val);
}

std::string PyDbPolyFaceMeshVertex::className()
{
    return "AcDbPolyFaceMeshVertex";
}

AcDbPolyFaceMeshVertex* PyDbPolyFaceMeshVertex::impObj() const
{
    return static_cast<AcDbPolyFaceMeshVertex*>(m_pImp);
}

//-------------------------------------------------------------------------------------------------------------
//AcDbFaceRecord

void makePyAcDbFaceRecordWrapper()
{
    static auto wrapper = class_<PyDbFaceRecord, bases<PyDbVertex>>("DbFaceRecord")
        .def(init<>())
        .def(init<Adesk::Int16, Adesk::Int16, Adesk::Int16, Adesk::Int16>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("getVertexAt", &PyDbFaceRecord::getVertexAt)
        .def("setVertexAt", &PyDbFaceRecord::setVertexAt)
        .def("isEdgeVisibleAt", &PyDbFaceRecord::isEdgeVisibleAt)
        .def("makeEdgeVisibleAt", &PyDbFaceRecord::makeEdgeVisibleAt)
        .def("makeEdgeInvisibleAt", &PyDbFaceRecord::makeEdgeInvisibleAt)
        .def("className", &PyDbFaceRecord::className).staticmethod("className")
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
    : PyDbVertex(ptr,autoDelete)
{
}

PyDbFaceRecord::PyDbFaceRecord(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbVertex(nullptr, false)
{
    AcDbFaceRecord* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbFaceRecord>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    m_pImp = pobj;
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
}

Adesk::Int16 PyDbFaceRecord::getVertexAt(Adesk::UInt16 faceIdx) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    Adesk::Int16 vtxIdx = 0;
    if(auto es = imp->getVertexAt(faceIdx,vtxIdx); es != eOk)
        throw PyAcadErrorStatus(es);
    return vtxIdx;
}

Acad::ErrorStatus PyDbFaceRecord::setVertexAt(Adesk::UInt16 faceIdx, Adesk::Int16 vtxIdx)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setVertexAt(faceIdx, vtxIdx);
}

Adesk::Boolean PyDbFaceRecord::isEdgeVisibleAt(Adesk::UInt16 faceIndex) const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    Adesk::Boolean flag = false;
    if (auto es = imp->isEdgeVisibleAt(faceIndex, flag); es != eOk)
        throw PyAcadErrorStatus(es);
    return flag;
}

Acad::ErrorStatus PyDbFaceRecord::makeEdgeVisibleAt(Adesk::UInt16 faceIndex)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->makeEdgeVisibleAt(faceIndex);
}

Acad::ErrorStatus PyDbFaceRecord::makeEdgeInvisibleAt(Adesk::UInt16 faceIndex)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->makeEdgeInvisibleAt(faceIndex);
}

std::string PyDbFaceRecord::className()
{
    return "AcDbFaceRecord";
}

AcDbFaceRecord* PyDbFaceRecord::impObj() const
{
    return static_cast<AcDbFaceRecord*>(m_pImp);
}

//-----------------------------------------------------------------------------------
//PyDbPoint
void makePyDbPointWrapper()
{
    static auto wrapper = class_<PyDbPoint, bases<PyDbEntity>>("DbPoint")
        .def(init<>())
        .def(init<AcGePoint3d&>())
        .def(init<const PyDbObjectId&, AcDb::OpenMode>())
        .def("position", &PyDbPoint::position)
        .def("setPosition", &PyDbPoint::setPosition)
        .def("thickness", &PyDbPoint::thickness)
        .def("setThickness", &PyDbPoint::setThickness)
        .def("normal", &PyDbPoint::normal)
        .def("setNormal", &PyDbPoint::setNormal)
        .def("ecsRotation", &PyDbPoint::ecsRotation)
        .def("setEcsRotation", &PyDbPoint::setEcsRotation)
        .def("isPlanar", &PyDbPoint::isPlanar)
        .def("className", &PyDbPoint::className).staticmethod("className")
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

PyDbPoint::PyDbPoint(AcDbPoint* ptr, bool autoDelete)
    : PyDbEntity(ptr, autoDelete)
{
}

PyDbPoint::PyDbPoint(const PyDbObjectId& id, AcDb::OpenMode mode)
    : PyDbEntity(nullptr, false)
{
    AcDbPoint* pobj = nullptr;
    if (auto es = acdbOpenObject<AcDbPoint>(pobj, id.m_id, mode); es != eOk)
        throw PyAcadErrorStatus(es);
    m_pImp = pobj;
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
}

AcGePoint3d PyDbPoint::position() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->position();
}

Acad::ErrorStatus PyDbPoint::setPosition(const AcGePoint3d& val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setPosition(val);
}

double PyDbPoint::thickness() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->thickness();
}

Acad::ErrorStatus PyDbPoint::setThickness(double val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setThickness(val);
}

AcGeVector3d PyDbPoint::normal() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->normal();
}

Acad::ErrorStatus PyDbPoint::setNormal(const AcGeVector3d& val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setNormal(val);
}

double PyDbPoint::ecsRotation() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->ecsRotation();
}

Acad::ErrorStatus PyDbPoint::setEcsRotation(double val)
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->setEcsRotation(val);
}

Adesk::Boolean PyDbPoint::isPlanar() const
{
    auto imp = impObj();
    if (imp == nullptr)
        throw PyNullObject();
    return imp->isPlanar();
}

std::string PyDbPoint::className()
{
    return "AcDbPoint";
}

AcDbPoint* PyDbPoint::impObj() const
{
    return static_cast<AcDbPoint*>(m_pImp);
}
