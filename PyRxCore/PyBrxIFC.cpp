#include "stdafx.h"
#include "PyBrxIfc.h"

#ifdef BRXAPP
#include "ifc/EntitiesList.h"
#include "BrxSpecific/bim/ifc/IfcConstants.h"

using namespace boost::python;

//---------------------------------------------------------------------------------------- -
//PyIfcGuid
void makePyIfcGuidWrapper()
{
    PyDocString DS("IfcGuid");
    class_<PyIfcGuid>("IfcGuid")
        .def("getText", &PyIfcGuid::getText, DS.ARGS())
        .def("getBase64", &PyIfcGuid::getBase64, DS.ARGS())
        .def("create", &PyIfcGuid::create, DS.SARGS()).staticmethod("create")
        .def("createFromBase64", &PyIfcGuid::createFromBase64, DS.SARGS({ "val: str" })).staticmethod("createFromBase64")
        .def("createFromText", &PyIfcGuid::createFromText, DS.SARGS({ "val: str" })).staticmethod("createFromText")
        .def("className", &PyIfcGuid::className, DS.SARGS()).staticmethod("className")
        ;
}

PyIfcGuid::PyIfcGuid()
    : PyIfcGuid(new Ice::IfcApi::Guid(), true)
{
}

PyIfcGuid::PyIfcGuid(Ice::IfcApi::Guid* pObject, bool autoDelete)
    : m_pyImp(pObject, PySharedObjectDeleter<Ice::IfcApi::Guid>(autoDelete))
{
}

PyIfcGuid::PyIfcGuid(const Ice::IfcApi::Guid& pObject)
    : PyIfcGuid(new Ice::IfcApi::Guid(pObject), true)
{
}

const std::string PyIfcGuid::getBase64() const
{
    return std::string{ impObj()->getBase64() };
}

const std::string PyIfcGuid::getText() const
{
    return std::string{ impObj()->getText() };
}

PyIfcGuid PyIfcGuid::create()
{
    return PyIfcGuid(Ice::IfcApi::Guid::create());
}

PyIfcGuid PyIfcGuid::createFromBase64(const std::string& base64)
{
    return PyIfcGuid(Ice::IfcApi::Guid::createFromBase64(base64.c_str()));
}

PyIfcGuid PyIfcGuid::createFromText(const std::string& text)
{
    return PyIfcGuid(Ice::IfcApi::Guid::createFromText(text.c_str()));
}

std::string PyIfcGuid::className()
{
    return "IfcGuid";
}

Ice::IfcApi::Guid* PyIfcGuid::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<Ice::IfcApi::Guid*>(m_pyImp.get());
}


//---------------------------------------------------------------------------------------- -
//PyIfcString
void makePyIfcStringWrapper()
{
    constexpr const std::string_view ctor = "Overloads:\n"
        "- None: Any\n"
        "- text: str\n";

    PyDocString DS("IfcString");
    class_<PyIfcString>("IfcString")
        .def(init<>())
        .def(init<const std::string&>(DS.CTOR(ctor)))
        .def("getEncoded", &PyIfcString::getEncoded, DS.ARGS())
        .def("c_str", &PyIfcString::c_str, DS.ARGS())
        .def("isEmpty", &PyIfcString::isEmpty, DS.ARGS())
        .def("setEmpty", &PyIfcString::setEmpty, DS.ARGS())
        .def("decode", &PyIfcString::decode, DS.SARGS({ "val: str" })).staticmethod("decode")
        .def("className", &PyIfcString::className, DS.SARGS()).staticmethod("className")
        ;
}

PyIfcString::PyIfcString()
    : PyIfcString(new Ice::IfcApi::String(), true)
{
}

PyIfcString::PyIfcString(Ice::IfcApi::String* pObject, bool autoDelete)
    : m_pyImp(pObject, PySharedObjectDeleter<Ice::IfcApi::String>(autoDelete))
{
}

PyIfcString::PyIfcString(const Ice::IfcApi::String& pObject)
    : PyIfcString(new Ice::IfcApi::String(pObject), true)
{
}

PyIfcString::PyIfcString(const std::string& val)
    : PyIfcString(new Ice::IfcApi::String(utf8_to_wstr(val).c_str()), true)
{
}

const std::string PyIfcString::getEncoded() const
{
    return std::string{ impObj()->getEncoded() };
}

const std::string PyIfcString::c_str() const
{
    return  wstr_to_utf8(impObj()->c_str());
}

bool PyIfcString::isEmpty() const
{
    return impObj()->isEmpty();
}

void PyIfcString::setEmpty()
{
    impObj()->setEmpty();
}

PyIfcString PyIfcString::decode(const std::string& encoded)
{
    return PyIfcString(Ice::IfcApi::String::decode(encoded.c_str()));
}

std::string PyIfcString::className()
{
    return "IfcString";
}

Ice::IfcApi::String* PyIfcString::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<Ice::IfcApi::String*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
//PyIfcBinary
void makePyIfcBinaryWrapper()
{
    PyDocString DS("IfcBinary");
    class_<PyIfcBinary>("IfcBinary")
        .def("getEncodedString", &PyIfcBinary::getEncodedString)
        .def("reset", &PyIfcBinary::reset, DS.ARGS({ "val: str" }))
        .def("numBits", &PyIfcBinary::numBits, DS.ARGS())
        .def("getBit", &PyIfcBinary::getBit, DS.ARGS({ "val: int" }))
        .def("isEmpty", &PyIfcBinary::isEmpty, DS.ARGS())
        .def("resize", &PyIfcBinary::resize, DS.ARGS({ "val: int" }))
        .def("clear", &PyIfcBinary::clear, DS.ARGS())
        .def("className", &PyIfcBinary::className, DS.SARGS()).staticmethod("className")
        ;
}

PyIfcBinary::PyIfcBinary()
    : PyIfcBinary(new Ice::IfcApi::Binary(), true)
{
}

PyIfcBinary::PyIfcBinary(Ice::IfcApi::Binary* pObject, bool autoDelete)
    : m_pyImp(pObject, PySharedObjectDeleter<Ice::IfcApi::Binary>(autoDelete))
{
}

PyIfcBinary::PyIfcBinary(const Ice::IfcApi::Binary& other)
    : PyIfcBinary(new Ice::IfcApi::Binary(other), true)
{
}

std::string PyIfcBinary::getEncodedString() const
{
    return std::string{ impObj()->getEncodedString() };
}

void PyIfcBinary::reset(const std::string& encodedStr)
{
    impObj()->reset(encodedStr.c_str());
}

size_t PyIfcBinary::numBits() const
{
    return impObj()->numBits();
}

bool PyIfcBinary::getBit(size_t i) const
{
    return impObj()->getBit(i);
}

bool PyIfcBinary::isEmpty() const
{
    return impObj()->isEmpty();
}

void PyIfcBinary::resize(size_t nBits)
{
    impObj()->resize(nBits);
}

void PyIfcBinary::clear()
{
    impObj()->clear();
}

std::string PyIfcBinary::className()
{
    return "IfcBinary";
}

Ice::IfcApi::Binary* PyIfcBinary::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<Ice::IfcApi::Binary*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
//PyIfcLogical
void makePyIfcLogicalWrapper()
{
    PyDocString DS("IfcLogical");
    class_<PyIfcLogical>("IfcLogical")
        .def("isKnown", &PyIfcLogical::isKnown, DS.ARGS())
        .def("isUnknown", &PyIfcLogical::isUnknown, DS.ARGS())
        .def("className", &PyIfcLogical::className, DS.SARGS()).staticmethod("className")
        ;
}

PyIfcLogical::PyIfcLogical()
    : PyIfcLogical(new Ice::IfcApi::Logical(), true)
{
}

PyIfcLogical::PyIfcLogical(Ice::IfcApi::Logical* pObject, bool autoDelete)
    : m_pyImp(pObject, PySharedObjectDeleter<Ice::IfcApi::Logical>(autoDelete))
{
}

PyIfcLogical::PyIfcLogical(const Ice::IfcApi::Logical& other)
    : PyIfcLogical(new Ice::IfcApi::Logical(), true)
{

}

bool PyIfcLogical::isKnown() const
{
    return impObj()->isKnown();
}

bool PyIfcLogical::isUnknown() const
{
    return impObj()->isUnknown();
}

std::string PyIfcLogical::className()
{
    return "IfcLogical";
}

Ice::IfcApi::Logical* PyIfcLogical::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<Ice::IfcApi::Logical*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
//PyIfcVectorDesc
void makePyIfcVectorDescWrapper()
{
    PyDocString DS("IfcVectorDesc");
    class_<PyIfcVectorDesc>("IfcVectorDesc")
        .def("className", &PyIfcVectorDesc::className, DS.SARGS()).staticmethod("className")
        ;
}

PyIfcVectorDesc::PyIfcVectorDesc()
    : PyIfcVectorDesc(new Ice::IfcApi::VectorDesc(), true)
{
}

PyIfcVectorDesc::PyIfcVectorDesc(Ice::IfcApi::VectorDesc* pObject, bool autoDelete)
    : m_pyImp(pObject, PySharedObjectDeleter<Ice::IfcApi::VectorDesc>(autoDelete))
{
}

std::string PyIfcVectorDesc::className()
{
    return "IfcVectorDesc";
}

Ice::IfcApi::VectorDesc* PyIfcVectorDesc::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<Ice::IfcApi::VectorDesc*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
//PyIfcVectorValue
void makePyIfcVectorValueWrapper()
{
    PyDocString DS("IfcVectorValue");
    class_<PyIfcVectorValue>("IfcVectorValue", no_init)
        .def("add", &PyIfcVectorValue::add, DS.ARGS({ "val: PyBrxBim.IfcVariant" }))
        .def("size", &PyIfcVectorValue::size, DS.ARGS())
        .def("remove", &PyIfcVectorValue::remove, DS.ARGS({ "val: int" }))
        .def("clear", &PyIfcVectorValue::clear, DS.ARGS())
        .def("isNull", &PyIfcVectorValue::isNull, DS.ARGS())
        .def("values", &PyIfcVectorValue::values, DS.ARGS())
        .def("className", &PyIfcVectorValue::className, DS.SARGS()).staticmethod("className")
        ;
}

PyIfcVectorValue::PyIfcVectorValue(const Ice::IfcApi::VectorValue& src)
    : PyIfcVectorValue(new Ice::IfcApi::VectorValue(src), true)
{
}

PyIfcVectorValue::PyIfcVectorValue(Ice::IfcApi::VectorValue* pObject, bool autoDelete)
    : m_pyImp(pObject, PySharedObjectDeleter<Ice::IfcApi::VectorValue>(autoDelete))
{
}

Ice::IfcApi::Result PyIfcVectorValue::add(const PyIfcVariant& value)
{
    return impObj()->add(value.impObj());
}

unsigned int PyIfcVectorValue::size() const
{
    return impObj()->size();
}

bool PyIfcVectorValue::remove(unsigned int index)
{
    return impObj()->remove(index);
}

void PyIfcVectorValue::clear()
{
    impObj()->clear();
}

bool PyIfcVectorValue::isNull() const
{
    return impObj()->isNull();
}

boost::python::list PyIfcVectorValue::values() const
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (auto it = impObj()->begin(); it != impObj()->end(); ++it)
        pylist.append(PyIfcVariant(*it));
    return pylist;
}

std::string PyIfcVectorValue::className()
{
    return "IfcVectorValue";
}

Ice::IfcApi::VectorValue* PyIfcVectorValue::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<Ice::IfcApi::VectorValue*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
//PyIfcSelectorDesc
void makePyIfcSelectorDescWrapper()
{
    PyDocString DS("IfcSelectorDesc");
    class_<PyIfcSelectorDesc>("IfcSelectorDesc")
        .def("className", &PyIfcSelectorDesc::className, DS.SARGS()).staticmethod("className")
        ;
}

PyIfcSelectorDesc::PyIfcSelectorDesc()
    : PyIfcSelectorDesc(new Ice::IfcApi::SelectorDesc(), true)
{
}

PyIfcSelectorDesc::PyIfcSelectorDesc(Ice::IfcApi::SelectorDesc* pObject, bool autoDelete)
    : m_pyImp(pObject, PySharedObjectDeleter<Ice::IfcApi::SelectorDesc>(autoDelete))
{
}

std::string PyIfcSelectorDesc::className()
{
    return "IfcSelectorDesc";
}

Ice::IfcApi::SelectorDesc* PyIfcSelectorDesc::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<Ice::IfcApi::SelectorDesc*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
//PyIfcSelectValue
void makePyIfcSelectValueWrapper()
{
    PyDocString DS("IfcSelectValue");
    class_<PyIfcSelectValue>("IfcSelectValue", no_init)
        .def("getValue", &PyIfcSelectValue::getValue, DS.ARGS())
        .def("tag", &PyIfcSelectValue::tag, DS.ARGS())
        .def("setValue", &PyIfcSelectValue::tag, DS.ARGS({ "tag: str","val: PyBrxBim.IfcVariant" }))
        .def("isNull", &PyIfcSelectValue::isNull, DS.ARGS())
        .def("className", &PyIfcSelectValue::className, DS.SARGS()).staticmethod("className")
        ;
}

PyIfcSelectValue::PyIfcSelectValue(const Ice::IfcApi::SelectValue& src)
    : PyIfcSelectValue(new Ice::IfcApi::SelectValue(src), true)
{
}

PyIfcSelectValue::PyIfcSelectValue(Ice::IfcApi::SelectValue* pObject, bool autoDelete)
    : m_pyImp(pObject, PySharedObjectDeleter<Ice::IfcApi::SelectValue>(autoDelete))
{
}

PyIfcVariant PyIfcSelectValue::getValue() const
{
    return PyIfcVariant(impObj()->getValue());
}

std::string PyIfcSelectValue::tag() const
{
    return std::string(impObj()->tag());
}

Ice::IfcApi::Result PyIfcSelectValue::setValue(const std::string& tag, const PyIfcVariant& val)
{
    return impObj()->setValue(tag.c_str(), *val.impObj());
}

bool PyIfcSelectValue::isNull() const
{
    return impObj()->isNull();
}

std::string PyIfcSelectValue::className()
{
    return "IfcSelectValue";
}

Ice::IfcApi::SelectValue* PyIfcSelectValue::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<Ice::IfcApi::SelectValue*>(m_pyImp.get());
}


//---------------------------------------------------------------------------------------- -
//PyIfcEnumValue
void makePyIfcEnumValueWrapper()
{
    PyDocString DS("IfcEnumValue");
    class_<PyIfcEnumValue>("IfcEnumValue", no_init)
        .def("getValue", &PyIfcEnumValue::getValue, DS.ARGS())
        .def("setValue", &PyIfcEnumValue::setValue, DS.ARGS({ "val: str" }))
        .def("className", &PyIfcEnumValue::className, DS.SARGS()).staticmethod("className")
        ;
}

PyIfcEnumValue::PyIfcEnumValue(const Ice::IfcApi::EnumValue& src)
    : PyIfcEnumValue(new Ice::IfcApi::EnumValue(src), true)
{
}

PyIfcEnumValue::PyIfcEnumValue(Ice::IfcApi::EnumValue* pObject, bool autoDelete)
    : m_pyImp(pObject, PySharedObjectDeleter<Ice::IfcApi::EnumValue>(autoDelete))
{
}

std::string PyIfcEnumValue::getValue() const
{
    return std::string{ impObj()->getValue() };
}

void PyIfcEnumValue::setValue(const std::string& stringValue)
{
    impObj()->setValue(stringValue.c_str());
}

std::string PyIfcEnumValue::className()
{
    return "IfcEnumValue";
}

