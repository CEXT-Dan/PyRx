#pragma once

#ifdef BRXAPP
#include "IfcDefs.h"

class PyIfcVariant;
class PyIfcModel;

namespace Ice {
    namespace IfcApi {
        enum class Result;
    }
}


//---------------------------------------------------------------------------------------- -
//PyIfcGuid
void makePyIfcGuidWrapper();
class PyIfcGuid
{
public:
    PyIfcGuid();
    PyIfcGuid(Ice::IfcApi::Guid* pObject, bool autoDelete);
    PyIfcGuid(const Ice::IfcApi::Guid& pObject);
    ~PyIfcGuid() = default;
    const std::string   getBase64() const;
    const std::string   getText() const;

    static PyIfcGuid    create();
    static PyIfcGuid    createFromBase64(const std::string& base64);
    static PyIfcGuid    createFromText(const std::string& text);

    static std::string  className();
public:
    Ice::IfcApi::Guid* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<Ice::IfcApi::Guid> m_pyImp;
};

//---------------------------------------------------------------------------------------- -
//PyIfcString
void makePyIfcStringWrapper();
class PyIfcString
{
public:
    PyIfcString();
    PyIfcString(const std::string& val);
    PyIfcString(const Ice::IfcApi::String& pObject);
    PyIfcString(Ice::IfcApi::String* pObject, bool autoDelete);
    ~PyIfcString() = default;

    const std::string   getEncoded() const;
    const std::string   c_str() const;
    bool                isEmpty() const;
    void                setEmpty();
    static PyIfcString  decode(const std::string& encoded);

    static std::string  className();
public:
    Ice::IfcApi::String* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<Ice::IfcApi::String> m_pyImp;
};

//---------------------------------------------------------------------------------------- -
//PyIfcBinary
void makePyIfcBinaryWrapper();
class PyIfcBinary
{
public:
    PyIfcBinary();
    PyIfcBinary(const Ice::IfcApi::Binary& other);
    PyIfcBinary(Ice::IfcApi::Binary* pObject, bool autoDelete);
    ~PyIfcBinary() = default;

    std::string     getEncodedString() const;
    void            reset(const std::string& encodedStr);
    size_t          numBits() const;
    bool            getBit(size_t i) const;
    bool            isEmpty() const;
    void            resize(size_t nBits);
    void            clear();

    static std::string  className();
public:
    Ice::IfcApi::Binary* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<Ice::IfcApi::Binary> m_pyImp;
};

//---------------------------------------------------------------------------------------- -
//PyIfcLogical
void makePyIfcLogicalWrapper();
class PyIfcLogical
{
public:
    PyIfcLogical();
    PyIfcLogical(const Ice::IfcApi::Logical& other);
    PyIfcLogical(Ice::IfcApi::Logical* pObject, bool autoDelete);
    ~PyIfcLogical() = default;

    bool        isKnown() const;
    bool        isUnknown() const;

    static std::string  className();
public:
    Ice::IfcApi::Logical* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<Ice::IfcApi::Logical> m_pyImp;
};

//---------------------------------------------------------------------------------------- -
//PyIfcVectorDesc
void makePyIfcVectorDescWrapper();
class PyIfcVectorDesc
{
public:
    PyIfcVectorDesc();
    PyIfcVectorDesc(Ice::IfcApi::VectorDesc* pObject, bool autoDelete);
    ~PyIfcVectorDesc() = default;

    static std::string  className();
public:
    Ice::IfcApi::VectorDesc* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<Ice::IfcApi::VectorDesc> m_pyImp;
};

//---------------------------------------------------------------------------------------- -
//PyIfcVectorValue
void makePyIfcVectorValueWrapper();
class PyIfcVectorValue
{
public:
    PyIfcVectorValue(const Ice::IfcApi::VectorValue& src);
    PyIfcVectorValue(Ice::IfcApi::VectorValue* pObject, bool autoDelete);
    ~PyIfcVectorValue() = default;

    Ice::IfcApi::Result add(const PyIfcVariant& value);
    unsigned int        size() const;
    bool                remove(unsigned int index);
    void                clear();
    bool                isNull() const;
    boost::python::list values() const;

    static std::string  className();
public:
    Ice::IfcApi::VectorValue* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<Ice::IfcApi::VectorValue> m_pyImp;
};

//---------------------------------------------------------------------------------------- -
//PyIfcSelectorDesc
void makePyIfcSelectorDescWrapper();
class PyIfcSelectorDesc
{
public:
    PyIfcSelectorDesc();
    PyIfcSelectorDesc(Ice::IfcApi::SelectorDesc* pObject, bool autoDelete);
    ~PyIfcSelectorDesc() = default;

    static std::string  className();
public:
    Ice::IfcApi::SelectorDesc* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<Ice::IfcApi::SelectorDesc> m_pyImp;
};

//---------------------------------------------------------------------------------------- -
//PyIfcSelectValue
void makePyIfcSelectValueWrapper();
class PyIfcSelectValue
{
public:
    PyIfcSelectValue(const Ice::IfcApi::SelectValue& src);
    PyIfcSelectValue(Ice::IfcApi::SelectValue* pObject, bool autoDelete);
    ~PyIfcSelectValue() = default;

    PyIfcVariant        getValue() const;
    std::string         tag() const;
    Ice::IfcApi::Result setValue(const std::string& tag, const PyIfcVariant& val);
    bool                isNull() const;

    static std::string  className();
public:
    Ice::IfcApi::SelectValue* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<Ice::IfcApi::SelectValue> m_pyImp;
};

//---------------------------------------------------------------------------------------- -
//PyIfcEnumValue
void makePyIfcEnumValueWrapper();
class PyIfcEnumValue
{
public:
    PyIfcEnumValue(const Ice::IfcApi::EnumValue& src);
    PyIfcEnumValue(Ice::IfcApi::EnumValue* pObject, bool autoDelete);
    ~PyIfcEnumValue() = default;

    std::string  getValue() const;
    void         setValue(const std::string& stringValue);

    static std::string  className();
public:
    Ice::IfcApi::EnumValue* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<Ice::IfcApi::EnumValue> m_pyImp;
};

//---------------------------------------------------------------------------------------- -
//PyIfcEntityDesc
void makePyIfcEntityDescWrapper();
class PyIfcEntityDesc
{
public:
    PyIfcEntityDesc();
    PyIfcEntityDesc(const Ice::IfcApi::EntityDesc* pObject);
    PyIfcEntityDesc(Ice::IfcApi::EntityDesc* pObject, bool autoDelete);
    ~PyIfcEntityDesc() = default;
    bool isDerivedFrom(const PyIfcEntityDesc& obj, Ice::EIfcSchemaId eSchema) const;
    std::string name();

