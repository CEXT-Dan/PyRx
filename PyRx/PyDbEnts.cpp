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

    scope enum_scope = class_<PyDbText>("DbText");

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
        .def(init<const AcGePoint3d&, const std::string&, const std::string&,const std::string&, const PyDbObjectId&>())
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
    : PyDbText(new AcDbAttribute(position, utf8_to_wstr(text).c_str(), utf8_to_wstr(tag).c_str(),style.m_id), true)
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