Ice::IfcApi::EnumValue* PyIfcEnumValue::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<Ice::IfcApi::EnumValue*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
//PyIfcEntityDesc
void makePyIfcEntityDescWrapper()
{
    PyDocString DS("IfcEntityDesc");
    class_<PyIfcEntityDesc>("IfcEntityDesc")
        .def("isDerivedFrom", &PyIfcEntityDesc::isDerivedFrom, DS.ARGS({ "entDesc: PyBrxBim.IfcEntityDesc","eSchema: IfcSchemaId" }))
        .def("name", &PyIfcEntityDesc::name, DS.ARGS())

        .def("Ifc2DCompositeCurve", &PyIfcEntityDesc::Ifc2DCompositeCurve, DS.SARGS()).staticmethod("Ifc2DCompositeCurve")
        .def("IfcActionRequest", &PyIfcEntityDesc::IfcActionRequest, DS.SARGS()).staticmethod("IfcActionRequest")
        .def("IfcActor", &PyIfcEntityDesc::IfcActor, DS.SARGS()).staticmethod("IfcActor")
        .def("IfcActorRole", &PyIfcEntityDesc::IfcActorRole, DS.SARGS()).staticmethod("IfcActorRole")
        .def("IfcActuator", &PyIfcEntityDesc::IfcActuator, DS.SARGS()).staticmethod("IfcActuator")
        .def("IfcActuatorType", &PyIfcEntityDesc::IfcActuatorType, DS.SARGS()).staticmethod("IfcActuatorType")
        .def("IfcAddress", &PyIfcEntityDesc::IfcAddress, DS.SARGS()).staticmethod("IfcAddress")
        .def("IfcAdvancedBrep", &PyIfcEntityDesc::IfcAdvancedBrep, DS.SARGS()).staticmethod("IfcAdvancedBrep")
        .def("IfcAdvancedBrepWithVoids", &PyIfcEntityDesc::IfcAdvancedBrepWithVoids, DS.SARGS()).staticmethod("IfcAdvancedBrepWithVoids")
        .def("IfcAdvancedFace", &PyIfcEntityDesc::IfcAdvancedFace, DS.SARGS()).staticmethod("IfcAdvancedFace")
        .def("IfcAirTerminal", &PyIfcEntityDesc::IfcAirTerminal, DS.SARGS()).staticmethod("IfcAirTerminal")
        .def("IfcAirTerminalBox", &PyIfcEntityDesc::IfcAirTerminalBox, DS.SARGS()).staticmethod("IfcAirTerminalBox")
        .def("IfcAirTerminalBoxType", &PyIfcEntityDesc::IfcAirTerminalBoxType, DS.SARGS()).staticmethod("IfcAirTerminalBoxType")
        .def("IfcAirTerminalType", &PyIfcEntityDesc::IfcAirTerminalType, DS.SARGS()).staticmethod("IfcAirTerminalType")
        .def("IfcAirToAirHeatRecovery", &PyIfcEntityDesc::IfcAirToAirHeatRecovery, DS.SARGS()).staticmethod("IfcAirToAirHeatRecovery")
        .def("IfcAirToAirHeatRecoveryType", &PyIfcEntityDesc::IfcAirToAirHeatRecoveryType, DS.SARGS()).staticmethod("IfcAirToAirHeatRecoveryType")
        .def("IfcAlarm", &PyIfcEntityDesc::IfcAlarm, DS.SARGS()).staticmethod("IfcAlarm")
        .def("IfcAlarmType", &PyIfcEntityDesc::IfcAlarmType, DS.SARGS()).staticmethod("IfcAlarmType")
        .def("IfcAlignment", &PyIfcEntityDesc::IfcAlignment, DS.SARGS()).staticmethod("IfcAlignment")
        .def("IfcAlignment2DHorizontal", &PyIfcEntityDesc::IfcAlignment2DHorizontal, DS.SARGS()).staticmethod("IfcAlignment2DHorizontal")
        .def("IfcAlignment2DHorizontalSegment", &PyIfcEntityDesc::IfcAlignment2DHorizontalSegment, DS.SARGS()).staticmethod("IfcAlignment2DHorizontalSegment")
        .def("IfcAlignment2DSegment", &PyIfcEntityDesc::IfcAlignment2DSegment, DS.SARGS()).staticmethod("IfcAlignment2DSegment")
        .def("IfcAlignment2DVerSegCircularArc", &PyIfcEntityDesc::IfcAlignment2DVerSegCircularArc, DS.SARGS()).staticmethod("IfcAlignment2DVerSegCircularArc")
        .def("IfcAlignment2DVerSegLine", &PyIfcEntityDesc::IfcAlignment2DVerSegLine, DS.SARGS()).staticmethod("IfcAlignment2DVerSegLine")
        .def("IfcAlignment2DVerSegParabolicArc", &PyIfcEntityDesc::IfcAlignment2DVerSegParabolicArc, DS.SARGS()).staticmethod("IfcAlignment2DVerSegParabolicArc")
        .def("IfcAlignment2DVertical", &PyIfcEntityDesc::IfcAlignment2DVertical, DS.SARGS()).staticmethod("IfcAlignment2DVertical")
        .def("IfcAlignment2DVerticalSegment", &PyIfcEntityDesc::IfcAlignment2DVerticalSegment, DS.SARGS()).staticmethod("IfcAlignment2DVerticalSegment")
        .def("IfcAlignmentCurve", &PyIfcEntityDesc::IfcAlignmentCurve, DS.SARGS()).staticmethod("IfcAlignmentCurve")
        .def("IfcAngularDimension", &PyIfcEntityDesc::IfcAngularDimension, DS.SARGS()).staticmethod("IfcAngularDimension")
        .def("IfcAnnotation", &PyIfcEntityDesc::IfcAnnotation, DS.SARGS()).staticmethod("IfcAnnotation")
        .def("IfcAnnotationCurveOccurrence", &PyIfcEntityDesc::IfcAnnotationCurveOccurrence, DS.SARGS()).staticmethod("IfcAnnotationCurveOccurrence")
        .def("IfcAnnotationFillArea", &PyIfcEntityDesc::IfcAnnotationFillArea, DS.SARGS()).staticmethod("IfcAnnotationFillArea")
        .def("IfcAnnotationFillAreaOccurrence", &PyIfcEntityDesc::IfcAnnotationFillAreaOccurrence, DS.SARGS()).staticmethod("IfcAnnotationFillAreaOccurrence")
        .def("IfcAnnotationOccurrence", &PyIfcEntityDesc::IfcAnnotationOccurrence, DS.SARGS()).staticmethod("IfcAnnotationOccurrence")
        .def("IfcAnnotationSurface", &PyIfcEntityDesc::IfcAnnotationSurface, DS.SARGS()).staticmethod("IfcAnnotationSurface")
        .def("IfcAnnotationSurfaceOccurrence", &PyIfcEntityDesc::IfcAnnotationSurfaceOccurrence, DS.SARGS()).staticmethod("IfcAnnotationSurfaceOccurrence")
        .def("IfcAnnotationSymbolOccurrence", &PyIfcEntityDesc::IfcAnnotationSymbolOccurrence, DS.SARGS()).staticmethod("IfcAnnotationSymbolOccurrence")
        .def("IfcAnnotationTextOccurrence", &PyIfcEntityDesc::IfcAnnotationTextOccurrence, DS.SARGS()).staticmethod("IfcAnnotationTextOccurrence")
        .def("IfcApplication", &PyIfcEntityDesc::IfcApplication, DS.SARGS()).staticmethod("IfcApplication")
        .def("IfcAppliedValue", &PyIfcEntityDesc::IfcAppliedValue, DS.SARGS()).staticmethod("IfcAppliedValue")
        .def("IfcAppliedValueRelationship", &PyIfcEntityDesc::IfcAppliedValueRelationship, DS.SARGS()).staticmethod("IfcAppliedValueRelationship")
        .def("IfcApproval", &PyIfcEntityDesc::IfcApproval, DS.SARGS()).staticmethod("IfcApproval")
        .def("IfcApprovalActorRelationship", &PyIfcEntityDesc::IfcApprovalActorRelationship, DS.SARGS()).staticmethod("IfcApprovalActorRelationship")
        .def("IfcApprovalPropertyRelationship", &PyIfcEntityDesc::IfcApprovalPropertyRelationship, DS.SARGS()).staticmethod("IfcApprovalPropertyRelationship")
        .def("IfcApprovalRelationship", &PyIfcEntityDesc::IfcApprovalRelationship, DS.SARGS()).staticmethod("IfcApprovalRelationship")
        .def("IfcArbitraryClosedProfileDef", &PyIfcEntityDesc::IfcArbitraryClosedProfileDef, DS.SARGS()).staticmethod("IfcArbitraryClosedProfileDef")
        .def("IfcArbitraryOpenProfileDef", &PyIfcEntityDesc::IfcArbitraryOpenProfileDef, DS.SARGS()).staticmethod("IfcArbitraryOpenProfileDef")
        .def("IfcArbitraryProfileDefWithVoids", &PyIfcEntityDesc::IfcArbitraryProfileDefWithVoids, DS.SARGS()).staticmethod("IfcArbitraryProfileDefWithVoids")
        .def("IfcAsset", &PyIfcEntityDesc::IfcAsset, DS.SARGS()).staticmethod("IfcAsset")
        .def("IfcAsymmetricIShapeProfileDef", &PyIfcEntityDesc::IfcAsymmetricIShapeProfileDef, DS.SARGS()).staticmethod("IfcAsymmetricIShapeProfileDef")
        .def("IfcAudioVisualAppliance", &PyIfcEntityDesc::IfcAudioVisualAppliance, DS.SARGS()).staticmethod("IfcAudioVisualAppliance")
        .def("IfcAudioVisualApplianceType", &PyIfcEntityDesc::IfcAudioVisualApplianceType, DS.SARGS()).staticmethod("IfcAudioVisualApplianceType")
        .def("IfcAxis1Placement", &PyIfcEntityDesc::IfcAxis1Placement, DS.SARGS()).staticmethod("IfcAxis1Placement")
        .def("IfcAxis2Placement2D", &PyIfcEntityDesc::IfcAxis2Placement2D, DS.SARGS()).staticmethod("IfcAxis2Placement2D")
        .def("IfcAxis2Placement3D", &PyIfcEntityDesc::IfcAxis2Placement3D, DS.SARGS()).staticmethod("IfcAxis2Placement3D")
        .def("IfcBSplineCurve", &PyIfcEntityDesc::IfcBSplineCurve, DS.SARGS()).staticmethod("IfcBSplineCurve")
        .def("IfcBSplineCurveWithKnots", &PyIfcEntityDesc::IfcBSplineCurveWithKnots, DS.SARGS()).staticmethod("IfcBSplineCurveWithKnots")
        .def("IfcBSplineSurface", &PyIfcEntityDesc::IfcBSplineSurface, DS.SARGS()).staticmethod("IfcBSplineSurface")
        .def("IfcBSplineSurfaceWithKnots", &PyIfcEntityDesc::IfcBSplineSurfaceWithKnots, DS.SARGS()).staticmethod("IfcBSplineSurfaceWithKnots")
        .def("IfcBeam", &PyIfcEntityDesc::IfcBeam, DS.SARGS()).staticmethod("IfcBeam")
        .def("IfcBeamStandardCase", &PyIfcEntityDesc::IfcBeamStandardCase, DS.SARGS()).staticmethod("IfcBeamStandardCase")
        .def("IfcBeamType", &PyIfcEntityDesc::IfcBeamType, DS.SARGS()).staticmethod("IfcBeamType")
        .def("IfcBezierCurve", &PyIfcEntityDesc::IfcBezierCurve, DS.SARGS()).staticmethod("IfcBezierCurve")
        .def("IfcBlobTexture", &PyIfcEntityDesc::IfcBlobTexture, DS.SARGS()).staticmethod("IfcBlobTexture")
        .def("IfcBlock", &PyIfcEntityDesc::IfcBlock, DS.SARGS()).staticmethod("IfcBlock")
        .def("IfcBoiler", &PyIfcEntityDesc::IfcBoiler, DS.SARGS()).staticmethod("IfcBoiler")
        .def("IfcBoilerType", &PyIfcEntityDesc::IfcBoilerType, DS.SARGS()).staticmethod("IfcBoilerType")
        .def("IfcBooleanClippingResult", &PyIfcEntityDesc::IfcBooleanClippingResult, DS.SARGS()).staticmethod("IfcBooleanClippingResult")
        .def("IfcBooleanResult", &PyIfcEntityDesc::IfcBooleanResult, DS.SARGS()).staticmethod("IfcBooleanResult")
        .def("IfcBoundaryCondition", &PyIfcEntityDesc::IfcBoundaryCondition, DS.SARGS()).staticmethod("IfcBoundaryCondition")
        .def("IfcBoundaryCurve", &PyIfcEntityDesc::IfcBoundaryCurve, DS.SARGS()).staticmethod("IfcBoundaryCurve")
        .def("IfcBoundaryEdgeCondition", &PyIfcEntityDesc::IfcBoundaryEdgeCondition, DS.SARGS()).staticmethod("IfcBoundaryEdgeCondition")
        .def("IfcBoundaryFaceCondition", &PyIfcEntityDesc::IfcBoundaryFaceCondition, DS.SARGS()).staticmethod("IfcBoundaryFaceCondition")
        .def("IfcBoundaryNodeCondition", &PyIfcEntityDesc::IfcBoundaryNodeCondition, DS.SARGS()).staticmethod("IfcBoundaryNodeCondition")
        .def("IfcBoundaryNodeConditionWarping", &PyIfcEntityDesc::IfcBoundaryNodeConditionWarping, DS.SARGS()).staticmethod("IfcBoundaryNodeConditionWarping")
        .def("IfcBoundedCurve", &PyIfcEntityDesc::IfcBoundedCurve, DS.SARGS()).staticmethod("IfcBoundedCurve")
        .def("IfcBoundedSurface", &PyIfcEntityDesc::IfcBoundedSurface, DS.SARGS()).staticmethod("IfcBoundedSurface")
        .def("IfcBoundingBox", &PyIfcEntityDesc::IfcBoundingBox, DS.SARGS()).staticmethod("IfcBoundingBox")
        .def("IfcBoxedHalfSpace", &PyIfcEntityDesc::IfcBoxedHalfSpace, DS.SARGS()).staticmethod("IfcBoxedHalfSpace")
        .def("IfcBuilding", &PyIfcEntityDesc::IfcBuilding, DS.SARGS()).staticmethod("IfcBuilding")
        .def("IfcBuildingElement", &PyIfcEntityDesc::IfcBuildingElement, DS.SARGS()).staticmethod("IfcBuildingElement")
        .def("IfcBuildingElementComponent", &PyIfcEntityDesc::IfcBuildingElementComponent, DS.SARGS()).staticmethod("IfcBuildingElementComponent")
        .def("IfcBuildingElementPart", &PyIfcEntityDesc::IfcBuildingElementPart, DS.SARGS()).staticmethod("IfcBuildingElementPart")
        .def("IfcBuildingElementPartType", &PyIfcEntityDesc::IfcBuildingElementPartType, DS.SARGS()).staticmethod("IfcBuildingElementPartType")
        .def("IfcBuildingElementProxy", &PyIfcEntityDesc::IfcBuildingElementProxy, DS.SARGS()).staticmethod("IfcBuildingElementProxy")
        .def("IfcBuildingElementProxyType", &PyIfcEntityDesc::IfcBuildingElementProxyType, DS.SARGS()).staticmethod("IfcBuildingElementProxyType")
        .def("IfcBuildingElementType", &PyIfcEntityDesc::IfcBuildingElementType, DS.SARGS()).staticmethod("IfcBuildingElementType")
        .def("IfcBuildingStorey", &PyIfcEntityDesc::IfcBuildingStorey, DS.SARGS()).staticmethod("IfcBuildingStorey")
        .def("IfcBuildingSystem", &PyIfcEntityDesc::IfcBuildingSystem, DS.SARGS()).staticmethod("IfcBuildingSystem")
        .def("IfcBurner", &PyIfcEntityDesc::IfcBurner, DS.SARGS()).staticmethod("IfcBurner")
        .def("IfcBurnerType", &PyIfcEntityDesc::IfcBurnerType, DS.SARGS()).staticmethod("IfcBurnerType")
        .def("IfcCShapeProfileDef", &PyIfcEntityDesc::IfcCShapeProfileDef, DS.SARGS()).staticmethod("IfcCShapeProfileDef")
        .def("IfcCableCarrierFitting", &PyIfcEntityDesc::IfcCableCarrierFitting, DS.SARGS()).staticmethod("IfcCableCarrierFitting")
        .def("IfcCableCarrierFittingType", &PyIfcEntityDesc::IfcCableCarrierFittingType, DS.SARGS()).staticmethod("IfcCableCarrierFittingType")
        .def("IfcCableCarrierSegment", &PyIfcEntityDesc::IfcCableCarrierSegment, DS.SARGS()).staticmethod("IfcCableCarrierSegment")
        .def("IfcCableCarrierSegmentType", &PyIfcEntityDesc::IfcCableCarrierSegmentType, DS.SARGS()).staticmethod("IfcCableCarrierSegmentType")
        .def("IfcCableFitting", &PyIfcEntityDesc::IfcCableFitting, DS.SARGS()).staticmethod("IfcCableFitting")
        .def("IfcCableFittingType", &PyIfcEntityDesc::IfcCableFittingType, DS.SARGS()).staticmethod("IfcCableFittingType")
        .def("IfcCableSegment", &PyIfcEntityDesc::IfcCableSegment, DS.SARGS()).staticmethod("IfcCableSegment")
        .def("IfcCableSegmentType", &PyIfcEntityDesc::IfcCableSegmentType, DS.SARGS()).staticmethod("IfcCableSegmentType")
        .def("IfcCalendarDate", &PyIfcEntityDesc::IfcCalendarDate, DS.SARGS()).staticmethod("IfcCalendarDate")
        .def("IfcCartesianPoint", &PyIfcEntityDesc::IfcCartesianPoint, DS.SARGS()).staticmethod("IfcCartesianPoint")
        .def("IfcCartesianPointList", &PyIfcEntityDesc::IfcCartesianPointList, DS.SARGS()).staticmethod("IfcCartesianPointList")
        .def("IfcCartesianPointList2D", &PyIfcEntityDesc::IfcCartesianPointList2D, DS.SARGS()).staticmethod("IfcCartesianPointList2D")
        .def("IfcCartesianPointList3D", &PyIfcEntityDesc::IfcCartesianPointList3D, DS.SARGS()).staticmethod("IfcCartesianPointList3D")
        .def("IfcCartesianTransformationOperator", &PyIfcEntityDesc::IfcCartesianTransformationOperator, DS.SARGS()).staticmethod("IfcCartesianTransformationOperator")
        .def("IfcCartesianTransformationOperator2D", &PyIfcEntityDesc::IfcCartesianTransformationOperator2D, DS.SARGS()).staticmethod("IfcCartesianTransformationOperator2D")
        .def("IfcCartesianTransformationOperator2DnonUniform", &PyIfcEntityDesc::IfcCartesianTransformationOperator2DnonUniform, DS.SARGS()).staticmethod("IfcCartesianTransformationOperator2DnonUniform")
        .def("IfcCartesianTransformationOperator3D", &PyIfcEntityDesc::IfcCartesianTransformationOperator3D, DS.SARGS()).staticmethod("IfcCartesianTransformationOperator3D")
        .def("IfcCartesianTransformationOperator3DnonUniform", &PyIfcEntityDesc::IfcCartesianTransformationOperator3DnonUniform, DS.SARGS()).staticmethod("IfcCartesianTransformationOperator3DnonUniform")
        .def("IfcCenterLineProfileDef", &PyIfcEntityDesc::IfcCenterLineProfileDef, DS.SARGS()).staticmethod("IfcCenterLineProfileDef")
        .def("IfcChamferEdgeFeature", &PyIfcEntityDesc::IfcChamferEdgeFeature, DS.SARGS()).staticmethod("IfcChamferEdgeFeature")
        .def("IfcChiller", &PyIfcEntityDesc::IfcChiller, DS.SARGS()).staticmethod("IfcChiller")
        .def("IfcChillerType", &PyIfcEntityDesc::IfcChillerType, DS.SARGS()).staticmethod("IfcChillerType")
        .def("IfcChimney", &PyIfcEntityDesc::IfcChimney, DS.SARGS()).staticmethod("IfcChimney")
        .def("IfcChimneyType", &PyIfcEntityDesc::IfcChimneyType, DS.SARGS()).staticmethod("IfcChimneyType")
        .def("IfcCircle", &PyIfcEntityDesc::IfcCircle, DS.SARGS()).staticmethod("IfcCircle")
        .def("IfcCircleHollowProfileDef", &PyIfcEntityDesc::IfcCircleHollowProfileDef, DS.SARGS()).staticmethod("IfcCircleHollowProfileDef")
        .def("IfcCircleProfileDef", &PyIfcEntityDesc::IfcCircleProfileDef, DS.SARGS()).staticmethod("IfcCircleProfileDef")
        .def("IfcCircularArcSegment2D", &PyIfcEntityDesc::IfcCircularArcSegment2D, DS.SARGS()).staticmethod("IfcCircularArcSegment2D")
        .def("IfcCivilElement", &PyIfcEntityDesc::IfcCivilElement, DS.SARGS()).staticmethod("IfcCivilElement")
        .def("IfcCivilElementType", &PyIfcEntityDesc::IfcCivilElementType, DS.SARGS()).staticmethod("IfcCivilElementType")
        .def("IfcClassification", &PyIfcEntityDesc::IfcClassification, DS.SARGS()).staticmethod("IfcClassification")
        .def("IfcClassificationItem", &PyIfcEntityDesc::IfcClassificationItem, DS.SARGS()).staticmethod("IfcClassificationItem")
        .def("IfcClassificationItemRelationship", &PyIfcEntityDesc::IfcClassificationItemRelationship, DS.SARGS()).staticmethod("IfcClassificationItemRelationship")
        .def("IfcClassificationNotation", &PyIfcEntityDesc::IfcClassificationNotation, DS.SARGS()).staticmethod("IfcClassificationNotation")
        .def("IfcClassificationNotationFacet", &PyIfcEntityDesc::IfcClassificationNotationFacet, DS.SARGS()).staticmethod("IfcClassificationNotationFacet")
        .def("IfcClassificationReference", &PyIfcEntityDesc::IfcClassificationReference, DS.SARGS()).staticmethod("IfcClassificationReference")
        .def("IfcClosedShell", &PyIfcEntityDesc::IfcClosedShell, DS.SARGS()).staticmethod("IfcClosedShell")
        .def("IfcCoil", &PyIfcEntityDesc::IfcCoil, DS.SARGS()).staticmethod("IfcCoil")
        .def("IfcCoilType", &PyIfcEntityDesc::IfcCoilType, DS.SARGS()).staticmethod("IfcCoilType")
        .def("IfcColourRgb", &PyIfcEntityDesc::IfcColourRgb, DS.SARGS()).staticmethod("IfcColourRgb")
        .def("IfcColourRgbList", &PyIfcEntityDesc::IfcColourRgbList, DS.SARGS()).staticmethod("IfcColourRgbList")
        .def("IfcColourSpecification", &PyIfcEntityDesc::IfcColourSpecification, DS.SARGS()).staticmethod("IfcColourSpecification")
        .def("IfcColumn", &PyIfcEntityDesc::IfcColumn, DS.SARGS()).staticmethod("IfcColumn")
        .def("IfcColumnStandardCase", &PyIfcEntityDesc::IfcColumnStandardCase, DS.SARGS()).staticmethod("IfcColumnStandardCase")
        .def("IfcColumnType", &PyIfcEntityDesc::IfcColumnType, DS.SARGS()).staticmethod("IfcColumnType")
        .def("IfcCommunicationsAppliance", &PyIfcEntityDesc::IfcCommunicationsAppliance, DS.SARGS()).staticmethod("IfcCommunicationsAppliance")
        .def("IfcCommunicationsApplianceType", &PyIfcEntityDesc::IfcCommunicationsApplianceType, DS.SARGS()).staticmethod("IfcCommunicationsApplianceType")
        .def("IfcComplexProperty", &PyIfcEntityDesc::IfcComplexProperty, DS.SARGS()).staticmethod("IfcComplexProperty")
        .def("IfcComplexPropertyTemplate", &PyIfcEntityDesc::IfcComplexPropertyTemplate, DS.SARGS()).staticmethod("IfcComplexPropertyTemplate")
        .def("IfcCompositeCurve", &PyIfcEntityDesc::IfcCompositeCurve, DS.SARGS()).staticmethod("IfcCompositeCurve")
        .def("IfcCompositeCurveOnSurface", &PyIfcEntityDesc::IfcCompositeCurveOnSurface, DS.SARGS()).staticmethod("IfcCompositeCurveOnSurface")
        .def("IfcCompositeCurveSegment", &PyIfcEntityDesc::IfcCompositeCurveSegment, DS.SARGS()).staticmethod("IfcCompositeCurveSegment")
        .def("IfcCompositeProfileDef", &PyIfcEntityDesc::IfcCompositeProfileDef, DS.SARGS()).staticmethod("IfcCompositeProfileDef")
        .def("IfcCompressor", &PyIfcEntityDesc::IfcCompressor, DS.SARGS()).staticmethod("IfcCompressor")
        .def("IfcCompressorType", &PyIfcEntityDesc::IfcCompressorType, DS.SARGS()).staticmethod("IfcCompressorType")
        .def("IfcCondenser", &PyIfcEntityDesc::IfcCondenser, DS.SARGS()).staticmethod("IfcCondenser")
        .def("IfcCondenserType", &PyIfcEntityDesc::IfcCondenserType, DS.SARGS()).staticmethod("IfcCondenserType")
        .def("IfcCondition", &PyIfcEntityDesc::IfcCondition, DS.SARGS()).staticmethod("IfcCondition")
        .def("IfcConditionCriterion", &PyIfcEntityDesc::IfcConditionCriterion, DS.SARGS()).staticmethod("IfcConditionCriterion")
        .def("IfcConic", &PyIfcEntityDesc::IfcConic, DS.SARGS()).staticmethod("IfcConic")
        .def("IfcConnectedFaceSet", &PyIfcEntityDesc::IfcConnectedFaceSet, DS.SARGS()).staticmethod("IfcConnectedFaceSet")
        .def("IfcConnectionCurveGeometry", &PyIfcEntityDesc::IfcConnectionCurveGeometry, DS.SARGS()).staticmethod("IfcConnectionCurveGeometry")
        .def("IfcConnectionGeometry", &PyIfcEntityDesc::IfcConnectionGeometry, DS.SARGS()).staticmethod("IfcConnectionGeometry")
        .def("IfcConnectionPointEccentricity", &PyIfcEntityDesc::IfcConnectionPointEccentricity, DS.SARGS()).staticmethod("IfcConnectionPointEccentricity")
        .def("IfcConnectionPointGeometry", &PyIfcEntityDesc::IfcConnectionPointGeometry, DS.SARGS()).staticmethod("IfcConnectionPointGeometry")
        .def("IfcConnectionPortGeometry", &PyIfcEntityDesc::IfcConnectionPortGeometry, DS.SARGS()).staticmethod("IfcConnectionPortGeometry")
        .def("IfcConnectionSurfaceGeometry", &PyIfcEntityDesc::IfcConnectionSurfaceGeometry, DS.SARGS()).staticmethod("IfcConnectionSurfaceGeometry")
        .def("IfcConnectionVolumeGeometry", &PyIfcEntityDesc::IfcConnectionVolumeGeometry, DS.SARGS()).staticmethod("IfcConnectionVolumeGeometry")
        .def("IfcConstraint", &PyIfcEntityDesc::IfcConstraint, DS.SARGS()).staticmethod("IfcConstraint")
        .def("IfcConstraintAggregationRelationship", &PyIfcEntityDesc::IfcConstraintAggregationRelationship, DS.SARGS()).staticmethod("IfcConstraintAggregationRelationship")
        .def("IfcConstraintClassificationRelationship", &PyIfcEntityDesc::IfcConstraintClassificationRelationship, DS.SARGS()).staticmethod("IfcConstraintClassificationRelationship")
        .def("IfcConstraintRelationship", &PyIfcEntityDesc::IfcConstraintRelationship, DS.SARGS()).staticmethod("IfcConstraintRelationship")
        .def("IfcConstructionEquipmentResource", &PyIfcEntityDesc::IfcConstructionEquipmentResource, DS.SARGS()).staticmethod("IfcConstructionEquipmentResource")
        .def("IfcConstructionEquipmentResourceType", &PyIfcEntityDesc::IfcConstructionEquipmentResourceType, DS.SARGS()).staticmethod("IfcConstructionEquipmentResourceType")
        .def("IfcConstructionMaterialResource", &PyIfcEntityDesc::IfcConstructionMaterialResource, DS.SARGS()).staticmethod("IfcConstructionMaterialResource")
        .def("IfcConstructionMaterialResourceType", &PyIfcEntityDesc::IfcConstructionMaterialResourceType, DS.SARGS()).staticmethod("IfcConstructionMaterialResourceType")
        .def("IfcConstructionProductResource", &PyIfcEntityDesc::IfcConstructionProductResource, DS.SARGS()).staticmethod("IfcConstructionProductResource")
        .def("IfcConstructionProductResourceType", &PyIfcEntityDesc::IfcConstructionProductResourceType, DS.SARGS()).staticmethod("IfcConstructionProductResourceType")
        .def("IfcConstructionResource", &PyIfcEntityDesc::IfcConstructionResource, DS.SARGS()).staticmethod("IfcConstructionResource")
        .def("IfcConstructionResourceType", &PyIfcEntityDesc::IfcConstructionResourceType, DS.SARGS()).staticmethod("IfcConstructionResourceType")
        .def("IfcContext", &PyIfcEntityDesc::IfcContext, DS.SARGS()).staticmethod("IfcContext")
        .def("IfcContextDependentUnit", &PyIfcEntityDesc::IfcContextDependentUnit, DS.SARGS()).staticmethod("IfcContextDependentUnit")
        .def("IfcControl", &PyIfcEntityDesc::IfcControl, DS.SARGS()).staticmethod("IfcControl")
        .def("IfcController", &PyIfcEntityDesc::IfcController, DS.SARGS()).staticmethod("IfcController")
        .def("IfcControllerType", &PyIfcEntityDesc::IfcControllerType, DS.SARGS()).staticmethod("IfcControllerType")
        .def("IfcConversionBasedUnit", &PyIfcEntityDesc::IfcConversionBasedUnit, DS.SARGS()).staticmethod("IfcConversionBasedUnit")
        .def("IfcConversionBasedUnitWithOffset", &PyIfcEntityDesc::IfcConversionBasedUnitWithOffset, DS.SARGS()).staticmethod("IfcConversionBasedUnitWithOffset")
        .def("IfcCooledBeam", &PyIfcEntityDesc::IfcCooledBeam, DS.SARGS()).staticmethod("IfcCooledBeam")
        .def("IfcCooledBeamType", &PyIfcEntityDesc::IfcCooledBeamType, DS.SARGS()).staticmethod("IfcCooledBeamType")
        .def("IfcCoolingTower", &PyIfcEntityDesc::IfcCoolingTower, DS.SARGS()).staticmethod("IfcCoolingTower")
        .def("IfcCoolingTowerType", &PyIfcEntityDesc::IfcCoolingTowerType, DS.SARGS()).staticmethod("IfcCoolingTowerType")
        .def("IfcCoordinateOperation", &PyIfcEntityDesc::IfcCoordinateOperation, DS.SARGS()).staticmethod("IfcCoordinateOperation")
        .def("IfcCoordinateReferenceSystem", &PyIfcEntityDesc::IfcCoordinateReferenceSystem, DS.SARGS()).staticmethod("IfcCoordinateReferenceSystem")
        .def("IfcCoordinatedUniversalTimeOffset", &PyIfcEntityDesc::IfcCoordinatedUniversalTimeOffset, DS.SARGS()).staticmethod("IfcCoordinatedUniversalTimeOffset")
        .def("IfcCostItem", &PyIfcEntityDesc::IfcCostItem, DS.SARGS()).staticmethod("IfcCostItem")
        .def("IfcCostSchedule", &PyIfcEntityDesc::IfcCostSchedule, DS.SARGS()).staticmethod("IfcCostSchedule")
        .def("IfcCostValue", &PyIfcEntityDesc::IfcCostValue, DS.SARGS()).staticmethod("IfcCostValue")
        .def("IfcCovering", &PyIfcEntityDesc::IfcCovering, DS.SARGS()).staticmethod("IfcCovering")
        .def("IfcCoveringType", &PyIfcEntityDesc::IfcCoveringType, DS.SARGS()).staticmethod("IfcCoveringType")
        .def("IfcCraneRailAShapeProfileDef", &PyIfcEntityDesc::IfcCraneRailAShapeProfileDef, DS.SARGS()).staticmethod("IfcCraneRailAShapeProfileDef")
        .def("IfcCraneRailFShapeProfileDef", &PyIfcEntityDesc::IfcCraneRailFShapeProfileDef, DS.SARGS()).staticmethod("IfcCraneRailFShapeProfileDef")
        .def("IfcCrewResource", &PyIfcEntityDesc::IfcCrewResource, DS.SARGS()).staticmethod("IfcCrewResource")
        .def("IfcCrewResourceType", &PyIfcEntityDesc::IfcCrewResourceType, DS.SARGS()).staticmethod("IfcCrewResourceType")
        .def("IfcCsgPrimitive3D", &PyIfcEntityDesc::IfcCsgPrimitive3D, DS.SARGS()).staticmethod("IfcCsgPrimitive3D")
        .def("IfcCsgSolid", &PyIfcEntityDesc::IfcCsgSolid, DS.SARGS()).staticmethod("IfcCsgSolid")
        .def("IfcCurrencyRelationship", &PyIfcEntityDesc::IfcCurrencyRelationship, DS.SARGS()).staticmethod("IfcCurrencyRelationship")
        .def("IfcCurtainWall", &PyIfcEntityDesc::IfcCurtainWall, DS.SARGS()).staticmethod("IfcCurtainWall")
        .def("IfcCurtainWallType", &PyIfcEntityDesc::IfcCurtainWallType, DS.SARGS()).staticmethod("IfcCurtainWallType")
        .def("IfcCurve", &PyIfcEntityDesc::IfcCurve, DS.SARGS()).staticmethod("IfcCurve")
        .def("IfcCurveBoundedPlane", &PyIfcEntityDesc::IfcCurveBoundedPlane, DS.SARGS()).staticmethod("IfcCurveBoundedPlane")
        .def("IfcCurveBoundedSurface", &PyIfcEntityDesc::IfcCurveBoundedSurface, DS.SARGS()).staticmethod("IfcCurveBoundedSurface")
        .def("IfcCurveSegment2D", &PyIfcEntityDesc::IfcCurveSegment2D, DS.SARGS()).staticmethod("IfcCurveSegment2D")
        .def("IfcCurveStyle", &PyIfcEntityDesc::IfcCurveStyle, DS.SARGS()).staticmethod("IfcCurveStyle")
        .def("IfcCurveStyleFont", &PyIfcEntityDesc::IfcCurveStyleFont, DS.SARGS()).staticmethod("IfcCurveStyleFont")
        .def("IfcCurveStyleFontAndScaling", &PyIfcEntityDesc::IfcCurveStyleFontAndScaling, DS.SARGS()).staticmethod("IfcCurveStyleFontAndScaling")
        .def("IfcCurveStyleFontPattern", &PyIfcEntityDesc::IfcCurveStyleFontPattern, DS.SARGS()).staticmethod("IfcCurveStyleFontPattern")
        .def("IfcCylindricalSurface", &PyIfcEntityDesc::IfcCylindricalSurface, DS.SARGS()).staticmethod("IfcCylindricalSurface")
        .def("IfcDamper", &PyIfcEntityDesc::IfcDamper, DS.SARGS()).staticmethod("IfcDamper")
        .def("IfcDamperType", &PyIfcEntityDesc::IfcDamperType, DS.SARGS()).staticmethod("IfcDamperType")
        .def("IfcDateAndTime", &PyIfcEntityDesc::IfcDateAndTime, DS.SARGS()).staticmethod("IfcDateAndTime")
        .def("IfcDefinedSymbol", &PyIfcEntityDesc::IfcDefinedSymbol, DS.SARGS()).staticmethod("IfcDefinedSymbol")
        .def("IfcDerivedProfileDef", &PyIfcEntityDesc::IfcDerivedProfileDef, DS.SARGS()).staticmethod("IfcDerivedProfileDef")
        .def("IfcDerivedUnit", &PyIfcEntityDesc::IfcDerivedUnit, DS.SARGS()).staticmethod("IfcDerivedUnit")
        .def("IfcDerivedUnitElement", &PyIfcEntityDesc::IfcDerivedUnitElement, DS.SARGS()).staticmethod("IfcDerivedUnitElement")
        .def("IfcDiameterDimension", &PyIfcEntityDesc::IfcDiameterDimension, DS.SARGS()).staticmethod("IfcDiameterDimension")
        .def("IfcDimensionCalloutRelationship", &PyIfcEntityDesc::IfcDimensionCalloutRelationship, DS.SARGS()).staticmethod("IfcDimensionCalloutRelationship")
        .def("IfcDimensionCurve", &PyIfcEntityDesc::IfcDimensionCurve, DS.SARGS()).staticmethod("IfcDimensionCurve")
        .def("IfcDimensionCurveDirectedCallout", &PyIfcEntityDesc::IfcDimensionCurveDirectedCallout, DS.SARGS()).staticmethod("IfcDimensionCurveDirectedCallout")
        .def("IfcDimensionCurveTerminator", &PyIfcEntityDesc::IfcDimensionCurveTerminator, DS.SARGS()).staticmethod("IfcDimensionCurveTerminator")
        .def("IfcDimensionPair", &PyIfcEntityDesc::IfcDimensionPair, DS.SARGS()).staticmethod("IfcDimensionPair")
        .def("IfcDimensionalExponents", &PyIfcEntityDesc::IfcDimensionalExponents, DS.SARGS()).staticmethod("IfcDimensionalExponents")
        .def("IfcDirection", &PyIfcEntityDesc::IfcDirection, DS.SARGS()).staticmethod("IfcDirection")
        .def("IfcDiscreteAccessory", &PyIfcEntityDesc::IfcDiscreteAccessory, DS.SARGS()).staticmethod("IfcDiscreteAccessory")
        .def("IfcDiscreteAccessoryType", &PyIfcEntityDesc::IfcDiscreteAccessoryType, DS.SARGS()).staticmethod("IfcDiscreteAccessoryType")
        .def("IfcDistanceExpression", &PyIfcEntityDesc::IfcDistanceExpression, DS.SARGS()).staticmethod("IfcDistanceExpression")
        .def("IfcDistributionChamberElement", &PyIfcEntityDesc::IfcDistributionChamberElement, DS.SARGS()).staticmethod("IfcDistributionChamberElement")
        .def("IfcDistributionChamberElementType", &PyIfcEntityDesc::IfcDistributionChamberElementType, DS.SARGS()).staticmethod("IfcDistributionChamberElementType")
        .def("IfcDistributionCircuit", &PyIfcEntityDesc::IfcDistributionCircuit, DS.SARGS()).staticmethod("IfcDistributionCircuit")
        .def("IfcDistributionControlElement", &PyIfcEntityDesc::IfcDistributionControlElement, DS.SARGS()).staticmethod("IfcDistributionControlElement")
        .def("IfcDistributionControlElementType", &PyIfcEntityDesc::IfcDistributionControlElementType, DS.SARGS()).staticmethod("IfcDistributionControlElementType")
        .def("IfcDistributionElement", &PyIfcEntityDesc::IfcDistributionElement, DS.SARGS()).staticmethod("IfcDistributionElement")
        .def("IfcDistributionElementType", &PyIfcEntityDesc::IfcDistributionElementType, DS.SARGS()).staticmethod("IfcDistributionElementType")
        .def("IfcDistributionFlowElement", &PyIfcEntityDesc::IfcDistributionFlowElement, DS.SARGS()).staticmethod("IfcDistributionFlowElement")
        .def("IfcDistributionFlowElementType", &PyIfcEntityDesc::IfcDistributionFlowElementType, DS.SARGS()).staticmethod("IfcDistributionFlowElementType")
        .def("IfcDistributionPort", &PyIfcEntityDesc::IfcDistributionPort, DS.SARGS()).staticmethod("IfcDistributionPort")
        .def("IfcDistributionSystem", &PyIfcEntityDesc::IfcDistributionSystem, DS.SARGS()).staticmethod("IfcDistributionSystem")
        .def("IfcDocumentElectronicFormat", &PyIfcEntityDesc::IfcDocumentElectronicFormat, DS.SARGS()).staticmethod("IfcDocumentElectronicFormat")
        .def("IfcDocumentInformation", &PyIfcEntityDesc::IfcDocumentInformation, DS.SARGS()).staticmethod("IfcDocumentInformation")
        .def("IfcDocumentInformationRelationship", &PyIfcEntityDesc::IfcDocumentInformationRelationship, DS.SARGS()).staticmethod("IfcDocumentInformationRelationship")
        .def("IfcDocumentReference", &PyIfcEntityDesc::IfcDocumentReference, DS.SARGS()).staticmethod("IfcDocumentReference")
        .def("IfcDoor", &PyIfcEntityDesc::IfcDoor, DS.SARGS()).staticmethod("IfcDoor")
        .def("IfcDoorLiningProperties", &PyIfcEntityDesc::IfcDoorLiningProperties, DS.SARGS()).staticmethod("IfcDoorLiningProperties")
        .def("IfcDoorPanelProperties", &PyIfcEntityDesc::IfcDoorPanelProperties, DS.SARGS()).staticmethod("IfcDoorPanelProperties")
        .def("IfcDoorStandardCase", &PyIfcEntityDesc::IfcDoorStandardCase, DS.SARGS()).staticmethod("IfcDoorStandardCase")
        .def("IfcDoorStyle", &PyIfcEntityDesc::IfcDoorStyle, DS.SARGS()).staticmethod("IfcDoorStyle")
        .def("IfcDoorType", &PyIfcEntityDesc::IfcDoorType, DS.SARGS()).staticmethod("IfcDoorType")
        .def("IfcDraughtingCallout", &PyIfcEntityDesc::IfcDraughtingCallout, DS.SARGS()).staticmethod("IfcDraughtingCallout")
        .def("IfcDraughtingCalloutRelationship", &PyIfcEntityDesc::IfcDraughtingCalloutRelationship, DS.SARGS()).staticmethod("IfcDraughtingCalloutRelationship")
        .def("IfcDraughtingPreDefinedColour", &PyIfcEntityDesc::IfcDraughtingPreDefinedColour, DS.SARGS()).staticmethod("IfcDraughtingPreDefinedColour")
        .def("IfcDraughtingPreDefinedCurveFont", &PyIfcEntityDesc::IfcDraughtingPreDefinedCurveFont, DS.SARGS()).staticmethod("IfcDraughtingPreDefinedCurveFont")
        .def("IfcDraughtingPreDefinedTextFont", &PyIfcEntityDesc::IfcDraughtingPreDefinedTextFont, DS.SARGS()).staticmethod("IfcDraughtingPreDefinedTextFont")
        .def("IfcDuctFitting", &PyIfcEntityDesc::IfcDuctFitting, DS.SARGS()).staticmethod("IfcDuctFitting")
        .def("IfcDuctFittingType", &PyIfcEntityDesc::IfcDuctFittingType, DS.SARGS()).staticmethod("IfcDuctFittingType")
        .def("IfcDuctSegment", &PyIfcEntityDesc::IfcDuctSegment, DS.SARGS()).staticmethod("IfcDuctSegment")
        .def("IfcDuctSegmentType", &PyIfcEntityDesc::IfcDuctSegmentType, DS.SARGS()).staticmethod("IfcDuctSegmentType")
        .def("IfcDuctSilencer", &PyIfcEntityDesc::IfcDuctSilencer, DS.SARGS()).staticmethod("IfcDuctSilencer")
        .def("IfcDuctSilencerType", &PyIfcEntityDesc::IfcDuctSilencerType, DS.SARGS()).staticmethod("IfcDuctSilencerType")
        .def("IfcEdge", &PyIfcEntityDesc::IfcEdge, DS.SARGS()).staticmethod("IfcEdge")
        .def("IfcEdgeCurve", &PyIfcEntityDesc::IfcEdgeCurve, DS.SARGS()).staticmethod("IfcEdgeCurve")
        .def("IfcEdgeFeature", &PyIfcEntityDesc::IfcEdgeFeature, DS.SARGS()).staticmethod("IfcEdgeFeature")
        .def("IfcEdgeLoop", &PyIfcEntityDesc::IfcEdgeLoop, DS.SARGS()).staticmethod("IfcEdgeLoop")
        .def("IfcElectricAppliance", &PyIfcEntityDesc::IfcElectricAppliance, DS.SARGS()).staticmethod("IfcElectricAppliance")
        .def("IfcElectricApplianceType", &PyIfcEntityDesc::IfcElectricApplianceType, DS.SARGS()).staticmethod("IfcElectricApplianceType")
        .def("IfcElectricDistributionBoard", &PyIfcEntityDesc::IfcElectricDistributionBoard, DS.SARGS()).staticmethod("IfcElectricDistributionBoard")
        .def("IfcElectricDistributionBoardType", &PyIfcEntityDesc::IfcElectricDistributionBoardType, DS.SARGS()).staticmethod("IfcElectricDistributionBoardType")
        .def("IfcElectricDistributionPoint", &PyIfcEntityDesc::IfcElectricDistributionPoint, DS.SARGS()).staticmethod("IfcElectricDistributionPoint")
        .def("IfcElectricFlowStorageDevice", &PyIfcEntityDesc::IfcElectricFlowStorageDevice, DS.SARGS()).staticmethod("IfcElectricFlowStorageDevice")
        .def("IfcElectricFlowStorageDeviceType", &PyIfcEntityDesc::IfcElectricFlowStorageDeviceType, DS.SARGS()).staticmethod("IfcElectricFlowStorageDeviceType")
        .def("IfcElectricGenerator", &PyIfcEntityDesc::IfcElectricGenerator, DS.SARGS()).staticmethod("IfcElectricGenerator")
        .def("IfcElectricGeneratorType", &PyIfcEntityDesc::IfcElectricGeneratorType, DS.SARGS()).staticmethod("IfcElectricGeneratorType")
        .def("IfcElectricHeaterType", &PyIfcEntityDesc::IfcElectricHeaterType, DS.SARGS()).staticmethod("IfcElectricHeaterType")
        .def("IfcElectricMotor", &PyIfcEntityDesc::IfcElectricMotor, DS.SARGS()).staticmethod("IfcElectricMotor")
        .def("IfcElectricMotorType", &PyIfcEntityDesc::IfcElectricMotorType, DS.SARGS()).staticmethod("IfcElectricMotorType")
        .def("IfcElectricTimeControl", &PyIfcEntityDesc::IfcElectricTimeControl, DS.SARGS()).staticmethod("IfcElectricTimeControl")
        .def("IfcElectricTimeControlType", &PyIfcEntityDesc::IfcElectricTimeControlType, DS.SARGS()).staticmethod("IfcElectricTimeControlType")
        .def("IfcElectricalBaseProperties", &PyIfcEntityDesc::IfcElectricalBaseProperties, DS.SARGS()).staticmethod("IfcElectricalBaseProperties")
        .def("IfcElectricalCircuit", &PyIfcEntityDesc::IfcElectricalCircuit, DS.SARGS()).staticmethod("IfcElectricalCircuit")
        .def("IfcElectricalElement", &PyIfcEntityDesc::IfcElectricalElement, DS.SARGS()).staticmethod("IfcElectricalElement")
        .def("IfcElement", &PyIfcEntityDesc::IfcElement, DS.SARGS()).staticmethod("IfcElement")
        .def("IfcElementAssembly", &PyIfcEntityDesc::IfcElementAssembly, DS.SARGS()).staticmethod("IfcElementAssembly")
        .def("IfcElementAssemblyType", &PyIfcEntityDesc::IfcElementAssemblyType, DS.SARGS()).staticmethod("IfcElementAssemblyType")
        .def("IfcElementComponent", &PyIfcEntityDesc::IfcElementComponent, DS.SARGS()).staticmethod("IfcElementComponent")
        .def("IfcElementComponentType", &PyIfcEntityDesc::IfcElementComponentType, DS.SARGS()).staticmethod("IfcElementComponentType")
        .def("IfcElementQuantity", &PyIfcEntityDesc::IfcElementQuantity, DS.SARGS()).staticmethod("IfcElementQuantity")
        .def("IfcElementType", &PyIfcEntityDesc::IfcElementType, DS.SARGS()).staticmethod("IfcElementType")
        .def("IfcElementarySurface", &PyIfcEntityDesc::IfcElementarySurface, DS.SARGS()).staticmethod("IfcElementarySurface")
        .def("IfcEllipse", &PyIfcEntityDesc::IfcEllipse, DS.SARGS()).staticmethod("IfcEllipse")
        .def("IfcEllipseProfileDef", &PyIfcEntityDesc::IfcEllipseProfileDef, DS.SARGS()).staticmethod("IfcEllipseProfileDef")
        .def("IfcEnergyConversionDevice", &PyIfcEntityDesc::IfcEnergyConversionDevice, DS.SARGS()).staticmethod("IfcEnergyConversionDevice")
        .def("IfcEnergyConversionDeviceType", &PyIfcEntityDesc::IfcEnergyConversionDeviceType, DS.SARGS()).staticmethod("IfcEnergyConversionDeviceType")
        .def("IfcEnergyProperties", &PyIfcEntityDesc::IfcEnergyProperties, DS.SARGS()).staticmethod("IfcEnergyProperties")
        .def("IfcEngine", &PyIfcEntityDesc::IfcEngine, DS.SARGS()).staticmethod("IfcEngine")
        .def("IfcEngineType", &PyIfcEntityDesc::IfcEngineType, DS.SARGS()).staticmethod("IfcEngineType")
        .def("IfcEnvironmentalImpactValue", &PyIfcEntityDesc::IfcEnvironmentalImpactValue, DS.SARGS()).staticmethod("IfcEnvironmentalImpactValue")
        .def("IfcEquipmentElement", &PyIfcEntityDesc::IfcEquipmentElement, DS.SARGS()).staticmethod("IfcEquipmentElement")
        .def("IfcEquipmentStandard", &PyIfcEntityDesc::IfcEquipmentStandard, DS.SARGS()).staticmethod("IfcEquipmentStandard")
        .def("IfcEvaporativeCooler", &PyIfcEntityDesc::IfcEvaporativeCooler, DS.SARGS()).staticmethod("IfcEvaporativeCooler")
        .def("IfcEvaporativeCoolerType", &PyIfcEntityDesc::IfcEvaporativeCoolerType, DS.SARGS()).staticmethod("IfcEvaporativeCoolerType")
        .def("IfcEvaporator", &PyIfcEntityDesc::IfcEvaporator, DS.SARGS()).staticmethod("IfcEvaporator")
        .def("IfcEvaporatorType", &PyIfcEntityDesc::IfcEvaporatorType, DS.SARGS()).staticmethod("IfcEvaporatorType")
        .def("IfcEvent", &PyIfcEntityDesc::IfcEvent, DS.SARGS()).staticmethod("IfcEvent")
        .def("IfcEventTime", &PyIfcEntityDesc::IfcEventTime, DS.SARGS()).staticmethod("IfcEventTime")
        .def("IfcEventType", &PyIfcEntityDesc::IfcEventType, DS.SARGS()).staticmethod("IfcEventType")
        .def("IfcExtendedMaterialProperties", &PyIfcEntityDesc::IfcExtendedMaterialProperties, DS.SARGS()).staticmethod("IfcExtendedMaterialProperties")
        .def("IfcExtendedProperties", &PyIfcEntityDesc::IfcExtendedProperties, DS.SARGS()).staticmethod("IfcExtendedProperties")
        .def("IfcExternalInformation", &PyIfcEntityDesc::IfcExternalInformation, DS.SARGS()).staticmethod("IfcExternalInformation")
        .def("IfcExternalReference", &PyIfcEntityDesc::IfcExternalReference, DS.SARGS()).staticmethod("IfcExternalReference")
        .def("IfcExternalReferenceRelationship", &PyIfcEntityDesc::IfcExternalReferenceRelationship, DS.SARGS()).staticmethod("IfcExternalReferenceRelationship")
        .def("IfcExternalSpatialElement", &PyIfcEntityDesc::IfcExternalSpatialElement, DS.SARGS()).staticmethod("IfcExternalSpatialElement")
        .def("IfcExternalSpatialStructureElement", &PyIfcEntityDesc::IfcExternalSpatialStructureElement, DS.SARGS()).staticmethod("IfcExternalSpatialStructureElement")
        .def("IfcExternallyDefinedHatchStyle", &PyIfcEntityDesc::IfcExternallyDefinedHatchStyle, DS.SARGS()).staticmethod("IfcExternallyDefinedHatchStyle")
        .def("IfcExternallyDefinedSurfaceStyle", &PyIfcEntityDesc::IfcExternallyDefinedSurfaceStyle, DS.SARGS()).staticmethod("IfcExternallyDefinedSurfaceStyle")
        .def("IfcExternallyDefinedSymbol", &PyIfcEntityDesc::IfcExternallyDefinedSymbol, DS.SARGS()).staticmethod("IfcExternallyDefinedSymbol")
        .def("IfcExternallyDefinedTextFont", &PyIfcEntityDesc::IfcExternallyDefinedTextFont, DS.SARGS()).staticmethod("IfcExternallyDefinedTextFont")
        .def("IfcExtrudedAreaSolid", &PyIfcEntityDesc::IfcExtrudedAreaSolid, DS.SARGS()).staticmethod("IfcExtrudedAreaSolid")
        .def("IfcExtrudedAreaSolidTapered", &PyIfcEntityDesc::IfcExtrudedAreaSolidTapered, DS.SARGS()).staticmethod("IfcExtrudedAreaSolidTapered")
        .def("IfcFace", &PyIfcEntityDesc::IfcFace, DS.SARGS()).staticmethod("IfcFace")
        .def("IfcFaceBasedSurfaceModel", &PyIfcEntityDesc::IfcFaceBasedSurfaceModel, DS.SARGS()).staticmethod("IfcFaceBasedSurfaceModel")
        .def("IfcFaceBound", &PyIfcEntityDesc::IfcFaceBound, DS.SARGS()).staticmethod("IfcFaceBound")
        .def("IfcFaceOuterBound", &PyIfcEntityDesc::IfcFaceOuterBound, DS.SARGS()).staticmethod("IfcFaceOuterBound")
        .def("IfcFaceSurface", &PyIfcEntityDesc::IfcFaceSurface, DS.SARGS()).staticmethod("IfcFaceSurface")
        .def("IfcFacetedBrep", &PyIfcEntityDesc::IfcFacetedBrep, DS.SARGS()).staticmethod("IfcFacetedBrep")
        .def("IfcFacetedBrepWithVoids", &PyIfcEntityDesc::IfcFacetedBrepWithVoids, DS.SARGS()).staticmethod("IfcFacetedBrepWithVoids")
        .def("IfcFailureConnectionCondition", &PyIfcEntityDesc::IfcFailureConnectionCondition, DS.SARGS()).staticmethod("IfcFailureConnectionCondition")
        .def("IfcFan", &PyIfcEntityDesc::IfcFan, DS.SARGS()).staticmethod("IfcFan")
        .def("IfcFanType", &PyIfcEntityDesc::IfcFanType, DS.SARGS()).staticmethod("IfcFanType")
        .def("IfcFastener", &PyIfcEntityDesc::IfcFastener, DS.SARGS()).staticmethod("IfcFastener")
        .def("IfcFastenerType", &PyIfcEntityDesc::IfcFastenerType, DS.SARGS()).staticmethod("IfcFastenerType")
        .def("IfcFeatureElement", &PyIfcEntityDesc::IfcFeatureElement, DS.SARGS()).staticmethod("IfcFeatureElement")
        .def("IfcFeatureElementAddition", &PyIfcEntityDesc::IfcFeatureElementAddition, DS.SARGS()).staticmethod("IfcFeatureElementAddition")
        .def("IfcFeatureElementSubtraction", &PyIfcEntityDesc::IfcFeatureElementSubtraction, DS.SARGS()).staticmethod("IfcFeatureElementSubtraction")
        .def("IfcFillAreaStyle", &PyIfcEntityDesc::IfcFillAreaStyle, DS.SARGS()).staticmethod("IfcFillAreaStyle")
        .def("IfcFillAreaStyleHatching", &PyIfcEntityDesc::IfcFillAreaStyleHatching, DS.SARGS()).staticmethod("IfcFillAreaStyleHatching")
        .def("IfcFillAreaStyleTileSymbolWithStyle", &PyIfcEntityDesc::IfcFillAreaStyleTileSymbolWithStyle, DS.SARGS()).staticmethod("IfcFillAreaStyleTileSymbolWithStyle")
        .def("IfcFillAreaStyleTiles", &PyIfcEntityDesc::IfcFillAreaStyleTiles, DS.SARGS()).staticmethod("IfcFillAreaStyleTiles")
        .def("IfcFilter", &PyIfcEntityDesc::IfcFilter, DS.SARGS()).staticmethod("IfcFilter")
        .def("IfcFilterType", &PyIfcEntityDesc::IfcFilterType, DS.SARGS()).staticmethod("IfcFilterType")
        .def("IfcFireSuppressionTerminal", &PyIfcEntityDesc::IfcFireSuppressionTerminal, DS.SARGS()).staticmethod("IfcFireSuppressionTerminal")
        .def("IfcFireSuppressionTerminalType", &PyIfcEntityDesc::IfcFireSuppressionTerminalType, DS.SARGS()).staticmethod("IfcFireSuppressionTerminalType")
        .def("IfcFixedReferenceSweptAreaSolid", &PyIfcEntityDesc::IfcFixedReferenceSweptAreaSolid, DS.SARGS()).staticmethod("IfcFixedReferenceSweptAreaSolid")
        .def("IfcFlowController", &PyIfcEntityDesc::IfcFlowController, DS.SARGS()).staticmethod("IfcFlowController")
        .def("IfcFlowControllerType", &PyIfcEntityDesc::IfcFlowControllerType, DS.SARGS()).staticmethod("IfcFlowControllerType")
        .def("IfcFlowFitting", &PyIfcEntityDesc::IfcFlowFitting, DS.SARGS()).staticmethod("IfcFlowFitting")
        .def("IfcFlowFittingType", &PyIfcEntityDesc::IfcFlowFittingType, DS.SARGS()).staticmethod("IfcFlowFittingType")
        .def("IfcFlowInstrument", &PyIfcEntityDesc::IfcFlowInstrument, DS.SARGS()).staticmethod("IfcFlowInstrument")
        .def("IfcFlowInstrumentType", &PyIfcEntityDesc::IfcFlowInstrumentType, DS.SARGS()).staticmethod("IfcFlowInstrumentType")
        .def("IfcFlowMeter", &PyIfcEntityDesc::IfcFlowMeter, DS.SARGS()).staticmethod("IfcFlowMeter")
        .def("IfcFlowMeterType", &PyIfcEntityDesc::IfcFlowMeterType, DS.SARGS()).staticmethod("IfcFlowMeterType")
        .def("IfcFlowMovingDevice", &PyIfcEntityDesc::IfcFlowMovingDevice, DS.SARGS()).staticmethod("IfcFlowMovingDevice")
        .def("IfcFlowMovingDeviceType", &PyIfcEntityDesc::IfcFlowMovingDeviceType, DS.SARGS()).staticmethod("IfcFlowMovingDeviceType")
        .def("IfcFlowSegment", &PyIfcEntityDesc::IfcFlowSegment, DS.SARGS()).staticmethod("IfcFlowSegment")
        .def("IfcFlowSegmentType", &PyIfcEntityDesc::IfcFlowSegmentType, DS.SARGS()).staticmethod("IfcFlowSegmentType")
        .def("IfcFlowStorageDevice", &PyIfcEntityDesc::IfcFlowStorageDevice, DS.SARGS()).staticmethod("IfcFlowStorageDevice")
        .def("IfcFlowStorageDeviceType", &PyIfcEntityDesc::IfcFlowStorageDeviceType, DS.SARGS()).staticmethod("IfcFlowStorageDeviceType")
        .def("IfcFlowTerminal", &PyIfcEntityDesc::IfcFlowTerminal, DS.SARGS()).staticmethod("IfcFlowTerminal")
        .def("IfcFlowTerminalType", &PyIfcEntityDesc::IfcFlowTerminalType, DS.SARGS()).staticmethod("IfcFlowTerminalType")
        .def("IfcFlowTreatmentDevice", &PyIfcEntityDesc::IfcFlowTreatmentDevice, DS.SARGS()).staticmethod("IfcFlowTreatmentDevice")
        .def("IfcFlowTreatmentDeviceType", &PyIfcEntityDesc::IfcFlowTreatmentDeviceType, DS.SARGS()).staticmethod("IfcFlowTreatmentDeviceType")
        .def("IfcFluidFlowProperties", &PyIfcEntityDesc::IfcFluidFlowProperties, DS.SARGS()).staticmethod("IfcFluidFlowProperties")
        .def("IfcFooting", &PyIfcEntityDesc::IfcFooting, DS.SARGS()).staticmethod("IfcFooting")
        .def("IfcFootingType", &PyIfcEntityDesc::IfcFootingType, DS.SARGS()).staticmethod("IfcFootingType")
        .def("IfcFuelProperties", &PyIfcEntityDesc::IfcFuelProperties, DS.SARGS()).staticmethod("IfcFuelProperties")
        .def("IfcFurnishingElement", &PyIfcEntityDesc::IfcFurnishingElement, DS.SARGS()).staticmethod("IfcFurnishingElement")
        .def("IfcFurnishingElementType", &PyIfcEntityDesc::IfcFurnishingElementType, DS.SARGS()).staticmethod("IfcFurnishingElementType")
        .def("IfcFurniture", &PyIfcEntityDesc::IfcFurniture, DS.SARGS()).staticmethod("IfcFurniture")
        .def("IfcFurnitureStandard", &PyIfcEntityDesc::IfcFurnitureStandard, DS.SARGS()).staticmethod("IfcFurnitureStandard")
        .def("IfcFurnitureType", &PyIfcEntityDesc::IfcFurnitureType, DS.SARGS()).staticmethod("IfcFurnitureType")
        .def("IfcGasTerminalType", &PyIfcEntityDesc::IfcGasTerminalType, DS.SARGS()).staticmethod("IfcGasTerminalType")
        .def("IfcGeneralMaterialProperties", &PyIfcEntityDesc::IfcGeneralMaterialProperties, DS.SARGS()).staticmethod("IfcGeneralMaterialProperties")
        .def("IfcGeneralProfileProperties", &PyIfcEntityDesc::IfcGeneralProfileProperties, DS.SARGS()).staticmethod("IfcGeneralProfileProperties")
        .def("IfcGeographicElement", &PyIfcEntityDesc::IfcGeographicElement, DS.SARGS()).staticmethod("IfcGeographicElement")
        .def("IfcGeographicElementType", &PyIfcEntityDesc::IfcGeographicElementType, DS.SARGS()).staticmethod("IfcGeographicElementType")
        .def("IfcGeometricCurveSet", &PyIfcEntityDesc::IfcGeometricCurveSet, DS.SARGS()).staticmethod("IfcGeometricCurveSet")
        .def("IfcGeometricRepresentationContext", &PyIfcEntityDesc::IfcGeometricRepresentationContext, DS.SARGS()).staticmethod("IfcGeometricRepresentationContext")
        .def("IfcGeometricRepresentationItem", &PyIfcEntityDesc::IfcGeometricRepresentationItem, DS.SARGS()).staticmethod("IfcGeometricRepresentationItem")
        .def("IfcGeometricRepresentationSubContext", &PyIfcEntityDesc::IfcGeometricRepresentationSubContext, DS.SARGS()).staticmethod("IfcGeometricRepresentationSubContext")
        .def("IfcGeometricSet", &PyIfcEntityDesc::IfcGeometricSet, DS.SARGS()).staticmethod("IfcGeometricSet")
        .def("IfcGrid", &PyIfcEntityDesc::IfcGrid, DS.SARGS()).staticmethod("IfcGrid")
        .def("IfcGridAxis", &PyIfcEntityDesc::IfcGridAxis, DS.SARGS()).staticmethod("IfcGridAxis")
        .def("IfcGridPlacement", &PyIfcEntityDesc::IfcGridPlacement, DS.SARGS()).staticmethod("IfcGridPlacement")
        .def("IfcGroup", &PyIfcEntityDesc::IfcGroup, DS.SARGS()).staticmethod("IfcGroup")
        .def("IfcHalfSpaceSolid", &PyIfcEntityDesc::IfcHalfSpaceSolid, DS.SARGS()).staticmethod("IfcHalfSpaceSolid")
        .def("IfcHeatExchanger", &PyIfcEntityDesc::IfcHeatExchanger, DS.SARGS()).staticmethod("IfcHeatExchanger")
        .def("IfcHeatExchangerType", &PyIfcEntityDesc::IfcHeatExchangerType, DS.SARGS()).staticmethod("IfcHeatExchangerType")
        .def("IfcHumidifier", &PyIfcEntityDesc::IfcHumidifier, DS.SARGS()).staticmethod("IfcHumidifier")
        .def("IfcHumidifierType", &PyIfcEntityDesc::IfcHumidifierType, DS.SARGS()).staticmethod("IfcHumidifierType")
        .def("IfcHygroscopicMaterialProperties", &PyIfcEntityDesc::IfcHygroscopicMaterialProperties, DS.SARGS()).staticmethod("IfcHygroscopicMaterialProperties")
        .def("IfcIShapeProfileDef", &PyIfcEntityDesc::IfcIShapeProfileDef, DS.SARGS()).staticmethod("IfcIShapeProfileDef")
        .def("IfcImageTexture", &PyIfcEntityDesc::IfcImageTexture, DS.SARGS()).staticmethod("IfcImageTexture")
        .def("IfcIndexedColourMap", &PyIfcEntityDesc::IfcIndexedColourMap, DS.SARGS()).staticmethod("IfcIndexedColourMap")
        .def("IfcIndexedPolyCurve", &PyIfcEntityDesc::IfcIndexedPolyCurve, DS.SARGS()).staticmethod("IfcIndexedPolyCurve")
        .def("IfcIndexedPolygonalFace", &PyIfcEntityDesc::IfcIndexedPolygonalFace, DS.SARGS()).staticmethod("IfcIndexedPolygonalFace")
        .def("IfcIndexedPolygonalFaceWithVoids", &PyIfcEntityDesc::IfcIndexedPolygonalFaceWithVoids, DS.SARGS()).staticmethod("IfcIndexedPolygonalFaceWithVoids")
        .def("IfcIndexedTextureMap", &PyIfcEntityDesc::IfcIndexedTextureMap, DS.SARGS()).staticmethod("IfcIndexedTextureMap")
        .def("IfcIndexedTriangleTextureMap", &PyIfcEntityDesc::IfcIndexedTriangleTextureMap, DS.SARGS()).staticmethod("IfcIndexedTriangleTextureMap")
        .def("IfcInterceptor", &PyIfcEntityDesc::IfcInterceptor, DS.SARGS()).staticmethod("IfcInterceptor")
        .def("IfcInterceptorType", &PyIfcEntityDesc::IfcInterceptorType, DS.SARGS()).staticmethod("IfcInterceptorType")
        .def("IfcIntersectionCurve", &PyIfcEntityDesc::IfcIntersectionCurve, DS.SARGS()).staticmethod("IfcIntersectionCurve")
        .def("IfcInventory", &PyIfcEntityDesc::IfcInventory, DS.SARGS()).staticmethod("IfcInventory")
        .def("IfcIrregularTimeSeries", &PyIfcEntityDesc::IfcIrregularTimeSeries, DS.SARGS()).staticmethod("IfcIrregularTimeSeries")
        .def("IfcIrregularTimeSeriesValue", &PyIfcEntityDesc::IfcIrregularTimeSeriesValue, DS.SARGS()).staticmethod("IfcIrregularTimeSeriesValue")
        .def("IfcJunctionBox", &PyIfcEntityDesc::IfcJunctionBox, DS.SARGS()).staticmethod("IfcJunctionBox")
        .def("IfcJunctionBoxType", &PyIfcEntityDesc::IfcJunctionBoxType, DS.SARGS()).staticmethod("IfcJunctionBoxType")
        .def("IfcLShapeProfileDef", &PyIfcEntityDesc::IfcLShapeProfileDef, DS.SARGS()).staticmethod("IfcLShapeProfileDef")
        .def("IfcLaborResource", &PyIfcEntityDesc::IfcLaborResource, DS.SARGS()).staticmethod("IfcLaborResource")
        .def("IfcLaborResourceType", &PyIfcEntityDesc::IfcLaborResourceType, DS.SARGS()).staticmethod("IfcLaborResourceType")
        .def("IfcLagTime", &PyIfcEntityDesc::IfcLagTime, DS.SARGS()).staticmethod("IfcLagTime")
        .def("IfcLamp", &PyIfcEntityDesc::IfcLamp, DS.SARGS()).staticmethod("IfcLamp")
        .def("IfcLampType", &PyIfcEntityDesc::IfcLampType, DS.SARGS()).staticmethod("IfcLampType")
        .def("IfcLibraryInformation", &PyIfcEntityDesc::IfcLibraryInformation, DS.SARGS()).staticmethod("IfcLibraryInformation")
        .def("IfcLibraryReference", &PyIfcEntityDesc::IfcLibraryReference, DS.SARGS()).staticmethod("IfcLibraryReference")
        .def("IfcLightDistributionData", &PyIfcEntityDesc::IfcLightDistributionData, DS.SARGS()).staticmethod("IfcLightDistributionData")
        .def("IfcLightFixture", &PyIfcEntityDesc::IfcLightFixture, DS.SARGS()).staticmethod("IfcLightFixture")
        .def("IfcLightFixtureType", &PyIfcEntityDesc::IfcLightFixtureType, DS.SARGS()).staticmethod("IfcLightFixtureType")
        .def("IfcLightIntensityDistribution", &PyIfcEntityDesc::IfcLightIntensityDistribution, DS.SARGS()).staticmethod("IfcLightIntensityDistribution")
        .def("IfcLightSource", &PyIfcEntityDesc::IfcLightSource, DS.SARGS()).staticmethod("IfcLightSource")
        .def("IfcLightSourceAmbient", &PyIfcEntityDesc::IfcLightSourceAmbient, DS.SARGS()).staticmethod("IfcLightSourceAmbient")
        .def("IfcLightSourceDirectional", &PyIfcEntityDesc::IfcLightSourceDirectional, DS.SARGS()).staticmethod("IfcLightSourceDirectional")
        .def("IfcLightSourceGoniometric", &PyIfcEntityDesc::IfcLightSourceGoniometric, DS.SARGS()).staticmethod("IfcLightSourceGoniometric")
        .def("IfcLightSourcePositional", &PyIfcEntityDesc::IfcLightSourcePositional, DS.SARGS()).staticmethod("IfcLightSourcePositional")
        .def("IfcLightSourceSpot", &PyIfcEntityDesc::IfcLightSourceSpot, DS.SARGS()).staticmethod("IfcLightSourceSpot")
        .def("IfcLine", &PyIfcEntityDesc::IfcLine, DS.SARGS()).staticmethod("IfcLine")
        .def("IfcLineSegment2D", &PyIfcEntityDesc::IfcLineSegment2D, DS.SARGS()).staticmethod("IfcLineSegment2D")
        .def("IfcLinearDimension", &PyIfcEntityDesc::IfcLinearDimension, DS.SARGS()).staticmethod("IfcLinearDimension")
        .def("IfcLinearPlacement", &PyIfcEntityDesc::IfcLinearPlacement, DS.SARGS()).staticmethod("IfcLinearPlacement")
        .def("IfcLinearPositioningElement", &PyIfcEntityDesc::IfcLinearPositioningElement, DS.SARGS()).staticmethod("IfcLinearPositioningElement")
        .def("IfcLocalPlacement", &PyIfcEntityDesc::IfcLocalPlacement, DS.SARGS()).staticmethod("IfcLocalPlacement")
        .def("IfcLocalTime", &PyIfcEntityDesc::IfcLocalTime, DS.SARGS()).staticmethod("IfcLocalTime")
        .def("IfcLoop", &PyIfcEntityDesc::IfcLoop, DS.SARGS()).staticmethod("IfcLoop")
        .def("IfcManifoldSolidBrep", &PyIfcEntityDesc::IfcManifoldSolidBrep, DS.SARGS()).staticmethod("IfcManifoldSolidBrep")
        .def("IfcMapConversion", &PyIfcEntityDesc::IfcMapConversion, DS.SARGS()).staticmethod("IfcMapConversion")
        .def("IfcMappedItem", &PyIfcEntityDesc::IfcMappedItem, DS.SARGS()).staticmethod("IfcMappedItem")
        .def("IfcMaterial", &PyIfcEntityDesc::IfcMaterial, DS.SARGS()).staticmethod("IfcMaterial")
        .def("IfcMaterialClassificationRelationship", &PyIfcEntityDesc::IfcMaterialClassificationRelationship, DS.SARGS()).staticmethod("IfcMaterialClassificationRelationship")
        .def("IfcMaterialConstituent", &PyIfcEntityDesc::IfcMaterialConstituent, DS.SARGS()).staticmethod("IfcMaterialConstituent")
        .def("IfcMaterialConstituentSet", &PyIfcEntityDesc::IfcMaterialConstituentSet, DS.SARGS()).staticmethod("IfcMaterialConstituentSet")
        .def("IfcMaterialDefinition", &PyIfcEntityDesc::IfcMaterialDefinition, DS.SARGS()).staticmethod("IfcMaterialDefinition")
        .def("IfcMaterialDefinitionRepresentation", &PyIfcEntityDesc::IfcMaterialDefinitionRepresentation, DS.SARGS()).staticmethod("IfcMaterialDefinitionRepresentation")
        .def("IfcMaterialLayer", &PyIfcEntityDesc::IfcMaterialLayer, DS.SARGS()).staticmethod("IfcMaterialLayer")
        .def("IfcMaterialLayerSet", &PyIfcEntityDesc::IfcMaterialLayerSet, DS.SARGS()).staticmethod("IfcMaterialLayerSet")
        .def("IfcMaterialLayerSetUsage", &PyIfcEntityDesc::IfcMaterialLayerSetUsage, DS.SARGS()).staticmethod("IfcMaterialLayerSetUsage")
        .def("IfcMaterialLayerWithOffsets", &PyIfcEntityDesc::IfcMaterialLayerWithOffsets, DS.SARGS()).staticmethod("IfcMaterialLayerWithOffsets")
        .def("IfcMaterialList", &PyIfcEntityDesc::IfcMaterialList, DS.SARGS()).staticmethod("IfcMaterialList")
        .def("IfcMaterialProfile", &PyIfcEntityDesc::IfcMaterialProfile, DS.SARGS()).staticmethod("IfcMaterialProfile")
        .def("IfcMaterialProfileSet", &PyIfcEntityDesc::IfcMaterialProfileSet, DS.SARGS()).staticmethod("IfcMaterialProfileSet")
        .def("IfcMaterialProfileSetUsage", &PyIfcEntityDesc::IfcMaterialProfileSetUsage, DS.SARGS()).staticmethod("IfcMaterialProfileSetUsage")
        .def("IfcMaterialProfileSetUsageTapering", &PyIfcEntityDesc::IfcMaterialProfileSetUsageTapering, DS.SARGS()).staticmethod("IfcMaterialProfileSetUsageTapering")
        .def("IfcMaterialProfileWithOffsets", &PyIfcEntityDesc::IfcMaterialProfileWithOffsets, DS.SARGS()).staticmethod("IfcMaterialProfileWithOffsets")
        .def("IfcMaterialProperties", &PyIfcEntityDesc::IfcMaterialProperties, DS.SARGS()).staticmethod("IfcMaterialProperties")
        .def("IfcMaterialRelationship", &PyIfcEntityDesc::IfcMaterialRelationship, DS.SARGS()).staticmethod("IfcMaterialRelationship")
        .def("IfcMaterialUsageDefinition", &PyIfcEntityDesc::IfcMaterialUsageDefinition, DS.SARGS()).staticmethod("IfcMaterialUsageDefinition")
        .def("IfcMeasureWithUnit", &PyIfcEntityDesc::IfcMeasureWithUnit, DS.SARGS()).staticmethod("IfcMeasureWithUnit")
        .def("IfcMechanicalConcreteMaterialProperties", &PyIfcEntityDesc::IfcMechanicalConcreteMaterialProperties, DS.SARGS()).staticmethod("IfcMechanicalConcreteMaterialProperties")
        .def("IfcMechanicalFastener", &PyIfcEntityDesc::IfcMechanicalFastener, DS.SARGS()).staticmethod("IfcMechanicalFastener")
        .def("IfcMechanicalFastenerType", &PyIfcEntityDesc::IfcMechanicalFastenerType, DS.SARGS()).staticmethod("IfcMechanicalFastenerType")
        .def("IfcMechanicalMaterialProperties", &PyIfcEntityDesc::IfcMechanicalMaterialProperties, DS.SARGS()).staticmethod("IfcMechanicalMaterialProperties")
        .def("IfcMechanicalSteelMaterialProperties", &PyIfcEntityDesc::IfcMechanicalSteelMaterialProperties, DS.SARGS()).staticmethod("IfcMechanicalSteelMaterialProperties")
        .def("IfcMedicalDevice", &PyIfcEntityDesc::IfcMedicalDevice, DS.SARGS()).staticmethod("IfcMedicalDevice")
        .def("IfcMedicalDeviceType", &PyIfcEntityDesc::IfcMedicalDeviceType, DS.SARGS()).staticmethod("IfcMedicalDeviceType")
        .def("IfcMember", &PyIfcEntityDesc::IfcMember, DS.SARGS()).staticmethod("IfcMember")
        .def("IfcMemberStandardCase", &PyIfcEntityDesc::IfcMemberStandardCase, DS.SARGS()).staticmethod("IfcMemberStandardCase")
        .def("IfcMemberType", &PyIfcEntityDesc::IfcMemberType, DS.SARGS()).staticmethod("IfcMemberType")
        .def("IfcMetric", &PyIfcEntityDesc::IfcMetric, DS.SARGS()).staticmethod("IfcMetric")
        .def("IfcMirroredProfileDef", &PyIfcEntityDesc::IfcMirroredProfileDef, DS.SARGS()).staticmethod("IfcMirroredProfileDef")
        .def("IfcMonetaryUnit", &PyIfcEntityDesc::IfcMonetaryUnit, DS.SARGS()).staticmethod("IfcMonetaryUnit")
        .def("IfcMotorConnection", &PyIfcEntityDesc::IfcMotorConnection, DS.SARGS()).staticmethod("IfcMotorConnection")
        .def("IfcMotorConnectionType", &PyIfcEntityDesc::IfcMotorConnectionType, DS.SARGS()).staticmethod("IfcMotorConnectionType")
        .def("IfcMove", &PyIfcEntityDesc::IfcMove, DS.SARGS()).staticmethod("IfcMove")
        .def("IfcNamedUnit", &PyIfcEntityDesc::IfcNamedUnit, DS.SARGS()).staticmethod("IfcNamedUnit")
        .def("IfcObject", &PyIfcEntityDesc::IfcObject, DS.SARGS()).staticmethod("IfcObject")
        .def("IfcObjectDefinition", &PyIfcEntityDesc::IfcObjectDefinition, DS.SARGS()).staticmethod("IfcObjectDefinition")
        .def("IfcObjectPlacement", &PyIfcEntityDesc::IfcObjectPlacement, DS.SARGS()).staticmethod("IfcObjectPlacement")
        .def("IfcObjective", &PyIfcEntityDesc::IfcObjective, DS.SARGS()).staticmethod("IfcObjective")
        .def("IfcOccupant", &PyIfcEntityDesc::IfcOccupant, DS.SARGS()).staticmethod("IfcOccupant")
        .def("IfcOffsetCurve", &PyIfcEntityDesc::IfcOffsetCurve, DS.SARGS()).staticmethod("IfcOffsetCurve")
        .def("IfcOffsetCurve2D", &PyIfcEntityDesc::IfcOffsetCurve2D, DS.SARGS()).staticmethod("IfcOffsetCurve2D")
        .def("IfcOffsetCurve3D", &PyIfcEntityDesc::IfcOffsetCurve3D, DS.SARGS()).staticmethod("IfcOffsetCurve3D")
        .def("IfcOffsetCurveByDistances", &PyIfcEntityDesc::IfcOffsetCurveByDistances, DS.SARGS()).staticmethod("IfcOffsetCurveByDistances")
        .def("IfcOneDirectionRepeatFactor", &PyIfcEntityDesc::IfcOneDirectionRepeatFactor, DS.SARGS()).staticmethod("IfcOneDirectionRepeatFactor")
        .def("IfcOpenShell", &PyIfcEntityDesc::IfcOpenShell, DS.SARGS()).staticmethod("IfcOpenShell")
        .def("IfcOpeningElement", &PyIfcEntityDesc::IfcOpeningElement, DS.SARGS()).staticmethod("IfcOpeningElement")
        .def("IfcOpeningStandardCase", &PyIfcEntityDesc::IfcOpeningStandardCase, DS.SARGS()).staticmethod("IfcOpeningStandardCase")
        .def("IfcOpticalMaterialProperties", &PyIfcEntityDesc::IfcOpticalMaterialProperties, DS.SARGS()).staticmethod("IfcOpticalMaterialProperties")
        .def("IfcOrderAction", &PyIfcEntityDesc::IfcOrderAction, DS.SARGS()).staticmethod("IfcOrderAction")
        .def("IfcOrganization", &PyIfcEntityDesc::IfcOrganization, DS.SARGS()).staticmethod("IfcOrganization")
        .def("IfcOrganizationRelationship", &PyIfcEntityDesc::IfcOrganizationRelationship, DS.SARGS()).staticmethod("IfcOrganizationRelationship")
        .def("IfcOrientationExpression", &PyIfcEntityDesc::IfcOrientationExpression, DS.SARGS()).staticmethod("IfcOrientationExpression")
        .def("IfcOrientedEdge", &PyIfcEntityDesc::IfcOrientedEdge, DS.SARGS()).staticmethod("IfcOrientedEdge")
        .def("IfcOuterBoundaryCurve", &PyIfcEntityDesc::IfcOuterBoundaryCurve, DS.SARGS()).staticmethod("IfcOuterBoundaryCurve")
        .def("IfcOutlet", &PyIfcEntityDesc::IfcOutlet, DS.SARGS()).staticmethod("IfcOutlet")
        .def("IfcOutletType", &PyIfcEntityDesc::IfcOutletType, DS.SARGS()).staticmethod("IfcOutletType")
        .def("IfcOwnerHistory", &PyIfcEntityDesc::IfcOwnerHistory, DS.SARGS()).staticmethod("IfcOwnerHistory")
        .def("IfcParameterizedProfileDef", &PyIfcEntityDesc::IfcParameterizedProfileDef, DS.SARGS()).staticmethod("IfcParameterizedProfileDef")
        .def("IfcPath", &PyIfcEntityDesc::IfcPath, DS.SARGS()).staticmethod("IfcPath")
        .def("IfcPcurve", &PyIfcEntityDesc::IfcPcurve, DS.SARGS()).staticmethod("IfcPcurve")
        .def("IfcPerformanceHistory", &PyIfcEntityDesc::IfcPerformanceHistory, DS.SARGS()).staticmethod("IfcPerformanceHistory")
        .def("IfcPermeableCoveringProperties", &PyIfcEntityDesc::IfcPermeableCoveringProperties, DS.SARGS()).staticmethod("IfcPermeableCoveringProperties")
        .def("IfcPermit", &PyIfcEntityDesc::IfcPermit, DS.SARGS()).staticmethod("IfcPermit")
        .def("IfcPerson", &PyIfcEntityDesc::IfcPerson, DS.SARGS()).staticmethod("IfcPerson")
        .def("IfcPersonAndOrganization", &PyIfcEntityDesc::IfcPersonAndOrganization, DS.SARGS()).staticmethod("IfcPersonAndOrganization")
        .def("IfcPhysicalComplexQuantity", &PyIfcEntityDesc::IfcPhysicalComplexQuantity, DS.SARGS()).staticmethod("IfcPhysicalComplexQuantity")
        .def("IfcPhysicalQuantity", &PyIfcEntityDesc::IfcPhysicalQuantity, DS.SARGS()).staticmethod("IfcPhysicalQuantity")
        .def("IfcPhysicalSimpleQuantity", &PyIfcEntityDesc::IfcPhysicalSimpleQuantity, DS.SARGS()).staticmethod("IfcPhysicalSimpleQuantity")
        .def("IfcPile", &PyIfcEntityDesc::IfcPile, DS.SARGS()).staticmethod("IfcPile")
        .def("IfcPileType", &PyIfcEntityDesc::IfcPileType, DS.SARGS()).staticmethod("IfcPileType")
        .def("IfcPipeFitting", &PyIfcEntityDesc::IfcPipeFitting, DS.SARGS()).staticmethod("IfcPipeFitting")
        .def("IfcPipeFittingType", &PyIfcEntityDesc::IfcPipeFittingType, DS.SARGS()).staticmethod("IfcPipeFittingType")
        .def("IfcPipeSegment", &PyIfcEntityDesc::IfcPipeSegment, DS.SARGS()).staticmethod("IfcPipeSegment")
        .def("IfcPipeSegmentType", &PyIfcEntityDesc::IfcPipeSegmentType, DS.SARGS()).staticmethod("IfcPipeSegmentType")
        .def("IfcPixelTexture", &PyIfcEntityDesc::IfcPixelTexture, DS.SARGS()).staticmethod("IfcPixelTexture")
        .def("IfcPlacement", &PyIfcEntityDesc::IfcPlacement, DS.SARGS()).staticmethod("IfcPlacement")
        .def("IfcPlanarBox", &PyIfcEntityDesc::IfcPlanarBox, DS.SARGS()).staticmethod("IfcPlanarBox")
        .def("IfcPlanarExtent", &PyIfcEntityDesc::IfcPlanarExtent, DS.SARGS()).staticmethod("IfcPlanarExtent")
        .def("IfcPlane", &PyIfcEntityDesc::IfcPlane, DS.SARGS()).staticmethod("IfcPlane")
        .def("IfcPlate", &PyIfcEntityDesc::IfcPlate, DS.SARGS()).staticmethod("IfcPlate")
        .def("IfcPlateStandardCase", &PyIfcEntityDesc::IfcPlateStandardCase, DS.SARGS()).staticmethod("IfcPlateStandardCase")
        .def("IfcPlateType", &PyIfcEntityDesc::IfcPlateType, DS.SARGS()).staticmethod("IfcPlateType")
        .def("IfcPoint", &PyIfcEntityDesc::IfcPoint, DS.SARGS()).staticmethod("IfcPoint")
        .def("IfcPointOnCurve", &PyIfcEntityDesc::IfcPointOnCurve, DS.SARGS()).staticmethod("IfcPointOnCurve")
        .def("IfcPointOnSurface", &PyIfcEntityDesc::IfcPointOnSurface, DS.SARGS()).staticmethod("IfcPointOnSurface")
        .def("IfcPolyLoop", &PyIfcEntityDesc::IfcPolyLoop, DS.SARGS()).staticmethod("IfcPolyLoop")
        .def("IfcPolygonalBoundedHalfSpace", &PyIfcEntityDesc::IfcPolygonalBoundedHalfSpace, DS.SARGS()).staticmethod("IfcPolygonalBoundedHalfSpace")
        .def("IfcPolygonalFaceSet", &PyIfcEntityDesc::IfcPolygonalFaceSet, DS.SARGS()).staticmethod("IfcPolygonalFaceSet")
        .def("IfcPolyline", &PyIfcEntityDesc::IfcPolyline, DS.SARGS()).staticmethod("IfcPolyline")
        .def("IfcPort", &PyIfcEntityDesc::IfcPort, DS.SARGS()).staticmethod("IfcPort")
        .def("IfcPositioningElement", &PyIfcEntityDesc::IfcPositioningElement, DS.SARGS()).staticmethod("IfcPositioningElement")
        .def("IfcPostalAddress", &PyIfcEntityDesc::IfcPostalAddress, DS.SARGS()).staticmethod("IfcPostalAddress")
        .def("IfcPreDefinedColour", &PyIfcEntityDesc::IfcPreDefinedColour, DS.SARGS()).staticmethod("IfcPreDefinedColour")
        .def("IfcPreDefinedCurveFont", &PyIfcEntityDesc::IfcPreDefinedCurveFont, DS.SARGS()).staticmethod("IfcPreDefinedCurveFont")
        .def("IfcPreDefinedDimensionSymbol", &PyIfcEntityDesc::IfcPreDefinedDimensionSymbol, DS.SARGS()).staticmethod("IfcPreDefinedDimensionSymbol")
        .def("IfcPreDefinedItem", &PyIfcEntityDesc::IfcPreDefinedItem, DS.SARGS()).staticmethod("IfcPreDefinedItem")
        .def("IfcPreDefinedPointMarkerSymbol", &PyIfcEntityDesc::IfcPreDefinedPointMarkerSymbol, DS.SARGS()).staticmethod("IfcPreDefinedPointMarkerSymbol")
        .def("IfcPreDefinedProperties", &PyIfcEntityDesc::IfcPreDefinedProperties, DS.SARGS()).staticmethod("IfcPreDefinedProperties")
        .def("IfcPreDefinedPropertySet", &PyIfcEntityDesc::IfcPreDefinedPropertySet, DS.SARGS()).staticmethod("IfcPreDefinedPropertySet")
        .def("IfcPreDefinedSymbol", &PyIfcEntityDesc::IfcPreDefinedSymbol, DS.SARGS()).staticmethod("IfcPreDefinedSymbol")
        .def("IfcPreDefinedTerminatorSymbol", &PyIfcEntityDesc::IfcPreDefinedTerminatorSymbol, DS.SARGS()).staticmethod("IfcPreDefinedTerminatorSymbol")
        .def("IfcPreDefinedTextFont", &PyIfcEntityDesc::IfcPreDefinedTextFont, DS.SARGS()).staticmethod("IfcPreDefinedTextFont")
        .def("IfcPresentationItem", &PyIfcEntityDesc::IfcPresentationItem, DS.SARGS()).staticmethod("IfcPresentationItem")
        .def("IfcPresentationLayerAssignment", &PyIfcEntityDesc::IfcPresentationLayerAssignment, DS.SARGS()).staticmethod("IfcPresentationLayerAssignment")
        .def("IfcPresentationLayerWithStyle", &PyIfcEntityDesc::IfcPresentationLayerWithStyle, DS.SARGS()).staticmethod("IfcPresentationLayerWithStyle")
        .def("IfcPresentationStyle", &PyIfcEntityDesc::IfcPresentationStyle, DS.SARGS()).staticmethod("IfcPresentationStyle")
        .def("IfcPresentationStyleAssignment", &PyIfcEntityDesc::IfcPresentationStyleAssignment, DS.SARGS()).staticmethod("IfcPresentationStyleAssignment")
        .def("IfcProcedure", &PyIfcEntityDesc::IfcProcedure, DS.SARGS()).staticmethod("IfcProcedure")
        .def("IfcProcedureType", &PyIfcEntityDesc::IfcProcedureType, DS.SARGS()).staticmethod("IfcProcedureType")
        .def("IfcProcess", &PyIfcEntityDesc::IfcProcess, DS.SARGS()).staticmethod("IfcProcess")
        .def("IfcProduct", &PyIfcEntityDesc::IfcProduct, DS.SARGS()).staticmethod("IfcProduct")
        .def("IfcProductDefinitionShape", &PyIfcEntityDesc::IfcProductDefinitionShape, DS.SARGS()).staticmethod("IfcProductDefinitionShape")
        .def("IfcProductRepresentation", &PyIfcEntityDesc::IfcProductRepresentation, DS.SARGS()).staticmethod("IfcProductRepresentation")
        .def("IfcProductsOfCombustionProperties", &PyIfcEntityDesc::IfcProductsOfCombustionProperties, DS.SARGS()).staticmethod("IfcProductsOfCombustionProperties")
        .def("IfcProfileDef", &PyIfcEntityDesc::IfcProfileDef, DS.SARGS()).staticmethod("IfcProfileDef")
        .def("IfcProfileProperties", &PyIfcEntityDesc::IfcProfileProperties, DS.SARGS()).staticmethod("IfcProfileProperties")
        .def("IfcProject", &PyIfcEntityDesc::IfcProject, DS.SARGS()).staticmethod("IfcProject")
        .def("IfcProjectLibrary", &PyIfcEntityDesc::IfcProjectLibrary, DS.SARGS()).staticmethod("IfcProjectLibrary")
        .def("IfcProjectOrder", &PyIfcEntityDesc::IfcProjectOrder, DS.SARGS()).staticmethod("IfcProjectOrder")
        .def("IfcProjectOrderRecord", &PyIfcEntityDesc::IfcProjectOrderRecord, DS.SARGS()).staticmethod("IfcProjectOrderRecord")
        .def("IfcProjectedCRS", &PyIfcEntityDesc::IfcProjectedCRS, DS.SARGS()).staticmethod("IfcProjectedCRS")
        .def("IfcProjectionCurve", &PyIfcEntityDesc::IfcProjectionCurve, DS.SARGS()).staticmethod("IfcProjectionCurve")
        .def("IfcProjectionElement", &PyIfcEntityDesc::IfcProjectionElement, DS.SARGS()).staticmethod("IfcProjectionElement")
        .def("IfcProperty", &PyIfcEntityDesc::IfcProperty, DS.SARGS()).staticmethod("IfcProperty")
        .def("IfcPropertyAbstraction", &PyIfcEntityDesc::IfcPropertyAbstraction, DS.SARGS()).staticmethod("IfcPropertyAbstraction")
        .def("IfcPropertyBoundedValue", &PyIfcEntityDesc::IfcPropertyBoundedValue, DS.SARGS()).staticmethod("IfcPropertyBoundedValue")
        .def("IfcPropertyConstraintRelationship", &PyIfcEntityDesc::IfcPropertyConstraintRelationship, DS.SARGS()).staticmethod("IfcPropertyConstraintRelationship")
        .def("IfcPropertyDefinition", &PyIfcEntityDesc::IfcPropertyDefinition, DS.SARGS()).staticmethod("IfcPropertyDefinition")
        .def("IfcPropertyDependencyRelationship", &PyIfcEntityDesc::IfcPropertyDependencyRelationship, DS.SARGS()).staticmethod("IfcPropertyDependencyRelationship")
        .def("IfcPropertyEnumeratedValue", &PyIfcEntityDesc::IfcPropertyEnumeratedValue, DS.SARGS()).staticmethod("IfcPropertyEnumeratedValue")
        .def("IfcPropertyEnumeration", &PyIfcEntityDesc::IfcPropertyEnumeration, DS.SARGS()).staticmethod("IfcPropertyEnumeration")
        .def("IfcPropertyListValue", &PyIfcEntityDesc::IfcPropertyListValue, DS.SARGS()).staticmethod("IfcPropertyListValue")
        .def("IfcPropertyReferenceValue", &PyIfcEntityDesc::IfcPropertyReferenceValue, DS.SARGS()).staticmethod("IfcPropertyReferenceValue")
        .def("IfcPropertySet", &PyIfcEntityDesc::IfcPropertySet, DS.SARGS()).staticmethod("IfcPropertySet")
        .def("IfcPropertySetDefinition", &PyIfcEntityDesc::IfcPropertySetDefinition, DS.SARGS()).staticmethod("IfcPropertySetDefinition")
        .def("IfcPropertySetTemplate", &PyIfcEntityDesc::IfcPropertySetTemplate, DS.SARGS()).staticmethod("IfcPropertySetTemplate")
        .def("IfcPropertySingleValue", &PyIfcEntityDesc::IfcPropertySingleValue, DS.SARGS()).staticmethod("IfcPropertySingleValue")
        .def("IfcPropertyTableValue", &PyIfcEntityDesc::IfcPropertyTableValue, DS.SARGS()).staticmethod("IfcPropertyTableValue")
        .def("IfcPropertyTemplate", &PyIfcEntityDesc::IfcPropertyTemplate, DS.SARGS()).staticmethod("IfcPropertyTemplate")
        .def("IfcPropertyTemplateDefinition", &PyIfcEntityDesc::IfcPropertyTemplateDefinition, DS.SARGS()).staticmethod("IfcPropertyTemplateDefinition")
        .def("IfcProtectiveDevice", &PyIfcEntityDesc::IfcProtectiveDevice, DS.SARGS()).staticmethod("IfcProtectiveDevice")
        .def("IfcProtectiveDeviceTrippingUnit", &PyIfcEntityDesc::IfcProtectiveDeviceTrippingUnit, DS.SARGS()).staticmethod("IfcProtectiveDeviceTrippingUnit")
        .def("IfcProtectiveDeviceTrippingUnitType", &PyIfcEntityDesc::IfcProtectiveDeviceTrippingUnitType, DS.SARGS()).staticmethod("IfcProtectiveDeviceTrippingUnitType")
        .def("IfcProtectiveDeviceType", &PyIfcEntityDesc::IfcProtectiveDeviceType, DS.SARGS()).staticmethod("IfcProtectiveDeviceType")
        .def("IfcProxy", &PyIfcEntityDesc::IfcProxy, DS.SARGS()).staticmethod("IfcProxy")
        .def("IfcPump", &PyIfcEntityDesc::IfcPump, DS.SARGS()).staticmethod("IfcPump")
        .def("IfcPumpType", &PyIfcEntityDesc::IfcPumpType, DS.SARGS()).staticmethod("IfcPumpType")
        .def("IfcQuantityArea", &PyIfcEntityDesc::IfcQuantityArea, DS.SARGS()).staticmethod("IfcQuantityArea")
        .def("IfcQuantityCount", &PyIfcEntityDesc::IfcQuantityCount, DS.SARGS()).staticmethod("IfcQuantityCount")
        .def("IfcQuantityLength", &PyIfcEntityDesc::IfcQuantityLength, DS.SARGS()).staticmethod("IfcQuantityLength")
        .def("IfcQuantitySet", &PyIfcEntityDesc::IfcQuantitySet, DS.SARGS()).staticmethod("IfcQuantitySet")
        .def("IfcQuantityTime", &PyIfcEntityDesc::IfcQuantityTime, DS.SARGS()).staticmethod("IfcQuantityTime")
        .def("IfcQuantityVolume", &PyIfcEntityDesc::IfcQuantityVolume, DS.SARGS()).staticmethod("IfcQuantityVolume")
        .def("IfcQuantityWeight", &PyIfcEntityDesc::IfcQuantityWeight, DS.SARGS()).staticmethod("IfcQuantityWeight")
        .def("IfcRadiusDimension", &PyIfcEntityDesc::IfcRadiusDimension, DS.SARGS()).staticmethod("IfcRadiusDimension")
        .def("IfcRailing", &PyIfcEntityDesc::IfcRailing, DS.SARGS()).staticmethod("IfcRailing")
        .def("IfcRailingType", &PyIfcEntityDesc::IfcRailingType, DS.SARGS()).staticmethod("IfcRailingType")
        .def("IfcRamp", &PyIfcEntityDesc::IfcRamp, DS.SARGS()).staticmethod("IfcRamp")
        .def("IfcRampFlight", &PyIfcEntityDesc::IfcRampFlight, DS.SARGS()).staticmethod("IfcRampFlight")
        .def("IfcRampFlightType", &PyIfcEntityDesc::IfcRampFlightType, DS.SARGS()).staticmethod("IfcRampFlightType")
        .def("IfcRampType", &PyIfcEntityDesc::IfcRampType, DS.SARGS()).staticmethod("IfcRampType")
        .def("IfcRationalBSplineCurveWithKnots", &PyIfcEntityDesc::IfcRationalBSplineCurveWithKnots, DS.SARGS()).staticmethod("IfcRationalBSplineCurveWithKnots")
        .def("IfcRationalBSplineSurfaceWithKnots", &PyIfcEntityDesc::IfcRationalBSplineSurfaceWithKnots, DS.SARGS()).staticmethod("IfcRationalBSplineSurfaceWithKnots")
        .def("IfcRationalBezierCurve", &PyIfcEntityDesc::IfcRationalBezierCurve, DS.SARGS()).staticmethod("IfcRationalBezierCurve")
        .def("IfcRectangleHollowProfileDef", &PyIfcEntityDesc::IfcRectangleHollowProfileDef, DS.SARGS()).staticmethod("IfcRectangleHollowProfileDef")
        .def("IfcRectangleProfileDef", &PyIfcEntityDesc::IfcRectangleProfileDef, DS.SARGS()).staticmethod("IfcRectangleProfileDef")
        .def("IfcRectangularPyramid", &PyIfcEntityDesc::IfcRectangularPyramid, DS.SARGS()).staticmethod("IfcRectangularPyramid")
        .def("IfcRectangularTrimmedSurface", &PyIfcEntityDesc::IfcRectangularTrimmedSurface, DS.SARGS()).staticmethod("IfcRectangularTrimmedSurface")
        .def("IfcRecurrencePattern", &PyIfcEntityDesc::IfcRecurrencePattern, DS.SARGS()).staticmethod("IfcRecurrencePattern")
        .def("IfcReference", &PyIfcEntityDesc::IfcReference, DS.SARGS()).staticmethod("IfcReference")
        .def("IfcReferencesValueDocument", &PyIfcEntityDesc::IfcReferencesValueDocument, DS.SARGS()).staticmethod("IfcReferencesValueDocument")
        .def("IfcReferent", &PyIfcEntityDesc::IfcReferent, DS.SARGS()).staticmethod("IfcReferent")
        .def("IfcRegularTimeSeries", &PyIfcEntityDesc::IfcRegularTimeSeries, DS.SARGS()).staticmethod("IfcRegularTimeSeries")
        .def("IfcReinforcementBarProperties", &PyIfcEntityDesc::IfcReinforcementBarProperties, DS.SARGS()).staticmethod("IfcReinforcementBarProperties")
        .def("IfcReinforcementDefinitionProperties", &PyIfcEntityDesc::IfcReinforcementDefinitionProperties, DS.SARGS()).staticmethod("IfcReinforcementDefinitionProperties")
        .def("IfcReinforcingBar", &PyIfcEntityDesc::IfcReinforcingBar, DS.SARGS()).staticmethod("IfcReinforcingBar")
        .def("IfcReinforcingBarType", &PyIfcEntityDesc::IfcReinforcingBarType, DS.SARGS()).staticmethod("IfcReinforcingBarType")
        .def("IfcReinforcingElement", &PyIfcEntityDesc::IfcReinforcingElement, DS.SARGS()).staticmethod("IfcReinforcingElement")
        .def("IfcReinforcingElementType", &PyIfcEntityDesc::IfcReinforcingElementType, DS.SARGS()).staticmethod("IfcReinforcingElementType")
        .def("IfcReinforcingMesh", &PyIfcEntityDesc::IfcReinforcingMesh, DS.SARGS()).staticmethod("IfcReinforcingMesh")
        .def("IfcReinforcingMeshType", &PyIfcEntityDesc::IfcReinforcingMeshType, DS.SARGS()).staticmethod("IfcReinforcingMeshType")
        .def("IfcRelAggregates", &PyIfcEntityDesc::IfcRelAggregates, DS.SARGS()).staticmethod("IfcRelAggregates")
        .def("IfcRelAssigns", &PyIfcEntityDesc::IfcRelAssigns, DS.SARGS()).staticmethod("IfcRelAssigns")
        .def("IfcRelAssignsTasks", &PyIfcEntityDesc::IfcRelAssignsTasks, DS.SARGS()).staticmethod("IfcRelAssignsTasks")
        .def("IfcRelAssignsToActor", &PyIfcEntityDesc::IfcRelAssignsToActor, DS.SARGS()).staticmethod("IfcRelAssignsToActor")
        .def("IfcRelAssignsToControl", &PyIfcEntityDesc::IfcRelAssignsToControl, DS.SARGS()).staticmethod("IfcRelAssignsToControl")
        .def("IfcRelAssignsToGroup", &PyIfcEntityDesc::IfcRelAssignsToGroup, DS.SARGS()).staticmethod("IfcRelAssignsToGroup")
        .def("IfcRelAssignsToGroupByFactor", &PyIfcEntityDesc::IfcRelAssignsToGroupByFactor, DS.SARGS()).staticmethod("IfcRelAssignsToGroupByFactor")
        .def("IfcRelAssignsToProcess", &PyIfcEntityDesc::IfcRelAssignsToProcess, DS.SARGS()).staticmethod("IfcRelAssignsToProcess")
        .def("IfcRelAssignsToProduct", &PyIfcEntityDesc::IfcRelAssignsToProduct, DS.SARGS()).staticmethod("IfcRelAssignsToProduct")
        .def("IfcRelAssignsToProjectOrder", &PyIfcEntityDesc::IfcRelAssignsToProjectOrder, DS.SARGS()).staticmethod("IfcRelAssignsToProjectOrder")
        .def("IfcRelAssignsToResource", &PyIfcEntityDesc::IfcRelAssignsToResource, DS.SARGS()).staticmethod("IfcRelAssignsToResource")
        .def("IfcRelAssociates", &PyIfcEntityDesc::IfcRelAssociates, DS.SARGS()).staticmethod("IfcRelAssociates")
        .def("IfcRelAssociatesAppliedValue", &PyIfcEntityDesc::IfcRelAssociatesAppliedValue, DS.SARGS()).staticmethod("IfcRelAssociatesAppliedValue")
        .def("IfcRelAssociatesApproval", &PyIfcEntityDesc::IfcRelAssociatesApproval, DS.SARGS()).staticmethod("IfcRelAssociatesApproval")
        .def("IfcRelAssociatesClassification", &PyIfcEntityDesc::IfcRelAssociatesClassification, DS.SARGS()).staticmethod("IfcRelAssociatesClassification")
        .def("IfcRelAssociatesConstraint", &PyIfcEntityDesc::IfcRelAssociatesConstraint, DS.SARGS()).staticmethod("IfcRelAssociatesConstraint")
        .def("IfcRelAssociatesDocument", &PyIfcEntityDesc::IfcRelAssociatesDocument, DS.SARGS()).staticmethod("IfcRelAssociatesDocument")
        .def("IfcRelAssociatesLibrary", &PyIfcEntityDesc::IfcRelAssociatesLibrary, DS.SARGS()).staticmethod("IfcRelAssociatesLibrary")
        .def("IfcRelAssociatesMaterial", &PyIfcEntityDesc::IfcRelAssociatesMaterial, DS.SARGS()).staticmethod("IfcRelAssociatesMaterial")
        .def("IfcRelAssociatesProfileProperties", &PyIfcEntityDesc::IfcRelAssociatesProfileProperties, DS.SARGS()).staticmethod("IfcRelAssociatesProfileProperties")
        .def("IfcRelConnects", &PyIfcEntityDesc::IfcRelConnects, DS.SARGS()).staticmethod("IfcRelConnects")
        .def("IfcRelConnectsElements", &PyIfcEntityDesc::IfcRelConnectsElements, DS.SARGS()).staticmethod("IfcRelConnectsElements")
        .def("IfcRelConnectsPathElements", &PyIfcEntityDesc::IfcRelConnectsPathElements, DS.SARGS()).staticmethod("IfcRelConnectsPathElements")
        .def("IfcRelConnectsPortToElement", &PyIfcEntityDesc::IfcRelConnectsPortToElement, DS.SARGS()).staticmethod("IfcRelConnectsPortToElement")
        .def("IfcRelConnectsPorts", &PyIfcEntityDesc::IfcRelConnectsPorts, DS.SARGS()).staticmethod("IfcRelConnectsPorts")
        .def("IfcRelConnectsStructuralActivity", &PyIfcEntityDesc::IfcRelConnectsStructuralActivity, DS.SARGS()).staticmethod("IfcRelConnectsStructuralActivity")
        .def("IfcRelConnectsStructuralElement", &PyIfcEntityDesc::IfcRelConnectsStructuralElement, DS.SARGS()).staticmethod("IfcRelConnectsStructuralElement")
        .def("IfcRelConnectsStructuralMember", &PyIfcEntityDesc::IfcRelConnectsStructuralMember, DS.SARGS()).staticmethod("IfcRelConnectsStructuralMember")
        .def("IfcRelConnectsWithEccentricity", &PyIfcEntityDesc::IfcRelConnectsWithEccentricity, DS.SARGS()).staticmethod("IfcRelConnectsWithEccentricity")
        .def("IfcRelConnectsWithRealizingElements", &PyIfcEntityDesc::IfcRelConnectsWithRealizingElements, DS.SARGS()).staticmethod("IfcRelConnectsWithRealizingElements")
        .def("IfcRelContainedInSpatialStructure", &PyIfcEntityDesc::IfcRelContainedInSpatialStructure, DS.SARGS()).staticmethod("IfcRelContainedInSpatialStructure")
        .def("IfcRelCoversBldgElements", &PyIfcEntityDesc::IfcRelCoversBldgElements, DS.SARGS()).staticmethod("IfcRelCoversBldgElements")
        .def("IfcRelCoversSpaces", &PyIfcEntityDesc::IfcRelCoversSpaces, DS.SARGS()).staticmethod("IfcRelCoversSpaces")
        .def("IfcRelDeclares", &PyIfcEntityDesc::IfcRelDeclares, DS.SARGS()).staticmethod("IfcRelDeclares")
        .def("IfcRelDecomposes", &PyIfcEntityDesc::IfcRelDecomposes, DS.SARGS()).staticmethod("IfcRelDecomposes")
        .def("IfcRelDefines", &PyIfcEntityDesc::IfcRelDefines, DS.SARGS()).staticmethod("IfcRelDefines")
        .def("IfcRelDefinesByObject", &PyIfcEntityDesc::IfcRelDefinesByObject, DS.SARGS()).staticmethod("IfcRelDefinesByObject")
        .def("IfcRelDefinesByProperties", &PyIfcEntityDesc::IfcRelDefinesByProperties, DS.SARGS()).staticmethod("IfcRelDefinesByProperties")
        .def("IfcRelDefinesByTemplate", &PyIfcEntityDesc::IfcRelDefinesByTemplate, DS.SARGS()).staticmethod("IfcRelDefinesByTemplate")
        .def("IfcRelDefinesByType", &PyIfcEntityDesc::IfcRelDefinesByType, DS.SARGS()).staticmethod("IfcRelDefinesByType")
        .def("IfcRelFillsElement", &PyIfcEntityDesc::IfcRelFillsElement, DS.SARGS()).staticmethod("IfcRelFillsElement")
        .def("IfcRelFlowControlElements", &PyIfcEntityDesc::IfcRelFlowControlElements, DS.SARGS()).staticmethod("IfcRelFlowControlElements")
        .def("IfcRelInteractionRequirements", &PyIfcEntityDesc::IfcRelInteractionRequirements, DS.SARGS()).staticmethod("IfcRelInteractionRequirements")
        .def("IfcRelInterferesElements", &PyIfcEntityDesc::IfcRelInterferesElements, DS.SARGS()).staticmethod("IfcRelInterferesElements")
        .def("IfcRelNests", &PyIfcEntityDesc::IfcRelNests, DS.SARGS()).staticmethod("IfcRelNests")
        .def("IfcRelOccupiesSpaces", &PyIfcEntityDesc::IfcRelOccupiesSpaces, DS.SARGS()).staticmethod("IfcRelOccupiesSpaces")
        .def("IfcRelOverridesProperties", &PyIfcEntityDesc::IfcRelOverridesProperties, DS.SARGS()).staticmethod("IfcRelOverridesProperties")
        .def("IfcRelProjectsElement", &PyIfcEntityDesc::IfcRelProjectsElement, DS.SARGS()).staticmethod("IfcRelProjectsElement")
        .def("IfcRelReferencedInSpatialStructure", &PyIfcEntityDesc::IfcRelReferencedInSpatialStructure, DS.SARGS()).staticmethod("IfcRelReferencedInSpatialStructure")
        .def("IfcRelSchedulesCostItems", &PyIfcEntityDesc::IfcRelSchedulesCostItems, DS.SARGS()).staticmethod("IfcRelSchedulesCostItems")
        .def("IfcRelSequence", &PyIfcEntityDesc::IfcRelSequence, DS.SARGS()).staticmethod("IfcRelSequence")
        .def("IfcRelServicesBuildings", &PyIfcEntityDesc::IfcRelServicesBuildings, DS.SARGS()).staticmethod("IfcRelServicesBuildings")
        .def("IfcRelSpaceBoundary", &PyIfcEntityDesc::IfcRelSpaceBoundary, DS.SARGS()).staticmethod("IfcRelSpaceBoundary")
        .def("IfcRelSpaceBoundary1stLevel", &PyIfcEntityDesc::IfcRelSpaceBoundary1stLevel, DS.SARGS()).staticmethod("IfcRelSpaceBoundary1stLevel")
        .def("IfcRelSpaceBoundary2ndLevel", &PyIfcEntityDesc::IfcRelSpaceBoundary2ndLevel, DS.SARGS()).staticmethod("IfcRelSpaceBoundary2ndLevel")
        .def("IfcRelVoidsElement", &PyIfcEntityDesc::IfcRelVoidsElement, DS.SARGS()).staticmethod("IfcRelVoidsElement")
        .def("IfcRelationship", &PyIfcEntityDesc::IfcRelationship, DS.SARGS()).staticmethod("IfcRelationship")
        .def("IfcRelaxation", &PyIfcEntityDesc::IfcRelaxation, DS.SARGS()).staticmethod("IfcRelaxation")
        .def("IfcReparametrisedCompositeCurveSegment", &PyIfcEntityDesc::IfcReparametrisedCompositeCurveSegment, DS.SARGS()).staticmethod("IfcReparametrisedCompositeCurveSegment")
        .def("IfcRepresentation", &PyIfcEntityDesc::IfcRepresentation, DS.SARGS()).staticmethod("IfcRepresentation")
        .def("IfcRepresentationContext", &PyIfcEntityDesc::IfcRepresentationContext, DS.SARGS()).staticmethod("IfcRepresentationContext")
        .def("IfcRepresentationItem", &PyIfcEntityDesc::IfcRepresentationItem, DS.SARGS()).staticmethod("IfcRepresentationItem")
        .def("IfcRepresentationMap", &PyIfcEntityDesc::IfcRepresentationMap, DS.SARGS()).staticmethod("IfcRepresentationMap")
        .def("IfcResource", &PyIfcEntityDesc::IfcResource, DS.SARGS()).staticmethod("IfcResource")
        .def("IfcResourceApprovalRelationship", &PyIfcEntityDesc::IfcResourceApprovalRelationship, DS.SARGS()).staticmethod("IfcResourceApprovalRelationship")
        .def("IfcResourceConstraintRelationship", &PyIfcEntityDesc::IfcResourceConstraintRelationship, DS.SARGS()).staticmethod("IfcResourceConstraintRelationship")
        .def("IfcResourceLevelRelationship", &PyIfcEntityDesc::IfcResourceLevelRelationship, DS.SARGS()).staticmethod("IfcResourceLevelRelationship")
        .def("IfcResourceTime", &PyIfcEntityDesc::IfcResourceTime, DS.SARGS()).staticmethod("IfcResourceTime")
        .def("IfcRevolvedAreaSolid", &PyIfcEntityDesc::IfcRevolvedAreaSolid, DS.SARGS()).staticmethod("IfcRevolvedAreaSolid")
        .def("IfcRevolvedAreaSolidTapered", &PyIfcEntityDesc::IfcRevolvedAreaSolidTapered, DS.SARGS()).staticmethod("IfcRevolvedAreaSolidTapered")
        .def("IfcRibPlateProfileProperties", &PyIfcEntityDesc::IfcRibPlateProfileProperties, DS.SARGS()).staticmethod("IfcRibPlateProfileProperties")
        .def("IfcRightCircularCone", &PyIfcEntityDesc::IfcRightCircularCone, DS.SARGS()).staticmethod("IfcRightCircularCone")
        .def("IfcRightCircularCylinder", &PyIfcEntityDesc::IfcRightCircularCylinder, DS.SARGS()).staticmethod("IfcRightCircularCylinder")
        .def("IfcRoof", &PyIfcEntityDesc::IfcRoof, DS.SARGS()).staticmethod("IfcRoof")
        .def("IfcRoofType", &PyIfcEntityDesc::IfcRoofType, DS.SARGS()).staticmethod("IfcRoofType")
        .def("IfcRoot", &PyIfcEntityDesc::IfcRoot, DS.SARGS()).staticmethod("IfcRoot")
        .def("IfcRoundedEdgeFeature", &PyIfcEntityDesc::IfcRoundedEdgeFeature, DS.SARGS()).staticmethod("IfcRoundedEdgeFeature")
        .def("IfcRoundedRectangleProfileDef", &PyIfcEntityDesc::IfcRoundedRectangleProfileDef, DS.SARGS()).staticmethod("IfcRoundedRectangleProfileDef")
        .def("IfcSIUnit", &PyIfcEntityDesc::IfcSIUnit, DS.SARGS()).staticmethod("IfcSIUnit")
        .def("IfcSanitaryTerminal", &PyIfcEntityDesc::IfcSanitaryTerminal, DS.SARGS()).staticmethod("IfcSanitaryTerminal")
        .def("IfcSanitaryTerminalType", &PyIfcEntityDesc::IfcSanitaryTerminalType, DS.SARGS()).staticmethod("IfcSanitaryTerminalType")
        .def("IfcScheduleTimeControl", &PyIfcEntityDesc::IfcScheduleTimeControl, DS.SARGS()).staticmethod("IfcScheduleTimeControl")
        .def("IfcSchedulingTime", &PyIfcEntityDesc::IfcSchedulingTime, DS.SARGS()).staticmethod("IfcSchedulingTime")
        .def("IfcSeamCurve", &PyIfcEntityDesc::IfcSeamCurve, DS.SARGS()).staticmethod("IfcSeamCurve")
        .def("IfcSectionProperties", &PyIfcEntityDesc::IfcSectionProperties, DS.SARGS()).staticmethod("IfcSectionProperties")
        .def("IfcSectionReinforcementProperties", &PyIfcEntityDesc::IfcSectionReinforcementProperties, DS.SARGS()).staticmethod("IfcSectionReinforcementProperties")
        .def("IfcSectionedSolid", &PyIfcEntityDesc::IfcSectionedSolid, DS.SARGS()).staticmethod("IfcSectionedSolid")
        .def("IfcSectionedSolidHorizontal", &PyIfcEntityDesc::IfcSectionedSolidHorizontal, DS.SARGS()).staticmethod("IfcSectionedSolidHorizontal")
        .def("IfcSectionedSpine", &PyIfcEntityDesc::IfcSectionedSpine, DS.SARGS()).staticmethod("IfcSectionedSpine")
        .def("IfcSensor", &PyIfcEntityDesc::IfcSensor, DS.SARGS()).staticmethod("IfcSensor")
        .def("IfcSensorType", &PyIfcEntityDesc::IfcSensorType, DS.SARGS()).staticmethod("IfcSensorType")
        .def("IfcServiceLife", &PyIfcEntityDesc::IfcServiceLife, DS.SARGS()).staticmethod("IfcServiceLife")
        .def("IfcServiceLifeFactor", &PyIfcEntityDesc::IfcServiceLifeFactor, DS.SARGS()).staticmethod("IfcServiceLifeFactor")
        .def("IfcShadingDevice", &PyIfcEntityDesc::IfcShadingDevice, DS.SARGS()).staticmethod("IfcShadingDevice")
        .def("IfcShadingDeviceType", &PyIfcEntityDesc::IfcShadingDeviceType, DS.SARGS()).staticmethod("IfcShadingDeviceType")
        .def("IfcShapeAspect", &PyIfcEntityDesc::IfcShapeAspect, DS.SARGS()).staticmethod("IfcShapeAspect")
        .def("IfcShapeModel", &PyIfcEntityDesc::IfcShapeModel, DS.SARGS()).staticmethod("IfcShapeModel")
        .def("IfcShapeRepresentation", &PyIfcEntityDesc::IfcShapeRepresentation, DS.SARGS()).staticmethod("IfcShapeRepresentation")
        .def("IfcShellBasedSurfaceModel", &PyIfcEntityDesc::IfcShellBasedSurfaceModel, DS.SARGS()).staticmethod("IfcShellBasedSurfaceModel")
        .def("IfcSimpleProperty", &PyIfcEntityDesc::IfcSimpleProperty, DS.SARGS()).staticmethod("IfcSimpleProperty")
        .def("IfcSimplePropertyTemplate", &PyIfcEntityDesc::IfcSimplePropertyTemplate, DS.SARGS()).staticmethod("IfcSimplePropertyTemplate")
        .def("IfcSite", &PyIfcEntityDesc::IfcSite, DS.SARGS()).staticmethod("IfcSite")
        .def("IfcSlab", &PyIfcEntityDesc::IfcSlab, DS.SARGS()).staticmethod("IfcSlab")
        .def("IfcSlabElementedCase", &PyIfcEntityDesc::IfcSlabElementedCase, DS.SARGS()).staticmethod("IfcSlabElementedCase")
        .def("IfcSlabStandardCase", &PyIfcEntityDesc::IfcSlabStandardCase, DS.SARGS()).staticmethod("IfcSlabStandardCase")
        .def("IfcSlabType", &PyIfcEntityDesc::IfcSlabType, DS.SARGS()).staticmethod("IfcSlabType")
        .def("IfcSlippageConnectionCondition", &PyIfcEntityDesc::IfcSlippageConnectionCondition, DS.SARGS()).staticmethod("IfcSlippageConnectionCondition")
        .def("IfcSolarDevice", &PyIfcEntityDesc::IfcSolarDevice, DS.SARGS()).staticmethod("IfcSolarDevice")
        .def("IfcSolarDeviceType", &PyIfcEntityDesc::IfcSolarDeviceType, DS.SARGS()).staticmethod("IfcSolarDeviceType")
        .def("IfcSolidModel", &PyIfcEntityDesc::IfcSolidModel, DS.SARGS()).staticmethod("IfcSolidModel")
        .def("IfcSoundProperties", &PyIfcEntityDesc::IfcSoundProperties, DS.SARGS()).staticmethod("IfcSoundProperties")
        .def("IfcSoundValue", &PyIfcEntityDesc::IfcSoundValue, DS.SARGS()).staticmethod("IfcSoundValue")
        .def("IfcSpace", &PyIfcEntityDesc::IfcSpace, DS.SARGS()).staticmethod("IfcSpace")
        .def("IfcSpaceHeater", &PyIfcEntityDesc::IfcSpaceHeater, DS.SARGS()).staticmethod("IfcSpaceHeater")
        .def("IfcSpaceHeaterType", &PyIfcEntityDesc::IfcSpaceHeaterType, DS.SARGS()).staticmethod("IfcSpaceHeaterType")
        .def("IfcSpaceProgram", &PyIfcEntityDesc::IfcSpaceProgram, DS.SARGS()).staticmethod("IfcSpaceProgram")
        .def("IfcSpaceThermalLoadProperties", &PyIfcEntityDesc::IfcSpaceThermalLoadProperties, DS.SARGS()).staticmethod("IfcSpaceThermalLoadProperties")
        .def("IfcSpaceType", &PyIfcEntityDesc::IfcSpaceType, DS.SARGS()).staticmethod("IfcSpaceType")
        .def("IfcSpatialElement", &PyIfcEntityDesc::IfcSpatialElement, DS.SARGS()).staticmethod("IfcSpatialElement")
        .def("IfcSpatialElementType", &PyIfcEntityDesc::IfcSpatialElementType, DS.SARGS()).staticmethod("IfcSpatialElementType")
        .def("IfcSpatialStructureElement", &PyIfcEntityDesc::IfcSpatialStructureElement, DS.SARGS()).staticmethod("IfcSpatialStructureElement")
        .def("IfcSpatialStructureElementType", &PyIfcEntityDesc::IfcSpatialStructureElementType, DS.SARGS()).staticmethod("IfcSpatialStructureElementType")
        .def("IfcSpatialZone", &PyIfcEntityDesc::IfcSpatialZone, DS.SARGS()).staticmethod("IfcSpatialZone")
        .def("IfcSpatialZoneType", &PyIfcEntityDesc::IfcSpatialZoneType, DS.SARGS()).staticmethod("IfcSpatialZoneType")
        .def("IfcSphere", &PyIfcEntityDesc::IfcSphere, DS.SARGS()).staticmethod("IfcSphere")
        .def("IfcSphericalSurface", &PyIfcEntityDesc::IfcSphericalSurface, DS.SARGS()).staticmethod("IfcSphericalSurface")
        .def("IfcStackTerminal", &PyIfcEntityDesc::IfcStackTerminal, DS.SARGS()).staticmethod("IfcStackTerminal")
        .def("IfcStackTerminalType", &PyIfcEntityDesc::IfcStackTerminalType, DS.SARGS()).staticmethod("IfcStackTerminalType")
        .def("IfcStair", &PyIfcEntityDesc::IfcStair, DS.SARGS()).staticmethod("IfcStair")
        .def("IfcStairFlight", &PyIfcEntityDesc::IfcStairFlight, DS.SARGS()).staticmethod("IfcStairFlight")
        .def("IfcStairFlightType", &PyIfcEntityDesc::IfcStairFlightType, DS.SARGS()).staticmethod("IfcStairFlightType")
        .def("IfcStairType", &PyIfcEntityDesc::IfcStairType, DS.SARGS()).staticmethod("IfcStairType")
        .def("IfcStructuralAction", &PyIfcEntityDesc::IfcStructuralAction, DS.SARGS()).staticmethod("IfcStructuralAction")
        .def("IfcStructuralActivity", &PyIfcEntityDesc::IfcStructuralActivity, DS.SARGS()).staticmethod("IfcStructuralActivity")
        .def("IfcStructuralAnalysisModel", &PyIfcEntityDesc::IfcStructuralAnalysisModel, DS.SARGS()).staticmethod("IfcStructuralAnalysisModel")
        .def("IfcStructuralConnection", &PyIfcEntityDesc::IfcStructuralConnection, DS.SARGS()).staticmethod("IfcStructuralConnection")
        .def("IfcStructuralConnectionCondition", &PyIfcEntityDesc::IfcStructuralConnectionCondition, DS.SARGS()).staticmethod("IfcStructuralConnectionCondition")
        .def("IfcStructuralCurveAction", &PyIfcEntityDesc::IfcStructuralCurveAction, DS.SARGS()).staticmethod("IfcStructuralCurveAction")
        .def("IfcStructuralCurveConnection", &PyIfcEntityDesc::IfcStructuralCurveConnection, DS.SARGS()).staticmethod("IfcStructuralCurveConnection")
        .def("IfcStructuralCurveMember", &PyIfcEntityDesc::IfcStructuralCurveMember, DS.SARGS()).staticmethod("IfcStructuralCurveMember")
        .def("IfcStructuralCurveMemberVarying", &PyIfcEntityDesc::IfcStructuralCurveMemberVarying, DS.SARGS()).staticmethod("IfcStructuralCurveMemberVarying")
        .def("IfcStructuralCurveReaction", &PyIfcEntityDesc::IfcStructuralCurveReaction, DS.SARGS()).staticmethod("IfcStructuralCurveReaction")
        .def("IfcStructuralItem", &PyIfcEntityDesc::IfcStructuralItem, DS.SARGS()).staticmethod("IfcStructuralItem")
        .def("IfcStructuralLinearAction", &PyIfcEntityDesc::IfcStructuralLinearAction, DS.SARGS()).staticmethod("IfcStructuralLinearAction")
        .def("IfcStructuralLinearActionVarying", &PyIfcEntityDesc::IfcStructuralLinearActionVarying, DS.SARGS()).staticmethod("IfcStructuralLinearActionVarying")
        .def("IfcStructuralLoad", &PyIfcEntityDesc::IfcStructuralLoad, DS.SARGS()).staticmethod("IfcStructuralLoad")
        .def("IfcStructuralLoadCase", &PyIfcEntityDesc::IfcStructuralLoadCase, DS.SARGS()).staticmethod("IfcStructuralLoadCase")
        .def("IfcStructuralLoadConfiguration", &PyIfcEntityDesc::IfcStructuralLoadConfiguration, DS.SARGS()).staticmethod("IfcStructuralLoadConfiguration")
        .def("IfcStructuralLoadGroup", &PyIfcEntityDesc::IfcStructuralLoadGroup, DS.SARGS()).staticmethod("IfcStructuralLoadGroup")
        .def("IfcStructuralLoadLinearForce", &PyIfcEntityDesc::IfcStructuralLoadLinearForce, DS.SARGS()).staticmethod("IfcStructuralLoadLinearForce")
        .def("IfcStructuralLoadOrResult", &PyIfcEntityDesc::IfcStructuralLoadOrResult, DS.SARGS()).staticmethod("IfcStructuralLoadOrResult")
        .def("IfcStructuralLoadPlanarForce", &PyIfcEntityDesc::IfcStructuralLoadPlanarForce, DS.SARGS()).staticmethod("IfcStructuralLoadPlanarForce")
        .def("IfcStructuralLoadSingleDisplacement", &PyIfcEntityDesc::IfcStructuralLoadSingleDisplacement, DS.SARGS()).staticmethod("IfcStructuralLoadSingleDisplacement")
        .def("IfcStructuralLoadSingleDisplacementDistortion", &PyIfcEntityDesc::IfcStructuralLoadSingleDisplacementDistortion, DS.SARGS()).staticmethod("IfcStructuralLoadSingleDisplacementDistortion")
        .def("IfcStructuralLoadSingleForce", &PyIfcEntityDesc::IfcStructuralLoadSingleForce, DS.SARGS()).staticmethod("IfcStructuralLoadSingleForce")
        .def("IfcStructuralLoadSingleForceWarping", &PyIfcEntityDesc::IfcStructuralLoadSingleForceWarping, DS.SARGS()).staticmethod("IfcStructuralLoadSingleForceWarping")
        .def("IfcStructuralLoadStatic", &PyIfcEntityDesc::IfcStructuralLoadStatic, DS.SARGS()).staticmethod("IfcStructuralLoadStatic")
        .def("IfcStructuralLoadTemperature", &PyIfcEntityDesc::IfcStructuralLoadTemperature, DS.SARGS()).staticmethod("IfcStructuralLoadTemperature")
        .def("IfcStructuralMember", &PyIfcEntityDesc::IfcStructuralMember, DS.SARGS()).staticmethod("IfcStructuralMember")
        .def("IfcStructuralPlanarAction", &PyIfcEntityDesc::IfcStructuralPlanarAction, DS.SARGS()).staticmethod("IfcStructuralPlanarAction")
        .def("IfcStructuralPlanarActionVarying", &PyIfcEntityDesc::IfcStructuralPlanarActionVarying, DS.SARGS()).staticmethod("IfcStructuralPlanarActionVarying")
        .def("IfcStructuralPointAction", &PyIfcEntityDesc::IfcStructuralPointAction, DS.SARGS()).staticmethod("IfcStructuralPointAction")
        .def("IfcStructuralPointConnection", &PyIfcEntityDesc::IfcStructuralPointConnection, DS.SARGS()).staticmethod("IfcStructuralPointConnection")
        .def("IfcStructuralPointReaction", &PyIfcEntityDesc::IfcStructuralPointReaction, DS.SARGS()).staticmethod("IfcStructuralPointReaction")
        .def("IfcStructuralProfileProperties", &PyIfcEntityDesc::IfcStructuralProfileProperties, DS.SARGS()).staticmethod("IfcStructuralProfileProperties")
        .def("IfcStructuralReaction", &PyIfcEntityDesc::IfcStructuralReaction, DS.SARGS()).staticmethod("IfcStructuralReaction")
        .def("IfcStructuralResultGroup", &PyIfcEntityDesc::IfcStructuralResultGroup, DS.SARGS()).staticmethod("IfcStructuralResultGroup")
        .def("IfcStructuralSteelProfileProperties", &PyIfcEntityDesc::IfcStructuralSteelProfileProperties, DS.SARGS()).staticmethod("IfcStructuralSteelProfileProperties")
        .def("IfcStructuralSurfaceAction", &PyIfcEntityDesc::IfcStructuralSurfaceAction, DS.SARGS()).staticmethod("IfcStructuralSurfaceAction")
        .def("IfcStructuralSurfaceConnection", &PyIfcEntityDesc::IfcStructuralSurfaceConnection, DS.SARGS()).staticmethod("IfcStructuralSurfaceConnection")
        .def("IfcStructuralSurfaceMember", &PyIfcEntityDesc::IfcStructuralSurfaceMember, DS.SARGS()).staticmethod("IfcStructuralSurfaceMember")
        .def("IfcStructuralSurfaceMemberVarying", &PyIfcEntityDesc::IfcStructuralSurfaceMemberVarying, DS.SARGS()).staticmethod("IfcStructuralSurfaceMemberVarying")
        .def("IfcStructuralSurfaceReaction", &PyIfcEntityDesc::IfcStructuralSurfaceReaction, DS.SARGS()).staticmethod("IfcStructuralSurfaceReaction")
        .def("IfcStructuredDimensionCallout", &PyIfcEntityDesc::IfcStructuredDimensionCallout, DS.SARGS()).staticmethod("IfcStructuredDimensionCallout")
        .def("IfcStyleModel", &PyIfcEntityDesc::IfcStyleModel, DS.SARGS()).staticmethod("IfcStyleModel")
        .def("IfcStyledItem", &PyIfcEntityDesc::IfcStyledItem, DS.SARGS()).staticmethod("IfcStyledItem")
        .def("IfcStyledRepresentation", &PyIfcEntityDesc::IfcStyledRepresentation, DS.SARGS()).staticmethod("IfcStyledRepresentation")
        .def("IfcSubContractResource", &PyIfcEntityDesc::IfcSubContractResource, DS.SARGS()).staticmethod("IfcSubContractResource")
        .def("IfcSubContractResourceType", &PyIfcEntityDesc::IfcSubContractResourceType, DS.SARGS()).staticmethod("IfcSubContractResourceType")
        .def("IfcSubedge", &PyIfcEntityDesc::IfcSubedge, DS.SARGS()).staticmethod("IfcSubedge")
        .def("IfcSurface", &PyIfcEntityDesc::IfcSurface, DS.SARGS()).staticmethod("IfcSurface")
        .def("IfcSurfaceCurve", &PyIfcEntityDesc::IfcSurfaceCurve, DS.SARGS()).staticmethod("IfcSurfaceCurve")
        .def("IfcSurfaceCurveSweptAreaSolid", &PyIfcEntityDesc::IfcSurfaceCurveSweptAreaSolid, DS.SARGS()).staticmethod("IfcSurfaceCurveSweptAreaSolid")
        .def("IfcSurfaceFeature", &PyIfcEntityDesc::IfcSurfaceFeature, DS.SARGS()).staticmethod("IfcSurfaceFeature")
        .def("IfcSurfaceOfLinearExtrusion", &PyIfcEntityDesc::IfcSurfaceOfLinearExtrusion, DS.SARGS()).staticmethod("IfcSurfaceOfLinearExtrusion")
        .def("IfcSurfaceOfRevolution", &PyIfcEntityDesc::IfcSurfaceOfRevolution, DS.SARGS()).staticmethod("IfcSurfaceOfRevolution")
        .def("IfcSurfaceReinforcementArea", &PyIfcEntityDesc::IfcSurfaceReinforcementArea, DS.SARGS()).staticmethod("IfcSurfaceReinforcementArea")
        .def("IfcSurfaceStyle", &PyIfcEntityDesc::IfcSurfaceStyle, DS.SARGS()).staticmethod("IfcSurfaceStyle")
        .def("IfcSurfaceStyleLighting", &PyIfcEntityDesc::IfcSurfaceStyleLighting, DS.SARGS()).staticmethod("IfcSurfaceStyleLighting")
        .def("IfcSurfaceStyleRefraction", &PyIfcEntityDesc::IfcSurfaceStyleRefraction, DS.SARGS()).staticmethod("IfcSurfaceStyleRefraction")
        .def("IfcSurfaceStyleRendering", &PyIfcEntityDesc::IfcSurfaceStyleRendering, DS.SARGS()).staticmethod("IfcSurfaceStyleRendering")
        .def("IfcSurfaceStyleShading", &PyIfcEntityDesc::IfcSurfaceStyleShading, DS.SARGS()).staticmethod("IfcSurfaceStyleShading")
        .def("IfcSurfaceStyleWithTextures", &PyIfcEntityDesc::IfcSurfaceStyleWithTextures, DS.SARGS()).staticmethod("IfcSurfaceStyleWithTextures")
        .def("IfcSurfaceTexture", &PyIfcEntityDesc::IfcSurfaceTexture, DS.SARGS()).staticmethod("IfcSurfaceTexture")
        .def("IfcSweptAreaSolid", &PyIfcEntityDesc::IfcSweptAreaSolid, DS.SARGS()).staticmethod("IfcSweptAreaSolid")
        .def("IfcSweptDiskSolid", &PyIfcEntityDesc::IfcSweptDiskSolid, DS.SARGS()).staticmethod("IfcSweptDiskSolid")
        .def("IfcSweptDiskSolidPolygonal", &PyIfcEntityDesc::IfcSweptDiskSolidPolygonal, DS.SARGS()).staticmethod("IfcSweptDiskSolidPolygonal")
        .def("IfcSweptSurface", &PyIfcEntityDesc::IfcSweptSurface, DS.SARGS()).staticmethod("IfcSweptSurface")
        .def("IfcSwitchingDevice", &PyIfcEntityDesc::IfcSwitchingDevice, DS.SARGS()).staticmethod("IfcSwitchingDevice")
        .def("IfcSwitchingDeviceType", &PyIfcEntityDesc::IfcSwitchingDeviceType, DS.SARGS()).staticmethod("IfcSwitchingDeviceType")
        .def("IfcSymbolStyle", &PyIfcEntityDesc::IfcSymbolStyle, DS.SARGS()).staticmethod("IfcSymbolStyle")
        .def("IfcSystem", &PyIfcEntityDesc::IfcSystem, DS.SARGS()).staticmethod("IfcSystem")
        .def("IfcSystemFurnitureElement", &PyIfcEntityDesc::IfcSystemFurnitureElement, DS.SARGS()).staticmethod("IfcSystemFurnitureElement")
        .def("IfcSystemFurnitureElementType", &PyIfcEntityDesc::IfcSystemFurnitureElementType, DS.SARGS()).staticmethod("IfcSystemFurnitureElementType")
        .def("IfcTShapeProfileDef", &PyIfcEntityDesc::IfcTShapeProfileDef, DS.SARGS()).staticmethod("IfcTShapeProfileDef")
        .def("IfcTable", &PyIfcEntityDesc::IfcTable, DS.SARGS()).staticmethod("IfcTable")
        .def("IfcTableColumn", &PyIfcEntityDesc::IfcTableColumn, DS.SARGS()).staticmethod("IfcTableColumn")
        .def("IfcTableRow", &PyIfcEntityDesc::IfcTableRow, DS.SARGS()).staticmethod("IfcTableRow")
        .def("IfcTank", &PyIfcEntityDesc::IfcTank, DS.SARGS()).staticmethod("IfcTank")
        .def("IfcTankType", &PyIfcEntityDesc::IfcTankType, DS.SARGS()).staticmethod("IfcTankType")
        .def("IfcTask", &PyIfcEntityDesc::IfcTask, DS.SARGS()).staticmethod("IfcTask")
        .def("IfcTaskTime", &PyIfcEntityDesc::IfcTaskTime, DS.SARGS()).staticmethod("IfcTaskTime")
        .def("IfcTaskTimeRecurring", &PyIfcEntityDesc::IfcTaskTimeRecurring, DS.SARGS()).staticmethod("IfcTaskTimeRecurring")
        .def("IfcTaskType", &PyIfcEntityDesc::IfcTaskType, DS.SARGS()).staticmethod("IfcTaskType")
        .def("IfcTelecomAddress", &PyIfcEntityDesc::IfcTelecomAddress, DS.SARGS()).staticmethod("IfcTelecomAddress")
        .def("IfcTendon", &PyIfcEntityDesc::IfcTendon, DS.SARGS()).staticmethod("IfcTendon")
        .def("IfcTendonAnchor", &PyIfcEntityDesc::IfcTendonAnchor, DS.SARGS()).staticmethod("IfcTendonAnchor")
        .def("IfcTendonAnchorType", &PyIfcEntityDesc::IfcTendonAnchorType, DS.SARGS()).staticmethod("IfcTendonAnchorType")
        .def("IfcTendonType", &PyIfcEntityDesc::IfcTendonType, DS.SARGS()).staticmethod("IfcTendonType")
        .def("IfcTerminatorSymbol", &PyIfcEntityDesc::IfcTerminatorSymbol, DS.SARGS()).staticmethod("IfcTerminatorSymbol")
        .def("IfcTessellatedFaceSet", &PyIfcEntityDesc::IfcTessellatedFaceSet, DS.SARGS()).staticmethod("IfcTessellatedFaceSet")
        .def("IfcTessellatedItem", &PyIfcEntityDesc::IfcTessellatedItem, DS.SARGS()).staticmethod("IfcTessellatedItem")
        .def("IfcTextLiteral", &PyIfcEntityDesc::IfcTextLiteral, DS.SARGS()).staticmethod("IfcTextLiteral")
        .def("IfcTextLiteralWithExtent", &PyIfcEntityDesc::IfcTextLiteralWithExtent, DS.SARGS()).staticmethod("IfcTextLiteralWithExtent")
        .def("IfcTextStyle", &PyIfcEntityDesc::IfcTextStyle, DS.SARGS()).staticmethod("IfcTextStyle")
        .def("IfcTextStyleFontModel", &PyIfcEntityDesc::IfcTextStyleFontModel, DS.SARGS()).staticmethod("IfcTextStyleFontModel")
        .def("IfcTextStyleForDefinedFont", &PyIfcEntityDesc::IfcTextStyleForDefinedFont, DS.SARGS()).staticmethod("IfcTextStyleForDefinedFont")
        .def("IfcTextStyleTextModel", &PyIfcEntityDesc::IfcTextStyleTextModel, DS.SARGS()).staticmethod("IfcTextStyleTextModel")
        .def("IfcTextStyleWithBoxCharacteristics", &PyIfcEntityDesc::IfcTextStyleWithBoxCharacteristics, DS.SARGS()).staticmethod("IfcTextStyleWithBoxCharacteristics")
        .def("IfcTextureCoordinate", &PyIfcEntityDesc::IfcTextureCoordinate, DS.SARGS()).staticmethod("IfcTextureCoordinate")
        .def("IfcTextureCoordinateGenerator", &PyIfcEntityDesc::IfcTextureCoordinateGenerator, DS.SARGS()).staticmethod("IfcTextureCoordinateGenerator")
        .def("IfcTextureMap", &PyIfcEntityDesc::IfcTextureMap, DS.SARGS()).staticmethod("IfcTextureMap")
        .def("IfcTextureVertex", &PyIfcEntityDesc::IfcTextureVertex, DS.SARGS()).staticmethod("IfcTextureVertex")
        .def("IfcTextureVertexList", &PyIfcEntityDesc::IfcTextureVertexList, DS.SARGS()).staticmethod("IfcTextureVertexList")
        .def("IfcThermalMaterialProperties", &PyIfcEntityDesc::IfcThermalMaterialProperties, DS.SARGS()).staticmethod("IfcThermalMaterialProperties")
        .def("IfcTimePeriod", &PyIfcEntityDesc::IfcTimePeriod, DS.SARGS()).staticmethod("IfcTimePeriod")
        .def("IfcTimeSeries", &PyIfcEntityDesc::IfcTimeSeries, DS.SARGS()).staticmethod("IfcTimeSeries")
        .def("IfcTimeSeriesReferenceRelationship", &PyIfcEntityDesc::IfcTimeSeriesReferenceRelationship, DS.SARGS()).staticmethod("IfcTimeSeriesReferenceRelationship")
        .def("IfcTimeSeriesSchedule", &PyIfcEntityDesc::IfcTimeSeriesSchedule, DS.SARGS()).staticmethod("IfcTimeSeriesSchedule")
        .def("IfcTimeSeriesValue", &PyIfcEntityDesc::IfcTimeSeriesValue, DS.SARGS()).staticmethod("IfcTimeSeriesValue")
        .def("IfcTopologicalRepresentationItem", &PyIfcEntityDesc::IfcTopologicalRepresentationItem, DS.SARGS()).staticmethod("IfcTopologicalRepresentationItem")
        .def("IfcTopologyRepresentation", &PyIfcEntityDesc::IfcTopologyRepresentation, DS.SARGS()).staticmethod("IfcTopologyRepresentation")
        .def("IfcToroidalSurface", &PyIfcEntityDesc::IfcToroidalSurface, DS.SARGS()).staticmethod("IfcToroidalSurface")
        .def("IfcTransformer", &PyIfcEntityDesc::IfcTransformer, DS.SARGS()).staticmethod("IfcTransformer")
        .def("IfcTransformerType", &PyIfcEntityDesc::IfcTransformerType, DS.SARGS()).staticmethod("IfcTransformerType")
        .def("IfcTransitionCurveSegment2D", &PyIfcEntityDesc::IfcTransitionCurveSegment2D, DS.SARGS()).staticmethod("IfcTransitionCurveSegment2D")
        .def("IfcTransportElement", &PyIfcEntityDesc::IfcTransportElement, DS.SARGS()).staticmethod("IfcTransportElement")
        .def("IfcTransportElementType", &PyIfcEntityDesc::IfcTransportElementType, DS.SARGS()).staticmethod("IfcTransportElementType")
        .def("IfcTrapeziumProfileDef", &PyIfcEntityDesc::IfcTrapeziumProfileDef, DS.SARGS()).staticmethod("IfcTrapeziumProfileDef")
        .def("IfcTriangulatedFaceSet", &PyIfcEntityDesc::IfcTriangulatedFaceSet, DS.SARGS()).staticmethod("IfcTriangulatedFaceSet")
        .def("IfcTriangulatedIrregularNetwork", &PyIfcEntityDesc::IfcTriangulatedIrregularNetwork, DS.SARGS()).staticmethod("IfcTriangulatedIrregularNetwork")
        .def("IfcTrimmedCurve", &PyIfcEntityDesc::IfcTrimmedCurve, DS.SARGS()).staticmethod("IfcTrimmedCurve")
        .def("IfcTubeBundle", &PyIfcEntityDesc::IfcTubeBundle, DS.SARGS()).staticmethod("IfcTubeBundle")
        .def("IfcTubeBundleType", &PyIfcEntityDesc::IfcTubeBundleType, DS.SARGS()).staticmethod("IfcTubeBundleType")
        .def("IfcTwoDirectionRepeatFactor", &PyIfcEntityDesc::IfcTwoDirectionRepeatFactor, DS.SARGS()).staticmethod("IfcTwoDirectionRepeatFactor")
        .def("IfcTypeObject", &PyIfcEntityDesc::IfcTypeObject, DS.SARGS()).staticmethod("IfcTypeObject")
        .def("IfcTypeProcess", &PyIfcEntityDesc::IfcTypeProcess, DS.SARGS()).staticmethod("IfcTypeProcess")
        .def("IfcTypeProduct", &PyIfcEntityDesc::IfcTypeProduct, DS.SARGS()).staticmethod("IfcTypeProduct")
        .def("IfcTypeResource", &PyIfcEntityDesc::IfcTypeResource, DS.SARGS()).staticmethod("IfcTypeResource")
        .def("IfcUShapeProfileDef", &PyIfcEntityDesc::IfcUShapeProfileDef, DS.SARGS()).staticmethod("IfcUShapeProfileDef")
        .def("IfcUnitAssignment", &PyIfcEntityDesc::IfcUnitAssignment, DS.SARGS()).staticmethod("IfcUnitAssignment")
        .def("IfcUnitaryControlElement", &PyIfcEntityDesc::IfcUnitaryControlElement, DS.SARGS()).staticmethod("IfcUnitaryControlElement")
        .def("IfcUnitaryControlElementType", &PyIfcEntityDesc::IfcUnitaryControlElementType, DS.SARGS()).staticmethod("IfcUnitaryControlElementType")
        .def("IfcUnitaryEquipment", &PyIfcEntityDesc::IfcUnitaryEquipment, DS.SARGS()).staticmethod("IfcUnitaryEquipment")
        .def("IfcUnitaryEquipmentType", &PyIfcEntityDesc::IfcUnitaryEquipmentType, DS.SARGS()).staticmethod("IfcUnitaryEquipmentType")
        .def("IfcValve", &PyIfcEntityDesc::IfcValve, DS.SARGS()).staticmethod("IfcValve")
        .def("IfcValveType", &PyIfcEntityDesc::IfcValveType, DS.SARGS()).staticmethod("IfcValveType")
        .def("IfcVector", &PyIfcEntityDesc::IfcVector, DS.SARGS()).staticmethod("IfcVector")
        .def("IfcVertex", &PyIfcEntityDesc::IfcVertex, DS.SARGS()).staticmethod("IfcVertex")
        .def("IfcVertexBasedTextureMap", &PyIfcEntityDesc::IfcVertexBasedTextureMap, DS.SARGS()).staticmethod("IfcVertexBasedTextureMap")
        .def("IfcVertexLoop", &PyIfcEntityDesc::IfcVertexLoop, DS.SARGS()).staticmethod("IfcVertexLoop")
        .def("IfcVertexPoint", &PyIfcEntityDesc::IfcVertexPoint, DS.SARGS()).staticmethod("IfcVertexPoint")
        .def("IfcVibrationIsolator", &PyIfcEntityDesc::IfcVibrationIsolator, DS.SARGS()).staticmethod("IfcVibrationIsolator")
        .def("IfcVibrationIsolatorType", &PyIfcEntityDesc::IfcVibrationIsolatorType, DS.SARGS()).staticmethod("IfcVibrationIsolatorType")
        .def("IfcVirtualElement", &PyIfcEntityDesc::IfcVirtualElement, DS.SARGS()).staticmethod("IfcVirtualElement")
        .def("IfcVirtualGridIntersection", &PyIfcEntityDesc::IfcVirtualGridIntersection, DS.SARGS()).staticmethod("IfcVirtualGridIntersection")
        .def("IfcVoidingFeature", &PyIfcEntityDesc::IfcVoidingFeature, DS.SARGS()).staticmethod("IfcVoidingFeature")
        .def("IfcWall", &PyIfcEntityDesc::IfcWall, DS.SARGS()).staticmethod("IfcWall")
        .def("IfcWallElementedCase", &PyIfcEntityDesc::IfcWallElementedCase, DS.SARGS()).staticmethod("IfcWallElementedCase")
        .def("IfcWallStandardCase", &PyIfcEntityDesc::IfcWallStandardCase, DS.SARGS()).staticmethod("IfcWallStandardCase")
        .def("IfcWallType", &PyIfcEntityDesc::IfcWallType, DS.SARGS()).staticmethod("IfcWallType")
        .def("IfcWasteTerminal", &PyIfcEntityDesc::IfcWasteTerminal, DS.SARGS()).staticmethod("IfcWasteTerminal")
        .def("IfcWasteTerminalType", &PyIfcEntityDesc::IfcWasteTerminalType, DS.SARGS()).staticmethod("IfcWasteTerminalType")
        .def("IfcWaterProperties", &PyIfcEntityDesc::IfcWaterProperties, DS.SARGS()).staticmethod("IfcWaterProperties")
        .def("IfcWindow", &PyIfcEntityDesc::IfcWindow, DS.SARGS()).staticmethod("IfcWindow")
        .def("IfcWindowLiningProperties", &PyIfcEntityDesc::IfcWindowLiningProperties, DS.SARGS()).staticmethod("IfcWindowLiningProperties")
        .def("IfcWindowPanelProperties", &PyIfcEntityDesc::IfcWindowPanelProperties, DS.SARGS()).staticmethod("IfcWindowPanelProperties")
        .def("IfcWindowStandardCase", &PyIfcEntityDesc::IfcWindowStandardCase, DS.SARGS()).staticmethod("IfcWindowStandardCase")
        .def("IfcWindowStyle", &PyIfcEntityDesc::IfcWindowStyle, DS.SARGS()).staticmethod("IfcWindowStyle")
        .def("IfcWindowType", &PyIfcEntityDesc::IfcWindowType, DS.SARGS()).staticmethod("IfcWindowType")
        .def("IfcWorkCalendar", &PyIfcEntityDesc::IfcWorkCalendar, DS.SARGS()).staticmethod("IfcWorkCalendar")
        .def("IfcWorkControl", &PyIfcEntityDesc::IfcWorkControl, DS.SARGS()).staticmethod("IfcWorkControl")
        .def("IfcWorkPlan", &PyIfcEntityDesc::IfcWorkPlan, DS.SARGS()).staticmethod("IfcWorkPlan")
        .def("IfcWorkSchedule", &PyIfcEntityDesc::IfcWorkSchedule, DS.SARGS()).staticmethod("IfcWorkSchedule")
        .def("IfcWorkTime", &PyIfcEntityDesc::IfcWorkTime, DS.SARGS()).staticmethod("IfcWorkTime")
        .def("IfcZShapeProfileDef", &PyIfcEntityDesc::IfcZShapeProfileDef, DS.SARGS()).staticmethod("IfcZShapeProfileDef")
        .def("IfcZone", &PyIfcEntityDesc::IfcZone, DS.SARGS()).staticmethod("IfcZone")


        .def("className", &PyIfcEntityDesc::className, DS.SARGS()).staticmethod("className")
        ;
}