    static  PyIfcEntityDesc Ifc2DCompositeCurve();
    static  PyIfcEntityDesc IfcActionRequest();
    static  PyIfcEntityDesc IfcActor();
    static  PyIfcEntityDesc IfcActorRole();
    static  PyIfcEntityDesc IfcActuator();
    static  PyIfcEntityDesc IfcActuatorType();
    static  PyIfcEntityDesc IfcAddress();
    static  PyIfcEntityDesc IfcAdvancedBrep();
    static  PyIfcEntityDesc IfcAdvancedBrepWithVoids();
    static  PyIfcEntityDesc IfcAdvancedFace();
    static  PyIfcEntityDesc IfcAirTerminal();
    static  PyIfcEntityDesc IfcAirTerminalBox();
    static  PyIfcEntityDesc IfcAirTerminalBoxType();
    static  PyIfcEntityDesc IfcAirTerminalType();
    static  PyIfcEntityDesc IfcAirToAirHeatRecovery();
    static  PyIfcEntityDesc IfcAirToAirHeatRecoveryType();
    static  PyIfcEntityDesc IfcAlarm();
    static  PyIfcEntityDesc IfcAlarmType();
    static  PyIfcEntityDesc IfcAlignment();
    static  PyIfcEntityDesc IfcAlignment2DHorizontal();
    static  PyIfcEntityDesc IfcAlignment2DHorizontalSegment();
    static  PyIfcEntityDesc IfcAlignment2DSegment();
    static  PyIfcEntityDesc IfcAlignment2DVerSegCircularArc();
    static  PyIfcEntityDesc IfcAlignment2DVerSegLine();
    static  PyIfcEntityDesc IfcAlignment2DVerSegParabolicArc();
    static  PyIfcEntityDesc IfcAlignment2DVertical();
    static  PyIfcEntityDesc IfcAlignment2DVerticalSegment();
    static  PyIfcEntityDesc IfcAlignmentCurve();
    static  PyIfcEntityDesc IfcAngularDimension();
    static  PyIfcEntityDesc IfcAnnotation();
    static  PyIfcEntityDesc IfcAnnotationCurveOccurrence();
    static  PyIfcEntityDesc IfcAnnotationFillArea();
    static  PyIfcEntityDesc IfcAnnotationFillAreaOccurrence();
    static  PyIfcEntityDesc IfcAnnotationOccurrence();
    static  PyIfcEntityDesc IfcAnnotationSurface();
    static  PyIfcEntityDesc IfcAnnotationSurfaceOccurrence();
    static  PyIfcEntityDesc IfcAnnotationSymbolOccurrence();
    static  PyIfcEntityDesc IfcAnnotationTextOccurrence();
    static  PyIfcEntityDesc IfcApplication();
    static  PyIfcEntityDesc IfcAppliedValue();
    static  PyIfcEntityDesc IfcAppliedValueRelationship();
    static  PyIfcEntityDesc IfcApproval();
    static  PyIfcEntityDesc IfcApprovalActorRelationship();
    static  PyIfcEntityDesc IfcApprovalPropertyRelationship();
    static  PyIfcEntityDesc IfcApprovalRelationship();
    static  PyIfcEntityDesc IfcArbitraryClosedProfileDef();
    static  PyIfcEntityDesc IfcArbitraryOpenProfileDef();
    static  PyIfcEntityDesc IfcArbitraryProfileDefWithVoids();
    static  PyIfcEntityDesc IfcAsset();
    static  PyIfcEntityDesc IfcAsymmetricIShapeProfileDef();
    static  PyIfcEntityDesc IfcAudioVisualAppliance();
    static  PyIfcEntityDesc IfcAudioVisualApplianceType();
    static  PyIfcEntityDesc IfcAxis1Placement();
    static  PyIfcEntityDesc IfcAxis2Placement2D();
    static  PyIfcEntityDesc IfcAxis2Placement3D();
    static  PyIfcEntityDesc IfcBSplineCurve();
    static  PyIfcEntityDesc IfcBSplineCurveWithKnots();
    static  PyIfcEntityDesc IfcBSplineSurface();
    static  PyIfcEntityDesc IfcBSplineSurfaceWithKnots();
    static  PyIfcEntityDesc IfcBeam();
    static  PyIfcEntityDesc IfcBeamStandardCase();
    static  PyIfcEntityDesc IfcBeamType();
    static  PyIfcEntityDesc IfcBezierCurve();
    static  PyIfcEntityDesc IfcBlobTexture();
    static  PyIfcEntityDesc IfcBlock();
    static  PyIfcEntityDesc IfcBoiler();
    static  PyIfcEntityDesc IfcBoilerType();
    static  PyIfcEntityDesc IfcBooleanClippingResult();
    static  PyIfcEntityDesc IfcBooleanResult();
    static  PyIfcEntityDesc IfcBoundaryCondition();
    static  PyIfcEntityDesc IfcBoundaryCurve();
    static  PyIfcEntityDesc IfcBoundaryEdgeCondition();
    static  PyIfcEntityDesc IfcBoundaryFaceCondition();
    static  PyIfcEntityDesc IfcBoundaryNodeCondition();
    static  PyIfcEntityDesc IfcBoundaryNodeConditionWarping();
    static  PyIfcEntityDesc IfcBoundedCurve();
    static  PyIfcEntityDesc IfcBoundedSurface();
    static  PyIfcEntityDesc IfcBoundingBox();
    static  PyIfcEntityDesc IfcBoxedHalfSpace();
    static  PyIfcEntityDesc IfcBuilding();
    static  PyIfcEntityDesc IfcBuildingElement();
    static  PyIfcEntityDesc IfcBuildingElementComponent();
    static  PyIfcEntityDesc IfcBuildingElementPart();
    static  PyIfcEntityDesc IfcBuildingElementPartType();
    static  PyIfcEntityDesc IfcBuildingElementProxy();
    static  PyIfcEntityDesc IfcBuildingElementProxyType();
    static  PyIfcEntityDesc IfcBuildingElementType();
    static  PyIfcEntityDesc IfcBuildingStorey();
    static  PyIfcEntityDesc IfcBuildingSystem();
    static  PyIfcEntityDesc IfcBurner();
    static  PyIfcEntityDesc IfcBurnerType();
    static  PyIfcEntityDesc IfcCShapeProfileDef();
    static  PyIfcEntityDesc IfcCableCarrierFitting();
    static  PyIfcEntityDesc IfcCableCarrierFittingType();
    static  PyIfcEntityDesc IfcCableCarrierSegment();
    static  PyIfcEntityDesc IfcCableCarrierSegmentType();
    static  PyIfcEntityDesc IfcCableFitting();
    static  PyIfcEntityDesc IfcCableFittingType();
    static  PyIfcEntityDesc IfcCableSegment();
    static  PyIfcEntityDesc IfcCableSegmentType();
    static  PyIfcEntityDesc IfcCalendarDate();
    static  PyIfcEntityDesc IfcCartesianPoint();
    static  PyIfcEntityDesc IfcCartesianPointList();
    static  PyIfcEntityDesc IfcCartesianPointList2D();
    static  PyIfcEntityDesc IfcCartesianPointList3D();
    static  PyIfcEntityDesc IfcCartesianTransformationOperator();
    static  PyIfcEntityDesc IfcCartesianTransformationOperator2D();
    static  PyIfcEntityDesc IfcCartesianTransformationOperator2DnonUniform();
    static  PyIfcEntityDesc IfcCartesianTransformationOperator3D();
    static  PyIfcEntityDesc IfcCartesianTransformationOperator3DnonUniform();
    static  PyIfcEntityDesc IfcCenterLineProfileDef();
    static  PyIfcEntityDesc IfcChamferEdgeFeature();
    static  PyIfcEntityDesc IfcChiller();
    static  PyIfcEntityDesc IfcChillerType();
    static  PyIfcEntityDesc IfcChimney();
    static  PyIfcEntityDesc IfcChimneyType();
    static  PyIfcEntityDesc IfcCircle();
    static  PyIfcEntityDesc IfcCircleHollowProfileDef();
    static  PyIfcEntityDesc IfcCircleProfileDef();
    static  PyIfcEntityDesc IfcCircularArcSegment2D();
    static  PyIfcEntityDesc IfcCivilElement();
    static  PyIfcEntityDesc IfcCivilElementType();
    static  PyIfcEntityDesc IfcClassification();
    static  PyIfcEntityDesc IfcClassificationItem();
    static  PyIfcEntityDesc IfcClassificationItemRelationship();
    static  PyIfcEntityDesc IfcClassificationNotation();
    static  PyIfcEntityDesc IfcClassificationNotationFacet();
    static  PyIfcEntityDesc IfcClassificationReference();
    static  PyIfcEntityDesc IfcClosedShell();
    static  PyIfcEntityDesc IfcCoil();
    static  PyIfcEntityDesc IfcCoilType();
    static  PyIfcEntityDesc IfcColourRgb();
    static  PyIfcEntityDesc IfcColourRgbList();
    static  PyIfcEntityDesc IfcColourSpecification();
    static  PyIfcEntityDesc IfcColumn();
    static  PyIfcEntityDesc IfcColumnStandardCase();
    static  PyIfcEntityDesc IfcColumnType();
    static  PyIfcEntityDesc IfcCommunicationsAppliance();
    static  PyIfcEntityDesc IfcCommunicationsApplianceType();
    static  PyIfcEntityDesc IfcComplexProperty();
    static  PyIfcEntityDesc IfcComplexPropertyTemplate();
    static  PyIfcEntityDesc IfcCompositeCurve();
    static  PyIfcEntityDesc IfcCompositeCurveOnSurface();
    static  PyIfcEntityDesc IfcCompositeCurveSegment();
    static  PyIfcEntityDesc IfcCompositeProfileDef();
    static  PyIfcEntityDesc IfcCompressor();
    static  PyIfcEntityDesc IfcCompressorType();
    static  PyIfcEntityDesc IfcCondenser();
    static  PyIfcEntityDesc IfcCondenserType();
    static  PyIfcEntityDesc IfcCondition();
    static  PyIfcEntityDesc IfcConditionCriterion();
    static  PyIfcEntityDesc IfcConic();
    static  PyIfcEntityDesc IfcConnectedFaceSet();
    static  PyIfcEntityDesc IfcConnectionCurveGeometry();
    static  PyIfcEntityDesc IfcConnectionGeometry();
    static  PyIfcEntityDesc IfcConnectionPointEccentricity();
    static  PyIfcEntityDesc IfcConnectionPointGeometry();
    static  PyIfcEntityDesc IfcConnectionPortGeometry();
    static  PyIfcEntityDesc IfcConnectionSurfaceGeometry();
    static  PyIfcEntityDesc IfcConnectionVolumeGeometry();
    static  PyIfcEntityDesc IfcConstraint();
    static  PyIfcEntityDesc IfcConstraintAggregationRelationship();
    static  PyIfcEntityDesc IfcConstraintClassificationRelationship();
    static  PyIfcEntityDesc IfcConstraintRelationship();
    static  PyIfcEntityDesc IfcConstructionEquipmentResource();
    static  PyIfcEntityDesc IfcConstructionEquipmentResourceType();
    static  PyIfcEntityDesc IfcConstructionMaterialResource();
    static  PyIfcEntityDesc IfcConstructionMaterialResourceType();
    static  PyIfcEntityDesc IfcConstructionProductResource();
    static  PyIfcEntityDesc IfcConstructionProductResourceType();
    static  PyIfcEntityDesc IfcConstructionResource();
    static  PyIfcEntityDesc IfcConstructionResourceType();
    static  PyIfcEntityDesc IfcContext();
    static  PyIfcEntityDesc IfcContextDependentUnit();
    static  PyIfcEntityDesc IfcControl();
    static  PyIfcEntityDesc IfcController();
    static  PyIfcEntityDesc IfcControllerType();
    static  PyIfcEntityDesc IfcConversionBasedUnit();
    static  PyIfcEntityDesc IfcConversionBasedUnitWithOffset();
    static  PyIfcEntityDesc IfcCooledBeam();
    static  PyIfcEntityDesc IfcCooledBeamType();
    static  PyIfcEntityDesc IfcCoolingTower();
    static  PyIfcEntityDesc IfcCoolingTowerType();
    static  PyIfcEntityDesc IfcCoordinateOperation();
    static  PyIfcEntityDesc IfcCoordinateReferenceSystem();
    static  PyIfcEntityDesc IfcCoordinatedUniversalTimeOffset();
    static  PyIfcEntityDesc IfcCostItem();
    static  PyIfcEntityDesc IfcCostSchedule();
    static  PyIfcEntityDesc IfcCostValue();
    static  PyIfcEntityDesc IfcCovering();
    static  PyIfcEntityDesc IfcCoveringType();
    static  PyIfcEntityDesc IfcCraneRailAShapeProfileDef();
    static  PyIfcEntityDesc IfcCraneRailFShapeProfileDef();
    static  PyIfcEntityDesc IfcCrewResource();
    static  PyIfcEntityDesc IfcCrewResourceType();
    static  PyIfcEntityDesc IfcCsgPrimitive3D();
    static  PyIfcEntityDesc IfcCsgSolid();
    static  PyIfcEntityDesc IfcCurrencyRelationship();
    static  PyIfcEntityDesc IfcCurtainWall();
    static  PyIfcEntityDesc IfcCurtainWallType();
    static  PyIfcEntityDesc IfcCurve();
    static  PyIfcEntityDesc IfcCurveBoundedPlane();
    static  PyIfcEntityDesc IfcCurveBoundedSurface();
    static  PyIfcEntityDesc IfcCurveSegment2D();
    static  PyIfcEntityDesc IfcCurveStyle();
    static  PyIfcEntityDesc IfcCurveStyleFont();
    static  PyIfcEntityDesc IfcCurveStyleFontAndScaling();
    static  PyIfcEntityDesc IfcCurveStyleFontPattern();
    static  PyIfcEntityDesc IfcCylindricalSurface();
    static  PyIfcEntityDesc IfcDamper();
    static  PyIfcEntityDesc IfcDamperType();
    static  PyIfcEntityDesc IfcDateAndTime();
    static  PyIfcEntityDesc IfcDefinedSymbol();
    static  PyIfcEntityDesc IfcDerivedProfileDef();
    static  PyIfcEntityDesc IfcDerivedUnit();
    static  PyIfcEntityDesc IfcDerivedUnitElement();
    static  PyIfcEntityDesc IfcDiameterDimension();
    static  PyIfcEntityDesc IfcDimensionCalloutRelationship();
    static  PyIfcEntityDesc IfcDimensionCurve();
    static  PyIfcEntityDesc IfcDimensionCurveDirectedCallout();
    static  PyIfcEntityDesc IfcDimensionCurveTerminator();
    static  PyIfcEntityDesc IfcDimensionPair();
    static  PyIfcEntityDesc IfcDimensionalExponents();
    static  PyIfcEntityDesc IfcDirection();
    static  PyIfcEntityDesc IfcDiscreteAccessory();
    static  PyIfcEntityDesc IfcDiscreteAccessoryType();
    static  PyIfcEntityDesc IfcDistanceExpression();
    static  PyIfcEntityDesc IfcDistributionChamberElement();
    static  PyIfcEntityDesc IfcDistributionChamberElementType();
    static  PyIfcEntityDesc IfcDistributionCircuit();
    static  PyIfcEntityDesc IfcDistributionControlElement();
    static  PyIfcEntityDesc IfcDistributionControlElementType();
    static  PyIfcEntityDesc IfcDistributionElement();
    static  PyIfcEntityDesc IfcDistributionElementType();
    static  PyIfcEntityDesc IfcDistributionFlowElement();
    static  PyIfcEntityDesc IfcDistributionFlowElementType();
    static  PyIfcEntityDesc IfcDistributionPort();
    static  PyIfcEntityDesc IfcDistributionSystem();
    static  PyIfcEntityDesc IfcDocumentElectronicFormat();
    static  PyIfcEntityDesc IfcDocumentInformation();
    static  PyIfcEntityDesc IfcDocumentInformationRelationship();
    static  PyIfcEntityDesc IfcDocumentReference();
    static  PyIfcEntityDesc IfcDoor();
    static  PyIfcEntityDesc IfcDoorLiningProperties();
    static  PyIfcEntityDesc IfcDoorPanelProperties();
    static  PyIfcEntityDesc IfcDoorStandardCase();
    static  PyIfcEntityDesc IfcDoorStyle();
    static  PyIfcEntityDesc IfcDoorType();
    static  PyIfcEntityDesc IfcDraughtingCallout();
    static  PyIfcEntityDesc IfcDraughtingCalloutRelationship();
    static  PyIfcEntityDesc IfcDraughtingPreDefinedColour();
    static  PyIfcEntityDesc IfcDraughtingPreDefinedCurveFont();
    static  PyIfcEntityDesc IfcDraughtingPreDefinedTextFont();
    static  PyIfcEntityDesc IfcDuctFitting();
    static  PyIfcEntityDesc IfcDuctFittingType();
    static  PyIfcEntityDesc IfcDuctSegment();
    static  PyIfcEntityDesc IfcDuctSegmentType();
    static  PyIfcEntityDesc IfcDuctSilencer();
    static  PyIfcEntityDesc IfcDuctSilencerType();
    static  PyIfcEntityDesc IfcEdge();
    static  PyIfcEntityDesc IfcEdgeCurve();
    static  PyIfcEntityDesc IfcEdgeFeature();
    static  PyIfcEntityDesc IfcEdgeLoop();
    static  PyIfcEntityDesc IfcElectricAppliance();
    static  PyIfcEntityDesc IfcElectricApplianceType();
    static  PyIfcEntityDesc IfcElectricDistributionBoard();
    static  PyIfcEntityDesc IfcElectricDistributionBoardType();
    static  PyIfcEntityDesc IfcElectricDistributionPoint();
    static  PyIfcEntityDesc IfcElectricFlowStorageDevice();
    static  PyIfcEntityDesc IfcElectricFlowStorageDeviceType();
    static  PyIfcEntityDesc IfcElectricGenerator();
    static  PyIfcEntityDesc IfcElectricGeneratorType();
    static  PyIfcEntityDesc IfcElectricHeaterType();
    static  PyIfcEntityDesc IfcElectricMotor();
    static  PyIfcEntityDesc IfcElectricMotorType();
    static  PyIfcEntityDesc IfcElectricTimeControl();
    static  PyIfcEntityDesc IfcElectricTimeControlType();
    static  PyIfcEntityDesc IfcElectricalBaseProperties();
    static  PyIfcEntityDesc IfcElectricalCircuit();
    static  PyIfcEntityDesc IfcElectricalElement();
    static  PyIfcEntityDesc IfcElement();
    static  PyIfcEntityDesc IfcElementAssembly();
    static  PyIfcEntityDesc IfcElementAssemblyType();
    static  PyIfcEntityDesc IfcElementComponent();
    static  PyIfcEntityDesc IfcElementComponentType();
    static  PyIfcEntityDesc IfcElementQuantity();
    static  PyIfcEntityDesc IfcElementType();
    static  PyIfcEntityDesc IfcElementarySurface();
    static  PyIfcEntityDesc IfcEllipse();
    static  PyIfcEntityDesc IfcEllipseProfileDef();
    static  PyIfcEntityDesc IfcEnergyConversionDevice();
    static  PyIfcEntityDesc IfcEnergyConversionDeviceType();
    static  PyIfcEntityDesc IfcEnergyProperties();
    static  PyIfcEntityDesc IfcEngine();
    static  PyIfcEntityDesc IfcEngineType();
    static  PyIfcEntityDesc IfcEnvironmentalImpactValue();
    static  PyIfcEntityDesc IfcEquipmentElement();
    static  PyIfcEntityDesc IfcEquipmentStandard();
    static  PyIfcEntityDesc IfcEvaporativeCooler();
    static  PyIfcEntityDesc IfcEvaporativeCoolerType();
    static  PyIfcEntityDesc IfcEvaporator();
    static  PyIfcEntityDesc IfcEvaporatorType();
    static  PyIfcEntityDesc IfcEvent();
    static  PyIfcEntityDesc IfcEventTime();
    static  PyIfcEntityDesc IfcEventType();
    static  PyIfcEntityDesc IfcExtendedMaterialProperties();
    static  PyIfcEntityDesc IfcExtendedProperties();
    static  PyIfcEntityDesc IfcExternalInformation();
    static  PyIfcEntityDesc IfcExternalReference();
    static  PyIfcEntityDesc IfcExternalReferenceRelationship();
    static  PyIfcEntityDesc IfcExternalSpatialElement();
    static  PyIfcEntityDesc IfcExternalSpatialStructureElement();
    static  PyIfcEntityDesc IfcExternallyDefinedHatchStyle();
    static  PyIfcEntityDesc IfcExternallyDefinedSurfaceStyle();
    static  PyIfcEntityDesc IfcExternallyDefinedSymbol();
    static  PyIfcEntityDesc IfcExternallyDefinedTextFont();
    static  PyIfcEntityDesc IfcExtrudedAreaSolid();
    static  PyIfcEntityDesc IfcExtrudedAreaSolidTapered();
    static  PyIfcEntityDesc IfcFace();
    static  PyIfcEntityDesc IfcFaceBasedSurfaceModel();
    static  PyIfcEntityDesc IfcFaceBound();
    static  PyIfcEntityDesc IfcFaceOuterBound();
    static  PyIfcEntityDesc IfcFaceSurface();
    static  PyIfcEntityDesc IfcFacetedBrep();
    static  PyIfcEntityDesc IfcFacetedBrepWithVoids();
    static  PyIfcEntityDesc IfcFailureConnectionCondition();
    static  PyIfcEntityDesc IfcFan();
    static  PyIfcEntityDesc IfcFanType();
    static  PyIfcEntityDesc IfcFastener();
    static  PyIfcEntityDesc IfcFastenerType();
    static  PyIfcEntityDesc IfcFeatureElement();
    static  PyIfcEntityDesc IfcFeatureElementAddition();
    static  PyIfcEntityDesc IfcFeatureElementSubtraction();
    static  PyIfcEntityDesc IfcFillAreaStyle();
    static  PyIfcEntityDesc IfcFillAreaStyleHatching();
    static  PyIfcEntityDesc IfcFillAreaStyleTileSymbolWithStyle();
    static  PyIfcEntityDesc IfcFillAreaStyleTiles();
    static  PyIfcEntityDesc IfcFilter();
    static  PyIfcEntityDesc IfcFilterType();
    static  PyIfcEntityDesc IfcFireSuppressionTerminal();
    static  PyIfcEntityDesc IfcFireSuppressionTerminalType();
    static  PyIfcEntityDesc IfcFixedReferenceSweptAreaSolid();
    static  PyIfcEntityDesc IfcFlowController();
    static  PyIfcEntityDesc IfcFlowControllerType();
    static  PyIfcEntityDesc IfcFlowFitting();
    static  PyIfcEntityDesc IfcFlowFittingType();
    static  PyIfcEntityDesc IfcFlowInstrument();
    static  PyIfcEntityDesc IfcFlowInstrumentType();
    static  PyIfcEntityDesc IfcFlowMeter();
    static  PyIfcEntityDesc IfcFlowMeterType();
    static  PyIfcEntityDesc IfcFlowMovingDevice();
    static  PyIfcEntityDesc IfcFlowMovingDeviceType();
    static  PyIfcEntityDesc IfcFlowSegment();
    static  PyIfcEntityDesc IfcFlowSegmentType();
    static  PyIfcEntityDesc IfcFlowStorageDevice();
    static  PyIfcEntityDesc IfcFlowStorageDeviceType();
    static  PyIfcEntityDesc IfcFlowTerminal();
    static  PyIfcEntityDesc IfcFlowTerminalType();
    static  PyIfcEntityDesc IfcFlowTreatmentDevice();
    static  PyIfcEntityDesc IfcFlowTreatmentDeviceType();
    static  PyIfcEntityDesc IfcFluidFlowProperties();
    static  PyIfcEntityDesc IfcFooting();
    static  PyIfcEntityDesc IfcFootingType();
    static  PyIfcEntityDesc IfcFuelProperties();
    static  PyIfcEntityDesc IfcFurnishingElement();
    static  PyIfcEntityDesc IfcFurnishingElementType();
    static  PyIfcEntityDesc IfcFurniture();
    static  PyIfcEntityDesc IfcFurnitureStandard();
    static  PyIfcEntityDesc IfcFurnitureType();
    static  PyIfcEntityDesc IfcGasTerminalType();
    static  PyIfcEntityDesc IfcGeneralMaterialProperties();
    static  PyIfcEntityDesc IfcGeneralProfileProperties();
    static  PyIfcEntityDesc IfcGeographicElement();
    static  PyIfcEntityDesc IfcGeographicElementType();
    static  PyIfcEntityDesc IfcGeometricCurveSet();
    static  PyIfcEntityDesc IfcGeometricRepresentationContext();
    static  PyIfcEntityDesc IfcGeometricRepresentationItem();
    static  PyIfcEntityDesc IfcGeometricRepresentationSubContext();
    static  PyIfcEntityDesc IfcGeometricSet();
    static  PyIfcEntityDesc IfcGrid();
    static  PyIfcEntityDesc IfcGridAxis();
    static  PyIfcEntityDesc IfcGridPlacement();
    static  PyIfcEntityDesc IfcGroup();
    static  PyIfcEntityDesc IfcHalfSpaceSolid();
    static  PyIfcEntityDesc IfcHeatExchanger();
    static  PyIfcEntityDesc IfcHeatExchangerType();
    static  PyIfcEntityDesc IfcHumidifier();
    static  PyIfcEntityDesc IfcHumidifierType();
    static  PyIfcEntityDesc IfcHygroscopicMaterialProperties();
    static  PyIfcEntityDesc IfcIShapeProfileDef();
    static  PyIfcEntityDesc IfcImageTexture();
    static  PyIfcEntityDesc IfcIndexedColourMap();
    static  PyIfcEntityDesc IfcIndexedPolyCurve();
    static  PyIfcEntityDesc IfcIndexedPolygonalFace();
    static  PyIfcEntityDesc IfcIndexedPolygonalFaceWithVoids();
    static  PyIfcEntityDesc IfcIndexedTextureMap();
    static  PyIfcEntityDesc IfcIndexedTriangleTextureMap();
    static  PyIfcEntityDesc IfcInterceptor();
    static  PyIfcEntityDesc IfcInterceptorType();
    static  PyIfcEntityDesc IfcIntersectionCurve();
    static  PyIfcEntityDesc IfcInventory();
    static  PyIfcEntityDesc IfcIrregularTimeSeries();
    static  PyIfcEntityDesc IfcIrregularTimeSeriesValue();
    static  PyIfcEntityDesc IfcJunctionBox();
    static  PyIfcEntityDesc IfcJunctionBoxType();
    static  PyIfcEntityDesc IfcLShapeProfileDef();
    static  PyIfcEntityDesc IfcLaborResource();
    static  PyIfcEntityDesc IfcLaborResourceType();
    static  PyIfcEntityDesc IfcLagTime();
    static  PyIfcEntityDesc IfcLamp();
    static  PyIfcEntityDesc IfcLampType();
    static  PyIfcEntityDesc IfcLibraryInformation();
    static  PyIfcEntityDesc IfcLibraryReference();
    static  PyIfcEntityDesc IfcLightDistributionData();
    static  PyIfcEntityDesc IfcLightFixture();
    static  PyIfcEntityDesc IfcLightFixtureType();
    static  PyIfcEntityDesc IfcLightIntensityDistribution();
    static  PyIfcEntityDesc IfcLightSource();
    static  PyIfcEntityDesc IfcLightSourceAmbient();
    static  PyIfcEntityDesc IfcLightSourceDirectional();
    static  PyIfcEntityDesc IfcLightSourceGoniometric();
    static  PyIfcEntityDesc IfcLightSourcePositional();
    static  PyIfcEntityDesc IfcLightSourceSpot();
    static  PyIfcEntityDesc IfcLine();
    static  PyIfcEntityDesc IfcLineSegment2D();
    static  PyIfcEntityDesc IfcLinearDimension();
    static  PyIfcEntityDesc IfcLinearPlacement();
    static  PyIfcEntityDesc IfcLinearPositioningElement();
    static  PyIfcEntityDesc IfcLocalPlacement();
    static  PyIfcEntityDesc IfcLocalTime();
    static  PyIfcEntityDesc IfcLoop();
    static  PyIfcEntityDesc IfcManifoldSolidBrep();
    static  PyIfcEntityDesc IfcMapConversion();
    static  PyIfcEntityDesc IfcMappedItem();
    static  PyIfcEntityDesc IfcMaterial();
    static  PyIfcEntityDesc IfcMaterialClassificationRelationship();
    static  PyIfcEntityDesc IfcMaterialConstituent();
    static  PyIfcEntityDesc IfcMaterialConstituentSet();
    static  PyIfcEntityDesc IfcMaterialDefinition();
    static  PyIfcEntityDesc IfcMaterialDefinitionRepresentation();
    static  PyIfcEntityDesc IfcMaterialLayer();
    static  PyIfcEntityDesc IfcMaterialLayerSet();
    static  PyIfcEntityDesc IfcMaterialLayerSetUsage();
    static  PyIfcEntityDesc IfcMaterialLayerWithOffsets();
    static  PyIfcEntityDesc IfcMaterialList();
    static  PyIfcEntityDesc IfcMaterialProfile();
    static  PyIfcEntityDesc IfcMaterialProfileSet();
    static  PyIfcEntityDesc IfcMaterialProfileSetUsage();
    static  PyIfcEntityDesc IfcMaterialProfileSetUsageTapering();
    static  PyIfcEntityDesc IfcMaterialProfileWithOffsets();
    static  PyIfcEntityDesc IfcMaterialProperties();
    static  PyIfcEntityDesc IfcMaterialRelationship();
    static  PyIfcEntityDesc IfcMaterialUsageDefinition();
    static  PyIfcEntityDesc IfcMeasureWithUnit();
    static  PyIfcEntityDesc IfcMechanicalConcreteMaterialProperties();
    static  PyIfcEntityDesc IfcMechanicalFastener();
    static  PyIfcEntityDesc IfcMechanicalFastenerType();
    static  PyIfcEntityDesc IfcMechanicalMaterialProperties();
    static  PyIfcEntityDesc IfcMechanicalSteelMaterialProperties();
    static  PyIfcEntityDesc IfcMedicalDevice();
    static  PyIfcEntityDesc IfcMedicalDeviceType();
    static  PyIfcEntityDesc IfcMember();
    static  PyIfcEntityDesc IfcMemberStandardCase();
    static  PyIfcEntityDesc IfcMemberType();
    static  PyIfcEntityDesc IfcMetric();
    static  PyIfcEntityDesc IfcMirroredProfileDef();
    static  PyIfcEntityDesc IfcMonetaryUnit();
    static  PyIfcEntityDesc IfcMotorConnection();
    static  PyIfcEntityDesc IfcMotorConnectionType();
    static  PyIfcEntityDesc IfcMove();
    static  PyIfcEntityDesc IfcNamedUnit();
    static  PyIfcEntityDesc IfcObject();
    static  PyIfcEntityDesc IfcObjectDefinition();
    static  PyIfcEntityDesc IfcObjectPlacement();
    static  PyIfcEntityDesc IfcObjective();
    static  PyIfcEntityDesc IfcOccupant();
    static  PyIfcEntityDesc IfcOffsetCurve();
    static  PyIfcEntityDesc IfcOffsetCurve2D();
    static  PyIfcEntityDesc IfcOffsetCurve3D();
    static  PyIfcEntityDesc IfcOffsetCurveByDistances();
    static  PyIfcEntityDesc IfcOneDirectionRepeatFactor();
    static  PyIfcEntityDesc IfcOpenShell();
    static  PyIfcEntityDesc IfcOpeningElement();
    static  PyIfcEntityDesc IfcOpeningStandardCase();
    static  PyIfcEntityDesc IfcOpticalMaterialProperties();
    static  PyIfcEntityDesc IfcOrderAction();
    static  PyIfcEntityDesc IfcOrganization();
    static  PyIfcEntityDesc IfcOrganizationRelationship();
    static  PyIfcEntityDesc IfcOrientationExpression();
    static  PyIfcEntityDesc IfcOrientedEdge();
    static  PyIfcEntityDesc IfcOuterBoundaryCurve();
    static  PyIfcEntityDesc IfcOutlet();
    static  PyIfcEntityDesc IfcOutletType();
    static  PyIfcEntityDesc IfcOwnerHistory();
    static  PyIfcEntityDesc IfcParameterizedProfileDef();
    static  PyIfcEntityDesc IfcPath();
    static  PyIfcEntityDesc IfcPcurve();
    static  PyIfcEntityDesc IfcPerformanceHistory();
    static  PyIfcEntityDesc IfcPermeableCoveringProperties();
    static  PyIfcEntityDesc IfcPermit();
    static  PyIfcEntityDesc IfcPerson();
    static  PyIfcEntityDesc IfcPersonAndOrganization();
    static  PyIfcEntityDesc IfcPhysicalComplexQuantity();
    static  PyIfcEntityDesc IfcPhysicalQuantity();
    static  PyIfcEntityDesc IfcPhysicalSimpleQuantity();
    static  PyIfcEntityDesc IfcPile();
    static  PyIfcEntityDesc IfcPileType();
    static  PyIfcEntityDesc IfcPipeFitting();
    static  PyIfcEntityDesc IfcPipeFittingType();
    static  PyIfcEntityDesc IfcPipeSegment();
    static  PyIfcEntityDesc IfcPipeSegmentType();
    static  PyIfcEntityDesc IfcPixelTexture();
    static  PyIfcEntityDesc IfcPlacement();
    static  PyIfcEntityDesc IfcPlanarBox();
    static  PyIfcEntityDesc IfcPlanarExtent();
    static  PyIfcEntityDesc IfcPlane();
    static  PyIfcEntityDesc IfcPlate();
    static  PyIfcEntityDesc IfcPlateStandardCase();
    static  PyIfcEntityDesc IfcPlateType();
    static  PyIfcEntityDesc IfcPoint();
    static  PyIfcEntityDesc IfcPointOnCurve();
    static  PyIfcEntityDesc IfcPointOnSurface();
    static  PyIfcEntityDesc IfcPolyLoop();
    static  PyIfcEntityDesc IfcPolygonalBoundedHalfSpace();
    static  PyIfcEntityDesc IfcPolygonalFaceSet();
    static  PyIfcEntityDesc IfcPolyline();
    static  PyIfcEntityDesc IfcPort();
    static  PyIfcEntityDesc IfcPositioningElement();
    static  PyIfcEntityDesc IfcPostalAddress();
    static  PyIfcEntityDesc IfcPreDefinedColour();
    static  PyIfcEntityDesc IfcPreDefinedCurveFont();
    static  PyIfcEntityDesc IfcPreDefinedDimensionSymbol();
    static  PyIfcEntityDesc IfcPreDefinedItem();
    static  PyIfcEntityDesc IfcPreDefinedPointMarkerSymbol();
    static  PyIfcEntityDesc IfcPreDefinedProperties();
    static  PyIfcEntityDesc IfcPreDefinedPropertySet();
    static  PyIfcEntityDesc IfcPreDefinedSymbol();
    static  PyIfcEntityDesc IfcPreDefinedTerminatorSymbol();
    static  PyIfcEntityDesc IfcPreDefinedTextFont();
    static  PyIfcEntityDesc IfcPresentationItem();
    static  PyIfcEntityDesc IfcPresentationLayerAssignment();
    static  PyIfcEntityDesc IfcPresentationLayerWithStyle();
    static  PyIfcEntityDesc IfcPresentationStyle();
    static  PyIfcEntityDesc IfcPresentationStyleAssignment();
    static  PyIfcEntityDesc IfcProcedure();
    static  PyIfcEntityDesc IfcProcedureType();
    static  PyIfcEntityDesc IfcProcess();
    static  PyIfcEntityDesc IfcProduct();
    static  PyIfcEntityDesc IfcProductDefinitionShape();
    static  PyIfcEntityDesc IfcProductRepresentation();
    static  PyIfcEntityDesc IfcProductsOfCombustionProperties();
    static  PyIfcEntityDesc IfcProfileDef();
    static  PyIfcEntityDesc IfcProfileProperties();
    static  PyIfcEntityDesc IfcProject();
    static  PyIfcEntityDesc IfcProjectLibrary();
    static  PyIfcEntityDesc IfcProjectOrder();
    static  PyIfcEntityDesc IfcProjectOrderRecord();
    static  PyIfcEntityDesc IfcProjectedCRS();
    static  PyIfcEntityDesc IfcProjectionCurve();
    static  PyIfcEntityDesc IfcProjectionElement();
    static  PyIfcEntityDesc IfcProperty();
    static  PyIfcEntityDesc IfcPropertyAbstraction();
    static  PyIfcEntityDesc IfcPropertyBoundedValue();
    static  PyIfcEntityDesc IfcPropertyConstraintRelationship();
    static  PyIfcEntityDesc IfcPropertyDefinition();
    static  PyIfcEntityDesc IfcPropertyDependencyRelationship();
    static  PyIfcEntityDesc IfcPropertyEnumeratedValue();
    static  PyIfcEntityDesc IfcPropertyEnumeration();
    static  PyIfcEntityDesc IfcPropertyListValue();
    static  PyIfcEntityDesc IfcPropertyReferenceValue();
    static  PyIfcEntityDesc IfcPropertySet();
    static  PyIfcEntityDesc IfcPropertySetDefinition();
    static  PyIfcEntityDesc IfcPropertySetTemplate();
    static  PyIfcEntityDesc IfcPropertySingleValue();
    static  PyIfcEntityDesc IfcPropertyTableValue();
    static  PyIfcEntityDesc IfcPropertyTemplate();
    static  PyIfcEntityDesc IfcPropertyTemplateDefinition();
    static  PyIfcEntityDesc IfcProtectiveDevice();
    static  PyIfcEntityDesc IfcProtectiveDeviceTrippingUnit();
    static  PyIfcEntityDesc IfcProtectiveDeviceTrippingUnitType();
    static  PyIfcEntityDesc IfcProtectiveDeviceType();
    static  PyIfcEntityDesc IfcProxy();
    static  PyIfcEntityDesc IfcPump();
    static  PyIfcEntityDesc IfcPumpType();
    static  PyIfcEntityDesc IfcQuantityArea();
    static  PyIfcEntityDesc IfcQuantityCount();
    static  PyIfcEntityDesc IfcQuantityLength();
    static  PyIfcEntityDesc IfcQuantitySet();
    static  PyIfcEntityDesc IfcQuantityTime();
    static  PyIfcEntityDesc IfcQuantityVolume();
    static  PyIfcEntityDesc IfcQuantityWeight();
    static  PyIfcEntityDesc IfcRadiusDimension();
    static  PyIfcEntityDesc IfcRailing();
    static  PyIfcEntityDesc IfcRailingType();
    static  PyIfcEntityDesc IfcRamp();
    static  PyIfcEntityDesc IfcRampFlight();
    static  PyIfcEntityDesc IfcRampFlightType();
    static  PyIfcEntityDesc IfcRampType();
    static  PyIfcEntityDesc IfcRationalBSplineCurveWithKnots();
    static  PyIfcEntityDesc IfcRationalBSplineSurfaceWithKnots();
    static  PyIfcEntityDesc IfcRationalBezierCurve();
    static  PyIfcEntityDesc IfcRectangleHollowProfileDef();
    static  PyIfcEntityDesc IfcRectangleProfileDef();
    static  PyIfcEntityDesc IfcRectangularPyramid();
    static  PyIfcEntityDesc IfcRectangularTrimmedSurface();
    static  PyIfcEntityDesc IfcRecurrencePattern();
    static  PyIfcEntityDesc IfcReference();
    static  PyIfcEntityDesc IfcReferencesValueDocument();
    static  PyIfcEntityDesc IfcReferent();
    static  PyIfcEntityDesc IfcRegularTimeSeries();
    static  PyIfcEntityDesc IfcReinforcementBarProperties();
    static  PyIfcEntityDesc IfcReinforcementDefinitionProperties();
    static  PyIfcEntityDesc IfcReinforcingBar();
    static  PyIfcEntityDesc IfcReinforcingBarType();
    static  PyIfcEntityDesc IfcReinforcingElement();
    static  PyIfcEntityDesc IfcReinforcingElementType();
    static  PyIfcEntityDesc IfcReinforcingMesh();
    static  PyIfcEntityDesc IfcReinforcingMeshType();
    static  PyIfcEntityDesc IfcRelAggregates();
    static  PyIfcEntityDesc IfcRelAssigns();
    static  PyIfcEntityDesc IfcRelAssignsTasks();
    static  PyIfcEntityDesc IfcRelAssignsToActor();
    static  PyIfcEntityDesc IfcRelAssignsToControl();
    static  PyIfcEntityDesc IfcRelAssignsToGroup();
    static  PyIfcEntityDesc IfcRelAssignsToGroupByFactor();
    static  PyIfcEntityDesc IfcRelAssignsToProcess();
    static  PyIfcEntityDesc IfcRelAssignsToProduct();
    static  PyIfcEntityDesc IfcRelAssignsToProjectOrder();
    static  PyIfcEntityDesc IfcRelAssignsToResource();
    static  PyIfcEntityDesc IfcRelAssociates();
    static  PyIfcEntityDesc IfcRelAssociatesAppliedValue();
    static  PyIfcEntityDesc IfcRelAssociatesApproval();
    static  PyIfcEntityDesc IfcRelAssociatesClassification();
    static  PyIfcEntityDesc IfcRelAssociatesConstraint();
    static  PyIfcEntityDesc IfcRelAssociatesDocument();
    static  PyIfcEntityDesc IfcRelAssociatesLibrary();
    static  PyIfcEntityDesc IfcRelAssociatesMaterial();
    static  PyIfcEntityDesc IfcRelAssociatesProfileProperties();
    static  PyIfcEntityDesc IfcRelConnects();
    static  PyIfcEntityDesc IfcRelConnectsElements();
    static  PyIfcEntityDesc IfcRelConnectsPathElements();
    static  PyIfcEntityDesc IfcRelConnectsPortToElement();
    static  PyIfcEntityDesc IfcRelConnectsPorts();
    static  PyIfcEntityDesc IfcRelConnectsStructuralActivity();
    static  PyIfcEntityDesc IfcRelConnectsStructuralElement();
    static  PyIfcEntityDesc IfcRelConnectsStructuralMember();
    static  PyIfcEntityDesc IfcRelConnectsWithEccentricity();
    static  PyIfcEntityDesc IfcRelConnectsWithRealizingElements();
    static  PyIfcEntityDesc IfcRelContainedInSpatialStructure();
    static  PyIfcEntityDesc IfcRelCoversBldgElements();
    static  PyIfcEntityDesc IfcRelCoversSpaces();
    static  PyIfcEntityDesc IfcRelDeclares();
    static  PyIfcEntityDesc IfcRelDecomposes();
    static  PyIfcEntityDesc IfcRelDefines();
    static  PyIfcEntityDesc IfcRelDefinesByObject();
    static  PyIfcEntityDesc IfcRelDefinesByProperties();
    static  PyIfcEntityDesc IfcRelDefinesByTemplate();
    static  PyIfcEntityDesc IfcRelDefinesByType();
    static  PyIfcEntityDesc IfcRelFillsElement();
    static  PyIfcEntityDesc IfcRelFlowControlElements();
    static  PyIfcEntityDesc IfcRelInteractionRequirements();
    static  PyIfcEntityDesc IfcRelInterferesElements();
    static  PyIfcEntityDesc IfcRelNests();
    static  PyIfcEntityDesc IfcRelOccupiesSpaces();
    static  PyIfcEntityDesc IfcRelOverridesProperties();
    static  PyIfcEntityDesc IfcRelProjectsElement();
    static  PyIfcEntityDesc IfcRelReferencedInSpatialStructure();
    static  PyIfcEntityDesc IfcRelSchedulesCostItems();
    static  PyIfcEntityDesc IfcRelSequence();
    static  PyIfcEntityDesc IfcRelServicesBuildings();
    static  PyIfcEntityDesc IfcRelSpaceBoundary();
    static  PyIfcEntityDesc IfcRelSpaceBoundary1stLevel();
    static  PyIfcEntityDesc IfcRelSpaceBoundary2ndLevel();
    static  PyIfcEntityDesc IfcRelVoidsElement();
    static  PyIfcEntityDesc IfcRelationship();
    static  PyIfcEntityDesc IfcRelaxation();
    static  PyIfcEntityDesc IfcReparametrisedCompositeCurveSegment();
    static  PyIfcEntityDesc IfcRepresentation();
    static  PyIfcEntityDesc IfcRepresentationContext();
    static  PyIfcEntityDesc IfcRepresentationItem();
    static  PyIfcEntityDesc IfcRepresentationMap();
    static  PyIfcEntityDesc IfcResource();
    static  PyIfcEntityDesc IfcResourceApprovalRelationship();
    static  PyIfcEntityDesc IfcResourceConstraintRelationship();
    static  PyIfcEntityDesc IfcResourceLevelRelationship();
    static  PyIfcEntityDesc IfcResourceTime();
    static  PyIfcEntityDesc IfcRevolvedAreaSolid();
    static  PyIfcEntityDesc IfcRevolvedAreaSolidTapered();
    static  PyIfcEntityDesc IfcRibPlateProfileProperties();
    static  PyIfcEntityDesc IfcRightCircularCone();
    static  PyIfcEntityDesc IfcRightCircularCylinder();
    static  PyIfcEntityDesc IfcRoof();
    static  PyIfcEntityDesc IfcRoofType();
    static  PyIfcEntityDesc IfcRoot();
    static  PyIfcEntityDesc IfcRoundedEdgeFeature();
    static  PyIfcEntityDesc IfcRoundedRectangleProfileDef();
    static  PyIfcEntityDesc IfcSIUnit();
    static  PyIfcEntityDesc IfcSanitaryTerminal();
    static  PyIfcEntityDesc IfcSanitaryTerminalType();
    static  PyIfcEntityDesc IfcScheduleTimeControl();
    static  PyIfcEntityDesc IfcSchedulingTime();
    static  PyIfcEntityDesc IfcSeamCurve();
    static  PyIfcEntityDesc IfcSectionProperties();
    static  PyIfcEntityDesc IfcSectionReinforcementProperties();
    static  PyIfcEntityDesc IfcSectionedSolid();
    static  PyIfcEntityDesc IfcSectionedSolidHorizontal();
    static  PyIfcEntityDesc IfcSectionedSpine();
    static  PyIfcEntityDesc IfcSensor();
    static  PyIfcEntityDesc IfcSensorType();
    static  PyIfcEntityDesc IfcServiceLife();
    static  PyIfcEntityDesc IfcServiceLifeFactor();
    static  PyIfcEntityDesc IfcShadingDevice();
    static  PyIfcEntityDesc IfcShadingDeviceType();
    static  PyIfcEntityDesc IfcShapeAspect();
    static  PyIfcEntityDesc IfcShapeModel();
    static  PyIfcEntityDesc IfcShapeRepresentation();
    static  PyIfcEntityDesc IfcShellBasedSurfaceModel();
    static  PyIfcEntityDesc IfcSimpleProperty();
    static  PyIfcEntityDesc IfcSimplePropertyTemplate();
    static  PyIfcEntityDesc IfcSite();
    static  PyIfcEntityDesc IfcSlab();
    static  PyIfcEntityDesc IfcSlabElementedCase();
    static  PyIfcEntityDesc IfcSlabStandardCase();
    static  PyIfcEntityDesc IfcSlabType();
    static  PyIfcEntityDesc IfcSlippageConnectionCondition();
    static  PyIfcEntityDesc IfcSolarDevice();
    static  PyIfcEntityDesc IfcSolarDeviceType();
    static  PyIfcEntityDesc IfcSolidModel();
    static  PyIfcEntityDesc IfcSoundProperties();
    static  PyIfcEntityDesc IfcSoundValue();
    static  PyIfcEntityDesc IfcSpace();
    static  PyIfcEntityDesc IfcSpaceHeater();
    static  PyIfcEntityDesc IfcSpaceHeaterType();
    static  PyIfcEntityDesc IfcSpaceProgram();
    static  PyIfcEntityDesc IfcSpaceThermalLoadProperties();
    static  PyIfcEntityDesc IfcSpaceType();
    static  PyIfcEntityDesc IfcSpatialElement();
    static  PyIfcEntityDesc IfcSpatialElementType();
    static  PyIfcEntityDesc IfcSpatialStructureElement();
    static  PyIfcEntityDesc IfcSpatialStructureElementType();
    static  PyIfcEntityDesc IfcSpatialZone();
    static  PyIfcEntityDesc IfcSpatialZoneType();
    static  PyIfcEntityDesc IfcSphere();
    static  PyIfcEntityDesc IfcSphericalSurface();
    static  PyIfcEntityDesc IfcStackTerminal();
    static  PyIfcEntityDesc IfcStackTerminalType();
    static  PyIfcEntityDesc IfcStair();
    static  PyIfcEntityDesc IfcStairFlight();
    static  PyIfcEntityDesc IfcStairFlightType();
    static  PyIfcEntityDesc IfcStairType();
    static  PyIfcEntityDesc IfcStructuralAction();
    static  PyIfcEntityDesc IfcStructuralActivity();
    static  PyIfcEntityDesc IfcStructuralAnalysisModel();
    static  PyIfcEntityDesc IfcStructuralConnection();
    static  PyIfcEntityDesc IfcStructuralConnectionCondition();
    static  PyIfcEntityDesc IfcStructuralCurveAction();
    static  PyIfcEntityDesc IfcStructuralCurveConnection();
    static  PyIfcEntityDesc IfcStructuralCurveMember();
    static  PyIfcEntityDesc IfcStructuralCurveMemberVarying();
    static  PyIfcEntityDesc IfcStructuralCurveReaction();
    static  PyIfcEntityDesc IfcStructuralItem();
    static  PyIfcEntityDesc IfcStructuralLinearAction();
    static  PyIfcEntityDesc IfcStructuralLinearActionVarying();
    static  PyIfcEntityDesc IfcStructuralLoad();
    static  PyIfcEntityDesc IfcStructuralLoadCase();
    static  PyIfcEntityDesc IfcStructuralLoadConfiguration();
    static  PyIfcEntityDesc IfcStructuralLoadGroup();
    static  PyIfcEntityDesc IfcStructuralLoadLinearForce();
    static  PyIfcEntityDesc IfcStructuralLoadOrResult();
    static  PyIfcEntityDesc IfcStructuralLoadPlanarForce();
    static  PyIfcEntityDesc IfcStructuralLoadSingleDisplacement();
    static  PyIfcEntityDesc IfcStructuralLoadSingleDisplacementDistortion();
    static  PyIfcEntityDesc IfcStructuralLoadSingleForce();
    static  PyIfcEntityDesc IfcStructuralLoadSingleForceWarping();
    static  PyIfcEntityDesc IfcStructuralLoadStatic();
    static  PyIfcEntityDesc IfcStructuralLoadTemperature();
    static  PyIfcEntityDesc IfcStructuralMember();
    static  PyIfcEntityDesc IfcStructuralPlanarAction();
    static  PyIfcEntityDesc IfcStructuralPlanarActionVarying();
    static  PyIfcEntityDesc IfcStructuralPointAction();
    static  PyIfcEntityDesc IfcStructuralPointConnection();
    static  PyIfcEntityDesc IfcStructuralPointReaction();
    static  PyIfcEntityDesc IfcStructuralProfileProperties();
    static  PyIfcEntityDesc IfcStructuralReaction();
    static  PyIfcEntityDesc IfcStructuralResultGroup();
    static  PyIfcEntityDesc IfcStructuralSteelProfileProperties();
    static  PyIfcEntityDesc IfcStructuralSurfaceAction();
    static  PyIfcEntityDesc IfcStructuralSurfaceConnection();
    static  PyIfcEntityDesc IfcStructuralSurfaceMember();
    static  PyIfcEntityDesc IfcStructuralSurfaceMemberVarying();
    static  PyIfcEntityDesc IfcStructuralSurfaceReaction();
    static  PyIfcEntityDesc IfcStructuredDimensionCallout();
    static  PyIfcEntityDesc IfcStyleModel();
    static  PyIfcEntityDesc IfcStyledItem();
    static  PyIfcEntityDesc IfcStyledRepresentation();
    static  PyIfcEntityDesc IfcSubContractResource();
    static  PyIfcEntityDesc IfcSubContractResourceType();
    static  PyIfcEntityDesc IfcSubedge();
    static  PyIfcEntityDesc IfcSurface();
    static  PyIfcEntityDesc IfcSurfaceCurve();
    static  PyIfcEntityDesc IfcSurfaceCurveSweptAreaSolid();
    static  PyIfcEntityDesc IfcSurfaceFeature();
    static  PyIfcEntityDesc IfcSurfaceOfLinearExtrusion();
    static  PyIfcEntityDesc IfcSurfaceOfRevolution();
    static  PyIfcEntityDesc IfcSurfaceReinforcementArea();
    static  PyIfcEntityDesc IfcSurfaceStyle();
    static  PyIfcEntityDesc IfcSurfaceStyleLighting();
    static  PyIfcEntityDesc IfcSurfaceStyleRefraction();
    static  PyIfcEntityDesc IfcSurfaceStyleRendering();
    static  PyIfcEntityDesc IfcSurfaceStyleShading();
    static  PyIfcEntityDesc IfcSurfaceStyleWithTextures();
    static  PyIfcEntityDesc IfcSurfaceTexture();
    static  PyIfcEntityDesc IfcSweptAreaSolid();
    static  PyIfcEntityDesc IfcSweptDiskSolid();
    static  PyIfcEntityDesc IfcSweptDiskSolidPolygonal();
    static  PyIfcEntityDesc IfcSweptSurface();
    static  PyIfcEntityDesc IfcSwitchingDevice();
    static  PyIfcEntityDesc IfcSwitchingDeviceType();
    static  PyIfcEntityDesc IfcSymbolStyle();
    static  PyIfcEntityDesc IfcSystem();
    static  PyIfcEntityDesc IfcSystemFurnitureElement();
    static  PyIfcEntityDesc IfcSystemFurnitureElementType();
    static  PyIfcEntityDesc IfcTShapeProfileDef();
    static  PyIfcEntityDesc IfcTable();
    static  PyIfcEntityDesc IfcTableColumn();
    static  PyIfcEntityDesc IfcTableRow();
    static  PyIfcEntityDesc IfcTank();
    static  PyIfcEntityDesc IfcTankType();
    static  PyIfcEntityDesc IfcTask();
    static  PyIfcEntityDesc IfcTaskTime();
    static  PyIfcEntityDesc IfcTaskTimeRecurring();
    static  PyIfcEntityDesc IfcTaskType();
    static  PyIfcEntityDesc IfcTelecomAddress();
    static  PyIfcEntityDesc IfcTendon();
    static  PyIfcEntityDesc IfcTendonAnchor();
    static  PyIfcEntityDesc IfcTendonAnchorType();
    static  PyIfcEntityDesc IfcTendonType();
    static  PyIfcEntityDesc IfcTerminatorSymbol();
    static  PyIfcEntityDesc IfcTessellatedFaceSet();
    static  PyIfcEntityDesc IfcTessellatedItem();
    static  PyIfcEntityDesc IfcTextLiteral();
    static  PyIfcEntityDesc IfcTextLiteralWithExtent();
    static  PyIfcEntityDesc IfcTextStyle();
    static  PyIfcEntityDesc IfcTextStyleFontModel();
    static  PyIfcEntityDesc IfcTextStyleForDefinedFont();
    static  PyIfcEntityDesc IfcTextStyleTextModel();
    static  PyIfcEntityDesc IfcTextStyleWithBoxCharacteristics();
    static  PyIfcEntityDesc IfcTextureCoordinate();
    static  PyIfcEntityDesc IfcTextureCoordinateGenerator();
    static  PyIfcEntityDesc IfcTextureMap();
    static  PyIfcEntityDesc IfcTextureVertex();
    static  PyIfcEntityDesc IfcTextureVertexList();
    static  PyIfcEntityDesc IfcThermalMaterialProperties();
    static  PyIfcEntityDesc IfcTimePeriod();
    static  PyIfcEntityDesc IfcTimeSeries();
    static  PyIfcEntityDesc IfcTimeSeriesReferenceRelationship();
    static  PyIfcEntityDesc IfcTimeSeriesSchedule();
    static  PyIfcEntityDesc IfcTimeSeriesValue();
    static  PyIfcEntityDesc IfcTopologicalRepresentationItem();
    static  PyIfcEntityDesc IfcTopologyRepresentation();
    static  PyIfcEntityDesc IfcToroidalSurface();
    static  PyIfcEntityDesc IfcTransformer();
    static  PyIfcEntityDesc IfcTransformerType();
    static  PyIfcEntityDesc IfcTransitionCurveSegment2D();
    static  PyIfcEntityDesc IfcTransportElement();
    static  PyIfcEntityDesc IfcTransportElementType();
    static  PyIfcEntityDesc IfcTrapeziumProfileDef();
    static  PyIfcEntityDesc IfcTriangulatedFaceSet();
    static  PyIfcEntityDesc IfcTriangulatedIrregularNetwork();
    static  PyIfcEntityDesc IfcTrimmedCurve();
    static  PyIfcEntityDesc IfcTubeBundle();
    static  PyIfcEntityDesc IfcTubeBundleType();
    static  PyIfcEntityDesc IfcTwoDirectionRepeatFactor();
    static  PyIfcEntityDesc IfcTypeObject();
    static  PyIfcEntityDesc IfcTypeProcess();
    static  PyIfcEntityDesc IfcTypeProduct();
    static  PyIfcEntityDesc IfcTypeResource();
    static  PyIfcEntityDesc IfcUShapeProfileDef();
    static  PyIfcEntityDesc IfcUnitAssignment();
    static  PyIfcEntityDesc IfcUnitaryControlElement();
    static  PyIfcEntityDesc IfcUnitaryControlElementType();
    static  PyIfcEntityDesc IfcUnitaryEquipment();
    static  PyIfcEntityDesc IfcUnitaryEquipmentType();
    static  PyIfcEntityDesc IfcValve();
    static  PyIfcEntityDesc IfcValveType();
    static  PyIfcEntityDesc IfcVector();
    static  PyIfcEntityDesc IfcVertex();
    static  PyIfcEntityDesc IfcVertexBasedTextureMap();
    static  PyIfcEntityDesc IfcVertexLoop();
    static  PyIfcEntityDesc IfcVertexPoint();
    static  PyIfcEntityDesc IfcVibrationIsolator();
    static  PyIfcEntityDesc IfcVibrationIsolatorType();
    static  PyIfcEntityDesc IfcVirtualElement();
    static  PyIfcEntityDesc IfcVirtualGridIntersection();
    static  PyIfcEntityDesc IfcVoidingFeature();
    static  PyIfcEntityDesc IfcWall();
    static  PyIfcEntityDesc IfcWallElementedCase();
    static  PyIfcEntityDesc IfcWallStandardCase();
    static  PyIfcEntityDesc IfcWallType();
    static  PyIfcEntityDesc IfcWasteTerminal();
    static  PyIfcEntityDesc IfcWasteTerminalType();
    static  PyIfcEntityDesc IfcWaterProperties();
    static  PyIfcEntityDesc IfcWindow();
    static  PyIfcEntityDesc IfcWindowLiningProperties();
    static  PyIfcEntityDesc IfcWindowPanelProperties();
    static  PyIfcEntityDesc IfcWindowStandardCase();
    static  PyIfcEntityDesc IfcWindowStyle();
    static  PyIfcEntityDesc IfcWindowType();
    static  PyIfcEntityDesc IfcWorkCalendar();
    static  PyIfcEntityDesc IfcWorkControl();
    static  PyIfcEntityDesc IfcWorkPlan();
    static  PyIfcEntityDesc IfcWorkSchedule();
    static  PyIfcEntityDesc IfcWorkTime();
    static  PyIfcEntityDesc IfcZShapeProfileDef();
    static  PyIfcEntityDesc IfcZone();

    static std::string  className();
public:
    Ice::IfcApi::EntityDesc* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<Ice::IfcApi::EntityDesc> m_pyImp;
};

//---------------------------------------------------------------------------------------- -
//PyIfcEntity
void makePyIfcEntityWrapper();
class PyIfcEntity
{
public:
    PyIfcEntity();
    PyIfcEntity(const Ice::IfcApi::Entity& src);
    PyIfcEntity(const Ice::IfcApi::Entity* src);
    PyIfcEntity(Ice::IfcApi::Entity* pObject, bool autoDelete);
    ~PyIfcEntity() = default;

    int             ifcId() const;
    PyIfcVariant    getAttribute(const std::string& attbName) const;
    void            setAttribute(const std::string& attribName, const PyIfcVariant& attribValue);
    PyIfcEntityDesc isA() const;
    bool            isKindOf(const PyIfcEntityDesc& ent) const;
    bool            isNull() const;
    boost::python::list getInverseRefs() const;

    static PyIfcEntity  create(const PyIfcModel& model, const PyIfcEntityDesc& entityDesc);
    static PyIfcEntity  createNull();

    static std::string  className();
public:
    Ice::IfcApi::Entity* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<Ice::IfcApi::Entity> m_pyImp;
};

//---------------------------------------------------------------------------------------- -
//PyIfcHeader
void makePyIfcHeaderWrapper();
class PyIfcHeader
{
public:
    PyIfcHeader();
    PyIfcHeader(Ice::IfcApi::Header* pObject, bool autoDelete);
    ~PyIfcHeader() = default;