PyIfcEntityDesc::PyIfcEntityDesc()
    : PyIfcEntityDesc(new Ice::IfcApi::EntityDesc(), true)
{
}

PyIfcEntityDesc::PyIfcEntityDesc(Ice::IfcApi::EntityDesc* pObject, bool autoDelete)
    : m_pyImp(pObject, PySharedObjectDeleter<Ice::IfcApi::EntityDesc>(autoDelete))
{
}

PyIfcEntityDesc::PyIfcEntityDesc(const Ice::IfcApi::EntityDesc* pObject)
    : PyIfcEntityDesc(const_cast<Ice::IfcApi::EntityDesc*>(pObject), false)
{
}

bool PyIfcEntityDesc::isDerivedFrom(const PyIfcEntityDesc& obj, Ice::EIfcSchemaId eSchema) const
{
    return impObj()->isDerivedFrom(*obj.impObj(), eSchema);
}

std::string PyIfcEntityDesc::name()
{
    return std::string((const char*)*impObj());
}

PyIfcEntityDesc PyIfcEntityDesc::Ifc2DCompositeCurve()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::Ifc2DCompositeCurve));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcActionRequest()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcActionRequest));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcActor()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcActor));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcActorRole()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcActorRole));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcActuator()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcActuator));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcActuatorType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcActuatorType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcAddress()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcAddress));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcAdvancedBrep()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcAdvancedBrep));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcAdvancedBrepWithVoids()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcAdvancedBrepWithVoids));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcAdvancedFace()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcAdvancedFace));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcAirTerminal()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcAirTerminal));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcAirTerminalBox()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcAirTerminalBox));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcAirTerminalBoxType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcAirTerminalBoxType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcAirTerminalType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcAirTerminalType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcAirToAirHeatRecovery()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcAirToAirHeatRecovery));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcAirToAirHeatRecoveryType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcAirToAirHeatRecoveryType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcAlarm()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcAlarm));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcAlarmType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcAlarmType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcAlignment()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcAlignment));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcAlignment2DHorizontal()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcAlignment2DHorizontal));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcAlignment2DHorizontalSegment()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcAlignment2DHorizontalSegment));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcAlignment2DSegment()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcAlignment2DSegment));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcAlignment2DVerSegCircularArc()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcAlignment2DVerSegCircularArc));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcAlignment2DVerSegLine()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcAlignment2DVerSegLine));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcAlignment2DVerSegParabolicArc()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcAlignment2DVerSegParabolicArc));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcAlignment2DVertical()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcAlignment2DVertical));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcAlignment2DVerticalSegment()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcAlignment2DVerticalSegment));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcAlignmentCurve()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcAlignmentCurve));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcAngularDimension()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcAngularDimension));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcAnnotation()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcAnnotation));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcAnnotationCurveOccurrence()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcAnnotationCurveOccurrence));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcAnnotationFillArea()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcAnnotationFillArea));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcAnnotationFillAreaOccurrence()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcAnnotationFillAreaOccurrence));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcAnnotationOccurrence()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcAnnotationOccurrence));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcAnnotationSurface()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcAnnotationSurface));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcAnnotationSurfaceOccurrence()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcAnnotationSurfaceOccurrence));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcAnnotationSymbolOccurrence()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcAnnotationSymbolOccurrence));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcAnnotationTextOccurrence()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcAnnotationTextOccurrence));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcApplication()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcApplication));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcAppliedValue()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcAppliedValue));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcAppliedValueRelationship()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcAppliedValueRelationship));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcApproval()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcApproval));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcApprovalActorRelationship()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcApprovalActorRelationship));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcApprovalPropertyRelationship()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcApprovalPropertyRelationship));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcApprovalRelationship()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcApprovalRelationship));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcArbitraryClosedProfileDef()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcArbitraryClosedProfileDef));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcArbitraryOpenProfileDef()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcArbitraryOpenProfileDef));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcArbitraryProfileDefWithVoids()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcArbitraryProfileDefWithVoids));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcAsset()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcAsset));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcAsymmetricIShapeProfileDef()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcAsymmetricIShapeProfileDef));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcAudioVisualAppliance()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcAudioVisualAppliance));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcAudioVisualApplianceType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcAudioVisualApplianceType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcAxis1Placement()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcAxis1Placement));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcAxis2Placement2D()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcAxis2Placement2D));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcAxis2Placement3D()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcAxis2Placement3D));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcBSplineCurve()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcBSplineCurve));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcBSplineCurveWithKnots()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcBSplineCurveWithKnots));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcBSplineSurface()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcBSplineSurface));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcBSplineSurfaceWithKnots()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcBSplineSurfaceWithKnots));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcBeam()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcBeam));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcBeamStandardCase()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcBeamStandardCase));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcBeamType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcBeamType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcBezierCurve()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcBezierCurve));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcBlobTexture()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcBlobTexture));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcBlock()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcBlock));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcBoiler()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcBoiler));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcBoilerType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcBoilerType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcBooleanClippingResult()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcBooleanClippingResult));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcBooleanResult()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcBooleanResult));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcBoundaryCondition()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcBoundaryCondition));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcBoundaryCurve()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcBoundaryCurve));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcBoundaryEdgeCondition()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcBoundaryEdgeCondition));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcBoundaryFaceCondition()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcBoundaryFaceCondition));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcBoundaryNodeCondition()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcBoundaryNodeCondition));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcBoundaryNodeConditionWarping()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcBoundaryNodeConditionWarping));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcBoundedCurve()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcBoundedCurve));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcBoundedSurface()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcBoundedSurface));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcBoundingBox()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcBoundingBox));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcBoxedHalfSpace()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcBoxedHalfSpace));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcBuilding()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcBuilding));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcBuildingElement()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcBuildingElement));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcBuildingElementComponent()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcBuildingElementComponent));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcBuildingElementPart()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcBuildingElementPart));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcBuildingElementPartType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcBuildingElementPartType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcBuildingElementProxy()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcBuildingElementProxy));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcBuildingElementProxyType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcBuildingElementProxyType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcBuildingElementType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcBuildingElementType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcBuildingStorey()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcBuildingStorey));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcBuildingSystem()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcBuildingSystem));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcBurner()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcBurner));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcBurnerType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcBurnerType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcCShapeProfileDef()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcCShapeProfileDef));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcCableCarrierFitting()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcCableCarrierFitting));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcCableCarrierFittingType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcCableCarrierFittingType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcCableCarrierSegment()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcCableCarrierSegment));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcCableCarrierSegmentType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcCableCarrierSegmentType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcCableFitting()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcCableFitting));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcCableFittingType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcCableFittingType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcCableSegment()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcCableSegment));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcCableSegmentType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcCableSegmentType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcCalendarDate()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcCalendarDate));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcCartesianPoint()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcCartesianPoint));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcCartesianPointList()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcCartesianPointList));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcCartesianPointList2D()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcCartesianPointList2D));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcCartesianPointList3D()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcCartesianPointList3D));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcCartesianTransformationOperator()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcCartesianTransformationOperator));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcCartesianTransformationOperator2D()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcCartesianTransformationOperator2D));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcCartesianTransformationOperator2DnonUniform()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcCartesianTransformationOperator2DnonUniform));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcCartesianTransformationOperator3D()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcCartesianTransformationOperator3D));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcCartesianTransformationOperator3DnonUniform()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcCartesianTransformationOperator3DnonUniform));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcCenterLineProfileDef()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcCenterLineProfileDef));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcChamferEdgeFeature()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcChamferEdgeFeature));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcChiller()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcChiller));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcChillerType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcChillerType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcChimney()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcChimney));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcChimneyType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcChimneyType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcCircle()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcCircle));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcCircleHollowProfileDef()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcCircleHollowProfileDef));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcCircleProfileDef()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcCircleProfileDef));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcCircularArcSegment2D()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcCircularArcSegment2D));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcCivilElement()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcCivilElement));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcClassification()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcClassification));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcClassificationItem()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcClassificationItem));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcClassificationItemRelationship()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcClassificationItemRelationship));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcClassificationNotation()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcClassificationNotation));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcClassificationNotationFacet()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcClassificationNotationFacet));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcClassificationReference()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcClassificationReference));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcClosedShell()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcClosedShell));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcCoil()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcCoil));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcCoilType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcCoilType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcColourRgb()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcColourRgb));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcColourRgbList()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcColourRgbList));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcColourSpecification()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcColourSpecification));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcColumn()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcColumn));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcColumnStandardCase()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcColumnStandardCase));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcColumnType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcColumnType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcCommunicationsAppliance()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcCommunicationsAppliance));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcCommunicationsApplianceType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcCommunicationsApplianceType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcComplexProperty()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcComplexProperty));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcComplexPropertyTemplate()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcComplexPropertyTemplate));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcCompositeCurve()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcCompositeCurve));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcCompositeCurveOnSurface()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcCompositeCurveOnSurface));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcCompositeCurveSegment()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcCompositeCurveSegment));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcCompositeProfileDef()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcCompositeProfileDef));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcCompressor()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcCompressor));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcCompressorType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcCompressorType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcCondenser()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcCondenser));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcCondenserType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcCondenserType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcCondition()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcCondition));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcConditionCriterion()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcConditionCriterion));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcConnectedFaceSet()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcConnectedFaceSet));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcCivilElementType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcCivilElementType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcConic()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcConic));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcConnectionCurveGeometry()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcConnectionCurveGeometry));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcConnectionGeometry()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcConnectionGeometry));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcConnectionPointEccentricity()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcConnectionPointEccentricity));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcConnectionPointGeometry()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcConnectionPointGeometry));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcConnectionPortGeometry()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcConnectionPortGeometry));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcConnectionSurfaceGeometry()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcConnectionSurfaceGeometry));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcConnectionVolumeGeometry()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcConnectionVolumeGeometry));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcConstraint()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcConstraint));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcConstraintAggregationRelationship()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcConstraintAggregationRelationship));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcConstraintClassificationRelationship()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcConstraintClassificationRelationship));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcConstraintRelationship()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcConstraintRelationship));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcConstructionEquipmentResource()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcConstructionEquipmentResource));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcConstructionEquipmentResourceType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcConstructionEquipmentResourceType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcConstructionMaterialResource()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcConstructionMaterialResource));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcConstructionMaterialResourceType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcConstructionMaterialResourceType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcConstructionProductResource()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcConstructionProductResource));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcConstructionProductResourceType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcConstructionProductResourceType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcConstructionResource()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcConstructionResource));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcConstructionResourceType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcConstructionResourceType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcContext()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcContext));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcContextDependentUnit()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcContextDependentUnit));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcControl()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcControl));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcController()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcController));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcControllerType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcControllerType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcConversionBasedUnit()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcConversionBasedUnit));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcConversionBasedUnitWithOffset()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcConversionBasedUnitWithOffset));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcCooledBeam()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcCooledBeam));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcCooledBeamType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcCooledBeamType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcCoolingTower()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcCoolingTower));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcCoolingTowerType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcCoolingTowerType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcCoordinateOperation()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcCoordinateOperation));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcCoordinateReferenceSystem()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcCoordinateReferenceSystem));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcCoordinatedUniversalTimeOffset()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcCoordinatedUniversalTimeOffset));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcCostItem()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcCostItem));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcCostSchedule()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcCostSchedule));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcCostValue()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcCostValue));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcCovering()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcCovering));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcCoveringType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcCoveringType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcCraneRailAShapeProfileDef()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcCraneRailAShapeProfileDef));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcCraneRailFShapeProfileDef()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcCraneRailFShapeProfileDef));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcCrewResource()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcCrewResource));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcCrewResourceType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcCrewResourceType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcCsgPrimitive3D()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcCsgPrimitive3D));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcCsgSolid()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcCsgSolid));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcCurrencyRelationship()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcCurrencyRelationship));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcCurtainWall()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcCurtainWall));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcCurtainWallType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcCurtainWallType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcCurve()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcCurve));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcCurveBoundedPlane()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcCurveBoundedPlane));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcCurveBoundedSurface()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcCurveBoundedSurface));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcCurveSegment2D()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcCurveSegment2D));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcCurveStyle()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcCurveStyle));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcCurveStyleFont()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcCurveStyleFont));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcCurveStyleFontAndScaling()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcCurveStyleFontAndScaling));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcCurveStyleFontPattern()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcCurveStyleFontPattern));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcCylindricalSurface()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcCylindricalSurface));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcDamper()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcDamper));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcDamperType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcDamperType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcDateAndTime()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcDateAndTime));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcDefinedSymbol()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcDefinedSymbol));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcDerivedProfileDef()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcDerivedProfileDef));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcDerivedUnit()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcDerivedUnit));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcDerivedUnitElement()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcDerivedUnitElement));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcDiameterDimension()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcDiameterDimension));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcDimensionCalloutRelationship()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcDimensionCalloutRelationship));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcDimensionCurve()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcDimensionCurve));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcDimensionCurveDirectedCallout()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcDimensionCurveDirectedCallout));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcDimensionCurveTerminator()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcDimensionCurveTerminator));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcDimensionPair()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcDimensionPair));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcDimensionalExponents()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcDimensionalExponents));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcDirection()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcDirection));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcDiscreteAccessory()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcDiscreteAccessory));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcDiscreteAccessoryType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcDiscreteAccessoryType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcDistanceExpression()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcDistanceExpression));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcDistributionChamberElement()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcDistributionChamberElement));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcDistributionChamberElementType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcDistributionChamberElementType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcDistributionCircuit()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcDistributionCircuit));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcDistributionControlElement()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcDistributionControlElement));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcDistributionControlElementType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcDistributionControlElementType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcDistributionElement()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcDistributionElement));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcDistributionElementType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcDistributionElementType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcDistributionFlowElement()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcDistributionFlowElement));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcDistributionFlowElementType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcDistributionFlowElementType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcDistributionPort()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcDistributionPort));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcDistributionSystem()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcDistributionSystem));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcDocumentElectronicFormat()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcDocumentElectronicFormat));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcDocumentInformation()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcDocumentInformation));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcDocumentInformationRelationship()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcDocumentInformationRelationship));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcDocumentReference()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcDocumentReference));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcDoor()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcDoor));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcDoorLiningProperties()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcDoorLiningProperties));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcDoorPanelProperties()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcDoorPanelProperties));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcDoorStandardCase()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcDoorStandardCase));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcDoorStyle()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcDoorStyle));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcDoorType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcDoorType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcDraughtingCallout()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcDraughtingCallout));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcDraughtingCalloutRelationship()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcDraughtingCalloutRelationship));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcDraughtingPreDefinedColour()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcDraughtingPreDefinedColour));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcDraughtingPreDefinedCurveFont()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcDraughtingPreDefinedCurveFont));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcDraughtingPreDefinedTextFont()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcDraughtingPreDefinedTextFont));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcDuctFitting()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcDuctFitting));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcDuctFittingType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcDuctFittingType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcDuctSegment()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcDuctSegment));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcDuctSegmentType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcDuctSegmentType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcDuctSilencer()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcDuctSilencer));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcDuctSilencerType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcDuctSilencerType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcEdge()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcEdge));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcEdgeCurve()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcEdgeCurve));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcEdgeFeature()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcEdgeFeature));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcEdgeLoop()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcEdgeLoop));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcElectricAppliance()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcElectricAppliance));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcElectricApplianceType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcElectricApplianceType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcElectricDistributionBoard()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcElectricDistributionBoard));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcElectricDistributionBoardType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcElectricDistributionBoardType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcElectricDistributionPoint()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcElectricDistributionPoint));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcElectricFlowStorageDevice()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcElectricFlowStorageDevice));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcElectricFlowStorageDeviceType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcElectricFlowStorageDeviceType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcElectricGenerator()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcElectricGenerator));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcElectricGeneratorType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcElectricGeneratorType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcElectricHeaterType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcElectricHeaterType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcElectricMotor()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcElectricMotor));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcElectricMotorType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcElectricMotorType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcElectricTimeControl()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcElectricTimeControl));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcElectricTimeControlType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcElectricTimeControlType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcElectricalBaseProperties()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcElectricalBaseProperties));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcElectricalCircuit()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcElectricalCircuit));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcElectricalElement()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcElectricalElement));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcElement()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcElement));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcElementAssembly()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcElementAssembly));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcElementAssemblyType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcElementAssemblyType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcElementComponent()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcElementComponent));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcElementComponentType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcElementComponentType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcElementQuantity()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcElementQuantity));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcElementType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcElementType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcElementarySurface()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcElementarySurface));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcEllipse()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcEllipse));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcEllipseProfileDef()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcEllipseProfileDef));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcEnergyConversionDevice()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcEnergyConversionDevice));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcEnergyConversionDeviceType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcEnergyConversionDeviceType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcEnergyProperties()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcEnergyProperties));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcEngine()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcEngine));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcEngineType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcEngineType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcEnvironmentalImpactValue()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcEnvironmentalImpactValue));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcEquipmentElement()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcEquipmentElement));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcEquipmentStandard()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcEquipmentStandard));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcEvaporativeCooler()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcEvaporativeCooler));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcEvaporativeCoolerType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcEvaporativeCoolerType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcEvaporator()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcEvaporator));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcEvaporatorType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcEvaporatorType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcEvent()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcEvent));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcEventTime()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcEventTime));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcEventType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcEventType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcExtendedMaterialProperties()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcExtendedMaterialProperties));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcExtendedProperties()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcExtendedProperties));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcExternalInformation()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcExternalInformation));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcExternalReference()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcExternalReference));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcExternalReferenceRelationship()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcExternalReferenceRelationship));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcExternalSpatialElement()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcExternalSpatialElement));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcExternalSpatialStructureElement()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcExternalSpatialStructureElement));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcExternallyDefinedHatchStyle()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcExternallyDefinedHatchStyle));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcExternallyDefinedSurfaceStyle()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcExternallyDefinedSurfaceStyle));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcExternallyDefinedSymbol()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcExternallyDefinedSymbol));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcExternallyDefinedTextFont()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcExternallyDefinedTextFont));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcExtrudedAreaSolid()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcExtrudedAreaSolid));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcExtrudedAreaSolidTapered()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcExtrudedAreaSolidTapered));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcFace()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcFace));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcFaceBasedSurfaceModel()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcFaceBasedSurfaceModel));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcFaceBound()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcFaceBound));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcFaceOuterBound()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcFaceOuterBound));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcFaceSurface()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcFaceSurface));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcFacetedBrep()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcFacetedBrep));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcFacetedBrepWithVoids()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcFacetedBrepWithVoids));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcFailureConnectionCondition()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcFailureConnectionCondition));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcFan()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcFan));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcFanType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcFanType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcFastener()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcFastener));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcFastenerType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcFastenerType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcFeatureElement()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcFeatureElement));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcFeatureElementAddition()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcFeatureElementAddition));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcFeatureElementSubtraction()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcFeatureElementSubtraction));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcFillAreaStyle()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcFillAreaStyle));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcFillAreaStyleHatching()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcFillAreaStyleHatching));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcFillAreaStyleTileSymbolWithStyle()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcFillAreaStyleTileSymbolWithStyle));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcFillAreaStyleTiles()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcFillAreaStyleTiles));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcFilter()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcFilter));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcFilterType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcFilterType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcFireSuppressionTerminal()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcFireSuppressionTerminal));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcFireSuppressionTerminalType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcFireSuppressionTerminalType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcFixedReferenceSweptAreaSolid()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcFixedReferenceSweptAreaSolid));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcFlowController()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcFlowController));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcFlowControllerType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcFlowControllerType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcFlowFitting()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcFlowFitting));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcFlowFittingType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcFlowFittingType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcFlowInstrument()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcFlowInstrument));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcFlowInstrumentType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcFlowInstrumentType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcFlowMeter()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcFlowMeter));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcFlowMeterType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcFlowMeterType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcFlowMovingDevice()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcFlowMovingDevice));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcFlowMovingDeviceType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcFlowMovingDeviceType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcFlowSegment()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcFlowSegment));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcFlowSegmentType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcFlowSegmentType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcFlowStorageDevice()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcFlowStorageDevice));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcFlowStorageDeviceType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcFlowStorageDeviceType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcFlowTerminal()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcFlowTerminal));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcFlowTerminalType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcFlowTerminalType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcFlowTreatmentDevice()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcFlowTreatmentDevice));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcFlowTreatmentDeviceType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcFlowTreatmentDeviceType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcFluidFlowProperties()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcFluidFlowProperties));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcFooting()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcFooting));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcFootingType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcFootingType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcFuelProperties()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcFuelProperties));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcFurnishingElement()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcFurnishingElement));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcFurnishingElementType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcFurnishingElementType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcFurniture()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcFurniture));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcFurnitureStandard()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcFurnitureStandard));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcFurnitureType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcFurnitureType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcGasTerminalType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcGasTerminalType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcGeneralMaterialProperties()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcGeneralMaterialProperties));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcGeneralProfileProperties()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcGeneralProfileProperties));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcGeographicElement()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcGeographicElement));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcGeographicElementType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcGeographicElementType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcGeometricCurveSet()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcGeometricCurveSet));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcGeometricRepresentationContext()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcGeometricRepresentationContext));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcGeometricRepresentationItem()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcGeometricRepresentationItem));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcGeometricRepresentationSubContext()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcGeometricRepresentationSubContext));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcGeometricSet()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcGeometricSet));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcGrid()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcGrid));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcGridAxis()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcGridAxis));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcGridPlacement()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcGridPlacement));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcGroup()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcGroup));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcHalfSpaceSolid()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcHalfSpaceSolid));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcHeatExchanger()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcHeatExchanger));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcHeatExchangerType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcHeatExchangerType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcHumidifier()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcHumidifier));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcHumidifierType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcHumidifierType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcHygroscopicMaterialProperties()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcHygroscopicMaterialProperties));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcIShapeProfileDef()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcIShapeProfileDef));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcImageTexture()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcImageTexture));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcIndexedColourMap()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcIndexedColourMap));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcIndexedPolyCurve()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcIndexedPolyCurve));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcIndexedPolygonalFace()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcIndexedPolygonalFace));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcIndexedPolygonalFaceWithVoids()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcIndexedPolygonalFaceWithVoids));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcIndexedTextureMap()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcIndexedTextureMap));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcIndexedTriangleTextureMap()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcIndexedTriangleTextureMap));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcInterceptor()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcInterceptor));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcInterceptorType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcInterceptorType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcIntersectionCurve()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcIntersectionCurve));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcInventory()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcInventory));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcIrregularTimeSeries()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcIrregularTimeSeries));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcIrregularTimeSeriesValue()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcIrregularTimeSeriesValue));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcJunctionBox()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcJunctionBox));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcJunctionBoxType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcJunctionBoxType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcLShapeProfileDef()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcLShapeProfileDef));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcLaborResource()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcLaborResource));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcLaborResourceType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcLaborResourceType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcLagTime()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcLagTime));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcLamp()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcLamp));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcLampType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcLampType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcLibraryInformation()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcLibraryInformation));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcLibraryReference()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcLibraryReference));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcLightDistributionData()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcLightDistributionData));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcLightFixture()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcLightFixture));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcLightFixtureType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcLightFixtureType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcLightIntensityDistribution()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcLightIntensityDistribution));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcLightSource()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcLightSource));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcLightSourceAmbient()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcLightSourceAmbient));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcLightSourceDirectional()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcLightSourceDirectional));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcLightSourceGoniometric()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcLightSourceGoniometric));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcLightSourcePositional()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcLightSourcePositional));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcLightSourceSpot()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcLightSourceSpot));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcLine()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcLine));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcLineSegment2D()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcLineSegment2D));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcLinearDimension()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcLinearDimension));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcLinearPlacement()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcLinearPlacement));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcLinearPositioningElement()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcLinearPositioningElement));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcLocalPlacement()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcLocalPlacement));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcLocalTime()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcLocalTime));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcLoop()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcLoop));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcManifoldSolidBrep()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcManifoldSolidBrep));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcMapConversion()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcMapConversion));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcMappedItem()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcMappedItem));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcMaterial()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcMaterial));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcMaterialClassificationRelationship()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcMaterialClassificationRelationship));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcMaterialConstituent()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcMaterialConstituent));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcMaterialConstituentSet()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcMaterialConstituentSet));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcMaterialDefinition()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcMaterialDefinition));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcMaterialDefinitionRepresentation()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcMaterialDefinitionRepresentation));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcMaterialLayer()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcMaterialLayer));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcMaterialLayerSet()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcMaterialLayerSet));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcMaterialLayerSetUsage()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcMaterialLayerSetUsage));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcMaterialLayerWithOffsets()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcMaterialLayerWithOffsets));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcMaterialList()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcMaterialList));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcMaterialProfile()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcMaterialProfile));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcMaterialProfileSet()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcMaterialProfileSet));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcMaterialProfileSetUsage()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcMaterialProfileSetUsage));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcMaterialProfileSetUsageTapering()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcMaterialProfileSetUsageTapering));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcMaterialProfileWithOffsets()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcMaterialProfileWithOffsets));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcMaterialProperties()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcMaterialProperties));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcMaterialRelationship()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcMaterialRelationship));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcMaterialUsageDefinition()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcMaterialUsageDefinition));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcMeasureWithUnit()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcMeasureWithUnit));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcMechanicalConcreteMaterialProperties()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcMechanicalConcreteMaterialProperties));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcMechanicalFastener()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcMechanicalFastener));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcMechanicalFastenerType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcMechanicalFastenerType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcMechanicalMaterialProperties()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcMechanicalMaterialProperties));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcMechanicalSteelMaterialProperties()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcMechanicalSteelMaterialProperties));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcMedicalDevice()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcMedicalDevice));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcMedicalDeviceType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcMedicalDeviceType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcMember()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcMember));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcMemberStandardCase()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcMemberStandardCase));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcMemberType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcMemberType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcMetric()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcMetric));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcMirroredProfileDef()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcMirroredProfileDef));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcMonetaryUnit()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcMonetaryUnit));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcMotorConnection()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcMotorConnection));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcMotorConnectionType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcMotorConnectionType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcMove()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcMove));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcNamedUnit()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcNamedUnit));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcObject()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcObject));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcObjectDefinition()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcObjectDefinition));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcObjectPlacement()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcObjectPlacement));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcObjective()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcObjective));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcOccupant()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcOccupant));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcOffsetCurve()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcOffsetCurve));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcOffsetCurve2D()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcOffsetCurve2D));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcOffsetCurve3D()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcOffsetCurve3D));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcOffsetCurveByDistances()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcOffsetCurveByDistances));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcOneDirectionRepeatFactor()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcOneDirectionRepeatFactor));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcOpenShell()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcOpenShell));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcOpeningElement()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcOpeningElement));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcOpeningStandardCase()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcOpeningStandardCase));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcOpticalMaterialProperties()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcOpticalMaterialProperties));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcOrderAction()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcOrderAction));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcOrganization()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcOrganization));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcOrganizationRelationship()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcOrganizationRelationship));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcOrientationExpression()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcOrientationExpression));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcOrientedEdge()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcOrientedEdge));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcOuterBoundaryCurve()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcOuterBoundaryCurve));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcOutlet()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcOutlet));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcOutletType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcOutletType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcOwnerHistory()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcOwnerHistory));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcParameterizedProfileDef()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcParameterizedProfileDef));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcPath()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcPath));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcPcurve()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcPcurve));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcPerformanceHistory()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcPerformanceHistory));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcPermeableCoveringProperties()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcPermeableCoveringProperties));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcPermit()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcPermit));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcPerson()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcPerson));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcPersonAndOrganization()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcPersonAndOrganization));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcPhysicalComplexQuantity()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcPhysicalComplexQuantity));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcPhysicalQuantity()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcPhysicalQuantity));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcPhysicalSimpleQuantity()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcPhysicalSimpleQuantity));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcPile()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcPile));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcPileType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcPileType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcPipeFitting()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcPipeFitting));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcPipeFittingType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcPipeFittingType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcPipeSegment()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcPipeSegment));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcPipeSegmentType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcPipeSegmentType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcPixelTexture()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcPixelTexture));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcPlacement()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcPlacement));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcPlanarBox()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcPlanarBox));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcPlanarExtent()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcPlanarExtent));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcPlane()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcPlane));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcPlate()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcPlate));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcPlateStandardCase()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcPlateStandardCase));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcPlateType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcPlateType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcPoint()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcPoint));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcPointOnCurve()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcPointOnCurve));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcPointOnSurface()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcPointOnSurface));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcPolyLoop()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcPolyLoop));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcPolygonalBoundedHalfSpace()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcPolygonalBoundedHalfSpace));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcPolygonalFaceSet()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcPolygonalFaceSet));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcPolyline()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcPolyline));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcPort()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcPort));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcPositioningElement()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcPositioningElement));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcPostalAddress()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcPostalAddress));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcPreDefinedColour()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcPreDefinedColour));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcPreDefinedCurveFont()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcPreDefinedCurveFont));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcPreDefinedDimensionSymbol()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcPreDefinedDimensionSymbol));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcPreDefinedItem()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcPreDefinedItem));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcPreDefinedPointMarkerSymbol()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcPreDefinedPointMarkerSymbol));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcPreDefinedProperties()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcPreDefinedProperties));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcPreDefinedPropertySet()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcPreDefinedPropertySet));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcPreDefinedSymbol()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcPreDefinedSymbol));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcPreDefinedTerminatorSymbol()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcPreDefinedTerminatorSymbol));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcPreDefinedTextFont()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcPreDefinedTextFont));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcPresentationItem()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcPresentationItem));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcPresentationLayerAssignment()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcPresentationLayerAssignment));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcPresentationLayerWithStyle()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcPresentationLayerWithStyle));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcPresentationStyle()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcPresentationStyle));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcPresentationStyleAssignment()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcPresentationStyleAssignment));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcProcedure()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcProcedure));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcProcedureType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcProcedureType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcProcess()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcProcess));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcProduct()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcProduct));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcProductDefinitionShape()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcProductDefinitionShape));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcProductRepresentation()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcProductRepresentation));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcProductsOfCombustionProperties()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcProductsOfCombustionProperties));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcProfileDef()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcProfileDef));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcProfileProperties()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcProfileProperties));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcProject()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcProject));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcProjectLibrary()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcProjectLibrary));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcProjectOrder()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcProjectOrder));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcProjectOrderRecord()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcProjectOrderRecord));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcProjectedCRS()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcProjectedCRS));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcProjectionCurve()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcProjectionCurve));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcProjectionElement()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcProjectionElement));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcProperty()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcProperty));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcPropertyAbstraction()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcPropertyAbstraction));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcPropertyBoundedValue()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcPropertyBoundedValue));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcPropertyConstraintRelationship()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcPropertyConstraintRelationship));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcPropertyDefinition()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcPropertyDefinition));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcPropertyDependencyRelationship()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcPropertyDependencyRelationship));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcPropertyEnumeratedValue()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcPropertyEnumeratedValue));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcPropertyEnumeration()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcPropertyEnumeration));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcPropertyListValue()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcPropertyListValue));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcPropertyReferenceValue()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcPropertyReferenceValue));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcPropertySet()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcPropertySet));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcPropertySetDefinition()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcPropertySetDefinition));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcPropertySetTemplate()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcPropertySetTemplate));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcPropertySingleValue()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcPropertySingleValue));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcPropertyTableValue()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcPropertyTableValue));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcPropertyTemplate()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcPropertyTemplate));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcPropertyTemplateDefinition()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcPropertyTemplateDefinition));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcProtectiveDevice()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcProtectiveDevice));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcProtectiveDeviceTrippingUnit()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcProtectiveDeviceTrippingUnit));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcProtectiveDeviceTrippingUnitType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcProtectiveDeviceTrippingUnitType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcProtectiveDeviceType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcProtectiveDeviceType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcProxy()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcProxy));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcPump()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcPump));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcPumpType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcPumpType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcQuantityArea()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcQuantityArea));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcQuantityCount()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcQuantityCount));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcQuantityLength()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcQuantityLength));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcQuantitySet()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcQuantitySet));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcQuantityTime()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcQuantityTime));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcQuantityVolume()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcQuantityVolume));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcQuantityWeight()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcQuantityWeight));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRadiusDimension()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRadiusDimension));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRailing()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRailing));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRailingType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRailingType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRamp()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRamp));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRampFlight()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRampFlight));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRampFlightType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRampFlightType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRampType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRampType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRationalBSplineCurveWithKnots()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRationalBSplineCurveWithKnots));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRationalBSplineSurfaceWithKnots()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRationalBSplineSurfaceWithKnots));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRationalBezierCurve()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRationalBezierCurve));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRectangleHollowProfileDef()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRectangleHollowProfileDef));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRectangleProfileDef()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRectangleProfileDef));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRectangularPyramid()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRectangularPyramid));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRectangularTrimmedSurface()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRectangularTrimmedSurface));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRecurrencePattern()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRecurrencePattern));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcReference()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcReference));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcReferencesValueDocument()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcReferencesValueDocument));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcReferent()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcReferent));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRegularTimeSeries()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRegularTimeSeries));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcReinforcementBarProperties()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcReinforcementBarProperties));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcReinforcementDefinitionProperties()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcReinforcementDefinitionProperties));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcReinforcingBar()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcReinforcingBar));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcReinforcingBarType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcReinforcingBarType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcReinforcingElement()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcReinforcingElement));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcReinforcingElementType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcReinforcingElementType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcReinforcingMesh()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcReinforcingMesh));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcReinforcingMeshType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcReinforcingMeshType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRelAggregates()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRelAggregates));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRelAssigns()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRelAssigns));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRelAssignsTasks()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRelAssignsTasks));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRelAssignsToActor()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRelAssignsToActor));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRelAssignsToControl()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRelAssignsToControl));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRelAssignsToGroup()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRelAssignsToGroup));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRelAssignsToGroupByFactor()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRelAssignsToGroupByFactor));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRelAssignsToProcess()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRelAssignsToProcess));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRelAssignsToProduct()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRelAssignsToProduct));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRelAssignsToProjectOrder()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRelAssignsToProjectOrder));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRelAssignsToResource()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRelAssignsToResource));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRelAssociates()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRelAssociates));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRelAssociatesAppliedValue()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRelAssociatesAppliedValue));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRelAssociatesApproval()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRelAssociatesApproval));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRelAssociatesClassification()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRelAssociatesClassification));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRelAssociatesConstraint()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRelAssociatesConstraint));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRelAssociatesDocument()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRelAssociatesDocument));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRelAssociatesLibrary()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRelAssociatesLibrary));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRelAssociatesMaterial()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRelAssociatesMaterial));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRelAssociatesProfileProperties()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRelAssociatesProfileProperties));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRelConnects()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRelConnects));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRelConnectsElements()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRelConnectsElements));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRelConnectsPathElements()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRelConnectsPathElements));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRelConnectsPortToElement()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRelConnectsPortToElement));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRelConnectsPorts()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRelConnectsPorts));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRelConnectsStructuralActivity()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRelConnectsStructuralActivity));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRelConnectsStructuralElement()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRelConnectsStructuralElement));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRelConnectsStructuralMember()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRelConnectsStructuralMember));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRelConnectsWithEccentricity()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRelConnectsWithEccentricity));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRelConnectsWithRealizingElements()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRelConnectsWithRealizingElements));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRelContainedInSpatialStructure()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRelContainedInSpatialStructure));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRelCoversBldgElements()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRelCoversBldgElements));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRelCoversSpaces()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRelCoversSpaces));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRelDeclares()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRelDeclares));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRelDecomposes()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRelDecomposes));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRelDefines()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRelDefines));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRelDefinesByObject()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRelDefinesByObject));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRelDefinesByProperties()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRelDefinesByProperties));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRelDefinesByTemplate()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRelDefinesByTemplate));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRelDefinesByType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRelDefinesByType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRelFillsElement()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRelFillsElement));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRelFlowControlElements()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRelFlowControlElements));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRelInteractionRequirements()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRelInteractionRequirements));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRelInterferesElements()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRelInterferesElements));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRelNests()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRelNests));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRelOccupiesSpaces()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRelOccupiesSpaces));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRelOverridesProperties()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRelOverridesProperties));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRelProjectsElement()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRelProjectsElement));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRelReferencedInSpatialStructure()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRelReferencedInSpatialStructure));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRelSchedulesCostItems()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRelSchedulesCostItems));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRelSequence()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRelSequence));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRelServicesBuildings()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRelServicesBuildings));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRelSpaceBoundary()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRelSpaceBoundary));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRelSpaceBoundary1stLevel()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRelSpaceBoundary1stLevel));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRelSpaceBoundary2ndLevel()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRelSpaceBoundary2ndLevel));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRelVoidsElement()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRelVoidsElement));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRelationship()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRelationship));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRelaxation()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRelaxation));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcReparametrisedCompositeCurveSegment()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcReparametrisedCompositeCurveSegment));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRepresentation()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRepresentation));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRepresentationContext()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRepresentationContext));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRepresentationItem()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRepresentationItem));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRepresentationMap()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRepresentationMap));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcResource()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcResource));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcResourceApprovalRelationship()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcResourceApprovalRelationship));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcResourceConstraintRelationship()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcResourceConstraintRelationship));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcResourceLevelRelationship()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcResourceLevelRelationship));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcResourceTime()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcResourceTime));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRevolvedAreaSolid()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRevolvedAreaSolid));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRevolvedAreaSolidTapered()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRevolvedAreaSolidTapered));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRibPlateProfileProperties()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRibPlateProfileProperties));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRightCircularCone()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRightCircularCone));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRightCircularCylinder()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRightCircularCylinder));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRoof()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRoof));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRoofType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRoofType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRoot()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRoot));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRoundedEdgeFeature()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRoundedEdgeFeature));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcRoundedRectangleProfileDef()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcRoundedRectangleProfileDef));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcSIUnit()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcSIUnit));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcSanitaryTerminal()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcSanitaryTerminal));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcSanitaryTerminalType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcSanitaryTerminalType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcScheduleTimeControl()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcScheduleTimeControl));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcSchedulingTime()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcSchedulingTime));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcSeamCurve()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcSeamCurve));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcSectionProperties()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcSectionProperties));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcSectionReinforcementProperties()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcSectionReinforcementProperties));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcSectionedSolid()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcSectionedSolid));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcSectionedSolidHorizontal()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcSectionedSolidHorizontal));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcSectionedSpine()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcSectionedSpine));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcSensor()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcSensor));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcSensorType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcSensorType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcServiceLife()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcServiceLife));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcServiceLifeFactor()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcServiceLifeFactor));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcShadingDevice()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcShadingDevice));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcShadingDeviceType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcShadingDeviceType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcShapeAspect()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcShapeAspect));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcShapeModel()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcShapeModel));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcShapeRepresentation()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcShapeRepresentation));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcShellBasedSurfaceModel()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcShellBasedSurfaceModel));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcSimpleProperty()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcSimpleProperty));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcSimplePropertyTemplate()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcSimplePropertyTemplate));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcSite()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcSite));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcSlab()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcSlab));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcSlabElementedCase()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcSlabElementedCase));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcSlabStandardCase()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcSlabStandardCase));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcSlabType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcSlabType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcSlippageConnectionCondition()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcSlippageConnectionCondition));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcSolarDevice()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcSolarDevice));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcSolarDeviceType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcSolarDeviceType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcSolidModel()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcSolidModel));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcSoundProperties()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcSoundProperties));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcSoundValue()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcSoundValue));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcSpace()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcSpace));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcSpaceHeater()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcSpaceHeater));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcSpaceHeaterType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcSpaceHeaterType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcSpaceProgram()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcSpaceProgram));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcSpaceThermalLoadProperties()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcSpaceThermalLoadProperties));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcSpaceType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcSpaceType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcSpatialElement()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcSpatialElement));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcSpatialElementType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcSpatialElementType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcSpatialStructureElement()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcSpatialStructureElement));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcSpatialStructureElementType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcSpatialStructureElementType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcSpatialZone()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcSpatialZone));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcSpatialZoneType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcSpatialZoneType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcSphere()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcSphere));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcSphericalSurface()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcSphericalSurface));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcStackTerminal()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcStackTerminal));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcStackTerminalType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcStackTerminalType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcStair()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcStair));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcStairFlight()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcStairFlight));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcStairFlightType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcStairFlightType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcStairType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcStairType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcStructuralAction()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcStructuralAction));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcStructuralActivity()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcStructuralActivity));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcStructuralAnalysisModel()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcStructuralAnalysisModel));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcStructuralConnection()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcStructuralConnection));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcStructuralConnectionCondition()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcStructuralConnectionCondition));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcStructuralCurveAction()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcStructuralCurveAction));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcStructuralCurveConnection()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcStructuralCurveConnection));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcStructuralCurveMember()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcStructuralCurveMember));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcStructuralCurveMemberVarying()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcStructuralCurveMemberVarying));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcStructuralCurveReaction()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcStructuralCurveReaction));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcStructuralItem()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcStructuralItem));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcStructuralLinearAction()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcStructuralLinearAction));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcStructuralLinearActionVarying()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcStructuralLinearActionVarying));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcStructuralLoad()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcStructuralLoad));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcStructuralLoadCase()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcStructuralLoadCase));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcStructuralLoadConfiguration()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcStructuralLoadConfiguration));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcStructuralLoadGroup()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcStructuralLoadGroup));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcStructuralLoadLinearForce()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcStructuralLoadLinearForce));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcStructuralLoadOrResult()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcStructuralLoadOrResult));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcStructuralLoadPlanarForce()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcStructuralLoadPlanarForce));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcStructuralLoadSingleDisplacement()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcStructuralLoadSingleDisplacement));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcStructuralLoadSingleDisplacementDistortion()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcStructuralLoadSingleDisplacementDistortion));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcStructuralLoadSingleForce()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcStructuralLoadSingleForce));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcStructuralLoadSingleForceWarping()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcStructuralLoadSingleForceWarping));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcStructuralLoadStatic()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcStructuralLoadStatic));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcStructuralLoadTemperature()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcStructuralLoadTemperature));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcStructuralMember()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcStructuralMember));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcStructuralPlanarAction()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcStructuralPlanarAction));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcStructuralPlanarActionVarying()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcStructuralPlanarActionVarying));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcStructuralPointAction()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcStructuralPointAction));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcStructuralPointConnection()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcStructuralPointConnection));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcStructuralPointReaction()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcStructuralPointReaction));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcStructuralProfileProperties()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcStructuralProfileProperties));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcStructuralReaction()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcStructuralReaction));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcStructuralResultGroup()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcStructuralResultGroup));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcStructuralSteelProfileProperties()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcStructuralSteelProfileProperties));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcStructuralSurfaceAction()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcStructuralSurfaceAction));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcStructuralSurfaceConnection()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcStructuralSurfaceConnection));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcStructuralSurfaceMember()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcStructuralSurfaceMember));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcStructuralSurfaceMemberVarying()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcStructuralSurfaceMemberVarying));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcStructuralSurfaceReaction()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcStructuralSurfaceReaction));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcStructuredDimensionCallout()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcStructuredDimensionCallout));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcStyleModel()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcStyleModel));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcStyledItem()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcStyledItem));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcStyledRepresentation()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcStyledRepresentation));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcSubContractResource()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcSubContractResource));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcSubContractResourceType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcSubContractResourceType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcSubedge()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcSubedge));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcSurface()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcSurface));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcSurfaceCurve()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcSurfaceCurve));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcSurfaceCurveSweptAreaSolid()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcSurfaceCurveSweptAreaSolid));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcSurfaceFeature()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcSurfaceFeature));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcSurfaceOfLinearExtrusion()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcSurfaceOfLinearExtrusion));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcSurfaceOfRevolution()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcSurfaceOfRevolution));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcSurfaceReinforcementArea()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcSurfaceReinforcementArea));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcSurfaceStyle()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcSurfaceStyle));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcSurfaceStyleLighting()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcSurfaceStyleLighting));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcSurfaceStyleRefraction()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcSurfaceStyleRefraction));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcSurfaceStyleRendering()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcSurfaceStyleRendering));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcSurfaceStyleShading()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcSurfaceStyleShading));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcSurfaceStyleWithTextures()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcSurfaceStyleWithTextures));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcSurfaceTexture()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcSurfaceTexture));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcSweptAreaSolid()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcSweptAreaSolid));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcSweptDiskSolid()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcSweptDiskSolid));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcSweptDiskSolidPolygonal()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcSweptDiskSolidPolygonal));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcSweptSurface()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcSweptSurface));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcSwitchingDevice()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcSwitchingDevice));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcSwitchingDeviceType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcSwitchingDeviceType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcSymbolStyle()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcSymbolStyle));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcSystem()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcSystem));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcSystemFurnitureElement()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcSystemFurnitureElement));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcSystemFurnitureElementType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcSystemFurnitureElementType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcTShapeProfileDef()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcTShapeProfileDef));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcTable()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcTable));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcTableColumn()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcTableColumn));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcTableRow()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcTableRow));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcTank()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcTank));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcTankType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcTankType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcTask()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcTask));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcTaskTime()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcTaskTime));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcTaskTimeRecurring()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcTaskTimeRecurring));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcTaskType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcTaskType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcTelecomAddress()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcTelecomAddress));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcTendon()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcTendon));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcTendonAnchor()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcTendonAnchor));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcTendonAnchorType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcTendonAnchorType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcTendonType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcTendonType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcTerminatorSymbol()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcTerminatorSymbol));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcTessellatedFaceSet()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcTessellatedFaceSet));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcTessellatedItem()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcTessellatedItem));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcTextLiteral()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcTextLiteral));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcTextLiteralWithExtent()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcTextLiteralWithExtent));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcTextStyle()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcTextStyle));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcTextStyleFontModel()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcTextStyleFontModel));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcTextStyleForDefinedFont()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcTextStyleForDefinedFont));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcTextStyleTextModel()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcTextStyleTextModel));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcTextStyleWithBoxCharacteristics()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcTextStyleWithBoxCharacteristics));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcTextureCoordinate()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcTextureCoordinate));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcTextureCoordinateGenerator()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcTextureCoordinateGenerator));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcTextureMap()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcTextureMap));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcTextureVertex()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcTextureVertex));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcTextureVertexList()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcTextureVertexList));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcThermalMaterialProperties()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcThermalMaterialProperties));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcTimePeriod()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcTimePeriod));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcTimeSeries()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcTimeSeries));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcTimeSeriesReferenceRelationship()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcTimeSeriesReferenceRelationship));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcTimeSeriesSchedule()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcTimeSeriesSchedule));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcTimeSeriesValue()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcTimeSeriesValue));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcTopologicalRepresentationItem()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcTopologicalRepresentationItem));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcTopologyRepresentation()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcTopologyRepresentation));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcToroidalSurface()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcToroidalSurface));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcTransformer()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcTransformer));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcTransformerType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcTransformerType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcTransitionCurveSegment2D()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcTransitionCurveSegment2D));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcTransportElement()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcTransportElement));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcTransportElementType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcTransportElementType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcTrapeziumProfileDef()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcTrapeziumProfileDef));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcTriangulatedFaceSet()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcTriangulatedFaceSet));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcTriangulatedIrregularNetwork()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcTriangulatedIrregularNetwork));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcTrimmedCurve()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcTrimmedCurve));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcTubeBundle()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcTubeBundle));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcTubeBundleType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcTubeBundleType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcTwoDirectionRepeatFactor()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcTwoDirectionRepeatFactor));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcTypeObject()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcTypeObject));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcTypeProcess()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcTypeProcess));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcTypeProduct()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcTypeProduct));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcTypeResource()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcTypeResource));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcUShapeProfileDef()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcUShapeProfileDef));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcUnitAssignment()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcUnitAssignment));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcUnitaryControlElement()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcUnitaryControlElement));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcUnitaryControlElementType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcUnitaryControlElementType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcUnitaryEquipment()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcUnitaryEquipment));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcUnitaryEquipmentType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcUnitaryEquipmentType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcValve()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcValve));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcValveType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcValveType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcVector()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcVector));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcVertex()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcVertex));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcVertexBasedTextureMap()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcVertexBasedTextureMap));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcVertexLoop()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcVertexLoop));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcVertexPoint()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcVertexPoint));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcVibrationIsolator()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcVibrationIsolator));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcVibrationIsolatorType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcVibrationIsolatorType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcVirtualElement()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcVirtualElement));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcVirtualGridIntersection()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcVirtualGridIntersection));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcVoidingFeature()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcVoidingFeature));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcWall()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcWall));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcWallElementedCase()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcWallElementedCase));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcWallStandardCase()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcWallStandardCase));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcWallType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcWallType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcWasteTerminal()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcWasteTerminal));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcWasteTerminalType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcWasteTerminalType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcWaterProperties()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcWaterProperties));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcWindow()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcWindow));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcWindowLiningProperties()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcWindowLiningProperties));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcWindowPanelProperties()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcWindowPanelProperties));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcWindowStandardCase()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcWindowStandardCase));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcWindowStyle()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcWindowStyle));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcWindowType()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcWindowType));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcWorkCalendar()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcWorkCalendar));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcWorkControl()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcWorkControl));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcWorkPlan()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcWorkPlan));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcWorkSchedule()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcWorkSchedule));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcWorkTime()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcWorkTime));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcZShapeProfileDef()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcZShapeProfileDef));
}