    PyIfcString fileDescription() const;
    PyIfcString implementationLevel() const;
    PyIfcString fileName() const;
    PyIfcString timeStamp() const;
    PyIfcString author() const;
    PyIfcString organization() const;
    PyIfcString preprocessorVersion() const;
    PyIfcString originatingSystem() const;
    PyIfcString authorization() const;
    PyIfcString fileSchema() const;

    void setFileDescription(const PyIfcString& str);
    void setFileName(const PyIfcString& str);
    void setTimeStamp(const PyIfcString& str);
    void setAuthor(const PyIfcString& str);
    void setOrganization(const PyIfcString& str);
    void setPreprocessorVersion(const PyIfcString& str);
    void setOriginatingSystem(const PyIfcString& str);
    void setAuthorization(const PyIfcString& str);
    void setFileSchema(const PyIfcString& str);

    static std::string  className();
public:
    Ice::IfcApi::Header* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<Ice::IfcApi::Header> m_pyImp;
};


//---------------------------------------------------------------------------------------- -
//PyIfcModel
void makePyIfcModelWrapper();
class PyIfcModel
{
public:

    PyIfcModel(Ice::IfcApi::Model* pObject, bool autoDelete);
    ~PyIfcModel() = default;

    void                release();
    size_t              getNumEntities() const;
    PyIfcEntity         get(size_t index) const;
    Ice::EIfcSchemaId   schemaId() const;
    bool                write(const std::string& fileName, const PyIfcHeader& header);