PyIfcEntityDesc PyIfcEntityDesc::IfcZone()
{
    return PyIfcEntityDesc(std::addressof(Ice::IfcApi::IfcZone));
}

std::string PyIfcEntityDesc::className()
{
    return "IfcEntityDesc";
}

Ice::IfcApi::EntityDesc* PyIfcEntityDesc::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<Ice::IfcApi::EntityDesc*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
//PyIfcEntity
void makePyIfcEntityWrapper()
{
    PyDocString DS("IfcEntity");
    class_<PyIfcEntity>("IfcEntity")
        .def("IfcId", &PyIfcEntity::ifcId, DS.ARGS())
        .def("getAttribute", &PyIfcEntity::getAttribute, DS.ARGS({ "val: str" }))
        .def("setAttribute", &PyIfcEntity::setAttribute, DS.ARGS({ "val: str","attribValue: PyBrxBim.IfcVariant" }))
        .def("isA", &PyIfcEntity::isA, DS.ARGS())
        .def("isKindOf", &PyIfcEntity::isKindOf, DS.ARGS({ "val: PyBrxBim.IfcEntityDesc" }))
        .def("isNull", &PyIfcEntity::isNull, DS.ARGS())
        .def("getInverseRefs", &PyIfcEntity::getInverseRefs, DS.ARGS())
        .def("create", &PyIfcEntity::create, DS.SARGS({"model:PyBrxBim."})).staticmethod("create")
        .def("className", &PyIfcEntity::className, DS.SARGS()).staticmethod("className")
        ;
}

PyIfcEntity::PyIfcEntity()
    : PyIfcEntity(new Ice::IfcApi::Entity(), true)
{
}

PyIfcEntity::PyIfcEntity(const Ice::IfcApi::Entity& src)
    : PyIfcEntity(new Ice::IfcApi::Entity(src), true)
{
}

PyIfcEntity::PyIfcEntity(Ice::IfcApi::Entity* pObject, bool autoDelete)
    : m_pyImp(pObject, PySharedObjectDeleter<Ice::IfcApi::Entity>(autoDelete))
{
}

PyIfcEntity::PyIfcEntity(const Ice::IfcApi::Entity* src)
    :PyIfcEntity(const_cast<Ice::IfcApi::Entity*>(src), false)
{
}

int PyIfcEntity::ifcId() const
{
    return impObj()->ifcId();
}

PyIfcVariant PyIfcEntity::getAttribute(const std::string& attbName) const
{
    Ice::IfcApi::Variant attribValue;
    if (impObj()->getAttribute(attbName.c_str(), attribValue) != Ice::IfcApi::Result::eOk)
        PyThrowBadEs(eInvalidInput);
    return PyIfcVariant{ attribValue };
}

void PyIfcEntity::setAttribute(const std::string& attribName, const PyIfcVariant& attribValue)
{
    if (impObj()->setAttribute(attribName.c_str(), *attribValue.impObj()) != Ice::IfcApi::Result::eOk)
        PyThrowBadEs(eInvalidInput);
}