    static PyIfcModel   create(Ice::EIfcSchemaId schemaId);
    static PyIfcModel   read(const std::string& fileName);

    static std::string  className();
public:
    Ice::IfcApi::Model* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<Ice::IfcApi::Model> m_pyImp;
};


//---------------------------------------------------------------------------------------- -
//PyIfcVariant
void makePyIfcVariantWrapper();
class PyIfcVariant
{
public:
    PyIfcVariant();
    PyIfcVariant(const Ice::IfcApi::Variant& pObject);
    PyIfcVariant(Ice::IfcApi::Variant* pObject, bool autoDelete);
    ~PyIfcVariant() = default;
    int                     getInt() const;
    void                    setInt(int val);
    bool                    getBool() const;
    void                    setBool(bool val);
    unsigned                getUInt() const;
    void                    setUInt(unsigned val);
    double                  getReal() const;
    void                    setReal(double val);
    PyIfcString             getString() const;
    void                    setString(const PyIfcString& val);
    PyIfcEntity             getEntity() const;
    void                    setEntity(const PyIfcEntity& val);
    PyIfcLogical            getLogical() const;
    void                    setLogical(const PyIfcLogical& val);
    PyIfcBinary             getBinary() const;
    void                    setBinary(const PyIfcBinary& val);
    PyIfcGuid               getGuid() const;
    void                    setGuid(const PyIfcGuid& val);
    PyIfcVectorValue        getVector() const;
    void                    setVector(const PyIfcVectorValue& val);
    PyIfcSelectValue        getSelect() const;
    void                    setSelect(const PyIfcSelectValue& val);
    PyIfcEnumValue          getEnum() const;
    void                    setEnum(const PyIfcEnumValue& val);
    Ice::IfcApi::ValueType  type() const;

    static std::string  className();
public:
    Ice::IfcApi::Variant* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<Ice::IfcApi::Variant> m_pyImp;
};

#endif