PyIfcEntityDesc PyIfcEntity::isA() const
{
    return PyIfcEntityDesc(impObj()->isA());
}

bool PyIfcEntity::isKindOf(const PyIfcEntityDesc& ent) const
{
    return impObj()->isKindOf(*ent.impObj());
}

bool PyIfcEntity::isNull() const
{
    return impObj()->isNull();
}

boost::python::list PyIfcEntity::getInverseRefs() const
{
    PyAutoLockGIL lock;
    boost::python::list pylist;
    for (const auto& item : impObj()->getInverseRefs())
        pylist.append(PyIfcEntity(item));
    return pylist;
}

PyIfcEntity PyIfcEntity::create(const PyIfcModel& model, const PyIfcEntityDesc& entityDesc)
{
    return PyIfcEntity(Ice::IfcApi::Entity::create(*model.impObj(), *entityDesc.impObj()));
}

std::string PyIfcEntity::className()
{
    return "IfcEntity";
}

Ice::IfcApi::Entity* PyIfcEntity::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<Ice::IfcApi::Entity*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
//PyIfcHeader
void makePyIfcHeaderWrapper()
{
    PyDocString DS("IfcHeader");
    class_<PyIfcHeader>("IfcHeader")
        .def("fileDescription", &PyIfcHeader::fileDescription, DS.ARGS())
        .def("implementationLevel", &PyIfcHeader::implementationLevel, DS.ARGS())
        .def("fileName", &PyIfcHeader::fileName, DS.ARGS())
        .def("timeStamp", &PyIfcHeader::timeStamp, DS.ARGS())
        .def("author", &PyIfcHeader::author, DS.ARGS())
        .def("organization", &PyIfcHeader::organization, DS.ARGS())
        .def("preprocessorVersion", &PyIfcHeader::preprocessorVersion, DS.ARGS())
        .def("originatingSystem", &PyIfcHeader::originatingSystem, DS.ARGS())
        .def("authorization", &PyIfcHeader::authorization, DS.ARGS())
        .def("fileSchema", &PyIfcHeader::fileSchema, DS.ARGS())

        .def("setFileDescription", &PyIfcHeader::setFileDescription, DS.ARGS({ "val: PyBrxBim.IfcString" }))
        .def("setFileName", &PyIfcHeader::setFileName, DS.ARGS({ "val: PyBrxBim.IfcString" }))
        .def("setTimeStamp", &PyIfcHeader::setTimeStamp, DS.ARGS({ "val: PyBrxBim.IfcString" }))
        .def("setAuthor", &PyIfcHeader::setAuthor, DS.ARGS({ "val: PyBrxBim.IfcString" }))
        .def("setOrganization", &PyIfcHeader::setOrganization, DS.ARGS({ "val: PyBrxBim.IfcString" }))
        .def("setPreprocessorVersion", &PyIfcHeader::setPreprocessorVersion, DS.ARGS({ "val: PyBrxBim.IfcString" }))
        .def("setOriginatingSystem", &PyIfcHeader::setOriginatingSystem, DS.ARGS({ "val: PyBrxBim.IfcString" }))
        .def("setAuthorization", &PyIfcHeader::setAuthorization, DS.ARGS({ "val: PyBrxBim.IfcString" }))
        .def("setFileSchema", &PyIfcHeader::setFileSchema, DS.ARGS({ "val: PyBrxBim.IfcString" }))

        .def("className", &PyIfcHeader::className, DS.SARGS()).staticmethod("className")
        ;
}

PyIfcHeader::PyIfcHeader()
    : PyIfcHeader(new Ice::IfcApi::Header(), true)
{
}

PyIfcHeader::PyIfcHeader(Ice::IfcApi::Header* pObject, bool autoDelete)
    : m_pyImp(pObject, PySharedObjectDeleter<Ice::IfcApi::Header>(autoDelete))
{
}

PyIfcString PyIfcHeader::fileDescription() const
{
    return PyIfcString{ impObj()->fileDescription() };
}

PyIfcString PyIfcHeader::implementationLevel() const
{
    return PyIfcString{ impObj()->implementationLevel() };
}

void PyIfcHeader::setFileDescription(const PyIfcString& str)
{
    impObj()->setFileDescription(*str.impObj());
}

PyIfcString PyIfcHeader::fileName() const
{
    return PyIfcString{ impObj()->fileName() };
}

PyIfcString PyIfcHeader::timeStamp() const
{
    return PyIfcString{ impObj()->timeStamp() };
}

PyIfcString PyIfcHeader::author() const
{
    return PyIfcString{ impObj()->author() };
}

PyIfcString PyIfcHeader::organization() const
{
    return PyIfcString{ impObj()->organization() };
}

PyIfcString PyIfcHeader::preprocessorVersion() const
{
    return PyIfcString{ impObj()->preprocessorVersion() };
}

PyIfcString PyIfcHeader::originatingSystem() const
{
    return PyIfcString{ impObj()->originatingSystem() };
}

PyIfcString PyIfcHeader::authorization() const
{
    return PyIfcString{ impObj()->authorization() };
}

void PyIfcHeader::setFileName(const PyIfcString& str)
{
    impObj()->setFileName(*str.impObj());
}

void PyIfcHeader::setTimeStamp(const PyIfcString& str)
{
    impObj()->setTimeStamp(*str.impObj());
}

void PyIfcHeader::setAuthor(const PyIfcString& str)
{
    impObj()->setAuthor(*str.impObj());
}

void PyIfcHeader::setOrganization(const PyIfcString& str)
{
    impObj()->setOrganization(*str.impObj());
}

void PyIfcHeader::setPreprocessorVersion(const PyIfcString& str)
{
    impObj()->setPreprocessorVersion(*str.impObj());
}

void PyIfcHeader::setOriginatingSystem(const PyIfcString& str)
{
    impObj()->setOriginatingSystem(*str.impObj());
}

void PyIfcHeader::setAuthorization(const PyIfcString& str)
{
    impObj()->setAuthorization(*str.impObj());
}

void PyIfcHeader::setFileSchema(const PyIfcString& str)
{
    impObj()->setFileSchema(*str.impObj());
}

PyIfcString PyIfcHeader::fileSchema() const
{
    return PyIfcString{ impObj()->fileSchema() };
}

std::string PyIfcHeader::className()
{
    return "IfcHeader";
}

Ice::IfcApi::Header* PyIfcHeader::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<Ice::IfcApi::Header*>(m_pyImp.get());
}

//---------------------------------------------------------------------------------------- -
//PyIfcModel
void makePyIfcModelWrapper()
{
    PyDocString DS("IfcModel");
    class_<PyIfcModel>("IfcModel", no_init)
        .def("release", &PyIfcModel::release, DS.ARGS())
        .def("getNumEntities", &PyIfcModel::getNumEntities, DS.ARGS())
        .def("get", &PyIfcModel::get, DS.ARGS({ "index: int" }))
        .def("schemaId", &PyIfcModel::schemaId, DS.ARGS())
        .def("write", &PyIfcModel::write, DS.SARGS({ "fileName: str","header: PyBrxBim.IfcHeader" })).staticmethod("write")
        .def("read", &PyIfcModel::read, DS.SARGS({ "fileName: str" })).staticmethod("read")
        .def("className", &PyIfcModel::className, DS.SARGS()).staticmethod("className")
        ;
}

template<typename T>
struct PySharedModelDeleter
{
    inline PySharedModelDeleter(bool autoDelete)
        : m_autoDelete(autoDelete)
    {
    }

    inline void operator()(T* p) const
    {
        if (!m_autoDelete)
            return;
        if (p != nullptr)
            p->release();
    }
    bool m_autoDelete = true;
};

PyIfcModel::PyIfcModel(Ice::IfcApi::Model* pObject, bool autoDelete)
    : m_pyImp(pObject, PySharedModelDeleter<Ice::IfcApi::Model>(autoDelete))
{
}

void PyIfcModel::release()
{
    impObj()->release();
}

size_t PyIfcModel::getNumEntities() const
{
    return impObj()->getNumEntities();
}

PyIfcEntity PyIfcModel::get(size_t index) const
{
    return PyIfcEntity{ impObj()->get(index) };
}

Ice::EIfcSchemaId PyIfcModel::schemaId() const
{
    return impObj()->schemaId();
}

bool PyIfcModel::write(const std::string& fileName, const PyIfcHeader& header)
{
    return impObj()->write(utf8_to_wstr(fileName).c_str(), *header.impObj());
}

PyIfcModel PyIfcModel::create(Ice::EIfcSchemaId schemaId)
{
    return PyIfcModel(Ice::IfcApi::Model::create(schemaId), true);
}

PyIfcModel PyIfcModel::read(const std::string& fileName)
{
    return PyIfcModel(Ice::IfcApi::Model::read(utf8_to_wstr(fileName).c_str()), true);
}

std::string PyIfcModel::className()
{
    return "IfcModel";
}

Ice::IfcApi::Model* PyIfcModel::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<Ice::IfcApi::Model*>(m_pyImp.get());
}


//---------------------------------------------------------------------------------------- -
//PyIfcVariant
void makePyIfcVariantWrapper()
{
    PyDocString DS("IfcVariant");
    class_<PyIfcVariant>("IfcVariant")
        .def(init<>(DS.ARGS()))
        .def("getBool", &PyIfcVariant::getBool, DS.ARGS())
        .def("setBool", &PyIfcVariant::setBool, DS.ARGS({ "val: bool" }))
        .def("getInt", &PyIfcVariant::getInt, DS.ARGS())
        .def("setInt", &PyIfcVariant::setInt, DS.ARGS({ "val: int" }))
        .def("getUInt", &PyIfcVariant::getUInt, DS.ARGS())
        .def("setUInt", &PyIfcVariant::setUInt, DS.ARGS({ "val: int" }))
        .def("getReal", &PyIfcVariant::getReal, DS.ARGS())
        .def("setReal", &PyIfcVariant::setReal, DS.ARGS({ "val: float" }))
        .def("getString", &PyIfcVariant::getString, DS.ARGS())
        .def("setString", &PyIfcVariant::setString, DS.ARGS({ "val: PyBrxBim.IfcString" }))
        .def("getEntity", &PyIfcVariant::getEntity, DS.ARGS())
        .def("setEntity", &PyIfcVariant::setEntity, DS.ARGS({ "val: PyBrxBim.IfcEntity" }))
        .def("getLogical", &PyIfcVariant::getLogical, DS.ARGS())
        .def("setLogical", &PyIfcVariant::setLogical, DS.ARGS({ "val: PyBrxBim.IfcLogical" }))
        .def("getBinary", &PyIfcVariant::getBinary, DS.ARGS())
        .def("setBinary", &PyIfcVariant::setBinary, DS.ARGS({ "val: PyBrxBim.IfcBinary" }))
        .def("getGuid", &PyIfcVariant::getGuid, DS.ARGS())
        .def("setGuid", &PyIfcVariant::setGuid, DS.ARGS({ "val: PyBrxBim.IfcGuid" }))
        .def("getVector", &PyIfcVariant::getVector, DS.ARGS())
        .def("setVector", &PyIfcVariant::setVector, DS.ARGS({ "val: PyBrxBim.IfcVectorValue" }))
        .def("getSelect", &PyIfcVariant::getSelect, DS.ARGS())
        .def("setSelect", &PyIfcVariant::setSelect, DS.ARGS({ "val: PyBrxBim.IfcVectorValue" }))
        .def("getEnum", &PyIfcVariant::getEnum, DS.ARGS())
        .def("setEnum", &PyIfcVariant::setEnum, DS.ARGS({ "val: PyBrxBim.IfcEnumValue" }))
        .def("type", &PyIfcVariant::type, DS.ARGS())
        .def("className", &PyIfcVariant::className, DS.SARGS()).staticmethod("className")
        ;
}

PyIfcVariant::PyIfcVariant()
    : PyIfcVariant(new Ice::IfcApi::Variant(), true)
{
}

PyIfcVariant::PyIfcVariant(Ice::IfcApi::Variant* pObject, bool autoDelete)
    : m_pyImp(pObject, PySharedObjectDeleter<Ice::IfcApi::Variant>(autoDelete))
{
}

PyIfcVariant::PyIfcVariant(const Ice::IfcApi::Variant& pObject)
    : PyIfcVariant(new Ice::IfcApi::Variant(pObject), true)
{
}

int PyIfcVariant::getInt() const
{
    return impObj()->getInt();
}

void PyIfcVariant::setInt(int val)
{
    *impObj() = val;
}

bool PyIfcVariant::getBool() const
{
    return impObj()->getBool();
}

void PyIfcVariant::setBool(bool val)
{
    *impObj() = val;
}

unsigned PyIfcVariant::getUInt() const
{
    return impObj()->getUInt();
}

void PyIfcVariant::setUInt(unsigned val)
{
    *impObj() = val;
}

double PyIfcVariant::getReal() const
{
    return impObj()->getReal();
}

void PyIfcVariant::setReal(double val)
{
    *impObj() = val;
}

PyIfcString PyIfcVariant::getString() const
{
    return PyIfcString{ impObj()->getString() };
}

void PyIfcVariant::setString(const PyIfcString& val)
{
    *impObj() = *val.impObj();
}

PyIfcEntity PyIfcVariant::getEntity() const
{
    return PyIfcEntity{ impObj()->getEntity() };
}

void PyIfcVariant::setEntity(const PyIfcEntity& val)
{
    *impObj() = *val.impObj();
}

PyIfcLogical PyIfcVariant::getLogical() const
{
    return PyIfcLogical{ impObj()->getLogical() };
}

void PyIfcVariant::setLogical(const PyIfcLogical& val)
{
    *impObj() = *val.impObj();
}

PyIfcBinary PyIfcVariant::getBinary() const
{
    return PyIfcBinary{ impObj()->getBinary() };
}

void PyIfcVariant::setBinary(const PyIfcBinary& val)
{
    *impObj() = *val.impObj();
}

PyIfcGuid PyIfcVariant::getGuid() const
{
    return PyIfcGuid{ impObj()->getGuid() };
}

void PyIfcVariant::setGuid(const PyIfcGuid& val)
{
    *impObj() = *val.impObj();
}

PyIfcVectorValue PyIfcVariant::getVector() const
{
    return PyIfcVectorValue{ impObj()->getVector() };
}

void PyIfcVariant::setVector(const PyIfcVectorValue& val)
{
    *impObj() = *val.impObj();
}

PyIfcSelectValue PyIfcVariant::getSelect() const
{
    return PyIfcSelectValue{ impObj()->getSelect() };
}

void PyIfcVariant::setSelect(const PyIfcSelectValue& val)
{
    *impObj() = *val.impObj();
}

PyIfcEnumValue PyIfcVariant::getEnum() const
{
    return PyIfcEnumValue{ impObj()->getEnum() };
}

void PyIfcVariant::setEnum(const PyIfcEnumValue& val)
{
    *impObj() = *val.impObj();
}

Ice::IfcApi::ValueType PyIfcVariant::type() const
{
    return impObj()->type();
}

std::string PyIfcVariant::className()
{
    return "IfcVariant";
}

Ice::IfcApi::Variant* PyIfcVariant::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_pyImp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return static_cast<Ice::IfcApi::Variant*>(m_pyImp.get());
}

#endif